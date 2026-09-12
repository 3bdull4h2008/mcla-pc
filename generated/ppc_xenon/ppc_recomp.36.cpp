#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8227B3D0"))) PPC_WEAK_FUNC(sub_8227B3D0);
PPC_FUNC_IMPL(__imp__sub_8227B3D0) {
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
	ctx.lr = 0x8227B3D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x8226ba28
	ctx.lr = 0x8227B3FC;
	sub_8226BA28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8227b454
	if (cr6.eq) goto loc_8227B454;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227B41C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b454
	if (cr6.eq) goto loc_8227B454;
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
	// bl 0x8227aa90
	ctx.lr = 0x8227B44C;
	sub_8227AA90(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227B454:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B460"))) PPC_WEAK_FUNC(sub_8227B460);
PPC_FUNC_IMPL(__imp__sub_8227B460) {
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
	ctx.lr = 0x8227B468;
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
loc_8227B484:
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
	ctx.lr = 0x8227B49C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b4d0
	if (cr6.eq) goto loc_8227B4D0;
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
	// beq cr6,0x8227b4c8
	if (cr6.eq) goto loc_8227B4C8;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227b4d0
	if (!cr6.eq) goto loc_8227B4D0;
loc_8227B4C8:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227b4d4
	goto loc_8227B4D4;
loc_8227B4D0:
	// li r11,0
	r11.s64 = 0;
loc_8227B4D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b558
	if (cr6.eq) goto loc_8227B558;
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
	// blt cr6,0x8227b548
	if (cr6.lt) goto loc_8227B548;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227B508;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227b52c
	if (!cr6.eq) goto loc_8227B52C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227B520;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b548
	if (cr6.eq) goto loc_8227B548;
loc_8227B52C:
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
	// bl 0x8227a0c0
	ctx.lr = 0x8227B544;
	sub_8227A0C0(ctx, base);
	// b 0x8227b54c
	goto loc_8227B54C;
loc_8227B548:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227B54C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8227B558:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227b484
	if (cr6.lt) goto loc_8227B484;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8227B570"))) PPC_WEAK_FUNC(sub_8227B570);
PPC_FUNC_IMPL(__imp__sub_8227B570) {
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
	ctx.lr = 0x8227B578;
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
	ctx.lr = 0x8227B5A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b5d4
	if (cr6.eq) goto loc_8227B5D4;
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
	// beq cr6,0x8227b5cc
	if (cr6.eq) goto loc_8227B5CC;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227b5d4
	if (!cr6.eq) goto loc_8227B5D4;
loc_8227B5CC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227b5d8
	goto loc_8227B5D8;
loc_8227B5D4:
	// li r11,0
	r11.s64 = 0;
loc_8227B5D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b614
	if (cr6.eq) goto loc_8227B614;
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
	// bl 0x8227ab10
	ctx.lr = 0x8227B60C;
	sub_8227AB10(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227B614:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B620"))) PPC_WEAK_FUNC(sub_8227B620);
PPC_FUNC_IMPL(__imp__sub_8227B620) {
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
	ctx.lr = 0x8227B628;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,136(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8227b768
	if (!cr6.gt) goto loc_8227B768;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// bge cr6,0x8227b768
	if (!cr6.lt) goto loc_8227B768;
	// mulli r11,r11,220
	r11.s64 = r11.s64 * 220;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// ori r9,r10,88
	ctx.r9.u64 = ctx.r10.u64 | 88;
	// lbzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,4
	cr6.compare<uint32_t>(ctx.r8.u32, 4, xer);
	// bne cr6,0x8227b768
	if (!cr6.eq) goto loc_8227B768;
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,292
	r30.s64 = r30.s64 + 292;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b768
	if (cr6.eq) goto loc_8227B768;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r10,29(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 29);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8227b744
	if (!cr6.eq) goto loc_8227B744;
	// bl 0x822781a0
	ctx.lr = 0x8227B69C;
	sub_822781A0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r11,16556
	r31.s64 = r11.s64 + 16556;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822769d0
	ctx.lr = 0x8227B6AC;
	sub_822769D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227b718
	if (cr6.eq) goto loc_8227B718;
	// lbz r8,48(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 48);
	// rlwinm r11,r8,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227b6e8
	if (!cr6.eq) goto loc_8227B6E8;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8227B6D4:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bdnz 0x8227b6d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8227B6D4;
loc_8227B6E8:
	// rlwinm r11,r8,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227b718
	if (!cr6.eq) goto loc_8227B718;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8227B704:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8227b704
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8227B704;
loc_8227B718:
	// lbz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 | 32;
	// stb r8,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r8.u8);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r5,30(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 30);
	// bl 0x8227ae08
	ctx.lr = 0x8227B73C;
	sub_8227AE08(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
loc_8227B744:
	// bl 0x82274d68
	ctx.lr = 0x8227B748;
	sub_82274D68(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r10,r11,84
	ctx.r10.u64 = r11.u64 | 84;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r4,r31,r10
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// bl 0x8227a458
	ctx.lr = 0x8227B768;
	sub_8227A458(ctx, base);
loc_8227B768:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B770"))) PPC_WEAK_FUNC(sub_8227B770);
PPC_FUNC_IMPL(__imp__sub_8227B770) {
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
	ctx.lr = 0x8227B778;
	// stwu r1,-1280(r1)
	ea = -1280 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8227B79C;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227b7dc
	if (cr6.eq) goto loc_8227B7DC;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r31,700(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x821c9790
	ctx.lr = 0x8227B7BC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x822837b8
	ctx.lr = 0x8227B7D4;
	sub_822837B8(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9244
	return;
loc_8227B7DC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227b82c
	if (cr6.eq) goto loc_8227B82C;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82250410
	ctx.lr = 0x8227B7EC;
	sub_82250410(ctx, base);
	// addi r3,r1,1216
	ctx.r3.s64 = ctx.r1.s64 + 1216;
	// bl 0x82293e18
	ctx.lr = 0x8227B7F4;
	sub_82293E18(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82275878
	ctx.lr = 0x8227B800;
	sub_82275878(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,1216
	ctx.r3.s64 = ctx.r1.s64 + 1216;
	// bl 0x82293e60
	ctx.lr = 0x8227B80C;
	sub_82293E60(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227b070
	ctx.lr = 0x8227B824;
	sub_8227B070(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9244
	return;
loc_8227B82C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822757d0
	ctx.lr = 0x8227B83C;
	sub_822757D0(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227b0e8
	ctx.lr = 0x8227B854;
	sub_8227B0E8(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227B85C"))) PPC_WEAK_FUNC(sub_8227B85C);
PPC_FUNC_IMPL(__imp__sub_8227B85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227B860"))) PPC_WEAK_FUNC(sub_8227B860);
PPC_FUNC_IMPL(__imp__sub_8227B860) {
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
	// beq cr6,0x8227b904
	if (cr6.eq) goto loc_8227B904;
	// stb r5,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r5.u8);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227B890;
	sub_824E7008(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227b8cc
	if (cr6.eq) goto loc_8227B8CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x82388580
	ctx.lr = 0x8227B8A8;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227B8BC;
	sub_82270170(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x8227B8C8;
	sub_82274128(ctx, base);
	// b 0x8227b904
	goto loc_8227B904;
loc_8227B8CC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8227B8DC;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227b904
	if (cr6.eq) goto loc_8227B904;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227b160
	ctx.lr = 0x8227B904;
	sub_8227B160(ctx, base);
loc_8227B904:
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

__attribute__((alias("__imp__sub_8227B91C"))) PPC_WEAK_FUNC(sub_8227B91C);
PPC_FUNC_IMPL(__imp__sub_8227B91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227B920"))) PPC_WEAK_FUNC(sub_8227B920);
PPC_FUNC_IMPL(__imp__sub_8227B920) {
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
	// stb r4,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r4.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r5,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r5.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stb r6,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r6.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r7,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r7.u8);
	// stb r8,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r8.u8);
	// stb r9,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r9.u8);
	// bl 0x8227b2c0
	ctx.lr = 0x8227B954;
	sub_8227B2C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227B964"))) PPC_WEAK_FUNC(sub_8227B964);
PPC_FUNC_IMPL(__imp__sub_8227B964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227B968"))) PPC_WEAK_FUNC(sub_8227B968);
PPC_FUNC_IMPL(__imp__sub_8227B968) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8227B990;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8227b9b0
	if (cr6.eq) goto loc_8227B9B0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82275398
	ctx.lr = 0x8227B9AC;
	sub_82275398(ctx, base);
	// b 0x8227b9c0
	goto loc_8227B9C0;
loc_8227B9B0:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8227b3d0
	ctx.lr = 0x8227B9C0;
	sub_8227B3D0(ctx, base);
loc_8227B9C0:
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

__attribute__((alias("__imp__sub_8227B9D8"))) PPC_WEAK_FUNC(sub_8227B9D8);
PPC_FUNC_IMPL(__imp__sub_8227B9D8) {
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
	ctx.lr = 0x8227B9E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227B9F4;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bb88
	if (cr6.eq) goto loc_8227BB88;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227baec
	if (!cr6.eq) goto loc_8227BAEC;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8227BA18;
	sub_8226BA28(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227ba48
	if (!cr6.eq) goto loc_8227BA48;
	// bl 0x82388580
	ctx.lr = 0x8227BA28;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227BA38;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r3,11780(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11780);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227baec
	if (cr6.eq) goto loc_8227BAEC;
loc_8227BA48:
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8227ba74
	if (cr6.eq) goto loc_8227BA74;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// lwz r11,17892(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// b 0x8227ba80
	goto loc_8227BA80;
loc_8227BA74:
	// lwz r10,17892(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_8227BA80:
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227BA88;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227baec
	if (cr6.eq) goto loc_8227BAEC;
	// lwz r3,17892(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822b6308
	ctx.lr = 0x8227BAA0;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227baec
	if (cr6.eq) goto loc_8227BAEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227BAC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227baec
	if (cr6.eq) goto loc_8227BAEC;
	// li r11,1
	r11.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r11,4(r29)
	PPC_STORE_U8(r29.u32 + 4, r11.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b460
	ctx.lr = 0x8227BAEC;
	sub_8227B460(ctx, base);
loc_8227BAEC:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bb88
	if (cr6.eq) goto loc_8227BB88;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,17892(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227bb24
	if (cr6.eq) goto loc_8227BB24;
	// addi r11,r4,101
	r11.s64 = ctx.r4.s64 + 101;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r3
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// b 0x8227bb2c
	goto loc_8227BB2C;
loc_8227BB24:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r3
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
loc_8227BB2C:
	// bl 0x822b6308
	ctx.lr = 0x8227BB30;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bb88
	if (cr6.eq) goto loc_8227BB88;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227BB50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227bb88
	if (cr6.eq) goto loc_8227BB88;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-12632
	ctx.r6.s64 = r11.s64 + -12632;
	// addi r5,r10,-12656
	ctx.r5.s64 = ctx.r10.s64 + -12656;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8227BB7C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227bb88
	if (cr6.eq) goto loc_8227BB88;
	// bl 0x822a57d0
	ctx.lr = 0x8227BB88;
	sub_822A57D0(ctx, base);
loc_8227BB88:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227BB90"))) PPC_WEAK_FUNC(sub_8227BB90);
PPC_FUNC_IMPL(__imp__sub_8227BB90) {
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
	ctx.lr = 0x8227BB98;
	// stwu r1,-1600(r1)
	ea = -1600 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227BBB4;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c2c8
	if (cr6.eq) goto loc_8227C2C8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,15992
	ctx.r10.s64 = r11.s64 + 15992;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227bc10
	if (!cr6.eq) goto loc_8227BC10;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x822795a0
	ctx.lr = 0x8227BBE8;
	sub_822795A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bc04
	if (cr6.eq) goto loc_8227BC04;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82278260
	ctx.lr = 0x8227BC04;
	sub_82278260(ctx, base);
loc_8227BC04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BC10:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16088
	ctx.r10.s64 = r11.s64 + 16088;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227bc60
	if (!cr6.eq) goto loc_8227BC60;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82277100
	ctx.lr = 0x8227BC38;
	sub_82277100(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bc54
	if (cr6.eq) goto loc_8227BC54;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82278338
	ctx.lr = 0x8227BC54;
	sub_82278338(ctx, base);
loc_8227BC54:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BC60:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,16376
	r29.s64 = r11.s64 + 16376;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8227bcbc
	if (!cr6.eq) goto loc_8227BCBC;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x8229af08
	ctx.lr = 0x8227BC7C;
	sub_8229AF08(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x822772a0
	ctx.lr = 0x8227BC94;
	sub_822772A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bcb0
	if (cr6.eq) goto loc_8227BCB0;
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822783b8
	ctx.lr = 0x8227BCB0;
	sub_822783B8(ctx, base);
loc_8227BCB0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BCBC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,16664
	r29.s64 = r11.s64 + 16664;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8227bd2c
	if (!cr6.eq) goto loc_8227BD2C;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x82293e18
	ctx.lr = 0x8227BCD8;
	sub_82293E18(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82277440
	ctx.lr = 0x8227BCF0;
	sub_82277440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bd20
	if (cr6.eq) goto loc_8227BD20;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227BD0C;
	sub_822768E8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822750a8
	ctx.lr = 0x8227BD20;
	sub_822750A8(ctx, base);
loc_8227BD20:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BD2C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,16312
	r29.s64 = r11.s64 + 16312;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8227bda4
	if (!cr6.eq) goto loc_8227BDA4;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x82250410
	ctx.lr = 0x8227BD48;
	sub_82250410(ctx, base);
	// addi r3,r1,1520
	ctx.r3.s64 = ctx.r1.s64 + 1520;
	// bl 0x82293e18
	ctx.lr = 0x8227BD50;
	sub_82293E18(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x822775e0
	ctx.lr = 0x8227BD68;
	sub_822775E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bd98
	if (cr6.eq) goto loc_8227BD98;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227BD84;
	sub_822768E8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,1520
	ctx.r5.s64 = ctx.r1.s64 + 1520;
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82275110
	ctx.lr = 0x8227BD98;
	sub_82275110(ctx, base);
loc_8227BD98:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BDA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16536
	ctx.r10.s64 = r11.s64 + 16536;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227be04
	if (!cr6.eq) goto loc_8227BE04;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279688
	ctx.lr = 0x8227BDCC;
	sub_82279688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bdf8
	if (cr6.eq) goto loc_8227BDF8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227BDE8;
	sub_822768E8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82275398
	ctx.lr = 0x8227BDF8;
	sub_82275398(ctx, base);
loc_8227BDF8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BE04:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16600
	ctx.r10.s64 = r11.s64 + 16600;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227be50
	if (!cr6.eq) goto loc_8227BE50;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279830
	ctx.lr = 0x8227BE2C;
	sub_82279830(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227be44
	if (cr6.eq) goto loc_8227BE44;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82276438
	ctx.lr = 0x8227BE44;
	sub_82276438(ctx, base);
loc_8227BE44:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BE50:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r29,r11,16152
	r29.s64 = r11.s64 + 16152;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8227beb0
	if (!cr6.eq) goto loc_8227BEB0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824f0498
	ctx.lr = 0x8227BE6C;
	sub_824F0498(ctx, base);
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x824f0498
	ctx.lr = 0x8227BE74;
	sub_824F0498(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279918
	ctx.lr = 0x8227BE8C;
	sub_82279918(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bea4
	if (cr6.eq) goto loc_8227BEA4;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x8226f850
	ctx.lr = 0x8227BEA4;
	sub_8226F850(ctx, base);
loc_8227BEA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BEB0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16408
	ctx.r10.s64 = r11.s64 + 16408;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227befc
	if (!cr6.eq) goto loc_8227BEFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,85
	ctx.r3.s64 = ctx.r1.s64 + 85;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82277838
	ctx.lr = 0x8227BED8;
	sub_82277838(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bef0
	if (cr6.eq) goto loc_8227BEF0;
	// addi r4,r1,85
	ctx.r4.s64 = ctx.r1.s64 + 85;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822763e8
	ctx.lr = 0x8227BEF0;
	sub_822763E8(ctx, base);
loc_8227BEF0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BEFC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16248
	ctx.r10.s64 = r11.s64 + 16248;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227bf48
	if (!cr6.eq) goto loc_8227BF48;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279a00
	ctx.lr = 0x8227BF24;
	sub_82279A00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bf3c
	if (cr6.eq) goto loc_8227BF3C;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x8226c478
	ctx.lr = 0x8227BF3C;
	sub_8226C478(ctx, base);
loc_8227BF3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BF48:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16792
	ctx.r10.s64 = r11.s64 + 16792;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227bf94
	if (!cr6.eq) goto loc_8227BF94;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82299ed0
	ctx.lr = 0x8227BF70;
	sub_82299ED0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227bf88
	if (cr6.eq) goto loc_8227BF88;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x8226c550
	ctx.lr = 0x8227BF88;
	sub_8226C550(ctx, base);
loc_8227BF88:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227BF94:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16344
	ctx.r10.s64 = r11.s64 + 16344;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227c038
	if (!cr6.eq) goto loc_8227C038;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r28,0
	r28.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r28,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r28.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r28,137(r1)
	PPC_STORE_U8(ctx.r1.u32 + 137, r28.u8);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r28,138(r1)
	PPC_STORE_U8(ctx.r1.u32 + 138, r28.u8);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stb r10,139(r1)
	PPC_STORE_U8(ctx.r1.u32 + 139, ctx.r10.u8);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stw r28,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r28.u32);
	// stb r28,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r28.u8);
	// bl 0x822779e0
	ctx.lr = 0x8227BFEC;
	sub_822779E0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227c02c
	if (cr6.eq) goto loc_8227C02C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227C008;
	sub_822768E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8227C018;
	sub_82130000(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82275170
	ctx.lr = 0x8227C02C;
	sub_82275170(ctx, base);
loc_8227C02C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227C038:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16504
	ctx.r10.s64 = r11.s64 + 16504;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227c084
	if (!cr6.eq) goto loc_8227C084;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279af0
	ctx.lr = 0x8227C060;
	sub_82279AF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c078
	if (cr6.eq) goto loc_8227C078;
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8226c5b0
	ctx.lr = 0x8227C078;
	sub_8226C5B0(ctx, base);
loc_8227C078:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227C084:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16024
	ctx.r10.s64 = r11.s64 + 16024;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227c0d8
	if (!cr6.eq) goto loc_8227C0D8;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279be0
	ctx.lr = 0x8227C0AC;
	sub_82279BE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c0cc
	if (cr6.eq) goto loc_8227C0CC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b9d8
	ctx.lr = 0x8227C0CC;
	sub_8227B9D8(ctx, base);
loc_8227C0CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227C0D8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16760
	ctx.r10.s64 = r11.s64 + 16760;
	// lwz r26,8(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r26,r30
	cr6.compare<uint32_t>(r26.u32, r30.u32, xer);
	// bne cr6,0x8227c1a0
	if (!cr6.eq) goto loc_8227C1A0;
	// lwz r27,40(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r28,0
	r28.s64 = 0;
	// lwz r29,44(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82257678
	ctx.lr = 0x8227C10C;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82618750
	ctx.lr = 0x8227C118;
	sub_82618750(ctx, base);
	// subf r5,r30,r27
	ctx.r5.s64 = r27.s64 - r30.s64;
	// add r4,r30,r29
	ctx.r4.u64 = r30.u64 + r29.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x826185e0
	ctx.lr = 0x8227C128;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8227c140
	if (cr6.eq) goto loc_8227C140;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227c144
	if (cr6.eq) goto loc_8227C144;
loc_8227C140:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8227C144:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c168
	if (cr6.eq) goto loc_8227C168;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x826186b0
	ctx.lr = 0x8227C158;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x8227c168
	if (!cr6.eq) goto loc_8227C168;
	// li r28,1
	r28.s64 = 1;
loc_8227C168:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c194
	if (cr6.eq) goto loc_8227C194;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227C184;
	sub_822768E8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822751e0
	ctx.lr = 0x8227C194;
	sub_822751E0(ctx, base);
loc_8227C194:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227C1A0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16728
	ctx.r10.s64 = r11.s64 + 16728;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// bne cr6,0x8227c200
	if (!cr6.eq) goto loc_8227C200;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82277c38
	ctx.lr = 0x8227C1C8;
	sub_82277C38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c1f4
	if (cr6.eq) goto loc_8227C1F4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227C1E4;
	sub_822768E8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82275240
	ctx.lr = 0x8227C1F4;
	sub_82275240(ctx, base);
loc_8227C1F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227C200:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,16632
	ctx.r10.s64 = r11.s64 + 16632;
	// lwz r26,8(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r26,r30
	cr6.compare<uint32_t>(r26.u32, r30.u32, xer);
	// bne cr6,0x8227c2c8
	if (!cr6.eq) goto loc_8227C2C8;
	// lwz r27,40(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r28,0
	r28.s64 = 0;
	// lwz r29,44(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82257678
	ctx.lr = 0x8227C234;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82618750
	ctx.lr = 0x8227C240;
	sub_82618750(ctx, base);
	// subf r5,r30,r27
	ctx.r5.s64 = r27.s64 - r30.s64;
	// add r4,r30,r29
	ctx.r4.u64 = r30.u64 + r29.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x826185e0
	ctx.lr = 0x8227C250;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8227c268
	if (cr6.eq) goto loc_8227C268;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227c26c
	if (cr6.eq) goto loc_8227C26C;
loc_8227C268:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8227C26C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c290
	if (cr6.eq) goto loc_8227C290;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x826186b0
	ctx.lr = 0x8227C280;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x8227c290
	if (!cr6.eq) goto loc_8227C290;
	// li r28,1
	r28.s64 = 1;
loc_8227C290:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c2bc
	if (cr6.eq) goto loc_8227C2BC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822768e8
	ctx.lr = 0x8227C2AC;
	sub_822768E8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82275338
	ctx.lr = 0x8227C2BC;
	sub_82275338(ctx, base);
loc_8227C2BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
loc_8227C2C8:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8229a700
	ctx.lr = 0x8227C2D8;
	sub_8229A700(ctx, base);
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8227C2E0"))) PPC_WEAK_FUNC(sub_8227C2E0);
PPC_FUNC_IMPL(__imp__sub_8227C2E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8227C2E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,49
	r30.s64 = 49;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
loc_8227C2F8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229af08
	ctx.lr = 0x8227C300;
	sub_8229AF08(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,56
	r29.s64 = r29.s64 + 56;
	// bge 0x8227c2f8
	if (!cr0.lt) goto loc_8227C2F8;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,2812
	r29.s64 = r31.s64 + 2812;
	// stw r30,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, r30.u32);
	// li r28,49
	r28.s64 = 49;
	// stw r30,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r30.u32);
	// addi r27,r29,4
	r27.s64 = r29.s64 + 4;
	// stw r30,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r30.u32);
loc_8227C328:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8229af08
	ctx.lr = 0x8227C330;
	sub_8229AF08(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,56
	r27.s64 = r27.s64 + 56;
	// bge 0x8227c328
	if (!cr0.lt) goto loc_8227C328;
	// li r11,-1
	r11.s64 = -1;
	// stw r30,2808(r29)
	PPC_STORE_U32(r29.u32 + 2808, r30.u32);
	// stw r30,2804(r29)
	PPC_STORE_U32(r29.u32 + 2804, r30.u32);
	// addi r3,r31,5636
	ctx.r3.s64 = r31.s64 + 5636;
	// stw r30,2800(r29)
	PPC_STORE_U32(r29.u32 + 2800, r30.u32);
	// stw r30,5624(r31)
	PPC_STORE_U32(r31.u32 + 5624, r30.u32);
	// stw r11,5628(r31)
	PPC_STORE_U32(r31.u32 + 5628, r11.u32);
	// stw r30,5632(r31)
	PPC_STORE_U32(r31.u32 + 5632, r30.u32);
	// bl 0x824ebf78
	ctx.lr = 0x8227C360;
	sub_824EBF78(ctx, base);
	// stw r30,5664(r31)
	PPC_STORE_U32(r31.u32 + 5664, r30.u32);
	// stw r30,5668(r31)
	PPC_STORE_U32(r31.u32 + 5668, r30.u32);
	// addi r3,r31,5664
	ctx.r3.s64 = r31.s64 + 5664;
	// stw r30,5672(r31)
	PPC_STORE_U32(r31.u32 + 5672, r30.u32);
	// stw r30,5676(r31)
	PPC_STORE_U32(r31.u32 + 5676, r30.u32);
	// sth r30,5680(r31)
	PPC_STORE_U16(r31.u32 + 5680, r30.u16);
	// bl 0x824e7d20
	ctx.lr = 0x8227C37C;
	sub_824E7D20(ctx, base);
	// stw r30,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, r30.u32);
	// stw r30,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, r30.u32);
	// stw r30,2808(r29)
	PPC_STORE_U32(r29.u32 + 2808, r30.u32);
	// stw r30,2804(r29)
	PPC_STORE_U32(r29.u32 + 2804, r30.u32);
	// stw r30,2800(r29)
	PPC_STORE_U32(r29.u32 + 2800, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227C3A0"))) PPC_WEAK_FUNC(sub_8227C3A0);
PPC_FUNC_IMPL(__imp__sub_8227C3A0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8227C3A8;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227C3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x8227c73c
	if (!cr6.eq) goto loc_8227C73C;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82278698
	ctx.lr = 0x8227C3F4;
	sub_82278698(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,5628(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 5628);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8227c73c
	if (!cr6.eq) goto loc_8227C73C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82257678
	ctx.lr = 0x8227C414;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r10,16992
	ctx.r9.s64 = ctx.r10.s64 + 16992;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8227c564
	if (!cr6.eq) goto loc_8227C564;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,280
	ctx.r3.s64 = ctx.r1.s64 + 280;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279310
	ctx.lr = 0x8227C448;
	sub_82279310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x8229af08
	ctx.lr = 0x8227C45C;
	sub_8229AF08(ctx, base);
	// lhz r11,280(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 280);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r11,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, r11.u16);
	// bl 0x82278750
	ctx.lr = 0x8227C470;
	sub_82278750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// lwz r11,5620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5620);
	// li r29,0
	r29.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8227c73c
	if (!cr6.gt) goto loc_8227C73C;
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lhz r7,282(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 282);
	// lis r11,20971
	r11.s64 = 1374355456;
	// addi r31,r30,2812
	r31.s64 = r30.s64 + 2812;
	// ori r11,r11,34079
	r11.u64 = r11.u64 | 34079;
loc_8227C4A4:
	// lwz r10,2804(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2804);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// mulhw r4,r5,r11
	ctx.r4.s64 = (int64_t(ctx.r5.s32) * int64_t(r11.s32)) >> 32;
	// srawi r10,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 4;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r10,r3,50
	ctx.r10.s64 = ctx.r3.s64 * 50;
	// subf r8,r10,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r10.s64;
	// mulli r5,r8,56
	ctx.r5.s64 = ctx.r8.s64 * 56;
	// lhzx r4,r5,r31
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + r31.u32);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// bne cr6,0x8227c504
	if (!cr6.eq) goto loc_8227C504;
	// lwz r10,2804(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2804);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// mulhw r4,r5,r11
	ctx.r4.s64 = (int64_t(ctx.r5.s32) * int64_t(r11.s32)) >> 32;
	// srawi r10,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 4;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r10,r3,50
	ctx.r10.s64 = ctx.r3.s64 * 50;
	// subf r8,r10,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r10.s64;
	// mulli r10,r8,56
	ctx.r10.s64 = ctx.r8.s64 * 56;
	// add r29,r10,r31
	r29.u64 = ctx.r10.u64 + r31.u64;
loc_8227C504:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// blt cr6,0x8227c4a4
	if (cr6.lt) goto loc_8227C4A4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r29,4
	ctx.r4.s64 = r29.s64 + 4;
	// addi r3,r1,284
	ctx.r3.s64 = ctx.r1.s64 + 284;
	// bl 0x822754d8
	ctx.lr = 0x8227C528;
	sub_822754D8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822787f0
	ctx.lr = 0x8227C534;
	sub_822787F0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275448
	ctx.lr = 0x8227C540;
	sub_82275448(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227afd8
	ctx.lr = 0x8227C54C;
	sub_8227AFD8(ctx, base);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r3,r30,5664
	ctx.r3.s64 = r30.s64 + 5664;
	// lwz r4,5628(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 5628);
	// bl 0x824e7db8
	ctx.lr = 0x8227C55C;
	sub_824E7DB8(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d924c
	return;
loc_8227C564:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,17024
	ctx.r9.s64 = ctx.r10.s64 + 17024;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8227c600
	if (!cr6.eq) goto loc_8227C600;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82279170
	ctx.lr = 0x8227C58C;
	sub_82279170(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// bl 0x8229af08
	ctx.lr = 0x8227C5A0;
	sub_8229AF08(ctx, base);
	// lhz r11,224(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 224);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// addi r4,r1,228
	ctx.r4.s64 = ctx.r1.s64 + 228;
	// li r5,52
	ctx.r5.s64 = 52;
	// sth r11,160(r1)
	PPC_STORE_U16(ctx.r1.u32 + 160, r11.u16);
	// bl 0x823da950
	ctx.lr = 0x8227C5B8;
	sub_823DA950(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82278750
	ctx.lr = 0x8227C5C4;
	sub_82278750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r30,2812
	ctx.r3.s64 = r30.s64 + 2812;
	// bl 0x82275448
	ctx.lr = 0x8227C5DC;
	sub_82275448(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227afd8
	ctx.lr = 0x8227C5E8;
	sub_8227AFD8(ctx, base);
	// addi r5,r1,164
	ctx.r5.s64 = ctx.r1.s64 + 164;
	// addi r3,r30,5664
	ctx.r3.s64 = r30.s64 + 5664;
	// lwz r4,5628(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 5628);
	// bl 0x824e7db8
	ctx.lr = 0x8227C5F8;
	sub_824E7DB8(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d924c
	return;
loc_8227C600:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,17056
	ctx.r9.s64 = ctx.r10.s64 + 17056;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8227c73c
	if (!cr6.eq) goto loc_8227C73C;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,376
	ctx.r3.s64 = ctx.r1.s64 + 376;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x822794b0
	ctx.lr = 0x8227C628;
	sub_822794B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
	// lwz r11,2808(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2808);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8227c73c
	if (!cr6.gt) goto loc_8227C73C;
	// lwz r5,2804(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 2804);
	// lis r11,20971
	r11.s64 = 1374355456;
	// lhz r6,376(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 376);
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// ori r11,r11,34079
	r11.u64 = r11.u64 | 34079;
loc_8227C658:
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mulhw r3,r4,r11
	ctx.r3.s64 = (int64_t(ctx.r4.s32) * int64_t(r11.s32)) >> 32;
	// srawi r10,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 4;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r8,r10,50
	ctx.r8.s64 = ctx.r10.s64 * 50;
	// subf r4,r8,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r8.s64;
	// mulli r3,r4,56
	ctx.r3.s64 = ctx.r4.s64 * 56;
	// lhzx r10,r3,r30
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + r30.u32);
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// beq cr6,0x8227c6a0
	if (cr6.eq) goto loc_8227C6A0;
	// lwz r10,2808(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 2808);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// blt cr6,0x8227c658
	if (cr6.lt) goto loc_8227C658;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d924c
	return;
loc_8227C6A0:
	// add r10,r5,r7
	ctx.r10.u64 = ctx.r5.u64 + ctx.r7.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// mulhw r8,r9,r11
	ctx.r8.s64 = (int64_t(ctx.r9.s32) * int64_t(r11.s32)) >> 32;
	// srawi r11,r8,4
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	r11.s64 = ctx.r8.s32 >> 4;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mulli r6,r7,50
	ctx.r6.s64 = ctx.r7.s64 * 50;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// mulli r11,r5,56
	r11.s64 = ctx.r5.s64 * 56;
	// add. r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8227c73c
	if (cr0.eq) goto loc_8227C73C;
	// lwz r11,5624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5624);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c72c
	if (cr6.eq) goto loc_8227C72C;
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rlwinm r9,r11,25,7,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r8,r10,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// rlwinm r10,r10,0,25,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x8227c718
	if (cr6.eq) goto loc_8227C718;
	// subfc r9,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
loc_8227C718:
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,31
	r11.u64 = ctx.r8.u32 & 0x1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c73c
	if (cr6.eq) goto loc_8227C73C;
loc_8227C72C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822788b8
	ctx.lr = 0x8227C738;
	sub_822788B8(ctx, base);
	// stw r31,5624(r30)
	PPC_STORE_U32(r30.u32 + 5624, r31.u32);
loc_8227C73C:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227C744"))) PPC_WEAK_FUNC(sub_8227C744);
PPC_FUNC_IMPL(__imp__sub_8227C744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227C748"))) PPC_WEAK_FUNC(sub_8227C748);
PPC_FUNC_IMPL(__imp__sub_8227C748) {
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
	ctx.lr = 0x8227C750;
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
loc_8227C770:
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227c7c4
	if (cr6.eq) goto loc_8227C7C4;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x8227C784;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c7c4
	if (cr6.eq) goto loc_8227C7C4;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227c7c4
	if (!cr6.eq) goto loc_8227C7C4;
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
	// bl 0x8227b570
	ctx.lr = 0x8227C7B8;
	sub_8227B570(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_8227C7C4:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x8227c770
	if (!cr0.eq) goto loc_8227C770;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8227C7DC"))) PPC_WEAK_FUNC(sub_8227C7DC);
PPC_FUNC_IMPL(__imp__sub_8227C7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227C7E0"))) PPC_WEAK_FUNC(sub_8227C7E0);
PPC_FUNC_IMPL(__imp__sub_8227C7E0) {
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
	ctx.lr = 0x8227C7E8;
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
loc_8227C804:
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
	ctx.lr = 0x8227C81C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227c850
	if (cr6.eq) goto loc_8227C850;
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
	// beq cr6,0x8227c848
	if (cr6.eq) goto loc_8227C848;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8227c850
	if (!cr6.eq) goto loc_8227C850;
loc_8227C848:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227c854
	goto loc_8227C854;
loc_8227C850:
	// li r11,0
	r11.s64 = 0;
loc_8227C854:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c8d8
	if (cr6.eq) goto loc_8227C8D8;
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
	// blt cr6,0x8227c8c8
	if (cr6.lt) goto loc_8227C8C8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebb30
	ctx.lr = 0x8227C888;
	sub_824EBB30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227c8ac
	if (!cr6.eq) goto loc_8227C8AC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// bl 0x824ebc40
	ctx.lr = 0x8227C8A0;
	sub_824EBC40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227c8c8
	if (cr6.eq) goto loc_8227C8C8;
loc_8227C8AC:
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
	// bl 0x8227ab90
	ctx.lr = 0x8227C8C4;
	sub_8227AB90(ctx, base);
	// b 0x8227c8cc
	goto loc_8227C8CC;
loc_8227C8C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227C8CC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// and r25,r11,r10
	r25.u64 = r11.u64 & ctx.r10.u64;
loc_8227C8D8:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,31
	cr6.compare<int32_t>(r28.s32, 31, xer);
	// blt cr6,0x8227c804
	if (cr6.lt) goto loc_8227C804;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8227C8F0"))) PPC_WEAK_FUNC(sub_8227C8F0);
PPC_FUNC_IMPL(__imp__sub_8227C8F0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8227C914:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8227c914
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8227C914;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130000
	ctx.lr = 0x8227C940;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227C948;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227C95C;
	sub_82270170(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,208(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 208);
	// bl 0x8227c748
	ctx.lr = 0x8227C978;
	sub_8227C748(ctx, base);
	// lwz r7,0(r13)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r6,72
	ctx.r6.s64 = 72;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// lbzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x8227c9ac
	if (cr6.eq) goto loc_8227C9AC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8227c9c8
	if (!cr6.gt) goto loc_8227C9C8;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8227c9bc
	goto loc_8227C9BC;
loc_8227C9AC:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8227c9c8
	if (!cr6.gt) goto loc_8227C9C8;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8227C9BC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227c9cc
	if (!cr6.eq) goto loc_8227C9CC;
loc_8227C9C8:
	// li r11,0
	r11.s64 = 0;
loc_8227C9CC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ca04
	if (cr6.eq) goto loc_8227CA04;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x8227C9E0;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8227ca04
	if (cr6.eq) goto loc_8227CA04;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8227ca04
	if (cr6.eq) goto loc_8227CA04;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82342b70
	ctx.lr = 0x8227CA04;
	sub_82342B70(ctx, base);
loc_8227CA04:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227CA18"))) PPC_WEAK_FUNC(sub_8227CA18);
PPC_FUNC_IMPL(__imp__sub_8227CA18) {
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
	ctx.lr = 0x8227CA20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ba28
	ctx.lr = 0x8227CA40;
	sub_8226BA28(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8227ca74
	if (!cr6.eq) goto loc_8227CA74;
	// bl 0x82388580
	ctx.lr = 0x8227CA54;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227CA64;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r31,11780(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11780);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227cabc
	if (cr6.eq) goto loc_8227CABC;
loc_8227CA74:
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227CA7C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227cab0
	if (!cr6.eq) goto loc_8227CAB0;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b210
	ctx.lr = 0x8227CAA8;
	sub_8227B210(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8227CAB0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227b9d8
	ctx.lr = 0x8227CABC;
	sub_8227B9D8(ctx, base);
loc_8227CABC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227CAC4"))) PPC_WEAK_FUNC(sub_8227CAC4);
PPC_FUNC_IMPL(__imp__sub_8227CAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CAC8"))) PPC_WEAK_FUNC(sub_8227CAC8);
PPC_FUNC_IMPL(__imp__sub_8227CAC8) {
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
	ctx.lr = 0x8227CAD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x8227CAE8;
	sub_8226BF18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227cb74
	if (cr6.eq) goto loc_8227CB74;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17892
	r11.s64 = r11.s64 + 17892;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x8227cb28
	if (cr6.eq) goto loc_8227CB28;
	// addi r10,r4,101
	ctx.r10.s64 = ctx.r4.s64 + 101;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r3
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// b 0x8227cb30
	goto loc_8227CB30;
loc_8227CB28:
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r3
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
loc_8227CB30:
	// bl 0x822b6308
	ctx.lr = 0x8227CB34;
	sub_822B6308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227cb74
	if (cr6.eq) goto loc_8227CB74;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227CB54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227cb74
	if (cr6.eq) goto loc_8227CB74;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227c7e0
	ctx.lr = 0x8227CB74;
	sub_8227C7E0(ctx, base);
loc_8227CB74:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227CB7C"))) PPC_WEAK_FUNC(sub_8227CB7C);
PPC_FUNC_IMPL(__imp__sub_8227CB7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CB80"))) PPC_WEAK_FUNC(sub_8227CB80);
PPC_FUNC_IMPL(__imp__sub_8227CB80) {
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
	ctx.lr = 0x8227CB88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229b568
	ctx.lr = 0x8227CB9C;
	sub_8229B568(ctx, base);
	// addi r28,r31,8280
	r28.s64 = r31.s64 + 8280;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8229b568
	ctx.lr = 0x8227CBA8;
	sub_8229B568(ctx, base);
	// addi r27,r31,16556
	r27.s64 = r31.s64 + 16556;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227c2e0
	ctx.lr = 0x8227CBB4;
	sub_8227C2E0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,22260
	ctx.r3.s64 = r31.s64 + 22260;
	// stw r30,22240(r31)
	PPC_STORE_U32(r31.u32 + 22240, r30.u32);
	// addi r11,r31,22240
	r11.s64 = r31.s64 + 22240;
	// stw r30,22244(r31)
	PPC_STORE_U32(r31.u32 + 22244, r30.u32);
	// stw r30,22248(r31)
	PPC_STORE_U32(r31.u32 + 22248, r30.u32);
	// stw r30,22252(r31)
	PPC_STORE_U32(r31.u32 + 22252, r30.u32);
	// stw r30,22256(r31)
	PPC_STORE_U32(r31.u32 + 22256, r30.u32);
	// bl 0x8229aa70
	ctx.lr = 0x8227CBD8;
	sub_8229AA70(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// sth r30,22292(r31)
	PPC_STORE_U16(r31.u32 + 22292, r30.u16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229b450
	ctx.lr = 0x8227CBE8;
	sub_8229B450(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8229b450
	ctx.lr = 0x8227CBF0;
	sub_8229B450(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227a380
	ctx.lr = 0x8227CBF8;
	sub_8227A380(ctx, base);
	// lbz r10,22300(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 22300);
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,22296(r31)
	PPC_STORE_U32(r31.u32 + 22296, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,22300(r31)
	PPC_STORE_U8(r31.u32 + 22300, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227CC18"))) PPC_WEAK_FUNC(sub_8227CC18);
PPC_FUNC_IMPL(__imp__sub_8227CC18) {
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
	ctx.lr = 0x8227CC20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32216
	ctx.r10.s64 = -2111307776;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-15456
	ctx.r9.s64 = ctx.r10.s64 + -15456;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r4,5628(r31)
	PPC_STORE_U32(r31.u32 + 5628, ctx.r4.u32);
	// addi r30,r31,5636
	r30.s64 = r31.s64 + 5636;
	// stw r6,5632(r31)
	PPC_STORE_U32(r31.u32 + 5632, ctx.r6.u32);
	// stw r11,5624(r31)
	PPC_STORE_U32(r31.u32 + 5624, r11.u32);
	// sth r11,5680(r31)
	PPC_STORE_U16(r31.u32 + 5680, r11.u16);
	// stw r11,5636(r31)
	PPC_STORE_U32(r31.u32 + 5636, r11.u32);
	// stw r9,5640(r31)
	PPC_STORE_U32(r31.u32 + 5640, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x8227CC58;
	sub_82130000(ctx, base);
	// stw r3,5636(r31)
	PPC_STORE_U32(r31.u32 + 5636, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,5632(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5632);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824ec120
	ctx.lr = 0x8227CC6C;
	sub_824EC120(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227CC74"))) PPC_WEAK_FUNC(sub_8227CC74);
PPC_FUNC_IMPL(__imp__sub_8227CC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CC78"))) PPC_WEAK_FUNC(sub_8227CC78);
PPC_FUNC_IMPL(__imp__sub_8227CC78) {
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
	ctx.lr = 0x8227CC80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r31,r11,-9300
	r31.s64 = r11.s64 + -9300;
	// addi r28,r10,-9344
	r28.s64 = ctx.r10.s64 + -9344;
	// bl 0x82299898
	ctx.lr = 0x8227CCA0;
	sub_82299898(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8227CCB4;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227cd10
	if (cr6.eq) goto loc_8227CD10;
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227cd10
	if (cr6.eq) goto loc_8227CD10;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8227cd10
	if (!cr6.eq) goto loc_8227CD10;
	// addi r3,r11,16556
	ctx.r3.s64 = r11.s64 + 16556;
	// bl 0x8227a380
	ctx.lr = 0x8227CCDC;
	sub_8227A380(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,68(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// addi r3,r11,16556
	ctx.r3.s64 = r11.s64 + 16556;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8227cc18
	ctx.lr = 0x8227CCF4;
	sub_8227CC18(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r4,r11,22240
	ctx.r4.s64 = r11.s64 + 22240;
	// addi r3,r11,16556
	ctx.r3.s64 = r11.s64 + 16556;
	// bl 0x8227a3f8
	ctx.lr = 0x8227CD04;
	sub_8227A3F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227CD10:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227CD1C"))) PPC_WEAK_FUNC(sub_8227CD1C);
PPC_FUNC_IMPL(__imp__sub_8227CD1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CD20"))) PPC_WEAK_FUNC(sub_8227CD20);
PPC_FUNC_IMPL(__imp__sub_8227CD20) {
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
	// lis r11,2
	r11.s64 = 131072;
	// ori r10,r11,76
	ctx.r10.u64 = r11.u64 | 76;
	// lwzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// lwz r31,12(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lhz r8,6(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addis r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 65536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// sth r7,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, ctx.r7.u16);
	// stw r6,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r6.u32);
	// beq cr6,0x8227cd6c
	if (cr6.eq) goto loc_8227CD6C;
	// bl 0x8227cb80
	ctx.lr = 0x8227CD68;
	sub_8227CB80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227CD6C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227CD80"))) PPC_WEAK_FUNC(sub_8227CD80);
PPC_FUNC_IMPL(__imp__sub_8227CD80) {
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
	ctx.lr = 0x8227CD88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227cde4
	if (cr6.eq) goto loc_8227CDE4;
	// addi r29,r31,16556
	r29.s64 = r31.s64 + 16556;
	// addi r28,r29,5664
	r28.s64 = r29.s64 + 5664;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7d20
	ctx.lr = 0x8227CDAC;
	sub_824E7D20(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7cc8
	ctx.lr = 0x8227CDB4;
	sub_824E7CC8(ctx, base);
	// addi r3,r29,5636
	ctx.r3.s64 = r29.s64 + 5636;
	// bl 0x82130000
	ctx.lr = 0x8227CDBC;
	sub_82130000(ctx, base);
	// addi r3,r31,16472
	ctx.r3.s64 = r31.s64 + 16472;
	// bl 0x82500d60
	ctx.lr = 0x8227CDC4;
	sub_82500D60(ctx, base);
	// addi r3,r31,8196
	ctx.r3.s64 = r31.s64 + 8196;
	// bl 0x82500d60
	ctx.lr = 0x8227CDCC;
	sub_82500D60(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// sth r10,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r10.u16);
loc_8227CDE4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227CDEC"))) PPC_WEAK_FUNC(sub_8227CDEC);
PPC_FUNC_IMPL(__imp__sub_8227CDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CDF0"))) PPC_WEAK_FUNC(sub_8227CDF0);
PPC_FUNC_IMPL(__imp__sub_8227CDF0) {
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
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227ce18
	if (!cr6.eq) goto loc_8227CE18;
	// bl 0x8227cd20
	ctx.lr = 0x8227CE14;
	sub_8227CD20(ctx, base);
	// stw r3,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r3.u32);
loc_8227CE18:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227CE2C"))) PPC_WEAK_FUNC(sub_8227CE2C);
PPC_FUNC_IMPL(__imp__sub_8227CE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CE30"))) PPC_WEAK_FUNC(sub_8227CE30);
PPC_FUNC_IMPL(__imp__sub_8227CE30) {
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
	ctx.lr = 0x8227CE38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r9,220
	ctx.r9.s64 = 220;
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addis r8,r11,-2
	ctx.r8.s64 = r11.s64 + -131072;
	// addi r8,r8,-80
	ctx.r8.s64 = ctx.r8.s64 + -80;
	// divw r31,r8,r9
	r31.s32 = ctx.r8.s32 / ctx.r9.s32;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8227CE68;
	sub_821E80F8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8227ce7c
	if (cr6.eq) goto loc_8227CE7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cad80
	ctx.lr = 0x8227CE7C;
	sub_822CAD80(ctx, base);
loc_8227CE7C:
	// mulli r11,r31,220
	r11.s64 = r31.s64 * 220;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r29,0
	r29.s64 = 0;
	// addis r31,r11,2
	r31.s64 = r11.s64 + 131072;
	// addi r31,r31,292
	r31.s64 = r31.s64 + 292;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ceb8
	if (cr6.eq) goto loc_8227CEB8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227ceb8
	if (cr6.eq) goto loc_8227CEB8;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x82238408
	ctx.lr = 0x8227CEB0;
	sub_82238408(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
loc_8227CEB8:
	// lwz r31,212(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227cee4
	if (cr6.eq) goto loc_8227CEE4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227acc8
	ctx.lr = 0x8227CECC;
	sub_8227ACC8(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r10,r11,76
	ctx.r10.u64 = r11.u64 | 76;
	// lwzx r3,r30,r10
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// bl 0x8227cd80
	ctx.lr = 0x8227CEE0;
	sub_8227CD80(ctx, base);
	// stw r29,212(r28)
	PPC_STORE_U32(r28.u32 + 212, r29.u32);
loc_8227CEE4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227CEEC"))) PPC_WEAK_FUNC(sub_8227CEEC);
PPC_FUNC_IMPL(__imp__sub_8227CEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227CEF0"))) PPC_WEAK_FUNC(sub_8227CEF0);
PPC_FUNC_IMPL(__imp__sub_8227CEF0) {
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
	ctx.lr = 0x8227CEF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lbz r11,279(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227cf3c
	if (cr6.eq) goto loc_8227CF3C;
	// lbz r11,280(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227cf34
	if (!cr6.eq) goto loc_8227CF34;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227CF28;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227cf3c
	if (cr6.eq) goto loc_8227CF3C;
loc_8227CF34:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227cf40
	goto loc_8227CF40;
loc_8227CF3C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8227CF40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d094
	if (cr6.eq) goto loc_8227D094;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822051a0
	ctx.lr = 0x8227CF58;
	sub_822051A0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8227d094
	if (cr6.lt) goto loc_8227D094;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bge cr6,0x8227d094
	if (!cr6.lt) goto loc_8227D094;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mulli r11,r31,220
	r11.s64 = r31.s64 * 220;
	// lwz r30,17268(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// add r9,r11,r26
	ctx.r9.u64 = r11.u64 + r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addis r29,r9,2
	r29.s64 = ctx.r9.s64 + 131072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// mr r27,r25
	r27.u64 = r25.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8227CF94;
	sub_821E80F8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8227cfb8
	if (cr6.eq) goto loc_8227CFB8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8227CFAC;
	sub_822A3998(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822a8e10
	ctx.lr = 0x8227CFB8;
	sub_822A8E10(ctx, base);
loc_8227CFB8:
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227cfe0
	if (cr6.eq) goto loc_8227CFE0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227cfe0
	if (cr6.eq) goto loc_8227CFE0;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x82238408
	ctx.lr = 0x8227CFD8;
	sub_82238408(ctx, base);
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
loc_8227CFE0:
	// li r11,1
	r11.s64 = 1;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stb r11,278(r28)
	PPC_STORE_U8(r28.u32 + 278, r11.u8);
	// mr r30,r25
	r30.u64 = r25.u64;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227CFF8;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227d070
	if (cr6.eq) goto loc_8227D070;
	// bl 0x82292970
	ctx.lr = 0x8227D008;
	sub_82292970(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d030
	if (cr6.eq) goto loc_8227D030;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82280280
	ctx.lr = 0x8227D020;
	sub_82280280(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r30,r10,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x8227d070
	goto loc_8227D070;
loc_8227D030:
	// bl 0x822912c8
	ctx.lr = 0x8227D034;
	sub_822912C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d068
	if (cr6.eq) goto loc_8227D068;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82291a20
	ctx.lr = 0x8227D048;
	sub_82291A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d068
	if (cr6.eq) goto loc_8227D068;
	// bl 0x822923d8
	ctx.lr = 0x8227D058;
	sub_822923D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227d06c
	if (cr6.eq) goto loc_8227D06C;
loc_8227D068:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8227D06C:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_8227D070:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d084
	if (cr6.eq) goto loc_8227D084;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82291ef0
	ctx.lr = 0x8227D084;
	sub_82291EF0(ctx, base);
loc_8227D084:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x82622c68
	ctx.lr = 0x8227D094;
	sub_82622C68(ctx, base);
loc_8227D094:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822999e0
	ctx.lr = 0x8227D0A0;
	sub_822999E0(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227D0B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,212(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227d0e8
	if (cr6.eq) goto loc_8227D0E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227acc8
	ctx.lr = 0x8227D0D0;
	sub_8227ACC8(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r10,r11,76
	ctx.r10.u64 = r11.u64 | 76;
	// lwzx r3,r26,r10
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// bl 0x8227cd80
	ctx.lr = 0x8227D0E4;
	sub_8227CD80(ctx, base);
	// stw r25,212(r30)
	PPC_STORE_U32(r30.u32 + 212, r25.u32);
loc_8227D0E8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8227D0F0"))) PPC_WEAK_FUNC(sub_8227D0F0);
PPC_FUNC_IMPL(__imp__sub_8227D0F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwimi r11,r10,0,25,31
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x7F) | (r11.u64 & 0xFFFFFFFFFFFFFF80);
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r6,r7,0,25,25
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x40) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// stb r6,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r6.u8);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r10,r11,0,26,26
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r6,r7,0,27,27
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x10) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFEF);
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// stb r6,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r6.u8);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r10,r11,0,28,28
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x8) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFF7);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r6,r7,0,29,29
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x4) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// stb r6,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r6.u8);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r10,r11,0,30,30
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x2) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFD);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r7,r6,0,24,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0xFE) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFF01);
	// stb r7,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r7.u8);
	// lbz r11,1(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rlwimi r9,r11,0,24,24
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x80) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFF7F);
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stb r10,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r10.u8);
	// lbz r8,1(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rlwimi r9,r8,0,25,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0x40) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stb r7,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r7.u8);
	// lbz r5,1(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rlwimi r6,r5,0,26,26
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x20) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r6,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D1AC"))) PPC_WEAK_FUNC(sub_8227D1AC);
PPC_FUNC_IMPL(__imp__sub_8227D1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D1B0"))) PPC_WEAK_FUNC(sub_8227D1B0);
PPC_FUNC_IMPL(__imp__sub_8227D1B0) {
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
	// bl 0x8227d0f0
	ctx.lr = 0x8227D1D0;
	sub_8227D0F0(ctx, base);
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
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// lbz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// stb r7,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r7.u8);
	// lbz r6,21(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 21);
	// stb r6,21(r31)
	PPC_STORE_U8(r31.u32 + 21, ctx.r6.u8);
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8227D224"))) PPC_WEAK_FUNC(sub_8227D224);
PPC_FUNC_IMPL(__imp__sub_8227D224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D228"))) PPC_WEAK_FUNC(sub_8227D228);
PPC_FUNC_IMPL(__imp__sub_8227D228) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227D24C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227d26c
	if (cr6.eq) goto loc_8227D26C;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227D26C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8227D26C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227D280"))) PPC_WEAK_FUNC(sub_8227D280);
PPC_FUNC_IMPL(__imp__sub_8227D280) {
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
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8227d2b4
	if (cr6.eq) goto loc_8227D2B4;
	// bl 0x82130588
	ctx.lr = 0x8227D2B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227D2B4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227D2C8"))) PPC_WEAK_FUNC(sub_8227D2C8);
PPC_FUNC_IMPL(__imp__sub_8227D2C8) {
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
	// addi r9,r11,68
	ctx.r9.s64 = r11.s64 + 68;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8227d2fc
	if (cr6.eq) goto loc_8227D2FC;
	// bl 0x82130588
	ctx.lr = 0x8227D2F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227D2FC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8227D310"))) PPC_WEAK_FUNC(sub_8227D310);
PPC_FUNC_IMPL(__imp__sub_8227D310) {
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
	ctx.lr = 0x8227D318;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// addi r4,r10,164
	ctx.r4.s64 = ctx.r10.s64 + 164;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r31,152
	r29.s64 = r31.s64 + 152;
	// addi r28,r31,988
	r28.s64 = r31.s64 + 988;
	// bl 0x82294ff0
	ctx.lr = 0x8227D344;
	sub_82294FF0(ctx, base);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x8227d368
	if (!cr6.eq) goto loc_8227D368;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,152
	ctx.r5.s64 = r11.s64 + 152;
	// addi r4,r10,140
	ctx.r4.s64 = ctx.r10.s64 + 140;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82294ff0
	ctx.lr = 0x8227D368;
	sub_82294FF0(ctx, base);
loc_8227D368:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8227d37c
	if (!cr6.eq) goto loc_8227D37C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r11.u32);
loc_8227D37C:
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8227d394
	if (!cr6.eq) goto loc_8227D394;
	// li r11,1
	r11.s64 = 1;
	// stw r11,72(r28)
	PPC_STORE_U32(r28.u32 + 72, r11.u32);
loc_8227D394:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227D39C"))) PPC_WEAK_FUNC(sub_8227D39C);
PPC_FUNC_IMPL(__imp__sub_8227D39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D3A0"))) PPC_WEAK_FUNC(sub_8227D3A0);
PPC_FUNC_IMPL(__imp__sub_8227D3A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// b 0x8226be68
	sub_8226BE68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8227D3AC"))) PPC_WEAK_FUNC(sub_8227D3AC);
PPC_FUNC_IMPL(__imp__sub_8227D3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D3B0"))) PPC_WEAK_FUNC(sub_8227D3B0);
PPC_FUNC_IMPL(__imp__sub_8227D3B0) {
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
	// li r11,16
	r11.s64 = 16;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,8960
	ctx.r3.s64 = ctx.r10.s64 + 8960;
	// bl 0x821c0750
	ctx.lr = 0x8227D3D4;
	sub_821C0750(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D3E8"))) PPC_WEAK_FUNC(sub_8227D3E8);
PPC_FUNC_IMPL(__imp__sub_8227D3E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x8227d408
	if (cr6.eq) goto loc_8227D408;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x8227d404
	if (cr6.eq) goto loc_8227D404;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227D404:
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
loc_8227D408:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D410"))) PPC_WEAK_FUNC(sub_8227D410);
PPC_FUNC_IMPL(__imp__sub_8227D410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,84
	ctx.r3.s64 = r11.s64 + 84;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D41C"))) PPC_WEAK_FUNC(sub_8227D41C);
PPC_FUNC_IMPL(__imp__sub_8227D41C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D420"))) PPC_WEAK_FUNC(sub_8227D420);
PPC_FUNC_IMPL(__imp__sub_8227D420) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bgt cr6,0x8227d454
	if (cr6.gt) goto loc_8227D454;
	// beq cr6,0x8227d44c
	if (cr6.eq) goto loc_8227D44C;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8227d444
	if (cr6.eq) goto loc_8227D444;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8227d464
	if (!cr6.eq) goto loc_8227D464;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227D444:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227D44C:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227D454:
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// beq cr6,0x8227d474
	if (cr6.eq) goto loc_8227D474;
	// cmplwi cr6,r4,65534
	cr6.compare<uint32_t>(ctx.r4.u32, 65534, xer);
	// beq cr6,0x8227d46c
	if (cr6.eq) goto loc_8227D46C;
loc_8227D464:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227D46C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227D474:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D47C"))) PPC_WEAK_FUNC(sub_8227D47C);
PPC_FUNC_IMPL(__imp__sub_8227D47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D480"))) PPC_WEAK_FUNC(sub_8227D480);
PPC_FUNC_IMPL(__imp__sub_8227D480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8227d4e0
	if (cr6.gt) {
		sub_8227D4E0(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-11104
	r12.s64 = r12.s64 + -11104;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227D4B4;
	case 1:
		goto loc_8227D4C0;
	case 2:
		goto loc_8227D4C8;
	case 3:
		goto loc_8227D4D0;
	case 4:
		goto loc_8227D4D8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-11084(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11084);
	// lwz r17,-11072(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11072);
	// lwz r17,-11064(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11064);
	// lwz r17,-11056(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11056);
	// lwz r17,-11048(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11048);
loc_8227D4B4:
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65534
	ctx.r3.u64 = ctx.r3.u64 | 65534;
	// blr 
	return;
loc_8227D4C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227D4C8:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227D4D0:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227D4D8:
	// li r3,4
	ctx.r3.s64 = 4;
}

__attribute__((alias("__imp__sub_8227D4E0"))) PPC_WEAK_FUNC(sub_8227D4E0);
PPC_FUNC_IMPL(__imp__sub_8227D4E0) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D4E8"))) PPC_WEAK_FUNC(sub_8227D4E8);
PPC_FUNC_IMPL(__imp__sub_8227D4E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8227d52c
	if (cr6.gt) {
		sub_8227D52C(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-11000
	r12.s64 = r12.s64 + -11000;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227D51C;
	case 1:
		goto loc_8227D524;
	case 2:
		goto loc_8227D524;
	case 3:
		goto loc_8227D524;
	case 4:
		goto loc_8227D524;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10980(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10980);
	// lwz r17,-10972(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10972);
	// lwz r17,-10972(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10972);
	// lwz r17,-10972(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10972);
	// lwz r17,-10972(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10972);
loc_8227D51C:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8227D524:
	// li r3,4
	ctx.r3.s64 = 4;
}

__attribute__((alias("__imp__sub_8227D52C"))) PPC_WEAK_FUNC(sub_8227D52C);
PPC_FUNC_IMPL(__imp__sub_8227D52C) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D534"))) PPC_WEAK_FUNC(sub_8227D534);
PPC_FUNC_IMPL(__imp__sub_8227D534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D538"))) PPC_WEAK_FUNC(sub_8227D538);
PPC_FUNC_IMPL(__imp__sub_8227D538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8227d57c
	if (cr6.gt) {
		sub_8227D57C(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10920
	r12.s64 = r12.s64 + -10920;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227D56C;
	case 1:
		goto loc_8227D574;
	case 2:
		goto loc_8227D574;
	case 3:
		goto loc_8227D574;
	case 4:
		goto loc_8227D574;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10900(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10900);
	// lwz r17,-10892(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10892);
	// lwz r17,-10892(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10892);
	// lwz r17,-10892(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10892);
	// lwz r17,-10892(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10892);
loc_8227D56C:
	// li r11,2
	r11.s64 = 2;
	// b 0x8227d580
	sub_8227D580(ctx, base);
	return;
loc_8227D574:
	// li r11,1
	r11.s64 = 1;
}

__attribute__((alias("__imp__sub_8227D57C"))) PPC_WEAK_FUNC(sub_8227D57C);
PPC_FUNC_IMPL(__imp__sub_8227D57C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// li r11,-1
	r11.s64 = -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8227d5d8
	if (cr6.gt) goto loc_8227D5D8;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10844
	r12.s64 = r12.s64 + -10844;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8227D5B8;
	case 1:
		goto loc_8227D5C0;
	case 2:
		goto loc_8227D5D0;
	case 3:
		goto loc_8227D5D8;
	case 4:
		goto loc_8227D5C8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10824);
	// lwz r17,-10816(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10816);
	// lwz r17,-10800(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10800);
	// lwz r17,-10792(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10792);
	// lwz r17,-10808(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10808);
loc_8227D5B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227D5C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227D5C8:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227D5D0:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227D5D8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D580"))) PPC_WEAK_FUNC(sub_8227D580);
PPC_FUNC_IMPL(__imp__sub_8227D580) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
}

__attribute__((alias("__imp__sub_8227D5E0"))) PPC_WEAK_FUNC(sub_8227D5E0);
PPC_FUNC_IMPL(__imp__sub_8227D5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,108
	ctx.r3.s64 = r11.s64 + 108;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D5EC"))) PPC_WEAK_FUNC(sub_8227D5EC);
PPC_FUNC_IMPL(__imp__sub_8227D5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D5F0"))) PPC_WEAK_FUNC(sub_8227D5F0);
PPC_FUNC_IMPL(__imp__sub_8227D5F0) {
	PPC_FUNC_PROLOGUE();
	// lis r3,-2
	ctx.r3.s64 = -131072;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D5F8"))) PPC_WEAK_FUNC(sub_8227D5F8);
PPC_FUNC_IMPL(__imp__sub_8227D5F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// addi r11,r4,-61
	r11.s64 = ctx.r4.s64 + -61;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8227d64c
	if (cr6.gt) {
		sub_8227D64C(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10724
	r12.s64 = r12.s64 + -10724;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8227D62C;
	case 1:
		goto loc_8227D634;
	case 2:
		goto loc_8227D63C;
	case 3:
		goto loc_8227D644;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10708(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10708);
	// lwz r17,-10700(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10700);
	// lwz r17,-10692(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10692);
	// lwz r17,-10684(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10684);
loc_8227D62C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227D634:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227D63C:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227D644:
	// li r3,3
	ctx.r3.s64 = 3;
}

__attribute__((alias("__imp__sub_8227D64C"))) PPC_WEAK_FUNC(sub_8227D64C);
PPC_FUNC_IMPL(__imp__sub_8227D64C) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D654"))) PPC_WEAK_FUNC(sub_8227D654);
PPC_FUNC_IMPL(__imp__sub_8227D654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D658"))) PPC_WEAK_FUNC(sub_8227D658);
PPC_FUNC_IMPL(__imp__sub_8227D658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227d6a8
	if (cr6.gt) {
		sub_8227D6A8(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10632
	r12.s64 = r12.s64 + -10632;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227D688;
	case 1:
		goto loc_8227D690;
	case 2:
		goto loc_8227D698;
	case 3:
		goto loc_8227D6A0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10616(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10616);
	// lwz r17,-10608(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10608);
	// lwz r17,-10600(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10600);
	// lwz r17,-10592(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10592);
loc_8227D688:
	// li r3,61
	ctx.r3.s64 = 61;
	// blr 
	return;
loc_8227D690:
	// li r3,62
	ctx.r3.s64 = 62;
	// blr 
	return;
loc_8227D698:
	// li r3,63
	ctx.r3.s64 = 63;
	// blr 
	return;
loc_8227D6A0:
	// li r3,64
	ctx.r3.s64 = 64;
}

__attribute__((alias("__imp__sub_8227D6A8"))) PPC_WEAK_FUNC(sub_8227D6A8);
PPC_FUNC_IMPL(__imp__sub_8227D6A8) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D6B0"))) PPC_WEAK_FUNC(sub_8227D6B0);
PPC_FUNC_IMPL(__imp__sub_8227D6B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227d6e8
	if (cr6.gt) {
		sub_8227D6E8(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10544
	r12.s64 = r12.s64 + -10544;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227D6E0;
	case 1:
		goto loc_8227D6E0;
	case 2:
		goto loc_8227D6E0;
	case 3:
		goto loc_8227D6E0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10528(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10528);
	// lwz r17,-10528(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10528);
	// lwz r17,-10528(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10528);
	// lwz r17,-10528(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10528);
loc_8227D6E0:
	// li r3,8
	ctx.r3.s64 = 8;
}

__attribute__((alias("__imp__sub_8227D6E8"))) PPC_WEAK_FUNC(sub_8227D6E8);
PPC_FUNC_IMPL(__imp__sub_8227D6E8) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D6F0"))) PPC_WEAK_FUNC(sub_8227D6F0);
PPC_FUNC_IMPL(__imp__sub_8227D6F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227d730
	if (cr6.gt) {
		sub_8227D730(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10480
	r12.s64 = r12.s64 + -10480;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227D720;
	case 1:
		goto loc_8227D720;
	case 2:
		goto loc_8227D728;
	case 3:
		goto loc_8227D728;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10464(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10464);
	// lwz r17,-10464(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10464);
	// lwz r17,-10456(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10456);
	// lwz r17,-10456(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10456);
loc_8227D720:
	// li r11,2
	r11.s64 = 2;
	// b 0x8227d734
	sub_8227D734(ctx, base);
	return;
loc_8227D728:
	// li r11,3
	r11.s64 = 3;
}

__attribute__((alias("__imp__sub_8227D730"))) PPC_WEAK_FUNC(sub_8227D730);
PPC_FUNC_IMPL(__imp__sub_8227D730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// li r11,-1
	r11.s64 = -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8227d78c
	if (cr6.gt) goto loc_8227D78C;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10408
	r12.s64 = r12.s64 + -10408;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8227D76C;
	case 1:
		goto loc_8227D774;
	case 2:
		goto loc_8227D784;
	case 3:
		goto loc_8227D78C;
	case 4:
		goto loc_8227D77C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10388(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10388);
	// lwz r17,-10380(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10380);
	// lwz r17,-10364(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10364);
	// lwz r17,-10356(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10356);
	// lwz r17,-10372(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10372);
loc_8227D76C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227D774:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227D77C:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227D784:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227D78C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D734"))) PPC_WEAK_FUNC(sub_8227D734);
PPC_FUNC_IMPL(__imp__sub_8227D734) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
}

__attribute__((alias("__imp__sub_8227D794"))) PPC_WEAK_FUNC(sub_8227D794);
PPC_FUNC_IMPL(__imp__sub_8227D794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227D798"))) PPC_WEAK_FUNC(sub_8227D798);
PPC_FUNC_IMPL(__imp__sub_8227D798) {
	PPC_FUNC_PROLOGUE();
	// li r3,61
	ctx.r3.s64 = 61;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D7A0"))) PPC_WEAK_FUNC(sub_8227D7A0);
PPC_FUNC_IMPL(__imp__sub_8227D7A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// bgt cr6,0x8227d830
	if (cr6.gt) {
		sub_8227D830(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10296
	r12.s64 = r12.s64 + -10296;
	// rlwinm r0,r6,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r6.u64) {
	case 0:
		goto loc_8227D7D8;
	case 1:
		goto loc_8227D7F4;
	case 2:
		goto loc_8227D824;
	case 3:
		goto loc_8227D810;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10280(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10280);
	// lwz r17,-10252(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10252);
	// lwz r17,-10204(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10204);
	// lwz r17,-10224(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10224);
loc_8227D7D8:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8227d7ec
	if (cr6.lt) goto loc_8227D7EC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8227D7EC:
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8227D7F4:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8227d7ec
	if (cr6.gt) goto loc_8227D7EC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8227D810:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8227D824:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
}

__attribute__((alias("__imp__sub_8227D830"))) PPC_WEAK_FUNC(sub_8227D830);
PPC_FUNC_IMPL(__imp__sub_8227D830) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D838"))) PPC_WEAK_FUNC(sub_8227D838);
PPC_FUNC_IMPL(__imp__sub_8227D838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// bgt cr6,0x8227d8c8
	if (cr6.gt) {
		sub_8227D8C8(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-10144
	r12.s64 = r12.s64 + -10144;
	// rlwinm r0,r6,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r6.u64) {
	case 0:
		goto loc_8227D870;
	case 1:
		goto loc_8227D88C;
	case 2:
		goto loc_8227D8BC;
	case 3:
		goto loc_8227D8A8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-10128(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10128);
	// lwz r17,-10100(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10100);
	// lwz r17,-10052(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10052);
	// lwz r17,-10072(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10072);
loc_8227D870:
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpd cr6,r11,r10
	cr6.compare<int64_t>(r11.s64, ctx.r10.s64, xer);
	// blt cr6,0x8227d884
	if (cr6.lt) goto loc_8227D884;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8227D884:
	// std r11,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, r11.u64);
	// blr 
	return;
loc_8227D88C:
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpd cr6,r11,r10
	cr6.compare<int64_t>(r11.s64, ctx.r10.s64, xer);
	// bgt cr6,0x8227d884
	if (cr6.gt) goto loc_8227D884;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// std r11,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, r11.u64);
	// blr 
	return;
loc_8227D8A8:
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// std r11,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, r11.u64);
	// blr 
	return;
loc_8227D8BC:
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
}

__attribute__((alias("__imp__sub_8227D8C8"))) PPC_WEAK_FUNC(sub_8227D8C8);
PPC_FUNC_IMPL(__imp__sub_8227D8C8) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D8D0"))) PPC_WEAK_FUNC(sub_8227D8D0);
PPC_FUNC_IMPL(__imp__sub_8227D8D0) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r6,3
	cr6.compare<uint32_t>(ctx.r6.u32, 3, xer);
	// bgt cr6,0x8227d960
	if (cr6.gt) {
		sub_8227D960(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-9992
	r12.s64 = r12.s64 + -9992;
	// rlwinm r0,r6,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r6.u64) {
	case 0:
		goto loc_8227D908;
	case 1:
		goto loc_8227D924;
	case 2:
		goto loc_8227D954;
	case 3:
		goto loc_8227D940;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-9976(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9976);
	// lwz r17,-9948(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9948);
	// lwz r17,-9900(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9900);
	// lwz r17,-9920(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9920);
loc_8227D908:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8227d91c
	if (cr6.lt) goto loc_8227D91C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8227D91C:
	// stfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
loc_8227D924:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8227d91c
	if (cr6.gt) goto loc_8227D91C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
loc_8227D940:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,0(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
loc_8227D954:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
}

__attribute__((alias("__imp__sub_8227D960"))) PPC_WEAK_FUNC(sub_8227D960);
PPC_FUNC_IMPL(__imp__sub_8227D960) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227D968"))) PPC_WEAK_FUNC(sub_8227D968);
PPC_FUNC_IMPL(__imp__sub_8227D968) {
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
	ctx.lr = 0x8227D970;
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
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d9b4
	if (cr6.eq) goto loc_8227D9B4;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227d9ac
	if (!cr6.eq) goto loc_8227D9AC;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227D9A0;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227d9b4
	if (cr6.eq) goto loc_8227D9B4;
loc_8227D9AC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227d9b8
	goto loc_8227D9B8;
loc_8227D9B4:
	// li r11,0
	r11.s64 = 0;
loc_8227D9B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227d9ec
	if (!cr6.eq) goto loc_8227D9EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,8788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8788);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8227d9ec
	if (cr6.eq) goto loc_8227D9EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8227D9EC:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x822728c0
	ctx.lr = 0x8227D9FC;
	sub_822728C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227DA04"))) PPC_WEAK_FUNC(sub_8227DA04);
PPC_FUNC_IMPL(__imp__sub_8227DA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DA08"))) PPC_WEAK_FUNC(sub_8227DA08);
PPC_FUNC_IMPL(__imp__sub_8227DA08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DA14"))) PPC_WEAK_FUNC(sub_8227DA14);
PPC_FUNC_IMPL(__imp__sub_8227DA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DA18"))) PPC_WEAK_FUNC(sub_8227DA18);
PPC_FUNC_IMPL(__imp__sub_8227DA18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bgt cr6,0x8227da4c
	if (cr6.gt) goto loc_8227DA4C;
	// beq cr6,0x8227da44
	if (cr6.eq) goto loc_8227DA44;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8227da3c
	if (cr6.eq) goto loc_8227DA3C;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8227da54
	if (!cr6.eq) goto loc_8227DA54;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227DA3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227DA44:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227DA4C:
	// cmplwi cr6,r4,65534
	cr6.compare<uint32_t>(ctx.r4.u32, 65534, xer);
	// beq cr6,0x8227da5c
	if (cr6.eq) goto loc_8227DA5C;
loc_8227DA54:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227DA5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DA64"))) PPC_WEAK_FUNC(sub_8227DA64);
PPC_FUNC_IMPL(__imp__sub_8227DA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DA68"))) PPC_WEAK_FUNC(sub_8227DA68);
PPC_FUNC_IMPL(__imp__sub_8227DA68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227dabc
	if (cr6.gt) {
		sub_8227DABC(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-9592
	r12.s64 = r12.s64 + -9592;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227DA98;
	case 1:
		goto loc_8227DAA4;
	case 2:
		goto loc_8227DAAC;
	case 3:
		goto loc_8227DAB4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-9576(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9576);
	// lwz r17,-9564(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9564);
	// lwz r17,-9556(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9556);
	// lwz r17,-9548(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9548);
loc_8227DA98:
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65534
	ctx.r3.u64 = ctx.r3.u64 | 65534;
	// blr 
	return;
loc_8227DAA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227DAAC:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227DAB4:
	// li r3,3
	ctx.r3.s64 = 3;
}

__attribute__((alias("__imp__sub_8227DABC"))) PPC_WEAK_FUNC(sub_8227DABC);
PPC_FUNC_IMPL(__imp__sub_8227DABC) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DAC4"))) PPC_WEAK_FUNC(sub_8227DAC4);
PPC_FUNC_IMPL(__imp__sub_8227DAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DAC8"))) PPC_WEAK_FUNC(sub_8227DAC8);
PPC_FUNC_IMPL(__imp__sub_8227DAC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227db08
	if (cr6.gt) {
		sub_8227DB08(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-9496
	r12.s64 = r12.s64 + -9496;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227DAF8;
	case 1:
		goto loc_8227DB00;
	case 2:
		goto loc_8227DB00;
	case 3:
		goto loc_8227DB00;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-9480(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9480);
	// lwz r17,-9472(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9472);
	// lwz r17,-9472(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9472);
	// lwz r17,-9472(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9472);
loc_8227DAF8:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
loc_8227DB00:
	// li r3,4
	ctx.r3.s64 = 4;
}

__attribute__((alias("__imp__sub_8227DB08"))) PPC_WEAK_FUNC(sub_8227DB08);
PPC_FUNC_IMPL(__imp__sub_8227DB08) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DB10"))) PPC_WEAK_FUNC(sub_8227DB10);
PPC_FUNC_IMPL(__imp__sub_8227DB10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227db50
	if (cr6.gt) {
		sub_8227DB50(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-9424
	r12.s64 = r12.s64 + -9424;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227DB40;
	case 1:
		goto loc_8227DB48;
	case 2:
		goto loc_8227DB48;
	case 3:
		goto loc_8227DB48;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-9408(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9408);
	// lwz r17,-9400(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9400);
	// lwz r17,-9400(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9400);
	// lwz r17,-9400(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9400);
loc_8227DB40:
	// li r11,2
	r11.s64 = 2;
	// b 0x8227db54
	sub_8227DB54(ctx, base);
	return;
loc_8227DB48:
	// li r11,1
	r11.s64 = 1;
}

__attribute__((alias("__imp__sub_8227DB50"))) PPC_WEAK_FUNC(sub_8227DB50);
PPC_FUNC_IMPL(__imp__sub_8227DB50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// li r11,-1
	r11.s64 = -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8227dbac
	if (cr6.gt) goto loc_8227DBAC;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-9352
	r12.s64 = r12.s64 + -9352;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8227DB8C;
	case 1:
		goto loc_8227DB94;
	case 2:
		goto loc_8227DBA4;
	case 3:
		goto loc_8227DBAC;
	case 4:
		goto loc_8227DB9C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-9332(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9332);
	// lwz r17,-9324(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9324);
	// lwz r17,-9308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9308);
	// lwz r17,-9300(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9300);
	// lwz r17,-9316(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9316);
loc_8227DB8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227DB94:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227DB9C:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227DBA4:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227DBAC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DB54"))) PPC_WEAK_FUNC(sub_8227DB54);
PPC_FUNC_IMPL(__imp__sub_8227DB54) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
}

__attribute__((alias("__imp__sub_8227DBB4"))) PPC_WEAK_FUNC(sub_8227DBB4);
PPC_FUNC_IMPL(__imp__sub_8227DBB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DBB8"))) PPC_WEAK_FUNC(sub_8227DBB8);
PPC_FUNC_IMPL(__imp__sub_8227DBB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bgt cr6,0x8227dbf8
	if (cr6.gt) goto loc_8227DBF8;
	// beq cr6,0x8227dbec
	if (cr6.eq) goto loc_8227DBEC;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8227dbe0
	if (cr6.eq) goto loc_8227DBE0;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x8227dc08
	if (!cr6.eq) goto loc_8227DC08;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,42
	ctx.r3.u64 = ctx.r3.u64 | 42;
	// blr 
	return;
loc_8227DBE0:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,36
	ctx.r3.u64 = ctx.r3.u64 | 36;
	// blr 
	return;
loc_8227DBEC:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,41
	ctx.r3.u64 = ctx.r3.u64 | 41;
	// blr 
	return;
loc_8227DBF8:
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x8227dc1c
	if (cr6.eq) goto loc_8227DC1C;
	// cmplwi cr6,r3,65534
	cr6.compare<uint32_t>(ctx.r3.u32, 65534, xer);
	// beq cr6,0x8227dc10
	if (cr6.eq) goto loc_8227DC10;
loc_8227DC08:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227DC10:
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// ori r3,r3,44
	ctx.r3.u64 = ctx.r3.u64 | 44;
	// blr 
	return;
loc_8227DC1C:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,43
	ctx.r3.u64 = ctx.r3.u64 | 43;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DC28"))) PPC_WEAK_FUNC(sub_8227DC28);
PPC_FUNC_IMPL(__imp__sub_8227DC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,42
	r11.u64 = r11.u64 | 42;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8227dc68
	if (cr6.gt) goto loc_8227DC68;
	// beq cr6,0x8227dc60
	if (cr6.eq) goto loc_8227DC60;
	// addis r11,r3,-4096
	r11.s64 = ctx.r3.s64 + -268435456;
	// addic. r11,r11,-36
	xer.ca = r11.u32 > 35;
	r11.s64 = r11.s64 + -36;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8227dc58
	if (cr0.eq) goto loc_8227DC58;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bne cr6,0x8227dc88
	if (!cr6.eq) goto loc_8227DC88;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227DC58:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227DC60:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227DC68:
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r10,r11,43
	ctx.r10.u64 = r11.u64 | 43;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x8227dc98
	if (cr6.eq) goto loc_8227DC98;
	// lis r11,8192
	r11.s64 = 536870912;
	// ori r10,r11,44
	ctx.r10.u64 = r11.u64 | 44;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x8227dc90
	if (cr6.eq) goto loc_8227DC90;
loc_8227DC88:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227DC90:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8227DC98:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DCA0"))) PPC_WEAK_FUNC(sub_8227DCA0);
PPC_FUNC_IMPL(__imp__sub_8227DCA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8227dd0c
	if (cr6.gt) goto loc_8227DD0C;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-9012
	r12.s64 = r12.s64 + -9012;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227DCE0;
	case 1:
		goto loc_8227DCEC;
	case 2:
		goto loc_8227DCF4;
	case 3:
		goto loc_8227DCFC;
	case 4:
		goto loc_8227DD04;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-8992(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8992);
	// lwz r17,-8980(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8980);
	// lwz r17,-8972(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8972);
	// lwz r17,-8964(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8964);
	// lwz r17,-8956(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8956);
loc_8227DCE0:
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65534
	ctx.r3.u64 = ctx.r3.u64 | 65534;
	// b 0x8227dd10
	goto loc_8227DD10;
loc_8227DCEC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8227dd10
	goto loc_8227DD10;
loc_8227DCF4:
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8227dd10
	goto loc_8227DD10;
loc_8227DCFC:
	// li r3,3
	ctx.r3.s64 = 3;
	// b 0x8227dd10
	goto loc_8227DD10;
loc_8227DD04:
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x8227dd10
	goto loc_8227DD10;
loc_8227DD0C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8227DD10:
	// bl 0x8227dbb8
	ctx.lr = 0x8227DD14;
	sub_8227DBB8(ctx, base);
	// bl 0x8227dc28
	ctx.lr = 0x8227DD18;
	sub_8227DC28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227DD28"))) PPC_WEAK_FUNC(sub_8227DD28);
PPC_FUNC_IMPL(__imp__sub_8227DD28) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8227dbb8
	sub_8227DBB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8227DD30"))) PPC_WEAK_FUNC(sub_8227DD30);
PPC_FUNC_IMPL(__imp__sub_8227DD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8227DD38;
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
	ctx.lr = 0x8227DD7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
loc_8227DD84:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227de8c
	if (cr6.eq) goto loc_8227DE8C;
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
	ctx.lr = 0x8227DDA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824e8f28
	ctx.lr = 0x8227DDB8;
	sub_824E8F28(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8227de80
	if (!cr6.eq) goto loc_8227DE80;
	// cmplwi cr6,r27,4
	cr6.compare<uint32_t>(r27.u32, 4, xer);
	// bgt cr6,0x8227de08
	if (cr6.gt) goto loc_8227DE08;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-8732
	r12.s64 = r12.s64 + -8732;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_8227DDF8;
	case 1:
		goto loc_8227DE00;
	case 2:
		goto loc_8227DE00;
	case 3:
		goto loc_8227DE00;
	case 4:
		goto loc_8227DE00;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-8712(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8712);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
loc_8227DDF8:
	// li r6,8
	ctx.r6.s64 = 8;
	// b 0x8227de0c
	goto loc_8227DE0C;
loc_8227DE00:
	// li r6,4
	ctx.r6.s64 = 4;
	// b 0x8227de0c
	goto loc_8227DE0C;
loc_8227DE08:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
loc_8227DE0C:
	// cmplw cr6,r19,r27
	cr6.compare<uint32_t>(r19.u32, r27.u32, xer);
	// bne cr6,0x8227de34
	if (!cr6.eq) goto loc_8227DE34;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227DE28;
	sub_824E9690(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r31,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r31.u8);
	// b 0x8227de80
	goto loc_8227DE80;
loc_8227DE34:
	// add r30,r6,r28
	r30.u64 = ctx.r6.u64 + r28.u64;
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// bgt cr6,0x8227de60
	if (cr6.gt) goto loc_8227DE60;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227DE50;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bne cr6,0x8227de64
	if (!cr6.eq) goto loc_8227DE64;
loc_8227DE60:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8227DE64:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227de7c
	if (cr6.eq) goto loc_8227DE7C;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// sld r10,r18,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (r18.u64 << (r11.u8 & 0x7F));
	// std r10,0(r23)
	PPC_STORE_U64(r23.u32 + 0, ctx.r10.u64);
loc_8227DE7C:
	// mr r28,r30
	r28.u64 = r30.u64;
loc_8227DE80:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,5
	cr6.compare<int32_t>(r27.s32, 5, xer);
	// blt cr6,0x8227dd84
	if (cr6.lt) goto loc_8227DD84;
loc_8227DE8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8227DE98"))) PPC_WEAK_FUNC(sub_8227DE98);
PPC_FUNC_IMPL(__imp__sub_8227DE98) {
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
	// blt cr6,0x8227def4
	if (cr6.lt) goto loc_8227DEF4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227def4
	if (cr6.eq) goto loc_8227DEF4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227DECC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,292
	ctx.r8.s64 = ctx.r9.s64 + 292;
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
loc_8227DEF4:
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

__attribute__((alias("__imp__sub_8227DF0C"))) PPC_WEAK_FUNC(sub_8227DF0C);
PPC_FUNC_IMPL(__imp__sub_8227DF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DF10"))) PPC_WEAK_FUNC(sub_8227DF10);
PPC_FUNC_IMPL(__imp__sub_8227DF10) {
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
	ctx.lr = 0x8227DF18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227DF34;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227DF40;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227DF50;
	sub_82270170(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,208(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 208);
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x8227DF68;
	sub_82293E30(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227DF7C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x8227DF98;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x8227DFB0;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293f28
	ctx.lr = 0x8227DFBC;
	sub_82293F28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x8227DFD8;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x8229bd30
	ctx.lr = 0x8227DFEC;
	sub_8229BD30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x8229bcd0
	ctx.lr = 0x8227E000;
	sub_8229BCD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E014;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E024;
	sub_82270170(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8227E030;
	sub_82274128(ctx, base);
loc_8227E030:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E038"))) PPC_WEAK_FUNC(sub_8227E038);
PPC_FUNC_IMPL(__imp__sub_8227E038) {
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
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E05C;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e094
	if (cr6.eq) goto loc_8227E094;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822952b0
	ctx.lr = 0x8227E070;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e094
	if (cr6.eq) goto loc_8227E094;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227E088;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227e098
	if (!cr6.eq) goto loc_8227E098;
loc_8227E094:
	// li r11,0
	r11.s64 = 0;
loc_8227E098:
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

__attribute__((alias("__imp__sub_8227E0B0"))) PPC_WEAK_FUNC(sub_8227E0B0);
PPC_FUNC_IMPL(__imp__sub_8227E0B0) {
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
	ctx.lr = 0x8227E0B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r11,-2628
	r30.s64 = r11.s64 + -2628;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E0D8;
	sub_822701C8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8227e110
	if (!cr6.eq) goto loc_8227E110;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8227e100
	if (cr6.eq) goto loc_8227E100;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8227e104
	if (!cr6.eq) goto loc_8227E104;
loc_8227E100:
	// li r11,1
	r11.s64 = 1;
loc_8227E104:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
loc_8227E110:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E11C;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227E13C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E154;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x8227E15C;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82389668
	ctx.lr = 0x8227E16C;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x8238eab8
	ctx.lr = 0x8227E19C;
	sub_8238EAB8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227E1A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E1B0"))) PPC_WEAK_FUNC(sub_8227E1B0);
PPC_FUNC_IMPL(__imp__sub_8227E1B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82293e30
	ctx.lr = 0x8227E1D8;
	sub_82293E30(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,-2628
	ctx.r4.s64 = ctx.r9.s64 + -2628;
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E1EC;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e230
	if (cr6.eq) goto loc_8227E230;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822952b0
	ctx.lr = 0x8227E200;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e230
	if (cr6.eq) goto loc_8227E230;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x8227E21C;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8227e230
	if (cr6.eq) goto loc_8227E230;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293f60
	ctx.lr = 0x8227E22C;
	sub_82293F60(ctx, base);
	// b 0x8227e234
	goto loc_8227E234;
loc_8227E230:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_8227E234:
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

__attribute__((alias("__imp__sub_8227E24C"))) PPC_WEAK_FUNC(sub_8227E24C);
PPC_FUNC_IMPL(__imp__sub_8227E24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E250"))) PPC_WEAK_FUNC(sub_8227E250);
PPC_FUNC_IMPL(__imp__sub_8227E250) {
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
	ctx.lr = 0x8227E258;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E270;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e310
	if (cr6.eq) goto loc_8227E310;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x8227E284;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e310
	if (cr6.eq) goto loc_8227E310;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E298;
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
	ctx.lr = 0x8227E2AC;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e310
	if (cr6.eq) goto loc_8227E310;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_8227E2C0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e304
	if (cr6.eq) goto loc_8227E304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8227E2D4;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e304
	if (cr6.eq) goto loc_8227E304;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e304
	if (!cr6.eq) goto loc_8227E304;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227E2F8;
	sub_822577D0(ctx, base);
	// cmplw cr6,r3,r27
	cr6.compare<uint32_t>(ctx.r3.u32, r27.u32, xer);
	// bne cr6,0x8227e304
	if (!cr6.eq) goto loc_8227E304;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8227E304:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8227e2c0
	if (!cr0.eq) goto loc_8227E2C0;
loc_8227E310:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227E31C"))) PPC_WEAK_FUNC(sub_8227E31C);
PPC_FUNC_IMPL(__imp__sub_8227E31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E320"))) PPC_WEAK_FUNC(sub_8227E320);
PPC_FUNC_IMPL(__imp__sub_8227E320) {
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
	ctx.lr = 0x8227E328;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E33C;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3c8
	if (cr6.eq) goto loc_8227E3C8;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x8227E350;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3c8
	if (cr6.eq) goto loc_8227E3C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E364;
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
	ctx.lr = 0x8227E378;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3c8
	if (cr6.eq) goto loc_8227E3C8;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_8227E38C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e3bc
	if (cr6.eq) goto loc_8227E3BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8227E3A0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3bc
	if (cr6.eq) goto loc_8227E3BC;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e3bc
	if (!cr6.eq) goto loc_8227E3BC;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8227E3BC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8227e38c
	if (!cr0.eq) goto loc_8227E38C;
loc_8227E3C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E3D4"))) PPC_WEAK_FUNC(sub_8227E3D4);
PPC_FUNC_IMPL(__imp__sub_8227E3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E3D8"))) PPC_WEAK_FUNC(sub_8227E3D8);
PPC_FUNC_IMPL(__imp__sub_8227E3D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8227E3E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822927f0
	ctx.lr = 0x8227E3EC;
	sub_822927F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E3F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227E40C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8227E414;
	sub_82272A30(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227E42C;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e4a8
	if (cr6.eq) goto loc_8227E4A8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227e4a8
	if (cr6.eq) goto loc_8227E4A8;
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e454
	if (cr6.eq) goto loc_8227E454;
loc_8227E448:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8227E454:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// ble cr6,0x8227e4a8
	if (!cr6.gt) goto loc_8227E4A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481590
	ctx.lr = 0x8227E464;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e448
	if (cr6.eq) goto loc_8227E448;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e320
	ctx.lr = 0x8227E478;
	sub_8227E320(ctx, base);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// bne cr6,0x8227e4a8
	if (!cr6.eq) goto loc_8227E4A8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x8227E488;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e448
	if (cr6.eq) goto loc_8227E448;
	// srawi r11,r29,1
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1) != 0);
	r11.s64 = r29.s32 >> 1;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r9,r29
	ctx.r8.s64 = r29.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8227e448
	if (cr0.eq) goto loc_8227E448;
loc_8227E4A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227E4B4"))) PPC_WEAK_FUNC(sub_8227E4B4);
PPC_FUNC_IMPL(__imp__sub_8227E4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E4B8"))) PPC_WEAK_FUNC(sub_8227E4B8);
PPC_FUNC_IMPL(__imp__sub_8227E4B8) {
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
	ctx.lr = 0x8227E4C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwzx r27,r11,r10
	r27.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9790
	ctx.lr = 0x8227E4E8;
	sub_821C9790(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823896c0
	ctx.lr = 0x8227E4F8;
	sub_823896C0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8227e51c
	if (cr6.eq) goto loc_8227E51C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823896c0
	ctx.lr = 0x8227E510;
	sub_823896C0(ctx, base);
	// bl 0x8238eb20
	ctx.lr = 0x8227E514;
	sub_8238EB20(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x8227e58c
	if (!cr6.eq) goto loc_8227E58C;
loc_8227E51C:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x8227e52c
	if (cr6.eq) goto loc_8227E52C;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// bne cr6,0x8227e58c
	if (!cr6.eq) goto loc_8227E58C;
loc_8227E52C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82389760
	ctx.lr = 0x8227E538;
	sub_82389760(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e58c
	if (!cr6.eq) goto loc_8227E58C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826bf4b0
	ctx.lr = 0x8227E554;
	sub_826BF4B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,6
	cr6.compare<int32_t>(r26.s32, 6, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,7
	cr6.compare<int32_t>(r26.s32, 7, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227e590
	if (!cr6.eq) goto loc_8227E590;
loc_8227E58C:
	// li r11,0
	r11.s64 = 0;
loc_8227E590:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8227E59C"))) PPC_WEAK_FUNC(sub_8227E59C);
PPC_FUNC_IMPL(__imp__sub_8227E59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E5A0"))) PPC_WEAK_FUNC(sub_8227E5A0);
PPC_FUNC_IMPL(__imp__sub_8227E5A0) {
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
	ctx.lr = 0x8227E5A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8227E5B8;
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
	ctx.lr = 0x8227E5CC;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e654
	if (cr6.eq) goto loc_8227E654;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8227E5E0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e644
	if (cr6.eq) goto loc_8227E644;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e620
	if (cr6.eq) goto loc_8227E620;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e618
	if (!cr6.eq) goto loc_8227E618;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227E60C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e620
	if (cr6.eq) goto loc_8227E620;
loc_8227E618:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227e624
	goto loc_8227E624;
loc_8227E620:
	// li r11,0
	r11.s64 = 0;
loc_8227E624:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e644
	if (cr6.eq) goto loc_8227E644;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8227E63C;
	sub_822051A0(ctx, base);
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// beq cr6,0x8227e660
	if (cr6.eq) goto loc_8227E660;
loc_8227E644:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x8227e5e0
	if (!cr6.eq) goto loc_8227E5E0;
loc_8227E654:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227E660:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E66C"))) PPC_WEAK_FUNC(sub_8227E66C);
PPC_FUNC_IMPL(__imp__sub_8227E66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E670"))) PPC_WEAK_FUNC(sub_8227E670);
PPC_FUNC_IMPL(__imp__sub_8227E670) {
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
	ctx.lr = 0x8227E678;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8227E688;
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
	ctx.lr = 0x8227E69C;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e72c
	if (cr6.eq) goto loc_8227E72C;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8227E6B0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e71c
	if (cr6.eq) goto loc_8227E71C;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e6f0
	if (cr6.eq) goto loc_8227E6F0;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e6e8
	if (!cr6.eq) goto loc_8227E6E8;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227E6DC;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e6f0
	if (cr6.eq) goto loc_8227E6F0;
loc_8227E6E8:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227e6f4
	goto loc_8227E6F4;
loc_8227E6F0:
	// li r11,0
	r11.s64 = 0;
loc_8227E6F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e71c
	if (cr6.eq) goto loc_8227E71C;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x8227E708;
	sub_82502300(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824f0550
	ctx.lr = 0x8227E710;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e738
	if (!cr6.eq) goto loc_8227E738;
loc_8227E71C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x8227e6b0
	if (!cr6.eq) goto loc_8227E6B0;
loc_8227E72C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227E738:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8227E744;
	sub_822051A0(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x8227E748;
	sub_822A5948(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E750"))) PPC_WEAK_FUNC(sub_8227E750);
PPC_FUNC_IMPL(__imp__sub_8227E750) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E76C;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e7dc
	if (cr6.eq) goto loc_8227E7DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E780;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227E790;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8227E798;
	sub_82272A30(ctx, base);
	// bl 0x82481688
	ctx.lr = 0x8227E79C;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e7dc
	if (cr6.eq) goto loc_8227E7DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E7B0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E7C0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8227E7C8;
	sub_82272A30(ctx, base);
	// bl 0x82481608
	ctx.lr = 0x8227E7CC;
	sub_82481608(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e7e0
	if (cr6.eq) goto loc_8227E7E0;
loc_8227E7DC:
	// li r11,0
	r11.s64 = 0;
loc_8227E7E0:
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

__attribute__((alias("__imp__sub_8227E7F8"))) PPC_WEAK_FUNC(sub_8227E7F8);
PPC_FUNC_IMPL(__imp__sub_8227E7F8) {
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
	ctx.lr = 0x8227E824;
	sub_822701C8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E834;
	sub_8226BE68(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227E854;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227E86C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227e8a4
	if (!cr6.eq) goto loc_8227E8A4;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8227e8a4
	if (!cr6.eq) goto loc_8227E8A4;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227e8a8
	if (cr6.eq) goto loc_8227E8A8;
loc_8227E8A4:
	// li r11,0
	r11.s64 = 0;
loc_8227E8A8:
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

__attribute__((alias("__imp__sub_8227E8C4"))) PPC_WEAK_FUNC(sub_8227E8C4);
PPC_FUNC_IMPL(__imp__sub_8227E8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E8C8"))) PPC_WEAK_FUNC(sub_8227E8C8);
PPC_FUNC_IMPL(__imp__sub_8227E8C8) {
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
	ctx.lr = 0x8227E8D0;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8227ea0c
	if (cr6.eq) goto loc_8227EA0C;
	// addi r29,r4,144
	r29.s64 = ctx.r4.s64 + 144;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227ea0c
	if (cr6.eq) goto loc_8227EA0C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x8227E8F0;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ea0c
	if (cr6.eq) goto loc_8227EA0C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x8227E904;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e9ec
	if (cr6.eq) goto loc_8227E9EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E918;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227E928;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8227E934;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E93C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E94C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8227E954;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x8227E958;
	sub_824F92F0(ctx, base);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824817c0
	ctx.lr = 0x8227E964;
	sub_824817C0(ctx, base);
	// addi r4,r3,12
	ctx.r4.s64 = ctx.r3.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ea3b8
	ctx.lr = 0x8227E970;
	sub_824EA3B8(ctx, base);
	// lis r4,8192
	ctx.r4.s64 = 536870912;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,53
	ctx.r4.u64 = ctx.r4.u64 | 53;
	// bl 0x824e9038
	ctx.lr = 0x8227E980;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e9740
	ctx.lr = 0x8227E990;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// bne cr6,0x8227e9ec
	if (!cr6.eq) goto loc_8227E9EC;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9530
	ctx.lr = 0x8227E9AC;
	sub_824E9530(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E9B4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E9C4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8227E9CC;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x824e9240
	ctx.lr = 0x8227E9DC;
	sub_824E9240(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82486800
	ctx.lr = 0x8227E9EC;
	sub_82486800(ctx, base);
loc_8227E9EC:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r11,28
	ctx.r9.u64 = r11.u32 & 0xF;
	// ori r8,r9,112
	ctx.r8.u64 = ctx.r9.u64 | 112;
	// lwz r3,-10012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// bl 0x826d5a18
	ctx.lr = 0x8227EA0C;
	sub_826D5A18(ctx, base);
loc_8227EA0C:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227EA14"))) PPC_WEAK_FUNC(sub_8227EA14);
PPC_FUNC_IMPL(__imp__sub_8227EA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227EA18"))) PPC_WEAK_FUNC(sub_8227EA18);
PPC_FUNC_IMPL(__imp__sub_8227EA18) {
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
	ctx.lr = 0x8227EA20;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8227EA30;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227EA40;
	sub_82270170(ctx, base);
	// lwz r11,296(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8227EA5C;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227eba4
	if (!cr6.eq) goto loc_8227EBA4;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// blt cr6,0x8227eaf8
	if (cr6.lt) goto loc_8227EAF8;
	// bne cr6,0x8227eba4
	if (!cr6.eq) goto loc_8227EBA4;
	// lbz r9,592(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 592);
	// li r11,0
	r11.s64 = 0;
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// std r11,84(r1)
	PPC_STORE_U64(ctx.r1.u32 + 84, r11.u64);
	// stb r8,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, ctx.r8.u8);
	// bl 0x82388598
	ctx.lr = 0x8227EA90;
	sub_82388598(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x8227EA9C;
	sub_82270170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EAB4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EAC8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r7,r30,296
	ctx.r7.s64 = r30.s64 + 296;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7b20
	ctx.lr = 0x8227EAF0;
	sub_824E7B20(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d924c
	return;
loc_8227EAF8:
	// lbz r9,1120(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1120);
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r11.u32);
	// std r11,612(r1)
	PPC_STORE_U64(ctx.r1.u32 + 612, r11.u64);
	// stb r8,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, ctx.r8.u8);
	// bl 0x82388598
	ctx.lr = 0x8227EB1C;
	sub_82388598(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x8227EB28;
	sub_82270170(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// addi r30,r29,16
	r30.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EB40;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EB54;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EB68;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EB7C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r7,r29,296
	ctx.r7.s64 = r29.s64 + 296;
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7b20
	ctx.lr = 0x8227EBA4;
	sub_824E7B20(ctx, base);
loc_8227EBA4:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227EBAC"))) PPC_WEAK_FUNC(sub_8227EBAC);
PPC_FUNC_IMPL(__imp__sub_8227EBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227EBB0"))) PPC_WEAK_FUNC(sub_8227EBB0);
PPC_FUNC_IMPL(__imp__sub_8227EBB0) {
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
	ctx.lr = 0x8227EBB8;
	// stwu r1,-3808(r1)
	ea = -3808 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227EBC4;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227EBD4;
	sub_82270170(ctx, base);
	// lwz r11,296(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8227EBF0;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227EBFC;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227EC0C;
	sub_82270170(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EC1C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x8227eff0
	if (cr6.lt) goto loc_8227EFF0;
	// beq cr6,0x8227ee10
	if (cr6.eq) goto loc_8227EE10;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x8227f094
	if (!cr6.lt) goto loc_8227F094;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EC3C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227ecc4
	if (!cr6.eq) goto loc_8227ECC4;
	// lbz r9,1120(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1120);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r11.u32);
	// std r11,612(r1)
	PPC_STORE_U64(ctx.r1.u32 + 612, r11.u64);
	// stb r8,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EC70;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EC84;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EC98;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227ECAC;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227ECC4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8227ed70
	if (!cr6.eq) goto loc_8227ED70;
	// bl 0x822577d0
	ctx.lr = 0x8227ECE8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// lbz r9,3232(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 3232);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,2720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2720, r11.u32);
	// std r11,2724(r1)
	PPC_STORE_U64(ctx.r1.u32 + 2724, r11.u64);
	// stb r8,3232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 3232, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227ED1C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227ED30;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227ED44;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227ED58;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,2720
	ctx.r6.s64 = ctx.r1.s64 + 2720;
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227ED70:
	// bl 0x822577d0
	ctx.lr = 0x8227ED74;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227ED88;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x8227f094
	if (!cr6.eq) goto loc_8227F094;
	// lbz r9,2176(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 2176);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,1664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1664, r11.u32);
	// std r11,1668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1668, r11.u64);
	// stb r8,2176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 2176, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EDBC;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EDD0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EDE4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EDF8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,1664
	ctx.r6.s64 = ctx.r1.s64 + 1664;
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EE10:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EE1C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227eea4
	if (!cr6.eq) goto loc_8227EEA4;
	// lbz r9,592(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 592);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// std r11,84(r1)
	PPC_STORE_U64(ctx.r1.u32 + 84, r11.u64);
	// stb r8,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EE50;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EE64;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EE78;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EE8C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EEA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8227ef50
	if (!cr6.eq) goto loc_8227EF50;
	// bl 0x822577d0
	ctx.lr = 0x8227EEC8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// lbz r9,1648(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1648);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, r11.u32);
	// std r11,1140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1140, r11.u64);
	// stb r8,1648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1648, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EEFC;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EF10;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EF24;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EF38;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,1136
	ctx.r6.s64 = ctx.r1.s64 + 1136;
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EF50:
	// bl 0x822577d0
	ctx.lr = 0x8227EF54;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EF68;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x8227f094
	if (!cr6.eq) goto loc_8227F094;
	// lbz r9,2704(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 2704);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,2192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2192, r11.u32);
	// std r11,2196(r1)
	PPC_STORE_U64(ctx.r1.u32 + 2196, r11.u64);
	// stb r8,2704(r1)
	PPC_STORE_U8(ctx.r1.u32 + 2704, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EF9C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EFB0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EFC4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EFD8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,2192
	ctx.r6.s64 = ctx.r1.s64 + 2192;
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EFF0:
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227EFFC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227f094
	if (!cr6.eq) goto loc_8227F094;
	// lbz r9,3760(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 3760);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,3248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3248, r11.u32);
	// std r11,3252(r1)
	PPC_STORE_U64(ctx.r1.u32 + 3252, r11.u64);
	// stb r8,3760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 3760, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227F030;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227F044;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227F058;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227F06C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,3248
	ctx.r6.s64 = ctx.r1.s64 + 3248;
	// li r5,3
	ctx.r5.s64 = 3;
loc_8227F080:
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r7,r31,296
	ctx.r7.s64 = r31.s64 + 296;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7b20
	ctx.lr = 0x8227F094;
	sub_824E7B20(ctx, base);
loc_8227F094:
	// addi r1,r1,3808
	ctx.r1.s64 = ctx.r1.s64 + 3808;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227F09C"))) PPC_WEAK_FUNC(sub_8227F09C);
PPC_FUNC_IMPL(__imp__sub_8227F09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F0A0"))) PPC_WEAK_FUNC(sub_8227F0A0);
PPC_FUNC_IMPL(__imp__sub_8227F0A0) {
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
	ctx.lr = 0x8227F0A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227F0C0;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// blt cr6,0x8227f0f4
	if (cr6.lt) goto loc_8227F0F4;
	// bne cr6,0x8227f2c0
	if (!cr6.eq) goto loc_8227F2C0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,28
	ctx.r4.s64 = 28;
	// bl 0x8268ee10
	ctx.lr = 0x8227F0EC;
	sub_8268EE10(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8227F0F4:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,2
	r11.s64 = 2;
	// beq cr6,0x8227f108
	if (cr6.eq) goto loc_8227F108;
	// li r11,-1
	r11.s64 = -1;
loc_8227F108:
	// stw r11,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e750
	ctx.lr = 0x8227F114;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227f148
	if (!cr6.eq) goto loc_8227F148;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F12C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F13C;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8227F148;
	sub_82274128(ctx, base);
loc_8227F148:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8227f168
	if (!cr6.eq) goto loc_8227F168;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,26
	ctx.r4.s64 = 26;
	// bl 0x8268ee10
	ctx.lr = 0x8227F168;
	sub_8268EE10(ctx, base);
loc_8227F168:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-1992
	ctx.r3.s64 = r11.s64 + -1992;
	// addi r31,r10,-11404
	r31.s64 = ctx.r10.s64 + -11404;
	// addi r28,r9,-22108
	r28.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8227F184;
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
	ctx.lr = 0x8227F198;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,92(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8227F1AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8227f1cc
	if (cr6.eq) goto loc_8227F1CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F1CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8227F1CC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e750
	ctx.lr = 0x8227F1D4;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r31,r11,-2628
	r31.s64 = r11.s64 + -2628;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227F1F4;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227F208;
	sub_822701C8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82295f70
	ctx.lr = 0x8227F214;
	sub_82295F70(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lbz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// ori r11,r7,128
	r11.u64 = ctx.r7.u64 | 128;
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// ori r8,r5,224
	ctx.r8.u64 = ctx.r5.u64 | 224;
	// clrlwi r10,r6,25
	ctx.r10.u64 = ctx.r6.u32 & 0x7F;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// ori r7,r9,64
	ctx.r7.u64 = ctx.r9.u64 | 64;
	// stb r8,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// stb r7,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r7.u8);
	// bl 0x822701c8
	ctx.lr = 0x8227F278;
	sub_822701C8(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82295538
	ctx.lr = 0x8227F284;
	sub_82295538(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82397458
	ctx.lr = 0x8227F28C;
	sub_82397458(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r30,-10240(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x8227e320
	ctx.lr = 0x8227F2A4;
	sub_8227E320(ctx, base);
	// addi r29,r3,-1
	r29.s64 = ctx.r3.s64 + -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227F2B4;
	sub_822701C8(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82295d70
	ctx.lr = 0x8227F2C0;
	sub_82295D70(ctx, base);
loc_8227F2C0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227F2C8"))) PPC_WEAK_FUNC(sub_8227F2C8);
PPC_FUNC_IMPL(__imp__sub_8227F2C8) {
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
	ctx.lr = 0x8227F2D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F2E0;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227F2F0;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8227F2FC;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F304;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F314;
	sub_82270170(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8227F320;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F328;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F338;
	sub_82270170(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x8227F344;
	sub_82274120(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8229bd58
	ctx.lr = 0x8227F34C;
	sub_8229BD58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F354;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F364;
	sub_82270170(ctx, base);
	// lwz r29,208(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x8227F370;
	sub_82481580(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8227f388
	if (!cr6.eq) goto loc_8227F388;
	// lwz r11,11784(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11784);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8227f39c
	if (!cr6.eq) goto loc_8227F39C;
loc_8227F388:
	// lwz r11,11792(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11792);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227f39c
	if (cr6.eq) goto loc_8227F39C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82297638
	ctx.lr = 0x8227F39C;
	sub_82297638(ctx, base);
loc_8227F39C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8227F3AC;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e750
	ctx.lr = 0x8227F3B8;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227f3f8
	if (cr6.eq) goto loc_8227F3F8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f3f8
	if (cr6.eq) goto loc_8227F3F8;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8227f3e8
	if (!cr6.eq) goto loc_8227F3E8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x8227F3E8;
	sub_82295F70(ctx, base);
loc_8227F3E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x8227F3F8;
	sub_82295F70(ctx, base);
loc_8227F3F8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8227f418
	if (!cr6.eq) goto loc_8227F418;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,27
	ctx.r4.s64 = 27;
	// bl 0x8268ee10
	ctx.lr = 0x8227F418;
	sub_8268EE10(ctx, base);
loc_8227F418:
	// li r11,-1
	r11.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// bl 0x821e6828
	ctx.lr = 0x8227F430;
	sub_821E6828(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227F438"))) PPC_WEAK_FUNC(sub_8227F438);
PPC_FUNC_IMPL(__imp__sub_8227F438) {
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
	ctx.lr = 0x8227F440;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r25,72
	r25.s64 = 72;
	// li r24,0
	r24.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// li r29,8
	r29.s64 = 8;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_8227F464:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f498
	if (cr6.eq) goto loc_8227F498;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8227f4c4
	if (cr6.lt) goto loc_8227F4C4;
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x8227f4c4
	if (!cr6.lt) goto loc_8227F4C4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// b 0x8227f4b8
	goto loc_8227F4B8;
loc_8227F498:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8227f4c4
	if (cr6.lt) goto loc_8227F4C4;
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x8227f4c4
	if (!cr6.lt) goto loc_8227F4C4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
loc_8227F4B8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227f4c8
	if (!cr6.eq) goto loc_8227F4C8;
loc_8227F4C4:
	// li r11,0
	r11.s64 = 0;
loc_8227F4C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f4e4
	if (cr6.eq) goto loc_8227F4E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5948
	ctx.lr = 0x8227F4DC;
	sub_822A5948(ctx, base);
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x8227f4e8
	goto loc_8227F4E8;
loc_8227F4E4:
	// li r31,0
	r31.s64 = 0;
loc_8227F4E8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f56c
	if (cr6.eq) goto loc_8227F56C;
	// lwz r11,16(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8227f510
	if (!cr6.eq) goto loc_8227F510;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F508;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f56c
	if (cr6.eq) goto loc_8227F56C;
loc_8227F510:
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f544
	if (cr6.eq) goto loc_8227F544;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227f53c
	if (!cr6.eq) goto loc_8227F53C;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227F530;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f544
	if (cr6.eq) goto loc_8227F544;
loc_8227F53C:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227f548
	goto loc_8227F548;
loc_8227F544:
	// li r11,0
	r11.s64 = 0;
loc_8227F548:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f56c
	if (cr6.eq) goto loc_8227F56C;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F560;
	sub_822577D0(ctx, base);
	// cmplw cr6,r3,r27
	cr6.compare<uint32_t>(ctx.r3.u32, r27.u32, xer);
	// bne cr6,0x8227f56c
	if (!cr6.eq) goto loc_8227F56C;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_8227F56C:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r29,132
	cr6.compare<int32_t>(r29.s32, 132, xer);
	// bne cr6,0x8227f464
	if (!cr6.eq) goto loc_8227F464;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8227F588"))) PPC_WEAK_FUNC(sub_8227F588);
PPC_FUNC_IMPL(__imp__sub_8227F588) {
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
	// bl 0x8227e0b0
	ctx.lr = 0x8227F5A0;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f5d8
	if (cr6.eq) goto loc_8227F5D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5052);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f5d8
	if (cr6.eq) goto loc_8227F5D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82257160
	ctx.lr = 0x8227F5C4;
	sub_82257160(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8227F5D8:
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

__attribute__((alias("__imp__sub_8227F5F0"))) PPC_WEAK_FUNC(sub_8227F5F0);
PPC_FUNC_IMPL(__imp__sub_8227F5F0) {
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
	ctx.lr = 0x8227F5F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F604;
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
	ctx.lr = 0x8227F618;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f690
	if (cr6.eq) goto loc_8227F690;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8227F62C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f680
	if (cr6.eq) goto loc_8227F680;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227f680
	if (!cr6.eq) goto loc_8227F680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8227F64C;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f680
	if (cr6.eq) goto loc_8227F680;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F664;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f680
	if (cr6.eq) goto loc_8227F680;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F678;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f6ec
	if (cr6.eq) goto loc_8227F6EC;
loc_8227F680:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x8227f62c
	if (!cr6.eq) goto loc_8227F62C;
loc_8227F690:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,444
	ctx.r3.s64 = r11.s64 + 444;
	// bl 0x821fa230
	ctx.lr = 0x8227F69C;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8227F6B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8227F6C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8227F6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8227F6EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227F6F8"))) PPC_WEAK_FUNC(sub_8227F6F8);
PPC_FUNC_IMPL(__imp__sub_8227F6F8) {
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
	ctx.lr = 0x8227F700;
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
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227f744
	if (cr6.gt) goto loc_8227F744;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-2252
	r12.s64 = r12.s64 + -2252;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227F74C;
	case 1:
		goto loc_8227F74C;
	case 2:
		goto loc_8227F74C;
	case 3:
		goto loc_8227F74C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
loc_8227F744:
	// li r31,-1
	r31.s64 = -1;
	// b 0x8227f750
	goto loc_8227F750;
loc_8227F74C:
	// li r31,3
	r31.s64 = 3;
loc_8227F750:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8227f808
	if (cr6.gt) goto loc_8227F808;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-2176
	r12.s64 = r12.s64 + -2176;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8227F790;
	case 1:
		goto loc_8227F7B0;
	case 2:
		goto loc_8227F7D0;
	case 3:
		goto loc_8227F7F0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-2160(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2160);
	// lwz r17,-2128(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2128);
	// lwz r17,-2096(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2096);
	// lwz r17,-2064(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2064);
loc_8227F790:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8227F7A4;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F7B0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8227F7C4;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F7D0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8227F7E4;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F7F0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8227F804;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8227F808:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227F814"))) PPC_WEAK_FUNC(sub_8227F814);
PPC_FUNC_IMPL(__imp__sub_8227F814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F818"))) PPC_WEAK_FUNC(sub_8227F818);
PPC_FUNC_IMPL(__imp__sub_8227F818) {
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
	ctx.lr = 0x8227F844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x8227f868
	if (!cr6.eq) goto loc_8227F868;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f868
	if (cr6.eq) goto loc_8227F868;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,212
	ctx.r10.s64 = r11.s64 + 212;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x8227f86c
	goto loc_8227F86C;
loc_8227F868:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227F86C:
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

__attribute__((alias("__imp__sub_8227F884"))) PPC_WEAK_FUNC(sub_8227F884);
PPC_FUNC_IMPL(__imp__sub_8227F884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F888"))) PPC_WEAK_FUNC(sub_8227F888);
PPC_FUNC_IMPL(__imp__sub_8227F888) {
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
	ctx.lr = 0x8227F890;
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
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8227f8d8
	if (cr6.gt) goto loc_8227F8D8;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1852
	r12.s64 = r12.s64 + -1852;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227F8E0;
	case 1:
		goto loc_8227F8E0;
	case 2:
		goto loc_8227F8E0;
	case 3:
		goto loc_8227F8E0;
	case 4:
		goto loc_8227F8E0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
loc_8227F8D8:
	// li r31,-1
	r31.s64 = -1;
	// b 0x8227f8e4
	goto loc_8227F8E4;
loc_8227F8E0:
	// li r31,3
	r31.s64 = 3;
loc_8227F8E4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F8F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8227f99c
	if (cr6.gt) goto loc_8227F99C;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1772
	r12.s64 = r12.s64 + -1772;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8227F924;
	case 1:
		goto loc_8227F944;
	case 2:
		goto loc_8227F964;
	case 3:
		goto loc_8227F984;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1756(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1756);
	// lwz r17,-1724(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1724);
	// lwz r17,-1692(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1692);
	// lwz r17,-1660(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1660);
loc_8227F924:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8227F938;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F944:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8227F958;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F964:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8227F978;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F984:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8227F998;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8227F99C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227F9A8"))) PPC_WEAK_FUNC(sub_8227F9A8);
PPC_FUNC_IMPL(__imp__sub_8227F9A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge cr6,0x8227f9c4
	if (!cr6.lt) goto loc_8227F9C4;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mulli r11,r4,568
	r11.s64 = ctx.r4.s64 * 568;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_8227F9C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227F9CC"))) PPC_WEAK_FUNC(sub_8227F9CC);
PPC_FUNC_IMPL(__imp__sub_8227F9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F9D0"))) PPC_WEAK_FUNC(sub_8227F9D0);
PPC_FUNC_IMPL(__imp__sub_8227F9D0) {
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
	ctx.lr = 0x8227F9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x8227fa20
	if (!cr6.eq) goto loc_8227FA20;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227fa20
	if (cr6.eq) goto loc_8227FA20;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,372
	ctx.r10.s64 = r11.s64 + 372;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x8227fa24
	goto loc_8227FA24;
loc_8227FA20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227FA24:
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

__attribute__((alias("__imp__sub_8227FA3C"))) PPC_WEAK_FUNC(sub_8227FA3C);
PPC_FUNC_IMPL(__imp__sub_8227FA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FA40"))) PPC_WEAK_FUNC(sub_8227FA40);
PPC_FUNC_IMPL(__imp__sub_8227FA40) {
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
	ctx.lr = 0x8227FA48;
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
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227faac
	if (cr6.gt) goto loc_8227FAAC;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1412
	r12.s64 = r12.s64 + -1412;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227FA8C;
	case 1:
		goto loc_8227FA94;
	case 2:
		goto loc_8227FA9C;
	case 3:
		goto loc_8227FAA4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1396(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1396);
	// lwz r17,-1388(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1388);
	// lwz r17,-1380(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1380);
	// lwz r17,-1372(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1372);
loc_8227FA8C:
	// li r11,61
	r11.s64 = 61;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FA94:
	// li r11,62
	r11.s64 = 62;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FA9C:
	// li r11,63
	r11.s64 = 63;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FAA4:
	// li r11,64
	r11.s64 = 64;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FAAC:
	// li r11,-1
	r11.s64 = -1;
loc_8227FAB0:
	// addi r11,r11,-61
	r11.s64 = r11.s64 + -61;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8227faf4
	if (cr6.gt) goto loc_8227FAF4;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1324
	r12.s64 = r12.s64 + -1324;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8227FAE4;
	case 1:
		goto loc_8227FAEC;
	case 2:
		goto loc_8227FAE4;
	case 3:
		goto loc_8227FAE4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1308);
	// lwz r17,-1300(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1300);
	// lwz r17,-1308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1308);
	// lwz r17,-1308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1308);
loc_8227FAE4:
	// li r31,2
	r31.s64 = 2;
	// b 0x8227faf8
	goto loc_8227FAF8;
loc_8227FAEC:
	// li r31,3
	r31.s64 = 3;
	// b 0x8227faf8
	goto loc_8227FAF8;
loc_8227FAF4:
	// li r31,-1
	r31.s64 = -1;
loc_8227FAF8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227FB08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8227fbb0
	if (cr6.gt) goto loc_8227FBB0;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1240
	r12.s64 = r12.s64 + -1240;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8227FB38;
	case 1:
		goto loc_8227FB58;
	case 2:
		goto loc_8227FB78;
	case 3:
		goto loc_8227FB98;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1224(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1224);
	// lwz r17,-1192(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1192);
	// lwz r17,-1160(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1160);
	// lwz r17,-1128(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1128);
loc_8227FB38:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8227FB4C;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227FB58:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8227FB6C;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227FB78:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8227FB8C;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227FB98:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8227FBAC;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8227FBB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227FBBC"))) PPC_WEAK_FUNC(sub_8227FBBC);
PPC_FUNC_IMPL(__imp__sub_8227FBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FBC0"))) PPC_WEAK_FUNC(sub_8227FBC0);
PPC_FUNC_IMPL(__imp__sub_8227FBC0) {
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
	ctx.lr = 0x8227FBC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	ctx.lr = 0x8227FBE4;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r10.u32);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227fc84
	if (cr6.eq) goto loc_8227FC84;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295510
	ctx.lr = 0x8227FC0C;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8227fc84
	if (!cr6.eq) goto loc_8227FC84;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227FC1C;
	sub_82618750(ctx, base);
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r27,r10,r31
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x822954b8
	ctx.lr = 0x8227FC34;
	sub_822954B8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,6
	ctx.r4.s64 = r31.s64 + 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x82618610
	ctx.lr = 0x8227FC48;
	sub_82618610(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822559f0
	ctx.lr = 0x8227FC54;
	sub_822559F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227fc84
	if (cr6.eq) goto loc_8227FC84;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618698
	ctx.lr = 0x8227FC68;
	sub_82618698(ctx, base);
	// stwx r3,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x8227FC78;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x8227FC84;
	sub_82295930(ctx, base);
loc_8227FC84:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r29,r31
	r31.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x8227FC90;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227FC9C"))) PPC_WEAK_FUNC(sub_8227FC9C);
PPC_FUNC_IMPL(__imp__sub_8227FC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FCA0"))) PPC_WEAK_FUNC(sub_8227FCA0);
PPC_FUNC_IMPL(__imp__sub_8227FCA0) {
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
	ctx.lr = 0x8227FCA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	ctx.lr = 0x8227FCC4;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227fd58
	if (cr6.eq) goto loc_8227FD58;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295510
	ctx.lr = 0x8227FCE0;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8227fd58
	if (!cr6.eq) goto loc_8227FD58;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227FCF4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227fd58
	if (cr6.eq) goto loc_8227FD58;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227FD08;
	sub_82618750(ctx, base);
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r30,r10,r31
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x822954b8
	ctx.lr = 0x8227FD20;
	sub_822954B8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,6
	ctx.r4.s64 = r31.s64 + 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x826185b0
	ctx.lr = 0x8227FD34;
	sub_826185B0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82255ae0
	ctx.lr = 0x8227FD40;
	sub_82255AE0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227fd58
	if (cr6.eq) goto loc_8227FD58;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8268d518
	ctx.lr = 0x8227FD54;
	sub_8268D518(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8227FD58:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8227FD60;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227FD6C"))) PPC_WEAK_FUNC(sub_8227FD6C);
PPC_FUNC_IMPL(__imp__sub_8227FD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FD70"))) PPC_WEAK_FUNC(sub_8227FD70);
PPC_FUNC_IMPL(__imp__sub_8227FD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// lis r11,4096
	r11.s64 = 268435456;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// ori r10,r11,36
	ctx.r10.u64 = r11.u64 | 36;
	// bgt cr6,0x8227fdbc
	if (cr6.gt) goto loc_8227FDBC;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-616
	r12.s64 = r12.s64 + -616;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227FDF0;
	case 1:
		goto loc_8227FDB4;
	case 2:
		goto loc_8227FDA8;
	case 3:
		goto loc_8227FDE0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-528(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -528);
	// lwz r17,-588(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -588);
	// lwz r17,-600(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -600);
	// lwz r17,-544(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -544);
loc_8227FDA8:
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,39
	r11.u64 = r11.u64 | 39;
	// b 0x8227fdc0
	goto loc_8227FDC0;
loc_8227FDB4:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x8227fdc0
	goto loc_8227FDC0;
loc_8227FDBC:
	// li r11,-1
	r11.s64 = -1;
loc_8227FDC0:
	// subf. r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8227fdd8
	if (cr0.eq) goto loc_8227FDD8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8227fde8
	if (!cr6.eq) goto loc_8227FDE8;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227FDD8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8227FDE0:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8227FDE8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227FDF0:
	// li r3,0
	ctx.r3.s64 = 0;
}

__attribute__((alias("__imp__sub_8227FDF8"))) PPC_WEAK_FUNC(sub_8227FDF8);
PPC_FUNC_IMPL(__imp__sub_8227FDF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bgt cr6,0x8227fe38
	if (cr6.gt) goto loc_8227FE38;
	// beq cr6,0x8227fe2c
	if (cr6.eq) goto loc_8227FE2C;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8227fe20
	if (cr6.eq) goto loc_8227FE20;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8227fe40
	if (!cr6.eq) goto loc_8227FE40;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,39
	ctx.r3.u64 = ctx.r3.u64 | 39;
	// blr 
	return;
loc_8227FE20:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,36
	ctx.r3.u64 = ctx.r3.u64 | 36;
	// blr 
	return;
loc_8227FE2C:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,40
	ctx.r3.u64 = ctx.r3.u64 | 40;
	// blr 
	return;
loc_8227FE38:
	// cmplwi cr6,r4,65534
	cr6.compare<uint32_t>(ctx.r4.u32, 65534, xer);
	// beq cr6,0x8227fe48
	if (cr6.eq) goto loc_8227FE48;
loc_8227FE40:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227FE48:
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// ori r3,r3,44
	ctx.r3.u64 = ctx.r3.u64 | 44;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227FE54"))) PPC_WEAK_FUNC(sub_8227FE54);
PPC_FUNC_IMPL(__imp__sub_8227FE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FE58"))) PPC_WEAK_FUNC(sub_8227FE58);
PPC_FUNC_IMPL(__imp__sub_8227FE58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8227FE60;
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
	ctx.lr = 0x8227FEA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
loc_8227FEAC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ffb0
	if (cr6.eq) goto loc_8227FFB0;
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
	ctx.lr = 0x8227FED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e8f28
	ctx.lr = 0x8227FEE0;
	sub_824E8F28(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8227ffa4
	if (!cr6.eq) goto loc_8227FFA4;
	// cmplwi cr6,r27,3
	cr6.compare<uint32_t>(r27.u32, 3, xer);
	// bgt cr6,0x8227ff2c
	if (cr6.gt) goto loc_8227FF2C;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-244
	r12.s64 = r12.s64 + -244;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_8227FF1C;
	case 1:
		goto loc_8227FF24;
	case 2:
		goto loc_8227FF24;
	case 3:
		goto loc_8227FF24;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -228);
	// lwz r17,-220(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -220);
	// lwz r17,-220(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -220);
	// lwz r17,-220(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -220);
loc_8227FF1C:
	// li r6,8
	ctx.r6.s64 = 8;
	// b 0x8227ff30
	goto loc_8227FF30;
loc_8227FF24:
	// li r6,4
	ctx.r6.s64 = 4;
	// b 0x8227ff30
	goto loc_8227FF30;
loc_8227FF2C:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
loc_8227FF30:
	// cmplw cr6,r19,r27
	cr6.compare<uint32_t>(r19.u32, r27.u32, xer);
	// bne cr6,0x8227ff58
	if (!cr6.eq) goto loc_8227FF58;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227FF4C;
	sub_824E9690(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r31,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r31.u8);
	// b 0x8227ffa4
	goto loc_8227FFA4;
loc_8227FF58:
	// add r29,r6,r28
	r29.u64 = ctx.r6.u64 + r28.u64;
	// cmplw cr6,r29,r20
	cr6.compare<uint32_t>(r29.u32, r20.u32, xer);
	// bgt cr6,0x8227ff84
	if (cr6.gt) goto loc_8227FF84;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227FF74;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bne cr6,0x8227ff88
	if (!cr6.eq) goto loc_8227FF88;
loc_8227FF84:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8227FF88:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227ffa0
	if (cr6.eq) goto loc_8227FFA0;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// sld r10,r18,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (r18.u64 << (r11.u8 & 0x7F));
	// std r10,0(r23)
	PPC_STORE_U64(r23.u32 + 0, ctx.r10.u64);
loc_8227FFA0:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8227FFA4:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// blt cr6,0x8227feac
	if (cr6.lt) goto loc_8227FEAC;
loc_8227FFB0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8227FFBC"))) PPC_WEAK_FUNC(sub_8227FFBC);
PPC_FUNC_IMPL(__imp__sub_8227FFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FFC0"))) PPC_WEAK_FUNC(sub_8227FFC0);
PPC_FUNC_IMPL(__imp__sub_8227FFC0) {
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
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8227fff4
	if (cr6.eq) goto loc_8227FFF4;
	// bl 0x82130588
	ctx.lr = 0x8227FFF0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227FFF4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82280008"))) PPC_WEAK_FUNC(sub_82280008);
PPC_FUNC_IMPL(__imp__sub_82280008) {
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
	// blt cr6,0x82280064
	if (cr6.lt) goto loc_82280064;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280064
	if (cr6.eq) goto loc_82280064;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228003C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,564
	ctx.r8.s64 = ctx.r9.s64 + 564;
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
loc_82280064:
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

__attribute__((alias("__imp__sub_8228007C"))) PPC_WEAK_FUNC(sub_8228007C);
PPC_FUNC_IMPL(__imp__sub_8228007C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280080"))) PPC_WEAK_FUNC(sub_82280080);
PPC_FUNC_IMPL(__imp__sub_82280080) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82280088;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280098;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822800A8;
	sub_82270170(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r26,208(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// bl 0x8227e0b0
	ctx.lr = 0x822800B8;
	sub_8227E0B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822801e4
	if (cr6.eq) goto loc_822801E4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822801e4
	if (cr6.eq) goto loc_822801E4;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x822800D8;
	sub_8227F438(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x822800E8;
	sub_8227F438(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822701c8
	ctx.lr = 0x82280100;
	sub_822701C8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r29,r7,3
	r29.s64 = ctx.r7.s64 + 196608;
	// addi r29,r29,-21024
	r29.s64 = r29.s64 + -21024;
	// beq cr6,0x822801e4
	if (cr6.eq) goto loc_822801E4;
	// addi r3,r26,144
	ctx.r3.s64 = r26.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x8228012C;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228015c
	if (cr6.eq) goto loc_8228015C;
	// add r11,r27,r28
	r11.u64 = r27.u64 + r28.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8228015C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822801b4
	if (cr6.eq) goto loc_822801B4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x82280174;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822801b4
	if (cr6.eq) goto loc_822801B4;
	// lbz r11,6(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 6);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822801b4
	if (cr6.eq) goto loc_822801B4;
	// subf r11,r27,r28
	r11.s64 = r28.s64 - r27.s64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// blt cr6,0x822801a4
	if (cr6.lt) goto loc_822801A4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x822801a8
	if (!cr6.gt) goto loc_822801A8;
loc_822801A4:
	// li r11,0
	r11.s64 = 0;
loc_822801A8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822801B4:
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822801e4
	if (!cr6.eq) goto loc_822801E4;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x822801d4
	if (cr6.eq) goto loc_822801D4;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822801d8
	if (!cr6.eq) goto loc_822801D8;
loc_822801D4:
	// li r11,0
	r11.s64 = 0;
loc_822801D8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822801E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822801F0"))) PPC_WEAK_FUNC(sub_822801F0);
PPC_FUNC_IMPL(__imp__sub_822801F0) {
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
	// bl 0x8227e750
	ctx.lr = 0x82280208;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280260
	if (cr6.eq) goto loc_82280260;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e7f8
	ctx.lr = 0x8228021C;
	sub_8227E7F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280260
	if (cr6.eq) goto loc_82280260;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280230;
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
	ctx.lr = 0x82280244;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228024C;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280250;
	sub_82481590(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82280264
	if (cr6.eq) goto loc_82280264;
loc_82280260:
	// li r11,0
	r11.s64 = 0;
loc_82280264:
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

__attribute__((alias("__imp__sub_8228027C"))) PPC_WEAK_FUNC(sub_8228027C);
PPC_FUNC_IMPL(__imp__sub_8228027C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280280"))) PPC_WEAK_FUNC(sub_82280280);
PPC_FUNC_IMPL(__imp__sub_82280280) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x822802A0;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82280308
	if (cr6.eq) goto loc_82280308;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822802B4;
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
	ctx.lr = 0x822802C8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x822802D0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x822802D4;
	sub_82481590(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82280308
	if (cr6.eq) goto loc_82280308;
	// bl 0x82256058
	ctx.lr = 0x822802E4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280308
	if (cr6.eq) goto loc_82280308;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f5f0
	ctx.lr = 0x822802F4;
	sub_8227F5F0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82280308:
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

__attribute__((alias("__imp__sub_82280320"))) PPC_WEAK_FUNC(sub_82280320);
PPC_FUNC_IMPL(__imp__sub_82280320) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280348;
	sub_822701C8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x8228035C;
	sub_82293E30(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82280368;
	sub_8226BE68(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822803a8
	if (cr6.eq) goto loc_822803A8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822803a8
	if (cr6.eq) goto loc_822803A8;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e7f8
	ctx.lr = 0x82280388;
	sub_8227E7F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822803a8
	if (cr6.eq) goto loc_822803A8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x822803A0;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82280408
	if (!cr6.eq) goto loc_82280408;
loc_822803A8:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x822803B4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280410
	if (cr6.eq) goto loc_82280410;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x822803D0;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82280410
	if (cr6.eq) goto loc_82280410;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r31,36(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// bl 0x8226b2f0
	ctx.lr = 0x822803E8;
	sub_8226B2F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82294028
	ctx.lr = 0x822803F8;
	sub_82294028(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x822803FC;
	sub_82293F60(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82280410
	if (!cr6.gt) goto loc_82280410;
loc_82280408:
	// li r11,1
	r11.s64 = 1;
	// b 0x82280414
	goto loc_82280414;
loc_82280410:
	// li r11,0
	r11.s64 = 0;
loc_82280414:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_82280430"))) PPC_WEAK_FUNC(sub_82280430);
PPC_FUNC_IMPL(__imp__sub_82280430) {
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
	ctx.lr = 0x82280438;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// bne cr6,0x822806a0
	if (!cr6.eq) goto loc_822806A0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822804b0
	if (cr6.eq) goto loc_822804B0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823c34d0
	ctx.lr = 0x82280474;
	sub_823C34D0(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82727cc0
	ctx.lr = 0x82280480;
	sub_82727CC0(ctx, base);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82727c48
	ctx.lr = 0x82280488;
	sub_82727C48(ctx, base);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822804a8
	if (cr6.eq) goto loc_822804A8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822804A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822804A8:
	// stw r28,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r28.u32);
	// bl 0x82727640
	ctx.lr = 0x822804B0;
	sub_82727640(ctx, base);
loc_822804B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822804B8;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822804C8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272d70
	ctx.lr = 0x822804D0;
	sub_82272D70(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,716
	ctx.r4.s64 = ctx.r10.s64 + 716;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822804F0;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,268(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82280500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,704
	ctx.r4.s64 = ctx.r7.s64 + 704;
	// addi r31,r6,-17724
	r31.s64 = ctx.r6.s64 + -17724;
	// addi r27,r5,-22108
	r27.s64 = ctx.r5.s64 + -22108;
	// bl 0x82691650
	ctx.lr = 0x82280520;
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
	ctx.lr = 0x82280534;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822805f0
	if (cr6.eq) goto loc_822805F0;
	// lis r27,-32119
	r27.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x82280550;
	sub_82305870(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82280568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-13284
	ctx.r4.s64 = ctx.r9.s64 + -13284;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82280584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r6,-10300
	r28.s64 = ctx.r6.s64 + -10300;
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822805A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x822805AC;
	sub_825EE0E0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r9,496(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 496);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822805C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,20304
	ctx.r4.s64 = ctx.r8.s64 + 20304;
	// lwz r6,44(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822805E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x822805F0;
	sub_823058F8(ctx, base);
loc_822805F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822805F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280608;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82280764
	if (!cr6.eq) goto loc_82280764;
	// li r11,4
	r11.s64 = 4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r10,672
	ctx.r3.s64 = ctx.r10.s64 + 672;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x8228063C;
	sub_82727908(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b1f8
	ctx.lr = 0x82280648;
	sub_8226B1F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228066c
	if (cr6.eq) goto loc_8228066C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228066c
	if (cr6.eq) goto loc_8228066C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826d7118
	ctx.lr = 0x8228066C;
	sub_826D7118(ctx, base);
loc_8228066C:
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lbz r11,756(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 756);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228068c
	if (cr6.eq) goto loc_8228068C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729c80
	ctx.lr = 0x8228068C;
	sub_82729C80(ctx, base);
loc_8228068C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388680
	ctx.lr = 0x82280694;
	sub_82388680(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_822806A0:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82280764
	if (!cr6.eq) goto loc_82280764;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822806d8
	if (!cr6.eq) goto loc_822806D8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,644
	ctx.r3.s64 = r11.s64 + 644;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x822806D4;
	sub_82727908(ctx, base);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
loc_822806D8:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280764
	if (cr6.eq) goto loc_82280764;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-12356(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12356);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82280700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-12012(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x8228070C;
	sub_821F15C8(ctx, base);
	// bl 0x821e60c0
	ctx.lr = 0x82280710;
	sub_821E60C0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822700e8
	ctx.lr = 0x8228071C;
	sub_822700E8(ctx, base);
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463cb0
	ctx.lr = 0x8228072C;
	sub_82463CB0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lbz r7,756(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 756);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82280754
	if (cr6.eq) goto loc_82280754;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729c80
	ctx.lr = 0x82280754;
	sub_82729C80(ctx, base);
loc_82280754:
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// blt cr6,0x82280788
	if (cr6.lt) goto loc_82280788;
	// beq cr6,0x82280770
	if (cr6.eq) goto loc_82280770;
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
loc_82280764:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82280770:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x8268ee10
	ctx.lr = 0x82280784;
	sub_8268EE10(ctx, base);
	// b 0x822807c4
	goto loc_822807C4;
loc_82280788:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x8268ee10
	ctx.lr = 0x8228079C;
	sub_8268EE10(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,636
	ctx.r4.s64 = ctx.r10.s64 + 636;
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
	ctx.lr = 0x822807C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822807C4:
	// lwz r3,-3624(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// bl 0x8226b1f8
	ctx.lr = 0x822807CC;
	sub_8226B1F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822807f0
	if (cr6.eq) goto loc_822807F0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822807f0
	if (cr6.eq) goto loc_822807F0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826d7118
	ctx.lr = 0x822807F0;
	sub_826D7118(ctx, base);
loc_822807F0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822807FC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82280810;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82280824;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// bl 0x82338388
	ctx.lr = 0x82280838;
	sub_82338388(ctx, base);
loc_82280838:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82280844"))) PPC_WEAK_FUNC(sub_82280844);
PPC_FUNC_IMPL(__imp__sub_82280844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280848"))) PPC_WEAK_FUNC(sub_82280848);
PPC_FUNC_IMPL(__imp__sub_82280848) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82280850;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280874;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82280894
	if (!cr6.eq) goto loc_82280894;
loc_82280880:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_82280894:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e750
	ctx.lr = 0x8228089C;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228096c
	if (cr6.eq) goto loc_8228096C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e1b0
	ctx.lr = 0x822808B0;
	sub_8227E1B0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r10,36(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// lfs f30,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f30.f64 = double(temp.f32);
	// blt cr6,0x82280880
	if (cr6.lt) goto loc_82280880;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b2f0
	ctx.lr = 0x822808DC;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x822808E0;
	sub_82293F60(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822808fc
	if (!cr6.lt) goto loc_822808FC;
loc_822808E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822808FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280904;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280914;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228091C;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280920;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822808e8
	if (!cr6.eq) goto loc_822808E8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82280938;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x8228093C;
	sub_82293F60(ctx, base);
	// fsubs f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f31.f64));
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x82280880
	if (cr6.gt) goto loc_82280880;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e250
	ctx.lr = 0x82280954;
	sub_8227E250(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8228096C:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82280978;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228099c
	if (cr6.eq) goto loc_8228099C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82280990;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822809a0
	if (cr6.eq) goto loc_822809A0;
loc_8228099C:
	// li r11,0
	r11.s64 = 0;
loc_822809A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822809B4"))) PPC_WEAK_FUNC(sub_822809B4);
PPC_FUNC_IMPL(__imp__sub_822809B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822809B8"))) PPC_WEAK_FUNC(sub_822809B8);
PPC_FUNC_IMPL(__imp__sub_822809B8) {
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
	ctx.lr = 0x822809C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822809DC;
	sub_822701C8(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82280848
	ctx.lr = 0x822809F4;
	sub_82280848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82280ac8
	if (!cr6.eq) goto loc_82280AC8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280A1C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280A2C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82280A34;
	sub_82272A30(ctx, base);
	// bl 0x82481578
	ctx.lr = 0x82280A38;
	sub_82481578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x82280A50;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82280A68;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82280ac8
	if (!cr6.eq) goto loc_82280AC8;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x82280A7C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280ab8
	if (cr6.eq) goto loc_82280AB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280A90;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280AA0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82280AA8;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280AAC;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82280ac8
	if (!cr6.eq) goto loc_82280AC8;
loc_82280AB8:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82280AC8:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82280AD8"))) PPC_WEAK_FUNC(sub_82280AD8);
PPC_FUNC_IMPL(__imp__sub_82280AD8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82280AE0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280AF0;
	sub_82388580(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82280B00;
	sub_82270170(ctx, base);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// lwz r11,24(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481580
	ctx.lr = 0x82280B30;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226b020
	ctx.lr = 0x82280B44;
	sub_8226B020(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// lbz r11,9(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82280c9c
	if (cr6.eq) goto loc_82280C9C;
	// bl 0x8227e750
	ctx.lr = 0x82280B70;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r28,1
	r28.s64 = 1;
	// li r27,1
	r27.s64 = 1;
	// bl 0x82481590
	ctx.lr = 0x82280B8C;
	sub_82481590(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_82280B98:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82280BAC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280c00
	if (!cr6.eq) goto loc_82280C00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280BCC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280BDC;
	sub_82270170(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bl 0x822577d0
	ctx.lr = 0x82280BF4;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_82280C00:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82280b98
	if (!cr0.eq) goto loc_82280B98;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82280C14;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280c34
	if (cr6.eq) goto loc_82280C34;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82280080
	ctx.lr = 0x82280C28;
	sub_82280080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
loc_82280C34:
	// cmpw cr6,r27,r28
	cr6.compare<int32_t>(r27.s32, r28.s32, xer);
	// bne cr6,0x82280c64
	if (!cr6.eq) goto loc_82280C64;
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bgt cr6,0x82280c54
	if (cr6.gt) goto loc_82280C54;
	// lbz r11,12(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82280c58
	if (cr6.eq) goto loc_82280C58;
loc_82280C54:
	// li r11,1
	r11.s64 = 1;
loc_82280C58:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82280C64:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// ble cr6,0x82280c8c
	if (!cr6.gt) goto loc_82280C8C;
	// srawi r11,r28,1
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x1) != 0);
	r11.s64 = r28.s32 >> 1;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82280c90
	if (cr6.gt) goto loc_82280C90;
loc_82280C8C:
	// li r11,0
	r11.s64 = 0;
loc_82280C90:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82280C9C:
	// bl 0x8227e038
	ctx.lr = 0x82280CA0;
	sub_8227E038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280CB4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280CC4;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x822577d0
	ctx.lr = 0x82280CCC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293e18
	ctx.lr = 0x82280CDC;
	sub_82293E18(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293e18
	ctx.lr = 0x82280CE4;
	sub_82293E18(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280CEC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280D00;
	sub_82270170(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8227d968
	ctx.lr = 0x82280D0C;
	sub_8227D968(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82280D14:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280d7c
	if (cr6.eq) goto loc_82280D7C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d7c
	if (!cr6.eq) goto loc_82280D7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82280D34;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d7c
	if (cr6.eq) goto loc_82280D7C;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82280D4C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280d7c
	if (cr6.eq) goto loc_82280D7C;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227d968
	ctx.lr = 0x82280D64;
	sub_8227D968(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293f28
	ctx.lr = 0x82280D70;
	sub_82293F28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
loc_82280D7C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x82280d14
	if (!cr6.eq) goto loc_82280D14;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82280D98:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82280DA4"))) PPC_WEAK_FUNC(sub_82280DA4);
PPC_FUNC_IMPL(__imp__sub_82280DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280DA8"))) PPC_WEAK_FUNC(sub_82280DA8);
PPC_FUNC_IMPL(__imp__sub_82280DA8) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82280ad8
	ctx.lr = 0x82280DD0;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280e1c
	if (cr6.eq) goto loc_82280E1C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82280e1c
	if (!cr6.eq) goto loc_82280E1C;
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280e1c
	if (!cr6.eq) goto loc_82280E1C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82280E0C;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82280E10;
	sub_82293F60(ctx, base);
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
loc_82280E1C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82280E38"))) PPC_WEAK_FUNC(sub_82280E38);
PPC_FUNC_IMPL(__imp__sub_82280E38) {
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
	ctx.lr = 0x82280E40;
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82280E58;
	sub_8226B2F0(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r9,9008
	ctx.r3.s64 = ctx.r9.s64 + 9008;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x821c07c0
	ctx.lr = 0x82280E80;
	sub_821C07C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280E88;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82280E98;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82280EA0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280EA4;
	sub_82481590(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82280ec0
	if (cr6.eq) goto loc_82280EC0;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// b 0x82280ed8
	goto loc_82280ED8;
loc_82280EC0:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82280edc
	if (!cr6.eq) goto loc_82280EDC;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
loc_82280ED8:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82280EDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 32, temp.u32);
	// bl 0x82280ad8
	ctx.lr = 0x82280EF0;
	sub_82280AD8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r31,r11,-2628
	r31.s64 = r11.s64 + -2628;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822701c8
	ctx.lr = 0x82280F10;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82280f48
	if (!cr6.eq) goto loc_82280F48;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280F2C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280F3C;
	sub_82270170(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822577d0
	ctx.lr = 0x82280F44;
	sub_822577D0(ctx, base);
	// b 0x82280f70
	goto loc_82280F70;
loc_82280F48:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227e750
	ctx.lr = 0x82280F50;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280F68;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x82280F70;
	sub_82295E90(ctx, base);
loc_82280F70:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r27,r11
	r27.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280fb4
	if (!cr6.eq) goto loc_82280FB4;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// bl 0x82389668
	ctx.lr = 0x82280FA8;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
loc_82280FB4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82280fc8
	if (cr6.eq) goto loc_82280FC8;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r29,-28256(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// b 0x82280fdc
	goto loc_82280FDC;
loc_82280FC8:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r29,r8,r9
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
loc_82280FDC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280FE8;
	sub_822701C8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82295e90
	ctx.lr = 0x82280FF0;
	sub_82295E90(ctx, base);
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82281108
	if (!cr6.eq) goto loc_82281108;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82281018
	if (!cr6.eq) goto loc_82281018;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281028
	if (cr6.eq) goto loc_82281028;
loc_82281018:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82281108
	if (!cr6.eq) goto loc_82281108;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
loc_82281028:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293f88
	ctx.lr = 0x82281034;
	sub_82293F88(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822810f0
	if (cr6.eq) goto loc_822810F0;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822810a8
	if (!cr6.eq) goto loc_822810A8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r10,3
	r31.s64 = ctx.r10.s64 + 196608;
	// addi r31,r31,-16384
	r31.s64 = r31.s64 + -16384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654d90
	ctx.lr = 0x82281064;
	sub_82654D90(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-6148(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82655ff8
	ctx.lr = 0x82281080;
	sub_82655FF8(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mulli r10,r3,1056
	ctx.r10.s64 = ctx.r3.s64 * 1056;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r6,r11,11984
	ctx.r6.s64 = r11.s64 + 11984;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8227b770
	ctx.lr = 0x822810A0;
	sub_8227B770(ctx, base);
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9244
	return;
loc_822810A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227e750
	ctx.lr = 0x822810B0;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82250410
	ctx.lr = 0x822810C4;
	sub_82250410(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// bl 0x822701c8
	ctx.lr = 0x822810D4;
	sub_822701C8(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8227fca0
	ctx.lr = 0x822810E0;
	sub_8227FCA0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82281108
	if (!cr6.gt) goto loc_82281108;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// b 0x822810f4
	goto loc_822810F4;
loc_822810F0:
	// li r6,0
	ctx.r6.s64 = 0;
loc_822810F4:
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b770
	ctx.lr = 0x82281108;
	sub_8227B770(ctx, base);
loc_82281108:
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82281110"))) PPC_WEAK_FUNC(sub_82281110);
PPC_FUNC_IMPL(__imp__sub_82281110) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82281134;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281158
	if (cr6.eq) goto loc_82281158;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82281148;
	sub_822A39C8(ctx, base);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82281150;
	sub_822A39C8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822ae7c8
	ctx.lr = 0x82281158;
	sub_822AE7C8(ctx, base);
loc_82281158:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82280430
	ctx.lr = 0x82281164;
	sub_82280430(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82281180;
	sub_82641CB0(ctx, base);
	// addi r3,r3,2832
	ctx.r3.s64 = ctx.r3.s64 + 2832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82281198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,19
	ctx.r4.s64 = 19;
	// bl 0x8268ee10
	ctx.lr = 0x822811AC;
	sub_8268EE10(ctx, base);
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

__attribute__((alias("__imp__sub_822811C4"))) PPC_WEAK_FUNC(sub_822811C4);
PPC_FUNC_IMPL(__imp__sub_822811C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822811C8"))) PPC_WEAK_FUNC(sub_822811C8);
PPC_FUNC_IMPL(__imp__sub_822811C8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x822811D0;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-784(r1)
	ea = -784 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82387b38
	ctx.lr = 0x822811E4;
	sub_82387B38(ctx, base);
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// li r22,0
	r22.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// bl 0x824817c0
	ctx.lr = 0x822811FC;
	sub_824817C0(ctx, base);
	// lbz r10,608(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 608);
	// addi r30,r3,12
	r30.s64 = ctx.r3.s64 + 12;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r9,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x82281214;
	sub_8226B078(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x8228122c
	if (cr6.eq) goto loc_8228122C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ea350
	ctx.lr = 0x8228122C;
	sub_824EA350(ctx, base);
loc_8228122C:
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x824e9038
	ctx.lr = 0x8228123C;
	sub_824E9038(ctx, base);
	// lis r19,-32121
	r19.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// addi r3,r11,4312
	ctx.r3.s64 = r11.s64 + 4312;
	// bl 0x82297350
	ctx.lr = 0x82281250;
	sub_82297350(ctx, base);
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// addi r3,r11,13928
	ctx.r3.s64 = r11.s64 + 13928;
	// bl 0x82297350
	ctx.lr = 0x8228125C;
	sub_82297350(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281a70
	if (cr6.eq) goto loc_82281A70;
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// bl 0x82387b90
	ctx.lr = 0x8228126C;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x82281274;
	sub_8238B7E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822812c0
	if (cr6.lt) goto loc_822812C0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82281290;
	sub_822A3998(ctx, base);
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,8100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8100);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822812b0
	if (cr6.eq) goto loc_822812B0;
	// bl 0x82387b90
	ctx.lr = 0x822812A4;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x822812c0
	if (cr6.eq) goto loc_822812C0;
loc_822812B0:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x826a4718
	ctx.lr = 0x822812C0;
	sub_826A4718(ctx, base);
loc_822812C0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82281310
	if (cr6.lt) goto loc_82281310;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x822812D4;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281310
	if (!cr6.eq) goto loc_82281310;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x822812E8;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281310
	if (cr6.eq) goto loc_82281310;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82281308
	if (cr6.lt) goto loc_82281308;
	// bne cr6,0x82281310
	if (!cr6.eq) goto loc_82281310;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// b 0x82281310
	goto loc_82281310;
loc_82281308:
	// li r11,1
	r11.s64 = 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82281310:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x82281320;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x8227e750
	ctx.lr = 0x8228132C;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r15,-32121
	r15.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822817b0
	if (cr6.eq) goto loc_822817B0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822817b0
	if (cr6.eq) goto loc_822817B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x82281350;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x82281364;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// ori r4,r4,10
	ctx.r4.u64 = ctx.r4.u64 | 10;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x82281378;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// ori r4,r4,35
	ctx.r4.u64 = ctx.r4.u64 | 35;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x8228138C;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// ori r4,r4,11
	ctx.r4.u64 = ctx.r4.u64 | 11;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x822813A0;
	sub_824E9038(ctx, base);
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r10,9048
	ctx.r8.s64 = ctx.r10.s64 + 9048;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lwz r6,4304(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// mr r21,r22
	r21.u64 = r22.u64;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r24,-1
	r24.s64 = -1;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r17,-7884(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -7884);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r29,2124(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2124);
	// lwz r16,2200(r5)
	r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2200);
	// bne cr6,0x822813fc
	if (!cr6.eq) goto loc_822813FC;
	// rotlwi r11,r6,0
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// mr r31,r22
	r31.u64 = r22.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,452(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 452);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82281400
	if (!cr6.gt) goto loc_82281400;
loc_822813FC:
	// li r31,1
	r31.s64 = 1;
loc_82281400:
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// mr r18,r22
	r18.u64 = r22.u64;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r27,r11,3
	r27.s64 = r11.s64 + 196608;
	// addi r27,r27,-21024
	r27.s64 = r27.s64 + -21024;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82397470
	ctx.lr = 0x8228141C;
	sub_82397470(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82281468
	if (!cr6.eq) goto loc_82281468;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281430;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281440;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x8228144C;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281468
	if (cr6.eq) goto loc_82281468;
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,21(r27)
	PPC_STORE_U8(r27.u32 + 21, ctx.r9.u8);
loc_82281468:
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228150c
	if (!cr6.eq) goto loc_8228150C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281480;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281490;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x8228149C;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228150c
	if (cr6.eq) goto loc_8228150C;
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// lwz r9,1896(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1896);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt cr6,0x822814c8
	if (cr6.gt) goto loc_822814C8;
	// li r11,0
	r11.s64 = 0;
loc_822814C8:
	// lbz r10,6(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 6);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lbz r6,4(r27)
	ctx.r6.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lbz r5,5(r27)
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + 5);
	// rlwinm r7,r10,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// ori r4,r9,60000
	ctx.r4.u64 = ctx.r9.u64 | 60000;
	// rlwimi r8,r7,7,17,24
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 7) & 0x7F80) | (ctx.r8.u64 & 0xFFFFFFFFFFFF807F);
	// rlwimi r6,r11,7,17,24
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0x7F80) | (ctx.r6.u64 & 0xFFFFFFFFFFFF807F);
	// clrlwi r3,r8,24
	ctx.r3.u64 = ctx.r8.u32 & 0xFF;
	// stb r5,5(r27)
	PPC_STORE_U8(r27.u32 + 5, ctx.r5.u8);
	// mullw r11,r29,r4
	r11.s64 = int64_t(r29.s32) * int64_t(ctx.r4.s32);
	// stb r6,4(r27)
	PPC_STORE_U8(r27.u32 + 4, ctx.r6.u8);
	// stw r11,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r11.u32);
	// rlwinm r3,r3,0,26,24
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// ori r9,r3,64
	ctx.r9.u64 = ctx.r3.u64 | 64;
	// stb r9,6(r27)
	PPC_STORE_U8(r27.u32 + 6, ctx.r9.u8);
loc_8228150C:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82281528
	if (cr6.eq) goto loc_82281528;
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r24,984(r10)
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + 984);
loc_82281528:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x82281588
	if (cr6.lt) goto loc_82281588;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x8228153C;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x8228155c
	if (!cr6.eq) goto loc_8228155C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x82281550;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228155c
	if (cr6.eq) goto loc_8228155C;
	// lwz r21,0(r3)
	r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8228155C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x82281568;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281588
	if (!cr6.eq) goto loc_82281588;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x8228157C;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281588
	if (cr6.eq) goto loc_82281588;
	// lwz r22,0(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_82281588:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// blt cr6,0x822815e4
	if (cr6.lt) goto loc_822815E4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x8228159C;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x822815e4
	if (!cr6.eq) goto loc_822815E4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x822815B0;
	sub_824E95F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822815e4
	if (cr6.eq) goto loc_822815E4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822815C8;
	sub_822F10D0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238eb90
	ctx.lr = 0x822815D0;
	sub_8238EB90(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82295f70
	ctx.lr = 0x822815E4;
	sub_82295F70(ctx, base);
loc_822815E4:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// blt cr6,0x82281624
	if (cr6.lt) goto loc_82281624;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x822815F8;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281624
	if (!cr6.eq) goto loc_82281624;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x8228160C;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281624
	if (cr6.eq) goto loc_82281624;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x82281624;
	sub_82295F70(ctx, base);
loc_82281624:
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// blt cr6,0x82281658
	if (cr6.lt) goto loc_82281658;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x82281638;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281658
	if (!cr6.eq) goto loc_82281658;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x8228164C;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281658
	if (cr6.eq) goto loc_82281658;
	// lwz r18,0(r3)
	r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_82281658:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281660;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281670;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82281678;
	sub_82502300(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281684;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281694;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x822816A0;
	sub_82274128(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816B0;
	sub_82295F70(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816C0;
	sub_82295F70(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816D0;
	sub_82295F70(ctx, base);
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// beq cr6,0x822816e8
	if (cr6.eq) goto loc_822816E8;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816E8;
	sub_82295F70(ctx, base);
loc_822816E8:
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r11,3
	r31.s64 = r11.s64 + 196608;
	// addi r31,r31,-16384
	r31.s64 = r31.s64 + -16384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654d90
	ctx.lr = 0x82281700;
	sub_82654D90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281738
	if (cr6.eq) goto loc_82281738;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-6148(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82655ff8
	ctx.lr = 0x8228171C;
	sub_82655FF8(ctx, base);
	// mulli r11,r3,1056
	r11.s64 = ctx.r3.s64 * 1056;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,11984
	ctx.r5.s64 = r11.s64 + 11984;
	// bl 0x8227fbc0
	ctx.lr = 0x82281734;
	sub_8227FBC0(ctx, base);
	// b 0x82281744
	goto loc_82281744;
loc_82281738:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295828
	ctx.lr = 0x82281744;
	sub_82295828(ctx, base);
loc_82281744:
	// li r4,6
	ctx.r4.s64 = 6;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82296088
	ctx.lr = 0x82281754;
	sub_82296088(ctx, base);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295d70
	ctx.lr = 0x82281764;
	sub_82295D70(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295bc8
	ctx.lr = 0x82281774;
	sub_82295BC8(ctx, base);
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295d70
	ctx.lr = 0x82281784;
	sub_82295D70(ctx, base);
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x82281794;
	sub_82295F70(ctx, base);
	// stw r18,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r18.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295bc8
	ctx.lr = 0x822817A8;
	sub_82295BC8(ctx, base);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r22,0
	r22.s64 = 0;
loc_822817B0:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x82280430
	ctx.lr = 0x822817BC;
	sub_82280430(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a70
	if (cr6.eq) goto loc_82281A70;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82280430
	ctx.lr = 0x822817D4;
	sub_82280430(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a70
	if (cr6.eq) goto loc_82281A70;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8268ee10
	ctx.lr = 0x822817F4;
	sub_8268EE10(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,0(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x8268ee10
	ctx.lr = 0x82281808;
	sub_8268EE10(ctx, base);
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,728
	ctx.r4.s64 = ctx.r10.s64 + 728;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82281820;
	sub_82691650(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82281870
	if (cr6.eq) goto loc_82281870;
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x82281844
	if (!cr6.eq) goto loc_82281844;
	// mr r31,r22
	r31.u64 = r22.u64;
loc_82281844:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824815a0
	ctx.lr = 0x8228184C;
	sub_824815A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x8268dcb0
	ctx.lr = 0x82281868;
	sub_8268DCB0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268dd70
	ctx.lr = 0x82281870;
	sub_8268DD70(ctx, base);
loc_82281870:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x8228187C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822818ec
	if (cr6.eq) goto loc_822818EC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82281890;
	sub_822A39C8(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x82281894;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r30,1316(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1316);
	// bl 0x822a39c8
	ctx.lr = 0x822818A4;
	sub_822A39C8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822ae7c8
	ctx.lr = 0x822818AC;
	sub_822AE7C8(ctx, base);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822818B4;
	sub_822A39C8(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822818ec
	if (cr6.eq) goto loc_822818EC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822818C8;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822818ec
	if (cr6.eq) goto loc_822818EC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822818E8;
	sub_822A39C8(ctx, base);
	// bl 0x822a57d0
	ctx.lr = 0x822818EC;
	sub_822A57D0(ctx, base);
loc_822818EC:
	// bl 0x82387b90
	ctx.lr = 0x822818F0;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,1316(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1316);
	// bl 0x82388580
	ctx.lr = 0x82281900;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281910;
	sub_82270170(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x8228191C;
	sub_82274128(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x82281920;
	sub_82387B90(ctx, base);
	// lwz r9,1344(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// mulli r11,r9,8176
	r11.s64 = ctx.r9.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f6b0
	ctx.lr = 0x82281934;
	sub_8238F6B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281940;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281950;
	sub_82270170(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x8228195C;
	sub_82274128(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lwz r3,-12640(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12640);
	// lbz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82281980
	if (cr6.eq) goto loc_82281980;
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82281984
	if (cr6.eq) goto loc_82281984;
loc_82281980:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82281984:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822819a4
	if (cr6.eq) goto loc_822819A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822819A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822819A4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stb r22,796(r9)
	PPC_STORE_U8(ctx.r9.u32 + 796, r22.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822819C4;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822819DC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822819F8;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82281A20;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82281A38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82281A44;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x82281a5c
	if (!cr6.eq) goto loc_82281A5C;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82281A5C:
	// lwz r3,1020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 1020);
	// bl 0x82308888
	ctx.lr = 0x82281A64;
	sub_82308888(ctx, base);
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_82281A70:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x8268ee10
	ctx.lr = 0x82281A84;
	sub_8268EE10(ctx, base);
loc_82281A84:
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82281A90"))) PPC_WEAK_FUNC(sub_82281A90);
PPC_FUNC_IMPL(__imp__sub_82281A90) {
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
	ctx.lr = 0x82281A98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r28,r10,r11
	r28.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x822577d0
	ctx.lr = 0x82281AC0;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82281b18
	if (!cr6.eq) goto loc_82281B18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// ble cr6,0x82281afc
	if (!cr6.gt) goto loc_82281AFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8227b860
	ctx.lr = 0x82281AE8;
	sub_8227B860(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82281AFC:
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8227b860
	ctx.lr = 0x82281B04;
	sub_8227B860(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82281B18:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// ble cr6,0x82281b60
	if (!cr6.gt) goto loc_82281B60;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82281ba0
	if (!cr6.eq) goto loc_82281BA0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b860
	ctx.lr = 0x82281B40;
	sub_8227B860(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82281B60:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// bge cr6,0x82281ba0
	if (!cr6.lt) goto loc_82281BA0;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82281ba0
	if (!cr6.eq) goto loc_82281BA0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b860
	ctx.lr = 0x82281B88;
	sub_8227B860(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_82281BA0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82281BA8"))) PPC_WEAK_FUNC(sub_82281BA8);
PPC_FUNC_IMPL(__imp__sub_82281BA8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x82281BCC;
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
	ctx.lr = 0x82281BE0;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82281BF4;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x82281C08;
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
	ctx.lr = 0x82281C20;
	sub_822183B0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r4,r7,744
	ctx.r4.s64 = ctx.r7.s64 + 744;
	// lwz r3,-10028(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// lfs f1,30712(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82208800
	ctx.lr = 0x82281C3C;
	sub_82208800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e750
	ctx.lr = 0x82281C44;
	sub_8227E750(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82281C58;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203310
	ctx.lr = 0x82281C6C;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281C84;
	sub_8227F438(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281C94;
	sub_8227F438(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82281a90
	ctx.lr = 0x82281CAC;
	sub_82281A90(ctx, base);
loc_82281CAC:
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

__attribute__((alias("__imp__sub_82281CC4"))) PPC_WEAK_FUNC(sub_82281CC4);
PPC_FUNC_IMPL(__imp__sub_82281CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82281CC8"))) PPC_WEAK_FUNC(sub_82281CC8);
PPC_FUNC_IMPL(__imp__sub_82281CC8) {
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
	ctx.lr = 0x82281CD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82281CF0;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281CFC;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281D0C;
	sub_82270170(ctx, base);
	// lwz r27,208(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82281D2C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82281D44;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82281D5C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82281D70;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82281e04
	if (!cr6.eq) goto loc_82281E04;
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82281e04
	if (!cr6.lt) goto loc_82281E04;
	// addi r30,r27,12
	r30.s64 = r27.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_82281D8C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281df8
	if (cr6.eq) goto loc_82281DF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82281DA0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281df8
	if (cr6.eq) goto loc_82281DF8;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82281DB8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281df8
	if (cr6.eq) goto loc_82281DF8;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82281DCC;
	sub_822051A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82281df8
	if (!cr6.gt) goto loc_82281DF8;
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x82281de8
	if (cr6.lt) goto loc_82281DE8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82281df8
	if (!cr6.lt) goto loc_82281DF8;
loc_82281DE8:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82281DF4;
	sub_822051A0(ctx, base);
	// stw r3,40(r28)
	PPC_STORE_U32(r28.u32 + 40, ctx.r3.u32);
loc_82281DF8:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82281d8c
	if (!cr0.eq) goto loc_82281D8C;
loc_82281E04:
	// lwz r11,204(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 204);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82281E28;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// addi r3,r27,144
	ctx.r3.s64 = r27.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x82281E44;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82281e98
	if (!cr6.eq) goto loc_82281E98;
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82281e64
	if (cr6.eq) goto loc_82281E64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82281e98
	if (!cr6.eq) goto loc_82281E98;
loc_82281E64:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281E70;
	sub_8227F438(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281E80;
	sub_8227F438(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82281a90
	ctx.lr = 0x82281E98;
	sub_82281A90(ctx, base);
loc_82281E98:
	// bl 0x82256058
	ctx.lr = 0x82281E9C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281f60
	if (cr6.eq) goto loc_82281F60;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82281f60
	if (!cr6.eq) goto loc_82281F60;
	// lwz r11,204(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 204);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82281ee0
	if (!cr6.eq) goto loc_82281EE0;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281f60
	if (cr6.eq) goto loc_82281F60;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822577d0
	ctx.lr = 0x82281ED8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bne cr6,0x82281f60
	if (!cr6.eq) goto loc_82281F60;
loc_82281EE0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,44
	ctx.r4.s64 = 44;
	// ori r30,r11,16256
	r30.u64 = r11.u64 | 16256;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82281F00;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82281F10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82281f60
	if (cr6.eq) goto loc_82281F60;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,764
	ctx.r4.s64 = ctx.r9.s64 + 764;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r29,-10020(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82281F3C;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r29,340
	ctx.r3.s64 = r29.s64 + 340;
	// bl 0x826cac98
	ctx.lr = 0x82281F48;
	sub_826CAC98(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82281F5C;
	sub_82641CB0(ctx, base);
	// bl 0x8227d228
	ctx.lr = 0x82281F60;
	sub_8227D228(ctx, base);
loc_82281F60:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x8268ee10
	ctx.lr = 0x82281F74;
	sub_8268EE10(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82281F7C"))) PPC_WEAK_FUNC(sub_82281F7C);
PPC_FUNC_IMPL(__imp__sub_82281F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82281F80"))) PPC_WEAK_FUNC(sub_82281F80);
PPC_FUNC_IMPL(__imp__sub_82281F80) {
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
	ctx.lr = 0x82281FAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x82281fd0
	if (!cr6.eq) goto loc_82281FD0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281fd0
	if (cr6.eq) goto loc_82281FD0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,484
	ctx.r10.s64 = r11.s64 + 484;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82281fd4
	goto loc_82281FD4;
loc_82281FD0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82281FD4:
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

__attribute__((alias("__imp__sub_82281FEC"))) PPC_WEAK_FUNC(sub_82281FEC);
PPC_FUNC_IMPL(__imp__sub_82281FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82281FF0"))) PPC_WEAK_FUNC(sub_82281FF0);
PPC_FUNC_IMPL(__imp__sub_82281FF0) {
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
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82282030
	if (cr6.eq) goto loc_82282030;
	// bl 0x82130588
	ctx.lr = 0x8228202C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82282030:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82282044"))) PPC_WEAK_FUNC(sub_82282044);
PPC_FUNC_IMPL(__imp__sub_82282044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282048"))) PPC_WEAK_FUNC(sub_82282048);
PPC_FUNC_IMPL(__imp__sub_82282048) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,524(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 524);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82282050"))) PPC_WEAK_FUNC(sub_82282050);
PPC_FUNC_IMPL(__imp__sub_82282050) {
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
	ctx.lr = 0x82282058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282068;
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
	ctx.lr = 0x8228207C;
	sub_82270170(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,208(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// bl 0x8227e750
	ctx.lr = 0x8228208C;
	sub_8227E750(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228213c
	if (cr6.eq) goto loc_8228213C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x822820A0;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228213c
	if (cr6.eq) goto loc_8228213C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228213c
	if (cr6.eq) goto loc_8228213C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227f438
	ctx.lr = 0x822820C0;
	sub_8227F438(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227f438
	ctx.lr = 0x822820D0;
	sub_8227F438(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// li r28,31
	r28.s64 = 31;
loc_822820DC:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82282130
	if (cr6.eq) goto loc_82282130;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82282130
	if (!cr6.eq) goto loc_82282130;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822820FC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282130
	if (cr6.eq) goto loc_82282130;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82282114;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82282130
	if (cr6.eq) goto loc_82282130;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82281a90
	ctx.lr = 0x82282130;
	sub_82281A90(ctx, base);
loc_82282130:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822820dc
	if (!cr0.eq) goto loc_822820DC;
loc_8228213C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82282144"))) PPC_WEAK_FUNC(sub_82282144);
PPC_FUNC_IMPL(__imp__sub_82282144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282148"))) PPC_WEAK_FUNC(sub_82282148);
PPC_FUNC_IMPL(__imp__sub_82282148) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82282150;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2176
	ctx.r6.s64 = ctx.r8.s64 + 2176;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,2176(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, r11.u32);
	// clrlwi r3,r11,1
	ctx.r3.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// srawi r11,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r11.s64 = ctx.r3.s32 >> 1;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r9,r3
	r11.s64 = ctx.r3.s64 - ctx.r9.s64;
	// addi r27,r11,1
	r27.s64 = r11.s64 + 1;
	// bl 0x82387b90
	ctx.lr = 0x822821A0;
	sub_82387B90(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r8,1344(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1344);
	// mulli r11,r8,8176
	r11.s64 = ctx.r8.s64 * 8176;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r29,r11,1360
	r29.s64 = r11.s64 + 1360;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f998
	ctx.lr = 0x822821BC;
	sub_8238F998(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82280430
	ctx.lr = 0x822821CC;
	sub_82280430(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// lfs f0,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stb r6,14(r31)
	PPC_STORE_U8(r31.u32 + 14, ctx.r6.u8);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// bl 0x82388580
	ctx.lr = 0x822821F8;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82282208;
	sub_82270170(ctx, base);
	// addic. r3,r3,112
	xer.ca = ctx.r3.u32 > 4294967183;
	ctx.r3.s64 = ctx.r3.s64 + 112;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82282214
	if (cr0.eq) goto loc_82282214;
	// bl 0x82273218
	ctx.lr = 0x82282214;
	sub_82273218(ctx, base);
loc_82282214:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228221C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228222C;
	sub_82270170(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,279(r3)
	PPC_STORE_U8(ctx.r3.u32 + 279, ctx.r10.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228223C;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228224C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282258;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r26,4(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x82388580
	ctx.lr = 0x82282264;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282274;
	sub_82270170(ctx, base);
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x82274120
	ctx.lr = 0x82282280;
	sub_82274120(ctx, base);
	// lwz r7,48(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// rlwinm r6,r7,0,16,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFF00;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822822bc
	if (cr6.eq) goto loc_822822BC;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// bl 0x82396408
	ctx.lr = 0x82282298;
	sub_82396408(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822822A4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822822B4;
	sub_82270170(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// b 0x822822ec
	goto loc_822822EC;
loc_822822BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822822C4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r28,-10240(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8238f1e8
	ctx.lr = 0x822822D8;
	sub_8238F1E8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82270170
	ctx.lr = 0x822822E8;
	sub_82270170(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
loc_822822EC:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82274120
	ctx.lr = 0x822822F4;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822822FC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r28,r10,9000
	r28.s64 = ctx.r10.s64 + 9000;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282314;
	sub_82270170(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82272d48
	ctx.lr = 0x82282320;
	sub_82272D48(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282328;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282338;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282344;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228234C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228235C;
	sub_82270170(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274128
	ctx.lr = 0x82282368;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282370;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282380;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8228238C;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282394;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822823A4;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822823B0;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822823B8;
	sub_82388580(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822823C8;
	sub_82270170(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822823D4;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822823DC;
	sub_82388580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822823EC;
	sub_82270170(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822823F8;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282400;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282410;
	sub_82270170(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8228241C;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282424;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282434;
	sub_82270170(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282440;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282448;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282458;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282464;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228246C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228247C;
	sub_82270170(ctx, base);
	// li r4,13
	ctx.r4.s64 = 13;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282488;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282490;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822824A0;
	sub_82270170(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82274128
	ctx.lr = 0x822824AC;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,1316(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 1316);
	// bl 0x82388580
	ctx.lr = 0x822824B8;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822824C8;
	sub_82270170(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x822824D4;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822824DC;
	sub_82388580(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822824EC;
	sub_82270170(ctx, base);
	// li r4,17
	ctx.r4.s64 = 17;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822824F8;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282500;
	sub_82388580(ctx, base);
	// lwz r28,4(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x8238f6b0
	ctx.lr = 0x82282510;
	sub_8238F6B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82270170
	ctx.lr = 0x82282520;
	sub_82270170(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82274128
	ctx.lr = 0x8228252C;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282534;
	sub_82388580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282544;
	sub_82270170(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282550;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282558;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282568;
	sub_82270170(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x82282574;
	sub_82274120(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8228257C"))) PPC_WEAK_FUNC(sub_8228257C);
PPC_FUNC_IMPL(__imp__sub_8228257C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282580"))) PPC_WEAK_FUNC(sub_82282580);
PPC_FUNC_IMPL(__imp__sub_82282580) {
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
	ctx.lr = 0x82282588;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x823896c0
	ctx.lr = 0x8228259C;
	sub_823896C0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x8238eb20
	ctx.lr = 0x822825A4;
	sub_8238EB20(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x822825B4;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228274c
	if (cr6.eq) goto loc_8228274C;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8228267c
	if (!cr6.eq) goto loc_8228267C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x822825D8;
	sub_8226B2F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822825E0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822825F8;
	sub_82270170(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82272d48
	ctx.lr = 0x82282604;
	sub_82272D48(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228260C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228261C;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82274128
	ctx.lr = 0x82282628;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282630;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282640;
	sub_82270170(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x8228264C;
	sub_82274128(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82280ad8
	ctx.lr = 0x82282654;
	sub_82280AD8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82282780
	if (cr6.eq) goto loc_82282780;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r5,13(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 13);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82280da8
	ctx.lr = 0x82282674;
	sub_82280DA8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8228267C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82282690;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822801f0
	ctx.lr = 0x8228269C;
	sub_822801F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82282780
	if (cr6.eq) goto loc_82282780;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82282780
	if (cr6.eq) goto loc_82282780;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822826C0;
	sub_82295F70(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822826D0;
	sub_82295F70(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822826E0;
	sub_82295F70(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r10,3
	r30.s64 = ctx.r10.s64 + 196608;
	// addi r30,r30,-16384
	r30.s64 = r30.s64 + -16384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82654d90
	ctx.lr = 0x822826FC;
	sub_82654D90(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82282738
	if (cr6.eq) goto loc_82282738;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,-6148(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82655ff8
	ctx.lr = 0x82282718;
	sub_82655FF8(ctx, base);
	// mulli r11,r3,1056
	r11.s64 = ctx.r3.s64 * 1056;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,11984
	ctx.r5.s64 = r11.s64 + 11984;
	// bl 0x8227fbc0
	ctx.lr = 0x82282730;
	sub_8227FBC0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82282738:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295828
	ctx.lr = 0x82282744;
	sub_82295828(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8228274C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r9,4304(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r30,984(r8)
	PPC_STORE_U32(ctx.r8.u32 + 984, r30.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r7,4304(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r28,528(r6)
	PPC_STORE_U32(ctx.r6.u32 + 528, r28.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r5,4304(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r27,1136(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1136, r27.u32);
loc_82282780:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82282788"))) PPC_WEAK_FUNC(sub_82282788);
PPC_FUNC_IMPL(__imp__sub_82282788) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82282790;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822827b4
	if (!cr6.eq) goto loc_822827B4;
	// li r4,10
	ctx.r4.s64 = 10;
	// b 0x82282c18
	goto loc_82282C18;
loc_822827B4:
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
	ctx.lr = 0x822827D8;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822827E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r26,1
	r26.s64 = 1;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822828a8
	if (cr6.eq) goto loc_822828A8;
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
	ctx.lr = 0x82282818;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82282898
	if (!cr6.eq) goto loc_82282898;
	// bl 0x82207e88
	ctx.lr = 0x82282828;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82282898
	if (!cr6.eq) goto loc_82282898;
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
	// bne cr6,0x82282874
	if (!cr6.eq) goto loc_82282874;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2012
	ctx.r4.s64 = r11.s64 + -2012;
	// bl 0x82691650
	ctx.lr = 0x8228285C;
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
	ctx.lr = 0x82282870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822828a8
	goto loc_822828A8;
loc_82282874:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2032
	ctx.r4.s64 = r11.s64 + -2032;
	// bl 0x82691650
	ctx.lr = 0x82282880;
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
	ctx.lr = 0x82282894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822828a8
	goto loc_822828A8;
loc_82282898:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822828A4;
	sub_82691650(ctx, base);
	// stb r26,103(r3)
	PPC_STORE_U8(ctx.r3.u32 + 103, r26.u8);
loc_822828A8:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822828BC;
	sub_822701C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r10,15900
	ctx.r3.s64 = ctx.r10.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x822828CC;
	sub_82293F60(ctx, base);
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b330
	ctx.lr = 0x822828D8;
	sub_8226B330(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82282c14
	if (cr6.eq) goto loc_82282C14;
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82282c14
	if (!cr6.eq) goto loc_82282C14;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82282c14
	if (cr6.eq) goto loc_82282C14;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227e038
	ctx.lr = 0x82282904;
	sub_8227E038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282c14
	if (cr6.eq) goto loc_82282C14;
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// fsubs f0,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - f30.f64));
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82282c14
	if (!cr6.gt) goto loc_82282C14;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82282938;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282944;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282954;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x82282960;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282968;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282978;
	sub_82270170(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282984;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228298C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228299C;
	sub_82270170(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x822829A8;
	sub_82274128(ctx, base);
	// stw r26,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r26.u32);
	// bl 0x822919d8
	ctx.lr = 0x822829B0;
	sub_822919D8(ctx, base);
	// lwz r7,16(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x82282a24
	if (!cr6.eq) goto loc_82282A24;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x822829C4;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282a24
	if (cr6.eq) goto loc_82282A24;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227f438
	ctx.lr = 0x822829DC;
	sub_8227F438(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227f438
	ctx.lr = 0x822829EC;
	sub_8227F438(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822829F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r29,r1,92
	r29.s64 = ctx.r1.s64 + 92;
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282A10;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82281a90
	ctx.lr = 0x82282A24;
	sub_82281A90(ctx, base);
loc_82282A24:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,34
	ctx.r4.s64 = 34;
	// bl 0x8268ee10
	ctx.lr = 0x82282A38;
	sub_8268EE10(ctx, base);
	// lwz r3,880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 880);
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,13
	cr6.compare<int32_t>(ctx.r10.s32, 13, xer);
	// bne cr6,0x82282a74
	if (!cr6.eq) goto loc_82282A74;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x82282A60;
	sub_822AFCD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5578
	ctx.lr = 0x82282A68;
	sub_822A5578(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
loc_82282A74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x82282A7C;
	sub_824F0498(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82295538
	ctx.lr = 0x82282A8C;
	sub_82295538(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82295e90
	ctx.lr = 0x82282A98;
	sub_82295E90(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x82282b9c
	if (!cr6.eq) goto loc_82282B9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282AB4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282AC4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82282ACC;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0570
	ctx.lr = 0x82282AD8;
	sub_824F0570(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282b9c
	if (cr6.eq) goto loc_82282B9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282AEC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282AFC;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82282b9c
	if (cr6.eq) goto loc_82282B9C;
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,808
	ctx.r4.s64 = r11.s64 + 808;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82282B2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282B34;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282B44;
	sub_82270170(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x82296dd8
	ctx.lr = 0x82282B50;
	sub_82296DD8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82282b9c
	if (cr6.eq) goto loc_82282B9C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82250410
	ctx.lr = 0x82282B64;
	sub_82250410(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227fca0
	ctx.lr = 0x82282B74;
	sub_8227FCA0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82282b9c
	if (!cr6.gt) goto loc_82282B9C;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x82282B84;
	sub_824E7118(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// addi r3,r11,11984
	ctx.r3.s64 = r11.s64 + 11984;
	// bl 0x82251260
	ctx.lr = 0x82282B9C;
	sub_82251260(ctx, base);
loc_82282B9C:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82282c28
	if (!cr6.eq) goto loc_82282C28;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282BB0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282BC0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82282BC8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0570
	ctx.lr = 0x82282BD4;
	sub_824F0570(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282c28
	if (cr6.eq) goto loc_82282C28;
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,800
	ctx.r4.s64 = r11.s64 + 800;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82282C04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82282C14:
	// li r4,3
	ctx.r4.s64 = 3;
loc_82282C18:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8268ee10
	ctx.lr = 0x82282C28;
	sub_8268EE10(ctx, base);
loc_82282C28:
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82282C38"))) PPC_WEAK_FUNC(sub_82282C38);
PPC_FUNC_IMPL(__imp__sub_82282C38) {
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
	ctx.lr = 0x82282C40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x8227e038
	ctx.lr = 0x82282C58;
	sub_8227E038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282c74
	if (cr6.eq) goto loc_82282C74;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,15764(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15764);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82282eac
	if (!cr6.eq) goto loc_82282EAC;
loc_82282C74:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82282C90;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82293eb0
	ctx.lr = 0x82282C9C;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// stw r25,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r25.u32);
	// bne cr6,0x82282cdc
	if (!cr6.eq) goto loc_82282CDC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282CBC;
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
	ctx.lr = 0x82282CD0;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282CDC;
	sub_82274128(ctx, base);
loc_82282CDC:
	// lis r26,-32115
	r26.s64 = -2104688640;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,-12672(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -12672);
	// subf r10,r27,r11
	ctx.r10.s64 = r11.s64 - r27.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82282d20
	if (!cr6.eq) goto loc_82282D20;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82389668
	ctx.lr = 0x82282D14;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
loc_82282D20:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82282d34
	if (cr6.eq) goto loc_82282D34;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r29,-28256(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// b 0x82282d48
	goto loc_82282D48;
loc_82282D34:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r29,r8,r9
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
loc_82282D48:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82282d78
	if (cr6.eq) goto loc_82282D78;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82282eac
	if (!cr6.eq) goto loc_82282EAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293eb0
	ctx.lr = 0x82282D6C;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
loc_82282D78:
	// li r30,0
	r30.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82291968
	ctx.lr = 0x82282D8C;
	sub_82291968(ctx, base);
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282dac
	if (cr6.eq) goto loc_82282DAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82282788
	ctx.lr = 0x82282DA0;
	sub_82282788(ctx, base);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82282DAC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82282e98
	if (!cr6.eq) goto loc_82282E98;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x822090b8
	ctx.lr = 0x82282DC8;
	sub_822090B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282e98
	if (cr6.eq) goto loc_82282E98;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82282DE4;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282e98
	if (cr6.eq) goto loc_82282E98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x8227e5a0
	ctx.lr = 0x82282DFC;
	sub_8227E5A0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r31,-10244(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x823896c0
	ctx.lr = 0x82282E18;
	sub_823896C0(ctx, base);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-27892
	ctx.r8.s64 = ctx.r10.s64 + -27892;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x82218310
	ctx.lr = 0x82282E30;
	sub_82218310(ctx, base);
	// lwz r11,-12672(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -12672);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x82282e48
	if (!cr6.eq) goto loc_82282E48;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
loc_82282E48:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r30,-10244(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82282E64;
	sub_82641CB0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,15768
	ctx.r4.s64 = ctx.r10.s64 + 15768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82282E78;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r28,16
	ctx.r4.s64 = r28.s64 + 16;
	// addi r3,r29,2832
	ctx.r3.s64 = r29.s64 + 2832;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x8264f2f8
	ctx.lr = 0x82282E90;
	sub_8264F2F8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82282E98:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x8268ee10
	ctx.lr = 0x82282EAC;
	sub_8268EE10(ctx, base);
loc_82282EAC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82282EB4"))) PPC_WEAK_FUNC(sub_82282EB4);
PPC_FUNC_IMPL(__imp__sub_82282EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282EB8"))) PPC_WEAK_FUNC(sub_82282EB8);
PPC_FUNC_IMPL(__imp__sub_82282EB8) {
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
	ctx.lr = 0x82282EC0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82282EDC;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283114
	if (cr6.eq) goto loc_82283114;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-3624(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x82282EF4;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293e18
	ctx.lr = 0x82282F08;
	sub_82293E18(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82282F14;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x82282F30;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,9000
	ctx.r4.s64 = r11.s64 + 9000;
	// bl 0x82293e78
	ctx.lr = 0x82282F48;
	sub_82293E78(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82282F60;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293eb0
	ctx.lr = 0x82282F6C;
	sub_82293EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,15764(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15764);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82282fdc
	if (!cr6.eq) goto loc_82282FDC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824f0498
	ctx.lr = 0x82282F90;
	sub_824F0498(ctx, base);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x82282FA0;
	sub_82295538(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e670
	ctx.lr = 0x82282FAC;
	sub_8227E670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// lwz r30,136(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// bl 0x82295e90
	ctx.lr = 0x82282FC8;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82282c38
	ctx.lr = 0x82282FDC;
	sub_82282C38(ctx, base);
loc_82282FDC:
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82282FE8;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283074
	if (cr6.eq) goto loc_82283074;
	// lbz r7,102(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 102);
	// li r8,255
	ctx.r8.s64 = 255;
	// lbz r5,97(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// li r11,0
	r11.s64 = 0;
	// ori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 | 128;
	// lbz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 100);
	// stb r8,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r8.u8);
	// ori r9,r5,224
	ctx.r9.u64 = ctx.r5.u64 | 224;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// clrlwi r3,r6,25
	ctx.r3.u64 = ctx.r6.u32 & 0x7F;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// ori r8,r10,64
	ctx.r8.u64 = ctx.r10.u64 | 64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stb r3,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r3.u8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// li r4,18
	ctx.r4.s64 = 18;
	// stb r9,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r11.u8);
	// stb r11,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r11.u8);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stb r8,102(r1)
	PPC_STORE_U8(ctx.r1.u32 + 102, ctx.r8.u8);
	// bl 0x82295538
	ctx.lr = 0x82283058;
	sub_82295538(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r6,3
	ctx.r3.s64 = ctx.r6.s64 + 196608;
	// addi r3,r3,-21024
	ctx.r3.s64 = ctx.r3.s64 + -21024;
	// bl 0x8227d1b0
	ctx.lr = 0x82283074;
	sub_8227D1B0(ctx, base);
loc_82283074:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227ebb0
	ctx.lr = 0x8228307C;
	sub_8227EBB0(ctx, base);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82283114
	if (cr6.eq) goto loc_82283114;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82283094;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822830d0
	if (!cr6.eq) goto loc_822830D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x822830AC;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822830d0
	if (!cr6.eq) goto loc_822830D0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x822830C4;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283114
	if (cr6.eq) goto loc_82283114;
loc_822830D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822830D8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,-10240(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8227e750
	ctx.lr = 0x822830EC;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r31,r8,1
	r31.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82270170
	ctx.lr = 0x82283108;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x82283114;
	sub_82274128(ctx, base);
loc_82283114:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228311C"))) PPC_WEAK_FUNC(sub_8228311C);
PPC_FUNC_IMPL(__imp__sub_8228311C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82283120"))) PPC_WEAK_FUNC(sub_82283120);
PPC_FUNC_IMPL(__imp__sub_82283120) {
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
	ctx.lr = 0x82283128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283150
	if (cr6.eq) goto loc_82283150;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82283150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82283150:
	// lwz r31,8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822831b4
	if (cr6.eq) goto loc_822831B4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82283174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r28,r9,-28
	r28.s64 = ctx.r9.s64 + -28;
	// addi r7,r8,68
	ctx.r7.s64 = ctx.r8.s64 + 68;
	// stw r28,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r28.u32);
	// addi r3,r30,52
	ctx.r3.s64 = r30.s64 + 52;
	// stw r7,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r7.u32);
	// stw r28,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r28.u32);
	// bl 0x82130000
	ctx.lr = 0x82283198;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b58
	ctx.lr = 0x822831A0;
	sub_824E6B58(ctx, base);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// bl 0x82130588
	ctx.lr = 0x822831B4;
	sub_82130588(ctx, base);
loc_822831B4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,64(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// addi r31,r29,44
	r31.s64 = r29.s64 + 44;
	// addi r10,r11,-11804
	ctx.r10.s64 = r11.s64 + -11804;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r10.u32);
	// beq cr6,0x822831e0
	if (cr6.eq) goto loc_822831E0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x822831D8;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_822831E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822831E8"))) PPC_WEAK_FUNC(sub_822831E8);
PPC_FUNC_IMPL(__imp__sub_822831E8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822831F0;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82283210;
	sub_822701C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228321C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228322C;
	sub_82270170(ctx, base);
	// lwz r4,20(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r4,5
	cr6.compare<int32_t>(ctx.r4.s32, 5, xer);
	// beq cr6,0x8228324c
	if (cr6.eq) goto loc_8228324C;
	// li r11,5
	r11.s64 = 5;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r11.u32);
	// bl 0x82280430
	ctx.lr = 0x8228324C;
	sub_82280430(ctx, base);
loc_8228324C:
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82283258;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x82283274;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82283294;
	sub_8226B2F0(ctx, base);
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,8920(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 8920);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82283648
	if (cr6.eq) goto loc_82283648;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x822832B4;
	sub_8226B2F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,8920(r23)
	PPC_STORE_U32(r23.u32 + 8920, r11.u32);
	// bne cr6,0x822832f0
	if (!cr6.eq) goto loc_822832F0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82280ad8
	ctx.lr = 0x822832D0;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822832f0
	if (cr6.eq) goto loc_822832F0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82280da8
	ctx.lr = 0x822832F0;
	sub_82280DA8(ctx, base);
loc_822832F0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227e750
	ctx.lr = 0x822832F8;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r26,r10,21846
	r26.u64 = ctx.r10.u64 | 21846;
	// beq cr6,0x822833a8
	if (cr6.eq) goto loc_822833A8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82283314;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822833a8
	if (cr6.eq) goto loc_822833A8;
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82283334
	if (cr6.eq) goto loc_82283334;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822833a8
	if (!cr6.eq) goto loc_822833A8;
loc_82283334:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x82283340;
	sub_82293F60(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82283350;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82283354;
	sub_82293F60(ctx, base);
	// fsubs f0,f31,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mulhw r11,r9,r26
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(r26.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf. r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x822833a8
	if (!cr0.eq) goto loc_822833A8;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x82283388;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822833a0
	if (!cr6.eq) goto loc_822833A0;
	// lwz r11,16(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822833a8
	if (!cr6.eq) goto loc_822833A8;
loc_822833A0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82282050
	ctx.lr = 0x822833A8;
	sub_82282050(ctx, base);
loc_822833A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822833B0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822833C0;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822833C8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283538
	if (cr6.eq) goto loc_82283538;
	// bl 0x82256058
	ctx.lr = 0x822833D4;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82283450
	if (cr6.eq) goto loc_82283450;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x822833EC;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82283450
	if (!cr6.eq) goto loc_82283450;
	// addic. r31,r30,8
	xer.ca = r30.u32 > 4294967287;
	r31.s64 = r30.s64 + 8;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82283538
	if (cr0.eq) goto loc_82283538;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82283408;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,3080(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 3080);
	// bne cr6,0x82283434
	if (!cr6.eq) goto loc_82283434;
	// bl 0x823eaef8
	ctx.lr = 0x8228341C;
	sub_823EAEF8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82263f60
	ctx.lr = 0x8228342C;
	sub_82263F60(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x8228350c
	goto loc_8228350C;
loc_82283434:
	// bl 0x823eaef8
	ctx.lr = 0x82283438;
	sub_823EAEF8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82263c28
	ctx.lr = 0x82283448;
	sub_82263C28(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x8228350c
	goto loc_8228350C;
loc_82283450:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228345C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// blt cr6,0x82283538
	if (cr6.lt) goto loc_82283538;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82283470;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,13
	cr6.compare<uint32_t>(ctx.r3.u32, 13, xer);
	// bgt cr6,0x82283538
	if (cr6.gt) goto loc_82283538;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// bl 0x82388580
	ctx.lr = 0x82283484;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82283494;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x822051a0
	ctx.lr = 0x8228349C;
	sub_822051A0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_822834A8:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283500
	if (cr6.eq) goto loc_82283500;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822834BC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283500
	if (cr6.eq) goto loc_82283500;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82283500
	if (!cr6.eq) goto loc_82283500;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x822834E0;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283500
	if (cr6.eq) goto loc_82283500;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x822834F4;
	sub_822051A0(ctx, base);
	// cmpw cr6,r27,r3
	cr6.compare<int32_t>(r27.s32, ctx.r3.s32, xer);
	// bge cr6,0x82283500
	if (!cr6.lt) goto loc_82283500;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_82283500:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822834a8
	if (!cr0.eq) goto loc_822834A8;
loc_8228350C:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82283538
	if (cr6.eq) goto loc_82283538;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228351C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228352C;
	sub_82270170(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82274128
	ctx.lr = 0x82283538;
	sub_82274128(ctx, base);
loc_82283538:
	// lwz r11,16(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822835cc
	if (!cr6.eq) goto loc_822835CC;
	// lwz r9,8920(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 8920);
	// mulhw r11,r9,r26
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(r26.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf. r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x822835cc
	if (!cr0.eq) goto loc_822835CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,32(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822835cc
	if (!cr6.gt) goto loc_822835CC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293e30
	ctx.lr = 0x82283580;
	sub_82293E30(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293eb0
	ctx.lr = 0x8228358C;
	sub_82293EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822835cc
	if (cr6.eq) goto loc_822835CC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82280ad8
	ctx.lr = 0x822835A0;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822835b8
	if (cr6.eq) goto loc_822835B8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82280e38
	ctx.lr = 0x822835B4;
	sub_82280E38(ctx, base);
	// b 0x822835c0
	goto loc_822835C0;
loc_822835B8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,14(r25)
	PPC_STORE_U8(r25.u32 + 14, r11.u8);
loc_822835C0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 32, temp.u32);
loc_822835CC:
	// lwz r11,-10240(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824fb3f8
	ctx.lr = 0x822835D8;
	sub_824FB3F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82283648
	if (!cr6.eq) goto loc_82283648;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822835EC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822835FC;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82283604;
	sub_82272A30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283648
	if (cr6.eq) goto loc_82283648;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82283614;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82283624;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228362C;
	sub_82272A30(ctx, base);
	// bl 0x824815a0
	ctx.lr = 0x82283630;
	sub_824815A0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283648
	if (cr6.eq) goto loc_82283648;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226c5b0
	ctx.lr = 0x82283648;
	sub_8226C5B0(ctx, base);
loc_82283648:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227df10
	ctx.lr = 0x82283650;
	sub_8227DF10(ctx, base);
loc_82283650:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8228365C"))) PPC_WEAK_FUNC(sub_8228365C);
PPC_FUNC_IMPL(__imp__sub_8228365C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82283660"))) PPC_WEAK_FUNC(sub_82283660);
PPC_FUNC_IMPL(__imp__sub_82283660) {
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
	ctx.lr = 0x82283668;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// ori r26,r10,64167
	r26.u64 = ctx.r10.u64 | 64167;
	// addi r29,r11,2176
	r29.s64 = r11.s64 + 2176;
loc_82283688:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r31,0
	r31.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822837ac
	if (!cr6.gt) goto loc_822837AC;
loc_822836A0:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8227e4b8
	ctx.lr = 0x822836B0;
	sub_8227E4B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822836c0
	if (cr6.eq) goto loc_822836C0;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_822836C0:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822836a0
	if (cr6.lt) goto loc_822836A0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822837ac
	if (cr6.eq) goto loc_822837AC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// twllei r31,0
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// mulld r11,r11,r26
	r11.s64 = r11.s64 * r26.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// divw r7,r8,r31
	ctx.r7.s32 = ctx.r8.s32 / r31.s32;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// mullw r5,r7,r31
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(r31.s32);
	// andc r4,r31,r6
	ctx.r4.u64 = r31.u64 & ~ctx.r6.u64;
	// subf r27,r5,r8
	r27.s64 = ctx.r8.s64 - ctx.r5.s64;
	// twlgei r4,-1
	// li r31,0
	r31.s64 = 0;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82283688
	if (!cr6.gt) goto loc_82283688;
loc_82283738:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8227e4b8
	ctx.lr = 0x82283748;
	sub_8227E4B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283760
	if (cr6.eq) goto loc_82283760;
	// cmplw cr6,r27,r31
	cr6.compare<uint32_t>(r27.u32, r31.u32, xer);
	// beq cr6,0x82283778
	if (cr6.eq) goto loc_82283778;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82283760:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82283738
	if (cr6.lt) goto loc_82283738;
	// b 0x82283688
	goto loc_82283688;
loc_82283778:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x821c9790
	ctx.lr = 0x82283790;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82282580
	ctx.lr = 0x822837A0;
	sub_82282580(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822837AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822837B8"))) PPC_WEAK_FUNC(sub_822837B8);
PPC_FUNC_IMPL(__imp__sub_822837B8) {
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
	ctx.lr = 0x822837C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823896c0
	ctx.lr = 0x822837E0;
	sub_823896C0(ctx, base);
	// bl 0x8238eb20
	ctx.lr = 0x822837E4;
	sub_8238EB20(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x8227e5a0
	ctx.lr = 0x822837F4;
	sub_8227E5A0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228380C;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e750
	ctx.lr = 0x82283818;
	sub_8227E750(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82283848;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82293eb0
	ctx.lr = 0x82283854;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82283898
	if (cr6.eq) goto loc_82283898;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82283a18
	if (!cr6.eq) goto loc_82283A18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293eb0
	ctx.lr = 0x8228388C;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
loc_82283898:
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x822838A0;
	sub_82502300(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823896c0
	ctx.lr = 0x822838B4;
	sub_823896C0(ctx, base);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82283978
	if (!cr6.eq) goto loc_82283978;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r27,-2
	ctx.r10.s64 = r27.s64 + -2;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r28,r8,3
	r28.s64 = ctx.r8.s64 + 196608;
	// addi r28,r28,-21024
	r28.s64 = r28.s64 + -21024;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823974a8
	ctx.lr = 0x822838EC;
	sub_823974A8(ctx, base);
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822838F8;
	sub_82295E90(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x8228390C;
	sub_82295BC8(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,-12672(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12672);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x82283968
	if (cr6.eq) goto loc_82283968;
	// li r11,-1
	r11.s64 = -1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82389668
	ctx.lr = 0x82283938;
	sub_82389668(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283968
	if (cr6.eq) goto loc_82283968;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbz r6,19(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 19);
	// extsb r28,r6
	r28.s64 = ctx.r6.s8;
loc_82283968:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295d70
	ctx.lr = 0x82283978;
	sub_82295D70(ctx, base);
loc_82283978:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x82283988;
	sub_82295F70(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x82283998;
	sub_82295F70(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822839A8;
	sub_82295F70(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x822839B8;
	sub_82295BC8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295828
	ctx.lr = 0x822839C4;
	sub_82295828(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822839D4;
	sub_82295F70(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x822839E4;
	sub_82295BC8(ctx, base);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82283a00
	if (cr6.eq) goto loc_82283A00;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x8227fbc0
	ctx.lr = 0x822839FC;
	sub_8227FBC0(ctx, base);
	// b 0x82283a04
	goto loc_82283A04;
loc_82283A00:
	// bl 0x82295828
	ctx.lr = 0x82283A04;
	sub_82295828(ctx, base);
loc_82283A04:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82282c38
	ctx.lr = 0x82283A18;
	sub_82282C38(ctx, base);
loc_82283A18:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82283A20"))) PPC_WEAK_FUNC(sub_82283A20);
PPC_FUNC_IMPL(__imp__sub_82283A20) {
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
	ctx.lr = 0x82283A28;
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// addi r31,r11,8924
	r31.s64 = r11.s64 + 8924;
	// stw r14,1364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1364, r14.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,8944(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8944);
	// li r26,0
	r26.s64 = 0;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82283a9c
	if (!cr6.eq) goto loc_82283A9C;
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
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// stw r11,8944(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8944, r11.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r10,-29216
	ctx.r3.s64 = ctx.r10.s64 + -29216;
	// bl 0x823d9a98
	ctx.lr = 0x82283A9C;
	sub_823D9A98(ctx, base);
loc_82283A9C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r24,r11,-2628
	r24.s64 = r11.s64 + -2628;
	// addi r22,r30,144
	r22.s64 = r30.s64 + 144;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82283ABC;
	sub_822701C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82295e90
	ctx.lr = 0x82283AC4;
	sub_82295E90(ctx, base);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
	// bl 0x8227e320
	ctx.lr = 0x82283AD4;
	sub_8227E320(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82283b94
	if (!cr6.gt) goto loc_82283B94;
	// addi r27,r30,12
	r27.s64 = r30.s64 + 12;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r23,-32121
	r23.s64 = -2105081856;
loc_82283AE8:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82283b7c
	if (cr6.eq) goto loc_82283B7C;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x82283B00;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82283b48
	if (!cr6.eq) goto loc_82283B48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 17268);
	// bl 0x822a3de0
	ctx.lr = 0x82283B14;
	sub_822A3DE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82283b7c
	if (cr6.eq) goto loc_82283B7C;
	// lwz r3,17892(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x82283B28;
	sub_822B62A0(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r20,r31,16
	r20.s64 = r31.s64 + 16;
	// bl 0x8227e320
	ctx.lr = 0x82283B38;
	sub_8227E320(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// extsb r5,r21
	ctx.r5.s64 = r21.s8;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// b 0x82283b70
	goto loc_82283B70;
loc_82283B48:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r21,r31,16
	r21.s64 = r31.s64 + 16;
	// bl 0x8227e320
	ctx.lr = 0x82283B54;
	sub_8227E320(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x82283B64;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
loc_82283B70:
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82481750
	ctx.lr = 0x82283B7C;
	sub_82481750(ctx, base);
loc_82283B7C:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bl 0x8227e320
	ctx.lr = 0x82283B8C;
	sub_8227E320(ctx, base);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// blt cr6,0x82283ae8
	if (cr6.lt) goto loc_82283AE8;
loc_82283B94:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82481590
	ctx.lr = 0x82283B9C;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283e78
	if (cr6.eq) goto loc_82283E78;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82283BB4;
	sub_8238EC00(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,-10240(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,564
	ctx.r8.s64 = ctx.r10.s64 + 564;
	// addi r7,r9,292
	ctx.r7.s64 = ctx.r9.s64 + 292;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r30,r1,108
	r30.s64 = ctx.r1.s64 + 108;
	// bl 0x822701c8
	ctx.lr = 0x82283BEC;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x82283BF4;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82389668
	ctx.lr = 0x82283C04;
	sub_82389668(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82283e78
	if (cr6.eq) goto loc_82283E78;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82283C18;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82283C28;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r31,208(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// bl 0x8227e320
	ctx.lr = 0x82283C3C;
	sub_8227E320(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82283e78
	if (!cr6.gt) goto loc_82283E78;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// lis r28,4096
	r28.s64 = 268435456;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r5,8192
	ctx.r5.s64 = 536870912;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r31,4096
	r31.s64 = 268435456;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// ori r23,r28,40
	r23.u64 = r28.u64 | 40;
	// ori r29,r5,44
	r29.u64 = ctx.r5.u64 | 44;
	// ori r30,r4,36
	r30.u64 = ctx.r4.u64 | 36;
	// ori r15,r3,43
	r15.u64 = ctx.r3.u64 | 43;
	// li r21,1
	r21.s64 = 1;
	// li r16,4
	r16.s64 = 4;
	// ori r22,r31,39
	r22.u64 = r31.u64 | 39;
	// li r17,6
	r17.s64 = 6;
	// li r18,15
	r18.s64 = 15;
	// addi r25,r7,820
	r25.s64 = ctx.r7.s64 + 820;
	// addi r28,r6,68
	r28.s64 = ctx.r6.s64 + 68;
	// addi r20,r8,784
	r20.s64 = ctx.r8.s64 + 784;
	// addi r19,r9,212
	r19.s64 = ctx.r9.s64 + 212;
	// addi r24,r10,484
	r24.s64 = ctx.r10.s64 + 484;
	// addi r27,r11,-28
	r27.s64 = r11.s64 + -28;
loc_82283CB4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283e50
	if (cr6.eq) goto loc_82283E50;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82283dd8
	if (cr6.lt) goto loc_82283DD8;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bgt cr6,0x82283dd8
	if (cr6.gt) goto loc_82283DD8;
	// lbz r7,648(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 648);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// stw r19,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r19.u32);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r20,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r20.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r29.u32);
	// ori r5,r7,128
	ctx.r5.u64 = ctx.r7.u64 | 128;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// ori r4,r9,42
	ctx.r4.u64 = ctx.r9.u64 | 42;
	// stw r15,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r15.u32);
	// ori r3,r8,41
	ctx.r3.u64 = ctx.r8.u64 | 41;
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// stb r5,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r5.u8);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stw r4,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r4.u32);
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// bgt cr6,0x82283d84
	if (cr6.gt) goto loc_82283D84;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,15676
	r12.s64 = r12.s64 + 15676;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82283D54;
	case 1:
		goto loc_82283D64;
	case 2:
		goto loc_82283D5C;
	case 3:
		goto loc_82283D74;
	case 4:
		goto loc_82283D6C;
	case 5:
		goto loc_82283D7C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,15700(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15700);
	// lwz r17,15716(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15716);
	// lwz r17,15708(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15708);
	// lwz r17,15732(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15732);
	// lwz r17,15724(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15724);
	// lwz r17,15740(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15740);
loc_82283D54:
	// li r11,7
	r11.s64 = 7;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D5C:
	// li r11,8
	r11.s64 = 8;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D64:
	// li r11,9
	r11.s64 = 9;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D6C:
	// li r11,10
	r11.s64 = 10;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D74:
	// li r11,11
	r11.s64 = 11;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D7C:
	// li r11,12
	r11.s64 = 12;
loc_82283D80:
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
loc_82283D84:
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// std r26,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r26.u64);
	// stw r21,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r21.u32);
	// li r10,31
	ctx.r10.s64 = 31;
	// stw r26,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r26.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// stw r11,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r26.u32);
	// addi r14,r1,128
	r14.s64 = ctx.r1.s64 + 128;
	// stw r26,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r26.u32);
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x822577d0
	ctx.lr = 0x82283DB8;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// bl 0x824816e8
	ctx.lr = 0x82283DCC;
	sub_824816E8(ctx, base);
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r27.u32);
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// b 0x82283e4c
	goto loc_82283E4C;
loc_82283DD8:
	// lbz r9,1176(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1176);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// std r26,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r26.u64);
	// li r4,14
	ctx.r4.s64 = 14;
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r24,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r24.u32);
	// stw r16,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, r16.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, r29.u32);
	// addi r14,r1,656
	r14.s64 = ctx.r1.s64 + 656;
	// stw r25,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r25.u32);
	// stw r30,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, r30.u32);
	// stb r8,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, ctx.r8.u8);
	// stw r22,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, r22.u32);
	// stw r23,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r23.u32);
	// stw r17,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r17.u32);
	// stw r10,1180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1180, ctx.r10.u32);
	// stw r26,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r26.u32);
	// stw r26,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, r26.u32);
	// stw r21,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, r21.u32);
	// std r18,668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 668, r18.u64);
	// bl 0x822577d0
	ctx.lr = 0x82283E30;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// bl 0x824816e8
	ctx.lr = 0x82283E44;
	sub_824816E8(ctx, base);
	// stw r27,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r27.u32);
	// stw r28,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r28.u32);
loc_82283E4C:
	// lwz r14,1364(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1364);
loc_82283E50:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8227e320
	ctx.lr = 0x82283E70;
	sub_8227E320(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x82283cb4
	if (cr6.lt) goto loc_82283CB4;
loc_82283E78:
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82283E80"))) PPC_WEAK_FUNC(sub_82283E80);
PPC_FUNC_IMPL(__imp__sub_82283E80) {
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
	ctx.lr = 0x82283E88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,9028
	ctx.r10.s64 = r11.s64 + 9028;
	// li r30,0
	r30.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r11,-1
	r11.s64 = -1;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// addi r9,r8,-11804
	ctx.r9.s64 = ctx.r8.s64 + -11804;
	// stb r7,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r7.u8);
	// stw r6,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r6.u32);
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// addi r28,r29,12
	r28.s64 = r29.s64 + 12;
	// stb r10,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r10.u8);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// bl 0x821b5a60
	ctx.lr = 0x82283F10;
	sub_821B5A60(ctx, base);
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x821b5a60
	ctx.lr = 0x82283F18;
	sub_821B5A60(ctx, base);
	// lis r8,-32216
	ctx.r8.s64 = -2111307776;
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-3936
	ctx.r7.s64 = ctx.r8.s64 + -3936;
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r7,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x82283F3C;
	sub_82130000(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r29,-9996(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9996);
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82207db8
	ctx.lr = 0x82283F54;
	sub_82207DB8(ctx, base);
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lwz r3,-27856(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82283F64;
	sub_8238EC00(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82283F70;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283f80
	if (cr6.eq) goto loc_82283F80;
	// bl 0x82289a58
	ctx.lr = 0x82283F7C;
	sub_82289A58(ctx, base);
	// b 0x82283f84
	goto loc_82283F84;
loc_82283F80:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82283F84:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r3,808
	ctx.r3.s64 = 808;
	// bl 0x82130528
	ctx.lr = 0x82283F90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283fb0
	if (cr6.eq) goto loc_82283FB0;
	// bl 0x8229bd90
	ctx.lr = 0x82283F9C;
	sub_8229BD90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82283FB0:
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82283FC0"))) PPC_WEAK_FUNC(sub_82283FC0);
PPC_FUNC_IMPL(__imp__sub_82283FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82283FD0"))) PPC_WEAK_FUNC(sub_82283FD0);
PPC_FUNC_IMPL(__imp__sub_82283FD0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,152(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 152);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82283FD8"))) PPC_WEAK_FUNC(sub_82283FD8);
PPC_FUNC_IMPL(__imp__sub_82283FD8) {
	PPC_FUNC_PROLOGUE();
	// stb r4,152(r3)
	PPC_STORE_U8(ctx.r3.u32 + 152, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82283FE0"))) PPC_WEAK_FUNC(sub_82283FE0);
PPC_FUNC_IMPL(__imp__sub_82283FE0) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// addi r8,r10,8844
	ctx.r8.s64 = ctx.r10.s64 + 8844;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r7,r9,3998
	ctx.r7.s64 = ctx.r9.s64 + 3998;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// bl 0x82637538
	ctx.lr = 0x82284044;
	sub_82637538(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// addi r3,r5,1292
	ctx.r3.s64 = ctx.r5.s64 + 1292;
	// addi r4,r6,1264
	ctx.r4.s64 = ctx.r6.s64 + 1264;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_8228407C"))) PPC_WEAK_FUNC(sub_8228407C);
PPC_FUNC_IMPL(__imp__sub_8228407C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284080"))) PPC_WEAK_FUNC(sub_82284080);
PPC_FUNC_IMPL(__imp__sub_82284080) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822840cc
	if (cr6.eq) goto loc_822840CC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822840B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822840cc
	if (cr6.eq) goto loc_822840CC;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
loc_822840CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82284100"))) PPC_WEAK_FUNC(sub_82284100);
PPC_FUNC_IMPL(__imp__sub_82284100) {
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
	ctx.lr = 0x82284108;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,116(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228412C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822841ac
	if (cr6.eq) goto loc_822841AC;
	// addi r31,r3,-48
	r31.s64 = ctx.r3.s64 + -48;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822841a0
	if (cr6.eq) goto loc_822841A0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82284178
	if (!cr6.eq) goto loc_82284178;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82284178:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82284080
	ctx.lr = 0x822841A0;
	sub_82284080(ctx, base);
loc_822841A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822841AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822841B8"))) PPC_WEAK_FUNC(sub_822841B8);
PPC_FUNC_IMPL(__imp__sub_822841B8) {
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
	ctx.lr = 0x822841C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,-44(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -44);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82284250
	if (cr6.lt) goto loc_82284250;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822841E8;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284250
	if (cr6.eq) goto loc_82284250;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82284200;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284238
	if (cr6.eq) goto loc_82284238;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228422c
	if (cr6.eq) goto loc_8228422C;
	// addi r3,r11,208
	ctx.r3.s64 = r11.s64 + 208;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8228422C:
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82284238:
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// lwz r4,-44(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -44);
	// bl 0x822a3998
	ctx.lr = 0x82284244;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82284248;
	sub_822A8108(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82284250:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8228425C"))) PPC_WEAK_FUNC(sub_8228425C);
PPC_FUNC_IMPL(__imp__sub_8228425C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284260"))) PPC_WEAK_FUNC(sub_82284260);
PPC_FUNC_IMPL(__imp__sub_82284260) {
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
	// lwz r4,-44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822842c4
	if (cr6.lt) goto loc_822842C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x8228428C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822842c4
	if (cr6.eq) goto loc_822842C4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822842AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822842C4:
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

__attribute__((alias("__imp__sub_822842DC"))) PPC_WEAK_FUNC(sub_822842DC);
PPC_FUNC_IMPL(__imp__sub_822842DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822842E0"))) PPC_WEAK_FUNC(sub_822842E0);
PPC_FUNC_IMPL(__imp__sub_822842E0) {
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
	// lwz r31,4(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// blt cr6,0x82284324
	if (cr6.lt) goto loc_82284324;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82284314;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82284328
	if (!cr6.eq) goto loc_82284328;
loc_82284324:
	// li r11,0
	r11.s64 = 0;
loc_82284328:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284348
	if (cr6.eq) goto loc_82284348;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82284340;
	sub_822A3998(ctx, base);
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x8228434c
	goto loc_8228434C;
loc_82284348:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8228434C:
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

__attribute__((alias("__imp__sub_82284364"))) PPC_WEAK_FUNC(sub_82284364);
PPC_FUNC_IMPL(__imp__sub_82284364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284368"))) PPC_WEAK_FUNC(sub_82284368);
PPC_FUNC_IMPL(__imp__sub_82284368) {
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
	// lwz r30,4(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822843b8
	if (cr6.lt) goto loc_822843B8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8228439C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822843b8
	if (cr6.eq) goto loc_822843B8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x822843B4;
	sub_822A3998(ctx, base);
	// b 0x822843bc
	goto loc_822843BC;
loc_822843B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822843BC:
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

__attribute__((alias("__imp__sub_822843D4"))) PPC_WEAK_FUNC(sub_822843D4);
PPC_FUNC_IMPL(__imp__sub_822843D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822843D8"))) PPC_WEAK_FUNC(sub_822843D8);
PPC_FUNC_IMPL(__imp__sub_822843D8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,-40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -40);
	// lwz r11,-8204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8204);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82284418
	if (!cr6.eq) goto loc_82284418;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82284474
	goto loc_82284474;
loc_82284418:
	// lwz r4,-44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -44);
	// addi r31,r30,-48
	r31.s64 = r30.s64 + -48;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82284444
	if (cr6.lt) goto loc_82284444;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82284434;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82284448
	if (!cr6.eq) goto loc_82284448;
loc_82284444:
	// li r11,0
	r11.s64 = 0;
loc_82284448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284474
	if (cr6.eq) goto loc_82284474;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228445C;
	sub_822842E0(ctx, base);
	// bl 0x82203310
	ctx.lr = 0x82284460;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284474
	if (cr6.eq) goto loc_82284474;
	// li r11,1
	r11.s64 = 1;
	// stb r11,52(r30)
	PPC_STORE_U8(r30.u32 + 52, r11.u8);
loc_82284474:
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

__attribute__((alias("__imp__sub_8228448C"))) PPC_WEAK_FUNC(sub_8228448C);
PPC_FUNC_IMPL(__imp__sub_8228448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284490"))) PPC_WEAK_FUNC(sub_82284490);
PPC_FUNC_IMPL(__imp__sub_82284490) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82284498;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,128(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 128);
	f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f13,128(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 128, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822844d4
	if (!cr6.gt) goto loc_822844D4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822844D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822844D4:
	// lwz r31,44(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lwz r30,116(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 116);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82284510
	if (cr6.eq) goto loc_82284510;
loc_822844E4:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82284510
	if (!cr6.gt) goto loc_82284510;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822844e4
	if (!cr6.eq) goto loc_822844E4;
loc_82284510:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826355a8
	ctx.lr = 0x8228451C;
	sub_826355A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82284528"))) PPC_WEAK_FUNC(sub_82284528);
PPC_FUNC_IMPL(__imp__sub_82284528) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,-3624(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lfs f0,9068(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 9068);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// stfs f0,9068(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 9068, temp.u32);
	// lfs f13,40(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822845a8
	if (!cr6.gt) goto loc_822845A8;
	// lwz r10,700(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822845a8
	if (!cr6.eq) goto loc_822845A8;
	// lbz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 132);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r5,184(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// stfs f0,9068(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 9068, temp.u32);
	// stb r6,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r6.u8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822845A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822845A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82284490
	ctx.lr = 0x822845B4;
	sub_82284490(ctx, base);
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

__attribute__((alias("__imp__sub_822845CC"))) PPC_WEAK_FUNC(sub_822845CC);
PPC_FUNC_IMPL(__imp__sub_822845CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822845D0"))) PPC_WEAK_FUNC(sub_822845D0);
PPC_FUNC_IMPL(__imp__sub_822845D0) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r4,116(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822845FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82284660
	if (cr6.eq) goto loc_82284660;
loc_82284608:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228461C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228463c
	if (cr6.eq) goto loc_8228463C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228463C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228463C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82284608
	if (!cr6.eq) goto loc_82284608;
loc_82284660:
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

__attribute__((alias("__imp__sub_8228467C"))) PPC_WEAK_FUNC(sub_8228467C);
PPC_FUNC_IMPL(__imp__sub_8228467C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284680"))) PPC_WEAK_FUNC(sub_82284680);
PPC_FUNC_IMPL(__imp__sub_82284680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82284694"))) PPC_WEAK_FUNC(sub_82284694);
PPC_FUNC_IMPL(__imp__sub_82284694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284698"))) PPC_WEAK_FUNC(sub_82284698);
PPC_FUNC_IMPL(__imp__sub_82284698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822846AC"))) PPC_WEAK_FUNC(sub_822846AC);
PPC_FUNC_IMPL(__imp__sub_822846AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822846B0"))) PPC_WEAK_FUNC(sub_822846B0);
PPC_FUNC_IMPL(__imp__sub_822846B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82635538
	sub_82635538(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822846B4"))) PPC_WEAK_FUNC(sub_822846B4);
PPC_FUNC_IMPL(__imp__sub_822846B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822846B8"))) PPC_WEAK_FUNC(sub_822846B8);
PPC_FUNC_IMPL(__imp__sub_822846B8) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r31,r11,80
	r31.s64 = r11.s64 + 80;
	// lwz r30,80(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// bl 0x822a5948
	ctx.lr = 0x822846E0;
	sub_822A5948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822846F4;
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

__attribute__((alias("__imp__sub_8228470C"))) PPC_WEAK_FUNC(sub_8228470C);
PPC_FUNC_IMPL(__imp__sub_8228470C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284710"))) PPC_WEAK_FUNC(sub_82284710);
PPC_FUNC_IMPL(__imp__sub_82284710) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-48
	ctx.r3.s64 = ctx.r3.s64 + -48;
	// b 0x82284718
	sub_82284718(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82284718"))) PPC_WEAK_FUNC(sub_82284718);
PPC_FUNC_IMPL(__imp__sub_82284718) {
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
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bne cr6,0x82284744
	if (!cr6.eq) goto loc_82284744;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82284744:
	// bl 0x826375a0
	ctx.lr = 0x82284748;
	sub_826375A0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,8844
	ctx.r9.s64 = r11.s64 + 8844;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8228476c
	if (cr6.eq) goto loc_8228476C;
	// bl 0x82130588
	ctx.lr = 0x82284768;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8228476C:
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

__attribute__((alias("__imp__sub_82284784"))) PPC_WEAK_FUNC(sub_82284784);
PPC_FUNC_IMPL(__imp__sub_82284784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284788"))) PPC_WEAK_FUNC(sub_82284788);
PPC_FUNC_IMPL(__imp__sub_82284788) {
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
	ctx.lr = 0x82284790;
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
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r30,116(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822847B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bge cr6,0x822848c8
	if (!cr6.lt) goto loc_822848C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822847D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822847ec
	if (cr6.eq) goto loc_822847EC;
	// addi r30,r3,-48
	r30.s64 = ctx.r3.s64 + -48;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82284840
	if (!cr6.eq) goto loc_82284840;
loc_822847EC:
	// lhz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 136);
	// addi r11,r31,132
	r11.s64 = r31.s64 + 132;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r7,136(r31)
	PPC_STORE_U16(r31.u32 + 136, ctx.r7.u16);
	// rlwinm r6,r7,2,14,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FFFC;
	// lwzx r30,r6,r9
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268d0d8
	ctx.lr = 0x8228481C;
	sub_8268D0D8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bne cr6,0x8228482c
	if (!cr6.eq) goto loc_8228482C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228482C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82284840:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r29,116(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82284870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// bge cr6,0x822848bc
	if (!cr6.lt) goto loc_822848BC;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r8,532(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 532);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822848AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82284080
	ctx.lr = 0x822848BC;
	sub_82284080(ctx, base);
loc_822848BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822848C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822848D4"))) PPC_WEAK_FUNC(sub_822848D4);
PPC_FUNC_IMPL(__imp__sub_822848D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822848D8"))) PPC_WEAK_FUNC(sub_822848D8);
PPC_FUNC_IMPL(__imp__sub_822848D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x822848E0;
	// stfd f30,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f30.u64);
	// stfd f31,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r21,-2
	ctx.r10.s64 = r21.s64 + -2;
	// addi r11,r11,3998
	r11.s64 = r11.s64 + 3998;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// clrlwi r20,r5,24
	r20.u64 = ctx.r5.u32 & 0xFF;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// mr r23,r11
	r23.u64 = r11.u64;
	// mr r19,r11
	r19.u64 = r11.u64;
	// rlwinm r26,r9,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// addi r28,r10,2168
	r28.s64 = ctx.r10.s64 + 2168;
	// beq cr6,0x82284930
	if (cr6.eq) goto loc_82284930;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82284930:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82284940;
	sub_82218310(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r11,-2628
	r30.s64 = r11.s64 + -2628;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228495C;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822952b0
	ctx.lr = 0x82284968;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228498c
	if (cr6.eq) goto loc_8228498C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295e90
	ctx.lr = 0x82284984;
	sub_82295E90(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x82284990
	goto loc_82284990;
loc_8228498C:
	// mr r25,r24
	r25.u64 = r24.u64;
loc_82284990:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x8228499C;
	sub_82270180(ctx, base);
	// addi r3,r3,144
	ctx.r3.s64 = ctx.r3.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x822849A4;
	sub_82481590(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bne cr6,0x822849c4
	if (!cr6.eq) goto loc_822849C4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822849BC;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_822849C4:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822849D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bge cr6,0x82284a54
	if (!cr6.lt) goto loc_82284A54;
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// beq cr6,0x82284a24
	if (cr6.eq) goto loc_82284A24;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284a10
	if (cr6.eq) goto loc_82284A10;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2140
	ctx.r4.s64 = r11.s64 + 2140;
	// bl 0x82218310
	ctx.lr = 0x82284A08;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A10:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2112
	ctx.r4.s64 = r11.s64 + 2112;
	// bl 0x82218310
	ctx.lr = 0x82284A1C;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A24:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284a40
	if (cr6.eq) goto loc_82284A40;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2088
	ctx.r4.s64 = r11.s64 + 2088;
	// bl 0x82218310
	ctx.lr = 0x82284A38;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A40:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2064
	ctx.r4.s64 = r11.s64 + 2064;
	// bl 0x82218310
	ctx.lr = 0x82284A4C;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A54:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x82284A64;
	sub_82293E30(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822952b0
	ctx.lr = 0x82284A70;
	sub_822952B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284a8c
	if (cr6.eq) goto loc_82284A8C;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295538
	ctx.lr = 0x82284A8C;
	sub_82295538(ctx, base);
loc_82284A8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r28,r11,15480
	r28.s64 = r11.s64 + 15480;
	// mr r11,r24
	r11.u64 = r24.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r10,-12672(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -12672);
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// bne cr6,0x82284af4
	if (!cr6.eq) goto loc_82284AF4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r4,-28256(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// bl 0x82218310
	ctx.lr = 0x82284AC0;
	sub_82218310(ctx, base);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lwz r11,-10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r9,r10,-27892
	ctx.r9.s64 = ctx.r10.s64 + -27892;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82218310
	ctx.lr = 0x82284ADC;
	sub_82218310(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r8,2052
	ctx.r4.s64 = ctx.r8.s64 + 2052;
	// bl 0x82218310
	ctx.lr = 0x82284AEC;
	sub_82218310(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// b 0x82284b88
	goto loc_82284B88;
loc_82284AF4:
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389668
	ctx.lr = 0x82284B10;
	sub_82389668(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284b88
	if (cr6.eq) goto loc_82284B88;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r9,r10,-27892
	ctx.r9.s64 = ctx.r10.s64 + -27892;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,44(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r9
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// bl 0x82218310
	ctx.lr = 0x82284B5C;
	sub_82218310(ctx, base);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// lwzx r4,r6,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x82218310
	ctx.lr = 0x82284B84;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
loc_82284B88:
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822952b0
	ctx.lr = 0x82284B94;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284cec
	if (cr6.eq) goto loc_82284CEC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295e90
	ctx.lr = 0x82284BAC;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x82284cec
	if (!cr6.eq) goto loc_82284CEC;
	// lbz r8,118(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 118);
	// li r10,255
	ctx.r10.s64 = 255;
	// lbz r6,113(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// ori r4,r8,128
	ctx.r4.u64 = ctx.r8.u64 | 128;
	// lbz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 116);
	// stb r10,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r10.u8);
	// ori r10,r6,224
	ctx.r10.u64 = ctx.r6.u64 | 224;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// stb r24,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r24.u8);
	// clrlwi r3,r7,25
	ctx.r3.u64 = ctx.r7.u32 & 0x7F;
	// stw r24,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r24.u32);
	// ori r9,r11,64
	ctx.r9.u64 = r11.u64 | 64;
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r24.u32);
	// stb r3,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r3.u8);
	// li r4,18
	ctx.r4.s64 = 18;
	// stw r24,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r10,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, ctx.r10.u8);
	// stb r24,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r24.u8);
	// stb r24,133(r1)
	PPC_STORE_U8(ctx.r1.u32 + 133, r24.u8);
	// stw r24,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r24.u32);
	// stb r9,118(r1)
	PPC_STORE_U8(ctx.r1.u32 + 118, ctx.r9.u8);
	// bl 0x82295538
	ctx.lr = 0x82284C14;
	sub_82295538(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82397458
	ctx.lr = 0x82284C1C;
	sub_82397458(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82284c58
	if (cr6.eq) goto loc_82284C58;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,2036
	ctx.r4.s64 = r11.s64 + 2036;
	// bl 0x82218310
	ctx.lr = 0x82284C38;
	sub_82218310(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,-5820
	ctx.r5.s64 = ctx.r10.s64 + -5820;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r7,r19
	ctx.r7.u64 = r19.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284C54;
	sub_82137A08(ctx, base);
	// b 0x82284ce8
	goto loc_82284CE8;
loc_82284C58:
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295c90
	ctx.lr = 0x82284C64;
	sub_82295C90(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bge cr6,0x82284ca8
	if (!cr6.lt) goto loc_82284CA8;
	// lwz r11,-12672(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12672);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bne cr6,0x82284ca8
	if (!cr6.eq) goto loc_82284CA8;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r9,127
	ctx.r9.s64 = 127;
	// subf r8,r28,r19
	ctx.r8.s64 = r19.s64 - r28.s64;
loc_82284C84:
	// lbzx r10,r11,r8
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284ca0
	if (cr6.eq) goto loc_82284CA0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82284c84
	if (cr0.gt) goto loc_82284C84;
loc_82284CA0:
	// stb r24,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r24.u8);
	// b 0x82284ce8
	goto loc_82284CE8;
loc_82284CA8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bne cr6,0x82284cb8
	if (!cr6.eq) goto loc_82284CB8;
	// li r30,2
	r30.s64 = 2;
loc_82284CB8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,2020
	ctx.r4.s64 = r11.s64 + 2020;
	// bl 0x82218310
	ctx.lr = 0x82284CC8;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r10,2008
	ctx.r5.s64 = ctx.r10.s64 + 2008;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284CE8;
	sub_82137A08(ctx, base);
loc_82284CE8:
	// mr r19,r28
	r19.u64 = r28.u64;
loc_82284CEC:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284D00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82284ee4
	if (cr6.eq) goto loc_82284EE4;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82284ee4
	if (!cr6.eq) goto loc_82284EE4;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e1b0
	ctx.lr = 0x82284D20;
	sub_8227E1B0(ctx, base);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r4,-3624(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82284D30;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82284D34;
	sub_82293F60(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-3624(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82284D44;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293eb0
	ctx.lr = 0x82284D50;
	sub_82293EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284e18
	if (cr6.eq) goto loc_82284E18;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r4,-3624(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82284D68;
	sub_8226B2F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82294028
	ctx.lr = 0x82284D78;
	sub_82294028(ctx, base);
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 120);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x82284d98
	if (cr6.eq) goto loc_82284D98;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,1976
	ctx.r3.s64 = r11.s64 + 1976;
	// bl 0x821e6800
	ctx.lr = 0x82284D94;
	sub_821E6800(ctx, base);
	// stw r30,120(r17)
	PPC_STORE_U32(r17.u32 + 120, r30.u32);
loc_82284D98:
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82284ddc
	if (cr6.eq) goto loc_82284DDC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-27008
	ctx.r4.s64 = r11.s64 + -27008;
	// bl 0x82218310
	ctx.lr = 0x82284DB0;
	sub_82218310(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,15608
	r31.s64 = r11.s64 + 15608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,1964
	ctx.r5.s64 = ctx.r10.s64 + 1964;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284DD8;
	sub_82137A08(ctx, base);
	// b 0x82284ee0
	goto loc_82284EE0;
loc_82284DDC:
	// cmpwi cr6,r21,2
	cr6.compare<int32_t>(r21.s32, 2, xer);
	// bne cr6,0x82284df0
	if (!cr6.eq) goto loc_82284DF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,1944
	ctx.r4.s64 = r11.s64 + 1944;
	// b 0x82284df8
	goto loc_82284DF8;
loc_82284DF0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,1924
	ctx.r4.s64 = r11.s64 + 1924;
loc_82284DF8:
	// bl 0x82218310
	ctx.lr = 0x82284DFC;
	sub_82218310(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r31,r11,15608
	r31.s64 = r11.s64 + 15608;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284E14;
	sub_82137A08(ctx, base);
	// b 0x82284ee0
	goto loc_82284EE0;
loc_82284E18:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82284eac
	if (!cr6.eq) goto loc_82284EAC;
	// clrlwi r10,r18,24
	ctx.r10.u64 = r18.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284ea4
	if (cr6.eq) goto loc_82284EA4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82284ea4
	if (!cr6.gt) goto loc_82284EA4;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82284ea4
	if (!cr6.gt) goto loc_82284EA4;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// fsubs f0,f30,f31
	f0.f64 = double(float(f30.f64 - f31.f64));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r10,1904
	ctx.r4.s64 = ctx.r10.s64 + 1904;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f13,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// bl 0x82218310
	ctx.lr = 0x82284E7C;
	sub_82218310(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r23,r8,15608
	r23.s64 = ctx.r8.s64 + 15608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r7,1896
	ctx.r5.s64 = ctx.r7.s64 + 1896;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284EA0;
	sub_82137A08(ctx, base);
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284EA4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284ee4
	if (cr6.eq) goto loc_82284EE4;
loc_82284EAC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,1880
	ctx.r4.s64 = r11.s64 + 1880;
	// bl 0x82218310
	ctx.lr = 0x82284EBC;
	sub_82218310(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r31,r10,15608
	r31.s64 = ctx.r10.s64 + 15608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,1872
	ctx.r5.s64 = ctx.r9.s64 + 1872;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x82284EE0;
	sub_82137A08(ctx, base);
loc_82284EE0:
	// mr r23,r31
	r23.u64 = r31.u64;
loc_82284EE4:
	// cmpwi cr6,r15,1
	cr6.compare<int32_t>(r15.s32, 1, xer);
	// mr r31,r23
	r31.u64 = r23.u64;
	// beq cr6,0x82284ef4
	if (cr6.eq) goto loc_82284EF4;
	// mr r31,r16
	r31.u64 = r16.u64;
loc_82284EF4:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-13276
	ctx.r4.s64 = ctx.r9.s64 + -13276;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82284F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r15,1
	cr6.compare<int32_t>(r15.s32, 1, xer);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// beq cr6,0x82284f34
	if (cr6.eq) goto loc_82284F34;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
loc_82284F34:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r15,2
	cr6.compare<int32_t>(r15.s32, 2, xer);
	// mr r31,r23
	r31.u64 = r23.u64;
	// beq cr6,0x82284f58
	if (cr6.eq) goto loc_82284F58;
	// mr r31,r16
	r31.u64 = r16.u64;
loc_82284F58:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,1864
	ctx.r4.s64 = ctx.r9.s64 + 1864;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82284F88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r17)
	ctx.r6.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r5,496(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 496);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82284F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r4,1856
	ctx.r4.s64 = ctx.r4.s64 + 1856;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,0(r19)
	ctx.r9.u64 = PPC_LOAD_U8(r19.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82284fe8
	if (cr6.eq) goto loc_82284FE8;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82284fe8
	if (cr6.eq) goto loc_82284FE8;
	// stw r15,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r15.u32);
	// b 0x82284ff0
	goto loc_82284FF0;
loc_82284FE8:
	// li r11,3
	r11.s64 = 3;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82284FF0:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,1840
	ctx.r4.s64 = ctx.r9.s64 + 1840;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82285020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-160(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f31,-152(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_82285030"))) PPC_WEAK_FUNC(sub_82285030);
PPC_FUNC_IMPL(__imp__sub_82285030) {
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
	ctx.lr = 0x82285038;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635538
	ctx.lr = 0x82285044;
	sub_82635538(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-18484
	ctx.r6.s64 = r11.s64 + -18484;
	// addi r5,r10,-18604
	ctx.r5.s64 = ctx.r10.s64 + -18604;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r3,588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 588);
	// bl 0x823dedd8
	ctx.lr = 0x8228506C;
	sub_823DEDD8(ctx, base);
	// lwz r4,-44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82285128
	if (cr6.lt) goto loc_82285128;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285128
	if (cr6.eq) goto loc_82285128;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285128
	if (cr6.eq) goto loc_82285128;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r10,r10,2192
	ctx.r10.s64 = ctx.r10.s64 + 2192;
loc_8228509C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822850c0
	if (cr6.eq) goto loc_822850C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228509c
	if (cr6.eq) goto loc_8228509C;
loc_822850C0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82285128
	if (!cr6.eq) goto loc_82285128;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822850fc
	if (cr6.eq) goto loc_822850FC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822850E0;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822850F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822850FC:
	// addic. r11,r31,-48
	xer.ca = r31.u32 > 47;
	r11.s64 = r31.s64 + -48;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bne 0x8228510c
	if (!cr0.eq) goto loc_8228510C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228510C:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x826290c0
	ctx.lr = 0x82285128;
	sub_826290C0(ctx, base);
loc_82285128:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82285130"))) PPC_WEAK_FUNC(sub_82285130);
PPC_FUNC_IMPL(__imp__sub_82285130) {
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
	ctx.lr = 0x82285138;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285184
	if (cr6.lt) goto loc_82285184;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82285164;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285184
	if (cr6.eq) goto loc_82285184;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8228517C;
	sub_822A3998(ctx, base);
	// lwz r27,1220(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x82285188
	goto loc_82285188;
loc_82285184:
	// mr r27,r25
	r27.u64 = r25.u64;
loc_82285188:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r26,700(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822701c8
	ctx.lr = 0x822851A8;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822851e0
	if (cr6.eq) goto loc_822851E0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822952b0
	ctx.lr = 0x822851BC;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822851e0
	if (cr6.eq) goto loc_822851E0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822851D4;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822851e4
	if (!cr6.eq) goto loc_822851E4;
loc_822851E0:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_822851E4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// bl 0x822952b0
	ctx.lr = 0x822851F4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285214
	if (cr6.eq) goto loc_82285214;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228520C;
	sub_82295E90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82285218
	goto loc_82285218;
loc_82285214:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_82285218:
	// stw r25,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r25.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822577d0
	ctx.lr = 0x82285228;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82285270
	if (cr6.eq) goto loc_82285270;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bne cr6,0x82285258
	if (!cr6.eq) goto loc_82285258;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2088
	ctx.r4.s64 = ctx.r10.s64 + 2088;
	// bl 0x82218310
	ctx.lr = 0x8228524C;
	sub_82218310(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285258:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2064
	ctx.r4.s64 = ctx.r10.s64 + 2064;
	// bl 0x82218310
	ctx.lr = 0x82285264;
	sub_82218310(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285270:
	// lwz r11,16(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82285290
	if (!cr6.eq) goto loc_82285290;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285290:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822852c0
	if (cr6.eq) goto loc_822852C0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2304
	ctx.r4.s64 = ctx.r10.s64 + 2304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822852B0;
	sub_82218310(ctx, base);
	// stw r25,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r25.u32);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_822852C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822852C8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822852D8;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,11780(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11780);
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// bne cr6,0x82285344
	if (!cr6.eq) goto loc_82285344;
	// bl 0x822577d0
	ctx.lr = 0x822852F4;
	sub_822577D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// beq cr6,0x82285324
	if (cr6.eq) goto loc_82285324;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2280
	ctx.r4.s64 = ctx.r10.s64 + 2280;
	// bl 0x82218310
	ctx.lr = 0x82285310;
	sub_82218310(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r11,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285324:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2256
	ctx.r4.s64 = ctx.r10.s64 + 2256;
	// bl 0x82218310
	ctx.lr = 0x82285330;
	sub_82218310(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r11,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285344:
	// bl 0x822577d0
	ctx.lr = 0x82285348;
	sub_822577D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// beq cr6,0x82285378
	if (cr6.eq) goto loc_82285378;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2232
	ctx.r4.s64 = ctx.r10.s64 + 2232;
	// bl 0x82218310
	ctx.lr = 0x82285364;
	sub_82218310(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r9,28(r28)
	PPC_STORE_U32(r28.u32 + 28, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285378:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2208
	ctx.r4.s64 = ctx.r10.s64 + 2208;
	// bl 0x82218310
	ctx.lr = 0x82285384;
	sub_82218310(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r9,28(r28)
	PPC_STORE_U32(r28.u32 + 28, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82285398"))) PPC_WEAK_FUNC(sub_82285398);
PPC_FUNC_IMPL(__imp__sub_82285398) {
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
	ctx.lr = 0x822853A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822853f4
	if (cr6.lt) goto loc_822853F4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822853CC;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822853f4
	if (cr6.eq) goto loc_822853F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822853E4;
	sub_822A3998(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822853f4
	if (cr6.eq) goto loc_822853F4;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x822853f8
	goto loc_822853F8;
loc_822853F4:
	// li r31,0
	r31.s64 = 0;
loc_822853F8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// beq cr6,0x822854dc
	if (cr6.eq) goto loc_822854DC;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82285428
	if (cr6.eq) goto loc_82285428;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8238f6b0
	ctx.lr = 0x8228541C;
	sub_8238F6B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r7,r27,8141
	ctx.r7.s64 = r27.s64 + 8141;
	// b 0x8228549c
	goto loc_8228549C;
loc_82285428:
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82285434;
	sub_822577D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82285444;
	sub_822051A0(ctx, base);
	// bl 0x82396f58
	ctx.lr = 0x82285448;
	sub_82396F58(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r30,r11,-12120
	r30.s64 = r11.s64 + -12120;
	// bge cr6,0x8228546c
	if (!cr6.lt) goto loc_8228546C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82285464;
	sub_822051A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82285478
	if (cr6.lt) goto loc_82285478;
loc_8228546C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x8228547c
	if (cr6.lt) goto loc_8228547C;
loc_82285478:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8228547C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// lwz r4,8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x822183a8
	ctx.lr = 0x82285498;
	sub_822183A8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_8228549C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r31,r11,9072
	r31.s64 = r11.s64 + 9072;
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r31,2048
	r11.s64 = r31.s64 + 2048;
	// addi r5,r9,2332
	ctx.r5.s64 = ctx.r9.s64 + 2332;
	// addi r6,r29,65
	ctx.r6.s64 = r29.s64 + 65;
	// li r4,64
	ctx.r4.s64 = 64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82137a08
	ctx.lr = 0x822854C8;
	sub_82137A08(ctx, base);
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r11,r31,2048
	r11.s64 = r31.s64 + 2048;
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r7.u32);
loc_822854DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822854E4"))) PPC_WEAK_FUNC(sub_822854E4);
PPC_FUNC_IMPL(__imp__sub_822854E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822854E8"))) PPC_WEAK_FUNC(sub_822854E8);
PPC_FUNC_IMPL(__imp__sub_822854E8) {
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
	ctx.lr = 0x822854F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,4(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285540
	if (cr6.lt) goto loc_82285540;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82285518;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285540
	if (cr6.eq) goto loc_82285540;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82285530;
	sub_822A3998(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82285540
	if (cr6.eq) goto loc_82285540;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x82285544
	goto loc_82285544;
loc_82285540:
	// li r31,0
	r31.s64 = 0;
loc_82285544:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228554C;
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
	ctx.lr = 0x82285560;
	sub_82270170(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x822855c0
	if (!cr6.eq) goto loc_822855C0;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822855c0
	if (cr6.eq) goto loc_822855C0;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-17564
	ctx.r6.s64 = ctx.r10.s64 + -17564;
	// addi r5,r9,-22108
	ctx.r5.s64 = ctx.r9.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82285594;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822855c0
	if (cr6.eq) goto loc_822855C0;
	// lwz r31,76(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// bl 0x82387b90
	ctx.lr = 0x822855A4;
	sub_82387B90(ctx, base);
	// mulli r11,r31,8176
	r11.s64 = r31.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,1360
	ctx.r4.s64 = r11.s64 + 1360;
	// bl 0x82285398
	ctx.lr = 0x822855B8;
	sub_82285398(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822855C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82285398
	ctx.lr = 0x822855CC;
	sub_82285398(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822855D4"))) PPC_WEAK_FUNC(sub_822855D4);
PPC_FUNC_IMPL(__imp__sub_822855D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822855D8"))) PPC_WEAK_FUNC(sub_822855D8);
PPC_FUNC_IMPL(__imp__sub_822855D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822855E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r11,r7,9072
	r11.s64 = ctx.r7.s64 + 9072;
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r4,r6,-2628
	ctx.r4.s64 = ctx.r6.s64 + -2628;
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r28,r10,r11
	r28.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x822701c8
	ctx.lr = 0x82285610;
	sub_822701C8(ctx, base);
	// lwz r31,4(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285664
	if (cr6.lt) goto loc_82285664;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82285638;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285664
	if (cr6.eq) goto loc_82285664;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82285650;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82285668
	if (cr6.eq) goto loc_82285668;
	// lwz r30,1220(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// b 0x8228566c
	goto loc_8228566C;
loc_82285664:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82285668:
	// mr r30,r26
	r30.u64 = r26.u64;
loc_8228566C:
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285688
	if (cr6.eq) goto loc_82285688;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8228568c
	if (!cr6.eq) goto loc_8228568C;
loc_82285688:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8228568C:
	// stb r26,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r26.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r25,r11,24
	r25.u64 = r11.u32 & 0xFF;
	// bl 0x822a5ab8
	ctx.lr = 0x8228569C;
	sub_822A5AB8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x822856B8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x822856D0;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x82285b24
	if (!cr6.eq) goto loc_82285B24;
	// bl 0x82292040
	ctx.lr = 0x822856DC;
	sub_82292040(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82285b24
	if (!cr6.gt) goto loc_82285B24;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x822856F0;
	sub_822577D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// beq cr6,0x82285aac
	if (cr6.eq) goto loc_82285AAC;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// beq cr6,0x82285aac
	if (cr6.eq) goto loc_82285AAC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82285aac
	if (cr6.eq) goto loc_82285AAC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82285718;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82285a58
	if (!cr6.eq) goto loc_82285A58;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228584c
	if (cr6.eq) goto loc_8228584C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8228584c
	if (!cr6.gt) goto loc_8228584C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x82285784;
	sub_82293E30(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x82285790;
	sub_822952B0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822857ac
	if (cr6.eq) goto loc_822857AC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295538
	ctx.lr = 0x822857AC;
	sub_82295538(ctx, base);
loc_822857AC:
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bne cr6,0x8228582c
	if (!cr6.eq) goto loc_8228582C;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x8228583c
	if (!cr6.eq) goto loc_8228583C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2384
	ctx.r4.s64 = ctx.r10.s64 + 2384;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822857D8;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_822857E0:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x822857e0
	if (cr0.gt) goto loc_822857E0;
	// b 0x82285b20
	goto loc_82285B20;
loc_8228582C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x8228583c
	if (cr6.gt) goto loc_8228583C;
	// bl 0x82292040
	ctx.lr = 0x82285838;
	sub_82292040(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8228583C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8223de50
	ctx.lr = 0x82285848;
	sub_8223DE50(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_8228584C:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// ble cr6,0x82285868
	if (!cr6.gt) goto loc_82285868;
	// li r11,32
	r11.s64 = 32;
	// stw r11,44(r27)
	PPC_STORE_U32(r27.u32 + 44, r11.u32);
loc_82285868:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822858dc
	if (!cr6.eq) goto loc_822858DC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2384
	ctx.r4.s64 = ctx.r10.s64 + 2384;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285888;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285890:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285890
	if (cr0.gt) goto loc_82285890;
	// b 0x82285b20
	goto loc_82285B20;
loc_822858DC:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8228594c
	if (!cr6.eq) goto loc_8228594C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2376
	ctx.r4.s64 = ctx.r10.s64 + 2376;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822858F8;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285900:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285900
	if (cr0.gt) goto loc_82285900;
	// b 0x82285b20
	goto loc_82285B20;
loc_8228594C:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822859bc
	if (!cr6.eq) goto loc_822859BC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2368
	ctx.r4.s64 = ctx.r10.s64 + 2368;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285968;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285970:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285970
	if (cr0.gt) goto loc_82285970;
	// b 0x82285b20
	goto loc_82285B20;
loc_822859BC:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// ble cr6,0x82285a2c
	if (!cr6.gt) goto loc_82285A2C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
	// bl 0x82218310
	ctx.lr = 0x822859D8;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_822859E0:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x822859e0
	if (cr0.gt) goto loc_822859E0;
	// b 0x82285b20
	goto loc_82285B20;
loc_82285A2C:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2348
	ctx.r4.s64 = ctx.r10.s64 + 2348;
	// bl 0x82218310
	ctx.lr = 0x82285A38;
	sub_82218310(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r6,44(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// addi r5,r9,2340
	ctx.r5.s64 = ctx.r9.s64 + 2340;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x82285A54;
	sub_82137A08(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_82285A58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5df8
	ctx.lr = 0x82285A60;
	sub_822A5DF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82285A70;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,13
	cr6.compare<uint32_t>(ctx.r3.u32, 13, xer);
	// bne cr6,0x82285a88
	if (!cr6.eq) goto loc_82285A88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8223de50
	ctx.lr = 0x82285A84;
	sub_8223DE50(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_82285A88:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285b24
	if (cr6.lt) goto loc_82285B24;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x82285AA8;
	sub_82137A08(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_82285AAC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285AC0;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285AC8:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285ac8
	if (cr0.gt) goto loc_82285AC8;
	// b 0x82285b20
	goto loc_82285B20;
loc_82285B14:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x82285b20
	goto loc_82285B20;
loc_82285B1C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_82285B20:
	// stb r26,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r26.u8);
loc_82285B24:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// stw r28,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82285b50
	if (!cr6.eq) goto loc_82285B50;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285b50
	if (cr6.eq) goto loc_82285B50;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82285B50:
	// clrlwi r3,r26,24
	ctx.r3.u64 = r26.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82285B5C"))) PPC_WEAK_FUNC(sub_82285B5C);
PPC_FUNC_IMPL(__imp__sub_82285B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82285B60"))) PPC_WEAK_FUNC(sub_82285B60);
PPC_FUNC_IMPL(__imp__sub_82285B60) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82285b8c
	if (!cr6.eq) goto loc_82285B8C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2412
	ctx.r4.s64 = r11.s64 + 2412;
	// b 0x82285b94
	goto loc_82285B94;
loc_82285B8C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2392
	ctx.r4.s64 = r11.s64 + 2392;
loc_82285B94:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285BA4;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285BB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,3998
	ctx.r7.s64 = ctx.r8.s64 + 3998;
	// lwz r10,-8204(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8204);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lwz r10,-8204(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8204);
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
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

__attribute__((alias("__imp__sub_82285C08"))) PPC_WEAK_FUNC(sub_82285C08);
PPC_FUNC_IMPL(__imp__sub_82285C08) {
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
	ctx.lr = 0x82285C10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82285C20;
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
	ctx.lr = 0x82285C34;
	sub_82270170(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,208(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// bl 0x82635f20
	ctx.lr = 0x82285C44;
	sub_82635F20(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r8,148(r30)
	PPC_STORE_U32(r30.u32 + 148, ctx.r8.u32);
	// beq cr6,0x82285cc4
	if (cr6.eq) goto loc_82285CC4;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x824817c0
	ctx.lr = 0x82285C5C;
	sub_824817C0(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r28,148(r30)
	PPC_STORE_U32(r30.u32 + 148, r28.u32);
	// bl 0x82387b90
	ctx.lr = 0x82285C6C;
	sub_82387B90(ctx, base);
	// lwz r11,1340(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285cc4
	if (cr6.eq) goto loc_82285CC4;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82285C80:
	// bl 0x82387b90
	ctx.lr = 0x82285C84;
	sub_82387B90(ctx, base);
	// add r11,r31,r3
	r11.u64 = r31.u64 + ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x823906d8
	ctx.lr = 0x82285C94;
	sub_823906D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285cac
	if (cr6.eq) goto loc_82285CAC;
	// lwz r11,148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,148(r30)
	PPC_STORE_U32(r30.u32 + 148, r11.u32);
loc_82285CAC:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,8176
	r31.s64 = r31.s64 + 8176;
	// bl 0x82387b90
	ctx.lr = 0x82285CB8;
	sub_82387B90(ctx, base);
	// lwz r11,1340(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x82285c80
	if (!cr6.eq) goto loc_82285C80;
loc_82285CC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82285CCC"))) PPC_WEAK_FUNC(sub_82285CCC);
PPC_FUNC_IMPL(__imp__sub_82285CCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82285CD0"))) PPC_WEAK_FUNC(sub_82285CD0);
PPC_FUNC_IMPL(__imp__sub_82285CD0) {
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
	ctx.lr = 0x82285CD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r29,80
	r30.s64 = r29.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82285d48
	if (cr6.eq) goto loc_82285D48;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285d48
	if (cr6.eq) goto loc_82285D48;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82285d48
	if (!cr6.eq) goto loc_82285D48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7cc8
	ctx.lr = 0x82285D24;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285d48
	if (cr6.eq) goto loc_82285D48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x82285D38;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82285d4c
	if (!cr6.eq) goto loc_82285D4C;
loc_82285D48:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82285D4C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r4,r29,128
	ctx.r4.s64 = r29.s64 + 128;
	// bne cr6,0x82285d5c
	if (!cr6.eq) goto loc_82285D5C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82285D5C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x826290c0
	ctx.lr = 0x82285D78;
	sub_826290C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82285D80"))) PPC_WEAK_FUNC(sub_82285D80);
PPC_FUNC_IMPL(__imp__sub_82285D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x826355a8
	ctx.lr = 0x82285D9C;
	sub_826355A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82285DA4;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f12,-28876(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28876);
	ctx.f12.f64 = double(temp.f32);
	// lbz r4,18(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// lfs f11,1068(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 1068);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fmuls f0,f7,f11
	f0.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82285e00
	if (!cr6.lt) goto loc_82285E00;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x82285e0c
	goto loc_82285E0C;
loc_82285E00:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x82285e0c
	if (!cr6.gt) goto loc_82285E0C;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_82285E0C:
	// lbz r10,19(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 19);
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fmuls f0,f7,f11
	f0.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82285e3c
	if (!cr6.lt) goto loc_82285E3C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x82285e48
	goto loc_82285E48;
loc_82285E3C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x82285e48
	if (!cr6.gt) goto loc_82285E48;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_82285E48:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lbz r11,629(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285f2c
	if (cr6.eq) goto loc_82285F2C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8260c6d8
	ctx.lr = 0x82285E78;
	sub_8260C6D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82285f2c
	if (cr6.gt) goto loc_82285F2C;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285E9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r9,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,548(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 548);
	// lvx128 v61,r9,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82285EF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x82285F0C;
	sub_826208D0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82625f50
	ctx.lr = 0x82285F2C;
	sub_82625F50(ctx, base);
loc_82285F2C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_82285F44"))) PPC_WEAK_FUNC(sub_82285F44);
PPC_FUNC_IMPL(__imp__sub_82285F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82285F48"))) PPC_WEAK_FUNC(sub_82285F48);
PPC_FUNC_IMPL(__imp__sub_82285F48) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82285F50;
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f29.u64);
	// stfd f30,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r26,0
	r26.s64 = 0;
	// lfs f29,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// bl 0x82388580
	ctx.lr = 0x82285F80;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82285F94;
	sub_82270170(ctx, base);
	// lwz r8,128(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r3,r28,128
	ctx.r3.s64 = r28.s64 + 128;
	// lwz r6,548(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 548);
	// lwz r31,208(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82285FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// addi r27,r31,12
	r27.s64 = r31.s64 + 12;
	// li r25,31
	r25.s64 = 31;
	// lfd f30,2432(r11)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(r11.u32 + 2432);
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_82285FCC:
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822860e8
	if (cr6.eq) goto loc_822860E8;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228600c
	if (cr6.eq) goto loc_8228600C;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82286004
	if (!cr6.eq) goto loc_82286004;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82285FF8;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228600c
	if (cr6.eq) goto loc_8228600C;
loc_82286004:
	// li r11,1
	r11.s64 = 1;
	// b 0x82286010
	goto loc_82286010;
loc_8228600C:
	// li r11,0
	r11.s64 = 0;
loc_82286010:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822860e8
	if (cr6.eq) goto loc_822860E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,17268(r22)
	r30.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8228602C;
	sub_822051A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82286038;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822860e8
	if (cr6.eq) goto loc_822860E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82286050;
	sub_822051A0(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x82286054;
	sub_822A5948(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a8108
	ctx.lr = 0x8228605C;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f13,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f8,f11,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f7,f10,f10
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f6,f9,f9,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fsqrts f11,f5
	ctx.f11.f64 = double(float(sqrt(ctx.f5.f64)));
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// bge cr6,0x822860d4
	if (!cr6.lt) goto loc_822860D4;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x822860dc
	if (cr6.eq) goto loc_822860DC;
	// lfs f10,4(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f8,8(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// lfs f6,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f12.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// bgt cr6,0x822860dc
	if (cr6.gt) goto loc_822860DC;
loc_822860D4:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bne cr6,0x822860e8
	if (!cr6.eq) goto loc_822860E8;
loc_822860DC:
	// fmr f31,f11
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f11.f64;
	// mr r26,r31
	r26.u64 = r31.u64;
	// mr r23,r30
	r23.u64 = r30.u64;
loc_822860E8:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x82285fcc
	if (!cr0.eq) goto loc_82285FCC;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lfs f0,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x8228615c
	if (!cr6.lt) goto loc_8228615C;
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// ble cr6,0x8228615c
	if (!cr6.gt) goto loc_8228615C;
	// addi r31,r28,80
	r31.s64 = r28.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228611C;
	sub_822842E0(ctx, base);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// bne cr6,0x82286144
	if (!cr6.eq) goto loc_82286144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228612C;
	sub_822842E0(ctx, base);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// bne cr6,0x8228615c
	if (!cr6.eq) goto loc_8228615C;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lbz r11,629(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228615c
	if (!cr6.eq) goto loc_8228615C;
loc_82286144:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8228615C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82286174"))) PPC_WEAK_FUNC(sub_82286174);
PPC_FUNC_IMPL(__imp__sub_82286174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82286178"))) PPC_WEAK_FUNC(sub_82286178);
PPC_FUNC_IMPL(__imp__sub_82286178) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82285f48
	ctx.lr = 0x82286198;
	sub_82285F48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822861AC;
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

__attribute__((alias("__imp__sub_822861C4"))) PPC_WEAK_FUNC(sub_822861C4);
PPC_FUNC_IMPL(__imp__sub_822861C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

