#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826D1110"))) PPC_WEAK_FUNC(sub_826D1110);
PPC_FUNC_IMPL(__imp__sub_826D1110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r10,r11,-23508
	ctx.r10.s64 = r11.s64 + -23508;
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D1134"))) PPC_WEAK_FUNC(sub_826D1134);
PPC_FUNC_IMPL(__imp__sub_826D1134) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1138"))) PPC_WEAK_FUNC(sub_826D1138);
PPC_FUNC_IMPL(__imp__sub_826D1138) {
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
	ctx.lr = 0x826D1140;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r7,r10,-23540
	ctx.r7.s64 = ctx.r10.s64 + -23540;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r9,10380
	r30.s64 = ctx.r9.s64 + 10380;
	// addi r29,r8,1332
	r29.s64 = ctx.r8.s64 + 1332;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// bl 0x823d9750
	ctx.lr = 0x826D1178;
	sub_823D9750(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r5,9848
	ctx.r4.s64 = ctx.r5.s64 + 9848;
	// addi r5,r31,88
	ctx.r5.s64 = r31.s64 + 88;
	// bl 0x823d9750
	ctx.lr = 0x826D118C;
	sub_823D9750(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r31,120
	ctx.r5.s64 = r31.s64 + 120;
	// bl 0x823d9750
	ctx.lr = 0x826D119C;
	sub_823D9750(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r4,1668
	ctx.r4.s64 = ctx.r4.s64 + 1668;
	// addi r5,r31,152
	ctx.r5.s64 = r31.s64 + 152;
	// bl 0x823d9750
	ctx.lr = 0x826D11B0;
	sub_823D9750(ctx, base);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r4,r3,1652
	ctx.r4.s64 = ctx.r3.s64 + 1652;
	// addi r3,r11,1412
	ctx.r3.s64 = r11.s64 + 1412;
	// bl 0x823d9750
	ctx.lr = 0x826D11C8;
	sub_823D9750(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D11D0"))) PPC_WEAK_FUNC(sub_826D11D0);
PPC_FUNC_IMPL(__imp__sub_826D11D0) {
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
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826d0b78
	ctx.lr = 0x826D11EC;
	sub_826D0B78(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,1696
	ctx.r8.s64 = ctx.r10.s64 + 1696;
	// addi r7,r9,1684
	ctx.r7.s64 = ctx.r9.s64 + 1684;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stb r6,41(r31)
	PPC_STORE_U8(r31.u32 + 41, ctx.r6.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D1230"))) PPC_WEAK_FUNC(sub_826D1230);
PPC_FUNC_IMPL(__imp__sub_826D1230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27184(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27184);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D123C"))) PPC_WEAK_FUNC(sub_826D123C);
PPC_FUNC_IMPL(__imp__sub_826D123C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1240"))) PPC_WEAK_FUNC(sub_826D1240);
PPC_FUNC_IMPL(__imp__sub_826D1240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1254"))) PPC_WEAK_FUNC(sub_826D1254);
PPC_FUNC_IMPL(__imp__sub_826D1254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1258"))) PPC_WEAK_FUNC(sub_826D1258);
PPC_FUNC_IMPL(__imp__sub_826D1258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r3,92
	ctx.r10.s64 = ctx.r3.s64 + 92;
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// stbx r9,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lbz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// stbx r8,r10,r4
	PPC_STORE_U8(ctx.r10.u32 + ctx.r4.u32, ctx.r8.u8);
	// lbz r7,93(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 93);
	// stb r7,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r7.u8);
	// lbz r6,94(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 94);
	// stb r6,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r6.u8);
	// lbz r4,95(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 95);
	// stb r4,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r4.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D12A8"))) PPC_WEAK_FUNC(sub_826D12A8);
PPC_FUNC_IMPL(__imp__sub_826D12A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r3,92
	r11.s64 = ctx.r3.s64 + 92;
	// lbzx r9,r10,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lbzx r7,r11,r4
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r7,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, ctx.r7.u8);
	// lbz r6,1(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// stb r6,93(r3)
	PPC_STORE_U8(ctx.r3.u32 + 93, ctx.r6.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,94(r3)
	PPC_STORE_U8(ctx.r3.u32 + 94, ctx.r4.u8);
	// lbz r11,3(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r11,95(r3)
	PPC_STORE_U8(ctx.r3.u32 + 95, r11.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D12F8"))) PPC_WEAK_FUNC(sub_826D12F8);
PPC_FUNC_IMPL(__imp__sub_826D12F8) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r10,-23540
	ctx.r8.s64 = ctx.r10.s64 + -23540;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r4,r9,10380
	ctx.r4.s64 = ctx.r9.s64 + 10380;
	// addi r3,r6,1332
	ctx.r3.s64 = ctx.r6.s64 + 1332;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x823d9750
	ctx.lr = 0x826D1334;
	sub_823D9750(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r4,764
	ctx.r4.s64 = ctx.r4.s64 + 764;
	// addi r3,r3,1412
	ctx.r3.s64 = ctx.r3.s64 + 1412;
	// bl 0x823d9750
	ctx.lr = 0x826D134C;
	sub_823D9750(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D1360"))) PPC_WEAK_FUNC(sub_826D1360);
PPC_FUNC_IMPL(__imp__sub_826D1360) {
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
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826d0b78
	ctx.lr = 0x826D137C;
	sub_826D0B78(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,1760
	ctx.r8.s64 = ctx.r10.s64 + 1760;
	// addi r7,r9,1748
	ctx.r7.s64 = ctx.r9.s64 + 1748;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// stb r6,41(r31)
	PPC_STORE_U8(r31.u32 + 41, ctx.r6.u8);
	// stb r11,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r11.u8);
	// stb r11,92(r31)
	PPC_STORE_U8(r31.u32 + 92, r11.u8);
	// stb r11,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D13D0"))) PPC_WEAK_FUNC(sub_826D13D0);
PPC_FUNC_IMPL(__imp__sub_826D13D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27180);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D13DC"))) PPC_WEAK_FUNC(sub_826D13DC);
PPC_FUNC_IMPL(__imp__sub_826D13DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D13E0"))) PPC_WEAK_FUNC(sub_826D13E0);
PPC_FUNC_IMPL(__imp__sub_826D13E0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r8,r11,1272
	ctx.r8.s64 = r11.s64 + 1272;
	// addi r7,r10,1260
	ctx.r7.s64 = ctx.r10.s64 + 1260;
	// addi r6,r9,-21868
	ctx.r6.s64 = ctx.r9.s64 + -21868;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// bl 0x821d2028
	ctx.lr = 0x826D1428;
	sub_821D2028(ctx, base);
	// clrlwi r5,r30,31
	ctx.r5.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d1440
	if (cr6.eq) goto loc_826D1440;
	// bl 0x82130588
	ctx.lr = 0x826D143C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D1440:
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

__attribute__((alias("__imp__sub_826D1458"))) PPC_WEAK_FUNC(sub_826D1458);
PPC_FUNC_IMPL(__imp__sub_826D1458) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// stw r11,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D146C"))) PPC_WEAK_FUNC(sub_826D146C);
PPC_FUNC_IMPL(__imp__sub_826D146C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1470"))) PPC_WEAK_FUNC(sub_826D1470);
PPC_FUNC_IMPL(__imp__sub_826D1470) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r10,r11,-23508
	ctx.r10.s64 = r11.s64 + -23508;
	// lwz r4,20(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D1494"))) PPC_WEAK_FUNC(sub_826D1494);
PPC_FUNC_IMPL(__imp__sub_826D1494) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1498"))) PPC_WEAK_FUNC(sub_826D1498);
PPC_FUNC_IMPL(__imp__sub_826D1498) {
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
	ctx.lr = 0x826D14A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r7,r10,-23540
	ctx.r7.s64 = ctx.r10.s64 + -23540;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r9,10380
	r30.s64 = ctx.r9.s64 + 10380;
	// addi r29,r8,1332
	r29.s64 = ctx.r8.s64 + 1332;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// bl 0x823d9750
	ctx.lr = 0x826D14D8;
	sub_823D9750(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r5,-7984
	ctx.r4.s64 = ctx.r5.s64 + -7984;
	// addi r5,r31,160
	ctx.r5.s64 = r31.s64 + 160;
	// bl 0x823d9750
	ctx.lr = 0x826D14EC;
	sub_823D9750(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r31,92
	ctx.r5.s64 = r31.s64 + 92;
	// bl 0x823d9750
	ctx.lr = 0x826D14FC;
	sub_823D9750(ctx, base);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r4,1668
	ctx.r4.s64 = ctx.r4.s64 + 1668;
	// addi r5,r31,124
	ctx.r5.s64 = r31.s64 + 124;
	// bl 0x823d9750
	ctx.lr = 0x826D1510;
	sub_823D9750(ctx, base);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// addi r30,r3,1412
	r30.s64 = ctx.r3.s64 + 1412;
	// addi r4,r11,1652
	ctx.r4.s64 = r11.s64 + 1652;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9750
	ctx.lr = 0x826D152C;
	sub_823D9750(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r4,r10,764
	ctx.r4.s64 = ctx.r10.s64 + 764;
	// bl 0x823d9750
	ctx.lr = 0x826D1540;
	sub_823D9750(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D1548"))) PPC_WEAK_FUNC(sub_826D1548);
PPC_FUNC_IMPL(__imp__sub_826D1548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r3,192
	ctx.r10.s64 = ctx.r3.s64 + 192;
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// stbx r9,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lbz r8,192(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 192);
	// stbx r8,r10,r4
	PPC_STORE_U8(ctx.r10.u32 + ctx.r4.u32, ctx.r8.u8);
	// lbz r7,193(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 193);
	// stb r7,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r7.u8);
	// lbz r6,194(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 194);
	// stb r6,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r6.u8);
	// lbz r4,195(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 195);
	// stb r4,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r4.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1598"))) PPC_WEAK_FUNC(sub_826D1598);
PPC_FUNC_IMPL(__imp__sub_826D1598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r3,192
	r11.s64 = ctx.r3.s64 + 192;
	// lbzx r9,r10,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lbzx r7,r11,r4
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r7,192(r3)
	PPC_STORE_U8(ctx.r3.u32 + 192, ctx.r7.u8);
	// lbz r6,1(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// stb r6,193(r3)
	PPC_STORE_U8(ctx.r3.u32 + 193, ctx.r6.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,194(r3)
	PPC_STORE_U8(ctx.r3.u32 + 194, ctx.r4.u8);
	// lbz r11,3(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r11,195(r3)
	PPC_STORE_U8(ctx.r3.u32 + 195, r11.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D15E8"))) PPC_WEAK_FUNC(sub_826D15E8);
PPC_FUNC_IMPL(__imp__sub_826D15E8) {
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
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826d0b78
	ctx.lr = 0x826D1604;
	sub_826D0B78(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,1824
	ctx.r8.s64 = ctx.r10.s64 + 1824;
	// addi r7,r9,1812
	ctx.r7.s64 = ctx.r9.s64 + 1812;
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// stb r6,41(r31)
	PPC_STORE_U8(r31.u32 + 41, ctx.r6.u8);
	// stb r11,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r11.u8);
	// stb r11,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D1650"))) PPC_WEAK_FUNC(sub_826D1650);
PPC_FUNC_IMPL(__imp__sub_826D1650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27176);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D165C"))) PPC_WEAK_FUNC(sub_826D165C);
PPC_FUNC_IMPL(__imp__sub_826D165C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1660"))) PPC_WEAK_FUNC(sub_826D1660);
PPC_FUNC_IMPL(__imp__sub_826D1660) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r10,r11,-23508
	ctx.r10.s64 = r11.s64 + -23508;
	// lwz r4,24(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D1684"))) PPC_WEAK_FUNC(sub_826D1684);
PPC_FUNC_IMPL(__imp__sub_826D1684) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1688"))) PPC_WEAK_FUNC(sub_826D1688);
PPC_FUNC_IMPL(__imp__sub_826D1688) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r10,-23540
	ctx.r8.s64 = ctx.r10.s64 + -23540;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r9,1332
	r30.s64 = ctx.r9.s64 + 1332;
	// addi r4,r6,10380
	ctx.r4.s64 = ctx.r6.s64 + 10380;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x823d9750
	ctx.lr = 0x826D16CC;
	sub_823D9750(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,1872
	ctx.r4.s64 = ctx.r5.s64 + 1872;
	// addi r5,r31,88
	ctx.r5.s64 = r31.s64 + 88;
	// bl 0x823d9750
	ctx.lr = 0x826D16E0;
	sub_823D9750(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r4,-7984
	ctx.r4.s64 = ctx.r4.s64 + -7984;
	// addi r5,r31,124
	ctx.r5.s64 = r31.s64 + 124;
	// bl 0x823d9750
	ctx.lr = 0x826D16F4;
	sub_823D9750(ctx, base);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r4,r3,764
	ctx.r4.s64 = ctx.r3.s64 + 764;
	// addi r3,r11,1412
	ctx.r3.s64 = r11.s64 + 1412;
	// bl 0x823d9750
	ctx.lr = 0x826D170C;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826D1724"))) PPC_WEAK_FUNC(sub_826D1724);
PPC_FUNC_IMPL(__imp__sub_826D1724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1728"))) PPC_WEAK_FUNC(sub_826D1728);
PPC_FUNC_IMPL(__imp__sub_826D1728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826D1748"))) PPC_WEAK_FUNC(sub_826D1748);
PPC_FUNC_IMPL(__imp__sub_826D1748) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D174C"))) PPC_WEAK_FUNC(sub_826D174C);
PPC_FUNC_IMPL(__imp__sub_826D174C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1750"))) PPC_WEAK_FUNC(sub_826D1750);
PPC_FUNC_IMPL(__imp__sub_826D1750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1764"))) PPC_WEAK_FUNC(sub_826D1764);
PPC_FUNC_IMPL(__imp__sub_826D1764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1768"))) PPC_WEAK_FUNC(sub_826D1768);
PPC_FUNC_IMPL(__imp__sub_826D1768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r3,156
	ctx.r10.s64 = ctx.r3.s64 + 156;
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// stbx r9,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lbz r8,156(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 156);
	// stbx r8,r10,r4
	PPC_STORE_U8(ctx.r10.u32 + ctx.r4.u32, ctx.r8.u8);
	// lbz r7,157(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 157);
	// stb r7,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r7.u8);
	// lbz r6,158(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 158);
	// stb r6,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r6.u8);
	// lbz r4,159(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 159);
	// stb r4,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r4.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D17B8"))) PPC_WEAK_FUNC(sub_826D17B8);
PPC_FUNC_IMPL(__imp__sub_826D17B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r3,156
	r11.s64 = ctx.r3.s64 + 156;
	// lbzx r9,r10,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lbzx r7,r11,r4
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r7,156(r3)
	PPC_STORE_U8(ctx.r3.u32 + 156, ctx.r7.u8);
	// lbz r6,1(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// stb r6,157(r3)
	PPC_STORE_U8(ctx.r3.u32 + 157, ctx.r6.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,158(r3)
	PPC_STORE_U8(ctx.r3.u32 + 158, ctx.r4.u8);
	// lbz r11,3(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r11,159(r3)
	PPC_STORE_U8(ctx.r3.u32 + 159, r11.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1808"))) PPC_WEAK_FUNC(sub_826D1808);
PPC_FUNC_IMPL(__imp__sub_826D1808) {
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
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826d0b78
	ctx.lr = 0x826D1824;
	sub_826D0B78(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,1900
	ctx.r8.s64 = ctx.r10.s64 + 1900;
	// addi r7,r9,1888
	ctx.r7.s64 = ctx.r9.s64 + 1888;
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// stw r11,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r11.u32);
	// stb r6,41(r31)
	PPC_STORE_U8(r31.u32 + 41, ctx.r6.u8);
	// stb r11,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D1874"))) PPC_WEAK_FUNC(sub_826D1874);
PPC_FUNC_IMPL(__imp__sub_826D1874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1878"))) PPC_WEAK_FUNC(sub_826D1878);
PPC_FUNC_IMPL(__imp__sub_826D1878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27172(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27172);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1884"))) PPC_WEAK_FUNC(sub_826D1884);
PPC_FUNC_IMPL(__imp__sub_826D1884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1888"))) PPC_WEAK_FUNC(sub_826D1888);
PPC_FUNC_IMPL(__imp__sub_826D1888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r10,r11,-23508
	ctx.r10.s64 = r11.s64 + -23508;
	// lwz r4,28(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D18AC"))) PPC_WEAK_FUNC(sub_826D18AC);
PPC_FUNC_IMPL(__imp__sub_826D18AC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D18B0"))) PPC_WEAK_FUNC(sub_826D18B0);
PPC_FUNC_IMPL(__imp__sub_826D18B0) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r10,-23540
	ctx.r8.s64 = ctx.r10.s64 + -23540;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r9,1332
	r30.s64 = ctx.r9.s64 + 1332;
	// addi r4,r6,10380
	ctx.r4.s64 = ctx.r6.s64 + 10380;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x823d9750
	ctx.lr = 0x826D18F4;
	sub_823D9750(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,-7904
	ctx.r4.s64 = ctx.r5.s64 + -7904;
	// addi r5,r31,88
	ctx.r5.s64 = r31.s64 + 88;
	// bl 0x823d9750
	ctx.lr = 0x826D1908;
	sub_823D9750(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// addi r4,r4,-8388
	ctx.r4.s64 = ctx.r4.s64 + -8388;
	// addi r3,r3,1412
	ctx.r3.s64 = ctx.r3.s64 + 1412;
	// bl 0x823d9750
	ctx.lr = 0x826D1920;
	sub_823D9750(ctx, base);
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

__attribute__((alias("__imp__sub_826D1938"))) PPC_WEAK_FUNC(sub_826D1938);
PPC_FUNC_IMPL(__imp__sub_826D1938) {
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
	ctx.lr = 0x826D1940;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// addi r30,r31,88
	r30.s64 = r31.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,-12440(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r27,0(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8238d970
	ctx.lr = 0x826D1970;
	sub_8238D970(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,84(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 84);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826D1984;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d19e8
	if (cr6.eq) goto loc_826D19E8;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d19bc
	if (!cr6.eq) goto loc_826D19BC;
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D19B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
loc_826D19BC:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d1a10
	if (cr6.eq) goto loc_826D1A10;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D19E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_826D19E8:
	// lwz r3,-12440(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12440);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826D1A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D1A10:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826D1A18"))) PPC_WEAK_FUNC(sub_826D1A18);
PPC_FUNC_IMPL(__imp__sub_826D1A18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826D1A3C"))) PPC_WEAK_FUNC(sub_826D1A3C);
PPC_FUNC_IMPL(__imp__sub_826D1A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1A40"))) PPC_WEAK_FUNC(sub_826D1A40);
PPC_FUNC_IMPL(__imp__sub_826D1A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r3,160
	ctx.r10.s64 = ctx.r3.s64 + 160;
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// stbx r9,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lbz r8,160(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 160);
	// stbx r8,r10,r4
	PPC_STORE_U8(ctx.r10.u32 + ctx.r4.u32, ctx.r8.u8);
	// lbz r7,161(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 161);
	// stb r7,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r7.u8);
	// lbz r6,162(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 162);
	// stb r6,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r6.u8);
	// lbz r10,163(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 163);
	// stb r10,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r10.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lbz r9,164(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 164);
	// stbx r9,r10,r4
	PPC_STORE_U8(ctx.r10.u32 + ctx.r4.u32, ctx.r9.u8);
	// lbz r8,165(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 165);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,166(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 166);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,167(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 167);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// stw r4,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1AC0"))) PPC_WEAK_FUNC(sub_826D1AC0);
PPC_FUNC_IMPL(__imp__sub_826D1AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// addi r11,r3,164
	r11.s64 = ctx.r3.s64 + 164;
	// lbzx r9,r10,r4
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lbzx r7,r11,r4
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r7,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r7.u8);
	// lbz r6,1(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// stb r6,161(r3)
	PPC_STORE_U8(ctx.r3.u32 + 161, ctx.r6.u8);
	// lbz r11,2(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r11,162(r3)
	PPC_STORE_U8(ctx.r3.u32 + 162, r11.u8);
	// lbz r10,3(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r10,163(r3)
	PPC_STORE_U8(ctx.r3.u32 + 163, ctx.r10.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r9,r11,r4
	ctx.r9.u64 = r11.u64 + ctx.r4.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lbzx r8,r11,r4
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r8,164(r3)
	PPC_STORE_U8(ctx.r3.u32 + 164, ctx.r8.u8);
	// lbz r7,1(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// stb r7,165(r3)
	PPC_STORE_U8(ctx.r3.u32 + 165, ctx.r7.u8);
	// lbz r6,2(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// stb r6,166(r3)
	PPC_STORE_U8(ctx.r3.u32 + 166, ctx.r6.u8);
	// lbz r4,3(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// stb r4,167(r3)
	PPC_STORE_U8(ctx.r3.u32 + 167, ctx.r4.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D1B44"))) PPC_WEAK_FUNC(sub_826D1B44);
PPC_FUNC_IMPL(__imp__sub_826D1B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1B48"))) PPC_WEAK_FUNC(sub_826D1B48);
PPC_FUNC_IMPL(__imp__sub_826D1B48) {
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
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x826D1B5C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d1b78
	if (cr6.eq) goto loc_826D1B78;
	// bl 0x826d0cd8
	ctx.lr = 0x826D1B68;
	sub_826D0CD8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D1B78:
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

__attribute__((alias("__imp__sub_826D1B8C"))) PPC_WEAK_FUNC(sub_826D1B8C);
PPC_FUNC_IMPL(__imp__sub_826D1B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1B90"))) PPC_WEAK_FUNC(sub_826D1B90);
PPC_FUNC_IMPL(__imp__sub_826D1B90) {
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
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x826D1BA8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d1bf4
	if (cr6.eq) goto loc_826D1BF4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826d0b78
	ctx.lr = 0x826D1BBC;
	sub_826D0B78(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,1464
	ctx.r9.s64 = r11.s64 + 1464;
	// addi r8,r10,1452
	ctx.r8.s64 = ctx.r10.s64 + 1452;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r7,88(r31)
	PPC_STORE_U8(r31.u32 + 88, ctx.r7.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826D1BF4:
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

__attribute__((alias("__imp__sub_826D1C0C"))) PPC_WEAK_FUNC(sub_826D1C0C);
PPC_FUNC_IMPL(__imp__sub_826D1C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1C10"))) PPC_WEAK_FUNC(sub_826D1C10);
PPC_FUNC_IMPL(__imp__sub_826D1C10) {
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
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x826D1C28;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d1c74
	if (cr6.eq) goto loc_826D1C74;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826d0b78
	ctx.lr = 0x826D1C3C;
	sub_826D0B78(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,1540
	ctx.r9.s64 = r11.s64 + 1540;
	// addi r8,r10,1528
	ctx.r8.s64 = ctx.r10.s64 + 1528;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r7,88(r31)
	PPC_STORE_U8(r31.u32 + 88, ctx.r7.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826D1C74:
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

__attribute__((alias("__imp__sub_826D1C8C"))) PPC_WEAK_FUNC(sub_826D1C8C);
PPC_FUNC_IMPL(__imp__sub_826D1C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1C90"))) PPC_WEAK_FUNC(sub_826D1C90);
PPC_FUNC_IMPL(__imp__sub_826D1C90) {
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
	// li r3,188
	ctx.r3.s64 = 188;
	// bl 0x82130528
	ctx.lr = 0x826D1CA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d1cc0
	if (cr6.eq) goto loc_826D1CC0;
	// bl 0x826d10a0
	ctx.lr = 0x826D1CB0;
	sub_826D10A0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D1CC0:
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

__attribute__((alias("__imp__sub_826D1CD4"))) PPC_WEAK_FUNC(sub_826D1CD4);
PPC_FUNC_IMPL(__imp__sub_826D1CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1CD8"))) PPC_WEAK_FUNC(sub_826D1CD8);
PPC_FUNC_IMPL(__imp__sub_826D1CD8) {
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
	ctx.lr = 0x826D1CEC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d1d08
	if (cr6.eq) goto loc_826D1D08;
	// bl 0x826d11d0
	ctx.lr = 0x826D1CF8;
	sub_826D11D0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D1D08:
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

__attribute__((alias("__imp__sub_826D1D1C"))) PPC_WEAK_FUNC(sub_826D1D1C);
PPC_FUNC_IMPL(__imp__sub_826D1D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1D20"))) PPC_WEAK_FUNC(sub_826D1D20);
PPC_FUNC_IMPL(__imp__sub_826D1D20) {
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
	// li r3,196
	ctx.r3.s64 = 196;
	// bl 0x82130528
	ctx.lr = 0x826D1D34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d1d50
	if (cr6.eq) goto loc_826D1D50;
	// bl 0x826d1360
	ctx.lr = 0x826D1D40;
	sub_826D1360(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D1D50:
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

__attribute__((alias("__imp__sub_826D1D64"))) PPC_WEAK_FUNC(sub_826D1D64);
PPC_FUNC_IMPL(__imp__sub_826D1D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1D68"))) PPC_WEAK_FUNC(sub_826D1D68);
PPC_FUNC_IMPL(__imp__sub_826D1D68) {
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
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x826D1D7C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d1d98
	if (cr6.eq) goto loc_826D1D98;
	// bl 0x826d15e8
	ctx.lr = 0x826D1D88;
	sub_826D15E8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D1D98:
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

__attribute__((alias("__imp__sub_826D1DAC"))) PPC_WEAK_FUNC(sub_826D1DAC);
PPC_FUNC_IMPL(__imp__sub_826D1DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1DB0"))) PPC_WEAK_FUNC(sub_826D1DB0);
PPC_FUNC_IMPL(__imp__sub_826D1DB0) {
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
	// li r3,168
	ctx.r3.s64 = 168;
	// bl 0x82130528
	ctx.lr = 0x826D1DC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d1de0
	if (cr6.eq) goto loc_826D1DE0;
	// bl 0x826d1808
	ctx.lr = 0x826D1DD0;
	sub_826D1808(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D1DE0:
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

__attribute__((alias("__imp__sub_826D1DF4"))) PPC_WEAK_FUNC(sub_826D1DF4);
PPC_FUNC_IMPL(__imp__sub_826D1DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1DF8"))) PPC_WEAK_FUNC(sub_826D1DF8);
PPC_FUNC_IMPL(__imp__sub_826D1DF8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x826d13e0
	sub_826D13E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D1E00"))) PPC_WEAK_FUNC(sub_826D1E00);
PPC_FUNC_IMPL(__imp__sub_826D1E00) {
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
	ctx.lr = 0x826D1E08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D1E14;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d1e58
	if (!cr6.eq) goto loc_826D1E58;
	// li r30,1
	r30.s64 = 1;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-3680
	ctx.r4.s64 = r11.s64 + -3680;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D1E40;
	sub_8268B770(ctx, base);
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3700
	ctx.r4.s64 = ctx.r10.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D1E58;
	sub_8268B770(ctx, base);
loc_826D1E58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D1E64"))) PPC_WEAK_FUNC(sub_826D1E64);
PPC_FUNC_IMPL(__imp__sub_826D1E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1E68"))) PPC_WEAK_FUNC(sub_826D1E68);
PPC_FUNC_IMPL(__imp__sub_826D1E68) {
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
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d1eac
	if (cr6.eq) goto loc_826D1EAC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r31,52
	ctx.r4.s64 = r31.s64 + 52;
	// addi r3,r11,1952
	ctx.r3.s64 = r11.s64 + 1952;
	// bl 0x82130000
	ctx.lr = 0x826D1E98;
	sub_82130000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826D1EAC:
	// lbz r11,52(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 52);
	// addi r5,r31,52
	ctx.r5.s64 = r31.s64 + 52;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d1ed4
	if (cr6.eq) goto loc_826D1ED4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x826D1ED0;
	sub_8268B960(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
loc_826D1ED4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D1EE8"))) PPC_WEAK_FUNC(sub_826D1EE8);
PPC_FUNC_IMPL(__imp__sub_826D1EE8) {
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
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d1f20
	if (cr6.eq) goto loc_826D1F20;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826D1F18;
	sub_8268B6D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
loc_826D1F20:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D1F34"))) PPC_WEAK_FUNC(sub_826D1F34);
PPC_FUNC_IMPL(__imp__sub_826D1F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D1F38"))) PPC_WEAK_FUNC(sub_826D1F38);
PPC_FUNC_IMPL(__imp__sub_826D1F38) {
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
	ctx.lr = 0x826D1F40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D1F50;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2014
	if (!cr6.eq) goto loc_826D2014;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d2014
	if (cr6.eq) goto loc_826D2014;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,3998
	ctx.r10.s64 = ctx.r10.s64 + 3998;
loc_826D1F74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d1f98
	if (cr6.eq) goto loc_826D1F98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d1f74
	if (cr6.eq) goto loc_826D1F74;
loc_826D1F98:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d2014
	if (cr6.eq) goto loc_826D2014;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826baf40
	ctx.lr = 0x826D1FAC;
	sub_826BAF40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// bne cr6,0x826d2014
	if (!cr6.eq) goto loc_826D2014;
	// li r28,1
	r28.s64 = 1;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stb r28,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r28.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-3680
	ctx.r4.s64 = r11.s64 + -3680;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D1FD8;
	sub_8268B770(ctx, base);
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r9,124(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// blt cr6,0x826d2014
	if (cr6.lt) goto loc_826D2014;
	// stb r28,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r28.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r11,-3700
	ctx.r4.s64 = r11.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D2008;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D2014:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D2020"))) PPC_WEAK_FUNC(sub_826D2020);
PPC_FUNC_IMPL(__imp__sub_826D2020) {
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
	ctx.lr = 0x826D2028;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826baf40
	ctx.lr = 0x826D2048;
	sub_826BAF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d2088
	if (cr6.eq) goto loc_826D2088;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2068
	if (!cr6.eq) goto loc_826D2068;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
loc_826D2068:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d2088
	if (cr6.eq) goto loc_826D2088;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D2088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D2088:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D2090"))) PPC_WEAK_FUNC(sub_826D2090);
PPC_FUNC_IMPL(__imp__sub_826D2090) {
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
	ctx.lr = 0x826D2098;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826baf40
	ctx.lr = 0x826D20B8;
	sub_826BAF40(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d20fc
	if (cr6.eq) goto loc_826D20FC;
	// lbz r11,40(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d20d4
	if (cr6.eq) goto loc_826D20D4;
	// lwz r7,120(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// b 0x826d20e0
	goto loc_826D20E0;
loc_826D20D4:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// subf r7,r10,r11
	ctx.r7.s64 = r11.s64 - ctx.r10.s64;
loc_826D20E0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,2060
	ctx.r5.s64 = r11.s64 + 2060;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x826D20FC;
	sub_82137A08(ctx, base);
loc_826D20FC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D2104"))) PPC_WEAK_FUNC(sub_826D2104);
PPC_FUNC_IMPL(__imp__sub_826D2104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2108"))) PPC_WEAK_FUNC(sub_826D2108);
PPC_FUNC_IMPL(__imp__sub_826D2108) {
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
	ctx.lr = 0x826D2110;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D2120;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d21ac
	if (!cr6.eq) goto loc_826D21AC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d21ac
	if (cr6.eq) goto loc_826D21AC;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
loc_826D213C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d2160
	if (cr6.eq) goto loc_826D2160;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d213c
	if (cr6.eq) goto loc_826D213C;
loc_826D2160:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826d21ac
	if (!cr6.eq) goto loc_826D21AC;
	// li r30,1
	r30.s64 = 1;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-3680
	ctx.r4.s64 = r11.s64 + -3680;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D2188;
	sub_8268B770(ctx, base);
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3700
	ctx.r4.s64 = ctx.r10.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D21A0;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D21AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D21B8"))) PPC_WEAK_FUNC(sub_826D21B8);
PPC_FUNC_IMPL(__imp__sub_826D21B8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d2210
	if (cr6.eq) goto loc_826D2210;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x826c5850
	ctx.lr = 0x826D21E0;
	sub_826C5850(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d2210
	if (cr6.eq) goto loc_826D2210;
	// lwz r11,656(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826d2210
	if (!cr6.eq) goto loc_826D2210;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D2210;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D2210:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D2224"))) PPC_WEAK_FUNC(sub_826D2224);
PPC_FUNC_IMPL(__imp__sub_826D2224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2228"))) PPC_WEAK_FUNC(sub_826D2228);
PPC_FUNC_IMPL(__imp__sub_826D2228) {
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
	ctx.lr = 0x826D2230;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D2240;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d22cc
	if (!cr6.eq) goto loc_826D22CC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d22cc
	if (cr6.eq) goto loc_826D22CC;
	// addi r10,r30,72
	ctx.r10.s64 = r30.s64 + 72;
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
loc_826D225C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d2280
	if (cr6.eq) goto loc_826D2280;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d225c
	if (cr6.eq) goto loc_826D225C;
loc_826D2280:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826d22cc
	if (!cr6.eq) goto loc_826D22CC;
	// li r30,1
	r30.s64 = 1;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-3680
	ctx.r4.s64 = r11.s64 + -3680;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D22A8;
	sub_8268B770(ctx, base);
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3700
	ctx.r4.s64 = ctx.r10.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D22C0;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D22CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D22D8"))) PPC_WEAK_FUNC(sub_826D22D8);
PPC_FUNC_IMPL(__imp__sub_826D22D8) {
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
	ctx.lr = 0x826D22E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D22F0;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d23f0
	if (!cr6.eq) goto loc_826D23F0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d23f0
	if (cr6.eq) goto loc_826D23F0;
	// addi r3,r31,120
	ctx.r3.s64 = r31.s64 + 120;
	// bl 0x8238e6d8
	ctx.lr = 0x826D230C;
	sub_8238E6D8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826d2328
	if (cr6.eq) goto loc_826D2328;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d2328
	if (cr6.eq) goto loc_826D2328;
	// lwz r11,3088(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3088);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bne cr6,0x826d23f0
	if (!cr6.eq) goto loc_826D23F0;
loc_826D2328:
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// bl 0x8238e748
	ctx.lr = 0x826D2330;
	sub_8238E748(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826d234c
	if (cr6.eq) goto loc_826D234C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d234c
	if (cr6.eq) goto loc_826D234C;
	// lwz r11,3092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3092);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bne cr6,0x826d23f0
	if (!cr6.eq) goto loc_826D23F0;
loc_826D234C:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d2364
	if (cr6.eq) goto loc_826D2364;
	// lwz r10,172(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 172);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x826d23f0
	if (cr6.gt) goto loc_826D23F0;
loc_826D2364:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826d23ac
	if (cr6.eq) goto loc_826D23AC;
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// addi r30,r31,88
	r30.s64 = r31.s64 + 88;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d23ac
	if (cr6.eq) goto loc_826D23AC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826D238C;
	sub_8238EC00(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x823d90b0
	ctx.lr = 0x826D23A4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d23f0
	if (cr6.eq) goto loc_826D23F0;
loc_826D23AC:
	// li r30,1
	r30.s64 = 1;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r30,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r30.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-3680
	ctx.r4.s64 = r11.s64 + -3680;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D23CC;
	sub_8268B770(ctx, base);
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3700
	ctx.r4.s64 = ctx.r10.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D23E4;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D23F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D23FC"))) PPC_WEAK_FUNC(sub_826D23FC);
PPC_FUNC_IMPL(__imp__sub_826D23FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2400"))) PPC_WEAK_FUNC(sub_826D2400);
PPC_FUNC_IMPL(__imp__sub_826D2400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d2420
	if (cr6.eq) goto loc_826D2420;
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// b 0x826d2424
	goto loc_826D2424;
loc_826D2420:
	// lwz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 92);
loc_826D2424:
	// lwz r8,88(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r5,r11,2060
	ctx.r5.s64 = r11.s64 + 2060;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D2438"))) PPC_WEAK_FUNC(sub_826D2438);
PPC_FUNC_IMPL(__imp__sub_826D2438) {
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
	ctx.lr = 0x826D2440;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D244C;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d24b8
	if (!cr6.eq) goto loc_826D24B8;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r29,1
	r29.s64 = 1;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r29,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r29.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3680
	ctx.r4.s64 = ctx.r10.s64 + -3680;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D2484;
	sub_8268B770(ctx, base);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r8,88(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x826d24b8
	if (!cr6.eq) goto loc_826D24B8;
	// stb r29,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r29.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r11,-3700
	ctx.r4.s64 = r11.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D24AC;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D24B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D24C4"))) PPC_WEAK_FUNC(sub_826D24C4);
PPC_FUNC_IMPL(__imp__sub_826D24C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D24C8"))) PPC_WEAK_FUNC(sub_826D24C8);
PPC_FUNC_IMPL(__imp__sub_826D24C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d24e8
	if (cr6.eq) goto loc_826D24E8;
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// b 0x826d24ec
	goto loc_826D24EC;
loc_826D24E8:
	// lwz r7,192(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 192);
loc_826D24EC:
	// lwz r8,88(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r5,r11,2060
	ctx.r5.s64 = r11.s64 + 2060;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D2500"))) PPC_WEAK_FUNC(sub_826D2500);
PPC_FUNC_IMPL(__imp__sub_826D2500) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d2520
	if (cr6.eq) goto loc_826D2520;
	// lwz r7,120(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// b 0x826d2524
	goto loc_826D2524;
loc_826D2520:
	// lwz r7,156(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 156);
loc_826D2524:
	// lwz r8,120(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// addi r5,r11,2060
	ctx.r5.s64 = r11.s64 + 2060;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D2538"))) PPC_WEAK_FUNC(sub_826D2538);
PPC_FUNC_IMPL(__imp__sub_826D2538) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826D256C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r11,r31,120
	r11.s64 = r31.s64 + 120;
	// addi r7,r8,-23468
	ctx.r7.s64 = ctx.r8.s64 + -23468;
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
loc_826D257C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d25a0
	if (cr6.eq) goto loc_826D25A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d257c
	if (cr6.eq) goto loc_826D257C;
loc_826D25A0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d25d0
	if (cr6.eq) goto loc_826D25D0;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// subf. r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x826d25c0
	if (!cr0.lt) goto loc_826D25C0;
	// li r11,0
	r11.s64 = 0;
	// b 0x826d25cc
	goto loc_826D25CC;
loc_826D25C0:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x826d25cc
	if (!cr6.gt) goto loc_826D25CC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_826D25CC:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_826D25D0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D25E4"))) PPC_WEAK_FUNC(sub_826D25E4);
PPC_FUNC_IMPL(__imp__sub_826D25E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D25E8"))) PPC_WEAK_FUNC(sub_826D25E8);
PPC_FUNC_IMPL(__imp__sub_826D25E8) {
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
	ctx.lr = 0x826D25F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D2600;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2708
	if (!cr6.eq) goto loc_826D2708;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d2708
	if (cr6.eq) goto loc_826D2708;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,3998
	ctx.r10.s64 = ctx.r10.s64 + 3998;
loc_826D2624:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d2648
	if (cr6.eq) goto loc_826D2648;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d2624
	if (cr6.eq) goto loc_826D2624;
loc_826D2648:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d2708
	if (cr6.eq) goto loc_826D2708;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_826D2658:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d267c
	if (cr6.eq) goto loc_826D267C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d2658
	if (cr6.eq) goto loc_826D2658;
loc_826D267C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826d2708
	if (!cr6.eq) goto loc_826D2708;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826D26A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,164(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// beq cr6,0x826d2708
	if (cr6.eq) goto loc_826D2708;
	// li r29,1
	r29.s64 = 1;
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stb r29,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r29.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-3680
	ctx.r4.s64 = r11.s64 + -3680;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D26D0;
	sub_8268B770(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r28,156(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// bl 0x826d2538
	ctx.lr = 0x826D26DC;
	sub_826D2538(ctx, base);
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// blt cr6,0x826d2708
	if (cr6.lt) goto loc_826D2708;
	// stb r29,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r29.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r11,-3700
	ctx.r4.s64 = r11.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D26FC;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D2708:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D2714"))) PPC_WEAK_FUNC(sub_826D2714);
PPC_FUNC_IMPL(__imp__sub_826D2714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2718"))) PPC_WEAK_FUNC(sub_826D2718);
PPC_FUNC_IMPL(__imp__sub_826D2718) {
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
	ctx.lr = 0x826D2720;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lbz r11,40(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d2744
	if (cr6.eq) goto loc_826D2744;
	// lwz r29,156(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// b 0x826d2750
	goto loc_826D2750;
loc_826D2744:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d2538
	ctx.lr = 0x826D274C;
	sub_826D2538(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_826D2750:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r8,r31,120
	ctx.r8.s64 = r31.s64 + 120;
	// addi r7,r11,-23468
	ctx.r7.s64 = r11.s64 + -23468;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
loc_826D2764:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x826d2788
	if (cr6.eq) goto loc_826D2788;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d2764
	if (cr6.eq) goto loc_826D2764;
loc_826D2788:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d280c
	if (cr6.eq) goto loc_826D280C;
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826D2798:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x826d27bc
	if (cr6.eq) goto loc_826D27BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d2798
	if (cr6.eq) goto loc_826D2798;
loc_826D27BC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d280c
	if (cr6.eq) goto loc_826D280C;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826D27CC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d27f0
	if (cr6.eq) goto loc_826D27F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d27cc
	if (cr6.eq) goto loc_826D27CC;
loc_826D27F0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826d2868
	if (!cr6.eq) goto loc_826D2868;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r8,156(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r11,2060
	ctx.r5.s64 = r11.s64 + 2060;
	// b 0x826d2858
	goto loc_826D2858;
loc_826D280C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,156(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r31,-10244(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217b70
	ctx.lr = 0x826D282C;
	sub_82217B70(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217b70
	ctx.lr = 0x826D2848;
	sub_82217B70(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r10,2072
	ctx.r5.s64 = ctx.r10.s64 + 2072;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_826D2858:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x826D2868;
	sub_82137A08(ctx, base);
loc_826D2868:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826D2870"))) PPC_WEAK_FUNC(sub_826D2870);
PPC_FUNC_IMPL(__imp__sub_826D2870) {
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
	ctx.lr = 0x826D2878;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D2888;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2968
	if (!cr6.eq) goto loc_826D2968;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
	// lwz r10,-23476(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23476);
loc_826D28A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d28c4
	if (cr6.eq) goto loc_826D28C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d28a0
	if (cr6.eq) goto loc_826D28A0;
loc_826D28C4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826d2974
	if (!cr6.eq) goto loc_826D2974;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r11.u16);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// lwz r30,-10004(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10004);
	// bl 0x8238e818
	ctx.lr = 0x826D28EC;
	sub_8238E818(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c6738
	ctx.lr = 0x826D2904;
	sub_826C6738(ctx, base);
	// lhz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bge cr6,0x826d2954
	if (!cr6.lt) goto loc_826D2954;
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-3700
	ctx.r4.s64 = ctx.r9.s64 + -3700;
	// lwz r3,-10224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D2934;
	sub_8268B770(ctx, base);
	// lhz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826d2948
	if (cr6.eq) goto loc_826D2948;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x826D2948;
	sub_82130588(ctx, base);
loc_826D2948:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826D2954:
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d2968
	if (cr6.eq) goto loc_826D2968;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x826D2968;
	sub_82130588(ctx, base);
loc_826D2968:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826D2974:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d2968
	if (cr6.eq) goto loc_826D2968;
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// bl 0x8238e818
	ctx.lr = 0x826D2984;
	sub_8238E818(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x826d29a8
	if (cr6.eq) goto loc_826D29A8;
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// beq cr6,0x826d29a8
	if (cr6.eq) goto loc_826D29A8;
	// addi r3,r29,456
	ctx.r3.s64 = r29.s64 + 456;
	// bl 0x8238e818
	ctx.lr = 0x826D29A0;
	sub_8238E818(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// bne cr6,0x826d2968
	if (!cr6.eq) goto loc_826D2968;
loc_826D29A8:
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// li r29,1
	r29.s64 = 1;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r29,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r29.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3680
	ctx.r4.s64 = ctx.r10.s64 + -3680;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D29D4;
	sub_8268B770(ctx, base);
	// lwz r9,156(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x826d2968
	if (!cr6.eq) goto loc_826D2968;
	// stb r29,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r29.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r11,-3700
	ctx.r4.s64 = r11.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D29FC;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D2A08"))) PPC_WEAK_FUNC(sub_826D2A08);
PPC_FUNC_IMPL(__imp__sub_826D2A08) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27204
	r31.s64 = r11.s64 + -27204;
	// lwz r11,-27204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2af8
	if (!cr6.eq) goto loc_826D2AF8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D2A34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d2a44
	if (cr6.eq) goto loc_826D2A44;
	// bl 0x821d5408
	ctx.lr = 0x826D2A40;
	sub_821D5408(ctx, base);
	// b 0x826d2a48
	goto loc_826D2A48;
loc_826D2A44:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D2A48:
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// addi r5,r8,2084
	ctx.r5.s64 = ctx.r8.s64 + 2084;
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r4,88
	ctx.r4.s64 = 88;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r7,-24192
	ctx.r9.s64 = ctx.r7.s64 + -24192;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// li r10,52
	ctx.r10.s64 = 52;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D2AA4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826D2AB4;
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
	ctx.lr = 0x826D2AD0;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-24168
	ctx.r4.s64 = ctx.r6.s64 + -24168;
	// bl 0x821d4b00
	ctx.lr = 0x826D2AE0;
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
	ctx.lr = 0x826D2AF8;
	sub_821C0548(ctx, base);
loc_826D2AF8:
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

__attribute__((alias("__imp__sub_826D2B0C"))) PPC_WEAK_FUNC(sub_826D2B0C);
PPC_FUNC_IMPL(__imp__sub_826D2B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2B10"))) PPC_WEAK_FUNC(sub_826D2B10);
PPC_FUNC_IMPL(__imp__sub_826D2B10) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27200
	r31.s64 = r11.s64 + -27200;
	// lwz r11,-27200(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2c4c
	if (!cr6.eq) goto loc_826D2C4C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D2B40;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d2b54
	if (cr6.eq) goto loc_826D2B54;
	// bl 0x821d5408
	ctx.lr = 0x826D2B50;
	sub_821D5408(ctx, base);
	// b 0x826d2b58
	goto loc_826D2B58;
loc_826D2B54:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D2B58:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2096
	ctx.r7.s64 = ctx.r10.s64 + 2096;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,6984
	ctx.r4.s64 = ctx.r8.s64 + 6984;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,-24136
	ctx.r5.s64 = ctx.r10.s64 + -24136;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r8,r3,-24160
	ctx.r8.s64 = ctx.r3.s64 + -24160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,88
	ctx.r10.s64 = 88;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,120
	ctx.r9.s64 = 120;
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826d2be4
	if (!cr6.eq) goto loc_826D2BE4;
	// bl 0x826d2a08
	ctx.lr = 0x826D2BE0;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D2BE4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D2BF0;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D2C08;
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
	ctx.lr = 0x826D2C24;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-24112
	ctx.r4.s64 = ctx.r8.s64 + -24112;
	// bl 0x821d4b00
	ctx.lr = 0x826D2C34;
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
	ctx.lr = 0x826D2C4C;
	sub_821C0548(ctx, base);
loc_826D2C4C:
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

__attribute__((alias("__imp__sub_826D2C64"))) PPC_WEAK_FUNC(sub_826D2C64);
PPC_FUNC_IMPL(__imp__sub_826D2C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2C68"))) PPC_WEAK_FUNC(sub_826D2C68);
PPC_FUNC_IMPL(__imp__sub_826D2C68) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27196
	r31.s64 = r11.s64 + -27196;
	// lwz r11,-27196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2d94
	if (!cr6.eq) goto loc_826D2D94;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D2C98;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d2cac
	if (cr6.eq) goto loc_826D2CAC;
	// bl 0x821d5408
	ctx.lr = 0x826D2CA8;
	sub_821D5408(ctx, base);
	// b 0x826d2cb0
	goto loc_826D2CB0;
loc_826D2CAC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D2CB0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2120
	ctx.r7.s64 = ctx.r10.s64 + 2120;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,120
	ctx.r5.s64 = 120;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,7056
	ctx.r4.s64 = ctx.r8.s64 + 7056;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-24100
	ctx.r9.s64 = ctx.r3.s64 + -24100;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,88
	ctx.r10.s64 = 88;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826d2d2c
	if (!cr6.eq) goto loc_826D2D2C;
	// bl 0x826d2a08
	ctx.lr = 0x826D2D28;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D2D2C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D2D38;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D2D50;
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
	ctx.lr = 0x826D2D6C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-24076
	ctx.r4.s64 = ctx.r8.s64 + -24076;
	// bl 0x821d4b00
	ctx.lr = 0x826D2D7C;
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
	ctx.lr = 0x826D2D94;
	sub_821C0548(ctx, base);
loc_826D2D94:
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

__attribute__((alias("__imp__sub_826D2DAC"))) PPC_WEAK_FUNC(sub_826D2DAC);
PPC_FUNC_IMPL(__imp__sub_826D2DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2DB0"))) PPC_WEAK_FUNC(sub_826D2DB0);
PPC_FUNC_IMPL(__imp__sub_826D2DB0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27192
	r31.s64 = r11.s64 + -27192;
	// lwz r11,-27192(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d2edc
	if (!cr6.eq) goto loc_826D2EDC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D2DE0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d2df4
	if (cr6.eq) goto loc_826D2DF4;
	// bl 0x821d5408
	ctx.lr = 0x826D2DF0;
	sub_821D5408(ctx, base);
	// b 0x826d2df8
	goto loc_826D2DF8;
loc_826D2DF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D2DF8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2140
	ctx.r7.s64 = ctx.r10.s64 + 2140;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,120
	ctx.r5.s64 = 120;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,7184
	ctx.r4.s64 = ctx.r8.s64 + 7184;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-24068
	ctx.r9.s64 = ctx.r3.s64 + -24068;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,88
	ctx.r10.s64 = 88;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826d2e74
	if (!cr6.eq) goto loc_826D2E74;
	// bl 0x826d2a08
	ctx.lr = 0x826D2E70;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D2E74:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D2E80;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D2E98;
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
	ctx.lr = 0x826D2EB4;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-24044
	ctx.r4.s64 = ctx.r8.s64 + -24044;
	// bl 0x821d4b00
	ctx.lr = 0x826D2EC4;
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
	ctx.lr = 0x826D2EDC;
	sub_821C0548(ctx, base);
loc_826D2EDC:
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

__attribute__((alias("__imp__sub_826D2EF4"))) PPC_WEAK_FUNC(sub_826D2EF4);
PPC_FUNC_IMPL(__imp__sub_826D2EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D2EF8"))) PPC_WEAK_FUNC(sub_826D2EF8);
PPC_FUNC_IMPL(__imp__sub_826D2EF8) {
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
	ctx.lr = 0x826D2F00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27188
	r31.s64 = r11.s64 + -27188;
	// lwz r11,-27188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d304c
	if (!cr6.eq) goto loc_826D304C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D2F20;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d2f34
	if (cr6.eq) goto loc_826D2F34;
	// bl 0x821d5408
	ctx.lr = 0x826D2F30;
	sub_821D5408(ctx, base);
	// b 0x826d2f38
	goto loc_826D2F38;
loc_826D2F34:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D2F38:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2160
	ctx.r7.s64 = ctx.r10.s64 + 2160;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,188
	ctx.r5.s64 = 188;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,7312
	ctx.r4.s64 = ctx.r8.s64 + 7312;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r5,r3,-24036
	ctx.r5.s64 = ctx.r3.s64 + -24036;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r10,-24012
	ctx.r3.s64 = ctx.r10.s64 + -24012;
	// addi r29,r9,-23988
	r29.s64 = ctx.r9.s64 + -23988;
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// addi r11,r8,-23964
	r11.s64 = ctx.r8.s64 + -23964;
	// li r10,88
	ctx.r10.s64 = 88;
	// li r9,120
	ctx.r9.s64 = 120;
	// li r8,152
	ctx.r8.s64 = 152;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,184
	ctx.r7.s64 = 184;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// bne cr6,0x826d2fe4
	if (!cr6.eq) goto loc_826D2FE4;
	// bl 0x826d2a08
	ctx.lr = 0x826D2FE0;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D2FE4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D2FF0;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D3008;
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
	ctx.lr = 0x826D3024;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-23940
	ctx.r4.s64 = ctx.r8.s64 + -23940;
	// bl 0x821d4b00
	ctx.lr = 0x826D3034;
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
	ctx.lr = 0x826D304C;
	sub_821C0548(ctx, base);
loc_826D304C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D3054"))) PPC_WEAK_FUNC(sub_826D3054);
PPC_FUNC_IMPL(__imp__sub_826D3054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3058"))) PPC_WEAK_FUNC(sub_826D3058);
PPC_FUNC_IMPL(__imp__sub_826D3058) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27184
	r31.s64 = r11.s64 + -27184;
	// lwz r11,-27184(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d3184
	if (!cr6.eq) goto loc_826D3184;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D3088;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d309c
	if (cr6.eq) goto loc_826D309C;
	// bl 0x821d5408
	ctx.lr = 0x826D3098;
	sub_821D5408(ctx, base);
	// b 0x826d30a0
	goto loc_826D30A0;
loc_826D309C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D30A0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2176
	ctx.r7.s64 = ctx.r10.s64 + 2176;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,7384
	ctx.r4.s64 = ctx.r8.s64 + 7384;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-23920
	ctx.r9.s64 = ctx.r3.s64 + -23920;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,88
	ctx.r10.s64 = 88;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826d311c
	if (!cr6.eq) goto loc_826D311C;
	// bl 0x826d2a08
	ctx.lr = 0x826D3118;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D311C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D3128;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D3140;
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
	ctx.lr = 0x826D315C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-23896
	ctx.r4.s64 = ctx.r8.s64 + -23896;
	// bl 0x821d4b00
	ctx.lr = 0x826D316C;
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
	ctx.lr = 0x826D3184;
	sub_821C0548(ctx, base);
loc_826D3184:
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

__attribute__((alias("__imp__sub_826D319C"))) PPC_WEAK_FUNC(sub_826D319C);
PPC_FUNC_IMPL(__imp__sub_826D319C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D31A0"))) PPC_WEAK_FUNC(sub_826D31A0);
PPC_FUNC_IMPL(__imp__sub_826D31A0) {
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
	ctx.lr = 0x826D31A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27180
	r31.s64 = r11.s64 + -27180;
	// lwz r11,-27180(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d3304
	if (!cr6.eq) goto loc_826D3304;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D31C8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d31dc
	if (cr6.eq) goto loc_826D31DC;
	// bl 0x821d5408
	ctx.lr = 0x826D31D8;
	sub_821D5408(ctx, base);
	// b 0x826d31e0
	goto loc_826D31E0;
loc_826D31DC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D31E0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2196
	ctx.r7.s64 = ctx.r10.s64 + 2196;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,196
	ctx.r5.s64 = 196;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,7456
	ctx.r4.s64 = ctx.r8.s64 + 7456;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r29,r10,-23864
	r29.s64 = ctx.r10.s64 + -23864;
	// addi r6,r9,-23840
	ctx.r6.s64 = ctx.r9.s64 + -23840;
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// addi r28,r8,-23816
	r28.s64 = ctx.r8.s64 + -23816;
	// addi r3,r3,-23888
	ctx.r3.s64 = ctx.r3.s64 + -23888;
	// addi r5,r5,-23792
	ctx.r5.s64 = ctx.r5.s64 + -23792;
	// li r10,88
	ctx.r10.s64 = 88;
	// li r9,92
	ctx.r9.s64 = 92;
	// li r8,124
	ctx.r8.s64 = 124;
	// li r7,156
	ctx.r7.s64 = 156;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r11,160
	r11.s64 = 160;
	// stw r9,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r9.u32);
	// stw r8,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r7,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r7.u32);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// bne cr6,0x826d329c
	if (!cr6.eq) goto loc_826D329C;
	// bl 0x826d2a08
	ctx.lr = 0x826D3298;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D329C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D32A8;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D32C0;
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
	ctx.lr = 0x826D32DC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-23768
	ctx.r4.s64 = ctx.r8.s64 + -23768;
	// bl 0x821d4b00
	ctx.lr = 0x826D32EC;
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
	ctx.lr = 0x826D3304;
	sub_821C0548(ctx, base);
loc_826D3304:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D330C"))) PPC_WEAK_FUNC(sub_826D330C);
PPC_FUNC_IMPL(__imp__sub_826D330C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3310"))) PPC_WEAK_FUNC(sub_826D3310);
PPC_FUNC_IMPL(__imp__sub_826D3310) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27176
	r31.s64 = r11.s64 + -27176;
	// lwz r11,-27176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d345c
	if (!cr6.eq) goto loc_826D345C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D3340;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d3354
	if (cr6.eq) goto loc_826D3354;
	// bl 0x821d5408
	ctx.lr = 0x826D3350;
	sub_821D5408(ctx, base);
	// b 0x826d3358
	goto loc_826D3358;
loc_826D3354:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D3358:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2220
	ctx.r7.s64 = ctx.r10.s64 + 2220;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,160
	ctx.r5.s64 = 160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-23744
	ctx.r7.s64 = ctx.r3.s64 + -23744;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-23720
	ctx.r5.s64 = ctx.r10.s64 + -23720;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-23696
	ctx.r3.s64 = ctx.r9.s64 + -23696;
	// li r10,88
	ctx.r10.s64 = 88;
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r9,120
	ctx.r9.s64 = 120;
	// li r8,124
	ctx.r8.s64 = 124;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x826d33f4
	if (!cr6.eq) goto loc_826D33F4;
	// bl 0x826d2a08
	ctx.lr = 0x826D33F0;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D33F4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D3400;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D3418;
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
	ctx.lr = 0x826D3434;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-23672
	ctx.r4.s64 = ctx.r8.s64 + -23672;
	// bl 0x821d4b00
	ctx.lr = 0x826D3444;
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
	ctx.lr = 0x826D345C;
	sub_821C0548(ctx, base);
loc_826D345C:
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

__attribute__((alias("__imp__sub_826D3474"))) PPC_WEAK_FUNC(sub_826D3474);
PPC_FUNC_IMPL(__imp__sub_826D3474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3478"))) PPC_WEAK_FUNC(sub_826D3478);
PPC_FUNC_IMPL(__imp__sub_826D3478) {
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
	ctx.lr = 0x826D3480;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27172
	r31.s64 = r11.s64 + -27172;
	// lwz r11,-27172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d35cc
	if (!cr6.eq) goto loc_826D35CC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D34A0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d34b4
	if (cr6.eq) goto loc_826D34B4;
	// bl 0x821d5408
	ctx.lr = 0x826D34B0;
	sub_821D5408(ctx, base);
	// b 0x826d34b8
	goto loc_826D34B8;
loc_826D34B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D34B8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32232
	r11.s64 = -2112356352;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2244
	ctx.r7.s64 = ctx.r10.s64 + 2244;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,10272
	ctx.r9.s64 = r11.s64 + 10272;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,168
	ctx.r5.s64 = 168;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,7600
	ctx.r4.s64 = ctx.r8.s64 + 7600;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r5,r3,-23656
	ctx.r5.s64 = ctx.r3.s64 + -23656;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r10,-23632
	ctx.r3.s64 = ctx.r10.s64 + -23632;
	// addi r29,r9,-23608
	r29.s64 = ctx.r9.s64 + -23608;
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// addi r11,r8,-23584
	r11.s64 = ctx.r8.s64 + -23584;
	// li r10,88
	ctx.r10.s64 = 88;
	// li r9,120
	ctx.r9.s64 = 120;
	// li r8,152
	ctx.r8.s64 = 152;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,156
	ctx.r7.s64 = 156;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// bne cr6,0x826d3564
	if (!cr6.eq) goto loc_826D3564;
	// bl 0x826d2a08
	ctx.lr = 0x826D3560;
	sub_826D2A08(ctx, base);
	// lwz r4,-27204(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27204);
loc_826D3564:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D3570;
	sub_821D4458(ctx, base);
	// lwz r11,-27204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27204);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D3588;
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
	ctx.lr = 0x826D35A4;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-23560
	ctx.r4.s64 = ctx.r8.s64 + -23560;
	// bl 0x821d4b00
	ctx.lr = 0x826D35B4;
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
	ctx.lr = 0x826D35CC;
	sub_821C0548(ctx, base);
loc_826D35CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D35D4"))) PPC_WEAK_FUNC(sub_826D35D4);
PPC_FUNC_IMPL(__imp__sub_826D35D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D35D8"))) PPC_WEAK_FUNC(sub_826D35D8);
PPC_FUNC_IMPL(__imp__sub_826D35D8) {
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
	ctx.lr = 0x826D35E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82387a98
	ctx.lr = 0x826D35F0;
	sub_82387A98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d3724
	if (!cr6.eq) goto loc_826D3724;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d3724
	if (cr6.eq) goto loc_826D3724;
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// bl 0x8238e748
	ctx.lr = 0x826D360C;
	sub_8238E748(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826d3628
	if (cr6.eq) goto loc_826D3628;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d3628
	if (cr6.eq) goto loc_826D3628;
	// lwz r11,3092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3092);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bne cr6,0x826d3724
	if (!cr6.eq) goto loc_826D3724;
loc_826D3628:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r30,-1
	r30.s64 = -1;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826d3664
	if (cr6.eq) goto loc_826D3664;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826D3644;
	sub_8238EC00(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,44(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r30,8(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x826d368c
	goto loc_826D368C;
loc_826D3664:
	// lwz r11,3096(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3096);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bne cr6,0x826d368c
	if (!cr6.eq) goto loc_826D368C;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,2260
	ctx.r4.s64 = ctx.r10.s64 + 2260;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x826D3684;
	sub_8220EEA8(ctx, base);
	// bl 0x822031a8
	ctx.lr = 0x826D3688;
	sub_822031A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_826D368C:
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// bl 0x8238e818
	ctx.lr = 0x826D3694;
	sub_8238E818(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826d36ac
	if (cr6.eq) goto loc_826D36AC;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// beq cr6,0x826d36ac
	if (cr6.eq) goto loc_826D36AC;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x826d3724
	if (!cr6.eq) goto loc_826D3724;
loc_826D36AC:
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d36c4
	if (cr6.eq) goto loc_826D36C4;
	// lwz r10,172(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 172);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x826d3724
	if (cr6.gt) goto loc_826D3724;
loc_826D36C4:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r29,1
	r29.s64 = 1;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r29,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r29.u8);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-3680
	ctx.r4.s64 = ctx.r10.s64 + -3680;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826D36F0;
	sub_8268B770(ctx, base);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r8,88(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x826d3724
	if (!cr6.eq) goto loc_826D3724;
	// stb r29,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r29.u8);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r11,-3700
	ctx.r4.s64 = r11.s64 + -3700;
	// bl 0x8268b770
	ctx.lr = 0x826D3718;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D3724:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D3730"))) PPC_WEAK_FUNC(sub_826D3730);
PPC_FUNC_IMPL(__imp__sub_826D3730) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,-21868
	ctx.r9.s64 = r11.s64 + -21868;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r4,r10,2760
	ctx.r4.s64 = ctx.r10.s64 + 2760;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x823db670
	ctx.lr = 0x826D3764;
	sub_823DB670(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,2748
	ctx.r7.s64 = ctx.r8.s64 + 2748;
	// li r6,10
	ctx.r6.s64 = 10;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// stw r6,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r6.u32);
	// stb r11,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r11.u8);
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
	// stb r11,104(r31)
	PPC_STORE_U8(r31.u32 + 104, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D37A8"))) PPC_WEAK_FUNC(sub_826D37A8);
PPC_FUNC_IMPL(__imp__sub_826D37A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27168(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27168);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D37B4"))) PPC_WEAK_FUNC(sub_826D37B4);
PPC_FUNC_IMPL(__imp__sub_826D37B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D37B8"))) PPC_WEAK_FUNC(sub_826D37B8);
PPC_FUNC_IMPL(__imp__sub_826D37B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27156);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D37C4"))) PPC_WEAK_FUNC(sub_826D37C4);
PPC_FUNC_IMPL(__imp__sub_826D37C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D37C8"))) PPC_WEAK_FUNC(sub_826D37C8);
PPC_FUNC_IMPL(__imp__sub_826D37C8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,2780
	ctx.r9.s64 = r11.s64 + 2780;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826d37fc
	if (cr6.eq) goto loc_826D37FC;
	// bl 0x82130588
	ctx.lr = 0x826D37F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D37FC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D3810"))) PPC_WEAK_FUNC(sub_826D3810);
PPC_FUNC_IMPL(__imp__sub_826D3810) {
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
	ctx.lr = 0x826D3824;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d3850
	if (cr6.eq) goto loc_826D3850;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,2780
	ctx.r9.s64 = ctx.r10.s64 + 2780;
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D3850:
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

__attribute__((alias("__imp__sub_826D3864"))) PPC_WEAK_FUNC(sub_826D3864);
PPC_FUNC_IMPL(__imp__sub_826D3864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3868"))) PPC_WEAK_FUNC(sub_826D3868);
PPC_FUNC_IMPL(__imp__sub_826D3868) {
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
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d38a8
	if (!cr6.eq) goto loc_826D38A8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,140(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r10,-2640
	ctx.r5.s64 = ctx.r10.s64 + -2640;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x826D38A4;
	sub_8268B960(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
loc_826D38A8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D38BC"))) PPC_WEAK_FUNC(sub_826D38BC);
PPC_FUNC_IMPL(__imp__sub_826D38BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D38C0"))) PPC_WEAK_FUNC(sub_826D38C0);
PPC_FUNC_IMPL(__imp__sub_826D38C0) {
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
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d38f8
	if (cr6.eq) goto loc_826D38F8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826D38F0;
	sub_8268B6D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
loc_826D38F8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D390C"))) PPC_WEAK_FUNC(sub_826D390C);
PPC_FUNC_IMPL(__imp__sub_826D390C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3910"))) PPC_WEAK_FUNC(sub_826D3910);
PPC_FUNC_IMPL(__imp__sub_826D3910) {
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
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x826d3ab8
	if (!cr6.eq) goto loc_826D3AB8;
	// lhz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d3ab8
	if (cr6.eq) goto loc_826D3AB8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d3ab8
	if (cr6.eq) goto loc_826D3AB8;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x823dd800
	ctx.lr = 0x826D3958;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d3978
	if (cr6.eq) goto loc_826D3978;
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
loc_826D3978:
	// addic. r11,r31,148
	xer.ca = r31.u32 > 4294967147;
	r11.s64 = r31.s64 + 148;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// beq 0x826d3a7c
	if (cr0.eq) goto loc_826D3A7C;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r7,r9,-22820
	ctx.r7.s64 = ctx.r9.s64 + -22820;
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
loc_826D3994:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r5,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r5.s64;
	// beq cr6,0x826d39b8
	if (cr6.eq) goto loc_826D39B8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x826d3994
	if (cr6.eq) goto loc_826D3994;
loc_826D39B8:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x826d3a1c
	if (!cr6.eq) goto loc_826D3A1C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lhz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// ori r7,r8,64167
	ctx.r7.u64 = ctx.r8.u64 | 64167;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// addis r6,r11,1
	ctx.r6.s64 = r11.s64 + 65536;
	// addi r6,r6,27768
	ctx.r6.s64 = ctx.r6.s64 + 27768;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r5,r7
	ctx.r10.s64 = ctx.r5.s64 * ctx.r7.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r4,r11,1
	ctx.r4.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// rldicl r5,r11,32,32
	ctx.r5.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// divw r8,r4,r9
	ctx.r8.s32 = ctx.r4.s32 / ctx.r9.s32;
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r11,r8,r9
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// andc r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// subf r6,r11,r4
	ctx.r6.s64 = ctx.r4.s64 - r11.s64;
	// twlgei r3,-1
	// b 0x826d3a78
	goto loc_826D3A78;
loc_826D3A1C:
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
loc_826D3A20:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826d3a44
	if (cr6.eq) goto loc_826D3A44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826d3a20
	if (cr6.eq) goto loc_826D3A20;
loc_826D3A44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826d3a7c
	if (!cr6.eq) goto loc_826D3A7C;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lhz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r7,r11,r9
	ctx.r7.s32 = r11.s32 / ctx.r9.s32;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// mullw r5,r7,r9
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// andc r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// twlgei r6,-1
	// subf r6,r5,r11
	ctx.r6.s64 = r11.s64 - ctx.r5.s64;
	// stw r4,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r4.u32);
loc_826D3A78:
	// twllei r9,0
loc_826D3A7C:
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// beq cr6,0x826d3aa0
	if (cr6.eq) goto loc_826D3AA0;
	// li r4,1500
	ctx.r4.s64 = 1500;
	// bl 0x826bd870
	ctx.lr = 0x826D3A9C;
	sub_826BD870(ctx, base);
	// b 0x826d3ab8
	goto loc_826D3AB8;
loc_826D3AA0:
	// li r8,1500
	ctx.r8.s64 = 1500;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x826D3AB8;
	sub_82727908(ctx, base);
loc_826D3AB8:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
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

__attribute__((alias("__imp__sub_826D3ADC"))) PPC_WEAK_FUNC(sub_826D3ADC);
PPC_FUNC_IMPL(__imp__sub_826D3ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3AE0"))) PPC_WEAK_FUNC(sub_826D3AE0);
PPC_FUNC_IMPL(__imp__sub_826D3AE0) {
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
	ctx.lr = 0x826D3AE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x826d3b80
	if (!cr6.eq) goto loc_826D3B80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d3b80
	if (cr6.eq) goto loc_826D3B80;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x823dd800
	ctx.lr = 0x826D3B18;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d3b2c
	if (cr6.eq) goto loc_826D3B2C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826D3B2C:
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// bl 0x826cd4b8
	ctx.lr = 0x826D3B34;
	sub_826CD4B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x826d3b80
	if (cr6.eq) goto loc_826D3B80;
	// cmpwi cr6,r30,6
	cr6.compare<int32_t>(r30.s32, 6, xer);
	// beq cr6,0x826d3b80
	if (cr6.eq) goto loc_826D3B80;
	// lbz r11,181(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 181);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d3b5c
	if (cr6.eq) goto loc_826D3B5C;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x826c6f40
	ctx.lr = 0x826D3B5C;
	sub_826C6F40(ctx, base);
loc_826D3B5C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r29,180(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 180);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826D3B70;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x826c67f8
	ctx.lr = 0x826D3B80;
	sub_826C67F8(ctx, base);
loc_826D3B80:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D3B98"))) PPC_WEAK_FUNC(sub_826D3B98);
PPC_FUNC_IMPL(__imp__sub_826D3B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27160(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27160);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D3BA4"))) PPC_WEAK_FUNC(sub_826D3BA4);
PPC_FUNC_IMPL(__imp__sub_826D3BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3BA8"))) PPC_WEAK_FUNC(sub_826D3BA8);
PPC_FUNC_IMPL(__imp__sub_826D3BA8) {
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
	// li r3,184
	ctx.r3.s64 = 184;
	// bl 0x82130528
	ctx.lr = 0x826D3BC0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d3c00
	if (cr6.eq) goto loc_826D3C00;
	// bl 0x826d3730
	ctx.lr = 0x826D3BD0;
	sub_826D3730(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,2792
	ctx.r9.s64 = ctx.r10.s64 + 2792;
	// stb r11,180(r31)
	PPC_STORE_U8(r31.u32 + 180, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,148(r31)
	PPC_STORE_U8(r31.u32 + 148, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826D3C00:
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

__attribute__((alias("__imp__sub_826D3C18"))) PPC_WEAK_FUNC(sub_826D3C18);
PPC_FUNC_IMPL(__imp__sub_826D3C18) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27156
	r31.s64 = r11.s64 + -27156;
	// lwz r11,-27156(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d3d28
	if (!cr6.eq) goto loc_826D3D28;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D3C48;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d3c5c
	if (cr6.eq) goto loc_826D3C5C;
	// bl 0x821d5408
	ctx.lr = 0x826D3C58;
	sub_821D5408(ctx, base);
	// b 0x826d3c60
	goto loc_826D3C60;
loc_826D3C5C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D3C60:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2804
	ctx.r7.s64 = ctx.r10.s64 + 2804;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,68
	ctx.r5.s64 = 68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,14352
	ctx.r4.s64 = ctx.r8.s64 + 14352;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,-22852
	ctx.r9.s64 = ctx.r3.s64 + -22852;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r10,4
	ctx.r10.s64 = 4;
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
	ctx.lr = 0x826D3CD4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826D3CE4;
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
	ctx.lr = 0x826D3D00;
	sub_821D41D0(ctx, base);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,-22828
	ctx.r4.s64 = ctx.r5.s64 + -22828;
	// bl 0x821d4b00
	ctx.lr = 0x826D3D10;
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
	ctx.lr = 0x826D3D28;
	sub_821C0548(ctx, base);
loc_826D3D28:
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

__attribute__((alias("__imp__sub_826D3D40"))) PPC_WEAK_FUNC(sub_826D3D40);
PPC_FUNC_IMPL(__imp__sub_826D3D40) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,2748
	ctx.r10.s64 = r11.s64 + 2748;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d3d8c
	if (cr6.eq) goto loc_826D3D8C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826D3D84;
	sub_8268B6D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
loc_826D3D8C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,-21868
	ctx.r9.s64 = r11.s64 + -21868;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x826d3db0
	if (cr6.eq) goto loc_826D3DB0;
	// bl 0x82130588
	ctx.lr = 0x826D3DAC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D3DB0:
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

__attribute__((alias("__imp__sub_826D3DC8"))) PPC_WEAK_FUNC(sub_826D3DC8);
PPC_FUNC_IMPL(__imp__sub_826D3DC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27164(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27164);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D3DD4"))) PPC_WEAK_FUNC(sub_826D3DD4);
PPC_FUNC_IMPL(__imp__sub_826D3DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3DD8"))) PPC_WEAK_FUNC(sub_826D3DD8);
PPC_FUNC_IMPL(__imp__sub_826D3DD8) {
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
	ctx.lr = 0x826D3DE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r11,2828
	ctx.r9.s64 = r11.s64 + 2828;
	// lhz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d3e28
	if (cr6.eq) goto loc_826D3E28;
	// li r30,0
	r30.s64 = 0;
loc_826D3E08:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82130588
	ctx.lr = 0x826D3E14;
	sub_82130588(ctx, base);
	// lhz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826d3e08
	if (cr6.lt) goto loc_826D3E08;
loc_826D3E28:
	// lhz r11,190(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 190);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d3e3c
	if (cr6.eq) goto loc_826D3E3C;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// bl 0x82130588
	ctx.lr = 0x826D3E3C;
	sub_82130588(ctx, base);
loc_826D3E3C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r10,r11,2748
	ctx.r10.s64 = r11.s64 + 2748;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x826d3e6c
	if (cr6.eq) goto loc_826D3E6C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826D3E64;
	sub_8268B6D0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
loc_826D3E6C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D3E80"))) PPC_WEAK_FUNC(sub_826D3E80);
PPC_FUNC_IMPL(__imp__sub_826D3E80) {
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
	// li r3,196
	ctx.r3.s64 = 196;
	// bl 0x82130528
	ctx.lr = 0x826D3E98;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d3eec
	if (cr6.eq) goto loc_826D3EEC;
	// bl 0x826d3730
	ctx.lr = 0x826D3EA8;
	sub_826D3730(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,2828
	ctx.r9.s64 = ctx.r10.s64 + 2828;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// sth r11,188(r31)
	PPC_STORE_U16(r31.u32 + 188, r11.u16);
	// sth r11,190(r31)
	PPC_STORE_U16(r31.u32 + 190, r11.u16);
	// stb r8,192(r31)
	PPC_STORE_U8(r31.u32 + 192, ctx.r8.u8);
	// stb r11,148(r31)
	PPC_STORE_U8(r31.u32 + 148, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826D3EEC:
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

__attribute__((alias("__imp__sub_826D3F04"))) PPC_WEAK_FUNC(sub_826D3F04);
PPC_FUNC_IMPL(__imp__sub_826D3F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D3F08"))) PPC_WEAK_FUNC(sub_826D3F08);
PPC_FUNC_IMPL(__imp__sub_826D3F08) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27168
	r31.s64 = r11.s64 + -27168;
	// lwz r11,-27168(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d4028
	if (!cr6.eq) goto loc_826D4028;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D3F34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d3f44
	if (cr6.eq) goto loc_826D3F44;
	// bl 0x821d5408
	ctx.lr = 0x826D3F40;
	sub_821D5408(ctx, base);
	// b 0x826d3f48
	goto loc_826D3F48;
loc_826D3F44:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D3F48:
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// addi r5,r8,2840
	ctx.r5.s64 = ctx.r8.s64 + 2840;
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r7,148
	ctx.r7.s64 = 148;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r7,r4,-23144
	ctx.r7.s64 = ctx.r4.s64 + -23144;
	// addi r5,r10,-23120
	ctx.r5.s64 = ctx.r10.s64 + -23120;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r9,-23096
	ctx.r4.s64 = ctx.r9.s64 + -23096;
	// addi r6,r8,-23072
	ctx.r6.s64 = ctx.r8.s64 + -23072;
	// li r10,40
	ctx.r10.s64 = 40;
	// li r9,104
	ctx.r9.s64 = 104;
	// li r8,140
	ctx.r8.s64 = 140;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r11,144
	r11.s64 = 144;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x826D3FD4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826D3FE4;
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
	ctx.lr = 0x826D4000;
	sub_821D41D0(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-23048
	ctx.r4.s64 = ctx.r10.s64 + -23048;
	// bl 0x821d4b00
	ctx.lr = 0x826D4010;
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
	ctx.lr = 0x826D4028;
	sub_821C0548(ctx, base);
loc_826D4028:
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

__attribute__((alias("__imp__sub_826D403C"))) PPC_WEAK_FUNC(sub_826D403C);
PPC_FUNC_IMPL(__imp__sub_826D403C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4040"))) PPC_WEAK_FUNC(sub_826D4040);
PPC_FUNC_IMPL(__imp__sub_826D4040) {
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
	// bl 0x826d3dd8
	ctx.lr = 0x826D4060;
	sub_826D3DD8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4078
	if (cr6.eq) goto loc_826D4078;
	// bl 0x82130588
	ctx.lr = 0x826D4074;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4078:
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

__attribute__((alias("__imp__sub_826D4090"))) PPC_WEAK_FUNC(sub_826D4090);
PPC_FUNC_IMPL(__imp__sub_826D4090) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27164
	r31.s64 = r11.s64 + -27164;
	// lwz r11,-27164(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d41dc
	if (!cr6.eq) goto loc_826D41DC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D40C0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d40d4
	if (cr6.eq) goto loc_826D40D4;
	// bl 0x821d5408
	ctx.lr = 0x826D40D0;
	sub_821D5408(ctx, base);
	// b 0x826d40d8
	goto loc_826D40D8;
loc_826D40D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D40D8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2856
	ctx.r7.s64 = ctx.r10.s64 + 2856;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,196
	ctx.r5.s64 = 196;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,16000
	ctx.r4.s64 = ctx.r8.s64 + 16000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-23028
	ctx.r7.s64 = ctx.r3.s64 + -23028;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-23004
	ctx.r5.s64 = ctx.r10.s64 + -23004;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-22808
	ctx.r3.s64 = ctx.r9.s64 + -22808;
	// li r10,148
	ctx.r10.s64 = 148;
	// lwz r4,-27168(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27168);
	// li r9,192
	ctx.r9.s64 = 192;
	// li r8,184
	ctx.r8.s64 = 184;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x826d4174
	if (!cr6.eq) goto loc_826D4174;
	// bl 0x826d3f08
	ctx.lr = 0x826D4170;
	sub_826D3F08(ctx, base);
	// lwz r4,-27168(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27168);
loc_826D4174:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D4180;
	sub_821D4458(ctx, base);
	// lwz r11,-27168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27168);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D4198;
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
	ctx.lr = 0x826D41B4;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-22956
	ctx.r4.s64 = ctx.r8.s64 + -22956;
	// bl 0x821d4b00
	ctx.lr = 0x826D41C4;
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
	ctx.lr = 0x826D41DC;
	sub_821C0548(ctx, base);
loc_826D41DC:
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

__attribute__((alias("__imp__sub_826D41F4"))) PPC_WEAK_FUNC(sub_826D41F4);
PPC_FUNC_IMPL(__imp__sub_826D41F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D41F8"))) PPC_WEAK_FUNC(sub_826D41F8);
PPC_FUNC_IMPL(__imp__sub_826D41F8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-27160
	r31.s64 = r11.s64 + -27160;
	// lwz r11,-27160(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d4344
	if (!cr6.eq) goto loc_826D4344;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826D4228;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d423c
	if (cr6.eq) goto loc_826D423C;
	// bl 0x821d5408
	ctx.lr = 0x826D4238;
	sub_821D5408(ctx, base);
	// b 0x826d4240
	goto loc_826D4240;
loc_826D423C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826D4240:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,2880
	ctx.r7.s64 = ctx.r10.s64 + 2880;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,184
	ctx.r5.s64 = 184;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32147
	ctx.r8.s64 = -2106785792;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,15272
	ctx.r4.s64 = ctx.r8.s64 + 15272;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-22940
	ctx.r7.s64 = ctx.r3.s64 + -22940;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-22916
	ctx.r5.s64 = ctx.r10.s64 + -22916;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-22892
	ctx.r3.s64 = ctx.r9.s64 + -22892;
	// li r10,148
	ctx.r10.s64 = 148;
	// lwz r4,-27168(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27168);
	// li r9,180
	ctx.r9.s64 = 180;
	// li r8,181
	ctx.r8.s64 = 181;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x826d42dc
	if (!cr6.eq) goto loc_826D42DC;
	// bl 0x826d3f08
	ctx.lr = 0x826D42D8;
	sub_826D3F08(ctx, base);
	// lwz r4,-27168(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27168);
loc_826D42DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x826D42E8;
	sub_821D4458(ctx, base);
	// lwz r11,-27168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27168);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x826D4300;
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
	ctx.lr = 0x826D431C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-22868
	ctx.r4.s64 = ctx.r8.s64 + -22868;
	// bl 0x821d4b00
	ctx.lr = 0x826D432C;
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
	ctx.lr = 0x826D4344;
	sub_821C0548(ctx, base);
loc_826D4344:
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

__attribute__((alias("__imp__sub_826D435C"))) PPC_WEAK_FUNC(sub_826D435C);
PPC_FUNC_IMPL(__imp__sub_826D435C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4360"))) PPC_WEAK_FUNC(sub_826D4360);
PPC_FUNC_IMPL(__imp__sub_826D4360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,3228
	ctx.r9.s64 = r11.s64 + 3228;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stb r7,80(r3)
	PPC_STORE_U8(ctx.r3.u32 + 80, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4388"))) PPC_WEAK_FUNC(sub_826D4388);
PPC_FUNC_IMPL(__imp__sub_826D4388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,3228
	ctx.r10.s64 = r11.s64 + 3228;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4398"))) PPC_WEAK_FUNC(sub_826D4398);
PPC_FUNC_IMPL(__imp__sub_826D4398) {
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
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// bl 0x823db670
	ctx.lr = 0x826D43C4;
	sub_823DB670(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// lbz r8,80(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 80);
	// stb r8,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_826D4400"))) PPC_WEAK_FUNC(sub_826D4400);
PPC_FUNC_IMPL(__imp__sub_826D4400) {
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
	// li r11,-1
	r11.s64 = -1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d4434
	if (cr6.eq) goto loc_826D4434;
	// bl 0x826d0328
	ctx.lr = 0x826D442C;
	sub_826D0328(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_826D4434:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D4448"))) PPC_WEAK_FUNC(sub_826D4448);
PPC_FUNC_IMPL(__imp__sub_826D4448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lbz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// stbx r10,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r10.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4464"))) PPC_WEAK_FUNC(sub_826D4464);
PPC_FUNC_IMPL(__imp__sub_826D4464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4468"))) PPC_WEAK_FUNC(sub_826D4468);
PPC_FUNC_IMPL(__imp__sub_826D4468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lbzx r10,r11,r4
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r4.u32);
	// stb r10,80(r3)
	PPC_STORE_U8(ctx.r3.u32 + 80, ctx.r10.u8);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4484"))) PPC_WEAK_FUNC(sub_826D4484);
PPC_FUNC_IMPL(__imp__sub_826D4484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4488"))) PPC_WEAK_FUNC(sub_826D4488);
PPC_FUNC_IMPL(__imp__sub_826D4488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x826d04c0
	sub_826D04C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D44A4"))) PPC_WEAK_FUNC(sub_826D44A4);
PPC_FUNC_IMPL(__imp__sub_826D44A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D44A8"))) PPC_WEAK_FUNC(sub_826D44A8);
PPC_FUNC_IMPL(__imp__sub_826D44A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stb r4,80(r3)
	PPC_STORE_U8(ctx.r3.u32 + 80, ctx.r4.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r4,196(r11)
	PPC_STORE_U8(r11.u32 + 196, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D44C0"))) PPC_WEAK_FUNC(sub_826D44C0);
PPC_FUNC_IMPL(__imp__sub_826D44C0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,3228
	ctx.r10.s64 = r11.s64 + 3228;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826D44EC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d4504
	if (cr6.eq) goto loc_826D4504;
	// bl 0x82130588
	ctx.lr = 0x826D4500;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4504:
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

__attribute__((alias("__imp__sub_826D451C"))) PPC_WEAK_FUNC(sub_826D451C);
PPC_FUNC_IMPL(__imp__sub_826D451C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4520"))) PPC_WEAK_FUNC(sub_826D4520);
PPC_FUNC_IMPL(__imp__sub_826D4520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4530"))) PPC_WEAK_FUNC(sub_826D4530);
PPC_FUNC_IMPL(__imp__sub_826D4530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4540"))) PPC_WEAK_FUNC(sub_826D4540);
PPC_FUNC_IMPL(__imp__sub_826D4540) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,3816
	ctx.r9.s64 = r11.s64 + 3816;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826d4574
	if (cr6.eq) goto loc_826D4574;
	// bl 0x82130588
	ctx.lr = 0x826D4570;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4574:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D4588"))) PPC_WEAK_FUNC(sub_826D4588);
PPC_FUNC_IMPL(__imp__sub_826D4588) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r10,r11,3832
	ctx.r10.s64 = r11.s64 + 3832;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82761428
	ctx.lr = 0x826D45B8;
	sub_82761428(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,3816
	ctx.r7.s64 = ctx.r9.s64 + 3816;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x826d45dc
	if (cr6.eq) goto loc_826D45DC;
	// bl 0x82130588
	ctx.lr = 0x826D45D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D45DC:
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

__attribute__((alias("__imp__sub_826D45F4"))) PPC_WEAK_FUNC(sub_826D45F4);
PPC_FUNC_IMPL(__imp__sub_826D45F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D45F8"))) PPC_WEAK_FUNC(sub_826D45F8);
PPC_FUNC_IMPL(__imp__sub_826D45F8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// addi r10,r11,3848
	ctx.r10.s64 = r11.s64 + 3848;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8254ab20
	ctx.lr = 0x826D4628;
	sub_8254AB20(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r8,r9,-30128
	ctx.r8.s64 = ctx.r9.s64 + -30128;
	// stw r8,240(r31)
	PPC_STORE_U32(r31.u32 + 240, ctx.r8.u32);
	// bl 0x827613a8
	ctx.lr = 0x826D463C;
	sub_827613A8(ctx, base);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// clrlwi r6,r30,31
	ctx.r6.u64 = r30.u32 & 0x1;
	// addi r5,r7,3816
	ctx.r5.s64 = ctx.r7.s64 + 3816;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x826d4660
	if (cr6.eq) goto loc_826D4660;
	// bl 0x82130588
	ctx.lr = 0x826D465C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4660:
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

__attribute__((alias("__imp__sub_826D4678"))) PPC_WEAK_FUNC(sub_826D4678);
PPC_FUNC_IMPL(__imp__sub_826D4678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d4698
	if (cr6.eq) goto loc_826D4698;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d46ec
	if (!cr6.eq) goto loc_826D46EC;
loc_826D4698:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d46b4
	if (cr6.eq) goto loc_826D46B4;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d46ec
	if (!cr6.eq) goto loc_826D46EC;
loc_826D46B4:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d46d0
	if (cr6.eq) goto loc_826D46D0;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d46ec
	if (!cr6.eq) goto loc_826D46EC;
loc_826D46D0:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d46f8
	if (cr6.eq) goto loc_826D46F8;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d46f8
	if (cr6.eq) goto loc_826D46F8;
loc_826D46EC:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_826D46F8:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4704"))) PPC_WEAK_FUNC(sub_826D4704);
PPC_FUNC_IMPL(__imp__sub_826D4704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4708"))) PPC_WEAK_FUNC(sub_826D4708);
PPC_FUNC_IMPL(__imp__sub_826D4708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stb r10,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D472C"))) PPC_WEAK_FUNC(sub_826D472C);
PPC_FUNC_IMPL(__imp__sub_826D472C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4730"))) PPC_WEAK_FUNC(sub_826D4730);
PPC_FUNC_IMPL(__imp__sub_826D4730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D473C"))) PPC_WEAK_FUNC(sub_826D473C);
PPC_FUNC_IMPL(__imp__sub_826D473C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4740"))) PPC_WEAK_FUNC(sub_826D4740);
PPC_FUNC_IMPL(__imp__sub_826D4740) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,3892
	ctx.r9.s64 = r11.s64 + 3892;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826d4774
	if (cr6.eq) goto loc_826D4774;
	// bl 0x82130588
	ctx.lr = 0x826D4770;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4774:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D4788"))) PPC_WEAK_FUNC(sub_826D4788);
PPC_FUNC_IMPL(__imp__sub_826D4788) {
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
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r11,r31,3664
	r11.s64 = r31.s64 + 3664;
	// addi r9,r10,3916
	ctx.r9.s64 = ctx.r10.s64 + 3916;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r9,r9,3864
	ctx.r9.s64 = ctx.r9.s64 + 3864;
loc_826D47B8:
	// addi r11,r11,-1216
	r11.s64 = r11.s64 + -1216;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x826d47b8
	if (!cr0.lt) goto loc_826D47B8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,3892
	ctx.r9.s64 = r11.s64 + 3892;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x826d47ec
	if (cr6.eq) goto loc_826D47EC;
	// bl 0x82130588
	ctx.lr = 0x826D47E8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D47EC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D4800"))) PPC_WEAK_FUNC(sub_826D4800);
PPC_FUNC_IMPL(__imp__sub_826D4800) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,3944
	ctx.r9.s64 = r11.s64 + 3944;
	// addi r8,r10,3848
	ctx.r8.s64 = ctx.r10.s64 + 3848;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r30,r31,96
	r30.s64 = r31.s64 + 96;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// addi r3,r30,272
	ctx.r3.s64 = r30.s64 + 272;
	// bl 0x8254ab20
	ctx.lr = 0x826D483C;
	sub_8254AB20(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// addi r6,r7,-30128
	ctx.r6.s64 = ctx.r7.s64 + -30128;
	// stw r6,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r6.u32);
	// bl 0x827613a8
	ctx.lr = 0x826D4850;
	sub_827613A8(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// addi r3,r5,3816
	ctx.r3.s64 = ctx.r5.s64 + 3816;
	// addi r11,r4,3892
	r11.s64 = ctx.r4.s64 + 3892;
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_826D4880"))) PPC_WEAK_FUNC(sub_826D4880);
PPC_FUNC_IMPL(__imp__sub_826D4880) {
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
	// bl 0x826d4800
	ctx.lr = 0x826D48A0;
	sub_826D4800(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d48b8
	if (cr6.eq) goto loc_826D48B8;
	// bl 0x82130588
	ctx.lr = 0x826D48B4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D48B8:
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

__attribute__((alias("__imp__sub_826D48D0"))) PPC_WEAK_FUNC(sub_826D48D0);
PPC_FUNC_IMPL(__imp__sub_826D48D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24732(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24732);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D48DC"))) PPC_WEAK_FUNC(sub_826D48DC);
PPC_FUNC_IMPL(__imp__sub_826D48DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D48E0"))) PPC_WEAK_FUNC(sub_826D48E0);
PPC_FUNC_IMPL(__imp__sub_826D48E0) {
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
	// li r3,3616
	ctx.r3.s64 = 3616;
	// bl 0x82130528
	ctx.lr = 0x826D48F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d4910
	if (cr6.eq) goto loc_826D4910;
	// bl 0x826e8d80
	ctx.lr = 0x826D4900;
	sub_826E8D80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D4910:
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

__attribute__((alias("__imp__sub_826D4924"))) PPC_WEAK_FUNC(sub_826D4924);
PPC_FUNC_IMPL(__imp__sub_826D4924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4928"))) PPC_WEAK_FUNC(sub_826D4928);
PPC_FUNC_IMPL(__imp__sub_826D4928) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// addi r10,r11,3972
	ctx.r10.s64 = r11.s64 + 3972;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826D4958;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826e4238
	ctx.lr = 0x826D4960;
	sub_826E4238(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d4978
	if (cr6.eq) goto loc_826D4978;
	// bl 0x82130588
	ctx.lr = 0x826D4974;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4978:
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

__attribute__((alias("__imp__sub_826D4990"))) PPC_WEAK_FUNC(sub_826D4990);
PPC_FUNC_IMPL(__imp__sub_826D4990) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r31,r3,96
	r31.s64 = ctx.r3.s64 + 96;
	// li r30,1
	r30.s64 = 1;
loc_826D49AC:
	// addi r31,r31,-48
	r31.s64 = r31.s64 + -48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826db8b8
	ctx.lr = 0x826D49B8;
	sub_826DB8B8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826d49ac
	if (!cr0.lt) goto loc_826D49AC;
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

__attribute__((alias("__imp__sub_826D49D8"))) PPC_WEAK_FUNC(sub_826D49D8);
PPC_FUNC_IMPL(__imp__sub_826D49D8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,4132
	ctx.r9.s64 = r11.s64 + 4132;
	// addi r7,r10,3916
	ctx.r7.s64 = ctx.r10.s64 + 3916;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r8,r31,944
	ctx.r8.s64 = r31.s64 + 944;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r7,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r7.u32);
	// addi r11,r8,3664
	r11.s64 = ctx.r8.s64 + 3664;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r9,3864
	ctx.r9.s64 = ctx.r9.s64 + 3864;
loc_826D4A18:
	// addi r11,r11,-1216
	r11.s64 = r11.s64 + -1216;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x826d4a18
	if (!cr0.lt) goto loc_826D4A18;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r31,512
	ctx.r3.s64 = r31.s64 + 512;
	// addi r10,r11,3892
	ctx.r10.s64 = r11.s64 + 3892;
	// stw r10,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// bl 0x826d4800
	ctx.lr = 0x826D4A3C;
	sub_826D4800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826e9da8
	ctx.lr = 0x826D4A44;
	sub_826E9DA8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D4A58"))) PPC_WEAK_FUNC(sub_826D4A58);
PPC_FUNC_IMPL(__imp__sub_826D4A58) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826D4A70;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d4ab0
	if (cr6.eq) goto loc_826D4AB0;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82740f18
	ctx.lr = 0x826D4A84;
	sub_82740F18(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,4260
	ctx.r9.s64 = r11.s64 + 4260;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826D4AB0:
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

__attribute__((alias("__imp__sub_826D4AC8"))) PPC_WEAK_FUNC(sub_826D4AC8);
PPC_FUNC_IMPL(__imp__sub_826D4AC8) {
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
	// li r3,4912
	ctx.r3.s64 = 4912;
	// bl 0x82130528
	ctx.lr = 0x826D4ADC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d4af8
	if (cr6.eq) goto loc_826D4AF8;
	// bl 0x826ebdb0
	ctx.lr = 0x826D4AE8;
	sub_826EBDB0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D4AF8:
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

__attribute__((alias("__imp__sub_826D4B0C"))) PPC_WEAK_FUNC(sub_826D4B0C);
PPC_FUNC_IMPL(__imp__sub_826D4B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4B10"))) PPC_WEAK_FUNC(sub_826D4B10);
PPC_FUNC_IMPL(__imp__sub_826D4B10) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,4324
	ctx.r10.s64 = r11.s64 + 4324;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826e4238
	ctx.lr = 0x826D4B3C;
	sub_826E4238(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d4b54
	if (cr6.eq) goto loc_826D4B54;
	// bl 0x82130588
	ctx.lr = 0x826D4B50;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D4B54:
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

__attribute__((alias("__imp__sub_826D4B6C"))) PPC_WEAK_FUNC(sub_826D4B6C);
PPC_FUNC_IMPL(__imp__sub_826D4B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4B70"))) PPC_WEAK_FUNC(sub_826D4B70);
PPC_FUNC_IMPL(__imp__sub_826D4B70) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8800
	ctx.r3.s64 = ctx.r3.s64 + 8800;
	// b 0x826ed540
	sub_826ED540(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4B78"))) PPC_WEAK_FUNC(sub_826D4B78);
PPC_FUNC_IMPL(__imp__sub_826D4B78) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r5,8800
	ctx.r3.s64 = ctx.r5.s64 + 8800;
	// b 0x826ed2e0
	sub_826ED2E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4B84"))) PPC_WEAK_FUNC(sub_826D4B84);
PPC_FUNC_IMPL(__imp__sub_826D4B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4B88"))) PPC_WEAK_FUNC(sub_826D4B88);
PPC_FUNC_IMPL(__imp__sub_826D4B88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,8800
	ctx.r3.s64 = ctx.r3.s64 + 8800;
	// b 0x826ed488
	sub_826ED488(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4B98"))) PPC_WEAK_FUNC(sub_826D4B98);
PPC_FUNC_IMPL(__imp__sub_826D4B98) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4B9C"))) PPC_WEAK_FUNC(sub_826D4B9C);
PPC_FUNC_IMPL(__imp__sub_826D4B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4BA0"))) PPC_WEAK_FUNC(sub_826D4BA0);
PPC_FUNC_IMPL(__imp__sub_826D4BA0) {
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
	ctx.lr = 0x826D4BA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d96b8
	ctx.lr = 0x826D4BBC;
	sub_826D96B8(ctx, base);
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,28
	r27.s64 = 28;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addis r29,r31,3
	r29.s64 = r31.s64 + 196608;
	// addi r10,r11,-27096
	ctx.r10.s64 = r11.s64 + -27096;
	// li r30,31
	r30.s64 = 31;
	// addi r29,r29,29296
	r29.s64 = r29.s64 + 29296;
	// lwzx r26,r27,r28
	r26.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// stwx r10,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, ctx.r10.u32);
loc_826D4BE0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826f1450
	ctx.lr = 0x826D4BE8;
	sub_826F1450(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,5936
	r29.s64 = r29.s64 + 5936;
	// bne 0x826d4be0
	if (!cr0.eq) goto loc_826D4BE0;
	// addi r3,r31,8536
	ctx.r3.s64 = r31.s64 + 8536;
	// bl 0x826da278
	ctx.lr = 0x826D4BFC;
	sub_826DA278(ctx, base);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4c10
	if (cr6.eq) goto loc_826D4C10;
	// bl 0x8278f830
	ctx.lr = 0x826D4C0C;
	sub_8278F830(ctx, base);
	// bl 0x8278f910
	ctx.lr = 0x826D4C10;
	sub_8278F910(ctx, base);
loc_826D4C10:
	// lwz r3,8492(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8492);
	// bl 0x827970f8
	ctx.lr = 0x826D4C18;
	sub_827970F8(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82130000
	ctx.lr = 0x826D4C20;
	sub_82130000(ctx, base);
	// addi r3,r31,8516
	ctx.r3.s64 = r31.s64 + 8516;
	// bl 0x826ee250
	ctx.lr = 0x826D4C28;
	sub_826EE250(ctx, base);
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D4C40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x826ed210
	ctx.lr = 0x826D4C48;
	sub_826ED210(ctx, base);
	// bl 0x826ed898
	ctx.lr = 0x826D4C4C;
	sub_826ED898(ctx, base);
	// stwx r26,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826D4C58"))) PPC_WEAK_FUNC(sub_826D4C58);
PPC_FUNC_IMPL(__imp__sub_826D4C58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r3,-27140(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -27140);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4C64"))) PPC_WEAK_FUNC(sub_826D4C64);
PPC_FUNC_IMPL(__imp__sub_826D4C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4C68"))) PPC_WEAK_FUNC(sub_826D4C68);
PPC_FUNC_IMPL(__imp__sub_826D4C68) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8536
	ctx.r3.s64 = ctx.r3.s64 + 8536;
	// b 0x826daff8
	sub_826DAFF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4C70"))) PPC_WEAK_FUNC(sub_826D4C70);
PPC_FUNC_IMPL(__imp__sub_826D4C70) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8536
	ctx.r3.s64 = ctx.r3.s64 + 8536;
	// b 0x826db070
	sub_826DB070(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4C78"))) PPC_WEAK_FUNC(sub_826D4C78);
PPC_FUNC_IMPL(__imp__sub_826D4C78) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8536
	ctx.r3.s64 = ctx.r3.s64 + 8536;
	// b 0x826da8c8
	sub_826DA8C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4C80"))) PPC_WEAK_FUNC(sub_826D4C80);
PPC_FUNC_IMPL(__imp__sub_826D4C80) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8536
	ctx.r3.s64 = ctx.r3.s64 + 8536;
	// b 0x826da8d8
	sub_826DA8D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4C88"))) PPC_WEAK_FUNC(sub_826D4C88);
PPC_FUNC_IMPL(__imp__sub_826D4C88) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8536
	ctx.r3.s64 = ctx.r3.s64 + 8536;
	// b 0x8221cfa8
	sub_8221CFA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D4C90"))) PPC_WEAK_FUNC(sub_826D4C90);
PPC_FUNC_IMPL(__imp__sub_826D4C90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r3,-27138(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -27138);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4C9C"))) PPC_WEAK_FUNC(sub_826D4C9C);
PPC_FUNC_IMPL(__imp__sub_826D4C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4CA0"))) PPC_WEAK_FUNC(sub_826D4CA0);
PPC_FUNC_IMPL(__imp__sub_826D4CA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-27139(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27139);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d4cec
	if (cr6.eq) goto loc_826D4CEC;
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16980
	ctx.r10.u64 = r11.u64 | 16980;
	// lwzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x826d4cec
	if (cr6.lt) goto loc_826D4CEC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r11,76(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d4cec
	if (!cr6.eq) goto loc_826D4CEC;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_826D4CEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D4CF4"))) PPC_WEAK_FUNC(sub_826D4CF4);
PPC_FUNC_IMPL(__imp__sub_826D4CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4CF8"))) PPC_WEAK_FUNC(sub_826D4CF8);
PPC_FUNC_IMPL(__imp__sub_826D4CF8) {
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
	ctx.lr = 0x826D4D00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r28,0,30,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4d64
	if (cr6.eq) goto loc_826D4D64;
	// lwz r10,-16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// addi r29,r30,-16
	r29.s64 = r30.s64 + -16;
	// mulli r11,r10,3616
	r11.s64 = ctx.r10.s64 * 3616;
	// addic. r31,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r31.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// blt 0x826d4d44
	if (cr0.lt) goto loc_826D4D44;
loc_826D4D30:
	// addi r30,r30,-3616
	r30.s64 = r30.s64 + -3616;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826e6848
	ctx.lr = 0x826D4D3C;
	sub_826E6848(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x826d4d30
	if (!cr0.lt) goto loc_826D4D30;
loc_826D4D44:
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4d58
	if (cr6.eq) goto loc_826D4D58;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826D4D58;
	sub_82130588(ctx, base);
loc_826D4D58:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D4D64:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826e6848
	ctx.lr = 0x826D4D6C;
	sub_826E6848(ctx, base);
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4d80
	if (cr6.eq) goto loc_826D4D80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x826D4D80;
	sub_82130588(ctx, base);
loc_826D4D80:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D4D8C"))) PPC_WEAK_FUNC(sub_826D4D8C);
PPC_FUNC_IMPL(__imp__sub_826D4D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4D90"))) PPC_WEAK_FUNC(sub_826D4D90);
PPC_FUNC_IMPL(__imp__sub_826D4D90) {
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
	ctx.lr = 0x826D4D98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r28,0,30,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4dfc
	if (cr6.eq) goto loc_826D4DFC;
	// lwz r10,-16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// addi r29,r30,-16
	r29.s64 = r30.s64 + -16;
	// mulli r11,r10,4912
	r11.s64 = ctx.r10.s64 * 4912;
	// addic. r31,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r31.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// blt 0x826d4ddc
	if (cr0.lt) goto loc_826D4DDC;
loc_826D4DC8:
	// addi r30,r30,-4912
	r30.s64 = r30.s64 + -4912;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826d49d8
	ctx.lr = 0x826D4DD4;
	sub_826D49D8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x826d4dc8
	if (!cr0.lt) goto loc_826D4DC8;
loc_826D4DDC:
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4df0
	if (cr6.eq) goto loc_826D4DF0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826D4DF0;
	sub_82130588(ctx, base);
loc_826D4DF0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D4DFC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826d49d8
	ctx.lr = 0x826D4E04;
	sub_826D49D8(ctx, base);
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4e18
	if (cr6.eq) goto loc_826D4E18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x826D4E18;
	sub_82130588(ctx, base);
loc_826D4E18:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D4E24"))) PPC_WEAK_FUNC(sub_826D4E24);
PPC_FUNC_IMPL(__imp__sub_826D4E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4E28"))) PPC_WEAK_FUNC(sub_826D4E28);
PPC_FUNC_IMPL(__imp__sub_826D4E28) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c9438
	ctx.lr = 0x826D4E4C;
	sub_821C9438(ctx, base);
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// rlwinm r3,r3,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FFFC;
	// bl 0x82130528
	ctx.lr = 0x826D4E58;
	sub_82130528(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// beq cr6,0x826d4e90
	if (cr6.eq) goto loc_826D4E90;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_826D4E74:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r9,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x826d4e74
	if (cr6.lt) goto loc_826D4E74;
loc_826D4E90:
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
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

__attribute__((alias("__imp__sub_826D4EAC"))) PPC_WEAK_FUNC(sub_826D4EAC);
PPC_FUNC_IMPL(__imp__sub_826D4EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D4EB0"))) PPC_WEAK_FUNC(sub_826D4EB0);
PPC_FUNC_IMPL(__imp__sub_826D4EB0) {
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
	ctx.lr = 0x826D4EB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,16(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4f80
	if (cr6.eq) goto loc_826D4F80;
	// rlwinm r3,r28,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x826D4EDC;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d4f00
	if (cr6.eq) goto loc_826D4F00;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_826D4EF4:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x826d4ef4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826D4EF4;
loc_826D4F00:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4f70
	if (cr6.eq) goto loc_826D4F70;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826D4F14:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d4f5c
	if (cr6.eq) goto loc_826D4F5C;
loc_826D4F24:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// twllei r31,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// divwu r4,r5,r31
	ctx.r4.u32 = ctx.r5.u32 / r31.u32;
	// mullw r3,r4,r31
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r31.s32);
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stwx r6,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r6.u32);
	// bne cr6,0x826d4f24
	if (!cr6.eq) goto loc_826D4F24;
loc_826D4F5C:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x826d4f14
	if (cr6.lt) goto loc_826D4F14;
loc_826D4F70:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826D4F7C;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_826D4F80:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D4F88"))) PPC_WEAK_FUNC(sub_826D4F88);
PPC_FUNC_IMPL(__imp__sub_826D4F88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r31,r3,360
	r31.s64 = ctx.r3.s64 + 360;
	// li r30,17
	r30.s64 = 17;
loc_826D4FA4:
	// addi r31,r31,-20
	r31.s64 = r31.s64 + -20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8251b968
	ctx.lr = 0x826D4FB0;
	sub_8251B968(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826d4fa4
	if (!cr0.lt) goto loc_826D4FA4;
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

__attribute__((alias("__imp__sub_826D4FD0"))) PPC_WEAK_FUNC(sub_826D4FD0);
PPC_FUNC_IMPL(__imp__sub_826D4FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r11,-31280
	ctx.r9.s64 = r11.s64 + -31280;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,32
	ctx.r6.s64 = 32;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// lvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82687800
	ctx.lr = 0x826D502C;
	sub_82687800(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r11,240(r31)
	PPC_STORE_U16(r31.u32 + 240, r11.u16);
	// stw r11,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r11.u32);
	// lfs f0,3796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r11.u32);
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r11.u32);
	// stw r10,264(r31)
	PPC_STORE_U32(r31.u32 + 264, ctx.r10.u32);
	// stw r10,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r10.u32);
	// stw r10,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r10.u32);
	// stw r10,276(r31)
	PPC_STORE_U32(r31.u32 + 276, ctx.r10.u32);
	// stw r11,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r11.u32);
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// stb r11,292(r31)
	PPC_STORE_U8(r31.u32 + 292, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826D508C"))) PPC_WEAK_FUNC(sub_826D508C);
PPC_FUNC_IMPL(__imp__sub_826D508C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5090"))) PPC_WEAK_FUNC(sub_826D5090);
PPC_FUNC_IMPL(__imp__sub_826D5090) {
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
	ctx.lr = 0x826D50A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d50d0
	if (cr6.eq) goto loc_826D50D0;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,4400
	ctx.r9.s64 = ctx.r10.s64 + 4400;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D50D0:
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

__attribute__((alias("__imp__sub_826D50E4"))) PPC_WEAK_FUNC(sub_826D50E4);
PPC_FUNC_IMPL(__imp__sub_826D50E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D50E8"))) PPC_WEAK_FUNC(sub_826D50E8);
PPC_FUNC_IMPL(__imp__sub_826D50E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826D50F0;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82687930
	ctx.lr = 0x826D5108;
	sub_82687930(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826df370
	ctx.lr = 0x826D5118;
	sub_826DF370(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x826ed540
	ctx.lr = 0x826D5124;
	sub_826ED540(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D512C"))) PPC_WEAK_FUNC(sub_826D512C);
PPC_FUNC_IMPL(__imp__sub_826D512C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5130"))) PPC_WEAK_FUNC(sub_826D5130);
PPC_FUNC_IMPL(__imp__sub_826D5130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826D5138;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82687930
	ctx.lr = 0x826D5150;
	sub_82687930(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826df3e8
	ctx.lr = 0x826D5160;
	sub_826DF3E8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x826ed540
	ctx.lr = 0x826D516C;
	sub_826ED540(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D5174"))) PPC_WEAK_FUNC(sub_826D5174);
PPC_FUNC_IMPL(__imp__sub_826D5174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5178"))) PPC_WEAK_FUNC(sub_826D5178);
PPC_FUNC_IMPL(__imp__sub_826D5178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-22584(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -22584);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D518C"))) PPC_WEAK_FUNC(sub_826D518C);
PPC_FUNC_IMPL(__imp__sub_826D518C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5190"))) PPC_WEAK_FUNC(sub_826D5190);
PPC_FUNC_IMPL(__imp__sub_826D5190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-22583(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -22583);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D51A4"))) PPC_WEAK_FUNC(sub_826D51A4);
PPC_FUNC_IMPL(__imp__sub_826D51A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D51A8"))) PPC_WEAK_FUNC(sub_826D51A8);
PPC_FUNC_IMPL(__imp__sub_826D51A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-27140(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -27140);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D51BC"))) PPC_WEAK_FUNC(sub_826D51BC);
PPC_FUNC_IMPL(__imp__sub_826D51BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D51C0"))) PPC_WEAK_FUNC(sub_826D51C0);
PPC_FUNC_IMPL(__imp__sub_826D51C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,-27140(r10)
	PPC_STORE_U8(ctx.r10.u32 + -27140, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D51E0"))) PPC_WEAK_FUNC(sub_826D51E0);
PPC_FUNC_IMPL(__imp__sub_826D51E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-22582(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -22582);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D51F4"))) PPC_WEAK_FUNC(sub_826D51F4);
PPC_FUNC_IMPL(__imp__sub_826D51F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D51F8"))) PPC_WEAK_FUNC(sub_826D51F8);
PPC_FUNC_IMPL(__imp__sub_826D51F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-27139(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -27139);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D520C"))) PPC_WEAK_FUNC(sub_826D520C);
PPC_FUNC_IMPL(__imp__sub_826D520C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5210"))) PPC_WEAK_FUNC(sub_826D5210);
PPC_FUNC_IMPL(__imp__sub_826D5210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,-27139(r10)
	PPC_STORE_U8(ctx.r10.u32 + -27139, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5230"))) PPC_WEAK_FUNC(sub_826D5230);
PPC_FUNC_IMPL(__imp__sub_826D5230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-27138(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -27138);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5244"))) PPC_WEAK_FUNC(sub_826D5244);
PPC_FUNC_IMPL(__imp__sub_826D5244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5248"))) PPC_WEAK_FUNC(sub_826D5248);
PPC_FUNC_IMPL(__imp__sub_826D5248) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d5280
	if (!cr6.eq) goto loc_826D5280;
loc_826D5278:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x826d52d4
	goto loc_826D52D4;
loc_826D5280:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,8536
	ctx.r3.s64 = r11.s64 + 8536;
	// bl 0x826da8d0
	ctx.lr = 0x826D5290;
	sub_826DA8D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d5278
	if (cr6.eq) goto loc_826D5278;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// lwz r4,172(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5278
	if (cr6.eq) goto loc_826D5278;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d5278
	if (cr6.eq) goto loc_826D5278;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f0,27644(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 * f0.f64));
	// bl 0x826e1418
	ctx.lr = 0x826D52D4;
	sub_826E1418(ctx, base);
loc_826D52D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_826D52F0"))) PPC_WEAK_FUNC(sub_826D52F0);
PPC_FUNC_IMPL(__imp__sub_826D52F0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d5328
	if (!cr6.eq) goto loc_826D5328;
loc_826D5320:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x826d5374
	goto loc_826D5374;
loc_826D5328:
	// addi r3,r11,8536
	ctx.r3.s64 = r11.s64 + 8536;
	// bl 0x826da8d8
	ctx.lr = 0x826D5330;
	sub_826DA8D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d5320
	if (cr6.eq) goto loc_826D5320;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// lwz r4,172(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5320
	if (cr6.eq) goto loc_826D5320;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d5320
	if (cr6.eq) goto loc_826D5320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f0,27644(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 * f0.f64));
	// bl 0x826e1418
	ctx.lr = 0x826D5374;
	sub_826E1418(ctx, base);
loc_826D5374:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_826D5390"))) PPC_WEAK_FUNC(sub_826D5390);
PPC_FUNC_IMPL(__imp__sub_826D5390) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d53ec
	if (cr6.eq) goto loc_826D53EC;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d53ec
	if (cr6.eq) goto loc_826D53EC;
loc_826D53C0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,172(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// bl 0x823db730
	ctx.lr = 0x826D53CC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d5408
	if (cr6.eq) goto loc_826D5408;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d53ec
	if (cr6.eq) goto loc_826D53EC;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d53c0
	if (!cr6.eq) goto loc_826D53C0;
loc_826D53EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D53F0:
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
loc_826D5408:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x826d53f0
	goto loc_826D53F0;
}

__attribute__((alias("__imp__sub_826D5410"))) PPC_WEAK_FUNC(sub_826D5410);
PPC_FUNC_IMPL(__imp__sub_826D5410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2192
	ctx.r7.s64 = ctx.r9.s64 + 2192;
	// lis r5,6
	ctx.r5.s64 = 393216;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lwz r11,2192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// ori r8,r5,16972
	ctx.r8.u64 = ctx.r5.u64 | 16972;
	// lis r4,6
	ctx.r4.s64 = 393216;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// ori r4,r4,16968
	ctx.r4.u64 = ctx.r4.u64 | 16968;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mulld r10,r5,r6
	ctx.r10.s64 = ctx.r5.s64 * ctx.r6.s64;
	// lfsx f0,r3,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// lfsx f13,r3,r4
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// lis r5,6
	ctx.r5.s64 = 393216;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// ori r6,r5,16964
	ctx.r6.u64 = ctx.r5.u64 | 16964;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// lfs f0,14348(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	f0.f64 = double(temp.f32);
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fmadds f7,f8,f0,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f13.f64));
	// stfsx f7,r3,r6
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r6.u32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5498"))) PPC_WEAK_FUNC(sub_826D5498);
PPC_FUNC_IMPL(__imp__sub_826D5498) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826d54ec
	if (!cr6.gt) goto loc_826D54EC;
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_826D54A8:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d54d8
	if (cr6.eq) goto loc_826D54D8;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d54d0
	if (cr6.eq) goto loc_826D54D0;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_826D54D0:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x826d54dc
	goto loc_826D54DC;
loc_826D54D8:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_826D54DC:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,3616
	r11.s64 = r11.s64 + 3616;
	// bne 0x826d54a8
	if (!cr0.eq) goto loc_826D54A8;
loc_826D54EC:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r4,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r4.u32);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5500"))) PPC_WEAK_FUNC(sub_826D5500);
PPC_FUNC_IMPL(__imp__sub_826D5500) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826d5554
	if (!cr6.gt) goto loc_826D5554;
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_826D5510:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5540
	if (cr6.eq) goto loc_826D5540;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d5538
	if (cr6.eq) goto loc_826D5538;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_826D5538:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x826d5544
	goto loc_826D5544;
loc_826D5540:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_826D5544:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,4912
	r11.s64 = r11.s64 + 4912;
	// bne 0x826d5510
	if (!cr0.eq) goto loc_826D5510;
loc_826D5554:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r4,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r4.u32);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5568"))) PPC_WEAK_FUNC(sub_826D5568);
PPC_FUNC_IMPL(__imp__sub_826D5568) {
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
	// li r30,0
	r30.s64 = 0;
loc_826D5584:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d55dc
	if (cr6.eq) goto loc_826D55DC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bne cr6,0x826d55a4
	if (!cr6.eq) goto loc_826D55A4;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_826D55A4:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d55b8
	if (cr6.eq) goto loc_826D55B8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_826D55B8:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d55cc
	if (cr6.eq) goto loc_826D55CC;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_826D55CC:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// bne cr6,0x826d5584
	if (!cr6.eq) goto loc_826D5584;
loc_826D55DC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5634
	if (cr6.eq) goto loc_826D5634;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826d55fc
	if (!cr6.eq) goto loc_826D55FC;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_826D55FC:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5610
	if (cr6.eq) goto loc_826D5610;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_826D5610:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5624
	if (cr6.eq) goto loc_826D5624;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_826D5624:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// bne cr6,0x826d55dc
	if (!cr6.eq) goto loc_826D55DC;
loc_826D5634:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5670
	if (cr6.eq) goto loc_826D5670;
	// lwz r10,-16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826d566c
	if (cr6.eq) goto loc_826D566C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826D5668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826d5670
	goto loc_826D5670;
loc_826D566C:
	// bl 0x82130588
	ctx.lr = 0x826D5670;
	sub_82130588(ctx, base);
loc_826D5670:
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
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

__attribute__((alias("__imp__sub_826D5694"))) PPC_WEAK_FUNC(sub_826D5694);
PPC_FUNC_IMPL(__imp__sub_826D5694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5698"))) PPC_WEAK_FUNC(sub_826D5698);
PPC_FUNC_IMPL(__imp__sub_826D5698) {
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
	ctx.lr = 0x826D56AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d56d8
	if (cr6.eq) goto loc_826D56D8;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,4424
	ctx.r9.s64 = ctx.r10.s64 + 4424;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D56D8:
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

__attribute__((alias("__imp__sub_826D56EC"))) PPC_WEAK_FUNC(sub_826D56EC);
PPC_FUNC_IMPL(__imp__sub_826D56EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D56F0"))) PPC_WEAK_FUNC(sub_826D56F0);
PPC_FUNC_IMPL(__imp__sub_826D56F0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826D56F8;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-2480(r1)
	ea = -2480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// addi r3,r26,8800
	ctx.r3.s64 = r26.s64 + 8800;
	// bl 0x826ed338
	ctx.lr = 0x826D5718;
	sub_826ED338(ctx, base);
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5a0c
	if (cr6.eq) goto loc_826D5A0C;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r23,0
	r23.s64 = 0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lfs f31,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r22,r23
	r22.u64 = r23.u64;
	// li r25,1
	r25.s64 = 1;
	// addi r31,r11,23056
	r31.s64 = r11.s64 + 23056;
	// addi r30,r10,-18952
	r30.s64 = ctx.r10.s64 + -18952;
	// addi r24,r9,3816
	r24.s64 = ctx.r9.s64 + 3816;
	// addi r28,r8,3832
	r28.s64 = ctx.r8.s64 + 3832;
loc_826D5758:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// add r11,r22,r11
	r11.u64 = r22.u64 + r11.u64;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d58a4
	if (cr6.eq) goto loc_826D58A4;
loc_826D576C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r27,4(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826e9620
	ctx.lr = 0x826D577C;
	sub_826E9620(ctx, base);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d579c
	if (cr6.eq) goto loc_826D579C;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d57f0
	if (!cr6.eq) goto loc_826D57F0;
loc_826D579C:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d57b8
	if (cr6.eq) goto loc_826D57B8;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d57f0
	if (!cr6.eq) goto loc_826D57F0;
loc_826D57B8:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d57d4
	if (cr6.eq) goto loc_826D57D4;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d57f0
	if (!cr6.eq) goto loc_826D57F0;
loc_826D57D4:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d57f8
	if (cr6.eq) goto loc_826D57F8;
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d57f8
	if (cr6.eq) goto loc_826D57F8;
loc_826D57F0:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x826d57fc
	goto loc_826D57FC;
loc_826D57F8:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_826D57FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5898
	if (cr6.eq) goto loc_826D5898;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x82687930
	ctx.lr = 0x826D5810;
	sub_82687930(ctx, base);
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826df370
	ctx.lr = 0x826D5820;
	sub_826DF370(ctx, base);
	// stb r23,944(r1)
	PPC_STORE_U8(ctx.r1.u32 + 944, r23.u8);
	// stw r25,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, r25.u32);
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// bl 0x82687930
	ctx.lr = 0x826D5830;
	sub_82687930(ctx, base);
	// lbz r11,1252(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1252);
	// stfs f31,1248(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 1248, temp.u32);
	// stw r28,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r28.u32);
	// rlwinm r11,r11,0,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// stb r11,1252(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1252, r11.u8);
	// bl 0x82761678
	ctx.lr = 0x826D584C;
	sub_82761678(ctx, base);
	// addi r3,r1,1488
	ctx.r3.s64 = ctx.r1.s64 + 1488;
	// bl 0x826d4fd0
	ctx.lr = 0x826D5854;
	sub_826D4FD0(ctx, base);
	// addi r4,r1,2080
	ctx.r4.s64 = ctx.r1.s64 + 2080;
	// addi r3,r1,944
	ctx.r3.s64 = ctx.r1.s64 + 944;
	// bl 0x826e0140
	ctx.lr = 0x826D5860;
	sub_826E0140(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,944
	ctx.r3.s64 = ctx.r1.s64 + 944;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826e0438
	ctx.lr = 0x826D5870;
	sub_826E0438(ctx, base);
	// stw r30,1680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1680, r30.u32);
	// stw r31,1552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1552, r31.u32);
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// stw r28,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r28.u32);
	// bl 0x82761428
	ctx.lr = 0x826D5884;
	sub_82761428(ctx, base);
	// stw r24,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r24.u32);
	// stw r30,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, r30.u32);
	// stw r31,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, r31.u32);
	// stw r30,2272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2272, r30.u32);
	// stw r31,2144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2144, r31.u32);
loc_826D5898:
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826d576c
	if (!cr6.eq) goto loc_826D576C;
loc_826D58A4:
	// addi r22,r22,52
	r22.s64 = r22.s64 + 52;
	// cmpwi cr6,r22,156
	cr6.compare<int32_t>(r22.s32, 156, xer);
	// blt cr6,0x826d5758
	if (cr6.lt) goto loc_826D5758;
	// mr r22,r23
	r22.u64 = r23.u64;
loc_826D58B4:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// add r11,r22,r11
	r11.u64 = r22.u64 + r11.u64;
	// lwz r29,32(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d5a00
	if (cr6.eq) goto loc_826D5A00;
loc_826D58C8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r27,4(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826e9620
	ctx.lr = 0x826D58D8;
	sub_826E9620(ctx, base);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d58f8
	if (cr6.eq) goto loc_826D58F8;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d594c
	if (!cr6.eq) goto loc_826D594C;
loc_826D58F8:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5914
	if (cr6.eq) goto loc_826D5914;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d594c
	if (!cr6.eq) goto loc_826D594C;
loc_826D5914:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5930
	if (cr6.eq) goto loc_826D5930;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d594c
	if (!cr6.eq) goto loc_826D594C;
loc_826D5930:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5954
	if (cr6.eq) goto loc_826D5954;
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5954
	if (cr6.eq) goto loc_826D5954;
loc_826D594C:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x826d5958
	goto loc_826D5958;
loc_826D5954:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_826D5958:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d59f4
	if (cr6.eq) goto loc_826D59F4;
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// bl 0x82687930
	ctx.lr = 0x826D596C;
	sub_82687930(ctx, base);
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826df370
	ctx.lr = 0x826D597C;
	sub_826DF370(ctx, base);
	// stb r23,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r23.u8);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82687930
	ctx.lr = 0x826D598C;
	sub_82687930(ctx, base);
	// lbz r11,404(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 404);
	// stfs f31,400(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stw r28,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r28.u32);
	// rlwinm r11,r11,0,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// stb r11,404(r1)
	PPC_STORE_U8(ctx.r1.u32 + 404, r11.u8);
	// bl 0x82761678
	ctx.lr = 0x826D59A8;
	sub_82761678(ctx, base);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x826d4fd0
	ctx.lr = 0x826D59B0;
	sub_826D4FD0(ctx, base);
	// addi r4,r1,1792
	ctx.r4.s64 = ctx.r1.s64 + 1792;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826e0140
	ctx.lr = 0x826D59BC;
	sub_826E0140(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826e0438
	ctx.lr = 0x826D59CC;
	sub_826E0438(ctx, base);
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r30.u32);
	// stw r31,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r31.u32);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// stw r28,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r28.u32);
	// bl 0x82761428
	ctx.lr = 0x826D59E0;
	sub_82761428(ctx, base);
	// stw r24,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r24.u32);
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r30.u32);
	// stw r31,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r31.u32);
	// stw r30,1984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1984, r30.u32);
	// stw r31,1856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1856, r31.u32);
loc_826D59F4:
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826d58c8
	if (!cr6.eq) goto loc_826D58C8;
loc_826D5A00:
	// addi r22,r22,52
	r22.s64 = r22.s64 + 52;
	// cmpwi cr6,r22,156
	cr6.compare<int32_t>(r22.s32, 156, xer);
	// blt cr6,0x826d58b4
	if (cr6.lt) goto loc_826D58B4;
loc_826D5A0C:
	// addi r1,r1,2480
	ctx.r1.s64 = ctx.r1.s64 + 2480;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_826D5A18"))) PPC_WEAK_FUNC(sub_826D5A18);
PPC_FUNC_IMPL(__imp__sub_826D5A18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16985
	ctx.r10.u64 = r11.u64 | 16985;
	// lbzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d5a38
	if (cr6.eq) goto loc_826D5A38;
	// addis r3,r3,6
	ctx.r3.s64 = ctx.r3.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// b 0x826d9530
	sub_826D9530(ctx, base);
	return;
loc_826D5A38:
	// b 0x826d56f0
	sub_826D56F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D5A3C"))) PPC_WEAK_FUNC(sub_826D5A3C);
PPC_FUNC_IMPL(__imp__sub_826D5A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5A40"))) PPC_WEAK_FUNC(sub_826D5A40);
PPC_FUNC_IMPL(__imp__sub_826D5A40) {
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
	ctx.lr = 0x826D5A48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826d5abc
	if (cr6.eq) goto loc_826D5ABC;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5ab0
	if (cr6.eq) goto loc_826D5AB0;
	// li r30,0
	r30.s64 = 0;
loc_826D5A6C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d5aa4
	if (cr6.eq) goto loc_826D5AA4;
loc_826D5A80:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D5A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d5a80
	if (!cr6.eq) goto loc_826D5A80;
loc_826D5AA4:
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// cmpwi cr6,r30,156
	cr6.compare<int32_t>(r30.s32, 156, xer);
	// blt cr6,0x826d5a6c
	if (cr6.lt) goto loc_826D5A6C;
loc_826D5AB0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r29,8800
	ctx.r3.s64 = r29.s64 + 8800;
	// bl 0x826ed3e0
	ctx.lr = 0x826D5ABC;
	sub_826ED3E0(ctx, base);
loc_826D5ABC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D5AC4"))) PPC_WEAK_FUNC(sub_826D5AC4);
PPC_FUNC_IMPL(__imp__sub_826D5AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5AC8"))) PPC_WEAK_FUNC(sub_826D5AC8);
PPC_FUNC_IMPL(__imp__sub_826D5AC8) {
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
	ctx.lr = 0x826D5AD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5b28
	if (cr6.eq) goto loc_826D5B28;
	// li r30,0
	r30.s64 = 0;
loc_826D5AE8:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d5b1c
	if (cr6.eq) goto loc_826D5B1C;
loc_826D5AFC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D5B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d5afc
	if (!cr6.eq) goto loc_826D5AFC;
loc_826D5B1C:
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// cmpwi cr6,r30,156
	cr6.compare<int32_t>(r30.s32, 156, xer);
	// blt cr6,0x826d5ae8
	if (cr6.lt) goto loc_826D5AE8;
loc_826D5B28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826D5B30"))) PPC_WEAK_FUNC(sub_826D5B30);
PPC_FUNC_IMPL(__imp__sub_826D5B30) {
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
	ctx.lr = 0x826D5B38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r29
	r28.u64 = r29.u64;
	// bl 0x82256058
	ctx.lr = 0x826D5B4C;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d5bf4
	if (cr6.eq) goto loc_826D5BF4;
	// bl 0x82256058
	ctx.lr = 0x826D5B5C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d5bf4
	if (cr6.eq) goto loc_826D5BF4;
	// bl 0x82256058
	ctx.lr = 0x826D5B68;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826d5bf4
	if (!cr6.eq) goto loc_826D5BF4;
loc_826D5B94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82256138
	ctx.lr = 0x826D5B9C;
	sub_82256138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d5bf4
	if (!cr6.eq) goto loc_826D5BF4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82256028
	ctx.lr = 0x826D5BB0;
	sub_82256028(ctx, base);
	// lis r11,6
	r11.s64 = 393216;
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// ori r6,r11,16980
	ctx.r6.u64 = r11.u64 | 16980;
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// ori r5,r9,16978
	ctx.r5.u64 = ctx.r9.u64 | 16978;
	// ori r11,r8,16976
	r11.u64 = ctx.r8.u64 | 16976;
	// ori r10,r7,16977
	ctx.r10.u64 = ctx.r7.u64 | 16977;
	// li r30,1
	r30.s64 = 1;
	// stwx r3,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stbx r9,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, ctx.r9.u8);
	// stbx r29,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r29.u8);
	// stbx r30,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r30.u8);
	// b 0x826d5c2c
	goto loc_826D5C2C;
loc_826D5BF4:
	// addis r11,r31,6
	r11.s64 = r31.s64 + 393216;
	// li r30,1
	r30.s64 = 1;
	// addi r11,r11,16977
	r11.s64 = r11.s64 + 16977;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5c10
	if (cr6.eq) goto loc_826D5C10;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_826D5C10:
	// lis r10,6
	ctx.r10.s64 = 393216;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// ori r8,r10,16976
	ctx.r8.u64 = ctx.r10.u64 | 16976;
	// ori r7,r9,16978
	ctx.r7.u64 = ctx.r9.u64 | 16978;
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// stbx r29,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r29.u8);
loc_826D5C2C:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5c50
	if (cr6.eq) goto loc_826D5C50;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D5C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D5C50:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// addis r11,r31,6
	r11.s64 = r31.s64 + 393216;
	// addi r11,r11,16979
	r11.s64 = r11.s64 + 16979;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// beq cr6,0x826d5cc4
	if (cr6.eq) goto loc_826D5CC4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d5cd0
	if (!cr6.eq) goto loc_826D5CD0;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r8,r10,16985
	ctx.r8.u64 = ctx.r10.u64 | 16985;
	// clrlwi r7,r9,28
	ctx.r7.u64 = ctx.r9.u32 & 0xF;
	// ori r6,r7,112
	ctx.r6.u64 = ctx.r7.u64 | 112;
	// lbzx r5,r31,r8
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + ctx.r8.u32);
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d5cb4
	if (cr6.eq) goto loc_826D5CB4;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5CAC;
	sub_826D9530(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D5CB4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D5CBC;
	sub_826D56F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D5CC4:
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x826d5cd0
	if (!cr6.eq) goto loc_826D5CD0;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
loc_826D5CD0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826D5CD8"))) PPC_WEAK_FUNC(sub_826D5CD8);
PPC_FUNC_IMPL(__imp__sub_826D5CD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// b 0x826e1a20
	sub_826E1A20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826D5D08"))) PPC_WEAK_FUNC(sub_826D5D08);
PPC_FUNC_IMPL(__imp__sub_826D5D08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5D0C"))) PPC_WEAK_FUNC(sub_826D5D0C);
PPC_FUNC_IMPL(__imp__sub_826D5D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5D10"))) PPC_WEAK_FUNC(sub_826D5D10);
PPC_FUNC_IMPL(__imp__sub_826D5D10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,-10012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r9,20(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// lfs f13,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f12,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stb r8,-27138(r7)
	PPC_STORE_U8(ctx.r7.u32 + -27138, ctx.r8.u8);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,-22568(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22568, ctx.r9.u32);
	// stfs f0,8312(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8312, temp.u32);
	// lwz r10,-10012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// stfs f13,8316(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8316, temp.u32);
	// lwz r10,-10012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// stfs f12,8304(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8304, temp.u32);
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// stfs f11,8308(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 8308, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5D8C"))) PPC_WEAK_FUNC(sub_826D5D8C);
PPC_FUNC_IMPL(__imp__sub_826D5D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826D5D90"))) PPC_WEAK_FUNC(sub_826D5D90);
PPC_FUNC_IMPL(__imp__sub_826D5D90) {
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
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5e0c
	if (cr6.eq) goto loc_826D5E0C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r3,-22584(r10)
	PPC_STORE_U8(ctx.r10.u32 + -22584, ctx.r3.u8);
	// bne cr6,0x826d5e0c
	if (!cr6.eq) goto loc_826D5E0C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// ori r7,r9,16985
	ctx.r7.u64 = ctx.r9.u64 | 16985;
	// ori r6,r8,96
	ctx.r6.u64 = ctx.r8.u64 | 96;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d5e04
	if (cr6.eq) goto loc_826D5E04;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5DF4;
	sub_826D9530(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D5E04:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D5E0C;
	sub_826D56F0(ctx, base);
loc_826D5E0C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826D5E1C"))) PPC_WEAK_FUNC(sub_826D5E1C);
PPC_FUNC_IMPL(__imp__sub_826D5E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

