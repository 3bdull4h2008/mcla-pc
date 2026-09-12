#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82299AA0"))) PPC_WEAK_FUNC(sub_82299AA0);
PPC_FUNC_IMPL(__imp__sub_82299AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82299AA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82299c90
	if (cr6.gt) goto loc_82299C90;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-25872
	r12.s64 = r12.s64 + -25872;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82299B00;
	case 1:
		goto loc_82299BCC;
	case 2:
		goto loc_82299B5C;
	case 3:
		goto loc_82299C50;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25856(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25856);
	// lwz r17,-25652(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25652);
	// lwz r17,-25764(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25764);
	// lwz r17,-25520(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25520);
loc_82299B00:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299B1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299c90
	if (cr6.eq) goto loc_82299C90;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r9.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82299B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82299B5C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299c90
	if (cr6.eq) goto loc_82299C90;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bgt cr6,0x82299bac
	if (cr6.gt) goto loc_82299BAC;
	// bl 0x821c9788
	ctx.lr = 0x82299BA8;
	sub_821C9788(ctx, base);
	// stw r3,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r3.u32);
loc_82299BAC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299BC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82299BCC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299BE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299c38
	if (cr6.eq) goto loc_82299C38;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bgt cr6,0x82299c1c
	if (cr6.gt) goto loc_82299C1C;
	// bl 0x821c9788
	ctx.lr = 0x82299C18;
	sub_821C9788(ctx, base);
	// stw r3,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r3.u32);
loc_82299C1C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,6
	ctx.r9.s64 = 6;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// stb r9,8(r7)
	PPC_STORE_U8(ctx.r7.u32 + 8, ctx.r9.u8);
loc_82299C38:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ef220
	ctx.lr = 0x82299C48;
	sub_824EF220(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82299C50:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82257678
	ctx.lr = 0x82299C6C;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82299c90
	if (cr6.eq) goto loc_82299C90;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82299C90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82299C90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82299C98"))) PPC_WEAK_FUNC(sub_82299C98);
PPC_FUNC_IMPL(__imp__sub_82299C98) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r3,r11,13928
	ctx.r3.s64 = r11.s64 + 13928;
	// bl 0x82297450
	ctx.lr = 0x82299CB8;
	sub_82297450(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,66
	ctx.r3.s64 = 66;
	// bge cr6,0x82299cc8
	if (!cr6.lt) goto loc_82299CC8;
	// li r3,89
	ctx.r3.s64 = 89;
loc_82299CC8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82299CD8"))) PPC_WEAK_FUNC(sub_82299CD8);
PPC_FUNC_IMPL(__imp__sub_82299CD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r10,-488
	ctx.r8.s64 = ctx.r10.s64 + -488;
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82299CF4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x82299cf4
	if (!cr0.lt) goto loc_82299CF4;
	// lbz r7,208(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 208);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// stw r10,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r10.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r10,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r10.u32);
	// stw r10,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r10.u32);
	// stb r6,208(r3)
	PPC_STORE_U8(ctx.r3.u32 + 208, ctx.r6.u8);
loc_82299D2C:
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x82299d2c
	if (!cr0.eq) goto loc_82299D2C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82299D44"))) PPC_WEAK_FUNC(sub_82299D44);
PPC_FUNC_IMPL(__imp__sub_82299D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299D48"))) PPC_WEAK_FUNC(sub_82299D48);
PPC_FUNC_IMPL(__imp__sub_82299D48) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r30
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82299d8c
	if (!cr6.gt) goto loc_82299D8C;
	// bl 0x821c9788
	ctx.lr = 0x82299D80;
	sub_821C9788(ctx, base);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// subf r3,r11,r3
	ctx.r3.s64 = ctx.r3.s64 - r11.s64;
	// b 0x82299d90
	goto loc_82299D90;
loc_82299D8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82299D90:
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

__attribute__((alias("__imp__sub_82299DA8"))) PPC_WEAK_FUNC(sub_82299DA8);
PPC_FUNC_IMPL(__imp__sub_82299DA8) {
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
	ctx.lr = 0x82299DB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82299DCC;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82299e0c
	if (cr6.eq) goto loc_82299E0C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82299DF4;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82299E00;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82299E0C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82299E18"))) PPC_WEAK_FUNC(sub_82299E18);
PPC_FUNC_IMPL(__imp__sub_82299E18) {
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
	ctx.lr = 0x82299E20;
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
	ctx.lr = 0x82299E44;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82299E50;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82299E60;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82299e84
	if (cr6.eq) goto loc_82299E84;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82299da8
	ctx.lr = 0x82299E74;
	sub_82299DA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299e88
	if (!cr6.eq) goto loc_82299E88;
loc_82299E84:
	// li r30,0
	r30.s64 = 0;
loc_82299E88:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82299ec0
	if (cr6.eq) goto loc_82299EC0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299eb8
	if (cr6.eq) goto loc_82299EB8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82299EA4;
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
loc_82299EB8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82299EC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82299ECC"))) PPC_WEAK_FUNC(sub_82299ECC);
PPC_FUNC_IMPL(__imp__sub_82299ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299ED0"))) PPC_WEAK_FUNC(sub_82299ED0);
PPC_FUNC_IMPL(__imp__sub_82299ED0) {
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
	ctx.lr = 0x82299ED8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x82299F08;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82299F14;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82299F24;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82299f58
	if (cr6.eq) goto loc_82299F58;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82299f58
	if (!cr6.eq) goto loc_82299F58;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x82299F48;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82299f5c
	if (!cr6.eq) goto loc_82299F5C;
loc_82299F58:
	// li r31,0
	r31.s64 = 0;
loc_82299F5C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82299f88
	if (cr6.eq) goto loc_82299F88;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299f80
	if (cr6.eq) goto loc_82299F80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82299F78;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82299f84
	goto loc_82299F84;
loc_82299F80:
	// li r11,0
	r11.s64 = 0;
loc_82299F84:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82299F88:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82299fac
	if (cr6.eq) goto loc_82299FAC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82299F9C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82299fb0
	if (cr6.eq) goto loc_82299FB0;
loc_82299FAC:
	// li r11,0
	r11.s64 = 0;
loc_82299FB0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82299FBC"))) PPC_WEAK_FUNC(sub_82299FBC);
PPC_FUNC_IMPL(__imp__sub_82299FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82299FC0"))) PPC_WEAK_FUNC(sub_82299FC0);
PPC_FUNC_IMPL(__imp__sub_82299FC0) {
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
	ctx.lr = 0x82299FC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,2308
	ctx.r3.s64 = 2308;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x82299FDC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a034
	if (cr6.eq) goto loc_8229A034;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229A000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8229A018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x821c2d88
	ctx.lr = 0x8229A030;
	sub_821C2D88(ctx, base);
	// b 0x8229a038
	goto loc_8229A038;
loc_8229A034:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8229A038:
	// stw r3,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229A050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1340
	ctx.r3.s64 = 1340;
	// bl 0x82130528
	ctx.lr = 0x8229A058;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a068
	if (cr6.eq) goto loc_8229A068;
	// bl 0x824ed2b0
	ctx.lr = 0x8229A064;
	sub_824ED2B0(ctx, base);
	// b 0x8229a06c
	goto loc_8229A06C;
loc_8229A068:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8229A06C:
	// stw r3,68(r30)
	PPC_STORE_U32(r30.u32 + 68, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r4,72(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r5,31
	ctx.r5.s64 = 31;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824f01d8
	ctx.lr = 0x8229A08C;
	sub_824F01D8(ctx, base);
	// mr r29,r27
	r29.u64 = r27.u64;
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
loc_8229A094:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8229A09C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a0b0
	if (cr6.eq) goto loc_8229A0B0;
	// bl 0x824ebf78
	ctx.lr = 0x8229A0A8;
	sub_824EBF78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8229a0b4
	goto loc_8229A0B4;
loc_8229A0B0:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_8229A0B4:
	// lis r11,-32214
	r11.s64 = -2111176704;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r10,r11,-25952
	ctx.r10.s64 = r11.s64 + -25952;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8229A0D0;
	sub_82130000(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ec120
	ctx.lr = 0x8229A0E4;
	sub_824EC120(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// blt cr6,0x8229a094
	if (cr6.lt) goto loc_8229A094;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229A100"))) PPC_WEAK_FUNC(sub_8229A100);
PPC_FUNC_IMPL(__imp__sub_8229A100) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,2100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229a178
	if (cr6.eq) goto loc_8229A178;
	// lwz r3,2092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2092);
	// addi r10,r11,2092
	ctx.r10.s64 = r11.s64 + 2092;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a178
	if (cr6.eq) goto loc_8229A178;
loc_8229A120:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a138
	if (cr6.eq) goto loc_8229A138;
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// b 0x8229a16c
	goto loc_8229A16C;
loc_8229A138:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a154
	if (cr6.eq) goto loc_8229A154;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a158
	if (!cr6.eq) goto loc_8229A158;
loc_8229A154:
	// li r11,0
	r11.s64 = 0;
loc_8229A158:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a16c
	if (cr6.eq) goto loc_8229A16C;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_8229A16C:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8229a120
	if (!cr6.eq) goto loc_8229A120;
loc_8229A178:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229A180"))) PPC_WEAK_FUNC(sub_8229A180);
PPC_FUNC_IMPL(__imp__sub_8229A180) {
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
	ctx.lr = 0x8229A188;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,2100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a240
	if (cr6.eq) goto loc_8229A240;
	// lwz r31,2092(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 2092);
	// addi r29,r30,2092
	r29.s64 = r30.s64 + 2092;
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a240
	if (cr6.eq) goto loc_8229A240;
	// li r27,1
	r27.s64 = 1;
loc_8229A1B8:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e6358
	ctx.lr = 0x8229A1C4;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a1f4
	if (cr6.eq) goto loc_8229A1F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82273ae0
	ctx.lr = 0x8229A1DC;
	sub_82273AE0(ctx, base);
	// addi r4,r30,2080
	ctx.r4.s64 = r30.s64 + 2080;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822996f0
	ctx.lr = 0x8229A1F0;
	sub_822996F0(ctx, base);
	// stb r27,2104(r30)
	PPC_STORE_U8(r30.u32 + 2104, r27.u8);
loc_8229A1F4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a204
	if (cr6.eq) goto loc_8229A204;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8229a238
	goto loc_8229A238;
loc_8229A204:
	// rlwinm r11,r28,0,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a220
	if (cr6.eq) goto loc_8229A220;
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bne cr6,0x8229a224
	if (!cr6.eq) goto loc_8229A224;
loc_8229A220:
	// li r11,0
	r11.s64 = 0;
loc_8229A224:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a240
	if (cr6.eq) goto loc_8229A240;
	// rlwinm r28,r28,0,0,30
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_8229A238:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229a1b8
	if (!cr6.eq) goto loc_8229A1B8;
loc_8229A240:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8229A248"))) PPC_WEAK_FUNC(sub_8229A248);
PPC_FUNC_IMPL(__imp__sub_8229A248) {
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
	ctx.lr = 0x8229A250;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,2100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a310
	if (cr6.eq) goto loc_8229A310;
	// lwz r31,2092(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 2092);
	// addi r29,r28,2092
	r29.s64 = r28.s64 + 2092;
	// mr r30,r29
	r30.u64 = r29.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a310
	if (cr6.eq) goto loc_8229A310;
loc_8229A27C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x824f92f8
	ctx.lr = 0x8229A288;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229a2e8
	if (!cr6.eq) goto loc_8229A2E8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a2a4
	if (cr6.eq) goto loc_8229A2A4;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8229a2d8
	goto loc_8229A2D8;
loc_8229A2A4:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a2c0
	if (cr6.eq) goto loc_8229A2C0;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a2c4
	if (!cr6.eq) goto loc_8229A2C4;
loc_8229A2C0:
	// li r11,0
	r11.s64 = 0;
loc_8229A2C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a310
	if (cr6.eq) goto loc_8229A310;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8229A2D8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229a27c
	if (!cr6.eq) goto loc_8229A27C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8229A2E8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82273ae0
	ctx.lr = 0x8229A2F4;
	sub_82273AE0(ctx, base);
	// addi r4,r28,2080
	ctx.r4.s64 = r28.s64 + 2080;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822996f0
	ctx.lr = 0x8229A308;
	sub_822996F0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,2104(r28)
	PPC_STORE_U8(r28.u32 + 2104, r11.u8);
loc_8229A310:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229A318"))) PPC_WEAK_FUNC(sub_8229A318);
PPC_FUNC_IMPL(__imp__sub_8229A318) {
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
	ctx.lr = 0x8229A320;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16960
	ctx.r10.s64 = r11.s64 + 16960;
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
	// bl 0x82299e18
	ctx.lr = 0x8229A354;
	sub_82299E18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a38c
	if (cr6.eq) goto loc_8229A38C;
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
	ctx.lr = 0x8229A37C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a390
	if (!cr6.eq) goto loc_8229A390;
loc_8229A38C:
	// li r11,0
	r11.s64 = 0;
loc_8229A390:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229A39C"))) PPC_WEAK_FUNC(sub_8229A39C);
PPC_FUNC_IMPL(__imp__sub_8229A39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229A3A0"))) PPC_WEAK_FUNC(sub_8229A3A0);
PPC_FUNC_IMPL(__imp__sub_8229A3A0) {
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
	ctx.lr = 0x8229A3A8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16928
	ctx.r10.s64 = r11.s64 + 16928;
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
	// bl 0x82299e18
	ctx.lr = 0x8229A3DC;
	sub_82299E18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a414
	if (cr6.eq) goto loc_8229A414;
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
	ctx.lr = 0x8229A404;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a418
	if (!cr6.eq) goto loc_8229A418;
loc_8229A414:
	// li r11,0
	r11.s64 = 0;
loc_8229A418:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229A424"))) PPC_WEAK_FUNC(sub_8229A424);
PPC_FUNC_IMPL(__imp__sub_8229A424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229A428"))) PPC_WEAK_FUNC(sub_8229A428);
PPC_FUNC_IMPL(__imp__sub_8229A428) {
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
	ctx.lr = 0x8229A430;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,19
	r29.s64 = 19;
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
	// li r31,0
	r31.s64 = 0;
loc_8229A444:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6400
	ctx.lr = 0x8229A44C;
	sub_824E6400(ctx, base);
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// bl 0x824f9438
	ctx.lr = 0x8229A454;
	sub_824F9438(ctx, base);
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// stw r31,84(r30)
	PPC_STORE_U32(r30.u32 + 84, r31.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stb r31,-16(r30)
	PPC_STORE_U8(r30.u32 + -16, r31.u8);
	// addi r30,r30,104
	r30.s64 = r30.s64 + 104;
	// bge 0x8229a444
	if (!cr0.lt) goto loc_8229A444;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r31,2080(r28)
	PPC_STORE_U32(r28.u32 + 2080, r31.u32);
	// stw r31,2084(r28)
	PPC_STORE_U32(r28.u32 + 2084, r31.u32);
	// addi r11,r28,2080
	r11.s64 = r28.s64 + 2080;
	// stw r31,2088(r28)
	PPC_STORE_U32(r28.u32 + 2088, r31.u32);
	// addi r10,r28,204
	ctx.r10.s64 = r28.s64 + 204;
	// stw r31,2092(r28)
	PPC_STORE_U32(r28.u32 + 2092, r31.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r31,2096(r28)
	PPC_STORE_U32(r28.u32 + 2096, r31.u32);
	// stw r31,2100(r28)
	PPC_STORE_U32(r28.u32 + 2100, r31.u32);
	// stb r9,2104(r28)
	PPC_STORE_U8(r28.u32 + 2104, ctx.r9.u8);
loc_8229A498:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r8,r10,-204
	ctx.r8.s64 = ctx.r10.s64 + -204;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a4c8
	if (cr6.eq) goto loc_8229A4C8;
	// stw r8,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,-104(r10)
	PPC_STORE_U32(ctx.r10.u32 + -104, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8229a4d0
	if (!cr6.eq) goto loc_8229A4D0;
	// b 0x8229a4cc
	goto loc_8229A4CC;
loc_8229A4C8:
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_8229A4CC:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
loc_8229A4D0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r9,r10,-100
	ctx.r9.s64 = ctx.r10.s64 + -100;
	// beq cr6,0x8229a508
	if (cr6.eq) goto loc_8229A508;
	// stw r9,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x8229a510
	if (!cr6.eq) goto loc_8229A510;
	// b 0x8229a50c
	goto loc_8229A50C;
loc_8229A508:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8229A50C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8229A510:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// beq cr6,0x8229a548
	if (cr6.eq) goto loc_8229A548;
	// stw r8,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8229a550
	if (!cr6.eq) goto loc_8229A550;
	// b 0x8229a54c
	goto loc_8229A54C;
loc_8229A548:
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_8229A54C:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
loc_8229A550:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r9,r10,108
	ctx.r9.s64 = ctx.r10.s64 + 108;
	// beq cr6,0x8229a588
	if (cr6.eq) goto loc_8229A588;
	// stw r9,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,208(r10)
	PPC_STORE_U32(ctx.r10.u32 + 208, ctx.r8.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bne cr6,0x8229a590
	if (!cr6.eq) goto loc_8229A590;
	// b 0x8229a58c
	goto loc_8229A58C;
loc_8229A588:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8229A58C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8229A590:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// beq cr6,0x8229a5cc
	if (cr6.eq) goto loc_8229A5CC;
	// addi r8,r10,212
	ctx.r8.s64 = ctx.r10.s64 + 212;
	// stw r8,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,312(r10)
	PPC_STORE_U32(ctx.r10.u32 + 312, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8229a5d8
	if (!cr6.eq) goto loc_8229A5D8;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// b 0x8229a5d8
	goto loc_8229A5D8;
loc_8229A5CC:
	// addi r9,r10,212
	ctx.r9.s64 = ctx.r10.s64 + 212;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8229A5D8:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r10,520
	ctx.r10.s64 = ctx.r10.s64 + 520;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// bne 0x8229a498
	if (!cr0.eq) goto loc_8229A498;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229A5FC"))) PPC_WEAK_FUNC(sub_8229A5FC);
PPC_FUNC_IMPL(__imp__sub_8229A5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229A600"))) PPC_WEAK_FUNC(sub_8229A600);
PPC_FUNC_IMPL(__imp__sub_8229A600) {
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
	ctx.lr = 0x8229A608;
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
	// blt cr6,0x8229a674
	if (cr6.lt) goto loc_8229A674;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8229A630;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229a654
	if (!cr6.eq) goto loc_8229A654;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8229A648;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a674
	if (cr6.eq) goto loc_8229A674;
loc_8229A654:
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
	// bl 0x8229a318
	ctx.lr = 0x8229A66C;
	sub_8229A318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229A674:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229A680"))) PPC_WEAK_FUNC(sub_8229A680);
PPC_FUNC_IMPL(__imp__sub_8229A680) {
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
	ctx.lr = 0x8229A688;
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
	// blt cr6,0x8229a6f4
	if (cr6.lt) goto loc_8229A6F4;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8229A6B0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229a6d4
	if (!cr6.eq) goto loc_8229A6D4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8229A6C8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a6f4
	if (cr6.eq) goto loc_8229A6F4;
loc_8229A6D4:
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
	// bl 0x8229a3a0
	ctx.lr = 0x8229A6EC;
	sub_8229A3A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229A6F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229A700"))) PPC_WEAK_FUNC(sub_8229A700);
PPC_FUNC_IMPL(__imp__sub_8229A700) {
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
	ctx.lr = 0x8229A708;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r9,r10,16928
	ctx.r9.s64 = ctx.r10.s64 + 16928;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8229a788
	if (!cr6.eq) goto loc_8229A788;
	// li r11,0
	r11.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82299ed0
	ctx.lr = 0x8229A748;
	sub_82299ED0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229a77c
	if (cr6.eq) goto loc_8229A77C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8229a600
	ctx.lr = 0x8229A77C;
	sub_8229A600(ctx, base);
loc_8229A77C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229A788:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,16960
	ctx.r9.s64 = ctx.r10.s64 + 16960;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8229a818
	if (!cr6.eq) goto loc_8229A818;
	// li r11,0
	r11.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82299ed0
	ctx.lr = 0x8229A7B8;
	sub_82299ED0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229a80c
	if (cr6.eq) goto loc_8229A80C;
	// bl 0x821c9788
	ctx.lr = 0x8229A7C8;
	sub_821C9788(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229A7E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229a80c
	if (cr6.eq) goto loc_8229A80C;
	// lwz r11,204(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	// stw r10,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r10.u32);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8229A80C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229A80C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229A818:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229A824"))) PPC_WEAK_FUNC(sub_8229A824);
PPC_FUNC_IMPL(__imp__sub_8229A824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229A828"))) PPC_WEAK_FUNC(sub_8229A828);
PPC_FUNC_IMPL(__imp__sub_8229A828) {
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
	// bl 0x821c9788
	ctx.lr = 0x8229A844;
	sub_821C9788(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8229a680
	ctx.lr = 0x8229A86C;
	sub_8229A680(ctx, base);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
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

__attribute__((alias("__imp__sub_8229A888"))) PPC_WEAK_FUNC(sub_8229A888);
PPC_FUNC_IMPL(__imp__sub_8229A888) {
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
	ctx.lr = 0x8229A890;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,2100(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a938
	if (cr6.eq) goto loc_8229A938;
	// lwz r31,2092(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 2092);
	// addi r30,r28,2092
	r30.s64 = r28.s64 + 2092;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a938
	if (cr6.eq) goto loc_8229A938;
	// addi r29,r27,176
	r29.s64 = r27.s64 + 176;
loc_8229A8BC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x824f92f8
	ctx.lr = 0x8229A8C8;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a8ec
	if (cr6.eq) goto loc_8229A8EC;
	// addi r4,r27,112
	ctx.r4.s64 = r27.s64 + 112;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e6358
	ctx.lr = 0x8229A8E0;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229aa68
	if (!cr6.eq) goto loc_8229AA68;
loc_8229A8EC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229a8fc
	if (cr6.eq) goto loc_8229A8FC;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8229a930
	goto loc_8229A930;
loc_8229A8FC:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a918
	if (cr6.eq) goto loc_8229A918;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229a91c
	if (!cr6.eq) goto loc_8229A91C;
loc_8229A918:
	// li r11,0
	r11.s64 = 0;
loc_8229A91C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229a938
	if (cr6.eq) goto loc_8229A938;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8229A930:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229a8bc
	if (!cr6.eq) goto loc_8229A8BC;
loc_8229A938:
	// addi r30,r27,176
	r30.s64 = r27.s64 + 176;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8229a248
	ctx.lr = 0x8229A948;
	sub_8229A248(ctx, base);
	// lwz r11,2088(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 2088);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229aa68
	if (cr6.eq) goto loc_8229AA68;
	// lwz r4,2080(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 2080);
	// addi r3,r28,2080
	ctx.r3.s64 = r28.s64 + 2080;
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229a96c
	if (cr6.eq) goto loc_8229A96C;
	// bl 0x82273ae0
	ctx.lr = 0x8229A96C;
	sub_82273AE0(ctx, base);
loc_8229A96C:
	// lwz r10,192(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 192);
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r8,15
	ctx.r8.s64 = 15;
loc_8229A978:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229aa08
	if (cr6.eq) goto loc_8229AA08;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a9ec
	if (cr6.eq) goto loc_8229A9EC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a9f4
	if (cr6.eq) goto loc_8229A9F4;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229a9fc
	if (cr6.eq) goto loc_8229A9FC;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229aa04
	if (cr6.eq) goto loc_8229AA04;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addic. r8,r8,-5
	xer.ca = ctx.r8.u32 > 4;
	ctx.r8.s64 = ctx.r8.s64 + -5;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// bgt 0x8229a978
	if (cr0.gt) goto loc_8229A978;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229A9EC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229A9F4:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229A9FC:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x8229aa08
	goto loc_8229AA08;
loc_8229AA04:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8229AA08:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r27,112
	ctx.r4.s64 = r27.s64 + 112;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x8229AA20;
	sub_823DA950(ctx, base);
	// ld r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// addi r4,r28,2092
	ctx.r4.s64 = r28.s64 + 2092;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r9,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r9.u64);
	// ld r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// std r8,88(r31)
	PPC_STORE_U64(r31.u32 + 88, ctx.r8.u64);
	// bl 0x822996f0
	ctx.lr = 0x8229AA44;
	sub_822996F0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// stb r7,2104(r28)
	PPC_STORE_U8(r28.u32 + 2104, ctx.r7.u8);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,13
	ctx.r5.s64 = 13;
	// lwz r4,-10240(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10240);
	// addis r3,r4,5
	ctx.r3.s64 = ctx.r4.s64 + 327680;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x822990d8
	ctx.lr = 0x8229AA68;
	sub_822990D8(ctx, base);
loc_8229AA68:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229AA70"))) PPC_WEAK_FUNC(sub_8229AA70);
PPC_FUNC_IMPL(__imp__sub_8229AA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8229AA80:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8229aa80
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229AA80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229AA90"))) PPC_WEAK_FUNC(sub_8229AA90);
PPC_FUNC_IMPL(__imp__sub_8229AA90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// bne cr6,0x8229aaac
	if (!cr6.eq) goto loc_8229AAAC;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x8229aad4
	goto loc_8229AAD4;
loc_8229AAAC:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r11,r6,r5
	r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// lfs f12,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
loc_8229AAD4:
	// lhz r11,2(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229aae8
	if (!cr6.eq) goto loc_8229AAE8;
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
	// b 0x8229ab10
	goto loc_8229AB10;
loc_8229AAE8:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r11,r6,r5
	r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
loc_8229AB10:
	// lhz r11,0(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ab44
	if (cr6.eq) goto loc_8229AB44;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r4.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
loc_8229AB44:
	// stfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229AB54"))) PPC_WEAK_FUNC(sub_8229AB54);
PPC_FUNC_IMPL(__imp__sub_8229AB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229AB58"))) PPC_WEAK_FUNC(sub_8229AB58);
PPC_FUNC_IMPL(__imp__sub_8229AB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-12(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// fabs f13,f10
	ctx.f13.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fabs f0,f11
	f0.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8229ab90
	if (!cr6.gt) goto loc_8229AB90;
	// li r9,1
	ctx.r9.s64 = 1;
	// fmr f9,f11
	ctx.f9.f64 = ctx.f11.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229AB90:
	// lfs f12,-8(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fabs f0,f12
	f0.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8229abac
	if (!cr6.gt) goto loc_8229ABAC;
	// li r9,2
	ctx.r9.s64 = 2;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229ABAC:
	// lfs f0,-4(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	f0.f64 = double(temp.f32);
	// fabs f8,f0
	ctx.f8.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f13
	cr6.compare(ctx.f8.f64, ctx.f13.f64);
	// ble cr6,0x8229abc8
	if (!cr6.gt) goto loc_8229ABC8;
	// li r9,3
	ctx.r9.s64 = 3;
	// fmr f9,f0
	ctx.f9.f64 = f0.f64;
	// fmr f13,f8
	ctx.f13.f64 = ctx.f8.f64;
loc_8229ABC8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f8,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f9,f8
	cr6.compare(ctx.f9.f64, ctx.f8.f64);
	// bgt cr6,0x8229abe0
	if (cr6.gt) goto loc_8229ABE0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8229ABE0:
	// fcmpu cr6,f13,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f8.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8229abf0
	if (cr6.gt) goto loc_8229ABF0;
	// li r11,0
	r11.s64 = 0;
loc_8229ABF0:
	// xor r11,r11,r10
	r11.u64 = r11.u64 ^ ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8229ac0c
	if (cr6.eq) goto loc_8229AC0C;
	// fneg f10,f10
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fneg f11,f11
	ctx.f11.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_8229AC0C:
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bgt cr6,0x8229ac4c
	if (cr6.gt) goto loc_8229AC4C;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-21460
	r12.s64 = r12.s64 + -21460;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_8229AC3C;
	case 1:
		goto loc_8229AC40;
	case 2:
		goto loc_8229AC44;
	case 3:
		goto loc_8229AC58;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-21444(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21444);
	// lwz r17,-21440(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21440);
	// lwz r17,-21436(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21436);
	// lwz r17,-21416(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21416);
loc_8229AC3C:
	// fmr f10,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f11.f64;
loc_8229AC40:
	// fmr f11,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f12.f64;
loc_8229AC44:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f0.f64;
	// b 0x8229ac58
	goto loc_8229AC58;
loc_8229AC4C:
	// lfs f12,-8(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
loc_8229AC58:
	// lis r11,-32253
	r11.s64 = -2113732608;
}

__attribute__((alias("__imp__sub_8229AD2C"))) PPC_WEAK_FUNC(sub_8229AD2C);
PPC_FUNC_IMPL(__imp__sub_8229AD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229AD30"))) PPC_WEAK_FUNC(sub_8229AD30);
PPC_FUNC_IMPL(__imp__sub_8229AD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// rlwinm r8,r11,20,22,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x3FF;
	// rlwinm r7,r11,10,22,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x3FF;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f11,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r6,r11,30,22,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FF;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lfs f0,300(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 300);
	f0.f64 = double(temp.f32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// fcfid f5,f10
	ctx.f5.f64 = double(ctx.f10.s64);
	// lfs f13,12512(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12512);
	ctx.f13.f64 = double(temp.f32);
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// lfs f12,32232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32232);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// lfs f9,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// fmuls f1,f3,f0
	ctx.f1.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fmsubs f11,f4,f13,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmuls f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * f0.f64));
	// fmsubs f0,f1,f13,f12
	f0.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmuls f7,f11,f11
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// fmadds f6,f0,f0,f7
	ctx.f6.f64 = double(float(f0.f64 * f0.f64 + ctx.f7.f64));
	// fmsubs f0,f8,f13,f12
	f0.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmadds f5,f0,f0,f6
	ctx.f5.f64 = double(float(f0.f64 * f0.f64 + ctx.f6.f64));
	// fsubs f4,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// fsqrts f13,f4
	ctx.f13.f64 = double(float(sqrt(ctx.f4.f64)));
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-21020
	r12.s64 = r12.s64 + -21020;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8229ADF4;
	case 1:
		goto loc_8229AE08;
	case 2:
		goto loc_8229AE1C;
	case 3:
		goto loc_8229AE30;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-21004(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21004);
	// lwz r17,-20984(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20984);
	// lwz r17,-20964(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20964);
	// lwz r17,-20944(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20944);
loc_8229ADF4:
	// stfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f11,4(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f10,8(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
loc_8229AE08:
	// stfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f10,8(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
loc_8229AE1C:
	// stfs f13,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f10,4(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
loc_8229AE30:
	// stfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
}

__attribute__((alias("__imp__sub_8229AE44"))) PPC_WEAK_FUNC(sub_8229AE44);
PPC_FUNC_IMPL(__imp__sub_8229AE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229AE48"))) PPC_WEAK_FUNC(sub_8229AE48);
PPC_FUNC_IMPL(__imp__sub_8229AE48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229aa90
	ctx.lr = 0x8229AE68;
	sub_8229AA90(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8229AE84"))) PPC_WEAK_FUNC(sub_8229AE84);
PPC_FUNC_IMPL(__imp__sub_8229AE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229AE88"))) PPC_WEAK_FUNC(sub_8229AE88);
PPC_FUNC_IMPL(__imp__sub_8229AE88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// addi r4,r3,22
	ctx.r4.s64 = ctx.r3.s64 + 22;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229aa90
	ctx.lr = 0x8229AEA8;
	sub_8229AA90(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8229AEC4"))) PPC_WEAK_FUNC(sub_8229AEC4);
PPC_FUNC_IMPL(__imp__sub_8229AEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229AEC8"))) PPC_WEAK_FUNC(sub_8229AEC8);
PPC_FUNC_IMPL(__imp__sub_8229AEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// stb r11,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r11.u8);
	// stb r11,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r11.u8);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r11.u8);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, r11.u8);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229AF08"))) PPC_WEAK_FUNC(sub_8229AF08);
PPC_FUNC_IMPL(__imp__sub_8229AF08) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,16
	ctx.r10.s64 = r31.s64 + 16;
	// li r9,8
	ctx.r9.s64 = 8;
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// stb r11,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r11.u8);
	// stb r11,3(r31)
	PPC_STORE_U8(r31.u32 + 3, r11.u8);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// stb r11,6(r31)
	PPC_STORE_U8(r31.u32 + 6, r11.u8);
	// stb r11,7(r31)
	PPC_STORE_U8(r31.u32 + 7, r11.u8);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// stb r11,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r11.u8);
	// stb r11,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r11.u8);
	// stb r11,11(r31)
	PPC_STORE_U8(r31.u32 + 11, r11.u8);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// stb r11,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r11.u8);
	// stb r11,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r11.u8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8229AF64:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8229af64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229AF64;
	// li r5,52
	ctx.r5.s64 = 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8229AF80;
	sub_823D9890(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r10,r11,27
	ctx.r10.u64 = r11.u32 & 0x1F;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229AFA4"))) PPC_WEAK_FUNC(sub_8229AFA4);
PPC_FUNC_IMPL(__imp__sub_8229AFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229AFA8"))) PPC_WEAK_FUNC(sub_8229AFA8);
PPC_FUNC_IMPL(__imp__sub_8229AFA8) {
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
	ctx.lr = 0x8229AFB0;
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
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x82618f70
	ctx.lr = 0x8229AFD0;
	sub_82618F70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0ec
	if (cr6.eq) goto loc_8229B0EC;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r11,25,7,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x82618f70
	ctx.lr = 0x8229AFEC;
	sub_82618F70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0ec
	if (cr6.eq) goto loc_8229B0EC;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r4,r11,26,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// bl 0x82618f70
	ctx.lr = 0x8229B008;
	sub_82618F70(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0ec
	if (cr6.eq) goto loc_8229B0EC;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b070
	if (cr6.eq) goto loc_8229B070;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B034;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b060
	if (cr6.eq) goto loc_8229B060;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B050;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b064
	if (!cr6.eq) goto loc_8229B064;
loc_8229B060:
	// li r11,0
	r11.s64 = 0;
loc_8229B064:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8229B070:
	// rlwinm r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b09c
	if (cr6.eq) goto loc_8229B09C;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B08C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b0a0
	if (cr6.eq) goto loc_8229B0A0;
loc_8229B09C:
	// li r11,1
	r11.s64 = 1;
loc_8229B0A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229b0f0
	if (cr6.eq) goto loc_8229B0F0;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b0dc
	if (cr6.eq) goto loc_8229B0DC;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B0CC;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b0e0
	if (cr6.eq) goto loc_8229B0E0;
loc_8229B0DC:
	// li r11,1
	r11.s64 = 1;
loc_8229B0E0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8229B0EC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8229B0F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229B0F8"))) PPC_WEAK_FUNC(sub_8229B0F8);
PPC_FUNC_IMPL(__imp__sub_8229B0F8) {
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
	ctx.lr = 0x8229B100;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x82618f10
	ctx.lr = 0x8229B11C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b25c
	if (cr6.eq) goto loc_8229B25C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f10
	ctx.lr = 0x8229B134;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b25c
	if (cr6.eq) goto loc_8229B25C;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f10
	ctx.lr = 0x8229B14C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b25c
	if (cr6.eq) goto loc_8229B25C;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwimi r10,r11,2,22,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 2) & 0x3FC) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFC03);
	// lbz r6,82(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// clrlwi r7,r10,22
	ctx.r7.u64 = ctx.r10.u32 & 0x3FF;
	// rlwinm r7,r7,0,31,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwimi r9,r7,5,0,26
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 5) & 0xFFFFFFE0) | (ctx.r9.u64 & 0xFFFFFFFF0000001F);
	// rlwimi r9,r6,6,25,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 6) & 0x40) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r4,r5,0,26,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// stb r5,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r5.u8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229b1dc
	if (cr6.eq) goto loc_8229B1DC;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B1A0;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b1cc
	if (cr6.eq) goto loc_8229B1CC;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B1BC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b1d0
	if (!cr6.eq) goto loc_8229B1D0;
loc_8229B1CC:
	// li r11,0
	r11.s64 = 0;
loc_8229B1D0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229B1DC:
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b20c
	if (cr6.eq) goto loc_8229B20C;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B1FC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b210
	if (cr6.eq) goto loc_8229B210;
loc_8229B20C:
	// li r11,1
	r11.s64 = 1;
loc_8229B210:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229b260
	if (cr6.eq) goto loc_8229B260;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b24c
	if (cr6.eq) goto loc_8229B24C;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8229B23C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229b250
	if (cr6.eq) goto loc_8229B250;
loc_8229B24C:
	// li r11,1
	r11.s64 = 1;
loc_8229B250:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8229B25C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8229B260:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229B268"))) PPC_WEAK_FUNC(sub_8229B268);
PPC_FUNC_IMPL(__imp__sub_8229B268) {
	PPC_FUNC_PROLOGUE();
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229ab58
	ctx.lr = 0x8229B290;
	sub_8229AB58(ctx, base);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lfs f13,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lfs f12,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
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

__attribute__((alias("__imp__sub_8229B2C0"))) PPC_WEAK_FUNC(sub_8229B2C0);
PPC_FUNC_IMPL(__imp__sub_8229B2C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8229ad30
	ctx.lr = 0x8229B2E4;
	sub_8229AD30(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r10,16
	ctx.r10.s64 = 16;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f12,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,0(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f10,4(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f8,12(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8229B348"))) PPC_WEAK_FUNC(sub_8229B348);
PPC_FUNC_IMPL(__imp__sub_8229B348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
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
	// bl 0x823d91f4
	ctx.lr = 0x8229B350;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x8261da20
	ctx.lr = 0x8229B374;
	sub_8261DA20(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229ab58
	ctx.lr = 0x8229B380;
	sub_8229AB58(ctx, base);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f1,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f30.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x8229B3B0;
	sub_8213E850(ctx, base);
	// addi r3,r30,2
	ctx.r3.s64 = r30.s64 + 2;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3BC;
	sub_8213E850(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3C8;
	sub_8213E850(ctx, base);
	// addi r30,r31,22
	r30.s64 = r31.s64 + 22;
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f31,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f30.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x8229B3E0;
	sub_8213E850(ctx, base);
	// addi r3,r30,2
	ctx.r3.s64 = r30.s64 + 2;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3EC;
	sub_8213E850(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213e850
	ctx.lr = 0x8229B3F8;
	sub_8213E850(ctx, base);
	// stb r27,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r27.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229B40C"))) PPC_WEAK_FUNC(sub_8229B40C);
PPC_FUNC_IMPL(__imp__sub_8229B40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B410"))) PPC_WEAK_FUNC(sub_8229B410);
PPC_FUNC_IMPL(__imp__sub_8229B410) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b2c0
	ctx.lr = 0x8229B430;
	sub_8229B2C0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8261d9d0
	ctx.lr = 0x8229B438;
	sub_8261D9D0(ctx, base);
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

__attribute__((alias("__imp__sub_8229B44C"))) PPC_WEAK_FUNC(sub_8229B44C);
PPC_FUNC_IMPL(__imp__sub_8229B44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B450"))) PPC_WEAK_FUNC(sub_8229B450);
PPC_FUNC_IMPL(__imp__sub_8229B450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8256(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8256);
	// li r11,0
	r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// clrlwi r8,r10,25
	ctx.r8.u64 = ctx.r10.u32 & 0x7F;
	// stw r11,8252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8252, r11.u32);
	// stw r11,8260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8260, r11.u32);
	// stb r8,8256(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8256, ctx.r8.u8);
	// stw r9,8272(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8272, ctx.r9.u32);
	// stw r11,8264(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8264, r11.u32);
	// stw r11,8268(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8268, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229B47C"))) PPC_WEAK_FUNC(sub_8229B47C);
PPC_FUNC_IMPL(__imp__sub_8229B47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B480"))) PPC_WEAK_FUNC(sub_8229B480);
PPC_FUNC_IMPL(__imp__sub_8229B480) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618750
	ctx.lr = 0x8229B4A4;
	sub_82618750(ctx, base);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8229B4B4;
	sub_82618640(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238fd38
	ctx.lr = 0x8229B4C0;
	sub_8238FD38(ctx, base);
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r10.u8);
	// bl 0x826186a0
	ctx.lr = 0x8229B4D4;
	sub_826186A0(ctx, base);
	// stw r3,8252(r31)
	PPC_STORE_U32(r31.u32 + 8252, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8229B4F0"))) PPC_WEAK_FUNC(sub_8229B4F0);
PPC_FUNC_IMPL(__imp__sub_8229B4F0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229b54c
	if (cr6.eq) goto loc_8229B54C;
	// lwz r11,8252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8229b54c
	if (!cr6.gt) goto loc_8229B54C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8229B530;
	sub_82618750(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,8252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// bl 0x826185e0
	ctx.lr = 0x8229B540;
	sub_826185E0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82390940
	ctx.lr = 0x8229B54C;
	sub_82390940(ctx, base);
loc_8229B54C:
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

__attribute__((alias("__imp__sub_8229B564"))) PPC_WEAK_FUNC(sub_8229B564);
PPC_FUNC_IMPL(__imp__sub_8229B564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B568"))) PPC_WEAK_FUNC(sub_8229B568);
PPC_FUNC_IMPL(__imp__sub_8229B568) {
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
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// bl 0x82500cf8
	ctx.lr = 0x8229B584;
	sub_82500CF8(ctx, base);
	// lbz r9,8256(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,8252(r31)
	PPC_STORE_U32(r31.u32 + 8252, r11.u32);
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8272(r31)
	PPC_STORE_U32(r31.u32 + 8272, ctx.r10.u32);
	// stw r11,8264(r31)
	PPC_STORE_U32(r31.u32 + 8264, r11.u32);
	// stw r11,8268(r31)
	PPC_STORE_U32(r31.u32 + 8268, r11.u32);
	// stb r8,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r8.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229B5C4"))) PPC_WEAK_FUNC(sub_8229B5C4);
PPC_FUNC_IMPL(__imp__sub_8229B5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B5C8"))) PPC_WEAK_FUNC(sub_8229B5C8);
PPC_FUNC_IMPL(__imp__sub_8229B5C8) {
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
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8229b6a0
	if (!cr6.eq) goto loc_8229B6A0;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b624
	if (cr6.eq) goto loc_8229B624;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r7,8252(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// lwz r5,8272(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8272);
	// bl 0x82500df8
	ctx.lr = 0x8229B60C;
	sub_82500DF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, ctx.r8.u32);
	// b 0x8229b6a0
	goto loc_8229B6A0;
loc_8229B624:
	// bl 0x821c9788
	ctx.lr = 0x8229B628;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821ce460
	ctx.lr = 0x8229B638;
	sub_821CE460(ctx, base);
	// lis r11,23772
	r11.s64 = 1557921792;
	// lis r10,-32116
	ctx.r10.s64 = -2104754176;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ori r9,r11,64167
	ctx.r9.u64 = r11.u64 | 64167;
	// ori r8,r10,49087
	ctx.r8.u64 = ctx.r10.u64 | 49087;
	// mulld r10,r5,r9
	ctx.r10.s64 = ctx.r5.s64 * ctx.r9.s64;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r10,r11,1
	ctx.r10.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rldicl r3,r11,32,32
	ctx.r3.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulhw r11,r10,r8
	r11.s64 = (int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32)) >> 32;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// srawi r11,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	r11.s64 = r11.s32 >> 7;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// mulli r8,r9,251
	ctx.r8.s64 = ctx.r9.s64 * 251;
	// subf r11,r8,r10
	r11.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r30,r11,250
	r30.s64 = r11.s64 + 250;
	// bl 0x821c9788
	ctx.lr = 0x8229B690;
	sub_821C9788(ctx, base);
	// add r7,r3,r30
	ctx.r7.u64 = ctx.r3.u64 + r30.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r7,8264(r31)
	PPC_STORE_U32(r31.u32 + 8264, ctx.r7.u32);
	// stw r6,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, ctx.r6.u32);
loc_8229B6A0:
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

__attribute__((alias("__imp__sub_8229B6B8"))) PPC_WEAK_FUNC(sub_8229B6B8);
PPC_FUNC_IMPL(__imp__sub_8229B6B8) {
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
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B6DC;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b704
	if (cr6.eq) goto loc_8229B704;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// bl 0x82618f70
	ctx.lr = 0x8229B6F4;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b708
	if (!cr6.eq) goto loc_8229B708;
loc_8229B704:
	// li r11,0
	r11.s64 = 0;
loc_8229B708:
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

__attribute__((alias("__imp__sub_8229B724"))) PPC_WEAK_FUNC(sub_8229B724);
PPC_FUNC_IMPL(__imp__sub_8229B724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B728"))) PPC_WEAK_FUNC(sub_8229B728);
PPC_FUNC_IMPL(__imp__sub_8229B728) {
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
	ctx.lr = 0x8229B730;
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
	ctx.lr = 0x8229B754;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8229B760;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8229B770;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229b794
	if (cr6.eq) goto loc_8229B794;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b6b8
	ctx.lr = 0x8229B784;
	sub_8229B6B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229b798
	if (!cr6.eq) goto loc_8229B798;
loc_8229B794:
	// li r30,0
	r30.s64 = 0;
loc_8229B798:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229b7d0
	if (cr6.eq) goto loc_8229B7D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b7c8
	if (cr6.eq) goto loc_8229B7C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8229B7B4;
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
loc_8229B7C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8229B7D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229B7DC"))) PPC_WEAK_FUNC(sub_8229B7DC);
PPC_FUNC_IMPL(__imp__sub_8229B7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B7E0"))) PPC_WEAK_FUNC(sub_8229B7E0);
PPC_FUNC_IMPL(__imp__sub_8229B7E0) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8226b338
	ctx.lr = 0x8229B808;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b850
	if (cr6.eq) goto loc_8229B850;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B824;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b850
	if (cr6.eq) goto loc_8229B850;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x8229B840;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b854
	if (!cr6.eq) goto loc_8229B854;
loc_8229B850:
	// li r11,0
	r11.s64 = 0;
loc_8229B854:
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

__attribute__((alias("__imp__sub_8229B870"))) PPC_WEAK_FUNC(sub_8229B870);
PPC_FUNC_IMPL(__imp__sub_8229B870) {
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
	ctx.lr = 0x8229B878;
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
	ctx.lr = 0x8229B89C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8229B8A8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8229B8B8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229b8dc
	if (cr6.eq) goto loc_8229B8DC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8229b7e0
	ctx.lr = 0x8229B8CC;
	sub_8229B7E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229b8e0
	if (!cr6.eq) goto loc_8229B8E0;
loc_8229B8DC:
	// li r30,0
	r30.s64 = 0;
loc_8229B8E0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229b918
	if (cr6.eq) goto loc_8229B918;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229b910
	if (cr6.eq) goto loc_8229B910;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8229B8FC;
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
loc_8229B910:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8229B918:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229B924"))) PPC_WEAK_FUNC(sub_8229B924);
PPC_FUNC_IMPL(__imp__sub_8229B924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B928"))) PPC_WEAK_FUNC(sub_8229B928);
PPC_FUNC_IMPL(__imp__sub_8229B928) {
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
	ctx.lr = 0x8229B930;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16088
	ctx.r10.s64 = r11.s64 + 16088;
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
	// bl 0x8229b728
	ctx.lr = 0x8229B964;
	sub_8229B728(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229b99c
	if (cr6.eq) goto loc_8229B99C;
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
	ctx.lr = 0x8229B98C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229b9a0
	if (!cr6.eq) goto loc_8229B9A0;
loc_8229B99C:
	// li r11,0
	r11.s64 = 0;
loc_8229B9A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229B9AC"))) PPC_WEAK_FUNC(sub_8229B9AC);
PPC_FUNC_IMPL(__imp__sub_8229B9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229B9B0"))) PPC_WEAK_FUNC(sub_8229B9B0);
PPC_FUNC_IMPL(__imp__sub_8229B9B0) {
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
	ctx.lr = 0x8229B9B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8229b928
	ctx.lr = 0x8229B9F8;
	sub_8229B928(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229ba48
	if (cr6.eq) goto loc_8229BA48;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// bl 0x82500a20
	ctx.lr = 0x8229BA20;
	sub_82500A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ba48
	if (cr6.eq) goto loc_8229BA48;
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r27,8252(r31)
	PPC_STORE_U32(r31.u32 + 8252, r27.u32);
	// clrlwi r9,r11,25
	ctx.r9.u64 = r11.u32 & 0x7F;
	// stw r30,8272(r31)
	PPC_STORE_U32(r31.u32 + 8272, r30.u32);
	// stw r10,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, ctx.r10.u32);
	// stb r9,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r9.u8);
loc_8229BA48:
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229BA60"))) PPC_WEAK_FUNC(sub_8229BA60);
PPC_FUNC_IMPL(__imp__sub_8229BA60) {
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
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stw r11,8260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8260, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8229b928
	ctx.lr = 0x8229BA94;
	sub_8229B928(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229BAA4"))) PPC_WEAK_FUNC(sub_8229BAA4);
PPC_FUNC_IMPL(__imp__sub_8229BAA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229BAA8"))) PPC_WEAK_FUNC(sub_8229BAA8);
PPC_FUNC_IMPL(__imp__sub_8229BAA8) {
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
	ctx.lr = 0x8229BAB0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,15992
	ctx.r10.s64 = r11.s64 + 15992;
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
	// bl 0x8229b870
	ctx.lr = 0x8229BAE4;
	sub_8229B870(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229bb1c
	if (cr6.eq) goto loc_8229BB1C;
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
	ctx.lr = 0x8229BB0C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8229bb20
	if (!cr6.eq) goto loc_8229BB20;
loc_8229BB1C:
	// li r11,0
	r11.s64 = 0;
loc_8229BB20:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229BB2C"))) PPC_WEAK_FUNC(sub_8229BB2C);
PPC_FUNC_IMPL(__imp__sub_8229BB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229BB30"))) PPC_WEAK_FUNC(sub_8229BB30);
PPC_FUNC_IMPL(__imp__sub_8229BB30) {
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
	ctx.lr = 0x8229BB38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8192
	ctx.r3.s64 = r31.s64 + 8192;
	// stw r30,8272(r31)
	PPC_STORE_U32(r31.u32 + 8272, r30.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r28,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r28.u32);
	// bl 0x825009a8
	ctx.lr = 0x8229BB60;
	sub_825009A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bbac
	if (cr6.eq) goto loc_8229BBAC;
	// lwz r11,8252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8252);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x8229baa8
	ctx.lr = 0x8229BB98;
	sub_8229BAA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229bbac
	if (cr6.eq) goto loc_8229BBAC;
	// li r11,3
	r11.s64 = 3;
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
loc_8229BBAC:
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229BBC4"))) PPC_WEAK_FUNC(sub_8229BBC4);
PPC_FUNC_IMPL(__imp__sub_8229BBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229BBC8"))) PPC_WEAK_FUNC(sub_8229BBC8);
PPC_FUNC_IMPL(__imp__sub_8229BBC8) {
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
	ctx.lr = 0x8229BBD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8229bc30
	if (!cr6.eq) goto loc_8229BC30;
	// addi r30,r31,8192
	r30.s64 = r31.s64 + 8192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500848
	ctx.lr = 0x8229BBF4;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bcc8
	if (cr6.eq) goto loc_8229BCC8;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r11.u32);
	// bl 0x82500830
	ctx.lr = 0x8229BC10;
	sub_82500830(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229bcc8
	if (cr6.eq) goto loc_8229BCC8;
	// lbz r11,8256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8256);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,8256(r31)
	PPC_STORE_U8(r31.u32 + 8256, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8229BC30:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8229bc50
	if (cr6.eq) goto loc_8229BC50;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8229bc50
	if (cr6.eq) goto loc_8229BC50;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x8229bc54
	if (!cr6.eq) goto loc_8229BC54;
loc_8229BC50:
	// li r11,1
	r11.s64 = 1;
loc_8229BC54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bcc8
	if (cr6.eq) goto loc_8229BCC8;
	// addi r30,r31,8192
	r30.s64 = r31.s64 + 8192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500848
	ctx.lr = 0x8229BC6C;
	sub_82500848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229bc8c
	if (cr6.eq) goto loc_8229BC8C;
	// stw r29,8260(r31)
	PPC_STORE_U32(r31.u32 + 8260, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500830
	ctx.lr = 0x8229BC84;
	sub_82500830(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8229BC8C:
	// lwz r11,8260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8260);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x8229bcc8
	if (!cr6.eq) goto loc_8229BCC8;
	// bl 0x821c9788
	ctx.lr = 0x8229BC9C;
	sub_821C9788(ctx, base);
	// lwz r11,8264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8264);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bgt cr6,0x8229bcc8
	if (cr6.gt) goto loc_8229BCC8;
	// lwz r11,8268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8268);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r29,8264(r31)
	PPC_STORE_U32(r31.u32 + 8264, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r4,8272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8272);
	// stw r11,8268(r31)
	PPC_STORE_U32(r31.u32 + 8268, r11.u32);
	// bl 0x8229bb30
	ctx.lr = 0x8229BCC8;
	sub_8229BB30(ctx, base);
loc_8229BCC8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229BCD0"))) PPC_WEAK_FUNC(sub_8229BCD0);
PPC_FUNC_IMPL(__imp__sub_8229BCD0) {
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
	// addi r3,r31,644
	ctx.r3.s64 = r31.s64 + 644;
	// bl 0x8266a810
	ctx.lr = 0x8229BCEC;
	sub_8266A810(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229bd10
	if (!cr6.eq) goto loc_8229BD10;
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x8266a810
	ctx.lr = 0x8229BD00;
	sub_8266A810(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229bd14
	if (cr6.eq) goto loc_8229BD14;
loc_8229BD10:
	// li r11,1
	r11.s64 = 1;
loc_8229BD14:
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

__attribute__((alias("__imp__sub_8229BD2C"))) PPC_WEAK_FUNC(sub_8229BD2C);
PPC_FUNC_IMPL(__imp__sub_8229BD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229BD30"))) PPC_WEAK_FUNC(sub_8229BD30);
PPC_FUNC_IMPL(__imp__sub_8229BD30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,717(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 717);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229bd4c
	if (!cr6.eq) goto loc_8229BD4C;
	// lbz r11,793(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 793);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8229bd50
	if (cr6.eq) goto loc_8229BD50;
loc_8229BD4C:
	// li r11,1
	r11.s64 = 1;
loc_8229BD50:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229BD58"))) PPC_WEAK_FUNC(sub_8229BD58);
PPC_FUNC_IMPL(__imp__sub_8229BD58) {
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
	// addi r3,r31,644
	ctx.r3.s64 = r31.s64 + 644;
	// bl 0x8266a848
	ctx.lr = 0x8229BD74;
	sub_8266A848(ctx, base);
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x8266a848
	ctx.lr = 0x8229BD7C;
	sub_8266A848(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229BD90"))) PPC_WEAK_FUNC(sub_8229BD90);
PPC_FUNC_IMPL(__imp__sub_8229BD90) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,292
	ctx.r9.s64 = r11.s64 + 292;
	// addi r8,r10,564
	ctx.r8.s64 = ctx.r10.s64 + 564;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// bl 0x8229d380
	ctx.lr = 0x8229BDC8;
	sub_8229D380(ctx, base);
	// addi r3,r31,644
	ctx.r3.s64 = r31.s64 + 644;
	// bl 0x8266a748
	ctx.lr = 0x8229BDD0;
	sub_8266A748(ctx, base);
	// addi r3,r31,720
	ctx.r3.s64 = r31.s64 + 720;
	// bl 0x8266a748
	ctx.lr = 0x8229BDD8;
	sub_8266A748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r11.u32);
	// stw r11,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r11.u32);
	// stb r11,796(r31)
	PPC_STORE_U8(r31.u32 + 796, r11.u8);
	// stb r11,797(r31)
	PPC_STORE_U8(r31.u32 + 797, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229BE04"))) PPC_WEAK_FUNC(sub_8229BE04);
PPC_FUNC_IMPL(__imp__sub_8229BE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229BE08"))) PPC_WEAK_FUNC(sub_8229BE08);
PPC_FUNC_IMPL(__imp__sub_8229BE08) {
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
	ctx.lr = 0x8229BE10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x82388580
	ctx.lr = 0x8229BE24;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8229BE38;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,208(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// bl 0x82388580
	ctx.lr = 0x8229BE48;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229BE58;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r30,0
	r30.s64 = 0;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// li r29,31
	r29.s64 = 31;
	// addi r25,r11,144
	r25.s64 = r11.s64 + 144;
loc_8229BE6C:
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229be9c
	if (cr6.eq) goto loc_8229BE9C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229BE84;
	sub_822577D0(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229BE90;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229be9c
	if (cr6.eq) goto loc_8229BE9C;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_8229BE9C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8229be6c
	if (!cr0.eq) goto loc_8229BE6C;
	// cmpw cr6,r27,r30
	cr6.compare<int32_t>(r27.s32, r30.s32, xer);
	// ble cr6,0x8229beb4
	if (!cr6.gt) goto loc_8229BEB4;
	// mr r27,r30
	r27.u64 = r30.u64;
loc_8229BEB4:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// subf r30,r27,r30
	r30.s64 = r30.s64 - r27.s64;
	// addi r31,r11,17088
	r31.s64 = r11.s64 + 17088;
	// lwz r11,17108(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17108);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229bf18
	if (!cr6.eq) goto loc_8229BF18;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r9,r9,464
	ctx.r9.s64 = ctx.r9.s64 + 464;
	// addi r8,r8,372
	ctx.r8.s64 = ctx.r8.s64 + 372;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,17108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 17108, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r10,-26264
	ctx.r3.s64 = ctx.r10.s64 + -26264;
	// bl 0x823d9a98
	ctx.lr = 0x8229BF18;
	sub_823D9A98(ctx, base);
loc_8229BF18:
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229BF24;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8229bf60
	if (!cr6.eq) goto loc_8229BF60;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3de0
	ctx.lr = 0x8229BF3C;
	sub_822A3DE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229bf88
	if (cr6.eq) goto loc_8229BF88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8229BF54;
	sub_822B62A0(ctx, base);
	// addi r7,r31,16
	ctx.r7.s64 = r31.s64 + 16;
	// extsb r5,r3
	ctx.r5.s64 = ctx.r3.s8;
	// b 0x8229bf78
	goto loc_8229BF78;
loc_8229BF60:
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bl 0x822577d0
	ctx.lr = 0x8229BF70;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
loc_8229BF78:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r26,16
	ctx.r4.s64 = r26.s64 + 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82481750
	ctx.lr = 0x8229BF88;
	sub_82481750(ctx, base);
loc_8229BF88:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8229BF90"))) PPC_WEAK_FUNC(sub_8229BF90);
PPC_FUNC_IMPL(__imp__sub_8229BF90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	ctx.lr = 0x8229BF98;
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229BFA8;
	sub_82388580(ctx, base);
	// lis r18,-32121
	r18.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8229BFB8;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,144
	ctx.r9.s64 = r11.s64 + 144;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8229BFD0;
	sub_8238EC00(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,-10240(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// li r31,0
	r31.s64 = 0;
	// addi r14,r10,-2628
	r14.s64 = ctx.r10.s64 + -2628;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// stw r14,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r14.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// bl 0x822701c8
	ctx.lr = 0x8229C000;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x8229C008;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82389668
	ctx.lr = 0x8229C018;
	sub_82389668(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8229c458
	if (cr6.eq) goto loc_8229C458;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,18692
	ctx.r4.s64 = ctx.r10.s64 + 18692;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8229C04C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C054;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C064;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r28,4096
	r28.s64 = 268435456;
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
	// lis r24,4096
	r24.s64 = 268435456;
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,4096
	r29.s64 = 268435456;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r7,18684
	ctx.r7.s64 = ctx.r7.s64 + 18684;
	// addi r6,r6,18676
	ctx.r6.s64 = ctx.r6.s64 + 18676;
	// addi r5,r5,18668
	ctx.r5.s64 = ctx.r5.s64 + 18668;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// ori r27,r28,39
	r27.u64 = r28.u64 | 39;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// ori r28,r24,40
	r28.u64 = r24.u64 | 40;
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// mr r15,r31
	r15.u64 = r31.u64;
	// li r21,4
	r21.s64 = 4;
	// ori r25,r3,44
	r25.u64 = ctx.r3.u64 | 44;
	// ori r26,r29,36
	r26.u64 = r29.u64 | 36;
	// li r24,1
	r24.s64 = 1;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// addi r17,r11,-28
	r17.s64 = r11.s64 + -28;
	// addi r23,r10,484
	r23.s64 = ctx.r10.s64 + 484;
	// addi r16,r9,68
	r16.s64 = ctx.r9.s64 + 68;
	// addi r22,r8,820
	r22.s64 = ctx.r8.s64 + 820;
loc_8229C0E4:
	// lwz r29,0(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229c444
	if (cr6.eq) goto loc_8229C444;
	// add r11,r30,r20
	r11.u64 = r30.u64 + r20.u64;
	// lbz r10,708(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 708);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8229c444
	if (!cr6.eq) goto loc_8229C444;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C10C;
	sub_822051A0(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8229C118;
	sub_822A3998(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8229be08
	ctx.lr = 0x8229C140;
	sub_8229BE08(ctx, base);
	// lbz r7,648(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 648);
	// lbz r6,1176(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1176);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// ori r5,r7,128
	ctx.r5.u64 = ctx.r7.u64 | 128;
	// std r31,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, r31.u64);
	// ori r11,r6,128
	r11.u64 = ctx.r6.u64 | 128;
	// stw r23,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r23.u32);
	// stw r21,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r21.u32);
	// stw r25,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r25.u32);
	// stw r26,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r26.u32);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r27.u32);
	// stw r28,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r28.u32);
	// stw r22,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r22.u32);
	// stw r23,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r23.u32);
	// stw r21,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, r21.u32);
	// stw r25,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, r25.u32);
	// stw r26,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, r26.u32);
	// stw r27,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, r27.u32);
	// stw r28,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r28.u32);
	// stw r22,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r22.u32);
	// stb r5,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r5.u8);
	// stb r11,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, r11.u8);
	// lwz r3,-10240(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + -10240);
	// std r31,668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 668, r31.u64);
	// bl 0x822701c8
	ctx.lr = 0x8229C1A4;
	sub_822701C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82295e90
	ctx.lr = 0x8229C1AC;
	sub_82295E90(ctx, base);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8229c204
	if (cr6.gt) goto loc_8229C204;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-15920
	r12.s64 = r12.s64 + -15920;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8229C1E4;
	case 1:
		goto loc_8229C1EC;
	case 2:
		goto loc_8229C1FC;
	case 3:
		goto loc_8229C204;
	case 4:
		goto loc_8229C1F4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-15900(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15900);
	// lwz r17,-15892(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15892);
	// lwz r17,-15876(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15876);
	// lwz r17,-15868(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15868);
	// lwz r17,-15884(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -15884);
loc_8229C1E4:
	// li r11,2
	r11.s64 = 2;
	// b 0x8229c200
	goto loc_8229C200;
loc_8229C1EC:
	// li r11,5
	r11.s64 = 5;
	// b 0x8229c200
	goto loc_8229C200;
loc_8229C1F4:
	// stw r21,20(r20)
	PPC_STORE_U32(r20.u32 + 20, r21.u32);
	// b 0x8229c204
	goto loc_8229C204;
loc_8229C1FC:
	// li r11,3
	r11.s64 = 3;
loc_8229C200:
	// stw r11,20(r20)
	PPC_STORE_U32(r20.u32 + 20, r11.u32);
loc_8229C204:
	// addi r11,r20,8
	r11.s64 = r20.s64 + 8;
	// addi r10,r20,16
	ctx.r10.s64 = r20.s64 + 16;
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r11,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, r11.u32);
	// ld r11,140(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// stw r10,1180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1180, ctx.r10.u32);
	// stw r9,12(r20)
	PPC_STORE_U32(r20.u32 + 12, ctx.r9.u32);
	// bne cr6,0x8229c290
	if (!cr6.eq) goto loc_8229C290;
	// std r24,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r24.u64);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x824e7008
	ctx.lr = 0x8229C23C;
	sub_824E7008(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229c26c
	if (cr6.eq) goto loc_8229C26C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C26C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229C26C:
	// ld r11,668(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ld r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// std r24,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r24.u64);
	// ori r8,r10,4
	ctx.r8.u64 = ctx.r10.u64 | 4;
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// ori r11,r8,8
	r11.u64 = ctx.r8.u64 | 8;
	// ori r10,r7,8
	ctx.r10.u64 = ctx.r7.u64 | 8;
	// b 0x8229c3a4
	goto loc_8229C3A4;
loc_8229C290:
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// std r31,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r31.u64);
	// bne cr6,0x8229c308
	if (!cr6.eq) goto loc_8229C308;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x824e7008
	ctx.lr = 0x8229C2AC;
	sub_824E7008(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229c2dc
	if (cr6.eq) goto loc_8229C2DC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229C2DC:
	// ld r11,668(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ld r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// stw r24,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r24.u32);
	// ori r8,r10,4
	ctx.r8.u64 = ctx.r10.u64 | 4;
	// std r31,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r31.u64);
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// stw r24,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r24.u32);
	// ori r11,r8,8
	r11.u64 = ctx.r8.u64 | 8;
	// ori r10,r7,8
	ctx.r10.u64 = ctx.r7.u64 | 8;
	// b 0x8229c3ac
	goto loc_8229C3AC;
loc_8229C308:
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bne cr6,0x8229c384
	if (!cr6.eq) goto loc_8229C384;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x824e7008
	ctx.lr = 0x8229C320;
	sub_824E7008(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229c350
	if (cr6.eq) goto loc_8229C350;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229C350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229C350:
	// ld r11,668(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ld r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 140);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
	// ori r8,r10,4
	ctx.r8.u64 = ctx.r10.u64 | 4;
	// stw r24,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r24.u32);
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// std r31,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r31.u64);
	// stw r31,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r31.u32);
	// ori r11,r8,8
	r11.u64 = ctx.r8.u64 | 8;
	// stw r24,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, r24.u32);
	// ori r10,r7,8
	ctx.r10.u64 = ctx.r7.u64 | 8;
	// b 0x8229c3b4
	goto loc_8229C3B4;
loc_8229C384:
	// ld r10,668(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 668);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// std r31,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r31.u64);
	// ori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 | 1;
	// ori r7,r9,4
	ctx.r7.u64 = ctx.r9.u64 | 4;
	// ori r6,r8,4
	ctx.r6.u64 = ctx.r8.u64 | 4;
	// ori r11,r7,8
	r11.u64 = ctx.r7.u64 | 8;
	// ori r10,r6,8
	ctx.r10.u64 = ctx.r6.u64 | 8;
loc_8229C3A4:
	// stw r31,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r31.u32);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
loc_8229C3AC:
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r31.u32);
	// stw r31,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, r31.u32);
loc_8229C3B4:
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r24,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r24.u32);
	// stw r24,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, r24.u32);
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// std r11,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, r11.u64);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r4,14
	ctx.r4.s64 = 14;
	// std r10,668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 668, ctx.r10.u64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r30,r29,16
	r30.s64 = r29.s64 + 16;
	// bl 0x822577d0
	ctx.lr = 0x8229C3E4;
	sub_822577D0(ctx, base);
	// lwz r14,88(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x824816e8
	ctx.lr = 0x8229C3FC;
	sub_824816E8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// addi r29,r1,656
	r29.s64 = ctx.r1.s64 + 656;
	// bl 0x822577d0
	ctx.lr = 0x8229C40C;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x824816e8
	ctx.lr = 0x8229C420;
	sub_824816E8(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r9,1
	r30.s64 = ctx.r9.s64 + 1;
	// lwz r14,96(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r17,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r17.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r16,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r16.u32);
	// stw r17,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r17.u32);
	// stw r16,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r16.u32);
loc_8229C444:
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// cmpwi cr6,r15,31
	cr6.compare<int32_t>(r15.s32, 31, xer);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// blt cr6,0x8229c0e4
	if (cr6.lt) goto loc_8229C0E4;
loc_8229C458:
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8229C460"))) PPC_WEAK_FUNC(sub_8229C460);
PPC_FUNC_IMPL(__imp__sub_8229C460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	ctx.lr = 0x8229C468;
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82388580
	ctx.lr = 0x8229C480;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8229C494;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,208(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// addi r17,r11,144
	r17.s64 = r11.s64 + 144;
	// bl 0x82388580
	ctx.lr = 0x8229C4A8;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C4B8;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r22,1
	r22.s64 = 1;
	// li r19,0
	r19.s64 = 0;
	// cmpwi cr6,r18,10
	cr6.compare<int32_t>(r18.s32, 10, xer);
	// beq cr6,0x8229c4e0
	if (cr6.eq) goto loc_8229C4E0;
	// cmpwi cr6,r18,9
	cr6.compare<int32_t>(r18.s32, 9, xer);
	// beq cr6,0x8229c4e0
	if (cr6.eq) goto loc_8229C4E0;
	// cmpwi cr6,r18,12
	cr6.compare<int32_t>(r18.s32, 12, xer);
	// mr r11,r19
	r11.u64 = r19.u64;
	// bne cr6,0x8229c4e4
	if (!cr6.eq) goto loc_8229C4E4;
loc_8229C4E0:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8229C4E4:
	// clrlwi r15,r11,24
	r15.u64 = r11.u32 & 0xFF;
	// mr r16,r19
	r16.u64 = r19.u64;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8229c50c
	if (cr6.eq) goto loc_8229C50C;
	// lwz r11,3172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3172);
	// mr r16,r22
	r16.u64 = r22.u64;
	// lwz r9,3176(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3176);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x8229c50c
	if (cr6.gt) goto loc_8229C50C;
	// li r16,2
	r16.s64 = 2;
loc_8229C50C:
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lbz r7,600(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 600);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r9,r9,212
	ctx.r9.s64 = ctx.r9.s64 + 212;
	// addi r8,r8,784
	ctx.r8.s64 = ctx.r8.s64 + 784;
	// lis r6,8192
	ctx.r6.s64 = 536870912;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ori r7,r7,128
	ctx.r7.u64 = ctx.r7.u64 | 128;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lis r5,4096
	ctx.r5.s64 = 268435456;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// stb r7,600(r1)
	PPC_STORE_U8(ctx.r1.u32 + 600, ctx.r7.u8);
	// li r9,5
	ctx.r9.s64 = 5;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// lis r30,4096
	r30.s64 = 268435456;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ori r8,r6,44
	ctx.r8.u64 = ctx.r6.u64 | 44;
	// ori r7,r5,36
	ctx.r7.u64 = ctx.r5.u64 | 36;
	// ori r6,r4,42
	ctx.r6.u64 = ctx.r4.u64 | 42;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// addi r11,r18,-8
	r11.s64 = r18.s64 + -8;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// ori r5,r3,41
	ctx.r5.u64 = ctx.r3.u64 | 41;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// ori r4,r30,43
	ctx.r4.u64 = r30.u64 | 43;
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// stw r5,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// std r9,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, ctx.r9.u64);
	// bgt cr6,0x8229c5e8
	if (cr6.gt) goto loc_8229C5E8;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-14944
	r12.s64 = r12.s64 + -14944;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8229C5B8;
	case 1:
		goto loc_8229C5C8;
	case 2:
		goto loc_8229C5C0;
	case 3:
		goto loc_8229C5D8;
	case 4:
		goto loc_8229C5D0;
	case 5:
		goto loc_8229C5E0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-14920(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14920);
	// lwz r17,-14904(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14904);
	// lwz r17,-14912(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14912);
	// lwz r17,-14888(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14888);
	// lwz r17,-14896(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14896);
	// lwz r17,-14880(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -14880);
loc_8229C5B8:
	// li r11,7
	r11.s64 = 7;
	// b 0x8229c5e4
	goto loc_8229C5E4;
loc_8229C5C0:
	// li r11,8
	r11.s64 = 8;
	// b 0x8229c5e4
	goto loc_8229C5E4;
loc_8229C5C8:
	// li r11,9
	r11.s64 = 9;
	// b 0x8229c5e4
	goto loc_8229C5E4;
loc_8229C5D0:
	// li r11,10
	r11.s64 = 10;
	// b 0x8229c5e4
	goto loc_8229C5E4;
loc_8229C5D8:
	// li r11,11
	r11.s64 = 11;
	// b 0x8229c5e4
	goto loc_8229C5E4;
loc_8229C5E0:
	// li r11,12
	r11.s64 = 12;
loc_8229C5E4:
	// stw r11,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r11.u32);
loc_8229C5E8:
	// addi r25,r31,196
	r25.s64 = r31.s64 + 196;
	// stw r23,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, r23.u32);
	// addi r24,r10,12
	r24.s64 = ctx.r10.s64 + 12;
	// mr r26,r25
	r26.u64 = r25.u64;
	// mr r21,r24
	r21.u64 = r24.u64;
	// li r20,31
	r20.s64 = 31;
loc_8229C600:
	// lwz r27,0(r21)
	r27.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8229c734
	if (cr6.eq) goto loc_8229C734;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8229c65c
	if (cr6.eq) goto loc_8229C65C;
	// lwz r11,-20(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -20);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// cmpw cr6,r11,r16
	cr6.compare<int32_t>(r11.s32, r16.s32, xer);
	// ori r11,r9,1
	r11.u64 = ctx.r9.u64 | 1;
	// bne cr6,0x8229c644
	if (!cr6.eq) goto loc_8229C644;
	// std r22,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r22.u64);
	// li r5,1
	ctx.r5.s64 = 1;
	// std r11,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, r11.u64);
	// bl 0x8229be08
	ctx.lr = 0x8229C63C;
	sub_8229BE08(ctx, base);
	// ld r11,92(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
	// b 0x8229c6dc
	goto loc_8229C6DC;
loc_8229C644:
	// std r19,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r19.u64);
	// li r5,2
	ctx.r5.s64 = 2;
	// std r11,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, r11.u64);
	// bl 0x8229be08
	ctx.lr = 0x8229C654;
	sub_8229BE08(ctx, base);
	// ld r11,92(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
	// b 0x8229c6dc
	goto loc_8229C6DC;
loc_8229C65C:
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r31,r24
	r31.u64 = r24.u64;
	// li r29,31
	r29.s64 = 31;
loc_8229C66C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229c6b4
	if (cr6.eq) goto loc_8229C6B4;
	// cmpwi cr6,r18,13
	cr6.compare<int32_t>(r18.s32, 13, xer);
	// bne cr6,0x8229c6a0
	if (!cr6.eq) goto loc_8229C6A0;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x822051a0
	ctx.lr = 0x8229C688;
	sub_822051A0(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C698;
	sub_822051A0(ctx, base);
	// cmpw cr6,r14,r3
	cr6.compare<int32_t>(r14.s32, ctx.r3.s32, xer);
	// b 0x8229c6ac
	goto loc_8229C6AC;
loc_8229C6A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
loc_8229C6AC:
	// ble cr6,0x8229c6b4
	if (!cr6.gt) goto loc_8229C6B4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8229C6B4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// bne 0x8229c66c
	if (!cr0.eq) goto loc_8229C66C;
	// ld r11,92(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
	// cmplwi cr6,r28,1
	cr6.compare<uint32_t>(r28.u32, 1, xer);
	// std r22,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r22.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// beq cr6,0x8229c6dc
	if (cr6.eq) goto loc_8229C6DC;
	// std r19,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r19.u64);
loc_8229C6DC:
	// lwz r10,-8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -8);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// lwz r9,-16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + -16);
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r7,-4(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + -4);
	// ori r8,r11,8
	ctx.r8.u64 = r11.u64 | 8;
	// stw r22,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r22.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ori r6,r8,16
	ctx.r6.u64 = ctx.r8.u64 | 16;
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// ori r5,r6,4
	ctx.r5.u64 = ctx.r6.u64 | 4;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// std r5,92(r1)
	PPC_STORE_U64(ctx.r1.u32 + 92, ctx.r5.u64);
	// bl 0x822577d0
	ctx.lr = 0x8229C71C;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r27,16
	ctx.r4.s64 = r27.s64 + 16;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x824816e8
	ctx.lr = 0x8229C730;
	sub_824816E8(ctx, base);
	// ld r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 92);
loc_8229C734:
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r26,r26,192
	r26.s64 = r26.s64 + 192;
	// bne 0x8229c600
	if (!cr0.eq) goto loc_8229C600;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8229C74C"))) PPC_WEAK_FUNC(sub_8229C74C);
PPC_FUNC_IMPL(__imp__sub_8229C74C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229C750"))) PPC_WEAK_FUNC(sub_8229C750);
PPC_FUNC_IMPL(__imp__sub_8229C750) {
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
	ctx.lr = 0x8229C758;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// bl 0x82256058
	ctx.lr = 0x8229C768;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229c9cc
	if (cr6.eq) goto loc_8229C9CC;
	// bl 0x82256058
	ctx.lr = 0x8229C774;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8229c9cc
	if (cr0.eq) goto loc_8229C9CC;
	// bl 0x82256058
	ctx.lr = 0x8229C780;
	sub_82256058(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8229c9cc
	if (cr6.eq) goto loc_8229C9CC;
	// addi r29,r25,8
	r29.s64 = r25.s64 + 8;
	// li r30,0
	r30.s64 = 0;
	// li r28,8
	r28.s64 = 8;
	// li r26,12
	r26.s64 = 12;
	// li r27,-1
	r27.s64 = -1;
	// lis r24,-32121
	r24.s64 = -2105081856;
loc_8229C7A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C7AC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C7BC;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r31,r10,r26
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229c884
	if (cr6.eq) goto loc_8229C884;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229c85c
	if (cr6.eq) goto loc_8229C85C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8229C7E0;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x8229c834
	if (cr6.eq) goto loc_8229C834;
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8229c804
	if (cr6.eq) goto loc_8229C804;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x822577d0
	ctx.lr = 0x8229C7FC;
	sub_822577D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8229c85c
	goto loc_8229C85C;
loc_8229C804:
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r30,3080(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// bl 0x822051a0
	ctx.lr = 0x8229C810;
	sub_822051A0(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8229C81C;
	sub_823EAEF8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82263c28
	ctx.lr = 0x8229C82C;
	sub_82263C28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8229c85c
	goto loc_8229C85C;
loc_8229C834:
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// bl 0x822051a0
	ctx.lr = 0x8229C848;
	sub_822051A0(ctx, base);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// stw r27,196(r10)
	PPC_STORE_U32(ctx.r10.u32 + 196, r27.u32);
loc_8229C85C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8229c884
	if (cr6.eq) goto loc_8229C884;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C870;
	sub_822051A0(ctx, base);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// stw r30,172(r10)
	PPC_STORE_U32(ctx.r10.u32 + 172, r30.u32);
loc_8229C884:
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpwi cr6,r26,136
	cr6.compare<int32_t>(r26.s32, 136, xer);
	// blt cr6,0x8229c7a4
	if (cr6.lt) goto loc_8229C7A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C898;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C8A8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8229C8B0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x8229C8B4;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229c940
	if (cr6.eq) goto loc_8229C940;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,444
	ctx.r3.s64 = r11.s64 + 444;
	// bl 0x821fa230
	ctx.lr = 0x8229C8CC;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229C8E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8229C8F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8229C910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r23,8
	cr6.compare<int32_t>(r23.s32, 8, xer);
	// blt cr6,0x8229c934
	if (cr6.lt) goto loc_8229C934;
	// cmpwi cr6,r23,13
	cr6.compare<int32_t>(r23.s32, 13, xer);
	// bgt cr6,0x8229c934
	if (cr6.gt) goto loc_8229C934;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8229c460
	ctx.lr = 0x8229C930;
	sub_8229C460(ctx, base);
	// b 0x8229c9a8
	goto loc_8229C9A8;
loc_8229C934:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8229bf90
	ctx.lr = 0x8229C93C;
	sub_8229BF90(ctx, base);
	// b 0x8229c9a8
	goto loc_8229C9A8;
loc_8229C940:
	// li r30,12
	r30.s64 = 12;
loc_8229C944:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C94C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C95C;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r31,r10,r30
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229c99c
	if (cr6.eq) goto loc_8229C99C;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8229C978;
	sub_822051A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// lwz r5,172(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// bl 0x8229be08
	ctx.lr = 0x8229C99C;
	sub_8229BE08(ctx, base);
loc_8229C99C:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,136
	cr6.compare<int32_t>(r30.s32, 136, xer);
	// blt cr6,0x8229c944
	if (cr6.lt) goto loc_8229C944;
loc_8229C9A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229C9B0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229C9C0;
	sub_82270170(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8229C9CC;
	sub_82274128(ctx, base);
loc_8229C9CC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8229C9D4"))) PPC_WEAK_FUNC(sub_8229C9D4);
PPC_FUNC_IMPL(__imp__sub_8229C9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229C9D8"))) PPC_WEAK_FUNC(sub_8229C9D8);
PPC_FUNC_IMPL(__imp__sub_8229C9D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,19004
	ctx.r3.s64 = r11.s64 + 19004;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229C9E4"))) PPC_WEAK_FUNC(sub_8229C9E4);
PPC_FUNC_IMPL(__imp__sub_8229C9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229C9E8"))) PPC_WEAK_FUNC(sub_8229C9E8);
PPC_FUNC_IMPL(__imp__sub_8229C9E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8229ca18
	if (cr6.eq) goto loc_8229CA18;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8229ca10
	if (cr6.eq) goto loc_8229CA10;
	// cmplwi cr6,r4,65534
	cr6.compare<uint32_t>(ctx.r4.u32, 65534, xer);
	// beq cr6,0x8229ca08
	if (cr6.eq) goto loc_8229CA08;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8229CA08:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8229CA10:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8229CA18:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CA20"))) PPC_WEAK_FUNC(sub_8229CA20);
PPC_FUNC_IMPL(__imp__sub_8229CA20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8229ca50
	if (cr6.lt) goto loc_8229CA50;
	// beq cr6,0x8229ca48
	if (cr6.eq) goto loc_8229CA48;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8229ca3c
	if (cr6.lt) goto loc_8229CA3C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8229CA3C:
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65534
	ctx.r3.u64 = ctx.r3.u64 | 65534;
	// blr 
	return;
loc_8229CA48:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8229CA50:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CA58"))) PPC_WEAK_FUNC(sub_8229CA58);
PPC_FUNC_IMPL(__imp__sub_8229CA58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8229ca7c
	if (cr6.lt) goto loc_8229CA7C;
	// beq cr6,0x8229ca74
	if (cr6.eq) goto loc_8229CA74;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8229ca74
	if (cr6.lt) goto loc_8229CA74;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8229CA74:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8229CA7C:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CA84"))) PPC_WEAK_FUNC(sub_8229CA84);
PPC_FUNC_IMPL(__imp__sub_8229CA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229CA88"))) PPC_WEAK_FUNC(sub_8229CA88);
PPC_FUNC_IMPL(__imp__sub_8229CA88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8229caac
	if (cr6.lt) goto loc_8229CAAC;
	// beq cr6,0x8229caa4
	if (cr6.eq) goto loc_8229CAA4;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8229caa4
	if (cr6.lt) goto loc_8229CAA4;
	// li r11,-1
	r11.s64 = -1;
	// b 0x8229cab0
	goto loc_8229CAB0;
loc_8229CAA4:
	// li r11,2
	r11.s64 = 2;
	// b 0x8229cab0
	goto loc_8229CAB0;
loc_8229CAAC:
	// li r11,1
	r11.s64 = 1;
loc_8229CAB0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8229cb08
	if (cr6.gt) goto loc_8229CB08;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-13612
	r12.s64 = r12.s64 + -13612;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8229CAE8;
	case 1:
		goto loc_8229CAF0;
	case 2:
		goto loc_8229CB00;
	case 3:
		goto loc_8229CB08;
	case 4:
		goto loc_8229CAF8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-13592(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13592);
	// lwz r17,-13584(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13584);
	// lwz r17,-13568(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13568);
	// lwz r17,-13560(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13560);
	// lwz r17,-13576(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13576);
loc_8229CAE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8229CAF0:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8229CAF8:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8229CB00:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8229CB08:
	// li r3,-1
	ctx.r3.s64 = -1;
}

__attribute__((alias("__imp__sub_8229CB10"))) PPC_WEAK_FUNC(sub_8229CB10);
PPC_FUNC_IMPL(__imp__sub_8229CB10) {
	PPC_FUNC_PROLOGUE();
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65534
	ctx.r3.u64 = ctx.r3.u64 | 65534;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CB1C"))) PPC_WEAK_FUNC(sub_8229CB1C);
PPC_FUNC_IMPL(__imp__sub_8229CB1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229CB20"))) PPC_WEAK_FUNC(sub_8229CB20);
PPC_FUNC_IMPL(__imp__sub_8229CB20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister f0{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// bgt cr6,0x8229cbb0
	if (cr6.gt) {
		sub_8229CBB0(ctx, base);
		return;
	}
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-13496
	r12.s64 = r12.s64 + -13496;
	// rlwinm r0,r6,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r6.u64) {
	case 0:
		goto loc_8229CB58;
	case 1:
		goto loc_8229CB74;
	case 2:
		goto loc_8229CBA4;
	case 3:
		goto loc_8229CB90;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-13480(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13480);
	// lwz r17,-13452(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13452);
	// lwz r17,-13404(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13404);
	// lwz r17,-13424(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13424);
loc_8229CB58:
	// lfd f0,0(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lfd f13,0(r4)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8229cb6c
	if (cr6.lt) goto loc_8229CB6C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8229CB6C:
	// stfd f0,0(r5)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r5.u32 + 0, f0.u64);
	// blr 
	return;
loc_8229CB74:
	// lfd f0,0(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lfd f13,0(r4)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8229cb6c
	if (cr6.gt) goto loc_8229CB6C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfd f0,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, f0.u64);
	// blr 
	return;
loc_8229CB90:
	// lfd f0,0(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lfd f13,0(r4)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// fadd f12,f0,f13
	ctx.f12.f64 = f0.f64 + ctx.f13.f64;
	// stfd f12,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.f12.u64);
	// blr 
	return;
loc_8229CBA4:
	// lfd f0,0(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 0);
}

__attribute__((alias("__imp__sub_8229CBB0"))) PPC_WEAK_FUNC(sub_8229CBB0);
PPC_FUNC_IMPL(__imp__sub_8229CBB0) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CBB8"))) PPC_WEAK_FUNC(sub_8229CBB8);
PPC_FUNC_IMPL(__imp__sub_8229CBB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,4096
	r11.s64 = 268435456;
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// ori r10,r11,27
	ctx.r10.u64 = r11.u64 | 27;
	// ori r9,r9,30
	ctx.r9.u64 = ctx.r9.u64 | 30;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8229cbf8
	if (cr6.lt) goto loc_8229CBF8;
	// beq cr6,0x8229cbf0
	if (cr6.eq) goto loc_8229CBF0;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8229cbe4
	if (cr6.lt) goto loc_8229CBE4;
	// li r11,-1
	r11.s64 = -1;
	// b 0x8229cbfc
	goto loc_8229CBFC;
loc_8229CBE4:
	// lis r11,8192
	r11.s64 = 536870912;
	// ori r11,r11,31
	r11.u64 = r11.u64 | 31;
	// b 0x8229cbfc
	goto loc_8229CBFC;
loc_8229CBF0:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// b 0x8229cbfc
	goto loc_8229CBFC;
loc_8229CBF8:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8229CBFC:
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8229cc2c
	if (cr6.eq) goto loc_8229CC2C;
	// subf. r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8229cc24
	if (cr0.eq) goto loc_8229CC24;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8229cc1c
	if (cr6.eq) goto loc_8229CC1C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8229CC1C:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8229CC24:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8229CC2C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CC34"))) PPC_WEAK_FUNC(sub_8229CC34);
PPC_FUNC_IMPL(__imp__sub_8229CC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229CC38"))) PPC_WEAK_FUNC(sub_8229CC38);
PPC_FUNC_IMPL(__imp__sub_8229CC38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8229cc70
	if (cr6.eq) goto loc_8229CC70;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8229cc64
	if (cr6.eq) goto loc_8229CC64;
	// cmplwi cr6,r4,65534
	cr6.compare<uint32_t>(ctx.r4.u32, 65534, xer);
	// beq cr6,0x8229cc58
	if (cr6.eq) goto loc_8229CC58;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8229CC58:
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// ori r3,r3,31
	ctx.r3.u64 = ctx.r3.u64 | 31;
	// blr 
	return;
loc_8229CC64:
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// ori r3,r3,30
	ctx.r3.u64 = ctx.r3.u64 | 30;
	// blr 
	return;
loc_8229CC70:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,27
	ctx.r3.u64 = ctx.r3.u64 | 27;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229CC7C"))) PPC_WEAK_FUNC(sub_8229CC7C);
PPC_FUNC_IMPL(__imp__sub_8229CC7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229CC80"))) PPC_WEAK_FUNC(sub_8229CC80);
PPC_FUNC_IMPL(__imp__sub_8229CC80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8229CC88;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// li r18,1
	r18.s64 = 1;
	// std r22,0(r23)
	PPC_STORE_U64(r23.u32 + 0, r22.u64);
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// stb r22,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r22.u8);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r18
	r31.u64 = r18.u64;
	// add r20,r4,r9
	r20.u64 = ctx.r4.u64 + ctx.r9.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229CCCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
loc_8229CCD4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229cdbc
	if (cr6.eq) goto loc_8229CDBC;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229CCF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e8f28
	ctx.lr = 0x8229CD08;
	sub_824E8F28(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229cdb0
	if (!cr6.eq) goto loc_8229CDB0;
	// cmplwi cr6,r27,1
	cr6.compare<uint32_t>(r27.u32, 1, xer);
	// blt cr6,0x8229cd38
	if (cr6.lt) goto loc_8229CD38;
	// beq cr6,0x8229cd30
	if (cr6.eq) goto loc_8229CD30;
	// cmplwi cr6,r27,3
	cr6.compare<uint32_t>(r27.u32, 3, xer);
	// blt cr6,0x8229cd30
	if (cr6.lt) goto loc_8229CD30;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// b 0x8229cd3c
	goto loc_8229CD3C;
loc_8229CD30:
	// li r6,8
	ctx.r6.s64 = 8;
	// b 0x8229cd3c
	goto loc_8229CD3C;
loc_8229CD38:
	// li r6,4
	ctx.r6.s64 = 4;
loc_8229CD3C:
	// cmplw cr6,r19,r27
	cr6.compare<uint32_t>(r19.u32, r27.u32, xer);
	// bne cr6,0x8229cd64
	if (!cr6.eq) goto loc_8229CD64;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8229CD58;
	sub_824E9690(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r31,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r31.u8);
	// b 0x8229cdb0
	goto loc_8229CDB0;
loc_8229CD64:
	// add r29,r6,r28
	r29.u64 = ctx.r6.u64 + r28.u64;
	// cmplw cr6,r29,r20
	cr6.compare<uint32_t>(r29.u32, r20.u32, xer);
	// bgt cr6,0x8229cd90
	if (cr6.gt) goto loc_8229CD90;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8229CD80;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bne cr6,0x8229cd94
	if (!cr6.eq) goto loc_8229CD94;
loc_8229CD90:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8229CD94:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229cdac
	if (cr6.eq) goto loc_8229CDAC;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// sld r10,r18,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (r18.u64 << (r11.u8 & 0x7F));
	// std r10,0(r23)
	PPC_STORE_U64(r23.u32 + 0, ctx.r10.u64);
loc_8229CDAC:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8229CDB0:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,3
	cr6.compare<int32_t>(r27.s32, 3, xer);
	// blt cr6,0x8229ccd4
	if (cr6.lt) goto loc_8229CCD4;
loc_8229CDBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8229CDC8"))) PPC_WEAK_FUNC(sub_8229CDC8);
PPC_FUNC_IMPL(__imp__sub_8229CDC8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,8
	cr6.compare<uint32_t>(ctx.r5.u32, 8, xer);
	// blt cr6,0x8229ce24
	if (cr6.lt) goto loc_8229CE24;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229ce24
	if (cr6.eq) goto loc_8229CE24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229CDFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,19116
	ctx.r8.s64 = ctx.r9.s64 + 19116;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8229CE24:
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

__attribute__((alias("__imp__sub_8229CE3C"))) PPC_WEAK_FUNC(sub_8229CE3C);
PPC_FUNC_IMPL(__imp__sub_8229CE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229CE40"))) PPC_WEAK_FUNC(sub_8229CE40);
PPC_FUNC_IMPL(__imp__sub_8229CE40) {
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
	ctx.lr = 0x8229CE48;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-11808(r1)
	ea = -11808 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r28,52
	ctx.r4.s64 = r28.s64 + 52;
	// bl 0x821c8fe0
	ctx.lr = 0x8229CE64;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82489428
	ctx.lr = 0x8229CE6C;
	sub_82489428(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r29,4304(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,72(r8)
	PPC_STORE_U32(ctx.r8.u32 + 72, r30.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r10,528(r7)
	PPC_STORE_U32(ctx.r7.u32 + 528, ctx.r10.u32);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x82289f20
	ctx.lr = 0x8229CEAC;
	sub_82289F20(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x82295050
	ctx.lr = 0x8229CEBC;
	sub_82295050(ctx, base);
	// std r30,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, r30.u64);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229CEC8;
	sub_82388580(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229CED8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8229CEE0;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x8229CEE4;
	sub_824F92F0(ctx, base);
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// li r4,23
	ctx.r4.s64 = 23;
	// bl 0x824e9530
	ctx.lr = 0x8229CF00;
	sub_824E9530(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229CF08;
	sub_82388580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229CF18;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8229CF20;
	sub_824E70E0(ctx, base);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r3,r3,19188
	ctx.r3.s64 = ctx.r3.s64 + 19188;
	// bl 0x821fa230
	ctx.lr = 0x8229CF2C;
	sub_821FA230(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229CF40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8229CF58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8229CF70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,-10240(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r5,4296(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4296);
	// lwz r27,68(r5)
	r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ea838
	ctx.lr = 0x8229CF84;
	sub_824EA838(ctx, base);
	// bl 0x824f88f8
	ctx.lr = 0x8229CF88;
	sub_824F88F8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r4,r29,23592
	ctx.r4.s64 = r29.s64 + 23592;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// li r6,11
	ctx.r6.s64 = 11;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x824852f8
	ctx.lr = 0x8229CFA8;
	sub_824852F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,-10240(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82388580
	ctx.lr = 0x8229CFB4;
	sub_82388580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229CFC4;
	sub_82270170(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r9,r29,16
	ctx.r9.s64 = r29.s64 + 16;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824860e8
	ctx.lr = 0x8229CFF8;
	sub_824860E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229d0ec
	if (cr6.eq) goto loc_8229D0EC;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8229d034
	if (!cr6.eq) goto loc_8229D034;
loc_8229D010:
	// bl 0x821c9788
	ctx.lr = 0x8229D014;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82486c48
	ctx.lr = 0x8229D020;
	sub_82486C48(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x8229D028;
	sub_821C91B8(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8229d010
	if (cr6.eq) goto loc_8229D010;
loc_8229D034:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8229d0ec
	if (!cr6.eq) goto loc_8229D0EC;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82486548
	ctx.lr = 0x8229D048;
	sub_82486548(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229d0ec
	if (cr6.eq) goto loc_8229D0EC;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8229d084
	if (!cr6.eq) goto loc_8229D084;
loc_8229D060:
	// bl 0x821c9788
	ctx.lr = 0x8229D064;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82486c48
	ctx.lr = 0x8229D070;
	sub_82486C48(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x8229D078;
	sub_821C91B8(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8229d060
	if (cr6.eq) goto loc_8229D060;
loc_8229D084:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8229D08C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8229D09C;
	sub_82270170(ctx, base);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r6,r28,92
	ctx.r6.s64 = r28.s64 + 92;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824816e8
	ctx.lr = 0x8229D0B0;
	sub_824816E8(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824866e8
	ctx.lr = 0x8229D0BC;
	sub_824866E8(ctx, base);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x8229d0ec
	if (!cr6.eq) goto loc_8229D0EC;
loc_8229D0C8:
	// bl 0x821c9788
	ctx.lr = 0x8229D0CC;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82486c48
	ctx.lr = 0x8229D0D8;
	sub_82486C48(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x8229D0E0;
	sub_821C91B8(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8229d0c8
	if (cr6.eq) goto loc_8229D0C8;
loc_8229D0EC:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82489608
	ctx.lr = 0x8229D0F4;
	sub_82489608(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c9030
	ctx.lr = 0x8229D0FC;
	sub_821C9030(ctx, base);
	// addi r1,r1,11808
	ctx.r1.s64 = ctx.r1.s64 + 11808;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229D104"))) PPC_WEAK_FUNC(sub_8229D104);
PPC_FUNC_IMPL(__imp__sub_8229D104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D108"))) PPC_WEAK_FUNC(sub_8229D108);
PPC_FUNC_IMPL(__imp__sub_8229D108) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229D134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x8229d158
	if (!cr6.eq) goto loc_8229D158;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229d158
	if (cr6.eq) goto loc_8229D158;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,19036
	ctx.r10.s64 = r11.s64 + 19036;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x8229d15c
	goto loc_8229D15C;
loc_8229D158:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229D15C:
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

__attribute__((alias("__imp__sub_8229D174"))) PPC_WEAK_FUNC(sub_8229D174);
PPC_FUNC_IMPL(__imp__sub_8229D174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D178"))) PPC_WEAK_FUNC(sub_8229D178);
PPC_FUNC_IMPL(__imp__sub_8229D178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8229D180;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8229d1c0
	if (cr6.lt) goto loc_8229D1C0;
	// beq cr6,0x8229d1b8
	if (cr6.eq) goto loc_8229D1B8;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8229d1b0
	if (cr6.lt) goto loc_8229D1B0;
	// li r31,-1
	r31.s64 = -1;
	// b 0x8229d1c4
	goto loc_8229D1C4;
loc_8229D1B0:
	// li r31,1
	r31.s64 = 1;
	// b 0x8229d1c4
	goto loc_8229D1C4;
loc_8229D1B8:
	// li r31,0
	r31.s64 = 0;
	// b 0x8229d1c4
	goto loc_8229D1C4;
loc_8229D1C0:
	// li r31,2
	r31.s64 = 2;
loc_8229D1C4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229D1D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8229d27c
	if (cr6.gt) goto loc_8229D27C;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,-11788
	r12.s64 = r12.s64 + -11788;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8229D204;
	case 1:
		goto loc_8229D224;
	case 2:
		goto loc_8229D244;
	case 3:
		goto loc_8229D264;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-11772(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11772);
	// lwz r17,-11740(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11740);
	// lwz r17,-11708(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11708);
	// lwz r17,-11676(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11676);
loc_8229D204:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8229D218;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229D224:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8229D238;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229D244:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8229D258;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229D264:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8229D278;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8229D27C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229D288"))) PPC_WEAK_FUNC(sub_8229D288);
PPC_FUNC_IMPL(__imp__sub_8229D288) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,68
	ctx.r8.s64 = ctx.r10.s64 + 68;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8229d2c8
	if (cr6.eq) goto loc_8229D2C8;
	// bl 0x82130588
	ctx.lr = 0x8229D2C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229D2C8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229D2DC"))) PPC_WEAK_FUNC(sub_8229D2DC);
PPC_FUNC_IMPL(__imp__sub_8229D2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D2E0"))) PPC_WEAK_FUNC(sub_8229D2E0);
PPC_FUNC_IMPL(__imp__sub_8229D2E0) {
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
	ctx.lr = 0x8229D2E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,52
	ctx.r4.s64 = r31.s64 + 52;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8229D308;
	sub_821C8FE0(ctx, base);
	// ld r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// extsw r10,r28
	ctx.r10.s64 = r28.s32;
	// neg r9,r28
	ctx.r9.s64 = -r28.s64;
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// std r6,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r6.u64);
	// std r10,124(r31)
	PPC_STORE_U64(r31.u32 + 124, ctx.r10.u64);
	// addi r11,r31,100
	r11.s64 = r31.s64 + 100;
	// ori r4,r5,2
	ctx.r4.u64 = ctx.r5.u64 | 2;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// std r4,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r4.u64);
	// cmplwi cr6,r30,351
	cr6.compare<uint32_t>(r30.u32, 351, xer);
	// std r8,136(r31)
	PPC_STORE_U64(r31.u32 + 136, ctx.r8.u64);
	// ori r10,r3,4
	ctx.r10.u64 = ctx.r3.u64 | 4;
	// std r10,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r10.u64);
	// blt cr6,0x8229d358
	if (cr6.lt) goto loc_8229D358;
	// addi r11,r30,31
	r11.s64 = r30.s64 + 31;
loc_8229D358:
	// addi r10,r31,84
	ctx.r10.s64 = r31.s64 + 84;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,616(r31)
	PPC_STORE_U32(r31.u32 + 616, ctx.r10.u32);
	// bl 0x824e6a10
	ctx.lr = 0x8229D36C;
	sub_824E6A10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8229D374;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229D37C"))) PPC_WEAK_FUNC(sub_8229D37C);
PPC_FUNC_IMPL(__imp__sub_8229D37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D380"))) PPC_WEAK_FUNC(sub_8229D380);
PPC_FUNC_IMPL(__imp__sub_8229D380) {
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
	// bl 0x824e6928
	ctx.lr = 0x8229D398;
	sub_824E6928(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// addi r10,r11,19252
	ctx.r10.s64 = r11.s64 + 19252;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x8229D3AC;
	sub_821C8ED8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r6,r9,19116
	ctx.r6.s64 = ctx.r9.s64 + 19116;
	// addi r5,r8,19212
	ctx.r5.s64 = ctx.r8.s64 + 19212;
	// lis r11,8192
	r11.s64 = 536870912;
	// stw r6,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r6.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// ori r5,r11,30
	ctx.r5.u64 = r11.u64 | 30;
	// addi r4,r7,19036
	ctx.r4.s64 = ctx.r7.s64 + 19036;
	// addi r11,r31,92
	r11.s64 = r31.s64 + 92;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// stw r5,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r5.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// ori r4,r10,31
	ctx.r4.u64 = ctx.r10.u64 | 31;
	// ori r6,r3,27
	ctx.r6.u64 = ctx.r3.u64 | 27;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r4,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r4.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r6,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r6.u32);
	// addi r3,r9,19232
	ctx.r3.s64 = ctx.r9.s64 + 19232;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// std r7,104(r31)
	PPC_STORE_U64(r31.u32 + 104, ctx.r7.u64);
	// lbz r11,612(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 612);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,612(r31)
	PPC_STORE_U8(r31.u32 + 612, ctx.r10.u8);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8229D43C"))) PPC_WEAK_FUNC(sub_8229D43C);
PPC_FUNC_IMPL(__imp__sub_8229D43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D440"))) PPC_WEAK_FUNC(sub_8229D440);
PPC_FUNC_IMPL(__imp__sub_8229D440) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,68
	ctx.r8.s64 = ctx.r10.s64 + 68;
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// stw r8,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x8229D480;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6b58
	ctx.lr = 0x8229D488;
	sub_824E6B58(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8229d4a0
	if (cr6.eq) goto loc_8229D4A0;
	// bl 0x82130588
	ctx.lr = 0x8229D49C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229D4A0:
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

__attribute__((alias("__imp__sub_8229D4B8"))) PPC_WEAK_FUNC(sub_8229D4B8);
PPC_FUNC_IMPL(__imp__sub_8229D4B8) {
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
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,40
	r31.s64 = 40;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lwz r3,17120(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17120);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r9.u32);
	// beq cr6,0x8229d504
	if (cr6.eq) goto loc_8229D504;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229D504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229D504:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
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

__attribute__((alias("__imp__sub_8229D528"))) PPC_WEAK_FUNC(sub_8229D528);
PPC_FUNC_IMPL(__imp__sub_8229D528) {
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
	ctx.lr = 0x8229D530;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8229d56c
	if (!cr6.gt) goto loc_8229D56C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_8229D548:
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
	ctx.lr = 0x8229D560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// bne 0x8229d548
	if (!cr0.eq) goto loc_8229D548;
loc_8229D56C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8229D574;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229D57C"))) PPC_WEAK_FUNC(sub_8229D57C);
PPC_FUNC_IMPL(__imp__sub_8229D57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D580"))) PPC_WEAK_FUNC(sub_8229D580);
PPC_FUNC_IMPL(__imp__sub_8229D580) {
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
	// addi r10,r11,19556
	ctx.r10.s64 = r11.s64 + 19556;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x8229D5AC;
	sub_821D2810(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229d5c4
	if (cr6.eq) goto loc_8229D5C4;
	// bl 0x82130588
	ctx.lr = 0x8229D5C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229D5C4:
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

__attribute__((alias("__imp__sub_8229D5DC"))) PPC_WEAK_FUNC(sub_8229D5DC);
PPC_FUNC_IMPL(__imp__sub_8229D5DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D5E0"))) PPC_WEAK_FUNC(sub_8229D5E0);
PPC_FUNC_IMPL(__imp__sub_8229D5E0) {
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
	ctx.lr = 0x8229D5E8;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r11,19612
	r30.s64 = r11.s64 + 19612;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r10,19604
	ctx.r5.s64 = ctx.r10.s64 + 19604;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8229D618;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1ce8
	ctx.lr = 0x8229D62C;
	sub_821D1CE8(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,19592
	ctx.r4.s64 = ctx.r8.s64 + 19592;
	// bl 0x821d0898
	ctx.lr = 0x8229D63C;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x8229D648;
	sub_821D0490(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,19580
	ctx.r4.s64 = ctx.r7.s64 + 19580;
	// bl 0x821d0898
	ctx.lr = 0x8229D65C;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x8229D668;
	sub_821D0490(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,19568
	ctx.r4.s64 = ctx.r6.s64 + 19568;
	// bl 0x821d0898
	ctx.lr = 0x8229D67C;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x8229D688;
	sub_821D0490(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8229D694;
	sub_821BE610(ctx, base);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229D69C"))) PPC_WEAK_FUNC(sub_8229D69C);
PPC_FUNC_IMPL(__imp__sub_8229D69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D6A0"))) PPC_WEAK_FUNC(sub_8229D6A0);
PPC_FUNC_IMPL(__imp__sub_8229D6A0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,19624
	ctx.r10.s64 = r11.s64 + 19624;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821bbea8
	ctx.lr = 0x8229D6C8;
	sub_821BBEA8(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229d6e8
	if (cr6.eq) goto loc_8229D6E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229D6E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229D6E8:
	// bl 0x821bbf00
	ctx.lr = 0x8229D6EC;
	sub_821BBF00(ctx, base);
	// lwz r30,40(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8229d708
	if (cr6.eq) goto loc_8229D708;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229ee80
	ctx.lr = 0x8229D700;
	sub_8229EE80(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8229D708;
	sub_82130588(ctx, base);
loc_8229D708:
	// bl 0x821bbea8
	ctx.lr = 0x8229D70C;
	sub_821BBEA8(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23464(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23464);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229D724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8258afb0
	ctx.lr = 0x8229D728;
	sub_8258AFB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,17120(r8)
	PPC_STORE_U32(ctx.r8.u32 + 17120, r11.u32);
	// bl 0x821bbf00
	ctx.lr = 0x8229D738;
	sub_821BBF00(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,19556
	ctx.r6.s64 = ctx.r7.s64 + 19556;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// bl 0x821d2810
	ctx.lr = 0x8229D74C;
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

__attribute__((alias("__imp__sub_8229D764"))) PPC_WEAK_FUNC(sub_8229D764);
PPC_FUNC_IMPL(__imp__sub_8229D764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D768"))) PPC_WEAK_FUNC(sub_8229D768);
PPC_FUNC_IMPL(__imp__sub_8229D768) {
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
	ctx.lr = 0x8229D770;
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
	// beq cr6,0x8229d7d4
	if (cr6.eq) goto loc_8229D7D4;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8229d7d4
	if (cr6.eq) goto loc_8229D7D4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8229D7A4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8229d7d4
	if (cr6.eq) goto loc_8229D7D4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8229D7B8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x8229f788
	ctx.lr = 0x8229D7CC;
	sub_8229F788(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229D7D4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229D7E4"))) PPC_WEAK_FUNC(sub_8229D7E4);
PPC_FUNC_IMPL(__imp__sub_8229D7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D7E8"))) PPC_WEAK_FUNC(sub_8229D7E8);
PPC_FUNC_IMPL(__imp__sub_8229D7E8) {
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
	// bl 0x8229d6a0
	ctx.lr = 0x8229D808;
	sub_8229D6A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229d820
	if (cr6.eq) goto loc_8229D820;
	// bl 0x82130588
	ctx.lr = 0x8229D81C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229D820:
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

__attribute__((alias("__imp__sub_8229D838"))) PPC_WEAK_FUNC(sub_8229D838);
PPC_FUNC_IMPL(__imp__sub_8229D838) {
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
	ctx.lr = 0x8229D840;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229d8a4
	if (cr6.eq) goto loc_8229D8A4;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_8229D860:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229d890
	if (cr6.eq) goto loc_8229D890;
loc_8229D870:
	// mr r26,r31
	r26.u64 = r31.u64;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8229D880;
	sub_821D2AA0(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x8229D888;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8229d870
	if (!cr6.eq) goto loc_8229D870;
loc_8229D890:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x8229d860
	if (cr6.lt) goto loc_8229D860;
loc_8229D8A4:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8229D8AC;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8229D8C0"))) PPC_WEAK_FUNC(sub_8229D8C0);
PPC_FUNC_IMPL(__imp__sub_8229D8C0) {
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
	// bl 0x8258ff28
	ctx.lr = 0x8229D8D8;
	sub_8258FF28(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// addi r10,r11,19644
	ctx.r10.s64 = r11.s64 + 19644;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8229f798
	ctx.lr = 0x8229D8EC;
	sub_8229F798(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,106(r31)
	PPC_STORE_U16(r31.u32 + 106, r11.u16);
	// sth r11,104(r31)
	PPC_STORE_U16(r31.u32 + 104, r11.u16);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stb r11,111(r31)
	PPC_STORE_U8(r31.u32 + 111, r11.u8);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// sth r11,116(r31)
	PPC_STORE_U16(r31.u32 + 116, r11.u16);
	// sth r11,118(r31)
	PPC_STORE_U16(r31.u32 + 118, r11.u16);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229D924"))) PPC_WEAK_FUNC(sub_8229D924);
PPC_FUNC_IMPL(__imp__sub_8229D924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D928"))) PPC_WEAK_FUNC(sub_8229D928);
PPC_FUNC_IMPL(__imp__sub_8229D928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// srw r3,r4,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (r11.u8 & 0x3F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229D934"))) PPC_WEAK_FUNC(sub_8229D934);
PPC_FUNC_IMPL(__imp__sub_8229D934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229D938"))) PPC_WEAK_FUNC(sub_8229D938);
PPC_FUNC_IMPL(__imp__sub_8229D938) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229d97c
	if (cr6.eq) goto loc_8229D97C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229D960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-23464(r9)
	PPC_STORE_U32(ctx.r9.u32 + -23464, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8229D97C:
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-23464(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23464, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229D998"))) PPC_WEAK_FUNC(sub_8229D998);
PPC_FUNC_IMPL(__imp__sub_8229D998) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229D9A0"))) PPC_WEAK_FUNC(sub_8229D9A0);
PPC_FUNC_IMPL(__imp__sub_8229D9A0) {
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
	ctx.lr = 0x8229D9A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// bl 0x82130528
	ctx.lr = 0x8229D9B8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8229d9e4
	if (!cr6.gt) goto loc_8229D9E4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8229D9C8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229d9d8
	if (cr6.eq) goto loc_8229D9D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8229f798
	ctx.lr = 0x8229D9D8;
	sub_8229F798(ctx, base);
loc_8229D9D8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// bne 0x8229d9c8
	if (!cr0.eq) goto loc_8229D9C8;
loc_8229D9E4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229D9F0"))) PPC_WEAK_FUNC(sub_8229D9F0);
PPC_FUNC_IMPL(__imp__sub_8229D9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// slw r11,r10,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// lwz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// and r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 & ctx.r4.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8229DA14"))) PPC_WEAK_FUNC(sub_8229DA14);
PPC_FUNC_IMPL(__imp__sub_8229DA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229DA18"))) PPC_WEAK_FUNC(sub_8229DA18);
PPC_FUNC_IMPL(__imp__sub_8229DA18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,116(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 116);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229DA24"))) PPC_WEAK_FUNC(sub_8229DA24);
PPC_FUNC_IMPL(__imp__sub_8229DA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229DA28"))) PPC_WEAK_FUNC(sub_8229DA28);
PPC_FUNC_IMPL(__imp__sub_8229DA28) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x8229DA48;
	sub_82183870(ctx, base);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8229DA50:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8229da74
	if (cr6.eq) goto loc_8229DA74;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8229da50
	if (cr6.eq) goto loc_8229DA50;
loc_8229DA74:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8229daa8
	if (cr6.eq) goto loc_8229DAA8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x8258f990
	ctx.lr = 0x8229DA88;
	sub_8258F990(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229daa8
	if (cr6.eq) goto loc_8229DAA8;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8229DAA8:
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229DAC0"))) PPC_WEAK_FUNC(sub_8229DAC0);
PPC_FUNC_IMPL(__imp__sub_8229DAC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,36
	r11.s64 = ctx.r3.s64 + 36;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x8229dafc
	if (cr6.eq) goto loc_8229DAFC;
	// lhz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229dafc
	if (cr6.eq) goto loc_8229DAFC;
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// subf r9,r11,r4
	ctx.r9.s64 = ctx.r4.s64 - r11.s64;
	// srawi r11,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	r11.s64 = ctx.r9.s32 >> 6;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8229daf4
	if (cr6.gt) goto loc_8229DAF4;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
loc_8229DAF4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8229DAFC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229DB04"))) PPC_WEAK_FUNC(sub_8229DB04);
PPC_FUNC_IMPL(__imp__sub_8229DB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229DB08"))) PPC_WEAK_FUNC(sub_8229DB08);
PPC_FUNC_IMPL(__imp__sub_8229DB08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x8229db30
	if (!cr6.gt) goto loc_8229DB30;
	// lhz r11,116(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 116);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x8229db30
	if (cr6.gt) goto loc_8229DB30;
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r10,r4,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,-64
	ctx.r3.s64 = r11.s64 + -64;
	// blr 
	return;
loc_8229DB30:
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229DB38"))) PPC_WEAK_FUNC(sub_8229DB38);
PPC_FUNC_IMPL(__imp__sub_8229DB38) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x8229DB58;
	sub_82183870(ctx, base);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8229DB60:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8229db84
	if (cr6.eq) goto loc_8229DB84;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8229db60
	if (cr6.eq) goto loc_8229DB60;
loc_8229DB84:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8229dba4
	if (!cr6.eq) goto loc_8229DBA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8229DBA4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x8258f990
	ctx.lr = 0x8229DBB0;
	sub_8258F990(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229dbe8
	if (cr6.eq) goto loc_8229DBE8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229DBD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8229DBE8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229DC00"))) PPC_WEAK_FUNC(sub_8229DC00);
PPC_FUNC_IMPL(__imp__sub_8229DC00) {
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
	ctx.lr = 0x8229DC08;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-29924
	ctx.r8.s64 = ctx.r10.s64 + -29924;
	// stw r9,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r9.u32);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x8229DC3C;
	sub_821CF7B8(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,-20156
	ctx.r4.s64 = ctx.r7.s64 + -20156;
	// bl 0x823db730
	ctx.lr = 0x8229DC4C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8229dc78
	if (!cr6.eq) goto loc_8229DC78;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,36
	ctx.r4.s64 = r31.s64 + 36;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229DC70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
loc_8229DC78:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8229DC94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229DCAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229DCB4"))) PPC_WEAK_FUNC(sub_8229DCB4);
PPC_FUNC_IMPL(__imp__sub_8229DCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229DCB8"))) PPC_WEAK_FUNC(sub_8229DCB8);
PPC_FUNC_IMPL(__imp__sub_8229DCB8) {
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
	ctx.lr = 0x8229DCC0;
	// stwu r1,-1632(r1)
	ea = -1632 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r6,r10,3998
	ctx.r6.s64 = ctx.r10.s64 + 3998;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// bl 0x821ca2f8
	ctx.lr = 0x8229DCF4;
	sub_821CA2F8(ctx, base);
	// addi r11,r1,480
	r11.s64 = ctx.r1.s64 + 480;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8229DCFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229dcfc
	if (!cr6.eq) goto loc_8229DCFC;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// li r25,0
	r25.s64 = 0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8229dd3c
	if (!cr6.gt) goto loc_8229DD3C;
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r10,46
	cr6.compare<uint32_t>(ctx.r10.u32, 46, xer);
	// bne cr6,0x8229dd3c
	if (!cr6.eq) goto loc_8229DD3C;
	// stb r25,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r25.u8);
loc_8229DD3C:
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x821d2a58
	ctx.lr = 0x8229DD48;
	sub_821D2A58(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r29,r11,19792
	r29.s64 = r11.s64 + 19792;
	// addi r5,r10,-24488
	ctx.r5.s64 = ctx.r10.s64 + -24488;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x821ca6a8
	ctx.lr = 0x8229DD6C;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8229decc
	if (cr6.eq) goto loc_8229DECC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r25,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, r25.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r10,r11,-29924
	ctx.r10.s64 = r11.s64 + -29924;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r10,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, ctx.r10.u32);
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cf7b8
	ctx.lr = 0x8229DD98;
	sub_821CF7B8(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cfaa8
	ctx.lr = 0x8229DDA8;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8229ddcc
	if (cr6.eq) goto loc_8229DDCC;
loc_8229DDB0:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x821cfaa8
	ctx.lr = 0x8229DDC4;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8229ddb0
	if (!cr6.eq) goto loc_8229DDB0;
loc_8229DDCC:
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// bl 0x821c9438
	ctx.lr = 0x8229DDD4;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r27,100
	ctx.r3.s64 = r27.s64 + 100;
	// bl 0x821bed68
	ctx.lr = 0x8229DDE0;
	sub_821BED68(ctx, base);
	// addi r30,r27,112
	r30.s64 = r27.s64 + 112;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229ddfc
	if (cr6.eq) goto loc_8229DDFC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229d9a0
	ctx.lr = 0x8229DDF8;
	sub_8229D9A0(ctx, base);
	// b 0x8229de00
	goto loc_8229DE00;
loc_8229DDFC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_8229DE00:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8258fa50
	ctx.lr = 0x8229DE14;
	sub_8258FA50(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be568
	ctx.lr = 0x8229DE20;
	sub_821BE568(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cf7b8
	ctx.lr = 0x8229DE30;
	sub_821CF7B8(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cfaa8
	ctx.lr = 0x8229DE40;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8229debc
	if (cr6.eq) goto loc_8229DEBC;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r10,19720
	r29.s64 = ctx.r10.s64 + 19720;
	// addi r30,r11,19716
	r30.s64 = r11.s64 + 19716;
loc_8229DE58:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca6a8
	ctx.lr = 0x8229DE70;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229de98
	if (cr6.eq) goto loc_8229DE98;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8229dc00
	ctx.lr = 0x8229DE8C;
	sub_8229DC00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8229DE94;
	sub_821BE610(ctx, base);
	// b 0x8229dea4
	goto loc_8229DEA4;
loc_8229DE98:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x8229DEA4;
	sub_82130000(ctx, base);
loc_8229DEA4:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x821cfaa8
	ctx.lr = 0x8229DEB4;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8229de58
	if (!cr6.eq) goto loc_8229DE58;
loc_8229DEBC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x8229DEC4;
	sub_821BE610(ctx, base);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
loc_8229DECC:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x821cb488
	ctx.lr = 0x8229DED8;
	sub_821CB488(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229e0a8
	if (cr6.eq) goto loc_8229E0A8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229DEFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8229e0a8
	if (cr6.eq) goto loc_8229E0A8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r26,r11,19716
	r26.s64 = r11.s64 + 19716;
loc_8229DF10:
	// li r4,46
	ctx.r4.s64 = 46;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x823db6d0
	ctx.lr = 0x8229DF1C;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229df3c
	if (cr6.eq) goto loc_8229DF3C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bl 0x823db730
	ctx.lr = 0x8229DF30;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8229df3c
	if (!cr6.eq) goto loc_8229DF3C;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_8229DF3C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229DF58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229df10
	if (!cr6.eq) goto loc_8229DF10;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229DF7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// bl 0x821c9438
	ctx.lr = 0x8229DF84;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r27,100
	ctx.r3.s64 = r27.s64 + 100;
	// bl 0x821bed68
	ctx.lr = 0x8229DF90;
	sub_821BED68(ctx, base);
	// addi r30,r27,112
	r30.s64 = r27.s64 + 112;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229dfac
	if (cr6.eq) goto loc_8229DFAC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229d9a0
	ctx.lr = 0x8229DFA8;
	sub_8229D9A0(ctx, base);
	// b 0x8229dfb0
	goto loc_8229DFB0;
loc_8229DFAC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_8229DFB0:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8258fa50
	ctx.lr = 0x8229DFC4;
	sub_8258FA50(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229DFE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8229DFE4:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca6a8
	ctx.lr = 0x8229DFFC;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8229e060
	if (cr6.eq) goto loc_8229E060;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8229E010:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229e010
	if (!cr6.eq) goto loc_8229E010;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,1296
	ctx.r3.s64 = ctx.r1.s64 + 1296;
	// rotlwi r31,r11,0
	r31.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r5,r31,-4
	ctx.r5.s64 = r31.s64 + -4;
	// bl 0x823db670
	ctx.lr = 0x8229E03C;
	sub_823DB670(ctx, base);
	// addi r11,r1,1296
	r11.s64 = ctx.r1.s64 + 1296;
	// addi r5,r1,1296
	ctx.r5.s64 = ctx.r1.s64 + 1296;
	// add r10,r31,r11
	ctx.r10.u64 = r31.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r25,-4(r10)
	PPC_STORE_U8(ctx.r10.u32 + -4, r25.u8);
	// bl 0x8229dc00
	ctx.lr = 0x8229E058;
	sub_8229DC00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x8229E060;
	sub_821BE610(ctx, base);
loc_8229E060:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229E07C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8229dfe4
	if (!cr6.eq) goto loc_8229DFE4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229E0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
loc_8229E0A8:
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// bl 0x821c9438
	ctx.lr = 0x8229E0B0;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r27,100
	ctx.r3.s64 = r27.s64 + 100;
	// bl 0x821bed68
	ctx.lr = 0x8229E0BC;
	sub_821BED68(ctx, base);
	// addi r30,r27,112
	r30.s64 = r27.s64 + 112;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229e0e4
	if (cr6.eq) goto loc_8229E0E4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229d9a0
	ctx.lr = 0x8229E0D4;
	sub_8229D9A0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
loc_8229E0E4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r1,r1,1632
	ctx.r1.s64 = ctx.r1.s64 + 1632;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8229E0F8"))) PPC_WEAK_FUNC(sub_8229E0F8);
PPC_FUNC_IMPL(__imp__sub_8229E0F8) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r11,116(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 116);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r9,r11,6
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 6);
	// sth r8,116(r31)
	PPC_STORE_U16(r31.u32 + 116, ctx.r8.u16);
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// add r30,r9,r10
	r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x82183870
	ctx.lr = 0x8229E138;
	sub_82183870(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x824a5248
	ctx.lr = 0x8229E14C;
	sub_824A5248(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x8238d0d0
	ctx.lr = 0x8229E15C;
	sub_8238D0D0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_8229E178"))) PPC_WEAK_FUNC(sub_8229E178);
PPC_FUNC_IMPL(__imp__sub_8229E178) {
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
	// addi r10,r11,19644
	ctx.r10.s64 = r11.s64 + 19644;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r5,118(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 118);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8229e1b8
	if (cr6.eq) goto loc_8229E1B8;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8229d528
	ctx.lr = 0x8229E1B8;
	sub_8229D528(ctx, base);
loc_8229E1B8:
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x8229d838
	ctx.lr = 0x8229E1C0;
	sub_8229D838(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x8229fb38
	ctx.lr = 0x8229E1C8;
	sub_8229FB38(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8258ff70
	ctx.lr = 0x8229E1D0;
	sub_8258FF70(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229e1e8
	if (cr6.eq) goto loc_8229E1E8;
	// bl 0x82130588
	ctx.lr = 0x8229E1E4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229E1E8:
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

__attribute__((alias("__imp__sub_8229E200"))) PPC_WEAK_FUNC(sub_8229E200);
PPC_FUNC_IMPL(__imp__sub_8229E200) {
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
	// bl 0x823d91f0
	ctx.lr = 0x8229E208;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821bbea8
	ctx.lr = 0x8229E218;
	sub_821BBEA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825953a0
	ctx.lr = 0x8229E220;
	sub_825953A0(ctx, base);
	// bl 0x8258ae78
	ctx.lr = 0x8229E224;
	sub_8258AE78(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82588e68
	ctx.lr = 0x8229E22C;
	sub_82588E68(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r11,25344
	r11.s64 = 25344;
	// li r10,256
	ctx.r10.s64 = 256;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// addi r4,r9,19804
	ctx.r4.s64 = ctx.r9.s64 + 19804;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x8229E260;
	sub_821CA540(ctx, base);
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82130528
	ctx.lr = 0x8229E268;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229e27c
	if (cr6.eq) goto loc_8229E27C;
	// bl 0x8229d8c0
	ctx.lr = 0x8229E274;
	sub_8229D8C0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8229e280
	goto loc_8229E280;
loc_8229E27C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8229E280:
	// lis r28,-32114
	r28.s64 = -2104623104;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r3,r11,36
	ctx.r3.s64 = r11.s64 + 36;
	// addi r4,r10,-20156
	ctx.r4.s64 = ctx.r10.s64 + -20156;
	// stw r11,-23464(r28)
	PPC_STORE_U32(r28.u32 + -23464, r11.u32);
	// bl 0x8238d0d0
	ctx.lr = 0x8229E298;
	sub_8238D0D0(ctx, base);
	// bl 0x8229f958
	ctx.lr = 0x8229E29C;
	sub_8229F958(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,-23464(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -23464);
	// addi r27,r9,-20564
	r27.s64 = ctx.r9.s64 + -20564;
	// addi r26,r8,-20524
	r26.s64 = ctx.r8.s64 + -20524;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8229E2C4;
	sub_823DEDD8(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8229E2D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8229f810
	ctx.lr = 0x8229E2D8;
	sub_8229F810(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,-23464(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -23464);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8229E2F0;
	sub_823DEDD8(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8229E304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8229E30C;
	sub_821C9A90(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r3,160
	ctx.r3.s64 = 160;
	// lfs f0,-6172(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6172);
	f0.f64 = double(temp.f32);
	// lfs f13,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,10356(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 10356, temp.u32);
	// stfs f13,10360(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 10360, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x8229E334;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229e344
	if (cr6.eq) goto loc_8229E344;
	// bl 0x8229fc00
	ctx.lr = 0x8229E340;
	sub_8229FC00(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8229E344:
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// bl 0x821c8fe0
	ctx.lr = 0x8229E358;
	sub_821C8FE0(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r10,104(r30)
	PPC_STORE_U32(r30.u32 + 104, ctx.r10.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,108(r30)
	PPC_STORE_U32(r30.u32 + 108, ctx.r9.u32);
	// bl 0x821c9030
	ctx.lr = 0x8229E370;
	sub_821C9030(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,31016(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvlx128 v63,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vspltw128 v50,v59,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v63,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f13,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v61,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vrlimi128 v56,v55,7,0
	simde_mm_store_ps(v56.f32, simde_mm_blend_ps(simde_mm_load_ps(v56.f32), simde_mm_permute_ps(simde_mm_load_ps(v55.f32), 228), 7));
	// vspltw128 v53,v62,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v60,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vrlimi128 v57,v54,7,0
	simde_mm_store_ps(v57.f32, simde_mm_blend_ps(simde_mm_load_ps(v57.f32), simde_mm_permute_ps(simde_mm_load_ps(v54.f32), 228), 7));
	// addi r4,r6,17152
	ctx.r4.s64 = ctx.r6.s64 + 17152;
	// vrlimi128 v53,v56,11,0
	simde_mm_store_ps(v53.f32, simde_mm_blend_ps(simde_mm_load_ps(v53.f32), simde_mm_permute_ps(simde_mm_load_ps(v56.f32), 228), 11));
	// addi r6,r5,17168
	ctx.r6.s64 = ctx.r5.s64 + 17168;
	// vrlimi128 v52,v57,11,0
	simde_mm_store_ps(v52.f32, simde_mm_blend_ps(simde_mm_load_ps(v52.f32), simde_mm_permute_ps(simde_mm_load_ps(v57.f32), 228), 11));
	// vrlimi128 v51,v53,13,0
	simde_mm_store_ps(v51.f32, simde_mm_blend_ps(simde_mm_load_ps(v51.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 228), 13));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v50,v52,13,0
	simde_mm_store_ps(v50.f32, simde_mm_blend_ps(simde_mm_load_ps(v50.f32), simde_mm_permute_ps(simde_mm_load_ps(v52.f32), 228), 13));
	// vaddfp128 v2,v63,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32)));
	// vsubfp128 v1,v62,v50
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v50.f32)));
	// bl 0x8256cba0
	ctx.lr = 0x8229E430;
	sub_8256CBA0(ctx, base);
	// li r4,5000
	ctx.r4.s64 = 5000;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x8256cc10
	ctx.lr = 0x8229E43C;
	sub_8256CC10(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x8256cb98
	ctx.lr = 0x8229E458;
	sub_8256CB98(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// sth r3,40(r11)
	PPC_STORE_U16(r11.u32 + 40, ctx.r3.u16);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r5,140(r9)
	PPC_STORE_U32(ctx.r9.u32 + 140, ctx.r5.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r4,100(r8)
	PPC_STORE_U32(ctx.r8.u32 + 100, ctx.r4.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x8256edf0
	ctx.lr = 0x8229E484;
	sub_8256EDF0(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r11,-23452(r7)
	PPC_STORE_U32(ctx.r7.u32 + -23452, r11.u32);
	// lfs f31,14992(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14992);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x825952c0
	ctx.lr = 0x8229E4A0;
	sub_825952C0(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825952d0
	ctx.lr = 0x8229E4A8;
	sub_825952D0(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82590660
	ctx.lr = 0x8229E4B0;
	sub_82590660(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82590670
	ctx.lr = 0x8229E4B8;
	sub_82590670(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x8229E4BC;
	sub_821BBF00(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8229E4C8"))) PPC_WEAK_FUNC(sub_8229E4C8);
PPC_FUNC_IMPL(__imp__sub_8229E4C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// bl 0x821d2970
	ctx.lr = 0x8229E4E0;
	sub_821D2970(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// addi r10,r11,19624
	ctx.r10.s64 = r11.s64 + 19624;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8229d768
	ctx.lr = 0x8229E4F4;
	sub_8229D768(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x8229ea18
	ctx.lr = 0x8229E504;
	sub_8229EA18(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r9,17168
	ctx.r5.s64 = ctx.r9.s64 + 17168;
	// addi r4,r8,17152
	ctx.r4.s64 = ctx.r8.s64 + 17152;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8229e200
	ctx.lr = 0x8229E534;
	sub_8229E200(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8229E54C"))) PPC_WEAK_FUNC(sub_8229E54C);
PPC_FUNC_IMPL(__imp__sub_8229E54C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229E550"))) PPC_WEAK_FUNC(sub_8229E550);
PPC_FUNC_IMPL(__imp__sub_8229E550) {
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
	// bl 0x821d2970
	ctx.lr = 0x8229E568;
	sub_821D2970(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,19556
	ctx.r9.s64 = ctx.r10.s64 + 19556;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// bl 0x8229d5e0
	ctx.lr = 0x8229E5A0;
	sub_8229D5E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8229e200
	ctx.lr = 0x8229E5A8;
	sub_8229E200(ctx, base);
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

__attribute__((alias("__imp__sub_8229E5C0"))) PPC_WEAK_FUNC(sub_8229E5C0);
PPC_FUNC_IMPL(__imp__sub_8229E5C0) {
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
	ctx.lr = 0x8229E5C8;
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
	ctx.lr = 0x8229E5FC;
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
	// beq cr6,0x8229e668
	if (cr6.eq) goto loc_8229E668;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8229e4c8
	ctx.lr = 0x8229E64C;
	sub_8229E4C8(ctx, base);
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
loc_8229E668:
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

__attribute__((alias("__imp__sub_8229E67C"))) PPC_WEAK_FUNC(sub_8229E67C);
PPC_FUNC_IMPL(__imp__sub_8229E67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229E680"))) PPC_WEAK_FUNC(sub_8229E680);
PPC_FUNC_IMPL(__imp__sub_8229E680) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8229E688;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,17168
	ctx.r9.s64 = r11.s64 + 17168;
	// addi r8,r10,17152
	ctx.r8.s64 = ctx.r10.s64 + 17152;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// beq cr6,0x8229e720
	if (cr6.eq) goto loc_8229E720;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,19848
	ctx.r4.s64 = ctx.r10.s64 + 19848;
	// bl 0x821ca540
	ctx.lr = 0x8229E6D8;
	sub_821CA540(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r27,r9,19612
	r27.s64 = ctx.r9.s64 + 19612;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x8229E6EC;
	sub_821CA540(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8229E6F8;
	sub_821CA540(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r30,r11,17120
	r30.s64 = r11.s64 + 17120;
	// addi r5,r8,19840
	ctx.r5.s64 = ctx.r8.s64 + 19840;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8229e5c0
	ctx.lr = 0x8229E71C;
	sub_8229E5C0(ctx, base);
	// b 0x8229e7b8
	goto loc_8229E7B8;
loc_8229E720:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,19612
	ctx.r4.s64 = ctx.r10.s64 + 19612;
	// bl 0x821ca540
	ctx.lr = 0x8229E72C;
	sub_821CA540(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8229E738;
	sub_821CA540(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r9,19832
	ctx.r4.s64 = ctx.r9.s64 + 19832;
	// bl 0x821ca540
	ctx.lr = 0x8229E748;
	sub_821CA540(ctx, base);
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82130528
	ctx.lr = 0x8229E750;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229e780
	if (cr6.eq) goto loc_8229E780;
	// bl 0x8229e550
	ctx.lr = 0x8229E760;
	sub_8229E550(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// addi r10,r11,19624
	ctx.r10.s64 = r11.s64 + 19624;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8229d768
	ctx.lr = 0x8229E774;
	sub_8229D768(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// b 0x8229e784
	goto loc_8229E784;
loc_8229E780:
	// li r31,0
	r31.s64 = 0;
loc_8229E784:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,52
	ctx.r3.s64 = 52;
	// addi r30,r11,17120
	r30.s64 = r11.s64 + 17120;
	// stw r31,17120(r11)
	PPC_STORE_U32(r11.u32 + 17120, r31.u32);
	// bl 0x82130528
	ctx.lr = 0x8229E798;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229e7a8
	if (cr6.eq) goto loc_8229E7A8;
	// bl 0x8229f1c8
	ctx.lr = 0x8229E7A4;
	sub_8229F1C8(ctx, base);
	// b 0x8229e7ac
	goto loc_8229E7AC;
loc_8229E7A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229E7AC:
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x8229f348
	ctx.lr = 0x8229E7B8;
	sub_8229F348(ctx, base);
loc_8229E7B8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8229E7C0;
	sub_821C9A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8229E7C8;
	sub_821C9A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8229E7D0;
	sub_821C9A90(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r7,500
	ctx.r7.s64 = 500;
	// lis r6,16
	ctx.r6.s64 = 1048576;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,36(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// bl 0x8258aad8
	ctx.lr = 0x8229E7EC;
	sub_8258AAD8(ctx, base);
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x82592f28
	ctx.lr = 0x8229E7FC;
	sub_82592F28(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,36(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// bl 0x8229e8f0
	ctx.lr = 0x8229E80C;
	sub_8229E8F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229E814"))) PPC_WEAK_FUNC(sub_8229E814);
PPC_FUNC_IMPL(__imp__sub_8229E814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229E818"))) PPC_WEAK_FUNC(sub_8229E818);
PPC_FUNC_IMPL(__imp__sub_8229E818) {
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
	ctx.lr = 0x8229E820;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x8229E838;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8229e864
	if (!cr6.gt) goto loc_8229E864;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8229E848:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229e858
	if (cr6.eq) goto loc_8229E858;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82595558
	ctx.lr = 0x8229E858;
	sub_82595558(ctx, base);
loc_8229E858:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// bne 0x8229e848
	if (!cr0.eq) goto loc_8229E848;
loc_8229E864:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229E870"))) PPC_WEAK_FUNC(sub_8229E870);
PPC_FUNC_IMPL(__imp__sub_8229E870) {
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
	ctx.lr = 0x8229E878;
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
	// beq cr6,0x8229e8dc
	if (cr6.eq) goto loc_8229E8DC;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8229e8dc
	if (cr6.eq) goto loc_8229E8DC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8229E8AC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8229e8dc
	if (cr6.eq) goto loc_8229E8DC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8229E8C0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82595760
	ctx.lr = 0x8229E8D4;
	sub_82595760(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229E8DC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229E8EC"))) PPC_WEAK_FUNC(sub_8229E8EC);
PPC_FUNC_IMPL(__imp__sub_8229E8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229E8F0"))) PPC_WEAK_FUNC(sub_8229E8F0);
PPC_FUNC_IMPL(__imp__sub_8229E8F0) {
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
	ctx.lr = 0x8229E8F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,36(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8229e924
	if (cr6.eq) goto loc_8229E924;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82573378
	ctx.lr = 0x8229E924;
	sub_82573378(ctx, base);
loc_8229E924:
	// lwz r4,48(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8229e944
	if (cr6.eq) goto loc_8229E944;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82573378
	ctx.lr = 0x8229E944;
	sub_82573378(ctx, base);
loc_8229E944:
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229e988
	if (cr6.eq) goto loc_8229E988;
	// li r31,0
	r31.s64 = 0;
loc_8229E958:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82573378
	ctx.lr = 0x8229E974;
	sub_82573378(ctx, base);
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8229e958
	if (cr6.lt) goto loc_8229E958;
loc_8229E988:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229E990"))) PPC_WEAK_FUNC(sub_8229E990);
PPC_FUNC_IMPL(__imp__sub_8229E990) {
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
	ctx.lr = 0x8229E998;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,36(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8229e9bc
	if (cr6.eq) goto loc_8229E9BC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825747f8
	ctx.lr = 0x8229E9BC;
	sub_825747F8(ctx, base);
loc_8229E9BC:
	// lwz r4,48(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8229e9d4
	if (cr6.eq) goto loc_8229E9D4;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825747f8
	ctx.lr = 0x8229E9D4;
	sub_825747F8(ctx, base);
loc_8229E9D4:
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ea10
	if (cr6.eq) goto loc_8229EA10;
	// li r31,0
	r31.s64 = 0;
loc_8229E9E8:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// bl 0x825747f8
	ctx.lr = 0x8229E9FC;
	sub_825747F8(ctx, base);
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8229e9e8
	if (cr6.lt) goto loc_8229E9E8;
loc_8229EA10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229EA18"))) PPC_WEAK_FUNC(sub_8229EA18);
PPC_FUNC_IMPL(__imp__sub_8229EA18) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8229EA20;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r6,r11,2352
	ctx.r6.s64 = r11.s64 + 2352;
	// lfs f0,-31380(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31380);
	f0.f64 = double(temp.f32);
	// li r8,32
	ctx.r8.s64 = 32;
	// lfs f13,20160(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20160);
	ctx.f13.f64 = double(temp.f32);
	// li r30,48
	r30.s64 = 48;
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stfs f0,4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// addi r31,r9,2384
	r31.s64 = ctx.r9.s64 + 2384;
	// stfs f0,8(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// stfs f13,0(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// stfs f13,8(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8229ebe0
	if (cr6.eq) goto loc_8229EBE0;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
	// lfs f0,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v61,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v57,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v55,v57,v59
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v54,v61,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v53,r9,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v52,v58,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vand128 v51,v53,v63
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v50,v58,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v49,v54,v55
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vor128 v48,v62,v51
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v51.u8)));
	// vmsum4fp128 v47,v48,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v46,v48,v49
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v45,v48,v50
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v44,v47,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v43,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// stvx128 v42,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8229eaf4
	if (!cr6.lt) goto loc_8229EAF4;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
loc_8229EAF4:
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8229eb0c
	if (!cr6.lt) goto loc_8229EB0C;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229EB0C:
	// lfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,4(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x8229eb24
	if (cr6.lt) goto loc_8229EB24;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8229EB24:
	// stfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// lwz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lvx128 v41,r11,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v36,v40,v41
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// lvx128 v39,r11,r30
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v35,v40,v41
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// lvx128 v38,r11,r10
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// vmrghw128 v37,v38,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// lfs f0,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// lvx128 v32,r11,r10
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v34,v38,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vand128 v62,v32,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v33,v36,v37
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// vmrghw128 v61,v36,v37
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v59,v35,v34
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vor128 v60,v63,v62
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmsum4fp128 v58,v60,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v33.f32), 0xFF));
	// vmsum4fp128 v57,v60,v61
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmsum4fp128 v56,v60,v59
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmrghw128 v55,v58,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v54,v57,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v53,v54,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// stvx128 v53,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x8229ebac
	if (!cr6.gt) goto loc_8229EBAC;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
loc_8229EBAC:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,0(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8229ebc4
	if (!cr6.gt) goto loc_8229EBC4;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229EBC4:
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bgt cr6,0x8229ebdc
	if (cr6.gt) goto loc_8229EBDC;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8229EBDC:
	// stfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
loc_8229EBE0:
	// lhz r11,20(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ed80
	if (cr6.eq) goto loc_8229ED80;
	// li r7,0
	ctx.r7.s64 = 0;
loc_8229EBF4:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,-80
	r28.s64 = ctx.r1.s64 + -80;
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + r11.u64;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lvx128 v52,r11,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r11,r30
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v51,v52
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lvx128 v48,r11,r10
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v47,v48,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v46,v48,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v45,v51,v52
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// lvx128 v44,r9,r8
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v43,v49,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vand128 v42,v44,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v41,v49,v47
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v40,v45,v46
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vor128 v39,v62,v42
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v42.u8)));
	// vmsum4fp128 v38,v39,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmsum4fp128 v37,v39,v40
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// vmsum4fp128 v36,v39,v41
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v41.f32), 0xFF));
	// vmrghw128 v35,v38,v39
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v34,v36,v37
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v33,v34,v35
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// stvx128 v33,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8229ec7c
	if (!cr6.lt) goto loc_8229EC7C;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
loc_8229EC7C:
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8229ec94
	if (!cr6.lt) goto loc_8229EC94;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229EC94:
	// lfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,4(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x8229ecac
	if (cr6.lt) goto loc_8229ECAC;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8229ECAC:
	// stfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// addi r28,r1,-64
	r28.s64 = ctx.r1.s64 + -64;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + r11.u64;
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v32,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// lvx128 v57,r9,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v59,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v55,v59,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vand128 v54,v57,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v53,v32,v61
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vor128 v52,v62,v54
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vmrglw128 v51,v56,v58
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v50,v56,v58
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v49,v53,v55
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmsum4fp128 v48,v52,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v47,v52,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v46,v52,v49
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmrghw128 v45,v48,v52
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v47,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v43,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-64(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x8229ed38
	if (!cr6.gt) goto loc_8229ED38;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
loc_8229ED38:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,-60(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,0(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8229ed50
	if (!cr6.gt) goto loc_8229ED50;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
loc_8229ED50:
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,-56(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bgt cr6,0x8229ed68
	if (cr6.gt) goto loc_8229ED68;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8229ED68:
	// stfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r7,r7,80
	ctx.r7.s64 = ctx.r7.s64 + 80;
	// lhz r11,20(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8229ebf4
	if (cr6.lt) goto loc_8229EBF4;
loc_8229ED80:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229ED84"))) PPC_WEAK_FUNC(sub_8229ED84);
PPC_FUNC_IMPL(__imp__sub_8229ED84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229ED88"))) PPC_WEAK_FUNC(sub_8229ED88);
PPC_FUNC_IMPL(__imp__sub_8229ED88) {
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
	ctx.lr = 0x8229ED90;
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
	// beq cr6,0x8229edbc
	if (cr6.eq) goto loc_8229EDBC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x8229EDB0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8229EDBC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229edf4
	if (cr6.eq) goto loc_8229EDF4;
	// li r30,0
	r30.s64 = 0;
loc_8229EDD0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x82595760
	ctx.lr = 0x8229EDE0;
	sub_82595760(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8229edd0
	if (cr6.lt) goto loc_8229EDD0;
loc_8229EDF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229EE00"))) PPC_WEAK_FUNC(sub_8229EE00);
PPC_FUNC_IMPL(__imp__sub_8229EE00) {
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
	ctx.lr = 0x8229EE08;
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
	// beq cr6,0x8229ee6c
	if (cr6.eq) goto loc_8229EE6C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8229ee6c
	if (cr6.eq) goto loc_8229EE6C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8229EE3C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8229ee6c
	if (cr6.eq) goto loc_8229EE6C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8229EE50;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x825988d8
	ctx.lr = 0x8229EE64;
	sub_825988D8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8229EE6C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8229EE7C"))) PPC_WEAK_FUNC(sub_8229EE7C);
PPC_FUNC_IMPL(__imp__sub_8229EE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229EE80"))) PPC_WEAK_FUNC(sub_8229EE80);
PPC_FUNC_IMPL(__imp__sub_8229EE80) {
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
	ctx.lr = 0x8229EE88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r27,r31,16
	r27.s64 = r31.s64 + 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lhz r5,22(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x822d6998
	ctx.lr = 0x8229EEA4;
	sub_822D6998(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// sth r28,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r28.u16);
	// sth r28,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r28.u16);
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ef10
	if (cr6.eq) goto loc_8229EF10;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8229EEC8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8258e568
	ctx.lr = 0x8229EED8;
	sub_8258E568(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r30,r10
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229eefc
	if (cr6.eq) goto loc_8229EEFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229EEFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229EEFC:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8229eec8
	if (cr6.lt) goto loc_8229EEC8;
loc_8229EF10:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r26,r31,8
	r26.s64 = r31.s64 + 8;
	// bl 0x82130588
	ctx.lr = 0x8229EF1C;
	sub_82130588(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// sth r28,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r28.u16);
	// mr r29,r28
	r29.u64 = r28.u64;
	// sth r28,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r28.u16);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ef84
	if (cr6.eq) goto loc_8229EF84;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8229EF3C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82582fd0
	ctx.lr = 0x8229EF4C;
	sub_82582FD0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r10
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229ef70
	if (cr6.eq) goto loc_8229EF70;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229EF70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229EF70:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8229ef3c
	if (cr6.lt) goto loc_8229EF3C;
loc_8229EF84:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8229EF8C;
	sub_82130588(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// beq cr6,0x8229efb8
	if (cr6.eq) goto loc_8229EFB8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229EFB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229EFB8:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8229efcc
	if (cr6.eq) goto loc_8229EFCC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8258e568
	ctx.lr = 0x8229EFCC;
	sub_8258E568(ctx, base);
loc_8229EFCC:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229efec
	if (cr6.eq) goto loc_8229EFEC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229EFEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229EFEC:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8229f000
	if (cr6.eq) goto loc_8229F000;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82582fd0
	ctx.lr = 0x8229F000;
	sub_82582FD0(ctx, base);
loc_8229F000:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f020
	if (cr6.eq) goto loc_8229F020;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229F020:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f040
	if (cr6.eq) goto loc_8229F040;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229F040:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f060
	if (cr6.eq) goto loc_8229F060;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229F060:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f080
	if (cr6.eq) goto loc_8229F080;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229F080:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f0a0
	if (cr6.eq) goto loc_8229F0A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8229F0A0:
	// lhz r29,6(r27)
	r29.u64 = PPC_LOAD_U16(r27.u32 + 6);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229f0e8
	if (cr6.eq) goto loc_8229F0E8;
	// lwz r28,0(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8229f0e0
	if (!cr6.gt) goto loc_8229F0E0;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8229F0BC:
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
	ctx.lr = 0x8229F0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bne 0x8229f0bc
	if (!cr0.eq) goto loc_8229F0BC;
loc_8229F0E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8229F0E8;
	sub_82130588(ctx, base);
loc_8229F0E8:
	// lhz r11,6(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229f0fc
	if (cr6.eq) goto loc_8229F0FC;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8229F0FC;
	sub_82130588(ctx, base);
loc_8229F0FC:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229f110
	if (cr6.eq) goto loc_8229F110;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8229F110;
	sub_82130588(ctx, base);
loc_8229F110:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8229F118"))) PPC_WEAK_FUNC(sub_8229F118);
PPC_FUNC_IMPL(__imp__sub_8229F118) {
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
	ctx.lr = 0x8229F120;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8229F130;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8229f1b8
	if (!cr6.gt) goto loc_8229F1B8;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_8229F148:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229f1ac
	if (cr6.eq) goto loc_8229F1AC;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8229f1a8
	if (cr6.eq) goto loc_8229F1A8;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229f1a8
	if (cr6.eq) goto loc_8229F1A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8229F17C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8229f1a8
	if (cr6.eq) goto loc_8229F1A8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8229F190;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8258f980
	ctx.lr = 0x8229F1A4;
	sub_8258F980(ctx, base);
	// b 0x8229f1ac
	goto loc_8229F1AC;
loc_8229F1A8:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_8229F1AC:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8229f148
	if (!cr0.eq) goto loc_8229F148;
loc_8229F1B8:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8229F1C4"))) PPC_WEAK_FUNC(sub_8229F1C4);
PPC_FUNC_IMPL(__imp__sub_8229F1C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229F1C8"))) PPC_WEAK_FUNC(sub_8229F1C8);
PPC_FUNC_IMPL(__imp__sub_8229F1C8) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
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
	// bl 0x8229ee00
	ctx.lr = 0x8229F210;
	sub_8229EE00(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x821b5a60
	ctx.lr = 0x8229F218;
	sub_821B5A60(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x8249e348
	ctx.lr = 0x8229F220;
	sub_8249E348(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x8229e870
	ctx.lr = 0x8229F228;
	sub_8229E870(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x821b5a60
	ctx.lr = 0x8229F230;
	sub_821B5A60(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x8249e348
	ctx.lr = 0x8229F238;
	sub_8249E348(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x8229e870
	ctx.lr = 0x8229F240;
	sub_8229E870(ctx, base);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8229F278"))) PPC_WEAK_FUNC(sub_8229F278);
PPC_FUNC_IMPL(__imp__sub_8229F278) {
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
	ctx.lr = 0x8229F280;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229f2a8
	if (cr6.eq) goto loc_8229F2A8;
	// bl 0x8217d890
	ctx.lr = 0x8229F29C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_8229F2A8:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229f338
	if (cr6.eq) goto loc_8229F338;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_8229F2C8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8229f320
	if (cr6.eq) goto loc_8229F320;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8229f320
	if (cr6.eq) goto loc_8229F320;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8229F2F4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8229f320
	if (cr6.eq) goto loc_8229F320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8229F308;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x8258f980
	ctx.lr = 0x8229F31C;
	sub_8258F980(ctx, base);
	// b 0x8229f324
	goto loc_8229F324;
loc_8229F320:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_8229F324:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x8229f2c8
	if (cr6.lt) goto loc_8229F2C8;
loc_8229F338:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8229F344"))) PPC_WEAK_FUNC(sub_8229F344);
PPC_FUNC_IMPL(__imp__sub_8229F344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229F348"))) PPC_WEAK_FUNC(sub_8229F348);
PPC_FUNC_IMPL(__imp__sub_8229F348) {
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
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8229F350;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dd534
	ctx.lr = 0x8229F358;
	// stwu r1,-1072(r1)
	ea = -1072 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r31,r9,19612
	r31.s64 = ctx.r9.s64 + 19612;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,9960(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 9960);
	// addi r5,r8,20188
	ctx.r5.s64 = ctx.r8.s64 + 20188;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// rlwinm r11,r11,0,23,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r11,9960(r10)
	PPC_STORE_U32(ctx.r10.u32 + 9960, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8229F390;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82598ee8
	ctx.lr = 0x8229F398;
	sub_82598EE8(ctx, base);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82598ee8
	ctx.lr = 0x8229F3A4;
	sub_82598EE8(ctx, base);
	// rotlwi r7,r3,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r3.u32);
	// lis r21,-32112
	r21.s64 = -2104492032;
	// li r20,2048
	r20.s64 = 2048;
	// li r22,16
	r22.s64 = 16;
	// li r23,32
	r23.s64 = 32;
	// li r24,48
	r24.s64 = 48;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x8229f484
	if (cr6.eq) goto loc_8229F484;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8229F3D0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f3e0
	if (cr6.eq) goto loc_8229F3E0;
	// bl 0x8258f4a8
	ctx.lr = 0x8229F3DC;
	sub_8258F4A8(ctx, base);
	// b 0x8229f3e4
	goto loc_8229F3E4;
loc_8229F3E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F3E4:
	// stw r3,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r4,40(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// bl 0x8258e6b8
	ctx.lr = 0x8229F3F4;
	sub_8258E6B8(ctx, base);
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// stw r20,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r20.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x8258e620
	ctx.lr = 0x8229F40C;
	sub_8258E620(ctx, base);
	// lbz r9,-2084(r21)
	ctx.r9.u64 = PPC_LOAD_U8(r21.u32 + -2084);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8229f428
	if (cr6.eq) goto loc_8229F428;
	// lhz r11,26(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,26(r10)
	PPC_STORE_U16(ctx.r10.u32 + 26, r11.u16);
loc_8229F428:
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x8229F430;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f440
	if (cr6.eq) goto loc_8229F440;
	// bl 0x82595558
	ctx.lr = 0x8229F43C;
	sub_82595558(ctx, base);
	// b 0x8229f444
	goto loc_8229F444;
loc_8229F440:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F444:
	// stw r3,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r4,44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x82595580
	ctx.lr = 0x8229F458;
	sub_82595580(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
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
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v63,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8229F484:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r5,r11,3684
	ctx.r5.s64 = r11.s64 + 3684;
	// addi r4,r10,20176
	ctx.r4.s64 = ctx.r10.s64 + 20176;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8229F4A8;
	sub_821CA6A8(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x8229f6e0
	if (cr6.eq) goto loc_8229F6E0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 880, ctx.r10.u32);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// stw r9,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cf7b8
	ctx.lr = 0x8229F4D8;
	sub_821CF7B8(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8229F4E0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f4f0
	if (cr6.eq) goto loc_8229F4F0;
	// bl 0x82595cc0
	ctx.lr = 0x8229F4EC;
	sub_82595CC0(ctx, base);
	// b 0x8229f4f4
	goto loc_8229F4F4;
loc_8229F4F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F4F4:
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x82595770
	ctx.lr = 0x8229F500;
	sub_82595770(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// lwz r3,-2076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2076);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229F51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// addi r4,r8,20164
	ctx.r4.s64 = ctx.r8.s64 + 20164;
	// bl 0x821d08d8
	ctx.lr = 0x8229F52C;
	sub_821D08D8(ctx, base);
	// lhz r7,22(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 22);
	// addi r25,r30,16
	r25.s64 = r30.s64 + 16;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8229f564
	if (!cr6.eq) goto loc_8229F564;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r31,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r31.u16);
	// beq cr6,0x8229f55c
	if (cr6.eq) goto loc_8229F55C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8229e818
	ctx.lr = 0x8229F558;
	sub_8229E818(ctx, base);
	// b 0x8229f560
	goto loc_8229F560;
loc_8229F55C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F560:
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
loc_8229F564:
	// clrlwi r28,r31,16
	r28.u64 = r31.u32 & 0xFFFF;
	// sth r28,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r28.u16);
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229f59c
	if (!cr6.eq) goto loc_8229F59C;
	// sth r28,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r28.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229f594
	if (cr6.eq) goto loc_8229F594;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82504778
	ctx.lr = 0x8229F590;
	sub_82504778(ctx, base);
	// b 0x8229f598
	goto loc_8229F598;
loc_8229F594:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F598:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8229F59C:
	// sth r28,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r28.u16);
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// lhz r11,14(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229f5d4
	if (!cr6.eq) goto loc_8229F5D4;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8229f5cc
	if (cr6.eq) goto loc_8229F5CC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229f118
	ctx.lr = 0x8229F5C8;
	sub_8229F118(ctx, base);
	// b 0x8229f5d0
	goto loc_8229F5D0;
loc_8229F5CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F5D0:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_8229F5D4:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// li r27,0
	r27.s64 = 0;
	// lhz r11,20(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229f6d8
	if (cr6.eq) goto loc_8229F6D8;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// li r28,0
	r28.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// vupkd3d128 v58,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// vpermwi128 v126,v58,234
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v125,v58,186
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// vpermwi128 v124,v58,174
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
loc_8229F604:
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwz r26,0(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82598b08
	ctx.lr = 0x8229F610;
	sub_82598B08(ctx, base);
	// stwx r3,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, ctx.r3.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8229F61C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f62c
	if (cr6.eq) goto loc_8229F62C;
	// bl 0x8258f4a8
	ctx.lr = 0x8229F628;
	sub_8258F4A8(ctx, base);
	// b 0x8229f630
	goto loc_8229F630;
loc_8229F62C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F630:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r4,r31,r10
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r31,r9
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// bl 0x8258e6b8
	ctx.lr = 0x8229F64C;
	sub_8258E6B8(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwzx r7,r31,r8
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// stw r20,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, r20.u32);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r31,r6
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// bl 0x8258e620
	ctx.lr = 0x8229F66C;
	sub_8258E620(ctx, base);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r4,-2084(r21)
	ctx.r4.u64 = PPC_LOAD_U8(r21.u32 + -2084);
	// lwzx r11,r31,r5
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8229f68c
	if (cr6.eq) goto loc_8229F68C;
	// lhz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,26(r11)
	PPC_STORE_U16(r11.u32 + 26, ctx.r10.u16);
loc_8229F68C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add r3,r28,r11
	ctx.r3.u64 = r28.u64 + r11.u64;
	// lwzx r4,r31,r10
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// bl 0x82595580
	ctx.lr = 0x8229F6A4;
	sub_82595580(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// addi r28,r28,80
	r28.s64 = r28.s64 + 80;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 20);
	// cmpw cr6,r27,r9
	cr6.compare<int32_t>(r27.s32, ctx.r9.s32, xer);
	// blt cr6,0x8229f604
	if (cr6.lt) goto loc_8229F604;
loc_8229F6D8:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821be610
	ctx.lr = 0x8229F6E0;
	sub_821BE610(ctx, base);
loc_8229F6E0:
	// addi r1,r1,1072
	ctx.r1.s64 = ctx.r1.s64 + 1072;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dd7cc
	ctx.lr = 0x8229F6EC;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8229F6F0"))) PPC_WEAK_FUNC(sub_8229F6F0);
PPC_FUNC_IMPL(__imp__sub_8229F6F0) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82249380
	ctx.lr = 0x8229F714;
	sub_82249380(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8229f278
	ctx.lr = 0x8229F724;
	sub_8229F278(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8229ed88
	ctx.lr = 0x8229F734;
	sub_8229ED88(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x8229ee00
	ctx.lr = 0x8229F73C;
	sub_8229EE00(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x821b5a60
	ctx.lr = 0x8229F744;
	sub_821B5A60(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x8249e348
	ctx.lr = 0x8229F74C;
	sub_8249E348(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x8229e870
	ctx.lr = 0x8229F754;
	sub_8229E870(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x821b5a60
	ctx.lr = 0x8229F75C;
	sub_821B5A60(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x8249e348
	ctx.lr = 0x8229F764;
	sub_8249E348(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x8229e870
	ctx.lr = 0x8229F76C;
	sub_8229E870(ctx, base);
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

__attribute__((alias("__imp__sub_8229F788"))) PPC_WEAK_FUNC(sub_8229F788);
PPC_FUNC_IMPL(__imp__sub_8229F788) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8229f6f0
	sub_8229F6F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229F794"))) PPC_WEAK_FUNC(sub_8229F794);
PPC_FUNC_IMPL(__imp__sub_8229F794) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229F798"))) PPC_WEAK_FUNC(sub_8229F798);
PPC_FUNC_IMPL(__imp__sub_8229F798) {
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
	// bl 0x82599658
	ctx.lr = 0x8229F7B0;
	sub_82599658(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,20224
	ctx.r9.s64 = r11.s64 + 20224;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r3,168
	ctx.r3.s64 = 168;
	// sth r8,56(r31)
	PPC_STORE_U16(r31.u32 + 56, ctx.r8.u16);
	// bl 0x82130528
	ctx.lr = 0x8229F7D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229f7e8
	if (cr6.eq) goto loc_8229F7E8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8229fcc0
	ctx.lr = 0x8229F7E4;
	sub_8229FCC0(ctx, base);
	// b 0x8229f7ec
	goto loc_8229F7EC;
loc_8229F7E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229F7EC:
	// li r11,0
	r11.s64 = 0;
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,58(r31)
	PPC_STORE_U16(r31.u32 + 58, r11.u16);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229F810"))) PPC_WEAK_FUNC(sub_8229F810);
PPC_FUNC_IMPL(__imp__sub_8229F810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f0,14988(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// addi r4,r8,20236
	ctx.r4.s64 = ctx.r8.s64 + 20236;
	// lfs f13,12424(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12424);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,60(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// stfs f0,28(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f13,32(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// b 0x8229fd18
	sub_8229FD18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229F83C"))) PPC_WEAK_FUNC(sub_8229F83C);
PPC_FUNC_IMPL(__imp__sub_8229F83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229F840"))) PPC_WEAK_FUNC(sub_8229F840);
PPC_FUNC_IMPL(__imp__sub_8229F840) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x825996f8
	ctx.lr = 0x8229F860;
	sub_825996F8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,20256
	ctx.r4.s64 = r11.s64 + 20256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8229F874;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229f89c
	if (cr6.eq) goto loc_8229F89C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// sth r3,56(r30)
	PPC_STORE_U16(r30.u32 + 56, ctx.r3.u16);
loc_8229F89C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,60(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// bl 0x8229fdc8
	ctx.lr = 0x8229F8A8;
	sub_8229FDC8(ctx, base);
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

__attribute__((alias("__imp__sub_8229F8C0"))) PPC_WEAK_FUNC(sub_8229F8C0);
PPC_FUNC_IMPL(__imp__sub_8229F8C0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82599948
	ctx.lr = 0x8229F8E0;
	sub_82599948(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,20264
	ctx.r4.s64 = r11.s64 + 20264;
	// lwz r9,152(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229F8FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lwz r6,144(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8229F918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,7044
	ctx.r4.s64 = ctx.r5.s64 + 7044;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229F934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x8229fe68
	ctx.lr = 0x8229F940;
	sub_8229FE68(ctx, base);
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

__attribute__((alias("__imp__sub_8229F958"))) PPC_WEAK_FUNC(sub_8229F958);
PPC_FUNC_IMPL(__imp__sub_8229F958) {
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
	ctx.lr = 0x8229F960;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r31,-32114
	r31.s64 = -2104623104;
	// addi r30,r11,-20564
	r30.s64 = r11.s64 + -20564;
	// addi r29,r10,-20524
	r29.s64 = ctx.r10.s64 + -20524;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r9,20372
	r28.s64 = ctx.r9.s64 + 20372;
	// bl 0x823dedd8
	ctx.lr = 0x8229F998;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8258fcd0
	ctx.lr = 0x8229F9A4;
	sub_8258FCD0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r8,20364
	r28.s64 = ctx.r8.s64 + 20364;
	// bl 0x823dedd8
	ctx.lr = 0x8229F9C4;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8258fcd0
	ctx.lr = 0x8229F9D0;
	sub_8258FCD0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r11,20352
	r28.s64 = r11.s64 + 20352;
	// bl 0x823dedd8
	ctx.lr = 0x8229F9F0;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x8258fcd0
	ctx.lr = 0x8229F9FC;
	sub_8258FCD0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r10,20340
	r28.s64 = ctx.r10.s64 + 20340;
	// bl 0x823dedd8
	ctx.lr = 0x8229FA1C;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FA28;
	sub_8258FCD0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r9,20332
	r28.s64 = ctx.r9.s64 + 20332;
	// bl 0x823dedd8
	ctx.lr = 0x8229FA48;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FA54;
	sub_8258FCD0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r8,20320
	r28.s64 = ctx.r8.s64 + 20320;
	// bl 0x823dedd8
	ctx.lr = 0x8229FA74;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FA80;
	sub_8258FCD0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r11,20308
	r28.s64 = r11.s64 + 20308;
	// bl 0x823dedd8
	ctx.lr = 0x8229FAA0;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FAAC;
	sub_8258FCD0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r10,20300
	r28.s64 = ctx.r10.s64 + 20300;
	// bl 0x823dedd8
	ctx.lr = 0x8229FACC;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FAD8;
	sub_8258FCD0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r9,20288
	r28.s64 = ctx.r9.s64 + 20288;
	// bl 0x823dedd8
	ctx.lr = 0x8229FAF8;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FB04;
	sub_8258FCD0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,-23464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23464);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r8,20276
	r31.s64 = ctx.r8.s64 + 20276;
	// bl 0x823dedd8
	ctx.lr = 0x8229FB24;
	sub_823DEDD8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,512
	ctx.r5.s64 = 512;
	// bl 0x8258fcd0
	ctx.lr = 0x8229FB30;
	sub_8258FCD0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8229FB38"))) PPC_WEAK_FUNC(sub_8229FB38);
PPC_FUNC_IMPL(__imp__sub_8229FB38) {
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
	// addi r10,r11,20224
	ctx.r10.s64 = r11.s64 + 20224;
	// lwz r30,60(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8229fb78
	if (cr6.eq) goto loc_8229FB78;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8229FB70;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8229FB78;
	sub_82130588(ctx, base);
loc_8229FB78:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825996e8
	ctx.lr = 0x8229FB80;
	sub_825996E8(ctx, base);
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

__attribute__((alias("__imp__sub_8229FB98"))) PPC_WEAK_FUNC(sub_8229FB98);
PPC_FUNC_IMPL(__imp__sub_8229FB98) {
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
	ctx.lr = 0x8229FBA0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,20224
	ctx.r10.s64 = r11.s64 + 20224;
	// lwz r30,60(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8229fbd4
	if (cr6.eq) goto loc_8229FBD4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8229FBCC;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8229FBD4;
	sub_82130588(ctx, base);
loc_8229FBD4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825996e8
	ctx.lr = 0x8229FBDC;
	sub_825996E8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229fbf4
	if (cr6.eq) goto loc_8229FBF4;
	// bl 0x82130588
	ctx.lr = 0x8229FBF0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229FBF4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229FBFC"))) PPC_WEAK_FUNC(sub_8229FBFC);
PPC_FUNC_IMPL(__imp__sub_8229FBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229FC00"))) PPC_WEAK_FUNC(sub_8229FC00);
PPC_FUNC_IMPL(__imp__sub_8229FC00) {
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
	// bl 0x8256cab0
	ctx.lr = 0x8229FC18;
	sub_8256CAB0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r9,r11,20660
	ctx.r9.s64 = r11.s64 + 20660;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r11,9960(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 9960);
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,9960(r10)
	PPC_STORE_U32(ctx.r10.u32 + 9960, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8229FC4C"))) PPC_WEAK_FUNC(sub_8229FC4C);
PPC_FUNC_IMPL(__imp__sub_8229FC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229FC50"))) PPC_WEAK_FUNC(sub_8229FC50);
PPC_FUNC_IMPL(__imp__sub_8229FC50) {
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
	// addi r10,r11,20660
	ctx.r10.s64 = r11.s64 + 20660;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8256f338
	ctx.lr = 0x8229FC7C;
	sub_8256F338(ctx, base);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-23452(r9)
	PPC_STORE_U32(ctx.r9.u32 + -23452, r11.u32);
	// bl 0x8256cb88
	ctx.lr = 0x8229FC90;
	sub_8256CB88(ctx, base);
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8229fca8
	if (cr6.eq) goto loc_8229FCA8;
	// bl 0x82130588
	ctx.lr = 0x8229FCA4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8229FCA8:
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

__attribute__((alias("__imp__sub_8229FCC0"))) PPC_WEAK_FUNC(sub_8229FCC0);
PPC_FUNC_IMPL(__imp__sub_8229FCC0) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x82163ee8
	ctx.lr = 0x8229FCE8;
	sub_82163EE8(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82163ee8
	ctx.lr = 0x8229FCF0;
	sub_82163EE8(ctx, base);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x82163ee8
	ctx.lr = 0x8229FCF8;
	sub_82163EE8(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x82163ee8
	ctx.lr = 0x8229FD00;
	sub_82163EE8(ctx, base);
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

__attribute__((alias("__imp__sub_8229FD18"))) PPC_WEAK_FUNC(sub_8229FD18);
PPC_FUNC_IMPL(__imp__sub_8229FD18) {
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
	ctx.lr = 0x8229FD20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,19856
	r30.s64 = r11.s64 + 19856;
	// lwz r11,760(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 760);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229fdc0
	if (cr6.eq) goto loc_8229FDC0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a20
	ctx.lr = 0x8229FD44;
	sub_82144A20(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8229fd80
	if (!cr6.eq) goto loc_8229FD80;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r9,20992
	ctx.r3.s64 = ctx.r9.s64 + 20992;
	// lwz r29,-728(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -728);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x8229FD70;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82144a20
	ctx.lr = 0x8229FD7C;
	sub_82144A20(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8229FD80:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lwz r4,214(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 214);
	// bl 0x82164840
	ctx.lr = 0x8229FD90;
	sub_82164840(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// lwz r4,74(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 74);
	// bl 0x82164840
	ctx.lr = 0x8229FDA0;
	sub_82164840(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// lwz r4,94(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 94);
	// bl 0x82164840
	ctx.lr = 0x8229FDB0;
	sub_82164840(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// lwz r4,218(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 218);
	// bl 0x82164840
	ctx.lr = 0x8229FDC0;
	sub_82164840(ctx, base);
loc_8229FDC0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229FDC8"))) PPC_WEAK_FUNC(sub_8229FDC8);
PPC_FUNC_IMPL(__imp__sub_8229FDC8) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,21164
	ctx.r4.s64 = r11.s64 + 21164;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8229FDF8;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8229fe28
	if (cr6.eq) goto loc_8229FE28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229FE20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// b 0x8229fe44
	goto loc_8229FE44;
loc_8229FE28:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,21072
	ctx.r3.s64 = ctx.r10.s64 + 21072;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x8229FE3C;
	sub_82130000(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,20236
	ctx.r4.s64 = ctx.r9.s64 + 20236;
loc_8229FE44:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229fd18
	ctx.lr = 0x8229FE4C;
	sub_8229FD18(ctx, base);
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

__attribute__((alias("__imp__sub_8229FE64"))) PPC_WEAK_FUNC(sub_8229FE64);
PPC_FUNC_IMPL(__imp__sub_8229FE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229FE68"))) PPC_WEAK_FUNC(sub_8229FE68);
PPC_FUNC_IMPL(__imp__sub_8229FE68) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,21184
	ctx.r4.s64 = ctx.r10.s64 + 21184;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8229FEA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r8,19856
	r11.s64 = ctx.r8.s64 + 19856;
	// addi r3,r11,700
	ctx.r3.s64 = r11.s64 + 700;
	// lwz r4,1(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8214d8f8
	ctx.lr = 0x8229FEBC;
	sub_8214D8F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,148(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8229FED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,7044
	ctx.r4.s64 = ctx.r5.s64 + 7044;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8229FEF0;
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

__attribute__((alias("__imp__sub_8229FF08"))) PPC_WEAK_FUNC(sub_8229FF08);
PPC_FUNC_IMPL(__imp__sub_8229FF08) {
	PPC_FUNC_PROLOGUE();
	// sth r4,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229FF10"))) PPC_WEAK_FUNC(sub_8229FF10);
PPC_FUNC_IMPL(__imp__sub_8229FF10) {
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
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,14560(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 14560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229ff6c
	if (cr6.eq) goto loc_8229FF6C;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82465898
	ctx.lr = 0x8229FF40;
	sub_82465898(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8229ff64
	if (!cr6.eq) goto loc_8229FF64;
	// lwz r3,14560(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 14560);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82465858
	ctx.lr = 0x8229FF58;
	sub_82465858(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ff6c
	if (cr6.eq) goto loc_8229FF6C;
loc_8229FF64:
	// li r11,1
	r11.s64 = 1;
	// b 0x8229ff70
	goto loc_8229FF70;
loc_8229FF6C:
	// li r11,0
	r11.s64 = 0;
loc_8229FF70:
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

__attribute__((alias("__imp__sub_8229FF8C"))) PPC_WEAK_FUNC(sub_8229FF8C);
PPC_FUNC_IMPL(__imp__sub_8229FF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8229FF90"))) PPC_WEAK_FUNC(sub_8229FF90);
PPC_FUNC_IMPL(__imp__sub_8229FF90) {
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
	ctx.lr = 0x8229FF98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// bne cr6,0x8229ffc0
	if (!cr6.eq) goto loc_8229FFC0;
	// li r11,-1
	r11.s64 = -1;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8229FFC0:
	// mr r30,r28
	r30.u64 = r28.u64;
	// bl 0x82387a18
	ctx.lr = 0x8229FFC8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229ffd8
	if (cr6.eq) goto loc_8229FFD8;
	// li r30,0
	r30.s64 = 0;
loc_8229FFD8:
	// extsh r11,r29
	r11.s64 = r29.s16;
	// li r4,2
	ctx.r4.s64 = 2;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a53b0
	ctx.lr = 0x8229FFF0;
	sub_822A53B0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a0008
	if (cr6.eq) goto loc_822A0008;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// extsh r4,r11
	ctx.r4.s64 = r11.s16;
	// bl 0x822a4ec0
	ctx.lr = 0x822A0008;
	sub_822A4EC0(ctx, base);
loc_822A0008:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82388580
	ctx.lr = 0x822A0010;
	sub_82388580(ctx, base);
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A0024"))) PPC_WEAK_FUNC(sub_822A0024);
PPC_FUNC_IMPL(__imp__sub_822A0024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A0028"))) PPC_WEAK_FUNC(sub_822A0028);
PPC_FUNC_IMPL(__imp__sub_822A0028) {
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
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A0044;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x822a4ed0
	ctx.lr = 0x822A004C;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A0054;
	sub_822A4DE8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A0068"))) PPC_WEAK_FUNC(sub_822A0068);
PPC_FUNC_IMPL(__imp__sub_822A0068) {
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
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// bl 0x82388580
	ctx.lr = 0x822A0088;
	sub_82388580(ctx, base);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822a00ac
	if (cr6.eq) goto loc_822A00AC;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A009C;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x822a4ed0
	ctx.lr = 0x822A00A4;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A00AC;
	sub_822A4DE8(ctx, base);
loc_822A00AC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A00C0"))) PPC_WEAK_FUNC(sub_822A00C0);
PPC_FUNC_IMPL(__imp__sub_822A00C0) {
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
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822a4b28
	ctx.lr = 0x822A00DC;
	sub_822A4B28(ctx, base);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A00E4;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x822a4ed0
	ctx.lr = 0x822A00EC;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A00F4;
	sub_822A4DE8(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a50c0
	ctx.lr = 0x822A00FC;
	sub_822A50C0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A0110"))) PPC_WEAK_FUNC(sub_822A0110);
PPC_FUNC_IMPL(__imp__sub_822A0110) {
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
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,676(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 676);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a0150
	if (cr6.eq) goto loc_822A0150;
	// bl 0x8234fdf0
	ctx.lr = 0x822A0140;
	sub_8234FDF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a0154
	if (cr6.eq) goto loc_822A0154;
loc_822A0150:
	// li r30,1
	r30.s64 = 1;
loc_822A0154:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82387ba0
	ctx.lr = 0x822A0160;
	sub_82387BA0(ctx, base);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// rlwinm r9,r10,0,18,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFBFFF;
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// bl 0x822a4ce0
	ctx.lr = 0x822A0178;
	sub_822A4CE0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a01c4
	if (cr6.eq) goto loc_822A01C4;
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a01c4
	if (!cr6.eq) goto loc_822A01C4;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a01c4
	if (cr6.eq) goto loc_822A01C4;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// xori r10,r11,32768
	ctx.r10.u64 = r11.u64 ^ 32768;
	// rlwinm r9,r10,0,16,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8000;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822a01c0
	if (!cr6.eq) goto loc_822A01C0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822A01C0:
	// bl 0x822a00c0
	ctx.lr = 0x822A01C4;
	sub_822A00C0(ctx, base);
loc_822A01C4:
	// li r4,43
	ctx.r4.s64 = 43;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A01D0;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a01f4
	if (cr6.eq) goto loc_822A01F4;
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a01f4
	if (!cr6.eq) goto loc_822A01F4;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// xori r10,r11,16384
	ctx.r10.u64 = r11.u64 ^ 16384;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A01F4:
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

__attribute__((alias("__imp__sub_822A020C"))) PPC_WEAK_FUNC(sub_822A020C);
PPC_FUNC_IMPL(__imp__sub_822A020C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A0210"))) PPC_WEAK_FUNC(sub_822A0210);
PPC_FUNC_IMPL(__imp__sub_822A0210) {
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
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r31,676(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 676);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a0370
	if (cr6.eq) goto loc_822A0370;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8234fdf0
	ctx.lr = 0x822A0244;
	sub_8234FDF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a0370
	if (cr6.eq) goto loc_822A0370;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822A0268;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a0370
	if (cr6.eq) goto loc_822A0370;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// rlwinm r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a02b4
	if (cr6.eq) goto loc_822A02B4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822a02e0
	if (!cr6.eq) goto loc_822A02E0;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stb r11,120(r31)
	PPC_STORE_U8(r31.u32 + 120, r11.u8);
	// stb r11,121(r31)
	PPC_STORE_U8(r31.u32 + 121, r11.u8);
	// stb r11,122(r31)
	PPC_STORE_U8(r31.u32 + 122, r11.u8);
	// stb r11,123(r31)
	PPC_STORE_U8(r31.u32 + 123, r11.u8);
	// bl 0x823452a8
	ctx.lr = 0x822A02B0;
	sub_823452A8(ctx, base);
	// b 0x822a02e0
	goto loc_822A02E0;
loc_822A02B4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a02e0
	if (cr6.eq) goto loc_822A02E0;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,120(r31)
	PPC_STORE_U8(r31.u32 + 120, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stb r11,121(r31)
	PPC_STORE_U8(r31.u32 + 121, r11.u8);
	// stb r11,122(r31)
	PPC_STORE_U8(r31.u32 + 122, r11.u8);
	// stb r11,123(r31)
	PPC_STORE_U8(r31.u32 + 123, r11.u8);
	// bl 0x82345268
	ctx.lr = 0x822A02E0;
	sub_82345268(ctx, base);
loc_822A02E0:
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// li r30,0
	r30.s64 = 0;
	// rlwinm r10,r11,16,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x1;
	// rlwinm r9,r11,15,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// rlwinm r8,r11,14,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// rlwinm r7,r11,13,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// rlwinm r6,r11,12,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// stb r8,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r8.u8);
	// rlwinm r5,r11,11,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// stb r7,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r7.u8);
	// rlwinm r4,r11,10,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// stb r6,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r6.u8);
	// rlwinm r3,r11,9,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1;
	// stb r5,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r5.u8);
	// stb r4,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r4.u8);
	// stb r3,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r3.u8);
loc_822A0328:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a0340
	if (cr6.eq) goto loc_822A0340;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x822a0358
	goto loc_822A0358;
loc_822A0340:
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// li r5,2
	ctx.r5.s64 = 2;
	// lbzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a0358
	if (!cr6.eq) goto loc_822A0358;
	// li r5,0
	ctx.r5.s64 = 0;
loc_822A0358:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82344de0
	ctx.lr = 0x822A0364;
	sub_82344DE0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x822a0328
	if (cr6.lt) goto loc_822A0328;
loc_822A0370:
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

__attribute__((alias("__imp__sub_822A0388"))) PPC_WEAK_FUNC(sub_822A0388);
PPC_FUNC_IMPL(__imp__sub_822A0388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwinm r10,r11,0,21,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFE7FF;
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A0398"))) PPC_WEAK_FUNC(sub_822A0398);
PPC_FUNC_IMPL(__imp__sub_822A0398) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a03d0
	if (cr6.eq) goto loc_822A03D0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a04fc
	if (!cr6.eq) goto loc_822A04FC;
loc_822A03D0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r30,68(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lbz r9,6(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a04ec
	if (!cr6.eq) goto loc_822A04EC;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A03F8;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a04ec
	if (cr6.eq) goto loc_822A04EC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a0438
	if (cr6.eq) goto loc_822A0438;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8232a728
	ctx.lr = 0x822A0414;
	sub_8232A728(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a0438
	if (cr6.eq) goto loc_822A0438;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,4,27,27
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 4) & 0x10) | (r11.u64 & 0xFFFFFFFFFFFFFFEF);
	// rlwimi r11,r10,4,20,20
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 4) & 0x800) | (r11.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x822a04fc
	goto loc_822A04FC;
loc_822A0438:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// rlwinm r10,r10,0,21,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// bl 0x822a5948
	ctx.lr = 0x822A0450;
	sub_822A5948(ctx, base);
	// lwz r9,880(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822a0484
	if (cr6.eq) goto loc_822A0484;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822a5948
	ctx.lr = 0x822A0464;
	sub_822A5948(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r4,72(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822A0474;
	sub_8271EB28(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r30,r9,1
	r30.u64 = ctx.r9.u64 ^ 1;
	// b 0x822a0488
	goto loc_822A0488;
loc_822A0484:
	// li r30,0
	r30.s64 = 0;
loc_822A0488:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bl 0x82337a48
	ctx.lr = 0x822A0494;
	sub_82337A48(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822a04fc
	if (cr6.eq) goto loc_822A04FC;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822a04fc
	if (!cr6.eq) goto loc_822A04FC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a04fc
	if (!cr6.eq) goto loc_822A04FC;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a04e0
	if (cr6.eq) goto loc_822A04E0;
	// rlwinm r11,r11,0,20,18
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x822a04fc
	goto loc_822A04FC;
loc_822A04E0:
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x822a04fc
	goto loc_822A04FC;
loc_822A04EC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// rlwinm r10,r10,0,21,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A04FC:
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

__attribute__((alias("__imp__sub_822A0514"))) PPC_WEAK_FUNC(sub_822A0514);
PPC_FUNC_IMPL(__imp__sub_822A0514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A0518"))) PPC_WEAK_FUNC(sub_822A0518);
PPC_FUNC_IMPL(__imp__sub_822A0518) {
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
	ctx.lr = 0x822A0520;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,76(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x822a0540
	if (!cr6.lt) goto loc_822A0540;
loc_822A0534:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822A0540:
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822a0534
	if (!cr6.eq) goto loc_822A0534;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r31,120
	ctx.r10.s64 = r31.s64 * 120;
	// addi r9,r11,14576
	ctx.r9.s64 = r11.s64 + 14576;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a0534
	if (cr6.eq) goto loc_822A0534;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,14560(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 14560);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824656d0
	ctx.lr = 0x822A0578;
	sub_824656D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a0534
	if (cr6.eq) goto loc_822A0534;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82465b90
	ctx.lr = 0x822A0594;
	sub_82465B90(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A05A0"))) PPC_WEAK_FUNC(sub_822A05A0);
PPC_FUNC_IMPL(__imp__sub_822A05A0) {
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
	ctx.lr = 0x822A05A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,76(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x822a05cc
	if (!cr6.lt) goto loc_822A05CC;
loc_822A05C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822A05CC:
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822a05c0
	if (!cr6.eq) goto loc_822A05C0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r31,120
	ctx.r10.s64 = r31.s64 * 120;
	// addi r9,r11,14576
	ctx.r9.s64 = r11.s64 + 14576;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a05c0
	if (cr6.eq) goto loc_822A05C0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,14560(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 14560);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824656d0
	ctx.lr = 0x822A0604;
	sub_824656D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a05c0
	if (cr6.eq) goto loc_822A05C0;
	// cmpwi cr6,r28,180
	cr6.compare<int32_t>(r28.s32, 180, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x822a0620
	if (cr6.lt) goto loc_822A0620;
	// li r11,-1
	r11.s64 = -1;
loc_822A0620:
	// mullw r5,r11,r29
	ctx.r5.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82465b18
	ctx.lr = 0x822A0630;
	sub_82465B18(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A063C"))) PPC_WEAK_FUNC(sub_822A063C);
PPC_FUNC_IMPL(__imp__sub_822A063C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A0640"))) PPC_WEAK_FUNC(sub_822A0640);
PPC_FUNC_IMPL(__imp__sub_822A0640) {
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
	// lwz r30,76(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822a06a8
	if (cr6.lt) goto loc_822A06A8;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,14576
	r31.s64 = r11.s64 + 14576;
	// lwz r3,14560(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a068c
	if (cr6.eq) goto loc_822A068C;
	// mulli r11,r30,120
	r11.s64 = r30.s64 * 120;
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x824656d0
	ctx.lr = 0x822A0688;
	sub_824656D0(ctx, base);
	// b 0x822a0690
	goto loc_822A0690;
loc_822A068C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A0690:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a06a8
	if (cr6.eq) goto loc_822A06A8;
	// mulli r11,r30,120
	r11.s64 = r30.s64 * 120;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82465490
	ctx.lr = 0x822A06A8;
	sub_82465490(ctx, base);
loc_822A06A8:
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

__attribute__((alias("__imp__sub_822A06C0"))) PPC_WEAK_FUNC(sub_822A06C0);
PPC_FUNC_IMPL(__imp__sub_822A06C0) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x822A06C8;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d4
	ctx.lr = 0x822A06D0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r26,1
	r26.s64 = 1;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r28,-1
	r28.s64 = -1;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// beq cr6,0x822a0710
	if (cr6.eq) goto loc_822A0710;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_822A0710:
	// fabs f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f28.u64 & ~0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,18612(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfs f0,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	f0.f64 = double(temp.f32);
	// bge cr6,0x822a0730
	if (!cr6.lt) goto loc_822A0730;
	// fmr f28,f31
	f28.f64 = f31.f64;
loc_822A0730:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,128(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lfs f13,276(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,280(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,272(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// lfs f9,276(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// lfs f7,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f12,f7,f8
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f7.f64 + ctx.f8.f64));
	// fnmadds f27,f11,f6,f5
	f27.f64 = double(float(-(ctx.f11.f64 * ctx.f6.f64 + ctx.f5.f64)));
	// bge cr6,0x822a0778
	if (!cr6.lt) goto loc_822A0778;
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x822a0778
	if (!cr6.eq) goto loc_822A0778;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
loc_822A0778:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r29,2
	r29.s64 = 2;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x822a099c
	if (cr6.gt) goto loc_822A099C;
	// lis r12,-32214
	r12.s64 = -2111176704;
	// addi r12,r12,1956
	r12.s64 = r12.s64 + 1956;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822A07B4;
	case 1:
		goto loc_822A07E0;
	case 2:
		goto loc_822A0858;
	case 3:
		goto loc_822A08F0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,1972(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1972);
	// lwz r17,2016(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2016);
	// lwz r17,2136(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2136);
	// lwz r17,2288(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2288);
loc_822A07B4:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// bge cr6,0x822a07d4
	if (!cr6.lt) goto loc_822A07D4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fneg f29,f28
	f29.u64 = f28.u64 ^ 0x8000000000000000;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// lfs f30,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f30.f64 = double(temp.f32);
	// b 0x822a099c
	goto loc_822A099C;
loc_822A07D4:
	// fmr f30,f28
	ctx.fpscr.disableFlushMode();
	f30.f64 = f28.f64;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A07E0:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// ble cr6,0x822a07f8
	if (!cr6.gt) goto loc_822A07F8;
	// li r11,4
	r11.s64 = 4;
	// fmr f30,f31
	f30.f64 = f31.f64;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// b 0x822a0998
	goto loc_822A0998;
loc_822A07F8:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// bge cr6,0x822a083c
	if (!cr6.lt) goto loc_822A083C;
	// bl 0x82332098
	ctx.lr = 0x822A0808;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a0830
	if (cr6.eq) goto loc_822A0830;
	// fneg f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f28.u64 ^ 0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f30,f12,f0,f13
	f30.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0830:
	// fneg f30,f28
	ctx.fpscr.disableFlushMode();
	f30.u64 = f28.u64 ^ 0x8000000000000000;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A083C:
	// bl 0x82332098
	ctx.lr = 0x822A0840;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a099c
	if (cr6.eq) goto loc_822A099C;
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0858:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// ble cr6,0x822a0870
	if (!cr6.gt) goto loc_822A0870;
	// fmr f30,f28
	f30.f64 = f28.f64;
	// stw r26,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r26.u32);
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0870:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x822a0884
	if (!cr6.eq) goto loc_822A0884;
	// fmr f30,f31
	f30.f64 = f31.f64;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0884:
	// lfs f30,32(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	f30.f64 = double(temp.f32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82332098
	ctx.lr = 0x822A0890;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a08b4
	if (!cr6.eq) goto loc_822A08B4;
	// fcmpu cr6,f27,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f30.f64);
	// bge cr6,0x822a08b4
	if (!cr6.lt) goto loc_822A08B4;
	// fneg f29,f28
	f29.u64 = f28.u64 ^ 0x8000000000000000;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A08B4:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82332098
	ctx.lr = 0x822A08BC;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a08e0
	if (cr6.eq) goto loc_822A08E0;
	// fcmpu cr6,f27,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f30.f64);
	// bge cr6,0x822a08e0
	if (!cr6.lt) goto loc_822A08E0;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A08E0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fneg f29,f28
	ctx.fpscr.disableFlushMode();
	f29.u64 = f28.u64 ^ 0x8000000000000000;
	// lfs f30,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f30.f64 = double(temp.f32);
	// b 0x822a099c
	goto loc_822A099C;
loc_822A08F0:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// bge cr6,0x822a0908
	if (!cr6.lt) goto loc_822A0908;
	// fneg f30,f28
	f30.u64 = f28.u64 ^ 0x8000000000000000;
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0908:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x822a0924
	if (!cr6.eq) goto loc_822A0924;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// lfs f30,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f30.f64 = double(temp.f32);
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0924:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82332098
	ctx.lr = 0x822A092C;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a0958
	if (!cr6.eq) goto loc_822A0958;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f27,f13
	cr6.compare(f27.f64, ctx.f13.f64);
	// ble cr6,0x822a0958
	if (!cr6.gt) goto loc_822A0958;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// b 0x822a0998
	goto loc_822A0998;
loc_822A0958:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82332098
	ctx.lr = 0x822A0960;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a0990
	if (cr6.eq) goto loc_822A0990;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f27,f13
	cr6.compare(f27.f64, ctx.f13.f64);
	// ble cr6,0x822a0990
	if (!cr6.gt) goto loc_822A0990;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// b 0x822a099c
	goto loc_822A099C;
loc_822A0990:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
loc_822A0998:
	// fmr f29,f28
	ctx.fpscr.disableFlushMode();
	f29.f64 = f28.f64;
loc_822A099C:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822a09d8
	if (!cr6.eq) goto loc_822A09D8;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f28,f13
	cr6.compare(f28.f64, ctx.f13.f64);
	// bge cr6,0x822a09c8
	if (!cr6.lt) goto loc_822A09C8;
	// li r28,-1
	r28.s64 = -1;
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// b 0x822a09d8
	goto loc_822A09D8;
loc_822A09C8:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f31.f64);
	// ble cr6,0x822a09d8
	if (!cr6.gt) goto loc_822A09D8;
	// mr r28,r26
	r28.u64 = r26.u64;
	// stw r26,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r26.u32);
loc_822A09D8:
	// stfs f30,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stfs f29,0(r24)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r24.u32 + 0, temp.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bge cr6,0x822a0a04
	if (!cr6.lt) goto loc_822A0A04;
	// rlwimi r11,r26,2,29,30
	r11.u64 = (__builtin_rotateleft32(r26.u32, 2) & 0x6) | (r11.u64 & 0xFFFFFFFFFFFFFFF9);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba20
	ctx.lr = 0x822A0A00;
	// b 0x823d9238
	return;
loc_822A0A04:
	// ble cr6,0x822a0a20
	if (!cr6.gt) goto loc_822A0A20;
	// rlwimi r11,r26,1,29,30
	r11.u64 = (__builtin_rotateleft32(r26.u32, 1) & 0x6) | (r11.u64 & 0xFFFFFFFFFFFFFFF9);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba20
	ctx.lr = 0x822A0A1C;
	// b 0x823d9238
	return;
loc_822A0A20:
	// rlwinm r10,r11,0,31,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba20
	ctx.lr = 0x822A0A34;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822A0A38"))) PPC_WEAK_FUNC(sub_822A0A38);
PPC_FUNC_IMPL(__imp__sub_822A0A38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lbz r10,52(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 52);
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f0,-1964(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -1964);
	f0.f64 = double(temp.f32);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lbz r10,52(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 52);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f0,-1964(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -1964);
	f0.f64 = double(temp.f32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f6,16(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lbz r10,52(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 52);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f0,-1964(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -1964);
	f0.f64 = double(temp.f32);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f2,20(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lbz r6,52(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 52);
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// lfs f0,-1960(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1960);
	f0.f64 = double(temp.f32);
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,84(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lbz r6,52(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 52);
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// lfs f0,-1960(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1960);
	f0.f64 = double(temp.f32);
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,28(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lbz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 52);
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f0,-1960(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1960);
	f0.f64 = double(temp.f32);
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f3,32(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lbz r6,52(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 52);
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// lfs f0,-1960(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1960);
	f0.f64 = double(temp.f32);
	// extsb r4,r6
	ctx.r4.s64 = ctx.r6.s8;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f2,-16(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,36(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lbz r5,52(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 52);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// lbz r7,52(r6)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + 52);
	// rlwimi r7,r5,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// lbz r5,52(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 52);
	// addi r4,r8,1
	ctx.r4.s64 = ctx.r8.s64 + 1;
	// rlwimi r5,r6,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// lbz r10,52(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 52);
	// rlwimi r10,r5,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// stw r4,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r4.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// lbz r6,52(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 52);
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// stw r6,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A0C1C"))) PPC_WEAK_FUNC(sub_822A0C1C);
PPC_FUNC_IMPL(__imp__sub_822A0C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A0C20"))) PPC_WEAK_FUNC(sub_822A0C20);
PPC_FUNC_IMPL(__imp__sub_822A0C20) {
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
	ctx.lr = 0x822A0C28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r31,124
	ctx.r10.s64 = r31.s64 + 124;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822A0C40:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x822a0c40
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822A0C40;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r29,16(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x821c9788
	ctx.lr = 0x822A0C6C;
	sub_821C9788(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lbz r9,131(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 131);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lbz r5,133(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 133);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// extsb r11,r9
	r11.s64 = ctx.r9.s8;
	// lfs f11,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f10,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,11412(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11412);
	f0.f64 = double(temp.f32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// fmuls f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64));
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f13,1068(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 1068);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lfs f12,15364(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 15364);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f6,f9
	ctx.f6.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	// stw r8,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r8.u32);
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// fcfid f4,f7
	ctx.f4.f64 = double(ctx.f7.s64);
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmsubs f1,f3,f13,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 - ctx.f11.f64));
	// fmsubs f13,f2,f12,f10
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 - ctx.f10.f64));
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fdivs f8,f1,f9
	ctx.f8.f64 = double(float(ctx.f1.f64 / ctx.f9.f64));
	// stfs f8,148(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r3,24(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fdivs f3,f13,f4
	ctx.f3.f64 = double(float(ctx.f13.f64 / ctx.f4.f64));
	// stfs f3,152(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A0D48"))) PPC_WEAK_FUNC(sub_822A0D48);
PPC_FUNC_IMPL(__imp__sub_822A0D48) {
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
	ctx.lr = 0x822A0D50;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
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
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x8255fa80
	ctx.lr = 0x822A0D6C;
	sub_8255FA80(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r11,-1
	r11.s64 = -1;
	// addi r9,r10,21536
	ctx.r9.s64 = ctx.r10.s64 + 21536;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// addi r29,r31,124
	r29.s64 = r31.s64 + 124;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229aec8
	ctx.lr = 0x822A0D90;
	sub_8229AEC8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// cntlzw r6,r30
	ctx.r6.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// li r30,0
	r30.s64 = 0;
	// rlwinm r5,r6,30,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x8;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// stfs f31,168(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// lfs f0,21528(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21528);
	f0.f64 = double(temp.f32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stb r30,57(r31)
	PPC_STORE_U8(r31.u32 + 57, r30.u8);
	// stw r5,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r5.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82388580
	ctx.lr = 0x822A0DD0;
	sub_82388580(ctx, base);
	// lwz r28,12(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// bne cr6,0x822a0de4
	if (!cr6.eq) goto loc_822A0DE4;
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// b 0x822a0e08
	goto loc_822A0E08;
loc_822A0DE4:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822A0DEC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a0e00
	if (cr6.eq) goto loc_822A0E00;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a4fe8
	ctx.lr = 0x822A0DFC;
	sub_822A4FE8(ctx, base);
	// b 0x822a0e04
	goto loc_822A0E04;
loc_822A0E00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822A0E04:
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
loc_822A0E08:
	// stw r27,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r27.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82388580
	ctx.lr = 0x822A0E14;
	sub_82388580(ctx, base);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822a0e38
	if (cr6.eq) goto loc_822A0E38;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A0E28;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x822a4ed0
	ctx.lr = 0x822A0E30;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A0E38;
	sub_822A4DE8(ctx, base);
loc_822A0E38:
	// stfs f31,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
	// stfs f31,148(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// sth r26,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r26.u16);
	// stfs f31,152(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
	// stfs f31,92(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stb r30,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r30.u8);
	// stfs f31,104(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,108(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
	// stfs f31,156(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stb r30,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r30.u8);
	// stfs f31,164(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// stb r30,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r30.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A0E9C"))) PPC_WEAK_FUNC(sub_822A0E9C);
PPC_FUNC_IMPL(__imp__sub_822A0E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A0EA0"))) PPC_WEAK_FUNC(sub_822A0EA0);
PPC_FUNC_IMPL(__imp__sub_822A0EA0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8255fb50
	ctx.lr = 0x822A0EC4;
	sub_8255FB50(ctx, base);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8232cb28
	ctx.lr = 0x822A0ED4;
	sub_8232CB28(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a0ee4
	if (cr6.eq) goto loc_822A0EE4;
	// bl 0x822a50b8
	ctx.lr = 0x822A0EE4;
	sub_822A50B8(ctx, base);
loc_822A0EE4:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// extsh r5,r11
	ctx.r5.s64 = r11.s16;
	// bl 0x8229ff90
	ctx.lr = 0x822A0EF8;
	sub_8229FF90(ctx, base);
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

__attribute__((alias("__imp__sub_822A0F10"))) PPC_WEAK_FUNC(sub_822A0F10);
PPC_FUNC_IMPL(__imp__sub_822A0F10) {
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
	ctx.lr = 0x822A0F18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822a1050
	if (!cr6.eq) goto loc_822A1050;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4b38
	ctx.lr = 0x822A0F34;
	sub_822A4B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a0fb0
	if (cr6.eq) goto loc_822A0FB0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822a4b28
	ctx.lr = 0x822A0F50;
	sub_822A4B28(ctx, base);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A0F58;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x822a4ed0
	ctx.lr = 0x822A0F60;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A0F68;
	sub_822A4DE8(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a50c0
	ctx.lr = 0x822A0F70;
	sub_822A50C0(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r9,r11,0,17,15
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,676(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 676);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822a0fb0
	if (cr6.eq) goto loc_822A0FB0;
	// li r11,1
	r11.s64 = 1;
	// stw r29,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r29.u32);
	// stb r11,120(r3)
	PPC_STORE_U8(ctx.r3.u32 + 120, r11.u8);
	// stb r11,121(r3)
	PPC_STORE_U8(ctx.r3.u32 + 121, r11.u8);
	// stb r11,122(r3)
	PPC_STORE_U8(ctx.r3.u32 + 122, r11.u8);
	// stb r11,123(r3)
	PPC_STORE_U8(ctx.r3.u32 + 123, r11.u8);
	// bl 0x82345268
	ctx.lr = 0x822A0FB0;
	sub_82345268(ctx, base);
loc_822A0FB0:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a0ff0
	if (cr6.eq) goto loc_822A0FF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A0FD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,24(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822A0FF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A0FF0:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// ble cr6,0x822a104c
	if (!cr6.gt) goto loc_822A104C;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r10,120
	ctx.r10.s64 = ctx.r10.s64 * 120;
	// lwz r3,14560(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 14560);
	// addi r30,r11,14576
	r30.s64 = r11.s64 + 14576;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r11,r10,r30
	r11.u64 = ctx.r10.u64 + r30.u64;
	// beq cr6,0x822a1028
	if (cr6.eq) goto loc_822A1028;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x822A1024;
	sub_824656D0(ctx, base);
	// b 0x822a102c
	goto loc_822A102C;
loc_822A1028:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822A102C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a104c
	if (cr6.eq) goto loc_822A104C;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mulli r10,r11,120
	ctx.r10.s64 = r11.s64 * 120;
	// stbx r29,r10,r30
	PPC_STORE_U8(ctx.r10.u32 + r30.u32, r29.u8);
	// bl 0x822a0640
	ctx.lr = 0x822A104C;
	sub_822A0640(ctx, base);
loc_822A104C:
	// stw r29,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r29.u32);
loc_822A1050:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A1058"))) PPC_WEAK_FUNC(sub_822A1058);
PPC_FUNC_IMPL(__imp__sub_822A1058) {
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
	ctx.lr = 0x822A1060;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8232cb28
	ctx.lr = 0x822A1078;
	sub_8232CB28(ctx, base);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,148(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 148, temp.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,132(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 132, temp.u32);
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f12,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,136(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 136, temp.u32);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f11,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,140(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 140, temp.u32);
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f10,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,144(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 144, temp.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r5,r11,0,23,23
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822a10d0
	if (cr6.eq) goto loc_822A10D0;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8255ae18
	ctx.lr = 0x822A10CC;
	sub_8255AE18(ctx, base);
	// b 0x822a1110
	goto loc_822A1110;
loc_822A10D0:
	// rlwinm r11,r11,0,22,22
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a1110
	if (cr6.eq) goto loc_822A1110;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a1104
	if (cr6.eq) goto loc_822A1104;
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a1110
	if (cr6.eq) goto loc_822A1110;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8255ae20
	ctx.lr = 0x822A1100;
	sub_8255AE20(ctx, base);
	// b 0x822a1110
	goto loc_822A1110;
loc_822A1104:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82561a50
	ctx.lr = 0x822A1110;
	sub_82561A50(ctx, base);
loc_822A1110:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a1138
	if (cr6.eq) goto loc_822A1138;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822a1138
	if (!cr6.eq) goto loc_822A1138;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8232d4b8
	ctx.lr = 0x822A1138;
	sub_8232D4B8(ctx, base);
loc_822A1138:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a0210
	ctx.lr = 0x822A1140;
	sub_822A0210(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r29,1
	r29.s64 = 1;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// beq cr6,0x822a1180
	if (cr6.eq) goto loc_822A1180;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822a116c
	if (!cr6.eq) goto loc_822A116C;
	// li r11,0
	r11.s64 = 0;
loc_822A116C:
	// stb r29,244(r11)
	PPC_STORE_U8(r11.u32 + 244, r29.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822a11a4
	goto loc_822A11A4;
loc_822A1180:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822a1190
	if (!cr6.eq) goto loc_822A1190;
	// li r11,0
	r11.s64 = 0;
loc_822A1190:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,244(r11)
	PPC_STORE_U8(r11.u32 + 244, ctx.r10.u8);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
loc_822A11A4:
	// bl 0x8234a370
	ctx.lr = 0x822A11A8;
	sub_8234A370(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a11c0
	if (cr6.eq) goto loc_822A11C0;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82331858
	ctx.lr = 0x822A11C0;
	sub_82331858(ctx, base);
loc_822A11C0:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a122c
	if (cr6.eq) goto loc_822A122C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// bl 0x8233b5e0
	ctx.lr = 0x822A11DC;
	sub_8233B5E0(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822a120c
	if (!cr6.eq) goto loc_822A120C;
	// bl 0x82387b90
	ctx.lr = 0x822A11F0;
	sub_82387B90(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x8238b0c8
	ctx.lr = 0x822A1200;
	sub_8238B0C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238b128
	ctx.lr = 0x822A120C;
	sub_8238B128(ctx, base);
loc_822A120C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// beq cr6,0x822a1228
	if (cr6.eq) goto loc_822A1228;
	// stb r29,2160(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2160, r29.u8);
	// b 0x822a122c
	goto loc_822A122C;
loc_822A1228:
	// stb r29,2159(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2159, r29.u8);
loc_822A122C:
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822a1244
	if (!cr6.eq) goto loc_822A1244;
	// li r11,0
	r11.s64 = 0;
loc_822A1244:
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lbz r8,304(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 304);
	// rlwinm r10,r10,22,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// beq cr6,0x822a1294
	if (cr6.eq) goto loc_822A1294;
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822a1270
	if (!cr6.eq) goto loc_822A1270;
	// li r11,0
	r11.s64 = 0;
loc_822A1270:
	// stb r10,304(r11)
	PPC_STORE_U8(r11.u32 + 304, ctx.r10.u8);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// beq cr6,0x822a1290
	if (cr6.eq) goto loc_822A1290;
	// bl 0x8234a180
	ctx.lr = 0x822A128C;
	sub_8234A180(ctx, base);
	// b 0x822a1294
	goto loc_822A1294;
loc_822A1290:
	// bl 0x8234a280
	ctx.lr = 0x822A1294;
	sub_8234A280(ctx, base);
loc_822A1294:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a12bc
	if (cr6.eq) goto loc_822A12BC;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,668(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a12bc
	if (cr6.eq) goto loc_822A12BC;
	// bl 0x823460a0
	ctx.lr = 0x822A12BC;
	sub_823460A0(ctx, base);
loc_822A12BC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a12e4
	if (cr6.eq) goto loc_822A12E4;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,664(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a12e4
	if (cr6.eq) goto loc_822A12E4;
	// bl 0x82345988
	ctx.lr = 0x822A12E4;
	sub_82345988(ctx, base);
loc_822A12E4:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a130c
	if (cr6.eq) goto loc_822A130C;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a130c
	if (cr6.eq) goto loc_822A130C;
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x8232bc98
	ctx.lr = 0x822A130C;
	sub_8232BC98(ctx, base);
loc_822A130C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A1314"))) PPC_WEAK_FUNC(sub_822A1314);
PPC_FUNC_IMPL(__imp__sub_822A1314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A1318"))) PPC_WEAK_FUNC(sub_822A1318);
PPC_FUNC_IMPL(__imp__sub_822A1318) {
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
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a1508
	if (cr6.eq) goto loc_822A1508;
	// lbz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 128);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,15364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15364);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f9,1068(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 1068);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lbz r5,129(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 129);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f6,16(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lbz r3,130(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 130);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f2,20(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lbz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 132);
	// lbz r6,133(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 133);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// lbz r8,131(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 131);
	// lfd f1,80(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsb r3,r8
	ctx.r3.s64 = ctx.r8.s8;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f1
	ctx.f10.f64 = double(ctx.f1.s64);
	// fcfid f7,f13
	ctx.f7.f64 = double(ctx.f13.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// fmuls f0,f6,f0
	f0.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fmuls f7,f5,f9
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f9.f64));
	// fmuls f13,f8,f9
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// beq cr6,0x822a147c
	if (cr6.eq) goto loc_822A147C;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f12,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// lfs f8,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	ctx.f8.f64 = double(temp.f32);
	// beq cr6,0x822a1444
	if (cr6.eq) goto loc_822A1444;
	// lfs f10,148(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// fmadds f10,f10,f8,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f8.f64 + ctx.f12.f64));
	// bge cr6,0x822a1434
	if (!cr6.lt) goto loc_822A1434;
	// fsubs f12,f10,f13
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f10,f12,f13,f10
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// b 0x822a1444
	goto loc_822A1444;
loc_822A1434:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x822a1444
	if (!cr6.gt) goto loc_822A1444;
	// fsubs f12,f10,f13
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f10,f12,f10,f13
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? ctx.f10.f64 : ctx.f13.f64;
loc_822A1444:
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x822a147c
	if (cr6.eq) goto loc_822A147C;
	// lfs f12,152(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmadds f11,f12,f8,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f13.f64));
	// bge cr6,0x822a146c
	if (!cr6.lt) goto loc_822A146C;
	// fsubs f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f11,f13,f0,f11
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// b 0x822a147c
	goto loc_822A147C;
loc_822A146C:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822a147c
	if (!cr6.gt) goto loc_822A147C;
	// fsubs f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f11,f13,f11,f0
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
loc_822A147C:
	// stfs f7,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stfs f10,24(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f11,88(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lbz r11,134(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 134);
	// sth r11,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r11.u16);
	// lbz r10,135(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 135);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f9
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// stfs f11,32(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lbz r7,136(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// stfs f6,36(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lbz r4,137(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 137);
	// stw r4,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r4.u32);
	// beq cr6,0x822a1500
	if (cr6.eq) goto loc_822A1500;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lbz r11,138(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 138);
	// rlwinm r4,r11,0,28,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// lwz r10,592(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 592);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x822a1500
	if (cr6.eq) goto loc_822A1500;
	// bl 0x8232c788
	ctx.lr = 0x822A1500;
	sub_8232C788(ctx, base);
loc_822A1500:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a1058
	ctx.lr = 0x822A1508;
	sub_822A1058(ctx, base);
loc_822A1508:
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

__attribute__((alias("__imp__sub_822A151C"))) PPC_WEAK_FUNC(sub_822A151C);
PPC_FUNC_IMPL(__imp__sub_822A151C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A1520"))) PPC_WEAK_FUNC(sub_822A1520);
PPC_FUNC_IMPL(__imp__sub_822A1520) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d0
	ctx.lr = 0x822A1534;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f1,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8255ff78
	ctx.lr = 0x822A154C;
	sub_8255FF78(ctx, base);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f29,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f29.f64 = double(temp.f32);
	// fmr f27,f1
	f27.f64 = ctx.f1.f64;
	// stfs f29,80(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	f0.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f28,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f28.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x822a15b8
	if (!cr6.gt) goto loc_822A15B8;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,128(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lfs f0,224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	f0.f64 = double(temp.f32);
	// lwz r10,28(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lfs f13,276(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f10,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fdivs f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 / f0.f64));
loc_822A15B8:
	// bl 0x823dca68
	ctx.lr = 0x822A15BC;
	sub_823DCA68(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// lwz r6,92(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// lfs f26,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f26.f64 = double(temp.f32);
	// lfs f10,568(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 568);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,76(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,80(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f5,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f5.f64 = double(temp.f32);
	// lwz r5,136(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 136);
	// fsubs f6,f8,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fcmpu cr6,f8,f31
	cr6.compare(ctx.f8.f64, f31.f64);
	// fsel f4,f11,f12,f13
	ctx.f4.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// lfs f3,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	ctx.f3.f64 = double(temp.f32);
	// fdivs f2,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 / ctx.f3.f64));
	// fmadds f13,f4,f6,f9
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f6.f64 + ctx.f9.f64));
	// fsubs f1,f2,f26
	ctx.f1.f64 = double(float(ctx.f2.f64 - f26.f64));
	// fsel f0,f1,f2,f26
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f26.f64;
	// fsubs f12,f0,f28
	ctx.f12.f64 = double(float(f0.f64 - f28.f64));
	// fsel f11,f12,f28,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f28.f64 : f0.f64;
	// fmuls f12,f11,f5
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f5.f64));
	// ble cr6,0x822a1638
	if (!cr6.gt) goto loc_822A1638;
	// lfs f10,80(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// b 0x822a163c
	goto loc_822A163C;
loc_822A1638:
	// lfs f10,76(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 76);
	ctx.f10.f64 = double(temp.f32);
loc_822A163C:
	// lbz r10,101(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a1654
	if (cr6.eq) goto loc_822A1654;
	// lfs f13,76(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fmr f12,f31
	ctx.f12.f64 = f31.f64;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
loc_822A1654:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f9,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// lfs f11,21516(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21516);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f8,f9,f11,f28
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + f28.f64));
	// fmuls f2,f8,f13
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f13,f8,f10
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// bgt cr6,0x822a1688
	if (cr6.gt) goto loc_822A1688;
	// fcmpu cr6,f30,f12
	cr6.compare(f30.f64, ctx.f12.f64);
	// bgt cr6,0x822a1688
	if (cr6.gt) goto loc_822A1688;
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x822a16a0
	if (!cr6.gt) goto loc_822A16A0;
loc_822A1688:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x822a16c0
	if (cr6.lt) goto loc_822A16C0;
	// fcmpu cr6,f30,f12
	cr6.compare(f30.f64, ctx.f12.f64);
	// blt cr6,0x822a16c0
	if (cr6.lt) goto loc_822A16C0;
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// blt cr6,0x822a16c0
	if (cr6.lt) goto loc_822A16C0;
loc_822A16A0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fmuls f1,f27,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f27.f64 * f30.f64));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f3,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x822A16B8;
	sub_821CE490(ctx, base);
	// lfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
	// b 0x822a1708
	goto loc_822A1708;
loc_822A16C0:
	// fcmpu cr6,f29,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f29.f64, f30.f64);
	// bge cr6,0x822a16e4
	if (!cr6.lt) goto loc_822A16E4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f29,f0,f13,f29
	f29.f64 = double(float(f0.f64 * ctx.f13.f64 + f29.f64));
	// fcmpu cr6,f29,f30
	cr6.compare(f29.f64, f30.f64);
	// ble cr6,0x822a1708
	if (!cr6.gt) goto loc_822A1708;
	// b 0x822a1704
	goto loc_822A1704;
loc_822A16E4:
	// fcmpu cr6,f29,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f29.f64, f30.f64);
	// ble cr6,0x822a1708
	if (!cr6.gt) goto loc_822A1708;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fnmsubs f29,f0,f13,f29
	f29.f64 = double(float(-(f0.f64 * ctx.f13.f64 - f29.f64)));
	// fcmpu cr6,f29,f30
	cr6.compare(f29.f64, f30.f64);
	// bge cr6,0x822a1708
	if (!cr6.lt) goto loc_822A1708;
loc_822A1704:
	// fmr f29,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = f30.f64;
loc_822A1708:
	// fsubs f0,f29,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - f26.f64));
	// fsel f13,f0,f29,f26
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : f26.f64;
	// fsubs f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 - f28.f64));
	// fsel f1,f12,f28,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f28.f64 : ctx.f13.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba1c
	ctx.lr = 0x822A1724;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A1734"))) PPC_WEAK_FUNC(sub_822A1734);
PPC_FUNC_IMPL(__imp__sub_822A1734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A1738"))) PPC_WEAK_FUNC(sub_822A1738);
PPC_FUNC_IMPL(__imp__sub_822A1738) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822A1740;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x822a1b64
	if (cr6.eq) goto loc_822A1B64;
	// lwz r28,76(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x822a1b64
	if (cr6.eq) goto loc_822A1B64;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r26,14560(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 14560);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824656d0
	ctx.lr = 0x822A177C;
	sub_824656D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a1b64
	if (cr6.eq) goto loc_822A1B64;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822a1b4c
	if (!cr6.eq) goto loc_822A1B4C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r28,120
	ctx.r10.s64 = r28.s64 * 120;
	// addi r9,r11,14576
	ctx.r9.s64 = r11.s64 + 14576;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a1b4c
	if (cr6.eq) goto loc_822A1B4C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a1b4c
	if (!cr6.eq) goto loc_822A1B4C;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822a5948
	ctx.lr = 0x822A17CC;
	sub_822A5948(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a17ec
	if (cr6.eq) goto loc_822A17EC;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822a5948
	ctx.lr = 0x822A17E0;
	sub_822A5948(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lbz r11,101(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 101);
	// b 0x822a17f0
	goto loc_822A17F0;
loc_822A17EC:
	// li r11,0
	r11.s64 = 0;
loc_822A17F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a1b64
	if (!cr6.eq) goto loc_822A1B64;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,128(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lfs f13,14992(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,276(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lfs f10,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f10,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f31,f2,f13
	f31.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822a1860
	if (!cr6.gt) goto loc_822A1860;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_822A1860:
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f13,540(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 540);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 428);
	ctx.f12.f64 = double(temp.f32);
	// beq cr6,0x822a18a0
	if (cr6.eq) goto loc_822A18A0;
	// lfs f11,540(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 540);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// lfs f9,428(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 428);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fdivs f8,f11,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 / ctx.f9.f64));
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fadds f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f8.f64));
	// fmuls f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// b 0x822a18a4
	goto loc_822A18A4;
loc_822A18A0:
	// fdivs f13,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
loc_822A18A4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,-1
	r29.s64 = -1;
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// blt cr6,0x822a18bc
	if (cr6.lt) goto loc_822A18BC;
	// li r29,1
	r29.s64 = 1;
loc_822A18BC:
	// fabs f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lfs f2,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f2.f64 = double(temp.f32);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f1,f10,f0,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// bl 0x823dc480
	ctx.lr = 0x822A18DC;
	sub_823DC480(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f8,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// lwz r8,412(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// fmuls f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// lbz r7,529(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 529);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// fmuls f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bne cr6,0x822a1930
	if (!cr6.eq) goto loc_822A1930;
	// lwz r11,420(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a192c
	if (cr6.eq) goto loc_822A192C;
	// lbz r11,529(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 529);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a1930
	if (!cr6.eq) goto loc_822A1930;
loc_822A192C:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822A1930:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a1958
	if (cr6.eq) goto loc_822A1958;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,164(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// b 0x822a195c
	goto loc_822A195C;
loc_822A1958:
	// stfs f30,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
loc_822A195C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822a1978
	if (cr6.gt) goto loc_822A1978;
	// li r11,0
	r11.s64 = 0;
loc_822A1978:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// lwz r11,-12640(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lbz r9,6(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a1b24
	if (!cr6.eq) goto loc_822A1B24;
	// lbz r11,160(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a19cc
	if (cr6.eq) goto loc_822A19CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f0,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f0.f64 = double(temp.f32);
	// lfs f13,21588(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21588);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82465dd0
	ctx.lr = 0x822A19CC;
	sub_82465DD0(ctx, base);
loc_822A19CC:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r7,90
	ctx.r7.s64 = 90;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f0,56(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f13,60(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82465918
	ctx.lr = 0x822A1A00;
	sub_82465918(ctx, base);
	// mullw r5,r30,r29
	ctx.r5.s64 = int64_t(r30.s32) * int64_t(r29.s32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824659b8
	ctx.lr = 0x822A1A10;
	sub_824659B8(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f9,68(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f31,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * f31.f64 + ctx.f9.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82465a68
	ctx.lr = 0x822A1A3C;
	sub_82465A68(ctx, base);
	// clrlwi r9,r27,24
	ctx.r9.u64 = r27.u32 & 0xFF;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// beq cr6,0x822a1a58
	if (cr6.eq) goto loc_822A1A58;
	// bl 0x82465d60
	ctx.lr = 0x822A1A54;
	sub_82465D60(ctx, base);
	// b 0x822a1a5c
	goto loc_822A1A5C;
loc_822A1A58:
	// bl 0x82465d98
	ctx.lr = 0x822A1A5C;
	sub_82465D98(ctx, base);
loc_822A1A5C:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r10,412(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// lwz r8,464(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 464);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a1b24
	if (cr6.eq) goto loc_822A1B24;
	// lfs f0,436(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 436);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822a1ac0
	if (cr6.eq) goto loc_822A1AC0;
	// lhz r10,56(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 56);
	// lwz r11,420(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a1ac0
	if (cr6.eq) goto loc_822A1AC0;
	// lfs f0,436(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 436);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822a1ac0
	if (cr6.eq) goto loc_822A1AC0;
	// lwz r11,464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 464);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a1ac0
	if (cr6.eq) goto loc_822A1AC0;
	// lhz r11,56(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 56);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bgt cr6,0x822a1ac0
	if (cr6.gt) goto loc_822A1AC0;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_822A1AC0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,20(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f0,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822a1ae4
	if (!cr6.lt) goto loc_822A1AE4;
	// bl 0x82465cb8
	ctx.lr = 0x822A1AE0;
	sub_82465CB8(ctx, base);
	// b 0x822a1b24
	goto loc_822A1B24;
loc_822A1AE4:
	// lhz r11,56(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 56);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x822a1af8
	if (!cr6.eq) goto loc_822A1AF8;
	// bl 0x82465cb8
	ctx.lr = 0x822A1AF4;
	sub_82465CB8(ctx, base);
	// b 0x822a1b24
	goto loc_822A1B24;
loc_822A1AF8:
	// mulli r11,r9,30
	r11.s64 = ctx.r9.s64 * 30;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82465c40
	ctx.lr = 0x822A1B24;
	sub_82465C40(ctx, base);
loc_822A1B24:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a1b64
	if (cr6.eq) goto loc_822A1B64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82465d28
	ctx.lr = 0x822A1B3C;
	sub_82465D28(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_822A1B4C:
	// li r7,70
	ctx.r7.s64 = 70;
	// li r6,70
	ctx.r6.s64 = 70;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82465918
	ctx.lr = 0x822A1B64;
	sub_82465918(ctx, base);
loc_822A1B64:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A1B74"))) PPC_WEAK_FUNC(sub_822A1B74);
PPC_FUNC_IMPL(__imp__sub_822A1B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A1B78"))) PPC_WEAK_FUNC(sub_822A1B78);
PPC_FUNC_IMPL(__imp__sub_822A1B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f13,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// fmadds f10,f0,f13,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f11,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,-12348(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12348);
	// lfs f0,21524(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21524);
	f0.f64 = double(temp.f32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// fsel f9,f10,f10,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsel f7,f8,f13,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lbz r10,-9(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stb r10,52(r4)
	PPC_STORE_U8(ctx.r4.u32 + 52, ctx.r10.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f10,-1964(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -1964);
	ctx.f10.f64 = double(temp.f32);
	// lfs f2,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f2,f13,f12
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fsel f9,f1,f1,f11
	ctx.f9.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : ctx.f11.f64;
	// fmuls f8,f3,f10
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// stfs f8,12(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// fsubs f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsel f6,f7,f13,f9
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f5.u64);
	// lbz r10,-9(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stb r10,52(r4)
	PPC_STORE_U8(ctx.r4.u32 + 52, ctx.r10.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f2,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f10,-1964(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -1964);
	ctx.f10.f64 = double(temp.f32);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f4,-16(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// fmadds f1,f2,f13,f12
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f12.f64));
	// frsp f9,f3
	ctx.f9.f64 = double(float(ctx.f3.f64));
	// fsel f11,f1,f1,f11
	ctx.f11.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : ctx.f11.f64;
	// fmuls f7,f9,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// stfs f7,16(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// fsubs f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsel f6,f8,f13,f11
	ctx.f6.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// lfs f13,21520(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 21520);
	ctx.f13.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f5.u64);
	// lbz r10,-9(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stb r10,52(r4)
	PPC_STORE_U8(ctx.r4.u32 + 52, ctx.r10.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lfs f2,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,-1964(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -1964);
	ctx.f11.f64 = double(temp.f32);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f4,-16(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// fmadds f1,f2,f0,f12
	ctx.f1.f64 = double(float(ctx.f2.f64 * f0.f64 + ctx.f12.f64));
	// frsp f10,f3
	ctx.f10.f64 = double(float(ctx.f3.f64));
	// fsubs f9,f1,f13
	ctx.f9.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fmuls f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fsel f7,f9,f1,f13
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f1.f64 : ctx.f13.f64;
	// stfs f8,20(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// fsubs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 - f0.f64));
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// fsel f5,f6,f0,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : ctx.f7.f64;
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f4.u64);
	// lbz r10,-9(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// stb r10,52(r5)
	PPC_STORE_U8(ctx.r5.u32 + 52, ctx.r10.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// lfs f1,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// lfs f11,-1960(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1960);
	ctx.f11.f64 = double(temp.f32);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f3,-16(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// fmadds f10,f1,f0,f12
	ctx.f10.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f12.f64));
	// frsp f8,f2
	ctx.f8.f64 = double(float(ctx.f2.f64));
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fmuls f6,f8,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// stfs f6,84(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// fsel f7,f9,f10,f13
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f13.f64;
	// fsubs f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsel f4,f5,f0,f7
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? f0.f64 : ctx.f7.f64;
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f3.u64);
	// lbz r5,-9(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// extsb r9,r5
	ctx.r9.s64 = ctx.r5.s8;
	// stb r5,52(r6)
	PPC_STORE_U8(ctx.r6.u32 + 52, ctx.r5.u8);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f2,-16(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// lfs f10,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f7,f10,f0,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f12.f64));
	// lfs f11,-1960(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1960);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// frsp f9,f1
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// fsel f5,f6,f7,f13
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f7.f64 : ctx.f13.f64;
	// fmuls f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfs f8,28(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// fsubs f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f3,f4,f0,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f2.u64);
	// lbz r6,-9(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// extsb r10,r6
	ctx.r10.s64 = ctx.r6.s8;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// stb r6,52(r7)
	PPC_STORE_U8(ctx.r7.u32 + 52, ctx.r6.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// lfs f10,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f0,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f12.f64));
	// lfs f12,-1960(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1960);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fcfid f11,f1
	ctx.f11.f64 = double(ctx.f1.s64);
	// fsel f6,f8,f9,f13
	ctx.f6.f64 = ctx.f8.f64 >= 0.0 ? ctx.f9.f64 : ctx.f13.f64;
	// frsp f7,f11
	ctx.f7.f64 = double(float(ctx.f11.f64));
	// fsubs f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fmuls f5,f7,f12
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f5,32(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// fsel f3,f4,f0,f6
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f2.u64);
	// lbz r7,-9(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// stb r7,52(r8)
	PPC_STORE_U8(ctx.r8.u32 + 52, ctx.r7.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lfs f0,-1960(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1960);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,36(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r7,r9,8,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// rlwinm r6,r9,16,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF;
	// stb r7,52(r8)
	PPC_STORE_U8(ctx.r8.u32 + 52, ctx.r7.u8);
	// rlwinm r5,r9,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stb r6,52(r4)
	PPC_STORE_U8(ctx.r4.u32 + 52, ctx.r6.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stb r5,52(r8)
	PPC_STORE_U8(ctx.r8.u32 + 52, ctx.r5.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stb r9,52(r7)
	PPC_STORE_U8(ctx.r7.u32 + 52, ctx.r9.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r5,80(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stb r5,52(r6)
	PPC_STORE_U8(ctx.r6.u32 + 52, ctx.r5.u8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// stw r3,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A1EA8"))) PPC_WEAK_FUNC(sub_822A1EA8);
PPC_FUNC_IMPL(__imp__sub_822A1EA8) {
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
	// bl 0x82387a18
	ctx.lr = 0x822A1EC0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a20b8
	if (cr6.eq) goto loc_822A20B8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r31,124
	r11.s64 = r31.s64 + 124;
	// lfs f0,15360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,21524(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21524);
	ctx.f13.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,128(r31)
	PPC_STORE_U8(r31.u32 + 128, ctx.r8.u8);
	// lfs f10,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,129(r31)
	PPC_STORE_U8(r31.u32 + 129, ctx.r6.u8);
	// lfs f7,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,130(r31)
	PPC_STORE_U8(r31.u32 + 130, ctx.r5.u8);
	// lfs f4,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,131(r31)
	PPC_STORE_U8(r31.u32 + 131, ctx.r4.u8);
	// lfs f1,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r3.u8);
	// lfs f10,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lbz r10,87(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r10,133(r31)
	PPC_STORE_U8(r31.u32 + 133, ctx.r10.u8);
	// lfs f7,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,135(r31)
	PPC_STORE_U8(r31.u32 + 135, ctx.r9.u8);
	// lfs f4,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r8.u8);
	// lhz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// stb r6,134(r31)
	PPC_STORE_U8(r31.u32 + 134, ctx.r6.u8);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stb r4,137(r31)
	PPC_STORE_U8(r31.u32 + 137, ctx.r4.u8);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// stb r9,138(r31)
	PPC_STORE_U8(r31.u32 + 138, ctx.r9.u8);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// sth r6,124(r31)
	PPC_STORE_U16(r31.u32 + 124, ctx.r6.u16);
	// stb r7,126(r31)
	PPC_STORE_U8(r31.u32 + 126, ctx.r7.u8);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,676(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 676);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a2034
	if (cr6.eq) goto loc_822A2034;
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwz r8,64(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// lwz r10,56(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// cntlzw r4,r6
	ctx.r4.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r3,r5
	ctx.r3.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// rlwinm r6,r3,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r8,r4,28,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0x2;
	// cntlzw r3,r5
	ctx.r3.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// or r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 | ctx.r6.u64;
	// rlwinm r8,r3,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r9,r4,1,24,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFE;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// cntlzw r4,r6
	ctx.r4.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r3,r5,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFE;
	// rlwinm r10,r4,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// or r9,r3,r10
	ctx.r9.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
loc_822A2034:
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,672(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 672);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a207c
	if (cr6.eq) goto loc_822A207C;
	// lbz r10,13(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 13);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r6,31,27,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x10;
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// stb r4,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r4.u8);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,672(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// lbz r8,14(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 14);
	// rotlwi r6,r8,5
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 5);
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// stb r5,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r5.u8);
loc_822A207C:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// stb r7,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r7.u8);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a20a8
	if (cr6.eq) goto loc_822A20A8;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,68(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a20a8
	if (cr6.eq) goto loc_822A20A8;
	// lwz r10,136(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// stb r10,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r10.u8);
loc_822A20A8:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// bl 0x822a1318
	ctx.lr = 0x822A20B8;
	sub_822A1318(ctx, base);
loc_822A20B8:
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

__attribute__((alias("__imp__sub_822A20CC"))) PPC_WEAK_FUNC(sub_822A20CC);
PPC_FUNC_IMPL(__imp__sub_822A20CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A20D0"))) PPC_WEAK_FUNC(sub_822A20D0);
PPC_FUNC_IMPL(__imp__sub_822A20D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387a18
	ctx.lr = 0x822A20EC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a22e4
	if (cr6.eq) goto loc_822A22E4;
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a22e4
	if (cr6.eq) goto loc_822A22E4;
	// bl 0x821c9788
	ctx.lr = 0x822A2108;
	sub_821C9788(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x822a22bc
	if (!cr6.lt) goto loc_822A22BC;
	// lhz r11,124(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 124);
	// addi r30,r31,124
	r30.s64 = r31.s64 + 124;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// beq cr6,0x822a215c
	if (cr6.eq) goto loc_822A215C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a215c
	if (cr6.eq) goto loc_822A215C;
	// lbz r10,3(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// stw r10,136(r11)
	PPC_STORE_U32(r11.u32 + 136, ctx.r10.u32);
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r7,r7,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,3(r30)
	PPC_STORE_U8(r30.u32 + 3, ctx.r9.u8);
	// sth r7,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r7.u16);
loc_822A215C:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a2254
	if (cr6.eq) goto loc_822A2254;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r8,r11,0,0,16
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a221c
	if (cr6.eq) goto loc_822A221C;
	// lbz r9,2(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// stb r11,120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 120, r11.u8);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r9,r6,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stw r5,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, ctx.r5.u32);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lbz r3,2(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// rlwinm r10,r3,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// lwz r8,676(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 676);
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// stb r11,121(r8)
	PPC_STORE_U8(ctx.r8.u32 + 121, r11.u8);
	// subfe r7,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r7,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, ctx.r6.u32);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lbz r4,2(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// rlwinm r3,r4,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4;
	// lwz r9,676(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 676);
	// subfic r10,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r3.s64;
	// stb r11,122(r9)
	PPC_STORE_U8(ctx.r9.u32 + 122, r11.u8);
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r8,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r7.u32);
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lbz r5,2(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// rlwinm r4,r5,0,28,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x8;
	// subfic r3,r4,0
	xer.ca = ctx.r4.u32 <= 0;
	ctx.r3.s64 = 0 - ctx.r4.s64;
	// lwz r10,676(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 676);
	// stb r11,123(r10)
	PPC_STORE_U8(ctx.r10.u32 + 123, r11.u8);
	// subfe r9,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r3.u64 + ctx.r3.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r8.u32);
	// b 0x822a2254
	goto loc_822A2254;
loc_822A221C:
	// stb r11,120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 120, r11.u8);
	// stw r9,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, ctx.r9.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r8,676(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 676);
	// stw r9,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, ctx.r9.u32);
	// stb r11,121(r8)
	PPC_STORE_U8(ctx.r8.u32 + 121, r11.u8);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r6,676(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 676);
	// stw r9,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, ctx.r9.u32);
	// stb r11,122(r6)
	PPC_STORE_U8(ctx.r6.u32 + 122, r11.u8);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r4,676(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 676);
	// stw r9,68(r4)
	PPC_STORE_U32(ctx.r4.u32 + 68, ctx.r9.u32);
	// stb r11,123(r4)
	PPC_STORE_U8(ctx.r4.u32 + 123, r11.u8);
loc_822A2254:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r3,672(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 672);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a22b0
	if (cr6.eq) goto loc_822A22B0;
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a22a4
	if (cr6.eq) goto loc_822A22A4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a22b0
	if (!cr6.eq) goto loc_822A22B0;
	// bl 0x8234ff70
	ctx.lr = 0x822A2284;
	sub_8234FF70(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lbz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r10,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// lwz r8,672(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 672);
	// stb r9,14(r8)
	PPC_STORE_U8(ctx.r8.u32 + 14, ctx.r9.u8);
	// bl 0x822a1318
	ctx.lr = 0x822A22A0;
	sub_822A1318(ctx, base);
	// b 0x822a22e4
	goto loc_822A22E4;
loc_822A22A4:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822a22b0
	if (!cr6.eq) goto loc_822A22B0;
	// bl 0x8234ff40
	ctx.lr = 0x822A22B0;
	sub_8234FF40(ctx, base);
loc_822A22B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a1318
	ctx.lr = 0x822A22B8;
	sub_822A1318(ctx, base);
	// b 0x822a22e4
	goto loc_822A22E4;
loc_822A22BC:
	// bl 0x821c9788
	ctx.lr = 0x822A22C0;
	sub_821C9788(ctx, base);
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// bl 0x8229aec8
	ctx.lr = 0x822A22C8;
	sub_8229AEC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a1318
	ctx.lr = 0x822A22D0;
	sub_822A1318(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A22E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A22E4:
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

__attribute__((alias("__imp__sub_822A22FC"))) PPC_WEAK_FUNC(sub_822A22FC);
PPC_FUNC_IMPL(__imp__sub_822A22FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A2300"))) PPC_WEAK_FUNC(sub_822A2300);
PPC_FUNC_IMPL(__imp__sub_822A2300) {
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
	ctx.lr = 0x822A2308;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,21536
	ctx.r10.s64 = r11.s64 + 21536;
	// lwz r30,116(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a2344
	if (cr6.eq) goto loc_822A2344;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4b48
	ctx.lr = 0x822A2334;
	sub_822A4B48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822A233C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
loc_822A2344:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8255faf8
	ctx.lr = 0x822A234C;
	sub_8255FAF8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a2364
	if (cr6.eq) goto loc_822A2364;
	// bl 0x82130588
	ctx.lr = 0x822A2360;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822A2364:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A236C"))) PPC_WEAK_FUNC(sub_822A236C);
PPC_FUNC_IMPL(__imp__sub_822A236C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A2370"))) PPC_WEAK_FUNC(sub_822A2370);
PPC_FUNC_IMPL(__imp__sub_822A2370) {
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
	ctx.lr = 0x822A2378;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822a25d4
	if (!cr6.eq) goto loc_822A25D4;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r29,r11,14576
	r29.s64 = r11.s64 + 14576;
	// addi r28,r9,21384
	r28.s64 = ctx.r9.s64 + 21384;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// ble cr6,0x822a2454
	if (!cr6.gt) goto loc_822A2454;
	// lwz r11,14560(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14560);
	// mulli r10,r10,120
	ctx.r10.s64 = ctx.r10.s64 * 120;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// beq cr6,0x822a23d4
	if (cr6.eq) goto loc_822A23D4;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x822A23CC;
	sub_824656D0(ctx, base);
	// lwz r11,14560(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14560);
	// b 0x822a23d8
	goto loc_822A23D8;
loc_822A23D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A23D8:
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a2458
	if (cr6.eq) goto loc_822A2458;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x8229ff10
	ctx.lr = 0x822A23F4;
	sub_8229FF10(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a2454
	if (cr6.eq) goto loc_822A2454;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x822a24e4
	if (cr6.eq) goto loc_822A24E4;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a244c
	if (cr6.eq) goto loc_822A244C;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A2430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822A244C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A244C:
	// li r11,2
	r11.s64 = 2;
	// b 0x822a24e0
	goto loc_822A24E0;
loc_822A2454:
	// lwz r11,14560(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 14560);
loc_822A2458:
	// lhz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// addi r9,r28,44
	ctx.r9.s64 = r28.s64 + 44;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// rlwinm r7,r8,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822a24e4
	if (cr6.eq) goto loc_822A24E4;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x822a24e4
	if (cr6.eq) goto loc_822A24E4;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// ble cr6,0x822a24dc
	if (!cr6.gt) goto loc_822A24DC;
	// mulli r10,r10,120
	ctx.r10.s64 = ctx.r10.s64 * 120;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// beq cr6,0x822a24ac
	if (cr6.eq) goto loc_822A24AC;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x822A24A8;
	sub_824656D0(ctx, base);
	// b 0x822a24b0
	goto loc_822A24B0;
loc_822A24AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A24B0:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a24dc
	if (cr6.eq) goto loc_822A24DC;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82465490
	ctx.lr = 0x822A24CC;
	sub_82465490(ctx, base);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// mulli r8,r9,120
	ctx.r8.s64 = ctx.r9.s64 * 120;
	// stbx r10,r8,r29
	PPC_STORE_U8(ctx.r8.u32 + r29.u32, ctx.r10.u8);
loc_822A24DC:
	// li r11,1
	r11.s64 = 1;
loc_822A24E0:
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
loc_822A24E4:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A24EC;
	sub_82388580(ctx, base);
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82387b90
	ctx.lr = 0x822A24F4;
	sub_82387B90(ctx, base);
	// addi r11,r30,297
	r11.s64 = r30.s64 + 297;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// lwzx r8,r9,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r30,r6,1
	r30.u64 = ctx.r6.u64 ^ 1;
	// bne cr6,0x822a2550
	if (!cr6.eq) goto loc_822A2550;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x822a2550
	if (!cr6.gt) goto loc_822A2550;
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// stbx r30,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, r30.u8);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a25a8
	if (cr6.eq) goto loc_822A25A8;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x822a25a4
	goto loc_822A25A4;
loc_822A2550:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x822a25a8
	if (!cr6.eq) goto loc_822A25A8;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// addi r9,r28,44
	ctx.r9.s64 = r28.s64 + 44;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lbzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822a25a8
	if (cr6.eq) goto loc_822A25A8;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a25a8
	if (cr6.eq) goto loc_822A25A8;
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + r28.u64;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x825ae378
	ctx.lr = 0x822A258C;
	sub_825AE378(ctx, base);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822A25A4:
	// bctrl 
	ctx.lr = 0x822A25A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A25A8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lwz r11,-12348(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a25d4
	if (cr6.eq) goto loc_822A25D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a0f10
	ctx.lr = 0x822A25D4;
	sub_822A0F10(ctx, base);
loc_822A25D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A25DC"))) PPC_WEAK_FUNC(sub_822A25DC);
PPC_FUNC_IMPL(__imp__sub_822A25DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A25E0"))) PPC_WEAK_FUNC(sub_822A25E0);
PPC_FUNC_IMPL(__imp__sub_822A25E0) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822A25E8;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d4
	ctx.lr = 0x822A25F0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f13,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f27,100(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	f27.f64 = double(temp.f32);
	// lfs f29,104(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	f29.f64 = double(temp.f32);
	// lfs f31,224(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	f31.f64 = double(temp.f32);
	// fsubs f12,f31,f13
	ctx.f12.f64 = double(float(f31.f64 - ctx.f13.f64));
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// stfs f11,108(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lwz r3,17268(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822A2638;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a8108
	ctx.lr = 0x822A2640;
	sub_822A8108(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r3,640(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 640);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f28,-13028(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13028);
	f28.f64 = double(temp.f32);
	// beq cr6,0x822a266c
	if (cr6.eq) goto loc_822A266C;
	// bl 0x82245340
	ctx.lr = 0x822A2658;
	sub_82245340(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a266c
	if (cr6.eq) goto loc_822A266C;
	// bl 0x822447b8
	ctx.lr = 0x822A2664;
	sub_822447B8(ctx, base);
	// fmuls f0,f1,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f28.f64));
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
loc_822A266C:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822A2684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// li r29,1
	r29.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f30,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x822a275c
	if (cr6.eq) goto loc_822A275C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8255ade0
	ctx.lr = 0x822A26AC;
	sub_8255ADE0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822a275c
	if (!cr6.gt) goto loc_822A275C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,664(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// lbz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822a275c
	if (!cr6.eq) goto loc_822A275C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f12,f30
	cr6.compare(ctx.f12.f64, f30.f64);
	// bne cr6,0x822a275c
	if (!cr6.eq) goto loc_822A275C;
	// lfs f12,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f30
	cr6.compare(ctx.f12.f64, f30.f64);
	// ble cr6,0x822a275c
	if (!cr6.gt) goto loc_822A275C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,21600(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21600);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822a275c
	if (!cr6.gt) goto loc_822A275C;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	f0.f64 = double(temp.f32);
	// lfs f13,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822a274c
	if (!cr6.lt) goto loc_822A274C;
	// lfs f0,108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// fmsubs f13,f0,f28,f12
	ctx.f13.f64 = double(float(f0.f64 * f28.f64 - ctx.f12.f64));
	// lfs f11,108(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fabs f9,f13
	ctx.f9.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f10
	cr6.compare(ctx.f9.f64, ctx.f10.f64);
	// bge cr6,0x822a2760
	if (!cr6.lt) goto loc_822A2760;
	// stb r29,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r29.u8);
	// b 0x822a2760
	goto loc_822A2760;
loc_822A274C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822a2760
	if (!cr6.gt) goto loc_822A2760;
loc_822A275C:
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
loc_822A2760:
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// stb r30,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r30.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a2894
	if (cr6.eq) goto loc_822A2894;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x822a2828
	if (!cr6.gt) goto loc_822A2828;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bgt cr6,0x822a2828
	if (cr6.gt) goto loc_822A2828;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-7912(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7912);
	f0.f64 = double(temp.f32);
	// fnmsubs f0,f13,f0,f12
	f0.f64 = double(float(-(ctx.f13.f64 * f0.f64 - ctx.f12.f64)));
	// lfs f12,21596(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21596);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fabs f11,f0
	ctx.f11.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fsel f9,f10,f10,f30
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f30.f64;
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsel f13,f8,f13,f9
	ctx.f13.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// ble cr6,0x822a27e4
	if (!cr6.gt) goto loc_822A27E4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stb r29,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r29.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-12084(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f0.f64 = double(temp.f32);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f0,f13,f0,f12
	f0.f64 = double(float(-(ctx.f13.f64 * f0.f64 - ctx.f12.f64)));
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a2894
	goto loc_822A2894;
loc_822A27E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,25488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 25488);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822a2814
	if (!cr6.lt) goto loc_822A2814;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stb r29,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r29.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,21592(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21592);
	f0.f64 = double(temp.f32);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f13,f0,f12
	f0.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a2894
	goto loc_822A2894;
loc_822A2814:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r29,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r29.u8);
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a2894
	goto loc_822A2894;
loc_822A2828:
	// fcmpu cr6,f0,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x822a2854
	if (cr6.gt) goto loc_822A2854;
	// fdivs f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 / f27.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fsel f11,f12,f12,f30
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f30.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f9,f10,f0,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// stfs f9,12(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a2894
	goto loc_822A2894;
loc_822A2854:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822a2894
	if (!cr6.gt) goto loc_822A2894;
	// fsubs f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 - f29.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fsubs f11,f13,f29
	ctx.f11.f64 = double(float(ctx.f13.f64 - f29.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fdivs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fadds f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 + f0.f64));
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f6,f7,f8,f0
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsel f4,f5,f13,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f6.f64;
	// stfs f4,12(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_822A2894:
	// lbz r11,102(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 102);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a28ac
	if (cr6.eq) goto loc_822A28AC;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,19,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFDFFF;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A28AC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba20
	ctx.lr = 0x822A28B8;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A28BC"))) PPC_WEAK_FUNC(sub_822A28BC);
PPC_FUNC_IMPL(__imp__sub_822A28BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A28C0"))) PPC_WEAK_FUNC(sub_822A28C0);
PPC_FUNC_IMPL(__imp__sub_822A28C0) {
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
	// bl 0x8255fb08
	ctx.lr = 0x822A28DC;
	sub_8255FB08(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r30,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r30.u8);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stb r30,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r30.u8);
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a2960
	if (cr6.eq) goto loc_822A2960;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822a4b28
	ctx.lr = 0x822A2940;
	sub_822A4B28(ctx, base);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A2948;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x822a4ed0
	ctx.lr = 0x822A2950;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A2958;
	sub_822A4DE8(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a50c0
	ctx.lr = 0x822A2960;
	sub_822A50C0(ctx, base);
loc_822A2960:
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a2370
	ctx.lr = 0x822A296C;
	sub_822A2370(ctx, base);
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

__attribute__((alias("__imp__sub_822A2984"))) PPC_WEAK_FUNC(sub_822A2984);
PPC_FUNC_IMPL(__imp__sub_822A2984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A2988"))) PPC_WEAK_FUNC(sub_822A2988);
PPC_FUNC_IMPL(__imp__sub_822A2988) {
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
	PPCRegister f0{};
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
	ctx.lr = 0x822A2990;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9c8
	ctx.lr = 0x822A2998;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387a18
	ctx.lr = 0x822A29A4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a29d4
	if (cr6.eq) goto loc_822A29D4;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a29d4
	if (cr6.eq) goto loc_822A29D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a20d0
	ctx.lr = 0x822A29C4;
	sub_822A20D0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba14
	ctx.lr = 0x822A29D0;
	// b 0x823d9228
	return;
loc_822A29D4:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x822a389c
	if (cr6.eq) goto loc_822A389C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lhz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r20,r11,29952
	r20.s64 = r11.s64 + 29952;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// lfs f29,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// beq cr6,0x822a3818
	if (cr6.eq) goto loc_822A3818;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a3818
	if (cr6.eq) goto loc_822A3818;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r10,21384
	ctx.r10.s64 = ctx.r10.s64 + 21384;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r6,r10,52
	ctx.r6.s64 = ctx.r10.s64 + 52;
	// li r22,1
	r22.s64 = 1;
	// li r25,0
	r25.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lbz r30,21381(r7)
	r30.u64 = PPC_LOAD_U8(ctx.r7.u32 + 21381);
	// lwzx r5,r8,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// cmpwi cr6,r5,4
	cr6.compare<int32_t>(ctx.r5.s32, 4, xer);
	// bne cr6,0x822a2a44
	if (!cr6.eq) goto loc_822A2A44;
	// mr r25,r22
	r25.u64 = r22.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822A2A44:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822a2a58
	if (cr6.eq) goto loc_822A2A58;
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// mr r30,r22
	r30.u64 = r22.u64;
loc_822A2A58:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x82388580
	ctx.lr = 0x822A2A60;
	sub_82388580(ctx, base);
	// lwz r29,12(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82387b90
	ctx.lr = 0x822A2A68;
	sub_82387B90(ctx, base);
	// addi r11,r29,306
	r11.s64 = r29.s64 + 306;
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r22
	r11.u64 = r22.u64;
	// lfsx f0,r10,r3
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x822a2a88
	if (!cr6.eq) goto loc_822A2A88;
	// li r11,0
	r11.s64 = 0;
loc_822A2A88:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// stfs f0,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stb r11,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a2ab4
	if (cr6.eq) goto loc_822A2AB4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4ed0
	ctx.lr = 0x822A2AA4;
	sub_822A4ED0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x822A2AAC;
	sub_822A4DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a2370
	ctx.lr = 0x822A2AB4;
	sub_822A2370(ctx, base);
loc_822A2AB4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r21,-32115
	r21.s64 = -2104688640;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lwz r3,568(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a2b20
	if (cr6.eq) goto loc_822A2B20;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// extsh r4,r10
	ctx.r4.s64 = ctx.r10.s16;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822A2AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822a2b18
	if (!cr6.eq) goto loc_822A2B18;
	// lwz r11,-12348(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -12348);
	// lbz r11,76(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a2b18
	if (!cr6.eq) goto loc_822A2B18;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822a2b1c
	if (cr6.eq) goto loc_822A2B1C;
loc_822A2B18:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_822A2B1C:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
loc_822A2B20:
	// lis r23,-32115
	r23.s64 = -2104688640;
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a2b44
	if (cr6.eq) goto loc_822A2B44;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r22
	r11.u64 = r22.u64;
	// beq cr6,0x822a2b48
	if (cr6.eq) goto loc_822A2B48;
loc_822A2B44:
	// li r11,0
	r11.s64 = 0;
loc_822A2B48:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a3880
	if (!cr6.eq) goto loc_822A3880;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3880
	if (cr6.eq) goto loc_822A3880;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a50c0
	ctx.lr = 0x822A2B68;
	sub_822A50C0(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4b80
	ctx.lr = 0x822A2B70;
	sub_822A4B80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r30,r11,17196
	r30.s64 = r11.s64 + 17196;
	// beq cr6,0x822a2bb0
	if (cr6.eq) goto loc_822A2BB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17236
	ctx.r10.s64 = r11.s64 + 17236;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a2ba4
	if (!cr6.eq) goto loc_822A2BA4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a2bb0
	if (cr6.eq) goto loc_822A2BB0;
loc_822A2BA4:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// b 0x822a2bb8
	goto loc_822A2BB8;
loc_822A2BB0:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
loc_822A2BB8:
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// addi r24,r31,80
	r24.s64 = r31.s64 + 80;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4b80
	ctx.lr = 0x822A2BC8;
	sub_822A4B80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a2bf4
	if (cr6.eq) goto loc_822A2BF4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17216
	ctx.r10.s64 = r11.s64 + 17216;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a2c00
	if (!cr6.eq) goto loc_822A2C00;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a2c00
	if (!cr6.eq) goto loc_822A2C00;
loc_822A2BF4:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// b 0x822a2c08
	goto loc_822A2C08;
loc_822A2C00:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_822A2C08:
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,0,27,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF1F;
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// bl 0x822a0110
	ctx.lr = 0x822A2C20;
	sub_822A0110(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a0398
	ctx.lr = 0x822A2C28;
	sub_822A0398(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// fmr f28,f29
	ctx.fpscr.disableFlushMode();
	f28.f64 = f29.f64;
	// addi r26,r11,-712
	r26.s64 = r11.s64 + -712;
	// fmr f27,f29
	f27.f64 = f29.f64;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// addi r28,r10,14576
	r28.s64 = ctx.r10.s64 + 14576;
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r9,6(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a2d04
	if (!cr6.eq) goto loc_822A2D04;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822a2cbc
	if (cr6.eq) goto loc_822A2CBC;
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// beq cr6,0x822a2c84
	if (cr6.eq) goto loc_822A2C84;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x822A2C80;
	sub_824656D0(ctx, base);
	// b 0x822a2c88
	goto loc_822A2C88;
loc_822A2C84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A2C88:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a2cbc
	if (cr6.eq) goto loc_822A2CBC;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82465448
	ctx.lr = 0x822A2CA4;
	sub_82465448(ctx, base);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mulli r11,r10,120
	r11.s64 = ctx.r10.s64 * 120;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82465400
	ctx.lr = 0x822A2CB8;
	sub_82465400(ctx, base);
	// b 0x822a2cd8
	goto loc_822A2CD8;
loc_822A2CBC:
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4bb8
	ctx.lr = 0x822A2CC8;
	sub_822A4BB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822A2CD8;
	sub_822A4BB8(ctx, base);
loc_822A2CD8:
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lfs f2,-4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822A2CE8;
	sub_8260C5C8(ctx, base);
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// lfs f2,-4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822A2CF8;
	sub_8260C5C8(ctx, base);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// fneg f0,f27
	f0.u64 = f27.u64 ^ 0x8000000000000000;
	// fadds f0,f0,f28
	f0.f64 = double(float(f0.f64 + f28.f64));
loc_822A2D04:
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lfs f26,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f26.f64 = double(temp.f32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f29,12(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// rlwinm r8,r10,0,31,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// stfs f29,16(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r8,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r8.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// lfs f24,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f24.f64 = double(temp.f32);
	// fsubs f13,f0,f24
	ctx.f13.f64 = double(float(f0.f64 - f24.f64));
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fsel f12,f13,f0,f24
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : f24.f64;
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f30,f11,f31,f12
	f30.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822A2D58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822a2db4
	if (cr6.eq) goto loc_822A2DB4;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a2d90
	if (cr6.eq) goto loc_822A2D90;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a06c0
	ctx.lr = 0x822A2D8C;
	sub_822A06C0(ctx, base);
	// b 0x822a2dec
	goto loc_822A2DEC;
loc_822A2D90:
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// bge cr6,0x822a2da8
	if (!cr6.lt) goto loc_822A2DA8;
	// fneg f0,f30
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// stfs f29,0(r30)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x822a2dec
	goto loc_822A2DEC;
loc_822A2DA8:
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f29,0(r29)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x822a2dec
	goto loc_822A2DEC;
loc_822A2DB4:
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// bge cr6,0x822a2dd4
	if (!cr6.lt) goto loc_822A2DD4;
	// li r11,3
	r11.s64 = 3;
	// fneg f0,f30
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// stfs f29,0(r30)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// b 0x822a2de0
	goto loc_822A2DE0;
loc_822A2DD4:
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stw r22,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r22.u32);
	// stfs f29,0(r29)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_822A2DE0:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwimi r11,r22,1,29,31
	r11.u64 = (__builtin_rotateleft32(r22.u32, 1) & 0x7) | (r11.u64 & 0xFFFFFFFFFFFFFFF8);
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
loc_822A2DEC:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f25,-13148(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	f25.f64 = double(temp.f32);
	// beq cr6,0x822a2e2c
	if (cr6.eq) goto loc_822A2E2C;
	// fmuls f0,f27,f25
	f0.f64 = double(float(f27.f64 * f25.f64));
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f28
	ctx.f11.f64 = double(float(ctx.f13.f64 - f28.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f9,f11,f13,f28
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : f28.f64;
	// stfs f9,0(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fsel f8,f10,f12,f0
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// stfs f8,0(r29)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x822a2e70
	goto loc_822A2E70;
loc_822A2E2C:
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a2e70
	if (cr6.eq) goto loc_822A2E70;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82332098
	ctx.lr = 0x822A2E40;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a2e5c
	if (!cr6.eq) goto loc_822A2E5C;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 - f27.f64));
	// fsel f12,f13,f0,f27
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : f27.f64;
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
loc_822A2E5C:
	// fmuls f0,f28,f25
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f28.f64 * f25.f64));
	// lfs f13,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f13,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_822A2E70:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,88(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823dc480
	ctx.lr = 0x822A2E80;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fsel f13,f0,f0,f29
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f11,f12,f31,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lfs f2,92(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823dc480
	ctx.lr = 0x822A2EA4;
	sub_823DC480(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fsel f8,f10,f10,f29
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f29.f64;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f10,0(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f28,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f28.f64 = double(temp.f32);
	// fsubs f9,f28,f26
	ctx.f9.f64 = double(float(f28.f64 - f26.f64));
	// fsubs f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f7,f9,f28,f26
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? f28.f64 : f26.f64;
	// fsel f5,f6,f31,f8
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// stfs f5,0(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lfs f0,12(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 12);
	f0.f64 = double(temp.f32);
	// fsubs f4,f28,f5
	ctx.f4.f64 = double(float(f28.f64 - ctx.f5.f64));
	// fsel f3,f4,f28,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f28.f64 : ctx.f5.f64;
	// fsubs f2,f3,f7
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f7.f64));
	// fmuls f26,f2,f0
	f26.f64 = double(float(ctx.f2.f64 * f0.f64));
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// sth r6,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r6.u16);
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r4,6(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822a2f10
	if (!cr6.eq) goto loc_822A2F10;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4bb8
	ctx.lr = 0x822A2F0C;
	sub_822A4BB8(ctx, base);
	// b 0x822a2f14
	goto loc_822A2F14;
loc_822A2F10:
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
loc_822A2F14:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stfs f1,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822a2f68
	if (cr6.eq) goto loc_822A2F68;
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// beq cr6,0x822a2f44
	if (cr6.eq) goto loc_822A2F44;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x822A2F40;
	sub_824656D0(ctx, base);
	// b 0x822a2f48
	goto loc_822A2F48;
loc_822A2F44:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A2F48:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a2f68
	if (cr6.eq) goto loc_822A2F68;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82465328
	ctx.lr = 0x822A2F64;
	sub_82465328(ctx, base);
	// b 0x822a2f74
	goto loc_822A2F74;
loc_822A2F68:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4bb8
	ctx.lr = 0x822A2F74;
	sub_822A4BB8(ctx, base);
loc_822A2F74:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822a2f84
	if (!cr6.gt) goto loc_822A2F84;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// b 0x822a2f90
	goto loc_822A2F90;
loc_822A2F84:
	// fcmpu cr6,f1,f24
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f24.f64);
	// bge cr6,0x822a2f90
	if (!cr6.lt) goto loc_822A2F90;
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
loc_822A2F90:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
	// clrlwi r25,r25,24
	r25.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// lfs f30,21604(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21604);
	f30.f64 = double(temp.f32);
	// bne cr6,0x822a2fb4
	if (!cr6.eq) goto loc_822A2FB4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,-8(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -8);
	f0.f64 = double(temp.f32);
	// lfs f30,84(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	f30.f64 = double(temp.f32);
loc_822A2FB4:
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fnmsubs f11,f12,f25,f0
	ctx.f11.f64 = double(float(-(ctx.f12.f64 * f25.f64 - f0.f64)));
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f2,f10,f0,f11
	ctx.f2.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822A2FCC;
	sub_8260C5C8(ctx, base);
	// lfs f9,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f9.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmuls f8,f9,f30
	ctx.f8.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmr f27,f1
	f27.f64 = ctx.f1.f64;
	// lfs f0,-32032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	f0.f64 = double(temp.f32);
	// fnmsubs f7,f8,f28,f30
	ctx.f7.f64 = double(float(-(ctx.f8.f64 * f28.f64 - f30.f64)));
	// fabs f1,f27
	ctx.f1.u64 = f27.u64 & ~0x8000000000000000;
	// fsubs f6,f0,f7
	ctx.f6.f64 = double(float(f0.f64 - ctx.f7.f64));
	// fsel f2,f6,f0,f7
	ctx.f2.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : ctx.f7.f64;
	// bl 0x823dc480
	ctx.lr = 0x822A2FF4;
	sub_823DC480(ctx, base);
	// fneg f5,f27
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = f27.u64 ^ 0x8000000000000000;
	// frsp f4,f1
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// fsel f3,f5,f29,f31
	ctx.f3.f64 = ctx.f5.f64 >= 0.0 ? f29.f64 : f31.f64;
	// fsel f2,f27,f3,f24
	ctx.f2.f64 = f27.f64 >= 0.0 ? ctx.f3.f64 : f24.f64;
	// fmuls f0,f4,f2
	f0.f64 = double(float(ctx.f4.f64 * ctx.f2.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822a3018
	if (!cr6.gt) goto loc_822A3018;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x822a3024
	goto loc_822A3024;
loc_822A3018:
	// fcmpu cr6,f0,f24
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f24.f64);
	// bge cr6,0x822a3024
	if (!cr6.lt) goto loc_822A3024;
	// fmr f0,f24
	f0.f64 = f24.f64;
loc_822A3024:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// lfs f11,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f29
	cr6.compare(ctx.f11.f64, f29.f64);
	// ble cr6,0x822a308c
	if (!cr6.gt) goto loc_822A308C;
	// lfs f12,116(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x822a308c
	if (!cr6.gt) goto loc_822A308C;
	// lfs f13,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// beq cr6,0x822a308c
	if (cr6.eq) goto loc_822A308C;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f10,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f12.f64));
	// fsel f8,f9,f9,f29
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsel f7,f9,f9,f29
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsubs f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f5,f6,f31,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : ctx.f7.f64;
	// fsubs f4,f31,f5
	ctx.f4.f64 = double(float(f31.f64 - ctx.f5.f64));
	// fmuls f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmadds f2,f3,f11,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + f0.f64));
	// fsubs f1,f2,f24
	ctx.f1.f64 = double(float(ctx.f2.f64 - f24.f64));
	// fsel f0,f1,f2,f24
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f24.f64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// fsel f12,f13,f31,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
loc_822A308C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822a309c
	if (cr6.eq) goto loc_822A309C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// b 0x822a30ac
	goto loc_822A30AC;
loc_822A309C:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8255ff78
	ctx.lr = 0x822A30AC;
	sub_8255FF78(ctx, base);
loc_822A30AC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f27,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f27.f64 = double(temp.f32);
	// addi r29,r31,36
	r29.s64 = r31.s64 + 36;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stfs f1,88(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// rlwinm r9,r9,0,31,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFF81;
	// lfs f30,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	f30.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822a31c4
	if (cr6.eq) goto loc_822A31C4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4bb8
	ctx.lr = 0x822A30E0;
	sub_822A4BB8(ctx, base);
	// fsubs f0,f1,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f24.f64));
	// lfs f2,-4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// fsel f13,f0,f1,f24
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : f24.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f1,f12,f31,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822A30F8;
	sub_8260C5C8(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822a311c
	if (!cr6.eq) goto loc_822A311C;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// lfs f3,88(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x821ce490
	ctx.lr = 0x822A3118;
	sub_821CE490(ctx, base);
	// b 0x822a3120
	goto loc_822A3120;
loc_822A311C:
	// stfs f1,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_822A3120:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822a3170
	if (cr6.eq) goto loc_822A3170;
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// beq cr6,0x822a314c
	if (cr6.eq) goto loc_822A314C;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x822A3148;
	sub_824656D0(ctx, base);
	// b 0x822a3150
	goto loc_822A3150;
loc_822A314C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A3150:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3170
	if (cr6.eq) goto loc_822A3170;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mulli r11,r11,120
	r11.s64 = r11.s64 * 120;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x82465328
	ctx.lr = 0x822A316C;
	sub_82465328(ctx, base);
	// b 0x822a3194
	goto loc_822A3194;
loc_822A3170:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4bb8
	ctx.lr = 0x822A317C;
	sub_822A4BB8(ctx, base);
	// fsubs f0,f1,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f24.f64));
	// lfs f2,-8(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -8);
	ctx.f2.f64 = double(temp.f32);
	// fsel f13,f0,f1,f24
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : f24.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f1,f12,f31,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822A3194;
	sub_8260C5C8(ctx, base);
loc_822A3194:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822a31bc
	if (!cr6.eq) goto loc_822A31BC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f3,88(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f2,-17876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x822A31B8;
	sub_821CE490(ctx, base);
	// b 0x822a31cc
	goto loc_822A31CC;
loc_822A31BC:
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x822a31cc
	goto loc_822A31CC;
loc_822A31C4:
	// stfs f29,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f29,0(r29)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_822A31CC:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4bb8
	ctx.lr = 0x822A31D8;
	sub_822A4BB8(ctx, base);
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x822a31f4
	if (!cr6.gt) goto loc_822A31F4;
	// fneg f0,f1
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f0,f29,f31
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : f31.f64;
	// fsel f1,f1,f13,f24
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? ctx.f13.f64 : f24.f64;
	// b 0x822a31f8
	goto loc_822A31F8;
loc_822A31F4:
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
loc_822A31F8:
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// lfs f3,88(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x821ce490
	ctx.lr = 0x822A3208;
	sub_821CE490(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r30,0
	r30.s64 = 0;
	// bl 0x822a4db0
	ctx.lr = 0x822A3218;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3274
	if (cr6.eq) goto loc_822A3274;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x822a3240
	if (cr6.eq) goto loc_822A3240;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x822a3240
	if (!cr6.eq) goto loc_822A3240;
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// b 0x822a3248
	goto loc_822A3248;
loc_822A3240:
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
loc_822A3248:
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822a325c
	if (!cr6.gt) goto loc_822A325C;
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// ble cr6,0x822a3270
	if (!cr6.gt) goto loc_822A3270;
loc_822A325C:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822a3274
	if (!cr6.lt) goto loc_822A3274;
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// blt cr6,0x822a3274
	if (cr6.lt) goto loc_822A3274;
loc_822A3270:
	// mr r30,r22
	r30.u64 = r22.u64;
loc_822A3274:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822a3298
	if (!cr6.gt) goto loc_822A3298;
	// fcmpu cr6,f26,f0
	cr6.compare(f26.f64, f0.f64);
	// ble cr6,0x822a3298
	if (!cr6.gt) goto loc_822A3298;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,8192
	ctx.r10.u64 = r11.u64 | 8192;
	// b 0x822a32a0
	goto loc_822A32A0;
loc_822A3298:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,19,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFDFFF;
loc_822A32A0:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822a32cc
	if (cr6.eq) goto loc_822A32CC;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r9,18(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 18);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a32cc
	if (!cr6.eq) goto loc_822A32CC;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// b 0x822a32d4
	goto loc_822A32D4;
loc_822A32CC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
loc_822A32D4:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4db0
	ctx.lr = 0x822A32E4;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// bne cr6,0x822a32fc
	if (!cr6.eq) goto loc_822A32FC;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_822A32FC:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r11,6(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a3334
	if (!cr6.eq) goto loc_822A3334;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4db0
	ctx.lr = 0x822A331C;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3334
	if (cr6.eq) goto loc_822A3334;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// b 0x822a333c
	goto loc_822A333C;
loc_822A3334:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_822A333C:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r11,6(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a3374
	if (!cr6.eq) goto loc_822A3374;
	// li r4,26
	ctx.r4.s64 = 26;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4db0
	ctx.lr = 0x822A335C;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3374
	if (cr6.eq) goto loc_822A3374;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// b 0x822a337c
	goto loc_822A337C;
loc_822A3374:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
loc_822A337C:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r11,6(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a344c
	if (!cr6.eq) goto loc_822A344C;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4db0
	ctx.lr = 0x822A339C;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a344c
	if (cr6.eq) goto loc_822A344C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r30,668(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// lwz r29,664(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a340c
	if (cr6.eq) goto loc_822A340C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82345fe0
	ctx.lr = 0x822A33C8;
	sub_82345FE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822a340c
	if (!cr6.eq) goto loc_822A340C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822a33fc
	if (cr6.eq) goto loc_822A33FC;
	// lbz r11,32(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a340c
	if (!cr6.eq) goto loc_822A340C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82345660
	ctx.lr = 0x822A33F0;
	sub_82345660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a340c
	if (cr6.eq) goto loc_822A340C;
loc_822A33FC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwimi r11,r22,2,28,29
	r11.u64 = (__builtin_rotateleft32(r22.u32, 2) & 0xC) | (r11.u64 & 0xFFFFFFFFFFFFFFF3);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x822a3458
	goto loc_822A3458;
loc_822A340C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822a3458
	if (cr6.eq) goto loc_822A3458;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a343c
	if (cr6.eq) goto loc_822A343C;
	// lbz r11,40(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a3458
	if (!cr6.eq) goto loc_822A3458;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82345df8
	ctx.lr = 0x822A3430;
	sub_82345DF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3458
	if (cr6.eq) goto loc_822A3458;
loc_822A343C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwimi r11,r22,3,28,29
	r11.u64 = (__builtin_rotateleft32(r22.u32, 3) & 0xC) | (r11.u64 & 0xFFFFFFFFFFFFFFF3);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x822a3458
	goto loc_822A3458;
loc_822A344C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,30,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3458:
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r11,6(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a348c
	if (!cr6.eq) goto loc_822A348C;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4db0
	ctx.lr = 0x822A3474;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a348c
	if (cr6.eq) goto loc_822A348C;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// b 0x822a3494
	goto loc_822A3494;
loc_822A348C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
loc_822A3494:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a3510
	if (!cr6.eq) goto loc_822A3510;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A34B4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3510
	if (cr6.eq) goto loc_822A3510;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a3510
	if (cr6.eq) goto loc_822A3510;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822a34e4
	if (!cr6.eq) goto loc_822A34E4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822a34f8
	goto loc_822A34F8;
loc_822A34E4:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mulli r10,r11,104
	ctx.r10.s64 = r11.s64 * 104;
	// lwz r11,-12120(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12120);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823960f8
	ctx.lr = 0x822A34F8;
	sub_823960F8(ctx, base);
loc_822A34F8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3510
	if (cr6.eq) goto loc_822A3510;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// xori r10,r11,1024
	ctx.r10.u64 = r11.u64 ^ 1024;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3510:
	// lwz r11,-12640(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -12640);
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a352c
	if (!cr6.eq) goto loc_822A352C;
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A352C;
	sub_822A4CE0(ctx, base);
loc_822A352C:
	// lfs f0,88(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 88);
	f0.f64 = double(temp.f32);
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f13,168(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r31,168
	r30.s64 = r31.s64 + 168;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,168(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A354C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a359c
	if (cr6.eq) goto loc_822A359C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a359c
	if (cr6.eq) goto loc_822A359C;
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822a3588
	if (!cr6.eq) goto loc_822A3588;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-708(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -708);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822a360c
	if (!cr6.gt) goto loc_822A360C;
loc_822A3588:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stfs f29,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stw r22,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r22.u32);
	// ori r10,r11,256
	ctx.r10.u64 = r11.u64 | 256;
	// b 0x822a3608
	goto loc_822A3608;
loc_822A359C:
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A35A8;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3600
	if (cr6.eq) goto loc_822A3600;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a3600
	if (cr6.eq) goto loc_822A3600;
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822a35e4
	if (!cr6.eq) goto loc_822A35E4;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-708(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -708);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822a360c
	if (!cr6.gt) goto loc_822A360C;
loc_822A35E4:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f29,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// ori r9,r11,512
	ctx.r9.u64 = r11.u64 | 512;
	// stw r10,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r10.u32);
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// b 0x822a360c
	goto loc_822A360C;
loc_822A3600:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,24,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFCFF;
loc_822A3608:
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A360C:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// sth r8,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r8.u16);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,676(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 676);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822a3768
	if (cr6.eq) goto loc_822A3768;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r4,38
	ctx.r4.s64 = 38;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// rlwinm r10,r11,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// bl 0x822a4ce0
	ctx.lr = 0x822A3648;
	sub_822A4CE0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a3660
	if (cr6.eq) goto loc_822A3660;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,1
	ctx.r10.u64 = r11.u64 | 65536;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3660:
	// li r4,39
	ctx.r4.s64 = 39;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A366C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3684
	if (cr6.eq) goto loc_822A3684;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,2
	ctx.r10.u64 = r11.u64 | 131072;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3684:
	// li r4,40
	ctx.r4.s64 = 40;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A3690;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a36a8
	if (cr6.eq) goto loc_822A36A8;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,4
	ctx.r10.u64 = r11.u64 | 262144;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A36A8:
	// li r4,41
	ctx.r4.s64 = 41;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A36B4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a36cc
	if (cr6.eq) goto loc_822A36CC;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,8
	ctx.r10.u64 = r11.u64 | 524288;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A36CC:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r4,38
	ctx.r4.s64 = 38;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// rlwinm r10,r11,0,12,7
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF0FFFFF;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// bl 0x822a4d48
	ctx.lr = 0x822A36E4;
	sub_822A4D48(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a36fc
	if (cr6.eq) goto loc_822A36FC;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,16
	ctx.r10.u64 = r11.u64 | 1048576;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A36FC:
	// li r4,39
	ctx.r4.s64 = 39;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4d48
	ctx.lr = 0x822A3708;
	sub_822A4D48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3720
	if (cr6.eq) goto loc_822A3720;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,32
	ctx.r10.u64 = r11.u64 | 2097152;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3720:
	// li r4,40
	ctx.r4.s64 = 40;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4d48
	ctx.lr = 0x822A372C;
	sub_822A4D48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3744
	if (cr6.eq) goto loc_822A3744;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,64
	ctx.r10.u64 = r11.u64 | 4194304;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3744:
	// li r4,41
	ctx.r4.s64 = 41;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a4d48
	ctx.lr = 0x822A3750;
	sub_822A4D48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3768
	if (cr6.eq) goto loc_822A3768;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// oris r10,r11,128
	ctx.r10.u64 = r11.u64 | 8388608;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A3768:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r8,r9,0,27,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1C;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822a378c
	if (cr6.eq) goto loc_822A378C;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_822A378C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a25e0
	ctx.lr = 0x822A3794;
	sub_822A25E0(ctx, base);
	// lwz r11,-12348(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -12348);
	// lbz r11,76(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a37b4
	if (cr6.eq) goto loc_822A37B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a1b78
	ctx.lr = 0x822A37B0;
	sub_822A1B78(ctx, base);
	// b 0x822a37c8
	goto loc_822A37C8;
loc_822A37B4:
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a37c8
	if (cr6.eq) goto loc_822A37C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a0a38
	ctx.lr = 0x822A37C8;
	sub_822A0A38(ctx, base);
loc_822A37C8:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822a37e0
	if (cr6.eq) goto loc_822A37E0;
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// b 0x822a37ec
	goto loc_822A37EC;
loc_822A37E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a1520
	ctx.lr = 0x822A37EC;
	sub_822A1520(ctx, base);
loc_822A37EC:
	// fsubs f0,f1,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f24.f64));
	// fsel f13,f0,f1,f24
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : f24.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f11,f12,f31,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x822A3804;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a3818
	if (!cr6.eq) goto loc_822A3818;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a1058
	ctx.lr = 0x822A3818;
	sub_822A1058(ctx, base);
loc_822A3818:
	// bl 0x82387a18
	ctx.lr = 0x822A381C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a383c
	if (cr6.eq) goto loc_822A383C;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822a383c
	if (!cr6.eq) goto loc_822A383C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a1ea8
	ctx.lr = 0x822A383C;
	sub_822A1EA8(ctx, base);
loc_822A383C:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bne cr6,0x822a3898
	if (!cr6.eq) goto loc_822A3898;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bne cr6,0x822a3898
	if (!cr6.eq) goto loc_822A3898;
	// lfs f0,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bne cr6,0x822a3898
	if (!cr6.eq) goto loc_822A3898;
	// lfs f13,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,112(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba14
	ctx.lr = 0x822A387C;
	// b 0x823d9228
	return;
loc_822A3880:
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x822a50c0
	ctx.lr = 0x822A3888;
	sub_822A50C0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba14
	ctx.lr = 0x822A3894;
	// b 0x823d9228
	return;
loc_822A3898:
	// stfs f29,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
loc_822A389C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba14
	ctx.lr = 0x822A38A8;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822A38AC"))) PPC_WEAK_FUNC(sub_822A38AC);
PPC_FUNC_IMPL(__imp__sub_822A38AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A38B0"))) PPC_WEAK_FUNC(sub_822A38B0);
PPC_FUNC_IMPL(__imp__sub_822A38B0) {
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
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a38e4
	if (cr6.eq) goto loc_822A38E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A38E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A38E4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,17268(r31)
	PPC_STORE_U32(r31.u32 + 17268, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A3900"))) PPC_WEAK_FUNC(sub_822A3900);
PPC_FUNC_IMPL(__imp__sub_822A3900) {
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
	ctx.lr = 0x822A3908;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// li r31,0
	r31.s64 = 0;
loc_822A391C:
	// lwz r11,132(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x822a3930
	if (cr6.lt) goto loc_822A3930;
	// li r11,0
	r11.s64 = 0;
loc_822A3930:
	// clrlwi r30,r11,31
	r30.u64 = r11.u32 & 0x1;
	// bl 0x82387a18
	ctx.lr = 0x822A3938;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3968
	if (cr6.eq) goto loc_822A3968;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388580
	ctx.lr = 0x822A394C;
	sub_82388580(ctx, base);
	// lbz r11,22(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// cntlzw r10,r31
	ctx.r10.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// and r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 & ctx.r8.u64;
	// and r30,r6,r30
	r30.u64 = ctx.r6.u64 & r30.u64;
loc_822A3968:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stbx r30,r31,r28
	PPC_STORE_U8(r31.u32 + r28.u32, r30.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// blt cr6,0x822a391c
	if (cr6.lt) goto loc_822A391C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822A3998"))) PPC_WEAK_FUNC(sub_822A3998);
PPC_FUNC_IMPL(__imp__sub_822A3998) {
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
	// addi r11,r4,34
	r11.s64 = ctx.r4.s64 + 34;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a39b4
	if (!cr6.eq) goto loc_822A39B4;
	// addi r11,r4,2
	r11.s64 = ctx.r4.s64 + 2;
loc_822A39B4:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A39C0"))) PPC_WEAK_FUNC(sub_822A39C0);
PPC_FUNC_IMPL(__imp__sub_822A39C0) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821e80f8
	sub_821E80F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A39C8"))) PPC_WEAK_FUNC(sub_822A39C8);
PPC_FUNC_IMPL(__imp__sub_822A39C8) {
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
	// beq cr6,0x822a39e4
	if (cr6.eq) goto loc_822A39E4;
	// lwz r3,136(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// blr 
	return;
loc_822A39E4:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A39EC"))) PPC_WEAK_FUNC(sub_822A39EC);
PPC_FUNC_IMPL(__imp__sub_822A39EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A39F0"))) PPC_WEAK_FUNC(sub_822A39F0);
PPC_FUNC_IMPL(__imp__sub_822A39F0) {
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
	// bl 0x821e80f8
	ctx.lr = 0x822A3A08;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3a2c
	if (cr6.eq) goto loc_822A3A2C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388580
	ctx.lr = 0x822A3A1C;
	sub_82388580(ctx, base);
	// lbz r11,22(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822a3a30
	if (cr6.eq) goto loc_822A3A30;
loc_822A3A2C:
	// li r11,0
	r11.s64 = 0;
loc_822A3A30:
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

__attribute__((alias("__imp__sub_822A3A48"))) PPC_WEAK_FUNC(sub_822A3A48);
PPC_FUNC_IMPL(__imp__sub_822A3A48) {
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
	ctx.lr = 0x822A3A50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a3aa0
	if (!cr6.gt) goto loc_822A3AA0;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
loc_822A3A6C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3a8c
	if (cr6.eq) goto loc_822A3A8C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A3A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A3A8C:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822a3a6c
	if (cr6.lt) goto loc_822A3A6C;
loc_822A3AA0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A3AA8"))) PPC_WEAK_FUNC(sub_822A3AA8);
PPC_FUNC_IMPL(__imp__sub_822A3AA8) {
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
	ctx.lr = 0x822A3AB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a3b00
	if (!cr6.gt) goto loc_822A3B00;
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
loc_822A3AD0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3aec
	if (cr6.eq) goto loc_822A3AEC;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a3aec
	if (cr6.eq) goto loc_822A3AEC;
	// bl 0x82331648
	ctx.lr = 0x822A3AEC;
	sub_82331648(ctx, base);
loc_822A3AEC:
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822a3ad0
	if (cr6.lt) goto loc_822A3AD0;
loc_822A3B00:
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a3b30
	if (!cr6.gt) goto loc_822A3B30;
	// addi r11,r30,136
	r11.s64 = r30.s64 + 136;
loc_822A3B14:
	// lwz r9,-128(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -128);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,132(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x822a3b14
	if (cr6.lt) goto loc_822A3B14;
loc_822A3B30:
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,260(r30)
	PPC_STORE_U32(r30.u32 + 260, r11.u32);
	// ble cr6,0x822a3ba8
	if (!cr6.gt) goto loc_822A3BA8;
	// addi r31,r30,400
	r31.s64 = r30.s64 + 400;
loc_822A3B48:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a3b94
	if (cr6.eq) goto loc_822A3B94;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A3B64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,656(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822a3b94
	if (!cr6.eq) goto loc_822A3B94;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a3b90
	if (cr6.eq) goto loc_822A3B90;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A3B90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A3B90:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_822A3B94:
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822a3b48
	if (cr6.lt) goto loc_822A3B48;
loc_822A3BA8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A3BB0"))) PPC_WEAK_FUNC(sub_822A3BB0);
PPC_FUNC_IMPL(__imp__sub_822A3BB0) {
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
	ctx.lr = 0x822A3BB8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// stb r30,564(r29)
	PPC_STORE_U8(r29.u32 + 564, r30.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a3c0c
	if (!cr6.gt) goto loc_822A3C0C;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
loc_822A3BD8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3bf8
	if (cr6.eq) goto loc_822A3BF8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A3BF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A3BF8:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822a3bd8
	if (cr6.lt) goto loc_822A3BD8;
loc_822A3C0C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A3C14"))) PPC_WEAK_FUNC(sub_822A3C14);
PPC_FUNC_IMPL(__imp__sub_822A3C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A3C18"))) PPC_WEAK_FUNC(sub_822A3C18);
PPC_FUNC_IMPL(__imp__sub_822A3C18) {
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
	ctx.lr = 0x822A3C20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a3d78
	if (!cr6.gt) goto loc_822A3D78;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
	// addi r26,r10,14576
	r26.s64 = ctx.r10.s64 + 14576;
loc_822A3C50:
	// lbzx r10,r28,r27
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r27.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a3c78
	if (cr6.eq) goto loc_822A3C78;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822a3c98
	if (cr6.lt) goto loc_822A3C98;
	// lwz r11,260(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822a3c98
	if (!cr6.lt) goto loc_822A3C98;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// b 0x822a3c8c
	goto loc_822A3C8C;
loc_822A3C78:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822a3c98
	if (cr6.lt) goto loc_822A3C98;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822a3c98
	if (!cr6.lt) goto loc_822A3C98;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822A3C8C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822a3c9c
	if (!cr6.eq) goto loc_822A3C9C;
loc_822A3C98:
	// li r11,0
	r11.s64 = 0;
loc_822A3C9C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3cc0
	if (cr6.eq) goto loc_822A3CC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388580
	ctx.lr = 0x822A3CB0;
	sub_82388580(ctx, base);
	// lbz r11,22(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822a3cc4
	if (cr6.eq) goto loc_822A3CC4;
loc_822A3CC0:
	// li r11,0
	r11.s64 = 0;
loc_822A3CC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3d64
	if (cr6.eq) goto loc_822A3D64;
	// lbzx r11,r28,r27
	r11.u64 = PPC_LOAD_U8(r28.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3ce4
	if (cr6.eq) goto loc_822A3CE4;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// b 0x822a3ce8
	goto loc_822A3CE8;
loc_822A3CE4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822A3CE8:
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3d14
	if (cr6.eq) goto loc_822A3D14;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a3d14
	if (cr6.eq) goto loc_822A3D14;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A3D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A3D14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388598
	ctx.lr = 0x822A3D1C;
	sub_82388598(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// ble cr6,0x822a3d30
	if (!cr6.gt) goto loc_822A3D30;
	// mulli r11,r3,120
	r11.s64 = ctx.r3.s64 * 120;
	// add r3,r11,r26
	ctx.r3.u64 = r11.u64 + r26.u64;
	// bl 0x82465490
	ctx.lr = 0x822A3D30;
	sub_82465490(ctx, base);
loc_822A3D30:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a3d64
	if (!cr6.eq) goto loc_822A3D64;
	// lbzx r11,r28,r27
	r11.u64 = PPC_LOAD_U8(r28.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3d50
	if (cr6.eq) goto loc_822A3D50;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// b 0x822a3d54
	goto loc_822A3D54;
loc_822A3D50:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822A3D54:
	// lwz r3,880(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a3d64
	if (cr6.eq) goto loc_822A3D64;
	// bl 0x822b32d0
	ctx.lr = 0x822A3D64;
	sub_822B32D0(ctx, base);
loc_822A3D64:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822a3c50
	if (cr6.lt) goto loc_822A3C50;
loc_822A3D78:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822A3D80"))) PPC_WEAK_FUNC(sub_822A3D80);
PPC_FUNC_IMPL(__imp__sub_822A3D80) {
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
	ctx.lr = 0x822A3D88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a3dd8
	if (!cr6.gt) goto loc_822A3DD8;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
loc_822A3DAC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a3dc4
	if (cr6.eq) goto loc_822A3DC4;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a6198
	ctx.lr = 0x822A3DC4;
	sub_822A6198(ctx, base);
loc_822A3DC4:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822a3dac
	if (cr6.lt) goto loc_822A3DAC;
loc_822A3DD8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

