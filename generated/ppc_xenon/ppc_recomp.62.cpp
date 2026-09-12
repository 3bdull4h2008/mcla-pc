#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82397F00"))) PPC_WEAK_FUNC(sub_82397F00);
PPC_FUNC_IMPL(__imp__sub_82397F00) {
	PPC_FUNC_PROLOGUE();
	// b 0x82397e88
	sub_82397E88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82397F04"))) PPC_WEAK_FUNC(sub_82397F04);
PPC_FUNC_IMPL(__imp__sub_82397F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82397F08"))) PPC_WEAK_FUNC(sub_82397F08);
PPC_FUNC_IMPL(__imp__sub_82397F08) {
	PPC_FUNC_PROLOGUE();
	// stb r4,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82397F10"))) PPC_WEAK_FUNC(sub_82397F10);
PPC_FUNC_IMPL(__imp__sub_82397F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// li r11,0
	r11.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82397F20:
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82397f20
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82397F20;
	// stb r11,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, r11.u8);
	// addi r10,r3,15
	ctx.r10.s64 = ctx.r3.s64 + 15;
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stb r11,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, r11.u8);
	// addi r10,r3,17
	ctx.r10.s64 = ctx.r3.s64 + 17;
	// stb r11,18(r3)
	PPC_STORE_U8(ctx.r3.u32 + 18, r11.u8);
	// stb r11,19(r3)
	PPC_STORE_U8(ctx.r3.u32 + 19, r11.u8);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// stb r11,22(r3)
	PPC_STORE_U8(ctx.r3.u32 + 22, r11.u8);
	// addi r11,r3,21
	r11.s64 = ctx.r3.s64 + 21;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82397F5C"))) PPC_WEAK_FUNC(sub_82397F5C);
PPC_FUNC_IMPL(__imp__sub_82397F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82397F60"))) PPC_WEAK_FUNC(sub_82397F60);
PPC_FUNC_IMPL(__imp__sub_82397F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r25{};
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r4,5
	cr6.compare<uint32_t>(ctx.r4.u32, 5, xer);
	// bgt cr6,0x82397ff8
	if (cr6.gt) goto loc_82397FF8;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,32644
	r12.s64 = r12.s64 + 32644;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_82397F9C;
	case 1:
		goto loc_82397FA8;
	case 2:
		goto loc_82397FB4;
	case 3:
		goto loc_82397FC0;
	case 4:
		goto loc_82397FCC;
	case 5:
		goto loc_82397FD8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,32668(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 32668);
	// lwz r17,32680(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 32680);
	// lwz r17,32692(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 32692);
	// lwz r17,32704(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 32704);
	// lwz r17,32716(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 32716);
	// lwz r17,32728(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 32728);
loc_82397F9C:
	// add r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r6,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, ctx.r6.u8);
	// b 0x82397ff4
	goto loc_82397FF4;
loc_82397FA8:
	// add r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r6,15(r10)
	PPC_STORE_U8(ctx.r10.u32 + 15, ctx.r6.u8);
	// b 0x82397ff4
	goto loc_82397FF4;
loc_82397FB4:
	// add r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r6,17(r10)
	PPC_STORE_U8(ctx.r10.u32 + 17, ctx.r6.u8);
	// b 0x82397ff4
	goto loc_82397FF4;
loc_82397FC0:
	// add r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r6,19(r10)
	PPC_STORE_U8(ctx.r10.u32 + 19, ctx.r6.u8);
	// b 0x82397ff4
	goto loc_82397FF4;
loc_82397FCC:
	// add r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r6,20(r10)
	PPC_STORE_U8(ctx.r10.u32 + 20, ctx.r6.u8);
	// b 0x82397ff4
	goto loc_82397FF4;
loc_82397FD8:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82397fec
	if (!cr6.eq) goto loc_82397FEC;
	// add r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r11,21(r10)
	PPC_STORE_U8(ctx.r10.u32 + 21, r11.u8);
	// b 0x82397ff4
	goto loc_82397FF4;
loc_82397FEC:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// stb r6,21(r11)
	PPC_STORE_U8(r11.u32 + 21, ctx.r6.u8);
loc_82397FF4:
	// li r11,128
	r11.s64 = 128;
loc_82397FF8:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82398014"))) PPC_WEAK_FUNC(sub_82398014);
PPC_FUNC_IMPL(__imp__sub_82398014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398018"))) PPC_WEAK_FUNC(sub_82398018);
PPC_FUNC_IMPL(__imp__sub_82398018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r25{};
	// cmplwi cr6,r4,5
	cr6.compare<uint32_t>(ctx.r4.u32, 5, xer);
	// bgt cr6,0x82398098
	if (cr6.gt) {
		sub_82398098(ctx, base);
		return;
	}
	// lis r12,-32198
	r12.s64 = -2110128128;
	// addi r12,r12,-32712
	r12.s64 = r12.s64 + -32712;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_82398050;
	case 1:
		goto loc_8239805C;
	case 2:
		goto loc_82398068;
	case 3:
		goto loc_82398074;
	case 4:
		goto loc_82398080;
	case 5:
		goto loc_8239808C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-32688(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + -32688);
	// lwz r17,-32676(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + -32676);
	// lwz r17,-32664(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + -32664);
	// lwz r17,-32652(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + -32652);
	// lwz r17,-32640(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + -32640);
	// lwz r17,-32628(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + -32628);
loc_82398050:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// blr 
	return;
loc_8239805C:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r3,15(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 15);
	// blr 
	return;
loc_82398068:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r3,17(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// blr 
	return;
loc_82398074:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r3,19(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 19);
	// blr 
	return;
loc_82398080:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// blr 
	return;
loc_8239808C:
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
}

__attribute__((alias("__imp__sub_82398098"))) PPC_WEAK_FUNC(sub_82398098);
PPC_FUNC_IMPL(__imp__sub_82398098) {
	PPC_FUNC_PROLOGUE();
	// li r3,200
	ctx.r3.s64 = 200;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823980A0"))) PPC_WEAK_FUNC(sub_823980A0);
PPC_FUNC_IMPL(__imp__sub_823980A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r10,r3,15
	ctx.r10.s64 = ctx.r3.s64 + 15;
	// li r9,7
	ctx.r9.s64 = 7;
	// li r11,0
	r11.s64 = 0;
loc_823980AC:
	// stb r11,-15(r10)
	PPC_STORE_U8(ctx.r10.u32 + -15, r11.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x823980ac
	if (!cr0.eq) goto loc_823980AC;
	// addi r10,r3,22
	ctx.r10.s64 = ctx.r3.s64 + 22;
	// li r9,2
	ctx.r9.s64 = 2;
loc_823980C8:
	// stb r11,-15(r10)
	PPC_STORE_U8(ctx.r10.u32 + -15, r11.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x823980c8
	if (!cr0.eq) goto loc_823980C8;
	// addi r10,r3,24
	ctx.r10.s64 = ctx.r3.s64 + 24;
	// li r9,2
	ctx.r9.s64 = 2;
loc_823980E4:
	// stb r11,-15(r10)
	PPC_STORE_U8(ctx.r10.u32 + -15, r11.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x823980e4
	if (!cr0.eq) goto loc_823980E4;
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, r11.u8);
	// addi r10,r3,13
	ctx.r10.s64 = ctx.r3.s64 + 13;
	// stb r11,26(r3)
	PPC_STORE_U8(ctx.r3.u32 + 26, r11.u8);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stb r11,27(r3)
	PPC_STORE_U8(ctx.r3.u32 + 27, r11.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82398118"))) PPC_WEAK_FUNC(sub_82398118);
PPC_FUNC_IMPL(__imp__sub_82398118) {
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
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r8,8
	ctx.r3.s64 = ctx.r8.s64 + 8;
	// addi r10,r11,-3140
	ctx.r10.s64 = r11.s64 + -3140;
	// stw r10,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// bl 0x823980a0
	ctx.lr = 0x8239813C;
	sub_823980A0(ctx, base);
	// li r11,100
	r11.s64 = 100;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,41(r8)
	PPC_STORE_U8(ctx.r8.u32 + 41, r11.u8);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stb r11,42(r8)
	PPC_STORE_U8(ctx.r8.u32 + 42, r11.u8);
	// stb r11,43(r8)
	PPC_STORE_U8(ctx.r8.u32 + 43, r11.u8);
	// stb r10,40(r8)
	PPC_STORE_U8(ctx.r8.u32 + 40, ctx.r10.u8);
	// stb r10,39(r8)
	PPC_STORE_U8(ctx.r8.u32 + 39, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239816C"))) PPC_WEAK_FUNC(sub_8239816C);
PPC_FUNC_IMPL(__imp__sub_8239816C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398170"))) PPC_WEAK_FUNC(sub_82398170);
PPC_FUNC_IMPL(__imp__sub_82398170) {
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
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8239819C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398254
	if (cr6.eq) goto loc_82398254;
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x823981B8;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398254
	if (cr6.eq) goto loc_82398254;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,39
	ctx.r4.s64 = r31.s64 + 39;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x823981D4;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398254
	if (cr6.eq) goto loc_82398254;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x823981F0;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398254
	if (cr6.eq) goto loc_82398254;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,41
	ctx.r4.s64 = r31.s64 + 41;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8239820C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398254
	if (cr6.eq) goto loc_82398254;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,42
	ctx.r4.s64 = r31.s64 + 42;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x82398228;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398254
	if (cr6.eq) goto loc_82398254;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,43
	ctx.r4.s64 = r31.s64 + 43;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x82398244;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82398258
	if (!cr6.eq) goto loc_82398258;
loc_82398254:
	// li r11,0
	r11.s64 = 0;
loc_82398258:
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

__attribute__((alias("__imp__sub_82398274"))) PPC_WEAK_FUNC(sub_82398274);
PPC_FUNC_IMPL(__imp__sub_82398274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398278"))) PPC_WEAK_FUNC(sub_82398278);
PPC_FUNC_IMPL(__imp__sub_82398278) {
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
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x823982A4;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239835c
	if (cr6.eq) goto loc_8239835C;
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x823982C0;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239835c
	if (cr6.eq) goto loc_8239835C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,39
	ctx.r4.s64 = r31.s64 + 39;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x823982DC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239835c
	if (cr6.eq) goto loc_8239835C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x823982F8;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239835c
	if (cr6.eq) goto loc_8239835C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,41
	ctx.r4.s64 = r31.s64 + 41;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x82398314;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239835c
	if (cr6.eq) goto loc_8239835C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,42
	ctx.r4.s64 = r31.s64 + 42;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x82398330;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239835c
	if (cr6.eq) goto loc_8239835C;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,43
	ctx.r4.s64 = r31.s64 + 43;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x8239834C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82398360
	if (!cr6.eq) goto loc_82398360;
loc_8239835C:
	// li r11,0
	r11.s64 = 0;
loc_82398360:
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

__attribute__((alias("__imp__sub_8239837C"))) PPC_WEAK_FUNC(sub_8239837C);
PPC_FUNC_IMPL(__imp__sub_8239837C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398380"))) PPC_WEAK_FUNC(sub_82398380);
PPC_FUNC_IMPL(__imp__sub_82398380) {
	PPC_FUNC_PROLOGUE();
	// stb r4,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r4.u8);
	// stb r4,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239838C"))) PPC_WEAK_FUNC(sub_8239838C);
PPC_FUNC_IMPL(__imp__sub_8239838C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398390"))) PPC_WEAK_FUNC(sub_82398390);
PPC_FUNC_IMPL(__imp__sub_82398390) {
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
	ctx.lr = 0x82398398;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r27,8
	r29.s64 = r27.s64 + 8;
	// addi r28,r11,9372
	r28.s64 = r11.s64 + 9372;
loc_823983B4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823983C8;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r29,r31
	ctx.r6.u64 = r29.u64 + r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x823983E4;
	sub_824DF200(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,7
	cr6.compare<int32_t>(r31.s32, 7, xer);
	// blt cr6,0x823983b4
	if (cr6.lt) goto loc_823983B4;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r31,0
	r31.s64 = 0;
	// addi r28,r27,15
	r28.s64 = r27.s64 + 15;
	// addi r29,r11,9356
	r29.s64 = r11.s64 + 9356;
loc_82398400:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82398414;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r28,r31
	ctx.r6.u64 = r28.u64 + r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82398430;
	sub_824DF200(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x82398400
	if (cr6.lt) goto loc_82398400;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r31,0
	r31.s64 = 0;
	// addi r28,r27,17
	r28.s64 = r27.s64 + 17;
	// addi r29,r11,9336
	r29.s64 = r11.s64 + 9336;
loc_8239844C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82398460;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r28,r31
	ctx.r6.u64 = r28.u64 + r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8239847C;
	sub_824DF200(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x8239844c
	if (cr6.lt) goto loc_8239844C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,9320
	ctx.r5.s64 = r11.s64 + 9320;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823984A0;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r27,19
	ctx.r6.s64 = r27.s64 + 19;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x823984BC;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r10,9308
	ctx.r5.s64 = ctx.r10.s64 + 9308;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823984D4;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r27,20
	ctx.r6.s64 = r27.s64 + 20;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x823984F0;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r27,21
	r29.s64 = r27.s64 + 21;
	// addi r28,r11,9288
	r28.s64 = r11.s64 + 9288;
loc_82398500:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,80
	ctx.r4.s64 = 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82398514;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r29,r31
	ctx.r6.u64 = r29.u64 + r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82398530;
	sub_824DF200(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x82398500
	if (cr6.lt) goto loc_82398500;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82398544"))) PPC_WEAK_FUNC(sub_82398544);
PPC_FUNC_IMPL(__imp__sub_82398544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398548"))) PPC_WEAK_FUNC(sub_82398548);
PPC_FUNC_IMPL(__imp__sub_82398548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,4
	r11.s64 = 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82398564"))) PPC_WEAK_FUNC(sub_82398564);
PPC_FUNC_IMPL(__imp__sub_82398564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398568"))) PPC_WEAK_FUNC(sub_82398568);
PPC_FUNC_IMPL(__imp__sub_82398568) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// bl 0x82387b90
	ctx.lr = 0x82398588;
	sub_82387B90(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8238b048
	ctx.lr = 0x82398598;
	sub_8238B048(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b128
	ctx.lr = 0x823985A4;
	sub_8238B128(ctx, base);
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

__attribute__((alias("__imp__sub_823985BC"))) PPC_WEAK_FUNC(sub_823985BC);
PPC_FUNC_IMPL(__imp__sub_823985BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823985C0"))) PPC_WEAK_FUNC(sub_823985C0);
PPC_FUNC_IMPL(__imp__sub_823985C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// stb r11,22(r3)
	PPC_STORE_U8(ctx.r3.u32 + 22, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823985EC"))) PPC_WEAK_FUNC(sub_823985EC);
PPC_FUNC_IMPL(__imp__sub_823985EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823985F0"))) PPC_WEAK_FUNC(sub_823985F0);
PPC_FUNC_IMPL(__imp__sub_823985F0) {
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
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82387b90
	ctx.lr = 0x82398608;
	sub_82387B90(ctx, base);
	// addi r11,r31,297
	r11.s64 = r31.s64 + 297;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82398628"))) PPC_WEAK_FUNC(sub_82398628);
PPC_FUNC_IMPL(__imp__sub_82398628) {
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
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82387b90
	ctx.lr = 0x82398640;
	sub_82387B90(ctx, base);
	// addi r11,r31,298
	r11.s64 = r31.s64 + 298;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82398660"))) PPC_WEAK_FUNC(sub_82398660);
PPC_FUNC_IMPL(__imp__sub_82398660) {
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
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82387b90
	ctx.lr = 0x82398678;
	sub_82387B90(ctx, base);
	// addi r11,r31,299
	r11.s64 = r31.s64 + 299;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82398698"))) PPC_WEAK_FUNC(sub_82398698);
PPC_FUNC_IMPL(__imp__sub_82398698) {
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
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82387b90
	ctx.lr = 0x823986B0;
	sub_82387B90(ctx, base);
	// addi r11,r31,303
	r11.s64 = r31.s64 + 303;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823986D0"))) PPC_WEAK_FUNC(sub_823986D0);
PPC_FUNC_IMPL(__imp__sub_823986D0) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x823986F4;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x82398700;
	sub_821C9790(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8239871C"))) PPC_WEAK_FUNC(sub_8239871C);
PPC_FUNC_IMPL(__imp__sub_8239871C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398720"))) PPC_WEAK_FUNC(sub_82398720);
PPC_FUNC_IMPL(__imp__sub_82398720) {
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
	// rlwinm r11,r31,6,0,25
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82130528
	ctx.lr = 0x82398740;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239876c
	if (!cr6.gt) goto loc_8239876C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82398750:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398760
	if (cr6.eq) goto loc_82398760;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_82398760:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,65
	r11.s64 = r11.s64 + 65;
	// bne 0x82398750
	if (!cr0.eq) goto loc_82398750;
loc_8239876C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82398780"))) PPC_WEAK_FUNC(sub_82398780);
PPC_FUNC_IMPL(__imp__sub_82398780) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82398788;
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// addi r11,r22,36
	r11.s64 = r22.s64 + 36;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
	// bl 0x82237920
	ctx.lr = 0x823987C4;
	sub_82237920(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238efe8
	ctx.lr = 0x823987CC;
	sub_8238EFE8(ctx, base);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r26,r31
	r26.u64 = r31.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82398954
	if (cr6.eq) goto loc_82398954;
	// lwz r24,88(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r21,1
	r21.s64 = 1;
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823987EC:
	// lwz r31,4(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239c698
	ctx.lr = 0x823987F8;
	sub_8239C698(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x82398808;
	sub_821C9790(ctx, base);
	// bl 0x82396fb8
	ctx.lr = 0x8239880C;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82398848
	if (cr6.eq) goto loc_82398848;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// slw r10,r21,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r21.u32 << (r11.u8 & 0x3F));
	// and r9,r10,r23
	ctx.r9.u64 = ctx.r10.u64 & r23.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82398848
	if (!cr6.eq) goto loc_82398848;
	// cmpwi cr6,r23,-1
	cr6.compare<int32_t>(r23.s32, -1, xer);
	// beq cr6,0x82398848
	if (cr6.eq) goto loc_82398848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x82398838;
	sub_82186D30(ctx, base);
	// lwz r24,88(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8239894c
	goto loc_8239894C;
loc_82398848:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823988f8
	if (cr6.eq) goto loc_823988F8;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239c548
	ctx.lr = 0x82398860;
	sub_8239C548(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82398980
	if (!cr6.eq) goto loc_82398980;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823988dc
	if (cr6.eq) goto loc_823988DC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8239c698
	ctx.lr = 0x8239887C;
	sub_8239C698(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239c080
	ctx.lr = 0x82398890;
	sub_8239C080(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8239c660
	ctx.lr = 0x823988A0;
	sub_8239C660(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8239c660
	ctx.lr = 0x823988B4;
	sub_8239C660(ctx, base);
	// subf r11,r27,r3
	r11.s64 = ctx.r3.s64 - r27.s64;
	// subf r10,r27,r18
	ctx.r10.s64 = r18.s64 - r27.s64;
	// srawi r9,r11,31
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = r11.s32 >> 31;
	// srawi r8,r10,31
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 31;
	// xor r7,r11,r9
	ctx.r7.u64 = r11.u64 ^ ctx.r9.u64;
	// xor r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// subf r5,r9,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r9.s64;
	// subf r4,r8,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r8.s64;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// bge cr6,0x823988f8
	if (!cr6.lt) goto loc_823988F8;
loc_823988DC:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
	// bl 0x8239c080
	ctx.lr = 0x823988F0;
	sub_8239C080(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// stw r26,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r26.u32);
loc_823988F8:
	// lwz r29,8(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bne cr6,0x823987ec
	if (!cr6.eq) goto loc_823987EC;
	// lhz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
loc_82398914:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82398944
	if (!cr6.lt) goto loc_82398944;
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r29,r8,r11
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82398914
	if (cr6.eq) goto loc_82398914;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// b 0x823987ec
	goto loc_823987EC;
loc_82398944:
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8239894C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823987ec
	if (!cr6.eq) goto loc_823987EC;
loc_82398954:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8238ea78
	ctx.lr = 0x8239895C;
	sub_8238EA78(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,10264
	ctx.r3.s64 = r11.s64 + 10264;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x82398970;
	sub_82130000(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82398980:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823989a0
	if (cr6.eq) goto loc_823989A0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239c080
	ctx.lr = 0x8239899C;
	sub_8239C080(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
loc_823989A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_823989B0"))) PPC_WEAK_FUNC(sub_823989B0);
PPC_FUNC_IMPL(__imp__sub_823989B0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x823989B8;
	// stfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r19,r8
	r19.u64 = ctx.r8.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823989f0
	if (cr6.eq) goto loc_823989F0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8238efe8
	ctx.lr = 0x823989EC;
	sub_8238EFE8(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_823989F0:
	// li r31,0
	r31.s64 = 0;
	// addi r11,r20,36
	r11.s64 = r20.s64 + 36;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r25,r31
	r25.u64 = r31.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x82398A10;
	sub_82237920(ctx, base);
	// mr r27,r31
	r27.u64 = r31.u64;
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82398ba4
	if (cr6.eq) goto loc_82398BA4;
	// lwz r24,88(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r21,1
	r21.s64 = 1;
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82398A2C:
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239c698
	ctx.lr = 0x82398A38;
	sub_8239C698(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x82398A48;
	sub_821C9790(ctx, base);
	// bl 0x82396fb8
	ctx.lr = 0x82398A4C;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82398a88
	if (cr6.eq) goto loc_82398A88;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// slw r10,r21,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r21.u32 << (r11.u8 & 0x3F));
	// and r9,r10,r22
	ctx.r9.u64 = ctx.r10.u64 & r22.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82398a88
	if (!cr6.eq) goto loc_82398A88;
	// cmpwi cr6,r22,-1
	cr6.compare<int32_t>(r22.s32, -1, xer);
	// beq cr6,0x82398a88
	if (cr6.eq) goto loc_82398A88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x82398A78;
	sub_82186D30(ctx, base);
	// lwz r24,88(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82398b9c
	goto loc_82398B9C;
loc_82398A88:
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82398A90:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82398ab4
	if (cr6.eq) goto loc_82398AB4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82398a90
	if (cr6.eq) goto loc_82398A90;
loc_82398AB4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82398bd4
	if (cr6.eq) goto loc_82398BD4;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82398b2c
	if (cr6.eq) goto loc_82398B2C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8239c698
	ctx.lr = 0x82398ACC;
	sub_8239C698(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239c080
	ctx.lr = 0x82398AE0;
	sub_8239C080(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8239c660
	ctx.lr = 0x82398AF0;
	sub_8239C660(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8239c660
	ctx.lr = 0x82398B04;
	sub_8239C660(ctx, base);
	// subf r11,r26,r3
	r11.s64 = ctx.r3.s64 - r26.s64;
	// subf r10,r26,r17
	ctx.r10.s64 = r17.s64 - r26.s64;
	// srawi r9,r11,31
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = r11.s32 >> 31;
	// srawi r8,r10,31
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 31;
	// xor r7,r11,r9
	ctx.r7.u64 = r11.u64 ^ ctx.r9.u64;
	// xor r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// subf r5,r9,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r9.s64;
	// subf r4,r8,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r8.s64;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// bge cr6,0x82398b48
	if (!cr6.lt) goto loc_82398B48;
loc_82398B2C:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
	// bl 0x8239c080
	ctx.lr = 0x82398B40;
	sub_8239C080(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r27.u32);
loc_82398B48:
	// lwz r28,8(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// bne cr6,0x82398a2c
	if (!cr6.eq) goto loc_82398A2C;
	// lhz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
loc_82398B64:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82398b94
	if (!cr6.lt) goto loc_82398B94;
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r28,r11,r8
	r28.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82398b64
	if (cr6.eq) goto loc_82398B64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// b 0x82398a2c
	goto loc_82398A2C;
loc_82398B94:
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
loc_82398B9C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82398a2c
	if (!cr6.eq) goto loc_82398A2C;
loc_82398BA4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8238ea78
	ctx.lr = 0x82398BAC;
	sub_8238EA78(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r11,10400
	ctx.r3.s64 = r11.s64 + 10400;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x82130000
	ctx.lr = 0x82398BC4;
	sub_82130000(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_82398BD4:
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398bf4
	if (cr6.eq) goto loc_82398BF4;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239c080
	ctx.lr = 0x82398BF0;
	sub_8239C080(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
loc_82398BF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_82398C04"))) PPC_WEAK_FUNC(sub_82398C04);
PPC_FUNC_IMPL(__imp__sub_82398C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398C08"))) PPC_WEAK_FUNC(sub_82398C08);
PPC_FUNC_IMPL(__imp__sub_82398C08) {
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
	ctx.lr = 0x82398C10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r11,r28,36
	r11.s64 = r28.s64 + 36;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x82398C34;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82398c98
	if (cr6.eq) goto loc_82398C98;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82398C48:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x8239ca18
	ctx.lr = 0x82398C50;
	sub_8239CA18(ctx, base);
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82398c48
	if (!cr6.eq) goto loc_82398C48;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82398C68:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82398c90
	if (!cr6.lt) goto loc_82398C90;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r8,r11
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82398c68
	if (cr6.eq) goto loc_82398C68;
	// b 0x82398c48
	goto loc_82398C48;
loc_82398C90:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82398c48
	if (!cr6.eq) goto loc_82398C48;
loc_82398C98:
	// stb r27,48(r28)
	PPC_STORE_U8(r28.u32 + 48, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82398CA4"))) PPC_WEAK_FUNC(sub_82398CA4);
PPC_FUNC_IMPL(__imp__sub_82398CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398CA8"))) PPC_WEAK_FUNC(sub_82398CA8);
PPC_FUNC_IMPL(__imp__sub_82398CA8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82398CB0;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r26,r11,10740
	r26.s64 = r11.s64 + 10740;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821cff40
	ctx.lr = 0x82398CD4;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398e50
	if (cr6.eq) goto loc_82398E50;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r31,36
	r27.s64 = r31.s64 + 36;
	// li r28,0
	r28.s64 = 0;
	// li r22,3
	r22.s64 = 3;
	// addi r23,r9,-29628
	r23.s64 = ctx.r9.s64 + -29628;
	// addi r25,r10,9848
	r25.s64 = ctx.r10.s64 + 9848;
	// addi r24,r11,-29624
	r24.s64 = r11.s64 + -29624;
loc_82398D04:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821cfe20
	ctx.lr = 0x82398D10;
	sub_821CFE20(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d0898
	ctx.lr = 0x82398D1C;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821cfe20
	ctx.lr = 0x82398D28;
	sub_821CFE20(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82398D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x82398D50;
	sub_821C9790(ctx, base);
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398db4
	if (cr6.eq) goto loc_82398DB4;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398db4
	if (cr6.eq) goto loc_82398DB4;
loc_82398D80:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x82398d9c
	if (cr6.eq) goto loc_82398D9C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82398d80
	if (!cr6.eq) goto loc_82398D80;
	// b 0x82398db4
	goto loc_82398DB4;
loc_82398D9C:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82398db4
	if (cr6.eq) goto loc_82398DB4;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82398e1c
	if (!cr6.eq) goto loc_82398E1C;
loc_82398DB4:
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x82398DBC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82398dfc
	if (cr6.eq) goto loc_82398DFC;
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r28,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r28.u16);
	// addi r29,r31,68
	r29.s64 = r31.s64 + 68;
	// sth r28,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r28.u16);
	// stb r28,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r28.u8);
	// bl 0x8239c9c8
	ctx.lr = 0x82398DE4;
	sub_8239C9C8(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82398720
	ctx.lr = 0x82398DF0;
	sub_82398720(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// sth r22,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r22.u16);
	// b 0x82398e00
	goto loc_82398E00;
loc_82398DFC:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82398E00:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x82398E1C;
	sub_82389998(ctx, base);
loc_82398E1C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239cca8
	ctx.lr = 0x82398E28;
	sub_8239CCA8(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d0898
	ctx.lr = 0x82398E34;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x82398E44;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82398d04
	if (!cr6.eq) goto loc_82398D04;
loc_82398E50:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82398E58"))) PPC_WEAK_FUNC(sub_82398E58);
PPC_FUNC_IMPL(__imp__sub_82398E58) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x82398ebc
	if (cr6.eq) goto loc_82398EBC;
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
	// bl 0x82398780
	ctx.lr = 0x82398EA0;
	sub_82398780(ctx, base);
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
loc_82398EBC:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,10536
	ctx.r3.s64 = r11.s64 + 10536;
	// bl 0x82130000
	ctx.lr = 0x82398EC8;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82398EE8"))) PPC_WEAK_FUNC(sub_82398EE8);
PPC_FUNC_IMPL(__imp__sub_82398EE8) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x82398f50
	if (cr6.eq) goto loc_82398F50;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// bl 0x823989b0
	ctx.lr = 0x82398F34;
	sub_823989B0(ctx, base);
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
loc_82398F50:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,10632
	ctx.r3.s64 = r11.s64 + 10632;
	// bl 0x82130000
	ctx.lr = 0x82398F5C;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82398F7C"))) PPC_WEAK_FUNC(sub_82398F7C);
PPC_FUNC_IMPL(__imp__sub_82398F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82398F80"))) PPC_WEAK_FUNC(sub_82398F80);
PPC_FUNC_IMPL(__imp__sub_82398F80) {
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
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-29096
	ctx.r4.s64 = r11.s64 + -29096;
	// addi r3,r10,10828
	ctx.r3.s64 = ctx.r10.s64 + 10828;
	// bl 0x82554798
	ctx.lr = 0x82398FA0;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-28952
	ctx.r4.s64 = ctx.r9.s64 + -28952;
	// addi r3,r8,10776
	ctx.r3.s64 = ctx.r8.s64 + 10776;
	// bl 0x82554798
	ctx.lr = 0x82398FB4;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-12200
	ctx.r4.s64 = ctx.r7.s64 + -12200;
	// addi r3,r6,10744
	ctx.r3.s64 = ctx.r6.s64 + 10744;
	// bl 0x82554798
	ctx.lr = 0x82398FC8;
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

__attribute__((alias("__imp__sub_82398FD8"))) PPC_WEAK_FUNC(sub_82398FD8);
PPC_FUNC_IMPL(__imp__sub_82398FD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lfs f11,29500(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29500);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,11536(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11536);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r3,76
	r11.s64 = ctx.r3.s64 + 76;
	// lfs f8,-17424(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -17424);
	ctx.f8.f64 = double(temp.f32);
	// li r10,7
	ctx.r10.s64 = 7;
	// lfs f12,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,31020(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31020);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,-32032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -32032);
	ctx.f7.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f8,16(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f11,20(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f10,24(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f12,52(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f9,56(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f7,60(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f9,64(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
loc_8239906C:
	// stfs f12,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239906c
	if (!cr0.eq) goto loc_8239906C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82399084"))) PPC_WEAK_FUNC(sub_82399084);
PPC_FUNC_IMPL(__imp__sub_82399084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82399088"))) PPC_WEAK_FUNC(sub_82399088);
PPC_FUNC_IMPL(__imp__sub_82399088) {
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
	// li r3,140
	ctx.r3.s64 = 140;
	// bl 0x82130528
	ctx.lr = 0x8239909C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823990b8
	if (cr6.eq) goto loc_823990B8;
	// bl 0x82398fd8
	ctx.lr = 0x823990A8;
	sub_82398FD8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823990B8:
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

__attribute__((alias("__imp__sub_823990CC"))) PPC_WEAK_FUNC(sub_823990CC);
PPC_FUNC_IMPL(__imp__sub_823990CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823990D0"))) PPC_WEAK_FUNC(sub_823990D0);
PPC_FUNC_IMPL(__imp__sub_823990D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-12044(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12044);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823990DC"))) PPC_WEAK_FUNC(sub_823990DC);
PPC_FUNC_IMPL(__imp__sub_823990DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823990E0"))) PPC_WEAK_FUNC(sub_823990E0);
PPC_FUNC_IMPL(__imp__sub_823990E0) {
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
	ctx.lr = 0x823990E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,-12044
	r31.s64 = r11.s64 + -12044;
	// lwz r11,-12044(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12044);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82399328
	if (!cr6.eq) goto loc_82399328;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82399108;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239911c
	if (cr6.eq) goto loc_8239911C;
	// bl 0x821d5408
	ctx.lr = 0x82399118;
	sub_821D5408(ctx, base);
	// b 0x82399120
	goto loc_82399120;
loc_8239911C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82399120:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32198
	r11.s64 = -2110128128;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,11540
	ctx.r7.s64 = ctx.r10.s64 + 11540;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-28464
	ctx.r9.s64 = r11.s64 + -28464;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,140
	ctx.r5.s64 = 140;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32129
	ctx.r3.s64 = -2105606144;
	// addi r4,r8,-28536
	ctx.r4.s64 = ctx.r8.s64 + -28536;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-25692
	ctx.r9.s64 = ctx.r3.s64 + -25692;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,-25668
	ctx.r8.s64 = ctx.r10.s64 + -25668;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32129
	ctx.r5.s64 = -2105606144;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r6,r5,-25644
	ctx.r6.s64 = ctx.r5.s64 + -25644;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32129
	ctx.r4.s64 = -2105606144;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r5,r4,-25620
	ctx.r5.s64 = ctx.r4.s64 + -25620;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,-25596
	ctx.r4.s64 = ctx.r7.s64 + -25596;
	// addi r6,r8,-25572
	ctx.r6.s64 = ctx.r8.s64 + -25572;
	// li r11,12
	r11.s64 = 12;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-25548
	ctx.r5.s64 = ctx.r7.s64 + -25548;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-25524
	ctx.r4.s64 = r30.s64 + -25524;
	// addi r6,r8,-25500
	ctx.r6.s64 = ctx.r8.s64 + -25500;
	// li r11,24
	r11.s64 = 24;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-25476
	ctx.r5.s64 = ctx.r7.s64 + -25476;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-25452
	ctx.r4.s64 = r30.s64 + -25452;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// lis r30,-32129
	r30.s64 = -2105606144;
	// addi r6,r8,-25428
	ctx.r6.s64 = ctx.r8.s64 + -25428;
	// li r11,36
	r11.s64 = 36;
	// li r10,40
	ctx.r10.s64 = 40;
	// addi r8,r7,-25404
	ctx.r8.s64 = ctx.r7.s64 + -25404;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,-25380
	ctx.r7.s64 = r30.s64 + -25380;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,44
	ctx.r9.s64 = 44;
	// li r11,48
	r11.s64 = 48;
	// li r10,52
	ctx.r10.s64 = 52;
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
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r9,r6,-25356
	ctx.r9.s64 = ctx.r6.s64 + -25356;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// li r11,56
	r11.s64 = 56;
	// addi r6,r10,-25332
	ctx.r6.s64 = ctx.r10.s64 + -25332;
	// addi r8,r8,-25308
	ctx.r8.s64 = ctx.r8.s64 + -25308;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r7,r7,-25284
	ctx.r7.s64 = ctx.r7.s64 + -25284;
	// li r10,60
	ctx.r10.s64 = 60;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r11,68
	r11.s64 = 68;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32129
	r29.s64 = -2105606144;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32129
	r28.s64 = -2105606144;
	// addi r6,r30,-25260
	ctx.r6.s64 = r30.s64 + -25260;
	// addi r8,r29,-25096
	ctx.r8.s64 = r29.s64 + -25096;
	// addi r7,r28,-25048
	ctx.r7.s64 = r28.s64 + -25048;
	// li r10,72
	ctx.r10.s64 = 72;
	// li r9,76
	ctx.r9.s64 = 76;
	// li r11,108
	r11.s64 = 108;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x823992D4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x823992E4;
	sub_821D4100(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82399300;
	sub_821D41D0(ctx, base);
	// lis r4,-32129
	ctx.r4.s64 = -2105606144;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r4,-25184
	ctx.r4.s64 = ctx.r4.s64 + -25184;
	// bl 0x821d4b00
	ctx.lr = 0x82399310;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x82399328;
	sub_821C0548(ctx, base);
loc_82399328:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82399330"))) PPC_WEAK_FUNC(sub_82399330);
PPC_FUNC_IMPL(__imp__sub_82399330) {
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
	ctx.lr = 0x82399338;
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r11,207(r1)
	PPC_STORE_U8(ctx.r1.u32 + 207, r11.u8);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// addi r5,r10,-6232
	ctx.r5.s64 = ctx.r10.s64 + -6232;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82399370;
	sub_821CA6A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82399474
	if (cr6.eq) goto loc_82399474;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d1cd0
	ctx.lr = 0x82399384;
	sub_821D1CD0(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x82399394;
	sub_821CF7B8(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82399464
	if (!cr6.gt) goto loc_82399464;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// subf r26,r30,r28
	r26.s64 = r28.s64 - r30.s64;
	// addi r28,r11,-29628
	r28.s64 = r11.s64 + -29628;
	// addi r27,r10,-29624
	r27.s64 = ctx.r10.s64 + -29624;
loc_823993B0:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwzx r31,r26,r30
	r31.u64 = PPC_LOAD_U32(r26.u32 + r30.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821d0898
	ctx.lr = 0x823993C0;
	sub_821D0898(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x823993CC;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe80
	ctx.lr = 0x823993DC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239944c
	if (!cr6.eq) goto loc_8239944C;
loc_823993E8:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cffe8
	ctx.lr = 0x82399400;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823993e8
	if (cr6.eq) goto loc_823993E8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82399430
	if (cr6.eq) goto loc_82399430;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x82399430;
	sub_821D2A58(ctx, base);
loc_82399430:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe80
	ctx.lr = 0x82399440;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823993e8
	if (cr6.eq) goto loc_823993E8;
loc_8239944C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x82399458;
	sub_821D0898(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x823993b0
	if (!cr0.eq) goto loc_823993B0;
loc_82399464:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821be610
	ctx.lr = 0x8239946C;
	sub_821BE610(ctx, base);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d923c
	return;
loc_82399474:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,12304
	ctx.r3.s64 = r11.s64 + 12304;
	// bl 0x82130000
	ctx.lr = 0x82399484;
	sub_82130000(ctx, base);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8239948C"))) PPC_WEAK_FUNC(sub_8239948C);
PPC_FUNC_IMPL(__imp__sub_8239948C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82399490"))) PPC_WEAK_FUNC(sub_82399490);
PPC_FUNC_IMPL(__imp__sub_82399490) {
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
	ctx.lr = 0x82399498;
	// stwu r1,-976(r1)
	ea = -976 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r10,207(r1)
	PPC_STORE_U8(ctx.r1.u32 + 207, ctx.r10.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r26,r11,30576
	r26.s64 = r11.s64 + 30576;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r4,r9,12364
	ctx.r4.s64 = ctx.r9.s64 + 12364;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ca540
	ctx.lr = 0x823994C0;
	sub_821CA540(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r31,r11,12348
	r31.s64 = r11.s64 + 12348;
	// addi r5,r8,-6232
	ctx.r5.s64 = ctx.r8.s64 + -6232;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x823994E4;
	sub_821CA6A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82399604
	if (cr6.eq) goto loc_82399604;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d1cd0
	ctx.lr = 0x823994F8;
	sub_821D1CD0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x82399508;
	sub_821CF7B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,12340
	ctx.r4.s64 = r11.s64 + 12340;
	// bl 0x821d0898
	ctx.lr = 0x82399518;
	sub_821D0898(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r10,-29624
	ctx.r4.s64 = ctx.r10.s64 + -29624;
	// bl 0x821d0898
	ctx.lr = 0x82399528;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r25,r11,-29628
	r25.s64 = r11.s64 + -29628;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82399540;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823995e4
	if (!cr6.eq) goto loc_823995E4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r28,r11,-24404
	r28.s64 = r11.s64 + -24404;
loc_82399554:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x82399564;
	sub_821CFAA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x82399570;
	sub_821D0490(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x823995c8
	if (!cr6.gt) goto loc_823995C8;
	// addi r30,r24,472
	r30.s64 = r24.s64 + 472;
loc_82399584:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x82137a08
	ctx.lr = 0x8239959C;
	sub_82137A08(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,768
	ctx.r4.s64 = ctx.r1.s64 + 768;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x823995BC;
	sub_821D2A58(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82399584
	if (cr6.lt) goto loc_82399584;
loc_823995C8:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe80
	ctx.lr = 0x823995D8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82399554
	if (cr6.eq) goto loc_82399554;
loc_823995E4:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x823995F0;
	sub_821D0898(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x823995F8;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
loc_82399604:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239960C;
	sub_821C9A90(ctx, base);
	// addi r1,r1,976
	ctx.r1.s64 = ctx.r1.s64 + 976;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82399614"))) PPC_WEAK_FUNC(sub_82399614);
PPC_FUNC_IMPL(__imp__sub_82399614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82399618"))) PPC_WEAK_FUNC(sub_82399618);
PPC_FUNC_IMPL(__imp__sub_82399618) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82399620;
	// stwu r1,-2672(r1)
	ea = -2672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r10,271(r1)
	PPC_STORE_U8(ctx.r1.u32 + 271, ctx.r10.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r21,r11,30576
	r21.s64 = r11.s64 + 30576;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r9,12364
	ctx.r4.s64 = ctx.r9.s64 + 12364;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821ca540
	ctx.lr = 0x82399648;
	sub_821CA540(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r27,r11,-6232
	r27.s64 = r11.s64 + -6232;
	// addi r31,r10,12528
	r31.s64 = ctx.r10.s64 + 12528;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82399670;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r20,r11,-30140
	r20.s64 = r11.s64 + -30140;
	// addi r25,r10,-29628
	r25.s64 = ctx.r10.s64 + -29628;
	// addi r22,r9,-29624
	r22.s64 = ctx.r9.s64 + -29624;
	// beq cr6,0x82399758
	if (cr6.eq) goto loc_82399758;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821d1cd0
	ctx.lr = 0x8239969C;
	sub_821D1CD0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821cf7b8
	ctx.lr = 0x823996AC;
	sub_821CF7B8(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// lwz r4,-24988(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -24988);
	// bl 0x821d0898
	ctx.lr = 0x823996BC;
	sub_821D0898(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821d0898
	ctx.lr = 0x823996C8;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821cfe80
	ctx.lr = 0x823996D8;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82399740
	if (!cr6.eq) goto loc_82399740;
loc_823996E4:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821cffe8
	ctx.lr = 0x823996FC;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823996e4
	if (cr6.eq) goto loc_823996E4;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x82399724;
	sub_821D2A58(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821cfe80
	ctx.lr = 0x82399734;
	sub_821CFE80(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823996e4
	if (cr6.eq) goto loc_823996E4;
loc_82399740:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,1456
	ctx.r3.s64 = ctx.r1.s64 + 1456;
	// bl 0x821d0898
	ctx.lr = 0x8239974C;
	sub_821D0898(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x82399754;
	sub_821BE610(ctx, base);
	// stw r20,1456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1456, r20.u32);
loc_82399758:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r26,r11,12512
	r26.s64 = r11.s64 + 12512;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82399778;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8239989c
	if (cr6.eq) goto loc_8239989C;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821d1cd0
	ctx.lr = 0x8239978C;
	sub_821D1CD0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cf7b8
	ctx.lr = 0x8239979C;
	sub_821CF7B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,12508
	ctx.r8.s64 = r11.s64 + 12508;
	// addi r7,r10,12500
	ctx.r7.s64 = ctx.r10.s64 + 12500;
	// addi r6,r9,12492
	ctx.r6.s64 = ctx.r9.s64 + 12492;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r5,r29,8
	ctx.r5.s64 = r29.s64 + 8;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// addi r3,r29,24
	ctx.r3.s64 = r29.s64 + 24;
	// stw r5,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r5.u32);
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
loc_823997DC:
	// addi r11,r1,120
	r11.s64 = ctx.r1.s64 + 120;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwzx r4,r30,r10
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// bl 0x821d0898
	ctx.lr = 0x823997F4;
	sub_821D0898(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821d0898
	ctx.lr = 0x82399800;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cfe80
	ctx.lr = 0x82399810;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82399878
	if (!cr6.eq) goto loc_82399878;
loc_8239981C:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x82399834;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239981c
	if (cr6.eq) goto loc_8239981C;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8239985C;
	sub_821D2A58(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cfe80
	ctx.lr = 0x8239986C;
	sub_821CFE80(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8239981c
	if (cr6.eq) goto loc_8239981C;
loc_82399878:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821d0898
	ctx.lr = 0x82399884;
	sub_821D0898(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,12
	cr6.compare<int32_t>(r30.s32, 12, xer);
	// blt cr6,0x823997dc
	if (cr6.lt) goto loc_823997DC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x82399898;
	sub_821BE610(ctx, base);
	// stw r20,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r20.u32);
loc_8239989C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r29,480
	ctx.r10.s64 = r29.s64 + 480;
	// addi r9,r11,12480
	ctx.r9.s64 = r11.s64 + 12480;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r8,12456
	ctx.r4.s64 = ctx.r8.s64 + 12456;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82399330
	ctx.lr = 0x823998CC;
	sub_82399330(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r31,r11,12440
	r31.s64 = r11.s64 + 12440;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x823998EC;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823999c0
	if (cr6.eq) goto loc_823999C0;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821d1cd0
	ctx.lr = 0x82399900;
	sub_821D1CD0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821cf7b8
	ctx.lr = 0x82399910;
	sub_821CF7B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// addi r4,r11,12428
	ctx.r4.s64 = r11.s64 + 12428;
	// bl 0x821d0898
	ctx.lr = 0x82399920;
	sub_821D0898(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821d0898
	ctx.lr = 0x8239992C;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821cfe80
	ctx.lr = 0x8239993C;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823999a8
	if (!cr6.eq) goto loc_823999A8;
	// addi r31,r29,56
	r31.s64 = r29.s64 + 56;
loc_8239994C:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821cffe8
	ctx.lr = 0x82399964;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239994c
	if (cr6.eq) goto loc_8239994C;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8239998C;
	sub_821D2A58(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821cfe80
	ctx.lr = 0x8239999C;
	sub_821CFE80(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8239994c
	if (cr6.eq) goto loc_8239994C;
loc_823999A8:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x821d0898
	ctx.lr = 0x823999B4;
	sub_821D0898(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x823999BC;
	sub_821BE610(ctx, base);
	// stw r20,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, r20.u32);
loc_823999C0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r11,2440
	ctx.r4.s64 = r11.s64 + 2440;
	// addi r3,r10,2428
	ctx.r3.s64 = ctx.r10.s64 + 2428;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// addi r11,r9,2400
	r11.s64 = ctx.r9.s64 + 2400;
	// addi r10,r8,12416
	ctx.r10.s64 = ctx.r8.s64 + 12416;
	// addi r9,r7,2448
	ctx.r9.s64 = ctx.r7.s64 + 2448;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r8,r6,12408
	ctx.r8.s64 = ctx.r6.s64 + 12408;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r4,r5,11804
	ctx.r4.s64 = ctx.r5.s64 + 11804;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// bl 0x821ca540
	ctx.lr = 0x82399A18;
	sub_821CA540(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r7,12392
	ctx.r4.s64 = ctx.r7.s64 + 12392;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82399A34;
	sub_821CA6A8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82399b48
	if (cr6.eq) goto loc_82399B48;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// bl 0x821d1cd0
	ctx.lr = 0x82399A48;
	sub_821D1CD0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// bl 0x821cf7b8
	ctx.lr = 0x82399A58;
	sub_821CF7B8(ctx, base);
	// addi r28,r29,680
	r28.s64 = r29.s64 + 680;
	// addi r27,r29,688
	r27.s64 = r29.s64 + 688;
	// addi r26,r1,96
	r26.s64 = ctx.r1.s64 + 96;
	// li r24,6
	r24.s64 = 6;
loc_82399A68:
	// lwz r31,0(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82399A78;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// bl 0x821d0490
	ctx.lr = 0x82399A84;
	sub_821D0490(ctx, base);
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r9.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x82399AA8;
	sub_821D2A58(ctx, base);
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// sth r7,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r7.u16);
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d0898
	ctx.lr = 0x82399ACC;
	sub_821D0898(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82399b24
	if (!cr6.gt) goto loc_82399B24;
loc_82399AD8:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// bl 0x821cffe8
	ctx.lr = 0x82399AF0;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82399ad8
	if (cr6.eq) goto loc_82399AD8;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x82399B18;
	sub_821D2A58(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82399ad8
	if (cr6.lt) goto loc_82399AD8;
loc_82399B24:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// bl 0x821d0898
	ctx.lr = 0x82399B30;
	sub_821D0898(ctx, base);
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82399a68
	if (!cr0.eq) goto loc_82399A68;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821be610
	ctx.lr = 0x82399B44;
	sub_821BE610(ctx, base);
	// stw r20,2016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2016, r20.u32);
loc_82399B48:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82399B50;
	sub_821C9A90(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82399B58;
	sub_821C9A90(ctx, base);
	// addi r1,r1,2672
	ctx.r1.s64 = ctx.r1.s64 + 2672;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82399B60"))) PPC_WEAK_FUNC(sub_82399B60);
PPC_FUNC_IMPL(__imp__sub_82399B60) {
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
	ctx.lr = 0x82399B68;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82399da8
	if (cr6.eq) goto loc_82399DA8;
	// cmpwi cr6,r29,54
	cr6.compare<int32_t>(r29.s32, 54, xer);
	// bge cr6,0x82399da8
	if (!cr6.lt) goto loc_82399DA8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x82399da8
	if (cr6.lt) goto loc_82399DA8;
	// addi r9,r31,64
	ctx.r9.s64 = r31.s64 + 64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// addi r8,r31,40
	ctx.r8.s64 = r31.s64 + 40;
	// addi r7,r31,48
	ctx.r7.s64 = r31.s64 + 48;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// addi r4,r31,496
	ctx.r4.s64 = r31.s64 + 496;
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// addi r3,r31,504
	ctx.r3.s64 = r31.s64 + 504;
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// addi r30,r31,512
	r30.s64 = r31.s64 + 512;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// addi r28,r31,520
	r28.s64 = r31.s64 + 520;
	// stw r3,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// addi r9,r31,528
	ctx.r9.s64 = r31.s64 + 528;
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r28.u32);
	// addi r8,r31,536
	ctx.r8.s64 = r31.s64 + 536;
	// addi r7,r31,544
	ctx.r7.s64 = r31.s64 + 544;
	// stw r9,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// addi r6,r31,552
	ctx.r6.s64 = r31.s64 + 552;
	// stw r8,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r8.u32);
	// addi r4,r31,560
	ctx.r4.s64 = r31.s64 + 560;
	// stw r7,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r7.u32);
	// addi r3,r31,568
	ctx.r3.s64 = r31.s64 + 568;
	// stw r6,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// addi r30,r31,576
	r30.s64 = r31.s64 + 576;
	// stw r4,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r4.u32);
	// addi r28,r31,488
	r28.s64 = r31.s64 + 488;
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// addi r9,r31,624
	ctx.r9.s64 = r31.s64 + 624;
	// stw r30,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r30.u32);
	// addi r8,r31,632
	ctx.r8.s64 = r31.s64 + 632;
	// stw r28,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r28.u32);
	// addi r7,r31,640
	ctx.r7.s64 = r31.s64 + 640;
	// stw r9,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// addi r6,r31,608
	ctx.r6.s64 = r31.s64 + 608;
	// stw r8,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r8.u32);
	// addi r4,r31,600
	ctx.r4.s64 = r31.s64 + 600;
	// stw r7,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r7.u32);
	// addi r3,r31,584
	ctx.r3.s64 = r31.s64 + 584;
	// stw r6,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r6.u32);
	// addi r30,r31,592
	r30.s64 = r31.s64 + 592;
	// stw r4,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r4.u32);
	// addi r28,r31,648
	r28.s64 = r31.s64 + 648;
	// stw r3,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r3.u32);
	// addi r9,r31,696
	ctx.r9.s64 = r31.s64 + 696;
	// stw r30,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r30.u32);
	// addi r8,r31,704
	ctx.r8.s64 = r31.s64 + 704;
	// stw r28,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, r28.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r9,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r9.u32);
	// addi r10,r31,728
	ctx.r10.s64 = r31.s64 + 728;
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// addi r27,r31,656
	r27.s64 = r31.s64 + 656;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r7,r31,776
	ctx.r7.s64 = r31.s64 + 776;
	// stw r10,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r10.u32);
	// addi r6,r31,664
	ctx.r6.s64 = r31.s64 + 664;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r4,r31,672
	ctx.r4.s64 = r31.s64 + 672;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r3,r31,752
	ctx.r3.s64 = r31.s64 + 752;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// addi r30,r31,744
	r30.s64 = r31.s64 + 744;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// addi r28,r31,760
	r28.s64 = r31.s64 + 760;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r11.u32);
	// addi r9,r1,312
	ctx.r9.s64 = ctx.r1.s64 + 312;
	// stw r27,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r27.u32);
	// addi r8,r31,720
	ctx.r8.s64 = r31.s64 + 720;
	// stw r7,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r7.u32);
	// stw r6,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r6.u32);
	// stw r4,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r4.u32);
	// stw r10,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r10.u32);
	// stw r3,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r3.u32);
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// stw r28,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r28.u32);
	// stw r11,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, r11.u32);
	// addi r7,r31,472
	ctx.r7.s64 = r31.s64 + 472;
	// stw r11,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r11.u32);
	// addi r6,r31,768
	ctx.r6.s64 = r31.s64 + 768;
	// stw r11,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, r11.u32);
	// stw r11,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r11.u32);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stw r11,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, r11.u32);
	// stw r11,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r11.u32);
	// stw r11,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r11.u32);
	// stw r11,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r11.u32);
	// stw r8,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r8.u32);
	// stw r7,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r7.u32);
	// stw r6,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r6.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// bl 0x821378b8
	ctx.lr = 0x82399D0C;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r3,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	// bl 0x82352e48
	ctx.lr = 0x82399D28;
	sub_82352E48(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82399d94
	if (!cr6.lt) goto loc_82399D94;
	// cmpwi cr6,r29,10
	cr6.compare<int32_t>(r29.s32, 10, xer);
	// bne cr6,0x82399d78
	if (!cr6.eq) goto loc_82399D78;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,616
	ctx.r3.s64 = r31.s64 + 616;
	// bl 0x82352e48
	ctx.lr = 0x82399D4C;
	sub_82352E48(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82399d94
	if (cr6.lt) goto loc_82399D94;
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r11,4(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82399D6C;
	sub_821D2AA0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9244
	return;
loc_82399D78:
	// cmpwi cr6,r29,7
	cr6.compare<int32_t>(r29.s32, 7, xer);
	// bne cr6,0x82399d94
	if (!cr6.eq) goto loc_82399D94;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82352e48
	ctx.lr = 0x82399D90;
	sub_82352E48(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82399D94:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x82399D9C;
	sub_821D2AA0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9244
	return;
loc_82399DA8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82399DB4"))) PPC_WEAK_FUNC(sub_82399DB4);
PPC_FUNC_IMPL(__imp__sub_82399DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82399DB8"))) PPC_WEAK_FUNC(sub_82399DB8);
PPC_FUNC_IMPL(__imp__sub_82399DB8) {
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
	ctx.lr = 0x82399DC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,100
	r31.s64 = ctx.r3.s64 + 100;
	// li r29,23
	r29.s64 = 23;
loc_82399DCC:
	// lhz r30,0(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82399de4
	if (cr6.eq) goto loc_82399DE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x82399DE0;
	sub_82130528(ctx, base);
	// b 0x82399de8
	goto loc_82399DE8;
loc_82399DE4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82399DE8:
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// sth r30,194(r31)
	PPC_STORE_U16(r31.u32 + 194, r30.u16);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82399dcc
	if (!cr0.eq) goto loc_82399DCC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82399E04"))) PPC_WEAK_FUNC(sub_82399E04);
PPC_FUNC_IMPL(__imp__sub_82399E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82399E08"))) PPC_WEAK_FUNC(sub_82399E08);
PPC_FUNC_IMPL(__imp__sub_82399E08) {
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
	ctx.lr = 0x82399E10;
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82399db8
	ctx.lr = 0x82399E1C;
	sub_82399DB8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r25,r11,30576
	r25.s64 = r11.s64 + 30576;
	// addi r4,r10,12564
	ctx.r4.s64 = ctx.r10.s64 + 12564;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ca540
	ctx.lr = 0x82399E34;
	sub_821CA540(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r30,r11,12544
	r30.s64 = r11.s64 + 12544;
	// addi r5,r9,-24488
	ctx.r5.s64 = ctx.r9.s64 + -24488;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82399E58;
	sub_821CA6A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82399f6c
	if (cr6.eq) goto loc_82399F6C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x82399E6C;
	sub_821D1CD0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x82399E7C;
	sub_821CF7B8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,23416
	ctx.r4.s64 = r11.s64 + 23416;
	// bl 0x821d0898
	ctx.lr = 0x82399E8C;
	sub_821D0898(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r28,r11,-24744
	r28.s64 = r11.s64 + -24744;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r31,288
	r31.s64 = r31.s64 + 288;
	// mr r29,r28
	r29.u64 = r28.u64;
	// addi r30,r11,-29628
	r30.s64 = r11.s64 + -29628;
	// addi r26,r10,-29624
	r26.s64 = ctx.r10.s64 + -29624;
loc_82399EAC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821d0898
	ctx.lr = 0x82399EB8;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0898
	ctx.lr = 0x82399EC4;
	sub_821D0898(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cfe80
	ctx.lr = 0x82399ED4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82399f28
	if (!cr6.eq) goto loc_82399F28;
loc_82399EE0:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x82399EEC;
	sub_821D0490(ctx, base);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stbx r5,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r5.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cfe80
	ctx.lr = 0x82399F1C;
	sub_821CFE80(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82399ee0
	if (cr6.eq) goto loc_82399EE0;
loc_82399F28:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0898
	ctx.lr = 0x82399F34;
	sub_821D0898(ctx, base);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r28,92
	r11.s64 = r28.s64 + 92;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82399eac
	if (cr6.lt) goto loc_82399EAC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x82399F50;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x821c9a90
	ctx.lr = 0x82399F64;
	sub_821C9A90(ctx, base);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d923c
	return;
loc_82399F6C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,12584
	ctx.r3.s64 = r11.s64 + 12584;
	// bl 0x82130000
	ctx.lr = 0x82399F78;
	sub_82130000(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82399F80;
	sub_821C9A90(ctx, base);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82399F88"))) PPC_WEAK_FUNC(sub_82399F88);
PPC_FUNC_IMPL(__imp__sub_82399F88) {
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
	ctx.lr = 0x82399F90;
	// stwu r1,-1456(r1)
	ea = -1456 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r30,207(r1)
	PPC_STORE_U8(ctx.r1.u32 + 207, r30.u8);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-29216
	ctx.r4.s64 = ctx.r10.s64 + -29216;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x82399FB8;
	sub_821CA540(ctx, base);
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82197068
	ctx.lr = 0x82399FC4;
	sub_82197068(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r27,r10,-24488
	r27.s64 = ctx.r10.s64 + -24488;
	// addi r26,r11,12644
	r26.s64 = r11.s64 + 12644;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82399FEC;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239a118
	if (cr6.eq) goto loc_8239A118;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821d1cd0
	ctx.lr = 0x8239A000;
	sub_821D1CD0(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r25,r11,12628
	r25.s64 = r11.s64 + 12628;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x821cf7b8
	ctx.lr = 0x8239A018;
	sub_821CF7B8(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A028;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239a04c
	if (cr6.eq) goto loc_8239A04C;
loc_8239A030:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A044;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8239a030
	if (!cr6.eq) goto loc_8239A030;
loc_8239A04C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8239A054;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r11,-30140
	r29.s64 = r11.s64 + -30140;
	// stw r29,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r29.u32);
	// beq cr6,0x8239a118
	if (cr6.eq) goto loc_8239A118;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82195e48
	ctx.lr = 0x8239A074;
	sub_82195E48(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8239A094;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8239a118
	if (cr6.eq) goto loc_8239A118;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x821d1cd0
	ctx.lr = 0x8239A0A8;
	sub_821D1CD0(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x821cf7b8
	ctx.lr = 0x8239A0B8;
	sub_821CF7B8(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A0C8;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239a10c
	if (cr6.eq) goto loc_8239A10C;
loc_8239A0D0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821ca8c8
	ctx.lr = 0x8239A0E0;
	sub_821CA8C8(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821970c0
	ctx.lr = 0x8239A0EC;
	sub_821970C0(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// bl 0x821d2a58
	ctx.lr = 0x8239A0F4;
	sub_821D2A58(ctx, base);
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A104;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8239a0d0
	if (!cr6.eq) goto loc_8239A0D0;
loc_8239A10C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x8239A114;
	sub_821BE610(ctx, base);
	// stw r29,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r29.u32);
loc_8239A118:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239A120;
	sub_821C9A90(ctx, base);
	// addi r1,r1,1456
	ctx.r1.s64 = ctx.r1.s64 + 1456;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8239A128"))) PPC_WEAK_FUNC(sub_8239A128);
PPC_FUNC_IMPL(__imp__sub_8239A128) {
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
	ctx.lr = 0x8239A130;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r10,223(r1)
	PPC_STORE_U8(ctx.r1.u32 + 223, ctx.r10.u8);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r23,r11,30576
	r23.s64 = r11.s64 + 30576;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r9,-29216
	ctx.r4.s64 = ctx.r9.s64 + -29216;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821ca540
	ctx.lr = 0x8239A15C;
	sub_821CA540(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r11,12708
	r30.s64 = r11.s64 + 12708;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// bne cr6,0x8239a180
	if (!cr6.eq) goto loc_8239A180;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8239a18c
	goto loc_8239A18C;
loc_8239A180:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,12688
	ctx.r5.s64 = r11.s64 + 12688;
loc_8239A18C:
	// bl 0x82137a08
	ctx.lr = 0x8239A190;
	sub_82137A08(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r5,r11,-24488
	ctx.r5.s64 = r11.s64 + -24488;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,784
	ctx.r4.s64 = ctx.r1.s64 + 784;
	// bl 0x821ca6a8
	ctx.lr = 0x8239A1AC;
	sub_821CA6A8(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8239a5c4
	if (cr6.eq) goto loc_8239A5C4;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d1cd0
	ctx.lr = 0x8239A1C0;
	sub_821D1CD0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cf7b8
	ctx.lr = 0x8239A1D0;
	sub_821CF7B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r4,r11,12680
	ctx.r4.s64 = r11.s64 + 12680;
	// bl 0x821d0898
	ctx.lr = 0x8239A1E0;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r25,r11,-29624
	r25.s64 = r11.s64 + -29624;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x821d0898
	ctx.lr = 0x8239A1F4;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r26,r11,-29628
	r26.s64 = r11.s64 + -29628;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821cfe80
	ctx.lr = 0x8239A20C;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239a3bc
	if (!cr6.eq) goto loc_8239A3BC;
	// addi r28,r27,64
	r28.s64 = r27.s64 + 64;
loc_8239A21C:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A22C;
	sub_821CFAA8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8239A234:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8239a234
	if (!cr6.eq) goto loc_8239A234;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x8239A25C;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823da950
	ctx.lr = 0x8239A268;
	sub_823DA950(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82352e48
	ctx.lr = 0x8239A27C;
	sub_82352E48(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x821d2aa0
	ctx.lr = 0x8239A288;
	sub_821D2AA0(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bge cr6,0x8239a2ac
	if (!cr6.lt) goto loc_8239A2AC;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821970c0
	ctx.lr = 0x8239A29C;
	sub_821970C0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2a58
	ctx.lr = 0x8239A2A4;
	sub_821D2A58(ctx, base);
	// lhz r11,68(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 68);
	// addi r29,r11,-1
	r29.s64 = r11.s64 + -1;
loc_8239A2AC:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A2B8;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A2C8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239a394
	if (!cr6.eq) goto loc_8239A394;
	// addi r30,r27,72
	r30.s64 = r27.s64 + 72;
loc_8239A2D8:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A2E8;
	sub_821CFAA8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8239A2F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8239a2f0
	if (!cr6.eq) goto loc_8239A2F0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x8239A318;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823da950
	ctx.lr = 0x8239A324;
	sub_823DA950(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82352e48
	ctx.lr = 0x8239A338;
	sub_82352E48(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821d2aa0
	ctx.lr = 0x8239A34C;
	sub_821D2AA0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239a378
	if (cr6.eq) goto loc_8239A378;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821970c0
	ctx.lr = 0x8239A360;
	sub_821970C0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2a58
	ctx.lr = 0x8239A368;
	sub_821D2A58(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r27,88
	ctx.r3.s64 = r27.s64 + 88;
	// bl 0x8262e420
	ctx.lr = 0x8239A374;
	sub_8262E420(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
loc_8239A378:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A388;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a2d8
	if (cr6.eq) goto loc_8239A2D8;
loc_8239A394:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A3A0;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A3B0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a21c
	if (cr6.eq) goto loc_8239A21C;
loc_8239A3BC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A3C8;
	sub_821D0898(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r4,r11,12672
	ctx.r4.s64 = r11.s64 + 12672;
	// bl 0x821d0898
	ctx.lr = 0x8239A3D8;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A3E4;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A3F4;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239a4b0
	if (!cr6.eq) goto loc_8239A4B0;
	// addi r30,r27,40
	r30.s64 = r27.s64 + 40;
loc_8239A404:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A414;
	sub_821CFAA8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8239A41C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8239a41c
	if (!cr6.eq) goto loc_8239A41C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x8239A444;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823da950
	ctx.lr = 0x8239A450;
	sub_823DA950(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82352e48
	ctx.lr = 0x8239A464;
	sub_82352E48(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821d2aa0
	ctx.lr = 0x8239A478;
	sub_821D2AA0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239a494
	if (cr6.eq) goto loc_8239A494;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821970c0
	ctx.lr = 0x8239A48C;
	sub_821970C0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2a58
	ctx.lr = 0x8239A494;
	sub_821D2A58(ctx, base);
loc_8239A494:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A4A4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a404
	if (cr6.eq) goto loc_8239A404;
loc_8239A4B0:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A4BC;
	sub_821D0898(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r4,r11,12664
	ctx.r4.s64 = r11.s64 + 12664;
	// bl 0x821d0898
	ctx.lr = 0x8239A4CC;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A4D8;
	sub_821D0898(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A4E8;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239a5a4
	if (!cr6.eq) goto loc_8239A5A4;
	// addi r30,r27,48
	r30.s64 = r27.s64 + 48;
loc_8239A4F8:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A508;
	sub_821CFAA8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8239A510:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8239a510
	if (!cr6.eq) goto loc_8239A510;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x8239A538;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823da950
	ctx.lr = 0x8239A544;
	sub_823DA950(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82352e48
	ctx.lr = 0x8239A558;
	sub_82352E48(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821d2aa0
	ctx.lr = 0x8239A56C;
	sub_821D2AA0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239a588
	if (cr6.eq) goto loc_8239A588;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821970c0
	ctx.lr = 0x8239A580;
	sub_821970C0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2a58
	ctx.lr = 0x8239A588;
	sub_821D2A58(ctx, base);
loc_8239A588:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe80
	ctx.lr = 0x8239A598;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a4f8
	if (cr6.eq) goto loc_8239A4F8;
loc_8239A5A4:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239A5B0;
	sub_821D0898(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be610
	ctx.lr = 0x8239A5B8;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r10.u32);
loc_8239A5C4:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239A5CC;
	sub_821C9A90(ctx, base);
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8239A5D4"))) PPC_WEAK_FUNC(sub_8239A5D4);
PPC_FUNC_IMPL(__imp__sub_8239A5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239A5D8"))) PPC_WEAK_FUNC(sub_8239A5D8);
PPC_FUNC_IMPL(__imp__sub_8239A5D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8239A5E0;
	// stwu r1,-1552(r1)
	ea = -1552 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r23,0
	r23.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r23,303(r1)
	PPC_STORE_U8(ctx.r1.u32 + 303, r23.u8);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r17,r11,30576
	r17.s64 = r11.s64 + 30576;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r10,-29216
	ctx.r4.s64 = ctx.r10.s64 + -29216;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x821ca540
	ctx.lr = 0x8239A608;
	sub_821CA540(ctx, base);
	// addi r31,r25,96
	r31.s64 = r25.s64 + 96;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r30,r31
	r30.u64 = r31.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// li r10,23
	ctx.r10.s64 = 23;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8239A620:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8239a620
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8239A620;
	// li r26,23
	r26.s64 = 23;
loc_8239A630:
	// lhz r29,6(r30)
	r29.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8239a658
	if (!cr6.gt) goto loc_8239A658;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_8239A644:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239A64C;
	sub_821D2AA0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8239a644
	if (!cr0.eq) goto loc_8239A644;
loc_8239A658:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x8239A660;
	sub_82130588(ctx, base);
	// stw r23,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r23.u32);
	// sth r23,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r23.u16);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// sth r23,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r23.u16);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x8239a630
	if (!cr0.eq) goto loc_8239A630;
	// lhz r29,286(r25)
	r29.u64 = PPC_LOAD_U16(r25.u32 + 286);
	// addi r30,r25,280
	r30.s64 = r25.s64 + 280;
	// lwz r27,280(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 280);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8239a6a4
	if (!cr6.gt) goto loc_8239A6A4;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_8239A690:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239A698;
	sub_821D2AA0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8239a690
	if (!cr0.eq) goto loc_8239A690;
loc_8239A6A4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x8239A6AC;
	sub_82130588(ctx, base);
	// stw r23,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r23.u32);
	// sth r23,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r23.u16);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// sth r23,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r23.u16);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r21,r11,-24488
	r21.s64 = r11.s64 + -24488;
	// addi r22,r10,12772
	r22.s64 = ctx.r10.s64 + 12772;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8239A6E0;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8239a9d0
	if (cr6.eq) goto loc_8239A9D0;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821d1cd0
	ctx.lr = 0x8239A6F4;
	sub_821D1CD0(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821cf7b8
	ctx.lr = 0x8239A704;
	sub_821CF7B8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// mr r29,r23
	r29.u64 = r23.u64;
	// addi r24,r11,-29628
	r24.s64 = r11.s64 + -29628;
	// addi r19,r10,-29624
	r19.s64 = ctx.r10.s64 + -29624;
	// addi r18,r9,-24744
	r18.s64 = ctx.r9.s64 + -24744;
loc_8239A720:
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// lwzx r4,r29,r18
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r18.u32);
	// bl 0x821d0898
	ctx.lr = 0x8239A72C;
	sub_821D0898(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821d0898
	ctx.lr = 0x8239A738;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821d0490
	ctx.lr = 0x8239A744;
	sub_821D0490(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r3,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r3.u32);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821cfe80
	ctx.lr = 0x8239A75C;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239a794
	if (!cr6.eq) goto loc_8239A794;
loc_8239A768:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A778;
	sub_821CFAA8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821cfe80
	ctx.lr = 0x8239A788;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a768
	if (cr6.eq) goto loc_8239A768;
loc_8239A794:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821d0898
	ctx.lr = 0x8239A7A0;
	sub_821D0898(ctx, base);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r29,92
	cr6.compare<int32_t>(r29.s32, 92, xer);
	// blt cr6,0x8239a720
	if (cr6.lt) goto loc_8239A720;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x8239A7B4;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r25,r23
	r25.u64 = r23.u64;
	// addi r20,r11,-30140
	r20.s64 = r11.s64 + -30140;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// stw r20,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r20.u32);
	// mr r28,r31
	r28.u64 = r31.u64;
	// li r27,23
	r27.s64 = 23;
loc_8239A7D0:
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239a814
	if (cr6.eq) goto loc_8239A814;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239A7E4;
	sub_82130528(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8239a80c
	if (!cr6.gt) goto loc_8239A80C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8239A7F4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a800
	if (cr6.eq) goto loc_8239A800;
	// stw r23,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r23.u32);
loc_8239A800:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239a7f4
	if (!cr0.eq) goto loc_8239A7F4;
loc_8239A80C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8239a818
	goto loc_8239A818;
loc_8239A814:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8239A818:
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// sth r29,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r29.u16);
	// add r25,r29,r25
	r25.u64 = r29.u64 + r25.u64;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x8239a7d0
	if (!cr0.eq) goto loc_8239A7D0;
	// addic. r29,r25,1
	xer.ca = r25.u32 > 4294967294;
	r29.s64 = r25.s64 + 1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8239a874
	if (cr0.eq) goto loc_8239A874;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239A844;
	sub_82130528(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8239a86c
	if (!cr6.gt) goto loc_8239A86C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8239A854:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239a860
	if (cr6.eq) goto loc_8239A860;
	// stw r23,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r23.u32);
loc_8239A860:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239a854
	if (!cr0.eq) goto loc_8239A854;
loc_8239A86C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8239a878
	goto loc_8239A878;
loc_8239A874:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8239A878:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r9,12760
	ctx.r4.s64 = ctx.r9.s64 + 12760;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8239A8A4;
	sub_821D2A58(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8239A8BC;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8239a9dc
	if (cr6.eq) goto loc_8239A9DC;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821d1cd0
	ctx.lr = 0x8239A8D0;
	sub_821D1CD0(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821cf7b8
	ctx.lr = 0x8239A8E0;
	sub_821CF7B8(ctx, base);
	// mr r29,r23
	r29.u64 = r23.u64;
loc_8239A8E4:
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// lwzx r4,r29,r18
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r18.u32);
	// bl 0x821d0898
	ctx.lr = 0x8239A8F0;
	sub_821D0898(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821d0898
	ctx.lr = 0x8239A8FC;
	sub_821D0898(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821d0490
	ctx.lr = 0x8239A908;
	sub_821D0490(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r3,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r3.u32);
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821cfe80
	ctx.lr = 0x8239A920;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239a998
	if (!cr6.eq) goto loc_8239A998;
loc_8239A92C:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821cfaa8
	ctx.lr = 0x8239A93C;
	sub_821CFAA8(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8239A95C;
	sub_821D2A58(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8239A97C;
	sub_821D2A58(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821cfe80
	ctx.lr = 0x8239A98C;
	sub_821CFE80(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8239a92c
	if (cr6.eq) goto loc_8239A92C;
loc_8239A998:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x821d0898
	ctx.lr = 0x8239A9A4;
	sub_821D0898(ctx, base);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpwi cr6,r29,92
	cr6.compare<int32_t>(r29.s32, 92, xer);
	// blt cr6,0x8239a8e4
	if (cr6.lt) goto loc_8239A8E4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x8239A9BC;
	sub_821BE610(ctx, base);
	// stw r20,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, r20.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239A9C8;
	sub_821C9A90(ctx, base);
	// addi r1,r1,1552
	ctx.r1.s64 = ctx.r1.s64 + 1552;
	// b 0x823d921c
	return;
loc_8239A9D0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,12724
	ctx.r3.s64 = r11.s64 + 12724;
	// bl 0x82130000
	ctx.lr = 0x8239A9DC;
	sub_82130000(ctx, base);
loc_8239A9DC:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239A9E4;
	sub_821C9A90(ctx, base);
	// addi r1,r1,1552
	ctx.r1.s64 = ctx.r1.s64 + 1552;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8239A9EC"))) PPC_WEAK_FUNC(sub_8239A9EC);
PPC_FUNC_IMPL(__imp__sub_8239A9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239A9F0"))) PPC_WEAK_FUNC(sub_8239A9F0);
PPC_FUNC_IMPL(__imp__sub_8239A9F0) {
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
	ctx.lr = 0x8239A9F8;
	// stwu r1,-1408(r1)
	ea = -1408 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r26,r11,30576
	r26.s64 = r11.s64 + 30576;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r10,-29216
	ctx.r4.s64 = ctx.r10.s64 + -29216;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ca540
	ctx.lr = 0x8239AA18;
	sub_821CA540(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stb r9,207(r1)
	PPC_STORE_U8(ctx.r1.u32 + 207, ctx.r9.u8);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r27,r10,-24488
	r27.s64 = ctx.r10.s64 + -24488;
	// addi r30,r11,12800
	r30.s64 = r11.s64 + 12800;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8239AA4C;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r22,r8,-30140
	r22.s64 = ctx.r8.s64 + -30140;
	// addi r28,r9,-29628
	r28.s64 = ctx.r9.s64 + -29628;
	// addi r24,r10,-29624
	r24.s64 = ctx.r10.s64 + -29624;
	// addi r23,r11,12788
	r23.s64 = r11.s64 + 12788;
	// beq cr6,0x8239ab00
	if (cr6.eq) goto loc_8239AB00;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821d1cd0
	ctx.lr = 0x8239AA80;
	sub_821D1CD0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821cf7b8
	ctx.lr = 0x8239AA90;
	sub_821CF7B8(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821cfe20
	ctx.lr = 0x8239AA9C;
	sub_821CFE20(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821d0898
	ctx.lr = 0x8239AAA8;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821cfe80
	ctx.lr = 0x8239AAB8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239aaf4
	if (!cr6.eq) goto loc_8239AAF4;
loc_8239AAC4:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bl 0x821cfaa8
	ctx.lr = 0x8239AAD8;
	sub_821CFAA8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821cfe80
	ctx.lr = 0x8239AAE8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239aac4
	if (cr6.eq) goto loc_8239AAC4;
loc_8239AAF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8239AAFC;
	sub_821BE610(ctx, base);
	// stw r22,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, r22.u32);
loc_8239AB00:
	// addi r31,r25,488
	r31.s64 = r25.s64 + 488;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82197068
	ctx.lr = 0x8239AB0C;
	sub_82197068(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239ab24
	if (cr6.eq) goto loc_8239AB24;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82195e48
	ctx.lr = 0x8239AB20;
	sub_82195E48(ctx, base);
	// b 0x8239ab28
	goto loc_8239AB28;
loc_8239AB24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8239AB28:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8239AB48;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239ac14
	if (cr6.eq) goto loc_8239AC14;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d1cd0
	ctx.lr = 0x8239AB5C;
	sub_821D1CD0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x8239AB6C;
	sub_821CF7B8(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe20
	ctx.lr = 0x8239AB78;
	sub_821CFE20(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x8239AB84;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe80
	ctx.lr = 0x8239AB94;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239abfc
	if (!cr6.eq) goto loc_8239ABFC;
loc_8239ABA0:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cffe8
	ctx.lr = 0x8239ABB8;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239aba0
	if (cr6.eq) goto loc_8239ABA0;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x821d2a58
	ctx.lr = 0x8239ABE0;
	sub_821D2A58(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe80
	ctx.lr = 0x8239ABF0;
	sub_821CFE80(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8239aba0
	if (cr6.eq) goto loc_8239ABA0;
loc_8239ABFC:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x8239AC08;
	sub_821D0898(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8239AC10;
	sub_821BE610(ctx, base);
	// stw r22,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r22.u32);
loc_8239AC14:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239AC1C;
	sub_821C9A90(ctx, base);
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8239AC24"))) PPC_WEAK_FUNC(sub_8239AC24);
PPC_FUNC_IMPL(__imp__sub_8239AC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239AC28"))) PPC_WEAK_FUNC(sub_8239AC28);
PPC_FUNC_IMPL(__imp__sub_8239AC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x8239AC30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8239ac8c
	if (!cr6.gt) goto loc_8239AC8C;
	// addi r28,r26,6
	r28.s64 = r26.s64 + 6;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_8239AC48:
	// lhz r31,0(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239ac80
	if (cr6.eq) goto loc_8239AC80;
	// lwz r29,-6(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -6);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239ac78
	if (!cr6.gt) goto loc_8239AC78;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239AC64:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239AC6C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239ac64
	if (!cr0.eq) goto loc_8239AC64;
loc_8239AC78:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239AC80;
	sub_82130588(ctx, base);
loc_8239AC80:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x8239ac48
	if (!cr0.eq) goto loc_8239AC48;
loc_8239AC8C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x8239AC94;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8239AC9C"))) PPC_WEAK_FUNC(sub_8239AC9C);
PPC_FUNC_IMPL(__imp__sub_8239AC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239ACA0"))) PPC_WEAK_FUNC(sub_8239ACA0);
PPC_FUNC_IMPL(__imp__sub_8239ACA0) {
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
	ctx.lr = 0x8239ACA8;
	// stwu r1,-1008(r1)
	ea = -1008 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r16,0
	r16.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stb r16,847(r1)
	PPC_STORE_U8(ctx.r1.u32 + 847, r16.u8);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-29216
	ctx.r4.s64 = ctx.r10.s64 + -29216;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,1028(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1028, r31.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x821ca540
	ctx.lr = 0x8239ACD8;
	sub_821CA540(ctx, base);
	// addi r17,r31,64
	r17.s64 = r31.s64 + 64;
	// mr r25,r16
	r25.u64 = r16.u64;
	// stw r16,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r16.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// mr r26,r16
	r26.u64 = r16.u64;
	// mr r14,r16
	r14.u64 = r16.u64;
	// bl 0x82197068
	ctx.lr = 0x8239ACF4;
	sub_82197068(ctx, base);
	// addi r15,r31,72
	r15.s64 = r31.s64 + 72;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x82197068
	ctx.lr = 0x8239AD00;
	sub_82197068(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r19,r31,88
	r19.s64 = r31.s64 + 88;
	// bl 0x82130588
	ctx.lr = 0x8239AD0C;
	sub_82130588(ctx, base);
	// stw r16,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r16.u32);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// sth r16,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r16.u16);
	// sth r16,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r16.u16);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// bl 0x82197068
	ctx.lr = 0x8239AD24;
	sub_82197068(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// bl 0x82197068
	ctx.lr = 0x8239AD30;
	sub_82197068(ctx, base);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r18,r16
	r18.u64 = r16.u64;
	// addi r24,r3,-30140
	r24.s64 = ctx.r3.s64 + -30140;
	// addi r23,r4,12664
	r23.s64 = ctx.r4.s64 + 12664;
	// addi r22,r5,12672
	r22.s64 = ctx.r5.s64 + 12672;
	// addi r31,r6,-29628
	r31.s64 = ctx.r6.s64 + -29628;
	// addi r30,r7,-29624
	r30.s64 = ctx.r7.s64 + -29624;
	// addi r27,r8,12680
	r27.s64 = ctx.r8.s64 + 12680;
	// addi r21,r9,-24488
	r21.s64 = ctx.r9.s64 + -24488;
	// addi r20,r10,12816
	r20.s64 = ctx.r10.s64 + 12816;
	// addi r28,r11,12708
	r28.s64 = r11.s64 + 12708;
	// b 0x8239ad84
	goto loc_8239AD84;
loc_8239AD80:
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8239AD84:
	// cmpwi cr6,r18,0
	cr6.compare<int32_t>(r18.s32, 0, xer);
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bne cr6,0x8239ada0
	if (!cr6.eq) goto loc_8239ADA0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8239ada8
	goto loc_8239ADA8;
loc_8239ADA0:
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
loc_8239ADA8:
	// bl 0x82137a08
	ctx.lr = 0x8239ADAC;
	sub_82137A08(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,656
	ctx.r4.s64 = ctx.r1.s64 + 656;
	// bl 0x821ca6a8
	ctx.lr = 0x8239ADC4;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239afb0
	if (cr6.eq) goto loc_8239AFB0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d1cd0
	ctx.lr = 0x8239ADD8;
	sub_821D1CD0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cf7b8
	ctx.lr = 0x8239ADE8;
	sub_821CF7B8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239ADF4;
	sub_821D0898(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AE00;
	sub_821D0898(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfe80
	ctx.lr = 0x8239AE10;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239aeb0
	if (!cr6.eq) goto loc_8239AEB0;
loc_8239AE1C:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,720
	ctx.r4.s64 = ctx.r1.s64 + 720;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfaa8
	ctx.lr = 0x8239AE2C;
	sub_821CFAA8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// bl 0x821d0898
	ctx.lr = 0x8239AE3C;
	sub_821D0898(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfe80
	ctx.lr = 0x8239AE4C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239ae88
	if (!cr6.eq) goto loc_8239AE88;
loc_8239AE58:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,720
	ctx.r4.s64 = ctx.r1.s64 + 720;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfaa8
	ctx.lr = 0x8239AE68;
	sub_821CFAA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// bl 0x821cfe80
	ctx.lr = 0x8239AE7C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239ae58
	if (cr6.eq) goto loc_8239AE58;
loc_8239AE88:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AE94;
	sub_821D0898(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfe80
	ctx.lr = 0x8239AEA4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239ae1c
	if (cr6.eq) goto loc_8239AE1C;
loc_8239AEB0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AEBC;
	sub_821D0898(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AEC8;
	sub_821D0898(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AED4;
	sub_821D0898(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfe80
	ctx.lr = 0x8239AEE4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239af20
	if (!cr6.eq) goto loc_8239AF20;
loc_8239AEF0:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,720
	ctx.r4.s64 = ctx.r1.s64 + 720;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfaa8
	ctx.lr = 0x8239AF00;
	sub_821CFAA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// bl 0x821cfe80
	ctx.lr = 0x8239AF14;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239aef0
	if (cr6.eq) goto loc_8239AEF0;
loc_8239AF20:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AF2C;
	sub_821D0898(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AF38;
	sub_821D0898(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AF44;
	sub_821D0898(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfe80
	ctx.lr = 0x8239AF54;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239af98
	if (!cr6.eq) goto loc_8239AF98;
loc_8239AF60:
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r4,r1,720
	ctx.r4.s64 = ctx.r1.s64 + 720;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cfaa8
	ctx.lr = 0x8239AF70;
	sub_821CFAA8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x821cfe80
	ctx.lr = 0x8239AF8C;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8239af60
	if (cr6.eq) goto loc_8239AF60;
loc_8239AF98:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d0898
	ctx.lr = 0x8239AFA4;
	sub_821D0898(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8239AFAC;
	sub_821BE610(ctx, base);
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
loc_8239AFB0:
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// cmpwi cr6,r18,8
	cr6.compare<int32_t>(r18.s32, 8, xer);
	// blt cr6,0x8239ad80
	if (cr6.lt) goto loc_8239AD80;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8239affc
	if (cr6.eq) goto loc_8239AFFC;
	// rlwinm r3,r25,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239AFCC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x8239aff4
	if (!cr6.gt) goto loc_8239AFF4;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_8239AFDC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239afe8
	if (cr6.eq) goto loc_8239AFE8;
	// stw r16,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r16.u32);
loc_8239AFE8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239afdc
	if (!cr0.eq) goto loc_8239AFDC;
loc_8239AFF4:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8239b000
	goto loc_8239B000;
loc_8239AFFC:
	// mr r11,r16
	r11.u64 = r16.u64;
loc_8239B000:
	// stw r11,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r11.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r25,6(r17)
	PPC_STORE_U16(r17.u32 + 6, r25.u16);
	// beq cr6,0x8239b048
	if (cr6.eq) goto loc_8239B048;
	// rlwinm r3,r26,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239B018;
	sub_82130528(ctx, base);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x8239b040
	if (!cr6.gt) goto loc_8239B040;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_8239B028:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239b034
	if (cr6.eq) goto loc_8239B034;
	// stw r16,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r16.u32);
loc_8239B034:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239b028
	if (!cr0.eq) goto loc_8239B028;
loc_8239B040:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8239b04c
	goto loc_8239B04C;
loc_8239B048:
	// mr r11,r16
	r11.u64 = r16.u64;
loc_8239B04C:
	// clrlwi r31,r26,16
	r31.u64 = r26.u32 & 0xFFFF;
	// stw r11,0(r15)
	PPC_STORE_U32(r15.u32 + 0, r11.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r31,6(r15)
	PPC_STORE_U16(r15.u32 + 6, r31.u16);
	// beq cr6,0x8239b06c
	if (cr6.eq) goto loc_8239B06C;
	// rlwinm r3,r26,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239B068;
	sub_82130528(ctx, base);
	// b 0x8239b070
	goto loc_8239B070;
loc_8239B06C:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
loc_8239B070:
	// stw r3,0(r19)
	PPC_STORE_U32(r19.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// sth r31,6(r19)
	PPC_STORE_U16(r19.u32 + 6, r31.u16);
	// beq cr6,0x8239b0b8
	if (cr6.eq) goto loc_8239B0B8;
	// rlwinm r3,r14,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r14.u32 | (r14.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239B088;
	sub_82130528(ctx, base);
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// ble cr6,0x8239b0b0
	if (!cr6.gt) goto loc_8239B0B0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
loc_8239B098:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239b0a4
	if (cr6.eq) goto loc_8239B0A4;
	// stw r16,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r16.u32);
loc_8239B0A4:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239b098
	if (!cr0.eq) goto loc_8239B098;
loc_8239B0B0:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8239b0bc
	goto loc_8239B0BC;
loc_8239B0B8:
	// mr r11,r16
	r11.u64 = r16.u64;
loc_8239B0BC:
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// sth r14,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r14.u16);
	// beq cr6,0x8239b10c
	if (cr6.eq) goto loc_8239B10C;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239B0DC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b104
	if (!cr6.gt) goto loc_8239B104;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8239B0EC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239b0f8
	if (cr6.eq) goto loc_8239B0F8;
	// stw r16,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r16.u32);
loc_8239B0F8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8239b0ec
	if (!cr0.eq) goto loc_8239B0EC;
loc_8239B104:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8239b110
	goto loc_8239B110;
loc_8239B10C:
	// mr r11,r16
	r11.u64 = r16.u64;
loc_8239B110:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// sth r31,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r31.u16);
	// bl 0x821c9a90
	ctx.lr = 0x8239B124;
	sub_821C9A90(ctx, base);
	// mr r31,r16
	r31.u64 = r16.u64;
loc_8239B128:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,1028(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1028);
	// bl 0x8239a128
	ctx.lr = 0x8239B134;
	sub_8239A128(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// blt cr6,0x8239b128
	if (cr6.lt) goto loc_8239B128;
	// addi r1,r1,1008
	ctx.r1.s64 = ctx.r1.s64 + 1008;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8239B148"))) PPC_WEAK_FUNC(sub_8239B148);
PPC_FUNC_IMPL(__imp__sub_8239B148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r9,22
	ctx.r9.s64 = 22;
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
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// sth r11,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, r11.u16);
	// sth r11,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r11.u16);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// sth r11,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r11.u16);
	// sth r11,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, r11.u16);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// sth r11,44(r3)
	PPC_STORE_U16(ctx.r3.u32 + 44, r11.u16);
	// sth r11,46(r3)
	PPC_STORE_U16(ctx.r3.u32 + 46, r11.u16);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// sth r11,52(r3)
	PPC_STORE_U16(ctx.r3.u32 + 52, r11.u16);
	// sth r11,54(r3)
	PPC_STORE_U16(ctx.r3.u32 + 54, r11.u16);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// sth r11,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, r11.u16);
	// sth r11,62(r3)
	PPC_STORE_U16(ctx.r3.u32 + 62, r11.u16);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// sth r11,68(r3)
	PPC_STORE_U16(ctx.r3.u32 + 68, r11.u16);
	// sth r11,70(r3)
	PPC_STORE_U16(ctx.r3.u32 + 70, r11.u16);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// sth r11,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, r11.u16);
	// sth r11,78(r3)
	PPC_STORE_U16(ctx.r3.u32 + 78, r11.u16);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// sth r11,84(r3)
	PPC_STORE_U16(ctx.r3.u32 + 84, r11.u16);
	// sth r11,86(r3)
	PPC_STORE_U16(ctx.r3.u32 + 86, r11.u16);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// sth r11,92(r3)
	PPC_STORE_U16(ctx.r3.u32 + 92, r11.u16);
	// sth r11,94(r3)
	PPC_STORE_U16(ctx.r3.u32 + 94, r11.u16);
loc_8239B1E4:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, r11.u16);
	// sth r11,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r11.u16);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bge 0x8239b1e4
	if (!cr0.lt) goto loc_8239B1E4;
	// stw r11,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, r11.u32);
	// addi r10,r3,288
	ctx.r10.s64 = ctx.r3.s64 + 288;
	// sth r11,284(r3)
	PPC_STORE_U16(ctx.r3.u32 + 284, r11.u16);
	// li r9,22
	ctx.r9.s64 = 22;
	// sth r11,286(r3)
	PPC_STORE_U16(ctx.r3.u32 + 286, r11.u16);
loc_8239B210:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, r11.u16);
	// sth r11,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r11.u16);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bge 0x8239b210
	if (!cr0.lt) goto loc_8239B210;
	// stw r11,472(r3)
	PPC_STORE_U32(ctx.r3.u32 + 472, r11.u32);
	// sth r11,476(r3)
	PPC_STORE_U16(ctx.r3.u32 + 476, r11.u16);
	// sth r11,478(r3)
	PPC_STORE_U16(ctx.r3.u32 + 478, r11.u16);
	// stw r11,480(r3)
	PPC_STORE_U32(ctx.r3.u32 + 480, r11.u32);
	// sth r11,484(r3)
	PPC_STORE_U16(ctx.r3.u32 + 484, r11.u16);
	// sth r11,486(r3)
	PPC_STORE_U16(ctx.r3.u32 + 486, r11.u16);
	// stw r11,488(r3)
	PPC_STORE_U32(ctx.r3.u32 + 488, r11.u32);
	// sth r11,492(r3)
	PPC_STORE_U16(ctx.r3.u32 + 492, r11.u16);
	// sth r11,494(r3)
	PPC_STORE_U16(ctx.r3.u32 + 494, r11.u16);
	// stw r11,496(r3)
	PPC_STORE_U32(ctx.r3.u32 + 496, r11.u32);
	// sth r11,500(r3)
	PPC_STORE_U16(ctx.r3.u32 + 500, r11.u16);
	// sth r11,502(r3)
	PPC_STORE_U16(ctx.r3.u32 + 502, r11.u16);
	// stw r11,504(r3)
	PPC_STORE_U32(ctx.r3.u32 + 504, r11.u32);
	// sth r11,508(r3)
	PPC_STORE_U16(ctx.r3.u32 + 508, r11.u16);
	// sth r11,510(r3)
	PPC_STORE_U16(ctx.r3.u32 + 510, r11.u16);
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, r11.u32);
	// sth r11,516(r3)
	PPC_STORE_U16(ctx.r3.u32 + 516, r11.u16);
	// sth r11,518(r3)
	PPC_STORE_U16(ctx.r3.u32 + 518, r11.u16);
	// stw r11,520(r3)
	PPC_STORE_U32(ctx.r3.u32 + 520, r11.u32);
	// sth r11,524(r3)
	PPC_STORE_U16(ctx.r3.u32 + 524, r11.u16);
	// sth r11,526(r3)
	PPC_STORE_U16(ctx.r3.u32 + 526, r11.u16);
	// stw r11,528(r3)
	PPC_STORE_U32(ctx.r3.u32 + 528, r11.u32);
	// sth r11,532(r3)
	PPC_STORE_U16(ctx.r3.u32 + 532, r11.u16);
	// sth r11,534(r3)
	PPC_STORE_U16(ctx.r3.u32 + 534, r11.u16);
	// stw r11,536(r3)
	PPC_STORE_U32(ctx.r3.u32 + 536, r11.u32);
	// sth r11,540(r3)
	PPC_STORE_U16(ctx.r3.u32 + 540, r11.u16);
	// sth r11,542(r3)
	PPC_STORE_U16(ctx.r3.u32 + 542, r11.u16);
	// stw r11,544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 544, r11.u32);
	// sth r11,548(r3)
	PPC_STORE_U16(ctx.r3.u32 + 548, r11.u16);
	// sth r11,550(r3)
	PPC_STORE_U16(ctx.r3.u32 + 550, r11.u16);
	// stw r11,552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 552, r11.u32);
	// sth r11,556(r3)
	PPC_STORE_U16(ctx.r3.u32 + 556, r11.u16);
	// sth r11,558(r3)
	PPC_STORE_U16(ctx.r3.u32 + 558, r11.u16);
	// stw r11,560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 560, r11.u32);
	// sth r11,564(r3)
	PPC_STORE_U16(ctx.r3.u32 + 564, r11.u16);
	// sth r11,566(r3)
	PPC_STORE_U16(ctx.r3.u32 + 566, r11.u16);
	// stw r11,568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 568, r11.u32);
	// sth r11,572(r3)
	PPC_STORE_U16(ctx.r3.u32 + 572, r11.u16);
	// sth r11,574(r3)
	PPC_STORE_U16(ctx.r3.u32 + 574, r11.u16);
	// stw r11,576(r3)
	PPC_STORE_U32(ctx.r3.u32 + 576, r11.u32);
	// sth r11,580(r3)
	PPC_STORE_U16(ctx.r3.u32 + 580, r11.u16);
	// sth r11,582(r3)
	PPC_STORE_U16(ctx.r3.u32 + 582, r11.u16);
	// stw r11,584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 584, r11.u32);
	// sth r11,588(r3)
	PPC_STORE_U16(ctx.r3.u32 + 588, r11.u16);
	// sth r11,590(r3)
	PPC_STORE_U16(ctx.r3.u32 + 590, r11.u16);
	// stw r11,592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 592, r11.u32);
	// sth r11,596(r3)
	PPC_STORE_U16(ctx.r3.u32 + 596, r11.u16);
	// sth r11,598(r3)
	PPC_STORE_U16(ctx.r3.u32 + 598, r11.u16);
	// stw r11,600(r3)
	PPC_STORE_U32(ctx.r3.u32 + 600, r11.u32);
	// sth r11,604(r3)
	PPC_STORE_U16(ctx.r3.u32 + 604, r11.u16);
	// sth r11,606(r3)
	PPC_STORE_U16(ctx.r3.u32 + 606, r11.u16);
	// stw r11,608(r3)
	PPC_STORE_U32(ctx.r3.u32 + 608, r11.u32);
	// sth r11,612(r3)
	PPC_STORE_U16(ctx.r3.u32 + 612, r11.u16);
	// sth r11,614(r3)
	PPC_STORE_U16(ctx.r3.u32 + 614, r11.u16);
	// stw r11,616(r3)
	PPC_STORE_U32(ctx.r3.u32 + 616, r11.u32);
	// sth r11,620(r3)
	PPC_STORE_U16(ctx.r3.u32 + 620, r11.u16);
	// sth r11,622(r3)
	PPC_STORE_U16(ctx.r3.u32 + 622, r11.u16);
	// stw r11,624(r3)
	PPC_STORE_U32(ctx.r3.u32 + 624, r11.u32);
	// sth r11,628(r3)
	PPC_STORE_U16(ctx.r3.u32 + 628, r11.u16);
	// sth r11,630(r3)
	PPC_STORE_U16(ctx.r3.u32 + 630, r11.u16);
	// stw r11,632(r3)
	PPC_STORE_U32(ctx.r3.u32 + 632, r11.u32);
	// sth r11,636(r3)
	PPC_STORE_U16(ctx.r3.u32 + 636, r11.u16);
	// sth r11,638(r3)
	PPC_STORE_U16(ctx.r3.u32 + 638, r11.u16);
	// stw r11,640(r3)
	PPC_STORE_U32(ctx.r3.u32 + 640, r11.u32);
	// sth r11,644(r3)
	PPC_STORE_U16(ctx.r3.u32 + 644, r11.u16);
	// sth r11,646(r3)
	PPC_STORE_U16(ctx.r3.u32 + 646, r11.u16);
	// stw r11,648(r3)
	PPC_STORE_U32(ctx.r3.u32 + 648, r11.u32);
	// sth r11,652(r3)
	PPC_STORE_U16(ctx.r3.u32 + 652, r11.u16);
	// sth r11,654(r3)
	PPC_STORE_U16(ctx.r3.u32 + 654, r11.u16);
	// stw r11,656(r3)
	PPC_STORE_U32(ctx.r3.u32 + 656, r11.u32);
	// sth r11,660(r3)
	PPC_STORE_U16(ctx.r3.u32 + 660, r11.u16);
	// sth r11,662(r3)
	PPC_STORE_U16(ctx.r3.u32 + 662, r11.u16);
	// stw r11,664(r3)
	PPC_STORE_U32(ctx.r3.u32 + 664, r11.u32);
	// sth r11,668(r3)
	PPC_STORE_U16(ctx.r3.u32 + 668, r11.u16);
	// sth r11,670(r3)
	PPC_STORE_U16(ctx.r3.u32 + 670, r11.u16);
	// stw r11,672(r3)
	PPC_STORE_U32(ctx.r3.u32 + 672, r11.u32);
	// sth r11,676(r3)
	PPC_STORE_U16(ctx.r3.u32 + 676, r11.u16);
	// sth r11,678(r3)
	PPC_STORE_U16(ctx.r3.u32 + 678, r11.u16);
	// stw r11,680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 680, r11.u32);
	// sth r11,684(r3)
	PPC_STORE_U16(ctx.r3.u32 + 684, r11.u16);
	// sth r11,686(r3)
	PPC_STORE_U16(ctx.r3.u32 + 686, r11.u16);
	// stw r11,688(r3)
	PPC_STORE_U32(ctx.r3.u32 + 688, r11.u32);
	// sth r11,692(r3)
	PPC_STORE_U16(ctx.r3.u32 + 692, r11.u16);
	// sth r11,694(r3)
	PPC_STORE_U16(ctx.r3.u32 + 694, r11.u16);
	// stw r11,696(r3)
	PPC_STORE_U32(ctx.r3.u32 + 696, r11.u32);
	// sth r11,700(r3)
	PPC_STORE_U16(ctx.r3.u32 + 700, r11.u16);
	// sth r11,702(r3)
	PPC_STORE_U16(ctx.r3.u32 + 702, r11.u16);
	// stw r11,704(r3)
	PPC_STORE_U32(ctx.r3.u32 + 704, r11.u32);
	// sth r11,708(r3)
	PPC_STORE_U16(ctx.r3.u32 + 708, r11.u16);
	// sth r11,710(r3)
	PPC_STORE_U16(ctx.r3.u32 + 710, r11.u16);
	// stw r11,712(r3)
	PPC_STORE_U32(ctx.r3.u32 + 712, r11.u32);
	// sth r11,716(r3)
	PPC_STORE_U16(ctx.r3.u32 + 716, r11.u16);
	// sth r11,718(r3)
	PPC_STORE_U16(ctx.r3.u32 + 718, r11.u16);
	// stw r11,720(r3)
	PPC_STORE_U32(ctx.r3.u32 + 720, r11.u32);
	// sth r11,724(r3)
	PPC_STORE_U16(ctx.r3.u32 + 724, r11.u16);
	// sth r11,726(r3)
	PPC_STORE_U16(ctx.r3.u32 + 726, r11.u16);
	// stw r11,728(r3)
	PPC_STORE_U32(ctx.r3.u32 + 728, r11.u32);
	// sth r11,732(r3)
	PPC_STORE_U16(ctx.r3.u32 + 732, r11.u16);
	// sth r11,734(r3)
	PPC_STORE_U16(ctx.r3.u32 + 734, r11.u16);
	// stw r11,736(r3)
	PPC_STORE_U32(ctx.r3.u32 + 736, r11.u32);
	// sth r11,740(r3)
	PPC_STORE_U16(ctx.r3.u32 + 740, r11.u16);
	// sth r11,742(r3)
	PPC_STORE_U16(ctx.r3.u32 + 742, r11.u16);
	// stw r11,744(r3)
	PPC_STORE_U32(ctx.r3.u32 + 744, r11.u32);
	// sth r11,748(r3)
	PPC_STORE_U16(ctx.r3.u32 + 748, r11.u16);
	// sth r11,750(r3)
	PPC_STORE_U16(ctx.r3.u32 + 750, r11.u16);
	// stw r11,752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 752, r11.u32);
	// sth r11,756(r3)
	PPC_STORE_U16(ctx.r3.u32 + 756, r11.u16);
	// sth r11,758(r3)
	PPC_STORE_U16(ctx.r3.u32 + 758, r11.u16);
	// stw r11,760(r3)
	PPC_STORE_U32(ctx.r3.u32 + 760, r11.u32);
	// sth r11,764(r3)
	PPC_STORE_U16(ctx.r3.u32 + 764, r11.u16);
	// sth r11,766(r3)
	PPC_STORE_U16(ctx.r3.u32 + 766, r11.u16);
	// stw r11,768(r3)
	PPC_STORE_U32(ctx.r3.u32 + 768, r11.u32);
	// sth r11,772(r3)
	PPC_STORE_U16(ctx.r3.u32 + 772, r11.u16);
	// sth r11,774(r3)
	PPC_STORE_U16(ctx.r3.u32 + 774, r11.u16);
	// stw r11,776(r3)
	PPC_STORE_U32(ctx.r3.u32 + 776, r11.u32);
	// sth r11,780(r3)
	PPC_STORE_U16(ctx.r3.u32 + 780, r11.u16);
	// sth r11,782(r3)
	PPC_STORE_U16(ctx.r3.u32 + 782, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239B400"))) PPC_WEAK_FUNC(sub_8239B400);
PPC_FUNC_IMPL(__imp__sub_8239B400) {
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
	ctx.lr = 0x8239B408;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lhz r31,782(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 782);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b448
	if (cr6.eq) goto loc_8239B448;
	// lwz r29,776(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 776);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b440
	if (!cr6.gt) goto loc_8239B440;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B42C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B434;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b42c
	if (!cr0.eq) goto loc_8239B42C;
loc_8239B440:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B448;
	sub_82130588(ctx, base);
loc_8239B448:
	// lhz r31,774(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 774);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b480
	if (cr6.eq) goto loc_8239B480;
	// lwz r29,768(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 768);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b478
	if (!cr6.gt) goto loc_8239B478;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B464:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B46C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b464
	if (!cr0.eq) goto loc_8239B464;
loc_8239B478:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B480;
	sub_82130588(ctx, base);
loc_8239B480:
	// lhz r31,766(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 766);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b4b8
	if (cr6.eq) goto loc_8239B4B8;
	// lwz r29,760(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 760);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b4b0
	if (!cr6.gt) goto loc_8239B4B0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B49C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B4A4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b49c
	if (!cr0.eq) goto loc_8239B49C;
loc_8239B4B0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B4B8;
	sub_82130588(ctx, base);
loc_8239B4B8:
	// lhz r31,758(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 758);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b4f0
	if (cr6.eq) goto loc_8239B4F0;
	// lwz r29,752(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 752);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b4e8
	if (!cr6.gt) goto loc_8239B4E8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B4D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B4DC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b4d4
	if (!cr0.eq) goto loc_8239B4D4;
loc_8239B4E8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B4F0;
	sub_82130588(ctx, base);
loc_8239B4F0:
	// lhz r31,750(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 750);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b528
	if (cr6.eq) goto loc_8239B528;
	// lwz r29,744(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 744);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b520
	if (!cr6.gt) goto loc_8239B520;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B50C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B514;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b50c
	if (!cr0.eq) goto loc_8239B50C;
loc_8239B520:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B528;
	sub_82130588(ctx, base);
loc_8239B528:
	// lhz r31,742(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 742);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b560
	if (cr6.eq) goto loc_8239B560;
	// lwz r29,736(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 736);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b558
	if (!cr6.gt) goto loc_8239B558;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B544:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B54C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b544
	if (!cr0.eq) goto loc_8239B544;
loc_8239B558:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B560;
	sub_82130588(ctx, base);
loc_8239B560:
	// lhz r31,734(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 734);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b598
	if (cr6.eq) goto loc_8239B598;
	// lwz r29,728(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 728);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b590
	if (!cr6.gt) goto loc_8239B590;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B57C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B584;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b57c
	if (!cr0.eq) goto loc_8239B57C;
loc_8239B590:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B598;
	sub_82130588(ctx, base);
loc_8239B598:
	// lhz r31,726(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 726);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b5d0
	if (cr6.eq) goto loc_8239B5D0;
	// lwz r29,720(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 720);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b5c8
	if (!cr6.gt) goto loc_8239B5C8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B5B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B5BC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b5b4
	if (!cr0.eq) goto loc_8239B5B4;
loc_8239B5C8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B5D0;
	sub_82130588(ctx, base);
loc_8239B5D0:
	// lhz r31,718(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 718);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b608
	if (cr6.eq) goto loc_8239B608;
	// lwz r29,712(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 712);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b600
	if (!cr6.gt) goto loc_8239B600;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B5EC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B5F4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b5ec
	if (!cr0.eq) goto loc_8239B5EC;
loc_8239B600:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B608;
	sub_82130588(ctx, base);
loc_8239B608:
	// lhz r31,710(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 710);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b640
	if (cr6.eq) goto loc_8239B640;
	// lwz r29,704(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 704);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b638
	if (!cr6.gt) goto loc_8239B638;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B624:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B62C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b624
	if (!cr0.eq) goto loc_8239B624;
loc_8239B638:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B640;
	sub_82130588(ctx, base);
loc_8239B640:
	// lhz r31,702(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 702);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b678
	if (cr6.eq) goto loc_8239B678;
	// lwz r29,696(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 696);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b670
	if (!cr6.gt) goto loc_8239B670;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B65C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B664;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b65c
	if (!cr0.eq) goto loc_8239B65C;
loc_8239B670:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B678;
	sub_82130588(ctx, base);
loc_8239B678:
	// lhz r5,694(r26)
	ctx.r5.u64 = PPC_LOAD_U16(r26.u32 + 694);
	// addi r3,r26,688
	ctx.r3.s64 = r26.s64 + 688;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8239b690
	if (cr6.eq) goto loc_8239B690;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8239ac28
	ctx.lr = 0x8239B690;
	sub_8239AC28(ctx, base);
loc_8239B690:
	// lhz r31,686(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 686);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b6c8
	if (cr6.eq) goto loc_8239B6C8;
	// lwz r29,680(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 680);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b6c0
	if (!cr6.gt) goto loc_8239B6C0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B6AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B6B4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b6ac
	if (!cr0.eq) goto loc_8239B6AC;
loc_8239B6C0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B6C8;
	sub_82130588(ctx, base);
loc_8239B6C8:
	// lhz r31,678(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 678);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b700
	if (cr6.eq) goto loc_8239B700;
	// lwz r29,672(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 672);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b6f8
	if (!cr6.gt) goto loc_8239B6F8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B6E4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B6EC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b6e4
	if (!cr0.eq) goto loc_8239B6E4;
loc_8239B6F8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B700;
	sub_82130588(ctx, base);
loc_8239B700:
	// lhz r31,670(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 670);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b738
	if (cr6.eq) goto loc_8239B738;
	// lwz r29,664(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 664);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b730
	if (!cr6.gt) goto loc_8239B730;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B71C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B724;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b71c
	if (!cr0.eq) goto loc_8239B71C;
loc_8239B730:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B738;
	sub_82130588(ctx, base);
loc_8239B738:
	// lhz r31,662(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 662);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b770
	if (cr6.eq) goto loc_8239B770;
	// lwz r29,656(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 656);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b768
	if (!cr6.gt) goto loc_8239B768;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B754:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B75C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b754
	if (!cr0.eq) goto loc_8239B754;
loc_8239B768:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B770;
	sub_82130588(ctx, base);
loc_8239B770:
	// lhz r31,654(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 654);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b7a8
	if (cr6.eq) goto loc_8239B7A8;
	// lwz r29,648(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 648);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b7a0
	if (!cr6.gt) goto loc_8239B7A0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B78C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B794;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b78c
	if (!cr0.eq) goto loc_8239B78C;
loc_8239B7A0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B7A8;
	sub_82130588(ctx, base);
loc_8239B7A8:
	// lhz r31,646(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 646);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b7e0
	if (cr6.eq) goto loc_8239B7E0;
	// lwz r29,640(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 640);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b7d8
	if (!cr6.gt) goto loc_8239B7D8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B7C4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B7CC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b7c4
	if (!cr0.eq) goto loc_8239B7C4;
loc_8239B7D8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B7E0;
	sub_82130588(ctx, base);
loc_8239B7E0:
	// lhz r31,638(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 638);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b818
	if (cr6.eq) goto loc_8239B818;
	// lwz r29,632(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 632);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b810
	if (!cr6.gt) goto loc_8239B810;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B7FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B804;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b7fc
	if (!cr0.eq) goto loc_8239B7FC;
loc_8239B810:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B818;
	sub_82130588(ctx, base);
loc_8239B818:
	// lhz r31,630(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 630);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b850
	if (cr6.eq) goto loc_8239B850;
	// lwz r29,624(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 624);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b848
	if (!cr6.gt) goto loc_8239B848;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B834:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B83C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b834
	if (!cr0.eq) goto loc_8239B834;
loc_8239B848:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B850;
	sub_82130588(ctx, base);
loc_8239B850:
	// lhz r31,622(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 622);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b888
	if (cr6.eq) goto loc_8239B888;
	// lwz r29,616(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 616);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b880
	if (!cr6.gt) goto loc_8239B880;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B86C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B874;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b86c
	if (!cr0.eq) goto loc_8239B86C;
loc_8239B880:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B888;
	sub_82130588(ctx, base);
loc_8239B888:
	// lhz r31,614(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 614);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b8c0
	if (cr6.eq) goto loc_8239B8C0;
	// lwz r29,608(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 608);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b8b8
	if (!cr6.gt) goto loc_8239B8B8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B8A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B8AC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b8a4
	if (!cr0.eq) goto loc_8239B8A4;
loc_8239B8B8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B8C0;
	sub_82130588(ctx, base);
loc_8239B8C0:
	// lhz r31,606(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 606);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b8f8
	if (cr6.eq) goto loc_8239B8F8;
	// lwz r29,600(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 600);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b8f0
	if (!cr6.gt) goto loc_8239B8F0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B8DC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B8E4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b8dc
	if (!cr0.eq) goto loc_8239B8DC;
loc_8239B8F0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B8F8;
	sub_82130588(ctx, base);
loc_8239B8F8:
	// lhz r31,598(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 598);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b930
	if (cr6.eq) goto loc_8239B930;
	// lwz r29,592(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 592);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b928
	if (!cr6.gt) goto loc_8239B928;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B914:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B91C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b914
	if (!cr0.eq) goto loc_8239B914;
loc_8239B928:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B930;
	sub_82130588(ctx, base);
loc_8239B930:
	// lhz r31,590(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 590);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b968
	if (cr6.eq) goto loc_8239B968;
	// lwz r29,584(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 584);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b960
	if (!cr6.gt) goto loc_8239B960;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B94C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B954;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b94c
	if (!cr0.eq) goto loc_8239B94C;
loc_8239B960:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B968;
	sub_82130588(ctx, base);
loc_8239B968:
	// lhz r31,582(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 582);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b9a0
	if (cr6.eq) goto loc_8239B9A0;
	// lwz r29,576(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 576);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b998
	if (!cr6.gt) goto loc_8239B998;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B984:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B98C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b984
	if (!cr0.eq) goto loc_8239B984;
loc_8239B998:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B9A0;
	sub_82130588(ctx, base);
loc_8239B9A0:
	// lhz r31,574(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 574);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239b9d8
	if (cr6.eq) goto loc_8239B9D8;
	// lwz r29,568(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 568);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239b9d0
	if (!cr6.gt) goto loc_8239B9D0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B9BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B9C4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b9bc
	if (!cr0.eq) goto loc_8239B9BC;
loc_8239B9D0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239B9D8;
	sub_82130588(ctx, base);
loc_8239B9D8:
	// lhz r31,566(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 566);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239ba10
	if (cr6.eq) goto loc_8239BA10;
	// lwz r29,560(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 560);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239ba08
	if (!cr6.gt) goto loc_8239BA08;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239B9F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239B9FC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239b9f4
	if (!cr0.eq) goto loc_8239B9F4;
loc_8239BA08:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BA10;
	sub_82130588(ctx, base);
loc_8239BA10:
	// lhz r31,558(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 558);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239ba48
	if (cr6.eq) goto loc_8239BA48;
	// lwz r29,552(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 552);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239ba40
	if (!cr6.gt) goto loc_8239BA40;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BA2C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BA34;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239ba2c
	if (!cr0.eq) goto loc_8239BA2C;
loc_8239BA40:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BA48;
	sub_82130588(ctx, base);
loc_8239BA48:
	// lhz r31,550(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 550);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239ba80
	if (cr6.eq) goto loc_8239BA80;
	// lwz r29,544(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 544);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239ba78
	if (!cr6.gt) goto loc_8239BA78;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BA64:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BA6C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239ba64
	if (!cr0.eq) goto loc_8239BA64;
loc_8239BA78:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BA80;
	sub_82130588(ctx, base);
loc_8239BA80:
	// lhz r31,542(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 542);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bab8
	if (cr6.eq) goto loc_8239BAB8;
	// lwz r29,536(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 536);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bab0
	if (!cr6.gt) goto loc_8239BAB0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BA9C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BAA4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239ba9c
	if (!cr0.eq) goto loc_8239BA9C;
loc_8239BAB0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BAB8;
	sub_82130588(ctx, base);
loc_8239BAB8:
	// lhz r31,534(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 534);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239baf0
	if (cr6.eq) goto loc_8239BAF0;
	// lwz r29,528(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 528);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bae8
	if (!cr6.gt) goto loc_8239BAE8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BAD4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BADC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bad4
	if (!cr0.eq) goto loc_8239BAD4;
loc_8239BAE8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BAF0;
	sub_82130588(ctx, base);
loc_8239BAF0:
	// lhz r31,526(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 526);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bb28
	if (cr6.eq) goto loc_8239BB28;
	// lwz r29,520(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 520);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bb20
	if (!cr6.gt) goto loc_8239BB20;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BB0C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BB14;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bb0c
	if (!cr0.eq) goto loc_8239BB0C;
loc_8239BB20:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BB28;
	sub_82130588(ctx, base);
loc_8239BB28:
	// lhz r31,518(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 518);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bb60
	if (cr6.eq) goto loc_8239BB60;
	// lwz r29,512(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 512);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bb58
	if (!cr6.gt) goto loc_8239BB58;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BB44:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BB4C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bb44
	if (!cr0.eq) goto loc_8239BB44;
loc_8239BB58:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BB60;
	sub_82130588(ctx, base);
loc_8239BB60:
	// lhz r31,510(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 510);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bb98
	if (cr6.eq) goto loc_8239BB98;
	// lwz r29,504(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 504);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bb90
	if (!cr6.gt) goto loc_8239BB90;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BB7C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BB84;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bb7c
	if (!cr0.eq) goto loc_8239BB7C;
loc_8239BB90:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BB98;
	sub_82130588(ctx, base);
loc_8239BB98:
	// lhz r31,502(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 502);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bbd0
	if (cr6.eq) goto loc_8239BBD0;
	// lwz r29,496(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 496);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bbc8
	if (!cr6.gt) goto loc_8239BBC8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BBB4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BBBC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bbb4
	if (!cr0.eq) goto loc_8239BBB4;
loc_8239BBC8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BBD0;
	sub_82130588(ctx, base);
loc_8239BBD0:
	// lhz r31,494(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 494);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bc08
	if (cr6.eq) goto loc_8239BC08;
	// lwz r29,488(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 488);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bc00
	if (!cr6.gt) goto loc_8239BC00;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BBEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BBF4;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bbec
	if (!cr0.eq) goto loc_8239BBEC;
loc_8239BC00:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BC08;
	sub_82130588(ctx, base);
loc_8239BC08:
	// lhz r31,486(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 486);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bc40
	if (cr6.eq) goto loc_8239BC40;
	// lwz r29,480(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 480);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bc38
	if (!cr6.gt) goto loc_8239BC38;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BC24:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BC2C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bc24
	if (!cr0.eq) goto loc_8239BC24;
loc_8239BC38:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BC40;
	sub_82130588(ctx, base);
loc_8239BC40:
	// lhz r31,478(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 478);
	// addi r28,r26,472
	r28.s64 = r26.s64 + 472;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bc7c
	if (cr6.eq) goto loc_8239BC7C;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bc74
	if (!cr6.gt) goto loc_8239BC74;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BC60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BC68;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bc60
	if (!cr0.eq) goto loc_8239BC60;
loc_8239BC74:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BC7C;
	sub_82130588(ctx, base);
loc_8239BC7C:
	// mr r31,r28
	r31.u64 = r28.u64;
	// li r30,22
	r30.s64 = 22;
loc_8239BC84:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239bc9c
	if (cr6.eq) goto loc_8239BC9C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8239BC9C;
	sub_82130588(ctx, base);
loc_8239BC9C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8239bc84
	if (!cr0.lt) goto loc_8239BC84;
	// lhz r31,286(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 286);
	// addi r28,r26,280
	r28.s64 = r26.s64 + 280;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bce0
	if (cr6.eq) goto loc_8239BCE0;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bcd8
	if (!cr6.gt) goto loc_8239BCD8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BCC4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BCCC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bcc4
	if (!cr0.eq) goto loc_8239BCC4;
loc_8239BCD8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BCE0;
	sub_82130588(ctx, base);
loc_8239BCE0:
	// li r27,22
	r27.s64 = 22;
loc_8239BCE4:
	// addi r28,r28,-8
	r28.s64 = r28.s64 + -8;
	// lhz r31,6(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bd20
	if (cr6.eq) goto loc_8239BD20;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bd18
	if (!cr6.gt) goto loc_8239BD18;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BD04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BD0C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bd04
	if (!cr0.eq) goto loc_8239BD04;
loc_8239BD18:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BD20;
	sub_82130588(ctx, base);
loc_8239BD20:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bge 0x8239bce4
	if (!cr0.lt) goto loc_8239BCE4;
	// lhz r11,94(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 94);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239bd3c
	if (cr6.eq) goto loc_8239BD3C;
	// lwz r3,88(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x8239BD3C;
	sub_82130588(ctx, base);
loc_8239BD3C:
	// lhz r31,86(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 86);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bd74
	if (cr6.eq) goto loc_8239BD74;
	// lwz r29,80(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 80);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bd6c
	if (!cr6.gt) goto loc_8239BD6C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BD58:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BD60;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bd58
	if (!cr0.eq) goto loc_8239BD58;
loc_8239BD6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BD74;
	sub_82130588(ctx, base);
loc_8239BD74:
	// lhz r31,78(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 78);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bdac
	if (cr6.eq) goto loc_8239BDAC;
	// lwz r29,72(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 72);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bda4
	if (!cr6.gt) goto loc_8239BDA4;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BD90:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BD98;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bd90
	if (!cr0.eq) goto loc_8239BD90;
loc_8239BDA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BDAC;
	sub_82130588(ctx, base);
loc_8239BDAC:
	// lhz r31,70(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 70);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bde4
	if (cr6.eq) goto loc_8239BDE4;
	// lwz r29,64(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 64);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bddc
	if (!cr6.gt) goto loc_8239BDDC;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BDC8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BDD0;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bdc8
	if (!cr0.eq) goto loc_8239BDC8;
loc_8239BDDC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BDE4;
	sub_82130588(ctx, base);
loc_8239BDE4:
	// lhz r31,62(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 62);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239be1c
	if (cr6.eq) goto loc_8239BE1C;
	// lwz r29,56(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 56);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239be14
	if (!cr6.gt) goto loc_8239BE14;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BE00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BE08;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239be00
	if (!cr0.eq) goto loc_8239BE00;
loc_8239BE14:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BE1C;
	sub_82130588(ctx, base);
loc_8239BE1C:
	// lhz r31,54(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 54);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239be54
	if (cr6.eq) goto loc_8239BE54;
	// lwz r29,48(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239be4c
	if (!cr6.gt) goto loc_8239BE4C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BE38:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BE40;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239be38
	if (!cr0.eq) goto loc_8239BE38;
loc_8239BE4C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BE54;
	sub_82130588(ctx, base);
loc_8239BE54:
	// lhz r31,46(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 46);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239be8c
	if (cr6.eq) goto loc_8239BE8C;
	// lwz r29,40(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239be84
	if (!cr6.gt) goto loc_8239BE84;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BE70:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BE78;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239be70
	if (!cr0.eq) goto loc_8239BE70;
loc_8239BE84:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BE8C;
	sub_82130588(ctx, base);
loc_8239BE8C:
	// lhz r31,38(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 38);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bec4
	if (cr6.eq) goto loc_8239BEC4;
	// lwz r29,32(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bebc
	if (!cr6.gt) goto loc_8239BEBC;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BEA8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BEB0;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bea8
	if (!cr0.eq) goto loc_8239BEA8;
loc_8239BEBC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BEC4;
	sub_82130588(ctx, base);
loc_8239BEC4:
	// lhz r31,30(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 30);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239befc
	if (cr6.eq) goto loc_8239BEFC;
	// lwz r29,24(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bef4
	if (!cr6.gt) goto loc_8239BEF4;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BEE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BEE8;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bee0
	if (!cr0.eq) goto loc_8239BEE0;
loc_8239BEF4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BEFC;
	sub_82130588(ctx, base);
loc_8239BEFC:
	// lhz r31,22(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 22);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bf34
	if (cr6.eq) goto loc_8239BF34;
	// lwz r29,16(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bf2c
	if (!cr6.gt) goto loc_8239BF2C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BF18:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BF20;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bf18
	if (!cr0.eq) goto loc_8239BF18;
loc_8239BF2C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BF34;
	sub_82130588(ctx, base);
loc_8239BF34:
	// lhz r31,14(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 14);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bf6c
	if (cr6.eq) goto loc_8239BF6C;
	// lwz r29,8(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bf64
	if (!cr6.gt) goto loc_8239BF64;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BF50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BF58;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bf50
	if (!cr0.eq) goto loc_8239BF50;
loc_8239BF64:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BF6C;
	sub_82130588(ctx, base);
loc_8239BF6C:
	// lhz r31,6(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239bfa4
	if (cr6.eq) goto loc_8239BFA4;
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239bf9c
	if (!cr6.gt) goto loc_8239BF9C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239BF88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8239BF90;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8239bf88
	if (!cr0.eq) goto loc_8239BF88;
loc_8239BF9C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239BFA4;
	sub_82130588(ctx, base);
loc_8239BFA4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8239BFAC"))) PPC_WEAK_FUNC(sub_8239BFAC);
PPC_FUNC_IMPL(__imp__sub_8239BFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239BFB0"))) PPC_WEAK_FUNC(sub_8239BFB0);
PPC_FUNC_IMPL(__imp__sub_8239BFB0) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// bl 0x821c9790
	ctx.lr = 0x8239C008;
	sub_821C9790(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x8239C01C;
	sub_823DB670(ctx, base);
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

__attribute__((alias("__imp__sub_8239C038"))) PPC_WEAK_FUNC(sub_8239C038);
PPC_FUNC_IMPL(__imp__sub_8239C038) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
loc_8239C040:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r4,r9
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, xer);
	// beq cr6,0x8239c064
	if (cr6.eq) goto loc_8239C064;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c040
	if (cr6.lt) goto loc_8239C040;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8239C064:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239C07C"))) PPC_WEAK_FUNC(sub_8239C07C);
PPC_FUNC_IMPL(__imp__sub_8239C07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239C080"))) PPC_WEAK_FUNC(sub_8239C080);
PPC_FUNC_IMPL(__imp__sub_8239C080) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// beq cr6,0x8239c0c0
	if (cr6.eq) goto loc_8239C0C0;
	// addi r10,r5,2118
	ctx.r10.s64 = ctx.r5.s64 + 2118;
	// lfs f0,8468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8468);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r5,5
	cr6.compare<int32_t>(ctx.r5.s32, 5, xer);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f0,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// beq cr6,0x8239c0e4
	if (cr6.eq) goto loc_8239C0E4;
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bne cr6,0x8239c0cc
	if (!cr6.eq) goto loc_8239C0CC;
	// lfs f13,8492(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8492);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f0,f1
	f0.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// b 0x8239c0f0
	goto loc_8239C0F0;
loc_8239C0C0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
loc_8239C0CC:
	// addi r10,r5,2119
	ctx.r10.s64 = ctx.r5.s64 + 2119;
	// lfs f0,8468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8468);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f0,f1
	f0.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// b 0x8239c0f0
	goto loc_8239C0F0;
loc_8239C0E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
loc_8239C0F0:
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r11,0
	r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8239C0FC:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8239c164
	if (cr6.eq) goto loc_8239C164;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c0fc
	if (cr6.lt) goto loc_8239C0FC;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8239C11C:
	// li r11,0
	r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8239C124:
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r7,100
	cr6.compare<int32_t>(ctx.r7.s32, 100, xer);
	// beq cr6,0x8239c17c
	if (cr6.eq) goto loc_8239C17C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c124
	if (cr6.lt) goto loc_8239C124;
	// li r7,0
	ctx.r7.s64 = 0;
loc_8239C144:
	// lfs f13,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x8239c198
	if (!cr6.lt) goto loc_8239C198;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8239c194
	if (!cr6.gt) goto loc_8239C194;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// b 0x8239c198
	goto loc_8239C198;
loc_8239C164:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// b 0x8239c11c
	goto loc_8239C11C;
loc_8239C17C:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// b 0x8239c144
	goto loc_8239C144;
loc_8239C194:
	// fmr f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = f0.f64;
loc_8239C198:
	// lfs f13,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8239c1b8
	if (!cr6.gt) goto loc_8239C1B8;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x8239c1b4
	if (!cr6.lt) goto loc_8239C1B4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x8239c1b8
	goto loc_8239C1B8;
loc_8239C1B4:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_8239C1B8:
	// fsubs f13,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lfs f0,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmadds f13,f13,f0,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
loc_8239C1D0:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,50
	cr6.compare<int32_t>(ctx.r8.s32, 50, xer);
	// beq cr6,0x8239c298
	if (cr6.eq) goto loc_8239C298;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c1d0
	if (cr6.lt) goto loc_8239C1D0;
	// li r11,0
	r11.s64 = 0;
loc_8239C1F0:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x8239c224
	if (!cr6.lt) goto loc_8239C224;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// li r11,0
	r11.s64 = 0;
loc_8239C204:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8239c2b0
	if (cr6.eq) goto loc_8239C2B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c204
	if (cr6.lt) goto loc_8239C204;
	// li r11,0
	r11.s64 = 0;
loc_8239C224:
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lfs f10,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f3,f8
	ctx.f3.f64 = double(ctx.f8.s64);
	// fsel f4,f11,f13,f12
	ctx.f4.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// fsubs f7,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// frsp f13,f3
	ctx.f13.f64 = double(float(ctx.f3.f64));
	// fsubs f1,f4,f10
	ctx.f1.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// fsel f12,f1,f10,f4
	ctx.f12.f64 = ctx.f1.f64 >= 0.0 ? ctx.f10.f64 : ctx.f4.f64;
	// fsubs f11,f13,f2
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f2.f64));
	// fsubs f10,f12,f9
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// fdivs f9,f10,f7
	ctx.f9.f64 = double(float(ctx.f10.f64 / ctx.f7.f64));
	// fmadds f8,f9,f11,f2
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f2.f64));
	// fadds f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 + f0.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_8239C298:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8239c1f0
	goto loc_8239C1F0;
loc_8239C2B0:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8239c224
	goto loc_8239C224;
}

__attribute__((alias("__imp__sub_8239C2C8"))) PPC_WEAK_FUNC(sub_8239C2C8);
PPC_FUNC_IMPL(__imp__sub_8239C2C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// cmpwi cr6,r4,50
	cr6.compare<int32_t>(ctx.r4.s32, 50, xer);
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// bge cr6,0x8239c38c
	if (!cr6.lt) goto loc_8239C38C;
loc_8239C2DC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8239c374
	if (cr6.eq) goto loc_8239C374;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c2dc
	if (cr6.lt) goto loc_8239C2DC;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8239C2FC:
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8239C304:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,50
	cr6.compare<int32_t>(ctx.r9.s32, 50, xer);
	// beq cr6,0x8239c3ec
	if (cr6.eq) goto loc_8239C3EC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c304
	if (cr6.lt) goto loc_8239C304;
loc_8239C320:
	// li r11,0
	r11.s64 = 0;
loc_8239C324:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r8,r10,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r10.s64;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fmadds f1,f5,f12,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + f0.f64));
	// blr 
	return;
loc_8239C374:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// b 0x8239c2fc
	goto loc_8239C2FC;
loc_8239C38C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,50
	cr6.compare<int32_t>(ctx.r8.s32, 50, xer);
	// beq cr6,0x8239c3d4
	if (cr6.eq) goto loc_8239C3D4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c38c
	if (cr6.lt) goto loc_8239C38C;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8239C3AC:
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8239C3B4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,100
	cr6.compare<int32_t>(ctx.r9.s32, 100, xer);
	// beq cr6,0x8239c3ec
	if (cr6.eq) goto loc_8239C3EC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c3b4
	if (cr6.lt) goto loc_8239C3B4;
	// b 0x8239c320
	goto loc_8239C320;
loc_8239C3D4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// b 0x8239c3ac
	goto loc_8239C3AC;
loc_8239C3EC:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8239c324
	goto loc_8239C324;
}

__attribute__((alias("__imp__sub_8239C404"))) PPC_WEAK_FUNC(sub_8239C404);
PPC_FUNC_IMPL(__imp__sub_8239C404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239C408"))) PPC_WEAK_FUNC(sub_8239C408);
PPC_FUNC_IMPL(__imp__sub_8239C408) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,13156
	ctx.r4.s64 = r11.s64 + 13156;
	// bl 0x821cfe20
	ctx.lr = 0x8239C434;
	sub_821CFE20(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8239C44C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r31,4
	ctx.r9.s64 = r31.s64 + 4;
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8239C458:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// beq cr6,0x8239c478
	if (cr6.eq) goto loc_8239C478;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c458
	if (cr6.lt) goto loc_8239C458;
	// b 0x8239c494
	goto loc_8239C494;
loc_8239C478:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239c518
	if (!cr6.eq) goto loc_8239C518;
loc_8239C494:
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8239C49C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x8239c530
	if (cr6.eq) goto loc_8239C530;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c49c
	if (cr6.lt) goto loc_8239C49C;
	// li r31,0
	r31.s64 = 0;
loc_8239C4BC:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,13144
	ctx.r4.s64 = r11.s64 + 13144;
	// bl 0x821cfe20
	ctx.lr = 0x8239C4D0;
	sub_821CFE20(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8239C4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-24932
	ctx.r4.s64 = ctx.r8.s64 + -24932;
	// bl 0x821cfe20
	ctx.lr = 0x8239C4FC;
	sub_821CFE20(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8239C514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_8239C518:
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
loc_8239C530:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// b 0x8239c4bc
	goto loc_8239C4BC;
}

__attribute__((alias("__imp__sub_8239C548"))) PPC_WEAK_FUNC(sub_8239C548);
PPC_FUNC_IMPL(__imp__sub_8239C548) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// beq cr6,0x8239c588
	if (cr6.eq) goto loc_8239C588;
	// addi r10,r5,2118
	ctx.r10.s64 = ctx.r5.s64 + 2118;
	// lfs f0,8468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8468);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r5,5
	cr6.compare<int32_t>(ctx.r5.s32, 5, xer);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f0,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// beq cr6,0x8239c5ac
	if (cr6.eq) goto loc_8239C5AC;
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bne cr6,0x8239c594
	if (!cr6.eq) goto loc_8239C594;
	// lfs f13,8492(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8492);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f0,f1
	f0.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// b 0x8239c5b8
	goto loc_8239C5B8;
loc_8239C588:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
loc_8239C594:
	// addi r10,r5,2119
	ctx.r10.s64 = ctx.r5.s64 + 2119;
	// lfs f0,8468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8468);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f13,f0,f1
	f0.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// b 0x8239c5b8
	goto loc_8239C5B8;
loc_8239C5AC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
loc_8239C5B8:
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r11,0
	r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8239C5C4:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8239c630
	if (cr6.eq) goto loc_8239C630;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c5c4
	if (cr6.lt) goto loc_8239C5C4;
	// li r11,0
	r11.s64 = 0;
loc_8239C5E4:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
loc_8239C5EC:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,100
	cr6.compare<int32_t>(ctx.r9.s32, 100, xer);
	// beq cr6,0x8239c648
	if (cr6.eq) goto loc_8239C648;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x8239c5ec
	if (cr6.lt) goto loc_8239C5EC;
	// li r11,0
	r11.s64 = 0;
loc_8239C60C:
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// blt cr6,0x8239c624
	if (cr6.lt) goto loc_8239C624;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x8239c628
	if (!cr6.gt) goto loc_8239C628;
loc_8239C624:
	// li r11,0
	r11.s64 = 0;
loc_8239C628:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_8239C630:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8239c5e4
	goto loc_8239C5E4;
loc_8239C648:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8239c60c
	goto loc_8239C60C;
}

__attribute__((alias("__imp__sub_8239C660"))) PPC_WEAK_FUNC(sub_8239C660);
PPC_FUNC_IMPL(__imp__sub_8239C660) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// fmr f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64;
	// bl 0x8239c2c8
	ctx.lr = 0x8239C678;
	sub_8239C2C8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fsubs f1,f1,f4
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f4.f64));
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826bcaf0
	ctx.lr = 0x8239C688;
	sub_826BCAF0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239C698"))) PPC_WEAK_FUNC(sub_8239C698);
PPC_FUNC_IMPL(__imp__sub_8239C698) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8239C6AC;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-12036
	ctx.r3.s64 = r11.s64 + -12036;
	// bl 0x826bddb0
	ctx.lr = 0x8239C6C0;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239c6dc
	if (cr6.eq) goto loc_8239C6DC;
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
loc_8239C6DC:
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

__attribute__((alias("__imp__sub_8239C6F0"))) PPC_WEAK_FUNC(sub_8239C6F0);
PPC_FUNC_IMPL(__imp__sub_8239C6F0) {
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
	ctx.lr = 0x8239C6F8;
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r19,r11,30576
	r19.s64 = r11.s64 + 30576;
	// addi r4,r10,-2696
	ctx.r4.s64 = ctx.r10.s64 + -2696;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821ca540
	ctx.lr = 0x8239C714;
	sub_821CA540(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r20,0
	r20.s64 = 0;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// addi r21,r4,-30140
	r21.s64 = ctx.r4.s64 + -30140;
	// addi r30,r5,-12036
	r30.s64 = ctx.r5.s64 + -12036;
	// addi r27,r6,-13276
	r27.s64 = ctx.r6.s64 + -13276;
	// addi r26,r7,-29624
	r26.s64 = ctx.r7.s64 + -29624;
	// addi r25,r8,-18144
	r25.s64 = ctx.r8.s64 + -18144;
	// addi r22,r9,13188
	r22.s64 = ctx.r9.s64 + 13188;
	// addi r24,r10,-32764
	r24.s64 = ctx.r10.s64 + -32764;
	// addi r23,r11,13160
	r23.s64 = r11.s64 + 13160;
loc_8239C75C:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x8239C770;
	sub_82137A08(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821ca6a8
	ctx.lr = 0x8239C788;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239c904
	if (cr6.eq) goto loc_8239C904;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d1cd0
	ctx.lr = 0x8239C79C;
	sub_821D1CD0(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cf7b8
	ctx.lr = 0x8239C7AC;
	sub_821CF7B8(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cff40
	ctx.lr = 0x8239C7BC;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239c8f8
	if (cr6.eq) goto loc_8239C8F8;
loc_8239C7C8:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0898
	ctx.lr = 0x8239C7D4;
	sub_821D0898(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfe20
	ctx.lr = 0x8239C7E0;
	sub_821CFE20(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cfaa8
	ctx.lr = 0x8239C7F0;
	sub_821CFAA8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82396408
	ctx.lr = 0x8239C7F8;
	sub_82396408(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8239c8d4
	if (cr6.eq) goto loc_8239C8D4;
	// lwz r11,-12120(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239c8d4
	if (!cr6.eq) goto loc_8239C8D4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x8239C824;
	sub_821C9790(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239c888
	if (cr6.eq) goto loc_8239C888;
	// divwu r9,r3,r11
	ctx.r9.u32 = ctx.r3.u32 / r11.u32;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// twllei r11,0
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r10
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239c888
	if (cr6.eq) goto loc_8239C888;
loc_8239C854:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x8239c870
	if (cr6.eq) goto loc_8239C870;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239c854
	if (!cr6.eq) goto loc_8239C854;
	// b 0x8239c888
	goto loc_8239C888;
loc_8239C870:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239c888
	if (cr6.eq) goto loc_8239C888;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8239c8c8
	if (!cr6.eq) goto loc_8239C8C8;
loc_8239C888:
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82130528
	ctx.lr = 0x8239C890;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239c8a8
	if (cr6.eq) goto loc_8239C8A8;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8239bfb0
	ctx.lr = 0x8239C8A0;
	sub_8239BFB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8239c8ac
	goto loc_8239C8AC;
loc_8239C8A8:
	// li r31,0
	r31.s64 = 0;
loc_8239C8AC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x8239C8C8;
	sub_82389998(ctx, base);
loc_8239C8C8:
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239c408
	ctx.lr = 0x8239C8D4;
	sub_8239C408(ctx, base);
loc_8239C8D4:
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821d0260
	ctx.lr = 0x8239C8DC;
	sub_821D0260(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x821cff40
	ctx.lr = 0x8239C8EC;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239c7c8
	if (!cr6.eq) goto loc_8239C7C8;
loc_8239C8F8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8239C900;
	sub_821BE610(ctx, base);
	// stw r21,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r21.u32);
loc_8239C904:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// cmpwi cr6,r20,5
	cr6.compare<int32_t>(r20.s32, 5, xer);
	// blt cr6,0x8239c75c
	if (cr6.lt) goto loc_8239C75C;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239C918;
	sub_821C9A90(ctx, base);
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8239C920"))) PPC_WEAK_FUNC(sub_8239C920);
PPC_FUNC_IMPL(__imp__sub_8239C920) {
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
	ctx.lr = 0x8239C928;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r11,-12036
	r31.s64 = r11.s64 + -12036;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// bl 0x82237920
	ctx.lr = 0x8239C94C;
	sub_82237920(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239c9c0
	if (cr6.eq) goto loc_8239C9C0;
loc_8239C958:
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x822b7bd0
	ctx.lr = 0x8239C970;
	sub_822B7BD0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239C978;
	sub_82130588(ctx, base);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8239c9ac
	if (!cr6.gt) goto loc_8239C9AC;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_8239C990:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8239c9ac
	if (!cr6.eq) goto loc_8239C9AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8239c990
	if (cr6.lt) goto loc_8239C990;
loc_8239C9AC:
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8239c958
	if (!cr6.eq) goto loc_8239C958;
loc_8239C9C0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8239C9C8"))) PPC_WEAK_FUNC(sub_8239C9C8);
PPC_FUNC_IMPL(__imp__sub_8239C9C8) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x8239C9EC;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x8239C9F8;
	sub_821C9790(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8239CA14"))) PPC_WEAK_FUNC(sub_8239CA14);
PPC_FUNC_IMPL(__imp__sub_8239CA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239CA18"))) PPC_WEAK_FUNC(sub_8239CA18);
PPC_FUNC_IMPL(__imp__sub_8239CA18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,80(r3)
	PPC_STORE_U8(ctx.r3.u32 + 80, r11.u8);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239CA28"))) PPC_WEAK_FUNC(sub_8239CA28);
PPC_FUNC_IMPL(__imp__sub_8239CA28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r6,72(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 72);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x8239ca84
	if (!cr6.gt) goto loc_8239CA84;
	// lwz r5,68(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_8239CA40:
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8239CA48:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// beq cr6,0x8239ca6c
	if (cr6.eq) goto loc_8239CA6C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8239ca48
	if (cr6.eq) goto loc_8239CA48;
loc_8239CA6C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8239ca8c
	if (cr6.eq) goto loc_8239CA8C;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,65
	ctx.r8.s64 = ctx.r8.s64 + 65;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// blt cr6,0x8239ca40
	if (cr6.lt) goto loc_8239CA40;
loc_8239CA84:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8239CA8C:
	// rlwinm r11,r7,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// add r3,r11,r5
	ctx.r3.u64 = r11.u64 + ctx.r5.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239CA9C"))) PPC_WEAK_FUNC(sub_8239CA9C);
PPC_FUNC_IMPL(__imp__sub_8239CA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239CAA0"))) PPC_WEAK_FUNC(sub_8239CAA0);
PPC_FUNC_IMPL(__imp__sub_8239CAA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lhz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 72);
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// twllei r9,0
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
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// rldicl r4,r11,32,32
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r5,r8,r9
	ctx.r5.s32 = ctx.r8.s32 / ctx.r9.s32;
	// stw r4,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// andc r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// twlgei r7,-1
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239CB10"))) PPC_WEAK_FUNC(sub_8239CB10);
PPC_FUNC_IMPL(__imp__sub_8239CB10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239cb88
	if (cr6.eq) goto loc_8239CB88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lhz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 72);
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// twllei r9,0
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
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// rldicl r4,r11,32,32
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r5,r8,r9
	ctx.r5.s32 = ctx.r8.s32 / ctx.r9.s32;
	// stw r4,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// andc r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// twlgei r7,-1
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_8239CB88:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239CB90"))) PPC_WEAK_FUNC(sub_8239CB90);
PPC_FUNC_IMPL(__imp__sub_8239CB90) {
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
	// bl 0x8239cb10
	ctx.lr = 0x8239CBB0;
	sub_8239CB10(ctx, base);
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

__attribute__((alias("__imp__sub_8239CBCC"))) PPC_WEAK_FUNC(sub_8239CBCC);
PPC_FUNC_IMPL(__imp__sub_8239CBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239CBD0"))) PPC_WEAK_FUNC(sub_8239CBD0);
PPC_FUNC_IMPL(__imp__sub_8239CBD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239cbf0
	if (cr6.eq) goto loc_8239CBF0;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_8239CBF0:
	// li r11,100
	r11.s64 = 100;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239CBFC"))) PPC_WEAK_FUNC(sub_8239CBFC);
PPC_FUNC_IMPL(__imp__sub_8239CBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239CC00"))) PPC_WEAK_FUNC(sub_8239CC00);
PPC_FUNC_IMPL(__imp__sub_8239CC00) {
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
	ctx.lr = 0x8239CC08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
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
	// bne cr6,0x8239cc80
	if (!cr6.eq) goto loc_8239CC80;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x82398720
	ctx.lr = 0x8239CC30;
	sub_82398720(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8239cc74
	if (cr6.eq) goto loc_8239CC74;
	// li r30,0
	r30.s64 = 0;
loc_8239CC44:
	// rlwinm r11,r30,6,0,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,65
	ctx.r5.s64 = 65;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x823da950
	ctx.lr = 0x8239CC60;
	sub_823DA950(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x8239cc44
	if (cr6.lt) goto loc_8239CC44;
loc_8239CC74:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8239CC7C;
	sub_82130588(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_8239CC80:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,6
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8239CCA4"))) PPC_WEAK_FUNC(sub_8239CCA4);
PPC_FUNC_IMPL(__imp__sub_8239CCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239CCA8"))) PPC_WEAK_FUNC(sub_8239CCA8);
PPC_FUNC_IMPL(__imp__sub_8239CCA8) {
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
	ctx.lr = 0x8239CCB0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,13512
	ctx.r4.s64 = r11.s64 + 13512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8239CCD0;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8239cd90
	if (cr6.eq) goto loc_8239CD90;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// bl 0x821d0898
	ctx.lr = 0x8239CCEC;
	sub_821D0898(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,9848
	r30.s64 = r11.s64 + 9848;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x8239CD04;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8239cd80
	if (cr6.eq) goto loc_8239CD80;
loc_8239CD10:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe20
	ctx.lr = 0x8239CD1C;
	sub_821CFE20(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239CD38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8239ca28
	ctx.lr = 0x8239CD44;
	sub_8239CA28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8239cd64
	if (!cr6.eq) goto loc_8239CD64;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r29,68
	ctx.r3.s64 = r29.s64 + 68;
	// bl 0x8239cc00
	ctx.lr = 0x8239CD58;
	sub_8239CC00(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x8239CD64;
	sub_823DB670(ctx, base);
loc_8239CD64:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8239CD74;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239cd10
	if (!cr6.eq) goto loc_8239CD10;
loc_8239CD80:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-29628
	ctx.r4.s64 = r11.s64 + -29628;
	// bl 0x821d0898
	ctx.lr = 0x8239CD90;
	sub_821D0898(ctx, base);
loc_8239CD90:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8239CD98"))) PPC_WEAK_FUNC(sub_8239CD98);
PPC_FUNC_IMPL(__imp__sub_8239CD98) {
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
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-12200
	ctx.r4.s64 = r11.s64 + -12200;
	// addi r3,r10,13584
	ctx.r3.s64 = ctx.r10.s64 + 13584;
	// bl 0x82554798
	ctx.lr = 0x8239CDB8;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-13424
	ctx.r4.s64 = ctx.r9.s64 + -13424;
	// addi r3,r8,13548
	ctx.r3.s64 = ctx.r8.s64 + 13548;
	// bl 0x82554798
	ctx.lr = 0x8239CDCC;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-13360
	ctx.r4.s64 = ctx.r7.s64 + -13360;
	// addi r3,r6,13520
	ctx.r3.s64 = ctx.r6.s64 + 13520;
	// bl 0x82554798
	ctx.lr = 0x8239CDE0;
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

__attribute__((alias("__imp__sub_8239CDF0"))) PPC_WEAK_FUNC(sub_8239CDF0);
PPC_FUNC_IMPL(__imp__sub_8239CDF0) {
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
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x8239CE14;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239ce44
	if (!cr6.gt) goto loc_8239CE44;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8239CE24:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239ce38
	if (cr6.eq) goto loc_8239CE38;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_8239CE38:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,40
	r11.s64 = r11.s64 + 40;
	// bne 0x8239ce24
	if (!cr0.eq) goto loc_8239CE24;
loc_8239CE44:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239CE58"))) PPC_WEAK_FUNC(sub_8239CE58);
PPC_FUNC_IMPL(__imp__sub_8239CE58) {
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
	ctx.lr = 0x8239CE60;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,100
	r28.s64 = 100;
	// bl 0x8239c698
	ctx.lr = 0x8239CE80;
	sub_8239C698(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239cf2c
	if (cr6.eq) goto loc_8239CF2C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8239c038
	ctx.lr = 0x8239CE94;
	sub_8239C038(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f31.f64 = double(temp.f32);
	// bl 0x8239c038
	ctx.lr = 0x8239CEA8;
	sub_8239C038(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// fsubs f12,f0,f31
	ctx.f12.f64 = double(float(f0.f64 - f31.f64));
	// addi r8,r29,2118
	ctx.r8.s64 = r29.s64 + 2118;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,12196(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12196);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f30,f13
	ctx.f11.f64 = double(float(f30.f64 + ctx.f13.f64));
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,8468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8468);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// lfsx f9,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f11,f9,f10,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f11.f64));
	// beq cr6,0x8239cf00
	if (cr6.eq) goto loc_8239CF00;
	// fsubs f13,f11,f31
	ctx.f13.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f11,f13,f11,f31
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f9,f10,f0,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fdivs f13,f8,f12
	ctx.f13.f64 = double(float(ctx.f8.f64 / ctx.f12.f64));
loc_8239CF00:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8239CF2C:
	// stw r28,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r28.u32);
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

__attribute__((alias("__imp__sub_8239CF40"))) PPC_WEAK_FUNC(sub_8239CF40);
PPC_FUNC_IMPL(__imp__sub_8239CF40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// lhz r11,4(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// beq cr6,0x8239cfa0
	if (cr6.eq) goto loc_8239CFA0;
	// subf r6,r5,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r5.s64;
loc_8239CF70:
	// add r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 + ctx.r9.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// li r8,10
	ctx.r8.s64 = 10;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8239CF80:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8239cf80
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8239CF80;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bne cr6,0x8239cf70
	if (!cr6.eq) goto loc_8239CF70;
loc_8239CFA0:
	// subf r11,r4,r5
	r11.s64 = ctx.r5.s64 - ctx.r4.s64;
	// lhz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// li r9,40
	ctx.r9.s64 = 40;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// divw r8,r11,r9
	ctx.r8.s32 = r11.s32 / ctx.r9.s32;
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,4(r7)
	PPC_STORE_U16(ctx.r7.u32 + 4, ctx.r6.u16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239CFC4"))) PPC_WEAK_FUNC(sub_8239CFC4);
PPC_FUNC_IMPL(__imp__sub_8239CFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239CFC8"))) PPC_WEAK_FUNC(sub_8239CFC8);
PPC_FUNC_IMPL(__imp__sub_8239CFC8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239d00c
	if (cr6.eq) goto loc_8239D00C;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239d00c
	if (cr6.eq) goto loc_8239D00C;
	// bl 0x8238efe8
	ctx.lr = 0x8239D000;
	sub_8238EFE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8239ce58
	ctx.lr = 0x8239D00C;
	sub_8239CE58(ctx, base);
loc_8239D00C:
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

__attribute__((alias("__imp__sub_8239D024"))) PPC_WEAK_FUNC(sub_8239D024);
PPC_FUNC_IMPL(__imp__sub_8239D024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D028"))) PPC_WEAK_FUNC(sub_8239D028);
PPC_FUNC_IMPL(__imp__sub_8239D028) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239d048
	if (cr6.eq) goto loc_8239D048;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_8239D048:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D054"))) PPC_WEAK_FUNC(sub_8239D054);
PPC_FUNC_IMPL(__imp__sub_8239D054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D058"))) PPC_WEAK_FUNC(sub_8239D058);
PPC_FUNC_IMPL(__imp__sub_8239D058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D06C"))) PPC_WEAK_FUNC(sub_8239D06C);
PPC_FUNC_IMPL(__imp__sub_8239D06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D070"))) PPC_WEAK_FUNC(sub_8239D070);
PPC_FUNC_IMPL(__imp__sub_8239D070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D088"))) PPC_WEAK_FUNC(sub_8239D088);
PPC_FUNC_IMPL(__imp__sub_8239D088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// rlwinm r11,r7,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D0B4"))) PPC_WEAK_FUNC(sub_8239D0B4);
PPC_FUNC_IMPL(__imp__sub_8239D0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D0B8"))) PPC_WEAK_FUNC(sub_8239D0B8);
PPC_FUNC_IMPL(__imp__sub_8239D0B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// ori r8,r9,64167
	ctx.r8.u64 = ctx.r9.u64 | 64167;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addis r6,r11,1
	ctx.r6.s64 = r11.s64 + 65536;
	// addi r6,r6,27768
	ctx.r6.s64 = ctx.r6.s64 + 27768;
	// lhz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// twllei r5,0
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r8
	ctx.r10.s64 = ctx.r4.s64 * ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// divw r6,r8,r5
	ctx.r6.s32 = ctx.r8.s32 / ctx.r5.s32;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r4,r6,r5
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r8,r5,r9
	ctx.r8.u64 = ctx.r5.u64 & ~ctx.r9.u64;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// twlgei r8,-1
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// stw r4,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D13C"))) PPC_WEAK_FUNC(sub_8239D13C);
PPC_FUNC_IMPL(__imp__sub_8239D13C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D140"))) PPC_WEAK_FUNC(sub_8239D140);
PPC_FUNC_IMPL(__imp__sub_8239D140) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8239d1e8
	if (!cr6.eq) goto loc_8239D1E8;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x8239cdf0
	ctx.lr = 0x8239D178;
	sub_8239CDF0(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8239d1dc
	if (cr6.eq) goto loc_8239D1DC;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8239D18C:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,10
	ctx.r8.s64 = 10;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8239D1B4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8239d1b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8239D1B4;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8239d18c
	if (cr6.lt) goto loc_8239D18C;
loc_8239D1DC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8239D1E4;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8239D1E8:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
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

__attribute__((alias("__imp__sub_8239D220"))) PPC_WEAK_FUNC(sub_8239D220);
PPC_FUNC_IMPL(__imp__sub_8239D220) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8239D228;
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lfs f30,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f30.f64 = double(temp.f32);
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// li r26,0
	r26.s64 = 0;
	// li r19,1
	r19.s64 = 1;
	// addi r22,r11,-12036
	r22.s64 = r11.s64 + -12036;
loc_8239D264:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x8239cf40
	ctx.lr = 0x8239D284;
	sub_8239CF40(ctx, base);
	// lwz r3,52(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x8239D28C;
	sub_8238EFE8(ctx, base);
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82237920
	ctx.lr = 0x8239D2A4;
	sub_82237920(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239d404
	if (cr6.eq) goto loc_8239D404;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8239D2B4:
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82396fb8
	ctx.lr = 0x8239D2C0;
	sub_82396FB8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823960f8
	ctx.lr = 0x8239D2C8;
	sub_823960F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239d324
	if (cr6.eq) goto loc_8239D324;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bne cr6,0x8239d2b4
	if (!cr6.eq) goto loc_8239D2B4;
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// lhz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
loc_8239D2F4:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x8239d3f4
	if (!cr6.lt) goto loc_8239D3F4;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r31,r7,r11
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239d2f4
	if (cr6.eq) goto loc_8239D2F4;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// b 0x8239d2b4
	goto loc_8239D2B4;
loc_8239D324:
	// lbz r11,42(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 42);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239d344
	if (cr6.eq) goto loc_8239D344;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x8239D338;
	sub_82186D30(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8239d3fc
	goto loc_8239D3FC;
loc_8239D344:
	// lwz r11,60(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// and r10,r11,r23
	ctx.r10.u64 = r11.u64 & r23.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8239d368
	if (!cr6.eq) goto loc_8239D368;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x8239D35C;
	sub_82186D30(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8239d3fc
	goto loc_8239D3FC;
loc_8239D368:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// slw r10,r19,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r19.u32 << (r11.u8 & 0x3F));
	// and r9,r10,r25
	ctx.r9.u64 = ctx.r10.u64 & r25.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8239d390
	if (!cr6.eq) goto loc_8239D390;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x8239D384;
	sub_82186D30(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8239d3fc
	goto loc_8239D3FC;
loc_8239D390:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8239c548
	ctx.lr = 0x8239D3A0;
	sub_8239C548(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239d3e0
	if (cr6.eq) goto loc_8239D3E0;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8239d140
	ctx.lr = 0x8239D3B8;
	sub_8239D140(ctx, base);
	// addi r31,r28,40
	r31.s64 = r28.s64 + 40;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8239D3CC;
	sub_821C9790(ctx, base);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x8239D3E0;
	sub_823DB670(ctx, base);
loc_8239D3E0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82186d30
	ctx.lr = 0x8239D3E8;
	sub_82186D30(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8239d3fc
	goto loc_8239D3FC;
loc_8239D3F4:
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
loc_8239D3FC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8239d2b4
	if (!cr6.eq) goto loc_8239D2B4;
loc_8239D404:
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x8239d494
	if (cr6.gt) goto loc_8239D494;
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// addi r11,r24,1
	r11.s64 = r24.s64 + 1;
	// blt cr6,0x8239d420
	if (cr6.lt) goto loc_8239D420;
	// addi r11,r24,-1
	r11.s64 = r24.s64 + -1;
loc_8239D420:
	// cmpwi cr6,r11,-2
	cr6.compare<int32_t>(r11.s32, -2, xer);
	// beq cr6,0x8239d444
	if (cr6.eq) goto loc_8239D444;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8239d444
	if (cr6.eq) goto loc_8239D444;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r25,r21
	r25.u64 = r21.u64;
	// mr r24,r11
	r24.u64 = r11.u64;
	// li r21,-1
	r21.s64 = -1;
	// b 0x8239d264
	goto loc_8239D264;
loc_8239D444:
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// bl 0x82237920
	ctx.lr = 0x8239D458;
	sub_82237920(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8239d140
	ctx.lr = 0x8239D464;
	sub_8239D140(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r31,r11,40
	r31.s64 = r11.s64 + 40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x8239D480;
	sub_821C9790(ctx, base);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x8239D494;
	sub_823DB670(ctx, base);
loc_8239D494:
	// lhz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8239D4A8"))) PPC_WEAK_FUNC(sub_8239D4A8);
PPC_FUNC_IMPL(__imp__sub_8239D4A8) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x8239cf40
	ctx.lr = 0x8239D4E0;
	sub_8239CF40(ctx, base);
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8239d4f4
	if (cr6.eq) goto loc_8239D4F4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8239D4F4;
	sub_82130588(ctx, base);
loc_8239D4F4:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239d50c
	if (cr6.eq) goto loc_8239D50C;
	// bl 0x82130588
	ctx.lr = 0x8239D508;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239D50C:
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

__attribute__((alias("__imp__sub_8239D524"))) PPC_WEAK_FUNC(sub_8239D524);
PPC_FUNC_IMPL(__imp__sub_8239D524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D528"))) PPC_WEAK_FUNC(sub_8239D528);
PPC_FUNC_IMPL(__imp__sub_8239D528) {
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
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8239D544;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8239d578
	if (cr6.eq) goto loc_8239D578;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
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
loc_8239D578:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239D594"))) PPC_WEAK_FUNC(sub_8239D594);
PPC_FUNC_IMPL(__imp__sub_8239D594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D598"))) PPC_WEAK_FUNC(sub_8239D598);
PPC_FUNC_IMPL(__imp__sub_8239D598) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// beq cr6,0x8239d5f8
	if (cr6.eq) goto loc_8239D5F8;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8239d5f8
	if (cr6.eq) goto loc_8239D5F8;
	// bl 0x8239d220
	ctx.lr = 0x8239D5DC;
	sub_8239D220(ctx, base);
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
loc_8239D5F8:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239D618"))) PPC_WEAK_FUNC(sub_8239D618);
PPC_FUNC_IMPL(__imp__sub_8239D618) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8239d4a8
	sub_8239D4A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239D630"))) PPC_WEAK_FUNC(sub_8239D630);
PPC_FUNC_IMPL(__imp__sub_8239D630) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D634"))) PPC_WEAK_FUNC(sub_8239D634);
PPC_FUNC_IMPL(__imp__sub_8239D634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D638"))) PPC_WEAK_FUNC(sub_8239D638);
PPC_FUNC_IMPL(__imp__sub_8239D638) {
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
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-12344
	ctx.r4.s64 = r11.s64 + -12344;
	// addi r3,r10,13964
	ctx.r3.s64 = ctx.r10.s64 + 13964;
	// bl 0x82554798
	ctx.lr = 0x8239D658;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-12248
	ctx.r4.s64 = ctx.r9.s64 + -12248;
	// addi r3,r8,13936
	ctx.r3.s64 = ctx.r8.s64 + 13936;
	// bl 0x82554798
	ctx.lr = 0x8239D66C;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-12200
	ctx.r4.s64 = ctx.r7.s64 + -12200;
	// addi r3,r6,13912
	ctx.r3.s64 = ctx.r6.s64 + 13912;
	// bl 0x82554798
	ctx.lr = 0x8239D680;
	sub_82554798(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r4,r5,-10968
	ctx.r4.s64 = ctx.r5.s64 + -10968;
	// addi r3,r3,14116
	ctx.r3.s64 = ctx.r3.s64 + 14116;
	// bl 0x82554798
	ctx.lr = 0x8239D694;
	sub_82554798(ctx, base);
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-10728
	ctx.r4.s64 = r11.s64 + -10728;
	// addi r3,r10,14096
	ctx.r3.s64 = ctx.r10.s64 + 14096;
	// bl 0x82554798
	ctx.lr = 0x8239D6A8;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-12176
	ctx.r4.s64 = ctx.r9.s64 + -12176;
	// addi r3,r8,14076
	ctx.r3.s64 = ctx.r8.s64 + 14076;
	// bl 0x82554798
	ctx.lr = 0x8239D6BC;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-10856
	ctx.r4.s64 = ctx.r7.s64 + -10856;
	// addi r3,r6,14060
	ctx.r3.s64 = ctx.r6.s64 + 14060;
	// bl 0x82554798
	ctx.lr = 0x8239D6D0;
	sub_82554798(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r4,r5,-12152
	ctx.r4.s64 = ctx.r5.s64 + -12152;
	// addi r3,r3,14032
	ctx.r3.s64 = ctx.r3.s64 + 14032;
	// bl 0x82554798
	ctx.lr = 0x8239D6E4;
	sub_82554798(ctx, base);
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-12104
	ctx.r4.s64 = r11.s64 + -12104;
	// addi r3,r10,13996
	ctx.r3.s64 = ctx.r10.s64 + 13996;
	// bl 0x82554798
	ctx.lr = 0x8239D6F8;
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

__attribute__((alias("__imp__sub_8239D708"))) PPC_WEAK_FUNC(sub_8239D708);
PPC_FUNC_IMPL(__imp__sub_8239D708) {
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
	// rlwinm r3,r31,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x8239D724;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8239d76c
	if (!cr6.gt) goto loc_8239D76C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8239D73C:
	// addic. r9,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r9.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8239d760
	if (cr0.eq) goto loc_8239D760;
	// stfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// stfs f0,-4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
loc_8239D760:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x8239d73c
	if (!cr0.eq) goto loc_8239D73C;
loc_8239D76C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239D780"))) PPC_WEAK_FUNC(sub_8239D780);
PPC_FUNC_IMPL(__imp__sub_8239D780) {
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
	ctx.lr = 0x8239D79C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239d7c8
	if (cr6.eq) goto loc_8239D7C8;
	// li r11,0
	r11.s64 = 0;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
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
loc_8239D7C8:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239D7E8"))) PPC_WEAK_FUNC(sub_8239D7E8);
PPC_FUNC_IMPL(__imp__sub_8239D7E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 8);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D800"))) PPC_WEAK_FUNC(sub_8239D800);
PPC_FUNC_IMPL(__imp__sub_8239D800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D818"))) PPC_WEAK_FUNC(sub_8239D818);
PPC_FUNC_IMPL(__imp__sub_8239D818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239D830"))) PPC_WEAK_FUNC(sub_8239D830);
PPC_FUNC_IMPL(__imp__sub_8239D830) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,14160
	ctx.r3.s64 = r11.s64 + 14160;
	// bl 0x82130000
	ctx.lr = 0x8239D854;
	sub_82130000(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8239D85C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239d87c
	if (cr6.eq) goto loc_8239D87C;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// b 0x8239d880
	goto loc_8239D880;
loc_8239D87C:
	// li r31,0
	r31.s64 = 0;
loc_8239D880:
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239d708
	ctx.lr = 0x8239D890;
	sub_8239D708(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stb r11,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r11.u8);
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

__attribute__((alias("__imp__sub_8239D8C0"))) PPC_WEAK_FUNC(sub_8239D8C0);
PPC_FUNC_IMPL(__imp__sub_8239D8C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8239d830
	sub_8239D830(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239D8D0"))) PPC_WEAK_FUNC(sub_8239D8D0);
PPC_FUNC_IMPL(__imp__sub_8239D8D0) {
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
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-10368
	ctx.r4.s64 = r11.s64 + -10368;
	// addi r3,r10,14316
	ctx.r3.s64 = ctx.r10.s64 + 14316;
	// bl 0x82554798
	ctx.lr = 0x8239D8F0;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-10048
	ctx.r4.s64 = ctx.r9.s64 + -10048;
	// addi r3,r8,14296
	ctx.r3.s64 = ctx.r8.s64 + 14296;
	// bl 0x82554798
	ctx.lr = 0x8239D904;
	sub_82554798(ctx, base);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,0
	ctx.r4.s64 = ctx.r7.s64 + 0;
	// addi r3,r6,14276
	ctx.r3.s64 = ctx.r6.s64 + 14276;
	// bl 0x82554798
	ctx.lr = 0x8239D918;
	sub_82554798(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r4,r5,-10264
	ctx.r4.s64 = ctx.r5.s64 + -10264;
	// addi r3,r3,14252
	ctx.r3.s64 = ctx.r3.s64 + 14252;
	// bl 0x82554798
	ctx.lr = 0x8239D92C;
	sub_82554798(ctx, base);
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-10240
	ctx.r4.s64 = r11.s64 + -10240;
	// addi r3,r10,14216
	ctx.r3.s64 = ctx.r10.s64 + 14216;
	// bl 0x82554798
	ctx.lr = 0x8239D940;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-10216
	ctx.r4.s64 = ctx.r9.s64 + -10216;
	// addi r3,r8,14192
	ctx.r3.s64 = ctx.r8.s64 + 14192;
	// bl 0x82554798
	ctx.lr = 0x8239D954;
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

__attribute__((alias("__imp__sub_8239D964"))) PPC_WEAK_FUNC(sub_8239D964);
PPC_FUNC_IMPL(__imp__sub_8239D964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239D968"))) PPC_WEAK_FUNC(sub_8239D968);
PPC_FUNC_IMPL(__imp__sub_8239D968) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r3,-12024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12024);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239d99c
	if (cr6.eq) goto loc_8239D99C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239D99C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239D99C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12024(r31)
	PPC_STORE_U32(r31.u32 + -12024, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239D9B8"))) PPC_WEAK_FUNC(sub_8239D9B8);
PPC_FUNC_IMPL(__imp__sub_8239D9B8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,14740
	ctx.r10.s64 = r11.s64 + 14740;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8239D9E4;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8239d9fc
	if (cr6.eq) goto loc_8239D9FC;
	// bl 0x82130588
	ctx.lr = 0x8239D9F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239D9FC:
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

__attribute__((alias("__imp__sub_8239DA14"))) PPC_WEAK_FUNC(sub_8239DA14);
PPC_FUNC_IMPL(__imp__sub_8239DA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239DA18"))) PPC_WEAK_FUNC(sub_8239DA18);
PPC_FUNC_IMPL(__imp__sub_8239DA18) {
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
	ctx.lr = 0x8239DA20;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r3,8
	r30.s64 = ctx.r3.s64 + 8;
	// addi r28,r5,14848
	r28.s64 = ctx.r5.s64 + 14848;
	// addi r27,r6,14832
	r27.s64 = ctx.r6.s64 + 14832;
	// addi r26,r7,14816
	r26.s64 = ctx.r7.s64 + 14816;
	// addi r25,r8,14800
	r25.s64 = ctx.r8.s64 + 14800;
	// addi r24,r9,14784
	r24.s64 = ctx.r9.s64 + 14784;
	// addi r23,r10,14760
	r23.s64 = ctx.r10.s64 + 14760;
	// addi r22,r11,14744
	r22.s64 = r11.s64 + 14744;
loc_8239DA68:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DA7C;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,-4
	ctx.r6.s64 = r30.s64 + -4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DA98;
	sub_824DF200(ctx, base);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DAAC;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DAC8;
	sub_824DF200(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DADC;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,4
	ctx.r6.s64 = r30.s64 + 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DAF8;
	sub_824DF200(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DB0C;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,8
	ctx.r6.s64 = r30.s64 + 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DB28;
	sub_824DF200(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DB3C;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,12
	ctx.r6.s64 = r30.s64 + 12;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DB58;
	sub_824DF200(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DB6C;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,16
	ctx.r6.s64 = r30.s64 + 16;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DB88;
	sub_824DF200(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239DB9C;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r30,20
	ctx.r6.s64 = r30.s64 + 20;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8239DBB8;
	sub_824DF200(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,28
	r30.s64 = r30.s64 + 28;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x8239da68
	if (cr6.lt) goto loc_8239DA68;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8239DBD0"))) PPC_WEAK_FUNC(sub_8239DBD0);
PPC_FUNC_IMPL(__imp__sub_8239DBD0) {
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
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-5840(r1)
	ea = -5840 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,14704
	r30.s64 = r11.s64 + 14704;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824df990
	ctx.lr = 0x8239DC00;
	sub_824DF990(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239da18
	ctx.lr = 0x8239DC0C;
	sub_8239DA18(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r31,r10,30576
	r31.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,-2648
	ctx.r4.s64 = ctx.r9.s64 + -2648;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8239DC24;
	sub_821CA540(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r8,14712
	ctx.r4.s64 = ctx.r8.s64 + 14712;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e0288
	ctx.lr = 0x8239DC38;
	sub_824E0288(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8239DC44;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824dfa38
	ctx.lr = 0x8239DC4C;
	sub_824DFA38(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,5840
	ctx.r1.s64 = ctx.r1.s64 + 5840;
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

__attribute__((alias("__imp__sub_8239DC68"))) PPC_WEAK_FUNC(sub_8239DC68);
PPC_FUNC_IMPL(__imp__sub_8239DC68) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8239DC7C;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f9,14912(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14912);
	ctx.f9.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f8,14908(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14908);
	ctx.f8.f64 = double(temp.f32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f11,14904(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14904);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f12,-12084(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12084);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lfs f7,31540(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31540);
	ctx.f7.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f6,14900(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14900);
	ctx.f6.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f4,14896(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14896);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f3.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f2,31952(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31952);
	ctx.f2.f64 = double(temp.f32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lfs f1,14892(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14892);
	ctx.f1.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lfs f10,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfs f5,31308(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31308);
	ctx.f5.f64 = double(temp.f32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f31,14888(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14888);
	f31.f64 = double(temp.f32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lfs f30,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	f30.f64 = double(temp.f32);
	// lfs f29,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f29.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,14740
	ctx.r7.s64 = ctx.r8.s64 + 14740;
	// lfs f28,-3164(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3164);
	f28.f64 = double(temp.f32);
	// lfs f27,14880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14880);
	f27.f64 = double(temp.f32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lfs f26,14876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14876);
	f26.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f8,12(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f11,36(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f12,40(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f13,44(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f13,48(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f7,64(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f6,68(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f5,80(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f4,84(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f3,88(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f2,92(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f1,96(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f10,104(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f30,116(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f29,120(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f28,124(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f27,136(r31)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f26,140(r31)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f9,14872(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14872);
	ctx.f9.f64 = double(temp.f32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stfs f9,148(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stfs f0,144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stfs f13,156(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stfs f13,160(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// lfs f8,-28668(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -28668);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,14868(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14868);
	ctx.f7.f64 = double(temp.f32);
	// lfs f9,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f9.f64 = double(temp.f32);
	// lfs f6,-30504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30504);
	ctx.f6.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f8,152(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f0,180(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f7,184(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// stfs f0,188(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// stfs f0,192(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f13,196(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f0,200(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// stfs f11,204(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// stfs f12,208(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f9,212(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f0,220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stfs f13,224(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stfs f0,228(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// stfs f6,232(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// stfs f12,236(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 236, temp.u32);
	// stfs f9,240(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// stfs f0,244(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stfs f0,248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f10,252(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// bl 0x8239dbd0
	ctx.lr = 0x8239DE5C;
	sub_8239DBD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba1c
	ctx.lr = 0x8239DE6C;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239DE7C"))) PPC_WEAK_FUNC(sub_8239DE7C);
PPC_FUNC_IMPL(__imp__sub_8239DE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239DE80"))) PPC_WEAK_FUNC(sub_8239DE80);
PPC_FUNC_IMPL(__imp__sub_8239DE80) {
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
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x8239DE94;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239deb8
	if (cr6.eq) goto loc_8239DEB8;
	// bl 0x8239dc68
	ctx.lr = 0x8239DEA0;
	sub_8239DC68(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-12024(r11)
	PPC_STORE_U32(r11.u32 + -12024, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8239DEB8:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12024(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12024, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239DED4"))) PPC_WEAK_FUNC(sub_8239DED4);
PPC_FUNC_IMPL(__imp__sub_8239DED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239DED8"))) PPC_WEAK_FUNC(sub_8239DED8);
PPC_FUNC_IMPL(__imp__sub_8239DED8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,15244
	ctx.r3.s64 = r11.s64 + 15244;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239DEE4"))) PPC_WEAK_FUNC(sub_8239DEE4);
PPC_FUNC_IMPL(__imp__sub_8239DEE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239DEE8"))) PPC_WEAK_FUNC(sub_8239DEE8);
PPC_FUNC_IMPL(__imp__sub_8239DEE8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,15212
	ctx.r10.s64 = r11.s64 + 15212;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e0430
	ctx.lr = 0x8239DF14;
	sub_824E0430(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8239df2c
	if (cr6.eq) goto loc_8239DF2C;
	// bl 0x82130588
	ctx.lr = 0x8239DF28;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239DF2C:
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

__attribute__((alias("__imp__sub_8239DF44"))) PPC_WEAK_FUNC(sub_8239DF44);
PPC_FUNC_IMPL(__imp__sub_8239DF44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239DF48"))) PPC_WEAK_FUNC(sub_8239DF48);
PPC_FUNC_IMPL(__imp__sub_8239DF48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,60
	r11.s64 = ctx.r4.s64 * 60;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239DF54"))) PPC_WEAK_FUNC(sub_8239DF54);
PPC_FUNC_IMPL(__imp__sub_8239DF54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239DF58"))) PPC_WEAK_FUNC(sub_8239DF58);
PPC_FUNC_IMPL(__imp__sub_8239DF58) {
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
	// bl 0x824e0648
	ctx.lr = 0x8239DF70;
	sub_824E0648(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f12,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lfs f11,6088(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 6088);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,15276(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15276);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r3,15212
	r11.s64 = ctx.r3.s64 + 15212;
	// lfs f9,14900(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14900);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f7,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f7.f64 = double(temp.f32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f11,28(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f10,32(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f9,36(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f8,44(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f7,48(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239E004"))) PPC_WEAK_FUNC(sub_8239E004);
PPC_FUNC_IMPL(__imp__sub_8239E004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E008"))) PPC_WEAK_FUNC(sub_8239E008);
PPC_FUNC_IMPL(__imp__sub_8239E008) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,15468
	ctx.r5.s64 = r11.s64 + 15468;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E044;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,15448
	ctx.r5.s64 = ctx.r10.s64 + 15448;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E064;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,15428
	ctx.r5.s64 = ctx.r9.s64 + 15428;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E084;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,15416
	ctx.r5.s64 = ctx.r8.s64 + 15416;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E0A4;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,15400
	ctx.r5.s64 = ctx.r7.s64 + 15400;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,28
	ctx.r6.s64 = r31.s64 + 28;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E0C4;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,15384
	ctx.r5.s64 = ctx.r6.s64 + 15384;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E0E4;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,15368
	ctx.r5.s64 = ctx.r5.s64 + 15368;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,36
	ctx.r6.s64 = r31.s64 + 36;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E104;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,15352
	ctx.r5.s64 = ctx.r4.s64 + 15352;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,40
	ctx.r6.s64 = r31.s64 + 40;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E124;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,15336
	ctx.r5.s64 = r11.s64 + 15336;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,44
	ctx.r6.s64 = r31.s64 + 44;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E144;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,15320
	ctx.r5.s64 = ctx.r10.s64 + 15320;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,48
	ctx.r6.s64 = r31.s64 + 48;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8239E164;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,15300
	ctx.r5.s64 = ctx.r9.s64 + 15300;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,52
	ctx.r6.s64 = r31.s64 + 52;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8239E184;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,15280
	ctx.r5.s64 = ctx.r7.s64 + 15280;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8239E1A4;
	sub_824DF200(ctx, base);
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

__attribute__((alias("__imp__sub_8239E1BC"))) PPC_WEAK_FUNC(sub_8239E1BC);
PPC_FUNC_IMPL(__imp__sub_8239E1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E1C0"))) PPC_WEAK_FUNC(sub_8239E1C0);
PPC_FUNC_IMPL(__imp__sub_8239E1C0) {
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
	ctx.lr = 0x8239E1C8;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r31,5
	r31.s64 = 5;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8239E1D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239df58
	ctx.lr = 0x8239E1E0;
	sub_8239DF58(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,60
	r30.s64 = r30.s64 + 60;
	// bge 0x8239e1d8
	if (!cr0.lt) goto loc_8239E1D8;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r31,r27
	r31.u64 = r27.u64;
	// addi r29,r11,-26884
	r29.s64 = r11.s64 + -26884;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r29
	r30.u64 = r29.u64;
	// addi r28,r11,15488
	r28.s64 = r11.s64 + 15488;
loc_8239E204:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8239E218;
	sub_82137A08(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e06e0
	ctx.lr = 0x8239E224;
	sub_824E06E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239E238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r9,r29,24
	ctx.r9.s64 = r29.s64 + 24;
	// addi r31,r31,60
	r31.s64 = r31.s64 + 60;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x8239e204
	if (cr6.lt) goto loc_8239E204;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8239E258"))) PPC_WEAK_FUNC(sub_8239E258);
PPC_FUNC_IMPL(__imp__sub_8239E258) {
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
	// li r3,360
	ctx.r3.s64 = 360;
	// bl 0x82130528
	ctx.lr = 0x8239E26C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e290
	if (cr6.eq) goto loc_8239E290;
	// bl 0x8239e1c0
	ctx.lr = 0x8239E278;
	sub_8239E1C0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-12020(r11)
	PPC_STORE_U32(r11.u32 + -12020, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8239E290:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12020(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12020, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239E2AC"))) PPC_WEAK_FUNC(sub_8239E2AC);
PPC_FUNC_IMPL(__imp__sub_8239E2AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E2B0"))) PPC_WEAK_FUNC(sub_8239E2B0);
PPC_FUNC_IMPL(__imp__sub_8239E2B0) {
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
	ctx.lr = 0x8239E2B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r28,-12020(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + -12020);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8239e2fc
	if (cr6.eq) goto loc_8239E2FC;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r31,r28,360
	r31.s64 = r28.s64 + 360;
	// li r30,5
	r30.s64 = 5;
	// addi r29,r11,15212
	r29.s64 = r11.s64 + 15212;
loc_8239E2DC:
	// addi r31,r31,-60
	r31.s64 = r31.s64 + -60;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// bl 0x824e0430
	ctx.lr = 0x8239E2EC;
	sub_824E0430(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8239e2dc
	if (!cr0.lt) goto loc_8239E2DC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8239E2FC;
	sub_82130588(ctx, base);
loc_8239E2FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8239E304"))) PPC_WEAK_FUNC(sub_8239E304);
PPC_FUNC_IMPL(__imp__sub_8239E304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E308"))) PPC_WEAK_FUNC(sub_8239E308);
PPC_FUNC_IMPL(__imp__sub_8239E308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,-3164
	ctx.r10.s64 = r11.s64 + -3164;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239E318"))) PPC_WEAK_FUNC(sub_8239E318);
PPC_FUNC_IMPL(__imp__sub_8239E318) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// b 0x82618f90
	sub_82618F90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239E32C"))) PPC_WEAK_FUNC(sub_8239E32C);
PPC_FUNC_IMPL(__imp__sub_8239E32C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E330"))) PPC_WEAK_FUNC(sub_8239E330);
PPC_FUNC_IMPL(__imp__sub_8239E330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// b 0x82618f80
	sub_82618F80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239E344"))) PPC_WEAK_FUNC(sub_8239E344);
PPC_FUNC_IMPL(__imp__sub_8239E344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E348"))) PPC_WEAK_FUNC(sub_8239E348);
PPC_FUNC_IMPL(__imp__sub_8239E348) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239e3a0
	if (!cr6.eq) goto loc_8239E3A0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8239e3a0
	if (!cr6.eq) goto loc_8239E3A0;
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x8239E37C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e3a0
	if (cr6.eq) goto loc_8239E3A0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823d4610
	ctx.lr = 0x8239E38C;
	sub_823D4610(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8239E3A0:
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

__attribute__((alias("__imp__sub_8239E3B8"))) PPC_WEAK_FUNC(sub_8239E3B8);
PPC_FUNC_IMPL(__imp__sub_8239E3B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8239e3dc
	if (cr6.eq) goto loc_8239E3DC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8239e3d8
	if (cr6.eq) goto loc_8239E3D8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x823d5b68
	sub_823D5B68(ctx, base);
	return;
loc_8239E3D8:
	// b 0x823a31e8
	sub_823A31E8(ctx, base);
	return;
loc_8239E3DC:
	// b 0x823a1008
	sub_823A1008(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239E3E0"))) PPC_WEAK_FUNC(sub_8239E3E0);
PPC_FUNC_IMPL(__imp__sub_8239E3E0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239E3E4"))) PPC_WEAK_FUNC(sub_8239E3E4);
PPC_FUNC_IMPL(__imp__sub_8239E3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E3E8"))) PPC_WEAK_FUNC(sub_8239E3E8);
PPC_FUNC_IMPL(__imp__sub_8239E3E8) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r9,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r9.u8);
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r8,2(r31)
	PPC_STORE_U8(r31.u32 + 2, ctx.r8.u8);
	// lbz r7,3(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r7,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r7.u8);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// lhz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 8);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x821c9650
	ctx.lr = 0x8239E440;
	sub_821C9650(ctx, base);
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

__attribute__((alias("__imp__sub_8239E458"))) PPC_WEAK_FUNC(sub_8239E458);
PPC_FUNC_IMPL(__imp__sub_8239E458) {
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
	// stb r5,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r5.u8);
	// stb r6,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r6.u8);
	// stb r7,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r7.u8);
	// stb r8,11(r31)
	PPC_STORE_U8(r31.u32 + 11, ctx.r8.u8);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// beq cr6,0x8239e4cc
	if (cr6.eq) goto loc_8239E4CC;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8239E4A8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239e4a8
	if (!cr6.eq) goto loc_8239E4A8;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x8239E4CC;
	sub_821C9650(ctx, base);
loc_8239E4CC:
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

__attribute__((alias("__imp__sub_8239E4E4"))) PPC_WEAK_FUNC(sub_8239E4E4);
PPC_FUNC_IMPL(__imp__sub_8239E4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E4E8"))) PPC_WEAK_FUNC(sub_8239E4E8);
PPC_FUNC_IMPL(__imp__sub_8239E4E8) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239e574
	if (!cr6.eq) goto loc_8239E574;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8239e558
	if (cr6.eq) goto loc_8239E558;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8239e574
	if (!cr6.eq) goto loc_8239E574;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x82130528
	ctx.lr = 0x8239E528;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8239e574
	if (cr6.eq) goto loc_8239E574;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e3e8
	ctx.lr = 0x8239E544;
	sub_8239E3E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823a1868
	ctx.lr = 0x8239E554;
	sub_823A1868(ctx, base);
	// b 0x8239e578
	goto loc_8239E578;
loc_8239E558:
	// li r3,288
	ctx.r3.s64 = 288;
	// bl 0x82130528
	ctx.lr = 0x8239E560;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e574
	if (cr6.eq) goto loc_8239E574;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823a0f08
	ctx.lr = 0x8239E570;
	sub_823A0F08(ctx, base);
	// b 0x8239e578
	goto loc_8239E578;
loc_8239E574:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8239E578:
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

__attribute__((alias("__imp__sub_8239E590"))) PPC_WEAK_FUNC(sub_8239E590);
PPC_FUNC_IMPL(__imp__sub_8239E590) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8239e5d0
	if (!cr6.eq) goto loc_8239E5D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8239E5D0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8239e5e4
	if (!cr6.gt) goto loc_8239E5E4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8239e5e8
	if (cr6.lt) goto loc_8239E5E8;
loc_8239E5E4:
	// li r11,0
	r11.s64 = 0;
loc_8239E5E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e600
	if (cr6.eq) goto loc_8239E600;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r11,16148
	ctx.r6.s64 = r11.s64 + 16148;
	// b 0x8239e608
	goto loc_8239E608;
loc_8239E600:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r11,16136
	ctx.r6.s64 = r11.s64 + 16136;
loc_8239E608:
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e620
	if (cr6.eq) goto loc_8239E620;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r7,r11,16128
	ctx.r7.s64 = r11.s64 + 16128;
	// b 0x8239e628
	goto loc_8239E628;
loc_8239E620:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r7,r11,16124
	ctx.r7.s64 = r11.s64 + 16124;
loc_8239E628:
	// lbz r11,9(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e640
	if (cr6.eq) goto loc_8239E640;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r8,r11,16120
	ctx.r8.s64 = r11.s64 + 16120;
	// b 0x8239e648
	goto loc_8239E648;
loc_8239E640:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r8,r11,16116
	ctx.r8.s64 = r11.s64 + 16116;
loc_8239E648:
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e660
	if (cr6.eq) goto loc_8239E660;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r9,r11,-6708
	ctx.r9.s64 = r11.s64 + -6708;
	// b 0x8239e668
	goto loc_8239E668;
loc_8239E660:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r9,r11,16108
	ctx.r9.s64 = r11.s64 + 16108;
loc_8239E668:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16092
	ctx.r5.s64 = r11.s64 + 16092;
	// bl 0x82137a08
	ctx.lr = 0x8239E678;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_8239E690"))) PPC_WEAK_FUNC(sub_8239E690);
PPC_FUNC_IMPL(__imp__sub_8239E690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239E6A0"))) PPC_WEAK_FUNC(sub_8239E6A0);
PPC_FUNC_IMPL(__imp__sub_8239E6A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239E6B0"))) PPC_WEAK_FUNC(sub_8239E6B0);
PPC_FUNC_IMPL(__imp__sub_8239E6B0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e6f8
	if (cr6.eq) goto loc_8239E6F8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8239e590
	ctx.lr = 0x8239E6E4;
	sub_8239E590(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8239E6F8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8239e720
	if (!cr6.eq) goto loc_8239E720;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8239E720:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8239e734
	if (!cr6.gt) goto loc_8239E734;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8239e738
	if (cr6.lt) goto loc_8239E738;
loc_8239E734:
	// li r11,0
	r11.s64 = 0;
loc_8239E738:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e750
	if (cr6.eq) goto loc_8239E750;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r11,16148
	ctx.r6.s64 = r11.s64 + 16148;
	// b 0x8239e758
	goto loc_8239E758;
loc_8239E750:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r11,16136
	ctx.r6.s64 = r11.s64 + 16136;
loc_8239E758:
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e770
	if (cr6.eq) goto loc_8239E770;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r7,r11,16128
	ctx.r7.s64 = r11.s64 + 16128;
	// b 0x8239e778
	goto loc_8239E778;
loc_8239E770:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r7,r11,16124
	ctx.r7.s64 = r11.s64 + 16124;
loc_8239E778:
	// lbz r11,9(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e790
	if (cr6.eq) goto loc_8239E790;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r8,r11,16120
	ctx.r8.s64 = r11.s64 + 16120;
	// b 0x8239e798
	goto loc_8239E798;
loc_8239E790:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r8,r11,16116
	ctx.r8.s64 = r11.s64 + 16116;
loc_8239E798:
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e7b0
	if (cr6.eq) goto loc_8239E7B0;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r9,r11,-6708
	ctx.r9.s64 = r11.s64 + -6708;
	// b 0x8239e7b8
	goto loc_8239E7B8;
loc_8239E7B0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r9,r11,16108
	ctx.r9.s64 = r11.s64 + 16108;
loc_8239E7B8:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16160
	ctx.r5.s64 = r11.s64 + 16160;
	// bl 0x82137a08
	ctx.lr = 0x8239E7CC;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_8239E7E4"))) PPC_WEAK_FUNC(sub_8239E7E4);
PPC_FUNC_IMPL(__imp__sub_8239E7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E7E8"))) PPC_WEAK_FUNC(sub_8239E7E8);
PPC_FUNC_IMPL(__imp__sub_8239E7E8) {
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
	ctx.lr = 0x8239E800;
	sub_821D2970(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,16180
	ctx.r9.s64 = ctx.r10.s64 + 16180;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// sth r11,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r11.u16);
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

__attribute__((alias("__imp__sub_8239E840"))) PPC_WEAK_FUNC(sub_8239E840);
PPC_FUNC_IMPL(__imp__sub_8239E840) {
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
	ctx.lr = 0x8239E848;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r29
	r28.u64 = r29.u64;
	// lhz r11,24(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239e8a8
	if (cr6.eq) goto loc_8239E8A8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_8239E868:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e88c
	if (cr6.eq) goto loc_8239E88C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239E88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239E88C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stwx r29,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r29.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lhz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x8239e868
	if (cr6.lt) goto loc_8239E868;
loc_8239E8A8:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8239E8B0;
	sub_82130588(ctx, base);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// sth r29,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r29.u16);
	// sth r29,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r29.u16);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e8dc
	if (cr6.eq) goto loc_8239E8DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239E8DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239E8DC:
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e900
	if (cr6.eq) goto loc_8239E900;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239E900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239E900:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239e924
	if (cr6.eq) goto loc_8239E924;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239E924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239E924:
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8239E930"))) PPC_WEAK_FUNC(sub_8239E930);
PPC_FUNC_IMPL(__imp__sub_8239E930) {
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
	ctx.lr = 0x8239E938;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8239E948;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8239e9d0
	if (!cr6.gt) goto loc_8239E9D0;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_8239E960:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239e9c4
	if (cr6.eq) goto loc_8239E9C4;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8239e9c0
	if (cr6.eq) goto loc_8239E9C0;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239e9c0
	if (cr6.eq) goto loc_8239E9C0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8239E994;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8239e9c0
	if (cr6.eq) goto loc_8239E9C0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8239E9A8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8239eee8
	ctx.lr = 0x8239E9BC;
	sub_8239EEE8(ctx, base);
	// b 0x8239e9c4
	goto loc_8239E9C4;
loc_8239E9C0:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_8239E9C4:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8239e960
	if (!cr0.eq) goto loc_8239E960;
loc_8239E9D0:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8239E9DC"))) PPC_WEAK_FUNC(sub_8239E9DC);
PPC_FUNC_IMPL(__imp__sub_8239E9DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239E9E0"))) PPC_WEAK_FUNC(sub_8239E9E0);
PPC_FUNC_IMPL(__imp__sub_8239E9E0) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,16180
	ctx.r10.s64 = r11.s64 + 16180;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8239e840
	ctx.lr = 0x8239EA0C;
	sub_8239E840(ctx, base);
	// lhz r9,26(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8239ea20
	if (cr6.eq) goto loc_8239EA20;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8239EA20;
	sub_82130588(ctx, base);
loc_8239EA20:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x8239EA28;
	sub_821D2810(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239ea40
	if (cr6.eq) goto loc_8239EA40;
	// bl 0x82130588
	ctx.lr = 0x8239EA3C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239EA40:
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

__attribute__((alias("__imp__sub_8239EA58"))) PPC_WEAK_FUNC(sub_8239EA58);
PPC_FUNC_IMPL(__imp__sub_8239EA58) {
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
	ctx.lr = 0x8239EA60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8239ea88
	if (!cr6.gt) goto loc_8239EA88;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8239ea8c
	if (cr6.lt) goto loc_8239EA8C;
loc_8239EA88:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8239EA8C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239eaa4
	if (cr6.eq) goto loc_8239EAA4;
	// addi r3,r4,8
	ctx.r3.s64 = ctx.r4.s64 + 8;
	// bl 0x823a1578
	ctx.lr = 0x8239EAA0;
	sub_823A1578(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
loc_8239EAA4:
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8239eac0
	if (cr6.eq) goto loc_8239EAC0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239e930
	ctx.lr = 0x8239EABC;
	sub_8239E930(ctx, base);
	// b 0x8239eac4
	goto loc_8239EAC4;
loc_8239EAC0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8239EAC4:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// ble cr6,0x8239eafc
	if (!cr6.gt) goto loc_8239EAFC;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8239EAD8:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// stwx r29,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r29.u32);
	// bne 0x8239ead8
	if (!cr0.eq) goto loc_8239EAD8;
loc_8239EAFC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8239EB04"))) PPC_WEAK_FUNC(sub_8239EB04);
PPC_FUNC_IMPL(__imp__sub_8239EB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EB08"))) PPC_WEAK_FUNC(sub_8239EB08);
PPC_FUNC_IMPL(__imp__sub_8239EB08) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8239EB10;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// blt cr6,0x8239eba4
	if (cr6.lt) goto loc_8239EBA4;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8239eb50
	if (!cr6.gt) goto loc_8239EB50;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8239eb54
	if (cr6.lt) goto loc_8239EB54;
loc_8239EB50:
	// li r11,0
	r11.s64 = 0;
loc_8239EB54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239eb6c
	if (cr6.eq) goto loc_8239EB6C;
	// addi r3,r26,8
	ctx.r3.s64 = r26.s64 + 8;
	// bl 0x823a1578
	ctx.lr = 0x8239EB68;
	sub_823A1578(ctx, base);
	// stw r3,16(r27)
	PPC_STORE_U32(r27.u32 + 16, ctx.r3.u32);
loc_8239EB6C:
	// lhz r11,12(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239eb80
	if (cr6.eq) goto loc_8239EB80;
	// lwz r3,8(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// b 0x8239eb88
	goto loc_8239EB88;
loc_8239EB80:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_8239EB88:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,16192
	ctx.r4.s64 = r11.s64 + 16192;
	// bl 0x823dd800
	ctx.lr = 0x8239EB98;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8239eba4
	if (!cr6.eq) goto loc_8239EBA4;
	// li r24,1
	r24.s64 = 1;
loc_8239EBA4:
	// addi r30,r27,20
	r30.s64 = r27.s64 + 20;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239ebc0
	if (cr6.eq) goto loc_8239EBC0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239e930
	ctx.lr = 0x8239EBBC;
	sub_8239E930(ctx, base);
	// b 0x8239ebc4
	goto loc_8239EBC4;
loc_8239EBC0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8239EBC4:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r31,0
	r31.s64 = 0;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8239ec3c
	if (!cr6.gt) goto loc_8239EC3C;
	// addi r28,r27,12
	r28.s64 = r27.s64 + 12;
loc_8239EBDC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8239e4e8
	ctx.lr = 0x8239EBE4;
	sub_8239E4E8(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// lwz r9,16(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// rlwinm r6,r11,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// lwz r20,0(r21)
	r20.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,24(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8239EC18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r21,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r21.u32);
	// blt cr6,0x8239ebdc
	if (cr6.lt) goto loc_8239EBDC;
loc_8239EC3C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8239EC44"))) PPC_WEAK_FUNC(sub_8239EC44);
PPC_FUNC_IMPL(__imp__sub_8239EC44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EC48"))) PPC_WEAK_FUNC(sub_8239EC48);
PPC_FUNC_IMPL(__imp__sub_8239EC48) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EC50"))) PPC_WEAK_FUNC(sub_8239EC50);
PPC_FUNC_IMPL(__imp__sub_8239EC50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8239EC60:
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239ec60
	if (!cr6.eq) goto loc_8239EC60;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EC74"))) PPC_WEAK_FUNC(sub_8239EC74);
PPC_FUNC_IMPL(__imp__sub_8239EC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EC78"))) PPC_WEAK_FUNC(sub_8239EC78);
PPC_FUNC_IMPL(__imp__sub_8239EC78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239ec9c
	if (cr6.eq) goto loc_8239EC9C;
loc_8239EC84:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8239ec84
	if (!cr6.eq) goto loc_8239EC84;
loc_8239EC9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239ECA4"))) PPC_WEAK_FUNC(sub_8239ECA4);
PPC_FUNC_IMPL(__imp__sub_8239ECA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239ECA8"))) PPC_WEAK_FUNC(sub_8239ECA8);
PPC_FUNC_IMPL(__imp__sub_8239ECA8) {
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
	// li r4,129
	ctx.r4.s64 = 129;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8246a088
	ctx.lr = 0x8239ECC8;
	sub_8246A088(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8239ed04
	if (!cr6.eq) goto loc_8239ED04;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8239ECDC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239ed00
	if (cr6.eq) goto loc_8239ED00;
	// li r4,129
	ctx.r4.s64 = 129;
	// bl 0x8246acc8
	ctx.lr = 0x8239ECF0;
	sub_8246ACC8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,16484
	ctx.r10.s64 = r11.s64 + 16484;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x8239ed04
	goto loc_8239ED04;
loc_8239ED00:
	// li r31,0
	r31.s64 = 0;
loc_8239ED04:
	// li r5,129
	ctx.r5.s64 = 129;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82469e08
	ctx.lr = 0x8239ED14;
	sub_82469E08(ctx, base);
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

__attribute__((alias("__imp__sub_8239ED30"))) PPC_WEAK_FUNC(sub_8239ED30);
PPC_FUNC_IMPL(__imp__sub_8239ED30) {
	PPC_FUNC_PROLOGUE();
	// b 0x8239eca8
	sub_8239ECA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239ED34"))) PPC_WEAK_FUNC(sub_8239ED34);
PPC_FUNC_IMPL(__imp__sub_8239ED34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239ED38"))) PPC_WEAK_FUNC(sub_8239ED38);
PPC_FUNC_IMPL(__imp__sub_8239ED38) {
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
	// beq cr6,0x8239ed68
	if (cr6.eq) goto loc_8239ED68;
	// li r4,129
	ctx.r4.s64 = 129;
	// bl 0x8246acc8
	ctx.lr = 0x8239ED5C;
	sub_8246ACC8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,16484
	ctx.r10.s64 = r11.s64 + 16484;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8239ED68:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239ED7C"))) PPC_WEAK_FUNC(sub_8239ED7C);
PPC_FUNC_IMPL(__imp__sub_8239ED7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239ED80"))) PPC_WEAK_FUNC(sub_8239ED80);
PPC_FUNC_IMPL(__imp__sub_8239ED80) {
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
	// beq cr6,0x8239edac
	if (cr6.eq) goto loc_8239EDAC;
	// bl 0x8246ad08
	ctx.lr = 0x8239EDA0;
	sub_8246AD08(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,16484
	ctx.r10.s64 = r11.s64 + 16484;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8239EDAC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239EDC0"))) PPC_WEAK_FUNC(sub_8239EDC0);
PPC_FUNC_IMPL(__imp__sub_8239EDC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-12016
	ctx.r3.s64 = r11.s64 + -12016;
	// b 0x8246ab20
	sub_8246AB20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239EDCC"))) PPC_WEAK_FUNC(sub_8239EDCC);
PPC_FUNC_IMPL(__imp__sub_8239EDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EDD0"))) PPC_WEAK_FUNC(sub_8239EDD0);
PPC_FUNC_IMPL(__imp__sub_8239EDD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-12016
	ctx.r3.s64 = r11.s64 + -12016;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EDDC"))) PPC_WEAK_FUNC(sub_8239EDDC);
PPC_FUNC_IMPL(__imp__sub_8239EDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EDE0"))) PPC_WEAK_FUNC(sub_8239EDE0);
PPC_FUNC_IMPL(__imp__sub_8239EDE0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8246a128
	ctx.lr = 0x8239EDF8;
	sub_8246A128(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239EE10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82509b28
	ctx.lr = 0x8239EE24;
	sub_82509B28(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8239ee50
	if (cr6.eq) goto loc_8239EE50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x82509ab8
	ctx.lr = 0x8239EE50;
	sub_82509AB8(ctx, base);
loc_8239EE50:
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

__attribute__((alias("__imp__sub_8239EE64"))) PPC_WEAK_FUNC(sub_8239EE64);
PPC_FUNC_IMPL(__imp__sub_8239EE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EE68"))) PPC_WEAK_FUNC(sub_8239EE68);
PPC_FUNC_IMPL(__imp__sub_8239EE68) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,16484
	ctx.r10.s64 = r11.s64 + 16484;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8246ad90
	ctx.lr = 0x8239EE94;
	sub_8246AD90(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8239eeac
	if (cr6.eq) goto loc_8239EEAC;
	// bl 0x82130588
	ctx.lr = 0x8239EEA8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239EEAC:
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

__attribute__((alias("__imp__sub_8239EEC4"))) PPC_WEAK_FUNC(sub_8239EEC4);
PPC_FUNC_IMPL(__imp__sub_8239EEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EEC8"))) PPC_WEAK_FUNC(sub_8239EEC8);
PPC_FUNC_IMPL(__imp__sub_8239EEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,-1
	r11.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r11.u32);
	// stb r10,129(r3)
	PPC_STORE_U8(ctx.r3.u32 + 129, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EEDC"))) PPC_WEAK_FUNC(sub_8239EEDC);
PPC_FUNC_IMPL(__imp__sub_8239EEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EEE0"))) PPC_WEAK_FUNC(sub_8239EEE0);
PPC_FUNC_IMPL(__imp__sub_8239EEE0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82612ba8
	sub_82612BA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239EEE8"))) PPC_WEAK_FUNC(sub_8239EEE8);
PPC_FUNC_IMPL(__imp__sub_8239EEE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8239e3b8
	sub_8239E3B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239EEEC"))) PPC_WEAK_FUNC(sub_8239EEEC);
PPC_FUNC_IMPL(__imp__sub_8239EEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EEF0"))) PPC_WEAK_FUNC(sub_8239EEF0);
PPC_FUNC_IMPL(__imp__sub_8239EEF0) {
	PPC_FUNC_PROLOGUE();
	PPCVRegister v63{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EEFC"))) PPC_WEAK_FUNC(sub_8239EEFC);
PPC_FUNC_IMPL(__imp__sub_8239EEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EF00"))) PPC_WEAK_FUNC(sub_8239EF00);
PPC_FUNC_IMPL(__imp__sub_8239EF00) {
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
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x8239EF20;
	sub_82339390(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lwz r5,29632(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29632);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8239ef4c
	if (cr6.eq) goto loc_8239EF4C;
	// lwz r11,29908(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29908);
	// lwz r10,-9052(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r6,288(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 288);
	// bl 0x82189ce0
	ctx.lr = 0x8239EF4C;
	sub_82189CE0(ctx, base);
loc_8239EF4C:
	// lwz r3,29908(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 29908);
	// bl 0x82190870
	ctx.lr = 0x8239EF54;
	sub_82190870(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,-32228(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32228);
	// bl 0x82187be0
	ctx.lr = 0x8239EF60;
	sub_82187BE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8239EF6C;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8239EF78;
	sub_8217F768(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x8239EF84;
	sub_8217F768(ctx, base);
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

__attribute__((alias("__imp__sub_8239EF9C"))) PPC_WEAK_FUNC(sub_8239EF9C);
PPC_FUNC_IMPL(__imp__sub_8239EF9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EFA0"))) PPC_WEAK_FUNC(sub_8239EFA0);
PPC_FUNC_IMPL(__imp__sub_8239EFA0) {
	PPC_FUNC_PROLOGUE();
	// stb r4,144(r3)
	PPC_STORE_U8(ctx.r3.u32 + 144, ctx.r4.u8);
	// stb r5,146(r3)
	PPC_STORE_U8(ctx.r3.u32 + 146, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EFAC"))) PPC_WEAK_FUNC(sub_8239EFAC);
PPC_FUNC_IMPL(__imp__sub_8239EFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EFB0"))) PPC_WEAK_FUNC(sub_8239EFB0);
PPC_FUNC_IMPL(__imp__sub_8239EFB0) {
	PPC_FUNC_PROLOGUE();
	// stb r4,148(r3)
	PPC_STORE_U8(ctx.r3.u32 + 148, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EFB8"))) PPC_WEAK_FUNC(sub_8239EFB8);
PPC_FUNC_IMPL(__imp__sub_8239EFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r10,r1,28
	ctx.r10.s64 = ctx.r1.s64 + 28;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239EFDC"))) PPC_WEAK_FUNC(sub_8239EFDC);
PPC_FUNC_IMPL(__imp__sub_8239EFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239EFE0"))) PPC_WEAK_FUNC(sub_8239EFE0);
PPC_FUNC_IMPL(__imp__sub_8239EFE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8239f024
	if (cr6.lt) goto loc_8239F024;
	// beq cr6,0x8239f00c
	if (cr6.eq) goto loc_8239F00C;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,24(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
loc_8239F00C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// blr 
	return;
loc_8239F024:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,16(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F03C"))) PPC_WEAK_FUNC(sub_8239F03C);
PPC_FUNC_IMPL(__imp__sub_8239F03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F040"))) PPC_WEAK_FUNC(sub_8239F040);
PPC_FUNC_IMPL(__imp__sub_8239F040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r11,2272
	ctx.r8.s64 = r11.s64 + 2272;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r7,r7,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F068"))) PPC_WEAK_FUNC(sub_8239F068);
PPC_FUNC_IMPL(__imp__sub_8239F068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r11,2304
	ctx.r8.s64 = r11.s64 + 2304;
	// ori r7,r10,16
	ctx.r7.u64 = ctx.r10.u64 | 16;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F08C"))) PPC_WEAK_FUNC(sub_8239F08C);
PPC_FUNC_IMPL(__imp__sub_8239F08C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F090"))) PPC_WEAK_FUNC(sub_8239F090);
PPC_FUNC_IMPL(__imp__sub_8239F090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F0B0"))) PPC_WEAK_FUNC(sub_8239F0B0);
PPC_FUNC_IMPL(__imp__sub_8239F0B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bne cr6,0x8239f130
	if (!cr6.eq) goto loc_8239F130;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F0F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r30,4
	ctx.r5.s64 = r30.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8239F114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r30,8
	ctx.r5.s64 = r30.s64 + 8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x8239f138
	goto loc_8239F138;
loc_8239F130:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8239F138:
	// bctrl 
	ctx.lr = 0x8239F13C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8239F158"))) PPC_WEAK_FUNC(sub_8239F158);
PPC_FUNC_IMPL(__imp__sub_8239F158) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 / ctx.f12.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8239f1a0
	if (cr6.lt) goto loc_8239F1A0;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8239F1A0:
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwzx r3,r7,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// bl 0x8239f0b0
	ctx.lr = 0x8239F1CC;
	sub_8239F0B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F1DC"))) PPC_WEAK_FUNC(sub_8239F1DC);
PPC_FUNC_IMPL(__imp__sub_8239F1DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F1E0"))) PPC_WEAK_FUNC(sub_8239F1E0);
PPC_FUNC_IMPL(__imp__sub_8239F1E0) {
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// bl 0x8239f158
	ctx.lr = 0x8239F200;
	sub_8239F158(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239F224"))) PPC_WEAK_FUNC(sub_8239F224);
PPC_FUNC_IMPL(__imp__sub_8239F224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F228"))) PPC_WEAK_FUNC(sub_8239F228);
PPC_FUNC_IMPL(__imp__sub_8239F228) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfs f31,172(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x8239f2d0
	if (!cr6.gt) goto loc_8239F2D0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8239f158
	ctx.lr = 0x8239F264;
	sub_8239F158(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32664);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x8239f2b0
	if (!cr6.lt) goto loc_8239F2B0;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239f2b0
	if (!cr6.eq) goto loc_8239F2B0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r9,r1,172
	ctx.r9.s64 = ctx.r1.s64 + 172;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8239f2c0
	goto loc_8239F2C0;
loc_8239F2B0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8239F2C0:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
loc_8239F2D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8239F2E8"))) PPC_WEAK_FUNC(sub_8239F2E8);
PPC_FUNC_IMPL(__imp__sub_8239F2E8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8239F2F0;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f30,244(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x8239f4a0
	if (!cr6.gt) goto loc_8239F4A0;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// bne cr6,0x8239f414
	if (!cr6.eq) goto loc_8239F414;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// dcbt r0,r11
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// dcbt r0,r10
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// dcbt r0,r9
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8239F364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8239F384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8239F3A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8239F3C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,52(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8239F3E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8239F40C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8239f434
	goto loc_8239F434;
loc_8239F414:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239F434:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32664);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bge cr6,0x8239f480
	if (!cr6.lt) goto loc_8239F480;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8239f480
	if (!cr6.eq) goto loc_8239F480;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r29,16
	r11.s64 = r29.s64 + 16;
	// addi r9,r1,244
	ctx.r9.s64 = ctx.r1.s64 + 244;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8239f490
	goto loc_8239F490;
loc_8239F480:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8239F490:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r29)
	PPC_STORE_U8(r29.u32 + 4, ctx.r10.u8);
loc_8239F4A0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8239F4B0"))) PPC_WEAK_FUNC(sub_8239F4B0);
PPC_FUNC_IMPL(__imp__sub_8239F4B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// fmadds f9,f11,f11,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f8,f10,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fcmpu cr6,f8,f13
	cr6.compare(ctx.f8.f64, ctx.f13.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8239f504
	if (cr6.eq) goto loc_8239F504;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// blr 
	return;
loc_8239F504:
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F518"))) PPC_WEAK_FUNC(sub_8239F518);
PPC_FUNC_IMPL(__imp__sub_8239F518) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,18692
	ctx.r9.s64 = r11.s64 + 18692;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8239f54c
	if (cr6.eq) goto loc_8239F54C;
	// bl 0x82130588
	ctx.lr = 0x8239F548;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239F54C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239F560"))) PPC_WEAK_FUNC(sub_8239F560);
PPC_FUNC_IMPL(__imp__sub_8239F560) {
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
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239f598
	if (cr6.eq) goto loc_8239F598;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239F598:
	// li r30,0
	r30.s64 = 0;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239f5c0
	if (cr6.eq) goto loc_8239F5C0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239F5C0:
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239f5e4
	if (cr6.eq) goto loc_8239F5E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F5E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
loc_8239F5E4:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239f604
	if (cr6.eq) goto loc_8239F604;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F600;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_8239F604:
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

__attribute__((alias("__imp__sub_8239F61C"))) PPC_WEAK_FUNC(sub_8239F61C);
PPC_FUNC_IMPL(__imp__sub_8239F61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F620"))) PPC_WEAK_FUNC(sub_8239F620);
PPC_FUNC_IMPL(__imp__sub_8239F620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r3,180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F63C"))) PPC_WEAK_FUNC(sub_8239F63C);
PPC_FUNC_IMPL(__imp__sub_8239F63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F640"))) PPC_WEAK_FUNC(sub_8239F640);
PPC_FUNC_IMPL(__imp__sub_8239F640) {
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
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x82130588
	ctx.lr = 0x8239F664;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// bl 0x826112e8
	ctx.lr = 0x8239F674;
	sub_826112E8(ctx, base);
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8239f68c
	if (cr6.eq) goto loc_8239F68C;
	// bl 0x82130588
	ctx.lr = 0x8239F688;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8239F68C:
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

__attribute__((alias("__imp__sub_8239F6A4"))) PPC_WEAK_FUNC(sub_8239F6A4);
PPC_FUNC_IMPL(__imp__sub_8239F6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F6A8"))) PPC_WEAK_FUNC(sub_8239F6A8);
PPC_FUNC_IMPL(__imp__sub_8239F6A8) {
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
	// bl 0x82612180
	ctx.lr = 0x8239F6C8;
	sub_82612180(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,18708
	ctx.r10.s64 = r11.s64 + 18708;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8239f6f4
	if (cr6.eq) goto loc_8239F6F4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8239F6E8;
	sub_8217D890(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
loc_8239F6F4:
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

__attribute__((alias("__imp__sub_8239F710"))) PPC_WEAK_FUNC(sub_8239F710);
PPC_FUNC_IMPL(__imp__sub_8239F710) {
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
	ctx.lr = 0x8239F718;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8239f740
	if (cr6.eq) goto loc_8239F740;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x823c9368
	ctx.lr = 0x8239F740;
	sub_823C9368(ctx, base);
loc_8239F740:
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8239f760
	if (cr6.eq) goto loc_8239F760;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239F760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8239F760:
	// li r30,0
	r30.s64 = 0;
	// stw r30,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r30.u32);
	// lwz r28,180(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8239f784
	if (cr6.eq) goto loc_8239F784;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82507cb8
	ctx.lr = 0x8239F77C;
	sub_82507CB8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8239F784;
	sub_82130588(ctx, base);
loc_8239F784:
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x823caa50
	ctx.lr = 0x8239F794;
	sub_823CAA50(ctx, base);
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// lwz r4,196(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r3,-4960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4960);
	// bl 0x823caa50
	ctx.lr = 0x8239F7A4;
	sub_823CAA50(ctx, base);
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// addi r29,r31,156
	r29.s64 = r31.s64 + 156;
	// li r28,3
	r28.s64 = 3;
loc_8239F7B0:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8239F7B8;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8239f7b0
	if (!cr0.eq) goto loc_8239F7B0;
	// lwz r29,152(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239f7e4
	if (cr6.eq) goto loc_8239F7E4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821b6018
	ctx.lr = 0x8239F7DC;
	sub_821B6018(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8239F7E4;
	sub_82130588(ctx, base);
loc_8239F7E4:
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8239F7F0"))) PPC_WEAK_FUNC(sub_8239F7F0);
PPC_FUNC_IMPL(__imp__sub_8239F7F0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823a4198
	ctx.lr = 0x8239F810;
	sub_823A4198(ctx, base);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239f854
	if (cr6.eq) goto loc_8239F854;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x8239F824;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239f854
	if (cr6.eq) goto loc_8239F854;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239f854
	if (cr6.eq) goto loc_8239F854;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239f854
	if (cr6.eq) goto loc_8239F854;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lwz r3,184(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// bl 0x823a51a0
	ctx.lr = 0x8239F854;
	sub_823A51A0(ctx, base);
loc_8239F854:
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

__attribute__((alias("__imp__sub_8239F86C"))) PPC_WEAK_FUNC(sub_8239F86C);
PPC_FUNC_IMPL(__imp__sub_8239F86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239F870"))) PPC_WEAK_FUNC(sub_8239F870);
PPC_FUNC_IMPL(__imp__sub_8239F870) {
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
	// bl 0x823a3eb0
	ctx.lr = 0x8239F888;
	sub_823A3EB0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// beq cr6,0x8239f8a4
	if (cr6.eq) goto loc_8239F8A4;
	// bl 0x823a6aa0
	ctx.lr = 0x8239F8A4;
	sub_823A6AA0(ctx, base);
loc_8239F8A4:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239f8b4
	if (cr6.eq) goto loc_8239F8B4;
	// bl 0x821b4d20
	ctx.lr = 0x8239F8B4;
	sub_821B4D20(ctx, base);
loc_8239F8B4:
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239f8c4
	if (cr6.eq) goto loc_8239F8C4;
	// bl 0x825079e8
	ctx.lr = 0x8239F8C4;
	sub_825079E8(ctx, base);
loc_8239F8C4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239F8D8"))) PPC_WEAK_FUNC(sub_8239F8D8);
PPC_FUNC_IMPL(__imp__sub_8239F8D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,184(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8239f8f4
	if (cr6.eq) goto loc_8239F8F4;
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8239f8f8
	if (!cr6.eq) goto loc_8239F8F8;
loc_8239F8F4:
	// li r11,0
	r11.s64 = 0;
loc_8239F8F8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8239F900"))) PPC_WEAK_FUNC(sub_8239F900);
PPC_FUNC_IMPL(__imp__sub_8239F900) {
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
	// lwz r11,184(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8239f968
	if (cr6.eq) goto loc_8239F968;
	// lwz r31,96(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8239f968
	if (cr6.eq) goto loc_8239F968;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x8239F938;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239f968
	if (cr6.eq) goto loc_8239F968;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239f968
	if (cr6.eq) goto loc_8239F968;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239f968
	if (cr6.eq) goto loc_8239F968;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lwz r3,184(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// bl 0x823a51a0
	ctx.lr = 0x8239F968;
	sub_823A51A0(ctx, base);
loc_8239F968:
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

__attribute__((alias("__imp__sub_8239F980"))) PPC_WEAK_FUNC(sub_8239F980);
PPC_FUNC_IMPL(__imp__sub_8239F980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,176(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,39
	r11.s64 = r11.s64 + 39;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// b 0x821a1768
	sub_821A1768(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239F998"))) PPC_WEAK_FUNC(sub_8239F998);
PPC_FUNC_IMPL(__imp__sub_8239F998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,172(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,39
	r11.s64 = r11.s64 + 39;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// b 0x821a1768
	sub_821A1768(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8239F9B0"))) PPC_WEAK_FUNC(sub_8239F9B0);
PPC_FUNC_IMPL(__imp__sub_8239F9B0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// stfs f13,208(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// beq cr6,0x8239f9ec
	if (cr6.eq) goto loc_8239F9EC;
	// bl 0x823a6aa0
	ctx.lr = 0x8239F9EC;
	sub_823A6AA0(ctx, base);
loc_8239F9EC:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239f9fc
	if (cr6.eq) goto loc_8239F9FC;
	// bl 0x821b4d20
	ctx.lr = 0x8239F9FC;
	sub_821B4D20(ctx, base);
loc_8239F9FC:
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8239fa0c
	if (cr6.eq) goto loc_8239FA0C;
	// bl 0x825079e8
	ctx.lr = 0x8239FA0C;
	sub_825079E8(ctx, base);
loc_8239FA0C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8239FA28"))) PPC_WEAK_FUNC(sub_8239FA28);
PPC_FUNC_IMPL(__imp__sub_8239FA28) {
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
	// lfs f13,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lfs f12,204(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f12,f13
	f0.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f13,200(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8239fa8c
	if (cr6.eq) goto loc_8239FA8C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11848
	ctx.r10.s64 = r11.s64 + -11848;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8239fa8c
	if (!cr6.eq) goto loc_8239FA8C;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,184(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// bl 0x823a6498
	ctx.lr = 0x8239FA7C;
	sub_823A6498(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-11992(r10)
	PPC_STORE_U8(ctx.r10.u32 + -11992, r11.u8);
	// b 0x8239fac8
	goto loc_8239FAC8;
loc_8239FA8C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r31,188(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,152(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x825284d0
	ctx.lr = 0x8239FAB0;
	sub_825284D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x825286e8
	ctx.lr = 0x8239FAC0;
	sub_825286E8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b4de0
	ctx.lr = 0x8239FAC8;
	sub_821B4DE0(ctx, base);
loc_8239FAC8:
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

__attribute__((alias("__imp__sub_8239FAE0"))) PPC_WEAK_FUNC(sub_8239FAE0);
PPC_FUNC_IMPL(__imp__sub_8239FAE0) {
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
	ctx.lr = 0x8239FAE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r30,22080(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// beq cr6,0x8239fb24
	if (cr6.eq) goto loc_8239FB24;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239FB18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// bl 0x82507aa0
	ctx.lr = 0x8239FB20;
	sub_82507AA0(ctx, base);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
loc_8239FB24:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// bl 0x82507a38
	ctx.lr = 0x8239FB30;
	sub_82507A38(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8239FB38"))) PPC_WEAK_FUNC(sub_8239FB38);
PPC_FUNC_IMPL(__imp__sub_8239FB38) {
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
	ctx.lr = 0x8239FB40;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x823a4100
	ctx.lr = 0x8239FB64;
	sub_823A4100(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r28,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r28.u32);
	// addi r10,r11,-11868
	ctx.r10.s64 = r11.s64 + -11868;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239fb88
	if (cr6.eq) goto loc_8239FB88;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// bl 0x823a5da0
	ctx.lr = 0x8239FB84;
	sub_823A5DA0(ctx, base);
	// b 0x8239fbcc
	goto loc_8239FBCC;
loc_8239FB88:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8239fbcc
	if (cr6.eq) goto loc_8239FBCC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lbz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 128);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f31,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a5c10
	ctx.lr = 0x8239FBB0;
	sub_823A5C10(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8239fbcc
	if (cr6.eq) goto loc_8239FBCC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lbz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 128);
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a7ca8
	ctx.lr = 0x8239FBCC;
	sub_823A7CA8(ctx, base);
loc_8239FBCC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-11828
	ctx.r10.s64 = r11.s64 + -11828;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239fbf0
	if (cr6.eq) goto loc_8239FBF0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lfs f1,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a7e30
	ctx.lr = 0x8239FBF0;
	sub_823A7E30(ctx, base);
loc_8239FBF0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8239FBFC"))) PPC_WEAK_FUNC(sub_8239FBFC);
PPC_FUNC_IMPL(__imp__sub_8239FBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8239FC00"))) PPC_WEAK_FUNC(sub_8239FC00);
PPC_FUNC_IMPL(__imp__sub_8239FC00) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x823a4128
	ctx.lr = 0x8239FC20;
	sub_823A4128(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// stw r30,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r30.u32);
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

__attribute__((alias("__imp__sub_8239FC48"))) PPC_WEAK_FUNC(sub_8239FC48);
PPC_FUNC_IMPL(__imp__sub_8239FC48) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a4100
	ctx.lr = 0x8239FC7C;
	sub_823A4100(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8239fc9c
	if (cr6.eq) goto loc_8239FC9C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f1,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a7b00
	ctx.lr = 0x8239FC9C;
	sub_823A7B00(ctx, base);
loc_8239FC9C:
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

