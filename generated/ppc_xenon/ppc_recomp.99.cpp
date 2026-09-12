#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824EDE48"))) PPC_WEAK_FUNC(sub_824EDE48);
PPC_FUNC_IMPL(__imp__sub_824EDE48) {
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
	ctx.lr = 0x824EDE50;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r28,1292
	ctx.r4.s64 = r28.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EDE68;
	sub_821C8FE0(ctx, base);
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824eded0
	if (!cr6.eq) goto loc_824EDED0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EDE80;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ede90
	if (cr6.lt) goto loc_824EDE90;
	// li r11,0
	r11.s64 = 0;
loc_824EDE90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eded0
	if (!cr6.eq) goto loc_824EDED0;
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824edec0
	if (!cr6.eq) goto loc_824EDEC0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EDEB4;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824edec4
	if (cr6.eq) goto loc_824EDEC4;
loc_824EDEC0:
	// li r11,0
	r11.s64 = 0;
loc_824EDEC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824edf40
	if (cr6.eq) goto loc_824EDF40;
loc_824EDED0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EDED8;
	sub_821F6C70(ctx, base);
	// addi r31,r28,72
	r31.s64 = r28.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824edcc0
	ctx.lr = 0x824EDEF0;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EDEF8;
	sub_824E6310(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// lwz r29,104(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r3,r29,64
	ctx.r3.s64 = r29.s64 + 64;
	// bl 0x824eb108
	ctx.lr = 0x824EDF14;
	sub_824EB108(ctx, base);
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824edf2c
	if (!cr6.eq) goto loc_824EDF2C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ed698
	ctx.lr = 0x824EDF2C;
	sub_824ED698(ctx, base);
loc_824EDF2C:
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,144(r30)
	PPC_STORE_U8(r30.u32 + 144, ctx.r10.u8);
	// bl 0x82533130
	ctx.lr = 0x824EDF40;
	sub_82533130(ctx, base);
loc_824EDF40:
	// addi r4,r28,112
	ctx.r4.s64 = r28.s64 + 112;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824eac30
	ctx.lr = 0x824EDF54;
	sub_824EAC30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EDF5C;
	sub_821C9030(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EDF64"))) PPC_WEAK_FUNC(sub_824EDF64);
PPC_FUNC_IMPL(__imp__sub_824EDF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EDF68"))) PPC_WEAK_FUNC(sub_824EDF68);
PPC_FUNC_IMPL(__imp__sub_824EDF68) {
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
	ctx.lr = 0x824EDF70;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EDF8C;
	sub_821C8FE0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r28,15
	cr6.compare<uint32_t>(r28.u32, 15, xer);
	// bgt cr6,0x824edfd4
	if (cr6.gt) goto loc_824EDFD4;
	// addi r31,r31,72
	r31.s64 = r31.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824edcc0
	ctx.lr = 0x824EDFB0;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EDFB8;
	sub_824E6310(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// beq cr6,0x824edfd4
	if (cr6.eq) goto loc_824EDFD4;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_824EDFD4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EDFDC;
	sub_821C9030(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EDFE8"))) PPC_WEAK_FUNC(sub_824EDFE8);
PPC_FUNC_IMPL(__imp__sub_824EDFE8) {
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
	ctx.lr = 0x824EDFF0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r30,1292
	ctx.r4.s64 = r30.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE018;
	sub_821C8FE0(ctx, base);
	// li r23,0
	r23.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r23
	r29.u64 = r23.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EE02C;
	sub_824EAFA0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ee058
	if (!cr6.eq) goto loc_824EE058;
	// bl 0x8218f5b0
	ctx.lr = 0x824EE04C;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ee05c
	if (cr6.eq) goto loc_824EE05C;
loc_824EE058:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824EE05C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee08c
	if (!cr6.eq) goto loc_824EE08C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EE070;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ee080
	if (cr6.lt) goto loc_824EE080;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824EE080:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
loc_824EE08C:
	// clrlwi r24,r25,31
	r24.u64 = r25.u32 & 0x1;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x824ee0b8
	if (!cr6.eq) goto loc_824EE0B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x824EE0A0;
	sub_82618698(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eca00
	ctx.lr = 0x824EE0AC;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee15c
	if (!cr6.eq) goto loc_824EE15C;
loc_824EE0B8:
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533190
	ctx.lr = 0x824EE0D0;
	sub_82533190(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee10c
	if (!cr6.eq) goto loc_824EE10C;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824ee10c
	if (cr6.eq) goto loc_824EE10C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ecad8
	ctx.lr = 0x824EE0F0;
	sub_824ECAD8(ctx, base);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533190
	ctx.lr = 0x824EE108;
	sub_82533190(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_824EE10C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
	// rlwinm r11,r25,0,7,7
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x1000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EE12C;
	sub_821F6C70(ctx, base);
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824edcc0
	ctx.lr = 0x824EE144;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EE14C;
	sub_824E6310(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r23,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r23.u32);
	// stw r23,132(r11)
	PPC_STORE_U32(r11.u32 + 132, r23.u32);
loc_824EE15C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee178
	if (!cr6.eq) goto loc_824EE178;
	// clrlwi r11,r25,31
	r11.u64 = r25.u32 & 0x1;
	// mr r31,r23
	r31.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee17c
	if (!cr6.eq) goto loc_824EE17C;
loc_824EE178:
	// li r31,1
	r31.s64 = 1;
loc_824EE17C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EE184;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824EE190"))) PPC_WEAK_FUNC(sub_824EE190);
PPC_FUNC_IMPL(__imp__sub_824EE190) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824EE198;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE1B4;
	sub_821C8FE0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edf68
	ctx.lr = 0x824EE1C4;
	sub_824EDF68(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ee1e8
	if (cr6.eq) goto loc_824EE1E8;
	// bl 0x82656bf8
	ctx.lr = 0x824EE1D0;
	sub_82656BF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EE1DC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824EE1E8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	r31.s64 = -1;
	// bl 0x821c9030
	ctx.lr = 0x824EE1F4;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EE200"))) PPC_WEAK_FUNC(sub_824EE200);
PPC_FUNC_IMPL(__imp__sub_824EE200) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824EE208;
	// stwu r1,-1328(r1)
	ea = -1328 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r14,r4
	r14.u64 = ctx.r4.u64;
	// addi r4,r25,1292
	ctx.r4.s64 = r25.s64 + 1292;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE22C;
	sub_821C8FE0(ctx, base);
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// blt cr6,0x824ee5b8
	if (cr6.lt) goto loc_824EE5B8;
	// cmplwi cr6,r30,1024
	cr6.compare<uint32_t>(r30.u32, 1024, xer);
	// bgt cr6,0x824ee5b8
	if (cr6.gt) goto loc_824EE5B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EE248;
	sub_82533EF0(ctx, base);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bgt cr6,0x824ee5b8
	if (cr6.gt) goto loc_824EE5B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EE258;
	sub_82533EF0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r27,r28,r30
	r27.s64 = r30.s64 - r28.s64;
	// bl 0x82533f58
	ctx.lr = 0x824EE268;
	sub_82533F58(ctx, base);
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee294
	if (cr6.eq) goto loc_824EE294;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ea950
	ctx.lr = 0x824EE288;
	sub_824EA950(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ee5b8
	if (cr6.eq) goto loc_824EE5B8;
loc_824EE294:
	// addi r30,r25,72
	r30.s64 = r25.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824edcc0
	ctx.lr = 0x824EE2AC;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EE2B4;
	sub_824E6310(ctx, base);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// li r16,0
	r16.s64 = 0;
	// lwz r17,136(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r16,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r16.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r16,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r16.u32);
	// stw r16,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r16.u32);
	// std r16,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r16.u64);
	// beq cr6,0x824ee300
	if (cr6.eq) goto loc_824EE300;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EE2E8;
	sub_82533FC0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x82533f20
	ctx.lr = 0x824EE2F8;
	sub_82533F20(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_824EE300:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824ee318
	if (cr6.eq) goto loc_824EE318;
	// add r11,r28,r31
	r11.u64 = r28.u64 + r31.u64;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_824EE318:
	// li r20,2
	r20.s64 = 2;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r18,r1,84
	r18.s64 = ctx.r1.s64 + 84;
	// mr r15,r20
	r15.u64 = r20.u64;
	// li r19,1
	r19.s64 = 1;
	// addi r21,r11,26944
	r21.s64 = r11.s64 + 26944;
loc_824EE330:
	// lwz r31,-4(r18)
	r31.u64 = PPC_LOAD_U32(r18.u32 + -4);
	// lwz r22,0(r18)
	r22.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// cmplw cr6,r31,r22
	cr6.compare<uint32_t>(r31.u32, r22.u32, xer);
	// bge cr6,0x824ee5ac
	if (!cr6.lt) goto loc_824EE5AC;
loc_824EE340:
	// subf r30,r31,r22
	r30.s64 = r22.s64 - r31.s64;
	// cmplwi cr6,r30,9
	cr6.compare<uint32_t>(r30.u32, 9, xer);
	// blt cr6,0x824ee5ac
	if (cr6.lt) goto loc_824EE5AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534318
	ctx.lr = 0x824EE354;
	sub_82534318(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplw cr6,r24,r30
	cr6.compare<uint32_t>(r24.u32, r30.u32, xer);
	// bgt cr6,0x824ee5ac
	if (cr6.gt) goto loc_824EE5AC;
	// cmplwi cr6,r24,9
	cr6.compare<uint32_t>(r24.u32, 9, xer);
	// blt cr6,0x824ee5ac
	if (cr6.lt) goto loc_824EE5AC;
	// cmplwi cr6,r24,1021
	cr6.compare<uint32_t>(r24.u32, 1021, xer);
	// bgt cr6,0x824ee5ac
	if (cr6.gt) goto loc_824EE5AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340d0
	ctx.lr = 0x824EE378;
	sub_825340D0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,15
	cr6.compare<uint32_t>(r28.u32, 15, xer);
	// bgt cr6,0x824ee5ac
	if (cr6.gt) goto loc_824EE5AC;
	// mulli r11,r28,68
	r11.s64 = r28.s64 * 68;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb8e0
	ctx.lr = 0x824EE3A0;
	sub_824EB8E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340a0
	ctx.lr = 0x824EE3A8;
	sub_825340A0(ctx, base);
	// rlwinm r11,r3,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee550
	if (!cr6.eq) goto loc_824EE550;
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// beq cr6,0x824ee3cc
	if (cr6.eq) goto loc_824EE3CC;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r11,r17
	r27.u64 = PPC_LOAD_U32(r11.u32 + r17.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x824ee45c
	if (!cr6.eq) goto loc_824EE45C;
loc_824EE3CC:
	// rlwinm r11,r28,27,5,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r28,27
	ctx.r10.u64 = r28.u32 & 0x1F;
	// addi r9,r11,333
	ctx.r9.s64 = r11.s64 + 333;
	// slw r8,r19,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r19.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r25.u32);
	// and r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825341a0
	ctx.lr = 0x824EE3F8;
	sub_825341A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE40C;
	sub_82534068(ctx, base);
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// blt cr6,0x824ee5a0
	if (cr6.lt) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE41C;
	sub_82534248(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82534318
	ctx.lr = 0x824EE424;
	sub_82534318(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825344c8
	ctx.lr = 0x824EE430;
	sub_825344C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340d0
	ctx.lr = 0x824EE444;
	sub_825340D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x824ed718
	ctx.lr = 0x824EE458;
	sub_824ED718(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE45C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EE464;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534210
	ctx.lr = 0x824EE474;
	sub_82534210(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee538
	if (cr6.eq) goto loc_824EE538;
	// lwz r3,12(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,168
	ctx.r4.s64 = 168;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ee52c
	if (cr6.eq) goto loc_824EE52C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE4B4;
	sub_82534068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ee4cc
	if (cr6.eq) goto loc_824EE4CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE4C4;
	sub_82534248(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x824ee4d0
	goto loc_824EE4D0;
loc_824EE4CC:
	// mr r26,r16
	r26.u64 = r16.u64;
loc_824EE4D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE4D8;
	sub_82534068(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EE4E4;
	sub_82656BF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r4,12(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EE4F8;
	sub_825301E0(ctx, base);
	// stw r29,164(r30)
	PPC_STORE_U32(r30.u32 + 164, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r20,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r20.u32);
	// stw r21,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r21.u32);
	// beq cr6,0x824ee51c
	if (cr6.eq) goto loc_824EE51C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r30,36
	ctx.r3.s64 = r30.s64 + 36;
	// bl 0x8244d5c0
	ctx.lr = 0x824EE51C;
	sub_8244D5C0(ctx, base);
loc_824EE51C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ec9a0
	ctx.lr = 0x824EE528;
	sub_824EC9A0(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE52C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EE534;
	sub_824ECCE8(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE538:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825337f0
	ctx.lr = 0x824EE54C;
	sub_825337F0(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE550:
	// cmplwi cr6,r24,9
	cr6.compare<uint32_t>(r24.u32, 9, xer);
	// ble cr6,0x824ee5a0
	if (!cr6.gt) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE560;
	sub_82534068(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,1012
	cr6.compare<uint32_t>(r30.u32, 1012, xer);
	// bgt cr6,0x824ee5a0
	if (cr6.gt) goto loc_824EE5A0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE57C;
	sub_82534248(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340d0
	ctx.lr = 0x824EE588;
	sub_825340D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x824ed840
	ctx.lr = 0x824EE5A0;
	sub_824ED840(ctx, base);
loc_824EE5A0:
	// add r31,r24,r31
	r31.u64 = r24.u64 + r31.u64;
	// cmplw cr6,r31,r22
	cr6.compare<uint32_t>(r31.u32, r22.u32, xer);
	// blt cr6,0x824ee340
	if (cr6.lt) goto loc_824EE340;
loc_824EE5AC:
	// addic. r15,r15,-1
	xer.ca = r15.u32 > 0;
	r15.s64 = r15.s64 + -1;
	cr0.compare<int32_t>(r15.s32, 0, xer);
	// addi r18,r18,8
	r18.s64 = r18.s64 + 8;
	// bne 0x824ee330
	if (!cr0.eq) goto loc_824EE330;
loc_824EE5B8:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EE5C0;
	sub_821C9030(ctx, base);
	// addi r1,r1,1328
	ctx.r1.s64 = ctx.r1.s64 + 1328;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824EE5C8"))) PPC_WEAK_FUNC(sub_824EE5C8);
PPC_FUNC_IMPL(__imp__sub_824EE5C8) {
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
	ctx.lr = 0x824EE5D0;
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r29,1006
	cr6.compare<uint32_t>(r29.u32, 1006, xer);
	// bgt cr6,0x824ee724
	if (cr6.gt) goto loc_824EE724;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x824eca00
	ctx.lr = 0x824EE600;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee724
	if (!cr6.eq) goto loc_824EE724;
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824edcc0
	ctx.lr = 0x824EE624;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EE62C;
	sub_824E6310(ctx, base);
	// lwz r22,88(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// beq cr6,0x824ee730
	if (cr6.eq) goto loc_824EE730;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ee724
	if (cr6.eq) goto loc_824EE724;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r29,9
	ctx.r4.s64 = r29.s64 + 9;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE68C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ee70c
	if (cr6.eq) goto loc_824EE70C;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// ori r9,r27,8
	ctx.r9.u64 = r27.u64 | 8;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// stw r26,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r26.u32);
	// bl 0x82533fc8
	ctx.lr = 0x824EE6C8;
	sub_82533FC8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE6D0;
	sub_82534248(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EE6DC;
	sub_8244D5C0(ctx, base);
	// rlwinm r10,r27,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x10;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r22,88
	ctx.r4.s64 = r22.s64 + 88;
	// bne cr6,0x824ee6fc
	if (!cr6.eq) goto loc_824EE6FC;
	// addi r4,r22,76
	ctx.r4.s64 = r22.s64 + 76;
loc_824EE6FC:
	// bl 0x824e7930
	ctx.lr = 0x824EE700;
	sub_824E7930(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d9230
	return;
loc_824EE70C:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EE724:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d9230
	return;
loc_824EE730:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82533fc0
	ctx.lr = 0x824EE738;
	sub_82533FC0(ctx, base);
	// ori r9,r27,8
	ctx.r9.u64 = r27.u64 | 8;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82533fc8
	ctx.lr = 0x824EE758;
	sub_82533FC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE760;
	sub_82534248(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EE76C;
	sub_8244D5C0(ctx, base);
	// rlwinm r11,r27,0,27,27
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee78c
	if (cr6.eq) goto loc_824EE78C;
	// mr r31,r26
	r31.u64 = r26.u64;
	// bl 0x82534318
	ctx.lr = 0x824EE784;
	sub_82534318(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x824ee798
	goto loc_824EE798;
loc_824EE78C:
	// bl 0x82534318
	ctx.lr = 0x824EE790;
	sub_82534318(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_824EE798:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82533e98
	ctx.lr = 0x824EE7A8;
	sub_82533E98(ctx, base);
	// mulli r11,r24,68
	r11.s64 = r24.s64 * 68;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb858
	ctx.lr = 0x824EE7C4;
	sub_824EB858(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ea9d0
	ctx.lr = 0x824EE7D8;
	sub_824EA9D0(ctx, base);
	// subf r11,r26,r3
	r11.s64 = ctx.r3.s64 - r26.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EE7EC"))) PPC_WEAK_FUNC(sub_824EE7EC);
PPC_FUNC_IMPL(__imp__sub_824EE7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EE7F0"))) PPC_WEAK_FUNC(sub_824EE7F0);
PPC_FUNC_IMPL(__imp__sub_824EE7F0) {
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
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee87c
	if (cr6.eq) goto loc_824EE87C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x824EE820;
	sub_824E6310(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824f8f38
	ctx.lr = 0x824EE838;
	sub_824F8F38(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824ee8e8
	if (!cr6.gt) goto loc_824EE8E8;
loc_824EE840:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee200
	ctx.lr = 0x824EE858;
	sub_824EE200(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824f8f38
	ctx.lr = 0x824EE870;
	sub_824F8F38(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x824ee840
	if (cr6.gt) goto loc_824EE840;
	// b 0x824ee8e8
	goto loc_824EE8E8;
loc_824EE87C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee8e8
	if (cr6.eq) goto loc_824EE8E8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x824EE890;
	sub_824E6310(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82533dc0
	ctx.lr = 0x824EE8A8;
	sub_82533DC0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824ee8e8
	if (!cr6.gt) goto loc_824EE8E8;
loc_824EE8B0:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee200
	ctx.lr = 0x824EE8C8;
	sub_824EE200(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82533dc0
	ctx.lr = 0x824EE8E0;
	sub_82533DC0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x824ee8b0
	if (cr6.gt) goto loc_824EE8B0;
loc_824EE8E8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
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

__attribute__((alias("__imp__sub_824EE904"))) PPC_WEAK_FUNC(sub_824EE904);
PPC_FUNC_IMPL(__imp__sub_824EE904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EE908"))) PPC_WEAK_FUNC(sub_824EE908);
PPC_FUNC_IMPL(__imp__sub_824EE908) {
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
	ctx.lr = 0x824EE910;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x821c9788
	ctx.lr = 0x824EE91C;
	sub_821C9788(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r27,0
	r27.s64 = 0;
	// addi r25,r26,156
	r25.s64 = r26.s64 + 156;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r24,r26,1292
	r24.s64 = r26.s64 + 1292;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// li r22,2
	r22.s64 = 2;
	// stw r3,30444(r11)
	PPC_STORE_U32(r11.u32 + 30444, ctx.r3.u32);
	// li r23,-1
	r23.s64 = -1;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
loc_824EE944:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE950;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee964
	if (cr6.eq) goto loc_824EE964;
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x824ee968
	goto loc_824EE968;
loc_824EE964:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EE968:
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ee97c
	if (cr6.eq) goto loc_824EE97C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EE97C;
	sub_824EB248(ctx, base);
loc_824EE97C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eea88
	if (cr6.eq) goto loc_824EEA88;
loc_824EE984:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee9b0
	if (cr6.eq) goto loc_824EE9B0;
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// bne cr6,0x824ee9b8
	if (!cr6.eq) goto loc_824EE9B8;
	// b 0x824ee9b4
	goto loc_824EE9B4;
loc_824EE9B0:
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
loc_824EE9B4:
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
loc_824EE9B8:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824EE9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x824eea18
	if (!cr6.eq) goto loc_824EEA18;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824eafa0
	ctx.lr = 0x824EE9F0;
	sub_824EAFA0(ctx, base);
	// lwz r31,140(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eea54
	if (cr6.eq) goto loc_824EEA54;
	// stw r27,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r27.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EEA10;
	sub_821CE0A0(ctx, base);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// b 0x824eea54
	goto loc_824EEA54;
loc_824EEA18:
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x824eea54
	if (!cr6.eq) goto loc_824EEA54;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824eafa0
	ctx.lr = 0x824EEA30;
	sub_824EAFA0(ctx, base);
	// lwz r31,140(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eea54
	if (cr6.eq) goto loc_824EEA54;
	// stw r27,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r27.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EEA50;
	sub_821CE0A0(ctx, base);
	// stw r23,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r23.u32);
loc_824EEA54:
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eea68
	if (cr6.eq) goto loc_824EEA68;
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x824eea6c
	goto loc_824EEA6C;
loc_824EEA68:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EEA6C:
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eea80
	if (cr6.eq) goto loc_824EEA80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EEA80;
	sub_824EB248(ctx, base);
loc_824EEA80:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ee984
	if (!cr6.eq) goto loc_824EE984;
loc_824EEA88:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EEA90;
	sub_821C9030(ctx, base);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eeaa8
	if (!cr6.eq) goto loc_824EEAA8;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_824EEAA8:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eeab8
	if (cr6.eq) goto loc_824EEAB8;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824eb248
	ctx.lr = 0x824EEAB8;
	sub_824EB248(ctx, base);
loc_824EEAB8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824eec10
	if (cr6.eq) goto loc_824EEC10;
loc_824EEAC0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EEAD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824eeba4
	if (!cr6.eq) goto loc_824EEBA4;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r30,r11,32
	r30.s64 = r11.s64 + 32;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x821c8fe0
	ctx.lr = 0x824EEAF4;
	sub_821C8FE0(ctx, base);
	// mr r31,r27
	r31.u64 = r27.u64;
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// bgt cr6,0x824eeb94
	if (cr6.gt) goto loc_824EEB94;
	// addi r31,r26,72
	r31.s64 = r26.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824ed1f0
	ctx.lr = 0x824EEB18;
	sub_824ED1F0(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824e6310
	ctx.lr = 0x824EEB20;
	sub_824E6310(ctx, base);
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eeb54
	if (cr6.eq) goto loc_824EEB54;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e62a0
	ctx.lr = 0x824EEB40;
	sub_824E62A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eeb54
	if (!cr6.eq) goto loc_824EEB54;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// b 0x824eeb68
	goto loc_824EEB68;
loc_824EEB54:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824e6310
	ctx.lr = 0x824EEB5C;
	sub_824E6310(ctx, base);
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r31.u32);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stw r27,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r27.u32);
loc_824EEB68:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824e6310
	ctx.lr = 0x824EEB74;
	sub_824E6310(ctx, base);
	// stw r31,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r27,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r27.u32);
	// beq cr6,0x824eeb90
	if (cr6.eq) goto loc_824EEB90;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// b 0x824eeb94
	goto loc_824EEB94;
loc_824EEB90:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EEB94:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824EEB9C;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eebd4
	if (!cr6.eq) goto loc_824EEBD4;
loc_824EEBA4:
	// addi r4,r26,124
	ctx.r4.s64 = r26.s64 + 124;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEBB0;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824ebff8
	ctx.lr = 0x824EEBCC;
	sub_824EBFF8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EEBD4;
	sub_821C9030(ctx, base);
loc_824EEBD4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82530158
	ctx.lr = 0x824EEBDC;
	sub_82530158(ctx, base);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eebf4
	if (!cr6.eq) goto loc_824EEBF4;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EEBF4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eec04
	if (cr6.eq) goto loc_824EEC04;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824eb248
	ctx.lr = 0x824EEC04;
	sub_824EB248(ctx, base);
loc_824EEC04:
	// mr r28,r31
	r28.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eeac0
	if (!cr6.eq) goto loc_824EEAC0;
loc_824EEC10:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// bne 0x824ee944
	if (!cr0.eq) goto loc_824EE944;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824fecd0
	ctx.lr = 0x824EEC20;
	sub_824FECD0(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EEC28"))) PPC_WEAK_FUNC(sub_824EEC28);
PPC_FUNC_IMPL(__imp__sub_824EEC28) {
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
	ctx.lr = 0x824EEC30;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r27,1292
	ctx.r4.s64 = r27.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEC4C;
	sub_821C8FE0(ctx, base);
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// li r28,0
	r28.s64 = 0;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// mr r26,r28
	r26.u64 = r28.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824eec78
	if (!cr6.eq) goto loc_824EEC78;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EEC6C;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824eec7c
	if (cr6.eq) goto loc_824EEC7C;
loc_824EEC78:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EEC7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eed28
	if (cr6.eq) goto loc_824EED28;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824eec98
	if (!cr6.eq) goto loc_824EEC98;
	// stw r28,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r28.u32);
	// b 0x824eeca4
	goto loc_824EECA4;
loc_824EEC98:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EECA4:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824eedf8
	if (!cr6.eq) goto loc_824EEDF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eae00
	ctx.lr = 0x824EECB8;
	sub_824EAE00(ctx, base);
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x824eecdc
	if (cr6.eq) goto loc_824EECDC;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x824eecdc
	if (cr6.eq) goto loc_824EECDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eae68
	ctx.lr = 0x824EECD0;
	sub_824EAE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eece0
	if (cr6.eq) goto loc_824EECE0;
loc_824EECDC:
	// li r26,1
	r26.s64 = 1;
loc_824EECE0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EECE8;
	sub_821F6C70(ctx, base);
	// addi r30,r27,72
	r30.s64 = r27.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824edcc0
	ctx.lr = 0x824EED00;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EED08;
	sub_824E6310(ctx, base);
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,136(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82618698
	ctx.lr = 0x824EED1C;
	sub_82618698(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r28.u32);
	// b 0x824eedf8
	goto loc_824EEDF8;
loc_824EED28:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EED30;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824eed40
	if (cr6.lt) goto loc_824EED40;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EED40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eede4
	if (cr6.eq) goto loc_824EEDE4;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824eed5c
	if (!cr6.eq) goto loc_824EED5C;
	// stw r28,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r28.u32);
	// b 0x824eed68
	goto loc_824EED68;
loc_824EED5C:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EED68:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824eedf8
	if (!cr6.eq) goto loc_824EEDF8;
	// lwz r30,140(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eed9c
	if (cr6.eq) goto loc_824EED9C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EED90;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// stw r28,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r28.u32);
loc_824EED9C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EEDA4;
	sub_821F6C70(ctx, base);
	// addi r30,r27,72
	r30.s64 = r27.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824edcc0
	ctx.lr = 0x824EEDBC;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EEDC4;
	sub_824E6310(ctx, base);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,136(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82618698
	ctx.lr = 0x824EEDD8;
	sub_82618698(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r28.u32);
	// b 0x824eedf4
	goto loc_824EEDF4;
loc_824EEDE4:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eedf8
	if (cr6.eq) goto loc_824EEDF8;
loc_824EEDF4:
	// li r26,1
	r26.s64 = 1;
loc_824EEDF8:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eee88
	if (cr6.eq) goto loc_824EEE88;
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EEE24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eee74
	if (cr6.eq) goto loc_824EEE74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x824EEE38;
	sub_82618698(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EEE44;
	sub_82656BF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r4,12(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EEE58;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,26956
	ctx.r10.s64 = r11.s64 + 26956;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x824ec9a0
	ctx.lr = 0x824EEE70;
	sub_824EC9A0(ctx, base);
	// b 0x824eee7c
	goto loc_824EEE7C;
loc_824EEE74:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EEE7C;
	sub_824ECCE8(ctx, base);
loc_824EEE7C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ede48
	ctx.lr = 0x824EEE88;
	sub_824EDE48(ctx, base);
loc_824EEE88:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EEE90;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824EEE9C"))) PPC_WEAK_FUNC(sub_824EEE9C);
PPC_FUNC_IMPL(__imp__sub_824EEE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EEEA0"))) PPC_WEAK_FUNC(sub_824EEEA0);
PPC_FUNC_IMPL(__imp__sub_824EEEA0) {
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
	ctx.lr = 0x824EEEA8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbz r11,1336(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef214
	if (cr6.eq) goto loc_824EF214;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eeee4
	if (cr6.eq) goto loc_824EEEE4;
	// addi r3,r28,1272
	ctx.r3.s64 = r28.s64 + 1272;
	// bl 0x824ea7b0
	ctx.lr = 0x824EEED4;
	sub_824EA7B0(ctx, base);
	// lbz r11,1336(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r10,1336(r28)
	PPC_STORE_U8(r28.u32 + 1336, ctx.r10.u8);
loc_824EEEE4:
	// addi r26,r28,124
	r26.s64 = r28.s64 + 124;
	// addi r24,r28,1292
	r24.s64 = r28.s64 + 1292;
	// addi r29,r28,236
	r29.s64 = r28.s64 + 236;
	// li r27,16
	r27.s64 = 16;
	// li r25,0
	r25.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
loc_824EEEFC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEF08;
	sub_821C8FE0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eef68
	if (cr6.eq) goto loc_824EEF68;
loc_824EEF14:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r31,-8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEF24;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eef54
	if (cr6.eq) goto loc_824EEF54;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x824eb248
	ctx.lr = 0x824EEF48;
	sub_824EB248(ctx, base);
	// stw r25,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r25.u32);
	// stw r25,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r25.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_824EEF54:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EEF5C;
	sub_821C9030(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eef14
	if (!cr6.eq) goto loc_824EEF14;
loc_824EEF68:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EEF70;
	sub_821C9030(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEF7C;
	sub_821C8FE0(ctx, base);
	// stw r30,-52(r29)
	PPC_STORE_U32(r29.u32 + -52, r30.u32);
	// addi r3,r29,-20
	ctx.r3.s64 = r29.s64 + -20;
	// bl 0x825307d0
	ctx.lr = 0x824EEF88;
	sub_825307D0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c9030
	ctx.lr = 0x824EEF90;
	sub_821C9030(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bne 0x824eeefc
	if (!cr0.eq) goto loc_824EEEFC;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEFA8;
	sub_821C8FE0(ctx, base);
	// lwz r11,68(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef070
	if (cr6.eq) goto loc_824EF070;
	// addi r29,r28,60
	r29.s64 = r28.s64 + 60;
loc_824EEFB8:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r30,72(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eefec
	if (cr6.eq) goto loc_824EEFEC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824ef064
	if (!cr6.gt) goto loc_824EF064;
loc_824EEFD0:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EEFE0;
	sub_824EEC28(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x824eefd0
	if (!cr0.eq) goto loc_824EEFD0;
	// b 0x824ef064
	goto loc_824EF064;
loc_824EEFEC:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEFF8;
	sub_821C8FE0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r28,72
	ctx.r4.s64 = r28.s64 + 72;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ece80
	ctx.lr = 0x824EF008;
	sub_824ECE80(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EF014;
	sub_824EB308(ctx, base);
	// stw r25,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r25.u32);
	// lwz r10,52(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// addi r11,r28,48
	r11.s64 = r28.s64 + 48;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef048
	if (cr6.eq) goto loc_824EF048;
	// stw r31,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, r31.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// bne cr6,0x824ef050
	if (!cr6.eq) goto loc_824EF050;
	// b 0x824ef04c
	goto loc_824EF04C;
loc_824EF048:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
loc_824EF04C:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_824EF050:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x824EF064;
	sub_821C9030(ctx, base);
loc_824EF064:
	// lwz r11,68(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eefb8
	if (!cr6.eq) goto loc_824EEFB8;
loc_824EF070:
	// lwz r11,120(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r31,r28,112
	r31.s64 = r28.s64 + 112;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef0a0
	if (cr6.eq) goto loc_824EF0A0;
loc_824EF080:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef094
	if (cr6.eq) goto loc_824EF094;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb108
	ctx.lr = 0x824EF094;
	sub_824EB108(ctx, base);
loc_824EF094:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef080
	if (!cr6.eq) goto loc_824EF080;
loc_824EF0A0:
	// lwz r11,56(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r31,r28,48
	r31.s64 = r28.s64 + 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef0d0
	if (cr6.eq) goto loc_824EF0D0;
loc_824EF0B0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef0c4
	if (cr6.eq) goto loc_824EF0C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EF0C4;
	sub_824EB308(ctx, base);
loc_824EF0C4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef0b0
	if (!cr6.eq) goto loc_824EF0B0;
loc_824EF0D0:
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r31,r28,20
	r31.s64 = r28.s64 + 20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef0f0
	if (cr6.eq) goto loc_824EF0F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ed930
	ctx.lr = 0x824EF0EC;
	sub_824ED930(ctx, base);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_824EF0F0:
	// lwz r11,84(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// addi r31,r28,84
	r31.s64 = r28.s64 + 84;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef110
	if (cr6.eq) goto loc_824EF110;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb3c8
	ctx.lr = 0x824EF10C;
	sub_824EB3C8(ctx, base);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_824EF110:
	// lwz r11,164(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef128
	if (cr6.eq) goto loc_824EF128;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x824ef12c
	goto loc_824EF12C;
loc_824EF128:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824EF12C:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef140
	if (cr6.eq) goto loc_824EF140;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EF140;
	sub_824EB248(ctx, base);
loc_824EF140:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ef188
	if (cr6.eq) goto loc_824EF188;
loc_824EF14C:
	// bl 0x82530158
	ctx.lr = 0x824EF150;
	sub_82530158(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef164
	if (cr6.eq) goto loc_824EF164;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x824ef168
	goto loc_824EF168;
loc_824EF164:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824EF168:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef17c
	if (cr6.eq) goto loc_824EF17C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EF17C;
	sub_824EB248(ctx, base);
loc_824EF17C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824ef14c
	if (!cr6.eq) goto loc_824EF14C;
loc_824EF188:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef1c0
	if (cr6.eq) goto loc_824EF1C0;
loc_824EF194:
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EF1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,16(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ef194
	if (!cr6.eq) goto loc_824EF194;
loc_824EF1C0:
	// bl 0x824fa8a8
	ctx.lr = 0x824EF1C4;
	sub_824FA8A8(ctx, base);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,27016
	ctx.r4.s64 = r11.s64 + 27016;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EF1E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r25,1332(r28)
	PPC_STORE_U32(r28.u32 + 1332, r25.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lbz r7,1336(r28)
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// rlwimi r7,r8,6,0,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0xFFFFFFC0) | (ctx.r7.u64 & 0xFFFFFFFF0000003F);
	// stw r25,1324(r28)
	PPC_STORE_U32(r28.u32 + 1324, r25.u32);
	// stw r25,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r25.u32);
	// stw r25,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r25.u32);
	// stw r25,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r25.u32);
	// sth r25,1328(r28)
	PPC_STORE_U16(r28.u32 + 1328, r25.u16);
	// stb r7,1336(r28)
	PPC_STORE_U8(r28.u32 + 1336, ctx.r7.u8);
	// bl 0x821c9030
	ctx.lr = 0x824EF214;
	sub_821C9030(ctx, base);
loc_824EF214:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824EF21C"))) PPC_WEAK_FUNC(sub_824EF21C);
PPC_FUNC_IMPL(__imp__sub_824EF21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EF220"))) PPC_WEAK_FUNC(sub_824EF220);
PPC_FUNC_IMPL(__imp__sub_824EF220) {
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
	ctx.lr = 0x824EF228;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF244;
	sub_821C8FE0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824ef280
	if (cr6.lt) goto loc_824EF280;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EF258;
	sub_824EAFA0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef280
	if (cr6.eq) goto loc_824EF280;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EF270;
	sub_824EEC28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef284
	if (!cr6.eq) goto loc_824EF284;
loc_824EF280:
	// li r31,0
	r31.s64 = 0;
loc_824EF284:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EF28C;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EF298"))) PPC_WEAK_FUNC(sub_824EF298);
PPC_FUNC_IMPL(__imp__sub_824EF298) {
	PPC_FUNC_PROLOGUE();
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x824ee5c8
	sub_824EE5C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824EF2A0"))) PPC_WEAK_FUNC(sub_824EF2A0);
PPC_FUNC_IMPL(__imp__sub_824EF2A0) {
	PPC_FUNC_PROLOGUE();
	// li r8,16
	ctx.r8.s64 = 16;
	// b 0x824ee5c8
	sub_824EE5C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824EF2A8"))) PPC_WEAK_FUNC(sub_824EF2A8);
PPC_FUNC_IMPL(__imp__sub_824EF2A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x824EF2B0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// addi r4,r26,1292
	ctx.r4.s64 = r26.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF2D4;
	sub_821C8FE0(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// lwz r31,16(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ef35c
	if (cr6.eq) goto loc_824EF35C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,16(r26)
	PPC_STORE_U32(r26.u32 + 16, r11.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82533ef0
	ctx.lr = 0x824EF2F4;
	sub_82533EF0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplw cr6,r25,r30
	cr6.compare<uint32_t>(r25.u32, r30.u32, xer);
	// bgt cr6,0x824ef32c
	if (cr6.gt) goto loc_824EF32C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82533ef0
	ctx.lr = 0x824EF308;
	sub_82533EF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EF318;
	sub_8244D5C0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r20)
	PPC_STORE_U32(r20.u32 + 4, ctx.r10.u32);
	// b 0x824ef330
	goto loc_824EF330;
loc_824EF32C:
	// li r25,0
	r25.s64 = 0;
loc_824EF330:
	// lwz r3,12(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EF348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EF350;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
loc_824EF35C:
	// cmplwi cr6,r30,12
	cr6.compare<uint32_t>(r30.u32, 12, xer);
	// ble cr6,0x824ef60c
	if (!cr6.gt) goto loc_824EF60C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EF36C;
	sub_82533FC0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r21,68(r26)
	r21.u64 = PPC_LOAD_U32(r26.u32 + 68);
	// subf r11,r29,r22
	r11.s64 = r22.s64 - r29.s64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// add r28,r11,r30
	r28.u64 = r11.u64 + r30.u64;
	// beq cr6,0x824ef60c
	if (cr6.eq) goto loc_824EF60C;
loc_824EF384:
	// addi r21,r21,-1
	r21.s64 = r21.s64 + -1;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x824ef60c
	if (!cr6.eq) goto loc_824EF60C;
	// lwz r4,60(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 60);
	// addi r31,r26,60
	r31.s64 = r26.s64 + 60;
	// extsw r27,r4
	r27.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef3ac
	if (cr6.eq) goto loc_824EF3AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EF3AC;
	sub_824EB308(ctx, base);
loc_824EF3AC:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eacc8
	ctx.lr = 0x824EF3C0;
	sub_824EACC8(ctx, base);
	// lwz r11,132(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef3d4
	if (cr6.eq) goto loc_824EF3D4;
	// subf. r11,r11,r24
	r11.s64 = r24.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x824ef604
	if (!cr0.gt) goto loc_824EF604;
loc_824EF3D4:
	// lwz r11,1324(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 1324);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef3ec
	if (cr6.eq) goto loc_824EF3EC;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// b 0x824ef3f0
	goto loc_824EF3F0;
loc_824EF3EC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824EF3F0:
	// lwz r11,72(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// stw r10,132(r27)
	PPC_STORE_U32(r27.u32 + 132, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef58c
	if (cr6.eq) goto loc_824EF58C;
	// mr r23,r11
	r23.u64 = r11.u64;
loc_824EF404:
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// cmplwi cr6,r28,9
	cr6.compare<uint32_t>(r28.u32, 9, xer);
	// blt cr6,0x824ef58c
	if (cr6.lt) goto loc_824EF58C;
	// lwz r4,64(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 64);
	// addi r30,r27,64
	r30.s64 = r27.s64 + 64;
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef42c
	if (cr6.eq) goto loc_824EF42C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb108
	ctx.lr = 0x824EF42C;
	sub_824EB108(ctx, base);
loc_824EF42C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef458
	if (cr6.eq) goto loc_824EF458;
	// stw r31,128(r11)
	PPC_STORE_U32(r11.u32 + 128, r31.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// bne cr6,0x824ef460
	if (!cr6.eq) goto loc_824EF460;
	// b 0x824ef45c
	goto loc_824EF45C;
loc_824EF458:
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
loc_824EF45C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
loc_824EF460:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// bl 0x8218f5b0
	ctx.lr = 0x824EF474;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x824ef488
	if (!cr6.eq) goto loc_824EF488;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EF484;
	sub_824ECCE8(ctx, base);
	// b 0x824ef584
	goto loc_824EF584;
loc_824EF488:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef4c0
	if (cr6.eq) goto loc_824EF4C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eae68
	ctx.lr = 0x824EF4A0;
	sub_824EAE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef4c0
	if (cr6.eq) goto loc_824EF4C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EF4BC;
	sub_824EEC28(ctx, base);
	// b 0x824ef584
	goto loc_824EF584;
loc_824EF4C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x824EF4C8;
	sub_82618698(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824eca00
	ctx.lr = 0x824EF4D8;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef548
	if (cr6.eq) goto loc_824EF548;
	// bl 0x82530b28
	ctx.lr = 0x824EF4EC;
	sub_82530B28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EF4F4;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ef504
	if (cr6.lt) goto loc_824EF504;
	// li r11,0
	r11.s64 = 0;
loc_824EF504:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef548
	if (!cr6.eq) goto loc_824EF548;
	// bl 0x825303e8
	ctx.lr = 0x824EF518;
	sub_825303E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef53c
	if (!cr6.eq) goto loc_824EF53C;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825303f8
	ctx.lr = 0x824EF530;
	sub_825303F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef584
	if (cr6.eq) goto loc_824EF584;
loc_824EF53C:
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x824ef54c
	goto loc_824EF54C;
loc_824EF548:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_824EF54C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82532508
	ctx.lr = 0x824EF558;
	sub_82532508(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r27,112
	ctx.r4.s64 = r27.s64 + 112;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb858
	ctx.lr = 0x824EF578;
	sub_824EB858(ctx, base);
	// add r29,r31,r29
	r29.u64 = r31.u64 + r29.u64;
	// subf r28,r31,r28
	r28.s64 = r28.s64 - r31.s64;
	// add r25,r31,r25
	r25.u64 = r31.u64 + r25.u64;
loc_824EF584:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// bne cr6,0x824ef404
	if (!cr6.eq) goto loc_824EF404;
loc_824EF58C:
	// addi r31,r27,112
	r31.s64 = r27.s64 + 112;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r27,76
	ctx.r5.s64 = r27.s64 + 76;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824ed588
	ctx.lr = 0x824EF5A8;
	sub_824ED588(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r30,r11,r25
	r30.u64 = r11.u64 + r25.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// subf r28,r11,r28
	r28.s64 = r28.s64 - r11.s64;
	// bl 0x82533e98
	ctx.lr = 0x824EF5C8;
	sub_82533E98(ctx, base);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r27,88
	ctx.r5.s64 = r27.s64 + 88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824ed588
	ctx.lr = 0x824EF5E0;
	sub_824ED588(ctx, base);
	// add. r25,r3,r30
	r25.u64 = ctx.r3.u64 + r30.u64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// subf r28,r3,r28
	r28.s64 = r28.s64 - ctx.r3.s64;
	// beq 0x824ef604
	if (cr0.eq) goto loc_824EF604;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r25,r25,3
	r25.s64 = r25.s64 + 3;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r20)
	PPC_STORE_U32(r20.u32 + 4, ctx.r10.u32);
loc_824EF604:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bne cr6,0x824ef384
	if (!cr6.eq) goto loc_824EF384;
loc_824EF60C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EF614;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824EF620"))) PPC_WEAK_FUNC(sub_824EF620);
PPC_FUNC_IMPL(__imp__sub_824EF620) {
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
	ctx.lr = 0x824EF628;
	// stwu r1,-2304(r1)
	ea = -2304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef64c
	if (!cr6.eq) goto loc_824EF64C;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef8b4
	if (cr6.eq) goto loc_824EF8B4;
loc_824EF64C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x824EF654;
	sub_824E6310(ctx, base);
	// li r7,1024
	ctx.r7.s64 = 1024;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef2a8
	ctx.lr = 0x824EF66C;
	sub_824EF2A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ef8b4
	if (cr6.eq) goto loc_824EF8B4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r25,0
	r25.s64 = 0;
	// li r23,1
	r23.s64 = 1;
	// addi r24,r11,26944
	r24.s64 = r11.s64 + 26944;
loc_824EF688:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r29,r1,160
	r29.s64 = ctx.r1.s64 + 160;
	// bl 0x82533ef0
	ctx.lr = 0x824EF694;
	sub_82533EF0(ctx, base);
	// lbz r11,1336(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1336);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// subf r27,r26,r31
	r27.s64 = r31.s64 - r26.s64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef74c
	if (cr6.eq) goto loc_824EF74C;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r31,r1,160
	r31.s64 = ctx.r1.s64 + 160;
	// bl 0x82533f20
	ctx.lr = 0x824EF6B8;
	sub_82533F20(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82533fc0
	ctx.lr = 0x824EF6C4;
	sub_82533FC0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1021
	ctx.r4.s64 = 1021;
	// addi r3,r1,1187
	ctx.r3.s64 = ctx.r1.s64 + 1187;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,1024
	ctx.r7.s64 = 1024;
	// bl 0x821d2af8
	ctx.lr = 0x824EF6DC;
	sub_821D2AF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ef70c
	if (cr6.eq) goto loc_824EF70C;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// bge cr6,0x824ef70c
	if (!cr6.lt) goto loc_824EF70C;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82533f58
	ctx.lr = 0x824EF6F8;
	sub_82533F58(ctx, base);
	// ori r5,r3,1
	ctx.r5.u64 = ctx.r3.u64 | 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,1184
	ctx.r3.s64 = ctx.r1.s64 + 1184;
	// bl 0x82533e98
	ctx.lr = 0x824EF708;
	sub_82533E98(ctx, base);
	// addi r31,r1,1184
	r31.s64 = ctx.r1.s64 + 1184;
loc_824EF70C:
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824ef74c
	if (cr6.eq) goto loc_824EF74C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533f88
	ctx.lr = 0x824EF720;
	sub_82533F88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef74c
	if (cr6.eq) goto loc_824EF74C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EF734;
	sub_82533EF0(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,1184
	ctx.r10.s64 = ctx.r1.s64 + 1184;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 + ctx.r10.u64;
	// add r4,r26,r11
	ctx.r4.u64 = r26.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EF74C;
	sub_8244D5C0(ctx, base);
loc_824EF74C:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ea9d0
	ctx.lr = 0x824EF760;
	sub_824EA9D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824ef890
	if (cr6.eq) goto loc_824EF890;
	// addi r28,r30,1292
	r28.s64 = r30.s64 + 1292;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF778;
	sub_821C8FE0(ctx, base);
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824edcc0
	ctx.lr = 0x824EF790;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EF798;
	sub_824E6310(ctx, base);
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r25,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r25.u32);
	// beq cr6,0x824ef888
	if (cr6.eq) goto loc_824EF888;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef888
	if (cr6.eq) goto loc_824EF888;
	// lwz r29,64(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ef888
	if (cr6.eq) goto loc_824EF888;
loc_824EF7C4:
	// lbz r11,144(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef7e8
	if (cr6.eq) goto loc_824EF7E8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EF7E4;
	sub_824EEC28(ctx, base);
	// b 0x824ef87c
	goto loc_824EF87C;
loc_824EF7E8:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,168
	ctx.r4.s64 = 168;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EF808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ef874
	if (cr6.eq) goto loc_824EF874;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618698
	ctx.lr = 0x824EF81C;
	sub_82618698(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EF828;
	sub_82656BF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EF83C;
	sub_825301E0(ctx, base);
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// stw r23,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r23.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r25,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r25.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF854;
	sub_821C8FE0(ctx, base);
	// addi r4,r30,156
	ctx.r4.s64 = r30.s64 + 156;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824eb708
	ctx.lr = 0x824EF868;
	sub_824EB708(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824EF870;
	sub_821C9030(ctx, base);
	// b 0x824ef87c
	goto loc_824EF87C;
loc_824EF874:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EF87C;
	sub_824ECCE8(ctx, base);
loc_824EF87C:
	// lwz r29,128(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824ef7c4
	if (!cr6.eq) goto loc_824EF7C4;
loc_824EF888:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EF890;
	sub_821C9030(ctx, base);
loc_824EF890:
	// li r7,1024
	ctx.r7.s64 = 1024;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef2a8
	ctx.lr = 0x824EF8A8;
	sub_824EF2A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ef688
	if (!cr6.eq) goto loc_824EF688;
loc_824EF8B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,2304
	ctx.r1.s64 = ctx.r1.s64 + 2304;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EF8C0"))) PPC_WEAK_FUNC(sub_824EF8C0);
PPC_FUNC_IMPL(__imp__sub_824EF8C0) {
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
	ctx.lr = 0x824EF8C8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF8E4;
	sub_821C8FE0(ctx, base);
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef984
	if (!cr6.eq) goto loc_824EF984;
	// lwz r28,92(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r30,r31,84
	r30.s64 = r31.s64 + 84;
	// addi r4,r28,1
	ctx.r4.s64 = r28.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb3c8
	ctx.lr = 0x824EF908;
	sub_824EB3C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r31,156
	ctx.r4.s64 = r31.s64 + 156;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// srw r9,r28,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 >> (r11.u8 & 0x3F));
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// and r6,r8,r28
	ctx.r6.u64 = ctx.r8.u64 & r28.u64;
	// mulli r11,r6,148
	r11.s64 = ctx.r6.s64 * 148;
	// lwzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,144(r3)
	PPC_STORE_U8(ctx.r3.u32 + 144, ctx.r10.u8);
	// bl 0x825303a8
	ctx.lr = 0x824EF950;
	sub_825303A8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// srw r8,r28,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 >> (r11.u8 & 0x3F));
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r5,r7,r28
	ctx.r5.u64 = ctx.r7.u64 & r28.u64;
	// mulli r10,r5,148
	ctx.r10.s64 = ctx.r5.s64 * 148;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// b 0x824ef99c
	goto loc_824EF99C;
loc_824EF984:
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// extsw r29,r4
	r29.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef99c
	if (cr6.eq) goto loc_824EF99C;
	// bl 0x824eb108
	ctx.lr = 0x824EF99C;
	sub_824EB108(ctx, base);
loc_824EF99C:
	// lis r11,23772
	r11.s64 = 1557921792;
	// lwz r9,168(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r10,172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ori r8,r11,64167
	ctx.r8.u64 = r11.u64 | 64167;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// mulld r11,r9,r8
	r11.s64 = ctx.r9.s64 * ctx.r8.s64;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r31,168
	r11.s64 = r31.s64 + 168;
	// rldicl r6,r30,32,32
	ctx.r6.u64 = __builtin_rotateleft64(r30.u64, 32) & 0xFFFFFFFF;
	// stw r30,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r30.u32);
	// stw r6,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r6.u32);
	// bl 0x824eab10
	ctx.lr = 0x824EF9D0;
	sub_824EAB10(ctx, base);
	// rlwinm r5,r30,16,1,15
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0x7FFF0000;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// or r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 | ctx.r5.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825330f0
	ctx.lr = 0x824EF9E8;
	sub_825330F0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824efa44
	if (cr6.eq) goto loc_824EFA44;
	// addi r30,r31,72
	r30.s64 = r31.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824edcc0
	ctx.lr = 0x824EFA0C;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e6310
	ctx.lr = 0x824EFA14;
	sub_824E6310(ctx, base);
	// lwz r28,120(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r11,0
	r11.s64 = 0;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// bne cr6,0x824efa70
	if (!cr6.eq) goto loc_824EFA70;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edd60
	ctx.lr = 0x824EFA38;
	sub_824EDD60(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824efa70
	if (!cr6.eq) goto loc_824EFA70;
loc_824EFA44:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ede48
	ctx.lr = 0x824EFA58;
	sub_824EDE48(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r29,0
	r29.s64 = 0;
	// bl 0x821c9030
	ctx.lr = 0x824EFA64;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_824EFA70:
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r28,64
	r30.s64 = r28.s64 + 64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stwx r29,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r29.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eac30
	ctx.lr = 0x824EFA90;
	sub_824EAC30(ctx, base);
	// mulli r11,r26,68
	r11.s64 = r26.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,196
	ctx.r4.s64 = r11.s64 + 196;
	// bl 0x82530720
	ctx.lr = 0x824EFAA4;
	sub_82530720(ctx, base);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r30,64(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// bl 0x824eb1c8
	ctx.lr = 0x824EFAC4;
	sub_824EB1C8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
loc_824EFACC:
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// beq cr6,0x824efaf4
	if (cr6.eq) goto loc_824EFAF4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618698
	ctx.lr = 0x824EFADC;
	sub_82618698(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bne cr6,0x824efaf4
	if (!cr6.eq) goto loc_824EFAF4;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EFAF4;
	sub_824EEC28(ctx, base);
loc_824EFAF4:
	// ld r11,88(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x824eb1c8
	ctx.lr = 0x824EFB08;
	sub_824EB1C8(ctx, base);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824efacc
	if (!cr6.eq) goto loc_824EFACC;
loc_824EFB14:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EFB1C;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824EFB28"))) PPC_WEAK_FUNC(sub_824EFB28);
PPC_FUNC_IMPL(__imp__sub_824EFB28) {
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
	ctx.lr = 0x824EFB30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,27012
	ctx.r10.s64 = r11.s64 + 27012;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// bl 0x824eeea0
	ctx.lr = 0x824EFB48;
	sub_824EEEA0(ctx, base);
	// addi r3,r29,1292
	ctx.r3.s64 = r29.s64 + 1292;
	// bl 0x82130000
	ctx.lr = 0x824EFB50;
	sub_82130000(ctx, base);
	// addi r11,r29,1272
	r11.s64 = r29.s64 + 1272;
	// li r28,15
	r28.s64 = 15;
	// addi r30,r11,40
	r30.s64 = r11.s64 + 40;
loc_824EFB5C:
	// addi r30,r30,-68
	r30.s64 = r30.s64 + -68;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824efb90
	if (cr6.eq) goto loc_824EFB90;
loc_824EFB70:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824efb84
	if (cr6.eq) goto loc_824EFB84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EFB84;
	sub_824EB248(ctx, base);
loc_824EFB84:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824efb70
	if (!cr6.eq) goto loc_824EFB70;
loc_824EFB90:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r30,-8
	r31.s64 = r30.s64 + -8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824efbc0
	if (cr6.eq) goto loc_824EFBC0;
loc_824EFBA0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824efbb4
	if (cr6.eq) goto loc_824EFBB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb048
	ctx.lr = 0x824EFBB4;
	sub_824EB048(ctx, base);
loc_824EFBB4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824efba0
	if (!cr6.eq) goto loc_824EFBA0;
loc_824EFBC0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x824efb5c
	if (!cr0.lt) goto loc_824EFB5C;
	// addi r3,r29,156
	ctx.r3.s64 = r29.s64 + 156;
	// bl 0x824fecd0
	ctx.lr = 0x824EFBD0;
	sub_824FECD0(ctx, base);
	// addi r3,r29,124
	ctx.r3.s64 = r29.s64 + 124;
	// bl 0x82130000
	ctx.lr = 0x824EFBD8;
	sub_82130000(ctx, base);
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// bl 0x824ebd48
	ctx.lr = 0x824EFBE0;
	sub_824EBD48(ctx, base);
	// addi r3,r29,60
	ctx.r3.s64 = r29.s64 + 60;
	// bl 0x824ebda0
	ctx.lr = 0x824EFBE8;
	sub_824EBDA0(ctx, base);
	// addi r3,r29,48
	ctx.r3.s64 = r29.s64 + 48;
	// bl 0x824ebda0
	ctx.lr = 0x824EFBF0;
	sub_824EBDA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EFBF8"))) PPC_WEAK_FUNC(sub_824EFBF8);
PPC_FUNC_IMPL(__imp__sub_824EFBF8) {
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
	ctx.lr = 0x824EFC00;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r30,1292
	ctx.r4.s64 = r30.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EFC28;
	sub_821C8FE0(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r31,r24
	r31.u64 = r24.u64;
	// beq cr6,0x824efc48
	if (cr6.eq) goto loc_824EFC48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824EFC44;
	sub_821CE080(ctx, base);
	// stw r24,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r24.u32);
loc_824EFC48:
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// bgt cr6,0x824efd20
	if (cr6.gt) goto loc_824EFD20;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824edf68
	ctx.lr = 0x824EFC60;
	sub_824EDF68(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824efc88
	if (!cr6.eq) goto loc_824EFC88;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef8c0
	ctx.lr = 0x824EFC7C;
	sub_824EF8C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824efd20
	if (cr6.eq) goto loc_824EFD20;
loc_824EFC88:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533190
	ctx.lr = 0x824EFCA0;
	sub_82533190(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824efce0
	if (!cr6.eq) goto loc_824EFCE0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824efd20
	if (cr6.eq) goto loc_824EFD20;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efd20
	if (!cr6.eq) goto loc_824EFD20;
	// li r11,1
	r11.s64 = 1;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EFCD8;
	sub_824EEC28(ctx, base);
	// mr r31,r24
	r31.u64 = r24.u64;
	// b 0x824efd20
	goto loc_824EFD20;
loc_824EFCE0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efd10
	if (cr6.eq) goto loc_824EFD10;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efcfc
	if (!cr6.eq) goto loc_824EFCFC;
	// stw r27,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r27.u32);
	// b 0x824efd10
	goto loc_824EFD10;
loc_824EFCFC:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFD0C;
	sub_821CE0A0(ctx, base);
	// stw r24,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r24.u32);
loc_824EFD10:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r24,1
	r24.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EFD20:
	// clrlwi r30,r24,24
	r30.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824efd54
	if (!cr6.eq) goto loc_824EFD54;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efd4c
	if (cr6.eq) goto loc_824EFD4C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFD44;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
loc_824EFD4C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824efd74
	if (cr6.eq) goto loc_824EFD74;
loc_824EFD54:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EFD5C;
	sub_82656BF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EFD68;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824EFD74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	r31.s64 = -1;
	// bl 0x821c9030
	ctx.lr = 0x824EFD80;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824EFD8C"))) PPC_WEAK_FUNC(sub_824EFD8C);
PPC_FUNC_IMPL(__imp__sub_824EFD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EFD90"))) PPC_WEAK_FUNC(sub_824EFD90);
PPC_FUNC_IMPL(__imp__sub_824EFD90) {
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
	ctx.lr = 0x824EFD98;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r30,1292
	ctx.r4.s64 = r30.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EFDBC;
	sub_821C8FE0(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r31,r25
	r31.u64 = r25.u64;
	// beq cr6,0x824efddc
	if (cr6.eq) goto loc_824EFDDC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824EFDD8;
	sub_821CE080(ctx, base);
	// stw r25,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r25.u32);
loc_824EFDDC:
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// bgt cr6,0x824efea4
	if (cr6.gt) goto loc_824EFEA4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824edf68
	ctx.lr = 0x824EFDF4;
	sub_824EDF68(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824efe64
	if (!cr6.eq) goto loc_824EFE64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef8c0
	ctx.lr = 0x824EFE10;
	sub_824EF8C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824efea4
	if (cr6.eq) goto loc_824EFEA4;
	// clrlwi r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// bl 0x825333c0
	ctx.lr = 0x824EFE2C;
	sub_825333C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824efe64
	if (!cr6.eq) goto loc_824EFE64;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efea4
	if (!cr6.eq) goto loc_824EFEA4;
	// li r11,1
	r11.s64 = 1;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EFE5C;
	sub_824EEC28(ctx, base);
	// mr r31,r25
	r31.u64 = r25.u64;
	// b 0x824efea4
	goto loc_824EFEA4;
loc_824EFE64:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efe94
	if (cr6.eq) goto loc_824EFE94;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efe80
	if (!cr6.eq) goto loc_824EFE80;
	// stw r27,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r27.u32);
	// b 0x824efe94
	goto loc_824EFE94;
loc_824EFE80:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFE90;
	sub_821CE0A0(ctx, base);
	// stw r25,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r25.u32);
loc_824EFE94:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r25,1
	r25.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EFEA4:
	// clrlwi r30,r25,24
	r30.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824efed8
	if (!cr6.eq) goto loc_824EFED8;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efed0
	if (cr6.eq) goto loc_824EFED0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFEC8;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
loc_824EFED0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824efef8
	if (cr6.eq) goto loc_824EFEF8;
loc_824EFED8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EFEE0;
	sub_82656BF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EFEEC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_824EFEF8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	r31.s64 = -1;
	// bl 0x821c9030
	ctx.lr = 0x824EFF04;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824EFF10"))) PPC_WEAK_FUNC(sub_824EFF10);
PPC_FUNC_IMPL(__imp__sub_824EFF10) {
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
	ctx.lr = 0x824EFF18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,1336(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1336);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f001c
	if (cr6.eq) goto loc_824F001C;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824effd4
	if (cr6.eq) goto loc_824EFFD4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lwz r9,1284(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1284);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x824effc4
	if (!cr6.eq) goto loc_824EFFC4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,30476(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30476);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eff74
	if (cr6.eq) goto loc_824EFF74;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// stw r11,30440(r9)
	PPC_STORE_U32(ctx.r9.u32 + 30440, r11.u32);
loc_824EFF74:
	// stw r30,30476(r10)
	PPC_STORE_U32(ctx.r10.u32 + 30476, r30.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee7f0
	ctx.lr = 0x824EFF84;
	sub_824EE7F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eff9c
	if (cr6.eq) goto loc_824EFF9C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ef620
	ctx.lr = 0x824EFF9C;
	sub_824EF620(ctx, base);
loc_824EFF9C:
	// addi r29,r31,184
	r29.s64 = r31.s64 + 184;
	// li r31,16
	r31.s64 = 16;
loc_824EFFA4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb7a0
	ctx.lr = 0x824EFFB0;
	sub_824EB7A0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bne 0x824effa4
	if (!cr0.eq) goto loc_824EFFA4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824EFFC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee908
	ctx.lr = 0x824EFFCC;
	sub_824EE908(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824EFFD4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee7f0
	ctx.lr = 0x824EFFE0;
	sub_824EE7F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee908
	ctx.lr = 0x824EFFE8;
	sub_824EE908(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ef620
	ctx.lr = 0x824EFFF4;
	sub_824EF620(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee908
	ctx.lr = 0x824EFFFC;
	sub_824EE908(ctx, base);
	// addi r29,r31,184
	r29.s64 = r31.s64 + 184;
	// li r31,16
	r31.s64 = 16;
loc_824F0004:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb7a0
	ctx.lr = 0x824F0010;
	sub_824EB7A0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bne 0x824f0004
	if (!cr0.eq) goto loc_824F0004;
loc_824F001C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F0024"))) PPC_WEAK_FUNC(sub_824F0024);
PPC_FUNC_IMPL(__imp__sub_824F0024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0028"))) PPC_WEAK_FUNC(sub_824F0028);
PPC_FUNC_IMPL(__imp__sub_824F0028) {
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
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r8,r11,64
	ctx.r8.u64 = r11.u64 | 64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r8,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r8.u8);
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// bl 0x821c9108
	ctx.lr = 0x824F0068;
	sub_821C9108(ctx, base);
	// lbz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// rlwinm r5,r6,0,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824f00a0
	if (!cr6.eq) goto loc_824F00A0;
loc_824F0078:
	// bl 0x821c9788
	ctx.lr = 0x824F007C;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eff10
	ctx.lr = 0x824F0088;
	sub_824EFF10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x824F0090;
	sub_821C91B8(ctx, base);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f0078
	if (cr6.eq) goto loc_824F0078;
loc_824F00A0:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// bl 0x821c9108
	ctx.lr = 0x824F00B8;
	sub_821C9108(ctx, base);
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

__attribute__((alias("__imp__sub_824F00D0"))) PPC_WEAK_FUNC(sub_824F00D0);
PPC_FUNC_IMPL(__imp__sub_824F00D0) {
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
	// bl 0x824efb28
	ctx.lr = 0x824F00F0;
	sub_824EFB28(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f0108
	if (cr6.eq) goto loc_824F0108;
	// bl 0x82130588
	ctx.lr = 0x824F0104;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824F0108:
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

__attribute__((alias("__imp__sub_824F0120"))) PPC_WEAK_FUNC(sub_824F0120);
PPC_FUNC_IMPL(__imp__sub_824F0120) {
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
	ctx.lr = 0x824F0128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f01cc
	if (!cr6.eq) goto loc_824F01CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x824F0150;
	sub_821C9060(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// beq cr6,0x824f01cc
	if (cr6.eq) goto loc_824F01CC;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// lis r3,-32177
	ctx.r3.s64 = -2108751872;
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// addi r7,r10,27040
	ctx.r7.s64 = ctx.r10.s64 + 27040;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,40
	ctx.r3.s64 = ctx.r3.s64 + 40;
	// bl 0x821c9308
	ctx.lr = 0x824F0194;
	sub_821C9308(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// beq cr6,0x824f01b4
	if (cr6.eq) goto loc_824F01B4;
	// bl 0x821c90c0
	ctx.lr = 0x824F01A8;
	sub_821C90C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824F01B4:
	// bl 0x821c9158
	ctx.lr = 0x824F01B8;
	sub_821C9158(ctx, base);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
loc_824F01CC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F01D8"))) PPC_WEAK_FUNC(sub_824F01D8);
PPC_FUNC_IMPL(__imp__sub_824F01D8) {
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
	ctx.lr = 0x824F01E0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lbz r11,1336(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1336);
	// li r28,0
	r28.s64 = 0;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824f047c
	if (!cr6.eq) goto loc_824F047C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F0220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x824fb3b0
	ctx.lr = 0x824F0224;
	sub_824FB3B0(ctx, base);
	// stw r31,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f0240
	if (cr6.eq) goto loc_824F0240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f88f8
	ctx.lr = 0x824F0238;
	sub_824F88F8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// b 0x824f0244
	goto loc_824F0244;
loc_824F0240:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824F0244:
	// sth r11,1328(r29)
	PPC_STORE_U16(r29.u32 + 1328, r11.u16);
	// addi r27,r29,20
	r27.s64 = r29.s64 + 20;
	// stw r24,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r24.u32);
	// stw r28,1332(r29)
	PPC_STORE_U32(r29.u32 + 1332, r28.u32);
	// lbz r10,1336(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 1336);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stb r9,1336(r29)
	PPC_STORE_U8(r29.u32 + 1336, ctx.r9.u8);
	// stw r28,1324(r29)
	PPC_STORE_U32(r29.u32 + 1324, r28.u32);
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824f0278
	if (!cr6.eq) goto loc_824F0278;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_824F0278:
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// addi r30,r29,84
	r30.s64 = r29.s64 + 84;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f0290
	if (!cr6.eq) goto loc_824F0290;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_824F0290:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ed930
	ctx.lr = 0x824F029C;
	sub_824ED930(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f0474
	if (cr6.eq) goto loc_824F0474;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb3c8
	ctx.lr = 0x824F02B4;
	sub_824EB3C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f0474
	if (cr6.eq) goto loc_824F0474;
	// mr r31,r28
	r31.u64 = r28.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x824f038c
	if (!cr6.gt) goto loc_824F038C;
	// addi r25,r29,156
	r25.s64 = r29.s64 + 156;
loc_824F02D0:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// srw r8,r31,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 & r31.u64;
	// mulli r10,r3,148
	ctx.r10.s64 = ctx.r3.s64 * 148;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,144(r3)
	PPC_STORE_U8(ctx.r3.u32 + 144, ctx.r10.u8);
	// bl 0x825303a8
	ctx.lr = 0x824F030C;
	sub_825303A8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f0474
	if (cr6.eq) goto loc_824F0474;
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r4,r29,48
	ctx.r4.s64 = r29.s64 + 48;
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// srw r8,r31,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// lwz r7,24(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 & r31.u64;
	// mulli r10,r3,136
	ctx.r10.s64 = ctx.r3.s64 * 136;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824eacc8
	ctx.lr = 0x824F034C;
	sub_824EACC8(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r4,r29,112
	ctx.r4.s64 = r29.s64 + 112;
	// srw r8,r31,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r11,r7,r31
	r11.u64 = ctx.r7.u64 & r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mulli r10,r11,148
	ctx.r10.s64 = r11.s64 * 148;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x824eac30
	ctx.lr = 0x824F0380;
	sub_824EAC30(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// blt cr6,0x824f02d0
	if (cr6.lt) goto loc_824F02D0;
loc_824F038C:
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r29,188
	r11.s64 = r29.s64 + 188;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r31,1
	r31.s64 = 1;
loc_824F039C:
	// lbz r8,60(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 60);
	// addi r7,r10,-2
	ctx.r7.s64 = ctx.r10.s64 + -2;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// clrlwi r5,r8,25
	ctx.r5.u64 = ctx.r8.u32 & 0x7F;
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// stw r6,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r6.u32);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r31,52(r11)
	PPC_STORE_U32(r11.u32 + 52, r31.u32);
	// stw r28,56(r11)
	PPC_STORE_U32(r11.u32 + 56, r28.u32);
	// stb r5,60(r11)
	PPC_STORE_U8(r11.u32 + 60, ctx.r5.u8);
	// stw r28,72(r11)
	PPC_STORE_U32(r11.u32 + 72, r28.u32);
	// stw r28,68(r11)
	PPC_STORE_U32(r11.u32 + 68, r28.u32);
	// stw r31,120(r11)
	PPC_STORE_U32(r11.u32 + 120, r31.u32);
	// stw r28,124(r11)
	PPC_STORE_U32(r11.u32 + 124, r28.u32);
	// lbz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 128);
	// clrlwi r8,r3,25
	ctx.r8.u64 = ctx.r3.u32 & 0x7F;
	// stb r8,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r8.u8);
	// stw r10,132(r11)
	PPC_STORE_U32(r11.u32 + 132, ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r28,140(r11)
	PPC_STORE_U32(r11.u32 + 140, r28.u32);
	// stw r28,136(r11)
	PPC_STORE_U32(r11.u32 + 136, r28.u32);
	// stw r31,188(r11)
	PPC_STORE_U32(r11.u32 + 188, r31.u32);
	// stw r28,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r28.u32);
	// lbz r7,196(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 196);
	// clrlwi r6,r7,25
	ctx.r6.u64 = ctx.r7.u32 & 0x7F;
	// stb r6,196(r11)
	PPC_STORE_U8(r11.u32 + 196, ctx.r6.u8);
	// stw r4,200(r11)
	PPC_STORE_U32(r11.u32 + 200, ctx.r4.u32);
	// stw r28,208(r11)
	PPC_STORE_U32(r11.u32 + 208, r28.u32);
	// stw r28,204(r11)
	PPC_STORE_U32(r11.u32 + 204, r28.u32);
	// stw r31,256(r11)
	PPC_STORE_U32(r11.u32 + 256, r31.u32);
	// stw r28,260(r11)
	PPC_STORE_U32(r11.u32 + 260, r28.u32);
	// lbz r5,264(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 264);
	// clrlwi r4,r5,25
	ctx.r4.u64 = ctx.r5.u32 & 0x7F;
	// stb r4,264(r11)
	PPC_STORE_U8(r11.u32 + 264, ctx.r4.u8);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// bne 0x824f039c
	if (!cr0.eq) goto loc_824F039C;
	// lbz r11,1336(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1336);
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// stb r11,1336(r29)
	PPC_STORE_U8(r29.u32 + 1336, r11.u8);
	// blt cr6,0x824f0488
	if (cr6.lt) goto loc_824F0488;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stb r10,1336(r29)
	PPC_STORE_U8(r29.u32 + 1336, ctx.r10.u8);
	// addi r3,r29,1272
	ctx.r3.s64 = r29.s64 + 1272;
	// bl 0x824f0120
	ctx.lr = 0x824F0468;
	sub_824F0120(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824f0488
	if (!cr6.eq) goto loc_824F0488;
loc_824F0474:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eeea0
	ctx.lr = 0x824F047C;
	sub_824EEEA0(ctx, base);
loc_824F047C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_824F0488:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824F0494"))) PPC_WEAK_FUNC(sub_824F0494);
PPC_FUNC_IMPL(__imp__sub_824F0494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0498"))) PPC_WEAK_FUNC(sub_824F0498);
PPC_FUNC_IMPL(__imp__sub_824F0498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,-1
	r11.s64 = -1;
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F04A4"))) PPC_WEAK_FUNC(sub_824F04A4);
PPC_FUNC_IMPL(__imp__sub_824F04A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F04A8"))) PPC_WEAK_FUNC(sub_824F04A8);
PPC_FUNC_IMPL(__imp__sub_824F04A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpdi cr6,r11,-1
	cr6.compare<int64_t>(r11.s64, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f04bc
	if (!cr6.eq) goto loc_824F04BC;
	// li r11,0
	r11.s64 = 0;
loc_824F04BC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F04C4"))) PPC_WEAK_FUNC(sub_824F04C4);
PPC_FUNC_IMPL(__imp__sub_824F04C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F04C8"))) PPC_WEAK_FUNC(sub_824F04C8);
PPC_FUNC_IMPL(__imp__sub_824F04C8) {
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
	ctx.lr = 0x824F04D0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82618750
	ctx.lr = 0x824F04EC;
	sub_82618750(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826185e0
	ctx.lr = 0x824F04FC;
	sub_826185E0(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618c90
	ctx.lr = 0x824F050C;
	sub_82618C90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f0544
	if (cr6.eq) goto loc_824F0544;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f053c
	if (cr6.eq) goto loc_824F053C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186b0
	ctx.lr = 0x824F052C;
	sub_826186B0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_824F053C:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_824F0544:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F0550"))) PPC_WEAK_FUNC(sub_824F0550);
PPC_FUNC_IMPL(__imp__sub_824F0550) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// ld r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpld cr6,r11,r10
	cr6.compare<uint64_t>(r11.u64, ctx.r10.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f0568
	if (cr6.eq) goto loc_824F0568;
	// li r11,0
	r11.s64 = 0;
loc_824F0568:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0570"))) PPC_WEAK_FUNC(sub_824F0570);
PPC_FUNC_IMPL(__imp__sub_824F0570) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// ld r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpld cr6,r11,r10
	cr6.compare<uint64_t>(r11.u64, ctx.r10.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f0588
	if (!cr6.eq) goto loc_824F0588;
	// li r11,0
	r11.s64 = 0;
loc_824F0588:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0590"))) PPC_WEAK_FUNC(sub_824F0590);
PPC_FUNC_IMPL(__imp__sub_824F0590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// ld r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// cmpld cr6,r11,r10
	cr6.compare<uint64_t>(r11.u64, ctx.r10.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824f05a8
	if (cr6.lt) goto loc_824F05A8;
	// li r11,0
	r11.s64 = 0;
loc_824F05A8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F05B0"))) PPC_WEAK_FUNC(sub_824F05B0);
PPC_FUNC_IMPL(__imp__sub_824F05B0) {
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
	ctx.lr = 0x824F05B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,-1
	r11.s64 = -1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// std r11,0(r29)
	PPC_STORE_U64(r29.u32 + 0, r11.u64);
	// bl 0x824e6cd8
	ctx.lr = 0x824F05D4;
	sub_824E6CD8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f06f4
	if (cr6.eq) goto loc_824F06F4;
	// li r5,15
	ctx.r5.s64 = 15;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,97
	ctx.r3.s64 = ctx.r1.s64 + 97;
	// bl 0x823d9890
	ctx.lr = 0x824F05F4;
	sub_823D9890(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7240
	ctx.lr = 0x824F0604;
	sub_824E7240(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f06f4
	if (cr6.eq) goto loc_824F06F4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6148
	ctx.lr = 0x824F0618;
	sub_824E6148(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f06f4
	if (cr6.eq) goto loc_824F06F4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_824F062C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824f062c
	if (!cr6.eq) goto loc_824F062C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c98a8
	ctx.lr = 0x824F0654;
	sub_821C98A8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_824F0660:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824f0660
	if (!cr6.eq) goto loc_824F0660;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c98a8
	ctx.lr = 0x824F0688;
	sub_821C98A8(ctx, base);
	// lbz r8,83(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// clrldi r6,r3,32
	ctx.r6.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lbz r11,84(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// clrldi r7,r31,32
	ctx.r7.u64 = r31.u64 & 0xFFFFFFFF;
	// lbz r4,85(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwimi r5,r4,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r3,r9,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// rldimi r8,r3,8,32
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r3.u64, 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r10,r5,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// xor r3,r8,r7
	ctx.r3.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// rldimi r4,r10,8,32
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// rldicr r11,r3,32,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000;
	// xor r10,r4,r6
	ctx.r10.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// std r9,0(r29)
	PPC_STORE_U64(r29.u32 + 0, ctx.r9.u64);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_824F06F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F0700"))) PPC_WEAK_FUNC(sub_824F0700);
PPC_FUNC_IMPL(__imp__sub_824F0700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,27108
	ctx.r10.s64 = r11.s64 + 27108;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0710"))) PPC_WEAK_FUNC(sub_824F0710);
PPC_FUNC_IMPL(__imp__sub_824F0710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// ori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f081c
	if (cr6.eq) goto loc_824F081C;
	// lwz r4,40(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - r11.s64;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// clrldi r5,r8,32
	ctx.r5.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r8,24
	ctx.r8.s64 = 24;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f13
	ctx.f7.f64 = double(ctx.f13.s64);
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f12
	ctx.f6.f64 = double(ctx.f12.s64);
	// lfs f0,11364(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fcfid f5,f11
	ctx.f5.f64 = double(ctx.f11.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// frsp f2,f7
	ctx.f2.f64 = double(float(ctx.f7.f64));
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f4,f10
	ctx.f4.f64 = double(ctx.f10.s64);
	// li r9,20
	ctx.r9.s64 = 20;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// li r7,28
	ctx.r7.s64 = 28;
	// frsp f1,f6
	ctx.f1.f64 = double(float(ctx.f6.f64));
	// li r6,32
	ctx.r6.s64 = 32;
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// li r11,0
	r11.s64 = 0;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// fmuls f9,f2,f0
	ctx.f9.f64 = double(float(ctx.f2.f64 * f0.f64));
	// frsp f11,f4
	ctx.f11.f64 = double(float(ctx.f4.f64));
	// frsp f3,f8
	ctx.f3.f64 = double(float(ctx.f8.f64));
	// fmuls f8,f1,f0
	ctx.f8.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmuls f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fdivs f5,f9,f11
	ctx.f5.f64 = double(float(ctx.f9.f64 / ctx.f11.f64));
	// fmuls f10,f3,f0
	ctx.f10.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fdivs f4,f8,f11
	ctx.f4.f64 = double(float(ctx.f8.f64 / ctx.f11.f64));
	// fdivs f3,f7,f11
	ctx.f3.f64 = double(float(ctx.f7.f64 / ctx.f11.f64));
	// fadds f1,f5,f13
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f13.f64));
	// fdivs f6,f10,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fadds f0,f4,f13
	f0.f64 = double(float(ctx.f4.f64 + ctx.f13.f64));
	// fctidz f11,f1
	ctx.f11.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// fadds f2,f6,f13
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f13.f64));
	// fadds f13,f3,f13
	ctx.f13.f64 = double(float(ctx.f3.f64 + ctx.f13.f64));
	// fctidz f10,f0
	ctx.f10.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// fctidz f12,f2
	ctx.f12.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f12,r3,r9
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.f12.u32);
	// stfiwx f11,r3,r8
	PPC_STORE_U32(ctx.r3.u32 + ctx.r8.u32, ctx.f11.u32);
	// fctidz f9,f13
	ctx.f9.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f10,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.f10.u32);
	// stfiwx f9,r3,r6
	PPC_STORE_U32(ctx.r3.u32 + ctx.r6.u32, ctx.f9.u32);
loc_824F081C:
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0824"))) PPC_WEAK_FUNC(sub_824F0824);
PPC_FUNC_IMPL(__imp__sub_824F0824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0828"))) PPC_WEAK_FUNC(sub_824F0828);
PPC_FUNC_IMPL(__imp__sub_824F0828) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// ori r9,r4,1
	ctx.r9.u64 = ctx.r4.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f08bc
	if (cr6.eq) goto loc_824F08BC;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// twllei r11,0
	// lwz r6,44(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mulli r5,r8,1000
	ctx.r5.s64 = ctx.r8.s64 * 1000;
	// lwz r4,48(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// stw r9,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// mulli r10,r7,1000
	ctx.r10.s64 = ctx.r7.s64 * 1000;
	// mulli r9,r6,1000
	ctx.r9.s64 = ctx.r6.s64 * 1000;
	// mulli r8,r4,1000
	ctx.r8.s64 = ctx.r4.s64 * 1000;
	// divwu r7,r5,r11
	ctx.r7.u32 = ctx.r5.u32 / r11.u32;
	// divwu r6,r10,r11
	ctx.r6.u32 = ctx.r10.u32 / r11.u32;
	// divwu r5,r9,r11
	ctx.r5.u32 = ctx.r9.u32 / r11.u32;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// divwu r4,r8,r11
	ctx.r4.u32 = ctx.r8.u32 / r11.u32;
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// twllei r11,0
	// stw r5,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r5.u32);
	// twllei r11,0
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// twllei r11,0
	// blr 
	return;
loc_824F08BC:
	// stw r9,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F08C4"))) PPC_WEAK_FUNC(sub_824F08C4);
PPC_FUNC_IMPL(__imp__sub_824F08C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F08C8"))) PPC_WEAK_FUNC(sub_824F08C8);
PPC_FUNC_IMPL(__imp__sub_824F08C8) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f08f8
	if (cr6.eq) goto loc_824F08F8;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8252fbd8
	ctx.lr = 0x824F08F4;
	sub_8252FBD8(ctx, base);
	// b 0x824f08fc
	goto loc_824F08FC;
loc_824F08F8:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_824F08FC:
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F0928"))) PPC_WEAK_FUNC(sub_824F0928);
PPC_FUNC_IMPL(__imp__sub_824F0928) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f0958
	if (cr6.eq) goto loc_824F0958;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8252fbd8
	ctx.lr = 0x824F0954;
	sub_8252FBD8(ctx, base);
	// b 0x824f095c
	goto loc_824F095C;
loc_824F0958:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_824F095C:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F0988"))) PPC_WEAK_FUNC(sub_824F0988);
PPC_FUNC_IMPL(__imp__sub_824F0988) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,27108
	ctx.r9.s64 = r11.s64 + 27108;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824f09bc
	if (cr6.eq) goto loc_824F09BC;
	// bl 0x82130588
	ctx.lr = 0x824F09B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824F09BC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F09D0"))) PPC_WEAK_FUNC(sub_824F09D0);
PPC_FUNC_IMPL(__imp__sub_824F09D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,27132
	ctx.r9.s64 = ctx.r10.s64 + 27132;
	// li r8,1000
	ctx.r8.s64 = 1000;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0A1C"))) PPC_WEAK_FUNC(sub_824F0A1C);
PPC_FUNC_IMPL(__imp__sub_824F0A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0A20"))) PPC_WEAK_FUNC(sub_824F0A20);
PPC_FUNC_IMPL(__imp__sub_824F0A20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r8,1536(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 1536);
	// cmpw cr6,r5,r8
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, xer);
	// bge cr6,0x824f0aa4
	if (!cr6.lt) goto loc_824F0AA4;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// ld r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_824F0A48:
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpld cr6,r9,r10
	cr6.compare<uint64_t>(ctx.r9.u64, ctx.r10.u64, xer);
	// bne cr6,0x824f0a64
	if (!cr6.eq) goto loc_824F0A64;
	// ld r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// cmpld cr6,r7,r6
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r6.u64, xer);
	// beq cr6,0x824f0a7c
	if (cr6.eq) goto loc_824F0A7C;
loc_824F0A64:
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// cmpld cr6,r9,r7
	cr6.compare<uint64_t>(ctx.r9.u64, ctx.r7.u64, xer);
	// bne cr6,0x824f0a84
	if (!cr6.eq) goto loc_824F0A84;
	// ld r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// cmpld cr6,r7,r10
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r10.u64, xer);
	// bne cr6,0x824f0a84
	if (!cr6.eq) goto loc_824F0A84;
loc_824F0A7C:
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x824f0a88
	goto loc_824F0A88;
loc_824F0A84:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824F0A88:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// blt cr6,0x824f0a48
	if (cr6.lt) goto loc_824F0A48;
loc_824F0AA4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0AAC"))) PPC_WEAK_FUNC(sub_824F0AAC);
PPC_FUNC_IMPL(__imp__sub_824F0AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0AB0"))) PPC_WEAK_FUNC(sub_824F0AB0);
PPC_FUNC_IMPL(__imp__sub_824F0AB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,-8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + -8);
	// addi r11,r3,-16
	r11.s64 = ctx.r3.s64 + -16;
	// std r5,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r5.u64);
	// lwz r10,40(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 40);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// std r4,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r4.u64);
	// ble cr6,0x824f0af0
	if (!cr6.gt) goto loc_824F0AF0;
loc_824F0ACC:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r9,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// ld r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// std r8,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r8.u64);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bgt cr6,0x824f0acc
	if (cr6.gt) goto loc_824F0ACC;
loc_824F0AF0:
	// addi r11,r1,32
	r11.s64 = ctx.r1.s64 + 32;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// std r10,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r10.u64);
	// std r9,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r9.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0B08"))) PPC_WEAK_FUNC(sub_824F0B08);
PPC_FUNC_IMPL(__imp__sub_824F0B08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// std r6,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r6.u64);
	// std r7,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r7.u64);
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// ble cr6,0x824f0b70
	if (!cr6.gt) goto loc_824F0B70;
	// lwz r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 56);
loc_824F0B2C:
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x824f0b70
	if (!cr6.gt) goto loc_824F0B70;
	// rlwinm r9,r4,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// add r31,r9,r3
	r31.u64 = ctx.r9.u64 + ctx.r3.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// srawi r11,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r11.s64 = ctx.r6.s32 >> 1;
	// stdx r7,r9,r3
	PPC_STORE_U64(ctx.r9.u32 + ctx.r3.u32, ctx.r7.u64);
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// ld r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// std r10,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r10.u64);
	// bgt cr6,0x824f0b2c
	if (cr6.gt) goto loc_824F0B2C;
loc_824F0B70:
	// addi r10,r1,48
	ctx.r10.s64 = ctx.r1.s64 + 48;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// stdx r8,r11,r3
	PPC_STORE_U64(r11.u32 + ctx.r3.u32, ctx.r8.u64);
	// std r7,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r7.u64);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0B94"))) PPC_WEAK_FUNC(sub_824F0B94);
PPC_FUNC_IMPL(__imp__sub_824F0B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0B98"))) PPC_WEAK_FUNC(sub_824F0B98);
PPC_FUNC_IMPL(__imp__sub_824F0B98) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824F0BA0"))) PPC_WEAK_FUNC(sub_824F0BA0);
PPC_FUNC_IMPL(__imp__sub_824F0BA0) {
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
	ctx.lr = 0x824F0BA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cntlzw r11,r6
	r11.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// lbz r10,2660(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// std r4,0(r31)
	PPC_STORE_U64(r31.u32 + 0, ctx.r4.u64);
	// rlwimi r10,r9,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// stw r5,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r5.u32);
	// stb r10,2660(r31)
	PPC_STORE_U8(r31.u32 + 2660, ctx.r10.u8);
	// beq cr6,0x824f0bf0
	if (cr6.eq) goto loc_824F0BF0;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// b 0x824f0bf8
	goto loc_824F0BF8;
loc_824F0BF0:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e6310
	ctx.lr = 0x824F0BF8;
	sub_824E6310(ctx, base);
loc_824F0BF8:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r9,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r8,2648(r31)
	PPC_STORE_U32(r31.u32 + 2648, ctx.r8.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r7,2652(r31)
	PPC_STORE_U32(r31.u32 + 2652, ctx.r7.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,2656(r31)
	PPC_STORE_U32(r31.u32 + 2656, ctx.r6.u32);
	// stw r11,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r11.u32);
	// stw r11,2112(r31)
	PPC_STORE_U32(r31.u32 + 2112, r11.u32);
	// stw r11,2632(r31)
	PPC_STORE_U32(r31.u32 + 2632, r11.u32);
	// stw r11,2640(r31)
	PPC_STORE_U32(r31.u32 + 2640, r11.u32);
	// stw r11,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, r11.u32);
	// bl 0x824ec120
	ctx.lr = 0x824F0C48;
	sub_824EC120(ctx, base);
	// lbz r5,2660(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// ori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 | 128;
	// stb r4,2660(r31)
	PPC_STORE_U8(r31.u32 + 2660, ctx.r4.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F0C5C"))) PPC_WEAK_FUNC(sub_824F0C5C);
PPC_FUNC_IMPL(__imp__sub_824F0C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0C60"))) PPC_WEAK_FUNC(sub_824F0C60);
PPC_FUNC_IMPL(__imp__sub_824F0C60) {
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
	// lbz r11,2660(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// std r30,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r30.u64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r10,2660(r31)
	PPC_STORE_U8(r31.u32 + 2660, ctx.r10.u8);
	// beq cr6,0x824f0ca4
	if (cr6.eq) goto loc_824F0CA4;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// bl 0x824ebcc8
	ctx.lr = 0x824F0CA0;
	sub_824EBCC8(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_824F0CA4:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e6310
	ctx.lr = 0x824F0CAC;
	sub_824E6310(ctx, base);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r30.u32);
	// stw r30,2112(r31)
	PPC_STORE_U32(r31.u32 + 2112, r30.u32);
	// stw r30,2632(r31)
	PPC_STORE_U32(r31.u32 + 2632, r30.u32);
	// stw r30,2640(r31)
	PPC_STORE_U32(r31.u32 + 2640, r30.u32);
	// stw r30,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, r30.u32);
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

__attribute__((alias("__imp__sub_824F0CE0"))) PPC_WEAK_FUNC(sub_824F0CE0);
PPC_FUNC_IMPL(__imp__sub_824F0CE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,568(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 568);
	// addi r10,r3,56
	ctx.r10.s64 = ctx.r3.s64 + 56;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x824f0d10
	if (!cr6.gt) goto loc_824F0D10;
loc_824F0CF4:
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r8,r4
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f0d14
	if (cr6.eq) goto loc_824F0D14;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824f0cf4
	if (cr6.lt) goto loc_824F0CF4;
loc_824F0D10:
	// li r11,-1
	r11.s64 = -1;
loc_824F0D14:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0D28"))) PPC_WEAK_FUNC(sub_824F0D28);
PPC_FUNC_IMPL(__imp__sub_824F0D28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,2632(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2632);
	// addi r10,r3,2120
	ctx.r10.s64 = ctx.r3.s64 + 2120;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_824F0D40:
	// ld r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// cmpld cr6,r7,r4
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f0d60
	if (cr6.eq) goto loc_824F0D60;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824f0d40
	if (cr6.lt) goto loc_824F0D40;
	// blr 
	return;
loc_824F0D60:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,512(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 512);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r11,512(r10)
	PPC_STORE_U32(ctx.r10.u32 + 512, r11.u32);
	// ldx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r7.u32 + ctx.r10.u32);
	// stdx r6,r8,r10
	PPC_STORE_U64(ctx.r8.u32 + ctx.r10.u32, ctx.r6.u64);
	// lwz r5,2632(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2632);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2644(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2644, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0D9C"))) PPC_WEAK_FUNC(sub_824F0D9C);
PPC_FUNC_IMPL(__imp__sub_824F0D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0DA0"))) PPC_WEAK_FUNC(sub_824F0DA0);
PPC_FUNC_IMPL(__imp__sub_824F0DA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,2632(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2632);
	// addi r10,r3,2120
	ctx.r10.s64 = ctx.r3.s64 + 2120;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x824f0dd0
	if (!cr6.gt) goto loc_824F0DD0;
loc_824F0DB4:
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r8,r4
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f0dd4
	if (cr6.eq) goto loc_824F0DD4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824f0db4
	if (cr6.lt) goto loc_824F0DB4;
loc_824F0DD0:
	// li r11,-1
	r11.s64 = -1;
loc_824F0DD4:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F0DE8"))) PPC_WEAK_FUNC(sub_824F0DE8);
PPC_FUNC_IMPL(__imp__sub_824F0DE8) {
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
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// lbz r10,2660(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// rlwimi r10,r9,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r10,2660(r31)
	PPC_STORE_U8(r31.u32 + 2660, ctx.r10.u8);
	// beq cr6,0x824f0e2c
	if (cr6.eq) goto loc_824F0E2C;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// b 0x824f0e34
	goto loc_824F0E34;
loc_824F0E2C:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e6310
	ctx.lr = 0x824F0E34;
	sub_824E6310(ctx, base);
loc_824F0E34:
	// lbz r10,2660(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// li r11,0
	r11.s64 = 0;
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// stw r11,2640(r31)
	PPC_STORE_U32(r31.u32 + 2640, r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f0e58
	if (cr6.eq) goto loc_824F0E58;
	// stw r11,2632(r31)
	PPC_STORE_U32(r31.u32 + 2632, r11.u32);
	// stw r11,2112(r31)
	PPC_STORE_U32(r31.u32 + 2112, r11.u32);
	// b 0x824f0e6c
	goto loc_824F0E6C;
loc_824F0E58:
	// lwz r11,2632(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2632);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824f0e70
	if (cr6.eq) goto loc_824F0E70;
	// bl 0x821c9788
	ctx.lr = 0x824F0E68;
	sub_821C9788(ctx, base);
	// ori r11,r3,1
	r11.u64 = ctx.r3.u64 | 1;
loc_824F0E6C:
	// stw r11,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, r11.u32);
loc_824F0E70:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F0E84"))) PPC_WEAK_FUNC(sub_824F0E84);
PPC_FUNC_IMPL(__imp__sub_824F0E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F0E88"))) PPC_WEAK_FUNC(sub_824F0E88);
PPC_FUNC_IMPL(__imp__sub_824F0E88) {
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
	ctx.lr = 0x824F0E90;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,2660(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2660);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f1024
	if (cr6.eq) goto loc_824F1024;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x824f0ff8
	if (!cr6.gt) goto loc_824F0FF8;
	// lbz r27,96(r1)
	r27.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// addi r25,r30,56
	r25.s64 = r30.s64 + 56;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// li r26,-1
	r26.s64 = -1;
	// li r23,1
	r23.s64 = 1;
loc_824F0ECC:
	// lwz r9,512(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 512);
	// li r11,0
	r11.s64 = 0;
	// ld r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x824f0fec
	if (!cr6.gt) goto loc_824F0FEC;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_824F0EE4:
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r7,r8
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r8.u64, xer);
	// beq cr6,0x824f0f04
	if (cr6.eq) goto loc_824F0F04;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824f0ee4
	if (cr6.lt) goto loc_824F0EE4;
	// b 0x824f0fec
	goto loc_824F0FEC;
loc_824F0F04:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x824f0fec
	if (cr6.lt) goto loc_824F0FEC;
	// clrlwi r11,r27,26
	r11.u64 = r27.u32 & 0x3F;
	// std r28,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r28.u64);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// addi r31,r30,576
	r31.s64 = r30.s64 + 576;
	// ori r27,r11,128
	r27.u64 = r11.u64 | 128;
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r27,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r27.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f0a20
	ctx.lr = 0x824F0F34;
	sub_824F0A20(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x824f0f7c
	if (!cr6.lt) goto loc_824F0F7C;
	// lwz r11,2112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2112);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x824f0fec
	if (cr6.eq) goto loc_824F0FEC;
	// lwz r11,1536(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1536);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,1536(r31)
	PPC_STORE_U32(r31.u32 + 1536, ctx.r9.u32);
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// clrlwi r6,r7,26
	ctx.r6.u64 = ctx.r7.u32 & 0x3F;
	// std r26,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r26.u64);
	// std r26,8(r11)
	PPC_STORE_U64(r11.u32 + 8, r26.u64);
	// stb r6,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r6.u8);
	// b 0x824f0f90
	goto loc_824F0F90;
loc_824F0F7C:
	// addi r11,r3,24
	r11.s64 = ctx.r3.s64 + 24;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_824F0F90:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f0fec
	if (cr6.eq) goto loc_824F0FEC;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpdi cr6,r10,-1
	cr6.compare<int64_t>(ctx.r10.s64, -1, xer);
	// bne cr6,0x824f0fc0
	if (!cr6.eq) goto loc_824F0FC0;
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// std r28,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r28.u64);
	// rlwimi r10,r23,7,0,25
	ctx.r10.u64 = (__builtin_rotateleft32(r23.u32, 7) & 0xFFFFFFC0) | (ctx.r10.u64 & 0xFFFFFFFF0000003F);
	// std r9,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r9.u64);
	// stb r10,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r10.u8);
	// b 0x824f0fec
	goto loc_824F0FEC;
loc_824F0FC0:
	// cmpld cr6,r28,r10
	cr6.compare<uint64_t>(r28.u64, ctx.r10.u64, xer);
	// bne cr6,0x824f0fd4
	if (!cr6.eq) goto loc_824F0FD4;
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// b 0x824f0fe8
	goto loc_824F0FE8;
loc_824F0FD4:
	// ld r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// cmpld cr6,r28,r10
	cr6.compare<uint64_t>(r28.u64, ctx.r10.u64, xer);
	// bne cr6,0x824f0fec
	if (!cr6.eq) goto loc_824F0FEC;
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
loc_824F0FE8:
	// stb r9,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r9.u8);
loc_824F0FEC:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x824f0ecc
	if (!cr0.eq) goto loc_824F0ECC;
loc_824F0FF8:
	// lwz r11,2640(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2640);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f1024
	if (!cr6.eq) goto loc_824F1024;
	// lwz r11,2112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824f1024
	if (cr6.eq) goto loc_824F1024;
	// bl 0x821c9788
	ctx.lr = 0x824F1014;
	sub_821C9788(ctx, base);
	// lwz r11,2648(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2648);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,2640(r30)
	PPC_STORE_U32(r30.u32 + 2640, ctx.r9.u32);
loc_824F1024:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824F102C"))) PPC_WEAK_FUNC(sub_824F102C);
PPC_FUNC_IMPL(__imp__sub_824F102C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1030"))) PPC_WEAK_FUNC(sub_824F1030);
PPC_FUNC_IMPL(__imp__sub_824F1030) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_824F103C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lbz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// lbz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// clrlwi r5,r8,26
	ctx.r5.u64 = ctx.r8.u32 & 0x3F;
	// lbz r4,72(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// clrlwi r8,r7,26
	ctx.r8.u64 = ctx.r7.u32 & 0x3F;
	// clrlwi r7,r6,26
	ctx.r7.u64 = ctx.r6.u32 & 0x3F;
	// std r10,-16(r11)
	PPC_STORE_U64(r11.u32 + -16, ctx.r10.u64);
	// clrlwi r6,r4,26
	ctx.r6.u64 = ctx.r4.u32 & 0x3F;
	// std r10,-8(r11)
	PPC_STORE_U64(r11.u32 + -8, ctx.r10.u64);
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// std r10,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r10.u64);
	// std r10,16(r11)
	PPC_STORE_U64(r11.u32 + 16, ctx.r10.u64);
	// stb r8,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r8.u8);
	// std r10,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r10.u64);
	// std r10,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r10.u64);
	// stb r7,48(r11)
	PPC_STORE_U8(r11.u32 + 48, ctx.r7.u8);
	// std r10,56(r11)
	PPC_STORE_U64(r11.u32 + 56, ctx.r10.u64);
	// std r10,64(r11)
	PPC_STORE_U64(r11.u32 + 64, ctx.r10.u64);
	// stb r6,72(r11)
	PPC_STORE_U8(r11.u32 + 72, ctx.r6.u8);
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// bne 0x824f103c
	if (!cr0.eq) goto loc_824F103C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,1536(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1536, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F10A4"))) PPC_WEAK_FUNC(sub_824F10A4);
PPC_FUNC_IMPL(__imp__sub_824F10A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F10A8"))) PPC_WEAK_FUNC(sub_824F10A8);
PPC_FUNC_IMPL(__imp__sub_824F10A8) {
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
	ctx.lr = 0x824F10B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// bl 0x82618d38
	ctx.lr = 0x824F10CC;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f1154
	if (cr6.eq) goto loc_824F1154;
	// addi r29,r31,520
	r29.s64 = r31.s64 + 520;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82299788
	ctx.lr = 0x824F10EC;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f1154
	if (cr6.eq) goto loc_824F1154;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r27,1
	r27.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824f113c
	if (!cr6.gt) goto loc_824F113C;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
loc_824F110C:
	// li r5,64
	ctx.r5.s64 = 64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618d38
	ctx.lr = 0x824F111C;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f1148
	if (cr6.eq) goto loc_824F1148;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x824f110c
	if (cr6.lt) goto loc_824F110C;
loc_824F113C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824F1148:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824F1154:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F1160"))) PPC_WEAK_FUNC(sub_824F1160);
PPC_FUNC_IMPL(__imp__sub_824F1160) {
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
	ctx.lr = 0x824F1168;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x82618c90
	ctx.lr = 0x824F1180;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f1208
	if (cr6.eq) goto loc_824F1208;
	// addi r29,r31,520
	r29.s64 = r31.s64 + 520;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82257568
	ctx.lr = 0x824F11A0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f1208
	if (cr6.eq) goto loc_824F1208;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r27,1
	r27.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824f11f0
	if (!cr6.gt) goto loc_824F11F0;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
loc_824F11C0:
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618c90
	ctx.lr = 0x824F11D0;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f11fc
	if (cr6.eq) goto loc_824F11FC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x824f11c0
	if (cr6.lt) goto loc_824F11C0;
loc_824F11F0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824F11FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824F1208:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F1214"))) PPC_WEAK_FUNC(sub_824F1214);
PPC_FUNC_IMPL(__imp__sub_824F1214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1218"))) PPC_WEAK_FUNC(sub_824F1218);
PPC_FUNC_IMPL(__imp__sub_824F1218) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_824F1224:
	// ld r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// addi r11,r9,-16
	r11.s64 = ctx.r9.s64 + -16;
	// lwz r5,-8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// std r8,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r8.u64);
	// std r6,8(r7)
	PPC_STORE_U64(ctx.r7.u32 + 8, ctx.r6.u64);
	// lwz r8,-8(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// cmplw cr6,r8,r5
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, xer);
	// ble cr6,0x824f1274
	if (!cr6.gt) goto loc_824F1274;
loc_824F1250:
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r7,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r7.u64);
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// std r6,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r6.u64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r8,r5
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, xer);
	// bgt cr6,0x824f1250
	if (cr6.gt) goto loc_824F1250;
loc_824F1274:
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// std r7,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r7.u64);
	// bne cr6,0x824f1224
	if (!cr6.eq) goto loc_824F1224;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F1298"))) PPC_WEAK_FUNC(sub_824F1298);
PPC_FUNC_IMPL(__imp__sub_824F1298) {
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
	ctx.lr = 0x824F12A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bge cr6,0x824f130c
	if (!cr6.lt) goto loc_824F130C;
loc_824F12B8:
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r10,-8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x824f12d4
	if (!cr6.gt) goto loc_824F12D4;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_824F12D4:
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r9,r3
	r30.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r29,r10,r3
	r29.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// ldx r9,r9,r3
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r9.u32 + ctx.r3.u32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// stdx r9,r10,r3
	PPC_STORE_U64(ctx.r10.u32 + ctx.r3.u32, ctx.r9.u64);
	// ld r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// std r10,8(r29)
	PPC_STORE_U64(r29.u32 + 8, ctx.r10.u64);
	// blt cr6,0x824f12b8
	if (cr6.lt) goto loc_824F12B8;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
loc_824F130C:
	// bne cr6,0x824f1338
	if (!cr6.eq) goto loc_824F1338;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r4,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r5,r9,r3
	ctx.r5.u64 = ctx.r9.u64 + ctx.r3.u64;
	// addi r4,r10,-16
	ctx.r4.s64 = ctx.r10.s64 + -16;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// ld r11,-16(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + -16);
	// stdx r11,r9,r3
	PPC_STORE_U64(ctx.r9.u32 + ctx.r3.u32, r11.u64);
	// ld r10,-8(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + -8);
	// std r10,8(r5)
	PPC_STORE_U64(ctx.r5.u32 + 8, ctx.r10.u64);
loc_824F1338:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x824f0b08
	ctx.lr = 0x824F1340;
	sub_824F0B08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F1348"))) PPC_WEAK_FUNC(sub_824F1348);
PPC_FUNC_IMPL(__imp__sub_824F1348) {
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
	ctx.lr = 0x824F1350;
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
	ctx.lr = 0x824F1374;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F1380;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F1390;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f13b4
	if (cr6.eq) goto loc_824F13B4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f10a8
	ctx.lr = 0x824F13A4;
	sub_824F10A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f13b8
	if (!cr6.eq) goto loc_824F13B8;
loc_824F13B4:
	// li r30,0
	r30.s64 = 0;
loc_824F13B8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f13f0
	if (cr6.eq) goto loc_824F13F0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f13e8
	if (cr6.eq) goto loc_824F13E8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F13D4;
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
loc_824F13E8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F13F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F13FC"))) PPC_WEAK_FUNC(sub_824F13FC);
PPC_FUNC_IMPL(__imp__sub_824F13FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1400"))) PPC_WEAK_FUNC(sub_824F1400);
PPC_FUNC_IMPL(__imp__sub_824F1400) {
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
	ctx.lr = 0x824F1408;
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
	ctx.lr = 0x824F1438;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F1444;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F1454;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f1484
	if (cr6.eq) goto loc_824F1484;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f1484
	if (!cr6.eq) goto loc_824F1484;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f1160
	ctx.lr = 0x824F1474;
	sub_824F1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f1488
	if (!cr6.eq) goto loc_824F1488;
loc_824F1484:
	// li r31,0
	r31.s64 = 0;
loc_824F1488:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f14b4
	if (cr6.eq) goto loc_824F14B4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f14ac
	if (cr6.eq) goto loc_824F14AC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F14A4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f14b0
	goto loc_824F14B0;
loc_824F14AC:
	// li r11,0
	r11.s64 = 0;
loc_824F14B0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F14B4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f14d8
	if (cr6.eq) goto loc_824F14D8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F14C8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f14dc
	if (cr6.eq) goto loc_824F14DC;
loc_824F14D8:
	// li r11,0
	r11.s64 = 0;
loc_824F14DC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F14E8"))) PPC_WEAK_FUNC(sub_824F14E8);
PPC_FUNC_IMPL(__imp__sub_824F14E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r7,56
	ctx.r10.s64 = ctx.r7.s64 + 56;
	// li r11,0
	r11.s64 = 0;
	// lwz r8,568(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 568);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x824f1530
	if (!cr6.gt) goto loc_824F1530;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_824F1508:
	// ld r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// cmpld cr6,r6,r4
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f1528
	if (cr6.eq) goto loc_824F1528;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824f1508
	if (cr6.lt) goto loc_824F1508;
	// b 0x824f1530
	goto loc_824F1530;
loc_824F1528:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgelr cr6
	if (!cr6.lt) return;
loc_824F1530:
	// lwz r11,568(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 568);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,512(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 512);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r10)
	PPC_STORE_U32(ctx.r10.u32 + 512, r11.u32);
	// stdx r4,r9,r10
	PPC_STORE_U64(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F1558"))) PPC_WEAK_FUNC(sub_824F1558);
PPC_FUNC_IMPL(__imp__sub_824F1558) {
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
	// lwz r10,568(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 568);
	// addi r31,r3,56
	r31.s64 = ctx.r3.s64 + 56;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x824f166c
	if (!cr6.gt) goto loc_824F166C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824F1584:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpld cr6,r9,r4
	cr6.compare<uint64_t>(ctx.r9.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f15a4
	if (cr6.eq) goto loc_824F15A4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x824f1584
	if (cr6.lt) goto loc_824F1584;
	// b 0x824f166c
	goto loc_824F166C;
loc_824F15A4:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824f166c
	if (cr6.lt) goto loc_824F166C;
	// bl 0x824f0d28
	ctx.lr = 0x824F15B0;
	sub_824F0D28(ctx, base);
	// lwz r11,512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 512);
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r11,512(r31)
	PPC_STORE_U32(r31.u32 + 512, r11.u32);
	// ldx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + r31.u32);
	// stdx r8,r10,r31
	PPC_STORE_U64(ctx.r10.u32 + r31.u32, ctx.r8.u64);
	// lwz r7,2112(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2112);
	// addic. r8,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r8.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x824f166c
	if (cr0.lt) goto loc_824F166C;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r6,r3,-584
	xer.ca = ctx.r3.u32 <= 4294966712;
	ctx.r6.s64 = -584 - ctx.r3.s64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r7,r11,584
	ctx.r7.s64 = r11.s64 + 584;
loc_824F15F0:
	// ld r11,-8(r7)
	r11.u64 = PPC_LOAD_U64(ctx.r7.u32 + -8);
	// cmpld cr6,r11,r4
	cr6.compare<uint64_t>(r11.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f1608
	if (cr6.eq) goto loc_824F1608;
	// ld r11,0(r7)
	r11.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// cmpld cr6,r11,r4
	cr6.compare<uint64_t>(r11.u64, ctx.r4.u64, xer);
	// bne cr6,0x824f1660
	if (!cr6.eq) goto loc_824F1660;
loc_824F1608:
	// lwz r11,2112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2112);
	// addi r10,r3,576
	ctx.r10.s64 = ctx.r3.s64 + 576;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// bge cr6,0x824f1654
	if (!cr6.lt) goto loc_824F1654;
	// add r11,r6,r7
	r11.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824F1624:
	// addi r30,r11,24
	r30.s64 = r11.s64 + 24;
	// ld r5,32(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 32);
	// ld r31,24(r11)
	r31.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// ld r30,40(r11)
	r30.u64 = PPC_LOAD_U64(r11.u32 + 40);
	// std r5,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r5.u64);
	// std r31,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r31.u64);
	// std r30,16(r11)
	PPC_STORE_U64(r11.u32 + 16, r30.u64);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// lwz r5,1536(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1536);
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// blt cr6,0x824f1624
	if (cr6.lt) goto loc_824F1624;
loc_824F1654:
	// lwz r11,1536(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1536);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,1536(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1536, r11.u32);
loc_824F1660:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r7,r7,-24
	ctx.r7.s64 = ctx.r7.s64 + -24;
	// bge 0x824f15f0
	if (!cr0.lt) goto loc_824F15F0;
loc_824F166C:
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

__attribute__((alias("__imp__sub_824F1684"))) PPC_WEAK_FUNC(sub_824F1684);
PPC_FUNC_IMPL(__imp__sub_824F1684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1688"))) PPC_WEAK_FUNC(sub_824F1688);
PPC_FUNC_IMPL(__imp__sub_824F1688) {
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
	ctx.lr = 0x824F1690;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// subf r11,r29,r4
	r11.s64 = ctx.r4.s64 - r29.s64;
	// srawi r28,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	r28.s64 = r11.s32 >> 4;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x824f170c
	if (cr6.lt) goto loc_824F170C;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// rlwinm r11,r31,4,0,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// ldx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + r29.u32);
	// ld r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// bl 0x824f1298
	ctx.lr = 0x824F16D8;
	sub_824F1298(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824f170c
	if (cr6.eq) goto loc_824F170C;
loc_824F16E0:
	// addi r30,r30,-16
	r30.s64 = r30.s64 + -16;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ld r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// ld r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// bl 0x824f1298
	ctx.lr = 0x824F1704;
	sub_824F1298(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x824f16e0
	if (!cr6.eq) goto loc_824F16E0;
loc_824F170C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F1714"))) PPC_WEAK_FUNC(sub_824F1714);
PPC_FUNC_IMPL(__imp__sub_824F1714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1718"))) PPC_WEAK_FUNC(sub_824F1718);
PPC_FUNC_IMPL(__imp__sub_824F1718) {
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
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
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
	ctx.lr = 0x824F1748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x824f17e0
	if (!cr6.eq) goto loc_824F17E0;
	// lbz r11,2660(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2660);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f17e0
	if (cr6.eq) goto loc_824F17E0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r9,r11,30480
	ctx.r9.s64 = r11.s64 + 30480;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,40(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r5,44(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x824f1400
	ctx.lr = 0x824F1784;
	sub_824F1400(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f17e0
	if (cr6.eq) goto loc_824F17E0;
	// lwz r9,568(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 568);
	// addi r11,r30,56
	r11.s64 = r30.s64 + 56;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x824f17e0
	if (!cr6.gt) goto loc_824F17E0;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_824F17A8:
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpld cr6,r8,r4
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f17c8
	if (cr6.eq) goto loc_824F17C8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x824f17a8
	if (cr6.lt) goto loc_824F17A8;
	// b 0x824f17e0
	goto loc_824F17E0;
loc_824F17C8:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x824f17e0
	if (cr6.lt) goto loc_824F17E0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lwz r6,600(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 600);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0e88
	ctx.lr = 0x824F17E0;
	sub_824F0E88(ctx, base);
loc_824F17E0:
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
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

__attribute__((alias("__imp__sub_824F17F8"))) PPC_WEAK_FUNC(sub_824F17F8);
PPC_FUNC_IMPL(__imp__sub_824F17F8) {
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
	ctx.lr = 0x824F1800;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,30480
	ctx.r10.s64 = r11.s64 + 30480;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
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
	// bl 0x824f1348
	ctx.lr = 0x824F1830;
	sub_824F1348(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f1864
	if (cr6.eq) goto loc_824F1864;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ef298
	ctx.lr = 0x824F1854;
	sub_824EF298(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f1868
	if (!cr6.eq) goto loc_824F1868;
loc_824F1864:
	// li r11,0
	r11.s64 = 0;
loc_824F1868:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F1874"))) PPC_WEAK_FUNC(sub_824F1874);
PPC_FUNC_IMPL(__imp__sub_824F1874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1878"))) PPC_WEAK_FUNC(sub_824F1878);
PPC_FUNC_IMPL(__imp__sub_824F1878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// lwz r11,40(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 40);
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
loc_824F1884:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x824f18a0
	if (!cr6.gt) goto loc_824F18A0;
loc_824F1890:
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bgt cr6,0x824f1890
	if (cr6.gt) goto loc_824F1890;
loc_824F18A0:
	// addi r4,r4,-16
	ctx.r4.s64 = ctx.r4.s64 + -16;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x824f18c0
	if (!cr6.gt) goto loc_824F18C0;
loc_824F18B0:
	// addi r4,r4,-16
	ctx.r4.s64 = ctx.r4.s64 + -16;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x824f18b0
	if (cr6.gt) goto loc_824F18B0;
loc_824F18C0:
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// ld r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// std r10,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r10.u64);
	// std r8,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r8.u64);
	// ld r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// ld r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r7.u32 + 8);
	// std r6,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r6.u64);
	// ld r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// std r9,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r9.u64);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// std r5,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, ctx.r5.u64);
	// std r10,8(r4)
	PPC_STORE_U64(ctx.r4.u32 + 8, ctx.r10.u64);
	// b 0x824f1884
	goto loc_824F1884;
}

__attribute__((alias("__imp__sub_824F1908"))) PPC_WEAK_FUNC(sub_824F1908);
PPC_FUNC_IMPL(__imp__sub_824F1908) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F190C"))) PPC_WEAK_FUNC(sub_824F190C);
PPC_FUNC_IMPL(__imp__sub_824F190C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1910"))) PPC_WEAK_FUNC(sub_824F1910);
PPC_FUNC_IMPL(__imp__sub_824F1910) {
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
	ctx.lr = 0x824F1918;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// std r30,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r30.u64);
	// bl 0x824e6310
	ctx.lr = 0x824F1934;
	sub_824E6310(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x824ebf78
	ctx.lr = 0x824F1940;
	sub_824EBF78(ctx, base);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// addi r3,r31,576
	ctx.r3.s64 = r31.s64 + 576;
	// stw r30,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r30.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// bl 0x824f1030
	ctx.lr = 0x824F1958;
	sub_824F1030(ctx, base);
	// li r11,10000
	r11.s64 = 10000;
	// li r10,1000
	ctx.r10.s64 = 1000;
	// stw r30,2632(r31)
	PPC_STORE_U32(r31.u32 + 2632, r30.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r30,2640(r31)
	PPC_STORE_U32(r31.u32 + 2640, r30.u32);
	// stw r30,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,2648(r31)
	PPC_STORE_U32(r31.u32 + 2648, r11.u32);
	// stw r10,2652(r31)
	PPC_STORE_U32(r31.u32 + 2652, ctx.r10.u32);
	// stw r9,2656(r31)
	PPC_STORE_U32(r31.u32 + 2656, ctx.r9.u32);
	// lbz r8,2660(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// clrlwi r7,r8,26
	ctx.r7.u64 = ctx.r8.u32 & 0x3F;
	// stb r7,2660(r31)
	PPC_STORE_U8(r31.u32 + 2660, ctx.r7.u8);
	// bl 0x824e6310
	ctx.lr = 0x824F1990;
	sub_824E6310(ctx, base);
	// lis r6,-32177
	ctx.r6.s64 = -2108751872;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,5912
	ctx.r5.s64 = ctx.r6.s64 + 5912;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x824F19A8;
	sub_82130000(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r30.u32);
	// stw r30,2112(r31)
	PPC_STORE_U32(r31.u32 + 2112, r30.u32);
	// stw r30,2632(r31)
	PPC_STORE_U32(r31.u32 + 2632, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F19CC"))) PPC_WEAK_FUNC(sub_824F19CC);
PPC_FUNC_IMPL(__imp__sub_824F19CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F19D0"))) PPC_WEAK_FUNC(sub_824F19D0);
PPC_FUNC_IMPL(__imp__sub_824F19D0) {
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
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,2660(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2660);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824f1a14
	if (!cr6.eq) goto loc_824F1A14;
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// addi r4,r3,8
	ctx.r4.s64 = ctx.r3.s64 + 8;
	// stw r10,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r10.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r5,2656(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2656);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x824f17f8
	ctx.lr = 0x824F1A14;
	sub_824F17F8(ctx, base);
loc_824F1A14:
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F1A24"))) PPC_WEAK_FUNC(sub_824F1A24);
PPC_FUNC_IMPL(__imp__sub_824F1A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1A28"))) PPC_WEAK_FUNC(sub_824F1A28);
PPC_FUNC_IMPL(__imp__sub_824F1A28) {
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
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,2660(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824f1a88
	if (!cr6.eq) goto loc_824F1A88;
	// lwz r11,2632(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2632);
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, r11.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// ble cr6,0x824f1a74
	if (!cr6.gt) goto loc_824F1A74;
	// addi r4,r31,2120
	ctx.r4.s64 = r31.s64 + 2120;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823dadd8
	ctx.lr = 0x824F1A74;
	sub_823DADD8(ctx, base);
loc_824F1A74:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r5,2656(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2656);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x824f17f8
	ctx.lr = 0x824F1A88;
	sub_824F17F8(ctx, base);
loc_824F1A88:
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F1A9C"))) PPC_WEAK_FUNC(sub_824F1A9C);
PPC_FUNC_IMPL(__imp__sub_824F1A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1AA0"))) PPC_WEAK_FUNC(sub_824F1AA0);
PPC_FUNC_IMPL(__imp__sub_824F1AA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// lwz r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x824f1b28
	if (!cr6.gt) goto loc_824F1B28;
	// subf r10,r3,r11
	ctx.r10.s64 = r11.s64 - ctx.r3.s64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// srawi. r9,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble 0x824f1b04
	if (!cr0.gt) goto loc_824F1B04;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
loc_824F1AE4:
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// std r7,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r7.u64);
	// bgt 0x824f1ae4
	if (cr0.gt) goto loc_824F1AE4;
loc_824F1B04:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// std r10,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r10.u64);
	// std r9,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r9.u64);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824F1B28:
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x824f0ab0
	ctx.lr = 0x824F1B34;
	sub_824F0AB0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F1B44"))) PPC_WEAK_FUNC(sub_824F1B44);
PPC_FUNC_IMPL(__imp__sub_824F1B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1B48"))) PPC_WEAK_FUNC(sub_824F1B48);
PPC_FUNC_IMPL(__imp__sub_824F1B48) {
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
	ctx.lr = 0x824F1B50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// ble cr6,0x824f1bc8
	if (!cr6.gt) goto loc_824F1BC8;
	// addi r29,r30,-16
	r29.s64 = r30.s64 + -16;
loc_824F1B70:
	// ld r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// ldx r7,r29,r11
	ctx.r7.u64 = PPC_LOAD_U64(r29.u32 + r11.u32);
	// addi r31,r11,-16
	r31.s64 = r11.s64 + -16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// srawi r5,r31,4
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0xF) != 0);
	ctx.r5.s64 = r31.s32 >> 4;
	// stdx r9,r29,r11
	PPC_STORE_U64(r29.u32 + r11.u32, ctx.r9.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r11,8(r10)
	r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// std r9,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r9.u64);
	// std r7,0(r6)
	PPC_STORE_U64(ctx.r6.u32 + 0, ctx.r7.u64);
	// std r11,8(r6)
	PPC_STORE_U64(ctx.r6.u32 + 8, r11.u64);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x824f1298
	ctx.lr = 0x824F1BB8;
	sub_824F1298(ctx, base);
	// rlwinm r8,r31,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r8,16
	cr6.compare<int32_t>(ctx.r8.s32, 16, xer);
	// bgt cr6,0x824f1b70
	if (cr6.gt) goto loc_824F1B70;
loc_824F1BC8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F1BD0"))) PPC_WEAK_FUNC(sub_824F1BD0);
PPC_FUNC_IMPL(__imp__sub_824F1BD0) {
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
	// addi r10,r11,-964
	ctx.r10.s64 = r11.s64 + -964;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82273a60
	ctx.lr = 0x824F1BFC;
	sub_82273A60(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824fa710
	ctx.lr = 0x824F1C04;
	sub_824FA710(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-1028
	ctx.r7.s64 = ctx.r9.s64 + -1028;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824f1c28
	if (cr6.eq) goto loc_824F1C28;
	// bl 0x82130588
	ctx.lr = 0x824F1C24;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824F1C28:
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

__attribute__((alias("__imp__sub_824F1C40"))) PPC_WEAK_FUNC(sub_824F1C40);
PPC_FUNC_IMPL(__imp__sub_824F1C40) {
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
	// addi r10,r31,56
	ctx.r10.s64 = r31.s64 + 56;
	// lwz r9,568(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 568);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x824f1d38
	if (!cr6.gt) goto loc_824F1D38;
loc_824F1C68:
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r8,r4
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f1c98
	if (cr6.eq) goto loc_824F1C98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824f1c68
	if (cr6.lt) goto loc_824F1C68;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824F1C98:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x824f1d38
	if (cr6.lt) goto loc_824F1D38;
	// lwz r8,2632(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 2632);
	// addi r9,r31,2120
	ctx.r9.s64 = r31.s64 + 2120;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x824f1ce0
	if (!cr6.gt) goto loc_824F1CE0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_824F1CB8:
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r7,r4
	cr6.compare<uint64_t>(ctx.r7.u64, ctx.r4.u64, xer);
	// beq cr6,0x824f1cd8
	if (cr6.eq) goto loc_824F1CD8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824f1cb8
	if (cr6.lt) goto loc_824F1CB8;
	// b 0x824f1ce0
	goto loc_824F1CE0;
loc_824F1CD8:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x824f1d38
	if (!cr6.eq) goto loc_824F1D38;
loc_824F1CE0:
	// lwz r11,2632(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2632);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x824f1d38
	if (cr6.eq) goto loc_824F1D38;
	// lwz r11,512(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 512);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,512(r9)
	PPC_STORE_U32(ctx.r9.u32 + 512, r11.u32);
	// stdx r4,r10,r9
	PPC_STORE_U64(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u64);
	// lbz r10,2660(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824f1d38
	if (!cr6.eq) goto loc_824F1D38;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f19d0
	ctx.lr = 0x824F1D18;
	sub_824F19D0(ctx, base);
	// lwz r11,2644(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2644);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f1d38
	if (!cr6.eq) goto loc_824F1D38;
	// bl 0x821c9788
	ctx.lr = 0x824F1D28;
	sub_821C9788(ctx, base);
	// lwz r11,2652(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2652);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, ctx.r9.u32);
loc_824F1D38:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F1D4C"))) PPC_WEAK_FUNC(sub_824F1D4C);
PPC_FUNC_IMPL(__imp__sub_824F1D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F1D50"))) PPC_WEAK_FUNC(sub_824F1D50);
PPC_FUNC_IMPL(__imp__sub_824F1D50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824F1D58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x824f1da0
	if (cr6.eq) goto loc_824F1DA0;
	// addi r31,r30,16
	r31.s64 = r30.s64 + 16;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x824f1da0
	if (cr6.eq) goto loc_824F1DA0;
loc_824F1D7C:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// ld r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ld r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f1aa0
	ctx.lr = 0x824F1D94;
	sub_824F1AA0(ctx, base);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x824f1d7c
	if (!cr6.eq) goto loc_824F1D7C;
loc_824F1DA0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F1DA8"))) PPC_WEAK_FUNC(sub_824F1DA8);
PPC_FUNC_IMPL(__imp__sub_824F1DA8) {
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
	ctx.lr = 0x824F1DB0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824f1688
	ctx.lr = 0x824F1DD4;
	sub_824F1688(ctx, base);
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bge cr6,0x824f1e40
	if (!cr6.lt) goto loc_824F1E40;
loc_824F1DE0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x824f1e34
	if (!cr6.gt) goto loc_824F1E34;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// ld r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// subf r7,r30,r29
	ctx.r7.s64 = r29.s64 - r30.s64;
	// ld r26,0(r30)
	r26.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// srawi r5,r7,4
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r9,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r9.u64);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r26,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r26.u64);
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// std r11,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r11.u64);
	// bl 0x824f1298
	ctx.lr = 0x824F1E34;
	sub_824F1298(ctx, base);
loc_824F1E34:
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// blt cr6,0x824f1de0
	if (cr6.lt) goto loc_824F1DE0;
loc_824F1E40:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f1b48
	ctx.lr = 0x824F1E50;
	sub_824F1B48(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F1E58"))) PPC_WEAK_FUNC(sub_824F1E58);
PPC_FUNC_IMPL(__imp__sub_824F1E58) {
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
	ctx.lr = 0x824F1E60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// subf r11,r31,r29
	r11.s64 = r29.s64 - r31.s64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmpwi cr6,r10,256
	cr6.compare<int32_t>(ctx.r10.s32, 256, xer);
	// ble cr6,0x824f1f58
	if (!cr6.gt) goto loc_824F1F58;
loc_824F1E84:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x824f1f40
	if (cr6.eq) goto loc_824F1F40;
	// subf r11,r31,r29
	r11.s64 = r29.s64 - r31.s64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// srawi r9,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	ctx.r9.s64 = r11.s32 >> 4;
	// addi r11,r29,-16
	r11.s64 = r29.s64 + -16;
	// srawi r8,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r8,r9,r31
	ctx.r8.u64 = ctx.r9.u64 + r31.u64;
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x824f1ed8
	if (!cr6.gt) goto loc_824F1ED8;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bgt cr6,0x824f1ef0
	if (cr6.gt) goto loc_824F1EF0;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bgt cr6,0x824f1ef4
	if (cr6.gt) goto loc_824F1EF4;
	// mr r11,r31
	r11.u64 = r31.u64;
	// b 0x824f1ef4
	goto loc_824F1EF4;
loc_824F1ED8:
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// ble cr6,0x824f1ee8
	if (!cr6.gt) goto loc_824F1EE8;
	// mr r11,r31
	r11.u64 = r31.u64;
	// b 0x824f1ef4
	goto loc_824F1EF4;
loc_824F1EE8:
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bgt cr6,0x824f1ef4
	if (cr6.gt) goto loc_824F1EF4;
loc_824F1EF0:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_824F1EF4:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f1878
	ctx.lr = 0x824F1F0C;
	sub_824F1878(ctx, base);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x824f1e58
	ctx.lr = 0x824F1F24;
	sub_824F1E58(ctx, base);
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// mr r29,r30
	r29.u64 = r30.u64;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmpwi cr6,r10,256
	cr6.compare<int32_t>(ctx.r10.s32, 256, xer);
	// bgt cr6,0x824f1e84
	if (cr6.gt) goto loc_824F1E84;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824F1F40:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f1da8
	ctx.lr = 0x824F1F58;
	sub_824F1DA8(ctx, base);
loc_824F1F58:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F1F60"))) PPC_WEAK_FUNC(sub_824F1F60);
PPC_FUNC_IMPL(__imp__sub_824F1F60) {
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
	ctx.lr = 0x824F1F68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x824f2008
	if (cr6.eq) goto loc_824F2008;
	// subf r10,r31,r30
	ctx.r10.s64 = r30.s64 - r31.s64;
	// li r11,0
	r11.s64 = 0;
	// srawi r29,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	r29.s64 = ctx.r10.s32 >> 4;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x824f1fa8
	if (cr6.eq) goto loc_824F1FA8;
loc_824F1F98:
	// srawi r10,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x824f1f98
	if (!cr6.eq) goto loc_824F1F98;
loc_824F1FA8:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f1e58
	ctx.lr = 0x824F1FC0;
	sub_824F1E58(ctx, base);
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// ble cr6,0x824f1ffc
	if (!cr6.gt) goto loc_824F1FFC;
	// addi r29,r31,256
	r29.s64 = r31.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f1d50
	ctx.lr = 0x824F1FE0;
	sub_824F1D50(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f1218
	ctx.lr = 0x824F1FF4;
	sub_824F1218(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824F1FFC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f1d50
	ctx.lr = 0x824F2008;
	sub_824F1D50(ctx, base);
loc_824F2008:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F2010"))) PPC_WEAK_FUNC(sub_824F2010);
PPC_FUNC_IMPL(__imp__sub_824F2010) {
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
	// stwu r1,-1184(r1)
	ea = -1184 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r9,2112(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 2112);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2214
	if (cr6.eq) goto loc_824F2214;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,63
	ctx.r10.s64 = 63;
	// li r31,0
	r31.s64 = 0;
loc_824F2040:
	// std r31,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r31.u64);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bge 0x824f2040
	if (!cr0.lt) goto loc_824F2040;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, ctx.r8.u32);
	// ble cr6,0x824f21b8
	if (!cr6.gt) goto loc_824F21B8;
	// addi r5,r30,576
	ctx.r5.s64 = r30.s64 + 576;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
loc_824F206C:
	// ld r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r5.u32 + 0);
	// mr r11,r31
	r11.u64 = r31.u64;
	// ld r6,8(r5)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r5.u32 + 8);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// ble cr6,0x824f20d0
	if (!cr6.gt) goto loc_824F20D0;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
loc_824F2094:
	// ld r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// cmpld cr6,r10,r7
	cr6.compare<uint64_t>(ctx.r10.u64, ctx.r7.u64, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x824f20a8
	if (cr6.eq) goto loc_824F20A8;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_824F20A8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824f20c8
	if (!cr6.eq) goto loc_824F20C8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824f2094
	if (cr6.lt) goto loc_824F2094;
	// b 0x824f20d0
	goto loc_824F20D0;
loc_824F20C8:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x824f20fc
	if (!cr6.lt) goto loc_824F20FC;
loc_824F20D0:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ld r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// ld r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// stw r8,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, ctx.r8.u32);
	// std r7,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r7.u64);
	// std r3,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r3.u64);
	// b 0x824f2108
	goto loc_824F2108;
loc_824F20FC:
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824F2108:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r8,1152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1152);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x824f2164
	if (!cr6.gt) goto loc_824F2164;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
loc_824F2128:
	// ld r11,0(r9)
	r11.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// cmpld cr6,r11,r6
	cr6.compare<uint64_t>(r11.u64, ctx.r6.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f213c
	if (cr6.eq) goto loc_824F213C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824F213C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f215c
	if (!cr6.eq) goto loc_824F215C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x824f2128
	if (cr6.lt) goto loc_824F2128;
	// b 0x824f2164
	goto loc_824F2164;
loc_824F215C:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x824f2190
	if (!cr6.lt) goto loc_824F2190;
loc_824F2164:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// ld r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// stw r8,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, ctx.r8.u32);
	// std r7,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r7.u64);
	// std r6,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r6.u64);
	// b 0x824f219c
	goto loc_824F219C;
loc_824F2190:
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824F219C:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// addi r5,r5,24
	ctx.r5.s64 = ctx.r5.s64 + 24;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r8,1152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1152);
	// bne 0x824f206c
	if (!cr0.eq) goto loc_824F206C;
loc_824F21B8:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// stb r31,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r31.u8);
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x824f1f60
	ctx.lr = 0x824F21D8;
	sub_824F1F60(ctx, base);
	// lwz r3,48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f21fc
	if (cr6.eq) goto loc_824F21FC;
	// lwz r5,1152(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1152);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824F21F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824f220c
	goto loc_824F220C;
loc_824F21FC:
	// lwz r4,1152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1152);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824F220C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824F220C:
	// stw r31,2112(r30)
	PPC_STORE_U32(r30.u32 + 2112, r31.u32);
	// stw r31,2632(r30)
	PPC_STORE_U32(r30.u32 + 2632, r31.u32);
loc_824F2214:
	// addi r1,r1,1184
	ctx.r1.s64 = ctx.r1.s64 + 1184;
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

__attribute__((alias("__imp__sub_824F222C"))) PPC_WEAK_FUNC(sub_824F222C);
PPC_FUNC_IMPL(__imp__sub_824F222C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2230"))) PPC_WEAK_FUNC(sub_824F2230);
PPC_FUNC_IMPL(__imp__sub_824F2230) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821c9788
	ctx.lr = 0x824F224C;
	sub_821C9788(ctx, base);
	// lbz r11,2660(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2660);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f2288
	if (cr6.eq) goto loc_824F2288;
	// lwz r11,2640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2640);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f22b4
	if (cr6.eq) goto loc_824F22B4;
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x824f22b4
	if (cr0.lt) goto loc_824F22B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2010
	ctx.lr = 0x824F227C;
	sub_824F2010(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,2640(r31)
	PPC_STORE_U32(r31.u32 + 2640, r11.u32);
	// b 0x824f22b4
	goto loc_824F22B4;
loc_824F2288:
	// lwz r11,2644(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2644);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f22b4
	if (cr6.eq) goto loc_824F22B4;
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x824f22b4
	if (cr0.lt) goto loc_824F22B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f1a28
	ctx.lr = 0x824F22A4;
	sub_824F1A28(ctx, base);
	// lwz r11,2652(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2652);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, ctx.r10.u32);
loc_824F22B4:
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

__attribute__((alias("__imp__sub_824F22CC"))) PPC_WEAK_FUNC(sub_824F22CC);
PPC_FUNC_IMPL(__imp__sub_824F22CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F22D0"))) PPC_WEAK_FUNC(sub_824F22D0);
PPC_FUNC_IMPL(__imp__sub_824F22D0) {
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
	// lbz r11,169(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 169);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f230c
	if (cr6.eq) goto loc_824F230C;
	// addi r30,r3,76
	r30.s64 = ctx.r3.s64 + 76;
	// li r31,3
	r31.s64 = 3;
loc_824F22F8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824F2300;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824f22f8
	if (!cr0.eq) goto loc_824F22F8;
loc_824F230C:
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

__attribute__((alias("__imp__sub_824F2324"))) PPC_WEAK_FUNC(sub_824F2324);
PPC_FUNC_IMPL(__imp__sub_824F2324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2328"))) PPC_WEAK_FUNC(sub_824F2328);
PPC_FUNC_IMPL(__imp__sub_824F2328) {
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
	// lbz r11,281(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 281);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f2364
	if (cr6.eq) goto loc_824F2364;
	// addi r30,r3,188
	r30.s64 = ctx.r3.s64 + 188;
	// li r31,3
	r31.s64 = 3;
loc_824F2350:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824F2358;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824f2350
	if (!cr0.eq) goto loc_824F2350;
loc_824F2364:
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

__attribute__((alias("__imp__sub_824F237C"))) PPC_WEAK_FUNC(sub_824F237C);
PPC_FUNC_IMPL(__imp__sub_824F237C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2380"))) PPC_WEAK_FUNC(sub_824F2380);
PPC_FUNC_IMPL(__imp__sub_824F2380) {
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
	// bl 0x824f9270
	ctx.lr = 0x824F2398;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f2430
	if (cr6.eq) goto loc_824F2430;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_824F23AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824f23ac
	if (!cr6.eq) goto loc_824F23AC;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f2430
	if (cr6.eq) goto loc_824F2430;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824f2430
	if (cr6.eq) goto loc_824F2430;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2430
	if (cr6.eq) goto loc_824F2430;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,52
	r11.s64 = r31.s64 + 52;
loc_824F23F0:
	// lwz r8,-12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x824f2430
	if (cr6.eq) goto loc_824F2430;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f2430
	if (cr6.eq) goto loc_824F2430;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x824f23f0
	if (cr6.lt) goto loc_824F23F0;
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
loc_824F2430:
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

__attribute__((alias("__imp__sub_824F2448"))) PPC_WEAK_FUNC(sub_824F2448);
PPC_FUNC_IMPL(__imp__sub_824F2448) {
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
	ctx.lr = 0x824F2450;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,4
	r31.s64 = 4;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
loc_824F2464:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F246C;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f2464
	if (!cr0.eq) goto loc_824F2464;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f2490
	if (cr6.eq) goto loc_824F2490;
	// bl 0x8244a330
	ctx.lr = 0x824F2488;
	sub_8244A330(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_824F2490:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f24a8
	if (cr6.eq) goto loc_824F24A8;
	// bl 0x82130588
	ctx.lr = 0x824F24A0;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_824F24A8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F24B0"))) PPC_WEAK_FUNC(sub_824F24B0);
PPC_FUNC_IMPL(__imp__sub_824F24B0) {
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
	ctx.lr = 0x824F24B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f24fc
	if (cr6.eq) goto loc_824F24FC;
	// li r31,0
	r31.s64 = 0;
loc_824F24D4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824e7678
	ctx.lr = 0x824F24E0;
	sub_824E7678(ctx, base);
	// bl 0x824e70f0
	ctx.lr = 0x824F24E4;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f2508
	if (!cr6.eq) goto loc_824F2508;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// blt cr6,0x824f24d4
	if (cr6.lt) goto loc_824F24D4;
loc_824F24FC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F2508:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F2514"))) PPC_WEAK_FUNC(sub_824F2514);
PPC_FUNC_IMPL(__imp__sub_824F2514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2518"))) PPC_WEAK_FUNC(sub_824F2518);
PPC_FUNC_IMPL(__imp__sub_824F2518) {
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
	ctx.lr = 0x824F2520;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r30,1
	r30.s64 = 1;
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, r31.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r30.u32);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// bne cr6,0x824f2564
	if (!cr6.eq) goto loc_824F2564;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// beq cr6,0x824f2568
	if (cr6.eq) goto loc_824F2568;
loc_824F2564:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
loc_824F2568:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// addi r3,r31,1
	ctx.r3.s64 = r31.s64 + 1;
	// bl 0x8244a3e8
	ctx.lr = 0x824F2578;
	sub_8244A3E8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f25b4
	if (cr6.eq) goto loc_824F25B4;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824f25b4
	if (cr6.eq) goto loc_824F25B4;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a488
	ctx.lr = 0x824F2594;
	sub_8244A488(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824f25b4
	if (!cr6.eq) goto loc_824F25B4;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a488
	ctx.lr = 0x824F25A8;
	sub_8244A488(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x824f25b8
	if (!cr6.eq) goto loc_824F25B8;
loc_824F25B4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_824F25B8:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F25C0"))) PPC_WEAK_FUNC(sub_824F25C0);
PPC_FUNC_IMPL(__imp__sub_824F25C0) {
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
	ctx.lr = 0x824F25C8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534570
	ctx.lr = 0x824F25DC;
	sub_82534570(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534580
	ctx.lr = 0x824F25E8;
	sub_82534580(ctx, base);
	// clrlwi r28,r3,16
	r28.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534570
	ctx.lr = 0x824F25F4;
	sub_82534570(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// ble cr6,0x824f272c
	if (!cr6.gt) goto loc_824F272C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534580
	ctx.lr = 0x824F2608;
	sub_82534580(ctx, base);
	// clrlwi r28,r3,16
	r28.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534570
	ctx.lr = 0x824F2614;
	sub_82534570(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
	// cmplwi cr6,r26,1
	cr6.compare<uint32_t>(r26.u32, 1, xer);
	// ble cr6,0x824f2648
	if (!cr6.gt) goto loc_824F2648;
	// bl 0x823df0a0
	ctx.lr = 0x824F262C;
	sub_823DF0A0(ctx, base);
	// divwu r10,r3,r26
	ctx.r10.u32 = ctx.r3.u32 / r26.u32;
	// clrlwi r11,r31,16
	r11.u64 = r31.u32 & 0xFFFF;
	// mullw r9,r10,r26
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r26.s32);
	// subf r10,r9,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r9.s64;
	// twllei r26,0
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r31,r8,16
	r31.u64 = ctx.r8.u32 & 0xFFFF;
loc_824F2648:
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r28,r27
	r28.u64 = r27.u64;
	// beq cr6,0x824f273c
	if (cr6.eq) goto loc_824F273C;
	// li r24,-1
	r24.s64 = -1;
	// li r25,2
	r25.s64 = 2;
loc_824F2660:
	// lwz r3,124(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f2674
	if (cr6.eq) goto loc_824F2674;
	// bl 0x8244a330
	ctx.lr = 0x824F2670;
	sub_8244A330(ctx, base);
	// stw r24,124(r29)
	PPC_STORE_U32(r29.u32 + 124, r24.u32);
loc_824F2674:
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8244a318
	ctx.lr = 0x824F2684;
	sub_8244A318(ctx, base);
	// stw r3,124(r29)
	PPC_STORE_U32(r29.u32 + 124, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f273c
	if (cr6.eq) goto loc_824F273C;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r27,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r27.u64);
	// std r27,8(r11)
	PPC_STORE_U64(r11.u32 + 8, r27.u64);
	// sth r25,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r25.u16);
	// bl 0x82534568
	ctx.lr = 0x824F26A8;
	sub_82534568(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// sth r31,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r31.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,124(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// bl 0x8244a3a8
	ctx.lr = 0x824F26C0;
	sub_8244A3A8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824f26e8
	if (!cr6.eq) goto loc_824F26E8;
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f2518
	ctx.lr = 0x824F26DC;
	sub_824F2518(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f2734
	if (!cr6.eq) goto loc_824F2734;
loc_824F26E8:
	// clrlwi r11,r31,16
	r11.u64 = r31.u32 & 0xFFFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// clrlwi r31,r11,16
	r31.u64 = r11.u32 & 0xFFFF;
	// bl 0x82534580
	ctx.lr = 0x824F2700;
	sub_82534580(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// ble cr6,0x824f2718
	if (!cr6.gt) goto loc_824F2718;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534570
	ctx.lr = 0x824F2714;
	sub_82534570(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_824F2718:
	// cmplw cr6,r28,r26
	cr6.compare<uint32_t>(r28.u32, r26.u32, xer);
	// blt cr6,0x824f2660
	if (cr6.lt) goto loc_824F2660;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_824F272C:
	// li r26,1
	r26.s64 = 1;
	// b 0x824f2648
	goto loc_824F2648;
loc_824F2734:
	// cmplw cr6,r28,r26
	cr6.compare<uint32_t>(r28.u32, r26.u32, xer);
	// blt cr6,0x824f2748
	if (cr6.lt) goto loc_824F2748;
loc_824F273C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_824F2748:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F2754"))) PPC_WEAK_FUNC(sub_824F2754);
PPC_FUNC_IMPL(__imp__sub_824F2754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2758"))) PPC_WEAK_FUNC(sub_824F2758);
PPC_FUNC_IMPL(__imp__sub_824F2758) {
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
	ctx.lr = 0x824F2760;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r22,r23,124
	r22.s64 = r23.s64 + 124;
	// lwz r11,124(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 124);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824f28f0
	if (!cr6.eq) goto loc_824F28F0;
	// bl 0x824f24b0
	ctx.lr = 0x824F2794;
	sub_824F24B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f28e4
	if (cr6.eq) goto loc_824F28E4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r27,r10,30512
	r27.s64 = ctx.r10.s64 + 30512;
	// addi r26,r11,30648
	r26.s64 = r11.s64 + 30648;
	// lwz r30,30512(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30512);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824f27e4
	if (!cr6.eq) goto loc_824F27E4;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82534d00
	ctx.lr = 0x824F27CC;
	sub_82534D00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f28dc
	if (cr6.eq) goto loc_824F28DC;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f28dc
	if (cr6.eq) goto loc_824F28DC;
loc_824F27E4:
	// li r24,0
	r24.s64 = 0;
loc_824F27E8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f28d0
	if (cr6.eq) goto loc_824F28D0;
	// bl 0x823df0a0
	ctx.lr = 0x824F27F4;
	sub_823DF0A0(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r29,r9,r3
	r29.s64 = ctx.r3.s64 - ctx.r9.s64;
	// mulli r28,r29,224
	r28.s64 = r29.s64 * 224;
	// add r31,r28,r26
	r31.u64 = r28.u64 + r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534610
	ctx.lr = 0x824F2818;
	sub_82534610(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f2884
	if (cr6.eq) goto loc_824F2884;
	// bl 0x821c9788
	ctx.lr = 0x824F2828;
	sub_821C9788(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534590
	ctx.lr = 0x824F2834;
	sub_82534590(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x824f2864
	if (!cr6.eq) goto loc_824F2864;
loc_824F283C:
	// bl 0x821c9788
	ctx.lr = 0x824F2840;
	sub_821C9788(ctx, base);
	// subf r11,r30,r3
	r11.s64 = ctx.r3.s64 - r30.s64;
	// cmplwi cr6,r11,3000
	cr6.compare<uint32_t>(r11.u32, 3000, xer);
	// bge cr6,0x824f2864
	if (!cr6.lt) goto loc_824F2864;
	// li r3,100
	ctx.r3.s64 = 100;
	// bl 0x821c91b8
	ctx.lr = 0x824F2854;
	sub_821C91B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534590
	ctx.lr = 0x824F285C;
	sub_82534590(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x824f283c
	if (cr6.eq) goto loc_824F283C;
loc_824F2864:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534590
	ctx.lr = 0x824F286C;
	sub_82534590(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x824f2884
	if (!cr6.eq) goto loc_824F2884;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x824f25c0
	ctx.lr = 0x824F2880;
	sub_824F25C0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_824F2884:
	// clrlwi r25,r24,24
	r25.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x824f28c4
	if (!cr6.eq) goto loc_824F28C4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r30,r11,-1
	r30.s64 = r11.s64 + -1;
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// bge cr6,0x824f28bc
	if (!cr6.lt) goto loc_824F28BC;
	// subf r10,r29,r30
	ctx.r10.s64 = r30.s64 - r29.s64;
	// addi r11,r26,224
	r11.s64 = r26.s64 + 224;
	// mulli r9,r10,224
	ctx.r9.s64 = ctx.r10.s64 * 224;
	// add r4,r28,r11
	ctx.r4.u64 = r28.u64 + r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r5,r9,0,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF8;
	// bl 0x823dadd8
	ctx.lr = 0x824F28BC;
	sub_823DADD8(ctx, base);
loc_824F28BC:
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// b 0x824f28c8
	goto loc_824F28C8;
loc_824F28C4:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_824F28C8:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824f27e8
	if (cr6.eq) goto loc_824F27E8;
loc_824F28D0:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f28f0
	if (!cr6.eq) goto loc_824F28F0;
loc_824F28DC:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824f2448
	ctx.lr = 0x824F28E4;
	sub_824F2448(ctx, base);
loc_824F28E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_824F28F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824F28FC"))) PPC_WEAK_FUNC(sub_824F28FC);
PPC_FUNC_IMPL(__imp__sub_824F28FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2900"))) PPC_WEAK_FUNC(sub_824F2900);
PPC_FUNC_IMPL(__imp__sub_824F2900) {
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
	ctx.lr = 0x824F2908;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r22,0
	r22.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r27,1
	r27.s64 = 1;
	// mr r28,r26
	r28.u64 = r26.u64;
	// mr r29,r22
	r29.u64 = r22.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f29e0
	if (cr6.eq) goto loc_824F29E0;
	// addi r25,r31,1
	r25.s64 = r31.s64 + 1;
	// li r24,30
	r24.s64 = 30;
loc_824F2938:
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, r31.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r27.u32);
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// mr r30,r22
	r30.u64 = r22.u64;
	// bl 0x8244a3e8
	ctx.lr = 0x824F296C;
	sub_8244A3E8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f29a8
	if (cr6.eq) goto loc_824F29A8;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824f29a8
	if (cr6.eq) goto loc_824F29A8;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a488
	ctx.lr = 0x824F2988;
	sub_8244A488(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824f29a8
	if (!cr6.eq) goto loc_824F29A8;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a488
	ctx.lr = 0x824F299C;
	sub_8244A488(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824f29a8
	if (cr6.eq) goto loc_824F29A8;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824F29A8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f29ec
	if (cr6.eq) goto loc_824F29EC;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// add r4,r29,r23
	ctx.r4.u64 = r29.u64 + r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a440
	ctx.lr = 0x824F29C8;
	sub_8244A440(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f29ec
	if (cr6.eq) goto loc_824F29EC;
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// subf r28,r3,r28
	r28.s64 = r28.s64 - ctx.r3.s64;
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// blt cr6,0x824f2938
	if (cr6.lt) goto loc_824F2938;
loc_824F29E0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9230
	return;
loc_824F29EC:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824F29F8"))) PPC_WEAK_FUNC(sub_824F29F8);
PPC_FUNC_IMPL(__imp__sub_824F29F8) {
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
	ctx.lr = 0x824F2A00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,-1
	r11.s64 = -1;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
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
	// beq cr6,0x824f2a78
	if (cr6.eq) goto loc_824F2A78;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x824f2900
	ctx.lr = 0x824F2A48;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f2a78
	if (cr6.eq) goto loc_824F2A78;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F2A68;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f2a7c
	if (!cr6.eq) goto loc_824F2A7C;
loc_824F2A78:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_824F2A7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F2A84"))) PPC_WEAK_FUNC(sub_824F2A84);
PPC_FUNC_IMPL(__imp__sub_824F2A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2A88"))) PPC_WEAK_FUNC(sub_824F2A88);
PPC_FUNC_IMPL(__imp__sub_824F2A88) {
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
	ctx.lr = 0x824F2A90;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r27,1
	r27.s64 = 1;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// mr r30,r24
	r30.u64 = r24.u64;
	// beq cr6,0x824f2b64
	if (cr6.eq) goto loc_824F2B64;
	// addi r26,r31,1
	r26.s64 = r31.s64 + 1;
	// li r25,30
	r25.s64 = 30;
loc_824F2ABC:
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, r31.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r27.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// mr r29,r24
	r29.u64 = r24.u64;
	// bl 0x8244a3e8
	ctx.lr = 0x824F2AF0;
	sub_8244A3E8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f2b2c
	if (cr6.eq) goto loc_824F2B2C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824f2b2c
	if (cr6.eq) goto loc_824F2B2C;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a488
	ctx.lr = 0x824F2B0C;
	sub_8244A488(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824f2b2c
	if (!cr6.eq) goto loc_824F2B2C;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a488
	ctx.lr = 0x824F2B20;
	sub_8244A488(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824f2b2c
	if (cr6.eq) goto loc_824F2B2C;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_824F2B2C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f2b70
	if (cr6.eq) goto loc_824F2B70;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r5,r30,r28
	ctx.r5.s64 = r28.s64 - r30.s64;
	// add r4,r30,r23
	ctx.r4.u64 = r30.u64 + r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244a408
	ctx.lr = 0x824F2B4C;
	sub_8244A408(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824f2b70
	if (cr6.eq) goto loc_824F2B70;
	// ble cr6,0x824f2b70
	if (!cr6.gt) goto loc_824F2B70;
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// blt cr6,0x824f2abc
	if (cr6.lt) goto loc_824F2ABC;
loc_824F2B64:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9234
	return;
loc_824F2B70:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824F2B7C"))) PPC_WEAK_FUNC(sub_824F2B7C);
PPC_FUNC_IMPL(__imp__sub_824F2B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2B80"))) PPC_WEAK_FUNC(sub_824F2B80);
PPC_FUNC_IMPL(__imp__sub_824F2B80) {
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
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r31,r4
	ctx.r9.s64 = ctx.r4.s64 - r31.s64;
loc_824F2BB0:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f2bc8
	if (cr6.eq) goto loc_824F2BC8;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f2bb0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F2BB0;
loc_824F2BC8:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// li r5,152
	ctx.r5.s64 = 152;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x823da950
	ctx.lr = 0x824F2BE0;
	sub_823DA950(ctx, base);
	// stb r30,184(r31)
	PPC_STORE_U8(r31.u32 + 184, r30.u8);
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

__attribute__((alias("__imp__sub_824F2BFC"))) PPC_WEAK_FUNC(sub_824F2BFC);
PPC_FUNC_IMPL(__imp__sub_824F2BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2C00"))) PPC_WEAK_FUNC(sub_824F2C00);
PPC_FUNC_IMPL(__imp__sub_824F2C00) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x824F2C08;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// beq cr6,0x824f2c68
	if (cr6.eq) goto loc_824F2C68;
	// addi r8,r31,88
	ctx.r8.s64 = r31.s64 + 88;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
loc_824F2C40:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r9,-12(r8)
	PPC_STORE_U32(ctx.r8.u32 + -12, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lwz r5,72(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r7,r5
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, xer);
	// blt cr6,0x824f2c40
	if (cr6.lt) goto loc_824F2C40;
loc_824F2C68:
	// addi r30,r31,100
	r30.s64 = r31.s64 + 100;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F2C7C;
	sub_8244D150(ctx, base);
	// lwz r5,236(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r5.u32);
	// beq cr6,0x824f2c98
	if (cr6.eq) goto loc_824F2C98;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,228(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// bl 0x8244d5c0
	ctx.lr = 0x824F2C98;
	sub_8244D5C0(ctx, base);
loc_824F2C98:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r31,r28
	ctx.r9.s64 = r28.s64 - r31.s64;
loc_824F2CA8:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f2cc0
	if (cr6.eq) goto loc_824F2CC0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f2ca8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F2CA8;
loc_824F2CC0:
	// stb r25,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r25.u8);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// ld r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// addi r11,r31,56
	r11.s64 = r31.s64 + 56;
	// std r9,40(r31)
	PPC_STORE_U64(r31.u32 + 40, ctx.r9.u64);
	// li r8,15
	ctx.r8.s64 = 15;
	// ld r7,8(r29)
	ctx.r7.u64 = PPC_LOAD_U64(r29.u32 + 8);
	// std r7,48(r31)
	PPC_STORE_U64(r31.u32 + 48, ctx.r7.u64);
loc_824F2CE8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2d78
	if (cr6.eq) goto loc_824F2D78;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2d5c
	if (cr6.eq) goto loc_824F2D5C;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2d64
	if (cr6.eq) goto loc_824F2D64;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2d6c
	if (cr6.eq) goto loc_824F2D6C;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2d74
	if (cr6.eq) goto loc_824F2D74;
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
	// bgt 0x824f2ce8
	if (cr0.gt) goto loc_824F2CE8;
	// b 0x824f2d78
	goto loc_824F2D78;
loc_824F2D5C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x824f2d78
	goto loc_824F2D78;
loc_824F2D64:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x824f2d78
	goto loc_824F2D78;
loc_824F2D6C:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x824f2d78
	goto loc_824F2D78;
loc_824F2D74:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_824F2D78:
	// lbz r10,247(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 247);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r25,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r25.u8);
	// stb r10,168(r31)
	PPC_STORE_U8(r31.u32 + 168, ctx.r10.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F2D90"))) PPC_WEAK_FUNC(sub_824F2D90);
PPC_FUNC_IMPL(__imp__sub_824F2D90) {
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
	ctx.lr = 0x824F2D98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// stw r6,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r6.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824f2df4
	if (cr6.eq) goto loc_824F2DF4;
	// addi r10,r31,200
	ctx.r10.s64 = r31.s64 + 200;
	// subf r8,r11,r7
	ctx.r8.s64 = ctx.r7.s64 - r11.s64;
loc_824F2DCC:
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r7.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// blt cr6,0x824f2dcc
	if (cr6.lt) goto loc_824F2DCC;
loc_824F2DF4:
	// addi r30,r31,212
	r30.s64 = r31.s64 + 212;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F2E08;
	sub_8244D150(ctx, base);
	// stw r29,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f2e24
	if (cr6.eq) goto loc_824F2E24;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824F2E24;
	sub_8244D5C0(ctx, base);
loc_824F2E24:
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r31,r27
	ctx.r9.s64 = r27.s64 - r31.s64;
loc_824F2E34:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f2e4c
	if (cr6.eq) goto loc_824F2E4C;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f2e34
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F2E34;
loc_824F2E4C:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// li r5,152
	ctx.r5.s64 = 152;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x823da950
	ctx.lr = 0x824F2E64;
	sub_823DA950(ctx, base);
	// lbz r9,231(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 231);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r9,280(r31)
	PPC_STORE_U8(r31.u32 + 280, ctx.r9.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F2E78"))) PPC_WEAK_FUNC(sub_824F2E78);
PPC_FUNC_IMPL(__imp__sub_824F2E78) {
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
	ctx.lr = 0x824F2E80;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r31,184
	r30.s64 = r31.s64 + 184;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F2EAC;
	sub_8244D150(ctx, base);
	// stw r26,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r26.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824F2EC0;
	sub_8244D5C0(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r31,r28
	ctx.r9.s64 = r28.s64 - r31.s64;
loc_824F2ED0:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f2ee8
	if (cr6.eq) goto loc_824F2EE8;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f2ed0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F2ED0;
loc_824F2EE8:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// li r5,152
	ctx.r5.s64 = 152;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824F2F00;
	sub_823DA950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F2F0C"))) PPC_WEAK_FUNC(sub_824F2F0C);
PPC_FUNC_IMPL(__imp__sub_824F2F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F2F10"))) PPC_WEAK_FUNC(sub_824F2F10);
PPC_FUNC_IMPL(__imp__sub_824F2F10) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x824F2F18;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// std r10,0(r31)
	PPC_STORE_U64(r31.u32 + 0, ctx.r10.u64);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// std r9,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r9.u64);
	// bl 0x8244d150
	ctx.lr = 0x824F2F68;
	sub_8244D150(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r8,15
	ctx.r8.s64 = 15;
loc_824F2F74:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f3004
	if (cr6.eq) goto loc_824F3004;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2fe8
	if (cr6.eq) goto loc_824F2FE8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2ff0
	if (cr6.eq) goto loc_824F2FF0;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f2ff8
	if (cr6.eq) goto loc_824F2FF8;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f3000
	if (cr6.eq) goto loc_824F3000;
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
	// bgt 0x824f2f74
	if (cr0.gt) goto loc_824F2F74;
	// b 0x824f3004
	goto loc_824F3004;
loc_824F2FE8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x824f3004
	goto loc_824F3004;
loc_824F2FF0:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x824f3004
	goto loc_824F3004;
loc_824F2FF8:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x824f3004
	goto loc_824F3004;
loc_824F3000:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_824F3004:
	// li r29,0
	r29.s64 = 0;
	// li r5,12
	ctx.r5.s64 = 12;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r27.u32);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8244d150
	ctx.lr = 0x824F3020;
	sub_8244D150(ctx, base);
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F3034;
	sub_8244D150(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r28,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r28.u32);
	// beq cr6,0x824f3078
	if (cr6.eq) goto loc_824F3078;
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// subf r8,r26,r25
	ctx.r8.s64 = r25.s64 - r26.s64;
loc_824F3050:
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r7.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// blt cr6,0x824f3050
	if (cr6.lt) goto loc_824F3050;
loc_824F3078:
	// lwz r11,252(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// stfs f31,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stw r24,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r24.u32);
	// addi r30,r31,76
	r30.s64 = r31.s64 + 76;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// bl 0x8244d150
	ctx.lr = 0x824F309C;
	sub_8244D150(ctx, base);
	// lwz r4,260(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// stw r29,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r29.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f30c0
	if (cr6.eq) goto loc_824F30C0;
	// lwz r29,268(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824F30BC;
	sub_8244D5C0(ctx, base);
	// stw r29,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r29.u32);
loc_824F30C0:
	// lbz r11,279(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 279);
	// stb r11,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F30D4"))) PPC_WEAK_FUNC(sub_824F30D4);
PPC_FUNC_IMPL(__imp__sub_824F30D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F30D8"))) PPC_WEAK_FUNC(sub_824F30D8);
PPC_FUNC_IMPL(__imp__sub_824F30D8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x824F30E0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x824f94e0
	ctx.lr = 0x824F3100;
	sub_824F94E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F3114;
	sub_82618750(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r5,r11,r30
	ctx.r5.s64 = r30.s64 - r11.s64;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// bl 0x82618640
	ctx.lr = 0x824F3128;
	sub_82618640(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r28,16
	ctx.r4.s64 = r28.s64 + 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82619080
	ctx.lr = 0x824F3138;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,32(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8226b338
	ctx.lr = 0x824F3154;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r30,36(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824F3174;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f31ac
	if (cr6.eq) goto loc_824F31AC;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824F319C;
	sub_82618390(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826188b8
	ctx.lr = 0x824F31A8;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F31AC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r30,64(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824F31CC;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3204
	if (cr6.eq) goto loc_824F3204;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824F31F4;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826188b8
	ctx.lr = 0x824F3200;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F3204:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f1,68(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82618df0
	ctx.lr = 0x824F321C;
	sub_82618DF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r30,72(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824F323C;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3274
	if (cr6.eq) goto loc_824F3274;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824F3264;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826188b8
	ctx.lr = 0x824F3270;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F3274:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r30,140(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 140);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824F3294;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f32cc
	if (cr6.eq) goto loc_824F32CC;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,7
	ctx.r5.s64 = 7;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824F32BC;
	sub_82618390(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826188b8
	ctx.lr = 0x824F32C8;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F32CC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r4,6
	ctx.r4.s64 = 6;
	// lbz r30,144(r28)
	r30.u64 = PPC_LOAD_U8(r28.u32 + 144);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824F32EC;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3324
	if (cr6.eq) goto loc_824F3324;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824F3314;
	sub_82618390(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826188b8
	ctx.lr = 0x824F3320;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F3324:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// lwz r11,36(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824f33cc
	if (!cr6.gt) goto loc_824F33CC;
	// addi r29,r28,52
	r29.s64 = r28.s64 + 52;
loc_824F3344:
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,-12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -12);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8226b338
	ctx.lr = 0x824F3354;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824F3374;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f33ac
	if (cr6.eq) goto loc_824F33AC;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824F339C;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826188b8
	ctx.lr = 0x824F33A8;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F33AC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
	// lwz r11,36(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824f3344
	if (cr6.lt) goto loc_824F3344;
loc_824F33CC:
	// lwz r5,140(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 140);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f33f0
	if (cr6.eq) goto loc_824F33F0;
	// addi r4,r28,76
	ctx.r4.s64 = r28.s64 + 76;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618f90
	ctx.lr = 0x824F33E4;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3400
	if (cr6.eq) goto loc_824F3400;
loc_824F33F0:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186a0
	ctx.lr = 0x824F33F8;
	sub_826186A0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r26,r3,r11
	r26.u64 = ctx.r3.u64 + r11.u64;
loc_824F3400:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824f340c
	if (cr6.eq) goto loc_824F340C;
	// stw r26,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r26.u32);
loc_824F340C:
	// subfic r11,r26,0
	xer.ca = r26.u32 <= 0;
	r11.s64 = 0 - r26.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F3420"))) PPC_WEAK_FUNC(sub_824F3420);
PPC_FUNC_IMPL(__imp__sub_824F3420) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x824F3428;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x824f95d0
	ctx.lr = 0x824F3448;
	sub_824F95D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F345C;
	sub_82618750(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r5,r11,r30
	ctx.r5.s64 = r30.s64 - r11.s64;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// bl 0x826185e0
	ctx.lr = 0x824F3470;
	sub_826185E0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r27,16
	ctx.r4.s64 = r27.s64 + 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618fa0
	ctx.lr = 0x824F3480;
	sub_82618FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F34A0;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f34e0
	if (cr6.eq) goto loc_824F34E0;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F34C8;
	sub_82618318(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x826188d8
	ctx.lr = 0x824F34D8;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f34e4
	goto loc_824F34E4;
loc_824F34E0:
	// mr r29,r25
	r29.u64 = r25.u64;
loc_824F34E4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3554
	if (cr6.eq) goto loc_824F3554;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F3500;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3540
	if (cr6.eq) goto loc_824F3540;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,31
	ctx.r5.s64 = 31;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F3528;
	sub_82618318(ctx, base);
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,88(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x826188d8
	ctx.lr = 0x824F3538;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f3544
	goto loc_824F3544;
loc_824F3540:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824F3544:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f3558
	if (!cr6.eq) goto loc_824F3558;
loc_824F3554:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_824F3558:
	// neg r10,r29
	ctx.r10.s64 = -r29.s64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// xor r11,r10,r30
	r11.u64 = ctx.r10.u64 ^ r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// stw r8,32(r27)
	PPC_STORE_U32(r27.u32 + 32, ctx.r8.u32);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F3584;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f35c8
	if (cr6.eq) goto loc_824F35C8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F35AC;
	sub_82618318(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,36(r27)
	PPC_STORE_U32(r27.u32 + 36, r11.u32);
	// bl 0x826188d8
	ctx.lr = 0x824F35C0;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f35cc
	goto loc_824F35CC;
loc_824F35C8:
	// stw r25,36(r27)
	PPC_STORE_U32(r27.u32 + 36, r25.u32);
loc_824F35CC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F35E8;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f362c
	if (cr6.eq) goto loc_824F362C;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F3610;
	sub_82618318(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,64(r27)
	PPC_STORE_U32(r27.u32 + 64, r11.u32);
	// bl 0x826188d8
	ctx.lr = 0x824F3624;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f3630
	goto loc_824F3630;
loc_824F362C:
	// stw r25,64(r27)
	PPC_STORE_U32(r27.u32 + 64, r25.u32);
loc_824F3630:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// addi r4,r27,68
	ctx.r4.s64 = r27.s64 + 68;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618db0
	ctx.lr = 0x824F3648;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F3664;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f36a8
	if (cr6.eq) goto loc_824F36A8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F368C;
	sub_82618318(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,72(r27)
	PPC_STORE_U32(r27.u32 + 72, r11.u32);
	// bl 0x826188d8
	ctx.lr = 0x824F36A0;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f36ac
	goto loc_824F36AC;
loc_824F36A8:
	// stw r25,72(r27)
	PPC_STORE_U32(r27.u32 + 72, r25.u32);
loc_824F36AC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F36C8;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f370c
	if (cr6.eq) goto loc_824F370C;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,7
	ctx.r5.s64 = 7;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F36F0;
	sub_82618318(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,140(r27)
	PPC_STORE_U32(r27.u32 + 140, r11.u32);
	// bl 0x826188d8
	ctx.lr = 0x824F3704;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f3710
	goto loc_824F3710;
loc_824F370C:
	// stw r25,140(r27)
	PPC_STORE_U32(r27.u32 + 140, r25.u32);
loc_824F3710:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F372C;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3770
	if (cr6.eq) goto loc_824F3770;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F3754;
	sub_82618318(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,144(r27)
	PPC_STORE_U8(r27.u32 + 144, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824F3768;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f3774
	goto loc_824F3774;
loc_824F3770:
	// stb r25,144(r27)
	PPC_STORE_U8(r27.u32 + 144, r25.u8);
loc_824F3774:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// mr r26,r25
	r26.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824f38f4
	if (!cr6.gt) goto loc_824F38F4;
	// addi r28,r27,52
	r28.s64 = r27.s64 + 52;
loc_824F3794:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F37A8;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f37e8
	if (cr6.eq) goto loc_824F37E8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F37D0;
	sub_82618318(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x826188d8
	ctx.lr = 0x824F37E0;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f37ec
	goto loc_824F37EC;
loc_824F37E8:
	// mr r29,r25
	r29.u64 = r25.u64;
loc_824F37EC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f385c
	if (cr6.eq) goto loc_824F385C;
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F3808;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3848
	if (cr6.eq) goto loc_824F3848;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,31
	ctx.r5.s64 = 31;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F3830;
	sub_82618318(ctx, base);
	// li r4,31
	ctx.r4.s64 = 31;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x826188d8
	ctx.lr = 0x824F3840;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f384c
	goto loc_824F384C;
loc_824F3848:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824F384C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f3860
	if (!cr6.eq) goto loc_824F3860;
loc_824F385C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_824F3860:
	// neg r10,r29
	ctx.r10.s64 = -r29.s64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// xor r11,r10,r30
	r11.u64 = ctx.r10.u64 ^ r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// stw r8,-12(r28)
	PPC_STORE_U32(r28.u32 + -12, ctx.r8.u32);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F388C;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f38d0
	if (cr6.eq) goto loc_824F38D0;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824F38B4;
	sub_82618318(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// bl 0x826188d8
	ctx.lr = 0x824F38C8;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824f38d4
	goto loc_824F38D4;
loc_824F38D0:
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
loc_824F38D4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x824f3794
	if (cr6.lt) goto loc_824F3794;
loc_824F38F4:
	// lwz r5,140(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 140);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f3918
	if (cr6.eq) goto loc_824F3918;
	// addi r4,r27,76
	ctx.r4.s64 = r27.s64 + 76;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618f80
	ctx.lr = 0x824F390C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3928
	if (cr6.eq) goto loc_824F3928;
loc_824F3918:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F3920;
	sub_826186B0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r25,r3,r11
	r25.u64 = ctx.r3.u64 + r11.u64;
loc_824F3928:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824f3934
	if (cr6.eq) goto loc_824F3934;
	// stw r25,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r25.u32);
loc_824F3934:
	// subfic r11,r25,0
	xer.ca = r25.u32 <= 0;
	r11.s64 = 0 - r25.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F3948"))) PPC_WEAK_FUNC(sub_824F3948);
PPC_FUNC_IMPL(__imp__sub_824F3948) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824F3950;
	// lwz r30,124(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lis r29,-32249
	r29.s64 = -2113470464;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r28,8
	r28.s64 = 8;
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r29,r29,27568
	r29.s64 = r29.s64 + 27568;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r6,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r6.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r4,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r4.u32);
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lbz r6,103(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r4,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r8,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
	// stw r9,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r27,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r27.u32);
	// stw r28,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r28.u32);
	// stb r6,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, ctx.r6.u8);
	// stw r5,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r5.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// beq cr6,0x824f39f0
	if (cr6.eq) goto loc_824F39F0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_824F39F0:
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F39F4"))) PPC_WEAK_FUNC(sub_824F39F4);
PPC_FUNC_IMPL(__imp__sub_824F39F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F39F8"))) PPC_WEAK_FUNC(sub_824F39F8);
PPC_FUNC_IMPL(__imp__sub_824F39F8) {
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
	ctx.lr = 0x824F3A00;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// lwz r10,252(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r8,9
	ctx.r8.s64 = 9;
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r7,r9,27576
	ctx.r7.s64 = ctx.r9.s64 + 27576;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r4,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r4.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,152
	ctx.r5.s64 = 152;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x823da950
	ctx.lr = 0x824F3A5C;
	sub_823DA950(ctx, base);
	// lwz r11,244(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// lbz r6,231(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 231);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,236(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r29.u32);
	// stw r28,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r28.u32);
	// stw r27,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r27.u32);
	// stw r26,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r26.u32);
	// stw r25,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r25.u32);
	// stb r6,196(r31)
	PPC_STORE_U8(r31.u32 + 196, ctx.r6.u8);
	// stw r5,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r5.u32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// beq cr6,0x824f3aa0
	if (cr6.eq) goto loc_824F3AA0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_824F3AA0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F3AA8"))) PPC_WEAK_FUNC(sub_824F3AA8);
PPC_FUNC_IMPL(__imp__sub_824F3AA8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,27468
	ctx.r9.s64 = r11.s64 + 27468;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824f3adc
	if (cr6.eq) goto loc_824F3ADC;
	// bl 0x82130588
	ctx.lr = 0x824F3AD8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824F3ADC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F3AF0"))) PPC_WEAK_FUNC(sub_824F3AF0);
PPC_FUNC_IMPL(__imp__sub_824F3AF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r9,10
	ctx.r9.s64 = 10;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r10,27584
	ctx.r10.s64 = ctx.r10.s64 + 27584;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stw r6,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r6.u32);
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// stw r8,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r8.u32);
	// beq cr6,0x824f3b34
	if (cr6.eq) goto loc_824F3B34;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
loc_824F3B34:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F3B50"))) PPC_WEAK_FUNC(sub_824F3B50);
PPC_FUNC_IMPL(__imp__sub_824F3B50) {
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
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x824e6a38
	ctx.lr = 0x824F3B6C;
	sub_824E6A38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3b98
	if (cr6.eq) goto loc_824F3B98;
	// bl 0x821c9788
	ctx.lr = 0x824F3B7C;
	sub_821C9788(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,32216(r11)
	PPC_STORE_U32(r11.u32 + 32216, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824F3B98:
	// addi r31,r31,124
	r31.s64 = r31.s64 + 124;
	// li r11,-1
	r11.s64 = -1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f3be8
	if (cr6.eq) goto loc_824F3BE8;
	// bl 0x821c9788
	ctx.lr = 0x824F3BC4;
	sub_821C9788(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// ori r9,r10,37856
	ctx.r9.u64 = ctx.r10.u64 | 37856;
	// lwz r11,32216(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32216);
	// subf r8,r11,r3
	ctx.r8.s64 = ctx.r3.s64 - r11.s64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// blt cr6,0x824f3be8
	if (cr6.lt) goto loc_824F3BE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2448
	ctx.lr = 0x824F3BE8;
	sub_824F2448(ctx, base);
loc_824F3BE8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F3BFC"))) PPC_WEAK_FUNC(sub_824F3BFC);
PPC_FUNC_IMPL(__imp__sub_824F3BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F3C00"))) PPC_WEAK_FUNC(sub_824F3C00);
PPC_FUNC_IMPL(__imp__sub_824F3C00) {
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
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F3C2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824f3c78
	if (!cr6.eq) goto loc_824F3C78;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r31,r30,124
	r31.s64 = r30.s64 + 124;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f3c78
	if (cr6.eq) goto loc_824F3C78;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f24b0
	ctx.lr = 0x824F3C64;
	sub_824F24B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f3c78
	if (!cr6.eq) goto loc_824F3C78;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2448
	ctx.lr = 0x824F3C78;
	sub_824F2448(ctx, base);
loc_824F3C78:
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

__attribute__((alias("__imp__sub_824F3C90"))) PPC_WEAK_FUNC(sub_824F3C90);
PPC_FUNC_IMPL(__imp__sub_824F3C90) {
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
	ctx.lr = 0x824F3C98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x824f2a88
	ctx.lr = 0x824F3CC4;
	sub_824F2A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3d4c
	if (cr6.eq) goto loc_824F3D4C;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f3ce4
	if (cr6.eq) goto loc_824F3CE4;
	// bl 0x82130588
	ctx.lr = 0x824F3CE0;
	sub_82130588(ctx, base);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
loc_824F3CE4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130528
	ctx.lr = 0x824F3CEC;
	sub_82130528(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// stw r5,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r5.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f3d4c
	if (cr6.eq) goto loc_824F3D4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x824f2a88
	ctx.lr = 0x824F3D0C;
	sub_824F2A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3d4c
	if (cr6.eq) goto loc_824F3D4C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82257678
	ctx.lr = 0x824F3D28;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f3d4c
	if (cr6.eq) goto loc_824F3D4C;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824F3D4C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F3D58"))) PPC_WEAK_FUNC(sub_824F3D58);
PPC_FUNC_IMPL(__imp__sub_824F3D58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824f3da8
	if (!cr6.eq) goto loc_824F3DA8;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f3d94
	if (cr6.eq) goto loc_824F3D94;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824F3D94:
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
loc_824F3DA8:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824f3de4
	if (!cr6.eq) goto loc_824F3DE4;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f3e08
	if (cr6.eq) goto loc_824F3E08;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824F3DE4:
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r7,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r7.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
loc_824F3E08:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F3E18"))) PPC_WEAK_FUNC(sub_824F3E18);
PPC_FUNC_IMPL(__imp__sub_824F3E18) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F3E3C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3e84
	if (cr6.eq) goto loc_824F3E84;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F3E58;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3e84
	if (cr6.eq) goto loc_824F3E84;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,36
	ctx.r4.s64 = r30.s64 + 36;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F3E74;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f3e88
	if (!cr6.eq) goto loc_824F3E88;
loc_824F3E84:
	// li r11,0
	r11.s64 = 0;
loc_824F3E88:
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

__attribute__((alias("__imp__sub_824F3EA4"))) PPC_WEAK_FUNC(sub_824F3EA4);
PPC_FUNC_IMPL(__imp__sub_824F3EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F3EA8"))) PPC_WEAK_FUNC(sub_824F3EA8);
PPC_FUNC_IMPL(__imp__sub_824F3EA8) {
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
	// bl 0x82618f10
	ctx.lr = 0x824F3EC8;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3f10
	if (cr6.eq) goto loc_824F3F10;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275750
	ctx.lr = 0x824F3EE4;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3f10
	if (cr6.eq) goto loc_824F3F10;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x824F3F00;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f3f14
	if (!cr6.eq) goto loc_824F3F14;
loc_824F3F10:
	// li r11,0
	r11.s64 = 0;
loc_824F3F14:
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

__attribute__((alias("__imp__sub_824F3F30"))) PPC_WEAK_FUNC(sub_824F3F30);
PPC_FUNC_IMPL(__imp__sub_824F3F30) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F3F54;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f3f7c
	if (cr6.eq) goto loc_824F3F7C;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa208
	ctx.lr = 0x824F3F6C;
	sub_824FA208(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f3f80
	if (!cr6.eq) goto loc_824F3F80;
loc_824F3F7C:
	// li r11,0
	r11.s64 = 0;
loc_824F3F80:
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

__attribute__((alias("__imp__sub_824F3F9C"))) PPC_WEAK_FUNC(sub_824F3F9C);
PPC_FUNC_IMPL(__imp__sub_824F3F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F3FA0"))) PPC_WEAK_FUNC(sub_824F3FA0);
PPC_FUNC_IMPL(__imp__sub_824F3FA0) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F3FC4;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4008
	if (cr6.eq) goto loc_824F4008;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa208
	ctx.lr = 0x824F3FDC;
	sub_824FA208(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4008
	if (cr6.eq) goto loc_824F4008;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,48
	ctx.r4.s64 = r30.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F3FF8;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f400c
	if (!cr6.eq) goto loc_824F400C;
loc_824F4008:
	// li r11,0
	r11.s64 = 0;
loc_824F400C:
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

__attribute__((alias("__imp__sub_824F4028"))) PPC_WEAK_FUNC(sub_824F4028);
PPC_FUNC_IMPL(__imp__sub_824F4028) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F404C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f40b0
	if (cr6.eq) goto loc_824F40B0;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F4068;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f40b0
	if (cr6.eq) goto loc_824F40B0;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,36
	ctx.r4.s64 = r30.s64 + 36;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F4084;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f40b0
	if (cr6.eq) goto loc_824F40B0;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,40
	ctx.r4.s64 = r30.s64 + 40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F40A0;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f40b4
	if (!cr6.eq) goto loc_824F40B4;
loc_824F40B0:
	// li r11,0
	r11.s64 = 0;
loc_824F40B4:
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

__attribute__((alias("__imp__sub_824F40D0"))) PPC_WEAK_FUNC(sub_824F40D0);
PPC_FUNC_IMPL(__imp__sub_824F40D0) {
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
	ctx.lr = 0x824F40D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f10
	ctx.lr = 0x824F40E8;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f419c
	if (cr6.eq) goto loc_824F419C;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82275750
	ctx.lr = 0x824F4104;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f419c
	if (cr6.eq) goto loc_824F419C;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4190
	if (cr6.eq) goto loc_824F4190;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82257568
	ctx.lr = 0x824F412C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f419c
	if (cr6.eq) goto loc_824F419C;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x824f419c
	if (cr6.gt) goto loc_824F419C;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4190
	if (cr6.eq) goto loc_824F4190;
	// li r31,0
	r31.s64 = 0;
loc_824F415C:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// bl 0x824fa5c8
	ctx.lr = 0x824F416C;
	sub_824FA5C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f419c
	if (cr6.eq) goto loc_824F419C;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,152
	r31.s64 = r31.s64 + 152;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x824f415c
	if (cr6.lt) goto loc_824F415C;
loc_824F4190:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824F419C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F41A8"))) PPC_WEAK_FUNC(sub_824F41A8);
PPC_FUNC_IMPL(__imp__sub_824F41A8) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F41CC;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4248
	if (cr6.eq) goto loc_824F4248;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa208
	ctx.lr = 0x824F41E4;
	sub_824FA208(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4248
	if (cr6.eq) goto loc_824F4248;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,48
	ctx.r4.s64 = r30.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F4200;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4248
	if (cr6.eq) goto loc_824F4248;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,52
	ctx.r4.s64 = r30.s64 + 52;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F421C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4248
	if (cr6.eq) goto loc_824F4248;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,56
	ctx.r4.s64 = r30.s64 + 56;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F4238;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f424c
	if (!cr6.eq) goto loc_824F424C;
loc_824F4248:
	// li r11,0
	r11.s64 = 0;
loc_824F424C:
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

__attribute__((alias("__imp__sub_824F4268"))) PPC_WEAK_FUNC(sub_824F4268);
PPC_FUNC_IMPL(__imp__sub_824F4268) {
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
	ctx.lr = 0x824F4270;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82618f10
	ctx.lr = 0x824F4280;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4300
	if (cr6.eq) goto loc_824F4300;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82275750
	ctx.lr = 0x824F429C;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4300
	if (cr6.eq) goto loc_824F4300;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f42f4
	if (cr6.eq) goto loc_824F42F4;
	// addi r29,r31,160
	r29.s64 = r31.s64 + 160;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x824F42C8;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4300
	if (cr6.eq) goto loc_824F4300;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f42f4
	if (cr6.eq) goto loc_824F42F4;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa5c8
	ctx.lr = 0x824F42EC;
	sub_824FA5C8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F42F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F4300:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F430C"))) PPC_WEAK_FUNC(sub_824F430C);
PPC_FUNC_IMPL(__imp__sub_824F430C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4310"))) PPC_WEAK_FUNC(sub_824F4310);
PPC_FUNC_IMPL(__imp__sub_824F4310) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F4334;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4360
	if (cr6.eq) goto loc_824F4360;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226b338
	ctx.lr = 0x824F4350;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f4364
	if (!cr6.eq) goto loc_824F4364;
loc_824F4360:
	// li r11,0
	r11.s64 = 0;
loc_824F4364:
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

__attribute__((alias("__imp__sub_824F4380"))) PPC_WEAK_FUNC(sub_824F4380);
PPC_FUNC_IMPL(__imp__sub_824F4380) {
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
	ctx.lr = 0x824F4388;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82618f10
	ctx.lr = 0x824F4398;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4418
	if (cr6.eq) goto loc_824F4418;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82275750
	ctx.lr = 0x824F43B4;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4418
	if (cr6.eq) goto loc_824F4418;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f440c
	if (cr6.eq) goto loc_824F440C;
	// addi r29,r31,160
	r29.s64 = r31.s64 + 160;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x824F43E0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4418
	if (cr6.eq) goto loc_824F4418;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f440c
	if (cr6.eq) goto loc_824F440C;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa5c8
	ctx.lr = 0x824F4404;
	sub_824FA5C8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F440C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F4418:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F4424"))) PPC_WEAK_FUNC(sub_824F4424);
PPC_FUNC_IMPL(__imp__sub_824F4424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4428"))) PPC_WEAK_FUNC(sub_824F4428);
PPC_FUNC_IMPL(__imp__sub_824F4428) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F444C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4490
	if (cr6.eq) goto loc_824F4490;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa5d0
	ctx.lr = 0x824F4464;
	sub_824FA5D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4490
	if (cr6.eq) goto loc_824F4490;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,184
	ctx.r4.s64 = r30.s64 + 184;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822525b0
	ctx.lr = 0x824F4480;
	sub_822525B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f4494
	if (!cr6.eq) goto loc_824F4494;
loc_824F4490:
	// li r11,0
	r11.s64 = 0;
loc_824F4494:
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

__attribute__((alias("__imp__sub_824F44B0"))) PPC_WEAK_FUNC(sub_824F44B0);
PPC_FUNC_IMPL(__imp__sub_824F44B0) {
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
	// bl 0x82618f10
	ctx.lr = 0x824F44D0;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4530
	if (cr6.eq) goto loc_824F4530;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275750
	ctx.lr = 0x824F44EC;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4530
	if (cr6.eq) goto loc_824F4530;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x824F4508;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4530
	if (cr6.eq) goto loc_824F4530;
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618db0
	ctx.lr = 0x824F4520;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f4534
	if (!cr6.eq) goto loc_824F4534;
loc_824F4530:
	// li r11,0
	r11.s64 = 0;
loc_824F4534:
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

__attribute__((alias("__imp__sub_824F4550"))) PPC_WEAK_FUNC(sub_824F4550);
PPC_FUNC_IMPL(__imp__sub_824F4550) {
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
	// bl 0x82618f10
	ctx.lr = 0x824F4570;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f459c
	if (cr6.eq) goto loc_824F459C;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275750
	ctx.lr = 0x824F458C;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f45a0
	if (!cr6.eq) goto loc_824F45A0;
loc_824F459C:
	// li r11,0
	r11.s64 = 0;
loc_824F45A0:
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

__attribute__((alias("__imp__sub_824F45BC"))) PPC_WEAK_FUNC(sub_824F45BC);
PPC_FUNC_IMPL(__imp__sub_824F45BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F45C0"))) PPC_WEAK_FUNC(sub_824F45C0);
PPC_FUNC_IMPL(__imp__sub_824F45C0) {
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
	ctx.lr = 0x824F45C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F45DC;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r29,32
	ctx.r4.s64 = r29.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F45F8;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// addi r4,r29,40
	ctx.r4.s64 = r29.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa208
	ctx.lr = 0x824F4610;
	sub_824FA208(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r29,56
	ctx.r4.s64 = r29.s64 + 56;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82619080
	ctx.lr = 0x824F462C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// addi r27,r29,72
	r27.s64 = r29.s64 + 72;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F464C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// addi r24,r29,164
	r24.s64 = r29.s64 + 164;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F466C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r29,168
	ctx.r4.s64 = r29.s64 + 168;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822525b0
	ctx.lr = 0x824F4688;
	sub_822525B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824f4730
	if (!cr6.gt) goto loc_824F4730;
	// addi r31,r29,88
	r31.s64 = r29.s64 + 88;
	// lis r25,16
	r25.s64 = 1048576;
	// li r26,1
	r26.s64 = 1;
loc_824F46B0:
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F46C0;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f471c
	if (cr6.eq) goto loc_824F471C;
	// lwz r11,-12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4700
	if (!cr6.eq) goto loc_824F4700;
	// cmplw cr6,r3,r25
	cr6.compare<uint32_t>(ctx.r3.u32, r25.u32, xer);
	// bgt cr6,0x824f4760
	if (cr6.gt) goto loc_824F4760;
	// bl 0x82130528
	ctx.lr = 0x824F46F0;
	sub_82130528(ctx, base);
	// stw r3,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
	// stb r26,169(r29)
	PPC_STORE_U8(r29.u32 + 169, r26.u8);
loc_824F4700:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,-12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// bl 0x82618f90
	ctx.lr = 0x824F4710;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
loc_824F471C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x824f46b0
	if (cr6.lt) goto loc_824F46B0;
loc_824F4730:
	// lwz r5,0(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f4754
	if (cr6.eq) goto loc_824F4754;
	// addi r4,r29,100
	ctx.r4.s64 = r29.s64 + 100;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x824F4748;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4760
	if (cr6.eq) goto loc_824F4760;
loc_824F4754:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824F4760:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F476C"))) PPC_WEAK_FUNC(sub_824F476C);
PPC_FUNC_IMPL(__imp__sub_824F476C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4770"))) PPC_WEAK_FUNC(sub_824F4770);
PPC_FUNC_IMPL(__imp__sub_824F4770) {
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
	// bl 0x82618f10
	ctx.lr = 0x824F4790;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f47dc
	if (cr6.eq) goto loc_824F47DC;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82275750
	ctx.lr = 0x824F47AC;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f47dc
	if (cr6.eq) goto loc_824F47DC;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f47d4
	if (cr6.eq) goto loc_824F47D4;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa5c8
	ctx.lr = 0x824F47D0;
	sub_824FA5C8(ctx, base);
	// b 0x824f47e0
	goto loc_824F47E0;
loc_824F47D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824f47e0
	goto loc_824F47E0;
loc_824F47DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824F47E0:
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

__attribute__((alias("__imp__sub_824F47F8"))) PPC_WEAK_FUNC(sub_824F47F8);
PPC_FUNC_IMPL(__imp__sub_824F47F8) {
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
	ctx.lr = 0x824F4800;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82619080
	ctx.lr = 0x824F4814;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// addi r4,r28,32
	ctx.r4.s64 = r28.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa5d0
	ctx.lr = 0x824F482C;
	sub_824FA5D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// addi r27,r28,184
	r27.s64 = r28.s64 + 184;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F484C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// addi r24,r28,276
	r24.s64 = r28.s64 + 276;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F486C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r28,280
	ctx.r4.s64 = r28.s64 + 280;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822525b0
	ctx.lr = 0x824F4888;
	sub_822525B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824f4930
	if (!cr6.gt) goto loc_824F4930;
	// addi r31,r28,200
	r31.s64 = r28.s64 + 200;
	// lis r25,16
	r25.s64 = 1048576;
	// li r26,1
	r26.s64 = 1;
loc_824F48B0:
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824F48C0;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f491c
	if (cr6.eq) goto loc_824F491C;
	// lwz r11,-12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4900
	if (!cr6.eq) goto loc_824F4900;
	// cmplw cr6,r3,r25
	cr6.compare<uint32_t>(ctx.r3.u32, r25.u32, xer);
	// bgt cr6,0x824f4960
	if (cr6.gt) goto loc_824F4960;
	// bl 0x82130528
	ctx.lr = 0x824F48F0;
	sub_82130528(ctx, base);
	// stw r3,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
	// stb r26,281(r28)
	PPC_STORE_U8(r28.u32 + 281, r26.u8);
loc_824F4900:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,-12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// bl 0x82618f90
	ctx.lr = 0x824F4910;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
loc_824F491C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824f48b0
	if (cr6.lt) goto loc_824F48B0;
loc_824F4930:
	// lwz r5,0(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f4954
	if (cr6.eq) goto loc_824F4954;
	// addi r4,r28,212
	ctx.r4.s64 = r28.s64 + 212;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x824F4948;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4960
	if (cr6.eq) goto loc_824F4960;
loc_824F4954:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824F4960:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F496C"))) PPC_WEAK_FUNC(sub_824F496C);
PPC_FUNC_IMPL(__imp__sub_824F496C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4970"))) PPC_WEAK_FUNC(sub_824F4970);
PPC_FUNC_IMPL(__imp__sub_824F4970) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8226b338
	ctx.lr = 0x824F4998;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f49c4
	if (cr6.eq) goto loc_824F49C4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F49B4;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f49c8
	if (!cr6.eq) goto loc_824F49C8;
loc_824F49C4:
	// li r11,0
	r11.s64 = 0;
loc_824F49C8:
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

__attribute__((alias("__imp__sub_824F49E4"))) PPC_WEAK_FUNC(sub_824F49E4);
PPC_FUNC_IMPL(__imp__sub_824F49E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F49E8"))) PPC_WEAK_FUNC(sub_824F49E8);
PPC_FUNC_IMPL(__imp__sub_824F49E8) {
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
	ctx.lr = 0x824F49F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618f10
	ctx.lr = 0x824F4A00;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4a78
	if (cr6.eq) goto loc_824F4A78;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82275750
	ctx.lr = 0x824F4A1C;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4a78
	if (cr6.eq) goto loc_824F4A78;
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82257568
	ctx.lr = 0x824F4A3C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4a78
	if (cr6.eq) goto loc_824F4A78;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f4a6c
	if (cr6.eq) goto loc_824F4A6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82618f80
	ctx.lr = 0x824F4A60;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4a78
	if (cr6.eq) goto loc_824F4A78;
loc_824F4A6C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F4A78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F4A84"))) PPC_WEAK_FUNC(sub_824F4A84);
PPC_FUNC_IMPL(__imp__sub_824F4A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4A88"))) PPC_WEAK_FUNC(sub_824F4A88);
PPC_FUNC_IMPL(__imp__sub_824F4A88) {
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
	ctx.lr = 0x824F4A90;
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
	// bl 0x82619080
	ctx.lr = 0x824F4AA4;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4b18
	if (cr6.eq) goto loc_824F4B18;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa5d0
	ctx.lr = 0x824F4ABC;
	sub_824FA5D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4b18
	if (cr6.eq) goto loc_824F4B18;
	// addi r29,r30,248
	r29.s64 = r30.s64 + 248;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x824F4ADC;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4b18
	if (cr6.eq) goto loc_824F4B18;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824f4b0c
	if (cr6.eq) goto loc_824F4B0C;
	// addi r4,r30,184
	ctx.r4.s64 = r30.s64 + 184;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824F4B00;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4b18
	if (cr6.eq) goto loc_824F4B18;
loc_824F4B0C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824F4B18:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F4B24"))) PPC_WEAK_FUNC(sub_824F4B24);
PPC_FUNC_IMPL(__imp__sub_824F4B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4B28"))) PPC_WEAK_FUNC(sub_824F4B28);
PPC_FUNC_IMPL(__imp__sub_824F4B28) {
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
	ctx.lr = 0x824F4B30;
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
	ctx.lr = 0x824F4B54;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F4B60;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F4B70;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f4b94
	if (cr6.eq) goto loc_824F4B94;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f3e18
	ctx.lr = 0x824F4B84;
	sub_824F3E18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4b98
	if (!cr6.eq) goto loc_824F4B98;
loc_824F4B94:
	// li r30,0
	r30.s64 = 0;
loc_824F4B98:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f4bd0
	if (cr6.eq) goto loc_824F4BD0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4bc8
	if (cr6.eq) goto loc_824F4BC8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F4BB4;
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
loc_824F4BC8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F4BD0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F4BDC"))) PPC_WEAK_FUNC(sub_824F4BDC);
PPC_FUNC_IMPL(__imp__sub_824F4BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4BE0"))) PPC_WEAK_FUNC(sub_824F4BE0);
PPC_FUNC_IMPL(__imp__sub_824F4BE0) {
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
	ctx.lr = 0x824F4BE8;
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
	ctx.lr = 0x824F4C0C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F4C18;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F4C28;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f4c4c
	if (cr6.eq) goto loc_824F4C4C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f3f30
	ctx.lr = 0x824F4C3C;
	sub_824F3F30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4c50
	if (!cr6.eq) goto loc_824F4C50;
loc_824F4C4C:
	// li r30,0
	r30.s64 = 0;
loc_824F4C50:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f4c88
	if (cr6.eq) goto loc_824F4C88;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4c80
	if (cr6.eq) goto loc_824F4C80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F4C6C;
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
loc_824F4C80:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F4C88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F4C94"))) PPC_WEAK_FUNC(sub_824F4C94);
PPC_FUNC_IMPL(__imp__sub_824F4C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4C98"))) PPC_WEAK_FUNC(sub_824F4C98);
PPC_FUNC_IMPL(__imp__sub_824F4C98) {
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
	ctx.lr = 0x824F4CA0;
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
	ctx.lr = 0x824F4CD0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F4CDC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F4CEC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f4d1c
	if (cr6.eq) goto loc_824F4D1C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f4d1c
	if (!cr6.eq) goto loc_824F4D1C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f3ea8
	ctx.lr = 0x824F4D0C;
	sub_824F3EA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4d20
	if (!cr6.eq) goto loc_824F4D20;
loc_824F4D1C:
	// li r31,0
	r31.s64 = 0;
loc_824F4D20:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f4d4c
	if (cr6.eq) goto loc_824F4D4C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4d44
	if (cr6.eq) goto loc_824F4D44;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F4D3C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f4d48
	goto loc_824F4D48;
loc_824F4D44:
	// li r11,0
	r11.s64 = 0;
loc_824F4D48:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F4D4C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4d70
	if (cr6.eq) goto loc_824F4D70;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F4D60;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f4d74
	if (cr6.eq) goto loc_824F4D74;
loc_824F4D70:
	// li r11,0
	r11.s64 = 0;
loc_824F4D74:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F4D80"))) PPC_WEAK_FUNC(sub_824F4D80);
PPC_FUNC_IMPL(__imp__sub_824F4D80) {
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
	ctx.lr = 0x824F4D88;
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
	ctx.lr = 0x824F4DAC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F4DB8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F4DC8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f4dec
	if (cr6.eq) goto loc_824F4DEC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f3fa0
	ctx.lr = 0x824F4DDC;
	sub_824F3FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4df0
	if (!cr6.eq) goto loc_824F4DF0;
loc_824F4DEC:
	// li r30,0
	r30.s64 = 0;
loc_824F4DF0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f4e28
	if (cr6.eq) goto loc_824F4E28;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4e20
	if (cr6.eq) goto loc_824F4E20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F4E0C;
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
loc_824F4E20:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F4E28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F4E34"))) PPC_WEAK_FUNC(sub_824F4E34);
PPC_FUNC_IMPL(__imp__sub_824F4E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4E38"))) PPC_WEAK_FUNC(sub_824F4E38);
PPC_FUNC_IMPL(__imp__sub_824F4E38) {
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
	ctx.lr = 0x824F4E40;
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
	ctx.lr = 0x824F4E70;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F4E7C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F4E8C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f4ebc
	if (cr6.eq) goto loc_824F4EBC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f4ebc
	if (!cr6.eq) goto loc_824F4EBC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f40d0
	ctx.lr = 0x824F4EAC;
	sub_824F40D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4ec0
	if (!cr6.eq) goto loc_824F4EC0;
loc_824F4EBC:
	// li r31,0
	r31.s64 = 0;
loc_824F4EC0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f4eec
	if (cr6.eq) goto loc_824F4EEC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4ee4
	if (cr6.eq) goto loc_824F4EE4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F4EDC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f4ee8
	goto loc_824F4EE8;
loc_824F4EE4:
	// li r11,0
	r11.s64 = 0;
loc_824F4EE8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F4EEC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4f10
	if (cr6.eq) goto loc_824F4F10;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F4F00;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f4f14
	if (cr6.eq) goto loc_824F4F14;
loc_824F4F10:
	// li r11,0
	r11.s64 = 0;
loc_824F4F14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F4F20"))) PPC_WEAK_FUNC(sub_824F4F20);
PPC_FUNC_IMPL(__imp__sub_824F4F20) {
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
	ctx.lr = 0x824F4F28;
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
	ctx.lr = 0x824F4F4C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F4F58;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F4F68;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f4f8c
	if (cr6.eq) goto loc_824F4F8C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f4028
	ctx.lr = 0x824F4F7C;
	sub_824F4028(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f4f90
	if (!cr6.eq) goto loc_824F4F90;
loc_824F4F8C:
	// li r30,0
	r30.s64 = 0;
loc_824F4F90:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f4fc8
	if (cr6.eq) goto loc_824F4FC8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f4fc0
	if (cr6.eq) goto loc_824F4FC0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F4FAC;
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
loc_824F4FC0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F4FC8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F4FD4"))) PPC_WEAK_FUNC(sub_824F4FD4);
PPC_FUNC_IMPL(__imp__sub_824F4FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F4FD8"))) PPC_WEAK_FUNC(sub_824F4FD8);
PPC_FUNC_IMPL(__imp__sub_824F4FD8) {
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
	ctx.lr = 0x824F4FE0;
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
	ctx.lr = 0x824F5004;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F5010;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F5020;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f5044
	if (cr6.eq) goto loc_824F5044;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f41a8
	ctx.lr = 0x824F5034;
	sub_824F41A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5048
	if (!cr6.eq) goto loc_824F5048;
loc_824F5044:
	// li r30,0
	r30.s64 = 0;
loc_824F5048:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f5080
	if (cr6.eq) goto loc_824F5080;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5078
	if (cr6.eq) goto loc_824F5078;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F5064;
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
loc_824F5078:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F5080:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F508C"))) PPC_WEAK_FUNC(sub_824F508C);
PPC_FUNC_IMPL(__imp__sub_824F508C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5090"))) PPC_WEAK_FUNC(sub_824F5090);
PPC_FUNC_IMPL(__imp__sub_824F5090) {
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
	ctx.lr = 0x824F5098;
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
	ctx.lr = 0x824F50C8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F50D4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F50E4;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f5114
	if (cr6.eq) goto loc_824F5114;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f5114
	if (!cr6.eq) goto loc_824F5114;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f4268
	ctx.lr = 0x824F5104;
	sub_824F4268(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5118
	if (!cr6.eq) goto loc_824F5118;
loc_824F5114:
	// li r31,0
	r31.s64 = 0;
loc_824F5118:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f5144
	if (cr6.eq) goto loc_824F5144;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f513c
	if (cr6.eq) goto loc_824F513C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5134;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f5140
	goto loc_824F5140;
loc_824F513C:
	// li r11,0
	r11.s64 = 0;
loc_824F5140:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F5144:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5168
	if (cr6.eq) goto loc_824F5168;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5158;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f516c
	if (cr6.eq) goto loc_824F516C;
loc_824F5168:
	// li r11,0
	r11.s64 = 0;
loc_824F516C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F5178"))) PPC_WEAK_FUNC(sub_824F5178);
PPC_FUNC_IMPL(__imp__sub_824F5178) {
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
	ctx.lr = 0x824F5180;
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
	ctx.lr = 0x824F51A4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F51B0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F51C0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f51e4
	if (cr6.eq) goto loc_824F51E4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f4310
	ctx.lr = 0x824F51D4;
	sub_824F4310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f51e8
	if (!cr6.eq) goto loc_824F51E8;
loc_824F51E4:
	// li r30,0
	r30.s64 = 0;
loc_824F51E8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f5220
	if (cr6.eq) goto loc_824F5220;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5218
	if (cr6.eq) goto loc_824F5218;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F5204;
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
loc_824F5218:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F5220:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F522C"))) PPC_WEAK_FUNC(sub_824F522C);
PPC_FUNC_IMPL(__imp__sub_824F522C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5230"))) PPC_WEAK_FUNC(sub_824F5230);
PPC_FUNC_IMPL(__imp__sub_824F5230) {
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
	ctx.lr = 0x824F5238;
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
	ctx.lr = 0x824F5268;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F5274;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F5284;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f52b4
	if (cr6.eq) goto loc_824F52B4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f52b4
	if (!cr6.eq) goto loc_824F52B4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f4380
	ctx.lr = 0x824F52A4;
	sub_824F4380(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f52b8
	if (!cr6.eq) goto loc_824F52B8;
loc_824F52B4:
	// li r31,0
	r31.s64 = 0;
loc_824F52B8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f52e4
	if (cr6.eq) goto loc_824F52E4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f52dc
	if (cr6.eq) goto loc_824F52DC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F52D4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f52e0
	goto loc_824F52E0;
loc_824F52DC:
	// li r11,0
	r11.s64 = 0;
loc_824F52E0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F52E4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5308
	if (cr6.eq) goto loc_824F5308;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F52F8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f530c
	if (cr6.eq) goto loc_824F530C;
loc_824F5308:
	// li r11,0
	r11.s64 = 0;
loc_824F530C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F5318"))) PPC_WEAK_FUNC(sub_824F5318);
PPC_FUNC_IMPL(__imp__sub_824F5318) {
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
	ctx.lr = 0x824F5320;
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
	ctx.lr = 0x824F5344;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F5350;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F5360;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f5384
	if (cr6.eq) goto loc_824F5384;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f4428
	ctx.lr = 0x824F5374;
	sub_824F4428(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5388
	if (!cr6.eq) goto loc_824F5388;
loc_824F5384:
	// li r30,0
	r30.s64 = 0;
loc_824F5388:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f53c0
	if (cr6.eq) goto loc_824F53C0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f53b8
	if (cr6.eq) goto loc_824F53B8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F53A4;
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
loc_824F53B8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F53C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F53CC"))) PPC_WEAK_FUNC(sub_824F53CC);
PPC_FUNC_IMPL(__imp__sub_824F53CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F53D0"))) PPC_WEAK_FUNC(sub_824F53D0);
PPC_FUNC_IMPL(__imp__sub_824F53D0) {
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
	ctx.lr = 0x824F53D8;
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
	ctx.lr = 0x824F5408;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F5414;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F5424;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f5454
	if (cr6.eq) goto loc_824F5454;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f5454
	if (!cr6.eq) goto loc_824F5454;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f44b0
	ctx.lr = 0x824F5444;
	sub_824F44B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5458
	if (!cr6.eq) goto loc_824F5458;
loc_824F5454:
	// li r31,0
	r31.s64 = 0;
loc_824F5458:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f5484
	if (cr6.eq) goto loc_824F5484;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f547c
	if (cr6.eq) goto loc_824F547C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5474;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f5480
	goto loc_824F5480;
loc_824F547C:
	// li r11,0
	r11.s64 = 0;
loc_824F5480:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F5484:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f54a8
	if (cr6.eq) goto loc_824F54A8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5498;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f54ac
	if (cr6.eq) goto loc_824F54AC;
loc_824F54A8:
	// li r11,0
	r11.s64 = 0;
loc_824F54AC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F54B8"))) PPC_WEAK_FUNC(sub_824F54B8);
PPC_FUNC_IMPL(__imp__sub_824F54B8) {
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
	ctx.lr = 0x824F54C0;
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
	ctx.lr = 0x824F54F0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F54FC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F550C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f553c
	if (cr6.eq) goto loc_824F553C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f553c
	if (!cr6.eq) goto loc_824F553C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f4550
	ctx.lr = 0x824F552C;
	sub_824F4550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5540
	if (!cr6.eq) goto loc_824F5540;
loc_824F553C:
	// li r31,0
	r31.s64 = 0;
loc_824F5540:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f556c
	if (cr6.eq) goto loc_824F556C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5564
	if (cr6.eq) goto loc_824F5564;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F555C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f5568
	goto loc_824F5568;
loc_824F5564:
	// li r11,0
	r11.s64 = 0;
loc_824F5568:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F556C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5590
	if (cr6.eq) goto loc_824F5590;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5580;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f5594
	if (cr6.eq) goto loc_824F5594;
loc_824F5590:
	// li r11,0
	r11.s64 = 0;
loc_824F5594:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F55A0"))) PPC_WEAK_FUNC(sub_824F55A0);
PPC_FUNC_IMPL(__imp__sub_824F55A0) {
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
	ctx.lr = 0x824F55A8;
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
	ctx.lr = 0x824F55CC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F55D8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F55E8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f560c
	if (cr6.eq) goto loc_824F560C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f45c0
	ctx.lr = 0x824F55FC;
	sub_824F45C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5610
	if (!cr6.eq) goto loc_824F5610;
loc_824F560C:
	// li r30,0
	r30.s64 = 0;
loc_824F5610:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f5648
	if (cr6.eq) goto loc_824F5648;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5640
	if (cr6.eq) goto loc_824F5640;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F562C;
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
loc_824F5640:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F5648:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F5654"))) PPC_WEAK_FUNC(sub_824F5654);
PPC_FUNC_IMPL(__imp__sub_824F5654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5658"))) PPC_WEAK_FUNC(sub_824F5658);
PPC_FUNC_IMPL(__imp__sub_824F5658) {
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
	ctx.lr = 0x824F5660;
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
	ctx.lr = 0x824F5684;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F5690;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F56A0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f56c4
	if (cr6.eq) goto loc_824F56C4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f47f8
	ctx.lr = 0x824F56B4;
	sub_824F47F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f56c8
	if (!cr6.eq) goto loc_824F56C8;
loc_824F56C4:
	// li r30,0
	r30.s64 = 0;
loc_824F56C8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f5700
	if (cr6.eq) goto loc_824F5700;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f56f8
	if (cr6.eq) goto loc_824F56F8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F56E4;
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
loc_824F56F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F5700:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F570C"))) PPC_WEAK_FUNC(sub_824F570C);
PPC_FUNC_IMPL(__imp__sub_824F570C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5710"))) PPC_WEAK_FUNC(sub_824F5710);
PPC_FUNC_IMPL(__imp__sub_824F5710) {
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
	ctx.lr = 0x824F5718;
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
	ctx.lr = 0x824F573C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F5748;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F5758;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f577c
	if (cr6.eq) goto loc_824F577C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f4970
	ctx.lr = 0x824F576C;
	sub_824F4970(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5780
	if (!cr6.eq) goto loc_824F5780;
loc_824F577C:
	// li r30,0
	r30.s64 = 0;
loc_824F5780:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f57b8
	if (cr6.eq) goto loc_824F57B8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f57b0
	if (cr6.eq) goto loc_824F57B0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F579C;
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
loc_824F57B0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F57B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F57C4"))) PPC_WEAK_FUNC(sub_824F57C4);
PPC_FUNC_IMPL(__imp__sub_824F57C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F57C8"))) PPC_WEAK_FUNC(sub_824F57C8);
PPC_FUNC_IMPL(__imp__sub_824F57C8) {
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
	ctx.lr = 0x824F57D0;
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
	ctx.lr = 0x824F5800;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F580C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F581C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f584c
	if (cr6.eq) goto loc_824F584C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f584c
	if (!cr6.eq) goto loc_824F584C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f49e8
	ctx.lr = 0x824F583C;
	sub_824F49E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5850
	if (!cr6.eq) goto loc_824F5850;
loc_824F584C:
	// li r31,0
	r31.s64 = 0;
loc_824F5850:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f587c
	if (cr6.eq) goto loc_824F587C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5874
	if (cr6.eq) goto loc_824F5874;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F586C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f5878
	goto loc_824F5878;
loc_824F5874:
	// li r11,0
	r11.s64 = 0;
loc_824F5878:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F587C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f58a0
	if (cr6.eq) goto loc_824F58A0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5890;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f58a4
	if (cr6.eq) goto loc_824F58A4;
loc_824F58A0:
	// li r11,0
	r11.s64 = 0;
loc_824F58A4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F58B0"))) PPC_WEAK_FUNC(sub_824F58B0);
PPC_FUNC_IMPL(__imp__sub_824F58B0) {
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
	ctx.lr = 0x824F58B8;
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
	ctx.lr = 0x824F58DC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824F58E8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F58F8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f591c
	if (cr6.eq) goto loc_824F591C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f4a88
	ctx.lr = 0x824F590C;
	sub_824F4A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5920
	if (!cr6.eq) goto loc_824F5920;
loc_824F591C:
	// li r30,0
	r30.s64 = 0;
loc_824F5920:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f5958
	if (cr6.eq) goto loc_824F5958;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5950
	if (cr6.eq) goto loc_824F5950;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F593C;
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
loc_824F5950:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824F5958:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F5964"))) PPC_WEAK_FUNC(sub_824F5964);
PPC_FUNC_IMPL(__imp__sub_824F5964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5968"))) PPC_WEAK_FUNC(sub_824F5968);
PPC_FUNC_IMPL(__imp__sub_824F5968) {
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
	ctx.lr = 0x824F5970;
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
	ctx.lr = 0x824F59A0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824F59AC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F59BC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f59ec
	if (cr6.eq) goto loc_824F59EC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f59ec
	if (!cr6.eq) goto loc_824F59EC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f4770
	ctx.lr = 0x824F59DC;
	sub_824F4770(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f59f0
	if (!cr6.eq) goto loc_824F59F0;
loc_824F59EC:
	// li r31,0
	r31.s64 = 0;
loc_824F59F0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f5a1c
	if (cr6.eq) goto loc_824F5A1C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5a14
	if (cr6.eq) goto loc_824F5A14;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5A0C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824f5a18
	goto loc_824F5A18;
loc_824F5A14:
	// li r11,0
	r11.s64 = 0;
loc_824F5A18:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824F5A1C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5a40
	if (cr6.eq) goto loc_824F5A40;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F5A30;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f5a44
	if (cr6.eq) goto loc_824F5A44;
loc_824F5A40:
	// li r11,0
	r11.s64 = 0;
loc_824F5A44:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F5A50"))) PPC_WEAK_FUNC(sub_824F5A50);
PPC_FUNC_IMPL(__imp__sub_824F5A50) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
	// bl 0x824f9438
	ctx.lr = 0x824F5A78;
	sub_824F9438(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r11,119(r1)
	PPC_STORE_U8(ctx.r1.u32 + 119, r11.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x824f2f10
	ctx.lr = 0x824F5AB8;
	sub_824F2F10(ctx, base);
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

__attribute__((alias("__imp__sub_824F5AD0"))) PPC_WEAK_FUNC(sub_824F5AD0);
PPC_FUNC_IMPL(__imp__sub_824F5AD0) {
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
	ctx.lr = 0x824F5AD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x824e7f88
	ctx.lr = 0x824F5AF8;
	sub_824E7F88(ctx, base);
	// lis r10,-32177
	ctx.r10.s64 = -2108751872;
	// li r28,0
	r28.s64 = 0;
	// addi r9,r10,15360
	ctx.r9.s64 = ctx.r10.s64 + 15360;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x824F5B14;
	sub_82130000(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lbz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 132);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824f5b58
	if (!cr6.eq) goto loc_824F5B58;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r4,r11,27492
	ctx.r4.s64 = r11.s64 + 27492;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824F5B44;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5b58
	if (cr6.eq) goto loc_824F5B58;
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// bne cr6,0x824f5b88
	if (!cr6.eq) goto loc_824F5B88;
loc_824F5B58:
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6a18
	ctx.lr = 0x824F5B64;
	sub_824E6A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5b8c
	if (cr6.eq) goto loc_824F5B8C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F5B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824f5b8c
	goto loc_824F5B8C;
loc_824F5B88:
	// li r28,1
	r28.s64 = 1;
loc_824F5B8C:
	// lbz r11,132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 132);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwimi r11,r28,7,17,24
	r11.u64 = (__builtin_rotateleft32(r28.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
	// stb r11,132(r31)
	PPC_STORE_U8(r31.u32 + 132, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F5BA4"))) PPC_WEAK_FUNC(sub_824F5BA4);
PPC_FUNC_IMPL(__imp__sub_824F5BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5BA8"))) PPC_WEAK_FUNC(sub_824F5BA8);
PPC_FUNC_IMPL(__imp__sub_824F5BA8) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5be8
	if (cr6.eq) goto loc_824F5BE8;
loc_824F5BC8:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f5bdc
	if (cr6.eq) goto loc_824F5BDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f3d58
	ctx.lr = 0x824F5BDC;
	sub_824F3D58(ctx, base);
loc_824F5BDC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5bc8
	if (!cr6.eq) goto loc_824F5BC8;
loc_824F5BE8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F5BFC"))) PPC_WEAK_FUNC(sub_824F5BFC);
PPC_FUNC_IMPL(__imp__sub_824F5BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5C00"))) PPC_WEAK_FUNC(sub_824F5C00);
PPC_FUNC_IMPL(__imp__sub_824F5C00) {
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
	// bl 0x824f9438
	ctx.lr = 0x824F5C18;
	sub_824F9438(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f5a50
	ctx.lr = 0x824F5C20;
	sub_824F5A50(ctx, base);
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

__attribute__((alias("__imp__sub_824F5C38"))) PPC_WEAK_FUNC(sub_824F5C38);
PPC_FUNC_IMPL(__imp__sub_824F5C38) {
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
	ctx.lr = 0x824F5C40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,132(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 132);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f5cfc
	if (cr6.eq) goto loc_824F5CFC;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f5c74
	if (cr6.eq) goto loc_824F5C74;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// bl 0x824e7fe8
	ctx.lr = 0x824F5C6C;
	sub_824E7FE8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_824F5C74:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F5C88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,88(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f5cf0
	if (cr6.eq) goto loc_824F5CF0;
	// addi r29,r30,80
	r29.s64 = r30.s64 + 80;
	// lis r28,-32115
	r28.s64 = -2104688640;
loc_824F5C9C:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f5cb4
	if (cr6.eq) goto loc_824F5CB4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f3d58
	ctx.lr = 0x824F5CB4;
	sub_824F3D58(ctx, base);
loc_824F5CB4:
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
	ctx.lr = 0x824F5CCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,32268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32268);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824F5CE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,88(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824f5c9c
	if (!cr6.eq) goto loc_824F5C9C;
loc_824F5CF0:
	// lbz r11,132(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 132);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,132(r30)
	PPC_STORE_U8(r30.u32 + 132, ctx.r10.u8);
loc_824F5CFC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F5D04"))) PPC_WEAK_FUNC(sub_824F5D04);
PPC_FUNC_IMPL(__imp__sub_824F5D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F5D08"))) PPC_WEAK_FUNC(sub_824F5D08);
PPC_FUNC_IMPL(__imp__sub_824F5D08) {
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
	ctx.lr = 0x824F5D10;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,31
	ctx.r10.s64 = 31;
	// lwz r8,28(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// lwz r7,24(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r9,20(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
loc_824F5D3C:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f5d54
	if (cr6.eq) goto loc_824F5D54;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f5d3c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F5D3C;
loc_824F5D54:
	// li r28,0
	r28.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r9,r10,31896
	ctx.r9.s64 = ctx.r10.s64 + 31896;
	// stw r8,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x824f4b28
	ctx.lr = 0x824F5D88;
	sub_824F4B28(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r27,-1
	r27.s64 = -1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f5e74
	if (cr6.eq) goto loc_824F5E74;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r29,r28
	r29.u64 = r28.u64;
	// subf r11,r4,r27
	r11.s64 = r27.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f5e04
	if (cr6.eq) goto loc_824F5E04;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F5DD4;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5e04
	if (cr6.eq) goto loc_824F5E04;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F5DF4;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5e04
	if (cr6.eq) goto loc_824F5E04;
	// li r29,1
	r29.s64 = 1;
loc_824F5E04:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5e74
	if (cr6.eq) goto loc_824F5E74;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F5E30;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f5e74
	if (cr6.eq) goto loc_824F5E74;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,31960
	ctx.r9.s64 = r11.s64 + 31960;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f5e74
	if (!cr6.eq) goto loc_824F5E74;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f4c98
	ctx.lr = 0x824F5E68;
	sub_824F4C98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f5ee4
	if (!cr6.eq) goto loc_824F5EE4;
loc_824F5E74:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r31,124
	r29.s64 = r31.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F5E84:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F5E8C;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f5e84
	if (!cr0.eq) goto loc_824F5E84;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f5eac
	if (cr6.eq) goto loc_824F5EAC;
	// bl 0x8244a330
	ctx.lr = 0x824F5EA8;
	sub_8244A330(ctx, base);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
loc_824F5EAC:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f5ec0
	if (cr6.eq) goto loc_824F5EC0;
	// bl 0x82130588
	ctx.lr = 0x824F5EBC;
	sub_82130588(ctx, base);
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
loc_824F5EC0:
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F5ED4;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9240
	return;
loc_824F5EE4:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f5efc
	if (cr6.eq) goto loc_824F5EFC;
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_824F5EFC:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f5f20
	if (!cr6.eq) goto loc_824F5F20;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F5F20:
	// bl 0x821ce0a0
	ctx.lr = 0x824F5F24;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F5F30"))) PPC_WEAK_FUNC(sub_824F5F30);
PPC_FUNC_IMPL(__imp__sub_824F5F30) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x824F5F38;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F5F4C;
	sub_824F9438(ctx, base);
	// lwz r9,20(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
loc_824F5F64:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f5f7c
	if (cr6.eq) goto loc_824F5F7C;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f5f64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F5F64;
loc_824F5F7C:
	// ld r10,24(r25)
	ctx.r10.u64 = PPC_LOAD_U64(r25.u32 + 24);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// ld r8,32(r25)
	ctx.r8.u64 = PPC_LOAD_U64(r25.u32 + 32);
	// li r27,0
	r27.s64 = 0;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,31704
	ctx.r4.s64 = ctx.r6.s64 + 31704;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// std r10,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r10.u64);
	// li r6,128
	ctx.r6.s64 = 128;
	// std r8,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r8.u64);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r30,r25,24
	r30.s64 = r25.s64 + 24;
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// bl 0x824f4be0
	ctx.lr = 0x824F5FC0;
	sub_824F4BE0(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// li r26,-1
	r26.s64 = -1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f60ac
	if (cr6.eq) goto loc_824F60AC;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// mr r28,r27
	r28.u64 = r27.u64;
	// subf r11,r4,r26
	r11.s64 = r26.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f603c
	if (cr6.eq) goto loc_824F603C;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F600C;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f603c
	if (cr6.eq) goto loc_824F603C;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F602C;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f603c
	if (cr6.eq) goto loc_824F603C;
	// li r28,1
	r28.s64 = 1;
loc_824F603C:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f60ac
	if (cr6.eq) goto loc_824F60AC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F6068;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f60ac
	if (cr6.eq) goto loc_824F60AC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,31576
	ctx.r9.s64 = r11.s64 + 31576;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f60ac
	if (!cr6.eq) goto loc_824F60AC;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f4c98
	ctx.lr = 0x824F60A0;
	sub_824F4C98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f611c
	if (!cr6.eq) goto loc_824F611C;
loc_824F60AC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r29,124
	r29.s64 = r29.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F60BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F60C4;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f60bc
	if (!cr0.eq) goto loc_824F60BC;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f60e4
	if (cr6.eq) goto loc_824F60E4;
	// bl 0x8244a330
	ctx.lr = 0x824F60E0;
	sub_8244A330(ctx, base);
	// stw r26,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r26.u32);
loc_824F60E4:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f60f8
	if (cr6.eq) goto loc_824F60F8;
	// bl 0x82130588
	ctx.lr = 0x824F60F4;
	sub_82130588(ctx, base);
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_824F60F8:
	// lwz r31,8(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F610C;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d923c
	return;
loc_824F611C:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f6158
	if (cr6.eq) goto loc_824F6158;
	// li r5,26
	ctx.r5.s64 = 26;
	// stb r27,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r27.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,113
	ctx.r3.s64 = ctx.r1.s64 + 113;
	// bl 0x823d9890
	ctx.lr = 0x824F613C;
	sub_823D9890(ctx, base);
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9478
	ctx.lr = 0x824F614C;
	sub_824F9478(ctx, base);
	// lwz r11,40(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 40);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_824F6158:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f617c
	if (!cr6.eq) goto loc_824F617C;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F617C:
	// bl 0x821ce0a0
	ctx.lr = 0x824F6180;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F618C"))) PPC_WEAK_FUNC(sub_824F618C);
PPC_FUNC_IMPL(__imp__sub_824F618C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F6190"))) PPC_WEAK_FUNC(sub_824F6190);
PPC_FUNC_IMPL(__imp__sub_824F6190) {
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
	ctx.lr = 0x824F6198;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F61AC;
	sub_824F9438(ctx, base);
	// lwz r8,40(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
loc_824F61C8:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f61e0
	if (cr6.eq) goto loc_824F61E0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f61c8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F61C8;
loc_824F61E0:
	// ld r5,32(r27)
	ctx.r5.u64 = PPC_LOAD_U64(r27.u32 + 32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// ld r10,24(r27)
	ctx.r10.u64 = PPC_LOAD_U64(r27.u32 + 24);
	// li r30,0
	r30.s64 = 0;
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r11,r4,31800
	r11.s64 = ctx.r4.s64 + 31800;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// std r5,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r5.u64);
	// li r6,128
	ctx.r6.s64 = 128;
	// std r10,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r10.u64);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// stw r8,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r8.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r29,r27,24
	r29.s64 = r27.s64 + 24;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824f4d80
	ctx.lr = 0x824F6228;
	sub_824F4D80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r25,-1
	r25.s64 = -1;
	// li r24,-1
	r24.s64 = -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f6338
	if (cr6.eq) goto loc_824F6338;
	// lwz r4,124(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// mr r28,r30
	r28.u64 = r30.u64;
	// subf r11,r4,r25
	r11.s64 = r25.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f62a8
	if (cr6.eq) goto loc_824F62A8;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F6278;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f62a8
	if (cr6.eq) goto loc_824F62A8;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F6298;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f62a8
	if (cr6.eq) goto loc_824F62A8;
	// li r28,1
	r28.s64 = 1;
loc_824F62A8:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6338
	if (cr6.eq) goto loc_824F6338;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F62D4;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6338
	if (cr6.eq) goto loc_824F6338;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,30580
	ctx.r9.s64 = r11.s64 + 30580;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f6338
	if (!cr6.eq) goto loc_824F6338;
	// lwz r11,40(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,48(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r9,44(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r24.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f4e38
	ctx.lr = 0x824F632C;
	sub_824F4E38(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824f63a4
	if (!cr6.eq) goto loc_824F63A4;
loc_824F6338:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r26,r26,124
	r26.s64 = r26.s64 + 124;
	// addi r29,r11,30648
	r29.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F6348:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82534698
	ctx.lr = 0x824F6350;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// bne 0x824f6348
	if (!cr0.eq) goto loc_824F6348;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f6370
	if (cr6.eq) goto loc_824F6370;
	// bl 0x8244a330
	ctx.lr = 0x824F636C;
	sub_8244A330(ctx, base);
	// stw r25,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r25.u32);
loc_824F6370:
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f6384
	if (cr6.eq) goto loc_824F6384;
	// bl 0x82130588
	ctx.lr = 0x824F6380;
	sub_82130588(ctx, base);
	// stw r30,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r30.u32);
loc_824F6384:
	// lwz r31,8(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F6398;
	sub_821CE0A0(ctx, base);
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9238
	return;
loc_824F63A4:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f6434
	if (cr6.eq) goto loc_824F6434;
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// mr r28,r30
	r28.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x824f6434
	if (!cr6.gt) goto loc_824F6434;
loc_824F63C4:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9388
	ctx.lr = 0x824F63D8;
	sub_824F9388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6410
	if (cr6.eq) goto loc_824F6410;
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9478
	ctx.lr = 0x824F63F4;
	sub_824F9478(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6410
	if (cr6.eq) goto loc_824F6410;
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9478
	ctx.lr = 0x824F6410;
	sub_824F9478(ctx, base);
loc_824F6410:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f8
	ctx.lr = 0x824F641C;
	sub_824F92F8(ctx, base);
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,152
	r30.s64 = r30.s64 + 152;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x824f63c4
	if (cr6.lt) goto loc_824F63C4;
loc_824F6434:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f6458
	if (!cr6.eq) goto loc_824F6458;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F6458:
	// bl 0x821ce0a0
	ctx.lr = 0x824F645C;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F6468"))) PPC_WEAK_FUNC(sub_824F6468);
PPC_FUNC_IMPL(__imp__sub_824F6468) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x824F6470;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,31
	ctx.r10.s64 = 31;
	// lwz r8,28(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// lwz r7,24(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r6,32(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
loc_824F64A0:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f64b8
	if (cr6.eq) goto loc_824F64B8;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f64a0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F64A0;
loc_824F64B8:
	// li r28,0
	r28.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// addi r9,r10,32024
	ctx.r9.s64 = ctx.r10.s64 + 32024;
	// stw r6,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r8,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x824f4f20
	ctx.lr = 0x824F64F0;
	sub_824F4F20(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r26,-1
	r26.s64 = -1;
	// li r25,-1
	r25.s64 = -1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f6600
	if (cr6.eq) goto loc_824F6600;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// mr r30,r28
	r30.u64 = r28.u64;
	// subf r11,r4,r26
	r11.s64 = r26.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f6570
	if (cr6.eq) goto loc_824F6570;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F6540;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6570
	if (cr6.eq) goto loc_824F6570;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F6560;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6570
	if (cr6.eq) goto loc_824F6570;
	// li r30,1
	r30.s64 = 1;
loc_824F6570:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6600
	if (cr6.eq) goto loc_824F6600;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F659C;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6600
	if (cr6.eq) goto loc_824F6600;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,31608
	ctx.r9.s64 = r11.s64 + 31608;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f6600
	if (!cr6.eq) goto loc_824F6600;
	// lwz r11,32(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,40(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r9,36(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// stb r28,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r28.u8);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f4e38
	ctx.lr = 0x824F65F4;
	sub_824F4E38(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824f666c
	if (!cr6.eq) goto loc_824F666C;
loc_824F6600:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r29,124
	r29.s64 = r29.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F6610:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F6618;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f6610
	if (!cr0.eq) goto loc_824F6610;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f6638
	if (cr6.eq) goto loc_824F6638;
	// bl 0x8244a330
	ctx.lr = 0x824F6634;
	sub_8244A330(ctx, base);
	// stw r26,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r26.u32);
loc_824F6638:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f664c
	if (cr6.eq) goto loc_824F664C;
	// bl 0x82130588
	ctx.lr = 0x824F6648;
	sub_82130588(ctx, base);
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
loc_824F664C:
	// lwz r31,8(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F6660;
	sub_821CE0A0(ctx, base);
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d923c
	return;
loc_824F666C:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f6690
	if (!cr6.eq) goto loc_824F6690;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F6690:
	// bl 0x821ce0a0
	ctx.lr = 0x824F6694;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F66A0"))) PPC_WEAK_FUNC(sub_824F66A0);
PPC_FUNC_IMPL(__imp__sub_824F66A0) {
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
	ctx.lr = 0x824F66A8;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,31
	ctx.r10.s64 = 31;
	// lwz r8,24(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r9,20(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
loc_824F66D0:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f66e8
	if (cr6.eq) goto loc_824F66E8;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f66d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F66D0;
loc_824F66E8:
	// li r27,0
	r27.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// addi r9,r10,30516
	ctx.r9.s64 = ctx.r10.s64 + 30516;
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x824f5178
	ctx.lr = 0x824F6718;
	sub_824F5178(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r28,-1
	r28.s64 = -1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f6804
	if (cr6.eq) goto loc_824F6804;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r29,r27
	r29.u64 = r27.u64;
	// subf r11,r4,r28
	r11.s64 = r28.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f6794
	if (cr6.eq) goto loc_824F6794;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F6764;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6794
	if (cr6.eq) goto loc_824F6794;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F6784;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6794
	if (cr6.eq) goto loc_824F6794;
	// li r29,1
	r29.s64 = 1;
loc_824F6794:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6804
	if (cr6.eq) goto loc_824F6804;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F67C0;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6804
	if (cr6.eq) goto loc_824F6804;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,30548
	ctx.r9.s64 = r11.s64 + 30548;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f6804
	if (!cr6.eq) goto loc_824F6804;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f54b8
	ctx.lr = 0x824F67F8;
	sub_824F54B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f6874
	if (!cr6.eq) goto loc_824F6874;
loc_824F6804:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r31,124
	r29.s64 = r31.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F6814:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F681C;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f6814
	if (!cr0.eq) goto loc_824F6814;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f683c
	if (cr6.eq) goto loc_824F683C;
	// bl 0x8244a330
	ctx.lr = 0x824F6838;
	sub_8244A330(ctx, base);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_824F683C:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f6850
	if (cr6.eq) goto loc_824F6850;
	// bl 0x82130588
	ctx.lr = 0x824F684C;
	sub_82130588(ctx, base);
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_824F6850:
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F6864;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9240
	return;
loc_824F6874:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f6898
	if (!cr6.eq) goto loc_824F6898;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F6898:
	// bl 0x821ce0a0
	ctx.lr = 0x824F689C;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F68A8"))) PPC_WEAK_FUNC(sub_824F68A8);
PPC_FUNC_IMPL(__imp__sub_824F68A8) {
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
	ctx.lr = 0x824F68B0;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r8,r10,31832
	ctx.r8.s64 = ctx.r10.s64 + 31832;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,20(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r9,28(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// li r6,128
	ctx.r6.s64 = 128;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// bl 0x824f5710
	ctx.lr = 0x824F68F4;
	sub_824F5710(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// li r23,-1
	r23.s64 = -1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f6aa0
	if (cr6.eq) goto loc_824F6AA0;
	// lwz r4,124(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// mr r30,r27
	r30.u64 = r27.u64;
	// subf r11,r4,r23
	r11.s64 = r23.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f6970
	if (cr6.eq) goto loc_824F6970;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F6940;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6970
	if (cr6.eq) goto loc_824F6970;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 124);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F6960;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6970
	if (cr6.eq) goto loc_824F6970;
	// li r30,1
	r30.s64 = 1;
loc_824F6970:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6aa0
	if (cr6.eq) goto loc_824F6AA0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F699C;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6aa0
	if (cr6.eq) goto loc_824F6AA0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r25,r11,32120
	r25.s64 = r11.s64 + 32120;
loc_824F69B0:
	// lwz r28,8(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f6b10
	if (!cr6.eq) goto loc_824F6B10;
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,88(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82257678
	ctx.lr = 0x824F69DC;
	sub_82257678(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82618750
	ctx.lr = 0x824F69E8;
	sub_82618750(ctx, base);
	// subf r5,r31,r29
	ctx.r5.s64 = r29.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826185e0
	ctx.lr = 0x824F69F8;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f6a28
	if (cr6.eq) goto loc_824F6A28;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f6a28
	if (!cr6.eq) goto loc_824F6A28;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82618db0
	ctx.lr = 0x824F6A18;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f6a2c
	if (!cr6.eq) goto loc_824F6A2C;
loc_824F6A28:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824F6A2C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6a50
	if (cr6.eq) goto loc_824F6A50;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826186b0
	ctx.lr = 0x824F6A40;
	sub_826186B0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f6a54
	if (cr6.eq) goto loc_824F6A54;
loc_824F6A50:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824F6A54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6aa0
	if (cr6.eq) goto loc_824F6AA0;
	// lwz r3,36(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f6a74
	if (cr6.eq) goto loc_824F6A74;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x821ce080
	ctx.lr = 0x824F6A74;
	sub_821CE080(ctx, base);
loc_824F6A74:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F6A94;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f69b0
	if (!cr6.eq) goto loc_824F69B0;
loc_824F6AA0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r26,124
	r29.s64 = r26.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F6AB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F6AB8;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f6ab0
	if (!cr0.eq) goto loc_824F6AB0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f6ad8
	if (cr6.eq) goto loc_824F6AD8;
	// bl 0x8244a330
	ctx.lr = 0x824F6AD4;
	sub_8244A330(ctx, base);
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
loc_824F6AD8:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f6aec
	if (cr6.eq) goto loc_824F6AEC;
	// bl 0x82130588
	ctx.lr = 0x824F6AE8;
	sub_82130588(ctx, base);
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_824F6AEC:
	// lwz r31,8(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F6B00;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9234
	return;
loc_824F6B10:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,31864
	ctx.r9.s64 = ctx.r10.s64 + 31864;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824f6aa0
	if (!cr6.eq) goto loc_824F6AA0;
	// lwz r11,24(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,28(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r27.u32);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// bl 0x824f57c8
	ctx.lr = 0x824F6B4C;
	sub_824F57C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f6aa0
	if (cr6.eq) goto loc_824F6AA0;
	// lbz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f6b70
	if (cr6.eq) goto loc_824F6B70;
	// lwz r11,32(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_824F6B70:
	// lbz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// lwz r30,116(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824f6ba0
	if (cr6.eq) goto loc_824F6BA0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824F6B94;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9234
	return;
loc_824F6BA0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824F6BA8;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824F6BB4"))) PPC_WEAK_FUNC(sub_824F6BB4);
PPC_FUNC_IMPL(__imp__sub_824F6BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F6BB8"))) PPC_WEAK_FUNC(sub_824F6BB8);
PPC_FUNC_IMPL(__imp__sub_824F6BB8) {
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
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F6BDC;
	sub_824F9438(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f5a50
	ctx.lr = 0x824F6BE4;
	sub_824F5A50(ctx, base);
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

__attribute__((alias("__imp__sub_824F6C00"))) PPC_WEAK_FUNC(sub_824F6C00);
PPC_FUNC_IMPL(__imp__sub_824F6C00) {
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
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F6C24;
	sub_824F9438(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f5a50
	ctx.lr = 0x824F6C2C;
	sub_824F5A50(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,188
	ctx.r3.s64 = r31.s64 + 188;
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,281(r31)
	PPC_STORE_U8(r31.u32 + 281, r11.u8);
	// bl 0x8244d150
	ctx.lr = 0x824F6C4C;
	sub_8244D150(ctx, base);
	// addi r3,r31,200
	ctx.r3.s64 = r31.s64 + 200;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824F6C5C;
	sub_8244D150(ctx, base);
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

__attribute__((alias("__imp__sub_824F6C78"))) PPC_WEAK_FUNC(sub_824F6C78);
PPC_FUNC_IMPL(__imp__sub_824F6C78) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x824e6928
	ctx.lr = 0x824F6CB8;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r10,r11,27476
	ctx.r10.s64 = r11.s64 + 27476;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824F6CDC;
	sub_821C8ED8(ctx, base);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r9.u32);
	// lbz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 132);
	// clrlwi r7,r8,25
	ctx.r7.u64 = ctx.r8.u32 & 0x7F;
	// stb r7,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_824F6D10"))) PPC_WEAK_FUNC(sub_824F6D10);
PPC_FUNC_IMPL(__imp__sub_824F6D10) {
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
	// bl 0x824f5c38
	ctx.lr = 0x824F6D28;
	sub_824F5C38(ctx, base);
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// bl 0x824f2448
	ctx.lr = 0x824F6D30;
	sub_824F2448(ctx, base);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x82130000
	ctx.lr = 0x824F6D38;
	sub_82130000(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x824f5ba8
	ctx.lr = 0x824F6D40;
	sub_824F5BA8(ctx, base);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x824e6b58
	ctx.lr = 0x824F6D48;
	sub_824E6B58(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824F6D5C"))) PPC_WEAK_FUNC(sub_824F6D5C);
PPC_FUNC_IMPL(__imp__sub_824F6D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F6D60"))) PPC_WEAK_FUNC(sub_824F6D60);
PPC_FUNC_IMPL(__imp__sub_824F6D60) {
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
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824F6D88;
	sub_821C8FE0(ctx, base);
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824fb448
	ctx.lr = 0x824F6D9C;
	sub_824FB448(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F6DA4;
	sub_821C9030(ctx, base);
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f6dc4
	if (cr6.eq) goto loc_824F6DC4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824F6DBC;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824F6DC4:
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x824e6a10
	ctx.lr = 0x824F6DCC;
	sub_824E6A10(ctx, base);
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

__attribute__((alias("__imp__sub_824F6DE4"))) PPC_WEAK_FUNC(sub_824F6DE4);
PPC_FUNC_IMPL(__imp__sub_824F6DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F6DE8"))) PPC_WEAK_FUNC(sub_824F6DE8);
PPC_FUNC_IMPL(__imp__sub_824F6DE8) {
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
	ctx.lr = 0x824F6DF0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f6e90
	if (cr6.eq) goto loc_824F6E90;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f6e90
	if (cr6.eq) goto loc_824F6E90;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,36
	ctx.r4.s64 = 36;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F6E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f6e7c
	if (cr6.eq) goto loc_824F6E7C;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r27.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,27520
	ctx.r9.s64 = ctx.r10.s64 + 27520;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r31,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r31.u32);
	// stw r29,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r29.u32);
	// stw r28,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, r28.u32);
	// stw r30,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, r30.u32);
loc_824F6E7C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F6E84;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_824F6E90:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F6E9C"))) PPC_WEAK_FUNC(sub_824F6E9C);
PPC_FUNC_IMPL(__imp__sub_824F6E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F6EA0"))) PPC_WEAK_FUNC(sub_824F6EA0);
PPC_FUNC_IMPL(__imp__sub_824F6EA0) {
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
	ctx.lr = 0x824F6EA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f6f94
	if (cr6.eq) goto loc_824F6F94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9270
	ctx.lr = 0x824F6ED8;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f6f94
	if (cr6.eq) goto loc_824F6F94;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f6f94
	if (cr6.eq) goto loc_824F6F94;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f6f94
	if (cr6.eq) goto loc_824F6F94;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f6f94
	if (cr6.eq) goto loc_824F6F94;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,56
	ctx.r4.s64 = 56;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F6F20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f6f80
	if (cr6.eq) goto loc_824F6F80;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r26,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r26.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,27528
	ctx.r8.s64 = ctx.r10.s64 + 27528;
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// stw r30,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r30.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r7.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r6,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r6.u32);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r5,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, ctx.r5.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r3,36(r4)
	PPC_STORE_U32(ctx.r4.u32 + 36, ctx.r3.u32);
	// stw r29,40(r4)
	PPC_STORE_U32(ctx.r4.u32 + 40, r29.u32);
	// stw r28,44(r4)
	PPC_STORE_U32(ctx.r4.u32 + 44, r28.u32);
	// stw r27,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, r27.u32);
loc_824F6F80:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F6F88;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_824F6F94:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F6FA0"))) PPC_WEAK_FUNC(sub_824F6FA0);
PPC_FUNC_IMPL(__imp__sub_824F6FA0) {
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
	ctx.lr = 0x824F6FA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f709c
	if (cr6.eq) goto loc_824F709C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9270
	ctx.lr = 0x824F6FDC;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f709c
	if (cr6.eq) goto loc_824F709C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f709c
	if (cr6.eq) goto loc_824F709C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f709c
	if (cr6.eq) goto loc_824F709C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F701C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f7088
	if (cr6.eq) goto loc_824F7088;
	// lwz r10,244(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r9,27544
	ctx.r7.s64 = ctx.r9.s64 + 27544;
	// stw r8,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r8.u32);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// stw r7,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
	// stw r30,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r6,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r6.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r5,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r5.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r3,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, ctx.r3.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,36(r4)
	PPC_STORE_U32(ctx.r4.u32 + 36, r11.u32);
	// stw r27,40(r4)
	PPC_STORE_U32(ctx.r4.u32 + 40, r27.u32);
	// stw r26,44(r4)
	PPC_STORE_U32(ctx.r4.u32 + 44, r26.u32);
	// stw r25,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, r25.u32);
	// stw r29,52(r4)
	PPC_STORE_U32(ctx.r4.u32 + 52, r29.u32);
	// stw r28,56(r4)
	PPC_STORE_U32(ctx.r4.u32 + 56, r28.u32);
loc_824F7088:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F7090;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824F709C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F70A8"))) PPC_WEAK_FUNC(sub_824F70A8);
PPC_FUNC_IMPL(__imp__sub_824F70A8) {
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
	ctx.lr = 0x824F70B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f717c
	if (cr6.eq) goto loc_824F717C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f717c
	if (cr6.eq) goto loc_824F717C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f717c
	if (cr6.eq) goto loc_824F717C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f717c
	if (cr6.eq) goto loc_824F717C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f717c
	if (cr6.eq) goto loc_824F717C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F7120;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f7168
	if (cr6.eq) goto loc_824F7168;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r25,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r25.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,27536
	ctx.r8.s64 = ctx.r10.s64 + 27536;
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// stw r31,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r31.u32);
	// stw r30,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r30.u32);
	// stw r26,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, r26.u32);
	// stw r29,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, r29.u32);
	// stw r28,36(r4)
	PPC_STORE_U32(ctx.r4.u32 + 36, r28.u32);
	// stw r27,40(r4)
	PPC_STORE_U32(ctx.r4.u32 + 40, r27.u32);
loc_824F7168:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F7170;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824F717C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F7188"))) PPC_WEAK_FUNC(sub_824F7188);
PPC_FUNC_IMPL(__imp__sub_824F7188) {
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
	ctx.lr = 0x824F7190;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f7250
	if (cr6.eq) goto loc_824F7250;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f2380
	ctx.lr = 0x824F71BC;
	sub_824F2380(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7250
	if (cr6.eq) goto loc_824F7250;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,184
	ctx.r4.s64 = 184;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F71EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f7238
	if (cr6.eq) goto loc_824F7238;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,27552
	ctx.r8.s64 = ctx.r10.s64 + 27552;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// li r5,152
	ctx.r5.s64 = 152;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x823da950
	ctx.lr = 0x824F7230;
	sub_823DA950(ctx, base);
	// stb r28,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r28.u8);
	// stw r27,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r27.u32);
loc_824F7238:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F7244;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_824F7250:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F725C"))) PPC_WEAK_FUNC(sub_824F725C);
PPC_FUNC_IMPL(__imp__sub_824F725C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F7260"))) PPC_WEAK_FUNC(sub_824F7260);
PPC_FUNC_IMPL(__imp__sub_824F7260) {
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
	ctx.lr = 0x824F7268;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f72fc
	if (cr6.eq) goto loc_824F72FC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x824f72fc
	if (cr6.eq) goto loc_824F72FC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,28
	ctx.r4.s64 = 28;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F72B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824f72e8
	if (cr6.eq) goto loc_824F72E8;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r29,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r29.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,27560
	ctx.r8.s64 = ctx.r10.s64 + 27560;
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// stw r31,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r31.u32);
	// stw r30,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r30.u32);
loc_824F72E8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F72F0;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824F72FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F7308"))) PPC_WEAK_FUNC(sub_824F7308);
PPC_FUNC_IMPL(__imp__sub_824F7308) {
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
	ctx.lr = 0x824F7310;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f9270
	ctx.lr = 0x824F7344;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// lwz r22,332(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// lwz r24,340(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// lbz r25,327(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 327);
	// cmplwi cr6,r25,32
	cr6.compare<uint32_t>(r25.u32, 32, xer);
	// bge cr6,0x824f7458
	if (!cr6.lt) goto loc_824F7458;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f73d0
	if (cr6.eq) goto loc_824F73D0;
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r9,r30,r29
	ctx.r9.s64 = r29.s64 - r30.s64;
loc_824F73A8:
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f7458
	if (cr6.eq) goto loc_824F7458;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// blt cr6,0x824f73a8
	if (cr6.lt) goto loc_824F73A8;
loc_824F73D0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,88
	ctx.r4.s64 = 88;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F73F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f7440
	if (cr6.eq) goto loc_824F7440;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r11,348(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r30,316(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r29,308(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// stw r24,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r24.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stw r22,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r22.u32);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r25,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r25.u8);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x824f3948
	ctx.lr = 0x824F7440;
	sub_824F3948(ctx, base);
loc_824F7440:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F744C;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d922c
	return;
loc_824F7458:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824F7464"))) PPC_WEAK_FUNC(sub_824F7464);
PPC_FUNC_IMPL(__imp__sub_824F7464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F7468"))) PPC_WEAK_FUNC(sub_824F7468);
PPC_FUNC_IMPL(__imp__sub_824F7468) {
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
	ctx.lr = 0x824F7470;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f2380
	ctx.lr = 0x824F74A4;
	sub_824F2380(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// lwz r21,316(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// lwz r22,324(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824f7568
	if (cr6.eq) goto loc_824F7568;
	// lbz r25,311(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// cmplwi cr6,r25,32
	cr6.compare<uint32_t>(r25.u32, 32, xer);
	// bge cr6,0x824f7568
	if (!cr6.lt) goto loc_824F7568;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,208
	ctx.r4.s64 = 208;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F7510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f7550
	if (cr6.eq) goto loc_824F7550;
	// lwz r11,332(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r21.u32);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// stb r25,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r25.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824f39f8
	ctx.lr = 0x824F7550;
	sub_824F39F8(ctx, base);
loc_824F7550:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F755C;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9228
	return;
loc_824F7568:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824F7574"))) PPC_WEAK_FUNC(sub_824F7574);
PPC_FUNC_IMPL(__imp__sub_824F7574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F7578"))) PPC_WEAK_FUNC(sub_824F7578);
PPC_FUNC_IMPL(__imp__sub_824F7578) {
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
	ctx.lr = 0x824F7580;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824f7628
	if (cr6.eq) goto loc_824F7628;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f7628
	if (cr6.eq) goto loc_824F7628;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f7628
	if (cr6.eq) goto loc_824F7628;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f7628
	if (cr6.eq) goto loc_824F7628;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f7628
	if (cr6.eq) goto loc_824F7628;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,40
	ctx.r4.s64 = 40;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F75EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f7610
	if (cr6.eq) goto loc_824F7610;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824f3af0
	ctx.lr = 0x824F7610;
	sub_824F3AF0(ctx, base);
loc_824F7610:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F761C;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_824F7628:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F7634"))) PPC_WEAK_FUNC(sub_824F7634);
PPC_FUNC_IMPL(__imp__sub_824F7634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F7638"))) PPC_WEAK_FUNC(sub_824F7638);
PPC_FUNC_IMPL(__imp__sub_824F7638) {
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
	ctx.lr = 0x824F7640;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824f770c
	if (cr6.eq) goto loc_824F770C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f770c
	if (cr6.eq) goto loc_824F770C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824f770c
	if (cr6.eq) goto loc_824F770C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f770c
	if (cr6.eq) goto loc_824F770C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,192
	ctx.r4.s64 = 192;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F76A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f76f4
	if (cr6.eq) goto loc_824F76F4;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r25,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r25.u32);
	// li r9,11
	ctx.r9.s64 = 11;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,27592
	ctx.r8.s64 = ctx.r10.s64 + 27592;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// li r5,152
	ctx.r5.s64 = 152;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x823da950
	ctx.lr = 0x824F76E8;
	sub_823DA950(ctx, base);
	// stw r29,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r29.u32);
	// stw r28,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r28.u32);
	// stw r27,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r27.u32);
loc_824F76F4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824f6d60
	ctx.lr = 0x824F7700;
	sub_824F6D60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824F770C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F7718"))) PPC_WEAK_FUNC(sub_824F7718);
PPC_FUNC_IMPL(__imp__sub_824F7718) {
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
	ctx.lr = 0x824F7720;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F7734;
	sub_824F9438(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,31
	ctx.r10.s64 = 31;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
loc_824F7758:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f7770
	if (cr6.eq) goto loc_824F7770;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f7758
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F7758;
loc_824F7770:
	// ld r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// ld r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// li r27,0
	r27.s64 = 0;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r11,r6,32184
	r11.s64 = ctx.r6.s64 + 32184;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// std r10,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r10.u64);
	// li r6,128
	ctx.r6.s64 = 128;
	// std r3,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r3.u64);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r4,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// addi r10,r31,24
	ctx.r10.s64 = r31.s64 + 24;
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// stw r8,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824f4fd8
	ctx.lr = 0x824F77C0;
	sub_824F4FD8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r26,-1
	r26.s64 = -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f78d0
	if (cr6.eq) goto loc_824F78D0;
	// lwz r4,124(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 124);
	// mr r29,r27
	r29.u64 = r27.u64;
	// subf r11,r4,r26
	r11.s64 = r26.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f783c
	if (cr6.eq) goto loc_824F783C;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F780C;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f783c
	if (cr6.eq) goto loc_824F783C;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,124(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 124);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F782C;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f783c
	if (cr6.eq) goto loc_824F783C;
	// li r29,1
	r29.s64 = 1;
loc_824F783C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f78d0
	if (cr6.eq) goto loc_824F78D0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F7868;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f78d0
	if (cr6.eq) goto loc_824F78D0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r11,31544
	r30.s64 = r11.s64 + 31544;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f78d0
	if (!cr6.eq) goto loc_824F78D0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824f6bb8
	ctx.lr = 0x824F7894;
	sub_824F6BB8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f5090
	ctx.lr = 0x824F78AC;
	sub_824F5090(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f78d0
	if (cr6.eq) goto loc_824F78D0;
	// lbz r10,160(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 160);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f7958
	if (cr6.eq) goto loc_824F7958;
	// lwz r11,320(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x824f7940
	if (!cr6.gt) goto loc_824F7940;
loc_824F78D0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r28,124
	r28.s64 = r28.s64 + 124;
	// addi r29,r11,30648
	r29.s64 = r11.s64 + 30648;
	// li r30,4
	r30.s64 = 4;
loc_824F78E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82534698
	ctx.lr = 0x824F78E8;
	sub_82534698(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// bne 0x824f78e0
	if (!cr0.eq) goto loc_824F78E0;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f7908
	if (cr6.eq) goto loc_824F7908;
	// bl 0x8244a330
	ctx.lr = 0x824F7904;
	sub_8244A330(ctx, base);
	// stw r26,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r26.u32);
loc_824F7908:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f791c
	if (cr6.eq) goto loc_824F791C;
	// bl 0x82130588
	ctx.lr = 0x824F7918;
	sub_82130588(ctx, base);
	// stw r27,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r27.u32);
loc_824F791C:
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F7930;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9240
	return;
loc_824F7940:
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r1,168
	ctx.r4.s64 = ctx.r1.s64 + 168;
	// li r5,152
	ctx.r5.s64 = 152;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x823da950
	ctx.lr = 0x824F7958;
	sub_823DA950(ctx, base);
loc_824F7958:
	// lbz r10,160(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 160);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,164(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f797c
	if (!cr6.eq) goto loc_824F797C;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F797C:
	// bl 0x821ce0a0
	ctx.lr = 0x824F7980;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F798C"))) PPC_WEAK_FUNC(sub_824F798C);
PPC_FUNC_IMPL(__imp__sub_824F798C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F7990"))) PPC_WEAK_FUNC(sub_824F7990);
PPC_FUNC_IMPL(__imp__sub_824F7990) {
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
	ctx.lr = 0x824F7998;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r10,31
	ctx.r10.s64 = 31;
	// lwz r8,24(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r9,20(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
loc_824F79C0:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f79d8
	if (cr6.eq) goto loc_824F79D8;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824f79c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824F79C0;
loc_824F79D8:
	// li r27,0
	r27.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// addi r9,r10,31992
	ctx.r9.s64 = ctx.r10.s64 + 31992;
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x824f5178
	ctx.lr = 0x824F7A08;
	sub_824F5178(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r28,-1
	r28.s64 = -1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824f7b18
	if (cr6.eq) goto loc_824F7B18;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// mr r30,r27
	r30.u64 = r27.u64;
	// subf r11,r4,r28
	r11.s64 = r28.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f7a84
	if (cr6.eq) goto loc_824F7A84;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F7A54;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7a84
	if (cr6.eq) goto loc_824F7A84;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 124);
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F7A74;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7a84
	if (cr6.eq) goto loc_824F7A84;
	// li r30,1
	r30.s64 = 1;
loc_824F7A84:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7b18
	if (cr6.eq) goto loc_824F7B18;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F7AB0;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7b18
	if (cr6.eq) goto loc_824F7B18;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r11,30612
	r31.s64 = r11.s64 + 30612;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f7b18
	if (!cr6.eq) goto loc_824F7B18;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824f6bb8
	ctx.lr = 0x824F7ADC;
	sub_824F6BB8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f5230
	ctx.lr = 0x824F7AF4;
	sub_824F5230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7b18
	if (cr6.eq) goto loc_824F7B18;
	// lbz r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f7ba0
	if (cr6.eq) goto loc_824F7BA0;
	// lwz r11,304(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x824f7b88
	if (!cr6.gt) goto loc_824F7B88;
loc_824F7B18:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r29,124
	r29.s64 = r29.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F7B28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F7B30;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f7b28
	if (!cr0.eq) goto loc_824F7B28;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f7b50
	if (cr6.eq) goto loc_824F7B50;
	// bl 0x8244a330
	ctx.lr = 0x824F7B4C;
	sub_8244A330(ctx, base);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_824F7B50:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f7b64
	if (cr6.eq) goto loc_824F7B64;
	// bl 0x82130588
	ctx.lr = 0x824F7B60;
	sub_82130588(ctx, base);
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_824F7B64:
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F7B78;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x823d9240
	return;
loc_824F7B88:
	// lwz r10,32(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// li r5,152
	ctx.r5.s64 = 152;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r3,28(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// bl 0x823da950
	ctx.lr = 0x824F7BA0;
	sub_823DA950(ctx, base);
loc_824F7BA0:
	// lbz r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 144);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,148(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f7bc4
	if (!cr6.eq) goto loc_824F7BC4;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F7BC4:
	// bl 0x821ce0a0
	ctx.lr = 0x824F7BC8;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F7BD4"))) PPC_WEAK_FUNC(sub_824F7BD4);
PPC_FUNC_IMPL(__imp__sub_824F7BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F7BD8"))) PPC_WEAK_FUNC(sub_824F7BD8);
PPC_FUNC_IMPL(__imp__sub_824F7BD8) {
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
	ctx.lr = 0x824F7BE0;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F7BF4;
	sub_824F9438(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824f5a50
	ctx.lr = 0x824F7BFC;
	sub_824F5A50(ctx, base);
	// addi r27,r28,24
	r27.s64 = r28.s64 + 24;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lbz r6,176(r28)
	ctx.r6.u64 = PPC_LOAD_U8(r28.u32 + 176);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r4,20(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// bl 0x824f2b80
	ctx.lr = 0x824F7C14;
	sub_824F2B80(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r25,0
	r25.s64 = 0;
	// addi r10,r11,32152
	ctx.r10.s64 = r11.s64 + 32152;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// li r6,512
	ctx.r6.s64 = 512;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824f5318
	ctx.lr = 0x824F7C3C;
	sub_824F5318(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r26,-1
	r26.s64 = -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f7d28
	if (cr6.eq) goto loc_824F7D28;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r29,r25
	r29.u64 = r25.u64;
	// subf r11,r4,r26
	r11.s64 = r26.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f7cb8
	if (cr6.eq) goto loc_824F7CB8;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F7C88;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7cb8
	if (cr6.eq) goto loc_824F7CB8;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F7CA8;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7cb8
	if (cr6.eq) goto loc_824F7CB8;
	// li r29,1
	r29.s64 = 1;
loc_824F7CB8:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7d28
	if (cr6.eq) goto loc_824F7D28;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F7CE4;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7d28
	if (cr6.eq) goto loc_824F7D28;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,32056
	ctx.r9.s64 = r11.s64 + 32056;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f7d28
	if (!cr6.eq) goto loc_824F7D28;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f53d0
	ctx.lr = 0x824F7D1C;
	sub_824F53D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f7d98
	if (!cr6.eq) goto loc_824F7D98;
loc_824F7D28:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r31,124
	r29.s64 = r31.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F7D38:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F7D40;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f7d38
	if (!cr0.eq) goto loc_824F7D38;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f7d60
	if (cr6.eq) goto loc_824F7D60;
	// bl 0x8244a330
	ctx.lr = 0x824F7D5C;
	sub_8244A330(ctx, base);
	// stw r26,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r26.u32);
loc_824F7D60:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f7d74
	if (cr6.eq) goto loc_824F7D74;
	// bl 0x82130588
	ctx.lr = 0x824F7D70;
	sub_82130588(ctx, base);
	// stw r25,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r25.u32);
loc_824F7D74:
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F7D88;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d923c
	return;
loc_824F7D98:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f7ddc
	if (cr6.eq) goto loc_824F7DDC;
	// lwz r3,180(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f7ddc
	if (cr6.eq) goto loc_824F7DDC;
	// li r5,152
	ctx.r5.s64 = 152;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x824F7DBC;
	sub_823DA950(ctx, base);
	// lwz r11,180(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r10,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r10.u32);
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// lwz r9,180(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// stfs f0,68(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 68, temp.u32);
	// lwz r8,180(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// stw r25,72(r8)
	PPC_STORE_U32(ctx.r8.u32 + 72, r25.u32);
loc_824F7DDC:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f7e00
	if (!cr6.eq) goto loc_824F7E00;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F7E00:
	// bl 0x821ce0a0
	ctx.lr = 0x824F7E04;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824F7E10"))) PPC_WEAK_FUNC(sub_824F7E10);
PPC_FUNC_IMPL(__imp__sub_824F7E10) {
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
	ctx.lr = 0x824F7E18;
	// stwu r1,-576(r1)
	ea = -576 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F7E2C;
	sub_824F9438(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r27,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, r27.u32);
	// addi r3,r1,236
	ctx.r3.s64 = ctx.r1.s64 + 236;
	// stb r27,329(r1)
	PPC_STORE_U8(ctx.r1.u32 + 329, r27.u8);
	// bl 0x8244d150
	ctx.lr = 0x824F7E4C;
	sub_8244D150(ctx, base);
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,248
	ctx.r3.s64 = ctx.r1.s64 + 248;
	// bl 0x8244d150
	ctx.lr = 0x824F7E5C;
	sub_8244D150(ctx, base);
	// lbz r11,72(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 72);
	// addi r6,r24,32
	ctx.r6.s64 = r24.s64 + 32;
	// lwz r9,56(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 56);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r7,48(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 48);
	// lwz r5,24(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// lwz r4,20(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// lwz r10,60(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 60);
	// lwz r8,52(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 52);
	// stb r11,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r11.u8);
	// lwz r31,68(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 68);
	// lwz r30,64(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 64);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824f2c00
	ctx.lr = 0x824F7E98;
	sub_824F2C00(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r23,-1
	r23.s64 = -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f80b8
	if (cr6.eq) goto loc_824F80B8;
	// lwz r11,52(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 52);
	// li r31,304
	r31.s64 = 304;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7ed0
	if (cr6.eq) goto loc_824F7ED0;
	// lwz r10,60(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 60);
loc_824F7EBC:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// bne 0x824f7ebc
	if (!cr0.eq) goto loc_824F7EBC;
loc_824F7ED0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x824F7ED8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f80bc
	if (cr6.eq) goto loc_824F80BC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r10,r11,31736
	ctx.r10.s64 = r11.s64 + 31736;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824f55a0
	ctx.lr = 0x824F7F08;
	sub_824F55A0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f80b8
	if (cr6.eq) goto loc_824F80B8;
	// lwz r4,124(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 124);
	// mr r30,r27
	r30.u64 = r27.u64;
	// subf r11,r4,r23
	r11.s64 = r23.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f7f80
	if (cr6.eq) goto loc_824F7F80;
	// lwz r31,112(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F7F50;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7f80
	if (cr6.eq) goto loc_824F7F80;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 124);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F7F70;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f7f80
	if (cr6.eq) goto loc_824F7F80;
	// li r30,1
	r30.s64 = 1;
loc_824F7F80:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f80b8
	if (cr6.eq) goto loc_824F80B8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x824F7F94;
	sub_82130588(ctx, base);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r27.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// bl 0x824f3c90
	ctx.lr = 0x824F7FB4;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f80b8
	if (cr6.eq) goto loc_824F80B8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r26,r11,32120
	r26.s64 = r11.s64 + 32120;
loc_824F7FC8:
	// lwz r28,8(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f8130
	if (!cr6.eq) goto loc_824F8130;
	// lwz r29,120(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r30,116(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82257678
	ctx.lr = 0x824F7FF4;
	sub_82257678(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82618750
	ctx.lr = 0x824F8000;
	sub_82618750(ctx, base);
	// subf r5,r31,r29
	ctx.r5.s64 = r29.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x826185e0
	ctx.lr = 0x824F8010;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f8040
	if (cr6.eq) goto loc_824F8040;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f8040
	if (!cr6.eq) goto loc_824F8040;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82618db0
	ctx.lr = 0x824F8030;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f8044
	if (!cr6.eq) goto loc_824F8044;
loc_824F8040:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824F8044:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8068
	if (cr6.eq) goto loc_824F8068;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x826186b0
	ctx.lr = 0x824F8058;
	sub_826186B0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f806c
	if (cr6.eq) goto loc_824F806C;
loc_824F8068:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824F806C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f80b8
	if (cr6.eq) goto loc_824F80B8;
	// lwz r3,80(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f808c
	if (cr6.eq) goto loc_824F808C;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x821ce080
	ctx.lr = 0x824F808C;
	sub_821CE080(ctx, base);
loc_824F808C:
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r27.u32);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F80AC;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f7fc8
	if (!cr6.eq) goto loc_824F7FC8;
loc_824F80B8:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
loc_824F80BC:
	// bl 0x824f22d0
	ctx.lr = 0x824F80C0;
	sub_824F22D0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r25,124
	r29.s64 = r25.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F80D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F80D8;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f80d0
	if (!cr0.eq) goto loc_824F80D0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f80f8
	if (cr6.eq) goto loc_824F80F8;
	// bl 0x8244a330
	ctx.lr = 0x824F80F4;
	sub_8244A330(ctx, base);
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
loc_824F80F8:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f810c
	if (cr6.eq) goto loc_824F810C;
	// bl 0x82130588
	ctx.lr = 0x824F8108;
	sub_82130588(ctx, base);
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_824F810C:
	// lwz r31,8(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F8120;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// b 0x823d9234
	return;
loc_824F8130:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r31,r10,31640
	r31.s64 = ctx.r10.s64 + 31640;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824f80b8
	if (!cr6.eq) goto loc_824F80B8;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x824f6bb8
	ctx.lr = 0x824F814C;
	sub_824F6BB8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x824f5968
	ctx.lr = 0x824F8164;
	sub_824F5968(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f80b8
	if (cr6.eq) goto loc_824F80B8;
	// lbz r10,336(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 336);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f818c
	if (cr6.eq) goto loc_824F818C;
	// addi r4,r1,344
	ctx.r4.s64 = ctx.r1.s64 + 344;
	// lwz r3,76(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 76);
	// li r5,152
	ctx.r5.s64 = 152;
	// bl 0x823da950
	ctx.lr = 0x824F818C;
	sub_823DA950(ctx, base);
loc_824F818C:
	// lbz r10,336(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 336);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,340(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f81b0
	if (!cr6.eq) goto loc_824F81B0;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F81B0:
	// bl 0x821ce0a0
	ctx.lr = 0x824F81B4;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824f22d0
	ctx.lr = 0x824F81C0;
	sub_824F22D0(ctx, base);
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824F81C8"))) PPC_WEAK_FUNC(sub_824F81C8);
PPC_FUNC_IMPL(__imp__sub_824F81C8) {
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
	ctx.lr = 0x824F81D0;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// bl 0x824f6c00
	ctx.lr = 0x824F81E4;
	sub_824F6C00(ctx, base);
	// lbz r11,196(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 196);
	// addi r5,r24,24
	ctx.r5.s64 = r24.s64 + 24;
	// lwz r10,192(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 192);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// lwz r9,188(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 188);
	// lwz r7,180(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 180);
	// lwz r4,20(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// lwz r8,184(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 184);
	// lwz r6,176(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 176);
	// stb r11,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r11.u8);
	// bl 0x824f2d90
	ctx.lr = 0x824F8210;
	sub_824F2D90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r26,0
	r26.s64 = 0;
	// li r23,-1
	r23.s64 = -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8434
	if (cr6.eq) goto loc_824F8434;
	// lwz r11,176(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 176);
	// li r31,416
	r31.s64 = 416;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f824c
	if (cr6.eq) goto loc_824F824C;
	// lwz r10,184(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 184);
loc_824F8238:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r31,r31,r9
	r31.u64 = r31.u64 + ctx.r9.u64;
	// bne 0x824f8238
	if (!cr0.eq) goto loc_824F8238;
loc_824F824C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x824F8254;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f8438
	if (cr6.eq) goto loc_824F8438;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r10,r11,31672
	ctx.r10.s64 = r11.s64 + 31672;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824f5658
	ctx.lr = 0x824F8284;
	sub_824F5658(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f8434
	if (cr6.eq) goto loc_824F8434;
	// lwz r4,124(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 124);
	// mr r30,r26
	r30.u64 = r26.u64;
	// subf r11,r4,r23
	r11.s64 = r23.s64 - ctx.r4.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824f82fc
	if (cr6.eq) goto loc_824F82FC;
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// bl 0x824f2900
	ctx.lr = 0x824F82CC;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f82fc
	if (cr6.eq) goto loc_824F82FC;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,124(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 124);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f2900
	ctx.lr = 0x824F82EC;
	sub_824F2900(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f82fc
	if (cr6.eq) goto loc_824F82FC;
	// li r30,1
	r30.s64 = 1;
loc_824F82FC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8434
	if (cr6.eq) goto loc_824F8434;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x824F8310;
	sub_82130588(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// bl 0x824f3c90
	ctx.lr = 0x824F8330;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8434
	if (cr6.eq) goto loc_824F8434;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r27,r11,32120
	r27.s64 = r11.s64 + 32120;
loc_824F8344:
	// lwz r28,8(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f84ac
	if (!cr6.eq) goto loc_824F84AC;
	// lwz r29,104(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82257678
	ctx.lr = 0x824F8370;
	sub_82257678(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618750
	ctx.lr = 0x824F837C;
	sub_82618750(ctx, base);
	// subf r5,r31,r29
	ctx.r5.s64 = r29.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826185e0
	ctx.lr = 0x824F838C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f83bc
	if (cr6.eq) goto loc_824F83BC;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824f83bc
	if (!cr6.eq) goto loc_824F83BC;
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618db0
	ctx.lr = 0x824F83AC;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f83c0
	if (!cr6.eq) goto loc_824F83C0;
loc_824F83BC:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_824F83C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f83e4
	if (cr6.eq) goto loc_824F83E4;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826186b0
	ctx.lr = 0x824F83D4;
	sub_826186B0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f83e8
	if (cr6.eq) goto loc_824F83E8;
loc_824F83E4:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_824F83E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8434
	if (cr6.eq) goto loc_824F8434;
	// lwz r3,204(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 204);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f8408
	if (cr6.eq) goto loc_824F8408;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x821ce080
	ctx.lr = 0x824F8408;
	sub_821CE080(ctx, base);
loc_824F8408:
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824f3c90
	ctx.lr = 0x824F8428;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f8344
	if (!cr6.eq) goto loc_824F8344;
loc_824F8434:
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
loc_824F8438:
	// bl 0x824f2328
	ctx.lr = 0x824F843C;
	sub_824F2328(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r25,124
	r29.s64 = r25.s64 + 124;
	// addi r30,r11,30648
	r30.s64 = r11.s64 + 30648;
	// li r31,4
	r31.s64 = 4;
loc_824F844C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534698
	ctx.lr = 0x824F8454;
	sub_82534698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// bne 0x824f844c
	if (!cr0.eq) goto loc_824F844C;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824f8474
	if (cr6.eq) goto loc_824F8474;
	// bl 0x8244a330
	ctx.lr = 0x824F8470;
	sub_8244A330(ctx, base);
	// stw r23,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r23.u32);
loc_824F8474:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824f8488
	if (cr6.eq) goto loc_824F8488;
	// bl 0x82130588
	ctx.lr = 0x824F8484;
	sub_82130588(ctx, base);
	// stw r26,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r26.u32);
loc_824F8488:
	// lwz r31,8(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F849C;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9234
	return;
loc_824F84AC:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r31,r10,32088
	r31.s64 = ctx.r10.s64 + 32088;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824f8434
	if (!cr6.eq) goto loc_824F8434;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824f6bb8
	ctx.lr = 0x824F84C8;
	sub_824F6BB8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x824f5968
	ctx.lr = 0x824F84E0;
	sub_824F5968(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8434
	if (cr6.eq) goto loc_824F8434;
	// lbz r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8508
	if (cr6.eq) goto loc_824F8508;
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// lwz r3,200(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 200);
	// li r5,152
	ctx.r5.s64 = 152;
	// bl 0x823da950
	ctx.lr = 0x824F8508;
	sub_823DA950(ctx, base);
loc_824F8508:
	// lbz r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 144);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r30,148(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x824f852c
	if (!cr6.eq) goto loc_824F852C;
	// li r4,2
	ctx.r4.s64 = 2;
loc_824F852C:
	// bl 0x821ce0a0
	ctx.lr = 0x824F8530;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x824f2328
	ctx.lr = 0x824F853C;
	sub_824F2328(ctx, base);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824F8544"))) PPC_WEAK_FUNC(sub_824F8544);
PPC_FUNC_IMPL(__imp__sub_824F8544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F8548"))) PPC_WEAK_FUNC(sub_824F8548);
PPC_FUNC_IMPL(__imp__sub_824F8548) {
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
	ctx.lr = 0x824F8550;
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x824f9438
	ctx.lr = 0x824F8564;
	sub_824F9438(ctx, base);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x824f5a50
	ctx.lr = 0x824F856C;
	sub_824F5A50(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// addi r5,r28,24
	ctx.r5.s64 = r28.s64 + 24;
	// lwz r6,176(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// stw r29,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, r29.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// lwz r4,20(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwz r7,180(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// bl 0x824f2e78
	ctx.lr = 0x824F858C;
	sub_824F2E78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f86d8
	if (cr6.eq) goto loc_824F86D8;
	// lwz r11,180(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// addi r30,r11,384
	r30.s64 = r11.s64 + 384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x824F85A8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f86d8
	if (cr6.eq) goto loc_824F86D8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,31768
	ctx.r10.s64 = r11.s64 + 31768;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824f58b0
	ctx.lr = 0x824F85D8;
	sub_824F58B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f86d8
	if (cr6.eq) goto loc_824F86D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f29f8
	ctx.lr = 0x824F85F4;
	sub_824F29F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f86d8
	if (cr6.eq) goto loc_824F86D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x824F8608;
	sub_82130588(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// bl 0x824f3c90
	ctx.lr = 0x824F8628;
	sub_824F3C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f86d8
	if (cr6.eq) goto loc_824F86D8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r11,31928
	r31.s64 = r11.s64 + 31928;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824f86d8
	if (!cr6.eq) goto loc_824F86D8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f6bb8
	ctx.lr = 0x824F8654;
	sub_824F6BB8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824f5968
	ctx.lr = 0x824F866C;
	sub_824F5968(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f86d8
	if (cr6.eq) goto loc_824F86D8;
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8694
	if (cr6.eq) goto loc_824F8694;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,184(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 184);
	// li r5,152
	ctx.r5.s64 = 152;
	// bl 0x823da950
	ctx.lr = 0x824F8694;
	sub_823DA950(ctx, base);
loc_824F8694:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824f86c4
	if (cr6.eq) goto loc_824F86C4;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824F86B8;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// b 0x823d9244
	return;
loc_824F86C4:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824F86CC;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// b 0x823d9244
	return;
loc_824F86D8:
	// addi r3,r27,124
	ctx.r3.s64 = r27.s64 + 124;
	// bl 0x824f2448
	ctx.lr = 0x824F86E0;
	sub_824F2448(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F86F4;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F8704"))) PPC_WEAK_FUNC(sub_824F8704);
PPC_FUNC_IMPL(__imp__sub_824F8704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F8708"))) PPC_WEAK_FUNC(sub_824F8708);
PPC_FUNC_IMPL(__imp__sub_824F8708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r15{};
	PPCRegister r18{};
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8730;
	sub_821C8FE0(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r11,80
	ctx.r3.s64 = r11.s64 + 80;
	// lwz r4,80(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// extsw r30,r4
	r30.s64 = ctx.r4.s32;
	// beq cr6,0x824f874c
	if (cr6.eq) goto loc_824F874C;
	// bl 0x824f3d58
	ctx.lr = 0x824F874C;
	sub_824F3D58(ctx, base);
loc_824F874C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8754;
	sub_821C9030(ctx, base);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f2758
	ctx.lr = 0x824F875C;
	sub_824F2758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f879c
	if (!cr6.eq) goto loc_824F879C;
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f88ac
	if (cr6.eq) goto loc_824F88AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824f88ac
	if (!cr6.eq) goto loc_824F88AC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824F8790;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F879C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bgt cr6,0x824f88ac
	if (cr6.gt) goto loc_824F88AC;
	// lis r12,-32176
	r12.s64 = -2108686336;
	// addi r12,r12,-30784
	r12.s64 = r12.s64 + -30784;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824F87F0;
	case 1:
		goto loc_824F8800;
	case 2:
		goto loc_824F8810;
	case 3:
		goto loc_824F8820;
	case 4:
		goto loc_824F8830;
	case 5:
		goto loc_824F8840;
	case 6:
		goto loc_824F8850;
	case 7:
		goto loc_824F8860;
	case 8:
		goto loc_824F8870;
	case 9:
		goto loc_824F8880;
	case 10:
		goto loc_824F8890;
	case 11:
		goto loc_824F88A0;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-30736(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30736);
	// lwz r18,-30720(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30720);
	// lwz r18,-30704(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30704);
	// lwz r18,-30688(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30688);
	// lwz r18,-30672(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30672);
	// lwz r18,-30656(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30656);
	// lwz r18,-30640(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30640);
	// lwz r18,-30624(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30624);
	// lwz r18,-30608(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30608);
	// lwz r18,-30592(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30592);
	// lwz r18,-30576(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30576);
	// lwz r18,-30560(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -30560);
loc_824F87F0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f5d08
	ctx.lr = 0x824F87FC;
	sub_824F5D08(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8800:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f5f30
	ctx.lr = 0x824F880C;
	sub_824F5F30(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8810:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f6190
	ctx.lr = 0x824F881C;
	sub_824F6190(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8820:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f7718
	ctx.lr = 0x824F882C;
	sub_824F7718(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8830:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f6468
	ctx.lr = 0x824F883C;
	sub_824F6468(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8840:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f7990
	ctx.lr = 0x824F884C;
	sub_824F7990(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8850:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f7bd8
	ctx.lr = 0x824F885C;
	sub_824F7BD8(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8860:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f66a0
	ctx.lr = 0x824F886C;
	sub_824F66A0(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8870:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f7e10
	ctx.lr = 0x824F887C;
	sub_824F7E10(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8880:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f81c8
	ctx.lr = 0x824F888C;
	sub_824F81C8(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F8890:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f68a8
	ctx.lr = 0x824F889C;
	sub_824F68A8(ctx, base);
	// b 0x824f88ac
	goto loc_824F88AC;
loc_824F88A0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x824f8548
	ctx.lr = 0x824F88AC;
	sub_824F8548(ctx, base);
loc_824F88AC:
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
	ctx.lr = 0x824F88C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,32268(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32268);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824F88E0;
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

__attribute__((alias("__imp__sub_824F88F8"))) PPC_WEAK_FUNC(sub_824F88F8);
PPC_FUNC_IMPL(__imp__sub_824F88F8) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,148(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 148);
	// blr 
	return;
}

