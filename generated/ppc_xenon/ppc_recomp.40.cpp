#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822A3DE0"))) PPC_WEAK_FUNC(sub_822A3DE0);
PPC_FUNC_IMPL(__imp__sub_822A3DE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// addi r7,r3,136
	ctx.r7.s64 = ctx.r3.s64 + 136;
	// lbzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x822a3dfc
	if (!cr6.eq) goto loc_822A3DFC;
	// addi r7,r3,8
	ctx.r7.s64 = ctx.r3.s64 + 8;
loc_822A3DFC:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
loc_822A3E08:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822a3e2c
	if (cr6.eq) goto loc_822A3E2C;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x822a3e50
	if (cr6.lt) goto loc_822A3E50;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x822a3e50
	if (!cr6.lt) goto loc_822A3E50;
	// lwz r11,128(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// b 0x822a3e44
	goto loc_822A3E44;
loc_822A3E2C:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x822a3e50
	if (cr6.lt) goto loc_822A3E50;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x822a3e50
	if (!cr6.lt) goto loc_822A3E50;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
loc_822A3E44:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822a3e54
	if (!cr6.eq) goto loc_822A3E54;
loc_822A3E50:
	// li r11,0
	r11.s64 = 0;
loc_822A3E54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a3e70
	if (cr6.eq) goto loc_822A3E70;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r5,1220(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 1220);
	// cmplw cr6,r5,r4
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, xer);
	// beq cr6,0x822a3e8c
	if (cr6.eq) goto loc_822A3E8C;
loc_822A3E70:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpwi cr6,r10,31
	cr6.compare<int32_t>(ctx.r10.s32, 31, xer);
	// blt cr6,0x822a3e08
	if (cr6.lt) goto loc_822A3E08;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822A3E8C:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r7
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A3E98"))) PPC_WEAK_FUNC(sub_822A3E98);
PPC_FUNC_IMPL(__imp__sub_822A3E98) {
	PPC_FUNC_PROLOGUE();
	// stb r4,564(r3)
	PPC_STORE_U8(ctx.r3.u32 + 564, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A3EA0"))) PPC_WEAK_FUNC(sub_822A3EA0);
PPC_FUNC_IMPL(__imp__sub_822A3EA0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,524
	ctx.r3.s64 = ctx.r3.s64 + 524;
	// b 0x821c3048
	sub_821C3048(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A3EA8"))) PPC_WEAK_FUNC(sub_822A3EA8);
PPC_FUNC_IMPL(__imp__sub_822A3EA8) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822A3ED4;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a3f24
	if (cr6.eq) goto loc_822A3F24;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// addi r11,r31,34
	r11.s64 = r31.s64 + 34;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a3efc
	if (!cr6.eq) goto loc_822A3EFC;
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
loc_822A3EFC:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A3F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a3f28
	if (!cr6.eq) goto loc_822A3F28;
loc_822A3F24:
	// li r11,0
	r11.s64 = 0;
loc_822A3F28:
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

__attribute__((alias("__imp__sub_822A3F44"))) PPC_WEAK_FUNC(sub_822A3F44);
PPC_FUNC_IMPL(__imp__sub_822A3F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A3F48"))) PPC_WEAK_FUNC(sub_822A3F48);
PPC_FUNC_IMPL(__imp__sub_822A3F48) {
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
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a3fb0
	if (cr6.eq) goto loc_822A3FB0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822A3F80;
	sub_82388580(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822a3f94
	if (!cr6.eq) goto loc_822A3F94;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x822a3fb0
	goto loc_822A3FB0;
loc_822A3F94:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822A3F9C;
	sub_82388580(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,28,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_822A3FB0:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_822A3FBC:
	// lbzx r8,r11,r30
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a3fcc
	if (cr6.eq) goto loc_822A3FCC;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_822A3FCC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// blt cr6,0x822a3fbc
	if (cr6.lt) goto loc_822A3FBC;
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

__attribute__((alias("__imp__sub_822A3FF4"))) PPC_WEAK_FUNC(sub_822A3FF4);
PPC_FUNC_IMPL(__imp__sub_822A3FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A3FF8"))) PPC_WEAK_FUNC(sub_822A3FF8);
PPC_FUNC_IMPL(__imp__sub_822A3FF8) {
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
	ctx.lr = 0x822A4000;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a40ec
	if (!cr6.eq) goto loc_822A40EC;
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822a40ec
	if (!cr6.gt) goto loc_822A40EC;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,72
	r27.s64 = 72;
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
loc_822A4030:
	// lbzx r10,r27,r28
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a4058
	if (cr6.eq) goto loc_822A4058;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822a4078
	if (cr6.lt) goto loc_822A4078;
	// lwz r11,260(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822a4078
	if (!cr6.lt) goto loc_822A4078;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// b 0x822a406c
	goto loc_822A406C;
loc_822A4058:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822a4078
	if (cr6.lt) goto loc_822A4078;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822a4078
	if (!cr6.lt) goto loc_822A4078;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822A406C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822a407c
	if (!cr6.eq) goto loc_822A407C;
loc_822A4078:
	// li r11,0
	r11.s64 = 0;
loc_822A407C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a40a0
	if (cr6.eq) goto loc_822A40A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388580
	ctx.lr = 0x822A4090;
	sub_82388580(ctx, base);
	// lbz r11,22(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822a40a4
	if (cr6.eq) goto loc_822A40A4;
loc_822A40A0:
	// li r11,0
	r11.s64 = 0;
loc_822A40A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a40d8
	if (cr6.eq) goto loc_822A40D8;
	// lbzx r11,r27,r28
	r11.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a40c4
	if (cr6.eq) goto loc_822A40C4;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// b 0x822a40c8
	goto loc_822A40C8;
loc_822A40C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822A40C8:
	// lwz r3,880(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a40d8
	if (cr6.eq) goto loc_822A40D8;
	// bl 0x822b33f0
	ctx.lr = 0x822A40D8;
	sub_822B33F0(ctx, base);
loc_822A40D8:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822a4030
	if (cr6.lt) goto loc_822A4030;
loc_822A40EC:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a3d80
	ctx.lr = 0x822A40FC;
	sub_822A3D80(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822A4104"))) PPC_WEAK_FUNC(sub_822A4104);
PPC_FUNC_IMPL(__imp__sub_822A4104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4108"))) PPC_WEAK_FUNC(sub_822A4108);
PPC_FUNC_IMPL(__imp__sub_822A4108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,-10016(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10016);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a4158
	if (cr6.eq) goto loc_822A4158;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addi r11,r4,34
	r11.s64 = ctx.r4.s64 + 34;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822a4140
	if (!cr6.eq) goto loc_822A4140;
	// addi r11,r4,2
	r11.s64 = ctx.r4.s64 + 2;
loc_822A4140:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,68(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// lwzx r11,r9,r3
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_822A4158:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r3,544
	ctx.r3.s64 = ctx.r3.s64 + 544;
	// b 0x821c3048
	sub_821C3048(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A416C"))) PPC_WEAK_FUNC(sub_822A416C);
PPC_FUNC_IMPL(__imp__sub_822A416C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4170"))) PPC_WEAK_FUNC(sub_822A4170);
PPC_FUNC_IMPL(__imp__sub_822A4170) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x822a419c
	if (cr6.eq) goto loc_822A419C;
	// lwz r9,260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822A419C:
	// lwz r9,132(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A41A8"))) PPC_WEAK_FUNC(sub_822A41A8);
PPC_FUNC_IMPL(__imp__sub_822A41A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,31
	r11.s64 = 31;
	// lwz r10,17268(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// addi r10,r10,400
	ctx.r10.s64 = ctx.r10.s64 + 400;
loc_822A41BC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a41cc
	if (cr6.eq) goto loc_822A41CC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_822A41CC:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x822a41bc
	if (!cr0.eq) goto loc_822A41BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A41E4"))) PPC_WEAK_FUNC(sub_822A41E4);
PPC_FUNC_IMPL(__imp__sub_822A41E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A41E8"))) PPC_WEAK_FUNC(sub_822A41E8);
PPC_FUNC_IMPL(__imp__sub_822A41E8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x821e80f8
	ctx.lr = 0x822A4210;
	sub_821E80F8(ctx, base);
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

__attribute__((alias("__imp__sub_822A4230"))) PPC_WEAK_FUNC(sub_822A4230);
PPC_FUNC_IMPL(__imp__sub_822A4230) {
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
	// bl 0x822a3ea8
	ctx.lr = 0x822A4250;
	sub_822A3EA8(ctx, base);
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

__attribute__((alias("__imp__sub_822A4270"))) PPC_WEAK_FUNC(sub_822A4270);
PPC_FUNC_IMPL(__imp__sub_822A4270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822a42c0
	if (!cr6.eq) goto loc_822A42C0;
	// lwz r10,864(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 864);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,864(r4)
	PPC_STORE_U32(ctx.r4.u32 + 864, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a42ac
	if (cr6.eq) goto loc_822A42AC;
	// stw r11,868(r10)
	PPC_STORE_U32(ctx.r10.u32 + 868, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_822A42AC:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_822A42C0:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822a42fc
	if (!cr6.eq) goto loc_822A42FC;
	// lwz r10,868(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 868);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,868(r4)
	PPC_STORE_U32(ctx.r4.u32 + 868, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a4320
	if (cr6.eq) goto loc_822A4320;
	// stw r11,864(r10)
	PPC_STORE_U32(ctx.r10.u32 + 864, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_822A42FC:
	// lwz r10,868(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 868);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,864(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 864);
	// stw r9,864(r10)
	PPC_STORE_U32(ctx.r10.u32 + 864, ctx.r9.u32);
	// lwz r8,864(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 864);
	// lwz r7,868(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 868);
	// stw r7,868(r8)
	PPC_STORE_U32(ctx.r8.u32 + 868, ctx.r7.u32);
	// stw r11,864(r4)
	PPC_STORE_U32(ctx.r4.u32 + 864, r11.u32);
	// stw r11,868(r4)
	PPC_STORE_U32(ctx.r4.u32 + 868, r11.u32);
loc_822A4320:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4330"))) PPC_WEAK_FUNC(sub_822A4330);
PPC_FUNC_IMPL(__imp__sub_822A4330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x822a4374
	if (!cr6.eq) goto loc_822A4374;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a4368
	if (cr6.eq) goto loc_822A4368;
	// stw r6,864(r11)
	PPC_STORE_U32(r11.u32 + 864, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,868(r6)
	PPC_STORE_U32(ctx.r6.u32 + 868, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x822a43ac
	if (!cr6.eq) goto loc_822A43AC;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x822a43ac
	goto loc_822A43AC;
loc_822A4368:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x822a43ac
	goto loc_822A43AC;
loc_822A4374:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x822a4394
	if (!cr6.eq) goto loc_822A4394;
	// stw r11,864(r6)
	PPC_STORE_U32(ctx.r6.u32 + 864, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,868(r11)
	PPC_STORE_U32(r11.u32 + 868, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x822a43ac
	goto loc_822A43AC;
loc_822A4394:
	// stw r5,864(r6)
	PPC_STORE_U32(ctx.r6.u32 + 864, ctx.r5.u32);
	// lwz r11,868(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 868);
	// stw r11,868(r6)
	PPC_STORE_U32(ctx.r6.u32 + 868, r11.u32);
	// lwz r10,868(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 868);
	// stw r6,864(r10)
	PPC_STORE_U32(ctx.r10.u32 + 864, ctx.r6.u32);
	// stw r6,868(r5)
	PPC_STORE_U32(ctx.r5.u32 + 868, ctx.r6.u32);
loc_822A43AC:
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

__attribute__((alias("__imp__sub_822A43C4"))) PPC_WEAK_FUNC(sub_822A43C4);
PPC_FUNC_IMPL(__imp__sub_822A43C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A43C8"))) PPC_WEAK_FUNC(sub_822A43C8);
PPC_FUNC_IMPL(__imp__sub_822A43C8) {
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
	ctx.lr = 0x822A43D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82387a18
	ctx.lr = 0x822A43DC;
	sub_82387A18(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a4404
	if (cr6.eq) goto loc_822A4404;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822a4408
	if (cr6.eq) goto loc_822A4408;
loc_822A4404:
	// li r11,0
	r11.s64 = 0;
loc_822A4408:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a4444
	if (!cr6.eq) goto loc_822A4444;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a443c
	if (cr6.eq) goto loc_822A443C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x822090b8
	ctx.lr = 0x822A4430;
	sub_822090B8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a4444
	if (cr6.eq) goto loc_822A4444;
loc_822A443C:
	// li r11,0
	r11.s64 = 0;
	// b 0x822a4448
	goto loc_822A4448;
loc_822A4444:
	// li r11,1
	r11.s64 = 1;
loc_822A4448:
	// lwz r10,132(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x822a44b8
	if (!cr6.gt) goto loc_822A44B8;
	// addi r31,r28,8
	r31.s64 = r28.s64 + 8;
loc_822A4460:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a44a4
	if (cr6.eq) goto loc_822A44A4;
	// clrlwi r30,r27,24
	r30.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a4490
	if (cr6.eq) goto loc_822A4490;
	// bl 0x822a7250
	ctx.lr = 0x822A447C;
	sub_822A7250(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a4490
	if (cr6.eq) goto loc_822A4490;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a44a4
	if (cr6.eq) goto loc_822A44A4;
loc_822A4490:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A44A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A44A4:
	// lwz r11,132(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822a4460
	if (cr6.lt) goto loc_822A4460;
loc_822A44B8:
	// bl 0x82256058
	ctx.lr = 0x822A44BC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a44cc
	if (cr6.eq) goto loc_822A44CC;
	// bl 0x82256058
	ctx.lr = 0x822A44C8;
	sub_82256058(ctx, base);
	// bl 0x82256220
	ctx.lr = 0x822A44CC;
	sub_82256220(ctx, base);
loc_822A44CC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5052);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a44e0
	if (cr6.eq) goto loc_822A44E0;
	// bl 0x82260700
	ctx.lr = 0x822A44E0;
	sub_82260700(ctx, base);
loc_822A44E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a44f4
	if (cr6.eq) goto loc_822A44F4;
	// bl 0x82262898
	ctx.lr = 0x822A44F4;
	sub_82262898(ctx, base);
loc_822A44F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A44FC"))) PPC_WEAK_FUNC(sub_822A44FC);
PPC_FUNC_IMPL(__imp__sub_822A44FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4500"))) PPC_WEAK_FUNC(sub_822A4500);
PPC_FUNC_IMPL(__imp__sub_822A4500) {
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
	// lis r11,-32214
	r11.s64 = -2111176704;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,16752
	ctx.r4.s64 = r11.s64 + 16752;
	// addi r3,r10,22052
	ctx.r3.s64 = ctx.r10.s64 + 22052;
	// bl 0x82554798
	ctx.lr = 0x822A4520;
	sub_82554798(ctx, base);
	// lis r9,-32214
	ctx.r9.s64 = -2111176704;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,16808
	ctx.r4.s64 = ctx.r9.s64 + 16808;
	// addi r3,r8,22020
	ctx.r3.s64 = ctx.r8.s64 + 22020;
	// bl 0x82554798
	ctx.lr = 0x822A4534;
	sub_82554798(ctx, base);
	// lis r7,-32214
	ctx.r7.s64 = -2111176704;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,16872
	ctx.r4.s64 = ctx.r7.s64 + 16872;
	// addi r3,r6,21992
	ctx.r3.s64 = ctx.r6.s64 + 21992;
	// bl 0x82554798
	ctx.lr = 0x822A4548;
	sub_82554798(ctx, base);
	// lis r5,-32214
	ctx.r5.s64 = -2111176704;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,16944
	ctx.r4.s64 = ctx.r5.s64 + 16944;
	// addi r3,r3,21964
	ctx.r3.s64 = ctx.r3.s64 + 21964;
	// bl 0x82554798
	ctx.lr = 0x822A455C;
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

__attribute__((alias("__imp__sub_822A456C"))) PPC_WEAK_FUNC(sub_822A456C);
PPC_FUNC_IMPL(__imp__sub_822A456C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4570"))) PPC_WEAK_FUNC(sub_822A4570);
PPC_FUNC_IMPL(__imp__sub_822A4570) {
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
	ctx.lr = 0x822A4578;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a4654
	if (cr6.eq) goto loc_822A4654;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a5d20
	ctx.lr = 0x822A45A0;
	sub_822A5D20(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwzx r4,r29,r30
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b61b0
	ctx.lr = 0x822A45B0;
	sub_822B61B0(ctx, base);
	// addi r10,r31,100
	ctx.r10.s64 = r31.s64 + 100;
	// lwzx r8,r29,r30
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// addi r28,r30,264
	r28.s64 = r30.s64 + 264;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r28
	r27.u64 = r28.u64;
	// stwx r8,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, ctx.r8.u32);
	// lwz r31,264(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a4638
	if (cr6.eq) goto loc_822A4638;
loc_822A45D4:
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x822a45ec
	if (!cr6.eq) goto loc_822A45EC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a4270
	ctx.lr = 0x822A45EC;
	sub_822A4270(ctx, base);
loc_822A45EC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a45fc
	if (cr6.eq) goto loc_822A45FC;
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// b 0x822a4630
	goto loc_822A4630;
loc_822A45FC:
	// rlwinm r11,r27,0,0,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a4618
	if (cr6.eq) goto loc_822A4618;
	// clrlwi r11,r27,31
	r11.u64 = r27.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822a461c
	if (!cr6.eq) goto loc_822A461C;
loc_822A4618:
	// li r11,0
	r11.s64 = 0;
loc_822A461C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a4638
	if (cr6.eq) goto loc_822A4638;
	// rlwinm r27,r27,0,0,30
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_822A4630:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822a45d4
	if (!cr6.eq) goto loc_822A45D4;
loc_822A4638:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// bl 0x822a7f10
	ctx.lr = 0x822A4644;
	sub_822A7F10(ctx, base);
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// bl 0x822a56a0
	ctx.lr = 0x822A464C;
	sub_822A56A0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
loc_822A4654:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822A465C"))) PPC_WEAK_FUNC(sub_822A465C);
PPC_FUNC_IMPL(__imp__sub_822A465C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4660"))) PPC_WEAK_FUNC(sub_822A4660);
PPC_FUNC_IMPL(__imp__sub_822A4660) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,22084
	ctx.r10.s64 = r11.s64 + 22084;
	// addi r3,r31,524
	ctx.r3.s64 = r31.s64 + 524;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// stw r30,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r30.u32);
	// bl 0x821c2f70
	ctx.lr = 0x822A469C;
	sub_821C2F70(ctx, base);
	// addi r3,r31,544
	ctx.r3.s64 = r31.s64 + 544;
	// bl 0x821c2f70
	ctx.lr = 0x822A46A4;
	sub_821C2F70(ctx, base);
	// li r9,31
	ctx.r9.s64 = 31;
	// stb r30,564(r31)
	PPC_STORE_U8(r31.u32 + 564, r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3900
	ctx.lr = 0x822A46BC;
	sub_822A3900(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x822a3f48
	ctx.lr = 0x822A46CC;
	sub_822A3F48(ctx, base);
	// addi r11,r31,400
	r11.s64 = r31.s64 + 400;
	// li r10,31
	ctx.r10.s64 = 31;
loc_822A46D4:
	// stw r30,-124(r11)
	PPC_STORE_U32(r11.u32 + -124, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r30,-392(r11)
	PPC_STORE_U32(r11.u32 + -392, r30.u32);
	// stw r30,-264(r11)
	PPC_STORE_U32(r11.u32 + -264, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822a46d4
	if (!cr0.eq) goto loc_822A46D4;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r30.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_822A4714"))) PPC_WEAK_FUNC(sub_822A4714);
PPC_FUNC_IMPL(__imp__sub_822A4714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4718"))) PPC_WEAK_FUNC(sub_822A4718);
PPC_FUNC_IMPL(__imp__sub_822A4718) {
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
	// addi r10,r4,2
	ctx.r10.s64 = ctx.r4.s64 + 2;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r4,r11,264
	ctx.r4.s64 = r11.s64 + 264;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r31,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822a4330
	ctx.lr = 0x822A4750;
	sub_822A4330(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17892(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17892);
	// bl 0x822b5ff0
	ctx.lr = 0x822A4760;
	sub_822B5FF0(ctx, base);
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

__attribute__((alias("__imp__sub_822A4774"))) PPC_WEAK_FUNC(sub_822A4774);
PPC_FUNC_IMPL(__imp__sub_822A4774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4778"))) PPC_WEAK_FUNC(sub_822A4778);
PPC_FUNC_IMPL(__imp__sub_822A4778) {
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
	ctx.lr = 0x822A4780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r10,22084
	ctx.r9.s64 = ctx.r10.s64 + 22084;
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x822a47d0
	if (cr0.lt) goto loc_822A47D0;
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
loc_822A47AC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a47c4
	if (cr6.eq) goto loc_822A47C4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4570
	ctx.lr = 0x822A47C4;
	sub_822A4570(ctx, base);
loc_822A47C4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// bge 0x822a47ac
	if (!cr0.lt) goto loc_822A47AC;
loc_822A47D0:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// li r28,0
	r28.s64 = 0;
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x822a481c
	if (cr0.lt) goto loc_822A481C;
	// addi r11,r30,100
	r11.s64 = r30.s64 + 100;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
loc_822A47EC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a4810
	if (cr6.eq) goto loc_822A4810;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A480C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_822A4810:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x822a47ec
	if (!cr0.lt) goto loc_822A47EC;
loc_822A481C:
	// stw r28,132(r29)
	PPC_STORE_U32(r29.u32 + 132, r28.u32);
	// addi r31,r29,264
	r31.s64 = r29.s64 + 264;
	// lwz r11,272(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a4850
	if (cr6.eq) goto loc_822A4850;
loc_822A4830:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822a4844
	if (cr6.eq) goto loc_822A4844;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a4270
	ctx.lr = 0x822A4844;
	sub_822A4270(ctx, base);
loc_822A4844:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a4830
	if (!cr6.eq) goto loc_822A4830;
loc_822A4850:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x822A4858;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A4860"))) PPC_WEAK_FUNC(sub_822A4860);
PPC_FUNC_IMPL(__imp__sub_822A4860) {
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
	// li r3,572
	ctx.r3.s64 = 572;
	// bl 0x82130528
	ctx.lr = 0x822A4874;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a4884
	if (cr6.eq) goto loc_822A4884;
	// bl 0x822a4660
	ctx.lr = 0x822A4880;
	sub_822A4660(ctx, base);
	// b 0x822a4888
	goto loc_822A4888;
loc_822A4884:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A4888:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,17268(r11)
	PPC_STORE_U32(r11.u32 + 17268, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A48A0"))) PPC_WEAK_FUNC(sub_822A48A0);
PPC_FUNC_IMPL(__imp__sub_822A48A0) {
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
	// bl 0x822a4778
	ctx.lr = 0x822A48C0;
	sub_822A4778(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a48d8
	if (cr6.eq) goto loc_822A48D8;
	// bl 0x82130588
	ctx.lr = 0x822A48D4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822A48D8:
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

__attribute__((alias("__imp__sub_822A48F0"))) PPC_WEAK_FUNC(sub_822A48F0);
PPC_FUNC_IMPL(__imp__sub_822A48F0) {
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
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// xor r6,r11,r9
	ctx.r6.u64 = r11.u64 ^ ctx.r9.u64;
	// lfs f12,22408(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 22408);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// lfs f0,-28876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28876);
	f0.f64 = double(temp.f32);
	// ble cr6,0x822a4984
	if (!cr6.gt) goto loc_822A4984;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fmuls f0,f8,f12
	f0.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822a4968
	if (cr6.lt) goto loc_822A4968;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822a496c
	if (!cr6.gt) goto loc_822A496C;
loc_822A4968:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_822A496C:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822A4974;
	sub_8260C5C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822A4984:
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fmuls f0,f8,f12
	f0.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822a49b4
	if (cr6.lt) goto loc_822A49B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822a49b8
	if (!cr6.gt) goto loc_822A49B8;
loc_822A49B4:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_822A49B8:
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

__attribute__((alias("__imp__sub_822A49CC"))) PPC_WEAK_FUNC(sub_822A49CC);
PPC_FUNC_IMPL(__imp__sub_822A49CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A49D0"))) PPC_WEAK_FUNC(sub_822A49D0);
PPC_FUNC_IMPL(__imp__sub_822A49D0) {
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
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// xor r8,r11,r9
	ctx.r8.u64 = r11.u64 ^ ctx.r9.u64;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// ble cr6,0x822a4a30
	if (!cr6.gt) goto loc_822A4A30;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x8260c5c8
	ctx.lr = 0x822A4A20;
	sub_8260C5C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822A4A30:
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4A54"))) PPC_WEAK_FUNC(sub_822A4A54);
PPC_FUNC_IMPL(__imp__sub_822A4A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4A58"))) PPC_WEAK_FUNC(sub_822A4A58);
PPC_FUNC_IMPL(__imp__sub_822A4A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stb r11,17297(r10)
	PPC_STORE_U8(ctx.r10.u32 + 17297, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4A68"))) PPC_WEAK_FUNC(sub_822A4A68);
PPC_FUNC_IMPL(__imp__sub_822A4A68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a4a84
	if (cr6.eq) goto loc_822A4A84;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x822a4a84
	if (cr6.eq) goto loc_822A4A84;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822a4a88
	if (!cr6.eq) goto loc_822A4A88;
loc_822A4A84:
	// li r11,1
	r11.s64 = 1;
loc_822A4A88:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4A90"))) PPC_WEAK_FUNC(sub_822A4A90);
PPC_FUNC_IMPL(__imp__sub_822A4A90) {
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
	// bl 0x82387ba0
	ctx.lr = 0x822A4AA0;
	sub_82387BA0(ctx, base);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4AB4"))) PPC_WEAK_FUNC(sub_822A4AB4);
PPC_FUNC_IMPL(__imp__sub_822A4AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4AB8"))) PPC_WEAK_FUNC(sub_822A4AB8);
PPC_FUNC_IMPL(__imp__sub_822A4AB8) {
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
	// bl 0x82387ba0
	ctx.lr = 0x822A4AC8;
	sub_82387BA0(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4ADC"))) PPC_WEAK_FUNC(sub_822A4ADC);
PPC_FUNC_IMPL(__imp__sub_822A4ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4AE0"))) PPC_WEAK_FUNC(sub_822A4AE0);
PPC_FUNC_IMPL(__imp__sub_822A4AE0) {
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
	// bl 0x82387ba0
	ctx.lr = 0x822A4AF0;
	sub_82387BA0(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// rlwinm r9,r10,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r8,r11,52
	ctx.r8.s64 = r11.s64 + 52;
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r7,r11,-4
	ctx.r7.s64 = r11.s64 + -4;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4B24"))) PPC_WEAK_FUNC(sub_822A4B24);
PPC_FUNC_IMPL(__imp__sub_822A4B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4B28"))) PPC_WEAK_FUNC(sub_822A4B28);
PPC_FUNC_IMPL(__imp__sub_822A4B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17297
	ctx.r10.s64 = r11.s64 + 17297;
	// stbx r4,r3,r10
	PPC_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4B38"))) PPC_WEAK_FUNC(sub_822A4B38);
PPC_FUNC_IMPL(__imp__sub_822A4B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17297
	ctx.r10.s64 = r11.s64 + 17297;
	// lbzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4B48"))) PPC_WEAK_FUNC(sub_822A4B48);
PPC_FUNC_IMPL(__imp__sub_822A4B48) {
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
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x822A4B64;
	sub_82130588(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822A4B6C;
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

__attribute__((alias("__imp__sub_822A4B80"))) PPC_WEAK_FUNC(sub_822A4B80);
PPC_FUNC_IMPL(__imp__sub_822A4B80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,17292
	ctx.r9.s64 = ctx.r10.s64 + 17292;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822a4bb0
	if (cr6.eq) goto loc_822A4BB0;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_822A4BB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4BB8"))) PPC_WEAK_FUNC(sub_822A4BB8);
PPC_FUNC_IMPL(__imp__sub_822A4BB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r9,17292
	ctx.r8.s64 = ctx.r9.s64 + 17292;
	// lwzx r11,r7,r8
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bne cr6,0x822a4c04
	if (!cr6.eq) goto loc_822A4C04;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f1,14992(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14992);
	ctx.f1.f64 = double(temp.f32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x822a49d0
	sub_822A49D0(ctx, base);
	return;
loc_822A4C04:
	// cmplwi cr6,r10,9
	cr6.compare<uint32_t>(ctx.r10.u32, 9, xer);
	// beq cr6,0x822a4c6c
	if (cr6.eq) goto loc_822A4C6C;
	// cmplwi cr6,r10,11
	cr6.compare<uint32_t>(ctx.r10.u32, 11, xer);
	// beq cr6,0x822a4c6c
	if (cr6.eq) goto loc_822A4C6C;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822a4c6c
	if (cr6.eq) goto loc_822A4C6C;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
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
	// beq cr6,0x822a4c60
	if (cr6.eq) goto loc_822A4C60;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822A4C60:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822A4C6C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a4cbc
	if (cr6.eq) goto loc_822A4CBC;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822a4cbc
	if (cr6.eq) goto loc_822A4CBC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x822a4cbc
	if (cr6.eq) goto loc_822A4CBC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822a4cbc
	if (cr6.eq) goto loc_822A4CBC;
	// cmpwi cr6,r11,20
	cr6.compare<int32_t>(r11.s32, 20, xer);
	// beq cr6,0x822a4cbc
	if (cr6.eq) goto loc_822A4CBC;
	// cmpwi cr6,r11,21
	cr6.compare<int32_t>(r11.s32, 21, xer);
	// beq cr6,0x822a4cbc
	if (cr6.eq) goto loc_822A4CBC;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f1,17032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f1.f64 = double(temp.f32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x822a49d0
	sub_822A49D0(ctx, base);
	return;
loc_822A4CBC:
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f1,17032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f1.f64 = double(temp.f32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x822a48f0
	sub_822A48F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A4CDC"))) PPC_WEAK_FUNC(sub_822A4CDC);
PPC_FUNC_IMPL(__imp__sub_822A4CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4CE0"))) PPC_WEAK_FUNC(sub_822A4CE0);
PPC_FUNC_IMPL(__imp__sub_822A4CE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
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
	// beq cr6,0x822a4d3c
	if (cr6.eq) goto loc_822A4D3C;
	// lbz r11,3(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// xor r10,r11,r10
	ctx.r10.u64 = r11.u64 ^ ctx.r10.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// subfic r8,r9,127
	xer.ca = ctx.r9.u32 <= 127;
	ctx.r8.s64 = 127 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822a4d40
	if (cr6.eq) goto loc_822A4D40;
loc_822A4D3C:
	// li r11,0
	r11.s64 = 0;
loc_822A4D40:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4D48"))) PPC_WEAK_FUNC(sub_822A4D48);
PPC_FUNC_IMPL(__imp__sub_822A4D48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
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
	// bne cr6,0x822a4da4
	if (!cr6.eq) goto loc_822A4DA4;
	// lbz r11,3(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// xor r10,r11,r10
	ctx.r10.u64 = r11.u64 ^ ctx.r10.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// subfic r8,r9,127
	xer.ca = ctx.r9.u32 <= 127;
	ctx.r8.s64 = 127 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x822a4da8
	if (!cr6.eq) goto loc_822A4DA8;
loc_822A4DA4:
	// li r11,0
	r11.s64 = 0;
loc_822A4DA8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4DB0"))) PPC_WEAK_FUNC(sub_822A4DB0);
PPC_FUNC_IMPL(__imp__sub_822A4DB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
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
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4DE4"))) PPC_WEAK_FUNC(sub_822A4DE4);
PPC_FUNC_IMPL(__imp__sub_822A4DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4DE8"))) PPC_WEAK_FUNC(sub_822A4DE8);
PPC_FUNC_IMPL(__imp__sub_822A4DE8) {
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
	ctx.lr = 0x822A4DF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r31,0
	r31.s64 = 0;
	// addi r8,r10,17292
	ctx.r8.s64 = ctx.r10.s64 + 17292;
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r7,r8
	r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
loc_822A4E1C:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stb r31,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, r31.u8);
	// stb r31,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, r31.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r31,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, r31.u8);
	// beq cr6,0x822a4e60
	if (cr6.eq) goto loc_822A4E60;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_822A4E40:
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stbx r31,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, r31.u8);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r31,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r31.u32);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// blt cr6,0x822a4e40
	if (cr6.lt) goto loc_822A4E40;
loc_822A4E60:
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822a4e7c
	if (!cr6.eq) goto loc_822A4E7C;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// beq cr6,0x822a4e80
	if (cr6.eq) goto loc_822A4E80;
loc_822A4E7C:
	// li r11,1
	r11.s64 = 1;
loc_822A4E80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a4ea4
	if (cr6.eq) goto loc_822A4EA4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r7,-1
	ctx.r7.s64 = -1;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// add r6,r29,r11
	ctx.r6.u64 = r29.u64 + r11.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8260b740
	ctx.lr = 0x822A4EA4;
	sub_8260B740(ctx, base);
loc_822A4EA4:
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpwi cr6,r29,888
	cr6.compare<int32_t>(r29.s32, 888, xer);
	// blt cr6,0x822a4e1c
	if (cr6.lt) goto loc_822A4E1C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A4EBC"))) PPC_WEAK_FUNC(sub_822A4EBC);
PPC_FUNC_IMPL(__imp__sub_822A4EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4EC0"))) PPC_WEAK_FUNC(sub_822A4EC0);
PPC_FUNC_IMPL(__imp__sub_822A4EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A4ECC"))) PPC_WEAK_FUNC(sub_822A4ECC);
PPC_FUNC_IMPL(__imp__sub_822A4ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A4ED0"))) PPC_WEAK_FUNC(sub_822A4ED0);
PPC_FUNC_IMPL(__imp__sub_822A4ED0) {
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
	ctx.lr = 0x822A4ED8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82387ba0
	ctx.lr = 0x822A4EE4;
	sub_82387BA0(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r28,r11,21384
	r28.s64 = r11.s64 + 21384;
	// rlwinm r9,r10,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r8,r28,52
	ctx.r8.s64 = r28.s64 + 52;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bne cr6,0x822a4f1c
	if (!cr6.eq) goto loc_822A4F1C;
	// bl 0x82387b90
	ctx.lr = 0x822A4F08;
	sub_82387B90(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// b 0x822a4f2c
	goto loc_822A4F2C;
loc_822A4F1C:
	// bl 0x82387b90
	ctx.lr = 0x822A4F20;
	sub_82387B90(ctx, base);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
loc_822A4F2C:
	// lis r29,-32115
	r29.s64 = -2104688640;
	// extsh r31,r11
	r31.s64 = r11.s16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-12052(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x822A4F40;
	sub_82397BA8(ctx, base);
	// lbz r11,604(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 604);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a4f6c
	if (!cr6.eq) goto loc_822A4F6C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12052(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12052);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,17292
	r11.s64 = r11.s64 + 17292;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82397ba8
	ctx.lr = 0x822A4F68;
	sub_82397BA8(ctx, base);
	// b 0x822a4fb8
	goto loc_822A4FB8;
loc_822A4F6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82387ba0
	ctx.lr = 0x822A4F74;
	sub_82387BA0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r10,r28,52
	ctx.r10.s64 = r28.s64 + 52;
	// rlwinm r9,r11,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17292
	r11.s64 = r11.s64 + 17292;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// beq cr6,0x822a4fac
	if (cr6.eq) goto loc_822A4FAC;
	// bl 0x82387b90
	ctx.lr = 0x822A4FA0;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238b080
	ctx.lr = 0x822A4FA8;
	sub_8238B080(ctx, base);
	// b 0x822a4fb8
	goto loc_822A4FB8;
loc_822A4FAC:
	// bl 0x82387b90
	ctx.lr = 0x822A4FB0;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238b070
	ctx.lr = 0x822A4FB8;
	sub_8238B070(ctx, base);
loc_822A4FB8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r10,r11,17297
	ctx.r10.s64 = r11.s64 + 17297;
	// lbzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a4fe0
	if (cr6.eq) goto loc_822A4FE0;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,-12052(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x822A4FDC;
	sub_82397BA8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_822A4FE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A4FE8"))) PPC_WEAK_FUNC(sub_822A4FE8);
PPC_FUNC_IMPL(__imp__sub_822A4FE8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r31,0
	r31.s64 = 0;
	// stw r4,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r4.u32);
	// stb r31,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r31.u8);
	// lbz r10,17296(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17296);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a502c
	if (!cr6.eq) goto loc_822A502C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,17296(r11)
	PPC_STORE_U8(r11.u32 + 17296, ctx.r10.u8);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x822a4ed0
	ctx.lr = 0x822A502C;
	sub_822A4ED0(ctx, base);
loc_822A502C:
	// li r3,776
	ctx.r3.s64 = 776;
	// bl 0x82130528
	ctx.lr = 0x822A5034;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5044
	if (cr6.eq) goto loc_822A5044;
	// bl 0x8260b730
	ctx.lr = 0x822A5040;
	sub_8260B730(ctx, base);
	// b 0x822a5048
	goto loc_822A5048;
loc_822A5044:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822A5048:
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// li r3,888
	ctx.r3.s64 = 888;
	// bl 0x82130528
	ctx.lr = 0x822A5054;
	sub_82130528(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a5094
	if (cr6.eq) goto loc_822A5094;
	// li r10,73
	ctx.r10.s64 = 73;
	// addi r11,r9,2
	r11.s64 = ctx.r9.s64 + 2;
loc_822A5068:
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
	// bge 0x822a5068
	if (!cr0.lt) goto loc_822A5068;
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// b 0x822a5098
	goto loc_822A5098;
loc_822A5094:
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
loc_822A5098:
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

__attribute__((alias("__imp__sub_822A50B4"))) PPC_WEAK_FUNC(sub_822A50B4);
PPC_FUNC_IMPL(__imp__sub_822A50B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A50B8"))) PPC_WEAK_FUNC(sub_822A50B8);
PPC_FUNC_IMPL(__imp__sub_822A50B8) {
	PPC_FUNC_PROLOGUE();
	// b 0x822a4de8
	sub_822A4DE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A50BC"))) PPC_WEAK_FUNC(sub_822A50BC);
PPC_FUNC_IMPL(__imp__sub_822A50BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A50C0"))) PPC_WEAK_FUNC(sub_822A50C0);
PPC_FUNC_IMPL(__imp__sub_822A50C0) {
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
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r10,17292
	ctx.r9.s64 = ctx.r10.s64 + 17292;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r8,r9
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x8260b990
	ctx.lr = 0x822A50F8;
	sub_8260B990(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// lbz r7,326(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 326);
	// lbz r6,324(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 324);
	// xor r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// subfic r3,r4,127
	xer.ca = ctx.r4.u32 <= 127;
	ctx.r3.s64 = 127 - ctx.r4.s64;
	// subfe r9,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r3.u64 + ctx.r3.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a516c
	if (cr6.eq) goto loc_822A516C;
	// lbz r9,338(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 338);
	// lbz r8,336(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 336);
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// subfic r5,r6,127
	xer.ca = ctx.r6.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a516c
	if (cr6.eq) goto loc_822A516C;
	// lwz r9,320(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 320);
	// li r8,255
	ctx.r8.s64 = 255;
	// stb r8,314(r10)
	PPC_STORE_U8(ctx.r10.u32 + 314, ctx.r8.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a51a0
	if (cr6.eq) goto loc_822A51A0;
	// lbz r10,316(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 316);
	// rotlwi r7,r10,3
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// stbx r8,r7,r9
	PPC_STORE_U8(ctx.r7.u32 + ctx.r9.u32, ctx.r8.u8);
	// b 0x822a51a0
	goto loc_822A51A0;
loc_822A516C:
	// lwz r9,208(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a51a0
	if (!cr6.eq) goto loc_822A51A0;
	// lwz r9,212(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822a51a0
	if (!cr6.eq) goto loc_822A51A0;
	// lwz r9,320(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 320);
	// stb r11,314(r10)
	PPC_STORE_U8(ctx.r10.u32 + 314, r11.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a51a0
	if (cr6.eq) goto loc_822A51A0;
	// lbz r10,316(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 316);
	// rotlwi r8,r10,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// stbx r11,r8,r9
	PPC_STORE_U8(ctx.r8.u32 + ctx.r9.u32, r11.u8);
loc_822A51A0:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lbz r9,314(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 314);
	// lbz r8,312(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 312);
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// subfic r5,r6,127
	xer.ca = ctx.r6.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5398
	if (cr6.eq) goto loc_822A5398;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
loc_822A51D4:
	// cmpwi cr6,r5,22
	cr6.compare<int32_t>(ctx.r5.s32, 22, xer);
	// beq cr6,0x822a5384
	if (cr6.eq) goto loc_822A5384;
	// cmpwi cr6,r5,23
	cr6.compare<int32_t>(ctx.r5.s32, 23, xer);
	// beq cr6,0x822a5384
	if (cr6.eq) goto loc_822A5384;
	// cmpwi cr6,r5,24
	cr6.compare<int32_t>(ctx.r5.s32, 24, xer);
	// beq cr6,0x822a5384
	if (cr6.eq) goto loc_822A5384;
	// cmpwi cr6,r5,25
	cr6.compare<int32_t>(ctx.r5.s32, 25, xer);
	// beq cr6,0x822a5384
	if (cr6.eq) goto loc_822A5384;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,176(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822a5258
	if (!cr6.eq) goto loc_822A5258;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r9,180(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x822a5258
	if (!cr6.eq) goto loc_822A5258;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r11,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, r11.u8);
	// stb r11,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r11.u8);
	// beq cr6,0x822a5258
	if (cr6.eq) goto loc_822A5258;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822A5238:
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stbx r11,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r11.u8);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// cmplwi cr6,r10,512
	cr6.compare<uint32_t>(ctx.r10.u32, 512, xer);
	// blt cr6,0x822a5238
	if (cr6.lt) goto loc_822A5238;
loc_822A5258:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,184(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822a52bc
	if (!cr6.eq) goto loc_822A52BC;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r9,188(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x822a52bc
	if (!cr6.eq) goto loc_822A52BC;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r11,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, r11.u8);
	// stb r11,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r11.u8);
	// beq cr6,0x822a52bc
	if (cr6.eq) goto loc_822A52BC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822A529C:
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stbx r11,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r11.u8);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r10,512
	cr6.compare<uint32_t>(ctx.r10.u32, 512, xer);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// blt cr6,0x822a529c
	if (cr6.lt) goto loc_822A529C;
loc_822A52BC:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,192(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822a5320
	if (!cr6.eq) goto loc_822A5320;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x822a5320
	if (!cr6.eq) goto loc_822A5320;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r11,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, r11.u8);
	// stb r11,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r11.u8);
	// beq cr6,0x822a5320
	if (cr6.eq) goto loc_822A5320;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822A5300:
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stbx r11,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r11.u8);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r10,512
	cr6.compare<uint32_t>(ctx.r10.u32, 512, xer);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// blt cr6,0x822a5300
	if (cr6.lt) goto loc_822A5300;
loc_822A5320:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822a5384
	if (!cr6.eq) goto loc_822A5384;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r9,204(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x822a5384
	if (!cr6.eq) goto loc_822A5384;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r11,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, r11.u8);
	// stb r11,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r11.u8);
	// beq cr6,0x822a5384
	if (cr6.eq) goto loc_822A5384;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822A5364:
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stbx r11,r10,r8
	PPC_STORE_U8(ctx.r10.u32 + ctx.r8.u32, r11.u8);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r10,512
	cr6.compare<uint32_t>(ctx.r10.u32, 512, xer);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// blt cr6,0x822a5364
	if (cr6.lt) goto loc_822A5364;
loc_822A5384:
	// addi r7,r7,12
	ctx.r7.s64 = ctx.r7.s64 + 12;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// cmpwi cr6,r7,888
	cr6.compare<int32_t>(ctx.r7.s32, 888, xer);
	// blt cr6,0x822a51d4
	if (cr6.lt) goto loc_822A51D4;
loc_822A5398:
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

__attribute__((alias("__imp__sub_822A53B0"))) PPC_WEAK_FUNC(sub_822A53B0);
PPC_FUNC_IMPL(__imp__sub_822A53B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822A53B8;
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
	// bl 0x82387ba0
	ctx.lr = 0x822A53CC;
	sub_82387BA0(ctx, base);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82387ba0
	ctx.lr = 0x822A53D8;
	sub_82387BA0(ctx, base);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a4ed0
	ctx.lr = 0x822A53E4;
	sub_822A4ED0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A53EC"))) PPC_WEAK_FUNC(sub_822A53EC);
PPC_FUNC_IMPL(__imp__sub_822A53EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A53F0"))) PPC_WEAK_FUNC(sub_822A53F0);
PPC_FUNC_IMPL(__imp__sub_822A53F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A5410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_822A5424"))) PPC_WEAK_FUNC(sub_822A5424);
PPC_FUNC_IMPL(__imp__sub_822A5424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5428"))) PPC_WEAK_FUNC(sub_822A5428);
PPC_FUNC_IMPL(__imp__sub_822A5428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A5448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
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

__attribute__((alias("__imp__sub_822A545C"))) PPC_WEAK_FUNC(sub_822A545C);
PPC_FUNC_IMPL(__imp__sub_822A545C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5460"))) PPC_WEAK_FUNC(sub_822A5460);
PPC_FUNC_IMPL(__imp__sub_822A5460) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,22740
	ctx.r9.s64 = r11.s64 + 22740;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x82740ec0
	ctx.lr = 0x822A5494;
	sub_82740EC0(ctx, base);
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a54ac
	if (cr6.eq) goto loc_822A54AC;
	// bl 0x82130588
	ctx.lr = 0x822A54A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822A54AC:
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

__attribute__((alias("__imp__sub_822A54C4"))) PPC_WEAK_FUNC(sub_822A54C4);
PPC_FUNC_IMPL(__imp__sub_822A54C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A54C8"))) PPC_WEAK_FUNC(sub_822A54C8);
PPC_FUNC_IMPL(__imp__sub_822A54C8) {
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
	// addi r10,r11,22804
	ctx.r10.s64 = r11.s64 + 22804;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82350570
	ctx.lr = 0x822A54F4;
	sub_82350570(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a550c
	if (cr6.eq) goto loc_822A550C;
	// bl 0x82130588
	ctx.lr = 0x822A5508;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822A550C:
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

__attribute__((alias("__imp__sub_822A5524"))) PPC_WEAK_FUNC(sub_822A5524);
PPC_FUNC_IMPL(__imp__sub_822A5524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5528"))) PPC_WEAK_FUNC(sub_822A5528);
PPC_FUNC_IMPL(__imp__sub_822A5528) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,896(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// lfs f1,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5534"))) PPC_WEAK_FUNC(sub_822A5534);
PPC_FUNC_IMPL(__imp__sub_822A5534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5538"))) PPC_WEAK_FUNC(sub_822A5538);
PPC_FUNC_IMPL(__imp__sub_822A5538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,896(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// lfs f1,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5544"))) PPC_WEAK_FUNC(sub_822A5544);
PPC_FUNC_IMPL(__imp__sub_822A5544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5548"))) PPC_WEAK_FUNC(sub_822A5548);
PPC_FUNC_IMPL(__imp__sub_822A5548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,896(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// lfs f1,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5554"))) PPC_WEAK_FUNC(sub_822A5554);
PPC_FUNC_IMPL(__imp__sub_822A5554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5558"))) PPC_WEAK_FUNC(sub_822A5558);
PPC_FUNC_IMPL(__imp__sub_822A5558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,896(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// lfs f1,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5564"))) PPC_WEAK_FUNC(sub_822A5564);
PPC_FUNC_IMPL(__imp__sub_822A5564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5568"))) PPC_WEAK_FUNC(sub_822A5568);
PPC_FUNC_IMPL(__imp__sub_822A5568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,896(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// lfs f1,88(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5574"))) PPC_WEAK_FUNC(sub_822A5574);
PPC_FUNC_IMPL(__imp__sub_822A5574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5578"))) PPC_WEAK_FUNC(sub_822A5578);
PPC_FUNC_IMPL(__imp__sub_822A5578) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,896(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5580"))) PPC_WEAK_FUNC(sub_822A5580);
PPC_FUNC_IMPL(__imp__sub_822A5580) {
	PPC_FUNC_PROLOGUE();
	// b 0x822aaa18
	sub_822AAA18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A5584"))) PPC_WEAK_FUNC(sub_822A5584);
PPC_FUNC_IMPL(__imp__sub_822A5584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5588"))) PPC_WEAK_FUNC(sub_822A5588);
PPC_FUNC_IMPL(__imp__sub_822A5588) {
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
	// lwz r3,892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a55bc
	if (cr6.eq) goto loc_822A55BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A55BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A55BC:
	// lwz r10,896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,892(r31)
	PPC_STORE_U32(r31.u32 + 892, r11.u32);
	// stw r11,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, r11.u32);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// bl 0x822aa960
	ctx.lr = 0x822A55DC;
	sub_822AA960(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A55F0"))) PPC_WEAK_FUNC(sub_822A55F0);
PPC_FUNC_IMPL(__imp__sub_822A55F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,904(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 904);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5600"))) PPC_WEAK_FUNC(sub_822A5600);
PPC_FUNC_IMPL(__imp__sub_822A5600) {
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
	ctx.lr = 0x822A5620;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5664
	if (cr6.eq) goto loc_822A5664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A5640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a5664
	if (cr6.eq) goto loc_822A5664;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5664
	if (cr6.eq) goto loc_822A5664;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82274120
	ctx.lr = 0x822A5664;
	sub_82274120(ctx, base);
loc_822A5664:
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

__attribute__((alias("__imp__sub_822A567C"))) PPC_WEAK_FUNC(sub_822A567C);
PPC_FUNC_IMPL(__imp__sub_822A567C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5680"))) PPC_WEAK_FUNC(sub_822A5680);
PPC_FUNC_IMPL(__imp__sub_822A5680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A569C"))) PPC_WEAK_FUNC(sub_822A569C);
PPC_FUNC_IMPL(__imp__sub_822A569C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A56A0"))) PPC_WEAK_FUNC(sub_822A56A0);
PPC_FUNC_IMPL(__imp__sub_822A56A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A56C0"))) PPC_WEAK_FUNC(sub_822A56C0);
PPC_FUNC_IMPL(__imp__sub_822A56C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A56C4"))) PPC_WEAK_FUNC(sub_822A56C4);
PPC_FUNC_IMPL(__imp__sub_822A56C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A56C8"))) PPC_WEAK_FUNC(sub_822A56C8);
PPC_FUNC_IMPL(__imp__sub_822A56C8) {
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
	// lwz r3,904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 904);
	// bl 0x82388598
	ctx.lr = 0x822A56E4;
	sub_82388598(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822a5788
	if (cr6.lt) goto loc_822A5788;
	// lwz r11,896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822a576c
	if (cr6.eq) goto loc_822A576C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a5724
	if (cr6.eq) goto loc_822A5724;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822a5728
	if (cr6.eq) goto loc_822A5728;
loc_822A5724:
	// li r11,0
	r11.s64 = 0;
loc_822A5728:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a576c
	if (!cr6.eq) goto loc_822A576C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a576c
	if (cr6.eq) goto loc_822A576C;
	// bl 0x82388658
	ctx.lr = 0x822A5744;
	sub_82388658(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a576c
	if (!cr6.eq) goto loc_822A576C;
	// bl 0x82387a18
	ctx.lr = 0x822A5754;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a576c
	if (!cr6.eq) goto loc_822A576C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bl 0x82338ef8
	ctx.lr = 0x822A576C;
	sub_82338EF8(ctx, base);
loc_822A576C:
	// lbz r11,908(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a5788
	if (!cr6.eq) goto loc_822A5788;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5788
	if (cr6.eq) goto loc_822A5788;
	// bl 0x822b35e8
	ctx.lr = 0x822A5788;
	sub_822B35E8(ctx, base);
loc_822A5788:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A579C"))) PPC_WEAK_FUNC(sub_822A579C);
PPC_FUNC_IMPL(__imp__sub_822A579C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A57A0"))) PPC_WEAK_FUNC(sub_822A57A0);
PPC_FUNC_IMPL(__imp__sub_822A57A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r3,948
	ctx.r10.s64 = ctx.r3.s64 + 948;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822A57B0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822a57b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822A57B0;
	// li r11,1
	r11.s64 = 1;
	// stb r11,980(r3)
	PPC_STORE_U8(ctx.r3.u32 + 980, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A57D0"))) PPC_WEAK_FUNC(sub_822A57D0);
PPC_FUNC_IMPL(__imp__sub_822A57D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a57f8
	if (cr6.eq) goto loc_822A57F8;
	// bl 0x822b34b0
	ctx.lr = 0x822A57F8;
	sub_822B34B0(ctx, base);
loc_822A57F8:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822a585c
	if (cr6.eq) goto loc_822A585C;
	// addi r11,r31,224
	r11.s64 = r31.s64 + 224;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x82558290
	ctx.lr = 0x822A5814;
	sub_82558290(ctx, base);
	// lfs f2,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x822A5820;
	sub_823DCDD8(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,176(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// stfs f0,180(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// stfs f31,184(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 184, temp.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A5854;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,984(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// b 0x822a5868
	goto loc_822A5868;
loc_822A585C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,984(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
loc_822A5868:
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

__attribute__((alias("__imp__sub_822A5880"))) PPC_WEAK_FUNC(sub_822A5880);
PPC_FUNC_IMPL(__imp__sub_822A5880) {
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
	// lwz r3,904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 904);
	// bl 0x82388580
	ctx.lr = 0x822A58A4;
	sub_82388580(ctx, base);
	// lbz r11,22(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a592c
	if (!cr6.eq) goto loc_822A592C;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a592c
	if (!cr6.eq) goto loc_822A592C;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,909(r31)
	PPC_STORE_U8(r31.u32 + 909, ctx.r9.u8);
	// beq cr6,0x822a58e8
	if (cr6.eq) goto loc_822A58E8;
	// lwz r10,912(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 912);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// sth r10,8(r8)
	PPC_STORE_U16(ctx.r8.u32 + 8, ctx.r10.u16);
	// b 0x822a592c
	goto loc_822A592C;
loc_822A58E8:
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a5908
	if (cr6.eq) goto loc_822A5908;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A5908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A5908:
	// lwz r3,896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// bl 0x822a0640
	ctx.lr = 0x822A5910;
	sub_822A0640(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8232c3a8
	ctx.lr = 0x822A591C;
	sub_8232C3A8(ctx, base);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// sth r10,8(r8)
	PPC_STORE_U16(ctx.r8.u32 + 8, ctx.r10.u16);
loc_822A592C:
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

__attribute__((alias("__imp__sub_822A5944"))) PPC_WEAK_FUNC(sub_822A5944);
PPC_FUNC_IMPL(__imp__sub_822A5944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5948"))) PPC_WEAK_FUNC(sub_822A5948);
PPC_FUNC_IMPL(__imp__sub_822A5948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// b 0x822a3998
	sub_822A3998(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A5958"))) PPC_WEAK_FUNC(sub_822A5958);
PPC_FUNC_IMPL(__imp__sub_822A5958) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x822a85b0
	ctx.lr = 0x822A5978;
	sub_822A85B0(ctx, base);
	// lwz r3,880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a5994
	if (cr6.eq) goto loc_822A5994;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822A5994;
	sub_822B0F10(ctx, base);
loc_822A5994:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// lhz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// sth r7,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r7.u16);
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// sth r8,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r8.u16);
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

__attribute__((alias("__imp__sub_822A59D4"))) PPC_WEAK_FUNC(sub_822A59D4);
PPC_FUNC_IMPL(__imp__sub_822A59D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A59D8"))) PPC_WEAK_FUNC(sub_822A59D8);
PPC_FUNC_IMPL(__imp__sub_822A59D8) {
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
	ctx.lr = 0x822A59E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822A59FC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5a4c
	if (cr6.eq) goto loc_822A5A4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822A5A14;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a5a4c
	if (cr6.eq) goto loc_822A5A4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822A5A2C;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// lwz r11,784(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// addi r9,r11,-13
	ctx.r9.s64 = r11.s64 + -13;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822A5A4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A5A58"))) PPC_WEAK_FUNC(sub_822A5A58);
PPC_FUNC_IMPL(__imp__sub_822A5A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822b34b0
	sub_822B34B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A5A68"))) PPC_WEAK_FUNC(sub_822A5A68);
PPC_FUNC_IMPL(__imp__sub_822A5A68) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A5A6C"))) PPC_WEAK_FUNC(sub_822A5A6C);
PPC_FUNC_IMPL(__imp__sub_822A5A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5A70"))) PPC_WEAK_FUNC(sub_822A5A70);
PPC_FUNC_IMPL(__imp__sub_822A5A70) {
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
	// addi r31,r3,288
	r31.s64 = ctx.r3.s64 + 288;
	// li r30,11
	r30.s64 = 11;
loc_822A5A8C:
	// addi r31,r31,-24
	r31.s64 = r31.s64 + -24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d9788
	ctx.lr = 0x822A5A98;
	sub_826D9788(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822a5a8c
	if (!cr0.lt) goto loc_822A5A8C;
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

__attribute__((alias("__imp__sub_822A5AB8"))) PPC_WEAK_FUNC(sub_822A5AB8);
PPC_FUNC_IMPL(__imp__sub_822A5AB8) {
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
	// bl 0x82387a18
	ctx.lr = 0x822A5AD0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5bc0
	if (cr6.eq) goto loc_822A5BC0;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5bc0
	if (cr6.eq) goto loc_822A5BC0;
	// bl 0x82203310
	ctx.lr = 0x822A5AEC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5bc0
	if (cr6.eq) goto loc_822A5BC0;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x822A5B04;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822a5b1c
	if (!cr6.eq) goto loc_822A5B1C;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// lbz r10,277(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 277);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a5bc0
	if (cr6.eq) goto loc_822A5BC0;
loc_822A5B1C:
	// bl 0x82256058
	ctx.lr = 0x822A5B20;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5b6c
	if (cr6.eq) goto loc_822A5B6C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A5B3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a5b6c
	if (cr6.eq) goto loc_822A5B6C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A5B58;
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
loc_822A5B6C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e0b0
	ctx.lr = 0x822A5B7C;
	sub_8227E0B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a5ba8
	if (cr6.eq) goto loc_822A5BA8;
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x822A5B94;
	sub_822577D0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822A5BA8:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822A5BC0:
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

__attribute__((alias("__imp__sub_822A5BD8"))) PPC_WEAK_FUNC(sub_822A5BD8);
PPC_FUNC_IMPL(__imp__sub_822A5BD8) {
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
	ctx.lr = 0x822A5BE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82387a18
	ctx.lr = 0x822A5BF8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5cb8
	if (cr6.eq) goto loc_822A5CB8;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5ca0
	if (cr6.eq) goto loc_822A5CA0;
	// bl 0x82203310
	ctx.lr = 0x822A5C14;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5ca0
	if (cr6.eq) goto loc_822A5CA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5ab8
	ctx.lr = 0x822A5C28;
	sub_822A5AB8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a5ca0
	if (cr6.eq) goto loc_822A5CA0;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5cac
	if (cr6.eq) goto loc_822A5CAC;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822A5C44;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a5cac
	if (cr6.eq) goto loc_822A5CAC;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x822a5cac
	if (cr6.eq) goto loc_822A5CAC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822A5C5C;
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
	ctx.lr = 0x822A5C70;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822A5C78;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822a5c84
	if (cr6.eq) goto loc_822A5C84;
	// li r28,1
	r28.s64 = 1;
loc_822A5C84:
	// bl 0x82256058
	ctx.lr = 0x822A5C88;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5cb8
	if (cr6.eq) goto loc_822A5CB8;
	// bl 0x82256058
	ctx.lr = 0x822A5C94;
	sub_82256058(ctx, base);
	// bl 0x82256028
	ctx.lr = 0x822A5C98;
	sub_82256028(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x822a5cb8
	if (cr6.gt) goto loc_822A5CB8;
loc_822A5CA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822A5CAC:
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822A5CB8:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a5ce0
	if (!cr6.eq) goto loc_822A5CE0;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a5ce0
	if (!cr6.eq) goto loc_822A5CE0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8420
	ctx.lr = 0x822A5CDC;
	sub_822A8420(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_822A5CE0:
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5d14
	if (cr6.eq) goto loc_822A5D14;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x822a5d14
	if (!cr6.eq) goto loc_822A5D14;
	// bl 0x82387a18
	ctx.lr = 0x822A5CF8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5d14
	if (cr6.eq) goto loc_822A5D14;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x822A5D10;
	sub_822577D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_822A5D14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A5D20"))) PPC_WEAK_FUNC(sub_822A5D20);
PPC_FUNC_IMPL(__imp__sub_822A5D20) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,1220(r31)
	PPC_STORE_U32(r31.u32 + 1220, ctx.r4.u32);
	// beq cr6,0x822a5d78
	if (cr6.eq) goto loc_822A5D78;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r5,r11,22928
	ctx.r5.s64 = r11.s64 + 22928;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822A5D58;
	sub_82137A08(ctx, base);
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x822A5D64;
	sub_824E7118(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x822A5D78;
	sub_822183B0(ctx, base);
loc_822A5D78:
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

__attribute__((alias("__imp__sub_822A5D8C"))) PPC_WEAK_FUNC(sub_822A5D8C);
PPC_FUNC_IMPL(__imp__sub_822A5D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A5D90"))) PPC_WEAK_FUNC(sub_822A5D90);
PPC_FUNC_IMPL(__imp__sub_822A5D90) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
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
	ctx.lr = 0x822A5DBC;
	sub_823D9890(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r5,r10,22928
	ctx.r5.s64 = ctx.r10.s64 + 22928;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822A5DD4;
	sub_82137A08(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822A5DE4;
	sub_82218310(ctx, base);
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

__attribute__((alias("__imp__sub_822A5DF8"))) PPC_WEAK_FUNC(sub_822A5DF8);
PPC_FUNC_IMPL(__imp__sub_822A5DF8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822A5E00;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r26,-1
	r26.s64 = -1;
	// li r27,0
	r27.s64 = 0;
	// bl 0x82387a18
	ctx.lr = 0x822A5E18;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6000
	if (cr6.eq) goto loc_822A6000;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822A5E38;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a6050
	if (cr6.eq) goto loc_822A6050;
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6050
	if (cr6.eq) goto loc_822A6050;
	// bl 0x82203310
	ctx.lr = 0x822A5E54;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6050
	if (cr6.eq) goto loc_822A6050;
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5e7c
	if (cr6.eq) goto loc_822A5E7C;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822A5E74;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x822a6050
	if (cr6.eq) goto loc_822A6050;
loc_822A5E7C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x822A5E88;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,13
	cr6.compare<uint32_t>(ctx.r3.u32, 13, xer);
	// bne cr6,0x822a5fd4
	if (!cr6.eq) goto loc_822A5FD4;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x822A5E9C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5fd4
	if (cr6.eq) goto loc_822A5FD4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x822A5EB4;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a5fd4
	if (cr6.eq) goto loc_822A5FD4;
	// li r4,19
	ctx.r4.s64 = 19;
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x822A5ECC;
	sub_822051A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822a5fbc
	if (!cr6.gt) goto loc_822A5FBC;
	// bl 0x82256058
	ctx.lr = 0x822A5ED8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a5ef0
	if (cr6.eq) goto loc_822A5EF0;
	// bl 0x82256058
	ctx.lr = 0x822A5EE4;
	sub_82256058(ctx, base);
	// bl 0x82256028
	ctx.lr = 0x822A5EE8;
	sub_82256028(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822a5f90
	goto loc_822A5F90;
loc_822A5EF0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x822A5F00;
	sub_82293E30(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x822A5F10;
	sub_82295538(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293f60
	ctx.lr = 0x822A5F18;
	sub_82293F60(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x822A5F28;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x822A5F2C;
	sub_82293F60(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfd f0,22960(r10)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 22960);
	// lfd f13,22952(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + 22952);
	// lfd f12,22944(r8)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r8.u32 + 22944);
	// lfs f11,32(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fadd f10,f11,f31
	ctx.f10.f64 = ctx.f11.f64 + f31.f64;
	// fadd f9,f10,f0
	ctx.f9.f64 = ctx.f10.f64 + f0.f64;
	// fsub f8,f1,f9
	ctx.f8.f64 = ctx.f1.f64 - ctx.f9.f64;
	// fmul f7,f8,f13
	ctx.f7.f64 = ctx.f8.f64 * ctx.f13.f64;
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
	// fmul f3,f4,f12
	ctx.f3.f64 = ctx.f4.f64 * ctx.f12.f64;
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r31,r4,-200
	xer.ca = ctx.r4.u32 <= 4294967096;
	r31.s64 = -200 - ctx.r4.s64;
loc_822A5F90:
	// li r4,19
	ctx.r4.s64 = 19;
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x822A5F9C;
	sub_822051A0(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// subf r31,r3,r31
	r31.s64 = r31.s64 - ctx.r3.s64;
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x822A5FAC;
	sub_822051A0(ctx, base);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_822A5FBC:
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x822A5FC8;
	sub_822051A0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_822A5FD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822A5FDC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822A5FEC;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822A5FF4;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x822a6000
	if (cr6.eq) goto loc_822A6000;
	// li r27,1
	r27.s64 = 1;
loc_822A6000:
	// clrlwi r31,r27,24
	r31.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822a6060
	if (!cr6.eq) goto loc_822A6060;
	// bl 0x82256058
	ctx.lr = 0x822A6010;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6060
	if (cr6.eq) goto loc_822A6060;
	// bl 0x82256058
	ctx.lr = 0x822A601C;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x822a6060
	if (cr0.eq) goto loc_822A6060;
	// bl 0x82256058
	ctx.lr = 0x822A6028;
	sub_82256058(ctx, base);
	// addic. r3,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r3.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x822a6060
	if (cr0.eq) goto loc_822A6060;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82269288
	ctx.lr = 0x822A6038;
	sub_82269288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6060
	if (cr6.eq) goto loc_822A6060;
	// lwz r3,188(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_822A6050:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_822A6060:
	// lwz r3,1220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6080
	if (cr6.eq) goto loc_822A6080;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a6080
	if (cr6.eq) goto loc_822A6080;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x822051a0
	ctx.lr = 0x822A607C;
	sub_822051A0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_822A6080:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A6090"))) PPC_WEAK_FUNC(sub_822A6090);
PPC_FUNC_IMPL(__imp__sub_822A6090) {
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
	ctx.lr = 0x822A6098;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,-1
	r30.s64 = -1;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82387a18
	ctx.lr = 0x822A60B0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6124
	if (cr6.eq) goto loc_822A6124;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a618c
	if (cr6.eq) goto loc_822A618C;
	// bl 0x82203310
	ctx.lr = 0x822A60CC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a618c
	if (cr6.eq) goto loc_822A618C;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a60f4
	if (cr6.eq) goto loc_822A60F4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822A60EC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x822a618c
	if (cr6.eq) goto loc_822A618C;
loc_822A60F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822A60FC;
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
	ctx.lr = 0x822A6110;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822A6118;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822a6124
	if (cr6.eq) goto loc_822A6124;
	// li r28,1
	r28.s64 = 1;
loc_822A6124:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a614c
	if (!cr6.eq) goto loc_822A614C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a614c
	if (!cr6.eq) goto loc_822A614C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8508
	ctx.lr = 0x822A6148;
	sub_822A8508(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_822A614C:
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6180
	if (cr6.eq) goto loc_822A6180;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x822a6180
	if (!cr6.eq) goto loc_822A6180;
	// bl 0x82387a18
	ctx.lr = 0x822A6164;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6180
	if (cr6.eq) goto loc_822A6180;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x822A617C;
	sub_822051A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_822A6180:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822A618C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A6198"))) PPC_WEAK_FUNC(sub_822A6198);
PPC_FUNC_IMPL(__imp__sub_822A6198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,908(r3)
	PPC_STORE_U8(ctx.r3.u32 + 908, ctx.r9.u8);
	// b 0x822a5880
	sub_822A5880(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A61B0"))) PPC_WEAK_FUNC(sub_822A61B0);
PPC_FUNC_IMPL(__imp__sub_822A61B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822A61B8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A61D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a6414
	if (cr6.eq) goto loc_822A6414;
	// lwz r3,48(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6414
	if (cr6.eq) goto loc_822A6414;
	// bl 0x82331d28
	ctx.lr = 0x822A61F0;
	sub_82331D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6414
	if (cr6.eq) goto loc_822A6414;
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// lwz r27,52(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822a6414
	if (cr6.eq) goto loc_822A6414;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f31,20(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 20);
	f31.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r4,r10,23016
	ctx.r4.s64 = ctx.r10.s64 + 23016;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,-12440(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238da28
	ctx.lr = 0x822A6240;
	sub_8238DA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A6254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r7,23008
	ctx.r4.s64 = ctx.r7.s64 + 23008;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,-12440(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238db50
	ctx.lr = 0x822A6274;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,40(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822A6288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r4,23000
	ctx.r4.s64 = ctx.r4.s64 + 23000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,-12440(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238db50
	ctx.lr = 0x822A62A8;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822A62BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82562448
	ctx.lr = 0x822A62C4;
	sub_82562448(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f1,48(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 48);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822a6308
	if (!cr6.gt) goto loc_822A6308;
	// lwz r30,-12440(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,22992
	ctx.r4.s64 = r11.s64 + 22992;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8238db50
	ctx.lr = 0x822A62F4;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A6308;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A6308:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,1224(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1224);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// lfs f0,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822a6408
	if (cr6.lt) goto loc_822A6408;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15108
	ctx.r3.s64 = r11.s64 + -15108;
	// bl 0x821fa230
	ctx.lr = 0x822A632C;
	sub_821FA230(ctx, base);
	// bl 0x821f87e8
	ctx.lr = 0x822A6330;
	sub_821F87E8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f31,-2036(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -2036);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822a63c4
	if (cr6.eq) goto loc_822A63C4;
	// lfs f13,1224(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1224);
	ctx.f13.f64 = double(temp.f32);
	// lwz r29,-12440(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lfs f0,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,22984
	ctx.r4.s64 = r11.s64 + 22984;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r26,0(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x8238db50
	ctx.lr = 0x822A6370;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A6384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// lfs f11,1224(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1224);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,22976
	ctx.r4.s64 = ctx.r9.s64 + 22976;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmuls f1,f10,f31
	ctx.f1.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lwz r29,-12440(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r26,0(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8238db50
	ctx.lr = 0x822A63B0;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,40(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A63C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A63C4:
	// lfs f13,1224(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1224);
	ctx.f13.f64 = double(temp.f32);
	// lwz r31,-12440(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lfs f0,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,22968
	ctx.r4.s64 = r11.s64 + 22968;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// bl 0x8238db50
	ctx.lr = 0x822A63F0;
	sub_8238DB50(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A6404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
loc_822A6408:
	// stfs f0,1224(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 1224, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82562448
	ctx.lr = 0x822A6414;
	sub_82562448(ctx, base);
loc_822A6414:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A6420"))) PPC_WEAK_FUNC(sub_822A6420);
PPC_FUNC_IMPL(__imp__sub_822A6420) {
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
	// bl 0x822a59d8
	ctx.lr = 0x822A6440;
	sub_822A59D8(ctx, base);
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

__attribute__((alias("__imp__sub_822A6460"))) PPC_WEAK_FUNC(sub_822A6460);
PPC_FUNC_IMPL(__imp__sub_822A6460) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82740f18
	ctx.lr = 0x822A6478;
	sub_82740F18(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r9,r11,22868
	ctx.r9.s64 = r11.s64 + 22868;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r31,20
	ctx.r7.s64 = r31.s64 + 20;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r11,r7,8
	r11.s64 = ctx.r7.s64 + 8;
loc_822A64A0:
	// addi r8,r11,-8
	ctx.r8.s64 = r11.s64 + -8;
	// stfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r8.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bge 0x822a64a0
	if (!cr0.lt) goto loc_822A64A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,288(r7)
	PPC_STORE_U32(ctx.r7.u32 + 288, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A64E4"))) PPC_WEAK_FUNC(sub_822A64E4);
PPC_FUNC_IMPL(__imp__sub_822A64E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A64E8"))) PPC_WEAK_FUNC(sub_822A64E8);
PPC_FUNC_IMPL(__imp__sub_822A64E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A64FC"))) PPC_WEAK_FUNC(sub_822A64FC);
PPC_FUNC_IMPL(__imp__sub_822A64FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6500"))) PPC_WEAK_FUNC(sub_822A6500);
PPC_FUNC_IMPL(__imp__sub_822A6500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
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

__attribute__((alias("__imp__sub_822A6514"))) PPC_WEAK_FUNC(sub_822A6514);
PPC_FUNC_IMPL(__imp__sub_822A6514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6518"))) PPC_WEAK_FUNC(sub_822A6518);
PPC_FUNC_IMPL(__imp__sub_822A6518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
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

__attribute__((alias("__imp__sub_822A652C"))) PPC_WEAK_FUNC(sub_822A652C);
PPC_FUNC_IMPL(__imp__sub_822A652C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6530"))) PPC_WEAK_FUNC(sub_822A6530);
PPC_FUNC_IMPL(__imp__sub_822A6530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A6544"))) PPC_WEAK_FUNC(sub_822A6544);
PPC_FUNC_IMPL(__imp__sub_822A6544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6548"))) PPC_WEAK_FUNC(sub_822A6548);
PPC_FUNC_IMPL(__imp__sub_822A6548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A655C"))) PPC_WEAK_FUNC(sub_822A655C);
PPC_FUNC_IMPL(__imp__sub_822A655C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6560"))) PPC_WEAK_FUNC(sub_822A6560);
PPC_FUNC_IMPL(__imp__sub_822A6560) {
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
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r5,904(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 904);
	// bl 0x822b65e8
	ctx.lr = 0x822A6594;
	sub_822B65E8(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x822b6640
	ctx.lr = 0x822A65A8;
	sub_822B6640(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stw r31,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r31.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// bl 0x8238f1f0
	ctx.lr = 0x822A65BC;
	sub_8238F1F0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r30,r31,1036
	r30.s64 = r31.s64 + 1036;
	// addi r4,r10,23156
	ctx.r4.s64 = ctx.r10.s64 + 23156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebb00
	ctx.lr = 0x822A65D0;
	sub_822EBB00(ctx, base);
	// stw r30,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r30,r31,1112
	r30.s64 = r31.s64 + 1112;
	// addi r4,r9,23136
	ctx.r4.s64 = ctx.r9.s64 + 23136;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebb00
	ctx.lr = 0x822A65E8;
	sub_822EBB00(ctx, base);
	// stw r30,1100(r31)
	PPC_STORE_U32(r31.u32 + 1100, r30.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r30,r31,1188
	r30.s64 = r31.s64 + 1188;
	// addi r4,r8,23120
	ctx.r4.s64 = ctx.r8.s64 + 23120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebb00
	ctx.lr = 0x822A6600;
	sub_822EBB00(ctx, base);
	// stw r30,1176(r31)
	PPC_STORE_U32(r31.u32 + 1176, r30.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r3,r31,1140
	ctx.r3.s64 = r31.s64 + 1140;
	// addi r4,r7,23088
	ctx.r4.s64 = ctx.r7.s64 + 23088;
	// bl 0x822eb000
	ctx.lr = 0x822A6614;
	sub_822EB000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x822A6618;
	sub_82387A18(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x822a6630
	if (!cr6.eq) goto loc_822A6630;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x822A6630;
	sub_82130000(ctx, base);
loc_822A6630:
	// li r3,172
	ctx.r3.s64 = 172;
	// bl 0x82130528
	ctx.lr = 0x822A6638;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a664c
	if (cr6.eq) goto loc_822A664C;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x822b9530
	ctx.lr = 0x822A6648;
	sub_822B9530(ctx, base);
	// b 0x822a6650
	goto loc_822A6650;
loc_822A664C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A6650:
	// stw r3,892(r31)
	PPC_STORE_U32(r31.u32 + 892, ctx.r3.u32);
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r5,88(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// bl 0x822a0ea0
	ctx.lr = 0x822A6664;
	sub_822A0EA0(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r7,896(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// stw r7,32(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32, ctx.r7.u32);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r3,44(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// bl 0x82350630
	ctx.lr = 0x822A6690;
	sub_82350630(ctx, base);
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,912(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 912);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// sth r4,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r4.u16);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a66b0
	if (cr6.eq) goto loc_822A66B0;
	// bl 0x822b3b98
	ctx.lr = 0x822A66B0;
	sub_822B3B98(ctx, base);
loc_822A66B0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A66C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,984(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// bl 0x822aebe0
	ctx.lr = 0x822A66D8;
	sub_822AEBE0(ctx, base);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lbz r7,-29347(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + -29347);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822a66f8
	if (!cr6.eq) goto loc_822A66F8;
	// bl 0x8269a1b0
	ctx.lr = 0x822A66EC;
	sub_8269A1B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6724
	if (cr6.eq) goto loc_822A6724;
loc_822A66F8:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822b1490
	ctx.lr = 0x822A6704;
	sub_822B1490(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3d80
	ctx.lr = 0x822A6718;
	sub_822A3D80(ctx, base);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-29340(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -29340);
	// bl 0x8269cdc0
	ctx.lr = 0x822A6724;
	sub_8269CDC0(ctx, base);
loc_822A6724:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,22804
	ctx.r10.s64 = r11.s64 + 22804;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82350570
	ctx.lr = 0x822A6738;
	sub_82350570(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
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

__attribute__((alias("__imp__sub_822A6750"))) PPC_WEAK_FUNC(sub_822A6750);
PPC_FUNC_IMPL(__imp__sub_822A6750) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822A6758;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,980(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 980);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6908
	if (cr6.eq) goto loc_822A6908;
	// addi r30,r31,948
	r30.s64 = r31.s64 + 948;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229b410
	ctx.lr = 0x822A677C;
	sub_8229B410(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lfs f0,8884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r6,31(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 31);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r4,472(r7)
	PPC_STORE_U8(ctx.r7.u32 + 472, ctx.r4.u8);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
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
	// fdivs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 / ctx.f9.f64));
	// stfs f8,468(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 468, temp.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x823316c0
	ctx.lr = 0x822A67E4;
	sub_823316C0(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822A67FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229ae48
	ctx.lr = 0x822A6808;
	sub_8229AE48(ctx, base);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r3,128(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A6828;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r8,33(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 33);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822a6868
	if (!cr6.eq) goto loc_822A6868;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8229ae88
	ctx.lr = 0x822A6848;
	sub_8229AE88(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,172(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 172);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A6868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A6868:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbz r10,976(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 976);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lhz r8,18(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 18);
	// extsh r11,r8
	r11.s64 = ctx.r8.s16;
	// bne cr6,0x822a68c8
	if (!cr6.eq) goto loc_822A68C8;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822a68a8
	if (!cr6.eq) goto loc_822A68A8;
	// li r11,-99
	r11.s64 = -99;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// stb r10,980(r31)
	PPC_STORE_U8(r31.u32 + 980, ctx.r10.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822A68A8:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822a68fc
	if (!cr6.eq) goto loc_822A68FC;
	// li r11,99
	r11.s64 = 99;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// stb r10,980(r31)
	PPC_STORE_U8(r31.u32 + 980, ctx.r10.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822A68C8:
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822a68fc
	if (cr6.eq) goto loc_822A68FC;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x822a68f0
	if (!cr6.eq) goto loc_822A68F0;
	// li r11,-2
	r11.s64 = -2;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// stb r10,980(r31)
	PPC_STORE_U8(r31.u32 + 980, ctx.r10.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
loc_822A68F0:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x822a68fc
	if (!cr6.eq) goto loc_822A68FC;
	// li r11,2
	r11.s64 = 2;
loc_822A68FC:
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// stb r10,980(r31)
	PPC_STORE_U8(r31.u32 + 980, ctx.r10.u8);
loc_822A6908:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A6910"))) PPC_WEAK_FUNC(sub_822A6910);
PPC_FUNC_IMPL(__imp__sub_822A6910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a69d4
	if (!cr6.eq) goto loc_822A69D4;
	// bl 0x822a61b0
	ctx.lr = 0x822A6938;
	sub_822A61B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ac310
	ctx.lr = 0x822A6940;
	sub_822AC310(ctx, base);
	// addi r11,r31,928
	r11.s64 = r31.s64 + 928;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,988
	ctx.r3.s64 = r31.s64 + 988;
	// stb r30,944(r31)
	PPC_STORE_U8(r31.u32 + 944, r30.u8);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822eafb0
	ctx.lr = 0x822A6960;
	sub_822EAFB0(ctx, base);
	// addi r3,r31,1064
	ctx.r3.s64 = r31.s64 + 1064;
	// bl 0x822eafb0
	ctx.lr = 0x822A6968;
	sub_822EAFB0(ctx, base);
	// addi r3,r31,1140
	ctx.r3.s64 = r31.s64 + 1140;
	// bl 0x822eafb0
	ctx.lr = 0x822A6970;
	sub_822EAFB0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,7220(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 7220, temp.u32);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6990
	if (cr6.eq) goto loc_822A6990;
	// bl 0x822b34b0
	ctx.lr = 0x822A6990;
	sub_822B34B0(ctx, base);
loc_822A6990:
	// lwz r3,892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a69ac
	if (cr6.eq) goto loc_822A69AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A69AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A69AC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,908(r31)
	PPC_STORE_U8(r31.u32 + 908, r30.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r30,909(r31)
	PPC_STORE_U8(r31.u32 + 909, r30.u8);
	// stb r30,980(r31)
	PPC_STORE_U8(r31.u32 + 980, r30.u8);
	// stb r10,924(r31)
	PPC_STORE_U8(r31.u32 + 924, ctx.r10.u8);
	// stb r30,888(r31)
	PPC_STORE_U8(r31.u32 + 888, r30.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,884(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 884, temp.u32);
	// b 0x822a69dc
	goto loc_822A69DC;
loc_822A69D4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_822A69DC:
	// stfs f0,872(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
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

__attribute__((alias("__imp__sub_822A69F8"))) PPC_WEAK_FUNC(sub_822A69F8);
PPC_FUNC_IMPL(__imp__sub_822A69F8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a6ad8
	if (!cr6.eq) goto loc_822A6AD8;
	// bl 0x822a61b0
	ctx.lr = 0x822A6A24;
	sub_822A61B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ac168
	ctx.lr = 0x822A6A2C;
	sub_822AC168(ctx, base);
	// addi r11,r31,928
	r11.s64 = r31.s64 + 928;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,988
	ctx.r3.s64 = r31.s64 + 988;
	// stb r30,944(r31)
	PPC_STORE_U8(r31.u32 + 944, r30.u8);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822eafb0
	ctx.lr = 0x822A6A4C;
	sub_822EAFB0(ctx, base);
	// addi r3,r31,1064
	ctx.r3.s64 = r31.s64 + 1064;
	// bl 0x822eafb0
	ctx.lr = 0x822A6A54;
	sub_822EAFB0(ctx, base);
	// addi r3,r31,1140
	ctx.r3.s64 = r31.s64 + 1140;
	// bl 0x822eafb0
	ctx.lr = 0x822A6A5C;
	sub_822EAFB0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,7220(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 7220, temp.u32);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6a7c
	if (cr6.eq) goto loc_822A6A7C;
	// bl 0x822b34b0
	ctx.lr = 0x822A6A7C;
	sub_822B34B0(ctx, base);
loc_822A6A7C:
	// lwz r3,892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6a98
	if (cr6.eq) goto loc_822A6A98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A6A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A6A98:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,908(r31)
	PPC_STORE_U8(r31.u32 + 908, r30.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r30,909(r31)
	PPC_STORE_U8(r31.u32 + 909, r30.u8);
	// stb r30,980(r31)
	PPC_STORE_U8(r31.u32 + 980, r30.u8);
	// stb r30,888(r31)
	PPC_STORE_U8(r31.u32 + 888, r30.u8);
	// stb r10,924(r31)
	PPC_STORE_U8(r31.u32 + 924, ctx.r10.u8);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stfs f31,884(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 884, temp.u32);
	// lwz r30,896(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x82342718
	ctx.lr = 0x822A6ACC;
	sub_82342718(ctx, base);
	// stfs f1,92(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 92, temp.u32);
	// stfs f31,872(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
	// b 0x822a6ae4
	goto loc_822A6AE4;
loc_822A6AD8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,872(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
loc_822A6AE4:
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

__attribute__((alias("__imp__sub_822A6B00"))) PPC_WEAK_FUNC(sub_822A6B00);
PPC_FUNC_IMPL(__imp__sub_822A6B00) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x822A6B24;
	sub_822B62A0(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lfs f0,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,984(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// lwz r11,-10240(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227ca18
	ctx.lr = 0x822A6B44;
	sub_8227CA18(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A6B58"))) PPC_WEAK_FUNC(sub_822A6B58);
PPC_FUNC_IMPL(__imp__sub_822A6B58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,48
	ctx.r10.s64 = 48;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f13,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	f0.f64 = double(temp.f32);
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,920(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 920);
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r10,-31664
	ctx.r9.s64 = ctx.r10.s64 + -31664;
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// addi r10,r8,-31648
	ctx.r10.s64 = ctx.r8.s64 + -31648;
	// addi r8,r4,17392
	ctx.r8.s64 = ctx.r4.s64 + 17392;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,920(r3)
	PPC_STORE_U32(ctx.r3.u32 + 920, r11.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// vcmpeqfp128 v11,v60,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v63,v6
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822a6c3c
	if (!cr6.eq) goto loc_822A6C3C;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// blt cr6,0x822a6c3c
	if (cr6.lt) goto loc_822A6C3C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,920(r3)
	PPC_STORE_U32(ctx.r3.u32 + 920, r11.u32);
	// bl 0x822a61b0
	ctx.lr = 0x822A6C3C;
	sub_822A61B0(ctx, base);
loc_822A6C3C:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f30.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmadds f1,f13,f31,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * f31.f64 + ctx.f12.f64));
	// stfs f1,12(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x822a6c6c
	if (cr6.lt) goto loc_822A6C6C;
	// stfs f31,12(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a6ca4
	goto loc_822A6CA4;
loc_822A6C6C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822a6c8c
	if (cr6.gt) goto loc_822A6C8C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-29924(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a6ca4
	goto loc_822A6CA4;
loc_822A6C8C:
	// bl 0x823dcb30
	ctx.lr = 0x822A6C90;
	sub_823DCB30(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,30288(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_822A6CA4:
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// bge cr6,0x822a6cc0
	if (!cr6.lt) goto loc_822A6CC0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,30284(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30284);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_822A6CC0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A6CDC"))) PPC_WEAK_FUNC(sub_822A6CDC);
PPC_FUNC_IMPL(__imp__sub_822A6CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6CE0"))) PPC_WEAK_FUNC(sub_822A6CE0);
PPC_FUNC_IMPL(__imp__sub_822A6CE0) {
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
	ctx.lr = 0x822A6CE8;
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
	// lwz r30,17268(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822A6D0C;
	sub_821E80F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a6d2c
	if (!cr6.eq) goto loc_822A6D2C;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822A6D2C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822A6D38;
	sub_822A3998(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A6D48"))) PPC_WEAK_FUNC(sub_822A6D48);
PPC_FUNC_IMPL(__imp__sub_822A6D48) {
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
	ctx.lr = 0x822A6D50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822A6D6C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6dd4
	if (cr6.eq) goto loc_822A6DD4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822A6D84;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a6dd4
	if (cr6.eq) goto loc_822A6DD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6dd4
	if (cr6.eq) goto loc_822A6DD4;
	// bl 0x821f7c20
	ctx.lr = 0x822A6DA4;
	sub_821F7C20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a6dd4
	if (cr6.eq) goto loc_822A6DD4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822A6DBC;
	sub_822A3998(ctx, base);
	// lwz r11,896(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 896);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x822A6DCC;
	sub_822A4CE0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822A6DD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A6DE0"))) PPC_WEAK_FUNC(sub_822A6DE0);
PPC_FUNC_IMPL(__imp__sub_822A6DE0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,48(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a6e70
	if (cr6.eq) goto loc_822A6E70;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// lhz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// lhz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bge cr6,0x822a6e70
	if (!cr6.lt) goto loc_822A6E70;
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A6E30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a6e70
	if (cr6.eq) goto loc_822A6E70;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82130000
	ctx.lr = 0x822A6E50;
	sub_82130000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x822A6E54;
	sub_82387A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822a6e70
	if (cr6.eq) goto loc_822A6E70;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227ac98
	ctx.lr = 0x822A6E70;
	sub_8227AC98(ctx, base);
loc_822A6E70:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A6E84"))) PPC_WEAK_FUNC(sub_822A6E84);
PPC_FUNC_IMPL(__imp__sub_822A6E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A6E88"))) PPC_WEAK_FUNC(sub_822A6E88);
PPC_FUNC_IMPL(__imp__sub_822A6E88) {
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
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822A6E90;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x822ab970
	ctx.lr = 0x822A6EB0;
	sub_822AB970(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,23180
	ctx.r10.s64 = r11.s64 + 23180;
	// addi r3,r31,948
	ctx.r3.s64 = r31.s64 + 948;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// stw r30,868(r31)
	PPC_STORE_U32(r31.u32 + 868, r30.u32);
	// bl 0x8229aa70
	ctx.lr = 0x822A6ED0;
	sub_8229AA70(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r31,988
	ctx.r3.s64 = r31.s64 + 988;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,984(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// bl 0x822eaf60
	ctx.lr = 0x822A6EE4;
	sub_822EAF60(ctx, base);
	// addi r3,r31,1036
	ctx.r3.s64 = r31.s64 + 1036;
	// bl 0x822eb198
	ctx.lr = 0x822A6EEC;
	sub_822EB198(ctx, base);
	// addi r3,r31,1064
	ctx.r3.s64 = r31.s64 + 1064;
	// bl 0x822eaf60
	ctx.lr = 0x822A6EF4;
	sub_822EAF60(ctx, base);
	// addi r3,r31,1112
	ctx.r3.s64 = r31.s64 + 1112;
	// bl 0x822eb198
	ctx.lr = 0x822A6EFC;
	sub_822EB198(ctx, base);
	// addi r3,r31,1140
	ctx.r3.s64 = r31.s64 + 1140;
	// bl 0x822eaf60
	ctx.lr = 0x822A6F04;
	sub_822EAF60(ctx, base);
	// addi r3,r31,1188
	ctx.r3.s64 = r31.s64 + 1188;
	// bl 0x822eb198
	ctx.lr = 0x822A6F0C;
	sub_822EB198(ctx, base);
	// stfs f31,1224(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1224, temp.u32);
	// stw r30,1220(r31)
	PPC_STORE_U32(r31.u32 + 1220, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82388580
	ctx.lr = 0x822A6F1C;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822a6f3c
	if (cr6.eq) goto loc_822A6F3C;
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x822a6f3c
	if (cr6.eq) goto loc_822A6F3C;
	// bl 0x822a4a90
	ctx.lr = 0x822A6F34;
	sub_822A4A90(ctx, base);
	// stw r3,912(r31)
	PPC_STORE_U32(r31.u32 + 912, ctx.r3.u32);
	// b 0x822a6f44
	goto loc_822A6F44;
loc_822A6F3C:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,912(r31)
	PPC_STORE_U32(r31.u32 + 912, r11.u32);
loc_822A6F44:
	// li r3,8176
	ctx.r3.s64 = 8176;
	// bl 0x82130528
	ctx.lr = 0x822A6F4C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6f5c
	if (cr6.eq) goto loc_822A6F5C;
	// bl 0x8238f550
	ctx.lr = 0x822A6F58;
	sub_8238F550(ctx, base);
	// b 0x822a6f60
	goto loc_822A6F60;
loc_822A6F5C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822A6F60:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// beq cr6,0x822a6f74
	if (cr6.eq) goto loc_822A6F74;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8238efe0
	ctx.lr = 0x822A6F74;
	sub_8238EFE0(ctx, base);
loc_822A6F74:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r3,r11,20
	ctx.r3.s64 = r11.s64 + 20;
	// bl 0x82398380
	ctx.lr = 0x822A6F84;
	sub_82398380(ctx, base);
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,904(r31)
	PPC_STORE_U32(r31.u32 + 904, r28.u32);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stw r28,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r28.u32);
	// stb r10,924(r31)
	PPC_STORE_U8(r31.u32 + 924, ctx.r10.u8);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r30,900(r31)
	PPC_STORE_U32(r31.u32 + 900, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stb r8,17(r31)
	PPC_STORE_U8(r31.u32 + 17, ctx.r8.u8);
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822A6FB8:
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x822a6fb8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822A6FB8;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x822A6FCC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a6fe8
	if (cr6.eq) goto loc_822A6FE8;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// sth r30,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r30.u16);
	// sth r30,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r30.u16);
	// b 0x822a6fec
	goto loc_822A6FEC;
loc_822A6FE8:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822A6FEC:
	// stw r29,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, r29.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822A6FF8;
	sub_82130588(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// sth r30,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r30.u16);
	// li r7,1
	ctx.r7.s64 = 1;
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,1216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// bl 0x8247ab50
	ctx.lr = 0x822A7034;
	sub_8247AB50(ctx, base);
	// addi r11,r31,928
	r11.s64 = r31.s64 + 928;
	// stb r30,944(r31)
	PPC_STORE_U8(r31.u32 + 944, r30.u8);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// li r3,176
	ctx.r3.s64 = 176;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,916(r31)
	PPC_STORE_U8(r31.u32 + 916, r30.u8);
	// stw r30,880(r31)
	PPC_STORE_U32(r31.u32 + 880, r30.u32);
	// stb r30,980(r31)
	PPC_STORE_U8(r31.u32 + 980, r30.u8);
	// stw r30,920(r31)
	PPC_STORE_U32(r31.u32 + 920, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822A7060;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a707c
	if (cr6.eq) goto loc_822A707C;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822a0d48
	ctx.lr = 0x822A7078;
	sub_822A0D48(ctx, base);
	// b 0x822a7080
	goto loc_822A7080;
loc_822A707C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822A7080:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r3,896(r31)
	PPC_STORE_U32(r31.u32 + 896, ctx.r3.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stfs f31,872(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
	// stw r30,892(r31)
	PPC_STORE_U32(r31.u32 + 892, r30.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r3,316
	ctx.r3.s64 = 316;
	// lfs f0,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	f0.f64 = double(temp.f32);
	// lfs f13,-5856(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,-5860(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5860);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f13,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f11,876(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 876, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822A70C4;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822a70f0
	if (cr6.eq) goto loc_822A70F0;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x822a6460
	ctx.lr = 0x822A70D8;
	sub_822A6460(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,312(r29)
	PPC_STORE_U32(r29.u32 + 312, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r10,r11,23028
	ctx.r10.s64 = r11.s64 + 23028;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x822a70f4
	goto loc_822A70F4;
loc_822A70F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822A70F4:
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7108;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,312(r9)
	PPC_STORE_U32(ctx.r9.u32 + 312, r31.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822A7120"))) PPC_WEAK_FUNC(sub_822A7120);
PPC_FUNC_IMPL(__imp__sub_822A7120) {
	PPC_FUNC_PROLOGUE();
	// b 0x822a8108
	sub_822A8108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A7124"))) PPC_WEAK_FUNC(sub_822A7124);
PPC_FUNC_IMPL(__imp__sub_822A7124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7128"))) PPC_WEAK_FUNC(sub_822A7128);
PPC_FUNC_IMPL(__imp__sub_822A7128) {
	PPC_FUNC_PROLOGUE();
	// stw r4,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7130"))) PPC_WEAK_FUNC(sub_822A7130);
PPC_FUNC_IMPL(__imp__sub_822A7130) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,132(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7138"))) PPC_WEAK_FUNC(sub_822A7138);
PPC_FUNC_IMPL(__imp__sub_822A7138) {
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
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a723c
	if (!cr6.eq) goto loc_822A723C;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a71bc
	if (cr6.eq) goto loc_822A71BC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r4,892(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A717C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A7190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r6,892(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,48(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// lwz r3,892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// stw r3,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, ctx.r3.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,892(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// b 0x822a7200
	goto loc_822A7200;
loc_822A71BC:
	// lwz r11,896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// stb r4,100(r11)
	PPC_STORE_U8(r11.u32 + 100, ctx.r4.u8);
	// lwz r3,896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822A71D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r7,896(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r5,48(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// stw r4,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r4.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
loc_822A7200:
	// bl 0x82350630
	ctx.lr = 0x822A7204;
	sub_82350630(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x822A7208;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a723c
	if (cr6.eq) goto loc_822A723C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7228;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a723c
	if (!cr6.eq) goto loc_822A723C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6750
	ctx.lr = 0x822A723C;
	sub_822A6750(ctx, base);
loc_822A723C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A7250"))) PPC_WEAK_FUNC(sub_822A7250);
PPC_FUNC_IMPL(__imp__sub_822A7250) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 904);
	// bl 0x82388598
	ctx.lr = 0x822A7270;
	sub_82388598(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822a7298
	if (cr6.lt) goto loc_822A7298;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a56c8
	ctx.lr = 0x822A7298;
	sub_822A56C8(ctx, base);
loc_822A7298:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a72a8
	if (cr6.eq) goto loc_822A72A8;
	// bl 0x822b58f0
	ctx.lr = 0x822A72A8;
	sub_822B58F0(ctx, base);
loc_822A72A8:
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a732c
	if (!cr6.eq) goto loc_822A732C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a72f8
	if (cr6.eq) goto loc_822A72F8;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822a72f8
	if (cr6.lt) goto loc_822A72F8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a93a8
	ctx.lr = 0x822A72D4;
	sub_822A93A8(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822A72F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// bl 0x822a0640
	ctx.lr = 0x822A72F8;
	sub_822A0640(ctx, base);
loc_822A72F8:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a731c
	if (cr6.eq) goto loc_822A731C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,240
	ctx.r4.s64 = r11.s64 + 240;
	// bl 0x822a6b58
	ctx.lr = 0x822A7318;
	sub_822A6B58(ctx, base);
	// b 0x822a732c
	goto loc_822A732C;
loc_822A731C:
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822A732C:
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

__attribute__((alias("__imp__sub_822A7344"))) PPC_WEAK_FUNC(sub_822A7344);
PPC_FUNC_IMPL(__imp__sub_822A7344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7348"))) PPC_WEAK_FUNC(sub_822A7348);
PPC_FUNC_IMPL(__imp__sub_822A7348) {
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
	// bl 0x822a6d48
	ctx.lr = 0x822A7368;
	sub_822A6D48(ctx, base);
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

__attribute__((alias("__imp__sub_822A7388"))) PPC_WEAK_FUNC(sub_822A7388);
PPC_FUNC_IMPL(__imp__sub_822A7388) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822A7390;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r29,48(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r31,896(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 896);
	// lwz r26,880(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 880);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A73B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r27,-32111
	r27.s64 = -2104426496;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lbz r7,-29347(r27)
	ctx.r7.u64 = PPC_LOAD_U8(r27.u32 + -29347);
	// rlwinm r28,r8,27,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822a7400
	if (cr6.eq) goto loc_822A7400;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A73E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a7400
	if (cr6.eq) goto loc_822A7400;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x826a8cd0
	ctx.lr = 0x822A7400;
	sub_826A8CD0(ctx, base);
loc_822A7400:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r28,r28,24
	r28.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// beq cr6,0x822a7420
	if (cr6.eq) goto loc_822A7420;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x8255f408
	ctx.lr = 0x822A7420;
	sub_8255F408(ctx, base);
loc_822A7420:
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// li r31,0
	r31.s64 = 0;
	// stb r31,1672(r11)
	PPC_STORE_U8(r11.u32 + 1672, r31.u8);
	// stb r31,1768(r11)
	PPC_STORE_U8(r11.u32 + 1768, r31.u8);
	// stb r31,1816(r11)
	PPC_STORE_U8(r11.u32 + 1816, r31.u8);
	// stb r31,1864(r11)
	PPC_STORE_U8(r11.u32 + 1864, r31.u8);
	// stb r31,1912(r11)
	PPC_STORE_U8(r11.u32 + 1912, r31.u8);
	// stb r31,1720(r11)
	PPC_STORE_U8(r11.u32 + 1720, r31.u8);
	// lwz r3,84(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// bl 0x8233e1b0
	ctx.lr = 0x822A745C;
	sub_8233E1B0(ctx, base);
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a746c
	if (cr6.eq) goto loc_822A746C;
	// addi r31,r11,-16
	r31.s64 = r11.s64 + -16;
loc_822A746C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a6de0
	ctx.lr = 0x822A7488;
	sub_822A6DE0(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822a74a4
	if (cr6.eq) goto loc_822A74A4;
	// li r31,10
	r31.s64 = 10;
loc_822A7494:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7e28
	ctx.lr = 0x822A749C;
	sub_822A7E28(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x822a7494
	if (!cr0.eq) goto loc_822A7494;
loc_822A74A4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822a74f4
	if (cr6.eq) goto loc_822A74F4;
	// lbz r11,-29347(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + -29347);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a74f4
	if (!cr6.eq) goto loc_822A74F4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822b34b0
	ctx.lr = 0x822A74C0;
	sub_822B34B0(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822a74f4
	if (cr6.eq) goto loc_822A74F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-13148(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822A74E0;
	sub_82207EF0(ctx, base);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A74F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A74F4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a7534
	if (cr6.eq) goto loc_822A7534;
	// bl 0x82387a18
	ctx.lr = 0x822A7518;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7534
	if (cr6.eq) goto loc_822A7534;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227ac68
	ctx.lr = 0x822A7534;
	sub_8227AC68(ctx, base);
loc_822A7534:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A753C"))) PPC_WEAK_FUNC(sub_822A753C);
PPC_FUNC_IMPL(__imp__sub_822A753C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7540"))) PPC_WEAK_FUNC(sub_822A7540);
PPC_FUNC_IMPL(__imp__sub_822A7540) {
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
	// bl 0x822ac490
	ctx.lr = 0x822A7558;
	sub_822AC490(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6de0
	ctx.lr = 0x822A7560;
	sub_822A6DE0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A7574"))) PPC_WEAK_FUNC(sub_822A7574);
PPC_FUNC_IMPL(__imp__sub_822A7574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7578"))) PPC_WEAK_FUNC(sub_822A7578);
PPC_FUNC_IMPL(__imp__sub_822A7578) {
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
	ctx.lr = 0x822A7580;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,23180
	ctx.r10.s64 = r11.s64 + 23180;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822a7f10
	ctx.lr = 0x822A759C;
	sub_822A7F10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a61b0
	ctx.lr = 0x822A75A4;
	sub_822A61B0(ctx, base);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a75c4
	if (cr6.eq) goto loc_822A75C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A75C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A75C4:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r29,0
	r29.s64 = 0;
	// stw r29,880(r31)
	PPC_STORE_U32(r31.u32 + 880, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a760c
	if (cr6.eq) goto loc_822A760C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A75E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a7608
	if (cr6.eq) goto loc_822A7608;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A7608:
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
loc_822A760C:
	// lwz r3,892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a762c
	if (cr6.eq) goto loc_822A762C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A762C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A762C:
	// lwz r3,896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 896);
	// stw r29,892(r31)
	PPC_STORE_U32(r31.u32 + 892, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a7650
	if (cr6.eq) goto loc_822A7650;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A7650:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stw r29,896(r31)
	PPC_STORE_U32(r31.u32 + 896, r29.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a7664
	if (cr6.eq) goto loc_822A7664;
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
loc_822A7664:
	// lwz r30,1216(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a768c
	if (cr6.eq) goto loc_822A768C;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7684
	if (cr6.eq) goto loc_822A7684;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822A7684;
	sub_82130588(ctx, base);
loc_822A7684:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822A768C;
	sub_82130588(ctx, base);
loc_822A768C:
	// stw r29,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, r29.u32);
	// addi r3,r31,1188
	ctx.r3.s64 = r31.s64 + 1188;
	// bl 0x824e0430
	ctx.lr = 0x822A7698;
	sub_824E0430(ctx, base);
	// addi r3,r31,1112
	ctx.r3.s64 = r31.s64 + 1112;
	// bl 0x824e0430
	ctx.lr = 0x822A76A0;
	sub_824E0430(ctx, base);
	// addi r3,r31,1036
	ctx.r3.s64 = r31.s64 + 1036;
	// bl 0x824e0430
	ctx.lr = 0x822A76A8;
	sub_824E0430(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a9268
	ctx.lr = 0x822A76B0;
	sub_822A9268(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822A76B8"))) PPC_WEAK_FUNC(sub_822A76B8);
PPC_FUNC_IMPL(__imp__sub_822A76B8) {
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
	// bl 0x823d91f8
	ctx.lr = 0x822A76C0;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a9d98
	ctx.lr = 0x822A76D4;
	sub_822A9D98(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A76E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,656(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822a77a4
	if (!cr6.eq) goto loc_822A77A4;
	// bl 0x82387a18
	ctx.lr = 0x822A76F8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7724
	if (cr6.eq) goto loc_822A7724;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a7b10
	if (cr6.eq) goto loc_822A7B10;
loc_822A7724:
	// addi r3,r31,988
	ctx.r3.s64 = r31.s64 + 988;
	// bl 0x822eb3a8
	ctx.lr = 0x822A772C;
	sub_822EB3A8(ctx, base);
	// addi r3,r31,1064
	ctx.r3.s64 = r31.s64 + 1064;
	// bl 0x822eb3a8
	ctx.lr = 0x822A7734;
	sub_822EB3A8(ctx, base);
	// addi r3,r31,1140
	ctx.r3.s64 = r31.s64 + 1140;
	// bl 0x822eb3a8
	ctx.lr = 0x822A773C;
	sub_822EB3A8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f30,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f31,f30
	f31.f64 = f30.f64;
	// beq cr6,0x822a7778
	if (cr6.eq) goto loc_822A7778;
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bl 0x82337a48
	ctx.lr = 0x822A775C;
	sub_82337A48(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822a7778
	if (cr6.eq) goto loc_822A7778;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lfs f31,76(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bgt cr6,0x822a779c
	if (cr6.gt) goto loc_822A779C;
loc_822A7778:
	// lfs f0,1008(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f12,1084(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1084);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,1160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1160);
	ctx.f11.f64 = double(temp.f32);
	// fsel f10,f13,f0,f31
	ctx.f10.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : f31.f64;
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsel f8,f9,f12,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// fsubs f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f11.f64));
	// fsel f31,f7,f11,f8
	f31.f64 = ctx.f7.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
loc_822A779C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f31,7220(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
loc_822A77A4:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a77b4
	if (cr6.eq) goto loc_822A77B4;
	// bl 0x822b4c98
	ctx.lr = 0x822A77B4;
	sub_822B4C98(ctx, base);
loc_822A77B4:
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a77d8
	if (!cr6.eq) goto loc_822A77D8;
	// lwz r3,904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 904);
	// bl 0x82388598
	ctx.lr = 0x822A77C8;
	sub_82388598(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822a77d8
	if (cr6.lt) goto loc_822A77D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a56c8
	ctx.lr = 0x822A77D8;
	sub_822A56C8(ctx, base);
loc_822A77D8:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a77fc
	if (cr6.eq) goto loc_822A77FC;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-6420
	ctx.r10.s64 = r11.s64 + -6420;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a77fc
	if (!cr6.eq) goto loc_822A77FC;
	// bl 0x822b2ab0
	ctx.lr = 0x822A77FC;
	sub_822B2AB0(ctx, base);
loc_822A77FC:
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a7b10
	if (!cr6.eq) goto loc_822A7B10;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822a7854
	if (cr6.eq) goto loc_822A7854;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x822a6b58
	ctx.lr = 0x822A7830;
	sub_822A6B58(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,224(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	f0.f64 = double(temp.f32);
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// bl 0x825585a0
	ctx.lr = 0x822A784C;
	sub_825585A0(ctx, base);
	// stfs f1,592(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// b 0x822a786c
	goto loc_822A786C;
loc_822A7854:
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,588(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// stfs f31,592(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
loc_822A786C:
	// lwz r3,904(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 904);
	// bl 0x82388580
	ctx.lr = 0x822A7874;
	sub_82388580(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x822A7878;
	sub_82387A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// beq cr6,0x822a78d4
	if (cr6.eq) goto loc_822A78D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A78A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a78d4
	if (cr6.eq) goto loc_822A78D4;
	// lfs f0,984(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 984);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822a78d4
	if (!cr6.gt) goto loc_822A78D4;
	// lfs f13,92(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,984(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x822a78d4
	if (cr6.gt) goto loc_822A78D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6b00
	ctx.lr = 0x822A78D4;
	sub_822A6B00(ctx, base);
loc_822A78D4:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a78f0
	if (cr6.eq) goto loc_822A78F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A78F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A78F0:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,23364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 23364);
	f0.f64 = double(temp.f32);
	// lfs f13,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822a7920
	if (!cr6.lt) goto loc_822A7920;
	// lfs f13,872(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,872(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
	// b 0x822a7924
	goto loc_822A7924;
loc_822A7920:
	// stfs f31,872(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
loc_822A7924:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7b04
	if (cr6.eq) goto loc_822A7B04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x822A7934;
	sub_822A8108(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x822A7944;
	sub_8255B9A8(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r8,1216(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// li r11,16
	r11.s64 = 16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v58,r3,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v57,r3,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r7,2384
	ctx.r6.s64 = ctx.r7.s64 + 2384;
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,31308(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lis r28,-32122
	r28.s64 = -2105147392;
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + f0.f64));
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// addi r5,r28,2352
	ctx.r5.s64 = r28.s64 + 2352;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v52,r0,r3
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v48,r0,r7
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v53,r0,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r30,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v39,v52,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v59,r30,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v61,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v51,r30,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v61,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmrghw128 v50,v59,v51
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vmrglw128 v49,v59,v51
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v42,v54,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v47,v48,v63
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v41,v53,v63
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v43,v55,v49
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vor128 v34,v62,v42
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v42.u8)));
	// vmrglw128 v46,v56,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v44,v56,v50
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vor128 v63,v62,v39
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v39.u8)));
	// vor128 v45,v62,v47
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// vmrglw128 v40,v56,v50
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vor128 v32,v62,v41
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v41.u8)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vmrghw128 v38,v56,v50
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v58,v34,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmrglw128 v37,v56,v50
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v36,v45,v46
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32), 0xFF));
	// vmrghw128 v35,v56,v50
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v33,v56,v50
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v61,v45,v43
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmrghw128 v62,v56,v50
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v60,v45,v44
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v59,v34,v40
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// vmsum4fp128 v57,v34,v38
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v38.f32), 0xFF));
	// vmrghw128 v56,v36,v45
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmsum4fp128 v53,v32,v43
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmrghw128 v54,v60,v61
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum4fp128 v50,v63,v43
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmrghw128 v47,v59,v34
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum4fp128 v55,v32,v37
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v37.f32), 0xFF));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// vmsum4fp128 v52,v32,v35
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v35.f32), 0xFF));
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// vmsum4fp128 v51,v63,v33
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v33.f32), 0xFF));
	// vmrghw128 v49,v54,v56
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmsum4fp128 v48,v63,v62
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xFF));
	// li r7,64
	ctx.r7.s64 = 64;
	// li r6,4
	ctx.r6.s64 = 4;
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,14192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v43,r0,r4
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v46,v57,v58
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v45,v55,v32
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v44,v52,v53
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v42,v51,v63
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v40,v48,v50
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v41,v46,v47
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v39,v44,v45
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v38,v40,v42
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// stvx128 v41,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,80(r8)
	PPC_STORE_U32(ctx.r8.u32 + 80, ctx.r6.u32);
	// stfs f0,88(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 88, temp.u32);
	// stb r5,84(r8)
	PPC_STORE_U8(ctx.r8.u32 + 84, ctx.r5.u8);
	// stvx128 v43,r8,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822A7B04:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a93a8
	ctx.lr = 0x822A7B10;
	sub_822A93A8(ctx, base);
loc_822A7B10:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822A7B20"))) PPC_WEAK_FUNC(sub_822A7B20);
PPC_FUNC_IMPL(__imp__sub_822A7B20) {
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
	// lis r11,-32214
	r11.s64 = -2111176704;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,27872
	ctx.r4.s64 = r11.s64 + 27872;
	// addi r3,r10,23484
	ctx.r3.s64 = ctx.r10.s64 + 23484;
	// bl 0x82554798
	ctx.lr = 0x822A7B40;
	sub_82554798(ctx, base);
	// lis r9,-32214
	ctx.r9.s64 = -2111176704;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,27872
	ctx.r4.s64 = ctx.r9.s64 + 27872;
	// addi r3,r8,23460
	ctx.r3.s64 = ctx.r8.s64 + 23460;
	// bl 0x82554798
	ctx.lr = 0x822A7B54;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-12200
	ctx.r4.s64 = ctx.r7.s64 + -12200;
	// addi r3,r6,23444
	ctx.r3.s64 = ctx.r6.s64 + 23444;
	// bl 0x82554798
	ctx.lr = 0x822A7B68;
	sub_82554798(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// addi r3,r3,23416
	ctx.r3.s64 = ctx.r3.s64 + 23416;
	// bl 0x82554798
	ctx.lr = 0x822A7B7C;
	sub_82554798(ctx, base);
	// lis r11,-32214
	r11.s64 = -2111176704;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,29512
	ctx.r4.s64 = r11.s64 + 29512;
	// addi r3,r10,23388
	ctx.r3.s64 = ctx.r10.s64 + 23388;
	// bl 0x82554798
	ctx.lr = 0x822A7B90;
	sub_82554798(ctx, base);
	// lis r9,-32214
	ctx.r9.s64 = -2111176704;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,25632
	ctx.r4.s64 = ctx.r9.s64 + 25632;
	// addi r3,r8,23368
	ctx.r3.s64 = ctx.r8.s64 + 23368;
	// bl 0x82554798
	ctx.lr = 0x822A7BA4;
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

__attribute__((alias("__imp__sub_822A7BB4"))) PPC_WEAK_FUNC(sub_822A7BB4);
PPC_FUNC_IMPL(__imp__sub_822A7BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7BB8"))) PPC_WEAK_FUNC(sub_822A7BB8);
PPC_FUNC_IMPL(__imp__sub_822A7BB8) {
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
	// bl 0x822a7578
	ctx.lr = 0x822A7BD8;
	sub_822A7578(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7bf0
	if (cr6.eq) goto loc_822A7BF0;
	// bl 0x82130588
	ctx.lr = 0x822A7BEC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822A7BF0:
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

__attribute__((alias("__imp__sub_822A7C08"))) PPC_WEAK_FUNC(sub_822A7C08);
PPC_FUNC_IMPL(__imp__sub_822A7C08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x822a7c20
	if (!cr6.lt) goto loc_822A7C20;
	// li r11,0
	r11.s64 = 0;
loc_822A7C20:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7C28"))) PPC_WEAK_FUNC(sub_822A7C28);
PPC_FUNC_IMPL(__imp__sub_822A7C28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,160(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7C54"))) PPC_WEAK_FUNC(sub_822A7C54);
PPC_FUNC_IMPL(__imp__sub_822A7C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7C58"))) PPC_WEAK_FUNC(sub_822A7C58);
PPC_FUNC_IMPL(__imp__sub_822A7C58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,840(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 840);
	// addi r9,r3,840
	ctx.r9.s64 = ctx.r3.s64 + 840;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7c94
	if (cr6.eq) goto loc_822A7C94;
	// addi r10,r9,5
	ctx.r10.s64 = ctx.r9.s64 + 5;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// li r8,5
	ctx.r8.s64 = 5;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_822A7C7C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x822a7c7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822A7C7C;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
loc_822A7C94:
	// lbz r11,850(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 850);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r10,851(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 851);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lbz r9,852(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 852);
	// lbz r8,853(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 853);
	// stb r7,850(r3)
	PPC_STORE_U8(ctx.r3.u32 + 850, ctx.r7.u8);
	// stb r11,854(r3)
	PPC_STORE_U8(ctx.r3.u32 + 854, r11.u8);
	// stb r10,855(r3)
	PPC_STORE_U8(ctx.r3.u32 + 855, ctx.r10.u8);
	// stb r9,856(r3)
	PPC_STORE_U8(ctx.r3.u32 + 856, ctx.r9.u8);
	// stb r8,857(r3)
	PPC_STORE_U8(ctx.r3.u32 + 857, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7CC8"))) PPC_WEAK_FUNC(sub_822A7CC8);
PPC_FUNC_IMPL(__imp__sub_822A7CC8) {
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
	// lwz r31,48(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a7d70
	if (cr6.eq) goto loc_822A7D70;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a7d70
	if (!cr6.eq) goto loc_822A7D70;
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a7d70
	if (!cr6.eq) goto loc_822A7D70;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// bl 0x8238f1e8
	ctx.lr = 0x822A7D10;
	sub_8238F1E8(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// bne cr6,0x822a7d70
	if (!cr6.eq) goto loc_822A7D70;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,-16
	r31.s64 = r11.s64 + -16;
	// bne cr6,0x822a7d30
	if (!cr6.eq) goto loc_822A7D30;
	// li r31,0
	r31.s64 = 0;
loc_822A7D30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82360ea0
	ctx.lr = 0x822A7D38;
	sub_82360EA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7d70
	if (cr6.eq) goto loc_822A7D70;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82360ee8
	ctx.lr = 0x822A7D4C;
	sub_82360EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7d70
	if (cr6.eq) goto loc_822A7D70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8235c4b8
	ctx.lr = 0x822A7D60;
	sub_8235C4B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a7d74
	if (!cr6.eq) goto loc_822A7D74;
loc_822A7D70:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A7D74:
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

__attribute__((alias("__imp__sub_822A7D8C"))) PPC_WEAK_FUNC(sub_822A7D8C);
PPC_FUNC_IMPL(__imp__sub_822A7D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7D90"))) PPC_WEAK_FUNC(sub_822A7D90);
PPC_FUNC_IMPL(__imp__sub_822A7D90) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a7dc8
	if (cr6.eq) goto loc_822A7DC8;
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a7dc8
	if (cr6.eq) goto loc_822A7DC8;
	// bl 0x8238f998
	ctx.lr = 0x822A7DB4;
	sub_8238F998(ctx, base);
	// bl 0x823964a8
	ctx.lr = 0x822A7DB8;
	sub_823964A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a7dcc
	if (!cr6.eq) goto loc_822A7DCC;
loc_822A7DC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A7DCC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7DDC"))) PPC_WEAK_FUNC(sub_822A7DDC);
PPC_FUNC_IMPL(__imp__sub_822A7DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7DE0"))) PPC_WEAK_FUNC(sub_822A7DE0);
PPC_FUNC_IMPL(__imp__sub_822A7DE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A7E04"))) PPC_WEAK_FUNC(sub_822A7E04);
PPC_FUNC_IMPL(__imp__sub_822A7E04) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7E08"))) PPC_WEAK_FUNC(sub_822A7E08);
PPC_FUNC_IMPL(__imp__sub_822A7E08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823320c8
	sub_823320C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A7E24"))) PPC_WEAK_FUNC(sub_822A7E24);
PPC_FUNC_IMPL(__imp__sub_822A7E24) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7E28"))) PPC_WEAK_FUNC(sub_822A7E28);
PPC_FUNC_IMPL(__imp__sub_822A7E28) {
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
	ctx.lr = 0x822A7E30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822a7f08
	if (!cr6.eq) goto loc_822A7F08;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a7f08
	if (cr6.eq) goto loc_822A7F08;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lis r27,-32115
	r27.s64 = -2104688640;
	// lis r26,-32127
	r26.s64 = -2105475072;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lwz r3,-12640(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12640);
	// stw r11,10204(r26)
	PPC_STORE_U32(r26.u32 + 10204, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822A7E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822a7efc
	if (cr6.lt) goto loc_822A7EFC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r28,-32112
	r28.s64 = -2104492032;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
loc_822A7E90:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822a7eb8
	if (!cr6.gt) goto loc_822A7EB8;
	// lwz r3,-12640(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12640);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7EAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x822a7ec0
	goto loc_822A7EC0;
loc_822A7EB8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822A7EC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821bd910
	ctx.lr = 0x822A7EC8;
	sub_821BD910(ctx, base);
	// lwz r3,-2288(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -2288);
	// lfs f1,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822A7EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x822a7e90
	if (!cr0.lt) goto loc_822A7E90;
loc_822A7EFC:
	// lis r11,0
	r11.s64 = 0;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// stw r11,10204(r26)
	PPC_STORE_U32(r26.u32 + 10204, r11.u32);
loc_822A7F08:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822A7F10"))) PPC_WEAK_FUNC(sub_822A7F10);
PPC_FUNC_IMPL(__imp__sub_822A7F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A7F1C"))) PPC_WEAK_FUNC(sub_822A7F1C);
PPC_FUNC_IMPL(__imp__sub_822A7F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A7F20"))) PPC_WEAK_FUNC(sub_822A7F20);
PPC_FUNC_IMPL(__imp__sub_822A7F20) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbz r11,115(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 115);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822a7f4c
	if (cr6.eq) goto loc_822A7F4C;
	// bl 0x82331c70
	ctx.lr = 0x822A7F4C;
	sub_82331C70(ctx, base);
loc_822A7F4C:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822a7f68
	if (!cr6.eq) goto loc_822A7F68;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822A7F68:
	// bl 0x82353700
	ctx.lr = 0x822A7F6C;
	sub_82353700(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822a7f84
	if (!cr6.eq) goto loc_822A7F84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822A7F84:
	// bl 0x823536b8
	ctx.lr = 0x822A7F88;
	sub_823536B8(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x823317a0
	ctx.lr = 0x822A7F90;
	sub_823317A0(ctx, base);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x821a5cc0
	ctx.lr = 0x822A7F98;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a8054
	if (!cr6.eq) goto loc_822A8054;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a7fd8
	if (cr6.eq) goto loc_822A7FD8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A7FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A7FD8:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x822a8008
	if (!cr0.eq) goto loc_822A8008;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A8008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A8008:
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// lis r4,15
	ctx.r4.s64 = 983040;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// ori r4,r4,65535
	ctx.r4.u64 = ctx.r4.u64 | 65535;
	// bl 0x8238ef30
	ctx.lr = 0x822A801C;
	sub_8238EF30(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A8030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a8050
	if (cr6.eq) goto loc_822A8050;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a8050
	if (cr6.eq) goto loc_822A8050;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822b1648
	ctx.lr = 0x822A8050;
	sub_822B1648(ctx, base);
loc_822A8050:
	// stw r30,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r30.u32);
loc_822A8054:
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

__attribute__((alias("__imp__sub_822A806C"))) PPC_WEAK_FUNC(sub_822A806C);
PPC_FUNC_IMPL(__imp__sub_822A806C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8070"))) PPC_WEAK_FUNC(sub_822A8070);
PPC_FUNC_IMPL(__imp__sub_822A8070) {
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
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a80c8
	if (cr6.eq) goto loc_822A80C8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A80A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a80c8
	if (cr6.eq) goto loc_822A80C8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A80C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A80C8:
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822a80f0
	if (cr6.eq) goto loc_822A80F0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A80F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822A80F0:
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

__attribute__((alias("__imp__sub_822A8108"))) PPC_WEAK_FUNC(sub_822A8108);
PPC_FUNC_IMPL(__imp__sub_822A8108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a813c
	if (cr6.eq) goto loc_822A813C;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a8130
	if (cr6.eq) goto loc_822A8130;
	// addi r3,r11,272
	ctx.r3.s64 = r11.s64 + 272;
	// blr 
	return;
loc_822A8130:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
loc_822A813C:
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8144"))) PPC_WEAK_FUNC(sub_822A8144);
PPC_FUNC_IMPL(__imp__sub_822A8144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8148"))) PPC_WEAK_FUNC(sub_822A8148);
PPC_FUNC_IMPL(__imp__sub_822A8148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8164
	if (cr6.eq) goto loc_822A8164;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r3,r11,272
	ctx.r3.s64 = r11.s64 + 272;
	// blr 
	return;
loc_822A8164:
	// addi r3,r3,432
	ctx.r3.s64 = ctx.r3.s64 + 432;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A816C"))) PPC_WEAK_FUNC(sub_822A816C);
PPC_FUNC_IMPL(__imp__sub_822A816C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8170"))) PPC_WEAK_FUNC(sub_822A8170);
PPC_FUNC_IMPL(__imp__sub_822A8170) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a81c0
	if (cr6.eq) goto loc_822A81C0;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a81b4
	if (cr6.eq) goto loc_822A81B4;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822a81c4
	goto loc_822A81C4;
loc_822A81B4:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// b 0x822a81c4
	goto loc_822A81C4;
loc_822A81C0:
	// addi r11,r4,288
	r11.s64 = ctx.r4.s64 + 288;
loc_822A81C4:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f13,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r9,r3,-31664
	ctx.r9.s64 = ctx.r3.s64 + -31664;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,48
	ctx.r7.s64 = 48;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// vcmpeqfp128 v11,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// stvx128 v59,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// vmulfp128 v58,v63,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f30,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f30.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 + f30.f64));
	// fmadds f1,f10,f31,f12
	ctx.f1.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f1,12(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x822a8288
	if (cr6.lt) goto loc_822A8288;
	// stfs f31,12(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a82c0
	goto loc_822A82C0;
loc_822A8288:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822a82a8
	if (cr6.gt) goto loc_822A82A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-29924(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x822a82c0
	goto loc_822A82C0;
loc_822A82A8:
	// bl 0x823dcb30
	ctx.lr = 0x822A82AC;
	sub_823DCB30(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,30288(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_822A82C0:
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bge cr6,0x822a82e0
	if (!cr6.lt) goto loc_822A82E0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,30284(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30284);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_822A82E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A82FC"))) PPC_WEAK_FUNC(sub_822A82FC);
PPC_FUNC_IMPL(__imp__sub_822A82FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8300"))) PPC_WEAK_FUNC(sub_822A8300);
PPC_FUNC_IMPL(__imp__sub_822A8300) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,480(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 480);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8308"))) PPC_WEAK_FUNC(sub_822A8308);
PPC_FUNC_IMPL(__imp__sub_822A8308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,472(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 472);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// lwz r10,476(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 476);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lfs f1,480(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 480);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8320"))) PPC_WEAK_FUNC(sub_822A8320);
PPC_FUNC_IMPL(__imp__sub_822A8320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8338"))) PPC_WEAK_FUNC(sub_822A8338);
PPC_FUNC_IMPL(__imp__sub_822A8338) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8358
	if (cr6.eq) goto loc_822A8358;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8358
	if (cr6.eq) goto loc_822A8358;
	// lwz r3,592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// blr 
	return;
loc_822A8358:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8360"))) PPC_WEAK_FUNC(sub_822A8360);
PPC_FUNC_IMPL(__imp__sub_822A8360) {
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
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8404
	if (cr6.eq) goto loc_822A8404;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8404
	if (cr6.eq) goto loc_822A8404;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x822a83e8
	if (!cr6.eq) goto loc_822A83E8;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822a83e8
	if (!cr6.lt) goto loc_822A83E8;
	// lbz r11,465(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 465);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a83e8
	if (!cr6.eq) goto loc_822A83E8;
	// bl 0x823bbf60
	ctx.lr = 0x822A83B8;
	sub_823BBF60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a83e8
	if (!cr6.eq) goto loc_822A83E8;
	// bl 0x82387a18
	ctx.lr = 0x822A83C8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a83e8
	if (!cr6.eq) goto loc_822A83E8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17708
	ctx.r10.s64 = r11.s64 + 17708;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8404
	if (cr6.eq) goto loc_822A8404;
loc_822A83E8:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8232c788
	ctx.lr = 0x822A83F8;
	sub_8232C788(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,692(r31)
	PPC_STORE_U32(r31.u32 + 692, ctx.r10.u32);
	// b 0x822a8408
	goto loc_822A8408;
loc_822A8404:
	// stw r30,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r30.u32);
loc_822A8408:
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

__attribute__((alias("__imp__sub_822A8420"))) PPC_WEAK_FUNC(sub_822A8420);
PPC_FUNC_IMPL(__imp__sub_822A8420) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a8488
	if (!cr6.eq) goto loc_822A8488;
	// bl 0x82256058
	ctx.lr = 0x822A8444;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8488
	if (cr6.eq) goto loc_822A8488;
	// bl 0x82256058
	ctx.lr = 0x822A8450;
	sub_82256058(ctx, base);
	// addic. r8,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r8.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x822a8488
	if (cr0.eq) goto loc_822A8488;
	// lwz r9,3080(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3080);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822a8488
	if (!cr6.gt) goto loc_822A8488;
	// addi r10,r8,8
	ctx.r10.s64 = ctx.r8.s64 + 8;
loc_822A846C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// beq cr6,0x822a84a0
	if (cr6.eq) goto loc_822A84A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822a846c
	if (cr6.lt) goto loc_822A846C;
loc_822A8488:
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
loc_822A84A0:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r8
	ctx.r10.u64 = r11.u64 + ctx.r8.u64;
	// lwz r3,172(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A84C8"))) PPC_WEAK_FUNC(sub_822A84C8);
PPC_FUNC_IMPL(__imp__sub_822A84C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a84f4
	if (cr6.eq) goto loc_822A84F4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a84f4
	if (cr6.eq) goto loc_822A84F4;
	// lwz r11,592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// lbz r10,689(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 689);
	// stw r11,836(r3)
	PPC_STORE_U32(ctx.r3.u32 + 836, r11.u32);
	// stb r10,832(r3)
	PPC_STORE_U8(ctx.r3.u32 + 832, ctx.r10.u8);
	// blr 
	return;
loc_822A84F4:
	// lbz r11,689(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 689);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,836(r3)
	PPC_STORE_U32(ctx.r3.u32 + 836, ctx.r10.u32);
	// stb r11,832(r3)
	PPC_STORE_U8(ctx.r3.u32 + 832, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8508"))) PPC_WEAK_FUNC(sub_822A8508);
PPC_FUNC_IMPL(__imp__sub_822A8508) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a8594
	if (!cr6.eq) goto loc_822A8594;
	// bl 0x82256058
	ctx.lr = 0x822A852C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8594
	if (cr6.eq) goto loc_822A8594;
	// bl 0x82256058
	ctx.lr = 0x822A8538;
	sub_82256058(ctx, base);
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// li r11,0
	r11.s64 = 0;
	// lwz r9,3080(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3080);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822a8594
	if (!cr6.gt) goto loc_822A8594;
	// addi r10,r8,8
	ctx.r10.s64 = ctx.r8.s64 + 8;
loc_822A8550:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// beq cr6,0x822a8570
	if (cr6.eq) goto loc_822A8570;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822a8550
	if (cr6.lt) goto loc_822A8550;
	// b 0x822a8594
	goto loc_822A8594;
loc_822A8570:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// ori r6,r9,65535
	ctx.r6.u64 = ctx.r9.u64 | 65535;
	// rlwinm r11,r7,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// add r5,r11,r8
	ctx.r5.u64 = r11.u64 + ctx.r8.u64;
	// lwz r3,40(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// cmpw cr6,r3,r6
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, xer);
	// bne cr6,0x822a8598
	if (!cr6.eq) goto loc_822A8598;
loc_822A8594:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_822A8598:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A85AC"))) PPC_WEAK_FUNC(sub_822A85AC);
PPC_FUNC_IMPL(__imp__sub_822A85AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A85B0"))) PPC_WEAK_FUNC(sub_822A85B0);
PPC_FUNC_IMPL(__imp__sub_822A85B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r9,48(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lwz r8,44(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	// stw r11,44(r4)
	PPC_STORE_U32(ctx.r4.u32 + 44, r11.u32);
	// stw r10,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, ctx.r10.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r8,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A85D4"))) PPC_WEAK_FUNC(sub_822A85D4);
PPC_FUNC_IMPL(__imp__sub_822A85D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A85D8"))) PPC_WEAK_FUNC(sub_822A85D8);
PPC_FUNC_IMPL(__imp__sub_822A85D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stb r4,689(r3)
	PPC_STORE_U8(ctx.r3.u32 + 689, ctx.r4.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822a861c
	if (!cr6.eq) goto loc_822A861C;
	// li r11,0
	r11.s64 = 0;
loc_822A861C:
	// stb r4,597(r11)
	PPC_STORE_U8(r11.u32 + 597, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8624"))) PPC_WEAK_FUNC(sub_822A8624);
PPC_FUNC_IMPL(__imp__sub_822A8624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8628"))) PPC_WEAK_FUNC(sub_822A8628);
PPC_FUNC_IMPL(__imp__sub_822A8628) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8664
	if (cr6.eq) goto loc_822A8664;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8664
	if (cr6.eq) goto loc_822A8664;
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// bl 0x8238f998
	ctx.lr = 0x822A8650;
	sub_8238F998(ctx, base);
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822A8664:
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
}

__attribute__((alias("__imp__sub_822A8678"))) PPC_WEAK_FUNC(sub_822A8678);
PPC_FUNC_IMPL(__imp__sub_822A8678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8698
	if (cr6.eq) goto loc_822A8698;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8698
	if (cr6.eq) goto loc_822A8698;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f1,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822A8698:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A86A4"))) PPC_WEAK_FUNC(sub_822A86A4);
PPC_FUNC_IMPL(__imp__sub_822A86A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A86A8"))) PPC_WEAK_FUNC(sub_822A86A8);
PPC_FUNC_IMPL(__imp__sub_822A86A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a86cc
	if (cr6.eq) goto loc_822A86CC;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a86cc
	if (cr6.eq) goto loc_822A86CC;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f1,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822A86CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A86D8"))) PPC_WEAK_FUNC(sub_822A86D8);
PPC_FUNC_IMPL(__imp__sub_822A86D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// b 0x822b6238
	sub_822B6238(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A86E8"))) PPC_WEAK_FUNC(sub_822A86E8);
PPC_FUNC_IMPL(__imp__sub_822A86E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8704
	if (cr6.eq) goto loc_822A8704;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_822A8704:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A870C"))) PPC_WEAK_FUNC(sub_822A870C);
PPC_FUNC_IMPL(__imp__sub_822A870C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8710"))) PPC_WEAK_FUNC(sub_822A8710);
PPC_FUNC_IMPL(__imp__sub_822A8710) {
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
	// beq cr6,0x822a8790
	if (cr6.eq) goto loc_822A8790;
	// bl 0x822a7cc8
	ctx.lr = 0x822A8730;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8790
	if (cr6.eq) goto loc_822A8790;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822a8754
	if (!cr6.eq) goto loc_822A8754;
	// li r11,0
	r11.s64 = 0;
loc_822A8754:
	// lbz r10,604(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 604);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a877c
	if (!cr6.eq) goto loc_822A877C;
	// lbz r10,607(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 607);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822a877c
	if (!cr6.eq) goto loc_822A877C;
	// lbz r11,605(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 605);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822a8780
	if (cr6.eq) goto loc_822A8780;
loc_822A877C:
	// li r11,0
	r11.s64 = 0;
loc_822A8780:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a8794
	if (!cr6.eq) goto loc_822A8794;
loc_822A8790:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A8794:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A87A8"))) PPC_WEAK_FUNC(sub_822A87A8);
PPC_FUNC_IMPL(__imp__sub_822A87A8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a8814
	if (cr6.eq) goto loc_822A8814;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8814
	if (cr6.eq) goto loc_822A8814;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a8814
	if (cr6.eq) goto loc_822A8814;
	// addi r11,r31,224
	r11.s64 = r31.s64 + 224;
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x82558290
	ctx.lr = 0x822A87E8;
	sub_82558290(ctx, base);
	// lfs f2,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x822A87F4;
	sub_823DCDD8(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// stfs f13,180(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// stfs f0,184(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 184, temp.u32);
loc_822A8814:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A8828"))) PPC_WEAK_FUNC(sub_822A8828);
PPC_FUNC_IMPL(__imp__sub_822A8828) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822a8360
	sub_822A8360(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A8834"))) PPC_WEAK_FUNC(sub_822A8834);
PPC_FUNC_IMPL(__imp__sub_822A8834) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8838"))) PPC_WEAK_FUNC(sub_822A8838);
PPC_FUNC_IMPL(__imp__sub_822A8838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A8850"))) PPC_WEAK_FUNC(sub_822A8850);
PPC_FUNC_IMPL(__imp__sub_822A8850) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8854"))) PPC_WEAK_FUNC(sub_822A8854);
PPC_FUNC_IMPL(__imp__sub_822A8854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8858"))) PPC_WEAK_FUNC(sub_822A8858);
PPC_FUNC_IMPL(__imp__sub_822A8858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822A8870"))) PPC_WEAK_FUNC(sub_822A8870);
PPC_FUNC_IMPL(__imp__sub_822A8870) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8874"))) PPC_WEAK_FUNC(sub_822A8874);
PPC_FUNC_IMPL(__imp__sub_822A8874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8878"))) PPC_WEAK_FUNC(sub_822A8878);
PPC_FUNC_IMPL(__imp__sub_822A8878) {
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
	// beq cr6,0x822a88c4
	if (cr6.eq) goto loc_822A88C4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a88bc
	if (cr6.eq) goto loc_822A88BC;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822a88bc
	if (cr6.eq) goto loc_822A88BC;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8232c788
	ctx.lr = 0x822A88B4;
	sub_8232C788(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// b 0x822a88c0
	goto loc_822A88C0;
loc_822A88BC:
	// li r11,2
	r11.s64 = 2;
loc_822A88C0:
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
loc_822A88C4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822A88D8"))) PPC_WEAK_FUNC(sub_822A88D8);
PPC_FUNC_IMPL(__imp__sub_822A88D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a88f0
	if (cr6.eq) goto loc_822A88F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_822A88F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A88F8"))) PPC_WEAK_FUNC(sub_822A88F8);
PPC_FUNC_IMPL(__imp__sub_822A88F8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822a8970
	if (cr6.eq) goto loc_822A8970;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A8924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822a8954
	if (cr6.eq) goto loc_822A8954;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822A8944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822a8958
	if (!cr6.eq) goto loc_822A8958;
loc_822A8954:
	// li r11,0
	r11.s64 = 0;
loc_822A8958:
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
loc_822A8970:
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

__attribute__((alias("__imp__sub_822A8988"))) PPC_WEAK_FUNC(sub_822A8988);
PPC_FUNC_IMPL(__imp__sub_822A8988) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8a3c
	if (cr6.eq) goto loc_822A8A3C;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8a3c
	if (cr6.eq) goto loc_822A8A3C;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a89c4
	if (cr6.eq) goto loc_822A89C4;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822a89cc
	goto loc_822A89CC;
loc_822A89C4:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822A89CC:
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821b9c70
	ctx.lr = 0x822A8A10;
	sub_821B9C70(ctx, base);
	// lfs f2,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x822A8A1C;
	sub_823DCDD8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f0,30288(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822A8A3C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8A54"))) PPC_WEAK_FUNC(sub_822A8A54);
PPC_FUNC_IMPL(__imp__sub_822A8A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8A58"))) PPC_WEAK_FUNC(sub_822A8A58);
PPC_FUNC_IMPL(__imp__sub_822A8A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8a78
	if (cr6.eq) goto loc_822A8A78;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8a78
	if (cr6.eq) goto loc_822A8A78;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f1,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822A8A78:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8A84"))) PPC_WEAK_FUNC(sub_822A8A84);
PPC_FUNC_IMPL(__imp__sub_822A8A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8A88"))) PPC_WEAK_FUNC(sub_822A8A88);
PPC_FUNC_IMPL(__imp__sub_822A8A88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8ac0
	if (cr6.eq) goto loc_822A8AC0;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822a8ac0
	if (cr6.eq) goto loc_822A8AC0;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_822A8AC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8AC8"))) PPC_WEAK_FUNC(sub_822A8AC8);
PPC_FUNC_IMPL(__imp__sub_822A8AC8) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8b38
	if (cr6.eq) goto loc_822A8B38;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8b38
	if (cr6.eq) goto loc_822A8B38;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r31,20(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f31,f12,f0,f13
	f31.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x822a8b24
	if (!cr6.lt) goto loc_822A8B24;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8232d8a8
	ctx.lr = 0x822A8B24;
	sub_8232D8A8(ctx, base);
loc_822A8B24:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
loc_822A8B38:
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

__attribute__((alias("__imp__sub_822A8B50"))) PPC_WEAK_FUNC(sub_822A8B50);
PPC_FUNC_IMPL(__imp__sub_822A8B50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8c10
	if (cr6.eq) goto loc_822A8C10;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822a8c10
	if (cr6.eq) goto loc_822A8C10;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8b9c
	if (cr6.eq) goto loc_822A8B9C;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a8b8c
	if (cr6.eq) goto loc_822A8B8C;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// b 0x822a8ba0
	goto loc_822A8BA0;
loc_822A8B8C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// b 0x822a8ba0
	goto loc_822A8BA0;
loc_822A8B9C:
	// addi r10,r4,288
	ctx.r10.s64 = ctx.r4.s64 + 288;
loc_822A8BA0:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8bd4
	if (cr6.eq) goto loc_822A8BD4;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822a8bc8
	if (cr6.eq) goto loc_822A8BC8;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822a8bd8
	goto loc_822A8BD8;
loc_822A8BC8:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// b 0x822a8bd8
	goto loc_822A8BD8;
loc_822A8BD4:
	// addi r11,r3,288
	r11.s64 = ctx.r3.s64 + 288;
loc_822A8BD8:
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,56(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// blr 
	return;
loc_822A8C10:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,-6432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6432);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8C1C"))) PPC_WEAK_FUNC(sub_822A8C1C);
PPC_FUNC_IMPL(__imp__sub_822A8C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8C20"))) PPC_WEAK_FUNC(sub_822A8C20);
PPC_FUNC_IMPL(__imp__sub_822A8C20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8cf8
	if (cr6.eq) goto loc_822A8CF8;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822a8cf8
	if (cr6.eq) goto loc_822A8CF8;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8c70
	if (cr6.eq) goto loc_822A8C70;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a8c64
	if (cr6.eq) goto loc_822A8C64;
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x822a8c74
	goto loc_822A8C74;
loc_822A8C64:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// b 0x822a8c74
	goto loc_822A8C74;
loc_822A8C70:
	// addi r10,r4,288
	ctx.r10.s64 = ctx.r4.s64 + 288;
loc_822A8C74:
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822a8cb8
	if (cr6.eq) goto loc_822A8CB8;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822a8cac
	if (cr6.eq) goto loc_822A8CAC;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822a8cbc
	goto loc_822A8CBC;
loc_822A8CAC:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// b 0x822a8cbc
	goto loc_822A8CBC;
loc_822A8CB8:
	// addi r11,r3,288
	r11.s64 = ctx.r3.s64 + 288;
loc_822A8CBC:
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x822A8CD8;
	sub_823DCDD8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,30288(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822A8CF8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,-29924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8D10"))) PPC_WEAK_FUNC(sub_822A8D10);
PPC_FUNC_IMPL(__imp__sub_822A8D10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8d88
	if (cr6.eq) goto loc_822A8D88;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8d4c
	if (cr6.eq) goto loc_822A8D4C;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822a8d40
	if (cr6.eq) goto loc_822A8D40;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822a8d50
	goto loc_822A8D50;
loc_822A8D40:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// b 0x822a8d50
	goto loc_822A8D50;
loc_822A8D4C:
	// addi r11,r3,288
	r11.s64 = ctx.r3.s64 + 288;
loc_822A8D50:
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// blr 
	return;
loc_822A8D88:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,-6432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6432);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8D94"))) PPC_WEAK_FUNC(sub_822A8D94);
PPC_FUNC_IMPL(__imp__sub_822A8D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8D98"))) PPC_WEAK_FUNC(sub_822A8D98);
PPC_FUNC_IMPL(__imp__sub_822A8D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8dac
	if (cr6.eq) goto loc_822A8DAC;
	// addi r3,r11,8109
	ctx.r3.s64 = r11.s64 + 8109;
	// blr 
	return;
loc_822A8DAC:
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,8109
	ctx.r3.s64 = r11.s64 + 8109;
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8DC4"))) PPC_WEAK_FUNC(sub_822A8DC4);
PPC_FUNC_IMPL(__imp__sub_822A8DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8DC8"))) PPC_WEAK_FUNC(sub_822A8DC8);
PPC_FUNC_IMPL(__imp__sub_822A8DC8) {
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
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8df8
	if (cr6.eq) goto loc_822A8DF8;
	// bl 0x8238f998
	ctx.lr = 0x822A8DE4;
	sub_8238F998(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822A8DF8:
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

__attribute__((alias("__imp__sub_822A8E0C"))) PPC_WEAK_FUNC(sub_822A8E0C);
PPC_FUNC_IMPL(__imp__sub_822A8E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8E10"))) PPC_WEAK_FUNC(sub_822A8E10);
PPC_FUNC_IMPL(__imp__sub_822A8E10) {
	PPC_FUNC_PROLOGUE();
	// stb r4,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E18"))) PPC_WEAK_FUNC(sub_822A8E18);
PPC_FUNC_IMPL(__imp__sub_822A8E18) {
	PPC_FUNC_PROLOGUE();
	// stb r4,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E20"))) PPC_WEAK_FUNC(sub_822A8E20);
PPC_FUNC_IMPL(__imp__sub_822A8E20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,1
	r11.s64 = 1;
	// stw r11,660(r3)
	PPC_STORE_U32(ctx.r3.u32 + 660, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E34"))) PPC_WEAK_FUNC(sub_822A8E34);
PPC_FUNC_IMPL(__imp__sub_822A8E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8E38"))) PPC_WEAK_FUNC(sub_822A8E38);
PPC_FUNC_IMPL(__imp__sub_822A8E38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,2
	r11.s64 = 2;
	// stw r11,660(r3)
	PPC_STORE_U32(ctx.r3.u32 + 660, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E4C"))) PPC_WEAK_FUNC(sub_822A8E4C);
PPC_FUNC_IMPL(__imp__sub_822A8E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8E50"))) PPC_WEAK_FUNC(sub_822A8E50);
PPC_FUNC_IMPL(__imp__sub_822A8E50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,660(r3)
	PPC_STORE_U32(ctx.r3.u32 + 660, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E64"))) PPC_WEAK_FUNC(sub_822A8E64);
PPC_FUNC_IMPL(__imp__sub_822A8E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8E68"))) PPC_WEAK_FUNC(sub_822A8E68);
PPC_FUNC_IMPL(__imp__sub_822A8E68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8e78
	if (cr6.eq) goto loc_822A8E78;
	// lwz r3,660(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 660);
	// blr 
	return;
loc_822A8E78:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E80"))) PPC_WEAK_FUNC(sub_822A8E80);
PPC_FUNC_IMPL(__imp__sub_822A8E80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// addi r3,r11,20
	ctx.r3.s64 = r11.s64 + 20;
	// b 0x82398380
	sub_82398380(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A8E98"))) PPC_WEAK_FUNC(sub_822A8E98);
PPC_FUNC_IMPL(__imp__sub_822A8E98) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8E9C"))) PPC_WEAK_FUNC(sub_822A8E9C);
PPC_FUNC_IMPL(__imp__sub_822A8E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8EA0"))) PPC_WEAK_FUNC(sub_822A8EA0);
PPC_FUNC_IMPL(__imp__sub_822A8EA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82331858
	sub_82331858(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822A8EB8"))) PPC_WEAK_FUNC(sub_822A8EB8);
PPC_FUNC_IMPL(__imp__sub_822A8EB8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8EBC"))) PPC_WEAK_FUNC(sub_822A8EBC);
PPC_FUNC_IMPL(__imp__sub_822A8EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8EC0"))) PPC_WEAK_FUNC(sub_822A8EC0);
PPC_FUNC_IMPL(__imp__sub_822A8EC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,1955(r11)
	PPC_STORE_U8(r11.u32 + 1955, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8EE4"))) PPC_WEAK_FUNC(sub_822A8EE4);
PPC_FUNC_IMPL(__imp__sub_822A8EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8EE8"))) PPC_WEAK_FUNC(sub_822A8EE8);
PPC_FUNC_IMPL(__imp__sub_822A8EE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,1955(r11)
	PPC_STORE_U8(r11.u32 + 1955, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8F0C"))) PPC_WEAK_FUNC(sub_822A8F0C);
PPC_FUNC_IMPL(__imp__sub_822A8F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8F10"))) PPC_WEAK_FUNC(sub_822A8F10);
PPC_FUNC_IMPL(__imp__sub_822A8F10) {
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
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822a8f48
	if (cr6.eq) goto loc_822A8F48;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822a8f48
	if (cr6.eq) goto loc_822A8F48;
	// bl 0x8234a5d8
	ctx.lr = 0x822A8F38;
	sub_8234A5D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822a8f4c
	if (!cr6.eq) goto loc_822A8F4C;
loc_822A8F48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822A8F4C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8F5C"))) PPC_WEAK_FUNC(sub_822A8F5C);
PPC_FUNC_IMPL(__imp__sub_822A8F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822A8F60"))) PPC_WEAK_FUNC(sub_822A8F60);
PPC_FUNC_IMPL(__imp__sub_822A8F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,684(r3)
	PPC_STORE_U32(ctx.r3.u32 + 684, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822A8F6C"))) PPC_WEAK_FUNC(sub_822A8F6C);
PPC_FUNC_IMPL(__imp__sub_822A8F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

