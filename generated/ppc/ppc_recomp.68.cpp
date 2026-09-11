#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_823B9E00) {
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
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,29432
	ctx.r9.s64 = ctx.r10.s64 + 29432;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// beq cr6,0x823b9e70
	if (cr6.eq) goto loc_823B9E70;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823B9E50:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823b9e50
	if (!cr6.eq) goto loc_823B9E50;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823B9E70;
	sub_821C9650(ctx, base);
loc_823B9E70:
	// li r11,4
	r11.s64 = 4;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8244d5c0
	ctx.lr = 0x823B9E88;
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
}

PPC_WEAK_FUNC(sub_823B9E00) {
	__imp__sub_823B9E00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9EA0) {
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
	// lwz r11,252(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bge cr6,0x823b9edc
	if (!cr6.lt) goto loc_823B9EDC;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r11,-29164
	ctx.r3.s64 = r11.s64 + -29164;
	// bl 0x82130000
	ctx.lr = 0x823B9EC8;
	sub_82130000(ctx, base);
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
loc_823B9EDC:
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

PPC_WEAK_FUNC(sub_823B9EA0) {
	__imp__sub_823B9EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9EF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lhz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x823b9f6c
	if (!cr6.gt) goto loc_823B9F6C;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
loc_823B9F14:
	// lhz r11,4(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b9f28
	if (cr6.eq) goto loc_823B9F28;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x823b9f2c
	goto loc_823B9F2C;
loc_823B9F28:
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_823B9F2C:
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823B9F30:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r31,0(r10)
	r31.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - r31.s64;
	// beq cr6,0x823b9f54
	if (cr6.eq) goto loc_823B9F54;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823b9f30
	if (cr6.eq) goto loc_823B9F30;
loc_823B9F54:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823b9f78
	if (cr6.eq) goto loc_823B9F78;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// blt cr6,0x823b9f14
	if (cr6.lt) goto loc_823B9F14;
loc_823B9F6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823B9F78:
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823B9EF0) {
	__imp__sub_823B9EF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9F88) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r3,r31,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x823B9FA4;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823b9fe8
	if (!cr6.gt) goto loc_823B9FE8;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r11,r3,14
	r11.s64 = ctx.r3.s64 + 14;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,29432
	ctx.r9.s64 = ctx.r9.s64 + 29432;
loc_823B9FBC:
	// addic. r8,r11,-14
	xer.ca = r11.u32 > 13;
	ctx.r8.s64 = r11.s64 + -14;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x823b9fdc
	if (cr0.eq) goto loc_823B9FDC;
	// stw r9,-14(r11)
	PPC_STORE_U32(r11.u32 + -14, ctx.r9.u32);
	// stw r10,-10(r11)
	PPC_STORE_U32(r11.u32 + -10, ctx.r10.u32);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stw r10,14(r11)
	PPC_STORE_U32(r11.u32 + 14, ctx.r10.u32);
loc_823B9FDC:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x823b9fbc
	if (!cr0.eq) goto loc_823B9FBC;
loc_823B9FE8:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823B9F88) {
	__imp__sub_823B9F88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823B9FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823B9FFC) {
	__imp__sub_823B9FFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA000) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,-29112
	ctx.r10.s64 = r11.s64 + -29112;
	// addi r7,r3,12
	ctx.r7.s64 = ctx.r3.s64 + 12;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r10,19
	ctx.r10.s64 = 19;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// sth r9,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r9.u16);
	// sth r9,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r9.u16);
	// addi r8,r8,-29168
	ctx.r8.s64 = ctx.r8.s64 + -29168;
loc_823BA030:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x823ba030
	if (!cr0.lt) goto loc_823BA030;
	// stw r9,240(r7)
	PPC_STORE_U32(ctx.r7.u32 + 240, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BA000) {
	__imp__sub_823BA000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BA04C) {
	__imp__sub_823BA04C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA050) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r10,r11,-29112
	ctx.r10.s64 = r11.s64 + -29112;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823ba090
	if (cr6.eq) goto loc_823BA090;
	// bl 0x8217d890
	ctx.lr = 0x823BA084;
	sub_8217D890(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_823BA090:
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// li r10,19
	ctx.r10.s64 = 19;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r9,-29168
	ctx.r9.s64 = ctx.r9.s64 + -29168;
loc_823BA0A4:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x823ba0a4
	if (!cr0.lt) goto loc_823BA0A4;
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

PPC_WEAK_FUNC(sub_823BA050) {
	__imp__sub_823BA050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA0D0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// addi r10,r11,-29112
	ctx.r10.s64 = r11.s64 + -29112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lhz r5,10(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823b9bc8
	ctx.lr = 0x823BA108;
	sub_823B9BC8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// sth r10,8(r30)
	PPC_STORE_U16(r30.u32 + 8, ctx.r10.u16);
	// addi r11,r30,252
	r11.s64 = r30.s64 + 252;
	// sth r10,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r10.u16);
	// li r10,19
	ctx.r10.s64 = 19;
	// addi r9,r9,-29168
	ctx.r9.s64 = ctx.r9.s64 + -29168;
loc_823BA128:
	// addi r11,r11,-12
	r11.s64 = r11.s64 + -12;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x823ba128
	if (!cr0.lt) goto loc_823BA128;
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823ba150
	if (cr6.eq) goto loc_823BA150;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823b9bc8
	ctx.lr = 0x823BA150;
	sub_823B9BC8(ctx, base);
loc_823BA150:
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

PPC_WEAK_FUNC(sub_823BA0D0) {
	__imp__sub_823BA0D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823ba050
	sub_823BA050(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BA168) {
	__imp__sub_823BA168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA174) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BA174) {
	__imp__sub_823BA174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA178) {
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
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x823ba1b4
	if (cr6.eq) goto loc_823BA1B4;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823BA1A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823BA1B4:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823BA1C0;
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

PPC_WEAK_FUNC(sub_823BA178) {
	__imp__sub_823BA178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA1D0) {
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
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823ba20c
	if (cr6.eq) goto loc_823BA20C;
	// bctrl 
	ctx.lr = 0x823BA1FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823BA20C:
	// bctrl 
	ctx.lr = 0x823BA210;
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

PPC_WEAK_FUNC(sub_823BA1D0) {
	__imp__sub_823BA1D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA220) {
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
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x823ba260
	if (cr6.eq) goto loc_823BA260;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BA250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823BA260:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BA270;
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

PPC_WEAK_FUNC(sub_823BA220) {
	__imp__sub_823BA220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA280) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823ba2b8
	if (cr6.eq) goto loc_823BA2B8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x823ba2ec
	if (!cr6.eq) goto loc_823BA2EC;
	// bl 0x823ba1d0
	ctx.lr = 0x823BA2AC;
	sub_823BA1D0(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stb r3,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r3.u8);
	// b 0x823ba2e8
	goto loc_823BA2E8;
loc_823BA2B8:
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823ba2dc
	if (cr6.eq) goto loc_823BA2DC;
	// bctrl 
	ctx.lr = 0x823BA2D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823ba2e0
	goto loc_823BA2E0;
loc_823BA2DC:
	// bctrl 
	ctx.lr = 0x823BA2E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823BA2E0:
	// stfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// li r11,1
	r11.s64 = 1;
loc_823BA2E8:
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_823BA2EC:
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

PPC_WEAK_FUNC(sub_823BA280) {
	__imp__sub_823BA280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA300) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823ba358
	if (cr6.eq) goto loc_823BA358;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x823ba344
	if (cr6.eq) goto loc_823BA344;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x823ba390
	if (!cr6.eq) goto loc_823BA390;
	// lfs f1,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ba1d0
	ctx.lr = 0x823BA338;
	sub_823BA1D0(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stb r3,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r3.u8);
	// b 0x823ba38c
	goto loc_823BA38C;
loc_823BA344:
	// lbz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// bl 0x823ba178
	ctx.lr = 0x823BA34C;
	sub_823BA178(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stb r3,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r3.u8);
	// b 0x823ba38c
	goto loc_823BA38C;
loc_823BA358:
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// lfs f1,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823ba380
	if (cr6.eq) goto loc_823BA380;
	// bctrl 
	ctx.lr = 0x823BA37C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823ba384
	goto loc_823BA384;
loc_823BA380:
	// bctrl 
	ctx.lr = 0x823BA384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823BA384:
	// stfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// li r11,1
	r11.s64 = 1;
loc_823BA38C:
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_823BA390:
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

PPC_WEAK_FUNC(sub_823BA300) {
	__imp__sub_823BA300(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BA3A4) {
	__imp__sub_823BA3A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA3A8) {
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
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// beq cr6,0x823ba3ec
	if (cr6.eq) goto loc_823BA3EC;
	// cmpwi cr6,r10,7
	cr6.compare<int32_t>(ctx.r10.s32, 7, xer);
	// bne cr6,0x823ba428
	if (!cr6.eq) goto loc_823BA428;
	// lbz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 4);
	// lbz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// bl 0x823ba220
	ctx.lr = 0x823BA3E0;
	sub_823BA220(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stb r3,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r3.u8);
	// b 0x823ba424
	goto loc_823BA424;
loc_823BA3EC:
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823ba418
	if (cr6.eq) goto loc_823BA418;
	// bctrl 
	ctx.lr = 0x823BA414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823ba41c
	goto loc_823BA41C;
loc_823BA418:
	// bctrl 
	ctx.lr = 0x823BA41C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823BA41C:
	// stfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// li r11,1
	r11.s64 = 1;
loc_823BA424:
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_823BA428:
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

PPC_WEAK_FUNC(sub_823BA3A8) {
	__imp__sub_823BA3A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BA43C) {
	__imp__sub_823BA43C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA440) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// sth r10,12(r30)
	PPC_STORE_U16(r30.u32 + 12, ctx.r10.u16);
	// lhz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821c9650
	ctx.lr = 0x823BA47C;
	sub_821C9650(ctx, base);
	// addi r8,r31,16
	ctx.r8.s64 = r31.s64 + 16;
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// beq cr6,0x823ba4c4
	if (cr6.eq) goto loc_823BA4C4;
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// ble cr6,0x823ba4c4
	if (!cr6.gt) goto loc_823BA4C4;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_823BA4A8:
	// lbzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// blt cr6,0x823ba4a8
	if (cr6.lt) goto loc_823BA4A8;
loc_823BA4C4:
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

PPC_WEAK_FUNC(sub_823BA440) {
	__imp__sub_823BA440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA4E0) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ba6bc
	if (cr6.eq) goto loc_823BA6BC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x823b9b08
	ctx.lr = 0x823BA508;
	sub_823B9B08(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x823ba654
	if (cr6.lt) goto loc_823BA654;
	// beq cr6,0x823ba5b4
	if (cr6.eq) goto loc_823BA5B4;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x823ba6a4
	if (!cr6.lt) goto loc_823BA6A4;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r11,0
	r11.s64 = 0;
	// addi r7,r9,-29168
	ctx.r7.s64 = ctx.r9.s64 + -29168;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// blt cr6,0x823ba540
	if (cr6.lt) goto loc_823BA540;
	// li r11,1
	r11.s64 = 1;
loc_823BA540:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ba6bc
	if (cr6.eq) goto loc_823BA6BC;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r9,r31
	ctx.r6.u64 = ctx.r9.u64 + r31.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// bl 0x823ba3a8
	ctx.lr = 0x823BA594;
	sub_823BA3A8(ctx, base);
	// lwz r11,240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// stw r7,240(r31)
	PPC_STORE_U32(r31.u32 + 240, ctx.r7.u32);
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x823ba694
	goto loc_823BA694;
loc_823BA5B4:
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r11,0
	r11.s64 = 0;
	// addi r7,r9,-29168
	ctx.r7.s64 = ctx.r9.s64 + -29168;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// blt cr6,0x823ba5d8
	if (cr6.lt) goto loc_823BA5D8;
	// li r11,1
	r11.s64 = 1;
loc_823BA5D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ba6bc
	if (cr6.eq) goto loc_823BA6BC;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// bl 0x823ba300
	ctx.lr = 0x823BA610;
	sub_823BA300(ctx, base);
	// lwz r11,240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,240(r31)
	PPC_STORE_U32(r31.u32 + 240, ctx.r9.u32);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
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
loc_823BA654:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-29168
	ctx.r8.s64 = r11.s64 + -29168;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x823ba280
	ctx.lr = 0x823BA674;
	sub_823BA280(ctx, base);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// stw r7,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r7.u32);
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_823BA694:
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r4,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r4.u32);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
loc_823BA6A4:
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_823BA6BC:
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
}

PPC_WEAK_FUNC(sub_823BA4E0) {
	__imp__sub_823BA4E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA6D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BA6D4) {
	__imp__sub_823BA6D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA6D8) {
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
	ctx.lr = 0x823BA6E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823ba788
	if (!cr6.eq) goto loc_823BA788;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x823b9f88
	ctx.lr = 0x823BA708;
	sub_823B9F88(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ba744
	if (cr6.eq) goto loc_823BA744;
	// li r30,0
	r30.s64 = 0;
loc_823BA71C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r30,5,0,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x823ba440
	ctx.lr = 0x823BA730;
	sub_823BA440(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x823ba71c
	if (cr6.lt) goto loc_823BA71C;
loc_823BA744:
	// lhz r29,4(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x823ba77c
	if (!cr6.gt) goto loc_823BA77C;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_823BA758:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BA770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// bne 0x823ba758
	if (!cr0.eq) goto loc_823BA758;
loc_823BA77C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x823BA784;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_823BA788:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,5
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_823BA6D8) {
	__imp__sub_823BA6D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA7A8) {
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
	// bl 0x823ba0d0
	ctx.lr = 0x823BA7C8;
	sub_823BA0D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ba7e0
	if (cr6.eq) goto loc_823BA7E0;
	// bl 0x82130588
	ctx.lr = 0x823BA7DC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823BA7E0:
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

PPC_WEAK_FUNC(sub_823BA7A8) {
	__imp__sub_823BA7A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA7F8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bl 0x823ba6d8
	ctx.lr = 0x823BA818;
	sub_823BA6D8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ba440
	ctx.lr = 0x823BA820;
	sub_823BA440(ctx, base);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BA7F8) {
	__imp__sub_823BA7F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BA834) {
	__imp__sub_823BA834(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BA838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x823BA840;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r24,r11,-29164
	r24.s64 = r11.s64 + -29164;
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823bb2d0
	if (cr6.eq) goto loc_823BB2D0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r25,0
	r25.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// li r27,2
	r27.s64 = 2;
	// addi r26,r11,-29168
	r26.s64 = r11.s64 + -29168;
loc_823BA87C:
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r11,r11,-33
	r11.s64 = r11.s64 + -33;
	// cmplwi cr6,r11,91
	cr6.compare<uint32_t>(r11.u32, 91, xer);
	// bgt cr6,0x823bb2c0
	if (cr6.gt) goto loc_823BB2C0;
	// lis r12,-32196
	r12.s64 = -2109997056;
	// addi r12,r12,-22352
	r12.s64 = r12.s64 + -22352;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-20620(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -20620);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-21776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21776);
	// lwz r17,-21984(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21984);
	// lwz r17,-21840(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21840);
	// lwz r17,-21092(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21092);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-21396(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21396);
	// lwz r17,-21700(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21700);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-21548(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21548);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-21244(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -21244);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-20236(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -20236);
	// lwz r17,-19936(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19936);
	// lwz r17,-20504(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -20504);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-20820(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -20820);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-19776(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -19776);
	// lwz r17,-20956(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + -20956);
	// mr r29,r25
	r29.u64 = r25.u64;
loc_823BAA24:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df330
	ctx.lr = 0x823BAA30;
	sub_823DF330(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823baa48
	if (!cr6.eq) goto loc_823BAA48;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,95
	cr6.compare<uint32_t>(ctx.r10.u32, 95, xer);
	// bne cr6,0x823baa68
	if (!cr6.eq) goto loc_823BAA68;
loc_823BAA48:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r9,r1,736
	ctx.r9.s64 = ctx.r1.s64 + 736;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stbx r10,r29,r9
	PPC_STORE_U8(r29.u32 + ctx.r9.u32, ctx.r10.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,127
	cr6.compare<int32_t>(r29.s32, 127, xer);
	// blt cr6,0x823baa24
	if (cr6.lt) goto loc_823BAA24;
loc_823BAA68:
	// addi r11,r1,736
	r11.s64 = ctx.r1.s64 + 736;
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stbx r25,r29,r11
	PPC_STORE_U8(r29.u32 + r11.u32, r25.u8);
	// bl 0x823b9ef0
	ctx.lr = 0x823BAA7C;
	sub_823B9EF0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ba4e0
	ctx.lr = 0x823BAA88;
	sub_823BA4E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823bb2c0
	if (!cr6.eq) goto loc_823BB2C0;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,21
	cr6.compare<int32_t>(r11.s32, 21, xer);
	// bge cr6,0x823bb2c0
	if (!cr6.lt) goto loc_823BB2C0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x823BAAAC;
	sub_82130000(ctx, base);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823df2c8
	ctx.lr = 0x823BAAB8;
	sub_823DF2C8(ctx, base);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stfs f0,652(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 652, temp.u32);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r7,652(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 652);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// stw r8,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r8.u32);
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ddf20
	ctx.lr = 0x823BAAFC;
	sub_823DDF20(ctx, base);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r8,r3,-1
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stb r5,172(r1)
	PPC_STORE_U8(ctx.r1.u32 + 172, ctx.r5.u8);
	// lwz r3,172(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// stw r4,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r4.u32);
	// stw r27,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r27.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BAB4C;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + r11.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r5,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r5.u32);
	// lfs f0,460(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 460);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r9.u32);
	// lfs f13,204(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,716(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 716, temp.u32);
	// lwz r7,716(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r8.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BABE4;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + r11.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r5,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r5.u32);
	// lfs f0,236(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r8,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r8.u32);
	// lfs f13,492(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 492);
	ctx.f13.f64 = double(temp.f32);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stfs f12,268(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,268(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// stw r9,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r9.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BAC7C;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r8.u32);
	// lfs f0,620(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 620);
	f0.f64 = double(temp.f32);
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r8,-1
	ctx.r10.s64 = ctx.r8.s64 + -1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r5.u32);
	// lfs f13,300(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,524(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// lwz r10,524(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 524);
	// stw r4,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r4.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BAD14;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r8,-1
	ctx.r10.s64 = ctx.r8.s64 + -1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// stw r7,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r7.u32);
	// lfs f13,684(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 684);
	ctx.f13.f64 = double(temp.f32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r4,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r4.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,332(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	f0.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,364(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// lwz r9,364(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// stw r3,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r3.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BADAC;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r8.u32);
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r5.u32);
	// lbz r3,556(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 556);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bae14
	if (cr6.eq) goto loc_823BAE14;
	// lbz r9,396(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 396);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// bne cr6,0x823bae18
	if (!cr6.eq) goto loc_823BAE18;
loc_823BAE14:
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
loc_823BAE18:
	// stb r9,140(r1)
	PPC_STORE_U8(ctx.r1.u32 + 140, ctx.r9.u8);
	// lwz r8,140(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// b 0x823bb29c
	goto loc_823BB29C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BAE34;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r8.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r5.u32);
	// lbz r3,428(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 428);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bae9c
	if (!cr6.eq) goto loc_823BAE9C;
	// lbz r9,588(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 588);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823baea0
	if (cr6.eq) goto loc_823BAEA0;
loc_823BAE9C:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_823BAEA0:
	// stb r10,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r10.u8);
	// lwz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// b 0x823bb29c
	goto loc_823BB29C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r26,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// bl 0x823b9ea0
	ctx.lr = 0x823BAECC;
	sub_823B9EA0(ctx, base);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r8,r31,12
	ctx.r8.s64 = r31.s64 + 12;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bl 0x823b9b70
	ctx.lr = 0x823BAF3C;
	sub_823B9B70(ctx, base);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r26,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r26.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r9.u32);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BAF84;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r7,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r6,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r6.u32);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r27,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r27.u32);
	// lbz r3,188(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 188);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r9,220(r1)
	PPC_STORE_U8(ctx.r1.u32 + 220, ctx.r9.u8);
	// lwz r8,220(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// b 0x823bb2c0
	goto loc_823BB2C0;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// cmplwi cr6,r11,61
	cr6.compare<uint32_t>(r11.u32, 61, xer);
	// bne cr6,0x823bb07c
	if (!cr6.eq) goto loc_823BB07C;
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x823b9ea0
	ctx.lr = 0x823BB00C;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r8.u32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r5.u32);
	// lfs f0,252(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	f0.f64 = double(temp.f32);
	// lfs f13,284(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823bb070
	if (!cr6.lt) goto loc_823BB070;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
loc_823BB070:
	// stb r9,316(r1)
	PPC_STORE_U8(ctx.r1.u32 + 316, ctx.r9.u8);
	// lwz r8,316(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// b 0x823bb29c
	goto loc_823BB29C;
loc_823BB07C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BB084;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r8.u32);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lfs f0,348(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	f0.f64 = double(temp.f32);
	// stw r5,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r5.u32);
	// lfs f13,380(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823bb0e8
	if (cr6.gt) goto loc_823BB0E8;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_823BB0E8:
	// stb r10,412(r1)
	PPC_STORE_U8(ctx.r1.u32 + 412, ctx.r10.u8);
	// lwz r8,412(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// b 0x823bb29c
	goto loc_823BB29C;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// cmplwi cr6,r11,61
	cr6.compare<uint32_t>(r11.u32, 61, xer);
	// bne cr6,0x823bb188
	if (!cr6.eq) goto loc_823BB188;
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x823b9ea0
	ctx.lr = 0x823BB118;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r8.u32);
	// lfs f0,444(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	f0.f64 = double(temp.f32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r5.u32);
	// lfs f13,476(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 476);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823bb17c
	if (!cr6.gt) goto loc_823BB17C;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
loc_823BB17C:
	// stb r9,508(r1)
	PPC_STORE_U8(ctx.r1.u32 + 508, ctx.r9.u8);
	// lwz r8,508(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 508);
	// b 0x823bb29c
	goto loc_823BB29C;
loc_823BB188:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BB190;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, ctx.r8.u32);
	// lfs f0,540(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 540);
	f0.f64 = double(temp.f32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r5.u32);
	// lfs f13,572(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 572);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x823bb1f4
	if (cr6.lt) goto loc_823BB1F4;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_823BB1F4:
	// stb r10,604(r1)
	PPC_STORE_U8(ctx.r1.u32 + 604, ctx.r10.u8);
	// lwz r10,240(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 240);
	// lwz r6,604(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 604);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,240(r11)
	PPC_STORE_U32(r11.u32 + 240, ctx.r8.u32);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// b 0x823bb2bc
	goto loc_823BB2BC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9ea0
	ctx.lr = 0x823BB230;
	sub_823B9EA0(ctx, base);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r8.u32);
	// lfs f0,636(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 636);
	f0.f64 = double(temp.f32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 668, ctx.r5.u32);
	// lfs f13,668(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 668);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x823bb294
	if (cr6.eq) goto loc_823BB294;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_823BB294:
	// stb r10,700(r1)
	PPC_STORE_U8(ctx.r1.u32 + 700, ctx.r10.u8);
	// lwz r8,700(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 700);
loc_823BB29C:
	// lwz r10,240(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 240);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,240(r11)
	PPC_STORE_U32(r11.u32 + 240, ctx.r7.u32);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_823BB2BC:
	// stw r27,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r27.u32);
loc_823BB2C0:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ba87c
	if (!cr6.eq) goto loc_823BA87C;
loc_823BB2D0:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x823bb2e8
	if (!cr6.lt) goto loc_823BB2E8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x823BB2E8;
	sub_82130000(ctx, base);
loc_823BB2E8:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// ble cr6,0x823bb32c
	if (!cr6.gt) goto loc_823BB32C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-29108
	ctx.r3.s64 = r11.s64 + -29108;
	// bl 0x821bd618
	ctx.lr = 0x823BB32C;
	sub_821BD618(ctx, base);
loc_823BB32C:
	// lbz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 92);
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823BA838) {
	__imp__sub_823BA838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB338) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-27808
	ctx.r9.s64 = r11.s64 + -27808;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823bb36c
	if (cr6.eq) goto loc_823BB36C;
	// bl 0x82130588
	ctx.lr = 0x823BB368;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823BB36C:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BB338) {
	__imp__sub_823BB338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB380) {
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
	// lfs f0,48(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lfs f13,52(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lfs f12,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lfs f2,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x823BB3B8;
	sub_823DCDD8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,30288(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,12(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BB380) {
	__imp__sub_823BB380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB3E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stb r3,-11200(r11)
	PPC_STORE_U8(r11.u32 + -11200, ctx.r3.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB3E0) {
	__imp__sub_823BB3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB3EC) {
	__imp__sub_823BB3EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB3F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r10,-11200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11200);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB3F0) {
	__imp__sub_823BB3F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB408) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-11156
	ctx.r10.s64 = r11.s64 + -11156;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bb47c
	if (!cr6.eq) goto loc_823BB47C;
	// bl 0x82387a18
	ctx.lr = 0x823BB434;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bb47c
	if (!cr6.eq) goto loc_823BB47C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18444
	ctx.r10.s64 = r11.s64 + 18444;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bb47c
	if (!cr6.eq) goto loc_823BB47C;
	// lbz r11,3892(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3892);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bb474
	if (!cr6.eq) goto loc_823BB474;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11016
	ctx.r10.s64 = r11.s64 + -11016;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bb47c
	if (cr6.eq) goto loc_823BB47C;
loc_823BB474:
	// li r11,0
	r11.s64 = 0;
	// b 0x823bb480
	goto loc_823BB480;
loc_823BB47C:
	// li r11,1
	r11.s64 = 1;
loc_823BB480:
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

PPC_WEAK_FUNC(sub_823BB408) {
	__imp__sub_823BB408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB498) {
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
	// bl 0x82387a18
	ctx.lr = 0x823BB4B0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bb4c4
	if (!cr6.eq) goto loc_823BB4C4;
	// li r11,1
	r11.s64 = 1;
	// stb r11,305(r31)
	PPC_STORE_U8(r31.u32 + 305, r11.u8);
loc_823BB4C4:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BB498) {
	__imp__sub_823BB498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB4D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r10,304(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 304);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bb4ec
	if (cr6.eq) goto loc_823BB4EC;
	// stb r11,304(r3)
	PPC_STORE_U8(ctx.r3.u32 + 304, r11.u8);
loc_823BB4EC:
	// lbz r10,305(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 305);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bb50c
	if (cr6.eq) goto loc_823BB50C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r11,305(r3)
	PPC_STORE_U8(ctx.r3.u32 + 305, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,296(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// blr 
	return;
loc_823BB50C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,296(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB4D8) {
	__imp__sub_823BB4D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB51C) {
	__imp__sub_823BB51C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB520) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r31,r11,-11344
	r31.s64 = r11.s64 + -11344;
	// addi r4,r10,-27788
	ctx.r4.s64 = ctx.r10.s64 + -27788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BB548;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bb584
	if (cr6.eq) goto loc_823BB584;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-15860
	ctx.r4.s64 = r11.s64 + -15860;
	// bl 0x823d90b0
	ctx.lr = 0x823BB560;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bb584
	if (!cr6.eq) goto loc_823BB584;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-27796
	ctx.r4.s64 = r11.s64 + -27796;
	// bl 0x823d90b0
	ctx.lr = 0x823BB578;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x823bb588
	if (cr6.eq) goto loc_823BB588;
loc_823BB584:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823BB588:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BB520) {
	__imp__sub_823BB520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB59C) {
	__imp__sub_823BB59C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB5A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,292(r3)
	PPC_STORE_U8(ctx.r3.u32 + 292, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB5A0) {
	__imp__sub_823BB5A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB5AC) {
	__imp__sub_823BB5AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
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
	// stfs f1,224(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB5B0) {
	__imp__sub_823BB5B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB5E8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,10352
	r30.s64 = r11.s64 + 10352;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BB610;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bb638
	if (cr6.eq) goto loc_823BB638;
loc_823BB618:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x823bb638
	if (cr6.eq) goto loc_823BB638;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BB630;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bb618
	if (!cr6.eq) goto loc_823BB618;
loc_823BB638:
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

PPC_WEAK_FUNC(sub_823BB5E8) {
	__imp__sub_823BB5E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB654) {
	__imp__sub_823BB654(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-11344
	ctx.r3.s64 = r11.s64 + -11344;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB658) {
	__imp__sub_823BB658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB664) {
	__imp__sub_823BB664(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB668) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bb694
	if (cr6.eq) goto loc_823BB694;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823bb6a0
	if (!cr6.eq) goto loc_823BB6A0;
loc_823BB694:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-27772
	ctx.r3.s64 = r11.s64 + -27772;
	// bl 0x821bd618
	ctx.lr = 0x823BB6A0;
	sub_821BD618(ctx, base);
loc_823BB6A0:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bb6ec
	if (cr6.eq) goto loc_823BB6EC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bb6ec
	if (cr6.eq) goto loc_823BB6EC;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// bne cr6,0x823bb6cc
	if (!cr6.eq) goto loc_823BB6CC;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823BB6CC:
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bne cr6,0x823bb6e0
	if (!cr6.eq) goto loc_823BB6E0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_823BB6E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// bl 0x821f1d58
	ctx.lr = 0x823BB6EC;
	sub_821F1D58(ctx, base);
loc_823BB6EC:
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

PPC_WEAK_FUNC(sub_823BB668) {
	__imp__sub_823BB668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB704) {
	__imp__sub_823BB704(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB708) {
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
	// lwz r11,4032(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4032);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bne cr6,0x823bb790
	if (!cr6.eq) goto loc_823BB790;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bb790
	if (cr6.eq) goto loc_823BB790;
	// bl 0x82256058
	ctx.lr = 0x823BB738;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bb790
	if (cr6.eq) goto loc_823BB790;
	// lbz r11,3774(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3774);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bb790
	if (!cr6.eq) goto loc_823BB790;
	// lwz r30,3080(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 3080);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823bb790
	if (!cr6.gt) goto loc_823BB790;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
loc_823BB75C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823bb784
	if (!cr6.eq) goto loc_823BB784;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823bb780
	if (!cr6.eq) goto loc_823BB780;
	// bl 0x822a8fc0
	ctx.lr = 0x823BB77C;
	sub_822A8FC0(ctx, base);
	// b 0x823bb784
	goto loc_823BB784;
loc_823BB780:
	// bl 0x822a9040
	ctx.lr = 0x823BB784;
	sub_822A9040(ctx, base);
loc_823BB784:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// bne 0x823bb75c
	if (!cr0.eq) goto loc_823BB75C;
loc_823BB790:
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

PPC_WEAK_FUNC(sub_823BB708) {
	__imp__sub_823BB708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB7AC) {
	__imp__sub_823BB7AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB7B0) {
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
	// lwz r3,48(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bb800
	if (cr6.eq) goto loc_823BB800;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bb800
	if (cr6.eq) goto loc_823BB800;
	// lwz r11,592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823bb800
	if (cr6.eq) goto loc_823BB800;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x82331d18
	ctx.lr = 0x823BB7F4;
	sub_82331D18(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a4108
	ctx.lr = 0x823BB800;
	sub_822A4108(ctx, base);
loc_823BB800:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BB7B0) {
	__imp__sub_823BB7B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB814) {
	__imp__sub_823BB814(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB818) {
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
	ctx.lr = 0x823BB820;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x823bb868
	if (cr6.eq) goto loc_823BB868;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823bb864
	if (cr6.eq) goto loc_823BB864;
	// bl 0x821b5998
	ctx.lr = 0x823BB85C;
	sub_821B5998(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// b 0x823bb868
	goto loc_823BB868;
loc_823BB864:
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
loc_823BB868:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bb8b0
	if (cr6.eq) goto loc_823BB8B0;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_823BB878:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// sth r28,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r28.u16);
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823BB89C;
	sub_821C9650(ctx, base);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// clrlwi r31,r11,16
	r31.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// blt cr6,0x823bb878
	if (cr6.lt) goto loc_823BB878;
loc_823BB8B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BB818) {
	__imp__sub_823BB818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB8B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823BB8C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,1
	r29.s64 = 1;
	// addi r31,r3,28
	r31.s64 = ctx.r3.s64 + 28;
	// li r30,4
	r30.s64 = 4;
loc_823BB8D0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823bb8e4
	if (cr6.eq) goto loc_823BB8E4;
	// bl 0x823bb8b8
	ctx.lr = 0x823BB8E0;
	sub_823BB8B8(ctx, base);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
loc_823BB8E4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823bb8d0
	if (!cr0.eq) goto loc_823BB8D0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BB8B8) {
	__imp__sub_823BB8B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB8FC) {
	__imp__sub_823BB8FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823BB908;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r29,8(r3)
	r29.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r31,r3,28
	r31.s64 = ctx.r3.s64 + 28;
	// li r30,4
	r30.s64 = 4;
loc_823BB918:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823bb92c
	if (cr6.eq) goto loc_823BB92C;
	// bl 0x823bb900
	ctx.lr = 0x823BB928;
	sub_823BB900(ctx, base);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
loc_823BB92C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823bb918
	if (!cr0.eq) goto loc_823BB918;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BB900) {
	__imp__sub_823BB900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB944) {
	__imp__sub_823BB944(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB948) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// li r11,0
	r11.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, r11.u8);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f0,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f12,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fmuls f6,f11,f11
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f8,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f12,-12(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmadds f5,f9,f9,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fmadds f4,f7,f7,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f5.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f3,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f3
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fcmpu cr6,f4,f2
	cr6.compare(ctx.f4.f64, ctx.f2.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r10.u8);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB948) {
	__imp__sub_823BB948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BB9F4) {
	__imp__sub_823BB9F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BB9F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-11136
	ctx.r9.s64 = r11.s64 + -11136;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BB9F8) {
	__imp__sub_823BB9F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BBA1C) {
	__imp__sub_823BBA1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBA20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-11176
	ctx.r9.s64 = r11.s64 + -11176;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BBA20) {
	__imp__sub_823BBA20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BBA44) {
	__imp__sub_823BBA44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBA48) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x823bba7c
	if (!cr6.eq) goto loc_823BBA7C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// b 0x823bbadc
	goto loc_823BBADC;
loc_823BBA7C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BBA90;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de4d8
	ctx.lr = 0x823BBA98;
	sub_823DE4D8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27684
	ctx.r4.s64 = ctx.r10.s64 + -27684;
	// bl 0x823d90b0
	ctx.lr = 0x823BBAA8;
	sub_823D90B0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x823bbac4
	if (!cr6.eq) goto loc_823BBAC4;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// b 0x823bbae0
	goto loc_823BBAE0;
loc_823BBAC4:
	// stb r11,-1(r7)
	PPC_STORE_U8(ctx.r7.u32 + -1, r11.u8);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r10,-27696
	ctx.r5.s64 = ctx.r10.s64 + -27696;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x823BBADC;
	sub_82137A08(ctx, base);
loc_823BBADC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823BBAE0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

PPC_WEAK_FUNC(sub_823BBA48) {
	__imp__sub_823BBA48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBAF8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,328(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 328);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823bbb30
	if (!cr6.gt) goto loc_823BBB30;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f13,328(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 328, temp.u32);
loc_823BBB30:
	// lwz r3,268(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// bl 0x823d69e0
	ctx.lr = 0x823BBB38;
	sub_823D69E0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cdc90
	ctx.lr = 0x823BBB44;
	sub_823CDC90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bbb84
	if (cr6.eq) goto loc_823BBB84;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x823BBB64;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bbb84
	if (cr6.eq) goto loc_823BBB84;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x823BBB7C;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x823BBB84;
	sub_822A93A8(ctx, base);
loc_823BBB84:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BBAF8) {
	__imp__sub_823BBAF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBB98) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823BBBA0;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d8
	ctx.lr = 0x823BBBA8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10948(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10948);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bbbd8
	if (cr6.eq) goto loc_823BBBD8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x823BBBD4;
	// b 0x823d9238
	return;
loc_823BBBD8:
	// lwz r11,264(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r24,0
	r24.s64 = 0;
	// mr r25,r24
	r25.u64 = r24.u64;
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lfs f28,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f28.f64 = double(temp.f32);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fmr f31,f28
	f31.f64 = f28.f64;
	// fmr f29,f28
	f29.f64 = f28.f64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823bbd9c
	if (cr6.eq) goto loc_823BBD9C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r29,r24
	r29.u64 = r24.u64;
	// addi r28,r11,3148
	r28.s64 = r11.s64 + 3148;
	// addi r27,r10,3108
	r27.s64 = ctx.r10.s64 + 3108;
	// addi r26,r9,-14976
	r26.s64 = ctx.r9.s64 + -14976;
loc_823BBC24:
	// lwz r11,264(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r31,r10,r29
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bbcec
	if (cr6.eq) goto loc_823BBCEC;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823bbcec
	if (cr6.eq) goto loc_823BBCEC;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
loc_823BBC4C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x823bbc70
	if (cr6.eq) goto loc_823BBC70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823bbc4c
	if (cr6.eq) goto loc_823BBC4C;
loc_823BBC70:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823bbcec
	if (!cr6.eq) goto loc_823BBCEC;
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
	ctx.lr = 0x823BBC90;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bbcec
	if (cr6.eq) goto loc_823BBCEC;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,73
	cr6.compare<int32_t>(r11.s32, 73, xer);
	// bne cr6,0x823bbcc0
	if (!cr6.eq) goto loc_823BBCC0;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x823bbcb8
	if (cr6.lt) goto loc_823BBCB8;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823bbcec
	if (!cr6.gt) goto loc_823BBCEC;
loc_823BBCB8:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// b 0x823bbcec
	goto loc_823BBCEC;
loc_823BBCC0:
	// cmpwi cr6,r11,72
	cr6.compare<int32_t>(r11.s32, 72, xer);
	// beq cr6,0x823bbcd0
	if (cr6.eq) goto loc_823BBCD0;
	// cmpwi cr6,r11,58
	cr6.compare<int32_t>(r11.s32, 58, xer);
	// bne cr6,0x823bbcec
	if (!cr6.eq) goto loc_823BBCEC;
loc_823BBCD0:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x823bbce4
	if (cr6.lt) goto loc_823BBCE4;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823bbcec
	if (!cr6.gt) goto loc_823BBCEC;
loc_823BBCE4:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// fmr f29,f0
	f29.f64 = f0.f64;
loc_823BBCEC:
	// lwz r11,264(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpw cr6,r25,r10
	cr6.compare<int32_t>(r25.s32, ctx.r10.s32, xer);
	// blt cr6,0x823bbc24
	if (cr6.lt) goto loc_823BBC24;
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// ble cr6,0x823bbd9c
	if (!cr6.gt) goto loc_823BBD9C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// bl 0x821f6238
	ctx.lr = 0x823BBD18;
	sub_821F6238(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x823BBD24;
	sub_821F15C8(ctx, base);
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// stw r24,344(r30)
	PPC_STORE_U32(r30.u32 + 344, r24.u32);
	// stb r24,341(r30)
	PPC_STORE_U8(r30.u32 + 341, r24.u8);
	// stw r24,348(r30)
	PPC_STORE_U32(r30.u32 + 348, r24.u32);
	// stw r24,352(r30)
	PPC_STORE_U32(r30.u32 + 352, r24.u32);
	// stb r24,356(r30)
	PPC_STORE_U8(r30.u32 + 356, r24.u8);
	// bne cr6,0x823bbd78
	if (!cr6.eq) goto loc_823BBD78;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823bbd78
	if (!cr6.eq) goto loc_823BBD78;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,319(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 319);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823bbd74
	if (!cr6.eq) goto loc_823BBD74;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823BBD74:
	// bl 0x823cc200
	ctx.lr = 0x823BBD78;
	sub_823CC200(ctx, base);
loc_823BBD78:
	// lwz r11,268(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 268);
	// lfs f0,364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 364);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f1,f12,f30,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : ctx.f13.f64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x823BBD98;
	// b 0x823d9238
	return;
loc_823BBD9C:
	// lbz r11,319(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 319);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bbdd4
	if (cr6.eq) goto loc_823BBDD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,319(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 319);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bne cr6,0x823bbdd0
	if (!cr6.eq) goto loc_823BBDD0;
	// li r5,0
	ctx.r5.s64 = 0;
loc_823BBDD0:
	// bl 0x823cc200
	ctx.lr = 0x823BBDD4;
	sub_823CC200(ctx, base);
loc_823BBDD4:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x823BBDE4;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823BBB98) {
	__imp__sub_823BBB98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBDE8) {
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
	ctx.lr = 0x823BBDF0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r11,r25,114
	r11.s64 = r25.s64 + 114;
	// li r24,0
	r24.s64 = 0;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r24
	r30.u64 = r24.u64;
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x823bbe5c
	if (!cr6.gt) goto loc_823BBE5C;
	// mulli r11,r25,120
	r11.s64 = r25.s64 * 120;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// addi r31,r11,468
	r31.s64 = r11.s64 + 468;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_823BBE2C:
	// lwz r23,0(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,-4960(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4960);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x823c98b0
	ctx.lr = 0x823BBE3C;
	sub_823C98B0(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-27432(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -27432);
	// bl 0x823d48d0
	ctx.lr = 0x823BBE48;
	sub_823D48D0(ctx, base);
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x823bbe2c
	if (cr6.lt) goto loc_823BBE2C;
loc_823BBE5C:
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// stwx r24,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r24.u32);
	// bne cr6,0x823bbe74
	if (!cr6.eq) goto loc_823BBE74;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// stb r24,389(r11)
	PPC_STORE_U8(r11.u32 + 389, r24.u8);
loc_823BBE74:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_823BBDE8) {
	__imp__sub_823BBDE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BBE7C) {
	__imp__sub_823BBE7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBE80) {
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
	ctx.lr = 0x823BBE88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,3812
	r30.s64 = 3812;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_823BBE94:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bbecc
	if (!cr6.gt) goto loc_823BBECC;
	// bl 0x822a86d8
	ctx.lr = 0x823BBEA8;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bbecc
	if (cr6.eq) goto loc_823BBECC;
	// bl 0x822a86e8
	ctx.lr = 0x823BBEB8;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bbecc
	if (cr6.eq) goto loc_823BBECC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a84c8
	ctx.lr = 0x823BBECC;
	sub_822A84C8(ctx, base);
loc_823BBECC:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,3876
	cr6.compare<int32_t>(r30.s32, 3876, xer);
	// blt cr6,0x823bbe94
	if (cr6.lt) goto loc_823BBE94;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BBE80) {
	__imp__sub_823BBE80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBEE0) {
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
	ctx.lr = 0x823BBEE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,3812
	r30.s64 = 3812;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_823BBEF8:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bbf34
	if (!cr6.gt) goto loc_823BBF34;
	// bl 0x822a86d8
	ctx.lr = 0x823BBF0C;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bbf34
	if (cr6.eq) goto loc_823BBF34;
	// bl 0x822a86e8
	ctx.lr = 0x823BBF1C;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bbf34
	if (cr6.eq) goto loc_823BBF34;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822aacf0
	ctx.lr = 0x823BBF34;
	sub_822AACF0(ctx, base);
loc_823BBF34:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,3876
	cr6.compare<int32_t>(r30.s32, 3876, xer);
	// blt cr6,0x823bbef8
	if (cr6.lt) goto loc_823BBEF8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BBEE0) {
	__imp__sub_823BBEE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBF48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,304(r11)
	PPC_STORE_U8(r11.u32 + 304, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BBF48) {
	__imp__sub_823BBF48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BBF5C) {
	__imp__sub_823BBF5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBF60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// b 0x823cc1c0
	sub_823CC1C0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BBF60) {
	__imp__sub_823BBF60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BBF6C) {
	__imp__sub_823BBF6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBF70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r3,288(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 288);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BBF70) {
	__imp__sub_823BBF70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBF80) {
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
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bbfdc
	if (cr6.eq) goto loc_823BBFDC;
	// lbz r11,288(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 288);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bbfc4
	if (!cr6.eq) goto loc_823BBFC4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cc1c0
	ctx.lr = 0x823BBFB4;
	sub_823CC1C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bbfc8
	if (cr6.eq) goto loc_823BBFC8;
loc_823BBFC4:
	// li r11,1
	r11.s64 = 1;
loc_823BBFC8:
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
loc_823BBFDC:
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

PPC_WEAK_FUNC(sub_823BBF80) {
	__imp__sub_823BBF80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BBFF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r3,341(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 341);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BBFF0) {
	__imp__sub_823BBFF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC000) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-12012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// lwz r9,344(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 344);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x823bc09c
	if (cr6.eq) goto loc_823BC09C;
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc050
	if (cr6.eq) goto loc_823BC050;
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823bc054
	if (!cr6.eq) goto loc_823BC054;
loc_823BC050:
	// li r11,0
	r11.s64 = 0;
loc_823BC054:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc074
	if (cr6.eq) goto loc_823BC074;
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// lbz r9,467(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 467);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823bc078
	if (!cr6.eq) goto loc_823BC078;
loc_823BC074:
	// li r11,0
	r11.s64 = 0;
loc_823BC078:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc09c
	if (cr6.eq) goto loc_823BC09C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x823BC094;
	sub_821F1498(ctx, base);
	// lwz r3,-12012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r10,-10000(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823BC09C:
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc0c8
	if (cr6.eq) goto loc_823BC0C8;
	// lwz r10,344(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 344);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x823bc0c8
	if (!cr6.eq) goto loc_823BC0C8;
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// lwz r10,420(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823bc0cc
	if (cr6.eq) goto loc_823BC0CC;
loc_823BC0C8:
	// li r11,0
	r11.s64 = 0;
loc_823BC0CC:
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

PPC_WEAK_FUNC(sub_823BC000) {
	__imp__sub_823BC000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC0E8) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r10,291(r11)
	PPC_STORE_U8(r11.u32 + 291, ctx.r10.u8);
	// lwz r3,-10008(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10008);
	// bl 0x823ce420
	ctx.lr = 0x823BC11C;
	sub_823CE420(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823bc14c
	if (cr6.eq) goto loc_823BC14C;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,290(r11)
	PPC_STORE_U8(r11.u32 + 290, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823BC14C:
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

PPC_WEAK_FUNC(sub_823BC0E8) {
	__imp__sub_823BC0E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC164) {
	__imp__sub_823BC164(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r3,289(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 289);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BC168) {
	__imp__sub_823BC168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC178) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,289(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 289);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bc19c
	if (cr6.eq) goto loc_823BC19C;
	// lbz r11,292(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 292);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823bc1a0
	if (cr6.eq) goto loc_823BC1A0;
loc_823BC19C:
	// li r11,0
	r11.s64 = 0;
loc_823BC1A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BC178) {
	__imp__sub_823BC178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC1A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,293(r3)
	PPC_STORE_U8(ctx.r3.u32 + 293, r11.u8);
	// stb r10,291(r3)
	PPC_STORE_U8(ctx.r3.u32 + 291, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BC1A8) {
	__imp__sub_823BC1A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC1BC) {
	__imp__sub_823BC1BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC1C0) {
	PPC_FUNC_PROLOGUE();
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r3,r10,-27672
	ctx.r3.s64 = ctx.r10.s64 + -27672;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lfs f1,84(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// lfs f3,328(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 328);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,324(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 324);
	ctx.f2.f64 = double(temp.f32);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x823BC210;
	sub_82130000(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 324);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x823bc24c
	if (cr6.lt) goto loc_823BC24C;
	// lfs f12,328(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 328);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fsel f1,f10,f13,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823BC24C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BC1C0) {
	__imp__sub_823BC1C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC268) {
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
	ctx.lr = 0x823BC270;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823c9a40
	ctx.lr = 0x823BC28C;
	sub_823C9A40(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x823bc2c4
	if (cr6.eq) goto loc_823BC2C4;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823bc2e0
	if (!cr6.gt) goto loc_823BC2E0;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x823bc2d4
	goto loc_823BC2D4;
loc_823BC2C4:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823bc2e0
	if (!cr6.gt) goto loc_823BC2E0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_823BC2D4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823bc2e4
	if (!cr6.eq) goto loc_823BC2E4;
loc_823BC2E0:
	// li r11,0
	r11.s64 = 0;
loc_823BC2E4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc300
	if (cr6.eq) goto loc_823BC300;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x823BC2F8;
	sub_822A3998(ctx, base);
	// bl 0x822a7d90
	ctx.lr = 0x823BC2FC;
	sub_822A7D90(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_823BC300:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc324
	if (cr6.eq) goto loc_823BC324;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823c9aa0
	ctx.lr = 0x823BC318;
	sub_823C9AA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc324
	if (cr6.eq) goto loc_823BC324;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_823BC324:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823bc338
	if (cr6.eq) goto loc_823BC338;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823BC338:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BC268) {
	__imp__sub_823BC268(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC344) {
	__imp__sub_823BC344(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC348) {
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
	ctx.lr = 0x823BC350;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823c9a70
	ctx.lr = 0x823BC36C;
	sub_823C9A70(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x823bc3a4
	if (cr6.eq) goto loc_823BC3A4;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823bc3c0
	if (!cr6.gt) goto loc_823BC3C0;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x823bc3b4
	goto loc_823BC3B4;
loc_823BC3A4:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823bc3c0
	if (!cr6.gt) goto loc_823BC3C0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_823BC3B4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823bc3c4
	if (!cr6.eq) goto loc_823BC3C4;
loc_823BC3C0:
	// li r11,0
	r11.s64 = 0;
loc_823BC3C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc3e0
	if (cr6.eq) goto loc_823BC3E0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x823BC3D8;
	sub_822A3998(ctx, base);
	// bl 0x822a7d90
	ctx.lr = 0x823BC3DC;
	sub_822A7D90(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_823BC3E0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc404
	if (cr6.eq) goto loc_823BC404;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823c9ad0
	ctx.lr = 0x823BC3F8;
	sub_823C9AD0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc404
	if (cr6.eq) goto loc_823BC404;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_823BC404:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823bc418
	if (cr6.eq) goto loc_823BC418;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823BC418:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BC348) {
	__imp__sub_823BC348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC424) {
	__imp__sub_823BC424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r7,17892(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// lbzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_823BC444:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823bc454
	if (cr6.eq) goto loc_823BC454;
	// lwz r11,804(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 804);
	// b 0x823bc458
	goto loc_823BC458;
loc_823BC454:
	// lwz r11,400(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 400);
loc_823BC458:
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x823bc4d8
	if (!cr6.lt) goto loc_823BC4D8;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823bc470
	if (cr6.eq) goto loc_823BC470;
	// lwz r11,404(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 404);
	// b 0x823bc474
	goto loc_823BC474;
loc_823BC470:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
loc_823BC474:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc4c4
	if (cr6.eq) goto loc_823BC4C4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823bc48c
	if (cr6.eq) goto loc_823BC48C;
	// lwz r11,404(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 404);
	// b 0x823bc490
	goto loc_823BC490;
loc_823BC48C:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
loc_823BC490:
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823BC498:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x823bc4bc
	if (cr6.eq) goto loc_823BC4BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823bc498
	if (cr6.eq) goto loc_823BC498;
loc_823BC4BC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823bc4d0
	if (cr6.eq) goto loc_823BC4D0;
loc_823BC4C4:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// b 0x823bc444
	goto loc_823BC444;
loc_823BC4D0:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_823BC4D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BC428) {
	__imp__sub_823BC428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC4E0) {
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
	ctx.lr = 0x823BC4E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823bb520
	ctx.lr = 0x823BC4F8;
	sub_823BB520(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc594
	if (cr6.eq) goto loc_823BC594;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x823bc594
	if (!cr6.eq) goto loc_823BC594;
	// bl 0x82256058
	ctx.lr = 0x823BC514;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc594
	if (cr6.eq) goto loc_823BC594;
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823bc594
	if (cr0.eq) goto loc_823BC594;
	// lwz r11,3144(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823bc588
	if (!cr6.eq) goto loc_823BC588;
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lbz r10,317(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 317);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// bne cr6,0x823bc590
	if (!cr6.eq) goto loc_823BC590;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r3,r11,2608
	ctx.r3.s64 = r11.s64 + 2608;
	// sth r10,2612(r11)
	PPC_STORE_U16(r11.u32 + 2612, ctx.r10.u16);
	// beq cr6,0x823bc594
	if (cr6.eq) goto loc_823BC594;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823BC560:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823bc560
	if (!cr6.eq) goto loc_823BC560;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823BC584;
	sub_821C9650(ctx, base);
	// b 0x823bc594
	goto loc_823BC594;
loc_823BC588:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
loc_823BC590:
	// lwz r31,2608(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 2608);
loc_823BC594:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// rlwinm r30,r30,6,0,25
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// addi r5,r10,-27568
	ctx.r5.s64 = ctx.r10.s64 + -27568;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r11,1232
	ctx.r3.s64 = r11.s64 + 1232;
	// bl 0x82137a08
	ctx.lr = 0x823BC5B8;
	sub_82137A08(ctx, base);
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r9,9572
	ctx.r5.s64 = ctx.r9.s64 + 9572;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r11,2512
	ctx.r3.s64 = r11.s64 + 2512;
	// bl 0x82137a08
	ctx.lr = 0x823BC5D8;
	sub_82137A08(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BC4E0) {
	__imp__sub_823BC4E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC5E0) {
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
	// bl 0x823bbf80
	ctx.lr = 0x823BC5F0;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc610
	if (cr6.eq) goto loc_823BC610;
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
loc_823BC610:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r3,334(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 334);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BC5E0) {
	__imp__sub_823BC5E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC62C) {
	__imp__sub_823BC62C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC630) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,319(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 319);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r3,335(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 335);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BC630) {
	__imp__sub_823BC630(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC650) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823BC670;
	sub_823D6478(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc6c4
	if (cr6.eq) goto loc_823BC6C4;
	// bl 0x823d45e8
	ctx.lr = 0x823BC67C;
	sub_823D45E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc6c4
	if (cr6.eq) goto loc_823BC6C4;
	// lwz r31,84(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bc6c4
	if (cr6.eq) goto loc_823BC6C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8233f010
	ctx.lr = 0x823BC698;
	sub_8233F010(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bc6c4
	if (!cr6.eq) goto loc_823BC6C4;
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,2154(r31)
	PPC_STORE_U8(r31.u32 + 2154, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823BC6C4:
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

PPC_WEAK_FUNC(sub_823BC650) {
	__imp__sub_823BC650(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC6DC) {
	__imp__sub_823BC6DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC6E0) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823BC700;
	sub_823D6478(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc754
	if (cr6.eq) goto loc_823BC754;
	// bl 0x823d45e8
	ctx.lr = 0x823BC70C;
	sub_823D45E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc754
	if (cr6.eq) goto loc_823BC754;
	// lwz r31,84(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bc754
	if (cr6.eq) goto loc_823BC754;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8233f010
	ctx.lr = 0x823BC728;
	sub_8233F010(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bc754
	if (!cr6.eq) goto loc_823BC754;
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,2153(r31)
	PPC_STORE_U8(r31.u32 + 2153, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823BC754:
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

PPC_WEAK_FUNC(sub_823BC6E0) {
	__imp__sub_823BC6E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BC76C) {
	__imp__sub_823BC76C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC770) {
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
	// addi r10,r3,953
	ctx.r10.s64 = ctx.r3.s64 + 953;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bc7c8
	if (!cr6.gt) goto loc_823BC7C8;
	// bl 0x822a86d8
	ctx.lr = 0x823BC7A4;
	sub_822A86D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc7c8
	if (cr6.eq) goto loc_823BC7C8;
	// bl 0x822a8f80
	ctx.lr = 0x823BC7B0;
	sub_822A8F80(ctx, base);
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
loc_823BC7C8:
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

PPC_WEAK_FUNC(sub_823BC770) {
	__imp__sub_823BC770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC7E0) {
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
	// addi r10,r3,953
	ctx.r10.s64 = ctx.r3.s64 + 953;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bc838
	if (!cr6.gt) goto loc_823BC838;
	// bl 0x822a86d8
	ctx.lr = 0x823BC814;
	sub_822A86D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc838
	if (cr6.eq) goto loc_823BC838;
	// bl 0x822a8f70
	ctx.lr = 0x823BC820;
	sub_822A8F70(ctx, base);
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
loc_823BC838:
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

PPC_WEAK_FUNC(sub_823BC7E0) {
	__imp__sub_823BC7E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC850) {
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
	// addi r10,r3,953
	ctx.r10.s64 = ctx.r3.s64 + 953;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bc8a8
	if (!cr6.gt) goto loc_823BC8A8;
	// bl 0x822a86d8
	ctx.lr = 0x823BC884;
	sub_822A86D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc8a8
	if (cr6.eq) goto loc_823BC8A8;
	// bl 0x822a8f60
	ctx.lr = 0x823BC890;
	sub_822A8F60(ctx, base);
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
loc_823BC8A8:
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

PPC_WEAK_FUNC(sub_823BC850) {
	__imp__sub_823BC850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC8C0) {
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
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d6478
	ctx.lr = 0x823BC8E0;
	sub_823D6478(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc920
	if (cr6.eq) goto loc_823BC920;
	// bl 0x823d45e8
	ctx.lr = 0x823BC8EC;
	sub_823D45E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc920
	if (cr6.eq) goto loc_823BC920;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bc920
	if (cr6.eq) goto loc_823BC920;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823BC920:
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

PPC_WEAK_FUNC(sub_823BC8C0) {
	__imp__sub_823BC8C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC938) {
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
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r3,336(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// bl 0x822a86d8
	ctx.lr = 0x823BC964;
	sub_822A86D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc980
	if (cr6.eq) goto loc_823BC980;
loc_823BC96C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86d8
	ctx.lr = 0x823BC978;
	sub_822A86D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bc96c
	if (!cr6.eq) goto loc_823BC96C;
loc_823BC980:
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

PPC_WEAK_FUNC(sub_823BC938) {
	__imp__sub_823BC938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BC998) {
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
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bc9cc
	if (cr6.eq) goto loc_823BC9CC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823bca0c
	goto loc_823BCA0C;
loc_823BC9CC:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,3896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bc9e8
	if (cr6.eq) goto loc_823BC9E8;
	// bl 0x821f5e80
	ctx.lr = 0x823BC9E4;
	sub_821F5E80(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823BC9E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3896
	ctx.r4.s64 = r11.s64 + 3896;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f62a8
	ctx.lr = 0x823BC9F8;
	sub_821F62A8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r11,3896(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
loc_823BCA0C:
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

PPC_WEAK_FUNC(sub_823BC998) {
	__imp__sub_823BC998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCA24) {
	__imp__sub_823BCA24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCA28) {
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
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bca5c
	if (cr6.eq) goto loc_823BCA5C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823bca9c
	goto loc_823BCA9C;
loc_823BCA5C:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,3900(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3900);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bca78
	if (cr6.eq) goto loc_823BCA78;
	// bl 0x821f5e80
	ctx.lr = 0x823BCA74;
	sub_821F5E80(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
loc_823BCA78:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,3900
	ctx.r4.s64 = r11.s64 + 3900;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f62a8
	ctx.lr = 0x823BCA88;
	sub_821F62A8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r11,3900(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3900);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
loc_823BCA9C:
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

PPC_WEAK_FUNC(sub_823BCA28) {
	__imp__sub_823BCA28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCAB4) {
	__imp__sub_823BCAB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCAB8) {
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
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bcae8
	if (cr6.eq) goto loc_823BCAE8;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823bcb2c
	goto loc_823BCB2C;
loc_823BCAE8:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r30,1
	r30.s64 = 1;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r3,3896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bcb0c
	if (cr6.eq) goto loc_823BCB0C;
	// bl 0x821f5bf0
	ctx.lr = 0x823BCB04;
	sub_821F5BF0(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// clrlwi r30,r3,31
	r30.u64 = ctx.r3.u32 & 0x1;
loc_823BCB0C:
	// lwz r3,3900(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3900);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bcb28
	if (cr6.eq) goto loc_823BCB28;
	// bl 0x821f5bf0
	ctx.lr = 0x823BCB1C;
	sub_821F5BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_823BCB28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823BCB2C:
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

PPC_WEAK_FUNC(sub_823BCAB8) {
	__imp__sub_823BCAB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCB44) {
	__imp__sub_823BCB44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCB48) {
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
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bcba8
	if (!cr6.eq) goto loc_823BCBA8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r4,r11,-27404
	ctx.r4.s64 = r11.s64 + -27404;
	// addi r3,r10,-11344
	ctx.r3.s64 = ctx.r10.s64 + -11344;
	// bl 0x823d90b0
	ctx.lr = 0x823BCB7C;
	sub_823D90B0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bcb94
	if (!cr6.eq) goto loc_823BCB94;
	// lwz r10,-10000(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,3892(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3892, ctx.r9.u8);
loc_823BCB94:
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r3,3896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bcbbc
	if (cr6.eq) goto loc_823BCBBC;
	// bl 0x821f5aa0
	ctx.lr = 0x823BCBA8;
	sub_821F5AA0(ctx, base);
loc_823BCBA8:
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
loc_823BCBBC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-27468
	ctx.r3.s64 = r11.s64 + -27468;
	// bl 0x82130000
	ctx.lr = 0x823BCBC8;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_823BCB48) {
	__imp__sub_823BCB48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCBDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCBDC) {
	__imp__sub_823BCBDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCBE0) {
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
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bcc24
	if (!cr6.eq) goto loc_823BCC24;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stb r9,3892(r11)
	PPC_STORE_U8(r11.u32 + 3892, ctx.r9.u8);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// lwz r3,3900(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3900);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bcc38
	if (cr6.eq) goto loc_823BCC38;
	// bl 0x821f5aa0
	ctx.lr = 0x823BCC24;
	sub_821F5AA0(ctx, base);
loc_823BCC24:
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
loc_823BCC38:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-27392
	ctx.r3.s64 = r11.s64 + -27392;
	// bl 0x82130000
	ctx.lr = 0x823BCC44;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_823BCBE0) {
	__imp__sub_823BCBE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCC58) {
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
	ctx.lr = 0x823BCC60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r28,r10,-11472
	r28.s64 = ctx.r10.s64 + -11472;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_823BCC78:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x823bcc9c
	if (cr6.eq) goto loc_823BCC9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823bcc78
	if (cr6.eq) goto loc_823BCC78;
loc_823BCC9C:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823bccb4
	if (!cr6.eq) goto loc_823BCCB4;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r29,317(r11)
	PPC_STORE_U8(r11.u32 + 317, r29.u8);
loc_823BCCB4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x823BCCC4;
	sub_82137A08(ctx, base);
	// addi r3,r28,128
	ctx.r3.s64 = r28.s64 + 128;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x823BCCD4;
	sub_82137A08(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-27324
	ctx.r3.s64 = r11.s64 + -27324;
	// bl 0x82130000
	ctx.lr = 0x823BCCE4;
	sub_82130000(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r29,288(r11)
	PPC_STORE_U8(r11.u32 + 288, r29.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r10,316(r11)
	PPC_STORE_U8(r11.u32 + 316, ctx.r10.u8);
	// lwz r11,-5008(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -5008);
	// sth r10,2612(r11)
	PPC_STORE_U16(r11.u32 + 2612, ctx.r10.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BCC58) {
	__imp__sub_823BCC58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCD0C) {
	__imp__sub_823BCD0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCD10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,-1
	ctx.r8.s64 = -1;
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f1,296(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 296, temp.u32);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stfs f0,308(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 308, temp.u32);
	// addi r10,r11,308
	ctx.r10.s64 = r11.s64 + 308;
	// stw r8,312(r11)
	PPC_STORE_U32(r11.u32 + 312, ctx.r8.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BCD10) {
	__imp__sub_823BCD10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCD3C) {
	__imp__sub_823BCD3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCD40) {
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
	ctx.lr = 0x823BCD48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,1
	r30.s64 = 1;
	// addi r29,r3,3876
	r29.s64 = ctx.r3.s64 + 3876;
	// li r31,3812
	r31.s64 = 3812;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_823BCD5C:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bcdac
	if (cr6.eq) goto loc_823BCDAC;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bcdac
	if (!cr6.gt) goto loc_823BCDAC;
	// bl 0x822a86d8
	ctx.lr = 0x823BCD7C;
	sub_822A86D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bcdac
	if (cr6.eq) goto loc_823BCDAC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bcda4
	if (cr6.eq) goto loc_823BCDA4;
	// bl 0x822aa928
	ctx.lr = 0x823BCD94;
	sub_822AA928(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823bcda8
	if (!cr6.eq) goto loc_823BCDA8;
loc_823BCDA4:
	// li r11,0
	r11.s64 = 0;
loc_823BCDA8:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_823BCDAC:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r31,3820
	cr6.compare<int32_t>(r31.s32, 3820, xer);
	// blt cr6,0x823bcd5c
	if (cr6.lt) goto loc_823BCD5C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BCD40) {
	__imp__sub_823BCD40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCDC8) {
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
	ctx.lr = 0x823BCDD0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r3,3876
	r29.s64 = ctx.r3.s64 + 3876;
	// li r30,3812
	r30.s64 = 3812;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lfs f31,32692(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32692);
	f31.f64 = double(temp.f32);
loc_823BCDEC:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bce68
	if (cr6.eq) goto loc_823BCE68;
	// lwz r11,-10000(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bce68
	if (!cr6.gt) goto loc_823BCE68;
	// bl 0x822a86d8
	ctx.lr = 0x823BCE0C;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bce68
	if (cr6.eq) goto loc_823BCE68;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822aa900
	ctx.lr = 0x823BCE20;
	sub_822AA900(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8a88
	ctx.lr = 0x823BCE28;
	sub_822A8A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bce68
	if (cr6.eq) goto loc_823BCE68;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bce68
	if (cr6.eq) goto loc_823BCE68;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bce68
	if (cr6.eq) goto loc_823BCE68;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823bce68
	if (cr6.eq) goto loc_823BCE68;
	// lfs f0,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,40(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// stfs f13,36(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
loc_823BCE68:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r30,3876
	cr6.compare<int32_t>(r30.s32, 3876, xer);
	// blt cr6,0x823bcdec
	if (cr6.lt) goto loc_823BCDEC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BCDC8) {
	__imp__sub_823BCDC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BCE84) {
	__imp__sub_823BCE84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCE88) {
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
	ctx.lr = 0x823BCE90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r28,1
	r28.s64 = 1;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823bceb0
	if (cr6.eq) goto loc_823BCEB0;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x823bcf4c
	if (!cr6.eq) goto loc_823BCF4C;
loc_823BCEB0:
	// addi r11,r30,953
	r11.s64 = r30.s64 + 953;
	// lwz r10,-10000(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bcf4c
	if (!cr6.gt) goto loc_823BCF4C;
	// bl 0x822a86d8
	ctx.lr = 0x823BCECC;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bcf4c
	if (cr6.eq) goto loc_823BCF4C;
	// bl 0x822a86e8
	ctx.lr = 0x823BCEDC;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bcf4c
	if (cr6.eq) goto loc_823BCF4C;
	// lbz r11,178(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 178);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bcf0c
	if (!cr6.eq) goto loc_823BCF0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82224ac8
	ctx.lr = 0x823BCEFC;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x823bcf10
	if (cr6.eq) goto loc_823BCF10;
loc_823BCF0C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823BCF10:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bcf4c
	if (!cr6.eq) goto loc_823BCF4C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BCF30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-27288
	ctx.r3.s64 = ctx.r9.s64 + -27288;
	// bl 0x82130000
	ctx.lr = 0x823BCF40;
	sub_82130000(ctx, base);
	// stb r28,178(r31)
	PPC_STORE_U8(r31.u32 + 178, r28.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822aed58
	ctx.lr = 0x823BCF4C;
	sub_822AED58(ctx, base);
loc_823BCF4C:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stb r28,3876(r11)
	PPC_STORE_U8(r11.u32 + 3876, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BCE88) {
	__imp__sub_823BCE88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCF60) {
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
	ctx.lr = 0x823BCF68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,3812
	r30.s64 = 3812;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r28,r11,-27196
	r28.s64 = r11.s64 + -27196;
loc_823BCF7C:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bcfd4
	if (!cr6.gt) goto loc_823BCFD4;
	// bl 0x822a86d8
	ctx.lr = 0x823BCF90;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bcfd4
	if (cr6.eq) goto loc_823BCFD4;
	// bl 0x822a86e8
	ctx.lr = 0x823BCFA0;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bcfd4
	if (cr6.eq) goto loc_823BCFD4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8d98
	ctx.lr = 0x823BCFB4;
	sub_822A8D98(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bcfd4
	if (cr6.eq) goto loc_823BCFD4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8d98
	ctx.lr = 0x823BCFC4;
	sub_822A8D98(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BCFCC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bcfec
	if (!cr6.eq) goto loc_823BCFEC;
loc_823BCFD4:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,3820
	cr6.compare<int32_t>(r30.s32, 3820, xer);
	// blt cr6,0x823bcf7c
	if (cr6.lt) goto loc_823BCF7C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823BCFEC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BCF60) {
	__imp__sub_823BCF60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BCFF8) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-11344
	r31.s64 = r11.s64 + -11344;
	// addi r4,r10,10352
	ctx.r4.s64 = ctx.r10.s64 + 10352;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BD028;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bd034
	if (cr6.eq) goto loc_823BD034;
	// addi r30,r3,1
	r30.s64 = ctx.r3.s64 + 1;
loc_823BD034:
	// bl 0x82178880
	ctx.lr = 0x823BD038;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd050
	if (cr6.eq) goto loc_823BD050;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,-19684
	ctx.r5.s64 = r11.s64 + -19684;
	// b 0x823bd058
	goto loc_823BD058;
loc_823BD050:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,-19700
	ctx.r5.s64 = r11.s64 + -19700;
loc_823BD058:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BD068;
	sub_82137A08(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-25460
	ctx.r4.s64 = r11.s64 + -25460;
	// bl 0x821f97f0
	ctx.lr = 0x823BD078;
	sub_821F97F0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stw r30,404(r11)
	PPC_STORE_U32(r11.u32 + 404, r30.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

PPC_WEAK_FUNC(sub_823BCFF8) {
	__imp__sub_823BCFF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD0A0) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bd160
	if (cr6.eq) goto loc_823BD160;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823BD0C4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823bd0c4
	if (!cr6.eq) goto loc_823BD0C4;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bd160
	if (cr6.eq) goto loc_823BD160;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11116
	ctx.r10.s64 = r11.s64 + -11116;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bd160
	if (!cr6.eq) goto loc_823BD160;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r10,-27180
	ctx.r4.s64 = ctx.r10.s64 + -27180;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x823BD114;
	sub_821CA540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bb5e8
	ctx.lr = 0x823BD11C;
	sub_823BB5E8(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r6,r9,-27184
	ctx.r6.s64 = ctx.r9.s64 + -27184;
	// addi r5,r8,-27188
	ctx.r5.s64 = ctx.r8.s64 + -27188;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BD13C;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ca778
	ctx.lr = 0x823BD14C;
	sub_821CA778(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823BD158;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x823bd164
	goto loc_823BD164;
loc_823BD160:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823BD164:
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

PPC_WEAK_FUNC(sub_823BD0A0) {
	__imp__sub_823BD0A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BD17C) {
	__imp__sub_823BD17C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD180) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11116
	ctx.r10.s64 = r11.s64 + -11116;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd1bc
	if (cr6.eq) goto loc_823BD1BC;
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
loc_823BD1BC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-11344
	r31.s64 = r11.s64 + -11344;
	// addi r4,r10,10352
	ctx.r4.s64 = ctx.r10.s64 + 10352;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BD1D4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bd1e0
	if (cr6.eq) goto loc_823BD1E0;
	// addi r31,r3,1
	r31.s64 = ctx.r3.s64 + 1;
loc_823BD1E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bd0a0
	ctx.lr = 0x823BD1E8;
	sub_823BD0A0(ctx, base);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BD180) {
	__imp__sub_823BD180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BD1FC) {
	__imp__sub_823BD1FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD200) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd224
	if (cr6.eq) goto loc_823BD224;
	// lwz r10,376(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r8,372(r3)
	PPC_STORE_U32(ctx.r3.u32 + 372, ctx.r8.u32);
	// stw r11,380(r3)
	PPC_STORE_U32(ctx.r3.u32 + 380, r11.u32);
	// stw r10,384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 384, ctx.r10.u32);
loc_823BD224:
	// lwz r11,388(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd244
	if (cr6.eq) goto loc_823BD244;
	// lwz r10,392(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r8,388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 388, ctx.r8.u32);
	// stw r11,396(r3)
	PPC_STORE_U32(ctx.r3.u32 + 396, r11.u32);
	// stw r10,400(r3)
	PPC_STORE_U32(ctx.r3.u32 + 400, ctx.r10.u32);
loc_823BD244:
	// lwz r11,404(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd264
	if (cr6.eq) goto loc_823BD264;
	// lwz r10,408(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r8,404(r3)
	PPC_STORE_U32(ctx.r3.u32 + 404, ctx.r8.u32);
	// stw r11,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, r11.u32);
	// stw r10,416(r3)
	PPC_STORE_U32(ctx.r3.u32 + 416, ctx.r10.u32);
loc_823BD264:
	// lwz r10,420(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bgt cr6,0x823bd278
	if (cr6.gt) goto loc_823BD278;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_823BD278:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r9,-1
	ctx.r9.s64 = -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd290
	if (cr6.eq) goto loc_823BD290;
	// stw r10,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r10.u32);
	// stw r9,420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 420, ctx.r9.u32);
loc_823BD290:
	// lwz r10,428(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bgt cr6,0x823bd2a4
	if (cr6.gt) goto loc_823BD2A4;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_823BD2A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd2b8
	if (cr6.eq) goto loc_823BD2B8;
	// stw r10,432(r3)
	PPC_STORE_U32(ctx.r3.u32 + 432, ctx.r10.u32);
	// stw r9,428(r3)
	PPC_STORE_U32(ctx.r3.u32 + 428, ctx.r9.u32);
loc_823BD2B8:
	// lwz r10,436(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 436);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bgt cr6,0x823bd2cc
	if (cr6.gt) goto loc_823BD2CC;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_823BD2CC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd2e0
	if (cr6.eq) goto loc_823BD2E0;
	// stw r10,440(r3)
	PPC_STORE_U32(ctx.r3.u32 + 440, ctx.r10.u32);
	// stw r9,436(r3)
	PPC_STORE_U32(ctx.r3.u32 + 436, ctx.r9.u32);
loc_823BD2E0:
	// lbz r11,444(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 444);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd2f8
	if (cr6.eq) goto loc_823BD2F8;
	// li r11,1
	r11.s64 = 1;
	// stb r8,444(r3)
	PPC_STORE_U8(ctx.r3.u32 + 444, ctx.r8.u8);
	// stb r11,445(r3)
	PPC_STORE_U8(ctx.r3.u32 + 445, r11.u8);
loc_823BD2F8:
	// lwz r11,448(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// stw r11,452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 452, r11.u32);
	// stw r9,448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 448, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BD200) {
	__imp__sub_823BD200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD310) {
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
	ctx.lr = 0x823BD318;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r10,-12012(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r11,2260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd358
	if (cr6.eq) goto loc_823BD358;
	// lwz r9,344(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 344);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823bd358
	if (!cr6.eq) goto loc_823BD358;
	// lwz r11,2256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// lwz r9,420(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823bd35c
	if (cr6.eq) goto loc_823BD35C;
loc_823BD358:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823BD35C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd428
	if (cr6.eq) goto loc_823BD428;
	// lwz r3,348(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bd428
	if (cr6.eq) goto loc_823BD428;
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd428
	if (cr6.eq) goto loc_823BD428;
	// lbz r11,356(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 356);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd3c0
	if (cr6.eq) goto loc_823BD3C0;
	// bl 0x822a86e8
	ctx.lr = 0x823BD390;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd3bc
	if (cr6.eq) goto loc_823BD3BC;
	// lwz r3,352(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// bl 0x822a86e8
	ctx.lr = 0x823BD3A4;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd3bc
	if (cr6.eq) goto loc_823BD3BC;
	// lwz r4,348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lwz r3,352(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// bl 0x823bb668
	ctx.lr = 0x823BD3BC;
	sub_823BB668(ctx, base);
loc_823BD3BC:
	// lwz r10,-12012(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -12012);
loc_823BD3C0:
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lwz r11,348(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 348);
	// lwz r8,352(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32213
	ctx.r6.s64 = -2111111168;
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// addi r4,r9,-28496
	ctx.r4.s64 = ctx.r9.s64 + -28496;
	// addi r3,r7,-28512
	ctx.r3.s64 = ctx.r7.s64 + -28512;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r9,r6,-28496
	ctx.r9.s64 = ctx.r6.s64 + -28496;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r5,r5,-28512
	ctx.r5.s64 = ctx.r5.s64 + -28512;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// bl 0x821f0f18
	ctx.lr = 0x823BD420;
	sub_821F0F18(ctx, base);
	// lwz r3,-12012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// bl 0x821f2a60
	ctx.lr = 0x823BD428;
	sub_821F2A60(ctx, base);
loc_823BD428:
	// stb r29,341(r31)
	PPC_STORE_U8(r31.u32 + 341, r29.u8);
	// stw r29,344(r31)
	PPC_STORE_U32(r31.u32 + 344, r29.u32);
	// stw r29,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r29.u32);
	// stw r29,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r29.u32);
	// stb r29,356(r31)
	PPC_STORE_U8(r31.u32 + 356, r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BD310) {
	__imp__sub_823BD310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BD444) {
	__imp__sub_823BD444(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD448) {
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
	ctx.lr = 0x823BD450;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bd5b8
	if (!cr6.eq) goto loc_823BD5B8;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r11,344(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bd5b8
	if (!cr6.eq) goto loc_823BD5B8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bd4ac
	if (!cr6.eq) goto loc_823BD4AC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-11344
	ctx.r4.s64 = r11.s64 + -11344;
	// addi r3,r10,-27144
	ctx.r3.s64 = ctx.r10.s64 + -27144;
	// bl 0x82130000
	ctx.lr = 0x823BD4A4;
	sub_82130000(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823BD4AC:
	// lis r28,-32111
	r28.s64 = -2104426496;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-27288(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -27288);
	// bl 0x821f2060
	ctx.lr = 0x823BD4BC;
	sub_821F2060(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823bd5b8
	if (cr6.eq) goto loc_823BD5B8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r6,r29,144
	ctx.r6.s64 = r29.s64 + 144;
	// bne cr6,0x823bd4e0
	if (!cr6.eq) goto loc_823BD4E0;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
loc_823BD4E0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823bd4ec
	if (cr6.eq) goto loc_823BD4EC;
	// addi r5,r27,144
	ctx.r5.s64 = r27.s64 + 144;
loc_823BD4EC:
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r3,-27288(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -27288);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821f3440
	ctx.lr = 0x823BD504;
	sub_821F3440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd5b8
	if (cr6.eq) goto loc_823BD5B8;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r30,344(r11)
	PPC_STORE_U32(r11.u32 + 344, r30.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r10,341(r11)
	PPC_STORE_U8(r11.u32 + 341, ctx.r10.u8);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stw r27,352(r11)
	PPC_STORE_U32(r11.u32 + 352, r27.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stw r29,348(r11)
	PPC_STORE_U32(r11.u32 + 348, r29.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// stb r26,356(r11)
	PPC_STORE_U8(r11.u32 + 356, r26.u8);
	// lwz r3,-12012(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12012);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r8,2260(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// lwz r7,344(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// beq cr6,0x823bd5b8
	if (cr6.eq) goto loc_823BD5B8;
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd574
	if (cr6.eq) goto loc_823BD574;
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823bd578
	if (!cr6.eq) goto loc_823BD578;
loc_823BD574:
	// li r11,0
	r11.s64 = 0;
loc_823BD578:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd598
	if (cr6.eq) goto loc_823BD598;
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// lbz r10,467(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 467);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823bd59c
	if (!cr6.eq) goto loc_823BD59C;
loc_823BD598:
	// li r11,0
	r11.s64 = 0;
loc_823BD59C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd5b8
	if (cr6.eq) goto loc_823BD5B8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x823BD5B8;
	sub_821F1498(ctx, base);
loc_823BD5B8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823BD448) {
	__imp__sub_823BD448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BD5C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x823BD5C8;
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823db9c4
	ctx.lr = 0x823BD5D0;
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-6736(r1)
	ea = -6736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lfs f25,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f25.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,0
	r28.s64 = 0;
	// lfs f23,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f23.f64 = double(temp.f32);
	// lis r6,6
	ctx.r6.s64 = 393216;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f27,-31400(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31400);
	f27.f64 = double(temp.f32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f24,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	f24.f64 = double(temp.f32);
	// lfs f29,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f29.f64 = double(temp.f32);
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// stfs f25,96(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// stfs f23,204(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// mr r25,r28
	r25.u64 = r28.u64;
	// fmr f28,f23
	f28.f64 = f23.f64;
	// li r26,-32
	r26.s64 = -32;
	// li r27,-16
	r27.s64 = -16;
	// ori r23,r6,16704
	r23.u64 = ctx.r6.u64 | 16704;
	// lis r21,-32121
	r21.s64 = -2105081856;
	// addi r20,r11,2256
	r20.s64 = r11.s64 + 2256;
	// addi r24,r10,-26984
	r24.s64 = ctx.r10.s64 + -26984;
loc_823BD65C:
	// fcmpu cr6,f28,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f26.f64);
	// bge cr6,0x823bd778
	if (!cr6.lt) goto loc_823BD778;
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,127
	ctx.r10.s64 = 127;
	// stfs f28,204(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r11,r1,416
	r11.s64 = ctx.r1.s64 + 416;
loc_823BD674:
	// stvx128 v63,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// stfs f29,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stb r28,12(r11)
	PPC_STORE_U8(r11.u32 + 12, r28.u8);
	// stfs f29,8(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bge 0x823bd674
	if (!cr0.lt) goto loc_823BD674;
	// lwz r11,-10012(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10012);
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// fmr f30,f27
	f30.f64 = f27.f64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// add r3,r11,r23
	ctx.r3.u64 = r11.u64 + r23.u64;
	// bl 0x82249e78
	ctx.lr = 0x823BD6B4;
	sub_82249E78(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x823bd76c
	if (!cr6.gt) goto loc_823BD76C;
	// addi r31,r1,420
	r31.s64 = ctx.r1.s64 + 420;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_823BD6C4:
	// lwz r30,-4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82245340
	ctx.lr = 0x823BD6D0;
	sub_82245340(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bd760
	if (cr6.eq) goto loc_823BD760;
	// lfs f5,-32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + -32);
	ctx.f5.f64 = double(temp.f32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lfs f0,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	f0.f64 = double(temp.f32);
	// fsubs f13,f5,f0
	ctx.f13.f64 = double(float(ctx.f5.f64 - f0.f64));
	// lfs f8,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,-28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -28);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f0
	ctx.f2.f64 = f0.f64;
	// lfs f4,-36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -36);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// stfd f6,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f6.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f5,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f5.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f4,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f4.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// fmadds f31,f13,f13,f8
	f31.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f8.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// stfd f7,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f7.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// bl 0x82130000
	ctx.lr = 0x823BD748;
	sub_82130000(ctx, base);
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x823bd760
	if (!cr6.lt) goto loc_823BD760;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f30,f31
	f30.f64 = f31.f64;
	// bl 0x82245340
	ctx.lr = 0x823BD75C;
	sub_82245340(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_823BD760:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// bne 0x823bd6c4
	if (!cr0.eq) goto loc_823BD6C4;
loc_823BD76C:
	// fadds f28,f28,f24
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(f28.f64 + f24.f64));
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823bd65c
	if (cr6.eq) goto loc_823BD65C;
loc_823BD778:
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r28.u32);
	// beq cr6,0x823bdd74
	if (cr6.eq) goto loc_823BDD74;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8224e3c8
	ctx.lr = 0x823BD798;
	sub_8224E3C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823bdd74
	if (cr6.eq) goto loc_823BDD74;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BD7BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f29,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f29,116(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lfs f28,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f28.f64 = double(temp.f32);
	// stfs f28,112(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f1,31292(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x823BD7E8;
	sub_82165300(ctx, base);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r10,r1,136
	ctx.r10.s64 = ctx.r1.s64 + 136;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// addi r9,r1,132
	ctx.r9.s64 = ctx.r1.s64 + 132;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8224e480
	ctx.lr = 0x823BD814;
	sub_8224E480(ctx, base);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r31,r28
	r31.u64 = r28.u64;
	// fmr f31,f25
	ctx.fpscr.disableFlushMode();
	f31.f64 = f25.f64;
	// fmr f30,f25
	f30.f64 = f25.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd87c
	if (cr6.eq) goto loc_823BD87C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823BD848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f0,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fmadds f7,f13,f8,f9
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f9.f64));
	// fmadds f31,f12,f11,f7
	f31.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f7.f64));
loc_823BD87C:
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823bd8cc
	if (cr6.eq) goto loc_823BD8CC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f1,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BD8A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lfs f12,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f30,f12,f8,f7
	f30.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64));
loc_823BD8CC:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// blt cr6,0x823bd8e8
	if (cr6.lt) goto loc_823BD8E8;
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// bge cr6,0x823bd8e8
	if (!cr6.lt) goto loc_823BD8E8;
	// lfs f0,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// b 0x823bda34
	goto loc_823BDA34;
loc_823BD8E8:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x823bd8f8
	if (!cr6.lt) goto loc_823BD8F8;
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// bge cr6,0x823bda2c
	if (!cr6.lt) goto loc_823BDA2C;
loc_823BD8F8:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// blt cr6,0x823bd984
	if (cr6.lt) goto loc_823BD984;
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// blt cr6,0x823bd984
	if (cr6.lt) goto loc_823BD984;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lfs f1,23884(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 23884);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c890
	ctx.lr = 0x823BD944;
	sub_8216C890(ctx, base);
	// lfs f0,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	f0.f64 = double(temp.f32);
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f29
	cr6.compare(ctx.f6.f64, f29.f64);
	// ble cr6,0x823bd978
	if (!cr6.gt) goto loc_823BD978;
	// lwz r31,132(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// b 0x823bda30
	goto loc_823BDA30;
loc_823BD978:
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// lwz r31,100(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// b 0x823bda34
	goto loc_823BDA34;
loc_823BD984:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x823bdd74
	if (!cr6.lt) goto loc_823BDD74;
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// bge cr6,0x823bdd74
	if (!cr6.lt) goto loc_823BDD74;
	// fmr f13,f25
	ctx.f13.f64 = f25.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bd9e0
	if (cr6.eq) goto loc_823BD9E0;
	// lfs f0,4(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// lfs f13,228(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,8(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,232(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,0(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,224(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f13,f6,f6,f4
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// b 0x823bd9e4
	goto loc_823BD9E4;
loc_823BD9E0:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
loc_823BD9E4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823bda38
	if (cr6.eq) goto loc_823BDA38;
	// fcmpu cr6,f13,f25
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f25.f64);
	// beq cr6,0x823bda2c
	if (cr6.eq) goto loc_823BDA2C;
	// lfs f12,4(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,244(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f9,8(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfs f6,0(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fmuls f3,f10,f10
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f2,f7,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f13
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x823bda38
	if (!cr6.lt) goto loc_823BDA38;
loc_823BDA2C:
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_823BDA30:
	// lfs f0,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
loc_823BDA34:
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_823BDA38:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bdd74
	if (cr6.eq) goto loc_823BDD74;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x823bda5c
	if (!cr6.lt) goto loc_823BDA5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f31.f64 = double(temp.f32);
	// b 0x823bda64
	goto loc_823BDA64;
loc_823BDA5C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f31,-15876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15876);
	f31.f64 = double(temp.f32);
loc_823BDA64:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r1,208
	r30.s64 = ctx.r1.s64 + 208;
	// fmr f27,f0
	ctx.fpscr.disableFlushMode();
	f27.f64 = f0.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BDA80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x825868f0
	ctx.lr = 0x823BDA94;
	sub_825868F0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r11,-10012(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10012);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// add r3,r11,r23
	ctx.r3.u64 = r11.u64 + r23.u64;
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// stfs f29,148(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f24,156(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x8224a078
	ctx.lr = 0x823BDACC;
	sub_8224A078(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bdba0
	if (cr6.eq) goto loc_823BDBA0;
loc_823BDAD4:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f12,f31,f0
	ctx.f12.f64 = double(float(f31.f64 + f0.f64));
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// fsel f11,f12,f12,f29
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fsubs f10,f11,f28
	ctx.f10.f64 = double(float(ctx.f11.f64 - f28.f64));
	// fsel f0,f10,f28,f11
	f0.f64 = ctx.f10.f64 >= 0.0 ? f28.f64 : ctx.f11.f64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x823bdba4
	if (cr6.eq) goto loc_823BDBA4;
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// beq cr6,0x823bdba4
	if (cr6.eq) goto loc_823BDBA4;
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// ble cr6,0x823bdb18
	if (!cr6.gt) goto loc_823BDB18;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bgt cr6,0x823bdb18
	if (cr6.gt) goto loc_823BDB18;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x823bdba4
	if (cr6.gt) goto loc_823BDBA4;
loc_823BDB18:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x823bdb30
	if (!cr6.lt) goto loc_823BDB30;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// blt cr6,0x823bdb30
	if (cr6.lt) goto loc_823BDB30;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// blt cr6,0x823bdba4
	if (cr6.lt) goto loc_823BDBA4;
loc_823BDB30:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r1,208
	r30.s64 = ctx.r1.s64 + 208;
	// fmr f27,f0
	ctx.fpscr.disableFlushMode();
	f27.f64 = f0.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BDB4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x825868f0
	ctx.lr = 0x823BDB60;
	sub_825868F0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r11,-10012(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -10012);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// add r3,r11,r23
	ctx.r3.u64 = r11.u64 + r23.u64;
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f24,156(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f0,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x8224a078
	ctx.lr = 0x823BDB98;
	sub_8224A078(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bdad4
	if (!cr6.eq) goto loc_823BDAD4;
loc_823BDBA0:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
loc_823BDBA4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r1,208
	r30.s64 = ctx.r1.s64 + 208;
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BDBC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x825868f0
	ctx.lr = 0x823BDBD4;
	sub_825868F0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r3,r7,-27016
	ctx.r3.s64 = ctx.r7.s64 + -27016;
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// lfs f3,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x823BDC14;
	sub_82130000(ctx, base);
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32114
	ctx.r4.s64 = -2104623104;
	// lfs f13,260(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// addi r31,r1,320
	r31.s64 = ctx.r1.s64 + 320;
	// lfs f0,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	f0.f64 = double(temp.f32);
	// addi r30,r1,336
	r30.s64 = ctx.r1.s64 + 336;
	// stfs f29,352(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stfs f29,356(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// lwz r3,-23452(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -23452);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r6,364(r1)
	PPC_STORE_U16(ctx.r1.u32 + 364, ctx.r6.u16);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r28,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r28.u32);
	// li r7,2048
	ctx.r7.s64 = 2048;
	// sth r28,366(r1)
	PPC_STORE_U16(ctx.r1.u32 + 366, r28.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r28,368(r1)
	PPC_STORE_U8(ctx.r1.u32 + 368, r28.u8);
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// sth r28,370(r1)
	PPC_STORE_U16(ctx.r1.u32 + 370, r28.u16);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// stw r28,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r28.u32);
	// fsubs f11,f0,f23
	ctx.f11.f64 = double(float(f0.f64 - f23.f64));
	// stfs f11,276(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// fadds f12,f13,f23
	ctx.f12.f64 = double(float(ctx.f13.f64 + f23.f64));
	// stfs f12,260(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x823BDCA8;
	sub_82574418(ctx, base);
	// lwz r5,288(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823bdd74
	if (cr6.eq) goto loc_823BDD74;
	// lfs f2,216(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,208(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x823BDCC0;
	sub_823DCDD8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14980(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14980);
	f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x823bdcfc
	if (!cr6.lt) goto loc_823BDCFC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// lfd f2,3432(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + 3432);
	// bl 0x823dc100
	ctx.lr = 0x823BDCE8;
	sub_823DC100(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,18204(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18204);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// b 0x823bdd20
	goto loc_823BDD20;
loc_823BDCFC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,18204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x823bdd20
	if (!cr6.gt) goto loc_823BDD20;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfd f2,3432(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + 3432);
	// bl 0x823dc100
	ctx.lr = 0x823BDD1C;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
loc_823BDD20:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r3,r9,-27052
	ctx.r3.s64 = ctx.r9.s64 + -27052;
	// lfs f13,30288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30288);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,0(r18)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r18.u32 + 0, temp.u32);
	// stvx128 v55,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,4(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,8(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x823BDD6C;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823bdd78
	goto loc_823BDD78;
loc_823BDD74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823BDD78:
	// addi r1,r1,6736
	ctx.r1.s64 = ctx.r1.s64 + 6736;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823dba10
	ctx.lr = 0x823BDD8C;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_823BD5C0) {
	__imp__sub_823BD5C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDD90) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x823BDDB4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bddec
	if (cr6.eq) goto loc_823BDDEC;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bddec
	if (cr6.eq) goto loc_823BDDEC;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823BDDEC:
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

PPC_WEAK_FUNC(sub_823BDD90) {
	__imp__sub_823BDD90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BDE04) {
	__imp__sub_823BDE04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDE08) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x823BDE2C;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bdea4
	if (cr6.eq) goto loc_823BDEA4;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bdea4
	if (cr6.eq) goto loc_823BDEA4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x823bb380
	ctx.lr = 0x823BDE5C;
	sub_823BB380(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,8
	ctx.r7.s64 = r31.s64 + 8;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// stw r4,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r4.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
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
loc_823BDEA4:
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
}

PPC_WEAK_FUNC(sub_823BDE08) {
	__imp__sub_823BDE08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BDEBC) {
	__imp__sub_823BDEBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDEC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// std r3,232(r11)
	PPC_STORE_U64(r11.u32 + 232, ctx.r3.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BDEC0) {
	__imp__sub_823BDEC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDED0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x823BDEF4;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823bdf24
	if (!cr6.gt) goto loc_823BDF24;
	// addi r11,r3,10
	r11.s64 = ctx.r3.s64 + 10;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823BDF04:
	// addic. r9,r11,-10
	xer.ca = r11.u32 > 9;
	ctx.r9.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823bdf18
	if (cr0.eq) goto loc_823BDF18;
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
loc_823BDF18:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x823bdf04
	if (!cr0.eq) goto loc_823BDF04;
loc_823BDF24:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BDED0) {
	__imp__sub_823BDED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDF38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
loc_823BDF38:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 + 28;
loc_823BDF40:
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bdfb4
	if (cr6.eq) goto loc_823BDFB4;
	// lfs f12,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	f0.f64 = double(temp.f32);
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f11,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x823bdfa4
	if (!cr6.lt) goto loc_823BDFA4;
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f10,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// bge cr6,0x823bdfa4
	if (!cr6.lt) goto loc_823BDFA4;
	// fadds f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 + ctx.f12.f64));
	// lfs f11,60(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 60);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// ble cr6,0x823bdfa4
	if (!cr6.gt) goto loc_823BDFA4;
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f13,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823bdfa8
	if (cr6.gt) goto loc_823BDFA8;
loc_823BDFA4:
	// li r11,0
	r11.s64 = 0;
loc_823BDFA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bdfc0
	if (!cr6.eq) goto loc_823BDFC0;
loc_823BDFB4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// b 0x823bdf40
	goto loc_823BDF40;
loc_823BDFC0:
	// addi r11,r9,7
	r11.s64 = ctx.r9.s64 + 7;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// b 0x823bdf38
	goto loc_823BDF38;
}

PPC_WEAK_FUNC(sub_823BDF38) {
	__imp__sub_823BDF38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDFD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BDFD0) {
	__imp__sub_823BDFD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BDFD4) {
	__imp__sub_823BDFD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BDFD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823be018
	if (cr6.eq) goto loc_823BE018;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823be00c
	if (!cr6.eq) goto loc_823BE00C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823be00c
	if (!cr6.eq) goto loc_823BE00C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823be010
	if (!cr6.eq) goto loc_823BE010;
loc_823BE00C:
	// li r11,1
	r11.s64 = 1;
loc_823BE010:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_823BE018:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BDFD8) {
	__imp__sub_823BDFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823BE028;
	// lhz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823be05c
	if (cr6.eq) goto loc_823BE05C;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_823BE040:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lhz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x823be040
	if (cr6.lt) goto loc_823BE040;
loc_823BE05C:
	// lhz r11,16(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823be0f8
	if (cr6.eq) goto loc_823BE0F8;
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// ori r6,r9,64167
	ctx.r6.u64 = ctx.r9.u64 | 64167;
	// addi r10,r10,2176
	ctx.r10.s64 = ctx.r10.s64 + 2176;
loc_823BE080:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mulld r7,r4,r6
	ctx.r7.s64 = ctx.r4.s64 * ctx.r6.s64;
	// lhz r31,16(r3)
	r31.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// twllei r31,0
	// clrlwi r4,r9,1
	ctx.r4.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// divw r30,r4,r31
	r30.s32 = ctx.r4.s32 / r31.s32;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// mullw r7,r30,r31
	ctx.r7.s64 = int64_t(r30.s32) * int64_t(r31.s32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwzx r29,r11,r30
	r29.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// subf r7,r7,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r7.s64;
	// rotlwi r9,r4,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r7,r31,r9
	ctx.r7.u64 = r31.u64 & ~ctx.r9.u64;
	// lwzx r9,r4,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + r30.u32);
	// twlgei r7,-1
	// stwx r9,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stwx r29,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, r29.u32);
	// lhz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// blt cr6,0x823be080
	if (cr6.lt) goto loc_823BE080;
loc_823BE0F8:
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BE020) {
	__imp__sub_823BE020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE100) {
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
	ctx.lr = 0x823BE108;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,1
	r29.s64 = 1;
	// li r30,4
	r30.s64 = 4;
	// addi r31,r11,28
	r31.s64 = r11.s64 + 28;
loc_823BE11C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823be130
	if (cr6.eq) goto loc_823BE130;
	// bl 0x823bb8b8
	ctx.lr = 0x823BE12C;
	sub_823BB8B8(ctx, base);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
loc_823BE130:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823be11c
	if (!cr0.eq) goto loc_823BE11C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BE100) {
	__imp__sub_823BE100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE148) {
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
	ctx.lr = 0x823BE150;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r30,4
	r30.s64 = 4;
	// addi r31,r11,28
	r31.s64 = r11.s64 + 28;
	// lhz r29,8(r11)
	r29.u64 = PPC_LOAD_U16(r11.u32 + 8);
loc_823BE164:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823be178
	if (cr6.eq) goto loc_823BE178;
	// bl 0x823bb900
	ctx.lr = 0x823BE174;
	sub_823BB900(ctx, base);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
loc_823BE178:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823be164
	if (!cr0.eq) goto loc_823BE164;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BE148) {
	__imp__sub_823BE148(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE190) {
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
	ctx.lr = 0x823BE198;
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
	// bne cr6,0x823be244
	if (!cr6.eq) goto loc_823BE244;
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
	ctx.lr = 0x823BE1D0;
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
	// bl 0x823b85f8
	ctx.lr = 0x823BE210;
	sub_823B85F8(ctx, base);
	// sth r28,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r28.u16);
	// sth r28,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r28.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x823BE224;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x823BE22C;
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
loc_823BE244:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_823BE190) {
	__imp__sub_823BE190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE24C) {
	__imp__sub_823BE24C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE250) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823BE258;
	// addi r31,r4,1
	r31.s64 = ctx.r4.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
loc_823BE264:
	// lhz r11,16(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x823be274
	if (!cr6.lt) goto loc_823BE274;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823BE274:
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x823be290
	if (!cr6.lt) goto loc_823BE290;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stwx r10,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r10.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// b 0x823be264
	goto loc_823BE264;
loc_823BE290:
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r5,r9,64167
	ctx.r5.u64 = ctx.r9.u64 | 64167;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,2176
	ctx.r9.s64 = r11.s64 + 2176;
loc_823BE2A8:
	// lhz r11,16(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823be2bc
	if (cr6.lt) goto loc_823BE2BC;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_823BE2BC:
	// cmpw cr6,r6,r8
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, xer);
	// bge cr6,0x823be344
	if (!cr6.lt) goto loc_823BE344;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// bge cr6,0x823be2d4
	if (!cr6.lt) goto loc_823BE2D4;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
loc_823BE2D4:
	// lwz r30,0(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// mulld r8,r30,r5
	ctx.r8.s64 = r30.s64 * ctx.r5.s64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// twllei r7,0
	// clrlwi r30,r11,1
	r30.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// divw r29,r30,r7
	r29.s32 = r30.s32 / ctx.r7.s32;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mullw r8,r29,r7
	ctx.r8.s64 = int64_t(r29.s32) * int64_t(ctx.r7.s32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// lwz r29,12(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwzx r28,r10,r29
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// subf r8,r8,r30
	ctx.r8.s64 = r30.s64 - ctx.r8.s64;
	// rotlwi r11,r30,1
	r11.u64 = __builtin_rotateleft32(r30.u32, 1);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// andc r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 & ~r11.u64;
	// lwzx r11,r8,r29
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// twlgei r7,-1
	// stwx r11,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stwx r28,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, r28.u32);
	// b 0x823be2a8
	goto loc_823BE2A8;
loc_823BE344:
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BE250) {
	__imp__sub_823BE250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,289(r11)
	PPC_STORE_U8(r11.u32 + 289, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE350) {
	__imp__sub_823BE350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE364) {
	__imp__sub_823BE364(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE368) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,289(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 289);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823be398
	if (cr6.eq) goto loc_823BE398;
	// lbz r10,293(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 293);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823be398
	if (!cr6.eq) goto loc_823BE398;
	// lbz r11,292(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 292);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823be39c
	if (cr6.eq) goto loc_823BE39C;
loc_823BE398:
	// li r11,0
	r11.s64 = 0;
loc_823BE39C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE368) {
	__imp__sub_823BE368(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE3AC) {
	__imp__sub_823BE3AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE3B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,289(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 289);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823be3d4
	if (cr6.eq) goto loc_823BE3D4;
	// lbz r11,292(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 292);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823be3d8
	if (cr6.eq) goto loc_823BE3D8;
loc_823BE3D4:
	// li r11,0
	r11.s64 = 0;
loc_823BE3D8:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE3B0) {
	__imp__sub_823BE3B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE3E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r9,288(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 288);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE3E8) {
	__imp__sub_823BE3E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE400) {
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
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cc1c0
	ctx.lr = 0x823BE420;
	sub_823CC1C0(ctx, base);
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

PPC_WEAK_FUNC(sub_823BE400) {
	__imp__sub_823BE400(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE440) {
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
	// bl 0x823bbf80
	ctx.lr = 0x823BE458;
	sub_823BBF80(ctx, base);
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

PPC_WEAK_FUNC(sub_823BE440) {
	__imp__sub_823BE440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r9,341(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 341);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE478) {
	__imp__sub_823BE478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE490) {
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
	// bl 0x823bc000
	ctx.lr = 0x823BE4A8;
	sub_823BC000(ctx, base);
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

PPC_WEAK_FUNC(sub_823BE490) {
	__imp__sub_823BE490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE4C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r9,316(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 316);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE4C8) {
	__imp__sub_823BE4C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE4E0) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce5c8
	ctx.lr = 0x823BE500;
	sub_823CE5C8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BE4E0) {
	__imp__sub_823BE4E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE51C) {
	__imp__sub_823BE51C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE520) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823bc1c0
	ctx.lr = 0x823BE538;
	sub_823BC1C0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BE520) {
	__imp__sub_823BE520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE554) {
	__imp__sub_823BE554(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r10,-10000(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 + 60;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823BE574:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823be574
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823BE574;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE558) {
	__imp__sub_823BE558(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE58C) {
	__imp__sub_823BE58C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r11,60
	ctx.r9.s64 = r11.s64 + 60;
	// addi r8,r10,8
	ctx.r8.s64 = ctx.r10.s64 + 8;
	// addi r7,r9,8
	ctx.r7.s64 = ctx.r9.s64 + 8;
	// lwz r6,60(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lwz r5,64(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// stw r3,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r3.u32);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// lwz r8,80(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r8,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r8.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE590) {
	__imp__sub_823BE590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,3892(r11)
	PPC_STORE_U8(r11.u32 + 3892, ctx.r6.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE5E0) {
	__imp__sub_823BE5E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE604) {
	__imp__sub_823BE604(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,-1
	ctx.r7.s64 = -1;
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,296(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 296, temp.u32);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stfs f0,308(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 308, temp.u32);
	// addi r10,r11,308
	ctx.r10.s64 = r11.s64 + 308;
	// stw r7,312(r11)
	PPC_STORE_U32(r11.u32 + 312, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE608) {
	__imp__sub_823BE608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE63C) {
	__imp__sub_823BE63C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,-11344
	ctx.r9.s64 = ctx.r10.s64 + -11344;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE640) {
	__imp__sub_823BE640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE654) {
	__imp__sub_823BE654(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823bce88
	sub_823BCE88(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BE658) {
	__imp__sub_823BE658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE664) {
	__imp__sub_823BE664(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bge cr6,0x823be6b8
	if (!cr6.lt) goto loc_823BE6B8;
	// addi r10,r9,114
	ctx.r10.s64 = ctx.r9.s64 + 114;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r8,30
	cr6.compare<int32_t>(ctx.r8.s32, 30, xer);
	// bge cr6,0x823be6b8
	if (!cr6.lt) goto loc_823BE6B8;
	// mulli r7,r9,30
	ctx.r7.s64 = ctx.r9.s64 * 30;
	// lwz r6,0(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r5,r8,117
	ctx.r5.s64 = ctx.r8.s64 + 117;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r6.u32);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 1;
	// stwx r3,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r3.u32);
loc_823BE6B8:
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,460(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 460);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// stb r10,389(r11)
	PPC_STORE_U8(r11.u32 + 389, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE668) {
	__imp__sub_823BE668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE6E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stw r9,448(r11)
	PPC_STORE_U32(r11.u32 + 448, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE6E0) {
	__imp__sub_823BE6E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE6F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r11,448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE6F8) {
	__imp__sub_823BE6F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE71C) {
	__imp__sub_823BE71C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// addi r7,r10,114
	ctx.r7.s64 = ctx.r10.s64 + 114;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE720) {
	__imp__sub_823BE720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE748) {
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
	// bl 0x823bd180
	ctx.lr = 0x823BE760;
	sub_823BD180(ctx, base);
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

PPC_WEAK_FUNC(sub_823BE748) {
	__imp__sub_823BE748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE780) {
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
	// bl 0x823bcff8
	ctx.lr = 0x823BE798;
	sub_823BCFF8(ctx, base);
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

PPC_WEAK_FUNC(sub_823BE780) {
	__imp__sub_823BE780(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r9,372(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 372);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE7B8) {
	__imp__sub_823BE7B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE7E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stw r10,420(r11)
	PPC_STORE_U32(r11.u32 + 420, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE7E0) {
	__imp__sub_823BE7E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE7F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE7F4) {
	__imp__sub_823BE7F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE7F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stw r10,428(r11)
	PPC_STORE_U32(r11.u32 + 428, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE7F8) {
	__imp__sub_823BE7F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE80C) {
	__imp__sub_823BE80C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x823ce758
	sub_823CE758(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BE810) {
	__imp__sub_823BE810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE820) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce618
	ctx.lr = 0x823BE840;
	sub_823CE618(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BE820) {
	__imp__sub_823BE820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE85C) {
	__imp__sub_823BE85C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE860) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cc1e8
	ctx.lr = 0x823BE880;
	sub_823CC1E8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BE860) {
	__imp__sub_823BE860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE89C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE89C) {
	__imp__sub_823BE89C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE8A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// b 0x823cc200
	sub_823CC200(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BE8A0) {
	__imp__sub_823BE8A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE8B4) {
	__imp__sub_823BE8B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE8B8) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c9bd0
	ctx.lr = 0x823BE8E0;
	sub_823C9BD0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BE8B8) {
	__imp__sub_823BE8B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE8FC) {
	__imp__sub_823BE8FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stb r8,3792(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3792, ctx.r8.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE900) {
	__imp__sub_823BE900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE920) {
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
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r11,1232
	ctx.r7.s64 = r11.s64 + 1232;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE920) {
	__imp__sub_823BE920(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE948) {
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
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r11,2512
	ctx.r7.s64 = r11.s64 + 2512;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE948) {
	__imp__sub_823BE948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbz r6,3792(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 3792);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE970) {
	__imp__sub_823BE970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BE994) {
	__imp__sub_823BE994(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE998) {
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
	// bl 0x823bbf80
	ctx.lr = 0x823BE9B0;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823be9c4
	if (cr6.eq) goto loc_823BE9C4;
	// li r11,1
	r11.s64 = 1;
	// b 0x823be9d0
	goto loc_823BE9D0;
loc_823BE9C4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r11,334(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 334);
loc_823BE9D0:
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

PPC_WEAK_FUNC(sub_823BE998) {
	__imp__sub_823BE998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BE9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lbz r10,334(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 334);
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,334(r11)
	PPC_STORE_U8(r11.u32 + 334, ctx.r6.u8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BE9F0) {
	__imp__sub_823BE9F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEA20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,335(r11)
	PPC_STORE_U8(r11.u32 + 335, ctx.r6.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BEA20) {
	__imp__sub_823BEA20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEA44) {
	__imp__sub_823BEA44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEA48) {
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
	// bl 0x823bc770
	ctx.lr = 0x823BEA68;
	sub_823BC770(ctx, base);
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

PPC_WEAK_FUNC(sub_823BEA48) {
	__imp__sub_823BEA48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEA88) {
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
	// bl 0x823bc7e0
	ctx.lr = 0x823BEAA8;
	sub_823BC7E0(ctx, base);
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

PPC_WEAK_FUNC(sub_823BEA88) {
	__imp__sub_823BEA88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEAC8) {
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
	// bl 0x823bc850
	ctx.lr = 0x823BEAE8;
	sub_823BC850(ctx, base);
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

PPC_WEAK_FUNC(sub_823BEAC8) {
	__imp__sub_823BEAC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEB08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823beb5c
	if (cr6.eq) goto loc_823BEB5C;
	// lwz r9,656(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x823beb5c
	if (!cr6.eq) goto loc_823BEB5C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823beb5c
	if (cr6.eq) goto loc_823BEB5C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823beb5c
	if (cr6.eq) goto loc_823BEB5C;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// li r11,1
	r11.s64 = 1;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_823BEB5C:
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

PPC_WEAK_FUNC(sub_823BEB08) {
	__imp__sub_823BEB08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEB70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,953
	ctx.r7.s64 = r11.s64 + 953;
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r8.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BEB70) {
	__imp__sub_823BEB70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEB94) {
	__imp__sub_823BEB94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEB98) {
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
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// addi r9,r4,953
	ctx.r9.s64 = ctx.r4.s64 + 953;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r8,r11
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x823bebf4
	if (!cr6.eq) goto loc_823BEBF4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r5,r11,-11344
	ctx.r5.s64 = r11.s64 + -11344;
	// addi r3,r10,-27552
	ctx.r3.s64 = ctx.r10.s64 + -27552;
	// bl 0x82130000
	ctx.lr = 0x823BEBE8;
	sub_82130000(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r30.u32);
	// b 0x823bebfc
	goto loc_823BEBFC;
loc_823BEBF4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_823BEBFC:
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

PPC_WEAK_FUNC(sub_823BEB98) {
	__imp__sub_823BEB98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEC14) {
	__imp__sub_823BEC14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEC18) {
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
	// bl 0x823bc938
	ctx.lr = 0x823BEC30;
	sub_823BC938(ctx, base);
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

PPC_WEAK_FUNC(sub_823BEC18) {
	__imp__sub_823BEC18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEC4C) {
	__imp__sub_823BEC4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEC50) {
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
	// bl 0x823bcab8
	ctx.lr = 0x823BEC68;
	sub_823BCAB8(ctx, base);
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

PPC_WEAK_FUNC(sub_823BEC50) {
	__imp__sub_823BEC50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEC88) {
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
	// bl 0x823bcb48
	ctx.lr = 0x823BECA0;
	sub_823BCB48(ctx, base);
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

PPC_WEAK_FUNC(sub_823BEC88) {
	__imp__sub_823BEC88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BECC0) {
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
	// bl 0x823bcbe0
	ctx.lr = 0x823BECD8;
	sub_823BCBE0(ctx, base);
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

PPC_WEAK_FUNC(sub_823BECC0) {
	__imp__sub_823BECC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BECF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r3,3896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821f5e80
	sub_821F5E80(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BECF8) {
	__imp__sub_823BECF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED10) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BED10) {
	__imp__sub_823BED10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BED14) {
	__imp__sub_823BED14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r3,3900(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3900);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821f5e80
	sub_821F5E80(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_823BED18) {
	__imp__sub_823BED18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED30) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BED30) {
	__imp__sub_823BED30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BED34) {
	__imp__sub_823BED34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,291(r11)
	PPC_STORE_U8(r11.u32 + 291, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BED38) {
	__imp__sub_823BED38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BED4C) {
	__imp__sub_823BED4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED50) {
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
	// bl 0x823bdd90
	ctx.lr = 0x823BED70;
	sub_823BDD90(ctx, base);
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

PPC_WEAK_FUNC(sub_823BED50) {
	__imp__sub_823BED50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BED90) {
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
	// bl 0x823bde08
	ctx.lr = 0x823BEDB0;
	sub_823BDE08(ctx, base);
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

PPC_WEAK_FUNC(sub_823BED90) {
	__imp__sub_823BED90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEDD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,-29932(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29932);
	ctx.f13.f64 = double(temp.f32);
	// li r8,6
	ctx.r8.s64 = 6;
	// lwz r11,-10000(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10000);
	// stfs f0,-8(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// stfs f13,-4(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwz r5,12(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r7,0(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r7,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r7.u32);
	// stw r4,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r4.u32);
	// stw r3,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r3.u32);
	// stw r5,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r5.u32);
	// lwz r11,-10000(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10000);
	// addi r11,r11,36
	r11.s64 = r11.s64 + 36;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_823BEE44:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823bee44
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823BEE44;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BEDD0) {
	__imp__sub_823BEDD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEE5C) {
	__imp__sub_823BEE5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r10,-10000(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823BEE7C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823bee7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823BEE7C;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BEE60) {
	__imp__sub_823BEE60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEE94) {
	__imp__sub_823BEE94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEE98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 340);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BEE98) {
	__imp__sub_823BEE98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEEB0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823bef08
	if (cr6.eq) goto loc_823BEF08;
	// lbz r10,305(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 305);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823beef8
	if (cr6.eq) goto loc_823BEEF8;
	// lbz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stb r9,52(r11)
	PPC_STORE_U8(r11.u32 + 52, ctx.r9.u8);
	// b 0x823bef20
	goto loc_823BEF20;
loc_823BEEF8:
	// lbz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r9,52(r11)
	PPC_STORE_U8(r11.u32 + 52, ctx.r9.u8);
	// b 0x823bef20
	goto loc_823BEF20;
loc_823BEF08:
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bef20
	if (cr6.eq) goto loc_823BEF20;
	// lbz r11,52(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// stb r10,305(r31)
	PPC_STORE_U8(r31.u32 + 305, ctx.r10.u8);
loc_823BEF20:
	// lbz r11,304(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 304);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bef40
	if (cr6.eq) goto loc_823BEF40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x823ce758
	ctx.lr = 0x823BEF3C;
	sub_823CE758(ctx, base);
	// b 0x823bef70
	goto loc_823BEF70;
loc_823BEF40:
	// lbz r11,305(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 305);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bef78
	if (cr6.eq) goto loc_823BEF78;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bbb98
	ctx.lr = 0x823BEF54;
	sub_823BBB98(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x823bef78
	if (!cr6.gt) goto loc_823BEF78;
	// li r11,2
	r11.s64 = 2;
	// stfs f1,308(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stw r11,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r11.u32);
loc_823BEF70:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,316(r31)
	PPC_STORE_U8(r31.u32 + 316, ctx.r10.u8);
loc_823BEF78:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BEEB0) {
	__imp__sub_823BEEB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BEF8C) {
	__imp__sub_823BEF8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BEF90) {
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
	ctx.lr = 0x823BEF98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r11,-9132
	ctx.r4.s64 = r11.s64 + -9132;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BEFB0;
	sub_823D90B0(ctx, base);
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823befd8
	if (cr6.eq) goto loc_823BEFD8;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,32132
	ctx.r4.s64 = r11.s64 + 32132;
	// bl 0x823d90b0
	ctx.lr = 0x823BEFCC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// beq cr6,0x823befdc
	if (cr6.eq) goto loc_823BEFDC;
loc_823BEFD8:
	// li r11,0
	r11.s64 = 0;
loc_823BEFDC:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r10,-10000(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// lbz r9,341(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 341);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823bf004
	if (!cr6.eq) goto loc_823BF004;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// bne cr6,0x823bf0c8
	if (!cr6.eq) goto loc_823BF0C8;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bf0c8
	if (!cr6.eq) goto loc_823BF0C8;
loc_823BF004:
	// li r30,0
	r30.s64 = 0;
loc_823BF008:
	// addi r11,r30,953
	r11.s64 = r30.s64 + 953;
	// lwz r10,-10000(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10000);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x823bf0bc
	if (!cr6.gt) goto loc_823BF0BC;
	// bl 0x822a86d8
	ctx.lr = 0x823BF024;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bf0bc
	if (cr6.eq) goto loc_823BF0BC;
	// bl 0x822a86e8
	ctx.lr = 0x823BF034;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf0bc
	if (cr6.eq) goto loc_823BF0BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x823BF048;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf0bc
	if (cr6.eq) goto loc_823BF0BC;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf0bc
	if (cr6.eq) goto loc_823BF0BC;
	// lwz r31,84(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bf0bc
	if (cr6.eq) goto loc_823BF0BC;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x823bf08c
	if (!cr6.eq) goto loc_823BF08C;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x823bf084
	if (!cr6.eq) goto loc_823BF084;
	// stb r29,2154(r31)
	PPC_STORE_U8(r31.u32 + 2154, r29.u8);
	// b 0x823bf0bc
	goto loc_823BF0BC;
loc_823BF084:
	// stb r29,2156(r31)
	PPC_STORE_U8(r31.u32 + 2156, r29.u8);
	// b 0x823bf0bc
	goto loc_823BF0BC;
loc_823BF08C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8233b608
	ctx.lr = 0x823BF094;
	sub_8233B608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bf0bc
	if (!cr6.eq) goto loc_823BF0BC;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// bne cr6,0x823bf0bc
	if (!cr6.eq) goto loc_823BF0BC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x823bf0b8
	if (!cr6.eq) goto loc_823BF0B8;
	// stb r29,2153(r31)
	PPC_STORE_U8(r31.u32 + 2153, r29.u8);
	// b 0x823bf0bc
	goto loc_823BF0BC;
loc_823BF0B8:
	// stb r29,2155(r31)
	PPC_STORE_U8(r31.u32 + 2155, r29.u8);
loc_823BF0BC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// blt cr6,0x823bf008
	if (cr6.lt) goto loc_823BF008;
loc_823BF0C8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_823BEF90) {
	__imp__sub_823BEF90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF0D0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x823BF0D8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// stw r30,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r30.u32);
	// lwz r31,-10000(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823bcdc8
	ctx.lr = 0x823BF100;
	sub_823BCDC8(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,-18004(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18004);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf120
	if (cr6.eq) goto loc_823BF120;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// stb r10,333(r31)
	PPC_STORE_U8(r31.u32 + 333, ctx.r10.u8);
	// stb r30,4(r11)
	PPC_STORE_U8(r11.u32 + 4, r30.u8);
loc_823BF120:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,264(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// bl 0x824a3e98
	ctx.lr = 0x823BF12C;
	sub_824A3E98(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823d69d8
	ctx.lr = 0x823BF144;
	sub_823D69D8(ctx, base);
	// lwz r3,268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823d69e0
	ctx.lr = 0x823BF150;
	sub_823D69E0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	f0.f64 = double(temp.f32);
	// stb r30,292(r31)
	PPC_STORE_U8(r31.u32 + 292, r30.u8);
	// stb r10,288(r31)
	PPC_STORE_U8(r31.u32 + 288, ctx.r10.u8);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// stb r30,293(r31)
	PPC_STORE_U8(r31.u32 + 293, r30.u8);
	// ble cr6,0x823bf178
	if (!cr6.gt) goto loc_823BF178;
	// li r11,2
	r11.s64 = 2;
	// stfs f0,308(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stw r11,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r11.u32);
loc_823BF178:
	// bl 0x821f97d0
	ctx.lr = 0x823BF17C;
	sub_821F97D0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r31,r11,-11344
	r31.s64 = r11.s64 + -11344;
	// addi r4,r10,-27788
	ctx.r4.s64 = ctx.r10.s64 + -27788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BF194;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bf1a4
	if (cr6.eq) goto loc_823BF1A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822f1720
	ctx.lr = 0x823BF1A4;
	sub_822F1720(ctx, base);
loc_823BF1A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823bef90
	ctx.lr = 0x823BF1B0;
	sub_823BEF90(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,-11756(r10)
	PPC_STORE_U8(ctx.r10.u32 + -11756, r11.u8);
	// lwz r31,17268(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x823BF1D0;
	sub_821E80F8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823bf1f0
	if (cr6.eq) goto loc_823BF1F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x823BF1E8;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x823BF1F0;
	sub_822A93A8(ctx, base);
loc_823BF1F0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-12288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// stb r30,1079(r11)
	PPC_STORE_U8(r11.u32 + 1079, r30.u8);
	// bl 0x821e6828
	ctx.lr = 0x823BF208;
	sub_821E6828(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// addi r3,r9,-26912
	ctx.r3.s64 = ctx.r9.s64 + -26912;
	// lfs f3,328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 328);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,84(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,324(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 324);
	ctx.f2.f64 = double(temp.f32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x823BF244;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_823BF0D0) {
	__imp__sub_823BF0D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF250) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823bf2d4
	if (cr6.eq) goto loc_823BF2D4;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823bf2d4
	if (cr6.eq) goto loc_823BF2D4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r5,r11,-14056
	ctx.r5.s64 = r11.s64 + -14056;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BF294;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de4d8
	ctx.lr = 0x823BF29C;
	sub_823DE4D8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27708
	ctx.r4.s64 = ctx.r10.s64 + -27708;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// bl 0x823d90b0
	ctx.lr = 0x823BF2B0;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bf2bc
	if (cr6.eq) goto loc_823BF2BC;
	// addi r31,r1,89
	r31.s64 = ctx.r1.s64 + 89;
loc_823BF2BC:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b7d68
	ctx.lr = 0x823BF2D0;
	sub_823B7D68(ctx, base);
	// b 0x823bf2d8
	goto loc_823BF2D8;
loc_823BF2D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823BF2D8:
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

PPC_WEAK_FUNC(sub_823BF250) {
	__imp__sub_823BF250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF2F0) {
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
	ctx.lr = 0x823BF2F8;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// lwz r5,368(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x823bf250
	ctx.lr = 0x823BF318;
	sub_823BF250(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf3b0
	if (cr6.eq) goto loc_823BF3B0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823bf3b0
	if (!cr6.eq) goto loc_823BF3B0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823bf340
	if (!cr6.eq) goto loc_823BF340;
	// li r11,0
	r11.s64 = 0;
loc_823BF338:
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// b 0x823bf39c
	goto loc_823BF39C;
loc_823BF340:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BF358;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de4d8
	ctx.lr = 0x823BF360;
	sub_823DE4D8(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-27708
	ctx.r4.s64 = ctx.r10.s64 + -27708;
	// bl 0x823d90b0
	ctx.lr = 0x823BF370;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x823bf338
	if (cr6.eq) goto loc_823BF338;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r7,r3,9
	ctx.r7.s64 = ctx.r3.s64 + 9;
	// addi r5,r10,-27720
	ctx.r5.s64 = ctx.r10.s64 + -27720;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82137a08
	ctx.lr = 0x823BF39C;
	sub_82137A08(ctx, base);
loc_823BF39C:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r5,368(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x823bf250
	ctx.lr = 0x823BF3B0;
	sub_823BF250(ctx, base);
loc_823BF3B0:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BF2F0) {
	__imp__sub_823BF2F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF3B8) {
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
	ctx.lr = 0x823BF3C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r31,364(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bf404
	if (cr6.eq) goto loc_823BF404;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823bf408
	if (cr6.eq) goto loc_823BF408;
loc_823BF404:
	// li r11,0
	r11.s64 = 0;
loc_823BF408:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf474
	if (cr6.eq) goto loc_823BF474;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823bf250
	ctx.lr = 0x823BF424;
	sub_823BF250(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823bf454
	if (!cr6.eq) goto loc_823BF454;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823BF43C;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-26792
	ctx.r3.s64 = ctx.r10.s64 + -26792;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x823BF454;
	sub_82130000(ctx, base);
loc_823BF454:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9bc0
	ctx.lr = 0x823BF46C;
	sub_823C9BC0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823BF474:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4960(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// bl 0x823caab8
	ctx.lr = 0x823BF488;
	sub_823CAAB8(ctx, base);
	// lwz r11,-4960(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4960);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823ca4e0
	ctx.lr = 0x823BF4A0;
	sub_823CA4E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823BF3B8) {
	__imp__sub_823BF3B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF4A8) {
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
	ctx.lr = 0x823BF4B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r31,364(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823bf4f0
	if (cr6.eq) goto loc_823BF4F0;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r10,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823bf4f4
	if (cr6.eq) goto loc_823BF4F4;
loc_823BF4F0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823BF4F4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bf588
	if (cr6.eq) goto loc_823BF588;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823bf5e4
	if (cr6.lt) goto loc_823BF5E4;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bge cr6,0x823bf5e4
	if (!cr6.lt) goto loc_823BF5E4;
	// addi r10,r3,208
	ctx.r10.s64 = ctx.r3.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r9,r11
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// ble cr6,0x823bf5e4
	if (!cr6.gt) goto loc_823BF5E4;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823bf250
	ctx.lr = 0x823BF538;
	sub_823BF250(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823bf568
	if (!cr6.eq) goto loc_823BF568;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823BF550;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-26712
	ctx.r3.s64 = ctx.r10.s64 + -26712;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x823BF568;
	sub_82130000(ctx, base);
loc_823BF568:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9bc0
	ctx.lr = 0x823BF580;
	sub_823C9BC0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823BF588:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823bf5e4
	if (cr6.lt) goto loc_823BF5E4;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bge cr6,0x823bf5e4
	if (!cr6.lt) goto loc_823BF5E4;
	// addi r10,r3,208
	ctx.r10.s64 = ctx.r3.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// ble cr6,0x823bf5e4
	if (!cr6.gt) goto loc_823BF5E4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-4960(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// bl 0x823caab8
	ctx.lr = 0x823BF5C4;
	sub_823CAAB8(ctx, base);
	// lwz r11,-4960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4960);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823ca4e0
	ctx.lr = 0x823BF5DC;
	sub_823CA4E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823BF5E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_823BF4A8) {
	__imp__sub_823BF4A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF5F0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x823BF5F8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r30,336(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// lwz r28,360(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bf64c
	if (cr6.eq) goto loc_823BF64C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823bf650
	if (cr6.eq) goto loc_823BF650;
loc_823BF64C:
	// li r11,0
	r11.s64 = 0;
loc_823BF650:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// beq cr6,0x823bf71c
	if (cr6.eq) goto loc_823BF71C;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823BF670;
	sub_823CA248(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823bf7a4
	if (cr6.eq) goto loc_823BF7A4;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// bl 0x823bf250
	ctx.lr = 0x823BF690;
	sub_823BF250(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823bf6c0
	if (!cr6.eq) goto loc_823BF6C0;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823b8690
	ctx.lr = 0x823BF6A8;
	sub_823B8690(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r10,-26624
	ctx.r3.s64 = ctx.r10.s64 + -26624;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x823BF6C0;
	sub_82130000(ctx, base);
loc_823BF6C0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823ca370
	ctx.lr = 0x823BF6E8;
	sub_823CA370(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823bf7a8
	if (!cr6.lt) goto loc_823BF7A8;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_823BF71C:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// bl 0x823ca248
	ctx.lr = 0x823BF728;
	sub_823CA248(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823bf7a4
	if (cr6.eq) goto loc_823BF7A4;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823caab8
	ctx.lr = 0x823BF744;
	sub_823CAAB8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-4960(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823ca2e8
	ctx.lr = 0x823BF770;
	sub_823CA2E8(ctx, base);
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// cmpwi cr6,r10,100
	cr6.compare<int32_t>(ctx.r10.s32, 100, xer);
	// bge cr6,0x823bf7a8
	if (!cr6.lt) goto loc_823BF7A8;
	// addi r10,r10,208
	ctx.r10.s64 = ctx.r10.s64 + 208;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,828(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,828(r11)
	PPC_STORE_U32(r11.u32 + 828, ctx.r8.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_823BF7A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823BF7A8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_823BF5F0) {
	__imp__sub_823BF5F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF7B0) {
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
	ctx.lr = 0x823BF7B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bne cr6,0x823bf8a0
	if (!cr6.eq) goto loc_823BF8A0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-28087
	ctx.r10.s64 = -1840709632;
	// addi r26,r11,-11188
	r26.s64 = r11.s64 + -11188;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// ori r30,r10,9363
	r30.u64 = ctx.r10.u64 | 9363;
	// addi r28,r11,-22496
	r28.s64 = r11.s64 + -22496;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,-8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -8);
	// addi r9,r28,-28
	ctx.r9.s64 = r28.s64 + -28;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// stw r31,-8(r26)
	PPC_STORE_U32(r26.u32 + -8, r31.u32);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// mulhw r10,r11,r30
	ctx.r10.s64 = (int64_t(r11.s32) * int64_t(r30.s32)) >> 32;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// srawi r11,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	r11.s64 = ctx.r7.s32 >> 2;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r11,r6
	ctx.r5.s64 = ctx.r6.s64 - r11.s64;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r3,r9
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
loc_823BF824:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823bc428
	ctx.lr = 0x823BF82C;
	sub_823BC428(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf874
	if (cr6.eq) goto loc_823BF874;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r9,r28,-28
	ctx.r9.s64 = r28.s64 + -28;
	// mulhw r11,r31,r30
	r11.s64 = (int64_t(r31.s32) * int64_t(r30.s32)) >> 32;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// srawi r11,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	r11.s64 = ctx.r8.s32 >> 2;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - r11.s64;
	// subf r5,r6,r31
	ctx.r5.s64 = r31.s64 - ctx.r6.s64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r4,r9
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// blt cr6,0x823bf824
	if (cr6.lt) goto loc_823BF824;
loc_823BF874:
	// stw r31,-8(r26)
	PPC_STORE_U32(r26.u32 + -8, r31.u32);
loc_823BF878:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823bc4e0
	ctx.lr = 0x823BF884;
	sub_823BC4E0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// stb r10,3792(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3792, ctx.r10.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_823BF8A0:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,26214
	ctx.r9.s64 = 1717960704;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// ori r7,r9,26215
	ctx.r7.u64 = ctx.r9.u64 | 26215;
	// addi r6,r8,-22496
	ctx.r6.s64 = ctx.r8.s64 + -22496;
	// lwz r11,-11188(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11188);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// stw r11,-11188(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11188, r11.u32);
	// mulhw r4,r5,r7
	ctx.r4.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r11,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r11.s64 = ctx.r4.s32 >> 2;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r11,r5
	ctx.r10.s64 = ctx.r5.s64 - r11.s64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r9,r6
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// b 0x823bf878
	goto loc_823BF878;
}

PPC_WEAK_FUNC(sub_823BF7B0) {
	__imp__sub_823BF7B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BF8F0) {
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
	ctx.lr = 0x823BF8F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bne cr6,0x823bf9cc
	if (!cr6.eq) goto loc_823BF9CC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// addi r26,r11,-11184
	r26.s64 = r11.s64 + -11184;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// ori r30,r10,21846
	r30.u64 = ctx.r10.u64 | 21846;
	// addi r28,r11,-22444
	r28.s64 = r11.s64 + -22444;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,-8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -8);
	// addi r9,r28,-12
	ctx.r9.s64 = r28.s64 + -12;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// stw r31,-8(r26)
	PPC_STORE_U32(r26.u32 + -8, r31.u32);
	// mulhw r11,r8,r30
	r11.s64 = (int64_t(ctx.r8.s32) * int64_t(r30.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r5,r9
	r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
loc_823BF958:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823bc428
	ctx.lr = 0x823BF960;
	sub_823BC428(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bf9a0
	if (cr6.eq) goto loc_823BF9A0;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r9,r28,-12
	ctx.r9.s64 = r28.s64 + -12;
	// mulhw r11,r31,r30
	r11.s64 = (int64_t(r31.s32) * int64_t(r30.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf r7,r8,r31
	ctx.r7.s64 = r31.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r6,r9
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// blt cr6,0x823bf958
	if (cr6.lt) goto loc_823BF958;
loc_823BF9A0:
	// stw r31,-8(r26)
	PPC_STORE_U32(r26.u32 + -8, r31.u32);
loc_823BF9A4:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823bc4e0
	ctx.lr = 0x823BF9B0;
	sub_823BC4E0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// stb r10,3792(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3792, ctx.r10.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_823BF9CC:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,10922
	ctx.r9.s64 = 715784192;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// ori r7,r9,43691
	ctx.r7.u64 = ctx.r9.u64 | 43691;
	// addi r6,r8,-22444
	ctx.r6.s64 = ctx.r8.s64 + -22444;
	// lwz r11,-11184(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11184);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// stw r11,-11184(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11184, r11.u32);
	// mulhw r11,r5,r7
	r11.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r3,r5
	r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r10,r6
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// b 0x823bf9a4
	goto loc_823BF9A4;
}

PPC_WEAK_FUNC(sub_823BF8F0) {
	__imp__sub_823BF8F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFA18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,26214
	ctx.r9.s64 = 1717960704;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r7,r9,26215
	ctx.r7.u64 = ctx.r9.u64 | 26215;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lwz r11,-11180(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11180);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r6,r8,-22420
	ctx.r6.s64 = ctx.r8.s64 + -22420;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// stw r11,-11180(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11180, r11.u32);
	// mulhw r3,r5,r7
	ctx.r3.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r11,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r11.s64 = ctx.r3.s32 >> 1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r11,r5
	ctx.r10.s64 = ctx.r5.s64 - r11.s64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// bl 0x823bc4e0
	ctx.lr = 0x823BFA7C;
	sub_823BC4E0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,-10000(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10000);
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// stb r7,3792(r6)
	PPC_STORE_U8(ctx.r6.u32 + 3792, ctx.r7.u8);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_823BFA18) {
	__imp__sub_823BFA18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFAA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BFAA4) {
	__imp__sub_823BFAA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFAA8) {
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
	ctx.lr = 0x823BFAB0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// addi r31,r11,96
	r31.s64 = r11.s64 + 96;
	// addi r27,r11,60
	r27.s64 = r11.s64 + 60;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823a3f00
	ctx.lr = 0x823BFACC;
	sub_823A3F00(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823a41d0
	ctx.lr = 0x823BFAEC;
	sub_823A41D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bfbd0
	if (cr6.eq) goto loc_823BFBD0;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,4(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8216c900
	ctx.lr = 0x823BFB18;
	sub_8216C900(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f0,-26540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26540);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x823bfbc4
	if (!cr6.gt) goto loc_823BFBC4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// vpermwi128 v61,v63,99
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// vpermwi128 v60,v63,135
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vpermwi128 v13,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// addi r4,r6,-31648
	ctx.r4.s64 = ctx.r6.s64 + -31648;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,-31664
	ctx.r3.s64 = ctx.r5.s64 + -31664;
	// lvx128 v10,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vmulfp128 v11,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v12,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vnmsubfp v13,v13,v0,v11
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v59,v13,v13
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// stvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v58,v59
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v9,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vcmpeqfp128 v8,v58,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v7,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v7,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vmulfp128 v6,v0,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v63,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v4,v9,v6,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v3,v4,v5,v0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v13,v3
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82350940
	ctx.lr = 0x823BFBC4;
	sub_82350940(ctx, base);
loc_823BFBC4:
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,228(r11)
	PPC_STORE_U8(r11.u32 + 228, ctx.r10.u8);
loc_823BFBD0:
	// stw r31,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r31.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_823BFAA8) {
	__imp__sub_823BFAA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFBDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BFBDC) {
	__imp__sub_823BFBDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFBE0) {
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
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r10,368(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823bfc1c
	if (cr6.eq) goto loc_823BFC1C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823bfc20
	if (cr6.eq) goto loc_823BFC20;
loc_823BFC1C:
	// li r11,0
	r11.s64 = 0;
loc_823BFC20:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bfc64
	if (cr6.eq) goto loc_823BFC64;
	// bl 0x823bcd40
	ctx.lr = 0x823BFC30;
	sub_823BCD40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bfc50
	if (cr6.eq) goto loc_823BFC50;
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
loc_823BFC50:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r11,-11344
	ctx.r4.s64 = r11.s64 + -11344;
	// addi r3,r10,-26536
	ctx.r3.s64 = ctx.r10.s64 + -26536;
	// bl 0x82130000
	ctx.lr = 0x823BFC64;
	sub_82130000(ctx, base);
loc_823BFC64:
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

PPC_WEAK_FUNC(sub_823BFBE0) {
	__imp__sub_823BFBE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFC78) {
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
	ctx.lr = 0x823BFC80;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BFC94;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de4d8
	ctx.lr = 0x823BFC9C;
	sub_823DE4D8(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-26480
	ctx.r4.s64 = r11.s64 + -26480;
	// bl 0x823d90b0
	ctx.lr = 0x823BFCAC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bfd7c
	if (cr6.eq) goto loc_823BFD7C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,-20580
	r30.s64 = r11.s64 + -20580;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r29,3812(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 3812);
	// lwz r28,3816(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 3816);
	// bl 0x823d90b0
	ctx.lr = 0x823BFCD8;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bfce8
	if (cr6.eq) goto loc_823BFCE8;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// b 0x823bfd20
	goto loc_823BFD20;
loc_823BFCE8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,-26484
	r30.s64 = r11.s64 + -26484;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823d90b0
	ctx.lr = 0x823BFCFC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823bfd18
	if (cr6.eq) goto loc_823BFD18;
	// lwz r11,-10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10000);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r29,3816(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 3816);
	// lwz r28,3812(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 3812);
	// b 0x823bfd20
	goto loc_823BFD20;
loc_823BFD18:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r11,496
	ctx.r6.s64 = r11.s64 + 496;
loc_823BFD20:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-26504
	ctx.r5.s64 = r11.s64 + -26504;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823BFD34;
	sub_82137A08(ctx, base);
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// ble cr6,0x823bfd7c
	if (!cr6.gt) goto loc_823BFD7C;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// ble cr6,0x823bfd7c
	if (!cr6.gt) goto loc_823BFD7C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a86d8
	ctx.lr = 0x823BFD4C;
	sub_822A86D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a86d8
	ctx.lr = 0x823BFD58;
	sub_822A86D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823bfd7c
	if (cr6.eq) goto loc_823BFD7C;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823bfd7c
	if (cr6.eq) goto loc_823BFD7C;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823bd448
	ctx.lr = 0x823BFD7C;
	sub_823BD448(ctx, base);
loc_823BFD7C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BFC78) {
	__imp__sub_823BFC78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFD84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BFD84) {
	__imp__sub_823BFD84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFD88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// lwz r11,260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x823bfda8
	if (cr6.eq) goto loc_823BFDA8;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823BFDA8:
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_823BFD88) {
	__imp__sub_823BFD88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BFDAC) {
	__imp__sub_823BFDAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFDB0) {
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
	ctx.lr = 0x823BFDB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r28,0
	r28.s64 = 0;
	// addi r9,r11,-26916
	ctx.r9.s64 = r11.s64 + -26916;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 52);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823bfe04
	if (cr6.eq) goto loc_823BFE04;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_823BFDE4:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82130588
	ctx.lr = 0x823BFDF0;
	sub_82130588(ctx, base);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 52);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x823bfde4
	if (cr6.lt) goto loc_823BFDE4;
loc_823BFE04:
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823BFE10;
	sub_82130588(ctx, base);
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823bfe30
	if (cr6.eq) goto loc_823BFE30;
	// rotlwi r3,r28,0
	ctx.r3.u64 = __builtin_rotateleft32(r28.u32, 0);
	// bl 0x82130588
	ctx.lr = 0x823BFE30;
	sub_82130588(ctx, base);
loc_823BFE30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_823BFDB0) {
	__imp__sub_823BFDB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFE38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823bfe68
	if (!cr6.gt) goto loc_823BFE68;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
loc_823BFE4C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// beq cr6,0x823bfe70
	if (cr6.eq) goto loc_823BFE70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823bfe4c
	if (cr6.lt) goto loc_823BFE4C;
loc_823BFE68:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823BFE70:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x823bfe68
	if (!cr6.gt) goto loc_823BFE68;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823bfea0
	if (cr6.eq) goto loc_823BFEA0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
loc_823BFEA0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_823BFE38) {
	__imp__sub_823BFE38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BFEAC) {
	__imp__sub_823BFEAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFEB0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r6,12(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cntlzw r4,r7
	ctx.r4.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r8,r11,1
	ctx.r8.u64 = r11.u64 ^ 1;
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r4,r8,24
	ctx.r4.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823BFF08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_823BFEB0) {
	__imp__sub_823BFEB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_823BFF24) {
	__imp__sub_823BFF24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_823BFF28) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x823BFF30;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// bl 0x82246b78
	ctx.lr = 0x823BFF4C;
	sub_82246B78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823bff64
	if (!cr6.eq) goto loc_823BFF64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d922c
	return;
loc_823BFF64:
	// lfs f0,8(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 8);
	f0.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,48(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x823bff88
	if (cr6.gt) goto loc_823BFF88;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823BFF88:
	// lfs f13,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r11,2
	r11.s64 = 2;
	// lfs f12,44(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x823bffa4
	if (cr6.gt) goto loc_823BFFA4;
	// li r11,0
	r11.s64 = 0;
loc_823BFFA4:
	// or r29,r11,r10
	r29.u64 = r11.u64 | ctx.r10.u64;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// addi r28,r11,-22320
	r28.s64 = r11.s64 + -22320;
loc_823BFFB8:
	// cmpw cr6,r30,r22
	cr6.compare<int32_t>(r30.s32, r22.s32, xer);
	// bge cr6,0x823c0014
	if (!cr6.lt) goto loc_823C0014;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r28
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// addi r9,r11,7
	ctx.r9.s64 = r11.s64 + 7;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r24
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r24.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823c0008
	if (cr6.eq) goto loc_823C0008;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// subf r6,r30,r22
	ctx.r6.s64 = r22.s64 - r30.s64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// add r5,r11,r27
	ctx.r5.u64 = r11.u64 + r27.u64;
	// bl 0x823bff28
	ctx.lr = 0x823C0004;
	sub_823BFF28(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_823C0008:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x823bffb8
	if (cr6.lt) goto loc_823BFFB8;
loc_823C0014:
	// lhz r11,8(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823c00d0
	if (cr6.eq) goto loc_823C00D0;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// li r29,0
	r29.s64 = 0;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// li r26,-32
	r26.s64 = -32;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// li r28,-16
	r28.s64 = -16;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// li r27,16
	r27.s64 = 16;
	// addi r31,r11,32
	r31.s64 = r11.s64 + 32;
loc_823C0048:
	// cmpw cr6,r30,r22
	cr6.compare<int32_t>(r30.s32, r22.s32, xer);
	// bge cr6,0x823c00d0
	if (!cr6.lt) goto loc_823C00D0;
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// and r8,r9,r21
	ctx.r8.u64 = ctx.r9.u64 & r21.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823c00bc
	if (cr6.eq) goto loc_823C00BC;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823bb948
	ctx.lr = 0x823C0078;
	sub_823BB948(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lbz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 44);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r10.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823c00bc
	if (cr6.eq) goto loc_823C00BC;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
loc_823C00BC:
	// lhz r11,8(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x823c0048
	if (cr6.lt) goto loc_823C0048;
loc_823C00D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_823BFF28) {
	__imp__sub_823BFF28(ctx, base);
}

