#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_8218D078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// addi r11,r3,3
	r11.s64 = ctx.r3.s64 + 3;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// clrlwi r10,r5,30
	ctx.r10.u64 = ctx.r5.u32 & 0x3;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r6,2
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 2;
	// rlwinm r11,r6,2,28,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xC;
	// addze r3,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r3.s64 = temp.s64;
	// srawi r9,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 2;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	r11.s64 = temp.s64;
	// mullw r9,r8,r3
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + r11.u64;
	// srawi r9,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 1;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// rlwinm r9,r5,2,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x4;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// clrlwi r5,r6,30
	ctx.r5.u64 = ctx.r6.u32 & 0x3;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lbzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// srw r10,r8,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r30,r10,28
	r30.u64 = ctx.r10.u32 & 0xF;
	// bl 0x8218cda8
	ctx.lr = 0x8218D0F8;
	sub_8218CDA8(ctx, base);
	// rlwinm r9,r30,4,20,27
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFF0;
	// or r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 | r30.u64;
	// stb r8,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r8.u8);
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

PPC_WEAK_FUNC(sub_8218D078) {
	__imp__sub_8218D078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218D11C) {
	__imp__sub_8218D11C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8218D128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,3
	r11.s64 = ctx.r3.s64 + 3;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// clrlwi r9,r5,30
	ctx.r9.u64 = ctx.r5.u32 & 0x3;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r6,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	ctx.r6.s64 = r31.s32 >> 2;
	// rlwinm r11,r31,2,28,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xC;
	// addze r3,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r3.s64 = temp.s64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// srawi r10,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 2;
	// mullw r8,r8,r3
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r6,r11,r6
	ctx.r6.u64 = r11.u64 + ctx.r6.u64;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// rlwinm r10,r3,29,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1F;
	// clrlwi r8,r3,29
	ctx.r8.u64 = ctx.r3.u32 & 0x7;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r5,r31,30
	ctx.r5.u64 = r31.u32 & 0x3;
	// subfic r28,r8,8
	xer.ca = ctx.r8.u32 <= 8;
	r28.s64 = 8 - ctx.r8.s64;
	// lbz r30,0(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lbz r29,1(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// lbz r31,3(r10)
	r31.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// li r6,2
	ctx.r6.s64 = 2;
	// lbz r10,2(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// slw r9,r31,r28
	ctx.r9.u64 = r28.u8 & 0x20 ? 0 : (r31.u32 << (r28.u8 & 0x3F));
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// srw r9,r11,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r8.u8 & 0x3F));
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r31,r8,29
	r31.u64 = ctx.r8.u32 & 0x7;
	// bl 0x8218cda8
	ctx.lr = 0x8218D1C0;
	sub_8218CDA8(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8218d1d8
	if (!cr6.eq) goto loc_8218D1D8;
	// stb r30,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8218D1D8:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8218d1ec
	if (!cr6.eq) goto loc_8218D1EC;
	// stb r29,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8218D1EC:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8218d224
	if (!cr6.gt) goto loc_8218D224;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// subfic r6,r11,8
	xer.ca = r11.u32 <= 8;
	ctx.r6.s64 = 8 - r11.s64;
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r6,r9
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// divw r3,r5,r4
	ctx.r3.s32 = ctx.r5.s32 / ctx.r4.s32;
	// stb r3,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, ctx.r3.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8218D224:
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bge cr6,0x8218d254
	if (!cr6.lt) goto loc_8218D254;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// subfic r6,r11,6
	xer.ca = r11.u32 <= 6;
	ctx.r6.s64 = 6 - r11.s64;
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r6,r9
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// divw r3,r5,r4
	ctx.r3.s32 = ctx.r5.s32 / ctx.r4.s32;
	// stb r3,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, ctx.r3.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8218D254:
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8218d260
	if (cr6.eq) goto loc_8218D260;
	// li r11,255
	r11.s64 = 255;
loc_8218D260:
	// stb r11,3(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8218D120) {
	__imp__sub_8218D120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218D26C) {
	__imp__sub_8218D26C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r24{};
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
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// clrlwi r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,20
	cr6.compare<uint32_t>(ctx.r10.u32, 20, xer);
	// bgt cr6,0x8218d4e0
	if (cr6.gt) goto loc_8218D4E0;
	// lis r12,-32231
	r12.s64 = -2112290816;
	// addi r12,r12,-11604
	r12.s64 = r12.s64 + -11604;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r16,-11520(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11520);
	// lwz r16,-11404(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11404);
	// lwz r16,-11248(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11248);
	// lwz r16,-11180(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11180);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11480(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11480);
	// lwz r16,-11440(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11440);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11520(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11520);
	// lwz r16,-11520(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11520);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11520(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11520);
	// lwz r16,-11040(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11040);
	// lwz r16,-11520(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11520);
	// lwz r16,-11112(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11112);
	// lwz r16,-11520(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -11520);
	// lhz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r11,r9,r5
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lhz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// rotlwi r3,r8,24
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r8.u32, 24);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lhz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// srawi r8,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 2;
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// clrlwi r5,r5,30
	ctx.r5.u64 = ctx.r5.u32 & 0x3;
	// addze r8,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// rlwinm r6,r10,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// mullw r7,r6,r8
	ctx.r7.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// add r3,r7,r4
	ctx.r3.u64 = ctx.r7.u64 + ctx.r4.u64;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rlwinm r7,r3,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lhz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// cmplw cr6,r3,r6
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r6.u32, xer);
	// srawi r3,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// clrlwi r4,r11,30
	ctx.r4.u64 = r11.u32 & 0x3;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// bgt cr6,0x8218d3e0
	if (cr6.gt) goto loc_8218D3E0;
	// li r6,1
	ctx.r6.s64 = 1;
loc_8218D3E0:
	// bl 0x8218cda8
	ctx.lr = 0x8218D3E4;
	sub_8218CDA8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r9,r11,16,8,15
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF0000;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r8,r8,0,16,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFF00FFFF;
	// or r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 | ctx.r8.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lhz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bl 0x8218d078
	ctx.lr = 0x8218D428;
	sub_8218D078(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r9,r11,16,8,15
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF0000;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r8,r8,0,16,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFF00FFFF;
	// or r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 | ctx.r8.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lhz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bl 0x8218d120
	ctx.lr = 0x8218D46C;
	sub_8218D120(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r9,r11,16,8,15
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF0000;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r8,r8,0,16,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFF00FFFF;
	// or r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 | ctx.r8.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
	// lhz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lhzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + r11.u32);
	// rlwinm r7,r8,24,28,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xF;
	// rlwinm r6,r8,28,4,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFF00;
	// rlwinm r5,r8,28,28,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xF;
	// or r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 | ctx.r6.u64;
	// clrlwi r3,r8,28
	ctx.r3.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r11,r4,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r5
	ctx.r10.u64 = r11.u64 | ctx.r5.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 | ctx.r3.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218D4E0:
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

PPC_WEAK_FUNC(sub_8218D270) {
	__imp__sub_8218D270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218D4F4) {
	__imp__sub_8218D4F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D4F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r11,r11,1
	r11.u64 = r11.u32 & 0x7FFFFFFF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,20
	cr6.compare<uint32_t>(r11.u32, 20, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32231
	r12.s64 = -2112290816;
	// addi r12,r12,-10972
	r12.s64 = r12.s64 + -10972;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8218D4F8) {
	__imp__sub_8218D4F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D524) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r16{};
	PPCRegister r24{};
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lwz r16,-10808(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10808);
	// lwz r16,-10600(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10600);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10860(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10860);
	// lwz r16,-10832(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10832);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lwz r16,-10368(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10368);
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lwz r16,-10424(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10424);
	// lwz r16,-10888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -10888);
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D524) {
	__imp__sub_8218D524(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D594) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// rlwinm r9,r6,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stbx r9,r8,r4
	PPC_STORE_U8(ctx.r8.u32 + ctx.r4.u32, ctx.r9.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D594) {
	__imp__sub_8218D594(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stbx r6,r8,r4
	PPC_STORE_U8(ctx.r8.u32 + ctx.r4.u32, ctx.r6.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D5B0) {
	__imp__sub_8218D5B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D5C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// srawi r11,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	r11.s64 = ctx.r5.s32 >> 2;
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// addze r9,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r3,r10,30,2,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// srawi r10,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 2;
	// mullw r11,r3,r9
	r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r11,r5,30
	r11.u64 = ctx.r5.u32 & 0x3;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lis r5,-256
	ctx.r5.s64 = -16777216;
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// rlwinm r9,r4,1,29,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x6;
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// slw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lbz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// andc r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 & ~ctx.r8.u64;
	// stb r3,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r3.u8);
	// bne cr6,0x8218d648
	if (!cr6.eq) goto loc_8218D648;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// slw r9,r7,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stb r8,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r8.u8);
	// blr 
	return;
loc_8218D648:
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// bne cr6,0x8218d668
	if (!cr6.eq) goto loc_8218D668;
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// slw r7,r10,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// stb r6,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r6.u8);
	// blr 
	return;
loc_8218D668:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8218d680
	if (!cr6.eq) goto loc_8218D680;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// or r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// blr 
	return;
loc_8218D680:
	// li r10,2
	ctx.r10.s64 = 2;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// slw r7,r10,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// or r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 | ctx.r8.u64;
	// stb r6,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r6.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D5C8) {
	__imp__sub_8218D5C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D698) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// srawi r11,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	r11.s64 = ctx.r5.s32 >> 2;
	// lhz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// addze r8,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r3,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 2;
	// rlwinm r11,r9,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addze r9,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r9.s64 = temp.s64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r5,r5,30
	ctx.r5.u64 = ctx.r5.u32 & 0x3;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// xori r10,r5,1
	ctx.r10.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r9,r4,30
	ctx.r9.u64 = ctx.r4.u32 & 0x3;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r3,10(r11)
	PPC_STORE_U16(r11.u32 + 10, ctx.r3.u16);
	// clrlwi r3,r6,8
	ctx.r3.u64 = ctx.r6.u32 & 0xFFFFFF;
	// sth r7,8(r11)
	PPC_STORE_U16(r11.u32 + 8, ctx.r7.u16);
	// li r4,3
	ctx.r4.s64 = 3;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// slw r4,r4,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r8.u8 & 0x3F));
	// rlwinm r6,r6,4,28,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xF;
	// lbz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// andc r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 & ~ctx.r4.u64;
	// stb r4,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r4.u8);
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// beq cr6,0x8218d714
	if (cr6.eq) goto loc_8218D714;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8218D714:
	// slw r3,r7,r8
	ctx.r3.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// or r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 | ctx.r4.u64;
	// stb r8,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r8.u8);
	// srawi r10,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 1;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,2,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x4;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// slw r7,r6,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r9.u8 & 0x3F));
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// lbzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stbx r5,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r5.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D698) {
	__imp__sub_8218D698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r6,20,20,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 20) & 0xFE0;
	// lhz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// rlwinm r8,r6,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r6,16,16,22
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFE00;
	// or r3,r11,r8
	ctx.r3.u64 = r11.u64 | ctx.r8.u64;
	// mullw r11,r9,r5
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// rlwinm r9,r3,0,16,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFE;
	// rlwinm r8,r6,31,25,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7F;
	// or r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 | ctx.r7.u64;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r7,3,16,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFF8;
	// or r3,r5,r8
	ctx.r3.u64 = ctx.r5.u64 | ctx.r8.u64;
	// sthx r3,r6,r4
	PPC_STORE_U16(ctx.r6.u32 + ctx.r4.u32, ctx.r3.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D748) {
	__imp__sub_8218D748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218D784) {
	__imp__sub_8218D784(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r3,24704(r11)
	PPC_STORE_U32(r11.u32 + 24704, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D788) {
	__imp__sub_8218D788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218D794) {
	__imp__sub_8218D794(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D798) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8218D7A8:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218d7a8
	if (!cr6.eq) goto loc_8218D7A8;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218D798) {
	__imp__sub_8218D798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218D7BC) {
	__imp__sub_8218D7BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D7C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lhz r11,2(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 2);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f7,f9,f2
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f2.f64));
	// fmuls f8,f10,f1
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fctiwz f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// fctiwz f6,f8
	ctx.f6.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8218d270
	ctx.lr = 0x8218D82C;
	sub_8218D270(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_8218D7C0) {
	__imp__sub_8218D7C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218D848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r24{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8218D850;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r11,-18100
	ctx.r5.s64 = r11.s64 + -18100;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca720
	ctx.lr = 0x8218D870;
	sub_821CA720(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8218d884
	if (!cr6.eq) goto loc_8218D884;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
loc_8218D884:
	// lis r11,8275
	r11.s64 = 542310400;
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r10,r11,17476
	ctx.r10.u64 = r11.u64 | 17476;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be7e8
	ctx.lr = 0x8218D8A0;
	sub_821BE7E8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r9,15
	ctx.r9.s64 = 15;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8218D8B0:
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x8218d8b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218D8B0;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r7,124
	ctx.r7.s64 = 124;
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// lhz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// clrlwi r6,r8,1
	ctx.r6.u64 = ctx.r8.u32 & 0x7FFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lfs f13,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// lfs f11,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// lfs f10,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lfs f9,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f9,164(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// beq cr6,0x8218d950
	if (cr6.eq) goto loc_8218D950;
	// cmpwi cr6,r6,14
	cr6.compare<int32_t>(ctx.r6.s32, 14, xer);
	// beq cr6,0x8218d950
	if (cr6.eq) goto loc_8218D950;
	// cmpwi cr6,r6,16
	cr6.compare<int32_t>(ctx.r6.s32, 16, xer);
	// beq cr6,0x8218d950
	if (cr6.eq) goto loc_8218D950;
	// cmpwi cr6,r6,17
	cr6.compare<int32_t>(ctx.r6.s32, 17, xer);
	// beq cr6,0x8218d950
	if (cr6.eq) goto loc_8218D950;
	// cmpwi cr6,r6,20
	cr6.compare<int32_t>(ctx.r6.s32, 20, xer);
	// beq cr6,0x8218d950
	if (cr6.eq) goto loc_8218D950;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lis r7,8
	ctx.r7.s64 = 524288;
	// mullw r9,r11,r9
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// ori r7,r7,4103
	ctx.r7.u64 = ctx.r7.u64 | 4103;
	// b 0x8218d95c
	goto loc_8218D95C;
loc_8218D950:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r7,4111
	ctx.r7.s64 = 4111;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
loc_8218D95C:
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bne cr6,0x8218d994
	if (!cr6.eq) goto loc_8218D994;
	// oris r7,r7,128
	ctx.r7.u64 = ctx.r7.u64 | 8388608;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8218D97C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218d97c
	if (!cr6.eq) goto loc_8218D97C;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// b 0x8218d998
	goto loc_8218D998;
loc_8218D994:
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
loc_8218D998:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8218d9b8
	if (cr6.eq) goto loc_8218D9B8;
loc_8218D9A8:
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8218d9a8
	if (!cr6.eq) goto loc_8218D9A8;
loc_8218D9B8:
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// ble cr6,0x8218d9d0
	if (!cr6.gt) goto loc_8218D9D0;
	// oris r11,r7,2
	r11.u64 = ctx.r7.u64 | 131072;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
loc_8218D9D0:
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r11,r6,-1
	r11.s64 = ctx.r6.s64 + -1;
	// stw r9,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// cmplwi cr6,r11,21
	cr6.compare<uint32_t>(r11.u32, 21, xer);
	// bgt cr6,0x8218dbbc
	if (cr6.gt) goto loc_8218DBBC;
	// lis r12,-32231
	r12.s64 = -2112290816;
	// addi r12,r12,-9732
	r12.s64 = r12.s64 + -9732;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r16,-9644(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9644);
	// lwz r16,-9600(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9600);
	// lwz r16,-9576(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9576);
	// lwz r16,-9552(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9552);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9384(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9384);
	// lwz r16,-9356(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9356);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9468(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9468);
	// lwz r16,-9528(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9528);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9644(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9644);
	// lwz r16,-9488(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9488);
	// lwz r16,-9448(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9448);
	// lwz r16,-9428(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9428);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9332(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9332);
	// lwz r16,-9284(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9284);
	// lwz r16,-9508(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -9508);
	// lis r11,0
	r11.s64 = 0;
	// stw r9,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// li r10,65
	ctx.r10.s64 = 65;
	// li r6,255
	ctx.r6.s64 = 255;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// stw r6,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// ori r7,r11,65280
	ctx.r7.u64 = r11.u64 | 65280;
	// stw r4,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r4.u32);
	// b 0x8218dbb4
	goto loc_8218DBB4;
	// lis r11,12628
	r11.s64 = 827588608;
	// li r10,4
	ctx.r10.s64 = 4;
	// ori r9,r11,22596
	ctx.r9.u64 = r11.u64 | 22596;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// lis r11,13140
	r11.s64 = 861143040;
	// li r10,4
	ctx.r10.s64 = 4;
	// ori r9,r11,22596
	ctx.r9.u64 = r11.u64 | 22596;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// lis r11,13652
	r11.s64 = 894697472;
	// li r10,4
	ctx.r10.s64 = 4;
	// ori r9,r11,22596
	ctx.r9.u64 = r11.u64 | 22596;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// li r11,4
	r11.s64 = 4;
	// li r10,116
	ctx.r10.s64 = 116;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// li r11,4
	r11.s64 = 4;
	// li r10,115
	ctx.r10.s64 = 115;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// li r11,4
	r11.s64 = 4;
	// li r10,114
	ctx.r10.s64 = 114;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// li r11,4
	r11.s64 = 4;
	// li r10,113
	ctx.r10.s64 = 113;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// li r11,4
	r11.s64 = 4;
	// li r10,112
	ctx.r10.s64 = 112;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// lis r11,0
	r11.s64 = 0;
	// stw r9,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// ori r7,r11,65535
	ctx.r7.u64 = r11.u64 | 65535;
	// stw r10,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r10.u32);
	// lis r6,-1
	ctx.r6.s64 = -65536;
	// stw r9,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r9.u32);
	// stw r7,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r7.u32);
	// stw r6,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r6.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// li r11,2
	r11.s64 = 2;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,255
	ctx.r9.s64 = 255;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// stw r9,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r9.u32);
	// b 0x8218dbbc
	goto loc_8218DBBC;
	// lis r11,2
	r11.s64 = 131072;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,255
	ctx.r9.s64 = 255;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// b 0x8218dbb8
	goto loc_8218DBB8;
	// li r11,65
	r11.s64 = 65;
	// li r10,16
	ctx.r10.s64 = 16;
	// lis r6,-256
	ctx.r6.s64 = -16777216;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// stw r10,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// li r9,3840
	ctx.r9.s64 = 3840;
	// stw r6,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r6.u32);
	// li r7,240
	ctx.r7.s64 = 240;
	// stw r4,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r4.u32);
loc_8218DBB4:
	// stw r7,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
loc_8218DBB8:
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
loc_8218DBBC:
	// li r11,4104
	r11.s64 = 4104;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// ble cr6,0x8218dbd8
	if (!cr6.gt) goto loc_8218DBD8;
	// lis r11,64
	r11.s64 = 4194304;
	// ori r10,r11,4104
	ctx.r10.u64 = r11.u64 | 4104;
	// stw r10,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r10.u32);
loc_8218DBD8:
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bne cr6,0x8218dbec
	if (!cr6.eq) goto loc_8218DBEC;
	// lis r11,32
	r11.s64 = 2097152;
	// stw r11,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r11.u32);
	// b 0x8218dc00
	goto loc_8218DC00;
loc_8218DBEC:
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bne cr6,0x8218dc00
	if (!cr6.eq) goto loc_8218DC00;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,65024
	ctx.r10.u64 = r11.u64 | 65024;
	// stw r10,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
loc_8218DC00:
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be7e8
	ctx.lr = 0x8218DC10;
	sub_821BE7E8(ctx, base);
	// mr r30,r31
	r30.u64 = r31.u64;
loc_8218DC14:
	// mr r31,r30
	r31.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218dcc4
	if (cr6.eq) goto loc_8218DCC4;
loc_8218DC20:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r10,r11,0,12,12
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218dc58
	if (cr6.eq) goto loc_8218DC58;
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// rlwinm r5,r7,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x821be780
	ctx.lr = 0x8218DC54;
	sub_821BE780(ctx, base);
	// b 0x8218dcb8
	goto loc_8218DCB8;
loc_8218DC58:
	// lwz r11,172(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218dc98
	if (!cr6.eq) goto loc_8218DC98;
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// cmplwi cr6,r11,256
	cr6.compare<uint32_t>(r11.u32, 256, xer);
	// blt cr6,0x8218dc98
	if (cr6.lt) goto loc_8218DC98;
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r5,r8,r9
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// bl 0x821be3d8
	ctx.lr = 0x8218DC94;
	sub_821BE3D8(ctx, base);
	// b 0x8218dcb8
	goto loc_8218DCB8;
loc_8218DC98:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r5,r8,r9
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// bl 0x821be7e8
	ctx.lr = 0x8218DCB8;
	sub_821BE7E8(ctx, base);
loc_8218DCB8:
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8218dc20
	if (!cr6.eq) goto loc_8218DC20;
loc_8218DCC4:
	// lwz r30,28(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8218dc14
	if (!cr6.eq) goto loc_8218DC14;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8218DCD8;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8218D848) {
	__imp__sub_8218D848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DCE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218DCE4) {
	__imp__sub_8218DCE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DCE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r11,r11,1
	r11.u64 = r11.u32 & 0x7FFFFFFF;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,21
	cr6.compare<uint32_t>(ctx.r10.u32, 21, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32231
	r12.s64 = -2112290816;
	// addi r12,r12,-8940
	r12.s64 = r12.s64 + -8940;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8218DCE8) {
	__imp__sub_8218DCE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DD14) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r16{};
	PPCRegister r24{};
	// lwz r16,-8852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8852);
	// lwz r16,-8836(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8836);
	// lwz r16,-8768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8768);
	// lwz r16,-8768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8768);
	// lwz r16,-8768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8768);
	// lwz r16,-8768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8768);
	// lwz r16,-8768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8768);
	// lwz r16,-8768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8768);
	// lwz r16,-8656(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8656);
	// lwz r16,-8656(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8656);
	// lwz r16,-8700(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8700);
	// lwz r16,-8684(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8684);
	// lwz r16,-8684(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8684);
	// lwz r16,-8852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8852);
	// lwz r16,-8852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8852);
	// lwz r16,-8852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8852);
	// lwz r16,-8852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8852);
	// lwz r16,-8700(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8700);
	// lwz r16,-8852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8852);
	// lwz r16,-8668(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8668);
	// lwz r16,-8656(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8656);
	// lwz r16,-8700(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + -8700);
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218DD14) {
	__imp__sub_8218DD14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DD7C) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8218dda0
	if (cr6.eq) goto loc_8218DDA0;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8218dda0
	if (cr6.eq) goto loc_8218DDA0;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8218dda0
	if (cr6.eq) goto loc_8218DDA0;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x8218ddac
	if (!cr6.eq) goto loc_8218DDAC;
loc_8218DDA0:
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// li r11,4
	r11.s64 = 4;
	// blt cr6,0x8218ddb0
	if (cr6.lt) goto loc_8218DDB0;
loc_8218DDAC:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8218DDB0:
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218DD7C) {
	__imp__sub_8218DD7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DDC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8218dde4
	if (cr6.eq) goto loc_8218DDE4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8218dde4
	if (cr6.eq) goto loc_8218DDE4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8218dde4
	if (cr6.eq) goto loc_8218DDE4;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x8218ddf8
	if (!cr6.eq) goto loc_8218DDF8;
loc_8218DDE4:
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bge cr6,0x8218ddf8
	if (!cr6.lt) goto loc_8218DDF8;
	// li r11,4
	r11.s64 = 4;
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
loc_8218DDF8:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218DDC0) {
	__imp__sub_8218DDC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DE04) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218DE04) {
	__imp__sub_8218DE04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DE14) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218DE14) {
	__imp__sub_8218DE14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DE24) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// rotlwi r11,r11,1
	r11.u64 = __builtin_rotateleft32(r11.u32, 1);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218DE24) {
	__imp__sub_8218DE24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DE34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218DE34) {
	__imp__sub_8218DE34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218DE38) {
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
	ctx.lr = 0x8218DE40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// clrlwi r29,r28,1
	r29.u64 = r28.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8218e050
	if (cr6.eq) goto loc_8218E050;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8218e050
	if (cr6.eq) goto loc_8218E050;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8218e050
	if (cr6.eq) goto loc_8218E050;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8218dea0
	if (cr6.eq) goto loc_8218DEA0;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// beq cr6,0x8218dea0
	if (cr6.eq) goto loc_8218DEA0;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// beq cr6,0x8218dea0
	if (cr6.eq) goto loc_8218DEA0;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// bne cr6,0x8218deb8
	if (!cr6.eq) goto loc_8218DEB8;
loc_8218DEA0:
	// clrlwi r11,r26,30
	r11.u64 = r26.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218e050
	if (!cr6.eq) goto loc_8218E050;
	// clrlwi r11,r25,30
	r11.u64 = r25.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218e050
	if (!cr6.eq) goto loc_8218E050;
loc_8218DEB8:
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x8218DEC0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r27,0
	r27.s64 = 0;
	// beq cr6,0x8218df28
	if (cr6.eq) goto loc_8218DF28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r27,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r27.u16);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// sth r27,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, r27.u16);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// sth r27,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r27.u16);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r27,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r27.u32);
	// stw r27,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r27.u32);
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r27,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r27.u32);
	// stw r27,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r27.u32);
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f13,64(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f13,72(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// b 0x8218df2c
	goto loc_8218DF2C;
loc_8218DF28:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_8218DF2C:
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// sth r26,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r26.u16);
	// sth r25,2(r31)
	PPC_STORE_U16(r31.u32 + 2, r25.u16);
	// sth r23,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r23.u16);
	// bl 0x8218dce8
	ctx.lr = 0x8218DF48;
	sub_8218DCE8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8218df98
	if (!cr6.eq) goto loc_8218DF98;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8218df70
	if (cr6.eq) goto loc_8218DF70;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// beq cr6,0x8218df70
	if (cr6.eq) goto loc_8218DF70;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// beq cr6,0x8218df70
	if (cr6.eq) goto loc_8218DF70;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// bne cr6,0x8218df7c
	if (!cr6.eq) goto loc_8218DF7C;
loc_8218DF70:
	// cmpwi cr6,r25,4
	cr6.compare<int32_t>(r25.s32, 4, xer);
	// li r11,4
	r11.s64 = 4;
	// blt cr6,0x8218df80
	if (cr6.lt) goto loc_8218DF80;
loc_8218DF7C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8218DF80:
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mullw r3,r9,r23
	ctx.r3.s64 = int64_t(ctx.r9.s32) * int64_t(r23.s32);
	// bl 0x82130528
	ctx.lr = 0x8218DF90;
	sub_82130528(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x8218df9c
	goto loc_8218DF9C;
loc_8218DF98:
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_8218DF9C:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8218dff8
	if (cr6.eq) goto loc_8218DFF8;
	// rlwinm r11,r23,31,1,31
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bgt cr6,0x8218dfb8
	if (cr6.gt) goto loc_8218DFB8;
	// li r5,1
	ctx.r5.s64 = 1;
loc_8218DFB8:
	// rlwinm r11,r25,31,1,31
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x8218dfc8
	if (cr6.gt) goto loc_8218DFC8;
	// li r11,1
	r11.s64 = 1;
loc_8218DFC8:
	// rlwinm r3,r26,31,1,31
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bgt cr6,0x8218dfd8
	if (cr6.gt) goto loc_8218DFD8;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8218DFD8:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r22,-1
	ctx.r8.s64 = r22.s64 + -1;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// bl 0x8218de38
	ctx.lr = 0x8218DFF4;
	sub_8218DE38(ctx, base);
	// b 0x8218dffc
	goto loc_8218DFFC;
loc_8218DFF8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8218DFFC:
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8218e03c
	if (cr6.eq) goto loc_8218E03C;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r21,-1
	ctx.r9.s64 = r21.s64 + -1;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8218de38
	ctx.lr = 0x8218E02C;
	sub_8218DE38(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_8218E03C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_8218E050:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_8218DE38) {
	__imp__sub_8218DE38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218E05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218E05C) {
	__imp__sub_8218E05C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218E060) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// sth r4,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r4.u16);
	// sth r5,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r5.u16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8218e08c
	if (cr6.eq) goto loc_8218E08C;
	// sth r6,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, ctx.r6.u16);
	// blr 
	return;
loc_8218E08C:
	// b 0x8218dce8
	sub_8218DCE8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8218E060) {
	__imp__sub_8218E060(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218E090) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8218E098;
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823db9d8
	ctx.lr = 0x8218E0A0;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-18100
	ctx.r5.s64 = r11.s64 + -18100;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x8218E0C8;
	sub_821CA6A8(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8218ece0
	if (cr6.eq) goto loc_8218ECE0;
	// li r19,0
	r19.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r19,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821be710
	ctx.lr = 0x8218E0E8;
	sub_821BE710(ctx, base);
	// lis r11,8275
	r11.s64 = 542310400;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// ori r10,r11,17476
	ctx.r10.u64 = r11.u64 | 17476;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x8218ecdc
	if (!cr6.eq) goto loc_8218ECDC;
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x821be710
	ctx.lr = 0x8218E10C;
	sub_821BE710(ctx, base);
	// cmplwi cr6,r3,31
	cr6.compare<uint32_t>(ctx.r3.u32, 31, xer);
	// beq cr6,0x8218e130
	if (cr6.eq) goto loc_8218E130;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r11,-17792
	ctx.r3.s64 = r11.s64 + -17792;
	// bl 0x82130000
	ctx.lr = 0x8218E124;
	sub_82130000(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821be610
	ctx.lr = 0x8218E12C;
	sub_821BE610(ctx, base);
	// b 0x8218ecd8
	goto loc_8218ECD8;
loc_8218E130:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,124
	cr6.compare<uint32_t>(r11.u32, 124, xer);
	// bne cr6,0x8218ecd8
	if (!cr6.eq) goto loc_8218ECD8;
	// lwz r11,184(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bne cr6,0x8218ecd8
	if (!cr6.eq) goto loc_8218ECD8;
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r23,136(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218e160
	if (!cr6.eq) goto loc_8218E160;
	// li r23,1
	r23.s64 = 1;
loc_8218E160:
	// lwz r11,220(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// li r29,1
	r29.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// mr r22,r19
	r22.u64 = r19.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218e1b0
	if (cr6.eq) goto loc_8218E1B0;
	// rlwinm r9,r11,17,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0x1;
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// rlwinm r8,r11,19,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r11,20,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r11,21,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r11,r11,22,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// li r22,1
	r22.s64 = 1;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8218e1c4
	goto loc_8218E1C4;
loc_8218E1B0:
	// rlwinm r11,r11,0,10,10
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218e1c4
	if (cr6.eq) goto loc_8218E1C4;
	// lwz r5,132(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r22,3
	r22.s64 = 3;
loc_8218E1C4:
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r20,r19
	r20.u64 = r19.u64;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// bne cr6,0x8218e300
	if (!cr6.eq) goto loc_8218E300;
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,24708(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24708);
	f0.f64 = double(temp.f32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctidz f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// fctidz f6,f8
	ctx.f6.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x8218e2ac
	if (cr6.eq) goto loc_8218E2AC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r7,24700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24700);
	// lwz r8,24696(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24696);
loc_8218E248:
	// srw. r11,r3,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (ctx.r9.u8 & 0x3F));
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// srw r10,r4,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r9.u8 & 0x3F));
	// bne 0x8218e258
	if (!cr0.eq) goto loc_8218E258;
	// li r11,1
	r11.s64 = 1;
loc_8218E258:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218e264
	if (!cr6.eq) goto loc_8218E264;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8218E264:
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8218e29c
	if (cr6.lt) goto loc_8218E29C;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x8218e29c
	if (cr6.lt) goto loc_8218E29C;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bgt cr6,0x8218e294
	if (cr6.gt) goto loc_8218E294;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// bgt cr6,0x8218e294
	if (cr6.gt) goto loc_8218E294;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8218e294
	if (cr6.gt) goto loc_8218E294;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// ble cr6,0x8218e2a0
	if (!cr6.gt) goto loc_8218E2A0;
loc_8218E294:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// b 0x8218e2a0
	goto loc_8218E2A0;
loc_8218E29C:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_8218E2A0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r23
	cr6.compare<uint32_t>(ctx.r9.u32, r23.u32, xer);
	// blt cr6,0x8218e248
	if (cr6.lt) goto loc_8218E248;
loc_8218E2AC:
	// subf. r23,r6,r23
	r23.s64 = r23.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bne 0x8218e2b8
	if (!cr0.eq) goto loc_8218E2B8;
	// li r23,1
	r23.s64 = 1;
loc_8218E2B8:
	// cmplw cr6,r20,r23
	cr6.compare<uint32_t>(r20.u32, r23.u32, xer);
	// blt cr6,0x8218e2c4
	if (cr6.lt) goto loc_8218E2C4;
	// addi r20,r23,-1
	r20.s64 = r23.s64 + -1;
loc_8218E2C4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,24704(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24704);
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// ble cr6,0x8218e2dc
	if (!cr6.gt) goto loc_8218E2DC;
	// mr r23,r11
	r23.u64 = r11.u64;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
loc_8218E2DC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-13524(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -13524);
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// bge cr6,0x8218e300
	if (!cr6.lt) goto loc_8218E300;
	// subf r11,r23,r11
	r11.s64 = r11.s64 - r23.s64;
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bge cr6,0x8218e2fc
	if (!cr6.lt) goto loc_8218E2FC;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_8218E2FC:
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
loc_8218E300:
	// lwz r11,188(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218e864
	if (cr6.eq) goto loc_8218E864;
	// lis r10,12628
	ctx.r10.s64 = 827588608;
	// lwz r11,192(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lis r9,13140
	ctx.r9.s64 = 861143040;
	// ori r10,r10,22596
	ctx.r10.u64 = ctx.r10.u64 | 22596;
	// lis r8,12873
	ctx.r8.s64 = 843644928;
	// ori r9,r9,22596
	ctx.r9.u64 = ctx.r9.u64 | 22596;
	// ori r8,r8,21569
	ctx.r8.u64 = ctx.r8.u64 | 21569;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// lis r7,13652
	ctx.r7.s64 = 894697472;
	// ori r6,r7,22596
	ctx.r6.u64 = ctx.r7.u64 | 22596;
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplwi cr6,r11,116
	cr6.compare<uint32_t>(r11.u32, 116, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplwi cr6,r11,115
	cr6.compare<uint32_t>(r11.u32, 115, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplwi cr6,r11,114
	cr6.compare<uint32_t>(r11.u32, 114, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplwi cr6,r11,113
	cr6.compare<uint32_t>(r11.u32, 113, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplwi cr6,r11,112
	cr6.compare<uint32_t>(r11.u32, 112, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// cmplwi cr6,r11,34
	cr6.compare<uint32_t>(r11.u32, 34, xer);
	// beq cr6,0x8218e3b0
	if (cr6.eq) goto loc_8218E3B0;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lbz r10,192(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 192);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lbz r7,193(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 193);
	// addi r3,r8,-17836
	ctx.r3.s64 = ctx.r8.s64 + -17836;
	// lbz r6,194(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 194);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x82130000
	ctx.lr = 0x8218E3AC;
	sub_82130000(ctx, base);
	// b 0x8218ecd8
	goto loc_8218ECD8;
loc_8218E3B0:
	// li r24,4
	r24.s64 = 4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8218e3c4
	if (!cr6.eq) goto loc_8218E3C4;
	// li r24,2
	r24.s64 = 2;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E3C4:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x8218e3d4
	if (!cr6.eq) goto loc_8218E3D4;
	// li r24,3
	r24.s64 = 3;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E3D4:
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x8218e3e4
	if (!cr6.eq) goto loc_8218E3E4;
	// li r24,5
	r24.s64 = 5;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E3E4:
	// cmplwi cr6,r11,116
	cr6.compare<uint32_t>(r11.u32, 116, xer);
	// bne cr6,0x8218e3f4
	if (!cr6.eq) goto loc_8218E3F4;
	// li r24,12
	r24.s64 = 12;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E3F4:
	// cmplwi cr6,r11,115
	cr6.compare<uint32_t>(r11.u32, 115, xer);
	// bne cr6,0x8218e404
	if (!cr6.eq) goto loc_8218E404;
	// li r24,22
	r24.s64 = 22;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E404:
	// cmplwi cr6,r11,114
	cr6.compare<uint32_t>(r11.u32, 114, xer);
	// bne cr6,0x8218e414
	if (!cr6.eq) goto loc_8218E414;
	// li r24,15
	r24.s64 = 15;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E414:
	// cmplwi cr6,r11,113
	cr6.compare<uint32_t>(r11.u32, 113, xer);
	// bne cr6,0x8218e438
	if (!cr6.eq) goto loc_8218E438;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lbz r10,-13520(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -13520);
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,30
	r11.u64 = ctx.r8.u32 & 0x3;
	// addi r24,r11,11
	r24.s64 = r11.s64 + 11;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E438:
	// cmplwi cr6,r11,112
	cr6.compare<uint32_t>(r11.u32, 112, xer);
	// bne cr6,0x8218e448
	if (!cr6.eq) goto loc_8218E448;
	// li r24,16
	r24.s64 = 16;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E448:
	// cmplwi cr6,r11,34
	cr6.compare<uint32_t>(r11.u32, 34, xer);
	// bne cr6,0x8218e458
	if (!cr6.eq) goto loc_8218E458;
	// li r24,17
	r24.s64 = 17;
	// b 0x8218e464
	goto loc_8218E464;
loc_8218E458:
	// cmplwi cr6,r11,36
	cr6.compare<uint32_t>(r11.u32, 36, xer);
	// bne cr6,0x8218e464
	if (!cr6.eq) goto loc_8218E464;
	// li r24,18
	r24.s64 = 18;
loc_8218E464:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-17840(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17840);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8218e47c
	if (!cr6.eq) goto loc_8218E47C;
	// oris r24,r24,32768
	r24.u64 = r24.u64 | 2147483648;
loc_8218E47C:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r29,-1
	ctx.r9.s64 = r29.s64 + -1;
	// addi r8,r23,-1
	ctx.r8.s64 = r23.s64 + -1;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// bl 0x8218de38
	ctx.lr = 0x8218E494;
	sub_8218DE38(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r27
	r25.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218ec5c
	if (cr6.eq) goto loc_8218EC5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f29,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f29.f64 = double(temp.f32);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfd f28,-32664(r9)
	f28.u64 = PPC_LOAD_U64(ctx.r9.u32 + -32664);
	// lfs f30,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f30.f64 = double(temp.f32);
loc_8218E4C4:
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8218e7e0
	if (cr6.eq) goto loc_8218E7E0;
	// clrlwi r26,r24,1
	r26.u64 = r24.u32 & 0x7FFFFFFF;
loc_8218E4D4:
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x8218e51c
	if (!cr6.eq) goto loc_8218E51C;
	// lfs f13,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bne cr6,0x8218e51c
	if (!cr6.eq) goto loc_8218E51C;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bne cr6,0x8218e51c
	if (!cr6.eq) goto loc_8218E51C;
	// lfs f13,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bne cr6,0x8218e51c
	if (!cr6.eq) goto loc_8218E51C;
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bne cr6,0x8218e51c
	if (!cr6.eq) goto loc_8218E51C;
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// beq cr6,0x8218e548
	if (cr6.eq) goto loc_8218E548;
loc_8218E51C:
	// stfs f0,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 48, temp.u32);
	// lfs f0,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 52, temp.u32);
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 56, temp.u32);
	// lfs f12,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,64(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 64, temp.u32);
	// lfs f11,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,68(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 68, temp.u32);
	// lfs f10,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,72(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r29.u32 + 72, temp.u32);
loc_8218E548:
	// lhz r11,14(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// cmpwi cr6,r26,14
	cr6.compare<int32_t>(r26.s32, 14, xer);
	// bne cr6,0x8218e790
	if (!cr6.eq) goto loc_8218E790;
	// lhz r10,2(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r30,16(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mullw r28,r8,r9
	r28.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
loc_8218E568:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821be6a8
	ctx.lr = 0x8218E578;
	sub_821BE6A8(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x8218e848
	if (!cr6.eq) goto loc_8218E848;
	// lhz r11,92(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 92);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218e598
	if (cr6.eq) goto loc_8218E598;
	// mr r31,r19
	r31.u64 = r19.u64;
	// b 0x8218e5b4
	goto loc_8218E5B4;
loc_8218E598:
	// clrlwi r10,r11,22
	ctx.r10.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r31,r11,-15
	r31.s64 = r11.s64 + -15;
loc_8218E5B4:
	// lhz r11,90(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218e5cc
	if (cr6.eq) goto loc_8218E5CC;
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// b 0x8218e5e8
	goto loc_8218E5E8;
loc_8218E5CC:
	// clrlwi r10,r11,22
	ctx.r10.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r9,r11,-15
	ctx.r9.s64 = r11.s64 + -15;
loc_8218E5E8:
	// lhz r11,88(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218e600
	if (cr6.eq) goto loc_8218E600;
	// mr r11,r19
	r11.u64 = r19.u64;
	// b 0x8218e61c
	goto loc_8218E61C;
loc_8218E600:
	// clrlwi r10,r11,22
	ctx.r10.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r10,r7,1
	ctx.r10.u64 = ctx.r7.u64 ^ 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,-15
	r11.s64 = r11.s64 + -15;
loc_8218E61C:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x8218e628
	if (cr6.gt) goto loc_8218E628;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8218E628:
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// ble cr6,0x8218e634
	if (!cr6.gt) goto loc_8218E634;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8218E634:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// std r11,248(r1)
	PPC_STORE_U64(ctx.r1.u32 + 248, r11.u64);
	// lfd f0,248(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 248);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f2,f13
	ctx.f2.f64 = double(float(ctx.f13.f64));
	// bl 0x823dc480
	ctx.lr = 0x8218E650;
	sub_823DC480(ctx, base);
	// lhz r11,92(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 92);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218e668
	if (!cr6.eq) goto loc_8218E668;
	// fmr f13,f30
	ctx.f13.f64 = f30.f64;
	// b 0x8218e690
	goto loc_8218E690;
loc_8218E668:
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
	// stw r4,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r4.u32);
	// lfs f13,236(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
loc_8218E690:
	// fdivs f0,f31,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 / f0.f64));
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fsel f12,f13,f13,f30
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f10,f11,f31,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fmuls f9,f10,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 * f29.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f8.u64);
	// lbz r11,111(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 111);
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
	// lhz r11,90(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218e6cc
	if (!cr6.eq) goto loc_8218E6CC;
	// fmr f13,f30
	ctx.f13.f64 = f30.f64;
	// b 0x8218e6f4
	goto loc_8218E6F4;
loc_8218E6CC:
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
	// stw r4,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r4.u32);
	// lfs f13,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
loc_8218E6F4:
	// fmuls f13,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fsel f12,f13,f13,f30
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f10,f11,f31,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fmuls f9,f10,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 * f29.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f8.u64);
	// lbz r11,111(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 111);
	// stb r11,1(r30)
	PPC_STORE_U8(r30.u32 + 1, r11.u8);
	// lhz r11,88(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218e72c
	if (!cr6.eq) goto loc_8218E72C;
	// fmr f13,f30
	ctx.f13.f64 = f30.f64;
	// b 0x8218e754
	goto loc_8218E754;
loc_8218E72C:
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_8218E754:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stb r11,3(r30)
	PPC_STORE_U8(r30.u32 + 3, r11.u8);
	// fsel f13,f0,f0,f30
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f11,f12,f31,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// fmuls f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f9.u64);
	// lbz r9,111(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 111);
	// stb r9,2(r30)
	PPC_STORE_U8(r30.u32 + 2, ctx.r9.u8);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8218e568
	if (!cr0.eq) goto loc_8218E568;
	// b 0x8218e7d4
	goto loc_8218E7D4;
loc_8218E790:
	// lhz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lhz r9,2(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// cmpwi cr6,r26,11
	cr6.compare<int32_t>(r26.s32, 11, xer);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// rlwinm r5,r7,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x821be6a8
	ctx.lr = 0x8218E7B4;
	sub_821BE6A8(ctx, base);
	// lhz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// lhz r6,14(r29)
	ctx.r6.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// lhz r4,2(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// mullw r11,r6,r5
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// mullw r10,r11,r4
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r4.s32);
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpw cr6,r3,r9
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, xer);
	// bne cr6,0x8218e848
	if (!cr6.eq) goto loc_8218E848;
loc_8218E7D4:
	// lwz r29,24(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8218e4d4
	if (!cr6.eq) goto loc_8218E4D4;
loc_8218E7E0:
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// bne cr6,0x8218e838
	if (!cr6.eq) goto loc_8218E838;
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// srw r10,r11,r23
	ctx.r10.u64 = r23.u8 & 0x20 ? 0 : (r11.u32 >> (r23.u8 & 0x3F));
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x8218e838
	if (!cr6.eq) goto loc_8218E838;
	// lwz r11,192(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// cmplwi cr6,r11,113
	cr6.compare<uint32_t>(r11.u32, 113, xer);
	// beq cr6,0x8218e838
	if (cr6.eq) goto loc_8218E838;
	// cmplwi cr6,r11,112
	cr6.compare<uint32_t>(r11.u32, 112, xer);
	// beq cr6,0x8218e838
	if (cr6.eq) goto loc_8218E838;
	// lhz r11,12(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 12);
	// lhz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 0);
	// rotlwi r9,r11,5
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 5);
	// twllei r10,0
	// divwu. r31,r9,r10
	r31.u32 = ctx.r9.u32 / ctx.r10.u32;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8218e838
	if (cr0.eq) goto loc_8218E838;
loc_8218E824:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// bl 0x821be4f0
	ctx.lr = 0x8218E830;
	sub_821BE4F0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x8218e824
	if (!cr6.eq) goto loc_8218E824;
loc_8218E838:
	// lwz r25,28(r25)
	r25.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8218e4c4
	if (!cr6.eq) goto loc_8218E4C4;
	// b 0x8218ec5c
	goto loc_8218EC5C;
loc_8218E848:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8218cd10
	ctx.lr = 0x8218E850;
	sub_8218CD10(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x8218E858;
	sub_82130588(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-17868
	ctx.r3.s64 = r11.s64 + -17868;
	// b 0x8218ecd0
	goto loc_8218ECD0;
loc_8218E864:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218ea10
	if (cr6.eq) goto loc_8218EA10;
	// lwz r6,200(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lis r11,255
	r11.s64 = 16711680;
	// lwz r8,208(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// lwz r7,204(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// bne cr6,0x8218e8ac
	if (!cr6.eq) goto loc_8218E8AC;
	// cmplwi cr6,r7,65280
	cr6.compare<uint32_t>(ctx.r7.u32, 65280, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x8218e8ec
	goto loc_8218E8EC;
loc_8218E8AC:
	// cmplwi cr6,r6,65535
	cr6.compare<uint32_t>(ctx.r6.u32, 65535, xer);
	// bne cr6,0x8218e8c8
	if (!cr6.eq) goto loc_8218E8C8;
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// li r6,17
	ctx.r6.s64 = 17;
	// b 0x8218e8ec
	goto loc_8218E8EC;
loc_8218E8C8:
	// cmplwi cr6,r6,3840
	cr6.compare<uint32_t>(ctx.r6.u32, 3840, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// cmplwi cr6,r7,240
	cr6.compare<uint32_t>(ctx.r7.u32, 240, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// cmplwi cr6,r8,15
	cr6.compare<uint32_t>(ctx.r8.u32, 15, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x8218e9f8
	if (!cr6.eq) goto loc_8218E9F8;
	// li r6,20
	ctx.r6.s64 = 20;
loc_8218E8EC:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r29,-1
	ctx.r9.s64 = r29.s64 + -1;
	// addi r8,r23,-1
	ctx.r8.s64 = r23.s64 + -1;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// bl 0x8218de38
	ctx.lr = 0x8218E900;
	sub_8218DE38(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218ec5c
	if (cr6.eq) goto loc_8218EC5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8218E918:
	// mr r31,r30
	r31.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218e9e8
	if (cr6.eq) goto loc_8218E9E8;
loc_8218E924:
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8218e96c
	if (!cr6.eq) goto loc_8218E96C;
	// lfs f13,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218e96c
	if (!cr6.eq) goto loc_8218E96C;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218e96c
	if (!cr6.eq) goto loc_8218E96C;
	// lfs f13,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218e96c
	if (!cr6.eq) goto loc_8218E96C;
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218e96c
	if (!cr6.eq) goto loc_8218E96C;
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// beq cr6,0x8218e998
	if (cr6.eq) goto loc_8218E998;
loc_8218E96C:
	// stfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lfs f0,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lfs f12,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lfs f11,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,68(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// lfs f10,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,72(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_8218E998:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lhz r10,14(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lhz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// rlwinm r5,r7,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// bl 0x821be710
	ctx.lr = 0x8218E9BC;
	sub_821BE710(ctx, base);
	// lhz r6,2(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r5,14(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lhz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// mullw r11,r6,r5
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// mullw r10,r11,r4
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r4.s32);
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmpw cr6,r3,r9
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, xer);
	// bne cr6,0x8218e848
	if (!cr6.eq) goto loc_8218E848;
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8218e924
	if (!cr6.eq) goto loc_8218E924;
loc_8218E9E8:
	// lwz r30,28(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8218e918
	if (!cr6.eq) goto loc_8218E918;
	// b 0x8218ec5c
	goto loc_8218EC5C;
loc_8218E9F8:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r10,-17944
	ctx.r3.s64 = ctx.r10.s64 + -17944;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x82130000
	ctx.lr = 0x8218EA0C;
	sub_82130000(ctx, base);
	// b 0x8218ecd8
	goto loc_8218ECD8;
loc_8218EA10:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218eb44
	if (cr6.eq) goto loc_8218EB44;
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8218eb2c
	if (!cr6.eq) goto loc_8218EB2C;
	// lwz r10,212(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// bne cr6,0x8218eb2c
	if (!cr6.eq) goto loc_8218EB2C;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r29,-1
	ctx.r9.s64 = r29.s64 + -1;
	// addi r8,r23,-1
	ctx.r8.s64 = r23.s64 + -1;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// li r6,6
	ctx.r6.s64 = 6;
	// bl 0x8218de38
	ctx.lr = 0x8218EA4C;
	sub_8218DE38(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218ec5c
	if (cr6.eq) goto loc_8218EC5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8218EA64:
	// mr r31,r30
	r31.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218eb1c
	if (cr6.eq) goto loc_8218EB1C;
loc_8218EA70:
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8218eab8
	if (!cr6.eq) goto loc_8218EAB8;
	// lfs f13,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218eab8
	if (!cr6.eq) goto loc_8218EAB8;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218eab8
	if (!cr6.eq) goto loc_8218EAB8;
	// lfs f13,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218eab8
	if (!cr6.eq) goto loc_8218EAB8;
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218eab8
	if (!cr6.eq) goto loc_8218EAB8;
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// beq cr6,0x8218eae4
	if (cr6.eq) goto loc_8218EAE4;
loc_8218EAB8:
	// stfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lfs f0,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lfs f12,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lfs f11,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,68(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// lfs f10,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,72(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_8218EAE4:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r29,r8,r9
	r29.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x8218EB08;
	sub_821BE250(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// bne cr6,0x8218e848
	if (!cr6.eq) goto loc_8218E848;
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8218ea70
	if (!cr6.eq) goto loc_8218EA70;
loc_8218EB1C:
	// lwz r30,28(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8218ea64
	if (!cr6.eq) goto loc_8218EA64;
	// b 0x8218ec5c
	goto loc_8218EC5C;
loc_8218EB2C:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r10,-17992
	ctx.r3.s64 = ctx.r10.s64 + -17992;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x82130000
	ctx.lr = 0x8218EB40;
	sub_82130000(ctx, base);
	// b 0x8218ecd8
	goto loc_8218ECD8;
loc_8218EB44:
	// rlwinm r11,r11,0,14,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218ecc8
	if (cr6.eq) goto loc_8218ECC8;
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bne cr6,0x8218ecb0
	if (!cr6.eq) goto loc_8218ECB0;
	// lwz r10,200(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// bne cr6,0x8218ecb0
	if (!cr6.eq) goto loc_8218ECB0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r29,-1
	ctx.r9.s64 = r29.s64 + -1;
	// addi r8,r23,-1
	ctx.r8.s64 = r23.s64 + -1;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// li r6,7
	ctx.r6.s64 = 7;
	// bl 0x8218de38
	ctx.lr = 0x8218EB80;
	sub_8218DE38(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218ec5c
	if (cr6.eq) goto loc_8218EC5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8218EB98:
	// mr r31,r30
	r31.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8218ec50
	if (cr6.eq) goto loc_8218EC50;
loc_8218EBA4:
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8218ebec
	if (!cr6.eq) goto loc_8218EBEC;
	// lfs f13,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218ebec
	if (!cr6.eq) goto loc_8218EBEC;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218ebec
	if (!cr6.eq) goto loc_8218EBEC;
	// lfs f13,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218ebec
	if (!cr6.eq) goto loc_8218EBEC;
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bne cr6,0x8218ebec
	if (!cr6.eq) goto loc_8218EBEC;
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// beq cr6,0x8218ec18
	if (cr6.eq) goto loc_8218EC18;
loc_8218EBEC:
	// stfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lfs f0,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lfs f12,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lfs f11,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,68(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// lfs f10,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,72(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_8218EC18:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r29,r8,r9
	r29.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x8218EC3C;
	sub_821BE250(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// bne cr6,0x8218e848
	if (!cr6.eq) goto loc_8218E848;
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8218eba4
	if (!cr6.eq) goto loc_8218EBA4;
loc_8218EC50:
	// lwz r30,28(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8218eb98
	if (!cr6.eq) goto loc_8218EB98;
loc_8218EC5C:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8218ec94
	if (cr6.eq) goto loc_8218EC94;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218ec94
	if (cr6.eq) goto loc_8218EC94;
loc_8218EC6C:
	// lwz r31,24(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// addi r20,r20,-1
	r20.s64 = r20.s64 + -1;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8218ec94
	if (cr6.eq) goto loc_8218EC94;
	// stw r19,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r19.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8217f540
	ctx.lr = 0x8218EC88;
	sub_8217F540(ctx, base);
	// mr r27,r31
	r27.u64 = r31.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x8218ec6c
	if (!cr6.eq) goto loc_8218EC6C;
loc_8218EC94:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821be610
	ctx.lr = 0x8218EC9C;
	sub_821BE610(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823dba24
	ctx.lr = 0x8218ECAC;
	// b 0x823d9220
	return;
loc_8218ECB0:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r10,-18044
	ctx.r3.s64 = ctx.r10.s64 + -18044;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x82130000
	ctx.lr = 0x8218ECC4;
	sub_82130000(ctx, base);
	// b 0x8218ecd8
	goto loc_8218ECD8;
loc_8218ECC8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-18096
	ctx.r3.s64 = r11.s64 + -18096;
loc_8218ECD0:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x82130000
	ctx.lr = 0x8218ECD8;
	sub_82130000(ctx, base);
loc_8218ECD8:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
loc_8218ECDC:
	// bl 0x821be610
	ctx.lr = 0x8218ECE0;
	sub_821BE610(ctx, base);
loc_8218ECE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823dba24
	ctx.lr = 0x8218ECF0;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_8218E090) {
	__imp__sub_8218E090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218ECF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218ECF4) {
	__imp__sub_8218ECF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218ECF8) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// stw r5,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218de38
	ctx.lr = 0x8218ED34;
	sub_8218DE38(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218ed90
	if (!cr6.gt) goto loc_8218ED90;
loc_8218ED44:
	// srawi r9,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 2;
	// li r11,0
	r11.s64 = 0;
	// addze r7,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r7.s64 = temp.s64;
loc_8218ED50:
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// xor r6,r9,r7
	ctx.r6.u64 = ctx.r9.u64 ^ ctx.r7.u64;
	// addi r9,r1,132
	ctx.r9.s64 = ctx.r1.s64 + 132;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x8218ed6c
	if (!cr6.eq) goto loc_8218ED6C;
	// addi r9,r1,124
	ctx.r9.s64 = ctx.r1.s64 + 124;
loc_8218ED6C:
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// blt cr6,0x8218ed50
	if (cr6.lt) goto loc_8218ED50;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r8,r31
	cr6.compare<int32_t>(ctx.r8.s32, r31.s32, xer);
	// blt cr6,0x8218ed44
	if (cr6.lt) goto loc_8218ED44;
loc_8218ED90:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8218ECF8) {
	__imp__sub_8218ECF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218EDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218EDA4) {
	__imp__sub_8218EDA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218EDA8) {
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
	// bl 0x8218e090
	ctx.lr = 0x8218EDC0;
	sub_8218E090(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8218ee20
	if (!cr6.eq) goto loc_8218EE20;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,30516(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30516);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x8218ede4
	if (cr6.lt) goto loc_8218EDE4;
	// lis r11,-32228
	r11.s64 = -2112094208;
	// addi r11,r11,-10728
	r11.s64 = r11.s64 + -10728;
	// b 0x8218edec
	goto loc_8218EDEC;
loc_8218EDE4:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
loc_8218EDEC:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r4,r10,30576
	ctx.r4.s64 = ctx.r10.s64 + 30576;
	// addi r3,r9,-17760
	ctx.r3.s64 = ctx.r9.s64 + -17760;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8218EE08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// ori r5,r5,255
	ctx.r5.u64 = ctx.r5.u64 | 255;
	// ori r4,r4,65280
	ctx.r4.u64 = ctx.r4.u64 | 65280;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8218ecf8
	ctx.lr = 0x8218EE20;
	sub_8218ECF8(ctx, base);
loc_8218EE20:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8218EDA8) {
	__imp__sub_8218EDA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218EE34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218EE34) {
	__imp__sub_8218EE34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218EE38) {
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
	ctx.lr = 0x8218EE40;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r27,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r27.u32);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218ee74
	if (cr6.eq) goto loc_8218EE74;
loc_8218EE64:
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8218ee64
	if (!cr6.eq) goto loc_8218EE64;
loc_8218EE74:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8218ee94
	if (cr6.eq) goto loc_8218EE94;
loc_8218EE84:
	// lwz r10,24(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8218ee84
	if (!cr6.eq) goto loc_8218EE84;
loc_8218EE94:
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lhz r5,14(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// clrlwi r6,r7,1
	ctx.r6.u64 = ctx.r7.u32 & 0x7FFFFFFF;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8218de38
	ctx.lr = 0x8218EEB8;
	sub_8218DE38(ctx, base);
	// lhz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// rotlwi r9,r4,15
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 15);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// ori r5,r10,32768
	ctx.r5.u64 = ctx.r10.u64 | 32768;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// rotlwi r7,r11,15
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 15);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// subf r6,r5,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r5.s64;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rotlwi r11,r6,1
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// rotlwi r9,r4,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r31,r27,-1
	r31.s64 = r27.s64 + -1;
	// addi r30,r28,-1
	r30.s64 = r28.s64 + -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r29,r9,-1
	r29.s64 = ctx.r9.s64 + -1;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// divw r8,r6,r31
	ctx.r8.s32 = ctx.r6.s32 / r31.s32;
	// divw r7,r4,r30
	ctx.r7.s32 = ctx.r4.s32 / r30.s32;
	// andc r6,r31,r11
	ctx.r6.u64 = r31.u64 & ~r11.u64;
	// andc r4,r30,r29
	ctx.r4.u64 = r30.u64 & ~r29.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// twllei r31,0
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// twllei r30,0
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// twlgei r6,-1
	// twlgei r4,-1
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8218f10c
	if (cr6.eq) goto loc_8218F10C;
loc_8218EF48:
	// rlwinm r8,r11,17,15,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0x1FFFF;
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r11,17
	ctx.r4.u64 = r11.u32 & 0x7FFF;
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// add r31,r8,r7
	r31.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// subf r29,r4,r5
	r29.s64 = ctx.r5.s64 - ctx.r4.s64;
	// stw r28,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, r28.u32);
	// add r30,r31,r10
	r30.u64 = r31.u64 + ctx.r10.u64;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218f0f8
	if (cr6.eq) goto loc_8218F0F8;
	// b 0x8218ef88
	goto loc_8218EF88;
loc_8218EF84:
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_8218EF88:
	// clrlwi r3,r7,17
	ctx.r3.u64 = ctx.r7.u32 & 0x7FFF;
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// rlwinm r8,r7,19,13,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 19) & 0x7FFFC;
	// lwz r23,92(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// subf r28,r3,r5
	r28.s64 = ctx.r5.s64 - ctx.r3.s64;
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// mullw r27,r28,r29
	r27.s64 = int64_t(r28.s32) * int64_t(r29.s32);
	// lbzx r22,r8,r30
	r22.u64 = PPC_LOAD_U8(ctx.r8.u32 + r30.u32);
	// lbzx r21,r8,r31
	r21.u64 = PPC_LOAD_U8(ctx.r8.u32 + r31.u32);
	// lbz r18,1(r10)
	r18.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r17,2(r10)
	r17.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r16,3(r10)
	r16.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// lbz r15,5(r10)
	r15.u64 = PPC_LOAD_U8(ctx.r10.u32 + 5);
	// lbz r14,6(r10)
	r14.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// lbz r5,7(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// rlwinm r27,r27,17,15,31
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 17) & 0x1FFFF;
	// lbz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// mullw r28,r28,r4
	r28.s64 = int64_t(r28.s32) * int64_t(ctx.r4.s32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// rlwinm r28,r28,17,15,31
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 17) & 0x1FFFF;
	// add r11,r8,r31
	r11.u64 = ctx.r8.u64 + r31.u64;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// mullw r29,r3,r29
	r29.s64 = int64_t(ctx.r3.s32) * int64_t(r29.s32);
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// lbz r25,6(r11)
	r25.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// lbz r24,2(r11)
	r24.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r20,7(r11)
	r20.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// lbz r19,3(r11)
	r19.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// lbz r26,1(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rlwinm r29,r29,17,15,31
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 17) & 0x1FFFF;
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// mullw r3,r3,r4
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// mullw r10,r8,r29
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r29.s32);
	// rlwinm r8,r3,17,15,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 17) & 0x1FFFF;
	// mullw r11,r26,r27
	r11.s64 = int64_t(r26.s32) * int64_t(r27.s32);
	// lwz r26,100(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// mullw r8,r24,r27
	ctx.r8.s64 = int64_t(r24.s32) * int64_t(r27.s32);
	// mullw r27,r20,r29
	r27.s64 = int64_t(r20.s32) * int64_t(r29.s32);
	// lwz r20,96(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// mullw r3,r25,r29
	ctx.r3.s64 = int64_t(r25.s32) * int64_t(r29.s32);
	// add r29,r3,r8
	r29.u64 = ctx.r3.u64 + ctx.r8.u64;
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mullw r28,r19,r20
	r28.s64 = int64_t(r19.s32) * int64_t(r20.s32);
	// lwz r19,104(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r24,96(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r26,r19
	ctx.r10.s64 = int64_t(r26.s32) * int64_t(r19.s32);
	// lwz r26,108(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mullw r11,r26,r24
	r11.s64 = int64_t(r26.s32) * int64_t(r24.s32);
	// mullw r26,r18,r3
	r26.s64 = int64_t(r18.s32) * int64_t(ctx.r3.s32);
	// lwz r18,112(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// mullw r3,r16,r3
	ctx.r3.s64 = int64_t(r16.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r27,r25,r26
	r27.u64 = r25.u64 + r26.u64;
	// mullw r10,r22,r18
	ctx.r10.s64 = int64_t(r22.s32) * int64_t(r18.s32);
	// mullw r26,r15,r19
	r26.s64 = int64_t(r15.s32) * int64_t(r19.s32);
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// mullw r3,r5,r19
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(r19.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r27,r27,r26
	r27.u64 = r27.u64 + r26.u64;
	// mullw r10,r21,r20
	ctx.r10.s64 = int64_t(r21.s32) * int64_t(r20.s32);
	// mullw r24,r17,r18
	r24.s64 = int64_t(r17.s32) * int64_t(r18.s32);
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// rlwinm r3,r27,17,15,31
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 17) & 0x1FFFF;
	// add r29,r29,r24
	r29.u64 = r29.u64 + r24.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mullw r28,r14,r19
	r28.s64 = int64_t(r14.s32) * int64_t(r19.s32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// add r29,r29,r28
	r29.u64 = r29.u64 + r28.u64;
	// rlwinm r3,r11,17,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0xFF;
	// stb r10,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r10.u8);
	// rlwinm r29,r29,17,15,31
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 17) & 0x1FFFF;
	// rlwinm r8,r8,17,15,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 17) & 0x1FFFF;
	// stb r3,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r3.u8);
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stb r29,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, r29.u8);
	// add r7,r7,r23
	ctx.r7.u64 = ctx.r7.u64 + r23.u64;
	// stb r8,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, ctx.r8.u8);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// ld r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// bne 0x8218ef84
	if (!cr0.eq) goto loc_8218EF84;
	// lwz r28,316(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r27,308(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
loc_8218F0F8:
	// lwz r8,124(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne cr6,0x8218ef48
	if (!cr6.eq) goto loc_8218EF48;
loc_8218F10C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_8218EE38) {
	__imp__sub_8218EE38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F114) {
	__imp__sub_8218F114(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8217bb68
	sub_8217BB68(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8218F118) {
	__imp__sub_8218F118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F12C) {
	__imp__sub_8218F12C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F130) {
	PPC_FUNC_PROLOGUE();
	// b 0x8217bc98
	sub_8217BC98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8218F130) {
	__imp__sub_8218F130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F134) {
	__imp__sub_8218F134(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F138) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9c0
	ctx.lr = 0x8218F14C;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f26,f5
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f5.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f25,f6
	f25.f64 = ctx.f6.f64;
	// lwz r31,284(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// fmr f24,f7
	f24.f64 = ctx.f7.f64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// fmr f27,f4
	f27.f64 = ctx.f4.f64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f23,f8
	f23.f64 = ctx.f8.f64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// fmr f22,f9
	f22.f64 = ctx.f9.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f3,f26
	ctx.f3.f64 = f26.f64;
	// fmr f7,f25
	ctx.f7.f64 = f25.f64;
	// fmr f8,f24
	ctx.f8.f64 = f24.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8218F1A0;
	sub_8217BC28(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f3,f26
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f26.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f8,f24
	ctx.f8.f64 = f24.f64;
	// fmr f7,f23
	ctx.f7.f64 = f23.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8218F1C8;
	sub_8217BC28(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f6,f31
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f8,f22
	ctx.f8.f64 = f22.f64;
	// fmr f7,f25
	ctx.f7.f64 = f25.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f26
	ctx.f3.f64 = f26.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8218F1F0;
	sub_8217BC28(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba0c
	ctx.lr = 0x8218F1FC;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218F138) {
	__imp__sub_8218F138(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F20C) {
	__imp__sub_8218F20C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// blt cr6,0x8218f22c
	if (cr6.lt) goto loc_8218F22C;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// bge cr6,0x8218f238
	if (!cr6.lt) goto loc_8218F238;
loc_8218F22C:
	// lhz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 208);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// b 0x8218f23c
	goto loc_8218F23C;
loc_8218F238:
	// addi r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 1;
loc_8218F23C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f12,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-48(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// stfs f0,-44(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// stfs f0,-40(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f12,-28(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// bge cr6,0x8218f2e4
	if (!cr6.lt) goto loc_8218F2E4;
	// rlwinm r9,r11,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// add r11,r9,r3
	r11.u64 = ctx.r9.u64 + ctx.r3.u64;
	// addi r9,r1,-48
	ctx.r9.s64 = ctx.r1.s64 + -48;
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,-16
	ctx.r7.s64 = -16;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// lfs f12,-17424(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -17424);
	ctx.f12.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f0,31016(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 31016);
	f0.f64 = double(temp.f32);
loc_8218F2B0:
	// stfs f13,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stb r9,44(r11)
	PPC_STORE_U8(r11.u32 + 44, ctx.r9.u8);
	// stfs f0,36(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// stb r9,45(r11)
	PPC_STORE_U8(r11.u32 + 45, ctx.r9.u8);
	// stfs f12,40(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// stb r6,46(r11)
	PPC_STORE_U8(r11.u32 + 46, ctx.r6.u8);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,47(r11)
	PPC_STORE_U8(r11.u32 + 47, ctx.r9.u8);
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x8218f2b0
	if (!cr0.eq) goto loc_8218F2B0;
loc_8218F2E4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stfs f13,204(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// lfs f0,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stfs f0,192(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f0,196(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f0,200(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218F210) {
	__imp__sub_8218F210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F304) {
	__imp__sub_8218F304(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F308) {
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
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// li r31,0
	r31.s64 = 0;
	// sth r11,208(r3)
	PPC_STORE_U16(ctx.r3.u32 + 208, r11.u16);
	// sth r11,210(r3)
	PPC_STORE_U16(ctx.r3.u32 + 210, r11.u16);
loc_8218F328:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218f210
	ctx.lr = 0x8218F330;
	sub_8218F210(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// blt cr6,0x8218f328
	if (cr6.lt) goto loc_8218F328;
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8218F308) {
	__imp__sub_8218F308(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F350) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f3a4
	if (cr6.eq) goto loc_8218F3A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F390;
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
loc_8218F3A4:
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

PPC_WEAK_FUNC(sub_8218F350) {
	__imp__sub_8218F350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F3BC) {
	__imp__sub_8218F3BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F3C0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F3DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f404
	if (cr6.eq) goto loc_8218F404;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F3F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F404:
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

PPC_WEAK_FUNC(sub_8218F3C0) {
	__imp__sub_8218F3C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F418) {
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
	ctx.lr = 0x8218F420;
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
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f46c
	if (cr6.eq) goto loc_8218F46C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8218F46C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8218F418) {
	__imp__sub_8218F418(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F478) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F49C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f4b8
	if (cr6.eq) goto loc_8218F4B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F4B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218F4B8:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8218F478) {
	__imp__sub_8218F478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F4CC) {
	__imp__sub_8218F4CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F4D0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F4EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f514
	if (cr6.eq) goto loc_8218F514;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F514:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25360(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8218F52C;
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

PPC_WEAK_FUNC(sub_8218F4D0) {
	__imp__sub_8218F4D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F53C) {
	__imp__sub_8218F53C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F540) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F55C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f584
	if (cr6.eq) goto loc_8218F584;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F584:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25360(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8218F59C;
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

PPC_WEAK_FUNC(sub_8218F540) {
	__imp__sub_8218F540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F5AC) {
	__imp__sub_8218F5AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F5B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218F5B0) {
	__imp__sub_8218F5B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F5B8) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F5D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f5fc
	if (cr6.eq) goto loc_8218F5FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F5EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F5FC:
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

PPC_WEAK_FUNC(sub_8218F5B8) {
	__imp__sub_8218F5B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F610) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f654
	if (cr6.eq) goto loc_8218F654;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F654:
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

PPC_WEAK_FUNC(sub_8218F610) {
	__imp__sub_8218F610(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F668) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f6ac
	if (cr6.eq) goto loc_8218F6AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F6AC:
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

PPC_WEAK_FUNC(sub_8218F668) {
	__imp__sub_8218F668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F6C0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F6DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f704
	if (cr6.eq) goto loc_8218F704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F6F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F704:
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

PPC_WEAK_FUNC(sub_8218F6C0) {
	__imp__sub_8218F6C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F718) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f74c
	if (cr6.eq) goto loc_8218F74C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F74C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218F74C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218F718) {
	__imp__sub_8218F718(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F75C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F75C) {
	__imp__sub_8218F75C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F760) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F77C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218f7a4
	if (cr6.eq) goto loc_8218F7A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8218F7A4:
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

PPC_WEAK_FUNC(sub_8218F760) {
	__imp__sub_8218F760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F7E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218f804
	if (cr6.eq) goto loc_8218F804;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F800;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8218f80c
	goto loc_8218F80C;
loc_8218F804:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
loc_8218F80C:
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_8218F7B8) {
	__imp__sub_8218F7B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F82C) {
	__imp__sub_8218F82C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218f87c
	if (cr6.eq) goto loc_8218F87C;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8218f884
	goto loc_8218F884;
loc_8218F87C:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
loc_8218F884:
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_8218F830) {
	__imp__sub_8218F830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F8A4) {
	__imp__sub_8218F8A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F8A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218f8c8
	if (cr6.eq) goto loc_8218F8C8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8218F8C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218F8A8) {
	__imp__sub_8218F8A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F8D0) {
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
	ctx.lr = 0x8218F8D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8218f8f4
	if (cr6.eq) goto loc_8218F8F4;
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8218F8F4;
	sub_821CE0D8(ctx, base);
loc_8218F8F4:
	// lwz r31,28(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218f930
	if (cr6.eq) goto loc_8218F930;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8218F908;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8218f930
	if (!cr6.eq) goto loc_8218F930;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218f930
	if (cr6.eq) goto loc_8218F930;
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
	ctx.lr = 0x8218F930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218F930:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r29.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218F948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8218F8D0) {
	__imp__sub_8218F8D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F954) {
	__imp__sub_8218F954(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8218F958) {
	__imp__sub_8218F958(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F978) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218F978) {
	__imp__sub_8218F978(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218F97C) {
	__imp__sub_8218F97C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F980) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-17132
	ctx.r10.s64 = r11.s64 + -17132;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x8218F9B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82180398
	ctx.lr = 0x8218F9B8;
	sub_82180398(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8218f9d0
	if (cr6.eq) goto loc_8218F9D0;
	// bl 0x82130588
	ctx.lr = 0x8218F9CC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8218F9D0:
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

PPC_WEAK_FUNC(sub_8218F980) {
	__imp__sub_8218F980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218F9E8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-17012
	ctx.r10.s64 = r11.s64 + -17012;
	// lwz r31,28(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218fa48
	if (cr6.eq) goto loc_8218FA48;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8218FA20;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8218fa48
	if (!cr6.eq) goto loc_8218FA48;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218fa48
	if (cr6.eq) goto loc_8218FA48;
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
	ctx.lr = 0x8218FA48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218FA48:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r10,r11,-17132
	ctx.r10.s64 = r11.s64 + -17132;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x8218FA5C;
	sub_82130588(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82180398
	ctx.lr = 0x8218FA64;
	sub_82180398(ctx, base);
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

PPC_WEAK_FUNC(sub_8218F9E8) {
	__imp__sub_8218F9E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FA7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FA7C) {
	__imp__sub_8218FA7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FA80) {
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
	// bl 0x8218f9e8
	ctx.lr = 0x8218FAA0;
	sub_8218F9E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218fab8
	if (cr6.eq) goto loc_8218FAB8;
	// bl 0x82130588
	ctx.lr = 0x8218FAB4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8218FAB8:
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

PPC_WEAK_FUNC(sub_8218FA80) {
	__imp__sub_8218FA80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FAD0) {
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
	ctx.lr = 0x8218FAD8;
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
	// bl 0x821d2970
	ctx.lr = 0x8218FAEC;
	sub_821D2970(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,-17132
	ctx.r8.s64 = ctx.r10.s64 + -17132;
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r7,12(r31)
	PPC_STORE_U16(r31.u32 + 12, ctx.r7.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x821378b8
	ctx.lr = 0x8218FB20;
	sub_821378B8(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r6,-17012
	ctx.r5.s64 = ctx.r6.s64 + -17012;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// beq cr6,0x8218fb44
	if (cr6.eq) goto loc_8218FB44;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8218FB44;
	sub_821CE0D8(ctx, base);
loc_8218FB44:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218FB58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218fb84
	if (cr6.eq) goto loc_8218FB84;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218FB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8218FB84:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25360(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8218FB9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8218FAD0) {
	__imp__sub_8218FAD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FBB0) {
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
	// bl 0x821d2970
	ctx.lr = 0x8218FBD0;
	sub_821D2970(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-17132
	ctx.r10.s64 = r11.s64 + -17132;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218fbfc
	if (cr6.eq) goto loc_8218FBFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8218FBF0;
	sub_8217D890(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
loc_8218FBFC:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r11,-17012
	ctx.r9.s64 = r11.s64 + -17012;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8218fc38
	if (!cr6.eq) goto loc_8218FC38;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218fc38
	if (cr6.eq) goto loc_8218FC38;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x821811c0
	ctx.lr = 0x8218FC2C;
	sub_821811C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218fc38
	if (cr6.eq) goto loc_8218FC38;
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
loc_8218FC38:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218FC4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218fc70
	if (cr6.eq) goto loc_8218FC70;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218FC64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// b 0x8218fc90
	goto loc_8218FC90;
loc_8218FC70:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25360(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8218FC88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
loc_8218FC90:
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

PPC_WEAK_FUNC(sub_8218FBB0) {
	__imp__sub_8218FBB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FCAC) {
	__imp__sub_8218FCAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FCB0) {
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
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8218fcec
	if (cr6.lt) goto loc_8218FCEC;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8218fcec
	if (!cr6.lt) goto loc_8218FCEC;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
loc_8218FCEC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218FD00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8218FCB0) {
	__imp__sub_8218FCB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FD18) {
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
	ctx.lr = 0x8218FD30;
	sub_821D2970(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r10,-16620
	ctx.r8.s64 = ctx.r10.s64 + -16620;
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_8218FD18) {
	__imp__sub_8218FD18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-16620
	ctx.r10.s64 = r11.s64 + -16620;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82180398
	sub_82180398(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8218FD70) {
	__imp__sub_8218FD70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FD80) {
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
	ctx.lr = 0x8218FD98;
	sub_821D2970(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16620
	ctx.r10.s64 = r11.s64 + -16620;
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

PPC_WEAK_FUNC(sub_8218FD80) {
	__imp__sub_8218FD80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FDBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FDBC) {
	__imp__sub_8218FDBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FDC0) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-16620
	ctx.r10.s64 = r11.s64 + -16620;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82180398
	ctx.lr = 0x8218FDEC;
	sub_82180398(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8218fe04
	if (cr6.eq) goto loc_8218FE04;
	// bl 0x82130588
	ctx.lr = 0x8218FE00;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8218FE04:
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

PPC_WEAK_FUNC(sub_8218FDC0) {
	__imp__sub_8218FDC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FE1C) {
	__imp__sub_8218FE1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// std r11,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, r11.u64);
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218FE20) {
	__imp__sub_8218FE20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,6
	r11.s64 = ctx.r4.s64 + 6;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218FE40) {
	__imp__sub_8218FE40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FE64) {
	__imp__sub_8218FE64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,14
	r11.s64 = ctx.r4.s64 + 14;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218FE68) {
	__imp__sub_8218FE68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FE8C) {
	__imp__sub_8218FE8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FE90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,15
	r11.s64 = ctx.r4.s64 + 15;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218FE90) {
	__imp__sub_8218FE90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FEB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FEB4) {
	__imp__sub_8218FEB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FEB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r11,6(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218ff34
	if (cr6.eq) goto loc_8218FF34;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r11,r11,-16160
	r11.s64 = r11.s64 + -16160;
	// addi r8,r10,-16224
	ctx.r8.s64 = ctx.r10.s64 + -16224;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8218FEF0:
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// slw r5,r6,r10
	ctx.r5.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// and r31,r7,r5
	r31.u64 = ctx.r7.u64 & ctx.r5.u64;
	// cmplw cr6,r31,r5
	cr6.compare<uint32_t>(r31.u32, ctx.r5.u32, xer);
	// bne cr6,0x8218ff1c
	if (!cr6.eq) goto loc_8218FF1C;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// beq cr6,0x8218ff8c
	if (cr6.eq) goto loc_8218FF8C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r5,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_8218FF1C:
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r9,128
	cr6.compare<uint32_t>(ctx.r9.u32, 128, xer);
	// blt cr6,0x8218fef0
	if (cr6.lt) goto loc_8218FEF0;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8218FF34:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r11,-16224
	ctx.r7.s64 = r11.s64 + -16224;
loc_8218FF40:
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x8218ff8c
	if (cr6.eq) goto loc_8218FF8C;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// slw r5,r6,r9
	ctx.r5.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r9.u8 & 0x3F));
	// and r11,r11,r5
	r11.u64 = r11.u64 & ctx.r5.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beq cr6,0x8218ff64
	if (cr6.eq) goto loc_8218FF64;
	// li r11,0
	r11.s64 = 0;
	// b 0x8218ff78
	goto loc_8218FF78;
loc_8218FF64:
	// ld r11,8(r8)
	r11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// extsw r5,r10
	ctx.r5.s64 = ctx.r10.s32;
	// srd r11,r11,r5
	r11.u64 = ctx.r5.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r5.u8 & 0x7F));
	// rlwinm r5,r11,2,26,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3C;
	// lwzx r11,r5,r7
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
loc_8218FF78:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// blt cr6,0x8218ff40
	if (cr6.lt) goto loc_8218FF40;
loc_8218FF8C:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218FEB8) {
	__imp__sub_8218FEB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FF94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8218FF94) {
	__imp__sub_8218FF94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8218FF98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r7,r9,-16224
	ctx.r7.s64 = ctx.r9.s64 + -16224;
loc_8218FFB0:
	// and r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 & ctx.r8.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x8218ffd8
	if (!cr6.eq) goto loc_8218FFD8;
	// addi r9,r10,-8
	ctx.r9.s64 = ctx.r10.s64 + -8;
	// ld r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// srd r9,r5,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r4.u8 & 0x7F));
	// rlwinm r5,r9,2,26,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r9,r5,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_8218FFD8:
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// and r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 & ctx.r8.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x82190004
	if (!cr6.eq) goto loc_82190004;
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// ld r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// srd r9,r5,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r4.u8 & 0x7F));
	// rlwinm r5,r9,2,26,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r9,r5,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_82190004:
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// and r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 & ctx.r8.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x8219002c
	if (!cr6.eq) goto loc_8219002C;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r5,r10
	ctx.r5.s64 = ctx.r10.s32;
	// srd r4,r9,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r5.u8 & 0x7F));
	// rlwinm r9,r4,2,26,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3C;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_8219002C:
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// and r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 & ctx.r8.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x82190058
	if (!cr6.eq) goto loc_82190058;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// ld r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// srd r9,r5,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r4.u8 & 0x7F));
	// rlwinm r5,r9,2,26,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3C;
	// lwzx r9,r5,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_82190058:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r8,r8,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// cmpwi cr6,r10,72
	cr6.compare<int32_t>(ctx.r10.s32, 72, xer);
	// blt cr6,0x8218ffb0
	if (cr6.lt) goto loc_8218FFB0;
	// lbz r10,6(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190084
	if (cr6.eq) goto loc_82190084;
	// addi r11,r11,15
	r11.s64 = r11.s64 + 15;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// blr 
	return;
loc_82190084:
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8218FF98) {
	__imp__sub_8218FF98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219008C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219008C) {
	__imp__sub_8219008C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190090) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821900a4
	if (!cr6.eq) goto loc_821900A4;
	// li r11,255
	r11.s64 = 255;
loc_821900A4:
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// lbz r11,1(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821900b8
	if (!cr6.eq) goto loc_821900B8;
	// li r11,255
	r11.s64 = 255;
loc_821900B8:
	// stb r11,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, r11.u8);
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821900cc
	if (!cr6.eq) goto loc_821900CC;
	// li r11,255
	r11.s64 = 255;
loc_821900CC:
	// stb r11,2(r4)
	PPC_STORE_U8(ctx.r4.u32 + 2, r11.u8);
	// lbz r11,3(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821900e0
	if (!cr6.eq) goto loc_821900E0;
	// li r11,255
	r11.s64 = 255;
loc_821900E0:
	// stb r11,3(r4)
	PPC_STORE_U8(ctx.r4.u32 + 3, r11.u8);
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821900f8
	if (!cr6.eq) goto loc_821900F8;
	// li r11,255
	r11.s64 = 255;
loc_821900F8:
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lbz r11,9(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8219010c
	if (!cr6.eq) goto loc_8219010C;
	// li r11,255
	r11.s64 = 255;
loc_8219010C:
	// stb r11,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, r11.u8);
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190120
	if (!cr6.eq) goto loc_82190120;
	// li r11,255
	r11.s64 = 255;
loc_82190120:
	// stb r11,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, r11.u8);
	// lbz r11,11(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190134
	if (!cr6.eq) goto loc_82190134;
	// li r11,255
	r11.s64 = 255;
loc_82190134:
	// stb r11,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, r11.u8);
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190148
	if (!cr6.eq) goto loc_82190148;
	// li r11,255
	r11.s64 = 255;
loc_82190148:
	// stb r11,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, r11.u8);
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8219015c
	if (!cr6.eq) goto loc_8219015C;
	// li r11,255
	r11.s64 = 255;
loc_8219015C:
	// stb r11,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, r11.u8);
	// lbz r11,14(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190170
	if (!cr6.eq) goto loc_82190170;
	// li r11,255
	r11.s64 = 255;
loc_82190170:
	// stb r11,6(r10)
	PPC_STORE_U8(ctx.r10.u32 + 6, r11.u8);
	// lbz r11,15(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 15);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190184
	if (!cr6.eq) goto loc_82190184;
	// li r11,255
	r11.s64 = 255;
loc_82190184:
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r11,r10,8
	r11.s64 = ctx.r10.s64 + 8;
	// stb r8,7(r10)
	PPC_STORE_U8(ctx.r10.u32 + 7, ctx.r8.u8);
	// subf r3,r9,r11
	ctx.r3.s64 = r11.s64 - ctx.r9.s64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82190090) {
	__imp__sub_82190090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190198) {
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
	ctx.lr = 0x821901A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190278
	if (cr6.eq) goto loc_82190278;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r10,r10,-16160
	ctx.r10.s64 = ctx.r10.s64 + -16160;
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// std r11,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, r11.u64);
	// li r6,15
	ctx.r6.s64 = 15;
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r11.u8);
	// stb r7,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r7.u8);
loc_821901E4:
	// lwz r9,-4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// slw r11,r7,r9
	r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & r11.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82190260
	if (!cr6.eq) goto loc_82190260;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r31,0(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// and r30,r10,r11
	r30.u64 = ctx.r10.u64 & r11.u64;
	// ld r29,8(r3)
	r29.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// sld r28,r6,r9
	r28.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r9.u8 & 0x7F));
	// cntlzw r30,r30
	r30.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// extsw r31,r31
	r31.s64 = r31.s32;
	// rlwinm r30,r30,27,31,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 27) & 0x1;
	// sld r9,r31,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (r31.u64 << (ctx.r9.u8 & 0x7F));
	// andc r29,r29,r28
	r29.u64 = r29.u64 & ~r28.u64;
	// xori r31,r30,1
	r31.u64 = r30.u64 ^ 1;
	// or r9,r29,r9
	ctx.r9.u64 = r29.u64 | ctx.r9.u64;
	// clrlwi r31,r31,24
	r31.u64 = r31.u32 & 0xFF;
	// std r9,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r9.u64);
	// lbz r9,7(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82190250
	if (!cr6.eq) goto loc_82190250;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// b 0x82190258
	goto loc_82190258;
loc_82190250:
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// addi r10,r9,255
	ctx.r10.s64 = ctx.r9.s64 + 255;
loc_82190258:
	// stb r10,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r10.u8);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_82190260:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// bne 0x821901e4
	if (!cr0.eq) goto loc_821901E4;
	// bl 0x8218ff98
	ctx.lr = 0x82190270;
	sub_8218FF98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82190278:
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lbz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r9,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// lbz r8,6(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// stb r8,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r8.u8);
	// ld r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// std r7,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r7.u64);
	// lbz r6,7(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// stb r6,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r6.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82190198) {
	__imp__sub_82190198(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821902B0) {
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
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821902d8
	if (cr6.eq) goto loc_821902D8;
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x821902f4
	goto loc_821902F4;
loc_821902D8:
	// cmpwi cr6,r5,16
	cr6.compare<int32_t>(ctx.r5.s32, 16, xer);
	// bne cr6,0x821902f4
	if (!cr6.eq) goto loc_821902F4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r5,r11,6
	ctx.r5.s64 = r11.s64 + 6;
loc_821902F4:
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// rldicr r7,r10,0,59
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 0) & 0xFFFFFFFFFFFFFFF0;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// beq cr6,0x82190338
	if (cr6.eq) goto loc_82190338;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82190338
	if (!cr6.eq) goto loc_82190338;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x82190350
	goto loc_82190350;
loc_82190338:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190358
	if (cr6.eq) goto loc_82190358;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_82190350:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82190358:
	// bl 0x8218ff98
	ctx.lr = 0x8219035C;
	sub_8218FF98(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190374
	if (cr6.eq) goto loc_82190374;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// b 0x8219037c
	goto loc_8219037C;
loc_82190374:
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_8219037C:
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_821902B0) {
	__imp__sub_821902B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82190394) {
	__imp__sub_82190394(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190398) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821903ac
	if (cr6.eq) goto loc_821903AC;
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x821903b8
	goto loc_821903B8;
loc_821903AC:
	// cmpwi cr6,r5,16
	cr6.compare<int32_t>(ctx.r5.s32, 16, xer);
	// bne cr6,0x821903b8
	if (!cr6.eq) goto loc_821903B8;
	// li r5,5
	ctx.r5.s64 = 5;
loc_821903B8:
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// li r12,-241
	r12.s64 = -241;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rldicr r7,r9,4,59
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 4) & 0xFFFFFFFFFFFFFFF0;
	// and r6,r10,r12
	ctx.r6.u64 = ctx.r10.u64 & r12.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r5,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r5.u64);
	// beq cr6,0x82190404
	if (cr6.eq) goto loc_82190404;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82190404
	if (!cr6.eq) goto loc_82190404;
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x8219041c
	goto loc_8219041C;
loc_82190404:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190424
	if (cr6.eq) goto loc_82190424;
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_8219041C:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82190424:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82190398) {
	__imp__sub_82190398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// cmpwi cr6,r5,16
	cr6.compare<int32_t>(ctx.r5.s32, 16, xer);
	// bne cr6,0x82190434
	if (!cr6.eq) goto loc_82190434;
	// li r5,9
	ctx.r5.s64 = 9;
loc_82190434:
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// li r12,-3841
	r12.s64 = -3841;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rldicr r7,r9,8,55
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// and r6,r10,r12
	ctx.r6.u64 = ctx.r10.u64 & r12.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r5,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r5.u64);
	// beq cr6,0x82190480
	if (cr6.eq) goto loc_82190480;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82190480
	if (!cr6.eq) goto loc_82190480;
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x82190498
	goto loc_82190498;
loc_82190480:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821904a0
	if (cr6.eq) goto loc_821904A0;
	// rlwinm r10,r11,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_82190498:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_821904A0:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82190428) {
	__imp__sub_82190428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821904A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821904A4) {
	__imp__sub_821904A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821904A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821904bc
	if (cr6.eq) goto loc_821904BC;
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x821904c8
	goto loc_821904C8;
loc_821904BC:
	// cmpwi cr6,r5,16
	cr6.compare<int32_t>(ctx.r5.s32, 16, xer);
	// bne cr6,0x821904c8
	if (!cr6.eq) goto loc_821904C8;
	// li r5,6
	ctx.r5.s64 = 6;
loc_821904C8:
	// lis r12,-1
	r12.s64 = -65536;
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r12,r12,4095
	r12.u64 = r12.u64 | 4095;
	// rldicr r7,r9,12,51
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 12) & 0xFFFFFFFFFFFFF000;
	// and r6,r10,r12
	ctx.r6.u64 = ctx.r10.u64 & r12.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r5,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r5.u64);
	// beq cr6,0x82190518
	if (cr6.eq) goto loc_82190518;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82190518
	if (!cr6.eq) goto loc_82190518;
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x82190530
	goto loc_82190530;
loc_82190518:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190538
	if (cr6.eq) goto loc_82190538;
	// rlwinm r10,r11,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_82190530:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82190538:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821904A8) {
	__imp__sub_821904A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219053C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219053C) {
	__imp__sub_8219053C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// cmpwi cr6,r5,16
	cr6.compare<int32_t>(ctx.r5.s32, 16, xer);
	// bne cr6,0x8219054c
	if (!cr6.eq) goto loc_8219054C;
	// li r5,9
	ctx.r5.s64 = 9;
loc_8219054C:
	// lis r12,-16
	r12.s64 = -1048576;
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r7,r9,16,47
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 16) & 0xFFFFFFFFFFFF0000;
	// and r6,r10,r12
	ctx.r6.u64 = ctx.r10.u64 & r12.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r11,28,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r5,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r5.u64);
	// beq cr6,0x8219059c
	if (cr6.eq) goto loc_8219059C;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8219059c
	if (!cr6.eq) goto loc_8219059C;
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x821905b4
	goto loc_821905B4;
loc_8219059C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821905bc
	if (cr6.eq) goto loc_821905BC;
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_821905B4:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_821905BC:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82190540) {
	__imp__sub_82190540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821905C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// cmpwi cr6,r5,16
	cr6.compare<int32_t>(ctx.r5.s32, 16, xer);
	// bne cr6,0x821905cc
	if (!cr6.eq) goto loc_821905CC;
	// li r5,9
	ctx.r5.s64 = 9;
loc_821905CC:
	// lis r12,-241
	r12.s64 = -15794176;
	// ld r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r12,r12,65535
	r12.u64 = r12.u64 | 65535;
	// rldicr r7,r9,20,43
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 20) & 0xFFFFFFFFFFF00000;
	// and r6,r10,r12
	ctx.r6.u64 = ctx.r10.u64 & r12.u64;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// std r5,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r5.u64);
	// beq cr6,0x8219061c
	if (cr6.eq) goto loc_8219061C;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8219061c
	if (!cr6.eq) goto loc_8219061C;
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x82190634
	goto loc_82190634;
loc_8219061C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8219063c
	if (cr6.eq) goto loc_8219063C;
	// rlwinm r10,r11,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_82190634:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8219063C:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821905C0) {
	__imp__sub_821905C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190640) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190654
	if (cr6.eq) goto loc_82190654;
	// li r6,7
	ctx.r6.s64 = 7;
	// b 0x82190660
	goto loc_82190660;
loc_82190654:
	// cmpwi cr6,r6,16
	cr6.compare<int32_t>(ctx.r6.s32, 16, xer);
	// bne cr6,0x82190660
	if (!cr6.eq) goto loc_82190660;
	// li r6,5
	ctx.r6.s64 = 5;
loc_82190660:
	// addi r11,r4,6
	r11.s64 = ctx.r4.s64 + 6;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,15
	ctx.r4.s64 = 15;
	// slw r11,r9,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// sld r9,r4,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r4.u64 << (ctx.r7.u8 & 0x7F));
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & r11.u64;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// sld r8,r6,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r7.u8 & 0x7F));
	// cntlzw r7,r4
	ctx.r7.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// xori r9,r4,1
	ctx.r9.u64 = ctx.r4.u64 ^ 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821906cc
	if (cr6.eq) goto loc_821906CC;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821906cc
	if (!cr6.eq) goto loc_821906CC;
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x821906e4
	goto loc_821906E4;
loc_821906CC:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821906ec
	if (cr6.eq) goto loc_821906EC;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_821906E4:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_821906EC:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82190640) {
	__imp__sub_82190640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821906F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190704
	if (cr6.eq) goto loc_82190704;
	// li r6,7
	ctx.r6.s64 = 7;
	// b 0x82190710
	goto loc_82190710;
loc_82190704:
	// cmpwi cr6,r6,16
	cr6.compare<int32_t>(ctx.r6.s32, 16, xer);
	// bne cr6,0x82190710
	if (!cr6.eq) goto loc_82190710;
	// li r6,6
	ctx.r6.s64 = 6;
loc_82190710:
	// addi r11,r4,14
	r11.s64 = ctx.r4.s64 + 14;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,15
	ctx.r4.s64 = 15;
	// slw r11,r9,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// sld r9,r4,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r4.u64 << (ctx.r7.u8 & 0x7F));
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & r11.u64;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// sld r8,r6,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r7.u8 & 0x7F));
	// cntlzw r7,r4
	ctx.r7.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// xori r9,r4,1
	ctx.r9.u64 = ctx.r4.u64 ^ 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8219077c
	if (cr6.eq) goto loc_8219077C;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8219077c
	if (!cr6.eq) goto loc_8219077C;
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x82190794
	goto loc_82190794;
loc_8219077C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8219079c
	if (cr6.eq) goto loc_8219079C;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_82190794:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8219079C:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821906F0) {
	__imp__sub_821906F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821907A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821907b4
	if (cr6.eq) goto loc_821907B4;
	// li r6,7
	ctx.r6.s64 = 7;
	// b 0x821907c0
	goto loc_821907C0;
loc_821907B4:
	// cmpwi cr6,r6,16
	cr6.compare<int32_t>(ctx.r6.s32, 16, xer);
	// bne cr6,0x821907c0
	if (!cr6.eq) goto loc_821907C0;
	// li r6,6
	ctx.r6.s64 = 6;
loc_821907C0:
	// addi r11,r4,15
	r11.s64 = ctx.r4.s64 + 15;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,15
	ctx.r4.s64 = 15;
	// slw r11,r9,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// sld r9,r4,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r4.u64 << (ctx.r7.u8 & 0x7F));
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & r11.u64;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// sld r8,r6,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r7.u8 & 0x7F));
	// cntlzw r7,r4
	ctx.r7.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// xori r9,r4,1
	ctx.r9.u64 = ctx.r4.u64 ^ 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8219082c
	if (cr6.eq) goto loc_8219082C;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8219082c
	if (!cr6.eq) goto loc_8219082C;
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// b 0x82190844
	goto loc_82190844;
loc_8219082C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8219084c
	if (cr6.eq) goto loc_8219084C;
	// andc r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ~r11.u64;
	// lbz r11,7(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r9,r11,255
	ctx.r9.s64 = r11.s64 + 255;
loc_82190844:
	// stb r9,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r9.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8219084C:
	// b 0x8218ff98
	sub_8218FF98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_821907A0) {
	__imp__sub_821907A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190850) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,244(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 244);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82190850) {
	__imp__sub_82190850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190860) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82190860) {
	__imp__sub_82190860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82190864) {
	__imp__sub_82190864(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190868) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82190868) {
	__imp__sub_82190868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-13428(r11)
	PPC_STORE_U32(r11.u32 + -13428, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82190870) {
	__imp__sub_82190870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219087C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219087C) {
	__imp__sub_8219087C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-13428(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -13428);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82190880) {
	__imp__sub_82190880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219088C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219088C) {
	__imp__sub_8219088C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-13500(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13500);
	// stw r11,-13500(r10)
	PPC_STORE_U32(ctx.r10.u32 + -13500, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82190890) {
	__imp__sub_82190890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821908A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821908A4) {
	__imp__sub_821908A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821908A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-13500(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -13500);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821908A8) {
	__imp__sub_821908A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821908B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821908B4) {
	__imp__sub_821908B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821908B8) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821908D4;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821908DC;
	sub_821D2AA0(ctx, base);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_821908B8) {
	__imp__sub_821908B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821908F0) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-30140
	ctx.r9.s64 = r11.s64 + -30140;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82190924
	if (cr6.eq) goto loc_82190924;
	// bl 0x82130588
	ctx.lr = 0x82190920;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82190924:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_821908F0) {
	__imp__sub_821908F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190938) {
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
	ctx.lr = 0x82190940;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,35
	cr6.compare<uint32_t>(r11.u32, 35, xer);
	// bne cr6,0x8219095c
	if (!cr6.eq) goto loc_8219095C;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8219095C:
	// bl 0x823dd7f0
	ctx.lr = 0x82190960;
	sub_823DD7F0(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r10,r11
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x821864d8
	ctx.lr = 0x82190970;
	sub_821864D8(ctx, base);
	// clrlwi r9,r28,30
	ctx.r9.u64 = r28.u32 & 0x3;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821909a0
	if (cr6.eq) goto loc_821909A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82186f40
	ctx.lr = 0x8219098C;
	sub_82186F40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
loc_821909A0:
	// rlwinm r11,r28,0,29,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821909b0
	if (cr6.eq) goto loc_821909B0;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
loc_821909B0:
	// clrlwi r11,r28,29
	r11.u64 = r28.u32 & 0x7;
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821909c4
	if (cr6.eq) goto loc_821909C4;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
loc_821909C4:
	// rlwinm r11,r28,0,28,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821909f4
	if (cr6.eq) goto loc_821909F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82186f40
	ctx.lr = 0x821909DC;
	sub_82186F40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_821909F4:
	// clrlwi r11,r28,28
	r11.u64 = r28.u32 & 0xF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190a24
	if (cr6.eq) goto loc_82190A24;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82186f40
	ctx.lr = 0x82190A0C;
	sub_82186F40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82190A24:
	// li r30,0
	r30.s64 = 0;
	// li r27,6
	r27.s64 = 6;
loc_82190A2C:
	// slw r11,r27,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r27.u32 << (r30.u8 & 0x3F));
	// and r10,r11,r28
	ctx.r10.u64 = r11.u64 & r28.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190a60
	if (cr6.eq) goto loc_82190A60;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82186f50
	ctx.lr = 0x82190A48;
	sub_82186F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82190A60:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x82190a2c
	if (cr6.lt) goto loc_82190A2C;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// twllei r31,0
	// lwz r11,-13424(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -13424);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r3,r11,r31
	ctx.r3.s32 = r11.s32 / r31.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r9,r31,r10
	ctx.r9.u64 = r31.u64 & ~ctx.r10.u64;
	// twlgei r9,-1
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82190938) {
	__imp__sub_82190938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82190A94) {
	__imp__sub_82190A94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190A98) {
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
	// addi r31,r3,1024
	r31.s64 = ctx.r3.s64 + 1024;
	// li r30,255
	r30.s64 = 255;
loc_82190AB4:
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82190AC0;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82190ab4
	if (!cr0.lt) goto loc_82190AB4;
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

PPC_WEAK_FUNC(sub_82190A98) {
	__imp__sub_82190A98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190AE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,26(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
loc_82190B00:
	// lhz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// lbz r4,9(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 9);
	// slw r7,r8,r4
	ctx.r7.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r4.u8 & 0x3F));
	// or r3,r7,r3
	ctx.r3.u64 = ctx.r7.u64 | ctx.r3.u64;
	// bne 0x82190b00
	if (!cr0.eq) goto loc_82190B00;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82190AE0) {
	__imp__sub_82190AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190B28) {
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
	ctx.lr = 0x82190B30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190b90
	if (cr6.eq) goto loc_82190B90;
	// li r29,0
	r29.s64 = 0;
loc_82190B50:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lhzx r9,r11,r29
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + r29.u32);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,72(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 72);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82190B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,26(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmpw cr6,r31,r5
	cr6.compare<int32_t>(r31.s32, ctx.r5.s32, xer);
	// blt cr6,0x82190b50
	if (cr6.lt) goto loc_82190B50;
loc_82190B90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82190B28) {
	__imp__sub_82190B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_82190B98) {
	__imp__sub_82190B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82190BB4) {
	__imp__sub_82190BB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_82190BB8) {
	__imp__sub_82190BB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190BD8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82190BE0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r22,-32124
	r22.s64 = -2105278464;
	// lwz r21,-13500(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + -13500);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82190c40
	if (cr6.eq) goto loc_82190C40;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lbz r10,-13430(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -13430);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190c40
	if (cr6.eq) goto loc_82190C40;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-26876(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -26876);
	// bl 0x8217c4b0
	ctx.lr = 0x82190C28;
	sub_8217C4B0(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// beq cr6,0x82190e10
	if (cr6.eq) goto loc_82190E10;
	// lhz r11,26(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82190c44
	if (!cr6.eq) goto loc_82190C44;
loc_82190C40:
	// li r19,2
	r19.s64 = 2;
loc_82190C44:
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r19,2
	cr6.compare<int32_t>(r19.s32, 2, xer);
	// beq cr6,0x82190c6c
	if (cr6.eq) goto loc_82190C6C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-26876(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -26876);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8217c4b0
	ctx.lr = 0x82190C64;
	sub_8217C4B0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r25,r11,27,31,31
	r25.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_82190C6C:
	// lis r27,-32124
	r27.s64 = -2105278464;
	// li r20,-1
	r20.s64 = -1;
	// lwz r10,-13428(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -13428);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190c90
	if (cr6.eq) goto loc_82190C90;
	// lbz r11,11(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190c90
	if (!cr6.eq) goto loc_82190C90;
	// lbz r20,9(r10)
	r20.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
loc_82190C90:
	// lhz r11,26(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82190e10
	if (!cr6.gt) goto loc_82190E10;
	// li r28,0
	r28.s64 = 0;
	// li r26,32
	r26.s64 = 32;
loc_82190CA8:
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmpwi cr6,r19,2
	cr6.compare<int32_t>(r19.s32, 2, xer);
	// beq cr6,0x82190cec
	if (cr6.eq) goto loc_82190CEC;
	// addi r9,r29,1
	ctx.r9.s64 = r29.s64 + 1;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bge cr6,0x82190ce0
	if (!cr6.lt) goto loc_82190CE0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-26876(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -26876);
	// add r4,r26,r11
	ctx.r4.u64 = r26.u64 + r11.u64;
	// bl 0x8217c4b0
	ctx.lr = 0x82190CD4;
	sub_8217C4B0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lwz r10,-13428(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -13428);
	// rlwinm r25,r11,27,31,31
	r25.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_82190CE0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190df8
	if (!cr6.eq) goto loc_82190DF8;
loc_82190CEC:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190cfc
	if (cr6.eq) goto loc_82190CFC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x82190d10
	goto loc_82190D10;
loc_82190CFC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,8(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// lhzx r8,r11,r28
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + r28.u32);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r3,r7,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
loc_82190D10:
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// bge cr6,0x82190d34
	if (!cr6.lt) goto loc_82190D34;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,8(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// lhzx r8,r11,r28
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + r28.u32);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lbz r11,9(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 9);
	// b 0x82190d38
	goto loc_82190D38;
loc_82190D34:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82190D38:
	// cmpw cr6,r11,r18
	cr6.compare<int32_t>(r11.s32, r18.s32, xer);
	// bne cr6,0x82190df8
	if (!cr6.eq) goto loc_82190DF8;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82190d64
	if (cr6.eq) goto loc_82190D64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8219a918
	ctx.lr = 0x82190D60;
	sub_8219A918(ctx, base);
	// b 0x82190df4
	goto loc_82190DF4;
loc_82190D64:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82190db8
	if (!cr6.eq) goto loc_82190DB8;
	// lhz r11,26(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82190db0
	if (!cr6.lt) goto loc_82190DB0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,8(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// add r9,r11,r28
	ctx.r9.u64 = r11.u64 + r28.u64;
	// lhz r8,14(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// lhz r7,2(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lhz r4,14(r5)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + 14);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// bne cr6,0x82190db0
	if (!cr6.eq) goto loc_82190DB0;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190db8
	if (cr6.eq) goto loc_82190DB8;
loc_82190DB0:
	// li r11,0
	r11.s64 = 0;
	// b 0x82190dbc
	goto loc_82190DBC;
loc_82190DB8:
	// li r11,1
	r11.s64 = 1;
loc_82190DBC:
	// lhz r10,26(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// addi r9,r29,1
	ctx.r9.s64 = r29.s64 + 1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x82190ddc
	if (cr6.eq) goto loc_82190DDC;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82190de0
	if (!cr6.eq) goto loc_82190DE0;
loc_82190DDC:
	// li r11,1
	r11.s64 = 1;
loc_82190DE0:
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82188000
	ctx.lr = 0x82190DF4;
	sub_82188000(ctx, base);
loc_82190DF4:
	// lwz r10,-13428(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -13428);
loc_82190DF8:
	// lhz r11,26(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,16
	r26.s64 = r26.s64 + 16;
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82190ca8
	if (cr6.lt) goto loc_82190CA8;
loc_82190E10:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_82190BD8) {
	__imp__sub_82190BD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190E18) {
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
	ctx.lr = 0x82190E20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r10,-13428(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -13428);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// li r24,-1
	r24.s64 = -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190e5c
	if (cr6.eq) goto loc_82190E5C;
	// lbz r11,11(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82190e5c
	if (!cr6.eq) goto loc_82190E5C;
	// lbz r24,9(r10)
	r24.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
loc_82190E5C:
	// lhz r9,26(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82190f5c
	if (!cr6.gt) goto loc_82190F5C;
	// li r29,0
	r29.s64 = 0;
loc_82190E70:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82190e80
	if (cr6.eq) goto loc_82190E80;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x82190e94
	goto loc_82190E94;
loc_82190E80:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,8(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lhzx r7,r11,r29
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + r29.u32);
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
loc_82190E94:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bge cr6,0x82190eb8
	if (!cr6.lt) goto loc_82190EB8;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,8(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lhzx r7,r11,r29
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + r29.u32);
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lbz r11,9(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 9);
	// b 0x82190ebc
	goto loc_82190EBC;
loc_82190EB8:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82190EBC:
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// bne cr6,0x82190f48
	if (!cr6.eq) goto loc_82190F48;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82190f08
	if (!cr6.eq) goto loc_82190F08;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x82190f00
	if (!cr6.lt) goto loc_82190F00;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// lhz r7,14(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// lhz r6,2(r8)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// rotlwi r5,r6,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lwzx r4,r5,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lhz r11,14(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 14);
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// beq cr6,0x82190f08
	if (cr6.eq) goto loc_82190F08;
loc_82190F00:
	// li r11,0
	r11.s64 = 0;
	// b 0x82190f0c
	goto loc_82190F0C;
loc_82190F08:
	// li r11,1
	r11.s64 = 1;
loc_82190F0C:
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x82190f28
	if (cr6.eq) goto loc_82190F28;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82190f2c
	if (!cr6.eq) goto loc_82190F2C;
loc_82190F28:
	// li r11,1
	r11.s64 = 1;
loc_82190F2C:
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82188080
	ctx.lr = 0x82190F44;
	sub_82188080(ctx, base);
	// lwz r10,-13428(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -13428);
loc_82190F48:
	// lhz r9,26(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82190e70
	if (cr6.lt) goto loc_82190E70;
loc_82190F5C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82190E18) {
	__imp__sub_82190E18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82190F64) {
	__imp__sub_82190F64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190F68) {
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
	ctx.lr = 0x82190F70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82190fc4
	if (cr6.eq) goto loc_82190FC4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82190fc4
	if (cr6.eq) goto loc_82190FC4;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r29,r11,-4
	r29.s64 = r11.s64 + -4;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addic. r31,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r31.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// blt 0x82190fbc
	if (cr0.lt) goto loc_82190FBC;
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
loc_82190FA8:
	// addi r30,r30,-16
	r30.s64 = r30.s64 + -16;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82190FB4;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82190fa8
	if (!cr0.lt) goto loc_82190FA8;
loc_82190FBC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82190FC4;
	sub_82130588(ctx, base);
loc_82190FC4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82190F68) {
	__imp__sub_82190F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82190FCC) {
	__imp__sub_82190FCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82190FD0) {
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
	ctx.lr = 0x82190FD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82191034
	if (cr6.eq) goto loc_82191034;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191034
	if (cr6.eq) goto loc_82191034;
	// lwz r9,-16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// addi r29,r11,-16
	r29.s64 = r11.s64 + -16;
	// rlwinm r10,r9,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// addic. r30,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r30.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// blt 0x8219102c
	if (cr0.lt) goto loc_8219102C;
	// addi r31,r11,244
	r31.s64 = r11.s64 + 244;
loc_82191010:
	// addi r31,r31,-256
	r31.s64 = r31.s64 + -256;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82191024
	if (cr6.eq) goto loc_82191024;
	// bl 0x82130588
	ctx.lr = 0x82191024;
	sub_82130588(ctx, base);
loc_82191024:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82191010
	if (!cr0.lt) goto loc_82191010;
loc_8219102C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82191034;
	sub_82130588(ctx, base);
loc_82191034:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82190FD0) {
	__imp__sub_82190FD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219103C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219103C) {
	__imp__sub_8219103C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191040) {
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
	ctx.lr = 0x82191048;
	// stwu r1,-1248(r1)
	ea = -1248 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x8219106C;
	sub_821CA6A8(ctx, base);
	// bl 0x821be8d8
	ctx.lr = 0x82191070;
	sub_821BE8D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82191084
	if (!cr6.eq) goto loc_82191084;
	// addi r1,r1,1248
	ctx.r1.s64 = ctx.r1.s64 + 1248;
	// b 0x823d9248
	return;
loc_82191084:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8219108C;
	sub_821BE4F0(ctx, base);
	// cmpwi cr6,r3,26
	cr6.compare<int32_t>(ctx.r3.s32, 26, xer);
	// bne cr6,0x821910ec
	if (!cr6.eq) goto loc_821910EC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r10,r11,-15748
	ctx.r10.s64 = r11.s64 + -15748;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r10.u32);
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x821cf7b8
	ctx.lr = 0x821910B0;
	sub_821CF7B8(ctx, base);
	// addi r9,r1,656
	ctx.r9.s64 = ctx.r1.s64 + 656;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r8,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, ctx.r8.u8);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8219f030
	ctx.lr = 0x821910CC;
	sub_8219F030(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-30140
	ctx.r6.s64 = ctx.r7.s64 + -30140;
	// stw r6,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r6.u32);
	// bl 0x821be610
	ctx.lr = 0x821910E0;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1248
	ctx.r1.s64 = ctx.r1.s64 + 1248;
	// b 0x823d9248
	return;
loc_821910EC:
	// cmpwi cr6,r3,13
	cr6.compare<int32_t>(ctx.r3.s32, 13, xer);
	// beq cr6,0x82191100
	if (cr6.eq) goto loc_82191100;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be568
	ctx.lr = 0x82191100;
	sub_821BE568(ctx, base);
loc_82191100:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r29,0
	r29.s64 = 0;
	// addi r10,r11,-29924
	ctx.r10.s64 = r11.s64 + -29924;
	// stw r29,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, r29.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cf7b8
	ctx.lr = 0x82191124;
	sub_821CF7B8(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r29.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8219f030
	ctx.lr = 0x8219113C;
	sub_8219F030(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-30140
	ctx.r7.s64 = ctx.r8.s64 + -30140;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x821be610
	ctx.lr = 0x82191150;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1248
	ctx.r1.s64 = ctx.r1.s64 + 1248;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82191040) {
	__imp__sub_82191040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219115C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219115C) {
	__imp__sub_8219115C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191160) {
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
	ctx.lr = 0x82191168;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-15580
	ctx.r10.s64 = r11.s64 + -15580;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x82191184;
	sub_82130588(ctx, base);
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821911d0
	if (cr6.eq) goto loc_821911D0;
	// li r30,0
	r30.s64 = 0;
loc_82191198:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821911bc
	if (cr6.eq) goto loc_821911BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821911BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821911BC:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82191198
	if (cr6.lt) goto loc_82191198;
loc_821911D0:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821911e0
	if (cr6.eq) goto loc_821911E0;
	// bl 0x82130588
	ctx.lr = 0x821911E0;
	sub_82130588(ctx, base);
loc_821911E0:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82192618
	ctx.lr = 0x821911E8;
	sub_82192618(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x821911F0;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82191160) {
	__imp__sub_82191160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821911F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x82191200;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r19,-32124
	r19.s64 = -2105278464;
	// std r7,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, ctx.r7.u64);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// lwz r11,-13428(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -13428);
	// mr r17,r8
	r17.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// li r21,-1
	r21.s64 = -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191244
	if (cr6.eq) goto loc_82191244;
	// lbz r10,11(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82191244
	if (!cr6.eq) goto loc_82191244;
	// lbz r21,9(r11)
	r21.u64 = PPC_LOAD_U8(r11.u32 + 9);
loc_82191244:
	// lhz r8,26(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// li r20,0
	r20.s64 = 0;
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8219129c
	if (!cr6.gt) goto loc_8219129C;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
loc_8219125C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bge cr6,0x82191280
	if (!cr6.lt) goto loc_82191280;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r7,8(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// lhzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + ctx.r10.u32);
	// rotlwi r5,r6,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lbz r11,9(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// b 0x82191284
	goto loc_82191284;
loc_82191280:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_82191284:
	// cmpw cr6,r11,r18
	cr6.compare<int32_t>(r11.s32, r18.s32, xer);
	// beq cr6,0x8219129c
	if (cr6.eq) goto loc_8219129C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x8219125c
	if (cr6.lt) goto loc_8219125C;
loc_8219129C:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bne cr6,0x821912b0
	if (!cr6.eq) goto loc_821912B0;
loc_821912A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d921c
	return;
loc_821912B0:
	// lbz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821912c8
	if (cr6.eq) goto loc_821912C8;
	// bl 0x821a15b8
	ctx.lr = 0x821912C0;
	sub_821A15B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x821912cc
	goto loc_821912CC;
loc_821912C8:
	// mr r26,r20
	r26.u64 = r20.u64;
loc_821912CC:
	// lbz r11,25(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821912e4
	if (cr6.eq) goto loc_821912E4;
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bgt cr6,0x821912a4
	if (cr6.gt) goto loc_821912A4;
loc_821912E4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r25,r11,-13429
	r25.s64 = r11.s64 + -13429;
	// lwz r3,33(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 33);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82191308
	if (!cr6.eq) goto loc_82191308;
	// addi r4,r25,33
	ctx.r4.s64 = r25.s64 + 33;
	// lis r3,3
	ctx.r3.s64 = 196608;
	// bl 0x82178a10
	ctx.lr = 0x82191304;
	sub_82178A10(ctx, base);
	// lwz r3,33(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 33);
loc_82191308:
	// lbz r11,25(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 25);
	// li r5,0
	ctx.r5.s64 = 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82179c20
	ctx.lr = 0x82191320;
	sub_82179C20(ctx, base);
	// lwz r11,276(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// subf r8,r20,r11
	ctx.r8.s64 = r11.s64 - r20.s64;
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
	// beq cr6,0x82191360
	if (cr6.eq) goto loc_82191360;
	// lwz r3,272(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mtctr r11
	ctr.u64 = r11.u64;
	// beq cr6,0x82191358
	if (cr6.eq) goto loc_82191358;
	// bctrl 
	ctx.lr = 0x82191354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82191384
	goto loc_82191384;
loc_82191358:
	// bctrl 
	ctx.lr = 0x8219135C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82191384
	goto loc_82191384;
loc_82191360:
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x8219136C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x82191378;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x82191384;
	sub_8217F768(ctx, base);
loc_82191384:
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// mr r29,r20
	r29.u64 = r20.u64;
	// li r27,1
	r27.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191450
	if (cr6.eq) goto loc_82191450;
	// mr r28,r20
	r28.u64 = r20.u64;
loc_8219139C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bge cr6,0x821913c0
	if (!cr6.lt) goto loc_821913C0;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r10,8(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// lhzx r9,r11,r28
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + r28.u32);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lbz r11,9(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 9);
	// b 0x821913c4
	goto loc_821913C4;
loc_821913C0:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_821913C4:
	// cmpw cr6,r11,r18
	cr6.compare<int32_t>(r11.s32, r18.s32, xer);
	// bne cr6,0x8219143c
	if (!cr6.eq) goto loc_8219143C;
	// lwz r31,-13428(r19)
	r31.u64 = PPC_LOAD_U32(r19.u32 + -13428);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821913ec
	if (!cr6.eq) goto loc_821913EC;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r10,8(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// lhzx r9,r11,r28
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + r28.u32);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r31,r8,r10
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
loc_821913EC:
	// lbz r11,25(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191424
	if (cr6.eq) goto loc_82191424;
	// li r3,0
	ctx.r3.s64 = 0;
	// slw r4,r27,r29
	ctx.r4.u64 = r29.u8 & 0x20 ? 0 : (r27.u32 << (r29.u8 & 0x3F));
	// bl 0x82178ae0
	ctx.lr = 0x82191404;
	sub_82178AE0(ctx, base);
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82188080
	ctx.lr = 0x82191420;
	sub_82188080(ctx, base);
	// b 0x8219143c
	goto loc_8219143C;
loc_82191424:
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82188000
	ctx.lr = 0x8219143C;
	sub_82188000(ctx, base);
loc_8219143C:
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8219139c
	if (cr6.lt) goto loc_8219139C;
loc_82191450:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178ae0
	ctx.lr = 0x8219145C;
	sub_82178AE0(ctx, base);
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r20.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82179d38
	ctx.lr = 0x82191468;
	sub_82179D38(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r3,0(r17)
	PPC_STORE_U32(r17.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82191480
	if (!cr6.eq) goto loc_82191480;
	// mr r11,r27
	r11.u64 = r27.u64;
	// stb r11,0(r25)
	PPC_STORE_U8(r25.u32 + 0, r11.u8);
loc_82191480:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x82191488;
	sub_82130588(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_821911F8) {
	__imp__sub_821911F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82191494) {
	__imp__sub_82191494(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191498) {
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
	ctx.lr = 0x821914A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821914f8
	if (cr6.eq) goto loc_821914F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821914f8
	if (cr6.eq) goto loc_821914F8;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r29,r11,-4
	r29.s64 = r11.s64 + -4;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addic. r31,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r31.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// blt 0x821914f0
	if (cr0.lt) goto loc_821914F0;
loc_821914D4:
	// addi r30,r30,-8
	r30.s64 = r30.s64 + -8;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821914E0;
	sub_821D2AA0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821914E8;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x821914d4
	if (!cr0.lt) goto loc_821914D4;
loc_821914F0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821914F8;
	sub_82130588(ctx, base);
loc_821914F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82191498) {
	__imp__sub_82191498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191500) {
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
	// bl 0x82191160
	ctx.lr = 0x82191520;
	sub_82191160(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191538
	if (cr6.eq) goto loc_82191538;
	// bl 0x82130588
	ctx.lr = 0x82191534;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82191538:
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

PPC_WEAK_FUNC(sub_82191500) {
	__imp__sub_82191500(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191550) {
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
	ctx.lr = 0x82191558;
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
	// beq cr6,0x82191580
	if (cr6.eq) goto loc_82191580;
	// bl 0x8217d890
	ctx.lr = 0x82191574;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82191580:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191610
	if (cr6.eq) goto loc_82191610;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_821915A0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821915f8
	if (cr6.eq) goto loc_821915F8;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821915f8
	if (cr6.eq) goto loc_821915F8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x821915CC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821915f8
	if (cr6.eq) goto loc_821915F8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x821915E0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x821a15a0
	ctx.lr = 0x821915F4;
	sub_821A15A0(ctx, base);
	// b 0x821915fc
	goto loc_821915FC;
loc_821915F8:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_821915FC:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x821915a0
	if (cr6.lt) goto loc_821915A0;
loc_82191610:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82191550) {
	__imp__sub_82191550(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219161C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219161C) {
	__imp__sub_8219161C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82191628;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r11.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r31,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r31.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82191668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x821916f0
	if (!cr6.gt) goto loc_821916F0;
	// li r23,0
	r23.s64 = 0;
	// mr r24,r31
	r24.u64 = r31.u64;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_82191680:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add. r31,r26,r11
	r31.u64 = r26.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x821916e4
	if (cr0.eq) goto loc_821916E4;
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r27,r28
	r30.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821916e0
	if (cr6.eq) goto loc_821916E0;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821916e0
	if (cr6.eq) goto loc_821916E0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x821916B4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821916e0
	if (cr6.eq) goto loc_821916E0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x821916C8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r28
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// bl 0x821a15a0
	ctx.lr = 0x821916DC;
	sub_821A15A0(ctx, base);
	// b 0x821916e4
	goto loc_821916E4;
loc_821916E0:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_821916E4:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82191680
	if (!cr0.eq) goto loc_82191680;
loc_821916F0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82191620) {
	__imp__sub_82191620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821916F8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,-15580
	ctx.r10.s64 = r11.s64 + -15580;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82191550
	ctx.lr = 0x8219172C;
	sub_82191550(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8219174c
	if (cr6.eq) goto loc_8219174C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82191740;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_8219174C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191778
	if (cr6.eq) goto loc_82191778;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82191778
	if (cr6.eq) goto loc_82191778;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8219176C;
	sub_8217D890(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_82191778:
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

PPC_WEAK_FUNC(sub_821916F8) {
	__imp__sub_821916F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82191794) {
	__imp__sub_82191794(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82191798) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821916f8
	sub_821916F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82191798) {
	__imp__sub_82191798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821917A4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821917A4) {
	__imp__sub_821917A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821917A8) {
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
	PPCRegister f18{};
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
	// bl 0x823d91c0
	ctx.lr = 0x821917B0;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9b0
	ctx.lr = 0x821917B8;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// stw r6,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r6.u32);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r15,r7
	r15.u64 = ctx.r7.u64;
	// lwz r14,4(r19)
	r14.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// bne cr6,0x821917f0
	if (!cr6.eq) goto loc_821917F0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9fc
	ctx.lr = 0x821917EC;
	// b 0x823d9210
	return;
loc_821917F0:
	// lis r11,32767
	r11.s64 = 2147418112;
	// sth r14,26(r18)
	PPC_STORE_U16(r18.u32 + 26, r14.u16);
	// li r30,-1
	r30.s64 = -1;
	// ori r9,r11,65535
	ctx.r9.u64 = r11.u64 | 65535;
	// rlwinm r4,r14,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r14.u32 | (r14.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r14,r9
	cr6.compare<uint32_t>(r14.u32, ctx.r9.u32, xer);
	// ble cr6,0x82191810
	if (!cr6.gt) goto loc_82191810;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_82191810:
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,12
	r28.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r28,r27
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219183C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r18)
	PPC_STORE_U32(r18.u32 + 16, ctx.r3.u32);
	// addi r17,r18,4
	r17.s64 = r18.s64 + 4;
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82191620
	ctx.lr = 0x82191854;
	sub_82191620(ctx, base);
	// lwz r9,16(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 16);
	// lis r29,-32131
	r29.s64 = -2105737216;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stb r8,20(r18)
	PPC_STORE_U8(r18.u32 + 20, ctx.r8.u8);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,25(r18)
	PPC_STORE_U8(r18.u32 + 25, ctx.r5.u8);
	// lbz r4,128(r19)
	ctx.r4.u64 = PPC_LOAD_U8(r19.u32 + 128);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// stb r10,21(r18)
	PPC_STORE_U8(r18.u32 + 21, ctx.r10.u8);
	// lbz r9,128(r19)
	ctx.r9.u64 = PPC_LOAD_U8(r19.u32 + 128);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821918f4
	if (!cr6.eq) goto loc_821918F4;
	// lbz r10,24840(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 24840);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821918f4
	if (cr6.eq) goto loc_821918F4;
	// cmpwi cr6,r14,1
	cr6.compare<int32_t>(r14.s32, 1, xer);
	// ble cr6,0x821918c4
	if (!cr6.gt) goto loc_821918C4;
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// addi r11,r14,1
	r11.s64 = r14.s64 + 1;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bgt cr6,0x821918d0
	if (cr6.gt) goto loc_821918D0;
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x821918d4
	goto loc_821918D4;
loc_821918C4:
	// li r11,1
	r11.s64 = 1;
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x821918d4
	goto loc_821918D4;
loc_821918D0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_821918D4:
	// lwzx r3,r28,r27
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821918F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r18)
	PPC_STORE_U32(r18.u32 + 12, ctx.r3.u32);
loc_821918F4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82191948
	if (cr6.eq) goto loc_82191948;
	// addi r11,r19,48
	r11.s64 = r19.s64 + 48;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r7,112
	ctx.r7.s64 = 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,80
	ctx.r6.s64 = 80;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,64
	ctx.r5.s64 = 64;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r19,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r19,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82191948:
	// lwz r11,12(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 12);
	// li r16,0
	r16.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82191964
	if (!cr6.eq) goto loc_82191964;
	// lbz r10,24840(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 24840);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82191dc4
	if (cr6.eq) goto loc_82191DC4;
loc_82191964:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,4(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// lfs f24,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f24.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f23,-31068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31068);
	f23.f64 = double(temp.f32);
	// fmr f30,f24
	f30.f64 = f24.f64;
	// lfs f6,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f6.f64 = double(temp.f32);
	// fmr f29,f24
	f29.f64 = f24.f64;
	// lfs f22,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f22.f64 = double(temp.f32);
	// fmr f27,f23
	f27.f64 = f23.f64;
	// fmr f26,f23
	f26.f64 = f23.f64;
	// fmr f28,f24
	f28.f64 = f24.f64;
	// fmr f25,f23
	f25.f64 = f23.f64;
	// ble cr6,0x82191d00
	if (!cr6.gt) goto loc_82191D00;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
loc_821919B4:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// fmr f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = f24.f64;
	// fmr f12,f24
	ctx.f12.f64 = f24.f64;
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// add r6,r11,r5
	ctx.r6.u64 = r11.u64 + ctx.r5.u64;
	// fmr f11,f24
	ctx.f11.f64 = f24.f64;
	// fmr f10,f23
	ctx.f10.f64 = f23.f64;
	// fmr f9,f23
	ctx.f9.f64 = f23.f64;
	// fmr f8,f23
	ctx.f8.f64 = f23.f64;
	// lwz r7,44(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// blt cr6,0x82191bc0
	if (cr6.lt) goto loc_82191BC0;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// lwz r11,40(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,260
	r11.s64 = r11.s64 + 260;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_82191A00:
	// lfs f4,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f4.f64 = double(temp.f32);
	// fabs f13,f4
	ctx.f13.u64 = ctx.f4.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191a14
	if (!cr6.gt) goto loc_82191A14;
	// fabs f6,f4
	ctx.f6.u64 = ctx.f4.u64 & ~0x8000000000000000;
loc_82191A14:
	// lfs f5,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fabs f13,f5
	ctx.f13.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191a28
	if (!cr6.gt) goto loc_82191A28;
	// fabs f6,f5
	ctx.f6.u64 = ctx.f5.u64 & ~0x8000000000000000;
loc_82191A28:
	// lfs f7,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fabs f13,f7
	ctx.f13.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191a3c
	if (!cr6.gt) goto loc_82191A3C;
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
loc_82191A3C:
	// lfs f13,252(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 252);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f3,f0,f4
	ctx.f3.f64 = double(float(f0.f64 - ctx.f4.f64));
	// fsubs f2,f12,f5
	ctx.f2.f64 = double(float(ctx.f12.f64 - ctx.f5.f64));
	// fsubs f31,f10,f4
	f31.f64 = double(float(ctx.f10.f64 - ctx.f4.f64));
	// fsubs f1,f11,f7
	ctx.f1.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// fsubs f21,f9,f5
	f21.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// fsubs f20,f8,f7
	f20.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fabs f19,f13
	f19.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fsel f3,f3,f4,f0
	ctx.f3.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : f0.f64;
	// fsel f2,f2,f5,f12
	ctx.f2.f64 = ctx.f2.f64 >= 0.0 ? ctx.f5.f64 : ctx.f12.f64;
	// fsel f4,f31,f10,f4
	ctx.f4.f64 = f31.f64 >= 0.0 ? ctx.f10.f64 : ctx.f4.f64;
	// fsel f1,f1,f7,f11
	ctx.f1.f64 = ctx.f1.f64 >= 0.0 ? ctx.f7.f64 : ctx.f11.f64;
	// fsel f5,f21,f9,f5
	ctx.f5.f64 = f21.f64 >= 0.0 ? ctx.f9.f64 : ctx.f5.f64;
	// fsel f31,f20,f8,f7
	f31.f64 = f20.f64 >= 0.0 ? ctx.f8.f64 : ctx.f7.f64;
	// fcmpu cr6,f19,f6
	cr6.compare(f19.f64, ctx.f6.f64);
	// ble cr6,0x82191a80
	if (!cr6.gt) goto loc_82191A80;
	// fabs f6,f13
	ctx.f6.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_82191A80:
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fabs f0,f11
	f0.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f6
	cr6.compare(f0.f64, ctx.f6.f64);
	// ble cr6,0x82191a94
	if (!cr6.gt) goto loc_82191A94;
	// fabs f6,f11
	ctx.f6.u64 = ctx.f11.u64 & ~0x8000000000000000;
loc_82191A94:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fabs f0,f12
	f0.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f6
	cr6.compare(f0.f64, ctx.f6.f64);
	// ble cr6,0x82191aa8
	if (!cr6.gt) goto loc_82191AA8;
	// fabs f6,f12
	ctx.f6.u64 = ctx.f12.u64 & ~0x8000000000000000;
loc_82191AA8:
	// fsubs f10,f4,f13
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// lfs f0,508(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 508);
	f0.f64 = double(temp.f32);
	// fsubs f9,f3,f13
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fsubs f8,f2,f11
	ctx.f8.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsubs f21,f1,f12
	f21.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsubs f20,f5,f11
	f20.f64 = double(float(ctx.f5.f64 - ctx.f11.f64));
	// fsubs f19,f31,f12
	f19.f64 = double(float(f31.f64 - ctx.f12.f64));
	// fabs f18,f0
	f18.u64 = f0.u64 & ~0x8000000000000000;
	// fsel f7,f10,f4,f13
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// fsel f10,f9,f13,f3
	ctx.f10.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f3.f64;
	// fsel f9,f8,f11,f2
	ctx.f9.f64 = ctx.f8.f64 >= 0.0 ? ctx.f11.f64 : ctx.f2.f64;
	// fsel f8,f21,f12,f1
	ctx.f8.f64 = f21.f64 >= 0.0 ? ctx.f12.f64 : ctx.f1.f64;
	// fsel f5,f20,f5,f11
	ctx.f5.f64 = f20.f64 >= 0.0 ? ctx.f5.f64 : ctx.f11.f64;
	// fsel f4,f19,f31,f12
	ctx.f4.f64 = f19.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fcmpu cr6,f18,f6
	cr6.compare(f18.f64, ctx.f6.f64);
	// ble cr6,0x82191aec
	if (!cr6.gt) goto loc_82191AEC;
	// fabs f6,f0
	ctx.f6.u64 = f0.u64 & ~0x8000000000000000;
loc_82191AEC:
	// lfs f11,256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 256);
	ctx.f11.f64 = double(temp.f32);
	// fabs f13,f11
	ctx.f13.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191b00
	if (!cr6.gt) goto loc_82191B00;
	// fabs f6,f11
	ctx.f6.u64 = ctx.f11.u64 & ~0x8000000000000000;
loc_82191B00:
	// lfs f12,260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 260);
	ctx.f12.f64 = double(temp.f32);
	// fabs f13,f12
	ctx.f13.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191b14
	if (!cr6.gt) goto loc_82191B14;
	// fabs f6,f12
	ctx.f6.u64 = ctx.f12.u64 & ~0x8000000000000000;
loc_82191B14:
	// lfs f13,764(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 764);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f2,f9,f11
	ctx.f2.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fsubs f1,f8,f12
	ctx.f1.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fsubs f31,f7,f0
	f31.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsubs f21,f5,f11
	f21.f64 = double(float(ctx.f5.f64 - ctx.f11.f64));
	// fsubs f20,f4,f12
	f20.f64 = double(float(ctx.f4.f64 - ctx.f12.f64));
	// fabs f19,f13
	f19.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fsel f10,f3,f0,f10
	ctx.f10.f64 = ctx.f3.f64 >= 0.0 ? f0.f64 : ctx.f10.f64;
	// fsel f3,f2,f11,f9
	ctx.f3.f64 = ctx.f2.f64 >= 0.0 ? ctx.f11.f64 : ctx.f9.f64;
	// fsel f2,f1,f12,f8
	ctx.f2.f64 = ctx.f1.f64 >= 0.0 ? ctx.f12.f64 : ctx.f8.f64;
	// fsel f7,f31,f7,f0
	ctx.f7.f64 = f31.f64 >= 0.0 ? ctx.f7.f64 : f0.f64;
	// fsel f5,f21,f5,f11
	ctx.f5.f64 = f21.f64 >= 0.0 ? ctx.f5.f64 : ctx.f11.f64;
	// fsel f4,f20,f4,f12
	ctx.f4.f64 = f20.f64 >= 0.0 ? ctx.f4.f64 : ctx.f12.f64;
	// fcmpu cr6,f19,f6
	cr6.compare(f19.f64, ctx.f6.f64);
	// ble cr6,0x82191b58
	if (!cr6.gt) goto loc_82191B58;
	// fabs f6,f13
	ctx.f6.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_82191B58:
	// lfs f9,512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 512);
	ctx.f9.f64 = double(temp.f32);
	// fabs f0,f9
	f0.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f6
	cr6.compare(f0.f64, ctx.f6.f64);
	// ble cr6,0x82191b6c
	if (!cr6.gt) goto loc_82191B6C;
	// fabs f6,f9
	ctx.f6.u64 = ctx.f9.u64 & ~0x8000000000000000;
loc_82191B6C:
	// lfs f8,516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 516);
	ctx.f8.f64 = double(temp.f32);
	// fabs f0,f8
	f0.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f6
	cr6.compare(f0.f64, ctx.f6.f64);
	// ble cr6,0x82191b80
	if (!cr6.gt) goto loc_82191B80;
	// fabs f6,f8
	ctx.f6.u64 = ctx.f8.u64 & ~0x8000000000000000;
loc_82191B80:
	// fsubs f0,f10,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fsubs f12,f3,f9
	ctx.f12.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// addi r10,r10,1024
	ctx.r10.s64 = ctx.r10.s64 + 1024;
	// fsubs f11,f2,f8
	ctx.f11.f64 = double(float(ctx.f2.f64 - ctx.f8.f64));
	// addi r11,r11,1024
	r11.s64 = r11.s64 + 1024;
	// fsubs f1,f7,f13
	ctx.f1.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fsubs f31,f5,f9
	f31.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// fsubs f21,f4,f8
	f21.f64 = double(float(ctx.f4.f64 - ctx.f8.f64));
	// fsel f0,f0,f13,f10
	f0.f64 = f0.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// fsel f12,f12,f9,f3
	ctx.f12.f64 = ctx.f12.f64 >= 0.0 ? ctx.f9.f64 : ctx.f3.f64;
	// fsel f11,f11,f8,f2
	ctx.f11.f64 = ctx.f11.f64 >= 0.0 ? ctx.f8.f64 : ctx.f2.f64;
	// fsel f10,f1,f7,f13
	ctx.f10.f64 = ctx.f1.f64 >= 0.0 ? ctx.f7.f64 : ctx.f13.f64;
	// fsel f9,f31,f5,f9
	ctx.f9.f64 = f31.f64 >= 0.0 ? ctx.f5.f64 : ctx.f9.f64;
	// fsel f8,f21,f4,f8
	ctx.f8.f64 = f21.f64 >= 0.0 ? ctx.f4.f64 : ctx.f8.f64;
	// bne 0x82191a00
	if (!cr0.eq) goto loc_82191A00;
loc_82191BC0:
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// bge cr6,0x82191c50
	if (!cr6.lt) goto loc_82191C50;
	// lwz r10,40(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// rlwinm r11,r8,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// subf r9,r8,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_82191BD8:
	// lfs f5,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fabs f13,f5
	ctx.f13.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191bec
	if (!cr6.gt) goto loc_82191BEC;
	// fabs f6,f5
	ctx.f6.u64 = ctx.f5.u64 & ~0x8000000000000000;
loc_82191BEC:
	// lfs f7,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fabs f13,f7
	ctx.f13.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f6
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x82191c00
	if (!cr6.gt) goto loc_82191C00;
	// fabs f6,f7
	ctx.f6.u64 = ctx.f7.u64 & ~0x8000000000000000;
loc_82191C00:
	// lfs f13,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fabs f4,f13
	ctx.f4.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f6
	cr6.compare(ctx.f4.f64, ctx.f6.f64);
	// ble cr6,0x82191c14
	if (!cr6.gt) goto loc_82191C14;
	// fabs f6,f13
	ctx.f6.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_82191C14:
	// fsubs f4,f0,f5
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f0.f64 - ctx.f5.f64));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fsubs f3,f12,f7
	ctx.f3.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// addi r11,r11,256
	r11.s64 = r11.s64 + 256;
	// fsubs f2,f11,f13
	ctx.f2.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f1,f10,f5
	ctx.f1.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// fsubs f31,f9,f7
	f31.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// fsubs f21,f8,f13
	f21.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f0,f4,f5,f0
	f0.f64 = ctx.f4.f64 >= 0.0 ? ctx.f5.f64 : f0.f64;
	// fsel f12,f3,f7,f12
	ctx.f12.f64 = ctx.f3.f64 >= 0.0 ? ctx.f7.f64 : ctx.f12.f64;
	// fsel f11,f2,f13,f11
	ctx.f11.f64 = ctx.f2.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// fsel f10,f1,f10,f5
	ctx.f10.f64 = ctx.f1.f64 >= 0.0 ? ctx.f10.f64 : ctx.f5.f64;
	// fsel f9,f31,f9,f7
	ctx.f9.f64 = f31.f64 >= 0.0 ? ctx.f9.f64 : ctx.f7.f64;
	// fsel f8,f21,f8,f13
	ctx.f8.f64 = f21.f64 >= 0.0 ? ctx.f8.f64 : ctx.f13.f64;
	// bne 0x82191bd8
	if (!cr0.eq) goto loc_82191BD8;
loc_82191C50:
	// lwz r11,12(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191cb8
	if (cr6.eq) goto loc_82191CB8;
	// lhz r10,26(r18)
	ctx.r10.u64 = PPC_LOAD_U16(r18.u32 + 26);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// ble cr6,0x82191cb8
	if (!cr6.gt) goto loc_82191CB8;
	// fsubs f13,f12,f9
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// fadds f4,f10,f0
	ctx.f4.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fadds f3,f9,f12
	ctx.f3.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// fadds f2,f8,f11
	ctx.f2.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// fsubs f5,f0,f10
	ctx.f5.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fmuls f1,f13,f13
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmuls f13,f4,f22
	ctx.f13.f64 = double(float(ctx.f4.f64 * f22.f64));
	// stfs f13,16(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// fmuls f4,f3,f22
	ctx.f4.f64 = double(float(ctx.f3.f64 * f22.f64));
	// stfs f4,20(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// fmuls f3,f2,f22
	ctx.f3.f64 = double(float(ctx.f2.f64 * f22.f64));
	// stfs f3,24(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// fmadds f2,f7,f7,f1
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f1.f64));
	// fmadds f1,f5,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fsqrts f13,f1
	ctx.f13.f64 = double(float(sqrt(ctx.f1.f64)));
	// fmuls f7,f13,f22
	ctx.f7.f64 = double(float(ctx.f13.f64 * f22.f64));
	// stfs f7,28(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
loc_82191CB8:
	// fsubs f13,f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f0.f64));
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// fsubs f7,f29,f12
	ctx.f7.f64 = double(float(f29.f64 - ctx.f12.f64));
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// fsubs f5,f28,f11
	ctx.f5.f64 = double(float(f28.f64 - ctx.f11.f64));
	// addi r5,r5,64
	ctx.r5.s64 = ctx.r5.s64 + 64;
	// fsubs f4,f27,f10
	ctx.f4.f64 = double(float(f27.f64 - ctx.f10.f64));
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// fsubs f3,f26,f9
	ctx.f3.f64 = double(float(f26.f64 - ctx.f9.f64));
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// fsubs f2,f25,f8
	ctx.f2.f64 = double(float(f25.f64 - ctx.f8.f64));
	// fsel f30,f13,f0,f30
	f30.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fsel f29,f7,f12,f29
	f29.f64 = ctx.f7.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fsel f28,f5,f11,f28
	f28.f64 = ctx.f5.f64 >= 0.0 ? ctx.f11.f64 : f28.f64;
	// fsel f27,f4,f27,f10
	f27.f64 = ctx.f4.f64 >= 0.0 ? f27.f64 : ctx.f10.f64;
	// fsel f26,f3,f26,f9
	f26.f64 = ctx.f3.f64 >= 0.0 ? f26.f64 : ctx.f9.f64;
	// fsel f25,f2,f25,f8
	f25.f64 = ctx.f2.f64 >= 0.0 ? f25.f64 : ctx.f8.f64;
	// blt cr6,0x821919b4
	if (cr6.lt) goto loc_821919B4;
loc_82191D00:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r9,r11,24864
	ctx.r9.s64 = r11.s64 + 24864;
	// addi r8,r10,24848
	ctx.r8.s64 = ctx.r10.s64 + 24848;
	// lfs f11,24864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24864);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,24848(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24848);
	f0.f64 = double(temp.f32);
	// fsubs f8,f11,f27
	ctx.f8.f64 = double(float(ctx.f11.f64 - f27.f64));
	// lfs f10,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f7,f0,f30
	ctx.f7.f64 = double(float(f0.f64 - f30.f64));
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f6,f10,f26
	ctx.f6.f64 = double(float(ctx.f10.f64 - f26.f64));
	// fsubs f5,f13,f29
	ctx.f5.f64 = double(float(ctx.f13.f64 - f29.f64));
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f4,f12,f28
	ctx.f4.f64 = double(float(ctx.f12.f64 - f28.f64));
	// fsubs f3,f9,f25
	ctx.f3.f64 = double(float(ctx.f9.f64 - f25.f64));
	// fsel f11,f8,f11,f27
	ctx.f11.f64 = ctx.f8.f64 >= 0.0 ? ctx.f11.f64 : f27.f64;
	// stfs f11,24864(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 24864, temp.u32);
	// fsel f0,f7,f30,f0
	f0.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : f0.f64;
	// stfs f0,24848(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24848, temp.u32);
	// fsel f0,f6,f10,f26
	f0.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : f26.f64;
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fsel f0,f5,f29,f13
	f0.f64 = ctx.f5.f64 >= 0.0 ? f29.f64 : ctx.f13.f64;
	// stfs f0,4(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// fsel f0,f4,f28,f12
	f0.f64 = ctx.f4.f64 >= 0.0 ? f28.f64 : ctx.f12.f64;
	// stfs f0,8(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8, temp.u32);
	// fsel f0,f3,f9,f25
	f0.f64 = ctx.f3.f64 >= 0.0 ? ctx.f9.f64 : f25.f64;
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lwz r11,12(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191dc4
	if (cr6.eq) goto loc_82191DC4;
	// fsubs f0,f29,f26
	f0.f64 = double(float(f29.f64 - f26.f64));
	// fsubs f13,f28,f25
	ctx.f13.f64 = double(float(f28.f64 - f25.f64));
	// fsubs f12,f30,f27
	ctx.f12.f64 = double(float(f30.f64 - f27.f64));
	// fadds f11,f27,f30
	ctx.f11.f64 = double(float(f27.f64 + f30.f64));
	// fadds f10,f26,f29
	ctx.f10.f64 = double(float(f26.f64 + f29.f64));
	// fadds f9,f25,f28
	ctx.f9.f64 = double(float(f25.f64 + f28.f64));
	// fmuls f8,f0,f0
	ctx.f8.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f7,f11,f22
	ctx.f7.f64 = double(float(ctx.f11.f64 * f22.f64));
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmuls f6,f10,f22
	ctx.f6.f64 = double(float(ctx.f10.f64 * f22.f64));
	// stfs f6,4(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmuls f5,f9,f22
	ctx.f5.f64 = double(float(ctx.f9.f64 * f22.f64));
	// stfs f5,8(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmadds f4,f13,f13,f8
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f3,f12,f12,f4
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fmuls f1,f2,f22
	ctx.f1.f64 = double(float(ctx.f2.f64 * f22.f64));
	// stfs f1,12(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
loc_82191DC4:
	// mr r23,r16
	r23.u64 = r16.u64;
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// ble cr6,0x82192138
	if (!cr6.gt) goto loc_82192138;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r26,r16
	r26.u64 = r16.u64;
	// mr r21,r16
	r21.u64 = r16.u64;
	// mr r20,r16
	r20.u64 = r16.u64;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r25,-32124
	r25.s64 = -2105278464;
	// lis r24,-32124
	r24.s64 = -2105278464;
	// lis r22,-32131
	r22.s64 = -2105737216;
	// addi r31,r11,-12088
	r31.s64 = r11.s64 + -12088;
loc_82191E00:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwzx r3,r11,r20
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r20.u32);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,35
	cr6.compare<uint32_t>(ctx.r10.u32, 35, xer);
	// bne cr6,0x82191e18
	if (!cr6.eq) goto loc_82191E18;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82191E18:
	// bl 0x823dd7f0
	ctx.lr = 0x82191E1C;
	sub_823DD7F0(ctx, base);
	// lwz r11,16(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 16);
	// li r4,58
	ctx.r4.s64 = 58;
	// sthx r3,r21,r11
	PPC_STORE_U16(r21.u32 + r11.u32, ctx.r3.u16);
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwzx r3,r11,r20
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r20.u32);
	// bl 0x823dd850
	ctx.lr = 0x82191E34;
	sub_823DD850(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82191e48
	if (cr6.eq) goto loc_82191E48;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bl 0x823dd7f0
	ctx.lr = 0x82191E44;
	sub_823DD7F0(ctx, base);
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
loc_82191E48:
	// lwz r10,396(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82191e90
	if (cr6.eq) goto loc_82191E90;
	// lwz r11,16(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 16);
	// lhz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// lhzx r11,r21,r11
	r11.u64 = PPC_LOAD_U16(r21.u32 + r11.u32);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// ble cr6,0x82191e90
	if (!cr6.gt) goto loc_82191E90;
	// lwz r10,64(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82191e84
	if (cr6.eq) goto loc_82191E84;
	// mr r15,r11
	r15.u64 = r11.u64;
	// b 0x82191e90
	goto loc_82191E90;
loc_82191E84:
	// lwz r11,24844(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 24844);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82191e98
	if (cr6.eq) goto loc_82191E98;
loc_82191E90:
	// cmpwi cr6,r15,-1
	cr6.compare<int32_t>(r15.s32, -1, xer);
	// bne cr6,0x82191e9c
	if (!cr6.eq) goto loc_82191E9C;
loc_82191E98:
	// li r15,89
	r15.s64 = 89;
loc_82191E9C:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// stwx r16,r26,r11
	PPC_STORE_U32(r26.u32 + r11.u32, r16.u32);
	// lwz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lwzx r9,r26,r10
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82192120
	if (!cr6.eq) goto loc_82192120;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,76
	ctx.r4.s64 = 76;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82191EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82191eec
	if (cr6.eq) goto loc_82191EEC;
	// bl 0x821a1308
	ctx.lr = 0x82191EE8;
	sub_821A1308(ctx, base);
	// b 0x82191ef0
	goto loc_82191EF0;
loc_82191EEC:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
loc_82191EF0:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// stwx r3,r26,r11
	PPC_STORE_U32(r26.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lwz r11,24844(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 24844);
	// and r6,r11,r15
	ctx.r6.u64 = r11.u64 & r15.u64;
	// lwzx r3,r26,r10
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82191F20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-13420(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -13420);
	// lwz r9,-13400(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + -13400);
	// mr r7,r16
	ctx.r7.u64 = r16.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,-13416(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -13416);
	// lwz r4,-13412(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -13412);
	// lwz r6,-13408(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + -13408);
	// lwz r5,-13404(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -13404);
	// stw r11,-13420(r24)
	PPC_STORE_U32(r24.u32 + -13420, r11.u32);
loc_82191F44:
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lwzx r11,r8,r31
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// bne cr6,0x82191f60
	if (!cr6.eq) goto loc_82191F60;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// b 0x82191fa4
	goto loc_82191FA4;
loc_82191F60:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x82191f70
	if (!cr6.eq) goto loc_82191F70;
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// b 0x82191fa4
	goto loc_82191FA4;
loc_82191F70:
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// beq cr6,0x82191fa0
	if (cr6.eq) goto loc_82191FA0;
	// cmpwi cr6,r7,15
	cr6.compare<int32_t>(ctx.r7.s32, 15, xer);
	// beq cr6,0x82191fa0
	if (cr6.eq) goto loc_82191FA0;
	// cmpwi cr6,r7,14
	cr6.compare<int32_t>(ctx.r7.s32, 14, xer);
	// beq cr6,0x82191fa0
	if (cr6.eq) goto loc_82191FA0;
	// cmpwi cr6,r7,6
	cr6.compare<int32_t>(ctx.r7.s32, 6, xer);
	// blt cr6,0x82191fa4
	if (cr6.lt) goto loc_82191FA4;
	// cmpwi cr6,r7,13
	cr6.compare<int32_t>(ctx.r7.s32, 13, xer);
	// bgt cr6,0x82191fa4
	if (cr6.gt) goto loc_82191FA4;
	// add r5,r11,r5
	ctx.r5.u64 = r11.u64 + ctx.r5.u64;
	// b 0x82191fa4
	goto loc_82191FA4;
loc_82191FA0:
	// add r6,r11,r6
	ctx.r6.u64 = r11.u64 + ctx.r6.u64;
loc_82191FA4:
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bne cr6,0x82191fc8
	if (!cr6.eq) goto loc_82191FC8;
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r3,-13416(r27)
	PPC_STORE_U32(r27.u32 + -13416, ctx.r3.u32);
	// b 0x82192018
	goto loc_82192018;
loc_82191FC8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82191fdc
	if (!cr6.eq) goto loc_82191FDC;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r4,-13412(r28)
	PPC_STORE_U32(r28.u32 + -13412, ctx.r4.u32);
	// b 0x82192018
	goto loc_82192018;
loc_82191FDC:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82192010
	if (cr6.eq) goto loc_82192010;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// beq cr6,0x82192010
	if (cr6.eq) goto loc_82192010;
	// cmpwi cr6,r11,14
	cr6.compare<int32_t>(r11.s32, 14, xer);
	// beq cr6,0x82192010
	if (cr6.eq) goto loc_82192010;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// blt cr6,0x82192018
	if (cr6.lt) goto loc_82192018;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bgt cr6,0x82192018
	if (cr6.gt) goto loc_82192018;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r5,-13404(r30)
	PPC_STORE_U32(r30.u32 + -13404, ctx.r5.u32);
	// b 0x82192018
	goto loc_82192018;
loc_82192010:
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r6,-13408(r29)
	PPC_STORE_U32(r29.u32 + -13408, ctx.r6.u32);
loc_82192018:
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// addi r11,r7,2
	r11.s64 = ctx.r7.s64 + 2;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bne cr6,0x8219203c
	if (!cr6.eq) goto loc_8219203C;
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r3,-13416(r27)
	PPC_STORE_U32(r27.u32 + -13416, ctx.r3.u32);
	// b 0x8219208c
	goto loc_8219208C;
loc_8219203C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82192050
	if (!cr6.eq) goto loc_82192050;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r4,-13412(r28)
	PPC_STORE_U32(r28.u32 + -13412, ctx.r4.u32);
	// b 0x8219208c
	goto loc_8219208C;
loc_82192050:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82192084
	if (cr6.eq) goto loc_82192084;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// beq cr6,0x82192084
	if (cr6.eq) goto loc_82192084;
	// cmpwi cr6,r11,14
	cr6.compare<int32_t>(r11.s32, 14, xer);
	// beq cr6,0x82192084
	if (cr6.eq) goto loc_82192084;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// blt cr6,0x8219208c
	if (cr6.lt) goto loc_8219208C;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bgt cr6,0x8219208c
	if (cr6.gt) goto loc_8219208C;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r5,-13404(r30)
	PPC_STORE_U32(r30.u32 + -13404, ctx.r5.u32);
	// b 0x8219208c
	goto loc_8219208C;
loc_82192084:
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r6,-13408(r29)
	PPC_STORE_U32(r29.u32 + -13408, ctx.r6.u32);
loc_8219208C:
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// addi r11,r7,3
	r11.s64 = ctx.r7.s64 + 3;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bne cr6,0x821920b0
	if (!cr6.eq) goto loc_821920B0;
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r3,-13416(r27)
	PPC_STORE_U32(r27.u32 + -13416, ctx.r3.u32);
	// b 0x82192100
	goto loc_82192100;
loc_821920B0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821920c4
	if (!cr6.eq) goto loc_821920C4;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r4,-13412(r28)
	PPC_STORE_U32(r28.u32 + -13412, ctx.r4.u32);
	// b 0x82192100
	goto loc_82192100;
loc_821920C4:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x821920f8
	if (cr6.eq) goto loc_821920F8;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// beq cr6,0x821920f8
	if (cr6.eq) goto loc_821920F8;
	// cmpwi cr6,r11,14
	cr6.compare<int32_t>(r11.s32, 14, xer);
	// beq cr6,0x821920f8
	if (cr6.eq) goto loc_821920F8;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// blt cr6,0x82192100
	if (cr6.lt) goto loc_82192100;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bgt cr6,0x82192100
	if (cr6.gt) goto loc_82192100;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r5,-13404(r30)
	PPC_STORE_U32(r30.u32 + -13404, ctx.r5.u32);
	// b 0x82192100
	goto loc_82192100;
loc_821920F8:
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r6,-13408(r29)
	PPC_STORE_U32(r29.u32 + -13408, ctx.r6.u32);
loc_82192100:
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpwi cr6,r7,16
	cr6.compare<int32_t>(ctx.r7.s32, 16, xer);
	// blt cr6,0x82191f44
	if (cr6.lt) goto loc_82191F44;
	// stw r9,-13400(r25)
	PPC_STORE_U32(r25.u32 + -13400, ctx.r9.u32);
	// stw r6,-13408(r29)
	PPC_STORE_U32(r29.u32 + -13408, ctx.r6.u32);
	// stw r5,-13404(r30)
	PPC_STORE_U32(r30.u32 + -13404, ctx.r5.u32);
	// stw r4,-13412(r28)
	PPC_STORE_U32(r28.u32 + -13412, ctx.r4.u32);
	// stw r3,-13416(r27)
	PPC_STORE_U32(r27.u32 + -13416, ctx.r3.u32);
loc_82192120:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r20,r20,64
	r20.s64 = r20.s64 + 64;
	// addi r21,r21,2
	r21.s64 = r21.s64 + 2;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r23,r14
	cr6.compare<int32_t>(r23.s32, r14.s32, xer);
	// blt cr6,0x82191e00
	if (cr6.lt) goto loc_82191E00;
loc_82192138:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9fc
	ctx.lr = 0x82192148;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_821917A8) {
	__imp__sub_821917A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219214C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219214C) {
	__imp__sub_8219214C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192150) {
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
	ctx.lr = 0x82192158;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82192198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821921e4
	if (cr6.eq) goto loc_821921E4;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-15580
	ctx.r9.s64 = ctx.r10.s64 + -15580;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// stb r11,23(r3)
	PPC_STORE_U8(ctx.r3.u32 + 23, r11.u8);
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, r11.u8);
	// stb r11,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, r11.u8);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// b 0x821921e8
	goto loc_821921E8;
loc_821921E4:
	// li r31,0
	r31.s64 = 0;
loc_821921E8:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821917a8
	ctx.lr = 0x82192200;
	sub_821917A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82192238
	if (!cr6.eq) goto loc_82192238;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8219222c
	if (cr6.eq) goto loc_8219222C;
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
	ctx.lr = 0x8219222C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8219222C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82192238:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82192244
	if (cr6.eq) goto loc_82192244;
	// stb r26,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r26.u8);
loc_82192244:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82192150) {
	__imp__sub_82192150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192250) {
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
	ctx.lr = 0x82192258;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r26,0,30,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192374
	if (cr6.eq) goto loc_82192374;
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// addi r27,r31,-4
	r27.s64 = r31.s64 + -4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addic. r29,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r29.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// blt 0x82192354
	if (cr0.lt) goto loc_82192354;
	// addi r31,r28,36
	r31.s64 = r28.s64 + 36;
loc_8219228C:
	// addi r31,r31,-64
	r31.s64 = r31.s64 + -64;
	// addi r28,r28,-64
	r28.s64 = r28.s64 + -64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821922cc
	if (cr6.eq) goto loc_821922CC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821922cc
	if (cr6.eq) goto loc_821922CC;
	// lis r11,-32231
	r11.s64 = -2112290816;
	// lwz r5,-16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r6,r11,2128
	ctx.r6.s64 = r11.s64 + 2128;
	// addi r30,r3,-16
	r30.s64 = ctx.r3.s64 + -16;
	// bl 0x82130630
	ctx.lr = 0x821922C4;
	sub_82130630(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821922CC;
	sub_82130588(ctx, base);
loc_821922CC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82192304
	if (cr6.eq) goto loc_82192304;
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82192304
	if (cr6.eq) goto loc_82192304;
	// lis r11,-32231
	r11.s64 = -2112290816;
	// lwz r5,-4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r6,r11,2152
	ctx.r6.s64 = r11.s64 + 2152;
	// addi r30,r3,-4
	r30.s64 = ctx.r3.s64 + -4;
	// bl 0x82130630
	ctx.lr = 0x821922FC;
	sub_82130630(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82192304;
	sub_82130588(ctx, base);
loc_82192304:
	// lwz r11,-12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8219233c
	if (cr6.eq) goto loc_8219233C;
	// lwz r3,-20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8219233c
	if (cr6.eq) goto loc_8219233C;
	// lis r11,-32231
	r11.s64 = -2112290816;
	// lwz r5,-4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r6,r11,2232
	ctx.r6.s64 = r11.s64 + 2232;
	// addi r30,r3,-4
	r30.s64 = ctx.r3.s64 + -4;
	// bl 0x82130630
	ctx.lr = 0x82192334;
	sub_82130630(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8219233C;
	sub_82130588(ctx, base);
loc_8219233C:
	// addi r3,r31,-32
	ctx.r3.s64 = r31.s64 + -32;
	// bl 0x8219d500
	ctx.lr = 0x82192344;
	sub_8219D500(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8219234C;
	sub_821D2AA0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x8219228c
	if (!cr0.lt) goto loc_8219228C;
loc_82192354:
	// clrlwi r11,r26,31
	r11.u64 = r26.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192368
	if (cr6.eq) goto loc_82192368;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x82192368;
	sub_82130588(ctx, base);
loc_82192368:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82192374:
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82190fd0
	ctx.lr = 0x8219237C;
	sub_82190FD0(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x82190f68
	ctx.lr = 0x82192384;
	sub_82190F68(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82191498
	ctx.lr = 0x8219238C;
	sub_82191498(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8219d500
	ctx.lr = 0x82192394;
	sub_8219D500(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8219239C;
	sub_821D2AA0(ctx, base);
	// clrlwi r11,r26,31
	r11.u64 = r26.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821923b0
	if (cr6.eq) goto loc_821923B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821923B0;
	sub_82130588(ctx, base);
loc_821923B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82192250) {
	__imp__sub_82192250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821923BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821923BC) {
	__imp__sub_821923BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821923C0) {
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
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// bl 0x82190a98
	ctx.lr = 0x821923E4;
	sub_82190A98(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821923f8
	if (cr6.eq) goto loc_821923F8;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x821923F8;
	sub_82130588(ctx, base);
loc_821923F8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82192418
	if (cr6.eq) goto loc_82192418;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82192418
	if (cr6.eq) goto loc_82192418;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82192250
	ctx.lr = 0x82192418;
	sub_82192250(ctx, base);
loc_82192418:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192430
	if (cr6.eq) goto loc_82192430;
	// bl 0x82130588
	ctx.lr = 0x8219242C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82192430:
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

PPC_WEAK_FUNC(sub_821923C0) {
	__imp__sub_821923C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192448) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82192450;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,0
	r24.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r23,r24
	r23.u64 = r24.u64;
	// bl 0x821bbea8
	ctx.lr = 0x82192474;
	sub_821BBEA8(ctx, base);
	// li r3,1184
	ctx.r3.s64 = 1184;
	// bl 0x82130528
	ctx.lr = 0x8219247C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82192494
	if (cr6.eq) goto loc_82192494;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8219e268
	ctx.lr = 0x8219248C;
	sub_8219E268(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82192498
	goto loc_82192498;
loc_82192494:
	// mr r31,r24
	r31.u64 = r24.u64;
loc_82192498:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r11,-15576
	ctx.r5.s64 = r11.s64 + -15576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82191040
	ctx.lr = 0x821924AC;
	sub_82191040(ctx, base);
	// clrlwi r30,r3,24
	r30.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821924f4
	if (cr6.eq) goto loc_821924F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8219bac8
	ctx.lr = 0x821924C0;
	sub_8219BAC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8219bb18
	ctx.lr = 0x821924C8;
	sub_8219BB18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8219bb68
	ctx.lr = 0x821924D0;
	sub_8219BB68(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-13424(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -13424);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821924f4
	if (cr6.eq) goto loc_821924F4;
	// lis r11,-32231
	r11.s64 = -2112290816;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,2360
	ctx.r4.s64 = r11.s64 + 2360;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8219e308
	ctx.lr = 0x821924F4;
	sub_8219E308(ctx, base);
loc_821924F4:
	// bl 0x821bbf00
	ctx.lr = 0x821924F8;
	sub_821BBF00(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82192584
	if (cr6.eq) goto loc_82192584;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-13372
	r11.s64 = r11.s64 + -13372;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r10,r24,r10
	ctx.r10.s64 = ctx.r10.s64 - r24.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82192568
	if (cr6.eq) goto loc_82192568;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8219254c
	if (cr6.eq) goto loc_8219254C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82192548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8219255c
	goto loc_8219255C;
loc_8219254C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8219255C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8219255C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192584
	if (cr6.eq) goto loc_82192584;
loc_82192568:
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82192150
	ctx.lr = 0x82192580;
	sub_82192150(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
loc_82192584:
	// bl 0x821bbea8
	ctx.lr = 0x82192588;
	sub_821BBEA8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-13364
	r11.s64 = r11.s64 + -13364;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r10,r24,r10
	ctx.r10.s64 = ctx.r10.s64 - r24.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821925f0
	if (cr6.eq) goto loc_821925F0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821925d4
	if (cr6.eq) goto loc_821925D4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821925D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821925e4
	goto loc_821925E4;
loc_821925D4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821925E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821925E4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192604
	if (cr6.eq) goto loc_82192604;
loc_821925F0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82192604
	if (cr6.eq) goto loc_82192604;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821923c0
	ctx.lr = 0x82192604;
	sub_821923C0(ctx, base);
loc_82192604:
	// bl 0x821bbf00
	ctx.lr = 0x82192608;
	sub_821BBF00(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82192448) {
	__imp__sub_82192448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192614) {
	__imp__sub_82192614(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192618) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192658
	if (cr6.eq) goto loc_82192658;
	// lis r11,0
	r11.s64 = 0;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
loc_82192640:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82192640
	if (!cr6.eq) goto loc_82192640;
loc_82192658:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82192660;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_82192618) {
	__imp__sub_82192618(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192680) {
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
	ctx.lr = 0x82192688;
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
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821926f0
	if (cr6.eq) goto loc_821926F0;
	// li r31,0
	r31.s64 = 0;
loc_821926A8:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821926dc
	if (cr6.eq) goto loc_821926DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821926C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823db730
	ctx.lr = 0x821926D4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821926fc
	if (cr6.eq) goto loc_821926FC;
loc_821926DC:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x821926a8
	if (cr6.lt) goto loc_821926A8;
loc_821926F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821926FC:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82192680) {
	__imp__sub_82192680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192710) {
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
	ctx.lr = 0x82192718;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8219278c
	if (cr6.eq) goto loc_8219278C;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x8219278c
	if (cr6.gt) goto loc_8219278C;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8219278c
	if (!cr6.gt) goto loc_8219278C;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82192750:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82192780
	if (cr6.eq) goto loc_82192780;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82192780;
	sub_82189CE0(ctx, base);
loc_82192780:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82192750
	if (!cr0.eq) goto loc_82192750;
loc_8219278C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192710) {
	__imp__sub_82192710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192794) {
	__imp__sub_82192794(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192798) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x821927A0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82192828
	if (cr6.eq) goto loc_82192828;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x82192828
	if (cr6.gt) goto loc_82192828;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82192828
	if (!cr6.gt) goto loc_82192828;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_821927DC:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8219281c
	if (cr6.eq) goto loc_8219281C;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8219281C;
	sub_8218A6E0(ctx, base);
loc_8219281C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x821927dc
	if (!cr0.eq) goto loc_821927DC;
loc_82192828:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82192798) {
	__imp__sub_82192798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192834) {
	__imp__sub_82192834(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192838) {
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
	ctx.lr = 0x82192840;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821928c4
	if (cr6.eq) goto loc_821928C4;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x821928c4
	if (cr6.gt) goto loc_821928C4;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821928c4
	if (!cr6.gt) goto loc_821928C4;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8219287C:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821928b8
	if (cr6.eq) goto loc_821928B8;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,2
	ctx.r9.s64 = 2;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x821928B8;
	sub_8218A6E0(ctx, base);
loc_821928B8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8219287c
	if (!cr0.eq) goto loc_8219287C;
loc_821928C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82192838) {
	__imp__sub_82192838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821928CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821928CC) {
	__imp__sub_821928CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821928D0) {
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
	ctx.lr = 0x821928D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82192958
	if (cr6.eq) goto loc_82192958;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x82192958
	if (cr6.gt) goto loc_82192958;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82192958
	if (!cr6.gt) goto loc_82192958;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82192910:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8219294c
	if (cr6.eq) goto loc_8219294C;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,8
	ctx.r7.s64 = 8;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8219294C;
	sub_8218A6E0(ctx, base);
loc_8219294C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82192910
	if (!cr0.eq) goto loc_82192910;
loc_82192958:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_821928D0) {
	__imp__sub_821928D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192960) {
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
	ctx.lr = 0x82192968;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821929e8
	if (cr6.eq) goto loc_821929E8;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x821929e8
	if (cr6.gt) goto loc_821929E8;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821929e8
	if (!cr6.gt) goto loc_821929E8;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_821929A0:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821929dc
	if (cr6.eq) goto loc_821929DC;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x821929DC;
	sub_8218A6E0(ctx, base);
loc_821929DC:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x821929a0
	if (!cr0.eq) goto loc_821929A0;
loc_821929E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192960) {
	__imp__sub_82192960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821929F0) {
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
	ctx.lr = 0x821929F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82192a7c
	if (cr6.eq) goto loc_82192A7C;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x82192a7c
	if (cr6.gt) goto loc_82192A7C;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82192a7c
	if (!cr6.gt) goto loc_82192A7C;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82192A34:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82192a70
	if (cr6.eq) goto loc_82192A70;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,4
	ctx.r9.s64 = 4;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82192A70;
	sub_8218A6E0(ctx, base);
loc_82192A70:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82192a34
	if (!cr0.eq) goto loc_82192A34;
loc_82192A7C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_821929F0) {
	__imp__sub_821929F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192A84) {
	__imp__sub_82192A84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192A88) {
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
	ctx.lr = 0x82192A90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82192b10
	if (cr6.eq) goto loc_82192B10;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x82192b10
	if (cr6.gt) goto loc_82192B10;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82192b10
	if (!cr6.gt) goto loc_82192B10;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82192AC8:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82192b04
	if (cr6.eq) goto loc_82192B04;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82192B04;
	sub_8218A6E0(ctx, base);
loc_82192B04:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82192ac8
	if (!cr0.eq) goto loc_82192AC8;
loc_82192B10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192A88) {
	__imp__sub_82192A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192B18) {
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
	ctx.lr = 0x82192B20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82192ba4
	if (cr6.eq) goto loc_82192BA4;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x82192ba4
	if (cr6.gt) goto loc_82192BA4;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82192ba4
	if (!cr6.gt) goto loc_82192BA4;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82192B5C:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82192b98
	if (cr6.eq) goto loc_82192B98;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,5
	ctx.r9.s64 = 5;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82192B98;
	sub_8218A6E0(ctx, base);
loc_82192B98:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82192b5c
	if (!cr0.eq) goto loc_82192B5C;
loc_82192BA4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82192B18) {
	__imp__sub_82192B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192BAC) {
	__imp__sub_82192BAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192BB0) {
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
	ctx.lr = 0x82192BB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82192c38
	if (cr6.eq) goto loc_82192C38;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x82192c38
	if (cr6.gt) goto loc_82192C38;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82192c38
	if (!cr6.gt) goto loc_82192C38;
	// rlwinm r29,r4,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82192BF0:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82192c2c
	if (cr6.eq) goto loc_82192C2C;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,64
	ctx.r7.s64 = 64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82192C2C;
	sub_8218A6E0(ctx, base);
loc_82192C2C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82192bf0
	if (!cr0.eq) goto loc_82192BF0;
loc_82192C38:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192BB0) {
	__imp__sub_82192BB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192C40) {
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
	ctx.lr = 0x82192C48;
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
	// beq cr6,0x82192cac
	if (cr6.eq) goto loc_82192CAC;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82192cac
	if (cr6.eq) goto loc_82192CAC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82192C7C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82192cac
	if (cr6.eq) goto loc_82192CAC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82192C90;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82194b18
	ctx.lr = 0x82192CA4;
	sub_82194B18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82192CAC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192C40) {
	__imp__sub_82192C40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192CBC) {
	__imp__sub_82192CBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192CC0) {
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
	ctx.lr = 0x82192CC8;
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
	// beq cr6,0x82192d2c
	if (cr6.eq) goto loc_82192D2C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82192d2c
	if (cr6.eq) goto loc_82192D2C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82192CFC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82192d2c
	if (cr6.eq) goto loc_82192D2C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82192D10;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82180420
	ctx.lr = 0x82192D24;
	sub_82180420(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82192D2C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192CC0) {
	__imp__sub_82192CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192D3C) {
	__imp__sub_82192D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192D40) {
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
	ctx.lr = 0x82192D48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r31,6(r3)
	r31.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82192d84
	if (cr6.eq) goto loc_82192D84;
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82192d7c
	if (!cr6.gt) goto loc_82192D7C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82192D68:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82192D70;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82192d68
	if (!cr0.eq) goto loc_82192D68;
loc_82192D7C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82192D84;
	sub_82130588(ctx, base);
loc_82192D84:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82192D40) {
	__imp__sub_82192D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192D8C) {
	__imp__sub_82192D8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192D90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82192D98;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r11.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r31,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r31.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82192DD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82192e60
	if (!cr6.gt) goto loc_82192E60;
	// li r23,0
	r23.s64 = 0;
	// mr r24,r31
	r24.u64 = r31.u64;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_82192DF0:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add. r31,r26,r11
	r31.u64 = r26.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82192e54
	if (cr0.eq) goto loc_82192E54;
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r27,r28
	r30.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82192e50
	if (cr6.eq) goto loc_82192E50;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82192e50
	if (cr6.eq) goto loc_82192E50;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82192E24;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82192e50
	if (cr6.eq) goto loc_82192E50;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82192E38;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r28
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// bl 0x82194b18
	ctx.lr = 0x82192E4C;
	sub_82194B18(ctx, base);
	// b 0x82192e54
	goto loc_82192E54;
loc_82192E50:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82192E54:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82192df0
	if (!cr0.eq) goto loc_82192DF0;
loc_82192E60:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82192D90) {
	__imp__sub_82192D90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192E68) {
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
	ctx.lr = 0x82192E70;
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
	// beq cr6,0x82192e98
	if (cr6.eq) goto loc_82192E98;
	// bl 0x8217d890
	ctx.lr = 0x82192E8C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82192E98:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82192f28
	if (cr6.eq) goto loc_82192F28;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82192EB8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82192f10
	if (cr6.eq) goto loc_82192F10;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82192f10
	if (cr6.eq) goto loc_82192F10;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82192EE4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82192f10
	if (cr6.eq) goto loc_82192F10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82192EF8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x82180420
	ctx.lr = 0x82192F0C;
	sub_82180420(ctx, base);
	// b 0x82192f14
	goto loc_82192F14;
loc_82192F10:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82192F14:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82192eb8
	if (cr6.lt) goto loc_82192EB8;
loc_82192F28:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82192E68) {
	__imp__sub_82192E68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82192F34) {
	__imp__sub_82192F34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82192F38) {
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
	ctx.lr = 0x82192F40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82193018
	if (cr6.eq) goto loc_82193018;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82192f84
	if (!cr6.gt) goto loc_82192F84;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
loc_82192F68:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// beq cr6,0x8219300c
	if (cr6.eq) goto loc_8219300C;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// blt cr6,0x82192f68
	if (cr6.lt) goto loc_82192F68;
loc_82192F84:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add. r29,r9,r10
	r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// beq 0x82192fac
	if (cr0.eq) goto loc_82192FAC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82192c40
	ctx.lr = 0x82192FAC;
	sub_82192C40(ctx, base);
loc_82192FAC:
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// lhz r11,68(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// sth r10,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r10.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rotlwi r28,r11,2
	r28.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r29,64(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82192FDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r3.u32);
	// lhz r6,14(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 14);
	// addi r10,r31,72
	ctx.r10.s64 = r31.s64 + 72;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lhz r11,76(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,76(r31)
	PPC_STORE_U16(r31.u32 + 76, ctx.r5.u16);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8219300C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82193018:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add. r30,r10,r9
	r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// beq 0x82193040
	if (cr0.eq) goto loc_82193040;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82192c40
	ctx.lr = 0x82193040;
	sub_82192C40(ctx, base);
loc_82193040:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r31,64
	ctx.r9.s64 = r31.s64 + 64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r9,r31,72
	ctx.r9.s64 = r31.s64 + 72;
	// lhz r11,68(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r7.u16);
	// stwx r10,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u32);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lhz r11,76(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,76(r31)
	PPC_STORE_U16(r31.u32 + 76, ctx.r5.u16);
	// stwx r10,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u32);
	// lhz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82192F38) {
	__imp__sub_82192F38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219308C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219308C) {
	__imp__sub_8219308C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193090) {
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
	// bl 0x821d2970
	ctx.lr = 0x821930B0;
	sub_821D2970(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-15276
	ctx.r10.s64 = r11.s64 + -15276;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x821930C4;
	sub_821B5A60(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821930e4
	if (cr6.eq) goto loc_821930E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x821930D8;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_821930E4:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82192e68
	ctx.lr = 0x821930F4;
	sub_82192E68(ctx, base);
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

PPC_WEAK_FUNC(sub_82193090) {
	__imp__sub_82193090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193110) {
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
	ctx.lr = 0x82193118;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-15276
	ctx.r10.s64 = r11.s64 + -15276;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8219315c
	if (cr6.eq) goto loc_8219315C;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x8219315c
	if (!cr0.eq) goto loc_8219315C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219315C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8219315C:
	// li r28,0
	r28.s64 = 0;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// lhz r11,28(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821931c0
	if (cr6.eq) goto loc_821931C0;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82193174:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwzx r30,r29,r11
	r30.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82193184;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821931ac
	if (!cr6.eq) goto loc_821931AC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821931ac
	if (cr6.eq) goto loc_821931AC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821931AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821931AC:
	// lhz r11,28(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82193174
	if (cr6.lt) goto loc_82193174;
loc_821931C0:
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821931d4
	if (cr6.eq) goto loc_821931D4;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x821931D4;
	sub_82130588(ctx, base);
loc_821931D4:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821931e8
	if (cr6.eq) goto loc_821931E8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x821931E8;
	sub_82130588(ctx, base);
loc_821931E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x821931F0;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82193110) {
	__imp__sub_82193110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821931F8) {
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
	// bl 0x82193110
	ctx.lr = 0x82193218;
	sub_82193110(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82193230
	if (cr6.eq) goto loc_82193230;
	// bl 0x82130588
	ctx.lr = 0x8219322C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82193230:
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

PPC_WEAK_FUNC(sub_821931F8) {
	__imp__sub_821931F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193248) {
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
	ctx.lr = 0x82193250;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82192d90
	ctx.lr = 0x8219326C;
	sub_82192D90(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82193280
	if (cr6.eq) goto loc_82193280;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8219327C;
	sub_82130528(ctx, base);
	// b 0x82193284
	goto loc_82193284;
loc_82193280:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82193284:
	// clrlwi r29,r30,16
	r29.u64 = r30.u32 & 0xFFFF;
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r29,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r29.u16);
	// beq cr6,0x821932b0
	if (cr6.eq) goto loc_821932B0;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x821932A0;
	sub_82130528(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// sth r29,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r29.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821932B0:
	// li r11,0
	r11.s64 = 0;
	// sth r29,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r29.u16);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82193248) {
	__imp__sub_82193248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821932C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821932C4) {
	__imp__sub_821932C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821932C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x821932D0;
	// stwu r1,-3152(r1)
	ea = -3152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r31,3172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3172, r31.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r10,-15180
	ctx.r4.s64 = ctx.r10.s64 + -15180;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821932FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// bl 0x82193248
	ctx.lr = 0x82193310;
	sub_82193248(ctx, base);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r16,r11,-29624
	r16.s64 = r11.s64 + -29624;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82193330;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// li r22,0
	r22.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-15188
	ctx.r4.s64 = ctx.r6.s64 + -15188;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r17,r22
	r17.u64 = r22.u64;
	// bl 0x821cfe80
	ctx.lr = 0x8219334C;
	sub_821CFE80(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82193374
	if (cr6.eq) goto loc_82193374;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
loc_82193374:
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82193710
	if (!cr6.gt) goto loc_82193710;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r21,-32124
	r21.s64 = -2105278464;
	// addi r20,r11,-15196
	r20.s64 = r11.s64 + -15196;
	// addi r15,r10,-20340
	r15.s64 = ctx.r10.s64 + -20340;
	// addi r14,r9,-15208
	r14.s64 = ctx.r9.s64 + -15208;
	// addi r19,r8,-15216
	r19.s64 = ctx.r8.s64 + -15216;
	// addi r18,r7,-15224
	r18.s64 = ctx.r7.s64 + -15224;
loc_821933AC:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r30,r1,944
	r30.s64 = ctx.r1.s64 + 944;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821933CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r23,r22
	r23.u64 = r22.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
	// mr r25,r22
	r25.u64 = r22.u64;
	// mr r26,r22
	r26.u64 = r22.u64;
	// li r24,-1
	r24.s64 = -1;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// ble cr6,0x8219357c
	if (!cr6.gt) goto loc_8219357C;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821933F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821933f0
	if (!cr6.eq) goto loc_821933F0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// ble cr6,0x82193450
	if (!cr6.gt) goto loc_82193450;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
loc_82193424:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82193448
	if (cr6.eq) goto loc_82193448;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82193424
	if (cr6.eq) goto loc_82193424;
loc_82193448:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82193494
	if (cr6.eq) goto loc_82193494;
loc_82193450:
	// cmpwi cr6,r8,7
	cr6.compare<int32_t>(ctx.r8.s32, 7, xer);
	// ble cr6,0x82193530
	if (!cr6.gt) goto loc_82193530;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
loc_82193468:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x8219348c
	if (cr6.eq) goto loc_8219348C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82193468
	if (cr6.eq) goto loc_82193468;
loc_8219348C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82193530
	if (!cr6.eq) goto loc_82193530;
loc_82193494:
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r25,r1,176
	r25.s64 = ctx.r1.s64 + 176;
	// bl 0x821cfe80
	ctx.lr = 0x821934A8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8219350c
	if (cr6.eq) goto loc_8219350C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,688
	ctx.r4.s64 = ctx.r1.s64 + 688;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821934D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r26,r1,688
	r26.s64 = ctx.r1.s64 + 688;
	// bl 0x821cfe80
	ctx.lr = 0x821934E4;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8219350c
	if (cr6.eq) goto loc_8219350C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_8219350C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r27,r1,432
	r27.s64 = ctx.r1.s64 + 432;
	// b 0x82193580
	goto loc_82193580;
loc_82193530:
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// ble cr6,0x8219357c
	if (!cr6.gt) goto loc_8219357C;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
loc_82193548:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8219356c
	if (cr6.eq) goto loc_8219356C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82193548
	if (cr6.eq) goto loc_82193548;
loc_8219356C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8219357c
	if (!cr6.eq) goto loc_8219357C;
	// addi r23,r1,176
	r23.s64 = ctx.r1.s64 + 176;
	// b 0x82193580
	goto loc_82193580;
loc_8219357C:
	// addi r27,r1,176
	r27.s64 = ctx.r1.s64 + 176;
loc_82193580:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r22
	r31.u64 = r22.u64;
loc_821935A0:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x821935b0
	if (cr6.eq) goto loc_821935B0;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// bge cr6,0x82193650
	if (!cr6.lt) goto loc_82193650;
loc_821935B0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,2992
	ctx.r8.s64 = ctx.r1.s64 + 2992;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// subf r5,r30,r8
	ctx.r5.s64 = ctx.r8.s64 - r30.s64;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821935DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82193618
	if (!cr6.eq) goto loc_82193618;
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821935EC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82193610
	if (cr6.eq) goto loc_82193610;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821935ec
	if (cr6.eq) goto loc_821935EC;
loc_82193610:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82193648
	if (cr6.eq) goto loc_82193648;
loc_82193618:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8219361C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8219361c
	if (!cr6.eq) goto loc_8219361C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// b 0x821935a0
	goto loc_821935A0;
loc_82193648:
	// li r29,-1
	r29.s64 = -1;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
loc_82193650:
	// mr r30,r22
	r30.u64 = r22.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8219368c
	if (cr6.eq) goto loc_8219368C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82195a98
	ctx.lr = 0x82193664;
	sub_82195A98(ctx, base);
	// bl 0x82195720
	ctx.lr = 0x82193668;
	sub_82195720(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8219368c
	if (cr6.eq) goto loc_8219368C;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193688;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8219368C:
	// lwz r3,-24728(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -24728);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821936AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821936E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82193738
	if (cr6.eq) goto loc_82193738;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,3172(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3172);
	// bl 0x82192f38
	ctx.lr = 0x821936F8;
	sub_82192F38(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x821933ac
	if (cr6.lt) goto loc_821933AC;
loc_82193710:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r10,-29628
	ctx.r4.s64 = ctx.r10.s64 + -29628;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8219372C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,3152
	ctx.r1.s64 = ctx.r1.s64 + 3152;
	// b 0x823d9210
	return;
loc_82193738:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r11,-15264
	ctx.r3.s64 = r11.s64 + -15264;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bne cr6,0x82193758
	if (!cr6.eq) goto loc_82193758;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_82193758:
	// bl 0x82130000
	ctx.lr = 0x8219375C;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,3152
	ctx.r1.s64 = ctx.r1.s64 + 3152;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_821932C8) {
	__imp__sub_821932C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193768) {
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
	ctx.lr = 0x82193770;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8219384c
	if (!cr6.eq) goto loc_8219384C;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r4.u16);
	// bl 0x821b5998
	ctx.lr = 0x82193798;
	sub_821B5998(ctx, base);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8219380c
	if (cr6.eq) goto loc_8219380C;
	// li r28,0
	r28.s64 = 0;
loc_821937AC:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r11,r28,3,0,28
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// add r31,r11,r27
	r31.u64 = r11.u64 + r27.u64;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x821937f4
	if (cr6.eq) goto loc_821937F4;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x821937e8
	if (cr6.eq) goto loc_821937E8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821937e8
	if (cr6.eq) goto loc_821937E8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821937E8;
	sub_82130588(ctx, base);
loc_821937E8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c7480
	ctx.lr = 0x821937F4;
	sub_826C7480(ctx, base);
loc_821937F4:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821937ac
	if (cr6.lt) goto loc_821937AC;
loc_8219380C:
	// lhz r29,4(r30)
	r29.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82193840
	if (!cr6.gt) goto loc_82193840;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82193820:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82193834
	if (cr6.eq) goto loc_82193834;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82193834;
	sub_82130588(ctx, base);
loc_82193834:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82193820
	if (!cr0.eq) goto loc_82193820;
loc_82193840:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82193848;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
loc_8219384C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82193768) {
	__imp__sub_82193768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219386C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219386C) {
	__imp__sub_8219386C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-15168
	ctx.r9.s64 = ctx.r10.s64 + -15168;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
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
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82193870) {
	__imp__sub_82193870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821938F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821938F4) {
	__imp__sub_821938F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821938F8) {
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
	ctx.lr = 0x82193900;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,-15168
	ctx.r9.s64 = r11.s64 + -15168;
	// lhz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82193960
	if (cr6.eq) goto loc_82193960;
	// li r31,0
	r31.s64 = 0;
loc_82193928:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8219394c
	if (cr6.eq) goto loc_8219394C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219394C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8219394C:
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82193928
	if (cr6.lt) goto loc_82193928;
loc_82193960:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82193980
	if (cr6.eq) goto loc_82193980;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82193980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82193980:
	// lhz r11,78(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 78);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82193994
	if (cr6.eq) goto loc_82193994;
	// lwz r3,72(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// bl 0x82130588
	ctx.lr = 0x82193994;
	sub_82130588(ctx, base);
loc_82193994:
	// lhz r11,70(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 70);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821939a8
	if (cr6.eq) goto loc_821939A8;
	// lwz r3,64(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// bl 0x82130588
	ctx.lr = 0x821939A8;
	sub_82130588(ctx, base);
loc_821939A8:
	// lhz r30,62(r28)
	r30.u64 = PPC_LOAD_U16(r28.u32 + 62);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821939ec
	if (cr6.eq) goto loc_821939EC;
	// lwz r29,56(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821939e4
	if (!cr6.gt) goto loc_821939E4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821939C4:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821939d8
	if (cr6.eq) goto loc_821939D8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821939D8;
	sub_82130588(ctx, base);
loc_821939D8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x821939c4
	if (!cr0.eq) goto loc_821939C4;
loc_821939E4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821939EC;
	sub_82130588(ctx, base);
loc_821939EC:
	// lhz r11,54(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 54);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82193a00
	if (cr6.eq) goto loc_82193A00;
	// lwz r3,48(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// bl 0x82130588
	ctx.lr = 0x82193A00;
	sub_82130588(ctx, base);
loc_82193A00:
	// lhz r31,46(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 46);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82193a38
	if (cr6.eq) goto loc_82193A38;
	// lwz r29,40(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82193a30
	if (!cr6.gt) goto loc_82193A30;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82193A1C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82193A24;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82193a1c
	if (!cr0.eq) goto loc_82193A1C;
loc_82193A30:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82193A38;
	sub_82130588(ctx, base);
loc_82193A38:
	// lhz r31,38(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 38);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82193a70
	if (cr6.eq) goto loc_82193A70;
	// lwz r29,32(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82193a68
	if (!cr6.gt) goto loc_82193A68;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82193A54:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82193A5C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82193a54
	if (!cr0.eq) goto loc_82193A54;
loc_82193A68:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82193A70;
	sub_82130588(ctx, base);
loc_82193A70:
	// lhz r31,30(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 30);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82193aa8
	if (cr6.eq) goto loc_82193AA8;
	// lwz r29,24(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82193aa0
	if (!cr6.gt) goto loc_82193AA0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82193A8C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82193A94;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82193a8c
	if (!cr0.eq) goto loc_82193A8C;
loc_82193AA0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82193AA8;
	sub_82130588(ctx, base);
loc_82193AA8:
	// lhz r31,22(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 22);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82193ae0
	if (cr6.eq) goto loc_82193AE0;
	// lwz r29,16(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82193ad8
	if (!cr6.gt) goto loc_82193AD8;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82193AC4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82193ACC;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82193ac4
	if (!cr0.eq) goto loc_82193AC4;
loc_82193AD8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82193AE0;
	sub_82130588(ctx, base);
loc_82193AE0:
	// addi r3,r28,8
	ctx.r3.s64 = r28.s64 + 8;
	// bl 0x82192618
	ctx.lr = 0x82193AE8;
	sub_82192618(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2028
	ctx.lr = 0x82193AF0;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_821938F8) {
	__imp__sub_821938F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193AF8) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82193B00;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lhz r27,12(r23)
	r27.u64 = PPC_LOAD_U16(r23.u32 + 12);
	// rotlwi r22,r27,2
	r22.u64 = __builtin_rotateleft32(r27.u32, 2);
	// neg r11,r22
	r11.s64 = -r22.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x82193B28;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// addi r24,r1,80
	r24.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82193b7c
	if (!cr6.gt) goto loc_82193B7C;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_82193B48:
	// lwz r11,8(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82193B60;
	sub_8218A568(ctx, base);
	// stwx r3,r30,r24
	PPC_STORE_U32(r30.u32 + r24.u32, ctx.r3.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82193b70
	if (cr6.eq) goto loc_82193B70;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_82193B70:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82193b48
	if (!cr0.eq) goto loc_82193B48;
loc_82193B7C:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82193bac
	if (cr6.eq) goto loc_82193BAC;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x82193bc0
	if (!cr6.eq) goto loc_82193BC0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-15164
	ctx.r3.s64 = r11.s64 + -15164;
	// bl 0x821bd618
	ctx.lr = 0x82193BA0;
	sub_821BD618(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9230
	return;
loc_82193BAC:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x82193bc0
	if (!cr6.eq) goto loc_82193BC0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9230
	return;
loc_82193BC0:
	// lhz r5,60(r23)
	ctx.r5.u64 = PPC_LOAD_U16(r23.u32 + 60);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82193c38
	if (!cr6.gt) goto loc_82193C38;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82193BD4:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82193c1c
	if (!cr6.gt) goto loc_82193C1C;
	// lwz r9,56(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// mr r11,r24
	r11.u64 = r24.u64;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// subf r9,r24,r4
	ctx.r9.s64 = ctx.r4.s64 - r24.s64;
loc_82193BF4:
	// lwzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// bne cr6,0x82193c18
	if (!cr6.eq) goto loc_82193C18;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r27
	cr6.compare<int32_t>(ctx.r10.s32, r27.s32, xer);
	// blt cr6,0x82193bf4
	if (cr6.lt) goto loc_82193BF4;
	// b 0x82193c1c
	goto loc_82193C1C;
loc_82193C18:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82193C1C:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82193c5c
	if (!cr6.eq) goto loc_82193C5C;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// blt cr6,0x82193bd4
	if (cr6.lt) goto loc_82193BD4;
loc_82193C38:
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r23,56
	ctx.r3.s64 = r23.s64 + 56;
	// bl 0x82193768
	ctx.lr = 0x82193C44;
	sub_82193768(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82193c68
	if (cr6.eq) goto loc_82193C68;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82130528
	ctx.lr = 0x82193C58;
	sub_82130528(ctx, base);
	// b 0x82193c6c
	goto loc_82193C6C;
loc_82193C5C:
	// addi r3,r6,1
	ctx.r3.s64 = ctx.r6.s64 + 1;
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9230
	return;
loc_82193C68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82193C6C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// ble cr6,0x82193cb0
	if (!cr6.gt) goto loc_82193CB0;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82193C84:
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// sth r5,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r5.u16);
	// stwx r6,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r6.u32);
	// bne 0x82193c84
	if (!cr0.eq) goto loc_82193C84;
loc_82193CB0:
	// lhz r3,60(r23)
	ctx.r3.u64 = PPC_LOAD_U16(r23.u32 + 60);
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82193AF8) {
	__imp__sub_82193AF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82193CBC) {
	__imp__sub_82193CBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193CC0) {
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
	ctx.lr = 0x82193CC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82193d34
	if (cr6.eq) goto loc_82193D34;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82193d34
	if (cr6.eq) goto loc_82193D34;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82193CFC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82193d34
	if (cr6.eq) goto loc_82193D34;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193D10;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82193d3c
	if (cr6.eq) goto loc_82193D3C;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x82193090
	ctx.lr = 0x82193D2C;
	sub_82193090(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82193D34:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82193D3C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82193CC0) {
	__imp__sub_82193CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82193D44) {
	__imp__sub_82193D44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193D48) {
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
	// bl 0x821938f8
	ctx.lr = 0x82193D68;
	sub_821938F8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82193d80
	if (cr6.eq) goto loc_82193D80;
	// bl 0x82130588
	ctx.lr = 0x82193D7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82193D80:
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

PPC_WEAK_FUNC(sub_82193D48) {
	__imp__sub_82193D48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82193D98) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82193DA0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r22,r26,4
	r22.s64 = r26.s64 + 4;
	// addi r10,r11,-15168
	ctx.r10.s64 = r11.s64 + -15168;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// bl 0x82193cc0
	ctx.lr = 0x82193DC4;
	sub_82193CC0(ctx, base);
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193de4
	if (cr6.eq) goto loc_82193DE4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193DD8;
	sub_8217D890(ctx, base);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,8(r26)
	PPC_STORE_U32(r26.u32 + 8, ctx.r10.u32);
loc_82193DE4:
	// lwz r4,16(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193e04
	if (cr6.eq) goto loc_82193E04;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193DF8;
	sub_8217D890(ctx, base);
	// lwz r11,16(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r26)
	PPC_STORE_U32(r26.u32 + 16, ctx.r10.u32);
loc_82193E04:
	// lwz r4,24(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193e24
	if (cr6.eq) goto loc_82193E24;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193E18;
	sub_8217D890(ctx, base);
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,24(r26)
	PPC_STORE_U32(r26.u32 + 24, ctx.r10.u32);
loc_82193E24:
	// lwz r4,32(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193e44
	if (cr6.eq) goto loc_82193E44;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193E38;
	sub_8217D890(ctx, base);
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,32(r26)
	PPC_STORE_U32(r26.u32 + 32, ctx.r10.u32);
loc_82193E44:
	// lwz r4,40(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193e64
	if (cr6.eq) goto loc_82193E64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193E58;
	sub_8217D890(ctx, base);
	// lwz r11,40(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,40(r26)
	PPC_STORE_U32(r26.u32 + 40, ctx.r10.u32);
loc_82193E64:
	// lwz r4,48(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193e84
	if (cr6.eq) goto loc_82193E84;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193E78;
	sub_8217D890(ctx, base);
	// lwz r11,48(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,48(r26)
	PPC_STORE_U32(r26.u32 + 48, ctx.r10.u32);
loc_82193E84:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r26,56
	ctx.r3.s64 = r26.s64 + 56;
	// bl 0x821b5cd8
	ctx.lr = 0x82193E94;
	sub_821B5CD8(ctx, base);
	// lwz r4,64(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 64);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193eb4
	if (cr6.eq) goto loc_82193EB4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193EA8;
	sub_8217D890(ctx, base);
	// lwz r11,64(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 64);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,64(r26)
	PPC_STORE_U32(r26.u32 + 64, ctx.r10.u32);
loc_82193EB4:
	// lwz r4,72(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 72);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82193ed4
	if (cr6.eq) goto loc_82193ED4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8217d890
	ctx.lr = 0x82193EC8;
	sub_8217D890(ctx, base);
	// lwz r11,72(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 72);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,72(r26)
	PPC_STORE_U32(r26.u32 + 72, ctx.r10.u32);
loc_82193ED4:
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lis r23,-32124
	r23.s64 = -2105278464;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82193ef0
	if (cr6.eq) goto loc_82193EF0;
	// lwz r10,-24880(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r23)
	PPC_STORE_U32(r23.u32 + -24880, r11.u32);
loc_82193EF0:
	// lhz r10,20(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 20);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r27,0
	r27.s64 = 0;
	// addi r24,r11,-26560
	r24.s64 = r11.s64 + -26560;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82193f88
	if (cr6.eq) goto loc_82193F88;
	// li r29,0
	r29.s64 = 0;
loc_82193F0C:
	// lwz r28,16(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// lwzx r31,r29,r28
	r31.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82193f74
	if (cr6.eq) goto loc_82193F74;
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x82193F2C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82193f54
	if (cr6.eq) goto loc_82193F54;
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
	// b 0x82193f68
	goto loc_82193F68;
loc_82193F54:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821d2378
	ctx.lr = 0x82193F64;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82193F68:
	// lwzx r10,r29,r28
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r29,r28
	PPC_STORE_U32(r29.u32 + r28.u32, r11.u32);
loc_82193F74:
	// lhz r11,20(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 20);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82193f0c
	if (cr6.lt) goto loc_82193F0C;
loc_82193F88:
	// lhz r11,28(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 28);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82194018
	if (cr6.eq) goto loc_82194018;
	// li r29,0
	r29.s64 = 0;
loc_82193F9C:
	// lwz r28,24(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwzx r31,r29,r28
	r31.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82194004
	if (cr6.eq) goto loc_82194004;
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x82193FBC;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82193fe4
	if (cr6.eq) goto loc_82193FE4;
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
	// b 0x82193ff8
	goto loc_82193FF8;
loc_82193FE4:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821d2378
	ctx.lr = 0x82193FF4;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82193FF8:
	// lwzx r10,r29,r28
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r29,r28
	PPC_STORE_U32(r29.u32 + r28.u32, r11.u32);
loc_82194004:
	// lhz r11,28(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 28);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82193f9c
	if (cr6.lt) goto loc_82193F9C;
loc_82194018:
	// lhz r11,36(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 36);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821940c8
	if (cr6.eq) goto loc_821940C8;
	// li r31,0
	r31.s64 = 0;
loc_8219402C:
	// lwz r30,32(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lwzx r5,r31,r30
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821940b4
	if (cr6.eq) goto loc_821940B4;
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x82194098
	if (!cr0.gt) goto loc_82194098;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_82194058:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x82194078
	if (cr6.lt) goto loc_82194078;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8219407c
	if (cr6.lt) goto loc_8219407C;
loc_82194078:
	// li r11,0
	r11.s64 = 0;
loc_8219407C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821941f8
	if (!cr6.eq) goto loc_821941F8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x82194058
	if (cr6.lt) goto loc_82194058;
loc_82194098:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821d2378
	ctx.lr = 0x821940A4;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_821940A8:
	// lwzx r10,r31,r30
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
loc_821940B4:
	// lhz r11,36(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 36);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8219402c
	if (cr6.lt) goto loc_8219402C;
loc_821940C8:
	// lhz r11,44(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 44);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82194178
	if (cr6.eq) goto loc_82194178;
	// li r31,0
	r31.s64 = 0;
loc_821940DC:
	// lwz r30,40(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// lwzx r5,r30,r31
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82194164
	if (cr6.eq) goto loc_82194164;
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// add. r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x82194148
	if (!cr0.gt) goto loc_82194148;
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
loc_82194108:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x82194128
	if (cr6.lt) goto loc_82194128;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8219412c
	if (cr6.lt) goto loc_8219412C;
loc_82194128:
	// li r11,0
	r11.s64 = 0;
loc_8219412C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82194220
	if (!cr6.eq) goto loc_82194220;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x82194108
	if (cr6.lt) goto loc_82194108;
loc_82194148:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821d2378
	ctx.lr = 0x82194154;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82194158:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
loc_82194164:
	// lhz r11,44(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 44);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x821940dc
	if (cr6.lt) goto loc_821940DC;
loc_82194178:
	// lhz r11,12(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821941d0
	if (cr6.eq) goto loc_821941D0;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821941d0
	if (!cr6.gt) goto loc_821941D0;
	// li r31,0
	r31.s64 = 0;
	// lis r29,-32124
	r29.s64 = -2105278464;
loc_82194198:
	// lwz r3,-24728(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24728);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821941BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,12(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82194198
	if (cr6.lt) goto loc_82194198;
loc_821941D0:
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821941f0
	if (cr6.eq) goto loc_821941F0;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,-24880(r23)
	PPC_STORE_U32(r23.u32 + -24880, ctx.r10.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_821941F0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_821941F8:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82194098
	if (cr6.eq) goto loc_82194098;
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
	// b 0x821940a8
	goto loc_821940A8;
loc_82194220:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82194148
	if (cr6.eq) goto loc_82194148;
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
	// b 0x82194158
	goto loc_82194158;
}

PPC_WEAK_FUNC(sub_82193D98) {
	__imp__sub_82193D98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82193d98
	sub_82193D98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82194248) {
	__imp__sub_82194248(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194254) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82194254) {
	__imp__sub_82194254(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8219426C:
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8219426c
	if (cr6.eq) goto loc_8219426C;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82194258) {
	__imp__sub_82194258(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82194284) {
	__imp__sub_82194284(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194288) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82194374
	if (cr6.eq) goto loc_82194374;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// addi r7,r11,3998
	ctx.r7.s64 = r11.s64 + 3998;
loc_821942A8:
	// addi r11,r8,16
	r11.s64 = ctx.r8.s64 + 16;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// addi r10,r4,2
	ctx.r10.s64 = ctx.r4.s64 + 2;
	// bne cr6,0x821942bc
	if (!cr6.eq) goto loc_821942BC;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_821942BC:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821942d0
	if (!cr6.eq) goto loc_821942D0;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_821942D0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r31,0(r10)
	r31.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - r31.s64;
	// beq cr6,0x821942f4
	if (cr6.eq) goto loc_821942F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821942d0
	if (cr6.eq) goto loc_821942D0;
loc_821942F4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82194308
	if (cr6.lt) goto loc_82194308;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// b 0x8219430c
	goto loc_8219430C;
loc_82194308:
	// lwz r8,12(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
loc_8219430C:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821942a8
	if (!cr6.eq) goto loc_821942A8;
	// cmplw cr6,r3,r5
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, xer);
	// beq cr6,0x82194374
	if (cr6.eq) goto loc_82194374;
	// lhz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// bne cr6,0x82194334
	if (!cr6.eq) goto loc_82194334;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_82194334:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// addi r11,r4,2
	r11.s64 = ctx.r4.s64 + 2;
	// bne cr6,0x82194344
	if (!cr6.eq) goto loc_82194344;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82194344:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194368
	if (cr6.eq) goto loc_82194368;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194344
	if (cr6.eq) goto loc_82194344;
loc_82194368:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x82194374
	if (!cr6.lt) goto loc_82194374;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
loc_82194374:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82194288) {
	__imp__sub_82194288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219437C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219437C) {
	__imp__sub_8219437C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194380) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821943c4
	if (cr6.eq) goto loc_821943C4;
loc_821943A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82194380
	ctx.lr = 0x821943B0;
	sub_82194380(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x821943BC;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821943a4
	if (!cr6.eq) goto loc_821943A4;
loc_821943C4:
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

PPC_WEAK_FUNC(sub_82194380) {
	__imp__sub_82194380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821943DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821943DC) {
	__imp__sub_821943DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821943E0) {
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
	ctx.lr = 0x821943E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r11,-13328(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13328);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82194488
	if (!cr6.eq) goto loc_82194488;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r4,-32124
	ctx.r4.s64 = -2105278464;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r31,r4,-13352
	r31.s64 = ctx.r4.s64 + -13352;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// std r10,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r10.u64);
	// mr r30,r31
	r30.u64 = r31.u64;
	// std r10,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, ctx.r10.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stb r6,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r6.u8);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// lis r3,-32132
	ctx.r3.s64 = -2105802752;
	// stw r11,-13328(r9)
	PPC_STORE_U32(ctx.r9.u32 + -13328, r11.u32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// addi r3,r3,-30392
	ctx.r3.s64 = ctx.r3.s64 + -30392;
	// lwz r7,12(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r29,4(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r5,8(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r7,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r7.u32);
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// stw r5,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r5.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// stb r10,-13352(r4)
	PPC_STORE_U8(ctx.r4.u32 + -13352, ctx.r10.u8);
	// bl 0x823d9a98
	ctx.lr = 0x8219447C;
	sub_823D9A98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_82194488:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-13352
	ctx.r3.s64 = r11.s64 + -13352;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_821943E0) {
	__imp__sub_821943E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194498) {
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
	ctx.lr = 0x821944A0;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stw r29,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r29.u32);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_821944BC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821944bc
	if (!cr6.eq) goto loc_821944BC;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_821944D8:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r11,38
	cr6.compare<uint32_t>(r11.u32, 38, xer);
	// beq cr6,0x82194510
	if (cr6.eq) goto loc_82194510;
loc_821944E8:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x82194510
	if (cr6.eq) goto loc_82194510;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82194510
	if (cr6.eq) goto loc_82194510;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,38
	cr6.compare<uint32_t>(r11.u32, 38, xer);
	// bne cr6,0x821944e8
	if (!cr6.eq) goto loc_821944E8;
loc_82194510:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82194520
	if (!cr6.eq) goto loc_82194520;
	// li r28,1
	r28.s64 = 1;
loc_82194520:
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// beq cr6,0x821945a4
	if (cr6.eq) goto loc_821945A4;
	// stb r29,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r29.u8);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// sth r29,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r29.u16);
loc_82194534:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82194534
	if (!cr6.eq) goto loc_82194534;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r31,r11,0
	r31.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x8219455C;
	sub_823DA950(ctx, base);
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r10,r1,82
	ctx.r10.s64 = ctx.r1.s64 + 82;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stbx r29,r8,r10
	PPC_STORE_U8(ctx.r8.u32 + ctx.r10.u32, r29.u8);
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// sth r6,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r6.u16);
	// bl 0x821943e0
	ctx.lr = 0x8219457C;
	sub_821943E0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82194288
	ctx.lr = 0x82194584;
	sub_82194288(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821943e0
	ctx.lr = 0x8219458C;
	sub_821943E0(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x821945a4
	if (cr6.eq) goto loc_821945A4;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// stw r9,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r9.u32);
loc_821945A4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821944d8
	if (cr6.eq) goto loc_821944D8;
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82194498) {
	__imp__sub_82194498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821945BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821945BC) {
	__imp__sub_821945BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821945C0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821945C0) {
	__imp__sub_821945C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821945C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r25{};
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82194654
	if (!cr6.eq) goto loc_82194654;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x8218a568
	ctx.lr = 0x82194600;
	sub_8218A568(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r4,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r4.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82194654
	if (cr6.eq) goto loc_82194654;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// bl 0x8218a6a0
	ctx.lr = 0x8219462C;
	sub_8218A6A0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82194654
	if (cr6.eq) goto loc_82194654;
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bne cr6,0x8219464c
	if (!cr6.eq) goto loc_8219464C;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x82194654
	if (cr6.eq) goto loc_82194654;
loc_8219464C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_82194654:
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x821947a8
	if (cr6.eq) goto loc_821947A8;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x821947a8
	if (cr6.gt) goto loc_821947A8;
	// lis r12,-32231
	r12.s64 = -2112290816;
	// addi r12,r12,18056
	r12.s64 = r12.s64 + 18056;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r16,18092(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18092);
	// lwz r16,18112(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18112);
	// lwz r16,18136(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18136);
	// lwz r16,18168(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18168);
	// lwz r16,18208(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18208);
	// lwz r16,18256(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18256);
	// lwz r16,18276(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18276);
	// lwz r16,18308(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18308);
	// lwz r16,18316(r25)
	r16.u64 = PPC_LOAD_U32(r25.u32 + 18316);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x8218a788
	ctx.lr = 0x821946BC;
	sub_8218A788(ctx, base);
	// b 0x821947a8
	goto loc_821947A8;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// b 0x82194798
	goto loc_82194798;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r9,3
	ctx.r9.s64 = 3;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r7,8
	ctx.r7.s64 = 8;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// b 0x82194798
	goto loc_82194798;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// b 0x82194798
	goto loc_82194798;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f11,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// b 0x82194798
	goto loc_82194798;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82189ce0
	ctx.lr = 0x82194760;
	sub_82189CE0(ctx, base);
	// b 0x821947a8
	goto loc_821947A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a758
	ctx.lr = 0x82194780;
	sub_8218A758(ctx, base);
	// b 0x821947a8
	goto loc_821947A8;
	// li r9,8
	ctx.r9.s64 = 8;
	// b 0x82194790
	goto loc_82194790;
	// li r9,9
	ctx.r9.s64 = 9;
loc_82194790:
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,64
	ctx.r7.s64 = 64;
loc_82194798:
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x821947A8;
	sub_8218A6E0(ctx, base);
loc_821947A8:
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

PPC_WEAK_FUNC(sub_821945C8) {
	__imp__sub_821945C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821947C0) {
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
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x821884b0
	ctx.lr = 0x821947DC;
	sub_821884B0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_821947C0) {
	__imp__sub_821947C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194818) {
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
	// bl 0x821884b0
	ctx.lr = 0x8219483C;
	sub_821884B0(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8219485c
	if (cr6.eq) goto loc_8219485C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82194850;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_8219485C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x8219487c
	if (!cr6.eq) goto loc_8219487C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82194898
	if (!cr6.eq) goto loc_82194898;
loc_8219487C:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x8219488c
	if (cr6.eq) goto loc_8219488C;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x821948ac
	if (!cr6.eq) goto loc_821948AC;
loc_8219488C:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821948ac
	if (cr6.eq) goto loc_821948AC;
loc_82194898:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x821948A0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_821948AC:
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

PPC_WEAK_FUNC(sub_82194818) {
	__imp__sub_82194818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821948C8) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x821948fc
	if (!cr6.eq) goto loc_821948FC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821948fc
	if (cr6.eq) goto loc_821948FC;
	// bl 0x82177a08
	ctx.lr = 0x821948F8;
	sub_82177A08(ctx, base);
	// b 0x82194914
	goto loc_82194914;
loc_821948FC:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x8219490c
	if (cr6.eq) goto loc_8219490C;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x82194914
	if (!cr6.eq) goto loc_82194914;
loc_8219490C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82194914;
	sub_82130588(ctx, base);
loc_82194914:
	// li r11,0
	r11.s64 = 0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bl 0x82130588
	ctx.lr = 0x82194928;
	sub_82130588(ctx, base);
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82194944
	if (cr6.eq) goto loc_82194944;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821948c8
	ctx.lr = 0x8219493C;
	sub_821948C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82194944;
	sub_82130588(ctx, base);
loc_82194944:
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_821948C8) {
	__imp__sub_821948C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194958) {
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
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8219497C;
	sub_82130588(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821378b8
	ctx.lr = 0x82194984;
	sub_821378B8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_82194958) {
	__imp__sub_82194958(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821949A0) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x821949dc
	if (!cr6.eq) goto loc_821949DC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821949dc
	if (cr6.eq) goto loc_821949DC;
	// bl 0x82177a08
	ctx.lr = 0x821949D8;
	sub_82177A08(ctx, base);
	// b 0x821949f4
	goto loc_821949F4;
loc_821949DC:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x821949ec
	if (cr6.eq) goto loc_821949EC;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x821949f4
	if (!cr6.eq) goto loc_821949F4;
loc_821949EC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821949F4;
	sub_82130588(ctx, base);
loc_821949F4:
	// li r11,0
	r11.s64 = 0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bl 0x82130588
	ctx.lr = 0x82194A08;
	sub_82130588(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x821378b8
	ctx.lr = 0x82194A30;
	sub_821378B8(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r6,20(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// stb r7,28(r31)
	PPC_STORE_U8(r31.u32 + 28, ctx.r7.u8);
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

PPC_WEAK_FUNC(sub_821949A0) {
	__imp__sub_821949A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82194A5C) {
	__imp__sub_82194A5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194A60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82194818
	sub_82194818(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82194A60) {
	__imp__sub_82194A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194A6C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82194A6C) {
	__imp__sub_82194A6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194A70) {
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
	ctx.lr = 0x82194A78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x82194A88;
	sub_821D2970(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stb r29,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r29.u8);
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-14524
	ctx.r10.s64 = r11.s64 + -14524;
	// stb r30,9(r31)
	PPC_STORE_U8(r31.u32 + 9, r30.u8);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stb r30,10(r31)
	PPC_STORE_U8(r31.u32 + 10, r30.u8);
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// bl 0x82189b70
	ctx.lr = 0x82194AB4;
	sub_82189B70(ctx, base);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82194A70) {
	__imp__sub_82194A70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194AC8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-14524
	ctx.r10.s64 = r11.s64 + -14524;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x82130588
	ctx.lr = 0x82194AF0;
	sub_82130588(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82189b98
	ctx.lr = 0x82194AF8;
	sub_82189B98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x82194B00;
	sub_821D2810(ctx, base);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_82194AC8) {
	__imp__sub_82194AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82194B14) {
	__imp__sub_82194B14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194B18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82194B48;
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

PPC_WEAK_FUNC(sub_82194B18) {
	__imp__sub_82194B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194B58) {
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
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82194B60;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9c4
	ctx.lr = 0x82194B68;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32131
	r31.s64 = -2105737216;
	// lwz r29,332(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// li r30,-1
	r30.s64 = -1;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// lwz r11,23648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23648);
	// fmr f27,f5
	f27.f64 = ctx.f5.f64;
	// fmr f26,f6
	f26.f64 = ctx.f6.f64;
	// fmr f25,f7
	f25.f64 = ctx.f7.f64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// fmr f24,f8
	f24.f64 = ctx.f8.f64;
	// fmr f23,f9
	f23.f64 = ctx.f9.f64;
	// bne cr6,0x82194bbc
	if (!cr6.eq) goto loc_82194BBC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,23660(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 23660);
	// stw r11,23648(r31)
	PPC_STORE_U32(r31.u32 + 23648, r11.u32);
	// b 0x82194bf0
	goto loc_82194BF0;
loc_82194BBC:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x82194bec
	if (!cr6.eq) goto loc_82194BEC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194BD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-14444
	ctx.r3.s64 = ctx.r9.s64 + -14444;
	// bl 0x82130000
	ctx.lr = 0x82194BE8;
	sub_82130000(ctx, base);
	// lwz r11,23648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23648);
loc_82194BEC:
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82194BF0:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187f40
	ctx.lr = 0x82194C04;
	sub_82187F40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// stw r30,23648(r31)
	PPC_STORE_U32(r31.u32 + 23648, r30.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82194ca0
	if (!cr6.gt) goto loc_82194CA0;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,8
	r30.s64 = 8;
loc_82194C20:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187b88
	ctx.lr = 0x82194C2C;
	sub_82187B88(ctx, base);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82194c48
	if (!cr6.eq) goto loc_82194C48;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8218f118
	ctx.lr = 0x82194C48;
	sub_8218F118(ctx, base);
loc_82194C48:
	// addi r11,r1,324
	r11.s64 = ctx.r1.s64 + 324;
	// fmr f9,f23
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f23.f64;
	// fmr f8,f24
	ctx.f8.f64 = f24.f64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// fmr f7,f25
	ctx.f7.f64 = f25.f64;
	// fmr f6,f26
	ctx.f6.f64 = f26.f64;
	// fmr f5,f27
	ctx.f5.f64 = f27.f64;
	// fmr f4,f28
	ctx.f4.f64 = f28.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8218f138
	ctx.lr = 0x82194C78;
	sub_8218F138(ctx, base);
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// bne 0x82194c8c
	if (!cr0.eq) goto loc_82194C8C;
	// bl 0x8218f130
	ctx.lr = 0x82194C8C;
	sub_8218F130(ctx, base);
loc_82194C8C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187ba8
	ctx.lr = 0x82194C94;
	sub_82187BA8(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82194c20
	if (cr6.lt) goto loc_82194C20;
loc_82194CA0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187bd0
	ctx.lr = 0x82194CA8;
	sub_82187BD0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba10
	ctx.lr = 0x82194CB4;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82194B58) {
	__imp__sub_82194B58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82194CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82194CC0;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194CE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821953b8
	if (cr6.eq) goto loc_821953B8;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r29,-32255
	r29.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r31,-32255
	r31.s64 = -2113863680;
	// lis r30,-32255
	r30.s64 = -2113863680;
	// lis r28,-32255
	r28.s64 = -2113863680;
	// lis r27,-32255
	r27.s64 = -2113863680;
	// lis r26,-32255
	r26.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r10,-14400
	ctx.r10.s64 = ctx.r10.s64 + -14400;
	// addi r14,r29,-19204
	r14.s64 = r29.s64 + -19204;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r22,r9,-14832
	r22.s64 = ctx.r9.s64 + -14832;
	// addi r23,r8,-25064
	r23.s64 = ctx.r8.s64 + -25064;
	// addi r21,r7,-19172
	r21.s64 = ctx.r7.s64 + -19172;
	// addi r20,r6,-19140
	r20.s64 = ctx.r6.s64 + -19140;
	// addi r19,r5,-19152
	r19.s64 = ctx.r5.s64 + -19152;
	// addi r18,r4,-19160
	r18.s64 = ctx.r4.s64 + -19160;
	// addi r17,r3,-19180
	r17.s64 = ctx.r3.s64 + -19180;
	// addi r16,r31,-19188
	r16.s64 = r31.s64 + -19188;
	// addi r15,r30,-19196
	r15.s64 = r30.s64 + -19196;
	// addi r28,r28,-19208
	r28.s64 = r28.s64 + -19208;
	// addi r27,r27,-20892
	r27.s64 = r27.s64 + -20892;
	// addi r26,r26,-29624
	r26.s64 = r26.s64 + -29624;
	// addi r29,r11,-29628
	r29.s64 = r11.s64 + -29628;
loc_82194D6C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
loc_82194D74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194d98
	if (cr6.eq) goto loc_82194D98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194d74
	if (cr6.eq) goto loc_82194D74;
loc_82194D98:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821953b8
	if (cr6.eq) goto loc_821953B8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821d0898
	ctx.lr = 0x82194DAC;
	sub_821D0898(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82194DD8;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82194dfc
	if (cr6.eq) goto loc_82194DFC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82194DFC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// bl 0x8218a568
	ctx.lr = 0x82194E0C;
	sub_8218A568(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82195340
	if (cr6.eq) goto loc_82195340;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82194E20:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194e44
	if (cr6.eq) goto loc_82194E44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194e20
	if (cr6.eq) goto loc_82194E20;
loc_82194E44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82194e7c
	if (!cr6.eq) goto loc_82194E7C;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a788
	ctx.lr = 0x82194E78;
	sub_8218A788(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82194E7C:
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82194E84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194ea8
	if (cr6.eq) goto loc_82194EA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194e84
	if (cr6.eq) goto loc_82194E84;
loc_82194EA8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82194ef0
	if (!cr6.eq) goto loc_82194EF0;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82194EEC;
	sub_8218A6E0(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82194EF0:
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82194EF8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194f1c
	if (cr6.eq) goto loc_82194F1C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194ef8
	if (cr6.eq) goto loc_82194EF8;
loc_82194F1C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82194f64
	if (!cr6.eq) goto loc_82194F64;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194F40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82194F60;
	sub_8218A6E0(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82194F64:
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82194F6C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82194f90
	if (cr6.eq) goto loc_82194F90;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194f6c
	if (cr6.eq) goto loc_82194F6C;
loc_82194F90:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82194fd8
	if (!cr6.eq) goto loc_82194FD8;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82194FB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82194FD4;
	sub_8218A6E0(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82194FD8:
	// mr r10,r17
	ctx.r10.u64 = r17.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82194FE0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82195004
	if (cr6.eq) goto loc_82195004;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82194fe0
	if (cr6.eq) goto loc_82194FE0;
loc_82195004:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8219504c
	if (!cr6.eq) goto loc_8219504C;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195028;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82195048;
	sub_8218A6E0(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_8219504C:
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82195054:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82195078
	if (cr6.eq) goto loc_82195078;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82195054
	if (cr6.eq) goto loc_82195054;
loc_82195078:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821950b8
	if (!cr6.eq) goto loc_821950B8;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195098;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// xori r6,r8,1
	ctx.r6.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a758
	ctx.lr = 0x821950B4;
	sub_8218A758(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_821950B8:
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_821950C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821950e4
	if (cr6.eq) goto loc_821950E4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821950c0
	if (cr6.eq) goto loc_821950C0;
loc_821950E4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82195180
	if (!cr6.eq) goto loc_82195180;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195108;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82195124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82195140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8219515C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x8219517C;
	sub_8218A6E0(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82195180:
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82195188:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821951ac
	if (cr6.eq) goto loc_821951AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82195188
	if (cr6.eq) goto loc_82195188;
loc_821951AC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82195248
	if (!cr6.eq) goto loc_82195248;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821951D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821951EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82195208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82195244;
	sub_8218A6E0(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82195248:
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_82195250:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82195274
	if (cr6.eq) goto loc_82195274;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82195250
	if (cr6.eq) goto loc_82195250;
loc_82195274:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82195334
	if (!cr6.eq) goto loc_82195334;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
loc_821952A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821952c4
	if (cr6.eq) goto loc_821952C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821952a0
	if (cr6.eq) goto loc_821952A0;
loc_821952C4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82195340
	if (cr6.eq) goto loc_82195340;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
loc_821952D4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821952f8
	if (cr6.eq) goto loc_821952F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821952d4
	if (cr6.eq) goto loc_821952D4;
loc_821952F8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82195340
	if (cr6.eq) goto loc_82195340;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82181330
	ctx.lr = 0x82195308;
	sub_82181330(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// bl 0x82189ce0
	ctx.lr = 0x82195320;
	sub_82189CE0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82195340
	if (cr6.eq) goto loc_82195340;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82177a08
	ctx.lr = 0x82195330;
	sub_82177A08(ctx, base);
	// b 0x82195340
	goto loc_82195340;
loc_82195334:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821bd618
	ctx.lr = 0x82195340;
	sub_821BD618(ctx, base);
loc_82195340:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82195350;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82195394
	if (!cr6.eq) goto loc_82195394;
loc_8219535C:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82195388;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8219535c
	if (cr6.eq) goto loc_8219535C;
loc_82195394:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821953B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82194d6c
	if (!cr6.eq) goto loc_82194D6C;
loc_821953B8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82194CB8) {
	__imp__sub_82194CB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821953C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821953C4) {
	__imp__sub_821953C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821953C8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-14524
	ctx.r10.s64 = r11.s64 + -14524;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x82130588
	ctx.lr = 0x821953F8;
	sub_82130588(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82189b98
	ctx.lr = 0x82195400;
	sub_82189B98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x82195408;
	sub_821D2810(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82195420
	if (cr6.eq) goto loc_82195420;
	// bl 0x82130588
	ctx.lr = 0x8219541C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82195420:
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

PPC_WEAK_FUNC(sub_821953C8) {
	__imp__sub_821953C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195438) {
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821954ac
	if (cr6.eq) goto loc_821954AC;
loc_8219546C:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x821954a0
	if (!cr6.eq) goto loc_821954A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821954a0
	if (cr6.lt) goto loc_821954A0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x821954a0
	if (!cr6.lt) goto loc_821954A0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_821954A0:
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8219546c
	if (!cr6.eq) goto loc_8219546C;
loc_821954AC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8218a5f8
	ctx.lr = 0x821954B8;
	sub_8218A5F8(ctx, base);
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

PPC_WEAK_FUNC(sub_82195438) {
	__imp__sub_82195438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821954D0) {
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
	// bl 0x821d2970
	ctx.lr = 0x821954F0;
	sub_821D2970(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,-14524
	ctx.r10.s64 = r11.s64 + -14524;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8218b708
	ctx.lr = 0x82195508;
	sub_8218B708(ctx, base);
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82195528
	if (cr6.eq) goto loc_82195528;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8219551C;
	sub_8217D890(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_82195528:
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

PPC_WEAK_FUNC(sub_821954D0) {
	__imp__sub_821954D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82195544) {
	__imp__sub_82195544(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195548) {
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
	ctx.lr = 0x82195550;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,56(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82195610
	if (cr6.eq) goto loc_82195610;
	// clrlwi r26,r6,24
	r26.u64 = ctx.r6.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
loc_82195574:
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// lwzx r31,r11,r28
	r31.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// beq cr6,0x821955a0
	if (cr6.eq) goto loc_821955A0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82195598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// beq cr6,0x821955fc
	if (cr6.eq) goto loc_821955FC;
loc_821955A0:
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x821955A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821955b8
	if (cr6.eq) goto loc_821955B8;
	// bl 0x821947c0
	ctx.lr = 0x821955B4;
	sub_821947C0(ctx, base);
	// b 0x821955bc
	goto loc_821955BC;
loc_821955B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821955BC:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82194958
	ctx.lr = 0x821955C8;
	sub_82194958(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821955DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821945c0
	ctx.lr = 0x821955E8;
	sub_821945C0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82196d80
	ctx.lr = 0x821955F4;
	sub_82196D80(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r30,r11,24
	r30.s64 = r11.s64 + 24;
loc_821955FC:
	// lhz r11,56(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 56);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82195574
	if (cr6.lt) goto loc_82195574;
loc_82195610:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82195548) {
	__imp__sub_82195548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195618) {
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
	ctx.lr = 0x82195620;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8219a1c8
	ctx.lr = 0x82195638;
	sub_8219A1C8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821973a8
	ctx.lr = 0x82195640;
	sub_821973A8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82198180
	ctx.lr = 0x82195650;
	sub_82198180(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82195674
	if (!cr6.eq) goto loc_82195674;
	// bl 0x82199818
	ctx.lr = 0x82195660;
	sub_82199818(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82197448
	ctx.lr = 0x82195668;
	sub_82197448(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
loc_82195674:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82195548
	ctx.lr = 0x82195688;
	sub_82195548(ctx, base);
	// bl 0x82199818
	ctx.lr = 0x8219568C;
	sub_82199818(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82197448
	ctx.lr = 0x82195694;
	sub_82197448(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82195618) {
	__imp__sub_82195618(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821956A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r5,r6,-19208
	ctx.r5.s64 = ctx.r6.s64 + -19208;
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lfs f12,8884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8884);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stfs f12,44(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stb r11,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, r11.u8);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r4,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821956A0) {
	__imp__sub_821956A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x82195730
	if (!cr6.eq) goto loc_82195730;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82195730:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mulli r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 * 28;
	// lwz r11,-13180(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -13180);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82195720) {
	__imp__sub_82195720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82195744) {
	__imp__sub_82195744(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195748) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-14060
	ctx.r10.s64 = r11.s64 + -14060;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82195774;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8219577C;
	sub_82130588(ctx, base);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82195798
	if (cr6.eq) goto loc_82195798;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821948c8
	ctx.lr = 0x82195790;
	sub_821948C8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82195798;
	sub_82130588(ctx, base);
loc_82195798:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821957b8
	if (cr6.eq) goto loc_821957B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821957B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821957B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x821957C0;
	sub_821D2028(ctx, base);
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

PPC_WEAK_FUNC(sub_82195748) {
	__imp__sub_82195748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821957D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_821957E4:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x821957e4
	if (!cr0.eq) goto loc_821957E4;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_821957D8) {
	__imp__sub_821957D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821957FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821957FC) {
	__imp__sub_821957FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195800) {
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
	// lis r11,2340
	r11.s64 = 153354240;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r10,r11,37449
	ctx.r10.u64 = r11.u64 | 37449;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82195838
	if (cr6.gt) goto loc_82195838;
	// mulli r11,r31,28
	r11.s64 = r31.s64 * 28;
	// li r10,-5
	ctx.r10.s64 = -5;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8219583c
	if (!cr6.gt) goto loc_8219583C;
loc_82195838:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8219583C:
	// bl 0x82130528
	ctx.lr = 0x82195840;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x82195894
	if (cr6.eq) goto loc_82195894;
	// addi r8,r3,4
	ctx.r8.s64 = ctx.r3.s64 + 4;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// blt 0x82195898
	if (cr0.lt) goto loc_82195898;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r7,r7,-14060
	ctx.r7.s64 = ctx.r7.s64 + -14060;
loc_82195868:
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
	// stb r9,25(r11)
	PPC_STORE_U8(r11.u32 + 25, ctx.r9.u8);
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// addi r11,r11,28
	r11.s64 = r11.s64 + 28;
	// bge 0x82195868
	if (!cr0.lt) goto loc_82195868;
	// b 0x82195898
	goto loc_82195898;
loc_82195894:
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_82195898:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r7,r11,-13180
	ctx.r7.s64 = r11.s64 + -13180;
	// stw r8,-13180(r11)
	PPC_STORE_U32(r11.u32 + -13180, ctx.r8.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stw r10,-13188(r6)
	PPC_STORE_U32(ctx.r6.u32 + -13188, ctx.r10.u32);
	// stw r31,-13184(r5)
	PPC_STORE_U32(ctx.r5.u32 + -13184, r31.u32);
	// ble cr6,0x821958e4
	if (!cr6.gt) goto loc_821958E4;
	// b 0x821958cc
	goto loc_821958CC;
loc_821958C8:
	// lwz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
loc_821958CC:
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,28
	ctx.r10.s64 = ctx.r10.s64 + 28;
	// stw r11,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// blt cr6,0x821958c8
	if (cr6.lt) goto loc_821958C8;
loc_821958E4:
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r9,-13168(r8)
	PPC_STORE_U32(ctx.r8.u32 + -13168, ctx.r9.u32);
	// stw r11,-13172(r10)
	PPC_STORE_U32(ctx.r10.u32 + -13172, r11.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_82195800) {
	__imp__sub_82195800(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8219590C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8219590C) {
	__imp__sub_8219590C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195910) {
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
	ctx.lr = 0x82195918;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r26,0,30,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821959d4
	if (cr6.eq) goto loc_821959D4;
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// addi r27,r31,-4
	r27.s64 = r31.s64 + -4;
	// mulli r11,r10,28
	r11.s64 = ctx.r10.s64 * 28;
	// addic. r29,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r29.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// blt 0x821959b4
	if (cr0.lt) goto loc_821959B4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r28,r11,-14060
	r28.s64 = r11.s64 + -14060;
loc_82195950:
	// addi r31,r31,-28
	r31.s64 = r31.s64 + -28;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82195960;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82195968;
	sub_82130588(ctx, base);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82195984
	if (cr6.eq) goto loc_82195984;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821948c8
	ctx.lr = 0x8219597C;
	sub_821948C8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82195984;
	sub_82130588(ctx, base);
loc_82195984:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821959a4
	if (cr6.eq) goto loc_821959A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821959A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821959A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x821959AC;
	sub_821D2028(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x82195950
	if (!cr0.lt) goto loc_82195950;
loc_821959B4:
	// clrlwi r11,r26,31
	r11.u64 = r26.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821959c8
	if (cr6.eq) goto loc_821959C8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x821959C8;
	sub_82130588(ctx, base);
loc_821959C8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821959D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82195748
	ctx.lr = 0x821959DC;
	sub_82195748(ctx, base);
	// clrlwi r11,r26,31
	r11.u64 = r26.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821959f0
	if (cr6.eq) goto loc_821959F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821959F0;
	sub_82130588(ctx, base);
loc_821959F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82195910) {
	__imp__sub_82195910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_821959FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_821959FC) {
	__imp__sub_821959FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82195A00) {
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
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r11,-13180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -13180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82195a50
	if (cr6.eq) goto loc_82195A50;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82195a4c
	if (cr6.eq) goto loc_82195A4C;
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
	ctx.lr = 0x82195A48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82195a50
	goto loc_82195A50;
loc_82195A4C:
	// bl 0x82130588
	ctx.lr = 0x82195A50;
	sub_82130588(ctx, base);
loc_82195A50:
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-13180(r31)
	PPC_STORE_U32(r31.u32 + -13180, r11.u32);
	// stw r10,-13188(r8)
	PPC_STORE_U32(ctx.r8.u32 + -13188, ctx.r10.u32);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// stw r9,-13184(r7)
	PPC_STORE_U32(ctx.r7.u32 + -13184, ctx.r9.u32);
	// lwz r3,-13176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -13176);
	// bl 0x82130588
	ctx.lr = 0x82195A7C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-13176(r31)
	PPC_STORE_U32(r31.u32 + -13176, r11.u32);
	// addi r1,r1,96
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

PPC_WEAK_FUNC(sub_82195A00) {
	__imp__sub_82195A00(ctx, base);
}

