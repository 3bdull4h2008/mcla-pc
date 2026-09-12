#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82292DD4"))) PPC_WEAK_FUNC(sub_82292DD4);
PPC_FUNC_IMPL(__imp__sub_82292DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292DD8"))) PPC_WEAK_FUNC(sub_82292DD8);
PPC_FUNC_IMPL(__imp__sub_82292DD8) {
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
	// bl 0x822927f0
	ctx.lr = 0x82292DF0;
	sub_822927F0(ctx, base);
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
}

__attribute__((alias("__imp__sub_82292E0C"))) PPC_WEAK_FUNC(sub_82292E0C);
PPC_FUNC_IMPL(__imp__sub_82292E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E10"))) PPC_WEAK_FUNC(sub_82292E10);
PPC_FUNC_IMPL(__imp__sub_82292E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,15896(r10)
	PPC_STORE_U32(ctx.r10.u32 + 15896, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292E24"))) PPC_WEAK_FUNC(sub_82292E24);
PPC_FUNC_IMPL(__imp__sub_82292E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E28"))) PPC_WEAK_FUNC(sub_82292E28);
PPC_FUNC_IMPL(__imp__sub_82292E28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,15896(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 15896);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292E3C"))) PPC_WEAK_FUNC(sub_82292E3C);
PPC_FUNC_IMPL(__imp__sub_82292E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E40"))) PPC_WEAK_FUNC(sub_82292E40);
PPC_FUNC_IMPL(__imp__sub_82292E40) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x822b62a0
	ctx.lr = 0x82292E60;
	sub_822B62A0(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226f598
	ctx.lr = 0x82292E74;
	sub_8226F598(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292E84"))) PPC_WEAK_FUNC(sub_82292E84);
PPC_FUNC_IMPL(__imp__sub_82292E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E88"))) PPC_WEAK_FUNC(sub_82292E88);
PPC_FUNC_IMPL(__imp__sub_82292E88) {
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
	// bl 0x822928a8
	ctx.lr = 0x82292EA0;
	sub_822928A8(ctx, base);
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
}

__attribute__((alias("__imp__sub_82292EBC"))) PPC_WEAK_FUNC(sub_82292EBC);
PPC_FUNC_IMPL(__imp__sub_82292EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292EC0"))) PPC_WEAK_FUNC(sub_82292EC0);
PPC_FUNC_IMPL(__imp__sub_82292EC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292ED4"))) PPC_WEAK_FUNC(sub_82292ED4);
PPC_FUNC_IMPL(__imp__sub_82292ED4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292ED8"))) PPC_WEAK_FUNC(sub_82292ED8);
PPC_FUNC_IMPL(__imp__sub_82292ED8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82292EF4;
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
	ctx.lr = 0x82292F08;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82292F10;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82292F14;
	sub_82481590(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82292F34"))) PPC_WEAK_FUNC(sub_82292F34);
PPC_FUNC_IMPL(__imp__sub_82292F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292F38"))) PPC_WEAK_FUNC(sub_82292F38);
PPC_FUNC_IMPL(__imp__sub_82292F38) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292F70;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292f94
	if (cr6.eq) goto loc_82292F94;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x82292F84;
	sub_822577D0(ctx, base);
	// addi r11,r3,-3
	r11.s64 = ctx.r3.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x82292f98
	goto loc_82292F98;
loc_82292F94:
	// li r11,0
	r11.s64 = 0;
loc_82292F98:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82292FB8"))) PPC_WEAK_FUNC(sub_82292FB8);
PPC_FUNC_IMPL(__imp__sub_82292FB8) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292FF0;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82293010
	if (cr6.eq) goto loc_82293010;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x82293004;
	sub_822577D0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x82293014
	goto loc_82293014;
loc_82293010:
	// li r11,0
	r11.s64 = 0;
loc_82293014:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82293034"))) PPC_WEAK_FUNC(sub_82293034);
PPC_FUNC_IMPL(__imp__sub_82293034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293038"))) PPC_WEAK_FUNC(sub_82293038);
PPC_FUNC_IMPL(__imp__sub_82293038) {
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
	// bl 0x82292750
	ctx.lr = 0x82293050;
	sub_82292750(ctx, base);
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
}

__attribute__((alias("__imp__sub_8229306C"))) PPC_WEAK_FUNC(sub_8229306C);
PPC_FUNC_IMPL(__imp__sub_8229306C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293070"))) PPC_WEAK_FUNC(sub_82293070);
PPC_FUNC_IMPL(__imp__sub_82293070) {
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
	ctx.lr = 0x82293078;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82293084;
	sub_82388580(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82293094;
	sub_82270170(ctx, base);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x822930A0;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822930b8
	if (!cr6.eq) goto loc_822930B8;
	// lwz r11,11784(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11784);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822930cc
	if (!cr6.eq) goto loc_822930CC;
loc_822930B8:
	// lwz r11,11792(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11792);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822930cc
	if (cr6.eq) goto loc_822930CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297638
	ctx.lr = 0x822930CC;
	sub_82297638(ctx, base);
loc_822930CC:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-12068
	r29.s64 = r11.s64 + -12068;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822930F0;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82293100;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822931c0
	if (cr6.eq) goto loc_822931C0;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229312C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822931ac
	if (!cr6.eq) goto loc_822931AC;
	// bl 0x82207e88
	ctx.lr = 0x8229313C;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822931ac
	if (!cr6.eq) goto loc_822931AC;
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82293188
	if (!cr6.eq) goto loc_82293188;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2012
	ctx.r4.s64 = r11.s64 + -2012;
	// bl 0x82691650
	ctx.lr = 0x82293170;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82293184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822931c0
	goto loc_822931C0;
loc_82293188:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2032
	ctx.r4.s64 = r11.s64 + -2032;
	// bl 0x82691650
	ctx.lr = 0x82293194;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822931A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822931c0
	goto loc_822931C0;
loc_822931AC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822931B8;
	sub_82691650(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,103(r3)
	PPC_STORE_U8(ctx.r3.u32 + 103, r11.u8);
loc_822931C0:
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x8226b298
	ctx.lr = 0x822931C8;
	sub_8226B298(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229320c
	if (cr6.eq) goto loc_8229320C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x822931E4;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x822931F4;
	sub_8226B2F0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229320c
	if (cr6.eq) goto loc_8229320C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x8229320C;
	sub_82295BC8(ctx, base);
loc_8229320C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82293214"))) PPC_WEAK_FUNC(sub_82293214);
PPC_FUNC_IMPL(__imp__sub_82293214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293218"))) PPC_WEAK_FUNC(sub_82293218);
PPC_FUNC_IMPL(__imp__sub_82293218) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82293238;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822932a8
	if (cr6.eq) goto loc_822932A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82293254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822932a8
	if (cr6.eq) goto loc_822932A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ab258
	ctx.lr = 0x82293268;
	sub_822AB258(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x82293284
	if (!cr6.eq) goto loc_82293284;
	// li r31,0
	r31.s64 = 0;
loc_82293284:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-2032
	ctx.r4.s64 = ctx.r10.s64 + -2032;
	// bl 0x82691650
	ctx.lr = 0x82293294;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,348(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 348);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822932A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822932A8:
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

__attribute__((alias("__imp__sub_822932BC"))) PPC_WEAK_FUNC(sub_822932BC);
PPC_FUNC_IMPL(__imp__sub_822932BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822932C0"))) PPC_WEAK_FUNC(sub_822932C0);
PPC_FUNC_IMPL(__imp__sub_822932C0) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822932E0;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82293350
	if (cr6.eq) goto loc_82293350;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822932FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82293350
	if (cr6.eq) goto loc_82293350;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ab258
	ctx.lr = 0x82293310;
	sub_822AB258(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x8229332c
	if (!cr6.eq) goto loc_8229332C;
	// li r31,0
	r31.s64 = 0;
loc_8229332C:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-21704
	ctx.r4.s64 = ctx.r10.s64 + -21704;
	// bl 0x82691650
	ctx.lr = 0x8229333C;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,348(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 348);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82293350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82293350:
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

__attribute__((alias("__imp__sub_82293364"))) PPC_WEAK_FUNC(sub_82293364);
PPC_FUNC_IMPL(__imp__sub_82293364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293368"))) PPC_WEAK_FUNC(sub_82293368);
PPC_FUNC_IMPL(__imp__sub_82293368) {
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
	ctx.lr = 0x82293370;
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8229338C;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82293480
	if (cr6.eq) goto loc_82293480;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x822952b0
	ctx.lr = 0x822933A0;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82293480
	if (cr6.eq) goto loc_82293480;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82250410
	ctx.lr = 0x822933B4;
	sub_82250410(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227fca0
	ctx.lr = 0x822933C4;
	sub_8227FCA0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822933CC;
	sub_823EAEF8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82267860
	ctx.lr = 0x822933D4;
	sub_82267860(ctx, base);
	// lbz r10,1139(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1139);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x822933e8
	if (!cr6.eq) goto loc_822933E8;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x822933ec
	goto loc_822933EC;
loc_822933E8:
	// lbz r11,1138(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1138);
loc_822933EC:
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822677a0
	ctx.lr = 0x822933F8;
	sub_822677A0(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// li r29,368
	r29.s64 = 368;
	// addi r31,r1,193
	r31.s64 = ctx.r1.s64 + 193;
loc_82293404:
	// lbz r10,1139(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1139);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82293418
	if (!cr6.eq) goto loc_82293418;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x8229341c
	goto loc_8229341C;
loc_82293418:
	// lbz r11,1138(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1138);
loc_8229341C:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x82293480
	if (!cr6.lt) goto loc_82293480;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r4,r31,-17
	ctx.r4.s64 = r31.s64 + -17;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// addi r3,r30,-368
	ctx.r3.s64 = r30.s64 + -368;
	// bl 0x82264e80
	ctx.lr = 0x82293438;
	sub_82264E80(ctx, base);
	// lbz r11,-1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -1);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r29,r29,368
	r29.s64 = r29.s64 + 368;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,-188(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + -188, temp.u32);
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,-200(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + -200, temp.u32);
	// b 0x82293404
	goto loc_82293404;
loc_82293480:
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82293488"))) PPC_WEAK_FUNC(sub_82293488);
PPC_FUNC_IMPL(__imp__sub_82293488) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82293490;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-1456(r1)
	ea = -1456 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822934B4;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82293610
	if (cr6.eq) goto loc_82293610;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82293610
	if (cr6.eq) goto loc_82293610;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x822952b0
	ctx.lr = 0x822934D0;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82293610
	if (cr6.eq) goto loc_82293610;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x82250410
	ctx.lr = 0x822934E4;
	sub_82250410(ctx, base);
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227fca0
	ctx.lr = 0x822934F4;
	sub_8227FCA0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lbz r6,1393(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1393);
	// addi r5,r1,400
	ctx.r5.s64 = ctx.r1.s64 + 400;
	// lbz r4,1392(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1392);
	// lwz r3,-6148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82251780
	ctx.lr = 0x82293510;
	sub_82251780(ctx, base);
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// vsubfp128 v59,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r11,2528
	ctx.r6.s64 = r11.s64 + 2528;
	// addi r11,r8,-31648
	r11.s64 = ctx.r8.s64 + -31648;
	// addi r8,r5,-31664
	ctx.r8.s64 = ctx.r5.s64 + -31664;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v58,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v57,v58
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v57,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v63,v6
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x822935B0;
	sub_823DCDD8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r29,3088(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 3088);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,30288(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30288);
	f0.f64 = double(temp.f32);
	// lfs f13,-29924(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29924);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f31,f12,f0,f13
	f31.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// bl 0x822561a0
	ctx.lr = 0x822935D8;
	sub_822561A0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82293610
	if (!cr6.gt) goto loc_82293610;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
loc_822935EC:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82264590
	ctx.lr = 0x82293600;
	sub_82264590(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x822935ec
	if (cr6.lt) goto loc_822935EC;
loc_82293610:
	// addi r1,r1,1456
	ctx.r1.s64 = ctx.r1.s64 + 1456;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229361C"))) PPC_WEAK_FUNC(sub_8229361C);
PPC_FUNC_IMPL(__imp__sub_8229361C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293620"))) PPC_WEAK_FUNC(sub_82293620);
PPC_FUNC_IMPL(__imp__sub_82293620) {
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
	// bl 0x82291a80
	ctx.lr = 0x82293640;
	sub_82291A80(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82293660"))) PPC_WEAK_FUNC(sub_82293660);
PPC_FUNC_IMPL(__imp__sub_82293660) {
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
	// bl 0x82292178
	ctx.lr = 0x82293680;
	sub_82292178(ctx, base);
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

__attribute__((alias("__imp__sub_8229369C"))) PPC_WEAK_FUNC(sub_8229369C);
PPC_FUNC_IMPL(__imp__sub_8229369C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822936A0"))) PPC_WEAK_FUNC(sub_822936A0);
PPC_FUNC_IMPL(__imp__sub_822936A0) {
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
	// bl 0x82292240
	ctx.lr = 0x822936C0;
	sub_82292240(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_822936E0"))) PPC_WEAK_FUNC(sub_822936E0);
PPC_FUNC_IMPL(__imp__sub_822936E0) {
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
	// bl 0x82291e48
	ctx.lr = 0x82293704;
	sub_82291E48(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82293724"))) PPC_WEAK_FUNC(sub_82293724);
PPC_FUNC_IMPL(__imp__sub_82293724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293728"))) PPC_WEAK_FUNC(sub_82293728);
PPC_FUNC_IMPL(__imp__sub_82293728) {
	PPC_FUNC_PROLOGUE();
	// b 0x82293070
	sub_82293070(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229372C"))) PPC_WEAK_FUNC(sub_8229372C);
PPC_FUNC_IMPL(__imp__sub_8229372C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293730"))) PPC_WEAK_FUNC(sub_82293730);
PPC_FUNC_IMPL(__imp__sub_82293730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82293368
	sub_82293368(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229373C"))) PPC_WEAK_FUNC(sub_8229373C);
PPC_FUNC_IMPL(__imp__sub_8229373C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293740"))) PPC_WEAK_FUNC(sub_82293740);
PPC_FUNC_IMPL(__imp__sub_82293740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82293488
	sub_82293488(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82293750"))) PPC_WEAK_FUNC(sub_82293750);
PPC_FUNC_IMPL(__imp__sub_82293750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82293218
	sub_82293218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229375C"))) PPC_WEAK_FUNC(sub_8229375C);
PPC_FUNC_IMPL(__imp__sub_8229375C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293760"))) PPC_WEAK_FUNC(sub_82293760);
PPC_FUNC_IMPL(__imp__sub_82293760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822932c0
	sub_822932C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229376C"))) PPC_WEAK_FUNC(sub_8229376C);
PPC_FUNC_IMPL(__imp__sub_8229376C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293770"))) PPC_WEAK_FUNC(sub_82293770);
PPC_FUNC_IMPL(__imp__sub_82293770) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82293778;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r22,0(r13)
	r22.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r21,72
	r21.s64 = 72;
	// li r26,0
	r26.s64 = 0;
	// li r23,8
	r23.s64 = 8;
	// lwz r3,17268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 17268);
	// li r25,1
	r25.s64 = 1;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// addi r28,r11,15912
	r28.s64 = r11.s64 + 15912;
loc_822937A4:
	// lbzx r11,r21,r22
	r11.u64 = PPC_LOAD_U8(r21.u32 + r22.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822937d4
	if (cr6.eq) goto loc_822937D4;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x822937f8
	if (cr6.lt) goto loc_822937F8;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bge cr6,0x822937f8
	if (!cr6.lt) goto loc_822937F8;
	// add r11,r23,r3
	r11.u64 = r23.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822937f0
	goto loc_822937F0;
loc_822937D4:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x822937f8
	if (cr6.lt) goto loc_822937F8;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bge cr6,0x822937f8
	if (!cr6.lt) goto loc_822937F8;
	// lwzx r11,r23,r3
	r11.u64 = PPC_LOAD_U32(r23.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_822937F0:
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x822937fc
	if (!cr6.eq) goto loc_822937FC;
loc_822937F8:
	// li r11,0
	r11.s64 = 0;
loc_822937FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82293944
	if (cr6.eq) goto loc_82293944;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822a3998
	ctx.lr = 0x82293810;
	sub_822A3998(ctx, base);
	// lwz r11,1220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// lwz r3,17268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 17268);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82293944
	if (cr6.eq) goto loc_82293944;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822a3998
	ctx.lr = 0x82293828;
	sub_822A3998(ctx, base);
	// lwz r11,-3624(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -3624);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r31,1220(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// bl 0x8227e0b0
	ctx.lr = 0x8229383C;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229386c
	if (cr6.eq) goto loc_8229386C;
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82293858;
	sub_822577D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82293880
	goto loc_82293880;
loc_8229386C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82293880:
	// bctrl 
	ctx.lr = 0x82293884;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822938b8
	if (cr6.eq) goto loc_822938B8;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822938b0
	if (!cr6.eq) goto loc_822938B0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x822938A4;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822938b8
	if (cr6.eq) goto loc_822938B8;
loc_822938B0:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x822938bc
	goto loc_822938BC;
loc_822938B8:
	// li r11,0
	r11.s64 = 0;
loc_822938BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82293930
	if (cr6.eq) goto loc_82293930;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822938D0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822938f4
	if (cr6.eq) goto loc_822938F4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x822938E8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x822938f8
	if (!cr6.eq) goto loc_822938F8;
loc_822938F4:
	// li r11,0
	r11.s64 = 0;
loc_822938F8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82293930
	if (cr6.eq) goto loc_82293930;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r5,64(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82293914;
	sub_82274120(ctx, base);
	// stb r25,277(r31)
	PPC_STORE_U8(r31.u32 + 277, r25.u8);
	// lwz r11,64(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,64(r28)
	PPC_STORE_U32(r28.u32 + 64, r11.u32);
	// stwx r30,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, r30.u32);
	// b 0x82293940
	goto loc_82293940;
loc_82293930:
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82293940;
	sub_82274120(ctx, base);
loc_82293940:
	// lwz r3,17268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 17268);
loc_82293944:
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpwi cr6,r23,132
	cr6.compare<int32_t>(r23.s32, 132, xer);
	// bne cr6,0x822937a4
	if (!cr6.eq) goto loc_822937A4;
	// li r31,0
	r31.s64 = 0;
loc_82293958:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82292508
	ctx.lr = 0x82293960;
	sub_82292508(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// blt cr6,0x82293958
	if (cr6.lt) goto loc_82293958;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r25
	r11.u64 = r25.u64;
	// stb r11,15765(r10)
	PPC_STORE_U8(ctx.r10.u32 + 15765, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82293980"))) PPC_WEAK_FUNC(sub_82293980);
PPC_FUNC_IMPL(__imp__sub_82293980) {
	PPC_FUNC_PROLOGUE();
	// b 0x82293770
	sub_82293770(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82293984"))) PPC_WEAK_FUNC(sub_82293984);
PPC_FUNC_IMPL(__imp__sub_82293984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293988"))) PPC_WEAK_FUNC(sub_82293988);
PPC_FUNC_IMPL(__imp__sub_82293988) {
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
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,13856
	ctx.r4.s64 = r11.s64 + 13856;
	// addi r3,r10,11288
	ctx.r3.s64 = ctx.r10.s64 + 11288;
	// bl 0x82554798
	ctx.lr = 0x822939A8;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,5472
	ctx.r4.s64 = ctx.r9.s64 + 5472;
	// addi r3,r8,11264
	ctx.r3.s64 = ctx.r8.s64 + 11264;
	// bl 0x82554798
	ctx.lr = 0x822939BC;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,10680
	ctx.r4.s64 = ctx.r7.s64 + 10680;
	// addi r3,r6,11248
	ctx.r3.s64 = ctx.r6.s64 + 11248;
	// bl 0x82554798
	ctx.lr = 0x822939D0;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,10736
	ctx.r4.s64 = ctx.r5.s64 + 10736;
	// addi r3,r3,11224
	ctx.r3.s64 = ctx.r3.s64 + 11224;
	// bl 0x82554798
	ctx.lr = 0x822939E4;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,10880
	ctx.r4.s64 = r11.s64 + 10880;
	// addi r3,r10,11200
	ctx.r3.s64 = ctx.r10.s64 + 11200;
	// bl 0x82554798
	ctx.lr = 0x822939F8;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,13920
	ctx.r4.s64 = ctx.r9.s64 + 13920;
	// addi r3,r8,11176
	ctx.r3.s64 = ctx.r8.s64 + 11176;
	// bl 0x82554798
	ctx.lr = 0x82293A0C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,13984
	ctx.r4.s64 = ctx.r7.s64 + 13984;
	// addi r3,r6,11148
	ctx.r3.s64 = ctx.r6.s64 + 11148;
	// bl 0x82554798
	ctx.lr = 0x82293A20;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,10944
	ctx.r4.s64 = ctx.r5.s64 + 10944;
	// addi r3,r3,11124
	ctx.r3.s64 = ctx.r3.s64 + 11124;
	// bl 0x82554798
	ctx.lr = 0x82293A34;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,10952
	ctx.r4.s64 = r11.s64 + 10952;
	// addi r3,r10,11100
	ctx.r3.s64 = ctx.r10.s64 + 11100;
	// bl 0x82554798
	ctx.lr = 0x82293A48;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14048
	ctx.r4.s64 = ctx.r9.s64 + 14048;
	// addi r3,r8,11076
	ctx.r3.s64 = ctx.r8.s64 + 11076;
	// bl 0x82554798
	ctx.lr = 0x82293A5C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,10968
	ctx.r4.s64 = ctx.r7.s64 + 10968;
	// addi r3,r6,11056
	ctx.r3.s64 = ctx.r6.s64 + 11056;
	// bl 0x82554798
	ctx.lr = 0x82293A70;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,10984
	ctx.r4.s64 = ctx.r5.s64 + 10984;
	// addi r3,r3,11032
	ctx.r3.s64 = ctx.r3.s64 + 11032;
	// bl 0x82554798
	ctx.lr = 0x82293A84;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,11000
	ctx.r4.s64 = r11.s64 + 11000;
	// addi r3,r10,11008
	ctx.r3.s64 = ctx.r10.s64 + 11008;
	// bl 0x82554798
	ctx.lr = 0x82293A98;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,11096
	ctx.r4.s64 = ctx.r9.s64 + 11096;
	// addi r3,r8,10984
	ctx.r3.s64 = ctx.r8.s64 + 10984;
	// bl 0x82554798
	ctx.lr = 0x82293AAC;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,14720
	ctx.r4.s64 = ctx.r7.s64 + 14720;
	// addi r3,r6,10964
	ctx.r3.s64 = ctx.r6.s64 + 10964;
	// bl 0x82554798
	ctx.lr = 0x82293AC0;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,11192
	ctx.r4.s64 = ctx.r5.s64 + 11192;
	// addi r3,r3,10944
	ctx.r3.s64 = ctx.r3.s64 + 10944;
	// bl 0x82554798
	ctx.lr = 0x82293AD4;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,11200
	ctx.r4.s64 = r11.s64 + 11200;
	// addi r3,r10,10920
	ctx.r3.s64 = ctx.r10.s64 + 10920;
	// bl 0x82554798
	ctx.lr = 0x82293AE8;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,11272
	ctx.r4.s64 = ctx.r9.s64 + 11272;
	// addi r3,r8,10896
	ctx.r3.s64 = ctx.r8.s64 + 10896;
	// bl 0x82554798
	ctx.lr = 0x82293AFC;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,11328
	ctx.r4.s64 = ctx.r7.s64 + 11328;
	// addi r3,r6,10876
	ctx.r3.s64 = ctx.r6.s64 + 10876;
	// bl 0x82554798
	ctx.lr = 0x82293B10;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,11336
	ctx.r4.s64 = ctx.r5.s64 + 11336;
	// addi r3,r3,10852
	ctx.r3.s64 = ctx.r3.s64 + 10852;
	// bl 0x82554798
	ctx.lr = 0x82293B24;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,11432
	ctx.r4.s64 = r11.s64 + 11432;
	// addi r3,r10,10832
	ctx.r3.s64 = ctx.r10.s64 + 10832;
	// bl 0x82554798
	ctx.lr = 0x82293B38;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,5488
	ctx.r4.s64 = ctx.r9.s64 + 5488;
	// addi r3,r8,10816
	ctx.r3.s64 = ctx.r8.s64 + 10816;
	// bl 0x82554798
	ctx.lr = 0x82293B4C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,5520
	ctx.r4.s64 = ctx.r7.s64 + 5520;
	// addi r3,r6,10784
	ctx.r3.s64 = ctx.r6.s64 + 10784;
	// bl 0x82554798
	ctx.lr = 0x82293B60;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,5592
	ctx.r4.s64 = ctx.r5.s64 + 5592;
	// addi r3,r3,10764
	ctx.r3.s64 = ctx.r3.s64 + 10764;
	// bl 0x82554798
	ctx.lr = 0x82293B74;
	sub_82554798(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,20536
	ctx.r4.s64 = r11.s64 + 20536;
	// addi r3,r10,10744
	ctx.r3.s64 = ctx.r10.s64 + 10744;
	// bl 0x82554798
	ctx.lr = 0x82293B88;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14120
	ctx.r4.s64 = ctx.r9.s64 + 14120;
	// addi r3,r8,10728
	ctx.r3.s64 = ctx.r8.s64 + 10728;
	// bl 0x82554798
	ctx.lr = 0x82293B9C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,11488
	ctx.r4.s64 = ctx.r7.s64 + 11488;
	// addi r3,r6,10696
	ctx.r3.s64 = ctx.r6.s64 + 10696;
	// bl 0x82554798
	ctx.lr = 0x82293BB0;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,11552
	ctx.r4.s64 = ctx.r5.s64 + 11552;
	// addi r3,r3,10680
	ctx.r3.s64 = ctx.r3.s64 + 10680;
	// bl 0x82554798
	ctx.lr = 0x82293BC4;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,14128
	ctx.r4.s64 = r11.s64 + 14128;
	// addi r3,r10,10648
	ctx.r3.s64 = ctx.r10.s64 + 10648;
	// bl 0x82554798
	ctx.lr = 0x82293BD8;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,14144
	ctx.r4.s64 = ctx.r9.s64 + 14144;
	// addi r3,r8,10624
	ctx.r3.s64 = ctx.r8.s64 + 10624;
	// bl 0x82554798
	ctx.lr = 0x82293BEC;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,11680
	ctx.r4.s64 = ctx.r7.s64 + 11680;
	// addi r3,r6,10608
	ctx.r3.s64 = ctx.r6.s64 + 10608;
	// bl 0x82554798
	ctx.lr = 0x82293C00;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,14160
	ctx.r4.s64 = ctx.r5.s64 + 14160;
	// addi r3,r3,10584
	ctx.r3.s64 = ctx.r3.s64 + 10584;
	// bl 0x82554798
	ctx.lr = 0x82293C14;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// addi r4,r11,14176
	ctx.r4.s64 = r11.s64 + 14176;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,10564
	ctx.r3.s64 = ctx.r10.s64 + 10564;
	// bl 0x82554798
	ctx.lr = 0x82293C28;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,11736
	ctx.r4.s64 = ctx.r9.s64 + 11736;
	// addi r3,r8,10540
	ctx.r3.s64 = ctx.r8.s64 + 10540;
	// bl 0x82554798
	ctx.lr = 0x82293C3C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,5664
	ctx.r4.s64 = ctx.r7.s64 + 5664;
	// addi r3,r6,10520
	ctx.r3.s64 = ctx.r6.s64 + 10520;
	// bl 0x82554798
	ctx.lr = 0x82293C50;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,5728
	ctx.r4.s64 = ctx.r5.s64 + 5728;
	// addi r3,r3,10508
	ctx.r3.s64 = ctx.r3.s64 + 10508;
	// bl 0x82554798
	ctx.lr = 0x82293C64;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,11792
	ctx.r4.s64 = r11.s64 + 11792;
	// addi r3,r10,10484
	ctx.r3.s64 = ctx.r10.s64 + 10484;
	// bl 0x82554798
	ctx.lr = 0x82293C78;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,11816
	ctx.r4.s64 = ctx.r9.s64 + 11816;
	// addi r3,r8,10460
	ctx.r3.s64 = ctx.r8.s64 + 10460;
	// bl 0x82554798
	ctx.lr = 0x82293C8C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,11840
	ctx.r4.s64 = ctx.r7.s64 + 11840;
	// addi r3,r6,10432
	ctx.r3.s64 = ctx.r6.s64 + 10432;
	// bl 0x82554798
	ctx.lr = 0x82293CA0;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,11912
	ctx.r4.s64 = ctx.r5.s64 + 11912;
	// addi r3,r3,10412
	ctx.r3.s64 = ctx.r3.s64 + 10412;
	// bl 0x82554798
	ctx.lr = 0x82293CB4;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,5792
	ctx.r4.s64 = r11.s64 + 5792;
	// addi r3,r10,10388
	ctx.r3.s64 = ctx.r10.s64 + 10388;
	// bl 0x82554798
	ctx.lr = 0x82293CC8;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,5816
	ctx.r4.s64 = ctx.r9.s64 + 5816;
	// addi r3,r8,10364
	ctx.r3.s64 = ctx.r8.s64 + 10364;
	// bl 0x82554798
	ctx.lr = 0x82293CDC;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,5840
	ctx.r4.s64 = ctx.r7.s64 + 5840;
	// addi r3,r6,10336
	ctx.r3.s64 = ctx.r6.s64 + 10336;
	// bl 0x82554798
	ctx.lr = 0x82293CF0;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,11968
	ctx.r4.s64 = ctx.r5.s64 + 11968;
	// addi r3,r3,10316
	ctx.r3.s64 = ctx.r3.s64 + 10316;
	// bl 0x82554798
	ctx.lr = 0x82293D04;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,5904
	ctx.r4.s64 = r11.s64 + 5904;
	// addi r3,r10,10300
	ctx.r3.s64 = ctx.r10.s64 + 10300;
	// bl 0x82554798
	ctx.lr = 0x82293D18;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,5960
	ctx.r4.s64 = ctx.r9.s64 + 5960;
	// addi r3,r8,10280
	ctx.r3.s64 = ctx.r8.s64 + 10280;
	// bl 0x82554798
	ctx.lr = 0x82293D2C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,6072
	ctx.r4.s64 = ctx.r7.s64 + 6072;
	// addi r3,r6,10260
	ctx.r3.s64 = ctx.r6.s64 + 10260;
	// bl 0x82554798
	ctx.lr = 0x82293D40;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,6192
	ctx.r4.s64 = ctx.r5.s64 + 6192;
	// addi r3,r3,10236
	ctx.r3.s64 = ctx.r3.s64 + 10236;
	// bl 0x82554798
	ctx.lr = 0x82293D54;
	sub_82554798(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32215
	ctx.r10.s64 = -2111242240;
	// addi r3,r11,10216
	ctx.r3.s64 = r11.s64 + 10216;
	// addi r4,r10,6304
	ctx.r4.s64 = ctx.r10.s64 + 6304;
	// bl 0x82554798
	ctx.lr = 0x82293D68;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,11992
	ctx.r4.s64 = ctx.r9.s64 + 11992;
	// addi r3,r8,10196
	ctx.r3.s64 = ctx.r8.s64 + 10196;
	// bl 0x82554798
	ctx.lr = 0x82293D7C;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,12088
	ctx.r4.s64 = ctx.r7.s64 + 12088;
	// addi r3,r6,10168
	ctx.r3.s64 = ctx.r6.s64 + 10168;
	// bl 0x82554798
	ctx.lr = 0x82293D90;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,12216
	ctx.r4.s64 = ctx.r5.s64 + 12216;
	// addi r3,r3,10148
	ctx.r3.s64 = ctx.r3.s64 + 10148;
	// bl 0x82554798
	ctx.lr = 0x82293DA4;
	sub_82554798(ctx, base);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,6344
	ctx.r4.s64 = r11.s64 + 6344;
	// addi r3,r10,10128
	ctx.r3.s64 = ctx.r10.s64 + 10128;
	// bl 0x82554798
	ctx.lr = 0x82293DB8;
	sub_82554798(ctx, base);
	// lis r9,-32215
	ctx.r9.s64 = -2111242240;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,12344
	ctx.r4.s64 = ctx.r9.s64 + 12344;
	// addi r3,r8,10108
	ctx.r3.s64 = ctx.r8.s64 + 10108;
	// bl 0x82554798
	ctx.lr = 0x82293DCC;
	sub_82554798(ctx, base);
	// lis r7,-32215
	ctx.r7.s64 = -2111242240;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,6408
	ctx.r4.s64 = ctx.r7.s64 + 6408;
	// addi r3,r6,10084
	ctx.r3.s64 = ctx.r6.s64 + 10084;
	// bl 0x82554798
	ctx.lr = 0x82293DE0;
	sub_82554798(ctx, base);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,6480
	ctx.r4.s64 = ctx.r5.s64 + 6480;
	// addi r3,r3,10052
	ctx.r3.s64 = ctx.r3.s64 + 10052;
	// bl 0x82554798
	ctx.lr = 0x82293DF4;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,10032
	ctx.r3.s64 = ctx.r10.s64 + 10032;
	// bl 0x82554798
	ctx.lr = 0x82293E08;
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

__attribute__((alias("__imp__sub_82293E18"))) PPC_WEAK_FUNC(sub_82293E18);
PPC_FUNC_IMPL(__imp__sub_82293E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293E30"))) PPC_WEAK_FUNC(sub_82293E30);
PPC_FUNC_IMPL(__imp__sub_82293E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// stfs f10,4(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293E60"))) PPC_WEAK_FUNC(sub_82293E60);
PPC_FUNC_IMPL(__imp__sub_82293E60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293E78"))) PPC_WEAK_FUNC(sub_82293E78);
PPC_FUNC_IMPL(__imp__sub_82293E78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82293e9c
	if (!cr6.eq) goto loc_82293E9C;
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x82293ea0
	if (cr6.eq) goto loc_82293EA0;
loc_82293E9C:
	// li r11,0
	r11.s64 = 0;
loc_82293EA0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293EB0"))) PPC_WEAK_FUNC(sub_82293EB0);
PPC_FUNC_IMPL(__imp__sub_82293EB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x82293ec8
	if (!cr6.gt) goto loc_82293EC8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82293EC8:
	// blt cr6,0x82293ee0
	if (cr6.lt) goto loc_82293EE0;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_82293EE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293EE8"))) PPC_WEAK_FUNC(sub_82293EE8);
PPC_FUNC_IMPL(__imp__sub_82293EE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82293f20
	if (cr6.gt) goto loc_82293F20;
	// bge cr6,0x82293f04
	if (!cr6.lt) goto loc_82293F04;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82293F04:
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82293f20
	if (cr6.gt) goto loc_82293F20;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// li r3,0
	ctx.r3.s64 = 0;
	// bltlr cr6
	if (cr6.lt) return;
loc_82293F20:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293F28"))) PPC_WEAK_FUNC(sub_82293F28);
PPC_FUNC_IMPL(__imp__sub_82293F28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82293f40
	if (!cr6.lt) goto loc_82293F40;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82293F40:
	// bgt cr6,0x82293f58
	if (cr6.gt) goto loc_82293F58;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bltlr cr6
	if (cr6.lt) return;
loc_82293F58:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293F60"))) PPC_WEAK_FUNC(sub_82293F60);
PPC_FUNC_IMPL(__imp__sub_82293F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fadds f1,f0,f11
	ctx.f1.f64 = double(float(f0.f64 + ctx.f11.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82293F84"))) PPC_WEAK_FUNC(sub_82293F84);
PPC_FUNC_IMPL(__imp__sub_82293F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82293F88"))) PPC_WEAK_FUNC(sub_82293F88);
PPC_FUNC_IMPL(__imp__sub_82293F88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// fadds f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 + f0.f64));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// fsubs f0,f12,f8
	f0.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// ble 0x82293ff8
	if (!cr0.gt) goto loc_82293FF8;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82293ff8
	if (!cr6.lt) goto loc_82293FF8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
loc_82293FF8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294028"))) PPC_WEAK_FUNC(sub_82294028);
PPC_FUNC_IMPL(__imp__sub_82294028) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// bl 0x82293f88
	ctx.lr = 0x82294074;
	sub_82293F88(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294084"))) PPC_WEAK_FUNC(sub_82294084);
PPC_FUNC_IMPL(__imp__sub_82294084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294088"))) PPC_WEAK_FUNC(sub_82294088);
PPC_FUNC_IMPL(__imp__sub_82294088) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8229409C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82294134
	if (cr6.eq) goto loc_82294134;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,250
	ctx.r10.s64 = 250;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f0,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// li r5,187
	ctx.r5.s64 = 187;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r4,500
	ctx.r4.s64 = 500;
	// lfs f12,-31384(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31384);
	ctx.f12.f64 = double(temp.f32);
	// li r10,10000
	ctx.r10.s64 = 10000;
	// lfs f11,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-332(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -332);
	ctx.f10.f64 = double(temp.f32);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, r11.u8);
	// stfs f12,16(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, r11.u8);
	// stfs f11,20(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, r11.u8);
	// stfs f10,44(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, r11.u8);
	// stb r11,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r11.u8);
	// stb r11,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, r11.u8);
	// stb r11,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, r11.u8);
	// stw r4,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r4.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82294134:
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

__attribute__((alias("__imp__sub_82294148"))) PPC_WEAK_FUNC(sub_82294148);
PPC_FUNC_IMPL(__imp__sub_82294148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,16824(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16824);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294154"))) PPC_WEAK_FUNC(sub_82294154);
PPC_FUNC_IMPL(__imp__sub_82294154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294158"))) PPC_WEAK_FUNC(sub_82294158);
PPC_FUNC_IMPL(__imp__sub_82294158) {
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
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8229416C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822941c0
	if (cr6.eq) goto loc_822941C0;
	// li r11,5000
	r11.s64 = 5000;
	// li r10,250
	ctx.r10.s64 = 250;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// li r8,1000
	ctx.r8.s64 = 1000;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,300
	ctx.r6.s64 = 300;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r5,100
	ctx.r5.s64 = 100;
	// stb r7,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r7.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// stw r5,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r5.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822941C0:
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

__attribute__((alias("__imp__sub_822941D4"))) PPC_WEAK_FUNC(sub_822941D4);
PPC_FUNC_IMPL(__imp__sub_822941D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822941D8"))) PPC_WEAK_FUNC(sub_822941D8);
PPC_FUNC_IMPL(__imp__sub_822941D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,16828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16828);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822941E4"))) PPC_WEAK_FUNC(sub_822941E4);
PPC_FUNC_IMPL(__imp__sub_822941E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822941E8"))) PPC_WEAK_FUNC(sub_822941E8);
PPC_FUNC_IMPL(__imp__sub_822941E8) {
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
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822941FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229421c
	if (cr6.eq) goto loc_8229421C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8229421C:
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

__attribute__((alias("__imp__sub_82294230"))) PPC_WEAK_FUNC(sub_82294230);
PPC_FUNC_IMPL(__imp__sub_82294230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,16832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16832);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229423C"))) PPC_WEAK_FUNC(sub_8229423C);
PPC_FUNC_IMPL(__imp__sub_8229423C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294240"))) PPC_WEAK_FUNC(sub_82294240);
PPC_FUNC_IMPL(__imp__sub_82294240) {
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
	ctx.lr = 0x82294254;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82294284
	if (cr6.eq) goto loc_82294284;
	// li r11,1200
	r11.s64 = 1200;
	// li r10,1500
	ctx.r10.s64 = 1500;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82294284:
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

__attribute__((alias("__imp__sub_82294298"))) PPC_WEAK_FUNC(sub_82294298);
PPC_FUNC_IMPL(__imp__sub_82294298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,16836(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16836);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822942A4"))) PPC_WEAK_FUNC(sub_822942A4);
PPC_FUNC_IMPL(__imp__sub_822942A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822942A8"))) PPC_WEAK_FUNC(sub_822942A8);
PPC_FUNC_IMPL(__imp__sub_822942A8) {
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
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82130528
	ctx.lr = 0x822942BC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82294344
	if (cr6.eq) goto loc_82294344;
	// li r11,8
	r11.s64 = 8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f13,14184(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14184);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f12,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f11,32668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32668);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,30712(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lfs f10,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,3732(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-2580(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -2580);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	ctx.f7.f64 = double(temp.f32);
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f10,20(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f9,24(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f8,32(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f7,40(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82294344:
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

__attribute__((alias("__imp__sub_82294358"))) PPC_WEAK_FUNC(sub_82294358);
PPC_FUNC_IMPL(__imp__sub_82294358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,16840(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16840);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294364"))) PPC_WEAK_FUNC(sub_82294364);
PPC_FUNC_IMPL(__imp__sub_82294364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294368"))) PPC_WEAK_FUNC(sub_82294368);
PPC_FUNC_IMPL(__imp__sub_82294368) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,16828
	r31.s64 = r11.s64 + 16828;
	// lwz r11,16828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822944e8
	if (!cr6.eq) goto loc_822944E8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82294398;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822943ac
	if (cr6.eq) goto loc_822943AC;
	// bl 0x821d5408
	ctx.lr = 0x822943A8;
	sub_821D5408(ctx, base);
	// b 0x822943b0
	goto loc_822943B0;
loc_822943AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822943B0:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,13440
	ctx.r7.s64 = ctx.r10.s64 + 13440;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,16856
	ctx.r9.s64 = r11.s64 + 16856;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,16728
	ctx.r4.s64 = ctx.r8.s64 + 16728;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,-5360
	ctx.r8.s64 = ctx.r10.s64 + -5360;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,-5384
	ctx.r9.s64 = ctx.r3.s64 + -5384;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r6,r5,-5336
	ctx.r6.s64 = ctx.r5.s64 + -5336;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r4,-5312
	ctx.r5.s64 = ctx.r4.s64 + -5312;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r11,4
	r11.s64 = 4;
	// addi r4,r7,-5288
	ctx.r4.s64 = ctx.r7.s64 + -5288;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,12
	ctx.r9.s64 = 12;
	// li r11,16
	r11.s64 = 16;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r5,r7,-5240
	ctx.r5.s64 = ctx.r7.s64 + -5240;
	// addi r6,r8,-5264
	ctx.r6.s64 = ctx.r8.s64 + -5264;
	// addi r4,r30,-5216
	ctx.r4.s64 = r30.s64 + -5216;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r11,28
	r11.s64 = 28;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x82294494;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822944A4;
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
	ctx.lr = 0x822944C0;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-5492
	ctx.r4.s64 = ctx.r8.s64 + -5492;
	// bl 0x821d4b00
	ctx.lr = 0x822944D0;
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
	ctx.lr = 0x822944E8;
	sub_821C0548(ctx, base);
loc_822944E8:
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

__attribute__((alias("__imp__sub_82294500"))) PPC_WEAK_FUNC(sub_82294500);
PPC_FUNC_IMPL(__imp__sub_82294500) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,16832
	r31.s64 = r11.s64 + 16832;
	// lwz r11,16832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16832);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294610
	if (!cr6.eq) goto loc_82294610;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82294530;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82294544
	if (cr6.eq) goto loc_82294544;
	// bl 0x821d5408
	ctx.lr = 0x82294540;
	sub_821D5408(ctx, base);
	// b 0x82294548
	goto loc_82294548;
loc_82294544:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82294548:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,13464
	ctx.r7.s64 = ctx.r10.s64 + 13464;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,16944
	ctx.r9.s64 = r11.s64 + 16944;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,16872
	ctx.r4.s64 = ctx.r8.s64 + 16872;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,-5192
	ctx.r9.s64 = ctx.r3.s64 + -5192;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x822945BC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822945CC;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x822945E8;
	sub_821D41D0(ctx, base);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,-5168
	ctx.r4.s64 = ctx.r5.s64 + -5168;
	// bl 0x821d4b00
	ctx.lr = 0x822945F8;
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
	ctx.lr = 0x82294610;
	sub_821C0548(ctx, base);
loc_82294610:
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

__attribute__((alias("__imp__sub_82294628"))) PPC_WEAK_FUNC(sub_82294628);
PPC_FUNC_IMPL(__imp__sub_82294628) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,16836
	r31.s64 = r11.s64 + 16836;
	// lwz r11,16836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294758
	if (!cr6.eq) goto loc_82294758;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82294658;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229466c
	if (cr6.eq) goto loc_8229466C;
	// bl 0x821d5408
	ctx.lr = 0x82294668;
	sub_821D5408(ctx, base);
	// b 0x82294670
	goto loc_82294670;
loc_8229466C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82294670:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,13488
	ctx.r7.s64 = ctx.r10.s64 + 13488;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,17048
	ctx.r9.s64 = r11.s64 + 17048;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,16960
	ctx.r4.s64 = ctx.r8.s64 + 16960;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-5160
	ctx.r7.s64 = ctx.r3.s64 + -5160;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// addi r4,r10,-5136
	ctx.r4.s64 = ctx.r10.s64 + -5136;
	// addi r3,r9,-5112
	ctx.r3.s64 = ctx.r9.s64 + -5112;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x82294704;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x82294714;
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
	ctx.lr = 0x82294730;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-5088
	ctx.r4.s64 = ctx.r8.s64 + -5088;
	// bl 0x821d4b00
	ctx.lr = 0x82294740;
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
	ctx.lr = 0x82294758;
	sub_821C0548(ctx, base);
loc_82294758:
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

__attribute__((alias("__imp__sub_82294770"))) PPC_WEAK_FUNC(sub_82294770);
PPC_FUNC_IMPL(__imp__sub_82294770) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,16840
	r31.s64 = r11.s64 + 16840;
	// lwz r11,16840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16840);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294920
	if (!cr6.eq) goto loc_82294920;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822947A0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822947b4
	if (cr6.eq) goto loc_822947B4;
	// bl 0x821d5408
	ctx.lr = 0x822947B0;
	sub_821D5408(ctx, base);
	// b 0x822947b8
	goto loc_822947B8;
loc_822947B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822947B8:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,13516
	ctx.r7.s64 = ctx.r10.s64 + 13516;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,17240
	ctx.r9.s64 = r11.s64 + 17240;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,44
	ctx.r5.s64 = 44;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,17064
	ctx.r4.s64 = ctx.r8.s64 + 17064;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,-5048
	ctx.r8.s64 = ctx.r10.s64 + -5048;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,-5072
	ctx.r9.s64 = ctx.r3.s64 + -5072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r6,r5,-5024
	ctx.r6.s64 = ctx.r5.s64 + -5024;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r4,-5000
	ctx.r5.s64 = ctx.r4.s64 + -5000;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r4,r7,-4976
	ctx.r4.s64 = ctx.r7.s64 + -4976;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// li r11,12
	r11.s64 = 12;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r6,r8,-4952
	ctx.r6.s64 = ctx.r8.s64 + -4952;
	// addi r5,r7,-4928
	ctx.r5.s64 = ctx.r7.s64 + -4928;
	// addi r4,r30,-4904
	ctx.r4.s64 = r30.s64 + -4904;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r11,24
	r11.s64 = 24;
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r5,r7,-4856
	ctx.r5.s64 = ctx.r7.s64 + -4856;
	// addi r6,r8,-4880
	ctx.r6.s64 = ctx.r8.s64 + -4880;
	// addi r4,r30,-4832
	ctx.r4.s64 = r30.s64 + -4832;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r11,36
	r11.s64 = 36;
	// li r10,40
	ctx.r10.s64 = 40;
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
	ctx.lr = 0x822948CC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822948DC;
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
	ctx.lr = 0x822948F8;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r8,-4808
	ctx.r4.s64 = ctx.r8.s64 + -4808;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4b00
	ctx.lr = 0x82294908;
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
	ctx.lr = 0x82294920;
	sub_821C0548(ctx, base);
loc_82294920:
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

__attribute__((alias("__imp__sub_82294938"))) PPC_WEAK_FUNC(sub_82294938);
PPC_FUNC_IMPL(__imp__sub_82294938) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,16824
	r31.s64 = r11.s64 + 16824;
	// lwz r11,16824(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294b48
	if (!cr6.eq) goto loc_82294B48;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82294968;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229497c
	if (cr6.eq) goto loc_8229497C;
	// bl 0x821d5408
	ctx.lr = 0x82294978;
	sub_821D5408(ctx, base);
	// b 0x82294980
	goto loc_82294980;
loc_8229497C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82294980:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32215
	r11.s64 = -2111242240;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,13536
	ctx.r7.s64 = ctx.r10.s64 + 13536;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,16712
	ctx.r9.s64 = r11.s64 + 16712;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32215
	ctx.r8.s64 = -2111242240;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,16520
	ctx.r4.s64 = ctx.r8.s64 + 16520;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-5900
	ctx.r9.s64 = ctx.r3.s64 + -5900;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,-5876
	ctx.r8.s64 = ctx.r10.s64 + -5876;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r6,r5,-5852
	ctx.r6.s64 = ctx.r5.s64 + -5852;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,24
	ctx.r9.s64 = 24;
	// addi r5,r4,-5828
	ctx.r5.s64 = ctx.r4.s64 + -5828;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,-5804
	ctx.r4.s64 = ctx.r7.s64 + -5804;
	// addi r6,r8,-5780
	ctx.r6.s64 = ctx.r8.s64 + -5780;
	// li r11,8
	r11.s64 = 8;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-5756
	ctx.r5.s64 = ctx.r7.s64 + -5756;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-5732
	ctx.r4.s64 = r30.s64 + -5732;
	// addi r6,r8,-5708
	ctx.r6.s64 = ctx.r8.s64 + -5708;
	// li r11,20
	r11.s64 = 20;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// li r9,29
	ctx.r9.s64 = 29;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-5684
	ctx.r5.s64 = ctx.r7.s64 + -5684;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-5660
	ctx.r4.s64 = r30.s64 + -5660;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r6,r8,-5636
	ctx.r6.s64 = ctx.r8.s64 + -5636;
	// li r11,30
	r11.s64 = 30;
	// li r10,31
	ctx.r10.s64 = 31;
	// addi r8,r7,-5612
	ctx.r8.s64 = ctx.r7.s64 + -5612;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,-5588
	ctx.r7.s64 = r30.s64 + -5588;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r11,33
	r11.s64 = 33;
	// li r10,34
	ctx.r10.s64 = 34;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r8,r6,-5564
	ctx.r8.s64 = ctx.r6.s64 + -5564;
	// addi r7,r11,-5540
	ctx.r7.s64 = r11.s64 + -5540;
	// addi r6,r10,-5516
	ctx.r6.s64 = ctx.r10.s64 + -5516;
	// li r11,36
	r11.s64 = 36;
	// li r10,40
	ctx.r10.s64 = 40;
	// li r9,44
	ctx.r9.s64 = 44;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// bl 0x821d4458
	ctx.lr = 0x82294AF4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x82294B04;
	sub_821D4100(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82294B20;
	sub_821D41D0(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-5456
	ctx.r4.s64 = ctx.r10.s64 + -5456;
	// bl 0x821d4b00
	ctx.lr = 0x82294B30;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x82294B48;
	sub_821C0548(ctx, base);
loc_82294B48:
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

__attribute__((alias("__imp__sub_82294B60"))) PPC_WEAK_FUNC(sub_82294B60);
PPC_FUNC_IMPL(__imp__sub_82294B60) {
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
	// bl 0x825018f8
	ctx.lr = 0x82294B78;
	sub_825018F8(ctx, base);
	// lbz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,13872
	ctx.r9.s64 = ctx.r10.s64 + 13872;
	// clrlwi r7,r8,26
	ctx.r7.u64 = ctx.r8.u32 & 0x3F;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stb r7,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_82294BB4"))) PPC_WEAK_FUNC(sub_82294BB4);
PPC_FUNC_IMPL(__imp__sub_82294BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294BB8"))) PPC_WEAK_FUNC(sub_82294BB8);
PPC_FUNC_IMPL(__imp__sub_82294BB8) {
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
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82294c3c
	if (!cr6.eq) goto loc_82294C3C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,40(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// lwz r9,36(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// bl 0x82501030
	ctx.lr = 0x82294BFC;
	sub_82501030(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82294c3c
	if (cr6.eq) goto loc_82294C3C;
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// bl 0x825011f8
	ctx.lr = 0x82294C1C;
	sub_825011F8(ctx, base);
	// lbz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// rlwimi r9,r8,6,25,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0x40) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
	// bl 0x821c9788
	ctx.lr = 0x82294C30;
	sub_821C9788(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// stw r6,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r6.u32);
loc_82294C3C:
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

__attribute__((alias("__imp__sub_82294C50"))) PPC_WEAK_FUNC(sub_82294C50);
PPC_FUNC_IMPL(__imp__sub_82294C50) {
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
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82294c9c
	if (cr6.eq) goto loc_82294C9C;
	// bl 0x82501158
	ctx.lr = 0x82294C78;
	sub_82501158(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82294c9c
	if (cr6.eq) goto loc_82294C9C;
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
loc_82294C9C:
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

__attribute__((alias("__imp__sub_82294CB0"))) PPC_WEAK_FUNC(sub_82294CB0);
PPC_FUNC_IMPL(__imp__sub_82294CB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82501118
	sub_82501118(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82294CC4"))) PPC_WEAK_FUNC(sub_82294CC4);
PPC_FUNC_IMPL(__imp__sub_82294CC4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294CC8"))) PPC_WEAK_FUNC(sub_82294CC8);
PPC_FUNC_IMPL(__imp__sub_82294CC8) {
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
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82294d40
	if (cr6.eq) goto loc_82294D40;
	// bl 0x825016a0
	ctx.lr = 0x82294CF0;
	sub_825016A0(ctx, base);
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82294d40
	if (!cr6.eq) goto loc_82294D40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825011f8
	ctx.lr = 0x82294D08;
	sub_825011F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294d2c
	if (!cr6.eq) goto loc_82294D2C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825011e8
	ctx.lr = 0x82294D1C;
	sub_825011E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82294d30
	if (cr6.eq) goto loc_82294D30;
loc_82294D2C:
	// li r11,1
	r11.s64 = 1;
loc_82294D30:
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwimi r10,r9,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
loc_82294D40:
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

__attribute__((alias("__imp__sub_82294D54"))) PPC_WEAK_FUNC(sub_82294D54);
PPC_FUNC_IMPL(__imp__sub_82294D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294D58"))) PPC_WEAK_FUNC(sub_82294D58);
PPC_FUNC_IMPL(__imp__sub_82294D58) {
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
	// bl 0x825011a0
	ctx.lr = 0x82294D70;
	sub_825011A0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82294d80
	if (!cr6.gt) goto loc_82294D80;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
loc_82294D80:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
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

__attribute__((alias("__imp__sub_82294D98"))) PPC_WEAK_FUNC(sub_82294D98);
PPC_FUNC_IMPL(__imp__sub_82294D98) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825011a0
	ctx.lr = 0x82294DB0;
	sub_825011A0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82294dc0
	if (!cr6.gt) goto loc_82294DC0;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
loc_82294DC0:
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
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

__attribute__((alias("__imp__sub_82294DF4"))) PPC_WEAK_FUNC(sub_82294DF4);
PPC_FUNC_IMPL(__imp__sub_82294DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294DF8"))) PPC_WEAK_FUNC(sub_82294DF8);
PPC_FUNC_IMPL(__imp__sub_82294DF8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825011a0
	ctx.lr = 0x82294E1C;
	sub_825011A0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82294e2c
	if (!cr6.gt) goto loc_82294E2C;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
loc_82294E2C:
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x82293e30
	ctx.lr = 0x82294E54;
	sub_82293E30(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_82294E70"))) PPC_WEAK_FUNC(sub_82294E70);
PPC_FUNC_IMPL(__imp__sub_82294E70) {
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
	// bl 0x821c9788
	ctx.lr = 0x82294E88;
	sub_821C9788(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// subf r3,r11,r3
	ctx.r3.s64 = ctx.r3.s64 - r11.s64;
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

__attribute__((alias("__imp__sub_82294EA4"))) PPC_WEAK_FUNC(sub_82294EA4);
PPC_FUNC_IMPL(__imp__sub_82294EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294EA8"))) PPC_WEAK_FUNC(sub_82294EA8);
PPC_FUNC_IMPL(__imp__sub_82294EA8) {
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
	// bl 0x82501208
	ctx.lr = 0x82294EC8;
	sub_82501208(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82294ee0
	if (cr6.eq) goto loc_82294EE0;
	// bl 0x82130588
	ctx.lr = 0x82294EDC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82294EE0:
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

__attribute__((alias("__imp__sub_82294EF8"))) PPC_WEAK_FUNC(sub_82294EF8);
PPC_FUNC_IMPL(__imp__sub_82294EF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82294f60
	if (cr6.eq) goto loc_82294F60;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_82294F10:
	// cmpwi cr6,r3,16
	cr6.compare<int32_t>(ctx.r3.s32, 16, xer);
	// beq cr6,0x82294f60
	if (cr6.eq) goto loc_82294F60;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_82294F20:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82294f44
	if (cr6.eq) goto loc_82294F44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82294f20
	if (cr6.eq) goto loc_82294F20;
loc_82294F44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82294f10
	if (!cr6.eq) goto loc_82294F10;
loc_82294F60:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294F68"))) PPC_WEAK_FUNC(sub_82294F68);
PPC_FUNC_IMPL(__imp__sub_82294F68) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294F74"))) PPC_WEAK_FUNC(sub_82294F74);
PPC_FUNC_IMPL(__imp__sub_82294F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82294F78"))) PPC_WEAK_FUNC(sub_82294F78);
PPC_FUNC_IMPL(__imp__sub_82294F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
loc_82294F84:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82294fd0
	if (cr6.eq) goto loc_82294FD0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_82294F94:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82294fb8
	if (cr6.eq) goto loc_82294FB8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82294f94
	if (cr6.eq) goto loc_82294F94;
loc_82294FB8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r8,r8,76
	ctx.r8.s64 = ctx.r8.s64 + 76;
	// cmpwi cr6,r3,32
	cr6.compare<int32_t>(ctx.r3.s32, 32, xer);
	// bne cr6,0x82294f84
	if (!cr6.eq) goto loc_82294F84;
loc_82294FD0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294FD8"))) PPC_WEAK_FUNC(sub_82294FD8);
PPC_FUNC_IMPL(__imp__sub_82294FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mulli r10,r4,76
	ctx.r10.s64 = ctx.r4.s64 * 76;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r5,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82294FF0"))) PPC_WEAK_FUNC(sub_82294FF0);
PPC_FUNC_IMPL(__imp__sub_82294FF0) {
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// bl 0x82294f78
	ctx.lr = 0x82295004;
	sub_82294F78(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82295020
	if (!cr6.lt) goto loc_82295020;
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
loc_82295020:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mulli r11,r3,76
	r11.s64 = ctx.r3.s64 * 76;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82294ef8
	ctx.lr = 0x82295038;
	sub_82294EF8(ctx, base);
	// stw r3,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r3.u32);
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
}

__attribute__((alias("__imp__sub_82295050"))) PPC_WEAK_FUNC(sub_82295050);
PPC_FUNC_IMPL(__imp__sub_82295050) {
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
	ctx.lr = 0x82295058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e8e40
	ctx.lr = 0x8229506C;
	sub_824E8E40(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x822950f0
	if (cr6.eq) goto loc_822950F0;
	// li r31,0
	r31.s64 = 0;
loc_82295084:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x824e9038
	ctx.lr = 0x82295090;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822950d8
	if (cr6.lt) goto loc_822950D8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e9740
	ctx.lr = 0x822950A8;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// blt cr6,0x822950d8
	if (cr6.lt) goto loc_822950D8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// addi r5,r11,72
	ctx.r5.s64 = r11.s64 + 72;
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822950d8
	if (cr6.eq) goto loc_822950D8;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e9530
	ctx.lr = 0x822950D8;
	sub_824E9530(ctx, base);
loc_822950D8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r31,r27,76
	r31.s64 = r27.s64 * 76;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82295084
	if (!cr6.eq) goto loc_82295084;
loc_822950F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822950F8"))) PPC_WEAK_FUNC(sub_822950F8);
PPC_FUNC_IMPL(__imp__sub_822950F8) {
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
	ctx.lr = 0x82295100;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r27
	r29.u64 = r27.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x82295184
	if (cr6.eq) goto loc_82295184;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82295128:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x824e9038
	ctx.lr = 0x82295134;
	sub_824E9038(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8229516c
	if (cr6.lt) goto loc_8229516C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e9740
	ctx.lr = 0x82295150;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x8229516c
	if (!cr6.eq) goto loc_8229516C;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e9690
	ctx.lr = 0x8229516C;
	sub_824E9690(ctx, base);
loc_8229516C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mulli r10,r29,76
	ctx.r10.s64 = r29.s64 * 76;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x82295128
	if (!cr6.eq) goto loc_82295128;
loc_82295184:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229518C"))) PPC_WEAK_FUNC(sub_8229518C);
PPC_FUNC_IMPL(__imp__sub_8229518C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295190"))) PPC_WEAK_FUNC(sub_82295190);
PPC_FUNC_IMPL(__imp__sub_82295190) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,-1
	ctx.r8.s64 = -1;
loc_822951A8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r8.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mulli r11,r10,76
	r11.s64 = ctx.r10.s64 * 76;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x822951a8
	if (!cr6.eq) goto loc_822951A8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822951CC"))) PPC_WEAK_FUNC(sub_822951CC);
PPC_FUNC_IMPL(__imp__sub_822951CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822951D0"))) PPC_WEAK_FUNC(sub_822951D0);
PPC_FUNC_IMPL(__imp__sub_822951D0) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x822951F8;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295214
	if (cr6.eq) goto loc_82295214;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x82619408
	ctx.lr = 0x82295214;
	sub_82619408(ctx, base);
loc_82295214:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229521C;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82295234"))) PPC_WEAK_FUNC(sub_82295234);
PPC_FUNC_IMPL(__imp__sub_82295234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295238"))) PPC_WEAK_FUNC(sub_82295238);
PPC_FUNC_IMPL(__imp__sub_82295238) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295260;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// beq cr6,0x82295284
	if (cr6.eq) goto loc_82295284;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x826193a0
	ctx.lr = 0x82295284;
	sub_826193A0(ctx, base);
loc_82295284:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821c9030
	ctx.lr = 0x82295290;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_822952AC"))) PPC_WEAK_FUNC(sub_822952AC);
PPC_FUNC_IMPL(__imp__sub_822952AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822952B0"))) PPC_WEAK_FUNC(sub_822952B0);
PPC_FUNC_IMPL(__imp__sub_822952B0) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x822952D8;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// beq cr6,0x822952fc
	if (cr6.eq) goto loc_822952FC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// bl 0x826193a0
	ctx.lr = 0x822952FC;
	sub_826193A0(ctx, base);
loc_822952FC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821c9030
	ctx.lr = 0x82295308;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_82295324"))) PPC_WEAK_FUNC(sub_82295324);
PPC_FUNC_IMPL(__imp__sub_82295324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295328"))) PPC_WEAK_FUNC(sub_82295328);
PPC_FUNC_IMPL(__imp__sub_82295328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r5,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r5.u8);
	// stb r11,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82295338"))) PPC_WEAK_FUNC(sub_82295338);
PPC_FUNC_IMPL(__imp__sub_82295338) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82295340;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,520
	r29.s64 = r31.s64 + 520;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// stb r30,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r30.u8);
	// bl 0x82618750
	ctx.lr = 0x82295364;
	sub_82618750(ctx, base);
	// addi r28,r31,552
	r28.s64 = r31.s64 + 552;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618750
	ctx.lr = 0x82295370;
	sub_82618750(ctx, base);
	// addi r27,r31,584
	r27.s64 = r31.s64 + 584;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618750
	ctx.lr = 0x8229537C;
	sub_82618750(ctx, base);
	// stw r30,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r30.u32);
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// addi r3,r31,1396
	ctx.r3.s64 = r31.s64 + 1396;
	// stw r30,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x82295390;
	sub_821C8ED8(ctx, base);
	// addi r26,r31,6
	r26.s64 = r31.s64 + 6;
	// li r5,512
	ctx.r5.s64 = 512;
	// stw r30,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r30.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r30,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x822953B0;
	sub_823D9890(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618750
	ctx.lr = 0x822953B8;
	sub_82618750(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82618610
	ctx.lr = 0x822953CC;
	sub_82618610(ctx, base);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826189a8
	ctx.lr = 0x822953D8;
	sub_826189A8(ctx, base);
	// stw r30,548(r31)
	PPC_STORE_U32(r31.u32 + 548, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r29,r31,548
	r29.s64 = r31.s64 + 548;
	// bl 0x82618750
	ctx.lr = 0x822953E8;
	sub_82618750(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82618610
	ctx.lr = 0x822953FC;
	sub_82618610(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826189a8
	ctx.lr = 0x82295408;
	sub_826189A8(ctx, base);
	// stw r30,580(r31)
	PPC_STORE_U32(r31.u32 + 580, r30.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r30,r31,580
	r30.s64 = r31.s64 + 580;
	// bl 0x82618750
	ctx.lr = 0x82295418;
	sub_82618750(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82618610
	ctx.lr = 0x8229542C;
	sub_82618610(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826189a8
	ctx.lr = 0x82295438;
	sub_826189A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82295444"))) PPC_WEAK_FUNC(sub_82295444);
PPC_FUNC_IMPL(__imp__sub_82295444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295448"))) PPC_WEAK_FUNC(sub_82295448);
PPC_FUNC_IMPL(__imp__sub_82295448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,1396
	ctx.r3.s64 = r11.s64 + 1396;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229545C"))) PPC_WEAK_FUNC(sub_8229545C);
PPC_FUNC_IMPL(__imp__sub_8229545C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295460"))) PPC_WEAK_FUNC(sub_82295460);
PPC_FUNC_IMPL(__imp__sub_82295460) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// bl 0x821c8fe0
	ctx.lr = 0x82295480;
	sub_821C8FE0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r11.u32);
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
	// stw r11,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r11.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// bl 0x821c9030
	ctx.lr = 0x822954A0;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_822954B4"))) PPC_WEAK_FUNC(sub_822954B4);
PPC_FUNC_IMPL(__imp__sub_822954B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822954B8"))) PPC_WEAK_FUNC(sub_822954B8);
PPC_FUNC_IMPL(__imp__sub_822954B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822954e4
	if (cr6.eq) goto loc_822954E4;
	// addi r11,r4,154
	r11.s64 = ctx.r4.s64 + 154;
	// addi r10,r4,153
	ctx.r10.s64 = ctx.r4.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// lwzx r6,r8,r3
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// subf r3,r6,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r6.s64;
	// blr 
	return;
loc_822954E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822954EC"))) PPC_WEAK_FUNC(sub_822954EC);
PPC_FUNC_IMPL(__imp__sub_822954EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822954F0"))) PPC_WEAK_FUNC(sub_822954F0);
PPC_FUNC_IMPL(__imp__sub_822954F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295504
	if (cr6.eq) goto loc_82295504;
	// lwz r3,1392(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1392);
	// blr 
	return;
loc_82295504:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229550C"))) PPC_WEAK_FUNC(sub_8229550C);
PPC_FUNC_IMPL(__imp__sub_8229550C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295510"))) PPC_WEAK_FUNC(sub_82295510);
PPC_FUNC_IMPL(__imp__sub_82295510) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229552c
	if (cr6.eq) goto loc_8229552C;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r3,888(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// blr 
	return;
loc_8229552C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82295534"))) PPC_WEAK_FUNC(sub_82295534);
PPC_FUNC_IMPL(__imp__sub_82295534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295538"))) PPC_WEAK_FUNC(sub_82295538);
PPC_FUNC_IMPL(__imp__sub_82295538) {
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
	ctx.lr = 0x82295540;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8229555C;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x82295634
	if (!cr6.eq) goto loc_82295634;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295598;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822955d0
	if (cr6.eq) goto loc_822955D0;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// b 0x822955d4
	goto loc_822955D4;
loc_822955D0:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822955D4:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r7,r29,r31
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// bl 0x826191b8
	ctx.lr = 0x822955F0;
	sub_826191B8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82295634
	if (cr6.eq) goto loc_82295634;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295630
	if (cr6.eq) goto loc_82295630;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// lwzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// subf r27,r10,r8
	r27.s64 = ctx.r8.s64 - ctx.r10.s64;
	// bl 0x821c9030
	ctx.lr = 0x82295624;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295630:
	// li r27,0
	r27.s64 = 0;
loc_82295634:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229563C;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82295648"))) PPC_WEAK_FUNC(sub_82295648);
PPC_FUNC_IMPL(__imp__sub_82295648) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295674;
	sub_821C8FE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x822956dc
	if (cr6.eq) goto loc_822956DC;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822956dc
	if (cr6.eq) goto loc_822956DC;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822956dc
	if (!cr6.eq) goto loc_822956DC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x822956B8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822956dc
	if (cr6.eq) goto loc_822956DC;
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82619330
	ctx.lr = 0x822956DC;
	sub_82619330(ctx, base);
loc_822956DC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f31.f64 = double(temp.f32);
	// bl 0x821c9030
	ctx.lr = 0x822956E8;
	sub_821C9030(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82295708"))) PPC_WEAK_FUNC(sub_82295708);
PPC_FUNC_IMPL(__imp__sub_82295708) {
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
	ctx.lr = 0x82295710;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295790
	if (cr6.eq) goto loc_82295790;
	// mr r30,r28
	r30.u64 = r28.u64;
	// bl 0x822954f0
	ctx.lr = 0x82295730;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82295790
	if (!cr6.gt) goto loc_82295790;
	// addi r29,r31,1396
	r29.s64 = r31.s64 + 1396;
loc_8229573C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295748;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295768
	if (cr6.eq) goto loc_82295768;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x826193a0
	ctx.lr = 0x82295768;
	sub_826193A0(ctx, base);
loc_82295768:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r27,80(r1)
	r27.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x821c9030
	ctx.lr = 0x82295774;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8229579c
	if (!cr6.eq) goto loc_8229579C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822954f0
	ctx.lr = 0x82295788;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8229573c
	if (cr6.lt) goto loc_8229573C;
loc_82295790:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8229579C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822957A8"))) PPC_WEAK_FUNC(sub_822957A8);
PPC_FUNC_IMPL(__imp__sub_822957A8) {
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
	ctx.lr = 0x822957B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229581c
	if (cr6.eq) goto loc_8229581C;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x822957CC;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8229581c
	if (!cr6.gt) goto loc_8229581C;
	// addi r29,r31,1396
	r29.s64 = r31.s64 + 1396;
loc_822957D8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x822957E4;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295800
	if (cr6.eq) goto loc_82295800;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,552
	ctx.r3.s64 = r31.s64 + 552;
	// bl 0x82619408
	ctx.lr = 0x82295800;
	sub_82619408(ctx, base);
loc_82295800:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295808;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822954f0
	ctx.lr = 0x82295814;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x822957d8
	if (cr6.lt) goto loc_822957D8;
loc_8229581C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82295824"))) PPC_WEAK_FUNC(sub_82295824);
PPC_FUNC_IMPL(__imp__sub_82295824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295828"))) PPC_WEAK_FUNC(sub_82295828);
PPC_FUNC_IMPL(__imp__sub_82295828) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82295850;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822958a0
	if (cr6.eq) goto loc_822958A0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295868;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822958a0
	if (cr6.eq) goto loc_822958A0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// bl 0x82619408
	ctx.lr = 0x82295884;
	sub_82619408(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295890;
	sub_822951D0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
loc_822958A0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822958A8;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_822958C0"))) PPC_WEAK_FUNC(sub_822958C0);
PPC_FUNC_IMPL(__imp__sub_822958C0) {
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
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295914
	if (cr6.eq) goto loc_82295914;
	// li r31,0
	r31.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x822958EC;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82295914
	if (!cr6.gt) goto loc_82295914;
loc_822958F4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295828
	ctx.lr = 0x82295900;
	sub_82295828(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x822954f0
	ctx.lr = 0x8229590C;
	sub_822954F0(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x822958f4
	if (cr6.lt) goto loc_822958F4;
loc_82295914:
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

__attribute__((alias("__imp__sub_8229592C"))) PPC_WEAK_FUNC(sub_8229592C);
PPC_FUNC_IMPL(__imp__sub_8229592C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295930"))) PPC_WEAK_FUNC(sub_82295930);
PPC_FUNC_IMPL(__imp__sub_82295930) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x82295958;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295998
	if (cr6.eq) goto loc_82295998;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295970;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82295998
	if (!cr6.eq) goto loc_82295998;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// bl 0x82619408
	ctx.lr = 0x8229598C;
	sub_82619408(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295998;
	sub_822951D0(ctx, base);
loc_82295998:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822959A0;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_822959B8"))) PPC_WEAK_FUNC(sub_822959B8);
PPC_FUNC_IMPL(__imp__sub_822959B8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x822959D4;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822959f0
	if (cr6.eq) goto loc_822959F0;
	// lwz r3,136(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822959F0:
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

__attribute__((alias("__imp__sub_82295A04"))) PPC_WEAK_FUNC(sub_82295A04);
PPC_FUNC_IMPL(__imp__sub_82295A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295A08"))) PPC_WEAK_FUNC(sub_82295A08);
PPC_FUNC_IMPL(__imp__sub_82295A08) {
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
	ctx.lr = 0x82295A10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82295A30;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82295b14
	if (!cr6.eq) goto loc_82295B14;
	// cmpwi cr6,r29,32
	cr6.compare<int32_t>(r29.s32, 32, xer);
	// bgt cr6,0x82295b14
	if (cr6.gt) goto loc_82295B14;
	// li r3,0
	ctx.r3.s64 = 0;
	// addic. r28,r29,1
	xer.ca = r29.u32 > 4294967294;
	r28.s64 = r29.s64 + 1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// beq 0x82295ae4
	if (cr0.eq) goto loc_82295AE4;
	// addi r8,r31,612
	ctx.r8.s64 = r31.s64 + 612;
	// addi r7,r31,748
	ctx.r7.s64 = r31.s64 + 748;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_82295A64:
	// lwz r11,132(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,132(r8)
	PPC_STORE_U32(ctx.r8.u32 + 132, r11.u32);
	// stwx r9,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r9.u32);
	// lwz r11,128(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 128);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,128(r7)
	PPC_STORE_U32(ctx.r7.u32 + 128, ctx.r5.u32);
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// bge cr6,0x82295ad4
	if (!cr6.lt) goto loc_82295AD4;
	// lwz r11,1392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1392);
	// addi r6,r31,880
	ctx.r6.s64 = r31.s64 + 880;
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r30,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r30.u32);
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
loc_82295AD4:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// bne cr6,0x82295a64
	if (!cr6.eq) goto loc_82295A64;
loc_82295AE4:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// bl 0x822958c0
	ctx.lr = 0x82295AF4;
	sub_822958C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822957a8
	ctx.lr = 0x82295AFC;
	sub_822957A8(ctx, base);
	// stb r27,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r27.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295B08;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295B14:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295B1C;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82295B28"))) PPC_WEAK_FUNC(sub_82295B28);
PPC_FUNC_IMPL(__imp__sub_82295B28) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295b9c
	if (cr6.eq) goto loc_82295B9C;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x82295B4C;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82295b9c
	if (cr6.eq) goto loc_82295B9C;
	// addi r8,r10,880
	ctx.r8.s64 = ctx.r10.s64 + 880;
loc_82295B58:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_82295B60:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x82295b84
	if (cr6.eq) goto loc_82295B84;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82295b60
	if (cr6.eq) goto loc_82295B60;
loc_82295B84:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82295bb0
	if (cr6.eq) goto loc_82295BB0;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpw cr6,r7,r3
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r3.s32, xer);
	// bne cr6,0x82295b58
	if (!cr6.eq) goto loc_82295B58;
loc_82295B9C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82295BB0:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82295BC4"))) PPC_WEAK_FUNC(sub_82295BC4);
PPC_FUNC_IMPL(__imp__sub_82295BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295BC8"))) PPC_WEAK_FUNC(sub_82295BC8);
PPC_FUNC_IMPL(__imp__sub_82295BC8) {
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
	ctx.lr = 0x82295BD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82295BEC;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, ctx.r10.u32);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82295c78
	if (cr6.eq) goto loc_82295C78;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x82295c78
	if (!cr6.eq) goto loc_82295C78;
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r10,r30,154
	ctx.r10.s64 = r30.s64 + 154;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf. r29,r7,r6
	r29.s64 = ctx.r6.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// ble 0x82295c78
	if (!cr0.gt) goto loc_82295C78;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// bl 0x82619268
	ctx.lr = 0x82295C50;
	sub_82619268(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295c78
	if (cr6.eq) goto loc_82295C78;
	// stwx r29,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r29.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295C6C;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82295C78;
	sub_82295930(ctx, base);
loc_82295C78:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r28,r31
	r31.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82295C84;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82295C90"))) PPC_WEAK_FUNC(sub_82295C90);
PPC_FUNC_IMPL(__imp__sub_82295C90) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295CB8;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82295d4c
	if (cr6.eq) goto loc_82295D4C;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295d4c
	if (cr6.eq) goto loc_82295D4C;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82295d4c
	if (!cr6.eq) goto loc_82295D4C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295CF8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295d4c
	if (cr6.eq) goto loc_82295D4C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295d30
	if (cr6.eq) goto loc_82295D30;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// b 0x82295d34
	goto loc_82295D34;
loc_82295D30:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82295D34:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273c30
	ctx.lr = 0x82295D4C;
	sub_82273C30(ctx, base);
loc_82295D4C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82295D54;
	sub_821C9030(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_82295D70"))) PPC_WEAK_FUNC(sub_82295D70);
PPC_FUNC_IMPL(__imp__sub_82295D70) {
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
	ctx.lr = 0x82295D78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82295D94;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r28,0
	r28.s64 = 0;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r28.u32);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82295dcc
	if (cr6.eq) goto loc_82295DCC;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r28,r6,r7
	r28.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_82295DCC:
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r11,r10,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// ble cr6,0x82295df8
	if (!cr6.gt) goto loc_82295DF8;
loc_82295DE4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295DEC;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295DF8:
	// subfic r11,r11,-1
	xer.ca = r11.u32 <= 4294967295;
	r11.s64 = -1 - r11.s64;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82295de4
	if (cr6.lt) goto loc_82295DE4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295E10;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295e30
	if (cr6.eq) goto loc_82295E30;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295c90
	ctx.lr = 0x82295E28;
	sub_82295C90(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// beq cr6,0x82295de4
	if (cr6.eq) goto loc_82295DE4;
loc_82295E30:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273cd0
	ctx.lr = 0x82295E4C;
	sub_82273CD0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82295e74
	if (cr6.eq) goto loc_82295E74;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x82295E64;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82295E70;
	sub_82295930(ctx, base);
	// stwx r28,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r28.u32);
loc_82295E74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r27,r31
	r31.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82295E80;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82295E8C"))) PPC_WEAK_FUNC(sub_82295E8C);
PPC_FUNC_IMPL(__imp__sub_82295E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82295E90"))) PPC_WEAK_FUNC(sub_82295E90);
PPC_FUNC_IMPL(__imp__sub_82295E90) {
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
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82295EB8;
	sub_821C8FE0(ctx, base);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82295f4c
	if (cr6.eq) goto loc_82295F4C;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295f4c
	if (cr6.eq) goto loc_82295F4C;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82295f4c
	if (!cr6.eq) goto loc_82295F4C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82295EF8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295f4c
	if (cr6.eq) goto loc_82295F4C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82295f30
	if (cr6.eq) goto loc_82295F30;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// b 0x82295f34
	goto loc_82295F34;
loc_82295F30:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82295F34:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273d70
	ctx.lr = 0x82295F4C;
	sub_82273D70(ctx, base);
loc_82295F4C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82295F54;
	sub_821C9030(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_82295F70"))) PPC_WEAK_FUNC(sub_82295F70);
PPC_FUNC_IMPL(__imp__sub_82295F70) {
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
	ctx.lr = 0x82295F78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82295F94;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r29.u32);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82295fcc
	if (cr6.eq) goto loc_82295FCC;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r29,r6,r7
	r29.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_82295FCC:
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r9,r10,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// cmplw cr6,r28,r8
	cr6.compare<uint32_t>(r28.u32, ctx.r8.u32, xer);
	// ble cr6,0x82295ffc
	if (!cr6.gt) goto loc_82295FFC;
loc_82295FE8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82295FF0;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82295FFC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296008;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296028
	if (cr6.eq) goto loc_82296028;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82296020;
	sub_82295E90(ctx, base);
	// cmplw cr6,r3,r28
	cr6.compare<uint32_t>(ctx.r3.u32, r28.u32, xer);
	// beq cr6,0x82295fe8
	if (cr6.eq) goto loc_82295FE8;
loc_82296028:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82273058
	ctx.lr = 0x82296044;
	sub_82273058(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229606c
	if (cr6.eq) goto loc_8229606C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x8229605C;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82296068;
	sub_82295930(ctx, base);
	// stwx r29,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r29.u32);
loc_8229606C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r27,r31
	r31.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82296078;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82296084"))) PPC_WEAK_FUNC(sub_82296084);
PPC_FUNC_IMPL(__imp__sub_82296084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296088"))) PPC_WEAK_FUNC(sub_82296088);
PPC_FUNC_IMPL(__imp__sub_82296088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82296090;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x822960B0;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r29.u32);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822960e8
	if (cr6.eq) goto loc_822960E8;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r29,r6,r7
	r29.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_822960E8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x822960F4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229612c
	if (cr6.eq) goto loc_8229612C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295648
	ctx.lr = 0x8229610C;
	sub_82295648(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x8229612c
	if (!cr6.eq) goto loc_8229612C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229611C;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8229612C:
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r3,r31,520
	ctx.r3.s64 = r31.s64 + 520;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82619370
	ctx.lr = 0x82296144;
	sub_82619370(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229616c
	if (cr6.eq) goto loc_8229616C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x8229615C;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x82296168;
	sub_82295930(ctx, base);
	// stwx r29,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, r29.u32);
loc_8229616C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r28,r31
	r31.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x82296178;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82296188"))) PPC_WEAK_FUNC(sub_82296188);
PPC_FUNC_IMPL(__imp__sub_82296188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x82296190;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822963a8
	if (cr6.eq) goto loc_822963A8;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822963a8
	if (cr6.eq) goto loc_822963A8;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822954f0
	ctx.lr = 0x822961B8;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822963a8
	if (cr6.eq) goto loc_822963A8;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r20,r4,24
	r20.u64 = ctx.r4.u32 & 0xFF;
	// addi r21,r31,612
	r21.s64 = r31.s64 + 612;
	// addi r25,r31,888
	r25.s64 = r31.s64 + 888;
	// addi r24,r5,14236
	r24.s64 = ctx.r5.s64 + 14236;
	// addi r27,r6,14220
	r27.s64 = ctx.r6.s64 + 14220;
	// addi r23,r7,14200
	r23.s64 = ctx.r7.s64 + 14200;
	// addi r26,r8,9792
	r26.s64 = ctx.r8.s64 + 9792;
	// addi r29,r9,32684
	r29.s64 = ctx.r9.s64 + 32684;
	// addi r22,r10,14180
	r22.s64 = ctx.r10.s64 + 14180;
	// addi r28,r11,14168
	r28.s64 = r11.s64 + 14168;
loc_82296204:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x82296224
	if (cr6.eq) goto loc_82296224;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82296218;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229638c
	if (cr6.eq) goto loc_8229638C;
loc_82296224:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296230;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296264
	if (!cr6.eq) goto loc_82296264;
	// mr r11,r28
	r11.u64 = r28.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8229624C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8229624c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229624C;
	// b 0x8229638c
	goto loc_8229638C;
loc_82296264:
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82296278
	if (cr6.eq) goto loc_82296278;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x8229627c
	goto loc_8229627C;
loc_82296278:
	// li r11,-1
	r11.s64 = -1;
loc_8229627C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8229638c
	if (cr6.gt) goto loc_8229638C;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,25248
	r12.s64 = r12.s64 + 25248;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822962B8;
	case 1:
		goto loc_822962C0;
	case 2:
		goto loc_822962E4;
	case 3:
		goto loc_82296308;
	case 4:
		goto loc_82296330;
	case 5:
		goto loc_82296338;
	default:
		__builtin_unreachable();
	}
	// lwz r17,25272(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25272);
	// lwz r17,25280(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25280);
	// lwz r17,25316(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25316);
	// lwz r17,25352(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25352);
	// lwz r17,25392(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25392);
	// lwz r17,25400(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 25400);
loc_822962B8:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// b 0x82296380
	goto loc_82296380;
loc_822962C0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295c90
	ctx.lr = 0x822962CC;
	sub_82295C90(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822962E0;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
loc_822962E4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822962F0;
	sub_82295E90(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82296304;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
loc_82296308:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295648
	ctx.lr = 0x82296314;
	sub_82295648(ctx, base);
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8229632C;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
loc_82296330:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// b 0x82296380
	goto loc_82296380;
loc_82296338:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229637c
	if (cr6.eq) goto loc_8229637C;
	// lwz r11,4(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 4);
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r9,64
	cr6.compare<int32_t>(ctx.r9.s32, 64, xer);
	// bne cr6,0x8229637c
	if (!cr6.eq) goto loc_8229637C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x82296364;
	sub_82295538(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82296378;
	sub_82137A08(ctx, base);
	// b 0x8229638c
	goto loc_8229638C;
loc_8229637C:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
loc_82296380:
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8229638C;
	sub_82137A08(ctx, base);
loc_8229638C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r25,r25,16
	r25.s64 = r25.s64 + 16;
	// bl 0x822954f0
	ctx.lr = 0x822963A0;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x82296204
	if (!cr6.eq) goto loc_82296204;
loc_822963A8:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822963B0"))) PPC_WEAK_FUNC(sub_822963B0);
PPC_FUNC_IMPL(__imp__sub_822963B0) {
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
	ctx.lr = 0x822963B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822963e4
	if (cr6.eq) goto loc_822963E4;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r29,892(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 892);
	// b 0x822963e8
	goto loc_822963E8;
loc_822963E4:
	// li r29,0
	r29.s64 = 0;
loc_822963E8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x822963F4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9038
	ctx.lr = 0x82296414;
	sub_824E9038(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// addi r11,r30,154
	r11.s64 = r30.s64 + 154;
	// addi r10,r30,153
	ctx.r10.s64 = r30.s64 + 153;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// subf r29,r6,r7
	r29.s64 = ctx.r7.s64 - ctx.r6.s64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822964d4
	if (cr6.eq) goto loc_822964D4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9740
	ctx.lr = 0x82296454;
	sub_824E9740(ctx, base);
	// addi r11,r29,31
	r11.s64 = r29.s64 + 31;
	// rlwinm r10,r11,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// srawi r9,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// bne cr6,0x822964d4
	if (!cr6.eq) goto loc_822964D4;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296488
	if (cr6.eq) goto loc_82296488;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r11,888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// b 0x8229648c
	goto loc_8229648C;
loc_82296488:
	// li r11,-1
	r11.s64 = -1;
loc_8229648C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x822964b0
	if (cr6.lt) goto loc_822964B0;
	// bne cr6,0x822964d4
	if (!cr6.eq) goto loc_822964D4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822964A4;
	sub_82295E90(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// b 0x822964c4
	goto loc_822964C4;
loc_822964B0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295c90
	ctx.lr = 0x822964BC;
	sub_82295C90(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
loc_822964C4:
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9530
	ctx.lr = 0x822964D4;
	sub_824E9530(ctx, base);
loc_822964D4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822964DC"))) PPC_WEAK_FUNC(sub_822964DC);
PPC_FUNC_IMPL(__imp__sub_822964DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822964E0"))) PPC_WEAK_FUNC(sub_822964E0);
PPC_FUNC_IMPL(__imp__sub_822964E0) {
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
	ctx.lr = 0x822964E8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// bl 0x826185a0
	ctx.lr = 0x822964F8;
	sub_826185A0(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lbz r4,1(r21)
	ctx.r4.u64 = PPC_LOAD_U8(r21.u32 + 1);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r22,r21,1
	r22.s64 = r21.s64 + 1;
	// bl 0x82250f50
	ctx.lr = 0x82296510;
	sub_82250F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r20,-32121
	r20.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229655c
	if (cr6.eq) goto loc_8229655C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lbz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// bl 0x82618f70
	ctx.lr = 0x8229652C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229655c
	if (cr6.eq) goto loc_8229655C;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-10240(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x82296544;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229655c
	if (cr6.eq) goto loc_8229655C;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82296560
	if (!cr6.eq) goto loc_82296560;
loc_8229655C:
	// li r11,0
	r11.s64 = 0;
loc_82296560:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82296778
	if (cr6.eq) goto loc_82296778;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-10240(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x82296578;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82296588
	if (cr6.eq) goto loc_82296588;
	// lwz r28,136(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8229658c
	goto loc_8229658C;
loc_82296588:
	// li r28,0
	r28.s64 = 0;
loc_8229658C:
	// addi r4,r28,1396
	ctx.r4.s64 = r28.s64 + 1396;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x82296598;
	sub_821C8FE0(ctx, base);
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822965dc
	if (!cr6.eq) goto loc_822965DC;
	// addi r31,r28,552
	r31.s64 = r28.s64 + 552;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822965B4;
	sub_82618830(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822965c8
	if (cr6.eq) goto loc_822965C8;
	// lwz r5,1392(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 1392);
	// b 0x822965cc
	goto loc_822965CC;
loc_822965C8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822965CC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x822965D8;
	sub_82618C80(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_822965DC:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296620
	if (cr6.eq) goto loc_82296620;
	// addi r31,r28,584
	r31.s64 = r28.s64 + 584;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822965F8;
	sub_82618830(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229660c
	if (cr6.eq) goto loc_8229660C;
	// lwz r5,1392(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 1392);
	// b 0x82296610
	goto loc_82296610;
loc_8229660C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82296610:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x8229661C;
	sub_82618C80(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_82296620:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296770
	if (cr6.eq) goto loc_82296770;
	// addi r29,r28,612
	r29.s64 = r28.s64 + 612;
	// addi r24,r28,888
	r24.s64 = r28.s64 + 888;
loc_82296638:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822954f0
	ctx.lr = 0x82296640;
	sub_822954F0(ctx, base);
	// cmpw cr6,r26,r3
	cr6.compare<int32_t>(r26.s32, ctx.r3.s32, xer);
	// bge cr6,0x82296770
	if (!cr6.lt) goto loc_82296770;
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229666c
	if (!cr6.eq) goto loc_8229666C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295238
	ctx.lr = 0x82296660;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
loc_8229666C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296678;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822966a0
	if (cr6.eq) goto loc_822966A0;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// subf r31,r9,r10
	r31.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x822966a4
	goto loc_822966A4;
loc_822966A0:
	// li r31,0
	r31.s64 = 0;
loc_822966A4:
	// mr r30,r31
	r30.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// beq cr6,0x8229670c
	if (cr6.eq) goto loc_8229670C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8229670c
	if (!cr6.eq) goto loc_8229670C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826185a0
	ctx.lr = 0x822966C8;
	sub_826185A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822966dc
	if (!cr6.eq) goto loc_822966DC;
	// lwz r30,136(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
loc_822966DC:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822966fc
	if (cr6.eq) goto loc_822966FC;
loc_822966EC:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822966ec
	if (!cr6.eq) goto loc_822966EC;
loc_822966FC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82299788
	ctx.lr = 0x82296708;
	sub_82299788(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8229670C:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
	// addi r31,r28,520
	r31.s64 = r28.s64 + 520;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82296728;
	sub_82618830(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x82296738;
	sub_82618C80(ctx, base);
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296758
	if (cr6.eq) goto loc_82296758;
	// stw r30,136(r29)
	PPC_STORE_U32(r29.u32 + 136, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822951d0
	ctx.lr = 0x82296758;
	sub_822951D0(ctx, base);
loc_82296758:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r24,r24,16
	r24.s64 = r24.s64 + 16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296638
	if (!cr6.eq) goto loc_82296638;
loc_82296770:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82296778;
	sub_821C9030(ctx, base);
loc_82296778:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822967c8
	if (cr6.eq) goto loc_822967C8;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822967c8
	if (cr6.eq) goto loc_822967C8;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,-10240(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x8229679C;
	sub_82270180(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822967bc
	if (cr6.eq) goto loc_822967BC;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
loc_822967BC:
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
loc_822967C8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822967D4"))) PPC_WEAK_FUNC(sub_822967D4);
PPC_FUNC_IMPL(__imp__sub_822967D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822967D8"))) PPC_WEAK_FUNC(sub_822967D8);
PPC_FUNC_IMPL(__imp__sub_822967D8) {
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
	ctx.lr = 0x822967E0;
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
	ctx.lr = 0x82296804;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82296810;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82296820;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82296844
	if (cr6.eq) goto loc_82296844;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822964e0
	ctx.lr = 0x82296834;
	sub_822964E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296848
	if (!cr6.eq) goto loc_82296848;
loc_82296844:
	// li r30,0
	r30.s64 = 0;
loc_82296848:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82296880
	if (cr6.eq) goto loc_82296880;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296878
	if (cr6.eq) goto loc_82296878;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82296864;
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
loc_82296878:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82296880:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229688C"))) PPC_WEAK_FUNC(sub_8229688C);
PPC_FUNC_IMPL(__imp__sub_8229688C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296890"))) PPC_WEAK_FUNC(sub_82296890);
PPC_FUNC_IMPL(__imp__sub_82296890) {
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
	ctx.lr = 0x82296898;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16844
	ctx.r10.s64 = r11.s64 + 16844;
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
	// bl 0x822967d8
	ctx.lr = 0x822968CC;
	sub_822967D8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82296904
	if (cr6.eq) goto loc_82296904;
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
	ctx.lr = 0x822968F4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82296908
	if (!cr6.eq) goto loc_82296908;
loc_82296904:
	// li r11,0
	r11.s64 = 0;
loc_82296908:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82296914"))) PPC_WEAK_FUNC(sub_82296914);
PPC_FUNC_IMPL(__imp__sub_82296914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296918"))) PPC_WEAK_FUNC(sub_82296918);
PPC_FUNC_IMPL(__imp__sub_82296918) {
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
	ctx.lr = 0x82296920;
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
	// blt cr6,0x8229698c
	if (cr6.lt) goto loc_8229698C;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x82296948;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229696c
	if (!cr6.eq) goto loc_8229696C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x82296960;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229698c
	if (cr6.eq) goto loc_8229698C;
loc_8229696C:
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
	// bl 0x82296890
	ctx.lr = 0x82296984;
	sub_82296890(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229698C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82296998"))) PPC_WEAK_FUNC(sub_82296998);
PPC_FUNC_IMPL(__imp__sub_82296998) {
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
	ctx.lr = 0x822969A0;
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
	ctx.lr = 0x822969C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822969fc
	if (cr6.eq) goto loc_822969FC;
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
	// beq cr6,0x822969f4
	if (cr6.eq) goto loc_822969F4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x822969fc
	if (!cr6.eq) goto loc_822969FC;
loc_822969F4:
	// li r11,1
	r11.s64 = 1;
	// b 0x82296a00
	goto loc_82296A00;
loc_822969FC:
	// li r11,0
	r11.s64 = 0;
loc_82296A00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296a3c
	if (cr6.eq) goto loc_82296A3C;
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
	// bl 0x82296918
	ctx.lr = 0x82296A34;
	sub_82296918(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82296A3C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82296A48"))) PPC_WEAK_FUNC(sub_82296A48);
PPC_FUNC_IMPL(__imp__sub_82296A48) {
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
	ctx.lr = 0x82296A50;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// li r30,1
	r30.s64 = 1;
	// addi r25,r4,12
	r25.s64 = ctx.r4.s64 + 12;
	// li r24,31
	r24.s64 = 31;
loc_82296A70:
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82296ac4
	if (cr6.eq) goto loc_82296AC4;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82296A84;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ac4
	if (cr6.eq) goto loc_82296AC4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296ac4
	if (!cr6.eq) goto loc_82296AC4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82296998
	ctx.lr = 0x82296AB8;
	sub_82296998(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_82296AC4:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x82296a70
	if (!cr0.eq) goto loc_82296A70;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82296ADC"))) PPC_WEAK_FUNC(sub_82296ADC);
PPC_FUNC_IMPL(__imp__sub_82296ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296AE0"))) PPC_WEAK_FUNC(sub_82296AE0);
PPC_FUNC_IMPL(__imp__sub_82296AE0) {
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
	ctx.lr = 0x82296AE8;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// bl 0x82295708
	ctx.lr = 0x82296B10;
	sub_82295708(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x824817c0
	ctx.lr = 0x82296B28;
	sub_824817C0(ctx, base);
	// addi r4,r3,12
	ctx.r4.s64 = ctx.r3.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ea3b8
	ctx.lr = 0x82296B34;
	sub_824EA3B8(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// mr r27,r30
	r27.u64 = r30.u64;
	// addi r28,r11,-10240
	r28.s64 = r11.s64 + -10240;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r10,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bne cr6,0x82296b84
	if (!cr6.eq) goto loc_82296B84;
	// bl 0x82296a48
	ctx.lr = 0x82296B80;
	sub_82296A48(ctx, base);
	// b 0x82296b90
	goto loc_82296B90;
loc_82296B84:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82296998
	ctx.lr = 0x82296B90;
	sub_82296998(ctx, base);
loc_82296B90:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822954f0
	ctx.lr = 0x82296B98;
	sub_822954F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82296c18
	if (!cr6.gt) goto loc_82296C18;
	// addi r29,r31,892
	r29.s64 = r31.s64 + 892;
loc_82296BA4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82296BB0;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c00
	if (cr6.eq) goto loc_82296C00;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296bd4
	if (cr6.eq) goto loc_82296BD4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82296c00
	if (cr6.eq) goto loc_82296C00;
loc_82296BD4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82296BE0;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c00
	if (cr6.eq) goto loc_82296C00;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822963b0
	ctx.lr = 0x82296BFC;
	sub_822963B0(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_82296C00:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bl 0x822954f0
	ctx.lr = 0x82296C10;
	sub_822954F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x82296ba4
	if (cr6.lt) goto loc_82296BA4;
loc_82296C18:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296c48
	if (cr6.eq) goto loc_82296C48;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x82296C34;
	sub_822950F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82486800
	ctx.lr = 0x82296C48;
	sub_82486800(ctx, base);
loc_82296C48:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82296C50"))) PPC_WEAK_FUNC(sub_82296C50);
PPC_FUNC_IMPL(__imp__sub_82296C50) {
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
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ce4
	if (cr6.eq) goto loc_82296CE4;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ce4
	if (cr6.eq) goto loc_82296CE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r7,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r7.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// bne cr6,0x82296cd0
	if (!cr6.eq) goto loc_82296CD0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82296a48
	ctx.lr = 0x82296CC0;
	sub_82296A48(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82296CD0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82296998
	ctx.lr = 0x82296CE4;
	sub_82296998(ctx, base);
loc_82296CE4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82296CF4"))) PPC_WEAK_FUNC(sub_82296CF4);
PPC_FUNC_IMPL(__imp__sub_82296CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296CF8"))) PPC_WEAK_FUNC(sub_82296CF8);
PPC_FUNC_IMPL(__imp__sub_82296CF8) {
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
	ctx.lr = 0x82296D00;
	// stwu r1,-3152(r1)
	ea = -3152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// li r31,30
	r31.s64 = 30;
loc_82296D14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x82296D1C;
	sub_824E71C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bge 0x82296d14
	if (!cr0.lt) goto loc_82296D14;
	// addi r27,r29,144
	r27.s64 = r29.s64 + 144;
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824817c8
	ctx.lr = 0x82296D3C;
	sub_824817C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82296dd0
	if (!cr6.gt) goto loc_82296DD0;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
loc_82296D50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82296D58;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82296D5C;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r28
	cr6.compare<uint64_t>(ctx.r3.u64, r28.u64, xer);
	// beq cr6,0x82296d7c
	if (cr6.eq) goto loc_82296D7C;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82296d50
	if (cr6.lt) goto loc_82296D50;
	// addi r1,r1,3152
	ctx.r1.s64 = ctx.r1.s64 + 3152;
	// b 0x823d9244
	return;
loc_82296D7C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f99c0
	ctx.lr = 0x82296D84;
	sub_824F99C0(ctx, base);
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82130000
	ctx.lr = 0x82296D9C;
	sub_82130000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82296DAC:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82296dac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82296DAC;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824853d0
	ctx.lr = 0x82296DD0;
	sub_824853D0(ctx, base);
loc_82296DD0:
	// addi r1,r1,3152
	ctx.r1.s64 = ctx.r1.s64 + 3152;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82296DD8"))) PPC_WEAK_FUNC(sub_82296DD8);
PPC_FUNC_IMPL(__imp__sub_82296DD8) {
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
	ctx.lr = 0x82296DE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
loc_82296DF4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296e1c
	if (cr6.eq) goto loc_82296E1C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296E08;
	sub_82502300(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f0550
	ctx.lr = 0x82296E10;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296e38
	if (!cr6.eq) goto loc_82296E38;
loc_82296E1C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// bne cr6,0x82296df4
	if (!cr6.eq) goto loc_82296DF4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82296E38:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r28
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82296E4C"))) PPC_WEAK_FUNC(sub_82296E4C);
PPC_FUNC_IMPL(__imp__sub_82296E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296E50"))) PPC_WEAK_FUNC(sub_82296E50);
PPC_FUNC_IMPL(__imp__sub_82296E50) {
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
	ctx.lr = 0x82296E58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r3,12
	r31.s64 = ctx.r3.s64 + 12;
loc_82296E68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296e90
	if (cr6.eq) goto loc_82296E90;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82296E7C;
	sub_824E7110(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f92f8
	ctx.lr = 0x82296E84;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82296eac
	if (!cr6.eq) goto loc_82296EAC;
loc_82296E90:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// bne cr6,0x82296e68
	if (!cr6.eq) goto loc_82296E68;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82296EAC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82296EB8"))) PPC_WEAK_FUNC(sub_82296EB8);
PPC_FUNC_IMPL(__imp__sub_82296EB8) {
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
	ctx.lr = 0x82296EC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r28,31
	r28.s64 = 31;
loc_82296ED8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296f54
	if (cr6.eq) goto loc_82296F54;
	// lbz r10,279(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 279);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82296f18
	if (cr6.eq) goto loc_82296F18;
	// lbz r10,280(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82296f10
	if (!cr6.eq) goto loc_82296F10;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82296F04;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296f18
	if (cr6.eq) goto loc_82296F18;
loc_82296F10:
	// li r11,1
	r11.s64 = 1;
	// b 0x82296f1c
	goto loc_82296F1C;
loc_82296F18:
	// li r11,0
	r11.s64 = 0;
loc_82296F1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296f54
	if (cr6.eq) goto loc_82296F54;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x82296f50
	if (cr6.eq) goto loc_82296F50;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296F3C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,144
	ctx.r3.s64 = r30.s64 + 144;
	// bl 0x82482520
	ctx.lr = 0x82296F48;
	sub_82482520(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// bne cr6,0x82296f54
	if (!cr6.eq) goto loc_82296F54;
loc_82296F50:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_82296F54:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82296ed8
	if (!cr0.eq) goto loc_82296ED8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82296F6C"))) PPC_WEAK_FUNC(sub_82296F6C);
PPC_FUNC_IMPL(__imp__sub_82296F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296F70"))) PPC_WEAK_FUNC(sub_82296F70);
PPC_FUNC_IMPL(__imp__sub_82296F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
loc_82296F78:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82296f9c
	if (cr6.eq) goto loc_82296F9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x82296f78
	if (cr6.lt) goto loc_82296F78;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82296F9C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82296FA4"))) PPC_WEAK_FUNC(sub_82296FA4);
PPC_FUNC_IMPL(__imp__sub_82296FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82296FA8"))) PPC_WEAK_FUNC(sub_82296FA8);
PPC_FUNC_IMPL(__imp__sub_82296FA8) {
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
	ctx.lr = 0x82296FB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
loc_82296FC4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82296ffc
	if (cr6.eq) goto loc_82296FFC;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296FD8;
	sub_82502300(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82296FE8;
	sub_82502300(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824f0550
	ctx.lr = 0x82296FF0;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297014
	if (!cr6.eq) goto loc_82297014;
loc_82296FFC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// bne cr6,0x82296fc4
	if (!cr6.eq) goto loc_82296FC4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82297014:
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229702C"))) PPC_WEAK_FUNC(sub_8229702C);
PPC_FUNC_IMPL(__imp__sub_8229702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82297030"))) PPC_WEAK_FUNC(sub_82297030);
PPC_FUNC_IMPL(__imp__sub_82297030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82297040"))) PPC_WEAK_FUNC(sub_82297040);
PPC_FUNC_IMPL(__imp__sub_82297040) {
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
	// addi r9,r11,-1380
	ctx.r9.s64 = r11.s64 + -1380;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82297074
	if (cr6.eq) goto loc_82297074;
	// bl 0x82130588
	ctx.lr = 0x82297070;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82297074:
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

__attribute__((alias("__imp__sub_82297088"))) PPC_WEAK_FUNC(sub_82297088);
PPC_FUNC_IMPL(__imp__sub_82297088) {
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
	ctx.lr = 0x82297090;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r4,1
	r30.s64 = ctx.r4.s64 + 1;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82297128
	if (!cr6.lt) goto loc_82297128;
	// lis r11,20971
	r11.s64 = 1374355456;
	// ori r29,r11,34079
	r29.u64 = r11.u64 | 34079;
loc_822970B0:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// li r5,96
	ctx.r5.s64 = 96;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mulhw r4,r7,r29
	ctx.r4.s64 = (int64_t(ctx.r7.s32) * int64_t(r29.s32)) >> 32;
	// mulhw r3,r6,r29
	ctx.r3.s64 = (int64_t(ctx.r6.s32) * int64_t(r29.s32)) >> 32;
	// srawi r11,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	r11.s64 = ctx.r4.s32 >> 5;
	// srawi r10,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r9,r11,100
	ctx.r9.s64 = r11.s64 * 100;
	// mulli r8,r10,100
	ctx.r8.s64 = ctx.r10.s64 * 100;
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// subf r11,r8,r6
	r11.s64 = ctx.r6.s64 - ctx.r8.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + r31.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x82297118;
	sub_823DA950(ctx, base);
	// lwz r5,9608(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r5
	cr6.compare<int32_t>(r30.s32, ctx.r5.s32, xer);
	// blt cr6,0x822970b0
	if (cr6.lt) goto loc_822970B0;
loc_82297128:
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,9600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9600);
	// stw r10,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82297150
	if (!cr6.eq) goto loc_82297150;
	// li r11,99
	r11.s64 = 99;
	// stw r11,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82297150:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82297160"))) PPC_WEAK_FUNC(sub_82297160);
PPC_FUNC_IMPL(__imp__sub_82297160) {
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
	ctx.lr = 0x82297168;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82488320
	ctx.lr = 0x8229717C;
	sub_82488320(ctx, base);
	// lwz r30,136(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82297198
	if (cr6.eq) goto loc_82297198;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295448
	ctx.lr = 0x82297190;
	sub_82295448(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82297198;
	sub_82130588(ctx, base);
loc_82297198:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// bl 0x82489608
	ctx.lr = 0x822971A8;
	sub_82489608(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822971B0"))) PPC_WEAK_FUNC(sub_822971B0);
PPC_FUNC_IMPL(__imp__sub_822971B0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822971B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r30,144
	r29.s64 = r30.s64 + 144;
	// stw r4,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r4.u32);
	// lwz r31,-10240(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4296(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r27,68(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ea838
	ctx.lr = 0x822971E4;
	sub_824EA838(ctx, base);
	// bl 0x824f88f8
	ctx.lr = 0x822971E8;
	sub_824F88F8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// li r6,11
	ctx.r6.s64 = 11;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r31,23592
	ctx.r4.s64 = r31.s64 + 23592;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// bl 0x824852f8
	ctx.lr = 0x82297208;
	sub_824852F8(ctx, base);
	// addi r4,r30,11760
	ctx.r4.s64 = r30.s64 + 11760;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82485608
	ctx.lr = 0x82297214;
	sub_82485608(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229721C"))) PPC_WEAK_FUNC(sub_8229721C);
PPC_FUNC_IMPL(__imp__sub_8229721C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82297220"))) PPC_WEAK_FUNC(sub_82297220);
PPC_FUNC_IMPL(__imp__sub_82297220) {
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
	ctx.lr = 0x82297228;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,31
	r27.s64 = 31;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r28,0
	r28.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_82297240:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82297268
	if (cr6.eq) goto loc_82297268;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82272a48
	ctx.lr = 0x82297254;
	sub_82272A48(ctx, base);
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x82297264;
	sub_82271D18(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_82297268:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82297240
	if (!cr0.eq) goto loc_82297240;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229727C"))) PPC_WEAK_FUNC(sub_8229727C);
PPC_FUNC_IMPL(__imp__sub_8229727C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82297280"))) PPC_WEAK_FUNC(sub_82297280);
PPC_FUNC_IMPL(__imp__sub_82297280) {
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
	ctx.lr = 0x82297288;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481578
	ctx.lr = 0x8229729C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822972b8
	if (cr6.eq) goto loc_822972B8;
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822972bc
	if (!cr6.eq) goto loc_822972BC;
loc_822972B8:
	// li r11,0
	r11.s64 = 0;
loc_822972BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297348
	if (!cr6.eq) goto loc_82297348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481578
	ctx.lr = 0x822972D0;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297348
	if (cr6.eq) goto loc_82297348;
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82486430
	ctx.lr = 0x822972F0;
	sub_82486430(ctx, base);
	// addi r29,r30,12
	r29.s64 = r30.s64 + 12;
	// li r28,31
	r28.s64 = 31;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_822972FC:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229733c
	if (cr6.eq) goto loc_8229733C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229733c
	if (cr6.eq) goto loc_8229733C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82297320;
	sub_82272A48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82296fa8
	ctx.lr = 0x8229732C;
	sub_82296FA8(ctx, base);
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x8229733C;
	sub_82271D18(ctx, base);
loc_8229733C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822972fc
	if (!cr0.eq) goto loc_822972FC;
loc_82297348:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82297350"))) PPC_WEAK_FUNC(sub_82297350);
PPC_FUNC_IMPL(__imp__sub_82297350) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822973c0
	if (cr6.eq) goto loc_822973C0;
loc_82297378:
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// lwz r10,9604(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r9,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r9.u32);
	// stw r11,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r11.u32);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x8229739c
	if (!cr6.eq) goto loc_8229739C;
	// stw r30,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r30.u32);
loc_8229739C:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x824e6f20
	ctx.lr = 0x822973B4;
	sub_824E6F20(ctx, base);
	// lwz r10,9608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82297378
	if (!cr6.eq) goto loc_82297378;
loc_822973C0:
	// stw r30,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, r30.u32);
	// stw r30,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r30.u32);
	// stw r30,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r30.u32);
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

__attribute__((alias("__imp__sub_822973E4"))) PPC_WEAK_FUNC(sub_822973E4);
PPC_FUNC_IMPL(__imp__sub_822973E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822973E8"))) PPC_WEAK_FUNC(sub_822973E8);
PPC_FUNC_IMPL(__imp__sub_822973E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,9608(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9608);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822973F0"))) PPC_WEAK_FUNC(sub_822973F0);
PPC_FUNC_IMPL(__imp__sub_822973F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82297444
	if (cr6.lt) goto loc_82297444;
	// lwz r11,9608(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9608);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82297444
	if (!cr6.lt) goto loc_82297444;
	// lwz r11,9604(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 9604);
	// lis r10,20971
	ctx.r10.s64 = 1374355456;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// ori r9,r10,34079
	ctx.r9.u64 = ctx.r10.u64 | 34079;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulhw r7,r8,r9
	ctx.r7.s64 = (int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32)) >> 32;
	// srawi r11,r7,5
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	r11.s64 = ctx.r7.s32 >> 5;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mulli r5,r6,100
	ctx.r5.s64 = ctx.r6.s64 * 100;
	// subf r11,r5,r8
	r11.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
loc_82297444:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229744C"))) PPC_WEAK_FUNC(sub_8229744C);
PPC_FUNC_IMPL(__imp__sub_8229744C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82297450"))) PPC_WEAK_FUNC(sub_82297450);
PPC_FUNC_IMPL(__imp__sub_82297450) {
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
	ctx.lr = 0x82297458;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822974d4
	if (!cr6.gt) goto loc_822974D4;
	// lis r11,20971
	r11.s64 = 1374355456;
	// ori r30,r11,34079
	r30.u64 = r11.u64 | 34079;
loc_8229747C:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// mulhw r8,r9,r30
	ctx.r8.s64 = (int64_t(ctx.r9.s32) * int64_t(r30.s32)) >> 32;
	// srawi r11,r8,5
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	r11.s64 = ctx.r8.s32 >> 5;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mulli r6,r7,100
	ctx.r6.s64 = ctx.r7.s64 * 100;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x824e7120
	ctx.lr = 0x822974B8;
	sub_824E7120(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822974e0
	if (!cr6.eq) goto loc_822974E0;
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8229747c
	if (cr6.lt) goto loc_8229747C;
loc_822974D4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822974E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822974EC"))) PPC_WEAK_FUNC(sub_822974EC);
PPC_FUNC_IMPL(__imp__sub_822974EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822974F0"))) PPC_WEAK_FUNC(sub_822974F0);
PPC_FUNC_IMPL(__imp__sub_822974F0) {
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
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82488320
	ctx.lr = 0x82297514;
	sub_82488320(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481578
	ctx.lr = 0x8229751C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297538
	if (!cr6.eq) goto loc_82297538;
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8229753c
	if (cr6.eq) goto loc_8229753C;
loc_82297538:
	// li r11,0
	r11.s64 = 0;
loc_8229753C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297550
	if (!cr6.eq) goto loc_82297550;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297280
	ctx.lr = 0x82297550;
	sub_82297280(ctx, base);
loc_82297550:
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

__attribute__((alias("__imp__sub_82297568"))) PPC_WEAK_FUNC(sub_82297568);
PPC_FUNC_IMPL(__imp__sub_82297568) {
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
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
	// stw r11,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r11.u32);
	// stw r11,11816(r31)
	PPC_STORE_U32(r31.u32 + 11816, r11.u32);
	// bl 0x82297220
	ctx.lr = 0x8229759C;
	sub_82297220(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822975b8
	if (cr6.eq) goto loc_822975B8;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822975b8
	if (cr6.eq) goto loc_822975B8;
	// bl 0x82295460
	ctx.lr = 0x822975B8;
	sub_82295460(ctx, base);
loc_822975B8:
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

__attribute__((alias("__imp__sub_822975CC"))) PPC_WEAK_FUNC(sub_822975CC);
PPC_FUNC_IMPL(__imp__sub_822975CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822975D0"))) PPC_WEAK_FUNC(sub_822975D0);
PPC_FUNC_IMPL(__imp__sub_822975D0) {
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
	// addi r4,r31,11784
	ctx.r4.s64 = r31.s64 + 11784;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82486548
	ctx.lr = 0x822975F0;
	sub_82486548(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229761c
	if (!cr6.eq) goto loc_8229761C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297280
	ctx.lr = 0x82297604;
	sub_82297280(ctx, base);
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
loc_8229761C:
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

__attribute__((alias("__imp__sub_82297634"))) PPC_WEAK_FUNC(sub_82297634);
PPC_FUNC_IMPL(__imp__sub_82297634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82297638"))) PPC_WEAK_FUNC(sub_82297638);
PPC_FUNC_IMPL(__imp__sub_82297638) {
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
	// addi r4,r31,11792
	ctx.r4.s64 = r31.s64 + 11792;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x824866e8
	ctx.lr = 0x82297658;
	sub_824866E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297684
	if (!cr6.eq) goto loc_82297684;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297280
	ctx.lr = 0x8229766C;
	sub_82297280(ctx, base);
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
loc_82297684:
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

__attribute__((alias("__imp__sub_8229769C"))) PPC_WEAK_FUNC(sub_8229769C);
PPC_FUNC_IMPL(__imp__sub_8229769C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822976A0"))) PPC_WEAK_FUNC(sub_822976A0);
PPC_FUNC_IMPL(__imp__sub_822976A0) {
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
	ctx.lr = 0x822976A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,99
	r31.s64 = 99;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822976B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x822976C0;
	sub_824E71C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bge 0x822976b8
	if (!cr0.lt) goto loc_822976B8;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,9608(r29)
	PPC_STORE_U32(r29.u32 + 9608, r11.u32);
	// stw r11,9604(r29)
	PPC_STORE_U32(r29.u32 + 9604, r11.u32);
	// stw r11,9600(r29)
	PPC_STORE_U32(r29.u32 + 9600, r11.u32);
	// bl 0x82297350
	ctx.lr = 0x822976E4;
	sub_82297350(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822976F0"))) PPC_WEAK_FUNC(sub_822976F0);
PPC_FUNC_IMPL(__imp__sub_822976F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82297350
	sub_82297350(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822976F4"))) PPC_WEAK_FUNC(sub_822976F4);
PPC_FUNC_IMPL(__imp__sub_822976F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822976F8"))) PPC_WEAK_FUNC(sub_822976F8);
PPC_FUNC_IMPL(__imp__sub_822976F8) {
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
	ctx.lr = 0x82297700;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82297450
	ctx.lr = 0x82297710;
	sub_82297450(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82297724
	if (cr6.lt) goto loc_82297724;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82297088
	ctx.lr = 0x82297724;
	sub_82297088(ctx, base);
loc_82297724:
	// lwz r11,9608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x8229776c
	if (!cr6.eq) goto loc_8229776C;
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// li r10,99
	ctx.r10.s64 = 99;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r10.u32);
	// stw r11,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r11.u32);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x82297754
	if (!cr6.eq) goto loc_82297754;
	// stw r29,9604(r31)
	PPC_STORE_U32(r31.u32 + 9604, r29.u32);
loc_82297754:
	// lwz r11,9604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9604);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x824e6f20
	ctx.lr = 0x8229776C;
	sub_824E6F20(ctx, base);
loc_8229776C:
	// lwz r11,9600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9600);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r11.u32);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// bne cr6,0x82297784
	if (!cr6.eq) goto loc_82297784;
	// stw r29,9600(r31)
	PPC_STORE_U32(r31.u32 + 9600, r29.u32);
loc_82297784:
	// lwz r10,9608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9608);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,9600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9600);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,9608(r31)
	PPC_STORE_U32(r31.u32 + 9608, ctx.r9.u32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x822977B0;
	sub_823DA950(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822977B8"))) PPC_WEAK_FUNC(sub_822977B8);
PPC_FUNC_IMPL(__imp__sub_822977B8) {
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
	ctx.lr = 0x822977C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// bl 0x826185a0
	ctx.lr = 0x822977D0;
	sub_826185A0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbz r4,1(r23)
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + 1);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82250f50
	ctx.lr = 0x822977E4;
	sub_82250F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229781c
	if (cr6.eq) goto loc_8229781C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lbz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// bl 0x82618f70
	ctx.lr = 0x822977FC;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229781c
	if (cr6.eq) goto loc_8229781C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822959b8
	ctx.lr = 0x82297810;
	sub_822959B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82297820
	if (!cr6.eq) goto loc_82297820;
loc_8229781C:
	// li r11,0
	r11.s64 = 0;
loc_82297820:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822979f4
	if (cr6.eq) goto loc_822979F4;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822959b8
	ctx.lr = 0x82297834;
	sub_822959B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r30,1396
	ctx.r4.s64 = r30.s64 + 1396;
	// bl 0x821c8fe0
	ctx.lr = 0x82297844;
	sub_821C8FE0(ctx, base);
	// lbz r11,0(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229787c
	if (!cr6.eq) goto loc_8229787C;
	// addi r31,r30,552
	r31.s64 = r30.s64 + 552;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82297860;
	sub_82618830(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x82297868;
	sub_822954F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x82297878;
	sub_82618C80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8229787C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822978b4
	if (cr6.eq) goto loc_822978B4;
	// addi r31,r30,584
	r31.s64 = r30.s64 + 584;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82297898;
	sub_82618830(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x822978A0;
	sub_822954F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x822978B0;
	sub_82618C80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_822978B4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979ec
	if (cr6.eq) goto loc_822979EC;
	// addi r26,r30,748
	r26.s64 = r30.s64 + 748;
loc_822978C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x822978D0;
	sub_822954F0(ctx, base);
	// cmpw cr6,r27,r3
	cr6.compare<int32_t>(r27.s32, ctx.r3.s32, xer);
	// bge cr6,0x822979ec
	if (!cr6.lt) goto loc_822979EC;
	// lbz r11,0(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822978fc
	if (!cr6.eq) goto loc_822978FC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295238
	ctx.lr = 0x822978F0;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
loc_822978FC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x82297908;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954b8
	ctx.lr = 0x82297920;
	sub_822954B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r28,r31
	r28.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// bl 0x82295510
	ctx.lr = 0x82297938;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8229798c
	if (!cr6.eq) goto loc_8229798C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826185a0
	ctx.lr = 0x82297948;
	sub_826185A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229795c
	if (!cr6.eq) goto loc_8229795C;
	// lwz r28,0(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8229795C:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229797c
	if (cr6.eq) goto loc_8229797C;
loc_8229796C:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229796c
	if (!cr6.eq) goto loc_8229796C;
loc_8229797C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82299788
	ctx.lr = 0x82297988;
	sub_82299788(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8229798C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
	// addi r31,r30,520
	r31.s64 = r30.s64 + 520;
	// lwz r4,-136(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + -136);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x822979A8;
	sub_82618830(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618c80
	ctx.lr = 0x822979B8;
	sub_82618C80(ctx, base);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822979d8
	if (cr6.eq) goto loc_822979D8;
	// stw r28,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822951d0
	ctx.lr = 0x822979D8;
	sub_822951D0(ctx, base);
loc_822979D8:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822978c8
	if (!cr6.eq) goto loc_822978C8;
loc_822979EC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x822979F4;
	sub_821C9030(ctx, base);
loc_822979F4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297a1c
	if (cr6.eq) goto loc_82297A1C;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297a1c
	if (cr6.eq) goto loc_82297A1C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822959b8
	ctx.lr = 0x82297A14;
	sub_822959B8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
loc_82297A1C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82297A28"))) PPC_WEAK_FUNC(sub_82297A28);
PPC_FUNC_IMPL(__imp__sub_82297A28) {
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
	ctx.lr = 0x82297A30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r27,r31,144
	r27.s64 = r31.s64 + 144;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82486c48
	ctx.lr = 0x82297A44;
	sub_82486C48(ctx, base);
	// lwz r11,11784(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11784);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// addi r30,r31,11784
	r30.s64 = r31.s64 + 11784;
	// ori r29,r10,25904
	r29.u64 = ctx.r10.u64 | 25904;
	// li r26,0
	r26.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82297a90
	if (cr6.eq) goto loc_82297A90;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x82297a80
	if (!cr6.eq) goto loc_82297A80;
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,27
	ctx.r5.s64 = 27;
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297A80;
	sub_822990D8(ctx, base);
loc_82297A80:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82297A8C;
	sub_821CE080(ctx, base);
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_82297A90:
	// lwz r11,11792(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11792);
	// addi r30,r31,11792
	r30.s64 = r31.s64 + 11792;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82297acc
	if (cr6.eq) goto loc_82297ACC;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x82297abc
	if (!cr6.eq) goto loc_82297ABC;
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,27
	ctx.r5.s64 = 27;
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297ABC;
	sub_822990D8(ctx, base);
loc_82297ABC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82297AC8;
	sub_821CE080(ctx, base);
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_82297ACC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481578
	ctx.lr = 0x82297AD4;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297b60
	if (!cr6.eq) goto loc_82297B60;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481688
	ctx.lr = 0x82297B0C;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82295708
	ctx.lr = 0x82297B20;
	sub_82295708(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297b60
	if (cr6.eq) goto loc_82297B60;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82296ae0
	ctx.lr = 0x82297B38;
	sub_82296AE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82296188
	ctx.lr = 0x82297B44;
	sub_82296188(ctx, base);
	// lwz r4,-10240(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// li r5,24
	ctx.r5.s64 = 24;
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297B58;
	sub_822990D8(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x822957a8
	ctx.lr = 0x82297B60;
	sub_822957A8(ctx, base);
loc_82297B60:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82297B68"))) PPC_WEAK_FUNC(sub_82297B68);
PPC_FUNC_IMPL(__imp__sub_82297B68) {
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
	ctx.lr = 0x82297B70;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// bl 0x82501b00
	ctx.lr = 0x82297B84;
	sub_82501B00(ctx, base);
	// addi r23,r26,16
	r23.s64 = r26.s64 + 16;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x824e7060
	ctx.lr = 0x82297B90;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297bb4
	if (cr6.eq) goto loc_82297BB4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r5,r26,112
	ctx.r5.s64 = r26.s64 + 112;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271118
	ctx.lr = 0x82297BB4;
	sub_82271118(ctx, base);
loc_82297BB4:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r31,-10240(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82297BC0;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822704d0
	ctx.lr = 0x82297BCC;
	sub_822704D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82297be4
	if (!cr6.eq) goto loc_82297BE4;
loc_82297BD8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d922c
	return;
loc_82297BE4:
	// addi r22,r28,144
	r22.s64 = r28.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824823f0
	ctx.lr = 0x82297BF4;
	sub_824823F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297bd8
	if (cr6.eq) goto loc_82297BD8;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x82297C08;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82297C0C;
	sub_82130000(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82501a88
	ctx.lr = 0x82297C18;
	sub_82501A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297c28
	if (cr6.eq) goto loc_82297C28;
	// stw r29,11780(r28)
	PPC_STORE_U32(r28.u32 + 11780, r29.u32);
loc_82297C28:
	// addi r24,r29,16
	r24.s64 = r29.s64 + 16;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824e7060
	ctx.lr = 0x82297C34;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297c60
	if (cr6.eq) goto loc_82297C60;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// addi r9,r10,8656
	ctx.r9.s64 = ctx.r10.s64 + 8656;
	// lwz r11,8792(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8792);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x826189a8
	ctx.lr = 0x82297C60;
	sub_826189A8(ctx, base);
loc_82297C60:
	// addi r25,r28,12
	r25.s64 = r28.s64 + 12;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82297C6C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297ca0
	if (cr6.eq) goto loc_82297CA0;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82297C80;
	sub_82502300(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82502300
	ctx.lr = 0x82297C8C;
	sub_82502300(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x824f0550
	ctx.lr = 0x82297C94;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297cb4
	if (!cr6.eq) goto loc_82297CB4;
loc_82297CA0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bne cr6,0x82297c6c
	if (!cr6.eq) goto loc_82297C6C;
	// b 0x82297cc0
	goto loc_82297CC0;
loc_82297CB4:
	// mr r30,r31
	r30.u64 = r31.u64;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x82297cfc
	if (!cr6.eq) goto loc_82297CFC;
loc_82297CC0:
	// li r11,0
	r11.s64 = 0;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_82297CC8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82297cf0
	if (cr6.eq) goto loc_82297CF0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x82297cc8
	if (cr6.lt) goto loc_82297CC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d922c
	return;
loc_82297CF0:
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82297bd8
	if (cr6.eq) goto loc_82297BD8;
loc_82297CFC:
	// li r11,0
	r11.s64 = 0;
	// addi r10,r29,208
	ctx.r10.s64 = r29.s64 + 208;
loc_82297D04:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// beq cr6,0x82297d24
	if (cr6.eq) goto loc_82297D24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x82297d04
	if (!cr6.eq) goto loc_82297D04;
	// b 0x82297d30
	goto loc_82297D30;
loc_82297D24:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82297d40
	if (!cr6.eq) goto loc_82297D40;
loc_82297D30:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822729c8
	ctx.lr = 0x82297D38;
	sub_822729C8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82297bd8
	if (cr6.eq) goto loc_82297BD8;
loc_82297D40:
	// addi r11,r3,26
	r11.s64 = ctx.r3.s64 + 26;
	// addi r10,r30,3
	ctx.r10.s64 = r30.s64 + 3;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// li r31,1
	r31.s64 = 1;
	// stwx r29,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, r29.u32);
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stb r31,5(r11)
	PPC_STORE_U8(r11.u32 + 5, r31.u8);
	// lbz r8,280(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 280);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r31,279(r29)
	PPC_STORE_U8(r29.u32 + 279, r31.u8);
	// bne cr6,0x82297d8c
	if (!cr6.eq) goto loc_82297D8C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824e7008
	ctx.lr = 0x82297D7C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82297d8c
	if (!cr6.eq) goto loc_82297D8C;
	// li r31,0
	r31.s64 = 0;
loc_82297D8C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297da8
	if (cr6.eq) goto loc_82297DA8;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// bl 0x82130000
	ctx.lr = 0x82297DA8;
	sub_82130000(ctx, base);
loc_82297DA8:
	// lis r11,5
	r11.s64 = 327680;
	// lwz r4,-10240(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// ori r31,r11,25904
	r31.u64 = r11.u64 | 25904;
	// li r5,15
	ctx.r5.s64 = 15;
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + r31.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297DC4;
	sub_822990D8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// addi r9,r10,-1372
	ctx.r9.s64 = ctx.r10.s64 + -1372;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x824e6310
	ctx.lr = 0x82297DD8;
	sub_824E6310(ctx, base);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r30,-10240(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82297DE8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822704d0
	ctx.lr = 0x82297DF4;
	sub_822704D0(ctx, base);
	// lwz r7,124(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// lwz r6,128(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// ld r8,112(r26)
	ctx.r8.u64 = PPC_LOAD_U64(r26.u32 + 112);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// std r8,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, ctx.r8.u64);
	// bl 0x824e7060
	ctx.lr = 0x82297E18;
	sub_824E7060(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82297ec4
	if (cr6.eq) goto loc_82297EC4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82297E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r30,31
	r30.s64 = 31;
loc_82297E4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82297E60;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x824825f0
	ctx.lr = 0x82297E7C;
	sub_824825F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82297E94;
	sub_821F8730(ctx, base);
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82270170
	ctx.lr = 0x82297EA4;
	sub_82270170(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82297eb4
	if (cr6.eq) goto loc_82297EB4;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82274a58
	ctx.lr = 0x82297EB4;
	sub_82274A58(ctx, base);
loc_82297EB4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82297e4c
	if (!cr0.eq) goto loc_82297E4C;
	// b 0x82297eec
	goto loc_82297EEC;
loc_82297EC4:
	// lwz r4,-10240(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,7
	ctx.r5.s64 = 7;
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + r31.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297ED8;
	sub_822990D8(ctx, base);
	// lwz r4,-10240(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// li r5,14
	ctx.r5.s64 = 14;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r3,r4,r31
	ctx.r3.u64 = ctx.r4.u64 + r31.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297EEC;
	sub_822990D8(ctx, base);
loc_82297EEC:
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82297F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82297F14"))) PPC_WEAK_FUNC(sub_82297F14);
PPC_FUNC_IMPL(__imp__sub_82297F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82297F18"))) PPC_WEAK_FUNC(sub_82297F18);
PPC_FUNC_IMPL(__imp__sub_82297F18) {
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
	ctx.lr = 0x82297F20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82297f40
	if (!cr6.eq) goto loc_82297F40;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82297F40:
	// lwz r11,11780(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 11780);
	// li r26,0
	r26.s64 = 0;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x82297f54
	if (!cr6.eq) goto loc_82297F54;
	// stw r26,11780(r28)
	PPC_STORE_U32(r28.u32 + 11780, r26.u32);
loc_82297F54:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// ori r29,r11,25904
	r29.u64 = r11.u64 | 25904;
	// li r5,14
	ctx.r5.s64 = 14;
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297F74;
	sub_822990D8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r9,r10,16332
	ctx.r9.s64 = ctx.r10.s64 + 16332;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x82297F9C;
	sub_822990D8(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,68(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82297FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,277(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 277);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82297fe0
	if (!cr6.eq) goto loc_82297FE0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82272a48
	ctx.lr = 0x82297FD0;
	sub_82272A48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82296fa8
	ctx.lr = 0x82297FDC;
	sub_82296FA8(ctx, base);
	// b 0x82297fe8
	goto loc_82297FE8;
loc_82297FE0:
	// li r11,1
	r11.s64 = 1;
	// stb r11,278(r31)
	PPC_STORE_U8(r31.u32 + 278, r11.u8);
loc_82297FE8:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82297FF0;
	sub_824E7008(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4280(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4280);
	// bl 0x82271d18
	ctx.lr = 0x82298004;
	sub_82271D18(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298078
	if (cr6.eq) goto loc_82298078;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226b020
	ctx.lr = 0x82298018;
	sub_8226B020(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298078
	if (!cr6.eq) goto loc_82298078;
	// addi r31,r28,12
	r31.s64 = r28.s64 + 12;
	// mr r27,r26
	r27.u64 = r26.u64;
loc_8229802C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8229804c
	if (cr6.eq) goto loc_8229804C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82298040;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298060
	if (!cr6.eq) goto loc_82298060;
loc_8229804C:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r27,31
	cr6.compare<int32_t>(r27.s32, 31, xer);
	// bne cr6,0x8229802c
	if (!cr6.eq) goto loc_8229802C;
	// b 0x82298064
	goto loc_82298064;
loc_82298060:
	// li r26,1
	r26.s64 = 1;
loc_82298064:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298078
	if (!cr6.eq) goto loc_82298078;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82297280
	ctx.lr = 0x82298078;
	sub_82297280(ctx, base);
loc_82298078:
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// add r3,r4,r29
	ctx.r3.u64 = ctx.r4.u64 + r29.u64;
	// bl 0x822990d8
	ctx.lr = 0x8229808C;
	sub_822990D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82298098"))) PPC_WEAK_FUNC(sub_82298098);
PPC_FUNC_IMPL(__imp__sub_82298098) {
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
	ctx.lr = 0x822980A0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,64(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822981b0
	if (cr6.eq) goto loc_822981B0;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481688
	ctx.lr = 0x822980C0;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298100
	if (cr6.eq) goto loc_82298100;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82298100
	if (cr6.eq) goto loc_82298100;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298100
	if (cr6.eq) goto loc_82298100;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82296c50
	ctx.lr = 0x822980EC;
	sub_82296C50(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82296188
	ctx.lr = 0x822980F8;
	sub_82296188(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x822957a8
	ctx.lr = 0x82298100;
	sub_822957A8(ctx, base);
loc_82298100:
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// stb r29,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r29.u8);
	// stw r29,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r29.u32);
loc_82298110:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298144
	if (cr6.eq) goto loc_82298144;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x82298124;
	sub_82130000(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x824f97c0
	ctx.lr = 0x82298130;
	sub_824F97C0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f97c0
	ctx.lr = 0x8229813C;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r26
	cr6.compare<uint64_t>(ctx.r3.u64, r26.u64, xer);
	// beq cr6,0x82298158
	if (cr6.eq) goto loc_82298158;
loc_82298144:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x82298110
	if (!cr6.eq) goto loc_82298110;
	// b 0x82298168
	goto loc_82298168;
loc_82298158:
	// addi r11,r29,3
	r11.s64 = r29.s64 + 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stw r9,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, ctx.r9.u32);
loc_82298168:
	// lwz r11,11780(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11780);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822981b0
	if (cr6.eq) goto loc_822981B0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r10,16340
	ctx.r8.s64 = ctx.r10.s64 + 16340;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r5,25
	ctx.r5.s64 = 25;
	// lwz r4,-10240(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822981A4;
	sub_822990D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_822981B0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,26
	ctx.r5.s64 = 26;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822981CC;
	sub_822990D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822981D8"))) PPC_WEAK_FUNC(sub_822981D8);
PPC_FUNC_IMPL(__imp__sub_822981D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822981E0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r29,r30,144
	r29.s64 = r30.s64 + 144;
	// cmplw cr6,r29,r4
	cr6.compare<uint32_t>(r29.u32, ctx.r4.u32, xer);
	// bne cr6,0x82298544
	if (!cr6.eq) goto loc_82298544;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229820C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,12
	cr6.compare<uint32_t>(ctx.r3.u32, 12, xer);
	// bgt cr6,0x82298544
	if (cr6.gt) goto loc_82298544;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-32212
	r12.s64 = r12.s64 + -32212;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_822982B0;
	case 1:
		goto loc_82298544;
	case 2:
		goto loc_82298450;
	case 3:
		goto loc_82298368;
	case 4:
		goto loc_82298398;
	case 5:
		goto loc_82298260;
	case 6:
		goto loc_82298274;
	case 7:
		goto loc_822984F0;
	case 8:
		goto loc_82298544;
	case 9:
		goto loc_82298344;
	case 10:
		goto loc_82298354;
	case 11:
		goto loc_82298544;
	case 12:
		goto loc_82298514;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-32080(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32080);
	// lwz r17,-31420(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31420);
	// lwz r17,-31664(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31664);
	// lwz r17,-31896(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31896);
	// lwz r17,-31848(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31848);
	// lwz r17,-32160(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32160);
	// lwz r17,-32140(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32140);
	// lwz r17,-31504(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31504);
	// lwz r17,-31420(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31420);
	// lwz r17,-31932(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31932);
	// lwz r17,-31916(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31916);
	// lwz r17,-31420(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31420);
	// lwz r17,-31468(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31468);
loc_82298260:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82297b68
	ctx.lr = 0x8229826C;
	sub_82297B68(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298274:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// lwz r31,-10240(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82298288;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822704d0
	ctx.lr = 0x82298294;
	sub_822704D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82297f18
	ctx.lr = 0x822982A8;
	sub_82297F18(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822982B0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x822982B8;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// lwz r29,-10240(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x822982D8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822704d0
	ctx.lr = 0x822982E4;
	sub_822704D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r11,112
	ctx.r8.s64 = r11.s64 + 112;
	// lwz r4,-10240(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r7,r10,16348
	ctx.r7.s64 = ctx.r10.s64 + 16348;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// lwz r3,624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 624);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82298330;
	sub_822990D8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r10,628(r11)
	PPC_STORE_U32(r11.u32 + 628, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298344:
	// li r11,1
	r11.s64 = 1;
	// stb r11,9(r30)
	PPC_STORE_U8(r30.u32 + 9, r11.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298354:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82298098
	ctx.lr = 0x82298360;
	sub_82298098(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298368:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82298390;
	sub_822990D8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298398:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822983BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsb r8,r3
	ctx.r8.s64 = ctx.r3.s8;
	// cmpwi cr6,r8,89
	cr6.compare<int32_t>(ctx.r8.s32, 89, xer);
	// beq cr6,0x822983e4
	if (cr6.eq) goto loc_822983E4;
	// li r11,0
	r11.s64 = 0;
	// stb r3,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r3.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,648(r31)
	PPC_STORE_U8(r31.u32 + 648, r11.u8);
	// stw r10,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822983E4:
	// li r11,1
	r11.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stb r11,648(r31)
	PPC_STORE_U8(r31.u32 + 648, r11.u8);
	// bl 0x82618750
	ctx.lr = 0x822983F4;
	sub_82618750(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82618750
	ctx.lr = 0x822983FC;
	sub_82618750(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r31,132
	ctx.r4.s64 = r31.s64 + 132;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82618610
	ctx.lr = 0x82298410;
	sub_82618610(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r10,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r9,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// bl 0x82295328
	ctx.lr = 0x82298430;
	sub_82295328(ctx, base);
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x822977b8
	ctx.lr = 0x8229843C;
	sub_822977B8(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x826186a0
	ctx.lr = 0x82298444;
	sub_826186A0(ctx, base);
	// stw r3,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r3.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298450:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82618750
	ctx.lr = 0x82298458;
	sub_82618750(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82618750
	ctx.lr = 0x82298460;
	sub_82618750(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x826185b0
	ctx.lr = 0x82298478;
	sub_826185B0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x822709c8
	ctx.lr = 0x82298494;
	sub_822709C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822959b8
	ctx.lr = 0x822984A8;
	sub_822959B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82298544
	if (cr6.eq) goto loc_82298544;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82296188
	ctx.lr = 0x822984C4;
	sub_82296188(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// lwz r4,-10240(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x822984E0;
	sub_822990D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822957a8
	ctx.lr = 0x822984E8;
	sub_822957A8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822984F0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,-10240(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x8229850C;
	sub_822990D8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_82298514:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82297568
	ctx.lr = 0x82298528;
	sub_82297568(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r4,-10240(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x82298544;
	sub_822990D8(ctx, base);
loc_82298544:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229854C"))) PPC_WEAK_FUNC(sub_8229854C);
PPC_FUNC_IMPL(__imp__sub_8229854C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82298550"))) PPC_WEAK_FUNC(sub_82298550);
PPC_FUNC_IMPL(__imp__sub_82298550) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// bl 0x82489428
	ctx.lr = 0x82298578;
	sub_82489428(ctx, base);
	// stw r30,11760(r31)
	PPC_STORE_U32(r31.u32 + 11760, r30.u32);
	// stw r30,11764(r31)
	PPC_STORE_U32(r31.u32 + 11764, r30.u32);
	// addi r3,r31,11800
	ctx.r3.s64 = r31.s64 + 11800;
	// stw r30,11768(r31)
	PPC_STORE_U32(r31.u32 + 11768, r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,11772(r31)
	PPC_STORE_U32(r31.u32 + 11772, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,11776(r31)
	PPC_STORE_U32(r31.u32 + 11776, r30.u32);
	// stw r30,11784(r31)
	PPC_STORE_U32(r31.u32 + 11784, r30.u32);
	// stw r30,11788(r31)
	PPC_STORE_U32(r31.u32 + 11788, r30.u32);
	// stw r30,11792(r31)
	PPC_STORE_U32(r31.u32 + 11792, r30.u32);
	// stw r30,11796(r31)
	PPC_STORE_U32(r31.u32 + 11796, r30.u32);
	// bl 0x821ce460
	ctx.lr = 0x822985AC;
	sub_821CE460(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// li r5,124
	ctx.r5.s64 = 124;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822985BC;
	sub_823D9890(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stb r30,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// stb r30,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r30.u8);
	// stw r30,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r30.u32);
	// stw r30,11816(r31)
	PPC_STORE_U32(r31.u32 + 11816, r30.u32);
	// bl 0x82297220
	ctx.lr = 0x822985DC;
	sub_82297220(ctx, base);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822985f8
	if (cr6.eq) goto loc_822985F8;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822985f8
	if (cr6.eq) goto loc_822985F8;
	// bl 0x82295460
	ctx.lr = 0x822985F8;
	sub_82295460(ctx, base);
loc_822985F8:
	// li r3,1428
	ctx.r3.s64 = 1428;
	// bl 0x82130528
	ctx.lr = 0x82298600;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82298614
	if (cr6.eq) goto loc_82298614;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82295338
	ctx.lr = 0x82298610;
	sub_82295338(ctx, base);
	// b 0x82298618
	goto loc_82298618;
loc_82298614:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82298618:
	// lis r11,-32214
	r11.s64 = -2111176704;
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// stw r30,11760(r31)
	PPC_STORE_U32(r31.u32 + 11760, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-32296
	ctx.r10.s64 = r11.s64 + -32296;
	// stw r10,11764(r31)
	PPC_STORE_U32(r31.u32 + 11764, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x82298634;
	sub_82130000(ctx, base);
	// stw r3,11760(r31)
	PPC_STORE_U32(r31.u32 + 11760, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,11780(r31)
	PPC_STORE_U32(r31.u32 + 11780, r30.u32);
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

__attribute__((alias("__imp__sub_82298658"))) PPC_WEAK_FUNC(sub_82298658);
PPC_FUNC_IMPL(__imp__sub_82298658) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x822a5578
	ctx.lr = 0x8229867C;
	sub_822A5578(ctx, base);
	// lbz r11,140(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298690
	if (!cr6.eq) goto loc_82298690;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8229871c
	goto loc_8229871C;
loc_82298690:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822986ac
	if (cr6.gt) goto loc_822986AC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8229871c
	goto loc_8229871C;
loc_822986AC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f12,f31,f0
	ctx.f12.f64 = double(float(f31.f64 - f0.f64));
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r11,1
	r11.s64 = 1;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f11,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lfs f8,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fsubs f2,f3,f9
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// fsel f1,f2,f3,f9
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : ctx.f9.f64;
	// fsubs f0,f1,f8
	f0.f64 = double(float(ctx.f1.f64 - ctx.f8.f64));
	// fsel f13,f0,f8,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f8.f64 : ctx.f1.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82298718
	if (!cr6.lt) goto loc_82298718;
	// li r11,0
	r11.s64 = 0;
loc_82298718:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
loc_8229871C:
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

__attribute__((alias("__imp__sub_82298734"))) PPC_WEAK_FUNC(sub_82298734);
PPC_FUNC_IMPL(__imp__sub_82298734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82298738"))) PPC_WEAK_FUNC(sub_82298738);
PPC_FUNC_IMPL(__imp__sub_82298738) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82298754
	if (cr6.gt) goto loc_82298754;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82298754:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r11,1
	r11.s64 = 1;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lfs f11,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lfs f8,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fsubs f2,f3,f9
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// fsel f1,f2,f3,f9
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : ctx.f9.f64;
	// fsubs f0,f1,f8
	f0.f64 = double(float(ctx.f1.f64 - ctx.f8.f64));
	// fsel f13,f0,f8,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f8.f64 : ctx.f1.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822987c0
	if (!cr6.lt) goto loc_822987C0;
	// li r11,0
	r11.s64 = 0;
loc_822987C0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822987C8"))) PPC_WEAK_FUNC(sub_822987C8);
PPC_FUNC_IMPL(__imp__sub_822987C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x822987EC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82298834
	if (!cr6.gt) goto loc_82298834;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
loc_82298804:
	// addic. r9,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r9.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82298828
	if (cr0.eq) goto loc_82298828;
	// stfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stw r10,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r10.u32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// sth r10,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r10.u16);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stb r10,10(r11)
	PPC_STORE_U8(r11.u32 + 10, ctx.r10.u8);
	// stb r10,11(r11)
	PPC_STORE_U8(r11.u32 + 11, ctx.r10.u8);
loc_82298828:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x82298804
	if (!cr0.eq) goto loc_82298804;
loc_82298834:
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

__attribute__((alias("__imp__sub_82298848"))) PPC_WEAK_FUNC(sub_82298848);
PPC_FUNC_IMPL(__imp__sub_82298848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82298858"))) PPC_WEAK_FUNC(sub_82298858);
PPC_FUNC_IMPL(__imp__sub_82298858) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// sth r30,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r30.u16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822988b4
	if (cr6.eq) goto loc_822988B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,984(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 984);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822988a0
	if (cr6.gt) goto loc_822988A0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_822988A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822988b0
	if (cr6.eq) goto loc_822988B0;
	// bl 0x822a57d0
	ctx.lr = 0x822988B0;
	sub_822A57D0(ctx, base);
loc_822988B0:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_822988B4:
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

__attribute__((alias("__imp__sub_822988CC"))) PPC_WEAK_FUNC(sub_822988CC);
PPC_FUNC_IMPL(__imp__sub_822988CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822988D0"))) PPC_WEAK_FUNC(sub_822988D0);
PPC_FUNC_IMPL(__imp__sub_822988D0) {
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
	ctx.lr = 0x822988D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,0(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,1220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 1220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8229896c
	if (cr6.eq) goto loc_8229896C;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x822051a0
	ctx.lr = 0x822988F8;
	sub_822051A0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17892(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8229890C;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229896c
	if (cr6.eq) goto loc_8229896C;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17892(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82298940
	if (cr6.eq) goto loc_82298940;
	// addi r10,r31,101
	ctx.r10.s64 = r31.s64 + 101;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x82298948
	goto loc_82298948;
loc_82298940:
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r11
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_82298948:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229895C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229896c
	if (cr6.eq) goto loc_8229896C;
	// mr r29,r31
	r29.u64 = r31.u64;
loc_8229896C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822989c8
	if (cr6.eq) goto loc_822989C8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x8229897C;
	sub_822A8108(ctx, base);
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// bl 0x822a8108
	ctx.lr = 0x82298988;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822989C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,29500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822989D8"))) PPC_WEAK_FUNC(sub_822989D8);
PPC_FUNC_IMPL(__imp__sub_822989D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_822989EC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x82298a0c
	if (cr6.eq) goto loc_82298A0C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822989ec
	if (cr6.lt) goto loc_822989EC;
	// blr 
	return;
loc_82298A0C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lhz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addis r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 65536;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r9,r11,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FFFC;
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// li r8,5
	ctx.r8.s64 = 5;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82298A58:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82298a58
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82298A58;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82298A70"))) PPC_WEAK_FUNC(sub_82298A70);
PPC_FUNC_IMPL(__imp__sub_82298A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8229af08
	ctx.lr = 0x82298A9C;
	sub_8229AF08(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x822a5578
	ctx.lr = 0x82298AA4;
	sub_822A5578(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r3,124
	r11.s64 = ctx.r3.s64 + 124;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82298AB4:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x82298ab4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82298AB4;
	// lbz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// li r11,0
	r11.s64 = 0;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// stfs f31,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lbz r8,18(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// stb r11,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r11.u8);
	// stb r10,19(r31)
	PPC_STORE_U8(r31.u32 + 19, ctx.r10.u8);
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lbz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// sth r9,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r9.u16);
	// ori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 | 128;
	// stb r8,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r8.u8);
	// stb r4,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r4.u8);
	// lwz r3,48(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bge cr6,0x82298b20
	if (!cr6.lt) goto loc_82298B20;
	// li r7,-1
	ctx.r7.s64 = -1;
	// b 0x82298b30
	goto loc_82298B30;
loc_82298B20:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// bgt cr6,0x82298b30
	if (cr6.gt) goto loc_82298B30;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_82298B30:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,128(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// beq cr6,0x82298b5c
	if (cr6.eq) goto loc_82298B5C;
	// addi r4,r11,272
	ctx.r4.s64 = r11.s64 + 272;
	// b 0x82298b64
	goto loc_82298B64;
loc_82298B5C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
loc_82298B64:
	// addi r6,r10,288
	ctx.r6.s64 = ctx.r10.s64 + 288;
	// addi r5,r10,272
	ctx.r5.s64 = ctx.r10.s64 + 272;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8229b348
	ctx.lr = 0x82298B74;
	sub_8229B348(ctx, base);
	// stfs f31,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lbz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r8,r9,64
	ctx.r8.u64 = ctx.r9.u64 | 64;
	// stb r8,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r8.u8);
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b620
	ctx.lr = 0x82298B9C;
	sub_8227B620(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_82298BB8"))) PPC_WEAK_FUNC(sub_82298BB8);
PPC_FUNC_IMPL(__imp__sub_82298BB8) {
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
	ctx.lr = 0x82298BC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,16704
	ctx.r10.s64 = r11.s64 + 16704;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// sth r28,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r28.u16);
	// sth r28,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r28.u16);
	// beq cr6,0x82298c00
	if (cr6.eq) goto loc_82298C00;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822987c8
	ctx.lr = 0x82298BFC;
	sub_822987C8(ctx, base);
	// b 0x82298c04
	goto loc_82298C04;
loc_82298C00:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82298C04:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82298C1C"))) PPC_WEAK_FUNC(sub_82298C1C);
PPC_FUNC_IMPL(__imp__sub_82298C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82298C20"))) PPC_WEAK_FUNC(sub_82298C20);
PPC_FUNC_IMPL(__imp__sub_82298C20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82298c60
	if (!cr6.gt) goto loc_82298C60;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_82298C38:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r7,r4
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, xer);
	// beq cr6,0x82298c58
	if (cr6.eq) goto loc_82298C58;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82298c38
	if (cr6.lt) goto loc_82298C38;
	// b 0x82298c60
	goto loc_82298C60;
loc_82298C58:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgelr cr6
	if (!cr6.lt) return;
loc_82298C60:
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f0.f64 = double(temp.f32);
	// sth r6,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r6.u16);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// sth r8,16(r11)
	PPC_STORE_U16(r11.u32 + 16, ctx.r8.u16);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stb r8,18(r11)
	PPC_STORE_U8(r11.u32 + 18, ctx.r8.u8);
	// stb r8,19(r11)
	PPC_STORE_U8(r11.u32 + 19, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82298CAC"))) PPC_WEAK_FUNC(sub_82298CAC);
PPC_FUNC_IMPL(__imp__sub_82298CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82298CB0"))) PPC_WEAK_FUNC(sub_82298CB0);
PPC_FUNC_IMPL(__imp__sub_82298CB0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82298CB8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 28);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82298dc4
	if (!cr6.eq) goto loc_82298DC4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82298dc4
	if (cr6.eq) goto loc_82298DC4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82298dc4
	if (cr6.eq) goto loc_82298DC4;
	// li r29,0
	r29.s64 = 0;
loc_82298D0C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r30,r29,r11
	r30.u64 = r29.u64 + r11.u64;
	// bl 0x822a5578
	ctx.lr = 0x82298D1C;
	sub_822A5578(ctx, base);
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lhz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// sth r9,16(r30)
	PPC_STORE_U16(r30.u32 + 16, ctx.r9.u16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x822a5578
	ctx.lr = 0x82298D34;
	sub_822A5578(ctx, base);
	// lbz r7,127(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 127);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82298d50
	if (cr6.eq) goto loc_82298D50;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x822a5578
	ctx.lr = 0x82298D48;
	sub_822A5578(ctx, base);
	// lbz r11,127(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 127);
	// stb r11,18(r30)
	PPC_STORE_U8(r30.u32 + 18, r11.u8);
loc_82298D50:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822988d0
	ctx.lr = 0x82298D5C;
	sub_822988D0(ctx, base);
	// stfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82298658
	ctx.lr = 0x82298D70;
	sub_82298658(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82298738
	ctx.lr = 0x82298D84;
	sub_82298738(ctx, base);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298da0
	if (!cr6.eq) goto loc_82298DA0;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298db0
	if (cr6.eq) goto loc_82298DB0;
loc_82298DA0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82298a70
	ctx.lr = 0x82298DB0;
	sub_82298A70(ctx, base);
loc_82298DB0:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82298d0c
	if (cr6.lt) goto loc_82298D0C;
loc_82298DC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82298DD0"))) PPC_WEAK_FUNC(sub_82298DD0);
PPC_FUNC_IMPL(__imp__sub_82298DD0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,16704
	ctx.r10.s64 = r11.s64 + 16704;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82298e0c
	if (cr6.eq) goto loc_82298E0C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82298E0C;
	sub_82130588(ctx, base);
loc_82298E0C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298e24
	if (cr6.eq) goto loc_82298E24;
	// bl 0x82130588
	ctx.lr = 0x82298E20;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82298E24:
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

__attribute__((alias("__imp__sub_82298E3C"))) PPC_WEAK_FUNC(sub_82298E3C);
PPC_FUNC_IMPL(__imp__sub_82298E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82298E40"))) PPC_WEAK_FUNC(sub_82298E40);
PPC_FUNC_IMPL(__imp__sub_82298E40) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82298e68
	if (!cr6.eq) goto loc_82298E68;
loc_82298E60:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82298e98
	goto loc_82298E98;
loc_82298E68:
	// li r31,0
	r31.s64 = 0;
	// addi r30,r3,21856
	r30.s64 = ctx.r3.s64 + 21856;
loc_82298E70:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fd670
	ctx.lr = 0x82298E78;
	sub_824FD670(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298e60
	if (!cr6.eq) goto loc_82298E60;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// blt cr6,0x82298e70
	if (cr6.lt) goto loc_82298E70;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82298E98:
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

__attribute__((alias("__imp__sub_82298EB0"))) PPC_WEAK_FUNC(sub_82298EB0);
PPC_FUNC_IMPL(__imp__sub_82298EB0) {
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
	ctx.lr = 0x82298EB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,27505
	r31.s64 = ctx.r3.s64 + 27505;
	// addi r29,r3,21856
	r29.s64 = ctx.r3.s64 + 21856;
	// li r30,32
	r30.s64 = 32;
	// li r28,0
	r28.s64 = 0;
loc_82298ECC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fd670
	ctx.lr = 0x82298ED4;
	sub_824FD670(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82298ee8
	if (cr6.eq) goto loc_82298EE8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fd688
	ctx.lr = 0x82298EE8;
	sub_824FD688(ctx, base);
loc_82298EE8:
	// stb r28,-1(r31)
	PPC_STORE_U8(r31.u32 + -1, r28.u8);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x82298ecc
	if (!cr0.eq) goto loc_82298ECC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82298F08"))) PPC_WEAK_FUNC(sub_82298F08);
PPC_FUNC_IMPL(__imp__sub_82298F08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,2000(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2000);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82298f48
	if (cr6.eq) goto loc_82298F48;
	// addi r10,r3,27504
	ctx.r10.s64 = ctx.r3.s64 + 27504;
loc_82298F20:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82298f38
	if (cr6.eq) goto loc_82298F38;
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x82298f50
	if (cr6.eq) goto loc_82298F50;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_82298F38:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82298f20
	if (!cr6.eq) goto loc_82298F20;
loc_82298F48:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82298F50:
	// mulli r11,r11,620
	r11.s64 = r11.s64 * 620;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,2016
	ctx.r3.s64 = r11.s64 + 2016;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82298F60"))) PPC_WEAK_FUNC(sub_82298F60);
PPC_FUNC_IMPL(__imp__sub_82298F60) {
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
	ctx.lr = 0x82298F68;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8229907c
	if (!cr6.eq) goto loc_8229907C;
	// addi r26,r31,528
	r26.s64 = r31.s64 + 528;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824fbd50
	ctx.lr = 0x82298F9C;
	sub_824FBD50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229907c
	if (!cr6.eq) goto loc_8229907C;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70e0
	ctx.lr = 0x82298FB4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229907c
	if (cr6.eq) goto loc_8229907C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70f0
	ctx.lr = 0x82298FC8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82298fe0
	if (!cr6.eq) goto loc_82298FE0;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229907c
	if (cr6.eq) goto loc_8229907C;
loc_82298FE0:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x82298eb0
	ctx.lr = 0x82298FF0;
	sub_82298EB0(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// stw r27,2000(r31)
	PPC_STORE_U32(r31.u32 + 2000, r27.u32);
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10240);
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x82299010;
	sub_822950F8(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// clrlwi r8,r23,24
	ctx.r8.u64 = r23.u32 & 0xFF;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// addi r10,r31,1992
	ctx.r10.s64 = r31.s64 + 1992;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r4,2008(r31)
	PPC_STORE_U32(r31.u32 + 2008, ctx.r4.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// lwz r11,-10240(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10240);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// rlwinm r5,r5,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// bl 0x824fd470
	ctx.lr = 0x82299064;
	sub_824FD470(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82299080
	if (!cr6.eq) goto loc_82299080;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8229907C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82299080:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82299088"))) PPC_WEAK_FUNC(sub_82299088);
PPC_FUNC_IMPL(__imp__sub_82299088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82299090;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,528
	ctx.r3.s64 = r31.s64 + 528;
	// bl 0x824fd0b0
	ctx.lr = 0x822990A0;
	sub_824FD0B0(ctx, base);
	// addi r29,r31,21856
	r29.s64 = r31.s64 + 21856;
	// addi r31,r31,28128
	r31.s64 = r31.s64 + 28128;
	// li r30,32
	r30.s64 = 32;
	// li r28,0
	r28.s64 = 0;
loc_822990B0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82270908
	ctx.lr = 0x822990BC;
	sub_82270908(ctx, base);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// bne 0x822990b0
	if (!cr0.eq) goto loc_822990B0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822990D8"))) PPC_WEAK_FUNC(sub_822990D8);
PPC_FUNC_IMPL(__imp__sub_822990D8) {
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
	ctx.lr = 0x822990E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821b5a60
	ctx.lr = 0x82299108;
	sub_821B5A60(ctx, base);
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// bl 0x821b5a60
	ctx.lr = 0x82299110;
	sub_821B5A60(ctx, base);
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// stb r9,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r9.u8);
	// bl 0x827283c8
	ctx.lr = 0x82299134;
	sub_827283C8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299190
	if (cr6.eq) goto loc_82299190;
loc_82299140:
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299168
	if (cr6.eq) goto loc_82299168;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82299164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8229917c
	goto loc_8229917C;
loc_82299168:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8229917C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229917C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824fd7b0
	ctx.lr = 0x82299184;
	sub_824FD7B0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299140
	if (!cr6.eq) goto loc_82299140;
loc_82299190:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229920c
	if (cr6.eq) goto loc_8229920C;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822991d0
	if (!cr6.eq) goto loc_822991D0;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822991c8
	if (cr6.eq) goto loc_822991C8;
	// stw r28,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r28.u32);
	// b 0x822991f8
	goto loc_822991F8;
loc_822991C8:
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// b 0x822991f8
	goto loc_822991F8;
loc_822991D0:
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822991f0
	if (cr6.eq) goto loc_822991F0;
	// lwz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// b 0x822991f8
	goto loc_822991F8;
loc_822991F0:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822991F8:
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8229920C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82299214"))) PPC_WEAK_FUNC(sub_82299214);
PPC_FUNC_IMPL(__imp__sub_82299214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299218"))) PPC_WEAK_FUNC(sub_82299218);
PPC_FUNC_IMPL(__imp__sub_82299218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// subf r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// li r10,176
	ctx.r10.s64 = 176;
	// addi r11,r11,-21856
	r11.s64 = r11.s64 + -21856;
	// li r8,0
	ctx.r8.s64 = 0;
	// divw r11,r11,r10
	r11.s32 = r11.s32 / ctx.r10.s32;
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r8,27505(r11)
	PPC_STORE_U8(r11.u32 + 27505, ctx.r8.u8);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-28060
	r12.s64 = r12.s64 + -28060;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82299274;
	case 1:
		goto loc_8229928C;
	case 2:
		goto loc_822992E8;
	case 3:
		goto loc_82299294;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-28044(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28044);
	// lwz r17,-28020(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28020);
	// lwz r17,-27928(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27928);
	// lwz r17,-28012(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -28012);
loc_82299274:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r8,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r8.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,28896
	ctx.r3.s64 = ctx.r3.s64 + 28896;
	// b 0x822990d8
	sub_822990D8(ctx, base);
	return;
loc_8229928C:
	// stb r8,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r8.u8);
	// blr 
	return;
loc_82299294:
	// stb r8,27504(r11)
	PPC_STORE_U8(r11.u32 + 27504, ctx.r8.u8);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r9,2000(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2000);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822992d4
	if (cr6.eq) goto loc_822992D4;
	// addi r11,r3,27504
	r11.s64 = ctx.r3.s64 + 27504;
loc_822992AC:
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822992ac
	if (!cr6.eq) goto loc_822992AC;
loc_822992D4:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,28896
	ctx.r3.s64 = ctx.r3.s64 + 28896;
	// b 0x822990d8
	sub_822990D8(ctx, base);
	return;
loc_822992E8:
	// li r10,1
	ctx.r10.s64 = 1;
}

__attribute__((alias("__imp__sub_82299320"))) PPC_WEAK_FUNC(sub_82299320);
PPC_FUNC_IMPL(__imp__sub_82299320) {
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
	ctx.lr = 0x82299328;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r28,528
	ctx.r3.s64 = r28.s64 + 528;
	// bl 0x824fbd00
	ctx.lr = 0x82299338;
	sub_824FBD00(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
	// bl 0x82298eb0
	ctx.lr = 0x82299348;
	sub_82298EB0(ctx, base);
	// addi r31,r28,28144
	r31.s64 = r28.s64 + 28144;
	// stw r29,2000(r28)
	PPC_STORE_U32(r28.u32 + 2000, r29.u32);
	// addi r30,r28,21868
	r30.s64 = r28.s64 + 21868;
	// li r27,32
	r27.s64 = 32;
loc_82299358:
	// lis r11,-32214
	r11.s64 = -2111176704;
	// stw r29,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, r29.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-28136
	ctx.r10.s64 = r11.s64 + -28136;
	// stw r10,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x82299370;
	sub_82130000(ctx, base);
	// stw r3,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, ctx.r3.u32);
	// lwz r9,-8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822993bc
	if (cr6.eq) goto loc_822993BC;
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r11,r31,-16
	r11.s64 = r31.s64 + -16;
	// beq cr6,0x822993ac
	if (cr6.eq) goto loc_822993AC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// stw r10,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r10.u32);
	// b 0x822993d0
	goto loc_822993D0;
loc_822993AC:
	// stw r11,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r11.u32);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// stw r10,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r10.u32);
	// b 0x822993d0
	goto loc_822993D0;
loc_822993BC:
	// addi r11,r31,-16
	r11.s64 = r31.s64 + -16;
	// stw r11,-8(r30)
	PPC_STORE_U32(r30.u32 + -8, r11.u32);
	// stw r11,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r11.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r29,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r29.u32);
loc_822993D0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r11,r30,-12
	r11.s64 = r30.s64 + -12;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x82299358
	if (!cr0.eq) goto loc_82299358;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822993FC"))) PPC_WEAK_FUNC(sub_822993FC);
PPC_FUNC_IMPL(__imp__sub_822993FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299400"))) PPC_WEAK_FUNC(sub_82299400);
PPC_FUNC_IMPL(__imp__sub_82299400) {
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
	ctx.lr = 0x82299408;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// li r25,1
	r25.s64 = 1;
	// lwz r11,2004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2004);
	// subf r11,r11,r24
	r11.s64 = r24.s64 - r11.s64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bge cr6,0x82299430
	if (!cr6.lt) goto loc_82299430;
	// mr r28,r25
	r28.u64 = r25.u64;
	// b 0x82299440
	goto loc_82299440;
loc_82299430:
	// cmplwi cr6,r11,1000
	cr6.compare<uint32_t>(r11.u32, 1000, xer);
	// li r28,1000
	r28.s64 = 1000;
	// bgt cr6,0x82299440
	if (cr6.gt) goto loc_82299440;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82299440:
	// addi r27,r31,528
	r27.s64 = r31.s64 + 528;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824fd428
	ctx.lr = 0x8229944C;
	sub_824FD428(ctx, base);
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82299480
	if (!cr6.gt) goto loc_82299480;
	// addi r29,r31,21856
	r29.s64 = r31.s64 + 21856;
loc_82299460:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fdc88
	ctx.lr = 0x8229946C;
	sub_824FDC88(ctx, base);
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82299460
	if (cr6.lt) goto loc_82299460;
loc_82299480:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82299568
	if (!cr6.eq) goto loc_82299568;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82299568
	if (cr6.eq) goto loc_82299568;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824fbd50
	ctx.lr = 0x822994A0;
	sub_824FBD50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299568
	if (!cr6.eq) goto loc_82299568;
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822994e0
	if (!cr6.eq) goto loc_822994E0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,28896
	ctx.r3.s64 = r31.s64 + 28896;
	// bl 0x822990d8
	ctx.lr = 0x822994CC;
	sub_822990D8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r24,2004(r31)
	PPC_STORE_U32(r31.u32 + 2004, r24.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822994E0:
	// li r27,0
	r27.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r31,21856
	r29.s64 = r31.s64 + 21856;
	// addi r30,r31,27488
	r30.s64 = r31.s64 + 27488;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_822994F4:
	// lbz r11,2012(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299530
	if (cr6.eq) goto loc_82299530;
	// lwz r11,-10240(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// li r7,11
	ctx.r7.s64 = 11;
	// lwz r10,1992(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1992);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,2008(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2008);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// addi r4,r10,557
	ctx.r4.s64 = ctx.r10.s64 + 557;
	// lwz r6,68(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824fdc30
	ctx.lr = 0x82299528;
	sub_824FDC30(ctx, base);
	// stb r25,17(r30)
	PPC_STORE_U8(r30.u32 + 17, r25.u8);
	// b 0x82299544
	goto loc_82299544;
loc_82299530:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299218
	ctx.lr = 0x82299544;
	sub_82299218(ctx, base);
loc_82299544:
	// lwz r11,2000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,620
	r28.s64 = r28.s64 + 620;
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x822994f4
	if (!cr6.eq) goto loc_822994F4;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82299568:
	// stw r24,2004(r31)
	PPC_STORE_U32(r31.u32 + 2004, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82299574"))) PPC_WEAK_FUNC(sub_82299574);
PPC_FUNC_IMPL(__imp__sub_82299574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299578"))) PPC_WEAK_FUNC(sub_82299578);
PPC_FUNC_IMPL(__imp__sub_82299578) {
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
	// bl 0x821c9788
	ctx.lr = 0x82299590;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824eff10
	ctx.lr = 0x8229959C;
	sub_824EFF10(ctx, base);
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

__attribute__((alias("__imp__sub_822995B0"))) PPC_WEAK_FUNC(sub_822995B0);
PPC_FUNC_IMPL(__imp__sub_822995B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822995C4"))) PPC_WEAK_FUNC(sub_822995C4);
PPC_FUNC_IMPL(__imp__sub_822995C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822995C8"))) PPC_WEAK_FUNC(sub_822995C8);
PPC_FUNC_IMPL(__imp__sub_822995C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822995E0"))) PPC_WEAK_FUNC(sub_822995E0);
PPC_FUNC_IMPL(__imp__sub_822995E0) {
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
	ctx.lr = 0x822995E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82299630
	if (!cr6.eq) goto loc_82299630;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229966c
	if (cr6.eq) goto loc_8229966C;
loc_82299630:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// stw r29,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r29.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r8,208(r31)
	PPC_STORE_U8(r31.u32 + 208, ctx.r8.u8);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8229966C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229966C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82299674"))) PPC_WEAK_FUNC(sub_82299674);
PPC_FUNC_IMPL(__imp__sub_82299674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299678"))) PPC_WEAK_FUNC(sub_82299678);
PPC_FUNC_IMPL(__imp__sub_82299678) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822996A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822996d8
	if (cr6.eq) goto loc_822996D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822996C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822996D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822996D8:
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

__attribute__((alias("__imp__sub_822996F0"))) PPC_WEAK_FUNC(sub_822996F0);
PPC_FUNC_IMPL(__imp__sub_822996F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82299734
	if (!cr6.eq) goto loc_82299734;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299728
	if (cr6.eq) goto loc_82299728;
	// stw r6,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,100(r6)
	PPC_STORE_U32(ctx.r6.u32 + 100, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x8229976c
	if (!cr6.eq) goto loc_8229976C;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x8229976c
	goto loc_8229976C;
loc_82299728:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x8229976c
	goto loc_8229976C;
loc_82299734:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x82299754
	if (!cr6.eq) goto loc_82299754;
	// stw r11,96(r6)
	PPC_STORE_U32(ctx.r6.u32 + 96, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x8229976c
	goto loc_8229976C;
loc_82299754:
	// stw r5,96(r6)
	PPC_STORE_U32(ctx.r6.u32 + 96, ctx.r5.u32);
	// lwz r11,100(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	// stw r11,100(r6)
	PPC_STORE_U32(ctx.r6.u32 + 100, r11.u32);
	// lwz r10,100(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	// stw r6,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, ctx.r6.u32);
	// stw r6,100(r5)
	PPC_STORE_U32(ctx.r5.u32 + 100, ctx.r6.u32);
loc_8229976C:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82299784"))) PPC_WEAK_FUNC(sub_82299784);
PPC_FUNC_IMPL(__imp__sub_82299784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299788"))) PPC_WEAK_FUNC(sub_82299788);
PPC_FUNC_IMPL(__imp__sub_82299788) {
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
	ctx.lr = 0x82299790;
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
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x822997B0;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822997f0
	if (cr6.eq) goto loc_822997F0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822997D8;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822997E4;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822997F0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822997FC"))) PPC_WEAK_FUNC(sub_822997FC);
PPC_FUNC_IMPL(__imp__sub_822997FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299800"))) PPC_WEAK_FUNC(sub_82299800);
PPC_FUNC_IMPL(__imp__sub_82299800) {
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
	ctx.lr = 0x82299808;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229986c
	if (cr6.eq) goto loc_8229986C;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// li r30,16
	r30.s64 = 16;
loc_82299828:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824ebcc8
	ctx.lr = 0x82299834;
	sub_824EBCC8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82299828
	if (!cr0.eq) goto loc_82299828;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824eeea0
	ctx.lr = 0x82299848;
	sub_824EEEA0(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299868
	if (cr6.eq) goto loc_82299868;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82299868:
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
loc_8229986C:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229988c
	if (cr6.eq) goto loc_8229988C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229988C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229988C:
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82299898"))) PPC_WEAK_FUNC(sub_82299898);
PPC_FUNC_IMPL(__imp__sub_82299898) {
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
	ctx.lr = 0x822998A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822998C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299918
	if (cr6.eq) goto loc_82299918;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// bl 0x824efbf8
	ctx.lr = 0x822998F8;
	sub_824EFBF8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stb r10,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r10.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82299918:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82299924"))) PPC_WEAK_FUNC(sub_82299924);
PPC_FUNC_IMPL(__imp__sub_82299924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299928"))) PPC_WEAK_FUNC(sub_82299928);
PPC_FUNC_IMPL(__imp__sub_82299928) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299990
	if (cr6.eq) goto loc_82299990;
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
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82299980
	if (cr6.eq) goto loc_82299980;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82299990
	if (!cr6.eq) goto loc_82299990;
loc_82299980:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82299994
	if (!cr6.lt) goto loc_82299994;
loc_82299990:
	// li r11,0
	r11.s64 = 0;
loc_82299994:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822999c8
	if (cr6.eq) goto loc_822999C8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,5
	ctx.r10.s64 = 5;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ef220
	ctx.lr = 0x822999C8;
	sub_824EF220(ctx, base);
loc_822999C8:
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

__attribute__((alias("__imp__sub_822999E0"))) PPC_WEAK_FUNC(sub_822999E0);
PPC_FUNC_IMPL(__imp__sub_822999E0) {
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
	ctx.lr = 0x822999E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299A04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r27,8
	r28.s64 = r27.s64 + 8;
loc_82299A10:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82299a3c
	if (cr6.eq) goto loc_82299A3C;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// beq cr6,0x82299a2c
	if (cr6.eq) goto loc_82299A2C;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82299a3c
	if (!cr6.eq) goto loc_82299A3C;
loc_82299A2C:
	// lwz r11,-4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82299a40
	if (!cr6.lt) goto loc_82299A40;
loc_82299A3C:
	// li r11,0
	r11.s64 = 0;
loc_82299A40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299a60
	if (cr6.eq) goto loc_82299A60;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299928
	ctx.lr = 0x82299A5C;
	sub_82299928(ctx, base);
	// b 0x82299a84
	goto loc_82299A84;
loc_82299A60:
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824ee190
	ctx.lr = 0x82299A6C;
	sub_824EE190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x82299a84
	if (cr6.eq) goto loc_82299A84;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x824ef220
	ctx.lr = 0x82299A84;
	sub_824EF220(ctx, base);
loc_82299A84:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// blt cr6,0x82299a10
	if (cr6.lt) goto loc_82299A10;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82299A9C"))) PPC_WEAK_FUNC(sub_82299A9C);
PPC_FUNC_IMPL(__imp__sub_82299A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

