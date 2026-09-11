#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_82775F18) {
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
	ctx.lr = 0x82775F20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r27,24(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stb r4,200(r31)
	PPC_STORE_U8(r31.u32 + 200, ctx.r4.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r5,201(r31)
	PPC_STORE_U8(r31.u32 + 201, ctx.r5.u8);
	// bne cr6,0x82775f70
	if (!cr6.eq) goto loc_82775F70;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82775F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82775f68
	if (!cr6.eq) goto loc_82775F68;
loc_82775F5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82775F68:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82775F70:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r30,r9,8
	r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82775fa8
	if (!cr0.eq) goto loc_82775FA8;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82775F94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82775FA8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// bne 0x82775fe0
	if (!cr0.eq) goto loc_82775FE0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82775FCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82775FE0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r9.u32);
	// bne 0x82776018
	if (!cr0.eq) goto loc_82776018;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776018:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r8,r9,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// bne 0x82776054
	if (!cr0.eq) goto loc_82776054;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776054:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// bne 0x82776094
	if (!cr0.eq) goto loc_82776094;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776094:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addic. r10,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r10.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// rotlwi r7,r8,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// bne 0x827760d0
	if (!cr0.eq) goto loc_827760D0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827760BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_827760D0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r9,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r7,r8
	r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// bne 0x82776110
	if (!cr0.eq) goto loc_82776110;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827760FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776110:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r28,r10,1
	r28.s64 = ctx.r10.s64 + 1;
	// lwz r6,380(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// addi r29,r9,-1
	r29.s64 = ctx.r9.s64 + -1;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,100
	ctx.r7.s64 = 100;
	// addi r30,r30,-8
	r30.s64 = r30.s64 + -8;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r8,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r6.u32);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r7.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277616C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,404(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lbz r4,13(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 13);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277619c
	if (cr6.eq) goto loc_8277619C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,58
	ctx.r10.s64 = 58;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277619C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277619C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827761c0
	if (!cr6.gt) goto loc_827761C0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827761c0
	if (!cr6.gt) goto loc_827761C0;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x827761e0
	if (cr6.gt) goto loc_827761E0;
loc_827761C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827761E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827761E0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x82776214
	if (cr6.eq) goto loc_82776214;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776214:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82776244
	if (!cr6.eq) goto loc_82776244;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mulli r5,r10,84
	ctx.r5.s64 = ctx.r10.s64 * 84;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82776240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
loc_82776244:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r26,0
	r26.s64 = 0;
	// lwz r30,196(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82776374
	if (!cr6.gt) goto loc_82776374;
	// li r25,101
	r25.s64 = 101;
loc_8277625C:
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8277628c
	if (!cr6.eq) goto loc_8277628C;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r28,0(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r29,4(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_8277628C:
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// bne 0x827762c4
	if (!cr0.eq) goto loc_827762C4;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827762B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_827762C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r8,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	// clrlwi r7,r9,28
	ctx.r7.u64 = ctx.r9.u32 & 0xF;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// stw r7,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r7.u32);
	// stw r6,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r6.u32);
	// bne 0x8277630c
	if (!cr0.eq) goto loc_8277630C;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827762F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_8277630C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r10,-1
	r29.s64 = ctx.r10.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r9.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r6,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r6.u32);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r5,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r5.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r25,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r25.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82776360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x8277625c
	if (cr6.lt) goto loc_8277625C;
loc_82776374:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,13(r11)
	PPC_STORE_U8(r11.u32 + 13, ctx.r10.u8);
	// stw r28,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r28.u32);
	// stw r29,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82775F18) {
	__imp__sub_82775F18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82776394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82776394) {
	__imp__sub_82776394(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82776398) {
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
	ctx.lr = 0x827763A0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r25,24(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,4(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827763e0
	if (!cr6.eq) goto loc_827763E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,62
	ctx.r10.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827763E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827763E0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82776418
	if (!cr6.eq) goto loc_82776418;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827763F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776410
	if (!cr6.eq) goto loc_82776410;
loc_82776404:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_82776410:
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,4(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776418:
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rotlwi r30,r9,8
	r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776450
	if (!cr0.eq) goto loc_82776450;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277643C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776450:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// bne 0x82776488
	if (!cr0.eq) goto loc_82776488;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776488:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,103
	ctx.r8.s64 = 103;
	// lbz r22,0(r11)
	r22.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r26,r10,-1
	r26.s64 = ctx.r10.s64 + -1;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r22,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, r22.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827764C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r22,3
	ctx.r4.s64 = r22.s64 + 3;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x827764e0
	if (!cr6.eq) goto loc_827764E0;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// blt cr6,0x827764e0
	if (cr6.lt) goto loc_827764E0;
	// cmpwi cr6,r22,4
	cr6.compare<int32_t>(r22.s32, 4, xer);
	// ble cr6,0x82776500
	if (!cr6.gt) goto loc_82776500;
loc_827764E0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776500:
	// stw r22,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r22.u32);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x82776640
	if (!cr6.gt) goto loc_82776640;
	// addi r23,r31,296
	r23.s64 = r31.s64 + 296;
	// li r20,5
	r20.s64 = 5;
	// li r21,104
	r21.s64 = 104;
loc_8277651C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82776548
	if (!cr6.eq) goto loc_82776548;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r28,0(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r26,4(r25)
	r26.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776548:
	// lbz r27,0(r28)
	r27.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addic. r10,r26,-1
	xer.ca = r26.u32 > 0;
	ctx.r10.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// bne 0x8277657c
	if (!cr0.eq) goto loc_8277657C;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_8277657C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// lbz r29,0(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r26,r10,-1
	r26.s64 = ctx.r10.s64 + -1;
	// lwz r30,196(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827765bc
	if (!cr6.gt) goto loc_827765BC;
loc_8277659C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// beq cr6,0x827765e0
	if (cr6.eq) goto loc_827765E0;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277659c
	if (cr6.lt) goto loc_8277659C;
loc_827765BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r20,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r20.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r27.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827765E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827765E0:
	// srawi r11,r29,4
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0xF) != 0);
	r11.s64 = r29.s32 >> 4;
	// stw r30,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r30.u32);
	// clrlwi r10,r29,28
	ctx.r10.u64 = r29.u32 & 0xF;
	// clrlwi r9,r11,28
	ctx.r9.u64 = r11.u32 & 0xF;
	// stw r10,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r27.u32);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r8,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r8.u32);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r7,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r21,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r21.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpw cr6,r24,r22
	cr6.compare<int32_t>(r24.s32, r22.s32, xer);
	// blt cr6,0x8277651c
	if (cr6.lt) goto loc_8277651C;
loc_82776640:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8277666c
	if (!cr6.eq) goto loc_8277666C;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r28,0(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r26,4(r25)
	r26.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_8277666C:
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addic. r10,r26,-1
	xer.ca = r26.u32 > 0;
	ctx.r10.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// stw r9,364(r31)
	PPC_STORE_U32(r31.u32 + 364, ctx.r9.u32);
	// bne 0x827766a4
	if (!cr0.eq) goto loc_827766A4;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_827766A4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r29,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r29.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// stw r9,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r9.u32);
	// bne 0x827766dc
	if (!cr0.eq) goto loc_827766DC;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827766C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,4(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_827766DC:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// li r9,105
	ctx.r9.s64 = 105;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// srawi r8,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
	// lwz r7,364(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// clrlwi r5,r8,28
	ctx.r5.u64 = ctx.r8.u32 & 0xF;
	// stw r6,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,372(r31)
	PPC_STORE_U32(r31.u32 + 372, ctx.r5.u32);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// lwz r8,372(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lwz r7,376(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277673C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,404(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r30,1
	ctx.r9.s64 = r30.s64 + 1;
	// addi r8,r29,-1
	ctx.r8.s64 = r29.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r6.u32);
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// stw r8,4(r25)
	PPC_STORE_U32(r25.u32 + 4, ctx.r8.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_82776398) {
	__imp__sub_82776398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82776770) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82776778;
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r24,24(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827767c0
	if (!cr6.eq) goto loc_827767C0;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827767A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827767b8
	if (!cr6.eq) goto loc_827767B8;
loc_827767AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x823d9220
	return;
loc_827767B8:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_827767C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r29,r9,8
	r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x827767f8
	if (!cr0.eq) goto loc_827767F8;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827767E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_827767F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// addi r28,r10,-1
	r28.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r29
	r11.u64 = ctx.r9.u64 + r29.u64;
	// addi r26,r11,-2
	r26.s64 = r11.s64 + -2;
	// cmpwi cr6,r26,16
	cr6.compare<int32_t>(r26.s32, 16, xer);
	// ble cr6,0x82776ae4
	if (!cr6.gt) goto loc_82776AE4;
	// li r21,80
	r21.s64 = 80;
	// li r22,0
	r22.s64 = 0;
	// li r23,86
	r23.s64 = 86;
	// li r19,8
	r19.s64 = 8;
	// li r20,30
	r20.s64 = 30;
loc_82776828:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82776854
	if (!cr6.eq) goto loc_82776854;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_82776854:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// lbz r25,0(r31)
	r25.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r21,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r21.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r22
	r27.u64 = r22.u64;
	// stb r22,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r22.u8);
	// li r29,1
	r29.s64 = 1;
loc_82776894:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827768c0
	if (!cr6.eq) goto loc_827768C0;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827768AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_827768C0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// add r27,r11,r27
	r27.u64 = r11.u64 + r27.u64;
	// ble cr6,0x82776894
	if (!cr6.gt) goto loc_82776894;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r26,r26,-17
	r26.s64 = r26.s64 + -17;
	// lbz r7,81(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r4,2
	ctx.r4.s64 = 2;
	// lbz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r9,83(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// lbz r8,86(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r29,87(r1)
	r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// lbz r18,88(r1)
	r18.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r29.u32);
	// stw r7,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r7.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r23,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r23.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r7,89(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// li r4,2
	ctx.r4.s64 = 2;
	// lbz r5,90(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 90);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 92);
	// lbz r9,91(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 91);
	// lbz r10,93(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 93);
	// lbz r8,94(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 94);
	// lbz r29,95(r1)
	r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// lbz r18,96(r1)
	r18.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r29.u32);
	// stw r7,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r7.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r23,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r23.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827769C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r27,256
	cr6.compare<int32_t>(r27.s32, 256, xer);
	// bgt cr6,0x827769d0
	if (cr6.gt) goto loc_827769D0;
	// cmpw cr6,r27,r26
	cr6.compare<int32_t>(r27.s32, r26.s32, xer);
	// ble cr6,0x827769ec
	if (!cr6.gt) goto loc_827769EC;
loc_827769D0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r19,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r19.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827769EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827769EC:
	// mr r29,r22
	r29.u64 = r22.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82776a44
	if (!cr6.gt) goto loc_82776A44;
loc_827769F8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82776a24
	if (!cr6.eq) goto loc_82776A24;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_82776A24:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stbx r11,r29,r10
	PPC_STORE_U8(r29.u32 + ctx.r10.u32, r11.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x827769f8
	if (cr6.lt) goto loc_827769F8;
loc_82776A44:
	// rlwinm r11,r25,0,27,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x10;
	// subf r26,r27,r26
	r26.s64 = r26.s64 - r27.s64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82776a60
	if (cr6.eq) goto loc_82776A60;
	// addi r25,r25,-16
	r25.s64 = r25.s64 + -16;
	// addi r11,r25,44
	r11.s64 = r25.s64 + 44;
	// b 0x82776a64
	goto loc_82776A64;
loc_82776A60:
	// addi r11,r25,40
	r11.s64 = r25.s64 + 40;
loc_82776A64:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// blt cr6,0x82776a7c
	if (cr6.lt) goto loc_82776A7C;
	// cmpwi cr6,r25,4
	cr6.compare<int32_t>(r25.s32, 4, xer);
	// blt cr6,0x82776aa0
	if (cr6.lt) goto loc_82776AA0;
loc_82776A7C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r20,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r20.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776AA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776AA0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82776ab8
	if (!cr6.eq) goto loc_82776AB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277a2e0
	ctx.lr = 0x82776AB4;
	sub_8277A2E0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82776AB8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,17
	ctx.r5.s64 = 17;
	// bl 0x823da950
	ctx.lr = 0x82776AC8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r11,17
	ctx.r3.s64 = r11.s64 + 17;
	// li r5,256
	ctx.r5.s64 = 256;
	// bl 0x823da950
	ctx.lr = 0x82776ADC;
	sub_823DA950(ctx, base);
	// cmpwi cr6,r26,16
	cr6.compare<int32_t>(r26.s32, 16, xer);
	// bgt cr6,0x82776828
	if (cr6.gt) goto loc_82776828;
loc_82776AE4:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82776b0c
	if (cr6.eq) goto loc_82776B0C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776B0C:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r28.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_82776770) {
	__imp__sub_82776770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82776B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82776B28;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r26,24(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776b70
	if (!cr6.eq) goto loc_82776B70;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776B50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776b68
	if (!cr6.eq) goto loc_82776B68;
loc_82776B5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
loc_82776B68:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776B70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r31,r9,8
	r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776ba8
	if (!cr0.eq) goto loc_82776BA8;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776BA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r27,r10,-1
	r27.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// addic. r21,r11,-2
	xer.ca = r11.u32 > 1;
	r21.s64 = r11.s64 + -2;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// ble 0x82776e0c
	if (!cr0.gt) goto loc_82776E0C;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// li r20,81
	r20.s64 = 81;
	// li r19,31
	r19.s64 = 31;
	// li r22,93
	r22.s64 = 93;
	// addi r23,r11,-31424
	r23.s64 = r11.s64 + -31424;
loc_82776BD4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82776c00
	if (!cr6.eq) goto loc_82776C00;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776C00:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// clrlwi r31,r10,28
	r31.u64 = ctx.r10.u32 & 0xF;
	// srawi r24,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	r24.s64 = ctx.r10.s32 >> 4;
	// stw r20,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r20.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r24,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, r24.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82776C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82776c70
	if (cr6.lt) goto loc_82776C70;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r19,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r19.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776C70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776C70:
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776c90
	if (!cr6.eq) goto loc_82776C90;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8277a2a0
	ctx.lr = 0x82776C8C;
	sub_8277A2A0(ctx, base);
	// stwx r3,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r3.u32);
loc_82776C90:
	// lwzx r25,r31,r28
	r25.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// mr r29,r23
	r29.u64 = r23.u64;
loc_82776C98:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x82776d18
	if (cr6.eq) goto loc_82776D18;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82776ccc
	if (!cr6.eq) goto loc_82776CCC;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776CB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776CCC:
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addic. r10,r27,-1
	xer.ca = r27.u32 > 0;
	ctx.r10.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// rotlwi r31,r9,8
	r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776d04
	if (!cr0.eq) goto loc_82776D04;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776D04:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r27,r10,-1
	r27.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// b 0x82776d50
	goto loc_82776D50;
loc_82776D18:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82776d44
	if (!cr6.eq) goto loc_82776D44;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776D44:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82776D50:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r7,r23,256
	ctx.r7.s64 = r23.s64 + 256;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// sthx r11,r8,r25
	PPC_STORE_U16(ctx.r8.u32 + r25.u32, r11.u16);
	// blt cr6,0x82776c98
	if (cr6.lt) goto loc_82776C98;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x82776df4
	if (cr6.lt) goto loc_82776DF4;
	// addi r31,r25,4
	r31.s64 = r25.s64 + 4;
	// li r29,8
	r29.s64 = 8;
loc_82776D84:
	// lhz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + -4);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lhz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + -2);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lhz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lhz r7,2(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// stw r6,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r6.u32);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// stw r5,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r5.u32);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// stw r9,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r9.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r22,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r22.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82776DE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x82776d84
	if (!cr0.eq) goto loc_82776D84;
loc_82776DF4:
	// addi r21,r21,-65
	r21.s64 = r21.s64 + -65;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x82776e04
	if (cr6.eq) goto loc_82776E04;
	// addi r21,r21,-64
	r21.s64 = r21.s64 + -64;
loc_82776E04:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bgt cr6,0x82776bd4
	if (cr6.gt) goto loc_82776BD4;
loc_82776E0C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x82776e34
	if (cr6.eq) goto loc_82776E34;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776E34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776E34:
	// stw r30,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r27,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r27.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_82776B20) {
	__imp__sub_82776B20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82776E48) {
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
	ctx.lr = 0x82776E50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776e98
	if (!cr6.eq) goto loc_82776E98;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776e90
	if (!cr6.eq) goto loc_82776E90;
loc_82776E84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82776E90:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776E98:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r27,r9,8
	r27.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776ed0
	if (!cr0.eq) goto loc_82776ED0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776EBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776e84
	if (cr6.eq) goto loc_82776E84;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776ED0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// addi r28,r10,-1
	r28.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r27
	r11.u64 = ctx.r9.u64 + r27.u64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82776f08
	if (cr6.eq) goto loc_82776F08;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776F08:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82776f34
	if (!cr6.eq) goto loc_82776F34;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776F20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776e84
	if (cr6.eq) goto loc_82776E84;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776F34:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addic. r27,r28,-1
	xer.ca = r28.u32 > 0;
	r27.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// rotlwi r28,r11,8
	r28.u64 = __builtin_rotateleft32(r11.u32, 8);
	// bne 0x82776f6c
	if (!cr0.eq) goto loc_82776F6C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776F58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776e84
	if (cr6.eq) goto loc_82776E84;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r27,4(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776F6C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,82
	ctx.r9.s64 = 82;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r28,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, r28.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82776FA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r29,1
	ctx.r5.s64 = r29.s64 + 1;
	// addi r4,r27,-1
	ctx.r4.s64 = r27.s64 + -1;
	// stw r28,252(r30)
	PPC_STORE_U32(r30.u32 + 252, r28.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82776E48) {
	__imp__sub_82776E48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82776FC0) {
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
	ctx.lr = 0x82776FC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// add r29,r5,r6
	r29.u64 = ctx.r5.u64 + ctx.r6.u64;
	// cmplwi cr6,r5,14
	cr6.compare<uint32_t>(ctx.r5.u32, 14, xer);
	// blt cr6,0x827771a0
	if (cr6.lt) goto loc_827771A0;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,74
	cr6.compare<uint32_t>(r11.u32, 74, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,70
	cr6.compare<uint32_t>(r11.u32, 70, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// cmplwi cr6,r11,73
	cr6.compare<uint32_t>(r11.u32, 73, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,3(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// cmplwi cr6,r11,70
	cr6.compare<uint32_t>(r11.u32, 70, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// li r11,1
	r11.s64 = 1;
	// stb r11,256(r31)
	PPC_STORE_U8(r31.u32 + 256, r11.u8);
	// lbz r10,5(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// stb r10,257(r31)
	PPC_STORE_U8(r31.u32 + 257, ctx.r10.u8);
	// lbz r9,6(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// stb r9,258(r31)
	PPC_STORE_U8(r31.u32 + 258, ctx.r9.u8);
	// lbz r8,7(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 7);
	// stb r8,259(r31)
	PPC_STORE_U8(r31.u32 + 259, ctx.r8.u8);
	// lbz r11,9(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 9);
	// lbz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// rotlwi r10,r7,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lbz r5,257(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// sth r6,260(r31)
	PPC_STORE_U16(r31.u32 + 260, ctx.r6.u16);
	// lbz r10,11(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 11);
	// lbz r3,10(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// rotlwi r11,r3,8
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// sth r11,262(r31)
	PPC_STORE_U16(r31.u32 + 262, r11.u16);
	// beq cr6,0x827770ac
	if (cr6.eq) goto loc_827770AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,119
	ctx.r10.s64 = 119;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r9,257(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r6,258(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 258);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827770AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827770AC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,87
	ctx.r10.s64 = 87;
	// lbz r9,257(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r9.u32);
	// lbz r8,258(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 258);
	// stw r8,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r8.u32);
	// lhz r7,260(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 260);
	// stw r7,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r7.u32);
	// lhz r6,262(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 262);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// lbz r5,259(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 259);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827770FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,13(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// lbz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8277714c
	if (cr6.eq) goto loc_8277714C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,90
	ctx.r10.s64 = 90;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r6,13(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277714C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277714C:
	// lbz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// addi r10,r29,-14
	ctx.r10.s64 = r29.s64 + -14;
	// lbz r11,13(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// beq cr6,0x82777284
	if (cr6.eq) goto loc_82777284;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,88
	ctx.r9.s64 = 88;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82777198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827771A0:
	// cmplwi cr6,r5,6
	cr6.compare<uint32_t>(ctx.r5.u32, 6, xer);
	// blt cr6,0x82777258
	if (cr6.lt) goto loc_82777258;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,74
	cr6.compare<uint32_t>(r11.u32, 74, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,70
	cr6.compare<uint32_t>(r11.u32, 70, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// cmplwi cr6,r11,88
	cr6.compare<uint32_t>(r11.u32, 88, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,3(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// cmplwi cr6,r11,88
	cr6.compare<uint32_t>(r11.u32, 88, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// beq cr6,0x82777250
	if (cr6.eq) goto loc_82777250;
	// cmpwi cr6,r11,17
	cr6.compare<int32_t>(r11.s32, 17, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82777248
	if (cr6.eq) goto loc_82777248;
	// cmpwi cr6,r11,19
	cr6.compare<int32_t>(r11.s32, 19, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// beq cr6,0x82777240
	if (cr6.eq) goto loc_82777240;
	// li r10,89
	ctx.r10.s64 = 89;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r8,5(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82777238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82777240:
	// li r10,110
	ctx.r10.s64 = 110;
	// b 0x82777268
	goto loc_82777268;
loc_82777248:
	// li r10,109
	ctx.r10.s64 = 109;
	// b 0x82777264
	goto loc_82777264;
loc_82777250:
	// li r10,108
	ctx.r10.s64 = 108;
	// b 0x8277725c
	goto loc_8277725C;
loc_82777258:
	// li r10,77
	ctx.r10.s64 = 77;
loc_8277725C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
loc_82777264:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_82777268:
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82777284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777284:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82776FC0) {
	__imp__sub_82776FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277728C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277728C) {
	__imp__sub_8277728C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82777290) {
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
	ctx.lr = 0x82777298;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,12
	cr6.compare<uint32_t>(ctx.r5.u32, 12, xer);
	// blt cr6,0x82777368
	if (cr6.lt) goto loc_82777368;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,65
	cr6.compare<uint32_t>(ctx.r10.u32, 65, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r10,100
	cr6.compare<uint32_t>(ctx.r10.u32, 100, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// cmplwi cr6,r10,111
	cr6.compare<uint32_t>(ctx.r10.u32, 111, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cmplwi cr6,r10,98
	cr6.compare<uint32_t>(ctx.r10.u32, 98, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,101
	cr6.compare<uint32_t>(ctx.r10.u32, 101, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r8,9(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// li r30,76
	r30.s64 = 76;
	// lbz r10,7(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// rotlwi r6,r8,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// rotlwi r8,r5,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lbz r7,6(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// lbz r5,10(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lbz r29,11(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r6,r5
	r11.u64 = ctx.r6.u64 + ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, r11.u32);
	// stw r29,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, r29.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82777354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r29,265(r31)
	PPC_STORE_U8(r31.u32 + 265, r29.u8);
	// stb r4,264(r31)
	PPC_STORE_U8(r31.u32 + 264, ctx.r4.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82777368:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,78
	ctx.r10.s64 = 78;
	// add r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 + ctx.r6.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82777398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82777290) {
	__imp__sub_82777290(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827773A0) {
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
	ctx.lr = 0x827773A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,24(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827773f0
	if (!cr6.eq) goto loc_827773F0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827773D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827773e8
	if (!cr6.eq) goto loc_827773E8;
loc_827773DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_827773E8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_827773F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r31,r9,8
	r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82777428
	if (!cr0.eq) goto loc_82777428;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827773dc
	if (cr6.eq) goto loc_827773DC;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82777428:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r29,r10,-1
	r29.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// addi r26,r11,-2
	r26.s64 = r11.s64 + -2;
	// cmpwi cr6,r26,14
	cr6.compare<int32_t>(r26.s32, 14, xer);
	// blt cr6,0x8277744c
	if (cr6.lt) goto loc_8277744C;
	// li r28,14
	r28.s64 = 14;
	// b 0x8277745c
	goto loc_8277745C;
loc_8277744C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r28,r26
	r28.u64 = r26.u64;
	// bgt cr6,0x8277745c
	if (cr6.gt) goto loc_8277745C;
	// li r28,0
	r28.s64 = 0;
loc_8277745C:
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827774b4
	if (cr6.eq) goto loc_827774B4;
loc_82777468:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82777494
	if (!cr6.eq) goto loc_82777494;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827773dc
	if (cr6.eq) goto loc_827773DC;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r29,4(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82777494:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stbx r11,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r11.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// blt cr6,0x82777468
	if (cr6.lt) goto loc_82777468;
loc_827774B4:
	// lwz r11,380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 380);
	// subf r31,r28,r26
	r31.s64 = r26.s64 - r28.s64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// cmpwi cr6,r11,224
	cr6.compare<int32_t>(r11.s32, 224, xer);
	// beq cr6,0x82777510
	if (cr6.eq) goto loc_82777510;
	// cmpwi cr6,r11,238
	cr6.compare<int32_t>(r11.s32, 238, xer);
	// beq cr6,0x827774fc
	if (cr6.eq) goto loc_827774FC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r10,68
	ctx.r10.s64 = 68;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r8,380(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 380);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827774F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82777520
	goto loc_82777520;
loc_827774FC:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82777290
	ctx.lr = 0x8277750C;
	sub_82777290(ctx, base);
	// b 0x82777520
	goto loc_82777520;
loc_82777510:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82776fc0
	ctx.lr = 0x82777520;
	sub_82776FC0(ctx, base);
loc_82777520:
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stw r29,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r29.u32);
	// ble cr6,0x82777548
	if (!cr6.gt) goto loc_82777548;
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82777548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777548:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_827773A0) {
	__imp__sub_827773A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82777554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82777554) {
	__imp__sub_82777554(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82777558) {
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
	ctx.lr = 0x82777560;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827775a8
	if (!cr6.eq) goto loc_827775A8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827775a0
	if (!cr6.eq) goto loc_827775A0;
loc_82777594:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827775A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_827775A8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r27,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r27.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// rotlwi r29,r9,8
	r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x827775e0
	if (!cr0.eq) goto loc_827775E0;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827775CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777594
	if (cr6.eq) goto loc_82777594;
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r27,4(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_827775E0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,91
	ctx.r9.s64 = 91;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// addi r29,r11,-2
	r29.s64 = r11.s64 + -2;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,380(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, r29.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// addi r9,r27,-1
	ctx.r9.s64 = r27.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// ble cr6,0x82777654
	if (!cr6.gt) goto loc_82777654;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82777654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777654:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82777558) {
	__imp__sub_82777558(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82777660) {
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
	ctx.lr = 0x82777668;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r30,24(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_8277767C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827776a8
	if (!cr6.eq) goto loc_827776A8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777778
	if (cr6.eq) goto loc_82777778;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_827776A8:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x82777714
	if (cr6.eq) goto loc_82777714;
loc_827776BC:
	// lwz r11,404(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// bne cr6,0x82777700
	if (!cr6.eq) goto loc_82777700;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827776EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777778
	if (cr6.eq) goto loc_82777778;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_82777700:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// bne cr6,0x827776bc
	if (!cr6.eq) goto loc_827776BC;
loc_82777714:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82777740
	if (!cr6.eq) goto loc_82777740;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277772C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777778
	if (cr6.eq) goto loc_82777778;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_82777740:
	// lbz r28,0(r29)
	r28.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r28,255
	cr6.compare<int32_t>(r28.s32, 255, xer);
	// beq cr6,0x82777714
	if (cr6.eq) goto loc_82777714;
	// lwz r11,404(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bne cr6,0x82777784
	if (!cr6.eq) goto loc_82777784;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// b 0x8277767c
	goto loc_8277767C;
loc_82777778:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82777784:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827777d4
	if (cr6.eq) goto loc_827777D4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r10,116
	ctx.r10.s64 = 116;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,404(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r28,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, r28.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827777C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,404(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
loc_827777D4:
	// stw r28,380(r27)
	PPC_STORE_U32(r27.u32 + 380, r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82777660) {
	__imp__sub_82777660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827777EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827777EC) {
	__imp__sub_827777EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827777F0) {
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
	ctx.lr = 0x827777F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,24(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82777840
	if (!cr6.eq) goto loc_82777840;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82777838
	if (!cr6.eq) goto loc_82777838;
loc_8277782C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82777838:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82777840:
	// lbz r28,0(r11)
	r28.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x82777874
	if (!cr0.eq) goto loc_82777874;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277782c
	if (cr6.eq) goto loc_8277782C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82777874:
	// lbz r30,0(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r27,r10,-1
	r27.s64 = ctx.r10.s64 + -1;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
	// cmpwi cr6,r28,255
	cr6.compare<int32_t>(r28.s32, 255, xer);
	// bne cr6,0x82777890
	if (!cr6.eq) goto loc_82777890;
	// cmpwi cr6,r30,216
	cr6.compare<int32_t>(r30.s32, 216, xer);
	// beq cr6,0x827778c0
	if (cr6.eq) goto loc_827778C0;
loc_82777890:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,53
	ctx.r10.s64 = 53;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r28,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r28.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, r30.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827778C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827778C0:
	// stw r30,380(r29)
	PPC_STORE_U32(r29.u32 + 380, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_827777F0) {
	__imp__sub_827777F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827778D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827778E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,60
	r27.s64 = 60;
	// li r28,92
	r28.s64 = 92;
	// li r29,68
	r29.s64 = 68;
	// li r30,0
	r30.s64 = 0;
loc_827778F8:
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82777930
	if (!cr6.eq) goto loc_82777930;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82777920
	if (!cr6.eq) goto loc_82777920;
	// bl 0x827777f0
	ctx.lr = 0x8277791C;
	sub_827777F0(ctx, base);
	// b 0x82777924
	goto loc_82777924;
loc_82777920:
	// bl 0x82777660
	ctx.lr = 0x82777924;
	sub_82777660(ctx, base);
loc_82777924:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
loc_82777930:
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,253
	cr6.compare<uint32_t>(ctx.r10.u32, 253, xer);
	// bgt cr6,0x82777f14
	if (cr6.gt) goto loc_82777F14;
	// lis r12,-32137
	r12.s64 = -2106130432;
	// addi r12,r12,31064
	r12.s64 = r12.s64 + 31064;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32112(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32112);
	// lwz r19,32112(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32112);
	// lwz r19,32148(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32148);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32308(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32308);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32184(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32184);
	// lwz r19,32220(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32220);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32280(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32280);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32080(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32080);
	// lwz r19,32616(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32616);
	// lwz r19,32580(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32580);
	// lwz r19,32336(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32336);
	// lwz r19,32280(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32280);
	// lwz r19,32364(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32364);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32440(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775e38
	ctx.lr = 0x82777D58;
	sub_82775E38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82777f3c
	if (!cr6.eq) goto loc_82777F3C;
loc_82777D64:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777D80;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777DA4;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777DC8;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777DEC;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// b 0x82777f28
	goto loc_82777F28;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82777558
	ctx.lr = 0x82777E20;
	sub_82777558(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776770
	ctx.lr = 0x82777E3C;
	sub_82776770(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776b20
	ctx.lr = 0x82777E58;
	sub_82776B20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776e48
	ctx.lr = 0x82777E74;
	sub_82776E48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// addi r11,r11,-217
	r11.s64 = r11.s64 + -217;
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82777EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82777ECC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r9,380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82777F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777F14:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r29.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
loc_82777F28:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82777F3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777F3C:
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776398
	ctx.lr = 0x82777F4C;
	sub_82776398(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,85
	ctx.r10.s64 = 85;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82777F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_827778D8) {
	__imp__sub_827778D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82777F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82777F9C) {
	__imp__sub_82777F9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82777FA0) {
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
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82777fe8
	if (!cr6.eq) goto loc_82777FE8;
	// bl 0x82777660
	ctx.lr = 0x82777FC4;
	sub_82777660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82777fe8
	if (!cr6.eq) goto loc_82777FE8;
loc_82777FD0:
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
loc_82777FE8:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r9,r4,208
	ctx.r9.s64 = ctx.r4.s64 + 208;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x82778040
	if (!cr6.eq) goto loc_82778040;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,98
	ctx.r10.s64 = 98;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,404(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82778034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r4,380(r31)
	PPC_STORE_U32(r31.u32 + 380, ctx.r4.u32);
	// b 0x82778060
	goto loc_82778060;
loc_82778040:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778054;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82777fd0
	if (cr6.eq) goto loc_82777FD0;
loc_82778060:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_82777FA0) {
	__imp__sub_82777FA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277808C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277808C) {
	__imp__sub_8277808C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778090) {
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
	ctx.lr = 0x82778098;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r10,121
	ctx.r10.s64 = 121;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r30,380(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r30.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r28,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, r28.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827780D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r27,97
	r27.s64 = 97;
loc_827780DC:
	// cmpwi cr6,r30,192
	cr6.compare<int32_t>(r30.s32, 192, xer);
	// bge cr6,0x827780ec
	if (!cr6.lt) goto loc_827780EC;
loc_827780E4:
	// li r31,2
	r31.s64 = 2;
	// b 0x82778158
	goto loc_82778158;
loc_827780EC:
	// cmpwi cr6,r30,208
	cr6.compare<int32_t>(r30.s32, 208, xer);
	// blt cr6,0x82778154
	if (cr6.lt) goto loc_82778154;
	// cmpwi cr6,r30,215
	cr6.compare<int32_t>(r30.s32, 215, xer);
	// bgt cr6,0x82778154
	if (cr6.gt) goto loc_82778154;
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x82778154
	if (cr6.eq) goto loc_82778154;
	// addi r11,r28,2
	r11.s64 = r28.s64 + 2;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x82778154
	if (cr6.eq) goto loc_82778154;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x827780e4
	if (cr6.eq) goto loc_827780E4;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x827780e4
	if (cr6.eq) goto loc_827780E4;
	// li r31,1
	r31.s64 = 1;
	// b 0x82778158
	goto loc_82778158;
loc_82778154:
	// li r31,3
	r31.s64 = 3;
loc_82778158:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r30.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r31,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r31.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82778188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x827781d4
	if (cr6.eq) goto loc_827781D4;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x827781ac
	if (cr6.eq) goto loc_827781AC;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bne cr6,0x827780dc
	if (!cr6.eq) goto loc_827780DC;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827781AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82777660
	ctx.lr = 0x827781B4;
	sub_82777660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827781c8
	if (cr6.eq) goto loc_827781C8;
	// lwz r30,380(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// b 0x827780dc
	goto loc_827780DC;
loc_827781C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827781D4:
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,380(r29)
	PPC_STORE_U32(r29.u32 + 380, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82778090) {
	__imp__sub_82778090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827781E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,404(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// li r11,0
	r11.s64 = 0;
	// stw r11,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, r11.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,380(r3)
	PPC_STORE_U32(ctx.r3.u32 + 380, r11.u32);
	// stb r11,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, r11.u8);
	// stb r11,13(r10)
	PPC_STORE_U8(ctx.r10.u32 + 13, r11.u8);
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// stw r11,160(r10)
	PPC_STORE_U32(ctx.r10.u32 + 160, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827781E8) {
	__imp__sub_827781E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,168
	ctx.r5.s64 = 168;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277823C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r7,-32137
	ctx.r7.s64 = -2106130432;
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// lis r6,-32137
	ctx.r6.s64 = -2106130432;
	// lis r8,-32137
	ctx.r8.s64 = -2106130432;
	// addi r5,r9,-32280
	ctx.r5.s64 = ctx.r9.s64 + -32280;
	// addi r10,r7,32672
	ctx.r10.s64 = ctx.r7.s64 + 32672;
	// addi r9,r6,30040
	ctx.r9.s64 = ctx.r6.s64 + 30040;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// addi r4,r8,30936
	ctx.r4.s64 = ctx.r8.s64 + 30936;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r9,16
	ctx.r9.s64 = 16;
loc_82778280:
	// lis r8,-32137
	ctx.r8.s64 = -2106130432;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r7,r8,30040
	ctx.r7.s64 = ctx.r8.s64 + 30040;
	// stw r7,-68(r10)
	PPC_STORE_U32(ctx.r10.u32 + -68, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82778280
	if (!cr0.eq) goto loc_82778280;
	// lis r10,-32137
	ctx.r10.s64 = -2106130432;
	// lis r9,-32137
	ctx.r9.s64 = -2106130432;
	// addi r8,r10,29600
	ctx.r8.s64 = ctx.r10.s64 + 29600;
	// addi r7,r9,29600
	ctx.r7.s64 = ctx.r9.s64 + 29600;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// stw r7,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r7.u32);
	// lwz r6,404(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stw r11,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r11.u32);
	// stb r11,12(r6)
	PPC_STORE_U8(ctx.r6.u32 + 12, r11.u8);
	// stb r11,13(r6)
	PPC_STORE_U8(ctx.r6.u32 + 13, r11.u8);
	// stw r11,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r11.u32);
	// stw r11,160(r6)
	PPC_STORE_U32(ctx.r6.u32 + 160, r11.u32);
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

PPC_WEAK_FUNC(sub_82778210) {
	__imp__sub_82778210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827782E8) {
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
	ctx.lr = 0x827782F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// beq cr6,0x8277833c
	if (cr6.eq) goto loc_8277833C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,62
	ctx.r9.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r4,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r4.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8277833C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277833C:
	// cmplwi cr6,r29,432
	cr6.compare<uint32_t>(r29.u32, 432, xer);
	// beq cr6,0x82778378
	if (cr6.eq) goto loc_82778378;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,21
	ctx.r10.s64 = 21;
	// li r9,432
	ctx.r9.s64 = 432;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82778378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778378:
	// li r5,432
	ctx.r5.s64 = 432;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x82778390;
	sub_823D9890(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x8277bbd8
	ctx.lr = 0x827783A8;
	sub_8277BBD8(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// stw r30,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r30.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
loc_827783CC:
	// stw r30,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827783cc
	if (!cr0.eq) goto loc_827783CC;
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778210
	ctx.lr = 0x827783EC;
	sub_82778210(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277ab78
	ctx.lr = 0x827783F4;
	sub_8277AB78(ctx, base);
	// li r11,200
	r11.s64 = 200;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827782E8) {
	__imp__sub_827782E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778404) {
	__imp__sub_82778404(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778408) {
	PPC_FUNC_PROLOGUE();
	// b 0x8277a250
	sub_8277A250(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82778408) {
	__imp__sub_82778408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277840C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277840C) {
	__imp__sub_8277840C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778410) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82778418;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// li r27,2
	r27.s64 = 2;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x827785dc
	if (cr6.eq) goto loc_827785DC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x827784d4
	if (cr6.eq) goto loc_827784D4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82778454
	if (cr6.eq) goto loc_82778454;
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_82778454:
	// lbz r11,264(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 264);
	// li r30,4
	r30.s64 = 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827784c8
	if (cr6.eq) goto loc_827784C8;
	// lbz r11,265(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827784c8
	if (cr6.eq) goto loc_827784C8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x827784b8
	if (cr6.eq) goto loc_827784B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,114
	ctx.r10.s64 = 114;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r9,265(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827784A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827784B8:
	// li r11,5
	r11.s64 = 5;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827784C8:
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827784D4:
	// lbz r11,256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82778564
	if (!cr6.eq) goto loc_82778564;
	// lbz r11,264(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277853c
	if (cr6.eq) goto loc_8277853C;
	// lbz r11,265(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8277858c
	if (cr6.lt) goto loc_8277858C;
	// beq cr6,0x82778564
	if (cr6.eq) goto loc_82778564;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,114
	ctx.r10.s64 = 114;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r9,265(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277852C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_8277853C:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// lwz r8,168(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82778574
	if (!cr6.eq) goto loc_82778574;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
loc_82778564:
	// li r11,3
	r11.s64 = 3;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_82778574:
	// cmpwi cr6,r10,82
	cr6.compare<int32_t>(ctx.r10.s32, 82, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
	// cmpwi cr6,r9,71
	cr6.compare<int32_t>(ctx.r9.s32, 71, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
	// cmpwi cr6,r8,66
	cr6.compare<int32_t>(ctx.r8.s32, 66, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
loc_8277858C:
	// stw r27,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r27.u32);
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_82778598:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,111
	ctx.r7.s64 = 111;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r7.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827785CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827785DC:
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
loc_827785E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r28.u32);
	// li r10,256
	ctx.r10.s64 = 256;
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// stb r29,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r29.u8);
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// lfd f0,21560(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 21560);
	// stb r28,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r28.u8);
	// stfd f0,56(r31)
	PPC_STORE_U64(r31.u32 + 56, f0.u64);
	// stb r28,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r28.u8);
	// stb r29,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r29.u8);
	// stw r27,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r27.u32);
	// stb r28,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r28.u8);
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
	// stb r29,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r29.u8);
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82778410) {
	__imp__sub_82778410(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,-200
	r11.s64 = r11.s64 + -200;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// bgt cr6,0x8277872c
	if (cr6.gt) goto loc_8277872C;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-31108
	r12.s64 = r12.s64 + -31108;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-31064(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -31064);
	// lwz r19,-31016(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -31016);
	// lwz r19,-30964(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30964);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30932(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30932);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827786BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827786D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,201
	ctx.r7.s64 = 201;
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827786EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x82778758
	if (!cr6.eq) goto loc_82778758;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778410
	ctx.lr = 0x82778700;
	sub_82778410(ctx, base);
	// li r11,202
	r11.s64 = 202;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// b 0x82778758
	goto loc_82778758;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8277875c
	goto loc_8277875C;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277875c
	goto loc_8277875C;
loc_8277872C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778758;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778758:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8277875C:
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

PPC_WEAK_FUNC(sub_82778638) {
	__imp__sub_82778638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778774) {
	__imp__sub_82778774(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778778) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,205
	cr6.compare<int32_t>(r11.s32, 205, xer);
	// beq cr6,0x827787a0
	if (cr6.eq) goto loc_827787A0;
	// cmpwi cr6,r11,206
	cr6.compare<int32_t>(r11.s32, 206, xer);
	// bne cr6,0x827787fc
	if (!cr6.eq) goto loc_827787FC;
loc_827787A0:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827787fc
	if (!cr6.eq) goto loc_827787FC;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x827787dc
	if (!cr6.lt) goto loc_827787DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,67
	ctx.r10.s64 = 67;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827787DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827787DC:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827787F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,210
	ctx.r9.s64 = 210;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// b 0x82778844
	goto loc_82778844;
loc_827787FC:
	// cmpwi cr6,r11,207
	cr6.compare<int32_t>(r11.s32, 207, xer);
	// bne cr6,0x82778810
	if (!cr6.eq) goto loc_82778810;
	// li r11,210
	r11.s64 = 210;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// b 0x82778844
	goto loc_82778844;
loc_82778810:
	// cmpwi cr6,r11,210
	cr6.compare<int32_t>(r11.s32, 210, xer);
	// beq cr6,0x82778844
	if (cr6.eq) goto loc_82778844;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778844:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82778880
	if (!cr6.eq) goto loc_82778880;
loc_82778854:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827788b4
	if (cr6.eq) goto loc_827788B4;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778854
	if (cr6.eq) goto loc_82778854;
loc_82778880:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a1e8
	ctx.lr = 0x8277889C;
	sub_8277A1E8(ctx, base);
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
loc_827788B4:
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

PPC_WEAK_FUNC(sub_82778778) {
	__imp__sub_82778778(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827788CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827788CC) {
	__imp__sub_827788CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827788D0) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,200
	cr6.compare<int32_t>(r11.s32, 200, xer);
	// beq cr6,0x82778928
	if (cr6.eq) goto loc_82778928;
	// cmpwi cr6,r11,201
	cr6.compare<int32_t>(r11.s32, 201, xer);
	// beq cr6,0x82778928
	if (cr6.eq) goto loc_82778928;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778928:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778638
	ctx.lr = 0x82778930;
	sub_82778638(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8277897c
	if (cr6.eq) goto loc_8277897C;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82778980
	if (!cr6.eq) goto loc_82778980;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277896c
	if (cr6.eq) goto loc_8277896C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,51
	ctx.r10.s64 = 51;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277896C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277896C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a1e8
	ctx.lr = 0x82778974;
	sub_8277A1E8(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x82778980
	goto loc_82778980;
loc_8277897C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82778980:
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

PPC_WEAK_FUNC(sub_827788D0) {
	__imp__sub_827788D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778998) {
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
	ctx.lr = 0x827789A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,204
	cr6.compare<int32_t>(r11.s32, 204, xer);
	// beq cr6,0x827789d4
	if (cr6.eq) goto loc_827789D4;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827789C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,204
	ctx.r9.s64 = 204;
	// stw r29,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r29.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
loc_827789D4:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778aa4
	if (cr6.eq) goto loc_82778AA4;
	// addi r30,r31,120
	r30.s64 = r31.s64 + 120;
loc_827789E8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x82778a68
	if (!cr6.lt) goto loc_82778A68;
loc_827789F8:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778a28
	if (cr6.eq) goto loc_82778A28;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778A28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778A28:
	// lwz r11,388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778A4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x82778ac8
	if (cr6.eq) goto loc_82778AC8;
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x827789f8
	if (cr6.lt) goto loc_827789F8;
loc_82778A68:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lwz r7,384(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lbz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x827789e8
	if (!cr6.eq) goto loc_827789E8;
loc_82778AA4:
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r3,1
	ctx.r3.s64 = 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r8,r11,205
	ctx.r8.s64 = r11.s64 + 205;
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82778AC8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82778998) {
	__imp__sub_82778998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778AD4) {
	__imp__sub_82778AD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778AD8) {
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
	ctx.lr = 0x82778AE0;
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,205
	cr6.compare<int32_t>(r11.s32, 205, xer);
	// beq cr6,0x82778b24
	if (cr6.eq) goto loc_82778B24;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778B24:
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82778b64
	if (cr6.lt) goto loc_82778B64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,123
	ctx.r10.s64 = 123;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82778B64:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778b94
	if (cr6.eq) goto loc_82778B94;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778B94:
	// li r11,0
	r11.s64 = 0;
	// lwz r10,388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82778BBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// stw r8,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82778AD8) {
	__imp__sub_82778AD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778BD4) {
	__imp__sub_82778BD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778BD8) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,202
	cr6.compare<int32_t>(r11.s32, 202, xer);
	// bne cr6,0x82778c30
	if (!cr6.eq) goto loc_82778C30;
	// bl 0x8277c628
	ctx.lr = 0x82778BFC;
	sub_8277C628(ctx, base);
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778c28
	if (cr6.eq) goto loc_82778C28;
	// li r11,207
	r11.s64 = 207;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_82778C28:
	// li r11,203
	r11.s64 = 203;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_82778C30:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,203
	cr6.compare<int32_t>(r11.s32, 203, xer);
	// bne cr6,0x82778d00
	if (!cr6.eq) goto loc_82778D00;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778cf4
	if (cr6.eq) goto loc_82778CF4;
loc_82778C4C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778c68
	if (cr6.eq) goto loc_82778C68;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82778C68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778C68:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82778cdc
	if (cr6.eq) goto loc_82778CDC;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82778cf4
	if (cr6.eq) goto loc_82778CF4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778c4c
	if (cr6.eq) goto loc_82778C4C;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x82778ca8
	if (cr6.eq) goto loc_82778CA8;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82778c4c
	if (!cr6.eq) goto loc_82778C4C;
loc_82778CA8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x82778c4c
	if (cr6.lt) goto loc_82778C4C;
	// lwz r10,284(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// b 0x82778c4c
	goto loc_82778C4C;
loc_82778CDC:
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
loc_82778CF4:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// b 0x82778d34
	goto loc_82778D34;
loc_82778D00:
	// cmpwi cr6,r11,204
	cr6.compare<int32_t>(r11.s32, 204, xer);
	// beq cr6,0x82778d34
	if (cr6.eq) goto loc_82778D34;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778D34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778998
	ctx.lr = 0x82778D3C;
	sub_82778998(ctx, base);
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

PPC_WEAK_FUNC(sub_82778BD8) {
	__imp__sub_82778BD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778D50) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778D74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a250
	ctx.lr = 0x82778D7C;
	sub_8277A250(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823db0a0
	ctx.lr = 0x82778D84;
	sub_823DB0A0(ctx, base);
}

PPC_WEAK_FUNC(sub_82778D50) {
	__imp__sub_82778D50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778D84) {
	__imp__sub_82778D84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778D88) {
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
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
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
	ctx.lr = 0x82778DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// addi r30,r9,9028
	r30.s64 = ctx.r9.s64 + 9028;
	// bl 0x823e1160
	ctx.lr = 0x82778DC0;
	sub_823E1160(ctx, base);
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x827a7460
	ctx.lr = 0x82778DD0;
	sub_827A7460(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
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

PPC_WEAK_FUNC(sub_82778D88) {
	__imp__sub_82778D88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778DE8) {
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
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82778e48
	if (!cr6.lt) goto loc_82778E48;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82778e1c
	if (cr6.eq) goto loc_82778E1C;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x82778e28
	if (cr6.lt) goto loc_82778E28;
loc_82778E1C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82778E28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778E28:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
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
loc_82778E48:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// blt cr6,0x82778e60
	if (cr6.lt) goto loc_82778E60;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82778E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778E60:
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

PPC_WEAK_FUNC(sub_82778DE8) {
	__imp__sub_82778DE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778E74) {
	__imp__sub_82778E74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778E78) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82778ebc
	if (!cr6.gt) goto loc_82778EBC;
	// lwz r9,116(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bgt cr6,0x82778ebc
	if (cr6.gt) goto loc_82778EBC;
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// b 0x82778eec
	goto loc_82778EEC;
loc_82778EBC:
	// lwz r8,120(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82778ef4
	if (cr6.eq) goto loc_82778EF4;
	// lwz r9,124(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82778ef4
	if (cr6.lt) goto loc_82778EF4;
	// lwz r6,128(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82778ef4
	if (cr6.gt) goto loc_82778EF4;
	// subf r9,r9,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
loc_82778EEC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82778f00
	if (!cr6.eq) goto loc_82778F00;
loc_82778EF4:
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
loc_82778F00:
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82778f44
	if (cr6.eq) goto loc_82778F44;
loc_82778F18:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,37
	cr6.compare<int32_t>(ctx.r10.s32, 37, xer);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// beq cr6,0x82778f38
	if (cr6.eq) goto loc_82778F38;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82778f18
	if (!cr6.eq) goto loc_82778F18;
	// b 0x82778f44
	goto loc_82778F44;
loc_82778F38:
	// cmplwi cr6,r10,115
	cr6.compare<uint32_t>(ctx.r10.u32, 115, xer);
	// bne cr6,0x82778f44
	if (!cr6.eq) goto loc_82778F44;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82778F44:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778f60
	if (cr6.eq) goto loc_82778F60;
	// addi r5,r11,24
	ctx.r5.s64 = r11.s64 + 24;
	// bl 0x823dc018
	ctx.lr = 0x82778F5C;
	sub_823DC018(ctx, base);
	// b 0x82778f8c
	goto loc_82778F8C;
loc_82778F60:
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r30,48(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x82778F8C;
	sub_823DC018(ctx, base);
loc_82778F8C:
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

PPC_WEAK_FUNC(sub_82778E78) {
	__imp__sub_82778E78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82778FA4) {
	__imp__sub_82778FA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778FA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82778FA8) {
	__imp__sub_82778FA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82778FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// addi r4,r10,-29360
	ctx.r4.s64 = ctx.r10.s64 + -29360;
	// addi r10,r5,32656
	ctx.r10.s64 = ctx.r5.s64 + 32656;
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r9,r9,-29208
	ctx.r9.s64 = ctx.r9.s64 + -29208;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// addi r8,r8,-29304
	ctx.r8.s64 = ctx.r8.s64 + -29304;
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// addi r7,r7,-29064
	ctx.r7.s64 = ctx.r7.s64 + -29064;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r6,r6,-28760
	ctx.r6.s64 = ctx.r6.s64 + -28760;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r5,123
	ctx.r5.s64 = 123;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r5,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r5.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82778FC0) {
	__imp__sub_82778FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779030) {
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
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82779038;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// beq cr6,0x82779084
	if (cr6.eq) goto loc_82779084;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,62
	ctx.r9.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r4,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r4.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82779084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779084:
	// cmplwi cr6,r29,360
	cr6.compare<uint32_t>(r29.u32, 360, xer);
	// beq cr6,0x827790c0
	if (cr6.eq) goto loc_827790C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,21
	ctx.r10.s64 = 21;
	// li r9,360
	ctx.r9.s64 = 360;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827790C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827790C0:
	// li r5,360
	ctx.r5.s64 = 360;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x827790D8;
	sub_823D9890(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// bl 0x8277bbd8
	ctx.lr = 0x827790EC;
	sub_8277BBD8(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// addi r11,r31,104
	r11.s64 = r31.s64 + 104;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
loc_82779114:
	// stw r30,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82779114
	if (!cr0.eq) goto loc_82779114;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r30.u32);
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// lfd f0,21560(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 21560);
	// stfd f0,48(r31)
	PPC_STORE_U64(r31.u32 + 48, f0.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82779030) {
	__imp__sub_82779030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779158
	if (cr6.eq) goto loc_82779158;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779158:
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779168
	if (cr6.eq) goto loc_82779168;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779168:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779178
	if (cr6.eq) goto loc_82779178;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779178:
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779188
	if (cr6.eq) goto loc_82779188;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779188:
	// addi r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 + 104;
	// li r9,4
	ctx.r9.s64 = 4;
loc_82779190:
	// lwz r11,-16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827791a0
	if (cr6.eq) goto loc_827791A0;
	// stb r4,273(r11)
	PPC_STORE_U8(r11.u32 + 273, ctx.r4.u8);
loc_827791A0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827791b0
	if (cr6.eq) goto loc_827791B0;
	// stb r4,273(r11)
	PPC_STORE_U8(r11.u32 + 273, ctx.r4.u8);
loc_827791B0:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82779190
	if (!cr0.eq) goto loc_82779190;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82779148) {
	__imp__sub_82779148(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827791C0) {
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
	ctx.lr = 0x827791C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// beq cr6,0x82779214
	if (cr6.eq) goto loc_82779214;
	// cmpwi cr6,r11,102
	cr6.compare<int32_t>(r11.s32, 102, xer);
	// beq cr6,0x82779214
	if (cr6.eq) goto loc_82779214;
	// cmpwi cr6,r11,103
	cr6.compare<int32_t>(r11.s32, 103, xer);
	// beq cr6,0x82779258
	if (cr6.eq) goto loc_82779258;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x82779254
	goto loc_82779254;
loc_82779214:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x82779244
	if (!cr6.lt) goto loc_82779244;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,67
	ctx.r10.s64 = 67;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82779244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779244:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82779254:
	// bctrl 
	ctx.lr = 0x82779258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779258:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82779334
	if (!cr6.eq) goto loc_82779334;
	// li r29,24
	r29.s64 = 24;
loc_8277926C:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277927C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,224(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82779310
	if (!cr6.gt) goto loc_82779310;
loc_8277928C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827792c0
	if (cr6.eq) goto loc_827792C0;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827792C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827792C0:
	// lwz r11,328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827792D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82779300
	if (!cr6.eq) goto loc_82779300;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r29.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82779300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779300:
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8277928c
	if (cr6.lt) goto loc_8277928C;
loc_82779310:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82779324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lbz r9,13(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277926c
	if (cr6.eq) goto loc_8277926C;
loc_82779334:
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82779348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277935C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a1e8
	ctx.lr = 0x82779364;
	sub_8277A1E8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827791C0) {
	__imp__sub_827791C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277936C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277936C) {
	__imp__sub_8277936C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779370) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x827793c0
	if (cr6.eq) goto loc_827793C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827793C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827793C0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827793d8
	if (cr6.eq) goto loc_827793D8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779148
	ctx.lr = 0x827793D8;
	sub_82779148(ctx, base);
loc_827793D8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827793EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82779400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277db10
	ctx.lr = 0x82779408;
	sub_8277DB10(ctx, base);
	// lwz r7,316(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277941C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// li r5,0
	ctx.r5.s64 = 0;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// stw r5,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r5.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_82779370) {
	__imp__sub_82779370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82779454) {
	__imp__sub_82779454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779458) {
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
	ctx.lr = 0x82779460;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// beq cr6,0x827794a4
	if (cr6.eq) goto loc_827794A4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827794A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827794A4:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x827794d8
	if (cr6.lt) goto loc_827794D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,123
	ctx.r10.s64 = 123;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827794D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827794D8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277950c
	if (cr6.eq) goto loc_8277950C;
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277950C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277950C:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277952c
	if (cr6.eq) goto loc_8277952C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277952C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277952C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x82779544
	if (!cr6.gt) goto loc_82779544;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82779544:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277956C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// stw r8,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82779458) {
	__imp__sub_82779458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82779584) {
	__imp__sub_82779584(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779588) {
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
	ctx.lr = 0x82779590;
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
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x827795dc
	if (cr6.eq) goto loc_827795DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827795DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827795DC:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x827795ec
	if (cr6.lt) goto loc_827795EC;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x82779614
	if (cr6.lt) goto loc_82779614;
loc_827795EC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,31
	ctx.r10.s64 = 31;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r30.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82779614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779614:
	// addi r11,r30,18
	r11.s64 = r30.s64 + 18;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82779634
	if (!cr6.eq) goto loc_82779634;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a2a0
	ctx.lr = 0x82779630;
	sub_8277A2A0(ctx, base);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
loc_82779634:
	// clrlwi r5,r28,24
	ctx.r5.u64 = r28.u32 & 0xFF;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r29,8
	ctx.r8.s64 = r29.s64 + 8;
	// li r6,100
	ctx.r6.s64 = 100;
loc_82779644:
	// lwz r11,-8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// mullw r11,r11,r27
	r11.s64 = int64_t(r11.s32) * int64_t(r27.s32);
	// addi r10,r11,50
	ctx.r10.s64 = r11.s64 + 50;
	// divw. r11,r10,r6
	r11.s32 = ctx.r10.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x82779660
	if (cr0.gt) goto loc_82779660;
	// li r11,1
	r11.s64 = 1;
	// b 0x8277966c
	goto loc_8277966C;
loc_82779660:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x8277966c
	if (!cr6.gt) goto loc_8277966C;
	// li r11,32767
	r11.s64 = 32767;
loc_8277966C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82779680
	if (cr6.eq) goto loc_82779680;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x82779680
	if (!cr6.gt) goto loc_82779680;
	// li r11,255
	r11.s64 = 255;
loc_82779680:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// sthx r11,r10,r7
	PPC_STORE_U16(ctx.r10.u32 + ctx.r7.u32, r11.u16);
	// lwz r4,-4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mullw r11,r4,r27
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(r27.s32);
	// addi r3,r11,50
	ctx.r3.s64 = r11.s64 + 50;
	// divw. r11,r3,r6
	r11.s32 = ctx.r3.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827796a4
	if (cr0.gt) goto loc_827796A4;
	// li r11,1
	r11.s64 = 1;
	// b 0x827796b0
	goto loc_827796B0;
loc_827796A4:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x827796b0
	if (!cr6.gt) goto loc_827796B0;
	// li r11,32767
	r11.s64 = 32767;
loc_827796B0:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827796c4
	if (cr6.eq) goto loc_827796C4;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x827796c4
	if (!cr6.gt) goto loc_827796C4;
	// li r11,255
	r11.s64 = 255;
loc_827796C4:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mullw r11,r9,r27
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r27.s32);
	// addi r4,r11,50
	ctx.r4.s64 = r11.s64 + 50;
	// divw. r11,r4,r6
	r11.s32 = ctx.r4.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827796ec
	if (cr0.gt) goto loc_827796EC;
	// li r11,1
	r11.s64 = 1;
	// b 0x827796f8
	goto loc_827796F8;
loc_827796EC:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x827796f8
	if (!cr6.gt) goto loc_827796F8;
	// li r11,32767
	r11.s64 = 32767;
loc_827796F8:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8277970c
	if (cr6.eq) goto loc_8277970C;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x8277970c
	if (!cr6.gt) goto loc_8277970C;
	// li r11,255
	r11.s64 = 255;
loc_8277970C:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r7,6
	ctx.r9.s64 = ctx.r7.s64 + 6;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,-2(r10)
	PPC_STORE_U16(ctx.r10.u32 + -2, r11.u16);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mullw r11,r4,r27
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(r27.s32);
	// addi r3,r11,50
	ctx.r3.s64 = r11.s64 + 50;
	// divw. r11,r3,r6
	r11.s32 = ctx.r3.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x82779738
	if (cr0.gt) goto loc_82779738;
	// li r11,1
	r11.s64 = 1;
	// b 0x82779744
	goto loc_82779744;
loc_82779738:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x82779744
	if (!cr6.gt) goto loc_82779744;
	// li r11,32767
	r11.s64 = 32767;
loc_82779744:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82779758
	if (cr6.eq) goto loc_82779758;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x82779758
	if (!cr6.gt) goto loc_82779758;
	// li r11,255
	r11.s64 = 255;
loc_82779758:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpwi cr6,r7,128
	cr6.compare<int32_t>(ctx.r7.s32, 128, xer);
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
	// blt cr6,0x82779644
	if (cr6.lt) goto loc_82779644;
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82779588) {
	__imp__sub_82779588(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82779784) {
	__imp__sub_82779784(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779788) {
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
	ctx.lr = 0x82779790;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bgt cr6,0x827797bc
	if (cr6.gt) goto loc_827797BC;
	// li r11,1
	r11.s64 = 1;
	// li r10,5000
	ctx.r10.s64 = 5000;
	// twllei r11,0
	// divw r31,r10,r11
	r31.s32 = ctx.r10.s32 / r11.s32;
	// b 0x827797d0
	goto loc_827797D0;
loc_827797BC:
	// cmpwi cr6,r4,100
	cr6.compare<int32_t>(ctx.r4.s32, 100, xer);
	// ble cr6,0x82779810
	if (!cr6.gt) goto loc_82779810;
	// li r11,100
	r11.s64 = 100;
loc_827797C8:
	// subfic r11,r11,100
	xer.ca = r11.u32 <= 100;
	r11.s64 = 100 - r11.s64;
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_827797D0:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r30,r11,-32376
	r30.s64 = r11.s64 + -32376;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82779588
	ctx.lr = 0x827797F0;
	sub_82779588(ctx, base);
	// addi r5,r30,256
	ctx.r5.s64 = r30.s64 + 256;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82779588
	ctx.lr = 0x82779808;
	sub_82779588(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82779810:
	// cmpwi cr6,r4,50
	cr6.compare<int32_t>(ctx.r4.s32, 50, xer);
	// bge cr6,0x827797c8
	if (!cr6.lt) goto loc_827797C8;
	// li r10,5000
	ctx.r10.s64 = 5000;
	// twllei r11,0
	// divw r31,r10,r11
	r31.s32 = ctx.r10.s32 / r11.s32;
	// b 0x827797d0
	goto loc_827797D0;
}

PPC_WEAK_FUNC(sub_82779788) {
	__imp__sub_82779788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779828) {
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
	ctx.lr = 0x82779830;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82779858
	if (!cr6.eq) goto loc_82779858;
	// bl 0x8277a2e0
	ctx.lr = 0x82779854;
	sub_8277A2E0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82779858:
	// li r5,17
	ctx.r5.s64 = 17;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82779868;
	sub_823DA950(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// li r10,4
	ctx.r10.s64 = 4;
loc_82779874:
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// bne 0x82779874
	if (!cr0.eq) goto loc_82779874;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// blt cr6,0x827798b0
	if (cr6.lt) goto loc_827798B0;
	// cmpwi cr6,r31,256
	cr6.compare<int32_t>(r31.s32, 256, xer);
	// ble cr6,0x827798d0
	if (!cr6.gt) goto loc_827798D0;
loc_827798B0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827798D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827798D0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,17
	ctx.r3.s64 = r11.s64 + 17;
	// bl 0x823da950
	ctx.lr = 0x827798E4;
	sub_823DA950(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stb r11,273(r10)
	PPC_STORE_U8(ctx.r10.u32 + 273, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82779828) {
	__imp__sub_82779828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827798F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82779900;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779940
	if (cr6.eq) goto loc_82779940;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779940:
	// li r31,0
	r31.s64 = 0;
	// stw r29,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r29.u32);
	// cmplwi cr6,r29,5
	cr6.compare<uint32_t>(r29.u32, 5, xer);
	// stb r31,196(r30)
	PPC_STORE_U8(r30.u32 + 196, r31.u8);
	// stb r31,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r31.u8);
	// bgt cr6,0x82779c6c
	if (cr6.gt) goto loc_82779C6C;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-26256
	r12.s64 = r12.s64 + -26256;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-25656(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25656);
	// lwz r19,-26232(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -26232);
	// lwz r19,-26184(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -26184);
	// lwz r19,-26064(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -26064);
	// lwz r19,-25952(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25952);
	// lwz r19,-25800(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25800);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// stb r11,196(r30)
	PPC_STORE_U8(r30.u32 + 196, r11.u8);
	// stw r11,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r11.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,82
	ctx.r8.s64 = 82;
	// stb r11,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r11.u8);
	// stw r9,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r9.u32);
	// li r7,71
	ctx.r7.s64 = 71;
	// li r6,66
	ctx.r6.s64 = 66;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r7,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r7.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// stw r31,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r31.u32);
	// stw r31,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r31.u32);
	// stw r31,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r6,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r6.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r31,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r31.u32);
	// stw r31,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r31.u32);
	// stw r31,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,196(r30)
	PPC_STORE_U8(r30.u32 + 196, r11.u8);
	// stw r8,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r8.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// stw r31,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r31.u32);
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r10,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r10.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// stw r11,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, r11.u32);
	// stw r11,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, r11.u32);
	// stw r11,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, r11.u32);
	// stw r11,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r11.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r8,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r8.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r11,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r11.u32);
	// stw r11,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r11.u32);
	// stw r11,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,67
	ctx.r8.s64 = 67;
	// stb r11,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r11.u8);
	// stw r9,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r9.u32);
	// li r7,77
	ctx.r7.s64 = 77;
	// li r6,89
	ctx.r6.s64 = 89;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// li r5,75
	ctx.r5.s64 = 75;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r7,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r7.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// stw r31,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r31.u32);
	// stw r31,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r31.u32);
	// stw r31,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r6,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r6.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r31,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r31.u32);
	// stw r31,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r31.u32);
	// stw r31,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r5,252(r10)
	PPC_STORE_U32(ctx.r10.u32 + 252, ctx.r5.u32);
	// stw r11,260(r10)
	PPC_STORE_U32(ctx.r10.u32 + 260, r11.u32);
	// stw r11,264(r10)
	PPC_STORE_U32(ctx.r10.u32 + 264, r11.u32);
	// stw r31,268(r10)
	PPC_STORE_U32(ctx.r10.u32 + 268, r31.u32);
	// stw r31,272(r10)
	PPC_STORE_U32(ctx.r10.u32 + 272, r31.u32);
	// stw r31,276(r10)
	PPC_STORE_U32(ctx.r10.u32 + 276, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r11.u8);
	// stw r8,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// stw r31,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r31.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r10,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r10.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// stw r11,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, r11.u32);
	// stw r11,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, r11.u32);
	// stw r11,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, r11.u32);
	// stw r11,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r11.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r7,168(r9)
	PPC_STORE_U32(ctx.r9.u32 + 168, ctx.r7.u32);
	// stw r11,176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 176, r11.u32);
	// stw r11,180(r9)
	PPC_STORE_U32(ctx.r9.u32 + 180, r11.u32);
	// stw r11,184(r9)
	PPC_STORE_U32(ctx.r9.u32 + 184, r11.u32);
	// stw r11,188(r9)
	PPC_STORE_U32(ctx.r9.u32 + 188, r11.u32);
	// stw r11,192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 192, r11.u32);
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r8,252(r11)
	PPC_STORE_U32(r11.u32 + 252, ctx.r8.u32);
	// stw r10,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r10.u32);
	// stw r10,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r10.u32);
	// stw r31,268(r11)
	PPC_STORE_U32(r11.u32 + 268, r31.u32);
	// stw r31,272(r11)
	PPC_STORE_U32(r11.u32 + 272, r31.u32);
	// stw r31,276(r11)
	PPC_STORE_U32(r11.u32 + 276, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r11.u32);
	// blt cr6,0x82779be0
	if (cr6.lt) goto loc_82779BE0;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x82779c18
	if (!cr6.gt) goto loc_82779C18;
loc_82779BE0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,10
	ctx.r9.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,60(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82779C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779C18:
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82779c8c
	if (!cr6.gt) goto loc_82779C8C;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r11,1
	r11.s64 = 1;
loc_82779C30:
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r8,r8,84
	ctx.r8.s64 = ctx.r8.s64 + 84;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x82779c30
	if (cr6.lt) goto loc_82779C30;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82779C6C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,10
	ctx.r10.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82779C8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779C8C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827798F8) {
	__imp__sub_827798F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82779C94) {
	__imp__sub_82779C94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82779C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
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
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8277a014
	if (cr6.gt) goto loc_8277A014;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-25392
	r12.s64 = r12.s64 + -25392;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-24588(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -24588);
	// lwz r19,-25368(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25368);
	// lwz r19,-25240(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25240);
	// lwz r19,-25240(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25240);
	// lwz r19,-25048(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25048);
	// lwz r19,-24816(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -24816);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779d20
	if (cr6.eq) goto loc_82779D20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779D20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779D20:
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stb r10,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r10.u8);
	// stb r11,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r11.u8);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r10,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779da0
	if (cr6.eq) goto loc_82779DA0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779DA0:
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,3
	ctx.r8.s64 = 3;
	// stb r11,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r11.u8);
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r10,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r10.u8);
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// stw r9,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r9.u32);
	// stw r10,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// stw r10,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r10.u32);
	// stw r10,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r10.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r9,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r9.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// stw r11,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r11.u32);
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r8,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r8.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r11,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r11.u32);
	// stw r11,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r11.u32);
	// stw r11,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r11.u32);
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779e60
	if (cr6.eq) goto loc_82779E60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779E60:
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// stb r10,196(r31)
	PPC_STORE_U8(r31.u32 + 196, ctx.r10.u8);
	// li r8,67
	ctx.r8.s64 = 67;
	// stb r11,204(r31)
	PPC_STORE_U8(r31.u32 + 204, r11.u8);
	// stw r7,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r7.u32);
	// li r6,77
	ctx.r6.s64 = 77;
	// stw r7,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r7.u32);
	// li r5,89
	ctx.r5.s64 = 89;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r4,75
	ctx.r4.s64 = 75;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r10,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r6,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r6.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// stw r11,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, r11.u32);
	// stw r10,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, ctx.r10.u32);
	// stw r10,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, ctx.r10.u32);
	// stw r10,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, ctx.r10.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r5,168(r9)
	PPC_STORE_U32(ctx.r9.u32 + 168, ctx.r5.u32);
	// stw r11,176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 176, r11.u32);
	// stw r11,180(r9)
	PPC_STORE_U32(ctx.r9.u32 + 180, r11.u32);
	// stw r10,184(r9)
	PPC_STORE_U32(ctx.r9.u32 + 184, ctx.r10.u32);
	// stw r10,188(r9)
	PPC_STORE_U32(ctx.r9.u32 + 188, ctx.r10.u32);
	// stw r10,192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 192, ctx.r10.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r4,252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 252, ctx.r4.u32);
	// stw r11,260(r9)
	PPC_STORE_U32(ctx.r9.u32 + 260, r11.u32);
	// stw r11,264(r9)
	PPC_STORE_U32(ctx.r9.u32 + 264, r11.u32);
	// stw r10,268(r9)
	PPC_STORE_U32(ctx.r9.u32 + 268, ctx.r10.u32);
	// stw r10,272(r9)
	PPC_STORE_U32(ctx.r9.u32 + 272, ctx.r10.u32);
	// stw r10,276(r9)
	PPC_STORE_U32(ctx.r9.u32 + 276, ctx.r10.u32);
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779f48
	if (cr6.eq) goto loc_82779F48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779F48:
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// stb r11,204(r31)
	PPC_STORE_U8(r31.u32 + 204, r11.u8);
	// li r6,5
	ctx.r6.s64 = 5;
	// stb r10,196(r31)
	PPC_STORE_U8(r31.u32 + 196, ctx.r10.u8);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r7,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r7.u32);
	// stw r6,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r6.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r9,84(r8)
	PPC_STORE_U32(ctx.r8.u32 + 84, ctx.r9.u32);
	// stw r11,92(r8)
	PPC_STORE_U32(ctx.r8.u32 + 92, r11.u32);
	// stw r11,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, r11.u32);
	// stw r11,100(r8)
	PPC_STORE_U32(ctx.r8.u32 + 100, r11.u32);
	// stw r11,104(r8)
	PPC_STORE_U32(ctx.r8.u32 + 104, r11.u32);
	// stw r11,108(r8)
	PPC_STORE_U32(ctx.r8.u32 + 108, r11.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r5,168(r8)
	PPC_STORE_U32(ctx.r8.u32 + 168, ctx.r5.u32);
	// stw r11,176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 176, r11.u32);
	// stw r11,180(r8)
	PPC_STORE_U32(ctx.r8.u32 + 180, r11.u32);
	// stw r11,184(r8)
	PPC_STORE_U32(ctx.r8.u32 + 184, r11.u32);
	// stw r11,188(r8)
	PPC_STORE_U32(ctx.r8.u32 + 188, r11.u32);
	// stw r11,192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 192, r11.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r7,252(r11)
	PPC_STORE_U32(r11.u32 + 252, ctx.r7.u32);
	// stw r9,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r9.u32);
	// stw r9,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r9.u32);
	// stw r10,268(r11)
	PPC_STORE_U32(r11.u32 + 268, ctx.r10.u32);
	// stw r10,272(r11)
	PPC_STORE_U32(r11.u32 + 272, ctx.r10.u32);
	// stw r10,276(r11)
	PPC_STORE_U32(r11.u32 + 276, ctx.r10.u32);
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827798f8
	ctx.lr = 0x8277A000;
	sub_827798F8(ctx, base);
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
loc_8277A014:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,9
	ctx.r10.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277A034;
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
}

PPC_WEAK_FUNC(sub_82779C98) {
	__imp__sub_82779C98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A048) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x8277a094
	if (cr6.eq) goto loc_8277A094;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277A094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A094:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277a0c0
	if (!cr6.eq) goto loc_8277A0C0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,840
	ctx.r5.s64 = 840;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A0BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
loc_8277A0C0:
	// li r11,8
	r11.s64 = 8;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r30,r10,-32376
	r30.s64 = ctx.r10.s64 + -32376;
	// li r6,50
	ctx.r6.s64 = 50;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779588
	ctx.lr = 0x8277A0E8;
	sub_82779588(ctx, base);
	// addi r5,r30,256
	ctx.r5.s64 = r30.s64 + 256;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,50
	ctx.r6.s64 = 50;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779588
	ctx.lr = 0x8277A100;
	sub_82779588(ctx, base);
	// addi r6,r30,532
	ctx.r6.s64 = r30.s64 + 532;
	// addi r5,r30,512
	ctx.r5.s64 = r30.s64 + 512;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A114;
	sub_82779828(ctx, base);
	// addi r6,r30,600
	ctx.r6.s64 = r30.s64 + 600;
	// addi r5,r30,576
	ctx.r5.s64 = r30.s64 + 576;
	// addi r4,r31,104
	ctx.r4.s64 = r31.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A128;
	sub_82779828(ctx, base);
	// addi r6,r30,564
	ctx.r6.s64 = r30.s64 + 564;
	// addi r5,r30,544
	ctx.r5.s64 = r30.s64 + 544;
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A13C;
	sub_82779828(ctx, base);
	// addi r6,r30,784
	ctx.r6.s64 = r30.s64 + 784;
	// addi r5,r30,764
	ctx.r5.s64 = r30.s64 + 764;
	// addi r4,r31,108
	ctx.r4.s64 = r31.s64 + 108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A150;
	sub_82779828(ctx, base);
	// addi r11,r31,136
	r11.s64 = r31.s64 + 136;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,5
	ctx.r7.s64 = 5;
loc_8277A164:
	// stb r10,-16(r11)
	PPC_STORE_U8(r11.u32 + -16, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// stb r7,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x8277a164
	if (!cr0.eq) goto loc_8277A164;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r10,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r10.u32);
	// stw r10,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r10.u32);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// stb r10,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r10.u8);
	// stb r10,177(r31)
	PPC_STORE_U8(r31.u32 + 177, ctx.r10.u8);
	// stb r10,178(r31)
	PPC_STORE_U8(r31.u32 + 178, ctx.r10.u8);
	// ble cr6,0x8277a1a0
	if (!cr6.gt) goto loc_8277A1A0;
	// stb r8,178(r31)
	PPC_STORE_U8(r31.u32 + 178, ctx.r8.u8);
loc_8277A1A0:
	// stb r10,179(r31)
	PPC_STORE_U8(r31.u32 + 179, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// stw r10,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r10.u32);
	// stw r10,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r10.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
	// stb r8,197(r31)
	PPC_STORE_U8(r31.u32 + 197, ctx.r8.u8);
	// stb r8,198(r31)
	PPC_STORE_U8(r31.u32 + 198, ctx.r8.u8);
	// stb r10,199(r31)
	PPC_STORE_U8(r31.u32 + 199, ctx.r10.u8);
	// sth r8,200(r31)
	PPC_STORE_U16(r31.u32 + 200, ctx.r8.u16);
	// sth r8,202(r31)
	PPC_STORE_U16(r31.u32 + 202, ctx.r8.u16);
	// bl 0x82779c98
	ctx.lr = 0x8277A1D0;
	sub_82779C98(ctx, base);
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

PPC_WEAK_FUNC(sub_8277A048) {
	__imp__sub_8277A048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A1E8) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277a23c
	if (cr6.eq) goto loc_8277A23C;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277A218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277a234
	if (cr6.eq) goto loc_8277A234;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,200
	r11.s64 = 200;
	// stw r10,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r10.u32);
	// b 0x8277a238
	goto loc_8277A238;
loc_8277A234:
	// li r11,100
	r11.s64 = 100;
loc_8277A238:
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8277A23C:
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

PPC_WEAK_FUNC(sub_8277A1E8) {
	__imp__sub_8277A1E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A250) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277a27c
	if (cr6.eq) goto loc_8277A27C;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277A27C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A27C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
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

PPC_WEAK_FUNC(sub_8277A250) {
	__imp__sub_8277A250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A29C) {
	__imp__sub_8277A29C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A2A0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,130
	ctx.r5.s64 = 130;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A2C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,128(r3)
	PPC_STORE_U8(ctx.r3.u32 + 128, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277A2A0) {
	__imp__sub_8277A2A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A2DC) {
	__imp__sub_8277A2DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A2E0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,274
	ctx.r5.s64 = 274;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,273(r3)
	PPC_STORE_U8(ctx.r3.u32 + 273, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277A2E0) {
	__imp__sub_8277A2E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A31C) {
	__imp__sub_8277A31C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// twllei r4,0
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r3,r10,r4
	ctx.r3.s32 = ctx.r10.s32 / ctx.r4.s32;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// andc r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277A320) {
	__imp__sub_8277A320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A344) {
	__imp__sub_8277A344(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// twllei r4,0
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// divw r9,r11,r4
	ctx.r9.s32 = r11.s32 / ctx.r4.s32;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r8,r9,r4
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// subf r6,r8,r11
	ctx.r6.s64 = r11.s64 - ctx.r8.s64;
	// andc r5,r4,r7
	ctx.r5.u64 = ctx.r4.u64 & ~ctx.r7.u64;
	// subf r3,r6,r11
	ctx.r3.s64 = r11.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277A348) {
	__imp__sub_8277A348(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A378) {
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
	ctx.lr = 0x8277A380;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
	// add r30,r10,r5
	r30.u64 = ctx.r10.u64 + ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8277a3c4
	if (!cr6.gt) goto loc_8277A3C4;
loc_8277A3A4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x8277A3BC;
	sub_823DA950(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bgt 0x8277a3a4
	if (cr0.gt) goto loc_8277A3A4;
loc_8277A3C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8277A378) {
	__imp__sub_8277A378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A3CC) {
	__imp__sub_8277A3CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm r5,r5,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x823da950
	sub_823DA950(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8277A3D0) {
	__imp__sub_8277A3D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A3E4) {
	__imp__sub_8277A3E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A3E8) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8277A3E8) {
	__imp__sub_8277A3E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A3F4) {
	__imp__sub_8277A3F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A3F8) {
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
	ctx.lr = 0x8277A400;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,0
	r11.s64 = 0;
	// ori r11,r11,65500
	r11.u64 = r11.u64 | 65500;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x8277a428
	if (cr6.gt) goto loc_8277A428;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8277a450
	if (!cr6.gt) goto loc_8277A450;
loc_8277A428:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,41
	ctx.r9.s64 = 41;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, r11.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277A450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A450:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x8277a488
	if (cr6.eq) goto loc_8277A488;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,15
	ctx.r10.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277A488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A488:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x8277a4cc
	if (!cr6.gt) goto loc_8277A4CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,10
	ctx.r9.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r8,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r8.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8277A4CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A4CC:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r27,1
	r27.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// stw r27,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r27.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r29,r26
	r29.u64 = r26.u64;
	// stw r27,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r27.u32);
	// ble cr6,0x8277a580
	if (!cr6.gt) goto loc_8277A580;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r28,18
	r28.s64 = 18;
loc_8277A4F8:
	// lwz r11,-4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a520
	if (!cr6.gt) goto loc_8277A520;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bgt cr6,0x8277a520
	if (cr6.gt) goto loc_8277A520;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a520
	if (!cr6.gt) goto loc_8277A520;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x8277a53c
	if (!cr6.gt) goto loc_8277A53C;
loc_8277A520:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277A53C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A53C:
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8277a550
	if (cr6.gt) goto loc_8277A550;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277A550:
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8277a568
	if (cr6.gt) goto loc_8277A568;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277A568:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277a4f8
	if (cr6.lt) goto loc_8277A4F8;
loc_8277A580:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r28,8
	r28.s64 = 8;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r29,r26
	r29.u64 = r26.u64;
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277a628
	if (!cr6.gt) goto loc_8277A628;
	// addi r30,r11,28
	r30.s64 = r11.s64 + 28;
loc_8277A5A0:
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// lwz r11,-20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,272(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// mullw r3,r11,r10
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A5BC;
	sub_8277A320(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r8,-16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// lwz r7,276(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// rlwinm r4,r7,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mullw r3,r8,r6
	ctx.r3.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277A5D8;
	sub_8277A320(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lwz r4,272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r5,-20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -20);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mullw r3,r5,r3
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277A5F0;
	sub_8277A320(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// lwz r4,276(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r11,-16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mullw r3,r11,r10
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277A608;
	sub_8277A320(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// stb r27,20(r30)
	PPC_STORE_U8(r30.u32 + 20, r27.u8);
	// stw r26,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r26.u32);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277a5a0
	if (cr6.lt) goto loc_8277A5A0;
loc_8277A628:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A638;
	sub_8277A320(ctx, base);
	// lwz r10,292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r3,284(r31)
	PPC_STORE_U32(r31.u32 + 284, ctx.r3.u32);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277a668
	if (cr6.lt) goto loc_8277A668;
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277a668
	if (!cr6.eq) goto loc_8277A668;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stb r26,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8277A668:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277A3F8) {
	__imp__sub_8277A3F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A678) {
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
	ctx.lr = 0x8277A680;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8277a6fc
	if (!cr6.eq) goto loc_8277A6FC;
	// lwz r11,296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r9,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r9.u32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stw r8,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r8.u32);
	// lwz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// twllei r9,0
	// divwu r5,r6,r9
	ctx.r5.u32 = ctx.r6.u32 / ctx.r9.u32;
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// stw r7,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r7.u32);
	// stw r10,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r10.u32);
	// subf. r8,r4,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r4.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8277a6e4
	if (!cr0.eq) goto loc_8277A6E4;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_8277A6E4:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r8.u32);
	// stw r10,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r10.u32);
	// stw r9,324(r31)
	PPC_STORE_U32(r31.u32 + 324, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277A6FC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a70c
	if (!cr6.gt) goto loc_8277A70C;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x8277a744
	if (!cr6.gt) goto loc_8277A744;
loc_8277A70C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,4
	ctx.r9.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r7,292(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8277A744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A744:
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A754;
	sub_8277A320(ctx, base);
	// stw r3,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r3.u32);
	// lwz r10,276(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r4,r10,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A768;
	sub_8277A320(ctx, base);
	// lwz r9,292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// li r29,0
	r29.s64 = 0;
	// stw r3,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r3.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r29,320(r31)
	PPC_STORE_U32(r31.u32 + 320, r29.u32);
	// ble cr6,0x8277a85c
	if (!cr6.gt) goto loc_8277A85C;
	// addi r28,r31,296
	r28.s64 = r31.s64 + 296;
	// li r27,13
	r27.s64 = 13;
loc_8277A788:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// twllei r10,0
	// lwz r6,36(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// divwu r7,r8,r10
	ctx.r7.u32 = ctx.r8.u32 / ctx.r10.u32;
	// mullw r30,r9,r10
	r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r30,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r30.u32);
	// stw r9,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r9.u32);
	// mullw r5,r7,r10
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r6,r10
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r4,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r4.u32);
	// subf. r8,r5,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8277a7cc
	if (!cr0.eq) goto loc_8277A7CC;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_8277A7CC:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// twllei r9,0
	// stw r8,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r8.u32);
	// divwu r8,r10,r9
	ctx.r8.u32 = ctx.r10.u32 / ctx.r9.u32;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subf. r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8277a7ec
	if (!cr0.eq) goto loc_8277A7EC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8277A7EC:
	// stw r10,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r10.u32);
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x8277a81c
	if (!cr6.gt) goto loc_8277A81C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277A81C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A81C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8277a848
	if (!cr6.gt) goto loc_8277A848;
loc_8277A824:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,81
	r11.s64 = r11.s64 + 81;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r29.u32);
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r9.u32);
	// bgt 0x8277a824
	if (cr0.gt) goto loc_8277A824;
loc_8277A848:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277a788
	if (cr6.lt) goto loc_8277A788;
loc_8277A85C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8277A678) {
	__imp__sub_8277A678(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A864) {
	__imp__sub_8277A864(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A868) {
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
	ctx.lr = 0x8277A870;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a938
	if (!cr6.gt) goto loc_8277A938;
	// addi r28,r31,296
	r28.s64 = r31.s64 + 296;
	// li r26,52
	r26.s64 = 52;
loc_8277A890:
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277a924
	if (!cr6.eq) goto loc_8277A924;
	// lwz r30,16(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8277a8c8
	if (cr6.lt) goto loc_8277A8C8;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bge cr6,0x8277a8c8
	if (!cr6.lt) goto loc_8277A8C8;
	// addi r11,r30,36
	r11.s64 = r30.s64 + 36;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8277a8ec
	if (!cr6.eq) goto loc_8277A8EC;
loc_8277A8C8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r30.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277A8EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A8EC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,130
	ctx.r5.s64 = 130;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r30,36
	ctx.r9.s64 = r30.s64 + 36;
	// li r5,130
	ctx.r5.s64 = 130;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x823da950
	ctx.lr = 0x8277A920;
	sub_823DA950(ctx, base);
	// stw r30,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r30.u32);
loc_8277A924:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8277a890
	if (cr6.lt) goto loc_8277A890;
loc_8277A938:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277A868) {
	__imp__sub_8277A868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A940) {
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
	// bl 0x8277a678
	ctx.lr = 0x8277A958;
	sub_8277A678(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a868
	ctx.lr = 0x8277A960;
	sub_8277A868(ctx, base);
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277A988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,392(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r6,400(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
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

PPC_WEAK_FUNC(sub_8277A940) {
	__imp__sub_8277A940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277A9AC) {
	__imp__sub_8277A9AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277A9B0) {
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
	ctx.lr = 0x8277A9B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,400(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r11,17(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277a9dc
	if (cr6.eq) goto loc_8277A9DC;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277A9DC:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A9F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8277aa74
	if (cr6.eq) goto loc_8277AA74;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x8277aad0
	if (!cr6.eq) goto loc_8277AAD0;
	// lbz r11,20(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r10,17(r30)
	PPC_STORE_U8(r30.u32 + 17, ctx.r10.u8);
	// beq cr6,0x8277aa54
	if (cr6.eq) goto loc_8277AA54;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277aad0
	if (cr6.eq) goto loc_8277AAD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,59
	ctx.r10.s64 = 59;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AA48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277AA54:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8277aad0
	if (!cr6.gt) goto loc_8277AAD0;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277AA74:
	// lbz r11,20(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277aa9c
	if (cr6.eq) goto loc_8277AA9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a3f8
	ctx.lr = 0x8277AA88;
	sub_8277A3F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r11,20(r30)
	PPC_STORE_U8(r30.u32 + 20, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277AA9C:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277aac8
	if (!cr6.eq) goto loc_8277AAC8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,35
	ctx.r10.s64 = 35;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AAC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AAC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a940
	ctx.lr = 0x8277AAD0;
	sub_8277A940(ctx, base);
loc_8277AAD0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8277A9B0) {
	__imp__sub_8277A9B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277AADC) {
	__imp__sub_8277AADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AAE0) {
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
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// li r31,0
	r31.s64 = 0;
	// addi r9,r10,-22096
	ctx.r9.s64 = ctx.r10.s64 + -22096;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,400(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 400);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stb r31,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r31.u8);
	// stb r31,17(r11)
	PPC_STORE_U8(r11.u32 + 17, r31.u8);
	// stb r8,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r8.u8);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277AB2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,404(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 404);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8277AB40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,140(r30)
	PPC_STORE_U32(r30.u32 + 140, r31.u32);
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

PPC_WEAK_FUNC(sub_8277AAE0) {
	__imp__sub_8277AAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277AB5C) {
	__imp__sub_8277AB5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AB60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,400(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r10,-22096
	ctx.r9.s64 = ctx.r10.s64 + -22096;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277AB60) {
	__imp__sub_8277AB60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277AB74) {
	__imp__sub_8277AB74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AB78) {
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
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277ABA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r3,400(r31)
	PPC_STORE_U32(r31.u32 + 400, ctx.r3.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// addi r5,r9,-22096
	ctx.r5.s64 = ctx.r9.s64 + -22096;
	// addi r4,r8,-21792
	ctx.r4.s64 = ctx.r8.s64 + -21792;
	// li r11,0
	r11.s64 = 0;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// addi r10,r7,-22208
	ctx.r10.s64 = ctx.r7.s64 + -22208;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r9,r6,-21664
	ctx.r9.s64 = ctx.r6.s64 + -21664;
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stb r11,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, r11.u8);
	// stb r8,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r8.u8);
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

PPC_WEAK_FUNC(sub_8277AB78) {
	__imp__sub_8277AB78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AC00) {
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
	ctx.lr = 0x8277AC08;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r25,4(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r22,54
	r22.s64 = 54;
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// ble cr6,0x8277ac54
	if (!cr6.gt) goto loc_8277AC54;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AC54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AC54:
	// clrlwi r11,r26,29
	r11.u64 = r26.u32 & 0x7;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ac68
	if (cr6.eq) goto loc_8277AC68;
	// subf r11,r11,r26
	r11.s64 = r26.s64 - r11.s64;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
loc_8277AC68:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277ac78
	if (cr6.lt) goto loc_8277AC78;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x8277aca0
	if (cr6.lt) goto loc_8277ACA0;
loc_8277AC78:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277ACA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277ACA0:
	// addi r11,r31,13
	r11.s64 = r31.s64 + 13;
	// li r24,0
	r24.s64 = 0;
	// rlwinm r23,r11,2,0,29
	r23.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r24
	r27.u64 = r24.u64;
	// lwzx r11,r23,r25
	r11.u64 = PPC_LOAD_U32(r23.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277acd8
	if (cr6.eq) goto loc_8277ACD8;
loc_8277ACBC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r26
	cr6.compare<uint32_t>(ctx.r10.u32, r26.u32, xer);
	// bge cr6,0x8277adb0
	if (!cr6.lt) goto loc_8277ADB0;
	// mr r27,r11
	r27.u64 = r11.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277acbc
	if (!cr6.eq) goto loc_8277ACBC;
loc_8277ACD8:
	// addi r29,r26,16
	r29.s64 = r26.s64 + 16;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bne cr6,0x8277acf4
	if (!cr6.eq) goto loc_8277ACF4;
	// addi r9,r11,-31104
	ctx.r9.s64 = r11.s64 + -31104;
	// b 0x8277acfc
	goto loc_8277ACFC;
loc_8277ACF4:
	// addi r11,r11,-31104
	r11.s64 = r11.s64 + -31104;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
loc_8277ACFC:
	// lis r11,15258
	r11.s64 = 999948288;
	// lwzx r31,r10,r9
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// ori r10,r11,51712
	ctx.r10.u64 = r11.u64 | 51712;
	// subf r11,r29,r10
	r11.s64 = ctx.r10.s64 - r29.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// ble cr6,0x8277ad18
	if (!cr6.gt) goto loc_8277AD18;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8277AD18:
	// add r4,r31,r29
	ctx.r4.u64 = r31.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277AD24;
	sub_8277DC20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277ad7c
	if (!cr6.eq) goto loc_8277AD7C;
	// li r28,2
	r28.s64 = 2;
loc_8277AD34:
	// rlwinm r31,r31,31,1,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,50
	cr6.compare<uint32_t>(r31.u32, 50, xer);
	// bge cr6,0x8277ad64
	if (!cr6.lt) goto loc_8277AD64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AD64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AD64:
	// add r4,r31,r29
	ctx.r4.u64 = r31.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277AD70;
	sub_8277DC20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ad34
	if (cr6.eq) goto loc_8277AD34;
loc_8277AD7C:
	// lwz r10,76(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// add r9,r31,r26
	ctx.r9.u64 = r31.u64 + r26.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + r29.u64;
	// stw r8,76(r25)
	PPC_STORE_U32(r25.u32 + 76, ctx.r8.u32);
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
	// stw r24,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r24.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// bne cr6,0x8277adac
	if (!cr6.eq) goto loc_8277ADAC;
	// stwx r11,r23,r25
	PPC_STORE_U32(r23.u32 + r25.u32, r11.u32);
	// b 0x8277adb0
	goto loc_8277ADB0;
loc_8277ADAC:
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_8277ADB0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// add r7,r10,r26
	ctx.r7.u64 = ctx.r10.u64 + r26.u64;
	// subf r6,r26,r8
	ctx.r6.s64 = ctx.r8.s64 - r26.s64;
	// addi r3,r9,16
	ctx.r3.s64 = ctx.r9.s64 + 16;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_8277AC00) {
	__imp__sub_8277AC00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277ADD8) {
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
	ctx.lr = 0x8277ADE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r28,4(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r26,54
	r26.s64 = 54;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8277ae2c
	if (!cr6.gt) goto loc_8277AE2C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AE2C:
	// clrlwi r11,r29,29
	r11.u64 = r29.u32 & 0x7;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ae40
	if (cr6.eq) goto loc_8277AE40;
	// subf r11,r11,r29
	r11.s64 = r29.s64 - r11.s64;
	// addi r29,r11,8
	r29.s64 = r11.s64 + 8;
loc_8277AE40:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8277ae50
	if (cr6.lt) goto loc_8277AE50;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// blt cr6,0x8277ae78
	if (cr6.lt) goto loc_8277AE78;
loc_8277AE50:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r27,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r27.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AE78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AE78:
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277AE84;
	sub_8277DC20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277aeb8
	if (!cr6.eq) goto loc_8277AEB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AEB8:
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// addi r9,r27,15
	ctx.r9.s64 = r27.s64 + 15;
	// li r8,0
	ctx.r8.s64 = 0;
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r7,76(r28)
	PPC_STORE_U32(r28.u32 + 76, ctx.r7.u32);
	// lwzx r6,r11,r28
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stwx r31,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277ADD8) {
	__imp__sub_8277ADD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277AEF4) {
	__imp__sub_8277AEF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AEF8) {
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
	ctx.lr = 0x8277AF00;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lwz r30,4(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// divwu. r31,r10,r28
	r31.u32 = ctx.r10.u32 / r28.u32;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// twllei r28,0
	// bgt 0x8277af48
	if (cr0.gt) goto loc_8277AF48;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r10,70
	ctx.r10.s64 = 70;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AF48:
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x8277af54
	if (cr6.lt) goto loc_8277AF54;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8277AF54:
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277AF68;
	sub_8277AC00(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8277afc8
	if (cr6.eq) goto loc_8277AFC8;
loc_8277AF78:
	// subf r11,r30,r29
	r11.s64 = r29.s64 - r30.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x8277af88
	if (cr6.lt) goto loc_8277AF88;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8277AF88:
	// mullw r5,r31,r28
	ctx.r5.s64 = int64_t(r31.s32) * int64_t(r28.s32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8277add8
	ctx.lr = 0x8277AF98;
	sub_8277ADD8(ctx, base);
	// mtctr r31
	ctr.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277afc0
	if (cr6.eq) goto loc_8277AFC0;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r30,r31
	r30.u64 = r30.u64 + r31.u64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
loc_8277AFB0:
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bdnz 0x8277afb0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277AFB0;
loc_8277AFC0:
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x8277af78
	if (cr6.lt) goto loc_8277AF78;
loc_8277AFC8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277AEF8) {
	__imp__sub_8277AEF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277AFD4) {
	__imp__sub_8277AFD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277AFD8) {
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
	ctx.lr = 0x8277AFE0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// rlwinm r25,r24,7,0,24
	r25.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 7) & 0xFFFFFF80;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// lwz r30,4(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// divwu. r31,r10,r25
	r31.u32 = ctx.r10.u32 / r25.u32;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// twllei r25,0
	// bgt 0x8277b02c
	if (cr0.gt) goto loc_8277B02C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,70
	ctx.r10.s64 = 70;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277B02C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B02C:
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x8277b038
	if (cr6.lt) goto loc_8277B038;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8277B038:
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277B04C;
	sub_8277AC00(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8277b0b0
	if (cr6.eq) goto loc_8277B0B0;
loc_8277B05C:
	// subf r11,r30,r29
	r11.s64 = r29.s64 - r30.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x8277b06c
	if (cr6.lt) goto loc_8277B06C;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8277B06C:
	// mullw r11,r31,r24
	r11.s64 = int64_t(r31.s32) * int64_t(r24.s32);
	// rlwinm r5,r11,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8277add8
	ctx.lr = 0x8277B080;
	sub_8277ADD8(ctx, base);
	// mtctr r31
	ctr.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277b0a8
	if (cr6.eq) goto loc_8277B0A8;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r30,r31
	r30.u64 = r30.u64 + r31.u64;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
loc_8277B098:
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r3,r25,r3
	ctx.r3.u64 = r25.u64 + ctx.r3.u64;
	// bdnz 0x8277b098
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277B098;
loc_8277B0A8:
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x8277b05c
	if (cr6.lt) goto loc_8277B05C;
loc_8277B0B0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8277AFD8) {
	__imp__sub_8277AFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B0BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277B0BC) {
	__imp__sub_8277B0BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B0C0) {
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
	ctx.lr = 0x8277B0C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8277b114
	if (cr6.eq) goto loc_8277B114;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277B114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B114:
	// li r5,120
	ctx.r5.s64 = 120;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277B124;
	sub_8277AC00(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r25.u32);
	// stb r28,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r28.u8);
	// stb r11,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, r11.u8);
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r3,68(r30)
	PPC_STORE_U32(r30.u32 + 68, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277B0C0) {
	__imp__sub_8277B0C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277B154) {
	__imp__sub_8277B154(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B158) {
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
	ctx.lr = 0x8277B160;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8277b1ac
	if (cr6.eq) goto loc_8277B1AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277B1AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B1AC:
	// li r5,120
	ctx.r5.s64 = 120;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277B1BC;
	sub_8277AC00(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r25.u32);
	// stb r28,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r28.u8);
	// stb r11,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, r11.u8);
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r3,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277B158) {
	__imp__sub_8277B158(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277B1EC) {
	__imp__sub_8277B1EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B1F0) {
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
	ctx.lr = 0x8277B1F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// lwz r27,4(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b250
	if (cr6.eq) goto loc_8277B250;
loc_8277B21C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b244
	if (!cr6.eq) goto loc_8277B244;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mullw r9,r7,r9
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
loc_8277B244:
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b21c
	if (!cr6.eq) goto loc_8277B21C;
loc_8277B250:
	// lwz r11,72(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b298
	if (cr6.eq) goto loc_8277B298;
loc_8277B25C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b28c
	if (!cr6.eq) goto loc_8277B28C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r7,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r10,r6,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
loc_8277B28C:
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b25c
	if (!cr6.eq) goto loc_8277B25C;
loc_8277B298:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8277b420
	if (!cr6.gt) goto loc_8277B420;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r6,76(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277dc28
	ctx.lr = 0x8277B2B4;
	sub_8277DC28(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// blt cr6,0x8277b2cc
	if (cr6.lt) goto loc_8277B2CC;
	// lis r30,15258
	r30.s64 = 999948288;
	// ori r30,r30,51712
	r30.u64 = r30.u64 | 51712;
	// b 0x8277b2ec
	goto loc_8277B2EC;
loc_8277B2CC:
	// rotlwi r11,r3,1
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// divw. r30,r3,r31
	r30.s32 = ctx.r3.s32 / r31.s32;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r31,0
	// andc r10,r31,r11
	ctx.r10.u64 = r31.u64 & ~r11.u64;
	// twlgei r10,-1
	// bgt 0x8277b2ec
	if (cr0.gt) goto loc_8277B2EC;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8277B2EC:
	// lwz r31,68(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277b384
	if (cr6.eq) goto loc_8277B384;
loc_8277B2F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b378
	if (!cr6.eq) goto loc_8277B378;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// twllei r10,0
	// divwu r9,r9,r10
	ctx.r9.u32 = ctx.r9.u32 / ctx.r10.u32;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// bgt cr6,0x8277b32c
	if (cr6.gt) goto loc_8277B32C;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x8277b34c
	goto loc_8277B34C;
loc_8277B32C:
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// mullw r5,r9,r11
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277dc30
	ctx.lr = 0x8277B348;
	sub_8277DC30(ctx, base);
	// stb r28,34(r31)
	PPC_STORE_U8(r31.u32 + 34, r28.u8);
loc_8277B34C:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8277aef8
	ctx.lr = 0x8277B360;
	sub_8277AEF8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r11,80(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// stb r26,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r26.u8);
loc_8277B378:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277b2f8
	if (!cr6.eq) goto loc_8277B2F8;
loc_8277B384:
	// lwz r31,72(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277b420
	if (cr6.eq) goto loc_8277B420;
loc_8277B390:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b414
	if (!cr6.eq) goto loc_8277B414;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// twllei r10,0
	// divwu r9,r9,r10
	ctx.r9.u32 = ctx.r9.u32 / ctx.r10.u32;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// bgt cr6,0x8277b3c4
	if (cr6.gt) goto loc_8277B3C4;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x8277b3e8
	goto loc_8277B3E8;
loc_8277B3C4:
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// rlwinm r5,r8,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277dc30
	ctx.lr = 0x8277B3E4;
	sub_8277DC30(ctx, base);
	// stb r28,34(r31)
	PPC_STORE_U8(r31.u32 + 34, r28.u8);
loc_8277B3E8:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8277afd8
	ctx.lr = 0x8277B3FC;
	sub_8277AFD8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r11,80(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// stb r26,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r26.u8);
loc_8277B414:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277b390
	if (!cr6.eq) goto loc_8277B390;
loc_8277B420:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277B1F0) {
	__imp__sub_8277B1F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B428) {
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
	ctx.lr = 0x8277B430;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r26,8(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r28,r10,r26
	r28.s64 = int64_t(ctx.r10.s32) * int64_t(r26.s32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b500
	if (!cr6.gt) goto loc_8277B500;
loc_8277B45C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8277b470
	if (!cr6.lt) goto loc_8277B470;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B470:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277b48c
	if (cr6.lt) goto loc_8277B48C;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8277B48C:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277b4a0
	if (cr6.lt) goto loc_8277B4A0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B4A0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b500
	if (!cr6.gt) goto loc_8277B500;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// mullw r29,r11,r26
	r29.s64 = int64_t(r11.s32) * int64_t(r26.s32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// beq cr6,0x8277b4dc
	if (cr6.eq) goto loc_8277B4DC;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// b 0x8277b4e0
	goto loc_8277B4E0;
loc_8277B4DC:
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_8277B4E0:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r28,r29,r28
	r28.u64 = r29.u64 + r28.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r30,r30,r10
	r30.u64 = r30.u64 + ctx.r10.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277b45c
	if (cr6.lt) goto loc_8277B45C;
loc_8277B500:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277B428) {
	__imp__sub_8277B428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B508) {
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
	ctx.lr = 0x8277B510;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r26,r10,7,0,24
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// mullw r28,r26,r9
	r28.s64 = int64_t(r26.s32) * int64_t(ctx.r9.s32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b5e4
	if (!cr6.gt) goto loc_8277B5E4;
loc_8277B540:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8277b554
	if (!cr6.lt) goto loc_8277B554;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B554:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277b570
	if (cr6.lt) goto loc_8277B570;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8277B570:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277b584
	if (cr6.lt) goto loc_8277B584;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B584:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b5e4
	if (!cr6.gt) goto loc_8277B5E4;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// mullw r29,r11,r26
	r29.s64 = int64_t(r11.s32) * int64_t(r26.s32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// beq cr6,0x8277b5c0
	if (cr6.eq) goto loc_8277B5C0;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// b 0x8277b5c4
	goto loc_8277B5C4;
loc_8277B5C0:
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_8277B5C4:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r28,r29,r28
	r28.u64 = r29.u64 + r28.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277b540
	if (cr6.lt) goto loc_8277B540;
loc_8277B5E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277B508) {
	__imp__sub_8277B508(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277B5EC) {
	__imp__sub_8277B5EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B5F0) {
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
	ctx.lr = 0x8277B5F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// add r30,r27,r6
	r30.u64 = r27.u64 + ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r28,22
	r28.s64 = 22;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bgt cr6,0x8277b638
	if (cr6.gt) goto loc_8277B638;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bgt cr6,0x8277b638
	if (cr6.gt) goto loc_8277B638;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b654
	if (!cr6.eq) goto loc_8277B654;
loc_8277B638:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B654:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8277b670
	if (cr6.lt) goto loc_8277B670;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8277b6f8
	if (!cr6.gt) goto loc_8277B6F8;
loc_8277B670:
	// lbz r11,34(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b69c
	if (!cr6.eq) goto loc_8277B69C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,69
	ctx.r10.s64 = 69;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277B69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B69C:
	// lbz r11,33(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 33);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b6c0
	if (cr6.eq) goto loc_8277B6C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b428
	ctx.lr = 0x8277B6B8;
	sub_8277B428(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B6C0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// ble cr6,0x8277b6d4
	if (!cr6.gt) goto loc_8277B6D4;
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// b 0x8277b6e8
	goto loc_8277B6E8;
loc_8277B6D4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8277b6e4
	if (!cr0.lt) goto loc_8277B6E4;
	// li r11,0
	r11.s64 = 0;
loc_8277B6E4:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_8277B6E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b428
	ctx.lr = 0x8277B6F8;
	sub_8277B428(ctx, base);
loc_8277B6F8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8277b7b8
	if (!cr6.lt) goto loc_8277B7B8;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x8277b738
	if (!cr6.lt) goto loc_8277B738;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b734
	if (cr6.eq) goto loc_8277B734;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B734:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8277B738:
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277b748
	if (cr6.eq) goto loc_8277B748;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
loc_8277B748:
	// lbz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277b794
	if (cr6.eq) goto loc_8277B794;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subf r10,r10,r30
	ctx.r10.s64 = r30.s64 - ctx.r10.s64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8277b7b8
	if (!cr6.lt) goto loc_8277B7B8;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
loc_8277B774:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8277a3e8
	ctx.lr = 0x8277B784;
	sub_8277A3E8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8277b774
	if (!cr0.eq) goto loc_8277B774;
	// b 0x8277b7b8
	goto loc_8277B7B8;
loc_8277B794:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b7b8
	if (!cr6.eq) goto loc_8277B7B8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B7B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B7B8:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b7cc
	if (cr6.eq) goto loc_8277B7CC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B7CC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277B5F0) {
	__imp__sub_8277B5F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B7E8) {
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
	ctx.lr = 0x8277B7F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// add r30,r27,r6
	r30.u64 = r27.u64 + ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r28,22
	r28.s64 = 22;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bgt cr6,0x8277b830
	if (cr6.gt) goto loc_8277B830;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bgt cr6,0x8277b830
	if (cr6.gt) goto loc_8277B830;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b84c
	if (!cr6.eq) goto loc_8277B84C;
loc_8277B830:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B84C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B84C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8277b868
	if (cr6.lt) goto loc_8277B868;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8277b8f0
	if (!cr6.gt) goto loc_8277B8F0;
loc_8277B868:
	// lbz r11,34(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b894
	if (!cr6.eq) goto loc_8277B894;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,69
	ctx.r10.s64 = 69;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277B894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B894:
	// lbz r11,33(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 33);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b8b8
	if (cr6.eq) goto loc_8277B8B8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b508
	ctx.lr = 0x8277B8B0;
	sub_8277B508(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B8B8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// ble cr6,0x8277b8cc
	if (!cr6.gt) goto loc_8277B8CC;
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// b 0x8277b8e0
	goto loc_8277B8E0;
loc_8277B8CC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8277b8dc
	if (!cr0.lt) goto loc_8277B8DC;
	// li r11,0
	r11.s64 = 0;
loc_8277B8DC:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_8277B8E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b508
	ctx.lr = 0x8277B8F0;
	sub_8277B508(ctx, base);
loc_8277B8F0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8277b9b4
	if (!cr6.lt) goto loc_8277B9B4;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x8277b930
	if (!cr6.lt) goto loc_8277B930;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b92c
	if (cr6.eq) goto loc_8277B92C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B92C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B92C:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8277B930:
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277b940
	if (cr6.eq) goto loc_8277B940;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
loc_8277B940:
	// lbz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277b990
	if (cr6.eq) goto loc_8277B990;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subf r10,r10,r30
	ctx.r10.s64 = r30.s64 - ctx.r10.s64;
	// rlwinm r28,r9,7,0,24
	r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8277b9b4
	if (!cr6.lt) goto loc_8277B9B4;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
loc_8277B970:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8277a3e8
	ctx.lr = 0x8277B980;
	sub_8277A3E8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8277b970
	if (!cr0.eq) goto loc_8277B970;
	// b 0x8277b9b4
	goto loc_8277B9B4;
loc_8277B990:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b9b4
	if (!cr6.eq) goto loc_8277B9B4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B9B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B9B4:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b9c8
	if (cr6.eq) goto loc_8277B9C8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B9C8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277B7E8) {
	__imp__sub_8277B7E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277B9E4) {
	__imp__sub_8277B9E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277B9E8) {
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
	ctx.lr = 0x8277B9F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// blt cr6,0x8277ba10
	if (cr6.lt) goto loc_8277BA10;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// blt cr6,0x8277ba38
	if (cr6.lt) goto loc_8277BA38;
loc_8277BA10:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r26,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r26.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277BA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BA38:
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// bne cr6,0x8277bac4
	if (!cr6.eq) goto loc_8277BAC4;
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8277ba80
	if (cr6.eq) goto loc_8277BA80;
loc_8277BA50:
	// lbz r11,34(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ba74
	if (cr6.eq) goto loc_8277BA74;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r4,r30,40
	ctx.r4.s64 = r30.s64 + 40;
	// stb r27,34(r30)
	PPC_STORE_U8(r30.u32 + 34, r27.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277BA74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BA74:
	// lwz r30,36(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277ba50
	if (!cr6.eq) goto loc_8277BA50;
loc_8277BA80:
	// lwz r30,72(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r27,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8277bac0
	if (cr6.eq) goto loc_8277BAC0;
loc_8277BA90:
	// lbz r11,34(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277bab4
	if (cr6.eq) goto loc_8277BAB4;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r4,r30,40
	ctx.r4.s64 = r30.s64 + 40;
	// stb r27,34(r30)
	PPC_STORE_U8(r30.u32 + 34, r27.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277BAB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BAB4:
	// lwz r30,36(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277ba90
	if (!cr6.eq) goto loc_8277BA90;
loc_8277BAC0:
	// stw r27,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r27.u32);
loc_8277BAC4:
	// addi r11,r26,15
	r11.s64 = r26.s64 + 15;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277bb14
	if (cr6.eq) goto loc_8277BB14;
loc_8277BADC:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r30,0(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821e4b18
	ctx.lr = 0x8277BAFC;
	sub_821E4B18(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// subf r10,r29,r11
	ctx.r10.s64 = r11.s64 - r29.s64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x8277badc
	if (!cr6.eq) goto loc_8277BADC;
loc_8277BB14:
	// addi r11,r26,13
	r11.s64 = r26.s64 + 13;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277bb64
	if (cr6.eq) goto loc_8277BB64;
loc_8277BB2C:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r30,0(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821e4b18
	ctx.lr = 0x8277BB4C;
	sub_821E4B18(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// subf r10,r29,r11
	ctx.r10.s64 = r11.s64 - r29.s64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x8277bb2c
	if (!cr6.eq) goto loc_8277BB2C;
loc_8277BB64:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277B9E8) {
	__imp__sub_8277B9E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277BB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277BB6C) {
	__imp__sub_8277BB6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277BB70) {
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
	// li r31,1
	r31.s64 = 1;
loc_8277BB8C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277b9e8
	ctx.lr = 0x8277BB98;
	sub_8277B9E8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8277bb8c
	if (!cr0.lt) goto loc_8277BB8C;
	// li r5,84
	ctx.r5.s64 = 84;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e4b18
	ctx.lr = 0x8277BBB0;
	sub_821E4B18(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x8277BBC0;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_8277BB70) {
	__imp__sub_8277BB70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277BBD8) {
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
	ctx.lr = 0x8277BBE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// bl 0x821a5cc0
	ctx.lr = 0x8277BBF4;
	sub_821A5CC0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,84
	ctx.r4.s64 = 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277BC04;
	sub_8277DC20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277bc40
	if (!cr6.eq) goto loc_8277BC40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8277BC18;
	sub_82130000(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,54
	r11.s64 = 54;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277BC40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BC40:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// addi r11,r11,-21504
	r11.s64 = r11.s64 + -21504;
	// addi r10,r10,-21032
	ctx.r10.s64 = ctx.r10.s64 + -21032;
	// addi r9,r9,-20744
	ctx.r9.s64 = ctx.r9.s64 + -20744;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lis r5,-32136
	ctx.r5.s64 = -2106064896;
	// lis r4,-32136
	ctx.r4.s64 = -2106064896;
	// lis r3,-32136
	ctx.r3.s64 = -2106064896;
	// lis r28,-32136
	r28.s64 = -2106064896;
	// lis r27,-32136
	r27.s64 = -2106064896;
	// lis r26,15258
	r26.s64 = 999948288;
	// addi r8,r8,-20520
	ctx.r8.s64 = ctx.r8.s64 + -20520;
	// addi r7,r7,-20288
	ctx.r7.s64 = ctx.r7.s64 + -20288;
	// addi r6,r6,-20136
	ctx.r6.s64 = ctx.r6.s64 + -20136;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// addi r5,r5,-19984
	ctx.r5.s64 = ctx.r5.s64 + -19984;
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// addi r4,r4,-18960
	ctx.r4.s64 = ctx.r4.s64 + -18960;
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// addi r3,r3,-18456
	ctx.r3.s64 = ctx.r3.s64 + -18456;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// addi r11,r28,-17944
	r11.s64 = r28.s64 + -17944;
	// stw r4,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r4.u32);
	// addi r10,r27,-17552
	ctx.r10.s64 = r27.s64 + -17552;
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// ori r9,r26,51712
	ctx.r9.u64 = r26.u64 | 51712;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r8,84
	ctx.r8.s64 = 84;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// stw r29,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r29.u32);
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r29.u32);
	// stw r29,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r29.u32);
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r8.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277BBD8) {
	__imp__sub_8277BBD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277BD00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lbz r11,266(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 266);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bgt cr6,0x8277bdc0
	if (cr6.gt) goto loc_8277BDC0;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,180(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r10,280(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x8277bdc0
	if (!cr6.eq) goto loc_8277BDC0;
	// lwz r11,204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 204);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8277BDC0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277BD00) {
	__imp__sub_8277BD00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277BDC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8277BDD0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,202
	cr6.compare<int32_t>(r11.s32, 202, xer);
	// beq cr6,0x8277be0c
	if (cr6.eq) goto loc_8277BE0C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277BE0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BE0C:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r27,1
	r27.s64 = 1;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r28,4
	r28.s64 = 4;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277be50
	if (cr6.gt) goto loc_8277BE50;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x8277a320
	ctx.lr = 0x8277BE34;
	sub_8277A320(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8277a320
	ctx.lr = 0x8277BE44;
	sub_8277A320(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r27,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r27.u32);
	// b 0x8277bed4
	goto loc_8277BED4;
loc_8277BE50:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277be88
	if (cr6.gt) goto loc_8277BE88;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x8277a320
	ctx.lr = 0x8277BE68;
	sub_8277A320(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8277a320
	ctx.lr = 0x8277BE78;
	sub_8277A320(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r11,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r11.u32);
	// b 0x8277bed4
	goto loc_8277BED4;
loc_8277BE88:
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277bebc
	if (cr6.gt) goto loc_8277BEBC;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x8277a320
	ctx.lr = 0x8277BEA0;
	sub_8277A320(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x8277a320
	ctx.lr = 0x8277BEB0;
	sub_8277A320(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// b 0x8277bed4
	goto loc_8277BED4;
loc_8277BEBC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r10,280(r31)
	PPC_STORE_U32(r31.u32 + 280, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
loc_8277BED4:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277bf58
	if (!cr6.gt) goto loc_8277BF58;
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
loc_8277BEEC:
	// lwz r9,280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// bge cr6,0x8277bf40
	if (!cr6.lt) goto loc_8277BF40;
	// lwz r7,272(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
loc_8277BF08:
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// rlwinm r4,r5,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// bgt cr6,0x8277bf40
	if (cr6.gt) goto loc_8277BF40;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,276(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mullw r3,r11,r5
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// mullw r5,r4,r9
	ctx.r5.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// rlwinm r4,r3,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// bgt cr6,0x8277bf40
	if (cr6.gt) goto loc_8277BF40;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8277bf08
	if (cr6.lt) goto loc_8277BF08;
loc_8277BF40:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x8277beec
	if (cr6.lt) goto loc_8277BEEC;
loc_8277BF58:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r29,0
	r29.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277bfcc
	if (!cr6.gt) goto loc_8277BFCC;
	// addi r30,r11,36
	r30.s64 = r11.s64 + 36;
loc_8277BF70:
	// lwz r11,-28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -28);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,272(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r3,r7,r8
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277BF90;
	sub_8277A320(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lwz r6,276(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r5,-24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -24);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mullw r11,r5,r4
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// mullw r3,r11,r3
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r3.s32);
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277BFB4;
	sub_8277A320(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277bf70
	if (cr6.lt) goto loc_8277BF70;
loc_8277BFCC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8277c020
	if (cr6.gt) goto loc_8277C020;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-16396
	r12.s64 = r12.s64 + -16396;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-16376(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16376);
	// lwz r19,-16368(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16368);
	// lwz r19,-16368(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16368);
	// lwz r19,-16360(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16360);
	// lwz r19,-16360(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -16360);
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// b 0x8277c028
	goto loc_8277C028;
	// li r11,3
	r11.s64 = 3;
	// b 0x8277c024
	goto loc_8277C024;
	// stw r28,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r28.u32);
	// b 0x8277c028
	goto loc_8277C028;
loc_8277C020:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
loc_8277C024:
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_8277C028:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bne cr6,0x8277c03c
	if (!cr6.eq) goto loc_8277C03C;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
loc_8277C03C:
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277bd00
	ctx.lr = 0x8277C048;
	sub_8277BD00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c064
	if (cr6.eq) goto loc_8277C064;
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277C064:
	// stw r27,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8277BDC8) {
	__imp__sub_8277BDC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C070) {
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
	ctx.lr = 0x8277C078;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r28,384(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// bl 0x8277bdc8
	ctx.lr = 0x8277C088;
	sub_8277BDC8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1408
	ctx.r5.s64 = 1408;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C0A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r3,256
	r30.s64 = ctx.r3.s64 + 256;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// addi r3,r30,-256
	ctx.r3.s64 = r30.s64 + -256;
	// bl 0x823d9890
	ctx.lr = 0x8277C0BC;
	sub_823D9890(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8277C0C4:
	// stbx r11,r11,r30
	PPC_STORE_U8(r11.u32 + r30.u32, r11.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x8277c0c4
	if (!cr6.gt) goto loc_8277C0C4;
	// addi r30,r30,128
	r30.s64 = r30.s64 + 128;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r11,r30,128
	r11.s64 = r30.s64 + 128;
	// li r10,384
	ctx.r10.s64 = 384;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8277C0E8:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8277c0e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277C0E8;
	// li r5,384
	ctx.r5.s64 = 384;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,512
	ctx.r3.s64 = r30.s64 + 512;
	// bl 0x823d9890
	ctx.lr = 0x8277C104;
	sub_823D9890(ctx, base);
	// addi r3,r30,896
	ctx.r3.s64 = r30.s64 + 896;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r4,288(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// bl 0x823da950
	ctx.lr = 0x8277C114;
	sub_823DA950(ctx, base);
	// stw r29,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277bd00
	ctx.lr = 0x8277C120;
	sub_8277BD00(ctx, base);
	// stb r3,16(r28)
	PPC_STORE_U8(r28.u32 + 16, ctx.r3.u8);
	// stw r29,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r29.u32);
	// stw r29,24(r28)
	PPC_STORE_U32(r28.u32 + 24, r29.u32);
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c144
	if (cr6.eq) goto loc_8277C144;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c150
	if (!cr6.eq) goto loc_8277C150;
loc_8277C144:
	// stb r29,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r29.u8);
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
loc_8277C150:
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1e8
	if (cr6.eq) goto loc_8277C1E8;
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c188
	if (cr6.eq) goto loc_8277C188;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,47
	ctx.r10.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C188:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8277c20c
	if (cr6.eq) goto loc_8277C20C;
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
loc_8277C1A0:
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
loc_8277C1A4:
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1c0
	if (cr6.eq) goto loc_8277C1C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82785498
	ctx.lr = 0x8277C1B8;
	sub_82785498(ctx, base);
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
loc_8277C1C0:
	// lbz r11,90(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c1d8
	if (!cr6.eq) goto loc_8277C1D8;
	// lbz r11,89(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 89);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1e8
	if (cr6.eq) goto loc_8277C1E8;
loc_8277C1D8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827846b8
	ctx.lr = 0x8277C1E0;
	sub_827846B8(ctx, base);
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// stw r11,24(r28)
	PPC_STORE_U32(r28.u32 + 24, r11.u32);
loc_8277C1E8:
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c24c
	if (!cr6.eq) goto loc_8277C24C;
	// lbz r11,16(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c234
	if (cr6.eq) goto loc_8277C234;
	// bl 0x82783240
	ctx.lr = 0x8277C208;
	sub_82783240(ctx, base);
	// b 0x8277c240
	goto loc_8277C240;
loc_8277C20C:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c220
	if (cr6.eq) goto loc_8277C220;
	// stb r30,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r30.u8);
	// b 0x8277c1a4
	goto loc_8277C1A4;
loc_8277C220:
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c1a0
	if (cr6.eq) goto loc_8277C1A0;
	// stb r30,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r30.u8);
	// b 0x8277c1a4
	goto loc_8277C1A4;
loc_8277C234:
	// bl 0x827829f8
	ctx.lr = 0x8277C238;
	sub_827829F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827822e8
	ctx.lr = 0x8277C240;
	sub_827822E8(ctx, base);
loc_8277C240:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,90(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// bl 0x82781c48
	ctx.lr = 0x8277C24C;
	sub_82781C48(ctx, base);
loc_8277C24C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827817e8
	ctx.lr = 0x8277C254;
	sub_827817E8(ctx, base);
	// lbz r11,201(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 201);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c280
	if (cr6.eq) goto loc_8277C280;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C27C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277c29c
	goto loc_8277C29C;
loc_8277C280:
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c298
	if (cr6.eq) goto loc_8277C298;
	// bl 0x82781318
	ctx.lr = 0x8277C294;
	sub_82781318(ctx, base);
	// b 0x8277c29c
	goto loc_8277C29C;
loc_8277C298:
	// bl 0x82780490
	ctx.lr = 0x8277C29C;
	sub_82780490(ctx, base);
loc_8277C29C:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c2bc
	if (!cr6.eq) goto loc_8277C2BC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// beq cr6,0x8277c2c0
	if (cr6.eq) goto loc_8277C2C0;
loc_8277C2BC:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8277C2C0:
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277f5f0
	ctx.lr = 0x8277C2CC;
	sub_8277F5F0(ctx, base);
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c2e4
	if (!cr6.eq) goto loc_8277C2E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277e378
	ctx.lr = 0x8277C2E4;
	sub_8277E378(ctx, base);
loc_8277C2E4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C2F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C30C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277c394
	if (cr6.eq) goto loc_8277C394;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c394
	if (!cr6.eq) goto loc_8277C394;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277c394
	if (cr6.eq) goto loc_8277C394;
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// beq cr6,0x8277c350
	if (cr6.eq) goto loc_8277C350;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8277C350:
	// stw r29,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r29.u32);
	// lwz r9,284(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r29,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, r29.u32);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbz r5,90(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r11,r3,1
	r11.u64 = ctx.r3.u64 ^ 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, r11.u32);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r10.u32);
loc_8277C394:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8277C070) {
	__imp__sub_8277C070(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277C39C) {
	__imp__sub_8277C39C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C3A0) {
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
	// lwz r30,384(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c404
	if (cr6.eq) goto loc_8277C404;
	// li r11,0
	r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r11.u8);
	// lwz r10,424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C3E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277C3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8277c534
	goto loc_8277C534;
loc_8277C404:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c480
	if (cr6.eq) goto loc_8277C480;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c480
	if (!cr6.eq) goto loc_8277C480;
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c448
	if (cr6.eq) goto loc_8277C448;
	// lbz r11,90(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c448
	if (cr6.eq) goto loc_8277C448;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r11.u32);
	// stb r10,8(r30)
	PPC_STORE_U8(r30.u32 + 8, ctx.r10.u8);
	// b 0x8277c480
	goto loc_8277C480;
loc_8277C448:
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c460
	if (cr6.eq) goto loc_8277C460;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r11,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r11.u32);
	// b 0x8277c480
	goto loc_8277C480;
loc_8277C460:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,46
	ctx.r10.s64 = 46;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C480:
	// lwz r11,412(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C4A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,65(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8277c548
	if (!cr6.eq) goto loc_8277C548;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277c4d4
	if (!cr6.eq) goto loc_8277C4D4;
	// lwz r11,420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C4D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C4D4:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,74(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277c50c
	if (cr6.eq) goto loc_8277C50C;
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C50C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C50C:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,396(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r4,r8,30
	ctx.r4.u64 = ctx.r8.u32 & 0x3;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277C530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
loc_8277C534:
	// lwz r6,388(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8277C548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C548:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c5c0
	if (cr6.eq) goto loc_8277C5C0;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stw r5,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r5.u32);
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277c5c0
	if (cr6.eq) goto loc_8277C5C0;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c5c0
	if (!cr6.eq) goto loc_8277C5C0;
	// lbz r10,90(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 90);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
loc_8277C5C0:
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

PPC_WEAK_FUNC(sub_8277C3A0) {
	__imp__sub_8277C3A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C5D8) {
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
	// lbz r11,74(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 74);
	// lwz r31,384(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277c608
	if (cr6.eq) goto loc_8277C608;
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C608:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
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

PPC_WEAK_FUNC(sub_8277C5D8) {
	__imp__sub_8277C5D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C628) {
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
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277C654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// stw r9,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r9.u32);
	// addi r6,r8,-15456
	ctx.r6.s64 = ctx.r8.s64 + -15456;
	// addi r5,r7,-14888
	ctx.r5.s64 = ctx.r7.s64 + -14888;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// stw r5,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r4,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r4.u8);
	// bl 0x8277c070
	ctx.lr = 0x8277C684;
	sub_8277C070(ctx, base);
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

PPC_WEAK_FUNC(sub_8277C628) {
	__imp__sub_8277C628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r4,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r4.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c70c
	if (!cr0.eq) goto loc_8277C70C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c70c
	if (!cr6.eq) goto loc_8277C70C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,24
	ctx.r10.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277C70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C70C:
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

PPC_WEAK_FUNC(sub_8277C698) {
	__imp__sub_8277C698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277C720) {
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
	ctx.lr = 0x8277C728;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r29,18
	r11.s64 = r29.s64 + 18;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r25,r10,r31
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8277c76c
	if (!cr6.eq) goto loc_8277C76C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,52
	ctx.r10.s64 = 52;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277C76C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C76C:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r25,4
	r11.s64 = r25.s64 + 4;
	// li r10,16
	ctx.r10.s64 = 16;
loc_8277C778:
	// lhz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -4);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c788
	if (!cr6.gt) goto loc_8277C788;
	// li r27,1
	r27.s64 = 1;
loc_8277C788:
	// lhz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c798
	if (!cr6.gt) goto loc_8277C798;
	// li r27,1
	r27.s64 = 1;
loc_8277C798:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c7a8
	if (!cr6.gt) goto loc_8277C7A8;
	// li r27,1
	r27.s64 = 1;
loc_8277C7A8:
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// ble cr6,0x8277c7b8
	if (!cr6.gt) goto loc_8277C7B8;
	// li r27,1
	r27.s64 = 1;
loc_8277C7B8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8277c778
	if (!cr0.eq) goto loc_8277C778;
	// lbz r11,128(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277cad4
	if (!cr6.eq) goto loc_8277CAD4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r26,24
	r26.s64 = 24;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277c838
	if (!cr0.eq) goto loc_8277C838;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c838
	if (!cr6.eq) goto loc_8277C838;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C838:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,219
	ctx.r10.s64 = 219;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c89c
	if (!cr0.eq) goto loc_8277C89C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C874;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c89c
	if (!cr6.eq) goto loc_8277C89C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C89C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C89C:
	// subfic r10,r27,0
	xer.ca = r27.u32 <= 0;
	ctx.r10.s64 = 0 - r27.s64;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r10,r9,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r10,67
	r30.s64 = ctx.r10.s64 + 67;
	// srawi r7,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r7.s64 = r30.s32 >> 8;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r10.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// bne 0x8277c910
	if (!cr0.eq) goto loc_8277C910;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C8E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c910
	if (!cr6.eq) goto loc_8277C910;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C910:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c970
	if (!cr0.eq) goto loc_8277C970;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c970
	if (!cr6.eq) goto loc_8277C970;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C970:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r27,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r10.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277c9d8
	if (!cr0.eq) goto loc_8277C9D8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277C9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277c9d8
	if (!cr6.eq) goto loc_8277C9D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277C9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277C9D8:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r28,r11,-31424
	r28.s64 = r11.s64 + -31424;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_8277C9E4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r30,r10,r25
	r30.u64 = PPC_LOAD_U16(ctx.r10.u32 + r25.u32);
	// beq cr6,0x8277ca5c
	if (cr6.eq) goto loc_8277CA5C;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 24) & 0xFF;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277ca5c
	if (!cr0.eq) goto loc_8277CA5C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CA34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277ca5c
	if (!cr6.eq) goto loc_8277CA5C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CA5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CA5C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277cabc
	if (!cr0.eq) goto loc_8277CABC;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cabc
	if (!cr6.eq) goto loc_8277CABC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CABC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CABC:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r11,r28,256
	r11.s64 = r28.s64 + 256;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277c9e4
	if (cr6.lt) goto loc_8277C9E4;
	// li r11,1
	r11.s64 = 1;
	// stb r11,128(r25)
	PPC_STORE_U8(r25.u32 + 128, r11.u8);
loc_8277CAD4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277C720) {
	__imp__sub_8277C720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277CAE0) {
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
	ctx.lr = 0x8277CAE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277cb0c
	if (cr6.eq) goto loc_8277CB0C;
	// addi r11,r29,26
	r11.s64 = r29.s64 + 26;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// b 0x8277cb10
	goto loc_8277CB10;
loc_8277CB0C:
	// addi r11,r29,22
	r11.s64 = r29.s64 + 22;
loc_8277CB10:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r10,r31
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8277cb48
	if (!cr6.eq) goto loc_8277CB48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,50
	ctx.r10.s64 = 50;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277CB48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CB48:
	// lbz r11,273(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 273);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277cdcc
	if (!cr6.eq) goto loc_8277CDCC;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CB60;
	sub_8277C698(ctx, base);
	// li r4,196
	ctx.r4.s64 = 196;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CB6C;
	sub_8277C698(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// addi r11,r26,3
	r11.s64 = r26.s64 + 3;
	// li r10,4
	ctx.r10.s64 = 4;
loc_8277CB78:
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r28,r9,r28
	r28.u64 = ctx.r9.u64 + r28.u64;
	// bne 0x8277cb78
	if (!cr0.eq) goto loc_8277CB78;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r30,r28,19
	r30.s64 = r28.s64 + 19;
	// li r27,24
	r27.s64 = 24;
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cc10
	if (!cr0.eq) goto loc_8277CC10;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CBE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cc10
	if (!cr6.eq) goto loc_8277CC10;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CC10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CC10:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cc70
	if (!cr0.eq) goto loc_8277CC70;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CC48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cc70
	if (!cr6.eq) goto loc_8277CC70;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CC70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CC70:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r29,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r29.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277ccd0
	if (!cr0.eq) goto loc_8277CCD0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CCA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277ccd0
	if (!cr6.eq) goto loc_8277CCD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CCD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CCD0:
	// li r30,1
	r30.s64 = 1;
loc_8277CCD4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbzx r10,r30,r26
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + r26.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cd38
	if (!cr0.eq) goto loc_8277CD38;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CD10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cd38
	if (!cr6.eq) goto loc_8277CD38;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CD38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CD38:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// ble cr6,0x8277ccd4
	if (!cr6.gt) goto loc_8277CCD4;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x8277cdc4
	if (!cr6.gt) goto loc_8277CDC4;
	// addi r29,r26,17
	r29.s64 = r26.s64 + 17;
loc_8277CD54:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cdb8
	if (!cr0.eq) goto loc_8277CDB8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CD90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cdb8
	if (!cr6.eq) goto loc_8277CDB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CDB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CDB8:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x8277cd54
	if (cr6.lt) goto loc_8277CD54;
loc_8277CDC4:
	// li r11,1
	r11.s64 = 1;
	// stb r11,273(r26)
	PPC_STORE_U8(r26.u32 + 273, r11.u8);
loc_8277CDCC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8277CAE0) {
	__imp__sub_8277CAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277CDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277CDD4) {
	__imp__sub_8277CDD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277CDD8) {
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
	ctx.lr = 0x8277CDE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CDF4;
	sub_8277C698(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CE00;
	sub_8277C698(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277CE20;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CE2C;
	sub_8277C698(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// ori r11,r10,65535
	r11.u64 = ctx.r10.u64 | 65535;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bgt cr6,0x8277ce4c
	if (cr6.gt) goto loc_8277CE4C;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8277ce74
	if (!cr6.gt) goto loc_8277CE74;
loc_8277CE4C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,41
	ctx.r9.s64 = 41;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, r11.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277CE74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CE74:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x8277c698
	ctx.lr = 0x8277CE80;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277CE94;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CEA0;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277CEB4;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277CEC0;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x8277c698
	ctx.lr = 0x8277CECC;
	sub_8277C698(ctx, base);
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// ble cr6,0x8277d030
	if (!cr6.gt) goto loc_8277D030;
	// li r28,24
	r28.s64 = 24;
loc_8277CEE4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addic. r10,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r10.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277cf48
	if (!cr0.eq) goto loc_8277CF48;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cf48
	if (!cr6.eq) goto loc_8277CF48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CF48:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// bne 0x8277cfb8
	if (!cr0.eq) goto loc_8277CFB8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CF90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277cfb8
	if (!cr6.eq) goto loc_8277CFB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277CFB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277CFB8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d01c
	if (!cr0.eq) goto loc_8277D01C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277CFF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d01c
	if (!cr6.eq) goto loc_8277D01C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D01C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D01C:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277cee4
	if (cr6.lt) goto loc_8277CEE4;
loc_8277D030:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8277CDD8) {
	__imp__sub_8277CDD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D038) {
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
	ctx.lr = 0x8277D040;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D050;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,218
	ctx.r4.s64 = 218;
	// bl 0x8277c698
	ctx.lr = 0x8277D05C;
	sub_8277C698(ctx, base);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r30,r11,1,0,30
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D078;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D084;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,228(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x8277c698
	ctx.lr = 0x8277D090;
	sub_8277C698(ctx, base);
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// li r28,0
	r28.s64 = 0;
	// li r27,24
	r27.s64 = 24;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8277d1cc
	if (!cr6.gt) goto loc_8277D1CC;
	// addi r29,r31,232
	r29.s64 = r31.s64 + 232;
loc_8277D0A8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d110
	if (!cr0.eq) goto loc_8277D110;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D0E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d110
	if (!cr6.eq) goto loc_8277D110;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D110:
	// lbz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277d150
	if (cr6.eq) goto loc_8277D150;
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8277d14c
	if (!cr6.eq) goto loc_8277D14C;
	// lwz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277d150
	if (cr6.eq) goto loc_8277D150;
	// lbz r10,177(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d150
	if (!cr6.eq) goto loc_8277D150;
loc_8277D14C:
	// li r11,0
	r11.s64 = 0;
loc_8277D150:
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d1b8
	if (!cr0.eq) goto loc_8277D1B8;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d1b8
	if (!cr6.eq) goto loc_8277D1B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D1B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D1B8:
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8277d0a8
	if (cr6.lt) goto loc_8277D0A8;
loc_8277D1CC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bne 0x8277d230
	if (!cr0.eq) goto loc_8277D230;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d230
	if (!cr6.eq) goto loc_8277D230;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D230:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277d294
	if (!cr0.eq) goto loc_8277D294;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D26C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d294
	if (!cr6.eq) goto loc_8277D294;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D294:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// lwz r9,312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addic. r10,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277d304
	if (!cr0.eq) goto loc_8277D304;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277d304
	if (!cr6.eq) goto loc_8277D304;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277D304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D304:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8277D038) {
	__imp__sub_8277D038(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D30C) {
	__imp__sub_8277D30C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D310) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D330;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,224
	ctx.r4.s64 = 224;
	// bl 0x8277c698
	ctx.lr = 0x8277D33C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277c698
	ctx.lr = 0x8277D348;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8277c698
	ctx.lr = 0x8277D354;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,74
	ctx.r4.s64 = 74;
	// bl 0x8277c698
	ctx.lr = 0x8277D360;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,70
	ctx.r4.s64 = 70;
	// bl 0x8277c698
	ctx.lr = 0x8277D36C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,73
	ctx.r4.s64 = 73;
	// bl 0x8277c698
	ctx.lr = 0x8277D378;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,70
	ctx.r4.s64 = 70;
	// bl 0x8277c698
	ctx.lr = 0x8277D384;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277c698
	ctx.lr = 0x8277D390;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,197(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 197);
	// bl 0x8277c698
	ctx.lr = 0x8277D39C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,198(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// bl 0x8277c698
	ctx.lr = 0x8277D3A8;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,199(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 199);
	// bl 0x8277c698
	ctx.lr = 0x8277D3B4;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r30,200(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 200);
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3C8;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3D4;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r30,202(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 202);
	// srawi r10,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	ctx.r10.s64 = r30.s32 >> 8;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3E8;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D3F4;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8277c698
	ctx.lr = 0x8277D400;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D40C;
	sub_8277C698(ctx, base);
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

PPC_WEAK_FUNC(sub_8277D310) {
	__imp__sub_8277D310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D424) {
	__imp__sub_8277D424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D428) {
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
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D444;
	sub_8277C698(ctx, base);
	// li r4,238
	ctx.r4.s64 = 238;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D450;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D45C;
	sub_8277C698(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D468;
	sub_8277C698(ctx, base);
	// li r4,65
	ctx.r4.s64 = 65;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D474;
	sub_8277C698(ctx, base);
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D480;
	sub_8277C698(ctx, base);
	// li r4,111
	ctx.r4.s64 = 111;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D48C;
	sub_8277C698(ctx, base);
	// li r4,98
	ctx.r4.s64 = 98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D498;
	sub_8277C698(ctx, base);
	// li r4,101
	ctx.r4.s64 = 101;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4A4;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4B0;
	sub_8277C698(ctx, base);
	// li r4,100
	ctx.r4.s64 = 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4BC;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4C8;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4D4;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4E0;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D4EC;
	sub_8277C698(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8277d514
	if (cr6.eq) goto loc_8277D514;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x8277d50c
	if (cr6.eq) goto loc_8277D50C;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8277d518
	goto loc_8277D518;
loc_8277D50C:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8277d518
	goto loc_8277D518;
loc_8277D514:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8277D518:
	// bl 0x8277c698
	ctx.lr = 0x8277D51C;
	sub_8277C698(ctx, base);
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

PPC_WEAK_FUNC(sub_8277D428) {
	__imp__sub_8277D428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D530) {
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
	ctx.lr = 0x8277D538;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,65533
	cr6.compare<uint32_t>(r30.u32, 65533, xer);
	// ble cr6,0x8277d56c
	if (!cr6.gt) goto loc_8277D56C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277D56C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277D56C:
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D578;
	sub_8277C698(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D584;
	sub_8277C698(ctx, base);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D598;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D5A4;
	sub_8277C698(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8277D530) {
	__imp__sub_8277D530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D5AC) {
	__imp__sub_8277D5AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D5B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8277c698
	sub_8277C698(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8277D5B0) {
	__imp__sub_8277D5B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D5B4) {
	__imp__sub_8277D5B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D5B8) {
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
	// li r4,255
	ctx.r4.s64 = 255;
	// lwz r30,332(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// bl 0x8277c698
	ctx.lr = 0x8277D5DC;
	sub_8277C698(ctx, base);
	// li r4,216
	ctx.r4.s64 = 216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D5E8;
	sub_8277C698(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r11.u32);
	// lbz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 196);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277d604
	if (cr6.eq) goto loc_8277D604;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277d310
	ctx.lr = 0x8277D604;
	sub_8277D310(ctx, base);
loc_8277D604:
	// lbz r11,204(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d618
	if (cr6.eq) goto loc_8277D618;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277d428
	ctx.lr = 0x8277D618;
	sub_8277D428(ctx, base);
loc_8277D618:
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

PPC_WEAK_FUNC(sub_8277D5B8) {
	__imp__sub_8277D5B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D630) {
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
	ctx.lr = 0x8277D638;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277d680
	if (!cr6.gt) goto loc_8277D680;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
loc_8277D65C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8277c720
	ctx.lr = 0x8277D668;
	sub_8277C720(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277d65c
	if (cr6.lt) goto loc_8277D65C;
loc_8277D680:
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d724
	if (!cr6.eq) goto loc_8277D724;
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d724
	if (!cr6.eq) goto loc_8277D724;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x8277d724
	if (!cr6.eq) goto loc_8277D724;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r30,1
	r30.s64 = 1;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277d6e4
	if (!cr6.gt) goto loc_8277D6E4;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
loc_8277D6BC:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bgt cr6,0x8277d6d4
	if (cr6.gt) goto loc_8277D6D4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x8277d6d8
	if (!cr6.gt) goto loc_8277D6D8;
loc_8277D6D4:
	// li r30,0
	r30.s64 = 0;
loc_8277D6D8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// bne 0x8277d6bc
	if (!cr0.eq) goto loc_8277D6BC;
loc_8277D6E4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8277d728
	if (cr6.eq) goto loc_8277D728;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d728
	if (cr6.eq) goto loc_8277D728;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,75
	ctx.r10.s64 = 75;
	// li r30,0
	r30.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277D720;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277d728
	goto loc_8277D728;
loc_8277D724:
	// li r30,0
	r30.s64 = 0;
loc_8277D728:
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d748
	if (cr6.eq) goto loc_8277D748;
	// li r4,201
	ctx.r4.s64 = 201;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cdd8
	ctx.lr = 0x8277D740;
	sub_8277CDD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8277D748:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d768
	if (cr6.eq) goto loc_8277D768;
	// li r4,194
	ctx.r4.s64 = 194;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cdd8
	ctx.lr = 0x8277D760;
	sub_8277CDD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8277D768:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// li r4,192
	ctx.r4.s64 = 192;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d77c
	if (!cr6.eq) goto loc_8277D77C;
	// li r4,193
	ctx.r4.s64 = 193;
loc_8277D77C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cdd8
	ctx.lr = 0x8277D784;
	sub_8277CDD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8277D630) {
	__imp__sub_8277D630(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D78C) {
	__imp__sub_8277D78C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D790) {
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
	ctx.lr = 0x8277D798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// lwz r27,332(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d82c
	if (!cr6.eq) goto loc_8277D82C;
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277d82c
	if (!cr6.gt) goto loc_8277D82C;
	// addi r29,r31,232
	r29.s64 = r31.s64 + 232;
loc_8277D7C4:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d7f8
	if (cr6.eq) goto loc_8277D7F8;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277d808
	if (!cr6.eq) goto loc_8277D808;
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277d818
	if (!cr6.eq) goto loc_8277D818;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8277d810
	goto loc_8277D810;
loc_8277D7F8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D808;
	sub_8277CAE0(ctx, base);
loc_8277D808:
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
loc_8277D810:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D818;
	sub_8277CAE0(ctx, base);
loc_8277D818:
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8277d7c4
	if (cr6.lt) goto loc_8277D7C4;
loc_8277D82C:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r10,28(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8277d894
	if (cr6.eq) goto loc_8277D894;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D848;
	sub_8277C698(ctx, base);
	// li r4,221
	ctx.r4.s64 = 221;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D854;
	sub_8277C698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D860;
	sub_8277C698(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D86C;
	sub_8277C698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,188(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// srawi r11,r30,8
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0xFF) != 0);
	r11.s64 = r30.s32 >> 8;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// bl 0x8277c698
	ctx.lr = 0x8277D880;
	sub_8277C698(ctx, base);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D88C;
	sub_8277C698(ctx, base);
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r10,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r10.u32);
loc_8277D894:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277d038
	ctx.lr = 0x8277D89C;
	sub_8277D038(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8277D790) {
	__imp__sub_8277D790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D8A4) {
	__imp__sub_8277D8A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D8A8) {
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
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D8C4;
	sub_8277C698(ctx, base);
	// li r4,217
	ctx.r4.s64 = 217;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D8D0;
	sub_8277C698(ctx, base);
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

PPC_WEAK_FUNC(sub_8277D8A8) {
	__imp__sub_8277D8A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277D8E4) {
	__imp__sub_8277D8E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277D8E8) {
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
	ctx.lr = 0x8277D8F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D900;
	sub_8277C698(ctx, base);
	// li r4,216
	ctx.r4.s64 = 216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c698
	ctx.lr = 0x8277D90C;
	sub_8277C698(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,72
	r29.s64 = r31.s64 + 72;
loc_8277D914:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d92c
	if (cr6.eq) goto loc_8277D92C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277c720
	ctx.lr = 0x8277D92C;
	sub_8277C720(ctx, base);
loc_8277D92C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x8277d914
	if (cr6.lt) goto loc_8277D914;
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277d998
	if (!cr6.eq) goto loc_8277D998;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,104
	r29.s64 = r31.s64 + 104;
loc_8277D950:
	// lwz r11,-16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d96c
	if (cr6.eq) goto loc_8277D96C;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D96C;
	sub_8277CAE0(ctx, base);
loc_8277D96C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277d988
	if (cr6.eq) goto loc_8277D988;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277cae0
	ctx.lr = 0x8277D988;
	sub_8277CAE0(ctx, base);
loc_8277D988:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x8277d950
	if (cr6.lt) goto loc_8277D950;
loc_8277D998:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r30,24
	r30.s64 = 24;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addic. r10,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r10.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// bne 0x8277da00
	if (!cr0.eq) goto loc_8277DA00;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277D9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277da00
	if (!cr6.eq) goto loc_8277DA00;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277DA00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277DA00:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,217
	ctx.r10.s64 = 217;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// addic. r10,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r10.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bne 0x8277da64
	if (!cr0.eq) goto loc_8277DA64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277DA3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277da64
	if (!cr6.eq) goto loc_8277DA64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277DA64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277DA64:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8277D8E8) {
	__imp__sub_8277D8E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277DA6C) {
	__imp__sub_8277DA6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DA70) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277DA9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r3,332(r31)
	PPC_STORE_U32(r31.u32 + 332, ctx.r3.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// addi r10,r9,-10824
	ctx.r10.s64 = ctx.r9.s64 + -10824;
	// lis r5,-32136
	ctx.r5.s64 = -2106064896;
	// addi r9,r8,-10704
	ctx.r9.s64 = ctx.r8.s64 + -10704;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r4,-32136
	ctx.r4.s64 = -2106064896;
	// addi r8,r7,-10352
	ctx.r8.s64 = ctx.r7.s64 + -10352;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r7,r6,-10072
	ctx.r7.s64 = ctx.r6.s64 + -10072;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// addi r6,r5,-10008
	ctx.r6.s64 = ctx.r5.s64 + -10008;
	// addi r5,r4,-10960
	ctx.r5.s64 = ctx.r4.s64 + -10960;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// addi r4,r11,-10832
	ctx.r4.s64 = r11.s64 + -10832;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// stw r4,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r4.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
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

PPC_WEAK_FUNC(sub_8277DA70) {
	__imp__sub_8277DA70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DB10) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8278c480
	ctx.lr = 0x8277DB2C;
	sub_8278C480(ctx, base);
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277db54
	if (!cr6.eq) goto loc_8277DB54;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8278b270
	ctx.lr = 0x8277DB40;
	sub_8278B270(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8278ab90
	ctx.lr = 0x8277DB48;
	sub_8278AB90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8278a188
	ctx.lr = 0x8277DB54;
	sub_8278A188(ctx, base);
loc_8277DB54:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82789a30
	ctx.lr = 0x8277DB5C;
	sub_82789A30(ctx, base);
	// lbz r11,177(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277db8c
	if (cr6.eq) goto loc_8277DB8C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277DB88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277dba8
	goto loc_8277DBA8;
loc_8277DB8C:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277dba4
	if (cr6.eq) goto loc_8277DBA4;
	// bl 0x827885c8
	ctx.lr = 0x8277DBA0;
	sub_827885C8(ctx, base);
	// b 0x8277dba8
	goto loc_8277DBA8;
loc_8277DBA4:
	// bl 0x82787518
	ctx.lr = 0x8277DBA8;
	sub_82787518(ctx, base);
loc_8277DBA8:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x8277dbc4
	if (cr6.gt) goto loc_8277DBC4;
	// lbz r11,178(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 178);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277dbc8
	if (cr6.eq) goto loc_8277DBC8;
loc_8277DBC4:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8277DBC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82786088
	ctx.lr = 0x8277DBD0;
	sub_82786088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82785700
	ctx.lr = 0x8277DBDC;
	sub_82785700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277da70
	ctx.lr = 0x8277DBE4;
	sub_8277DA70(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277DBF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,332(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277DC0C;
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
}

PPC_WEAK_FUNC(sub_8277DB10) {
	__imp__sub_8277DB10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DC20) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x821bc130
	sub_821BC130(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8277DC20) {
	__imp__sub_8277DC20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DC28) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277DC28) {
	__imp__sub_8277DC28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DC30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,49
	ctx.r10.s64 = 49;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8277DC30) {
	__imp__sub_8277DC30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277DC4C) {
	__imp__sub_8277DC4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DC50) {
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
	ctx.lr = 0x8277DC58;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r27,388(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// lwz r30,280(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277DC84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,56(r27)
	PPC_STORE_U32(r27.u32 + 56, ctx.r3.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r3
	ctx.r7.u64 = r11.u64 + ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// stw r7,60(r27)
	PPC_STORE_U32(r27.u32 + 60, ctx.r7.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ble cr6,0x8277dd38
	if (!cr6.gt) goto loc_8277DD38;
	// addi r26,r30,4
	r26.s64 = r30.s64 + 4;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8277DCB8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,280(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r25,r8,r9
	r25.s32 = ctx.r8.s32 / ctx.r9.s32;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// mullw r24,r26,r25
	r24.s64 = int64_t(r26.s32) * int64_t(r25.s32);
	// andc r11,r9,r5
	r11.u64 = ctx.r9.u64 & ~ctx.r5.u64;
	// twllei r9,0
	// rlwinm r5,r24,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 3) & 0xFFFFFFF8;
	// twlgei r11,-1
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277DD00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r8,r25,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,56(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 56);
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r8
	r11.u64 = ctx.r3.u64 + ctx.r8.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// stwx r11,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + r29.u32, r11.u32);
	// lwz r6,60(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 60);
	// stwx r7,r29,r6
	PPC_STORE_U32(r29.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r28,r5
	cr6.compare<int32_t>(r28.s32, ctx.r5.s32, xer);
	// blt cr6,0x8277dcb8
	if (cr6.lt) goto loc_8277DCB8;
loc_8277DD38:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8277DC50) {
	__imp__sub_8277DC50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DD40) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8277DD48;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r25,0
	r25.s64 = 0;
	// lwz r28,388(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r27,280(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// ble cr6,0x8277de70
	if (!cr6.gt) goto loc_8277DE70;
	// addi r26,r27,2
	r26.s64 = r27.s64 + 2;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
loc_8277DD74:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,280(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// mullw r5,r11,r10
	ctx.r5.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,56(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r7,r5,r6
	ctx.r7.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// twllei r6,0
	// andc r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 & ~ctx.r10.u64;
	// mullw. r9,r26,r7
	ctx.r9.s64 = int64_t(r26.s32) * int64_t(ctx.r7.s32);
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// twlgei r6,-1
	// ble 0x8277dddc
	if (!cr0.gt) goto loc_8277DDDC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// subf r5,r11,r4
	ctx.r5.s64 = ctx.r4.s64 - r11.s64;
loc_8277DDC4:
	// lwzx r24,r6,r10
	r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r24,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r24.u32);
	// stwx r24,r5,r10
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, r24.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8277ddc4
	if (!cr0.eq) goto loc_8277DDC4;
loc_8277DDDC:
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8277de30
	if (!cr6.gt) goto loc_8277DE30;
	// addi r10,r27,-2
	ctx.r10.s64 = r27.s64 + -2;
	// mullw r9,r7,r27
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(r27.s32);
	// mullw r6,r10,r7
	ctx.r6.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// subf r8,r8,r11
	ctx.r8.s64 = r11.s64 - ctx.r8.s64;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_8277DE10:
	// lwzx r5,r9,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r5,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8277de10
	if (!cr0.eq) goto loc_8277DE10;
loc_8277DE30:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8277de54
	if (!cr6.gt) goto loc_8277DE54;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
loc_8277DE40:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8277de40
	if (!cr0.eq) goto loc_8277DE40;
loc_8277DE54:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8277dd74
	if (cr6.lt) goto loc_8277DD74;
loc_8277DE70:
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8277DD40) {
	__imp__sub_8277DD40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277DE74) {
	__imp__sub_8277DE74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DE78) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8277DE80;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r29,0
	r29.s64 = 0;
	// lwz r30,388(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r31,280(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// ble cr6,0x8277df5c
	if (!cr6.gt) goto loc_8277DF5C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
loc_8277DEA4:
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r8,280(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r6,56(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// lwzx r6,r5,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwzx r11,r5,r11
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// rotlwi r9,r7,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw. r10,r7,r8
	ctx.r10.s32 = ctx.r7.s32 / ctx.r8.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// twllei r8,0
	// andc r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	// ble 0x8277df44
	if (!cr0.gt) goto loc_8277DF44;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r10,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + r11.u64;
	// subf r8,r28,r11
	ctx.r8.s64 = r11.s64 - r28.s64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// subf r6,r11,r6
	ctx.r6.s64 = ctx.r6.s64 - r11.s64;
loc_8277DF0C:
	// lwzx r28,r6,r9
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwx r28,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, r28.u32);
	// lwz r28,0(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r28,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r28.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// lwzx r28,r6,r11
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// stwx r28,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, r28.u32);
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r28,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r28.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8277df0c
	if (!cr0.eq) goto loc_8277DF0C;
loc_8277DF44:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r4,r4,84
	ctx.r4.s64 = ctx.r4.s64 + 84;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277dea4
	if (cr6.lt) goto loc_8277DEA4;
loc_8277DF5C:
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8277DE78) {
	__imp__sub_8277DE78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277DF60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,388(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277e048
	if (!cr6.gt) goto loc_8277E048;
	// addi r7,r11,12
	ctx.r7.s64 = r11.s64 + 12;
loc_8277DF80:
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// lwz r9,32(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,280(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divwu r4,r9,r11
	ctx.r4.u32 = ctx.r9.u32 / r11.u32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r4,r4,r11
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(r11.s32);
	// andc r31,r8,r10
	r31.u64 = ctx.r8.u64 & ~ctx.r10.u64;
	// subf. r10,r4,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r4.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// twllei r11,0
	// divw r9,r11,r8
	ctx.r9.s32 = r11.s32 / ctx.r8.s32;
	// twllei r8,0
	// twlgei r31,-1
	// bne 0x8277dfc4
	if (!cr0.eq) goto loc_8277DFC4;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8277DFC4:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x8277dff0
	if (!cr6.eq) goto loc_8277DFF0;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// twllei r9,0
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r11,r11,r9
	r11.s32 = r11.s32 / ctx.r9.s32;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// andc r11,r9,r8
	r11.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// stw r4,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r4.u32);
	// twlgei r11,-1
loc_8277DFF0:
	// lwz r8,64(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r8,14
	ctx.r9.s64 = ctx.r8.s64 + 14;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r8,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	// lwzx r9,r9,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// ble cr6,0x8277e034
	if (!cr6.gt) goto loc_8277E034;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8277E020:
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8277e020
	if (!cr0.eq) goto loc_8277E020;
loc_8277E034:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,84
	ctx.r7.s64 = ctx.r7.s64 + 84;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// blt cr6,0x8277df80
	if (cr6.lt) goto loc_8277DF80;
loc_8277E048:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277DF60) {
	__imp__sub_8277DF60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E050) {
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
	ctx.lr = 0x8277E058;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r30,388(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// lbz r11,48(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277e0a0
	if (!cr6.eq) goto loc_8277E0A0;
	// lwz r11,392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8277e0ec
	if (cr6.eq) goto loc_8277E0EC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,48(r30)
	PPC_STORE_U8(r30.u32 + 48, r11.u8);
loc_8277E0A0:
	// lwz r11,396(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// addi r29,r30,52
	r29.s64 = r30.s64 + 52;
	// lwz r25,280(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,52(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplw cr6,r9,r25
	cr6.compare<uint32_t>(ctx.r9.u32, r25.u32, xer);
	// blt cr6,0x8277e0ec
	if (cr6.lt) goto loc_8277E0EC;
	// li r11,0
	r11.s64 = 0;
	// stb r11,48(r30)
	PPC_STORE_U8(r30.u32 + 48, r11.u8);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8277E0EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277E050) {
	__imp__sub_8277E050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277E0F4) {
	__imp__sub_8277E0F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E0F8) {
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
	ctx.lr = 0x8277E100;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r24,1
	r24.s64 = 1;
	// lwz r31,388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 388);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277e160
	if (!cr6.eq) goto loc_8277E160;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r10,392(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// addi r9,r11,14
	ctx.r9.s64 = r11.s64 + 14;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277E148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8277e290
	if (cr6.eq) goto loc_8277E290;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stb r24,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r24.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_8277E160:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8277e1d4
	if (cr6.lt) goto loc_8277E1D4;
	// beq cr6,0x8277e200
	if (cr6.eq) goto loc_8277E200;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8277e290
	if (!cr6.lt) goto loc_8277E290;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r5,r31,52
	ctx.r5.s64 = r31.s64 + 52;
	// lwz r10,396(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r7,r11,14
	ctx.r7.s64 = r11.s64 + 14;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r4,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277E1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8277e290
	if (cr6.lt) goto loc_8277E290;
	// stw r25,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r25.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x8277e290
	if (!cr6.lt) goto loc_8277E290;
loc_8277E1D4:
	// stw r25,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r25.u32);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// lwz r8,284(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x8277e1fc
	if (!cr6.eq) goto loc_8277E1FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277df60
	ctx.lr = 0x8277E1FC;
	sub_8277DF60(ctx, base);
loc_8277E1FC:
	// stw r24,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r24.u32);
loc_8277E200:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r29,r31,52
	r29.s64 = r31.s64 + 52;
	// lwz r10,396(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r7,r11,14
	ctx.r7.s64 = r11.s64 + 14;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r4,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277E23C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8277e290
	if (cr6.lt) goto loc_8277E290;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8277e260
	if (!cr6.eq) goto loc_8277E260;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277de78
	ctx.lr = 0x8277E260;
	sub_8277DE78(ctx, base);
loc_8277E260:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r25,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r25.u8);
	// xori r9,r11,1
	ctx.r9.u64 = r11.u64 ^ 1;
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lwz r11,280(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 280);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
loc_8277E290:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8277E0F8) {
	__imp__sub_8277E0F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,396(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8277E298) {
	__imp__sub_8277E298(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E2C0) {
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
	// lwz r31,388(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8277e318
	if (cr6.eq) goto loc_8277E318;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8277e308
	if (cr6.eq) goto loc_8277E308;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277E304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277e360
	goto loc_8277E360;
loc_8277E308:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,-7528
	ctx.r10.s64 = r11.s64 + -7528;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// b 0x8277e360
	goto loc_8277E360;
loc_8277E318:
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// li r30,0
	r30.s64 = 0;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277e34c
	if (cr6.eq) goto loc_8277E34C;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,-7944
	ctx.r10.s64 = r11.s64 + -7944;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x8277dd40
	ctx.lr = 0x8277E33C;
	sub_8277DD40(ctx, base);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// b 0x8277e358
	goto loc_8277E358;
loc_8277E34C:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,-8112
	ctx.r10.s64 = r11.s64 + -8112;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_8277E358:
	// stb r30,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r30.u8);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
loc_8277E360:
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

PPC_WEAK_FUNC(sub_8277E2C0) {
	__imp__sub_8277E2C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E378) {
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
	ctx.lr = 0x8277E380;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E3A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// stw r29,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r29.u32);
	// addi r7,r9,-7488
	ctx.r7.s64 = ctx.r9.s64 + -7488;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// beq cr6,0x8277e3e4
	if (cr6.eq) goto loc_8277E3E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277E3E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277E3E4:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277e434
	if (cr6.eq) goto loc_8277E434;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x8277e420
	if (!cr6.lt) goto loc_8277E420;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,47
	ctx.r10.s64 = 47;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277E420;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277E420:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277dc50
	ctx.lr = 0x8277E428;
	sub_8277DC50(ctx, base);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// addi r27,r11,2
	r27.s64 = r11.s64 + 2;
	// b 0x8277e438
	goto loc_8277E438;
loc_8277E434:
	// lwz r27,280(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 280);
loc_8277E438:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277e4bc
	if (!cr6.gt) goto loc_8277E4BC;
	// addi r30,r11,36
	r30.s64 = r11.s64 + 36;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
loc_8277E454:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,-24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,280(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,-8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// lwz r9,8(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// rotlwi r11,r7,1
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r7,r7,r8
	ctx.r7.s32 = ctx.r7.s32 / ctx.r8.s32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r8,0
	// andc r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & ~r11.u64;
	// mullw r6,r7,r27
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r27.s32);
	// mullw r5,r5,r10
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// twlgei r8,-1
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277E4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r28,r7
	cr6.compare<int32_t>(r28.s32, ctx.r7.s32, xer);
	// blt cr6,0x8277e454
	if (cr6.lt) goto loc_8277E454;
loc_8277E4BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8277E378) {
	__imp__sub_8277E378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277E4C4) {
	__imp__sub_8277E4C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E4C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,292(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 292);
	// lwz r11,392(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x8277e4f0
	if (!cr6.gt) goto loc_8277E4F0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// blr 
	return;
loc_8277E4F0:
	// lwz r10,284(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r10,296(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bge cr6,0x8277e520
	if (!cr6.lt) goto loc_8277E520;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// blr 
	return;
loc_8277E520:
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8277E4C8) {
	__imp__sub_8277E4C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// b 0x8277e4c8
	sub_8277E4C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8277E538) {
	__imp__sub_8277E538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277E544) {
	__imp__sub_8277E544(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E548) {
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
	ctx.lr = 0x8277E550;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// lwz r11,312(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 312);
	// lwz r18,392(r26)
	r18.u64 = PPC_LOAD_U32(r26.u32 + 392);
	// addi r14,r11,-1
	r14.s64 = r11.s64 + -1;
	// lwz r11,284(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 284);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r19,24(r18)
	r19.u64 = PPC_LOAD_U32(r18.u32 + 24);
	// lwz r10,28(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmpw cr6,r19,r10
	cr6.compare<int32_t>(r19.s32, ctx.r10.s32, xer);
	// bge cr6,0x8277e718
	if (!cr6.lt) goto loc_8277E718;
loc_8277E584:
	// lwz r20,20(r18)
	r20.u64 = PPC_LOAD_U32(r18.u32 + 20);
	// cmplw cr6,r20,r14
	cr6.compare<uint32_t>(r20.u32, r14.u32, xer);
	// bgt cr6,0x8277e700
	if (cr6.gt) goto loc_8277E700;
loc_8277E590:
	// lwz r11,320(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 320);
	// addi r31,r18,32
	r31.s64 = r18.s64 + 32;
	// lwz r3,32(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + 32);
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// bl 0x8277a3e8
	ctx.lr = 0x8277E5A4;
	sub_8277A3E8(ctx, base);
	// lwz r10,408(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 408);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277E5BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8277e76c
	if (cr6.eq) goto loc_8277E76C;
	// lwz r11,292(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// li r23,0
	r23.s64 = 0;
	// li r15,0
	r15.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277e6f4
	if (!cr6.gt) goto loc_8277E6F4;
	// addi r16,r26,296
	r16.s64 = r26.s64 + 296;
loc_8277E5E0:
	// lwz r31,0(r16)
	r31.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277e5fc
	if (!cr6.eq) goto loc_8277E5FC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
	// b 0x8277e6e0
	goto loc_8277E6E0;
loc_8277E5FC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r20,r14
	cr6.compare<uint32_t>(r20.u32, r14.u32, xer);
	// lwz r10,412(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 412);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r24,4(r10)
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bge cr6,0x8277e620
	if (!cr6.lt) goto loc_8277E620;
	// lwz r22,52(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x8277e624
	goto loc_8277E624;
loc_8277E620:
	// lwz r22,68(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 68);
loc_8277E624:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r25,0
	r25.s64 = 0;
	// lwzx r10,r11,r17
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r17.u32);
	// mullw r8,r9,r19
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r19.s32);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r6,56(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r21,r7,r20
	r21.s64 = int64_t(ctx.r7.s32) * int64_t(r20.s32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// add r27,r11,r10
	r27.u64 = r11.u64 + ctx.r10.u64;
	// ble cr6,0x8277e6e0
	if (!cr6.gt) goto loc_8277E6E0;
loc_8277E650:
	// lwz r11,128(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8277e670
	if (cr6.lt) goto loc_8277E670;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// add r10,r25,r19
	ctx.r10.u64 = r25.u64 + r19.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8277e6bc
	if (!cr6.lt) goto loc_8277E6BC;
loc_8277E670:
	// mr r28,r21
	r28.u64 = r21.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x8277e6bc
	if (!cr6.gt) goto loc_8277E6BC;
	// addi r11,r23,8
	r11.s64 = r23.s64 + 8;
	// mr r30,r22
	r30.u64 = r22.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r18
	r29.u64 = r11.u64 + r18.u64;
loc_8277E68C:
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mtctr r24
	ctr.u64 = r24.u64;
	// bctrl 
	ctx.lr = 0x8277E6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// bne 0x8277e68c
	if (!cr0.eq) goto loc_8277E68C;
loc_8277E6BC:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r23,r10,r23
	r23.u64 = ctx.r10.u64 + r23.u64;
	// add r27,r11,r27
	r27.u64 = r11.u64 + r27.u64;
	// cmpw cr6,r25,r9
	cr6.compare<int32_t>(r25.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277e650
	if (cr6.lt) goto loc_8277E650;
loc_8277E6E0:
	// lwz r11,292(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// addi r16,r16,4
	r16.s64 = r16.s64 + 4;
	// cmpw cr6,r15,r11
	cr6.compare<int32_t>(r15.s32, r11.s32, xer);
	// blt cr6,0x8277e5e0
	if (cr6.lt) goto loc_8277E5E0;
loc_8277E6F4:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// cmplw cr6,r20,r14
	cr6.compare<uint32_t>(r20.u32, r14.u32, xer);
	// ble cr6,0x8277e590
	if (!cr6.gt) goto loc_8277E590;
loc_8277E700:
	// li r11,0
	r11.s64 = 0;
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// stw r11,20(r18)
	PPC_STORE_U32(r18.u32 + 20, r11.u32);
	// lwz r10,28(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// cmpw cr6,r19,r10
	cr6.compare<int32_t>(r19.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277e584
	if (cr6.lt) goto loc_8277E584;
loc_8277E718:
	// lwz r11,136(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 136);
	// lwz r10,284(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 284);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r11,128(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 128);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r9,136(r26)
	PPC_STORE_U32(r26.u32 + 136, ctx.r9.u32);
	// stw r11,128(r26)
	PPC_STORE_U32(r26.u32 + 128, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8277e7b8
	if (!cr6.lt) goto loc_8277E7B8;
	// lwz r8,292(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// lwz r9,392(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 392);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x8277e780
	if (!cr6.gt) goto loc_8277E780;
	// li r11,1
	r11.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r11.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// stw r11,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_8277E76C:
	// stw r19,24(r18)
	PPC_STORE_U32(r18.u32 + 24, r19.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r20,20(r18)
	PPC_STORE_U32(r18.u32 + 20, r20.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_8277E780:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// lwz r11,296(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 296);
	// bge cr6,0x8277e798
	if (!cr6.lt) goto loc_8277E798;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x8277e79c
	goto loc_8277E79C;
loc_8277E798:
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
loc_8277E79C:
	// li r11,0
	r11.s64 = 0;
	// stw r10,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r10.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// stw r11,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
loc_8277E7B8:
	// lwz r11,400(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 400);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E7CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_8277E548) {
	__imp__sub_8277E548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277E7D8) {
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
	ctx.lr = 0x8277E7E0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r29,r25
	r29.u64 = r25.u64;
	// lwz r11,292(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// lwz r27,392(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 392);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277e860
	if (!cr6.gt) goto loc_8277E860;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,296
	r31.s64 = r28.s64 + 296;
loc_8277E808:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,128(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r4,r11,18
	ctx.r4.s64 = r11.s64 + 18;
	// lwz r11,32(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r5,r8,r5
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// lwzx r4,r10,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277E844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,292(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277e808
	if (cr6.lt) goto loc_8277E808;
loc_8277E860:
	// lwz r23,24(r27)
	r23.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// bge cr6,0x8277e984
	if (!cr6.lt) goto loc_8277E984;
	// rlwinm r24,r23,2,0,29
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
loc_8277E874:
	// lwz r26,20(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r11,312(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 312);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bge cr6,0x8277e96c
	if (!cr6.lt) goto loc_8277E96C;
	// addi r22,r27,32
	r22.s64 = r27.s64 + 32;
loc_8277E888:
	// lwz r11,292(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277e938
	if (!cr6.gt) goto loc_8277E938;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,296
	r31.s64 = r28.s64 + 296;
loc_8277E8A4:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,52(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// lwz r10,56(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mullw r11,r8,r26
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r26.s32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277e920
	if (!cr6.gt) goto loc_8277E920;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r4,r11,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r5,r24,r10
	ctx.r5.u64 = r24.u64 + ctx.r10.u64;
loc_8277E8CC:
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r9,r11,r4
	ctx.r9.u64 = r11.u64 + ctx.r4.u64;
	// ble cr6,0x8277e90c
	if (!cr6.gt) goto loc_8277E90C;
	// addi r11,r6,8
	r11.s64 = ctx.r6.s64 + 8;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
loc_8277E8EC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,52(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8277e8ec
	if (cr6.lt) goto loc_8277E8EC;
loc_8277E90C:
	// lwz r11,56(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x8277e8cc
	if (cr6.lt) goto loc_8277E8CC;
loc_8277E920:
	// lwz r11,292(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277e8a4
	if (cr6.lt) goto loc_8277E8A4;
loc_8277E938:
	// lwz r11,408(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 408);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277E950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277e9c8
	if (cr6.eq) goto loc_8277E9C8;
	// lwz r11,312(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 312);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x8277e888
	if (cr6.lt) goto loc_8277E888;
loc_8277E96C:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// stw r25,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r25.u32);
	// lwz r11,28(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x8277e874
	if (cr6.lt) goto loc_8277E874;
loc_8277E984:
	// lwz r11,128(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r9,284(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 284);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,128(r28)
	PPC_STORE_U32(r28.u32 + 128, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8277ea24
	if (!cr6.lt) goto loc_8277EA24;
	// lwz r8,292(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 292);
	// lwz r10,392(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 392);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x8277e9dc
	if (!cr6.gt) goto loc_8277E9DC;
	// li r11,1
	r11.s64 = 1;
	// stw r25,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r25.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// stw r11,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277E9C8:
	// stw r23,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r23.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r26,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277E9DC:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// lwz r11,296(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 296);
	// bge cr6,0x8277ea08
	if (!cr6.lt) goto loc_8277EA08;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r25,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r25.u32);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277EA08:
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r25,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r25.u32);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_8277EA24:
	// lwz r11,400(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 400);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277EA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_8277E7D8) {
	__imp__sub_8277E7D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277EA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277EA44) {
	__imp__sub_8277EA44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277EA48) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8277EA50;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// lwz r30,392(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 392);
	// addi r18,r11,-1
	r18.s64 = r11.s64 + -1;
loc_8277EA68:
	// lwz r11,124(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 124);
	// lwz r10,132(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277ea8c
	if (cr6.lt) goto loc_8277EA8C;
	// bne cr6,0x8277eab0
	if (!cr6.eq) goto loc_8277EAB0;
	// lwz r11,128(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 128);
	// lwz r10,136(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8277eab0
	if (cr6.gt) goto loc_8277EAB0;
loc_8277EA8C:
	// lwz r11,400(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 400);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277EAA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8277ea68
	if (!cr6.eq) goto loc_8277EA68;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
loc_8277EAB0:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// li r20,0
	r20.s64 = 0;
	// lwz r31,196(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277ebdc
	if (!cr6.gt) goto loc_8277EBDC;
	// li r22,0
	r22.s64 = 0;
	// addi r21,r30,72
	r21.s64 = r30.s64 + 72;
loc_8277EACC:
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ebc0
	if (cr6.eq) goto loc_8277EBC0;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,136(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// lwz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// mullw r5,r9,r10
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277EB04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,136(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// cmplw cr6,r7,r18
	cr6.compare<uint32_t>(ctx.r7.u32, r18.u32, xer);
	// bge cr6,0x8277eb18
	if (!cr6.lt) goto loc_8277EB18;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// b 0x8277eb38
	goto loc_8277EB38;
loc_8277EB18:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// twllei r10,0
	// divwu r9,r11,r10
	ctx.r9.u32 = r11.u32 / ctx.r10.u32;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf. r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8277eb38
	if (!cr0.eq) goto loc_8277EB38;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277EB38:
	// lwz r10,412(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 412);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwzx r26,r22,r19
	r26.u64 = PPC_LOAD_U32(r22.u32 + r19.u32);
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + r22.u64;
	// lwz r25,4(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// ble cr6,0x8277ebc0
	if (!cr6.gt) goto loc_8277EBC0;
	// mr r23,r11
	r23.u64 = r11.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_8277EB5C:
	// lwz r29,0(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277eba8
	if (cr6.eq) goto loc_8277EBA8;
loc_8277EB70:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r25
	ctr.u64 = r25.u64;
	// bctrl 
	ctx.lr = 0x8277EB8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,128
	r29.s64 = r29.s64 + 128;
	// add r28,r28,r10
	r28.u64 = r28.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8277eb70
	if (cr6.lt) goto loc_8277EB70;
loc_8277EBA8:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r10,r26
	r26.u64 = ctx.r10.u64 + r26.u64;
	// bne 0x8277eb5c
	if (!cr0.eq) goto loc_8277EB5C;
loc_8277EBC0:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r20,r11
	cr6.compare<int32_t>(r20.s32, r11.s32, xer);
	// blt cr6,0x8277eacc
	if (cr6.lt) goto loc_8277EACC;
loc_8277EBDC:
	// lwz r11,136(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// lwz r10,284(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,136(r27)
	PPC_STORE_U32(r27.u32 + 136, r11.u32);
	// subfe r11,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_8277EA48) {
	__imp__sub_8277EA48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277EC00) {
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
	ctx.lr = 0x8277EC08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lbz r11,200(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 200);
	// lwz r31,392(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277ec64
	if (!cr6.eq) goto loc_8277EC64;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r5,r8,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277EC60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
loc_8277EC64:
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277ed84
	if (!cr6.gt) goto loc_8277ED84;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r11,76
	ctx.r6.s64 = r11.s64 + 76;
loc_8277EC84:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lhz r11,4(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ed90
	if (cr6.eq) goto loc_8277ED90;
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8277ed90
	if (cr6.lt) goto loc_8277ED90;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed04
	if (cr6.eq) goto loc_8277ED04;
	// li r29,1
	r29.s64 = 1;
loc_8277ED04:
	// li r10,8
	ctx.r10.s64 = 8;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8277ed20
	if (cr6.eq) goto loc_8277ED20;
	// li r29,1
	r29.s64 = 1;
loc_8277ED20:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed38
	if (cr6.eq) goto loc_8277ED38;
	// li r29,1
	r29.s64 = 1;
loc_8277ED38:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r10,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed50
	if (cr6.eq) goto loc_8277ED50;
	// li r29,1
	r29.s64 = 1;
loc_8277ED50:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8277ed68
	if (cr6.eq) goto loc_8277ED68;
	// li r29,1
	r29.s64 = 1;
loc_8277ED68:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// addi r8,r8,256
	ctx.r8.s64 = ctx.r8.s64 + 256;
	// addi r6,r6,84
	ctx.r6.s64 = ctx.r6.s64 + 84;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8277ec84
	if (cr6.lt) goto loc_8277EC84;
loc_8277ED84:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277ED90:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8277EC00) {
	__imp__sub_8277EC00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277ED9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277ED9C) {
	__imp__sub_8277ED9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277EDA0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8277EDA8;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r30,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, r30.u32);
	// lwz r10,392(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// lwz r9,132(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// lwz r8,124(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// bgt cr6,0x8277ee44
	if (cr6.gt) goto loc_8277EE44;
loc_8277EDDC:
	// lwz r9,400(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 400);
	// lbz r11,17(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277ee44
	if (!cr6.eq) goto loc_8277EE44;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8277ee1c
	if (!cr6.eq) goto loc_8277EE1C;
	// lwz r10,364(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r7,128(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// rlwinm r10,r8,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bgt cr6,0x8277ee44
	if (cr6.gt) goto loc_8277EE44;
loc_8277EE1C:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277EE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8277eeb4
	if (cr6.eq) goto loc_8277EEB4;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x8277eddc
	if (!cr6.gt) goto loc_8277EDDC;
loc_8277EE44:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r16,196(r30)
	r16.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277f530
	if (!cr6.gt) goto loc_8277F530;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r14,1
	r14.s64 = 1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// addi r9,r11,72
	ctx.r9.s64 = r11.s64 + 72;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// subfic r8,r11,-72
	xer.ca = r11.u32 <= 4294967224;
	ctx.r8.s64 = -72 - r11.s64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
loc_8277EE7C:
	// lbz r11,48(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f4ec
	if (cr6.eq) goto loc_8277F4EC;
	// lwz r31,468(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// lwz r11,12(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// bge cr6,0x8277eec0
	if (!cr6.lt) goto loc_8277EEC0;
	// mr r28,r11
	r28.u64 = r11.u64;
	// li r30,0
	r30.s64 = 0;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// b 0x8277eeec
	goto loc_8277EEEC;
loc_8277EEB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9210
	return;
loc_8277EEC0:
	// lwz r9,32(r16)
	ctx.r9.u64 = PPC_LOAD_U32(r16.u32 + 32);
	// twllei r11,0
	// divwu r8,r9,r11
	ctx.r8.u32 = ctx.r9.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf. r28,r7,r9
	r28.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// bne 0x8277eee4
	if (!cr0.eq) goto loc_8277EEE4;
	// mr r28,r11
	r28.u64 = r11.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8277EEE4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r30,r14
	r30.u64 = r14.u64;
loc_8277EEEC:
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// beq cr6,0x8277ef38
	if (cr6.eq) goto loc_8277EF38;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// add r6,r11,r6
	ctx.r6.u64 = r11.u64 + ctx.r6.u64;
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,32(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277EF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,12(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r3
	ctx.r8.u64 = r11.u64 + ctx.r3.u64;
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// b 0x8277ef58
	goto loc_8277EF58;
loc_8277EF38:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277EF50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
loc_8277EF58:
	// lwz r11,412(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r7,76(r16)
	ctx.r7.u64 = PPC_LOAD_U32(r16.u32 + 76);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,112(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// add r5,r10,r3
	ctx.r5.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lhz r11,2(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// lhz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 16);
	// lhz r3,32(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 32);
	// lhz r10,18(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 18);
	// lhz r31,4(r7)
	r31.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lhz r15,0(r7)
	r15.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r4,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r4.u32);
	// ble cr6,0x8277f4ec
	if (!cr6.gt) goto loc_8277F4EC;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
loc_8277EFE0:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,132(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,148(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r19,0(r11)
	r19.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x8277f00c
	if (cr6.eq) goto loc_8277F00C;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// beq cr6,0x8277f010
	if (cr6.eq) goto loc_8277F010;
loc_8277F00C:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
loc_8277F010:
	// lwz r8,140(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8277f034
	if (cr6.eq) goto loc_8277F034;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// bne cr6,0x8277f034
	if (!cr6.eq) goto loc_8277F034;
	// mr r11,r19
	r11.u64 = r19.u64;
	// b 0x8277f038
	goto loc_8277F038;
loc_8277F034:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8277F038:
	// lhz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// li r20,0
	r20.s64 = 0;
	// lhz r8,0(r19)
	ctx.r8.u64 = PPC_LOAD_U16(r19.u32 + 0);
	// li r21,0
	r21.s64 = 0;
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// extsh r25,r10
	r25.s64 = ctx.r10.s16;
	// lwz r10,28(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 28);
	// extsh r28,r8
	r28.s64 = ctx.r8.s16;
	// extsh r24,r7
	r24.s64 = ctx.r7.s16;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r22,r24
	r22.u64 = r24.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r27,r28
	r27.u64 = r28.u64;
	// mr r29,r24
	r29.u64 = r24.u64;
	// addi r31,r10,-1
	r31.s64 = ctx.r10.s64 + -1;
	// addi r17,r11,128
	r17.s64 = r11.s64 + 128;
	// addi r18,r9,128
	r18.s64 = ctx.r9.s64 + 128;
loc_8277F080:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8277a3d0
	ctx.lr = 0x8277F090;
	sub_8277A3D0(ctx, base);
	// cmplw cr6,r21,r31
	cr6.compare<uint32_t>(r21.u32, r31.u32, xer);
	// bge cr6,0x8277f0b0
	if (!cr6.lt) goto loc_8277F0B0;
	// lhz r11,0(r18)
	r11.u64 = PPC_LOAD_U16(r18.u32 + 0);
	// lhz r10,128(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 128);
	// lhz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U16(r17.u32 + 0);
	// extsh r25,r11
	r25.s64 = r11.s16;
	// extsh r28,r10
	r28.s64 = ctx.r10.s16;
	// extsh r24,r9
	r24.s64 = ctx.r9.s16;
loc_8277F0B0:
	// lwz r7,144(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277f174
	if (cr6.eq) goto loc_8277F174;
	// lhz r11,162(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 162);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f174
	if (!cr6.eq) goto loc_8277F174;
	// subf r11,r28,r27
	r11.s64 = r27.s64 - r28.s64;
	// mullw r11,r11,r15
	r11.s64 = int64_t(r11.s32) * int64_t(r15.s32);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277f12c
	if (cr6.lt) goto loc_8277F12C;
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r8,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f170
	if (!cr6.gt) goto loc_8277F170;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f170
	if (cr6.lt) goto loc_8277F170;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f170
	goto loc_8277F170;
loc_8277F12C:
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r9,r5,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f16c
	if (!cr6.gt) goto loc_8277F16C;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f16c
	if (cr6.lt) goto loc_8277F16C;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F16C:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F170:
	// sth r11,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r11.u16);
loc_8277F174:
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277f234
	if (cr6.eq) goto loc_8277F234;
	// lhz r11,176(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f234
	if (!cr6.eq) goto loc_8277F234;
	// subf r11,r22,r23
	r11.s64 = r23.s64 - r22.s64;
	// mullw r11,r11,r15
	r11.s64 = int64_t(r11.s32) * int64_t(r15.s32);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277f1ec
	if (cr6.lt) goto loc_8277F1EC;
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r8,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f230
	if (!cr6.gt) goto loc_8277F230;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f230
	if (cr6.lt) goto loc_8277F230;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f230
	goto loc_8277F230;
loc_8277F1EC:
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r8,r9,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r9,r5,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f22c
	if (!cr6.gt) goto loc_8277F22C;
	// slw r10,r14,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f22c
	if (cr6.lt) goto loc_8277F22C;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F22C:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F230:
	// sth r11,176(r1)
	PPC_STORE_U16(ctx.r1.u32 + 176, r11.u16);
loc_8277F234:
	// lwz r9,12(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8277f2f0
	if (cr6.eq) goto loc_8277F2F0;
	// lhz r11,192(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f2f0
	if (!cr6.eq) goto loc_8277F2F0;
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r11,r11,r22
	r11.s64 = r22.s64 - r11.s64;
	// add r10,r11,r23
	ctx.r10.u64 = r11.u64 + r23.u64;
	// mullw r11,r10,r15
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r15.s32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8277f2ac
	if (cr0.lt) goto loc_8277F2AC;
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f2ec
	if (!cr6.gt) goto loc_8277F2EC;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f2ec
	if (cr6.lt) goto loc_8277F2EC;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f2ec
	goto loc_8277F2EC;
loc_8277F2AC:
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f2e8
	if (!cr6.gt) goto loc_8277F2E8;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f2e8
	if (cr6.lt) goto loc_8277F2E8;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F2E8:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F2EC:
	// sth r11,192(r1)
	PPC_STORE_U16(ctx.r1.u32 + 192, r11.u16);
loc_8277F2F0:
	// lwz r9,16(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8277f3ac
	if (cr6.eq) goto loc_8277F3AC;
	// lhz r11,178(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 178);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f3ac
	if (!cr6.eq) goto loc_8277F3AC;
	// subf r11,r29,r24
	r11.s64 = r24.s64 - r29.s64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r11,r25,r11
	r11.s64 = r11.s64 - r25.s64;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// mullw r11,r10,r15
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r15.s32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8277f368
	if (cr0.lt) goto loc_8277F368;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r8
	r11.s32 = ctx.r6.s32 / ctx.r8.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// andc r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f3a8
	if (!cr6.gt) goto loc_8277F3A8;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f3a8
	if (cr6.lt) goto loc_8277F3A8;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f3a8
	goto loc_8277F3A8;
loc_8277F368:
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - r11.s64;
	// twllei r6,0
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// andc r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// ble cr6,0x8277f3a4
	if (!cr6.gt) goto loc_8277F3A4;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f3a4
	if (cr6.lt) goto loc_8277F3A4;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F3A4:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F3A8:
	// sth r11,178(r1)
	PPC_STORE_U16(ctx.r1.u32 + 178, r11.u16);
loc_8277F3AC:
	// lwz r9,20(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8277f468
	if (cr6.eq) goto loc_8277F468;
	// lhz r11,164(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f468
	if (!cr6.eq) goto loc_8277F468;
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// mullw r11,r10,r15
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r15.s32);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8277f424
	if (cr0.lt) goto loc_8277F424;
	// lwz r8,124(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// rlwinm r10,r8,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r11,r7,r8
	r11.s32 = ctx.r7.s32 / ctx.r8.s32;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// andc r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r6.u64;
	// twlgei r5,-1
	// ble cr6,0x8277f464
	if (!cr6.gt) goto loc_8277F464;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f464
	if (cr6.lt) goto loc_8277F464;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x8277f464
	goto loc_8277F464;
loc_8277F424:
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r7,r10,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// twllei r7,0
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r11,r6,r7
	r11.s32 = ctx.r6.s32 / ctx.r7.s32;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// andc r4,r7,r5
	ctx.r4.u64 = ctx.r7.u64 & ~ctx.r5.u64;
	// twlgei r4,-1
	// ble cr6,0x8277f460
	if (!cr6.gt) goto loc_8277F460;
	// slw r10,r14,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (r14.u32 << (ctx.r9.u8 & 0x3F));
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f460
	if (cr6.lt) goto loc_8277F460;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
loc_8277F460:
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8277F464:
	// sth r11,164(r1)
	PPC_STORE_U16(ctx.r1.u32 + 164, r11.u16);
loc_8277F468:
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// lwz r3,468(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277F488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 36);
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// mr r30,r23
	r30.u64 = r23.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r22,r24
	r22.u64 = r24.u64;
	// addi r19,r19,128
	r19.s64 = r19.s64 + 128;
	// addi r18,r18,128
	r18.s64 = r18.s64 + 128;
	// addi r17,r17,128
	r17.s64 = r17.s64 + 128;
	// cmplw cr6,r21,r31
	cr6.compare<uint32_t>(r21.u32, r31.u32, xer);
	// add r20,r20,r11
	r20.u64 = r20.u64 + r11.u64;
	// ble cr6,0x8277f080
	if (!cr6.gt) goto loc_8277F080;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// blt cr6,0x8277efe0
	if (cr6.lt) goto loc_8277EFE0;
loc_8277F4EC:
	// lwz r10,468(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// addi r16,r16,84
	r16.s64 = r16.s64 + 84;
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r5,r8,24
	ctx.r5.s64 = ctx.r8.s64 + 24;
	// lwz r4,36(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// addi r3,r7,4
	ctx.r3.s64 = ctx.r7.s64 + 4;
	// addi r10,r6,4
	ctx.r10.s64 = ctx.r6.s64 + 4;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// blt cr6,0x8277ee7c
	if (cr6.lt) goto loc_8277EE7C;
loc_8277F530:
	// lwz r10,468(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// lwz r11,136(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r9,284(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 284);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// subfc r8,r9,r11
	xer.ca = r11.u32 >= ctx.r9.u32;
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// stw r11,136(r10)
	PPC_STORE_U32(ctx.r10.u32 + 136, r11.u32);
	// subfe r11,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_8277EDA0) {
	__imp__sub_8277EDA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277F558) {
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
	// lwz r30,392(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f5cc
	if (cr6.eq) goto loc_8277F5CC;
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f5b4
	if (cr6.eq) goto loc_8277F5B4;
	// bl 0x8277ec00
	ctx.lr = 0x8277F590;
	sub_8277EC00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f5b4
	if (cr6.eq) goto loc_8277F5B4;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-4704
	ctx.r9.s64 = r11.s64 + -4704;
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// b 0x8277f5d4
	goto loc_8277F5D4;
loc_8277F5B4:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-5560
	ctx.r9.s64 = r11.s64 + -5560;
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// b 0x8277f5d4
	goto loc_8277F5D4;
loc_8277F5CC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_8277F5D4:
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

PPC_WEAK_FUNC(sub_8277F558) {
	__imp__sub_8277F558(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277F5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277F5EC) {
	__imp__sub_8277F5EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277F5F0) {
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
	ctx.lr = 0x8277F5F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,116
	ctx.r5.s64 = 116;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277F61C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r29,392(r30)
	PPC_STORE_U32(r30.u32 + 392, r29.u32);
	// li r26,0
	r26.s64 = 0;
	// addi r7,r9,-6856
	ctx.r7.s64 = ctx.r9.s64 + -6856;
	// addi r6,r8,-2728
	ctx.r6.s64 = ctx.r8.s64 + -2728;
	// stw r26,112(r29)
	PPC_STORE_U32(r29.u32 + 112, r26.u32);
	// clrlwi r5,r31,24
	ctx.r5.u64 = r31.u32 & 0xFF;
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// stw r6,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r6.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8277f708
	if (cr6.eq) goto loc_8277F708;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277f6e0
	if (!cr6.gt) goto loc_8277F6E0;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
	// addi r27,r29,72
	r27.s64 = r29.s64 + 72;
loc_8277F668:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,200(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 200);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277f684
	if (cr6.eq) goto loc_8277F684;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r28,r28,r11
	r28.u64 = r28.u64 + r11.u64;
loc_8277F684:
	// lwz r25,4(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8277a348
	ctx.lr = 0x8277F690;
	sub_8277A348(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r4,-4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8277a348
	ctx.lr = 0x8277F6A0;
	sub_8277A348(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,20(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277F6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277f668
	if (cr6.lt) goto loc_8277F668;
loc_8277F6E0:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,-6184
	ctx.r9.s64 = r11.s64 + -6184;
	// addi r8,r10,-5560
	ctx.r8.s64 = ctx.r10.s64 + -5560;
	// addi r7,r29,72
	ctx.r7.s64 = r29.s64 + 72;
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
	// stw r7,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8277F708:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1280
	ctx.r5.s64 = 1280;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277F724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r3,128
	ctx.r7.s64 = ctx.r3.s64 + 128;
	// addi r6,r3,256
	ctx.r6.s64 = ctx.r3.s64 + 256;
	// stw r3,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r3.u32);
	// addi r5,r3,384
	ctx.r5.s64 = ctx.r3.s64 + 384;
	// stw r7,36(r29)
	PPC_STORE_U32(r29.u32 + 36, ctx.r7.u32);
	// addi r4,r3,512
	ctx.r4.s64 = ctx.r3.s64 + 512;
	// stw r6,40(r29)
	PPC_STORE_U32(r29.u32 + 40, ctx.r6.u32);
	// lis r9,-32230
	ctx.r9.s64 = -2112225280;
	// stw r5,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r5.u32);
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r4,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r4.u32);
	// addi r11,r3,640
	r11.s64 = ctx.r3.s64 + 640;
	// addi r10,r3,768
	ctx.r10.s64 = ctx.r3.s64 + 768;
	// addi r7,r3,896
	ctx.r7.s64 = ctx.r3.s64 + 896;
	// stw r11,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r11.u32);
	// addi r6,r3,1024
	ctx.r6.s64 = ctx.r3.s64 + 1024;
	// stw r10,56(r29)
	PPC_STORE_U32(r29.u32 + 56, ctx.r10.u32);
	// addi r5,r3,1152
	ctx.r5.s64 = ctx.r3.s64 + 1152;
	// stw r7,60(r29)
	PPC_STORE_U32(r29.u32 + 60, ctx.r7.u32);
	// addi r4,r9,23744
	ctx.r4.s64 = ctx.r9.s64 + 23744;
	// stw r6,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r6.u32);
	// addi r3,r8,-6840
	ctx.r3.s64 = ctx.r8.s64 + -6840;
	// stw r5,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r5.u32);
	// stw r4,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r4.u32);
	// stw r3,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r3.u32);
	// stw r26,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r26.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8277F5F0) {
	__imp__sub_8277F5F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277F794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277F794) {
	__imp__sub_8277F794(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277F798) {
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
	ctx.lr = 0x8277F7A0;
	// stwu r1,-1472(r1)
	ea = -1472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r28,50
	r28.s64 = 50;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277f7c8
	if (cr6.lt) goto loc_8277F7C8;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x8277f7ec
	if (cr6.lt) goto loc_8277F7EC;
loc_8277F7C8:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277F7EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F7EC:
	// clrlwi r22,r30,24
	r22.u64 = r30.u32 & 0xFF;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x8277f800
	if (!cr6.eq) goto loc_8277F800;
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
loc_8277F800:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r10,r25
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8277f834
	if (!cr6.eq) goto loc_8277F834;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277F834;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F834:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277f860
	if (!cr6.eq) goto loc_8277F860;
	// lwz r11,4(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// li r5,1424
	ctx.r5.s64 = 1424;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277F85C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_8277F860:
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r26,1
	r26.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r26
	r30.u64 = r26.u64;
	// li r23,8
	r23.s64 = 8;
	// stw r27,140(r28)
	PPC_STORE_U32(r28.u32 + 140, r27.u32);
loc_8277F878:
	// lbzx r31,r30,r27
	r31.u64 = PPC_LOAD_U8(r30.u32 + r27.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277f890
	if (cr6.lt) goto loc_8277F890;
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// ble cr6,0x8277f8ac
	if (!cr6.gt) goto loc_8277F8AC;
loc_8277F890:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277F8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F8AC:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8277f8dc
	if (cr6.eq) goto loc_8277F8DC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// extsb r10,r30
	ctx.r10.s64 = r30.s8;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277f8d8
	if (cr6.eq) goto loc_8277F8D8;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_8277F8CC:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8277f8cc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277F8CC;
loc_8277F8D8:
	// add r29,r31,r29
	r29.u64 = r31.u64 + r29.u64;
loc_8277F8DC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// ble cr6,0x8277f878
	if (!cr6.gt) goto loc_8277F878;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r24,r29
	r24.u64 = r29.u64;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// stbx r10,r29,r11
	PPC_STORE_U8(r29.u32 + r11.u32, ctx.r10.u8);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r29,r9
	r29.s64 = ctx.r9.s8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8277f998
	if (cr6.eq) goto loc_8277F998;
loc_8277F910:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// bne cr6,0x8277f958
	if (!cr6.eq) goto loc_8277F958;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_8277F934:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// beq cr6,0x8277f934
	if (cr6.eq) goto loc_8277F934;
loc_8277F958:
	// slw r11,r26,r29
	r11.u64 = r29.u8 & 0x20 ? 0 : (r26.u32 << (r29.u8 & 0x3F));
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277f980
	if (cr6.lt) goto loc_8277F980;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277F980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277F980:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r30,r30,1,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lbzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277f910
	if (!cr6.eq) goto loc_8277F910;
loc_8277F998:
	// li r11,0
	r11.s64 = 0;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// addi r10,r28,4
	ctx.r10.s64 = r28.s64 + 4;
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8277F9A8:
	// lbzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r27.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8277f9e8
	if (cr6.eq) goto loc_8277F9E8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// lwzx r4,r8,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// subf r3,r4,r11
	ctx.r3.s64 = r11.s64 - ctx.r4.s64;
	// stw r3,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, ctx.r3.u32);
	// lbzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r27.u32);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// b 0x8277f9ec
	goto loc_8277F9EC;
loc_8277F9E8:
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_8277F9EC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// ble cr6,0x8277f9a8
	if (!cr6.gt) goto loc_8277F9A8;
	// lis r11,15
	r11.s64 = 983040;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r28,144
	ctx.r3.s64 = r28.s64 + 144;
	// stw r10,68(r28)
	PPC_STORE_U32(r28.u32 + 68, ctx.r10.u32);
	// bl 0x823d9890
	ctx.lr = 0x8277FA18;
	sub_823D9890(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r30,7
	r30.s64 = 7;
loc_8277FA24:
	// lbzx r11,r5,r27
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + r27.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8277faac
	if (cr6.lt) goto loc_8277FAAC;
	// add r11,r4,r27
	r11.u64 = ctx.r4.u64 + r27.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// slw r31,r26,r30
	r31.u64 = r30.u8 & 0x20 ? 0 : (r26.u32 << (r30.u8 & 0x3F));
	// addi r8,r11,17
	ctx.r8.s64 = r11.s64 + 17;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_8277FA4C:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// slw r11,r11,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r11.u32 << (r30.u8 & 0x3F));
	// ble cr6,0x8277fa90
	if (!cr6.gt) goto loc_8277FA90;
	// addi r10,r11,36
	ctx.r10.s64 = r11.s64 + 36;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1168
	ctx.r10.s64 = r11.s64 + 1168;
	// add r11,r7,r28
	r11.u64 = ctx.r7.u64 + r28.u64;
loc_8277FA74:
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bgt 0x8277fa74
	if (cr0.gt) goto loc_8277FA74;
loc_8277FA90:
	// lbzx r11,r5,r27
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + r27.u32);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// ble cr6,0x8277fa4c
	if (!cr6.gt) goto loc_8277FA4C;
loc_8277FAAC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// bge 0x8277fa24
	if (!cr0.lt) goto loc_8277FA24;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8277fb0c
	if (cr6.eq) goto loc_8277FB0C;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8277fb0c
	if (!cr6.gt) goto loc_8277FB0C;
	// addi r30,r27,17
	r30.s64 = r27.s64 + 17;
loc_8277FAD0:
	// lbzx r11,r30,r31
	r11.u64 = PPC_LOAD_U8(r30.u32 + r31.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277fae4
	if (cr6.lt) goto loc_8277FAE4;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// ble cr6,0x8277fb00
	if (!cr6.gt) goto loc_8277FB00;
loc_8277FAE4:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277FB00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277FB00:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r24
	cr6.compare<int32_t>(r31.s32, r24.s32, xer);
	// blt cr6,0x8277fad0
	if (cr6.lt) goto loc_8277FAD0;
loc_8277FB0C:
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_8277F798) {
	__imp__sub_8277F798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277FB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277FB14) {
	__imp__sub_8277FB14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277FB18) {
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
	ctx.lr = 0x8277FB20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r29,16(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r30,4(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r11,380(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277fc18
	if (!cr6.eq) goto loc_8277FC18;
	// cmpwi cr6,r28,25
	cr6.compare<int32_t>(r28.s32, 25, xer);
	// bge cr6,0x8277fc6c
	if (!cr6.lt) goto loc_8277FC6C;
loc_8277FB54:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277fb88
	if (!cr6.eq) goto loc_8277FB88;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277FB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277fc08
	if (cr6.eq) goto loc_8277FC08;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8277FB88:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// bne cr6,0x8277fbf0
	if (!cr6.eq) goto loc_8277FBF0;
loc_8277FB9C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277fbd0
	if (!cr6.eq) goto loc_8277FBD0;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277FBB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277fc08
	if (cr6.eq) goto loc_8277FC08;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8277FBD0:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x8277fb9c
	if (cr6.eq) goto loc_8277FB9C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8277fc14
	if (!cr6.eq) goto loc_8277FC14;
	// li r11,255
	r11.s64 = 255;
loc_8277FBF0:
	// rlwinm r10,r26,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 8) & 0xFFFFFF00;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// or r26,r10,r11
	r26.u64 = ctx.r10.u64 | r11.u64;
	// cmpwi cr6,r28,25
	cr6.compare<int32_t>(r28.s32, 25, xer);
	// blt cr6,0x8277fb54
	if (cr6.lt) goto loc_8277FB54;
	// b 0x8277fc6c
	goto loc_8277FC6C;
loc_8277FC08:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8277FC14:
	// stw r11,380(r29)
	PPC_STORE_U32(r29.u32 + 380, r11.u32);
loc_8277FC18:
	// cmpw cr6,r25,r28
	cr6.compare<int32_t>(r25.s32, r28.s32, xer);
	// ble cr6,0x8277fc6c
	if (!cr6.gt) goto loc_8277FC6C;
	// lwz r11,408(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 408);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277fc60
	if (!cr6.eq) goto loc_8277FC60;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,117
	ctx.r10.s64 = 117;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277FC54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,408(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 408);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,8(r6)
	PPC_STORE_U8(ctx.r6.u32 + 8, ctx.r7.u8);
loc_8277FC60:
	// subfic r11,r28,25
	xer.ca = r28.u32 <= 25;
	r11.s64 = 25 - r28.s64;
	// li r28,25
	r28.s64 = 25;
	// slw r26,r26,r11
	r26.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
loc_8277FC6C:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// stw r26,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r26.u32);
	// stw r28,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8277FB18) {
	__imp__sub_8277FB18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277FC88) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8277FC90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x8277fcd0
	if (!cr6.lt) goto loc_8277FCD0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x8277fb18
	ctx.lr = 0x8277FCB0;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277fcc8
	if (!cr6.eq) goto loc_8277FCC8;
loc_8277FCBC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277FCC8:
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
loc_8277FCD0:
	// li r11,1
	r11.s64 = 1;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r11,r11,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r11.u32 << (r31.u8 & 0x3F));
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// lwzx r9,r10,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// sraw r7,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r7.s64 = ctx.r4.s32 >> temp.u32;
	// and r11,r7,r8
	r11.u64 = ctx.r7.u64 & ctx.r8.u64;
	// add r30,r10,r27
	r30.u64 = ctx.r10.u64 + r27.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x8277fd4c
	if (!cr6.gt) goto loc_8277FD4C;
loc_8277FCFC:
	// rlwinm r28,r11,1,0,30
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bge cr6,0x8277fd28
	if (!cr6.lt) goto loc_8277FD28;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277fb18
	ctx.lr = 0x8277FD14;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fcbc
	if (cr6.eq) goto loc_8277FCBC;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
loc_8277FD28:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// sraw r11,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	r11.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// or r11,r10,r28
	r11.u64 = ctx.r10.u64 | r28.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x8277fcfc
	if (cr6.gt) goto loc_8277FCFC;
loc_8277FD4C:
	// stw r4,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r4.u32);
	// cmpwi cr6,r31,16
	cr6.compare<int32_t>(r31.s32, 16, xer);
	// stw r5,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r5.u32);
	// ble cr6,0x8277fd90
	if (!cr6.gt) goto loc_8277FD90;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r10,118
	ctx.r10.s64 = 118;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277FD84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277FD90:
	// addi r10,r31,18
	ctx.r10.s64 = r31.s64 + 18;
	// lwz r9,140(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 140);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r27
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r27.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbz r3,17(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 17);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8277FC88) {
	__imp__sub_8277FC88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277FDB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8277FDB4) {
	__imp__sub_8277FDB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8277FDB8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8277FDC0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// li r25,1
	r25.s64 = 1;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r10,252(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 252);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r24,408(r26)
	r24.u64 = PPC_LOAD_U32(r26.u32 + 408);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// beq cr6,0x8277feac
	if (cr6.eq) goto loc_8277FEAC;
	// lwz r11,36(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277feac
	if (!cr6.eq) goto loc_8277FEAC;
	// lwz r10,16(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lwz r11,404(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 404);
	// srawi r9,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// stw r31,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r31.u32);
	// lwz r7,404(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 404);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277FE38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8277fe4c
	if (!cr6.eq) goto loc_8277FE4C;
	// mr r11,r31
	r11.u64 = r31.u64;
	// b 0x8277fe94
	goto loc_8277FE94;
loc_8277FE4C:
	// lwz r11,292(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277fe78
	if (!cr6.gt) goto loc_8277FE78;
	// addi r11,r24,20
	r11.s64 = r24.s64 + 20;
loc_8277FE60:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r9,292(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 292);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277fe60
	if (cr6.lt) goto loc_8277FE60;
loc_8277FE78:
	// lwz r11,252(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 252);
	// stw r11,36(r24)
	PPC_STORE_U32(r24.u32 + 36, r11.u32);
	// lwz r10,380(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 380);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8277fe90
	if (!cr6.eq) goto loc_8277FE90;
	// stb r31,8(r24)
	PPC_STORE_U8(r24.u32 + 8, r31.u8);
loc_8277FE90:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8277FE94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277feac
	if (!cr6.eq) goto loc_8277FEAC;
loc_8277FEA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
loc_8277FEAC:
	// lbz r11,8(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827802cc
	if (!cr6.eq) goto loc_827802CC;
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,20(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r22,r24,20
	r22.s64 = r24.s64 + 20;
	// lwz r8,24(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// mr r19,r31
	r19.u64 = r31.u64;
	// lwz r7,28(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// lwz r6,32(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,320(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 320);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// ble cr6,0x82780288
	if (!cr6.gt) goto loc_82780288;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// mr r20,r30
	r20.u64 = r30.u64;
	// addi r21,r26,324
	r21.s64 = r26.s64 + 324;
	// addi r23,r24,112
	r23.s64 = r24.s64 + 112;
	// addi r18,r11,-31424
	r18.s64 = r11.s64 + -31424;
	// addi r27,r10,-31088
	r27.s64 = ctx.r10.s64 + -31088;
loc_8277FF2C:
	// lwz r29,0(r20)
	r29.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// lwz r31,-40(r23)
	r31.u64 = PPC_LOAD_U32(r23.u32 + -40);
	// lwz r28,0(r23)
	r28.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bge cr6,0x8277ff70
	if (!cr6.lt) goto loc_8277FF70;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x8277FF4C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x8277ff70
	if (!cr6.lt) goto loc_8277FF70;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// b 0x8277ffa4
	goto loc_8277FFA4;
loc_8277FF70:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8277ffa0
	if (cr6.eq) goto loc_8277FFA0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r31,1168(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x8277ffc4
	goto loc_8277FFC4;
loc_8277FFA0:
	// li r7,9
	ctx.r7.s64 = 9;
loc_8277FFA4:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x8277FFB0;
	sub_8277FC88(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277fea0
	if (cr6.lt) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_8277FFC4:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82780024
	if (cr6.eq) goto loc_82780024;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x8277fff4
	if (!cr6.lt) goto loc_8277FFF4;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x8277FFE0;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_8277FFF4:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// slw r10,r25,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r25.u32 << (r31.u8 & 0x3F));
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r11,r27
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// and r31,r10,r9
	r31.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// bge cr6,0x82780024
	if (!cr6.lt) goto loc_82780024;
	// addi r10,r27,64
	ctx.r10.s64 = r27.s64 + 64;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82780024:
	// add r11,r19,r24
	r11.u64 = r19.u64 + r24.u64;
	// lbz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 152);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780050
	if (cr6.eq) goto loc_82780050;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
loc_82780050:
	// add r11,r19,r24
	r11.u64 = r19.u64 + r24.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lbz r10,162(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 162);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780188
	if (cr6.eq) goto loc_82780188;
loc_82780064:
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x8278009c
	if (!cr6.lt) goto loc_8278009C;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780078;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x8278009c
	if (!cr6.lt) goto loc_8278009C;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// b 0x827800d0
	goto loc_827800D0;
loc_8278009C:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827800cc
	if (cr6.eq) goto loc_827800CC;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x827800ec
	goto loc_827800EC;
loc_827800CC:
	// li r7,9
	ctx.r7.s64 = 9;
loc_827800D0:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x827800DC;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8277fea0
	if (cr6.lt) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_827800EC:
	// clrlwi r31,r3,28
	r31.u64 = ctx.r3.u32 & 0xF;
	// srawi r11,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r11.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8278016c
	if (cr6.eq) goto loc_8278016C;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x82780128
	if (!cr6.lt) goto loc_82780128;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780114;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780128:
	// slw r11,r25,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r25.u32 << (r31.u8 & 0x3F));
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// and r11,r11,r9
	r11.u64 = r11.u64 & ctx.r9.u64;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x82780158
	if (!cr6.lt) goto loc_82780158;
	// addi r9,r27,64
	ctx.r9.s64 = r27.s64 + 64;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_82780158:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r18
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r18.u32);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r7,r29
	PPC_STORE_U16(ctx.r7.u32 + r29.u32, r11.u16);
	// b 0x82780178
	goto loc_82780178;
loc_8278016C:
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x8278026c
	if (!cr6.eq) goto loc_8278026C;
	// addi r30,r30,15
	r30.s64 = r30.s64 + 15;
loc_82780178:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// blt cr6,0x82780064
	if (cr6.lt) goto loc_82780064;
	// b 0x8278026c
	goto loc_8278026C;
loc_82780188:
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x827801c0
	if (!cr6.lt) goto loc_827801C0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x8278019C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x827801c0
	if (!cr6.lt) goto loc_827801C0;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// b 0x827801f4
	goto loc_827801F4;
loc_827801C0:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827801f0
	if (cr6.eq) goto loc_827801F0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780210
	goto loc_82780210;
loc_827801F0:
	// li r7,9
	ctx.r7.s64 = 9;
loc_827801F4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x82780200;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8277fea0
	if (cr6.lt) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780210:
	// clrlwi r31,r3,28
	r31.u64 = ctx.r3.u32 & 0xF;
	// srawi r11,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r11.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82780254
	if (cr6.eq) goto loc_82780254;
	// add r30,r30,r11
	r30.u64 = r30.u64 + r11.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x8278024c
	if (!cr6.lt) goto loc_8278024C;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780238;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277fea0
	if (cr6.eq) goto loc_8277FEA0;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_8278024C:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// b 0x82780260
	goto loc_82780260;
loc_82780254:
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x8278026c
	if (!cr6.eq) goto loc_8278026C;
	// addi r30,r30,15
	r30.s64 = r30.s64 + 15;
loc_82780260:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// blt cr6,0x82780188
	if (cr6.lt) goto loc_82780188;
loc_8278026C:
	// lwz r11,320(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 320);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// cmpw cr6,r19,r11
	cr6.compare<int32_t>(r19.s32, r11.s32, xer);
	// blt cr6,0x8277ff2c
	if (cr6.lt) goto loc_8277FF2C;
loc_82780288:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r4,12(r24)
	PPC_STORE_U32(r24.u32 + 12, ctx.r4.u32);
	// stw r5,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r5.u32);
	// stw r7,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r7.u32);
	// stw r6,4(r22)
	PPC_STORE_U32(r22.u32 + 4, ctx.r6.u32);
	// stw r3,8(r22)
	PPC_STORE_U32(r22.u32 + 8, ctx.r3.u32);
	// stw r11,12(r22)
	PPC_STORE_U32(r22.u32 + 12, r11.u32);
loc_827802CC:
	// lwz r11,36(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,36(r24)
	PPC_STORE_U32(r24.u32 + 36, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_8277FDB8) {
	__imp__sub_8277FDB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827802E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827802E4) {
	__imp__sub_827802E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827802E8) {
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
	ctx.lr = 0x827802F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,364(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r30,408(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8278032c
	if (!cr6.eq) goto loc_8278032C;
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmpwi cr6,r11,63
	cr6.compare<int32_t>(r11.s32, 63, xer);
	// bne cr6,0x8278032c
	if (!cr6.eq) goto loc_8278032C;
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8278032c
	if (!cr6.eq) goto loc_8278032C;
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82780350
	if (cr6.eq) goto loc_82780350;
loc_8278032C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,122
	ctx.r10.s64 = 122;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82780350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82780350:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// li r25,0
	r25.s64 = 0;
	// mr r26,r25
	r26.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827803c8
	if (!cr6.gt) goto loc_827803C8;
	// addi r28,r30,20
	r28.s64 = r30.s64 + 20;
	// addi r29,r31,296
	r29.s64 = r31.s64 + 296;
loc_8278036C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r27,24(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r10,r5,10
	ctx.r10.s64 = ctx.r5.s64 + 10;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// bl 0x8277f798
	ctx.lr = 0x82780390;
	sub_8277F798(ctx, base);
	// addi r9,r27,14
	ctx.r9.s64 = r27.s64 + 14;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277f798
	ctx.lr = 0x827803AC;
	sub_8277F798(ctx, base);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r8,292(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x8278036c
	if (cr6.lt) goto loc_8278036C;
loc_827803C8:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82780470
	if (!cr6.gt) goto loc_82780470;
	// addi r8,r30,152
	ctx.r8.s64 = r30.s64 + 152;
	// addi r10,r30,112
	ctx.r10.s64 = r30.s64 + 112;
	// addi r7,r31,324
	ctx.r7.s64 = r31.s64 + 324;
	// subfic r6,r30,-152
	xer.ca = r30.u32 <= 4294967144;
	ctx.r6.s64 = -152 - r30.s64;
	// li r5,1
	ctx.r5.s64 = 1;
loc_827803E8:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,74
	r11.s64 = r11.s64 + 74;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r9,10
	ctx.r4.s64 = ctx.r9.s64 + 10;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r3,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + r30.u32);
	// stw r9,-40(r10)
	PPC_STORE_U32(ctx.r10.u32 + -40, ctx.r9.u32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r4,r9,14
	ctx.r4.s64 = ctx.r9.s64 + 14;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r3,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + r30.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lbz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8278044c
	if (cr6.eq) goto loc_8278044C;
	// stb r5,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r5.u8);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// bgt cr6,0x82780444
	if (cr6.gt) goto loc_82780444;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_82780444:
	// stb r11,10(r8)
	PPC_STORE_U8(ctx.r8.u32 + 10, r11.u8);
	// b 0x82780454
	goto loc_82780454;
loc_8278044C:
	// stb r25,10(r8)
	PPC_STORE_U8(ctx.r8.u32 + 10, r25.u8);
	// stb r25,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r25.u8);
loc_82780454:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// add r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x827803e8
	if (cr6.lt) goto loc_827803E8;
loc_82780470:
	// stw r25,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r25.u32);
	// stb r25,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r25.u8);
	// stw r25,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r25.u32);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_827802E8) {
	__imp__sub_827802E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8278048C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8278048C) {
	__imp__sub_8278048C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82780490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,172
	ctx.r5.s64 = 172;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827804BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r3,408(r31)
	PPC_STORE_U32(r31.u32 + 408, ctx.r3.u32);
	// addi r7,r9,744
	ctx.r7.s64 = ctx.r9.s64 + 744;
	// addi r6,r8,-584
	ctx.r6.s64 = ctx.r8.s64 + -584;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r11,r3,40
	r11.s64 = ctx.r3.s64 + 40;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_827804E4:
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827804e4
	if (!cr0.eq) goto loc_827804E4;
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

PPC_WEAK_FUNC(sub_82780490) {
	__imp__sub_82780490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8278050C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8278050C) {
	__imp__sub_8278050C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82780510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82780518;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,408(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// srawi r8,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 3;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// stw r29,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r29.u32);
	// lwz r6,404(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82780558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82780570
	if (!cr6.eq) goto loc_82780570;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82780570:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278059c
	if (!cr6.gt) goto loc_8278059C;
	// addi r11,r30,24
	r11.s64 = r30.s64 + 24;
loc_82780584:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// lwz r9,292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82780584
	if (cr6.lt) goto loc_82780584;
loc_8278059C:
	// stw r29,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r29.u32);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// lwz r10,380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827805b8
	if (!cr6.eq) goto loc_827805B8;
	// stb r29,8(r30)
	PPC_STORE_U8(r30.u32 + 8, r29.u8);
loc_827805B8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82780510) {
	__imp__sub_82780510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827805C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827805C4) {
	__imp__sub_827805C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827805C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x827805D0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,252(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 252);
	// lwz r24,408(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r21,376(r30)
	r21.u64 = PPC_LOAD_U32(r30.u32 + 376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780618
	if (cr6.eq) goto loc_82780618;
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780618
	if (!cr6.eq) goto loc_82780618;
	// bl 0x82780510
	ctx.lr = 0x82780600;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780618
	if (!cr6.eq) goto loc_82780618;
loc_8278060C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
loc_82780618:
	// lbz r11,8(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780818
	if (!cr6.eq) goto loc_82780818;
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r20,r24,20
	r20.s64 = r24.s64 + 20;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r11,r20
	r11.u64 = r20.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82780658:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82780658
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82780658;
	// lwz r11,320(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827807d4
	if (!cr6.gt) goto loc_827807D4;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// mr r29,r31
	r29.u64 = r31.u64;
	// addi r28,r30,324
	r28.s64 = r30.s64 + 324;
	// li r22,1
	r22.s64 = 1;
	// addi r23,r11,-30960
	r23.s64 = r11.s64 + -30960;
loc_82780690:
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// lwz r25,0(r29)
	r25.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r27,74
	r11.s64 = r27.s64 + 74;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r7,r24
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + r24.u32);
	// bge cr6,0x827806ec
	if (!cr6.lt) goto loc_827806EC;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x827806C8;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278060c
	if (cr6.eq) goto loc_8278060C;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x827806ec
	if (!cr6.lt) goto loc_827806EC;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// b 0x82780720
	goto loc_82780720;
loc_827806EC:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8278071c
	if (cr6.eq) goto loc_8278071C;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r31,1168(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780740
	goto loc_82780740;
loc_8278071C:
	// li r7,9
	ctx.r7.s64 = 9;
loc_82780720:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fc88
	ctx.lr = 0x8278072C;
	sub_8277FC88(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8278060c
	if (cr6.lt) goto loc_8278060C;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780740:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827807a0
	if (cr6.eq) goto loc_827807A0;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x82780770
	if (!cr6.lt) goto loc_82780770;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x8278075C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8278060c
	if (cr6.eq) goto loc_8278060C;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780770:
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// slw r10,r22,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r22.u32 << (r31.u8 & 0x3F));
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r11,r23
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r23.u32);
	// and r31,r10,r9
	r31.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// bge cr6,0x827807a0
	if (!cr6.lt) goto loc_827807A0;
	// addi r10,r23,64
	ctx.r10.s64 = r23.s64 + 64;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_827807A0:
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// slw r8,r11,r21
	ctx.r8.u64 = r21.u8 & 0x20 ? 0 : (r11.u32 << (r21.u8 & 0x3F));
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// sth r8,0(r25)
	PPC_STORE_U16(r25.u32 + 0, ctx.r8.u16);
	// lwz r6,320(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// cmpw cr6,r26,r6
	cr6.compare<int32_t>(r26.s32, ctx.r6.s32, xer);
	// blt cr6,0x82780690
	if (cr6.lt) goto loc_82780690;
loc_827807D4:
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r3,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// stw r4,12(r24)
	PPC_STORE_U32(r24.u32 + 12, ctx.r4.u32);
	// stw r5,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r5.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82780804:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82780804
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82780804;
loc_82780818:
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_827805C8) {
	__imp__sub_827805C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82780830) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82780838;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,252(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 252);
	// lwz r24,408(r25)
	r24.u64 = PPC_LOAD_U32(r25.u32 + 408);
	// lwz r21,368(r25)
	r21.u64 = PPC_LOAD_U32(r25.u32 + 368);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r20,376(r25)
	r20.u64 = PPC_LOAD_U32(r25.u32 + 376);
	// beq cr6,0x82780884
	if (cr6.eq) goto loc_82780884;
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780884
	if (!cr6.eq) goto loc_82780884;
	// bl 0x82780510
	ctx.lr = 0x8278086C;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780884
	if (!cr6.eq) goto loc_82780884;
loc_82780878:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9224
	return;
loc_82780884:
	// lbz r11,8(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780a84
	if (!cr6.eq) goto loc_82780A84;
	// lwz r19,20(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x827808a4
	if (cr6.eq) goto loc_827808A4;
	// addi r19,r19,-1
	r19.s64 = r19.s64 + -1;
	// b 0x82780a80
	goto loc_82780A80;
loc_827808A4:
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// lwz r29,364(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 364);
	// lwz r22,0(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpw cr6,r29,r21
	cr6.compare<int32_t>(r29.s32, r21.s32, xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lwz r28,60(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 60);
	// bgt cr6,0x82780a60
	if (cr6.gt) goto loc_82780A60;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// li r26,1
	r26.s64 = 1;
	// addi r23,r10,-31424
	r23.s64 = ctx.r10.s64 + -31424;
	// addi r27,r11,-30960
	r27.s64 = r11.s64 + -30960;
loc_827808EC:
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x82780924
	if (!cr6.lt) goto loc_82780924;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x82780900;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780878
	if (cr6.eq) goto loc_82780878;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r5,8
	cr6.compare<int32_t>(ctx.r5.s32, 8, xer);
	// bge cr6,0x82780924
	if (!cr6.lt) goto loc_82780924;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// b 0x82780958
	goto loc_82780958;
loc_82780924:
	// addi r11,r5,-8
	r11.s64 = ctx.r5.s64 + -8;
	// sraw r10,r4,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780954
	if (cr6.eq) goto loc_82780954;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r5,r10,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780974
	goto loc_82780974;
loc_82780954:
	// li r7,9
	ctx.r7.s64 = 9;
loc_82780958:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fc88
	ctx.lr = 0x82780964;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82780878
	if (cr6.lt) goto loc_82780878;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780974:
	// clrlwi r31,r3,28
	r31.u64 = ctx.r3.u32 & 0xF;
	// srawi r30,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r30.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x827809f8
	if (cr6.eq) goto loc_827809F8;
	// add r30,r30,r29
	r30.u64 = r30.u64 + r29.u64;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// bge cr6,0x827809b0
	if (!cr6.lt) goto loc_827809B0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x8278099C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780878
	if (cr6.eq) goto loc_82780878;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_827809B0:
	// slw r11,r26,r31
	r11.u64 = r31.u8 & 0x20 ? 0 : (r26.u32 << (r31.u8 & 0x3F));
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sraw r9,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r9.s64 = ctx.r4.s32 >> temp.u32;
	// lwzx r8,r10,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// and r11,r11,r9
	r11.u64 = r11.u64 & ctx.r9.u64;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x827809e0
	if (!cr6.lt) goto loc_827809E0;
	// addi r9,r27,64
	ctx.r9.s64 = r27.s64 + 64;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_827809E0:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r9,r11,r20
	ctx.r9.u64 = r20.u8 & 0x20 ? 0 : (r11.u32 << (r20.u8 & 0x3F));
	// lwzx r8,r10,r23
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r23.u32);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r9,r6,r22
	PPC_STORE_U16(ctx.r6.u32 + r22.u32, ctx.r9.u16);
	// b 0x82780a04
	goto loc_82780A04;
loc_827809F8:
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// bne cr6,0x82780a14
	if (!cr6.eq) goto loc_82780A14;
	// addi r30,r29,15
	r30.s64 = r29.s64 + 15;
loc_82780A04:
	// addi r29,r30,1
	r29.s64 = r30.s64 + 1;
	// cmpw cr6,r29,r21
	cr6.compare<int32_t>(r29.s32, r21.s32, xer);
	// ble cr6,0x827808ec
	if (!cr6.gt) goto loc_827808EC;
	// b 0x82780a60
	goto loc_82780A60;
loc_82780A14:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// slw r31,r26,r30
	r31.u64 = r30.u8 & 0x20 ? 0 : (r26.u32 << (r30.u8 & 0x3F));
	// beq cr6,0x82780a5c
	if (cr6.eq) goto loc_82780A5C;
	// cmpw cr6,r5,r30
	cr6.compare<int32_t>(ctx.r5.s32, r30.s32, xer);
	// bge cr6,0x82780a48
	if (!cr6.lt) goto loc_82780A48;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x82780A34;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780878
	if (cr6.eq) goto loc_82780878;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780A48:
	// subf r5,r30,r5
	ctx.r5.s64 = ctx.r5.s64 - r30.s64;
	// addi r11,r31,-1
	r11.s64 = r31.s64 + -1;
	// sraw r10,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	ctx.r10.s64 = ctx.r4.s32 >> temp.u32;
	// and r11,r10,r11
	r11.u64 = ctx.r10.u64 & r11.u64;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82780A5C:
	// addi r19,r31,-1
	r19.s64 = r31.s64 + -1;
loc_82780A60:
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r4,12(r24)
	PPC_STORE_U32(r24.u32 + 12, ctx.r4.u32);
	// stw r5,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r5.u32);
loc_82780A80:
	// stw r19,20(r24)
	PPC_STORE_U32(r24.u32 + 20, r19.u32);
loc_82780A84:
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_82780830) {
	__imp__sub_82780830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82780A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82780A9C) {
	__imp__sub_82780A9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82780AA0) {
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
	ctx.lr = 0x82780AA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// lwz r30,408(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// slw r26,r10,r11
	r26.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82780af8
	if (cr6.eq) goto loc_82780AF8;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780af8
	if (!cr6.eq) goto loc_82780AF8;
	// bl 0x82780510
	ctx.lr = 0x82780AE0;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780af8
	if (!cr6.eq) goto loc_82780AF8;
loc_82780AEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82780AF8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r27,0
	r27.s64 = 0;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// ble cr6,0x82780b88
	if (!cr6.gt) goto loc_82780B88;
loc_82780B28:
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bge cr6,0x82780b54
	if (!cr6.lt) goto loc_82780B54;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8277fb18
	ctx.lr = 0x82780B40;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780aec
	if (cr6.eq) goto loc_82780AEC;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82780B54:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// sraw r11,r4,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r4.s32 < 0) & (((ctx.r4.s32 >> temp.u32) << temp.u32) != ctx.r4.s32);
	r11.s64 = ctx.r4.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780b74
	if (cr6.eq) goto loc_82780B74;
	// lhz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// or r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 | r26.u64;
	// sth r9,0(r28)
	PPC_STORE_U16(r28.u32 + 0, ctx.r9.u16);
loc_82780B74:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82780b28
	if (cr6.lt) goto loc_82780B28;
loc_82780B88:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r4,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r4.u32);
	// stw r5,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r5.u32);
	// stw r7,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82780AA0) {
	__imp__sub_82780AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82780BC0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82780BC8;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r15,1
	r15.s64 = 1;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,376(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 376);
	// lwz r27,368(r19)
	r27.u64 = PPC_LOAD_U32(r19.u32 + 368);
	// lwz r9,252(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 252);
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// lwz r17,408(r19)
	r17.u64 = PPC_LOAD_U32(r19.u32 + 408);
	// slw r20,r15,r11
	r20.u64 = r11.u8 & 0x20 ? 0 : (r15.u32 << (r11.u8 & 0x3F));
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// beq cr6,0x82780c20
	if (cr6.eq) goto loc_82780C20;
	// lwz r11,40(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780c20
	if (!cr6.eq) goto loc_82780C20;
	// bl 0x82780510
	ctx.lr = 0x82780C14;
	sub_82780510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82781010
	if (cr6.eq) goto loc_82781010;
loc_82780C20:
	// lbz r11,8(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82780fc8
	if (!cr6.eq) goto loc_82780FC8;
	// lwz r10,24(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// stw r19,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r19.u32);
	// li r16,0
	r16.s64 = 0;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r21,r11,-31424
	r21.s64 = r11.s64 + -31424;
	// lwz r24,364(r19)
	r24.u64 = PPC_LOAD_U32(r19.u32 + 364);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// lwz r14,20(r17)
	r14.u64 = PPC_LOAD_U32(r17.u32 + 20);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// lwz r25,12(r17)
	r25.u64 = PPC_LOAD_U32(r17.u32 + 12);
	// lwz r30,16(r17)
	r30.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// lwz r23,60(r17)
	r23.u64 = PPC_LOAD_U32(r17.u32 + 60);
	// bne cr6,0x82780ef8
	if (!cr6.eq) goto loc_82780EF8;
	// cmpw cr6,r24,r27
	cr6.compare<int32_t>(r24.s32, r27.s32, xer);
	// bgt cr6,0x82780fa4
	if (cr6.gt) goto loc_82780FA4;
	// addi r22,r1,128
	r22.s64 = ctx.r1.s64 + 128;
	// li r18,118
	r18.s64 = 118;
loc_82780C80:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x82780cc4
	if (!cr6.lt) goto loc_82780CC4;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780C9C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bge cr6,0x82780cc4
	if (!cr6.lt) goto loc_82780CC4;
	// mr r7,r15
	ctx.r7.u64 = r15.u64;
	// b 0x82780cf8
	goto loc_82780CF8;
loc_82780CC4:
	// addi r11,r30,-8
	r11.s64 = r30.s64 + -8;
	// sraw r10,r25,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	ctx.r10.s64 = r25.s32 >> temp.u32;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,36
	ctx.r9.s64 = r11.s64 + 36;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r23
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r23.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780cf4
	if (cr6.eq) goto loc_82780CF4;
	// add r11,r11,r23
	r11.u64 = r11.u64 + r23.u64;
	// subf r30,r10,r30
	r30.s64 = r30.s64 - ctx.r10.s64;
	// lbz r3,1168(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1168);
	// b 0x82780d1c
	goto loc_82780D1C;
loc_82780CF4:
	// li r7,9
	ctx.r7.s64 = 9;
loc_82780CF8:
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fc88
	ctx.lr = 0x82780D0C;
	sub_8277FC88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82780fe0
	if (cr6.lt) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780D1C:
	// clrlwi r27,r3,28
	r27.u64 = ctx.r3.u32 & 0xF;
	// srawi r26,r3,4
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	r26.s64 = ctx.r3.s32 >> 4;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82780da8
	if (cr6.eq) goto loc_82780DA8;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// beq cr6,0x82780d54
	if (cr6.eq) goto loc_82780D54;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r18,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r18.u32);
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82780D54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82780D54:
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bge cr6,0x82780d84
	if (!cr6.lt) goto loc_82780D84;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780D70;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780D84:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// sraw r11,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780da0
	if (cr6.eq) goto loc_82780DA0;
	// mr r27,r20
	r27.u64 = r20.u64;
	// b 0x82780db0
	goto loc_82780DB0;
loc_82780DA0:
	// lwz r27,116(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x82780db0
	goto loc_82780DB0;
loc_82780DA8:
	// cmpwi cr6,r26,15
	cr6.compare<int32_t>(r26.s32, 15, xer);
	// bne cr6,0x82780e9c
	if (!cr6.eq) goto loc_82780E9C;
loc_82780DB0:
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r21
	r29.u64 = r11.u64 + r21.u64;
loc_82780DB8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780e48
	if (cr6.eq) goto loc_82780E48;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bge cr6,0x82780dfc
	if (!cr6.lt) goto loc_82780DFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780DE8;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780DFC:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// sraw r11,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780e50
	if (cr6.eq) goto loc_82780E50;
	// lhzx r11,r31,r28
	r11.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// and r9,r10,r20
	ctx.r9.u64 = ctx.r10.u64 & r20.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82780e50
	if (!cr6.eq) goto loc_82780E50;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82780e38
	if (cr6.lt) goto loc_82780E38;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// sthx r11,r31,r28
	PPC_STORE_U16(r31.u32 + r28.u32, r11.u16);
	// b 0x82780e50
	goto loc_82780E50;
loc_82780E38:
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// sthx r9,r31,r28
	PPC_STORE_U16(r31.u32 + r28.u32, ctx.r9.u16);
	// b 0x82780e50
	goto loc_82780E50;
loc_82780E48:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82780e64
	if (cr0.lt) goto loc_82780E64;
loc_82780E50:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// ble cr6,0x82780db8
	if (!cr6.gt) goto loc_82780DB8;
loc_82780E64:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82780e88
	if (cr6.eq) goto loc_82780E88;
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r16,r16,1
	r16.s64 = r16.s64 + 1;
	// lwzx r9,r11,r21
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r21.u32);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r9.u32);
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// sthx r27,r8,r28
	PPC_STORE_U16(ctx.r8.u32 + r28.u32, r27.u16);
loc_82780E88:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// ble cr6,0x82780c80
	if (!cr6.gt) goto loc_82780C80;
	// b 0x82780fa4
	goto loc_82780FA4;
loc_82780E9C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// slw r14,r15,r26
	r14.u64 = r26.u8 & 0x20 ? 0 : (r15.u32 << (r26.u8 & 0x3F));
	// beq cr6,0x82780eec
	if (cr6.eq) goto loc_82780EEC;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// bge cr6,0x82780ed8
	if (!cr6.lt) goto loc_82780ED8;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780EC4;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780ED8:
	// subf r30,r26,r30
	r30.s64 = r30.s64 - r26.s64;
	// addi r11,r14,-1
	r11.s64 = r14.s64 + -1;
	// sraw r10,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	ctx.r10.s64 = r25.s32 >> temp.u32;
	// and r11,r10,r11
	r11.u64 = ctx.r10.u64 & r11.u64;
	// add r14,r11,r14
	r14.u64 = r11.u64 + r14.u64;
loc_82780EEC:
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x82780fa4
	if (cr6.eq) goto loc_82780FA4;
loc_82780EF8:
	// cmpw cr6,r24,r27
	cr6.compare<int32_t>(r24.s32, r27.s32, xer);
	// bgt cr6,0x82780fa0
	if (cr6.gt) goto loc_82780FA0;
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r26,116(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// add r29,r11,r21
	r29.u64 = r11.u64 + r21.u64;
loc_82780F0C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82780f90
	if (cr6.eq) goto loc_82780F90;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bge cr6,0x82780f50
	if (!cr6.lt) goto loc_82780F50;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8277fb18
	ctx.lr = 0x82780F3C;
	sub_8277FB18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82780fe0
	if (cr6.eq) goto loc_82780FE0;
	// lwz r25,104(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r30,108(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82780F50:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// sraw r11,r25,r30
	temp.u32 = r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r25.s32 < 0) & (((r25.s32 >> temp.u32) << temp.u32) != r25.s32);
	r11.s64 = r25.s32 >> temp.u32;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82780f90
	if (cr6.eq) goto loc_82780F90;
	// lhzx r11,r31,r28
	r11.u64 = PPC_LOAD_U16(r31.u32 + r28.u32);
	// extsh r10,r11
	ctx.r10.s64 = r11.s16;
	// and r9,r10,r20
	ctx.r9.u64 = ctx.r10.u64 & r20.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82780f90
	if (!cr6.eq) goto loc_82780F90;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82780f88
	if (cr6.lt) goto loc_82780F88;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// b 0x82780f8c
	goto loc_82780F8C;
loc_82780F88:
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
loc_82780F8C:
	// sthx r11,r31,r28
	PPC_STORE_U16(r31.u32 + r28.u32, r11.u16);
loc_82780F90:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r24,r27
	cr6.compare<int32_t>(r24.s32, r27.s32, xer);
	// ble cr6,0x82780f0c
	if (!cr6.gt) goto loc_82780F0C;
loc_82780FA0:
	// addi r14,r14,-1
	r14.s64 = r14.s64 + -1;
loc_82780FA4:
	// lwz r11,24(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r25,12(r17)
	PPC_STORE_U32(r17.u32 + 12, r25.u32);
	// stw r30,16(r17)
	PPC_STORE_U32(r17.u32 + 16, r30.u32);
	// stw r14,20(r17)
	PPC_STORE_U32(r17.u32 + 20, r14.u32);
loc_82780FC8:
	// lwz r11,40(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,40(r17)
	PPC_STORE_U32(r17.u32 + 40, r11.u32);
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9210
	return;
loc_82780FE0:
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// ble cr6,0x82781010
	if (!cr6.gt) goto loc_82781010;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// rlwinm r11,r16,2,0,29
	r11.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82780FF8:
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// addic. r16,r16,-1
	xer.ca = r16.u32 > 0;
	r16.s64 = r16.s64 + -1;
	cr0.compare<int32_t>(r16.s32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r8,r28
	PPC_STORE_U16(ctx.r8.u32 + r28.u32, ctx.r10.u16);
	// bgt 0x82780ff8
	if (cr0.gt) goto loc_82780FF8;
loc_82781010:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_82780BC0) {
	__imp__sub_82780BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8278101C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8278101C) {
	__imp__sub_8278101C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781020) {
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
	ctx.lr = 0x82781028;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// lwz r10,364(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r24,408(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// cntlzw r11,r10
	r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r22,r11
	r22.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// beq cr6,0x82781060
	if (cr6.eq) goto loc_82781060;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// b 0x8278107c
	goto loc_8278107C;
loc_82781060:
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x82781070
	if (cr6.gt) goto loc_82781070;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// blt cr6,0x82781074
	if (cr6.lt) goto loc_82781074;
loc_82781070:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82781074:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
loc_8278107C:
	// beq cr6,0x82781084
	if (cr6.eq) goto loc_82781084;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82781084:
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827810a4
	if (cr6.eq) goto loc_827810A4;
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// beq cr6,0x827810a4
	if (cr6.eq) goto loc_827810A4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_827810A4:
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// ble cr6,0x827810b4
	if (!cr6.gt) goto loc_827810B4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_827810B4:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82781110
	if (cr6.eq) goto loc_82781110;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,16
	ctx.r10.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,364(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,368(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,372(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// stw r4,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r4.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,376(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781110:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// mr r25,r23
	r25.u64 = r23.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82781214
	if (!cr6.gt) goto loc_82781214;
	// addi r26,r31,296
	r26.s64 = r31.s64 + 296;
	// li r27,115
	r27.s64 = 115;
loc_82781128:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r28,4(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r10,r28,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 8) & 0xFFFFFF00;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// bne cr6,0x82781180
	if (!cr6.eq) goto loc_82781180;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82781180
	if (!cr6.lt) goto loc_82781180;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r23,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r23.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82781180;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781180:
	// lwz r30,364(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bgt cr6,0x82781200
	if (cr6.gt) goto loc_82781200;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
loc_82781198:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x827811a8
	if (!cr6.lt) goto loc_827811A8;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_827811A8:
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x827811e4
	if (cr6.eq) goto loc_827811E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r30.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827811E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827811E4:
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x82781198
	if (!cr6.gt) goto loc_82781198;
loc_82781200:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82781128
	if (cr6.lt) goto loc_82781128;
loc_82781214:
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82781240
	if (!cr6.eq) goto loc_82781240;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82781234
	if (cr6.eq) goto loc_82781234;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,1480
	ctx.r10.s64 = r11.s64 + 1480;
	// b 0x8278125c
	goto loc_8278125C;
loc_82781234:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,2096
	ctx.r10.s64 = r11.s64 + 2096;
	// b 0x8278125c
	goto loc_8278125C;
loc_82781240:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82781254
	if (cr6.eq) goto loc_82781254;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,2720
	ctx.r10.s64 = r11.s64 + 2720;
	// b 0x8278125c
	goto loc_8278125C;
loc_82781254:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,3008
	ctx.r10.s64 = r11.s64 + 3008;
loc_8278125C:
	// stw r10,4(r24)
	PPC_STORE_U32(r24.u32 + 4, ctx.r10.u32);
	// mr r27,r23
	r27.u64 = r23.u64;
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827812f4
	if (!cr6.gt) goto loc_827812F4;
	// addi r28,r24,24
	r28.s64 = r24.s64 + 24;
	// addi r29,r31,296
	r29.s64 = r31.s64 + 296;
loc_82781278:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x827812b0
	if (cr6.eq) goto loc_827812B0;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827812d8
	if (!cr6.eq) goto loc_827812D8;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r5,11
	r11.s64 = ctx.r5.s64 + 11;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r24
	ctx.r6.u64 = r11.u64 + r24.u64;
	// bl 0x8277f798
	ctx.lr = 0x827812AC;
	sub_8277F798(ctx, base);
	// b 0x827812d8
	goto loc_827812D8;
loc_827812B0:
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r5,11
	r11.s64 = ctx.r5.s64 + 11;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r24
	r30.u64 = r11.u64 + r24.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x8277f798
	ctx.lr = 0x827812D0;
	sub_8277F798(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,60(r24)
	PPC_STORE_U32(r24.u32 + 60, ctx.r10.u32);
loc_827812D8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// stw r23,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r23.u32);
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82781278
	if (cr6.lt) goto loc_82781278;
loc_827812F4:
	// stw r23,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r23.u32);
	// stw r23,12(r24)
	PPC_STORE_U32(r24.u32 + 12, r23.u32);
	// stw r23,20(r24)
	PPC_STORE_U32(r24.u32 + 20, r23.u32);
	// stb r23,8(r24)
	PPC_STORE_U8(r24.u32 + 8, r23.u8);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r11,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82781020) {
	__imp__sub_82781020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82781314) {
	__imp__sub_82781314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781318) {
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
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// li r30,0
	r30.s64 = 0;
	// stw r3,408(r31)
	PPC_STORE_U32(r31.u32 + 408, ctx.r3.u32);
	// addi r8,r9,4128
	ctx.r8.s64 = ctx.r9.s64 + 4128;
	// addi r11,r3,44
	r11.s64 = ctx.r3.s64 + 44;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r30.u32);
	// stw r30,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r30.u32);
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r30.u32);
	// stw r30,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82781390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r9.u32);
	// ble cr6,0x827813d4
	if (!cr6.gt) goto loc_827813D4;
	// li r8,-1
	ctx.r8.s64 = -1;
loc_827813A8:
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// li r10,64
	ctx.r10.s64 = 64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_827813B4:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x827813b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_827813B4;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r9,r9,256
	ctx.r9.s64 = ctx.r9.s64 + 256;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827813a8
	if (cr6.lt) goto loc_827813A8;
loc_827813D4:
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

PPC_WEAK_FUNC(sub_82781318) {
	__imp__sub_82781318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827813EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827813EC) {
	__imp__sub_827813EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827813F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// bl 0x823d91e4
	ctx.lr = 0x827813F8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// lwz r9,36(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// lwz r11,412(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 412);
	// lwz r10,196(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827817e0
	if (!cr6.gt) goto loc_827817E0;
	// addi r26,r11,44
	r26.s64 = r11.s64 + 44;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r30,r10,36
	r30.s64 = ctx.r10.s64 + 36;
	// li r24,48
	r24.s64 = 48;
	// li r23,7
	r23.s64 = 7;
	// addi r31,r11,-30832
	r31.s64 = r11.s64 + -30832;
loc_82781438:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x82781514
	if (cr6.gt) goto loc_82781514;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,5216
	r12.s64 = r12.s64 + 5216;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,5248(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5248);
	// lwz r19,5264(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5264);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5280(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5280);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5396(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5396);
	// lwz r19,5296(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 5296);
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-9560
	r28.s64 = r11.s64 + -9560;
	// b 0x8278153c
	goto loc_8278153C;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-10952
	r28.s64 = r11.s64 + -10952;
	// b 0x8278153c
	goto loc_8278153C;
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-11736
	r28.s64 = r11.s64 + -11736;
	// b 0x8278153c
	goto loc_8278153C;
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82781504
	if (cr6.lt) goto loc_82781504;
	// beq cr6,0x827814f4
	if (cr6.eq) goto loc_827814F4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x827814e4
	if (cr6.lt) goto loc_827814E4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82781538
	goto loc_82781538;
loc_827814E4:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,2
	r29.s64 = 2;
	// addi r28,r11,-12840
	r28.s64 = r11.s64 + -12840;
	// b 0x8278153c
	goto loc_8278153C;
loc_827814F4:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,1
	r29.s64 = 1;
	// addi r28,r11,-13824
	r28.s64 = r11.s64 + -13824;
	// b 0x8278153c
	goto loc_8278153C;
loc_82781504:
	// lis r11,-32135
	r11.s64 = -2105999360;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r11,-14976
	r28.s64 = r11.s64 + -14976;
	// b 0x8278153c
	goto loc_8278153C;
loc_82781514:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82781538:
	// bctrl 
	ctx.lr = 0x8278153C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8278153C:
	// stw r28,-40(r26)
	PPC_STORE_U32(r26.u32 + -40, r28.u32);
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827817c8
	if (cr6.eq) goto loc_827817C8;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x827817c8
	if (cr6.eq) goto loc_827817C8;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827817c8
	if (cr6.eq) goto loc_827817C8;
	// stw r29,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r29.u32);
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// blt cr6,0x827817a8
	if (cr6.lt) goto loc_827817A8;
	// beq cr6,0x827816fc
	if (cr6.eq) goto loc_827816FC;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// blt cr6,0x8278159c
	if (cr6.lt) goto loc_8278159C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82781598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827817c8
	goto loc_827817C8;
loc_8278159C:
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
loc_827815AC:
	// lhz r7,-4(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + -4);
	// lfd f9,0(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lfd f0,136(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 136);
	// addi r8,r31,128
	ctx.r8.s64 = r31.s64 + 128;
	// lfd f13,144(r31)
	ctx.f13.u64 = PPC_LOAD_U64(r31.u32 + 144);
	// lfd f12,152(r31)
	ctx.f12.u64 = PPC_LOAD_U64(r31.u32 + 152);
	// addi r4,r8,64
	ctx.r4.s64 = ctx.r8.s64 + 64;
	// lfd f11,168(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 168);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f10,176(r31)
	ctx.f10.u64 = PPC_LOAD_U64(r31.u32 + 176);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fmul f6,f7,f9
	ctx.f6.f64 = ctx.f7.f64 * ctx.f9.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,-8(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// lfd f4,0(r11)
	ctx.f4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,-2(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f3,88(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// fmul f1,f2,f4
	ctx.f1.f64 = ctx.f2.f64 * ctx.f4.f64;
	// fmul f0,f1,f0
	f0.f64 = ctx.f1.f64 * f0.f64;
	// frsp f9,f0
	ctx.f9.f64 = double(float(f0.f64));
	// stfs f9,-4(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// lfd f8,0(r11)
	ctx.f8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f7,96(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fmul f5,f6,f8
	ctx.f5.f64 = ctx.f6.f64 * ctx.f8.f64;
	// fmul f4,f5,f13
	ctx.f4.f64 = ctx.f5.f64 * ctx.f13.f64;
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfd f2,0(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f1,104(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// fmul f13,f0,f2
	ctx.f13.f64 = f0.f64 * ctx.f2.f64;
	// fmul f12,f13,f12
	ctx.f12.f64 = ctx.f13.f64 * ctx.f12.f64;
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// stfs f9,4(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lfd f8,0(r11)
	ctx.f8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fmul f5,f6,f8
	ctx.f5.f64 = ctx.f6.f64 * ctx.f8.f64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f4,8(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lfd f3,0(r11)
	ctx.f3.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r3,6(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f2,120(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// fmul f0,f1,f3
	f0.f64 = ctx.f1.f64 * ctx.f3.f64;
	// fmul f13,f0,f11
	ctx.f13.f64 = f0.f64 * ctx.f11.f64;
	// lfd f0,184(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 184);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,12(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfd f11,0(r11)
	ctx.f11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// std r7,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r7.u64);
	// lfd f9,128(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fmul f7,f8,f11
	ctx.f7.f64 = ctx.f8.f64 * ctx.f11.f64;
	// fmul f6,f7,f10
	ctx.f6.f64 = ctx.f7.f64 * ctx.f10.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,16(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// lfd f4,0(r11)
	ctx.f4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// lhz r5,10(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10);
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lfd f3,136(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// fmul f1,f2,f4
	ctx.f1.f64 = ctx.f2.f64 * ctx.f4.f64;
	// fmul f0,f1,f0
	f0.f64 = ctx.f1.f64 * f0.f64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// stfs f13,20(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// blt cr6,0x827815ac
	if (cr6.lt) goto loc_827815AC;
	// b 0x827817c8
	goto loc_827817C8;
loc_827816FC:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// addi r5,r31,2
	ctx.r5.s64 = r31.s64 + 2;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// add r6,r7,r31
	ctx.r6.u64 = ctx.r7.u64 + r31.u64;
	// addi r9,r31,2
	ctx.r9.s64 = r31.s64 + 2;
	// addi r11,r8,4
	r11.s64 = ctx.r8.s64 + 4;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
loc_8278171C:
	// lhz r8,-2(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + -2);
	// addi r5,r31,130
	ctx.r5.s64 = r31.s64 + 130;
	// lhz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + -4);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// mullw r8,r3,r4
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// addi r8,r8,2048
	ctx.r8.s64 = ctx.r8.s64 + 2048;
	// srawi r4,r8,12
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 12;
	// stw r4,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r4.u32);
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// lhz r3,-2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// mullw r8,r3,r4
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// addi r3,r8,2048
	ctx.r3.s64 = ctx.r8.s64 + 2048;
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// srawi r8,r3,12
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 12;
	// stw r8,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r8.u32);
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lhzx r4,r6,r11
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + r11.u32);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// mullw r8,r3,r5
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// addi r8,r8,2048
	ctx.r8.s64 = ctx.r8.s64 + 2048;
	// srawi r5,r8,12
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 12;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// lhz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// mullw r8,r8,r4
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r4.s32);
	// addi r5,r8,2048
	ctx.r5.s64 = ctx.r8.s64 + 2048;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// srawi r4,r5,12
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFF) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 12;
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// blt cr6,0x8278171c
	if (cr6.lt) goto loc_8278171C;
	// b 0x827817c8
	goto loc_827817C8;
loc_827817A8:
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// li r11,64
	r11.s64 = 64;
loc_827817B0:
	// lhz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x827817b0
	if (!cr0.eq) goto loc_827817B0;
loc_827817C8:
	// lwz r11,36(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82781438
	if (cr6.lt) goto loc_82781438;
loc_827817E0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_827813F0) {
	__imp__sub_827813F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827817E8) {
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
	ctx.lr = 0x827817F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,84
	ctx.r5.s64 = 84;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// stw r3,412(r31)
	PPC_STORE_U32(r31.u32 + 412, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// addi r8,r9,5104
	ctx.r8.s64 = ctx.r9.s64 + 5104;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// ble cr6,0x82781888
	if (!cr6.gt) goto loc_82781888;
	// addi r29,r11,80
	r29.s64 = r11.s64 + 80;
	// addi r30,r3,44
	r30.s64 = ctx.r3.s64 + 44;
	// li r27,-1
	r27.s64 = -1;
loc_82781840:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278185C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// bl 0x823d9890
	ctx.lr = 0x8278186C;
	sub_823D9890(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// blt cr6,0x82781840
	if (cr6.lt) goto loc_82781840;
loc_82781888:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_827817E8) {
	__imp__sub_827817E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781890) {
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
	ctx.lr = 0x82781898;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r29,396(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// ble cr6,0x827818c4
	if (!cr6.gt) goto loc_827818C4;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_827818C4:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827818E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,424(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82781890) {
	__imp__sub_82781890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781928) {
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
	ctx.lr = 0x82781930;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// lwz r31,396(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 396);
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781980
	if (!cr6.eq) goto loc_82781980;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8278197C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
loc_82781980:
	// lwz r11,416(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 416);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827819B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// ble cr6,0x827819f4
	if (!cr6.gt) goto loc_827819F4;
	// lwz r9,424(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 424);
	// subf r27,r29,r11
	r27.s64 = r11.s64 - r29.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827819E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r7,r11,r27
	ctx.r7.u64 = r11.u64 + r27.u64;
	// stw r7,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r7.u32);
loc_827819F4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82781a18
	if (cr6.lt) goto loc_82781A18;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
loc_82781A18:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82781928) {
	__imp__sub_82781928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781A20) {
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
	ctx.lr = 0x82781A28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// lwz r31,396(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 396);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781a70
	if (!cr6.eq) goto loc_82781A70;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781A6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
loc_82781A70:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf r9,r10,r30
	ctx.r9.s64 = r30.s64 - ctx.r10.s64;
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// ble cr6,0x82781a90
	if (!cr6.gt) goto loc_82781A90;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
loc_82781A90:
	// lwz r9,96(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// ble cr6,0x82781aa8
	if (!cr6.gt) goto loc_82781AA8;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
loc_82781AA8:
	// lwz r8,424(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 424);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r9,r27
	ctx.r5.u64 = ctx.r9.u64 + r27.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82781AD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// stw r6,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r6.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82781b0c
	if (cr6.lt) goto loc_82781B0C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
loc_82781B0C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82781A20) {
	__imp__sub_82781A20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82781B14) {
	__imp__sub_82781B14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781B18) {
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
	// lwz r31,396(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82781bcc
	if (cr6.eq) goto loc_82781BCC;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x82781b98
	if (cr6.eq) goto loc_82781B98;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// beq cr6,0x82781b64
	if (cr6.eq) goto loc_82781B64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781B60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82781c24
	goto loc_82781C24;
loc_82781B64:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781b8c
	if (!cr6.eq) goto loc_82781B8C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781B8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781B8C:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,6440
	ctx.r10.s64 = r11.s64 + 6440;
	// b 0x82781c20
	goto loc_82781C20;
loc_82781B98:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82781bc0
	if (!cr6.eq) goto loc_82781BC0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781BC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82781BC0:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,6688
	ctx.r10.s64 = r11.s64 + 6688;
	// b 0x82781c20
	goto loc_82781C20;
loc_82781BCC:
	// lbz r11,74(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82781c18
	if (cr6.eq) goto loc_82781C18;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,6288
	ctx.r9.s64 = r11.s64 + 6288;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// bne cr6,0x82781c24
	if (!cr6.eq) goto loc_82781C24;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// b 0x82781c24
	goto loc_82781C24;
loc_82781C18:
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_82781C20:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_82781C24:
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
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

PPC_WEAK_FUNC(sub_82781B18) {
	__imp__sub_82781B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82781C44) {
	__imp__sub_82781C44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781C48) {
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
	ctx.lr = 0x82781C50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82781C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// li r11,0
	r11.s64 = 0;
	// stw r30,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r30.u32);
	// addi r8,r9,6936
	ctx.r8.s64 = ctx.r9.s64 + 6936;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// lbz r7,74(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82781d28
	if (cr6.eq) goto loc_82781D28;
	// lwz r29,276(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r29.u32);
	// beq cr6,0x82781cfc
	if (cr6.eq) goto loc_82781CFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8277a348
	ctx.lr = 0x82781CC4;
	sub_8277A348(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mullw r6,r11,r10
	ctx.r6.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82781CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82781CFC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mullw r5,r10,r9
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82781D24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
loc_82781D28:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82781C48) {
	__imp__sub_82781C48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781D30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r10,276(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// stw r10,92(r11)
	PPC_STORE_U32(r11.u32 + 92, ctx.r10.u32);
	// lwz r9,96(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// stw r9,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82781D30) {
	__imp__sub_82781D30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781D48) {
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
	ctx.lr = 0x82781D50;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// lwz r29,416(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 416);
	// lwz r11,276(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// lwz r10,92(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82781dec
	if (cr6.lt) goto loc_82781DEC;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r27,0
	r27.s64 = 0;
	// lwz r26,196(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82781de4
	if (!cr6.gt) goto loc_82781DE4;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r29,12
	r31.s64 = r29.s64 + 12;
loc_82781D98:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82781DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r26,r26,84
	r26.s64 = r26.s64 + 84;
	// cmpw cr6,r27,r6
	cr6.compare<int32_t>(r27.s32, ctx.r6.s32, xer);
	// blt cr6,0x82781d98
	if (cr6.lt) goto loc_82781D98;
loc_82781DE4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,92(r29)
	PPC_STORE_U32(r29.u32 + 92, r11.u32);
loc_82781DEC:
	// lwz r5,92(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// lwz r10,276(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// subf r31,r5,r10
	r31.s64 = ctx.r10.s64 - ctx.r5.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// ble cr6,0x82781e08
	if (!cr6.gt) goto loc_82781E08;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_82781E08:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// subf r10,r11,r23
	ctx.r10.s64 = r23.s64 - r11.s64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// ble cr6,0x82781e1c
	if (!cr6.gt) goto loc_82781E1C;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_82781E1C:
	// lwz r10,420(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 420);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// add r6,r11,r22
	ctx.r6.u64 = r11.u64 + r22.u64;
	// addi r4,r29,12
	ctx.r4.s64 = r29.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82781E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stw r8,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r8.u32);
	// lwz r7,96(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// subf r6,r31,r7
	ctx.r6.s64 = ctx.r7.s64 - r31.s64;
	// lwz r11,92(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// stw r11,92(r29)
	PPC_STORE_U32(r29.u32 + 92, r11.u32);
	// stw r6,96(r29)
	PPC_STORE_U32(r29.u32 + 96, ctx.r6.u32);
	// lwz r5,276(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x82781e7c
	if (cr6.lt) goto loc_82781E7C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
loc_82781E7C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82781D48) {
	__imp__sub_82781D48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82781E84) {
	__imp__sub_82781E84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781E88) {
	PPC_FUNC_PROLOGUE();
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82781E88) {
	__imp__sub_82781E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82781E90) {
	__imp__sub_82781E90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82781E9C) {
	__imp__sub_82781E9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781EA0) {
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
	ctx.lr = 0x82781EA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r25,0(r6)
	r25.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lwz r9,276(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lbz r29,140(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 140);
	// lbz r26,150(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 150);
	// ble cr6,0x82781f70
	if (!cr6.gt) goto loc_82781F70;
	// rlwinm r24,r26,2,0,29
	r24.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
loc_82781EE4:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bge cr6,0x82781f34
	if (!cr6.lt) goto loc_82781F34;
loc_82781EFC:
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82781f2c
	if (!cr6.gt) goto loc_82781F2C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82781f28
	if (cr6.eq) goto loc_82781F28;
	// mtctr r29
	ctr.u64 = r29.u64;
loc_82781F1C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82781f1c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82781F1C;
loc_82781F28:
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
loc_82781F2C:
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x82781efc
	if (cr6.lt) goto loc_82781EFC;
loc_82781F34:
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// ble cr6,0x82781f58
	if (!cr6.gt) goto loc_82781F58;
	// addi r7,r26,-1
	ctx.r7.s64 = r26.s64 + -1;
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r6,r30,1
	ctx.r6.s64 = r30.s64 + 1;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8277a378
	ctx.lr = 0x82781F58;
	sub_8277A378(ctx, base);
loc_82781F58:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// add r30,r30,r26
	r30.u64 = r30.u64 + r26.u64;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// add r27,r24,r27
	r27.u64 = r24.u64 + r27.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82781ee4
	if (cr6.lt) goto loc_82781EE4;
loc_82781F70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82781EA0) {
	__imp__sub_82781EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// subf r7,r8,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r8.s64;
loc_82781F90:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwzx r10,r7,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x82781fc8
	if (!cr6.lt) goto loc_82781FC8;
loc_82781FA8:
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82781fa8
	if (cr6.lt) goto loc_82781FA8;
loc_82781FC8:
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x82781f90
	if (cr6.lt) goto loc_82781F90;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82781F78) {
	__imp__sub_82781F78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82781FE0) {
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
	ctx.lr = 0x82781FE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r27,0(r6)
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82782078
	if (!cr6.gt) goto loc_82782078;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
loc_8278200C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,92(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x82782044
	if (!cr6.lt) goto loc_82782044;
loc_82782024:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82782024
	if (cr6.lt) goto loc_82782024;
loc_82782044:
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r8,92(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// addi r6,r28,1
	ctx.r6.s64 = r28.s64 + 1;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8277a378
	ctx.lr = 0x82782060;
	sub_8277A378(ctx, base);
	// lwz r11,276(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 276);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8278200c
	if (cr6.lt) goto loc_8278200C;
loc_82782078:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82781FE0) {
	__imp__sub_82781FE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782080) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// li r31,0
	r31.s64 = 0;
	// lwz r6,0(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8278216c
	if (!cr6.gt) goto loc_8278216C;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
loc_827820A0:
	// lwzx r10,r5,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r7,r10,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r30.u8);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// lwz r7,40(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// addic. r9,r7,-2
	xer.ca = ctx.r7.u32 > 1;
	ctx.r9.s64 = ctx.r7.s64 + -2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82782130
	if (cr0.eq) goto loc_82782130;
loc_827820E8:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r7,r8,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lbz r7,-2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// srawi r7,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 2;
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne 0x827820e8
	if (!cr0.eq) goto loc_827820E8;
loc_82782130:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r11,-1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// rotlwi r8,r9,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// lwz r7,276(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// blt cr6,0x827820a0
	if (cr6.lt) goto loc_827820A0;
loc_8278216C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82782080) {
	__imp__sub_82782080(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782178) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82782180;
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// li r27,0
	r27.s64 = 0;
	// lwz r24,0(r6)
	r24.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827822e4
	if (!cr6.gt) goto loc_827822E4;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
loc_82782198:
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// li r26,0
	r26.s64 = 0;
	// add r28,r11,r24
	r28.u64 = r11.u64 + r24.u64;
loc_827821A4:
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x827821b8
	if (!cr6.eq) goto loc_827821B8;
	// lwz r10,-4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -4);
	// b 0x827821bc
	goto loc_827821BC;
loc_827821B8:
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_827821BC:
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lbz r11,0(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r31,r9,1
	r31.s64 = ctx.r9.s64 + 1;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lbz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// rotlwi r30,r11,1
	r30.u64 = __builtin_rotateleft32(r11.u32, 1);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + r11.u64;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r6,7
	ctx.r6.s64 = ctx.r6.s64 + 7;
	// srawi r5,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 4;
	// srawi r6,r6,4
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 4;
	// stb r5,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r5.u8);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stb r6,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r6.u8);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// lwz r10,40(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// addic. r9,r10,-2
	xer.ca = ctx.r10.u32 > 1;
	ctx.r9.s64 = ctx.r10.s64 + -2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// beq 0x827822a0
	if (cr0.eq) goto loc_827822A0;
loc_82782244:
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r11,0(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// lbz r30,0(r7)
	r30.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
	// rotlwi r29,r11,1
	r29.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r5,r31,r5
	ctx.r5.u64 = r31.u64 + ctx.r5.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// srawi r30,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	r30.s64 = ctx.r5.s32 >> 4;
	// add r5,r31,r11
	ctx.r5.u64 = r31.u64 + r11.u64;
	// stb r30,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r30.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r5,r5,7
	ctx.r5.s64 = ctx.r5.s64 + 7;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// srawi r31,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	r31.s64 = ctx.r5.s32 >> 4;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// stb r31,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r31.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne 0x82782244
	if (!cr0.eq) goto loc_82782244;
loc_827822A0:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r10,7
	ctx.r10.s64 = ctx.r10.s64 + 7;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// srawi r7,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 4;
	// srawi r6,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 4;
	// stb r7,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r7.u8);
	// stb r6,1(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1, ctx.r6.u8);
	// blt cr6,0x827821a4
	if (cr6.lt) goto loc_827821A4;
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82782198
	if (cr6.lt) goto loc_82782198;
loc_827822E4:
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82782178) {
	__imp__sub_82782178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827822E8) {
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
	ctx.lr = 0x827822F0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,160
	ctx.r5.s64 = 160;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r26,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r26.u32);
	// addi r7,r9,7472
	ctx.r7.s64 = ctx.r9.s64 + 7472;
	// addi r6,r8,7496
	ctx.r6.s64 = ctx.r8.s64 + 7496;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r7.u32);
	// stw r6,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r6.u32);
	// stb r5,8(r26)
	PPC_STORE_U8(r26.u32 + 8, ctx.r5.u8);
	// lbz r4,266(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 266);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82782364
	if (cr6.eq) goto loc_82782364;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,25
	ctx.r10.s64 = 25;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782364:
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// li r25,1
	r25.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782384
	if (cr6.eq) goto loc_82782384;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x82782388
	if (cr6.gt) goto loc_82782388;
loc_82782384:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82782388:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// clrlwi r24,r10,24
	r24.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827825f0
	if (!cr6.gt) goto loc_827825F0;
	// addi r29,r11,36
	r29.s64 = r11.s64 + 36;
	// addi r30,r26,52
	r30.s64 = r26.s64 + 52;
	// li r23,38
	r23.s64 = 38;
loc_827823AC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r28,r25
	r28.u64 = r25.u64;
	// lwz r10,-28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -28);
	// lwz r8,-24(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + -24);
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r6,280(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// lwz r10,272(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r9,276(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// mullw r5,r8,r11
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// rotlwi r11,r7,1
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// rotlwi r8,r5,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// addi r3,r8,-1
	ctx.r3.s64 = ctx.r8.s64 + -1;
	// divw r11,r5,r6
	r11.s32 = ctx.r5.s32 / ctx.r6.s32;
	// andc r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// andc r4,r6,r3
	ctx.r4.u64 = ctx.r6.u64 & ~ctx.r3.u64;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
	// lbz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// twllei r6,0
	// divw r8,r7,r6
	ctx.r8.s32 = ctx.r7.s32 / ctx.r6.s32;
	// twllei r6,0
	// twlgei r5,-1
	// twlgei r4,-1
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82782424
	if (!cr6.eq) goto loc_82782424;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,7824
	ctx.r10.s64 = r11.s64 + 7824;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782424:
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// bne cr6,0x82782448
	if (!cr6.eq) goto loc_82782448;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82782448
	if (!cr6.eq) goto loc_82782448;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,7816
	ctx.r10.s64 = r11.s64 + 7816;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782448:
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bne cr6,0x827824e4
	if (!cr6.eq) goto loc_827824E4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82782494
	if (!cr6.eq) goto loc_82782494;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782484
	if (cr6.eq) goto loc_82782484;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// ble cr6,0x82782484
	if (!cr6.gt) goto loc_82782484;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8320
	ctx.r10.s64 = r11.s64 + 8320;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782484:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8056
	ctx.r10.s64 = r11.s64 + 8056;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_82782494:
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bne cr6,0x827824e4
	if (!cr6.eq) goto loc_827824E4;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bne cr6,0x827824e4
	if (!cr6.eq) goto loc_827824E4;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827824d4
	if (cr6.eq) goto loc_827824D4;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// ble cr6,0x827824d4
	if (!cr6.gt) goto loc_827824D4;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8568
	ctx.r10.s64 = r11.s64 + 8568;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stb r25,8(r26)
	PPC_STORE_U8(r26.u32 + 8, r25.u8);
	// b 0x82782598
	goto loc_82782598;
loc_827824D4:
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,8160
	ctx.r10.s64 = r11.s64 + 8160;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82782598
	goto loc_82782598;
loc_827824E4:
	// rotlwi r7,r10,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r6,r10,r8
	ctx.r6.s32 = ctx.r10.s32 / ctx.r8.s32;
	// addi r4,r7,-1
	ctx.r4.s64 = ctx.r7.s64 + -1;
	// mullw r5,r6,r8
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// andc r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 & ~ctx.r4.u64;
	// twllei r8,0
	// subf. r3,r5,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// twlgei r7,-1
	// bne 0x8278257c
	if (!cr0.eq) goto loc_8278257C;
	// rotlwi r7,r9,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r6,r9,r11
	ctx.r6.s32 = ctx.r9.s32 / r11.s32;
	// addi r4,r7,-1
	ctx.r4.s64 = ctx.r7.s64 + -1;
	// mullw r5,r6,r11
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// andc r7,r11,r4
	ctx.r7.u64 = r11.u64 & ~ctx.r4.u64;
	// twllei r11,0
	// subf. r3,r5,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// twlgei r7,-1
	// bne 0x8278257c
	if (!cr0.eq) goto loc_8278257C;
	// rotlwi r6,r10,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// rotlwi r7,r9,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r4,r10,r8
	ctx.r4.s32 = ctx.r10.s32 / ctx.r8.s32;
	// addi r3,r6,-1
	ctx.r3.s64 = ctx.r6.s64 + -1;
	// lis r5,-32136
	ctx.r5.s64 = -2106064896;
	// add r10,r27,r26
	ctx.r10.u64 = r27.u64 + r26.u64;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// add r6,r27,r26
	ctx.r6.u64 = r27.u64 + r26.u64;
	// addi r5,r5,7840
	ctx.r5.s64 = ctx.r5.s64 + 7840;
	// divw r9,r9,r11
	ctx.r9.s32 = ctx.r9.s32 / r11.s32;
	// andc r3,r8,r3
	ctx.r3.u64 = ctx.r8.u64 & ~ctx.r3.u64;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// andc r7,r11,r7
	ctx.r7.u64 = r11.u64 & ~ctx.r7.u64;
	// stb r4,140(r10)
	PPC_STORE_U8(ctx.r10.u32 + 140, ctx.r4.u8);
	// twllei r8,0
	// stb r9,150(r6)
	PPC_STORE_U8(ctx.r6.u32 + 150, ctx.r9.u8);
	// twllei r11,0
	// twlgei r3,-1
	// twlgei r7,-1
	// b 0x82782598
	goto loc_82782598;
loc_8278257C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r23,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r23.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82782598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782598:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827825d8
	if (cr6.eq) goto loc_827825D8;
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r22,276(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r4,272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x8277a348
	ctx.lr = 0x827825B8;
	sub_8277A348(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827825D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,-40(r30)
	PPC_STORE_U32(r30.u32 + -40, ctx.r3.u32);
loc_827825D8:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x827823ac
	if (cr6.lt) goto loc_827823AC;
loc_827825F0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_827822E8) {
	__imp__sub_827822E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827825F8) {
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
	ctx.lr = 0x82782600;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r31,420(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 420);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82782664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r7,91
	ctx.r7.s64 = 5963776;
	// lis r8,-227
	ctx.r8.s64 = -14876672;
	// lis r9,-179
	ctx.r9.s64 = -11730944;
	// lis r10,44
	ctx.r10.s64 = 2883584;
	// lis r30,0
	r30.s64 = 0;
	// lis r29,-44
	r29.s64 = -2883584;
	// ori r3,r6,26345
	ctx.r3.u64 = ctx.r6.u64 | 26345;
	// ori r4,r5,50594
	ctx.r4.u64 = ctx.r5.u64 | 50594;
	// li r11,0
	r11.s64 = 0;
	// ori r7,r7,26880
	ctx.r7.u64 = ctx.r7.u64 | 26880;
	// ori r8,r8,44800
	ctx.r8.u64 = ctx.r8.u64 | 44800;
	// ori r9,r9,2944
	ctx.r9.u64 = ctx.r9.u64 | 2944;
	// ori r10,r10,36096
	ctx.r10.u64 = ctx.r10.u64 | 36096;
	// ori r5,r30,46802
	ctx.r5.u64 = r30.u64 | 46802;
	// ori r6,r29,51994
	ctx.r6.u64 = r29.u64 | 51994;
loc_827826CC:
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// srawi r29,r9,16
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	r29.s64 = ctx.r9.s32 >> 16;
	// srawi r28,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	r28.s64 = ctx.r8.s32 >> 16;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stwx r29,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r29.u32);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stwx r28,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r28.u32);
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stwx r7,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r7.u32);
	// subf r7,r5,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r5.s64;
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stwx r10,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r10.u32);
	// addi r10,r10,-22554
	ctx.r10.s64 = ctx.r10.s64 + -22554;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x827826cc
	if (!cr6.lt) goto loc_827826CC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827825F8) {
	__imp__sub_827825F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782718) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82782720;
	// lwz r11,420(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// addic. r23,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r23.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// lwz r24,92(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r7,288(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r28,12(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r27,16(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r26,20(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// blt 0x827827e8
	if (cr0.lt) goto loc_827827E8;
	// rlwinm r25,r5,2,0,29
	r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_82782748:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lwzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// lwzx r11,r25,r8
	r11.u64 = PPC_LOAD_U32(r25.u32 + ctx.r8.u32);
	// lwzx r8,r5,r25
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + r25.u32);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// beq cr6,0x827827e0
	if (cr6.eq) goto loc_827827E0;
	// subf r30,r11,r8
	r30.s64 = ctx.r8.s64 - r11.s64;
	// subf r31,r11,r9
	r31.s64 = ctx.r9.s64 - r11.s64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
loc_82782780:
	// lbzx r5,r30,r11
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// lbzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// rotlwi r3,r5,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r22,r5,2
	r22.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r5,r3,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lbzx r5,r5,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// stb r5,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// lwzx r5,r3,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + r27.u32);
	// lwzx r3,r22,r26
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + r26.u32);
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// srawi r5,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r3.s32 >> 16;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lbzx r3,r5,r7
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r7.u32);
	// stb r3,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r3.u8);
	// lwzx r5,r22,r28
	ctx.r5.u64 = PPC_LOAD_U32(r22.u32 + r28.u32);
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lbzx r5,r9,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// bne 0x82782780
	if (!cr0.eq) goto loc_82782780;
loc_827827E0:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bge 0x82782748
	if (!cr0.lt) goto loc_82782748;
loc_827827E8:
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82782718) {
	__imp__sub_82782718(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827827EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827827EC) {
	__imp__sub_827827EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827827F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827827F8;
	// lwz r31,36(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addic. r30,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r30.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// blt 0x82782870
	if (cr0.lt) goto loc_82782870;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8278280C:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82782860
	if (!cr6.gt) goto loc_82782860;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
loc_8278281C:
	// lwz r29,0(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r10,r29,r5
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + ctx.r5.u32);
	// beq cr6,0x82782850
	if (cr6.eq) goto loc_82782850;
loc_82782838:
	// lbz r29,0(r10)
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r29,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r29.u8);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// bne 0x82782838
	if (!cr0.eq) goto loc_82782838;
loc_82782850:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r8,r31
	cr6.compare<int32_t>(ctx.r8.s32, r31.s32, xer);
	// blt cr6,0x8278281c
	if (cr6.lt) goto loc_8278281C;
loc_82782860:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bge 0x8278280c
	if (!cr0.lt) goto loc_8278280C;
loc_82782870:
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827827F0) {
	__imp__sub_827827F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82782874) {
	__imp__sub_82782874(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8277a378
	sub_8277A378(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82782878) {
	__imp__sub_82782878(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82782894) {
	__imp__sub_82782894(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addic. r31,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r31.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x827828f4
	if (cr0.lt) goto loc_827828F4;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_827828AC:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// beq cr6,0x827828ec
	if (cr6.eq) goto loc_827828EC;
loc_827828CC:
	// lbzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// stb r5,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r5.u8);
	// stb r5,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r5.u8);
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// blt cr6,0x827828cc
	if (cr6.lt) goto loc_827828CC;
loc_827828EC:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x827828ac
	if (!cr0.lt) goto loc_827828AC;
loc_827828F4:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82782898) {
	__imp__sub_82782898(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827828FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827828FC) {
	__imp__sub_827828FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782900) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82782908;
	// lwz r11,420(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// addic. r23,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	r23.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// lwz r24,92(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r8,288(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwz r28,8(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r27,12(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r26,16(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r25,20(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// blt 0x827829f0
	if (cr0.lt) goto loc_827829F0;
	// rlwinm r29,r5,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_82782930:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lwzx r9,r11,r29
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwzx r11,r29,r7
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r7.u32);
	// lwzx r7,r5,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + r29.u32);
	// lwzx r5,r29,r3
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// beq cr6,0x827829e8
	if (cr6.eq) goto loc_827829E8;
	// subf r3,r11,r9
	ctx.r3.s64 = ctx.r9.s64 - r11.s64;
	// subf r31,r11,r7
	r31.s64 = ctx.r7.s64 - r11.s64;
	// subf r30,r11,r5
	r30.s64 = ctx.r5.s64 - r11.s64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
loc_82782974:
	// lbzx r7,r31,r11
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lbzx r22,r3,r11
	r22.u64 = PPC_LOAD_U8(ctx.r3.u32 + r11.u32);
	// rotlwi r21,r5,2
	r21.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r5,r7,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + r28.u32);
	// subf r5,r5,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r5.s64;
	// subf r5,r22,r5
	ctx.r5.s64 = ctx.r5.s64 - r22.s64;
	// lbz r5,255(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 255);
	// stb r5,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r5.u8);
	// lwzx r7,r7,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r26.u32);
	// lwzx r5,r21,r25
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + r25.u32);
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// srawi r5,r7,16
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 16;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r7,r5,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r5.s64;
	// subf r5,r22,r7
	ctx.r5.s64 = ctx.r7.s64 - r22.s64;
	// lbz r7,255(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 255);
	// stb r7,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r7.u8);
	// lwzx r5,r21,r27
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + r27.u32);
	// subf r7,r5,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r5.s64;
	// subf r5,r22,r7
	ctx.r5.s64 = ctx.r7.s64 - r22.s64;
	// lbz r7,255(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 255);
	// stb r7,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r7.u8);
	// lbzx r5,r30,r11
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r5,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r5.u8);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82782974
	if (!cr0.eq) goto loc_82782974;
loc_827829E8:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bge 0x82782930
	if (!cr0.lt) goto loc_82782930;
loc_827829F0:
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82782900) {
	__imp__sub_82782900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827829F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827829F4) {
	__imp__sub_827829F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827829F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r24{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82782A00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r30,420(r31)
	PPC_STORE_U32(r31.u32 + 420, r30.u32);
	// addi r8,r9,0
	ctx.r8.s64 = ctx.r9.s64 + 0;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x82782aa0
	if (cr6.gt) goto loc_82782AA0;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,10844
	r12.s64 = r12.s64 + 10844;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,10864(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10864);
	// lwz r19,10880(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10880);
	// lwz r19,10880(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10880);
	// lwz r19,10896(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10896);
	// lwz r19,10896(r24)
	r19.u64 = PPC_LOAD_U32(r24.u32 + 10896);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82782acc
	if (cr6.eq) goto loc_82782ACC;
	// b 0x82782aac
	goto loc_82782AAC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82782acc
	if (cr6.eq) goto loc_82782ACC;
	// b 0x82782aac
	goto loc_82782AAC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82782acc
	if (cr6.eq) goto loc_82782ACC;
	// b 0x82782aac
	goto loc_82782AAC;
loc_82782AA0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x82782acc
	if (!cr6.lt) goto loc_82782ACC;
loc_82782AAC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,10
	ctx.r10.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782ACC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r29,1
	r29.s64 = 1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82782bb0
	if (cr6.eq) goto loc_82782BB0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82782b54
	if (cr6.eq) goto loc_82782B54;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82782b10
	if (cr6.eq) goto loc_82782B10;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82782bc8
	if (!cr6.eq) goto loc_82782BC8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r10,10224
	ctx.r9.s64 = ctx.r10.s64 + 10224;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B10:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x82782b3c
	if (!cr6.eq) goto loc_82782B3C;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10496
	ctx.r10.s64 = r11.s64 + 10496;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bl 0x827825f8
	ctx.lr = 0x82782B38;
	sub_827825F8(ctx, base);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B3C:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82782bc8
	if (!cr6.eq) goto loc_82782BC8;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,10224
	ctx.r10.s64 = r11.s64 + 10224;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B54:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82782b80
	if (!cr6.eq) goto loc_82782B80;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,10008
	ctx.r10.s64 = r11.s64 + 10008;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bl 0x827825f8
	ctx.lr = 0x82782B7C;
	sub_827825F8(ctx, base);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B80:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82782b98
	if (!cr6.eq) goto loc_82782B98;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,10392
	ctx.r10.s64 = r11.s64 + 10392;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782B98:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82782bc8
	if (!cr6.eq) goto loc_82782BC8;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// addi r10,r11,10224
	ctx.r10.s64 = r11.s64 + 10224;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782BB0:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82782bec
	if (cr6.eq) goto loc_82782BEC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82782bec
	if (cr6.eq) goto loc_82782BEC;
loc_82782BC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,27
	ctx.r10.s64 = 27;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782BE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82782c30
	goto loc_82782C30;
loc_82782BEC:
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r9,r10,10360
	ctx.r9.s64 = ctx.r10.s64 + 10360;
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x82782c30
	if (!cr6.gt) goto loc_82782C30;
	// li r10,84
	ctx.r10.s64 = 84;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82782C10:
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
	// stb r8,48(r9)
	PPC_STORE_U8(ctx.r9.u32 + 48, ctx.r8.u8);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82782c10
	if (cr6.lt) goto loc_82782C10;
loc_82782C30:
	// lbz r11,74(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782c48
	if (cr6.eq) goto loc_82782C48;
	// stw r29,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82782C48:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827829F8) {
	__imp__sub_827829F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782C58) {
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
	ctx.lr = 0x82782C60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r31,416(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 416);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782C84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82782CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82782CE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r7,91
	ctx.r7.s64 = 5963776;
	// lis r8,-227
	ctx.r8.s64 = -14876672;
	// lis r9,-179
	ctx.r9.s64 = -11730944;
	// lis r10,44
	ctx.r10.s64 = 2883584;
	// lis r30,0
	r30.s64 = 0;
	// lis r29,-44
	r29.s64 = -2883584;
	// ori r3,r6,26345
	ctx.r3.u64 = ctx.r6.u64 | 26345;
	// ori r4,r5,50594
	ctx.r4.u64 = ctx.r5.u64 | 50594;
	// li r11,0
	r11.s64 = 0;
	// ori r7,r7,26880
	ctx.r7.u64 = ctx.r7.u64 | 26880;
	// ori r8,r8,44800
	ctx.r8.u64 = ctx.r8.u64 | 44800;
	// ori r9,r9,2944
	ctx.r9.u64 = ctx.r9.u64 | 2944;
	// ori r10,r10,36096
	ctx.r10.u64 = ctx.r10.u64 | 36096;
	// ori r5,r30,46802
	ctx.r5.u64 = r30.u64 | 46802;
	// ori r6,r29,51994
	ctx.r6.u64 = r29.u64 | 51994;
loc_82782D2C:
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// srawi r29,r9,16
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	r29.s64 = ctx.r9.s32 >> 16;
	// srawi r28,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	r28.s64 = ctx.r8.s32 >> 16;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// stwx r29,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r29.u32);
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stwx r28,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r28.u32);
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stwx r7,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r7.u32);
	// subf r7,r5,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r5.s64;
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stwx r10,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r10.u32);
	// addi r10,r10,-22554
	ctx.r10.s64 = ctx.r10.s64 + -22554;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x82782d2c
	if (!cr6.lt) goto loc_82782D2C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82782C58) {
	__imp__sub_82782C58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,416(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,36(r11)
	PPC_STORE_U8(r11.u32 + 36, ctx.r10.u8);
	// lwz r9,96(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// stw r9,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82782D78) {
	__imp__sub_82782D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782D90) {
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
	ctx.lr = 0x82782D98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,416(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82782dec
	if (cr6.eq) goto loc_82782DEC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r5,r11,r5
	ctx.r5.u64 = r11.u64 + ctx.r5.u64;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x8277a378
	ctx.lr = 0x82782DDC;
	sub_8277A378(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r30,1
	r30.s64 = 1;
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
	// b 0x82782e5c
	goto loc_82782E5C;
loc_82782DEC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r30,2
	r30.s64 = 2;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bge cr6,0x82782e00
	if (!cr6.lt) goto loc_82782E00;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82782E00:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// ble cr6,0x82782e14
	if (!cr6.gt) goto loc_82782E14;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
loc_82782E14:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ble cr6,0x82782e38
	if (!cr6.gt) goto loc_82782E38;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// b 0x82782e48
	goto loc_82782E48;
loc_82782E38:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
loc_82782E48:
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82782E5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82782E5C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lbz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// subf r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - r30.s64;
	// stw r8,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82782e8c
	if (!cr6.eq) goto loc_82782E8C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82782E8C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82782D90) {
	__imp__sub_82782D90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82782E94) {
	__imp__sub_82782E94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782E98) {
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
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// lwz r10,416(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r6,r11,r7
	ctx.r6.u64 = r11.u64 + ctx.r7.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82782ED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
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

PPC_WEAK_FUNC(sub_82782E98) {
	__imp__sub_82782E98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82782F04) {
	__imp__sub_82782F04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82782F08) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82782F10;
	// lwz r10,416(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r31,8(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,92(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r28,16(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r4,r5,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r27,20(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r26,24(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r25,28(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r11,288(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// lwzx r7,r7,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// beq cr6,0x82782ff0
	if (cr6.eq) goto loc_82782FF0;
loc_82782F58:
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// addi r6,r5,1
	ctx.r6.s64 = ctx.r5.s64 + 1;
	// lbz r31,0(r7)
	r31.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rotlwi r29,r9,2
	r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lbz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rotlwi r24,r31,2
	r24.u64 = __builtin_rotateleft32(r31.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// lwzx r31,r24,r25
	r31.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// lwzx r5,r29,r26
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r26.u32);
	// add r23,r9,r30
	r23.u64 = ctx.r9.u64 + r30.u64;
	// lwzx r29,r24,r27
	r29.u64 = PPC_LOAD_U32(r24.u32 + r27.u32);
	// add r5,r31,r5
	ctx.r5.u64 = r31.u64 + ctx.r5.u64;
	// add r24,r9,r29
	r24.u64 = ctx.r9.u64 + r29.u64;
	// srawi r31,r5,16
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	r31.s64 = ctx.r5.s32 >> 16;
	// lbzx r23,r23,r11
	r23.u64 = PPC_LOAD_U8(r23.u32 + r11.u32);
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + r31.u64;
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stb r23,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r23.u8);
	// lbzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stb r9,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8);
	// lbzx r9,r24,r11
	ctx.r9.u64 = PPC_LOAD_U8(r24.u32 + r11.u32);
	// stb r9,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lbz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// add r6,r9,r30
	ctx.r6.u64 = ctx.r9.u64 + r30.u64;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// lbzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// lbzx r6,r31,r11
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// stb r6,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// lbzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// stb r9,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// bne 0x82782f58
	if (!cr0.eq) goto loc_82782F58;
loc_82782FF0:
	// lwz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82783050
	if (cr6.eq) goto loc_82783050;
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lbz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rotlwi r5,r8,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r8,r7,r28
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + r28.u32);
	// lwzx r6,r5,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + r25.u32);
	// lwzx r7,r7,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r26.u32);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwzx r8,r5,r27
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + r27.u32);
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r8,r3,16
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 16;
	// lbzx r6,r4,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stb r6,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r6.u8);
	// lbzx r4,r5,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r4,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r4.u8);
	// lbzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + r11.u32);
	// stb r3,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r3.u8);
loc_82783050:
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_82782F08) {
	__imp__sub_82782F08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82783054) {
	__imp__sub_82783054(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783058) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82783060;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r10,r5,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,416(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r4,92(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r11,288(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// rlwinm r28,r4,31,1,31
	r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r26,16(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r29,4(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r25,20(r9)
	r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r24,24(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r23,28(r9)
	r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwzx r31,r7,r8
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// beq cr6,0x827831b0
	if (cr6.eq) goto loc_827831B0;
loc_827830B8:
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lbz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rotlwi r6,r8,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rotlwi r22,r7,2
	r22.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwzx r7,r6,r26
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + r26.u32);
	// lwzx r27,r22,r23
	r27.u64 = PPC_LOAD_U32(r22.u32 + r23.u32);
	// lwzx r8,r6,r24
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + r24.u32);
	// add r21,r5,r7
	r21.u64 = ctx.r5.u64 + ctx.r7.u64;
	// lwzx r6,r22,r25
	ctx.r6.u64 = PPC_LOAD_U32(r22.u32 + r25.u32);
	// add r8,r27,r8
	ctx.r8.u64 = r27.u64 + ctx.r8.u64;
	// add r27,r5,r6
	r27.u64 = ctx.r5.u64 + ctx.r6.u64;
	// srawi r8,r8,16
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 16;
	// lbzx r22,r21,r11
	r22.u64 = PPC_LOAD_U8(r21.u32 + r11.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// stb r22,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r22.u8);
	// lbzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r5,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r5.u8);
	// lbzx r5,r27,r11
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lbz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// add r27,r5,r7
	r27.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r22,r5,r8
	r22.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lbzx r27,r27,r11
	r27.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stb r27,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r27.u8);
	// lbzx r27,r22,r11
	r27.u64 = PPC_LOAD_U8(r22.u32 + r11.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stb r27,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, r27.u8);
	// lbzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lbz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// add r27,r5,r7
	r27.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r22,r5,r8
	r22.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lbzx r27,r27,r11
	r27.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stb r27,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r27.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lbzx r27,r22,r11
	r27.u64 = PPC_LOAD_U8(r22.u32 + r11.u32);
	// stb r27,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r27.u8);
	// lbzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + r11.u32);
	// stb r5,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// lbz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// add r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lbzx r7,r7,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + r11.u32);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stb r7,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r7.u8);
	// lbzx r5,r8,r11
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stb r5,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r5.u8);
	// lbzx r8,r6,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// stb r8,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r8.u8);
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// bne 0x827830b8
	if (!cr0.eq) goto loc_827830B8;
loc_827831B0:
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82783238
	if (cr6.eq) goto loc_82783238;
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rotlwi r5,r7,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lbz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rotlwi r3,r4,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwzx r6,r5,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + r26.u32);
	// lwzx r4,r3,r23
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + r23.u32);
	// lwzx r7,r5,r24
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + r24.u32);
	// add r31,r8,r6
	r31.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lwzx r5,r3,r25
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + r25.u32);
	// add r7,r4,r7
	ctx.r7.u64 = ctx.r4.u64 + ctx.r7.u64;
	// add r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 + ctx.r5.u64;
	// srawi r7,r7,16
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 16;
	// lbzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + r11.u32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stb r3,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// lbzx r3,r8,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// stb r3,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r3.u8);
	// lbzx r8,r4,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// stb r8,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r8.u8);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lbzx r3,r6,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r6.u32 + r11.u32);
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stb r3,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r3.u8);
	// lbzx r8,r4,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + r11.u32);
	// stb r8,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, ctx.r8.u8);
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// stb r7,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, ctx.r7.u8);
loc_82783238:
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82783058) {
	__imp__sub_82783058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8278323C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8278323C) {
	__imp__sub_8278323C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783240) {
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
	// li r5,48
	ctx.r5.s64 = 48;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82783270;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// li r11,0
	r11.s64 = 0;
	// stw r31,416(r30)
	PPC_STORE_U32(r30.u32 + 416, r31.u32);
	// addi r8,r9,11640
	ctx.r8.s64 = ctx.r9.s64 + 11640;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// lwz r7,100(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r6,92(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// mullw r5,r7,r6
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// lwz r4,276(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x827832e4
	if (!cr6.eq) goto loc_827832E4;
	// lis r11,-32136
	r11.s64 = -2106064896;
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r11,11664
	ctx.r9.s64 = r11.s64 + 11664;
	// addi r8,r10,12376
	ctx.r8.s64 = ctx.r10.s64 + 12376;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// rotlwi r5,r5,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827832DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// b 0x82783300
	goto loc_82783300;
loc_827832E4:
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// addi r8,r10,11928
	ctx.r8.s64 = ctx.r10.s64 + 11928;
	// addi r7,r9,12040
	ctx.r7.s64 = ctx.r9.s64 + 12040;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
loc_82783300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82782c58
	ctx.lr = 0x82783308;
	sub_82782C58(ctx, base);
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

PPC_WEAK_FUNC(sub_82783240) {
	__imp__sub_82783240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783320) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r31,92(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// ble cr6,0x827833b0
	if (!cr6.gt) goto loc_827833B0;
	// lis r11,0
	r11.s64 = 0;
	// ori r3,r11,65535
	ctx.r3.u64 = r11.u64 | 65535;
loc_82783340:
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827833a4
	if (cr6.eq) goto loc_827833A4;
loc_82783350:
	// lbz r11,1(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1);
	// lbz r10,2(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// lbz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// rlwinm r11,r11,3,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFE0;
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r9,31,1,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// lhzx r11,r10,r9
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82783398
	if (!cr6.eq) goto loc_82783398;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
loc_82783398:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// bne 0x82783350
	if (!cr0.eq) goto loc_82783350;
loc_827833A4:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x82783340
	if (!cr0.eq) goto loc_82783340;
loc_827833B0:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82783320) {
	__imp__sub_82783320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827833B8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x827833C0;
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// lwz r31,0(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r26,4(r4)
	r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r29,8(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r27,12(r4)
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmpw cr6,r26,r31
	cr6.compare<int32_t>(r26.s32, r31.s32, xer);
	// lwz r25,24(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r30,16(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r28,20(r4)
	r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// ble cr6,0x827834f8
	if (!cr6.gt) goto loc_827834F8;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// add r7,r11,r25
	ctx.r7.u64 = r11.u64 + r25.u64;
loc_827833F4:
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bgt cr6,0x82783450
	if (cr6.gt) goto loc_82783450;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
loc_82783414:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bgt cr6,0x82783440
	if (cr6.gt) goto loc_82783440;
loc_82783424:
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783464
	if (!cr6.eq) goto loc_82783464;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x82783424
	if (!cr6.gt) goto loc_82783424;
loc_82783440:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r8,r27
	cr6.compare<int32_t>(ctx.r8.s32, r27.s32, xer);
	// ble cr6,0x82783414
	if (!cr6.gt) goto loc_82783414;
loc_82783450:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r6,r26
	cr6.compare<int32_t>(ctx.r6.s32, r26.s32, xer);
	// ble cr6,0x827833f4
	if (!cr6.gt) goto loc_827833F4;
	// b 0x8278346c
	goto loc_8278346C;
loc_82783464:
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
loc_8278346C:
	// cmpw cr6,r26,r31
	cr6.compare<int32_t>(r26.s32, r31.s32, xer);
	// ble cr6,0x827834f8
	if (!cr6.gt) goto loc_827834F8;
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// add r7,r11,r25
	ctx.r7.u64 = r11.u64 + r25.u64;
loc_82783480:
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bgt cr6,0x827834dc
	if (cr6.gt) goto loc_827834DC;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
loc_827834A0:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bgt cr6,0x827834cc
	if (cr6.gt) goto loc_827834CC;
loc_827834B0:
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827834f0
	if (!cr6.eq) goto loc_827834F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x827834b0
	if (!cr6.gt) goto loc_827834B0;
loc_827834CC:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r8,r27
	cr6.compare<int32_t>(ctx.r8.s32, r27.s32, xer);
	// ble cr6,0x827834a0
	if (!cr6.gt) goto loc_827834A0;
loc_827834DC:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// cmpw cr6,r6,r31
	cr6.compare<int32_t>(ctx.r6.s32, r31.s32, xer);
	// bge cr6,0x82783480
	if (!cr6.lt) goto loc_82783480;
	// b 0x827834f8
	goto loc_827834F8;
loc_827834F0:
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
loc_827834F8:
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bge cr6,0x82783608
	if (!cr6.lt) goto loc_82783608;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_82783510:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x82783564
	if (cr6.gt) goto loc_82783564;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
loc_82783524:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bgt cr6,0x82783554
	if (cr6.gt) goto loc_82783554;
loc_82783538:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783578
	if (!cr6.eq) goto loc_82783578;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x82783538
	if (!cr6.gt) goto loc_82783538;
loc_82783554:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x82783524
	if (!cr6.gt) goto loc_82783524;
loc_82783564:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// cmpw cr6,r6,r27
	cr6.compare<int32_t>(ctx.r6.s32, r27.s32, xer);
	// ble cr6,0x82783510
	if (!cr6.gt) goto loc_82783510;
	// b 0x82783580
	goto loc_82783580;
loc_82783578:
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r6,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r6.u32);
loc_82783580:
	// cmpw cr6,r27,r29
	cr6.compare<int32_t>(r27.s32, r29.s32, xer);
	// ble cr6,0x82783608
	if (!cr6.gt) goto loc_82783608;
	// rlwinm r11,r27,5,0,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_82783598:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x827835ec
	if (cr6.gt) goto loc_827835EC;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
loc_827835AC:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bgt cr6,0x827835dc
	if (cr6.gt) goto loc_827835DC;
loc_827835C0:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783600
	if (!cr6.eq) goto loc_82783600;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x827835c0
	if (!cr6.gt) goto loc_827835C0;
loc_827835DC:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x827835ac
	if (!cr6.gt) goto loc_827835AC;
loc_827835EC:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r8,r8,-64
	ctx.r8.s64 = ctx.r8.s64 + -64;
	// cmpw cr6,r6,r29
	cr6.compare<int32_t>(ctx.r6.s32, r29.s32, xer);
	// bge cr6,0x82783598
	if (!cr6.lt) goto loc_82783598;
	// b 0x82783608
	goto loc_82783608;
loc_82783600:
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// stw r6,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r6.u32);
loc_82783608:
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bge cr6,0x82783710
	if (!cr6.lt) goto loc_82783710;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
loc_82783614:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x82783674
	if (cr6.gt) goto loc_82783674;
	// rlwinm r10,r29,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
loc_82783634:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// bgt cr6,0x82783664
	if (cr6.gt) goto loc_82783664;
loc_82783648:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783684
	if (!cr6.eq) goto loc_82783684;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// ble cr6,0x82783648
	if (!cr6.gt) goto loc_82783648;
loc_82783664:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x82783634
	if (!cr6.gt) goto loc_82783634;
loc_82783674:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r28
	cr6.compare<int32_t>(ctx.r6.s32, r28.s32, xer);
	// ble cr6,0x82783614
	if (!cr6.gt) goto loc_82783614;
	// b 0x8278368c
	goto loc_8278368C;
loc_82783684:
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// stw r6,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r6.u32);
loc_8278368C:
	// cmpw cr6,r28,r30
	cr6.compare<int32_t>(r28.s32, r30.s32, xer);
	// ble cr6,0x82783710
	if (!cr6.gt) goto loc_82783710;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_82783698:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x827836f8
	if (cr6.gt) goto loc_827836F8;
	// rlwinm r10,r29,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
loc_827836B8:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// bgt cr6,0x827836e8
	if (cr6.gt) goto loc_827836E8;
loc_827836CC:
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82783708
	if (!cr6.eq) goto loc_82783708;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// ble cr6,0x827836cc
	if (!cr6.gt) goto loc_827836CC;
loc_827836E8:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// ble cr6,0x827836b8
	if (!cr6.gt) goto loc_827836B8;
loc_827836F8:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// cmpw cr6,r6,r30
	cr6.compare<int32_t>(ctx.r6.s32, r30.s32, xer);
	// bge cr6,0x82783698
	if (!cr6.lt) goto loc_82783698;
	// b 0x82783710
	goto loc_82783710;
loc_82783708:
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stw r6,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r6.u32);
loc_82783710:
	// subf r8,r29,r27
	ctx.r8.s64 = r27.s64 - r29.s64;
	// subf r5,r30,r28
	ctx.r5.s64 = r28.s64 - r30.s64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r5,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subf r11,r31,r26
	r11.s64 = r26.s64 - r31.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r10,r9,r9
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
	// mullw r9,r6,r6
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r6.s32);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r10.u32);
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// bgt cr6,0x827837c4
	if (cr6.gt) goto loc_827837C4;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// add r6,r10,r25
	ctx.r6.u64 = ctx.r10.u64 + r25.u64;
loc_82783760:
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bgt cr6,0x827837b8
	if (cr6.gt) goto loc_827837B8;
	// rlwinm r11,r29,5,0,26
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
loc_82783780:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bgt cr6,0x827837ac
	if (cr6.gt) goto loc_827837AC;
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
loc_82783790:
	// lhz r26,0(r10)
	r26.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x827837a0
	if (cr6.eq) goto loc_827837A0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_827837A0:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bne 0x82783790
	if (!cr0.eq) goto loc_82783790;
loc_827837AC:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// bne 0x82783780
	if (!cr0.eq) goto loc_82783780;
loc_827837B8:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x82783760
	if (!cr0.eq) goto loc_82783760;
loc_827837C4:
	// stw r3,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r3.u32);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_827833B8) {
	__imp__sub_827833B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827837CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827837CC) {
	__imp__sub_827837CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827837D0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x827837D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// bge cr6,0x827839a4
	if (!cr6.lt) goto loc_827839A4;
	// rlwinm r11,r27,5,0,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r26,r27,1,0,30
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// addi r31,r11,12
	r31.s64 = r11.s64 + 12;
loc_82783804:
	// cmpw cr6,r26,r23
	cr6.compare<int32_t>(r26.s32, r23.s32, xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bgt cr6,0x82783854
	if (cr6.gt) goto loc_82783854;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82783884
	if (!cr6.gt) goto loc_82783884;
	// addi r11,r25,28
	r11.s64 = r25.s64 + 28;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_82783824:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x82783844
	if (!cr6.gt) goto loc_82783844;
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82783844
	if (!cr6.gt) goto loc_82783844;
	// addi r4,r11,-28
	ctx.r4.s64 = r11.s64 + -28;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82783844:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82783824
	if (!cr0.eq) goto loc_82783824;
	// b 0x82783884
	goto loc_82783884;
loc_82783854:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82783884
	if (!cr6.gt) goto loc_82783884;
	// addi r11,r25,24
	r11.s64 = r25.s64 + 24;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_82783864:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x82783878
	if (!cr6.gt) goto loc_82783878;
	// addi r4,r11,-24
	ctx.r4.s64 = r11.s64 + -24;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82783878:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x82783864
	if (!cr0.eq) goto loc_82783864;
loc_82783884:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827839a4
	if (cr6.eq) goto loc_827839A4;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r29,r31,-12
	r29.s64 = r31.s64 + -12;
	// li r30,1
	r30.s64 = 1;
	// stw r11,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, r11.u32);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r8,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, ctx.r8.u32);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r7,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r7.u32);
	// lwz r6,16(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r5,20(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r3,16(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// subf r11,r6,r7
	r11.s64 = ctx.r7.s64 - ctx.r6.s64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r28,r8,r9
	r28.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r28,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r28,r3,r5
	r28.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r28,3,0,28
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8278390c
	if (!cr6.gt) goto loc_8278390C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// li r30,0
	r30.s64 = 0;
loc_8278390C:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// ble cr6,0x82783918
	if (!cr6.gt) goto loc_82783918;
	// li r30,2
	r30.s64 = 2;
loc_82783918:
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// blt cr6,0x82783964
	if (cr6.lt) goto loc_82783964;
	// beq cr6,0x82783948
	if (cr6.eq) goto loc_82783948;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bge cr6,0x8278397c
	if (!cr6.lt) goto loc_8278397C;
	// add r11,r3,r5
	r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// b 0x8278397c
	goto loc_8278397C;
loc_82783948:
	// add r11,r6,r7
	r11.u64 = ctx.r6.u64 + ctx.r7.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r9,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r9.u32);
	// b 0x8278397c
	goto loc_8278397C;
loc_82783964:
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
loc_8278397C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827833b8
	ctx.lr = 0x82783984;
	sub_827833B8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827833b8
	ctx.lr = 0x82783990;
	sub_827833B8(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r27,r23
	cr6.compare<int32_t>(r27.s32, r23.s32, xer);
	// blt cr6,0x82783804
	if (cr6.lt) goto loc_82783804;
loc_827839A4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_827837D0) {
	__imp__sub_827837D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827839B0) {
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
	ctx.lr = 0x827839B8;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lwz r6,424(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r23,8(r8)
	r23.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r19,12(r8)
	r19.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lwz r9,24(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r26,16(r8)
	r26.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r21,20(r8)
	r21.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bgt cr6,0x82783aac
	if (cr6.gt) goto loc_82783AAC;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// addi r28,r8,4
	r28.s64 = ctx.r8.s64 + 4;
	// add r20,r6,r9
	r20.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r18,r11,1
	r18.s64 = r11.s64 + 1;
loc_82783A0C:
	// cmpw cr6,r23,r19
	cr6.compare<int32_t>(r23.s32, r19.s32, xer);
	// bgt cr6,0x82783a9c
	if (cr6.gt) goto loc_82783A9C;
	// rlwinm r11,r23,5,0,26
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r26
	ctx.r8.u64 = r11.u64 + r26.u64;
	// subf r11,r23,r19
	r11.s64 = r19.s64 - r23.s64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r10,2
	r29.s64 = ctx.r10.s64 + 2;
	// add r24,r8,r9
	r24.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
loc_82783A38:
	// mr r25,r24
	r25.u64 = r24.u64;
	// cmpw cr6,r26,r21
	cr6.compare<int32_t>(r26.s32, r21.s32, xer);
	// bgt cr6,0x82783a8c
	if (cr6.gt) goto loc_82783A8C;
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r26,r21
	r11.s64 = r21.s64 - r26.s64;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// addi r27,r11,1
	r27.s64 = r11.s64 + 1;
loc_82783A54:
	// lhz r11,0(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 0);
	// addi r25,r25,2
	r25.s64 = r25.s64 + 2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82783a80
	if (cr6.eq) goto loc_82783A80;
	// mullw r8,r28,r11
	ctx.r8.s64 = int64_t(r28.s32) * int64_t(r11.s32);
	// mullw r9,r29,r11
	ctx.r9.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// mullw r10,r6,r11
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// add r4,r8,r4
	ctx.r4.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
loc_82783A80:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// bne 0x82783a54
	if (!cr0.eq) goto loc_82783A54;
loc_82783A8C:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r24,r24,64
	r24.s64 = r24.s64 + 64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82783a38
	if (!cr0.eq) goto loc_82783A38;
loc_82783A9C:
	// addic. r18,r18,-1
	xer.ca = r18.u32 > 0;
	r18.s64 = r18.s64 + -1;
	cr0.compare<int32_t>(r18.s32, 0, xer);
	// addi r20,r20,4
	r20.s64 = r20.s64 + 4;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x82783a0c
	if (!cr0.eq) goto loc_82783A0C;
loc_82783AAC:
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// srawi r11,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r11.s64 = ctx.r7.s32 >> 1;
	// twllei r7,0
	// add r9,r11,r4
	ctx.r9.u64 = r11.u64 + ctx.r4.u64;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// divw r31,r9,r7
	r31.s32 = ctx.r9.s32 / ctx.r7.s32;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r30,r8,r7
	r30.s32 = ctx.r8.s32 / ctx.r7.s32;
	// rotlwi r11,r6,1
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// stbx r31,r4,r5
	PPC_STORE_U8(ctx.r4.u32 + ctx.r5.u32, r31.u8);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// lwz r8,116(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stbx r30,r10,r5
	PPC_STORE_U8(ctx.r10.u32 + ctx.r5.u32, r30.u8);
	// andc r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 & ~ctx.r9.u64;
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// andc r8,r7,r4
	ctx.r8.u64 = ctx.r7.u64 & ~ctx.r4.u64;
	// divw r6,r6,r7
	ctx.r6.s32 = ctx.r6.s32 / ctx.r7.s32;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// andc r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 & ~r11.u64;
	// twllei r7,0
	// stbx r6,r4,r5
	PPC_STORE_U8(ctx.r4.u32 + ctx.r5.u32, ctx.r6.u8);
	// twllei r7,0
	// twlgei r10,-1
	// twlgei r8,-1
	// twlgei r3,-1
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_827839B0) {
	__imp__sub_827839B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82783B2C) {
	__imp__sub_82783B2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783B30) {
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
	ctx.lr = 0x82783B38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// rlwinm r5,r29,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82783B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r11,31
	r11.s64 = 31;
	// li r9,63
	ctx.r9.s64 = 63;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x827833b8
	ctx.lr = 0x82783B90;
	sub_827833B8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827837d0
	ctx.lr = 0x82783BA0;
	sub_827837D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82783bcc
	if (!cr6.gt) goto loc_82783BCC;
loc_82783BB0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827839b0
	ctx.lr = 0x82783BBC;
	sub_827839B0(ctx, base);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r5,r29
	cr6.compare<int32_t>(ctx.r5.s32, r29.s32, xer);
	// blt cr6,0x82783bb0
	if (cr6.lt) goto loc_82783BB0;
loc_82783BCC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,96
	ctx.r10.s64 = 96;
	// stw r29,112(r30)
	PPC_STORE_U32(r30.u32 + 112, r29.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82783BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82783B30) {
	__imp__sub_82783B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82783C04) {
	__imp__sub_82783C04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783C08) {
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
	ctx.lr = 0x82783C10;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r4,24
	r28.s64 = ctx.r4.s64 + 24;
	// lwz r25,112(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// addi r30,r5,28
	r30.s64 = ctx.r5.s64 + 28;
	// addi r29,r6,24
	r29.s64 = ctx.r6.s64 + 24;
	// add r11,r28,r4
	r11.u64 = r28.u64 + ctx.r4.u64;
	// add r10,r30,r5
	ctx.r10.u64 = r30.u64 + ctx.r5.u64;
	// add r9,r29,r6
	ctx.r9.u64 = r29.u64 + ctx.r6.u64;
	// lis r23,32767
	r23.s64 = 2147418112;
	// srawi r24,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r24.s64 = r11.s32 >> 1;
	// srawi r19,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	r19.s64 = ctx.r10.s32 >> 1;
	// srawi r18,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	r18.s64 = ctx.r9.s32 >> 1;
	// ori r23,r23,65535
	r23.u64 = r23.u64 | 65535;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82783dd0
	if (!cr6.gt) goto loc_82783DD0;
	// lwz r11,116(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r26,r1,16
	r26.s64 = ctx.r1.s64 + 16;
	// lwz r22,0(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r21,4(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r20,8(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82783C64:
	// lbzx r11,r22,r27
	r11.u64 = PPC_LOAD_U8(r22.u32 + r27.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bge cr6,0x82783c8c
	if (!cr6.lt) goto loc_82783C8C;
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// subf r9,r28,r11
	ctx.r9.s64 = r11.s64 - r28.s64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r9,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r10,r8,r8
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// b 0x82783cd0
	goto loc_82783CD0;
loc_82783C8C:
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x82783cb0
	if (!cr6.gt) goto loc_82783CB0;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// subf r9,r4,r11
	ctx.r9.s64 = r11.s64 - ctx.r4.s64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r9,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r10,r8,r8
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// b 0x82783cd0
	goto loc_82783CD0;
loc_82783CB0:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// bgt cr6,0x82783cc4
	if (cr6.gt) goto loc_82783CC4;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// b 0x82783cc8
	goto loc_82783CC8;
loc_82783CC4:
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
loc_82783CC8:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r9
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
loc_82783CD0:
	// lbzx r11,r21,r27
	r11.u64 = PPC_LOAD_U8(r21.u32 + r27.u32);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bge cr6,0x82783d00
	if (!cr6.lt) goto loc_82783D00;
	// subf r8,r5,r11
	ctx.r8.s64 = r11.s64 - ctx.r5.s64;
	// subf r3,r30,r11
	ctx.r3.s64 = r11.s64 - r30.s64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r3,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// mullw r8,r11,r11
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(r11.s32);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783d48
	goto loc_82783D48;
loc_82783D00:
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// ble cr6,0x82783d2c
	if (!cr6.gt) goto loc_82783D2C;
	// subf r8,r30,r11
	ctx.r8.s64 = r11.s64 - r30.s64;
	// subf r3,r5,r11
	ctx.r3.s64 = r11.s64 - ctx.r5.s64;
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r3,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// mullw r8,r11,r11
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(r11.s32);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783d48
	goto loc_82783D48;
loc_82783D2C:
	// cmpw cr6,r11,r19
	cr6.compare<int32_t>(r11.s32, r19.s32, xer);
	// bgt cr6,0x82783d3c
	if (cr6.gt) goto loc_82783D3C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// b 0x82783d40
	goto loc_82783D40;
loc_82783D3C:
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
loc_82783D40:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
loc_82783D48:
	// mullw r11,r11,r11
	r11.s64 = int64_t(r11.s32) * int64_t(r11.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbzx r9,r20,r27
	ctx.r9.u64 = PPC_LOAD_U8(r20.u32 + r27.u32);
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// bge cr6,0x82783d74
	if (!cr6.lt) goto loc_82783D74;
	// subf r8,r6,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r6.s64;
	// subf r3,r29,r9
	ctx.r3.s64 = ctx.r9.s64 - r29.s64;
	// mullw r8,r8,r8
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783dac
	goto loc_82783DAC;
loc_82783D74:
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// ble cr6,0x82783d94
	if (!cr6.gt) goto loc_82783D94;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
	// subf r3,r6,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r6.s64;
	// mullw r8,r8,r8
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r8.s32);
	// mullw r9,r3,r3
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r3.s32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82783dac
	goto loc_82783DAC;
loc_82783D94:
	// cmpw cr6,r9,r18
	cr6.compare<int32_t>(ctx.r9.s32, r18.s32, xer);
	// bgt cr6,0x82783da4
	if (cr6.gt) goto loc_82783DA4;
	// subf r9,r29,r9
	ctx.r9.s64 = ctx.r9.s64 - r29.s64;
	// b 0x82783da8
	goto loc_82783DA8;
loc_82783DA4:
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
loc_82783DA8:
	// mullw r9,r9,r9
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
loc_82783DAC:
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// bge cr6,0x82783dc0
	if (!cr6.lt) goto loc_82783DC0;
	// mr r23,r11
	r23.u64 = r11.u64;
loc_82783DC0:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r27,r25
	cr6.compare<int32_t>(r27.s32, r25.s32, xer);
	// blt cr6,0x82783c64
	if (cr6.lt) goto loc_82783C64;
loc_82783DD0:
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82783e08
	if (!cr6.gt) goto loc_82783E08;
	// addi r10,r1,16
	ctx.r10.s64 = ctx.r1.s64 + 16;
loc_82783DE4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r23
	cr6.compare<int32_t>(ctx.r9.s32, r23.s32, xer);
	// bgt cr6,0x82783df8
	if (cr6.gt) goto loc_82783DF8;
	// stbx r11,r3,r7
	PPC_STORE_U8(ctx.r3.u32 + ctx.r7.u32, r11.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82783DF8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// blt cr6,0x82783de4
	if (cr6.lt) goto loc_82783DE4;
loc_82783E08:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_82783C08) {
	__imp__sub_82783C08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783E10) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82783E18;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,32767
	r31.s64 = 2147418112;
	// addi r11,r1,16
	r11.s64 = ctx.r1.s64 + 16;
	// ori r31,r31,65535
	r31.u64 = r31.u64 | 65535;
	// li r10,128
	ctx.r10.s64 = 128;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82783E30:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82783e30
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82783E30;
	// li r19,0
	r19.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82783f64
	if (!cr6.gt) goto loc_82783F64;
loc_82783E48:
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r11,r1,16
	r11.s64 = ctx.r1.s64 + 16;
	// lbzx r28,r19,r8
	r28.u64 = PPC_LOAD_U8(r19.u32 + ctx.r8.u32);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// li r22,3
	r22.s64 = 3;
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r29,0(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + r28.u32);
	// lbzx r31,r30,r28
	r31.u64 = PPC_LOAD_U8(r30.u32 + r28.u32);
	// subf r10,r10,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lbzx r29,r28,r29
	r29.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// subf r30,r31,r6
	r30.s64 = ctx.r6.s64 - r31.s64;
	// rlwinm r31,r10,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r29,r29,r4
	r29.s64 = ctx.r4.s64 - r29.s64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// rlwinm r31,r29,1,0,30
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r10,6
	r29.s64 = ctx.r10.s64 + 6;
	// mullw r25,r10,r10
	r25.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r10.s32);
	// mullw r10,r30,r30
	ctx.r10.s64 = int64_t(r30.s32) * int64_t(r30.s32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// rlwinm r26,r29,1,0,30
	r26.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + r25.u64;
	// rlwinm r25,r30,4,0,27
	r25.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// mullw r30,r31,r31
	r30.s64 = int64_t(r31.s32) * int64_t(r31.s32);
	// add r29,r29,r26
	r29.u64 = r29.u64 + r26.u64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// add r26,r10,r30
	r26.u64 = ctx.r10.u64 + r30.u64;
	// rlwinm r20,r29,3,0,28
	r20.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r21,r31,5,0,26
	r21.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r24,r25,128
	r24.s64 = r25.s64 + 128;
	// addi r23,r25,256
	r23.s64 = r25.s64 + 256;
loc_82783EC8:
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r29,r20
	r29.u64 = r20.u64;
	// li r30,7
	r30.s64 = 7;
loc_82783ED4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bge cr6,0x82783ee8
	if (!cr6.lt) goto loc_82783EE8;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stb r28,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r28.u8);
loc_82783EE8:
	// lwz r18,4(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r31,r25
	ctx.r10.u64 = r31.u64 + r25.u64;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bge cr6,0x82783f00
	if (!cr6.lt) goto loc_82783F00;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stb r28,1(r27)
	PPC_STORE_U8(r27.u32 + 1, r28.u8);
loc_82783F00:
	// lwz r18,8(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r24,r10
	ctx.r10.u64 = r24.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bge cr6,0x82783f18
	if (!cr6.lt) goto loc_82783F18;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stb r28,2(r27)
	PPC_STORE_U8(r27.u32 + 2, r28.u8);
loc_82783F18:
	// lwz r18,12(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r10,r23,r10
	ctx.r10.u64 = r23.u64 + ctx.r10.u64;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// bge cr6,0x82783f30
	if (!cr6.lt) goto loc_82783F30;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stb r28,3(r27)
	PPC_STORE_U8(r27.u32 + 3, r28.u8);
loc_82783F30:
	// add r31,r29,r31
	r31.u64 = r29.u64 + r31.u64;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// bge 0x82783ed4
	if (!cr0.lt) goto loc_82783ED4;
	// add r26,r21,r26
	r26.u64 = r21.u64 + r26.u64;
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r21,r21,512
	r21.s64 = r21.s64 + 512;
	// bge 0x82783ec8
	if (!cr0.lt) goto loc_82783EC8;
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// cmpw cr6,r19,r7
	cr6.compare<int32_t>(r19.s32, ctx.r7.s32, xer);
	// blt cr6,0x82783e48
	if (cr6.lt) goto loc_82783E48;
loc_82783F64:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_82783E10) {
	__imp__sub_82783E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82783F6C) {
	__imp__sub_82783F6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82783F70) {
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
	ctx.lr = 0x82783F78;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// srawi r31,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r31.s64 = ctx.r4.s32 >> 2;
	// srawi r30,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	r30.s64 = ctx.r5.s32 >> 3;
	// srawi r29,r6,2
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	r29.s64 = ctx.r6.s32 >> 2;
	// rlwinm r11,r31,5,0,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,424(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 424);
	// rlwinm r10,r30,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r9,r29,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lwz r28,24(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// bl 0x82783c08
	ctx.lr = 0x82783FB4;
	sub_82783C08(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82783e10
	ctx.lr = 0x82783FC8;
	sub_82783E10(ctx, base);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r30,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r31,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r31,r5,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r9,r28
	ctx.r4.u64 = ctx.r9.u64 + r28.u64;
	// li r3,4
	ctx.r3.s64 = 4;
loc_82783FE8:
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r9,8
	ctx.r9.s64 = 8;
loc_82783FF0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r30,r7,1
	r30.s64 = ctx.r7.s64 + 1;
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// sth r30,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r30.u16);
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// sth r6,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r6.u16);
	// sth r5,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r5.u16);
	// sth r7,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r7.u16);
	// bne 0x82783ff0
	if (!cr0.eq) goto loc_82783FF0;
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x82783fe8
	if (!cr0.eq) goto loc_82783FE8;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82783F70) {
	__imp__sub_82783F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8278404C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8278404C) {
	__imp__sub_8278404C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82784050) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82784058;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwz r11,424(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 424);
	// lwz r23,92(r24)
	r23.u64 = PPC_LOAD_U32(r24.u32 + 92);
	// lwz r26,24(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// ble cr6,0x82784104
	if (!cr6.gt) goto loc_82784104;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// subf r22,r5,r4
	r22.s64 = ctx.r4.s64 - ctx.r5.s64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
loc_82784080:
	// lwzx r31,r22,r25
	r31.u64 = PPC_LOAD_U32(r22.u32 + r25.u32);
	// mr r28,r23
	r28.u64 = r23.u64;
	// lwz r27,0(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x827840f8
	if (cr6.eq) goto loc_827840F8;
loc_82784094:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r4,r10,29,3,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r5,r9,30,2,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r5,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// rlwinm r6,r7,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// lwzx r29,r8,r26
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r30,r3,1,0,30
	r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r30,r29
	r11.u64 = PPC_LOAD_U16(r30.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827840e0
	if (!cr6.eq) goto loc_827840E0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82783f70
	ctx.lr = 0x827840E0;
	sub_82783F70(ctx, base);
loc_827840E0:
	// lhzx r11,r30,r29
	r11.u64 = PPC_LOAD_U16(r30.u32 + r29.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r11,r11,255
	r11.s64 = r11.s64 + 255;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// bne 0x82784094
	if (!cr0.eq) goto loc_82784094;
loc_827840F8:
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x82784080
	if (!cr0.eq) goto loc_82784080;
loc_82784104:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82784050) {
	__imp__sub_82784050(ctx, base);
}

