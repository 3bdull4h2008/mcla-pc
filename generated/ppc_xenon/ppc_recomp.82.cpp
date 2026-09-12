#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8245C868"))) PPC_WEAK_FUNC(sub_8245C868);
PPC_FUNC_IMPL(__imp__sub_8245C868) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8245C870;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r26,156(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// add r27,r26,r25
	r27.u64 = r26.u64 + r25.u64;
	// bgt cr6,0x8245ca78
	if (cr6.gt) goto loc_8245CA78;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bgt cr6,0x8245ca78
	if (cr6.gt) goto loc_8245CA78;
	// li r10,170
	ctx.r10.s64 = 170;
	// addi r11,r27,169
	r11.s64 = r27.s64 + 169;
	// li r28,0
	r28.s64 = 0;
	// divwu r9,r11,r10
	ctx.r9.u32 = r11.u32 / ctx.r10.u32;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x8245c8c0
	if (!cr6.gt) goto loc_8245C8C0;
	// addi r11,r9,169
	r11.s64 = ctx.r9.s64 + 169;
	// li r28,1
	r28.s64 = 1;
	// divwu r11,r11,r10
	r11.u32 = r11.u32 / ctx.r10.u32;
	// b 0x8245c8c4
	goto loc_8245C8C4;
loc_8245C8C0:
	// li r11,0
	r11.s64 = 0;
loc_8245C8C4:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x8245c8dc
	if (!cr6.gt) goto loc_8245C8DC;
	// addi r8,r11,169
	ctx.r8.s64 = r11.s64 + 169;
	// li r28,2
	r28.s64 = 2;
	// divwu r10,r8,r10
	ctx.r10.u32 = ctx.r8.u32 / ctx.r10.u32;
	// b 0x8245c8e0
	goto loc_8245C8E0;
loc_8245C8DC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8245C8E0:
	// lbz r8,205(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 205);
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne 0x8245c930
	if (!cr0.eq) goto loc_8245C930;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// li r7,20
	ctx.r7.s64 = 20;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// rldicl r11,r11,12,20
	r11.u64 = __builtin_rotateleft64(r11.u64, 12) & 0xFFFFFFFFFFF;
	// rldicr r11,r11,0,51
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFFFFFFFF000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// bl 0x827bd9b4
	ctx.lr = 0x8245C928;
	__imp__NtSetInformationFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245ca80
	if (cr0.lt) goto loc_8245CA80;
loc_8245C930:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8245ca5c
	if (cr6.eq) goto loc_8245CA5C;
	// lbz r11,202(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 202);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bge cr6,0x8245ca5c
	if (!cr6.lt) goto loc_8245CA5C;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245be30
	ctx.lr = 0x8245C954;
	sub_8245BE30(ctx, base);
	// lbz r11,202(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 202);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// bgt cr6,0x8245ca5c
	if (cr6.gt) goto loc_8245CA5C;
loc_8245C964:
	// addi r29,r10,1
	r29.s64 = ctx.r10.s64 + 1;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b6f8
	ctx.lr = 0x8245C980;
	sub_8245B6F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245ca80
	if (cr0.lt) goto loc_8245CA80;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r31,176
	ctx.r9.s64 = r31.s64 + 176;
	// li r8,5
	ctx.r8.s64 = 5;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8245C9A0:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8245c9a0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8245C9A0;
	// lwz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwimi r11,r7,0,0,16
	r11.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0xFFFF8000) | (r11.u64 & 0xFFFFFFFF00007FFF);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwimi r4,r11,15,2,16
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 15) & 0x3FFF8000) | (ctx.r4.u64 & 0xFFFFFFFFC0007FFF);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r24,196(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwimi r24,r11,0,1,31
	r24.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x7FFFFFFF) | (r24.u64 & 0xFFFFFFFF80000000);
	// mr r11,r24
	r11.u64 = r24.u64;
	// stw r24,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r24.u32);
	// lwz r24,196(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwimi r11,r24,0,1,1
	r11.u64 = (__builtin_rotateleft32(r24.u32, 0) & 0x40000000) | (r11.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// stw r26,4080(r30)
	PPC_STORE_U32(r30.u32 + 4080, r26.u32);
	// bl 0x827bd8f4
	ctx.lr = 0x8245CA18;
	__imp__XeCryptSha(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r8,1
	ctx.r8.s64 = 1;
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r9,r9,255
	ctx.r9.s64 = ctx.r9.s64 + 255;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwimi r11,r8,31,0,1
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 31) & 0xC0000000) | (r11.u64 & 0xFFFFFFFF3FFFFFFF);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// ble cr6,0x8245c964
	if (!cr6.gt) goto loc_8245C964;
loc_8245CA5C:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r27,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r27.u32);
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// stb r28,202(r31)
	PPC_STORE_U8(r31.u32 + 202, r28.u8);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// b 0x8245ca80
	goto loc_8245CA80;
loc_8245CA78:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,127
	ctx.r3.u64 = ctx.r3.u64 | 127;
loc_8245CA80:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8245CA88"))) PPC_WEAK_FUNC(sub_8245CA88);
PPC_FUNC_IMPL(__imp__sub_8245CA88) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8245CA90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8245b990
	ctx.lr = 0x8245CAB0;
	sub_8245B990(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245cbbc
	if (cr0.lt) goto loc_8245CBBC;
	// lwz r11,156(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 156);
	// subf r10,r30,r11
	ctx.r10.s64 = r11.s64 - r30.s64;
	// cmplwi cr6,r10,170
	cr6.compare<uint32_t>(ctx.r10.u32, 170, xer);
	// ble cr6,0x8245cacc
	if (!cr6.gt) goto loc_8245CACC;
	// li r10,170
	ctx.r10.s64 = 170;
loc_8245CACC:
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + r30.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r6,160(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// bge cr6,0x8245cb94
	if (!cr6.lt) goto loc_8245CB94;
	// addi r7,r28,20
	ctx.r7.s64 = r28.s64 + 20;
loc_8245CAF8:
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// rlwinm. r3,r3,0,0,1
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xC0000000;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8245cb84
	if (!cr0.eq) goto loc_8245CB84;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8245cb58
	if (cr6.eq) goto loc_8245CB58;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// rlwimi r3,r11,0,0,7
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFF000000) | (ctx.r3.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r3,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r3.u32);
	// beq cr6,0x8245cb58
	if (cr6.eq) goto loc_8245CB58;
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
loc_8245CB58:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// oris r11,r11,49152
	r11.u64 = r11.u64 | 3221225472;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// ble cr6,0x8245cb70
	if (!cr6.gt) goto loc_8245CB70;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_8245CB70:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r10,r7,-20
	ctx.r10.s64 = ctx.r7.s64 + -20;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// beq 0x8245cb94
	if (cr0.eq) goto loc_8245CB94;
loc_8245CB84:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r7,r7,24
	ctx.r7.s64 = ctx.r7.s64 + 24;
	// cmplw cr6,r30,r5
	cr6.compare<uint32_t>(r30.u32, ctx.r5.u32, xer);
	// blt cr6,0x8245caf8
	if (cr6.lt) goto loc_8245CAF8;
loc_8245CB94:
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r6,160(r29)
	PPC_STORE_U32(r29.u32 + 160, ctx.r6.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// ble cr6,0x8245cbac
	if (!cr6.gt) goto loc_8245CBAC;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
loc_8245CBAC:
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
loc_8245CBBC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8245CBC4"))) PPC_WEAK_FUNC(sub_8245CBC4);
PPC_FUNC_IMPL(__imp__sub_8245CBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245CBC8"))) PPC_WEAK_FUNC(sub_8245CBC8);
PPC_FUNC_IMPL(__imp__sub_8245CBC8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8245CBD0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-22704
	r11.s64 = r11.s64 + -22704;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r25,-4(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// bl 0x8245b990
	ctx.lr = 0x8245CC04;
	sub_8245B990(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245cda4
	if (cr0.lt) goto loc_8245CDA4;
	// lwz r11,156(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 156);
	// lwz r22,80(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r7,r30,r11
	ctx.r7.s64 = r11.s64 - r30.s64;
	// cmplw cr6,r7,r31
	cr6.compare<uint32_t>(ctx.r7.u32, r31.u32, xer);
	// lwz r11,4080(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 4080);
	// ble cr6,0x8245cc28
	if (!cr6.gt) goto loc_8245CC28;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
loc_8245CC28:
	// subf. r10,r11,r7
	ctx.r10.s64 = ctx.r7.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8245ccd0
	if (cr0.eq) goto loc_8245CCD0;
	// divwu r9,r11,r25
	ctx.r9.u32 = r11.u32 / r25.u32;
	// li r8,170
	ctx.r8.s64 = 170;
	// divwu r6,r11,r25
	ctx.r6.u32 = r11.u32 / r25.u32;
	// divwu r8,r9,r8
	ctx.r8.u32 = ctx.r9.u32 / ctx.r8.u32;
	// mullw r6,r6,r25
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(r25.s32);
	// mulli r8,r8,170
	ctx.r8.s64 = ctx.r8.s64 * 170;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// twllei r25,0
	// mulli r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 * 24;
	// twllei r25,0
	// subf. r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r9,r9,r22
	ctx.r9.u64 = ctx.r9.u64 + r22.u64;
	// beq 0x8245cc90
	if (cr0.eq) goto loc_8245CC90;
	// subf. r11,r11,r25
	r11.s64 = r25.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245cc90
	if (cr0.eq) goto loc_8245CC90;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8245cc78
	if (!cr6.gt) goto loc_8245CC78;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8245CC78:
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwimi r11,r8,0,0,16
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFF8000) | (r11.u64 & 0xFFFFFFFF00007FFF);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
loc_8245CC90:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8245ccc8
	if (cr6.eq) goto loc_8245CCC8;
	// addi r9,r9,20
	ctx.r9.s64 = ctx.r9.s64 + 20;
loc_8245CC9C:
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// ble cr6,0x8245ccac
	if (!cr6.gt) goto loc_8245CCAC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8245CCAC:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// subf. r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwimi r6,r8,0,0,16
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFF8000) | (ctx.r6.u64 & 0xFFFFFFFF00007FFF);
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// bne 0x8245cc9c
	if (!cr0.eq) goto loc_8245CC9C;
loc_8245CCC8:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// stw r7,4080(r22)
	PPC_STORE_U32(r22.u32 + 4080, ctx.r7.u32);
loc_8245CCD0:
	// add r26,r11,r30
	r26.u64 = r11.u64 + r30.u64;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bge cr6,0x8245cd78
	if (!cr6.lt) goto loc_8245CD78;
	// addi r28,r22,20
	r28.s64 = r22.s64 + 20;
loc_8245CCE4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi. r29,r11,17
	r29.u64 = r11.u32 & 0x7FFF;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8245cd68
	if (cr0.eq) goto loc_8245CD68;
	// cmplw cr6,r29,r25
	cr6.compare<uint32_t>(r29.u32, r25.u32, xer);
	// beq cr6,0x8245cd08
	if (cr6.eq) goto loc_8245CD08;
	// subf r11,r30,r26
	r11.s64 = r26.s64 - r30.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x8245cd0c
	if (!cr6.eq) goto loc_8245CD0C;
loc_8245CD08:
	// li r5,1
	ctx.r5.s64 = 1;
loc_8245CD0C:
	// cmplwi cr6,r23,1
	cr6.compare<uint32_t>(r23.u32, 1, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bne cr6,0x8245cd28
	if (!cr6.eq) goto loc_8245CD28;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// bl 0x8245ca88
	ctx.lr = 0x8245CD24;
	sub_8245CA88(ctx, base);
	// b 0x8245cd38
	goto loc_8245CD38;
loc_8245CD28:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// addi r5,r23,-1
	ctx.r5.s64 = r23.s64 + -1;
	// bl 0x8245cbc8
	ctx.lr = 0x8245CD38;
	sub_8245CBC8(ctx, base);
loc_8245CD38:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8245cd78
	if (cr6.lt) goto loc_8245CD78;
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplw cr6,r29,r31
	cr6.compare<uint32_t>(r29.u32, r31.u32, xer);
	// ble cr6,0x8245cd50
	if (!cr6.gt) goto loc_8245CD50;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8245CD50:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// subf. r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// rlwimi r11,r10,0,0,16
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFF8000) | (r11.u64 & 0xFFFFFFFF00007FFF);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// beq 0x8245cd78
	if (cr0.eq) goto loc_8245CD78;
loc_8245CD68:
	// add r30,r25,r30
	r30.u64 = r25.u64 + r30.u64;
	// addi r28,r28,24
	r28.s64 = r28.s64 + 24;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// blt cr6,0x8245cce4
	if (cr6.lt) goto loc_8245CCE4;
loc_8245CD78:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// lwz r10,48(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// lwz r11,52(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 52);
	// subf r11,r11,r22
	r11.s64 = r22.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_8245CDA4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8245CDAC"))) PPC_WEAK_FUNC(sub_8245CDAC);
PPC_FUNC_IMPL(__imp__sub_8245CDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245CDB0"))) PPC_WEAK_FUNC(sub_8245CDB0);
PPC_FUNC_IMPL(__imp__sub_8245CDB0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8245CDB8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// bne cr6,0x8245cde8
	if (!cr6.eq) goto loc_8245CDE8;
	// lis r28,255
	r28.s64 = 16711680;
	// ori r28,r28,65535
	r28.u64 = r28.u64 | 65535;
loc_8245CDE8:
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// blt cr6,0x8245ce1c
	if (cr6.lt) goto loc_8245CE1C;
	// beq cr6,0x8245ce0c
	if (cr6.eq) goto loc_8245CE0C;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// bge cr6,0x8245ce1c
	if (!cr6.lt) goto loc_8245CE1C;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// b 0x8245ce24
	goto loc_8245CE24;
loc_8245CE0C:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8245ce24
	goto loc_8245CE24;
loc_8245CE1C:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_8245CE24:
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8245ce44
	if (!cr6.lt) goto loc_8245CE44;
	// subf r4,r10,r11
	ctx.r4.s64 = r11.s64 - ctx.r10.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245c868
	ctx.lr = 0x8245CE3C;
	sub_8245C868(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245cfcc
	if (cr0.lt) goto loc_8245CFCC;
loc_8245CE44:
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x8245ce54
	if (!cr6.eq) goto loc_8245CE54;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8245cfcc
	goto loc_8245CFCC;
loc_8245CE54:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r8,160(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r9,156(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// li r29,0
	r29.s64 = 0;
	// lbz r11,202(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 202);
	// li r7,1
	ctx.r7.s64 = 1;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r7,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r7.u8);
	// std r29,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r29.u64);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// std r29,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r29.u64);
	// stw r29,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r29.u32);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne 0x8245ceb0
	if (!cr0.eq) goto loc_8245CEB0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ca88
	ctx.lr = 0x8245CEAC;
	sub_8245CA88(ctx, base);
	// b 0x8245cec0
	goto loc_8245CEC0;
loc_8245CEB0:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bl 0x8245cbc8
	ctx.lr = 0x8245CEC0;
	sub_8245CBC8(ctx, base);
loc_8245CEC0:
	// lbz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r29,204(r31)
	PPC_STORE_U8(r31.u32 + 204, r29.u8);
	// beq 0x8245cef4
	if (cr0.eq) goto loc_8245CEF4;
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
loc_8245CED8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andi. r9,r9,247
	ctx.r9.u64 = ctx.r9.u64 & 247;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8245ced8
	if (!cr0.eq) goto loc_8245CED8;
loc_8245CEF4:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8245cf38
	if (cr6.eq) goto loc_8245CF38;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwimi r28,r10,0,0,7
	r28.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFF000000) | (r28.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_8245CF38:
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x8245cfb4
	if (cr6.eq) goto loc_8245CFB4;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b990
	ctx.lr = 0x8245CF58;
	sub_8245B990(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245cfcc
	if (cr0.lt) goto loc_8245CFCC;
	// li r11,170
	r11.s64 = 170;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// divwu r11,r27,r11
	r11.u32 = r27.u32 / r11.u32;
	// mulli r11,r11,170
	r11.s64 = r11.s64 * 170;
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwimi r8,r9,0,8,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFFF) | (ctx.r8.u64 & 0xFFFFFFFFFF000000);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_8245CFB4:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
	// beq cr6,0x8245cfcc
	if (cr6.eq) goto loc_8245CFCC;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8245CFCC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8245CFD4"))) PPC_WEAK_FUNC(sub_8245CFD4);
PPC_FUNC_IMPL(__imp__sub_8245CFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245CFD8"))) PPC_WEAK_FUNC(sub_8245CFD8);
PPC_FUNC_IMPL(__imp__sub_8245CFD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8245CFE0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r19,r7
	r19.u64 = ctx.r7.u64;
	// lwz r11,156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x8245d01c
	if (cr6.lt) goto loc_8245D01C;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r23,r11,50
	r23.u64 = r11.u64 | 50;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8245ae08
	ctx.lr = 0x8245D018;
	sub_8245AE08(ctx, base);
	// b 0x8245d0e4
	goto loc_8245D0E4;
loc_8245D01C:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8245b990
	ctx.lr = 0x8245D030;
	sub_8245B990(ctx, base);
	// mr. r23,r3
	r23.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// blt 0x8245d0e4
	if (cr0.lt) goto loc_8245D0E4;
	// li r27,170
	r27.s64 = 170;
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r11,255
	r11.s64 = 16711680;
	// li r24,0
	r24.s64 = 0;
	// divwu r22,r31,r27
	r22.u32 = r31.u32 / r27.u32;
	// li r25,0
	r25.s64 = 0;
	// ori r28,r11,65535
	r28.u64 = r11.u64 | 65535;
loc_8245D054:
	// divwu r11,r31,r27
	r11.u32 = r31.u32 / r27.u32;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r11,r11,170
	r11.s64 = r11.s64 * 170;
	// subf r11,r11,r31
	r11.s64 = r31.s64 - r11.s64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r4,r11,r26
	ctx.r4.u64 = r11.u64 + r26.u64;
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// clrlwi r31,r11,8
	r31.u64 = r11.u32 & 0xFFFFFF;
	// beq cr6,0x8245d0f0
	if (cr6.eq) goto loc_8245D0F0;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// rlwinm r11,r11,2,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8245d120
	if (cr6.eq) goto loc_8245D120;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x8245d120
	if (cr6.eq) goto loc_8245D120;
loc_8245D09C:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r23,r11,50
	r23.u64 = r11.u64 | 50;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8245ae08
	ctx.lr = 0x8245D0B0;
	sub_8245AE08(ctx, base);
loc_8245D0B0:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// subf r11,r11,r26
	r11.s64 = r26.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stw r24,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r24.u32);
	// stw r25,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r25.u32);
	// stw r31,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r31.u32);
loc_8245D0E4:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_8245D0F0:
	// rlwinm r10,r11,2,30,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x8245d10c
	if (!cr6.eq) goto loc_8245D10C;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// rlwimi r11,r10,30,0,1
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 30) & 0xC0000000) | (r11.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x8245d11c
	goto loc_8245D11C;
loc_8245D10C:
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x8245d09c
	if (!cr6.eq) goto loc_8245D09C;
	// clrlwi r11,r11,2
	r11.u64 = r11.u32 & 0x3FFFFFFF;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
loc_8245D11C:
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
loc_8245D120:
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// or r11,r11,r28
	r11.u64 = r11.u64 | r28.u64;
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8245d144
	if (cr6.eq) goto loc_8245D144;
	// li r5,24
	ctx.r5.s64 = 24;
	// bl 0x823da950
	ctx.lr = 0x8245D140;
	sub_823DA950(ctx, base);
	// mr r31,r28
	r31.u64 = r28.u64;
loc_8245D144:
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x8245d0b0
	if (cr6.eq) goto loc_8245D0B0;
	// divwu r11,r31,r27
	r11.u32 = r31.u32 / r27.u32;
	// cmplw cr6,r11,r22
	cr6.compare<uint32_t>(r11.u32, r22.u32, xer);
	// beq cr6,0x8245d054
	if (cr6.eq) goto loc_8245D054;
	// b 0x8245d0b0
	goto loc_8245D0B0;
}

__attribute__((alias("__imp__sub_8245D15C"))) PPC_WEAK_FUNC(sub_8245D15C);
PPC_FUNC_IMPL(__imp__sub_8245D15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245D160"))) PPC_WEAK_FUNC(sub_8245D160);
PPC_FUNC_IMPL(__imp__sub_8245D160) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8245D168;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-22704
	r11.s64 = r11.s64 + -22704;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,156(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r19,r7
	r19.u64 = ctx.r7.u64;
	// mr r18,r8
	r18.u64 = ctx.r8.u64;
	// lwz r21,0(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// lwz r28,-4(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// blt cr6,0x8245d1c4
	if (cr6.lt) goto loc_8245D1C4;
	// lis r4,-16384
	ctx.r4.s64 = -1073741824;
	// ori r4,r4,50
	ctx.r4.u64 = ctx.r4.u64 | 50;
	// bl 0x8245ae08
	ctx.lr = 0x8245D1B8;
	sub_8245AE08(ctx, base);
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,50
	ctx.r3.u64 = ctx.r3.u64 | 50;
	// b 0x8245d350
	goto loc_8245D350;
loc_8245D1C4:
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8245b990
	ctx.lr = 0x8245D1D8;
	sub_8245B990(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d350
	if (cr0.lt) goto loc_8245D350;
	// lwz r23,92(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// divwu r17,r31,r21
	r17.u32 = r31.u32 / r21.u32;
	// twllei r21,0
	// li r25,0
	r25.s64 = 0;
	// li r24,0
	r24.s64 = 0;
loc_8245D1F4:
	// divwu r11,r31,r28
	r11.u32 = r31.u32 / r28.u32;
	// li r10,170
	ctx.r10.s64 = 170;
	// twllei r28,0
	// divwu r10,r11,r10
	ctx.r10.u32 = r11.u32 / ctx.r10.u32;
	// cmplwi cr6,r27,1
	cr6.compare<uint32_t>(r27.u32, 1, xer);
	// mulli r10,r10,170
	ctx.r10.s64 = ctx.r10.s64 * 170;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r29,r11,r23
	r29.u64 = r11.u64 + r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x8245d23c
	if (!cr6.eq) goto loc_8245D23C;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8245cfd8
	ctx.lr = 0x8245D238;
	sub_8245CFD8(ctx, base);
	// b 0x8245d254
	goto loc_8245D254;
loc_8245D23C:
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r27,-1
	ctx.r5.s64 = r27.s64 + -1;
	// bl 0x8245d160
	ctx.lr = 0x8245D254;
	sub_8245D160(ctx, base);
loc_8245D254:
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x8245d314
	if (cr6.lt) goto loc_8245D314;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// divwu r8,r31,r28
	ctx.r8.u32 = r31.u32 / r28.u32;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// twllei r28,0
	// rlwinm r11,r9,0,0,16
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r10,r10,15,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0xFFFF8000;
	// mullw r8,r8,r28
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(r28.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r8,r31
	ctx.r10.s64 = r31.s64 - ctx.r8.s64;
	// rlwimi r11,r9,0,17,1
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFFFFFC0007FFF) | (r11.u64 & 0x3FFF8000);
	// subf r4,r10,r31
	ctx.r4.s64 = r31.s64 - ctx.r10.s64;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwimi r10,r11,0,0,16
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFF8000) | (ctx.r10.u64 & 0xFFFFFFFF00007FFF);
	// stw r10,20(r29)
	PPC_STORE_U32(r29.u32 + 20, ctx.r10.u32);
	// lwz r11,156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// ble cr6,0x8245d2b4
	if (!cr6.gt) goto loc_8245D2B4;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8245D2B4:
	// rlwinm r9,r10,17,17,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 17) & 0x7FFF;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x8245d2c8
	if (!cr6.eq) goto loc_8245D2C8;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x8245d2d4
	if (cr6.eq) goto loc_8245D2D4;
loc_8245D2C8:
	// clrlwi r10,r10,17
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8245d2e0
	if (!cr6.eq) goto loc_8245D2E0;
loc_8245D2D4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824595d8
	ctx.lr = 0x8245D2E0;
	sub_824595D8(ctx, base);
loc_8245D2E0:
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r31,88(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
	// add r25,r10,r25
	r25.u64 = ctx.r10.u64 + r25.u64;
	// add r24,r11,r24
	r24.u64 = r11.u64 + r24.u64;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// beq cr6,0x8245d314
	if (cr6.eq) goto loc_8245D314;
	// divwu r11,r31,r21
	r11.u32 = r31.u32 / r21.u32;
	// twllei r21,0
	// cmplw cr6,r11,r17
	cr6.compare<uint32_t>(r11.u32, r17.u32, xer);
	// beq cr6,0x8245d1f4
	if (cr6.eq) goto loc_8245D1F4;
loc_8245D314:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// subf r11,r11,r23
	r11.s64 = r23.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stw r25,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r25.u32);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r24,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r24.u32);
	// stw r11,0(r18)
	PPC_STORE_U32(r18.u32 + 0, r11.u32);
loc_8245D350:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8245D358"))) PPC_WEAK_FUNC(sub_8245D358);
PPC_FUNC_IMPL(__imp__sub_8245D358) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r30,0
	r30.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r11,202(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 202);
	// std r30,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r30.u64);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// stb r9,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r9.u8);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bne 0x8245d3b0
	if (!cr0.eq) goto loc_8245D3B0;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8245cfd8
	ctx.lr = 0x8245D3AC;
	sub_8245CFD8(ctx, base);
	// b 0x8245d3c8
	goto loc_8245D3C8;
loc_8245D3B0:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bl 0x8245d160
	ctx.lr = 0x8245D3C8;
	sub_8245D160(ctx, base);
loc_8245D3C8:
	// lbz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stb r30,204(r31)
	PPC_STORE_U8(r31.u32 + 204, r30.u8);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8245d3fc
	if (cr0.eq) goto loc_8245D3FC;
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
loc_8245D3E0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andi. r9,r9,247
	ctx.r9.u64 = ctx.r9.u64 & 247;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8245d3e0
	if (!cr0.eq) goto loc_8245D3E0;
loc_8245D3FC:
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lwz r8,160(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r10,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r10.u32);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
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

__attribute__((alias("__imp__sub_8245D434"))) PPC_WEAK_FUNC(sub_8245D434);
PPC_FUNC_IMPL(__imp__sub_8245D434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245D438"))) PPC_WEAK_FUNC(sub_8245D438);
PPC_FUNC_IMPL(__imp__sub_8245D438) {
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
	ctx.lr = 0x8245D440;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r28,80(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 80);
	// lwz r31,24(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x827bcf64
	ctx.lr = 0x8245D45C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lbz r11,53(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245d474
	if (!cr0.eq) goto loc_8245D474;
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,13
	r30.u64 = r30.u64 | 13;
	// b 0x8245d5fc
	goto loc_8245D5FC;
loc_8245D474:
	// lwz r30,136(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 136);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8245d5fc
	if (!cr6.eq) goto loc_8245D5FC;
	// lbz r11,2(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245d498
	if (cr0.eq) goto loc_8245D498;
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,296
	r30.u64 = r30.u64 | 296;
	// b 0x8245d5fc
	goto loc_8245D5FC;
loc_8245D498:
	// lwz r27,12(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// bne cr6,0x8245d4d8
	if (!cr6.eq) goto loc_8245D4D8;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b060
	ctx.lr = 0x8245D4C0;
	sub_8245B060(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8245d5fc
	if (cr0.lt) goto loc_8245D5FC;
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r27,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r27.u32);
	// li r31,1
	r31.s64 = 1;
	// b 0x8245d4dc
	goto loc_8245D4DC;
loc_8245D4D8:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_8245D4DC:
	// lbz r11,2(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 2);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245d4ec
	if (cr0.eq) goto loc_8245D4EC;
	// stw r25,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r25.u32);
loc_8245D4EC:
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8245c580
	ctx.lr = 0x8245D504;
	sub_8245C580(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8245d53c
	if (!cr0.lt) goto loc_8245D53C;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,52
	r11.u64 = r11.u64 | 52;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x8245d5fc
	if (!cr6.eq) goto loc_8245D5FC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8245d530
	if (cr6.eq) goto loc_8245D530;
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,15
	r30.u64 = r30.u64 | 15;
	// b 0x8245d5fc
	goto loc_8245D5FC;
loc_8245D530:
	// lis r30,-32768
	r30.s64 = -2147483648;
	// ori r30,r30,6
	r30.u64 = r30.u64 | 6;
	// b 0x8245d5fc
	goto loc_8245D5FC;
loc_8245D53C:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245c028
	ctx.lr = 0x8245D548;
	sub_8245C028(ctx, base);
	// lwz r3,152(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r31,28(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// bl 0x8245a410
	ctx.lr = 0x8245D554;
	sub_8245A410(ctx, base);
	// std r3,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r3.u64);
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x8245a410
	ctx.lr = 0x8245D560;
	sub_8245A410(ctx, base);
	// lbz r11,136(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 136);
	// std r3,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r3.u64);
	// rlwinm. r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// std r3,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r3.u64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r3,32(r31)
	PPC_STORE_U64(r31.u32 + 32, ctx.r3.u64);
	// beq 0x8245d590
	if (cr0.eq) goto loc_8245D590;
	// li r11,16
	r11.s64 = 16;
	// std r25,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r25.u64);
	// std r25,48(r31)
	PPC_STORE_U64(r31.u32 + 48, r25.u64);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x8245d5a4
	goto loc_8245D5A4;
loc_8245D590:
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r9,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r9.u32);
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// std r11,48(r31)
	PPC_STORE_U64(r31.u32 + 48, r11.u64);
loc_8245D5A4:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// clrlwi r28,r10,26
	r28.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r11,-64
	r11.s64 = r11.s64 + -64;
	// mr r29,r28
	r29.u64 = r28.u64;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// ble cr6,0x8245d5d0
	if (!cr6.gt) goto loc_8245D5D0;
	// lis r30,-32768
	r30.s64 = -2147483648;
	// mr r29,r11
	r29.u64 = r11.u64;
	// ori r30,r30,5
	r30.u64 = r30.u64 | 5;
	// b 0x8245d5d4
	goto loc_8245D5D4;
loc_8245D5D0:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_8245D5D4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x823da950
	ctx.lr = 0x8245D5E4;
	sub_823DA950(ctx, base);
	// lwz r11,160(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r29,64
	ctx.r10.s64 = r29.s64 + 64;
	// stw r28,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r28.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// stw r10,20(r26)
	PPC_STORE_U32(r26.u32 + 20, ctx.r10.u32);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_8245D5FC:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8245D604;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r30,16(r26)
	PPC_STORE_U32(r26.u32 + 16, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bdb04
	ctx.lr = 0x8245D614;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8245D61C"))) PPC_WEAK_FUNC(sub_8245D61C);
PPC_FUNC_IMPL(__imp__sub_8245D61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245D620"))) PPC_WEAK_FUNC(sub_8245D620);
PPC_FUNC_IMPL(__imp__sub_8245D620) {
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
	ctx.lr = 0x8245D628;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8245d678
	if (cr6.eq) goto loc_8245D678;
loc_8245D640:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245c770
	ctx.lr = 0x8245D650;
	sub_8245C770(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8245d678
	if (cr6.eq) goto loc_8245D678;
	// lis r11,255
	r11.s64 = 16711680;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x8245d678
	if (cr6.eq) goto loc_8245D678;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x8245d640
	if (cr6.lt) goto loc_8245D640;
loc_8245D678:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8245D680"))) PPC_WEAK_FUNC(sub_8245D680);
PPC_FUNC_IMPL(__imp__sub_8245D680) {
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
	ctx.lr = 0x8245D688;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
loc_8245D6A0:
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245D6BC;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d868
	if (cr0.lt) goto loc_8245D868;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r29,92(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8245d6e8
	if (!cr6.eq) goto loc_8245D6E8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245a2a0
	ctx.lr = 0x8245D6E0;
	sub_8245A2A0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245d6f8
	if (!cr0.eq) goto loc_8245D6F8;
loc_8245D6E8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245d620
	ctx.lr = 0x8245D6F8;
	sub_8245D620(ctx, base);
loc_8245D6F8:
	// li r11,170
	r11.s64 = 170;
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// divwu r11,r29,r11
	r11.u32 = r29.u32 / r11.u32;
	// mulli r11,r11,170
	r11.s64 = r11.s64 * 170;
	// subf r28,r11,r29
	r28.s64 = r29.s64 - r11.s64;
	// subfic r11,r28,170
	xer.ca = r28.u32 <= 170;
	r11.s64 = 170 - r28.s64;
	// rlwinm r11,r11,12,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8245d720
	if (!cr6.gt) goto loc_8245D720;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_8245D720:
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// ble cr6,0x8245d72c
	if (!cr6.gt) goto loc_8245D72C;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8245D72C:
	// lis r11,1
	r11.s64 = 65536;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8245d73c
	if (!cr6.gt) goto loc_8245D73C;
	// lis r30,1
	r30.s64 = 65536;
loc_8245D73C:
	// lbz r11,206(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 206);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8245d768
	if (cr0.eq) goto loc_8245D768;
	// rlwinm r11,r30,20,12,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 20) & 0xFFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// bl 0x8245be30
	ctx.lr = 0x8245D760;
	sub_8245BE30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d868
	if (cr0.lt) goto loc_8245D868;
loc_8245D768:
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b7e8
	ctx.lr = 0x8245D77C;
	sub_8245B7E8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d868
	if (cr0.lt) goto loc_8245D868;
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// ld r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rldicl r11,r11,12,20
	r11.u64 = __builtin_rotateleft64(r11.u64, 12) & 0xFFFFFFFFFFF;
	// rldicr r11,r11,0,51
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFFFFFFFF000;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8245aa18
	ctx.lr = 0x8245D7AC;
	sub_8245AA18(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d870
	if (cr0.lt) goto loc_8245D870;
	// mulli r11,r28,24
	r11.s64 = r28.s64 * 24;
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r27,r30,r27
	r27.s64 = r27.s64 - r30.s64;
	// add r25,r30,r25
	r25.u64 = r30.u64 + r25.u64;
	// add r29,r11,r28
	r29.u64 = r11.u64 + r28.u64;
loc_8245D7C8:
	// li r10,20
	ctx.r10.s64 = 20;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd8f4
	ctx.lr = 0x8245D7EC;
	__imp__XeCryptSha(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r8,r29,20
	ctx.r8.s64 = r29.s64 + 20;
loc_8245D7F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8245d818
	if (!cr0.eq) goto loc_8245D818;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x8245d7f8
	if (!cr6.eq) goto loc_8245D7F8;
loc_8245D818:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8245d8a0
	if (!cr0.eq) goto loc_8245D8A0;
	// addic. r30,r30,-4096
	xer.ca = r30.u32 > 4095;
	r30.s64 = r30.s64 + -4096;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,24
	r29.s64 = r29.s64 + 24;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r26,r26,4096
	r26.s64 = r26.s64 + 4096;
	// bne 0x8245d7c8
	if (!cr0.eq) goto loc_8245D7C8;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// bne cr6,0x8245d6a0
	if (!cr6.eq) goto loc_8245D6A0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245D868:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8245D870:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x8245d868
	goto loc_8245D868;
loc_8245D8A0:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r4,-16384
	ctx.r4.s64 = -1073741824;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// ori r4,r4,50
	ctx.r4.u64 = ctx.r4.u64 | 50;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// bl 0x8245ae08
	ctx.lr = 0x8245D8D8;
	sub_8245AE08(ctx, base);
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,50
	ctx.r3.u64 = ctx.r3.u64 | 50;
	// b 0x8245d868
	goto loc_8245D868;
}

__attribute__((alias("__imp__sub_8245D8E4"))) PPC_WEAK_FUNC(sub_8245D8E4);
PPC_FUNC_IMPL(__imp__sub_8245D8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245D8E8"))) PPC_WEAK_FUNC(sub_8245D8E8);
PPC_FUNC_IMPL(__imp__sub_8245D8E8) {
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
	ctx.lr = 0x8245D8F0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
loc_8245D908:
	// clrlwi r26,r27,20
	r26.u64 = r27.u32 & 0xFFF;
	// subfic r31,r26,4096
	xer.ca = r26.u32 <= 4096;
	r31.s64 = 4096 - r26.s64;
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// ble cr6,0x8245d91c
	if (!cr6.gt) goto loc_8245D91C;
	// mr r31,r25
	r31.u64 = r25.u64;
loc_8245D91C:
	// lwz r11,28(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bge cr6,0x8245d9a4
	if (!cr6.lt) goto loc_8245D9A4;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245D944;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d9c8
	if (cr0.lt) goto loc_8245D9C8;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245bc28
	ctx.lr = 0x8245D95C;
	sub_8245BC28(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245d9c8
	if (cr0.lt) goto loc_8245D9C8;
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r30,r26
	ctx.r4.u64 = r30.u64 + r26.u64;
	// bl 0x823da950
	ctx.lr = 0x8245D978;
	sub_823DA950(ctx, base);
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x8245d9b4
	goto loc_8245D9B4;
loc_8245D9A4:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d9890
	ctx.lr = 0x8245D9B4;
	sub_823D9890(ctx, base);
loc_8245D9B4:
	// subf. r25,r31,r25
	r25.s64 = r25.s64 - r31.s64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// add r28,r31,r28
	r28.u64 = r31.u64 + r28.u64;
	// add r27,r31,r27
	r27.u64 = r31.u64 + r27.u64;
	// bne 0x8245d908
	if (!cr0.eq) goto loc_8245D908;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245D9C8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8245D9D0"))) PPC_WEAK_FUNC(sub_8245D9D0);
PPC_FUNC_IMPL(__imp__sub_8245D9D0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8245D9D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// clrlwi. r11,r31,20
	r11.u64 = r31.u32 & 0xFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245da18
	if (cr0.eq) goto loc_8245DA18;
	// subfic r27,r11,4096
	xer.ca = r11.u32 <= 4096;
	r27.s64 = 4096 - r11.s64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x8245d8e8
	ctx.lr = 0x8245DA04;
	sub_8245D8E8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245db14
	if (cr0.lt) goto loc_8245DB14;
	// add r30,r27,r30
	r30.u64 = r27.u64 + r30.u64;
	// subf r29,r27,r29
	r29.s64 = r29.s64 - r27.s64;
	// add r31,r27,r31
	r31.u64 = r27.u64 + r31.u64;
loc_8245DA18:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245DA34;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245db14
	if (cr0.lt) goto loc_8245DB14;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82459680
	ctx.lr = 0x8245DA54;
	sub_82459680(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8245dab0
	if (cr0.eq) goto loc_8245DAB0;
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x8245DA70;
	sub_823DA950(ctx, base);
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// lwz r10,48(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// addi r29,r29,-4096
	r29.s64 = r29.s64 + -4096;
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// addi r30,r30,4096
	r30.s64 = r30.s64 + 4096;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addi r31,r31,4096
	r31.s64 = r31.s64 + 4096;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// cmplwi cr6,r29,4096
	cr6.compare<uint32_t>(r29.u32, 4096, xer);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// bge cr6,0x8245da18
	if (!cr6.lt) goto loc_8245DA18;
	// b 0x8245dae8
	goto loc_8245DAE8;
loc_8245DAB0:
	// cmplwi cr6,r29,4096
	cr6.compare<uint32_t>(r29.u32, 4096, xer);
	// blt cr6,0x8245dae8
	if (cr6.lt) goto loc_8245DAE8;
	// rlwinm r27,r29,0,0,19
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFF000;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8245d680
	ctx.lr = 0x8245DAD4;
	sub_8245D680(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245db14
	if (cr0.lt) goto loc_8245DB14;
	// add r30,r27,r30
	r30.u64 = r27.u64 + r30.u64;
	// subf r29,r27,r29
	r29.s64 = r29.s64 - r27.s64;
	// add r31,r27,r31
	r31.u64 = r27.u64 + r31.u64;
loc_8245DAE8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8245db10
	if (cr6.eq) goto loc_8245DB10;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8245d8e8
	ctx.lr = 0x8245DB08;
	sub_8245D8E8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245db14
	if (cr0.lt) goto loc_8245DB14;
loc_8245DB10:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245DB14:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8245DB1C"))) PPC_WEAK_FUNC(sub_8245DB1C);
PPC_FUNC_IMPL(__imp__sub_8245DB1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245DB20"))) PPC_WEAK_FUNC(sub_8245DB20);
PPC_FUNC_IMPL(__imp__sub_8245DB20) {
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
	ctx.lr = 0x8245DB28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,14504
	ctx.r10.s64 = r11.s64 + 14504;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r28,80(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// lwz r24,24(r28)
	r24.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r27,8(r24)
	r27.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// bl 0x827bcf64
	ctx.lr = 0x8245DB5C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,136(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8245db70
	if (cr6.eq) goto loc_8245DB70;
	// mr r30,r11
	r30.u64 = r11.u64;
	// b 0x8245dc88
	goto loc_8245DC88;
loc_8245DB70:
	// lbz r11,2(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 2);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245db88
	if (cr0.eq) goto loc_8245DB88;
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,296
	r30.u64 = r30.u64 | 296;
	// b 0x8245dc88
	goto loc_8245DC88;
loc_8245DB88:
	// lbz r11,53(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245dba0
	if (cr0.eq) goto loc_8245DBA0;
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,16
	r30.u64 = r30.u64 | 16;
	// b 0x8245dc88
	goto loc_8245DC88;
loc_8245DBA0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8245dbb4
	if (!cr6.eq) goto loc_8245DBB4;
	// li r30,0
	r30.s64 = 0;
	// stw r30,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r30.u32);
	// b 0x8245dc88
	goto loc_8245DC88;
loc_8245DBB4:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r30,16(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8245dc80
	if (!cr6.eq) goto loc_8245DC80;
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bge cr6,0x8245dc80
	if (!cr6.lt) goto loc_8245DC80;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x8245dbe0
	if (cr6.lt) goto loc_8245DBE0;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8245DBE0:
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// add r25,r30,r31
	r25.u64 = r30.u64 + r31.u64;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bgt cr6,0x8245dc28
	if (cr6.gt) goto loc_8245DC28;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,28(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x8245a318
	ctx.lr = 0x8245DC04;
	sub_8245A318(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245dc28
	if (!cr0.eq) goto loc_8245DC28;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245d9d0
	ctx.lr = 0x8245DC24;
	sub_8245D9D0(ctx, base);
	// b 0x8245dc40
	goto loc_8245DC40;
loc_8245DC28:
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245d8e8
	ctx.lr = 0x8245DC40;
	sub_8245D8E8(ctx, base);
loc_8245DC40:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8245dc6c
	if (cr6.lt) goto loc_8245DC6C;
	// lbz r11,2(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 2);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245dc64
	if (cr0.eq) goto loc_8245DC64;
	// li r11,0
	r11.s64 = 0;
	// stw r25,24(r24)
	PPC_STORE_U32(r24.u32 + 24, r25.u32);
	// stw r11,20(r24)
	PPC_STORE_U32(r24.u32 + 20, r11.u32);
loc_8245DC64:
	// stw r31,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r31.u32);
	// b 0x8245dc88
	goto loc_8245DC88;
loc_8245DC6C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8245DC7C;
	sub_823D9890(ctx, base);
	// b 0x8245dc88
	goto loc_8245DC88;
loc_8245DC80:
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,17
	r30.u64 = r30.u64 | 17;
loc_8245DC88:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8245DC90;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r30,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bdb04
	ctx.lr = 0x8245DCA0;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8245DCA8"))) PPC_WEAK_FUNC(sub_8245DCA8);
PPC_FUNC_IMPL(__imp__sub_8245DCA8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8245DCB0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// add r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r10,4095
	ctx.r10.s64 = ctx.r10.s64 + 4095;
	// li r21,0
	r21.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r28,r10,0,0,19
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r29,r6,0,0,19
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFF000;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// ble cr6,0x8245dce8
	if (!cr6.gt) goto loc_8245DCE8;
	// subf r10,r11,r28
	ctx.r10.s64 = r28.s64 - r11.s64;
	// mr r28,r11
	r28.u64 = r11.u64;
	// rlwinm r21,r10,20,12,31
	r21.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
loc_8245DCE8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// ble cr6,0x8245dcf8
	if (!cr6.gt) goto loc_8245DCF8;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8245DCF8:
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// ble cr6,0x8245dd04
	if (!cr6.gt) goto loc_8245DD04;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_8245DD04:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8245dd18
	if (!cr6.eq) goto loc_8245DD18;
	// subf r11,r29,r28
	r11.s64 = r28.s64 - r29.s64;
	// cmplwi cr6,r11,4096
	cr6.compare<uint32_t>(r11.u32, 4096, xer);
	// beq cr6,0x8245de84
	if (cr6.eq) goto loc_8245DE84;
loc_8245DD18:
	// subf r11,r29,r28
	r11.s64 = r28.s64 - r29.s64;
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// lwz r9,160(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// rlwinm r11,r11,20,12,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x8245de84
	if (!cr6.gt) goto loc_8245DE84;
	// lwz r25,40(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r22,r29
	r22.u64 = r29.u64;
	// lwz r24,44(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r23,48(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// b 0x8245de34
	goto loc_8245DE34;
loc_8245DD4C:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245DD68;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245de88
	if (cr0.lt) goto loc_8245DE88;
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245b7e8
	ctx.lr = 0x8245DD88;
	sub_8245B7E8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245de88
	if (cr0.lt) goto loc_8245DE88;
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r11,170
	r11.s64 = 170;
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// divwu r11,r26,r11
	r11.u32 = r26.u32 / r11.u32;
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// subf r10,r10,r27
	ctx.r10.s64 = r27.s64 - ctx.r10.s64;
	// mulli r11,r11,170
	r11.s64 = r11.s64 * 170;
	// srawi r10,r10,12
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 12;
	// subf r11,r11,r26
	r11.s64 = r26.s64 - r11.s64;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,7(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// rlwinm r11,r11,2,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3;
	// rlwinm. r9,r9,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8245dde8
	if (!cr0.eq) goto loc_8245DDE8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8245dde8
	if (!cr6.eq) goto loc_8245DDE8;
	// li r11,2
	r11.s64 = 2;
loc_8245DDE8:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8245de08
	if (!cr6.eq) goto loc_8245DE08;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// cmplw cr6,r29,r22
	cr6.compare<uint32_t>(r29.u32, r22.u32, xer);
	// bne cr6,0x8245de24
	if (!cr6.eq) goto loc_8245DE24;
	// cmplw cr6,r22,r25
	cr6.compare<uint32_t>(r22.u32, r25.u32, xer);
	// bge cr6,0x8245de24
	if (!cr6.lt) goto loc_8245DE24;
	// b 0x8245de18
	goto loc_8245DE18;
loc_8245DE08:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8245de90
	if (!cr6.eq) goto loc_8245DE90;
	// cmplw cr6,r29,r22
	cr6.compare<uint32_t>(r29.u32, r22.u32, xer);
	// bne cr6,0x8245de24
	if (!cr6.eq) goto loc_8245DE24;
loc_8245DE18:
	// lwz r23,48(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r24,44(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r25,40(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_8245DE24:
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// addi r29,r29,4096
	r29.s64 = r29.s64 + 4096;
	// addi r11,r11,255
	r11.s64 = r11.s64 + 255;
	// stb r11,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, r11.u8);
loc_8245DE34:
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// blt cr6,0x8245dd4c
	if (cr6.lt) goto loc_8245DD4C;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// beq cr6,0x8245de54
	if (cr6.eq) goto loc_8245DE54;
	// stw r25,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r25.u32);
	// stw r24,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r24.u32);
	// stw r23,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r23.u32);
loc_8245DE54:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8245de84
	if (cr6.eq) goto loc_8245DE84;
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// add r10,r21,r10
	ctx.r10.u64 = r21.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8245de84
	if (!cr6.lt) goto loc_8245DE84;
	// subf r4,r11,r10
	ctx.r4.s64 = ctx.r10.s64 - r11.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245c868
	ctx.lr = 0x8245DE7C;
	sub_8245C868(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245de88
	if (cr0.lt) goto loc_8245DE88;
loc_8245DE84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245DE88:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
loc_8245DE90:
	// lis r4,-16384
	ctx.r4.s64 = -1073741824;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,50
	ctx.r4.u64 = ctx.r4.u64 | 50;
	// bl 0x8245ae08
	ctx.lr = 0x8245DEA0;
	sub_8245AE08(ctx, base);
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// ori r3,r3,50
	ctx.r3.u64 = ctx.r3.u64 | 50;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x8245de88
	goto loc_8245DE88;
}

__attribute__((alias("__imp__sub_8245DED4"))) PPC_WEAK_FUNC(sub_8245DED4);
PPC_FUNC_IMPL(__imp__sub_8245DED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245DED8"))) PPC_WEAK_FUNC(sub_8245DED8);
PPC_FUNC_IMPL(__imp__sub_8245DED8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8245DEE0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r25,r5,0,0,19
	r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFF000;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r19,r7
	r19.u64 = ctx.r7.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r26,40(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lwz r24,44(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r23,48(r30)
	r23.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245DF20;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e274
	if (cr0.lt) goto loc_8245E274;
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b990
	ctx.lr = 0x8245DF44;
	sub_8245B990(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e274
	if (cr0.lt) goto loc_8245E274;
	// li r11,170
	r11.s64 = 170;
	// lwz r29,0(r21)
	r29.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// divwu r11,r27,r11
	r11.u32 = r27.u32 / r11.u32;
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// mulli r11,r11,170
	r11.s64 = r11.s64 * 170;
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r28,r11,r29
	r28.u64 = r11.u64 + r29.u64;
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// rlwinm r10,r11,2,30,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3;
	// bne cr6,0x8245e008
	if (!cr6.eq) goto loc_8245E008;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// beq cr6,0x8245dfd0
	if (cr6.eq) goto loc_8245DFD0;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// beq cr6,0x8245dfd0
	if (cr6.eq) goto loc_8245DFD0;
	// lis r4,-16384
	ctx.r4.s64 = -1073741824;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,50
	ctx.r4.u64 = ctx.r4.u64 | 50;
	// bl 0x8245ae08
	ctx.lr = 0x8245DF9C;
	sub_8245AE08(ctx, base);
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,50
	ctx.r3.u64 = ctx.r3.u64 | 50;
loc_8245DFA4:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r11,r11,r29
	r11.s64 = r29.s64 - r11.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// b 0x8245e274
	goto loc_8245E274;
loc_8245DFD0:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b6f8
	ctx.lr = 0x8245DFE8;
	sub_8245B6F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245dfa4
	if (cr0.lt) goto loc_8245DFA4;
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// oris r11,r11,49152
	r11.u64 = r11.u64 | 3221225472;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// stw r27,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r27.u32);
	// b 0x8245e274
	goto loc_8245E274;
loc_8245E008:
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x8245e050
	if (!cr6.eq) goto loc_8245E050;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8245e034
	if (cr6.eq) goto loc_8245E034;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8245b6f8
	ctx.lr = 0x8245E030;
	sub_8245B6F8(ctx, base);
	// b 0x8245e03c
	goto loc_8245E03C;
loc_8245E034:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x8245bd28
	ctx.lr = 0x8245E03C;
	sub_8245BD28(ctx, base);
loc_8245E03C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8245dfa4
	if (cr6.lt) goto loc_8245DFA4;
	// stw r27,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r27.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8245e274
	goto loc_8245E274;
loc_8245E050:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// clrlwi r28,r11,8
	r28.u64 = r11.u32 & 0xFFFFFF;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r11,r9,r29
	r11.s64 = r29.s64 - ctx.r9.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// beq cr6,0x8245e0a0
	if (cr6.eq) goto loc_8245E0A0;
	// lis r4,-16384
	ctx.r4.s64 = -1073741824;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,50
	ctx.r4.u64 = ctx.r4.u64 | 50;
	// bl 0x8245ae08
	ctx.lr = 0x8245E094;
	sub_8245AE08(ctx, base);
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,50
	ctx.r3.u64 = ctx.r3.u64 | 50;
	// b 0x8245e274
	goto loc_8245E274;
loc_8245E0A0:
	// li r6,-1
	ctx.r6.s64 = -1;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// beq cr6,0x8245e0fc
	if (cr6.eq) goto loc_8245E0FC;
	// addi r5,r25,-4096
	ctx.r5.s64 = r25.s64 + -4096;
	// cmplw cr6,r5,r26
	cr6.compare<uint32_t>(ctx.r5.u32, r26.u32, xer);
	// blt cr6,0x8245e0d8
	if (cr6.lt) goto loc_8245E0D8;
	// add r11,r24,r26
	r11.u64 = r24.u64 + r26.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bge cr6,0x8245e0d8
	if (!cr6.lt) goto loc_8245E0D8;
	// subf r11,r26,r5
	r11.s64 = ctx.r5.s64 - r26.s64;
	// rlwinm r11,r11,20,12,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// add r6,r11,r23
	ctx.r6.u64 = r11.u64 + r23.u64;
	// b 0x8245e0fc
	goto loc_8245E0FC;
loc_8245E0D8:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245E0F0;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e274
	if (cr0.lt) goto loc_8245E274;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8245E0FC:
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r5,r11,31,30,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x2;
	// bl 0x8245cdb0
	ctx.lr = 0x8245E11C;
	sub_8245CDB0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e274
	if (cr0.lt) goto loc_8245E274;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x8245e138
	if (!cr6.eq) goto loc_8245E138;
	// stw r29,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r29.u32);
loc_8245E138:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x8245e148
	if (!cr6.eq) goto loc_8245E148;
	// stw r29,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r29.u32);
loc_8245E148:
	// add r11,r24,r26
	r11.u64 = r24.u64 + r26.u64;
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// bne cr6,0x8245e174
	if (!cr6.eq) goto loc_8245E174;
	// rlwinm r11,r24,20,12,31
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 20) & 0xFFFFF;
	// add r11,r11,r23
	r11.u64 = r11.u64 + r23.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x8245e174
	if (!cr6.eq) goto loc_8245E174;
	// addi r11,r24,4096
	r11.s64 = r24.s64 + 4096;
	// stw r26,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r26.u32);
	// stw r23,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r23.u32);
	// b 0x8245e180
	goto loc_8245E180;
loc_8245E174:
	// li r11,4096
	r11.s64 = 4096;
	// stw r25,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r25.u32);
	// stw r29,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r29.u32);
loc_8245E180:
	// stw r11,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r11.u32);
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8245e1a0
	if (cr0.eq) goto loc_8245E1A0;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// b 0x8245e1a8
	goto loc_8245E1A8;
loc_8245E1A0:
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,53(r30)
	PPC_STORE_U8(r30.u32 + 53, r11.u8);
loc_8245E1A8:
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245d358
	ctx.lr = 0x8245E1BC;
	sub_8245D358(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e274
	if (cr0.lt) goto loc_8245E274;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8245e1e8
	if (cr6.eq) goto loc_8245E1E8;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8245b6f8
	ctx.lr = 0x8245E1E4;
	sub_8245B6F8(ctx, base);
	// b 0x8245e1f8
	goto loc_8245E1F8;
loc_8245E1E8:
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x8245bda0
	ctx.lr = 0x8245E1F8;
	sub_8245BDA0(ctx, base);
loc_8245E1F8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8245e270
	if (cr6.lt) goto loc_8245E270;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x8245e224
	if (!cr6.eq) goto loc_8245E224;
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245e224
	if (cr0.eq) goto loc_8245E224;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r5,0(r22)
	ctx.r5.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245a5c8
	ctx.lr = 0x8245E224;
	sub_8245A5C8(ctx, base);
loc_8245E224:
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245b990
	ctx.lr = 0x8245E23C;
	sub_8245B990(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8245e270
	if (!cr0.lt) goto loc_8245E270;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// srawi r11,r11,12
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFF) != 0);
	r11.s64 = r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_8245E270:
	// stw r29,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r29.u32);
loc_8245E274:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8245E27C"))) PPC_WEAK_FUNC(sub_8245E27C);
PPC_FUNC_IMPL(__imp__sub_8245E27C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E280"))) PPC_WEAK_FUNC(sub_8245E280);
PPC_FUNC_IMPL(__imp__sub_8245E280) {
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
	ctx.lr = 0x8245E288;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// addi r4,r31,56
	ctx.r4.s64 = r31.s64 + 56;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8245ded8
	ctx.lr = 0x8245E2B8;
	sub_8245DED8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e2e4
	if (cr0.lt) goto loc_8245E2E4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r10,r30,20
	ctx.r10.u64 = r30.u32 & 0xFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8245e2e4
	if (!cr6.eq) goto loc_8245E2E4;
	// addi r11,r11,4096
	r11.s64 = r11.s64 + 4096;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
loc_8245E2E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8245E2EC"))) PPC_WEAK_FUNC(sub_8245E2EC);
PPC_FUNC_IMPL(__imp__sub_8245E2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E2F0"))) PPC_WEAK_FUNC(sub_8245E2F0);
PPC_FUNC_IMPL(__imp__sub_8245E2F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8245E2F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// lhz r11,54(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 54);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rotlwi r4,r11,6
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 6);
	// bl 0x8245e280
	ctx.lr = 0x8245E324;
	sub_8245E280(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x8245e360
	if (cr0.lt) goto loc_8245E360;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245a758
	ctx.lr = 0x8245E33C;
	sub_8245A758(ctx, base);
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// andi. r11,r11,207
	r11.u64 = r11.u64 & 207;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
	// bl 0x8245a6b0
	ctx.lr = 0x8245E360;
	sub_8245A6B0(ctx, base);
loc_8245E360:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8245E36C"))) PPC_WEAK_FUNC(sub_8245E36C);
PPC_FUNC_IMPL(__imp__sub_8245E36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E370"))) PPC_WEAK_FUNC(sub_8245E370);
PPC_FUNC_IMPL(__imp__sub_8245E370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8245E378;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245e398
	if (cr0.eq) goto loc_8245E398;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8245e3e4
	goto loc_8245E3E4;
loc_8245E398:
	// lhz r11,54(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 54);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// rotlwi r4,r11,6
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 6);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e280
	ctx.lr = 0x8245E3B8;
	sub_8245E280(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245e3e0
	if (cr0.lt) goto loc_8245E3E0;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
	// bl 0x8245a6b0
	ctx.lr = 0x8245E3E0;
	sub_8245A6B0(ctx, base);
loc_8245E3E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8245E3E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8245E3EC"))) PPC_WEAK_FUNC(sub_8245E3EC);
PPC_FUNC_IMPL(__imp__sub_8245E3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E3F0"))) PPC_WEAK_FUNC(sub_8245E3F0);
PPC_FUNC_IMPL(__imp__sub_8245E3F0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8245d358
	ctx.lr = 0x8245E414;
	sub_8245D358(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e44c
	if (cr0.lt) goto loc_8245E44C;
	// lbz r9,53(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// ori r9,r9,16
	ctx.r9.u64 = ctx.r9.u64 | 16;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stb r9,53(r31)
	PPC_STORE_U8(r31.u32 + 53, ctx.r9.u8);
loc_8245E44C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8245E460"))) PPC_WEAK_FUNC(sub_8245E460);
PPC_FUNC_IMPL(__imp__sub_8245E460) {
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
	ctx.lr = 0x8245E468;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r30,-1
	ctx.r5.s64 = r30.s64 + -1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8245c278
	ctx.lr = 0x8245E48C;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e4f4
	if (cr0.lt) goto loc_8245E4F4;
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245d358
	ctx.lr = 0x8245E4AC;
	sub_8245D358(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e4f4
	if (cr0.lt) goto loc_8245E4F4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r28,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r28.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// ble cr6,0x8245e4d4
	if (!cr6.gt) goto loc_8245E4D4;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
loc_8245E4D4:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// ble cr6,0x8245e4e4
	if (!cr6.gt) goto loc_8245E4E4;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
loc_8245E4E4:
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
loc_8245E4F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8245E4FC"))) PPC_WEAK_FUNC(sub_8245E4FC);
PPC_FUNC_IMPL(__imp__sub_8245E4FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E500"))) PPC_WEAK_FUNC(sub_8245E500);
PPC_FUNC_IMPL(__imp__sub_8245E500) {
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
	ctx.lr = 0x8245E508;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// beq cr6,0x8245e558
	if (cr6.eq) goto loc_8245E558;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// bne cr6,0x8245e558
	if (!cr6.eq) goto loc_8245E558;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r30,-1
	ctx.r5.s64 = r30.s64 + -1;
	// bl 0x8245c278
	ctx.lr = 0x8245E548;
	sub_8245C278(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e5ec
	if (cr0.lt) goto loc_8245E5EC;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
loc_8245E558:
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// lbz r10,53(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r29,r11,20,12,31
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// li r7,-1
	ctx.r7.s64 = -1;
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8245cdb0
	ctx.lr = 0x8245E580;
	sub_8245CDB0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e5ec
	if (cr0.lt) goto loc_8245E5EC;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// bne cr6,0x8245e5c4
	if (!cr6.eq) goto loc_8245E5C4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// cmplw cr6,r10,r29
	cr6.compare<uint32_t>(ctx.r10.u32, r29.u32, xer);
	// bne cr6,0x8245e5c4
	if (!cr6.eq) goto loc_8245E5C4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_8245E5C4:
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8245e5e0
	if (cr0.eq) goto loc_8245E5E0;
	// lwz r11,168(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 168);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,168(r27)
	PPC_STORE_U32(r27.u32 + 168, r11.u32);
	// b 0x8245e5e8
	goto loc_8245E5E8;
loc_8245E5E0:
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
loc_8245E5E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245E5EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8245E5F4"))) PPC_WEAK_FUNC(sub_8245E5F4);
PPC_FUNC_IMPL(__imp__sub_8245E5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E5F8"))) PPC_WEAK_FUNC(sub_8245E5F8);
PPC_FUNC_IMPL(__imp__sub_8245E5F8) {
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
	ctx.lr = 0x8245E600;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,-4096
	r11.s64 = -4096;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// ble cr6,0x8245e628
	if (!cr6.gt) goto loc_8245E628;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,127
	ctx.r3.u64 = ctx.r3.u64 | 127;
	// b 0x8245e6c8
	goto loc_8245E6C8;
loc_8245E628:
	// addi r11,r5,4095
	r11.s64 = ctx.r5.s64 + 4095;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r30,r11,0,0,19
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// beq cr6,0x8245e6c8
	if (cr6.eq) goto loc_8245E6C8;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245e668
	if (!cr0.eq) goto loc_8245E668;
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245e668
	if (!cr0.eq) goto loc_8245E668;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245e370
	ctx.lr = 0x8245E660;
	sub_8245E370(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245e6c8
	if (cr0.lt) goto loc_8245E6C8;
loc_8245E668:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8245e680
	if (!cr6.eq) goto loc_8245E680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245e3f0
	ctx.lr = 0x8245E67C;
	sub_8245E3F0(ctx, base);
	// b 0x8245e6c8
	goto loc_8245E6C8;
loc_8245E680:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8245e6a0
	if (!cr6.lt) goto loc_8245E6A0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245e500
	ctx.lr = 0x8245E69C;
	sub_8245E500(ctx, base);
	// b 0x8245e6c8
	goto loc_8245E6C8;
loc_8245E6A0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8245e6c4
	if (!cr6.eq) goto loc_8245E6C4;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// ble cr6,0x8245e6c4
	if (!cr6.gt) goto loc_8245E6C4;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245e460
	ctx.lr = 0x8245E6C0;
	sub_8245E460(ctx, base);
	// b 0x8245e6c8
	goto loc_8245E6C8;
loc_8245E6C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245E6C8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8245E6D0"))) PPC_WEAK_FUNC(sub_8245E6D0);
PPC_FUNC_IMPL(__imp__sub_8245E6D0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8245E6D8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r30,80(r19)
	r30.u64 = PPC_LOAD_U32(r19.u32 + 80);
	// lwz r20,24(r30)
	r20.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r21,4(r30)
	r21.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r31,8(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// bl 0x827bcf64
	ctx.lr = 0x8245E6F8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r29,136(r23)
	r29.u64 = PPC_LOAD_U32(r23.u32 + 136);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8245e954
	if (!cr6.eq) goto loc_8245E954;
	// lbz r11,2(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + 2);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245e71c
	if (cr0.eq) goto loc_8245E71C;
	// lis r29,-16384
	r29.s64 = -1073741824;
	// ori r29,r29,296
	r29.u64 = r29.u64 | 296;
	// b 0x8245e954
	goto loc_8245E954;
loc_8245E71C:
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245e734
	if (cr0.eq) goto loc_8245E734;
	// lis r29,-16384
	r29.s64 = -1073741824;
	// ori r29,r29,16
	r29.u64 = r29.u64 | 16;
	// b 0x8245e954
	goto loc_8245E954;
loc_8245E734:
	// lbz r11,206(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 206);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8245e74c
	if (!cr0.eq) goto loc_8245E74C;
	// lis r29,-16384
	r29.s64 = -1073741824;
	// ori r29,r29,34
	r29.u64 = r29.u64 | 34;
	// b 0x8245e954
	goto loc_8245E954;
loc_8245E74C:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8245e764
	if (!cr6.eq) goto loc_8245E764;
	// li r18,0
	r18.s64 = 0;
	// mr r29,r18
	r29.u64 = r18.u64;
	// stw r18,20(r19)
	PPC_STORE_U32(r19.u32 + 20, r18.u32);
	// b 0x8245e954
	goto loc_8245E954;
loc_8245E764:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245e370
	ctx.lr = 0x8245E770;
	sub_8245E370(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245e954
	if (cr0.lt) goto loc_8245E954;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r18,0
	r18.s64 = 0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8245e7a0
	if (!cr6.eq) goto loc_8245E7A0;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8245e7a0
	if (!cr6.eq) goto loc_8245E7A0;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r18,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r18.u32);
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
loc_8245E7A0:
	// lwz r28,16(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// add r22,r28,r21
	r22.u64 = r28.u64 + r21.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r11,r22,4095
	r11.s64 = r22.s64 + 4095;
	// rlwinm r30,r11,0,0,19
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// bne cr6,0x8245e94c
	if (!cr6.eq) goto loc_8245E94C;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// ble cr6,0x8245e94c
	if (!cr6.gt) goto loc_8245E94C;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245dca8
	ctx.lr = 0x8245E7D8;
	sub_8245DCA8(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245e954
	if (cr0.lt) goto loc_8245E954;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplw cr6,r22,r11
	cr6.compare<uint32_t>(r22.u32, r11.u32, xer);
	// ble cr6,0x8245e808
	if (!cr6.gt) goto loc_8245E808;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245e5f8
	ctx.lr = 0x8245E800;
	sub_8245E5F8(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245e954
	if (cr0.lt) goto loc_8245E954;
loc_8245E808:
	// rlwinm r30,r28,0,0,19
	r30.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFF000;
	// b 0x8245e858
	goto loc_8245E858;
loc_8245E810:
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245ded8
	ctx.lr = 0x8245E830;
	sub_8245DED8(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245e954
	if (cr0.lt) goto loc_8245E954;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8245a6b0
	ctx.lr = 0x8245E84C;
	sub_8245A6B0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,4096
	r11.s64 = r11.s64 + 4096;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
loc_8245E858:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// blt cr6,0x8245e810
	if (cr6.lt) goto loc_8245E810;
	// lwz r24,28(r19)
	r24.u64 = PPC_LOAD_U32(r19.u32 + 28);
	// mr r25,r21
	r25.u64 = r21.u64;
loc_8245E86C:
	// clrlwi r26,r28,20
	r26.u64 = r28.u32 & 0xFFF;
	// subfic r30,r26,4096
	xer.ca = r26.u32 <= 4096;
	r30.s64 = 4096 - r26.s64;
	// cmplw cr6,r30,r25
	cr6.compare<uint32_t>(r30.u32, r25.u32, xer);
	// ble cr6,0x8245e880
	if (!cr6.gt) goto loc_8245E880;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_8245E880:
	// addi r11,r30,-4096
	r11.s64 = r30.s64 + -4096;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// rlwinm r6,r11,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245ded8
	ctx.lr = 0x8245E8A8;
	sub_8245DED8(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245e954
	if (cr0.lt) goto loc_8245E954;
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// add r3,r26,r27
	ctx.r3.u64 = r26.u64 + r27.u64;
	// bl 0x823da950
	ctx.lr = 0x8245E8C4;
	sub_823DA950(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8245a6b0
	ctx.lr = 0x8245E8D8;
	sub_8245A6B0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r10,r28,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFF000;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8245e8f0
	if (!cr6.eq) goto loc_8245E8F0;
	// addi r11,r11,4096
	r11.s64 = r11.s64 + 4096;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
loc_8245E8F0:
	// subf. r25,r30,r25
	r25.s64 = r25.s64 - r30.s64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// add r24,r30,r24
	r24.u64 = r30.u64 + r24.u64;
	// add r28,r30,r28
	r28.u64 = r30.u64 + r28.u64;
	// bne 0x8245e86c
	if (!cr0.eq) goto loc_8245E86C;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r11,r22
	cr6.compare<uint32_t>(r11.u32, r22.u32, xer);
	// bge cr6,0x8245e910
	if (!cr6.lt) goto loc_8245E910;
	// stw r22,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r22.u32);
loc_8245E910:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bda64
	ctx.lr = 0x8245E918;
	__imp__KeQuerySystemTime(ctx, base);
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x8245a488
	ctx.lr = 0x8245E924;
	sub_8245A488(ctx, base);
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
	// lbz r11,2(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + 2);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245e944
	if (cr0.eq) goto loc_8245E944;
	// stw r22,24(r20)
	PPC_STORE_U32(r20.u32 + 24, r22.u32);
	// stw r18,20(r20)
	PPC_STORE_U32(r20.u32 + 20, r18.u32);
loc_8245E944:
	// stw r21,20(r19)
	PPC_STORE_U32(r19.u32 + 20, r21.u32);
	// b 0x8245e954
	goto loc_8245E954;
loc_8245E94C:
	// lis r29,-16384
	r29.s64 = -1073741824;
	// ori r29,r29,127
	r29.u64 = r29.u64 | 127;
loc_8245E954:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8245E95C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r29,16(r19)
	PPC_STORE_U32(r19.u32 + 16, r29.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x827bdb04
	ctx.lr = 0x8245E96C;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8245E974"))) PPC_WEAK_FUNC(sub_8245E974);
PPC_FUNC_IMPL(__imp__sub_8245E974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245E978"))) PPC_WEAK_FUNC(sub_8245E978);
PPC_FUNC_IMPL(__imp__sub_8245E978) {
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
	ctx.lr = 0x8245E980;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,80(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// lwz r29,24(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r31,8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x827bcf64
	ctx.lr = 0x8245E99C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r4,r31,56
	ctx.r4.s64 = r31.s64 + 56;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bdb64
	ctx.lr = 0x8245E9A8;
	__imp__IoRemoveShareAccess(ctx, base);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8245ea4c
	if (!cr6.eq) goto loc_8245EA4C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8245ea4c
	if (!cr6.eq) goto loc_8245EA4C;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8245ea34
	if (cr0.eq) goto loc_8245EA34;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e2f0
	ctx.lr = 0x8245E9E0;
	sub_8245E2F0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245ea4c
	if (cr0.lt) goto loc_8245EA4C;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245ea14
	if (!cr0.eq) goto loc_8245EA14;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8245ea14
	if (cr6.eq) goto loc_8245EA14;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245d358
	ctx.lr = 0x8245EA14;
	sub_8245D358(ctx, base);
loc_8245EA14:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8245a048
	ctx.lr = 0x8245EA2C;
	sub_8245A048(ctx, base);
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// b 0x8245ea4c
	goto loc_8245EA4C;
loc_8245EA34:
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245ea4c
	if (cr0.eq) goto loc_8245EA4C;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e2f0
	ctx.lr = 0x8245EA4C;
	sub_8245E2F0(ctx, base);
loc_8245EA4C:
	// lbz r11,2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,2(r29)
	PPC_STORE_U8(r29.u32 + 2, r11.u8);
	// bl 0x827bcf54
	ctx.lr = 0x8245EA60;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r27,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r27.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bdb04
	ctx.lr = 0x8245EA70;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8245EA78"))) PPC_WEAK_FUNC(sub_8245EA78);
PPC_FUNC_IMPL(__imp__sub_8245EA78) {
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
	ctx.lr = 0x8245EA80;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// lbz r11,206(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 206);
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8245eabc
	if (!cr0.eq) goto loc_8245EABC;
loc_8245EAB0:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,746
	ctx.r3.u64 = ctx.r3.u64 | 746;
	// b 0x8245ebe0
	goto loc_8245EBE0;
loc_8245EABC:
	// lwz r28,68(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// bne cr6,0x8245eaec
	if (!cr6.eq) goto loc_8245EAEC;
	// lwz r28,84(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r30,56
	ctx.r4.s64 = r30.s64 + 56;
	// addi r5,r28,4096
	ctx.r5.s64 = r28.s64 + 4096;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e5f8
	ctx.lr = 0x8245EAE0;
	sub_8245E5F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8245eafc
	if (!cr0.lt) goto loc_8245EAFC;
	// b 0x8245ebe0
	goto loc_8245EBE0;
loc_8245EAEC:
	// lis r11,63
	r11.s64 = 4128768;
	// ori r11,r11,65408
	r11.u64 = r11.u64 | 65408;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bgt cr6,0x8245eab0
	if (cr6.gt) goto loc_8245EAB0;
loc_8245EAFC:
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r28,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8245EB10;
	sub_823D9890(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x823da950
	ctx.lr = 0x8245EB20;
	sub_823DA950(ctx, base);
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lbz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 40);
	// rlwimi r11,r10,0,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// rlwimi r11,r26,7,0,24
	r11.u64 = (__builtin_rotateleft32(r26.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
	// bl 0x827bda64
	ctx.lr = 0x8245EB3C;
	__imp__KeQuerySystemTime(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ld r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x8245a488
	ctx.lr = 0x8245EB48;
	sub_8245A488(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// bl 0x82459e18
	ctx.lr = 0x8245EB68;
	sub_82459E18(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8245eb7c
	if (!cr0.eq) goto loc_8245EB7C;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,154
	ctx.r3.u64 = ctx.r3.u64 | 154;
	// b 0x8245ebe0
	goto loc_8245EBE0;
loc_8245EB7C:
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245eba4
	if (!cr0.eq) goto loc_8245EBA4;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e5f8
	ctx.lr = 0x8245EB9C;
	sub_8245E5F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x8245eba8
	goto loc_8245EBA8;
loc_8245EBA4:
	// li r29,0
	r29.s64 = 0;
loc_8245EBA8:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8245ebd4
	if (cr6.lt) goto loc_8245EBD4;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e2f0
	ctx.lr = 0x8245EBC0;
	sub_8245E2F0(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8245ebd4
	if (cr0.lt) goto loc_8245EBD4;
	// stw r31,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r31.u32);
	// li r29,0
	r29.s64 = 0;
	// b 0x8245ebdc
	goto loc_8245EBDC;
loc_8245EBD4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245a048
	ctx.lr = 0x8245EBDC;
	sub_8245A048(ctx, base);
loc_8245EBDC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8245EBE0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8245EBE8"))) PPC_WEAK_FUNC(sub_8245EBE8);
PPC_FUNC_IMPL(__imp__sub_8245EBE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8245EBF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// bl 0x827bda64
	ctx.lr = 0x8245EC14;
	__imp__KeQuerySystemTime(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ld r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x8245a488
	ctx.lr = 0x8245EC20;
	sub_8245A488(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// bl 0x8245e5f8
	ctx.lr = 0x8245EC40;
	sub_8245E5F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245ec58
	if (cr0.lt) goto loc_8245EC58;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e2f0
	ctx.lr = 0x8245EC58;
	sub_8245E2F0(ctx, base);
loc_8245EC58:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8245EC60"))) PPC_WEAK_FUNC(sub_8245EC60);
PPC_FUNC_IMPL(__imp__sub_8245EC60) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8245EC68;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r29,80(r18)
	r29.u64 = PPC_LOAD_U32(r18.u32 + 80);
	// lwz r26,24(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r19,8(r29)
	r19.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r21,4(r29)
	r21.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lhz r20,14(r29)
	r20.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// rlwinm r22,r19,8,24,31
	r22.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 8) & 0xFF;
	// bl 0x827bdb34
	ctx.lr = 0x8245EC94;
	__imp__ObIsTitleObject(ctx, base);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r30,28(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// bl 0x827bcf64
	ctx.lr = 0x8245ECB0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r31,136(r23)
	r31.u64 = PPC_LOAD_U32(r23.u32 + 136);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x8245ee8c
	if (!cr6.eq) goto loc_8245EE8C;
	// lbz r11,206(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 206);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8245ecf4
	if (!cr0.eq) goto loc_8245ECF4;
	// cmplwi cr6,r22,2
	cr6.compare<uint32_t>(r22.u32, 2, xer);
	// beq cr6,0x8245ece8
	if (cr6.eq) goto loc_8245ECE8;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8245ece8
	if (cr6.eq) goto loc_8245ECE8;
	// cmplwi cr6,r22,4
	cr6.compare<uint32_t>(r22.u32, 4, xer);
	// beq cr6,0x8245ece8
	if (cr6.eq) goto loc_8245ECE8;
	// cmplwi cr6,r22,5
	cr6.compare<uint32_t>(r22.u32, 5, xer);
	// bne cr6,0x8245ecf4
	if (!cr6.eq) goto loc_8245ECF4;
loc_8245ECE8:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,34
	r31.u64 = r31.u64 | 34;
	// b 0x8245ee8c
	goto loc_8245EE8C;
loc_8245ECF4:
	// lwz r11,40(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8245ed0c
	if (cr6.eq) goto loc_8245ED0C;
loc_8245ED00:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,13
	r31.u64 = r31.u64 | 13;
	// b 0x8245ee8c
	goto loc_8245EE8C;
loc_8245ED0C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8245ed8c
	if (cr6.eq) goto loc_8245ED8C;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lbz r11,53(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245ed00
	if (cr0.eq) goto loc_8245ED00;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8245a0c0
	ctx.lr = 0x8245ED2C;
	sub_8245A0C0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245ed40
	if (!cr0.eq) goto loc_8245ED40;
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,154
	r31.u64 = r31.u64 | 154;
	// b 0x8245ee8c
	goto loc_8245EE8C;
loc_8245ED40:
	// lhz r31,88(r1)
	r31.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi r31,0
	cr0.compare<uint32_t>(r31.u32, 0, xer);
	// bne 0x8245ed70
	if (!cr0.eq) goto loc_8245ED70;
	// lbz r11,2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245ed68
	if (cr0.eq) goto loc_8245ED68;
loc_8245ED5C:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,34
	r31.u64 = r31.u64 | 34;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245ED68:
	// li r31,0
	r31.s64 = 0;
	// b 0x8245f0dc
	goto loc_8245F0DC;
loc_8245ED70:
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,92
	cr6.compare<uint32_t>(ctx.r10.u32, 92, xer);
	// bne cr6,0x8245edd8
	if (!cr6.eq) goto loc_8245EDD8;
loc_8245ED80:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,51
	r31.u64 = r31.u64 | 51;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245ED8C:
	// lhz r31,88(r1)
	r31.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi r31,0
	cr0.compare<uint32_t>(r31.u32, 0, xer);
	// beq 0x8245ece8
	if (cr0.eq) goto loc_8245ECE8;
	// addi r25,r23,56
	r25.s64 = r23.s64 + 56;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8245a0c0
	ctx.lr = 0x8245EDA8;
	sub_8245A0C0(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,92
	cr6.compare<uint32_t>(ctx.r10.u32, 92, xer);
	// bne cr6,0x8245ed80
	if (!cr6.eq) goto loc_8245ED80;
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// bne cr6,0x8245edd8
	if (!cr6.eq) goto loc_8245EDD8;
	// lbz r11,2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245ed68
	if (cr0.eq) goto loc_8245ED68;
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,13
	r31.u64 = r31.u64 | 13;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245EDD8:
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r11,-1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r11,92
	cr6.compare<uint32_t>(r11.u32, 92, xer);
	// bne cr6,0x8245edfc
	if (!cr6.eq) goto loc_8245EDFC;
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r24,1
	r24.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sth r11,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, r11.u16);
	// b 0x8245ee00
	goto loc_8245EE00;
loc_8245EDFC:
	// li r24,0
	r24.s64 = 0;
loc_8245EE00:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// ld r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ae88
	ctx.lr = 0x8245EE10;
	sub_8245AE88(ctx, base);
	// lhz r30,88(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// mr. r31,r30
	r31.u64 = r30.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8245ee2c
	if (cr0.eq) goto loc_8245EE2C;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,92
	cr6.compare<uint32_t>(r11.u32, 92, xer);
	// beq cr6,0x8245ed80
	if (cr6.eq) goto loc_8245ED80;
loc_8245EE2C:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8245a208
	ctx.lr = 0x8245EE38;
	sub_8245A208(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8245eeac
	if (cr0.eq) goto loc_8245EEAC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8245a0c0
	ctx.lr = 0x8245EE4C;
	sub_8245A0C0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x8245f038
	if (cr0.eq) goto loc_8245F038;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8245a048
	ctx.lr = 0x8245EE5C;
	sub_8245A048(ctx, base);
	// mr r25,r30
	r25.u64 = r30.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8245f044
	if (cr6.eq) goto loc_8245F044;
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245ee00
	if (!cr0.eq) goto loc_8245EE00;
loc_8245EE74:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,58
	r31.u64 = r31.u64 | 58;
loc_8245EE7C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8245ee8c
	if (cr6.eq) goto loc_8245EE8C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8245a048
	ctx.lr = 0x8245EE8C;
	sub_8245A048(ctx, base);
loc_8245EE8C:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8245EE94;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r31,16(r18)
	PPC_STORE_U32(r18.u32 + 16, r31.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x827bdb04
	ctx.lr = 0x8245EEA4;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9220
	return;
loc_8245EEAC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8245a380
	ctx.lr = 0x8245EEB4;
	sub_8245A380(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8245ed80
	if (cr0.eq) goto loc_8245ED80;
	// clrlwi r28,r30,16
	r28.u64 = r30.u32 & 0xFFFF;
loc_8245EEC0:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245c580
	ctx.lr = 0x8245EED8;
	sub_8245C580(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8245ef68
	if (cr0.lt) goto loc_8245EF68;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8245eef4
	if (cr6.eq) goto loc_8245EEF4;
	// lbz r11,152(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 152);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245ee74
	if (cr0.eq) goto loc_8245EE74;
loc_8245EEF4:
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82459e18
	ctx.lr = 0x8245EF08;
	sub_82459E18(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// beq 0x8245f038
	if (cr0.eq) goto loc_8245F038;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8245a048
	ctx.lr = 0x8245EF1C;
	sub_8245A048(ctx, base);
	// mr r25,r30
	r25.u64 = r30.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8245f028
	if (cr6.eq) goto loc_8245F028;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// ld r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ae88
	ctx.lr = 0x8245EF38;
	sub_8245AE88(ctx, base);
	// lhz r30,88(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// mr. r28,r30
	r28.u64 = r30.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// beq 0x8245ef54
	if (cr0.eq) goto loc_8245EF54;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,92
	cr6.compare<uint32_t>(r11.u32, 92, xer);
	// beq cr6,0x8245ed80
	if (cr6.eq) goto loc_8245ED80;
loc_8245EF54:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8245a380
	ctx.lr = 0x8245EF5C;
	sub_8245A380(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245eec0
	if (!cr0.eq) goto loc_8245EEC0;
	// b 0x8245ed80
	goto loc_8245ED80;
loc_8245EF68:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,52
	r11.u64 = r11.u64 | 52;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x8245ee7c
	if (!cr6.eq) goto loc_8245EE7C;
	// clrlwi. r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245ee74
	if (!cr0.eq) goto loc_8245EE74;
	// lbz r11,53(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 53);
	// rlwinm. r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245f0c0
	if (!cr0.eq) goto loc_8245F0C0;
	// lbz r11,2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245efa4
	if (cr0.eq) goto loc_8245EFA4;
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// b 0x8245f0ac
	goto loc_8245F0AC;
loc_8245EFA4:
	// cmplwi cr6,r22,1
	cr6.compare<uint32_t>(r22.u32, 1, xer);
	// beq cr6,0x8245ee7c
	if (cr6.eq) goto loc_8245EE7C;
	// cmplwi cr6,r22,4
	cr6.compare<uint32_t>(r22.u32, 4, xer);
	// beq cr6,0x8245ee7c
	if (cr6.eq) goto loc_8245EE7C;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8245efc4
	if (cr6.eq) goto loc_8245EFC4;
	// rlwinm. r11,r19,0,25,25
	r11.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245ed80
	if (!cr0.eq) goto loc_8245ED80;
loc_8245EFC4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r7,44(r18)
	ctx.r7.u64 = PPC_LOAD_U32(r18.u32 + 44);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245ea78
	ctx.lr = 0x8245EFE8;
	sub_8245EA78(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8245ee7c
	if (cr0.lt) goto loc_8245EE7C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8245a048
	ctx.lr = 0x8245EFF8;
	sub_8245A048(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// clrlwi r4,r20,16
	ctx.r4.u64 = r20.u32 & 0xFFFF;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x827bdb54
	ctx.lr = 0x8245F010;
	__imp__IoSetShareAccess(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r31,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r31.u32);
	// stw r11,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r11.u32);
	// stw r10,20(r18)
	PPC_STORE_U32(r18.u32 + 20, ctx.r10.u32);
	// b 0x8245f1fc
	goto loc_8245F1FC;
loc_8245F028:
	// lbz r11,2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f0d0
	if (cr0.eq) goto loc_8245F0D0;
	// b 0x8245f0a4
	goto loc_8245F0A4;
loc_8245F038:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,154
	r31.u64 = r31.u64 | 154;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245F044:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8245f098
	if (cr6.eq) goto loc_8245F098;
	// rlwinm. r10,r19,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245f0c0
	if (!cr0.eq) goto loc_8245F0C0;
	// lbz r10,53(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 53);
	// rlwinm. r10,r10,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245f0c0
	if (!cr0.eq) goto loc_8245F0C0;
	// lbz r10,53(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245f098
	if (!cr0.eq) goto loc_8245F098;
	// lis r12,1
	r12.s64 = 65536;
	// ori r12,r12,262
	r12.u64 = r12.u64 | 262;
	// and. r10,r21,r12
	ctx.r10.u64 = r21.u64 & r12.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245ed5c
	if (!cr0.eq) goto loc_8245ED5C;
	// lbz r10,58(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 58);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x8245ed5c
	if (!cr0.eq) goto loc_8245ED5C;
	// lbz r11,59(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 59);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8245ed5c
	if (!cr0.eq) goto loc_8245ED5C;
loc_8245F098:
	// lbz r11,2(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f0cc
	if (cr0.eq) goto loc_8245F0CC;
loc_8245F0A4:
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r6,4
	ctx.r6.s64 = 4;
loc_8245F0AC:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245bf60
	ctx.lr = 0x8245F0B8;
	sub_8245BF60(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245F0C0:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,86
	r31.u64 = r31.u64 | 86;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245F0CC:
	// li r31,0
	r31.s64 = 0;
loc_8245F0D0:
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f10c
	if (cr0.eq) goto loc_8245F10C;
loc_8245F0DC:
	// cmplwi cr6,r22,1
	cr6.compare<uint32_t>(r22.u32, 1, xer);
	// beq cr6,0x8245f0f8
	if (cr6.eq) goto loc_8245F0F8;
	// cmplwi cr6,r22,3
	cr6.compare<uint32_t>(r22.u32, 3, xer);
	// beq cr6,0x8245f0f8
	if (cr6.eq) goto loc_8245F0F8;
loc_8245F0EC:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,53
	r31.u64 = r31.u64 | 53;
	// b 0x8245ee7c
	goto loc_8245EE7C;
loc_8245F0F8:
	// rlwinm. r11,r19,0,25,25
	r11.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f12c
	if (cr0.eq) goto loc_8245F12C;
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,186
	r31.u64 = r31.u64 | 186;
	// b 0x8245f12c
	goto loc_8245F12C;
loc_8245F10C:
	// cmplwi cr6,r22,2
	cr6.compare<uint32_t>(r22.u32, 2, xer);
	// beq cr6,0x8245f0ec
	if (cr6.eq) goto loc_8245F0EC;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x8245f124
	if (!cr6.eq) goto loc_8245F124;
	// clrlwi. r11,r19,31
	r11.u64 = r19.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f12c
	if (cr0.eq) goto loc_8245F12C;
loc_8245F124:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,259
	r31.u64 = r31.u64 | 259;
loc_8245F12C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8245ee7c
	if (cr6.lt) goto loc_8245EE7C;
	// lbz r11,56(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 56);
	// addi r30,r25,56
	r30.s64 = r25.s64 + 56;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// clrlwi r4,r20,16
	ctx.r4.u64 = r20.u32 & 0xFFFF;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bne 0x8245f15c
	if (!cr0.eq) goto loc_8245F15C;
	// bl 0x827bdb54
	ctx.lr = 0x8245F158;
	__imp__IoSetShareAccess(ctx, base);
	// b 0x8245f168
	goto loc_8245F168;
loc_8245F15C:
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x827bdb44
	ctx.lr = 0x8245F164;
	__imp__IoCheckShareAccess(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8245F168:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8245ee7c
	if (cr6.lt) goto loc_8245EE7C;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8245f190
	if (cr6.eq) goto loc_8245F190;
	// cmplwi cr6,r22,4
	cr6.compare<uint32_t>(r22.u32, 4, xer);
	// beq cr6,0x8245f190
	if (cr6.eq) goto loc_8245F190;
	// cmplwi cr6,r22,5
	cr6.compare<uint32_t>(r22.u32, 5, xer);
	// beq cr6,0x8245f190
	if (cr6.eq) goto loc_8245F190;
	// li r11,1
	r11.s64 = 1;
	// b 0x8245f1ac
	goto loc_8245F1AC;
loc_8245F190:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r5,44(r18)
	ctx.r5.u64 = PPC_LOAD_U32(r18.u32 + 44);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8245ebe8
	ctx.lr = 0x8245F1A0;
	sub_8245EBE8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x8245f1b4
	if (cr0.lt) goto loc_8245F1B4;
	// li r11,3
	r11.s64 = 3;
loc_8245F1AC:
	// stw r11,20(r18)
	PPC_STORE_U32(r18.u32 + 20, r11.u32);
	// b 0x8245f1c0
	goto loc_8245F1C0;
loc_8245F1B4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bdb64
	ctx.lr = 0x8245F1C0;
	__imp__IoRemoveShareAccess(ctx, base);
loc_8245F1C0:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8245ee7c
	if (cr6.lt) goto loc_8245EE7C;
	// li r11,0
	r11.s64 = 0;
	// stw r25,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r25.u32);
	// stw r11,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r11.u32);
	// lbz r11,206(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 206);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8245f1fc
	if (cr0.eq) goto loc_8245F1FC;
	// rlwinm. r11,r19,0,19,19
	r11.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f1fc
	if (cr0.eq) goto loc_8245F1FC;
	// lbz r11,53(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 53);
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245f1fc
	if (!cr0.eq) goto loc_8245F1FC;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// stb r11,53(r25)
	PPC_STORE_U8(r25.u32 + 53, r11.u8);
loc_8245F1FC:
	// lwz r9,128(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 128);
	// addi r10,r23,128
	ctx.r10.s64 = r23.s64 + 128;
	// addi r11,r26,80
	r11.s64 = r26.s64 + 80;
	// stw r10,84(r26)
	PPC_STORE_U32(r26.u32 + 84, ctx.r10.u32);
	// li r31,0
	r31.s64 = 0;
	// stw r9,80(r26)
	PPC_STORE_U32(r26.u32 + 80, ctx.r9.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r11,128(r23)
	PPC_STORE_U32(r23.u32 + 128, r11.u32);
	// b 0x8245ee8c
	goto loc_8245EE8C;
}

__attribute__((alias("__imp__sub_8245F220"))) PPC_WEAK_FUNC(sub_8245F220);
PPC_FUNC_IMPL(__imp__sub_8245F220) {
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
	ctx.lr = 0x8245F228;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r29,128
	r30.s64 = r29.s64 + 128;
	// lwz r31,128(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// b 0x8245f264
	goto loc_8245F264;
loc_8245F23C:
	// lwz r4,-72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -72);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,53(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 53);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f264
	if (cr0.eq) goto loc_8245F264;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8245e2f0
	ctx.lr = 0x8245F25C;
	sub_8245E2F0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f270
	if (cr0.lt) goto loc_8245F270;
loc_8245F264:
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bne cr6,0x8245f23c
	if (!cr6.eq) goto loc_8245F23C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245F270:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8245F278"))) PPC_WEAK_FUNC(sub_8245F278);
PPC_FUNC_IMPL(__imp__sub_8245F278) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r31,24(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8245f2b4
	if (cr6.eq) goto loc_8245F2B4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8245f2b4
	if (cr6.eq) goto loc_8245F2B4;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8245f42c
	if (!cr6.eq) goto loc_8245F42C;
loc_8245F2B4:
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x8245f420
	if (cr6.gt) goto loc_8245F420;
	// lis r12,-32249
	r12.s64 = -2113470464;
	// addi r12,r12,-22656
	r12.s64 = r12.s64 + -22656;
	// lbzx r0,r12,r11
	r0.u64 = PPC_LOAD_U8(r12.u32 + r11.u32);
	// rlwinm r0,r0,2,0,29
	r0.u64 = __builtin_rotateleft64(r0.u32 | (r0.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r12,-32186
	r12.s64 = -2109341696;
	// addi r12,r12,-3352
	r12.s64 = r12.s64 + -3352;
	// add r12,r12,r0
	r12.u64 = r12.u64 + r0.u64;
	// mtctr r12
	ctr.u64 = r12.u64;
	// nop 
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8245F2E8;
	case 1:
		goto loc_8245F2F4;
	case 2:
		goto loc_8245F300;
	case 3:
		goto loc_8245F334;
	case 4:
		goto loc_8245F344;
	case 5:
		goto loc_8245F3F4;
	case 6:
		goto loc_8245F400;
	case 7:
		goto loc_8245F3DC;
	case 8:
		goto loc_8245F40C;
	default:
		__builtin_unreachable();
	}
loc_8245F2E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8245F2F0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F2F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8245F2FC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F300:
	// lwz r30,136(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8245f428
	if (!cr6.eq) goto loc_8245F428;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245f220
	ctx.lr = 0x8245F314;
	sub_8245F220(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8245f428
	if (cr0.lt) goto loc_8245F428;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8245be30
	ctx.lr = 0x8245F32C;
	sub_8245BE30(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F334:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,136(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82459770
	ctx.lr = 0x8245F340;
	sub_82459770(ctx, base);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F344:
	// lwz r30,136(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8245f428
	if (!cr6.eq) goto loc_8245F428;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r9,160(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r10,r31,128
	ctx.r10.s64 = r31.s64 + 128;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r6,76(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// clrlwi r7,r7,1
	ctx.r7.u64 = ctx.r7.u32 & 0x7FFFFFFF;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// rlwinm r6,r6,20,12,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 20) & 0xFFFFF;
	// stw r9,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r9.u32);
	// stw r7,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r7.u32);
	// stw r6,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r6.u32);
	// stw r8,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r8.u32);
	// b 0x8245f3a0
	goto loc_8245F3A0;
loc_8245F38C:
	// lwz r9,-72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -72);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,53(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 53);
	// andi. r8,r8,223
	ctx.r8.u64 = ctx.r8.u64 & 223;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stb r8,53(r9)
	PPC_STORE_U8(ctx.r9.u32 + 53, ctx.r8.u8);
loc_8245F3A0:
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8245f38c
	if (!cr6.eq) goto loc_8245F38C;
	// lbz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8245f428
	if (cr0.eq) goto loc_8245F428;
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
loc_8245F3BC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andi. r9,r9,251
	ctx.r9.u64 = ctx.r9.u64 & 251;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8245f3bc
	if (!cr0.eq) goto loc_8245F3BC;
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F3DC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r11,14504
	ctx.r4.s64 = r11.s64 + 14504;
	// li r5,40
	ctx.r5.s64 = 40;
	// bl 0x823da950
	ctx.lr = 0x8245F3F0;
	sub_823DA950(ctx, base);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F3F4:
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F400:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F40C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// b 0x8245f428
	goto loc_8245F428;
loc_8245F420:
	// lis r30,-16384
	r30.s64 = -1073741824;
	// ori r30,r30,16
	r30.u64 = r30.u64 | 16;
loc_8245F428:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8245F42C:
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

__attribute__((alias("__imp__sub_8245F444"))) PPC_WEAK_FUNC(sub_8245F444);
PPC_FUNC_IMPL(__imp__sub_8245F444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245F448"))) PPC_WEAK_FUNC(sub_8245F448);
PPC_FUNC_IMPL(__imp__sub_8245F448) {
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
	ctx.lr = 0x8245F450;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// cmpdi cr6,r11,-1
	cr6.compare<int64_t>(r11.s64, -1, xer);
	// beq cr6,0x8245f4b0
	if (cr6.eq) goto loc_8245F4B0;
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// beq cr6,0x8245f4b0
	if (cr6.eq) goto loc_8245F4B0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8245a488
	ctx.lr = 0x8245F484;
	sub_8245A488(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245f498
	if (!cr0.eq) goto loc_8245F498;
loc_8245F48C:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// b 0x8245f55c
	goto loc_8245F55C;
loc_8245F498:
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// beq cr6,0x8245f4b4
	if (cr6.eq) goto loc_8245F4B4;
	// li r28,1
	r28.s64 = 1;
	// b 0x8245f4b4
	goto loc_8245F4B4;
loc_8245F4B0:
	// lwz r27,64(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 64);
loc_8245F4B4:
	// ld r11,16(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 16);
	// cmpdi cr6,r11,-1
	cr6.compare<int64_t>(r11.s64, -1, xer);
	// beq cr6,0x8245f4f4
	if (cr6.eq) goto loc_8245F4F4;
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// beq cr6,0x8245f4f4
	if (cr6.eq) goto loc_8245F4F4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8245a488
	ctx.lr = 0x8245F4D4;
	sub_8245A488(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8245f48c
	if (cr0.eq) goto loc_8245F48C;
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x8245f4f8
	if (cr6.eq) goto loc_8245F4F8;
	// li r28,1
	r28.s64 = 1;
	// b 0x8245f4f8
	goto loc_8245F4F8;
loc_8245F4F4:
	// lwz r29,68(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 68);
loc_8245F4F8:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8245f528
	if (cr6.eq) goto loc_8245F528;
	// lbz r10,53(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8245f520
	if (cr0.eq) goto loc_8245F520;
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245f528
	if (!cr0.eq) goto loc_8245F528;
	// b 0x8245f48c
	goto loc_8245F48C;
loc_8245F520:
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245f48c
	if (!cr0.eq) goto loc_8245F48C;
loc_8245F528:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8245f558
	if (cr6.eq) goto loc_8245F558;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245e370
	ctx.lr = 0x8245F53C;
	sub_8245E370(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f55c
	if (cr0.lt) goto loc_8245F55C;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// stw r27,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r27.u32);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
loc_8245F558:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245F55C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8245F564"))) PPC_WEAK_FUNC(sub_8245F564);
PPC_FUNC_IMPL(__imp__sub_8245F564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245F568"))) PPC_WEAK_FUNC(sub_8245F568);
PPC_FUNC_IMPL(__imp__sub_8245F568) {
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
	ctx.lr = 0x8245F570;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r5,80(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8245f59c
	if (!cr0.eq) goto loc_8245F59C;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// b 0x8245f7f0
	goto loc_8245F7F0;
loc_8245F59C:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r8,92
	cr6.compare<uint32_t>(ctx.r8.u32, 92, xer);
	// bne cr6,0x8245f5b8
	if (!cr6.eq) goto loc_8245F5B8;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8245F5B8:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8245f5e4
	if (!cr6.gt) goto loc_8245F5E4;
loc_8245F5C4:
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r9,92
	cr6.compare<uint32_t>(ctx.r9.u32, 92, xer);
	// beq cr6,0x8245f5e0
	if (cr6.eq) goto loc_8245F5E0;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8245f5c4
	if (cr6.gt) goto loc_8245F5C4;
	// b 0x8245f5e4
	goto loc_8245F5E4;
loc_8245F5E0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_8245F5E4:
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// clrlwi r27,r11,16
	r27.u64 = r11.u32 & 0xFFFF;
	// sth r27,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, r27.u16);
	// sth r27,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r27.u16);
	// bl 0x8245a380
	ctx.lr = 0x8245F600;
	sub_8245A380(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245f614
	if (!cr0.eq) goto loc_8245F614;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,51
	ctx.r3.u64 = ctx.r3.u64 | 51;
	// b 0x8245f7f0
	goto loc_8245F7F0;
loc_8245F614:
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8245f64c
	if (cr6.eq) goto loc_8245F64C;
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245f650
	if (!cr0.eq) goto loc_8245F650;
	// lbz r10,53(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 53);
	// xor r11,r10,r11
	r11.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f650
	if (cr0.eq) goto loc_8245F650;
loc_8245F640:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,34
	ctx.r3.u64 = ctx.r3.u64 | 34;
	// b 0x8245f7f0
	goto loc_8245F7F0;
loc_8245F64C:
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
loc_8245F650:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x8245f640
	if (!cr6.eq) goto loc_8245F640;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245c580
	ctx.lr = 0x8245F674;
	sub_8245C580(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f74c
	if (cr0.lt) goto loc_8245F74C;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8245f740
	if (cr0.eq) goto loc_8245F740;
	// lbz r11,152(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 152);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245f740
	if (!cr0.eq) goto loc_8245F740;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245a208
	ctx.lr = 0x8245F6A0;
	sub_8245A208(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8245f640
	if (!cr0.eq) goto loc_8245F640;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// lwz r4,176(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245e280
	ctx.lr = 0x8245F6C4;
	sub_8245E280(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f7f0
	if (cr0.lt) goto loc_8245F7F0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// rlwinm r10,r10,0,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFC0;
	// stb r10,40(r11)
	PPC_STORE_U8(r11.u32 + 40, ctx.r10.u8);
	// bl 0x8245a6b0
	ctx.lr = 0x8245F6F0;
	sub_8245A6B0(ctx, base);
	// lbz r11,158(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 158);
	// lbz r9,157(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 157);
	// rotlwi r10,r11,8
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 8);
	// lbz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 156);
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// add. r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f75c
	if (cr0.eq) goto loc_8245F75C;
	// lbz r11,161(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 161);
	// li r6,0
	ctx.r6.s64 = 0;
	// lbz r9,160(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 160);
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r11,r11,8
	r11.u64 = __builtin_rotateleft32(r11.u32, 8);
	// lbz r8,159(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 159);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// bl 0x8245d358
	ctx.lr = 0x8245F73C;
	sub_8245D358(ctx, base);
	// b 0x8245f75c
	goto loc_8245F75C;
loc_8245F740:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,53
	ctx.r3.u64 = ctx.r3.u64 | 53;
	// b 0x8245f7f0
	goto loc_8245F7F0;
loc_8245F74C:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,52
	r11.u64 = r11.u64 | 52;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8245f7f0
	if (!cr6.eq) goto loc_8245F7F0;
loc_8245F75C:
	// clrlwi r5,r27,16
	ctx.r5.u64 = r27.u32 & 0xFFFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// bl 0x823da950
	ctx.lr = 0x8245F76C;
	sub_823DA950(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stb r27,52(r29)
	PPC_STORE_U8(r29.u32 + 52, r27.u8);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x8245f7e0
	if (cr6.eq) goto loc_8245F7E0;
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r31,r29,72
	r31.s64 = r29.s64 + 72;
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x8245a048
	ctx.lr = 0x8245F798;
	sub_8245A048(ctx, base);
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// clrlwi r28,r11,31
	r28.u64 = r11.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8245a0c0
	ctx.lr = 0x8245F7B0;
	sub_8245A0C0(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8245f7c8
	if (!cr6.eq) goto loc_8245F7C8;
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r11,r26,120
	r11.s64 = r26.s64 + 120;
	// bne 0x8245f7cc
	if (!cr0.eq) goto loc_8245F7CC;
loc_8245F7C8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8245F7CC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8245F7E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245e2f0
	ctx.lr = 0x8245F7F0;
	sub_8245E2F0(ctx, base);
loc_8245F7F0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8245F7F8"))) PPC_WEAK_FUNC(sub_8245F7F8);
PPC_FUNC_IMPL(__imp__sub_8245F7F8) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// bne 0x8245f82c
	if (!cr0.eq) goto loc_8245F82C;
	// andi. r11,r11,247
	r11.u64 = r11.u64 & 247;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// b 0x8245f89c
	goto loc_8245F89C;
loc_8245F82C:
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f880
	if (cr0.eq) goto loc_8245F880;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245c580
	ctx.lr = 0x8245F85C;
	sub_8245C580(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f870
	if (cr0.lt) goto loc_8245F870;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,257
	ctx.r3.u64 = ctx.r3.u64 | 257;
	// b 0x8245f8a4
	goto loc_8245F8A4;
loc_8245F870:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,52
	r11.u64 = r11.u64 | 52;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8245f8a4
	if (!cr6.eq) goto loc_8245F8A4;
loc_8245F880:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8245e370
	ctx.lr = 0x8245F88C;
	sub_8245E370(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f8a4
	if (cr0.lt) goto loc_8245F8A4;
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
loc_8245F89C:
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245F8A4:
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

__attribute__((alias("__imp__sub_8245F8BC"))) PPC_WEAK_FUNC(sub_8245F8BC);
PPC_FUNC_IMPL(__imp__sub_8245F8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8245F8C0"))) PPC_WEAK_FUNC(sub_8245F8C0);
PPC_FUNC_IMPL(__imp__sub_8245F8C0) {
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
	ctx.lr = 0x8245F8C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8245f8ec
	if (cr6.eq) goto loc_8245F8EC;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,127
	ctx.r3.u64 = ctx.r3.u64 | 127;
	// b 0x8245f948
	goto loc_8245F948;
loc_8245F8EC:
	// lwz r30,4(r5)
	r30.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r29,24(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// beq cr6,0x8245f944
	if (cr6.eq) goto loc_8245F944;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8245e370
	ctx.lr = 0x8245F908;
	sub_8245E370(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f948
	if (cr0.lt) goto loc_8245F948;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// ble cr6,0x8245f934
	if (!cr6.gt) goto loc_8245F934;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8245e5f8
	ctx.lr = 0x8245F92C;
	sub_8245E5F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245f948
	if (cr0.lt) goto loc_8245F948;
loc_8245F934:
	// lbz r11,53(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 53);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// ori r11,r11,16
	r11.u64 = r11.u64 | 16;
	// stb r11,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r11.u8);
loc_8245F944:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8245F948:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8245F950"))) PPC_WEAK_FUNC(sub_8245F950);
PPC_FUNC_IMPL(__imp__sub_8245F950) {
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
	ctx.lr = 0x8245F958;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r29,80(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// lwz r28,24(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r30,8(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x827bcf64
	ctx.lr = 0x8245F974;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r31,136(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 136);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x8245fb10
	if (!cr6.eq) goto loc_8245FB10;
	// lbz r11,2(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 2);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245f998
	if (cr0.eq) goto loc_8245F998;
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,296
	r31.u64 = r31.u64 | 296;
	// b 0x8245fb10
	goto loc_8245FB10;
loc_8245F998:
	// lbz r11,206(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 206);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x8245f9bc
	if (!cr0.eq) goto loc_8245F9BC;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,14
	cr6.compare<int32_t>(r11.s32, 14, xer);
	// beq cr6,0x8245f9bc
	if (cr6.eq) goto loc_8245F9BC;
loc_8245F9B0:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,34
	r31.u64 = r31.u64 | 34;
	// b 0x8245fb10
	goto loc_8245FB10;
loc_8245F9BC:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8245fad8
	if (cr6.eq) goto loc_8245FAD8;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8245faa8
	if (cr6.eq) goto loc_8245FAA8;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x8245fa7c
	if (cr6.eq) goto loc_8245FA7C;
	// cmpwi cr6,r11,14
	cr6.compare<int32_t>(r11.s32, 14, xer);
	// beq cr6,0x8245fa6c
	if (cr6.eq) goto loc_8245FA6C;
	// cmpwi cr6,r11,19
	cr6.compare<int32_t>(r11.s32, 19, xer);
	// beq cr6,0x8245fa20
	if (cr6.eq) goto loc_8245FA20;
	// cmpwi cr6,r11,20
	cr6.compare<int32_t>(r11.s32, 20, xer);
	// bne cr6,0x8245fae4
	if (!cr6.eq) goto loc_8245FAE4;
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245fae4
	if (!cr0.eq) goto loc_8245FAE4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8245f9b0
	if (!cr6.eq) goto loc_8245F9B0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,28(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245f8c0
	ctx.lr = 0x8245FA1C;
	sub_8245F8C0(ctx, base);
	// b 0x8245fb0c
	goto loc_8245FB0C;
loc_8245FA20:
	// lbz r10,53(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8245fae4
	if (!cr0.eq) goto loc_8245FAE4;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8245f9b0
	if (!cr6.eq) goto loc_8245F9B0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8245fa54
	if (cr6.eq) goto loc_8245FA54;
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,127
	r31.u64 = r31.u64 | 127;
	// b 0x8245fb10
	goto loc_8245FB10;
loc_8245FA54:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245e5f8
	ctx.lr = 0x8245FA68;
	sub_8245E5F8(ctx, base);
	// b 0x8245fb0c
	goto loc_8245FB0C;
loc_8245FA6C:
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r11,20(r28)
	PPC_STORE_U64(r28.u32 + 20, r11.u64);
	// b 0x8245fb10
	goto loc_8245FB10;
loc_8245FA7C:
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245fae4
	if (!cr0.eq) goto loc_8245FAE4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8245f9b0
	if (!cr6.eq) goto loc_8245F9B0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,28(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245f7f8
	ctx.lr = 0x8245FAA4;
	sub_8245F7F8(ctx, base);
	// b 0x8245fb0c
	goto loc_8245FB0C;
loc_8245FAA8:
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8245fae4
	if (!cr0.eq) goto loc_8245FAE4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8245f9b0
	if (!cr6.eq) goto loc_8245F9B0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r6,28(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245f568
	ctx.lr = 0x8245FAD4;
	sub_8245F568(ctx, base);
	// b 0x8245fb0c
	goto loc_8245FB0C;
loc_8245FAD8:
	// lbz r11,53(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 53);
	// rlwinm. r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8245faf0
	if (cr0.eq) goto loc_8245FAF0;
loc_8245FAE4:
	// lis r31,-16384
	r31.s64 = -1073741824;
	// ori r31,r31,13
	r31.u64 = r31.u64 | 13;
	// b 0x8245fb10
	goto loc_8245FB10;
loc_8245FAF0:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8245f9b0
	if (!cr6.eq) goto loc_8245F9B0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,28(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8245f448
	ctx.lr = 0x8245FB0C;
	sub_8245F448(ctx, base);
loc_8245FB0C:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8245FB10:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8245FB18;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r31,16(r27)
	PPC_STORE_U32(r27.u32 + 16, r31.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bdb04
	ctx.lr = 0x8245FB28;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8245FB30"))) PPC_WEAK_FUNC(sub_8245FB30);
PPC_FUNC_IMPL(__imp__sub_8245FB30) {
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
	ctx.lr = 0x8245FB38;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,64
	r11.s64 = 64;
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// li r23,0
	r23.s64 = 0;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r23.u32);
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// li r8,24
	ctx.r8.s64 = 24;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd8d4
	ctx.lr = 0x8245FB74;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245fbc4
	if (cr0.lt) goto loc_8245FBC4;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r11,8
	r11.s64 = 8;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lis r8,7
	ctx.r8.s64 = 458752;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bda44
	ctx.lr = 0x8245FBB0;
	__imp__NtDeviceIoControlFile(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8245fbcc
	if (!cr0.lt) goto loc_8245FBCC;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x8245FBC0;
	__imp__NtClose(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8245FBC4:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_8245FBCC:
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8245fbe4
	if (cr6.eq) goto loc_8245FBE4;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r11,r11,31
	xer.ca = r11.u32 <= 31;
	r11.s64 = 31 - r11.s64;
	// b 0x8245fbe8
	goto loc_8245FBE8;
loc_8245FBE4:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8245FBE8:
	// li r9,16
	ctx.r9.s64 = 16;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lis r8,7
	ctx.r8.s64 = 458752;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r8,16388
	ctx.r8.u64 = ctx.r8.u64 | 16388;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// clrlwi r22,r11,24
	r22.u64 = r11.u32 & 0xFF;
	// bl 0x827bda44
	ctx.lr = 0x8245FC24;
	__imp__NtDeviceIoControlFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8245fc48
	if (cr0.lt) goto loc_8245FC48;
	// ld r10,168(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// cmpdi cr6,r10,0
	cr6.compare<int64_t>(ctx.r10.s64, 0, xer);
	// bne cr6,0x8245fc40
	if (!cr6.eq) goto loc_8245FC40;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,52
	ctx.r3.u64 = ctx.r3.u64 | 52;
loc_8245FC40:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x8245fc5c
	if (!cr6.lt) goto loc_8245FC5C;
loc_8245FC48:
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8245FC4C:
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x8245FC54;
	__imp__NtClose(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// b 0x8245fbc4
	goto loc_8245FBC4;
loc_8245FC5C:
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r30,r11,0,0,19
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// cmplw cr6,r24,r30
	cr6.compare<uint32_t>(r24.u32, r30.u32, xer);
	// bge cr6,0x8245fc74
	if (!cr6.lt) goto loc_8245FC74;
	// mr r24,r30
	r24.u64 = r30.u64;
loc_8245FC74:
	// li r29,4096
	r29.s64 = 4096;
	// cmplwi cr6,r30,4096
	cr6.compare<uint32_t>(r30.u32, 4096, xer);
	// ble cr6,0x8245fc84
	if (!cr6.gt) goto loc_8245FC84;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_8245FC84:
	// clrldi r25,r29,32
	r25.u64 = r29.u64 & 0xFFFFFFFF;
	// cmpld cr6,r25,r10
	cr6.compare<uint64_t>(r25.u64, ctx.r10.u64, xer);
	// blt cr6,0x8245fc9c
	if (cr6.lt) goto loc_8245FC9C;
loc_8245FC90:
	// lis r28,-16384
	r28.s64 = -1073741824;
	// ori r28,r28,127
	r28.u64 = r28.u64 | 127;
	// b 0x8245fc4c
	goto loc_8245FC4C;
loc_8245FC9C:
	// clrldi r9,r24,32
	ctx.r9.u64 = r24.u64 & 0xFFFFFFFF;
	// rotldi r11,r10,1
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 1);
	// divd r8,r10,r9
	ctx.r8.s64 = ctx.r10.s64 / ctx.r9.s64;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// andc r8,r9,r7
	ctx.r8.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// tdllei r9,0
	// tdlgei r8,-1
	// cmplwi cr6,r11,65520
	cr6.compare<uint32_t>(r11.u32, 65520, xer);
	// bge cr6,0x8245fcd4
	if (!cr6.lt) goto loc_8245FCD4;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r26,1
	r26.s64 = 1;
	// b 0x8245fcdc
	goto loc_8245FCDC;
loc_8245FCD4:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_8245FCDC:
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r8,r30,-1
	ctx.r8.s64 = r30.s64 + -1;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// subf r11,r25,r10
	r11.s64 = ctx.r10.s64 - r25.s64;
	// andc r27,r7,r8
	r27.u64 = ctx.r7.u64 & ~ctx.r8.u64;
	// clrldi r10,r27,32
	ctx.r10.u64 = r27.u64 & 0xFFFFFFFF;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// bgt cr6,0x8245fc90
	if (cr6.gt) goto loc_8245FC90;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cmpld cr6,r9,r11
	cr6.compare<uint64_t>(ctx.r9.u64, r11.u64, xer);
	// bgt cr6,0x8245fc90
	if (cr6.gt) goto loc_8245FC90;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82132530
	ctx.lr = 0x8245FD14;
	sub_82132530(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8245fd28
	if (!cr0.eq) goto loc_8245FD28;
	// lis r28,-16384
	r28.s64 = -1073741824;
	// ori r28,r28,154
	r28.u64 = r28.u64 | 154;
	// b 0x8245fc4c
	goto loc_8245FC4C;
loc_8245FD28:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8245FD38;
	sub_823D9890(ctx, base);
	// std r23,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r23.u64);
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd904
	ctx.lr = 0x8245FD60;
	__imp__NtWriteFile(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// blt 0x8245fef0
	if (cr0.lt) goto loc_8245FEF0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8245FD78;
	sub_823D9890(ctx, base);
	// clrlwi. r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r25,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r25.u64);
	// beq 0x8245fd98
	if (cr0.eq) goto loc_8245FD98;
	// li r11,-8
	r11.s64 = -8;
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// sth r10,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r10.u16);
	// b 0x8245fda8
	goto loc_8245FDA8;
loc_8245FD98:
	// li r11,-8
	r11.s64 = -8;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_8245FDA8:
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd904
	ctx.lr = 0x8245FDCC;
	__imp__NtWriteFile(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// blt 0x8245fef0
	if (cr0.lt) goto loc_8245FEF0;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8245FDE4;
	sub_823D9890(ctx, base);
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// clrldi r11,r30,32
	r11.u64 = r30.u64 & 0xFFFFFFFF;
	// subf. r27,r30,r27
	r27.s64 = r27.s64 - r30.s64;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// bne 0x8245fda8
	if (!cr0.eq) goto loc_8245FDA8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8245FE0C;
	sub_823D9890(ctx, base);
	// mr r27,r24
	r27.u64 = r24.u64;
	// clrldi r26,r30,32
	r26.u64 = r30.u64 & 0xFFFFFFFF;
loc_8245FE14:
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd904
	ctx.lr = 0x8245FE38;
	__imp__NtWriteFile(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x8245feec
	if (cr0.lt) goto loc_8245FEEC;
	// ld r11,104(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// subf. r27,r30,r27
	r27.s64 = r27.s64 - r30.s64;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// bne 0x8245fe14
	if (!cr0.eq) goto loc_8245FE14;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8245FE64;
	sub_823D9890(ctx, base);
	// srw r11,r24,r22
	r11.u64 = r22.u8 & 0x20 ? 0 : (r24.u32 >> (r22.u8 & 0x3F));
	// lis r10,22612
	ctx.r10.s64 = 1481900032;
	// sth r23,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r23.u16);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// ori r10,r10,16710
	ctx.r10.u64 = ctx.r10.u64 | 16710;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// bl 0x827bda64
	ctx.lr = 0x8245FE90;
	__imp__KeQuerySystemTime(ctx, base);
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// std r23,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r23.u64);
loc_8245FE9C:
	// addi r10,r1,104
	ctx.r10.s64 = ctx.r1.s64 + 104;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd904
	ctx.lr = 0x8245FEC0;
	__imp__NtWriteFile(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// blt 0x8245fef0
	if (cr0.lt) goto loc_8245FEF0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8245FED8;
	sub_823D9890(ctx, base);
	// ld r11,104(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// subf. r29,r30,r29
	r29.s64 = r29.s64 - r30.s64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// bne 0x8245fe9c
	if (!cr0.eq) goto loc_8245FE9C;
loc_8245FEEC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8245FEF0:
	// bl 0x82132620
	ctx.lr = 0x8245FEF4;
	sub_82132620(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bdb74
	ctx.lr = 0x8245FEFC;
	__imp__IoDismountVolumeByFileHandle(ctx, base);
	// b 0x8245fc4c
	goto loc_8245FC4C;
}

__attribute__((alias("__imp__sub_8245FF00"))) PPC_WEAK_FUNC(sub_8245FF00);
PPC_FUNC_IMPL(__imp__sub_8245FF00) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd844
	ctx.lr = 0x8245FF28;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-4
	r11.s64 = -4;
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8245FF58"))) PPC_WEAK_FUNC(sub_8245FF58);
PPC_FUNC_IMPL(__imp__sub_8245FF58) {
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
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r11,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r11.u32);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x823da950
	ctx.lr = 0x8245FFCC;
	sub_823DA950(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stb r10,44(r11)
	PPC_STORE_U8(r11.u32 + 44, ctx.r10.u8);
	// stb r10,304(r30)
	PPC_STORE_U8(r30.u32 + 304, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8245FFF8"))) PPC_WEAK_FUNC(sub_8245FFF8);
PPC_FUNC_IMPL(__imp__sub_8245FFF8) {
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
	ctx.lr = 0x82460000;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lhz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// beq 0x82460068
	if (cr0.eq) goto loc_82460068;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
loc_82460054:
	// lbzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r7,92
	cr6.compare<uint32_t>(ctx.r7.u32, 92, xer);
	// beq cr6,0x82460068
	if (cr6.eq) goto loc_82460068;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82460054
	if (!cr0.eq) goto loc_82460054;
loc_82460068:
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// clrlwi. r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r10,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r10.u16);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// sth r10,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r10.u16);
	// sth r9,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, ctx.r9.u16);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// sth r9,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, ctx.r9.u16);
	// beq 0x82460164
	if (cr0.eq) goto loc_82460164;
	// clrlwi. r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82460164
	if (cr0.eq) goto loc_82460164;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x824600c8
	if (!cr6.eq) goto loc_824600C8;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,42
	cr6.compare<uint32_t>(ctx.r10.u32, 42, xer);
	// bne cr6,0x824600c8
	if (!cr6.eq) goto loc_824600C8;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r10,46
	cr6.compare<uint32_t>(ctx.r10.u32, 46, xer);
	// bne cr6,0x824600c8
	if (!cr6.eq) goto loc_824600C8;
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// cmplwi cr6,r11,42
	cr6.compare<uint32_t>(r11.u32, 42, xer);
	// bne cr6,0x824600c8
	if (!cr6.eq) goto loc_824600C8;
	// sth r31,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r31.u16);
loc_824600C8:
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// li r8,16417
	ctx.r8.s64 = 16417;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bd8d4
	ctx.lr = 0x824600E8;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8246016c
	if (cr0.lt) goto loc_8246016C;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82460128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82460140
	if (!cr0.lt) goto loc_82460140;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x82460138;
	__imp__NtClose(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x8246016c
	goto loc_8246016C;
loc_82460140:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82460154
	if (cr6.eq) goto loc_82460154;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x8246015c
	goto loc_8246015C;
loc_82460154:
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x827bceb4
	ctx.lr = 0x8246015C;
	__imp__NtClose(ctx, base);
loc_8246015C:
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// b 0x8246016c
	goto loc_8246016C;
loc_82460164:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
loc_8246016C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82460174"))) PPC_WEAK_FUNC(sub_82460174);
PPC_FUNC_IMPL(__imp__sub_82460174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82460178"))) PPC_WEAK_FUNC(sub_82460178);
PPC_FUNC_IMPL(__imp__sub_82460178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824601B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824601c4
	if (cr0.lt) goto loc_824601C4;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_824601C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824601D4"))) PPC_WEAK_FUNC(sub_824601D4);
PPC_FUNC_IMPL(__imp__sub_824601D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824601D8"))) PPC_WEAK_FUNC(sub_824601D8);
PPC_FUNC_IMPL(__imp__sub_824601D8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,1
	r11.s64 = 1;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r10,-3
	ctx.r10.s64 = -3;
	// li r9,64
	ctx.r9.s64 = 64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r8,16417
	ctx.r8.s64 = 16417;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lis r4,17
	ctx.r4.s64 = 1114112;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x827bd8d4
	ctx.lr = 0x82460220;
	__imp__NtOpenFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8246025c
	if (cr0.lt) goto loc_8246025C;
	// li r7,13
	ctx.r7.s64 = 13;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd9b4
	ctx.lr = 0x82460240;
	__imp__NtSetInformationFile(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x827bceb4
	ctx.lr = 0x8246024C;
	__imp__NtClose(ctx, base);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8246025c
	if (!cr6.lt) goto loc_8246025C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8246025C:
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

__attribute__((alias("__imp__sub_82460270"))) PPC_WEAK_FUNC(sub_82460270);
PPC_FUNC_IMPL(__imp__sub_82460270) {
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
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824602a0
	if (cr6.eq) goto loc_824602A0;
	// clrldi r11,r3,32
	r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// mulli r11,r11,-10000
	r11.s64 = r11.s64 * -10000;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// b 0x824602b0
	goto loc_824602B0;
loc_824602A0:
	// lis r11,-32768
	r11.s64 = -2147483648;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
loc_824602B0:
	// clrlwi r30,r31,24
	r30.u64 = r31.u32 & 0xFF;
loc_824602B4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827bdbb4
	ctx.lr = 0x824602C4;
	__imp__KeDelayExecutionThread(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824602d4
	if (cr6.eq) goto loc_824602D4;
	// cmpwi cr6,r3,257
	cr6.compare<int32_t>(ctx.r3.s32, 257, xer);
	// beq cr6,0x824602b4
	if (cr6.eq) goto loc_824602B4;
loc_824602D4:
	// cmpwi cr6,r3,192
	cr6.compare<int32_t>(ctx.r3.s32, 192, xer);
	// li r3,192
	ctx.r3.s64 = 192;
	// beq cr6,0x824602e4
	if (cr6.eq) goto loc_824602E4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_824602E4:
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

__attribute__((alias("__imp__sub_824602FC"))) PPC_WEAK_FUNC(sub_824602FC);
PPC_FUNC_IMPL(__imp__sub_824602FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82460300"))) PPC_WEAK_FUNC(sub_82460300);
PPC_FUNC_IMPL(__imp__sub_82460300) {
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
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// rlwinm r9,r7,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x82460330
	if (cr6.eq) goto loc_82460330;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// rlwinm r10,r10,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000;
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
loc_82460330:
	// lis r10,-32186
	ctx.r10.s64 = -2109341696;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r6,r10,3848
	ctx.r6.s64 = ctx.r10.s64 + 3848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd5d4
	ctx.lr = 0x82460348;
	__imp__ExCreateThread(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8246035c
	if (!cr0.lt) goto loc_8246035C;
	// bl 0x82135d58
	ctx.lr = 0x82460354;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82460360
	goto loc_82460360;
loc_8246035C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82460360:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82460370"))) PPC_WEAK_FUNC(sub_82460370);
PPC_FUNC_IMPL(__imp__sub_82460370) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lis r11,30403
	r11.s64 = 1992491008;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62033
	r11.u64 = r11.u64 | 62033;
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x82461378
	ctx.lr = 0x824603A0;
	sub_82461378(ctx, base);
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

__attribute__((alias("__imp__sub_824603B8"))) PPC_WEAK_FUNC(sub_824603B8);
PPC_FUNC_IMPL(__imp__sub_824603B8) {
	PPC_FUNC_PROLOGUE();
	// b 0x824613f0
	sub_824613F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824603BC"))) PPC_WEAK_FUNC(sub_824603BC);
PPC_FUNC_IMPL(__imp__sub_824603BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824603C0"))) PPC_WEAK_FUNC(sub_824603C0);
PPC_FUNC_IMPL(__imp__sub_824603C0) {
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
	// bl 0x82460f88
	ctx.lr = 0x824603D0;
	sub_82460F88(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x82460408
	if (cr6.lt) goto loc_82460408;
	// beq cr6,0x824603fc
	if (cr6.eq) goto loc_824603FC;
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// beq cr6,0x824603f0
	if (cr6.eq) goto loc_824603F0;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8246040c
	goto loc_8246040C;
loc_824603F0:
	// lis r3,-32290
	ctx.r3.s64 = -2116157440;
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// b 0x8246040c
	goto loc_8246040C;
loc_824603FC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8246040c
	goto loc_8246040C;
loc_82460408:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8246040C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8246041C"))) PPC_WEAK_FUNC(sub_8246041C);
PPC_FUNC_IMPL(__imp__sub_8246041C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82460420"))) PPC_WEAK_FUNC(sub_82460420);
PPC_FUNC_IMPL(__imp__sub_82460420) {
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
	// bl 0x82461010
	ctx.lr = 0x82460430;
	sub_82461010(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x82460468
	if (cr6.lt) goto loc_82460468;
	// beq cr6,0x8246045c
	if (cr6.eq) goto loc_8246045C;
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// beq cr6,0x82460450
	if (cr6.eq) goto loc_82460450;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x8246046c
	goto loc_8246046C;
loc_82460450:
	// lis r3,-32290
	ctx.r3.s64 = -2116157440;
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// b 0x8246046c
	goto loc_8246046C;
loc_8246045C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8246046c
	goto loc_8246046C;
loc_82460468:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8246046C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8246047C"))) PPC_WEAK_FUNC(sub_8246047C);
PPC_FUNC_IMPL(__imp__sub_8246047C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82460480"))) PPC_WEAK_FUNC(sub_82460480);
PPC_FUNC_IMPL(__imp__sub_82460480) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,14552(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14552);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824605c8
	if (!cr6.eq) goto loc_824605C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r11,2024(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2024);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824605c0
	if (cr6.eq) goto loc_824605C0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r11,2412(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2412);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm. r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824605c0
	if (cr0.eq) goto loc_824605C0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-22644
	ctx.r3.s64 = r11.s64 + -22644;
	// bl 0x827bd894
	ctx.lr = 0x824604E0;
	__imp__XexGetModuleHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824605c0
	if (cr6.eq) goto loc_824605C0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,155
	ctx.r4.s64 = 155;
	// bl 0x827bd884
	ctx.lr = 0x82460500;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,156
	ctx.r4.s64 = 156;
	// bl 0x827bd884
	ctx.lr = 0x82460518;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,157
	ctx.r4.s64 = 157;
	// bl 0x827bd884
	ctx.lr = 0x82460530;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,158
	ctx.r4.s64 = 158;
	// bl 0x827bd884
	ctx.lr = 0x82460548;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,159
	ctx.r4.s64 = 159;
	// bl 0x827bd884
	ctx.lr = 0x82460560;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,160
	ctx.r4.s64 = 160;
	// bl 0x827bd884
	ctx.lr = 0x82460578;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824605c0
	if (cr0.lt) goto loc_824605C0;
	// lis r8,-32107
	ctx.r8.s64 = -2104164352;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r7,r8,-23168
	ctx.r7.s64 = ctx.r8.s64 + -23168;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// stw r10,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r10.u32);
	// stw r9,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r9.u32);
	// lwsync 
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r11,-23168(r8)
	PPC_STORE_U32(ctx.r8.u32 + -23168, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r9.u32);
	// lwsync 
loc_824605C0:
	// li r11,1
	r11.s64 = 1;
	// stw r11,14552(r31)
	PPC_STORE_U32(r31.u32 + 14552, r11.u32);
loc_824605C8:
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

__attribute__((alias("__imp__sub_824605DC"))) PPC_WEAK_FUNC(sub_824605DC);
PPC_FUNC_IMPL(__imp__sub_824605DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824605E0"))) PPC_WEAK_FUNC(sub_824605E0);
PPC_FUNC_IMPL(__imp__sub_824605E0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x827bd844
	ctx.lr = 0x82460600;
	__imp__RtlInitAnsiString(ctx, base);
	// li r11,-3
	r11.s64 = -3;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x827bd9c4
	ctx.lr = 0x82460624;
	__imp__NtQueryFullAttributesFile(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x82460664
	if (cr0.lt) goto loc_82460664;
	// lwz r11,160(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// li r3,1
	ctx.r3.s64 = 1;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// ld r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// lwz r7,152(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// std r10,4(r31)
	PPC_STORE_U64(r31.u32 + 4, ctx.r10.u64);
	// std r9,12(r31)
	PPC_STORE_U64(r31.u32 + 12, ctx.r9.u64);
	// std r8,20(r31)
	PPC_STORE_U64(r31.u32 + 20, ctx.r8.u64);
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// stw r6,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r6.u32);
	// b 0x8246066c
	goto loc_8246066C;
loc_82460664:
	// bl 0x82135d58
	ctx.lr = 0x82460668;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8246066C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82460680"))) PPC_WEAK_FUNC(sub_82460680);
PPC_FUNC_IMPL(__imp__sub_82460680) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x827bdbc4
	ctx.lr = 0x82460690;
	__imp__XexUnloadImage(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x824606a4
	if (!cr0.lt) goto loc_824606A4;
	// bl 0x821326a0
	ctx.lr = 0x8246069C;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824606a8
	goto loc_824606A8;
loc_824606A4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824606A8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824606B8"))) PPC_WEAK_FUNC(sub_824606B8);
PPC_FUNC_IMPL(__imp__sub_824606B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd884
	ctx.lr = 0x824606CC;
	__imp__XexGetProcedureAddress(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x824606e0
	if (!cr0.lt) goto loc_824606E0;
	// bl 0x821326a0
	ctx.lr = 0x824606D8;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824606e4
	goto loc_824606E4;
loc_824606E0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_824606E4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824606F4"))) PPC_WEAK_FUNC(sub_824606F4);
PPC_FUNC_IMPL(__imp__sub_824606F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824606F8"))) PPC_WEAK_FUNC(sub_824606F8);
PPC_FUNC_IMPL(__imp__sub_824606F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x827bdbd4
	ctx.lr = 0x82460714;
	__imp__XexLoadImage(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x82460728
	if (!cr0.lt) goto loc_82460728;
	// bl 0x821326a0
	ctx.lr = 0x82460720;
	sub_821326A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8246072c
	goto loc_8246072C;
loc_82460728:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8246072C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8246073C"))) PPC_WEAK_FUNC(sub_8246073C);
PPC_FUNC_IMPL(__imp__sub_8246073C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82460740"))) PPC_WEAK_FUNC(sub_82460740);
PPC_FUNC_IMPL(__imp__sub_82460740) {
	PPC_FUNC_PROLOGUE();
	// lhz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82461440
	sub_82461440(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8246074C"))) PPC_WEAK_FUNC(sub_8246074C);
PPC_FUNC_IMPL(__imp__sub_8246074C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82460750"))) PPC_WEAK_FUNC(sub_82460750);
PPC_FUNC_IMPL(__imp__sub_82460750) {
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
	ctx.lr = 0x82460758;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x8244fd08
	ctx.lr = 0x82460778;
	sub_8244FD08(ctx, base);
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x824607b0
	if (cr0.eq) goto loc_824607B0;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82461448
	ctx.lr = 0x82460790;
	sub_82461448(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82460990
	if (cr0.eq) goto loc_82460990;
	// ld r11,0(r20)
	r11.u64 = PPC_LOAD_U64(r20.u32 + 0);
	// ld r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U64(r21.u32 + 0);
	// cmpd cr6,r11,r10
	cr6.compare<int64_t>(r11.s64, ctx.r10.s64, xer);
	// blt cr6,0x82460990
	if (cr6.lt) goto loc_82460990;
loc_824607A8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82460994
	goto loc_82460994;
loc_824607B0:
	// lha r22,6(r29)
	r22.s64 = int16_t(PPC_LOAD_U16(r29.u32 + 6));
	// cmpwi cr6,r22,5
	cr6.compare<int32_t>(r22.s32, 5, xer);
	// bgt cr6,0x82460990
	if (cr6.gt) goto loc_82460990;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// beq cr6,0x82460990
	if (cr6.eq) goto loc_82460990;
	// li r23,0
	r23.s64 = 0;
	// lhz r25,2(r29)
	r25.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// clrlwi. r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lhz r31,4(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r24,1
	r24.s64 = 1;
	// mr r26,r23
	r26.u64 = r23.u64;
	// bne 0x82460810
	if (!cr0.eq) goto loc_82460810;
	// lhz r11,114(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// extsh r10,r25
	ctx.r10.s64 = r25.s16;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82460800
	if (!cr6.lt) goto loc_82460800;
	// lhz r11,112(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsh r28,r11
	r28.s64 = r11.s16;
	// b 0x82460814
	goto loc_82460814;
loc_82460800:
	// lhz r28,112(r1)
	r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
	// bgt cr6,0x82460814
	if (cr6.gt) goto loc_82460814;
	// mr r26,r24
	r26.u64 = r24.u64;
	// b 0x82460814
	goto loc_82460814;
loc_82460810:
	// lhz r28,112(r1)
	r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
loc_82460814:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lhz r10,10(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// lhz r8,14(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// sth r28,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, r28.u16);
	// sth r25,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r25.u16);
	// sth r24,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r24.u16);
	// sth r11,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r11.u16);
	// sth r10,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r10.u16);
	// sth r9,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r9.u16);
	// sth r23,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r23.u16);
	// sth r8,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r8.u16);
	// bl 0x827bdaf4
	ctx.lr = 0x82460850;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82460990
	if (cr0.eq) goto loc_82460990;
	// extsh r27,r31
	r27.s64 = r31.s16;
loc_8246085C:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd9e4
	ctx.lr = 0x82460868;
	__imp__RtlTimeToTimeFields(ctx, base);
	// lha r11,142(r1)
	r11.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 142));
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// ble cr6,0x8246088c
	if (!cr6.gt) goto loc_8246088C;
	// lha r10,100(r1)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 100));
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
loc_82460884:
	// extsh r11,r11
	r11.s64 = r11.s16;
	// b 0x824608a4
	goto loc_824608A4;
loc_8246088C:
	// bge cr6,0x824608a0
	if (!cr6.lt) goto loc_824608A0;
	// lhz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82460884
	goto loc_82460884;
loc_824608A0:
	// lhz r11,100(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
loc_824608A4:
	// mr r30,r11
	r30.u64 = r11.u64;
	// mr r31,r24
	r31.u64 = r24.u64;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// ble cr6,0x824608fc
	if (!cr6.gt) goto loc_824608FC;
	// b 0x824608bc
	goto loc_824608BC;
loc_824608B8:
	// lhz r11,100(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
loc_824608BC:
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r11.u16);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bdaf4
	ctx.lr = 0x824608D0;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824608fc
	if (cr0.eq) goto loc_824608FC;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827bd9e4
	ctx.lr = 0x824608E4;
	__imp__RtlTimeToTimeFields(ctx, base);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// extsh r31,r11
	r31.s64 = r11.s16;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpw cr6,r11,r22
	cr6.compare<int32_t>(r11.s32, r22.s32, xer);
	// lhz r30,132(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 132);
	// blt cr6,0x824608b8
	if (cr6.lt) goto loc_824608B8;
loc_824608FC:
	// sth r30,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r30.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827bdaf4
	ctx.lr = 0x8246090C;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82460990
	if (cr0.eq) goto loc_82460990;
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi. r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8246099c
	if (cr0.eq) goto loc_8246099C;
	// lhz r11,118(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 118);
	// lha r10,100(r1)
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + 100));
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82460940
	if (cr6.lt) goto loc_82460940;
	// bne cr6,0x8246099c
	if (!cr6.eq) goto loc_8246099C;
	// ld r11,0(r21)
	r11.u64 = PPC_LOAD_U64(r21.u32 + 0);
	// cmpd cr6,r9,r11
	cr6.compare<int64_t>(ctx.r9.s64, r11.s64, xer);
	// bge cr6,0x8246099c
	if (!cr6.lt) goto loc_8246099C;
loc_82460940:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lhz r10,10(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// lhz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// extsh r28,r11
	r28.s64 = r11.s16;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// lhz r8,14(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 14);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// sth r28,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, r28.u16);
	// mr r26,r23
	r26.u64 = r23.u64;
	// sth r10,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r10.u16);
	// sth r25,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r25.u16);
	// sth r11,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r11.u16);
	// sth r9,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r9.u16);
	// sth r24,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r24.u16);
	// sth r8,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, ctx.r8.u16);
	// sth r23,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r23.u16);
	// bl 0x827bdaf4
	ctx.lr = 0x82460988;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8246085c
	if (!cr0.eq) goto loc_8246085C;
loc_82460990:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82460994:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9228
	return;
loc_8246099C:
	// std r9,0(r20)
	PPC_STORE_U64(r20.u32 + 0, ctx.r9.u64);
	// b 0x824607a8
	goto loc_824607A8;
}

__attribute__((alias("__imp__sub_824609A4"))) PPC_WEAK_FUNC(sub_824609A4);
PPC_FUNC_IMPL(__imp__sub_824609A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824609A8"))) PPC_WEAK_FUNC(sub_824609A8);
PPC_FUNC_IMPL(__imp__sub_824609A8) {
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
	ctx.lr = 0x824609B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// sth r30,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r30.u16);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x827bced4
	ctx.lr = 0x824609EC;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x824609fc
	if (!cr0.lt) goto loc_824609FC;
loc_824609F4:
	// bl 0x827bd024
	ctx.lr = 0x824609F8;
	__imp__RtlNtStatusToDosError(ctx, base);
	// b 0x82460bd0
	goto loc_82460BD0;
loc_824609FC:
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x827bced4
	ctx.lr = 0x82460A1C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// addi r8,r31,4
	ctx.r8.s64 = r31.s64 + 4;
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// li r11,4
	r11.s64 = 4;
loc_82460A34:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r7,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r7.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bne 0x82460a34
	if (!cr0.eq) goto loc_82460A34;
	// sth r30,8(r8)
	PPC_STORE_U16(ctx.r8.u32 + 8, r30.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x827bced4
	ctx.lr = 0x82460A68;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// addi r8,r31,88
	ctx.r8.s64 = r31.s64 + 88;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// li r11,4
	r11.s64 = 4;
loc_82460A80:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r7,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r7.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bne 0x82460a80
	if (!cr0.eq) goto loc_82460A80;
	// sth r30,8(r8)
	PPC_STORE_U16(ctx.r8.u32 + 8, r30.u16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x827bced4
	ctx.lr = 0x82460AB4;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82460ACC;
	sub_823D9890(ctx, base);
	// lbz r11,84(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r9,86(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,5
	ctx.r4.s64 = 5;
	// sth r11,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r11.u16);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// sth r10,74(r31)
	PPC_STORE_U16(r31.u32 + 74, ctx.r10.u16);
	// li r3,3
	ctx.r3.s64 = 3;
	// sth r9,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r9.u16);
	// sth r11,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r11.u16);
	// bl 0x827bced4
	ctx.lr = 0x82460B08;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82460B20;
	sub_823D9890(ctx, base);
	// lbz r11,88(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// lbz r10,89(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lbz r9,90(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 90);
	// li r6,4
	ctx.r6.s64 = 4;
	// lbz r8,91(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 91);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,6
	ctx.r4.s64 = 6;
	// sth r11,154(r31)
	PPC_STORE_U16(r31.u32 + 154, r11.u16);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// sth r10,158(r31)
	PPC_STORE_U16(r31.u32 + 158, ctx.r10.u16);
	// li r3,3
	ctx.r3.s64 = 3;
	// sth r9,156(r31)
	PPC_STORE_U16(r31.u32 + 156, ctx.r9.u16);
	// sth r11,160(r31)
	PPC_STORE_U16(r31.u32 + 160, r11.u16);
	// bl 0x827bced4
	ctx.lr = 0x82460B5C;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// bl 0x827bced4
	ctx.lr = 0x82460B84;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// beq cr6,0x82460bcc
	if (cr6.eq) goto loc_82460BCC;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// li r4,12
	ctx.r4.s64 = 12;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x827bced4
	ctx.lr = 0x82460BB4;
	__imp__ExGetXConfigSetting(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x824609f4
	if (cr0.lt) goto loc_824609F4;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwinm r11,r11,31,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_82460BCC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82460BD0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82460BD8"))) PPC_WEAK_FUNC(sub_82460BD8);
PPC_FUNC_IMPL(__imp__sub_82460BD8) {
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
	ctx.lr = 0x82460BE0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x82460c1c
	if (!cr6.eq) goto loc_82460C1C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82460BFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82460bfc
	if (!cr6.eq) goto loc_82460BFC;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
loc_82460C1C:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x82460dac
	if (!cr6.gt) goto loc_82460DAC;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r31,0
	r31.s64 = 0;
	// lis r26,-32129
	r26.s64 = -2105606144;
	// lis r25,-32129
	r25.s64 = -2105606144;
	// lis r27,-32129
	r27.s64 = -2105606144;
	// lis r28,-32129
	r28.s64 = -2105606144;
	// lis r24,-32129
	r24.s64 = -2105606144;
	// lis r21,-32129
	r21.s64 = -2105606144;
	// lis r20,-32129
	r20.s64 = -2105606144;
	// lis r22,-32129
	r22.s64 = -2105606144;
	// addi r23,r9,14848
	r23.s64 = ctx.r9.s64 + 14848;
	// addi r30,r11,14872
	r30.s64 = r11.s64 + 14872;
loc_82460C58:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// lbzx r9,r8,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r30.u32);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// subf r7,r29,r9
	ctx.r7.s64 = ctx.r9.s64 - r29.s64;
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmpw cr6,r7,r4
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, xer);
	// bgt cr6,0x82460dac
	if (cr6.gt) goto loc_82460DAC;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// blt cr6,0x82460cfc
	if (cr6.lt) goto loc_82460CFC;
	// beq cr6,0x82460ce8
	if (cr6.eq) goto loc_82460CE8;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// blt cr6,0x82460cd4
	if (cr6.lt) goto loc_82460CD4;
	// beq cr6,0x82460cc0
	if (cr6.eq) goto loc_82460CC0;
	// cmplwi cr6,r9,5
	cr6.compare<uint32_t>(ctx.r9.u32, 5, xer);
	// blt cr6,0x82460cac
	if (cr6.lt) goto loc_82460CAC;
	// bne cr6,0x82460d0c
	if (!cr6.eq) goto loc_82460D0C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
loc_82460CAC:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_82460CC0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_82460CD4:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_82460CE8:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
loc_82460CFC:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
loc_82460D0C:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,14820(r22)
	ctx.r8.u64 = PPC_LOAD_U32(r22.u32 + 14820);
	// lwzx r9,r9,r23
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r23.u32);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bgt cr6,0x82460d34
	if (cr6.gt) goto loc_82460D34;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r3,r6
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82460da4
	if (cr6.gt) goto loc_82460DA4;
	// b 0x82460d9c
	goto loc_82460D9C;
loc_82460D34:
	// lwz r9,14824(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 14824);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x82460d54
	if (!cr6.gt) goto loc_82460D54;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r3,r6
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82460da4
	if (cr6.gt) goto loc_82460DA4;
	// lwz r11,14816(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 14816);
	// b 0x82460d9c
	goto loc_82460D9C;
loc_82460D54:
	// lwz r9,14832(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 14832);
	// addi r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 1;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82460d80
	if (cr6.gt) goto loc_82460D80;
	// lwz r9,14828(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 14828);
	// lwz r8,14840(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 14840);
	// srw r9,r11,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r9.u8 & 0x3F));
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r9,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, ctx.r9.u16);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
loc_82460D80:
	// addi r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r3,r6
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82460da4
	if (cr6.gt) goto loc_82460DA4;
	// lwz r9,14836(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 14836);
	// lwz r8,14844(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 14844);
	// and r11,r9,r11
	r11.u64 = ctx.r9.u64 & r11.u64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
loc_82460D9C:
	// sth r11,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, r11.u16);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
loc_82460DA4:
	// cmpw cr6,r31,r4
	cr6.compare<int32_t>(r31.s32, ctx.r4.s32, xer);
	// blt cr6,0x82460c58
	if (cr6.lt) goto loc_82460C58;
loc_82460DAC:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x82460dc8
	if (cr6.eq) goto loc_82460DC8;
	// cmpw cr6,r6,r3
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, xer);
	// bge cr6,0x82460dc8
	if (!cr6.lt) goto loc_82460DC8;
	// li r3,122
	ctx.r3.s64 = 122;
	// bl 0x82135d38
	ctx.lr = 0x82460DC4;
	sub_82135D38(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82460DC8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82460DD0"))) PPC_WEAK_FUNC(sub_82460DD0);
PPC_FUNC_IMPL(__imp__sub_82460DD0) {
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
	ctx.lr = 0x82460DD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x82460dfc
	if (!cr6.eq) goto loc_82460DFC;
	// bl 0x823de3a8
	ctx.lr = 0x82460DF8;
	sub_823DE3A8(ctx, base);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
loc_82460DFC:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x82460ed4
	if (!cr6.gt) goto loc_82460ED4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82460E08:
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bgt cr6,0x82460e34
	if (cr6.gt) goto loc_82460E34;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// bgt cr6,0x82460ec8
	if (cr6.gt) goto loc_82460EC8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82460ec8
	if (cr6.eq) goto loc_82460EC8;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// b 0x82460ec4
	goto loc_82460EC4;
loc_82460E34:
	// cmplwi cr6,r11,2047
	cr6.compare<uint32_t>(r11.u32, 2047, xer);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// bgt cr6,0x82460e5c
	if (cr6.gt) goto loc_82460E5C;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bgt cr6,0x82460ea4
	if (cr6.gt) goto loc_82460EA4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82460ea4
	if (cr6.eq) goto loc_82460EA4;
	// li r8,192
	ctx.r8.s64 = 192;
	// rlwimi r8,r10,26,27,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 26) & 0x1F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFE0);
	// b 0x82460e9c
	goto loc_82460E9C;
loc_82460E5C:
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bgt cr6,0x82460e7c
	if (cr6.gt) goto loc_82460E7C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82460e7c
	if (cr6.eq) goto loc_82460E7C;
	// li r8,224
	ctx.r8.s64 = 224;
	// rlwimi r8,r10,20,28,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 20) & 0xF) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFF0);
	// stb r8,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r8.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82460E7C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bgt cr6,0x82460ea4
	if (cr6.gt) goto loc_82460EA4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82460ea4
	if (cr6.eq) goto loc_82460EA4;
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// li r8,128
	ctx.r8.s64 = 128;
	// rlwimi r8,r10,26,26,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 26) & 0x3F) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFC0);
loc_82460E9C:
	// stb r8,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r8.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82460EA4:
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// bgt cr6,0x82460ec8
	if (cr6.gt) goto loc_82460EC8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82460ec8
	if (cr6.eq) goto loc_82460EC8;
	// lhz r11,0(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// rlwimi r11,r9,7,0,25
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 7) & 0xFFFFFFC0) | (r11.u64 & 0xFFFFFFFF0000003F);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
loc_82460EC4:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82460EC8:
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// bne 0x82460e08
	if (!cr0.eq) goto loc_82460E08;
loc_82460ED4:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82460ef4
	if (cr6.eq) goto loc_82460EF4;
	// cmpw cr6,r29,r30
	cr6.compare<int32_t>(r29.s32, r30.s32, xer);
	// bge cr6,0x82460ef4
	if (!cr6.lt) goto loc_82460EF4;
	// li r3,122
	ctx.r3.s64 = 122;
	// bl 0x82135d38
	ctx.lr = 0x82460EEC;
	sub_82135D38(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82460ef8
	goto loc_82460EF8;
loc_82460EF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82460EF8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82460F00"))) PPC_WEAK_FUNC(sub_82460F00);
PPC_FUNC_IMPL(__imp__sub_82460F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,10008(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 10008);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82460F10;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82132898
	ctx.lr = 0x82460F38;
	sub_82132898(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r30
	ctr.u64 = r30.u64;
	// bctrl 
	ctx.lr = 0x82460F44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82132898
	ctx.lr = 0x82460F50;
	sub_82132898(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x827bda24
	ctx.lr = 0x82460F64;
	__imp__ExTerminateThread(ctx, base);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82131f00
	ctx.lr = 0x82460F74;
	sub_82131F00(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82460F08"))) PPC_WEAK_FUNC(sub_82460F08);
PPC_FUNC_IMPL(__imp__sub_82460F08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82460F10;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82132898
	ctx.lr = 0x82460F38;
	sub_82132898(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r30
	ctr.u64 = r30.u64;
	// bctrl 
	ctx.lr = 0x82460F44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82132898
	ctx.lr = 0x82460F50;
	sub_82132898(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x827bda24
	ctx.lr = 0x82460F64;
	__imp__ExTerminateThread(ctx, base);
}

__attribute__((alias("__imp__sub_82460F64"))) PPC_WEAK_FUNC(sub_82460F64);
PPC_FUNC_IMPL(__imp__sub_82460F64) {
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
	// bl 0x82131f00
	ctx.lr = 0x82460F74;
	sub_82131F00(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82460F88"))) PPC_WEAK_FUNC(sub_82460F88);
PPC_FUNC_IMPL(__imp__sub_82460F88) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r30,20
	r31.s64 = r30.s64 + 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824614e8
	ctx.lr = 0x82460FAC;
	sub_824614E8(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82460fc4
	if (cr0.eq) goto loc_82460FC4;
	// li r11,0
	r11.s64 = 0;
	// stb r11,12284(r31)
	PPC_STORE_U8(r31.u32 + 12284, r11.u8);
	// b 0x82460fe4
	goto loc_82460FE4;
loc_82460FC4:
	// rlwinm. r11,r11,0,0,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82460ff0
	if (cr0.eq) goto loc_82460FF0;
	// li r11,0
	r11.s64 = 0;
	// stw r11,12276(r31)
	PPC_STORE_U32(r31.u32 + 12276, r11.u32);
	// stw r11,12284(r31)
	PPC_STORE_U32(r31.u32 + 12284, r11.u32);
	// stw r11,12288(r31)
	PPC_STORE_U32(r31.u32 + 12288, r11.u32);
	// stw r11,12292(r31)
	PPC_STORE_U32(r31.u32 + 12292, r11.u32);
	// stw r11,12296(r31)
	PPC_STORE_U32(r31.u32 + 12296, r11.u32);
loc_82460FE4:
	// stw r11,12280(r31)
	PPC_STORE_U32(r31.u32 + 12280, r11.u32);
	// stw r11,12272(r31)
	PPC_STORE_U32(r31.u32 + 12272, r11.u32);
	// stw r11,12268(r31)
	PPC_STORE_U32(r31.u32 + 12268, r11.u32);
loc_82460FF0:
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

__attribute__((alias("__imp__sub_8246100C"))) PPC_WEAK_FUNC(sub_8246100C);
PPC_FUNC_IMPL(__imp__sub_8246100C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461010"))) PPC_WEAK_FUNC(sub_82461010);
PPC_FUNC_IMPL(__imp__sub_82461010) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x82461018;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// lbz r11,12304(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12304);
	// li r17,0
	r17.s64 = 0;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r15,r7
	r15.u64 = ctx.r7.u64;
	// lwz r18,0(r16)
	r18.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r31,r3,20
	r31.s64 = ctx.r3.s64 + 20;
	// mr r24,r17
	r24.u64 = r17.u64;
	// mr r21,r17
	r21.u64 = r17.u64;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// mr r22,r17
	r22.u64 = r17.u64;
	// bne 0x82461054
	if (!cr0.eq) goto loc_82461054;
	// lwz r22,0(r15)
	r22.u64 = PPC_LOAD_U32(r15.u32 + 0);
loc_82461054:
	// lwz r28,12272(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12272);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8246109c
	if (cr6.eq) goto loc_8246109C;
	// cmplw cr6,r28,r18
	cr6.compare<uint32_t>(r28.u32, r18.u32, xer);
	// mr r30,r28
	r30.u64 = r28.u64;
	// blt cr6,0x82461070
	if (cr6.lt) goto loc_82461070;
	// mr r30,r18
	r30.u64 = r18.u64;
loc_82461070:
	// lwz r11,12264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12264);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r29,12268(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 12268);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x823da950
	ctx.lr = 0x82461088;
	sub_823DA950(ctx, base);
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// add r10,r29,r30
	ctx.r10.u64 = r29.u64 + r30.u64;
	// stw r11,12272(r31)
	PPC_STORE_U32(r31.u32 + 12272, r11.u32);
	// mr r21,r30
	r21.u64 = r30.u64;
	// stw r10,12268(r31)
	PPC_STORE_U32(r31.u32 + 12268, ctx.r10.u32);
loc_8246109C:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x824610b0
	if (!cr6.eq) goto loc_824610B0;
	// lwz r11,12280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12280);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x824612f0
	if (!cr6.gt) goto loc_824612F0;
loc_824610B0:
	// lwz r29,12280(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 12280);
	// mr r28,r22
	r28.u64 = r22.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8246117c
	if (cr6.eq) goto loc_8246117C;
	// lwz r27,12276(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 12276);
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x824610dc
	if (!cr6.eq) goto loc_824610DC;
	// li r26,5
	r26.s64 = 5;
	// addi r25,r27,3
	r25.s64 = r27.s64 + 3;
	// b 0x824610e4
	goto loc_824610E4;
loc_824610DC:
	// li r26,2
	r26.s64 = 2;
	// mr r25,r27
	r25.u64 = r27.u64;
loc_824610E4:
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// bge cr6,0x8246111c
	if (!cr6.lt) goto loc_8246111C;
	// subf r30,r29,r26
	r30.s64 = r26.s64 - r29.s64;
	// cmplw cr6,r30,r22
	cr6.compare<uint32_t>(r30.u32, r22.u32, xer);
	// blt cr6,0x824610fc
	if (cr6.lt) goto loc_824610FC;
	// mr r30,r22
	r30.u64 = r22.u64;
loc_824610FC:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// add r3,r29,r27
	ctx.r3.u64 = r29.u64 + r27.u64;
	// bl 0x823da950
	ctx.lr = 0x8246110C;
	sub_823DA950(ctx, base);
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// mr r24,r30
	r24.u64 = r30.u64;
	// stw r11,12280(r31)
	PPC_STORE_U32(r31.u32 + 12280, r11.u32);
	// subf r28,r30,r22
	r28.s64 = r22.s64 - r30.s64;
loc_8246111C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82461180
	if (cr6.eq) goto loc_82461180;
	// lbz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 0);
	// subf r11,r24,r22
	r11.s64 = r22.s64 - r24.s64;
	// lbz r9,1(r25)
	ctx.r9.u64 = PPC_LOAD_U8(r25.u32 + 1);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lwz r30,12280(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12280);
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// add r28,r10,r26
	r28.u64 = ctx.r10.u64 + r26.u64;
	// subf r29,r30,r28
	r29.s64 = r28.s64 - r30.s64;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82461150
	if (cr6.lt) goto loc_82461150;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82461150:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r24,r20
	ctx.r4.u64 = r24.u64 + r20.u64;
	// add r3,r30,r27
	ctx.r3.u64 = r30.u64 + r27.u64;
	// bl 0x823da950
	ctx.lr = 0x82461160;
	sub_823DA950(ctx, base);
	// add r11,r30,r29
	r11.u64 = r30.u64 + r29.u64;
	// add r24,r29,r24
	r24.u64 = r29.u64 + r24.u64;
	// stw r11,12280(r31)
	PPC_STORE_U32(r31.u32 + 12280, r11.u32);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bge cr6,0x82461180
	if (!cr6.lt) goto loc_82461180;
	// mr r28,r17
	r28.u64 = r17.u64;
	// b 0x82461180
	goto loc_82461180;
loc_8246117C:
	// mr r27,r20
	r27.u64 = r20.u64;
loc_82461180:
	// lwz r11,12272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824612f0
	if (!cr6.eq) goto loc_824612F0;
	// lwz r25,80(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82461190:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824612f0
	if (cr6.eq) goto loc_824612F0;
	// stw r17,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r17.u32);
	// lbz r23,0(r27)
	r23.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r23,255
	cr6.compare<uint32_t>(r23.u32, 255, xer);
	// bne cr6,0x824611e4
	if (!cr6.eq) goto loc_824611E4;
	// li r10,5
	ctx.r10.s64 = 5;
	// cmplwi cr6,r28,5
	cr6.compare<uint32_t>(r28.u32, 5, xer);
	// blt cr6,0x824611dc
	if (cr6.lt) goto loc_824611DC;
	// lbz r11,3(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 3);
	// lbz r9,1(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 1);
	// lbz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// rotlwi r11,r11,8
	r11.u64 = __builtin_rotateleft32(r11.u32, 8);
	// lbz r7,2(r27)
	ctx.r7.u64 = PPC_LOAD_U8(r27.u32 + 2);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// or r25,r9,r7
	r25.u64 = ctx.r9.u64 | ctx.r7.u64;
	// addi r26,r11,5
	r26.s64 = r11.s64 + 5;
	// b 0x82461210
	goto loc_82461210;
loc_824611DC:
	// li r26,5
	r26.s64 = 5;
	// b 0x82461210
	goto loc_82461210;
loc_824611E4:
	// li r10,2
	ctx.r10.s64 = 2;
	// cmplwi cr6,r28,2
	cr6.compare<uint32_t>(r28.u32, 2, xer);
	// blt cr6,0x8246120c
	if (cr6.lt) goto loc_8246120C;
	// lbz r11,1(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1);
	// rlwinm r9,r23,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 8) & 0xFFFFFF00;
	// lis r25,0
	r25.s64 = 0;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// ori r25,r25,32768
	r25.u64 = r25.u64 | 32768;
	// addi r26,r11,2
	r26.s64 = r11.s64 + 2;
	// b 0x82461210
	goto loc_82461210;
loc_8246120C:
	// li r26,2
	r26.s64 = 2;
loc_82461210:
	// cmplw cr6,r28,r26
	cr6.compare<uint32_t>(r28.u32, r26.u32, xer);
	// bge cr6,0x82461238
	if (!cr6.lt) goto loc_82461238;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,12276(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12276);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x82461228;
	sub_823DA950(ctx, base);
	// stw r28,12280(r31)
	PPC_STORE_U32(r31.u32 + 12280, r28.u32);
	// add r24,r28,r24
	r24.u64 = r28.u64 + r24.u64;
	// mr r28,r17
	r28.u64 = r17.u64;
	// b 0x824612e4
	goto loc_824612E4;
loc_82461238:
	// subf r29,r21,r18
	r29.s64 = r18.s64 - r21.s64;
	// cmplw cr6,r29,r25
	cr6.compare<uint32_t>(r29.u32, r25.u32, xer);
	// bge cr6,0x8246124c
	if (!cr6.lt) goto loc_8246124C;
	// lwz r30,12264(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12264);
	// b 0x82461250
	goto loc_82461250;
loc_8246124C:
	// add r30,r21,r19
	r30.u64 = r21.u64 + r19.u64;
loc_82461250:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// subf r6,r10,r26
	ctx.r6.s64 = r26.s64 - ctx.r10.s64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + r27.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461530
	ctx.lr = 0x82461270;
	sub_82461530(ctx, base);
	// lwz r11,12264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12264);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x824612a4
	if (!cr6.eq) goto loc_824612A4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r3,r21,r19
	ctx.r3.u64 = r21.u64 + r19.u64;
	// bl 0x823da950
	ctx.lr = 0x8246128C;
	sub_823DA950(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r29,12268(r31)
	PPC_STORE_U32(r31.u32 + 12268, r29.u32);
	// add r21,r29,r21
	r21.u64 = r29.u64 + r21.u64;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// stw r11,12272(r31)
	PPC_STORE_U32(r31.u32 + 12272, r11.u32);
	// b 0x824612ac
	goto loc_824612AC;
loc_824612A4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r21,r11,r21
	r21.u64 = r11.u64 + r21.u64;
loc_824612AC:
	// lwz r11,12276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12276);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x824612c4
	if (!cr6.eq) goto loc_824612C4;
	// add r27,r24,r20
	r27.u64 = r24.u64 + r20.u64;
	// stw r17,12280(r31)
	PPC_STORE_U32(r31.u32 + 12280, r17.u32);
	// b 0x824612cc
	goto loc_824612CC;
loc_824612C4:
	// add r27,r26,r27
	r27.u64 = r26.u64 + r27.u64;
	// add r24,r26,r24
	r24.u64 = r26.u64 + r24.u64;
loc_824612CC:
	// cmplwi cr6,r23,255
	cr6.compare<uint32_t>(r23.u32, 255, xer);
	// bne cr6,0x824612e0
	if (!cr6.eq) goto loc_824612E0;
	// li r11,1
	r11.s64 = 1;
	// mr r22,r24
	r22.u64 = r24.u64;
	// stb r11,12284(r31)
	PPC_STORE_U8(r31.u32 + 12284, r11.u8);
loc_824612E0:
	// subf r28,r24,r22
	r28.s64 = r22.s64 - r24.s64;
loc_824612E4:
	// lwz r11,12272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82461190
	if (cr6.eq) goto loc_82461190;
loc_824612F0:
	// stw r21,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r21.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r24,0(r15)
	PPC_STORE_U32(r15.u32 + 0, r24.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_82461304"))) PPC_WEAK_FUNC(sub_82461304);
PPC_FUNC_IMPL(__imp__sub_82461304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461308"))) PPC_WEAK_FUNC(sub_82461308);
PPC_FUNC_IMPL(__imp__sub_82461308) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r5,12
	ctx.r5.s64 = 12;
	// beq cr6,0x82461330
	if (cr6.eq) goto loc_82461330;
	// bl 0x823da950
	ctx.lr = 0x8246132C;
	sub_823DA950(ctx, base);
	// b 0x82461338
	goto loc_82461338;
loc_82461330:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82461338;
	sub_823D9890(ctx, base);
loc_82461338:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8246134c
	if (!cr6.eq) goto loc_8246134C;
	// lis r11,2
	r11.s64 = 131072;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_8246134C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82461360
	if (!cr6.eq) goto loc_82461360;
	// lis r11,8
	r11.s64 = 524288;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_82461360:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82461374"))) PPC_WEAK_FUNC(sub_82461374);
PPC_FUNC_IMPL(__imp__sub_82461374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461378"))) PPC_WEAK_FUNC(sub_82461378);
PPC_FUNC_IMPL(__imp__sub_82461378) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r6,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r6.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82461308
	ctx.lr = 0x824613A4;
	sub_82461308(ctx, base);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r1,172
	ctx.r4.s64 = ctx.r1.s64 + 172;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461840
	ctx.lr = 0x824613BC;
	sub_82461840(ctx, base);
	// clrlwi. r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// beq 0x824613d4
	if (cr0.eq) goto loc_824613D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82460f88
	ctx.lr = 0x824613D4;
	sub_82460F88(ctx, base);
loc_824613D4:
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

__attribute__((alias("__imp__sub_824613EC"))) PPC_WEAK_FUNC(sub_824613EC);
PPC_FUNC_IMPL(__imp__sub_824613EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824613F0"))) PPC_WEAK_FUNC(sub_824613F0);
PPC_FUNC_IMPL(__imp__sub_824613F0) {
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
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82461308
	ctx.lr = 0x82461410;
	sub_82461308(ctx, base);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82461840
	ctx.lr = 0x82461428;
	sub_82461840(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_82461440"))) PPC_WEAK_FUNC(sub_82461440);
PPC_FUNC_IMPL(__imp__sub_82461440) {
	PPC_FUNC_PROLOGUE();
	// twi 31,r0,20
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82461448"))) PPC_WEAK_FUNC(sub_82461448);
PPC_FUNC_IMPL(__imp__sub_82461448) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// lhz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lhz r6,10(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 10);
	// lhz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// lhz r11,14(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// sth r10,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r10.u16);
	// sth r9,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r9.u16);
	// sth r8,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r8.u16);
	// sth r7,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, ctx.r7.u16);
	// sth r6,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, ctx.r6.u16);
	// sth r5,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, ctx.r5.u16);
	// sth r11,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r11.u16);
	// bl 0x827bdaf4
	ctx.lr = 0x824614A4;
	__imp__RtlTimeFieldsToTime(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x824614c0
	if (!cr0.eq) goto loc_824614C0;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,13
	ctx.r3.u64 = ctx.r3.u64 | 13;
	// bl 0x82135d58
	ctx.lr = 0x824614B8;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824614d4
	goto loc_824614D4;
loc_824614C0:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_824614D4:
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

__attribute__((alias("__imp__sub_824614E8"))) PPC_WEAK_FUNC(sub_824614E8);
PPC_FUNC_IMPL(__imp__sub_824614E8) {
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
	// bl 0x82461948
	ctx.lr = 0x82461500;
	sub_82461948(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824619c0
	ctx.lr = 0x82461508;
	sub_824619C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824619f8
	ctx.lr = 0x82461510;
	sub_824619F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,11972(r31)
	PPC_STORE_U32(r31.u32 + 11972, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8246152C"))) PPC_WEAK_FUNC(sub_8246152C);
PPC_FUNC_IMPL(__imp__sub_8246152C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461530"))) PPC_WEAK_FUNC(sub_82461530);
PPC_FUNC_IMPL(__imp__sub_82461530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82461538;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r5,r6
	r11.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r7,11020(r31)
	PPC_STORE_U32(r31.u32 + 11020, ctx.r7.u32);
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// stw r5,11012(r31)
	PPC_STORE_U32(r31.u32 + 11012, ctx.r5.u32);
	// stw r11,11016(r31)
	PPC_STORE_U32(r31.u32 + 11016, r11.u32);
	// bl 0x827bcf44
	ctx.lr = 0x82461564;
	__imp__MmQueryAddressProtect(ctx, base);
	// rlwinm r11,r3,0,21,22
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x600;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stb r11,12260(r31)
	PPC_STORE_U8(r31.u32 + 12260, r11.u8);
	// bl 0x82461e68
	ctx.lr = 0x82461580;
	sub_82461E68(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461b98
	ctx.lr = 0x8246158C;
	sub_82461B98(ctx, base);
	// lwz r10,11972(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 11972);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,11972(r31)
	PPC_STORE_U32(r31.u32 + 11972, ctx.r10.u32);
	// bge 0x824615b0
	if (!cr0.lt) goto loc_824615B0;
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x824615c4
	goto loc_824615C4;
loc_824615B0:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,11024(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 11024);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,11024(r31)
	PPC_STORE_U32(r31.u32 + 11024, r11.u32);
loc_824615C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824615CC"))) PPC_WEAK_FUNC(sub_824615CC);
PPC_FUNC_IMPL(__imp__sub_824615CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824615D0"))) PPC_WEAK_FUNC(sub_824615D0);
PPC_FUNC_IMPL(__imp__sub_824615D0) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x824615D8;
	// lis r9,257
	ctx.r9.s64 = 16842752;
	// lis r8,771
	ctx.r8.s64 = 50528256;
	// ori r9,r9,514
	ctx.r9.u64 = ctx.r9.u64 | 514;
	// lis r6,1799
	ctx.r6.s64 = 117899264;
	// lis r7,1285
	ctx.r7.s64 = 84213760;
	// stw r9,12008(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12008, ctx.r9.u32);
	// ori r8,r8,1028
	ctx.r8.u64 = ctx.r8.u64 | 1028;
	// ori r7,r7,1542
	ctx.r7.u64 = ctx.r7.u64 | 1542;
	// ori r9,r6,2056
	ctx.r9.u64 = ctx.r6.u64 | 2056;
	// stw r8,12012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12012, ctx.r8.u32);
	// lis r5,2313
	ctx.r5.s64 = 151584768;
	// stw r7,12016(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12016, ctx.r7.u32);
	// lis r4,2827
	ctx.r4.s64 = 185270272;
	// stw r9,12020(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12020, ctx.r9.u32);
	// lis r31,3341
	r31.s64 = 218955776;
	// ori r8,r5,2570
	ctx.r8.u64 = ctx.r5.u64 | 2570;
	// ori r7,r4,3084
	ctx.r7.u64 = ctx.r4.u64 | 3084;
	// ori r9,r31,3598
	ctx.r9.u64 = r31.u64 | 3598;
	// stw r8,12024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12024, ctx.r8.u32);
	// lis r11,4369
	r11.s64 = 286326784;
	// stw r7,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r7.u32);
	// lis r30,3855
	r30.s64 = 252641280;
	// stw r9,12032(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12032, ctx.r9.u32);
	// ori r11,r11,4369
	r11.u64 = r11.u64 | 4369;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r8,r30,4112
	ctx.r8.u64 = r30.u64 | 4112;
	// stw r11,12040(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12040, r11.u32);
	// li r7,-2
	ctx.r7.s64 = -2;
	// stw r10,12004(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12004, ctx.r10.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r8,12036(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12036, ctx.r8.u32);
	// stw r11,12044(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12044, r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,12048(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12048, r11.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r11,12052(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12052, r11.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r7,12056(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12056, ctx.r7.u32);
	// li r11,6
	r11.s64 = 6;
	// stw r9,12060(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12060, ctx.r9.u32);
	// li r7,10
	ctx.r7.s64 = 10;
	// stw r10,12064(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12064, ctx.r10.u32);
	// li r9,14
	ctx.r9.s64 = 14;
	// li r10,22
	ctx.r10.s64 = 22;
	// stw r8,12068(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12068, ctx.r8.u32);
	// stw r6,12072(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12072, ctx.r6.u32);
	// li r8,30
	ctx.r8.s64 = 30;
	// li r6,46
	ctx.r6.s64 = 46;
	// stw r5,12076(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12076, ctx.r5.u32);
	// stw r11,12080(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12080, r11.u32);
	// li r5,62
	ctx.r5.s64 = 62;
	// stw r7,12084(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12084, ctx.r7.u32);
	// li r11,94
	r11.s64 = 94;
	// stw r9,12088(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12088, ctx.r9.u32);
	// li r7,126
	ctx.r7.s64 = 126;
	// stw r10,12092(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12092, ctx.r10.u32);
	// li r9,190
	ctx.r9.s64 = 190;
	// li r10,254
	ctx.r10.s64 = 254;
	// stw r8,12096(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12096, ctx.r8.u32);
	// stw r6,12100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12100, ctx.r6.u32);
	// li r8,382
	ctx.r8.s64 = 382;
	// li r6,510
	ctx.r6.s64 = 510;
	// stw r5,12104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12104, ctx.r5.u32);
	// stw r11,12108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12108, r11.u32);
	// li r5,766
	ctx.r5.s64 = 766;
	// stw r7,12112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12112, ctx.r7.u32);
	// li r11,1022
	r11.s64 = 1022;
	// stw r9,12116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12116, ctx.r9.u32);
	// li r7,1534
	ctx.r7.s64 = 1534;
	// stw r10,12120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12120, ctx.r10.u32);
	// li r9,2046
	ctx.r9.s64 = 2046;
	// li r10,3070
	ctx.r10.s64 = 3070;
	// stw r8,12124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12124, ctx.r8.u32);
	// stw r6,12128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12128, ctx.r6.u32);
	// li r8,4094
	ctx.r8.s64 = 4094;
	// stw r5,12132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12132, ctx.r5.u32);
	// li r6,6142
	ctx.r6.s64 = 6142;
	// stw r11,12136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12136, r11.u32);
	// stw r7,12140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12140, ctx.r7.u32);
	// stw r9,12144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12144, ctx.r9.u32);
	// stw r10,12148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12148, ctx.r10.u32);
	// lis r11,0
	r11.s64 = 0;
	// stw r8,12152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12152, ctx.r8.u32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r6,12156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12156, ctx.r6.u32);
	// ori r11,r11,49150
	r11.u64 = r11.u64 | 49150;
	// ori r10,r10,65534
	ctx.r10.u64 = ctx.r10.u64 | 65534;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// stw r11,12180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12180, r11.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// stw r10,12184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12184, ctx.r10.u32);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// ori r9,r9,32766
	ctx.r9.u64 = ctx.r9.u64 | 32766;
	// ori r11,r8,65534
	r11.u64 = ctx.r8.u64 | 65534;
	// ori r10,r7,65534
	ctx.r10.u64 = ctx.r7.u64 | 65534;
	// stw r9,12188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12188, ctx.r9.u32);
	// lis r6,3
	ctx.r6.s64 = 196608;
	// stw r11,12192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12192, r11.u32);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// stw r10,12196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12196, ctx.r10.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// ori r9,r6,65534
	ctx.r9.u64 = ctx.r6.u64 | 65534;
	// ori r11,r5,65534
	r11.u64 = ctx.r5.u64 | 65534;
	// ori r10,r4,65534
	ctx.r10.u64 = ctx.r4.u64 | 65534;
	// stw r9,12200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12200, ctx.r9.u32);
	// lis r31,9
	r31.s64 = 589824;
	// stw r11,12204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12204, r11.u32);
	// lis r30,11
	r30.s64 = 720896;
	// stw r10,12208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12208, ctx.r10.u32);
	// lis r29,13
	r29.s64 = 851968;
	// ori r9,r31,65534
	ctx.r9.u64 = r31.u64 | 65534;
	// ori r11,r30,65534
	r11.u64 = r30.u64 | 65534;
	// ori r10,r29,65534
	ctx.r10.u64 = r29.u64 | 65534;
	// stw r9,12212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12212, ctx.r9.u32);
	// lis r28,15
	r28.s64 = 983040;
	// stw r11,12216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12216, r11.u32);
	// lis r27,17
	r27.s64 = 1114112;
	// stw r10,12220(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12220, ctx.r10.u32);
	// lis r26,19
	r26.s64 = 1245184;
	// ori r9,r28,65534
	ctx.r9.u64 = r28.u64 | 65534;
	// ori r11,r27,65534
	r11.u64 = r27.u64 | 65534;
	// ori r10,r26,65534
	ctx.r10.u64 = r26.u64 | 65534;
	// stw r9,12224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12224, ctx.r9.u32);
	// lis r25,21
	r25.s64 = 1376256;
	// stw r11,12228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12228, r11.u32);
	// lis r24,23
	r24.s64 = 1507328;
	// stw r10,12232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12232, ctx.r10.u32);
	// lis r23,25
	r23.s64 = 1638400;
	// li r19,8190
	r19.s64 = 8190;
	// li r18,12286
	r18.s64 = 12286;
	// ori r9,r25,65534
	ctx.r9.u64 = r25.u64 | 65534;
	// stw r19,12160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12160, r19.u32);
	// ori r11,r24,65534
	r11.u64 = r24.u64 | 65534;
	// stw r18,12164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12164, r18.u32);
	// ori r10,r23,65534
	ctx.r10.u64 = r23.u64 | 65534;
	// stw r9,12236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12236, ctx.r9.u32);
	// lis r22,27
	r22.s64 = 1769472;
	// stw r11,12240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12240, r11.u32);
	// lis r21,29
	r21.s64 = 1900544;
	// stw r10,12244(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12244, ctx.r10.u32);
	// lis r20,31
	r20.s64 = 2031616;
	// li r17,16382
	r17.s64 = 16382;
	// li r19,24574
	r19.s64 = 24574;
	// li r18,32766
	r18.s64 = 32766;
	// stw r17,12168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12168, r17.u32);
	// ori r9,r22,65534
	ctx.r9.u64 = r22.u64 | 65534;
	// stw r19,12172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12172, r19.u32);
	// ori r11,r21,65534
	r11.u64 = r21.u64 | 65534;
	// stw r18,12176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12176, r18.u32);
	// ori r10,r20,65534
	ctx.r10.u64 = r20.u64 | 65534;
	// stw r9,12248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12248, ctx.r9.u32);
	// stw r11,12252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12252, r11.u32);
	// stw r10,12256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12256, ctx.r10.u32);
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_82461840"))) PPC_WEAK_FUNC(sub_82461840);
PPC_FUNC_IMPL(__imp__sub_82461840) {
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
	ctx.lr = 0x82461848;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// addi r27,r30,261
	r27.s64 = r30.s64 + 261;
	// lis r10,0
	ctx.r10.s64 = 0;
	// add r11,r27,r6
	r11.u64 = r27.u64 + ctx.r6.u64;
	// clrlwi. r26,r25,31
	r26.u64 = r25.u32 & 0x1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// ori r28,r10,32768
	r28.u64 = ctx.r10.u64 | 32768;
	// addi r11,r11,12304
	r11.s64 = r11.s64 + 12304;
	// beq 0x8246187c
	if (cr0.eq) goto loc_8246187C;
	// addis r11,r11,1
	r11.s64 = r11.s64 + 65536;
	// addi r11,r11,-26619
	r11.s64 = r11.s64 + -26619;
	// b 0x82461888
	goto loc_82461888;
loc_8246187C:
	// rlwinm. r10,r25,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82461888
	if (cr0.eq) goto loc_82461888;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
loc_82461888:
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// beq cr6,0x82461940
	if (cr6.eq) goto loc_82461940;
	// add r31,r3,r6
	r31.u64 = ctx.r3.u64 + ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r31,12304
	r29.s64 = r31.s64 + 12304;
	// bl 0x824615d0
	ctx.lr = 0x824618A8;
	sub_824615D0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r9,r30,-1
	ctx.r9.s64 = r30.s64 + -1;
	// stw r11,11992(r31)
	PPC_STORE_U32(r31.u32 + 11992, r11.u32);
	// stw r11,11996(r31)
	PPC_STORE_U32(r31.u32 + 11996, r11.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r11,12000(r31)
	PPC_STORE_U32(r31.u32 + 12000, r11.u32);
	// stb r10,11957(r31)
	PPC_STORE_U8(r31.u32 + 11957, ctx.r10.u8);
loc_824618CC:
	// lbz r9,11957(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 11957);
	// li r8,1
	ctx.r8.s64 = 1;
	// add r7,r9,r31
	ctx.r7.u64 = ctx.r9.u64 + r31.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r7,12004(r7)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12004);
	// stb r9,11957(r31)
	PPC_STORE_U8(r31.u32 + 11957, ctx.r9.u8);
	// slw r9,r8,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r7.u8 & 0x3F));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// blt cr6,0x824618cc
	if (cr6.lt) goto loc_824618CC;
	// add r10,r29,r27
	ctx.r10.u64 = r29.u64 + r27.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r11,12268(r31)
	PPC_STORE_U32(r31.u32 + 12268, r11.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r10,12264(r31)
	PPC_STORE_U32(r31.u32 + 12264, ctx.r10.u32);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// stw r11,12272(r31)
	PPC_STORE_U32(r31.u32 + 12272, r11.u32);
	// stw r11,12276(r31)
	PPC_STORE_U32(r31.u32 + 12276, r11.u32);
	// stw r11,12280(r31)
	PPC_STORE_U32(r31.u32 + 12280, r11.u32);
	// stw r11,12284(r31)
	PPC_STORE_U32(r31.u32 + 12284, r11.u32);
	// stw r11,12288(r31)
	PPC_STORE_U32(r31.u32 + 12288, r11.u32);
	// stw r11,12292(r31)
	PPC_STORE_U32(r31.u32 + 12292, r11.u32);
	// stw r11,12296(r31)
	PPC_STORE_U32(r31.u32 + 12296, r11.u32);
	// beq cr6,0x82461934
	if (cr6.eq) goto loc_82461934;
	// stw r10,12276(r31)
	PPC_STORE_U32(r31.u32 + 12276, ctx.r10.u32);
	// b 0x82461940
	goto loc_82461940;
loc_82461934:
	// rlwinm. r11,r25,0,0,0
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82461940
	if (cr0.eq) goto loc_82461940;
	// stw r10,12300(r31)
	PPC_STORE_U32(r31.u32 + 12300, ctx.r10.u32);
loc_82461940:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82461948"))) PPC_WEAK_FUNC(sub_82461948);
PPC_FUNC_IMPL(__imp__sub_82461948) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,2584
	ctx.r3.s64 = r31.s64 + 2584;
	// lbz r11,11957(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11957);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823d9890
	ctx.lr = 0x82461974;
	sub_823D9890(ctx, base);
	// lbz r11,11957(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11957);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r3,r31,11028
	ctx.r3.s64 = r31.s64 + 11028;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823d9890
	ctx.lr = 0x8246198C;
	sub_823D9890(ctx, base);
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3256
	ctx.r3.s64 = r31.s64 + 3256;
	// bl 0x823d9890
	ctx.lr = 0x8246199C;
	sub_823D9890(ctx, base);
	// li r5,249
	ctx.r5.s64 = 249;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,11700
	ctx.r3.s64 = r31.s64 + 11700;
	// bl 0x823d9890
	ctx.lr = 0x824619AC;
	sub_823D9890(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824619C0"))) PPC_WEAK_FUNC(sub_824619C0);
PPC_FUNC_IMPL(__imp__sub_824619C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,11960(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11960, r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r11,11024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11024, r11.u32);
	// stw r10,11988(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11988, ctx.r10.u32);
	// stw r11,11980(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11980, r11.u32);
	// stw r11,11984(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11984, r11.u32);
	// stb r10,11958(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11958, ctx.r10.u8);
	// stw r11,11964(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11964, r11.u32);
	// stb r11,11959(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11959, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824619F8"))) PPC_WEAK_FUNC(sub_824619F8);
PPC_FUNC_IMPL(__imp__sub_824619F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,11968(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11968, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82461A04"))) PPC_WEAK_FUNC(sub_82461A04);
PPC_FUNC_IMPL(__imp__sub_82461A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461A08"))) PPC_WEAK_FUNC(sub_82461A08);
PPC_FUNC_IMPL(__imp__sub_82461A08) {
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
	ctx.lr = 0x82461A10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r30,6
	cr6.compare<int32_t>(r30.s32, 6, xer);
	// bgt cr6,0x82461a38
	if (cr6.gt) goto loc_82461A38;
	// lwz r11,11968(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 11968);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,11968(r28)
	PPC_STORE_U32(r28.u32 + 11968, r11.u32);
	// b 0x82461b90
	goto loc_82461B90;
loc_82461A38:
	// add r27,r31,r30
	r27.u64 = r31.u64 + r30.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r29,r27,-6
	r29.s64 = r27.s64 + -6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x82461A50;
	sub_823DA950(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,232
	ctx.r4.s64 = 232;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x82461A60;
	sub_823D9890(ctx, base);
	// lwz r11,11968(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 11968);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r7,r11,-10
	ctx.r7.s64 = r11.s64 + -10;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r6,r11,-22624
	ctx.r6.s64 = r11.s64 + -22624;
loc_82461A74:
	// addi r11,r31,15
	r11.s64 = r31.s64 + 15;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,0,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bge cr6,0x82461aa8
	if (!cr6.lt) goto loc_82461AA8;
loc_82461A8C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,232
	cr6.compare<uint32_t>(ctx.r8.u32, 232, xer);
	// beq cr6,0x82461aa8
	if (cr6.eq) goto loc_82461AA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82461a8c
	if (cr6.lt) goto loc_82461A8C;
loc_82461AA8:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82461ad4
	if (!cr6.eq) goto loc_82461AD4;
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82461ac0
	goto loc_82461AC0;
loc_82461AB8:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_82461AC0:
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpequb. v13,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_cmpeq_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 0xFFFF);
	// beq cr6,0x82461ab8
	if (cr6.eq) goto loc_82461AB8;
	// b 0x82461ad4
	goto loc_82461AD4;
loc_82461AD0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82461AD4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,232
	cr6.compare<uint32_t>(ctx.r9.u32, 232, xer);
	// bne cr6,0x82461ad0
	if (!cr6.eq) goto loc_82461AD0;
	// lwz r9,11968(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 11968);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,11968(r28)
	PPC_STORE_U32(r28.u32 + 11968, ctx.r10.u32);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x82461b78
	if (!cr6.lt) goto loc_82461B78;
	// lbz r9,3(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r5,1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// lwz r8,11964(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 11964);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 | ctx.r4.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x82461b3c
	if (!cr6.lt) goto loc_82461B3C;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// b 0x82461b50
	goto loc_82461B50;
loc_82461B3C:
	// neg r5,r9
	ctx.r5.s64 = -ctx.r9.s64;
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82461b68
	if (cr6.gt) goto loc_82461B68;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
loc_82461B50:
	// rlwinm r5,r9,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r9,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF;
	// rlwinm r9,r9,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// stb r5,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r5.u8);
	// stb r4,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r4.u8);
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
loc_82461B68:
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// stw r10,11968(r28)
	PPC_STORE_U32(r28.u32 + 11968, ctx.r10.u32);
	// b 0x82461a74
	goto loc_82461A74;
loc_82461B78:
	// addi r11,r7,10
	r11.s64 = ctx.r7.s64 + 10;
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r11,11968(r28)
	PPC_STORE_U32(r28.u32 + 11968, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r27,-6
	ctx.r3.s64 = r27.s64 + -6;
	// bl 0x823da950
	ctx.lr = 0x82461B90;
	sub_823DA950(ctx, base);
loc_82461B90:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82461B98"))) PPC_WEAK_FUNC(sub_82461B98);
PPC_FUNC_IMPL(__imp__sub_82461B98) {
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
	ctx.lr = 0x82461BA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	r27.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
	// b 0x82461dc8
	goto loc_82461DC8;
loc_82461BB8:
	// lwz r11,11988(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11988);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82461d98
	if (!cr6.eq) goto loc_82461D98;
	// lbz r11,11958(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11958);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82461c18
	if (cr0.eq) goto loc_82461C18;
	// stb r27,11958(r31)
	PPC_STORE_U8(r31.u32 + 11958, r27.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461BE0;
	sub_82461F40(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82461c14
	if (cr0.eq) goto loc_82461C14;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461BF4;
	sub_82461F40(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461C04;
	sub_82461F40(ctx, base);
	// rlwinm r11,r30,16,0,15
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r3,r11
	r11.u64 = ctx.r3.u64 | r11.u64;
	// stw r11,11964(r31)
	PPC_STORE_U32(r31.u32 + 11964, r11.u32);
	// b 0x82461c18
	goto loc_82461C18;
loc_82461C14:
	// stw r27,11964(r31)
	PPC_STORE_U32(r31.u32 + 11964, r27.u32);
loc_82461C18:
	// lwz r11,11984(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11984);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82461c30
	if (!cr6.eq) goto loc_82461C30;
	// stw r27,11984(r31)
	PPC_STORE_U32(r31.u32 + 11984, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461e08
	ctx.lr = 0x82461C30;
	sub_82461E08(ctx, base);
loc_82461C30:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461C3C;
	sub_82461F40(ctx, base);
	// stw r3,11984(r31)
	PPC_STORE_U32(r31.u32 + 11984, ctx.r3.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461C4C;
	sub_82461F40(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461C5C;
	sub_82461F40(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x82461C6C;
	sub_82461F40(ctx, base);
	// rlwinm r11,r26,8,0,23
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r10,11984(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 11984);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// stw r11,11976(r31)
	PPC_STORE_U32(r31.u32 + 11976, r11.u32);
	// stw r11,11980(r31)
	PPC_STORE_U32(r31.u32 + 11980, r11.u32);
	// bne cr6,0x82461c98
	if (!cr6.eq) goto loc_82461C98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463748
	ctx.lr = 0x82461C98;
	sub_82463748(ctx, base);
loc_82461C98:
	// lwz r11,11984(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11984);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82461ccc
	if (cr6.eq) goto loc_82461CCC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82461ccc
	if (cr6.eq) goto loc_82461CCC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82461cc4
	if (!cr6.eq) goto loc_82461CC4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82462138
	ctx.lr = 0x82461CBC;
	sub_82462138(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82461cfc
	if (!cr0.eq) goto loc_82461CFC;
loc_82461CC4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82461dfc
	goto loc_82461DFC;
loc_82461CCC:
	// lbz r11,11957(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11957);
	// addi r4,r31,2584
	ctx.r4.s64 = r31.s64 + 2584;
	// addi r3,r31,11028
	ctx.r3.s64 = r31.s64 + 11028;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823da950
	ctx.lr = 0x82461CE4;
	sub_823DA950(ctx, base);
	// li r5,249
	ctx.r5.s64 = 249;
	// addi r4,r31,3256
	ctx.r4.s64 = r31.s64 + 3256;
	// addi r3,r31,11700
	ctx.r3.s64 = r31.s64 + 11700;
	// bl 0x823da950
	ctx.lr = 0x82461CF4;
	sub_823DA950(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463658
	ctx.lr = 0x82461CFC;
	sub_82463658(ctx, base);
loc_82461CFC:
	// li r11,2
	r11.s64 = 2;
	// stw r11,11988(r31)
	PPC_STORE_U32(r31.u32 + 11988, r11.u32);
	// b 0x82461d98
	goto loc_82461D98;
loc_82461D08:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82461da4
	if (!cr6.gt) goto loc_82461DA4;
	// lwz r30,11980(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 11980);
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82461d20
	if (cr6.lt) goto loc_82461D20;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82461D20:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82461cc4
	if (cr6.eq) goto loc_82461CC4;
	// lwz r11,11984(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11984);
	// lwz r4,11960(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 11960);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82461d48
	if (!cr6.eq) goto loc_82461D48;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82462ff8
	ctx.lr = 0x82461D44;
	sub_82462FF8(ctx, base);
	// b 0x82461d7c
	goto loc_82461D7C;
loc_82461D48:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82461d60
	if (!cr6.eq) goto loc_82461D60;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824627e8
	ctx.lr = 0x82461D5C;
	sub_824627E8(ctx, base);
	// b 0x82461d7c
	goto loc_82461D7C;
loc_82461D60:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82461d78
	if (!cr6.eq) goto loc_82461D78;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f78
	ctx.lr = 0x82461D74;
	sub_82461F78(ctx, base);
	// b 0x82461d7c
	goto loc_82461D7C;
loc_82461D78:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82461D7C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82461cc4
	if (!cr6.eq) goto loc_82461CC4;
	// lwz r11,11980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11980);
	// subf r29,r30,r29
	r29.s64 = r29.s64 - r30.s64;
	// add r28,r30,r28
	r28.u64 = r30.u64 + r28.u64;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// stw r11,11980(r31)
	PPC_STORE_U32(r31.u32 + 11980, r11.u32);
loc_82461D98:
	// lwz r11,11980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11980);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82461d08
	if (cr6.gt) goto loc_82461D08;
loc_82461DA4:
	// lwz r11,11980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11980);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82461db8
	if (!cr6.eq) goto loc_82461DB8;
	// li r11,1
	r11.s64 = 1;
	// stw r11,11988(r31)
	PPC_STORE_U32(r31.u32 + 11988, r11.u32);
loc_82461DB8:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x82461dcc
	if (!cr6.eq) goto loc_82461DCC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461e08
	ctx.lr = 0x82461DC8;
	sub_82461E08(ctx, base);
loc_82461DC8:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
loc_82461DCC:
	// bgt cr6,0x82461bb8
	if (cr6.gt) goto loc_82461BB8;
	// lwz r11,11960(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11960);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82461de4
	if (!cr6.eq) goto loc_82461DE4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82461DE4:
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463068
	ctx.lr = 0x82461DF8;
	sub_82463068(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82461DFC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82461E04"))) PPC_WEAK_FUNC(sub_82461E04);
PPC_FUNC_IMPL(__imp__sub_82461E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461E08"))) PPC_WEAK_FUNC(sub_82461E08);
PPC_FUNC_IMPL(__imp__sub_82461E08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,11984(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11984);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,11012(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// lwz r9,11016(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// li r8,16
	ctx.r8.s64 = 16;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stw r10,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r10.u32);
	// stb r8,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, ctx.r8.u8);
	// rlwinm r10,r9,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82461E64"))) PPC_WEAK_FUNC(sub_82461E64);
PPC_FUNC_IMPL(__imp__sub_82461E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461E68"))) PPC_WEAK_FUNC(sub_82461E68);
PPC_FUNC_IMPL(__imp__sub_82461E68) {
	PPC_FUNC_PROLOGUE();
	// b 0x82461e08
	sub_82461E08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82461E6C"))) PPC_WEAK_FUNC(sub_82461E6C);
PPC_FUNC_IMPL(__imp__sub_82461E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461E70"))) PPC_WEAK_FUNC(sub_82461E70);
PPC_FUNC_IMPL(__imp__sub_82461E70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,11956(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// lwz r10,11952(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// slw r9,r10,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r9.u32);
	// stb r11,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, r11.u8);
	// bgtlr 
	if (cr0.gt) return;
	// lwz r8,11016(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// lwz r10,11012(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bge cr6,0x82461eec
	if (!cr6.lt) goto loc_82461EEC;
	// lbz r6,11956(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r11,r10,2
	r11.s64 = ctx.r10.s64 + 2;
	// lbz r7,1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// stw r11,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, r11.u32);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 | ctx.r4.u64;
	// neg r6,r6
	ctx.r6.s64 = -ctx.r6.s64;
	// addi r10,r5,16
	ctx.r10.s64 = ctx.r5.s64 + 16;
	// slw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stb r10,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, ctx.r10.u8);
	// stw r9,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r9.u32);
	// bgtlr 
	if (cr0.gt) return;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x82461ef8
	if (cr6.lt) goto loc_82461EF8;
loc_82461EEC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,11959(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11959, r11.u8);
	// blr 
	return;
loc_82461EF8:
	// lbz r8,11956(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lwz r6,11952(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// stw r9,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, ctx.r9.u32);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | r11.u64;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
	// addi r11,r7,16
	r11.s64 = ctx.r7.s64 + 16;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stb r11,11956(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11956, r11.u8);
	// stw r10,11952(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11952, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82461F3C"))) PPC_WEAK_FUNC(sub_82461F3C);
PPC_FUNC_IMPL(__imp__sub_82461F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82461F40"))) PPC_WEAK_FUNC(sub_82461F40);
PPC_FUNC_IMPL(__imp__sub_82461F40) {
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
	// lwz r11,11952(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11952);
	// subfic r10,r4,32
	xer.ca = ctx.r4.u32 <= 32;
	ctx.r10.s64 = 32 - ctx.r4.s64;
	// srw r31,r11,r10
	r31.u64 = ctx.r10.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r10.u8 & 0x3F));
	// bl 0x82461e70
	ctx.lr = 0x82461F60;
	sub_82461E70(ctx, base);
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

__attribute__((alias("__imp__sub_82461F78"))) PPC_WEAK_FUNC(sub_82461F78);
PPC_FUNC_IMPL(__imp__sub_82461F78) {
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
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82461F80;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r21,r25,11012
	r21.s64 = r25.s64 + 11012;
	// add r22,r27,r5
	r22.u64 = r27.u64 + ctx.r5.u64;
	// lwz r30,11012(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 11012);
	// lwz r11,11016(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 11016);
	// lwz r24,0(r25)
	r24.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// lwz r20,4(r25)
	r20.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// blt cr6,0x82461fb4
	if (cr6.lt) goto loc_82461FB4;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
loc_82461FB4:
	// add r29,r24,r27
	r29.u64 = r24.u64 + r27.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// add r23,r22,r24
	r23.u64 = r22.u64 + r24.u64;
	// add r26,r29,r5
	r26.u64 = r29.u64 + ctx.r5.u64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// blt cr6,0x82461ff4
	if (cr6.lt) goto loc_82461FF4;
	// addi r11,r30,64
	r11.s64 = r30.s64 + 64;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bge cr6,0x82461ff4
	if (!cr6.lt) goto loc_82461FF4;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824620ac
	if (cr6.lt) goto loc_824620AC;
	// rlwinm r11,r5,0,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// add r6,r11,r29
	ctx.r6.u64 = r11.u64 + r29.u64;
	// b 0x824620a4
	goto loc_824620A4;
loc_82461FF4:
	// rlwinm r11,r5,0,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwinm r10,r5,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// add r6,r10,r29
	ctx.r6.u64 = ctx.r10.u64 + r29.u64;
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// bge cr6,0x824620a4
	if (!cr6.lt) goto loc_824620A4;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// li r7,64
	ctx.r7.s64 = 64;
loc_82462018:
	// li r5,128
	ctx.r5.s64 = 128;
	// dcbt r5,r30
	// dcbt r5,r31
	// lvrx128 v62,r9,r30
	temp.u32 = ctx.r9.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v63,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvrx128 v61,r10,r30
	temp.u32 = ctx.r10.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r9,r30
	temp.u32 = ctx.r9.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v62,v62,v61
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// lvrx128 v60,r11,r30
	temp.u32 = r11.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v61,r10,r30
	temp.u32 = ctx.r10.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v61,v61,v60
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// lvrx128 v59,r7,r30
	temp.u32 = ctx.r7.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r11,r30
	temp.u32 = r11.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r30,r30,64
	r30.s64 = r30.s64 + 64;
	// stvlx128 v63,r0,r31
	ea = r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v63.u8[15 - i]);
	// vor128 v60,v60,v59
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// stvrx128 v63,r31,r9
	ea = r31.u32 + ctx.r9.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v63.u8[i]);
	// stvlx128 v62,r31,r9
	ea = r31.u32 + ctx.r9.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v62.u8[15 - i]);
	// stvrx128 v62,r31,r10
	ea = r31.u32 + ctx.r10.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v62.u8[i]);
	// stvlx128 v61,r31,r10
	ea = r31.u32 + ctx.r10.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v61.u8[15 - i]);
	// stvrx128 v61,r31,r11
	ea = r31.u32 + r11.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v61.u8[i]);
	// stvlx128 v60,r31,r11
	ea = r31.u32 + r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v60.u8[15 - i]);
	// stvrx128 v60,r31,r7
	ea = r31.u32 + ctx.r7.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v60.u8[i]);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// cmplw cr6,r31,r8
	cr6.compare<uint32_t>(r31.u32, ctx.r8.u32, xer);
	// blt cr6,0x82462018
	if (cr6.lt) goto loc_82462018;
	// b 0x824620a4
	goto loc_824620A4;
loc_82462088:
	// lvlx128 v63,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v62,r9,r30
	temp.u32 = ctx.r9.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvlx128 v63,r0,r31
	ea = r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v63.u8[15 - i]);
	// stvrx128 v63,r31,r9
	ea = r31.u32 + ctx.r9.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v63.u8[i]);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
loc_824620A4:
	// cmplw cr6,r31,r6
	cr6.compare<uint32_t>(r31.u32, ctx.r6.u32, xer);
	// blt cr6,0x82462088
	if (cr6.lt) goto loc_82462088;
loc_824620AC:
	// cmplw cr6,r31,r26
	cr6.compare<uint32_t>(r31.u32, r26.u32, xer);
	// bge cr6,0x824620d0
	if (!cr6.lt) goto loc_824620D0;
	// subf r28,r31,r26
	r28.s64 = r26.s64 - r31.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dadd8
	ctx.lr = 0x824620C8;
	sub_823DADD8(ctx, base);
	// add r30,r28,r30
	r30.u64 = r28.u64 + r30.u64;
	// add r31,r28,r31
	r31.u64 = r28.u64 + r31.u64;
loc_824620D0:
	// subf r11,r29,r31
	r11.s64 = r31.s64 - r29.s64;
	// cmplw cr6,r26,r23
	cr6.compare<uint32_t>(r26.u32, r23.u32, xer);
	// add r31,r11,r27
	r31.u64 = r11.u64 + r27.u64;
	// beq cr6,0x824620e8
	if (cr6.eq) goto loc_824620E8;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82462130
	goto loc_82462130;
loc_824620E8:
	// stw r30,0(r21)
	PPC_STORE_U32(r21.u32 + 0, r30.u32);
	// cmpwi cr6,r22,257
	cr6.compare<int32_t>(r22.s32, 257, xer);
	// li r10,257
	ctx.r10.s64 = 257;
	// bgt cr6,0x824620fc
	if (cr6.gt) goto loc_824620FC;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_824620FC:
	// add r11,r27,r20
	r11.u64 = r27.u64 + r20.u64;
	// subf r10,r27,r10
	ctx.r10.s64 = ctx.r10.s64 - r27.s64;
	// add r3,r11,r24
	ctx.r3.u64 = r11.u64 + r24.u64;
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x82462120
	if (!cr6.lt) goto loc_82462120;
	// subf r4,r20,r3
	ctx.r4.s64 = ctx.r3.s64 - r20.s64;
	// subf r5,r3,r11
	ctx.r5.s64 = r11.s64 - ctx.r3.s64;
	// bl 0x823dadd8
	ctx.lr = 0x82462120;
	sub_823DADD8(ctx, base);
loc_82462120:
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// subf r3,r22,r31
	ctx.r3.s64 = r31.s64 - r22.s64;
	// and r11,r11,r31
	r11.u64 = r11.u64 & r31.u64;
	// stw r11,11960(r25)
	PPC_STORE_U32(r25.u32 + 11960, r11.u32);
loc_82462130:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82462138"))) PPC_WEAK_FUNC(sub_82462138);
PPC_FUNC_IMPL(__imp__sub_82462138) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,11012(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11012);
	// addi r9,r3,12
	ctx.r9.s64 = ctx.r3.s64 + 12;
	// lwz r10,11016(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11016);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// stw r11,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, r11.u32);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// blt cr6,0x82462160
	if (cr6.lt) goto loc_82462160;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82462160:
	// li r10,3
	ctx.r10.s64 = 3;
loc_82462164:
	// lbz r8,3(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 | ctx.r6.u64;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 | ctx.r5.u64;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82462164
	if (!cr0.eq) goto loc_82462164;
	// stw r11,11012(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11012, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824621AC"))) PPC_WEAK_FUNC(sub_824621AC);
PPC_FUNC_IMPL(__imp__sub_824621AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824621B0"))) PPC_WEAK_FUNC(sub_824621B0);
PPC_FUNC_IMPL(__imp__sub_824621B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x824621B8;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// add r28,r4,r5
	r28.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r25,r11,3644
	r25.s64 = r11.s64 + 3644;
	// addi r24,r11,9020
	r24.s64 = r11.s64 + 9020;
	// addi r23,r11,24
	r23.s64 = r11.s64 + 24;
	// lwz r21,11016(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 11016);
	// addi r22,r11,2072
	r22.s64 = r11.s64 + 2072;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r27,r11,2584
	r27.s64 = r11.s64 + 2584;
	// lbz r8,11956(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 11956);
	// addi r26,r11,3256
	r26.s64 = r11.s64 + 3256;
	// lwz r10,11952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11952);
	// addi r29,r11,12
	r29.s64 = r11.s64 + 12;
	// lwz r5,11012(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 11012);
	// b 0x8246244c
	goto loc_8246244C;
loc_824621F4:
	// rlwinm r9,r10,11,21,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FE;
	// lhax r7,r9,r23
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + r23.u32));
	// cmpwi r7,0
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge 0x82462234
	if (!cr0.lt) goto loc_82462234;
	// lis r9,32
	ctx.r9.s64 = 2097152;
loc_82462208:
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r7,r7,r25
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + r25.u32));
	// cmpwi r7,0
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt 0x82462208
	if (cr0.lt) goto loc_82462208;
loc_82462234:
	// cmplw cr6,r5,r21
	cr6.compare<uint32_t>(ctx.r5.u32, r21.u32, xer);
	// bge cr6,0x82462468
	if (!cr6.lt) goto loc_82462468;
	// lbzx r9,r7,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + r27.u32);
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x8246227c
	if (cr0.gt) goto loc_8246227C;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r3,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_8246227C:
	// addic. r6,r7,-256
	xer.ca = ctx.r7.u32 > 255;
	ctx.r6.s64 = ctx.r7.s64 + -256;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge 0x824622a0
	if (!cr0.lt) goto loc_824622A0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r7,r6,24
	ctx.r7.u64 = ctx.r6.u32 & 0xFF;
	// add r9,r9,r30
	ctx.r9.u64 = ctx.r9.u64 + r30.u64;
	// stbx r7,r30,r4
	PPC_STORE_U8(r30.u32 + ctx.r4.u32, ctx.r7.u8);
	// stbx r7,r9,r4
	PPC_STORE_U8(ctx.r9.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x8246244c
	goto loc_8246244C;
loc_824622A0:
	// clrlwi r3,r6,29
	ctx.r3.u64 = ctx.r6.u32 & 0x7;
	// cmpwi cr6,r3,7
	cr6.compare<int32_t>(ctx.r3.s32, 7, xer);
	// bne cr6,0x82462330
	if (!cr6.eq) goto loc_82462330;
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhax r9,r9,r22
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + r22.u32));
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge 0x824622ec
	if (!cr0.lt) goto loc_824622EC;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_824622C0:
	// and r3,r7,r10
	ctx.r3.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r3,r3,27,5,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x7FFFFFF;
	// xori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 ^ 1;
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r9,r9,r24
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + r24.u32));
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x824622c0
	if (cr0.lt) goto loc_824622C0;
loc_824622EC:
	// lbzx r7,r9,r26
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + r26.u32);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bgt 0x8246232c
	if (cr0.gt) goto loc_8246232C;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// neg r3,r7
	ctx.r3.s64 = -ctx.r7.s64;
	// lbz r31,0(r5)
	r31.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// or r31,r8,r31
	r31.u64 = ctx.r8.u64 | r31.u64;
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// slw r7,r31,r3
	ctx.r7.u64 = ctx.r3.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
loc_8246232C:
	// addi r3,r9,7
	ctx.r3.s64 = ctx.r9.s64 + 7;
loc_82462330:
	// srawi r9,r6,3
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 3;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// cmpwi cr6,r7,2
	cr6.compare<int32_t>(ctx.r7.s32, 2, xer);
	// ble cr6,0x824623f4
	if (!cr6.gt) goto loc_824623F4;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// ble cr6,0x824623dc
	if (!cr6.gt) goto loc_824623DC;
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + r11.u64;
	// lbz r9,12004(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// subfic r6,r31,32
	xer.ca = r31.u32 <= 32;
	ctx.r6.s64 = 32 - r31.s64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// srw r6,r10,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r6.u8 & 0x3F));
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r10,r10,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// bgt 0x824623c8
	if (cr0.gt) goto loc_824623C8;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// addi r31,r9,16
	r31.s64 = ctx.r9.s64 + 16;
	// neg r19,r9
	r19.s64 = -ctx.r9.s64;
	// lbz r20,0(r5)
	r20.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rotlwi r9,r8,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// extsb r8,r31
	ctx.r8.s64 = r31.s8;
	// or r31,r9,r20
	r31.u64 = ctx.r9.u64 | r20.u64;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r31,r31,r19
	r31.u64 = r19.u8 & 0x20 ? 0 : (r31.u32 << (r19.u8 & 0x3F));
	// or r10,r31,r10
	ctx.r10.u64 = r31.u64 | ctx.r10.u64;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// bgt 0x824623c8
	if (cr0.gt) goto loc_824623C8;
	// lbz r8,1(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// neg r31,r9
	r31.s64 = -ctx.r9.s64;
	// lbz r20,0(r5)
	r20.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// or r20,r8,r20
	r20.u64 = ctx.r8.u64 | r20.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r20,r31
	ctx.r9.u64 = r31.u8 & 0x20 ? 0 : (r20.u32 << (r31.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_824623C8:
	// addi r9,r7,3014
	ctx.r9.s64 = ctx.r7.s64 + 3014;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// b 0x824623e0
	goto loc_824623E0;
loc_824623DC:
	// li r9,1
	ctx.r9.s64 = 1;
loc_824623E0:
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r7,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r7.u32);
	// stw r6,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r6.u32);
	// b 0x8246240c
	goto loc_8246240C;
loc_824623F4:
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwzx r9,r6,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	// beq cr6,0x82462410
	if (cr6.eq) goto loc_82462410;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stwx r7,r6,r29
	PPC_STORE_U32(ctx.r6.u32 + r29.u32, ctx.r7.u32);
loc_8246240C:
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
loc_82462410:
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// subf r7,r9,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r9.s64;
loc_8246241C:
	// and r9,r7,r31
	ctx.r9.u64 = ctx.r7.u64 & r31.u64;
	// cmpwi cr6,r4,257
	cr6.compare<int32_t>(ctx.r4.s32, 257, xer);
	// lbzx r9,r9,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + r30.u32);
	// stbx r9,r30,r4
	PPC_STORE_U8(r30.u32 + ctx.r4.u32, ctx.r9.u8);
	// bge cr6,0x8246243c
	if (!cr6.lt) goto loc_8246243C;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + r30.u64;
	// stbx r9,r6,r4
	PPC_STORE_U8(ctx.r6.u32 + ctx.r4.u32, ctx.r9.u8);
loc_8246243C:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// bgt 0x8246241c
	if (cr0.gt) goto loc_8246241C;
loc_8246244C:
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// blt cr6,0x824621f4
	if (cr6.lt) goto loc_824621F4;
	// stb r8,11956(r11)
	PPC_STORE_U8(r11.u32 + 11956, ctx.r8.u8);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,11952(r11)
	PPC_STORE_U32(r11.u32 + 11952, ctx.r10.u32);
	// stw r5,11012(r11)
	PPC_STORE_U32(r11.u32 + 11012, ctx.r5.u32);
loc_82462464:
	// b 0x823d9224
	return;
loc_82462468:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82462464
	goto loc_82462464;
}

__attribute__((alias("__imp__sub_82462470"))) PPC_WEAK_FUNC(sub_82462470);
PPC_FUNC_IMPL(__imp__sub_82462470) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82462478;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// add r28,r4,r5
	r28.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r26,r11,11956
	r26.s64 = r11.s64 + 11956;
	// addi r25,r11,11952
	r25.s64 = r11.s64 + 11952;
	// addi r24,r11,11012
	r24.s64 = r11.s64 + 11012;
	// lwz r16,11016(r11)
	r16.u64 = PPC_LOAD_U32(r11.u32 + 11016);
	// addi r20,r11,3644
	r20.s64 = r11.s64 + 3644;
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r19,r11,9020
	r19.s64 = r11.s64 + 9020;
	// lbz r31,11956(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 11956);
	// addi r18,r11,24
	r18.s64 = r11.s64 + 24;
	// lwz r9,11952(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 11952);
	// addi r17,r11,2072
	r17.s64 = r11.s64 + 2072;
	// lwz r30,11012(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 11012);
	// addi r22,r11,2584
	r22.s64 = r11.s64 + 2584;
	// addi r21,r11,3256
	r21.s64 = r11.s64 + 3256;
	// addi r27,r11,12
	r27.s64 = r11.s64 + 12;
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// bge cr6,0x824627c0
	if (!cr6.lt) goto loc_824627C0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r23,16
	r23.s64 = 16;
	// addi r10,r10,-22608
	ctx.r10.s64 = ctx.r10.s64 + -22608;
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824624D4:
	// rlwinm r10,r9,11,21,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0x7FE;
	// lhax r8,r10,r18
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + r18.u32));
	// cmpwi r8,0
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge 0x82462514
	if (!cr0.lt) goto loc_82462514;
	// lis r10,32
	ctx.r10.s64 = 2097152;
loc_824624E8:
	// and r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 & ctx.r9.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r7,r7
	ctx.r7.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r7,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x7FFFFFF;
	// xori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 ^ 1;
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r8,r8,r20
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + r20.u32));
	// cmpwi r8,0
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x824624e8
	if (cr0.lt) goto loc_824624E8;
loc_82462514:
	// cmplw cr6,r30,r16
	cr6.compare<uint32_t>(r30.u32, r16.u32, xer);
	// bge cr6,0x824627e0
	if (!cr6.lt) goto loc_824627E0;
	// lbzx r10,r8,r22
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r22.u32);
	// subf r7,r10,r31
	ctx.r7.s64 = r31.s64 - ctx.r10.s64;
	// slw r9,r9,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// extsb r31,r7
	r31.s64 = ctx.r7.s8;
	// mr. r10,r31
	ctx.r10.u64 = r31.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt 0x8246255c
	if (cr0.gt) goto loc_8246255C;
	// lbz r7,1(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r6,r10
	ctx.r6.s64 = -ctx.r10.s64;
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r31,r10
	r31.s64 = ctx.r10.s8;
	// or r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 | ctx.r5.u64;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// slw r10,r7,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
loc_8246255C:
	// addic. r7,r8,-256
	xer.ca = ctx.r8.u32 > 255;
	ctx.r7.s64 = ctx.r8.s64 + -256;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge 0x82462570
	if (!cr0.lt) goto loc_82462570;
	// stbx r7,r29,r4
	PPC_STORE_U8(r29.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x824627b8
	goto loc_824627B8;
loc_82462570:
	// clrlwi r6,r7,29
	ctx.r6.u64 = ctx.r7.u32 & 0x7;
	// cmpwi cr6,r6,7
	cr6.compare<int32_t>(ctx.r6.s32, 7, xer);
	// bne cr6,0x82462600
	if (!cr6.eq) goto loc_82462600;
	// rlwinm r10,r9,9,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 9) & 0x1FE;
	// lhax r10,r10,r17
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + r17.u32));
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x824625bc
	if (!cr0.lt) goto loc_824625BC;
	// lis r8,128
	ctx.r8.s64 = 8388608;
loc_82462590:
	// and r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 & ctx.r9.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r10,r10,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r10,r10,r19
	ctx.r10.s64 = int16_t(PPC_LOAD_U16(ctx.r10.u32 + r19.u32));
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x82462590
	if (cr0.lt) goto loc_82462590;
loc_824625BC:
	// lbzx r8,r10,r21
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r21.u32);
	// subf r6,r8,r31
	ctx.r6.s64 = r31.s64 - ctx.r8.s64;
	// slw r9,r9,r8
	ctx.r9.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// extsb r31,r6
	r31.s64 = ctx.r6.s8;
	// mr. r8,r31
	ctx.r8.u64 = r31.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bgt 0x824625fc
	if (cr0.gt) goto loc_824625FC;
	// lbz r6,1(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r5,r8
	ctx.r5.s64 = -ctx.r8.s64;
	// lbz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r6,r6,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// extsb r31,r8
	r31.s64 = ctx.r8.s8;
	// or r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 | ctx.r3.u64;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// slw r8,r6,r5
	ctx.r8.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r5.u8 & 0x3F));
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
loc_824625FC:
	// addi r6,r10,7
	ctx.r6.s64 = ctx.r10.s64 + 7;
loc_82462600:
	// srawi r10,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 3;
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// ble cr6,0x824626c4
	if (!cr6.gt) goto loc_824626C4;
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// ble cr6,0x824626ac
	if (!cr6.gt) goto loc_824626AC;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// lbz r10,12004(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12004);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
	// subfic r7,r3,32
	xer.ca = ctx.r3.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r3.s64;
	// extsb r31,r10
	r31.s64 = ctx.r10.s8;
	// srw r7,r9,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
	// mr. r10,r31
	ctx.r10.u64 = r31.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// slw r9,r9,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82462698
	if (cr0.gt) goto loc_82462698;
	// lbz r5,1(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// addi r3,r10,16
	ctx.r3.s64 = ctx.r10.s64 + 16;
	// neg r14,r10
	r14.s64 = -ctx.r10.s64;
	// lbz r15,0(r30)
	r15.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rotlwi r10,r5,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// extsb r31,r3
	r31.s64 = ctx.r3.s8;
	// or r5,r10,r15
	ctx.r5.u64 = ctx.r10.u64 | r15.u64;
	// mr. r10,r31
	ctx.r10.u64 = r31.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// slw r5,r5,r14
	ctx.r5.u64 = r14.u8 & 0x20 ? 0 : (ctx.r5.u32 << (r14.u8 & 0x3F));
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// bgt 0x82462698
	if (cr0.gt) goto loc_82462698;
	// lbz r5,1(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// lbz r31,0(r30)
	r31.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r5,r5,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// or r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 | r31.u64;
	// extsb r31,r10
	r31.s64 = ctx.r10.s8;
	// slw r10,r5,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r3.u8 & 0x3F));
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
loc_82462698:
	// addi r10,r8,3014
	ctx.r10.s64 = ctx.r8.s64 + 3014;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 + ctx.r7.u64;
	// b 0x824626b0
	goto loc_824626B0;
loc_824626AC:
	// lwz r8,12068(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12068);
loc_824626B0:
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,8(r27)
	PPC_STORE_U32(r27.u32 + 8, ctx.r10.u32);
	// stw r7,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r7.u32);
	// b 0x824626dc
	goto loc_824626DC;
loc_824626C4:
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// beq cr6,0x824626e0
	if (cr6.eq) goto loc_824626E0;
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stwx r7,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, ctx.r7.u32);
loc_824626DC:
	// stw r8,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r8.u32);
loc_824626E0:
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r8,r8,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r8.s64;
	// addi r10,r6,2
	ctx.r10.s64 = ctx.r6.s64 + 2;
	// and r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// blt cr6,0x82462700
	if (cr6.lt) goto loc_82462700;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
loc_82462700:
	// subf r6,r8,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r8.s64;
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// bge cr6,0x8246272c
	if (!cr6.lt) goto loc_8246272C;
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + r29.u64;
loc_82462710:
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stbx r7,r29,r4
	PPC_STORE_U8(r29.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bgt 0x82462710
	if (cr0.gt) goto loc_82462710;
	// b 0x824627b8
	goto loc_824627B8;
loc_8246272C:
	// cmpwi cr6,r10,16
	cr6.compare<int32_t>(ctx.r10.s32, 16, xer);
	// ble cr6,0x8246277c
	if (!cr6.gt) goto loc_8246277C;
	// addi r7,r10,-17
	ctx.r7.s64 = ctx.r10.s64 + -17;
	// add r3,r29,r4
	ctx.r3.u64 = r29.u64 + ctx.r4.u64;
	// rlwinm r7,r7,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// add r5,r8,r29
	ctx.r5.u64 = ctx.r8.u64 + r29.u64;
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// rlwinm r7,r6,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 + ctx.r4.u64;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
loc_82462758:
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lvrx128 v62,r23,r5
	temp.u32 = r23.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvlx128 v63,r0,r3
	ea = ctx.r3.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v63.u8[15 - i]);
	// stvrx128 v63,r3,r23
	ea = ctx.r3.u32 + r23.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v63.u8[i]);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bne 0x82462758
	if (!cr0.eq) goto loc_82462758;
loc_8246277C:
	// add r7,r29,r4
	ctx.r7.u64 = r29.u64 + ctx.r4.u64;
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + r29.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lvrx128 v63,r23,r7
	temp.u32 = r23.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v61,r23,r8
	temp.u32 = r23.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v13,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// lvsr v12,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vor128 v11,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpgtub v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_cmpgt_epu8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vsel v13,v11,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvlx v13,r29,r4
	ea = r29.u32 + ctx.r4.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v13.u8[15 - i]);
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stvrx v13,r7,r23
	ea = ctx.r7.u32 + r23.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v13.u8[i]);
loc_824627B8:
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// blt cr6,0x824624d4
	if (cr6.lt) goto loc_824624D4;
loc_824627C0:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r3,r28,r4
	ctx.r3.s64 = ctx.r4.s64 - r28.s64;
	// stb r31,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r31.u8);
	// and r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 & ctx.r4.u64;
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// stw r30,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r10,11960(r11)
	PPC_STORE_U32(r11.u32 + 11960, ctx.r10.u32);
loc_824627DC:
	// b 0x823d9210
	return;
loc_824627E0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x824627dc
	goto loc_824627DC;
}

__attribute__((alias("__imp__sub_824627E8"))) PPC_WEAK_FUNC(sub_824627E8);
PPC_FUNC_IMPL(__imp__sub_824627E8) {
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
	ctx.lr = 0x824627F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,257
	cr6.compare<int32_t>(r30.s32, 257, xer);
	// bge cr6,0x82462840
	if (!cr6.lt) goto loc_82462840;
	// subfic r5,r30,257
	xer.ca = r30.u32 <= 257;
	ctx.r5.s64 = 257 - r30.s64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// blt cr6,0x82462818
	if (cr6.lt) goto loc_82462818;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
loc_82462818:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824621b0
	ctx.lr = 0x82462824;
	sub_824621B0(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// stw r3,11960(r29)
	PPC_STORE_U32(r29.u32 + 11960, ctx.r3.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add. r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bgt 0x82462840
	if (cr0.gt) goto loc_82462840;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82462850
	goto loc_82462850;
loc_82462840:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82462470
	ctx.lr = 0x82462850;
	sub_82462470(ctx, base);
loc_82462850:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82462858"))) PPC_WEAK_FUNC(sub_82462858);
PPC_FUNC_IMPL(__imp__sub_82462858) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82462860;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// add r26,r4,r5
	r26.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r23,r11,3644
	r23.s64 = r11.s64 + 3644;
	// addi r22,r11,9020
	r22.s64 = r11.s64 + 9020;
	// addi r21,r11,24
	r21.s64 = r11.s64 + 24;
	// lwz r19,11016(r11)
	r19.u64 = PPC_LOAD_U32(r11.u32 + 11016);
	// addi r20,r11,2072
	r20.s64 = r11.s64 + 2072;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r25,r11,2584
	r25.s64 = r11.s64 + 2584;
	// lbz r9,11956(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 11956);
	// addi r24,r11,3256
	r24.s64 = r11.s64 + 3256;
	// lwz r10,11952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11952);
	// addi r28,r11,3508
	r28.s64 = r11.s64 + 3508;
	// lwz r31,11012(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 11012);
	// addi r27,r11,3636
	r27.s64 = r11.s64 + 3636;
	// addi r29,r11,12
	r29.s64 = r11.s64 + 12;
	// b 0x82462ba8
	goto loc_82462BA8;
loc_824628A4:
	// rlwinm r8,r10,11,21,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FE;
	// lhax r7,r8,r21
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + r21.u32));
	// cmpwi r7,0
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge 0x824628e4
	if (!cr0.lt) goto loc_824628E4;
	// lis r8,32
	ctx.r8.s64 = 2097152;
loc_824628B8:
	// and r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 & ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r7,r7,r23
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + r23.u32));
	// cmpwi r7,0
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt 0x824628b8
	if (cr0.lt) goto loc_824628B8;
loc_824628E4:
	// cmplw cr6,r31,r19
	cr6.compare<uint32_t>(r31.u32, r19.u32, xer);
	// bge cr6,0x82462bc4
	if (!cr6.lt) goto loc_82462BC4;
	// lbzx r8,r7,r25
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + r25.u32);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bgt 0x8246292c
	if (cr0.gt) goto loc_8246292C;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// neg r6,r8
	ctx.r6.s64 = -ctx.r8.s64;
	// lbz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// or r5,r9,r5
	ctx.r5.u64 = ctx.r9.u64 | ctx.r5.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r5,r6
	ctx.r8.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_8246292C:
	// addic. r6,r7,-256
	xer.ca = ctx.r7.u32 > 255;
	ctx.r6.s64 = ctx.r7.s64 + -256;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge 0x82462950
	if (!cr0.lt) goto loc_82462950;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r7,r6,24
	ctx.r7.u64 = ctx.r6.u32 & 0xFF;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + r30.u64;
	// stbx r7,r30,r4
	PPC_STORE_U8(r30.u32 + ctx.r4.u32, ctx.r7.u8);
	// stbx r7,r8,r4
	PPC_STORE_U8(ctx.r8.u32 + ctx.r4.u32, ctx.r7.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x82462ba8
	goto loc_82462BA8;
loc_82462950:
	// clrlwi r5,r6,29
	ctx.r5.u64 = ctx.r6.u32 & 0x7;
	// cmpwi cr6,r5,7
	cr6.compare<int32_t>(ctx.r5.s32, 7, xer);
	// bne cr6,0x824629e0
	if (!cr6.eq) goto loc_824629E0;
	// rlwinm r8,r10,9,23,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhax r8,r8,r20
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + r20.u32));
	// cmpwi r8,0
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge 0x8246299c
	if (!cr0.lt) goto loc_8246299C;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_82462970:
	// and r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r5,r5
	ctx.r5.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r5,r5,27,5,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// subf r8,r8,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r8,r8,r22
	ctx.r8.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + r22.u32));
	// cmpwi r8,0
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x82462970
	if (cr0.lt) goto loc_82462970;
loc_8246299C:
	// lbzx r7,r8,r24
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + r24.u32);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// mr. r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bgt 0x824629dc
	if (cr0.gt) goto loc_824629DC;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// neg r5,r7
	ctx.r5.s64 = -ctx.r7.s64;
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// or r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 | ctx.r3.u64;
	// extsb r9,r7
	ctx.r9.s64 = ctx.r7.s8;
	// slw r7,r3,r5
	ctx.r7.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
loc_824629DC:
	// addi r5,r8,7
	ctx.r5.s64 = ctx.r8.s64 + 7;
loc_824629E0:
	// srawi r8,r6,3
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 3;
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// cmpwi cr6,r6,2
	cr6.compare<int32_t>(ctx.r6.s32, 2, xer);
	// ble cr6,0x82462b58
	if (!cr6.gt) goto loc_82462B58;
	// add r8,r6,r11
	ctx.r8.u64 = ctx.r6.u64 + r11.u64;
	// lbz r7,12004(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12004);
	// cmplwi cr6,r7,3
	cr6.compare<uint32_t>(ctx.r7.u32, 3, xer);
	// blt cr6,0x82462ad8
	if (cr6.lt) goto loc_82462AD8;
	// addic. r7,r7,-3
	xer.ca = ctx.r7.u32 > 2;
	ctx.r7.s64 = ctx.r7.s64 + -3;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x82462a68
	if (cr0.eq) goto loc_82462A68;
	// lbz r8,12004(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12004);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// extsb r3,r8
	ctx.r3.s64 = ctx.r8.s8;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// subf r8,r3,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r3.s64;
	// subfic r7,r9,35
	xer.ca = ctx.r9.u32 <= 35;
	ctx.r7.s64 = 35 - ctx.r9.s64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// addi r3,r9,-3
	ctx.r3.s64 = ctx.r9.s64 + -3;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// srw r7,r10,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82462a6c
	if (cr0.gt) goto loc_82462A6C;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// lbz r18,0(r31)
	r18.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// or r18,r9,r18
	r18.u64 = ctx.r9.u64 | r18.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r18,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// b 0x82462a6c
	goto loc_82462A6C;
loc_82462A68:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82462A6C:
	// rlwinm r3,r10,7,25,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x7F;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r6,3014
	ctx.r7.s64 = ctx.r6.s64 + 3014;
	// mr r18,r9
	r18.u64 = ctx.r9.u64;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r7,r3,r28
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + r28.u32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r9,r7,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + r27.u32);
	// subf r8,r9,r18
	ctx.r8.s64 = r18.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bgt 0x82462ad0
	if (cr0.gt) goto loc_82462AD0;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// lbz r18,0(r31)
	r18.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// or r18,r9,r18
	r18.u64 = ctx.r9.u64 | r18.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r18,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_82462AD0:
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// b 0x82462b44
	goto loc_82462B44;
loc_82462AD8:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82462b40
	if (cr6.eq) goto loc_82462B40;
	// lbz r8,12004(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12004);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subfic r8,r3,32
	xer.ca = ctx.r3.u32 <= 32;
	ctx.r8.s64 = 32 - ctx.r3.s64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// srw r7,r10,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r8.u8 & 0x3F));
	// mr. r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82462b2c
	if (cr0.gt) goto loc_82462B2C;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// neg r3,r8
	ctx.r3.s64 = -ctx.r8.s64;
	// lbz r18,0(r31)
	r18.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rotlwi r9,r9,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
	// or r18,r9,r18
	r18.u64 = ctx.r9.u64 | r18.u64;
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// slw r8,r18,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
loc_82462B2C:
	// addi r8,r6,3014
	ctx.r8.s64 = ctx.r6.s64 + 3014;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x82462b44
	goto loc_82462B44;
loc_82462B40:
	// li r8,1
	ctx.r8.s64 = 1;
loc_82462B44:
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r7,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r7.u32);
	// stw r6,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r6.u32);
	// b 0x82462b68
	goto loc_82462B68;
loc_82462B58:
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r8,r7,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + r29.u32);
	// stwx r6,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + r29.u32, ctx.r6.u32);
loc_82462B68:
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// subf r7,r8,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r8.s64;
loc_82462B78:
	// and r8,r7,r3
	ctx.r8.u64 = ctx.r7.u64 & ctx.r3.u64;
	// cmpwi cr6,r4,257
	cr6.compare<int32_t>(ctx.r4.s32, 257, xer);
	// lbzx r8,r8,r30
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + r30.u32);
	// stbx r8,r30,r4
	PPC_STORE_U8(r30.u32 + ctx.r4.u32, ctx.r8.u8);
	// bge cr6,0x82462b98
	if (!cr6.lt) goto loc_82462B98;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + r30.u64;
	// stbx r8,r6,r4
	PPC_STORE_U8(ctx.r6.u32 + ctx.r4.u32, ctx.r8.u8);
loc_82462B98:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// bgt 0x82462b78
	if (cr0.gt) goto loc_82462B78;
loc_82462BA8:
	// cmpw cr6,r4,r26
	cr6.compare<int32_t>(ctx.r4.s32, r26.s32, xer);
	// blt cr6,0x824628a4
	if (cr6.lt) goto loc_824628A4;
	// stb r9,11956(r11)
	PPC_STORE_U8(r11.u32 + 11956, ctx.r9.u8);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stw r10,11952(r11)
	PPC_STORE_U32(r11.u32 + 11952, ctx.r10.u32);
	// stw r31,11012(r11)
	PPC_STORE_U32(r11.u32 + 11012, r31.u32);
loc_82462BC0:
	// b 0x823d9220
	return;
loc_82462BC4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82462bc0
	goto loc_82462BC0;
}

__attribute__((alias("__imp__sub_82462BCC"))) PPC_WEAK_FUNC(sub_82462BCC);
PPC_FUNC_IMPL(__imp__sub_82462BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82462BD0"))) PPC_WEAK_FUNC(sub_82462BD0);
PPC_FUNC_IMPL(__imp__sub_82462BD0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82462BD8;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// add r28,r4,r5
	r28.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r26,r11,11956
	r26.s64 = r11.s64 + 11956;
	// addi r25,r11,11952
	r25.s64 = r11.s64 + 11952;
	// addi r24,r11,11012
	r24.s64 = r11.s64 + 11012;
	// lwz r14,11016(r11)
	r14.u64 = PPC_LOAD_U32(r11.u32 + 11016);
	// addi r18,r11,3644
	r18.s64 = r11.s64 + 3644;
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r17,r11,9020
	r17.s64 = r11.s64 + 9020;
	// lbz r8,11956(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 11956);
	// addi r16,r11,24
	r16.s64 = r11.s64 + 24;
	// lwz r10,11952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11952);
	// addi r15,r11,2072
	r15.s64 = r11.s64 + 2072;
	// lwz r30,11012(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 11012);
	// addi r20,r11,2584
	r20.s64 = r11.s64 + 2584;
	// addi r19,r11,3256
	r19.s64 = r11.s64 + 3256;
	// addi r23,r11,3508
	r23.s64 = r11.s64 + 3508;
	// addi r22,r11,3636
	r22.s64 = r11.s64 + 3636;
	// addi r27,r11,12
	r27.s64 = r11.s64 + 12;
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// bge cr6,0x82462fd0
	if (!cr6.lt) goto loc_82462FD0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r21,16
	r21.s64 = 16;
	// addi r9,r9,-22608
	ctx.r9.s64 = ctx.r9.s64 + -22608;
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82462C3C:
	// rlwinm r9,r10,11,21,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FE;
	// lhax r7,r9,r16
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + r16.u32));
	// cmpwi r7,0
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge 0x82462c7c
	if (!cr0.lt) goto loc_82462C7C;
	// lis r9,32
	ctx.r9.s64 = 2097152;
loc_82462C50:
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r7,r7,r18
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(ctx.r7.u32 + r18.u32));
	// cmpwi r7,0
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt 0x82462c50
	if (cr0.lt) goto loc_82462C50;
loc_82462C7C:
	// cmplw cr6,r30,r14
	cr6.compare<uint32_t>(r30.u32, r14.u32, xer);
	// bge cr6,0x82462ff0
	if (!cr6.lt) goto loc_82462FF0;
	// lbzx r9,r7,r20
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + r20.u32);
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x82462cc4
	if (cr0.gt) goto loc_82462CC4;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r6,r9
	ctx.r6.s64 = -ctx.r9.s64;
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// or r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 | ctx.r5.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r5,r6
	ctx.r9.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r6.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82462CC4:
	// addic. r6,r7,-256
	xer.ca = ctx.r7.u32 > 255;
	ctx.r6.s64 = ctx.r7.s64 + -256;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge 0x82462cd8
	if (!cr0.lt) goto loc_82462CD8;
	// stbx r6,r29,r4
	PPC_STORE_U8(r29.u32 + ctx.r4.u32, ctx.r6.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x82462fc8
	goto loc_82462FC8;
loc_82462CD8:
	// clrlwi r5,r6,29
	ctx.r5.u64 = ctx.r6.u32 & 0x7;
	// cmpwi cr6,r5,7
	cr6.compare<int32_t>(ctx.r5.s32, 7, xer);
	// bne cr6,0x82462d68
	if (!cr6.eq) goto loc_82462D68;
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhax r9,r9,r15
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + r15.u32));
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge 0x82462d24
	if (!cr0.lt) goto loc_82462D24;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_82462CF8:
	// and r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r5,r5
	ctx.r5.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r5,r5,27,5,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// subf r9,r9,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r9.s64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhax r9,r9,r17
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r9.u32 + r17.u32));
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x82462cf8
	if (cr0.lt) goto loc_82462CF8;
loc_82462D24:
	// lbzx r7,r9,r19
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + r19.u32);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// slw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r7.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bgt 0x82462d64
	if (cr0.gt) goto loc_82462D64;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r5,r7
	ctx.r5.s64 = -ctx.r7.s64;
	// lbz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// or r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 | ctx.r3.u64;
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// slw r7,r3,r5
	ctx.r7.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
loc_82462D64:
	// addi r5,r9,7
	ctx.r5.s64 = ctx.r9.s64 + 7;
loc_82462D68:
	// srawi r9,r6,3
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 3;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// cmpwi cr6,r6,2
	cr6.compare<int32_t>(ctx.r6.s32, 2, xer);
	// ble cr6,0x82462ee4
	if (!cr6.gt) goto loc_82462EE4;
	// add r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 + r11.u64;
	// lbz r7,12004(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// cmplwi cr6,r7,3
	cr6.compare<uint32_t>(ctx.r7.u32, 3, xer);
	// blt cr6,0x82462e5c
	if (cr6.lt) goto loc_82462E5C;
	// addic. r7,r7,-3
	xer.ca = ctx.r7.u32 > 2;
	ctx.r7.s64 = ctx.r7.s64 + -3;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x82462dec
	if (cr0.eq) goto loc_82462DEC;
	// lbz r9,12004(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r3,r9,-3
	ctx.r3.s64 = ctx.r9.s64 + -3;
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// subfic r7,r9,35
	xer.ca = ctx.r9.u32 <= 35;
	ctx.r7.s64 = 35 - ctx.r9.s64;
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// srw r7,r10,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x82462df0
	if (cr0.gt) goto loc_82462DF0;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lbz r31,0(r30)
	r31.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// or r31,r8,r31
	r31.u64 = ctx.r8.u64 | r31.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r31,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// b 0x82462df0
	goto loc_82462DF0;
loc_82462DEC:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82462DF0:
	// rlwinm r3,r10,7,25,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x7F;
	// rlwinm r9,r7,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r6,3014
	ctx.r7.s64 = ctx.r6.s64 + 3014;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r7,r3,r23
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + r23.u32);
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lbzx r9,r7,r22
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + r22.u32);
	// subf r8,r9,r31
	ctx.r8.s64 = r31.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x82462e54
	if (cr0.gt) goto loc_82462E54;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lbz r31,0(r30)
	r31.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// or r31,r8,r31
	r31.u64 = ctx.r8.u64 | r31.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r31,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82462E54:
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// b 0x82462ed0
	goto loc_82462ED0;
loc_82462E5C:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82462ec4
	if (cr6.eq) goto loc_82462EC4;
	// lbz r9,12004(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12004);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// subfic r7,r3,32
	xer.ca = ctx.r3.u32 <= 32;
	ctx.r7.s64 = 32 - ctx.r3.s64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// srw r7,r10,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// mr. r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r10,r10,r3
	ctx.r10.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r3.u8 & 0x3F));
	// bgt 0x82462eb0
	if (cr0.gt) goto loc_82462EB0;
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// neg r3,r9
	ctx.r3.s64 = -ctx.r9.s64;
	// lbz r31,0(r30)
	r31.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// or r31,r8,r31
	r31.u64 = ctx.r8.u64 | r31.u64;
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// slw r9,r31,r3
	ctx.r9.u64 = ctx.r3.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r3.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82462EB0:
	// addi r9,r6,3014
	ctx.r9.s64 = ctx.r6.s64 + 3014;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// b 0x82462ed0
	goto loc_82462ED0;
loc_82462EC4:
	// addi r9,r6,3014
	ctx.r9.s64 = ctx.r6.s64 + 3014;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
loc_82462ED0:
	// lwz r7,4(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r7,8(r27)
	PPC_STORE_U32(r27.u32 + 8, ctx.r7.u32);
	// stw r6,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r6.u32);
	// b 0x82462ef4
	goto loc_82462EF4;
loc_82462EE4:
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r9,r7,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + r27.u32);
	// stwx r6,r7,r27
	PPC_STORE_U32(ctx.r7.u32 + r27.u32, ctx.r6.u32);
loc_82462EF4:
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r6,r9,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r9.s64;
	// stw r9,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r9.u32);
	// addi r9,r5,2
	ctx.r9.s64 = ctx.r5.s64 + 2;
	// and r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 & ctx.r7.u64;
	// subf r6,r7,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r7.s64;
	// cmplw cr6,r6,r9
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, xer);
	// bge cr6,0x82462f3c
	if (!cr6.lt) goto loc_82462F3C;
	// cmplwi cr6,r6,16
	cr6.compare<uint32_t>(ctx.r6.u32, 16, xer);
	// bge cr6,0x82462f3c
	if (!cr6.lt) goto loc_82462F3C;
	// add r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 + r29.u64;
loc_82462F20:
	// lbz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stbx r6,r29,r4
	PPC_STORE_U8(r29.u32 + ctx.r4.u32, ctx.r6.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// bgt 0x82462f20
	if (cr0.gt) goto loc_82462F20;
	// b 0x82462fc8
	goto loc_82462FC8;
loc_82462F3C:
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// ble cr6,0x82462f8c
	if (!cr6.gt) goto loc_82462F8C;
	// addi r6,r9,-17
	ctx.r6.s64 = ctx.r9.s64 + -17;
	// add r31,r29,r4
	r31.u64 = r29.u64 + ctx.r4.u64;
	// rlwinm r6,r6,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// add r3,r7,r29
	ctx.r3.u64 = ctx.r7.u64 + r29.u64;
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// rlwinm r6,r5,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r6,r4
	ctx.r4.u64 = ctx.r6.u64 + ctx.r4.u64;
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
loc_82462F68:
	// lvlx128 v63,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lvrx128 v62,r21,r3
	temp.u32 = r21.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvlx128 v63,r0,r31
	ea = r31.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v63.u8[15 - i]);
	// stvrx128 v63,r31,r21
	ea = r31.u32 + r21.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v63.u8[i]);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x82462f68
	if (!cr0.eq) goto loc_82462F68;
loc_82462F8C:
	// add r6,r29,r4
	ctx.r6.u64 = r29.u64 + ctx.r4.u64;
	// add r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 + r29.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lvrx128 v63,r21,r6
	temp.u32 = r21.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v61,r21,r7
	temp.u32 = r21.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v13,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// lvsr v12,r9,r5
	temp.u32 = ctx.r9.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vor128 v11,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpgtub v12,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_cmpgt_epu8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// vsel v13,v11,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvlx v13,r29,r4
	ea = r29.u32 + ctx.r4.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, ctx.v13.u8[15 - i]);
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stvrx v13,r6,r21
	ea = ctx.r6.u32 + r21.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, ctx.v13.u8[i]);
loc_82462FC8:
	// cmpw cr6,r4,r28
	cr6.compare<int32_t>(ctx.r4.s32, r28.s32, xer);
	// blt cr6,0x82462c3c
	if (cr6.lt) goto loc_82462C3C;
loc_82462FD0:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r3,r28,r4
	ctx.r3.s64 = ctx.r4.s64 - r28.s64;
	// stb r8,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r8.u8);
	// and r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 & ctx.r4.u64;
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
	// stw r30,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r9,11960(r11)
	PPC_STORE_U32(r11.u32 + 11960, ctx.r9.u32);
loc_82462FEC:
	// b 0x823d9210
	return;
loc_82462FF0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82462fec
	goto loc_82462FEC;
}

__attribute__((alias("__imp__sub_82462FF8"))) PPC_WEAK_FUNC(sub_82462FF8);
PPC_FUNC_IMPL(__imp__sub_82462FF8) {
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
	ctx.lr = 0x82463000;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,257
	cr6.compare<int32_t>(r30.s32, 257, xer);
	// bge cr6,0x82463050
	if (!cr6.lt) goto loc_82463050;
	// subfic r5,r30,257
	xer.ca = r30.u32 <= 257;
	ctx.r5.s64 = 257 - r30.s64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// blt cr6,0x82463028
	if (cr6.lt) goto loc_82463028;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
loc_82463028:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82462858
	ctx.lr = 0x82463034;
	sub_82462858(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// stw r3,11960(r29)
	PPC_STORE_U32(r29.u32 + 11960, ctx.r3.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add. r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bgt 0x82463050
	if (cr0.gt) goto loc_82463050;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82463060
	goto loc_82463060;
loc_82463050:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82462bd0
	ctx.lr = 0x82463060;
	sub_82462BD0(ctx, base);
loc_82463060:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82463068"))) PPC_WEAK_FUNC(sub_82463068);
PPC_FUNC_IMPL(__imp__sub_82463068) {
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
	ctx.lr = 0x82463070;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r31,11020(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 11020);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82463104
	if (cr6.eq) goto loc_82463104;
	// lwz r11,11964(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11964);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824630a8
	if (cr6.eq) goto loc_824630A8;
	// lwz r11,11972(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11972);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r11,32768
	cr6.compare<uint32_t>(r11.u32, 32768, xer);
	// blt cr6,0x824630ac
	if (cr6.lt) goto loc_824630AC;
loc_824630A8:
	// li r28,0
	r28.s64 = 0;
loc_824630AC:
	// lbz r11,12260(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12260);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x824630c8
	if (cr0.eq) goto loc_824630C8;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8246310c
	if (cr6.eq) goto loc_8246310C;
	// lwz r31,12264(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 12264);
loc_824630C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824630D0;
	sub_8244D5C0(ctx, base);
loc_824630D0:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82463104
	if (cr6.eq) goto loc_82463104;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82461a08
	ctx.lr = 0x824630E8;
	sub_82461A08(ctx, base);
	// lbz r11,12260(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12260);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82463104
	if (cr0.eq) goto loc_82463104;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,11020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 11020);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8244d510
	ctx.lr = 0x82463104;
	sub_8244D510(ctx, base);
loc_82463104:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8246310C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244d510
	ctx.lr = 0x82463114;
	sub_8244D510(ctx, base);
	// b 0x824630d0
	goto loc_824630D0;
}

__attribute__((alias("__imp__sub_82463118"))) PPC_WEAK_FUNC(sub_82463118);
PPC_FUNC_IMPL(__imp__sub_82463118) {
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
	ctx.lr = 0x82463120;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r31,0
	r31.s64 = 0;
loc_82463138:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82461f40
	ctx.lr = 0x82463144;
	sub_82461F40(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stbx r3,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,20
	cr6.compare<int32_t>(r31.s32, 20, xer);
	// blt cr6,0x82463138
	if (cr6.lt) goto loc_82463138;
	// lbz r11,11959(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 11959);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8246316c
	if (cr0.eq) goto loc_8246316C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8246364c
	goto loc_8246364C;
loc_8246316C:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,304
	ctx.r7.s64 = ctx.r1.s64 + 304;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824637c0
	ctx.lr = 0x82463188;
	sub_824637C0(ctx, base);
	// lwz r11,11012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11012);
	// lwz r10,11952(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 11952);
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r6,11956(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 11956);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// lbz r3,11959(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 11959);
	// lwz r31,11016(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 11016);
	// ble cr6,0x82463630
	if (!cr6.gt) goto loc_82463630;
loc_824631A8:
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// rlwinm r9,r10,9,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0x1FE;
	// lhzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r8.u32);
	// extsh. r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge 0x824631f8
	if (!cr0.lt) goto loc_824631F8;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_824631C0:
	// neg r9,r8
	ctx.r9.s64 = -ctx.r8.s64;
	// and r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 & ctx.r10.u64;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r9,r5
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r5.u32);
	// extsh. r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x824631c0
	if (cr0.lt) goto loc_824631C0;
loc_824631F8:
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lbzx r9,r8,r9
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// subf r7,r9,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r9.s64;
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x82463288
	if (cr0.gt) goto loc_82463288;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bge cr6,0x82463258
	if (!cr6.lt) goto loc_82463258;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r26,r9
	r26.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 | ctx.r5.u64;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r7,r7,r26
	ctx.r7.u64 = r26.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r26.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x82463288
	if (cr0.gt) goto loc_82463288;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x82463260
	if (cr6.lt) goto loc_82463260;
loc_82463258:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82463288
	goto loc_82463288;
loc_82463260:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// neg r5,r9
	ctx.r5.s64 = -ctx.r9.s64;
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// slw r9,r7,r5
	ctx.r9.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82463288:
	// clrlwi. r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x82463630
	if (!cr0.eq) goto loc_82463630;
	// cmpwi cr6,r8,17
	cr6.compare<int32_t>(ctx.r8.s32, 17, xer);
	// bne cr6,0x82463360
	if (!cr6.eq) goto loc_82463360;
	// addi r9,r6,-4
	ctx.r9.s64 = ctx.r6.s64 + -4;
	// rlwinm r8,r10,4,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x82463320
	if (cr0.gt) goto loc_82463320;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bge cr6,0x824632f0
	if (!cr6.lt) goto loc_824632F0;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r26,r9
	r26.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 | ctx.r5.u64;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r7,r7,r26
	ctx.r7.u64 = r26.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r26.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x82463320
	if (cr0.gt) goto loc_82463320;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x824632f8
	if (cr6.lt) goto loc_824632F8;
loc_824632F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82463320
	goto loc_82463320;
loc_824632F8:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// neg r5,r9
	ctx.r5.s64 = -ctx.r9.s64;
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// slw r9,r7,r5
	ctx.r9.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_82463320:
	// addi r9,r8,4
	ctx.r9.s64 = ctx.r8.s64 + 4;
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// blt cr6,0x82463334
	if (cr6.lt) goto loc_82463334;
	// subf r9,r4,r29
	ctx.r9.s64 = r29.s64 - ctx.r4.s64;
loc_82463334:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82463600
	if (!cr6.gt) goto loc_82463600;
	// add r8,r4,r28
	ctx.r8.u64 = ctx.r4.u64 + r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq 0x8246342c
	if (cr0.eq) goto loc_8246342C;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82463350:
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x82463350
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82463350;
	// b 0x8246342c
	goto loc_8246342C;
loc_82463360:
	// cmpwi cr6,r8,18
	cr6.compare<int32_t>(ctx.r8.s32, 18, xer);
	// bne cr6,0x82463434
	if (!cr6.eq) goto loc_82463434;
	// addi r9,r6,-5
	ctx.r9.s64 = ctx.r6.s64 + -5;
	// rlwinm r8,r10,5,27,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1F;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x824633f0
	if (cr0.gt) goto loc_824633F0;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bge cr6,0x824633c0
	if (!cr6.lt) goto loc_824633C0;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r26,r9
	r26.s64 = -ctx.r9.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 | ctx.r5.u64;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r7,r7,r26
	ctx.r7.u64 = r26.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r26.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x824633f0
	if (cr0.gt) goto loc_824633F0;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x824633c8
	if (cr6.lt) goto loc_824633C8;
loc_824633C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824633f0
	goto loc_824633F0;
loc_824633C8:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// neg r5,r9
	ctx.r5.s64 = -ctx.r9.s64;
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// slw r9,r7,r5
	ctx.r9.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r5.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_824633F0:
	// addi r9,r8,20
	ctx.r9.s64 = ctx.r8.s64 + 20;
	// add r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 + ctx.r4.u64;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// blt cr6,0x82463404
	if (cr6.lt) goto loc_82463404;
	// subf r9,r4,r29
	ctx.r9.s64 = r29.s64 - ctx.r4.s64;
loc_82463404:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82463600
	if (!cr6.gt) goto loc_82463600;
	// add r8,r4,r28
	ctx.r8.u64 = ctx.r4.u64 + r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq 0x8246342c
	if (cr0.eq) goto loc_8246342C;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82463420:
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x82463420
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82463420;
loc_8246342C:
	// add r4,r9,r4
	ctx.r4.u64 = ctx.r9.u64 + ctx.r4.u64;
	// b 0x82463600
	goto loc_82463600;
loc_82463434:
	// cmpwi cr6,r8,19
	cr6.compare<int32_t>(ctx.r8.s32, 19, xer);
	// bne cr6,0x82463608
	if (!cr6.eq) goto loc_82463608;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// mr. r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt 0x824634c8
	if (cr0.gt) goto loc_824634C8;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bge cr6,0x82463498
	if (!cr6.lt) goto loc_82463498;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// neg r26,r10
	r26.s64 = -ctx.r10.s64;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r10,r7,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r10,r5
	ctx.r7.u64 = ctx.r10.u64 | ctx.r5.u64;
	// mr. r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// slw r7,r7,r26
	ctx.r7.u64 = r26.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r26.u8 & 0x3F));
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x824634c8
	if (cr0.gt) goto loc_824634C8;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x824634a0
	if (cr6.lt) goto loc_824634A0;
loc_82463498:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824634c8
	goto loc_824634C8;
loc_824634A0:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// neg r5,r10
	ctx.r5.s64 = -ctx.r10.s64;
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// extsb r6,r10
	ctx.r6.s64 = ctx.r10.s8;
	// slw r10,r7,r5
	ctx.r10.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r5.u8 & 0x3F));
	// or r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 | ctx.r9.u64;
loc_824634C8:
	// addi r5,r8,4
	ctx.r5.s64 = ctx.r8.s64 + 4;
	// add r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 + ctx.r4.u64;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// blt cr6,0x824634dc
	if (cr6.lt) goto loc_824634DC;
	// subf r5,r4,r29
	ctx.r5.s64 = r29.s64 - ctx.r4.s64;
loc_824634DC:
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// rlwinm r10,r9,9,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 9) & 0x1FE;
	// lhzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r8.u32);
	// extsh. r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge 0x8246352c
	if (!cr0.lt) goto loc_8246352C;
	// lis r7,128
	ctx.r7.s64 = 8388608;
loc_824634F4:
	// neg r10,r8
	ctx.r10.s64 = -ctx.r8.s64;
	// and r8,r7,r9
	ctx.r8.u64 = ctx.r7.u64 & ctx.r9.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r26,r8,27,5,31
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// xori r10,r26,1
	ctx.r10.u64 = r26.u64 ^ 1;
	// addi r26,r1,112
	r26.s64 = ctx.r1.s64 + 112;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r10,r26
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + r26.u32);
	// extsh. r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt 0x824634f4
	if (cr0.lt) goto loc_824634F4;
loc_8246352C:
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lbzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// subf r7,r10,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r10.s64;
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt 0x824635bc
	if (cr0.gt) goto loc_824635BC;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bge cr6,0x8246358c
	if (!cr6.lt) goto loc_8246358C;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// neg r25,r9
	r25.s64 = -ctx.r9.s64;
	// lbz r26,0(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r9,r7,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r9,r26
	ctx.r7.u64 = ctx.r9.u64 | r26.u64;
	// mr. r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// slw r7,r7,r25
	ctx.r7.u64 = r25.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r25.u8 & 0x3F));
	// or r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 | ctx.r10.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x824635bc
	if (cr0.gt) goto loc_824635BC;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x82463594
	if (cr6.lt) goto loc_82463594;
loc_8246358C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824635bc
	goto loc_824635BC;
loc_82463594:
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// neg r26,r9
	r26.s64 = -ctx.r9.s64;
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// slw r9,r7,r26
	ctx.r9.u64 = r26.u8 & 0x20 ? 0 : (ctx.r7.u32 << (r26.u8 & 0x3F));
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_824635BC:
	// lbzx r9,r4,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + r27.u32);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r9,r9,17
	ctx.r9.s64 = ctx.r9.s64 + 17;
	// cmpwi cr6,r9,17
	cr6.compare<int32_t>(ctx.r9.s32, 17, xer);
	// blt cr6,0x824635d4
	if (cr6.lt) goto loc_824635D4;
	// addi r9,r9,-17
	ctx.r9.s64 = ctx.r9.s64 + -17;
loc_824635D4:
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82463600
	if (!cr6.gt) goto loc_82463600;
	// add r9,r4,r28
	ctx.r9.u64 = ctx.r4.u64 + r28.u64;
	// cmplwi r5,0
	cr0.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq 0x824635fc
	if (cr0.eq) goto loc_824635FC;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
loc_824635F0:
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x824635f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824635F0;
loc_824635FC:
	// add r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 + ctx.r4.u64;
loc_82463600:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// b 0x82463624
	goto loc_82463624;
loc_82463608:
	// lbzx r9,r4,r27
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + r27.u32);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r9,r9,17
	ctx.r9.s64 = ctx.r9.s64 + 17;
	// cmpwi cr6,r9,17
	cr6.compare<int32_t>(ctx.r9.s32, 17, xer);
	// blt cr6,0x82463620
	if (cr6.lt) goto loc_82463620;
	// addi r9,r9,-17
	ctx.r9.s64 = ctx.r9.s64 + -17;
loc_82463620:
	// stbx r9,r4,r28
	PPC_STORE_U8(ctx.r4.u32 + r28.u32, ctx.r9.u8);
loc_82463624:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// blt cr6,0x824631a8
	if (cr6.lt) goto loc_824631A8;
loc_82463630:
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r11,11012(r30)
	PPC_STORE_U32(r30.u32 + 11012, r11.u32);
	// stb r3,11959(r30)
	PPC_STORE_U8(r30.u32 + 11959, ctx.r3.u8);
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r10,11952(r30)
	PPC_STORE_U32(r30.u32 + 11952, ctx.r10.u32);
	// stb r6,11956(r30)
	PPC_STORE_U8(r30.u32 + 11956, ctx.r6.u8);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_8246364C:
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82463654"))) PPC_WEAK_FUNC(sub_82463654);
PPC_FUNC_IMPL(__imp__sub_82463654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82463658"))) PPC_WEAK_FUNC(sub_82463658);
PPC_FUNC_IMPL(__imp__sub_82463658) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r30,r31,2584
	r30.s64 = r31.s64 + 2584;
	// addi r5,r31,11028
	ctx.r5.s64 = r31.s64 + 11028;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82463118
	ctx.lr = 0x82463684;
	sub_82463118(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82463694
	if (!cr0.eq) goto loc_82463694;
loc_8246368C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82463730
	goto loc_82463730;
loc_82463694:
	// lbz r11,11957(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11957);
	// addi r6,r31,2840
	ctx.r6.s64 = r31.s64 + 2840;
	// addi r5,r31,11284
	ctx.r5.s64 = r31.s64 + 11284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r4,r11,3
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 3);
	// bl 0x82463118
	ctx.lr = 0x824636AC;
	sub_82463118(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8246368c
	if (cr0.eq) goto loc_8246368C;
	// lbz r11,11957(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11957);
	// addi r8,r31,3644
	ctx.r8.s64 = r31.s64 + 3644;
	// addi r7,r31,24
	ctx.r7.s64 = r31.s64 + 24;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824637c0
	ctx.lr = 0x824636D8;
	sub_824637C0(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8246368c
	if (cr0.eq) goto loc_8246368C;
	// addi r30,r31,3256
	r30.s64 = r31.s64 + 3256;
	// addi r5,r31,11700
	ctx.r5.s64 = r31.s64 + 11700;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,249
	ctx.r4.s64 = 249;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463118
	ctx.lr = 0x824636F8;
	sub_82463118(ctx, base);
	// clrlwi. r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8246368c
	if (cr0.eq) goto loc_8246368C;
	// addi r8,r31,9020
	ctx.r8.s64 = r31.s64 + 9020;
	// addi r7,r31,2072
	ctx.r7.s64 = r31.s64 + 2072;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,249
	ctx.r4.s64 = 249;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824637c0
	ctx.lr = 0x8246371C;
	sub_824637C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
loc_82463730:
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

__attribute__((alias("__imp__sub_82463748"))) PPC_WEAK_FUNC(sub_82463748);
PPC_FUNC_IMPL(__imp__sub_82463748) {
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
	ctx.lr = 0x82463750;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,3636
	r29.s64 = r31.s64 + 3636;
loc_82463760:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82461f40
	ctx.lr = 0x8246376C;
	sub_82461F40(ctx, base);
	// stbx r3,r29,r30
	PPC_STORE_U8(r29.u32 + r30.u32, ctx.r3.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x82463760
	if (cr6.lt) goto loc_82463760;
	// lbz r11,11959(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11959);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82463790
	if (cr0.eq) goto loc_82463790;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824637b4
	goto loc_824637B4;
loc_82463790:
	// addi r5,r31,3508
	ctx.r5.s64 = r31.s64 + 3508;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463a88
	ctx.lr = 0x824637A0;
	sub_82463A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
loc_824637B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824637BC"))) PPC_WEAK_FUNC(sub_824637BC);
PPC_FUNC_IMPL(__imp__sub_824637BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824637C0"))) PPC_WEAK_FUNC(sub_824637C0);
PPC_FUNC_IMPL(__imp__sub_824637C0) {
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
	ctx.lr = 0x824637C8;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// li r11,16
	r11.s64 = 16;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_824637F0:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824637f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824637F0;
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8246382c
	if (cr6.eq) goto loc_8246382C;
loc_82463808:
	// lbzx r9,r11,r24
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r24.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// blt cr6,0x82463808
	if (cr6.lt) goto loc_82463808;
loc_8246382C:
	// li r28,1
	r28.s64 = 1;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// mr r11,r25
	r11.u64 = r25.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_8246383C:
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// subfic r7,r10,16
	xer.ca = ctx.r10.u32 <= 16;
	ctx.r7.s64 = 16 - ctx.r10.s64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwzx r8,r11,r8
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// slw r9,r9,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwx r9,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// ble cr6,0x8246383c
	if (!cr6.gt) goto loc_8246383C;
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lis r4,1
	ctx.r4.s64 = 65536;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x824638ac
	if (cr6.eq) goto loc_824638AC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824638a4
	if (!cr6.eq) goto loc_824638A4;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// slw r11,r28,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 << (r11.u8 & 0x3F));
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x824638A0;
	sub_823D9890(ctx, base);
	// b 0x82463a78
	goto loc_82463A78;
loc_824638A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82463a7c
	goto loc_82463A7C;
loc_824638AC:
	// clrlwi r31,r6,24
	r31.u64 = ctx.r6.u32 & 0xFF;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// subfic r11,r31,16
	xer.ca = r31.u32 <= 16;
	r11.s64 = 16 - r31.s64;
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// blt cr6,0x8246390c
	if (cr6.lt) goto loc_8246390C;
	// clrlwi r6,r5,24
	ctx.r6.u64 = ctx.r5.u32 & 0xFF;
	// addi r9,r31,-1
	ctx.r9.s64 = r31.s64 + -1;
	// mr r11,r25
	r11.u64 = r25.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
loc_824638D8:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// slw r30,r28,r9
	r30.u64 = ctx.r9.u8 & 0x20 ? 0 : (r28.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r23,r11,r7
	r23.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwx r30,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, r30.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// srw r3,r23,r6
	ctx.r3.u64 = ctx.r6.u8 & 0x20 ? 0 : (r23.u32 >> (ctx.r6.u8 & 0x3F));
	// stwx r3,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r3.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x824638d8
	if (!cr0.eq) goto loc_824638D8;
	// cmplwi cr6,r8,16
	cr6.compare<uint32_t>(ctx.r8.u32, 16, xer);
	// bgt cr6,0x82463938
	if (cr6.gt) goto loc_82463938;
loc_8246390C:
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// subfic r10,r8,16
	xer.ca = ctx.r8.u32 <= 16;
	ctx.r10.s64 = 16 - ctx.r8.s64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// subfic r11,r8,17
	xer.ca = ctx.r8.u32 <= 17;
	r11.s64 = 17 - ctx.r8.s64;
loc_82463920:
	// slw r8,r28,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r28.u32 << (ctx.r10.u8 & 0x3F));
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82463920
	if (!cr0.eq) goto loc_82463920;
loc_82463938:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// clrlwi r30,r5,24
	r30.u64 = ctx.r5.u32 & 0xFF;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// srw r11,r11,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 >> (r30.u8 & 0x3F));
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x82463970
	if (cr6.eq) goto loc_82463970;
	// slw r9,r28,r31
	ctx.r9.u64 = r31.u8 & 0x20 ? 0 : (r28.u32 << (r31.u8 & 0x3F));
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r29
	ctx.r3.u64 = ctx.r10.u64 + r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x82463970;
	sub_823D9890(ctx, base);
loc_82463970:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82463a78
	if (!cr6.gt) goto loc_82463A78;
loc_82463980:
	// lbzx r9,r4,r24
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + r24.u32);
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq 0x82463a6c
	if (cr0.eq) goto loc_82463A6C;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// lwzx r11,r8,r7
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// bgt cr6,0x824639ec
	if (cr6.gt) goto loc_824639EC;
	// slw r9,r28,r31
	ctx.r9.u64 = r31.u8 & 0x20 ? 0 : (r28.u32 << (r31.u8 & 0x3F));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bgt cr6,0x824638a4
	if (cr6.gt) goto loc_824638A4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x824639e4
	if (!cr6.lt) goto loc_824639E4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// extsh r6,r4
	ctx.r6.s64 = ctx.r4.s16;
	// beq 0x824639e4
	if (cr0.eq) goto loc_824639E4;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_824639D8:
	// sth r6,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r6.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bdnz 0x824639d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824639D8;
loc_824639E4:
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// b 0x82463a6c
	goto loc_82463A6C;
loc_824639EC:
	// srw r6,r11,r30
	ctx.r6.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 >> (r30.u8 & 0x3F));
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// subf r10,r31,r9
	ctx.r10.s64 = ctx.r9.s64 - r31.s64;
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r6,r11,r31
	ctx.r6.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + r29.u64;
	// neg r7,r5
	ctx.r7.s64 = -ctx.r5.s64;
	// add r11,r9,r27
	r11.u64 = ctx.r9.u64 + r27.u64;
loc_82463A14:
	// lhz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82463a38
	if (!cr6.eq) goto loc_82463A38;
	// sth r25,2(r11)
	PPC_STORE_U16(r11.u32 + 2, r25.u16);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// sth r25,0(r11)
	PPC_STORE_U16(r11.u32 + 0, r25.u16);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// sth r7,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r7.u16);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
loc_82463A38:
	// extsh. r9,r6
	ctx.r9.s64 = ctx.r6.s16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lha r9,0(r8)
	ctx.r9.s64 = int16_t(PPC_LOAD_U16(ctx.r8.u32 + 0));
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bge 0x82463a54
	if (!cr0.lt) goto loc_82463A54;
	// subf r9,r9,r27
	ctx.r9.s64 = r27.s64 - ctx.r9.s64;
	// addi r8,r9,2
	ctx.r8.s64 = ctx.r9.s64 + 2;
	// b 0x82463a58
	goto loc_82463A58;
loc_82463A54:
	// subf r8,r9,r27
	ctx.r8.s64 = r27.s64 - ctx.r9.s64;
loc_82463A58:
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82463a14
	if (!cr0.eq) goto loc_82463A14;
	// sth r4,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r4.u16);
loc_82463A6C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r4,r26
	cr6.compare<int32_t>(ctx.r4.s32, r26.s32, xer);
	// blt cr6,0x82463980
	if (cr6.lt) goto loc_82463980;
loc_82463A78:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82463A7C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82463A84"))) PPC_WEAK_FUNC(sub_82463A84);
PPC_FUNC_IMPL(__imp__sub_82463A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82463A88"))) PPC_WEAK_FUNC(sub_82463A88);
PPC_FUNC_IMPL(__imp__sub_82463A88) {
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
	ctx.lr = 0x82463A90;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// li r31,0
	r31.s64 = 0;
loc_82463AA8:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// sthx r31,r9,r8
	PPC_STORE_U16(ctx.r9.u32 + ctx.r8.u32, r31.u16);
	// ble cr6,0x82463aa8
	if (!cr6.gt) goto loc_82463AA8;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82463AC8:
	// lbzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// lhzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sthx r8,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u16);
	// blt cr6,0x82463ac8
	if (cr6.lt) goto loc_82463AC8;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// sth r31,130(r1)
	PPC_STORE_U16(ctx.r1.u32 + 130, r31.u16);
loc_82463AF8:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// subfic r6,r11,16
	xer.ca = r11.u32 <= 16;
	ctx.r6.s64 = 16 - r11.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r5,r1,130
	ctx.r5.s64 = ctx.r1.s64 + 130;
	// lhzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lhzx r9,r8,r9
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r9.u32);
	// slw r10,r10,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// sthx r10,r8,r5
	PPC_STORE_U16(ctx.r8.u32 + ctx.r5.u32, ctx.r10.u16);
	// ble cr6,0x82463af8
	if (!cr6.gt) goto loc_82463AF8;
	// lhz r11,162(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 162);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82463b44
	if (cr0.eq) goto loc_82463B44;
loc_82463B3C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82463c30
	goto loc_82463C30;
loc_82463B44:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82463B48:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// subfic r8,r11,7
	xer.ca = r11.u32 <= 7;
	ctx.r8.s64 = 7 - r11.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// slw r8,r7,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r8.u8 & 0x3F));
	// lhzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sthx r8,r10,r5
	PPC_STORE_U16(ctx.r10.u32 + ctx.r5.u32, ctx.r8.u16);
	// rlwinm r6,r6,23,9,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0x7FFFFF;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// sthx r6,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u16);
	// ble cr6,0x82463b48
	if (!cr6.gt) goto loc_82463B48;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x82463bac
	if (cr6.gt) goto loc_82463BAC;
loc_82463B88:
	// subfic r10,r11,16
	xer.ca = r11.u32 <= 16;
	ctx.r10.s64 = 16 - r11.s64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// slw r10,r7,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r10.u8 & 0x3F));
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// sthx r10,r8,r6
	PPC_STORE_U16(ctx.r8.u32 + ctx.r6.u32, ctx.r10.u16);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// ble cr6,0x82463b88
	if (!cr6.gt) goto loc_82463B88;
loc_82463BAC:
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d9890
	ctx.lr = 0x82463BBC;
	sub_823D9890(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
loc_82463BC4:
	// lbzx r11,r5,r30
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + r30.u32);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82463c18
	if (cr0.eq) goto loc_82463C18;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lhzx r11,r9,r7
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r7.u32);
	// lhzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,128
	cr6.compare<uint32_t>(ctx.r10.u32, 128, xer);
	// bgt cr6,0x82463b3c
	if (cr6.gt) goto loc_82463B3C;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x82463c14
	if (!cr6.lt) goto loc_82463C14;
loc_82463C00:
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stbx r6,r11,r29
	PPC_STORE_U8(r11.u32 + r29.u32, ctx.r6.u8);
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82463c00
	if (cr6.lt) goto loc_82463C00;
loc_82463C14:
	// sthx r10,r9,r7
	PPC_STORE_U16(ctx.r9.u32 + ctx.r7.u32, ctx.r10.u16);
loc_82463C18:
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplwi cr6,r6,8
	cr6.compare<uint32_t>(ctx.r6.u32, 8, xer);
	// blt cr6,0x82463bc4
	if (cr6.lt) goto loc_82463BC4;
	// li r3,1
	ctx.r3.s64 = 1;
loc_82463C30:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82463C38"))) PPC_WEAK_FUNC(sub_82463C38);
PPC_FUNC_IMPL(__imp__sub_82463C38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_82463C50:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// beq cr6,0x82463c74
	if (cr6.eq) goto loc_82463C74;
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82463c50
	if (cr6.lt) goto loc_82463C50;
	// blr 
	return;
loc_82463C74:
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r7,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// stwx r5,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r5.u32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r8.u32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r8,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82463CB0"))) PPC_WEAK_FUNC(sub_82463CB0);
PPC_FUNC_IMPL(__imp__sub_82463CB0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,6448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 6448, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82463CB8"))) PPC_WEAK_FUNC(sub_82463CB8);
PPC_FUNC_IMPL(__imp__sub_82463CB8) {
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// bl 0x824f92f0
	ctx.lr = 0x82463CDC;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8274b3f8
	ctx.lr = 0x82463CEC;
	sub_8274B3F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82463cfc
	if (!cr6.eq) goto loc_82463CFC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82463CFC:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_82463D20"))) PPC_WEAK_FUNC(sub_82463D20);
PPC_FUNC_IMPL(__imp__sub_82463D20) {
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
	ctx.lr = 0x82463D28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x824e6cd8
	ctx.lr = 0x82463D3C;
	sub_824E6CD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82463e14
	if (cr6.eq) goto loc_82463E14;
	// li r30,0
	r30.s64 = 0;
	// li r29,1
	r29.s64 = 1;
loc_82463D50:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6cd8
	ctx.lr = 0x82463D58;
	sub_824E6CD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82463df0
	if (cr6.eq) goto loc_82463DF0;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,252
	ctx.r4.s64 = 252;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82457608
	ctx.lr = 0x82463D78;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82463d88
	if (cr6.eq) goto loc_82463D88;
	// cmplwi cr6,r3,1245
	cr6.compare<uint32_t>(ctx.r3.u32, 1245, xer);
	// bne cr6,0x82463de4
	if (!cr6.eq) goto loc_82463DE4;
loc_82463D88:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82463de4
	if (!cr6.eq) goto loc_82463DE4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,251
	ctx.r4.s64 = 251;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82457608
	ctx.lr = 0x82463DA4;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82463db4
	if (cr6.eq) goto loc_82463DB4;
	// cmplwi cr6,r3,1245
	cr6.compare<uint32_t>(ctx.r3.u32, 1245, xer);
	// bne cr6,0x82463de4
	if (!cr6.eq) goto loc_82463DE4;
loc_82463DB4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82463de4
	if (cr6.eq) goto loc_82463DE4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f92f0
	ctx.lr = 0x82463DC8;
	sub_824F92F0(ctx, base);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82457600
	ctx.lr = 0x82463DE4;
	sub_82457600(ctx, base);
loc_82463DE4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82463df4
	if (!cr6.eq) goto loc_82463DF4;
loc_82463DF0:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82463DF4:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82463d50
	if (cr6.lt) goto loc_82463D50;
	// addi r11,r30,-4
	r11.s64 = r30.s64 + -4;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_82463E14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82463E20"))) PPC_WEAK_FUNC(sub_82463E20);
PPC_FUNC_IMPL(__imp__sub_82463E20) {
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
	// lwz r3,6456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6456);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82463E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r3,-1
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r3,r7,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82463E5C"))) PPC_WEAK_FUNC(sub_82463E5C);
PPC_FUNC_IMPL(__imp__sub_82463E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82463E60"))) PPC_WEAK_FUNC(sub_82463E60);
PPC_FUNC_IMPL(__imp__sub_82463E60) {
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
	ctx.lr = 0x82463E68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,-1
	r27.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,3980(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3980);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82463ebc
	if (!cr6.gt) goto loc_82463EBC;
	// addi r31,r29,3844
	r31.s64 = r29.s64 + 3844;
loc_82463E8C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82502300
	ctx.lr = 0x82463E94;
	sub_82502300(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824f0550
	ctx.lr = 0x82463E9C;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82463ec8
	if (!cr6.eq) goto loc_82463EC8;
	// lwz r11,3980(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3980);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82463e8c
	if (cr6.lt) goto loc_82463E8C;
loc_82463EBC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82463EC8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82463ED4"))) PPC_WEAK_FUNC(sub_82463ED4);
PPC_FUNC_IMPL(__imp__sub_82463ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82463ED8"))) PPC_WEAK_FUNC(sub_82463ED8);
PPC_FUNC_IMPL(__imp__sub_82463ED8) {
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
	ctx.lr = 0x82463EE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,-1
	r27.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,5364(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 5364);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82463f30
	if (!cr6.gt) goto loc_82463F30;
	// addi r31,r29,5228
	r31.s64 = r29.s64 + 5228;
loc_82463F04:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e62e0
	ctx.lr = 0x82463F10;
	sub_824E62E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82463f3c
	if (!cr6.eq) goto loc_82463F3C;
	// lwz r11,5364(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 5364);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82463f04
	if (cr6.lt) goto loc_82463F04;
loc_82463F30:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82463F3C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82463F48"))) PPC_WEAK_FUNC(sub_82463F48);
PPC_FUNC_IMPL(__imp__sub_82463F48) {
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
	// bl 0x82463ed8
	ctx.lr = 0x82463F60;
	sub_82463ED8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82463f88
	if (cr6.lt) goto loc_82463F88;
	// addi r11,r3,1307
	r11.s64 = ctx.r3.s64 + 1307;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82463F88:
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

__attribute__((alias("__imp__sub_82463FA0"))) PPC_WEAK_FUNC(sub_82463FA0);
PPC_FUNC_IMPL(__imp__sub_82463FA0) {
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
	ctx.lr = 0x82463FA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r28,r31,5400
	r28.s64 = r31.s64 + 5400;
	// lwz r11,6408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6408);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// ble cr6,0x82464028
	if (!cr6.gt) goto loc_82464028;
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82464024
	if (!cr6.gt) goto loc_82464024;
	// addi r30,r31,5228
	r30.s64 = r31.s64 + 5228;
loc_82463FD4:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r11,32(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 32);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82464010
	if (!cr6.eq) goto loc_82464010;
	// rlwinm r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464010
	if (cr6.eq) goto loc_82464010;
	// lwz r11,6408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6408);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r5,5384(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 5384);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// lwz r3,5380(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5380);
	// addi r7,r11,-5400
	ctx.r7.s64 = r11.s64 + -5400;
	// bl 0x824ef2a0
	ctx.lr = 0x82464010;
	sub_824EF2A0(ctx, base);
loc_82464010:
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82463fd4
	if (cr6.lt) goto loc_82463FD4;
loc_82464024:
	// stw r28,6408(r31)
	PPC_STORE_U32(r31.u32 + 6408, r28.u32);
loc_82464028:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82464030"))) PPC_WEAK_FUNC(sub_82464030);
PPC_FUNC_IMPL(__imp__sub_82464030) {
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
	ctx.lr = 0x82464038;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x823d9890
	ctx.lr = 0x8246405C;
	sub_823D9890(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r30,r31,6452
	r30.s64 = r31.s64 + 6452;
	// lwz r11,-1840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// addi r5,r31,6456
	ctx.r5.s64 = r31.s64 + 6456;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8274c698
	ctx.lr = 0x824640A0;
	sub_8274C698(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x824640b8
	if (!cr6.eq) goto loc_824640B8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82131e48
	ctx.lr = 0x824640B8;
	sub_82131E48(ctx, base);
loc_824640B8:
	// addi r11,r29,0
	r11.s64 = r29.s64 + 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// stw r10,6412(r31)
	PPC_STORE_U32(r31.u32 + 6412, ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824640D4"))) PPC_WEAK_FUNC(sub_824640D4);
PPC_FUNC_IMPL(__imp__sub_824640D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824640D8"))) PPC_WEAK_FUNC(sub_824640D8);
PPC_FUNC_IMPL(__imp__sub_824640D8) {
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
	ctx.lr = 0x824640E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,-1840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x824e7008
	ctx.lr = 0x82464104;
	sub_824E7008(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82464164
	if (cr6.eq) goto loc_82464164;
	// bl 0x821f8730
	ctx.lr = 0x82464118;
	sub_821F8730(ctx, base);
	// lwz r11,6456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82464138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824641cc
	if (cr6.lt) goto loc_824641CC;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82464160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824641c0
	goto loc_824641C0;
loc_82464164:
	// bl 0x824e7110
	ctx.lr = 0x82464168;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x8246416C;
	sub_824F92F0(ctx, base);
	// lwz r11,6456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82464198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824641cc
	if (cr6.lt) goto loc_824641CC;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824641C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824641C0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bge cr6,0x824641d0
	if (!cr6.lt) goto loc_824641D0;
loc_824641CC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_824641D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824641D8"))) PPC_WEAK_FUNC(sub_824641D8);
PPC_FUNC_IMPL(__imp__sub_824641D8) {
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
	// bl 0x82463e60
	ctx.lr = 0x824641F4;
	sub_82463E60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824642c4
	if (cr6.lt) goto loc_824642C4;
	// addi r11,r3,961
	r11.s64 = ctx.r3.s64 + 961;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r31
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824642c4
	if (cr6.eq) goto loc_824642C4;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-1840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x824e7008
	ctx.lr = 0x82464224;
	sub_824E7008(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8246427c
	if (cr6.eq) goto loc_8246427C;
	// bl 0x821f8730
	ctx.lr = 0x82464238;
	sub_821F8730(ctx, base);
	// lwz r11,6456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82464260;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82464278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824642c4
	goto loc_824642C4;
loc_8246427C:
	// bl 0x824e7110
	ctx.lr = 0x82464280;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x82464284;
	sub_824F92F0(ctx, base);
	// lwz r11,6456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824642AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824642C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824642C4:
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

__attribute__((alias("__imp__sub_824642DC"))) PPC_WEAK_FUNC(sub_824642DC);
PPC_FUNC_IMPL(__imp__sub_824642DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824642E0"))) PPC_WEAK_FUNC(sub_824642E0);
PPC_FUNC_IMPL(__imp__sub_824642E0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7008
	ctx.lr = 0x82464304;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,6456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x82464338
	if (cr6.eq) goto loc_82464338;
	// bl 0x821f8730
	ctx.lr = 0x82464320;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// lwz r10,56(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82464334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82464354
	goto loc_82464354;
loc_82464338:
	// bl 0x824e7110
	ctx.lr = 0x8246433C;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x82464340;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82464354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82464354:
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_82464378"))) PPC_WEAK_FUNC(sub_82464378);
PPC_FUNC_IMPL(__imp__sub_82464378) {
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
	ctx.lr = 0x82464380;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,4
	r25.s64 = 4;
	// addi r26,r30,3984
	r26.s64 = r30.s64 + 3984;
loc_82464390:
	// lwz r27,0(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82464438
	if (cr6.eq) goto loc_82464438;
	// lwz r11,3980(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3980);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82464438
	if (!cr6.gt) goto loc_82464438;
	// addi r29,r30,3844
	r29.s64 = r30.s64 + 3844;
loc_824643B0:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7008
	ctx.lr = 0x824643BC;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82464424
	if (!cr6.eq) goto loc_82464424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7110
	ctx.lr = 0x824643D0;
	sub_824E7110(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,6456(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 6456);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lbz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r9,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// neg r23,r6
	r23.s64 = -ctx.r6.s64;
	// bl 0x821f8730
	ctx.lr = 0x824643FC;
	sub_821F8730(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824f92f0
	ctx.lr = 0x82464408;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,6456(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 6456);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82464424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82464424:
	// lwz r11,3980(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3980);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x824643b0
	if (cr6.lt) goto loc_824643B0;
loc_82464438:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82464390
	if (!cr0.eq) goto loc_82464390;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8246444C"))) PPC_WEAK_FUNC(sub_8246444C);
PPC_FUNC_IMPL(__imp__sub_8246444C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82464450"))) PPC_WEAK_FUNC(sub_82464450);
PPC_FUNC_IMPL(__imp__sub_82464450) {
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
	ctx.lr = 0x82464458;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82464484;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r29,996
	ctx.r9.s64 = r29.s64 + 996;
	// clrlwi r29,r3,28
	r29.u64 = ctx.r3.u32 & 0xF;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82464528
	if (cr6.eq) goto loc_82464528;
	// bl 0x821f8730
	ctx.lr = 0x824644A0;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82464528
	if (cr6.lt) goto loc_82464528;
	// li r11,1
	r11.s64 = 1;
	// slw r10,r11,r4
	ctx.r10.u64 = ctx.r4.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r4.u8 & 0x3F));
	// and r9,r10,r29
	ctx.r9.u64 = ctx.r10.u64 & r29.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82464528
	if (cr6.eq) goto loc_82464528;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824644EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82464508
	if (cr6.lt) goto loc_82464508;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82464508:
	// lis r11,-32768
	r11.s64 = -2147483648;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// ori r10,r11,10
	ctx.r10.u64 = r11.u64 | 10;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x8246452c
	if (cr6.eq) goto loc_8246452C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82464528:
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
loc_8246452C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82464538"))) PPC_WEAK_FUNC(sub_82464538);
PPC_FUNC_IMPL(__imp__sub_82464538) {
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
	ctx.lr = 0x82464540;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lbz r11,6460(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6460);
	// li r26,0
	r26.s64 = 0;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824645c8
	if (!cr6.eq) goto loc_824645C8;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// bl 0x82464030
	ctx.lr = 0x82464574;
	sub_82464030(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824645c8
	if (cr6.eq) goto loc_824645C8;
	// li r11,100
	r11.s64 = 100;
	// stw r30,5368(r31)
	PPC_STORE_U32(r31.u32 + 5368, r30.u32);
	// stw r29,5372(r31)
	PPC_STORE_U32(r31.u32 + 5372, r29.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r28,5380(r31)
	PPC_STORE_U32(r31.u32 + 5380, r28.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r27,5384(r31)
	PPC_STORE_U32(r31.u32 + 5384, r27.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r26,5388(r31)
	PPC_STORE_U32(r31.u32 + 5388, r26.u32);
	// stw r26,5392(r31)
	PPC_STORE_U32(r31.u32 + 5392, r26.u32);
	// stw r11,5396(r31)
	PPC_STORE_U32(r31.u32 + 5396, r11.u32);
	// bl 0x824ec120
	ctx.lr = 0x824645B0;
	sub_824EC120(ctx, base);
	// lbz r10,6460(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 6460);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,6460(r31)
	PPC_STORE_U8(r31.u32 + 6460, ctx.r9.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_824645C8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824645D4"))) PPC_WEAK_FUNC(sub_824645D4);
PPC_FUNC_IMPL(__imp__sub_824645D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824645D8"))) PPC_WEAK_FUNC(sub_824645D8);
PPC_FUNC_IMPL(__imp__sub_824645D8) {
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
	ctx.lr = 0x824645E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,6416
	ctx.r4.s64 = r31.s64 + 6416;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824645FC;
	sub_821C8FE0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x824e7008
	ctx.lr = 0x82464608;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464624
	if (cr6.eq) goto loc_82464624;
	// lwz r11,5368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5368);
	// lwz r10,5376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5376);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82464650
	if (cr6.lt) goto loc_82464650;
loc_82464624:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7060
	ctx.lr = 0x8246462C;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464778
	if (cr6.eq) goto loc_82464778;
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// lwz r10,5376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5376);
	// lwz r9,5372(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 5372);
	// subf r8,r10,r11
	ctx.r8.s64 = r11.s64 - ctx.r10.s64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bge cr6,0x82464778
	if (!cr6.lt) goto loc_82464778;
loc_82464650:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824640d8
	ctx.lr = 0x8246465C;
	sub_824640D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464778
	if (cr6.eq) goto loc_82464778;
	// lwz r30,3840(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 3840);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,104(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// stw r11,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, r11.u32);
	// stw r27,104(r30)
	PPC_STORE_U32(r30.u32 + 104, r27.u32);
	// bl 0x823da950
	ctx.lr = 0x82464688;
	sub_823DA950(ctx, base);
	// lbz r10,108(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 108);
	// stw r27,96(r30)
	PPC_STORE_U32(r30.u32 + 96, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,108(r30)
	PPC_STORE_U8(r30.u32 + 108, ctx.r9.u8);
	// bl 0x824e7008
	ctx.lr = 0x824646A0;
	sub_824E7008(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824646d0
	if (cr6.eq) goto loc_824646D0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821f8730
	ctx.lr = 0x824646B4;
	sub_821F8730(ctx, base);
	// addi r11,r3,996
	r11.s64 = ctx.r3.s64 + 996;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r30.u32);
	// lwz r11,5376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5376);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,5376(r31)
	PPC_STORE_U32(r31.u32 + 5376, ctx.r9.u32);
	// b 0x82464758
	goto loc_82464758;
loc_824646D0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463f48
	ctx.lr = 0x824646DC;
	sub_82463F48(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82464730
	if (!cr6.eq) goto loc_82464730;
	// lwz r3,5224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5224);
	// li r11,1
	r11.s64 = 1;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stw r10,5224(r31)
	PPC_STORE_U32(r31.u32 + 5224, ctx.r10.u32);
	// stw r27,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r27.u32);
	// lbz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 32);
	// rlwimi r9,r11,7,0,25
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0xFFFFFFC0) | (ctx.r9.u64 & 0xFFFFFFFF0000003F);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stb r9,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, ctx.r9.u8);
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// addi r6,r11,1307
	ctx.r6.s64 = r11.s64 + 1307;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r3.u32);
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r4,5364(r31)
	PPC_STORE_U32(r31.u32 + 5364, ctx.r4.u32);
loc_82464730:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bge cr6,0x82464758
	if (!cr6.lt) goto loc_82464758;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, r30.u32);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r3,100(r30)
	PPC_STORE_U32(r30.u32 + 100, ctx.r3.u32);
loc_82464758:
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// li r27,1
	r27.s64 = 1;
	// addi r11,r11,961
	r11.s64 = r11.s64 + 961;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r30.u32);
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,3980(r31)
	PPC_STORE_U32(r31.u32 + 3980, ctx.r9.u32);
loc_82464778:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82464780;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8246478C"))) PPC_WEAK_FUNC(sub_8246478C);
PPC_FUNC_IMPL(__imp__sub_8246478C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82464790"))) PPC_WEAK_FUNC(sub_82464790);
PPC_FUNC_IMPL(__imp__sub_82464790) {
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
	ctx.lr = 0x82464798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,6416
	ctx.r4.s64 = r31.s64 + 6416;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824647B0;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463e60
	ctx.lr = 0x824647BC;
	sub_82463E60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824648f0
	if (cr6.lt) goto loc_824648F0;
	// addi r11,r3,961
	r11.s64 = ctx.r3.s64 + 961;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r29,r30,r31
	r29.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x824641d8
	ctx.lr = 0x824647DC;
	sub_824641D8(ctx, base);
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// li r28,0
	r28.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r10,r11,960
	ctx.r10.s64 = r11.s64 + 960;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stwx r8,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r8.u32);
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// addi r7,r11,960
	ctx.r7.s64 = r11.s64 + 960;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, r28.u32);
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// stw r5,3980(r31)
	PPC_STORE_U32(r31.u32 + 3980, ctx.r5.u32);
	// bl 0x824e7008
	ctx.lr = 0x82464818;
	sub_824E7008(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82464848
	if (cr6.eq) goto loc_82464848;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821f8730
	ctx.lr = 0x8246482C;
	sub_821F8730(ctx, base);
	// addi r11,r3,996
	r11.s64 = ctx.r3.s64 + 996;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r28.u32);
	// lwz r11,5376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5376);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,5376(r31)
	PPC_STORE_U32(r31.u32 + 5376, ctx.r9.u32);
	// b 0x824648cc
	goto loc_824648CC;
loc_82464848:
	// lwz r30,100(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82463c38
	ctx.lr = 0x82464858;
	sub_82463C38(ctx, base);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824648cc
	if (!cr6.eq) goto loc_824648CC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82463ed8
	ctx.lr = 0x82464870;
	sub_82463ED8(ctx, base);
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// addi r10,r3,1307
	ctx.r10.s64 = ctx.r3.s64 + 1307;
	// addi r11,r11,1306
	r11.s64 = r11.s64 + 1306;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stwx r7,r8,r31
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, ctx.r7.u32);
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// addi r6,r11,1306
	ctx.r6.s64 = r11.s64 + 1306;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, r28.u32);
	// lwz r11,5364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5364);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// stw r4,5364(r31)
	PPC_STORE_U32(r31.u32 + 5364, ctx.r4.u32);
	// bl 0x824e6310
	ctx.lr = 0x824648B0;
	sub_824E6310(ctx, base);
	// lbz r11,32(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 32);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r11,r3,7,0,25
	r11.u64 = (__builtin_rotateleft32(ctx.r3.u32, 7) & 0xFFFFFFC0) | (r11.u64 & 0xFFFFFFFF0000003F);
	// stb r11,32(r30)
	PPC_STORE_U8(r30.u32 + 32, r11.u8);
	// lwz r10,5224(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 5224);
	// stw r10,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r10.u32);
	// stw r30,5224(r31)
	PPC_STORE_U32(r31.u32 + 5224, r30.u32);
loc_824648CC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6f20
	ctx.lr = 0x824648D4;
	sub_824E6F20(ctx, base);
	// lbz r11,108(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 108);
	// stw r28,96(r29)
	PPC_STORE_U32(r29.u32 + 96, r28.u32);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,108(r29)
	PPC_STORE_U8(r29.u32 + 108, ctx.r10.u8);
	// lwz r9,3840(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3840);
	// stw r9,104(r29)
	PPC_STORE_U32(r29.u32 + 104, ctx.r9.u32);
	// stw r29,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, r29.u32);
loc_824648F0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824648F8;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82464900"))) PPC_WEAK_FUNC(sub_82464900);
PPC_FUNC_IMPL(__imp__sub_82464900) {
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
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464940
	if (cr6.eq) goto loc_82464940;
loc_82464920:
	// lwz r3,3844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 3844);
	// bl 0x82502300
	ctx.lr = 0x82464928;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82464790
	ctx.lr = 0x82464934;
	sub_82464790(ctx, base);
	// lwz r11,3980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3980);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82464920
	if (!cr6.eq) goto loc_82464920;
loc_82464940:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82464954"))) PPC_WEAK_FUNC(sub_82464954);
PPC_FUNC_IMPL(__imp__sub_82464954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82464958"))) PPC_WEAK_FUNC(sub_82464958);
PPC_FUNC_IMPL(__imp__sub_82464958) {
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
	// bl 0x82463e60
	ctx.lr = 0x82464970;
	sub_82463E60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82464988
	if (cr6.lt) goto loc_82464988;
	// addi r11,r3,961
	r11.s64 = ctx.r3.s64 + 961;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// b 0x8246498c
	goto loc_8246498C;
loc_82464988:
	// li r11,0
	r11.s64 = 0;
loc_8246498C:
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
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

__attribute__((alias("__imp__sub_824649B0"))) PPC_WEAK_FUNC(sub_824649B0);
PPC_FUNC_IMPL(__imp__sub_824649B0) {
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
	// bl 0x82463e60
	ctx.lr = 0x824649C8;
	sub_82463E60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824649fc
	if (cr6.lt) goto loc_824649FC;
	// addi r11,r3,961
	r11.s64 = ctx.r3.s64 + 961;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824649fc
	if (cr6.eq) goto loc_824649FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824642e0
	ctx.lr = 0x824649EC;
	sub_824642E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82464a00
	if (!cr6.eq) goto loc_82464A00;
loc_824649FC:
	// li r11,0
	r11.s64 = 0;
loc_82464A00:
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

__attribute__((alias("__imp__sub_82464A18"))) PPC_WEAK_FUNC(sub_82464A18);
PPC_FUNC_IMPL(__imp__sub_82464A18) {
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
	ctx.lr = 0x82464A20;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// addi r23,r31,3984
	r23.s64 = r31.s64 + 3984;
	// li r22,1006
	r22.s64 = 1006;
loc_82464A34:
	// lwz r25,0(r23)
	r25.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x82464a78
	if (!cr6.eq) goto loc_82464A78;
	// addi r30,r31,5400
	r30.s64 = r31.s64 + 5400;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
loc_82464A48:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82464450
	ctx.lr = 0x82464A5C;
	sub_82464450(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464b58
	if (cr6.eq) goto loc_82464B58;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82464a48
	if (!cr6.eq) goto loc_82464A48;
	// b 0x82464b58
	goto loc_82464B58;
loc_82464A78:
	// li r26,0
	r26.s64 = 0;
loc_82464A7C:
	// lwz r28,6408(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 6408);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// subf r11,r28,r31
	r11.s64 = r31.s64 - r28.s64;
	// addi r30,r11,6406
	r30.s64 = r11.s64 + 6406;
	// bl 0x82502300
	ctx.lr = 0x82464A90;
	sub_82502300(ctx, base);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8252a660
	ctx.lr = 0x82464AA0;
	sub_8252A660(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// add r27,r11,r28
	r27.u64 = r11.u64 + r28.u64;
	// addi r30,r30,-10
	r30.s64 = r30.s64 + -10;
	// addi r9,r27,2
	ctx.r9.s64 = r27.s64 + 2;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,6408(r31)
	PPC_STORE_U32(r31.u32 + 6408, ctx.r9.u32);
	// bne cr6,0x82464b48
	if (!cr6.eq) goto loc_82464B48;
loc_82464AC4:
	// lwz r11,6412(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6412);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82464b28
	if (cr6.lt) goto loc_82464B28;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r5,6408(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 6408);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82464450
	ctx.lr = 0x82464AE8;
	sub_82464450(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464b18
	if (cr6.eq) goto loc_82464B18;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464b18
	if (cr6.eq) goto loc_82464B18;
	// lwz r10,6408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6408);
	// subf r30,r11,r30
	r30.s64 = r30.s64 - r11.s64;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,6408(r31)
	PPC_STORE_U32(r31.u32 + 6408, r11.u32);
	// b 0x82464b1c
	goto loc_82464B1C;
loc_82464B18:
	// li r26,1
	r26.s64 = 1;
loc_82464B1C:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464ac4
	if (cr6.eq) goto loc_82464AC4;
loc_82464B28:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82464b48
	if (cr6.eq) goto loc_82464B48;
	// rlwinm r10,r29,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 24) & 0xFF;
	// stb r29,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r29.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,1(r27)
	PPC_STORE_U8(r27.u32 + 1, ctx.r10.u8);
	// bl 0x82463fa0
	ctx.lr = 0x82464B44;
	sub_82463FA0(ctx, base);
	// b 0x82464b4c
	goto loc_82464B4C;
loc_82464B48:
	// stw r28,6408(r31)
	PPC_STORE_U32(r31.u32 + 6408, r28.u32);
loc_82464B4C:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464a7c
	if (cr6.eq) goto loc_82464A7C;
loc_82464B58:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpwi cr6,r24,4
	cr6.compare<int32_t>(r24.s32, 4, xer);
	// blt cr6,0x82464a34
	if (cr6.lt) goto loc_82464A34;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82464B70"))) PPC_WEAK_FUNC(sub_82464B70);
PPC_FUNC_IMPL(__imp__sub_82464B70) {
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
	ctx.lr = 0x82464B78;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x824f0498
	ctx.lr = 0x82464B90;
	sub_824F0498(ctx, base);
	// add r26,r30,r27
	r26.u64 = r30.u64 + r27.u64;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bge cr6,0x82464c5c
	if (!cr6.lt) goto loc_82464C5C;
	// li r25,1000
	r25.s64 = 1000;
loc_82464BA0:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824f04c8
	ctx.lr = 0x82464BB4;
	sub_824F04C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82464c5c
	if (cr6.eq) goto loc_82464C5C;
	// lwz r10,6412(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6412);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// blt cr6,0x82464c5c
	if (cr6.lt) goto loc_82464C5C;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r11,2
	r30.s64 = r11.s64 + 2;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r29,r8,r9
	r29.u64 = ctx.r8.u64 | ctx.r9.u64;
	// bl 0x82463e60
	ctx.lr = 0x82464BFC;
	sub_82463E60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82464c50
	if (cr6.lt) goto loc_82464C50;
	// addi r11,r3,961
	r11.s64 = ctx.r3.s64 + 961;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82464c50
	if (cr6.eq) goto loc_82464C50;
	// stw r25,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r25.u32);
	// bl 0x824e7110
	ctx.lr = 0x82464C20;
	sub_824E7110(ctx, base);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// lwz r11,6456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// addi r24,r1,84
	r24.s64 = ctx.r1.s64 + 84;
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824f92f0
	ctx.lr = 0x82464C34;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,84(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82464C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82464C50:
	// add r30,r29,r30
	r30.u64 = r29.u64 + r30.u64;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// blt cr6,0x82464ba0
	if (cr6.lt) goto loc_82464BA0;
loc_82464C5C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82464C64"))) PPC_WEAK_FUNC(sub_82464C64);
PPC_FUNC_IMPL(__imp__sub_82464C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82464C68"))) PPC_WEAK_FUNC(sub_82464C68);
PPC_FUNC_IMPL(__imp__sub_82464C68) {
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
	// lbz r11,6460(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6460);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82464d0c
	if (cr6.eq) goto loc_82464D0C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,5380(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5380);
	// bl 0x824ebcc8
	ctx.lr = 0x82464C9C;
	sub_824EBCC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82464900
	ctx.lr = 0x82464CA4;
	sub_82464900(ctx, base);
	// lwz r3,6456(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6456);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82464cc8
	if (cr6.eq) goto loc_82464CC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82464CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,6456(r31)
	PPC_STORE_U32(r31.u32 + 6456, r30.u32);
loc_82464CC8:
	// lbz r11,6460(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6460);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,100
	ctx.r9.s64 = 100;
	// stw r30,5380(r31)
	PPC_STORE_U32(r31.u32 + 5380, r30.u32);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r10,5384(r31)
	PPC_STORE_U32(r31.u32 + 5384, ctx.r10.u32);
	// addi r7,r31,5400
	ctx.r7.s64 = r31.s64 + 5400;
	// stw r30,5388(r31)
	PPC_STORE_U32(r31.u32 + 5388, r30.u32);
	// clrlwi r6,r11,25
	ctx.r6.u64 = r11.u32 & 0x7F;
	// stw r30,5392(r31)
	PPC_STORE_U32(r31.u32 + 5392, r30.u32);
	// stw r9,5396(r31)
	PPC_STORE_U32(r31.u32 + 5396, ctx.r9.u32);
	// stw r30,6412(r31)
	PPC_STORE_U32(r31.u32 + 6412, r30.u32);
	// stw r8,6448(r31)
	PPC_STORE_U32(r31.u32 + 6448, ctx.r8.u32);
	// stw r30,5372(r31)
	PPC_STORE_U32(r31.u32 + 5372, r30.u32);
	// stw r30,5368(r31)
	PPC_STORE_U32(r31.u32 + 5368, r30.u32);
	// stw r7,6408(r31)
	PPC_STORE_U32(r31.u32 + 6408, ctx.r7.u32);
	// stb r6,6460(r31)
	PPC_STORE_U8(r31.u32 + 6460, ctx.r6.u8);
loc_82464D0C:
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

__attribute__((alias("__imp__sub_82464D24"))) PPC_WEAK_FUNC(sub_82464D24);
PPC_FUNC_IMPL(__imp__sub_82464D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82464D28"))) PPC_WEAK_FUNC(sub_82464D28);
PPC_FUNC_IMPL(__imp__sub_82464D28) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82464D30;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x821c9788
	ctx.lr = 0x82464D3C;
	sub_821C9788(ctx, base);
	// lwz r11,5388(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 5388);
	// ori r10,r3,1
	ctx.r10.u64 = ctx.r3.u64 | 1;
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// subf r20,r11,r10
	r20.s64 = ctx.r10.s64 - r11.s64;
	// bne cr6,0x82464d58
	if (!cr6.eq) goto loc_82464D58;
	// mr r20,r22
	r20.u64 = r22.u64;
loc_82464D58:
	// lwz r11,3980(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 3980);
	// mr r29,r22
	r29.u64 = r22.u64;
	// stw r10,5388(r25)
	PPC_STORE_U32(r25.u32 + 5388, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82464dc0
	if (!cr6.gt) goto loc_82464DC0;
	// addi r30,r25,3844
	r30.s64 = r25.s64 + 3844;
loc_82464D70:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82464dac
	if (!cr6.gt) goto loc_82464DAC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824642e0
	ctx.lr = 0x82464D8C;
	sub_824642E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82464da8
	if (!cr6.eq) goto loc_82464DA8;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// subf. r10,r20,r11
	ctx.r10.s64 = r11.s64 - r20.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// bge 0x82464dac
	if (!cr0.lt) goto loc_82464DAC;
loc_82464DA8:
	// stw r22,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r22.u32);
loc_82464DAC:
	// lwz r11,3980(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 3980);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82464d70
	if (cr6.lt) goto loc_82464D70;
loc_82464DC0:
	// addi r23,r25,3984
	r23.s64 = r25.s64 + 3984;
	// li r21,4
	r21.s64 = 4;
	// li r27,1
	r27.s64 = 1;
loc_82464DCC:
	// lwz r24,0(r23)
	r24.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82464ea8
	if (cr6.eq) goto loc_82464EA8;
	// lwz r11,5364(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 5364);
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82464ea8
	if (!cr6.gt) goto loc_82464EA8;
	// addi r28,r25,5228
	r28.s64 = r25.s64 + 5228;
loc_82464DEC:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r30,r22
	r30.u64 = r22.u64;
	// lbz r11,32(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r9,32(r31)
	PPC_STORE_U8(r31.u32 + 32, ctx.r9.u8);
	// ble cr6,0x82464e94
	if (!cr6.gt) goto loc_82464E94;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
loc_82464E14:
	// lbz r11,32(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82464e94
	if (!cr6.eq) goto loc_82464E94;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x824e7110
	ctx.lr = 0x82464E2C;
	sub_824E7110(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821f8730
	ctx.lr = 0x82464E38;
	sub_821F8730(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r19,r1,80
	r19.s64 = ctx.r1.s64 + 80;
	// bl 0x824f92f0
	ctx.lr = 0x82464E48;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// bl 0x8274b3f8
	ctx.lr = 0x82464E58;
	sub_8274B3F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82464e64
	if (cr6.eq) goto loc_82464E64;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
loc_82464E64:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// subf r9,r27,r11
	ctx.r9.s64 = r11.s64 - r27.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwimi r10,r7,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r10,32(r31)
	PPC_STORE_U8(r31.u32 + 32, ctx.r10.u8);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r30,r5
	cr6.compare<int32_t>(r30.s32, ctx.r5.s32, xer);
	// blt cr6,0x82464e14
	if (cr6.lt) goto loc_82464E14;
loc_82464E94:
	// lwz r11,5364(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 5364);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82464dec
	if (cr6.lt) goto loc_82464DEC;
loc_82464EA8:
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// bne 0x82464dcc
	if (!cr0.eq) goto loc_82464DCC;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82464378
	ctx.lr = 0x82464EC0;
	sub_82464378(ctx, base);
	// lwz r11,5392(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 5392);
	// subf. r10,r20,r11
	ctx.r10.s64 = r11.s64 - r20.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,5392(r25)
	PPC_STORE_U32(r25.u32 + 5392, ctx.r10.u32);
	// bge 0x82464ee0
	if (!cr0.lt) goto loc_82464EE0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82464a18
	ctx.lr = 0x82464ED8;
	sub_82464A18(ctx, base);
	// lwz r11,5396(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 5396);
	// stw r11,5392(r25)
	PPC_STORE_U32(r25.u32 + 5392, r11.u32);
loc_82464EE0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82464EE8"))) PPC_WEAK_FUNC(sub_82464EE8);
PPC_FUNC_IMPL(__imp__sub_82464EE8) {
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
	ctx.lr = 0x82464F18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82464f34
	if (!cr6.eq) goto loc_82464F34;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,40(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r4,44(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bl 0x82464b70
	ctx.lr = 0x82464F34;
	sub_82464B70(ctx, base);
loc_82464F34:
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

__attribute__((alias("__imp__sub_82464F4C"))) PPC_WEAK_FUNC(sub_82464F4C);
PPC_FUNC_IMPL(__imp__sub_82464F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82464F50"))) PPC_WEAK_FUNC(sub_82464F50);
PPC_FUNC_IMPL(__imp__sub_82464F50) {
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
	ctx.lr = 0x82464F58;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824ebf78
	ctx.lr = 0x82464F64;
	sub_824EBF78(ctx, base);
	// addi r25,r31,32
	r25.s64 = r31.s64 + 32;
	// li r28,33
	r28.s64 = 33;
	// mr r29,r25
	r29.u64 = r25.u64;
	// li r30,0
	r30.s64 = 0;
loc_82464F74:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e71c8
	ctx.lr = 0x82464F7C;
	sub_824E71C8(ctx, base);
	// lbz r11,108(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 108);
	// stw r30,96(r29)
	PPC_STORE_U32(r29.u32 + 96, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r30,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r30.u32);
	// stw r30,104(r29)
	PPC_STORE_U32(r29.u32 + 104, r30.u32);
	// stb r10,108(r29)
	PPC_STORE_U8(r29.u32 + 108, ctx.r10.u8);
	// addi r29,r29,112
	r29.s64 = r29.s64 + 112;
	// bge 0x82464f74
	if (!cr0.lt) goto loc_82464F74;
	// addi r27,r31,4000
	r27.s64 = r31.s64 + 4000;
	// stw r30,3980(r31)
	PPC_STORE_U32(r31.u32 + 3980, r30.u32);
	// li r28,33
	r28.s64 = 33;
	// stw r30,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, r30.u32);
	// mr r29,r27
	r29.u64 = r27.u64;
	// li r26,1
	r26.s64 = 1;
loc_82464FB8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6310
	ctx.lr = 0x82464FC0;
	sub_824E6310(ctx, base);
	// lbz r11,32(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 32);
	// stw r30,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// rlwimi r11,r26,7,0,25
	r11.u64 = (__builtin_rotateleft32(r26.u32, 7) & 0xFFFFFFC0) | (r11.u64 & 0xFFFFFFFF0000003F);
	// stw r30,28(r29)
	PPC_STORE_U32(r29.u32 + 28, r30.u32);
	// stb r11,32(r29)
	PPC_STORE_U8(r29.u32 + 32, r11.u8);
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r30.u32);
	// stw r30,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r30.u32);
	// addi r29,r29,36
	r29.s64 = r29.s64 + 36;
	// bge 0x82464fb8
	if (!cr0.lt) goto loc_82464FB8;
	// li r11,-1
	r11.s64 = -1;
	// stw r30,5364(r31)
	PPC_STORE_U32(r31.u32 + 5364, r30.u32);
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r30,5224(r31)
	PPC_STORE_U32(r31.u32 + 5224, r30.u32);
	// addi r9,r31,5400
	ctx.r9.s64 = r31.s64 + 5400;
	// stw r30,5368(r31)
	PPC_STORE_U32(r31.u32 + 5368, r30.u32);
	// stw r30,5372(r31)
	PPC_STORE_U32(r31.u32 + 5372, r30.u32);
	// addi r3,r31,6416
	ctx.r3.s64 = r31.s64 + 6416;
	// stw r30,5376(r31)
	PPC_STORE_U32(r31.u32 + 5376, r30.u32);
	// stw r30,5380(r31)
	PPC_STORE_U32(r31.u32 + 5380, r30.u32);
	// stw r11,5384(r31)
	PPC_STORE_U32(r31.u32 + 5384, r11.u32);
	// stw r30,5388(r31)
	PPC_STORE_U32(r31.u32 + 5388, r30.u32);
	// stw r30,5392(r31)
	PPC_STORE_U32(r31.u32 + 5392, r30.u32);
	// stw r10,5396(r31)
	PPC_STORE_U32(r31.u32 + 5396, ctx.r10.u32);
	// stw r9,6408(r31)
	PPC_STORE_U32(r31.u32 + 6408, ctx.r9.u32);
	// stw r30,6412(r31)
	PPC_STORE_U32(r31.u32 + 6412, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x82465034;
	sub_821C8ED8(ctx, base);
	// lbz r8,6460(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 6460);
	// li r29,8
	r29.s64 = 8;
	// clrlwi r7,r8,25
	ctx.r7.u64 = ctx.r8.u32 & 0x7F;
	// stw r29,6448(r31)
	PPC_STORE_U32(r31.u32 + 6448, r29.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stb r7,6460(r31)
	PPC_STORE_U8(r31.u32 + 6460, ctx.r7.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3984
	ctx.r3.s64 = r31.s64 + 3984;
	// bl 0x8244d150
	ctx.lr = 0x82465058;
	sub_8244D150(ctx, base);
	// lis r6,-32186
	ctx.r6.s64 = -2109341696;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,20200
	ctx.r5.s64 = ctx.r6.s64 + 20200;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x82465070;
	sub_82130000(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r9,r31,5228
	ctx.r9.s64 = r31.s64 + 5228;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// li r8,34
	ctx.r8.s64 = 34;
loc_82465084:
	// lwz r7,3840(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 3840);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r7,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r7.u32);
	// stw r11,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, r11.u32);
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
	// stw r30,-1384(r9)
	PPC_STORE_U32(ctx.r9.u32 + -1384, r30.u32);
	// lwz r6,5224(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 5224);
	// stw r6,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r6.u32);
	// stw r10,5224(r31)
	PPC_STORE_U32(r31.u32 + 5224, ctx.r10.u32);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// stw r30,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r30.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82465084
	if (!cr0.eq) goto loc_82465084;
	// stw r29,6448(r31)
	PPC_STORE_U32(r31.u32 + 6448, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,6452(r31)
	PPC_STORE_U32(r31.u32 + 6452, r30.u32);
	// stw r30,6456(r31)
	PPC_STORE_U32(r31.u32 + 6456, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824650D0"))) PPC_WEAK_FUNC(sub_824650D0);
PPC_FUNC_IMPL(__imp__sub_824650D0) {
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
	// bl 0x82464c68
	ctx.lr = 0x824650E8;
	sub_82464C68(ctx, base);
	// addi r3,r31,6416
	ctx.r3.s64 = r31.s64 + 6416;
	// bl 0x82130000
	ctx.lr = 0x824650F0;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x824650F8;
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
}

__attribute__((alias("__imp__sub_8246510C"))) PPC_WEAK_FUNC(sub_8246510C);
PPC_FUNC_IMPL(__imp__sub_8246510C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465110"))) PPC_WEAK_FUNC(sub_82465110);
PPC_FUNC_IMPL(__imp__sub_82465110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// stb r11,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, r11.u8);
	// stb r11,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465124"))) PPC_WEAK_FUNC(sub_82465124);
PPC_FUNC_IMPL(__imp__sub_82465124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465128"))) PPC_WEAK_FUNC(sub_82465128);
PPC_FUNC_IMPL(__imp__sub_82465128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// stb r11,14564(r10)
	PPC_STORE_U8(ctx.r10.u32 + 14564, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465138"))) PPC_WEAK_FUNC(sub_82465138);
PPC_FUNC_IMPL(__imp__sub_82465138) {
	PPC_FUNC_PROLOGUE();
	// b 0x82465e28
	sub_82465E28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8246513C"))) PPC_WEAK_FUNC(sub_8246513C);
PPC_FUNC_IMPL(__imp__sub_8246513C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465140"))) PPC_WEAK_FUNC(sub_82465140);
PPC_FUNC_IMPL(__imp__sub_82465140) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,14564(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 14564);
	// stb r10,15140(r9)
	PPC_STORE_U8(ctx.r9.u32 + 15140, ctx.r10.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82465180
	if (!cr6.eq) goto loc_82465180;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-22304
	ctx.r3.s64 = r11.s64 + -22304;
	// bl 0x821bd618
	ctx.lr = 0x8246517C;
	sub_821BD618(ctx, base);
	// b 0x824651cc
	goto loc_824651CC;
loc_82465180:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82465188;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465198
	if (cr6.eq) goto loc_82465198;
	// bl 0x82465630
	ctx.lr = 0x82465194;
	sub_82465630(ctx, base);
	// b 0x8246519c
	goto loc_8246519C;
loc_82465198:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8246519C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r30,r11,14560
	r30.s64 = r11.s64 + 14560;
	// stw r3,14560(r11)
	PPC_STORE_U32(r11.u32 + 14560, ctx.r3.u32);
	// bl 0x824656c8
	ctx.lr = 0x824651AC;
	sub_824656C8(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_824651B0:
	// li r5,15
	ctx.r5.s64 = 15;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824658d8
	ctx.lr = 0x824651C0;
	sub_824658D8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x824651b0
	if (cr6.lt) goto loc_824651B0;
loc_824651CC:
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

__attribute__((alias("__imp__sub_824651E4"))) PPC_WEAK_FUNC(sub_824651E4);
PPC_FUNC_IMPL(__imp__sub_824651E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824651E8"))) PPC_WEAK_FUNC(sub_824651E8);
PPC_FUNC_IMPL(__imp__sub_824651E8) {
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
	ctx.lr = 0x824651F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// bl 0x824656d0
	ctx.lr = 0x82465208;
	sub_824656D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82465220
	if (!cr6.eq) goto loc_82465220;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82465220:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// stw r10,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r10.u32);
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// bl 0x82465728
	ctx.lr = 0x82465240;
	sub_82465728(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82465250:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x82465250
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82465250;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// addi r26,r10,15272
	r26.s64 = ctx.r10.s64 + 15272;
	// addi r28,r11,15144
	r28.s64 = r11.s64 + 15144;
loc_82465284:
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// ldx r5,r30,r28
	ctx.r5.u64 = PPC_LOAD_U64(r30.u32 + r28.u32);
	// bl 0x82465808
	ctx.lr = 0x82465294;
	sub_82465808(ctx, base);
	// stb r3,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r3.u8);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// ldx r5,r30,r28
	ctx.r5.u64 = PPC_LOAD_U64(r30.u32 + r28.u32);
	// bl 0x82465768
	ctx.lr = 0x824652A8;
	sub_82465768(ctx, base);
	// stb r3,1(r29)
	PPC_STORE_U8(r29.u32 + 1, ctx.r3.u8);
	// ldx r5,r30,r28
	ctx.r5.u64 = PPC_LOAD_U64(r30.u32 + r28.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,14560(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 14560);
	// bl 0x824657b8
	ctx.lr = 0x824652BC;
	sub_824657B8(ctx, base);
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// stb r3,2(r29)
	PPC_STORE_U8(r29.u32 + 2, ctx.r3.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824652dc
	if (cr6.eq) goto loc_824652DC;
	// ldx r9,r30,r28
	ctx.r9.u64 = PPC_LOAD_U64(r30.u32 + r28.u32);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r8.u32);
loc_824652DC:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824652f8
	if (cr6.eq) goto loc_824652F8;
	// ldx r9,r30,r26
	ctx.r9.u64 = PPC_LOAD_U64(r30.u32 + r26.u32);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r8.u32);
loc_824652F8:
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// addi r29,r29,3
	r29.s64 = r29.s64 + 3;
	// cmpwi cr6,r30,128
	cr6.compare<int32_t>(r30.s32, 128, xer);
	// blt cr6,0x82465284
	if (cr6.lt) goto loc_82465284;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// extsh r9,r11
	ctx.r9.s64 = r11.s16;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82465328"))) PPC_WEAK_FUNC(sub_82465328);
PPC_FUNC_IMPL(__imp__sub_82465328) {
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
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,14560(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 14560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465398
	if (cr6.eq) goto loc_82465398;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x824656d0
	ctx.lr = 0x82465358;
	sub_824656D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82465398
	if (cr6.eq) goto loc_82465398;
	// lwz r3,14560(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 14560);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821a5cc0
	ctx.lr = 0x82465370;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82465398
	if (cr6.eq) goto loc_82465398;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f0,-22228(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22228);
	f0.f64 = double(temp.f32);
	// b 0x824653b0
	goto loc_824653B0;
loc_82465398:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfs f0,-22232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22232);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_824653B0:
	// fcfid f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f13,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f12,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f1,f9,f13,f10
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
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

__attribute__((alias("__imp__sub_824653FC"))) PPC_WEAK_FUNC(sub_824653FC);
PPC_FUNC_IMPL(__imp__sub_824653FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465400"))) PPC_WEAK_FUNC(sub_82465400);
PPC_FUNC_IMPL(__imp__sub_82465400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,22(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 22);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f12,-22224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	ctx.f12.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f0,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsel f8,f9,f10,f0
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f1,f7,f13,f8
	ctx.f1.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f8.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465448"))) PPC_WEAK_FUNC(sub_82465448);
PPC_FUNC_IMPL(__imp__sub_82465448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,24(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f12,-22224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22224);
	ctx.f12.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f0,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsel f8,f9,f10,f0
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f1,f7,f13,f8
	ctx.f1.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f8.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465490"))) PPC_WEAK_FUNC(sub_82465490);
PPC_FUNC_IMPL(__imp__sub_82465490) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,14560(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 14560);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824656d0
	ctx.lr = 0x824654BC;
	sub_824656D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82465534
	if (cr6.eq) goto loc_82465534;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465cb8
	ctx.lr = 0x824654D4;
	sub_82465CB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465c08
	ctx.lr = 0x824654E0;
	sub_82465C08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465cf0
	ctx.lr = 0x824654EC;
	sub_82465CF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465d28
	ctx.lr = 0x824654F8;
	sub_82465D28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465d98
	ctx.lr = 0x82465504;
	sub_82465D98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465a30
	ctx.lr = 0x82465510;
	sub_82465A30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82465ae0
	ctx.lr = 0x8246551C;
	sub_82465AE0(ctx, base);
	// li r7,70
	ctx.r7.s64 = 70;
	// li r6,70
	ctx.r6.s64 = 70;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82465918
	ctx.lr = 0x82465534;
	sub_82465918(ctx, base);
loc_82465534:
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

__attribute__((alias("__imp__sub_8246554C"))) PPC_WEAK_FUNC(sub_8246554C);
PPC_FUNC_IMPL(__imp__sub_8246554C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465550"))) PPC_WEAK_FUNC(sub_82465550);
PPC_FUNC_IMPL(__imp__sub_82465550) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r30,14560(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 14560);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82465584
	if (cr6.eq) goto loc_82465584;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82465690
	ctx.lr = 0x8246557C;
	sub_82465690(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82465584;
	sub_82130588(ctx, base);
loc_82465584:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,14560(r31)
	PPC_STORE_U32(r31.u32 + 14560, r11.u32);
	// stb r10,14564(r9)
	PPC_STORE_U8(ctx.r9.u32 + 14564, ctx.r10.u8);
	// bl 0x82465e58
	ctx.lr = 0x8246559C;
	sub_82465E58(ctx, base);
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

__attribute__((alias("__imp__sub_824655B4"))) PPC_WEAK_FUNC(sub_824655B4);
PPC_FUNC_IMPL(__imp__sub_824655B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824655B8"))) PPC_WEAK_FUNC(sub_824655B8);
PPC_FUNC_IMPL(__imp__sub_824655B8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r10,14564(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14564);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82465618
	if (cr6.eq) goto loc_82465618;
	// bl 0x824661e0
	ctx.lr = 0x824655E0;
	sub_824661E0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,14560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 14560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824655f4
	if (cr6.eq) goto loc_824655F4;
	// bl 0x824656c8
	ctx.lr = 0x824655F4;
	sub_824656C8(ctx, base);
loc_824655F4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r30,r11,14576
	r30.s64 = r11.s64 + 14576;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_82465600:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824651e8
	ctx.lr = 0x82465608;
	sub_824651E8(ctx, base);
	// addi r31,r31,120
	r31.s64 = r31.s64 + 120;
	// addi r11,r30,480
	r11.s64 = r30.s64 + 480;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82465600
	if (cr6.lt) goto loc_82465600;
loc_82465618:
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

__attribute__((alias("__imp__sub_82465630"))) PPC_WEAK_FUNC(sub_82465630);
PPC_FUNC_IMPL(__imp__sub_82465630) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82466b48
	ctx.lr = 0x82465648;
	sub_82466B48(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,0
	r11.s64 = 0;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82466aa0
	ctx.lr = 0x82465674;
	sub_82466AA0(ctx, base);
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

__attribute__((alias("__imp__sub_8246568C"))) PPC_WEAK_FUNC(sub_8246568C);
PPC_FUNC_IMPL(__imp__sub_8246568C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465690"))) PPC_WEAK_FUNC(sub_82465690);
PPC_FUNC_IMPL(__imp__sub_82465690) {
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
	// bl 0x82465e58
	ctx.lr = 0x824656A8;
	sub_82465E58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82466be0
	ctx.lr = 0x824656B0;
	sub_82466BE0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824656C4"))) PPC_WEAK_FUNC(sub_824656C4);
PPC_FUNC_IMPL(__imp__sub_824656C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824656C8"))) PPC_WEAK_FUNC(sub_824656C8);
PPC_FUNC_IMPL(__imp__sub_824656C8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82466d20
	sub_82466D20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824656CC"))) PPC_WEAK_FUNC(sub_824656CC);
PPC_FUNC_IMPL(__imp__sub_824656CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824656D0"))) PPC_WEAK_FUNC(sub_824656D0);
PPC_FUNC_IMPL(__imp__sub_824656D0) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82465710
	if (cr6.lt) goto loc_82465710;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// bge cr6,0x82465710
	if (!cr6.lt) goto loc_82465710;
	// bl 0x82466b38
	ctx.lr = 0x824656F0;
	sub_82466B38(ctx, base);
	// addi r11,r3,0
	r11.s64 = ctx.r3.s64 + 0;
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
loc_82465710:
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

__attribute__((alias("__imp__sub_82465724"))) PPC_WEAK_FUNC(sub_82465724);
PPC_FUNC_IMPL(__imp__sub_82465724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465728"))) PPC_WEAK_FUNC(sub_82465728);
PPC_FUNC_IMPL(__imp__sub_82465728) {
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
	// bl 0x82466b38
	ctx.lr = 0x82465738;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82465750
	if (!cr6.eq) goto loc_82465750;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82465750:
	// bl 0x82466e80
	ctx.lr = 0x82465754;
	sub_82466E80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465764"))) PPC_WEAK_FUNC(sub_82465764);
PPC_FUNC_IMPL(__imp__sub_82465764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465768"))) PPC_WEAK_FUNC(sub_82465768);
PPC_FUNC_IMPL(__imp__sub_82465768) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465780;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8246579c
	if (!cr6.eq) goto loc_8246579C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8246579C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82466f80
	ctx.lr = 0x824657A4;
	sub_82466F80(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824657B8"))) PPC_WEAK_FUNC(sub_824657B8);
PPC_FUNC_IMPL(__imp__sub_824657B8) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x824657D0;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824657ec
	if (!cr6.eq) goto loc_824657EC;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824657EC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82467158
	ctx.lr = 0x824657F4;
	sub_82467158(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82465808"))) PPC_WEAK_FUNC(sub_82465808);
PPC_FUNC_IMPL(__imp__sub_82465808) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465820;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8246583c
	if (!cr6.eq) goto loc_8246583C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8246583C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82467310
	ctx.lr = 0x82465844;
	sub_82467310(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82465858"))) PPC_WEAK_FUNC(sub_82465858);
PPC_FUNC_IMPL(__imp__sub_82465858) {
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
	// bl 0x82466b38
	ctx.lr = 0x82465868;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82465880
	if (!cr6.eq) goto loc_82465880;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82465880:
	// bl 0x823b20c0
	ctx.lr = 0x82465884;
	sub_823B20C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465894"))) PPC_WEAK_FUNC(sub_82465894);
PPC_FUNC_IMPL(__imp__sub_82465894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465898"))) PPC_WEAK_FUNC(sub_82465898);
PPC_FUNC_IMPL(__imp__sub_82465898) {
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
	// bl 0x82466b38
	ctx.lr = 0x824658A8;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824658c0
	if (!cr6.eq) goto loc_824658C0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824658C0:
	// bl 0x823b20d8
	ctx.lr = 0x824658C4;
	sub_823B20D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824658D4"))) PPC_WEAK_FUNC(sub_824658D4);
PPC_FUNC_IMPL(__imp__sub_824658D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824658D8"))) PPC_WEAK_FUNC(sub_824658D8);
PPC_FUNC_IMPL(__imp__sub_824658D8) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x824658F0;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465900
	if (cr6.eq) goto loc_82465900;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82467488
	ctx.lr = 0x82465900;
	sub_82467488(ctx, base);
loc_82465900:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82465914"))) PPC_WEAK_FUNC(sub_82465914);
PPC_FUNC_IMPL(__imp__sub_82465914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465918"))) PPC_WEAK_FUNC(sub_82465918);
PPC_FUNC_IMPL(__imp__sub_82465918) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82465920;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465934;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824659ac
	if (cr6.eq) goto loc_824659AC;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x824659ac
	if (cr0.eq) goto loc_824659AC;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// extsw r10,r30
	ctx.r10.s64 = r30.s32;
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	f0.f64 = double(temp.f32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fctiwz f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// fctiwz f6,f8
	ctx.f6.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82467ba0
	ctx.lr = 0x824659AC;
	sub_82467BA0(ctx, base);
loc_824659AC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824659B4"))) PPC_WEAK_FUNC(sub_824659B4);
PPC_FUNC_IMPL(__imp__sub_824659B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824659B8"))) PPC_WEAK_FUNC(sub_824659B8);
PPC_FUNC_IMPL(__imp__sub_824659B8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x824659D0;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465a1c
	if (cr6.eq) goto loc_82465A1C;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465a1c
	if (cr0.eq) goto loc_82465A1C;
	// extsw r11,r31
	r11.s64 = r31.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82467cb0
	ctx.lr = 0x82465A1C;
	sub_82467CB0(ctx, base);
loc_82465A1C:
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

__attribute__((alias("__imp__sub_82465A30"))) PPC_WEAK_FUNC(sub_82465A30);
PPC_FUNC_IMPL(__imp__sub_82465A30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465A40;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465a54
	if (cr6.eq) goto loc_82465A54;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465a54
	if (cr0.eq) goto loc_82465A54;
	// bl 0x82467700
	ctx.lr = 0x82465A54;
	sub_82467700(ctx, base);
loc_82465A54:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465A64"))) PPC_WEAK_FUNC(sub_82465A64);
PPC_FUNC_IMPL(__imp__sub_82465A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465A68"))) PPC_WEAK_FUNC(sub_82465A68);
PPC_FUNC_IMPL(__imp__sub_82465A68) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465A80;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465ac8
	if (cr6.eq) goto loc_82465AC8;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465ac8
	if (cr0.eq) goto loc_82465AC8;
	// extsw r11,r31
	r11.s64 = r31.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82467d58
	ctx.lr = 0x82465AC8;
	sub_82467D58(ctx, base);
loc_82465AC8:
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

__attribute__((alias("__imp__sub_82465ADC"))) PPC_WEAK_FUNC(sub_82465ADC);
PPC_FUNC_IMPL(__imp__sub_82465ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465AE0"))) PPC_WEAK_FUNC(sub_82465AE0);
PPC_FUNC_IMPL(__imp__sub_82465AE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465AF0;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465b04
	if (cr6.eq) goto loc_82465B04;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465b04
	if (cr0.eq) goto loc_82465B04;
	// bl 0x82467710
	ctx.lr = 0x82465B04;
	sub_82467710(ctx, base);
loc_82465B04:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465B14"))) PPC_WEAK_FUNC(sub_82465B14);
PPC_FUNC_IMPL(__imp__sub_82465B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465B18"))) PPC_WEAK_FUNC(sub_82465B18);
PPC_FUNC_IMPL(__imp__sub_82465B18) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465B30;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465b78
	if (cr6.eq) goto loc_82465B78;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465b78
	if (cr0.eq) goto loc_82465B78;
	// extsw r11,r31
	r11.s64 = r31.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82467e40
	ctx.lr = 0x82465B78;
	sub_82467E40(ctx, base);
loc_82465B78:
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

__attribute__((alias("__imp__sub_82465B8C"))) PPC_WEAK_FUNC(sub_82465B8C);
PPC_FUNC_IMPL(__imp__sub_82465B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465B90"))) PPC_WEAK_FUNC(sub_82465B90);
PPC_FUNC_IMPL(__imp__sub_82465B90) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465BA8;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465bf0
	if (cr6.eq) goto loc_82465BF0;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465bf0
	if (cr0.eq) goto loc_82465BF0;
	// extsw r11,r31
	r11.s64 = r31.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82467ee0
	ctx.lr = 0x82465BF0;
	sub_82467EE0(ctx, base);
loc_82465BF0:
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

__attribute__((alias("__imp__sub_82465C04"))) PPC_WEAK_FUNC(sub_82465C04);
PPC_FUNC_IMPL(__imp__sub_82465C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465C08"))) PPC_WEAK_FUNC(sub_82465C08);
PPC_FUNC_IMPL(__imp__sub_82465C08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465C18;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465c2c
	if (cr6.eq) goto loc_82465C2C;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465c2c
	if (cr0.eq) goto loc_82465C2C;
	// bl 0x82467730
	ctx.lr = 0x82465C2C;
	sub_82467730(ctx, base);
loc_82465C2C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465C3C"))) PPC_WEAK_FUNC(sub_82465C3C);
PPC_FUNC_IMPL(__imp__sub_82465C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465C40"))) PPC_WEAK_FUNC(sub_82465C40);
PPC_FUNC_IMPL(__imp__sub_82465C40) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465C58;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465ca0
	if (cr6.eq) goto loc_82465CA0;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465ca0
	if (cr0.eq) goto loc_82465CA0;
	// extsw r11,r31
	r11.s64 = r31.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82467f90
	ctx.lr = 0x82465CA0;
	sub_82467F90(ctx, base);
loc_82465CA0:
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

__attribute__((alias("__imp__sub_82465CB4"))) PPC_WEAK_FUNC(sub_82465CB4);
PPC_FUNC_IMPL(__imp__sub_82465CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465CB8"))) PPC_WEAK_FUNC(sub_82465CB8);
PPC_FUNC_IMPL(__imp__sub_82465CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465CC8;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465cdc
	if (cr6.eq) goto loc_82465CDC;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465cdc
	if (cr0.eq) goto loc_82465CDC;
	// bl 0x82467750
	ctx.lr = 0x82465CDC;
	sub_82467750(ctx, base);
loc_82465CDC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465CEC"))) PPC_WEAK_FUNC(sub_82465CEC);
PPC_FUNC_IMPL(__imp__sub_82465CEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465CF0"))) PPC_WEAK_FUNC(sub_82465CF0);
PPC_FUNC_IMPL(__imp__sub_82465CF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465D00;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465d14
	if (cr6.eq) goto loc_82465D14;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465d14
	if (cr0.eq) goto loc_82465D14;
	// bl 0x82467770
	ctx.lr = 0x82465D14;
	sub_82467770(ctx, base);
loc_82465D14:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465D24"))) PPC_WEAK_FUNC(sub_82465D24);
PPC_FUNC_IMPL(__imp__sub_82465D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465D28"))) PPC_WEAK_FUNC(sub_82465D28);
PPC_FUNC_IMPL(__imp__sub_82465D28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465D38;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465d4c
	if (cr6.eq) goto loc_82465D4C;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465d4c
	if (cr0.eq) goto loc_82465D4C;
	// bl 0x824677f0
	ctx.lr = 0x82465D4C;
	sub_824677F0(ctx, base);
loc_82465D4C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465D5C"))) PPC_WEAK_FUNC(sub_82465D5C);
PPC_FUNC_IMPL(__imp__sub_82465D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465D60"))) PPC_WEAK_FUNC(sub_82465D60);
PPC_FUNC_IMPL(__imp__sub_82465D60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465D70;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465d84
	if (cr6.eq) goto loc_82465D84;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465d84
	if (cr0.eq) goto loc_82465D84;
	// bl 0x82467810
	ctx.lr = 0x82465D84;
	sub_82467810(ctx, base);
loc_82465D84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465D94"))) PPC_WEAK_FUNC(sub_82465D94);
PPC_FUNC_IMPL(__imp__sub_82465D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465D98"))) PPC_WEAK_FUNC(sub_82465D98);
PPC_FUNC_IMPL(__imp__sub_82465D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x82466b38
	ctx.lr = 0x82465DA8;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82465dbc
	if (cr6.eq) goto loc_82465DBC;
	// addic. r3,r3,4208
	xer.ca = ctx.r3.u32 > 4294963087;
	ctx.r3.s64 = ctx.r3.s64 + 4208;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82465dbc
	if (cr0.eq) goto loc_82465DBC;
	// bl 0x82467880
	ctx.lr = 0x82465DBC;
	sub_82467880(ctx, base);
loc_82465DBC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465DCC"))) PPC_WEAK_FUNC(sub_82465DCC);
PPC_FUNC_IMPL(__imp__sub_82465DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465DD0"))) PPC_WEAK_FUNC(sub_82465DD0);
PPC_FUNC_IMPL(__imp__sub_82465DD0) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82466b38
	ctx.lr = 0x82465DE8;
	sub_82466B38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82465e08
	if (!cr6.eq) goto loc_82465E08;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82465E08:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82466f00
	ctx.lr = 0x82465E10;
	sub_82466F00(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82465E24"))) PPC_WEAK_FUNC(sub_82465E24);
PPC_FUNC_IMPL(__imp__sub_82465E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465E28"))) PPC_WEAK_FUNC(sub_82465E28);
PPC_FUNC_IMPL(__imp__sub_82465E28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lbz r9,16104(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 16104);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82465e44
	if (cr6.eq) goto loc_82465E44;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// blr 
	return;
loc_82465E44:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,15408(r11)
	PPC_STORE_U32(r11.u32 + 15408, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465E54"))) PPC_WEAK_FUNC(sub_82465E54);
PPC_FUNC_IMPL(__imp__sub_82465E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465E58"))) PPC_WEAK_FUNC(sub_82465E58);
PPC_FUNC_IMPL(__imp__sub_82465E58) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// addi r30,r31,16105
	r30.s64 = r31.s64 + 16105;
	// lwz r3,-1029(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -1029);
	// bl 0x8244eee0
	ctx.lr = 0x82465E7C;
	sub_8244EEE0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-1029(r30)
	PPC_STORE_U32(r30.u32 + -1029, r11.u32);
	// stb r10,-1(r30)
	PPC_STORE_U8(r30.u32 + -1, ctx.r10.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r9,16105(r31)
	PPC_STORE_U8(r31.u32 + 16105, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_82465EB0"))) PPC_WEAK_FUNC(sub_82465EB0);
PPC_FUNC_IMPL(__imp__sub_82465EB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r11,16105
	r11.s64 = r11.s64 + 16105;
	// lbz r9,-1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82465ed0
	if (!cr6.eq) goto loc_82465ED0;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// blr 
	return;
loc_82465ED0:
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82465EEC"))) PPC_WEAK_FUNC(sub_82465EEC);
PPC_FUNC_IMPL(__imp__sub_82465EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82465EF0"))) PPC_WEAK_FUNC(sub_82465EF0);
PPC_FUNC_IMPL(__imp__sub_82465EF0) {
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
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x8275cb78
	ctx.lr = 0x82465F0C;
	sub_8275CB78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82465f58
	if (!cr6.eq) goto loc_82465F58;
	// lbz r11,86(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r10,87(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// lhz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// rotlwi r9,r11,7
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 7);
	// rotlwi r7,r10,7
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 7);
	// rotlwi r6,r10,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// subf r5,r7,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r7.s64;
	// rotlwi r4,r11,8
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 8);
	// sth r6,14(r31)
	PPC_STORE_U16(r31.u32 + 14, ctx.r6.u16);
	// sth r8,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r8.u16);
	// sth r4,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r4.u16);
	// sth r5,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r5.u16);
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
loc_82465F58:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
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

__attribute__((alias("__imp__sub_82465F70"))) PPC_WEAK_FUNC(sub_82465F70);
PPC_FUNC_IMPL(__imp__sub_82465F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82465F78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r5,116
	ctx.r5.s64 = 116;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x82465F98;
	sub_823D9890(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82466034
	if (cr6.gt) goto loc_82466034;
	// lis r12,-32186
	r12.s64 = -2109341696;
	// addi r12,r12,24520
	r12.s64 = r12.s64 + 24520;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82465FEC;
	case 1:
		goto loc_82465FF4;
	case 2:
		goto loc_82465FFC;
	case 3:
		goto loc_82466004;
	case 4:
		goto loc_8246600C;
	case 5:
		goto loc_82466014;
	case 6:
		goto loc_8246601C;
	case 7:
		goto loc_82466024;
	case 8:
		goto loc_8246602C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,24556(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24556);
	// lwz r18,24564(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24564);
	// lwz r18,24572(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24572);
	// lwz r18,24580(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24580);
	// lwz r18,24588(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24588);
	// lwz r18,24596(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24596);
	// lwz r18,24604(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24604);
	// lwz r18,24612(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24612);
	// lwz r18,24620(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24620);
loc_82465FEC:
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// b 0x82466034
	goto loc_82466034;
loc_82465FF4:
	// li r11,2
	r11.s64 = 2;
	// b 0x82466030
	goto loc_82466030;
loc_82465FFC:
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// b 0x82466034
	goto loc_82466034;
loc_82466004:
	// li r11,3
	r11.s64 = 3;
	// b 0x82466030
	goto loc_82466030;
loc_8246600C:
	// li r11,5
	r11.s64 = 5;
	// b 0x82466030
	goto loc_82466030;
loc_82466014:
	// li r11,6
	r11.s64 = 6;
	// b 0x82466030
	goto loc_82466030;
loc_8246601C:
	// li r11,7
	r11.s64 = 7;
	// b 0x82466030
	goto loc_82466030;
loc_82466024:
	// li r11,8
	r11.s64 = 8;
	// b 0x82466030
	goto loc_82466030;
loc_8246602C:
	// li r11,9
	r11.s64 = 9;
loc_82466030:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82466034:
	// li r11,255
	r11.s64 = 255;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// std r10,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r10.u64);
	// std r10,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r10.u64);
	// bgt cr6,0x824661b8
	if (cr6.gt) goto loc_824661B8;
	// lis r12,-32186
	r12.s64 = -2109341696;
	// addi r12,r12,24712
	r12.s64 = r12.s64 + 24712;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824660AC;
	case 1:
		goto loc_824660E8;
	case 2:
		goto loc_82466104;
	case 3:
		goto loc_82466104;
	case 4:
		goto loc_82466104;
	case 5:
		goto loc_82466104;
	case 6:
		goto loc_82466104;
	case 7:
		goto loc_8246615C;
	case 8:
		goto loc_8246615C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,24748(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24748);
	// lwz r18,24808(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24808);
	// lwz r18,24836(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24836);
	// lwz r18,24836(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24836);
	// lwz r18,24836(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24836);
	// lwz r18,24836(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24836);
	// lwz r18,24836(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24836);
	// lwz r18,24924(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24924);
	// lwz r18,24924(r6)
	r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24924);
loc_824660AC:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r8,r30,20
	ctx.r8.s64 = r30.s64 + 20;
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// srawi r6,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r6.s64 = r11.s32 >> 1;
	// lwz r5,28(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// neg r3,r6
	ctx.r3.s64 = -ctx.r6.s64;
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// stw r4,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r4.u32);
	// b 0x824661b8
	goto loc_824661B8;
loc_824660E8:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// srawi r8,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// b 0x824661b8
	goto loc_824661B8;
loc_82466104:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r8,r30,32
	ctx.r8.s64 = r30.s64 + 32;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r5,40(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// lwz r4,44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// stw r7,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r7.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// stw r4,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r4.u32);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// srawi r11,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r11.s64 = ctx.r3.s32 >> 1;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r7,r8,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r7,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r7.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// b 0x824661b8
	goto loc_824661B8;
loc_8246615C:
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// addi r10,r30,32
	ctx.r10.s64 = r30.s64 + 32;
	// li r9,2
	ctx.r9.s64 = 2;
loc_82466168:
	// lwz r8,-20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -20);
	// srawi r7,r8,8
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 8;
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// srawi r5,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// srawi r3,r4,1
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,-8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r7,-12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
	// lwz r6,-16(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	// rlwinm r5,r6,24,8,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFFFFFF;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bne 0x82466168
	if (!cr0.eq) goto loc_82466168;
loc_824661B8:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r9.u32);
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824661E0"))) PPC_WEAK_FUNC(sub_824661E0);
PPC_FUNC_IMPL(__imp__sub_824661E0) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r31,r11,16105
	r31.s64 = r11.s64 + 16105;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-1029(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -1029);
	// bl 0x827bd054
	ctx.lr = 0x82466218;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82466260
	if (cr6.eq) goto loc_82466260;
	// lis r11,1
	r11.s64 = 65536;
	// ori r30,r11,19
	r30.u64 = r11.u64 | 19;
loc_82466228:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// beq cr6,0x82466244
	if (cr6.eq) goto loc_82466244;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x82466244
	if (!cr6.eq) goto loc_82466244;
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
loc_82466244:
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r3,-1029(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -1029);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd054
	ctx.lr = 0x82466258;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82466228
	if (!cr6.eq) goto loc_82466228;
loc_82466260:
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

__attribute__((alias("__imp__sub_8246627C"))) PPC_WEAK_FUNC(sub_8246627C);
PPC_FUNC_IMPL(__imp__sub_8246627C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82466280"))) PPC_WEAK_FUNC(sub_82466280);
PPC_FUNC_IMPL(__imp__sub_82466280) {
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
	ctx.lr = 0x82466288;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,2224(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2224);
	// bl 0x821c90c0
	ctx.lr = 0x824662A0;
	sub_821C90C0(ctx, base);
	// addi r30,r31,2176
	r30.s64 = r31.s64 + 2176;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c8f08
	ctx.lr = 0x824662AC;
	sub_821C8F08(ctx, base);
	// lwz r11,2216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2216);
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// beq cr6,0x8246631c
	if (cr6.eq) goto loc_8246631C;
	// lwz r11,2208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2208);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,2208(r31)
	PPC_STORE_U32(r31.u32 + 2208, r11.u32);
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// bne cr6,0x824662d0
	if (!cr6.eq) goto loc_824662D0;
	// stw r28,2208(r31)
	PPC_STORE_U32(r31.u32 + 2208, r28.u32);
loc_824662D0:
	// lwz r11,2208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2208);
	// li r5,68
	ctx.r5.s64 = 68;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x824662E8;
	sub_823DA950(ctx, base);
	// lwz r9,2208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2208);
	// lwz r10,2216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2216);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mulli r11,r9,68
	r11.s64 = ctx.r9.s64 * 68;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// stw r8,2216(r31)
	PPC_STORE_U32(r31.u32 + 2216, ctx.r8.u32);
	// bl 0x821c8f70
	ctx.lr = 0x82466308;
	sub_821C8F70(ctx, base);
	// lwz r3,2220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2220);
	// bl 0x821c9108
	ctx.lr = 0x82466310;
	sub_821C9108(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8246631C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c8f70
	ctx.lr = 0x82466324;
	sub_821C8F70(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82466330"))) PPC_WEAK_FUNC(sub_82466330);
PPC_FUNC_IMPL(__imp__sub_82466330) {
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
	ctx.lr = 0x82466338;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// blt cr6,0x8246635c
	if (cr6.lt) goto loc_8246635C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_8246635C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r29,0
	r29.s64 = 0;
	// li r30,32
	r30.s64 = 32;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r27,4
	r27.s64 = 4;
	// stb r11,16105(r10)
	PPC_STORE_U8(ctx.r10.u32 + 16105, r11.u8);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r11,16112
	r28.s64 = r11.s64 + 16112;
loc_8246637C:
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82466280
	ctx.lr = 0x8246638C;
	sub_82466280(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8246637c
	if (!cr0.eq) goto loc_8246637C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8275cb70
	ctx.lr = 0x824663A4;
	sub_8275CB70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8246643c
	if (!cr6.eq) goto loc_8246643C;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8246643c
	if (!cr6.eq) goto loc_8246643C;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x8246640c
	if (!cr6.eq) goto loc_8246640C;
	// lhz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8246640c
	if (cr6.eq) goto loc_8246640C;
	// li r11,18
	r11.s64 = 18;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r9,r26,1
	ctx.r9.s64 = r26.s64 + 1;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// stb r9,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r9.u8);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_8246640C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8246643c
	if (!cr6.eq) goto loc_8246643C;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8246643c
	if (!cr6.eq) goto loc_8246643C;
	// li r11,33
	r11.s64 = 33;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// b 0x82466454
	goto loc_82466454;
loc_8246643C:
	// li r11,34
	r11.s64 = 34;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
loc_82466454:
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r10,r26,1
	ctx.r10.s64 = r26.s64 + 1;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r10,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r10.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82466470"))) PPC_WEAK_FUNC(sub_82466470);
PPC_FUNC_IMPL(__imp__sub_82466470) {
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
	ctx.lr = 0x82466478;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r31,32
	r31.s64 = 32;
	// li r28,4
	r28.s64 = 4;
	// addi r29,r11,16112
	r29.s64 = r11.s64 + 16112;
loc_82466494:
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x82466280
	ctx.lr = 0x824664A4;
	sub_82466280(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82466494
	if (!cr0.eq) goto loc_82466494;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8275cb70
	ctx.lr = 0x824664BC;
	sub_8275CB70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824665b8
	if (!cr6.eq) goto loc_824665B8;
	// lbz r11,96(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// lbz r10,97(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824665b8
	if (!cr6.eq) goto loc_824665B8;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x82466568
	if (!cr6.eq) goto loc_82466568;
	// lhz r9,98(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82466568
	if (cr6.eq) goto loc_82466568;
	// li r3,100
	ctx.r3.s64 = 100;
	// bl 0x8244fec0
	ctx.lr = 0x824664F8;
	sub_8244FEC0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8275c980
	ctx.lr = 0x82466504;
	sub_8275C980(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824665d0
	if (!cr6.eq) goto loc_824665D0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,15080
	ctx.r9.s64 = ctx.r10.s64 + 15080;
	// cmpwi cr6,r8,64
	cr6.compare<int32_t>(ctx.r8.s32, 64, xer);
	// addi r10,r9,-20
	ctx.r10.s64 = ctx.r9.s64 + -20;
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// ble cr6,0x82466534
	if (!cr6.gt) goto loc_82466534;
	// li r8,64
	ctx.r8.s64 = 64;
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82466534:
	// rlwinm r11,r30,8,0,23
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x823d9890
	ctx.lr = 0x82466548;
	sub_823D9890(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8275cb08
	ctx.lr = 0x82466554;
	sub_8275CB08(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824665d0
	if (!cr6.eq) goto loc_824665D0;
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
loc_82466568:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824665b8
	if (!cr6.eq) goto loc_824665B8;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x824665b8
	if (!cr6.eq) goto loc_824665B8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,15080
	r11.s64 = r11.s64 + 15080;
	// rlwinm r10,r30,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// addi r8,r11,-20
	ctx.r8.s64 = r11.s64 + -20;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// bl 0x823d9890
	ctx.lr = 0x824665A8;
	sub_823D9890(ctx, base);
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
loc_824665B8:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,15080
	r11.s64 = r11.s64 + 15080;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-20
	ctx.r8.s64 = r11.s64 + -20;
	// stwx r9,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
loc_824665D0:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
}

