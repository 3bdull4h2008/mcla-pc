#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82483018"))) PPC_WEAK_FUNC(sub_82483018);
PPC_FUNC_IMPL(__imp__sub_82483018) {
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
	ctx.lr = 0x82483020;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// bl 0x82618d38
	ctx.lr = 0x82483038;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483054
	if (cr6.eq) goto loc_82483054;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82483058
	if (!cr6.eq) goto loc_82483058;
loc_82483054:
	// li r11,0
	r11.s64 = 0;
loc_82483058:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824830f0
	if (cr6.eq) goto loc_824830F0;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa288
	ctx.lr = 0x82483070;
	sub_824FA288(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824830f0
	if (cr6.eq) goto loc_824830F0;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,104
	ctx.r4.s64 = r31.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x8248308C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824830f0
	if (cr6.eq) goto loc_824830F0;
	// addi r29,r31,108
	r29.s64 = r31.s64 + 108;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x824830AC;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824830f0
	if (cr6.eq) goto loc_824830F0;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,512
	cr6.compare<uint32_t>(ctx.r5.u32, 512, xer);
	// bgt cr6,0x824830f0
	if (cr6.gt) goto loc_824830F0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824830dc
	if (cr6.eq) goto loc_824830DC;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x824830D8;
	sub_82618F90(ctx, base);
	// b 0x824830e0
	goto loc_824830E0;
loc_824830DC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824830E0:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824830f4
	if (!cr6.eq) goto loc_824830F4;
loc_824830F0:
	// li r11,0
	r11.s64 = 0;
loc_824830F4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82483100"))) PPC_WEAK_FUNC(sub_82483100);
PPC_FUNC_IMPL(__imp__sub_82483100) {
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
	ctx.lr = 0x82483108;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82618c90
	ctx.lr = 0x8248311C;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483138
	if (cr6.eq) goto loc_82483138;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8248313c
	if (!cr6.eq) goto loc_8248313C;
loc_82483138:
	// li r11,0
	r11.s64 = 0;
loc_8248313C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824831d4
	if (cr6.eq) goto loc_824831D4;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fa280
	ctx.lr = 0x82483154;
	sub_824FA280(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824831d4
	if (cr6.eq) goto loc_824831D4;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,104
	ctx.r4.s64 = r31.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x82483170;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824831d4
	if (cr6.eq) goto loc_824831D4;
	// addi r29,r31,108
	r29.s64 = r31.s64 + 108;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x82483190;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824831d4
	if (cr6.eq) goto loc_824831D4;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,512
	cr6.compare<uint32_t>(ctx.r5.u32, 512, xer);
	// bgt cr6,0x824831d4
	if (cr6.gt) goto loc_824831D4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824831c0
	if (cr6.eq) goto loc_824831C0;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x824831BC;
	sub_82618F80(ctx, base);
	// b 0x824831c4
	goto loc_824831C4;
loc_824831C0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824831C4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824831d8
	if (!cr6.eq) goto loc_824831D8;
loc_824831D4:
	// li r11,0
	r11.s64 = 0;
loc_824831D8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824831E4"))) PPC_WEAK_FUNC(sub_824831E4);
PPC_FUNC_IMPL(__imp__sub_824831E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824831E8"))) PPC_WEAK_FUNC(sub_824831E8);
PPC_FUNC_IMPL(__imp__sub_824831E8) {
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
	ctx.lr = 0x824831F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// beq cr6,0x82483238
	if (cr6.eq) goto loc_82483238;
loc_82483208:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// ld r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ld r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// bl 0x82481e58
	ctx.lr = 0x8248322C;
	sub_82481E58(ctx, base);
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bne cr6,0x82483208
	if (!cr6.eq) goto loc_82483208;
loc_82483238:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82483240"))) PPC_WEAK_FUNC(sub_82483240);
PPC_FUNC_IMPL(__imp__sub_82483240) {
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
	ctx.lr = 0x82483248;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// mr r21,r30
	r21.u64 = r30.u64;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// bge cr6,0x8248331c
	if (!cr6.lt) goto loc_8248331C;
loc_82483280:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r28,r11,r29
	r28.u64 = r11.u64 + r29.u64;
	// addi r3,r28,-48
	ctx.r3.s64 = r28.s64 + -48;
	// bl 0x824f97c0
	ctx.lr = 0x82483298;
	sub_824F97C0(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824832A4;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r20
	cr6.compare<uint64_t>(ctx.r3.u64, r20.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824832b4
	if (cr6.lt) goto loc_824832B4;
	// li r11,0
	r11.s64 = 0;
loc_824832B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824832c4
	if (cr6.eq) goto loc_824832C4;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_824832C4:
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r31,r10
	ctx.r10.u64 = r31.u64 + ctx.r10.u64;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + r29.u64;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824832F0:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824832f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824832F0;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// mr r30,r31
	r30.u64 = r31.u64;
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x82483280
	if (cr6.lt) goto loc_82483280;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
loc_8248331C:
	// bne cr6,0x82483364
	if (!cr6.eq) goto loc_82483364;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r31,r10
	ctx.r10.u64 = r31.u64 + ctx.r10.u64;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8248334C:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8248334c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8248334C;
	// addi r30,r31,-1
	r30.s64 = r31.s64 + -1;
loc_82483364:
	// ld r3,296(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 296);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// lbz r11,311(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r11,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r11.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481f08
	ctx.lr = 0x82483398;
	sub_82481F08(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824833A0"))) PPC_WEAK_FUNC(sub_824833A0);
PPC_FUNC_IMPL(__imp__sub_824833A0) {
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
	ctx.lr = 0x824833A8;
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
	ctx.lr = 0x824833CC;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824833D8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824833E8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248340c
	if (cr6.eq) goto loc_8248340C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82482ab8
	ctx.lr = 0x824833FC;
	sub_82482AB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483410
	if (!cr6.eq) goto loc_82483410;
loc_8248340C:
	// li r30,0
	r30.s64 = 0;
loc_82483410:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82483448
	if (cr6.eq) goto loc_82483448;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483440
	if (cr6.eq) goto loc_82483440;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8248342C;
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
loc_82483440:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82483448:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82483454"))) PPC_WEAK_FUNC(sub_82483454);
PPC_FUNC_IMPL(__imp__sub_82483454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483458"))) PPC_WEAK_FUNC(sub_82483458);
PPC_FUNC_IMPL(__imp__sub_82483458) {
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
	ctx.lr = 0x82483460;
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
	ctx.lr = 0x82483490;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8248349C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824834AC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824834dc
	if (cr6.eq) goto loc_824834DC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824834dc
	if (!cr6.eq) goto loc_824834DC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82482b90
	ctx.lr = 0x824834CC;
	sub_82482B90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824834e0
	if (!cr6.eq) goto loc_824834E0;
loc_824834DC:
	// li r31,0
	r31.s64 = 0;
loc_824834E0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8248350c
	if (cr6.eq) goto loc_8248350C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483504
	if (cr6.eq) goto loc_82483504;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824834FC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82483508
	goto loc_82483508;
loc_82483504:
	// li r11,0
	r11.s64 = 0;
loc_82483508:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8248350C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483530
	if (cr6.eq) goto loc_82483530;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82483520;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82483534
	if (cr6.eq) goto loc_82483534;
loc_82483530:
	// li r11,0
	r11.s64 = 0;
loc_82483534:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82483540"))) PPC_WEAK_FUNC(sub_82483540);
PPC_FUNC_IMPL(__imp__sub_82483540) {
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
	ctx.lr = 0x82483548;
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
	ctx.lr = 0x82483578;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x82483584;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82483594;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824835c4
	if (cr6.eq) goto loc_824835C4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824835c4
	if (!cr6.eq) goto loc_824835C4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82482c68
	ctx.lr = 0x824835B4;
	sub_82482C68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824835c8
	if (!cr6.eq) goto loc_824835C8;
loc_824835C4:
	// li r31,0
	r31.s64 = 0;
loc_824835C8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824835f4
	if (cr6.eq) goto loc_824835F4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824835ec
	if (cr6.eq) goto loc_824835EC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824835E4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824835f0
	goto loc_824835F0;
loc_824835EC:
	// li r11,0
	r11.s64 = 0;
loc_824835F0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824835F4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483618
	if (cr6.eq) goto loc_82483618;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82483608;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8248361c
	if (cr6.eq) goto loc_8248361C;
loc_82483618:
	// li r11,0
	r11.s64 = 0;
loc_8248361C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82483628"))) PPC_WEAK_FUNC(sub_82483628);
PPC_FUNC_IMPL(__imp__sub_82483628) {
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
	ctx.lr = 0x82483630;
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
	ctx.lr = 0x82483660;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8248366C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8248367C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824836ac
	if (cr6.eq) goto loc_824836AC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824836ac
	if (!cr6.eq) goto loc_824836AC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82482cf8
	ctx.lr = 0x8248369C;
	sub_82482CF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824836b0
	if (!cr6.eq) goto loc_824836B0;
loc_824836AC:
	// li r31,0
	r31.s64 = 0;
loc_824836B0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824836dc
	if (cr6.eq) goto loc_824836DC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824836d4
	if (cr6.eq) goto loc_824836D4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824836CC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824836d8
	goto loc_824836D8;
loc_824836D4:
	// li r11,0
	r11.s64 = 0;
loc_824836D8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824836DC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483700
	if (cr6.eq) goto loc_82483700;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824836F0;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82483704
	if (cr6.eq) goto loc_82483704;
loc_82483700:
	// li r11,0
	r11.s64 = 0;
loc_82483704:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82483710"))) PPC_WEAK_FUNC(sub_82483710);
PPC_FUNC_IMPL(__imp__sub_82483710) {
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
	ctx.lr = 0x82483718;
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
	ctx.lr = 0x8248373C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82483748;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82483758;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248377c
	if (cr6.eq) goto loc_8248377C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82482d50
	ctx.lr = 0x8248376C;
	sub_82482D50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483780
	if (!cr6.eq) goto loc_82483780;
loc_8248377C:
	// li r30,0
	r30.s64 = 0;
loc_82483780:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824837b8
	if (cr6.eq) goto loc_824837B8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824837b0
	if (cr6.eq) goto loc_824837B0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x8248379C;
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
loc_824837B0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824837B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824837C4"))) PPC_WEAK_FUNC(sub_824837C4);
PPC_FUNC_IMPL(__imp__sub_824837C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824837C8"))) PPC_WEAK_FUNC(sub_824837C8);
PPC_FUNC_IMPL(__imp__sub_824837C8) {
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
	ctx.lr = 0x824837D0;
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
	ctx.lr = 0x82483800;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8248380C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x8248381C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8248384c
	if (cr6.eq) goto loc_8248384C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x8248384c
	if (!cr6.eq) goto loc_8248384C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82482e08
	ctx.lr = 0x8248383C;
	sub_82482E08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483850
	if (!cr6.eq) goto loc_82483850;
loc_8248384C:
	// li r31,0
	r31.s64 = 0;
loc_82483850:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8248387c
	if (cr6.eq) goto loc_8248387C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483874
	if (cr6.eq) goto loc_82483874;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x8248386C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82483878
	goto loc_82483878;
loc_82483874:
	// li r11,0
	r11.s64 = 0;
loc_82483878:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8248387C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824838a0
	if (cr6.eq) goto loc_824838A0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82483890;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824838a4
	if (cr6.eq) goto loc_824838A4;
loc_824838A0:
	// li r11,0
	r11.s64 = 0;
loc_824838A4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824838B0"))) PPC_WEAK_FUNC(sub_824838B0);
PPC_FUNC_IMPL(__imp__sub_824838B0) {
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
	ctx.lr = 0x824838B8;
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
	ctx.lr = 0x824838E8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824838F4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82483904;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82483934
	if (cr6.eq) goto loc_82483934;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82483934
	if (!cr6.eq) goto loc_82483934;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82482e98
	ctx.lr = 0x82483924;
	sub_82482E98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483938
	if (!cr6.eq) goto loc_82483938;
loc_82483934:
	// li r31,0
	r31.s64 = 0;
loc_82483938:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82483964
	if (cr6.eq) goto loc_82483964;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248395c
	if (cr6.eq) goto loc_8248395C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82483954;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82483960
	goto loc_82483960;
loc_8248395C:
	// li r11,0
	r11.s64 = 0;
loc_82483960:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82483964:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483988
	if (cr6.eq) goto loc_82483988;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82483978;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8248398c
	if (cr6.eq) goto loc_8248398C;
loc_82483988:
	// li r11,0
	r11.s64 = 0;
loc_8248398C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82483998"))) PPC_WEAK_FUNC(sub_82483998);
PPC_FUNC_IMPL(__imp__sub_82483998) {
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
	ctx.lr = 0x824839A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,2264
	r29.s64 = r31.s64 + 2264;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1160
	ctx.lr = 0x824839B4;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483a9c
	if (cr6.eq) goto loc_82483A9C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1160
	ctx.lr = 0x824839C8;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824839ec
	if (cr6.eq) goto loc_824839EC;
	// addi r3,r31,4408
	ctx.r3.s64 = r31.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x824839DC;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824839f0
	if (cr6.eq) goto loc_824839F0;
loc_824839EC:
	// li r11,0
	r11.s64 = 0;
loc_824839F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483a9c
	if (cr6.eq) goto loc_82483A9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824815a8
	ctx.lr = 0x82483A04;
	sub_824815A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483a9c
	if (cr6.eq) goto loc_82483A9C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0e40
	ctx.lr = 0x82483A18;
	sub_824E0E40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824825f0
	ctx.lr = 0x82483A24;
	sub_824825F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483a9c
	if (cr6.eq) goto loc_82483A9C;
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82483a9c
	if (!cr6.eq) goto loc_82483A9C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1258
	ctx.lr = 0x82483A48;
	sub_824E1258(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483a60
	if (cr6.eq) goto loc_82483A60;
	// lwz r11,11588(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11588);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bgt cr6,0x82483a9c
	if (cr6.gt) goto loc_82483A9C;
loc_82483A60:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e12a8
	ctx.lr = 0x82483A68;
	sub_824E12A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483a88
	if (cr6.eq) goto loc_82483A88;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252a6e8
	ctx.lr = 0x82483A7C;
	sub_8252A6E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483a9c
	if (!cr6.eq) goto loc_82483A9C;
loc_82483A88:
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82483aa0
	if (!cr6.eq) goto loc_82483AA0;
loc_82483A9C:
	// li r11,0
	r11.s64 = 0;
loc_82483AA0:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82483b10
	if (cr6.eq) goto loc_82483B10;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e12a8
	ctx.lr = 0x82483AB4;
	sub_824E12A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483b10
	if (cr6.eq) goto loc_82483B10;
	// lwz r3,11548(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 11548);
	// addi r11,r31,11548
	r11.s64 = r31.s64 + 11548;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// beq cr6,0x82483b10
	if (cr6.eq) goto loc_82483B10;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r31,r11,-8472
	r31.s64 = r11.s64 + -8472;
loc_82483AE0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82483AF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// beq cr6,0x82483b1c
	if (cr6.eq) goto loc_82483B1C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82482730
	ctx.lr = 0x82483B04;
	sub_82482730(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82483ae0
	if (!cr6.eq) goto loc_82483AE0;
loc_82483B10:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82483B1C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82483B28"))) PPC_WEAK_FUNC(sub_82483B28);
PPC_FUNC_IMPL(__imp__sub_82483B28) {
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
	// bl 0x82481b70
	ctx.lr = 0x82483B38;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82483b48
	if (cr6.eq) goto loc_82483B48;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82483b4c
	goto loc_82483B4C;
loc_82483B48:
	// li r11,-1
	r11.s64 = -1;
loc_82483B4C:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82483B6C"))) PPC_WEAK_FUNC(sub_82483B6C);
PPC_FUNC_IMPL(__imp__sub_82483B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483B70"))) PPC_WEAK_FUNC(sub_82483B70);
PPC_FUNC_IMPL(__imp__sub_82483B70) {
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
	ctx.lr = 0x82483B78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,2264
	r29.s64 = ctx.r3.s64 + 2264;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x824e1160
	ctx.lr = 0x82483B90;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483ba8
	if (!cr6.eq) goto loc_82483BA8;
loc_82483B9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82483BA8:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r10,r11,32364
	ctx.r10.s64 = r11.s64 + 32364;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82482260
	ctx.lr = 0x82483BC8;
	sub_82482260(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82483b9c
	if (cr6.eq) goto loc_82483B9C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0f78
	ctx.lr = 0x82483BDC;
	sub_824E0F78(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e6358
	ctx.lr = 0x82483BE4;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_82483BFC"))) PPC_WEAK_FUNC(sub_82483BFC);
PPC_FUNC_IMPL(__imp__sub_82483BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483C00"))) PPC_WEAK_FUNC(sub_82483C00);
PPC_FUNC_IMPL(__imp__sub_82483C00) {
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
	ctx.lr = 0x82483C08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82483C24;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483c3c
	if (!cr6.eq) goto loc_82483C3C;
loc_82483C30:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82483C3C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82483C44;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483c68
	if (cr6.eq) goto loc_82483C68;
	// addi r3,r31,4408
	ctx.r3.s64 = r31.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x82483C58;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82483c6c
	if (cr6.eq) goto loc_82483C6C;
loc_82483C68:
	// li r11,0
	r11.s64 = 0;
loc_82483C6C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483c30
	if (cr6.eq) goto loc_82483C30;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22380
	ctx.r10.s64 = r11.s64 + 22380;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82482260
	ctx.lr = 0x82483C98;
	sub_82482260(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82483c30
	if (cr6.eq) goto loc_82483C30;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0f78
	ctx.lr = 0x82483CAC;
	sub_824E0F78(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824e6358
	ctx.lr = 0x82483CB4;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82483CCC"))) PPC_WEAK_FUNC(sub_82483CCC);
PPC_FUNC_IMPL(__imp__sub_82483CCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483CD0"))) PPC_WEAK_FUNC(sub_82483CD0);
PPC_FUNC_IMPL(__imp__sub_82483CD0) {
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
	// beq cr6,0x82483d10
	if (cr6.eq) goto loc_82483D10;
loc_82483CF0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82483d04
	if (cr6.eq) goto loc_82483D04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482830
	ctx.lr = 0x82483D04;
	sub_82482830(ctx, base);
loc_82483D04:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483cf0
	if (!cr6.eq) goto loc_82483CF0;
loc_82483D10:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82483D24"))) PPC_WEAK_FUNC(sub_82483D24);
PPC_FUNC_IMPL(__imp__sub_82483D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483D28"))) PPC_WEAK_FUNC(sub_82483D28);
PPC_FUNC_IMPL(__imp__sub_82483D28) {
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
	// beq cr6,0x82483d68
	if (cr6.eq) goto loc_82483D68;
loc_82483D48:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82483d5c
	if (cr6.eq) goto loc_82483D5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f8968
	ctx.lr = 0x82483D5C;
	sub_824F8968(ctx, base);
loc_82483D5C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483d48
	if (!cr6.eq) goto loc_82483D48;
loc_82483D68:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82483D7C"))) PPC_WEAK_FUNC(sub_82483D7C);
PPC_FUNC_IMPL(__imp__sub_82483D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483D80"))) PPC_WEAK_FUNC(sub_82483D80);
PPC_FUNC_IMPL(__imp__sub_82483D80) {
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
	// beq cr6,0x82483dc0
	if (cr6.eq) goto loc_82483DC0;
loc_82483DA0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82483db4
	if (cr6.eq) goto loc_82483DB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482670
	ctx.lr = 0x82483DB4;
	sub_82482670(ctx, base);
loc_82483DB4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483da0
	if (!cr6.eq) goto loc_82483DA0;
loc_82483DC0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82483DD4"))) PPC_WEAK_FUNC(sub_82483DD4);
PPC_FUNC_IMPL(__imp__sub_82483DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483DD8"))) PPC_WEAK_FUNC(sub_82483DD8);
PPC_FUNC_IMPL(__imp__sub_82483DD8) {
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
	ctx.lr = 0x82483DE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// bl 0x82618d38
	ctx.lr = 0x82483DF8;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483e14
	if (cr6.eq) goto loc_82483E14;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82483e18
	if (!cr6.eq) goto loc_82483E18;
loc_82483E14:
	// li r11,0
	r11.s64 = 0;
loc_82483E18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f10
	if (cr6.eq) goto loc_82483F10;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x82483E34;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f10
	if (cr6.eq) goto loc_82483F10;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x82483E50;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f10
	if (cr6.eq) goto loc_82483F10;
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x82483E70;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f10
	if (cr6.eq) goto loc_82483F10;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// bgt cr6,0x82483f10
	if (cr6.gt) goto loc_82483F10;
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x82483E9C;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f10
	if (cr6.eq) goto loc_82483F10;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// bgt cr6,0x82483f10
	if (cr6.gt) goto loc_82483F10;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82483ed0
	if (cr6.eq) goto loc_82483ED0;
	// addi r4,r31,24
	ctx.r4.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x82483ECC;
	sub_82618F90(ctx, base);
	// b 0x82483ed4
	goto loc_82483ED4;
loc_82483ED0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82483ED4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f10
	if (cr6.eq) goto loc_82483F10;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82483efc
	if (cr6.eq) goto loc_82483EFC;
	// addi r4,r31,536
	ctx.r4.s64 = r31.s64 + 536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x82483EF8;
	sub_82618F90(ctx, base);
	// b 0x82483f00
	goto loc_82483F00;
loc_82483EFC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82483F00:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82483f14
	if (!cr6.eq) goto loc_82483F14;
loc_82483F10:
	// li r11,0
	r11.s64 = 0;
loc_82483F14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82483F20"))) PPC_WEAK_FUNC(sub_82483F20);
PPC_FUNC_IMPL(__imp__sub_82483F20) {
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
	// bl 0x82483018
	ctx.lr = 0x82483F40;
	sub_82483018(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483f68
	if (cr6.eq) goto loc_82483F68;
	// addi r4,r30,624
	ctx.r4.s64 = r30.s64 + 624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fdcf8
	ctx.lr = 0x82483F58;
	sub_824FDCF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483f6c
	if (!cr6.eq) goto loc_82483F6C;
loc_82483F68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82483F6C:
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

__attribute__((alias("__imp__sub_82483F84"))) PPC_WEAK_FUNC(sub_82483F84);
PPC_FUNC_IMPL(__imp__sub_82483F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483F88"))) PPC_WEAK_FUNC(sub_82483F88);
PPC_FUNC_IMPL(__imp__sub_82483F88) {
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
	// bl 0x82483100
	ctx.lr = 0x82483FA8;
	sub_82483100(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82483fd0
	if (cr6.eq) goto loc_82483FD0;
	// addi r4,r30,624
	ctx.r4.s64 = r30.s64 + 624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fdda8
	ctx.lr = 0x82483FC0;
	sub_824FDDA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82483fd4
	if (!cr6.eq) goto loc_82483FD4;
loc_82483FD0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82483FD4:
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

__attribute__((alias("__imp__sub_82483FEC"))) PPC_WEAK_FUNC(sub_82483FEC);
PPC_FUNC_IMPL(__imp__sub_82483FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82483FF0"))) PPC_WEAK_FUNC(sub_82483FF0);
PPC_FUNC_IMPL(__imp__sub_82483FF0) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82618c90
	ctx.lr = 0x82484014;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484030
	if (cr6.eq) goto loc_82484030;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82484034
	if (!cr6.eq) goto loc_82484034;
loc_82484030:
	// li r11,0
	r11.s64 = 0;
loc_82484034:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248407c
	if (cr6.eq) goto loc_8248407C;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x82484050;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248407c
	if (cr6.eq) goto loc_8248407C;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x8248406C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82484080
	if (!cr6.eq) goto loc_82484080;
loc_8248407C:
	// li r11,0
	r11.s64 = 0;
loc_82484080:
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

__attribute__((alias("__imp__sub_8248409C"))) PPC_WEAK_FUNC(sub_8248409C);
PPC_FUNC_IMPL(__imp__sub_8248409C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824840A0"))) PPC_WEAK_FUNC(sub_824840A0);
PPC_FUNC_IMPL(__imp__sub_824840A0) {
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
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,32396
	ctx.r10.s64 = r11.s64 + 32396;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82275ca8
	ctx.lr = 0x824840DC;
	sub_82275CA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248410c
	if (cr6.eq) goto loc_8248410C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481238
	ctx.lr = 0x824840FC;
	sub_82481238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82484110
	if (!cr6.eq) goto loc_82484110;
loc_8248410C:
	// li r11,0
	r11.s64 = 0;
loc_82484110:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
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

__attribute__((alias("__imp__sub_8248412C"))) PPC_WEAK_FUNC(sub_8248412C);
PPC_FUNC_IMPL(__imp__sub_8248412C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484130"))) PPC_WEAK_FUNC(sub_82484130);
PPC_FUNC_IMPL(__imp__sub_82484130) {
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
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22508
	ctx.r10.s64 = r11.s64 + 22508;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824820a8
	ctx.lr = 0x8248416C;
	sub_824820A8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248419c
	if (cr6.eq) goto loc_8248419C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481238
	ctx.lr = 0x8248418C;
	sub_82481238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824841a0
	if (!cr6.eq) goto loc_824841A0;
loc_8248419C:
	// li r11,0
	r11.s64 = 0;
loc_824841A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
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

__attribute__((alias("__imp__sub_824841BC"))) PPC_WEAK_FUNC(sub_824841BC);
PPC_FUNC_IMPL(__imp__sub_824841BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824841C0"))) PPC_WEAK_FUNC(sub_824841C0);
PPC_FUNC_IMPL(__imp__sub_824841C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-8172
	ctx.r3.s64 = r11.s64 + -8172;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824841CC"))) PPC_WEAK_FUNC(sub_824841CC);
PPC_FUNC_IMPL(__imp__sub_824841CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824841D0"))) PPC_WEAK_FUNC(sub_824841D0);
PPC_FUNC_IMPL(__imp__sub_824841D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-8124
	ctx.r3.s64 = r11.s64 + -8124;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824841DC"))) PPC_WEAK_FUNC(sub_824841DC);
PPC_FUNC_IMPL(__imp__sub_824841DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824841E0"))) PPC_WEAK_FUNC(sub_824841E0);
PPC_FUNC_IMPL(__imp__sub_824841E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-8072
	ctx.r3.s64 = r11.s64 + -8072;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824841EC"))) PPC_WEAK_FUNC(sub_824841EC);
PPC_FUNC_IMPL(__imp__sub_824841EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824841F0"))) PPC_WEAK_FUNC(sub_824841F0);
PPC_FUNC_IMPL(__imp__sub_824841F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-8028
	ctx.r3.s64 = r11.s64 + -8028;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824841FC"))) PPC_WEAK_FUNC(sub_824841FC);
PPC_FUNC_IMPL(__imp__sub_824841FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484200"))) PPC_WEAK_FUNC(sub_82484200);
PPC_FUNC_IMPL(__imp__sub_82484200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-7980
	ctx.r3.s64 = r11.s64 + -7980;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248420C"))) PPC_WEAK_FUNC(sub_8248420C);
PPC_FUNC_IMPL(__imp__sub_8248420C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484210"))) PPC_WEAK_FUNC(sub_82484210);
PPC_FUNC_IMPL(__imp__sub_82484210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-7936
	ctx.r3.s64 = r11.s64 + -7936;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248421C"))) PPC_WEAK_FUNC(sub_8248421C);
PPC_FUNC_IMPL(__imp__sub_8248421C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484220"))) PPC_WEAK_FUNC(sub_82484220);
PPC_FUNC_IMPL(__imp__sub_82484220) {
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
	ctx.lr = 0x82484228;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r3,r29,4780
	ctx.r3.s64 = r29.s64 + 4780;
	// bl 0x8252e818
	ctx.lr = 0x8248423C;
	sub_8252E818(ctx, base);
	// addi r31,r29,4768
	r31.s64 = r29.s64 + 4768;
	// li r30,31
	r30.s64 = 31;
loc_82484244:
	// addi r31,r31,-96
	r31.s64 = r31.s64 + -96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8252eca8
	ctx.lr = 0x82484250;
	sub_8252ECA8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82484244
	if (!cr0.lt) goto loc_82484244;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82482008
	ctx.lr = 0x82484260;
	sub_82482008(ctx, base);
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484278
	if (cr6.eq) goto loc_82484278;
	// bl 0x82130588
	ctx.lr = 0x82484274;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82484278:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484280"))) PPC_WEAK_FUNC(sub_82484280);
PPC_FUNC_IMPL(__imp__sub_82484280) {
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
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x824c7068
	ctx.lr = 0x824842A4;
	sub_824C7068(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482008
	ctx.lr = 0x824842AC;
	sub_82482008(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824842c4
	if (cr6.eq) goto loc_824842C4;
	// bl 0x82130588
	ctx.lr = 0x824842C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824842C4:
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

__attribute__((alias("__imp__sub_824842DC"))) PPC_WEAK_FUNC(sub_824842DC);
PPC_FUNC_IMPL(__imp__sub_824842DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824842E0"))) PPC_WEAK_FUNC(sub_824842E0);
PPC_FUNC_IMPL(__imp__sub_824842E0) {
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
	ctx.lr = 0x824842E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// subf r11,r29,r4
	r11.s64 = ctx.r4.s64 - r29.s64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// divw r28,r11,r10
	r28.s32 = r11.s32 / ctx.r10.s32;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x82484398
	if (cr6.lt) goto loc_82484398;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// stb r27,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r27.u8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r30,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r30.s64 = temp.s64;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// ldx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + r29.u32);
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// ld r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// ld r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// bl 0x82483240
	ctx.lr = 0x82484350;
	sub_82483240(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82484398
	if (cr6.eq) goto loc_82484398;
loc_82484358:
	// addi r31,r31,-48
	r31.s64 = r31.s64 + -48;
	// stb r27,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r27.u8);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// ld r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// ld r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// ld r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// bl 0x82483240
	ctx.lr = 0x82484390;
	sub_82483240(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x82484358
	if (!cr6.eq) goto loc_82484358;
loc_82484398:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824843A0"))) PPC_WEAK_FUNC(sub_824843A0);
PPC_FUNC_IMPL(__imp__sub_824843A0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r4,-48
	ctx.r9.s64 = ctx.r4.s64 + -48;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// li r8,6
	ctx.r8.s64 = 6;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824843CC:
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824843cc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824843CC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824843F0:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824843f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824843F0;
	// subf r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// ld r30,152(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// li r10,48
	ctx.r10.s64 = 48;
	// ld r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r9,r11,-48
	ctx.r9.s64 = r11.s64 + -48;
	// ld r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// divw r5,r9,r10
	ctx.r5.s32 = ctx.r9.s32 / ctx.r10.s32;
	// ld r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// ld r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// stb r31,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r31.u8);
	// std r30,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r30.u64);
	// bl 0x82483240
	ctx.lr = 0x8248443C;
	sub_82483240(ctx, base);
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

__attribute__((alias("__imp__sub_82484454"))) PPC_WEAK_FUNC(sub_82484454);
PPC_FUNC_IMPL(__imp__sub_82484454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484458"))) PPC_WEAK_FUNC(sub_82484458);
PPC_FUNC_IMPL(__imp__sub_82484458) {
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
	ctx.lr = 0x82484460;
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
	ctx.lr = 0x82484490;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8248449C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824844AC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824844dc
	if (cr6.eq) goto loc_824844DC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824844dc
	if (!cr6.eq) goto loc_824844DC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82483100
	ctx.lr = 0x824844CC;
	sub_82483100(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824844e0
	if (!cr6.eq) goto loc_824844E0;
loc_824844DC:
	// li r31,0
	r31.s64 = 0;
loc_824844E0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8248450c
	if (cr6.eq) goto loc_8248450C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484504
	if (cr6.eq) goto loc_82484504;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824844FC;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82484508
	goto loc_82484508;
loc_82484504:
	// li r11,0
	r11.s64 = 0;
loc_82484508:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8248450C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484530
	if (cr6.eq) goto loc_82484530;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82484520;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82484534
	if (cr6.eq) goto loc_82484534;
loc_82484530:
	// li r11,0
	r11.s64 = 0;
loc_82484534:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82484540"))) PPC_WEAK_FUNC(sub_82484540);
PPC_FUNC_IMPL(__imp__sub_82484540) {
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
	ctx.lr = 0x82484548;
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
	ctx.lr = 0x8248456C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82484578;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82484588;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824845ac
	if (cr6.eq) goto loc_824845AC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82483dd8
	ctx.lr = 0x8248459C;
	sub_82483DD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824845b0
	if (!cr6.eq) goto loc_824845B0;
loc_824845AC:
	// li r30,0
	r30.s64 = 0;
loc_824845B0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824845e8
	if (cr6.eq) goto loc_824845E8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824845e0
	if (cr6.eq) goto loc_824845E0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824845CC;
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
loc_824845E0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824845E8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824845F4"))) PPC_WEAK_FUNC(sub_824845F4);
PPC_FUNC_IMPL(__imp__sub_824845F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824845F8"))) PPC_WEAK_FUNC(sub_824845F8);
PPC_FUNC_IMPL(__imp__sub_824845F8) {
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
	ctx.lr = 0x82484600;
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
	ctx.lr = 0x82484624;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82484630;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82484640;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82484664
	if (cr6.eq) goto loc_82484664;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82483f20
	ctx.lr = 0x82484654;
	sub_82483F20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484668
	if (!cr6.eq) goto loc_82484668;
loc_82484664:
	// li r30,0
	r30.s64 = 0;
loc_82484668:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824846a0
	if (cr6.eq) goto loc_824846A0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484698
	if (cr6.eq) goto loc_82484698;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82484684;
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
loc_82484698:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824846A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824846AC"))) PPC_WEAK_FUNC(sub_824846AC);
PPC_FUNC_IMPL(__imp__sub_824846AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824846B0"))) PPC_WEAK_FUNC(sub_824846B0);
PPC_FUNC_IMPL(__imp__sub_824846B0) {
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
	ctx.lr = 0x824846B8;
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
	ctx.lr = 0x824846E8;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824846F4;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x82484704;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82484734
	if (cr6.eq) goto loc_82484734;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x82484734
	if (!cr6.eq) goto loc_82484734;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82483f88
	ctx.lr = 0x82484724;
	sub_82483F88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484738
	if (!cr6.eq) goto loc_82484738;
loc_82484734:
	// li r31,0
	r31.s64 = 0;
loc_82484738:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82484764
	if (cr6.eq) goto loc_82484764;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248475c
	if (cr6.eq) goto loc_8248475C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82484754;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82484760
	goto loc_82484760;
loc_8248475C:
	// li r11,0
	r11.s64 = 0;
loc_82484760:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82484764:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484788
	if (cr6.eq) goto loc_82484788;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82484778;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8248478c
	if (cr6.eq) goto loc_8248478C;
loc_82484788:
	// li r11,0
	r11.s64 = 0;
loc_8248478C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82484798"))) PPC_WEAK_FUNC(sub_82484798);
PPC_FUNC_IMPL(__imp__sub_82484798) {
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
	ctx.lr = 0x824847A0;
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
	ctx.lr = 0x824847D0;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824847DC;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824847EC;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8248481c
	if (cr6.eq) goto loc_8248481C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x8248481c
	if (!cr6.eq) goto loc_8248481C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82483ff0
	ctx.lr = 0x8248480C;
	sub_82483FF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484820
	if (!cr6.eq) goto loc_82484820;
loc_8248481C:
	// li r31,0
	r31.s64 = 0;
loc_82484820:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8248484c
	if (cr6.eq) goto loc_8248484C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484844
	if (cr6.eq) goto loc_82484844;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x8248483C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x82484848
	goto loc_82484848;
loc_82484844:
	// li r11,0
	r11.s64 = 0;
loc_82484848:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8248484C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484870
	if (cr6.eq) goto loc_82484870;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x82484860;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82484874
	if (cr6.eq) goto loc_82484874;
loc_82484870:
	// li r11,0
	r11.s64 = 0;
loc_82484874:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82484880"))) PPC_WEAK_FUNC(sub_82484880);
PPC_FUNC_IMPL(__imp__sub_82484880) {
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
	ctx.lr = 0x82484888;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r30,2264
	r31.s64 = r30.s64 + 2264;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2608
	ctx.lr = 0x8248489C;
	sub_824E2608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824849a4
	if (cr6.eq) goto loc_824849A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1160
	ctx.lr = 0x824848B0;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824848d4
	if (cr6.eq) goto loc_824848D4;
	// addi r3,r30,4408
	ctx.r3.s64 = r30.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x824848C4;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824848d8
	if (cr6.eq) goto loc_824848D8;
loc_824848D4:
	// li r11,0
	r11.s64 = 0;
loc_824848D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824848f8
	if (cr6.eq) goto loc_824848F8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82483998
	ctx.lr = 0x824848EC;
	sub_82483998(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824849a4
	if (cr6.eq) goto loc_824849A4;
loc_824848F8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e12a8
	ctx.lr = 0x82484900;
	sub_824E12A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484920
	if (cr6.eq) goto loc_82484920;
	// addi r3,r30,40
	ctx.r3.s64 = r30.s64 + 40;
	// bl 0x8252a6e8
	ctx.lr = 0x82484914;
	sub_8252A6E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824849a4
	if (!cr6.eq) goto loc_824849A4;
loc_82484920:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1258
	ctx.lr = 0x82484928;
	sub_824E1258(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484940
	if (cr6.eq) goto loc_82484940;
	// lwz r11,11588(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11588);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bgt cr6,0x824849a4
	if (cr6.gt) goto loc_824849A4;
loc_82484940:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0ec8
	ctx.lr = 0x8248494C;
	sub_824E0EC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0f28
	ctx.lr = 0x82484958;
	sub_824E0F28(ctx, base);
	// lwz r11,8308(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8308);
	// lwz r10,11528(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 11528);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// subf r11,r29,r9
	r11.s64 = ctx.r9.s64 - r29.s64;
	// add. r8,r11,r3
	ctx.r8.u64 = r11.u64 + ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x82484994
	if (!cr0.eq) goto loc_82484994;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0ec8
	ctx.lr = 0x8248497C;
	sub_824E0EC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0f28
	ctx.lr = 0x82484988;
	sub_824E0F28(ctx, base);
	// lwz r11,11528(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11528);
	// subf. r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824849a4
	if (cr0.eq) goto loc_824849A4;
loc_82484994:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824849A4:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824849B4"))) PPC_WEAK_FUNC(sub_824849B4);
PPC_FUNC_IMPL(__imp__sub_824849B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824849B8"))) PPC_WEAK_FUNC(sub_824849B8);
PPC_FUNC_IMPL(__imp__sub_824849B8) {
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
	ctx.lr = 0x824849C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x82484aa0
	if (cr6.lt) goto loc_82484AA0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824ebbc8
	ctx.lr = 0x824849E4;
	sub_824EBBC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484aa0
	if (!cr6.eq) goto loc_82484AA0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824eba48
	ctx.lr = 0x824849FC;
	sub_824EBA48(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f97c0
	ctx.lr = 0x82484A08;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481b70
	ctx.lr = 0x82484A14;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82484aa0
	if (!cr6.eq) goto loc_82484AA0;
	// lwz r11,11392(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11392);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484aa0
	if (cr6.eq) goto loc_82484AA0;
	// lwz r4,11384(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 11384);
	// addi r3,r30,11384
	ctx.r3.s64 = r30.s64 + 11384;
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82484a40
	if (cr6.eq) goto loc_82484A40;
	// bl 0x824f8968
	ctx.lr = 0x82484A40;
	sub_824F8968(ctx, base);
loc_82484A40:
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82484A54:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82484a54
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82484A54;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
	// lwz r11,11524(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11524);
	// addi r7,r11,2849
	ctx.r7.s64 = r11.s64 + 2849;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r6,r30
	PPC_STORE_U32(ctx.r6.u32 + r30.u32, r31.u32);
	// lwz r11,11524(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11524);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,11524(r30)
	PPC_STORE_U32(r30.u32 + 11524, ctx.r5.u32);
loc_82484AA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82484AAC"))) PPC_WEAK_FUNC(sub_82484AAC);
PPC_FUNC_IMPL(__imp__sub_82484AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484AB0"))) PPC_WEAK_FUNC(sub_82484AB0);
PPC_FUNC_IMPL(__imp__sub_82484AB0) {
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
	ctx.lr = 0x82484AB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82484AD4;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484aec
	if (!cr6.eq) goto loc_82484AEC;
loc_82484AE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82484AEC:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82484ae0
	if (cr6.lt) goto loc_82484AE0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,4496(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82484B04;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82484b14
	if (cr6.eq) goto loc_82484B14;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82484b18
	goto loc_82484B18;
loc_82484B14:
	// li r11,-1
	r11.s64 = -1;
loc_82484B18:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82484ae0
	if (!cr6.eq) goto loc_82484AE0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22348
	ctx.r10.s64 = r11.s64 + 22348;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82483540
	ctx.lr = 0x82484B44;
	sub_82483540(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484ae0
	if (cr6.eq) goto loc_82484AE0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82484B58;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82484b6c
	if (!cr6.eq) goto loc_82484B6C;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82484B6C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484B74"))) PPC_WEAK_FUNC(sub_82484B74);
PPC_FUNC_IMPL(__imp__sub_82484B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484B78"))) PPC_WEAK_FUNC(sub_82484B78);
PPC_FUNC_IMPL(__imp__sub_82484B78) {
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
	ctx.lr = 0x82484B80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r30,2264
	r29.s64 = r30.s64 + 2264;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1160
	ctx.lr = 0x82484B9C;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484bb4
	if (!cr6.eq) goto loc_82484BB4;
loc_82484BA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82484BB4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r10,r11,22316
	ctx.r10.s64 = r11.s64 + 22316;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82483458
	ctx.lr = 0x82484BD4;
	sub_82483458(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484ba8
	if (cr6.eq) goto loc_82484BA8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82484BE8;
	sub_824E0E80(ctx, base);
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// bne cr6,0x82484ba8
	if (!cr6.eq) goto loc_82484BA8;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82484ba8
	if (cr6.lt) goto loc_82484BA8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481688
	ctx.lr = 0x82484C08;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484c44
	if (!cr6.eq) goto loc_82484C44;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r4,4496(r30)
	ctx.r4.u64 = PPC_LOAD_U64(r30.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82484C20;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82484c30
	if (cr6.eq) goto loc_82484C30;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82484c34
	goto loc_82484C34;
loc_82484C30:
	// li r11,-1
	r11.s64 = -1;
loc_82484C34:
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82484c48
	if (!cr6.eq) goto loc_82484C48;
loc_82484C44:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82484C48:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484C50"))) PPC_WEAK_FUNC(sub_82484C50);
PPC_FUNC_IMPL(__imp__sub_82484C50) {
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
	ctx.lr = 0x82484C58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82484C74;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484c8c
	if (!cr6.eq) goto loc_82484C8C;
loc_82484C80:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82484C8C:
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252a700
	ctx.lr = 0x82484C94;
	sub_8252A700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484c80
	if (cr6.eq) goto loc_82484C80;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82484c80
	if (cr6.lt) goto loc_82484C80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,4496(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82484CB8;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82484cc8
	if (cr6.eq) goto loc_82484CC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82484ccc
	goto loc_82484CCC;
loc_82484CC8:
	// li r11,-1
	r11.s64 = -1;
loc_82484CCC:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82484c80
	if (!cr6.eq) goto loc_82484C80;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22028
	ctx.r10.s64 = r11.s64 + 22028;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82483628
	ctx.lr = 0x82484CF8;
	sub_82483628(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484c80
	if (cr6.eq) goto loc_82484C80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82484D0C;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82484d20
	if (!cr6.eq) goto loc_82484D20;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82484D20:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484D28"))) PPC_WEAK_FUNC(sub_82484D28);
PPC_FUNC_IMPL(__imp__sub_82484D28) {
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
	ctx.lr = 0x82484D30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82484D4C;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484d64
	if (!cr6.eq) goto loc_82484D64;
loc_82484D58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82484D64:
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252a700
	ctx.lr = 0x82484D6C;
	sub_8252A700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82484d58
	if (cr6.eq) goto loc_82484D58;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22252
	ctx.r10.s64 = r11.s64 + 22252;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82483540
	ctx.lr = 0x82484D98;
	sub_82483540(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484d58
	if (cr6.eq) goto loc_82484D58;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82484DAC;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82484dc0
	if (!cr6.eq) goto loc_82484DC0;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82484DC0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484DC8"))) PPC_WEAK_FUNC(sub_82484DC8);
PPC_FUNC_IMPL(__imp__sub_82484DC8) {
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
	ctx.lr = 0x82484DD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82484DEC;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484e04
	if (!cr6.eq) goto loc_82484E04;
loc_82484DF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82484E04:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82484df8
	if (cr6.lt) goto loc_82484DF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,4496(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82484E1C;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82484e2c
	if (cr6.eq) goto loc_82484E2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82484e30
	goto loc_82484E30;
loc_82484E2C:
	// li r11,-1
	r11.s64 = -1;
loc_82484E30:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82484df8
	if (!cr6.eq) goto loc_82484DF8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22444
	ctx.r10.s64 = r11.s64 + 22444;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824837c8
	ctx.lr = 0x82484E5C;
	sub_824837C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484df8
	if (cr6.eq) goto loc_82484DF8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82484E70;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82484e84
	if (!cr6.eq) goto loc_82484E84;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82484E84:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484E8C"))) PPC_WEAK_FUNC(sub_82484E8C);
PPC_FUNC_IMPL(__imp__sub_82484E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484E90"))) PPC_WEAK_FUNC(sub_82484E90);
PPC_FUNC_IMPL(__imp__sub_82484E90) {
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
	ctx.lr = 0x82484E98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82484EB4;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82484ecc
	if (!cr6.eq) goto loc_82484ECC;
loc_82484EC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82484ECC:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82484ec0
	if (cr6.lt) goto loc_82484EC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,4496(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82484EE4;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82484ef4
	if (cr6.eq) goto loc_82484EF4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82484ef8
	goto loc_82484EF8;
loc_82484EF4:
	// li r11,-1
	r11.s64 = -1;
loc_82484EF8:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82484ec0
	if (!cr6.eq) goto loc_82484EC0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22284
	ctx.r10.s64 = r11.s64 + 22284;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824838b0
	ctx.lr = 0x82484F24;
	sub_824838B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484ec0
	if (cr6.eq) goto loc_82484EC0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82484F38;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82484f4c
	if (!cr6.eq) goto loc_82484F4C;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82484F4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82484F54"))) PPC_WEAK_FUNC(sub_82484F54);
PPC_FUNC_IMPL(__imp__sub_82484F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82484F58"))) PPC_WEAK_FUNC(sub_82484F58);
PPC_FUNC_IMPL(__imp__sub_82484F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,11548(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11548);
	// addi r11,r3,11548
	r11.s64 = ctx.r3.s64 + 11548;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82484fac
	if (cr6.eq) goto loc_82484FAC;
loc_82484F68:
	// lbz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82484f88
	if (cr6.eq) goto loc_82484F88;
	// rlwinm r9,r9,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x82484f8c
	if (cr6.eq) goto loc_82484F8C;
loc_82484F88:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82484F8C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82484fa4
	if (cr6.eq) goto loc_82484FA4;
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82484f68
	if (!cr6.eq) goto loc_82484F68;
loc_82484FA4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82484fe8
	if (!cr6.eq) goto loc_82484FE8;
loc_82484FAC:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82484fdc
	if (cr6.eq) goto loc_82484FDC;
	// stw r4,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// bne cr6,0x82485020
	if (!cr6.eq) goto loc_82485020;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// b 0x82485020
	goto loc_82485020;
loc_82484FDC:
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// b 0x82485020
	goto loc_82485020;
loc_82484FE8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82485008
	if (!cr6.eq) goto loc_82485008;
	// stw r9,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r4,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r4.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// b 0x82485020
	goto loc_82485020;
loc_82485008:
	// stw r10,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r9,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r9.u32);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r4,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r4.u32);
	// stw r4,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r4.u32);
loc_82485020:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,11556(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11556);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8248504C"))) PPC_WEAK_FUNC(sub_8248504C);
PPC_FUNC_IMPL(__imp__sub_8248504C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82485050"))) PPC_WEAK_FUNC(sub_82485050);
PPC_FUNC_IMPL(__imp__sub_82485050) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-7912
	ctx.r10.s64 = r11.s64 + -7912;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824827b0
	ctx.lr = 0x8248507C;
	sub_824827B0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824fa710
	ctx.lr = 0x82485084;
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
	// beq cr6,0x824850a8
	if (cr6.eq) goto loc_824850A8;
	// bl 0x82130588
	ctx.lr = 0x824850A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824850A8:
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

__attribute__((alias("__imp__sub_824850C0"))) PPC_WEAK_FUNC(sub_824850C0);
PPC_FUNC_IMPL(__imp__sub_824850C0) {
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
	ctx.lr = 0x824850C8;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22316
	ctx.r10.s64 = r11.s64 + 22316;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824833a0
	ctx.lr = 0x824850FC;
	sub_824833A0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82485134
	if (cr6.eq) goto loc_82485134;
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
	// bl 0x82481188
	ctx.lr = 0x82485124;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82485138
	if (!cr6.eq) goto loc_82485138;
loc_82485134:
	// li r11,0
	r11.s64 = 0;
loc_82485138:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82485144"))) PPC_WEAK_FUNC(sub_82485144);
PPC_FUNC_IMPL(__imp__sub_82485144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485148"))) PPC_WEAK_FUNC(sub_82485148);
PPC_FUNC_IMPL(__imp__sub_82485148) {
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
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22060
	ctx.r10.s64 = r11.s64 + 22060;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82483710
	ctx.lr = 0x82485184;
	sub_82483710(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824851b4
	if (cr6.eq) goto loc_824851B4;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481238
	ctx.lr = 0x824851A4;
	sub_82481238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824851b8
	if (!cr6.eq) goto loc_824851B8;
loc_824851B4:
	// li r11,0
	r11.s64 = 0;
loc_824851B8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
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

__attribute__((alias("__imp__sub_824851D4"))) PPC_WEAK_FUNC(sub_824851D4);
PPC_FUNC_IMPL(__imp__sub_824851D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824851D8"))) PPC_WEAK_FUNC(sub_824851D8);
PPC_FUNC_IMPL(__imp__sub_824851D8) {
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
	ctx.lr = 0x824851E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r5,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r5.u64);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// std r6,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r6.u64);
	// std r7,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.r7.u64);
	// std r8,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r8.u64);
	// std r9,224(r1)
	PPC_STORE_U64(ctx.r1.u32 + 224, ctx.r9.u64);
	// std r10,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r10.u64);
loc_82485204:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f97c0
	ctx.lr = 0x8248520C;
	sub_824F97C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824f97c0
	ctx.lr = 0x82485218;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r29,r3
	cr6.compare<uint64_t>(r29.u64, ctx.r3.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82485228
	if (cr6.lt) goto loc_82485228;
	// li r11,0
	r11.s64 = 0;
loc_82485228:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248523c
	if (cr6.eq) goto loc_8248523C;
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// b 0x82485204
	goto loc_82485204;
loc_8248523C:
	// addi r30,r30,-48
	r30.s64 = r30.s64 + -48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f97c0
	ctx.lr = 0x82485248;
	sub_824F97C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824f97c0
	ctx.lr = 0x82485254;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r29
	cr6.compare<uint64_t>(ctx.r3.u64, r29.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82485264
	if (cr6.lt) goto loc_82485264;
	// li r11,0
	r11.s64 = 0;
loc_82485264:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248523c
	if (!cr6.eq) goto loc_8248523C;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bge cr6,0x824852ec
	if (!cr6.lt) goto loc_824852EC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82485288:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82485288
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82485288;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824852AC:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824852ac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824852AC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824852D0:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824852d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824852D0;
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// b 0x82485204
	goto loc_82485204;
loc_824852EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824852F8"))) PPC_WEAK_FUNC(sub_824852F8);
PPC_FUNC_IMPL(__imp__sub_824852F8) {
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
	ctx.lr = 0x82485300;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lbz r10,11608(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824853c0
	if (!cr6.eq) goto loc_824853C0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// stw r6,11580(r31)
	PPC_STORE_U32(r31.u32 + 11580, ctx.r6.u32);
	// stw r7,11584(r31)
	PPC_STORE_U32(r31.u32 + 11584, ctx.r7.u32);
	// bl 0x824e59d8
	ctx.lr = 0x8248533C;
	sub_824E59D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824853c0
	if (cr6.eq) goto loc_824853C0;
	// addi r3,r31,11592
	ctx.r3.s64 = r31.s64 + 11592;
	// bl 0x8252f228
	ctx.lr = 0x82485350;
	sub_8252F228(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824853c0
	if (cr6.eq) goto loc_824853C0;
	// addi r27,r31,8168
	r27.s64 = r31.s64 + 8168;
	// addi r26,r31,11384
	r26.s64 = r31.s64 + 11384;
	// addi r28,r31,8312
	r28.s64 = r31.s64 + 8312;
	// addi r29,r31,4584
	r29.s64 = r31.s64 + 4584;
	// li r30,32
	r30.s64 = 32;
loc_82485370:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82482988
	ctx.lr = 0x82485384;
	sub_82482988(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82482a20
	ctx.lr = 0x82485398;
	sub_82482A20(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,112
	r29.s64 = r29.s64 + 112;
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// bne 0x82485370
	if (!cr0.eq) goto loc_82485370;
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,11608(r31)
	PPC_STORE_U8(r31.u32 + 11608, ctx.r10.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_824853C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824853CC"))) PPC_WEAK_FUNC(sub_824853CC);
PPC_FUNC_IMPL(__imp__sub_824853CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824853D0"))) PPC_WEAK_FUNC(sub_824853D0);
PPC_FUNC_IMPL(__imp__sub_824853D0) {
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
	ctx.lr = 0x824853D8;
	// stwu r1,-1696(r1)
	ea = -1696 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r3,r28,2264
	ctx.r3.s64 = r28.s64 + 2264;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x824e1160
	ctx.lr = 0x824853F4;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485590
	if (cr6.eq) goto loc_82485590;
	// lbz r11,11608(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 11608);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82485590
	if (!cr6.eq) goto loc_82485590;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// li r30,31
	r30.s64 = 31;
loc_82485418:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f99c0
	ctx.lr = 0x82485420;
	sub_824F99C0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,48
	r29.s64 = r29.s64 + 48;
	// bge 0x82485418
	if (!cr0.lt) goto loc_82485418;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x824854c4
	if (!cr6.gt) goto loc_824854C4;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
loc_82485440:
	// cmplwi cr6,r27,32
	cr6.compare<uint32_t>(r27.u32, 32, xer);
	// bge cr6,0x824854bc
	if (!cr6.lt) goto loc_824854BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f97c0
	ctx.lr = 0x82485450;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82481b70
	ctx.lr = 0x8248545C;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82485590
	if (cr6.eq) goto loc_82485590;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82485480
	if (!cr6.lt) goto loc_82485480;
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824854ac
	if (cr6.eq) goto loc_824854AC;
loc_82485480:
	// mr r11,r31
	r11.u64 = r31.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82485490:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82485490
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82485490;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
loc_824854AC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// cmpw cr6,r29,r26
	cr6.compare<int32_t>(r29.s32, r26.s32, xer);
	// blt cr6,0x82485440
	if (cr6.lt) goto loc_82485440;
loc_824854BC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x824854ec
	if (!cr6.eq) goto loc_824854EC;
loc_824854C4:
	// addi r11,r28,4408
	r11.s64 = r28.s64 + 4408;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824854D4:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824854d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824854D4;
	// li r27,1
	r27.s64 = 1;
loc_824854EC:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// std r11,4496(r28)
	PPC_STORE_U64(r28.u32 + 4496, r11.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4848
	ctx.r4.s64 = 4848;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82485514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82485590
	if (cr6.eq) goto loc_82485590;
	// bl 0x824cf9a0
	ctx.lr = 0x82485524;
	sub_824CF9A0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r7,r31,4840
	ctx.r7.s64 = r31.s64 + 4840;
	// addi r10,r11,-8192
	ctx.r10.s64 = r11.s64 + -8192;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r25,4840(r31)
	PPC_STORE_U32(r31.u32 + 4840, r25.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r25,4844(r31)
	PPC_STORE_U32(r31.u32 + 4844, r25.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c8878
	ctx.lr = 0x82485550;
	sub_824C8878(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8248559c
	if (!cr6.eq) goto loc_8248559C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485578;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82485590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485590:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,1696
	ctx.r1.s64 = ctx.r1.s64 + 1696;
	// b 0x823d923c
	return;
loc_8248559C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// addi r8,r10,-8204
	ctx.r8.s64 = ctx.r10.s64 + -8204;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r28,11532
	ctx.r3.s64 = r28.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824855D4;
	sub_824E7DB8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82484f58
	ctx.lr = 0x824855E0;
	sub_82484F58(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824819e8
	ctx.lr = 0x824855EC;
	sub_824819E8(ctx, base);
	// lbz r6,11608(r28)
	ctx.r6.u64 = PPC_LOAD_U8(r28.u32 + 11608);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 | 32;
	// stb r5,11608(r28)
	PPC_STORE_U8(r28.u32 + 11608, ctx.r5.u8);
	// addi r1,r1,1696
	ctx.r1.s64 = ctx.r1.s64 + 1696;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82485604"))) PPC_WEAK_FUNC(sub_82485604);
PPC_FUNC_IMPL(__imp__sub_82485604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485608"))) PPC_WEAK_FUNC(sub_82485608);
PPC_FUNC_IMPL(__imp__sub_82485608) {
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
	// addi r30,r3,11532
	r30.s64 = ctx.r3.s64 + 11532;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x82485634;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82485650
	if (!cr6.eq) goto loc_82485650;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7930
	ctx.lr = 0x82485650;
	sub_824E7930(ctx, base);
loc_82485650:
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

__attribute__((alias("__imp__sub_82485668"))) PPC_WEAK_FUNC(sub_82485668);
PPC_FUNC_IMPL(__imp__sub_82485668) {
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
	ctx.lr = 0x82485670;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x82130000
	ctx.lr = 0x82485694;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82485698;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x824856A4;
	sub_82481B70(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82485734
	if (cr6.eq) goto loc_82485734;
	// lwz r11,8176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485734
	if (cr6.eq) goto loc_82485734;
	// lwz r4,8168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8168);
	// addi r29,r31,8168
	r29.s64 = r31.s64 + 8168;
	// extsw r30,r4
	r30.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824856d8
	if (cr6.eq) goto loc_824856D8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82482830
	ctx.lr = 0x824856D8;
	sub_82482830(ctx, base);
loc_824856D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6f20
	ctx.lr = 0x824856E0;
	sub_824E6F20(ctx, base);
	// lbz r10,108(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 108);
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stw r11,96(r30)
	PPC_STORE_U32(r30.u32 + 96, r11.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// stb r9,108(r30)
	PPC_STORE_U8(r30.u32 + 108, ctx.r9.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82485704;
	sub_823DA950(ctx, base);
	// stw r26,96(r30)
	PPC_STORE_U32(r30.u32 + 96, r26.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82482348
	ctx.lr = 0x82485714;
	sub_82482348(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82485740
	if (!cr6.eq) goto loc_82485740;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82482988
	ctx.lr = 0x82485734;
	sub_82482988(ctx, base);
loc_82485734:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9234
	return;
loc_82485740:
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r11,r11,2045
	r11.s64 = r11.s64 + 2045;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r30.u32);
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,8308(r31)
	PPC_STORE_U32(r31.u32 + 8308, ctx.r9.u32);
	// lwz r8,96(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// bne cr6,0x82485774
	if (!cr6.eq) goto loc_82485774;
	// lwz r11,11528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11528);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,11528(r31)
	PPC_STORE_U32(r31.u32 + 11528, r11.u32);
loc_82485774:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// mr r30,r23
	r30.u64 = r23.u64;
	// bne cr6,0x82485784
	if (!cr6.eq) goto loc_82485784;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82485784:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r25.u32);
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// addi r8,r10,-8228
	ctx.r8.s64 = ctx.r10.s64 + -8228;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x824857BC;
	sub_823DA950(ctx, base);
	// ld r6,56(r27)
	ctx.r6.u64 = PPC_LOAD_U64(r27.u32 + 56);
	// stw r26,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r26.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r30,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r24,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r24.u32);
	// addi r3,r31,11532
	ctx.r3.s64 = r31.s64 + 11532;
	// std r6,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.r6.u64);
	// bl 0x824e7db8
	ctx.lr = 0x824857E0;
	sub_824E7DB8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824857EC"))) PPC_WEAK_FUNC(sub_824857EC);
PPC_FUNC_IMPL(__imp__sub_824857EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824857F0"))) PPC_WEAK_FUNC(sub_824857F0);
PPC_FUNC_IMPL(__imp__sub_824857F0) {
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
	ctx.lr = 0x824857F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x82485814;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248582c
	if (!cr6.eq) goto loc_8248582C;
loc_82485820:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8248582C:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82485820
	if (cr6.lt) goto loc_82485820;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,4496(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82485844;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82485854
	if (cr6.eq) goto loc_82485854;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82485858
	goto loc_82485858;
loc_82485854:
	// li r11,-1
	r11.s64 = -1;
loc_82485858:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82485820
	if (!cr6.eq) goto loc_82485820;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22156
	ctx.r10.s64 = r11.s64 + 22156;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824846b0
	ctx.lr = 0x82485884;
	sub_824846B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82485820
	if (cr6.eq) goto loc_82485820;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82485898;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x824858ac
	if (!cr6.eq) goto loc_824858AC;
	// li r3,1
	ctx.r3.s64 = 1;
loc_824858AC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824858B4"))) PPC_WEAK_FUNC(sub_824858B4);
PPC_FUNC_IMPL(__imp__sub_824858B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824858B8"))) PPC_WEAK_FUNC(sub_824858B8);
PPC_FUNC_IMPL(__imp__sub_824858B8) {
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
	ctx.lr = 0x824858C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1160
	ctx.lr = 0x824858DC;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824858f4
	if (!cr6.eq) goto loc_824858F4;
loc_824858E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824858F4:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x824858e8
	if (cr6.lt) goto loc_824858E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r4,4496(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x8248590C;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248591c
	if (cr6.eq) goto loc_8248591C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82485920
	goto loc_82485920;
loc_8248591C:
	// li r11,-1
	r11.s64 = -1;
loc_82485920:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x824858e8
	if (!cr6.eq) goto loc_824858E8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22220
	ctx.r10.s64 = r11.s64 + 22220;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82484798
	ctx.lr = 0x8248594C;
	sub_82484798(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824858e8
	if (cr6.eq) goto loc_824858E8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82485960;
	sub_824E0E80(ctx, base);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82485974
	if (!cr6.eq) goto loc_82485974;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82485974:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8248597C"))) PPC_WEAK_FUNC(sub_8248597C);
PPC_FUNC_IMPL(__imp__sub_8248597C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485980"))) PPC_WEAK_FUNC(sub_82485980);
PPC_FUNC_IMPL(__imp__sub_82485980) {
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
	// lwz r11,11572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824859e8
	if (cr6.eq) goto loc_824859E8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824859BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r9,-8496
	ctx.r8.s64 = ctx.r9.s64 + -8496;
	// cmplw cr6,r3,r8
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, xer);
	// beq cr6,0x824859e8
	if (cr6.eq) goto loc_824859E8;
	// addi r4,r31,11548
	ctx.r4.s64 = r31.s64 + 11548;
	// lwz r6,11572(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 11572);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824828f0
	ctx.lr = 0x824859E0;
	sub_824828F0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,11572(r31)
	PPC_STORE_U32(r31.u32 + 11572, r11.u32);
loc_824859E8:
	// addi r4,r31,11548
	ctx.r4.s64 = r31.s64 + 11548;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824828f0
	ctx.lr = 0x824859FC;
	sub_824828F0(ctx, base);
	// lwz r11,11556(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11556);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82485a1c
	if (!cr6.eq) goto loc_82485A1C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485A1C:
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

__attribute__((alias("__imp__sub_82485A34"))) PPC_WEAK_FUNC(sub_82485A34);
PPC_FUNC_IMPL(__imp__sub_82485A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485A38"))) PPC_WEAK_FUNC(sub_82485A38);
PPC_FUNC_IMPL(__imp__sub_82485A38) {
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
	ctx.lr = 0x82485A40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r28,r27,11560
	r28.s64 = r27.s64 + 11560;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r31,11560(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 11560);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// ld r11,88(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x82482730
	ctx.lr = 0x82485A70;
	sub_82482730(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82485bac
	if (cr6.eq) goto loc_82485BAC;
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82485A80:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82485aa4
	if (!cr6.eq) goto loc_82485AA4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485AA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485AA4:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485ac4
	if (cr6.eq) goto loc_82485AC4;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82485ac8
	if (cr6.eq) goto loc_82485AC8;
loc_82485AC4:
	// li r11,0
	r11.s64 = 0;
loc_82485AC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485aec
	if (cr6.eq) goto loc_82485AEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485AEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485AEC:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485b4c
	if (cr6.eq) goto loc_82485B4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82482670
	ctx.lr = 0x82485B08;
	sub_82482670(ctx, base);
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485b4c
	if (cr6.eq) goto loc_82485B4C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r25,0(r27)
	r25.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485B34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82485B4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485B4C:
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// beq cr6,0x82485b64
	if (cr6.eq) goto loc_82485B64;
	// lwz r29,16(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// b 0x82485b9c
	goto loc_82485B9C;
loc_82485B64:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485b80
	if (cr6.eq) goto loc_82485B80;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82485b84
	if (!cr6.eq) goto loc_82485B84;
loc_82485B80:
	// li r11,0
	r11.s64 = 0;
loc_82485B84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485ba0
	if (cr6.eq) goto loc_82485BA0;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82485B9C:
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
loc_82485BA0:
	// lwz r31,88(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82485a80
	if (!cr6.eq) goto loc_82485A80;
loc_82485BAC:
	// lwz r11,11556(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 11556);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485bc0
	if (cr6.eq) goto loc_82485BC0;
	// lwz r31,11548(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 11548);
loc_82485BC0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82485bf8
	if (!cr6.eq) goto loc_82485BF8;
	// lwz r31,11572(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 11572);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82485d64
	if (cr6.eq) goto loc_82485D64;
	// addi r4,r27,11548
	ctx.r4.s64 = r27.s64 + 11548;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824828f0
	ctx.lr = 0x82485BE8;
	sub_824828F0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,11572(r27)
	PPC_STORE_U32(r27.u32 + 11572, r11.u32);
	// beq cr6,0x82485d64
	if (cr6.eq) goto loc_82485D64;
loc_82485BF8:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82485c1c
	if (!cr6.eq) goto loc_82485C1C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485C1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485C1C:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485c3c
	if (cr6.eq) goto loc_82485C3C;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82485c40
	if (cr6.eq) goto loc_82485C40;
loc_82485C3C:
	// li r11,0
	r11.s64 = 0;
loc_82485C40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485c64
	if (cr6.eq) goto loc_82485C64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485C64:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485d34
	if (cr6.eq) goto loc_82485D34;
	// addi r30,r27,11548
	r30.s64 = r27.s64 + 11548;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82482670
	ctx.lr = 0x82485C84;
	sub_82482670(ctx, base);
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485cc8
	if (cr6.eq) goto loc_82485CC8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,0(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82485CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485CC8:
	// lwz r11,11556(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 11556);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485cdc
	if (cr6.eq) goto loc_82485CDC;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82485CDC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82485d64
	if (cr6.eq) goto loc_82485D64;
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r11,r10,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485d04
	if (cr6.eq) goto loc_82485D04;
	// rlwinm r11,r10,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82485d08
	if (cr6.eq) goto loc_82485D08;
loc_82485D04:
	// li r11,0
	r11.s64 = 0;
loc_82485D08:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485d34
	if (cr6.eq) goto loc_82485D34;
	// rlwinm r11,r10,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82485d34
	if (!cr6.eq) goto loc_82485D34;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82485D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82485D34:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82485d54
	if (cr6.eq) goto loc_82485D54;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82485d58
	if (cr6.eq) goto loc_82485D58;
loc_82485D54:
	// li r11,0
	r11.s64 = 0;
loc_82485D58:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485bf8
	if (cr6.eq) goto loc_82485BF8;
loc_82485D64:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82485D6C"))) PPC_WEAK_FUNC(sub_82485D6C);
PPC_FUNC_IMPL(__imp__sub_82485D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485D70"))) PPC_WEAK_FUNC(sub_82485D70);
PPC_FUNC_IMPL(__imp__sub_82485D70) {
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
	ctx.lr = 0x82485D78;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22412
	ctx.r10.s64 = r11.s64 + 22412;
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
	// bl 0x82484540
	ctx.lr = 0x82485DAC;
	sub_82484540(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82485de4
	if (cr6.eq) goto loc_82485DE4;
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
	ctx.lr = 0x82485DD4;
	sub_824EDFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82485de8
	if (!cr6.eq) goto loc_82485DE8;
loc_82485DE4:
	// li r11,0
	r11.s64 = 0;
loc_82485DE8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82485DF4"))) PPC_WEAK_FUNC(sub_82485DF4);
PPC_FUNC_IMPL(__imp__sub_82485DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485DF8"))) PPC_WEAK_FUNC(sub_82485DF8);
PPC_FUNC_IMPL(__imp__sub_82485DF8) {
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
	ctx.lr = 0x82485E00;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22156
	ctx.r10.s64 = r11.s64 + 22156;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824845f8
	ctx.lr = 0x82485E34;
	sub_824845F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82485e6c
	if (cr6.eq) goto loc_82485E6C;
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
	// bl 0x82481188
	ctx.lr = 0x82485E5C;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82485e70
	if (!cr6.eq) goto loc_82485E70;
loc_82485E6C:
	// li r11,0
	r11.s64 = 0;
loc_82485E70:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82485E7C"))) PPC_WEAK_FUNC(sub_82485E7C);
PPC_FUNC_IMPL(__imp__sub_82485E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485E80"))) PPC_WEAK_FUNC(sub_82485E80);
PPC_FUNC_IMPL(__imp__sub_82485E80) {
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
	ctx.lr = 0x82485E88;
	// stwu r1,-2192(r1)
	ea = -2192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82485f7c
	if (!cr6.gt) goto loc_82485F7C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r29,11396
	r28.s64 = r29.s64 + 11396;
	// addi r26,r11,22316
	r26.s64 = r11.s64 + 22316;
loc_82485EB4:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82485f68
	if (cr6.lt) goto loc_82485F68;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82485ee4
	if (cr6.eq) goto loc_82485EE4;
	// addi r4,r24,8
	ctx.r4.s64 = r24.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824f9950
	ctx.lr = 0x82485ED8;
	sub_824F9950(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82485f68
	if (!cr6.eq) goto loc_82485F68;
loc_82485EE4:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r6,999
	ctx.r6.s64 = 999;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824833a0
	ctx.lr = 0x82485F00;
	sub_824833A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82485f68
	if (cr6.eq) goto loc_82485F68;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1006
	ctx.r4.s64 = 1006;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x8252e178
	ctx.lr = 0x82485F1C;
	sub_8252E178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82485f68
	if (cr6.eq) goto loc_82485F68;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r31,r3,r5
	r31.u64 = ctx.r3.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,1006
	cr6.compare<uint32_t>(r31.u32, 1006, xer);
	// bgt cr6,0x82485f68
	if (cr6.gt) goto loc_82485F68;
	// addi r11,r1,1104
	r11.s64 = ctx.r1.s64 + 1104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x82485F44;
	sub_8244D5C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82485f68
	if (cr6.eq) goto loc_82485F68;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,1104
	ctx.r5.s64 = ctx.r1.s64 + 1104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r29,4552
	ctx.r3.s64 = r29.s64 + 4552;
	// bl 0x8252eaa0
	ctx.lr = 0x82485F68;
	sub_8252EAA0(ctx, base);
loc_82485F68:
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x82485eb4
	if (cr6.lt) goto loc_82485EB4;
loc_82485F7C:
	// addi r1,r1,2192
	ctx.r1.s64 = ctx.r1.s64 + 2192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82485F84"))) PPC_WEAK_FUNC(sub_82485F84);
PPC_FUNC_IMPL(__imp__sub_82485F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82485F88"))) PPC_WEAK_FUNC(sub_82485F88);
PPC_FUNC_IMPL(__imp__sub_82485F88) {
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
	ctx.lr = 0x82485F90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r5.u64);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// std r6,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r6.u64);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// std r7,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r7.u64);
	// std r8,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r8.u64);
	// std r9,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r9.u64);
	// std r10,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r10.u64);
	// bl 0x824f97c0
	ctx.lr = 0x82485FB8;
	sub_824F97C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824f97c0
	ctx.lr = 0x82485FC4;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r3,r29
	cr6.compare<uint64_t>(ctx.r3.u64, r29.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82485fd4
	if (cr6.lt) goto loc_82485FD4;
	// li r11,0
	r11.s64 = 0;
loc_82485FD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486058
	if (cr6.eq) goto loc_82486058;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// divw. r6,r11,r10
	ctx.r6.s32 = r11.s32 / ctx.r10.s32;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble 0x8248602c
	if (!cr0.gt) goto loc_8248602C;
	// addi r8,r9,-48
	ctx.r8.s64 = ctx.r9.s64 + -48;
loc_82485FF8:
	// addi r9,r9,-48
	ctx.r9.s64 = ctx.r9.s64 + -48;
	// addi r8,r8,-48
	ctx.r8.s64 = ctx.r8.s64 + -48;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// li r7,6
	ctx.r7.s64 = 6;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82486010:
	// ld r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r7,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r7.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82486010
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82486010;
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bgt 0x82485ff8
	if (cr0.gt) goto loc_82485FF8;
loc_8248602C:
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8248603C:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8248603c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8248603C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82486058:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,215(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 215);
	// ld r4,160(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// ld r5,168(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// ld r6,176(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// ld r7,184(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 184);
	// ld r8,192(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// ld r9,200(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 200);
	// bl 0x82481e58
	ctx.lr = 0x8248607C;
	sub_82481E58(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82486084"))) PPC_WEAK_FUNC(sub_82486084);
PPC_FUNC_IMPL(__imp__sub_82486084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82486088"))) PPC_WEAK_FUNC(sub_82486088);
PPC_FUNC_IMPL(__imp__sub_82486088) {
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
	ctx.lr = 0x82486090;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r27,48
	r27.s64 = 48;
	// subf r30,r29,r31
	r30.s64 = r31.s64 - r29.s64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// divw r11,r30,r27
	r11.s32 = r30.s32 / r27.s32;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x824860dc
	if (!cr6.gt) goto loc_824860DC;
loc_824860B4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824843a0
	ctx.lr = 0x824860C8;
	sub_824843A0(ctx, base);
	// addi r30,r30,-48
	r30.s64 = r30.s64 + -48;
	// addi r31,r31,-48
	r31.s64 = r31.s64 + -48;
	// divw r11,r30,r27
	r11.s32 = r30.s32 / r27.s32;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x824860b4
	if (cr6.gt) goto loc_824860B4;
loc_824860DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824860E4"))) PPC_WEAK_FUNC(sub_824860E4);
PPC_FUNC_IMPL(__imp__sub_824860E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824860E8"))) PPC_WEAK_FUNC(sub_824860E8);
PPC_FUNC_IMPL(__imp__sub_824860E8) {
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
	ctx.lr = 0x824860F0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// li r21,0
	r21.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82486150
	if (cr6.eq) goto loc_82486150;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x82486130
	if (!cr6.eq) goto loc_82486130;
	// bl 0x825019b0
	ctx.lr = 0x8248612C;
	sub_825019B0(ctx, base);
	// b 0x8248613c
	goto loc_8248613C;
loc_82486130:
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x82486148
	if (!cr6.eq) goto loc_82486148;
	// bl 0x82501a28
	ctx.lr = 0x8248613C;
	sub_82501A28(ctx, base);
loc_8248613C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486150
	if (!cr6.eq) goto loc_82486150;
loc_82486148:
	// li r11,0
	r11.s64 = 0;
	// b 0x82486154
	goto loc_82486154;
loc_82486150:
	// li r11,1
	r11.s64 = 1;
loc_82486154:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r28,308(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486234
	if (cr6.eq) goto loc_82486234;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x824ea838
	ctx.lr = 0x8248616C;
	sub_824EA838(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82130000
	ctx.lr = 0x82486174;
	sub_82130000(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1192
	ctx.r4.s64 = 1192;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486194;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82486234
	if (cr6.eq) goto loc_82486234;
	// bl 0x824caf50
	ctx.lr = 0x824861A4;
	sub_824CAF50(ctx, base);
	// lwz r4,292(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// lwz r11,300(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c8138
	ctx.lr = 0x824861E0;
	sub_824C8138(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82486224
	if (!cr6.eq) goto loc_82486224;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82486220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82486234
	goto loc_82486234;
loc_82486224:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82485980
	ctx.lr = 0x82486230;
	sub_82485980(ctx, base);
	// li r21,1
	r21.s64 = 1;
loc_82486234:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486274
	if (!cr6.eq) goto loc_82486274;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82486274
	if (cr6.eq) goto loc_82486274;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ce080
	ctx.lr = 0x82486254;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x8248626C;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r10.u32);
loc_82486274:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82486280"))) PPC_WEAK_FUNC(sub_82486280);
PPC_FUNC_IMPL(__imp__sub_82486280) {
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
	ctx.lr = 0x82486288;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// li r21,0
	r21.s64 = 0;
	// bl 0x82502300
	ctx.lr = 0x824862B8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481af0
	ctx.lr = 0x824862C4;
	sub_82481AF0(ctx, base);
	// lwz r22,300(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824863e4
	if (!cr6.eq) goto loc_824863E4;
	// bl 0x825019b0
	ctx.lr = 0x824862D4;
	sub_825019B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
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
	// bne cr6,0x82486310
	if (!cr6.eq) goto loc_82486310;
	// bl 0x82501a28
	ctx.lr = 0x824862F4;
	sub_82501A28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
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
	// beq cr6,0x824863e4
	if (cr6.eq) goto loc_824863E4;
loc_82486310:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x824ea838
	ctx.lr = 0x82486318;
	sub_824EA838(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82130000
	ctx.lr = 0x82486320;
	sub_82130000(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2432
	ctx.r4.s64 = 2432;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824863e4
	if (cr6.eq) goto loc_824863E4;
	// bl 0x824cf520
	ctx.lr = 0x82486350;
	sub_824CF520(ctx, base);
	// lwz r11,292(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r23.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c82e8
	ctx.lr = 0x82486384;
	sub_824C82E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824863c8
	if (!cr6.eq) goto loc_824863C8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824863AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824863C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824863e4
	goto loc_824863E4;
loc_824863C8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485980
	ctx.lr = 0x824863D4;
	sub_82485980(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824819e8
	ctx.lr = 0x824863E0;
	sub_824819E8(ctx, base);
	// li r21,1
	r21.s64 = 1;
loc_824863E4:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486424
	if (!cr6.eq) goto loc_82486424;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82486424
	if (cr6.eq) goto loc_82486424;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821ce080
	ctx.lr = 0x82486404;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r22)
	PPC_STORE_U32(r22.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x8248641C;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r22)
	PPC_STORE_U32(r22.u32 + 4, ctx.r10.u32);
loc_82486424:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82486430"))) PPC_WEAK_FUNC(sub_82486430);
PPC_FUNC_IMPL(__imp__sub_82486430) {
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
	ctx.lr = 0x82486438;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// li r28,0
	r28.s64 = 0;
	// bl 0x824e1160
	ctx.lr = 0x82486450;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824864fc
	if (cr6.eq) goto loc_824864FC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824819e8
	ctx.lr = 0x82486468;
	sub_824819E8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,36
	ctx.r4.s64 = 36;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824864fc
	if (cr6.eq) goto loc_824864FC;
	// bl 0x824cad58
	ctx.lr = 0x82486498;
	sub_824CAD58(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c8758
	ctx.lr = 0x824864A8;
	sub_824C8758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824864ec
	if (!cr6.eq) goto loc_824864EC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824864D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824864E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824864fc
	goto loc_824864FC;
loc_824864EC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485980
	ctx.lr = 0x824864F8;
	sub_82485980(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824864FC:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248653c
	if (!cr6.eq) goto loc_8248653C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248653c
	if (cr6.eq) goto loc_8248653C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x8248651C;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x82486534;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
loc_8248653C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82486548"))) PPC_WEAK_FUNC(sub_82486548);
PPC_FUNC_IMPL(__imp__sub_82486548) {
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
	ctx.lr = 0x82486550;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r30,2264
	r29.s64 = r30.s64 + 2264;
	// li r27,0
	r27.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1160
	ctx.lr = 0x8248656C;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248669c
	if (cr6.eq) goto loc_8248669C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1160
	ctx.lr = 0x82486580;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824865a4
	if (cr6.eq) goto loc_824865A4;
	// addi r3,r30,4408
	ctx.r3.s64 = r30.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x82486594;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824865a8
	if (cr6.eq) goto loc_824865A8;
loc_824865A4:
	// li r11,0
	r11.s64 = 0;
loc_824865A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248669c
	if (cr6.eq) goto loc_8248669C;
	// addi r3,r30,40
	ctx.r3.s64 = r30.s64 + 40;
	// bl 0x8252a6e8
	ctx.lr = 0x824865BC;
	sub_8252A6E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248669c
	if (!cr6.eq) goto loc_8248669C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1258
	ctx.lr = 0x824865D0;
	sub_824E1258(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824865e8
	if (cr6.eq) goto loc_824865E8;
	// lwz r11,11588(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11588);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248669c
	if (!cr6.eq) goto loc_8248669C;
loc_824865E8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3480
	ctx.r4.s64 = 3480;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248669c
	if (cr6.eq) goto loc_8248669C;
	// bl 0x824cde08
	ctx.lr = 0x82486618;
	sub_824CDE08(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c85b8
	ctx.lr = 0x82486628;
	sub_824C85B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248666c
	if (!cr6.eq) goto loc_8248666C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82486668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8248669c
	goto loc_8248669C;
loc_8248666C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e12a8
	ctx.lr = 0x82486674;
	sub_824E12A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248668c
	if (cr6.eq) goto loc_8248668C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824819e8
	ctx.lr = 0x8248668C;
	sub_824819E8(ctx, base);
loc_8248668C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82485980
	ctx.lr = 0x82486698;
	sub_82485980(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_8248669C:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824866dc
	if (!cr6.eq) goto loc_824866DC;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824866dc
	if (cr6.eq) goto loc_824866DC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ce080
	ctx.lr = 0x824866BC;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824866D4;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r10.u32);
loc_824866DC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824866E8"))) PPC_WEAK_FUNC(sub_824866E8);
PPC_FUNC_IMPL(__imp__sub_824866E8) {
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
	ctx.lr = 0x824866F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// li r28,0
	r28.s64 = 0;
	// bl 0x824e1160
	ctx.lr = 0x82486708;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824867b4
	if (cr6.eq) goto loc_824867B4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824867b4
	if (cr6.eq) goto loc_824867B4;
	// bl 0x824cc7a0
	ctx.lr = 0x82486744;
	sub_824CC7A0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c8758
	ctx.lr = 0x82486754;
	sub_824C8758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486798
	if (!cr6.eq) goto loc_82486798;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248677C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82486794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824867b4
	goto loc_824867B4;
loc_82486798:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485980
	ctx.lr = 0x824867A4;
	sub_82485980(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824819e8
	ctx.lr = 0x824867B0;
	sub_824819E8(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824867B4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824867f4
	if (!cr6.eq) goto loc_824867F4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824867f4
	if (cr6.eq) goto loc_824867F4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x824867D4;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824867EC;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
loc_824867F4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82486800"))) PPC_WEAK_FUNC(sub_82486800);
PPC_FUNC_IMPL(__imp__sub_82486800) {
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
	ctx.lr = 0x82486808;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r30,2264
	r31.s64 = r30.s64 + 2264;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x824e1160
	ctx.lr = 0x82486828;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486908
	if (cr6.eq) goto loc_82486908;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1160
	ctx.lr = 0x8248683C;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486860
	if (cr6.eq) goto loc_82486860;
	// addi r3,r30,4408
	ctx.r3.s64 = r30.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x82486850;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82486864
	if (cr6.eq) goto loc_82486864;
loc_82486860:
	// li r11,0
	r11.s64 = 0;
loc_82486864:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486908
	if (cr6.eq) goto loc_82486908;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,552
	ctx.r4.s64 = 552;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82486908
	if (cr6.eq) goto loc_82486908;
	// bl 0x824cb300
	ctx.lr = 0x824868A0;
	sub_824CB300(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c8d38
	ctx.lr = 0x824868B4;
	sub_824C8D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824868f8
	if (!cr6.eq) goto loc_824868F8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824868DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824868F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82486908
	goto loc_82486908;
loc_824868F8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82485980
	ctx.lr = 0x82486904;
	sub_82485980(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_82486908:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486948
	if (!cr6.eq) goto loc_82486948;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82486948
	if (cr6.eq) goto loc_82486948;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x82486928;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x82486940;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
loc_82486948:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82486954"))) PPC_WEAK_FUNC(sub_82486954);
PPC_FUNC_IMPL(__imp__sub_82486954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82486958"))) PPC_WEAK_FUNC(sub_82486958);
PPC_FUNC_IMPL(__imp__sub_82486958) {
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
	ctx.lr = 0x82486960;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// li r24,0
	r24.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1016
	ctx.r4.s64 = 1016;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824869A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82486a24
	if (cr6.eq) goto loc_82486A24;
	// bl 0x824cc8a8
	ctx.lr = 0x824869B0;
	sub_824CC8A8(ctx, base);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
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
	// bl 0x824c90a8
	ctx.lr = 0x824869D0;
	sub_824C90A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486a14
	if (!cr6.eq) goto loc_82486A14;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824869F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82486A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82486a24
	goto loc_82486A24;
loc_82486A14:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82485980
	ctx.lr = 0x82486A20;
	sub_82485980(ctx, base);
	// li r24,1
	r24.s64 = 1;
loc_82486A24:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486a4c
	if (!cr6.eq) goto loc_82486A4C;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82486a4c
	if (cr6.eq) goto loc_82486A4C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ce080
	ctx.lr = 0x82486A44;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r25)
	PPC_STORE_U32(r25.u32 + 4, r11.u32);
loc_82486A4C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82486A58"))) PPC_WEAK_FUNC(sub_82486A58);
PPC_FUNC_IMPL(__imp__sub_82486A58) {
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
	ctx.lr = 0x82486A60;
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// li r21,0
	r21.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82486bfc
	if (cr6.eq) goto loc_82486BFC;
	// cmplwi cr6,r31,32
	cr6.compare<uint32_t>(r31.u32, 32, xer);
	// bge cr6,0x82486bfc
	if (!cr6.lt) goto loc_82486BFC;
	// bl 0x82484880
	ctx.lr = 0x82486A90;
	sub_82484880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486bfc
	if (cr6.eq) goto loc_82486BFC;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// li r30,31
	r30.s64 = 31;
loc_82486AA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9438
	ctx.lr = 0x82486AAC;
	sub_824F9438(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bge 0x82486aa4
	if (!cr0.lt) goto loc_82486AA4;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82486bfc
	if (!cr6.gt) goto loc_82486BFC;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// mr r29,r27
	r29.u64 = r27.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
loc_82486AD0:
	// lwz r11,8308(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8308);
	// li r27,0
	r27.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82486b24
	if (!cr6.gt) goto loc_82486B24;
	// addi r31,r28,8180
	r31.s64 = r28.s64 + 8180;
loc_82486AE8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e7110
	ctx.lr = 0x82486AF0;
	sub_824E7110(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f92f8
	ctx.lr = 0x82486AFC;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486b20
	if (!cr6.eq) goto loc_82486B20;
	// lwz r11,8308(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8308);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82486ae8
	if (cr6.lt) goto loc_82486AE8;
	// b 0x82486b24
	goto loc_82486B24;
loc_82486B20:
	// li r27,1
	r27.s64 = 1;
loc_82486B24:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486b48
	if (!cr6.eq) goto loc_82486B48;
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// ld r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U64(r29.u32 + 8);
	// std r11,0(r26)
	PPC_STORE_U64(r26.u32 + 0, r11.u64);
	// std r10,8(r26)
	PPC_STORE_U64(r26.u32 + 8, ctx.r10.u64);
	// addi r26,r26,16
	r26.s64 = r26.s64 + 16;
loc_82486B48:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x82486ad0
	if (!cr0.eq) goto loc_82486AD0;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82486bfc
	if (cr6.eq) goto loc_82486BFC;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,172
	ctx.r4.s64 = 172;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82486bfc
	if (cr6.eq) goto loc_82486BFC;
	// bl 0x824cb380
	ctx.lr = 0x82486B8C;
	sub_824CB380(ctx, base);
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c8e58
	ctx.lr = 0x82486BA8;
	sub_824C8E58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486bec
	if (!cr6.eq) goto loc_82486BEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82486BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82486BE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82486bfc
	goto loc_82486BFC;
loc_82486BEC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82485980
	ctx.lr = 0x82486BF8;
	sub_82485980(ctx, base);
	// li r21,1
	r21.s64 = 1;
loc_82486BFC:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82486c3c
	if (!cr6.eq) goto loc_82486C3C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82486c3c
	if (cr6.eq) goto loc_82486C3C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821ce080
	ctx.lr = 0x82486C1C;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x82486C34;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r23)
	PPC_STORE_U32(r23.u32 + 4, ctx.r10.u32);
loc_82486C3C:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82486C48"))) PPC_WEAK_FUNC(sub_82486C48);
PPC_FUNC_IMPL(__imp__sub_82486C48) {
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
	ctx.lr = 0x82486C50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82486cd0
	if (cr6.eq) goto loc_82486CD0;
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// bl 0x82130000
	ctx.lr = 0x82486C74;
	sub_82130000(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252d058
	ctx.lr = 0x82486C7C;
	sub_8252D058(ctx, base);
	// addi r3,r31,11592
	ctx.r3.s64 = r31.s64 + 11592;
	// bl 0x8252f638
	ctx.lr = 0x82486C84;
	sub_8252F638(ctx, base);
	// lwz r11,11576(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11576);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82486ca0
	if (cr6.eq) goto loc_82486CA0;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// ble cr6,0x82486ca0
	if (!cr6.gt) goto loc_82486CA0;
	// subf r30,r11,r29
	r30.s64 = r29.s64 - r11.s64;
loc_82486CA0:
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// ori r10,r29,1
	ctx.r10.u64 = r29.u64 | 1;
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// stw r10,11576(r31)
	PPC_STORE_U32(r31.u32 + 11576, ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82486cc4
	if (cr6.eq) goto loc_82486CC4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,4552
	ctx.r3.s64 = r31.s64 + 4552;
	// bl 0x8252f0d8
	ctx.lr = 0x82486CC4;
	sub_8252F0D8(ctx, base);
loc_82486CC4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485a38
	ctx.lr = 0x82486CD0;
	sub_82485A38(ctx, base);
loc_82486CD0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82486CD8"))) PPC_WEAK_FUNC(sub_82486CD8);
PPC_FUNC_IMPL(__imp__sub_82486CD8) {
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
	ctx.lr = 0x82486CE0;
	// stwu r1,-1472(r1)
	ea = -1472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r5,11580(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 11580);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824ee190
	ctx.lr = 0x82486D04;
	sub_824EE190(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// std r31,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r31.u64);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r3,r30,2264
	ctx.r3.s64 = r30.s64 + 2264;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// bl 0x824e0e80
	ctx.lr = 0x82486D2C;
	sub_824E0E80(ctx, base);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r25.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// beq cr6,0x82486d58
	if (cr6.eq) goto loc_82486D58;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,632
	ctx.r3.s64 = ctx.r1.s64 + 632;
	// bl 0x8244d5c0
	ctx.lr = 0x82486D58;
	sub_8244D5C0(ctx, base);
loc_82486D58:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bge cr6,0x82486db0
	if (!cr6.lt) goto loc_82486DB0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,22412
	ctx.r10.s64 = r11.s64 + 22412;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r1,1152
	ctx.r5.s64 = ctx.r1.s64 + 1152;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82484540
	ctx.lr = 0x82486D84;
	sub_82484540(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82486dc8
	if (cr6.eq) goto loc_82486DC8;
	// addi r6,r1,1152
	ctx.r6.s64 = ctx.r1.s64 + 1152;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r5,11580(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 11580);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824eaf08
	ctx.lr = 0x82486DA8;
	sub_824EAF08(ctx, base);
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x823d923c
	return;
loc_82486DB0:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82485d70
	ctx.lr = 0x82486DC8;
	sub_82485D70(ctx, base);
loc_82486DC8:
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82486DD0"))) PPC_WEAK_FUNC(sub_82486DD0);
PPC_FUNC_IMPL(__imp__sub_82486DD0) {
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
	ctx.lr = 0x82486DD8;
	// stwu r1,-1584(r1)
	ea = -1584 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82130000
	ctx.lr = 0x82486DEC;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82486DF0;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x82486DFC;
	sub_82481B70(ctx, base);
	// addi r22,r31,2264
	r22.s64 = r31.s64 + 2264;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824e0e40
	ctx.lr = 0x82486E0C;
	sub_824E0E40(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// li r27,0
	r27.s64 = 0;
	// addi r8,r10,-8252
	ctx.r8.s64 = ctx.r10.s64 + -8252;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// bl 0x824e71c8
	ctx.lr = 0x82486E44;
	sub_824E71C8(ctx, base);
	// addi r3,r1,1376
	ctx.r3.s64 = ctx.r1.s64 + 1376;
	// bl 0x824e71c8
	ctx.lr = 0x82486E4C;
	sub_824E71C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x82486E5C;
	sub_823DA950(ctx, base);
	// li r23,512
	r23.s64 = 512;
	// stw r27,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r27.u32);
	// addi r3,r1,744
	ctx.r3.s64 = ctx.r1.s64 + 744;
	// stw r23,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r23.u32);
	// std r27,736(r1)
	PPC_STORE_U64(ctx.r1.u32 + 736, r27.u64);
	// bl 0x824e71c8
	ctx.lr = 0x82486E74;
	sub_824E71C8(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r27,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, r27.u32);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// stw r6,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r6.u32);
	// bl 0x824e6310
	ctx.lr = 0x82486E88;
	sub_824E6310(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82502300
	ctx.lr = 0x82486E90;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481af0
	ctx.lr = 0x82486E9C;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82486f50
	if (cr6.eq) goto loc_82486F50;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823da950
	ctx.lr = 0x82486EB4;
	sub_823DA950(ctx, base);
	// stw r23,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r23.u32);
	// stw r27,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r27.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,11532
	ctx.r3.s64 = r31.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x82486ECC;
	sub_824E7DB8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82502300
	ctx.lr = 0x82486ED4;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481af0
	ctx.lr = 0x82486EE0;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82486ef0
	if (cr6.eq) goto loc_82486EF0;
	// lwz r30,96(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// b 0x82486ef4
	goto loc_82486EF4;
loc_82486EF0:
	// li r30,-1
	r30.s64 = -1;
loc_82486EF4:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82486EFC;
	sub_824E0E80(ctx, base);
	// std r3,736(r1)
	PPC_STORE_U64(ctx.r1.u32 + 736, ctx.r3.u64);
	// addi r3,r1,744
	ctx.r3.s64 = ctx.r1.s64 + 744;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823da950
	ctx.lr = 0x82486F10;
	sub_823DA950(ctx, base);
	// lwz r5,724(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r5.u32);
	// beq cr6,0x82486f2c
	if (cr6.eq) goto loc_82486F2C;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,848
	ctx.r3.s64 = ctx.r1.s64 + 848;
	// bl 0x8244d5c0
	ctx.lr = 0x82486F2C;
	sub_8244D5C0(ctx, base);
loc_82486F2C:
	// stw r30,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, r30.u32);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// bl 0x824e6310
	ctx.lr = 0x82486F38;
	sub_824E6310(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r5,r1,736
	ctx.r5.s64 = ctx.r1.s64 + 736;
	// addi r3,r31,4552
	ctx.r3.s64 = r31.s64 + 4552;
	// bl 0x82485df8
	ctx.lr = 0x82486F50;
	sub_82485DF8(ctx, base);
loc_82486F50:
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// mr r24,r27
	r24.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824870bc
	if (!cr6.gt) goto loc_824870BC;
	// addi r26,r31,8180
	r26.s64 = r31.s64 + 8180;
loc_82486F64:
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7120
	ctx.lr = 0x82486F74;
	sub_824E7120(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824870a8
	if (!cr6.eq) goto loc_824870A8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82486F88;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82486F8C;
	sub_824F97C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82130000
	ctx.lr = 0x82486F98;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82486F9C;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r29,r3
	cr6.compare<uint64_t>(r29.u64, ctx.r3.u64, xer);
	// beq cr6,0x824870a8
	if (cr6.eq) goto loc_824870A8;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lbz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 108);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824870a8
	if (cr6.eq) goto loc_824870A8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82486FC8;
	sub_823DA950(ctx, base);
	// stw r23,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r23.u32);
	// stw r27,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r27.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,11532
	ctx.r3.s64 = r31.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x82486FE0;
	sub_824E7DB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82486FE8;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82486FEC;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x82486FF8;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82487010
	if (cr6.eq) goto loc_82487010;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x824eba48
	ctx.lr = 0x8248700C;
	sub_824EBA48(ctx, base);
	// b 0x82487018
	goto loc_82487018;
loc_82487010:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x82487018;
	sub_824E6310(ctx, base);
loc_82487018:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r28,0(r11)
	r28.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82502300
	ctx.lr = 0x82487028;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481af0
	ctx.lr = 0x82487034;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82487044
	if (cr6.eq) goto loc_82487044;
	// lwz r29,96(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// b 0x82487048
	goto loc_82487048;
loc_82487044:
	// li r29,-1
	r29.s64 = -1;
loc_82487048:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82487050;
	sub_824E0E80(ctx, base);
	// std r3,736(r1)
	PPC_STORE_U64(ctx.r1.u32 + 736, ctx.r3.u64);
	// addi r3,r1,744
	ctx.r3.s64 = ctx.r1.s64 + 744;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82487064;
	sub_823DA950(ctx, base);
	// lwz r5,724(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r5.u32);
	// beq cr6,0x82487080
	if (cr6.eq) goto loc_82487080;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,848
	ctx.r3.s64 = ctx.r1.s64 + 848;
	// bl 0x8244d5c0
	ctx.lr = 0x82487080;
	sub_8244D5C0(ctx, base);
loc_82487080:
	// stw r29,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, r29.u32);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// bl 0x824e6310
	ctx.lr = 0x8248708C;
	sub_824E6310(ctx, base);
	// std r28,1360(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1360, r28.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,736
	ctx.r5.s64 = ctx.r1.s64 + 736;
	// addi r3,r31,4552
	ctx.r3.s64 = r31.s64 + 4552;
	// bl 0x82485df8
	ctx.lr = 0x824870A8;
	sub_82485DF8(ctx, base);
loc_824870A8:
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82486f64
	if (cr6.lt) goto loc_82486F64;
loc_824870BC:
	// addi r1,r1,1584
	ctx.r1.s64 = ctx.r1.s64 + 1584;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824870C4"))) PPC_WEAK_FUNC(sub_824870C4);
PPC_FUNC_IMPL(__imp__sub_824870C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824870C8"))) PPC_WEAK_FUNC(sub_824870C8);
PPC_FUNC_IMPL(__imp__sub_824870C8) {
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
	ctx.lr = 0x824870D0;
	// stwu r1,-3472(r1)
	ea = -3472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x824870E4;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x824870E8;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481b70
	ctx.lr = 0x824870F4;
	sub_82481B70(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// li r26,0
	r26.s64 = 0;
	// addi r8,r10,-8252
	ctx.r8.s64 = ctx.r10.s64 + -8252;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// bl 0x824e71c8
	ctx.lr = 0x8248712C;
	sub_824E71C8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x8248713C;
	sub_823DA950(ctx, base);
	// li r6,512
	ctx.r6.s64 = 512;
	// stw r26,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r26.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r6,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r6.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r27,11532
	ctx.r3.s64 = r27.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x82487158;
	sub_824E7DB8(ctx, base);
	// std r26,736(r1)
	PPC_STORE_U64(ctx.r1.u32 + 736, r26.u64);
	// addi r3,r1,744
	ctx.r3.s64 = ctx.r1.s64 + 744;
	// bl 0x824e71c8
	ctx.lr = 0x82487164;
	sub_824E71C8(ctx, base);
	// li r30,-1
	r30.s64 = -1;
	// stw r26,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, r26.u32);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// stw r30,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, r30.u32);
	// bl 0x824e6310
	ctx.lr = 0x82487178;
	sub_824E6310(ctx, base);
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x824eba48
	ctx.lr = 0x82487184;
	sub_824EBA48(ctx, base);
	// lwz r5,724(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// addi r28,r1,208
	r28.s64 = ctx.r1.s64 + 208;
	// ld r29,0(r3)
	r29.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8248719c
	if (!cr6.eq) goto loc_8248719C;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_8248719C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502300
	ctx.lr = 0x824871A4;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481af0
	ctx.lr = 0x824871B0;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824871bc
	if (cr6.eq) goto loc_824871BC;
	// lwz r30,96(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
loc_824871BC:
	// addi r3,r27,2264
	ctx.r3.s64 = r27.s64 + 2264;
	// bl 0x824e0e80
	ctx.lr = 0x824871C4;
	sub_824E0E80(ctx, base);
	// std r3,736(r1)
	PPC_STORE_U64(ctx.r1.u32 + 736, ctx.r3.u64);
	// addi r3,r1,744
	ctx.r3.s64 = ctx.r1.s64 + 744;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x824871D8;
	sub_823DA950(ctx, base);
	// lwz r5,724(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r5.u32);
	// beq cr6,0x824871f4
	if (cr6.eq) goto loc_824871F4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,848
	ctx.r3.s64 = ctx.r1.s64 + 848;
	// bl 0x8244d5c0
	ctx.lr = 0x824871F4;
	sub_8244D5C0(ctx, base);
loc_824871F4:
	// stw r30,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, r30.u32);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// bl 0x824e6310
	ctx.lr = 0x82487200;
	sub_824E6310(ctx, base);
	// lwz r11,11524(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 11524);
	// std r29,1360(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1360, r29.u64);
	// mr r28,r26
	r28.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82487300
	if (!cr6.gt) goto loc_82487300;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r29,r27,11396
	r29.s64 = r27.s64 + 11396;
	// addi r25,r11,22156
	r25.s64 = r11.s64 + 22156;
loc_82487220:
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r8,r24
	cr6.compare<uint32_t>(ctx.r8.u32, r24.u32, xer);
	// beq cr6,0x824872ec
	if (cr6.eq) goto loc_824872EC;
	// lwz r9,80(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x824872ec
	if (!cr6.gt) goto loc_824872EC;
	// addi r10,r8,64
	ctx.r10.s64 = ctx.r8.s64 + 64;
loc_82487240:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r6,108(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 108);
	// rlwinm r5,r6,0,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82487268
	if (!cr6.eq) goto loc_82487268;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82487240
	if (cr6.lt) goto loc_82487240;
	// b 0x824872ec
	goto loc_824872EC;
loc_82487268:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// li r6,999
	ctx.r6.s64 = 999;
	// lwz r30,0(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r5,r1,1376
	ctx.r5.s64 = ctx.r1.s64 + 1376;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x824845f8
	ctx.lr = 0x82487284;
	sub_824845F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824872ec
	if (cr6.eq) goto loc_824872EC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1006
	ctx.r4.s64 = 1006;
	// addi r3,r1,2384
	ctx.r3.s64 = ctx.r1.s64 + 2384;
	// bl 0x8252e178
	ctx.lr = 0x824872A0;
	sub_8252E178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824872ec
	if (cr6.eq) goto loc_824872EC;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r31,r3,r5
	r31.u64 = ctx.r3.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,1006
	cr6.compare<uint32_t>(r31.u32, 1006, xer);
	// bgt cr6,0x824872ec
	if (cr6.gt) goto loc_824872EC;
	// addi r11,r1,2384
	r11.s64 = ctx.r1.s64 + 2384;
	// addi r4,r1,1376
	ctx.r4.s64 = ctx.r1.s64 + 1376;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824872C8;
	sub_8244D5C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824872ec
	if (cr6.eq) goto loc_824872EC;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,2384
	ctx.r5.s64 = ctx.r1.s64 + 2384;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r27,4552
	ctx.r3.s64 = r27.s64 + 4552;
	// bl 0x8252eaa0
	ctx.lr = 0x824872EC;
	sub_8252EAA0(ctx, base);
loc_824872EC:
	// lwz r11,11524(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 11524);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82487220
	if (cr6.lt) goto loc_82487220;
loc_82487300:
	// addi r1,r1,3472
	ctx.r1.s64 = ctx.r1.s64 + 3472;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82487308"))) PPC_WEAK_FUNC(sub_82487308);
PPC_FUNC_IMPL(__imp__sub_82487308) {
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
	ctx.lr = 0x82487310;
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
	// beq cr6,0x82487368
	if (cr6.eq) goto loc_82487368;
	// addi r31,r30,48
	r31.s64 = r30.s64 + 48;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x82487368
	if (cr6.eq) goto loc_82487368;
loc_82487334:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ld r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U64(r31.u32 + 8);
	// ld r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// ld r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// ld r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// ld r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// stb r28,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r28.u8);
	// bl 0x82485f88
	ctx.lr = 0x8248735C;
	sub_82485F88(ctx, base);
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bne cr6,0x82487334
	if (!cr6.eq) goto loc_82487334;
loc_82487368:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82487370"))) PPC_WEAK_FUNC(sub_82487370);
PPC_FUNC_IMPL(__imp__sub_82487370) {
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
	ctx.lr = 0x82487378;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
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
	// bl 0x824842e0
	ctx.lr = 0x8248739C;
	sub_824842E0(ctx, base);
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// bge cr6,0x82487464
	if (!cr6.lt) goto loc_82487464;
	// li r27,48
	r27.s64 = 48;
loc_824873AC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824873B4;
	sub_824F97C0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824873C0;
	sub_824F97C0(ctx, base);
	// cmpld cr6,r25,r3
	cr6.compare<uint64_t>(r25.u64, ctx.r3.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824873d0
	if (cr6.lt) goto loc_824873D0;
	// li r11,0
	r11.s64 = 0;
loc_824873D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82487458
	if (cr6.eq) goto loc_82487458;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824873EC:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824873ec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824873EC;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82487410:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82487410
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82487410;
	// ld r11,152(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// subf r10,r30,r29
	ctx.r10.s64 = r29.s64 - r30.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// divw r5,r10,r27
	ctx.r5.s32 = ctx.r10.s32 / r27.s32;
	// ld r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// ld r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// ld r10,144(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// stb r28,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r28.u8);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// bl 0x82483240
	ctx.lr = 0x82487458;
	sub_82483240(ctx, base);
loc_82487458:
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// cmplw cr6,r31,r26
	cr6.compare<uint32_t>(r31.u32, r26.u32, xer);
	// blt cr6,0x824873ac
	if (cr6.lt) goto loc_824873AC;
loc_82487464:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82486088
	ctx.lr = 0x82487474;
	sub_82486088(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8248747C"))) PPC_WEAK_FUNC(sub_8248747C);
PPC_FUNC_IMPL(__imp__sub_8248747C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82487480"))) PPC_WEAK_FUNC(sub_82487480);
PPC_FUNC_IMPL(__imp__sub_82487480) {
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
	ctx.lr = 0x82487488;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r26,48
	r26.s64 = 48;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// divw r10,r11,r26
	ctx.r10.s32 = r11.s32 / r26.s32;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// ble cr6,0x82487560
	if (!cr6.gt) goto loc_82487560;
loc_824874B0:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8248754c
	if (cr6.eq) goto loc_8248754C;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// divw r10,r11,r26
	ctx.r10.s32 = r11.s32 / r26.s32;
	// addi r5,r31,-48
	ctx.r5.s64 = r31.s64 + -48;
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x82481d50
	ctx.lr = 0x824874EC;
	sub_82481D50(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stb r27,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r27.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// ld r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// ld r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 24);
	// ld r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 32);
	// ld r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 40);
	// bl 0x824851d8
	ctx.lr = 0x82487518;
	sub_824851D8(ctx, base);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82487480
	ctx.lr = 0x82487530;
	sub_82487480(ctx, base);
	// subf r10,r30,r29
	ctx.r10.s64 = r29.s64 - r30.s64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// divw r9,r10,r26
	ctx.r9.s32 = ctx.r10.s32 / r26.s32;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// bgt cr6,0x824874b0
	if (cr6.gt) goto loc_824874B0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8248754C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82487370
	ctx.lr = 0x82487560;
	sub_82487370(ctx, base);
loc_82487560:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82487568"))) PPC_WEAK_FUNC(sub_82487568);
PPC_FUNC_IMPL(__imp__sub_82487568) {
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
	ctx.lr = 0x82487570;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r11,r3,4408
	r11.s64 = ctx.r3.s64 + 4408;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82487588:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82487588
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82487588;
	// lwz r11,11524(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11524);
	// li r27,1
	r27.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824876d0
	if (!cr6.gt) goto loc_824876D0;
	// addi r8,r28,48
	ctx.r8.s64 = r28.s64 + 48;
	// addi r7,r3,11396
	ctx.r7.s64 = ctx.r3.s64 + 11396;
loc_824875B8:
	// cmpwi cr6,r27,32
	cr6.compare<int32_t>(r27.s32, 32, xer);
	// bge cr6,0x82487610
	if (!cr6.lt) goto loc_82487610;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x824875fc
	if (cr6.lt) goto loc_824875FC;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824875E0:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824875e0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824875E0;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
loc_824875FC:
	// lwz r11,11524(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11524);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x824875b8
	if (cr6.lt) goto loc_824875B8;
loc_82487610:
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// ble cr6,0x824876d0
	if (!cr6.gt) goto loc_824876D0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r27,1,0,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r27,r11
	ctx.r8.u64 = r27.u64 + r11.u64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
	// cmplw cr6,r28,r31
	cr6.compare<uint32_t>(r28.u32, r31.u32, xer);
	// lbz r29,80(r1)
	r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// beq cr6,0x824876d0
	if (cr6.eq) goto loc_824876D0;
	// subf r10,r28,r31
	ctx.r10.s64 = r31.s64 - r28.s64;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r11,0
	r11.s64 = 0;
	// divw r30,r10,r9
	r30.s32 = ctx.r10.s32 / ctx.r9.s32;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x8248766c
	if (cr6.eq) goto loc_8248766C;
loc_8248765C:
	// srawi r10,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8248765c
	if (!cr6.eq) goto loc_8248765C;
loc_8248766C:
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82487480
	ctx.lr = 0x82487684;
	sub_82487480(ctx, base);
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// ble cr6,0x824876c4
	if (!cr6.gt) goto loc_824876C4;
	// addi r30,r28,768
	r30.s64 = r28.s64 + 768;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82487308
	ctx.lr = 0x824876A4;
	sub_82487308(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824831e8
	ctx.lr = 0x824876B8;
	sub_824831E8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824876C4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82487308
	ctx.lr = 0x824876D0;
	sub_82487308(ctx, base);
loc_824876D0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824876DC"))) PPC_WEAK_FUNC(sub_824876DC);
PPC_FUNC_IMPL(__imp__sub_824876DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824876E0"))) PPC_WEAK_FUNC(sub_824876E0);
PPC_FUNC_IMPL(__imp__sub_824876E0) {
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
	ctx.lr = 0x824876E8;
	// stwu r1,-1648(r1)
	ea = -1648 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824877ac
	if (cr6.lt) goto loc_824877AC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x824ef220
	ctx.lr = 0x8248770C;
	sub_824EF220(ctx, base);
	// li r29,-1
	r29.s64 = -1;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// bl 0x824f97c0
	ctx.lr = 0x8248771C;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// bne cr6,0x824877ac
	if (!cr6.eq) goto loc_824877AC;
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824877ac
	if (!cr6.eq) goto loc_824877AC;
	// std r29,4496(r31)
	PPC_STORE_U64(r31.u32 + 4496, r29.u64);
	// addi r30,r31,2264
	r30.s64 = r31.s64 + 2264;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e1160
	ctx.lr = 0x82487748;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824877ac
	if (cr6.eq) goto loc_824877AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e0e40
	ctx.lr = 0x8248775C;
	sub_824E0E40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824825f0
	ctx.lr = 0x82487768;
	sub_824825F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824877ac
	if (cr6.eq) goto loc_824877AC;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// li r30,31
	r30.s64 = 31;
loc_8248777C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f99c0
	ctx.lr = 0x82487784;
	sub_824F99C0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,48
	r29.s64 = r29.s64 + 48;
	// bge 0x8248777c
	if (!cr0.lt) goto loc_8248777C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82487568
	ctx.lr = 0x8248779C;
	sub_82487568(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824853d0
	ctx.lr = 0x824877AC;
	sub_824853D0(ctx, base);
loc_824877AC:
	// addi r1,r1,1648
	ctx.r1.s64 = ctx.r1.s64 + 1648;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824877B4"))) PPC_WEAK_FUNC(sub_824877B4);
PPC_FUNC_IMPL(__imp__sub_824877B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824877B8"))) PPC_WEAK_FUNC(sub_824877B8);
PPC_FUNC_IMPL(__imp__sub_824877B8) {
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
	// addi r11,r31,4400
	r11.s64 = r31.s64 + 4400;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x824878bc
	if (cr6.eq) goto loc_824878BC;
	// bl 0x824876e0
	ctx.lr = 0x824877E4;
	sub_824876E0(ctx, base);
	// lwz r9,11524(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82487854
	if (!cr6.gt) goto loc_82487854;
	// addi r10,r31,11396
	ctx.r10.s64 = r31.s64 + 11396;
loc_824877F8:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x8248781c
	if (cr6.eq) goto loc_8248781C;
	// lwz r8,11524(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824877f8
	if (cr6.lt) goto loc_824877F8;
	// b 0x82487854
	goto loc_82487854;
loc_8248781C:
	// addi r10,r9,2848
	ctx.r10.s64 = ctx.r9.s64 + 2848;
	// addi r9,r11,2849
	ctx.r9.s64 = r11.s64 + 2849;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwzx r5,r8,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// stwx r5,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r5.u32);
	// lwz r11,11524(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// addi r4,r11,2848
	ctx.r4.s64 = r11.s64 + 2848;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r3,r31
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, ctx.r6.u32);
	// lwz r11,11524(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,11524(r31)
	PPC_STORE_U32(r31.u32 + 11524, r11.u32);
loc_82487854:
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// bl 0x824f9788
	ctx.lr = 0x82487864;
	sub_824F9788(ctx, base);
	// addi r3,r30,56
	ctx.r3.s64 = r30.s64 + 56;
	// bl 0x824e6310
	ctx.lr = 0x8248786C;
	sub_824E6310(ctx, base);
	// lbz r10,92(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 92);
	// addi r11,r31,11384
	r11.s64 = r31.s64 + 11384;
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,92(r30)
	PPC_STORE_U8(r30.u32 + 92, ctx.r9.u8);
	// lwz r10,11388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 11388);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824878a8
	if (cr6.eq) goto loc_824878A8;
	// stw r30,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r30.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,88(r30)
	PPC_STORE_U32(r30.u32 + 88, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// bne cr6,0x824878b0
	if (!cr6.eq) goto loc_824878B0;
	// b 0x824878ac
	goto loc_824878AC;
loc_824878A8:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
loc_824878AC:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_824878B0:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_824878BC:
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

__attribute__((alias("__imp__sub_824878D4"))) PPC_WEAK_FUNC(sub_824878D4);
PPC_FUNC_IMPL(__imp__sub_824878D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824878D8"))) PPC_WEAK_FUNC(sub_824878D8);
PPC_FUNC_IMPL(__imp__sub_824878D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// bl 0x82481b70
	ctx.lr = 0x824878F0;
	sub_82481B70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82487904
	if (cr6.eq) goto loc_82487904;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824877b8
	ctx.lr = 0x82487904;
	sub_824877B8(ctx, base);
loc_82487904:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82487918"))) PPC_WEAK_FUNC(sub_82487918);
PPC_FUNC_IMPL(__imp__sub_82487918) {
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
	ctx.lr = 0x82487920;
	// stwu r1,-2496(r1)
	ea = -2496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// addi r28,r31,2264
	r28.s64 = r31.s64 + 2264;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// li r27,-1
	r27.s64 = -1;
	// mr r22,r25
	r22.u64 = r25.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82487958;
	sub_824E0E80(ctx, base);
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// bne cr6,0x82487ad4
	if (!cr6.eq) goto loc_82487AD4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x82130000
	ctx.lr = 0x8248796C;
	sub_82130000(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x824f97c0
	ctx.lr = 0x82487974;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x82487980;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82487ad4
	if (!cr6.eq) goto loc_82487AD4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,624
	ctx.r5.s64 = 624;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82487998;
	sub_823DA950(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,184(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// bl 0x824818a8
	ctx.lr = 0x824879A4;
	sub_824818A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824879fc
	if (!cr6.eq) goto loc_824879FC;
	// lwz r11,184(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824879c0
	if (!cr6.eq) goto loc_824879C0;
	// li r25,1
	r25.s64 = 1;
	// b 0x82487ad4
	goto loc_82487AD4;
loc_824879C0:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0ec8
	ctx.lr = 0x824879CC;
	sub_824E0EC8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e0f28
	ctx.lr = 0x824879D8;
	sub_824E0F28(ctx, base);
	// lwz r11,11528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11528);
	// lwz r10,8308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// subf r11,r30,r9
	r11.s64 = ctx.r9.s64 - r30.s64;
	// add. r8,r11,r3
	ctx.r8.u64 = r11.u64 + ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x824879f8
	if (!cr0.eq) goto loc_824879F8;
	// li r25,1
	r25.s64 = 1;
	// b 0x82487ad4
	goto loc_82487AD4;
loc_824879F8:
	// stw r25,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r25.u32);
loc_824879FC:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,11580(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 11580);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x824efd90
	ctx.lr = 0x82487A14;
	sub_824EFD90(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x82487ad4
	if (cr6.lt) goto loc_82487AD4;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824849b8
	ctx.lr = 0x82487A30;
	sub_824849B8(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82487ad4
	if (cr6.eq) goto loc_82487AD4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1056
	ctx.r4.s64 = 1056;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82487A5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82487ad4
	if (cr6.eq) goto loc_82487AD4;
	// bl 0x824ccfa0
	ctx.lr = 0x82487A6C;
	sub_824CCFA0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r7,r29,1048
	ctx.r7.s64 = r29.s64 + 1048;
	// addi r10,r11,-8440
	ctx.r10.s64 = r11.s64 + -8440;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r25,1048(r29)
	PPC_STORE_U32(r29.u32 + 1048, r25.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r25,1052(r29)
	PPC_STORE_U32(r29.u32 + 1052, r25.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824c6b68
	ctx.lr = 0x82487A98;
	sub_824C6B68(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82487ad4
	if (cr6.eq) goto loc_82487AD4;
	// lwz r7,188(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82487ab8
	if (!cr6.eq) goto loc_82487AB8;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
loc_82487AB8:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r5,184(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485668
	ctx.lr = 0x82487AC8;
	sub_82485668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82487b5c
	if (!cr6.eq) goto loc_82487B5C;
loc_82487AD4:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82486cd8
	ctx.lr = 0x82487AEC;
	sub_82486CD8(ctx, base);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x82487b04
	if (cr6.lt) goto loc_82487B04;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824ef220
	ctx.lr = 0x82487B04;
	sub_824EF220(ctx, base);
loc_82487B04:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82487b18
	if (cr6.eq) goto loc_82487B18;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824877b8
	ctx.lr = 0x82487B18;
	sub_824877B8(ctx, base);
loc_82487B18:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82487c08
	if (cr6.eq) goto loc_82487C08;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82487B3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82487B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,2496
	ctx.r1.s64 = ctx.r1.s64 + 2496;
	// b 0x823d9228
	return;
loc_82487B5C:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,1760
	ctx.r3.s64 = ctx.r1.s64 + 1760;
	// bl 0x82482170
	ctx.lr = 0x82487B68;
	sub_82482170(ctx, base);
	// addi r5,r1,1760
	ctx.r5.s64 = ctx.r1.s64 + 1760;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,11532
	ctx.r3.s64 = r31.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x82487B78;
	sub_824E7DB8(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// std r25,704(r1)
	PPC_STORE_U64(ctx.r1.u32 + 704, r25.u64);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, r11.u32);
	// stw r25,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, r25.u32);
	// stw r25,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r25.u32);
	// stw r25,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r25.u32);
	// bl 0x824e0e80
	ctx.lr = 0x82487B98;
	sub_824E0E80(ctx, base);
	// lwz r5,2388(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2388);
	// lwz r10,184(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// li r9,3
	ctx.r9.s64 = 3;
	// std r3,704(r1)
	PPC_STORE_U64(ctx.r1.u32 + 704, ctx.r3.u64);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r9,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r9.u32);
	// stw r5,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r5.u32);
	// stw r10,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r10.u32);
	// beq cr6,0x82487bc8
	if (cr6.eq) goto loc_82487BC8;
	// addi r4,r1,1872
	ctx.r4.s64 = ctx.r1.s64 + 1872;
	// addi r3,r1,728
	ctx.r3.s64 = ctx.r1.s64 + 728;
	// bl 0x8244d5c0
	ctx.lr = 0x82487BC8;
	sub_8244D5C0(ctx, base);
loc_82487BC8:
	// stw r21,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r21.u32);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82487be4
	if (cr6.eq) goto loc_82487BE4;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,1240
	ctx.r3.s64 = ctx.r1.s64 + 1240;
	// bl 0x8244d5c0
	ctx.lr = 0x82487BE4;
	sub_8244D5C0(ctx, base);
loc_82487BE4:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,704
	ctx.r5.s64 = ctx.r1.s64 + 704;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82485d70
	ctx.lr = 0x82487BFC;
	sub_82485D70(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485980
	ctx.lr = 0x82487C08;
	sub_82485980(ctx, base);
loc_82487C08:
	// addi r1,r1,2496
	ctx.r1.s64 = ctx.r1.s64 + 2496;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82487C10"))) PPC_WEAK_FUNC(sub_82487C10);
PPC_FUNC_IMPL(__imp__sub_82487C10) {
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
	ctx.lr = 0x82487C18;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82487c6c
	if (!cr6.gt) goto loc_82487C6C;
	// addi r29,r31,8180
	r29.s64 = r31.s64 + 8180;
loc_82487C3C:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82502300
	ctx.lr = 0x82487C44;
	sub_82502300(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824f0550
	ctx.lr = 0x82487C4C;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82487c78
	if (!cr6.eq) goto loc_82487C78;
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x82487c3c
	if (cr6.lt) goto loc_82487C3C;
loc_82487C6C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
loc_82487C78:
	// addi r11,r30,2045
	r11.s64 = r30.s64 + 2045;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r28,r31
	r30.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82487c6c
	if (cr6.eq) goto loc_82487C6C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82487C94;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x82487C98;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x82487CA4;
	sub_82481B70(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82487c6c
	if (cr6.eq) goto loc_82487C6C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82481450
	ctx.lr = 0x82487CB8;
	sub_82481450(ctx, base);
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r11,r11,2044
	r11.s64 = r11.s64 + 2044;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stwx r9,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, ctx.r9.u32);
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r8,r11,2044
	ctx.r8.s64 = r11.s64 + 2044;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r26,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, r26.u32);
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,8308(r31)
	PPC_STORE_U32(r31.u32 + 8308, ctx.r6.u32);
	// lwz r5,96(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bne cr6,0x82487d00
	if (!cr6.eq) goto loc_82487D00;
	// lwz r11,11528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11528);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,11528(r31)
	PPC_STORE_U32(r31.u32 + 11528, r11.u32);
loc_82487D00:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// addi r8,r10,-8216
	ctx.r8.s64 = ctx.r10.s64 + -8216;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82487D38;
	sub_823DA950(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,11532
	ctx.r3.s64 = r31.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x82487D48;
	sub_824E7DB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6f20
	ctx.lr = 0x82487D50;
	sub_824E6F20(ctx, base);
	// lbz r11,108(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 108);
	// li r6,-1
	ctx.r6.s64 = -1;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r6,96(r30)
	PPC_STORE_U32(r30.u32 + 96, ctx.r6.u32);
	// addi r4,r31,8168
	ctx.r4.s64 = r31.s64 + 8168;
	// stb r10,108(r30)
	PPC_STORE_U8(r30.u32 + 108, ctx.r10.u8);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82482988
	ctx.lr = 0x82487D78;
	sub_82482988(ctx, base);
	// lwz r9,80(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82487d90
	if (!cr6.eq) goto loc_82487D90;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824877b8
	ctx.lr = 0x82487D90;
	sub_824877B8(ctx, base);
loc_82487D90:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82487D9C"))) PPC_WEAK_FUNC(sub_82487D9C);
PPC_FUNC_IMPL(__imp__sub_82487D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82487DA0"))) PPC_WEAK_FUNC(sub_82487DA0);
PPC_FUNC_IMPL(__imp__sub_82487DA0) {
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
	ctx.lr = 0x82487DA8;
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r20,0
	r20.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r30,r20
	r30.u64 = r20.u64;
	// ble cr6,0x824880ac
	if (!cr6.gt) goto loc_824880AC;
	// ld r4,4496(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82487DE0;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82487df4
	if (cr6.eq) goto loc_82487DF4;
	// cmplw cr6,r27,r3
	cr6.compare<uint32_t>(r27.u32, ctx.r3.u32, xer);
	// li r21,1
	r21.s64 = 1;
	// beq cr6,0x82487df8
	if (cr6.eq) goto loc_82487DF8;
loc_82487DF4:
	// mr r21,r20
	r21.u64 = r20.u64;
loc_82487DF8:
	// addi r11,r29,4400
	r11.s64 = r29.s64 + 4400;
	// addi r25,r29,2264
	r25.s64 = r29.s64 + 2264;
	// subf r10,r27,r11
	ctx.r10.s64 = r11.s64 - r27.s64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r22,r9,27,31,31
	r22.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x824e1160
	ctx.lr = 0x82487E14;
	sub_824E1160(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82487e38
	if (cr6.eq) goto loc_82487E38;
	// addi r3,r29,4408
	ctx.r3.s64 = r29.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x82487E28;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82487e3c
	if (cr6.eq) goto loc_82487E3C;
loc_82487E38:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82487E3C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82487e60
	if (!cr6.eq) goto loc_82487E60;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82487e60
	if (!cr6.eq) goto loc_82487E60;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824880ac
	if (cr6.eq) goto loc_824880AC;
loc_82487E60:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82487e90
	if (cr6.eq) goto loc_82487E90;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c7440
	ctx.lr = 0x82487E80;
	sub_824C7440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824880ac
	if (cr6.eq) goto loc_824880AC;
	// b 0x82487f28
	goto loc_82487F28;
loc_82487E90:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,304
	ctx.r4.s64 = 304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82487EB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824880ac
	if (cr6.eq) goto loc_824880AC;
	// bl 0x824cab68
	ctx.lr = 0x82487EC0;
	sub_824CAB68(ctx, base);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c7440
	ctx.lr = 0x82487ED8;
	sub_824C7440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82487f1c
	if (!cr6.eq) goto loc_82487F1C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r29,0(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82487F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82487F18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824880ac
	goto loc_824880AC;
loc_82487F1C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82485980
	ctx.lr = 0x82487F28;
	sub_82485980(ctx, base);
loc_82487F28:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x82487F30;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82487fa0
	if (cr6.eq) goto loc_82487FA0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x8248802c
	if (!cr6.eq) goto loc_8248802C;
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
	// std r20,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r20.u64);
	// li r31,31
	r31.s64 = 31;
loc_82487F50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x82487F58;
	sub_824F0498(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x82487f50
	if (!cr0.lt) goto loc_82487F50;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82487F6C;
	sub_824E0E80(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82487f88
	if (cr6.eq) goto loc_82487F88;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r5,r28,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823dadd8
	ctx.lr = 0x82487F88;
	sub_823DADD8(ctx, base);
loc_82487F88:
	// stw r28,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r28.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82485e80
	ctx.lr = 0x82487F9C;
	sub_82485E80(ctx, base);
	// b 0x8248802c
	goto loc_8248802C;
loc_82487FA0:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248802c
	if (cr6.eq) goto loc_8248802C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ld r4,4496(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 4496);
	// bl 0x82481b70
	ctx.lr = 0x82487FB8;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248802c
	if (cr6.eq) goto loc_8248802C;
	// lwz r27,0(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8248802c
	if (cr6.lt) goto loc_8248802C;
	// addi r30,r1,360
	r30.s64 = ctx.r1.s64 + 360;
	// std r20,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, r20.u64);
	// li r31,31
	r31.s64 = 31;
loc_82487FD8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x82487FE0;
	sub_824F0498(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x82487fd8
	if (!cr0.lt) goto loc_82487FD8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82487FF4;
	sub_824E0E80(ctx, base);
	// std r3,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, ctx.r3.u64);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82488010
	if (cr6.eq) goto loc_82488010;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,360
	ctx.r3.s64 = ctx.r1.s64 + 360;
	// rlwinm r5,r28,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823dadd8
	ctx.lr = 0x82488010;
	sub_823DADD8(ctx, base);
loc_82488010:
	// stw r28,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, r28.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,4552
	ctx.r3.s64 = r29.s64 + 4552;
	// bl 0x824850c0
	ctx.lr = 0x8248802C;
	sub_824850C0(ctx, base);
loc_8248802C:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x824880a8
	if (!cr6.gt) goto loc_824880A8;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_82488038:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481af0
	ctx.lr = 0x82488044;
	sub_82481AF0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8248809c
	if (cr6.eq) goto loc_8248809C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x82488058;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488090
	if (!cr6.eq) goto loc_82488090;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488090
	if (!cr6.eq) goto loc_82488090;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248809c
	if (cr6.eq) goto loc_8248809C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7008
	ctx.lr = 0x82488084;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248809c
	if (cr6.eq) goto loc_8248809C;
loc_82488090:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82487c10
	ctx.lr = 0x8248809C;
	sub_82487C10(ctx, base);
loc_8248809C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82488038
	if (!cr0.eq) goto loc_82488038;
loc_824880A8:
	// li r30,1
	r30.s64 = 1;
loc_824880AC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824880e8
	if (!cr6.eq) goto loc_824880E8;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824880e8
	if (cr6.eq) goto loc_824880E8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821ce080
	ctx.lr = 0x824880CC;
	sub_821CE080(ctx, base);
	// stw r20,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r20.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824880E0;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r23)
	PPC_STORE_U32(r23.u32 + 4, r11.u32);
loc_824880E8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824880F4"))) PPC_WEAK_FUNC(sub_824880F4);
PPC_FUNC_IMPL(__imp__sub_824880F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824880F8"))) PPC_WEAK_FUNC(sub_824880F8);
PPC_FUNC_IMPL(__imp__sub_824880F8) {
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
	ctx.lr = 0x82488100;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// li r23,0
	r23.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// bl 0x824f97c0
	ctx.lr = 0x82488130;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x8248813C;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824881ac
	if (!cr6.eq) goto loc_824881AC;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x82488178
	if (!cr6.lt) goto loc_82488178;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// lwz r5,11580(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 11580);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x824efbf8
	ctx.lr = 0x82488168;
	sub_824EFBF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r30
	r28.u64 = r30.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824881ac
	if (cr6.lt) goto loc_824881AC;
loc_82488178:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824849b8
	ctx.lr = 0x82488188;
	sub_824849B8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824881ec
	if (!cr6.eq) goto loc_824881EC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824881ac
	if (cr6.lt) goto loc_824881AC;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824ef220
	ctx.lr = 0x824881AC;
	sub_824EF220(ctx, base);
loc_824881AC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82488228
	if (cr6.eq) goto loc_82488228;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x824881C0;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824881D8;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_824881EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481688
	ctx.lr = 0x824881F4;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488228
	if (!cr6.eq) goto loc_82488228;
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82488228
	if (!cr6.eq) goto loc_82488228;
	// lwz r11,11524(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82488228
	if (!cr6.eq) goto loc_82488228;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f97c0
	ctx.lr = 0x82488224;
	sub_824F97C0(ctx, base);
	// std r3,4496(r31)
	PPC_STORE_U64(r31.u32 + 4496, ctx.r3.u64);
loc_82488228:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82488234"))) PPC_WEAK_FUNC(sub_82488234);
PPC_FUNC_IMPL(__imp__sub_82488234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82488238"))) PPC_WEAK_FUNC(sub_82488238);
PPC_FUNC_IMPL(__imp__sub_82488238) {
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
	ctx.lr = 0x82488240;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,-1
	r29.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// std r29,4496(r31)
	PPC_STORE_U64(r31.u32 + 4496, r29.u64);
	// bl 0x824819e8
	ctx.lr = 0x82488258;
	sub_824819E8(ctx, base);
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82488288
	if (cr6.eq) goto loc_82488288;
	// addi r3,r31,4552
	ctx.r3.s64 = r31.s64 + 4552;
	// bl 0x8252e9b0
	ctx.lr = 0x82488270;
	sub_8252E9B0(ctx, base);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x824ebcc8
	ctx.lr = 0x8248827C;
	sub_824EBCC8(ctx, base);
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,11608(r31)
	PPC_STORE_U8(r31.u32 + 11608, ctx.r10.u8);
loc_82488288:
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824882b4
	if (cr6.eq) goto loc_824882B4;
loc_82488294:
	// lwz r3,8180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8180);
	// bl 0x82502300
	ctx.lr = 0x8248829C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82487c10
	ctx.lr = 0x824882A8;
	sub_82487C10(ctx, base);
	// lwz r11,8308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488294
	if (!cr6.eq) goto loc_82488294;
loc_824882B4:
	// lwz r11,11524(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824882d8
	if (cr6.eq) goto loc_824882D8;
loc_824882C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,11396(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 11396);
	// bl 0x824877b8
	ctx.lr = 0x824882CC;
	sub_824877B8(ctx, base);
	// lwz r11,11524(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824882c0
	if (!cr6.eq) goto loc_824882C0;
loc_824882D8:
	// stw r29,4400(r31)
	PPC_STORE_U32(r31.u32 + 4400, r29.u32);
	// addi r30,r31,4400
	r30.s64 = r31.s64 + 4400;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x824f9788
	ctx.lr = 0x824882E8;
	sub_824F9788(ctx, base);
	// addi r3,r30,56
	ctx.r3.s64 = r30.s64 + 56;
	// bl 0x824e6310
	ctx.lr = 0x824882F0;
	sub_824E6310(ctx, base);
	// lbz r10,4492(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4492);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,4492(r31)
	PPC_STORE_U8(r31.u32 + 4492, ctx.r9.u8);
	// lbz r8,11608(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r7,r7,0,27,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r11,11528(r31)
	PPC_STORE_U32(r31.u32 + 11528, r11.u32);
	// stw r11,11588(r31)
	PPC_STORE_U32(r31.u32 + 11588, r11.u32);
	// stb r7,11608(r31)
	PPC_STORE_U8(r31.u32 + 11608, ctx.r7.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82488320"))) PPC_WEAK_FUNC(sub_82488320);
PPC_FUNC_IMPL(__imp__sub_82488320) {
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
	ctx.lr = 0x82488328;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,11608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824884a0
	if (cr6.eq) goto loc_824884A0;
	// addi r3,r31,11532
	ctx.r3.s64 = r31.s64 + 11532;
	// bl 0x824e7d20
	ctx.lr = 0x82488348;
	sub_824E7D20(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252cfa8
	ctx.lr = 0x82488350;
	sub_8252CFA8(ctx, base);
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// bl 0x824e5a60
	ctx.lr = 0x82488358;
	sub_824E5A60(ctx, base);
	// addi r3,r31,11592
	ctx.r3.s64 = r31.s64 + 11592;
	// bl 0x8252f580
	ctx.lr = 0x82488360;
	sub_8252F580(ctx, base);
	// lwz r11,11556(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11556);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824883e8
	if (cr6.eq) goto loc_824883E8;
	// addi r29,r31,11548
	r29.s64 = r31.s64 + 11548;
loc_82488370:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248839c
	if (!cr6.eq) goto loc_8248839C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248839C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248839C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82482670
	ctx.lr = 0x824883A8;
	sub_82482670(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824883C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824883DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,11556(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 11556);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82488370
	if (!cr6.eq) goto loc_82488370;
loc_824883E8:
	// lwz r11,11568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11568);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488440
	if (cr6.eq) goto loc_82488440;
	// addi r30,r31,11560
	r30.s64 = r31.s64 + 11560;
loc_824883F8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82488420
	if (!cr6.eq) goto loc_82488420;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82488420;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82488420:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82488434
	if (cr6.eq) goto loc_82488434;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82482670
	ctx.lr = 0x82488434;
	sub_82482670(ctx, base);
loc_82488434:
	// lwz r11,11568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11568);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824883f8
	if (!cr6.eq) goto loc_824883F8;
loc_82488440:
	// lwz r3,11572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 11572);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248845c
	if (cr6.eq) goto loc_8248845C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x82488458;
	sub_824E1948(ctx, base);
	// stw r30,11572(r31)
	PPC_STORE_U32(r31.u32 + 11572, r30.u32);
loc_8248845C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82488238
	ctx.lr = 0x82488464;
	sub_82488238(ctx, base);
	// addi r3,r31,8168
	ctx.r3.s64 = r31.s64 + 8168;
	// bl 0x82483cd0
	ctx.lr = 0x8248846C;
	sub_82483CD0(ctx, base);
	// addi r3,r31,11384
	ctx.r3.s64 = r31.s64 + 11384;
	// bl 0x82483d28
	ctx.lr = 0x82488474;
	sub_82483D28(ctx, base);
	// lbz r10,11608(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// li r11,-1
	r11.s64 = -1;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,11576(r31)
	PPC_STORE_U32(r31.u32 + 11576, r30.u32);
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r11,11580(r31)
	PPC_STORE_U32(r31.u32 + 11580, r11.u32);
	// stw r30,11584(r31)
	PPC_STORE_U32(r31.u32 + 11584, r30.u32);
	// stw r30,11588(r31)
	PPC_STORE_U32(r31.u32 + 11588, r30.u32);
	// stb r9,11608(r31)
	PPC_STORE_U8(r31.u32 + 11608, ctx.r9.u8);
loc_824884A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824884A8"))) PPC_WEAK_FUNC(sub_824884A8);
PPC_FUNC_IMPL(__imp__sub_824884A8) {
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
	ctx.lr = 0x824884B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r27,r31,2264
	r27.s64 = r31.s64 + 2264;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e1160
	ctx.lr = 0x824884CC;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488540
	if (cr6.eq) goto loc_82488540;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7008
	ctx.lr = 0x824884E0;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488540
	if (cr6.eq) goto loc_82488540;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82502300
	ctx.lr = 0x824884F4;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481af0
	ctx.lr = 0x82488500;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82488540
	if (cr6.eq) goto loc_82488540;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82502300
	ctx.lr = 0x82488510;
	sub_82502300(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,4400
	ctx.r4.s64 = r31.s64 + 4400;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x82487da0
	ctx.lr = 0x82488530;
	sub_82487DA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488544
	if (!cr6.eq) goto loc_82488544;
loc_82488540:
	// li r28,0
	r28.s64 = 0;
loc_82488544:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488584
	if (!cr6.eq) goto loc_82488584;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82488584
	if (cr6.eq) goto loc_82488584;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x82488564;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x8248857C;
	sub_821CE0A0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
loc_82488584:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0e40
	ctx.lr = 0x8248858C;
	sub_824E0E40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7120
	ctx.lr = 0x82488598;
	sub_824E7120(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824885b0
	if (cr6.eq) goto loc_824885B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824819e8
	ctx.lr = 0x824885B0;
	sub_824819E8(ctx, base);
loc_824885B0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824885BC"))) PPC_WEAK_FUNC(sub_824885BC);
PPC_FUNC_IMPL(__imp__sub_824885BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824885C0"))) PPC_WEAK_FUNC(sub_824885C0);
PPC_FUNC_IMPL(__imp__sub_824885C0) {
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
	ctx.lr = 0x824885C8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,2264
	r30.s64 = r31.s64 + 2264;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x824e1160
	ctx.lr = 0x824885EC;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824886b8
	if (cr6.eq) goto loc_824886B8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e1160
	ctx.lr = 0x82488600;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488624
	if (cr6.eq) goto loc_82488624;
	// addi r3,r31,4408
	ctx.r3.s64 = r31.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x82488614;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82488628
	if (cr6.eq) goto loc_82488628;
loc_82488624:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82488628:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824886b8
	if (cr6.eq) goto loc_824886B8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481b70
	ctx.lr = 0x82488640;
	sub_82481B70(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824886b8
	if (cr6.eq) goto loc_824886B8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824876e0
	ctx.lr = 0x82488658;
	sub_824876E0(ctx, base);
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// li r30,3
	r30.s64 = 3;
loc_82488660:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x82488668;
	sub_824F0498(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bge 0x82488660
	if (!cr0.lt) goto loc_82488660;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824813e0
	ctx.lr = 0x82488684;
	sub_824813E0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824886f4
	if (cr6.eq) goto loc_824886F4;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,4400
	ctx.r4.s64 = r31.s64 + 4400;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82487da0
	ctx.lr = 0x824886AC;
	sub_82487DA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488718
	if (!cr6.eq) goto loc_82488718;
loc_824886B8:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824886e8
	if (cr6.eq) goto loc_824886E8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824886CC;
	sub_821CE080(ctx, base);
	// stw r25,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r25.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824886E0;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
loc_824886E8:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
loc_824886F4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824877b8
	ctx.lr = 0x82488700;
	sub_824877B8(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82488718
	if (cr6.eq) goto loc_82488718;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x82488714;
	sub_821CE080(ctx, base);
	// stw r25,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r25.u32);
loc_82488718:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82488724"))) PPC_WEAK_FUNC(sub_82488724);
PPC_FUNC_IMPL(__imp__sub_82488724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82488728"))) PPC_WEAK_FUNC(sub_82488728);
PPC_FUNC_IMPL(__imp__sub_82488728) {
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
	ctx.lr = 0x82488730;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82481c00
	ctx.lr = 0x82488744;
	sub_82481C00(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824889ac
	if (cr6.eq) goto loc_824889AC;
	// addi r3,r26,2264
	ctx.r3.s64 = r26.s64 + 2264;
	// bl 0x824e1160
	ctx.lr = 0x82488758;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488780
	if (cr6.eq) goto loc_82488780;
	// addi r3,r26,4408
	ctx.r3.s64 = r26.s64 + 4408;
	// bl 0x824f97c0
	ctx.lr = 0x82488770;
	sub_824F97C0(ctx, base);
	// ld r11,4496(r26)
	r11.u64 = PPC_LOAD_U64(r26.u32 + 4496);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82488784
	if (cr6.eq) goto loc_82488784;
loc_82488780:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82488784:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,264(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 264);
	// beq cr6,0x82488800
	if (cr6.eq) goto loc_82488800;
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824887d0
	if (!cr6.gt) goto loc_824887D0;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
loc_824887A4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824814f8
	ctx.lr = 0x824887B0;
	sub_824814F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824887bc
	if (cr6.eq) goto loc_824887BC;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_824887BC:
	// lwz r11,264(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 264);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x824887a4
	if (cr6.lt) goto loc_824887A4;
loc_824887D0:
	// lwz r6,264(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 264);
	// cmplw cr6,r6,r28
	cr6.compare<uint32_t>(ctx.r6.u32, r28.u32, xer);
	// bne cr6,0x824889ac
	if (!cr6.eq) goto loc_824889AC;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r29,8
	ctx.r5.s64 = r29.s64 + 8;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82487da0
	ctx.lr = 0x824887F8;
	sub_82487DA0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
loc_82488800:
	// mr r27,r28
	r27.u64 = r28.u64;
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82488854
	if (!cr6.gt) goto loc_82488854;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
loc_82488814:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82481af0
	ctx.lr = 0x82488820;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82488838
	if (cr6.eq) goto loc_82488838;
	// bl 0x824e7008
	ctx.lr = 0x8248882C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488850
	if (!cr6.eq) goto loc_82488850;
loc_82488838:
	// lwz r11,264(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 264);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82488814
	if (cr6.lt) goto loc_82488814;
	// b 0x82488854
	goto loc_82488854;
loc_82488850:
	// li r27,1
	r27.s64 = 1;
loc_82488854:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488914
	if (cr6.eq) goto loc_82488914;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r31,31
	r31.s64 = 31;
loc_82488868:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x82488870;
	sub_824F0498(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x82488868
	if (!cr0.lt) goto loc_82488868;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82481830
	ctx.lr = 0x8248888C;
	sub_82481830(ctx, base);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824889ac
	if (!cr6.gt) goto loc_824889AC;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_824888A4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82481af0
	ctx.lr = 0x824888B0;
	sub_82481AF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824888d8
	if (cr6.eq) goto loc_824888D8;
	// bl 0x824e7060
	ctx.lr = 0x824888BC;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824888d8
	if (cr6.eq) goto loc_824888D8;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// std r11,0(r30)
	PPC_STORE_U64(r30.u32 + 0, r11.u64);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
loc_824888D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x824888a4
	if (!cr0.eq) goto loc_824888A4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824889ac
	if (cr6.eq) goto loc_824889AC;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82487da0
	ctx.lr = 0x8248890C;
	sub_82487DA0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
loc_82488914:
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,312
	ctx.r4.s64 = 312;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82488934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824889ac
	if (cr6.eq) goto loc_824889AC;
	// bl 0x824cac78
	ctx.lr = 0x82488944;
	sub_824CAC78(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r25,8
	ctx.r3.s64 = r25.s64 + 8;
	// addi r10,r11,-8392
	ctx.r10.s64 = r11.s64 + -8392;
	// addi r30,r31,304
	r30.s64 = r31.s64 + 304;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r28,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r28.u32);
	// stw r28,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r28.u32);
	// bl 0x824f97c0
	ctx.lr = 0x82488964;
	sub_824F97C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r7,264(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 264);
	// addi r6,r29,8
	ctx.r6.s64 = r29.s64 + 8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c7740
	ctx.lr = 0x82488980;
	sub_824C7740(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824889a0
	if (cr6.eq) goto loc_824889A0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82485980
	ctx.lr = 0x82488998;
	sub_82485980(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
loc_824889A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x824889AC;
	sub_824E1948(ctx, base);
loc_824889AC:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824889B4"))) PPC_WEAK_FUNC(sub_824889B4);
PPC_FUNC_IMPL(__imp__sub_824889B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824889B8"))) PPC_WEAK_FUNC(sub_824889B8);
PPC_FUNC_IMPL(__imp__sub_824889B8) {
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
	ctx.lr = 0x824889C0;
	// stwu r1,-1408(r1)
	ea = -1408 + ctx.r1.u32;
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
	ctx.lr = 0x824889E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82488a84
	if (cr6.eq) goto loc_82488A84;
	// cmplwi cr6,r29,4
	cr6.compare<uint32_t>(r29.u32, 4, xer);
	// beq cr6,0x82488a84
	if (cr6.eq) goto loc_82488A84;
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// beq cr6,0x82488c90
	if (cr6.eq) goto loc_82488C90;
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// beq cr6,0x82488a0c
	if (cr6.eq) goto loc_82488A0C;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// bne cr6,0x82488c90
	if (!cr6.eq) goto loc_82488C90;
loc_82488A0C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82481c00
	ctx.lr = 0x82488A18;
	sub_82481C00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82488c90
	if (cr6.eq) goto loc_82488C90;
	// addi r3,r30,2264
	ctx.r3.s64 = r30.s64 + 2264;
	// bl 0x824e1160
	ctx.lr = 0x82488A2C;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488a70
	if (cr6.eq) goto loc_82488A70;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481688
	ctx.lr = 0x82488A40;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488a70
	if (cr6.eq) goto loc_82488A70;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824f97c0
	ctx.lr = 0x82488A54;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x824885c0
	ctx.lr = 0x82488A68;
	sub_824885C0(ctx, base);
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9244
	return;
loc_82488A70:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824876e0
	ctx.lr = 0x82488A7C;
	sub_824876E0(ctx, base);
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9244
	return;
loc_82488A84:
	// addi r27,r30,2264
	r27.s64 = r30.s64 + 2264;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e1160
	ctx.lr = 0x82488A90;
	sub_824E1160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488c90
	if (cr6.eq) goto loc_82488C90;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481688
	ctx.lr = 0x82488AA4;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488c90
	if (cr6.eq) goto loc_82488C90;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x82481c58
	ctx.lr = 0x82488AB8;
	sub_82481C58(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r9,r11,22476
	ctx.r9.s64 = r11.s64 + 22476;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// lwz r6,40(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r5,44(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bne cr6,0x82488af0
	if (!cr6.eq) goto loc_82488AF0;
	// bl 0x82484458
	ctx.lr = 0x82488AE4;
	sub_82484458(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r28,r11,48
	r28.s64 = r11.s64 + 48;
	// b 0x82488afc
	goto loc_82488AFC;
loc_82488AF0:
	// bl 0x82484458
	ctx.lr = 0x82488AF4;
	sub_82484458(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r28,r11,52
	r28.s64 = r11.s64 + 52;
loc_82488AFC:
	// addi r31,r11,32
	r31.s64 = r11.s64 + 32;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82488c90
	if (cr6.eq) goto loc_82488C90;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0e80
	ctx.lr = 0x82488B14;
	sub_824E0E80(ctx, base);
	// ld r11,736(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 736);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// bne cr6,0x82488c90
	if (!cr6.eq) goto loc_82488C90;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0ec8
	ctx.lr = 0x82488B2C;
	sub_824E0EC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0f28
	ctx.lr = 0x82488B38;
	sub_824E0F28(ctx, base);
	// lwz r11,11528(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11528);
	// subf. r10,r11,r29
	ctx.r10.s64 = r29.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82488b94
	if (!cr0.eq) goto loc_82488B94;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0ec8
	ctx.lr = 0x82488B50;
	sub_824E0EC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0f28
	ctx.lr = 0x82488B5C;
	sub_824E0F28(ctx, base);
	// lwz r11,11528(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11528);
	// lwz r10,8308(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8308);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// subf r11,r29,r9
	r11.s64 = ctx.r9.s64 - r29.s64;
	// add. r8,r11,r3
	ctx.r8.u64 = r11.u64 + ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x82488b94
	if (!cr0.eq) goto loc_82488B94;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82486cd8
	ctx.lr = 0x82488B8C;
	sub_82486CD8(ctx, base);
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9244
	return;
loc_82488B94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82483998
	ctx.lr = 0x82488B9C;
	sub_82483998(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488bc8
	if (!cr6.eq) goto loc_82488BC8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82486cd8
	ctx.lr = 0x82488BC0;
	sub_82486CD8(ctx, base);
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9244
	return;
loc_82488BC8:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// li r29,0
	r29.s64 = 0;
	// addi r8,r10,-8240
	ctx.r8.s64 = ctx.r10.s64 + -8240;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r4,r1,744
	ctx.r4.s64 = ctx.r1.s64 + 744;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x823da950
	ctx.lr = 0x82488C04;
	sub_823DA950(ctx, base);
	// ld r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// lwz r6,840(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 840);
	// addi r10,r1,848
	ctx.r10.s64 = ctx.r1.s64 + 848;
	// lwz r11,844(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 844);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r29,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, r29.u32);
	// addi r3,r30,11532
	ctx.r3.s64 = r30.s64 + 11532;
	// std r9,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r9.u64);
	// stw r6,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r6.u32);
	// stw r11,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r11.u32);
	// stb r29,728(r1)
	PPC_STORE_U8(ctx.r1.u32 + 728, r29.u8);
	// bl 0x824e7db8
	ctx.lr = 0x82488C3C;
	sub_824E7DB8(ctx, base);
	// lbz r7,728(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 728);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82488c6c
	if (cr6.eq) goto loc_82488C6C;
	// addi r7,r1,212
	ctx.r7.s64 = ctx.r1.s64 + 212;
	// lwz r8,724(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lhz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82487918
	ctx.lr = 0x82488C64;
	sub_82487918(ctx, base);
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9244
	return;
loc_82488C6C:
	// lwz r7,724(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// addi r6,r1,212
	ctx.r6.s64 = ctx.r1.s64 + 212;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82488c80
	if (!cr6.eq) goto loc_82488C80;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
loc_82488C80:
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82486cd8
	ctx.lr = 0x82488C90;
	sub_82486CD8(ctx, base);
loc_82488C90:
	// addi r1,r1,1408
	ctx.r1.s64 = ctx.r1.s64 + 1408;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82488C98"))) PPC_WEAK_FUNC(sub_82488C98);
PPC_FUNC_IMPL(__imp__sub_82488C98) {
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
	ctx.lr = 0x82488CA0;
	// stwu r1,-2544(r1)
	ea = -2544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r5,24(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r4,20(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// bl 0x82257678
	ctx.lr = 0x82488CC0;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r9,r10,22348
	ctx.r9.s64 = ctx.r10.s64 + 22348;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82488d9c
	if (!cr6.eq) goto loc_82488D9C;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// std r30,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r30.u64);
	// bl 0x8252ad00
	ctx.lr = 0x82488CF0;
	sub_8252AD00(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82484ab0
	ctx.lr = 0x82488D00;
	sub_82484AB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252a6e8
	ctx.lr = 0x82488D14;
	sub_8252A6E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248941c
	if (!cr6.eq) goto loc_8248941C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82488D40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// bl 0x824cb0b0
	ctx.lr = 0x82488D50;
	sub_824CB0B0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r7,r29,72
	ctx.r7.s64 = r29.s64 + 72;
	// addi r10,r11,-8144
	ctx.r10.s64 = r11.s64 + -8144;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stw r30,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r30,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824c8450
	ctx.lr = 0x82488D7C;
	sub_824C8450(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824893fc
	if (!cr6.eq) goto loc_824893FC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x82488D94;
	sub_824E1948(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82488D9C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,32364
	ctx.r9.s64 = ctx.r10.s64 + 32364;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82488dec
	if (!cr6.eq) goto loc_82488DEC;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x824e6400
	ctx.lr = 0x82488DB8;
	sub_824E6400(ctx, base);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82483b70
	ctx.lr = 0x82488DC8;
	sub_82483B70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824840a0
	ctx.lr = 0x82488DE4;
	sub_824840A0(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82488DEC:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22380
	ctx.r9.s64 = ctx.r10.s64 + 22380;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82488ea0
	if (!cr6.eq) goto loc_82488EA0;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x824e6400
	ctx.lr = 0x82488E08;
	sub_824E6400(ctx, base);
	// addi r5,r1,400
	ctx.r5.s64 = ctx.r1.s64 + 400;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82483c00
	ctx.lr = 0x82488E18;
	sub_82483C00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x824f99c0
	ctx.lr = 0x82488E2C;
	sub_824F99C0(ctx, base);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x824f9970
	ctx.lr = 0x82488E34;
	sub_824F9970(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x824f99c0
	ctx.lr = 0x82488E48;
	sub_824F99C0(ctx, base);
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// bl 0x824e1c10
	ctx.lr = 0x82488E50;
	sub_824E1C10(ctx, base);
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// bl 0x824e0dc0
	ctx.lr = 0x82488E58;
	sub_824E0DC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r10,r1,736
	ctx.r10.s64 = ctx.r1.s64 + 736;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82488E6C:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82488e6c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82488E6C;
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// bl 0x82214f50
	ctx.lr = 0x82488E88;
	sub_82214F50(ctx, base);
	// addi r5,r1,736
	ctx.r5.s64 = ctx.r1.s64 + 736;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82484130
	ctx.lr = 0x82488E98;
	sub_82484130(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82488EA0:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22156
	ctx.r9.s64 = ctx.r10.s64 + 22156;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82488fe4
	if (!cr6.eq) goto loc_82488FE4;
	// addi r3,r1,1872
	ctx.r3.s64 = ctx.r1.s64 + 1872;
	// bl 0x82481a98
	ctx.lr = 0x82488EBC;
	sub_82481A98(ctx, base);
	// addi r5,r1,1872
	ctx.r5.s64 = ctx.r1.s64 + 1872;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824857f0
	ctx.lr = 0x82488ECC;
	sub_824857F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,840
	ctx.r4.s64 = 840;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82488EF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// bl 0x824ca8b0
	ctx.lr = 0x82488F08;
	sub_824CA8B0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-8348
	ctx.r10.s64 = r11.s64 + -8348;
	// addi r6,r29,832
	ctx.r6.s64 = r29.s64 + 832;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// addi r5,r1,1872
	ctx.r5.s64 = ctx.r1.s64 + 1872;
	// stw r30,832(r29)
	PPC_STORE_U32(r29.u32 + 832, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r30,836(r29)
	PPC_STORE_U32(r29.u32 + 836, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824cd2b8
	ctx.lr = 0x82488F34;
	sub_824CD2B8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82488fd0
	if (cr6.eq) goto loc_82488FD0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485980
	ctx.lr = 0x82488F4C;
	sub_82485980(ctx, base);
	// lwz r11,11572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82488fb0
	if (!cr6.eq) goto loc_82488FB0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,5856
	ctx.r4.s64 = 5856;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82488F78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82488fb0
	if (cr6.eq) goto loc_82488FB0;
	// bl 0x824cd610
	ctx.lr = 0x82488F88;
	sub_824CD610(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r5,r29,5848
	ctx.r5.s64 = r29.s64 + 5848;
	// addi r10,r11,-8324
	ctx.r10.s64 = r11.s64 + -8324;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,5848(r29)
	PPC_STORE_U32(r29.u32 + 5848, r30.u32);
	// stw r30,5852(r29)
	PPC_STORE_U32(r29.u32 + 5852, r30.u32);
	// bl 0x824c71c8
	ctx.lr = 0x82488FAC;
	sub_824C71C8(ctx, base);
	// stw r29,11572(r31)
	PPC_STORE_U32(r31.u32 + 11572, r29.u32);
loc_82488FB0:
	// lwz r3,11572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 11572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r4,r1,1880
	ctx.r4.s64 = ctx.r1.s64 + 1880;
	// lwz r5,1976(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1976);
	// bl 0x824c5fc8
	ctx.lr = 0x82488FC8;
	sub_824C5FC8(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82488FD0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x82488FDC;
	sub_824E1948(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82488FE4:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22316
	ctx.r9.s64 = ctx.r10.s64 + 22316;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82489050
	if (!cr6.eq) goto loc_82489050;
	// li r11,0
	r11.s64 = 0;
	// addi r29,r1,472
	r29.s64 = ctx.r1.s64 + 472;
	// std r11,464(r1)
	PPC_STORE_U64(ctx.r1.u32 + 464, r11.u64);
	// li r30,31
	r30.s64 = 31;
loc_82489008:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x82489010;
	sub_824F0498(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bge 0x82489008
	if (!cr0.lt) goto loc_82489008;
	// addi r5,r1,464
	ctx.r5.s64 = ctx.r1.s64 + 464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82484b78
	ctx.lr = 0x8248902C;
	sub_82484B78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r5,r1,464
	ctx.r5.s64 = ctx.r1.s64 + 464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82488728
	ctx.lr = 0x82489048;
	sub_82488728(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82489050:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22028
	ctx.r9.s64 = ctx.r10.s64 + 22028;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82489138
	if (!cr6.eq) goto loc_82489138;
	// li r30,0
	r30.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// std r30,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, r30.u64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82484c50
	ctx.lr = 0x8248907C;
	sub_82484C50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8252a6e8
	ctx.lr = 0x82489094;
	sub_8252A6E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248941c
	if (!cr6.eq) goto loc_8248941C;
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// bl 0x824e0e40
	ctx.lr = 0x824890A8;
	sub_824E0E40(ctx, base);
	// bl 0x82502300
	ctx.lr = 0x824890AC;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8252b030
	ctx.lr = 0x824890B8;
	sub_8252B030(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2520
	ctx.r4.s64 = 2520;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824890E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// bl 0x824ce3e0
	ctx.lr = 0x824890F4;
	sub_824CE3E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r5,r29,2512
	ctx.r5.s64 = r29.s64 + 2512;
	// addi r10,r11,-8092
	ctx.r10.s64 = r11.s64 + -8092;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,2512(r29)
	PPC_STORE_U32(r29.u32 + 2512, r30.u32);
	// stw r30,2516(r29)
	PPC_STORE_U32(r29.u32 + 2516, r30.u32);
	// bl 0x824c8758
	ctx.lr = 0x82489118;
	sub_824C8758(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824893fc
	if (!cr6.eq) goto loc_824893FC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x82489130;
	sub_824E1948(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82489138:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22252
	ctx.r9.s64 = ctx.r10.s64 + 22252;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824891e4
	if (!cr6.eq) goto loc_824891E4;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// std r11,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, r11.u64);
	// bl 0x824f0498
	ctx.lr = 0x8248915C;
	sub_824F0498(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82484d28
	ctx.lr = 0x8248916C;
	sub_82484D28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8252ad10
	ctx.lr = 0x82489180;
	sub_8252AD10(ctx, base);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82481140
	ctx.lr = 0x82489188;
	sub_82481140(ctx, base);
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// bl 0x824e0e80
	ctx.lr = 0x82489190;
	sub_824E0E80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252af40
	ctx.lr = 0x824891A0;
	sub_8252AF40(ctx, base);
	// std r29,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, r29.u64);
	// addi r10,r1,184
	ctx.r10.s64 = ctx.r1.s64 + 184;
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824891B4:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824891b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824891B4;
	// stb r3,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, ctx.r3.u8);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82485148
	ctx.lr = 0x824891DC;
	sub_82485148(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_824891E4:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22444
	ctx.r9.s64 = ctx.r10.s64 + 22444;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8248929c
	if (!cr6.eq) goto loc_8248929C;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r1,1352
	ctx.r3.s64 = ctx.r1.s64 + 1352;
	// std r30,1344(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1344, r30.u64);
	// bl 0x824e8de8
	ctx.lr = 0x82489208;
	sub_824E8DE8(ctx, base);
	// addi r5,r1,1344
	ctx.r5.s64 = ctx.r1.s64 + 1344;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82484dc8
	ctx.lr = 0x82489218;
	sub_82484DC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,560
	ctx.r4.s64 = 560;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82489244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// bl 0x824cb300
	ctx.lr = 0x82489254;
	sub_824CB300(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r6,r29,552
	ctx.r6.s64 = r29.s64 + 552;
	// addi r10,r11,-8048
	ctx.r10.s64 = r11.s64 + -8048;
	// addi r5,r1,1352
	ctx.r5.s64 = ctx.r1.s64 + 1352;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r30,552(r29)
	PPC_STORE_U32(r29.u32 + 552, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,556(r29)
	PPC_STORE_U32(r29.u32 + 556, r30.u32);
	// bl 0x824c8d38
	ctx.lr = 0x8248927C;
	sub_824C8D38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824893fc
	if (!cr6.eq) goto loc_824893FC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x82489294;
	sub_824E1948(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_8248929C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22284
	ctx.r9.s64 = ctx.r10.s64 + 22284;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82489350
	if (!cr6.eq) goto loc_82489350;
	// li r30,0
	r30.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// std r30,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r30.u64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r30,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82484e90
	ctx.lr = 0x824892CC;
	sub_82484E90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,48
	ctx.r4.s64 = 48;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824892F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// bl 0x824cb458
	ctx.lr = 0x82489308;
	sub_824CB458(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r6,r29,40
	ctx.r6.s64 = r29.s64 + 40;
	// addi r10,r11,-8000
	ctx.r10.s64 = r11.s64 + -8000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,40(r29)
	PPC_STORE_U32(r29.u32 + 40, r30.u32);
	// stw r30,44(r29)
	PPC_STORE_U32(r29.u32 + 44, r30.u32);
	// lbz r5,120(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 120);
	// bl 0x824c9310
	ctx.lr = 0x82489330;
	sub_824C9310(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824893fc
	if (!cr6.eq) goto loc_824893FC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x82489348;
	sub_824E1948(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82489350:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,22220
	ctx.r9.s64 = ctx.r10.s64 + 22220;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8248941c
	if (!cr6.eq) goto loc_8248941C;
	// li r11,-1
	r11.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// std r30,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r30.u64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824858b8
	ctx.lr = 0x82489388;
	sub_824858B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,56
	ctx.r4.s64 = 56;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824893B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248941c
	if (cr6.eq) goto loc_8248941C;
	// bl 0x824cb4a8
	ctx.lr = 0x824893C4;
	sub_824CB4A8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r7,r29,48
	ctx.r7.s64 = r29.s64 + 48;
	// addi r10,r11,-7956
	ctx.r10.s64 = r11.s64 + -7956;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r30.u32);
	// stw r30,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r30.u32);
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x824c9470
	ctx.lr = 0x824893F0;
	sub_824C9470(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82489410
	if (cr6.eq) goto loc_82489410;
loc_824893FC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82485980
	ctx.lr = 0x82489408;
	sub_82485980(ctx, base);
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
loc_82489410:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e1948
	ctx.lr = 0x8248941C;
	sub_824E1948(ctx, base);
loc_8248941C:
	// addi r1,r1,2544
	ctx.r1.s64 = ctx.r1.s64 + 2544;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82489424"))) PPC_WEAK_FUNC(sub_82489424);
PPC_FUNC_IMPL(__imp__sub_82489424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489428"))) PPC_WEAK_FUNC(sub_82489428);
PPC_FUNC_IMPL(__imp__sub_82489428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82489430;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r31,8
	r26.s64 = r31.s64 + 8;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// bl 0x824ebf78
	ctx.lr = 0x82489450;
	sub_824EBF78(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252cf08
	ctx.lr = 0x82489458;
	sub_8252CF08(ctx, base);
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// bl 0x824e58a0
	ctx.lr = 0x82489460;
	sub_824E58A0(ctx, base);
	// li r27,-1
	r27.s64 = -1;
	// addi r29,r31,4400
	r29.s64 = r31.s64 + 4400;
	// stw r27,4400(r31)
	PPC_STORE_U32(r31.u32 + 4400, r27.u32);
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x824f99c0
	ctx.lr = 0x82489474;
	sub_824F99C0(ctx, base);
	// addi r3,r29,56
	ctx.r3.s64 = r29.s64 + 56;
	// bl 0x824e6310
	ctx.lr = 0x8248947C;
	sub_824E6310(ctx, base);
	// stw r30,4480(r31)
	PPC_STORE_U32(r31.u32 + 4480, r30.u32);
	// stw r30,4484(r31)
	PPC_STORE_U32(r31.u32 + 4484, r30.u32);
	// addi r25,r31,4504
	r25.s64 = r31.s64 + 4504;
	// stw r30,4488(r31)
	PPC_STORE_U32(r31.u32 + 4488, r30.u32);
	// lbz r11,4492(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4492);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,4492(r31)
	PPC_STORE_U8(r31.u32 + 4492, ctx.r10.u8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// std r27,4496(r31)
	PPC_STORE_U64(r31.u32 + 4496, r27.u64);
	// bl 0x8252e7a8
	ctx.lr = 0x824894A4;
	sub_8252E7A8(ctx, base);
	// addi r3,r31,4552
	ctx.r3.s64 = r31.s64 + 4552;
	// bl 0x8252f070
	ctx.lr = 0x824894AC;
	sub_8252F070(ctx, base);
	// addi r29,r31,4584
	r29.s64 = r31.s64 + 4584;
	// li r28,31
	r28.s64 = 31;
loc_824894B4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824894BC;
	sub_824E71C8(ctx, base);
	// stw r30,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r30.u32);
	// stw r30,104(r29)
	PPC_STORE_U32(r29.u32 + 104, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6f20
	ctx.lr = 0x824894CC;
	sub_824E6F20(ctx, base);
	// lbz r11,108(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 108);
	// stw r27,96(r29)
	PPC_STORE_U32(r29.u32 + 96, r27.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,108(r29)
	PPC_STORE_U8(r29.u32 + 108, ctx.r10.u8);
	// addi r29,r29,112
	r29.s64 = r29.s64 + 112;
	// bge 0x824894b4
	if (!cr0.lt) goto loc_824894B4;
	// stw r30,8168(r31)
	PPC_STORE_U32(r31.u32 + 8168, r30.u32);
	// addi r29,r31,8312
	r29.s64 = r31.s64 + 8312;
	// stw r30,8172(r31)
	PPC_STORE_U32(r31.u32 + 8172, r30.u32);
	// li r28,31
	r28.s64 = 31;
	// stw r30,8176(r31)
	PPC_STORE_U32(r31.u32 + 8176, r30.u32);
	// stw r30,8308(r31)
	PPC_STORE_U32(r31.u32 + 8308, r30.u32);
loc_82489500:
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x824f99c0
	ctx.lr = 0x8248950C;
	sub_824F99C0(ctx, base);
	// addi r3,r29,56
	ctx.r3.s64 = r29.s64 + 56;
	// bl 0x824e6310
	ctx.lr = 0x82489514;
	sub_824E6310(ctx, base);
	// stw r30,80(r29)
	PPC_STORE_U32(r29.u32 + 80, r30.u32);
	// stw r30,84(r29)
	PPC_STORE_U32(r29.u32 + 84, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r30,88(r29)
	PPC_STORE_U32(r29.u32 + 88, r30.u32);
	// lbz r11,92(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 92);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,92(r29)
	PPC_STORE_U8(r29.u32 + 92, ctx.r10.u8);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bge 0x82489500
	if (!cr0.lt) goto loc_82489500;
	// stw r30,11384(r31)
	PPC_STORE_U32(r31.u32 + 11384, r30.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r30,11388(r31)
	PPC_STORE_U32(r31.u32 + 11388, r30.u32);
	// addi r3,r31,11592
	ctx.r3.s64 = r31.s64 + 11592;
	// stw r30,11392(r31)
	PPC_STORE_U32(r31.u32 + 11392, r30.u32);
	// stw r30,11524(r31)
	PPC_STORE_U32(r31.u32 + 11524, r30.u32);
	// stw r30,11528(r31)
	PPC_STORE_U32(r31.u32 + 11528, r30.u32);
	// stw r30,11532(r31)
	PPC_STORE_U32(r31.u32 + 11532, r30.u32);
	// stw r30,11536(r31)
	PPC_STORE_U32(r31.u32 + 11536, r30.u32);
	// stw r30,11540(r31)
	PPC_STORE_U32(r31.u32 + 11540, r30.u32);
	// stw r30,11544(r31)
	PPC_STORE_U32(r31.u32 + 11544, r30.u32);
	// stw r30,11548(r31)
	PPC_STORE_U32(r31.u32 + 11548, r30.u32);
	// stw r30,11552(r31)
	PPC_STORE_U32(r31.u32 + 11552, r30.u32);
	// stw r30,11556(r31)
	PPC_STORE_U32(r31.u32 + 11556, r30.u32);
	// stw r30,11560(r31)
	PPC_STORE_U32(r31.u32 + 11560, r30.u32);
	// stw r30,11564(r31)
	PPC_STORE_U32(r31.u32 + 11564, r30.u32);
	// stw r30,11568(r31)
	PPC_STORE_U32(r31.u32 + 11568, r30.u32);
	// stw r30,11572(r31)
	PPC_STORE_U32(r31.u32 + 11572, r30.u32);
	// stw r30,11576(r31)
	PPC_STORE_U32(r31.u32 + 11576, r30.u32);
	// stw r11,11580(r31)
	PPC_STORE_U32(r31.u32 + 11580, r11.u32);
	// stw r30,11584(r31)
	PPC_STORE_U32(r31.u32 + 11584, r30.u32);
	// stw r30,11588(r31)
	PPC_STORE_U32(r31.u32 + 11588, r30.u32);
	// bl 0x8252f8a8
	ctx.lr = 0x82489594;
	sub_8252F8A8(ctx, base);
	// lbz r10,11608(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 11608);
	// li r5,128
	ctx.r5.s64 = 128;
	// clrlwi r9,r10,28
	ctx.r9.u64 = ctx.r10.u32 & 0xF;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r9,11608(r31)
	PPC_STORE_U8(r31.u32 + 11608, ctx.r9.u8);
	// addi r3,r31,8180
	ctx.r3.s64 = r31.s64 + 8180;
	// bl 0x8244d150
	ctx.lr = 0x824895B0;
	sub_8244D150(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,11396
	ctx.r3.s64 = r31.s64 + 11396;
	// bl 0x8244d150
	ctx.lr = 0x824895C0;
	sub_8244D150(ctx, base);
	// lis r8,-32183
	ctx.r8.s64 = -2109145088;
	// stw r30,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-29544
	ctx.r7.s64 = ctx.r8.s64 + -29544;
	// stw r7,4(r25)
	PPC_STORE_U32(r25.u32 + 4, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x824895D8;
	sub_82130000(ctx, base);
	// lis r6,-32183
	ctx.r6.s64 = -2109145088;
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-30280
	ctx.r5.s64 = ctx.r6.s64 + -30280;
	// stw r30,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r30.u32);
	// stw r5,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x824895F4;
	sub_82130000(ctx, base);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82489604"))) PPC_WEAK_FUNC(sub_82489604);
PPC_FUNC_IMPL(__imp__sub_82489604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489608"))) PPC_WEAK_FUNC(sub_82489608);
PPC_FUNC_IMPL(__imp__sub_82489608) {
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
	ctx.lr = 0x82489610;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82488320
	ctx.lr = 0x8248961C;
	sub_82488320(ctx, base);
	// addi r3,r31,11592
	ctx.r3.s64 = r31.s64 + 11592;
	// bl 0x8252f8c8
	ctx.lr = 0x82489624;
	sub_8252F8C8(ctx, base);
	// addi r3,r31,11560
	ctx.r3.s64 = r31.s64 + 11560;
	// bl 0x82483d80
	ctx.lr = 0x8248962C;
	sub_82483D80(ctx, base);
	// addi r3,r31,11548
	ctx.r3.s64 = r31.s64 + 11548;
	// bl 0x82483d80
	ctx.lr = 0x82489634;
	sub_82483D80(ctx, base);
	// addi r30,r31,11532
	r30.s64 = r31.s64 + 11532;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7d20
	ctx.lr = 0x82489640;
	sub_824E7D20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7cc8
	ctx.lr = 0x82489648;
	sub_824E7CC8(ctx, base);
	// addi r3,r31,11384
	ctx.r3.s64 = r31.s64 + 11384;
	// bl 0x82483d28
	ctx.lr = 0x82489650;
	sub_82483D28(ctx, base);
	// addi r30,r31,11384
	r30.s64 = r31.s64 + 11384;
	// li r29,31
	r29.s64 = 31;
	// li r27,-1
	r27.s64 = -1;
loc_8248965C:
	// addi r30,r30,-96
	r30.s64 = r30.s64 + -96;
	// addi r28,r30,56
	r28.s64 = r30.s64 + 56;
	// addi r3,r28,-48
	ctx.r3.s64 = r28.s64 + -48;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// bl 0x824f9788
	ctx.lr = 0x82489670;
	sub_824F9788(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e6310
	ctx.lr = 0x82489678;
	sub_824E6310(ctx, base);
	// lbz r11,92(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 92);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,92(r30)
	PPC_STORE_U8(r30.u32 + 92, ctx.r10.u8);
	// bge 0x8248965c
	if (!cr0.lt) goto loc_8248965C;
	// addi r3,r31,8168
	ctx.r3.s64 = r31.s64 + 8168;
	// bl 0x82483cd0
	ctx.lr = 0x82489694;
	sub_82483CD0(ctx, base);
	// addi r3,r31,4552
	ctx.r3.s64 = r31.s64 + 4552;
	// bl 0x8252f098
	ctx.lr = 0x8248969C;
	sub_8252F098(ctx, base);
	// addi r3,r31,4504
	ctx.r3.s64 = r31.s64 + 4504;
	// bl 0x8252e818
	ctx.lr = 0x824896A4;
	sub_8252E818(ctx, base);
	// stw r27,4400(r31)
	PPC_STORE_U32(r31.u32 + 4400, r27.u32);
	// addi r30,r31,4400
	r30.s64 = r31.s64 + 4400;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x824f9788
	ctx.lr = 0x824896B4;
	sub_824F9788(ctx, base);
	// addi r3,r30,56
	ctx.r3.s64 = r30.s64 + 56;
	// bl 0x824e6310
	ctx.lr = 0x824896BC;
	sub_824E6310(ctx, base);
	// lbz r11,4492(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4492);
	// addi r3,r31,2264
	ctx.r3.s64 = r31.s64 + 2264;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,4492(r31)
	PPC_STORE_U8(r31.u32 + 4492, ctx.r10.u8);
	// bl 0x824e5ed8
	ctx.lr = 0x824896D0;
	sub_824E5ED8(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x8252d7b0
	ctx.lr = 0x824896D8;
	sub_8252D7B0(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82130000
	ctx.lr = 0x824896E0;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824896E8"))) PPC_WEAK_FUNC(sub_824896E8);
PPC_FUNC_IMPL(__imp__sub_824896E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248971c
	if (cr6.eq) goto loc_8248971C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x82489710;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82489720
	if (!cr6.eq) goto loc_82489720;
loc_8248971C:
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
loc_82489720:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82489734"))) PPC_WEAK_FUNC(sub_82489734);
PPC_FUNC_IMPL(__imp__sub_82489734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489738"))) PPC_WEAK_FUNC(sub_82489738);
PPC_FUNC_IMPL(__imp__sub_82489738) {
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
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,160(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x82489764
	if (!cr6.eq) goto loc_82489764;
	// lhz r3,170(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 170);
	// blr 
	return;
loc_82489764:
	// lhz r3,168(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 168);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248976C"))) PPC_WEAK_FUNC(sub_8248976C);
PPC_FUNC_IMPL(__imp__sub_8248976C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489770"))) PPC_WEAK_FUNC(sub_82489770);
PPC_FUNC_IMPL(__imp__sub_82489770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// vspltw128 v50,v57,3
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x0));
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// vmsum3fp128 v58,v60,v60
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v54,v55,v55
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vor128 v53,v55,v55
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// vor128 v56,v60,v60
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vmrghw128 v52,v61,v53
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// li r7,48
	ctx.r7.s64 = 48;
	// vmrglw128 v51,v61,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// addi r6,r8,2384
	ctx.r6.s64 = ctx.r8.s64 + 2384;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v12,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r5,2352
	r11.s64 = ctx.r5.s64 + 2352;
	// lvx128 v49,r4,r7
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v56,v49
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vand128 v46,v57,v13
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// vmrglw128 v45,v56,v49
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaxfp128 v47,v59,v58
	simde_mm_store_ps(v47.f32, simde_mm_max_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vmrglw128 v44,v52,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vor128 v43,v63,v46
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v46.u8)));
	// vmrghw128 v42,v52,v48
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v41,v51,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmsum4fp128 v40,v43,v44
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v39,v43,v41
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v41.f32), 0xFF));
	// vmsum4fp128 v38,v43,v42
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v42.f32), 0xFF));
	// vmaxfp128 v37,v47,v54
	simde_mm_store_ps(v37.f32, simde_mm_max_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v54.f32)));
	// vmrghw128 v35,v40,v43
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v34,v38,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vrsqrtefp128 v36,v37
	simde_mm_store_ps(v36.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v37.f32))));
	// vor128 v11,v37,v37
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v37.u8));
	// vmrghw128 v10,v34,v35
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vcmpeqfp128 v9,v36,v62
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v8,v36,v36
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v61,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v11,v7,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v33,v37,v4
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vmulfp128 v3,v50,v33
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v33.f32)));
	// vsel v2,v3,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// stvx128 v2,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248986C"))) PPC_WEAK_FUNC(sub_8248986C);
PPC_FUNC_IMPL(__imp__sub_8248986C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489870"))) PPC_WEAK_FUNC(sub_82489870);
PPC_FUNC_IMPL(__imp__sub_82489870) {
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
	ctx.lr = 0x82489878;
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x824773c0
	ctx.lr = 0x8248989C;
	sub_824773C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824898d0
	if (cr6.eq) goto loc_824898D0;
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r29,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r29.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824898C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// b 0x823d924c
	return;
loc_824898D0:
	// lwz r10,248(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 248);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824898DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824898E8"))) PPC_WEAK_FUNC(sub_824898E8);
PPC_FUNC_IMPL(__imp__sub_824898E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f8,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// beq cr6,0x824899fc
	if (cr6.eq) goto loc_824899FC;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r11,2384
	ctx.r9.s64 = r11.s64 + 2384;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// addi r11,r4,2352
	r11.s64 = ctx.r4.s64 + 2352;
	// lvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// vand128 v61,v62,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,-29232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v63,v63,v61
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// lfs f9,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f9.f64 = double(temp.f32);
	// li r11,16
	r11.s64 = 16;
loc_82489948:
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// lvx128 v60,r5,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r5,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v59,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v56,r5,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v59,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v54,v56,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v53,v56,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v52,v57,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v51,v55,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v50,v57,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmsum4fp128 v49,v63,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v48,v63,v51
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v47,v63,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v46,v49,v63
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v47,v48
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v44,v45,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// stvx128 v44,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-8(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	f0.f64 = double(temp.f32);
	// fmadds f7,f0,f0,f11
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f6,f12,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fsqrts f11,f6
	ctx.f11.f64 = double(float(sqrt(ctx.f6.f64)));
	// fmuls f0,f11,f1
	f0.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x824899c4
	if (!cr6.gt) goto loc_824899C4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_824899C4:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824899e4
	if (!cr6.eq) goto loc_824899E4;
	// fdivs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fadds f7,f11,f13
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// fmadds f6,f7,f10,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fmuls f0,f6,f0
	f0.f64 = double(float(ctx.f6.f64 * f0.f64));
loc_824899E4:
	// fcmpu cr6,f0,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f8.f64);
	// ble cr6,0x824899f0
	if (!cr6.gt) goto loc_824899F0;
	// fmr f8,f0
	ctx.f8.f64 = f0.f64;
loc_824899F0:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x82489948
	if (!cr0.eq) goto loc_82489948;
loc_824899FC:
	// lfs f0,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	f0.f64 = double(temp.f32);
	// fdivs f1,f8,f0
	ctx.f1.f64 = double(float(ctx.f8.f64 / f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489A08"))) PPC_WEAK_FUNC(sub_82489A08);
PPC_FUNC_IMPL(__imp__sub_82489A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,-12(r1)
	PPC_STORE_U16(ctx.r1.u32 + -12, ctx.r10.u16);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// ld r9,-16(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, ctx.r9.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489A24"))) PPC_WEAK_FUNC(sub_82489A24);
PPC_FUNC_IMPL(__imp__sub_82489A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489A28"))) PPC_WEAK_FUNC(sub_82489A28);
PPC_FUNC_IMPL(__imp__sub_82489A28) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f29.u64);
	// stfd f30,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r3,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821b9c70
	ctx.lr = 0x82489A8C;
	sub_821B9C70(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f31,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// bne cr6,0x82489ab8
	if (!cr6.eq) goto loc_82489AB8;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x82489ab8
	if (!cr6.eq) goto loc_82489AB8;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x82489ac0
	goto loc_82489AC0;
loc_82489AB8:
	// bl 0x823dcdd8
	ctx.lr = 0x82489ABC;
	sub_823DCDD8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
loc_82489AC0:
	// lfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dca68
	ctx.lr = 0x82489AC8;
	sub_823DCA68(ctx, base);
	// lfs f2,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f2.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// bne cr6,0x82489ae8
	if (!cr6.eq) goto loc_82489AE8;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x82489af0
	if (cr6.eq) goto loc_82489AF0;
loc_82489AE8:
	// bl 0x823dcdd8
	ctx.lr = 0x82489AEC;
	sub_823DCDD8(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
loc_82489AF0:
	// stfs f31,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f30,4(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f29,8(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-40(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489B1C"))) PPC_WEAK_FUNC(sub_82489B1C);
PPC_FUNC_IMPL(__imp__sub_82489B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489B20"))) PPC_WEAK_FUNC(sub_82489B20);
PPC_FUNC_IMPL(__imp__sub_82489B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister vTemp{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// vspltisw v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_set1_epi32(int(0x1)));
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,12512
	ctx.r9.s64 = r11.s64 + 12512;
	// vspltisw128 v61,3
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x3)));
	// addi r8,r10,12624
	ctx.r8.s64 = ctx.r10.s64 + 12624;
	// vspltisw128 v60,2
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x2)));
	// vcfux v12,v13,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v13.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// vslw128 v11,v62,v62
	ctx.v11.u32[0] = v62.u32[0] << (v62.u8[0] & 0x1F);
	ctx.v11.u32[1] = v62.u32[1] << (v62.u8[4] & 0x1F);
	ctx.v11.u32[2] = v62.u32[2] << (v62.u8[8] & 0x1F);
	ctx.v11.u32[3] = v62.u32[3] << (v62.u8[12] & 0x1F);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r7,12640
	ctx.r5.s64 = ctx.r7.s64 + 12640;
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// vmulfp128 v59,v1,v63
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v3,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// vcsxwfp128 v57,v62,0
	simde_mm_store_ps(v57.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// vupkd3d128 v58,v0,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// lvx128 v31,r0,r5
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r6,12672
	ctx.r9.s64 = ctx.r6.s64 + 12672;
	// addi r8,r4,12656
	ctx.r8.s64 = ctx.r4.s64 + 12656;
	// addi r7,r11,12704
	ctx.r7.s64 = r11.s64 + 12704;
	// addi r6,r10,12688
	ctx.r6.s64 = ctx.r10.s64 + 12688;
	// vspltw128 v10,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x0));
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lvx128 v9,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lvx128 v8,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r5,12720
	r11.s64 = ctx.r5.s64 + 12720;
	// lvx128 v7,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r4,12736
	ctx.r10.s64 = ctx.r4.s64 + 12736;
	// lvx128 v6,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,48
	ctx.r7.s64 = 48;
	// vor128 v30,v59,v59
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v5,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v29,v12,v30,v11
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)v30.u8))));
	// stvx128 v2,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v59,v29
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v29.f32)));
	// vcfpsxws128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.s32, simde_mm_vctsxs(simde_mm_load_ps(v56.f32)));
	// vcsxwfp128 v54,v55,0
	simde_mm_store_ps(v54.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vand128 v12,v55,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vadduwm v28,v13,v12
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// vand128 v53,v12,v13
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// vand128 v52,v12,v60
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vand128 v51,v28,v13
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// vcmpequw128 v27,v53,v0
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vand128 v50,v28,v60
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vcmpequw128 v26,v52,v0
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vor128 v25,v54,v54
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vor128 v24,v54,v54
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vcmpequw128 v22,v51,v0
	simde_mm_store_si128((simde__m128i*)v22.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vcmpequw128 v21,v50,v0
	simde_mm_store_si128((simde__m128i*)v21.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vnmsubfp v23,v25,v3,v1
	simde_mm_store_ps(v23.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v12,v24,v31,v23
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v24.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v23.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v13,v12,v12
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v20,v9,v13,v8
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v19,v7,v13,v6
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmulfp128 v18,v13,v12
	simde_mm_store_ps(v18.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v17,v20,v13,v5
	simde_mm_store_ps(v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v20.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v16,v19,v13,v4
	simde_mm_store_ps(v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v19.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v15,v17,v13,v10
	simde_mm_store_ps(v15.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v17.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmrghw128 v13,v10,v57
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vmaddfp v14,v16,v18,v12
	simde_mm_store_ps(v14.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v16.f32), simde_mm_load_ps(v18.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmrghw128 v49,v13,v13
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vsel v9,v15,v14,v27
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)v15.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)v14.u8))));
	// vsel v8,v15,v14,v22
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)v15.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)v14.u8))));
	// vxor v6,v11,v9
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vxor v4,v11,v8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)));
	// vsel v3,v6,v9,v26
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vsel v2,v4,v8,v21
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vspltw128 v48,v3,1
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), 0xAA));
	// vmrghw128 v47,v0,v3
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vspltw128 v46,v2,1
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), 0xAA));
	// vmrghw128 v45,v3,v2
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), simde_mm_load_si128((simde__m128i*)ctx.v3.u32)));
	// vmulfp128 v44,v2,v48
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v48.f32)));
	// vspltw128 v43,v3,2
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), 0x55));
	// vspltw128 v41,v2,2
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), 0x55));
	// vmulfp128 v42,v3,v48
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v48.f32)));
	// vmrghw128 v40,v47,v2
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmulfp128 v39,v45,v46
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	// vmulfp128 v1,v43,v49
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v49.f32)));
	// vmulfp128 v31,v41,v49
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v49.f32)));
	// vmulfp128 v30,v43,v40
	simde_mm_store_ps(v30.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v40.f32)));
	// vmulfp128 v29,v41,v40
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v40.f32)));
	// vmrghw128 v38,v46,v44
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vsldoi128 v28,v48,v39,12
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v39.u8), 4));
	// vmrghw128 v12,v38,v42
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmaddfp v27,v28,v13,v0
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v25,v12,v31,v30
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v30.f32)));
	// vnmsubfp v24,v1,v12,v29
	simde_mm_store_ps(v24.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(v29.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v27,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489CB4"))) PPC_WEAK_FUNC(sub_82489CB4);
PPC_FUNC_IMPL(__imp__sub_82489CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489CB8"))) PPC_WEAK_FUNC(sub_82489CB8);
PPC_FUNC_IMPL(__imp__sub_82489CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82489cd8
	if (!cr6.eq) goto loc_82489CD8;
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
loc_82489CD8:
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489CE8"))) PPC_WEAK_FUNC(sub_82489CE8);
PPC_FUNC_IMPL(__imp__sub_82489CE8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,-7164
	ctx.r9.s64 = r11.s64 + -7164;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r11,19620(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19620);
	// addi r3,r11,876
	ctx.r3.s64 = r11.s64 + 876;
	// lwz r8,888(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 888);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82489D24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82595608
	ctx.lr = 0x82489D2C;
	sub_82595608(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82489D40"))) PPC_WEAK_FUNC(sub_82489D40);
PPC_FUNC_IMPL(__imp__sub_82489D40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82489d94
	if (cr6.eq) goto loc_82489D94;
	// lwz r10,268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// li r11,0
	r11.s64 = 0;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82489d80
	if (cr6.eq) goto loc_82489D80;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_82489D64:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82489da0
	if (!cr6.eq) goto loc_82489DA0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82489d64
	if (cr6.lt) goto loc_82489D64;
loc_82489D80:
	// li r11,0
	r11.s64 = 0;
loc_82489D84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82489d98
	if (!cr6.eq) goto loc_82489D98;
loc_82489D94:
	// li r11,0
	r11.s64 = 0;
loc_82489D98:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_82489DA0:
	// li r11,1
	r11.s64 = 1;
	// b 0x82489d84
	goto loc_82489D84;
}

__attribute__((alias("__imp__sub_82489DA8"))) PPC_WEAK_FUNC(sub_82489DA8);
PPC_FUNC_IMPL(__imp__sub_82489DA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489DBC"))) PPC_WEAK_FUNC(sub_82489DBC);
PPC_FUNC_IMPL(__imp__sub_82489DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489DC0"))) PPC_WEAK_FUNC(sub_82489DC0);
PPC_FUNC_IMPL(__imp__sub_82489DC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,84(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x824a6ff0
	sub_824A6FF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82489DD0"))) PPC_WEAK_FUNC(sub_82489DD0);
PPC_FUNC_IMPL(__imp__sub_82489DD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489DD4"))) PPC_WEAK_FUNC(sub_82489DD4);
PPC_FUNC_IMPL(__imp__sub_82489DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489DD8"))) PPC_WEAK_FUNC(sub_82489DD8);
PPC_FUNC_IMPL(__imp__sub_82489DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v56{};
	PPCVRegister v57{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v62,1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x1)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 156);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcuxwfp128 v58,v62,1
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v62.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// vupkd3d128 v57,v60,4
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v57 = vTemp;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f12,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// ori r9,r8,128
	ctx.r9.u64 = ctx.r8.u64 | 128;
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v57,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x0));
	// lwz r10,19684(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19684);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// stb r9,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r9.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// vrsqrtefp128 v0,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// vmulfp128 v11,v0,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v10,v58,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v9,v12,v11,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v8,v9,v10,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v63,v8
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82489ed4
	if (cr6.eq) goto loc_82489ED4;
	// lfs f0,44(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	f0.f64 = double(temp.f32);
	// lfs f11,40(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// lfs f13,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// bge cr6,0x82489ed4
	if (!cr6.lt) goto loc_82489ED4;
	// fmuls f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r9,244(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 244);
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f8,f9,f12,f0
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f6,f7,f13,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f8.f64;
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fdivs f4,f5,f10
	ctx.f4.f64 = double(float(ctx.f5.f64 / ctx.f10.f64));
	// fmuls f3,f11,f4
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f4.f64));
	// fmuls f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f4.f64));
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82489ED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82489ED4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82489EE4"))) PPC_WEAK_FUNC(sub_82489EE4);
PPC_FUNC_IMPL(__imp__sub_82489EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82489EE8"))) PPC_WEAK_FUNC(sub_82489EE8);
PPC_FUNC_IMPL(__imp__sub_82489EE8) {
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
	// bl 0x823d91e8
	ctx.lr = 0x82489EF0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// bl 0x822a7c08
	ctx.lr = 0x82489F10;
	sub_822A7C08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82489f58
	if (!cr6.eq) goto loc_82489F58;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_82489F20:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// lbz r8,165(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 165);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82489f58
	if (!cr6.eq) goto loc_82489F58;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x82489F4C;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82489f20
	if (cr6.eq) goto loc_82489F20;
loc_82489F58:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82489f70
	if (!cr6.lt) goto loc_82489F70;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82489F70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248a3a0
	if (!cr6.eq) goto loc_8248A3A0;
	// lhz r8,8(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// bne cr6,0x82489fe8
	if (!cr6.eq) goto loc_82489FE8;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7c08
	ctx.lr = 0x82489F94;
	sub_822A7C08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248a3a0
	if (!cr6.eq) goto loc_8248A3A0;
loc_82489FA0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r7,165(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 165);
	// clrlwi r6,r7,25
	ctx.r6.u64 = ctx.r7.u32 & 0x7F;
	// stb r6,165(r8)
	PPC_STORE_U8(ctx.r8.u32 + 165, ctx.r6.u8);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
	// bl 0x822a7c08
	ctx.lr = 0x82489FD0;
	sub_822A7C08(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82489fa0
	if (cr6.eq) goto loc_82489FA0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_82489FE8:
	// lwz r27,4(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r27,r24
	cr6.compare<uint32_t>(r27.u32, r24.u32, xer);
	// beq cr6,0x8248a01c
	if (cr6.eq) goto loc_8248A01C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,160(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8248a014
	if (!cr6.eq) goto loc_8248A014;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8248A014:
	// cmplw cr6,r10,r24
	cr6.compare<uint32_t>(ctx.r10.u32, r24.u32, xer);
	// bne cr6,0x8248a3a0
	if (!cr6.eq) goto loc_8248A3A0;
loc_8248A01C:
	// lis r25,-32112
	r25.s64 = -2104492032;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,-2288(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -2288);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8248a054
	if (!cr6.eq) goto loc_8248A054;
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r11,r10
	r26.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x8248a058
	goto loc_8248A058;
loc_8248A054:
	// mr r26,r30
	r26.u64 = r30.u64;
loc_8248A058:
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r30
	r29.u64 = r30.u64;
	// lfs f31,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// bl 0x822a7c08
	ctx.lr = 0x8248A070;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248a0d0
	if (!cr6.eq) goto loc_8248A0D0;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_8248A080:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lbz r9,165(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 165);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8248a0b0
	if (cr6.eq) goto loc_8248A0B0;
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8248a0b0
	if (!cr6.gt) goto loc_8248A0B0;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_8248A0B0:
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822a7c08
	ctx.lr = 0x8248A0C4;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248a080
	if (cr6.eq) goto loc_8248A080;
loc_8248A0D0:
	// lbz r8,188(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 188);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r7,188(r1)
	PPC_STORE_U8(ctx.r1.u32 + 188, ctx.r7.u8);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r6,160(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplw cr6,r27,r5
	cr6.compare<uint32_t>(r27.u32, ctx.r5.u32, xer);
	// bne cr6,0x8248a104
	if (!cr6.eq) goto loc_8248A104;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// b 0x8248a108
	goto loc_8248A108;
loc_8248A104:
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
loc_8248A108:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,160(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r27,r6
	cr6.compare<uint32_t>(r27.u32, ctx.r6.u32, xer);
	// bne cr6,0x8248a130
	if (!cr6.eq) goto loc_8248A130;
	// lwz r5,28(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// b 0x8248a134
	goto loc_8248A134;
loc_8248A130:
	// lwz r5,36(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
loc_8248A134:
	// stw r5,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r5.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,160(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r27,r8
	cr6.compare<uint32_t>(r27.u32, ctx.r8.u32, xer);
	// bne cr6,0x8248a154
	if (!cr6.eq) goto loc_8248A154;
	// lwz r9,36(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// b 0x8248a158
	goto loc_8248A158;
loc_8248A154:
	// lwz r9,28(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
loc_8248A158:
	// stw r9,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r27,r7
	cr6.compare<uint32_t>(r27.u32, ctx.r7.u32, xer);
	// bne cr6,0x8248a178
	if (!cr6.eq) goto loc_8248A178;
	// lhz r9,168(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 168);
	// b 0x8248a17c
	goto loc_8248A17C;
loc_8248A178:
	// lhz r9,170(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 170);
loc_8248A17C:
	// stw r9,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r9.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r27,r7
	cr6.compare<uint32_t>(r27.u32, ctx.r7.u32, xer);
	// bne cr6,0x8248a19c
	if (!cr6.eq) goto loc_8248A19C;
	// lhz r9,170(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 170);
	// b 0x8248a1a0
	goto loc_8248A1A0;
loc_8248A19C:
	// lhz r9,168(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 168);
loc_8248A1A0:
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,160(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x8248a1c0
	if (!cr6.eq) goto loc_8248A1C0;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x8248a1c4
	goto loc_8248A1C4;
loc_8248A1C0:
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
loc_8248A1C4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// beq cr6,0x8248a1e0
	if (cr6.eq) goto loc_8248A1E0;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// b 0x8248a1ec
	goto loc_8248A1EC;
loc_8248A1E0:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
loc_8248A1EC:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A1F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248a284
	if (cr6.eq) goto loc_8248A284;
	// lhz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x8248a284
	if (cr6.eq) goto loc_8248A284;
	// lwz r11,-2288(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -2288);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,112(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8248a260
	if (!cr6.eq) goto loc_8248A260;
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248a260
	if (cr6.eq) goto loc_8248A260;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// b 0x8248a26c
	goto loc_8248A26C;
loc_8248A260:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
loc_8248A26C:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r5,180(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8248A284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248A284:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// li r10,80
	ctx.r10.s64 = 80;
	// lwz r7,160(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x8248a2b8
	if (!cr6.eq) goto loc_8248A2B8;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8248a2c4
	goto loc_8248A2C4;
loc_8248A2B8:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
loc_8248A2C4:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// vsubfp128 v62,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lwz r11,19684(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 19684);
	// lfs f0,7444(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f11,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// lfs f13,15000(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// vmsum3fp128 v59,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvlx128 v58,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// stfs f11,164(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248a350
	if (cr6.eq) goto loc_8248A350;
	// lfs f10,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f0.f64 = double(temp.f32);
	// lfs f13,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
loc_8248A350:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x8248a3a0
	if (!cr6.gt) goto loc_8248A3A0;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,244(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 244);
	// fsel f8,f11,f12,f0
	ctx.f8.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f6,f7,f13,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f8.f64;
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fdivs f4,f5,f9
	ctx.f4.f64 = double(float(ctx.f5.f64 / ctx.f9.f64));
	// fmuls f3,f10,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// fmuls f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f4.f64));
	// stfs f2,164(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A3A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248A3A0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8248A3AC"))) PPC_WEAK_FUNC(sub_8248A3AC);
PPC_FUNC_IMPL(__imp__sub_8248A3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A3B0"))) PPC_WEAK_FUNC(sub_8248A3B0);
PPC_FUNC_IMPL(__imp__sub_8248A3B0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x82477458
	ctx.lr = 0x8248A3D8;
	sub_82477458(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8248a400
	if (!cr6.eq) goto loc_8248A400;
	// lwz r10,248(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 248);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A3F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8248a438
	goto loc_8248A438;
loc_8248A400:
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A40C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r8,255
	ctx.r8.s64 = 255;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824abcb8
	ctx.lr = 0x8248A430;
	sub_824ABCB8(ctx, base);
	// stw r31,256(r30)
	PPC_STORE_U32(r30.u32 + 256, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8248A438:
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

__attribute__((alias("__imp__sub_8248A450"))) PPC_WEAK_FUNC(sub_8248A450);
PPC_FUNC_IMPL(__imp__sub_8248A450) {
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
	ctx.lr = 0x8248A458;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x82595408
	ctx.lr = 0x8248A470;
	sub_82595408(ctx, base);
	// lwz r11,84(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248a498
	if (cr6.eq) goto loc_8248A498;
	// lwz r3,404(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248a498
	if (cr6.eq) goto loc_8248A498;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825a89d8
	ctx.lr = 0x8248A498;
	sub_825A89D8(ctx, base);
loc_8248A498:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8248A4A0"))) PPC_WEAK_FUNC(sub_8248A4A0);
PPC_FUNC_IMPL(__imp__sub_8248A4A0) {
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
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8248a4d0
	if (cr6.eq) goto loc_8248A4D0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x82477750
	ctx.lr = 0x8248A4D0;
	sub_82477750(ctx, base);
loc_8248A4D0:
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8248a4ec
	if (cr6.eq) goto loc_8248A4EC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x8258b6c8
	ctx.lr = 0x8248A4EC;
	sub_8258B6C8(ctx, base);
loc_8248A4EC:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82595580
	ctx.lr = 0x8248A4FC;
	sub_82595580(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8248A510"))) PPC_WEAK_FUNC(sub_8248A510);
PPC_FUNC_IMPL(__imp__sub_8248A510) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A518"))) PPC_WEAK_FUNC(sub_8248A518);
PPC_FUNC_IMPL(__imp__sub_8248A518) {
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
	ctx.lr = 0x8248A520;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,220(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 220);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,92(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8248a5a8
	if (cr6.eq) goto loc_8248A5A8;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248a570
	if (cr6.eq) goto loc_8248A570;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r11,256
	r29.s64 = r11.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8248A568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// b 0x8248a598
	goto loc_8248A598;
loc_8248A570:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248a5a8
	if (!cr6.eq) goto loc_8248A5A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
loc_8248A598:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8249edf0
	ctx.lr = 0x8248A5A8;
	sub_8249EDF0(ctx, base);
loc_8248A5A8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8248A5B4"))) PPC_WEAK_FUNC(sub_8248A5B4);
PPC_FUNC_IMPL(__imp__sub_8248A5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A5B8"))) PPC_WEAK_FUNC(sub_8248A5B8);
PPC_FUNC_IMPL(__imp__sub_8248A5B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,92(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,307(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 307);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A5F8"))) PPC_WEAK_FUNC(sub_8248A5F8);
PPC_FUNC_IMPL(__imp__sub_8248A5F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248a618
	if (cr6.eq) goto loc_8248A618;
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8248a618
	if (cr6.eq) goto loc_8248A618;
	// lwz r3,352(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 352);
	// blr 
	return;
loc_8248A618:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A620"))) PPC_WEAK_FUNC(sub_8248A620);
PPC_FUNC_IMPL(__imp__sub_8248A620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f12,14868(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14868);
	ctx.f12.f64 = double(temp.f32);
	// li r9,112
	ctx.r9.s64 = 112;
	// clrlwi r7,r10,21
	ctx.r7.u64 = ctx.r10.u32 & 0x7FF;
	// lfs f11,-18280(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18280);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r6,r10,21,21,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x7FF;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// rlwinm r5,r10,10,22,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x3FF;
	// fcfid f7,f0
	ctx.f7.f64 = double(f0.s64);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// lfs f13,14980(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14980);
	ctx.f13.f64 = double(temp.f32);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// lfs f0,18204(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 18204);
	f0.f64 = double(temp.f32);
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v2,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// fmuls f3,f6,f11
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f1,f4,f12
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fmuls f2,f5,f12
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fnmsubs f12,f3,f0,f13
	ctx.f12.f64 = double(float(-(ctx.f3.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fnmsubs f10,f1,f0,f13
	ctx.f10.f64 = double(float(-(ctx.f1.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fnmsubs f11,f2,f0,f13
	ctx.f11.f64 = double(float(-(ctx.f2.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82489b20
	ctx.lr = 0x8248A6D4;
	sub_82489B20(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r3,32
	ctx.r3.s64 = 32;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A724"))) PPC_WEAK_FUNC(sub_8248A724);
PPC_FUNC_IMPL(__imp__sub_8248A724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A728"))) PPC_WEAK_FUNC(sub_8248A728);
PPC_FUNC_IMPL(__imp__sub_8248A728) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r6,r10,10,22,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x3FF;
	// xor r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r5,r10,23,9,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x7FFFFF;
	// xor r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r10.u64;
	// rlwinm r9,r10,10,0,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0xFFFFFC00;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r4,r10,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// xor r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 ^ ctx.r10.u64;
	// rlwinm r9,r10,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r3,r10,20,12,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// xor r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r10.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// and r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 & ctx.r7.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248a7b0
	if (cr6.eq) goto loc_8248A7B0;
loc_8248A798:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8248a798
	if (!cr6.eq) goto loc_8248A798;
loc_8248A7B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A7B8"))) PPC_WEAK_FUNC(sub_8248A7B8);
PPC_FUNC_IMPL(__imp__sub_8248A7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-29220
	ctx.r3.s64 = r11.s64 + -29220;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A7C4"))) PPC_WEAK_FUNC(sub_8248A7C4);
PPC_FUNC_IMPL(__imp__sub_8248A7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A7C8"))) PPC_WEAK_FUNC(sub_8248A7C8);
PPC_FUNC_IMPL(__imp__sub_8248A7C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-29148
	ctx.r3.s64 = r11.s64 + -29148;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A7D4"))) PPC_WEAK_FUNC(sub_8248A7D4);
PPC_FUNC_IMPL(__imp__sub_8248A7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A7D8"))) PPC_WEAK_FUNC(sub_8248A7D8);
PPC_FUNC_IMPL(__imp__sub_8248A7D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-29080
	ctx.r3.s64 = r11.s64 + -29080;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A7E4"))) PPC_WEAK_FUNC(sub_8248A7E4);
PPC_FUNC_IMPL(__imp__sub_8248A7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A7E8"))) PPC_WEAK_FUNC(sub_8248A7E8);
PPC_FUNC_IMPL(__imp__sub_8248A7E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-29000
	ctx.r3.s64 = r11.s64 + -29000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A7F4"))) PPC_WEAK_FUNC(sub_8248A7F4);
PPC_FUNC_IMPL(__imp__sub_8248A7F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A7F8"))) PPC_WEAK_FUNC(sub_8248A7F8);
PPC_FUNC_IMPL(__imp__sub_8248A7F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-28936
	ctx.r3.s64 = r11.s64 + -28936;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A804"))) PPC_WEAK_FUNC(sub_8248A804);
PPC_FUNC_IMPL(__imp__sub_8248A804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A808"))) PPC_WEAK_FUNC(sub_8248A808);
PPC_FUNC_IMPL(__imp__sub_8248A808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-28864
	ctx.r3.s64 = r11.s64 + -28864;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A814"))) PPC_WEAK_FUNC(sub_8248A814);
PPC_FUNC_IMPL(__imp__sub_8248A814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A818"))) PPC_WEAK_FUNC(sub_8248A818);
PPC_FUNC_IMPL(__imp__sub_8248A818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r3,r11,-28760
	ctx.r3.s64 = r11.s64 + -28760;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248A824"))) PPC_WEAK_FUNC(sub_8248A824);
PPC_FUNC_IMPL(__imp__sub_8248A824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248A828"))) PPC_WEAK_FUNC(sub_8248A828);
PPC_FUNC_IMPL(__imp__sub_8248A828) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248a88c
	if (cr6.eq) goto loc_8248A88C;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248a88c
	if (cr6.eq) goto loc_8248A88C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r10,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r10.u16);
	// lwz r9,752(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// lwz r3,28(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// bl 0x8248a728
	ctx.lr = 0x8248A87C;
	sub_8248A728(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248a88c
	if (cr6.eq) goto loc_8248A88C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8248a8e0
	goto loc_8248A8E0;
loc_8248A88C:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// addi r3,r11,812
	ctx.r3.s64 = r11.s64 + 812;
	// lwz r9,824(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 824);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8248A8B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8248a8dc
	if (cr6.eq) goto loc_8248A8DC;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8248a8dc
	if (cr6.eq) goto loc_8248A8DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,204(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 204);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248A8DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248A8DC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8248A8E0:
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

__attribute__((alias("__imp__sub_8248A8F8"))) PPC_WEAK_FUNC(sub_8248A8F8);
PPC_FUNC_IMPL(__imp__sub_8248A8F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x8248A900;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825a5008
	ctx.lr = 0x8248A910;
	sub_825A5008(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r29,-32122
	r29.s64 = -2105147392;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,-7164
	ctx.r9.s64 = r11.s64 + -7164;
	// addi r28,r29,2256
	r28.s64 = r29.s64 + 2256;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stfs f31,88(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f31,100(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// li r8,112
	ctx.r8.s64 = 112;
	// stfs f31,104(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f31,108(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r7.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,19620(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 19620);
	// addi r3,r11,860
	ctx.r3.s64 = r11.s64 + 860;
	// lwz r5,872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 872);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8248A988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// stfs f31,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lfs f0,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r3,-31280
	ctx.r3.s64 = ctx.r3.s64 + -31280;
	// lfs f12,2256(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 2256);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// bl 0x82489a28
	ctx.lr = 0x8248A9BC;
	sub_82489A28(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261e658
	ctx.lr = 0x8248A9C4;
	sub_8261E658(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8248a620
	ctx.lr = 0x8248A9D4;
	sub_8248A620(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r6,16
	ctx.r6.s64 = 16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8248AA24"))) PPC_WEAK_FUNC(sub_8248AA24);
PPC_FUNC_IMPL(__imp__sub_8248AA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248AA28"))) PPC_WEAK_FUNC(sub_8248AA28);
PPC_FUNC_IMPL(__imp__sub_8248AA28) {
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
	ctx.lr = 0x8248AA30;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x825a5008
	ctx.lr = 0x8248AA48;
	sub_825A5008(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-7164
	ctx.r8.s64 = ctx.r10.s64 + -7164;
	// li r28,48
	r28.s64 = 48;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r7,112
	ctx.r7.s64 = 112;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// addi r30,r31,96
	r30.s64 = r31.s64 + 96;
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lvx128 v63,r27,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r6.u32);
	// stw r26,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r26.u32);
	// lwz r11,19620(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 19620);
	// addi r3,r11,860
	ctx.r3.s64 = r11.s64 + 860;
	// lwz r11,872(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 872);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8248AABC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82489a28
	ctx.lr = 0x8248AACC;
	sub_82489A28(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8261e658
	ctx.lr = 0x8248AAD4;
	sub_8261E658(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a620
	ctx.lr = 0x8248AAE4;
	sub_8248A620(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r6,16
	ctx.r6.s64 = 16;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248ab64
	if (cr6.eq) goto loc_8248AB64;
	// lwz r11,236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 236);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v58,r11,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f12,12(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// stfs f0,8(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f11,4(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f13,0(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// bl 0x82489770
	ctx.lr = 0x8248AB64;
	sub_82489770(ctx, base);
loc_8248AB64:
	// stw r29,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,0,24,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// rlwinm r10,r10,0,22,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8248AB84"))) PPC_WEAK_FUNC(sub_8248AB84);
PPC_FUNC_IMPL(__imp__sub_8248AB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248AB88"))) PPC_WEAK_FUNC(sub_8248AB88);
PPC_FUNC_IMPL(__imp__sub_8248AB88) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8248AB90;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r24,-32115
	r24.s64 = -2104688640;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// li r25,1
	r25.s64 = 1;
	// lwz r8,19684(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 19684);
loc_8248ABB4:
	// lwz r10,92(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 92);
	// rlwinm r11,r6,2,22,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// clrlwi r9,r6,24
	ctx.r9.u64 = ctx.r6.u32 & 0xFF;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r7,208(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// lwzx r31,r7,r11
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// bge cr6,0x8248abe8
	if (!cr6.lt) goto loc_8248ABE8;
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
	// beq cr6,0x8248abe8
	if (cr6.eq) goto loc_8248ABE8;
	// lfs f0,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	f0.f64 = double(temp.f32);
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
loc_8248ABE8:
	// lwz r10,84(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8248ad28
	if (cr6.eq) goto loc_8248AD28;
	// addi r29,r10,256
	r29.s64 = ctx.r10.s64 + 256;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248ac24
	if (cr6.eq) goto loc_8248AC24;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm r7,r9,29,3,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r6,r9,27
	ctx.r6.u64 = ctx.r9.u32 & 0x1F;
	// slw r5,r25,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r6.u8 & 0x3F));
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r3,r7,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// and r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 & ctx.r5.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248ac34
	if (!cr6.eq) goto loc_8248AC34;
loc_8248AC24:
	// lfsx f0,r11,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r26.u32);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfsx f13,r11,r26
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + r26.u32, temp.u32);
	// lwz r8,19684(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 19684);
loc_8248AC34:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bgt cr6,0x8248accc
	if (cr6.gt) goto loc_8248ACCC;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248acc4
	if (cr6.eq) goto loc_8248ACC4;
	// li r30,0
	r30.s64 = 0;
loc_8248AC50:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248ac84
	if (cr6.eq) goto loc_8248AC84;
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r8,r11,29,3,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// slw r5,r25,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r7.u8 & 0x3F));
	// lwzx r4,r8,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// and r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 & ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8248aca8
	if (!cr6.eq) goto loc_8248ACA8;
loc_8248AC84:
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// addi r7,r28,-1
	ctx.r7.s64 = r28.s64 + -1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8248ab88
	ctx.lr = 0x8248ACA8;
	sub_8248AB88(ctx, base);
loc_8248ACA8:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8248ac50
	if (cr6.lt) goto loc_8248AC50;
	// lwz r8,19684(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 19684);
loc_8248ACC4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x8248ad30
	if (cr6.lt) goto loc_8248AD30;
loc_8248ACCC:
	// lbz r6,69(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8248ad30
	if (cr6.eq) goto loc_8248AD30;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248ad08
	if (cr6.eq) goto loc_8248AD08;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// slw r5,r25,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r7.u8 & 0x3F));
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r3,r9,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// and r11,r3,r5
	r11.u64 = ctx.r3.u64 & ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248ad30
	if (!cr6.eq) goto loc_8248AD30;
loc_8248AD08:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
	// beq cr6,0x8248ad20
	if (cr6.eq) goto loc_8248AD20;
	// lfs f0,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f31,f0,f31
	f31.f64 = double(float(f0.f64 * f31.f64));
loc_8248AD20:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// b 0x8248abb4
	goto loc_8248ABB4;
loc_8248AD28:
	// li r29,0
	r29.s64 = 0;
	// b 0x8248ac24
	goto loc_8248AC24;
loc_8248AD30:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8248AD3C"))) PPC_WEAK_FUNC(sub_8248AD3C);
PPC_FUNC_IMPL(__imp__sub_8248AD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248AD40"))) PPC_WEAK_FUNC(sub_8248AD40);
PPC_FUNC_IMPL(__imp__sub_8248AD40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8248ad5c
	if (!cr6.eq) goto loc_8248AD5C;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8248AD5C:
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8248ad6c
	if (!cr6.eq) goto loc_8248AD6C;
	// blr 
	return;
loc_8248AD6C:
	// lwz r4,92(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// b 0x824a7008
	sub_824A7008(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8248AD74"))) PPC_WEAK_FUNC(sub_8248AD74);
PPC_FUNC_IMPL(__imp__sub_8248AD74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248AD78"))) PPC_WEAK_FUNC(sub_8248AD78);
PPC_FUNC_IMPL(__imp__sub_8248AD78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x8248AD80;
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248adb0
	if (cr6.eq) goto loc_8248ADB0;
	// lwz r11,436(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
	// b 0x823d924c
	return;
loc_8248ADB0:
	// lwz r11,252(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248adcc
	if (cr6.eq) goto loc_8248ADCC;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
	// b 0x823d924c
	return;
loc_8248ADCC:
	// lbz r11,303(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 303);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8248ADE0;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8249d240
	ctx.lr = 0x8248ADF8;
	sub_8249D240(ctx, base);
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r7,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8248AE08"))) PPC_WEAK_FUNC(sub_8248AE08);
PPC_FUNC_IMPL(__imp__sub_8248AE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// bl 0x821c8fe0
	ctx.lr = 0x8248AE30;
	sub_821C8FE0(ctx, base);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8248ae4c
	if (cr6.eq) goto loc_8248AE4C;
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x82477750
	ctx.lr = 0x8248AE4C;
	sub_82477750(ctx, base);
loc_8248AE4C:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248aea8
	if (cr6.eq) goto loc_8248AEA8;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a620
	ctx.lr = 0x8248AE64;
	sub_8248A620(ctx, base);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r8,236(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 236);
	// lvx128 v63,r8,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f11,100(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bl 0x82489770
	ctx.lr = 0x8248AEA8;
	sub_82489770(ctx, base);
loc_8248AEA8:
	// lwz r11,19620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 19620);
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// addi r3,r11,828
	ctx.r3.s64 = r11.s64 + 828;
	// lwz r11,840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 840);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8248AEC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8248aedc
	if (cr6.eq) goto loc_8248AEDC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x8258b6c8
	ctx.lr = 0x8248AEDC;
	sub_8258B6C8(ctx, base);
loc_8248AEDC:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82595580
	ctx.lr = 0x8248AEEC;
	sub_82595580(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x8248AF00;
	sub_821C9030(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_8248AF18"))) PPC_WEAK_FUNC(sub_8248AF18);
PPC_FUNC_IMPL(__imp__sub_8248AF18) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8248AF20;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// bl 0x821c8fe0
	ctx.lr = 0x8248AF3C;
	sub_821C8FE0(ctx, base);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r10,0,24,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// rlwinm r9,r9,0,22,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8248af7c
	if (cr6.eq) goto loc_8248AF7C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 156);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248AF70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r8,r9,0,26,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
loc_8248AF7C:
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8248afe0
	if (cr6.eq) goto loc_8248AFE0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a70b8
	ctx.lr = 0x8248AF90;
	sub_824A70B8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x82477750
	ctx.lr = 0x8248AFA8;
	sub_82477750(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,176(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 176);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8248AFBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8248b1c0
	if (cr6.eq) goto loc_8248B1C0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248b1c0
	if (!cr6.eq) goto loc_8248B1C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// b 0x8248b1b4
	goto loc_8248B1B4;
loc_8248AFE0:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a620
	ctx.lr = 0x8248AFEC;
	sub_8248A620(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,88(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// beq cr6,0x8248b024
	if (cr6.eq) goto loc_8248B024;
	// lwz r11,208(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248b024
	if (cr6.eq) goto loc_8248B024;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248b024
	if (cr6.eq) goto loc_8248B024;
	// lfs f0,80(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
loc_8248B024:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r27,16
	r27.s64 = 16;
	// li r28,32
	r28.s64 = 32;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// li r30,48
	r30.s64 = 48;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248b0c0
	if (cr6.eq) goto loc_8248B0C0;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8248b0c0
	if (!cr6.eq) goto loc_8248B0C0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8248b074
	if (cr6.eq) goto loc_8248B074;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8248b074
	if (cr6.eq) goto loc_8248B074;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,204(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 204);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248B074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248B074:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248b0c0
	if (cr6.eq) goto loc_8248B0C0;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8248b0c0
	if (!cr6.eq) goto loc_8248B0C0;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B0C0:
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lis r29,-32114
	r29.s64 = -2104623104;
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8248b0fc
	if (cr6.eq) goto loc_8248B0FC;
	// lwz r11,-23452(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8248b0fc
	if (!cr6.eq) goto loc_8248B0FC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x82588d90
	ctx.lr = 0x8248B0FC;
	sub_82588D90(ctx, base);
loc_8248B0FC:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248b194
	if (cr6.eq) goto loc_8248B194;
	// lwz r11,236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v55,r11,r30
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f11,100(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bl 0x82489770
	ctx.lr = 0x8248B178;
	sub_82489770(ctx, base);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lfs f10,316(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 316);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f31
	cr6.compare(ctx.f10.f64, f31.f64);
	// beq cr6,0x8248b194
	if (cr6.eq) goto loc_8248B194;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
loc_8248B194:
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x8248b1c0
	if (cr6.eq) goto loc_8248B1C0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-23452(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// bl 0x825734b0
	ctx.lr = 0x8248B1AC;
	sub_825734B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
loc_8248B1B4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248B1C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248B1C0:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x8248B1D4;
	sub_821C9030(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8248B1E0"))) PPC_WEAK_FUNC(sub_8248B1E0);
PPC_FUNC_IMPL(__imp__sub_8248B1E0) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
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
	// bl 0x823d91cc
	ctx.lr = 0x8248B1E8;
	// lwz r17,84(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// beq cr6,0x8248b4dc
	if (cr6.eq) goto loc_8248B4DC;
	// lwz r22,92(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lwz r24,268(r17)
	r24.u64 = PPC_LOAD_U32(r17.u32 + 268);
	// li r19,16
	r19.s64 = 16;
	// addi r27,r10,2384
	r27.s64 = ctx.r10.s64 + 2384;
	// li r21,-16
	r21.s64 = -16;
	// li r20,-32
	r20.s64 = -32;
	// lwz r9,280(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 280);
	// li r11,0
	r11.s64 = 0;
	// lbz r10,303(r22)
	ctx.r10.u64 = PPC_LOAD_U8(r22.u32 + 303);
	// li r18,0
	r18.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r23,4(r9)
	r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// ble cr6,0x8248b400
	if (!cr6.gt) goto loc_8248B400;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r28,0
	r28.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8248B240:
	// lwz r10,212(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 212);
	// lwzx r29,r28,r10
	r29.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// lhz r9,14(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// extsh r3,r9
	ctx.r3.s64 = ctx.r9.s16;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bge cr6,0x8248b308
	if (!cr6.lt) goto loc_8248B308;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r30,r11,r3
	r30.s64 = ctx.r3.s64 - r11.s64;
	// addi r7,r10,32
	ctx.r7.s64 = ctx.r10.s64 + 32;
loc_8248B270:
	// lwz r11,4(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v61,r11,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v61,v62
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpeqfp128. v59,v60,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8248b2ac
	if (cr6.eq) goto loc_8248B2AC;
	// stvx128 v63,r7,r19
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r7,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r7,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B2AC:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8248b2f8
	if (cr6.eq) goto loc_8248B2F8;
	// lvx128 v58,r11,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r27
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v58,v57
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vcmpeqfp128. v55,v56,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248b2f8
	if (cr6.eq) goto loc_8248B2F8;
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B2F8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// bne 0x8248b270
	if (!cr0.eq) goto loc_8248B270;
loc_8248B308:
	// lbz r11,12(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r8,r11,27
	ctx.r8.u64 = r11.u32 & 0x1F;
	// slw r7,r25,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// and r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248b380
	if (cr6.eq) goto loc_8248B380;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// addi r8,r11,32
	ctx.r8.s64 = r11.s64 + 32;
	// addi r7,r11,16
	ctx.r7.s64 = r11.s64 + 16;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8248b3f0
	if (cr6.eq) goto loc_8248B3F0;
	// add r11,r10,r5
	r11.u64 = ctx.r10.u64 + ctx.r5.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8248b3f0
	goto loc_8248B3F0;
loc_8248B380:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8248b3f0
	if (cr6.eq) goto loc_8248B3F0;
	// lwz r10,260(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 260);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// lfsx f13,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8248b3cc
	if (cr6.gt) goto loc_8248B3CC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r18,r25
	r18.u64 = r25.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8248b3f0
	goto loc_8248B3F0;
loc_8248B3CC:
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// vspltisw128 v53,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B3F0:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8248b240
	if (!cr0.eq) goto loc_8248B240;
loc_8248B400:
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x8248b4b8
	if (!cr6.lt) goto loc_8248B4B8;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// subf r7,r11,r6
	ctx.r7.s64 = ctx.r6.s64 - r11.s64;
	// add r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// subf r3,r4,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r4.s64;
	// li r6,32
	ctx.r6.s64 = 32;
loc_8248B430:
	// lwz r11,4(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// lvx128 v52,r0,r27
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v51,r11,r4
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v50,v51,v52
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vcmpeqfp128. v49,v50,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v49.f32), 0xF);
	// mfocrf r31,2
	r31.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r31,r31,0,24,24
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248b46c
	if (cr6.eq) goto loc_8248B46C;
	// stvx128 v63,r10,r19
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B46C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8248b4a4
	if (cr6.eq) goto loc_8248B4A4;
	// lvx128 v48,r11,r5
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r27
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v46,v48,v47
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// vcmpeqfp128. v45,v46,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v45.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248b4a4
	if (cr6.eq) goto loc_8248B4A4;
	// stvx128 v63,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B4A4:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// bne 0x8248b430
	if (!cr0.eq) goto loc_8248B430;
loc_8248B4B8:
	// lwz r11,196(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 196);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8248b4dc
	if (cr6.eq) goto loc_8248B4DC;
	// lwz r10,184(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 184);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248b4dc
	if (cr6.eq) goto loc_8248B4DC;
	// stb r18,264(r17)
	PPC_STORE_U8(r17.u32 + 264, r18.u8);
loc_8248B4DC:
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8248B4E0"))) PPC_WEAK_FUNC(sub_8248B4E0);
PPC_FUNC_IMPL(__imp__sub_8248B4E0) {
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
	// li r11,256
	r11.s64 = 256;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,20336
	ctx.r3.s64 = ctx.r10.s64 + 20336;
	// bl 0x821c0750
	ctx.lr = 0x8248B510;
	sub_821C0750(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,20328
	r11.s64 = r11.s64 + 20328;
	// lwz r10,19620(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19620);
	// lwz r8,752(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 752);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,8(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x8248b5a8
	if (!cr6.gt) goto loc_8248B5A8;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8248b5a8
	if (!cr6.lt) goto loc_8248B5A8;
	// lwz r31,92(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248b574
	if (cr6.eq) goto loc_8248B574;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x8248B568;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x8248b578
	if (!cr6.eq) goto loc_8248B578;
loc_8248B574:
	// lwz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 176);
loc_8248B578:
	// lfs f3,72(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lfs f2,68(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,64(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r11,-6792
	ctx.r3.s64 = r11.s64 + -6792;
	// stfd f3,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f3.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x8248B5A8;
	sub_82130000(ctx, base);
loc_8248B5A8:
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

__attribute__((alias("__imp__sub_8248B5C0"))) PPC_WEAK_FUNC(sub_8248B5C0);
PPC_FUNC_IMPL(__imp__sub_8248B5C0) {
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
	PPCRegister f0{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91ec
	ctx.lr = 0x8248B5C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,84(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248b8ec
	if (cr6.eq) goto loc_8248B8EC;
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// lwz r4,132(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// beq cr6,0x8248b5fc
	if (cr6.eq) goto loc_8248B5FC;
	// lhz r11,146(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 146);
	// rotlwi r5,r11,6
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 6);
	// bl 0x823da950
	ctx.lr = 0x8248B5FC;
	sub_823DA950(ctx, base);
loc_8248B5FC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248B610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,92(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lbz r11,303(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 303);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8248b7e8
	if (!cr6.gt) goto loc_8248B7E8;
	// mr r28,r11
	r28.u64 = r11.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r27,1
	r27.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8248B644:
	// lwz r11,212(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 212);
	// lwz r6,268(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// lwzx r10,r4,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// lwz r6,0(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lbz r11,12(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// rlwinm r26,r11,29,3,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r25,r11,27
	r25.u64 = r11.u32 & 0x1F;
	// slw r25,r27,r25
	r25.u64 = r25.u8 & 0x20 ? 0 : (r27.u32 << (r25.u8 & 0x3F));
	// lwzx r6,r26,r6
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + ctx.r6.u32);
	// and r6,r25,r6
	ctx.r6.u64 = r25.u64 & ctx.r6.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8248b7d8
	if (!cr6.eq) goto loc_8248B7D8;
	// lwz r6,144(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// rlwinm r26,r11,2,0,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,260(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// addi r11,r6,128
	r11.s64 = ctx.r6.s64 + 128;
	// lhz r6,14(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14);
	// lfsx f13,r25,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + r26.u32);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bgt cr6,0x8248b6c4
	if (cr6.gt) goto loc_8248B6C4;
	// lwz r11,148(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248b6c4
	if (cr6.eq) goto loc_8248B6C4;
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B6C4:
	// extsh r10,r6
	ctx.r10.s64 = ctx.r6.s16;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// vspltw128 v13,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lwz r6,228(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltw128 v59,v63,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// vspltw128 v57,v61,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v11,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// vspltw128 v10,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v9,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// lvx128 v6,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v5,v0,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vmaddfp v4,v0,v13,v6
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v13,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v3,v0,v58
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v12,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v2,v0,v57
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v1,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v31,v62,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v56,r10,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v30,v61,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// lvx128 v55,r10,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,132(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 132);
	// lvx128 v53,r10,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// vmaddfp v29,v13,v10,v5
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v28,v13,v11,v4
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v27,v13,v9,v3
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v26,v13,v8,v2
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v25,v12,v1,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v12,v7,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// vmsum3fp128 v52,v25,v55
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vsubfp128 v51,v24,v56
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v24.f32), simde_mm_load_ps(v56.f32)));
	// vmsum3fp128 v50,v25,v53
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v49,v25,v54
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v48,v23,v55
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v47,v23,v53
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v46,v23,v54
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v45,v22,v55
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v44,v22,v53
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v43,v22,v54
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v42,v51,v55
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v41,v51,v53
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v40,v51,v54
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v39,v52,v25
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v25.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v38,v49,v50
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v37,v48,v23
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v23.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v36,v46,v47
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v35,v45,v22
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v22.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v34,v38,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v33,v43,v44
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v32,v36,v37
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v63,v33,v35
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v62,v42,v24
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v24.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v61,v40,v41
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// stvx128 v32,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v60,v61,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248B7D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r5,r5,64
	ctx.r5.s64 = ctx.r5.s64 + 64;
	// bne 0x8248b644
	if (!cr0.eq) goto loc_8248B644;
loc_8248B7E8:
	// lwz r11,236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 236);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lis r28,-32122
	r28.s64 = -2105147392;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,280(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 280);
	// addi r27,r4,2384
	r27.s64 = ctx.r4.s64 + 2384;
	// addi r29,r28,2352
	r29.s64 = r28.s64 + 2352;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lvx128 v54,r11,r8
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v63,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v52.f32)));
	// vmsum3fp128 v50,v55,v51
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v49,v54,v51
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v48,v53,v51
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmrghw128 v47,v50,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v46,v48,v49
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v63,v46,v47
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vand128 v45,v63,v62
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// vor128 v44,v61,v45
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// lvx128 v41,r10,r9
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r10,r7
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r10,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v38,v42,v43
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v39,v40,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v37,v42,v43
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrglw128 v36,v40,v41
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v35,v38,v39
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v34,v38,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v33,v37,v36
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmsum4fp128 v32,v44,v35
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v35.f32), 0xFF));
	// vmsum4fp128 v63,v44,v34
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmsum4fp128 v62,v44,v33
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v33.f32), 0xFF));
	// vmrghw128 v61,v32,v44
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v60,v63,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v55,v60,v61
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vsubfp128 v54,v55,v59
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v59.f32)));
	// vmsum3fp128 v53,v57,v54
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v52,v56,v54
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v51,v58,v54
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v50,v53,v53
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v49,v51,v52
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v48,v49,v50
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// stvx128 v48,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8248B8EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248B8EC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8248B8F4"))) PPC_WEAK_FUNC(sub_8248B8F4);
PPC_FUNC_IMPL(__imp__sub_8248B8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248B8F8"))) PPC_WEAK_FUNC(sub_8248B8F8);
PPC_FUNC_IMPL(__imp__sub_8248B8F8) {
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
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister v121{};
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8248B900;
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd51c
	ctx.lr = 0x8248B908;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// lwz r27,84(r17)
	r27.u64 = PPC_LOAD_U32(r17.u32 + 84);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// beq cr6,0x8248bef4
	if (cr6.eq) goto loc_8248BEF4;
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// lwz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// li r25,0
	r25.s64 = 0;
	// lwz r20,92(r17)
	r20.u64 = PPC_LOAD_U32(r17.u32 + 92);
	// addi r16,r27,256
	r16.s64 = r27.s64 + 256;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// std r25,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r25.u64);
	// std r25,8(r11)
	PPC_STORE_U64(r11.u32 + 8, r25.u64);
	// std r25,16(r11)
	PPC_STORE_U64(r11.u32 + 16, r25.u64);
	// std r25,24(r11)
	PPC_STORE_U64(r11.u32 + 24, r25.u64);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8248B954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r17)
	ctx.r8.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8248B96C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,4(r17)
	ctx.r6.u64 = PPC_LOAD_U32(r17.u32 + 4);
	// lbz r5,303(r20)
	ctx.r5.u64 = PPC_LOAD_U8(r20.u32 + 303);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r24,12(r6)
	r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// beq cr6,0x8248bef4
	if (cr6.eq) goto loc_8248BEF4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// mr r22,r25
	r22.u64 = r25.u64;
	// li r29,16
	r29.s64 = 16;
	// li r30,32
	r30.s64 = 32;
	// li r28,48
	r28.s64 = 48;
	// li r14,80
	r14.s64 = 80;
	// li r21,12
	r21.s64 = 12;
	// li r15,640
	r15.s64 = 640;
	// addi r23,r11,29952
	r23.s64 = r11.s64 + 29952;
	// addi r19,r10,2352
	r19.s64 = ctx.r10.s64 + 2352;
	// addi r18,r9,2384
	r18.s64 = ctx.r9.s64 + 2384;
	// b 0x8248b9c0
	goto loc_8248B9C0;
loc_8248B9BC:
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8248B9C0:
	// lwz r11,212(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 212);
	// li r31,1
	r31.s64 = 1;
	// lwz r10,12(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// lwzx r9,r11,r22
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r22.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r7,12(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12);
	// rlwinm r6,r7,29,3,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r5,r7,27
	ctx.r5.u64 = ctx.r7.u32 & 0x1F;
	// slw r4,r31,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r5.u8 & 0x3F));
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// and r11,r4,r3
	r11.u64 = ctx.r4.u64 & ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248bed4
	if (!cr6.eq) goto loc_8248BED4;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,116(r16)
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + 116);
	// bl 0x825aeb50
	ctx.lr = 0x8248BA00;
	sub_825AEB50(ctx, base);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// lbzx r11,r3,r8
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248bed4
	if (!cr6.eq) goto loc_8248BED4;
	// lwz r11,212(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 212);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lwz r9,228(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 228);
	// stbx r31,r3,r8
	PPC_STORE_U8(ctx.r3.u32 + ctx.r8.u32, r31.u8);
	// addi r31,r17,16
	r31.s64 = r17.s64 + 16;
	// lwzx r10,r11,r22
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r22.u32);
	// lwz r9,132(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// addi r11,r10,80
	r11.s64 = ctx.r10.s64 + 80;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// add r9,r9,r25
	ctx.r9.u64 = ctx.r9.u64 + r25.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v8,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v7,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v5,v0,v59
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmulfp128 v3,v0,v58
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v13,r10,r29
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v30,v57,0
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lvx128 v29,r10,r28
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v12,r10,r30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v31,v60,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// lvx128 v10,r9,r29
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v26,v0,v30,v29
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v29.f32)));
	// vspltw128 v28,v57,1
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xAA));
	// vspltw128 v27,v57,2
	simde_mm_store_si128((simde__m128i*)v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x55));
	// lvx128 v9,r9,r30
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v25,r9,r28
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v24,v13,v8,v7
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v23,v13,v6,v5
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v22,v13,v4,v3
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v21,v13,v28,v26
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v20,v12,v2,v24
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v24.f32)));
	// lvx128 v24,r31,r28
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v19,v12,v1,v23
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v23.f32)));
	// vmaddfp v18,v12,v31,v22
	simde_mm_store_ps(v18.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v22.f32)));
	// vmaddfp v17,v12,v27,v21
	simde_mm_store_ps(v17.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(v21.f32)));
	// vspltw128 v56,v20,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v20.u32), 0xFF));
	// vspltw128 v55,v19,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v19.u32), 0xFF));
	// vspltw128 v54,v18,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v18.u32), 0xFF));
	// vspltw v16,v20,1
	simde_mm_store_si128((simde__m128i*)v16.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v20.u32), 0xAA));
	// vmulfp128 v15,v11,v56
	simde_mm_store_ps(v15.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v56.f32)));
	// vspltw v14,v19,1
	simde_mm_store_si128((simde__m128i*)v14.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v19.u32), 0xAA));
	// vmulfp128 v0,v11,v55
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v55.f32)));
	// vspltw v13,v18,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v18.u32), 0xAA));
	// vmulfp128 v12,v11,v54
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v54.f32)));
	// vspltw v8,v20,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v20.u32), 0x55));
	// vspltw v7,v19,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v19.u32), 0x55));
	// vspltw v6,v18,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v18.u32), 0x55));
	// vspltw v5,v17,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v17.u32), 0xFF));
	// vspltw v4,v17,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v17.u32), 0xAA));
	// vspltw v3,v17,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v17.u32), 0x55));
	// vmaddfp v2,v11,v5,v25
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(v25.f32)));
	// vmaddfp v1,v10,v16,v15
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v16.f32)), simde_mm_load_ps(v15.f32)));
	// vmaddfp v31,v10,v14,v0
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v14.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v0,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v30,v10,v13,v12
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// lvx128 v13,r31,r29
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v25,v10,v4,v2
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v29,v9,v8,v1
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v28,v9,v7,v31
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(v31.f32)));
	// vmaddfp v27,v9,v6,v30
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(v30.f32)));
	// vspltw128 v53,v29,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v29.u32), 0xFF));
	// vspltw128 v52,v28,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v28.u32), 0xFF));
	// vspltw128 v51,v27,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v27.u32), 0xFF));
	// vspltw v26,v29,1
	simde_mm_store_si128((simde__m128i*)v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v29.u32), 0xAA));
	// vmulfp128 v23,v0,v53
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v53.f32)));
	// vspltw v21,v28,1
	simde_mm_store_si128((simde__m128i*)v21.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v28.u32), 0xAA));
	// vmulfp128 v22,v0,v52
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vspltw v19,v27,1
	simde_mm_store_si128((simde__m128i*)v19.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v27.u32), 0xAA));
	// vmulfp128 v20,v0,v51
	simde_mm_store_ps(v20.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vmaddfp v15,v9,v3,v25
	simde_mm_store_ps(v15.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(v25.f32)));
	// vspltw v18,v29,2
	simde_mm_store_si128((simde__m128i*)v18.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v29.u32), 0x55));
	// vmaddfp v14,v13,v26,v23
	simde_mm_store_ps(v14.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v26.f32)), simde_mm_load_ps(v23.f32)));
	// vspltw v17,v28,2
	simde_mm_store_si128((simde__m128i*)v17.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v28.u32), 0x55));
	// vmaddfp v10,v13,v21,v22
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v21.f32)), simde_mm_load_ps(v22.f32)));
	// vspltw v16,v27,2
	simde_mm_store_si128((simde__m128i*)v16.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v27.u32), 0x55));
	// vmaddfp v9,v13,v19,v20
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v19.f32)), simde_mm_load_ps(v20.f32)));
	// lvx128 v12,r31,r30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v8,v15,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v15.u32), 0xFF));
	// vspltw v7,v15,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v15.u32), 0xAA));
	// vmaddfp v11,v12,v18,v14
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v18.f32)), simde_mm_load_ps(v14.f32)));
	// vspltw v6,v15,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v15.u32), 0x55));
	// vmaddfp v10,v12,v17,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v17.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v9,v12,v16,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v16.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v5,v0,v8,v24
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v24.f32)));
	// vmaddfp v4,v13,v7,v5
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v0,v12,v6,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// bne cr6,0x8248bbe0
	if (!cr6.eq) goto loc_8248BBE0;
	// lvx128 v50,r20,r28
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v10,v0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// lvx128 v48,r20,r30
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v47,v11,v9
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vsubfp128 v46,v48,v50
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v50.f32)));
	// vmrglw128 v45,v10,v0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vmrglw128 v44,v11,v9
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vmrghw128 v43,v47,v49
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrglw128 v42,v47,v49
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v41,v44,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmsum3fp128 v40,v46,v41
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v41.f32), 0xEF));
	// vmsum3fp128 v39,v46,v43
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vmsum3fp128 v38,v46,v42
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v42.f32), 0xEF));
	// vmrghw128 v37,v39,v40
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v36,v38,v37
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v35,v37,v36
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vaddfp128 v0,v0,v35
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v35.f32)));
loc_8248BBE0:
	// lwz r11,116(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 116);
	// li r10,256
	ctx.r10.s64 = 256;
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
	// lwz r8,108(r16)
	ctx.r8.u64 = PPC_LOAD_U32(r16.u32 + 108);
	// vmrghw128 v34,v11,v9
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// vmrglw128 v33,v11,v9
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// lvx128 v32,r11,r10
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v0,v32
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v32.f32)));
	// lwzx r27,r7,r8
	r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// addi r26,r27,464
	r26.s64 = r27.s64 + 464;
	// addi r11,r27,416
	r11.s64 = r27.s64 + 416;
	// vmrghw128 v62,v10,v63
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v61,v10,v63
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vmrghw128 v60,v34,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrglw128 v59,v34,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v58,v33,v61
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,128(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 128);
	// lwzx r9,r6,r22
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + r22.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8248bed4
	if (cr6.eq) goto loc_8248BED4;
	// lwz r11,136(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 136);
	// lvx128 v57,r9,r14
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,132(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 132);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// lvx128 v62,r0,r19
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v53,r11,r28
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v52,r10,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// vsubfp128 v51,v52,v53
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// lvx128 v48,r11,r29
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r10,r29
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v33,v48,v48
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// lvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v42,v47,v48
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v34,v44,v48
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// lvx128 v49,r11,r30
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v43,v47,v50
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// lvx128 v46,r10,r30
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v45,v47,v49
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmsum3fp128 v40,v46,v49
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// lvx128 v41,r0,r6
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v38,v46,v50
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v36,v46,v48
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// lvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v32,v44,v49
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// lvx128 v39,r0,r5
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v44,v50
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vor128 v60,v49,v49
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vor128 v58,v46,v46
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vmsum3fp128 v59,v51,v49
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vor128 v37,v50,v50
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vmsum3fp128 v57,v51,v50
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vor128 v35,v44,v44
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v44.u8));
	// vmsum3fp128 v52,v51,v48
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vor128 v63,v47,v47
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v51,r10,r28
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vsubfp128 v124,v58,v60
	simde_mm_store_ps(v124.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32)));
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// vsubfp128 v127,v35,v37
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v37.f32)));
	// vmrghw128 v49,v42,v55
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vsubfp128 v126,v63,v33
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v33.f32)));
	// vmrghw128 v46,v34,v41
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vsubfp128 v123,v51,v53
	simde_mm_store_ps(v123.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v53.f32)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// vor128 v125,v62,v56
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vmrghw128 v50,v43,v45
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// vmrghw128 v48,v38,v40
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v47,v36,v54
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v45,v50,v49
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v44,v61,v32
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v43,v48,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v42,v57,v59
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v41,v52,v39
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v40,v44,v46
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v45,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v122,v127,v124
	simde_mm_store_si128((simde__m128i*)v122.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// vmrghw128 v121,v126,v123
	simde_mm_store_si128((simde__m128i*)v121.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// vmrghw128 v39,v42,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821d1f30
	ctx.lr = 0x8248BD74;
	sub_821D1F30(ctx, base);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x823cc7b0
	ctx.lr = 0x8248BD84;
	sub_823CC7B0(ctx, base);
	// vmrglw128 v38,v126,v123
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// vmrglw128 v37,v127,v124
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// vmrglw128 v36,v122,v121
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v121.u32), simde_mm_load_si128((simde__m128i*)v122.u32)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vmrghw128 v35,v122,v121
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v121.u32), simde_mm_load_si128((simde__m128i*)v122.u32)));
	// lvlx128 v34,r23,r21
	temp.u32 = r23.u32 + r21.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v32,v34,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// lvlx128 v33,r23,r21
	temp.u32 = r23.u32 + r21.u32;
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmrghw128 v63,v37,v38
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v61,v125,v36
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// lvlx128 v60,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmsum4fp128 v59,v125,v35
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v35.f32), 0xFF));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v57,r0,r4
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v56,v33,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// vmsum4fp128 v55,v125,v63
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// lvx128 v54,r31,r30
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r31,r28
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v49,v62,v62
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vmulfp128 v51,v57,v58
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v50,r31,r29
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v47,v54,v54
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vmrghw128 v52,v62,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vor128 v45,v53,v53
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vmrghw128 v48,v50,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vor128 v43,v50,v50
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vmrglw128 v46,v62,v54
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v44,v50,v53
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// vmrghw128 v42,v49,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// vmrglw128 v40,v49,v47
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// addi r9,r27,608
	ctx.r9.s64 = r27.s64 + 608;
	// vmrghw128 v41,v43,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// addi r11,r27,624
	r11.s64 = r27.s64 + 624;
	// vmrglw128 v39,v43,v45
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// addi r10,r27,656
	ctx.r10.s64 = r27.s64 + 656;
	// vmrghw128 v37,v46,v44
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v38,v52,v48
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lvx128 v35,r0,r3
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v34,v61,v125
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v63,v51,v56
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v56.f32)));
	// vmrghw128 v36,v42,v41
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v62,v40,v39
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v60,v59,v55
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v59,v42,v41
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrglw128 v61,v52,v48
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v58,v60,v34
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmulfp128 v57,v58,v32
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v32.f32)));
	// vmsum3fp128 v56,v63,v62
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v55,v63,v36
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// vmsum3fp128 v54,v63,v59
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v53,v57,v37
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v37.f32), 0xEF));
	// vmsum3fp128 v52,v57,v38
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vmsum3fp128 v51,v57,v61
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmrghw128 v50,v55,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v49,v54,v50
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v48,v50,v49
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v47,v52,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vaddfp128 v63,v48,v33
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v33.f32)));
	// vmrghw128 v46,v51,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v45,v47,v46
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vaddfp128 v44,v45,v35
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v35.f32)));
	// vor128 v43,v63,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r27,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v13,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r26
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v12,v41,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0x9C));
	// vpermwi128 v0,v40,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x78));
	// vpermwi128 v11,v40,99
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x9C));
	// vpermwi128 v10,v41,135
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0x78));
	// vmaddfp v9,v12,v0,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v8,v10,v11,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v8,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248BED4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// lbz r10,303(r20)
	ctx.r10.u64 = PPC_LOAD_U8(r20.u32 + 303);
	// addi r25,r25,64
	r25.s64 = r25.s64 + 64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8248b9bc
	if (cr6.lt) goto loc_8248B9BC;
loc_8248BEF4:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd7b4
	ctx.lr = 0x8248BF00;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8248BF04"))) PPC_WEAK_FUNC(sub_8248BF04);
PPC_FUNC_IMPL(__imp__sub_8248BF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248BF08"))) PPC_WEAK_FUNC(sub_8248BF08);
PPC_FUNC_IMPL(__imp__sub_8248BF08) {
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
	ctx.lr = 0x8248BF10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r10,92(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// rlwinm r9,r11,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248bf48
	if (cr6.eq) goto loc_8248BF48;
	// rlwinm r9,r11,0,23,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248bf54
	if (cr6.eq) goto loc_8248BF54;
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248bf70
	if (cr6.eq) goto loc_8248BF70;
loc_8248BF48:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8248BF54:
	// lbz r11,307(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 307);
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248bf70
	if (cr6.eq) goto loc_8248BF70;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8248BF70:
	// lbz r11,307(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 307);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248c04c
	if (cr6.eq) goto loc_8248C04C;
	// lwz r11,84(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8248bfa8
	if (!cr6.eq) goto loc_8248BFA8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248BFA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248bf48
	if (cr6.eq) goto loc_8248BF48;
loc_8248BFA8:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r31,84(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248bfc4
	if (!cr6.eq) goto loc_8248BFC4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824aae80
	ctx.lr = 0x8248BFC4;
	sub_824AAE80(ctx, base);
loc_8248BFC4:
	// addi r31,r31,256
	r31.s64 = r31.s64 + 256;
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248bff4
	if (cr6.eq) goto loc_8248BFF4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248BFE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248bf48
	if (cr6.eq) goto loc_8248BF48;
loc_8248BFF4:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248c008
	if (cr6.eq) goto loc_8248C008;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8248b8f8
	ctx.lr = 0x8248C008;
	sub_8248B8F8(ctx, base);
loc_8248C008:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248c040
	if (cr6.eq) goto loc_8248C040;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248c028
	if (!cr6.eq) goto loc_8248C028;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248c040
	if (cr6.eq) goto loc_8248C040;
loc_8248C028:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248C040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248C040:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// stw r10,80(r30)
	PPC_STORE_U32(r30.u32 + 80, ctx.r10.u32);
loc_8248C04C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8248C058"))) PPC_WEAK_FUNC(sub_8248C058);
PPC_FUNC_IMPL(__imp__sub_8248C058) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lfs f12,316(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 316);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x8248c09c
	if (cr6.eq) goto loc_8248C09C;
	// lbz r10,307(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 307);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248c0a8
	if (cr6.eq) goto loc_8248C0A8;
loc_8248C09C:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
loc_8248C0A8:
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8248c0c4
	if (!cr6.eq) goto loc_8248C0C4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,228(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 228);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82595580
	ctx.lr = 0x8248C0C4;
	sub_82595580(ctx, base);
loc_8248C0C4:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8248c0d8
	if (cr6.eq) goto loc_8248C0D8;
	// bl 0x824ab670
	ctx.lr = 0x8248C0D4;
	sub_824AB670(ctx, base);
	// b 0x8248c0ec
	goto loc_8248C0EC;
loc_8248C0D8:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,80(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
loc_8248C0EC:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8248c10c
	if (!cr6.eq) goto loc_8248C10C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x8258b598
	ctx.lr = 0x8248C108;
	sub_8258B598(ctx, base);
	// b 0x8248c144
	goto loc_8248C144;
loc_8248C10C:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8248c128
	if (!cr6.eq) goto loc_8248C128;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x8258b630
	ctx.lr = 0x8248C124;
	sub_8258B630(ctx, base);
	// b 0x8248c144
	goto loc_8248C144;
loc_8248C128:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8248c144
	if (!cr6.eq) goto loc_8248C144;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x8258be48
	ctx.lr = 0x8248C144;
	sub_8258BE48(ctx, base);
loc_8248C144:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248C158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8248c198
	if (!cr6.eq) goto loc_8248C198;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248C178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248c198
	if (cr6.eq) goto loc_8248C198;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248C198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248C198:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8248C1AC"))) PPC_WEAK_FUNC(sub_8248C1AC);
PPC_FUNC_IMPL(__imp__sub_8248C1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C1B0"))) PPC_WEAK_FUNC(sub_8248C1B0);
PPC_FUNC_IMPL(__imp__sub_8248C1B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,92(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lbz r10,309(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 309);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248c21c
	if (!cr6.eq) goto loc_8248C21C;
	// lhz r10,220(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 220);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248c21c
	if (!cr6.eq) goto loc_8248C21C;
	// lwz r10,224(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 224);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8248c21c
	if (!cr6.eq) goto loc_8248C21C;
	// lbz r8,303(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 303);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8248c214
	if (!cr6.gt) goto loc_8248C214;
	// lwz r11,212(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 212);
loc_8248C1E8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,152(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248c204
	if (cr6.eq) goto loc_8248C204;
	// lhz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8248c21c
	if (!cr6.eq) goto loc_8248C21C;
loc_8248C204:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8248c1e8
	if (cr6.lt) goto loc_8248C1E8;
loc_8248C214:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8248C21C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8248C224"))) PPC_WEAK_FUNC(sub_8248C224);
PPC_FUNC_IMPL(__imp__sub_8248C224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C228"))) PPC_WEAK_FUNC(sub_8248C228);
PPC_FUNC_IMPL(__imp__sub_8248C228) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8248C230;
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
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248c324
	if (cr6.eq) goto loc_8248C324;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248c324
	if (cr6.eq) goto loc_8248C324;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8248c298
	if (cr6.eq) goto loc_8248C298;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,-23452(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23452);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8248c298
	if (cr6.eq) goto loc_8248C298;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248C298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248C298:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,356(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 356);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248c2b0
	if (cr6.eq) goto loc_8248C2B0;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x8248c2b4
	goto loc_8248C2B4;
loc_8248C2B0:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8248C2B4:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248b1e0
	ctx.lr = 0x8248C2C4;
	sub_8248B1E0(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lvx128 v63,r8,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f11,100(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bl 0x82489770
	ctx.lr = 0x8248C308;
	sub_82489770(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r11,19620(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19620);
	// addi r3,r11,844
	ctx.r3.s64 = r11.s64 + 844;
	// lwz r6,856(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 856);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8248C324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248C324:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8248C32C"))) PPC_WEAK_FUNC(sub_8248C32C);
PPC_FUNC_IMPL(__imp__sub_8248C32C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C330"))) PPC_WEAK_FUNC(sub_8248C330);
PPC_FUNC_IMPL(__imp__sub_8248C330) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8248C34C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c380
	if (cr6.eq) goto loc_8248C380;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,16
	r11.s64 = 16;
	// addi r9,r10,-6900
	ctx.r9.s64 = ctx.r10.s64 + -6900;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C380:
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

__attribute__((alias("__imp__sub_8248C398"))) PPC_WEAK_FUNC(sub_8248C398);
PPC_FUNC_IMPL(__imp__sub_8248C398) {
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
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8248C3B4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c3e4
	if (cr6.eq) goto loc_8248C3E4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-6884
	ctx.r10.s64 = r11.s64 + -6884;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C3E4:
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

__attribute__((alias("__imp__sub_8248C3FC"))) PPC_WEAK_FUNC(sub_8248C3FC);
PPC_FUNC_IMPL(__imp__sub_8248C3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C400"))) PPC_WEAK_FUNC(sub_8248C400);
PPC_FUNC_IMPL(__imp__sub_8248C400) {
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
	ctx.lr = 0x8248C41C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c44c
	if (cr6.eq) goto loc_8248C44C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-6868
	ctx.r10.s64 = r11.s64 + -6868;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C44C:
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

__attribute__((alias("__imp__sub_8248C464"))) PPC_WEAK_FUNC(sub_8248C464);
PPC_FUNC_IMPL(__imp__sub_8248C464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C468"))) PPC_WEAK_FUNC(sub_8248C468);
PPC_FUNC_IMPL(__imp__sub_8248C468) {
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
	ctx.lr = 0x8248C484;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c4b4
	if (cr6.eq) goto loc_8248C4B4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-6852
	ctx.r10.s64 = r11.s64 + -6852;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C4B4:
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

__attribute__((alias("__imp__sub_8248C4CC"))) PPC_WEAK_FUNC(sub_8248C4CC);
PPC_FUNC_IMPL(__imp__sub_8248C4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C4D0"))) PPC_WEAK_FUNC(sub_8248C4D0);
PPC_FUNC_IMPL(__imp__sub_8248C4D0) {
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
	ctx.lr = 0x8248C4EC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c51c
	if (cr6.eq) goto loc_8248C51C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-6836
	ctx.r10.s64 = r11.s64 + -6836;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C51C:
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

__attribute__((alias("__imp__sub_8248C534"))) PPC_WEAK_FUNC(sub_8248C534);
PPC_FUNC_IMPL(__imp__sub_8248C534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C538"))) PPC_WEAK_FUNC(sub_8248C538);
PPC_FUNC_IMPL(__imp__sub_8248C538) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8248C554;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c59c
	if (cr6.eq) goto loc_8248C59C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-6820
	ctx.r10.s64 = r11.s64 + -6820;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C59C:
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

__attribute__((alias("__imp__sub_8248C5B4"))) PPC_WEAK_FUNC(sub_8248C5B4);
PPC_FUNC_IMPL(__imp__sub_8248C5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C5B8"))) PPC_WEAK_FUNC(sub_8248C5B8);
PPC_FUNC_IMPL(__imp__sub_8248C5B8) {
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
	ctx.lr = 0x8248C5D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8248c604
	if (cr6.eq) goto loc_8248C604;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,-6804
	ctx.r10.s64 = r11.s64 + -6804;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8248C604:
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

__attribute__((alias("__imp__sub_8248C61C"))) PPC_WEAK_FUNC(sub_8248C61C);
PPC_FUNC_IMPL(__imp__sub_8248C61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248C620"))) PPC_WEAK_FUNC(sub_8248C620);
PPC_FUNC_IMPL(__imp__sub_8248C620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825a5048
	ctx.lr = 0x8248C63C;
	sub_825A5048(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-7164
	ctx.r9.s64 = ctx.r10.s64 + -7164;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// bl 0x821b5a60
	ctx.lr = 0x8248C65C;
	sub_821B5A60(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r31,96
	r30.s64 = r31.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stw r6,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r6.u32);
	// lwz r11,19620(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19620);
	// addi r3,r11,860
	ctx.r3.s64 = r11.s64 + 860;
	// lwz r5,872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 872);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8248C69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,236(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r8,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f12,100(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f11,104(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// bl 0x82489770
	ctx.lr = 0x8248C6E4;
	sub_82489770(ctx, base);
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r6,r7,0,24,22
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// rlwinm r6,r6,0,22,20
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
	// stw r6,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8248C710"))) PPC_WEAK_FUNC(sub_8248C710);
PPC_FUNC_IMPL(__imp__sub_8248C710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8248C718;
	// stfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r10,r11,20356
	ctx.r10.s64 = r11.s64 + 20356;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248c774
	if (!cr6.eq) goto loc_8248C774;
	// lhz r11,8(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8248c774
	if (cr6.eq) goto loc_8248C774;
	// lwz r11,80(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 80);
	// lwz r23,92(r25)
	r23.u64 = PPC_LOAD_U32(r25.u32 + 92);
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248c788
	if (cr6.eq) goto loc_8248C788;
	// rlwinm r11,r11,0,22,22
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248c7a0
	if (cr6.eq) goto loc_8248C7A0;
loc_8248C774:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_8248C788:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8248c7a0
	if (cr6.eq) goto loc_8248C7A0;
	// lbz r11,307(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 307);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248c774
	if (!cr6.eq) goto loc_8248C774;
loc_8248C7A0:
	// lwz r20,84(r25)
	r20.u64 = PPC_LOAD_U32(r25.u32 + 84);
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// bne cr6,0x8248c858
	if (!cr6.eq) goto loc_8248C858;
	// lbz r11,307(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 307);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248c858
	if (!cr6.eq) goto loc_8248C858;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r10,0(r19)
	PPC_STORE_U8(r19.u32 + 0, ctx.r10.u8);
	// lfs f13,316(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8248c774
	if (cr6.lt) goto loc_8248C774;
	// lwz r11,4(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lhz r10,146(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 146);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8248c81c
	if (!cr6.gt) goto loc_8248C81C;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
loc_8248C7F0:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lfs f10,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// fmadds f8,f10,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fadds f0,f6,f0
	f0.f64 = double(float(ctx.f6.f64 + f0.f64));
	// bne 0x8248c7f0
	if (!cr0.eq) goto loc_8248C7F0;
loc_8248C81C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,19684(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19684);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248c834
	if (cr6.eq) goto loc_8248C834;
	// lfs f12,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
loc_8248C834:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8248c774
	if (cr6.lt) goto loc_8248C774;
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,0(r18)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r18.u32 + 0, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-136(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_8248C858:
	// li r21,0
	r21.s64 = 0;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// addi r22,r20,256
	r22.s64 = r20.s64 + 256;
	// bne cr6,0x8248c86c
	if (!cr6.eq) goto loc_8248C86C;
	// mr r22,r21
	r22.u64 = r21.u64;
loc_8248C86C:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r11,-23452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// lhz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// lhz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 40);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8248c774
	if (cr6.gt) goto loc_8248C774;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8248c898
	if (cr6.eq) goto loc_8248C898;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824a6ff0
	ctx.lr = 0x8248C898;
	sub_824A6FF0(ctx, base);
loc_8248C898:
	// cntlzw r11,r20
	r11.u64 = r20.u32 == 0 ? 32 : __builtin_clz(r20.u32);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// bl 0x824773c0
	ctx.lr = 0x8248C8B8;
	sub_824773C0(ctx, base);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bge cr6,0x8248c8d4
	if (!cr6.lt) goto loc_8248C8D4;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,248(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 248);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248C8D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8248C8D4:
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lbz r11,777(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 777);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248c774
	if (!cr6.eq) goto loc_8248C774;
	// lbz r11,302(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 302);
	// addi r26,r19,4
	r26.s64 = r19.s64 + 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rotlwi r5,r11,3
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 3);
	// bl 0x823d9890
	ctx.lr = 0x8248C8FC;
	sub_823D9890(ctx, base);
	// lwz r9,4(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r24,1
	r24.s64 = 1;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// lhz r11,146(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 146);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8248c9e8
	if (!cr6.gt) goto loc_8248C9E8;
	// mr r29,r11
	r29.u64 = r11.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r30,r21
	r30.u64 = r21.u64;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// addi r28,r11,2384
	r28.s64 = r11.s64 + 2384;
loc_8248C938:
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v61
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vcmpeqfp128. v59,v60,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248c9d8
	if (!cr6.eq) goto loc_8248C9D8;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r11,212(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 212);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lbz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f1,f9
	ctx.f1.f64 = double(float(sqrt(ctx.f9.f64)));
	// beq cr6,0x8248c9b0
	if (cr6.eq) goto loc_8248C9B0;
	// lwz r10,12(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 12);
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r8,r11,27
	ctx.r8.u64 = r11.u32 & 0x1F;
	// slw r7,r24,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r8.u8 & 0x3F));
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r4,r9,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// and r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8248c9d8
	if (!cr6.eq) goto loc_8248C9D8;
loc_8248C9B0:
	// lwz r11,19684(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 19684);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248c9c4
	if (cr6.eq) goto loc_8248C9C4;
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
loc_8248C9C4:
	// li r7,0
	ctx.r7.s64 = 0;
	// fadds f30,f1,f30
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64 + f30.f64));
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8248ab88
	ctx.lr = 0x8248C9D8;
	sub_8248AB88(ctx, base);
loc_8248C9D8:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8248c938
	if (!cr0.eq) goto loc_8248C938;
loc_8248C9E8:
	// lwz r11,80(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 80);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248ca48
	if (!cr6.eq) goto loc_8248CA48;
	// lfs f0,316(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 316);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8248ca48
	if (cr6.lt) goto loc_8248CA48;
	// lwz r11,208(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 208);
	// lfs f13,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f12,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8248ca48
	if (cr6.lt) goto loc_8248CA48;
	// li r11,255
	r11.s64 = 255;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,0(r19)
	PPC_STORE_U8(r19.u32 + 0, r11.u8);
	// lfs f0,316(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 316);
	f0.f64 = double(temp.f32);
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f13,0(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r18.u32 + 0, temp.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-136(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_8248CA48:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lbz r10,307(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 307);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r21,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r21.u32);
	// stw r21,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r21.u32);
	// stw r21,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r21.u32);
	// stw r21,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r21.u32);
	// beq cr6,0x8248cb14
	if (cr6.eq) goto loc_8248CB14;
	// lbz r11,302(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 302);
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8248cb14
	if (cr0.lt) goto loc_8248CB14;
	// rlwinm r30,r31,2,0,29
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
loc_8248CA7C:
	// rlwinm r11,r31,29,3,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0x1FFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// clrlwi r9,r31,27
	ctx.r9.u64 = r31.u32 & 0x1F;
	// slw r8,r24,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8248cb08
	if (!cr6.eq) goto loc_8248CB08;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8249cdd0
	ctx.lr = 0x8248CAA8;
	sub_8249CDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cb08
	if (cr6.eq) goto loc_8248CB08;
	// lwz r7,208(r23)
	ctx.r7.u64 = PPC_LOAD_U32(r23.u32 + 208);
	// lwzx r11,r30,r7
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// lbz r11,69(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 69);
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x8248cb08
	if (cr6.eq) goto loc_8248CB08;
loc_8248CAC8:
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// clrlwi r8,r11,27
	ctx.r8.u64 = r11.u32 & 0x1F;
	// slw r8,r24,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// and r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8248cb08
	if (!cr6.eq) goto loc_8248CB08;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r6,r6,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// or r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 | ctx.r6.u64;
	// lwzx r4,r11,r7
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lbz r11,69(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 69);
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// bne cr6,0x8248cac8
	if (!cr6.eq) goto loc_8248CAC8;
loc_8248CB08:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// bge 0x8248ca7c
	if (!cr0.lt) goto loc_8248CA7C;
loc_8248CB14:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r25,16
	ctx.r4.s64 = r25.s64 + 16;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8249ce60
	ctx.lr = 0x8248CB30;
	sub_8249CE60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cb58
	if (cr6.eq) goto loc_8248CB58;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8248cb50
	if (cr6.eq) goto loc_8248CB50;
	// lbz r11,172(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248cb58
	if (!cr6.eq) goto loc_8248CB58;
loc_8248CB50:
	// mr r29,r24
	r29.u64 = r24.u64;
	// b 0x8248cb5c
	goto loc_8248CB5C;
loc_8248CB58:
	// mr r29,r21
	r29.u64 = r21.u64;
loc_8248CB5C:
	// lbz r30,302(r23)
	r30.u64 = PPC_LOAD_U8(r23.u32 + 302);
	// li r31,255
	r31.s64 = 255;
	// fmr f11,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = f31.f64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8248cda0
	if (!cr6.gt) goto loc_8248CDA0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// lfs f8,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,14196(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14196);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,-31400(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31400);
	ctx.f10.f64 = double(temp.f32);
loc_8248CB94:
	// lfs f12,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x8248cd8c
	if (!cr6.gt) goto loc_8248CD8C;
	// lwz r11,208(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 208);
	// lwzx r5,r11,r4
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	// lfs f0,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8248cbc0
	if (!cr6.lt) goto loc_8248CBC0;
	// lfs f13,56(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// beq cr6,0x8248cd8c
	if (cr6.eq) goto loc_8248CD8C;
loc_8248CBC0:
	// lbz r11,69(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 69);
	// addi r10,r11,-255
	ctx.r10.s64 = r11.s64 + -255;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8248cc10
	if (!cr6.eq) goto loc_8248CC10;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8248cc08
	if (cr6.eq) goto loc_8248CC08;
	// lwz r10,12(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 12);
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r8,r11,27
	ctx.r8.u64 = r11.u32 & 0x1F;
	// slw r11,r24,r8
	r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r8.u8 & 0x3F));
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8248cc10
	if (!cr6.eq) goto loc_8248CC10;
loc_8248CC08:
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// b 0x8248cc14
	goto loc_8248CC14;
loc_8248CC10:
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
loc_8248CC14:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8248cc98
	if (cr6.eq) goto loc_8248CC98;
	// lbz r11,304(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 304);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x8248cc98
	if (!cr6.gt) goto loc_8248CC98;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8248CC34:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8248cc84
	if (cr6.lt) goto loc_8248CC84;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8248cc6c
	if (cr6.eq) goto loc_8248CC6C;
	// lwz r10,12(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 12);
	// rlwinm r28,r11,29,3,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r27,r11,27
	r27.u64 = r11.u32 & 0x1F;
	// slw r27,r24,r27
	r27.u64 = r27.u8 & 0x20 ? 0 : (r24.u32 << (r27.u8 & 0x3F));
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r10,r28,r10
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// and r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// bne cr6,0x8248cc70
	if (!cr6.eq) goto loc_8248CC70;
loc_8248CC6C:
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_8248CC70:
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// blt cr6,0x8248cc34
	if (cr6.lt) goto loc_8248CC34;
	// b 0x8248cc90
	goto loc_8248CC90;
loc_8248CC84:
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// blt cr6,0x8248cc94
	if (cr6.lt) goto loc_8248CC94;
loc_8248CC90:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_8248CC94:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
loc_8248CC98:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248ccc0
	if (!cr6.eq) goto loc_8248CCC0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8248ccb8
	if (cr6.eq) goto loc_8248CCB8;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248ccc0
	if (cr6.eq) goto loc_8248CCC0;
loc_8248CCB8:
	// mr r11,r21
	r11.u64 = r21.u64;
	// b 0x8248ccc4
	goto loc_8248CCC4;
loc_8248CCC0:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8248CCC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cd8c
	if (cr6.eq) goto loc_8248CD8C;
	// rlwinm r11,r6,29,3,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFC;
	// fmr f13,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f10.f64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// clrlwi r9,r6,27
	ctx.r9.u64 = ctx.r6.u32 & 0x1F;
	// slw r8,r24,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// and r11,r8,r7
	r11.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8248cd10
	if (!cr6.eq) goto loc_8248CD10;
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8248cd04
	if (!cr6.gt) goto loc_8248CD04;
	// fdivs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 / f0.f64));
	// b 0x8248cd10
	goto loc_8248CD10;
loc_8248CD04:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8248cd10
	if (!cr6.lt) goto loc_8248CD10;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
loc_8248CD10:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cd24
	if (cr6.eq) goto loc_8248CD24;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8248cd44
	if (cr6.eq) goto loc_8248CD44;
loc_8248CD24:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8248cd70
	if (cr6.eq) goto loc_8248CD70;
	// lwz r11,168(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cd70
	if (cr6.eq) goto loc_8248CD70;
	// lwzx r11,r4,r11
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cd70
	if (cr6.eq) goto loc_8248CD70;
loc_8248CD44:
	// lfs f0,56(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x8248cdcc
	if (!cr6.gt) goto loc_8248CDCC;
	// fdivs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 / f0.f64));
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// ble cr6,0x8248cd70
	if (!cr6.gt) goto loc_8248CD70;
loc_8248CD5C:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x8248cd70
	if (!cr6.gt) goto loc_8248CD70;
	// clrlwi r31,r6,24
	r31.u64 = ctx.r6.u32 & 0xFF;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8248CD70:
	// fcmpu cr6,f13,f8
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f8.f64);
	// ble cr6,0x8248cd8c
	if (!cr6.gt) goto loc_8248CD8C;
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8248cd8c
	if (!cr6.gt) goto loc_8248CD8C;
	// clrlwi r31,r6,24
	r31.u64 = ctx.r6.u32 & 0xFF;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
loc_8248CD8C:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// blt cr6,0x8248cb94
	if (cr6.lt) goto loc_8248CB94;
loc_8248CDA0:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8248c774
	if (cr6.eq) goto loc_8248C774;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,208(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 208);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// beq cr6,0x8248cddc
	if (cr6.eq) goto loc_8248CDDC;
	// lfs f0,56(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	f0.f64 = double(temp.f32);
	// b 0x8248cde0
	goto loc_8248CDE0;
loc_8248CDCC:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8248cd70
	if (cr6.lt) goto loc_8248CD70;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// b 0x8248cd5c
	goto loc_8248CD5C;
loc_8248CDDC:
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
loc_8248CDE0:
	// fdivs f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 / f30.f64));
	// stfs f13,0(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r18.u32 + 0, temp.u32);
	// stb r3,1(r19)
	PPC_STORE_U8(r19.u32 + 1, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r31,0(r19)
	PPC_STORE_U8(r19.u32 + 0, r31.u8);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-136(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8248CE04"))) PPC_WEAK_FUNC(sub_8248CE04);
PPC_FUNC_IMPL(__imp__sub_8248CE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248CE08"))) PPC_WEAK_FUNC(sub_8248CE08);
PPC_FUNC_IMPL(__imp__sub_8248CE08) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8248CE10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248ce74
	if (cr6.eq) goto loc_8248CE74;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248ce74
	if (cr6.eq) goto loc_8248CE74;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lvx128 v63,r8,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f11,100(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bl 0x82489770
	ctx.lr = 0x8248CE74;
	sub_82489770(ctx, base);
loc_8248CE74:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r11,19620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19620);
	// addi r3,r11,844
	ctx.r3.s64 = r11.s64 + 844;
	// lwz r10,856(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 856);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248CE90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r28,r30,256
	r28.s64 = r30.s64 + 256;
	// bne cr6,0x8248cea4
	if (!cr6.eq) goto loc_8248CEA4;
	// li r28,0
	r28.s64 = 0;
loc_8248CEA4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248CEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8248cf18
	if (cr6.eq) goto loc_8248CF18;
	// lwz r11,108(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cf18
	if (cr6.eq) goto loc_8248CF18;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,-23452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8248cf18
	if (!cr6.eq) goto loc_8248CF18;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248CF10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8248CF18:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8248cf74
	if (cr6.eq) goto loc_8248CF74;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821b4de0
	ctx.lr = 0x8248CF28;
	sub_821B4DE0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8248cf74
	if (cr6.eq) goto loc_8248CF74;
	// lwz r11,356(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 356);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248cf5c
	if (cr6.eq) goto loc_8248CF5C;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r30,20(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 20);
	// rotlwi r5,r9,6
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 6);
	// bl 0x8244d5c0
	ctx.lr = 0x8248CF5C;
	sub_8244D5C0(ctx, base);
loc_8248CF5C:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lhz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// bl 0x8248b1e0
	ctx.lr = 0x8248CF74;
	sub_8248B1E0(ctx, base);
loc_8248CF74:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8248CF7C"))) PPC_WEAK_FUNC(sub_8248CF7C);
PPC_FUNC_IMPL(__imp__sub_8248CF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248CF80"))) PPC_WEAK_FUNC(sub_8248CF80);
PPC_FUNC_IMPL(__imp__sub_8248CF80) {
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
	// lhz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x8248d048
	if (cr6.eq) goto loc_8248D048;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,-23452(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// blt cr6,0x8248cfc4
	if (cr6.lt) goto loc_8248CFC4;
	// lhz r11,38(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 38);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8248cfc8
	if (cr6.lt) goto loc_8248CFC8;
loc_8248CFC4:
	// li r11,0
	r11.s64 = 0;
loc_8248CFC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248d048
	if (cr6.eq) goto loc_8248D048;
	// lwz r11,84(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248d048
	if (cr6.eq) goto loc_8248D048;
	// addi r10,r11,256
	ctx.r10.s64 = r11.s64 + 256;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248d048
	if (cr6.eq) goto loc_8248D048;
	// lwz r31,96(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8248d020
	if (cr6.eq) goto loc_8248D020;
	// lwz r11,108(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248d020
	if (cr6.eq) goto loc_8248D020;
	// lwz r10,112(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8248d048
	if (cr6.eq) goto loc_8248D048;
loc_8248D020:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248d048
	if (cr6.eq) goto loc_8248D048;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821b4de0
	ctx.lr = 0x8248D030;
	sub_821B4DE0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// bl 0x8248b1e0
	ctx.lr = 0x8248D048;
	sub_8248B1E0(ctx, base);
loc_8248D048:
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

__attribute__((alias("__imp__sub_8248D060"))) PPC_WEAK_FUNC(sub_8248D060);
PPC_FUNC_IMPL(__imp__sub_8248D060) {
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
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8248D068;
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd534
	ctx.lr = 0x8248D070;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// lhz r11,8(r14)
	r11.u64 = PPC_LOAD_U16(r14.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8248d7b4
	if (cr6.eq) goto loc_8248D7B4;
	// lwz r26,84(r14)
	r26.u64 = PPC_LOAD_U32(r14.u32 + 84);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// beq cr6,0x8248d7b4
	if (cr6.eq) goto loc_8248D7B4;
	// addi r24,r26,256
	r24.s64 = r26.s64 + 256;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8248d7b4
	if (cr6.eq) goto loc_8248D7B4;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x8248d7b4
	if (cr6.eq) goto loc_8248D7B4;
	// lwz r16,92(r14)
	r16.u64 = PPC_LOAD_U32(r14.u32 + 92);
	// lwz r27,96(r24)
	r27.u64 = PPC_LOAD_U32(r24.u32 + 96);
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x8248d7b4
	if (cr6.eq) goto loc_8248D7B4;
	// lwz r18,108(r24)
	r18.u64 = PPC_LOAD_U32(r24.u32 + 108);
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8248d7b4
	if (cr6.eq) goto loc_8248D7B4;
	// lwz r11,212(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 212);
	// li r29,48
	r29.s64 = 48;
	// lbz r17,303(r16)
	r17.u64 = PPC_LOAD_U8(r16.u32 + 303);
	// li r30,16
	r30.s64 = 16;
	// li r31,32
	r31.s64 = 32;
	// li r22,0
	r22.s64 = 0;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,14(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14);
	// extsh r28,r9
	r28.s64 = ctx.r9.s16;
	// ble cr6,0x8248d5d0
	if (!cr6.gt) goto loc_8248D5D0;
	// li r23,0
	r23.s64 = 0;
	// li r19,0
	r19.s64 = 0;
	// li r15,1
	r15.s64 = 1;
	// li r20,256
	r20.s64 = 256;
	// li r21,464
	r21.s64 = 464;
loc_8248D104:
	// lwz r11,212(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 212);
	// lwzx r25,r11,r19
	r25.u64 = PPC_LOAD_U32(r11.u32 + r19.u32);
	// lhz r10,14(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 14);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// ble cr6,0x8248d124
	if (!cr6.gt) goto loc_8248D124;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
loc_8248D124:
	// bge cr6,0x8248d210
	if (!cr6.lt) goto loc_8248D210;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r28,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r9,r28,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
loc_8248D13C:
	// lwz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r6,20(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// add r10,r6,r7
	ctx.r10.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r8,r8,80
	ctx.r8.s64 = ctx.r8.s64 + 80;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// lvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// lvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v11,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vspltw128 v10,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vspltw128 v9,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vspltw128 v8,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v6,r11,r29
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v5,v0,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vmaddfp v4,v0,v13,v6
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v13,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v3,v0,v58
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v2,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vmulfp128 v1,v0,v57
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v31,v60,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// lvx128 v0,r11,r31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v30,v13,v11,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v29,v13,v12,v4
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v28,v13,v10,v3
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v27,v13,v9,v1
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v26,v0,v7,v30
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp v25,v0,v8,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v0,v2,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v0,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r11,14(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 14);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x8248d13c
	if (cr6.lt) goto loc_8248D13C;
loc_8248D210:
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lbz r10,12(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 12);
	// rlwinm r9,r10,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// slw r6,r15,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (r15.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r5,r9,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// and r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 & ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8248d5b8
	if (!cr6.eq) goto loc_8248D5B8;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,116(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 116);
	// bl 0x825aeb50
	ctx.lr = 0x8248D244;
	sub_825AEB50(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8248d4f0
	if (cr6.lt) goto loc_8248D4F0;
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// lwz r10,116(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 116);
	// addi r26,r14,16
	r26.s64 = r14.s64 + 16;
	// lwz r9,176(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 176);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v56,r10,r20
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r26,r29
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r10,r8,r18
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r18.u32);
	// lvx128 v53,r26,r30
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r26
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r10,416
	r11.s64 = ctx.r10.s64 + 416;
	// lvx128 v52,r26,r31
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r10,r21
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v50,v51,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v56.f32)));
	// lvx128 v49,r11,r31
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r11,r29
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v46,v48,v49
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// lvx128 v45,r11,r30
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v44,v48,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v45,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrglw128 v42,v45,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v41,v46,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrglw128 v40,v46,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v39,v44,v42
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vsubfp128 v38,v50,v55
	simde_mm_store_ps(v38.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v55.f32)));
	// vmsum3fp128 v37,v41,v53
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v36,v41,v52
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v35,v41,v54
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v34,v40,v53
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v33,v40,v52
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v61,v39,v54
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v32,v40,v54
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v63,v39,v53
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v62,v39,v52
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v60,v38,v53
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v59,v38,v52
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v58,v38,v54
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v57,v37,v41
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v56,v35,v36
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v55,v34,v40
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v54,v32,v33
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v53,v63,v39
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v52,v61,v62
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v0,v56,v57
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v13,v54,v55
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v51,v60,v50
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v12,v52,v53
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v50,v58,v59
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v11,v50,v51
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// beq cr6,0x8248d324
	if (cr6.eq) goto loc_8248D324;
	// add r11,r23,r9
	r11.u64 = r23.u64 + ctx.r9.u64;
	// b 0x8248d32c
	goto loc_8248D32C;
loc_8248D324:
	// lwz r11,248(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 248);
	// add r11,r11,r23
	r11.u64 = r11.u64 + r23.u64;
loc_8248D32C:
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,144(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 144);
	// lvx128 v48,r11,r30
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v47,v49,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// lvx128 v46,r11,r31
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v45,v48,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// lvx128 v44,r11,r29
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v43,v46,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vspltw128 v10,v44,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v9,v0,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v47.f32)));
	// vspltw128 v8,v49,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xAA));
	// vmulfp128 v7,v0,v45
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v45.f32)));
	// vspltw128 v6,v48,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xAA));
	// vmulfp128 v5,v0,v43
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v43.f32)));
	// vspltw128 v4,v46,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xAA));
	// vmaddfp v3,v0,v10,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v2,v44,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xAA));
	// vspltw128 v42,v49,2
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x55));
	// addi r4,r10,128
	ctx.r4.s64 = ctx.r10.s64 + 128;
	// vspltw128 v41,v48,2
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x55));
	// vspltw128 v40,v46,2
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x55));
	// vspltw128 v39,v44,2
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0x55));
	// vmaddfp v1,v13,v8,v9
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v31,v13,v6,v7
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v30,v13,v4,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v29,v13,v2,v3
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp128 v1,v12,v42,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v42.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp128 v31,v12,v41,v31
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v41.f32)), simde_mm_load_ps(v31.f32)));
	// vmaddfp128 v30,v12,v40,v30
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v40.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp128 v29,v12,v39,v29
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v39.f32)), simde_mm_load_ps(v29.f32)));
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// vor128 v126,v31,v31
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v31.u8));
	// vor128 v125,v30,v30
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)v30.u8));
	// vor128 v124,v29,v29
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_load_si128((simde__m128i*)v29.u8));
	// bl 0x8217c5c8
	ctx.lr = 0x8248D3BC;
	sub_8217C5C8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v0,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v13,r26,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v12,r26,r31
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v24,r26,r29
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v38,v63,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v37,v62,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v36,v61,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v35,v60,0
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v34,v127,v38
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v38.f32)));
	// vspltw128 v33,v63,1
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v32,v127,v37
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v37.f32)));
	// vspltw128 v59,v62,1
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v58,v127,v36
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v36.f32)));
	// vspltw128 v57,v61,1
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmaddfp128 v124,v127,v35,v124
	simde_mm_store_ps(v124.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v35.f32)), simde_mm_load_ps(v124.f32)));
	// vspltw128 v56,v60,1
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vspltw128 v55,v63,2
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v54,v62,2
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v53,v61,2
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vspltw128 v52,v60,2
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmaddfp128 v34,v126,v33,v34
	simde_mm_store_ps(v34.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v33.f32)), simde_mm_load_ps(v34.f32)));
	// vmaddfp128 v32,v126,v59,v32
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v59.f32)), simde_mm_load_ps(v32.f32)));
	// vmaddfp128 v58,v126,v57,v58
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v57.f32)), simde_mm_load_ps(v58.f32)));
	// vmaddfp128 v124,v126,v56,v124
	simde_mm_store_ps(v124.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v56.f32)), simde_mm_load_ps(v124.f32)));
	// vmaddfp128 v34,v125,v55,v34
	simde_mm_store_ps(v34.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v55.f32)), simde_mm_load_ps(v34.f32)));
	// vmaddfp128 v32,v125,v54,v32
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v54.f32)), simde_mm_load_ps(v32.f32)));
	// vmaddfp128 v58,v125,v53,v58
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v53.f32)), simde_mm_load_ps(v58.f32)));
	// vmaddfp128 v124,v125,v52,v124
	simde_mm_store_ps(v124.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v52.f32)), simde_mm_load_ps(v124.f32)));
	// vspltw128 v51,v34,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// vspltw128 v50,v32,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0xFF));
	// vspltw128 v28,v34,1
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xAA));
	// vspltw128 v27,v34,2
	simde_mm_store_si128((simde__m128i*)v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x55));
	// vspltw128 v49,v58,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v26,v0,v51
	simde_mm_store_ps(v26.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v25,v124,0
	simde_mm_store_si128((simde__m128i*)v25.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), 0xFF));
	// vmulfp128 v23,v0,v50
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// vspltw128 v22,v32,1
	simde_mm_store_si128((simde__m128i*)v22.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0xAA));
	// vmulfp128 v20,v0,v49
	simde_mm_store_ps(v20.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v21,v58,1
	simde_mm_store_si128((simde__m128i*)v21.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vmaddfp v18,v0,v25,v24
	simde_mm_store_ps(v18.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v25.f32)), simde_mm_load_ps(v24.f32)));
	// vspltw128 v19,v124,1
	simde_mm_store_si128((simde__m128i*)v19.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), 0xAA));
	// vmaddfp v14,v13,v28,v26
	simde_mm_store_ps(v14.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(v26.f32)));
	// vspltw128 v17,v32,2
	simde_mm_store_si128((simde__m128i*)v17.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x55));
	// vmaddfp v11,v13,v22,v23
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(v23.f32)));
	// vspltw128 v16,v58,2
	simde_mm_store_si128((simde__m128i*)v16.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vspltw128 v15,v124,2
	simde_mm_store_si128((simde__m128i*)v15.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), 0x55));
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// rlwinm r10,r28,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vmaddfp v10,v13,v21,v20
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v21.f32)), simde_mm_load_ps(v20.f32)));
	// vmaddfp v9,v13,v19,v18
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v19.f32)), simde_mm_load_ps(v18.f32)));
	// vmaddfp v0,v12,v27,v14
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(v14.f32)));
	// vmaddfp v13,v12,v17,v11
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v17.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v11,v12,v16,v10
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v16.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v12,v12,v15,v9
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v15.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8248d5b8
	goto loc_8248D5B8;
loc_8248D4F0:
	// lwz r7,4(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r28,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// add r5,r28,r11
	ctx.r5.u64 = r28.u64 + r11.u64;
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// rlwinm r8,r28,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r3,r4,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// lvx128 v48,r11,r29
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r11,r30
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v48,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lvx128 v45,r11,r31
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v44,v47,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// vspltw128 v43,v46,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vspltw128 v42,v45,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// vspltw128 v12,v48,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xAA));
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v11,v47,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xAA));
	// lvx128 v10,r10,r29
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v0,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v44.f32)));
	// vmaddfp v8,v0,v13,v10
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v7,v46,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xAA));
	// vmulfp128 v6,v0,v43
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v43.f32)));
	// vspltw128 v5,v45,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xAA));
	// vmulfp128 v4,v0,v42
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v42.f32)));
	// lvx128 v0,r10,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v48,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x55));
	// lvx128 v13,r10,r31
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v47,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x55));
	// vspltw128 v1,v46,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x55));
	// vspltw128 v31,v45,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0x55));
	// vmaddfp v30,v0,v11,v9
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v29,v0,v12,v8
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v28,v0,v7,v6
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v27,v0,v5,v4
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v26,v13,v2,v30
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp v25,v13,v3,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// stvx128 v26,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248D5B8:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r19,r19,4
	r19.s64 = r19.s64 + 4;
	// addi r23,r23,64
	r23.s64 = r23.s64 + 64;
	// cmpw cr6,r22,r17
	cr6.compare<int32_t>(r22.s32, r17.s32, xer);
	// blt cr6,0x8248d104
	if (cr6.lt) goto loc_8248D104;
loc_8248D5D0:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// bge cr6,0x8248d6c0
	if (!cr6.lt) goto loc_8248D6C0;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r28,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r8,r28,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r9,r28,r10
	ctx.r9.s64 = ctx.r10.s64 - r28.s64;
loc_8248D5F8:
	// lwz r4,4(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r5,20(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// add r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 + ctx.r5.u64;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r7,r7,80
	ctx.r7.s64 = ctx.r7.s64 + 80;
	// addi r6,r6,64
	ctx.r6.s64 = ctx.r6.s64 + 64;
	// lvx128 v41,r11,r29
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v41,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// lwzx r4,r3,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lvx128 v39,r11,r30
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r31
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v37,v40,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// rlwinm r11,r4,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltw128 v36,v39,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// vspltw128 v35,v38,0
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xFF));
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// vspltw128 v12,v41,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xAA));
	// vspltw128 v11,v40,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xAA));
	// vspltw128 v10,v39,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xAA));
	// vspltw128 v9,v38,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xAA));
	// vspltw128 v8,v41,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0x55));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v40,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x55));
	// lvx128 v6,r11,r29
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v5,v0,v37
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v37.f32)));
	// vmaddfp v4,v0,v13,v6
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v13,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v3,v0,v36
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v36.f32)));
	// vspltw128 v2,v39,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0x55));
	// vmulfp128 v1,v0,v35
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v35.f32)));
	// vspltw128 v31,v38,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x55));
	// lvx128 v0,r11,r31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v30,v13,v11,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v29,v13,v12,v4
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v28,v13,v10,v3
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v27,v13,v9,v1
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v26,v0,v7,v30
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp v25,v0,v8,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v0,v2,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v0,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x8248d5f8
	if (!cr0.eq) goto loc_8248D5F8;
loc_8248D6C0:
	// lwz r11,212(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 212);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,14(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8248d788
	if (cr6.eq) goto loc_8248D788;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r3,20(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r4,r11,80
	ctx.r4.s64 = r11.s64 + 80;
	// bl 0x8217c5c8
	ctx.lr = 0x8248D6E4;
	sub_8217C5C8(ctx, base);
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// addi r7,r11,32
	ctx.r7.s64 = r11.s64 + 32;
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// lvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v32,v34,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// lvx128 v33,r0,r9
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v9,v34,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xAA));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v33,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r10,r29
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v10,v0,v32
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v32.f32)));
	// vmaddfp v8,v0,v12,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v7,v33,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xAA));
	// vmulfp128 v6,v0,v61
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v5,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v4,v0,v60
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v3,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vspltw128 v2,v33,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0x55));
	// lvx128 v13,r10,r31
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v34,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x55));
	// vspltw128 v31,v63,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v30,v62,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v0,r10,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v29,v0,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v0,v7,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v0,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v0,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v25,v13,v1,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v2,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v13,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248D788:
	// lwz r11,356(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 356);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248d79c
	if (cr6.eq) goto loc_8248D79C;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x8248d7a0
	goto loc_8248D7A0;
loc_8248D79C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8248D7A0:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r4,20(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lhz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// bl 0x8248b1e0
	ctx.lr = 0x8248D7B4;
	sub_8248B1E0(ctx, base);
loc_8248D7B4:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd7cc
	ctx.lr = 0x8248D7C0;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8248D7C4"))) PPC_WEAK_FUNC(sub_8248D7C4);
PPC_FUNC_IMPL(__imp__sub_8248D7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248D7C8"))) PPC_WEAK_FUNC(sub_8248D7C8);
PPC_FUNC_IMPL(__imp__sub_8248D7C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x8248D7D0;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r18,92(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + 92);
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8248dda0
	if (cr6.eq) goto loc_8248DDA0;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8248D7F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8248dda0
	if (cr6.eq) goto loc_8248DDA0;
	// lwz r10,4(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 4);
	// lwz r11,84(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r17,r11,256
	r17.s64 = r11.s64 + 256;
	// lwz r23,12(r10)
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bne cr6,0x8248d81c
	if (!cr6.eq) goto loc_8248D81C;
	// li r17,0
	r17.s64 = 0;
loc_8248D81C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,64
	ctx.r9.s64 = 64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8248D82C:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8248d82c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8248D82C;
	// addi r11,r17,32
	r11.s64 = r17.s64 + 32;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,48
	ctx.r6.s64 = 48;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r19,1
	r19.s64 = 1;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v57,v59,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r10,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vmaddfp v10,v0,v13,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v9,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v8,v0,v58
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v7,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v6,v0,v57
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v5,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vspltw128 v4,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// lvx128 v0,r10,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v13,r10,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// mr r11,r19
	r11.u64 = r19.u64;
	// vspltw128 v1,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vspltw128 v31,v59,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// vmaddfp v30,v0,v7,v11
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v29,v0,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v0,v5,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v0,v4,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v13,v2,v30
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp v25,v13,v3,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// stvx128 v26,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r9,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,303(r18)
	ctx.r10.u64 = PPC_LOAD_U8(r18.u32 + 303);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8248dc64
	if (!cr6.gt) goto loc_8248DC64;
	// li r24,0
	r24.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// mr r20,r10
	r20.u64 = ctx.r10.u64;
loc_8248D900:
	// lwz r10,212(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 212);
	// lwzx r29,r21,r10
	r29.u64 = PPC_LOAD_U32(r21.u32 + ctx.r10.u32);
	// lhz r9,14(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// extsh r25,r9
	r25.s64 = ctx.r9.s16;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// ble cr6,0x8248d920
	if (!cr6.gt) goto loc_8248D920;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
loc_8248D920:
	// bge cr6,0x8248da04
	if (!cr6.lt) goto loc_8248DA04;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r11,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r10,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r9,r11,r25
	ctx.r9.s64 = r25.s64 - r11.s64;
loc_8248D93C:
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// add r10,r3,r30
	ctx.r10.u64 = ctx.r3.u64 + r30.u64;
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r4,r4,80
	ctx.r4.s64 = ctx.r4.s64 + 80;
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// lvx128 v56,r11,r6
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lwzx r28,r28,r5
	r28.u64 = PPC_LOAD_U32(r28.u32 + ctx.r5.u32);
	// lvx128 v54,r11,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v55,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// rlwinm r11,r28,6,0,25
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltw128 v51,v54,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vspltw128 v50,v53,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// vspltw128 v12,v56,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xAA));
	// vspltw128 v11,v55,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xAA));
	// vspltw128 v10,v54,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xAA));
	// vspltw128 v9,v53,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xAA));
	// vspltw128 v8,v56,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x55));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v55,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x55));
	// lvx128 v6,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v5,v0,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vmaddfp v4,v0,v13,v6
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v13,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v3,v0,v51
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v2,v54,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x55));
	// vmulfp128 v1,v0,v50
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// vspltw128 v31,v53,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x55));
	// lvx128 v0,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v30,v13,v11,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v29,v13,v12,v4
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v28,v13,v10,v3
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v27,v13,v9,v1
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v26,v0,v7,v30
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp v25,v0,v8,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v0,v2,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v0,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x8248d93c
	if (!cr0.eq) goto loc_8248D93C;
loc_8248DA04:
	// lwz r10,84(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 84);
	// lbz r11,12(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8248da68
	if (cr6.eq) goto loc_8248DA68;
	// lwz r10,12(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 12);
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r5,r11,27
	ctx.r5.u64 = r11.u32 & 0x1F;
	// slw r4,r19,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (r19.u32 << (ctx.r5.u8 & 0x3F));
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r11,r9,r3
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// and r10,r11,r4
	ctx.r10.u64 = r11.u64 & ctx.r4.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8248da68
	if (cr6.eq) goto loc_8248DA68;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r10,r25,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltisw128 v49,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_set1_epi32(int(0x0)));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// stvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8248dc50
	goto loc_8248DC50;
loc_8248DA68:
	// rlwinm r26,r25,29,3,29
	r26.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 29) & 0x1FFFFFFC;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// clrlwi r11,r25,27
	r11.u64 = r25.u32 & 0x1F;
	// slw r3,r19,r11
	ctx.r3.u64 = r11.u8 & 0x20 ? 0 : (r19.u32 << (r11.u8 & 0x3F));
	// lwzx r10,r26,r27
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// and r9,r3,r10
	ctx.r9.u64 = ctx.r3.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8248dc50
	if (!cr6.eq) goto loc_8248DC50;
	// lwz r11,144(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// rlwinm r5,r25,6,0,25
	ctx.r5.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// vspltisw128 v48,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r9,r11,128
	ctx.r9.s64 = r11.s64 + 128;
	// lwzx r16,r26,r27
	r16.u64 = PPC_LOAD_U32(r26.u32 + r27.u32);
	// add r11,r5,r10
	r11.u64 = ctx.r5.u64 + ctx.r10.u64;
	// addi r30,r9,48
	r30.s64 = ctx.r9.s64 + 48;
	// addi r29,r9,32
	r29.s64 = ctx.r9.s64 + 32;
	// addi r28,r9,16
	r28.s64 = ctx.r9.s64 + 16;
	// lvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// lvx128 v46,r0,r30
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// lvx128 v45,r0,r29
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// or r16,r3,r16
	r16.u64 = ctx.r3.u64 | r16.u64;
	// lvx128 v44,r0,r28
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v43,v47,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v42,v44,v46
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// addi r3,r22,16
	ctx.r3.s64 = r22.s64 + 16;
	// vmrglw128 v41,v44,v46
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stwx r16,r26,r27
	PPC_STORE_U32(r26.u32 + r27.u32, r16.u32);
	// vmrglw128 v40,v47,v45
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v39,v43,v42
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrglw128 v38,v43,v42
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v37,v40,v41
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// stvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r29
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r0,r28
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r30
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r0,r9
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v32,v33,v34
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmsum3fp128 v63,v36,v34
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmsum3fp128 v62,v35,v34
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmrghw128 v61,v32,v63
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v60,v62,v61
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v59,v61,v60
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v48,v58
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,132(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 132);
	// add r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 + r24.u64;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r9,r6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v57,v57
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// lvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// lvx128 v13,r9,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v6,v53,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xAA));
	// lvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v4,v53,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x55));
	// lvx128 v12,r9,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v10,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v5,v0,v52
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vmaddfp v7,v0,v10,v11
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v9,v56,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xAA));
	// vspltw128 v51,v55,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmaddfp v27,v13,v6,v5
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v8,v56,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x55));
	// vspltw128 v3,v55,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xAA));
	// vspltw128 v50,v54,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vmulfp128 v1,v0,v51
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v2,v54,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xAA));
	// vspltw128 v31,v55,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x55));
	// vspltw128 v30,v54,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x55));
	// vmulfp128 v29,v0,v50
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// vmaddfp v28,v13,v9,v7
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v11,v12,v4,v27
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v26,v13,v3,v1
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v23,v13,v2,v29
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v25,v12,v8,v28
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v28.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v49,v11,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xFF));
	// vmaddfp v0,v12,v31,v26
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v24,v25,0
	simde_mm_store_si128((simde__m128i*)v24.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v25.u32), 0xFF));
	// stvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v48,v0,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xFF));
	// vspltw v18,v0,1
	simde_mm_store_si128((simde__m128i*)v18.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xAA));
	// vspltw v17,v0,2
	simde_mm_store_si128((simde__m128i*)v17.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x55));
	// vmaddfp v0,v12,v30,v23
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v23.f32)));
	// vspltw v21,v11,1
	simde_mm_store_si128((simde__m128i*)v21.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xAA));
	// vspltw v19,v11,2
	simde_mm_store_si128((simde__m128i*)v19.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x55));
	// vspltw v22,v25,1
	simde_mm_store_si128((simde__m128i*)v22.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v25.u32), 0xAA));
	// vspltw v20,v25,2
	simde_mm_store_si128((simde__m128i*)v20.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v25.u32), 0x55));
	// stvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v47,v0,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xFF));
	// lvx128 v16,r3,r6
	simde_mm_store_si128((simde__m128i*)v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v15,v0,1
	simde_mm_store_si128((simde__m128i*)v15.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xAA));
	// lvx128 v12,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v14,v0,2
	simde_mm_store_si128((simde__m128i*)v14.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x55));
	// lvx128 v0,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v13,v49
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v49.f32)));
	// vmaddfp v10,v13,v24,v16
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(v16.f32)));
	// vmulfp128 v9,v13,v48
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v48.f32)));
	// vmulfp128 v8,v13,v47
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v47.f32)));
	// vmaddfp v7,v12,v21,v11
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v21.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v6,v12,v22,v10
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v5,v12,v18,v9
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v18.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v4,v12,v15,v8
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v15.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v3,v0,v19,v7
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v19.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v2,v0,v20,v6
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v20.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v1,v0,v17,v5
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v17.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v31,v0,v14,v4
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v14.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// stvx128 v3,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v1,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v31,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8248DC50:
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// addi r11,r25,1
	r11.s64 = r25.s64 + 1;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r24,r24,64
	r24.s64 = r24.s64 + 64;
	// bne 0x8248d900
	if (!cr0.eq) goto loc_8248D900;
loc_8248DC64:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 20);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8248dd54
	if (!cr6.lt) goto loc_8248DD54;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r11,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r10,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
loc_8248DC8C:
	// lwz r29,4(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// add r10,r3,r30
	ctx.r10.u64 = ctx.r3.u64 + r30.u64;
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r4,80
	ctx.r4.s64 = ctx.r4.s64 + 80;
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// lvx128 v46,r11,r6
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v46,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// lwzx r29,r29,r5
	r29.u64 = PPC_LOAD_U32(r29.u32 + ctx.r5.u32);
	// lvx128 v44,r11,r7
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r11,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v42,v45,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// rlwinm r11,r29,6,0,25
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltw128 v41,v44,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// vspltw128 v40,v43,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// vspltw128 v12,v46,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xAA));
	// vspltw128 v11,v45,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xAA));
	// vspltw128 v10,v44,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xAA));
	// vspltw128 v9,v43,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xAA));
	// vspltw128 v8,v46,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x55));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v45,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0x55));
	// lvx128 v6,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v5,v0,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v42.f32)));
	// vmaddfp v4,v0,v13,v6
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v13,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v3,v0,v41
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v41.f32)));
	// vspltw128 v2,v44,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0x55));
	// vmulfp128 v1,v0,v40
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v40.f32)));
	// vspltw128 v31,v43,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0x55));
	// lvx128 v0,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v30,v13,v11,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v29,v13,v12,v4
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v28,v13,v10,v3
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v27,v13,v9,v1
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v26,v0,v7,v30
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp v25,v0,v8,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v0,v2,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v0,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x8248dc8c
	if (!cr0.eq) goto loc_8248DC8C;
loc_8248DD54:
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// beq cr6,0x8248dda0
	if (cr6.eq) goto loc_8248DDA0;
	// lwz r11,100(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 100);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248dd88
	if (cr6.eq) goto loc_8248DD88;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,20(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 20);
	// rotlwi r5,r9,6
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 6);
	// bl 0x8244d5c0
	ctx.lr = 0x8248DD88;
	sub_8244D5C0(ctx, base);
loc_8248DD88:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lhz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// bl 0x8248b1e0
	ctx.lr = 0x8248DDA0;
	sub_8248B1E0(ctx, base);
loc_8248DDA0:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_8248DDA8"))) PPC_WEAK_FUNC(sub_8248DDA8);
PPC_FUNC_IMPL(__imp__sub_8248DDA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821b5a60
	ctx.lr = 0x8248DDC8;
	sub_821B5A60(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8248DDD0;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248ddfc
	if (cr6.eq) goto loc_8248DDFC;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r10,-6900
	ctx.r8.s64 = ctx.r10.s64 + -6900;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8248de00
	goto loc_8248DE00;
loc_8248DDFC:
	// li r11,0
	r11.s64 = 0;
loc_8248DE00:
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

__attribute__((alias("__imp__sub_8248DE1C"))) PPC_WEAK_FUNC(sub_8248DE1C);
PPC_FUNC_IMPL(__imp__sub_8248DE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8248DE20"))) PPC_WEAK_FUNC(sub_8248DE20);
PPC_FUNC_IMPL(__imp__sub_8248DE20) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821b5a60
	ctx.lr = 0x8248DE40;
	sub_821B5A60(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8248DE48;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8248de70
	if (cr6.eq) goto loc_8248DE70;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r10,-6884
	ctx.r9.s64 = ctx.r10.s64 + -6884;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// b 0x8248de74
	goto loc_8248DE74;
loc_8248DE70:
	// li r11,0
	r11.s64 = 0;
loc_8248DE74:
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

