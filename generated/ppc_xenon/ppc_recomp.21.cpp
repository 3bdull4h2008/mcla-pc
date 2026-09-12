#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821F1234"))) PPC_WEAK_FUNC(sub_821F1234);
PPC_FUNC_IMPL(__imp__sub_821F1234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1238"))) PPC_WEAK_FUNC(sub_821F1238);
PPC_FUNC_IMPL(__imp__sub_821F1238) {
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
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x821F125C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x821f12a0
	if (!cr6.gt) goto loc_821F12A0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_821F1274:
	// addic. r9,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r9.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x821f1294
	if (cr0.eq) goto loc_821F1294;
	// stw r10,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r10.u32);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_821F1294:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bne 0x821f1274
	if (!cr0.eq) goto loc_821F1274;
loc_821F12A0:
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

__attribute__((alias("__imp__sub_821F12B4"))) PPC_WEAK_FUNC(sub_821F12B4);
PPC_FUNC_IMPL(__imp__sub_821F12B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F12B8"))) PPC_WEAK_FUNC(sub_821F12B8);
PPC_FUNC_IMPL(__imp__sub_821F12B8) {
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
	ctx.lr = 0x821F12C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x821f1308
	if (cr6.eq) goto loc_821F1308;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r11.u16);
	// sth r11,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821f1304
	if (cr6.eq) goto loc_821F1304;
	// bl 0x821f1238
	ctx.lr = 0x821F12FC;
	sub_821F1238(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// b 0x821f1308
	goto loc_821F1308;
loc_821F1304:
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
loc_821F1308:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f1380
	if (cr6.eq) goto loc_821F1380;
loc_821F1314:
	// rlwinm r11,r29,1,0,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// add r31,r9,r11
	r31.u64 = ctx.r9.u64 + r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// bl 0x821d2a58
	ctx.lr = 0x821F133C;
	sub_821D2A58(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F1348;
	sub_821D2A58(ctx, base);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821d2a58
	ctx.lr = 0x821F1354;
	sub_821D2A58(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,16(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// clrlwi r29,r10,16
	r29.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// lhz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// blt cr6,0x821f1314
	if (cr6.lt) goto loc_821F1314;
loc_821F1380:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821F1388"))) PPC_WEAK_FUNC(sub_821F1388);
PPC_FUNC_IMPL(__imp__sub_821F1388) {
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
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82137a08
	ctx.lr = 0x821F13B0;
	sub_82137A08(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// addi r5,r30,128
	ctx.r5.s64 = r30.s64 + 128;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x821F13C0;
	sub_82137A08(ctx, base);
	// lwz r11,256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// lwz r10,260(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// stw r10,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r10.u32);
	// lbz r9,264(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 264);
	// stb r9,264(r31)
	PPC_STORE_U8(r31.u32 + 264, ctx.r9.u8);
	// lbz r8,265(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 265);
	// stb r8,265(r31)
	PPC_STORE_U8(r31.u32 + 265, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_821F13FC"))) PPC_WEAK_FUNC(sub_821F13FC);
PPC_FUNC_IMPL(__imp__sub_821F13FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1400"))) PPC_WEAK_FUNC(sub_821F1400);
PPC_FUNC_IMPL(__imp__sub_821F1400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f1424
	if (cr6.eq) goto loc_821F1424;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821f1428
	if (!cr6.eq) goto loc_821F1428;
loc_821F1424:
	// li r11,0
	r11.s64 = 0;
loc_821F1428:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F1438"))) PPC_WEAK_FUNC(sub_821F1438);
PPC_FUNC_IMPL(__imp__sub_821F1438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-12012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2256(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f145c
	if (cr6.eq) goto loc_821F145C;
	// lwz r11,2260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821f1460
	if (!cr6.eq) goto loc_821F1460;
loc_821F145C:
	// li r11,0
	r11.s64 = 0;
loc_821F1460:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f1480
	if (cr6.eq) goto loc_821F1480;
	// lwz r11,2256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// lbz r10,467(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 467);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f1484
	if (cr6.eq) goto loc_821F1484;
loc_821F1480:
	// li r11,0
	r11.s64 = 0;
loc_821F1484:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F1494"))) PPC_WEAK_FUNC(sub_821F1494);
PPC_FUNC_IMPL(__imp__sub_821F1494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1498"))) PPC_WEAK_FUNC(sub_821F1498);
PPC_FUNC_IMPL(__imp__sub_821F1498) {
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
	ctx.lr = 0x821F14A0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// lwz r11,2256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f14d0
	if (cr6.eq) goto loc_821F14D0;
	// lwz r3,460(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 460);
	// lwz r11,456(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 456);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821F14D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F14D0:
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,2216
	r29.s64 = r31.s64 + 2216;
	// mr r27,r30
	r27.u64 = r30.u64;
	// li r28,2
	r28.s64 = 2;
loc_821F14E0:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f14f8
	if (cr6.eq) goto loc_821F14F8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x821F14F4;
	sub_8213C218(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_821F14F8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x821f14e0
	if (!cr0.eq) goto loc_821F14E0;
	// lwz r11,2256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f1520
	if (cr6.eq) goto loc_821F1520;
	// lwz r3,2196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2196);
	// lwz r11,2188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2188);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821F1520;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F1520:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// stw r30,2256(r31)
	PPC_STORE_U32(r31.u32 + 2256, r30.u32);
	// stw r30,2260(r31)
	PPC_STORE_U32(r31.u32 + 2260, r30.u32);
	// stw r30,2208(r31)
	PPC_STORE_U32(r31.u32 + 2208, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,2212(r31)
	PPC_STORE_U32(r31.u32 + 2212, r30.u32);
	// beq cr6,0x821f155c
	if (cr6.eq) goto loc_821F155C;
	// lwz r3,2252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2252);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F155C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F155C:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r30,2252(r31)
	PPC_STORE_U32(r31.u32 + 2252, r30.u32);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// stw r30,2268(r31)
	PPC_STORE_U32(r31.u32 + 2268, r30.u32);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// addi r6,r10,0
	ctx.r6.s64 = ctx.r10.s64 + 0;
	// stw r8,2264(r31)
	PPC_STORE_U32(r31.u32 + 2264, ctx.r8.u32);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// stw r30,2276(r31)
	PPC_STORE_U32(r31.u32 + 2276, r30.u32);
	// addi r4,r9,0
	ctx.r4.s64 = ctx.r9.s64 + 0;
	// stw r6,2272(r31)
	PPC_STORE_U32(r31.u32 + 2272, ctx.r6.u32);
	// addi r3,r7,0
	ctx.r3.s64 = ctx.r7.s64 + 0;
	// stw r30,2284(r31)
	PPC_STORE_U32(r31.u32 + 2284, r30.u32);
	// stw r4,2280(r31)
	PPC_STORE_U32(r31.u32 + 2280, ctx.r4.u32);
	// stw r3,2288(r31)
	PPC_STORE_U32(r31.u32 + 2288, ctx.r3.u32);
	// stw r30,2292(r31)
	PPC_STORE_U32(r31.u32 + 2292, r30.u32);
	// lwz r11,-12012(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12012);
	// lwz r3,2240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2240);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f15bc
	if (cr6.eq) goto loc_821F15BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821F15BC;
	sub_821EC060(ctx, base);
loc_821F15BC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821F15C4"))) PPC_WEAK_FUNC(sub_821F15C4);
PPC_FUNC_IMPL(__imp__sub_821F15C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F15C8"))) PPC_WEAK_FUNC(sub_821F15C8);
PPC_FUNC_IMPL(__imp__sub_821F15C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,2180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2180, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,2176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2176, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,2172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2172, r11.u32);
	// b 0x821f1498
	sub_821F1498(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F15E8"))) PPC_WEAK_FUNC(sub_821F15E8);
PPC_FUNC_IMPL(__imp__sub_821F15E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// stb r11,128(r3)
	PPC_STORE_U8(ctx.r3.u32 + 128, r11.u8);
	// stw r11,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, r11.u32);
	// stw r11,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, r11.u32);
	// stb r11,264(r3)
	PPC_STORE_U8(ctx.r3.u32 + 264, r11.u8);
	// stb r11,265(r3)
	PPC_STORE_U8(ctx.r3.u32 + 265, r11.u8);
	// stb r11,268(r3)
	PPC_STORE_U8(ctx.r3.u32 + 268, r11.u8);
	// stb r11,396(r3)
	PPC_STORE_U8(ctx.r3.u32 + 396, r11.u8);
	// stw r11,524(r3)
	PPC_STORE_U32(ctx.r3.u32 + 524, r11.u32);
	// stw r11,528(r3)
	PPC_STORE_U32(ctx.r3.u32 + 528, r11.u32);
	// stb r11,532(r3)
	PPC_STORE_U8(ctx.r3.u32 + 532, r11.u8);
	// stb r11,533(r3)
	PPC_STORE_U8(ctx.r3.u32 + 533, r11.u8);
	// stb r11,536(r3)
	PPC_STORE_U8(ctx.r3.u32 + 536, r11.u8);
	// stb r11,664(r3)
	PPC_STORE_U8(ctx.r3.u32 + 664, r11.u8);
	// stw r11,792(r3)
	PPC_STORE_U32(ctx.r3.u32 + 792, r11.u32);
	// stw r11,796(r3)
	PPC_STORE_U32(ctx.r3.u32 + 796, r11.u32);
	// stb r11,800(r3)
	PPC_STORE_U8(ctx.r3.u32 + 800, r11.u8);
	// stb r11,801(r3)
	PPC_STORE_U8(ctx.r3.u32 + 801, r11.u8);
	// stb r11,804(r3)
	PPC_STORE_U8(ctx.r3.u32 + 804, r11.u8);
	// stb r11,932(r3)
	PPC_STORE_U8(ctx.r3.u32 + 932, r11.u8);
	// stw r11,1060(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1060, r11.u32);
	// stw r11,1064(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1064, r11.u32);
	// stb r11,1068(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1068, r11.u8);
	// stb r11,1069(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1069, r11.u8);
	// stb r11,1072(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1072, r11.u8);
	// stb r11,1200(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1200, r11.u8);
	// stw r11,1328(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1328, r11.u32);
	// stw r11,1332(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1332, r11.u32);
	// stb r11,1336(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1336, r11.u8);
	// stb r11,1337(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1337, r11.u8);
	// stb r11,1340(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1340, r11.u8);
	// stb r11,1468(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1468, r11.u8);
	// stw r11,1596(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1596, r11.u32);
	// stw r11,1600(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1600, r11.u32);
	// stb r11,1604(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1604, r11.u8);
	// stb r11,1605(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1605, r11.u8);
	// stb r11,1608(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1608, r11.u8);
	// stb r11,1736(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1736, r11.u8);
	// stw r11,1864(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1864, r11.u32);
	// stw r11,1868(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1868, r11.u32);
	// stb r11,1872(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1872, r11.u8);
	// stb r11,1873(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1873, r11.u8);
	// stb r11,1876(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1876, r11.u8);
	// stb r11,2004(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2004, r11.u8);
	// stw r11,2132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2132, r11.u32);
	// stw r11,2136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2136, r11.u32);
	// stb r11,2140(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2140, r11.u8);
	// stb r11,2141(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2141, r11.u8);
	// stw r11,2152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2152, r11.u32);
	// stw r11,2148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2148, r11.u32);
	// stw r11,2144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2144, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F16BC"))) PPC_WEAK_FUNC(sub_821F16BC);
PPC_FUNC_IMPL(__imp__sub_821F16BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F16C0"))) PPC_WEAK_FUNC(sub_821F16C0);
PPC_FUNC_IMPL(__imp__sub_821F16C0) {
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
	// lwz r11,2152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2152);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x821f16f8
	if (!cr6.eq) goto loc_821F16F8;
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
loc_821F16F8:
	// lwz r11,2144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2144);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,2144(r31)
	PPC_STORE_U32(r31.u32 + 2144, r11.u32);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x821f1714
	if (!cr6.eq) goto loc_821F1714;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2144(r31)
	PPC_STORE_U32(r31.u32 + 2144, r11.u32);
loc_821F1714:
	// lwz r11,2144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2144);
	// mulli r11,r11,268
	r11.s64 = r11.s64 * 268;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x821f1388
	ctx.lr = 0x821F1724;
	sub_821F1388(ctx, base);
	// lwz r11,2152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2152);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,2152(r31)
	PPC_STORE_U32(r31.u32 + 2152, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821F1748"))) PPC_WEAK_FUNC(sub_821F1748);
PPC_FUNC_IMPL(__imp__sub_821F1748) {
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
	ctx.lr = 0x821F1750;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x821f178c
	if (!cr6.gt) goto loc_821F178C;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_821F1768:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F1770;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821F1778;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,-4
	ctx.r3.s64 = r31.s64 + -4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F1780;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x821f1768
	if (!cr0.eq) goto loc_821F1768;
loc_821F178C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821F1794;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F179C"))) PPC_WEAK_FUNC(sub_821F179C);
PPC_FUNC_IMPL(__imp__sub_821F179C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F17A0"))) PPC_WEAK_FUNC(sub_821F17A0);
PPC_FUNC_IMPL(__imp__sub_821F17A0) {
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
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// stw r4,416(r31)
	PPC_STORE_U32(r31.u32 + 416, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f1848
	if (cr6.eq) goto loc_821F1848;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f1848
	if (cr6.eq) goto loc_821F1848;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821f180c
	if (cr6.eq) goto loc_821F180C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821f1810
	goto loc_821F1810;
loc_821F180C:
	// li r11,0
	r11.s64 = 0;
loc_821F1810:
	// stw r31,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r31.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821607a0
	ctx.lr = 0x821F1824;
	sub_821607A0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,428(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821F1848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F1848:
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

__attribute__((alias("__imp__sub_821F185C"))) PPC_WEAK_FUNC(sub_821F185C);
PPC_FUNC_IMPL(__imp__sub_821F185C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1860"))) PPC_WEAK_FUNC(sub_821F1860);
PPC_FUNC_IMPL(__imp__sub_821F1860) {
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
	ctx.lr = 0x821F1868;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821f1880
	if (!cr6.eq) goto loc_821F1880;
	// addi r31,r26,8
	r31.s64 = r26.s64 + 8;
loc_821F1880:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f1914
	if (cr6.eq) goto loc_821F1914;
	// addi r23,r26,8
	r23.s64 = r26.s64 + 8;
	// cmplw cr6,r31,r23
	cr6.compare<uint32_t>(r31.u32, r23.u32, xer);
	// beq cr6,0x821f18b4
	if (cr6.eq) goto loc_821F18B4;
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r10,r31,r23
	ctx.r10.s64 = r23.s64 - r31.s64;
loc_821F18A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821f18a0
	if (!cr6.eq) goto loc_821F18A0;
loc_821F18B4:
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lwz r3,-12012(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -12012);
	// lwz r11,2232(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2232);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x821f18d0
	if (!cr6.eq) goto loc_821F18D0;
	// li r11,0
	r11.s64 = 0;
loc_821F18D0:
	// addi r11,r11,277
	r11.s64 = r11.s64 + 277;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r28,r11,r3
	r28.u64 = r11.u64 + ctx.r3.u64;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f1ba8
	if (!cr6.eq) goto loc_821F1BA8;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f1ba8
	if (!cr6.eq) goto loc_821F1BA8;
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821f1920
	if (!cr6.eq) goto loc_821F1920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x821F1914;
	sub_821F1498(ctx, base);
loc_821F1914:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9234
	return;
loc_821F1920:
	// lbz r10,264(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 264);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r25,r26,264
	r25.s64 = r26.s64 + 264;
	// addi r29,r11,-26992
	r29.s64 = r11.s64 + -26992;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f1958
	if (!cr6.eq) goto loc_821F1958;
	// lwz r11,408(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 408);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x821F1958;
	sub_82137A08(ctx, base);
loc_821F1958:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8215b4d0
	ctx.lr = 0x821F1964;
	sub_8215B4D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f1bcc
	if (cr6.eq) goto loc_821F1BCC;
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r10,r31,r23
	ctx.r10.s64 = r23.s64 - r31.s64;
loc_821F1978:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821f1978
	if (!cr6.eq) goto loc_821F1978;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82145020
	ctx.lr = 0x821F1998;
	sub_82145020(ctx, base);
	// lwz r31,0(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x821f19c4
	if (!cr6.eq) goto loc_821F19C4;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// ble cr6,0x821f19c4
	if (!cr6.gt) goto loc_821F19C4;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmplw cr6,r27,r30
	cr6.compare<uint32_t>(r27.u32, r30.u32, xer);
	// ble cr6,0x821f19c4
	if (!cr6.gt) goto loc_821F19C4;
	// li r27,1
	r27.s64 = 1;
loc_821F19C4:
	// lbz r11,21(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f19d4
	if (cr6.eq) goto loc_821F19D4;
	// stw r11,424(r26)
	PPC_STORE_U32(r26.u32 + 424, r11.u32);
loc_821F19D4:
	// lwz r11,424(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 424);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f19f0
	if (cr6.eq) goto loc_821F19F0;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// mr r27,r11
	r27.u64 = r11.u64;
	// blt cr6,0x821f19f0
	if (cr6.lt) goto loc_821F19F0;
	// mr r27,r30
	r27.u64 = r30.u64;
loc_821F19F0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e8080
	ctx.lr = 0x821F19F8;
	sub_821E8080(ctx, base);
	// lwz r3,-12012(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -12012);
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f1a38
	if (cr6.eq) goto loc_821F1A38;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rotlwi r7,r9,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x821F1A2C;
	sub_82137A08(ctx, base);
	// lwz r3,-12012(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -12012);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// b 0x821f1a3c
	goto loc_821F1A3C;
loc_821F1A38:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
loc_821F1A3C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82549368
	ctx.lr = 0x821F1A48;
	sub_82549368(ctx, base);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f1bb4
	if (cr6.eq) goto loc_821F1BB4;
	// lwz r11,-12012(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -12012);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// lbz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f1a7c
	if (cr6.eq) goto loc_821F1A7C;
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x8213b860
	ctx.lr = 0x821F1A78;
	sub_8213B860(ctx, base);
	// b 0x821f1ac4
	goto loc_821F1AC4;
loc_821F1A7C:
	// lwz r11,416(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 416);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f1ac4
	if (!cr6.eq) goto loc_821F1AC4;
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821f1ab8
	if (cr6.eq) goto loc_821F1AB8;
	// lbz r11,64(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821f1abc
	goto loc_821F1ABC;
loc_821F1AB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821F1ABC:
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82148e08
	ctx.lr = 0x821F1AC4;
	sub_82148E08(ctx, base);
loc_821F1AC4:
	// lwz r11,416(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 416);
	// stw r28,428(r26)
	PPC_STORE_U32(r26.u32 + 428, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f1b38
	if (cr6.eq) goto loc_821F1B38;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821607a0
	ctx.lr = 0x821F1AE0;
	sub_821607A0(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821f1b14
	if (cr6.eq) goto loc_821F1B14;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821f1b18
	goto loc_821F1B18;
loc_821F1B14:
	// li r11,0
	r11.s64 = 0;
loc_821F1B18:
	// stw r26,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12012(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -12012);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F1B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F1B38:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r26,136
	r31.s64 = r26.s64 + 136;
	// addi r5,r11,-27000
	ctx.r5.s64 = r11.s64 + -27000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x821F1B58;
	sub_82137A08(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8215b190
	ctx.lr = 0x821F1B6C;
	sub_8215B190(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8215b438
	ctx.lr = 0x821F1B78;
	sub_8215B438(ctx, base);
	// sth r3,464(r26)
	PPC_STORE_U16(r26.u32 + 464, ctx.r3.u16);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82138240
	ctx.lr = 0x821F1B8C;
	sub_82138240(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lhz r4,464(r26)
	ctx.r4.u64 = PPC_LOAD_U16(r26.u32 + 464);
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x821382e8
	ctx.lr = 0x821F1B9C;
	sub_821382E8(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// stw r3,420(r26)
	PPC_STORE_U32(r26.u32 + 420, ctx.r3.u32);
	// stb r27,20(r10)
	PPC_STORE_U8(ctx.r10.u32 + 20, r27.u8);
loc_821F1BA8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9234
	return;
loc_821F1BB4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-27032
	ctx.r3.s64 = r11.s64 + -27032;
	// bl 0x82130000
	ctx.lr = 0x821F1BC0;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9234
	return;
loc_821F1BCC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-12384
	ctx.r10.s64 = r11.s64 + -12384;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f1bf4
	if (!cr6.eq) goto loc_821F1BF4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r3,r11,-27120
	ctx.r3.s64 = r11.s64 + -27120;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x821F1BF4;
	sub_82130000(ctx, base);
loc_821F1BF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821F1C00"))) PPC_WEAK_FUNC(sub_821F1C00);
PPC_FUNC_IMPL(__imp__sub_821F1C00) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// addi r10,r11,-26980
	ctx.r10.s64 = r11.s64 + -26980;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lbz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f1c3c
	if (cr6.eq) goto loc_821F1C3C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821F1C3C;
	sub_82130588(ctx, base);
loc_821F1C3C:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x82548b50
	ctx.lr = 0x821F1C5C;
	sub_82548B50(ctx, base);
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

__attribute__((alias("__imp__sub_821F1C74"))) PPC_WEAK_FUNC(sub_821F1C74);
PPC_FUNC_IMPL(__imp__sub_821F1C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1C78"))) PPC_WEAK_FUNC(sub_821F1C78);
PPC_FUNC_IMPL(__imp__sub_821F1C78) {
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
	ctx.lr = 0x821F1C80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,14(r31)
	PPC_STORE_U16(r31.u32 + 14, ctx.r10.u16);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// bl 0x821f0e78
	ctx.lr = 0x821F1CB4;
	sub_821F0E78(ctx, base);
	// lbz r7,22(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 22);
	// lwz r9,2200(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2200);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x821f1d0c
	if (cr6.eq) goto loc_821F1D0C;
	// lwz r11,2208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2208);
	// lwz r10,2204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2204);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r9,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, ctx.r9.u32);
	// stw r11,416(r3)
	PPC_STORE_U32(ctx.r3.u32 + 416, r11.u32);
	// stw r10,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r10.u32);
	// lwz r8,2264(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 2264);
	// stw r8,448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 448, ctx.r8.u32);
	// lwz r7,2268(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2268);
	// stw r7,452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 452, ctx.r7.u32);
	// lwz r6,2272(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2272);
	// stw r6,456(r3)
	PPC_STORE_U32(ctx.r3.u32 + 456, ctx.r6.u32);
	// lwz r5,2276(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2276);
	// stfs f1,400(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 400, temp.u32);
	// stw r5,460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 460, ctx.r5.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F1D0C:
	// lwz r11,2204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2204);
	// lwz r10,2212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2212);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r9,412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 412, ctx.r9.u32);
	// stw r11,408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 408, r11.u32);
	// stw r10,416(r3)
	PPC_STORE_U32(ctx.r3.u32 + 416, ctx.r10.u32);
	// lwz r8,2280(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 2280);
	// stw r8,448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 448, ctx.r8.u32);
	// lwz r7,2284(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2284);
	// stw r7,452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 452, ctx.r7.u32);
	// lwz r6,2288(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2288);
	// stw r6,456(r3)
	PPC_STORE_U32(ctx.r3.u32 + 456, ctx.r6.u32);
	// lwz r5,2292(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2292);
	// stfs f1,400(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 400, temp.u32);
	// stw r5,460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 460, ctx.r5.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F1D54"))) PPC_WEAK_FUNC(sub_821F1D54);
PPC_FUNC_IMPL(__imp__sub_821F1D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1D58"))) PPC_WEAK_FUNC(sub_821F1D58);
PPC_FUNC_IMPL(__imp__sub_821F1D58) {
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
	ctx.lr = 0x821F1D60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,2256(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r30,2208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2208, r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r29,2212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2212, r29.u32);
	// beq cr6,0x821f1dac
	if (cr6.eq) goto loc_821F1DAC;
loc_821F1D80:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f1d98
	if (!cr6.eq) goto loc_821F1D98;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_821F1D98:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f17a0
	ctx.lr = 0x821F1DA0;
	sub_821F17A0(ctx, base);
	// lwz r31,404(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821f1d80
	if (!cr6.eq) goto loc_821F1D80;
loc_821F1DAC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F1DB4"))) PPC_WEAK_FUNC(sub_821F1DB4);
PPC_FUNC_IMPL(__imp__sub_821F1DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1DB8"))) PPC_WEAK_FUNC(sub_821F1DB8);
PPC_FUNC_IMPL(__imp__sub_821F1DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// addi r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 + 28;
	// stw r11,2180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2180, r11.u32);
	// stw r11,2176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2176, r11.u32);
	// stw r11,2172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2172, r11.u32);
	// b 0x821f1498
	sub_821F1498(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F1DE4"))) PPC_WEAK_FUNC(sub_821F1DE4);
PPC_FUNC_IMPL(__imp__sub_821F1DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F1DE8"))) PPC_WEAK_FUNC(sub_821F1DE8);
PPC_FUNC_IMPL(__imp__sub_821F1DE8) {
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
	ctx.lr = 0x821F1DF0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821f1e30
	if (cr6.eq) goto loc_821F1E30;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11444(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x821f1e34
	goto loc_821F1E34;
loc_821F1E30:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821F1E34:
	// lwz r29,172(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821f1f38
	if (cr6.eq) goto loc_821F1F38;
	// lwz r8,416(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 416);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821f1f38
	if (cr6.eq) goto loc_821F1F38;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821f1e70
	if (cr6.eq) goto loc_821F1E70;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11444(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11444);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821f1e74
	goto loc_821F1E74;
loc_821F1E70:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821F1E74:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82148e08
	ctx.lr = 0x821F1E7C;
	sub_82148E08(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// beq cr6,0x821f1f28
	if (cr6.eq) goto loc_821F1F28;
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821f1ebc
	if (cr6.eq) goto loc_821F1EBC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821f1ec0
	goto loc_821F1EC0;
loc_821F1EBC:
	// li r11,0
	r11.s64 = 0;
loc_821F1EC0:
	// stw r7,172(r11)
	PPC_STORE_U32(r11.u32 + 172, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,416(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 416);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F1EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821f1f18
	if (cr6.eq) goto loc_821F1F18;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,200(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r29,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F1F18:
	// li r11,0
	r11.s64 = 0;
	// stw r29,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F1F28:
	// lwz r11,416(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 416);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,64
	ctx.r4.s64 = r11.s64 + 64;
	// bl 0x8213b860
	ctx.lr = 0x821F1F38;
	sub_8213B860(ctx, base);
loc_821F1F38:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F1F40"))) PPC_WEAK_FUNC(sub_821F1F40);
PPC_FUNC_IMPL(__imp__sub_821F1F40) {
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
	ctx.lr = 0x821F1F48;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// lhz r11,32(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f201c
	if (cr6.eq) goto loc_821F201C;
	// li r26,0
	r26.s64 = 0;
loc_821F1F68:
	// lwz r11,28(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// lwzx r4,r11,r26
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x823db730
	ctx.lr = 0x821F1F7C;
	sub_823DB730(ctx, base);
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f2028
	if (cr6.eq) goto loc_821F2028;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2008
	if (cr6.eq) goto loc_821F2008;
	// li r29,0
	r29.s64 = 0;
loc_821F1F98:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// lwzx r4,r11,r29
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821f1fbc
	if (cr6.eq) goto loc_821F1FBC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x821F1FB4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f2050
	if (cr6.eq) goto loc_821F2050;
loc_821F1FBC:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821f1fd8
	if (cr6.eq) goto loc_821F1FD8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x821F1FD0;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f2050
	if (cr6.eq) goto loc_821F2050;
loc_821F1FD8:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821f1ff4
	if (cr6.eq) goto loc_821F1FF4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x821F1FEC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f2050
	if (cr6.eq) goto loc_821F2050;
loc_821F1FF4:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,24
	r29.s64 = r29.s64 + 24;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x821f1f98
	if (cr6.lt) goto loc_821F1F98;
loc_821F2008:
	// lhz r11,32(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 32);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,20
	r26.s64 = r26.s64 + 20;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x821f1f68
	if (cr6.lt) goto loc_821F1F68;
loc_821F201C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_821F2028:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x82145020
	ctx.lr = 0x821F2034;
	sub_82145020(ctx, base);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_821F2050:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821F205C"))) PPC_WEAK_FUNC(sub_821F205C);
PPC_FUNC_IMPL(__imp__sub_821F205C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F2060"))) PPC_WEAK_FUNC(sub_821F2060);
PPC_FUNC_IMPL(__imp__sub_821F2060) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x821F2088;
	sub_821C9790(ctx, base);
	// lhz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f20c4
	if (cr6.eq) goto loc_821F20C4;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de288
	ctx.lr = 0x821F20B0;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f20c4
	if (cr6.eq) goto loc_821F20C4;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f20dc
	if (!cr6.eq) goto loc_821F20DC;
loc_821F20C4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-26952
	ctx.r3.s64 = r11.s64 + -26952;
	// bl 0x82130000
	ctx.lr = 0x821F20D4;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821f20e0
	goto loc_821F20E0;
loc_821F20DC:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_821F20E0:
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

__attribute__((alias("__imp__sub_821F20F8"))) PPC_WEAK_FUNC(sub_821F20F8);
PPC_FUNC_IMPL(__imp__sub_821F20F8) {
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
	// lhz r5,24(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f2140
	if (cr6.eq) goto loc_821F2140;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// bl 0x823de288
	ctx.lr = 0x821F212C;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f2140
	if (cr6.eq) goto loc_821F2140;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2164
	if (!cr6.eq) goto loc_821F2164;
loc_821F2140:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r3,r11,-26892
	ctx.r3.s64 = r11.s64 + -26892;
	// bl 0x82130000
	ctx.lr = 0x821F2150;
	sub_82130000(ctx, base);
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
loc_821F2164:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F2178"))) PPC_WEAK_FUNC(sub_821F2178);
PPC_FUNC_IMPL(__imp__sub_821F2178) {
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
	// li r9,468
	ctx.r9.s64 = 468;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// beq cr6,0x821f21c4
	if (cr6.eq) goto loc_821F21C4;
	// mulli r3,r10,468
	ctx.r3.s64 = ctx.r10.s64 * 468;
	// bl 0x82130528
	ctx.lr = 0x821F21C0;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_821F21C4:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x821F21D4;
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

__attribute__((alias("__imp__sub_821F21EC"))) PPC_WEAK_FUNC(sub_821F21EC);
PPC_FUNC_IMPL(__imp__sub_821F21EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F21F0"))) PPC_WEAK_FUNC(sub_821F21F0);
PPC_FUNC_IMPL(__imp__sub_821F21F0) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f225c
	if (cr6.eq) goto loc_821F225C;
	// lhz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f223c
	if (cr6.eq) goto loc_821F223C;
	// lis r10,-32148
	ctx.r10.s64 = -2106851328;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r10,10896
	ctx.r7.s64 = ctx.r10.s64 + 10896;
	// bl 0x823de288
	ctx.lr = 0x821F2230;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x821f2240
	if (!cr6.eq) goto loc_821F2240;
loc_821F223C:
	// li r11,0
	r11.s64 = 0;
loc_821F2240:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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
	// blr 
	return;
loc_821F225C:
	// lhz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x821f2290
	if (!cr6.gt) goto loc_821F2290;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_821F2274:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r7,r8
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, xer);
	// beq cr6,0x821f22a4
	if (cr6.eq) goto loc_821F22A4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x821f2274
	if (cr6.lt) goto loc_821F2274;
loc_821F2290:
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
loc_821F22A4:
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
}

__attribute__((alias("__imp__sub_821F22B8"))) PPC_WEAK_FUNC(sub_821F22B8);
PPC_FUNC_IMPL(__imp__sub_821F22B8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x821F22C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x821f23a8
	if (!cr6.eq) goto loc_821F23A8;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r29)
	PPC_STORE_U16(r29.u32 + 6, ctx.r4.u16);
	// bl 0x821f1238
	ctx.lr = 0x821F22E8;
	sub_821F1238(ctx, base);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f2364
	if (cr6.eq) goto loc_821F2364;
	// li r28,0
	r28.s64 = 0;
loc_821F22FC:
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r27
	r30.u64 = r11.u64 + r27.u64;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x821d2a58
	ctx.lr = 0x821F2320;
	sub_821D2A58(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F232C;
	sub_821D2A58(ctx, base);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821d2a58
	ctx.lr = 0x821F2338;
	sub_821D2A58(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,16(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// clrlwi r28,r10,16
	r28.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// lhz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r28,r8
	cr6.compare<uint32_t>(r28.u32, ctx.r8.u32, xer);
	// blt cr6,0x821f22fc
	if (cr6.lt) goto loc_821F22FC;
loc_821F2364:
	// lhz r30,4(r29)
	r30.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821f239c
	if (!cr6.gt) goto loc_821F239C;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
loc_821F2378:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F2380;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821F2388;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,-4
	ctx.r3.s64 = r31.s64 + -4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F2390;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x821f2378
	if (!cr0.eq) goto loc_821F2378;
loc_821F239C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x821F23A4;
	sub_82130588(ctx, base);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
loc_821F23A8:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821F23D0"))) PPC_WEAK_FUNC(sub_821F23D0);
PPC_FUNC_IMPL(__imp__sub_821F23D0) {
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
	// bl 0x821f1c00
	ctx.lr = 0x821F23F0;
	sub_821F1C00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2408
	if (cr6.eq) goto loc_821F2408;
	// bl 0x82130588
	ctx.lr = 0x821F2404;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F2408:
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

__attribute__((alias("__imp__sub_821F2420"))) PPC_WEAK_FUNC(sub_821F2420);
PPC_FUNC_IMPL(__imp__sub_821F2420) {
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x821f2490
	if (!cr6.eq) goto loc_821F2490;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F2464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f24b8
	if (cr6.eq) goto loc_821F24B8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f1860
	ctx.lr = 0x821F247C;
	sub_821F1860(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821F2490:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x821f24b8
	if (!cr6.eq) goto loc_821F24B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821f1860
	ctx.lr = 0x821F24A4;
	sub_821F1860(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_821F24B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F24D0"))) PPC_WEAK_FUNC(sub_821F24D0);
PPC_FUNC_IMPL(__imp__sub_821F24D0) {
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
	ctx.lr = 0x821F24D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r9,420(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x821f2518
	if (!cr6.eq) goto loc_821F2518;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-26832
	ctx.r3.s64 = r11.s64 + -26832;
	// bl 0x82130000
	ctx.lr = 0x821F24F8;
	sub_82130000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// bl 0x821f1498
	ctx.lr = 0x821F2510;
	sub_821F1498(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821F2518:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r10,2232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2232);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x821f2538
	if (!cr6.eq) goto loc_821F2538;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_821F2538:
	// addi r10,r10,277
	ctx.r10.s64 = ctx.r10.s64 + 277;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821f2570
	if (cr6.eq) goto loc_821F2570;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f2570
	if (cr6.eq) goto loc_821F2570;
	// addi r5,r31,136
	ctx.r5.s64 = r31.s64 + 136;
	// lhz r4,464(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 464);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821382e8
	ctx.lr = 0x821F2568;
	sub_821382E8(ctx, base);
	// stw r3,420(r31)
	PPC_STORE_U32(r31.u32 + 420, ctx.r3.u32);
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
loc_821F2570:
	// lwz r10,420(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x821f25ec
	if (!cr6.eq) goto loc_821F25EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-12384
	ctx.r10.s64 = r11.s64 + -12384;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2598
	if (!cr6.eq) goto loc_821F2598;
	// addi r3,r31,264
	ctx.r3.s64 = r31.s64 + 264;
	// bl 0x82130000
	ctx.lr = 0x821F2598;
	sub_82130000(ctx, base);
loc_821F2598:
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,466(r31)
	PPC_STORE_U8(r31.u32 + 466, r11.u8);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213c218
	ctx.lr = 0x821F25AC;
	sub_8213C218(ctx, base);
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f27cc
	if (cr6.eq) goto loc_821F27CC;
loc_821F25B8:
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x821f2420
	ctx.lr = 0x821F25C0;
	sub_821F2420(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f27cc
	if (!cr6.eq) goto loc_821F27CC;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,404(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r10.u32);
	// bne cr6,0x821f25b8
	if (!cr6.eq) goto loc_821F25B8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821F25EC:
	// lbz r10,467(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 467);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f2778
	if (!cr6.eq) goto loc_821F2778;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f0,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f13,400(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,392(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821f2778
	if (cr6.lt) goto loc_821F2778;
	// lbz r10,2296(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2296);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f2638
	if (cr6.eq) goto loc_821F2638;
	// stb r28,2296(r11)
	PPC_STORE_U8(r11.u32 + 2296, r28.u8);
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
loc_821F2638:
	// lwz r10,2236(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2236);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f27cc
	if (!cr6.eq) goto loc_821F27CC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f2714
	if (cr6.eq) goto loc_821F2714;
	// lwz r10,420(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x821f27cc
	if (!cr6.eq) goto loc_821F27CC;
	// stw r31,2256(r11)
	PPC_STORE_U32(r11.u32 + 2256, r31.u32);
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r10,2232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2232);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,2232(r11)
	PPC_STORE_U32(r11.u32 + 2232, ctx.r10.u32);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x821f2680
	if (!cr6.eq) goto loc_821F2680;
	// stw r28,2232(r11)
	PPC_STORE_U32(r11.u32 + 2232, r28.u32);
loc_821F2680:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213c0c0
	ctx.lr = 0x821F2694;
	sub_8213C0C0(ctx, base);
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f26cc
	if (cr6.eq) goto loc_821F26CC;
loc_821F26A0:
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x821f2420
	ctx.lr = 0x821F26A8;
	sub_821F2420(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f26cc
	if (!cr6.eq) goto loc_821F26CC;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,404(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r10.u32);
	// bne cr6,0x821f26a0
	if (!cr6.eq) goto loc_821F26A0;
loc_821F26CC:
	// lwz r3,-12012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// bl 0x821f1038
	ctx.lr = 0x821F26D4;
	sub_821F1038(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 436);
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// stb r11,466(r31)
	PPC_STORE_U8(r31.u32 + 466, r11.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F26EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,444(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 444);
	// lwz r9,440(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 440);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F26FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,452(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// lwz r8,448(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F270C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821F2714:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-12384
	ctx.r10.s64 = r11.s64 + -12384;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2730
	if (!cr6.eq) goto loc_821F2730;
	// addi r3,r31,264
	ctx.r3.s64 = r31.s64 + 264;
	// bl 0x82130000
	ctx.lr = 0x821F2730;
	sub_82130000(ctx, base);
loc_821F2730:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,466(r31)
	PPC_STORE_U8(r31.u32 + 466, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f27cc
	if (cr6.eq) goto loc_821F27CC;
loc_821F2744:
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x821f2420
	ctx.lr = 0x821F274C;
	sub_821F2420(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f27cc
	if (!cr6.eq) goto loc_821F27CC;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,404(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r10.u32);
	// bne cr6,0x821f2744
	if (!cr6.eq) goto loc_821F2744;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821F2778:
	// lbz r10,2296(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2296);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f27cc
	if (!cr6.eq) goto loc_821F27CC;
	// lwz r10,2240(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2240);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f27cc
	if (cr6.eq) goto loc_821F27CC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,400(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	f0.f64 = double(temp.f32);
	// lwz r9,34(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 34);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x821f27cc
	if (cr6.lt) goto loc_821F27CC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2296(r11)
	PPC_STORE_U8(r11.u32 + 2296, ctx.r10.u8);
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r3,2240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2240);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f27cc
	if (cr6.eq) goto loc_821F27CC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821F27CC;
	sub_821EC060(ctx, base);
loc_821F27CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F27D4"))) PPC_WEAK_FUNC(sub_821F27D4);
PPC_FUNC_IMPL(__imp__sub_821F27D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F27D8"))) PPC_WEAK_FUNC(sub_821F27D8);
PPC_FUNC_IMPL(__imp__sub_821F27D8) {
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
	ctx.lr = 0x821F27E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lbz r11,466(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 466);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-12012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -12012);
	// lwz r10,2232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2232);
	// addi r10,r10,277
	ctx.r10.s64 = ctx.r10.s64 + 277;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// bne cr6,0x821f2814
	if (!cr6.eq) goto loc_821F2814;
	// bl 0x821f24d0
	ctx.lr = 0x821F280C;
	sub_821F24D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F2814:
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lfs f13,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r9,29952
	ctx.r8.s64 = ctx.r9.s64 + 29952;
	// lfs f0,92(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,396(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821f2888
	if (!cr6.eq) goto loc_821F2888;
	// lwz r3,460(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 460);
	// addi r30,r31,456
	r30.s64 = r31.s64 + 456;
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821F284C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// stw r9,460(r31)
	PPC_STORE_U32(r31.u32 + 460, ctx.r9.u32);
	// stw r8,456(r31)
	PPC_STORE_U32(r31.u32 + 456, ctx.r8.u32);
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f2874
	if (cr6.eq) goto loc_821F2874;
	// bl 0x821f24d0
	ctx.lr = 0x821F2870;
	sub_821F24D0(ctx, base);
	// b 0x821f2888
	goto loc_821F2888;
loc_821F2874:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-12012(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12012);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x821F2888;
	sub_821F1498(ctx, base);
loc_821F2888:
	// lwz r11,420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x821f28a8
	if (!cr6.eq) goto loc_821F28A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1860
	ctx.lr = 0x821F28A0;
	sub_821F1860(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F28A8:
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f28c8
	if (cr6.eq) goto loc_821F28C8;
	// lwz r11,420(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 420);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x821f28c8
	if (!cr6.eq) goto loc_821F28C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1860
	ctx.lr = 0x821F28C8;
	sub_821F1860(ctx, base);
loc_821F28C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F28D0"))) PPC_WEAK_FUNC(sub_821F28D0);
PPC_FUNC_IMPL(__imp__sub_821F28D0) {
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
	ctx.lr = 0x821F28D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82548ac0
	ctx.lr = 0x821F28E4;
	sub_82548AC0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r10,r11,-26980
	ctx.r10.s64 = r11.s64 + -26980;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821f2178
	ctx.lr = 0x821F28FC;
	sub_821F2178(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x821f15e8
	ctx.lr = 0x821F2904;
	sub_821F15E8(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r6,r9,0
	ctx.r6.s64 = ctx.r9.s64 + 0;
	// addi r5,r8,0
	ctx.r5.s64 = ctx.r8.s64 + 0;
	// stw r30,2192(r31)
	PPC_STORE_U32(r31.u32 + 2192, r30.u32);
	// lis r4,-32237
	ctx.r4.s64 = -2112684032;
	// stw r6,2184(r31)
	PPC_STORE_U32(r31.u32 + 2184, ctx.r6.u32);
	// lis r3,-32237
	ctx.r3.s64 = -2112684032;
	// stw r30,2196(r31)
	PPC_STORE_U32(r31.u32 + 2196, r30.u32);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r30,2200(r31)
	PPC_STORE_U32(r31.u32 + 2200, r30.u32);
	// stw r30,2204(r31)
	PPC_STORE_U32(r31.u32 + 2204, r30.u32);
	// addi r10,r4,0
	ctx.r10.s64 = ctx.r4.s64 + 0;
	// stw r30,2208(r31)
	PPC_STORE_U32(r31.u32 + 2208, r30.u32);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r30,2212(r31)
	PPC_STORE_U32(r31.u32 + 2212, r30.u32);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r5,2188(r31)
	PPC_STORE_U32(r31.u32 + 2188, ctx.r5.u32);
	// addi r8,r3,0
	ctx.r8.s64 = ctx.r3.s64 + 0;
	// stw r30,2216(r31)
	PPC_STORE_U32(r31.u32 + 2216, r30.u32);
	// addi r7,r11,0
	ctx.r7.s64 = r11.s64 + 0;
	// stw r30,2220(r31)
	PPC_STORE_U32(r31.u32 + 2220, r30.u32);
	// addi r6,r9,0
	ctx.r6.s64 = ctx.r9.s64 + 0;
	// stw r30,2224(r31)
	PPC_STORE_U32(r31.u32 + 2224, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,2228(r31)
	PPC_STORE_U32(r31.u32 + 2228, r30.u32);
	// stfs f0,2244(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 2244, temp.u32);
	// stfs f0,2248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 2248, temp.u32);
	// stw r30,2232(r31)
	PPC_STORE_U32(r31.u32 + 2232, r30.u32);
	// stw r30,2236(r31)
	PPC_STORE_U32(r31.u32 + 2236, r30.u32);
	// stw r30,2240(r31)
	PPC_STORE_U32(r31.u32 + 2240, r30.u32);
	// stw r30,2252(r31)
	PPC_STORE_U32(r31.u32 + 2252, r30.u32);
	// stw r30,2256(r31)
	PPC_STORE_U32(r31.u32 + 2256, r30.u32);
	// stw r30,2260(r31)
	PPC_STORE_U32(r31.u32 + 2260, r30.u32);
	// stw r30,2268(r31)
	PPC_STORE_U32(r31.u32 + 2268, r30.u32);
	// stw r10,2264(r31)
	PPC_STORE_U32(r31.u32 + 2264, ctx.r10.u32);
	// stw r30,2276(r31)
	PPC_STORE_U32(r31.u32 + 2276, r30.u32);
	// stw r8,2272(r31)
	PPC_STORE_U32(r31.u32 + 2272, ctx.r8.u32);
	// stw r30,2284(r31)
	PPC_STORE_U32(r31.u32 + 2284, r30.u32);
	// stw r7,2280(r31)
	PPC_STORE_U32(r31.u32 + 2280, ctx.r7.u32);
	// stw r30,2292(r31)
	PPC_STORE_U32(r31.u32 + 2292, r30.u32);
	// stw r6,2288(r31)
	PPC_STORE_U32(r31.u32 + 2288, ctx.r6.u32);
	// stb r30,2296(r31)
	PPC_STORE_U8(r31.u32 + 2296, r30.u8);
	// bl 0x82548ba8
	ctx.lr = 0x821F29BC;
	sub_82548BA8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r31,2220
	r29.s64 = r31.s64 + 2220;
	// addi r28,r11,-26756
	r28.s64 = r11.s64 + -26756;
loc_821F29C8:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821F29DC;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821380e0
	ctx.lr = 0x821F29E4;
	sub_821380E0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// blt cr6,0x821f29c8
	if (cr6.lt) goto loc_821F29C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F2A04"))) PPC_WEAK_FUNC(sub_821F2A04);
PPC_FUNC_IMPL(__imp__sub_821F2A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F2A08"))) PPC_WEAK_FUNC(sub_821F2A08);
PPC_FUNC_IMPL(__imp__sub_821F2A08) {
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
	// lis r11,-32225
	r11.s64 = -2111897600;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,5120
	ctx.r4.s64 = r11.s64 + 5120;
	// addi r3,r10,-26692
	ctx.r3.s64 = ctx.r10.s64 + -26692;
	// bl 0x82554798
	ctx.lr = 0x821F2A28;
	sub_82554798(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,5176
	ctx.r4.s64 = ctx.r9.s64 + 5176;
	// addi r3,r8,-26716
	ctx.r3.s64 = ctx.r8.s64 + -26716;
	// bl 0x82554798
	ctx.lr = 0x821F2A3C;
	sub_82554798(ctx, base);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,7608
	ctx.r4.s64 = ctx.r7.s64 + 7608;
	// addi r3,r6,-26744
	ctx.r3.s64 = ctx.r6.s64 + -26744;
	// bl 0x82554798
	ctx.lr = 0x821F2A50;
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

__attribute__((alias("__imp__sub_821F2A60"))) PPC_WEAK_FUNC(sub_821F2A60);
PPC_FUNC_IMPL(__imp__sub_821F2A60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,2256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f2a7c
	if (cr6.eq) goto loc_821F2A7C;
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821f2a80
	if (!cr6.eq) goto loc_821F2A80;
loc_821F2A7C:
	// li r11,0
	r11.s64 = 0;
loc_821F2A80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2a9c
	if (cr6.eq) goto loc_821F2A9C;
	// lbz r11,467(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 467);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x821f2aa0
	if (cr6.eq) goto loc_821F2AA0;
loc_821F2A9C:
	// li r11,0
	r11.s64 = 0;
loc_821F2AA0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2ab8
	if (cr6.eq) goto loc_821F2AB8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-26520
	ctx.r3.s64 = r11.s64 + -26520;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_821F2AB8:
	// lwz r11,2260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2af8
	if (cr6.eq) goto loc_821F2AF8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f2af8
	if (cr6.eq) goto loc_821F2AF8;
	// lwz r11,420(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 420);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821f2ae4
	if (cr6.eq) goto loc_821F2AE4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-26576
	ctx.r3.s64 = r11.s64 + -26576;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_821F2AE4:
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,467(r11)
	PPC_STORE_U8(r11.u32 + 467, ctx.r10.u8);
	// lwz r3,2256(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// b 0x821f24d0
	sub_821F24D0(ctx, base);
	return;
loc_821F2AF8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-26664
	ctx.r3.s64 = r11.s64 + -26664;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F2B04"))) PPC_WEAK_FUNC(sub_821F2B04);
PPC_FUNC_IMPL(__imp__sub_821F2B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F2B08"))) PPC_WEAK_FUNC(sub_821F2B08);
PPC_FUNC_IMPL(__imp__sub_821F2B08) {
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
	// li r3,2300
	ctx.r3.s64 = 2300;
	// bl 0x82130528
	ctx.lr = 0x821F2B1C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f2b40
	if (cr6.eq) goto loc_821F2B40;
	// bl 0x821f28d0
	ctx.lr = 0x821F2B28;
	sub_821F28D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-12012(r11)
	PPC_STORE_U32(r11.u32 + -12012, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_821F2B40:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12012(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12012, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F2B5C"))) PPC_WEAK_FUNC(sub_821F2B5C);
PPC_FUNC_IMPL(__imp__sub_821F2B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F2B60"))) PPC_WEAK_FUNC(sub_821F2B60);
PPC_FUNC_IMPL(__imp__sub_821F2B60) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x821F2B68;
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// bl 0x82387a18
	ctx.lr = 0x821F2B98;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2c5c
	if (!cr6.eq) goto loc_821F2C5C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f2c5c
	if (cr6.eq) goto loc_821F2C5C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2c70
	if (cr6.eq) goto loc_821F2C70;
	// lwz r11,2260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2c70
	if (cr6.eq) goto loc_821F2C70;
	// lwz r11,2180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2180);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x821f2c4c
	if (cr6.eq) goto loc_821F2C4C;
	// li r28,0
	r28.s64 = 0;
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
	// stw r24,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r24.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// stb r28,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r28.u8);
	// stb r29,344(r1)
	PPC_STORE_U8(ctx.r1.u32 + 344, r29.u8);
	// stb r22,345(r1)
	PPC_STORE_U8(ctx.r1.u32 + 345, r22.u8);
	// beq cr6,0x821f2c04
	if (cr6.eq) goto loc_821F2C04;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821F2C04;
	sub_82137A08(ctx, base);
loc_821F2C04:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821f2c1c
	if (cr6.eq) goto loc_821F2C1C;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82137a08
	ctx.lr = 0x821F2C1C;
	sub_82137A08(ctx, base);
loc_821F2C1C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r11,-25588
	ctx.r3.s64 = r11.s64 + -25588;
	// bl 0x82130000
	ctx.lr = 0x821F2C2C;
	sub_82130000(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x821f16c0
	ctx.lr = 0x821F2C38;
	sub_821F16C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2C4C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r11,-25656
	ctx.r3.s64 = r11.s64 + -25656;
	// bl 0x82130000
	ctx.lr = 0x821F2C5C;
	sub_82130000(ctx, base);
loc_821F2C5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2C70:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2cac
	if (!cr6.eq) goto loc_821F2CAC;
	// lfs f0,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f11,2244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 2244);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// blt cr6,0x821f2c5c
	if (cr6.lt) goto loc_821F2C5C;
	// li r4,99
	ctx.r4.s64 = 99;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x821F2CA0;
	sub_82145020(ctx, base);
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// ble cr6,0x821f2c5c
	if (!cr6.gt) goto loc_821F2C5C;
loc_821F2CAC:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2cdc
	if (!cr6.eq) goto loc_821F2CDC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r11,-25700
	ctx.r3.s64 = r11.s64 + -25700;
	// bl 0x82130000
	ctx.lr = 0x821F2CC8;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2CDC:
	// lwz r11,2260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2d60
	if (cr6.eq) goto loc_821F2D60;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x821f2d1c
	if (!cr6.eq) goto loc_821F2D1C;
	// lwz r10,2256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// lbz r9,467(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 467);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f2d1c
	if (cr6.eq) goto loc_821F2D1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f2a60
	ctx.lr = 0x821F2D08;
	sub_821F2A60(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2D1C:
	// lwz r10,2252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2252);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f2e18
	if (cr6.eq) goto loc_821F2E18;
	// cmplw cr6,r10,r24
	cr6.compare<uint32_t>(ctx.r10.u32, r24.u32, xer);
	// beq cr6,0x821f2e18
	if (cr6.eq) goto loc_821F2E18;
	// lwz r11,36(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// lwz r10,36(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x821f2df4
	if (!cr6.gt) goto loc_821F2DF4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-25816
	ctx.r3.s64 = r11.s64 + -25816;
	// bl 0x82130000
	ctx.lr = 0x821F2D4C;
	sub_82130000(ctx, base);
loc_821F2D4C:
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f1498
	ctx.lr = 0x821F2D60;
	sub_821F1498(ctx, base);
loc_821F2D60:
	// lfs f0,2244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 2244);
	f0.f64 = double(temp.f32);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// stfs f0,24(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x82145020
	ctx.lr = 0x821F2D78;
	sub_82145020(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// li r28,0
	r28.s64 = 0;
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// cmpw cr6,r3,r9
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, xer);
	// bne cr6,0x821f2da8
	if (!cr6.eq) goto loc_821F2DA8;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x821f2da8
	if (!cr6.eq) goto loc_821F2DA8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_821F2DA8:
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821f10e0
	ctx.lr = 0x821F2DB4;
	sub_821F10E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r23,r11,3998
	r23.s64 = r11.s64 + 3998;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2e64
	if (cr6.eq) goto loc_821F2E64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bne cr6,0x821f2dd8
	if (!cr6.eq) goto loc_821F2DD8;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_821F2DD8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r10,-25876
	ctx.r3.s64 = ctx.r10.s64 + -25876;
	// bl 0x82130000
	ctx.lr = 0x821F2DE8;
	sub_82130000(ctx, base);
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// stw r9,2200(r31)
	PPC_STORE_U32(r31.u32 + 2200, ctx.r9.u32);
	// b 0x821f2e94
	goto loc_821F2E94;
loc_821F2DF4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r11,-25968
	ctx.r3.s64 = r11.s64 + -25968;
	// bl 0x82130000
	ctx.lr = 0x821F2E04;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2E18:
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplw cr6,r5,r7
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, xer);
	// ble cr6,0x821f2e44
	if (!cr6.gt) goto loc_821F2E44;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// rotlwi r8,r6,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// addi r3,r10,-26032
	ctx.r3.s64 = ctx.r10.s64 + -26032;
	// bl 0x82130000
	ctx.lr = 0x821F2E40;
	sub_82130000(ctx, base);
	// b 0x821f2d4c
	goto loc_821F2D4C;
loc_821F2E44:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-26120
	ctx.r3.s64 = ctx.r10.s64 + -26120;
	// bl 0x82130000
	ctx.lr = 0x821F2E50;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2E64:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821f2e94
	if (cr6.eq) goto loc_821F2E94;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2e94
	if (cr6.eq) goto loc_821F2E94;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F2E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,2200(r31)
	PPC_STORE_U32(r31.u32 + 2200, ctx.r3.u32);
loc_821F2E94:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2ecc
	if (cr6.eq) goto loc_821F2ECC;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bne cr6,0x821f2eb0
	if (!cr6.eq) goto loc_821F2EB0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
loc_821F2EB0:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r10,-26188
	ctx.r3.s64 = ctx.r10.s64 + -26188;
	// bl 0x82130000
	ctx.lr = 0x821F2EC0;
	sub_82130000(ctx, base);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stw r9,2204(r31)
	PPC_STORE_U32(r31.u32 + 2204, ctx.r9.u32);
	// b 0x821f2efc
	goto loc_821F2EFC;
loc_821F2ECC:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821f2efc
	if (cr6.eq) goto loc_821F2EFC;
	// lbz r11,0(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2efc
	if (cr6.eq) goto loc_821F2EFC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F2EF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,2204(r31)
	PPC_STORE_U32(r31.u32 + 2204, ctx.r3.u32);
loc_821F2EFC:
	// lwz r11,2200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2f2c
	if (!cr6.eq) goto loc_821F2F2C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r11,-26240
	ctx.r3.s64 = r11.s64 + -26240;
	// bl 0x82130000
	ctx.lr = 0x821F2F18;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F2F2C:
	// lfs f31,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f31.f64 = double(temp.f32);
	// stw r24,2252(r31)
	PPC_STORE_U32(r31.u32 + 2252, r24.u32);
	// stw r30,2260(r31)
	PPC_STORE_U32(r31.u32 + 2260, r30.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// mr r27,r28
	r27.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f2fc8
	if (cr6.eq) goto loc_821F2FC8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
loc_821F2F54:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add r4,r28,r11
	ctx.r4.u64 = r28.u64 + r11.u64;
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// blt cr6,0x821f2f80
	if (cr6.lt) goto loc_821F2F80;
	// bne cr6,0x821f2fb4
	if (!cr6.eq) goto loc_821F2FB4;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x823de058
	ctx.lr = 0x821F2F74;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// b 0x821f2fb4
	goto loc_821F2FB4;
loc_821F2F80:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f1c78
	ctx.lr = 0x821F2F90;
	sub_821F1C78(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821f2f9c
	if (cr6.eq) goto loc_821F2F9C;
	// stw r3,404(r29)
	PPC_STORE_U32(r29.u32 + 404, ctx.r3.u32);
loc_821F2F9C:
	// lwz r11,2256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f2fb0
	if (!cr6.eq) goto loc_821F2FB0;
	// stw r3,2256(r31)
	PPC_STORE_U32(r31.u32 + 2256, ctx.r3.u32);
loc_821F2FB0:
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
loc_821F2FB4:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,24
	r28.s64 = r28.s64 + 24;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x821f2f54
	if (cr6.lt) goto loc_821F2F54;
loc_821F2FC8:
	// lwz r11,2256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3000
	if (cr6.eq) goto loc_821F3000;
loc_821F2FD4:
	// lwz r3,2256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// bl 0x821f2420
	ctx.lr = 0x821F2FDC;
	sub_821F2420(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f3000
	if (!cr6.eq) goto loc_821F3000;
	// lwz r11,2256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// lwz r10,404(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,2256(r31)
	PPC_STORE_U32(r31.u32 + 2256, ctx.r10.u32);
	// bne cr6,0x821f2fd4
	if (!cr6.eq) goto loc_821F2FD4;
loc_821F3000:
	// lwz r11,2256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f3040
	if (!cr6.eq) goto loc_821F3040;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-26320
	ctx.r3.s64 = r11.s64 + -26320;
	// bl 0x82130000
	ctx.lr = 0x821F3018;
	sub_82130000(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f1498
	ctx.lr = 0x821F302C;
	sub_821F1498(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_821F3040:
	// lwz r10,2184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2184);
	// stw r10,440(r11)
	PPC_STORE_U32(r11.u32 + 440, ctx.r10.u32);
	// lwz r9,2256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// lwz r8,2192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// stw r8,444(r9)
	PPC_STORE_U32(ctx.r9.u32 + 444, ctx.r8.u32);
	// lwz r7,2256(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2256);
	// stb r22,467(r7)
	PPC_STORE_U8(ctx.r7.u32 + 467, r22.u8);
	// lwz r11,2204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3070
	if (cr6.eq) goto loc_821F3070;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821f3074
	goto loc_821F3074;
loc_821F3070:
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
loc_821F3074:
	// lwz r11,2200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3088
	if (cr6.eq) goto loc_821F3088;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x821f308c
	goto loc_821F308C;
loc_821F3088:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
loc_821F308C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r11,-26400
	ctx.r3.s64 = r11.s64 + -26400;
	// bl 0x82130000
	ctx.lr = 0x821F309C;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821F30B0"))) PPC_WEAK_FUNC(sub_821F30B0);
PPC_FUNC_IMPL(__imp__sub_821F30B0) {
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
	ctx.lr = 0x821F30B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// li r29,0
	r29.s64 = 0;
	// lfs f13,2244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2244);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,2256(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 2256);
	// stfs f1,2248(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 2248, temp.u32);
	// lfs f0,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,2244(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 2244, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f3128
	if (cr6.eq) goto loc_821F3128;
	// bl 0x82387a18
	ctx.lr = 0x821F30F0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3120
	if (cr6.eq) goto loc_821F3120;
	// stw r29,2180(r30)
	PPC_STORE_U32(r30.u32 + 2180, r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r29,2176(r30)
	PPC_STORE_U32(r30.u32 + 2176, r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,2172(r30)
	PPC_STORE_U32(r30.u32 + 2172, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f1498
	ctx.lr = 0x821F311C;
	sub_821F1498(ctx, base);
	// b 0x821f3128
	goto loc_821F3128;
loc_821F3120:
	// lwz r3,2256(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2256);
	// bl 0x821f27d8
	ctx.lr = 0x821F3128;
	sub_821F27D8(ctx, base);
loc_821F3128:
	// lwz r11,2256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3144
	if (cr6.eq) goto loc_821F3144;
	// lwz r11,2260(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x821f3148
	if (!cr6.eq) goto loc_821F3148;
loc_821F3144:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_821F3148:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f31e4
	if (!cr6.eq) goto loc_821F31E4;
	// lwz r11,2180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2180);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821f31e4
	if (cr6.eq) goto loc_821F31E4;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r9,2176(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 2176);
	// addi r11,r30,28
	r11.s64 = r30.s64 + 28;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r8,2180(r30)
	PPC_STORE_U32(r30.u32 + 2180, ctx.r8.u32);
	// stw r10,2176(r30)
	PPC_STORE_U32(r30.u32 + 2176, ctx.r10.u32);
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// bne cr6,0x821f3188
	if (!cr6.eq) goto loc_821F3188;
	// stw r29,2148(r11)
	PPC_STORE_U32(r11.u32 + 2148, r29.u32);
loc_821F3188:
	// lwz r10,2148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mulli r10,r10,268
	ctx.r10.s64 = ctx.r10.s64 * 268;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x821f1498
	ctx.lr = 0x821F31A8;
	sub_821F1498(ctx, base);
	// addi r7,r31,128
	ctx.r7.s64 = r31.s64 + 128;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r9,265(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lbz r8,264(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 264);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,260(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// lwz r4,256(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// bl 0x821f2b60
	ctx.lr = 0x821F31CC;
	sub_821F2B60(ctx, base);
	// stb r29,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r29.u8);
	// stb r29,128(r31)
	PPC_STORE_U8(r31.u32 + 128, r29.u8);
	// stw r29,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r29.u32);
	// stw r29,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r29.u32);
	// stb r29,264(r31)
	PPC_STORE_U8(r31.u32 + 264, r29.u8);
	// stb r29,265(r31)
	PPC_STORE_U8(r31.u32 + 265, r29.u8);
loc_821F31E4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F31EC"))) PPC_WEAK_FUNC(sub_821F31EC);
PPC_FUNC_IMPL(__imp__sub_821F31EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F31F0"))) PPC_WEAK_FUNC(sub_821F31F0);
PPC_FUNC_IMPL(__imp__sub_821F31F0) {
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
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// sth r11,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r11.u16);
	// sth r11,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r11.u16);
	// bl 0x821d2a58
	ctx.lr = 0x821F3224;
	sub_821D2A58(ctx, base);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f1138
	ctx.lr = 0x821F3238;
	sub_821F1138(ctx, base);
	// lhz r5,94(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x821f3280
	if (!cr6.eq) goto loc_821F3280;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f3258
	if (cr6.eq) goto loc_821F3258;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x821f1748
	ctx.lr = 0x821F3258;
	sub_821F1748(ctx, base);
loc_821F3258:
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3260;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3268;
	sub_821D2AA0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_821F3280:
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x821f32a8
	if (cr6.eq) goto loc_821F32A8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x821f1748
	ctx.lr = 0x821F32A8;
	sub_821F1748(ctx, base);
loc_821F32A8:
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x821d2aa0
	ctx.lr = 0x821F32B0;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x821F32B8;
	sub_821D2AA0(ctx, base);
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

__attribute__((alias("__imp__sub_821F32D0"))) PPC_WEAK_FUNC(sub_821F32D0);
PPC_FUNC_IMPL(__imp__sub_821F32D0) {
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
	ctx.lr = 0x821F32D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// bl 0x821c9790
	ctx.lr = 0x821F3304;
	sub_821C9790(ctx, base);
	// lhz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f3340
	if (cr6.eq) goto loc_821F3340;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de288
	ctx.lr = 0x821F332C;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f3340
	if (cr6.eq) goto loc_821F3340;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f335c
	if (!cr6.eq) goto loc_821F335C;
loc_821F3340:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-25544
	ctx.r3.s64 = r11.s64 + -25544;
	// bl 0x82130000
	ctx.lr = 0x821F3350;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_821F335C:
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r3,-12012(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12012);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821f2b60
	ctx.lr = 0x821F3384;
	sub_821F2B60(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821F338C"))) PPC_WEAK_FUNC(sub_821F338C);
PPC_FUNC_IMPL(__imp__sub_821F338C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F3390"))) PPC_WEAK_FUNC(sub_821F3390);
PPC_FUNC_IMPL(__imp__sub_821F3390) {
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
	ctx.lr = 0x821F3398;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r4,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r4.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lhz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f33f0
	if (cr6.eq) goto loc_821F33F0;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,172
	ctx.r3.s64 = ctx.r1.s64 + 172;
	// bl 0x823de288
	ctx.lr = 0x821F33DC;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f33f0
	if (cr6.eq) goto loc_821F33F0;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f340c
	if (!cr6.eq) goto loc_821F340C;
loc_821F33F0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r4,172(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// addi r3,r11,-25504
	ctx.r3.s64 = r11.s64 + -25504;
	// bl 0x82130000
	ctx.lr = 0x821F3400;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821F340C:
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r3,-12012(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12012);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821f2b60
	ctx.lr = 0x821F3434;
	sub_821F2B60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F343C"))) PPC_WEAK_FUNC(sub_821F343C);
PPC_FUNC_IMPL(__imp__sub_821F343C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F3440"))) PPC_WEAK_FUNC(sub_821F3440);
PPC_FUNC_IMPL(__imp__sub_821F3440) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// b 0x821f2b60
	sub_821F2B60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F3464"))) PPC_WEAK_FUNC(sub_821F3464);
PPC_FUNC_IMPL(__imp__sub_821F3464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F3468"))) PPC_WEAK_FUNC(sub_821F3468);
PPC_FUNC_IMPL(__imp__sub_821F3468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x821f2b60
	sub_821F2B60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F348C"))) PPC_WEAK_FUNC(sub_821F348C);
PPC_FUNC_IMPL(__imp__sub_821F348C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F3490"))) PPC_WEAK_FUNC(sub_821F3490);
PPC_FUNC_IMPL(__imp__sub_821F3490) {
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
	ctx.lr = 0x821F3498;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821d2a58
	ctx.lr = 0x821F34AC;
	sub_821D2A58(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F34B8;
	sub_821D2A58(ctx, base);
	// addi r28,r29,8
	r28.s64 = r29.s64 + 8;
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x821f34fc
	if (cr6.eq) goto loc_821F34FC;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x821f34f0
	if (cr6.eq) goto loc_821F34F0;
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f34f0
	if (cr6.eq) goto loc_821F34F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821f1748
	ctx.lr = 0x821F34F0;
	sub_821F1748(ctx, base);
loc_821F34F0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f12b8
	ctx.lr = 0x821F34FC;
	sub_821F12B8(ctx, base);
loc_821F34FC:
	// lbz r11,16(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r11,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F3510"))) PPC_WEAK_FUNC(sub_821F3510);
PPC_FUNC_IMPL(__imp__sub_821F3510) {
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
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x821F3534;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x821f356c
	if (!cr6.gt) goto loc_821F356C;
	// addi r11,r3,14
	r11.s64 = ctx.r3.s64 + 14;
	// li r10,0
	ctx.r10.s64 = 0;
loc_821F3544:
	// addic. r9,r11,-14
	xer.ca = r11.u32 > 13;
	ctx.r9.s64 = r11.s64 + -14;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x821f3560
	if (cr0.eq) goto loc_821F3560;
	// stw r10,-14(r11)
	PPC_STORE_U32(r11.u32 + -14, ctx.r10.u32);
	// stw r10,-10(r11)
	PPC_STORE_U32(r11.u32 + -10, ctx.r10.u32);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
loc_821F3560:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x821f3544
	if (!cr0.eq) goto loc_821F3544;
loc_821F356C:
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

__attribute__((alias("__imp__sub_821F3580"))) PPC_WEAK_FUNC(sub_821F3580);
PPC_FUNC_IMPL(__imp__sub_821F3580) {
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
	ctx.lr = 0x821F3588;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// beq cr6,0x821f3620
	if (cr6.eq) goto loc_821F3620;
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
loc_821F35A8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821d2a58
	ctx.lr = 0x821F35B4;
	sub_821D2A58(ctx, base);
	// addi r28,r31,6
	r28.s64 = r31.s64 + 6;
	// lwz r4,-4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// addi r3,r28,-10
	ctx.r3.s64 = r28.s64 + -10;
	// bl 0x821d2a58
	ctx.lr = 0x821F35C4;
	sub_821D2A58(ctx, base);
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x821f3600
	if (cr6.eq) goto loc_821F3600;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,-2(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + -2);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x821f35f4
	if (cr6.eq) goto loc_821F35F4;
	// lhz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f35f4
	if (cr6.eq) goto loc_821F35F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821f1748
	ctx.lr = 0x821F35F4;
	sub_821F1748(ctx, base);
loc_821F35F4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f12b8
	ctx.lr = 0x821F3600;
	sub_821F12B8(ctx, base);
loc_821F3600:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// addi r27,r27,20
	r27.s64 = r27.s64 + 20;
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne cr6,0x821f35a8
	if (!cr6.eq) goto loc_821F35A8;
loc_821F3620:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F3628"))) PPC_WEAK_FUNC(sub_821F3628);
PPC_FUNC_IMPL(__imp__sub_821F3628) {
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
	ctx.lr = 0x821F3630;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x821F364C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f3390
	ctx.lr = 0x821F366C;
	sub_821F3390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f368c
	if (cr6.eq) goto loc_821F368C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r3,2260(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821F368C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F3698"))) PPC_WEAK_FUNC(sub_821F3698);
PPC_FUNC_IMPL(__imp__sub_821F3698) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x821F36A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x821f3720
	if (!cr6.gt) goto loc_821F3720;
	// addi r29,r25,14
	r29.s64 = r25.s64 + 14;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
loc_821F36B8:
	// lhz r30,0(r29)
	r30.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// addi r27,r29,-14
	r27.s64 = r29.s64 + -14;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f3704
	if (cr6.eq) goto loc_821F3704;
	// lwz r28,-6(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -6);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821f36fc
	if (!cr6.gt) goto loc_821F36FC;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
loc_821F36D8:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F36E0;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821F36E8;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,-4
	ctx.r3.s64 = r31.s64 + -4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F36F0;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x821f36d8
	if (!cr0.eq) goto loc_821F36D8;
loc_821F36FC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x821F3704;
	sub_82130588(ctx, base);
loc_821F3704:
	// addi r3,r27,4
	ctx.r3.s64 = r27.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F370C;
	sub_821D2AA0(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3714;
	sub_821D2AA0(ctx, base);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// bne 0x821f36b8
	if (!cr0.eq) goto loc_821F36B8;
loc_821F3720:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x821F3728;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821F3730"))) PPC_WEAK_FUNC(sub_821F3730);
PPC_FUNC_IMPL(__imp__sub_821F3730) {
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
	ctx.lr = 0x821F3738;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x821F3754;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f20f8
	ctx.lr = 0x821F3760;
	sub_821F20F8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821f2b60
	ctx.lr = 0x821F378C;
	sub_821F2B60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f37a0
	if (!cr6.eq) goto loc_821F37A0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_821F37A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F37A8"))) PPC_WEAK_FUNC(sub_821F37A8);
PPC_FUNC_IMPL(__imp__sub_821F37A8) {
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
	ctx.lr = 0x821F37B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lhz r11,6(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x821f3890
	if (!cr6.eq) goto loc_821F3890;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r28)
	PPC_STORE_U16(r28.u32 + 6, ctx.r4.u16);
	// bl 0x821f3510
	ctx.lr = 0x821F37D8;
	sub_821F3510(ctx, base);
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f387c
	if (cr6.eq) goto loc_821F387C;
	// li r27,0
	r27.s64 = 0;
loc_821F37EC:
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r25
	r30.u64 = r11.u64 + r25.u64;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x821d2a58
	ctx.lr = 0x821F3810;
	sub_821D2A58(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F381C;
	sub_821D2A58(ctx, base);
	// addi r26,r31,8
	r26.s64 = r31.s64 + 8;
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r26
	cr6.compare<uint32_t>(r29.u32, r26.u32, xer);
	// beq cr6,0x821f3860
	if (cr6.eq) goto loc_821F3860;
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x821f3854
	if (cr6.eq) goto loc_821F3854;
	// lhz r5,6(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f3854
	if (cr6.eq) goto loc_821F3854;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821f1748
	ctx.lr = 0x821F3854;
	sub_821F1748(ctx, base);
loc_821F3854:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821f12b8
	ctx.lr = 0x821F3860;
	sub_821F12B8(ctx, base);
loc_821F3860:
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// clrlwi r27,r11,16
	r27.u64 = r11.u32 & 0xFFFF;
	// stb r10,16(r30)
	PPC_STORE_U8(r30.u32 + 16, ctx.r10.u8);
	// lhz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// blt cr6,0x821f37ec
	if (cr6.lt) goto loc_821F37EC;
loc_821F387C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lhz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821f3698
	ctx.lr = 0x821F388C;
	sub_821F3698(ctx, base);
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
loc_821F3890:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821F38B8"))) PPC_WEAK_FUNC(sub_821F38B8);
PPC_FUNC_IMPL(__imp__sub_821F38B8) {
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
	ctx.lr = 0x821F38C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x821f3924
	if (!cr6.gt) goto loc_821F3924;
	// addi r28,r26,6
	r28.s64 = r26.s64 + 6;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_821F38D8:
	// lhz r30,0(r28)
	r30.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f3918
	if (cr6.eq) goto loc_821F3918;
	// lwz r29,-6(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -6);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x821f3910
	if (!cr6.gt) goto loc_821F3910;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
loc_821F38F4:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x821F38FC;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3904;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x821f38f4
	if (!cr0.eq) goto loc_821F38F4;
loc_821F3910:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821F3918;
	sub_82130588(ctx, base);
loc_821F3918:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x821f38d8
	if (!cr0.eq) goto loc_821F38D8;
loc_821F3924:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x821F392C;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F3934"))) PPC_WEAK_FUNC(sub_821F3934);
PPC_FUNC_IMPL(__imp__sub_821F3934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F3938"))) PPC_WEAK_FUNC(sub_821F3938);
PPC_FUNC_IMPL(__imp__sub_821F3938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-25460
	ctx.r9.s64 = ctx.r10.s64 + -25460;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F3988"))) PPC_WEAK_FUNC(sub_821F3988);
PPC_FUNC_IMPL(__imp__sub_821F3988) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x821F3990;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r27,r11,30576
	r27.s64 = r11.s64 + 30576;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// addi r4,r10,-25336
	ctx.r4.s64 = ctx.r10.s64 + -25336;
	// stw r24,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821ca540
	ctx.lr = 0x821F39C4;
	sub_821CA540(ctx, base);
	// lhz r11,32(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 32);
	// addi r26,r24,28
	r26.s64 = r24.s64 + 28;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r30,28(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821f3580
	ctx.lr = 0x821F39F4;
	sub_821F3580(ctx, base);
	// subf r8,r30,r31
	ctx.r8.s64 = r31.s64 - r30.s64;
	// li r7,20
	ctx.r7.s64 = 20;
	// lhz r5,32(r24)
	ctx.r5.u64 = PPC_LOAD_U16(r24.u32 + 32);
	// lis r14,-32125
	r14.s64 = -2105344000;
	// divw r6,r8,r7
	ctx.r6.s32 = ctx.r8.s32 / ctx.r7.s32;
	// li r25,0
	r25.s64 = 0;
	// subf r4,r6,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// sth r4,32(r24)
	PPC_STORE_U16(r24.u32 + 32, ctx.r4.u16);
	// lwz r11,2828(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f3a48
	if (!cr6.eq) goto loc_821F3A48;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x821F3A28;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f3a40
	if (cr6.eq) goto loc_821F3A40;
	// bl 0x821c0580
	ctx.lr = 0x821F3A38;
	sub_821C0580(ctx, base);
	// stw r31,2828(r14)
	PPC_STORE_U32(r14.u32 + 2828, r31.u32);
	// b 0x821f3a48
	goto loc_821F3A48;
loc_821F3A40:
	// mr r11,r25
	r11.u64 = r25.u64;
	// stw r11,2828(r14)
	PPC_STORE_U32(r14.u32 + 2828, r11.u32);
loc_821F3A48:
	// bl 0x821c4210
	ctx.lr = 0x821F3A4C;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r3,2828(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x821F3A70;
	sub_821C05E8(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821f3e10
	if (cr6.eq) goto loc_821F3E10;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r21,r8,-25352
	r21.s64 = ctx.r8.s64 + -25352;
	// addi r20,r7,-25364
	r20.s64 = ctx.r7.s64 + -25364;
	// addi r19,r6,-25372
	r19.s64 = ctx.r6.s64 + -25372;
	// addi r22,r5,-25384
	r22.s64 = ctx.r5.s64 + -25384;
	// addi r17,r4,-25400
	r17.s64 = ctx.r4.s64 + -25400;
	// addi r16,r9,-25412
	r16.s64 = ctx.r9.s64 + -25412;
	// addi r23,r10,-13276
	r23.s64 = ctx.r10.s64 + -13276;
	// addi r29,r11,5276
	r29.s64 = r11.s64 + 5276;
loc_821F3AC8:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821ca6a8
	ctx.lr = 0x821F3AE4;
	sub_821CA6A8(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x821f3df4
	if (cr6.eq) goto loc_821F3DF4;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// lwz r3,2828(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 2828);
	// bl 0x821c00e8
	ctx.lr = 0x821F3AFC;
	sub_821C00E8(ctx, base);
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// lwz r11,0(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// lwz r24,28(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821f3dd8
	if (cr6.eq) goto loc_821F3DD8;
loc_821F3B10:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r27,r25
	r27.u64 = r25.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3B20;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f3dc8
	if (cr6.eq) goto loc_821F3DC8;
	// lwz r30,4(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3B38;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f3dc8
	if (cr6.eq) goto loc_821F3DC8;
	// lwz r28,4(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3B50;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f3b60
	if (cr6.eq) goto loc_821F3B60;
	// bl 0x821c6038
	ctx.lr = 0x821F3B5C;
	sub_821C6038(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_821F3B60:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x821f3b70
	if (!cr6.eq) goto loc_821F3B70;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// b 0x821f3ba8
	goto loc_821F3BA8;
loc_821F3B70:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_821F3B74:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f3b74
	if (!cr6.eq) goto loc_821F3B74;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x821F3B9C;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821F3BA8;
	sub_823DA950(ctx, base);
loc_821F3BA8:
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821f3bbc
	if (!cr6.eq) goto loc_821F3BBC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// b 0x821f3bf4
	goto loc_821F3BF4;
loc_821F3BBC:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_821F3BC0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f3bc0
	if (!cr6.eq) goto loc_821F3BC0;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x821F3BE8;
	sub_82130528(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x821F3BF4;
	sub_823DA950(ctx, base);
loc_821F3BF4:
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r25,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r25.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stb r27,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r27.u8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// sth r25,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, r25.u16);
	// sth r25,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, r25.u16);
	// bl 0x821f1138
	ctx.lr = 0x821F3C18;
	sub_821F1138(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821f3c38
	if (cr6.eq) goto loc_821F3C38;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821f3c6c
	goto loc_821F3C6C;
loc_821F3C38:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// bl 0x821f37a8
	ctx.lr = 0x821F3C48;
	sub_821F37A8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821f3490
	ctx.lr = 0x821F3C50;
	sub_821F3490(ctx, base);
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r28,r11,-20
	r28.s64 = r11.s64 + -20;
loc_821F3C6C:
	// lhz r5,126(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 126);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f3c84
	if (cr6.eq) goto loc_821F3C84;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x821f1748
	ctx.lr = 0x821F3C84;
	sub_821F1748(ctx, base);
loc_821F3C84:
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3C8C;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3C94;
	sub_821D2AA0(ctx, base);
	// lwz r31,28(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f3dc8
	if (cr6.eq) goto loc_821F3DC8;
loc_821F3CA0:
	// stfs f31,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r25.u32);
	// stfs f31,160(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stw r25,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r25.u32);
	// stw r25,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r25.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stw r25,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r25.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3CC4;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3da4
	if (cr6.eq) goto loc_821F3DA4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F3CDC;
	sub_821D2A58(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3CE8;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f3cf8
	if (cr6.eq) goto loc_821F3CF8;
	// bl 0x821c60f8
	ctx.lr = 0x821F3CF4;
	sub_821C60F8(ctx, base);
	// stfs f1,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
loc_821F3CF8:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3D04;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f3d14
	if (cr6.eq) goto loc_821F3D14;
	// bl 0x821c60f8
	ctx.lr = 0x821F3D10;
	sub_821C60F8(ctx, base);
	// stfs f1,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
loc_821F3D14:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3D20;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3d38
	if (cr6.eq) goto loc_821F3D38;
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F3D38;
	sub_821D2A58(ctx, base);
loc_821F3D38:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F3D44;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3d5c
	if (cr6.eq) goto loc_821F3D5C;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F3D5C;
	sub_821D2A58(ctx, base);
loc_821F3D5C:
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r28,8
	ctx.r3.s64 = r28.s64 + 8;
	// bl 0x821f22b8
	ctx.lr = 0x821F3D68;
	sub_821F22B8(ctx, base);
	// lwz r4,144(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821d2a58
	ctx.lr = 0x821F3D74;
	sub_821D2A58(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,148(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x821d2a58
	ctx.lr = 0x821F3D80;
	sub_821D2A58(ctx, base);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// bl 0x821d2a58
	ctx.lr = 0x821F3D8C;
	sub_821D2A58(ctx, base);
	// lfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// lfs f13,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,16(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// lwz r11,164(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
loc_821F3DA4:
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3DAC;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,148
	ctx.r3.s64 = ctx.r1.s64 + 148;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3DB4;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821d2aa0
	ctx.lr = 0x821F3DBC;
	sub_821D2AA0(ctx, base);
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821f3ca0
	if (!cr6.eq) goto loc_821F3CA0;
loc_821F3DC8:
	// lwz r24,24(r24)
	r24.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x821f3b10
	if (!cr6.eq) goto loc_821F3B10;
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_821F3DD8:
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x821c5c70
	ctx.lr = 0x821F3DE0;
	sub_821C5C70(ctx, base);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x82130588
	ctx.lr = 0x821F3DE8;
	sub_82130588(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821be610
	ctx.lr = 0x821F3DF0;
	sub_821BE610(ctx, base);
	// lwz r24,356(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
loc_821F3DF4:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne 0x821f3ac8
	if (!cr0.eq) goto loc_821F3AC8;
loc_821F3E10:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821F3E18;
	sub_821C9A90(ctx, base);
	// lhz r11,32(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 32);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f3e7c
	if (cr6.eq) goto loc_821F3E7C;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
loc_821F3E2C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// lhz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f3e68
	if (cr6.eq) goto loc_821F3E68;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
loc_821F3E48:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// lhz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x821f3e48
	if (cr6.lt) goto loc_821F3E48;
loc_821F3E68:
	// lhz r11,32(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 32);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,20
	ctx.r7.s64 = ctx.r7.s64 + 20;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x821f3e2c
	if (cr6.lt) goto loc_821F3E2C;
loc_821F3E7C:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_821F3E88"))) PPC_WEAK_FUNC(sub_821F3E88);
PPC_FUNC_IMPL(__imp__sub_821F3E88) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x821F3E90;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// stw r22,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, r22.u32);
	// addi r4,r10,-25336
	ctx.r4.s64 = ctx.r10.s64 + -25336;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r23,916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 916, r23.u32);
	// bl 0x821ca540
	ctx.lr = 0x821F3ECC;
	sub_821CA540(ctx, base);
	// lis r27,-32125
	r27.s64 = -2105344000;
	// li r15,0
	r15.s64 = 0;
	// lwz r11,2828(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f3f08
	if (!cr6.eq) goto loc_821F3F08;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x821F3EE8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f3f00
	if (cr6.eq) goto loc_821F3F00;
	// bl 0x821c0580
	ctx.lr = 0x821F3EF8;
	sub_821C0580(ctx, base);
	// stw r31,2828(r27)
	PPC_STORE_U32(r27.u32 + 2828, r31.u32);
	// b 0x821f3f08
	goto loc_821F3F08;
loc_821F3F00:
	// mr r11,r15
	r11.u64 = r15.u64;
	// stw r11,2828(r27)
	PPC_STORE_U32(r27.u32 + 2828, r11.u32);
loc_821F3F08:
	// bl 0x821c4210
	ctx.lr = 0x821F3F0C;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,2828(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 2828);
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
	ctx.lr = 0x821F3F30;
	sub_821C05E8(ctx, base);
	// lis r9,16383
	ctx.r9.s64 = 1073676288;
	// li r30,-1
	r30.s64 = -1;
	// ori r31,r9,65535
	r31.u64 = ctx.r9.u64 | 65535;
	// rlwinm r3,r23,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r23,r31
	cr6.compare<uint32_t>(r23.u32, r31.u32, xer);
	// ble cr6,0x821f3f4c
	if (!cr6.gt) goto loc_821F3F4C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821F3F4C:
	// bl 0x82130528
	ctx.lr = 0x821F3F50;
	sub_82130528(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// rlwinm r3,r23,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x821f3f6c
	if (!cr6.gt) goto loc_821F3F6C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821F3F6C:
	// bl 0x82130528
	ctx.lr = 0x821F3F70;
	sub_82130528(ctx, base);
	// rlwinm r30,r23,2,0,29
	r30.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x821F3F8C;
	sub_823D9890(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823d9890
	ctx.lr = 0x821F3F9C;
	sub_823D9890(ctx, base);
	// mr r30,r15
	r30.u64 = r15.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x821f401c
	if (cr6.eq) goto loc_821F401C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// subf r28,r31,r29
	r28.s64 = r29.s64 - r31.s64;
	// subf r29,r31,r26
	r29.s64 = r26.s64 - r31.s64;
	// mr r26,r23
	r26.u64 = r23.u64;
	// addi r25,r11,5276
	r25.s64 = r11.s64 + 5276;
loc_821F3FBC:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwzx r4,r28,r31
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x821F3FD4;
	sub_821CA6A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821f4010
	if (cr6.eq) goto loc_821F4010;
	// lwz r3,2828(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 2828);
	// bl 0x821c00e8
	ctx.lr = 0x821F3FEC;
	sub_821C00E8(ctx, base);
	// stwx r3,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4010
	if (cr6.eq) goto loc_821F4010;
loc_821F4000:
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f4000
	if (!cr6.eq) goto loc_821F4000;
loc_821F4010:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x821f3fbc
	if (!cr0.eq) goto loc_821F3FBC;
loc_821F401C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821F4024;
	sub_821C9A90(ctx, base);
	// addi r31,r22,16
	r31.s64 = r22.s64 + 16;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x821F4034;
	sub_82130588(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r15,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r15.u32);
	// sth r15,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r15.u16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r15,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r15.u16);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// beq cr6,0x821f405c
	if (cr6.eq) goto loc_821F405C;
	// rlwinm r3,r30,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x821F4058;
	sub_82130528(ctx, base);
	// b 0x821f4060
	goto loc_821F4060;
loc_821F405C:
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
loc_821F4060:
	// stw r3,20(r22)
	PPC_STORE_U32(r22.u32 + 20, ctx.r3.u32);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// stw r15,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r15.u32);
	// sth r30,26(r22)
	PPC_STORE_U16(r22.u32 + 26, r30.u16);
	// beq cr6,0x821f4924
	if (cr6.eq) goto loc_821F4924;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r24,-32254
	r24.s64 = -2113798144;
	// lis r23,-32254
	r23.s64 = -2113798144;
	// lfs f29,-31068(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31068);
	f29.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f30,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	f30.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lis r22,-32254
	r22.s64 = -2113798144;
	// addi r26,r23,-25112
	r26.s64 = r23.s64 + -25112;
	// addi r30,r24,-25100
	r30.s64 = r24.s64 + -25100;
	// lwz r24,900(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 900);
	// lis r18,-32254
	r18.s64 = -2113798144;
	// stw r26,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r26.u32);
	// addi r11,r11,2256
	r11.s64 = r11.s64 + 2256;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// addi r10,r10,7744
	ctx.r10.s64 = ctx.r10.s64 + 7744;
	// addi r9,r9,-25124
	ctx.r9.s64 = ctx.r9.s64 + -25124;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// addi r8,r8,-25140
	ctx.r8.s64 = ctx.r8.s64 + -25140;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// addi r7,r7,-25156
	ctx.r7.s64 = ctx.r7.s64 + -25156;
	// stw r9,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// addi r6,r6,-25160
	ctx.r6.s64 = ctx.r6.s64 + -25160;
	// stw r8,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// addi r5,r5,-25172
	ctx.r5.s64 = ctx.r5.s64 + -25172;
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// addi r4,r4,-25180
	ctx.r4.s64 = ctx.r4.s64 + -25180;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// lis r21,-32254
	r21.s64 = -2113798144;
	// stw r5,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r5.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r4,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r4.u32);
	// lis r31,-32254
	r31.s64 = -2113798144;
	// lis r29,-32254
	r29.s64 = -2113798144;
	// lis r28,-32254
	r28.s64 = -2113798144;
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lis r25,-32256
	r25.s64 = -2113929216;
	// lis r20,-32254
	r20.s64 = -2113798144;
	// lis r19,-32254
	r19.s64 = -2113798144;
	// addi r23,r22,-25196
	r23.s64 = r22.s64 + -25196;
	// addi r22,r18,-25208
	r22.s64 = r18.s64 + -25208;
	// addi r6,r21,-25220
	ctx.r6.s64 = r21.s64 + -25220;
	// stw r23,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r23.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stw r22,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r22.u32);
	// lis r26,-32125
	r26.s64 = -2105344000;
	// lwz r21,144(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lis r17,-32255
	r17.s64 = -2113863680;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// lis r16,-32255
	r16.s64 = -2113863680;
	// addi r3,r3,10380
	ctx.r3.s64 = ctx.r3.s64 + 10380;
	// addi r11,r31,-25232
	r11.s64 = r31.s64 + -25232;
	// addi r10,r29,-25240
	ctx.r10.s64 = r29.s64 + -25240;
	// stw r3,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// addi r9,r28,-25256
	ctx.r9.s64 = r28.s64 + -25256;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// addi r8,r27,-25288
	ctx.r8.s64 = r27.s64 + -25288;
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
	// addi r7,r25,17404
	ctx.r7.s64 = r25.s64 + 17404;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// addi r5,r20,-25300
	ctx.r5.s64 = r20.s64 + -25300;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// addi r4,r19,-25308
	ctx.r4.s64 = r19.s64 + -25308;
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// addi r14,r30,-25320
	r14.s64 = r30.s64 + -25320;
	// stw r5,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r5.u32);
	// addi r26,r26,19856
	r26.s64 = r26.s64 + 19856;
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// addi r17,r17,-10160
	r17.s64 = r17.s64 + -10160;
	// addi r23,r16,-13276
	r23.s64 = r16.s64 + -13276;
	// li r22,2
	r22.s64 = 2;
	// li r18,1
	r18.s64 = 1;
	// lwz r16,180(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// rotlwi r19,r3,0
	r19.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r20,120(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
loc_821F41C4:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4908
	if (cr6.eq) goto loc_821F4908;
	// stw r15,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r15.u32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r25,28(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x821f4908
	if (cr6.eq) goto loc_821F4908;
loc_821F41F0:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F41FC;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f48fc
	if (cr6.eq) goto loc_821F48FC;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
loc_821F420C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x821f420c
	if (!cr6.eq) goto loc_821F420C;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x823de4d8
	ctx.lr = 0x821F422C;
	sub_823DE4D8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x821c9790
	ctx.lr = 0x821F4238;
	sub_821C9790(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821f21f0
	ctx.lr = 0x821F4248;
	sub_821F21F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f48fc
	if (!cr6.eq) goto loc_821F48FC;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x821F425C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f42c4
	if (cr6.eq) goto loc_821F42C4;
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r15,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r15.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// sth r15,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r15.u16);
	// sth r15,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r15.u16);
	// li r7,100
	ctx.r7.s64 = 100;
	// stw r15,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r15.u32);
	// stfs f31,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f30,20(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stfs f29,24(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// stw r15,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r15.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r15,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r15.u32);
	// stw r15,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r15.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r7.u32);
	// stw r15,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r15.u32);
	// stb r15,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r15.u8);
	// b 0x821f42c8
	goto loc_821F42C8;
loc_821F42C4:
	// mr r27,r15
	r27.u64 = r15.u64;
loc_821F42C8:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stb r15,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r15.u8);
	// bl 0x824787b0
	ctx.lr = 0x821F42DC;
	sub_824787B0(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r4,r1,448
	ctx.r4.s64 = ctx.r1.s64 + 448;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r27,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r27.u32);
	// bl 0x821d2a58
	ctx.lr = 0x821F42F8;
	sub_821D2A58(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F4304;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f4314
	if (cr6.eq) goto loc_821F4314;
	// bl 0x821c6090
	ctx.lr = 0x821F4310;
	sub_821C6090(ctx, base);
	// stw r3,12(r27)
	PPC_STORE_U32(r27.u32 + 12, ctx.r3.u32);
loc_821F4314:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,188(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// bl 0x821c75d0
	ctx.lr = 0x821F4320;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f4350
	if (cr6.eq) goto loc_821F4350;
	// bl 0x821c6090
	ctx.lr = 0x821F432C;
	sub_821C6090(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x821f4340
	if (!cr6.lt) goto loc_821F4340;
	// mr r11,r15
	r11.u64 = r15.u64;
	// b 0x821f434c
	goto loc_821F434C;
loc_821F4340:
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// ble cr6,0x821f434c
	if (!cr6.gt) goto loc_821F434C;
	// li r11,100
	r11.s64 = 100;
loc_821F434C:
	// stw r11,64(r27)
	PPC_STORE_U32(r27.u32 + 64, r11.u32);
loc_821F4350:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x821c75d0
	ctx.lr = 0x821F435C;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f436c
	if (cr6.eq) goto loc_821F436C;
	// bl 0x821c60f8
	ctx.lr = 0x821F4368;
	sub_821C60F8(ctx, base);
	// stfs f1,16(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r27.u32 + 16, temp.u32);
loc_821F436C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,168(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x821c75d0
	ctx.lr = 0x821F4378;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f4388
	if (cr6.eq) goto loc_821F4388;
	// bl 0x821c60f8
	ctx.lr = 0x821F4384;
	sub_821C60F8(ctx, base);
	// stfs f1,20(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r27.u32 + 20, temp.u32);
loc_821F4388:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x821c75d0
	ctx.lr = 0x821F4394;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f43bc
	if (cr6.eq) goto loc_821F43BC;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F43B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r27)
	PPC_STORE_U32(r27.u32 + 32, ctx.r3.u32);
loc_821F43BC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,184(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// bl 0x821c75d0
	ctx.lr = 0x821F43C8;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f43f0
	if (cr6.eq) goto loc_821F43F0;
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F43EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,36(r27)
	PPC_STORE_U32(r27.u32 + 36, ctx.r3.u32);
loc_821F43F0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// bl 0x821c75d0
	ctx.lr = 0x821F43FC;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f441c
	if (cr6.eq) goto loc_821F441C;
	// bl 0x821c6038
	ctx.lr = 0x821F4408;
	sub_821C6038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,68(r27)
	PPC_STORE_U32(r27.u32 + 68, ctx.r8.u32);
loc_821F441C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,176(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// bl 0x821c75d0
	ctx.lr = 0x821F4428;
	sub_821C75D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f4450
	if (cr6.eq) goto loc_821F4450;
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x823db730
	ctx.lr = 0x821F4440;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f4460
	if (cr6.eq) goto loc_821F4460;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// b 0x821f4454
	goto loc_821F4454;
loc_821F4450:
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_821F4454:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82144a20
	ctx.lr = 0x821F445C;
	sub_82144A20(ctx, base);
	// stw r3,40(r27)
	PPC_STORE_U32(r27.u32 + 40, ctx.r3.u32);
loc_821F4460:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x821c75d0
	ctx.lr = 0x821F446C;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f45c8
	if (cr6.eq) goto loc_821F45C8;
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82137a08
	ctx.lr = 0x821F4484;
	sub_82137A08(ctx, base);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r30,r1,192
	r30.s64 = ctx.r1.s64 + 192;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821F4490:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f4490
	if (!cr6.eq) goto loc_821F4490;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bge cr6,0x821f44ec
	if (!cr6.lt) goto loc_821F44EC;
loc_821F44C0:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bne cr6,0x821f44e0
	if (!cr6.eq) goto loc_821F44E0;
	// subf r5,r30,r31
	ctx.r5.s64 = r31.s64 - r30.s64;
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x821F44DC;
	sub_823DA950(ctx, base);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_821F44E0:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// blt cr6,0x821f44c0
	if (cr6.lt) goto loc_821F44C0;
loc_821F44EC:
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_821F44F4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f44f4
	if (!cr6.eq) goto loc_821F44F4;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stb r18,72(r27)
	PPC_STORE_U8(r27.u32 + 72, r18.u8);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r30,r22
	r30.u64 = r22.u64;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r29,r27,56
	r29.s64 = r27.s64 + 56;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r31,r11,-1
	r31.s64 = r11.s64 + -1;
loc_821F4528:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,44
	cr6.compare<int32_t>(r11.s32, 44, xer);
	// beq cr6,0x821f4558
	if (cr6.eq) goto loc_821F4558;
	// cmpwi cr6,r11,46
	cr6.compare<int32_t>(r11.s32, 46, xer);
	// beq cr6,0x821f4558
	if (cr6.eq) goto loc_821F4558;
	// cmpwi cr6,r11,45
	cr6.compare<int32_t>(r11.s32, 45, xer);
	// beq cr6,0x821f4558
	if (cr6.eq) goto loc_821F4558;
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// bge cr6,0x821f4558
	if (!cr6.lt) goto loc_821F4558;
	// cmpwi cr6,r11,57
	cr6.compare<int32_t>(r11.s32, 57, xer);
	// bgt cr6,0x821f4594
	if (cr6.gt) goto loc_821F4594;
loc_821F4558:
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// beq cr6,0x821f459c
	if (cr6.eq) goto loc_821F459C;
	// cmpwi cr6,r11,44
	cr6.compare<int32_t>(r11.s32, 44, xer);
	// bne cr6,0x821f4588
	if (!cr6.eq) goto loc_821F4588;
	// addi r3,r31,1
	ctx.r3.s64 = r31.s64 + 1;
	// bl 0x823de058
	ctx.lr = 0x821F4574;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// stb r15,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r15.u8);
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
loc_821F4588:
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x821f4528
	if (!cr6.lt) goto loc_821F4528;
loc_821F4594:
	// stb r15,72(r27)
	PPC_STORE_U8(r27.u32 + 72, r15.u8);
	// b 0x821f45bc
	goto loc_821F45BC;
loc_821F459C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823de058
	ctx.lr = 0x821F45A4;
	sub_823DE058(ctx, base);
	// addi r11,r30,12
	r11.s64 = r30.s64 + 12;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r10,r27
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, temp.u32);
	// stb r15,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r15.u8);
loc_821F45BC:
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x821f45c8
	if (cr6.eq) goto loc_821F45C8;
	// stb r15,72(r27)
	PPC_STORE_U8(r27.u32 + 72, r15.u8);
loc_821F45C8:
	// lwz r11,28(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// mr r31,r15
	r31.u64 = r15.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4630
	if (cr6.eq) goto loc_821F4630;
loc_821F45D8:
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f45d8
	if (!cr6.eq) goto loc_821F45D8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f4630
	if (cr6.eq) goto loc_821F4630;
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x821F45F8;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x821f4628
	if (!cr6.gt) goto loc_821F4628;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_821F4608:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f461c
	if (cr6.eq) goto loc_821F461C;
	// stw r15,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r15.u32);
	// sth r15,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r15.u16);
	// sth r15,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r15.u16);
loc_821F461C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x821f4608
	if (!cr0.eq) goto loc_821F4608;
loc_821F4628:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x821f4634
	goto loc_821F4634;
loc_821F4630:
	// mr r11,r15
	r11.u64 = r15.u64;
loc_821F4634:
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// sth r31,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r31.u16);
	// lwz r28,28(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821f48fc
	if (cr6.eq) goto loc_821F48FC;
loc_821F4648:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
loc_821F4650:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821f4674
	if (cr6.eq) goto loc_821F4674;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f4650
	if (cr6.eq) goto loc_821F4650;
loc_821F4674:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821f48f0
	if (!cr6.eq) goto loc_821F48F0;
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// mr r30,r15
	r30.u64 = r15.u64;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// sth r9,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r9.u16);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,28(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f46cc
	if (cr6.eq) goto loc_821F46CC;
loc_821F46A4:
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f46a4
	if (!cr6.eq) goto loc_821F46A4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f46cc
	if (cr6.eq) goto loc_821F46CC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f11b0
	ctx.lr = 0x821F46C8;
	sub_821F11B0(ctx, base);
	// b 0x821f46d0
	goto loc_821F46D0;
loc_821F46CC:
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
loc_821F46D0:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// lwz r29,28(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821f48f0
	if (cr6.eq) goto loc_821F48F0;
loc_821F46E4:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x821F4710;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f476c
	if (cr6.eq) goto loc_821F476C;
	// lwz r4,148(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x821F4724;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f476c
	if (cr6.eq) goto loc_821F476C;
	// lwz r4,156(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x821F4738;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821f484c
	if (!cr6.eq) goto loc_821F484C;
	// stw r22,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r22.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F4750;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f484c
	if (cr6.eq) goto loc_821F484C;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F4768;
	sub_821D2A58(ctx, base);
	// b 0x821f48e4
	goto loc_821F48E4;
loc_821F476C:
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x821F4778;
	sub_823DB730(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// bl 0x821c75d0
	ctx.lr = 0x821F4794;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f484c
	if (cr6.eq) goto loc_821F484C;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F47AC;
	sub_821D2A58(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F47B8;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f47dc
	if (cr6.eq) goto loc_821F47DC;
	// lwz r4,164(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x823db730
	ctx.lr = 0x821F47CC;
	sub_823DB730(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r10,22(r30)
	PPC_STORE_U8(r30.u32 + 22, ctx.r10.u8);
	// b 0x821f47e0
	goto loc_821F47E0;
loc_821F47DC:
	// stb r18,22(r30)
	PPC_STORE_U8(r30.u32 + 22, r18.u8);
loc_821F47E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,172(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// bl 0x821c75d0
	ctx.lr = 0x821F47EC;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f484c
	if (cr6.eq) goto loc_821F484C;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_821F4800:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821f4824
	if (cr6.eq) goto loc_821F4824;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f4800
	if (cr6.eq) goto loc_821F4800;
loc_821F4824:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f487c
	if (cr6.eq) goto loc_821F487C;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F4840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821f487c
	if (!cr6.eq) goto loc_821F487C;
loc_821F484C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// addi r30,r11,-1
	r30.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f48e0
	if (!cr6.eq) goto loc_821F48E0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x821f48d8
	if (cr6.eq) goto loc_821F48D8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f11b0
	ctx.lr = 0x821F4878;
	sub_821F11B0(ctx, base);
	// b 0x821f48dc
	goto loc_821F48DC;
loc_821F487C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x821c75d0
	ctx.lr = 0x821F4888;
	sub_821C75D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f48a0
	if (cr6.eq) goto loc_821F48A0;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x821F48A0;
	sub_821D2A58(ctx, base);
loc_821F48A0:
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c75d0
	ctx.lr = 0x821F48AC;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f48bc
	if (cr6.eq) goto loc_821F48BC;
	// bl 0x821c6090
	ctx.lr = 0x821F48B8;
	sub_821C6090(ctx, base);
	// stb r3,21(r30)
	PPC_STORE_U8(r30.u32 + 21, ctx.r3.u8);
loc_821F48BC:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F48D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x821f48e4
	goto loc_821F48E4;
loc_821F48D8:
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
loc_821F48DC:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_821F48E0:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
loc_821F48E4:
	// lwz r29,24(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x821f46e4
	if (!cr6.eq) goto loc_821F46E4;
loc_821F48F0:
	// lwz r28,24(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x821f4648
	if (!cr6.eq) goto loc_821F4648;
loc_821F48FC:
	// lwz r25,24(r25)
	r25.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x821f41f0
	if (!cr6.eq) goto loc_821F41F0;
loc_821F4908:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,916(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 916);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821f41c4
	if (cr6.lt) goto loc_821F41C4;
	// b 0x821f4928
	goto loc_821F4928;
loc_821F4924:
	// li r18,1
	r18.s64 = 1;
loc_821F4928:
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f495c
	if (!cr6.eq) goto loc_821F495C;
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821f4958
	if (cr6.eq) goto loc_821F4958;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r6,r11,10896
	ctx.r6.s64 = r11.s64 + 10896;
	// bl 0x823dcf08
	ctx.lr = 0x821F4958;
	sub_823DCF08(ctx, base);
loc_821F4958:
	// stb r18,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r18.u8);
loc_821F495C:
	// lwz r29,916(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 916);
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821f49b0
	if (cr6.eq) goto loc_821F49B0;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r31,r27
	r31.u64 = r27.u64;
	// subf r28,r27,r11
	r28.s64 = r11.s64 - r27.s64;
loc_821F4978:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f4988
	if (cr6.eq) goto loc_821F4988;
	// bl 0x821be610
	ctx.lr = 0x821F4988;
	sub_821BE610(ctx, base);
loc_821F4988:
	// lwzx r30,r28,r31
	r30.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f49a4
	if (cr6.eq) goto loc_821F49A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c5c70
	ctx.lr = 0x821F499C;
	sub_821C5C70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x821F49A4;
	sub_82130588(ctx, base);
loc_821F49A4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x821f4978
	if (!cr0.eq) goto loc_821F4978;
loc_821F49B0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x821F49B8;
	sub_82130588(ctx, base);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x821F49C0;
	sub_82130588(ctx, base);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_821F49D4"))) PPC_WEAK_FUNC(sub_821F49D4);
PPC_FUNC_IMPL(__imp__sub_821F49D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F49D8"))) PPC_WEAK_FUNC(sub_821F49D8);
PPC_FUNC_IMPL(__imp__sub_821F49D8) {
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
	ctx.lr = 0x821F49E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r28,16
	r11.s64 = r28.s64 + 16;
	// addi r9,r10,-25460
	ctx.r9.s64 = ctx.r10.s64 + -25460;
	// li r30,0
	r30.s64 = 0;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// mr r29,r11
	r29.u64 = r11.u64;
	// lhz r8,24(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821f4a10
	if (!cr6.eq) goto loc_821F4A10;
loc_821F4A0C:
	// li r29,0
	r29.s64 = 0;
loc_821F4A10:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x821f4a24
	if (!cr6.eq) goto loc_821F4A24;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x821f4a28
	if (cr6.eq) goto loc_821F4A28;
loc_821F4A24:
	// li r11,1
	r11.s64 = 1;
loc_821F4A28:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4a8c
	if (cr6.eq) goto loc_821F4A8C;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f4a74
	if (cr6.eq) goto loc_821F4A74;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821d2aa0
	ctx.lr = 0x821F4A54;
	sub_821D2AA0(ctx, base);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f4a6c
	if (cr6.eq) goto loc_821F4A6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821f38b8
	ctx.lr = 0x821F4A6C;
	sub_821F38B8(ctx, base);
loc_821F4A6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x821F4A74;
	sub_82130588(ctx, base);
loc_821F4A74:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x821f4a10
	if (cr6.lt) goto loc_821F4A10;
	// li r30,0
	r30.s64 = 0;
	// b 0x821f4a0c
	goto loc_821F4A0C;
loc_821F4A8C:
	// lhz r5,34(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 34);
	// addi r3,r28,28
	ctx.r3.s64 = r28.s64 + 28;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x821f4aa4
	if (cr6.eq) goto loc_821F4AA4;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x821f3698
	ctx.lr = 0x821F4AA4;
	sub_821F3698(ctx, base);
loc_821F4AA4:
	// lhz r11,26(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4ab8
	if (cr6.eq) goto loc_821F4AB8;
	// lwz r3,20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x821F4AB8;
	sub_82130588(ctx, base);
loc_821F4AB8:
	// lhz r11,14(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4acc
	if (cr6.eq) goto loc_821F4ACC;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x821F4ACC;
	sub_82130588(ctx, base);
loc_821F4ACC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821F4AD4"))) PPC_WEAK_FUNC(sub_821F4AD4);
PPC_FUNC_IMPL(__imp__sub_821F4AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F4AD8"))) PPC_WEAK_FUNC(sub_821F4AD8);
PPC_FUNC_IMPL(__imp__sub_821F4AD8) {
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
	// bl 0x821f49d8
	ctx.lr = 0x821F4AF8;
	sub_821F49D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4b10
	if (cr6.eq) goto loc_821F4B10;
	// bl 0x82130588
	ctx.lr = 0x821F4B0C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F4B10:
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

__attribute__((alias("__imp__sub_821F4B28"))) PPC_WEAK_FUNC(sub_821F4B28);
PPC_FUNC_IMPL(__imp__sub_821F4B28) {
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
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x821F4B48;
	sub_82144A18(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821f4b80
	if (cr6.lt) goto loc_821F4B80;
	// bne cr6,0x821f4b88
	if (!cr6.eq) goto loc_821F4B88;
	// li r11,5
	r11.s64 = 5;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// bl 0x8213c020
	ctx.lr = 0x821F4B6C;
	sub_8213C020(ctx, base);
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
loc_821F4B80:
	// li r11,1
	r11.s64 = 1;
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
loc_821F4B88:
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

__attribute__((alias("__imp__sub_821F4B9C"))) PPC_WEAK_FUNC(sub_821F4B9C);
PPC_FUNC_IMPL(__imp__sub_821F4B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F4BA0"))) PPC_WEAK_FUNC(sub_821F4BA0);
PPC_FUNC_IMPL(__imp__sub_821F4BA0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f4be4
	if (!cr6.eq) goto loc_821F4BE4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x821F4BD0;
	sub_82144A18(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r10,r11,100
	ctx.r10.s64 = r11.s64 + 100;
	// li r11,1
	r11.s64 = 1;
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// bge cr6,0x821f4be8
	if (!cr6.lt) goto loc_821F4BE8;
loc_821F4BE4:
	// li r11,0
	r11.s64 = 0;
loc_821F4BE8:
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

__attribute__((alias("__imp__sub_821F4C00"))) PPC_WEAK_FUNC(sub_821F4C00);
PPC_FUNC_IMPL(__imp__sub_821F4C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F4C14"))) PPC_WEAK_FUNC(sub_821F4C14);
PPC_FUNC_IMPL(__imp__sub_821F4C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F4C18"))) PPC_WEAK_FUNC(sub_821F4C18);
PPC_FUNC_IMPL(__imp__sub_821F4C18) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4c5c
	if (cr6.eq) goto loc_821F4C5C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x821F4C4C;
	sub_82144A18(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8213c218
	ctx.lr = 0x821F4C5C;
	sub_8213C218(ctx, base);
loc_821F4C5C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4c74
	if (cr6.eq) goto loc_821F4C74;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_821F4C74:
	// li r11,4
	r11.s64 = 4;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
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

__attribute__((alias("__imp__sub_821F4C98"))) PPC_WEAK_FUNC(sub_821F4C98);
PPC_FUNC_IMPL(__imp__sub_821F4C98) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4cd0
	if (cr6.eq) goto loc_821F4CD0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a18
	ctx.lr = 0x821F4CC4;
	sub_82144A18(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8213c2c0
	ctx.lr = 0x821F4CD0;
	sub_8213C2C0(ctx, base);
loc_821F4CD0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f4ce8
	if (cr6.eq) goto loc_821F4CE8;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_821F4CE8:
	// li r11,4
	r11.s64 = 4;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
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

__attribute__((alias("__imp__sub_821F4D08"))) PPC_WEAK_FUNC(sub_821F4D08);
PPC_FUNC_IMPL(__imp__sub_821F4D08) {
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
	ctx.lr = 0x821F4D10;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// subf r10,r27,r3
	ctx.r10.s64 = ctx.r3.s64 - r27.s64;
loc_821F4D28:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821f4d28
	if (!cr6.eq) goto loc_821F4D28;
	// bl 0x823de4d8
	ctx.lr = 0x821F4D40;
	sub_823DE4D8(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r25,r31
	r25.u64 = r31.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// li r28,1
	r28.s64 = 1;
	// addi r26,r11,-24740
	r26.s64 = r11.s64 + -24740;
loc_821F4D58:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821F4D70;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821380e0
	ctx.lr = 0x821F4D78;
	sub_821380E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f4d94
	if (cr6.eq) goto loc_821F4D94;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// b 0x821f4d58
	goto loc_821F4D58;
loc_821F4D94:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x821f4da8
	if (!cr6.eq) goto loc_821F4DA8;
	// mr r25,r28
	r25.u64 = r28.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// b 0x821f4d58
	goto loc_821F4D58;
loc_821F4DA8:
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x821f4e6c
	if (cr6.eq) goto loc_821F4E6C;
	// lis r11,2047
	r11.s64 = 134152192;
	// rlwinm r3,r30,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// ble cr6,0x821f4dcc
	if (!cr6.gt) goto loc_821F4DCC;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821F4DCC:
	// bl 0x82130528
	ctx.lr = 0x821F4DD0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f4e18
	if (cr6.eq) goto loc_821F4E18;
	// addic. r10,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r10.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x821f4e10
	if (cr0.lt) goto loc_821F4E10;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
loc_821F4DE4:
	// stw r31,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, r31.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r31,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// stb r28,20(r11)
	PPC_STORE_U8(r11.u32 + 20, r28.u8);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bge 0x821f4de4
	if (!cr0.lt) goto loc_821F4DE4;
loc_821F4E10:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x821f4e1c
	goto loc_821F4E1C;
loc_821F4E18:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_821F4E1C:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821f4e6c
	if (!cr6.gt) goto loc_821F4E6C;
	// mr r30,r31
	r30.u64 = r31.u64;
loc_821F4E30:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// add r7,r31,r25
	ctx.r7.u64 = r31.u64 + r25.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821F4E48;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821380e0
	ctx.lr = 0x821F4E50;
	sub_821380E0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stwx r3,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, ctx.r3.u32);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x821f4e30
	if (cr6.lt) goto loc_821F4E30;
loc_821F4E6C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821F4E74"))) PPC_WEAK_FUNC(sub_821F4E74);
PPC_FUNC_IMPL(__imp__sub_821F4E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F4E78"))) PPC_WEAK_FUNC(sub_821F4E78);
PPC_FUNC_IMPL(__imp__sub_821F4E78) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x821F4E80;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r10
	r17.u64 = ctx.r10.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// li r31,0
	r31.s64 = 0;
	// li r18,-1
	r18.s64 = -1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r25,-1
	r25.s64 = -1;
	// lfs f13,-25056(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -25056);
	ctx.f13.f64 = double(temp.f32);
	// li r9,255
	ctx.r9.s64 = 255;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r18,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r18.u32);
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r25.u32);
	// stb r9,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r9.u8);
	// stb r31,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r31.u8);
	// stb r8,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r8.u8);
	// beq cr6,0x821f4f2c
	if (cr6.eq) goto loc_821F4F2C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x823da950
	ctx.lr = 0x821F4F2C;
	sub_823DA950(ctx, base);
loc_821F4F2C:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r27,r31
	r27.u64 = r31.u64;
	// mr r26,r25
	r26.u64 = r25.u64;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f5194
	if (!cr6.gt) goto loc_821F5194;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r31
	r28.u64 = r31.u64;
	// addi r20,r11,19856
	r20.s64 = r11.s64 + 19856;
loc_821F4F50:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r30,r28,r11
	r30.u64 = r28.u64 + r11.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f4fa4
	if (!cr6.eq) goto loc_821F4FA4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f4f90
	if (!cr6.eq) goto loc_821F4F90;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F4F7C;
	sub_82144A18(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x821f4f94
	if (!cr6.lt) goto loc_821F4F94;
loc_821F4F90:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_821F4F94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f5024
	if (!cr6.eq) goto loc_821F5024;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_821F4FA4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// bge cr6,0x821f4fc8
	if (!cr6.lt) goto loc_821F4FC8;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// bge cr6,0x821f4fc8
	if (!cr6.lt) goto loc_821F4FC8;
	// mr r25,r11
	r25.u64 = r11.u64;
	// mr r26,r27
	r26.u64 = r27.u64;
loc_821F4FC8:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,32
	r28.s64 = r28.s64 + 32;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x821f4f50
	if (cr6.lt) goto loc_821F4F50;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x821f4fe8
	if (cr6.eq) goto loc_821F4FE8;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
loc_821F4FE8:
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// beq cr6,0x821f5194
	if (cr6.eq) goto loc_821F5194;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r26,5,0,26
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f50b8
	if (cr6.eq) goto loc_821F50B8;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f50b0
	if (cr6.eq) goto loc_821F50B0;
	// bl 0x821f4c98
	ctx.lr = 0x821F5020;
	sub_821F4C98(ctx, base);
	// b 0x821f50b8
	goto loc_821F50B8;
loc_821F5024:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5048
	if (cr6.eq) goto loc_821F5048;
	// lbz r11,72(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5048
	if (cr6.eq) goto loc_821F5048;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,-22968(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -22968);
	// stb r11,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r11.u8);
loc_821F5048:
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82549078
	ctx.lr = 0x821F5060;
	sub_82549078(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5194
	if (cr6.eq) goto loc_821F5194;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// blt cr6,0x821f5078
	if (cr6.lt) goto loc_821F5078;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_821F5078:
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x821f508c
	if (cr6.eq) goto loc_821F508C;
	// stw r30,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r30.u32);
	// stw r19,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r19.u32);
loc_821F508C:
	// li r11,5
	r11.s64 = 5;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8213c0c0
	ctx.lr = 0x821F50A8;
	sub_8213C0C0(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d921c
	return;
loc_821F50B0:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821f4c18
	ctx.lr = 0x821F50B8;
	sub_821F4C18(ctx, base);
loc_821F50B8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f50dc
	if (cr6.eq) goto loc_821F50DC;
	// lbz r11,72(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f50dc
	if (cr6.eq) goto loc_821F50DC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,-22968(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -22968);
	// stb r11,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r11.u8);
loc_821F50DC:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82549078
	ctx.lr = 0x821F50F0;
	sub_82549078(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5194
	if (cr6.eq) goto loc_821F5194;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// blt cr6,0x821f510c
	if (cr6.lt) goto loc_821F510C;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_821F510C:
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x821f5120
	if (cr6.eq) goto loc_821F5120;
	// stw r30,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r30.u32);
	// stw r19,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r19.u32);
loc_821F5120:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f514c
	if (!cr6.eq) goto loc_821F514C;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F5138;
	sub_82144A18(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x821f514c
	if (cr6.lt) goto loc_821F514C;
	// li r31,1
	r31.s64 = 1;
loc_821F514C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f508c
	if (!cr6.eq) goto loc_821F508C;
	// li r11,3
	r11.s64 = 3;
	// clrlwi r10,r17,24
	ctx.r10.u64 = r17.u32 & 0xFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r9,28(r30)
	PPC_STORE_U8(r30.u32 + 28, ctx.r9.u8);
	// beq cr6,0x821f5184
	if (cr6.eq) goto loc_821F5184;
	// mr r11,r18
	r11.u64 = r18.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d921c
	return;
loc_821F5184:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F518C;
	sub_82144A18(ctx, base);
	// addi r11,r3,20000
	r11.s64 = ctx.r3.s64 + 20000;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
loc_821F5194:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_821F519C"))) PPC_WEAK_FUNC(sub_821F519C);
PPC_FUNC_IMPL(__imp__sub_821F519C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F51A0"))) PPC_WEAK_FUNC(sub_821F51A0);
PPC_FUNC_IMPL(__imp__sub_821F51A0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x821F51A8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// li r31,0
	r31.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r23,-1
	r23.s64 = -1;
	// lfs f13,-25056(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -25056);
	ctx.f13.f64 = double(temp.f32);
	// li r9,255
	ctx.r9.s64 = 255;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r23.u32);
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// stb r9,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r9.u8);
	// stb r31,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r31.u8);
	// stb r8,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r8.u8);
	// beq cr6,0x821f5254
	if (cr6.eq) goto loc_821F5254;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,72
	ctx.r5.s64 = 72;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x823da950
	ctx.lr = 0x821F5254;
	sub_823DA950(ctx, base);
loc_821F5254:
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x821f5428
	if (!cr6.gt) goto loc_821F5428;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r5,12
	ctx.r9.s64 = ctx.r5.s64 + 12;
loc_821F5274:
	// lwz r11,-8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f52b0
	if (cr6.eq) goto loc_821F52B0;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x821f529c
	if (!cr6.lt) goto loc_821F529C;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// bge cr6,0x821f529c
	if (!cr6.lt) goto loc_821F529C;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_821F529C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x821f5274
	if (cr6.lt) goto loc_821F5274;
	// b 0x821f52b4
	goto loc_821F52B4;
loc_821F52B0:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_821F52B4:
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x821f5428
	if (cr6.eq) goto loc_821F5428;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r11,r5
	r30.u64 = r11.u64 + ctx.r5.u64;
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f52f4
	if (cr6.eq) goto loc_821F52F4;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f52ec
	if (cr6.eq) goto loc_821F52EC;
	// bl 0x821f4c98
	ctx.lr = 0x821F52E8;
	sub_821F4C98(ctx, base);
	// b 0x821f52f4
	goto loc_821F52F4;
loc_821F52EC:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821f4c18
	ctx.lr = 0x821F52F4;
	sub_821F4C18(ctx, base);
loc_821F52F4:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// blt cr6,0x821f5304
	if (cr6.lt) goto loc_821F5304;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_821F5304:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f532c
	if (cr6.eq) goto loc_821F532C;
	// lbz r11,72(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f532c
	if (cr6.eq) goto loc_821F532C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,-22968(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -22968);
	// stb r11,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r11.u8);
loc_821F532C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82549078
	ctx.lr = 0x821F5340;
	sub_82549078(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5428
	if (cr6.eq) goto loc_821F5428;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x821f535c
	if (cr6.eq) goto loc_821F535C;
	// stw r30,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r30.u32);
	// stw r24,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r24.u32);
loc_821F535C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stb r31,28(r30)
	PPC_STORE_U8(r30.u32 + 28, r31.u8);
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f5394
	if (!cr6.eq) goto loc_821F5394;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F5380;
	sub_82144A18(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x821f5394
	if (cr6.lt) goto loc_821F5394;
	// li r31,1
	r31.s64 = 1;
loc_821F5394:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f53f4
	if (cr6.eq) goto loc_821F53F4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x8213e2f0
	ctx.lr = 0x821F53B0;
	sub_8213E2F0(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f53e4
	if (cr6.eq) goto loc_821F53E4;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x821f53e4
	if (cr6.eq) goto loc_821F53E4;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5418
	if (cr6.eq) goto loc_821F5418;
	// mr r11,r23
	r11.u64 = r23.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
loc_821F53E4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f4c98
	ctx.lr = 0x821F53EC;
	sub_821F4C98(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
loc_821F53F4:
	// li r11,3
	r11.s64 = 3;
	// clrlwi r10,r22,24
	ctx.r10.u64 = r22.u32 & 0xFF;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f5418
	if (cr6.eq) goto loc_821F5418;
	// mr r11,r23
	r11.u64 = r23.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
loc_821F5418:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F5420;
	sub_82144A18(ctx, base);
	// addi r11,r3,20000
	r11.s64 = ctx.r3.s64 + 20000;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
loc_821F5428:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821F5430"))) PPC_WEAK_FUNC(sub_821F5430);
PPC_FUNC_IMPL(__imp__sub_821F5430) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r11,19856
	r30.s64 = r11.s64 + 19856;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f546c
	if (cr6.eq) goto loc_821F546C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F5468;
	sub_82144A18(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_821F546C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f54a0
	if (!cr6.eq) goto loc_821F54A0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5498
	if (cr6.eq) goto loc_821F5498;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_821F5498:
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// b 0x821f5554
	goto loc_821F5554;
loc_821F54A0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821f54fc
	if (cr6.lt) goto loc_821F54FC;
	// beq cr6,0x821f54d0
	if (cr6.eq) goto loc_821F54D0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x821f5548
	if (!cr6.eq) goto loc_821F5548;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f4ba0
	ctx.lr = 0x821F54C0;
	sub_821F4BA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5554
	if (cr6.eq) goto loc_821F5554;
	// b 0x821f5510
	goto loc_821F5510;
loc_821F54D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F54D8;
	sub_82144A18(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F54E4;
	sub_82144A18(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x821f5554
	if (cr6.lt) goto loc_821F5554;
loc_821F54F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f4c98
	ctx.lr = 0x821F54F8;
	sub_821F4C98(ctx, base);
	// b 0x821f5554
	goto loc_821F5554;
loc_821F54FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F5504;
	sub_82144A18(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x821f54f0
	if (!cr6.lt) goto loc_821F54F0;
loc_821F5510:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8213e2f0
	ctx.lr = 0x821F5520;
	sub_8213E2F0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// bne cr6,0x821f5554
	if (!cr6.eq) goto loc_821F5554;
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5554
	if (cr6.eq) goto loc_821F5554;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8213c020
	ctx.lr = 0x821F5540;
	sub_8213C020(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_821F5548:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a18
	ctx.lr = 0x821F5550;
	sub_82144A18(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_821F5554:
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

__attribute__((alias("__imp__sub_821F556C"))) PPC_WEAK_FUNC(sub_821F556C);
PPC_FUNC_IMPL(__imp__sub_821F556C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F5570"))) PPC_WEAK_FUNC(sub_821F5570);
PPC_FUNC_IMPL(__imp__sub_821F5570) {
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
	ctx.lr = 0x821F5578;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f55b4
	if (!cr6.gt) goto loc_821F55B4;
	// li r31,0
	r31.s64 = 0;
loc_821F5594:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x821f5430
	ctx.lr = 0x821F55A0;
	sub_821F5430(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x821f5594
	if (cr6.lt) goto loc_821F5594;
loc_821F55B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F55BC"))) PPC_WEAK_FUNC(sub_821F55BC);
PPC_FUNC_IMPL(__imp__sub_821F55BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F55C0"))) PPC_WEAK_FUNC(sub_821F55C0);
PPC_FUNC_IMPL(__imp__sub_821F55C0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x821374e0
	ctx.lr = 0x821F55F4;
	sub_821374E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821375c8
	ctx.lr = 0x821F5600;
	sub_821375C8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_821F5620"))) PPC_WEAK_FUNC(sub_821F5620);
PPC_FUNC_IMPL(__imp__sub_821F5620) {
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
	ctx.lr = 0x821F5628;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f56a8
	if (!cr6.gt) goto loc_821F56A8;
	// lis r11,0
	r11.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// li r26,2
	r26.s64 = 2;
	// ori r27,r11,65535
	r27.u64 = r11.u64 | 65535;
loc_821F5650:
	// lwz r11,140(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x821f5694
	if (!cr6.eq) goto loc_821F5694;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// bl 0x821375c8
	ctx.lr = 0x821F5670;
	sub_821375C8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x821f5694
	if (!cr6.eq) goto loc_821F5694;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bne 0x821f5694
	if (!cr0.eq) goto loc_821F5694;
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// sth r27,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r27.u16);
loc_821F5694:
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x821f5650
	if (cr6.lt) goto loc_821F5650;
loc_821F56A8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F56B0"))) PPC_WEAK_FUNC(sub_821F56B0);
PPC_FUNC_IMPL(__imp__sub_821F56B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f56f0
	if (!cr6.gt) goto loc_821F56F0;
	// lwz r9,140(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_821F56CC:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// beq cr6,0x821f56f8
	if (cr6.eq) goto loc_821F56F8;
	// lwz r7,128(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x821f56cc
	if (cr6.lt) goto loc_821F56CC;
loc_821F56F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821F56F8:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f56f0
	if (cr6.eq) goto loc_821F56F0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bne 0x821f5728
	if (!cr0.eq) goto loc_821F5728;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// sth r9,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r9.u16);
loc_821F5728:
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x821f574c
	if (!cr6.eq) goto loc_821F574C;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, r11.u32);
loc_821F574C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F5754"))) PPC_WEAK_FUNC(sub_821F5754);
PPC_FUNC_IMPL(__imp__sub_821F5754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F5758"))) PPC_WEAK_FUNC(sub_821F5758);
PPC_FUNC_IMPL(__imp__sub_821F5758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x821f57a0
	if (!cr6.gt) goto loc_821F57A0;
	// lwz r7,140(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_821F5770:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x821f5790
	if (!cr6.eq) goto loc_821F5790;
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821f57a8
	if (cr6.eq) goto loc_821F57A8;
loc_821F5790:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x821f5770
	if (cr6.lt) goto loc_821F5770;
loc_821F57A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821F57A8:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r7
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F57B4"))) PPC_WEAK_FUNC(sub_821F57B4);
PPC_FUNC_IMPL(__imp__sub_821F57B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F57B8"))) PPC_WEAK_FUNC(sub_821F57B8);
PPC_FUNC_IMPL(__imp__sub_821F57B8) {
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
	ctx.lr = 0x821F57C0;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r23,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r23.u32);
	// subf r10,r26,r31
	ctx.r10.s64 = r31.s64 - r26.s64;
	// stw r23,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r23.u32);
	// stw r23,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r23.u32);
loc_821F57E4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x821f57e4
	if (!cr6.eq) goto loc_821F57E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823de4d8
	ctx.lr = 0x821F5800;
	sub_823DE4D8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r24,r11,-24404
	r24.s64 = r11.s64 + -24404;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821F5820;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821380e0
	ctx.lr = 0x821F5828;
	sub_821380E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5864
	if (cr6.eq) goto loc_821F5864;
loc_821F5830:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r4,128
	ctx.r4.s64 = 128;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x82137a08
	ctx.lr = 0x821F5854;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821380e0
	ctx.lr = 0x821F585C;
	sub_821380E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821f5830
	if (!cr6.eq) goto loc_821F5830;
loc_821F5864:
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x821f5880
	if (!cr6.gt) goto loc_821F5880;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821F5880:
	// bl 0x82130528
	ctx.lr = 0x821F5884;
	sub_82130528(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// mr r29,r23
	r29.u64 = r23.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f5914
	if (!cr6.gt) goto loc_821F5914;
	// lis r11,0
	r11.s64 = 0;
	// mr r27,r23
	r27.u64 = r23.u64;
	// li r25,2
	r25.s64 = 2;
	// ori r28,r11,65535
	r28.u64 = r11.u64 | 65535;
loc_821F58A8:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x821F58C0;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821380e0
	ctx.lr = 0x821F58C8;
	sub_821380E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x821F58D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f58f4
	if (cr6.eq) goto loc_821F58F4;
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r30.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r23,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r23.u32);
	// sth r28,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r28.u16);
	// stw r25,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r25.u32);
	// b 0x821f58f8
	goto loc_821F58F8;
loc_821F58F4:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_821F58F8:
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r11,r27,r10
	PPC_STORE_U32(r27.u32 + ctx.r10.u32, r11.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x821f58a8
	if (cr6.lt) goto loc_821F58A8;
loc_821F5914:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821F5920"))) PPC_WEAK_FUNC(sub_821F5920);
PPC_FUNC_IMPL(__imp__sub_821F5920) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f5978
	if (!cr6.gt) goto loc_821F5978;
	// lwz r9,140(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_821F5954:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// beq cr6,0x821f59a4
	if (cr6.eq) goto loc_821F59A4;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x821f5954
	if (cr6.lt) goto loc_821F5954;
loc_821F5978:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f5758
	ctx.lr = 0x821F5980;
	sub_821F5758(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f59e8
	if (cr6.eq) goto loc_821F59E8;
	// bl 0x821f55c0
	ctx.lr = 0x821F5990;
	sub_821F55C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f59d0
	if (!cr6.eq) goto loc_821F59D0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821f59ec
	goto loc_821F59EC;
loc_821F59A4:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r9
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5978
	if (cr6.eq) goto loc_821F5978;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r10.u32);
	// b 0x821f59ec
	goto loc_821F59EC;
loc_821F59D0:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
loc_821F59E8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_821F59EC:
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

__attribute__((alias("__imp__sub_821F5A04"))) PPC_WEAK_FUNC(sub_821F5A04);
PPC_FUNC_IMPL(__imp__sub_821F5A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F5A08"))) PPC_WEAK_FUNC(sub_821F5A08);
PPC_FUNC_IMPL(__imp__sub_821F5A08) {
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
	ctx.lr = 0x821F5A10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,128(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 128);
	// addic. r28,r11,-1
	xer.ca = r11.u32 > 0;
	r28.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x821f5a8c
	if (cr0.lt) goto loc_821F5A8C;
	// lis r11,0
	r11.s64 = 0;
	// rlwinm r29,r28,2,0,29
	r29.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r30,2
	r30.s64 = 2;
	// ori r31,r11,65535
	r31.u64 = r11.u64 | 65535;
	// li r26,0
	r26.s64 = 0;
loc_821F5A38:
	// lwz r11,140(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 140);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5a80
	if (cr6.eq) goto loc_821F5A80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f5a78
	if (!cr6.gt) goto loc_821F5A78;
loc_821F5A54:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bne 0x821f5a6c
	if (!cr0.eq) goto loc_821F5A6C;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// sth r31,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r31.u16);
loc_821F5A6C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x821f5a54
	if (cr6.gt) goto loc_821F5A54;
loc_821F5A78:
	// stw r26,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r26.u32);
	// bl 0x82130588
	ctx.lr = 0x821F5A80;
	sub_82130588(ctx, base);
loc_821F5A80:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,-4
	r29.s64 = r29.s64 + -4;
	// bge 0x821f5a38
	if (!cr0.lt) goto loc_821F5A38;
loc_821F5A8C:
	// lwz r3,140(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 140);
	// bl 0x82130588
	ctx.lr = 0x821F5A94;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F5A9C"))) PPC_WEAK_FUNC(sub_821F5A9C);
PPC_FUNC_IMPL(__imp__sub_821F5A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F5AA0"))) PPC_WEAK_FUNC(sub_821F5AA0);
PPC_FUNC_IMPL(__imp__sub_821F5AA0) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5bd8
	if (cr6.eq) goto loc_821F5BD8;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821f5bd8
	if (!cr6.eq) goto loc_821F5BD8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5ae8
	if (cr6.eq) goto loc_821F5AE8;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821f5bd8
	if (!cr6.eq) goto loc_821F5BD8;
loc_821F5AE8:
	// bl 0x821f4b28
	ctx.lr = 0x821F5AEC;
	sub_821F4B28(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5afc
	if (cr6.eq) goto loc_821F5AFC;
	// bl 0x821f4b28
	ctx.lr = 0x821F5AFC;
	sub_821F4B28(ctx, base);
loc_821F5AFC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lbz r10,27(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f5b20
	if (cr6.eq) goto loc_821F5B20;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x821f0270
	ctx.lr = 0x821F5B20;
	sub_821F0270(ctx, base);
loc_821F5B20:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,27(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f5b40
	if (cr6.eq) goto loc_821F5B40;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x821f0400
	ctx.lr = 0x821F5B40;
	sub_821F0400(ctx, base);
loc_821F5B40:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r5,r31,20
	ctx.r5.s64 = r31.s64 + 20;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,23(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 23);
	// bl 0x821ee790
	ctx.lr = 0x821F5B60;
	sub_821EE790(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r7,10(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 10);
	// rlwinm r6,r7,0,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821f5b8c
	if (cr6.eq) goto loc_821F5B8C;
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stb r11,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r11.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12288);
	// bl 0x821ebcf0
	ctx.lr = 0x821F5B8C;
	sub_821EBCF0(ctx, base);
loc_821F5B8C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x821F5B98;
	sub_821E6828(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f5bb8
	if (cr6.eq) goto loc_821F5BB8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x821F5BB8;
	sub_821F15C8(ctx, base);
loc_821F5BB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f5bd8
	if (cr6.eq) goto loc_821F5BD8;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// bl 0x826fd888
	ctx.lr = 0x821F5BD8;
	sub_826FD888(ctx, base);
loc_821F5BD8:
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

__attribute__((alias("__imp__sub_821F5BF0"))) PPC_WEAK_FUNC(sub_821F5BF0);
PPC_FUNC_IMPL(__imp__sub_821F5BF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5c2c
	if (cr6.eq) goto loc_821F5C2C;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821f5c2c
	if (!cr6.eq) goto loc_821F5C2C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5c20
	if (cr6.eq) goto loc_821F5C20;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x821f5c2c
	if (!cr6.eq) goto loc_821F5C2C;
loc_821F5C20:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_821F5C2C:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F5C38"))) PPC_WEAK_FUNC(sub_821F5C38);
PPC_FUNC_IMPL(__imp__sub_821F5C38) {
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
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5c88
	if (cr6.eq) goto loc_821F5C88;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5c88
	if (cr6.eq) goto loc_821F5C88;
	// lbz r11,27(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 27);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f5c88
	if (cr6.eq) goto loc_821F5C88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0590
	ctx.lr = 0x821F5C88;
	sub_821F0590(ctx, base);
loc_821F5C88:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5c9c
	if (cr6.eq) goto loc_821F5C9C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x821F5C9C;
	sub_821EC060(ctx, base);
loc_821F5C9C:
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// li r30,0
	r30.s64 = 0;
	// stb r30,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r30.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5cc4
	if (cr6.eq) goto loc_821F5CC4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// bl 0x821ebc70
	ctx.lr = 0x821F5CC0;
	sub_821EBC70(ctx, base);
	// stb r30,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r30.u8);
loc_821F5CC4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// beq cr6,0x821f5cf4
	if (cr6.eq) goto loc_821F5CF4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f5cf0
	if (cr6.eq) goto loc_821F5CF0;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_821F5CF0:
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_821F5CF4:
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

__attribute__((alias("__imp__sub_821F5D0C"))) PPC_WEAK_FUNC(sub_821F5D0C);
PPC_FUNC_IMPL(__imp__sub_821F5D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F5D10"))) PPC_WEAK_FUNC(sub_821F5D10);
PPC_FUNC_IMPL(__imp__sub_821F5D10) {
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
	// bl 0x82548ac0
	ctx.lr = 0x821F5D28;
	sub_82548AC0(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-24064
	ctx.r9.s64 = ctx.r10.s64 + -24064;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
	// stb r11,41(r31)
	PPC_STORE_U8(r31.u32 + 41, r11.u8);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stb r11,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r11.u8);
	// stb r11,69(r31)
	PPC_STORE_U8(r31.u32 + 69, r11.u8);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stb r11,96(r31)
	PPC_STORE_U8(r31.u32 + 96, r11.u8);
	// stb r11,97(r31)
	PPC_STORE_U8(r31.u32 + 97, r11.u8);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// stb r11,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r11.u8);
	// stb r11,125(r31)
	PPC_STORE_U8(r31.u32 + 125, r11.u8);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
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

__attribute__((alias("__imp__sub_821F5DD8"))) PPC_WEAK_FUNC(sub_821F5DD8);
PPC_FUNC_IMPL(__imp__sub_821F5DD8) {
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
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// li r30,4
	r30.s64 = 4;
loc_821F5DF4:
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f5e14
	if (!cr6.eq) goto loc_821F5E14;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f5e14
	if (!cr6.eq) goto loc_821F5E14;
	// addi r3,r31,-8
	ctx.r3.s64 = r31.s64 + -8;
	// bl 0x821f5c38
	ctx.lr = 0x821F5E14;
	sub_821F5C38(ctx, base);
loc_821F5E14:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// bne 0x821f5df4
	if (!cr0.eq) goto loc_821F5DF4;
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

__attribute__((alias("__imp__sub_821F5E38"))) PPC_WEAK_FUNC(sub_821F5E38);
PPC_FUNC_IMPL(__imp__sub_821F5E38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,24
	ctx.r10.s64 = ctx.r3.s64 + 24;
loc_821F5E40:
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f5e58
	if (!cr6.eq) goto loc_821F5E58;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f5e70
	if (cr6.eq) goto loc_821F5E70;
loc_821F5E58:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,28
	ctx.r10.s64 = ctx.r10.s64 + 28;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x821f5e40
	if (cr6.lt) goto loc_821F5E40;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821F5E70:
	// mulli r11,r11,28
	r11.s64 = r11.s64 * 28;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F5E80"))) PPC_WEAK_FUNC(sub_821F5E80);
PPC_FUNC_IMPL(__imp__sub_821F5E80) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5ea8
	if (cr6.eq) goto loc_821F5EA8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F5EA8;
	sub_821F4C18(ctx, base);
loc_821F5EA8:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5ebc
	if (cr6.eq) goto loc_821F5EBC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F5EBC;
	sub_821F4C18(ctx, base);
loc_821F5EBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f5c38
	ctx.lr = 0x821F5EC4;
	sub_821F5C38(ctx, base);
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

__attribute__((alias("__imp__sub_821F5ED8"))) PPC_WEAK_FUNC(sub_821F5ED8);
PPC_FUNC_IMPL(__imp__sub_821F5ED8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f5f30
	if (cr6.eq) goto loc_821F5F30;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5f14
	if (cr6.eq) goto loc_821F5F14;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F5F14;
	sub_821F4C18(ctx, base);
loc_821F5F14:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f5f28
	if (cr6.eq) goto loc_821F5F28;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F5F28;
	sub_821F4C18(ctx, base);
loc_821F5F28:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f5c38
	ctx.lr = 0x821F5F30;
	sub_821F5C38(ctx, base);
loc_821F5F30:
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

__attribute__((alias("__imp__sub_821F5F44"))) PPC_WEAK_FUNC(sub_821F5F44);
PPC_FUNC_IMPL(__imp__sub_821F5F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F5F48"))) PPC_WEAK_FUNC(sub_821F5F48);
PPC_FUNC_IMPL(__imp__sub_821F5F48) {
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
	// bl 0x82548b50
	ctx.lr = 0x821F5F68;
	sub_82548B50(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f5f80
	if (cr6.eq) goto loc_821F5F80;
	// bl 0x82130588
	ctx.lr = 0x821F5F7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F5F80:
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

__attribute__((alias("__imp__sub_821F5F98"))) PPC_WEAK_FUNC(sub_821F5F98);
PPC_FUNC_IMPL(__imp__sub_821F5F98) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x821F5FA0;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821f5e38
	ctx.lr = 0x821F5FB4;
	sub_821F5E38(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x821f5fd4
	if (!cr6.eq) goto loc_821F5FD4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-23944
	ctx.r3.s64 = r11.s64 + -23944;
	// bl 0x82130000
	ctx.lr = 0x821F5FCC;
	sub_82130000(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9234
	return;
loc_821F5FD4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821f5fe8
	if (cr6.eq) goto loc_821F5FE8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r26,-12536(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -12536);
	// b 0x821f5ff0
	goto loc_821F5FF0;
loc_821F5FE8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r26,-12548(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -12548);
loc_821F5FF0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,-23960
	ctx.r5.s64 = r11.s64 + -23960;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x821F6008;
	sub_82137A08(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x821F6018;
	sub_82144A20(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x821f622c
	if (cr6.eq) goto loc_821F622C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,12(r24)
	PPC_STORE_U32(r24.u32 + 12, r28.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r27,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r27.u32);
	// li r29,0
	r29.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r7,255
	ctx.r7.s64 = 255;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r6,4
	ctx.r6.s64 = 4;
	// lfs f13,-24352(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -24352);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r29.u32);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r29.u32);
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r29.u32);
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
	// stw r9,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// stb r7,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r7.u8);
	// stb r29,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r29.u8);
	// stb r6,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r6.u8);
	// beq cr6,0x821f6198
	if (cr6.eq) goto loc_821F6198;
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// li r10,36
	ctx.r10.s64 = 36;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stb r10,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r10.u8);
loc_821F60BC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r11,-12288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// lfs f13,1044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1044);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x821f60e4
	if (cr6.eq) goto loc_821F60E4;
	// lwz r4,15(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 15);
	// lwz r11,-32452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32452);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x821f60e8
	if (!cr6.eq) goto loc_821F60E8;
loc_821F60E4:
	// lwz r4,11(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 11);
loc_821F60E8:
	// addi r30,r24,4
	r30.s64 = r24.s64 + 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821f51a0
	ctx.lr = 0x821F6108;
	sub_821F51A0(ctx, base);
	// lwz r4,19(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 19);
	// lwz r11,-32452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32452);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x821f6144
	if (cr6.eq) goto loc_821F6144;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// beq cr6,0x821f6128
	if (cr6.eq) goto loc_821F6128;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_821F6128:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r24,8
	ctx.r5.s64 = r24.s64 + 8;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821f51a0
	ctx.lr = 0x821F6144;
	sub_821F51A0(ctx, base);
loc_821F6144:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f622c
	if (cr6.eq) goto loc_821F622C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r11,-24032
	ctx.r3.s64 = r11.s64 + -24032;
	// bl 0x82130000
	ctx.lr = 0x821F6160;
	sub_82130000(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r9,-12216(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12216);
	// lwz r11,376(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821f61a0
	if (!cr6.eq) goto loc_821F61A0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6190
	if (cr6.eq) goto loc_821F6190;
	// lwz r11,380(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821f61a0
	if (!cr6.eq) goto loc_821F61A0;
loc_821F6190:
	// li r11,1
	r11.s64 = 1;
	// b 0x821f61a4
	goto loc_821F61A4;
loc_821F6198:
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// b 0x821f60bc
	goto loc_821F60BC;
loc_821F61A0:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_821F61A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f61c4
	if (cr6.eq) goto loc_821F61C4;
	// lbz r11,27(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 27);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821f61c8
	if (!cr6.eq) goto loc_821F61C8;
loc_821F61C4:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_821F61C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,24(r24)
	PPC_STORE_U8(r24.u32 + 24, r11.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6224
	if (cr6.eq) goto loc_821F6224;
	// lwz r3,-12216(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12216);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x821f620c
	if (!cr6.eq) goto loc_821F620C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6204
	if (cr6.eq) goto loc_821F6204;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821f620c
	if (!cr6.eq) goto loc_821F620C;
loc_821F6204:
	// li r11,1
	r11.s64 = 1;
	// b 0x821f6210
	goto loc_821F6210;
loc_821F620C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_821F6210:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6224
	if (cr6.eq) goto loc_821F6224;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821ef1f8
	ctx.lr = 0x821F6224;
	sub_821EF1F8(ctx, base);
loc_821F6224:
	// stw r24,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r24.u32);
	// stw r23,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r23.u32);
loc_821F622C:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821F6234"))) PPC_WEAK_FUNC(sub_821F6234);
PPC_FUNC_IMPL(__imp__sub_821F6234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6238"))) PPC_WEAK_FUNC(sub_821F6238);
PPC_FUNC_IMPL(__imp__sub_821F6238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// li r30,4
	r30.s64 = 4;
loc_821F6254:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f6268
	if (cr6.eq) goto loc_821F6268;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F6268;
	sub_821F4C18(ctx, base);
loc_821F6268:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f627c
	if (cr6.eq) goto loc_821F627C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f4c18
	ctx.lr = 0x821F627C;
	sub_821F4C18(ctx, base);
loc_821F627C:
	// addi r3,r31,-8
	ctx.r3.s64 = r31.s64 + -8;
	// bl 0x821f5c38
	ctx.lr = 0x821F6284;
	sub_821F5C38(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// bne 0x821f6254
	if (!cr0.eq) goto loc_821F6254;
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

__attribute__((alias("__imp__sub_821F62A8"))) PPC_WEAK_FUNC(sub_821F62A8);
PPC_FUNC_IMPL(__imp__sub_821F62A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-12560(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// b 0x821f5f98
	sub_821F5F98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F62C0"))) PPC_WEAK_FUNC(sub_821F62C0);
PPC_FUNC_IMPL(__imp__sub_821F62C0) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-23500
	ctx.r9.s64 = r11.s64 + -23500;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x821f62f4
	if (cr6.eq) goto loc_821F62F4;
	// bl 0x82130588
	ctx.lr = 0x821F62F0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F62F4:
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

__attribute__((alias("__imp__sub_821F6308"))) PPC_WEAK_FUNC(sub_821F6308);
PPC_FUNC_IMPL(__imp__sub_821F6308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r11,-23480
	ctx.r4.s64 = r11.s64 + -23480;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x821F6334;
	sub_82144A20(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,48(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r4,40(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// stw r3,-11980(r31)
	PPC_STORE_U32(r31.u32 + -11980, ctx.r3.u32);
	// lhz r8,38(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// lfs f31,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f31.f64 = double(temp.f32);
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x821493f8
	ctx.lr = 0x821F637C;
	sub_821493F8(ctx, base);
	// lwz r11,-11980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -11980);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bl 0x821f6830
	ctx.lr = 0x821F6390;
	sub_821F6830(ctx, base);
	// lwz r11,-11980(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -11980);
	// lwz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 62);
	// lwz r9,54(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// lhz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// lwz r3,58(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 58);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f3,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f2,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f1,f9
	ctx.f1.f64 = double(float(ctx.f9.f64));
	// bl 0x821f6898
	ctx.lr = 0x821F63CC;
	sub_821F6898(ctx, base);
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

__attribute__((alias("__imp__sub_821F63E8"))) PPC_WEAK_FUNC(sub_821F63E8);
PPC_FUNC_IMPL(__imp__sub_821F63E8) {
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
	ctx.lr = 0x821F63F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r28,4
	r28.s64 = 4;
	// lwz r30,12(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r27,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r27.u32);
	// stw r4,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r4.u32);
loc_821F6410:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r11
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f6460
	if (cr6.eq) goto loc_821F6460;
	// lbz r11,119(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f6460
	if (!cr6.eq) goto loc_821F6460;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6d60
	ctx.lr = 0x821F6438;
	sub_821F6D60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6460
	if (cr6.eq) goto loc_821F6460;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F645C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
loc_821F6460:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// bne cr6,0x821f6470
	if (!cr6.eq) goto loc_821F6470;
	// li r30,0
	r30.s64 = 0;
loc_821F6470:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821f6484
	if (cr6.eq) goto loc_821F6484;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x821f6410
	if (!cr6.eq) goto loc_821F6410;
loc_821F6484:
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F6490"))) PPC_WEAK_FUNC(sub_821F6490);
PPC_FUNC_IMPL(__imp__sub_821F6490) {
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
	ctx.lr = 0x821F6498;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r26,r29,16
	r26.s64 = r29.s64 + 16;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c8f20
	ctx.lr = 0x821F64B0;
	sub_821C8F20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6524
	if (cr6.eq) goto loc_821F6524;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821f651c
	if (!cr6.gt) goto loc_821F651C;
	// li r30,0
	r30.s64 = 0;
loc_821F64D0:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f6508
	if (cr6.eq) goto loc_821F6508;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x821F64E8;
	sub_82618698(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f6508
	if (cr6.eq) goto loc_821F6508;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F6508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F6508:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x821f64d0
	if (cr6.lt) goto loc_821F64D0;
loc_821F651C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c8f70
	ctx.lr = 0x821F6524;
	sub_821C8F70(ctx, base);
loc_821F6524:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821F652C"))) PPC_WEAK_FUNC(sub_821F652C);
PPC_FUNC_IMPL(__imp__sub_821F652C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6530"))) PPC_WEAK_FUNC(sub_821F6530);
PPC_FUNC_IMPL(__imp__sub_821F6530) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r10,r11,-23488
	ctx.r10.s64 = r11.s64 + -23488;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x821F6558;
	sub_821C8ED8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bl 0x821f6308
	ctx.lr = 0x821F6570;
	sub_821F6308(ctx, base);
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

__attribute__((alias("__imp__sub_821F6588"))) PPC_WEAK_FUNC(sub_821F6588);
PPC_FUNC_IMPL(__imp__sub_821F6588) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r10,r11,-23488
	ctx.r10.s64 = r11.s64 + -23488;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x821F65B8;
	sub_82130000(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-23500
	ctx.r7.s64 = ctx.r9.s64 + -23500;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x821f65dc
	if (cr6.eq) goto loc_821F65DC;
	// bl 0x82130588
	ctx.lr = 0x821F65D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F65DC:
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

__attribute__((alias("__imp__sub_821F65F4"))) PPC_WEAK_FUNC(sub_821F65F4);
PPC_FUNC_IMPL(__imp__sub_821F65F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F65F8"))) PPC_WEAK_FUNC(sub_821F65F8);
PPC_FUNC_IMPL(__imp__sub_821F65F8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821f6694
	if (cr6.eq) goto loc_821F6694;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r31,255
	r31.s64 = 255;
	// lfs f13,-23456(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -23456);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r31.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r10,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r10.u8);
	// bl 0x825494d8
	ctx.lr = 0x821F6694;
	sub_825494D8(ctx, base);
loc_821F6694:
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

__attribute__((alias("__imp__sub_821F66A8"))) PPC_WEAK_FUNC(sub_821F66A8);
PPC_FUNC_IMPL(__imp__sub_821F66A8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r31,-1
	r31.s64 = -1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r30,255
	r30.s64 = 255;
	// lfs f13,-23456(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -23456);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r30.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r10,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r10.u8);
	// bl 0x82549660
	ctx.lr = 0x821F6740;
	sub_82549660(ctx, base);
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

__attribute__((alias("__imp__sub_821F6758"))) PPC_WEAK_FUNC(sub_821F6758);
PPC_FUNC_IMPL(__imp__sub_821F6758) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-28924
	ctx.r10.s64 = r11.s64 + -28924;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82548ac0
	ctx.lr = 0x821F6780;
	sub_82548AC0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r7,r9,-23104
	ctx.r7.s64 = ctx.r9.s64 + -23104;
	// addi r6,r8,-23136
	ctx.r6.s64 = ctx.r8.s64 + -23136;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_821F67B8"))) PPC_WEAK_FUNC(sub_821F67B8);
PPC_FUNC_IMPL(__imp__sub_821F67B8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821f67c0
	sub_821F67C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F67C0"))) PPC_WEAK_FUNC(sub_821F67C0);
PPC_FUNC_IMPL(__imp__sub_821F67C0) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bne cr6,0x821f67ec
	if (!cr6.eq) goto loc_821F67EC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_821F67EC:
	// bl 0x82548b50
	ctx.lr = 0x821F67F0;
	sub_82548B50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x821F67F8;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6810
	if (cr6.eq) goto loc_821F6810;
	// bl 0x82130588
	ctx.lr = 0x821F680C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F6810:
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

__attribute__((alias("__imp__sub_821F6828"))) PPC_WEAK_FUNC(sub_821F6828);
PPC_FUNC_IMPL(__imp__sub_821F6828) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F6830"))) PPC_WEAK_FUNC(sub_821F6830);
PPC_FUNC_IMPL(__imp__sub_821F6830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f29.u64);
	// stfd f30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// addi r3,r11,-11952
	ctx.r3.s64 = r11.s64 + -11952;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// bl 0x82164840
	ctx.lr = 0x821F6864;
	sub_82164840(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,-11976
	ctx.r9.s64 = ctx.r10.s64 + -11976;
	// stfs f31,-11976(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + -11976, temp.u32);
	// stfs f30,4(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f29,8(r9)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-32(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f30,-24(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F6894"))) PPC_WEAK_FUNC(sub_821F6894);
PPC_FUNC_IMPL(__imp__sub_821F6894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6898"))) PPC_WEAK_FUNC(sub_821F6898);
PPC_FUNC_IMPL(__imp__sub_821F6898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f29.u64);
	// stfd f30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// addi r3,r11,-11912
	ctx.r3.s64 = r11.s64 + -11912;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// bl 0x82164840
	ctx.lr = 0x821F68CC;
	sub_82164840(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,-11956
	ctx.r9.s64 = ctx.r10.s64 + -11956;
	// stfs f29,-11956(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + -11956, temp.u32);
	// stfs f31,-8(r9)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// stfs f30,-4(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-32(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f30,-24(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F68FC"))) PPC_WEAK_FUNC(sub_821F68FC);
PPC_FUNC_IMPL(__imp__sub_821F68FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6900"))) PPC_WEAK_FUNC(sub_821F6900);
PPC_FUNC_IMPL(__imp__sub_821F6900) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x821F6908;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821c8f08
	ctx.lr = 0x821F691C;
	sub_821C8F08(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r29,r11,-11976
	r29.s64 = r11.s64 + -11976;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lfs f3,-11976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11976);
	ctx.f3.f64 = double(temp.f32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r3,r8,-11952
	ctx.r3.s64 = ctx.r8.s64 + -11952;
	// lfs f5,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f0,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// fsubs f13,f5,f0
	ctx.f13.f64 = double(float(ctx.f5.f64 - f0.f64));
	// lfs f2,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// fsel f12,f13,f5,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f5.f64 : f0.f64;
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// bl 0x82165128
	ctx.lr = 0x821F6960;
	sub_82165128(ctx, base);
	// stfs f1,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f1,36(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lfs f5,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f1,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// addi r3,r6,-11912
	ctx.r3.s64 = ctx.r6.s64 + -11912;
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// lfs f2,-23044(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -23044);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82165128
	ctx.lr = 0x821F698C;
	sub_82165128(ctx, base);
	// stfs f1,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f1,40(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f0,-22652(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -22652);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x823db788
	ctx.lr = 0x821F69A4;
	sub_823DB788(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f10,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-22768(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -22768);
	f0.f64 = double(temp.f32);
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f9,44(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f10,0(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f8,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,4(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// bl 0x821c8f70
	ctx.lr = 0x821F69D0;
	sub_821C8F70(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F69DC"))) PPC_WEAK_FUNC(sub_821F69DC);
PPC_FUNC_IMPL(__imp__sub_821F69DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F69E0"))) PPC_WEAK_FUNC(sub_821F69E0);
PPC_FUNC_IMPL(__imp__sub_821F69E0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// beq cr6,0x821f6a74
	if (cr6.eq) goto loc_821F6A74;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r30,r11,-11976
	r30.s64 = r11.s64 + -11976;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lfs f3,-11976(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11976);
	ctx.f3.f64 = double(temp.f32);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r3,r8,-11952
	ctx.r3.s64 = ctx.r8.s64 + -11952;
	// lfs f2,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f4,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x82165128
	ctx.lr = 0x821F6A44;
	sub_82165128(ctx, base);
	// stfs f1,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lfs f4,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f1,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// addi r3,r6,-11912
	ctx.r3.s64 = ctx.r6.s64 + -11912;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f2,-23044(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -23044);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82165128
	ctx.lr = 0x821F6A6C;
	sub_82165128(ctx, base);
	// stfs f1,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f31,32(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_821F6A74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F6A94"))) PPC_WEAK_FUNC(sub_821F6A94);
PPC_FUNC_IMPL(__imp__sub_821F6A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6A98"))) PPC_WEAK_FUNC(sub_821F6A98);
PPC_FUNC_IMPL(__imp__sub_821F6A98) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x821F6AA0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x821c8f20
	ctx.lr = 0x821F6AB8;
	sub_821C8F20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6b88
	if (cr6.eq) goto loc_821F6B88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f1,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// addi r28,r31,36
	r28.s64 = r31.s64 + 36;
	// addi r29,r11,-11956
	r29.s64 = r11.s64 + -11956;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x821f6af0
	if (cr6.eq) goto loc_821F6AF0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f2,-12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -12);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// bl 0x821ce490
	ctx.lr = 0x821F6AF0;
	sub_821CE490(ctx, base);
loc_821F6AF0:
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f13,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x821f6b70
	if (cr6.eq) goto loc_821F6B70;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,-22652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -22652);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823db788
	ctx.lr = 0x821F6B10;
	sub_823DB788(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r30,r31,44
	r30.s64 = r31.s64 + 44;
	// lfs f2,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,-22768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22768);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x821ce490
	ctx.lr = 0x821F6B34;
	sub_821CE490(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f6b4c
	if (cr6.eq) goto loc_821F6B4C;
	// lfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// b 0x821f6b70
	goto loc_821F6B70;
loc_821F6B4C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f2,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfd f1,-32664(r11)
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + -32664);
	// bl 0x823dc480
	ctx.lr = 0x821F6B5C;
	sub_823DC480(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-23044(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -23044);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,40(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
loc_821F6B70:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// bl 0x821c8f70
	ctx.lr = 0x821F6B88;
	sub_821C8F70(ctx, base);
loc_821F6B88:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821F6B94"))) PPC_WEAK_FUNC(sub_821F6B94);
PPC_FUNC_IMPL(__imp__sub_821F6B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6B98"))) PPC_WEAK_FUNC(sub_821F6B98);
PPC_FUNC_IMPL(__imp__sub_821F6B98) {
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
	// bl 0x821c8f08
	ctx.lr = 0x821F6BB8;
	sub_821C8F08(ctx, base);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f12,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,4(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// bl 0x821c8f70
	ctx.lr = 0x821F6BDC;
	sub_821C8F70(ctx, base);
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

__attribute__((alias("__imp__sub_821F6BF4"))) PPC_WEAK_FUNC(sub_821F6BF4);
PPC_FUNC_IMPL(__imp__sub_821F6BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6BF8"))) PPC_WEAK_FUNC(sub_821F6BF8);
PPC_FUNC_IMPL(__imp__sub_821F6BF8) {
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
	// bl 0x82618698
	ctx.lr = 0x821F6C10;
	sub_82618698(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f6c3c
	if (cr6.eq) goto loc_821F6C3C;
	// lbz r11,119(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f6c3c
	if (!cr6.eq) goto loc_821F6C3C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r5,r31,4
	ctx.r5.s64 = r31.s64 + 4;
	// addi r10,r11,19856
	ctx.r10.s64 = r11.s64 + 19856;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// lfs f1,808(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 808);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821f6a98
	ctx.lr = 0x821F6C3C;
	sub_821F6A98(ctx, base);
loc_821F6C3C:
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

__attribute__((alias("__imp__sub_821F6C50"))) PPC_WEAK_FUNC(sub_821F6C50);
PPC_FUNC_IMPL(__imp__sub_821F6C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,118(r3)
	PPC_STORE_U8(ctx.r3.u32 + 118, r11.u8);
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// stb r10,119(r3)
	PPC_STORE_U8(ctx.r3.u32 + 119, ctx.r10.u8);
	// stb r11,117(r3)
	PPC_STORE_U8(ctx.r3.u32 + 117, r11.u8);
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// b 0x821f6900
	sub_821F6900(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F6C70"))) PPC_WEAK_FUNC(sub_821F6C70);
PPC_FUNC_IMPL(__imp__sub_821F6C70) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F6C78"))) PPC_WEAK_FUNC(sub_821F6C78);
PPC_FUNC_IMPL(__imp__sub_821F6C78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// li r11,0
	r11.s64 = 0;
	// li r8,32
	ctx.r8.s64 = 32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,48
	ctx.r6.s64 = 48;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,-1
	ctx.r5.s64 = -1;
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r5,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, ctx.r5.u16);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// sth r11,78(r3)
	PPC_STORE_U16(ctx.r3.u32 + 78, r11.u16);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stb r11,80(r3)
	PPC_STORE_U8(ctx.r3.u32 + 80, r11.u8);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// sth r11,82(r3)
	PPC_STORE_U16(ctx.r3.u32 + 82, r11.u16);
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F6CD8"))) PPC_WEAK_FUNC(sub_821F6CD8);
PPC_FUNC_IMPL(__imp__sub_821F6CD8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x821F6CE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82162518
	ctx.lr = 0x821F6CF0;
	sub_82162518(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// addi r10,r11,-22760
	ctx.r10.s64 = r11.s64 + -22760;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x821F6D08;
	sub_821C8ED8(ctx, base);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// li r8,80
	ctx.r8.s64 = 80;
	// stw r29,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r29.u32);
	// addi r7,r9,2256
	ctx.r7.s64 = ctx.r9.s64 + 2256;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,117(r31)
	PPC_STORE_U8(r31.u32 + 117, r11.u8);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stb r11,118(r31)
	PPC_STORE_U8(r31.u32 + 118, r11.u8);
	// stb r5,119(r31)
	PPC_STORE_U8(r31.u32 + 119, ctx.r5.u8);
	// bl 0x821f6900
	ctx.lr = 0x821F6D50;
	sub_821F6900(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F6D5C"))) PPC_WEAK_FUNC(sub_821F6D5C);
PPC_FUNC_IMPL(__imp__sub_821F6D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F6D60"))) PPC_WEAK_FUNC(sub_821F6D60);
PPC_FUNC_IMPL(__imp__sub_821F6D60) {
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
	// bl 0x82618698
	ctx.lr = 0x821F6D78;
	sub_82618698(ctx, base);
	// lbz r11,116(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// bne cr6,0x821f6d8c
	if (!cr6.eq) goto loc_821F6D8C;
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
loc_821F6D8C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r10,-12352
	ctx.r8.s64 = ctx.r10.s64 + -12352;
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,-11980(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11980);
	// lfs f0,52(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,56(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,48(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lwz r7,10(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f7
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f6
	cr6.compare(ctx.f3.f64, ctx.f6.f64);
	// blt cr6,0x821f6e08
	if (cr6.lt) goto loc_821F6E08;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821f6900
	ctx.lr = 0x821F6DF0;
	sub_821F6900(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_821F6E08:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_821F6E20"))) PPC_WEAK_FUNC(sub_821F6E20);
PPC_FUNC_IMPL(__imp__sub_821F6E20) {
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
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91e8
	ctx.lr = 0x821F6E28;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d0
	ctx.lr = 0x821F6E30;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r26,r11,-11872
	r26.s64 = r11.s64 + -11872;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r11,-10336(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10336);
	// li r30,16
	r30.s64 = 16;
	// li r31,0
	r31.s64 = 0;
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// lfs f26,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f26.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821f6ec4
	if (!cr6.eq) goto loc_821F6EC4;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stw r11,-10336(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10336, r11.u32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r6,r9,2256
	ctx.r6.s64 = ctx.r9.s64 + 2256;
	// addi r11,r26,32
	r11.s64 = r26.s64 + 32;
	// li r8,-16
	ctx.r8.s64 = -16;
	// ori r9,r7,65535
	ctx.r9.u64 = ctx.r7.u64 | 65535;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821F6E8C:
	// stfs f26,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stw r31,-32(r11)
	PPC_STORE_U32(r11.u32 + -32, r31.u32);
	// stfs f26,36(r11)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// sth r9,44(r11)
	PPC_STORE_U16(r11.u32 + 44, ctx.r9.u16);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r31,46(r11)
	PPC_STORE_U16(r11.u32 + 46, r31.u16);
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r31,48(r11)
	PPC_STORE_U8(r11.u32 + 48, r31.u8);
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r31,50(r11)
	PPC_STORE_U16(r11.u32 + 50, r31.u16);
	// stw r31,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r31.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// bge 0x821f6e8c
	if (!cr0.lt) goto loc_821F6E8C;
loc_821F6EC4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82618698
	ctx.lr = 0x821F6ECC;
	sub_82618698(ctx, base);
	// lbz r11,116(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6eec
	if (cr6.eq) goto loc_821F6EEC;
	// li r11,80
	r11.s64 = 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r25,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821f6fb8
	goto loc_821F6FB8;
loc_821F6EEC:
	// lbz r11,117(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 117);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f6f9c
	if (cr6.eq) goto loc_821F6F9C;
	// lbz r11,118(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 118);
	// li r10,96
	ctx.r10.s64 = 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f6f8c
	if (!cr6.eq) goto loc_821F6F8C;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// addi r5,r9,2384
	ctx.r5.s64 = ctx.r9.s64 + 2384;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r4,2352
	ctx.r9.s64 = ctx.r4.s64 + 2352;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v62,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v56,r25,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v61,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vand128 v54,v56,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v55,v62,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v53,v61,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r3,118(r25)
	PPC_STORE_U8(r25.u32 + 118, ctx.r3.u8);
	// vmrglw128 v52,v58,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vor128 v50,v63,v54
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vmrghw128 v51,v58,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v49,v55,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmsum4fp128 v48,v50,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v47,v50,v49
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v46,v50,v51
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmrghw128 v45,v48,v50
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v43,r25,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821F6F8C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r25,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821f6fb8
	goto loc_821F6FB8;
loc_821F6F9C:
	// li r11,80
	r11.s64 = 80;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v42,r25,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r3,r10
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v41,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v42.f32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821F6FB8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r5,76(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r27,r11,-12352
	r27.s64 = r11.s64 + -12352;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r27,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,16
	ctx.r6.s64 = 16;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r24,r31
	r24.u64 = r31.u64;
	// lfs f0,-31380(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31380);
	f0.f64 = double(temp.f32);
	// fmr f27,f0
	f27.f64 = f0.f64;
	// fmr f28,f0
	f28.f64 = f0.f64;
	// bl 0x822c6370
	ctx.lr = 0x821F7010;
	sub_822C6370(ctx, base);
	// lis r28,-32114
	r28.s64 = -2104623104;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x821f70a4
	if (!cr6.gt) goto loc_821F70A4;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r26,24
	r30.s64 = r26.s64 + 24;
loc_821F7024:
	// lwz r3,-23464(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -23464);
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F703C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r8,226(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 226);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// beq cr6,0x821f7098
	if (cr6.eq) goto loc_821F7098;
	// lfs f0,52(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,56(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f11,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f0,48(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfs f9,-8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f0,f8,f8,f6
	f0.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bge cr6,0x821f7098
	if (!cr6.lt) goto loc_821F7098;
	// fmr f27,f0
	f27.f64 = f0.f64;
	// mr r24,r11
	r24.u64 = r11.u64;
loc_821F7098:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bne 0x821f7024
	if (!cr0.eq) goto loc_821F7024;
loc_821F70A4:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,76(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x822c6370
	ctx.lr = 0x821F70B8;
	sub_822C6370(ctx, base);
	// lfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f31.f64 = double(temp.f32);
	// lfs f30,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f30.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f29,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f29.f64 = double(temp.f32);
	// ble cr6,0x821f7148
	if (!cr6.gt) goto loc_821F7148;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r26,24
	r30.s64 = r26.s64 + 24;
loc_821F70D4:
	// lwz r3,-23464(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -23464);
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F70EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r8,226(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 226);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// beq cr6,0x821f713c
	if (cr6.eq) goto loc_821F713C;
	// lfs f0,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// lfs f10,-8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 - f29.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f0,f9,f9,f7
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x821f713c
	if (!cr6.lt) goto loc_821F713C;
	// fmr f28,f0
	f28.f64 = f0.f64;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_821F713C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bne 0x821f70d4
	if (!cr0.eq) goto loc_821F70D4;
loc_821F7148:
	// lfs f0,48(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lfs f13,52(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// lfs f12,56(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f29
	f0.f64 = double(float(f0.f64 - f29.f64));
	// fsubs f13,f13,f30
	ctx.f13.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fsubs f12,f12,f31
	ctx.f12.f64 = double(float(ctx.f12.f64 - f31.f64));
	// beq cr6,0x821f71d0
	if (cr6.eq) goto loc_821F71D0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f71bc
	if (cr6.eq) goto loc_821F71BC;
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lwz r11,226(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 226);
	// lwz r10,226(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 226);
	// fsqrts f11,f27
	ctx.f11.f64 = double(float(sqrt(f27.f64)));
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f12,f12,f13
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fsqrts f7,f28
	ctx.f7.f64 = double(float(sqrt(f28.f64)));
	// fmadds f6,f0,f0,f8
	ctx.f6.f64 = double(float(f0.f64 * f0.f64 + ctx.f8.f64));
	// fsubs f5,f9,f10
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsqrts f4,f6
	ctx.f4.f64 = double(float(sqrt(ctx.f6.f64)));
	// fsubs f3,f4,f11
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f11.f64));
	// fsel f2,f5,f9,f10
	ctx.f2.f64 = ctx.f5.f64 >= 0.0 ? ctx.f9.f64 : ctx.f10.f64;
	// fsubs f1,f3,f7
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f7.f64));
	// fmuls f1,f1,f2
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// b 0x821f71ec
	goto loc_821F71EC;
loc_821F71BC:
	// lwz r11,226(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 226);
	// fsqrts f0,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(sqrt(f27.f64)));
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// b 0x821f71e8
	goto loc_821F71E8;
loc_821F71D0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821f71ec
	if (cr6.eq) goto loc_821F71EC;
	// lwz r11,226(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 226);
	// fsqrts f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(sqrt(f28.f64)));
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
loc_821F71E8:
	// fmuls f1,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_821F71EC:
	// addi r3,r25,20
	ctx.r3.s64 = r25.s64 + 20;
	// bl 0x821f69e0
	ctx.lr = 0x821F71F4;
	sub_821F69E0(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba1c
	ctx.lr = 0x821F7200;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821F7204"))) PPC_WEAK_FUNC(sub_821F7204);
PPC_FUNC_IMPL(__imp__sub_821F7204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7208"))) PPC_WEAK_FUNC(sub_821F7208);
PPC_FUNC_IMPL(__imp__sub_821F7208) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r5,117(r31)
	PPC_STORE_U8(r31.u32 + 117, ctx.r5.u8);
	// beq cr6,0x821f727c
	if (cr6.eq) goto loc_821F727C;
	// bl 0x821f6d60
	ctx.lr = 0x821F7230;
	sub_821F6D60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f727c
	if (cr6.eq) goto loc_821F727C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821f6b98
	ctx.lr = 0x821F7260;
	sub_821F6B98(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,119(r31)
	PPC_STORE_U8(r31.u32 + 119, ctx.r9.u8);
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
loc_821F727C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,119(r31)
	PPC_STORE_U8(r31.u32 + 119, r11.u8);
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

__attribute__((alias("__imp__sub_821F7298"))) PPC_WEAK_FUNC(sub_821F7298);
PPC_FUNC_IMPL(__imp__sub_821F7298) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// addi r10,r11,-22760
	ctx.r10.s64 = r11.s64 + -22760;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x821F72C8;
	sub_82130000(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,29936
	ctx.r7.s64 = ctx.r9.s64 + 29936;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x821f72ec
	if (cr6.eq) goto loc_821F72EC;
	// bl 0x82162698
	ctx.lr = 0x821F72E8;
	sub_82162698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F72EC:
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

__attribute__((alias("__imp__sub_821F7304"))) PPC_WEAK_FUNC(sub_821F7304);
PPC_FUNC_IMPL(__imp__sub_821F7304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7308"))) PPC_WEAK_FUNC(sub_821F7308);
PPC_FUNC_IMPL(__imp__sub_821F7308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// li r11,0
	r11.s64 = 0;
	// li r9,8
	ctx.r9.s64 = 8;
	// clrlwi r8,r10,25
	ctx.r8.u64 = ctx.r10.u32 & 0x7F;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stb r8,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7334"))) PPC_WEAK_FUNC(sub_821F7334);
PPC_FUNC_IMPL(__imp__sub_821F7334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7338"))) PPC_WEAK_FUNC(sub_821F7338);
PPC_FUNC_IMPL(__imp__sub_821F7338) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f735c
	if (cr6.eq) goto loc_821F735C;
	// bl 0x82130588
	ctx.lr = 0x821F735C;
	sub_82130588(ctx, base);
loc_821F735C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_821F7378"))) PPC_WEAK_FUNC(sub_821F7378);
PPC_FUNC_IMPL(__imp__sub_821F7378) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// li r10,0
	ctx.r10.s64 = 0;
loc_821F738C:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821f738c
	if (cr6.lt) goto loc_821F738C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F73AC"))) PPC_WEAK_FUNC(sub_821F73AC);
PPC_FUNC_IMPL(__imp__sub_821F73AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F73B0"))) PPC_WEAK_FUNC(sub_821F73B0);
PPC_FUNC_IMPL(__imp__sub_821F73B0) {
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
	ctx.lr = 0x821F73B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f7438
	if (!cr6.gt) goto loc_821F7438;
loc_821F73D4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x821f7428
	if (!cr6.gt) goto loc_821F7428;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_821F73E8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x82145020
	ctx.lr = 0x821F73F8;
	sub_82145020(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stwx r8,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r8.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r9,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u32);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r29,r6
	cr6.compare<int32_t>(r29.s32, ctx.r6.s32, xer);
	// blt cr6,0x821f73e8
	if (cr6.lt) goto loc_821F73E8;
loc_821F7428:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x821f73d4
	if (cr6.lt) goto loc_821F73D4;
loc_821F7438:
	// stw r27,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821F7444"))) PPC_WEAK_FUNC(sub_821F7444);
PPC_FUNC_IMPL(__imp__sub_821F7444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7448"))) PPC_WEAK_FUNC(sub_821F7448);
PPC_FUNC_IMPL(__imp__sub_821F7448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// twllei r10,0
	// divw r7,r9,r10
	ctx.r7.s32 = ctx.r9.s32 / ctx.r10.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r6,r7,r10
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// andc r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r4.u64;
	// twlgei r10,-1
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7488"))) PPC_WEAK_FUNC(sub_821F7488);
PPC_FUNC_IMPL(__imp__sub_821F7488) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bge 0x821f74a4
	if (!cr0.lt) goto loc_821F74A4;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_821F74A4:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F74B8"))) PPC_WEAK_FUNC(sub_821F74B8);
PPC_FUNC_IMPL(__imp__sub_821F74B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x821f74cc
	if (!cr6.eq) goto loc_821F74CC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// b 0x821f74d0
	goto loc_821F74D0;
loc_821F74CC:
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
loc_821F74D0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821f7500
	if (!cr6.gt) goto loc_821F7500;
	// li r10,0
	ctx.r10.s64 = 0;
loc_821F74E4:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821f74e4
	if (cr6.lt) goto loc_821F74E4;
loc_821F7500:
	// lbz r11,20(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821f73b0
	sub_821F73B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F7514"))) PPC_WEAK_FUNC(sub_821F7514);
PPC_FUNC_IMPL(__imp__sub_821F7514) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7518"))) PPC_WEAK_FUNC(sub_821F7518);
PPC_FUNC_IMPL(__imp__sub_821F7518) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_821F752C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x821f7550
	if (cr6.eq) goto loc_821F7550;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x821f752c
	if (cr6.lt) goto loc_821F752C;
	// blr 
	return;
loc_821F7550:
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7558"))) PPC_WEAK_FUNC(sub_821F7558);
PPC_FUNC_IMPL(__imp__sub_821F7558) {
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
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// rlwimi r11,r5,7,17,24
	r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// ble cr6,0x821f7598
	if (!cr6.gt) goto loc_821F7598;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821F7598:
	// bl 0x82130528
	ctx.lr = 0x821F759C;
	sub_82130528(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x821f75d0
	if (!cr6.gt) goto loc_821F75D0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_821F75B4:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x821f75b4
	if (cr6.lt) goto loc_821F75B4;
loc_821F75D0:
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821f75e8
	if (cr6.eq) goto loc_821F75E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f73b0
	ctx.lr = 0x821F75E8;
	sub_821F73B0(ctx, base);
loc_821F75E8:
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

__attribute__((alias("__imp__sub_821F75FC"))) PPC_WEAK_FUNC(sub_821F75FC);
PPC_FUNC_IMPL(__imp__sub_821F75FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7600"))) PPC_WEAK_FUNC(sub_821F7600);
PPC_FUNC_IMPL(__imp__sub_821F7600) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-21868
	ctx.r9.s64 = r11.s64 + -21868;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x821f7634
	if (cr6.eq) goto loc_821F7634;
	// bl 0x82130588
	ctx.lr = 0x821F7630;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F7634:
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

__attribute__((alias("__imp__sub_821F7648"))) PPC_WEAK_FUNC(sub_821F7648);
PPC_FUNC_IMPL(__imp__sub_821F7648) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// beq cr6,0x821f768c
	if (cr6.eq) goto loc_821F768C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F768C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F768C:
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

__attribute__((alias("__imp__sub_821F76B0"))) PPC_WEAK_FUNC(sub_821F76B0);
PPC_FUNC_IMPL(__imp__sub_821F76B0) {
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
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stb r30,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r30.u8);
	// bl 0x824e6310
	ctx.lr = 0x821F76DC;
	sub_824E6310(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x824e0a58
	ctx.lr = 0x821F76E4;
	sub_824E0A58(ctx, base);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ce080
	ctx.lr = 0x821F76F0;
	sub_821CE080(ctx, base);
	// stw r30,644(r31)
	PPC_STORE_U32(r31.u32 + 644, r30.u32);
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

__attribute__((alias("__imp__sub_821F770C"))) PPC_WEAK_FUNC(sub_821F770C);
PPC_FUNC_IMPL(__imp__sub_821F770C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7710"))) PPC_WEAK_FUNC(sub_821F7710);
PPC_FUNC_IMPL(__imp__sub_821F7710) {
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
	ctx.lr = 0x821F7718;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r3,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.r3.u64);
	// std r4,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r4.u64);
	// std r5,224(r1)
	PPC_STORE_U64(ctx.r1.u32 + 224, ctx.r5.u64);
	// std r6,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r6.u64);
	// std r7,240(r1)
	PPC_STORE_U64(ctx.r1.u32 + 240, ctx.r7.u64);
	// std r8,248(r1)
	PPC_STORE_U64(ctx.r1.u32 + 248, ctx.r8.u64);
	// bl 0x82178880
	ctx.lr = 0x821F7738;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f7750
	if (cr6.eq) goto loc_821F7750;
	// li r25,256
	r25.s64 = 256;
	// li r24,256
	r24.s64 = 256;
	// b 0x821f7758
	goto loc_821F7758;
loc_821F7750:
	// li r25,128
	r25.s64 = 128;
	// li r24,128
	r24.s64 = 128;
loc_821F7758:
	// li r30,0
	r30.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// li r11,4
	r11.s64 = 4;
	// stw r30,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r30.u32);
	// stb r30,216(r1)
	PPC_STORE_U8(ctx.r1.u32 + 216, r30.u8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stb r29,226(r1)
	PPC_STORE_U8(ctx.r1.u32 + 226, r29.u8);
	// stw r29,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, r29.u32);
	// stw r11,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r11.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e4c18
	ctx.lr = 0x821F7784;
	sub_822E4C18(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r28,r11,-10324
	r28.s64 = r11.s64 + -10324;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r28
	r31.u64 = r28.u64;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// stw r3,-10308(r23)
	PPC_STORE_U32(r23.u32 + -10308, ctx.r3.u32);
	// addi r27,r11,-21848
	r27.s64 = r11.s64 + -21848;
	// b 0x821f77ac
	goto loc_821F77AC;
loc_821F77A8:
	// lwz r3,-10308(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10308);
loc_821F77AC:
	// stw r3,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r3.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r29,216(r1)
	PPC_STORE_U8(ctx.r1.u32 + 216, r29.u8);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stb r29,226(r1)
	PPC_STORE_U8(ctx.r1.u32 + 226, r29.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x821F77C8;
	sub_823DC018(ctx, base);
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F77F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r9,r28,12
	ctx.r9.s64 = r28.s64 + 12;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x821f77a8
	if (cr6.lt) goto loc_821F77A8;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821F7814"))) PPC_WEAK_FUNC(sub_821F7814);
PPC_FUNC_IMPL(__imp__sub_821F7814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7818"))) PPC_WEAK_FUNC(sub_821F7818);
PPC_FUNC_IMPL(__imp__sub_821F7818) {
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
	ctx.lr = 0x821F7820;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r25,0
	r25.s64 = 0;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lwz r11,-10308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f7888
	if (cr6.eq) goto loc_821F7888;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// addi r4,r11,-21824
	ctx.r4.s64 = r11.s64 + -21824;
	// bl 0x82181530
	ctx.lr = 0x821F784C;
	sub_82181530(ctx, base);
	// lwz r30,-10308(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10308);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821F7858;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821f7880
	if (!cr6.eq) goto loc_821F7880;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f7880
	if (cr6.eq) goto loc_821F7880;
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
	ctx.lr = 0x821F7880;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F7880:
	// mr r11,r25
	r11.u64 = r25.u64;
	// stw r11,-10308(r31)
	PPC_STORE_U32(r31.u32 + -10308, r11.u32);
loc_821F7888:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r25
	r29.u64 = r25.u64;
	// addi r27,r11,-10324
	r27.s64 = r11.s64 + -10324;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r27
	r31.u64 = r27.u64;
	// addi r28,r11,-21848
	r28.s64 = r11.s64 + -21848;
loc_821F78A0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f7900
	if (cr6.eq) goto loc_821F7900;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x821F78BC;
	sub_823DC018(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// bl 0x82181530
	ctx.lr = 0x821F78C8;
	sub_82181530(ctx, base);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821F78D4;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821f78fc
	if (!cr6.eq) goto loc_821F78FC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821f78fc
	if (cr6.eq) goto loc_821F78FC;
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
	ctx.lr = 0x821F78FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F78FC:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_821F7900:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r27,12
	r11.s64 = r27.s64 + 12;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x821f78a0
	if (cr6.lt) goto loc_821F78A0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821F791C"))) PPC_WEAK_FUNC(sub_821F791C);
PPC_FUNC_IMPL(__imp__sub_821F791C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7920"))) PPC_WEAK_FUNC(sub_821F7920);
PPC_FUNC_IMPL(__imp__sub_821F7920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x821F7928;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r10,-21720
	r31.s64 = ctx.r10.s64 + -21720;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F7960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r27,-32111
	r27.s64 = -2104426496;
	// li r30,0
	r30.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,-22052(r27)
	PPC_STORE_U32(r27.u32 + -22052, ctx.r3.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821F799C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-22052(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -22052);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-21728
	ctx.r4.s64 = ctx.r10.s64 + -21728;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x821F79B4;
	sub_8218A568(ctx, base);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r11,-22052(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -22052);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-27772
	ctx.r4.s64 = ctx.r8.s64 + -27772;
	// stw r3,-22624(r9)
	PPC_STORE_U32(ctx.r9.u32 + -22624, ctx.r3.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x821F79D4;
	sub_8218B688(ctx, base);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// stw r3,-23148(r7)
	PPC_STORE_U32(ctx.r7.u32 + -23148, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82180430
	ctx.lr = 0x821F79E8;
	sub_82180430(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stb r30,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r30.u8);
	// lis r27,-32120
	r27.s64 = -2105016320;
	// stb r31,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, r31.u8);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stb r31,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r31.u8);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x821F7A14;
	sub_822E50B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822e5048
	ctx.lr = 0x821F7A28;
	sub_822E5048(ctx, base);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r4,r5,-21752
	ctx.r4.s64 = ctx.r5.s64 + -21752;
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// li r7,220
	ctx.r7.s64 = 220;
	// li r6,220
	ctx.r6.s64 = 220;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7A5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r25,-32111
	r25.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// stw r11,-22076(r25)
	PPC_STORE_U32(r25.u32 + -22076, r11.u32);
	// bl 0x822e50b8
	ctx.lr = 0x821F7A70;
	sub_822E50B8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x822e5048
	ctx.lr = 0x821F7A84;
	sub_822E5048(ctx, base);
	// stb r30,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, r30.u8);
	// lis r24,-32111
	r24.s64 = -2104426496;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stb r30,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r30.u8);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r4,r8,-21772
	ctx.r4.s64 = ctx.r8.s64 + -21772;
	// stw r11,-22088(r24)
	PPC_STORE_U32(r24.u32 + -22088, r11.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,256
	ctx.r7.s64 = 256;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,-22076(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -22076);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stb r31,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r31.u8);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stb r31,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, r31.u8);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,-22080(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22080, r11.u32);
	// bl 0x822e50b8
	ctx.lr = 0x821F7AF0;
	sub_822E50B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x822e5048
	ctx.lr = 0x821F7B04;
	sub_822E5048(ctx, base);
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r30,r7,-21784
	r30.s64 = ctx.r7.s64 + -21784;
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,220
	ctx.r7.s64 = 220;
	// li r6,220
	ctx.r6.s64 = 220;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r28,-32111
	r28.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// stw r11,-22072(r28)
	PPC_STORE_U32(r28.u32 + -22072, r11.u32);
	// bl 0x822e50b8
	ctx.lr = 0x821F7B4C;
	sub_822E50B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x822e5048
	ctx.lr = 0x821F7B60;
	sub_822E5048(ctx, base);
	// lwz r11,-22088(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -22088);
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,430
	ctx.r7.s64 = 430;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r6,749
	ctx.r6.s64 = 749;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// stb r31,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r31.u8);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stb r31,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, r31.u8);
	// stw r11,-22092(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22092, r11.u32);
	// addi r4,r7,-21796
	ctx.r4.s64 = ctx.r7.s64 + -21796;
	// stw r11,-22068(r29)
	PPC_STORE_U32(r29.u32 + -22068, r11.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,256
	ctx.r7.s64 = 256;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7BE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r5,-22072(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + -22072);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// addi r4,r8,-21808
	ctx.r4.s64 = ctx.r8.s64 + -21808;
	// stw r11,-22084(r9)
	PPC_STORE_U32(ctx.r9.u32 + -22084, r11.u32);
	// bl 0x82182150
	ctx.lr = 0x821F7C04;
	sub_82182150(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,-22068(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -22068);
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x821F7C14;
	sub_82182150(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821F7C1C"))) PPC_WEAK_FUNC(sub_821F7C1C);
PPC_FUNC_IMPL(__imp__sub_821F7C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7C20"))) PPC_WEAK_FUNC(sub_821F7C20);
PPC_FUNC_IMPL(__imp__sub_821F7C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// lfs f13,10660(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10660);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x821f7c74
	if (!cr6.gt) goto loc_821F7C74;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21704
	ctx.r4.s64 = ctx.r10.s64 + -21704;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x821F7C54;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F7C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821f7c78
	if (!cr6.eq) goto loc_821F7C78;
loc_821F7C74:
	// li r11,0
	r11.s64 = 0;
loc_821F7C78:
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

__attribute__((alias("__imp__sub_821F7C8C"))) PPC_WEAK_FUNC(sub_821F7C8C);
PPC_FUNC_IMPL(__imp__sub_821F7C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7C90"))) PPC_WEAK_FUNC(sub_821F7C90);
PPC_FUNC_IMPL(__imp__sub_821F7C90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// ori r10,r10,4944
	ctx.r10.u64 = ctx.r10.u64 | 4944;
	// lbzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7CA4"))) PPC_WEAK_FUNC(sub_821F7CA4);
PPC_FUNC_IMPL(__imp__sub_821F7CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7CA8"))) PPC_WEAK_FUNC(sub_821F7CA8);
PPC_FUNC_IMPL(__imp__sub_821F7CA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// lbz r3,10640(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 10640);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7CB4"))) PPC_WEAK_FUNC(sub_821F7CB4);
PPC_FUNC_IMPL(__imp__sub_821F7CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7CB8"))) PPC_WEAK_FUNC(sub_821F7CB8);
PPC_FUNC_IMPL(__imp__sub_821F7CB8) {
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
	// bl 0x82203a78
	ctx.lr = 0x821F7CD4;
	sub_82203A78(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// stw r31,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r31.u32);
	// bl 0x8223d5f8
	ctx.lr = 0x821F7CE0;
	sub_8223D5F8(ctx, base);
	// stw r31,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r31.u32);
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

__attribute__((alias("__imp__sub_821F7CFC"))) PPC_WEAK_FUNC(sub_821F7CFC);
PPC_FUNC_IMPL(__imp__sub_821F7CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7D00"))) PPC_WEAK_FUNC(sub_821F7D00);
PPC_FUNC_IMPL(__imp__sub_821F7D00) {
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
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f7d54
	if (cr6.eq) goto loc_821F7D54;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f7d54
	if (cr6.eq) goto loc_821F7D54;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7D54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F7D54:
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

__attribute__((alias("__imp__sub_821F7D68"))) PPC_WEAK_FUNC(sub_821F7D68);
PPC_FUNC_IMPL(__imp__sub_821F7D68) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,10736
	ctx.r3.s64 = ctx.r3.s64 + 10736;
	// b 0x82213fb8
	sub_82213FB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F7D70"))) PPC_WEAK_FUNC(sub_821F7D70);
PPC_FUNC_IMPL(__imp__sub_821F7D70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r9,r9,-21652
	ctx.r9.s64 = ctx.r9.s64 + -21652;
loc_821F7D80:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x821f7da4
	if (cr6.eq) goto loc_821F7DA4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x821f7d80
	if (cr6.eq) goto loc_821F7D80;
loc_821F7DA4:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x821f7db4
	if (!cr6.eq) goto loc_821F7DB4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821F7DB4:
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r9,r9,-21664
	ctx.r9.s64 = ctx.r9.s64 + -21664;
loc_821F7DC0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// beq cr6,0x821f7de4
	if (cr6.eq) goto loc_821F7DE4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x821f7dc0
	if (cr6.eq) goto loc_821F7DC0;
loc_821F7DE4:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x821f7df4
	if (!cr6.eq) goto loc_821F7DF4;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_821F7DF4:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r10,r10,-21676
	ctx.r10.s64 = ctx.r10.s64 + -21676;
loc_821F7DFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821f7e20
	if (cr6.eq) goto loc_821F7E20;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821f7dfc
	if (cr6.eq) goto loc_821F7DFC;
loc_821F7E20:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F7E34"))) PPC_WEAK_FUNC(sub_821F7E34);
PPC_FUNC_IMPL(__imp__sub_821F7E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7E38"))) PPC_WEAK_FUNC(sub_821F7E38);
PPC_FUNC_IMPL(__imp__sub_821F7E38) {
	PPC_FUNC_PROLOGUE();
	// b 0x82216168
	sub_82216168(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F7E3C"))) PPC_WEAK_FUNC(sub_821F7E3C);
PPC_FUNC_IMPL(__imp__sub_821F7E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F7E40"))) PPC_WEAK_FUNC(sub_821F7E40);
PPC_FUNC_IMPL(__imp__sub_821F7E40) {
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
	ctx.lr = 0x821F7E48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r11,10000
	r11.s64 = 10000;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r29,r30
	r29.u64 = r30.u64;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stb r10,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r10.u8);
	// stb r30,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r30.u8);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
	// stb r30,15(r31)
	PPC_STORE_U8(r31.u32 + 15, r30.u8);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// bl 0x82387860
	ctx.lr = 0x821F7E80;
	sub_82387860(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// beq cr6,0x821f7e9c
	if (cr6.eq) goto loc_821F7E9C;
	// bl 0x82387860
	ctx.lr = 0x821F7E90;
	sub_82387860(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x821f7ee4
	if (!cr6.eq) goto loc_821F7EE4;
loc_821F7E9C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821F7EA4;
	sub_82387928(ctx, base);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// bne cr6,0x821f7ec8
	if (!cr6.eq) goto loc_821F7EC8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-21572
	ctx.r3.s64 = r11.s64 + -21572;
	// bl 0x82720750
	ctx.lr = 0x821F7EB8;
	sub_82720750(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821f7f34
	if (!cr6.eq) goto loc_821F7F34;
	// li r29,1
	r29.s64 = 1;
loc_821F7EC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f7f34
	if (!cr6.eq) goto loc_821F7F34;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-21596
	ctx.r3.s64 = r11.s64 + -21596;
	// bl 0x82720750
	ctx.lr = 0x821F7EE0;
	sub_82720750(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_821F7EE4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f7f34
	if (!cr6.eq) goto loc_821F7F34;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821F7EF8;
	sub_82387928(ctx, base);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// bne cr6,0x821f7f18
	if (!cr6.eq) goto loc_821F7F18;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-21620
	ctx.r3.s64 = r11.s64 + -21620;
	// bl 0x82720750
	ctx.lr = 0x821F7F0C;
	sub_82720750(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// rlwinm r29,r10,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_821F7F18:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821f7f34
	if (!cr6.eq) goto loc_821F7F34;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-21640
	ctx.r3.s64 = r11.s64 + -21640;
	// bl 0x82720750
	ctx.lr = 0x821F7F30;
	sub_82720750(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_821F7F34:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f7f5c
	if (cr6.eq) goto loc_821F7F5C;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r11,1
	r11.s64 = 1;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// stb r11,-6746(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6746, r11.u8);
	// bl 0x82387928
	ctx.lr = 0x821F7F54;
	sub_82387928(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// stw r3,-6752(r9)
	PPC_STORE_U32(ctx.r9.u32 + -6752, ctx.r3.u32);
loc_821F7F5C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f7fac
	if (cr6.eq) goto loc_821F7FAC;
	// li r3,304
	ctx.r3.s64 = 304;
	// bl 0x82130528
	ctx.lr = 0x821F7F70;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f7fa4
	if (cr6.eq) goto loc_821F7FA4;
	// li r9,5000
	ctx.r9.s64 = 5000;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,100
	ctx.r8.s64 = 100;
	// li r7,100
	ctx.r7.s64 = 100;
	// li r6,100
	ctx.r6.s64 = 100;
	// li r5,500
	ctx.r5.s64 = 500;
	// bl 0x825eeb40
	ctx.lr = 0x821F7F94;
	sub_825EEB40(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_821F7FA4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_821F7FAC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F7FB8"))) PPC_WEAK_FUNC(sub_821F7FB8);
PPC_FUNC_IMPL(__imp__sub_821F7FB8) {
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
	ctx.lr = 0x821F7FC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x821F7FD0;
	sub_8217D9A0(ctx, base);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f7ff0
	if (cr6.eq) goto loc_821F7FF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F7FF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F7FF0:
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,40
	r31.s64 = 40;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// beq cr6,0x821f8024
	if (cr6.eq) goto loc_821F8024;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F8024:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F8038"))) PPC_WEAK_FUNC(sub_821F8038);
PPC_FUNC_IMPL(__imp__sub_821F8038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821F8090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x821F80B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F80D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387860
	ctx.lr = 0x821F80D4;
	sub_82387860(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// beq cr6,0x821f8110
	if (cr6.eq) goto loc_821F8110;
	// bl 0x82387860
	ctx.lr = 0x821F80E4;
	sub_82387860(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x821f8110
	if (cr6.eq) goto loc_821F8110;
	// bl 0x82178848
	ctx.lr = 0x821F80F4;
	sub_82178848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r10,-21512
	ctx.r4.s64 = ctx.r10.s64 + -21512;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// b 0x821f811c
	goto loc_821F811C;
loc_821F8110:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-21512
	ctx.r4.s64 = r11.s64 + -21512;
loc_821F811C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x825ee0e0
	ctx.lr = 0x821F8124;
	sub_825EE0E0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x821F812C;
	sub_82387928(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r11,-21520
	ctx.r4.s64 = r11.s64 + -21520;
	// bl 0x825ee0e0
	ctx.lr = 0x821F8140;
	sub_825EE0E0(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r9,-21528
	ctx.r4.s64 = ctx.r9.s64 + -21528;
	// lwz r5,-6756(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6756);
	// bl 0x825ee0e0
	ctx.lr = 0x821F8158;
	sub_825EE0E0(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-21540
	ctx.r4.s64 = ctx.r8.s64 + -21540;
	// bl 0x825ee0e0
	ctx.lr = 0x821F816C;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_821F8184"))) PPC_WEAK_FUNC(sub_821F8184);
PPC_FUNC_IMPL(__imp__sub_821F8184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8188"))) PPC_WEAK_FUNC(sub_821F8188);
PPC_FUNC_IMPL(__imp__sub_821F8188) {
	PPC_FUNC_PROLOGUE();
	// stb r4,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8190"))) PPC_WEAK_FUNC(sub_821F8190);
PPC_FUNC_IMPL(__imp__sub_821F8190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F819C"))) PPC_WEAK_FUNC(sub_821F819C);
PPC_FUNC_IMPL(__imp__sub_821F819C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F81A0"))) PPC_WEAK_FUNC(sub_821F81A0);
PPC_FUNC_IMPL(__imp__sub_821F81A0) {
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
	// lwz r11,1544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bne cr6,0x821f81d8
	if (!cr6.eq) goto loc_821F81D8;
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
loc_821F81D8:
	// lwz r11,1536(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1536);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1536(r31)
	PPC_STORE_U32(r31.u32 + 1536, r11.u32);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bne cr6,0x821f81f4
	if (!cr6.eq) goto loc_821F81F4;
	// li r11,0
	r11.s64 = 0;
	// stw r11,1536(r31)
	PPC_STORE_U32(r31.u32 + 1536, r11.u32);
loc_821F81F4:
	// lwz r11,1536(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1536);
	// li r5,96
	ctx.r5.s64 = 96;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x821F8210;
	sub_823DA950(ctx, base);
	// lwz r11,1544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821F8234"))) PPC_WEAK_FUNC(sub_821F8234);
PPC_FUNC_IMPL(__imp__sub_821F8234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8238"))) PPC_WEAK_FUNC(sub_821F8238);
PPC_FUNC_IMPL(__imp__sub_821F8238) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-21500
	ctx.r9.s64 = r11.s64 + -21500;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x821f826c
	if (cr6.eq) goto loc_821F826C;
	// bl 0x82130588
	ctx.lr = 0x821F8268;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F826C:
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

__attribute__((alias("__imp__sub_821F8280"))) PPC_WEAK_FUNC(sub_821F8280);
PPC_FUNC_IMPL(__imp__sub_821F8280) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-21492
	ctx.r10.s64 = r11.s64 + -21492;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822187e0
	ctx.lr = 0x821F82AC;
	sub_822187E0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f82c4
	if (cr6.eq) goto loc_821F82C4;
	// bl 0x82130588
	ctx.lr = 0x821F82C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F82C4:
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

__attribute__((alias("__imp__sub_821F82DC"))) PPC_WEAK_FUNC(sub_821F82DC);
PPC_FUNC_IMPL(__imp__sub_821F82DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F82E0"))) PPC_WEAK_FUNC(sub_821F82E0);
PPC_FUNC_IMPL(__imp__sub_821F82E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// bl 0x826337a8
	ctx.lr = 0x821F8308;
	sub_826337A8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,32639
	ctx.r10.s64 = 2139029504;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,-21484
	ctx.r7.s64 = r11.s64 + -21484;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r10,32767
	ctx.r5.u64 = ctx.r10.u64 | 32767;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// stw r6,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r6.u32);
	// stw r5,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r5.u32);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stw r4,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r4.u32);
	// stfs f31,192(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// li r3,992
	ctx.r3.s64 = 992;
	// stfs f29,196(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f31,200(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// stfs f30,204(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x821F8358;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821f8368
	if (cr6.eq) goto loc_821F8368;
	// bl 0x8217d5e8
	ctx.lr = 0x821F8364;
	sub_8217D5E8(ctx, base);
	// b 0x821f836c
	goto loc_821F836C;
loc_821F8368:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821F836C:
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// bl 0x8217d098
	ctx.lr = 0x821F8374;
	sub_8217D098(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// fmr f6,f30
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = f30.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r9,r11,45
	ctx.r9.s64 = r11.s64 + 45;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r6,692(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 692);
	// lfs f13,648(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 648);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,688(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 688);
	// lfs f0,652(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 652);
	f0.f64 = double(temp.f32);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f2,f7,f0
	ctx.f2.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f3,f8,f13
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fctiwz f13,f2
	ctx.f13.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f3,f9
	ctx.f3.f64 = double(float(ctx.f9.f64));
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// bl 0x8217cc80
	ctx.lr = 0x821F8428;
	sub_8217CC80(ctx, base);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,2256
	ctx.r4.s64 = ctx.r6.s64 + 2256;
	// bl 0x8262fec8
	ctx.lr = 0x821F8438;
	sub_8262FEC8(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r11,80
	r11.s64 = 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,31016(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_821F8480"))) PPC_WEAK_FUNC(sub_821F8480);
PPC_FUNC_IMPL(__imp__sub_821F8480) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821F849C"))) PPC_WEAK_FUNC(sub_821F849C);
PPC_FUNC_IMPL(__imp__sub_821F849C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F84A0"))) PPC_WEAK_FUNC(sub_821F84A0);
PPC_FUNC_IMPL(__imp__sub_821F84A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
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

__attribute__((alias("__imp__sub_821F84B0"))) PPC_WEAK_FUNC(sub_821F84B0);
PPC_FUNC_IMPL(__imp__sub_821F84B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821F84C0"))) PPC_WEAK_FUNC(sub_821F84C0);
PPC_FUNC_IMPL(__imp__sub_821F84C0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8268cea8
	sub_8268CEA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F84C4"))) PPC_WEAK_FUNC(sub_821F84C4);
PPC_FUNC_IMPL(__imp__sub_821F84C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F84C8"))) PPC_WEAK_FUNC(sub_821F84C8);
PPC_FUNC_IMPL(__imp__sub_821F84C8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8268d180
	sub_8268D180(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F84CC"))) PPC_WEAK_FUNC(sub_821F84CC);
PPC_FUNC_IMPL(__imp__sub_821F84CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F84D0"))) PPC_WEAK_FUNC(sub_821F84D0);
PPC_FUNC_IMPL(__imp__sub_821F84D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F84E0"))) PPC_WEAK_FUNC(sub_821F84E0);
PPC_FUNC_IMPL(__imp__sub_821F84E0) {
	PPC_FUNC_PROLOGUE();
	// stb r4,65(r3)
	PPC_STORE_U8(ctx.r3.u32 + 65, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F84E8"))) PPC_WEAK_FUNC(sub_821F84E8);
PPC_FUNC_IMPL(__imp__sub_821F84E8) {
	PPC_FUNC_PROLOGUE();
	// stb r4,66(r3)
	PPC_STORE_U8(ctx.r3.u32 + 66, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F84F0"))) PPC_WEAK_FUNC(sub_821F84F0);
PPC_FUNC_IMPL(__imp__sub_821F84F0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,64(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F84F8"))) PPC_WEAK_FUNC(sub_821F84F8);
PPC_FUNC_IMPL(__imp__sub_821F84F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F850C"))) PPC_WEAK_FUNC(sub_821F850C);
PPC_FUNC_IMPL(__imp__sub_821F850C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8510"))) PPC_WEAK_FUNC(sub_821F8510);
PPC_FUNC_IMPL(__imp__sub_821F8510) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f854c
	if (cr6.eq) goto loc_821F854C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821f8570
	if (cr6.eq) goto loc_821F8570;
loc_821F854C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x821f8574
	if (!cr6.eq) goto loc_821F8574;
loc_821F8570:
	// li r11,0
	r11.s64 = 0;
loc_821F8574:
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

__attribute__((alias("__imp__sub_821F858C"))) PPC_WEAK_FUNC(sub_821F858C);
PPC_FUNC_IMPL(__imp__sub_821F858C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8590"))) PPC_WEAK_FUNC(sub_821F8590);
PPC_FUNC_IMPL(__imp__sub_821F8590) {
	PPC_FUNC_PROLOGUE();
	// stw r4,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8598"))) PPC_WEAK_FUNC(sub_821F8598);
PPC_FUNC_IMPL(__imp__sub_821F8598) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F85A0"))) PPC_WEAK_FUNC(sub_821F85A0);
PPC_FUNC_IMPL(__imp__sub_821F85A0) {
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
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lbz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x821f85dc
	if (cr6.eq) goto loc_821F85DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F85DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F85DC:
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
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

__attribute__((alias("__imp__sub_821F85F8"))) PPC_WEAK_FUNC(sub_821F85F8);
PPC_FUNC_IMPL(__imp__sub_821F85F8) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,100(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 100);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8600"))) PPC_WEAK_FUNC(sub_821F8600);
PPC_FUNC_IMPL(__imp__sub_821F8600) {
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
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lbz r10,101(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x821f863c
	if (cr6.eq) goto loc_821F863C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F863C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F863C:
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
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

__attribute__((alias("__imp__sub_821F8658"))) PPC_WEAK_FUNC(sub_821F8658);
PPC_FUNC_IMPL(__imp__sub_821F8658) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,101(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 101);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8660"))) PPC_WEAK_FUNC(sub_821F8660);
PPC_FUNC_IMPL(__imp__sub_821F8660) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8668"))) PPC_WEAK_FUNC(sub_821F8668);
PPC_FUNC_IMPL(__imp__sub_821F8668) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,102(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 102);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8670"))) PPC_WEAK_FUNC(sub_821F8670);
PPC_FUNC_IMPL(__imp__sub_821F8670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-20836
	ctx.r3.s64 = r11.s64 + -20836;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F867C"))) PPC_WEAK_FUNC(sub_821F867C);
PPC_FUNC_IMPL(__imp__sub_821F867C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8680"))) PPC_WEAK_FUNC(sub_821F8680);
PPC_FUNC_IMPL(__imp__sub_821F8680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-20828
	ctx.r3.s64 = r11.s64 + -20828;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F868C"))) PPC_WEAK_FUNC(sub_821F868C);
PPC_FUNC_IMPL(__imp__sub_821F868C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8690"))) PPC_WEAK_FUNC(sub_821F8690);
PPC_FUNC_IMPL(__imp__sub_821F8690) {
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
	// bl 0x8263f330
	ctx.lr = 0x821F86A8;
	sub_8263F330(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r7,r11,-20156
	ctx.r7.s64 = r11.s64 + -20156;
	// addi r6,r10,-20196
	ctx.r6.s64 = ctx.r10.s64 + -20196;
	// addi r5,r9,-20756
	ctx.r5.s64 = ctx.r9.s64 + -20756;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r4,r8,-20776
	ctx.r4.s64 = ctx.r8.s64 + -20776;
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// stw r5,456(r31)
	PPC_STORE_U32(r31.u32 + 456, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_821F86F0"))) PPC_WEAK_FUNC(sub_821F86F0);
PPC_FUNC_IMPL(__imp__sub_821F86F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,52(r3)
	PPC_STORE_U8(ctx.r3.u32 + 52, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F86FC"))) PPC_WEAK_FUNC(sub_821F86FC);
PPC_FUNC_IMPL(__imp__sub_821F86FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821F8700"))) PPC_WEAK_FUNC(sub_821F8700);
PPC_FUNC_IMPL(__imp__sub_821F8700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,384(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 384);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821F8710"))) PPC_WEAK_FUNC(sub_821F8710);
PPC_FUNC_IMPL(__imp__sub_821F8710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,388(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 388);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821F8720"))) PPC_WEAK_FUNC(sub_821F8720);
PPC_FUNC_IMPL(__imp__sub_821F8720) {
	PPC_FUNC_PROLOGUE();
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8728"))) PPC_WEAK_FUNC(sub_821F8728);
PPC_FUNC_IMPL(__imp__sub_821F8728) {
	PPC_FUNC_PROLOGUE();
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8730"))) PPC_WEAK_FUNC(sub_821F8730);
PPC_FUNC_IMPL(__imp__sub_821F8730) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8738"))) PPC_WEAK_FUNC(sub_821F8738);
PPC_FUNC_IMPL(__imp__sub_821F8738) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821F8740"))) PPC_WEAK_FUNC(sub_821F8740);
PPC_FUNC_IMPL(__imp__sub_821F8740) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r7,r11,-20156
	ctx.r7.s64 = r11.s64 + -20156;
	// addi r6,r10,-20196
	ctx.r6.s64 = ctx.r10.s64 + -20196;
	// addi r5,r9,-20756
	ctx.r5.s64 = ctx.r9.s64 + -20756;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r4,r8,-20776
	ctx.r4.s64 = ctx.r8.s64 + -20776;
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// stw r5,456(r31)
	PPC_STORE_U32(r31.u32 + 456, ctx.r5.u32);
	// stw r4,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r4.u32);
	// bl 0x8263f748
	ctx.lr = 0x821F8790;
	sub_8263F748(ctx, base);
	// clrlwi r3,r30,31
	ctx.r3.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x821f87a8
	if (cr6.eq) goto loc_821F87A8;
	// bl 0x82130588
	ctx.lr = 0x821F87A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_821F87A8:
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

__attribute__((alias("__imp__sub_821F87C0"))) PPC_WEAK_FUNC(sub_821F87C0);
PPC_FUNC_IMPL(__imp__sub_821F87C0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-456
	ctx.r3.s64 = ctx.r3.s64 + -456;
	// b 0x821f8740
	sub_821F8740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87C8"))) PPC_WEAK_FUNC(sub_821F87C8);
PPC_FUNC_IMPL(__imp__sub_821F87C8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-420
	ctx.r3.s64 = ctx.r3.s64 + -420;
	// b 0x8263cfd0
	sub_8263CFD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87D0"))) PPC_WEAK_FUNC(sub_821F87D0);
PPC_FUNC_IMPL(__imp__sub_821F87D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-456
	ctx.r3.s64 = ctx.r3.s64 + -456;
	// b 0x8263e4f0
	sub_8263E4F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87D8"))) PPC_WEAK_FUNC(sub_821F87D8);
PPC_FUNC_IMPL(__imp__sub_821F87D8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-36
	ctx.r3.s64 = ctx.r3.s64 + -36;
	// b 0x821f8740
	sub_821F8740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87E0"))) PPC_WEAK_FUNC(sub_821F87E0);
PPC_FUNC_IMPL(__imp__sub_821F87E0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-536
	ctx.r3.s64 = ctx.r3.s64 + -536;
	// b 0x821f8740
	sub_821F8740(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821F87E8"))) PPC_WEAK_FUNC(sub_821F87E8);
PPC_FUNC_IMPL(__imp__sub_821F87E8) {
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
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f8824
	if (cr6.eq) goto loc_821F8824;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8818;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x821f8828
	if (!cr6.eq) goto loc_821F8828;
loc_821F8824:
	// li r11,1
	r11.s64 = 1;
loc_821F8828:
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

__attribute__((alias("__imp__sub_821F8840"))) PPC_WEAK_FUNC(sub_821F8840);
PPC_FUNC_IMPL(__imp__sub_821F8840) {
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
	ctx.lr = 0x821F8848;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x824e6400
	ctx.lr = 0x821F886C;
	sub_824E6400(ctx, base);
	// addi r3,r30,68
	ctx.r3.s64 = r30.s64 + 68;
	// bl 0x824e6310
	ctx.lr = 0x821F8874;
	sub_824E6310(ctx, base);
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// bl 0x824e1c10
	ctx.lr = 0x821F887C;
	sub_824E1C10(ctx, base);
	// stw r29,648(r31)
	PPC_STORE_U32(r31.u32 + 648, r29.u32);
	// stw r29,652(r31)
	PPC_STORE_U32(r31.u32 + 652, r29.u32);
	// addi r3,r30,68
	ctx.r3.s64 = r30.s64 + 68;
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// stb r29,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r29.u8);
	// bl 0x824e6310
	ctx.lr = 0x821F8894;
	sub_824E6310(ctx, base);
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// bl 0x824e0a58
	ctx.lr = 0x821F889C;
	sub_824E0A58(ctx, base);
	// addi r3,r30,640
	ctx.r3.s64 = r30.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821ce080
	ctx.lr = 0x821F88A8;
	sub_821CE080(ctx, base);
	// stw r29,652(r31)
	PPC_STORE_U32(r31.u32 + 652, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F88B8"))) PPC_WEAK_FUNC(sub_821F88B8);
PPC_FUNC_IMPL(__imp__sub_821F88B8) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-20132
	ctx.r4.s64 = ctx.r10.s64 + -20132;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82691650
	ctx.lr = 0x821F88EC;
	sub_82691650(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821f8918
	if (cr6.eq) goto loc_821F8918;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F890C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x821f891c
	if (!cr6.eq) goto loc_821F891C;
loc_821F8918:
	// li r11,1
	r11.s64 = 1;
loc_821F891C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821f8948
	if (cr6.eq) goto loc_821F8948;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-20148
	ctx.r4.s64 = r11.s64 + -20148;
	// bl 0x82691650
	ctx.lr = 0x821F8938;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,268(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821F8948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821F8948:
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

__attribute__((alias("__imp__sub_821F8960"))) PPC_WEAK_FUNC(sub_821F8960);
PPC_FUNC_IMPL(__imp__sub_821F8960) {
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
	ctx.lr = 0x821F8968;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x821F897C;
	sub_82180430(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// li r31,1
	r31.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r31,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r31.u8);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r8,-20108
	ctx.r4.s64 = ctx.r8.s64 + -20108;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r7,640
	ctx.r7.s64 = 640;
	// stb r31,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r31.u8);
	// li r6,960
	ctx.r6.s64 = 960;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F89D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r11,-25232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stb r31,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r31.u8);
	// addi r4,r7,-20124
	ctx.r4.s64 = ctx.r7.s64 + -20124;
	// stb r31,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r31.u8);
	// li r7,640
	ctx.r7.s64 = 640;
	// stw r3,-22100(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22100, ctx.r3.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,56(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	// li r6,960
	ctx.r6.s64 = 960;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821F8A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// lwz r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// rldicr r8,r6,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// ld r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// stw r11,-22104(r7)
	PPC_STORE_U32(ctx.r7.u32 + -22104, r11.u32);
	// ld r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// bl 0x821f7710
	ctx.lr = 0x821F8A4C;
	sub_821F7710(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821F8A54"))) PPC_WEAK_FUNC(sub_821F8A54);
PPC_FUNC_IMPL(__imp__sub_821F8A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

