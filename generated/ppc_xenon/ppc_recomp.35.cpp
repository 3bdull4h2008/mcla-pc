#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82268A88"))) PPC_WEAK_FUNC(sub_82268A88);
PPC_FUNC_IMPL(__imp__sub_82268A88) {
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
	ctx.lr = 0x82268A90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,160(r29)
	PPC_STORE_U32(r29.u32 + 160, r11.u32);
	// ble 0x82268b28
	if (!cr0.gt) goto loc_82268B28;
	// lwz r31,168(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 168);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82268ae0
	if (!cr6.lt) goto loc_82268AE0;
	// mulli r11,r31,368
	r11.s64 = r31.s64 * 368;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r30,r11,176
	r30.s64 = r11.s64 + 176;
loc_82268AC0:
	// addi r4,r30,368
	ctx.r4.s64 = r30.s64 + 368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82264c90
	ctx.lr = 0x82268ACC;
	sub_82264C90(ctx, base);
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82268ac0
	if (cr6.lt) goto loc_82268AC0;
loc_82268AE0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-4944(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82268b00
	if (cr6.eq) goto loc_82268B00;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x82268b04
	goto loc_82268B04;
loc_82268B00:
	// li r11,0
	r11.s64 = 0;
loc_82268B04:
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822523f0
	ctx.lr = 0x82268B10;
	sub_822523F0(ctx, base);
	// lwz r3,11584(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 11584);
	// bl 0x822635f0
	ctx.lr = 0x82268B18;
	sub_822635F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82252948
	ctx.lr = 0x82268B28;
	sub_82252948(ctx, base);
loc_82268B28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82268B30"))) PPC_WEAK_FUNC(sub_82268B30);
PPC_FUNC_IMPL(__imp__sub_82268B30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82268B38;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82387ba0
	ctx.lr = 0x82268B4C;
	sub_82387BA0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// addi r29,r11,-12360
	r29.s64 = r11.s64 + -12360;
	// lfs f31,30712(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82269098
	if (cr6.eq) goto loc_82269098;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwzx r6,r8,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// lwzx r27,r10,r7
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xor r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// and r25,r3,r5
	r25.u64 = ctx.r3.u64 & ctx.r5.u64;
	// bne cr6,0x82268bdc
	if (!cr6.eq) goto loc_82268BDC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268BB4;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82268BB8;
	sub_822A5578(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82268BC4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268bdc
	if (cr6.eq) goto loc_82268BDC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268BDC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r29
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x82268c28
	if (!cr6.eq) goto loc_82268C28;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268BFC;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82268C00;
	sub_822A5578(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82268C0C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268c6c
	if (cr6.eq) goto loc_82268C6C;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82268c6c
	if (!cr6.eq) goto loc_82268C6C;
	// b 0x82268c58
	goto loc_82268C58;
loc_82268C28:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bne cr6,0x82268c6c
	if (!cr6.eq) goto loc_82268C6C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268C3C;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82268C40;
	sub_822A5578(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82268C4C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268c6c
	if (cr6.eq) goto loc_82268C6C;
loc_82268C58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252ab8
	ctx.lr = 0x82268C60;
	sub_82252AB8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268C6C:
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// li r26,1
	r26.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268fe0
	if (cr6.eq) goto loc_82268FE0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,14
	cr6.compare<int32_t>(ctx.r9.s32, 14, xer);
	// bne cr6,0x82268cbc
	if (!cr6.eq) goto loc_82268CBC;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82268cbc
	if (!cr6.eq) goto loc_82268CBC;
	// rlwinm r11,r25,0,22,22
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268cbc
	if (cr6.eq) goto loc_82268CBC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268a88
	ctx.lr = 0x82268CB0;
	sub_82268A88(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268CBC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,11
	cr6.compare<int32_t>(ctx.r9.s32, 11, xer);
	// beq cr6,0x82268cdc
	if (cr6.eq) goto loc_82268CDC;
	// lbz r11,22(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d18
	if (cr6.eq) goto loc_82268D18;
loc_82268CDC:
	// rlwinm r11,r25,0,29,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d18
	if (cr6.eq) goto loc_82268D18;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252948
	ctx.lr = 0x82268CF8;
	sub_82252948(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,11
	cr6.compare<int32_t>(ctx.r9.s32, 11, xer);
	// bne cr6,0x82268d14
	if (!cr6.eq) goto loc_82268D14;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268D14:
	// stb r26,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r26.u8);
loc_82268D18:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,12
	cr6.compare<int32_t>(ctx.r9.s32, 12, xer);
	// beq cr6,0x82268d38
	if (cr6.eq) goto loc_82268D38;
	// lbz r11,23(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 23);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d74
	if (cr6.eq) goto loc_82268D74;
loc_82268D38:
	// rlwinm r11,r25,0,28,28
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268d74
	if (cr6.eq) goto loc_82268D74;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252948
	ctx.lr = 0x82268D54;
	sub_82252948(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,12
	cr6.compare<int32_t>(ctx.r9.s32, 12, xer);
	// bne cr6,0x82268d70
	if (!cr6.eq) goto loc_82268D70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268D70:
	// stb r26,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r26.u8);
loc_82268D74:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,5
	cr6.compare<int32_t>(ctx.r9.s32, 5, xer);
	// beq cr6,0x82268d98
	if (cr6.eq) goto loc_82268D98;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268e48
	if (cr6.eq) goto loc_82268E48;
loc_82268D98:
	// rlwinm r11,r27,0,19,19
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268dbc
	if (cr6.eq) goto loc_82268DBC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// b 0x82268ddc
	goto loc_82268DDC;
loc_82268DBC:
	// rlwinm r11,r27,0,17,17
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268e44
	if (cr6.eq) goto loc_82268E44;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_82268DDC:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,-4944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,14988(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f12,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f0,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsel f0,f9,f12,f10
	f0.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// stfs f0,-13512(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -13512, temp.u32);
	// lwz r6,168(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r6,368
	r11.s64 = ctx.r6.s64 * 368;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stfs f0,356(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 356, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lfs f0,-13512(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f0,352(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 352, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// bl 0x822627c0
	ctx.lr = 0x82268E3C;
	sub_822627C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268808
	ctx.lr = 0x82268E44;
	sub_82268808(ctx, base);
loc_82268E44:
	// stb r26,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r26.u8);
loc_82268E48:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,6
	cr6.compare<int32_t>(ctx.r9.s32, 6, xer);
	// beq cr6,0x82268e68
	if (cr6.eq) goto loc_82268E68;
	// lbz r11,21(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268f04
	if (cr6.eq) goto loc_82268F04;
loc_82268E68:
	// rlwinm r11,r27,0,16,16
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268e8c
	if (cr6.eq) goto loc_82268E8C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-13516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13516);
	f0.f64 = double(temp.f32);
	// lfs f13,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// b 0x82268eac
	goto loc_82268EAC;
loc_82268E8C:
	// rlwinm r11,r27,0,18,18
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268f00
	if (cr6.eq) goto loc_82268F00;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-13516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13516);
	f0.f64 = double(temp.f32);
	// lfs f13,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
loc_82268EAC:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,-4944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f13,27640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f12,-11624(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -11624);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f0,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsel f0,f9,f12,f10
	f0.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// stfs f0,-13516(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -13516, temp.u32);
	// lwz r7,168(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r7,368
	r11.s64 = ctx.r7.s64 * 368;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// stfs f0,344(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 344, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// bl 0x822627c0
	ctx.lr = 0x82268EF8;
	sub_822627C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268870
	ctx.lr = 0x82268F00;
	sub_82268870(ctx, base);
loc_82268F00:
	// stb r26,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r26.u8);
loc_82268F04:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,9
	cr6.compare<int32_t>(ctx.r9.s32, 9, xer);
	// beq cr6,0x82268f24
	if (cr6.eq) goto loc_82268F24;
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268fe0
	if (cr6.eq) goto loc_82268FE0;
loc_82268F24:
	// rlwinm r11,r25,0,25,25
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82268fe0
	if (cr6.eq) goto loc_82268FE0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82268F3C;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// ori r5,r9,54592
	ctx.r5.u64 = ctx.r9.u64 | 54592;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32122
	r28.s64 = -2105147392;
	// li r4,0
	ctx.r4.s64 = 0;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,2272
	r28.s64 = r28.s64 + 2272;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a3998
	ctx.lr = 0x82268FA0;
	sub_822A3998(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x82268FC0;
	sub_822A9930(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r29
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	// cmpwi cr6,r6,9
	cr6.compare<int32_t>(ctx.r6.s32, 9, xer);
	// bne cr6,0x82268fdc
	if (!cr6.eq) goto loc_82268FDC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82268FDC:
	// stb r26,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r26.u8);
loc_82268FE0:
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82269018
	if (cr6.eq) goto loc_82269018;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r29
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82269014
	if (cr6.eq) goto loc_82269014;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82269014
	if (cr6.eq) goto loc_82269014;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82269018
	if (!cr6.eq) goto loc_82269018;
loc_82269014:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82269018:
	// rlwinm r11,r25,0,23,23
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82269098
	if (cr6.eq) goto loc_82269098;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r29
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// beq cr6,0x8226906c
	if (cr6.eq) goto loc_8226906C;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226906c
	if (!cr6.eq) goto loc_8226906C;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x82269098
	if (!cr6.eq) goto loc_82269098;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252e10
	ctx.lr = 0x82269058;
	sub_82252E10(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// b 0x82269088
	goto loc_82269088;
loc_8226906C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252e10
	ctx.lr = 0x82269078;
	sub_82252E10(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmpwi cr6,r9,7
	cr6.compare<int32_t>(ctx.r9.s32, 7, xer);
loc_82269088:
	// bne cr6,0x82269094
	if (!cr6.eq) goto loc_82269094;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82269094:
	// stb r26,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r26.u8);
loc_82269098:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r29
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x822691fc
	if (cr6.gt) goto loc_822691FC;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-28476
	r12.s64 = r12.s64 + -28476;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82269108;
	case 1:
		goto loc_82269108;
	case 2:
		goto loc_82269108;
	case 3:
		goto loc_82269108;
	case 4:
		goto loc_82269130;
	case 5:
		goto loc_82269144;
	case 6:
		goto loc_82269144;
	case 7:
		goto loc_822691FC;
	case 8:
		goto loc_822691FC;
	case 9:
		goto loc_82269164;
	case 10:
		goto loc_822691FC;
	case 11:
		goto loc_82269164;
	case 12:
		goto loc_82269164;
	case 13:
		goto loc_822691C4;
	case 14:
		goto loc_82269184;
	case 15:
		goto loc_822691A4;
	case 16:
		goto loc_822691A4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28408(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28408);
	// lwz r17,-28368(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28368);
	// lwz r17,-28348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28348);
	// lwz r17,-28348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28348);
	// lwz r17,-28164(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28164);
	// lwz r17,-28164(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28164);
	// lwz r17,-28316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28316);
	// lwz r17,-28164(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28164);
	// lwz r17,-28316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28316);
	// lwz r17,-28316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28316);
	// lwz r17,-28220(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28220);
	// lwz r17,-28284(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28284);
	// lwz r17,-28252(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28252);
	// lwz r17,-28252(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -28252);
loc_82269108:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4632
	ctx.r5.s64 = r11.s64 + -4632;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x8226911C;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822688d8
	ctx.lr = 0x82269124;
	sub_822688D8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269130:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822689b0
	ctx.lr = 0x82269138;
	sub_822689B0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269144:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4712
	ctx.r5.s64 = r11.s64 + -4712;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x82269158;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269164:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4800
	ctx.r5.s64 = r11.s64 + -4800;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x82269178;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82269184:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4880
	ctx.r5.s64 = r11.s64 + -4880;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x82269198;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822691A4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,120
	ctx.r4.s64 = 120;
	// addi r5,r11,-4944
	ctx.r5.s64 = r11.s64 + -4944;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x822691B8;
	sub_82137A08(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822691C4:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// lfs f13,-4304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4304);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,-4304(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4304, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822691fc
	if (!cr6.gt) goto loc_822691FC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,14(r31)
	PPC_STORE_U8(r31.u32 + 14, ctx.r9.u8);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-4304(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4304, temp.u32);
loc_822691FC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82269208"))) PPC_WEAK_FUNC(sub_82269208);
PPC_FUNC_IMPL(__imp__sub_82269208) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
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
	// bl 0x82255e68
	ctx.lr = 0x82269250;
	sub_82255E68(ctx, base);
	// lwz r7,3196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3196);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,3196(r31)
	PPC_STORE_U32(r31.u32 + 3196, ctx.r7.u32);
	// lwz r6,3200(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 3200);
	// stw r6,3200(r31)
	PPC_STORE_U32(r31.u32 + 3200, ctx.r6.u32);
	// lwz r5,3204(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 3204);
	// stw r5,3204(r31)
	PPC_STORE_U32(r31.u32 + 3204, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_82269284"))) PPC_WEAK_FUNC(sub_82269284);
PPC_FUNC_IMPL(__imp__sub_82269284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269288"))) PPC_WEAK_FUNC(sub_82269288);
PPC_FUNC_IMPL(__imp__sub_82269288) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,3080(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3080);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822692b8
	if (!cr6.gt) goto loc_822692B8;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_8226929C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822692c0
	if (cr6.eq) goto loc_822692C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8226929c
	if (cr6.lt) goto loc_8226929C;
loc_822692B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822692C0:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822692D8"))) PPC_WEAK_FUNC(sub_822692D8);
PPC_FUNC_IMPL(__imp__sub_822692D8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,3080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x82145020
	ctx.lr = 0x82269300;
	sub_82145020(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82269328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8226935c
	if (cr6.eq) goto loc_8226935C;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// lwz r9,3080(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r8,r10,r9
	ctx.r8.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// andc r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// twllei r9,0
	// subf r31,r6,r10
	r31.s64 = ctx.r10.s64 - ctx.r6.s64;
	// twlgei r5,-1
loc_8226935C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
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

__attribute__((alias("__imp__sub_82269388"))) PPC_WEAK_FUNC(sub_82269388);
PPC_FUNC_IMPL(__imp__sub_82269388) {
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
	// lwz r9,3080(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3080);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82269400
	if (!cr6.gt) goto loc_82269400;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_822693B0:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// beq cr6,0x822693e4
	if (cr6.eq) goto loc_822693E4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822693b0
	if (cr6.lt) goto loc_822693B0;
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
loc_822693E4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82269418
	if (!cr6.eq) goto loc_82269418;
loc_82269400:
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
loc_82269418:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226942C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82269460
	if (cr6.eq) goto loc_82269460;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82269400
	if (cr6.eq) goto loc_82269400;
	// lbz r11,278(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82269400
	if (!cr6.eq) goto loc_82269400;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82269458;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82269400
	if (!cr6.eq) goto loc_82269400;
loc_82269460:
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

__attribute__((alias("__imp__sub_82269478"))) PPC_WEAK_FUNC(sub_82269478);
PPC_FUNC_IMPL(__imp__sub_82269478) {
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
	// stwu r1,-3312(r1)
	ea = -3312 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r31,0
	r31.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// bl 0x82250310
	ctx.lr = 0x822694B0;
	sub_82250310(ctx, base);
	// stw r31,3276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3276, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,3280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3280, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,3284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3284, r31.u32);
	// bl 0x82269208
	ctx.lr = 0x822694C8;
	sub_82269208(ctx, base);
	// addi r1,r1,3312
	ctx.r1.s64 = ctx.r1.s64 + 3312;
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

__attribute__((alias("__imp__sub_822694E0"))) PPC_WEAK_FUNC(sub_822694E0);
PPC_FUNC_IMPL(__imp__sub_822694E0) {
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
	// bl 0x822692d8
	ctx.lr = 0x82269500;
	sub_822692D8(ctx, base);
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

__attribute__((alias("__imp__sub_8226951C"))) PPC_WEAK_FUNC(sub_8226951C);
PPC_FUNC_IMPL(__imp__sub_8226951C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269520"))) PPC_WEAK_FUNC(sub_82269520);
PPC_FUNC_IMPL(__imp__sub_82269520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32217
	r11.s64 = -2111373312;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-27528
	ctx.r4.s64 = r11.s64 + -27528;
	// addi r3,r10,-4260
	ctx.r3.s64 = ctx.r10.s64 + -4260;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82269534"))) PPC_WEAK_FUNC(sub_82269534);
PPC_FUNC_IMPL(__imp__sub_82269534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269538"))) PPC_WEAK_FUNC(sub_82269538);
PPC_FUNC_IMPL(__imp__sub_82269538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32217
	r11.s64 = -2111373312;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-27424
	ctx.r4.s64 = r11.s64 + -27424;
	// addi r3,r10,-4236
	ctx.r3.s64 = ctx.r10.s64 + -4236;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226954C"))) PPC_WEAK_FUNC(sub_8226954C);
PPC_FUNC_IMPL(__imp__sub_8226954C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269550"))) PPC_WEAK_FUNC(sub_82269550);
PPC_FUNC_IMPL(__imp__sub_82269550) {
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
	// addi r10,r11,-3660
	ctx.r10.s64 = r11.s64 + -3660;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e6bc0
	ctx.lr = 0x8226957C;
	sub_822E6BC0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82269594
	if (cr6.eq) goto loc_82269594;
	// bl 0x82130588
	ctx.lr = 0x82269590;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82269594:
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

__attribute__((alias("__imp__sub_822695AC"))) PPC_WEAK_FUNC(sub_822695AC);
PPC_FUNC_IMPL(__imp__sub_822695AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822695B0"))) PPC_WEAK_FUNC(sub_822695B0);
PPC_FUNC_IMPL(__imp__sub_822695B0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-4216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4216);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822695e8
	if (cr6.eq) goto loc_822695E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822695E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822695E8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r10,-4288
	r30.s64 = ctx.r10.s64 + -4288;
	// stw r11,-4216(r31)
	PPC_STORE_U32(r31.u32 + -4216, r11.u32);
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822695FC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226961c
	if (cr6.eq) goto loc_8226961C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226961C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8226961C:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,72
	r11.s64 = r30.s64 + 72;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822695fc
	if (cr6.lt) goto loc_822695FC;
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

__attribute__((alias("__imp__sub_82269644"))) PPC_WEAK_FUNC(sub_82269644);
PPC_FUNC_IMPL(__imp__sub_82269644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269648"))) PPC_WEAK_FUNC(sub_82269648);
PPC_FUNC_IMPL(__imp__sub_82269648) {
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
	PPCRegister f0{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82269650;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d8
	ctx.lr = 0x82269658;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fmr f29,f2
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f2.f64;
	// lbz r10,-12256(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82269a5c
	if (cr6.eq) goto loc_82269A5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-4288
	ctx.r9.s64 = r11.s64 + -4288;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwzx r31,r10,r9
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bne cr6,0x82269a5c
	if (!cr6.eq) goto loc_82269A5C;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
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
	// li r4,0
	ctx.r4.s64 = 0;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,2
	ctx.r3.s64 = 2;
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217f768
	ctx.lr = 0x822696D0;
	sub_8217F768(ctx, base);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,-26876(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822696E0;
	sub_8217C088(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x822696E8;
	sub_8217D9A0(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x8217bb68
	ctx.lr = 0x822696FC;
	sub_8217BB68(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lfs f12,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f10,124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f10.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f9,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lfs f31,15360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15360);
	f31.f64 = double(temp.f32);
	// lis r25,-32124
	r25.s64 = -2105278464;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lis r24,-32124
	r24.s64 = -2105278464;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lis r23,-32124
	r23.s64 = -2105278464;
	// fmuls f0,f10,f31
	f0.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lis r22,-32124
	r22.s64 = -2105278464;
	// fmuls f12,f9,f31
	ctx.f12.f64 = double(float(ctx.f9.f64 * f31.f64));
	// lfs f3,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// lfs f30,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	f30.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fctiwz f10,f13
	ctx.f10.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f10.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f9,f11
	ctx.f9.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f9.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwimi r3,r8,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r3,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// bl 0x8217bc28
	ctx.lr = 0x822697B0;
	sub_8217BC28(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f12,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// lfs f10,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	ctx.f10.f64 = double(temp.f32);
	// addi r20,r11,-4176
	r20.s64 = r11.s64 + -4176;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// fctiwz f4,f11
	ctx.f4.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f4.u64);
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f3,f9
	ctx.f3.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f3.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lfs f8,140(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	ctx.f8.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f7,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fmuls f5,f7,f31
	ctx.f5.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fctiwz f2,f6
	ctx.f2.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f2,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f2.u64);
	// fctiwz f1,f5
	ctx.f1.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f1,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f1.u64);
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwimi r7,r4,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r7,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// ble cr6,0x8226987c
	if (!cr6.gt) goto loc_8226987C;
	// addi r30,r20,4
	r30.s64 = r20.s64 + 4;
	// b 0x82269838
	goto loc_82269838;
loc_82269834:
	// lwz r9,-26892(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -26892);
loc_82269838:
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f3,f0,f29
	ctx.f3.f64 = double(float(f0.f64 * f29.f64));
	// lfs f12,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fadds f2,f13,f30
	ctx.f2.f64 = double(float(ctx.f13.f64 + f30.f64));
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f12,f29
	ctx.f1.f64 = double(float(ctx.f12.f64 * f29.f64));
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82269868;
	sub_8217BC28(ctx, base);
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82269834
	if (cr6.lt) goto loc_82269834;
loc_8226987C:
	// bl 0x8217bc98
	ctx.lr = 0x82269880;
	sub_8217BC98(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// li r3,4
	ctx.r3.s64 = 4;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,-31384(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31384);
	f0.f64 = double(temp.f32);
	// fmuls f28,f29,f0
	f28.f64 = double(float(f29.f64 * f0.f64));
	// bl 0x8217bb68
	ctx.lr = 0x8226989C;
	sub_8217BB68(ctx, base);
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lfs f12,168(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f10,172(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 172);
	ctx.f10.f64 = double(temp.f32);
	// addi r30,r31,160
	r30.s64 = r31.s64 + 160;
	// lfs f9,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f31
	ctx.f8.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fmuls f7,f9,f31
	ctx.f7.f64 = double(float(ctx.f9.f64 * f31.f64));
	// li r21,0
	r21.s64 = 0;
	// fctiwz f6,f13
	ctx.f6.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f6.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f5,f11
	ctx.f5.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f5,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f5.u64);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f4.u64);
	// fctiwz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f3.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwimi r9,r6,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r9,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// stw r11,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, r11.u32);
	// ble cr6,0x82269a58
	if (!cr6.gt) goto loc_82269A58;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r31,r20,4
	r31.s64 = r20.s64 + 4;
loc_8226991C:
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f8,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f10,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f4,f8,f31
	ctx.f4.f64 = double(float(ctx.f8.f64 * f31.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lfs f3,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f3,f29
	ctx.f3.f64 = double(float(ctx.f3.f64 * f29.f64));
	// lfs f1,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// fadds f2,f2,f30
	ctx.f2.f64 = double(float(ctx.f2.f64 + f30.f64));
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f1,f29
	ctx.f1.f64 = double(float(ctx.f1.f64 * f29.f64));
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fctiwz f0,f13
	f0.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, f0.u64);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f13,f11
	ctx.f13.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f11,f4
	ctx.f11.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f11.u64);
	// fctiwz f12,f9
	ctx.f12.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f12,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwimi r8,r10,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwimi r11,r7,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r11,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// bl 0x8217bc28
	ctx.lr = 0x822699B0;
	sub_8217BC28(ctx, base);
	// lfs f10,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f0,f10,f31
	f0.f64 = double(float(ctx.f10.f64 * f31.f64));
	// lfs f9,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f9,f31
	ctx.f12.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fmuls f10,f13,f31
	ctx.f10.f64 = double(float(ctx.f13.f64 * f31.f64));
	// lfs f11,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f11,f31
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64));
	// lfs f3,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f3,f28
	ctx.f3.f64 = double(float(ctx.f3.f64 * f28.f64));
	// lfs f1,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// fadds f2,f2,f30
	ctx.f2.f64 = double(float(ctx.f2.f64 + f30.f64));
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f1,f28
	ctx.f1.f64 = double(float(ctx.f1.f64 * f28.f64));
	// lfs f7,-26916(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, f0.u64);
	// fctiwz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// fctiwz f12,f10
	ctx.f12.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f11,f9
	ctx.f11.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// lfs f4,-26928(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfd f12,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f12.u64);
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfd f11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f11.u64);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r3,r5,16
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwimi r4,r3,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r4,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// bl 0x8217bc28
	ctx.lr = 0x82269A44;
	sub_8217BC28(ctx, base);
	// lwz r11,-4212(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4212);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x8226991c
	if (cr6.lt) goto loc_8226991C;
loc_82269A58:
	// bl 0x8217bc98
	ctx.lr = 0x82269A5C;
	sub_8217BC98(ctx, base);
loc_82269A5C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba24
	ctx.lr = 0x82269A68;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82269A6C"))) PPC_WEAK_FUNC(sub_82269A6C);
PPC_FUNC_IMPL(__imp__sub_82269A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269A70"))) PPC_WEAK_FUNC(sub_82269A70);
PPC_FUNC_IMPL(__imp__sub_82269A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82269A78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x82269A84;
	sub_824E0648(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-3644
	ctx.r8.s64 = r11.s64 + -3644;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f13,-13148(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// li r10,160
	ctx.r10.s64 = 160;
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// li r29,144
	r29.s64 = 144;
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lfs f12,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f12,100(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// lfs f13,-29232(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lfs f12,-6172(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -6172);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,32680(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32680);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f11,32692(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32692);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,112(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f11,116(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f10,120(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f12,128(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f13,140(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f11,132(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f10,136(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// lfs f13,3796(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,-12736(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12736);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f8.f64 = double(temp.f32);
	// stfs f9,176(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f8,180(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,172(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stvx128 v63,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,192(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f11,196(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f10,200(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// stfs f0,204(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// lfs f12,14884(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f13,220(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stfs f12,224(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82269BA4"))) PPC_WEAK_FUNC(sub_82269BA4);
PPC_FUNC_IMPL(__imp__sub_82269BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269BA8"))) PPC_WEAK_FUNC(sub_82269BA8);
PPC_FUNC_IMPL(__imp__sub_82269BA8) {
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
	// addi r10,r11,-3644
	ctx.r10.s64 = r11.s64 + -3644;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e0430
	ctx.lr = 0x82269BD4;
	sub_824E0430(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82269bec
	if (cr6.eq) goto loc_82269BEC;
	// bl 0x82130588
	ctx.lr = 0x82269BE8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82269BEC:
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

__attribute__((alias("__imp__sub_82269C04"))) PPC_WEAK_FUNC(sub_82269C04);
PPC_FUNC_IMPL(__imp__sub_82269C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269C08"))) PPC_WEAK_FUNC(sub_82269C08);
PPC_FUNC_IMPL(__imp__sub_82269C08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-4204
	ctx.r10.s64 = r11.s64 + -4204;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82269c28
	if (cr6.eq) goto loc_82269C28;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3596
	ctx.r3.s64 = r11.s64 + -3596;
	// blr 
	return;
loc_82269C28:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3612
	ctx.r3.s64 = r11.s64 + -3612;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82269C34"))) PPC_WEAK_FUNC(sub_82269C34);
PPC_FUNC_IMPL(__imp__sub_82269C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269C38"))) PPC_WEAK_FUNC(sub_82269C38);
PPC_FUNC_IMPL(__imp__sub_82269C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3560
	ctx.r3.s64 = r11.s64 + -3560;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82269C44"))) PPC_WEAK_FUNC(sub_82269C44);
PPC_FUNC_IMPL(__imp__sub_82269C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269C48"))) PPC_WEAK_FUNC(sub_82269C48);
PPC_FUNC_IMPL(__imp__sub_82269C48) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3228
	ctx.r5.s64 = r11.s64 + -3228;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269C84;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-3244
	ctx.r5.s64 = ctx.r10.s64 + -3244;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269CA4;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3260
	ctx.r5.s64 = ctx.r9.s64 + -3260;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,48
	ctx.r6.s64 = r31.s64 + 48;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269CC4;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-3284
	ctx.r5.s64 = ctx.r8.s64 + -3284;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269CE4;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-3304
	ctx.r5.s64 = ctx.r7.s64 + -3304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,64
	ctx.r6.s64 = r31.s64 + 64;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269D04;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-3328
	ctx.r5.s64 = ctx.r6.s64 + -3328;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82269D24;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-3344
	ctx.r5.s64 = ctx.r5.s64 + -3344;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269D44;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-3360
	ctx.r5.s64 = ctx.r4.s64 + -3360;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,212
	ctx.r6.s64 = r31.s64 + 212;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269D64;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3380
	ctx.r5.s64 = r11.s64 + -3380;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269D84;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-3400
	ctx.r5.s64 = ctx.r10.s64 + -3400;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82269DA4;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3420
	ctx.r5.s64 = ctx.r9.s64 + -3420;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269DC4;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-3440
	ctx.r5.s64 = ctx.r8.s64 + -3440;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269DE4;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-3452
	ctx.r5.s64 = ctx.r7.s64 + -3452;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82269E04;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-3464
	ctx.r5.s64 = ctx.r6.s64 + -3464;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E24;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-3480
	ctx.r5.s64 = ctx.r5.s64 + -3480;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,180
	ctx.r6.s64 = r31.s64 + 180;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E44;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-3492
	ctx.r5.s64 = ctx.r4.s64 + -3492;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E64;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3520
	ctx.r5.s64 = r11.s64 + -3520;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,216
	ctx.r6.s64 = r31.s64 + 216;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82269E84;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-3552
	ctx.r5.s64 = ctx.r10.s64 + -3552;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,220
	ctx.r6.s64 = r31.s64 + 220;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82269EA4;
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

__attribute__((alias("__imp__sub_82269EBC"))) PPC_WEAK_FUNC(sub_82269EBC);
PPC_FUNC_IMPL(__imp__sub_82269EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269EC0"))) PPC_WEAK_FUNC(sub_82269EC0);
PPC_FUNC_IMPL(__imp__sub_82269EC0) {
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
	ctx.lr = 0x82269EC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x822e6a80
	ctx.lr = 0x82269ED8;
	sub_822E6A80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82269ef4
	if (cr6.eq) goto loc_82269EF4;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82269EF4:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x82269EFC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82269f1c
	if (cr6.eq) goto loc_82269F1C;
	// bl 0x822e6d98
	ctx.lr = 0x82269F0C;
	sub_822E6D98(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-3660
	ctx.r10.s64 = r11.s64 + -3660;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82269f20
	goto loc_82269F20;
loc_82269F1C:
	// li r31,0
	r31.s64 = 0;
loc_82269F20:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6c18
	ctx.lr = 0x82269F2C;
	sub_822E6C18(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822e6ad0
	ctx.lr = 0x82269F38;
	sub_822E6AD0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82269F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82269F5C"))) PPC_WEAK_FUNC(sub_82269F5C);
PPC_FUNC_IMPL(__imp__sub_82269F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269F60"))) PPC_WEAK_FUNC(sub_82269F60);
PPC_FUNC_IMPL(__imp__sub_82269F60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4944(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x82269f7c
	if (cr6.eq) goto loc_82269F7C;
	// b 0x82263128
	sub_82263128(ctx, base);
	return;
loc_82269F7C:
	// b 0x82262960
	sub_82262960(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82269F80"))) PPC_WEAK_FUNC(sub_82269F80);
PPC_FUNC_IMPL(__imp__sub_82269F80) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82269F84"))) PPC_WEAK_FUNC(sub_82269F84);
PPC_FUNC_IMPL(__imp__sub_82269F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269F88"))) PPC_WEAK_FUNC(sub_82269F88);
PPC_FUNC_IMPL(__imp__sub_82269F88) {
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
	// bl 0x822e6f68
	ctx.lr = 0x82269FA0;
	sub_822E6F68(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-3208
	ctx.r10.s64 = r11.s64 + -3208;
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

__attribute__((alias("__imp__sub_82269FC4"))) PPC_WEAK_FUNC(sub_82269FC4);
PPC_FUNC_IMPL(__imp__sub_82269FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82269FC8"))) PPC_WEAK_FUNC(sub_82269FC8);
PPC_FUNC_IMPL(__imp__sub_82269FC8) {
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
	// addi r10,r11,-3208
	ctx.r10.s64 = r11.s64 + -3208;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e6e68
	ctx.lr = 0x82269FF4;
	sub_822E6E68(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226a00c
	if (cr6.eq) goto loc_8226A00C;
	// bl 0x82130588
	ctx.lr = 0x8226A008;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226A00C:
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

__attribute__((alias("__imp__sub_8226A024"))) PPC_WEAK_FUNC(sub_8226A024);
PPC_FUNC_IMPL(__imp__sub_8226A024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A028"))) PPC_WEAK_FUNC(sub_8226A028);
PPC_FUNC_IMPL(__imp__sub_8226A028) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-3192
	ctx.r9.s64 = r11.s64 + -3192;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x8226A060;
	sub_822E5148(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-3664(r8)
	PPC_STORE_U32(ctx.r8.u32 + -3664, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8226A074;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8226a08c
	if (cr6.eq) goto loc_8226A08C;
	// bl 0x82130588
	ctx.lr = 0x8226A088;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226A08C:
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

__attribute__((alias("__imp__sub_8226A0A4"))) PPC_WEAK_FUNC(sub_8226A0A4);
PPC_FUNC_IMPL(__imp__sub_8226A0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A0A8"))) PPC_WEAK_FUNC(sub_8226A0A8);
PPC_FUNC_IMPL(__imp__sub_8226A0A8) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8226A0B0;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9cc
	ctx.lr = 0x8226A0B8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f26,-28880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	f26.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f27,-19928(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19928);
	f27.f64 = double(temp.f32);
	// lfs f29,-3164(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3164);
	f29.f64 = double(temp.f32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,-6172(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6172);
	f31.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f25,-29232(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	f25.f64 = double(temp.f32);
	// lfs f28,-26928(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26928);
	f28.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// lfs f30,32692(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32692);
	f30.f64 = double(temp.f32);
	// addi r31,r11,-4288
	r31.s64 = r11.s64 + -4288;
	// addi r28,r10,9572
	r28.s64 = ctx.r10.s64 + 9572;
	// addi r27,r9,-12248
	r27.s64 = ctx.r9.s64 + -12248;
loc_8226A110:
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r6,r30,r27
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + r27.u32);
	// bl 0x82137a08
	ctx.lr = 0x8226A128;
	sub_82137A08(ctx, base);
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x8226A130;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226a140
	if (cr6.eq) goto loc_8226A140;
	// bl 0x82269a70
	ctx.lr = 0x8226A13C;
	sub_82269A70(ctx, base);
	// b 0x8226a144
	goto loc_8226A144;
loc_8226A140:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226A144:
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// bl 0x824e06e0
	ctx.lr = 0x8226A154;
	sub_824E06E0(ctx, base);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8226A178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x8226a1dc
	if (!cr6.eq) goto loc_8226A1DC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f30,120(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f28,124(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,132(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f30,136(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f28,140(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,148(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f30,152(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f25,156(r11)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f30,164(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f30,168(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f25,172(r11)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a368
	goto loc_8226A368;
loc_8226A1DC:
	// cmpwi cr6,r29,13
	cr6.compare<int32_t>(r29.s32, 13, xer);
	// bne cr6,0x8226a244
	if (!cr6.eq) goto loc_8226A244;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f31,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f31,120(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f29,124(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f31,128(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f30,132(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f31,136(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f29,140(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f31,144(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,148(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f31,156(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f31,160(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
	// stfs f30,164(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f31,168(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f31,172(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a36c
	goto loc_8226A36C;
loc_8226A244:
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x8226a2a0
	if (!cr6.eq) goto loc_8226A2A0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f31,116(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f31,120(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f29,124(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f31,132(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f31,136(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f29,140(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f31,148(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f31,156(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f31,172(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a360
	goto loc_8226A360;
loc_8226A2A0:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8226a308
	if (!cr6.eq) goto loc_8226A308;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f27,116(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f31,120(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f29,124(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f27,132(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f31,136(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f29,140(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f26,144(r11)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f28,148(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f31,156(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f26,160(r11)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
	// stfs f28,164(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
	// stfs f31,168(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f31,172(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// b 0x8226a36c
	goto loc_8226A36C;
loc_8226A308:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8226a370
	if (!cr6.eq) goto loc_8226A370;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// stfs f30,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stfs f30,116(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f30,120(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f28,124(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// stfs f30,128(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 128, temp.u32);
	// stfs f30,132(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// stfs f30,136(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// stfs f28,140(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
	// stfs f30,144(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// stfs f31,148(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// stfs f31,152(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f29,156(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stfs f29,172(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
loc_8226A360:
	// stfs f31,168(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f31,164(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
loc_8226A368:
	// stfs f30,160(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
loc_8226A36C:
	// addi r10,r11,160
	ctx.r10.s64 = r11.s64 + 160;
loc_8226A370:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,18
	cr6.compare<int32_t>(r29.s32, 18, xer);
	// blt cr6,0x8226a110
	if (cr6.lt) goto loc_8226A110;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r10,r10,-4176
	ctx.r10.s64 = ctx.r10.s64 + -4176;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r31,r10,8
	r31.s64 = ctx.r10.s64 + 8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,32
	r11.s64 = 32;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// stw r11,-4212(r29)
	PPC_STORE_U32(r29.u32 + -4212, r11.u32);
	// lfs f29,18204(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18204);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
loc_8226A3B0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stfs f30,-8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// extsw r10,r30
	ctx.r10.s64 = r30.s32;
	// stfs f31,-4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fmuls f28,f8,f29
	f28.f64 = double(float(ctx.f8.f64 * f29.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8226A3F8;
	sub_823DBAE8(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8226A404;
	sub_823DBBC8(ctx, base);
	// lfs f7,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// frsp f6,f1
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lfs f5,-8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f7,f27
	ctx.f4.f64 = double(float(ctx.f7.f64 * f27.f64));
	// fmuls f3,f5,f27
	ctx.f3.f64 = double(float(ctx.f5.f64 * f27.f64));
	// lwz r11,-4212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -4212);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// fmadds f2,f5,f6,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f6.f64 + ctx.f4.f64));
	// stfs f2,-8(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// fmsubs f1,f7,f6,f3
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 - ctx.f3.f64));
	// stfs f1,0(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// blt cr6,0x8226a3b0
	if (cr6.lt) goto loc_8226A3B0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lfs f0,-3168(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3168);
	f0.f64 = double(temp.f32);
	// lfs f13,-3172(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3172);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-4208(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4208, temp.u32);
	// stfs f13,-12260(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + -12260, temp.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba18
	ctx.lr = 0x8226A468;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226A46C"))) PPC_WEAK_FUNC(sub_8226A46C);
PPC_FUNC_IMPL(__imp__sub_8226A46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A470"))) PPC_WEAK_FUNC(sub_8226A470);
PPC_FUNC_IMPL(__imp__sub_8226A470) {
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
	ctx.lr = 0x8226A488;
	sub_822E6B38(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-3192
	ctx.r8.s64 = r11.s64 + -3192;
	// ori r7,r10,1
	ctx.r7.u64 = ctx.r10.u64 | 1;
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
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x8226A4BC;
	sub_822E5138(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r4,r5,-3156
	ctx.r4.s64 = ctx.r5.s64 + -3156;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// bl 0x8226a0a8
	ctx.lr = 0x8226A4CC;
	sub_8226A0A8(ctx, base);
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

__attribute__((alias("__imp__sub_8226A4E4"))) PPC_WEAK_FUNC(sub_8226A4E4);
PPC_FUNC_IMPL(__imp__sub_8226A4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A4E8"))) PPC_WEAK_FUNC(sub_8226A4E8);
PPC_FUNC_IMPL(__imp__sub_8226A4E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-3136
	ctx.r3.s64 = r11.s64 + -3136;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A4F4"))) PPC_WEAK_FUNC(sub_8226A4F4);
PPC_FUNC_IMPL(__imp__sub_8226A4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A4F8"))) PPC_WEAK_FUNC(sub_8226A4F8);
PPC_FUNC_IMPL(__imp__sub_8226A4F8) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// lwz r3,-3664(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3664);
	// bl 0x82269ec0
	ctx.lr = 0x8226A520;
	sub_82269EC0(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x822e6c50
	ctx.lr = 0x8226A530;
	sub_822E6C50(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226A544"))) PPC_WEAK_FUNC(sub_8226A544);
PPC_FUNC_IMPL(__imp__sub_8226A544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A548"))) PPC_WEAK_FUNC(sub_8226A548);
PPC_FUNC_IMPL(__imp__sub_8226A548) {
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
	// addi r10,r11,-3156
	ctx.r10.s64 = r11.s64 + -3156;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822695b0
	ctx.lr = 0x8226A574;
	sub_822695B0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r9,-3192
	ctx.r7.s64 = ctx.r9.s64 + -3192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r3,-8092(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x8226A590;
	sub_822E5148(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-3664(r6)
	PPC_STORE_U32(ctx.r6.u32 + -3664, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8226A5A4;
	sub_822E6940(ctx, base);
	// clrlwi r5,r30,31
	ctx.r5.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8226a5bc
	if (cr6.eq) goto loc_8226A5BC;
	// bl 0x82130588
	ctx.lr = 0x8226A5B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226A5BC:
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

__attribute__((alias("__imp__sub_8226A5D4"))) PPC_WEAK_FUNC(sub_8226A5D4);
PPC_FUNC_IMPL(__imp__sub_8226A5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A5D8"))) PPC_WEAK_FUNC(sub_8226A5D8);
PPC_FUNC_IMPL(__imp__sub_8226A5D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r31,-1
	r31.s64 = -1;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8226A5F4:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8226a5f4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8226A5F4;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8226a6ec
	if (cr6.eq) goto loc_8226A6EC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a6ec
	if (!cr6.lt) goto loc_8226A6EC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// li r8,0
	ctx.r8.s64 = 0;
	// divw r11,r4,r9
	r11.s32 = ctx.r4.s32 / ctx.r9.s32;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r10,r9,r11
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// twllei r9,0
	// andc r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// twlgei r9,-1
	// subf r4,r10,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r10.s64;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// bgt cr6,0x8226a6ec
	if (cr6.gt) goto loc_8226A6EC;
loc_8226A64C:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x8226a6c0
	if (cr6.lt) goto loc_8226A6C0;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x8226a6c0
	if (!cr6.lt) goto loc_8226A6C0;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// addi r7,r4,1
	ctx.r7.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bgt cr6,0x8226a6e0
	if (cr6.gt) goto loc_8226A6E0;
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - r11.s64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
loc_8226A684:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8226a6a8
	if (cr6.lt) goto loc_8226A6A8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8226a6a8
	if (!cr6.lt) goto loc_8226A6A8;
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// b 0x8226a6ac
	goto loc_8226A6AC;
loc_8226A6A8:
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
loc_8226A6AC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// ble cr6,0x8226a684
	if (!cr6.gt) goto loc_8226A684;
	// b 0x8226a6e0
	goto loc_8226A6E0;
loc_8226A6C0:
	// addi r10,r8,2
	ctx.r10.s64 = ctx.r8.s64 + 2;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// stwx r31,r9,r5
	PPC_STORE_U32(ctx.r9.u32 + ctx.r5.u32, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8226A6E0:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// ble cr6,0x8226a64c
	if (!cr6.gt) goto loc_8226A64C;
loc_8226A6EC:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A6F8"))) PPC_WEAK_FUNC(sub_8226A6F8);
PPC_FUNC_IMPL(__imp__sub_8226A6F8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8226a780
	if (cr6.lt) goto loc_8226A780;
	// lfs f12,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8226a780
	if (!cr6.lt) goto loc_8226A780;
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8226a780
	if (cr6.lt) goto loc_8226A780;
	// lfs f11,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x8226a780
	if (!cr6.lt) goto loc_8226A780;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-3072(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3072);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,0,r4
	PPC_STORE_U32(ctx.r4.u32, ctx.f11.u32);
	// lfs f10,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f6.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// blr 
	return;
loc_8226A780:
	// li r11,0
	r11.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A794"))) PPC_WEAK_FUNC(sub_8226A794);
PPC_FUNC_IMPL(__imp__sub_8226A794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A798"))) PPC_WEAK_FUNC(sub_8226A798);
PPC_FUNC_IMPL(__imp__sub_8226A798) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8226a7bc
	if (cr6.lt) goto loc_8226A7BC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a7bc
	if (!cr6.lt) goto loc_8226A7BC;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
loc_8226A7BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A7C4"))) PPC_WEAK_FUNC(sub_8226A7C4);
PPC_FUNC_IMPL(__imp__sub_8226A7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226A7C8"))) PPC_WEAK_FUNC(sub_8226A7C8);
PPC_FUNC_IMPL(__imp__sub_8226A7C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8226a800
	if (cr6.lt) goto loc_8226A800;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a800
	if (!cr6.lt) goto loc_8226A800;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x8226a800
	if (cr6.lt) goto loc_8226A800;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// bge cr6,0x8226a800
	if (!cr6.lt) goto loc_8226A800;
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = r11.u32 & 0xFFFF;
	// blr 
	return;
loc_8226A800:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A808"))) PPC_WEAK_FUNC(sub_8226A808);
PPC_FUNC_IMPL(__imp__sub_8226A808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8226A810;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8226a910
	if (cr6.eq) goto loc_8226A910;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8226a910
	if (!cr6.lt) goto loc_8226A910;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// li r31,0
	r31.s64 = 0;
	// divw r11,r4,r9
	r11.s32 = ctx.r4.s32 / ctx.r9.s32;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// andc r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// twllei r9,0
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// twlgei r10,-1
	// subf r4,r6,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r6.s64;
	// cmpw cr6,r7,r30
	cr6.compare<int32_t>(ctx.r7.s32, r30.s32, xer);
	// bgt cr6,0x8226a92c
	if (cr6.gt) goto loc_8226A92C;
loc_8226A860:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x8226a8e0
	if (cr6.lt) goto loc_8226A8E0;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bge cr6,0x8226a8e0
	if (!cr6.lt) goto loc_8226A8E0;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// addi r6,r4,1
	ctx.r6.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bgt cr6,0x8226a900
	if (cr6.gt) goto loc_8226A900;
	// subf r9,r11,r6
	ctx.r9.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
loc_8226A898:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8226a8c8
	if (cr6.lt) goto loc_8226A8C8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8226a8c8
	if (!cr6.lt) goto loc_8226A8C8;
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// lwz r29,28(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// b 0x8226a8cc
	goto loc_8226A8CC;
loc_8226A8C8:
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r31.u32);
loc_8226A8CC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// ble cr6,0x8226a898
	if (!cr6.gt) goto loc_8226A898;
	// b 0x8226a900
	goto loc_8226A900;
loc_8226A8E0:
	// addi r10,r8,2
	ctx.r10.s64 = ctx.r8.s64 + 2;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// stwx r31,r9,r5
	PPC_STORE_U32(ctx.r9.u32 + ctx.r5.u32, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8226A900:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r7,r30
	cr6.compare<int32_t>(ctx.r7.s32, r30.s32, xer);
	// ble cr6,0x8226a860
	if (!cr6.gt) goto loc_8226A860;
	// b 0x823d924c
	return;
loc_8226A910:
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8226A920:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8226a920
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8226A920;
loc_8226A92C:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226A930"))) PPC_WEAK_FUNC(sub_8226A930);
PPC_FUNC_IMPL(__imp__sub_8226A930) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226a994
	if (!cr6.eq) goto loc_8226A994;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// beq cr6,0x8226a9b4
	if (cr6.eq) goto loc_8226A9B4;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// li r11,-1
	r11.s64 = -1;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// sth r11,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, r11.u16);
	// blr 
	return;
loc_8226A994:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8226a9b4
	if (cr6.eq) goto loc_8226A9B4;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_8226A9B4:
	// li r11,-1
	r11.s64 = -1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// sth r11,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226A9C8"))) PPC_WEAK_FUNC(sub_8226A9C8);
PPC_FUNC_IMPL(__imp__sub_8226A9C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r11,0
	r11.s64 = 0;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// ori r4,r11,65535
	ctx.r4.u64 = r11.u64 | 65535;
loc_8226A9E8:
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226aa80
	if (cr6.eq) goto loc_8226AA80;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// bge cr6,0x8226aa70
	if (!cr6.lt) goto loc_8226AA70;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8226aa44
	if (!cr6.eq) goto loc_8226AA44;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226aa64
	if (cr6.eq) goto loc_8226AA64;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// b 0x8226aa64
	goto loc_8226AA64;
loc_8226AA44:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226aa64
	if (cr6.eq) goto loc_8226AA64;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
loc_8226AA64:
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
loc_8226AA70:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226a9e8
	if (!cr6.eq) goto loc_8226A9E8;
loc_8226AA80:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// blt cr6,0x8226a9e8
	if (cr6.lt) goto loc_8226A9E8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226AA98"))) PPC_WEAK_FUNC(sub_8226AA98);
PPC_FUNC_IMPL(__imp__sub_8226AA98) {
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
	ctx.lr = 0x8226AAA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8226aac0
	if (!cr6.lt) goto loc_8226AAC0;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8226AAC0:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f0,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x8226aad4
	if (cr6.lt) goto loc_8226AAD4;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8226AAD4:
	// stfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f13,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// lfs f12,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// bgt cr6,0x8226aaf0
	if (cr6.gt) goto loc_8226AAF0;
	// fmr f9,f13
	ctx.f9.f64 = ctx.f13.f64;
loc_8226AAF0:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f9,0(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bgt cr6,0x8226ab04
	if (cr6.gt) goto loc_8226AB04;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8226AB04:
	// stfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f7,f9,f12
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f7,f7
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fsubs f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f12,32224(r11)
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + 32224);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfd f11,21560(r10)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21560);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,-3072(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3072);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f4,f6,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// frsqrte f3,f4
	// fneg f2,f4
	ctx.f2.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fmul f1,f3,f3
	ctx.f1.f64 = ctx.f3.f64 * ctx.f3.f64;
	// fmul f5,f3,f12
	ctx.f5.f64 = ctx.f3.f64 * ctx.f12.f64;
	// fnmsub f1,f1,f4,f11
	ctx.f1.f64 = -(ctx.f1.f64 * ctx.f4.f64 - ctx.f11.f64);
	// fmadd f5,f1,f5,f3
	ctx.f5.f64 = ctx.f1.f64 * ctx.f5.f64 + ctx.f3.f64;
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f1,f5,f12
	ctx.f1.f64 = ctx.f5.f64 * ctx.f12.f64;
	// fnmsub f12,f3,f4,f11
	ctx.f12.f64 = -(ctx.f3.f64 * ctx.f4.f64 - ctx.f11.f64);
	// fmadd f11,f12,f1,f5
	ctx.f11.f64 = ctx.f12.f64 * ctx.f1.f64 + ctx.f5.f64;
	// frsp f5,f11
	ctx.f5.f64 = double(float(ctx.f11.f64));
	// fsel f4,f2,f13,f5
	ctx.f4.f64 = ctx.f2.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// fmuls f3,f4,f7
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// fmuls f2,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f4.f64));
	// fmuls f1,f3,f10
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fmuls f12,f2,f10
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fadds f11,f9,f1
	ctx.f11.f64 = double(float(ctx.f9.f64 + ctx.f1.f64));
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fadds f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f10,4(r5)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f9,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f0,f7,f1
	f0.f64 = double(float(ctx.f7.f64 - ctx.f1.f64));
	// fsubs f12,f9,f12
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f12,4(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8226abc0
	if (cr6.lt) goto loc_8226ABC0;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x8226abd4
	goto loc_8226ABD4;
loc_8226ABC0:
	// fmuls f0,f0,f8
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f8.f64));
	// fctiwz f11,f0
	ctx.f11.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r7,r11,1
	xer.ca = r11.u32 <= 1;
	ctx.r7.s64 = 1 - r11.s64;
loc_8226ABD4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfs f11,-3068(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3068);
	ctx.f11.f64 = double(temp.f32);
	// bgt cr6,0x8226abf0
	if (cr6.gt) goto loc_8226ABF0;
	// li r11,0
	r11.s64 = 0;
	// b 0x8226ac04
	goto loc_8226AC04;
loc_8226ABF0:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f10,f0
	ctx.f10.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r11,r11,1
	xer.ca = r11.u32 <= 1;
	r11.s64 = 1 - r11.s64;
loc_8226AC04:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8226ac14
	if (cr6.lt) goto loc_8226AC14;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8226ac28
	goto loc_8226AC28;
loc_8226AC14:
	// fmuls f0,f12,f8
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// fctiwz f12,f0
	ctx.f12.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r8,r10,1
	xer.ca = ctx.r10.u32 <= 1;
	ctx.r8.s64 = 1 - ctx.r10.s64;
loc_8226AC28:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8226ac3c
	if (cr6.gt) goto loc_8226AC3C;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8226ac50
	goto loc_8226AC50;
loc_8226AC3C:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r10,r10,1
	xer.ca = ctx.r10.u32 <= 1;
	ctx.r10.s64 = 1 - ctx.r10.s64;
loc_8226AC50:
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x8226ac68
	if (!cr6.lt) goto loc_8226AC68;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_8226AC68:
	// add r11,r10,r8
	r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bge cr6,0x8226ac7c
	if (!cr6.lt) goto loc_8226AC7C;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_8226AC7C:
	// extsw r11,r8
	r11.s64 = ctx.r8.s32;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// extsw r8,r7
	ctx.r8.s64 = ctx.r7.s32;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,29496(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 29496);
	f0.f64 = double(temp.f32);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// mullw r29,r10,r9
	r29.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// frsp f4,f10
	ctx.f4.f64 = double(float(ctx.f10.f64));
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,31304(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31304);
	ctx.f13.f64 = double(temp.f32);
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f1,16(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// fmuls f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f5,12(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fmadds f0,f2,f13,f5
	f0.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fmadds f13,f3,f13,f1
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 + ctx.f1.f64));
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// beq cr6,0x8226ad24
	if (cr6.eq) goto loc_8226AD24;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8226AD20;
	sub_82130528(ctx, base);
	// b 0x8226ad28
	goto loc_8226AD28;
loc_8226AD24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226AD28:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// clrlwi r10,r29,16
	ctx.r10.u64 = r29.u32 & 0xFFFF;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bne cr6,0x8226ad60
	if (!cr6.eq) goto loc_8226AD60;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// beq cr6,0x8226ad58
	if (cr6.eq) goto loc_8226AD58;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8226AD54;
	sub_82130528(ctx, base);
	// b 0x8226ad5c
	goto loc_8226AD5C;
loc_8226AD58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226AD5C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8226AD60:
	// sth r29,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r29.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823d9890
	ctx.lr = 0x8226AD78;
	sub_823D9890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226AD80"))) PPC_WEAK_FUNC(sub_8226AD80);
PPC_FUNC_IMPL(__imp__sub_8226AD80) {
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
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x8226a6f8
	ctx.lr = 0x8226AD9C;
	sub_8226A6F8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226ADAC"))) PPC_WEAK_FUNC(sub_8226ADAC);
PPC_FUNC_IMPL(__imp__sub_8226ADAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226ADB0"))) PPC_WEAK_FUNC(sub_8226ADB0);
PPC_FUNC_IMPL(__imp__sub_8226ADB0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226ADE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r3,48
	ctx.r6.s64 = ctx.r3.s64 + 48;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226a6f8
	ctx.lr = 0x8226ADF4;
	sub_8226A6F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplw cr6,r9,r6
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, xer);
	// beq cr6,0x8226ae68
	if (cr6.eq) goto loc_8226AE68;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226a930
	ctx.lr = 0x8226AE14;
	sub_8226A930(ctx, base);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226ae68
	if (cr6.eq) goto loc_8226AE68;
	// sth r5,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r5.u16);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x8226ae68
	if (!cr6.lt) goto loc_8226AE68;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// lwz r7,28(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226ae60
	if (cr6.eq) goto loc_8226AE60;
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r31.u32);
loc_8226AE60:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stwx r31,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r31.u32);
loc_8226AE68:
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

__attribute__((alias("__imp__sub_8226AE80"))) PPC_WEAK_FUNC(sub_8226AE80);
PPC_FUNC_IMPL(__imp__sub_8226AE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r3,-3660(r9)
	PPC_STORE_U32(ctx.r9.u32 + -3660, ctx.r3.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stb r10,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r10.u8);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stb r10,37(r3)
	PPC_STORE_U8(ctx.r3.u32 + 37, ctx.r10.u8);
	// stb r10,38(r3)
	PPC_STORE_U8(ctx.r3.u32 + 38, ctx.r10.u8);
	// stb r11,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, r11.u8);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226AEE0"))) PPC_WEAK_FUNC(sub_8226AEE0);
PPC_FUNC_IMPL(__imp__sub_8226AEE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-3660(r10)
	PPC_STORE_U32(ctx.r10.u32 + -3660, r11.u32);
	// lhz r9,34(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 34);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226AF00"))) PPC_WEAK_FUNC(sub_8226AF00);
PPC_FUNC_IMPL(__imp__sub_8226AF00) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226AF04"))) PPC_WEAK_FUNC(sub_8226AF04);
PPC_FUNC_IMPL(__imp__sub_8226AF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226AF08"))) PPC_WEAK_FUNC(sub_8226AF08);
PPC_FUNC_IMPL(__imp__sub_8226AF08) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
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
	// bl 0x824ea3b8
	ctx.lr = 0x8226AF48;
	sub_824EA3B8(ctx, base);
	// lwz r8,528(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 528);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,528(r31)
	PPC_STORE_U32(r31.u32 + 528, ctx.r8.u32);
	// lwz r7,532(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 532);
	// stw r7,532(r31)
	PPC_STORE_U32(r31.u32 + 532, ctx.r7.u32);
	// lwz r6,536(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 536);
	// stw r6,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r6.u32);
	// ld r5,544(r30)
	ctx.r5.u64 = PPC_LOAD_U64(r30.u32 + 544);
	// std r5,544(r31)
	PPC_STORE_U64(r31.u32 + 544, ctx.r5.u64);
	// ld r4,552(r30)
	ctx.r4.u64 = PPC_LOAD_U64(r30.u32 + 552);
	// std r4,552(r31)
	PPC_STORE_U64(r31.u32 + 552, ctx.r4.u64);
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

__attribute__((alias("__imp__sub_8226AF8C"))) PPC_WEAK_FUNC(sub_8226AF8C);
PPC_FUNC_IMPL(__imp__sub_8226AF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226AF90"))) PPC_WEAK_FUNC(sub_8226AF90);
PPC_FUNC_IMPL(__imp__sub_8226AF90) {
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
	// addi r9,r11,-2620
	ctx.r9.s64 = r11.s64 + -2620;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8226afc4
	if (cr6.eq) goto loc_8226AFC4;
	// bl 0x82130588
	ctx.lr = 0x8226AFC0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226AFC4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226AFD8"))) PPC_WEAK_FUNC(sub_8226AFD8);
PPC_FUNC_IMPL(__imp__sub_8226AFD8) {
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
	// addi r9,r11,-2588
	ctx.r9.s64 = r11.s64 + -2588;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8226b00c
	if (cr6.eq) goto loc_8226B00C;
	// bl 0x82130588
	ctx.lr = 0x8226B008;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226B00C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226B020"))) PPC_WEAK_FUNC(sub_8226B020);
PPC_FUNC_IMPL(__imp__sub_8226B020) {
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
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x8226B03C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226b058
	if (cr6.eq) goto loc_8226B058;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226b05c
	if (!cr6.eq) goto loc_8226B05C;
loc_8226B058:
	// li r11,0
	r11.s64 = 0;
loc_8226B05C:
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

__attribute__((alias("__imp__sub_8226B074"))) PPC_WEAK_FUNC(sub_8226B074);
PPC_FUNC_IMPL(__imp__sub_8226B074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B078"))) PPC_WEAK_FUNC(sub_8226B078);
PPC_FUNC_IMPL(__imp__sub_8226B078) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8226B080;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// ori r10,r10,32779
	ctx.r10.u64 = ctx.r10.u64 | 32779;
	// ori r9,r9,8
	ctx.r9.u64 = ctx.r9.u64 | 8;
	// ori r8,r8,9
	ctx.r8.u64 = ctx.r8.u64 | 9;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lis r7,4096
	ctx.r7.s64 = 268435456;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r6,4096
	ctx.r6.s64 = 268435456;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// lis r5,4096
	ctx.r5.s64 = 268435456;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// lis r31,4096
	r31.s64 = 268435456;
	// lis r30,4096
	r30.s64 = 268435456;
	// lis r29,4096
	r29.s64 = 268435456;
	// ori r7,r7,10
	ctx.r7.u64 = ctx.r7.u64 | 10;
	// ori r6,r6,11
	ctx.r6.u64 = ctx.r6.u64 | 11;
	// li r11,0
	r11.s64 = 0;
	// stw r7,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r7.u32);
	// ori r5,r5,12
	ctx.r5.u64 = ctx.r5.u64 | 12;
	// stw r6,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r6.u32);
	// ori r4,r4,14
	ctx.r4.u64 = ctx.r4.u64 | 14;
	// std r11,4(r3)
	PPC_STORE_U64(ctx.r3.u32 + 4, r11.u64);
	// ori r10,r31,15
	ctx.r10.u64 = r31.u64 | 15;
	// stw r5,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r5.u32);
	// ori r9,r30,16
	ctx.r9.u64 = r30.u64 | 16;
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// ori r8,r29,17
	ctx.r8.u64 = r29.u64 | 17;
	// stw r4,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// lis r28,4096
	r28.s64 = 268435456;
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// lis r27,4096
	r27.s64 = 268435456;
	// stw r9,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r9.u32);
	// lis r26,4096
	r26.s64 = 268435456;
	// stw r8,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r8.u32);
	// lis r25,4096
	r25.s64 = 268435456;
	// lis r24,4096
	r24.s64 = 268435456;
	// lis r23,4096
	r23.s64 = 268435456;
	// lis r22,4096
	r22.s64 = 268435456;
	// lis r21,4096
	r21.s64 = 268435456;
	// ori r7,r28,18
	ctx.r7.u64 = r28.u64 | 18;
	// ori r6,r27,33
	ctx.r6.u64 = r27.u64 | 33;
	// ori r5,r26,34
	ctx.r5.u64 = r26.u64 | 34;
	// stw r7,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r7.u32);
	// ori r4,r25,35
	ctx.r4.u64 = r25.u64 | 35;
	// stw r6,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r6.u32);
	// ori r11,r24,45
	r11.u64 = r24.u64 | 45;
	// stw r5,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r5.u32);
	// ori r10,r23,46
	ctx.r10.u64 = r23.u64 | 46;
	// stw r4,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r4.u32);
	// ori r9,r22,47
	ctx.r9.u64 = r22.u64 | 47;
	// stw r11,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r11.u32);
	// ori r8,r21,48
	ctx.r8.u64 = r21.u64 | 48;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// lis r20,4096
	r20.s64 = 268435456;
	// stw r9,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r9.u32);
	// lis r19,4096
	r19.s64 = 268435456;
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// lis r18,4096
	r18.s64 = 268435456;
	// lis r17,4096
	r17.s64 = 268435456;
	// lis r16,8192
	r16.s64 = 536870912;
	// lis r15,4096
	r15.s64 = 268435456;
	// ori r7,r20,49
	ctx.r7.u64 = r20.u64 | 49;
	// ori r6,r19,50
	ctx.r6.u64 = r19.u64 | 50;
	// li r14,30
	r14.s64 = 30;
	// stw r7,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r7.u32);
	// ori r5,r18,51
	ctx.r5.u64 = r18.u64 | 51;
	// stw r6,172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 172, ctx.r6.u32);
	// ori r4,r17,52
	ctx.r4.u64 = r17.u64 | 52;
	// stw r14,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r14.u32);
	// ori r11,r16,53
	r11.u64 = r16.u64 | 53;
	// stw r5,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r5.u32);
	// ori r10,r15,54
	ctx.r10.u64 = r15.u64 | 54;
	// stw r4,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r4.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r11,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, r11.u32);
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// stw r10,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r10.u32);
	// ori r7,r9,55
	ctx.r7.u64 = ctx.r9.u64 | 55;
	// ori r6,r8,56
	ctx.r6.u64 = ctx.r8.u64 | 56;
	// lis r5,4096
	ctx.r5.s64 = 268435456;
	// stw r7,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, ctx.r7.u32);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// stw r6,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r6.u32);
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r10,r5,57
	ctx.r10.u64 = ctx.r5.u64 | 57;
	// ori r9,r4,58
	ctx.r9.u64 = ctx.r4.u64 | 58;
	// ori r8,r11,59
	ctx.r8.u64 = r11.u64 | 59;
	// stw r10,232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 232, ctx.r10.u32);
	// stw r9,240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 240, ctx.r9.u32);
	// stw r8,248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 248, ctx.r8.u32);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8226B1F4"))) PPC_WEAK_FUNC(sub_8226B1F4);
PPC_FUNC_IMPL(__imp__sub_8226B1F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B1F8"))) PPC_WEAK_FUNC(sub_8226B1F8);
PPC_FUNC_IMPL(__imp__sub_8226B1F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r9,34(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 34);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B214"))) PPC_WEAK_FUNC(sub_8226B214);
PPC_FUNC_IMPL(__imp__sub_8226B214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B218"))) PPC_WEAK_FUNC(sub_8226B218);
PPC_FUNC_IMPL(__imp__sub_8226B218) {
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
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823da950
	ctx.lr = 0x8226B23C;
	sub_823DA950(ctx, base);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// addi r4,r30,80
	ctx.r4.s64 = r30.s64 + 80;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// stb r10,64(r31)
	PPC_STORE_U8(r31.u32 + 64, ctx.r10.u8);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r9,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r9.u32);
	// lwz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// bl 0x8226af08
	ctx.lr = 0x8226B268;
	sub_8226AF08(ctx, base);
	// lwz r7,640(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 640);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,640(r31)
	PPC_STORE_U32(r31.u32 + 640, ctx.r7.u32);
	// lwz r6,644(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 644);
	// stw r6,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8226B294"))) PPC_WEAK_FUNC(sub_8226B294);
PPC_FUNC_IMPL(__imp__sub_8226B294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B298"))) PPC_WEAK_FUNC(sub_8226B298);
PPC_FUNC_IMPL(__imp__sub_8226B298) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,700(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 700);
	// b 0x8227e750
	sub_8227E750(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B2A0"))) PPC_WEAK_FUNC(sub_8226B2A0);
PPC_FUNC_IMPL(__imp__sub_8226B2A0) {
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
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226b2d4
	if (cr6.eq) goto loc_8226B2D4;
	// bl 0x824e70f0
	ctx.lr = 0x8226B2C4;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226b2d8
	if (!cr6.eq) goto loc_8226B2D8;
loc_8226B2D4:
	// li r11,0
	r11.s64 = 0;
loc_8226B2D8:
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
}

__attribute__((alias("__imp__sub_8226B2EC"))) PPC_WEAK_FUNC(sub_8226B2EC);
PPC_FUNC_IMPL(__imp__sub_8226B2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B2F0"))) PPC_WEAK_FUNC(sub_8226B2F0);
PPC_FUNC_IMPL(__imp__sub_8226B2F0) {
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
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82294df8
	ctx.lr = 0x8226B30C;
	sub_82294DF8(ctx, base);
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

__attribute__((alias("__imp__sub_8226B324"))) PPC_WEAK_FUNC(sub_8226B324);
PPC_FUNC_IMPL(__imp__sub_8226B324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B328"))) PPC_WEAK_FUNC(sub_8226B328);
PPC_FUNC_IMPL(__imp__sub_8226B328) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82294d58
	sub_82294D58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B330"))) PPC_WEAK_FUNC(sub_8226B330);
PPC_FUNC_IMPL(__imp__sub_8226B330) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82294d98
	sub_82294D98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B338"))) PPC_WEAK_FUNC(sub_8226B338);
PPC_FUNC_IMPL(__imp__sub_8226B338) {
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
	ctx.lr = 0x8226B340;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// rlwinm r30,r28,1,31,31
	r30.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0x1;
	// li r29,0
	r29.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x8226B360;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226b398
	if (cr6.eq) goto loc_8226B398;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x8226B388;
	sub_82618390(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x8226B394;
	sub_826188B8(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_8226B398:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226b3cc
	if (cr6.eq) goto loc_8226B3CC;
	// neg r11,r30
	r11.s64 = -r30.s64;
	// addi r5,r27,-1
	ctx.r5.s64 = r27.s64 + -1;
	// xor r11,r11,r28
	r11.u64 = r11.u64 ^ r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824e6390
	ctx.lr = 0x8226B3BC;
	sub_824E6390(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226b3d0
	if (!cr6.eq) goto loc_8226B3D0;
loc_8226B3CC:
	// li r11,0
	r11.s64 = 0;
loc_8226B3D0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226B3DC"))) PPC_WEAK_FUNC(sub_8226B3DC);
PPC_FUNC_IMPL(__imp__sub_8226B3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B3E0"))) PPC_WEAK_FUNC(sub_8226B3E0);
PPC_FUNC_IMPL(__imp__sub_8226B3E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,46
	r11.u64 = r11.u64 | 46;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8226b50c
	if (cr6.gt) {
		// ERROR 8226B50C
		return;
	}
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,27
	r11.u64 = r11.u64 | 27;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8226b4b0
	if (cr6.gt) {
		// ERROR 8226B4B0
		return;
	}
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,12
	r11.u64 = r11.u64 | 12;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8226b474
	if (cr6.gt) goto loc_8226B474;
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,9
	r11.u64 = r11.u64 | 9;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8226b458
	if (cr6.gt) goto loc_8226B458;
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
	// cmplwi cr6,r3,32779
	cr6.compare<uint32_t>(ctx.r3.u32, 32779, xer);
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bne cr6,0x8226b46c
	if (!cr6.eq) goto loc_8226B46C;
loc_8226B450:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8226B458:
	// addis r11,r3,-4096
	r11.s64 = ctx.r3.s64 + -268435456;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8226b450
	if (cr0.eq) goto loc_8226B450;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8226b450
	if (cr6.eq) goto loc_8226B450;
loc_8226B46C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8226B474:
	// addis r11,r3,-4096
	r11.s64 = ctx.r3.s64 + -268435456;
	// addi r11,r11,-14
	r11.s64 = r11.s64 + -14;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8226b46c
	if (cr6.gt) goto loc_8226B46C;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-19300
	r12.s64 = r12.s64 + -19300;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8226B450;
	case 1:
		goto loc_8226B450;
	case 2:
		goto loc_8226B450;
	case 3:
		goto loc_8226B450;
	case 4:
		goto loc_8226B450;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8226B49C"))) PPC_WEAK_FUNC(sub_8226B49C);
PPC_FUNC_IMPL(__imp__sub_8226B49C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// addis r11,r3,-4096
	r11.s64 = ctx.r3.s64 + -268435456;
	// addi r11,r11,-33
	r11.s64 = r11.s64 + -33;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8226b46c
	if (cr6.gt) {
		// ERROR 8226B46C
		return;
	}
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-19240
	r12.s64 = r12.s64 + -19240;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x8226B450
		return;
	case 1:
		// ERROR: 0x8226B450
		return;
	case 2:
		// ERROR: 0x8226B450
		return;
	case 3:
		// ERROR: 0x8226B450
		return;
	case 4:
		// ERROR: 0x8226B450
		return;
	case 5:
		// ERROR: 0x8226B450
		return;
	case 6:
		// ERROR: 0x8226B450
		return;
	case 7:
		// ERROR: 0x8226B450
		return;
	case 8:
		// ERROR: 0x8226B450
		return;
	case 9:
		// ERROR: 0x8226B450
		return;
	case 10:
		// ERROR: 0x8226B450
		return;
	case 11:
		// ERROR: 0x8226B46C
		return;
	case 12:
		// ERROR: 0x8226B450
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8226B4D8"))) PPC_WEAK_FUNC(sub_8226B4D8);
PPC_FUNC_IMPL(__imp__sub_8226B4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,32769
	r11.u64 = r11.u64 | 32769;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8226b57c
	if (cr6.gt) {
		// ERROR 8226B57C
		return;
	}
	// beq cr6,0x8226b450
	if (cr6.eq) {
		// ERROR 8226B450
		return;
	}
	// addis r11,r3,-4096
	r11.s64 = ctx.r3.s64 + -268435456;
	// addi r11,r11,-47
	r11.s64 = r11.s64 + -47;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8226b46c
	if (cr6.gt) {
		// ERROR 8226B46C
		return;
	}
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-19128
	r12.s64 = r12.s64 + -19128;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x8226B450
		return;
	case 1:
		// ERROR: 0x8226B450
		return;
	case 2:
		// ERROR: 0x8226B450
		return;
	case 3:
		// ERROR: 0x8226B450
		return;
	case 4:
		// ERROR: 0x8226B450
		return;
	case 5:
		// ERROR: 0x8226B450
		return;
	case 6:
		// ERROR: 0x8226B46C
		return;
	case 7:
		// ERROR: 0x8226B450
		return;
	case 8:
		// ERROR: 0x8226B450
		return;
	case 9:
		// ERROR: 0x8226B450
		return;
	case 10:
		// ERROR: 0x8226B450
		return;
	case 11:
		// ERROR: 0x8226B450
		return;
	case 12:
		// ERROR: 0x8226B450
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8226B548"))) PPC_WEAK_FUNC(sub_8226B548);
PPC_FUNC_IMPL(__imp__sub_8226B548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// lwz r17,-19376(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19376);
	// addis r11,r3,-8192
	r11.s64 = ctx.r3.s64 + -536870912;
	// addi r11,r11,-19
	r11.s64 = r11.s64 + -19;
	// cmplwi cr6,r11,34
	cr6.compare<uint32_t>(r11.u32, 34, xer);
	// bgt cr6,0x8226b46c
	if (cr6.gt) {
		// ERROR 8226B46C
		return;
	}
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-19036
	r12.s64 = r12.s64 + -19036;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x8226B630
		return;
	case 1:
		// ERROR: 0x8226B630
		return;
	case 2:
		// ERROR: 0x8226B630
		return;
	case 3:
		// ERROR: 0x8226B630
		return;
	case 4:
		// ERROR: 0x8226B630
		return;
	case 5:
		// ERROR: 0x8226B630
		return;
	case 6:
		// ERROR: 0x8226B630
		return;
	case 7:
		// ERROR: 0x8226B630
		return;
	case 8:
		// ERROR: 0x8226B46C
		return;
	case 9:
		// ERROR: 0x8226B46C
		return;
	case 10:
		// ERROR: 0x8226B46C
		return;
	case 11:
		// ERROR: 0x8226B630
		return;
	case 12:
		// ERROR: 0x8226B630
		return;
	case 13:
		// ERROR: 0x8226B46C
		return;
	case 14:
		// ERROR: 0x8226B46C
		return;
	case 15:
		// ERROR: 0x8226B46C
		return;
	case 16:
		// ERROR: 0x8226B46C
		return;
	case 17:
		// ERROR: 0x8226B46C
		return;
	case 18:
		// ERROR: 0x8226B46C
		return;
	case 19:
		// ERROR: 0x8226B46C
		return;
	case 20:
		// ERROR: 0x8226B46C
		return;
	case 21:
		// ERROR: 0x8226B46C
		return;
	case 22:
		// ERROR: 0x8226B46C
		return;
	case 23:
		// ERROR: 0x8226B46C
		return;
	case 24:
		// ERROR: 0x8226B46C
		return;
	case 25:
		// ERROR: 0x8226B630
		return;
	case 26:
		// ERROR: 0x8226B46C
		return;
	case 27:
		// ERROR: 0x8226B46C
		return;
	case 28:
		// ERROR: 0x8226B46C
		return;
	case 29:
		// ERROR: 0x8226B46C
		return;
	case 30:
		// ERROR: 0x8226B46C
		return;
	case 31:
		// ERROR: 0x8226B46C
		return;
	case 32:
		// ERROR: 0x8226B46C
		return;
	case 33:
		// ERROR: 0x8226B46C
		return;
	case 34:
		// ERROR: 0x8226B630
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8226B5A4"))) PPC_WEAK_FUNC(sub_8226B5A4);
PPC_FUNC_IMPL(__imp__sub_8226B5A4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-19348(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19348);
	// lwz r17,-18896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18896);
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B638"))) PPC_WEAK_FUNC(sub_8226B638);
PPC_FUNC_IMPL(__imp__sub_8226B638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	// cmplwi cr6,r3,22
	cr6.compare<uint32_t>(ctx.r3.u32, 22, xer);
	// bgt cr6,0x8226b7b8
	if (cr6.gt) {
		sub_8226B7B8(ctx, base);
		return;
	}
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-18856
	r12.s64 = r12.s64 + -18856;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		// ERROR: 0x8226B6B4
		return;
	case 1:
		// ERROR: 0x8226B6C0
		return;
	case 2:
		// ERROR: 0x8226B6B4
		return;
	case 3:
		// ERROR: 0x8226B6C8
		return;
	case 4:
		// ERROR: 0x8226B6D4
		return;
	case 5:
		// ERROR: 0x8226B6E0
		return;
	case 6:
		// ERROR: 0x8226B6EC
		return;
	case 7:
		// ERROR: 0x8226B6F8
		return;
	case 8:
		// ERROR: 0x8226B704
		return;
	case 9:
		// ERROR: 0x8226B710
		return;
	case 10:
		// ERROR: 0x8226B71C
		return;
	case 11:
		// ERROR: 0x8226B728
		return;
	case 12:
		// ERROR: 0x8226B734
		return;
	case 13:
		// ERROR: 0x8226B740
		return;
	case 14:
		// ERROR: 0x8226B74C
		return;
	case 15:
		// ERROR: 0x8226B758
		return;
	case 16:
		// ERROR: 0x8226B764
		return;
	case 17:
		// ERROR: 0x8226B770
		return;
	case 18:
		// ERROR: 0x8226B77C
		return;
	case 19:
		// ERROR: 0x8226B788
		return;
	case 20:
		// ERROR: 0x8226B794
		return;
	case 21:
		// ERROR: 0x8226B7A0
		return;
	case 22:
		// ERROR: 0x8226B7AC
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8226B658"))) PPC_WEAK_FUNC(sub_8226B658);
PPC_FUNC_IMPL(__imp__sub_8226B658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r17{};
	// lwz r17,-18764(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18764);
	// lwz r17,-18752(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18752);
	// lwz r17,-18764(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18764);
	// lwz r17,-18744(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18744);
	// lwz r17,-18732(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18732);
	// lwz r17,-18720(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18720);
	// lwz r17,-18708(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18708);
	// lwz r17,-18696(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18696);
	// lwz r17,-18684(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18684);
	// lwz r17,-18672(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18672);
	// lwz r17,-18660(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18660);
	// lwz r17,-18648(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18648);
	// lwz r17,-18636(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18636);
	// lwz r17,-18624(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18624);
	// lwz r17,-18612(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18612);
	// lwz r17,-18600(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18600);
	// lwz r17,-18588(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18588);
	// lwz r17,-18576(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18576);
	// lwz r17,-18564(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18564);
	// lwz r17,-18552(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18552);
	// lwz r17,-18540(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18540);
	// lwz r17,-18528(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18528);
	// lwz r17,-18516(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18516);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,32779
	ctx.r3.u64 = ctx.r3.u64 | 32779;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B6C0"))) PPC_WEAK_FUNC(sub_8226B6C0);
PPC_FUNC_IMPL(__imp__sub_8226B6C0) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B6C8"))) PPC_WEAK_FUNC(sub_8226B6C8);
PPC_FUNC_IMPL(__imp__sub_8226B6C8) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B6D4"))) PPC_WEAK_FUNC(sub_8226B6D4);
PPC_FUNC_IMPL(__imp__sub_8226B6D4) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B6E0"))) PPC_WEAK_FUNC(sub_8226B6E0);
PPC_FUNC_IMPL(__imp__sub_8226B6E0) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,8
	ctx.r3.u64 = ctx.r3.u64 | 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B6EC"))) PPC_WEAK_FUNC(sub_8226B6EC);
PPC_FUNC_IMPL(__imp__sub_8226B6EC) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,11
	ctx.r3.u64 = ctx.r3.u64 | 11;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B6F8"))) PPC_WEAK_FUNC(sub_8226B6F8);
PPC_FUNC_IMPL(__imp__sub_8226B6F8) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,9
	ctx.r3.u64 = ctx.r3.u64 | 9;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B704"))) PPC_WEAK_FUNC(sub_8226B704);
PPC_FUNC_IMPL(__imp__sub_8226B704) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,15
	ctx.r3.u64 = ctx.r3.u64 | 15;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B710"))) PPC_WEAK_FUNC(sub_8226B710);
PPC_FUNC_IMPL(__imp__sub_8226B710) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,16
	ctx.r3.u64 = ctx.r3.u64 | 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B71C"))) PPC_WEAK_FUNC(sub_8226B71C);
PPC_FUNC_IMPL(__imp__sub_8226B71C) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,12
	ctx.r3.u64 = ctx.r3.u64 | 12;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B728"))) PPC_WEAK_FUNC(sub_8226B728);
PPC_FUNC_IMPL(__imp__sub_8226B728) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,17
	ctx.r3.u64 = ctx.r3.u64 | 17;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B734"))) PPC_WEAK_FUNC(sub_8226B734);
PPC_FUNC_IMPL(__imp__sub_8226B734) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,18
	ctx.r3.u64 = ctx.r3.u64 | 18;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B740"))) PPC_WEAK_FUNC(sub_8226B740);
PPC_FUNC_IMPL(__imp__sub_8226B740) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,35
	ctx.r3.u64 = ctx.r3.u64 | 35;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B74C"))) PPC_WEAK_FUNC(sub_8226B74C);
PPC_FUNC_IMPL(__imp__sub_8226B74C) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,52
	ctx.r3.u64 = ctx.r3.u64 | 52;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B758"))) PPC_WEAK_FUNC(sub_8226B758);
PPC_FUNC_IMPL(__imp__sub_8226B758) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,51
	ctx.r3.u64 = ctx.r3.u64 | 51;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B764"))) PPC_WEAK_FUNC(sub_8226B764);
PPC_FUNC_IMPL(__imp__sub_8226B764) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,50
	ctx.r3.u64 = ctx.r3.u64 | 50;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B770"))) PPC_WEAK_FUNC(sub_8226B770);
PPC_FUNC_IMPL(__imp__sub_8226B770) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,49
	ctx.r3.u64 = ctx.r3.u64 | 49;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B77C"))) PPC_WEAK_FUNC(sub_8226B77C);
PPC_FUNC_IMPL(__imp__sub_8226B77C) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,48
	ctx.r3.u64 = ctx.r3.u64 | 48;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B788"))) PPC_WEAK_FUNC(sub_8226B788);
PPC_FUNC_IMPL(__imp__sub_8226B788) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,47
	ctx.r3.u64 = ctx.r3.u64 | 47;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B794"))) PPC_WEAK_FUNC(sub_8226B794);
PPC_FUNC_IMPL(__imp__sub_8226B794) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,46
	ctx.r3.u64 = ctx.r3.u64 | 46;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B7A0"))) PPC_WEAK_FUNC(sub_8226B7A0);
PPC_FUNC_IMPL(__imp__sub_8226B7A0) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,45
	ctx.r3.u64 = ctx.r3.u64 | 45;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B7AC"))) PPC_WEAK_FUNC(sub_8226B7AC);
PPC_FUNC_IMPL(__imp__sub_8226B7AC) {
	PPC_FUNC_PROLOGUE();
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,59
	ctx.r3.u64 = ctx.r3.u64 | 59;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B7B8"))) PPC_WEAK_FUNC(sub_8226B7B8);
PPC_FUNC_IMPL(__imp__sub_8226B7B8) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B7C0"))) PPC_WEAK_FUNC(sub_8226B7C0);
PPC_FUNC_IMPL(__imp__sub_8226B7C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	// cmplwi cr6,r3,22
	cr6.compare<uint32_t>(ctx.r3.u32, 22, xer);
	// bgt cr6,0x8226b854
	if (cr6.gt) {
		sub_8226B854(ctx, base);
		return;
	}
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-18464
	r12.s64 = r12.s64 + -18464;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		// ERROR: 0x8226B83C
		return;
	case 1:
		// ERROR: 0x8226B83C
		return;
	case 2:
		// ERROR: 0x8226B83C
		return;
	case 3:
		// ERROR: 0x8226B83C
		return;
	case 4:
		// ERROR: 0x8226B83C
		return;
	case 5:
		// ERROR: 0x8226B83C
		return;
	case 6:
		// ERROR: 0x8226B83C
		return;
	case 7:
		// ERROR: 0x8226B83C
		return;
	case 8:
		// ERROR: 0x8226B848
		return;
	case 9:
		// ERROR: 0x8226B83C
		return;
	case 10:
		// ERROR: 0x8226B83C
		return;
	case 11:
		// ERROR: 0x8226B83C
		return;
	case 12:
		// ERROR: 0x8226B83C
		return;
	case 13:
		// ERROR: 0x8226B83C
		return;
	case 14:
		// ERROR: 0x8226B848
		return;
	case 15:
		// ERROR: 0x8226B848
		return;
	case 16:
		// ERROR: 0x8226B848
		return;
	case 17:
		// ERROR: 0x8226B848
		return;
	case 18:
		// ERROR: 0x8226B848
		return;
	case 19:
		// ERROR: 0x8226B848
		return;
	case 20:
		// ERROR: 0x8226B848
		return;
	case 21:
		// ERROR: 0x8226B848
		return;
	case 22:
		// ERROR: 0x8226B83C
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8226B7E0"))) PPC_WEAK_FUNC(sub_8226B7E0);
PPC_FUNC_IMPL(__imp__sub_8226B7E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r17{};
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18360(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18360);
	// lwz r17,-18372(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18372);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2540
	ctx.r3.s64 = r11.s64 + -2540;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B848"))) PPC_WEAK_FUNC(sub_8226B848);
PPC_FUNC_IMPL(__imp__sub_8226B848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2544
	ctx.r3.s64 = r11.s64 + -2544;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B854"))) PPC_WEAK_FUNC(sub_8226B854);
PPC_FUNC_IMPL(__imp__sub_8226B854) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B85C"))) PPC_WEAK_FUNC(sub_8226B85C);
PPC_FUNC_IMPL(__imp__sub_8226B85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B860"))) PPC_WEAK_FUNC(sub_8226B860);
PPC_FUNC_IMPL(__imp__sub_8226B860) {
	PPC_FUNC_PROLOGUE();
	// li r3,23
	ctx.r3.s64 = 23;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226B868"))) PPC_WEAK_FUNC(sub_8226B868);
PPC_FUNC_IMPL(__imp__sub_8226B868) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8226b638
	sub_8226B638(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B870"))) PPC_WEAK_FUNC(sub_8226B870);
PPC_FUNC_IMPL(__imp__sub_8226B870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// bl 0x8226b638
	ctx.lr = 0x8226B884;
	sub_8226B638(ctx, base);
	// bl 0x8226b3e0
	ctx.lr = 0x8226B888;
	sub_8226B3E0(ctx, base);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8226b910
	if (cr6.gt) goto loc_8226B910;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-18260
	r12.s64 = r12.s64 + -18260;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8226B8C0;
	case 1:
		goto loc_8226B8D4;
	case 2:
		goto loc_8226B8FC;
	case 3:
		goto loc_8226B910;
	case 4:
		goto loc_8226B8E8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-18240(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18240);
	// lwz r17,-18220(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18220);
	// lwz r17,-18180(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18180);
	// lwz r17,-18160(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18160);
	// lwz r17,-18200(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18200);
loc_8226B8C0:
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
loc_8226B8D4:
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
loc_8226B8E8:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8226B8FC:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8226B910:
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

__attribute__((alias("__imp__sub_8226B924"))) PPC_WEAK_FUNC(sub_8226B924);
PPC_FUNC_IMPL(__imp__sub_8226B924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226B928"))) PPC_WEAK_FUNC(sub_8226B928);
PPC_FUNC_IMPL(__imp__sub_8226B928) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8226b7c0
	sub_8226B7C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226B930"))) PPC_WEAK_FUNC(sub_8226B930);
PPC_FUNC_IMPL(__imp__sub_8226B930) {
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
	ctx.lr = 0x8226B938;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r29,4304(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295190
	ctx.lr = 0x8226B954;
	sub_82295190(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f88f8
	ctx.lr = 0x8226B960;
	sub_824F88F8(ctx, base);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x82294fd8
	ctx.lr = 0x8226B970;
	sub_82294FD8(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82294fd8
	ctx.lr = 0x8226B980;
	sub_82294FD8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226B988"))) PPC_WEAK_FUNC(sub_8226B988);
PPC_FUNC_IMPL(__imp__sub_8226B988) {
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
	// lis r3,2
	ctx.r3.s64 = 131072;
	// ori r3,r3,6932
	ctx.r3.u64 = ctx.r3.u64 | 6932;
	// bl 0x82130528
	ctx.lr = 0x8226B9A0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226b9bc
	if (cr6.eq) goto loc_8226B9BC;
	// bl 0x82279cc8
	ctx.lr = 0x8226B9AC;
	sub_82279CC8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8226B9BC:
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

__attribute__((alias("__imp__sub_8226B9D0"))) PPC_WEAK_FUNC(sub_8226B9D0);
PPC_FUNC_IMPL(__imp__sub_8226B9D0) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8226B9F8;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226ba14
	if (cr6.eq) goto loc_8226BA14;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r4,r11,15752
	ctx.r4.s64 = r11.s64 + 15752;
	// li r5,19
	ctx.r5.s64 = 19;
	// bl 0x82295a08
	ctx.lr = 0x8226BA14;
	sub_82295A08(ctx, base);
loc_8226BA14:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226BA28"))) PPC_WEAK_FUNC(sub_8226BA28);
PPC_FUNC_IMPL(__imp__sub_8226BA28) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8226BA50;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226bab0
	if (cr6.eq) goto loc_8226BAB0;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822952b0
	ctx.lr = 0x8226BA64;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226bab0
	if (cr6.eq) goto loc_8226BAB0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x8226BA78;
	sub_824F0498(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x8226BA88;
	sub_82295538(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BA90;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226BAA0;
	sub_82270170(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x82296dd8
	ctx.lr = 0x8226BAAC;
	sub_82296DD8(ctx, base);
	// b 0x8226bab4
	goto loc_8226BAB4;
loc_8226BAB0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226BAB4:
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

__attribute__((alias("__imp__sub_8226BACC"))) PPC_WEAK_FUNC(sub_8226BACC);
PPC_FUNC_IMPL(__imp__sub_8226BACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226BAD0"))) PPC_WEAK_FUNC(sub_8226BAD0);
PPC_FUNC_IMPL(__imp__sub_8226BAD0) {
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
	ctx.lr = 0x8226BAD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r11,-28304
	ctx.r3.s64 = r11.s64 + -28304;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r30,4304(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82388178
	ctx.lr = 0x8226BB00;
	sub_82388178(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8226bb20
	if (!cr6.eq) goto loc_8226BB20;
	// stw r28,984(r11)
	PPC_STORE_U32(r11.u32 + 984, r28.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r28,1060(r11)
	PPC_STORE_U32(r11.u32 + 1060, r28.u32);
loc_8226BB20:
	// lwz r11,696(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 696);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8226bccc
	if (!cr6.eq) goto loc_8226BCCC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,700(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 700);
	// bl 0x8227d310
	ctx.lr = 0x8226BB38;
	sub_8227D310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226bccc
	if (cr6.eq) goto loc_8226BCCC;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x82295050
	ctx.lr = 0x8226BB54;
	sub_82295050(ctx, base);
	// std r28,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r28.u64);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BB60;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226BB70;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8226BB78;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x8226BB7C;
	sub_824F92F0(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e9530
	ctx.lr = 0x8226BB98;
	sub_824E9530(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// bl 0x82387b90
	ctx.lr = 0x8226BBA4;
	sub_82387B90(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x8226BBAC;
	sub_8238B7E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8226bccc
	if (cr6.lt) goto loc_8226BCCC;
	// lwz r3,700(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 700);
	// bl 0x82282148
	ctx.lr = 0x8226BBBC;
	sub_82282148(ctx, base);
	// addi r3,r27,48
	ctx.r3.s64 = r27.s64 + 48;
	// bl 0x821f76b0
	ctx.lr = 0x8226BBC4;
	sub_821F76B0(ctx, base);
	// lwz r3,8(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// bl 0x82294c50
	ctx.lr = 0x8226BBCC;
	sub_82294C50(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// bgt cr6,0x8226bbe4
	if (cr6.gt) goto loc_8226BBE4;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8226BBE4:
	// stb r11,756(r27)
	PPC_STORE_U8(r27.u32 + 756, r11.u8);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x8226BBF8;
	sub_822950F8(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,2352(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2352);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8226bc0c
	if (!cr6.gt) goto loc_8226BC0C;
	// li r28,1
	r28.s64 = 1;
loc_8226BC0C:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,-10240(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r26,2428(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 2428);
	// addi r30,r11,2356
	r30.s64 = r11.s64 + 2356;
	// bl 0x82388580
	ctx.lr = 0x8226BC20;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r31,-10240(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,-2524
	ctx.r4.s64 = ctx.r10.s64 + -2524;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82294ef8
	ctx.lr = 0x8226BC3C;
	sub_82294EF8(ctx, base);
	// subf r9,r26,r3
	ctx.r9.s64 = ctx.r3.s64 - r26.s64;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r8,-2628
	r31.s64 = ctx.r8.s64 + -2628;
	// rlwinm r30,r7,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bl 0x82270170
	ctx.lr = 0x8226BC60;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82273760
	ctx.lr = 0x8226BC74;
	sub_82273760(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226bccc
	if (cr6.eq) goto loc_8226BCCC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8226b9d0
	ctx.lr = 0x8226BC8C;
	sub_8226B9D0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x8226BC98;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226bcb8
	if (cr6.eq) goto loc_8226BCB8;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8226BCAC;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,40(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// bl 0x82298848
	ctx.lr = 0x8226BCB8;
	sub_82298848(ctx, base);
loc_8226BCB8:
	// li r11,2
	r11.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,696(r27)
	PPC_STORE_U32(r27.u32 + 696, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8226BCCC:
	// lwz r11,700(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226BCE4;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8226BCF0"))) PPC_WEAK_FUNC(sub_8226BCF0);
PPC_FUNC_IMPL(__imp__sub_8226BCF0) {
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
	ctx.lr = 0x8226BCF8;
	// stwu r1,-784(r1)
	ea = -784 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8226b218
	ctx.lr = 0x8226BD10;
	sub_8226B218(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8226BD14;
	sub_82387B90(ctx, base);
	// lwz r11,696(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 696);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8226be40
	if (!cr6.eq) goto loc_8226BE40;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BD2C;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226BD3C;
	sub_82270170(ctx, base);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226be40
	if (!cr6.eq) goto loc_8226BE40;
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// lwz r27,1344(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 1344);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x8226BD58;
	sub_8238B7E0(ctx, base);
	// cmpw cr6,r3,r27
	cr6.compare<int32_t>(ctx.r3.s32, r27.s32, xer);
	// bne cr6,0x8226be38
	if (!cr6.eq) goto loc_8226BE38;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8226BD70;
	sub_822A3998(ctx, base);
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,8100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8100);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8226be38
	if (cr6.eq) goto loc_8226BE38;
	// lwz r3,700(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// bl 0x82282148
	ctx.lr = 0x8226BD88;
	sub_82282148(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f76b0
	ctx.lr = 0x8226BD90;
	sub_821F76B0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82294c50
	ctx.lr = 0x8226BD98;
	sub_82294C50(ctx, base);
	// lwz r10,168(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lwz r11,164(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// subfic r10,r11,8
	xer.ca = r11.u32 <= 8;
	ctx.r10.s64 = 8 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// stb r8,756(r31)
	PPC_STORE_U8(r31.u32 + 756, ctx.r8.u8);
	// bl 0x82388580
	ctx.lr = 0x8226BDBC;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r6,-2628
	r29.s64 = ctx.r6.s64 + -2628;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226BDD8;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82273628
	ctx.lr = 0x8226BDE4;
	sub_82273628(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8226be40
	if (cr6.eq) goto loc_8226BE40;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226b9d0
	ctx.lr = 0x8226BDFC;
	sub_8226B9D0(ctx, base);
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x8226BE04;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226be24
	if (cr6.eq) goto loc_8226BE24;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8226BE18;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x82298848
	ctx.lr = 0x8226BE24;
	sub_82298848(ctx, base);
loc_8226BE24:
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,696(r31)
	PPC_STORE_U32(r31.u32 + 696, r11.u32);
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// b 0x823d9244
	return;
loc_8226BE38:
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8226be44
	goto loc_8226BE44;
loc_8226BE40:
	// li r4,10
	ctx.r4.s64 = 10;
loc_8226BE44:
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226BE58;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226BE64"))) PPC_WEAK_FUNC(sub_8226BE64);
PPC_FUNC_IMPL(__imp__sub_8226BE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226BE68"))) PPC_WEAK_FUNC(sub_8226BE68);
PPC_FUNC_IMPL(__imp__sub_8226BE68) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BE80;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226BE90;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226befc
	if (cr6.eq) goto loc_8226BEFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BEA4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226BEB4;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x8226BEC0;
	sub_82481578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226befc
	if (cr6.eq) goto loc_8226BEFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BED4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226BEE4;
	sub_82270170(ctx, base);
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x8226b020
	ctx.lr = 0x8226BEEC;
	sub_8226B020(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226bf00
	if (cr6.eq) goto loc_8226BF00;
loc_8226BEFC:
	// li r11,0
	r11.s64 = 0;
loc_8226BF00:
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

__attribute__((alias("__imp__sub_8226BF18"))) PPC_WEAK_FUNC(sub_8226BF18);
PPC_FUNC_IMPL(__imp__sub_8226BF18) {
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
	// bl 0x8226ba28
	ctx.lr = 0x8226BF2C;
	sub_8226BA28(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226bf60
	if (cr6.eq) goto loc_8226BF60;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BF40;
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
	ctx.lr = 0x8226BF54;
	sub_82270170(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8226bf64
	if (cr6.eq) goto loc_8226BF64;
loc_8226BF60:
	// li r11,0
	r11.s64 = 0;
loc_8226BF64:
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

__attribute__((alias("__imp__sub_8226BF7C"))) PPC_WEAK_FUNC(sub_8226BF7C);
PPC_FUNC_IMPL(__imp__sub_8226BF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226BF80"))) PPC_WEAK_FUNC(sub_8226BF80);
PPC_FUNC_IMPL(__imp__sub_8226BF80) {
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
	ctx.lr = 0x8226BF88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298f08
	ctx.lr = 0x8226BFA0;
	sub_82298F08(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8226bfd0
	if (!cr6.eq) goto loc_8226BFD0;
	// lwz r11,700(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226BFC4;
	sub_8268EE10(ctx, base);
loc_8226BFC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8226BFD0:
	// addi r28,r31,44
	r28.s64 = r31.s64 + 44;
	// bl 0x82387b90
	ctx.lr = 0x8226BFD8;
	sub_82387B90(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x8226BFE0;
	sub_8238B7E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8226bfc4
	if (cr6.lt) goto loc_8226BFC4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226BFF0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226C000;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,48
	ctx.r3.s64 = r30.s64 + 48;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x822705d8
	ctx.lr = 0x8226C014;
	sub_822705D8(ctx, base);
	// lwz r10,700(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,29
	ctx.r4.s64 = 29;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226C02C;
	sub_8268EE10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226C038"))) PPC_WEAK_FUNC(sub_8226C038);
PPC_FUNC_IMPL(__imp__sub_8226C038) {
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
	ctx.lr = 0x8226C040;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r11,2356
	r30.s64 = r11.s64 + 2356;
	// lwz r10,2352(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2352);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8226c070
	if (cr6.gt) goto loc_8226C070;
	// li r29,0
	r29.s64 = 0;
loc_8226C070:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r27,72(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x82388580
	ctx.lr = 0x8226C07C;
	sub_82388580(ctx, base);
	// lwz r31,-10240(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,-2524
	ctx.r4.s64 = ctx.r10.s64 + -2524;
	// lwz r30,4292(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4292);
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82294ef8
	ctx.lr = 0x8226C09C;
	sub_82294EF8(ctx, base);
	// subf r9,r27,r3
	ctx.r9.s64 = ctx.r3.s64 - r27.s64;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r31,r8,-11588
	r31.s64 = ctx.r8.s64 + -11588;
	// rlwinm r27,r7,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x82270170
	ctx.lr = 0x8226C0BC;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// bl 0x82298f60
	ctx.lr = 0x8226C0D8;
	sub_82298F60(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226c0f8
	if (cr6.eq) goto loc_8226C0F8;
	// li r11,3
	r11.s64 = 3;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,696(r28)
	PPC_STORE_U32(r28.u32 + 696, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8226C0F8:
	// lwz r11,700(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226C110;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8226C11C"))) PPC_WEAK_FUNC(sub_8226C11C);
PPC_FUNC_IMPL(__imp__sub_8226C11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C120"))) PPC_WEAK_FUNC(sub_8226C120);
PPC_FUNC_IMPL(__imp__sub_8226C120) {
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
	ctx.lr = 0x8226C128;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-2456
	ctx.r3.s64 = r11.s64 + -2456;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8226C150;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8226C164;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226c1e4
	if (cr6.eq) goto loc_8226C1E4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2480
	ctx.r4.s64 = r11.s64 + -2480;
	// bl 0x82637dd8
	ctx.lr = 0x8226C17C;
	sub_82637DD8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10016(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c1e4
	if (cr6.eq) goto loc_8226C1E4;
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8226c1e4
	if (!cr6.gt) goto loc_8226C1E4;
	// bl 0x8265e5e8
	ctx.lr = 0x8226C19C;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c1e4
	if (cr6.eq) goto loc_8226C1E4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8226C1BC;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-2496
	ctx.r4.s64 = ctx.r9.s64 + -2496;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8226C1D4;
	sub_822183B0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-2516
	ctx.r4.s64 = ctx.r8.s64 + -2516;
	// bl 0x82637dd8
	ctx.lr = 0x8226C1E4;
	sub_82637DD8(ctx, base);
loc_8226C1E4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r29,48
	ctx.r3.s64 = r29.s64 + 48;
	// bl 0x82215500
	ctx.lr = 0x8226C1F0;
	sub_82215500(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226C1F8;
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
	ctx.lr = 0x8226C20C;
	sub_82270170(ctx, base);
	// lwz r11,700(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r9,108(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 108);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,29
	ctx.r4.s64 = 29;
	// cmplw cr6,r9,r3
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x8226c250
	if (cr6.eq) goto loc_8226C250;
	// bl 0x8268ee10
	ctx.lr = 0x8226C230;
	sub_8268EE10(ctx, base);
	// lwz r10,700(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,31
	ctx.r4.s64 = 31;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226C248;
	sub_8268EE10(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8226C250:
	// bl 0x8268ee10
	ctx.lr = 0x8226C254;
	sub_8268EE10(ctx, base);
	// addi r31,r29,140
	r31.s64 = r29.s64 + 140;
	// bl 0x82387b90
	ctx.lr = 0x8226C25C;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x8226C264;
	sub_8238B7E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226C26C"))) PPC_WEAK_FUNC(sub_8226C26C);
PPC_FUNC_IMPL(__imp__sub_8226C26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C270"))) PPC_WEAK_FUNC(sub_8226C270);
PPC_FUNC_IMPL(__imp__sub_8226C270) {
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
	ctx.lr = 0x8226C278;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221df98
	ctx.lr = 0x8226C294;
	sub_8221DF98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c3c8
	if (cr6.eq) goto loc_8226C3C8;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,1828
	ctx.r10.s64 = ctx.r10.s64 + 1828;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8226c2c4
	if (!cr6.eq) goto loc_8226C2C4;
	// li r11,0
	r11.s64 = 0;
loc_8226C2C4:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r9,-2212
	ctx.r3.s64 = ctx.r9.s64 + -2212;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x821fa230
	ctx.lr = 0x8226C2D8;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2232
	ctx.r3.s64 = r11.s64 + -2232;
	// bl 0x821fa230
	ctx.lr = 0x8226C2EC;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2256
	ctx.r3.s64 = r11.s64 + -2256;
	// bl 0x821fa230
	ctx.lr = 0x8226C300;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2276
	ctx.r3.s64 = r11.s64 + -2276;
	// bl 0x821fa230
	ctx.lr = 0x8226C314;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2296
	ctx.r3.s64 = r11.s64 + -2296;
	// bl 0x821fa230
	ctx.lr = 0x8226C328;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2320
	ctx.r3.s64 = r11.s64 + -2320;
	// bl 0x821fa230
	ctx.lr = 0x8226C33C;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2344
	ctx.r3.s64 = r11.s64 + -2344;
	// bl 0x821fa230
	ctx.lr = 0x8226C350;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2372
	ctx.r3.s64 = r11.s64 + -2372;
	// bl 0x821fa230
	ctx.lr = 0x8226C364;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2392
	ctx.r3.s64 = r11.s64 + -2392;
	// bl 0x821fa230
	ctx.lr = 0x8226C378;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2412
	ctx.r3.s64 = r11.s64 + -2412;
	// bl 0x821fa230
	ctx.lr = 0x8226C38C;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2428
	ctx.r3.s64 = r11.s64 + -2428;
	// bl 0x821fa230
	ctx.lr = 0x8226C3A0;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226c3c0
	if (cr6.eq) goto loc_8226C3C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-2444
	ctx.r3.s64 = r11.s64 + -2444;
	// bl 0x821fa230
	ctx.lr = 0x8226C3B4;
	sub_821FA230(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8226c3c4
	if (!cr6.eq) goto loc_8226C3C4;
loc_8226C3C0:
	// li r11,1
	r11.s64 = 1;
loc_8226C3C4:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_8226C3C8:
	// lwz r11,696(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 696);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8226c3ec
	if (cr6.eq) goto loc_8226C3EC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8226c3ec
	if (cr6.eq) goto loc_8226C3EC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8226c3f0
	if (cr6.eq) goto loc_8226C3F0;
loc_8226C3EC:
	// li r11,1
	r11.s64 = 1;
loc_8226C3F0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226C3FC"))) PPC_WEAK_FUNC(sub_8226C3FC);
PPC_FUNC_IMPL(__imp__sub_8226C3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C400"))) PPC_WEAK_FUNC(sub_8226C400);
PPC_FUNC_IMPL(__imp__sub_8226C400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4292(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,696(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 696);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8226c440
	if (cr6.eq) goto loc_8226C440;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,700(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
loc_8226C440:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r11,696(r3)
	PPC_STORE_U32(ctx.r3.u32 + 696, r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r11,700(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 700);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bne cr6,0x8226c468
	if (!cr6.eq) goto loc_8226C468;
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
loc_8226C468:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8226C470"))) PPC_WEAK_FUNC(sub_8226C470);
PPC_FUNC_IMPL(__imp__sub_8226C470) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226C474"))) PPC_WEAK_FUNC(sub_8226C474);
PPC_FUNC_IMPL(__imp__sub_8226C474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C478"))) PPC_WEAK_FUNC(sub_8226C478);
PPC_FUNC_IMPL(__imp__sub_8226C478) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8226C498;
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
	ctx.lr = 0x8226C4AC;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8226C4B4;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226c538
	if (cr6.eq) goto loc_8226C538;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// bl 0x822b6308
	ctx.lr = 0x8226C4CC;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c538
	if (cr6.eq) goto loc_8226C538;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8226c504
	if (cr6.eq) goto loc_8226C504;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8226c510
	goto loc_8226C510;
loc_8226C504:
	// lwz r10,17892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_8226C510:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226C524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226c538
	if (cr6.eq) goto loc_8226C538;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822914c8
	ctx.lr = 0x8226C538;
	sub_822914C8(ctx, base);
loc_8226C538:
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

__attribute__((alias("__imp__sub_8226C550"))) PPC_WEAK_FUNC(sub_8226C550);
PPC_FUNC_IMPL(__imp__sub_8226C550) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8226C56C;
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
	ctx.lr = 0x8226C580;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8226C588;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226c598
	if (cr6.eq) goto loc_8226C598;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822914d8
	ctx.lr = 0x8226C598;
	sub_822914D8(ctx, base);
loc_8226C598:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226C5AC"))) PPC_WEAK_FUNC(sub_8226C5AC);
PPC_FUNC_IMPL(__imp__sub_8226C5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C5B0"))) PPC_WEAK_FUNC(sub_8226C5B0);
PPC_FUNC_IMPL(__imp__sub_8226C5B0) {
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
	ctx.lr = 0x8226C5B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-2052
	ctx.r3.s64 = r11.s64 + -2052;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r31,r10,-18876
	r31.s64 = ctx.r10.s64 + -18876;
	// addi r28,r9,-22108
	r28.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8226C5E0;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8226C5F4;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226C600;
	sub_8226BE68(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8226c6c0
	if (cr6.eq) goto loc_8226C6C0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226c6c0
	if (cr6.eq) goto loc_8226C6C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-2068
	ctx.r4.s64 = r11.s64 + -2068;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8226C628;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226c6a8
	if (cr6.eq) goto loc_8226C6A8;
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8226c694
	if (cr6.gt) goto loc_8226C694;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-14764
	r12.s64 = r12.s64 + -14764;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8226C67C;
	case 1:
		goto loc_8226C688;
	case 2:
		goto loc_8226C664;
	case 3:
		goto loc_8226C670;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-14724(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14724);
	// lwz r17,-14712(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14712);
	// lwz r17,-14748(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14748);
	// lwz r17,-14736(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14736);
loc_8226C664:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r9,r11,-2092
	ctx.r9.s64 = r11.s64 + -2092;
	// b 0x8226c69c
	goto loc_8226C69C;
loc_8226C670:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r9,r11,-2116
	ctx.r9.s64 = r11.s64 + -2116;
	// b 0x8226c69c
	goto loc_8226C69C;
loc_8226C67C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r9,r11,-2144
	ctx.r9.s64 = r11.s64 + -2144;
	// b 0x8226c69c
	goto loc_8226C69C;
loc_8226C688:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r9,r11,-2168
	ctx.r9.s64 = r11.s64 + -2168;
	// b 0x8226c69c
	goto loc_8226C69C;
loc_8226C694:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r9,r11,-2196
	ctx.r9.s64 = r11.s64 + -2196;
loc_8226C69C:
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8226C6A8:
	// lwz r11,700(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,40
	ctx.r4.s64 = 40;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226C6C0;
	sub_8268EE10(ctx, base);
loc_8226C6C0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226C6C8"))) PPC_WEAK_FUNC(sub_8226C6C8);
PPC_FUNC_IMPL(__imp__sub_8226C6C8) {
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
	ctx.lr = 0x8226C6D0;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r10,r11,-7496
	ctx.r10.s64 = r11.s64 + -7496;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226c804
	if (!cr6.eq) goto loc_8226C804;
	// bl 0x8226be68
	ctx.lr = 0x8226C6F8;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c804
	if (cr6.eq) goto loc_8226C804;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x824e70f0
	ctx.lr = 0x8226C70C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c804
	if (cr6.eq) goto loc_8226C804;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r11,-2628
	r30.s64 = r11.s64 + -2628;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8226C730;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226c804
	if (cr6.eq) goto loc_8226C804;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x822952b0
	ctx.lr = 0x8226C744;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c804
	if (cr6.eq) goto loc_8226C804;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8226C75C;
	sub_822701C8(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x82295648
	ctx.lr = 0x8226C764;
	sub_82295648(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x8226c804
	if (cr6.lt) goto loc_8226C804;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822952b0
	ctx.lr = 0x8226C788;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c7ac
	if (cr6.eq) goto loc_8226C7AC;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8226C7A0;
	sub_82295E90(ctx, base);
	// subf r11,r30,r3
	r11.s64 = ctx.r3.s64 - r30.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r30,r10,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8226C7AC:
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x82294d98
	ctx.lr = 0x8226C7B4;
	sub_82294D98(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,-2036(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2036);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// beq cr6,0x8226c7ec
	if (cr6.eq) goto loc_8226C7EC;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,15004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15004);
	f0.f64 = double(temp.f32);
	// lfs f3,29504(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29504);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f1,f13,f0,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64 + f31.f64));
	// bl 0x82151fe0
	ctx.lr = 0x8226C7E8;
	sub_82151FE0(ctx, base);
	// b 0x8226c7f0
	goto loc_8226C7F0;
loc_8226C7EC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_8226C7F0:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lfs f2,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822f1518
	ctx.lr = 0x8226C804;
	sub_822F1518(ctx, base);
loc_8226C804:
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

__attribute__((alias("__imp__sub_8226C814"))) PPC_WEAK_FUNC(sub_8226C814);
PPC_FUNC_IMPL(__imp__sub_8226C814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C818"))) PPC_WEAK_FUNC(sub_8226C818);
PPC_FUNC_IMPL(__imp__sub_8226C818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x8226C820;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226C82C;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c98c
	if (cr6.eq) goto loc_8226C98C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8226C84C;
	sub_822701C8(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x822952b0
	ctx.lr = 0x8226C858;
	sub_822952B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226c98c
	if (cr6.eq) goto loc_8226C98C;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295c90
	ctx.lr = 0x8226C870;
	sub_82295C90(ctx, base);
	// lis r27,-32120
	r27.s64 = -2105016320;
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r28,-7884(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + -7884);
	// bl 0x8227e750
	ctx.lr = 0x8226C888;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226c96c
	if (cr6.eq) goto loc_8226C96C;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r31,0
	r31.s64 = 0;
	// li r30,1
	r30.s64 = 1;
	// bl 0x822952b0
	ctx.lr = 0x8226C8A8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226c91c
	if (cr6.eq) goto loc_8226C91C;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x8226C8C0;
	sub_82295E90(ctx, base);
	// subf r10,r31,r3
	ctx.r10.s64 = ctx.r3.s64 - r31.s64;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bgt cr6,0x8226c918
	if (cr6.gt) goto loc_8226C918;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-14096
	r12.s64 = r12.s64 + -14096;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8226C91C;
	case 1:
		goto loc_8226C900;
	case 2:
		goto loc_8226C910;
	case 3:
		goto loc_8226C908;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-14052(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14052);
	// lwz r17,-14080(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14080);
	// lwz r17,-14064(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14064);
	// lwz r17,-14072(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14072);
loc_8226C900:
	// li r31,1
	r31.s64 = 1;
	// b 0x8226c91c
	goto loc_8226C91C;
loc_8226C908:
	// li r31,2
	r31.s64 = 2;
	// b 0x8226c91c
	goto loc_8226C91C;
loc_8226C910:
	// li r31,3
	r31.s64 = 3;
	// b 0x8226c91c
	goto loc_8226C91C;
loc_8226C918:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_8226C91C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r30,-7880(r11)
	PPC_STORE_U8(r11.u32 + -7880, r30.u8);
	// bne cr6,0x8226c944
	if (!cr6.eq) goto loc_8226C944;
	// cmpw cr6,r28,r31
	cr6.compare<int32_t>(r28.s32, r31.s32, xer);
	// beq cr6,0x8226c944
	if (cr6.eq) goto loc_8226C944;
	// stw r31,-7884(r27)
	PPC_STORE_U32(r27.u32 + -7884, r31.u32);
	// bl 0x822e8a78
	ctx.lr = 0x8226C940;
	sub_822E8A78(ctx, base);
	// mr r28,r31
	r28.u64 = r31.u64;
loc_8226C944:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x8226c98c
	if (cr6.lt) goto loc_8226C98C;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// beq cr6,0x8226c98c
	if (cr6.eq) goto loc_8226C98C;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295d70
	ctx.lr = 0x8226C964;
	sub_82295D70(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8226C96C:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stb r11,-7880(r10)
	PPC_STORE_U8(ctx.r10.u32 + -7880, r11.u8);
	// blt cr6,0x8226c98c
	if (cr6.lt) goto loc_8226C98C;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// beq cr6,0x8226c98c
	if (cr6.eq) goto loc_8226C98C;
	// stw r26,-7884(r27)
	PPC_STORE_U32(r27.u32 + -7884, r26.u32);
loc_8226C98C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8226C994"))) PPC_WEAK_FUNC(sub_8226C994);
PPC_FUNC_IMPL(__imp__sub_8226C994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226C998"))) PPC_WEAK_FUNC(sub_8226C998);
PPC_FUNC_IMPL(__imp__sub_8226C998) {
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
	ctx.lr = 0x8226C9A0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r11,4300(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226cc78
	if (cr6.eq) goto loc_8226CC78;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226C9C4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226C9D4;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272e60
	ctx.lr = 0x8226C9DC;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226ca2c
	if (!cr6.eq) goto loc_8226CA2C;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r23,1
	r23.s64 = 1;
	// bl 0x82388580
	ctx.lr = 0x8226C9F4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CA04;
	sub_82270170(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82272e60
	ctx.lr = 0x8226CA0C;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226ca2c
	if (!cr6.eq) goto loc_8226CA2C;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82464900
	ctx.lr = 0x8226CA24;
	sub_82464900(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_8226CA2C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CA34;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CA44;
	sub_82270170(ctx, base);
	// addic. r30,r3,208
	xer.ca = ctx.r3.u32 > 4294967087;
	r30.s64 = ctx.r3.s64 + 208;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x8226cc78
	if (cr0.eq) goto loc_8226CC78;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cc78
	if (cr6.eq) goto loc_8226CC78;
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x8226CA60;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cc78
	if (cr6.eq) goto loc_8226CC78;
	// lwz r24,0(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r25,31
	r25.s64 = 31;
	// addi r26,r24,12
	r26.s64 = r24.s64 + 12;
loc_8226CA78:
	// lwz r29,0(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226cc6c
	if (cr6.eq) goto loc_8226CC6C;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cb00
	if (cr6.eq) goto loc_8226CB00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CA98;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CAA8;
	sub_82270170(ctx, base);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226cb00
	if (cr6.eq) goto loc_8226CB00;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8226CAB8;
	sub_824E7110(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CAC4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CAD4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8226CADC;
	sub_821F8730(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463d20
	ctx.lr = 0x8226CAF0;
	sub_82463D20(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226cb04
	if (cr6.eq) goto loc_8226CB04;
loc_8226CB00:
	// li r27,1
	r27.s64 = 1;
loc_8226CB04:
	// addi r30,r29,16
	r30.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7110
	ctx.lr = 0x8226CB10;
	sub_824E7110(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CB1C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CB2C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8226CB34;
	sub_821F8730(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463cb8
	ctx.lr = 0x8226CB48;
	sub_82463CB8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226cb70
	if (!cr6.eq) goto loc_8226CB70;
	// lbz r11,281(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 281);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226cb70
	if (!cr6.eq) goto loc_8226CB70;
	// lbz r11,282(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 282);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cb74
	if (cr6.eq) goto loc_8226CB74;
loc_8226CB70:
	// li r28,1
	r28.s64 = 1;
loc_8226CB74:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x8226CB7C;
	sub_82502300(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82464958
	ctx.lr = 0x8226CB8C;
	sub_82464958(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r11,278(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 278);
	// bne cr6,0x8226cc34
	if (!cr6.eq) goto loc_8226CC34;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226cc6c
	if (!cr6.eq) goto loc_8226CC6C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cc6c
	if (cr6.eq) goto loc_8226CC6C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226cc6c
	if (!cr6.eq) goto loc_8226CC6C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7060
	ctx.lr = 0x8226CBC4;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cc1c
	if (cr6.eq) goto loc_8226CC1C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x8226CBD8;
	sub_824E6310(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8226CBE0;
	sub_82130000(ctx, base);
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x824f97c0
	ctx.lr = 0x8226CBE8;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r24,144
	ctx.r3.s64 = r24.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82482560
	ctx.lr = 0x8226CBF8;
	sub_82482560(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cc6c
	if (cr6.eq) goto loc_8226CC6C;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x824645d8
	ctx.lr = 0x8226CC18;
	sub_824645D8(ctx, base);
	// b 0x8226cc6c
	goto loc_8226CC6C;
loc_8226CC1C:
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x824645d8
	ctx.lr = 0x8226CC30;
	sub_824645D8(ctx, base);
	// b 0x8226cc6c
	goto loc_8226CC6C;
loc_8226CC34:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226cc54
	if (!cr6.eq) goto loc_8226CC54;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226cc54
	if (!cr6.eq) goto loc_8226CC54;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226cc6c
	if (!cr6.eq) goto loc_8226CC6C;
loc_8226CC54:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x8226CC5C;
	sub_82502300(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82464790
	ctx.lr = 0x8226CC6C;
	sub_82464790(ctx, base);
loc_8226CC6C:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x8226ca78
	if (!cr0.eq) goto loc_8226CA78;
loc_8226CC78:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8226CC80"))) PPC_WEAK_FUNC(sub_8226CC80);
PPC_FUNC_IMPL(__imp__sub_8226CC80) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CCA0;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226CCB0;
	sub_82270170(ctx, base);
	// lbz r11,279(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ccec
	if (cr6.eq) goto loc_8226CCEC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226CCC4;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ccec
	if (cr6.eq) goto loc_8226CCEC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CCD8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CCE8;
	sub_82270170(ctx, base);
	// bl 0x82274ae0
	ctx.lr = 0x8226CCEC;
	sub_82274AE0(ctx, base);
loc_8226CCEC:
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cd00
	if (cr6.eq) goto loc_8226CD00;
	// bl 0x82298cb0
	ctx.lr = 0x8226CD00;
	sub_82298CB0(ctx, base);
loc_8226CD00:
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

__attribute__((alias("__imp__sub_8226CD18"))) PPC_WEAK_FUNC(sub_8226CD18);
PPC_FUNC_IMPL(__imp__sub_8226CD18) {
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
	ctx.lr = 0x8226CD20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,700(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8226CD30;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ce5c
	if (cr6.eq) goto loc_8226CE5C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8226CD50;
	sub_822701C8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8226ce5c
	if (cr6.eq) goto loc_8226CE5C;
	// li r4,8
	ctx.r4.s64 = 8;
	// li r31,0
	r31.s64 = 0;
	// bl 0x822952b0
	ctx.lr = 0x8226CD68;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226cd94
	if (cr6.eq) goto loc_8226CD94;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8226ba28
	ctx.lr = 0x8226CD7C;
	sub_8226BA28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226cd94
	if (cr6.eq) goto loc_8226CD94;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8226CD8C;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8226cd98
	if (cr6.eq) goto loc_8226CD98;
loc_8226CD94:
	// li r31,1
	r31.s64 = 1;
loc_8226CD98:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ce5c
	if (cr6.eq) goto loc_8226CE5C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226CDAC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226CDBC;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ce38
	if (cr6.eq) goto loc_8226CE38;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8226CDD0:
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// beq cr6,0x8226ce38
	if (cr6.eq) goto loc_8226CE38;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226ce0c
	if (cr6.eq) goto loc_8226CE0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8226CDEC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ce0c
	if (cr6.eq) goto loc_8226CE0C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8226CE04;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8226ce18
	if (cr6.eq) goto loc_8226CE18;
loc_8226CE0C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// b 0x8226cdd0
	goto loc_8226CDD0;
loc_8226CE18:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x8226CE20;
	sub_82502300(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295bc8
	ctx.lr = 0x8226CE30;
	sub_82295BC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8226CE38:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x8226CE44;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ce5c
	if (cr6.eq) goto loc_8226CE5C;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295828
	ctx.lr = 0x8226CE5C;
	sub_82295828(ctx, base);
loc_8226CE5C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226CE64"))) PPC_WEAK_FUNC(sub_8226CE64);
PPC_FUNC_IMPL(__imp__sub_8226CE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226CE68"))) PPC_WEAK_FUNC(sub_8226CE68);
PPC_FUNC_IMPL(__imp__sub_8226CE68) {
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
	// lwz r3,752(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 752);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8226cec0
	if (!cr6.eq) goto loc_8226CEC0;
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x8226CE90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226cea0
	if (cr6.eq) goto loc_8226CEA0;
	// bl 0x824f6c78
	ctx.lr = 0x8226CE9C;
	sub_824F6C78(ctx, base);
	// b 0x8226cea4
	goto loc_8226CEA4;
loc_8226CEA0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226CEA4:
	// stw r3,752(r31)
	PPC_STORE_U32(r31.u32 + 752, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r4,r11,1184
	ctx.r4.s64 = r11.s64 + 1184;
	// bl 0x824f5ad0
	ctx.lr = 0x8226CEBC;
	sub_824F5AD0(ctx, base);
	// lwz r3,752(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 752);
loc_8226CEC0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226CED4"))) PPC_WEAK_FUNC(sub_8226CED4);
PPC_FUNC_IMPL(__imp__sub_8226CED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226CED8"))) PPC_WEAK_FUNC(sub_8226CED8);
PPC_FUNC_IMPL(__imp__sub_8226CED8) {
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
	// lwz r3,752(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 752);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226cf00
	if (cr6.eq) goto loc_8226CF00;
	// bl 0x824f5c38
	ctx.lr = 0x8226CF00;
	sub_824F5C38(ctx, base);
loc_8226CF00:
	// lwz r31,752(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 752);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226cf1c
	if (cr6.eq) goto loc_8226CF1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f6d10
	ctx.lr = 0x8226CF14;
	sub_824F6D10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8226CF1C;
	sub_82130588(ctx, base);
loc_8226CF1C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,752(r30)
	PPC_STORE_U32(r30.u32 + 752, r11.u32);
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

__attribute__((alias("__imp__sub_8226CF3C"))) PPC_WEAK_FUNC(sub_8226CF3C);
PPC_FUNC_IMPL(__imp__sub_8226CF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226CF40"))) PPC_WEAK_FUNC(sub_8226CF40);
PPC_FUNC_IMPL(__imp__sub_8226CF40) {
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
	ctx.lr = 0x8226CF48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x8226CF64;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226cfa4
	if (cr6.eq) goto loc_8226CFA4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,7
	ctx.r5.s64 = 7;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x8226CF8C;
	sub_82618390(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x8226CF98;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8226CFA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226CFB0"))) PPC_WEAK_FUNC(sub_8226CFB0);
PPC_FUNC_IMPL(__imp__sub_8226CFB0) {
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
	ctx.lr = 0x8226CFB8;
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
	ctx.lr = 0x8226CFDC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8226CFE8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8226CFF8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226d01c
	if (cr6.eq) goto loc_8226D01C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226cf40
	ctx.lr = 0x8226D00C;
	sub_8226CF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226d020
	if (!cr6.eq) goto loc_8226D020;
loc_8226D01C:
	// li r30,0
	r30.s64 = 0;
loc_8226D020:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8226d058
	if (cr6.eq) goto loc_8226D058;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d050
	if (cr6.eq) goto loc_8226D050;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8226D03C;
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
loc_8226D050:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8226D058:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226D064"))) PPC_WEAK_FUNC(sub_8226D064);
PPC_FUNC_IMPL(__imp__sub_8226D064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226D068"))) PPC_WEAK_FUNC(sub_8226D068);
PPC_FUNC_IMPL(__imp__sub_8226D068) {
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
	ctx.lr = 0x8226D070;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226d104
	if (cr6.eq) goto loc_8226D104;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x8226D088;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d104
	if (cr6.eq) goto loc_8226D104;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226d104
	if (!cr6.eq) goto loc_8226D104;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8226D0C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226d110
	if (cr6.eq) goto loc_8226D110;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r29,12
	r30.s64 = r29.s64 + 12;
loc_8226D0D4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8226d0f4
	if (!cr6.gt) goto loc_8226D0F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82299d48
	ctx.lr = 0x8226D0EC;
	sub_82299D48(ctx, base);
	// cmplwi cr6,r3,500
	cr6.compare<uint32_t>(ctx.r3.u32, 500, xer);
	// bge cr6,0x8226d110
	if (!cr6.lt) goto loc_8226D110;
loc_8226D0F4:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// cmpwi cr6,r31,16
	cr6.compare<int32_t>(r31.s32, 16, xer);
	// blt cr6,0x8226d0d4
	if (cr6.lt) goto loc_8226D0D4;
loc_8226D104:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8226D110:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226D11C"))) PPC_WEAK_FUNC(sub_8226D11C);
PPC_FUNC_IMPL(__imp__sub_8226D11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226D120"))) PPC_WEAK_FUNC(sub_8226D120);
PPC_FUNC_IMPL(__imp__sub_8226D120) {
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
	ctx.lr = 0x8226D128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226D134;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d228
	if (cr6.eq) goto loc_8226D228;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lbz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8226d228
	if (!cr6.eq) goto loc_8226D228;
	// lwz r3,700(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8226D15C;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d184
	if (cr6.eq) goto loc_8226D184;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4296(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r4,68(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// b 0x8226d21c
	goto loc_8226D21C;
loc_8226D184:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226D18C;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226D19C;
	sub_82270170(ctx, base);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226d228
	if (cr6.eq) goto loc_8226D228;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// bl 0x824e6310
	ctx.lr = 0x8226D1B4;
	sub_824E6310(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r31,11780(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 11780);
	// beq cr6,0x8226d228
	if (cr6.eq) goto loc_8226D228;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226d228
	if (cr6.eq) goto loc_8226D228;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481578
	ctx.lr = 0x8226D1D0;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d228
	if (cr6.eq) goto loc_8226D228;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x8226D1E4;
	sub_82130000(ctx, base);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// bl 0x824f97c0
	ctx.lr = 0x8226D1EC;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82482560
	ctx.lr = 0x8226D1FC;
	sub_82482560(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d228
	if (cr6.eq) goto loc_8226D228;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 68);
loc_8226D21C:
	// li r7,10
	ctx.r7.s64 = 10;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x82294bb8
	ctx.lr = 0x8226D228;
	sub_82294BB8(ctx, base);
loc_8226D228:
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x82294cc8
	ctx.lr = 0x8226D230;
	sub_82294CC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226D238"))) PPC_WEAK_FUNC(sub_8226D238);
PPC_FUNC_IMPL(__imp__sub_8226D238) {
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
	ctx.lr = 0x8226D240;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226d2fc
	if (cr6.eq) goto loc_8226D2FC;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r31,0
	r31.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x8226D270;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d2d8
	if (cr6.eq) goto loc_8226D2D8;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82274f48
	ctx.lr = 0x8226D28C;
	sub_82274F48(ctx, base);
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226d2d8
	if (cr6.eq) goto loc_8226D2D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r29,17268(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8226D2B4;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226d2d8
	if (cr6.eq) goto loc_8226D2D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x8226D2CC;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,40(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// bl 0x82298c20
	ctx.lr = 0x8226D2D8;
	sub_82298C20(ctx, base);
loc_8226D2D8:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x8226D2E8;
	sub_82274120(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lbz r11,277(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 277);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226d2fc
	if (!cr6.eq) goto loc_8226D2FC;
	// bl 0x822912d8
	ctx.lr = 0x8226D2FC;
	sub_822912D8(ctx, base);
loc_8226D2FC:
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r3,700(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 700);
	// bl 0x82281ba8
	ctx.lr = 0x8226D308;
	sub_82281BA8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226D310"))) PPC_WEAK_FUNC(sub_8226D310);
PPC_FUNC_IMPL(__imp__sub_8226D310) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8226D318;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226d62c
	if (cr6.eq) goto loc_8226D62C;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82274f48
	ctx.lr = 0x8226D340;
	sub_82274F48(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8226d378
	if (cr6.lt) goto loc_8226D378;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x8226D360;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d378
	if (cr6.eq) goto loc_8226D378;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5948
	ctx.lr = 0x8226D374;
	sub_822A5948(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_8226D378:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d3c8
	if (cr6.eq) goto loc_8226D3C8;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x8226D38C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d3c8
	if (cr6.eq) goto loc_8226D3C8;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227cef0
	ctx.lr = 0x8226D3A8;
	sub_8227CEF0(ctx, base);
	// lwz r3,40(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d3c8
	if (cr6.eq) goto loc_8226D3C8;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8226d3c8
	if (cr6.eq) goto loc_8226D3C8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822989d8
	ctx.lr = 0x8226D3C8;
	sub_822989D8(ctx, base);
loc_8226D3C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226D3D0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226D3E0;
	sub_82270170(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// addi r27,r11,-22108
	r27.s64 = r11.s64 + -22108;
	// beq cr6,0x8226d44c
	if (cr6.eq) goto loc_8226D44C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226D3FC;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d44c
	if (cr6.eq) goto loc_8226D44C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8226D414;
	sub_824E7118(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,-1952
	ctx.r4.s64 = ctx.r10.s64 + -1952;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8226D42C;
	sub_822183B0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r4,r7,-1968
	ctx.r4.s64 = ctx.r7.s64 + -1968;
	// lwz r3,-10028(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// lfs f1,30712(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82208800
	ctx.lr = 0x8226D448;
	sub_82208800(ctx, base);
	// b 0x8226d4b4
	goto loc_8226D4B4;
loc_8226D44C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226D454;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226D464;
	sub_82270170(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226d4b4
	if (!cr6.eq) goto loc_8226D4B4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r3,r11,-1992
	ctx.r3.s64 = r11.s64 + -1992;
	// addi r31,r10,-11404
	r31.s64 = ctx.r10.s64 + -11404;
	// bl 0x821fa230
	ctx.lr = 0x8226D484;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8226D498;
	sub_823DEDD8(ctx, base);
	// lbz r9,976(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 976);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226d4b4
	if (cr6.eq) goto loc_8226D4B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226D4B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8226D4B4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r29,r11,-12068
	r29.s64 = r11.s64 + -12068;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r31,r11,-17812
	r31.s64 = r11.s64 + -17812;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82691650
	ctx.lr = 0x8226D4E0;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8226D4F4;
	sub_823DEDD8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226D504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226d628
	if (cr6.eq) goto loc_8226D628;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8226d628
	if (cr6.eq) goto loc_8226D628;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82691650
	ctx.lr = 0x8226D524;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8226D538;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226d628
	if (cr6.eq) goto loc_8226D628;
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// bne cr6,0x8226d628
	if (!cr6.eq) goto loc_8226D628;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8226D554;
	sub_822A39C8(ctx, base);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// beq cr6,0x8226d628
	if (cr6.eq) goto loc_8226D628;
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
	ctx.lr = 0x8226D578;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8226d614
	if (!cr6.eq) goto loc_8226D614;
	// bl 0x82207e88
	ctx.lr = 0x8226D588;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226d614
	if (!cr6.eq) goto loc_8226D614;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bne cr6,0x8226d5e8
	if (!cr6.eq) goto loc_8226D5E8;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-2012
	ctx.r3.s64 = ctx.r10.s64 + -2012;
	// bl 0x821fa230
	ctx.lr = 0x8226D5C8;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8226D5DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8221fa88
	ctx.lr = 0x8226D5E0;
	sub_8221FA88(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8226D5E8:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-2032
	ctx.r3.s64 = ctx.r10.s64 + -2032;
	// bl 0x821fa230
	ctx.lr = 0x8226D5F4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8226D608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8221fa88
	ctx.lr = 0x8226D60C;
	sub_8221FA88(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8226D614:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82691650
	ctx.lr = 0x8226D620;
	sub_82691650(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,103(r3)
	PPC_STORE_U8(ctx.r3.u32 + 103, r11.u8);
loc_8226D628:
	// bl 0x8221fa88
	ctx.lr = 0x8226D62C;
	sub_8221FA88(ctx, base);
loc_8226D62C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8226D634"))) PPC_WEAK_FUNC(sub_8226D634);
PPC_FUNC_IMPL(__imp__sub_8226D634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226D638"))) PPC_WEAK_FUNC(sub_8226D638);
PPC_FUNC_IMPL(__imp__sub_8226D638) {
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
	ctx.lr = 0x8226D640;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-3252
	ctx.r10.s64 = r11.s64 + -3252;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8226d674
	if (cr6.eq) goto loc_8226D674;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-1920
	ctx.r4.s64 = ctx.r10.s64 + -1920;
	// b 0x8226d67c
	goto loc_8226D67C;
loc_8226D674:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-1932
	ctx.r4.s64 = ctx.r10.s64 + -1932;
loc_8226D67C:
	// bl 0x821ca540
	ctx.lr = 0x8226D680;
	sub_821CA540(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r29,2828(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// beq cr6,0x8226d6ac
	if (cr6.eq) goto loc_8226D6AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226D6A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// b 0x8226d6b4
	goto loc_8226D6B4;
loc_8226D6AC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,-3628(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -3628);
loc_8226D6B4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// addi r4,r10,-1940
	ctx.r4.s64 = ctx.r10.s64 + -1940;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c04b0
	ctx.lr = 0x8226D6D4;
	sub_821C04B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8226D6DC;
	sub_821C9A90(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,-3292
	ctx.r3.s64 = r11.s64 + -3292;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d6f8
	if (cr6.eq) goto loc_8226D6F8;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// bl 0x821c0750
	ctx.lr = 0x8226D6F8;
	sub_821C0750(ctx, base);
loc_8226D6F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226D700"))) PPC_WEAK_FUNC(sub_8226D700);
PPC_FUNC_IMPL(__imp__sub_8226D700) {
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
	// bl 0x824fa370
	ctx.lr = 0x8226D720;
	sub_824FA370(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d764
	if (cr6.eq) goto loc_8226D764;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa370
	ctx.lr = 0x8226D738;
	sub_824FA370(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d764
	if (cr6.eq) goto loc_8226D764;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822525b0
	ctx.lr = 0x8226D754;
	sub_822525B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226d768
	if (!cr6.eq) goto loc_8226D768;
loc_8226D764:
	// li r11,0
	r11.s64 = 0;
loc_8226D768:
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

__attribute__((alias("__imp__sub_8226D784"))) PPC_WEAK_FUNC(sub_8226D784);
PPC_FUNC_IMPL(__imp__sub_8226D784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226D788"))) PPC_WEAK_FUNC(sub_8226D788);
PPC_FUNC_IMPL(__imp__sub_8226D788) {
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
	ctx.lr = 0x8226D790;
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
	ctx.lr = 0x8226D7B4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8226D7C0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8226D7D0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226d7f4
	if (cr6.eq) goto loc_8226D7F4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226d700
	ctx.lr = 0x8226D7E4;
	sub_8226D700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226d7f8
	if (!cr6.eq) goto loc_8226D7F8;
loc_8226D7F4:
	// li r30,0
	r30.s64 = 0;
loc_8226D7F8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8226d830
	if (cr6.eq) goto loc_8226D830;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d828
	if (cr6.eq) goto loc_8226D828;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8226D814;
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
loc_8226D828:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8226D830:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226D83C"))) PPC_WEAK_FUNC(sub_8226D83C);
PPC_FUNC_IMPL(__imp__sub_8226D83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226D840"))) PPC_WEAK_FUNC(sub_8226D840);
PPC_FUNC_IMPL(__imp__sub_8226D840) {
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
	ctx.lr = 0x8226D848;
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
	ctx.lr = 0x8226D86C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x8226D878;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x8226D888;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226d8b0
	if (cr6.eq) goto loc_8226D8B0;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b338
	ctx.lr = 0x8226D8A0;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226d8b4
	if (!cr6.eq) goto loc_8226D8B4;
loc_8226D8B0:
	// li r30,0
	r30.s64 = 0;
loc_8226D8B4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8226d8ec
	if (cr6.eq) goto loc_8226D8EC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226d8e4
	if (cr6.eq) goto loc_8226D8E4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8226D8D0;
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
loc_8226D8E4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8226D8EC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226D8F8"))) PPC_WEAK_FUNC(sub_8226D8F8);
PPC_FUNC_IMPL(__imp__sub_8226D8F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x8226D900;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// cmplwi cr6,r5,27
	cr6.compare<uint32_t>(ctx.r5.u32, 27, xer);
	// bgt cr6,0x8226e230
	if (cr6.gt) goto loc_8226E230;
	// lis r12,-32217
	r12.s64 = -2111373312;
	// addi r12,r12,-9924
	r12.s64 = r12.s64 + -9924;
	// rlwinm r0,r5,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r5.u64) {
	case 0:
		goto loc_8226D9CC;
	case 1:
		goto loc_8226D9AC;
	case 2:
		goto loc_8226DA18;
	case 3:
		goto loc_8226DD40;
	case 4:
		goto loc_8226DD60;
	case 5:
		goto loc_8226DD7C;
	case 6:
		goto loc_8226E00C;
	case 7:
		goto loc_8226DC90;
	case 8:
		goto loc_8226DCAC;
	case 9:
		goto loc_8226DCC8;
	case 10:
		goto loc_8226E0A4;
	case 11:
		goto loc_8226E06C;
	case 12:
		goto loc_8226E034;
	case 13:
		goto loc_8226DBB8;
	case 14:
		goto loc_8226DC04;
	case 15:
		goto loc_8226DB9C;
	case 16:
		goto loc_8226DD9C;
	case 17:
		goto loc_8226DE70;
	case 18:
		goto loc_8226DF40;
	case 19:
		goto loc_8226DEB0;
	case 20:
		goto loc_8226DFCC;
	case 21:
		goto loc_8226DF8C;
	case 22:
		goto loc_8226E0C4;
	case 23:
		goto loc_8226DBAC;
	case 24:
		goto loc_8226DC80;
	case 25:
		goto loc_8226E12C;
	case 26:
		goto loc_8226E104;
	case 27:
		goto loc_8226E118;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-9780(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9780);
	// lwz r17,-9812(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9812);
	// lwz r17,-9704(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9704);
	// lwz r17,-8896(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8896);
	// lwz r17,-8864(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8864);
	// lwz r17,-8836(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8836);
	// lwz r17,-8180(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8180);
	// lwz r17,-9072(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9072);
	// lwz r17,-9044(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9044);
	// lwz r17,-9016(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9016);
	// lwz r17,-8028(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8028);
	// lwz r17,-8084(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8084);
	// lwz r17,-8140(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8140);
	// lwz r17,-9288(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9288);
	// lwz r17,-9212(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9212);
	// lwz r17,-9316(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9316);
	// lwz r17,-8804(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8804);
	// lwz r17,-8592(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8592);
	// lwz r17,-8384(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8384);
	// lwz r17,-8528(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8528);
	// lwz r17,-8244(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8244);
	// lwz r17,-8308(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8308);
	// lwz r17,-7996(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -7996);
	// lwz r17,-9300(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9300);
	// lwz r17,-9088(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9088);
	// lwz r17,-7892(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -7892);
	// lwz r17,-7932(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -7932);
	// lwz r17,-7912(r6)
	r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + -7912);
loc_8226D9AC:
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226D9C4;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226D9CC:
	// lwz r11,696(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 696);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8226db8c
	if (!cr6.gt) goto loc_8226DB8C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bgt cr6,0x8226db8c
	if (cr6.gt) goto loc_8226DB8C;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,700(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,696(r26)
	PPC_STORE_U32(r26.u32 + 696, r11.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DA00;
	sub_8268EE10(ctx, base);
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// bl 0x824f0c60
	ctx.lr = 0x8226DA08;
	sub_824F0C60(ctx, base);
	// lwz r3,40(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// bl 0x82298858
	ctx.lr = 0x8226DA10;
	sub_82298858(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DA18:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8226DA28;
	sub_822A3998(ctx, base);
	// lwz r29,52(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r11,8100(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8100);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226db64
	if (cr6.eq) goto loc_8226DB64;
	// bl 0x82387b90
	ctx.lr = 0x8226DA3C;
	sub_82387B90(ctx, base);
	// lwz r27,1344(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// bl 0x82387b90
	ctx.lr = 0x8226DA44;
	sub_82387B90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r27,8176
	r11.s64 = r27.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238ee58
	ctx.lr = 0x8226DA5C;
	sub_8238EE58(ctx, base);
	// lis r11,3
	r11.s64 = 196608;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r9,r11,57424
	ctx.r9.u64 = r11.u64 | 57424;
	// li r4,0
	ctx.r4.s64 = 0;
	// stbx r10,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, ctx.r10.u8);
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8226DA78;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226db64
	if (cr6.eq) goto loc_8226DB64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8226db64
	if (cr6.eq) goto loc_8226DB64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226db64
	if (cr6.eq) goto loc_8226DB64;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226db64
	if (cr6.eq) goto loc_8226DB64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f0,36(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// bne cr6,0x8226daf4
	if (!cr6.eq) goto loc_8226DAF4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8226DAF4:
	// lfs f0,4112(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4112);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// bne cr6,0x8226db10
	if (!cr6.eq) goto loc_8226DB10;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8226DB10:
	// lfs f0,4116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4116);
	f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// bne cr6,0x8226db2c
	if (!cr6.eq) goto loc_8226DB2C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8226DB2C:
	// lfs f0,4120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4120);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8226db48
	if (!cr6.eq) goto loc_8226DB48;
	// li r11,0
	r11.s64 = 0;
loc_8226DB48:
	// lfs f0,4124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4124);
	f0.f64 = double(temp.f32);
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82387b90
	ctx.lr = 0x8226DB58;
	sub_82387B90(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8238acd8
	ctx.lr = 0x8226DB64;
	sub_8238ACD8(ctx, base);
loc_8226DB64:
	// lwz r11,696(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 696);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8226e230
	if (!cr6.gt) goto loc_8226E230;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bgt cr6,0x8226e230
	if (cr6.gt) goto loc_8226E230;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x822811c8
	ctx.lr = 0x8226DB8C;
	sub_822811C8(ctx, base);
loc_8226DB8C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,696(r26)
	PPC_STORE_U32(r26.u32 + 696, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DB9C:
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x8228bed8
	ctx.lr = 0x8226DBA4;
	sub_8228BED8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DBAC:
	// bl 0x82130af8
	ctx.lr = 0x8226DBB0;
	sub_82130AF8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DBB8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-1896
	ctx.r5.s64 = ctx.r10.s64 + -1896;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82234d88
	ctx.lr = 0x8226DBE4;
	sub_82234D88(ctx, base);
	// lwz r9,700(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,36
	ctx.r4.s64 = 36;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DBFC;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DC04:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x82281cc8
	ctx.lr = 0x8226DC10;
	sub_82281CC8(ctx, base);
	// lwz r11,204(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226dc70
	if (cr6.eq) goto loc_8226DC70;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x8226DC2C;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// blt cr6,0x8226dc70
	if (cr6.lt) goto loc_8226DC70;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bgt cr6,0x8226dc70
	if (cr6.gt) goto loc_8226DC70;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3de0
	ctx.lr = 0x8226DC4C;
	sub_822A3DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226dc70
	if (cr6.eq) goto loc_8226DC70;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226dc70
	if (cr6.eq) goto loc_8226DC70;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226dc70
	if (cr6.eq) goto loc_8226DC70;
	// bl 0x8232bae8
	ctx.lr = 0x8226DC70;
	sub_8232BAE8(ctx, base);
loc_8226DC70:
	// li r11,0
	r11.s64 = 0;
	// stw r11,204(r30)
	PPC_STORE_U32(r30.u32 + 204, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DC80:
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x82282eb8
	ctx.lr = 0x8226DC88;
	sub_82282EB8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DC90:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226d238
	ctx.lr = 0x8226DCA4;
	sub_8226D238(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DCAC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226d310
	ctx.lr = 0x8226DCC0;
	sub_8226D310(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DCC8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203310
	ctx.lr = 0x8226DCD8;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822051a0
	ctx.lr = 0x8226DCF8;
	sub_822051A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8226DD04;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822051a0
	ctx.lr = 0x8226DD1C;
	sub_822051A0(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x8226DD20;
	sub_822A5948(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a5d20
	ctx.lr = 0x8226DD28;
	sub_822A5D20(ctx, base);
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82289438
	ctx.lr = 0x8226DD38;
	sub_82289438(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DD40:
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,36
	ctx.r4.s64 = 36;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DD58;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DD60:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x82283a20
	ctx.lr = 0x8226DD74;
	sub_82283A20(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DD7C:
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DD94;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DD9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DDA4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DDB4;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,17268
	r30.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8226ddf0
	if (cr6.eq) goto loc_8226DDF0;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8226de0c
	if (!cr6.gt) goto loc_8226DE0C;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8226de00
	goto loc_8226DE00;
loc_8226DDF0:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8226de0c
	if (!cr6.gt) goto loc_8226DE0C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8226DE00:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226de10
	if (!cr6.eq) goto loc_8226DE10;
loc_8226DE0C:
	// li r11,0
	r11.s64 = 0;
loc_8226DE10:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DE24;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DE38;
	sub_82270170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8226DE48;
	sub_822A3998(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822a5d20
	ctx.lr = 0x8226DE50;
	sub_822A5D20(ctx, base);
	// lwz r10,700(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DE68;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DE70:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DE78;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DE88;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DEA8;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DEB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DEB8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DEC8;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DEE8;
	sub_8268EE10(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226DEF0;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DF04;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DF14;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481598
	ctx.lr = 0x8226DF20;
	sub_82481598(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226c5b0
	ctx.lr = 0x8226DF38;
	sub_8226C5B0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DF40:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DF48;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DF58;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226df8c
	if (!cr6.eq) goto loc_8226DF8C;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x82275e60
	ctx.lr = 0x8226DF6C;
	sub_82275E60(ctx, base);
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DF84;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DF8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DF94;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DFA4;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226DFC4;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226DFCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226DFD4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226DFE4;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226E004;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E00C:
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x82281110
	ctx.lr = 0x8226E014;
	sub_82281110(ctx, base);
	// lwz r3,8(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// bl 0x82294c50
	ctx.lr = 0x8226E01C;
	sub_82294C50(ctx, base);
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// bl 0x824f0c60
	ctx.lr = 0x8226E024;
	sub_824F0C60(ctx, base);
	// lwz r3,40(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// bl 0x82298858
	ctx.lr = 0x8226E02C;
	sub_82298858(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E034:
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,29
	ctx.r4.s64 = 29;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226E04C;
	sub_8268EE10(ctx, base);
	// lwz r10,700(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,33
	ctx.r4.s64 = 33;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226E064;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E06C:
	// lwz r11,700(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,29
	ctx.r4.s64 = 29;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226E084;
	sub_8268EE10(ctx, base);
	// lwz r10,700(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8226E09C;
	sub_8268EE10(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E0A4:
	// lwz r11,696(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 696);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226c120
	ctx.lr = 0x8226E0BC;
	sub_8226C120(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E0C4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3de0
	ctx.lr = 0x8226E0D4;
	sub_822A3DE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8226E0EC;
	sub_822B62A0(ctx, base);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r9.u32);
	// stb r3,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E104:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226c5b0
	ctx.lr = 0x8226E110;
	sub_8226C5B0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E118:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8226c5b0
	ctx.lr = 0x8226E124;
	sub_8226C5B0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8226E12C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// lwz r28,4(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r29,r28,144
	r29.s64 = r28.s64 + 144;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481578
	ctx.lr = 0x8226E154;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226e230
	if (cr6.eq) goto loc_8226E230;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226e230
	if (!cr6.eq) goto loc_8226E230;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x8226E174;
	sub_824E6310(ctx, base);
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x8226E180;
	sub_82130000(ctx, base);
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// bl 0x824f97c0
	ctx.lr = 0x8226E188;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82482560
	ctx.lr = 0x8226E198;
	sub_82482560(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226E1A0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226E1B0;
	sub_82270170(ctx, base);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// subf r10,r30,r3
	ctx.r10.s64 = ctx.r3.s64 - r30.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lbz r8,92(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8226e1f8
	if (cr6.eq) goto loc_8226E1F8;
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226e1ec
	if (cr6.eq) goto loc_8226E1EC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8226e1f4
	goto loc_8226E1F4;
loc_8226E1EC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
loc_8226E1F4:
	// bl 0x82294cb0
	ctx.lr = 0x8226E1F8;
	sub_82294CB0(ctx, base);
loc_8226E1F8:
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lbz r11,2660(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2660);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226e224
	if (cr6.eq) goto loc_8226E224;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226e220
	if (!cr6.eq) goto loc_8226E220;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
loc_8226E220:
	// bl 0x824f0de8
	ctx.lr = 0x8226E224;
	sub_824F0DE8(ctx, base);
loc_8226E224:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,700(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 700);
	// bl 0x8227e8c8
	ctx.lr = 0x8226E230;
	sub_8227E8C8(ctx, base);
loc_8226E230:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8226E238"))) PPC_WEAK_FUNC(sub_8226E238);
PPC_FUNC_IMPL(__imp__sub_8226E238) {
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
	// addi r10,r11,-1868
	ctx.r10.s64 = r11.s64 + -1868;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e27c
	if (cr6.eq) goto loc_8226E27C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x8226E274;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8226E27C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226e294
	if (cr6.eq) goto loc_8226E294;
	// bl 0x82130588
	ctx.lr = 0x8226E290;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226E294:
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

__attribute__((alias("__imp__sub_8226E2AC"))) PPC_WEAK_FUNC(sub_8226E2AC);
PPC_FUNC_IMPL(__imp__sub_8226E2AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E2B0"))) PPC_WEAK_FUNC(sub_8226E2B0);
PPC_FUNC_IMPL(__imp__sub_8226E2B0) {
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
	// addi r10,r11,-1860
	ctx.r10.s64 = r11.s64 + -1860;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e2f4
	if (cr6.eq) goto loc_8226E2F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x8226E2EC;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8226E2F4:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226e30c
	if (cr6.eq) goto loc_8226E30C;
	// bl 0x82130588
	ctx.lr = 0x8226E308;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226E30C:
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

__attribute__((alias("__imp__sub_8226E324"))) PPC_WEAK_FUNC(sub_8226E324);
PPC_FUNC_IMPL(__imp__sub_8226E324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E328"))) PPC_WEAK_FUNC(sub_8226E328);
PPC_FUNC_IMPL(__imp__sub_8226E328) {
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
	ctx.lr = 0x8226E330;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16248
	ctx.r10.s64 = r11.s64 + 16248;
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
	// bl 0x8226cfb0
	ctx.lr = 0x8226E364;
	sub_8226CFB0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226e39c
	if (cr6.eq) goto loc_8226E39C;
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
	ctx.lr = 0x8226E38C;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226e3a0
	if (!cr6.eq) goto loc_8226E3A0;
loc_8226E39C:
	// li r11,0
	r11.s64 = 0;
loc_8226E3A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226E3AC"))) PPC_WEAK_FUNC(sub_8226E3AC);
PPC_FUNC_IMPL(__imp__sub_8226E3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E3B0"))) PPC_WEAK_FUNC(sub_8226E3B0);
PPC_FUNC_IMPL(__imp__sub_8226E3B0) {
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
	ctx.lr = 0x8226E3B8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16792
	ctx.r10.s64 = r11.s64 + 16792;
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
	ctx.lr = 0x8226E3EC;
	sub_82299E18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226e424
	if (cr6.eq) goto loc_8226E424;
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
	ctx.lr = 0x8226E414;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226e428
	if (!cr6.eq) goto loc_8226E428;
loc_8226E424:
	// li r11,0
	r11.s64 = 0;
loc_8226E428:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226E434"))) PPC_WEAK_FUNC(sub_8226E434);
PPC_FUNC_IMPL(__imp__sub_8226E434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E438"))) PPC_WEAK_FUNC(sub_8226E438);
PPC_FUNC_IMPL(__imp__sub_8226E438) {
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
	ctx.lr = 0x8226E440;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r10,r11,-1852
	ctx.r10.s64 = r11.s64 + -1852;
	// addi r26,r30,728
	r26.s64 = r30.s64 + 728;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r11,4292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// addi r3,r11,28896
	ctx.r3.s64 = r11.s64 + 28896;
	// bl 0x82270908
	ctx.lr = 0x8226E470;
	sub_82270908(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// addi r25,r30,704
	r25.s64 = r30.s64 + 704;
	// stw r28,748(r30)
	PPC_STORE_U32(r30.u32 + 748, r28.u32);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r3,25904
	ctx.r3.s64 = ctx.r3.s64 + 25904;
	// bl 0x82270908
	ctx.lr = 0x8226E490;
	sub_82270908(ctx, base);
	// stw r28,724(r30)
	PPC_STORE_U32(r30.u32 + 724, r28.u32);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e4b4
	if (cr6.eq) goto loc_8226E4B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226E4B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8226E4B4:
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r28,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r28.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226e4d4
	if (cr6.eq) goto loc_8226E4D4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0b98
	ctx.lr = 0x8226E4CC;
	sub_824F0B98(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8226E4D4;
	sub_82130588(ctx, base);
loc_8226E4D4:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e4f8
	if (cr6.eq) goto loc_8226E4F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226E4F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8226E4F8:
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8226E504;
	sub_82130588(ctx, base);
	// stw r28,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r28.u32);
	// lwz r29,700(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 700);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226e524
	if (cr6.eq) goto loc_8226E524;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82283120
	ctx.lr = 0x8226E51C;
	sub_82283120(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8226E524;
	sub_82130588(ctx, base);
loc_8226E524:
	// stw r28,700(r30)
	PPC_STORE_U32(r30.u32 + 700, r28.u32);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x8226E530;
	sub_82130588(ctx, base);
	// stw r28,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r28.u32);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x8226E53C;
	sub_82130588(ctx, base);
	// stw r28,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r28.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r10,-3556
	ctx.r4.s64 = ctx.r10.s64 + -3556;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f8aa8
	ctx.lr = 0x8226E554;
	sub_824F8AA8(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r8,-3040
	ctx.r5.s64 = ctx.r8.s64 + -3040;
	// lwz r9,4296(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// bl 0x824eba00
	ctx.lr = 0x8226E570;
	sub_824EBA00(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r7,-3348
	ctx.r5.s64 = ctx.r7.s64 + -3348;
	// lwz r6,4296(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	// bl 0x824eba00
	ctx.lr = 0x8226E58C;
	sub_824EBA00(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r5,-3404
	ctx.r5.s64 = ctx.r5.s64 + -3404;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// bl 0x824eba00
	ctx.lr = 0x8226E5A8;
	sub_824EBA00(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,11
	ctx.r4.s64 = 11;
	// addi r5,r10,-3096
	ctx.r5.s64 = ctx.r10.s64 + -3096;
	// lwz r9,4296(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// bl 0x824eba00
	ctx.lr = 0x8226E5C4;
	sub_824EBA00(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r4,14
	ctx.r4.s64 = 14;
	// addi r5,r8,-3232
	ctx.r5.s64 = ctx.r8.s64 + -3232;
	// lwz r7,4296(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// bl 0x824eba00
	ctx.lr = 0x8226E5E0;
	sub_824EBA00(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r28
	r29.u64 = r28.u64;
	// addi r27,r11,-3500
	r27.s64 = r11.s64 + -3500;
loc_8226E5EC:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8226e62c
	if (cr6.eq) goto loc_8226E62C;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8226e62c
	if (cr6.eq) goto loc_8226E62C;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8226e62c
	if (cr6.eq) goto loc_8226E62C;
	// cmpwi cr6,r29,11
	cr6.compare<int32_t>(r29.s32, 11, xer);
	// beq cr6,0x8226e62c
	if (cr6.eq) goto loc_8226E62C;
	// cmpwi cr6,r29,14
	cr6.compare<int32_t>(r29.s32, 14, xer);
	// beq cr6,0x8226e62c
	if (cr6.eq) goto loc_8226E62C;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824eba00
	ctx.lr = 0x8226E62C;
	sub_824EBA00(ctx, base);
loc_8226E62C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,15
	cr6.compare<int32_t>(r29.s32, 15, xer);
	// blt cr6,0x8226e5ec
	if (cr6.lt) goto loc_8226E5EC;
	// lwz r29,-10240(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226e654
	if (cr6.eq) goto loc_8226E654;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272678
	ctx.lr = 0x8226E64C;
	sub_82272678(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8226E654;
	sub_82130588(ctx, base);
loc_8226E654:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// stw r11,-10240(r31)
	PPC_STORE_U32(r31.u32 + -10240, r11.u32);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// stw r10,-3624(r9)
	PPC_STORE_U32(ctx.r9.u32 + -3624, ctx.r10.u32);
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfc50
	ctx.lr = 0x8226E674;
	sub_821BFC50(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8226e6a4
	if (cr6.eq) goto loc_8226E6A4;
	// lwz r29,2828(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226e69c
	if (cr6.eq) goto loc_8226E69C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c0688
	ctx.lr = 0x8226E694;
	sub_821C0688(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8226E69C;
	sub_82130588(ctx, base);
loc_8226E69C:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_8226E6A4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,20(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// addi r10,r11,-1860
	ctx.r10.s64 = r11.s64 + -1860;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8226e6c8
	if (cr6.eq) goto loc_8226E6C8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82270908
	ctx.lr = 0x8226E6C4;
	sub_82270908(ctx, base);
	// stw r28,20(r26)
	PPC_STORE_U32(r26.u32 + 20, r28.u32);
loc_8226E6C8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,20(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// addi r10,r11,-1868
	ctx.r10.s64 = r11.s64 + -1868;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8226e6ec
	if (cr6.eq) goto loc_8226E6EC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82270908
	ctx.lr = 0x8226E6E8;
	sub_82270908(ctx, base);
	// stw r28,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r28.u32);
loc_8226E6EC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8226E6F4;
	sub_821D2028(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8226E6FC"))) PPC_WEAK_FUNC(sub_8226E6FC);
PPC_FUNC_IMPL(__imp__sub_8226E6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E700"))) PPC_WEAK_FUNC(sub_8226E700);
PPC_FUNC_IMPL(__imp__sub_8226E700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3628(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3628);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226E70C"))) PPC_WEAK_FUNC(sub_8226E70C);
PPC_FUNC_IMPL(__imp__sub_8226E70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E710"))) PPC_WEAK_FUNC(sub_8226E710);
PPC_FUNC_IMPL(__imp__sub_8226E710) {
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
	ctx.lr = 0x8226E718;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16152
	ctx.r10.s64 = r11.s64 + 16152;
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
	// bl 0x8226d788
	ctx.lr = 0x8226E74C;
	sub_8226D788(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226e784
	if (cr6.eq) goto loc_8226E784;
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
	ctx.lr = 0x8226E774;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226e788
	if (!cr6.eq) goto loc_8226E788;
loc_8226E784:
	// li r11,0
	r11.s64 = 0;
loc_8226E788:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226E794"))) PPC_WEAK_FUNC(sub_8226E794);
PPC_FUNC_IMPL(__imp__sub_8226E794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E798"))) PPC_WEAK_FUNC(sub_8226E798);
PPC_FUNC_IMPL(__imp__sub_8226E798) {
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
	ctx.lr = 0x8226E7A0;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,16504
	ctx.r10.s64 = r11.s64 + 16504;
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
	// bl 0x8226d840
	ctx.lr = 0x8226E7D4;
	sub_8226D840(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8226e80c
	if (cr6.eq) goto loc_8226E80C;
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
	ctx.lr = 0x8226E7FC;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8226e810
	if (!cr6.eq) goto loc_8226E810;
loc_8226E80C:
	// li r11,0
	r11.s64 = 0;
loc_8226E810:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226E81C"))) PPC_WEAK_FUNC(sub_8226E81C);
PPC_FUNC_IMPL(__imp__sub_8226E81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226E820"))) PPC_WEAK_FUNC(sub_8226E820);
PPC_FUNC_IMPL(__imp__sub_8226E820) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8226E828;
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-1852
	ctx.r10.s64 = r11.s64 + -1852;
	// li r3,48
	ctx.r3.s64 = 48;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x8226E84C;
	sub_82130528(ctx, base);
	// li r25,250
	r25.s64 = 250;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e8d8
	if (cr6.eq) goto loc_8226E8D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r25,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r25.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, r30.u8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, r30.u8);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, r30.u8);
	// li r6,187
	ctx.r6.s64 = 187;
	// lfs f0,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r5,500
	ctx.r5.s64 = 500;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lfs f12,-31384(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31384);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// lfs f10,-332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -332);
	ctx.f10.f64 = double(temp.f32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, r30.u8);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r30,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r30.u8);
	// stfs f12,16(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r30,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, r30.u8);
	// stfs f11,20(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r30,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, r30.u8);
	// stfs f10,44(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stw r4,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r4.u32);
	// b 0x8226e8dc
	goto loc_8226E8DC;
loc_8226E8D8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8226E8DC:
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8226E8E8;
	sub_82130528(ctx, base);
	// li r26,20
	r26.s64 = 20;
	// li r23,1000
	r23.s64 = 1000;
	// li r29,5000
	r29.s64 = 5000;
	// li r24,1
	r24.s64 = 1;
	// li r27,300
	r27.s64 = 300;
	// li r28,100
	r28.s64 = 100;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e930
	if (cr6.eq) goto loc_8226E930;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r23,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r23.u32);
	// stw r29,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r29.u32);
	// stb r24,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r24.u8);
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r29.u32);
	// stw r27,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r27.u32);
	// stw r28,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r28.u32);
	// b 0x8226e934
	goto loc_8226E934;
loc_8226E930:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8226E934:
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8226E940;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e970
	if (cr6.eq) goto loc_8226E970;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r23,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r23.u32);
	// stw r29,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r29.u32);
	// stb r24,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r24.u8);
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r29.u32);
	// stw r27,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r27.u32);
	// stw r28,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r28.u32);
	// b 0x8226e974
	goto loc_8226E974;
loc_8226E970:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8226E974:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x8226E980;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e994
	if (cr6.eq) goto loc_8226E994;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// b 0x8226e998
	goto loc_8226E998;
loc_8226E994:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8226E998:
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x8226E9A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226e9cc
	if (cr6.eq) goto loc_8226E9CC;
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// b 0x8226e9d0
	goto loc_8226E9D0;
loc_8226E9CC:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8226E9D0:
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82130528
	ctx.lr = 0x8226E9DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226ea5c
	if (cr6.eq) goto loc_8226EA5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f13,14184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14184);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f12,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f11,32668(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32668);
	ctx.f11.f64 = double(temp.f32);
	// li r11,8
	r11.s64 = 8;
	// lfs f0,30712(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lfs f10,11368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f9.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lfs f8,-2580(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -2580);
	ctx.f8.f64 = double(temp.f32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lfs f7,-1684(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1684);
	ctx.f7.f64 = double(temp.f32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
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
	// b 0x8226ea60
	goto loc_8226EA60;
loc_8226EA5C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8226EA60:
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8226EA6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226ea80
	if (cr6.eq) goto loc_8226EA80;
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x82298bb8
	ctx.lr = 0x8226EA7C;
	sub_82298BB8(ctx, base);
	// b 0x8226ea84
	goto loc_8226EA84;
loc_8226EA80:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8226EA84:
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6400
	ctx.lr = 0x8226EA94;
	sub_824E6400(ctx, base);
	// addi r3,r29,68
	ctx.r3.s64 = r29.s64 + 68;
	// bl 0x824e6310
	ctx.lr = 0x8226EA9C;
	sub_824E6310(ctx, base);
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// bl 0x824e1c10
	ctx.lr = 0x8226EAA4;
	sub_824E1C10(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,688(r31)
	PPC_STORE_U32(r31.u32 + 688, r30.u32);
	// addi r28,r31,704
	r28.s64 = r31.s64 + 704;
	// stw r30,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r30.u32);
	// addi r10,r11,-1868
	ctx.r10.s64 = r11.s64 + -1868;
	// stw r30,696(r31)
	PPC_STORE_U32(r31.u32 + 696, r30.u32);
	// addi r27,r28,12
	r27.s64 = r28.s64 + 12;
	// stw r30,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r30.u32);
	// stw r30,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r30.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r30,712(r31)
	PPC_STORE_U32(r31.u32 + 712, r30.u32);
	// stw r10,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x8226EAD8;
	sub_821B5A60(ctx, base);
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x821b5a60
	ctx.lr = 0x8226EAE0;
	sub_821B5A60(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r30,720(r31)
	PPC_STORE_U32(r31.u32 + 720, r30.u32);
	// addi r27,r31,728
	r27.s64 = r31.s64 + 728;
	// stw r30,716(r31)
	PPC_STORE_U32(r31.u32 + 716, r30.u32);
	// addi r8,r9,-1860
	ctx.r8.s64 = ctx.r9.s64 + -1860;
	// stw r30,724(r31)
	PPC_STORE_U32(r31.u32 + 724, r30.u32);
	// addi r26,r27,12
	r26.s64 = r27.s64 + 12;
	// stw r30,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r30.u32);
	// stw r30,736(r31)
	PPC_STORE_U32(r31.u32 + 736, r30.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r8,728(r31)
	PPC_STORE_U32(r31.u32 + 728, ctx.r8.u32);
	// bl 0x821b5a60
	ctx.lr = 0x8226EB10;
	sub_821B5A60(ctx, base);
	// addi r3,r26,4
	ctx.r3.s64 = r26.s64 + 4;
	// bl 0x821b5a60
	ctx.lr = 0x8226EB18;
	sub_821B5A60(ctx, base);
	// lis r26,-32125
	r26.s64 = -2105344000;
	// stw r30,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r30.u32);
	// stw r30,740(r31)
	PPC_STORE_U32(r31.u32 + 740, r30.u32);
	// stw r30,748(r31)
	PPC_STORE_U32(r31.u32 + 748, r30.u32);
	// stw r30,752(r31)
	PPC_STORE_U32(r31.u32 + 752, r30.u32);
	// stb r30,756(r31)
	PPC_STORE_U8(r31.u32 + 756, r30.u8);
	// stb r24,758(r31)
	PPC_STORE_U8(r31.u32 + 758, r24.u8);
	// lwz r11,2828(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226eb68
	if (!cr6.eq) goto loc_8226EB68;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8226EB48;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8226eb60
	if (cr6.eq) goto loc_8226EB60;
	// bl 0x821c0580
	ctx.lr = 0x8226EB58;
	sub_821C0580(ctx, base);
	// stw r25,2828(r26)
	PPC_STORE_U32(r26.u32 + 2828, r25.u32);
	// b 0x8226eb68
	goto loc_8226EB68;
loc_8226EB60:
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,2828(r26)
	PPC_STORE_U32(r26.u32 + 2828, r11.u32);
loc_8226EB68:
	// bl 0x821c4210
	ctx.lr = 0x8226EB6C;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,2828(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x8226EB90;
	sub_821C05E8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r3,68
	ctx.r3.s64 = 68;
	// stw r31,-3624(r9)
	PPC_STORE_U32(ctx.r9.u32 + -3624, r31.u32);
	// bl 0x82130528
	ctx.lr = 0x8226EBA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226ebb0
	if (cr6.eq) goto loc_8226EBB0;
	// bl 0x82283e80
	ctx.lr = 0x8226EBAC;
	sub_82283E80(ctx, base);
	// b 0x8226ebb4
	goto loc_8226EBB4;
loc_8226EBB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8226EBB4:
	// stw r3,700(r31)
	PPC_STORE_U32(r31.u32 + 700, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226d638
	ctx.lr = 0x8226EBC0;
	sub_8226D638(ctx, base);
	// stw r30,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r30.u32);
	// stb r30,64(r29)
	PPC_STORE_U8(r29.u32 + 64, r30.u8);
	// addi r3,r29,68
	ctx.r3.s64 = r29.s64 + 68;
	// bl 0x824e6310
	ctx.lr = 0x8226EBD0;
	sub_824E6310(ctx, base);
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// bl 0x824e0a58
	ctx.lr = 0x8226EBD8;
	sub_824E0A58(ctx, base);
	// addi r3,r29,640
	ctx.r3.s64 = r29.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ce080
	ctx.lr = 0x8226EBE4;
	sub_821CE080(ctx, base);
	// lbz r10,624(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 624);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r30,644(r29)
	PPC_STORE_U32(r29.u32 + 644, r30.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,624(r1)
	PPC_STORE_U8(ctx.r1.u32 + 624, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x8226EBFC;
	sub_8226B078(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r8,-3576
	ctx.r3.s64 = ctx.r8.s64 + -3576;
	// bl 0x821c0750
	ctx.lr = 0x8226EC0C;
	sub_821C0750(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8226ec1c
	if (!cr6.eq) goto loc_8226EC1C;
	// stw r23,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r23.u32);
loc_8226EC1C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-3176
	ctx.r10.s64 = r11.s64 + -3176;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ec38
	if (cr6.eq) goto loc_8226EC38;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stb r24,29(r11)
	PPC_STORE_U8(r11.u32 + 29, r24.u8);
loc_8226EC38:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x8226EC40;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226ec64
	if (cr6.eq) goto loc_8226EC64;
	// lis r10,21588
	ctx.r10.s64 = 1414791168;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// ori r9,r10,2026
	ctx.r9.u64 = ctx.r10.u64 | 2026;
	// addi r25,r11,-3620
	r25.s64 = r11.s64 + -3620;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r3,-3620(r11)
	PPC_STORE_U32(r11.u32 + -3620, ctx.r3.u32);
	// b 0x8226ec74
	goto loc_8226EC74;
loc_8226EC64:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r25,r10,-3620
	r25.s64 = ctx.r10.s64 + -3620;
	// stw r11,-3620(r10)
	PPC_STORE_U32(ctx.r10.u32 + -3620, r11.u32);
loc_8226EC74:
	// lis r3,5
	ctx.r3.s64 = 327680;
	// ori r3,r3,25936
	ctx.r3.u64 = ctx.r3.u64 | 25936;
	// bl 0x82130528
	ctx.lr = 0x8226EC80;
	sub_82130528(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8226ec94
	if (cr6.eq) goto loc_8226EC94;
	// bl 0x822720d8
	ctx.lr = 0x8226EC90;
	sub_822720D8(ctx, base);
	// b 0x8226ec98
	goto loc_8226EC98;
loc_8226EC94:
	// mr r26,r30
	r26.u64 = r30.u64;
loc_8226EC98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r29,r11,-10240
	r29.s64 = r11.s64 + -10240;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r24,r9,15400
	r24.s64 = ctx.r9.s64 + 15400;
	// stw r26,-10240(r11)
	PPC_STORE_U32(r11.u32 + -10240, r26.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r23,r7,-4576
	r23.s64 = ctx.r7.s64 + -4576;
	// addi r8,r11,-2532
	ctx.r8.s64 = r11.s64 + -2532;
	// addi r22,r1,112
	r22.s64 = ctx.r1.s64 + 112;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// addi r21,r1,100
	r21.s64 = ctx.r1.s64 + 100;
	// clrlwi r20,r10,16
	r20.u64 = ctx.r10.u32 & 0xFFFF;
	// bl 0x823878d0
	ctx.lr = 0x8226ECD4;
	sub_823878D0(ctx, base);
	// li r6,22
	ctx.r6.s64 = 22;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// bl 0x82270e78
	ctx.lr = 0x8226ED00;
	sub_82270E78(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r5,4296(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	// bl 0x824ea8d0
	ctx.lr = 0x8226ED14;
	sub_824EA8D0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// bl 0x824ea880
	ctx.lr = 0x8226ED2C;
	sub_824EA880(ctx, base);
	// lis r11,-32217
	r11.s64 = -2111373312;
	// stw r30,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-15360
	ctx.r10.s64 = r11.s64 + -15360;
	// stw r10,736(r31)
	PPC_STORE_U32(r31.u32 + 736, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8226ED44;
	sub_82130000(ctx, base);
	// stw r3,732(r31)
	PPC_STORE_U32(r31.u32 + 732, ctx.r3.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,4292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// addi r26,r11,28896
	r26.s64 = r11.s64 + 28896;
	// addi r3,r26,4
	ctx.r3.s64 = r26.s64 + 4;
	// bl 0x82207db8
	ctx.lr = 0x8226ED60;
	sub_82207DB8(ctx, base);
	// lis r9,-32217
	ctx.r9.s64 = -2111373312;
	// stw r26,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-9992
	ctx.r8.s64 = ctx.r9.s64 + -9992;
	// stw r30,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r30.u32);
	// stw r8,712(r31)
	PPC_STORE_U32(r31.u32 + 712, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x8226ED7C;
	sub_82130000(ctx, base);
	// stw r3,708(r31)
	PPC_STORE_U32(r31.u32 + 708, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addis r27,r11,5
	r27.s64 = r11.s64 + 327680;
	// addi r27,r27,25904
	r27.s64 = r27.s64 + 25904;
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x82207db8
	ctx.lr = 0x8226ED98;
	sub_82207DB8(ctx, base);
	// stw r27,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r27.u32);
	// li r3,2664
	ctx.r3.s64 = 2664;
	// bl 0x82130528
	ctx.lr = 0x8226EDA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226edb4
	if (cr6.eq) goto loc_8226EDB4;
	// bl 0x824f1910
	ctx.lr = 0x8226EDB0;
	sub_824F1910(ctx, base);
	// b 0x8226edb8
	goto loc_8226EDB8;
loc_8226EDB4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8226EDB8:
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x8226EDC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226edd4
	if (cr6.eq) goto loc_8226EDD4;
	// bl 0x82294b60
	ctx.lr = 0x8226EDD0;
	sub_82294B60(ctx, base);
	// b 0x8226edd8
	goto loc_8226EDD8;
loc_8226EDD4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8226EDD8:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// bl 0x82294c50
	ctx.lr = 0x8226EDE0;
	sub_82294C50(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-3156
	ctx.r10.s64 = r11.s64 + -3156;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,757(r31)
	PPC_STORE_U8(r31.u32 + 757, ctx.r7.u8);
	// bl 0x82291508
	ctx.lr = 0x8226EE00;
	sub_82291508(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r28,4304(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295190
	ctx.lr = 0x8226EE10;
	sub_82295190(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f88f8
	ctx.lr = 0x8226EE1C;
	sub_824F88F8(ctx, base);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x82294fd8
	ctx.lr = 0x8226EE2C;
	sub_82294FD8(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82294fd8
	ctx.lr = 0x8226EE3C;
	sub_82294FD8(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82295050
	ctx.lr = 0x8226EE4C;
	sub_82295050(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// addi r5,r6,32220
	ctx.r5.s64 = ctx.r6.s64 + 32220;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226ee68
	if (!cr6.eq) goto loc_8226EE68;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x824fa640
	ctx.lr = 0x8226EE68;
	sub_824FA640(ctx, base);
loc_8226EE68:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r10,-3556
	ctx.r4.s64 = ctx.r10.s64 + -3556;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f90e0
	ctx.lr = 0x8226EE7C;
	sub_824F90E0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r9,-3040
	ctx.r5.s64 = ctx.r9.s64 + -3040;
	// lwz r8,4296(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// bl 0x824ec0d0
	ctx.lr = 0x8226EE98;
	sub_824EC0D0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r7,-3348
	ctx.r5.s64 = ctx.r7.s64 + -3348;
	// lwz r6,4296(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	// bl 0x824ec0d0
	ctx.lr = 0x8226EEB4;
	sub_824EC0D0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r5,-3404
	ctx.r5.s64 = ctx.r5.s64 + -3404;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// bl 0x824ec0d0
	ctx.lr = 0x8226EED0;
	sub_824EC0D0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,11
	ctx.r4.s64 = 11;
	// addi r5,r10,-3096
	ctx.r5.s64 = ctx.r10.s64 + -3096;
	// lwz r9,4296(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// bl 0x824ec0d0
	ctx.lr = 0x8226EEEC;
	sub_824EC0D0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r4,14
	ctx.r4.s64 = 14;
	// addi r5,r8,-3232
	ctx.r5.s64 = ctx.r8.s64 + -3232;
	// lwz r7,4296(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// bl 0x824ec0d0
	ctx.lr = 0x8226EF08;
	sub_824EC0D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r28,r11,-3500
	r28.s64 = r11.s64 + -3500;
loc_8226EF10:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8226ef50
	if (cr6.eq) goto loc_8226EF50;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x8226ef50
	if (cr6.eq) goto loc_8226EF50;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x8226ef50
	if (cr6.eq) goto loc_8226EF50;
	// cmpwi cr6,r30,11
	cr6.compare<int32_t>(r30.s32, 11, xer);
	// beq cr6,0x8226ef50
	if (cr6.eq) goto loc_8226EF50;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// beq cr6,0x8226ef50
	if (cr6.eq) goto loc_8226EF50;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824ec0d0
	ctx.lr = 0x8226EF50;
	sub_824EC0D0(ctx, base);
loc_8226EF50:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// blt cr6,0x8226ef10
	if (cr6.lt) goto loc_8226EF10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8226EF68"))) PPC_WEAK_FUNC(sub_8226EF68);
PPC_FUNC_IMPL(__imp__sub_8226EF68) {
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
	// bl 0x8226e438
	ctx.lr = 0x8226EF88;
	sub_8226E438(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226efa0
	if (cr6.eq) goto loc_8226EFA0;
	// bl 0x82130588
	ctx.lr = 0x8226EF9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8226EFA0:
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

__attribute__((alias("__imp__sub_8226EFB8"))) PPC_WEAK_FUNC(sub_8226EFB8);
PPC_FUNC_IMPL(__imp__sub_8226EFB8) {
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
	// li r3,760
	ctx.r3.s64 = 760;
	// bl 0x82130528
	ctx.lr = 0x8226EFCC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226efec
	if (cr6.eq) goto loc_8226EFEC;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8226e820
	ctx.lr = 0x8226EFDC;
	sub_8226E820(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8226EFEC:
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

__attribute__((alias("__imp__sub_8226F000"))) PPC_WEAK_FUNC(sub_8226F000);
PPC_FUNC_IMPL(__imp__sub_8226F000) {
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
	ctx.lr = 0x8226F008;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8226F024:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226F03C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f070
	if (cr6.eq) goto loc_8226F070;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8226f068
	if (cr6.eq) goto loc_8226F068;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8226f070
	if (!cr6.eq) goto loc_8226F070;
loc_8226F068:
	// li r11,1
	r11.s64 = 1;
	// b 0x8226f074
	goto loc_8226F074;
loc_8226F070:
	// li r11,0
	r11.s64 = 0;
loc_8226F074:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f0f8
	if (cr6.eq) goto loc_8226F0F8;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8226f0e8
	if (cr6.lt) goto loc_8226F0E8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8226F0A8;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f0cc
	if (!cr6.eq) goto loc_8226F0CC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8226F0C0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f0e8
	if (cr6.eq) goto loc_8226F0E8;
loc_8226F0CC:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226e328
	ctx.lr = 0x8226F0E4;
	sub_8226E328(ctx, base);
	// b 0x8226f0ec
	goto loc_8226F0EC;
loc_8226F0E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226F0EC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8226F0F8:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8226f024
	if (cr6.lt) goto loc_8226F024;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8226F110"))) PPC_WEAK_FUNC(sub_8226F110);
PPC_FUNC_IMPL(__imp__sub_8226F110) {
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
	ctx.lr = 0x8226F118;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8226F134:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226F14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f180
	if (cr6.eq) goto loc_8226F180;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8226f178
	if (cr6.eq) goto loc_8226F178;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8226f180
	if (!cr6.eq) goto loc_8226F180;
loc_8226F178:
	// li r11,1
	r11.s64 = 1;
	// b 0x8226f184
	goto loc_8226F184;
loc_8226F180:
	// li r11,0
	r11.s64 = 0;
loc_8226F184:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f208
	if (cr6.eq) goto loc_8226F208;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8226f1f8
	if (cr6.lt) goto loc_8226F1F8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8226F1B8;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f1dc
	if (!cr6.eq) goto loc_8226F1DC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8226F1D0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f1f8
	if (cr6.eq) goto loc_8226F1F8;
loc_8226F1DC:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226e3b0
	ctx.lr = 0x8226F1F4;
	sub_8226E3B0(ctx, base);
	// b 0x8226f1fc
	goto loc_8226F1FC;
loc_8226F1F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226F1FC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8226F208:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8226f134
	if (cr6.lt) goto loc_8226F134;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8226F220"))) PPC_WEAK_FUNC(sub_8226F220);
PPC_FUNC_IMPL(__imp__sub_8226F220) {
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
	ctx.lr = 0x8226F228;
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
	// blt cr6,0x8226f294
	if (cr6.lt) goto loc_8226F294;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8226F250;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f274
	if (!cr6.eq) goto loc_8226F274;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8226F268;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f294
	if (cr6.eq) goto loc_8226F294;
loc_8226F274:
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
	// bl 0x8226e710
	ctx.lr = 0x8226F28C;
	sub_8226E710(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8226F294:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226F2A0"))) PPC_WEAK_FUNC(sub_8226F2A0);
PPC_FUNC_IMPL(__imp__sub_8226F2A0) {
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
	ctx.lr = 0x8226F2A8;
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
	// blt cr6,0x8226f314
	if (cr6.lt) goto loc_8226F314;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8226F2D0;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f2f4
	if (!cr6.eq) goto loc_8226F2F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8226F2E8;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f314
	if (cr6.eq) goto loc_8226F314;
loc_8226F2F4:
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
	// bl 0x8226e798
	ctx.lr = 0x8226F30C;
	sub_8226E798(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8226F314:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226F320"))) PPC_WEAK_FUNC(sub_8226F320);
PPC_FUNC_IMPL(__imp__sub_8226F320) {
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
	ctx.lr = 0x8226F328;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,-3628
	r31.s64 = r11.s64 + -3628;
	// lwz r11,-3628(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f528
	if (!cr6.eq) goto loc_8226F528;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8226F348;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f35c
	if (cr6.eq) goto loc_8226F35C;
	// bl 0x821d5408
	ctx.lr = 0x8226F358;
	sub_821D5408(ctx, base);
	// b 0x8226f360
	goto loc_8226F360;
loc_8226F35C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8226F360:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r7,r10,-1844
	ctx.r7.s64 = ctx.r10.s64 + -1844;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,760
	ctx.r5.s64 = 760;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32217
	ctx.r8.s64 = -2111373312;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r8,-4168
	ctx.r4.s64 = ctx.r8.s64 + -4168;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r10,-11844
	r30.s64 = ctx.r10.s64 + -11844;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// std r10,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r10.u64);
	// addi r8,r3,-11868
	ctx.r8.s64 = ctx.r3.s64 + -11868;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r11,16824(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// bne cr6,0x8226f3ec
	if (!cr6.eq) goto loc_8226F3EC;
	// bl 0x82294938
	ctx.lr = 0x8226F3E8;
	sub_82294938(ctx, base);
	// lwz r11,16824(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16824);
loc_8226F3EC:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r29,r10,-11808
	r29.s64 = ctx.r10.s64 + -11808;
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r11,16828(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16828);
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f418
	if (!cr6.eq) goto loc_8226F418;
	// bl 0x82294368
	ctx.lr = 0x8226F414;
	sub_82294368(ctx, base);
	// lwz r11,16828(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16828);
loc_8226F418:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,-11772
	r28.s64 = ctx.r10.s64 + -11772;
	// li r10,24
	ctx.r10.s64 = 24;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8226f43c
	if (!cr6.eq) goto loc_8226F43C;
	// bl 0x82294368
	ctx.lr = 0x8226F438;
	sub_82294368(ctx, base);
	// lwz r11,16828(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16828);
loc_8226F43C:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r10,-11736
	r30.s64 = ctx.r10.s64 + -11736;
	// li r10,28
	ctx.r10.s64 = 28;
	// lwz r11,16832(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16832);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f468
	if (!cr6.eq) goto loc_8226F468;
	// bl 0x82294500
	ctx.lr = 0x8226F464;
	sub_82294500(ctx, base);
	// lwz r11,16832(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16832);
loc_8226F468:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r29,r10,-11700
	r29.s64 = ctx.r10.s64 + -11700;
	// li r10,32
	ctx.r10.s64 = 32;
	// lwz r11,16836(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16836);
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f494
	if (!cr6.eq) goto loc_8226F494;
	// bl 0x82294628
	ctx.lr = 0x8226F490;
	sub_82294628(ctx, base);
	// lwz r11,16836(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16836);
loc_8226F494:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r30,r10,-11664
	r30.s64 = ctx.r10.s64 + -11664;
	// li r10,36
	ctx.r10.s64 = 36;
	// lwz r11,16840(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16840);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f4c0
	if (!cr6.eq) goto loc_8226F4C0;
	// bl 0x82294770
	ctx.lr = 0x8226F4BC;
	sub_82294770(ctx, base);
	// lwz r11,16840(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16840);
loc_8226F4C0:
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8226F4D4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8226F4E4;
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
	ctx.lr = 0x8226F500;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-11628
	ctx.r4.s64 = ctx.r8.s64 + -11628;
	// bl 0x821d4b00
	ctx.lr = 0x8226F510;
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
	ctx.lr = 0x8226F528;
	sub_821C0548(ctx, base);
loc_8226F528:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226F530"))) PPC_WEAK_FUNC(sub_8226F530);
PPC_FUNC_IMPL(__imp__sub_8226F530) {
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
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,760
	ctx.r3.s64 = 760;
	// stb r11,57(r9)
	PPC_STORE_U8(ctx.r9.u32 + 57, r11.u8);
	// bl 0x82130528
	ctx.lr = 0x8226F55C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f570
	if (cr6.eq) goto loc_8226F570;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226e820
	ctx.lr = 0x8226F56C;
	sub_8226E820(ctx, base);
	// b 0x8226f574
	goto loc_8226F574;
loc_8226F570:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226F574:
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8226F594"))) PPC_WEAK_FUNC(sub_8226F594);
PPC_FUNC_IMPL(__imp__sub_8226F594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226F598"))) PPC_WEAK_FUNC(sub_8226F598);
PPC_FUNC_IMPL(__imp__sub_8226F598) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8226f000
	ctx.lr = 0x8226F5C8;
	sub_8226F000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226F5D8"))) PPC_WEAK_FUNC(sub_8226F5D8);
PPC_FUNC_IMPL(__imp__sub_8226F5D8) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8226f110
	ctx.lr = 0x8226F608;
	sub_8226F110(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8226F618"))) PPC_WEAK_FUNC(sub_8226F618);
PPC_FUNC_IMPL(__imp__sub_8226F618) {
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
	ctx.lr = 0x8226F620;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226F648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f680
	if (cr6.eq) goto loc_8226F680;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8226f220
	ctx.lr = 0x8226F678;
	sub_8226F220(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8226F680:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226F68C"))) PPC_WEAK_FUNC(sub_8226F68C);
PPC_FUNC_IMPL(__imp__sub_8226F68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226F690"))) PPC_WEAK_FUNC(sub_8226F690);
PPC_FUNC_IMPL(__imp__sub_8226F690) {
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
	ctx.lr = 0x8226F698;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r25,1
	r25.s64 = 1;
	// li r28,0
	r28.s64 = 0;
loc_8226F6B4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226F6CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f700
	if (cr6.eq) goto loc_8226F700;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8226f6f8
	if (cr6.eq) goto loc_8226F6F8;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8226f700
	if (!cr6.eq) goto loc_8226F700;
loc_8226F6F8:
	// li r11,1
	r11.s64 = 1;
	// b 0x8226f704
	goto loc_8226F704;
loc_8226F700:
	// li r11,0
	r11.s64 = 0;
loc_8226F704:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f788
	if (cr6.eq) goto loc_8226F788;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8226f778
	if (cr6.lt) goto loc_8226F778;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8226F738;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226f75c
	if (!cr6.eq) goto loc_8226F75C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8226F750;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f778
	if (cr6.eq) goto loc_8226F778;
loc_8226F75C:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226e710
	ctx.lr = 0x8226F774;
	sub_8226E710(ctx, base);
	// b 0x8226f77c
	goto loc_8226F77C;
loc_8226F778:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8226F77C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8226F788:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8226f6b4
	if (cr6.lt) goto loc_8226F6B4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8226F7A0"))) PPC_WEAK_FUNC(sub_8226F7A0);
PPC_FUNC_IMPL(__imp__sub_8226F7A0) {
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
	ctx.lr = 0x8226F7A8;
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
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8226F7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f804
	if (cr6.eq) goto loc_8226F804;
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
	// beq cr6,0x8226f7fc
	if (cr6.eq) goto loc_8226F7FC;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8226f804
	if (!cr6.eq) goto loc_8226F804;
loc_8226F7FC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8226f808
	goto loc_8226F808;
loc_8226F804:
	// li r11,0
	r11.s64 = 0;
loc_8226F808:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f844
	if (cr6.eq) goto loc_8226F844;
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
	// bl 0x8226f2a0
	ctx.lr = 0x8226F83C;
	sub_8226F2A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8226F844:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226F850"))) PPC_WEAK_FUNC(sub_8226F850);
PPC_FUNC_IMPL(__imp__sub_8226F850) {
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
	ctx.lr = 0x8226F858;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8226F86C;
	sub_82388580(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226F87C;
	sub_82270170(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x82296dd8
	ctx.lr = 0x8226F888;
	sub_82296DD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226F894;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226F8A4;
	sub_82270170(ctx, base);
	// addi r4,r27,8
	ctx.r4.s64 = r27.s64 + 8;
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x82296dd8
	ctx.lr = 0x8226F8B0;
	sub_82296DD8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226f9dc
	if (cr6.eq) goto loc_8226F9DC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8226f9dc
	if (cr6.eq) goto loc_8226F9DC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8226F8D0;
	sub_822051A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822051a0
	ctx.lr = 0x8226F8E0;
	sub_822051A0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r29,17268(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8226F8F8;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f9dc
	if (cr6.eq) goto loc_8226F9DC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8226F910;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f9dc
	if (cr6.eq) goto loc_8226F9DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226F924;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226F934;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8226F93C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226f994
	if (cr6.eq) goto loc_8226F994;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8226F950;
	sub_822A3998(ctx, base);
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822a3998
	ctx.lr = 0x8226F964;
	sub_822A3998(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226f994
	if (cr6.eq) goto loc_8226F994;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226f994
	if (cr6.eq) goto loc_8226F994;
	// lwz r4,48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8226f994
	if (cr6.eq) goto loc_8226F994;
	// lbz r5,16(r27)
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + 16);
	// bl 0x8232c080
	ctx.lr = 0x8226F994;
	sub_8232C080(ctx, base);
loc_8226F994:
	// lwz r3,700(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8226F99C;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226f9dc
	if (cr6.eq) goto loc_8226F9DC;
	// ld r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U64(r27.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ld r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U64(r27.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// ld r7,16(r27)
	ctx.r7.u64 = PPC_LOAD_U64(r27.u32 + 16);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10240(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r10,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r10.u64);
	// std r8,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r8.u64);
	// std r7,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r7.u64);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8226f690
	ctx.lr = 0x8226F9DC;
	sub_8226F690(ctx, base);
loc_8226F9DC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8226F9E4"))) PPC_WEAK_FUNC(sub_8226F9E4);
PPC_FUNC_IMPL(__imp__sub_8226F9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226F9E8"))) PPC_WEAK_FUNC(sub_8226F9E8);
PPC_FUNC_IMPL(__imp__sub_8226F9E8) {
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
	ctx.lr = 0x8226F9F0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8226FA08;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226facc
	if (cr6.eq) goto loc_8226FACC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FA1C;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226FA2C;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226facc
	if (cr6.eq) goto loc_8226FACC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FA40;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FA50;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addic. r9,r10,144
	xer.ca = ctx.r10.u32 > 4294967151;
	ctx.r9.s64 = ctx.r10.s64 + 144;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8226facc
	if (cr0.eq) goto loc_8226FACC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e71c8
	ctx.lr = 0x8226FA64;
	sub_824E71C8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FA6C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// ld r28,0(r30)
	r28.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FA84;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8226FA8C;
	sub_82272A30(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x824824c8
	ctx.lr = 0x8226FA9C;
	sub_824824C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8226facc
	if (cr6.eq) goto loc_8226FACC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// ld r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8226f7a0
	ctx.lr = 0x8226FACC;
	sub_8226F7A0(ctx, base);
loc_8226FACC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8226FAD4"))) PPC_WEAK_FUNC(sub_8226FAD4);
PPC_FUNC_IMPL(__imp__sub_8226FAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226FAD8"))) PPC_WEAK_FUNC(sub_8226FAD8);
PPC_FUNC_IMPL(__imp__sub_8226FAD8) {
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
	ctx.lr = 0x8226FAE0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226FAEC;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226fc14
	if (cr6.eq) goto loc_8226FC14;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r10,2660(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2660);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8226fc14
	if (!cr6.eq) goto loc_8226FC14;
	// lis r11,-32217
	r11.s64 = -2111373312;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1560
	ctx.r9.s64 = r11.s64 + -1560;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82388580
	ctx.lr = 0x8226FB2C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FB3C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x8226FB44;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x8226FB48;
	sub_824F97C0(ctx, base);
	// lwz r7,700(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 700);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8227e750
	ctx.lr = 0x8226FB58;
	sub_8227E750(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226fb6c
	if (cr6.eq) goto loc_8226FB6C;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8226fbf4
	goto loc_8226FBF4;
loc_8226FB6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FB74;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FB84;
	sub_82270170(ctx, base);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226fc14
	if (cr6.eq) goto loc_8226FC14;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// bl 0x824e6310
	ctx.lr = 0x8226FB9C;
	sub_824E6310(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r31,11780(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 11780);
	// beq cr6,0x8226fc14
	if (cr6.eq) goto loc_8226FC14;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8226fc14
	if (cr6.eq) goto loc_8226FC14;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481578
	ctx.lr = 0x8226FBB8;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226fc14
	if (cr6.eq) goto loc_8226FC14;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x8226FBCC;
	sub_82130000(ctx, base);
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// bl 0x824f97c0
	ctx.lr = 0x8226FBD4;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82482560
	ctx.lr = 0x8226FBE4;
	sub_82482560(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226fc14
	if (cr6.eq) goto loc_8226FC14;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
loc_8226FBF4:
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r5,68(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824f0ba0
	ctx.lr = 0x8226FC14;
	sub_824F0BA0(ctx, base);
loc_8226FC14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226be68
	ctx.lr = 0x8226FC1C;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226fd0c
	if (cr6.eq) goto loc_8226FD0C;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r11,2660(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2660);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226fd0c
	if (cr6.eq) goto loc_8226FD0C;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226fd0c
	if (!cr6.eq) goto loc_8226FD0C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FC50;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FC60;
	sub_82270170(ctx, base);
	// lwz r26,208(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lbz r10,9(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 9);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226fd0c
	if (!cr6.eq) goto loc_8226FD0C;
	// addi r29,r26,12
	r29.s64 = r26.s64 + 12;
	// li r28,31
	r28.s64 = 31;
loc_8226FC78:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226d068
	ctx.lr = 0x8226FC88;
	sub_8226D068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226fd00
	if (cr6.eq) goto loc_8226FD00;
	// lwz r11,11780(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 11780);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8226fcb4
	if (!cr6.eq) goto loc_8226FCB4;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x822999e0
	ctx.lr = 0x8226FCB0;
	sub_822999E0(ctx, base);
	// b 0x8226fd00
	goto loc_8226FD00;
loc_8226FCB4:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x8226FCBC;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x8226FCC0;
	sub_824F97C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824f0ce0
	ctx.lr = 0x8226FCD0;
	sub_824F0CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226fd00
	if (cr6.eq) goto loc_8226FD00;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824f0da0
	ctx.lr = 0x8226FCE8;
	sub_824F0DA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8226fd00
	if (!cr6.eq) goto loc_8226FD00;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824f1c40
	ctx.lr = 0x8226FD00;
	sub_824F1C40(ctx, base);
loc_8226FD00:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8226fc78
	if (!cr0.eq) goto loc_8226FC78;
loc_8226FD0C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r11,2660(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2660);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226fd24
	if (cr6.eq) goto loc_8226FD24;
	// bl 0x824f2230
	ctx.lr = 0x8226FD24;
	sub_824F2230(ctx, base);
loc_8226FD24:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8226FD2C"))) PPC_WEAK_FUNC(sub_8226FD2C);
PPC_FUNC_IMPL(__imp__sub_8226FD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226FD30"))) PPC_WEAK_FUNC(sub_8226FD30);
PPC_FUNC_IMPL(__imp__sub_8226FD30) {
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
	ctx.lr = 0x8226FD38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x822995b0
	ctx.lr = 0x8226FD50;
	sub_822995B0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r10,-10240(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r29,-3644
	ctx.r9.s64 = r29.s64 + -3644;
	// lwz r3,4296(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4296);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// bl 0x822995c8
	ctx.lr = 0x8226FD6C;
	sub_822995C8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// stw r11,-3644(r29)
	PPC_STORE_U32(r29.u32 + -3644, r11.u32);
	// bl 0x82272370
	ctx.lr = 0x8226FD7C;
	sub_82272370(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226fad8
	ctx.lr = 0x8226FD84;
	sub_8226FAD8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226d120
	ctx.lr = 0x8226FD8C;
	sub_8226D120(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226c6c8
	ctx.lr = 0x8226FD94;
	sub_8226C6C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226c818
	ctx.lr = 0x8226FD9C;
	sub_8226C818(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226c998
	ctx.lr = 0x8226FDA4;
	sub_8226C998(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226cc80
	ctx.lr = 0x8226FDAC;
	sub_8226CC80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226cd18
	ctx.lr = 0x8226FDB4;
	sub_8226CD18(ctx, base);
	// lwz r3,752(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 752);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8226fdc4
	if (cr6.eq) goto loc_8226FDC4;
	// bl 0x824f3b50
	ctx.lr = 0x8226FDC4;
	sub_824F3B50(ctx, base);
loc_8226FDC4:
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r11,4300(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226feb8
	if (cr6.eq) goto loc_8226FEB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FDDC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FDEC;
	sub_82270170(ctx, base);
	// bl 0x82203310
	ctx.lr = 0x8226FDF0;
	sub_82203310(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226feb8
	if (cr6.eq) goto loc_8226FEB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FE04;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FE14;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272e60
	ctx.lr = 0x8226FE1C;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8226fe54
	if (!cr6.eq) goto loc_8226FE54;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FE30;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FE40;
	sub_82270170(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82272e60
	ctx.lr = 0x8226FE48;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8226feb8
	if (cr6.eq) goto loc_8226FEB8;
loc_8226FE54:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FE5C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FE6C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8226FE74;
	sub_821F8730(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463e20
	ctx.lr = 0x8226FE84;
	sub_82463E20(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r29,r8,1
	r29.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82388580
	ctx.lr = 0x8226FE9C;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8226FEAC;
	sub_82270170(ctx, base);
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82274128
	ctx.lr = 0x8226FEB8;
	sub_82274128(ctx, base);
loc_8226FEB8:
	// lwz r3,700(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// bl 0x822831e8
	ctx.lr = 0x8226FEC0;
	sub_822831E8(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r11,4296(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8226ff04
	if (cr6.eq) goto loc_8226FF04;
	// lwz r30,68(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8226ff04
	if (cr6.eq) goto loc_8226FF04;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r29,758(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 758);
	// bl 0x824ea870
	ctx.lr = 0x8226FEE8;
	sub_824EA870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8226ff04
	if (cr6.eq) goto loc_8226FF04;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ea858
	ctx.lr = 0x8226FF04;
	sub_824EA858(ctx, base);
loc_8226FF04:
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82289360
	ctx.lr = 0x8226FF10;
	sub_82289360(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8226FF18"))) PPC_WEAK_FUNC(sub_8226FF18);
PPC_FUNC_IMPL(__imp__sub_8226FF18) {
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
	ctx.lr = 0x8226FF20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x8226FF3C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8226ffec
	if (cr6.eq) goto loc_8226FFEC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x8226FF50;
	sub_824F0498(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824f0498
	ctx.lr = 0x8226FF58;
	sub_824F0498(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8226FF60;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8226FF70;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x8226FF78;
	sub_82502300(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// bl 0x822a3998
	ctx.lr = 0x8226FF90;
	sub_822A3998(ctx, base);
	// lwz r11,1220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x8226FF9C;
	sub_82502300(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,700(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 700);
	// ld r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// stb r27,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r27.u8);
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// bl 0x8227e750
	ctx.lr = 0x8226FFB4;
	sub_8227E750(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8226ffd4
	if (cr6.eq) goto loc_8226FFD4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226f850
	ctx.lr = 0x8226FFCC;
	sub_8226F850(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_8226FFD4:
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8226f618
	ctx.lr = 0x8226FFEC;
	sub_8226F618(ctx, base);
loc_8226FFEC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8226FFF4"))) PPC_WEAK_FUNC(sub_8226FFF4);
PPC_FUNC_IMPL(__imp__sub_8226FFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8226FFF8"))) PPC_WEAK_FUNC(sub_8226FFF8);
PPC_FUNC_IMPL(__imp__sub_8226FFF8) {
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
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x82270014;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270030
	if (!cr6.eq) goto loc_82270030;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82270034
	if (cr6.eq) goto loc_82270034;
loc_82270030:
	// li r11,0
	r11.s64 = 0;
loc_82270034:
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

__attribute__((alias("__imp__sub_8227004C"))) PPC_WEAK_FUNC(sub_8227004C);
PPC_FUNC_IMPL(__imp__sub_8227004C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82270050"))) PPC_WEAK_FUNC(sub_82270050);
PPC_FUNC_IMPL(__imp__sub_82270050) {
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
	ctx.lr = 0x82270058;
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
	// beq cr6,0x822700bc
	if (cr6.eq) goto loc_822700BC;
	// lwz r10,-8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// addi r29,r30,-8
	r29.s64 = r30.s64 + -8;
	// mulli r11,r10,10832
	r11.s64 = ctx.r10.s64 * 10832;
	// addic. r31,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r31.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// blt 0x8227009c
	if (cr0.lt) goto loc_8227009C;
loc_82270088:
	// addi r30,r30,-10832
	r30.s64 = r30.s64 + -10832;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82274c80
	ctx.lr = 0x82270094;
	sub_82274C80(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82270088
	if (!cr0.lt) goto loc_82270088;
loc_8227009C:
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822700b0
	if (cr6.eq) goto loc_822700B0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822700B0;
	sub_82130588(ctx, base);
loc_822700B0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822700BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82274c80
	ctx.lr = 0x822700C4;
	sub_82274C80(ctx, base);
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822700d8
	if (cr6.eq) goto loc_822700D8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822700D8;
	sub_82130588(ctx, base);
loc_822700D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822700E4"))) PPC_WEAK_FUNC(sub_822700E4);
PPC_FUNC_IMPL(__imp__sub_822700E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822700E8"))) PPC_WEAK_FUNC(sub_822700E8);
PPC_FUNC_IMPL(__imp__sub_822700E8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,19816
	ctx.r10.s64 = r11.s64 + 19816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270158
	if (!cr6.eq) goto loc_82270158;
	// lwz r11,4300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4300);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270158
	if (!cr6.eq) goto loc_82270158;
	// li r3,6464
	ctx.r3.s64 = 6464;
	// bl 0x82130528
	ctx.lr = 0x82270124;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82270134
	if (cr6.eq) goto loc_82270134;
	// bl 0x82464f50
	ctx.lr = 0x82270130;
	sub_82464F50(ctx, base);
	// b 0x82270138
	goto loc_82270138;
loc_82270134:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82270138:
	// stw r3,4300(r31)
	PPC_STORE_U32(r31.u32 + 4300, ctx.r3.u32);
	// li r7,14
	ctx.r7.s64 = 14;
	// lwz r11,4296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,68(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x82464538
	ctx.lr = 0x82270158;
	sub_82464538(ctx, base);
loc_82270158:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227016C"))) PPC_WEAK_FUNC(sub_8227016C);
PPC_FUNC_IMPL(__imp__sub_8227016C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82270170"))) PPC_WEAK_FUNC(sub_82270170);
PPC_FUNC_IMPL(__imp__sub_82270170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4284);
	// mulli r10,r4,10832
	ctx.r10.s64 = ctx.r4.s64 * 10832;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82270180"))) PPC_WEAK_FUNC(sub_82270180);
PPC_FUNC_IMPL(__imp__sub_82270180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,4288(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4288);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
loc_82270194:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// cmpw cr6,r6,r9
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, xer);
	// beq cr6,0x822701bc
	if (cr6.eq) goto loc_822701BC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,11824
	r11.s64 = r11.s64 + 11824;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x82270194
	if (!cr6.eq) goto loc_82270194;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822701BC:
	// mulli r11,r10,11824
	r11.s64 = ctx.r10.s64 * 11824;
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822701C8"))) PPC_WEAK_FUNC(sub_822701C8);
PPC_FUNC_IMPL(__imp__sub_822701C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,4288(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4288);
	// li r11,0
	r11.s64 = 0;
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
loc_822701DC:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// cmpw cr6,r6,r8
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, xer);
	// beq cr6,0x82270204
	if (cr6.eq) goto loc_82270204;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,11824
	ctx.r10.s64 = ctx.r10.s64 + 11824;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822701dc
	if (!cr6.eq) goto loc_822701DC;
loc_822701FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82270204:
	// mulli r11,r11,11824
	r11.s64 = r11.s64 * 11824;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822701fc
	if (cr6.eq) goto loc_822701FC;
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227021C"))) PPC_WEAK_FUNC(sub_8227021C);
PPC_FUNC_IMPL(__imp__sub_8227021C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82270220"))) PPC_WEAK_FUNC(sub_82270220);
PPC_FUNC_IMPL(__imp__sub_82270220) {
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
	ctx.lr = 0x82270228;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822702f4
	if (cr6.eq) goto loc_822702F4;
	// li r27,0
	r27.s64 = 0;
	// li r31,0
	r31.s64 = 0;
loc_82270248:
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x82270258;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270274
	if (!cr6.eq) goto loc_82270274;
	// lbz r11,8(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82270278
	if (cr6.eq) goto loc_82270278;
loc_82270274:
	// li r11,0
	r11.s64 = 0;
loc_82270278:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822702e4
	if (!cr6.eq) goto loc_822702E4;
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x82270294;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822702b0
	if (cr6.eq) goto loc_822702B0;
	// lbz r11,8(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822702b4
	if (!cr6.eq) goto loc_822702B4;
loc_822702B0:
	// li r11,0
	r11.s64 = 0;
loc_822702B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822702e4
	if (!cr6.eq) goto loc_822702E4;
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481618
	ctx.lr = 0x822702D0;
	sub_82481618(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824e6358
	ctx.lr = 0x822702D8;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270354
	if (!cr6.eq) goto loc_82270354;
loc_822702E4:
	// addi r31,r31,11824
	r31.s64 = r31.s64 + 11824;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmplwi cr6,r31,47296
	cr6.compare<uint32_t>(r31.u32, 47296, xer);
	// bne cr6,0x82270248
	if (!cr6.eq) goto loc_82270248;
loc_822702F4:
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
loc_822702FC:
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481578
	ctx.lr = 0x8227030C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270328
	if (!cr6.eq) goto loc_82270328;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227032c
	if (cr6.eq) goto loc_8227032C;
loc_82270328:
	// li r11,0
	r11.s64 = 0;
loc_8227032C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270374
	if (!cr6.eq) goto loc_82270374;
	// addi r29,r29,11824
	r29.s64 = r29.s64 + 11824;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmplwi cr6,r29,47296
	cr6.compare<uint32_t>(r29.u32, 47296, xer);
	// bne cr6,0x822702fc
	if (!cr6.eq) goto loc_822702FC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82270354:
	// lwz r10,4288(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// mulli r11,r27,11824
	r11.s64 = r27.s64 * 11824;
	// lbz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// lwz r10,4288(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82270374:
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// mulli r31,r28,11824
	r31.s64 = r28.s64 * 11824;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82297568
	ctx.lr = 0x82270384;
	sub_82297568(ctx, base);
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// lbz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// lwz r11,4288(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4288);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822703A0"))) PPC_WEAK_FUNC(sub_822703A0);
PPC_FUNC_IMPL(__imp__sub_822703A0) {
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
	ctx.lr = 0x822703A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x82618640
	ctx.lr = 0x822703C0;
	sub_82618640(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x822703D8;
	sub_82257568(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82270440
	if (cr6.eq) goto loc_82270440;
	// cmplwi cr6,r29,512
	cr6.compare<uint32_t>(r29.u32, 512, xer);
	// bgt cr6,0x82270440
	if (cr6.gt) goto loc_82270440;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826186c0
	ctx.lr = 0x822703FC;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270440
	if (cr6.eq) goto loc_82270440;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82270440
	if (cr6.eq) goto loc_82270440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x82270418;
	sub_823EAEF8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618678
	ctx.lr = 0x82270424;
	sub_82618678(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x82618a30
	ctx.lr = 0x82270438;
	sub_82618A30(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82270444
	goto loc_82270444;
loc_82270440:
	// li r30,1
	r30.s64 = 1;
loc_82270444:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270468
	if (cr6.eq) goto loc_82270468;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189a8
	ctx.lr = 0x8227045C;
	sub_826189A8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82270468;
	sub_82618830(ctx, base);
loc_82270468:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82270474"))) PPC_WEAK_FUNC(sub_82270474);
PPC_FUNC_IMPL(__imp__sub_82270474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82270478"))) PPC_WEAK_FUNC(sub_82270478);
PPC_FUNC_IMPL(__imp__sub_82270478) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x824f0498
	ctx.lr = 0x82270494;
	sub_824F0498(ctx, base);
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618750
	ctx.lr = 0x822704A0;
	sub_82618750(ctx, base);
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618640
	ctx.lr = 0x822704B0;
	sub_82618640(ctx, base);
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

__attribute__((alias("__imp__sub_822704CC"))) PPC_WEAK_FUNC(sub_822704CC);
PPC_FUNC_IMPL(__imp__sub_822704CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822704D0"))) PPC_WEAK_FUNC(sub_822704D0);
PPC_FUNC_IMPL(__imp__sub_822704D0) {
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
	ctx.lr = 0x822704D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// ori r27,r11,43328
	r27.u64 = r11.u64 | 43328;
loc_822704F4:
	// lwz r11,4284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4284);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82270504;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270538
	if (cr6.eq) goto loc_82270538;
	// lwz r11,4284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4284);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82270520;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0550
	ctx.lr = 0x8227052C;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822705ac
	if (!cr6.eq) goto loc_822705AC;
loc_82270538:
	// addi r31,r31,10832
	r31.s64 = r31.s64 + 10832;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x822704f4
	if (cr6.lt) goto loc_822704F4;
	// lwz r11,4280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4280);
	// li r29,0
	r29.s64 = 0;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822705a0
	if (cr6.eq) goto loc_822705A0;
	// li r31,0
	r31.s64 = 0;
loc_82270560:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82270570;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0550
	ctx.lr = 0x8227057C;
	sub_824F0550(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,4280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822705c0
	if (!cr6.eq) goto loc_822705C0;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82270560
	if (cr6.lt) goto loc_82270560;
loc_822705A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822705AC:
	// lwz r10,4284(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4284);
	// mulli r11,r29,10832
	r11.s64 = r29.s64 * 10832;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822705C0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822705D4"))) PPC_WEAK_FUNC(sub_822705D4);
PPC_FUNC_IMPL(__imp__sub_822705D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822705D8"))) PPC_WEAK_FUNC(sub_822705D8);
PPC_FUNC_IMPL(__imp__sub_822705D8) {
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
	ctx.lr = 0x822705E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// addi r27,r31,68
	r27.s64 = r31.s64 + 68;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r29,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r29.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x824e6310
	ctx.lr = 0x8227060C;
	sub_824E6310(ctx, base);
	// addi r28,r31,80
	r28.s64 = r31.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0a58
	ctx.lr = 0x82270618;
	sub_824E0A58(ctx, base);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ce080
	ctx.lr = 0x82270624;
	sub_821CE080(ctx, base);
	// stw r29,644(r31)
	PPC_STORE_U32(r31.u32 + 644, r29.u32);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// stw r26,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r26.u32);
	// addi r4,r30,557
	ctx.r4.s64 = r30.s64 + 557;
	// stb r25,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r25.u8);
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r26,r10,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x823da950
	ctx.lr = 0x8227064C;
	sub_823DA950(ctx, base);
	// cntlzw r9,r26
	ctx.r9.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// cntlzw r7,r26
	ctx.r7.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r6,32(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// rlwinm r10,r7,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// xori r9,r4,1
	ctx.r9.u64 = ctx.r4.u64 ^ 1;
	// std r29,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r29.u64);
	// addi r7,r30,44
	ctx.r7.s64 = r30.s64 + 44;
	// std r29,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r29.u64);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x824e0ab0
	ctx.lr = 0x82270684;
	sub_824E0AB0(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x822706b0
	if (!cr6.eq) goto loc_822706B0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824f88f8
	ctx.lr = 0x822706A0;
	sub_824F88F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e6330
	ctx.lr = 0x822706B0;
	sub_824E6330(ctx, base);
loc_822706B0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822706B8"))) PPC_WEAK_FUNC(sub_822706B8);
PPC_FUNC_IMPL(__imp__sub_822706B8) {
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
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x822703a0
	ctx.lr = 0x822706E0;
	sub_822703A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270728
	if (cr6.eq) goto loc_82270728;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x822706FC;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270728
	if (cr6.eq) goto loc_82270728;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r30,100
	ctx.r4.s64 = r30.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82270718;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227072c
	if (!cr6.eq) goto loc_8227072C;
loc_82270728:
	// li r11,0
	r11.s64 = 0;
loc_8227072C:
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

__attribute__((alias("__imp__sub_82270748"))) PPC_WEAK_FUNC(sub_82270748);
PPC_FUNC_IMPL(__imp__sub_82270748) {
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
	ctx.lr = 0x82270750;
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
	ctx.lr = 0x82270780;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227078C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8227079C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822707cc
	if (cr6.eq) goto loc_822707CC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x822707cc
	if (!cr6.eq) goto loc_822707CC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822706b8
	ctx.lr = 0x822707BC;
	sub_822706B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822707d0
	if (!cr6.eq) goto loc_822707D0;
loc_822707CC:
	// li r31,0
	r31.s64 = 0;
loc_822707D0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822707fc
	if (cr6.eq) goto loc_822707FC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822707f4
	if (cr6.eq) goto loc_822707F4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822707EC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x822707f8
	goto loc_822707F8;
loc_822707F4:
	// li r11,0
	r11.s64 = 0;
loc_822707F8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_822707FC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270820
	if (cr6.eq) goto loc_82270820;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82270810;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82270824
	if (cr6.eq) goto loc_82270824;
loc_82270820:
	// li r11,0
	r11.s64 = 0;
loc_82270824:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82270830"))) PPC_WEAK_FUNC(sub_82270830);
PPC_FUNC_IMPL(__imp__sub_82270830) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,288
	ctx.r9.s64 = 288;
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// sth r10,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r10.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// beq cr6,0x82270884
	if (cr6.eq) goto loc_82270884;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x82270880;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82270884:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x82270894;
	sub_821F10E0(ctx, base);
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

__attribute__((alias("__imp__sub_822708AC"))) PPC_WEAK_FUNC(sub_822708AC);
PPC_FUNC_IMPL(__imp__sub_822708AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822708B0"))) PPC_WEAK_FUNC(sub_822708B0);
PPC_FUNC_IMPL(__imp__sub_822708B0) {
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
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lhz r11,6(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r10.u16);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822708f0
	if (cr6.eq) goto loc_822708F0;
	// bl 0x82273280
	ctx.lr = 0x822708EC;
	sub_82273280(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822708F0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82270904"))) PPC_WEAK_FUNC(sub_82270904);
PPC_FUNC_IMPL(__imp__sub_82270904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82270908"))) PPC_WEAK_FUNC(sub_82270908);
PPC_FUNC_IMPL(__imp__sub_82270908) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270948
	if (cr6.eq) goto loc_82270948;
loc_82270914:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x8227093c
	if (!cr6.eq) goto loc_8227093C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82270930
	if (cr6.eq) goto loc_82270930;
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_82270930:
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r9.u8);
loc_8227093C:
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270914
	if (!cr6.eq) goto loc_82270914;
loc_82270948:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82270984
	if (!cr6.eq) goto loc_82270984;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r8,16(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8227097c
	if (cr6.eq) goto loc_8227097C;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// b 0x822709ac
	goto loc_822709AC;
loc_8227097C:
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// b 0x822709ac
	goto loc_822709AC;
loc_82270984:
	// lwz r8,16(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822709a4
	if (cr6.eq) goto loc_822709A4;
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r8.u32);
	// b 0x822709ac
	goto loc_822709AC;
loc_822709A4:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822709AC:
	// stw r9,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r9.u32);
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822709C4"))) PPC_WEAK_FUNC(sub_822709C4);
PPC_FUNC_IMPL(__imp__sub_822709C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822709C8"))) PPC_WEAK_FUNC(sub_822709C8);
PPC_FUNC_IMPL(__imp__sub_822709C8) {
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
	ctx.lr = 0x822709D0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// bl 0x826185a0
	ctx.lr = 0x822709E0;
	sub_826185A0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r24,1
	ctx.r4.s64 = r24.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82250ff8
	ctx.lr = 0x822709F4;
	sub_82250FF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270a2c
	if (cr6.eq) goto loc_82270A2C;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618f10
	ctx.lr = 0x82270A0C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270a2c
	if (cr6.eq) goto loc_82270A2C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822959b8
	ctx.lr = 0x82270A20;
	sub_822959B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82270a30
	if (!cr6.eq) goto loc_82270A30;
loc_82270A2C:
	// li r11,0
	r11.s64 = 0;
loc_82270A30:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82270c04
	if (cr6.eq) goto loc_82270C04;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822959b8
	ctx.lr = 0x82270A44;
	sub_822959B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r30,1396
	ctx.r4.s64 = r30.s64 + 1396;
	// bl 0x821c8fe0
	ctx.lr = 0x82270A54;
	sub_821C8FE0(ctx, base);
	// lbz r11,0(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270a8c
	if (!cr6.eq) goto loc_82270A8C;
	// addi r31,r30,552
	r31.s64 = r30.s64 + 552;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82270A70;
	sub_82618830(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x82270A78;
	sub_822954F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618af8
	ctx.lr = 0x82270A88;
	sub_82618AF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82270A8C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270ac4
	if (cr6.eq) goto loc_82270AC4;
	// addi r31,r30,584
	r31.s64 = r30.s64 + 584;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82270AA8;
	sub_82618830(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x82270AB0;
	sub_822954F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618af8
	ctx.lr = 0x82270AC0;
	sub_82618AF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82270AC4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270bfc
	if (cr6.eq) goto loc_82270BFC;
	// addi r27,r30,748
	r27.s64 = r30.s64 + 748;
loc_82270AD8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954f0
	ctx.lr = 0x82270AE0;
	sub_822954F0(ctx, base);
	// cmpw cr6,r28,r3
	cr6.compare<int32_t>(r28.s32, ctx.r3.s32, xer);
	// bge cr6,0x82270bfc
	if (!cr6.lt) goto loc_82270BFC;
	// lbz r11,0(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270b0c
	if (!cr6.eq) goto loc_82270B0C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295238
	ctx.lr = 0x82270B00;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270be8
	if (cr6.eq) goto loc_82270BE8;
loc_82270B0C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x82270B18;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270be8
	if (cr6.eq) goto loc_82270BE8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822954b8
	ctx.lr = 0x82270B30;
	sub_822954B8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// bl 0x82295510
	ctx.lr = 0x82270B44;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82270b9c
	if (!cr6.eq) goto loc_82270B9C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826185a0
	ctx.lr = 0x82270B54;
	sub_826185A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270b68
	if (!cr6.eq) goto loc_82270B68;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82270B68:
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82270b88
	if (cr6.eq) goto loc_82270B88;
loc_82270B78:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270b78
	if (!cr6.eq) goto loc_82270B78;
loc_82270B88:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82257568
	ctx.lr = 0x82270B94;
	sub_82257568(ctx, base);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82270B9C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270be8
	if (cr6.eq) goto loc_82270BE8;
	// addi r31,r30,520
	r31.s64 = r30.s64 + 520;
	// lwz r4,-136(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + -136);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618830
	ctx.lr = 0x82270BB8;
	sub_82618830(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82618af8
	ctx.lr = 0x82270BC8;
	sub_82618AF8(ctx, base);
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270be8
	if (cr6.eq) goto loc_82270BE8;
	// stw r29,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r29.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822951d0
	ctx.lr = 0x82270BE8;
	sub_822951D0(ctx, base);
loc_82270BE8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270ad8
	if (!cr6.eq) goto loc_82270AD8;
loc_82270BFC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82270C04;
	sub_821C9030(ctx, base);
loc_82270C04:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270c2c
	if (cr6.eq) goto loc_82270C2C;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270c2c
	if (cr6.eq) goto loc_82270C2C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822959b8
	ctx.lr = 0x82270C24;
	sub_822959B8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
loc_82270C2C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82270C38"))) PPC_WEAK_FUNC(sub_82270C38);
PPC_FUNC_IMPL(__imp__sub_82270C38) {
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
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82250ff8
	ctx.lr = 0x82270C5C;
	sub_82250FF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270c88
	if (cr6.eq) goto loc_82270C88;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618c90
	ctx.lr = 0x82270C78;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82270c8c
	if (!cr6.eq) goto loc_82270C8C;
loc_82270C88:
	// li r11,0
	r11.s64 = 0;
loc_82270C8C:
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

__attribute__((alias("__imp__sub_82270CA8"))) PPC_WEAK_FUNC(sub_82270CA8);
PPC_FUNC_IMPL(__imp__sub_82270CA8) {
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
	ctx.lr = 0x82270CB0;
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
	ctx.lr = 0x82270CE0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82270CEC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82270CFC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82270d2c
	if (cr6.eq) goto loc_82270D2C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82270d2c
	if (!cr6.eq) goto loc_82270D2C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822709c8
	ctx.lr = 0x82270D1C;
	sub_822709C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270d30
	if (!cr6.eq) goto loc_82270D30;
loc_82270D2C:
	// li r31,0
	r31.s64 = 0;
loc_82270D30:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82270d5c
	if (cr6.eq) goto loc_82270D5C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270d54
	if (cr6.eq) goto loc_82270D54;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82270D4C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82270d58
	goto loc_82270D58;
loc_82270D54:
	// li r11,0
	r11.s64 = 0;
loc_82270D58:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82270D5C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270d80
	if (cr6.eq) goto loc_82270D80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82270D70;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82270d84
	if (cr6.eq) goto loc_82270D84;
loc_82270D80:
	// li r11,0
	r11.s64 = 0;
loc_82270D84:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82270D90"))) PPC_WEAK_FUNC(sub_82270D90);
PPC_FUNC_IMPL(__imp__sub_82270D90) {
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
	ctx.lr = 0x82270D98;
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
	ctx.lr = 0x82270DC8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82270DD4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82270DE4;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82270e14
	if (cr6.eq) goto loc_82270E14;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82270e14
	if (!cr6.eq) goto loc_82270E14;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82270c38
	ctx.lr = 0x82270E04;
	sub_82270C38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82270e18
	if (!cr6.eq) goto loc_82270E18;
loc_82270E14:
	// li r31,0
	r31.s64 = 0;
loc_82270E18:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82270e44
	if (cr6.eq) goto loc_82270E44;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270e3c
	if (cr6.eq) goto loc_82270E3C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82270E34;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82270e40
	goto loc_82270E40;
loc_82270E3C:
	// li r11,0
	r11.s64 = 0;
loc_82270E40:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82270E44:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82270e68
	if (cr6.eq) goto loc_82270E68;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82270E58;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82270e6c
	if (cr6.eq) goto loc_82270E6C;
loc_82270E68:
	// li r11,0
	r11.s64 = 0;
loc_82270E6C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82270E78"))) PPC_WEAK_FUNC(sub_82270E78);
PPC_FUNC_IMPL(__imp__sub_82270E78) {
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
	ctx.lr = 0x82270E80;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// addi r30,r31,23592
	r30.s64 = r31.s64 + 23592;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,23592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23592);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82270EBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb718
	ctx.lr = 0x82270ED0;
	sub_824FB718(ctx, base);
	// bl 0x824fb3b0
	ctx.lr = 0x82270ED4;
	sub_824FB3B0(ctx, base);
	// lwz r11,4292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4292);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x824ea350
	ctx.lr = 0x82270EE4;
	sub_824EA350(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824ea350
	ctx.lr = 0x82270EF0;
	sub_824EA350(ctx, base);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82270F04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,4296(r31)
	PPC_STORE_U32(r31.u32 + 4296, ctx.r3.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82299fc0
	ctx.lr = 0x82270F10;
	sub_82299FC0(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,4304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4304);
	// bl 0x82294f68
	ctx.lr = 0x82270F1C;
	sub_82294F68(ctx, base);
	// lwz r29,4280(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4280);
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82270f68
	if (!cr6.eq) goto loc_82270F68;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82270F34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82270f48
	if (cr6.eq) goto loc_82270F48;
	// li r4,31
	ctx.r4.s64 = 31;
	// bl 0x82270830
	ctx.lr = 0x82270F44;
	sub_82270830(ctx, base);
	// b 0x82270f4c
	goto loc_82270F4C;
loc_82270F48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82270F4C:
	// li r25,31
	r25.s64 = 31;
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// li r3,124
	ctx.r3.s64 = 124;
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
	// bl 0x82130528
	ctx.lr = 0x82270F60;
	sub_82130528(ctx, base);
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// sth r25,14(r29)
	PPC_STORE_U16(r29.u32 + 14, r25.u16);
loc_82270F68:
	// lwz r11,4296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x824ea838
	ctx.lr = 0x82270F74;
	sub_824EA838(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x824fb990
	ctx.lr = 0x82270F88;
	sub_824FB990(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,244(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// bl 0x82272870
	ctx.lr = 0x82270F94;
	sub_82272870(ctx, base);
	// lwz r10,4296(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,23564
	ctx.r4.s64 = r31.s64 + 23564;
	// lwz r3,68(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// bl 0x824ec120
	ctx.lr = 0x82270FA8;
	sub_824EC120(ctx, base);
	// lwz r9,4296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// lwz r28,68(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// lwz r29,4292(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4292);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ea838
	ctx.lr = 0x82270FBC;
	sub_824EA838(ctx, base);
	// bl 0x824f88f8
	ctx.lr = 0x82270FC0;
	sub_824F88F8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// bl 0x824ea838
	ctx.lr = 0x82270FD0;
	sub_824EA838(ctx, base);
	// bl 0x82656bf0
	ctx.lr = 0x82270FD4;
	sub_82656BF0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82299320
	ctx.lr = 0x82270FE4;
	sub_82299320(ctx, base);
	// addi r27,r31,1184
	r27.s64 = r31.s64 + 1184;
	// addi r4,r31,23544
	ctx.r4.s64 = r31.s64 + 23544;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e7f88
	ctx.lr = 0x82270FF4;
	sub_824E7F88(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x824e8808
	ctx.lr = 0x82271000;
	sub_824E8808(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// addi r3,r3,25900
	ctx.r3.s64 = ctx.r3.s64 + 25900;
	// bl 0x824ea460
	ctx.lr = 0x8227100C;
	sub_824EA460(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r7,4296(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4296);
	// lwz r11,-10240(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// lwz r6,4296(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r3,68(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r28,68(r7)
	r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// bl 0x824ea838
	ctx.lr = 0x8227102C;
	sub_824EA838(ctx, base);
	// bl 0x824f88f8
	ctx.lr = 0x82271030;
	sub_824F88F8(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r3,r5,-2984
	ctx.r3.s64 = ctx.r5.s64 + -2984;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// li r6,11
	ctx.r6.s64 = 11;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// bl 0x824852f8
	ctx.lr = 0x82271054;
	sub_824852F8(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// ori r28,r11,47296
	r28.u64 = r11.u64 | 47296;
loc_82271064:
	// lwz r11,4288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4288);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x82297568
	ctx.lr = 0x82271070;
	sub_82297568(ctx, base);
	// lwz r11,4288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4288);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822971b0
	ctx.lr = 0x82271080;
	sub_822971B0(ctx, base);
	// addi r30,r30,11824
	r30.s64 = r30.s64 + 11824;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x82271064
	if (cr6.lt) goto loc_82271064;
	// lis r11,0
	r11.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// ori r26,r11,43328
	r26.u64 = r11.u64 | 43328;
loc_822710A0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e7678
	ctx.lr = 0x822710AC;
	sub_824E7678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822710e4
	if (cr6.eq) goto loc_822710E4;
	// bl 0x824e6f80
	ctx.lr = 0x822710BC;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822710e4
	if (cr6.eq) goto loc_822710E4;
	// lwz r11,4284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4284);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82274130
	ctx.lr = 0x822710D8;
	sub_82274130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271108
	if (cr6.eq) goto loc_82271108;
loc_822710E4:
	// addi r29,r29,10832
	r29.s64 = r29.s64 + 10832;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r29,r26
	cr6.compare<int32_t>(r29.s32, r26.s32, xer);
	// blt cr6,0x822710a0
	if (cr6.lt) goto loc_822710A0;
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_82271108:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82271114"))) PPC_WEAK_FUNC(sub_82271114);
PPC_FUNC_IMPL(__imp__sub_82271114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82271118"))) PPC_WEAK_FUNC(sub_82271118);
PPC_FUNC_IMPL(__imp__sub_82271118) {
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
	ctx.lr = 0x82271120;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r31,-10240(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82502300
	ctx.lr = 0x82271140;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822704d0
	ctx.lr = 0x8227114C;
	sub_822704D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82271198
	if (!cr6.eq) goto loc_82271198;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822711b8
	if (cr6.eq) goto loc_822711B8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822708b0
	ctx.lr = 0x82271170;
	sub_822708B0(ctx, base);
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// sth r8,12(r30)
	PPC_STORE_U16(r30.u32 + 12, ctx.r8.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stwx r31,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r31.u32);
	// beq cr6,0x822711b8
	if (cr6.eq) goto loc_822711B8;
loc_82271198:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x822711A8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_822711B8:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x822711C0;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822711dc
	if (cr6.eq) goto loc_822711DC;
	// lwz r11,-10240(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x822995e0
	ctx.lr = 0x822711DC;
	sub_822995E0(ctx, base);
loc_822711DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822711E8"))) PPC_WEAK_FUNC(sub_822711E8);
PPC_FUNC_IMPL(__imp__sub_822711E8) {
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
	// addi r10,r11,-1348
	ctx.r10.s64 = r11.s64 + -1348;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227122c
	if (cr6.eq) goto loc_8227122C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x82271224;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8227122C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82271244
	if (cr6.eq) goto loc_82271244;
	// bl 0x82130588
	ctx.lr = 0x82271240;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82271244:
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

