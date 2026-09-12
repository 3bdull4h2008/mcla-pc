#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8238A324"))) PPC_WEAK_FUNC(sub_8238A324);
PPC_FUNC_IMPL(__imp__sub_8238A324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A328"))) PPC_WEAK_FUNC(sub_8238A328);
PPC_FUNC_IMPL(__imp__sub_8238A328) {
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
	ctx.lr = 0x8238A330;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r24,r11,14500
	r24.s64 = r11.s64 + 14500;
	// stw r10,32(r25)
	PPC_STORE_U32(r25.u32 + 32, ctx.r10.u32);
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r28,r25,32
	r28.s64 = r25.s64 + 32;
	// bl 0x821cff40
	ctx.lr = 0x8238A364;
	sub_821CFF40(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238a4ac
	if (cr6.eq) goto loc_8238A4AC;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r20,r25,44
	r20.s64 = r25.s64 + 44;
	// addi r26,r25,52
	r26.s64 = r25.s64 + 52;
	// addi r30,r25,36
	r30.s64 = r25.s64 + 36;
	// addi r22,r10,-7904
	r22.s64 = ctx.r10.s64 + -7904;
	// addi r21,r11,-29624
	r21.s64 = r11.s64 + -29624;
loc_8238A38C:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x8238A398;
	sub_821D0898(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe20
	ctx.lr = 0x8238A3A4;
	sub_821CFE20(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238A3C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x8238A3CC;
	sub_821C9790(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// bl 0x821970c0
	ctx.lr = 0x8238A3E0;
	sub_821970C0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2a58
	ctx.lr = 0x8238A3E8;
	sub_821D2A58(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8238a098
	ctx.lr = 0x8238A3F4;
	sub_8238A098(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r29,148(r27)
	PPC_STORE_U32(r27.u32 + 148, r29.u32);
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238a444
	if (cr6.eq) goto loc_8238A444;
	// divwu r10,r29,r11
	ctx.r10.u32 = r29.u32 / r11.u32;
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r29
	ctx.r7.s64 = r29.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238a444
	if (cr6.eq) goto loc_8238A444;
loc_8238A42C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x8238a444
	if (cr6.eq) goto loc_8238A444;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238a42c
	if (!cr6.eq) goto loc_8238A42C;
loc_8238A444:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82389998
	ctx.lr = 0x8238A454;
	sub_82389998(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0260
	ctx.lr = 0x8238A45C;
	sub_821D0260(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r6,-4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// bl 0x82388e48
	ctx.lr = 0x8238A484;
	sub_82388E48(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// bl 0x821cff40
	ctx.lr = 0x8238A4A0;
	sub_821CFF40(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8238a38c
	if (!cr6.eq) goto loc_8238A38C;
loc_8238A4AC:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8238A4B4"))) PPC_WEAK_FUNC(sub_8238A4B4);
PPC_FUNC_IMPL(__imp__sub_8238A4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A4B8"))) PPC_WEAK_FUNC(sub_8238A4B8);
PPC_FUNC_IMPL(__imp__sub_8238A4B8) {
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
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x8238A4DC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8238a568
	if (!cr6.gt) goto loc_8238A568;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r3,24
	r11.s64 = ctx.r3.s64 + 24;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8238A4F4:
	// addic. r9,r11,-24
	xer.ca = r11.u32 > 23;
	ctx.r9.s64 = r11.s64 + -24;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8238a55c
	if (cr0.eq) goto loc_8238A55C;
	// stw r10,-24(r11)
	PPC_STORE_U32(r11.u32 + -24, ctx.r10.u32);
	// stw r10,-20(r11)
	PPC_STORE_U32(r11.u32 + -20, ctx.r10.u32);
	// stw r10,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, ctx.r10.u32);
	// stb r10,-12(r11)
	PPC_STORE_U8(r11.u32 + -12, ctx.r10.u8);
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
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// sth r10,16(r11)
	PPC_STORE_U16(r11.u32 + 16, ctx.r10.u16);
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// sth r10,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r10.u16);
	// sth r10,26(r11)
	PPC_STORE_U16(r11.u32 + 26, ctx.r10.u16);
	// sth r10,34(r11)
	PPC_STORE_U16(r11.u32 + 34, ctx.r10.u16);
	// sth r10,32(r11)
	PPC_STORE_U16(r11.u32 + 32, ctx.r10.u16);
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// stb r10,39(r11)
	PPC_STORE_U8(r11.u32 + 39, ctx.r10.u8);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// sth r10,44(r11)
	PPC_STORE_U16(r11.u32 + 44, ctx.r10.u16);
	// sth r10,46(r11)
	PPC_STORE_U16(r11.u32 + 46, ctx.r10.u16);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
loc_8238A55C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// bne 0x8238a4f4
	if (!cr0.eq) goto loc_8238A4F4;
loc_8238A568:
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

__attribute__((alias("__imp__sub_8238A57C"))) PPC_WEAK_FUNC(sub_8238A57C);
PPC_FUNC_IMPL(__imp__sub_8238A57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A580"))) PPC_WEAK_FUNC(sub_8238A580);
PPC_FUNC_IMPL(__imp__sub_8238A580) {
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
	ctx.lr = 0x8238A588;
	// stwu r1,-1392(r1)
	ea = -1392 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-7836
	ctx.r4.s64 = ctx.r10.s64 + -7836;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r26,0
	r26.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x8238A5B4;
	sub_821CA540(ctx, base);
	// clrlwi r29,r29,24
	r29.u64 = r29.u32 & 0xFF;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// cntlzw r8,r29
	ctx.r8.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// addi r5,r9,-7840
	ctx.r5.s64 = ctx.r9.s64 + -7840;
	// rlwinm r28,r8,27,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x8238A5DC;
	sub_821CA6A8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8238a610
	if (!cr6.eq) goto loc_8238A610;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8238a600
	if (cr6.eq) goto loc_8238A600;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r11,-7884
	ctx.r3.s64 = r11.s64 + -7884;
	// bl 0x82130000
	ctx.lr = 0x8238A600;
	sub_82130000(ctx, base);
loc_8238A600:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8238A608;
	sub_821C9A90(ctx, base);
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x823d923c
	return;
loc_8238A610:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r11,-7892
	r29.s64 = r11.s64 + -7892;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821ca778
	ctx.lr = 0x8238A628;
	sub_821CA778(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238a65c
	if (cr6.eq) goto loc_8238A65C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x8238A64C;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8238a65c
	if (cr6.eq) goto loc_8238A65C;
	// li r25,1
	r25.s64 = 1;
loc_8238A65C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8238A664;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x8238A66C;
	sub_821D1CD0(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821cf7b8
	ctx.lr = 0x8238A67C;
	sub_821CF7B8(ctx, base);
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821d1cd0
	ctx.lr = 0x8238A684;
	sub_821D1CD0(ctx, base);
	// clrlwi r31,r25,24
	r31.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8238a6a4
	if (cr6.eq) goto loc_8238A6A4;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r11,-7900
	ctx.r4.s64 = r11.s64 + -7900;
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x821cf7b8
	ctx.lr = 0x8238A6A4;
	sub_821CF7B8(ctx, base);
loc_8238A6A4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,19612
	ctx.r4.s64 = r11.s64 + 19612;
	// bl 0x821cfe20
	ctx.lr = 0x8238A6B4;
	sub_821CFE20(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,640
	ctx.r4.s64 = ctx.r1.s64 + 640;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238A6D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,768
	ctx.r5.s64 = ctx.r1.s64 + 768;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238a328
	ctx.lr = 0x8238A6E0;
	sub_8238A328(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x8238A6E8;
	sub_821BE610(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8238a6f8
	if (cr6.eq) goto loc_8238A6F8;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x8238A6F8;
	sub_821BE610(ctx, base);
loc_8238A6F8:
	// addi r1,r1,1392
	ctx.r1.s64 = ctx.r1.s64 + 1392;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8238A700"))) PPC_WEAK_FUNC(sub_8238A700);
PPC_FUNC_IMPL(__imp__sub_8238A700) {
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
	ctx.lr = 0x8238A708;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// bne cr6,0x8238a7a8
	if (!cr6.eq) goto loc_8238A7A8;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x8238a4b8
	ctx.lr = 0x8238A730;
	sub_8238A4B8(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238a774
	if (cr6.eq) goto loc_8238A774;
	// li r30,0
	r30.s64 = 0;
loc_8238A744:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x8238a148
	ctx.lr = 0x8238A760;
	sub_8238A148(ctx, base);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r10,16
	r30.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// blt cr6,0x8238a744
	if (cr6.lt) goto loc_8238A744;
loc_8238A774:
	// lhz r30,4(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8238a79c
	if (!cr6.gt) goto loc_8238A79C;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_8238A788:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238a288
	ctx.lr = 0x8238A790;
	sub_8238A288(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// bne 0x8238a788
	if (!cr0.eq) goto loc_8238A788;
loc_8238A79C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x8238A7A4;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_8238A7A8:
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
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238A7D0"))) PPC_WEAK_FUNC(sub_8238A7D0);
PPC_FUNC_IMPL(__imp__sub_8238A7D0) {
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
	ctx.lr = 0x8238A7D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,-24480
	r29.s64 = r11.s64 + -24480;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821cff40
	ctx.lr = 0x8238A7F4;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238a86c
	if (cr6.eq) goto loc_8238A86C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r30,r11,-12648
	r30.s64 = r11.s64 + -12648;
loc_8238A808:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe20
	ctx.lr = 0x8238A814;
	sub_821CFE20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8238a700
	ctx.lr = 0x8238A820;
	sub_8238A700(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82388ac0
	ctx.lr = 0x8238A828;
	sub_82388AC0(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,-80
	ctx.r3.s64 = r11.s64 + -80;
	// bl 0x8238a580
	ctx.lr = 0x8238A850;
	sub_8238A580(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8238A860;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8238a808
	if (!cr6.eq) goto loc_8238A808;
loc_8238A86C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238A874"))) PPC_WEAK_FUNC(sub_8238A874);
PPC_FUNC_IMPL(__imp__sub_8238A874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A878"))) PPC_WEAK_FUNC(sub_8238A878);
PPC_FUNC_IMPL(__imp__sub_8238A878) {
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
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r31,r11,-28260
	r31.s64 = r11.s64 + -28260;
	// addi r3,r10,-12712
	ctx.r3.s64 = ctx.r10.s64 + -12712;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c0750
	ctx.lr = 0x8238A8A0;
	sub_821C0750(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// blt cr6,0x8238a8b4
	if (cr6.lt) goto loc_8238A8B4;
	// li r11,7
	r11.s64 = 7;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8238A8B4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r5,r11,-32764
	ctx.r5.s64 = r11.s64 + -32764;
	// addi r4,r10,-7780
	ctx.r4.s64 = ctx.r10.s64 + -7780;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x821ca6a8
	ctx.lr = 0x8238A8D8;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8238a904
	if (!cr6.eq) goto loc_8238A904;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-7824
	ctx.r3.s64 = r11.s64 + -7824;
	// bl 0x821bd618
	ctx.lr = 0x8238A8F0;
	sub_821BD618(ctx, base);
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8238A904:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x8238A90C;
	sub_821D1CD0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,19612
	ctx.r4.s64 = r11.s64 + 19612;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x8238A920;
	sub_821CF7B8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238a7d0
	ctx.lr = 0x8238A928;
	sub_8238A7D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8238A930;
	sub_821BE610(ctx, base);
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238A944"))) PPC_WEAK_FUNC(sub_8238A944);
PPC_FUNC_IMPL(__imp__sub_8238A944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A948"))) PPC_WEAK_FUNC(sub_8238A948);
PPC_FUNC_IMPL(__imp__sub_8238A948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,-7592
	ctx.r10.s64 = r11.s64 + -7592;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238A958"))) PPC_WEAK_FUNC(sub_8238A958);
PPC_FUNC_IMPL(__imp__sub_8238A958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,6(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lbz r8,10(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// lbz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r10,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r10.u8);
	// stb r9,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r9.u8);
	// stb r8,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r8.u8);
	// stb r7,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238A984"))) PPC_WEAK_FUNC(sub_8238A984);
PPC_FUNC_IMPL(__imp__sub_8238A984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A988"))) PPC_WEAK_FUNC(sub_8238A988);
PPC_FUNC_IMPL(__imp__sub_8238A988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-7592
	ctx.r9.s64 = ctx.r10.s64 + -7592;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r11.u8);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stb r11,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, r11.u8);
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238A9CC"))) PPC_WEAK_FUNC(sub_8238A9CC);
PPC_FUNC_IMPL(__imp__sub_8238A9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A9D0"))) PPC_WEAK_FUNC(sub_8238A9D0);
PPC_FUNC_IMPL(__imp__sub_8238A9D0) {
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
	// addi r10,r11,-7592
	ctx.r10.s64 = r11.s64 + -7592;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8238A9FC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238aa14
	if (cr6.eq) goto loc_8238AA14;
	// bl 0x82130588
	ctx.lr = 0x8238AA10;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238AA14:
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

__attribute__((alias("__imp__sub_8238AA2C"))) PPC_WEAK_FUNC(sub_8238AA2C);
PPC_FUNC_IMPL(__imp__sub_8238AA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AA30"))) PPC_WEAK_FUNC(sub_8238AA30);
PPC_FUNC_IMPL(__imp__sub_8238AA30) {
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
	ctx.lr = 0x8238AA38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// beq cr6,0x8238aa9c
	if (cr6.eq) goto loc_8238AA9C;
	// mr r29,r27
	r29.u64 = r27.u64;
	// bge cr6,0x8238aa9c
	if (!cr6.lt) goto loc_8238AA9C;
	// mulli r11,r27,8176
	r11.s64 = r27.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addis r28,r31,4
	r28.s64 = r31.s64 + 262144;
	// addi r30,r11,1360
	r30.s64 = r11.s64 + 1360;
	// addi r28,r28,-8112
	r28.s64 = r28.s64 + -8112;
	// li r26,1
	r26.s64 = 1;
loc_8238AA74:
	// addi r4,r30,8176
	ctx.r4.s64 = r30.s64 + 8176;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238ee58
	ctx.lr = 0x8238AA80;
	sub_8238EE58(ctx, base);
	// stb r26,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r26.u8);
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r30,r30,8176
	r30.s64 = r30.s64 + 8176;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8238aa74
	if (cr6.lt) goto loc_8238AA74;
loc_8238AA9C:
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r29,r10,3998
	r29.s64 = ctx.r10.s64 + 3998;
	// addi r30,r11,-6816
	r30.s64 = r11.s64 + -6816;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f968
	ctx.lr = 0x8238AAC0;
	sub_8238F968(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f980
	ctx.lr = 0x8238AACC;
	sub_8238F980(ctx, base);
	// lwz r10,1340(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// lwz r11,1344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// stw r9,1340(r31)
	PPC_STORE_U32(r31.u32 + 1340, ctx.r9.u32);
	// blt cr6,0x8238aaec
	if (cr6.lt) goto loc_8238AAEC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r11.u32);
loc_8238AAEC:
	// lwz r11,1344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8238ab00
	if (!cr6.lt) goto loc_8238AB00;
	// li r11,0
	r11.s64 = 0;
	// stw r11,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r11.u32);
loc_8238AB00:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8238AB08"))) PPC_WEAK_FUNC(sub_8238AB08);
PPC_FUNC_IMPL(__imp__sub_8238AB08) {
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
	// bl 0x8238f0a8
	ctx.lr = 0x8238AB24;
	sub_8238F0A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238f0a8
	ctx.lr = 0x8238AB30;
	sub_8238F0A8(ctx, base);
	// subf r3,r3,r30
	ctx.r3.s64 = r30.s64 - ctx.r3.s64;
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

__attribute__((alias("__imp__sub_8238AB4C"))) PPC_WEAK_FUNC(sub_8238AB4C);
PPC_FUNC_IMPL(__imp__sub_8238AB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AB50"))) PPC_WEAK_FUNC(sub_8238AB50);
PPC_FUNC_IMPL(__imp__sub_8238AB50) {
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
	ctx.lr = 0x8238AB58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,1340(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238aba0
	if (!cr6.gt) goto loc_8238ABA0;
	// addi r31,r29,9469
	r31.s64 = r29.s64 + 9469;
loc_8238AB78:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db730
	ctx.lr = 0x8238AB84;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238abac
	if (cr6.eq) goto loc_8238ABAC;
	// lwz r11,1340(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1340);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,8176
	r31.s64 = r31.s64 + 8176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8238ab78
	if (cr6.lt) goto loc_8238AB78;
loc_8238ABA0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238ABAC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238ABB8"))) PPC_WEAK_FUNC(sub_8238ABB8);
PPC_FUNC_IMPL(__imp__sub_8238ABB8) {
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
	ctx.lr = 0x8238ABC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r10,1344(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// subf r9,r29,r10
	ctx.r9.s64 = ctx.r10.s64 - r29.s64;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r27,r8,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bge cr6,0x8238ac58
	if (!cr6.lt) goto loc_8238AC58;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r28,r29
	r28.u64 = r29.u64;
	// stw r11,1340(r31)
	PPC_STORE_U32(r31.u32 + 1340, r11.u32);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x8238ac28
	if (!cr6.lt) goto loc_8238AC28;
	// mulli r11,r29,8176
	r11.s64 = r29.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,1360
	r30.s64 = r11.s64 + 1360;
loc_8238AC08:
	// addi r4,r30,8176
	ctx.r4.s64 = r30.s64 + 8176;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238ee58
	ctx.lr = 0x8238AC14;
	sub_8238EE58(ctx, base);
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,8176
	r30.s64 = r30.s64 + 8176;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8238ac08
	if (cr6.lt) goto loc_8238AC08;
loc_8238AC28:
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r28,r10,3998
	r28.s64 = ctx.r10.s64 + 3998;
	// addi r30,r11,1360
	r30.s64 = r11.s64 + 1360;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f968
	ctx.lr = 0x8238AC4C;
	sub_8238F968(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f980
	ctx.lr = 0x8238AC58;
	sub_8238F980(ctx, base);
loc_8238AC58:
	// lwz r11,1344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// blt cr6,0x8238ac78
	if (cr6.lt) goto loc_8238AC78;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238ac78
	if (!cr6.gt) goto loc_8238AC78;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r11.u32);
loc_8238AC78:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238AC80"))) PPC_WEAK_FUNC(sub_8238AC80);
PPC_FUNC_IMPL(__imp__sub_8238AC80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,52684
	cr6.compare<uint32_t>(ctx.r5.u32, 52684, xer);
	// lis r11,0
	r11.s64 = 0;
	// bne cr6,0x8238ac94
	if (!cr6.eq) goto loc_8238AC94;
	// ori r11,r11,52684
	r11.u64 = r11.u64 | 52684;
	// b 0x8238aca8
	goto loc_8238ACA8;
loc_8238AC94:
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// bge cr6,0x8238aca8
	if (!cr6.lt) goto loc_8238ACA8;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8238ACA8:
	// mulli r10,r4,84
	ctx.r10.s64 = ctx.r4.s64 * 84;
	// lis r9,3
	ctx.r9.s64 = 196608;
	// lis r8,3
	ctx.r8.s64 = 196608;
	// add r7,r10,r3
	ctx.r7.u64 = ctx.r10.u64 + ctx.r3.u64;
	// ori r6,r9,50114
	ctx.r6.u64 = ctx.r9.u64 | 50114;
	// ori r5,r8,57424
	ctx.r5.u64 = ctx.r8.u64 | 57424;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// sthx r4,r7,r6
	PPC_STORE_U16(ctx.r7.u32 + ctx.r6.u32, ctx.r4.u16);
	// stbx r11,r3,r5
	PPC_STORE_U8(ctx.r3.u32 + ctx.r5.u32, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238ACD4"))) PPC_WEAK_FUNC(sub_8238ACD4);
PPC_FUNC_IMPL(__imp__sub_8238ACD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238ACD8"))) PPC_WEAK_FUNC(sub_8238ACD8);
PPC_FUNC_IMPL(__imp__sub_8238ACD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// ori r8,r10,56500
	ctx.r8.u64 = ctx.r10.u64 | 56500;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r9,3
	ctx.r9.s64 = 196608;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r4,10547
	ctx.r10.s64 = ctx.r4.s64 + 10547;
	// lis r7,3
	ctx.r7.s64 = 196608;
	// ori r6,r9,56504
	ctx.r6.u64 = ctx.r9.u64 | 56504;
	// lis r4,3
	ctx.r4.s64 = 196608;
	// stfsx f0,r11,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r7,r7,56508
	ctx.r7.u64 = ctx.r7.u64 | 56508;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,3
	ctx.r8.s64 = 196608;
	// ori r4,r4,56512
	ctx.r4.u64 = ctx.r4.u64 | 56512;
	// stfsx f13,r11,r6
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// ori r9,r8,56516
	ctx.r9.u64 = ctx.r8.u64 | 56516;
	// stfsx f12,r11,r7
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, temp.u32);
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f11,r11,r4
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, temp.u32);
	// lfs f10,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// stfsx f10,r11,r9
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, temp.u32);
	// lfs f9,20(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// stfsx f9,r8,r3
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AD54"))) PPC_WEAK_FUNC(sub_8238AD54);
PPC_FUNC_IMPL(__imp__sub_8238AD54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AD58"))) PPC_WEAK_FUNC(sub_8238AD58);
PPC_FUNC_IMPL(__imp__sub_8238AD58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
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
	// lis r10,3
	ctx.r10.s64 = 196608;
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// ori r8,r10,57282
	ctx.r8.u64 = ctx.r10.u64 | 57282;
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// stbx r5,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r5.u8);
	// bne cr6,0x8238ae44
	if (!cr6.eq) goto loc_8238AE44;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8238ae44
	if (cr6.gt) goto loc_8238AE44;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-21084
	r12.s64 = r12.s64 + -21084;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8238ADB4;
	case 1:
		goto loc_8238ADD8;
	case 2:
		goto loc_8238ADFC;
	case 3:
		goto loc_8238AE20;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-21068(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -21068);
	// lwz r17,-21032(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -21032);
	// lwz r17,-20996(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -20996);
	// lwz r17,-20960(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -20960);
loc_8238ADB4:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-7228
	ctx.r4.s64 = r11.s64 + -7228;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238ADD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8238ADD8:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-7236
	ctx.r4.s64 = r11.s64 + -7236;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238ADFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8238ADFC:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-7244
	ctx.r4.s64 = r11.s64 + -7244;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238AE20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8238AE20:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-7252
	ctx.r4.s64 = r11.s64 + -7252;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238AE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8238AE44:
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

__attribute__((alias("__imp__sub_8238AE58"))) PPC_WEAK_FUNC(sub_8238AE58);
PPC_FUNC_IMPL(__imp__sub_8238AE58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
	// lis r10,3
	ctx.r10.s64 = 196608;
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// ori r9,r10,57282
	ctx.r9.u64 = ctx.r10.u64 | 57282;
	// lbzx r11,r11,r9
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// bgt cr6,0x8238aeb4
	if (cr6.gt) {
		sub_8238AEB4(ctx, base);
		return;
	}
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-20852
	r12.s64 = r12.s64 + -20852;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8238AE9C;
	case 1:
		goto loc_8238AEA4;
	case 2:
		goto loc_8238AEAC;
	case 3:
		goto loc_8238AEAC;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-20836(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -20836);
	// lwz r17,-20828(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -20828);
	// lwz r17,-20820(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -20820);
	// lwz r17,-20820(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -20820);
loc_8238AE9C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238AEA4:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8238AEAC:
	// li r3,3
	ctx.r3.s64 = 3;
}

__attribute__((alias("__imp__sub_8238AEB4"))) PPC_WEAK_FUNC(sub_8238AEB4);
PPC_FUNC_IMPL(__imp__sub_8238AEB4) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AEBC"))) PPC_WEAK_FUNC(sub_8238AEBC);
PPC_FUNC_IMPL(__imp__sub_8238AEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AEC0"))) PPC_WEAK_FUNC(sub_8238AEC0);
PPC_FUNC_IMPL(__imp__sub_8238AEC0) {
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
	ctx.lr = 0x8238AEC8;
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
	// lwz r11,1344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8238af30
	if (cr6.lt) goto loc_8238AF30;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a5948
	ctx.lr = 0x8238AEEC;
	sub_822A5948(ctx, base);
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,8100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8100);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8238af30
	if (cr6.eq) goto loc_8238AF30;
	// lwz r11,1344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238fe90
	ctx.lr = 0x8238AF18;
	sub_8238FE90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238af30
	if (cr6.eq) goto loc_8238AF30;
	// lwz r3,1344(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8238AF30:
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238af74
	if (cr6.eq) goto loc_8238AF74;
	// addi r30,r31,1360
	r30.s64 = r31.s64 + 1360;
loc_8238AF44:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238fe90
	ctx.lr = 0x8238AF54;
	sub_8238FE90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238af80
	if (!cr6.eq) goto loc_8238AF80;
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8176
	r30.s64 = r30.s64 + 8176;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x8238af44
	if (!cr6.eq) goto loc_8238AF44;
loc_8238AF74:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8238AF80:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238AF8C"))) PPC_WEAK_FUNC(sub_8238AF8C);
PPC_FUNC_IMPL(__imp__sub_8238AF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AF90"))) PPC_WEAK_FUNC(sub_8238AF90);
PPC_FUNC_IMPL(__imp__sub_8238AF90) {
	PPC_FUNC_PROLOGUE();
	// stw r4,1316(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1316, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AF98"))) PPC_WEAK_FUNC(sub_8238AF98);
PPC_FUNC_IMPL(__imp__sub_8238AF98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// lhzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// beq cr6,0x8238afbc
	if (cr6.eq) goto loc_8238AFBC;
	// sthx r5,r11,r3
	PPC_STORE_U16(r11.u32 + ctx.r3.u32, ctx.r5.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238AFBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AFC4"))) PPC_WEAK_FUNC(sub_8238AFC4);
PPC_FUNC_IMPL(__imp__sub_8238AFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AFC8"))) PPC_WEAK_FUNC(sub_8238AFC8);
PPC_FUNC_IMPL(__imp__sub_8238AFC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + ctx.r3.u32);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// beq cr6,0x8238aff0
	if (cr6.eq) goto loc_8238AFF0;
	// sthx r5,r11,r3
	PPC_STORE_U16(r11.u32 + ctx.r3.u32, ctx.r5.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238AFF0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AFF8"))) PPC_WEAK_FUNC(sub_8238AFF8);
PPC_FUNC_IMPL(__imp__sub_8238AFF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,298
	r11.s64 = ctx.r4.s64 + 298;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// beq cr6,0x8238b018
	if (cr6.eq) goto loc_8238B018;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238B018:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B020"))) PPC_WEAK_FUNC(sub_8238B020);
PPC_FUNC_IMPL(__imp__sub_8238B020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,301
	r11.s64 = ctx.r4.s64 + 301;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// beq cr6,0x8238b040
	if (cr6.eq) goto loc_8238B040;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238B040:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B048"))) PPC_WEAK_FUNC(sub_8238B048);
PPC_FUNC_IMPL(__imp__sub_8238B048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,302
	r11.s64 = ctx.r4.s64 + 302;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// beq cr6,0x8238b068
	if (cr6.eq) goto loc_8238B068;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238B068:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B070"))) PPC_WEAK_FUNC(sub_8238B070);
PPC_FUNC_IMPL(__imp__sub_8238B070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,592
	r11.s64 = ctx.r4.s64 * 592;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,596
	ctx.r3.s64 = r11.s64 + 596;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B080"))) PPC_WEAK_FUNC(sub_8238B080);
PPC_FUNC_IMPL(__imp__sub_8238B080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,592
	r11.s64 = ctx.r4.s64 * 592;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B090"))) PPC_WEAK_FUNC(sub_8238B090);
PPC_FUNC_IMPL(__imp__sub_8238B090) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// addi r11,r4,306
	r11.s64 = ctx.r4.s64 + 306;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// beq cr6,0x8238b0b0
	if (cr6.eq) goto loc_8238B0B0;
	// stfsx f1,r11,r3
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238B0B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B0B8"))) PPC_WEAK_FUNC(sub_8238B0B8);
PPC_FUNC_IMPL(__imp__sub_8238B0B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// lbz r3,1228(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1228);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B0C4"))) PPC_WEAK_FUNC(sub_8238B0C4);
PPC_FUNC_IMPL(__imp__sub_8238B0C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238B0C8"))) PPC_WEAK_FUNC(sub_8238B0C8);
PPC_FUNC_IMPL(__imp__sub_8238B0C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// lbz r9,1228(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1228);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x8238b0e8
	if (cr6.eq) goto loc_8238B0E8;
	// stb r5,1228(r11)
	PPC_STORE_U8(r11.u32 + 1228, ctx.r5.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238B0E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B0F0"))) PPC_WEAK_FUNC(sub_8238B0F0);
PPC_FUNC_IMPL(__imp__sub_8238B0F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// lhz r9,1238(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 1238);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// cmpw cr6,r6,r10
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, xer);
	// beq cr6,0x8238b120
	if (cr6.eq) goto loc_8238B120;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,1238(r11)
	PPC_STORE_U16(r11.u32 + 1238, ctx.r10.u16);
	// blr 
	return;
loc_8238B120:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B128"))) PPC_WEAK_FUNC(sub_8238B128);
PPC_FUNC_IMPL(__imp__sub_8238B128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,3
	r11.s64 = 196608;
	// ori r11,r11,57424
	r11.u64 = r11.u64 | 57424;
	// stbx r4,r3,r11
	PPC_STORE_U8(ctx.r3.u32 + r11.u32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238B138"))) PPC_WEAK_FUNC(sub_8238B138);
PPC_FUNC_IMPL(__imp__sub_8238B138) {
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
	ctx.lr = 0x8238B140;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r24,r29
	r24.u64 = r29.u64;
	// addi r30,r29,1196
	r30.s64 = r29.s64 + 1196;
	// addi r31,r28,1188
	r31.s64 = r28.s64 + 1188;
	// addi r23,r29,596
	r23.s64 = r29.s64 + 596;
	// addi r25,r28,4
	r25.s64 = r28.s64 + 4;
	// addi r26,r28,2
	r26.s64 = r28.s64 + 2;
	// subf r22,r28,r29
	r22.s64 = r29.s64 - r28.s64;
loc_8238B16C:
	// lhz r11,-2(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + -2);
	// lhz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lhzx r11,r22,r26
	r11.u64 = PPC_LOAD_U16(r22.u32 + r26.u32);
	// lhz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// add r4,r22,r25
	ctx.r4.u64 = r22.u64 + r25.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82391758
	ctx.lr = 0x8238B198;
	sub_82391758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238b3b0
	if (cr6.eq) goto loc_8238B3B0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r25,592
	ctx.r3.s64 = r25.s64 + 592;
	// bl 0x82391758
	ctx.lr = 0x8238B1B0;
	sub_82391758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238b3b0
	if (cr6.eq) goto loc_8238B3B0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r10,r22,r31
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + r31.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// add r11,r27,r29
	r11.u64 = r27.u64 + r29.u64;
	// add r10,r27,r28
	ctx.r10.u64 = r27.u64 + r28.u64;
	// lbz r9,1228(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1228);
	// lbz r8,1228(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1228);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r24,r24,2
	r24.s64 = r24.s64 + 2;
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r23,r23,592
	r23.s64 = r23.s64 + 592;
	// addi r25,r25,592
	r25.s64 = r25.s64 + 592;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// blt cr6,0x8238b16c
	if (cr6.lt) goto loc_8238B16C;
	// lfs f0,1232(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1232);
	f0.f64 = double(temp.f32);
	// lfs f13,1232(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 1232);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lhz r11,1236(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1236);
	// lhz r10,1236(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 1236);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lhz r11,1238(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1238);
	// lhz r10,1238(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 1238);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r29,1240
	r11.s64 = r29.s64 + 1240;
	// subf r9,r29,r28
	ctx.r9.s64 = r28.s64 - r29.s64;
loc_8238B2D4:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// blt cr6,0x8238b2d4
	if (cr6.lt) goto loc_8238B2D4;
	// lwz r11,1260(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1260);
	// lwz r10,1260(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1260);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r29,1264
	ctx.r4.s64 = r29.s64 + 1264;
	// addi r3,r28,1264
	ctx.r3.s64 = r28.s64 + 1264;
	// bl 0x823dd800
	ctx.lr = 0x8238B314;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r4,r29,1274
	ctx.r4.s64 = r29.s64 + 1274;
	// addi r3,r28,1274
	ctx.r3.s64 = r28.s64 + 1274;
	// bl 0x823df0e0
	ctx.lr = 0x8238B32C;
	sub_823DF0E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,1316(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1316);
	// lwz r10,1316(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1316);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,1320(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1320);
	// lwz r10,1320(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1320);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lbz r11,1324(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1324);
	// lbz r10,1324(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1324);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lbz r11,1325(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1325);
	// lbz r10,1325(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1325);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lwz r11,1328(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1328);
	// lwz r10,1328(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1328);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lfs f0,1332(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 1332);
	f0.f64 = double(temp.f32);
	// lfs f13,1332(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 1332);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8238b3b0
	if (!cr6.eq) goto loc_8238B3B0;
	// lbz r11,1336(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1336);
	// lbz r10,1336(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_8238B3B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8238B3BC"))) PPC_WEAK_FUNC(sub_8238B3BC);
PPC_FUNC_IMPL(__imp__sub_8238B3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238B3C0"))) PPC_WEAK_FUNC(sub_8238B3C0);
PPC_FUNC_IMPL(__imp__sub_8238B3C0) {
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
	// li r5,1340
	ctx.r5.s64 = 1340;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823da950
	ctx.lr = 0x8238B3DC;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_8238B3F4"))) PPC_WEAK_FUNC(sub_8238B3F4);
PPC_FUNC_IMPL(__imp__sub_8238B3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238B3F8"))) PPC_WEAK_FUNC(sub_8238B3F8);
PPC_FUNC_IMPL(__imp__sub_8238B3F8) {
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
	ctx.lr = 0x8238B400;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,3
	r11.s64 = 196608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r28,r11,50040
	r28.u64 = r11.u64 | 50040;
	// li r10,77
	ctx.r10.s64 = 77;
	// add r11,r30,r28
	r11.u64 = r30.u64 + r28.u64;
loc_8238B418:
	// lhz r9,74(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 74);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// bne 0x8238b418
	if (!cr0.eq) goto loc_8238B418;
	// lwz r11,1340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238b498
	if (!cr6.gt) goto loc_8238B498;
	// addi r29,r30,1360
	r29.s64 = r30.s64 + 1360;
loc_8238B444:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f1e8
	ctx.lr = 0x8238B44C;
	sub_8238F1E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f998
	ctx.lr = 0x8238B458;
	sub_8238F998(ctx, base);
	// stw r31,8088(r29)
	PPC_STORE_U32(r29.u32 + 8088, r31.u32);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// ble cr6,0x8238b484
	if (!cr6.gt) goto loc_8238B484;
	// mulli r10,r31,84
	ctx.r10.s64 = r31.s64 * 84;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + r28.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_8238B484:
	// lwz r11,1340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,8176
	r29.s64 = r29.s64 + 8176;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8238b444
	if (cr6.lt) goto loc_8238B444;
loc_8238B498:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238B4A0"))) PPC_WEAK_FUNC(sub_8238B4A0);
PPC_FUNC_IMPL(__imp__sub_8238B4A0) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8238B4B8;
	sub_821C9790(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8238B4C0;
	sub_82387B90(ctx, base);
	// lwz r9,1340(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8238b4f0
	if (!cr6.gt) goto loc_8238B4F0;
	// addi r11,r3,9464
	r11.s64 = ctx.r3.s64 + 9464;
loc_8238B4D4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r31,r8
	cr6.compare<uint32_t>(r31.u32, ctx.r8.u32, xer);
	// beq cr6,0x8238b508
	if (cr6.eq) goto loc_8238B508;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8176
	r11.s64 = r11.s64 + 8176;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8238b4d4
	if (cr6.lt) goto loc_8238B4D4;
loc_8238B4F0:
	// li r3,-1
	ctx.r3.s64 = -1;
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
loc_8238B508:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
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

__attribute__((alias("__imp__sub_8238B520"))) PPC_WEAK_FUNC(sub_8238B520);
PPC_FUNC_IMPL(__imp__sub_8238B520) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387b90
	ctx.lr = 0x8238B538;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// ori r8,r10,57220
	ctx.r8.u64 = ctx.r10.u64 | 57220;
	// li r7,1
	ctx.r7.s64 = 1;
	// addis r11,r11,4
	r11.s64 = r11.s64 + 262144;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,-8315
	r11.s64 = r11.s64 + -8315;
	// li r10,10
	ctx.r10.s64 = 10;
	// stbx r7,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u8);
loc_8238B560:
	// lbz r9,-1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238b570
	if (cr6.eq) goto loc_8238B570;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8238B570:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238b580
	if (cr6.eq) goto loc_8238B580;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8238B580:
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238b590
	if (cr6.eq) goto loc_8238B590;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8238B590:
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238b5a0
	if (cr6.eq) goto loc_8238B5A0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8238B5A0:
	// lbz r9,3(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238b5b0
	if (cr6.eq) goto loc_8238B5B0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8238B5B0:
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238b5c0
	if (cr6.eq) goto loc_8238B5C0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8238B5C0:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// bne 0x8238b560
	if (!cr0.eq) goto loc_8238B560;
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

__attribute__((alias("__imp__sub_8238B5E0"))) PPC_WEAK_FUNC(sub_8238B5E0);
PPC_FUNC_IMPL(__imp__sub_8238B5E0) {
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
	ctx.lr = 0x8238B5E8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r28,8176
	r11.s64 = r28.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// addi r25,r11,1360
	r25.s64 = r11.s64 + 1360;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8238f1e8
	ctx.lr = 0x8238B60C;
	sub_8238F1E8(ctx, base);
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238b658
	if (!cr6.gt) goto loc_8238B658;
	// addi r29,r31,1360
	r29.s64 = r31.s64 + 1360;
loc_8238B628:
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// beq cr6,0x8238b644
	if (cr6.eq) goto loc_8238B644;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f1e8
	ctx.lr = 0x8238B638;
	sub_8238F1E8(ctx, base);
	// cmpw cr6,r3,r26
	cr6.compare<int32_t>(ctx.r3.s32, r26.s32, xer);
	// bne cr6,0x8238b644
	if (!cr6.eq) goto loc_8238B644;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_8238B644:
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,8176
	r29.s64 = r29.s64 + 8176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8238b628
	if (cr6.lt) goto loc_8238B628;
loc_8238B658:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// addi r5,r11,-7220
	ctx.r5.s64 = r11.s64 + -7220;
	// li r4,50
	ctx.r4.s64 = 50;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x8238B670;
	sub_82137A08(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// ble cr6,0x8238b6b8
	if (!cr6.gt) goto loc_8238B6B8;
	// bl 0x82218310
	ctx.lr = 0x8238B688;
	sub_82218310(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,-13556
	ctx.r5.s64 = ctx.r10.s64 + -13556;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238B6A4;
	sub_82137A08(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8238f968
	ctx.lr = 0x8238B6B0;
	sub_8238F968(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9238
	return;
loc_8238B6B8:
	// bl 0x82218310
	ctx.lr = 0x8238B6BC;
	sub_82218310(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,9572
	ctx.r5.s64 = ctx.r10.s64 + 9572;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8238B6D4;
	sub_82137A08(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8238f968
	ctx.lr = 0x8238B6E0;
	sub_8238F968(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8238B6E8"))) PPC_WEAK_FUNC(sub_8238B6E8);
PPC_FUNC_IMPL(__imp__sub_8238B6E8) {
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
	ctx.lr = 0x8238B6F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r27,r28,8109
	r27.s64 = r28.s64 + 8109;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82396408
	ctx.lr = 0x8238B708;
	sub_82396408(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8238b7d4
	if (cr6.lt) goto loc_8238B7D4;
	// lwz r30,1340(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// cmpwi cr6,r30,30
	cr6.compare<int32_t>(r30.s32, 30, xer);
	// bge cr6,0x8238b7b4
	if (!cr6.lt) goto loc_8238B7B4;
	// mulli r11,r30,8176
	r11.s64 = r30.s64 * 8176;
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r29,1360
	ctx.r3.s64 = r29.s64 + 1360;
	// bl 0x8238ee58
	ctx.lr = 0x8238B730;
	sub_8238EE58(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r28,9460(r29)
	PPC_STORE_U32(r29.u32 + 9460, r28.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238b5e0
	ctx.lr = 0x8238B748;
	sub_8238B5E0(ctx, base);
	// lis r11,3
	r11.s64 = 196608;
	// lwz r8,1344(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// ori r9,r11,57424
	ctx.r9.u64 = r11.u64 | 57424;
	// stw r10,1340(r31)
	PPC_STORE_U32(r31.u32 + 1340, ctx.r10.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stbx r28,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r28.u8);
	// bge cr6,0x8238b770
	if (!cr6.lt) goto loc_8238B770;
	// li r11,0
	r11.s64 = 0;
	// stw r11,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r11.u32);
loc_8238B770:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addis r7,r8,4
	ctx.r7.s64 = ctx.r8.s64 + 262144;
	// addi r7,r7,-9036
	ctx.r7.s64 = ctx.r7.s64 + -9036;
	// stfs f0,0(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,20(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// stfs f0,16(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 16, temp.u32);
	// stfs f0,12(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// stfs f0,8(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfs f0,4(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8238B7B4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,18508(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 18508);
	// lwz r4,44(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// bl 0x826b93e0
	ctx.lr = 0x8238B7D4;
	sub_826B93E0(ctx, base);
loc_8238B7D4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238B7E0"))) PPC_WEAK_FUNC(sub_8238B7E0);
PPC_FUNC_IMPL(__imp__sub_8238B7E0) {
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
	ctx.lr = 0x8238B7E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,-1
	r28.s64 = -1;
	// bl 0x82388628
	ctx.lr = 0x8238B800;
	sub_82388628(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-28304
	r31.s64 = r11.s64 + -28304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823882b8
	ctx.lr = 0x8238B818;
	sub_823882B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238b850
	if (!cr6.eq) goto loc_8238B850;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,38
	ctx.r4.s64 = 38;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8238B844;
	sub_8268EE10(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8238B850:
	// li r5,1
	ctx.r5.s64 = 1;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x823882b8
	ctx.lr = 0x8238B860;
	sub_823882B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238b898
	if (!cr6.eq) goto loc_8238B898;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,39
	ctx.r4.s64 = 39;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8238B88C;
	sub_8268EE10(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8238B898:
	// lwz r11,1340(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8238b8cc
	if (!cr6.eq) goto loc_8238B8CC;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27408
	ctx.r10.s64 = r11.s64 + -27408;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238b8cc
	if (cr6.eq) goto loc_8238B8CC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// lwz r4,100(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// bl 0x8238b6e8
	ctx.lr = 0x8238B8CC;
	sub_8238B6E8(ctx, base);
loc_8238B8CC:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8238b8fc
	if (cr6.eq) goto loc_8238B8FC;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8238b918
	if (!cr6.gt) goto loc_8238B918;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8238b90c
	goto loc_8238B90C;
loc_8238B8FC:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8238b918
	if (!cr6.gt) goto loc_8238B918;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8238B90C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8238b91c
	if (!cr6.eq) goto loc_8238B91C;
loc_8238B918:
	// li r11,0
	r11.s64 = 0;
loc_8238B91C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238b9a8
	if (cr6.eq) goto loc_8238B9A8;
	// lwz r11,1340(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238b9a8
	if (cr6.eq) goto loc_8238B9A8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x822950f8
	ctx.lr = 0x8238B948;
	sub_822950F8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// bl 0x824e9038
	ctx.lr = 0x8238B960;
	sub_824E9038(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8238b9a8
	if (cr6.lt) goto loc_8238B9A8;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e9690
	ctx.lr = 0x8238B97C;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238b9a8
	if (cr6.eq) goto loc_8238B9A8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x8238aec0
	ctx.lr = 0x8238B99C;
	sub_8238AEC0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x8238b9c8
	if (!cr6.lt) goto loc_8238B9C8;
loc_8238B9A8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,37
	ctx.r4.s64 = 37;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8238B9C8;
	sub_8268EE10(ctx, base);
loc_8238B9C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238B9D4"))) PPC_WEAK_FUNC(sub_8238B9D4);
PPC_FUNC_IMPL(__imp__sub_8238B9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238B9D8"))) PPC_WEAK_FUNC(sub_8238B9D8);
PPC_FUNC_IMPL(__imp__sub_8238B9D8) {
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
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,592(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 592);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stb r9,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x8238BA08;
	sub_8226B078(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295050
	ctx.lr = 0x8238BA14;
	sub_82295050(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x8238BA20;
	sub_8238B7E0(ctx, base);
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
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

__attribute__((alias("__imp__sub_8238BA38"))) PPC_WEAK_FUNC(sub_8238BA38);
PPC_FUNC_IMPL(__imp__sub_8238BA38) {
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
	ctx.lr = 0x8238BA40;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8352(r1)
	ea = -8352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-12620
	ctx.r3.s64 = r11.s64 + -12620;
	// bl 0x821c0750
	ctx.lr = 0x8238BA6C;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r9,3
	ctx.r9.s64 = 196608;
	// li r24,1
	r24.s64 = 1;
	// ori r26,r9,57424
	r26.u64 = ctx.r9.u64 | 57424;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238bab4
	if (cr6.eq) goto loc_8238BAB4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// beq cr6,0x8238baac
	if (cr6.eq) goto loc_8238BAAC;
	// sth r11,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r11.u16);
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8238bab0
	goto loc_8238BAB0;
loc_8238BAAC:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BAB0:
	// stbx r11,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r11.u8);
loc_8238BAB4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-12520
	ctx.r3.s64 = r11.s64 + -12520;
	// bl 0x821c0750
	ctx.lr = 0x8238BAC4;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238bb00
	if (cr6.eq) goto loc_8238BB00;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// beq cr6,0x8238baf8
	if (cr6.eq) goto loc_8238BAF8;
	// sth r11,2(r31)
	PPC_STORE_U16(r31.u32 + 2, r11.u16);
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8238bafc
	goto loc_8238BAFC;
loc_8238BAF8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BAFC:
	// stbx r11,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r11.u8);
loc_8238BB00:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-12460
	ctx.r10.s64 = r11.s64 + -12460;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bb38
	if (cr6.eq) goto loc_8238BB38;
	// lwz r11,1188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1188);
	// add r10,r31,r26
	ctx.r10.u64 = r31.u64 + r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238bb30
	if (cr6.eq) goto loc_8238BB30;
	// mr r11,r24
	r11.u64 = r24.u64;
	// stw r25,1188(r31)
	PPC_STORE_U32(r31.u32 + 1188, r25.u32);
	// b 0x8238bb34
	goto loc_8238BB34;
loc_8238BB30:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BB34:
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
loc_8238BB38:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-12580
	ctx.r10.s64 = r11.s64 + -12580;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bb9c
	if (cr6.eq) goto loc_8238BB9C;
	// lwz r11,1192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1192);
	// add r9,r31,r26
	ctx.r9.u64 = r31.u64 + r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238bb68
	if (cr6.eq) goto loc_8238BB68;
	// mr r11,r24
	r11.u64 = r24.u64;
	// stw r25,1192(r31)
	PPC_STORE_U32(r31.u32 + 1192, r25.u32);
	// b 0x8238bb6c
	goto loc_8238BB6C;
loc_8238BB68:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BB6C:
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bb9c
	if (cr6.eq) goto loc_8238BB9C;
	// lwz r11,1196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238bb94
	if (cr6.eq) goto loc_8238BB94;
	// mr r11,r24
	r11.u64 = r24.u64;
	// stw r25,1196(r31)
	PPC_STORE_U32(r31.u32 + 1196, r25.u32);
	// b 0x8238bb98
	goto loc_8238BB98;
loc_8238BB94:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BB98:
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
loc_8238BB9C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-12500
	ctx.r10.s64 = r11.s64 + -12500;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bbd0
	if (cr6.eq) goto loc_8238BBD0;
	// lhz r11,1238(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1238);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238bbc8
	if (!cr6.eq) goto loc_8238BBC8;
	// mr r11,r24
	r11.u64 = r24.u64;
	// sth r24,1238(r31)
	PPC_STORE_U16(r31.u32 + 1238, r24.u16);
	// b 0x8238bbcc
	goto loc_8238BBCC;
loc_8238BBC8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BBCC:
	// stbx r11,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r11.u8);
loc_8238BBD0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bd18
	if (cr6.eq) goto loc_8238BD18;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r25
	r28.u64 = r25.u64;
	// addi r10,r11,-12600
	ctx.r10.s64 = r11.s64 + -12600;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bc00
	if (cr6.eq) goto loc_8238BC00;
	// mr r28,r11
	r28.u64 = r11.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8238bc04
	goto loc_8238BC04;
loc_8238BC00:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BC04:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238bc58
	if (!cr6.eq) goto loc_8238BC58;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-12540
	ctx.r10.s64 = r11.s64 + -12540;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bc30
	if (cr6.eq) goto loc_8238BC30;
	// mr r28,r11
	r28.u64 = r11.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8238bc34
	goto loc_8238BC34;
loc_8238BC30:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8238BC34:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238bc58
	if (!cr6.eq) goto loc_8238BC58;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-12560
	ctx.r10.s64 = r11.s64 + -12560;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238bc58
	if (cr6.eq) goto loc_8238BC58;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8238BC58:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8238bd18
	if (cr6.eq) goto loc_8238BD18;
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// mr r27,r25
	r27.u64 = r25.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238bcb4
	if (!cr6.gt) goto loc_8238BCB4;
	// mr r30,r25
	r30.u64 = r25.u64;
	// addi r29,r31,9469
	r29.s64 = r31.s64 + 9469;
loc_8238BC78:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823db730
	ctx.lr = 0x8238BC84;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238bca4
	if (cr6.eq) goto loc_8238BCA4;
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,8176
	r29.s64 = r29.s64 + 8176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8238bc78
	if (cr6.lt) goto loc_8238BC78;
	// b 0x8238bcb4
	goto loc_8238BCB4;
loc_8238BCA4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stbx r24,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r24.u8);
	// mr r27,r24
	r27.u64 = r24.u64;
	// stw r11,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r11.u32);
loc_8238BCB4:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238bd18
	if (!cr6.eq) goto loc_8238BD18;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238f550
	ctx.lr = 0x8238BCC8;
	sub_8238F550(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238f980
	ctx.lr = 0x8238BCD4;
	sub_8238F980(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238f968
	ctx.lr = 0x8238BCE0;
	sub_8238F968(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82390b18
	ctx.lr = 0x8238BCF0;
	sub_82390B18(ctx, base);
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// stw r25,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r25.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r24,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r24.u8);
	// addi r3,r31,1360
	ctx.r3.s64 = r31.s64 + 1360;
	// stw r11,1340(r31)
	PPC_STORE_U32(r31.u32 + 1340, r11.u32);
	// bl 0x8238efe0
	ctx.lr = 0x8238BD10;
	sub_8238EFE0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238ed78
	ctx.lr = 0x8238BD18;
	sub_8238ED78(ctx, base);
loc_8238BD18:
	// addi r1,r1,8352
	ctx.r1.s64 = ctx.r1.s64 + 8352;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8238BD20"))) PPC_WEAK_FUNC(sub_8238BD20);
PPC_FUNC_IMPL(__imp__sub_8238BD20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
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
	ctx.lr = 0x8238BD28;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,4100
	r11.s64 = 268697600;
	// lis r10,4100
	ctx.r10.s64 = 268697600;
	// lis r9,4100
	ctx.r9.s64 = 268697600;
	// lis r8,4100
	ctx.r8.s64 = 268697600;
	// lis r7,4100
	ctx.r7.s64 = 268697600;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// ori r5,r9,39
	ctx.r5.u64 = ctx.r9.u64 | 39;
	// ori r4,r8,40
	ctx.r4.u64 = ctx.r8.u64 | 40;
	// ori r3,r7,41
	ctx.r3.u64 = ctx.r7.u64 | 41;
	// stw r5,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r5.u32);
	// ori r6,r10,38
	ctx.r6.u64 = ctx.r10.u64 | 38;
	// stw r4,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r4.u32);
	// ori r27,r11,24
	r27.u64 = r11.u64 | 24;
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// stw r6,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r6.u32);
	// stw r27,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r31,80
	ctx.r7.s64 = r31.s64 + 80;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r5,5
	ctx.r5.s64 = 5;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244a758
	ctx.lr = 0x8238BD9C;
	sub_8244A758(ctx, base);
	// cmplwi cr6,r3,122
	cr6.compare<uint32_t>(ctx.r3.u32, 122, xer);
	// bne cr6,0x8238c040
	if (!cr6.eq) goto loc_8238C040;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238c040
	if (cr6.eq) goto loc_8238C040;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8238BDBC;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r31,80
	ctx.r7.s64 = r31.s64 + 80;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// bl 0x8244a758
	ctx.lr = 0x8238BDE8;
	sub_8244A758(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8238c040
	if (!cr6.eq) goto loc_8238C040;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// ori r9,r10,57424
	ctx.r9.u64 = ctx.r10.u64 | 57424;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8238bfac
	if (!cr6.gt) goto loc_8238BFAC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r26,-32256
	r26.s64 = -2113929216;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// lfs f12,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8238BE34:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x8238bf98
	if (!cr6.eq) goto loc_8238BF98;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// subf r10,r27,r10
	ctx.r10.s64 = ctx.r10.s64 - r27.s64;
	// cmplwi cr6,r10,17
	cr6.compare<uint32_t>(ctx.r10.u32, 17, xer);
	// bgt cr6,0x8238bf98
	if (cr6.gt) goto loc_8238BF98;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-16784
	r12.s64 = r12.s64 + -16784;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_8238BF38;
	case 1:
		goto loc_8238BF98;
	case 2:
		goto loc_8238BF98;
	case 3:
		goto loc_8238BF98;
	case 4:
		goto loc_8238BF98;
	case 5:
		goto loc_8238BF98;
	case 6:
		goto loc_8238BF98;
	case 7:
		goto loc_8238BF98;
	case 8:
		goto loc_8238BF98;
	case 9:
		goto loc_8238BF98;
	case 10:
		goto loc_8238BF98;
	case 11:
		goto loc_8238BF98;
	case 12:
		goto loc_8238BF98;
	case 13:
		goto loc_8238BF98;
	case 14:
		goto loc_8238BEB8;
	case 15:
		goto loc_8238BECC;
	case 16:
		goto loc_8238BF98;
	case 17:
		goto loc_8238BF28;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-16584(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16584);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16712(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16712);
	// lwz r17,-16692(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16692);
	// lwz r17,-16488(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16488);
	// lwz r17,-16600(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -16600);
loc_8238BEB8:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x8238bf98
	goto loc_8238BF98;
loc_8238BECC:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// add r10,r29,r9
	ctx.r10.u64 = r29.u64 + ctx.r9.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8238bf10
	if (cr6.eq) goto loc_8238BF10;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lwz r11,1208(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1208);
	// beq cr6,0x8238befc
	if (cr6.eq) goto loc_8238BEFC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8238bf90
	if (cr6.eq) goto loc_8238BF90;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// stw r3,1208(r29)
	PPC_STORE_U32(r29.u32 + 1208, ctx.r3.u32);
	// b 0x8238bf94
	goto loc_8238BF94;
loc_8238BEFC:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8238bf90
	if (cr6.eq) goto loc_8238BF90;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// stw r6,1208(r29)
	PPC_STORE_U32(r29.u32 + 1208, ctx.r6.u32);
	// b 0x8238bf94
	goto loc_8238BF94;
loc_8238BF10:
	// lwz r11,1208(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238bf90
	if (cr6.eq) goto loc_8238BF90;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// stw r28,1208(r29)
	PPC_STORE_U32(r29.u32 + 1208, r28.u32);
	// b 0x8238bf94
	goto loc_8238BF94;
loc_8238BF28:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x8238bf98
	goto loc_8238BF98;
loc_8238BF38:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lfs f11,1224(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 1224);
	ctx.f11.f64 = double(temp.f32);
	// add r10,r29,r9
	ctx.r10.u64 = r29.u64 + ctx.r9.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8238bf7c
	if (cr6.eq) goto loc_8238BF7C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8238bf68
	if (cr6.eq) goto loc_8238BF68;
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x8238bf90
	if (cr6.eq) goto loc_8238BF90;
	// stfs f0,1224(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 1224, temp.u32);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// b 0x8238bf94
	goto loc_8238BF94;
loc_8238BF68:
	// fcmpu cr6,f11,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// beq cr6,0x8238bf90
	if (cr6.eq) goto loc_8238BF90;
	// stfs f13,1224(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 1224, temp.u32);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// b 0x8238bf94
	goto loc_8238BF94;
loc_8238BF7C:
	// fcmpu cr6,f11,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// beq cr6,0x8238bf90
	if (cr6.eq) goto loc_8238BF90;
	// stfs f12,1224(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 1224, temp.u32);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// b 0x8238bf94
	goto loc_8238BF94;
loc_8238BF90:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8238BF94:
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
loc_8238BF98:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,40
	ctx.r8.s64 = ctx.r8.s64 + 40;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x8238be34
	if (cr6.lt) goto loc_8238BE34;
loc_8238BFAC:
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// beq cr6,0x8238bfcc
	if (cr6.eq) goto loc_8238BFCC;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8238BFCC:
	// lhz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// add r9,r29,r9
	ctx.r9.u64 = r29.u64 + ctx.r9.u64;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// beq cr6,0x8238bff4
	if (cr6.eq) goto loc_8238BFF4;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// b 0x8238bff8
	goto loc_8238BFF8;
loc_8238BFF4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8238BFF8:
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
	// lhz r8,2(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// cmpw cr6,r7,r4
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, xer);
	// beq cr6,0x8238c038
	if (cr6.eq) goto loc_8238C038;
	// sth r11,2(r29)
	PPC_STORE_U16(r29.u32 + 2, r11.u16);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9240
	return;
loc_8238C038:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stb r11,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r11.u8);
loc_8238C040:
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8238C048"))) PPC_WEAK_FUNC(sub_8238C048);
PPC_FUNC_IMPL(__imp__sub_8238C048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,1324(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1324);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,3
	r11.s64 = 196608;
	// stb r4,1324(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1324, ctx.r4.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r9,r11,57424
	ctx.r9.u64 = r11.u64 | 57424;
	// stbx r10,r3,r9
	PPC_STORE_U8(ctx.r3.u32 + ctx.r9.u32, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238C070"))) PPC_WEAK_FUNC(sub_8238C070);
PPC_FUNC_IMPL(__imp__sub_8238C070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,3
	r11.s64 = 196608;
	// stw r4,1320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1320, ctx.r4.u32);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// ori r9,r11,57424
	ctx.r9.u64 = r11.u64 | 57424;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r4,-6752(r10)
	PPC_STORE_U32(ctx.r10.u32 + -6752, ctx.r4.u32);
	// stbx r8,r3,r9
	PPC_STORE_U8(ctx.r3.u32 + ctx.r9.u32, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238C090"))) PPC_WEAK_FUNC(sub_8238C090);
PPC_FUNC_IMPL(__imp__sub_8238C090) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r6,r4,310
	ctx.r6.s64 = ctx.r4.s64 + 310;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fsel f10,f1,f1,f0
	ctx.f10.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsel f9,f1,f1,f0
	ctx.f9.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f0,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	f0.f64 = double(temp.f32);
	// lfs f12,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f8,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f6,f7,f13,f9
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// fmadds f5,f6,f0,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f4.u64);
	// lwz r5,-12(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f3,-16(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f0,f1,f11
	f0.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fcmpu cr6,f8,f0
	cr6.compare(ctx.f8.f64, f0.f64);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// stfsx f0,r11,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,57424
	ctx.r8.u64 = ctx.r10.u64 | 57424;
	// stbx r9,r3,r8
	PPC_STORE_U8(ctx.r3.u32 + ctx.r8.u32, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238C11C"))) PPC_WEAK_FUNC(sub_8238C11C);
PPC_FUNC_IMPL(__imp__sub_8238C11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C120"))) PPC_WEAK_FUNC(sub_8238C120);
PPC_FUNC_IMPL(__imp__sub_8238C120) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8238C128;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r29,1
	r29.s64 = 1;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r30,0
	r30.s64 = 0;
	// sth r29,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r29.u16);
	// li r8,2
	ctx.r8.s64 = 2;
	// sth r9,2(r31)
	PPC_STORE_U16(r31.u32 + 2, ctx.r9.u16);
	// li r7,4
	ctx.r7.s64 = 4;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,-7212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7212);
	f0.f64 = double(temp.f32);
	// stw r29,1188(r31)
	PPC_STORE_U32(r31.u32 + 1188, r29.u32);
	// stfs f31,1224(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1224, temp.u32);
	// stw r29,1192(r31)
	PPC_STORE_U32(r31.u32 + 1192, r29.u32);
	// stw r30,1196(r31)
	PPC_STORE_U32(r31.u32 + 1196, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r8,1200(r31)
	PPC_STORE_U32(r31.u32 + 1200, ctx.r8.u32);
	// stw r30,1204(r31)
	PPC_STORE_U32(r31.u32 + 1204, r30.u32);
	// stw r7,1208(r31)
	PPC_STORE_U32(r31.u32 + 1208, ctx.r7.u32);
	// stw r30,1212(r31)
	PPC_STORE_U32(r31.u32 + 1212, r30.u32);
	// stw r29,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, r29.u32);
	// stw r30,1220(r31)
	PPC_STORE_U32(r31.u32 + 1220, r30.u32);
	// stfs f0,1232(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1232, temp.u32);
	// bl 0x82387928
	ctx.lr = 0x8238C194;
	sub_82387928(ctx, base);
	// cntlzw r4,r3
	ctx.r4.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stw r3,1320(r31)
	PPC_STORE_U32(r31.u32 + 1320, ctx.r3.u32);
	// addi r10,r5,-12112
	ctx.r10.s64 = ctx.r5.s64 + -12112;
	// xori r9,r11,1
	ctx.r9.u64 = r11.u64 ^ 1;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// or r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 | ctx.r6.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// sth r4,1238(r31)
	PPC_STORE_U16(r31.u32 + 1238, ctx.r4.u16);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238c1e0
	if (cr6.eq) goto loc_8238C1E0;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// b 0x8238c1e4
	goto loc_8238C1E4;
loc_8238C1E0:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_8238C1E4:
	// fsel f10,f13,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f31.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsel f9,f13,f13,f31
	ctx.f9.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f31.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,1240(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1240, temp.u32);
	// li r8,7
	ctx.r8.s64 = 7;
	// stfs f0,1248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1248, temp.u32);
	// stfs f0,1252(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1252, temp.u32);
	// stw r30,1260(r31)
	PPC_STORE_U32(r31.u32 + 1260, r30.u32);
	// lfs f13,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,1264(r31)
	PPC_STORE_U8(r31.u32 + 1264, r30.u8);
	// lfs f12,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// sth r30,1274(r31)
	PPC_STORE_U16(r31.u32 + 1274, r30.u16);
	// lfs f11,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f11.f64 = double(temp.f32);
	// sth r30,1236(r31)
	PPC_STORE_U16(r31.u32 + 1236, r30.u16);
	// stfs f0,1256(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1256, temp.u32);
	// stb r30,1324(r31)
	PPC_STORE_U8(r31.u32 + 1324, r30.u8);
	// stw r8,1328(r31)
	PPC_STORE_U32(r31.u32 + 1328, ctx.r8.u32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// stb r29,1325(r31)
	PPC_STORE_U8(r31.u32 + 1325, r29.u8);
	// stb r29,1336(r31)
	PPC_STORE_U8(r31.u32 + 1336, r29.u8);
	// fsel f7,f8,f0,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fmadds f6,f7,f13,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f5.u64);
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f4,88(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f2,f11
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// stfs f1,1244(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1244, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238C278"))) PPC_WEAK_FUNC(sub_8238C278);
PPC_FUNC_IMPL(__imp__sub_8238C278) {
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
	ctx.lr = 0x8238C280;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8336(r1)
	ea = -8336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r26,r11,-12120
	r26.s64 = r11.s64 + -12120;
	// li r29,0
	r29.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r30,r29
	r30.u64 = r29.u64;
	// lhz r27,4(r26)
	r27.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// stw r29,1340(r25)
	PPC_STORE_U32(r25.u32 + 1340, r29.u32);
	// stw r10,1344(r25)
	PPC_STORE_U32(r25.u32 + 1344, ctx.r10.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8238c32c
	if (!cr6.gt) goto loc_8238C32C;
	// addis r31,r25,4
	r31.s64 = r25.s64 + 262144;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r31,-15422
	r31.s64 = r31.s64 + -15422;
	// addi r28,r25,1360
	r28.s64 = r25.s64 + 1360;
	// li r24,1
	r24.s64 = 1;
	// addi r23,r11,3998
	r23.s64 = r11.s64 + 3998;
loc_8238C2D0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238f550
	ctx.lr = 0x8238C2D8;
	sub_8238F550(ctx, base);
	// cmpwi cr6,r30,30
	cr6.compare<int32_t>(r30.s32, 30, xer);
	// bge cr6,0x8238c2f8
	if (!cr6.lt) goto loc_8238C2F8;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238f968
	ctx.lr = 0x8238C2EC;
	sub_8238F968(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238ee58
	ctx.lr = 0x8238C2F8;
	sub_8238EE58(ctx, base);
loc_8238C2F8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// sth r24,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r24.u16);
	// stw r10,-78(r31)
	PPC_STORE_U32(r31.u32 + -78, ctx.r10.u32);
	// bl 0x8238ed78
	ctx.lr = 0x8238C314;
	sub_8238ED78(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,8176
	r28.s64 = r28.s64 + 8176;
	// addi r29,r29,104
	r29.s64 = r29.s64 + 104;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x8238c2d0
	if (cr6.lt) goto loc_8238C2D0;
loc_8238C32C:
	// stw r27,1348(r25)
	PPC_STORE_U32(r25.u32 + 1348, r27.u32);
	// addi r1,r1,8336
	ctx.r1.s64 = ctx.r1.s64 + 8336;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8238C338"))) PPC_WEAK_FUNC(sub_8238C338);
PPC_FUNC_IMPL(__imp__sub_8238C338) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82387b90
	ctx.lr = 0x8238C354;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238abb8
	ctx.lr = 0x8238C35C;
	sub_8238ABB8(ctx, base);
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

__attribute__((alias("__imp__sub_8238C370"))) PPC_WEAK_FUNC(sub_8238C370);
PPC_FUNC_IMPL(__imp__sub_8238C370) {
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
	// bl 0x82387b90
	ctx.lr = 0x8238C388;
	sub_82387B90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,1344(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8238C3A8"))) PPC_WEAK_FUNC(sub_8238C3A8);
PPC_FUNC_IMPL(__imp__sub_8238C3A8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82387b90
	ctx.lr = 0x8238C3C4;
	sub_82387B90(ctx, base);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// stw r31,1344(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1344, r31.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r10,r10,57424
	ctx.r10.u64 = ctx.r10.u64 | 57424;
	// stbx r9,r3,r10
	PPC_STORE_U8(ctx.r3.u32 + ctx.r10.u32, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_8238C3EC"))) PPC_WEAK_FUNC(sub_8238C3EC);
PPC_FUNC_IMPL(__imp__sub_8238C3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C3F0"))) PPC_WEAK_FUNC(sub_8238C3F0);
PPC_FUNC_IMPL(__imp__sub_8238C3F0) {
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
	// bl 0x82387b90
	ctx.lr = 0x8238C408;
	sub_82387B90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,1340(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8238C428"))) PPC_WEAK_FUNC(sub_8238C428);
PPC_FUNC_IMPL(__imp__sub_8238C428) {
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
	// bl 0x82387a98
	ctx.lr = 0x8238C440;
	sub_82387A98(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8238C460"))) PPC_WEAK_FUNC(sub_8238C460);
PPC_FUNC_IMPL(__imp__sub_8238C460) {
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
	// bl 0x8238b520
	ctx.lr = 0x8238C480;
	sub_8238B520(ctx, base);
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

__attribute__((alias("__imp__sub_8238C49C"))) PPC_WEAK_FUNC(sub_8238C49C);
PPC_FUNC_IMPL(__imp__sub_8238C49C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C4A0"))) PPC_WEAK_FUNC(sub_8238C4A0);
PPC_FUNC_IMPL(__imp__sub_8238C4A0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82387b90
	ctx.lr = 0x8238C4C4;
	sub_82387B90(ctx, base);
	// lis r9,3
	ctx.r9.s64 = 196608;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r8,r3,r31
	ctx.r8.u64 = ctx.r3.u64 + r31.u64;
	// ori r7,r9,57220
	ctx.r7.u64 = ctx.r9.u64 | 57220;
	// lbzx r6,r8,r7
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8238C4F4"))) PPC_WEAK_FUNC(sub_8238C4F4);
PPC_FUNC_IMPL(__imp__sub_8238C4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C4F8"))) PPC_WEAK_FUNC(sub_8238C4F8);
PPC_FUNC_IMPL(__imp__sub_8238C4F8) {
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
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8288(r1)
	ea = -8288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8238c580
	if (cr6.eq) goto loc_8238C580;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238f550
	ctx.lr = 0x8238C528;
	sub_8238F550(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82390b18
	ctx.lr = 0x8238C538;
	sub_82390B18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238c578
	if (cr6.eq) goto loc_8238C578;
	// bl 0x82387b90
	ctx.lr = 0x8238C548;
	sub_82387B90(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238f968
	ctx.lr = 0x8238C558;
	sub_8238F968(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238b6e8
	ctx.lr = 0x8238C564;
	sub_8238B6E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x8238C570;
	sub_8238ED78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x8238c584
	goto loc_8238C584;
loc_8238C578:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8238ed78
	ctx.lr = 0x8238C580;
	sub_8238ED78(ctx, base);
loc_8238C580:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8238C584:
	// addi r1,r1,8288
	ctx.r1.s64 = ctx.r1.s64 + 8288;
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

__attribute__((alias("__imp__sub_8238C59C"))) PPC_WEAK_FUNC(sub_8238C59C);
PPC_FUNC_IMPL(__imp__sub_8238C59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C5A0"))) PPC_WEAK_FUNC(sub_8238C5A0);
PPC_FUNC_IMPL(__imp__sub_8238C5A0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8238C5A8;
	// stfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// stwu r1,-8640(r1)
	ea = -8640 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// lis r9,3
	ctx.r9.s64 = 196608;
	// lis r8,3
	ctx.r8.s64 = 196608;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,1340(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// mr r20,r22
	r20.u64 = r22.u64;
	// ori r21,r9,50114
	r21.u64 = ctx.r9.u64 | 50114;
	// ori r23,r8,50032
	r23.u64 = ctx.r8.u64 | 50032;
	// li r18,1
	r18.s64 = 1;
	// mr r27,r22
	r27.u64 = r22.u64;
	// addi r17,r11,-12120
	r17.s64 = r11.s64 + -12120;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8238c6c8
	if (!cr6.gt) goto loc_8238C6C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r25,r10,50040
	r25.u64 = ctx.r10.u64 | 50040;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lfs f31,32680(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	f31.f64 = double(temp.f32);
	// ori r19,r9,65535
	r19.u64 = ctx.r9.u64 | 65535;
loc_8238C60C:
	// mulli r11,r27,84
	r11.s64 = r27.s64 * 84;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r9,r11,r21
	ctx.r9.u64 = r11.u64 + r21.u64;
	// lhzx r10,r11,r21
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + r21.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,52684
	cr6.compare<uint32_t>(ctx.r10.u32, 52684, xer);
	// beq cr6,0x8238c630
	if (cr6.eq) goto loc_8238C630;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x8238c66c
	if (!cr6.eq) goto loc_8238C66C;
loc_8238C630:
	// add r10,r11,r25
	ctx.r10.u64 = r11.u64 + r25.u64;
	// lwzx r11,r11,r25
	r11.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// cmplwi cr6,r11,52684
	cr6.compare<uint32_t>(r11.u32, 52684, xer);
	// bne cr6,0x8238c64c
	if (!cr6.eq) goto loc_8238C64C;
	// lis r11,0
	r11.s64 = 0;
	// ori r11,r11,52684
	r11.u64 = r11.u64 | 52684;
	// b 0x8238c664
	goto loc_8238C664;
loc_8238C64C:
	// cmpw cr6,r11,r19
	cr6.compare<int32_t>(r11.s32, r19.s32, xer);
	// bge cr6,0x8238c660
	if (!cr6.lt) goto loc_8238C660;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8238c664
	goto loc_8238C664;
loc_8238C660:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8238C664:
	// stw r22,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r22.u32);
	// sth r11,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, r11.u16);
loc_8238C66C:
	// mulli r11,r27,8176
	r11.s64 = r27.s64 * 8176;
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// addi r28,r29,9469
	r28.s64 = r29.s64 + 9469;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82396408
	ctx.lr = 0x8238C680;
	sub_82396408(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8238c86c
	if (cr6.lt) goto loc_8238C86C;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mulli r10,r31,104
	ctx.r10.s64 = r31.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823961c0
	ctx.lr = 0x8238C69C;
	sub_823961C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238c86c
	if (cr6.eq) goto loc_8238C86C;
	// stw r31,9448(r29)
	PPC_STORE_U32(r29.u32 + 9448, r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,1360
	ctx.r3.s64 = r29.s64 + 1360;
	// bl 0x82390768
	ctx.lr = 0x8238C6B8;
	sub_82390768(ctx, base);
loc_8238C6B8:
	// lwz r11,1340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8238c60c
	if (cr6.lt) goto loc_8238C60C;
loc_8238C6C8:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r26,r10,57424
	r26.u64 = ctx.r10.u64 | 57424;
	// beq cr6,0x8238c72c
	if (cr6.eq) goto loc_8238C72C;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x8238f550
	ctx.lr = 0x8238C6E4;
	sub_8238F550(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-18844
	ctx.r4.s64 = r11.s64 + -18844;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82390b18
	ctx.lr = 0x8238C6F8;
	sub_82390B18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238c724
	if (cr6.eq) goto loc_8238C724;
	// bl 0x82387b90
	ctx.lr = 0x8238C708;
	sub_82387B90(ctx, base);
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8238b6e8
	ctx.lr = 0x8238C714;
	sub_8238B6E8(ctx, base);
	// mulli r11,r3,84
	r11.s64 = ctx.r3.s64 * 84;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// sthx r18,r11,r21
	PPC_STORE_U16(r11.u32 + r21.u32, r18.u16);
	// stbx r18,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r18.u8);
loc_8238C724:
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x8238ed78
	ctx.lr = 0x8238C72C;
	sub_8238ED78(ctx, base);
loc_8238C72C:
	// lwz r11,1348(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1348);
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238c780
	if (!cr6.gt) goto loc_8238C780;
	// add r29,r30,r23
	r29.u64 = r30.u64 + r23.u64;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238C748:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82396f58
	ctx.lr = 0x8238C750;
	sub_82396F58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8238c76c
	if (cr6.lt) goto loc_8238C76C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f070
	ctx.lr = 0x8238C764;
	sub_8238F070(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
loc_8238C76C:
	// lwz r11,1348(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1348);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,84
	r31.s64 = r31.s64 + 84;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8238c748
	if (cr6.lt) goto loc_8238C748;
loc_8238C780:
	// stw r28,1348(r30)
	PPC_STORE_U32(r30.u32 + 1348, r28.u32);
	// lhz r11,4(r17)
	r11.u64 = PPC_LOAD_U16(r17.u32 + 4);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x8238c848
	if (!cr6.lt) goto loc_8238C848;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238c844
	if (!cr6.gt) goto loc_8238C844;
	// mulli r10,r28,84
	ctx.r10.s64 = r28.s64 * 84;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// mr r25,r11
	r25.u64 = r11.u64;
	// add r29,r10,r23
	r29.u64 = ctx.r10.u64 + r23.u64;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r22
	r31.u64 = r22.u64;
	// ori r24,r10,50036
	r24.u64 = ctx.r10.u64 | 50036;
	// addi r27,r11,-10208
	r27.s64 = r11.s64 + -10208;
loc_8238C7BC:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// lwz r9,1348(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1348);
	// add r8,r31,r11
	ctx.r8.u64 = r31.u64 + r11.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// ble cr6,0x8238c7fc
	if (!cr6.gt) goto loc_8238C7FC;
	// add r11,r30,r24
	r11.u64 = r30.u64 + r24.u64;
loc_8238C7DC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x8238c838
	if (cr6.eq) goto loc_8238C838;
	// lwz r8,1348(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1348);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,84
	r11.s64 = r11.s64 + 84;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8238c7dc
	if (cr6.lt) goto loc_8238C7DC;
loc_8238C7FC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8238ffc8
	ctx.lr = 0x8238C804;
	sub_8238FFC8(ctx, base);
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// bl 0x8238f070
	ctx.lr = 0x8238C820;
	sub_8238F070(ctx, base);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// stbx r18,r30,r26
	PPC_STORE_U8(r30.u32 + r26.u32, r18.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// bl 0x821d2028
	ctx.lr = 0x8238C838;
	sub_821D2028(ctx, base);
loc_8238C838:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bne 0x8238c7bc
	if (!cr0.eq) goto loc_8238C7BC;
loc_8238C844:
	// stw r28,1348(r30)
	PPC_STORE_U32(r30.u32 + 1348, r28.u32);
loc_8238C848:
	// lis r11,-32199
	r11.s64 = -2110193664;
	// li r5,84
	ctx.r5.s64 = 84;
	// addi r6,r11,-21752
	ctx.r6.s64 = r11.s64 + -21752;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r23
	ctx.r3.u64 = r30.u64 + r23.u64;
	// bl 0x823dcf08
	ctx.lr = 0x8238C860;
	sub_823DCF08(ctx, base);
	// addi r1,r1,8640
	ctx.r1.s64 = ctx.r1.s64 + 8640;
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_8238C86C:
	// li r5,127
	ctx.r5.s64 = 127;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// mr r26,r22
	r26.u64 = r22.u64;
	// bl 0x823db670
	ctx.lr = 0x8238C880;
	sub_823DB670(ctx, base);
	// addi r29,r29,9448
	r29.s64 = r29.s64 + 9448;
	// stb r22,319(r1)
	PPC_STORE_U8(ctx.r1.u32 + 319, r22.u8);
loc_8238C888:
	// lwz r11,1340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// mr r28,r22
	r28.u64 = r22.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238c6b8
	if (!cr6.gt) goto loc_8238C6B8;
	// addi r31,r30,9469
	r31.s64 = r30.s64 + 9469;
loc_8238C89C:
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db730
	ctx.lr = 0x8238C8A8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238c8c8
	if (cr6.eq) goto loc_8238C8C8;
	// lwz r11,1340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,8176
	r31.s64 = r31.s64 + 8176;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8238c89c
	if (cr6.lt) goto loc_8238C89C;
	// b 0x8238c6b8
	goto loc_8238C6B8;
loc_8238C8C8:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x8238c6b8
	if (cr6.lt) goto loc_8238C6B8;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238c93c
	if (!cr6.eq) goto loc_8238C93C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,18508(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 18508);
	// mulli r31,r11,84
	r31.s64 = r11.s64 * 84;
	// add r10,r31,r30
	ctx.r10.u64 = r31.u64 + r30.u64;
	// add r26,r10,r25
	r26.u64 = ctx.r10.u64 + r25.u64;
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x826b93e0
	ctx.lr = 0x8238C91C;
	sub_826B93E0(ctx, base);
	// stw r22,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r22.u32);
	// bl 0x82387b90
	ctx.lr = 0x8238C924;
	sub_82387B90(ctx, base);
	// add r7,r31,r3
	ctx.r7.u64 = r31.u64 + ctx.r3.u64;
	// add r3,r7,r23
	ctx.r3.u64 = ctx.r7.u64 + r23.u64;
	// bl 0x8238f730
	ctx.lr = 0x8238C930;
	sub_8238F730(ctx, base);
	// mr r26,r18
	r26.u64 = r18.u64;
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r29,r29,-8176
	r29.s64 = r29.s64 + -8176;
loc_8238C93C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238aa30
	ctx.lr = 0x8238C948;
	sub_8238AA30(ctx, base);
	// lwz r11,1340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8238c888
	if (!cr6.eq) goto loc_8238C888;
	// mr r20,r18
	r20.u64 = r18.u64;
	// b 0x8238c888
	goto loc_8238C888;
}

__attribute__((alias("__imp__sub_8238C95C"))) PPC_WEAK_FUNC(sub_8238C95C);
PPC_FUNC_IMPL(__imp__sub_8238C95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C960"))) PPC_WEAK_FUNC(sub_8238C960);
PPC_FUNC_IMPL(__imp__sub_8238C960) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82391b18
	ctx.lr = 0x8238C97C;
	sub_82391B18(ctx, base);
	// addi r3,r31,596
	ctx.r3.s64 = r31.s64 + 596;
	// bl 0x82391b18
	ctx.lr = 0x8238C984;
	sub_82391B18(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,1260(r31)
	PPC_STORE_U32(r31.u32 + 1260, r11.u32);
	// bl 0x8238c120
	ctx.lr = 0x8238C994;
	sub_8238C120(ctx, base);
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

__attribute__((alias("__imp__sub_8238C9AC"))) PPC_WEAK_FUNC(sub_8238C9AC);
PPC_FUNC_IMPL(__imp__sub_8238C9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C9B0"))) PPC_WEAK_FUNC(sub_8238C9B0);
PPC_FUNC_IMPL(__imp__sub_8238C9B0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8238c120
	ctx.lr = 0x8238C9CC;
	sub_8238C120(ctx, base);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// li r30,0
	r30.s64 = 0;
	// li r5,6468
	ctx.r5.s64 = 6468;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,1340(r31)
	PPC_STORE_U32(r31.u32 + 1340, r30.u32);
	// addi r3,r3,-15504
	ctx.r3.s64 = ctx.r3.s64 + -15504;
	// stw r30,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r30.u32);
	// stw r30,1348(r31)
	PPC_STORE_U32(r31.u32 + 1348, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8238C9F0;
	sub_823D9890(ctx, base);
	// lis r11,3
	r11.s64 = 196608;
	// addis r9,r31,4
	ctx.r9.s64 = r31.s64 + 262144;
	// ori r8,r11,57280
	ctx.r8.u64 = r11.u64 | 57280;
	// addi r9,r9,-8254
	ctx.r9.s64 = ctx.r9.s64 + -8254;
	// addis r11,r31,4
	r11.s64 = r31.s64 + 262144;
	// li r10,60
	ctx.r10.s64 = 60;
	// addi r11,r11,-8316
	r11.s64 = r11.s64 + -8316;
	// sthx r30,r31,r8
	PPC_STORE_U16(r31.u32 + ctx.r8.u32, r30.u16);
	// stb r30,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r30.u8);
	// stb r30,1(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1, r30.u8);
	// stb r30,2(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2, r30.u8);
	// stb r30,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, r30.u8);
	// stb r30,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r30.u8);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8238CA2C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8238ca2c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238CA2C;
	// addis r11,r31,4
	r11.s64 = r31.s64 + 262144;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r11,-8248
	r11.s64 = r11.s64 + -8248;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8238CA48:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8238ca48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238CA48;
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

__attribute__((alias("__imp__sub_8238CA6C"))) PPC_WEAK_FUNC(sub_8238CA6C);
PPC_FUNC_IMPL(__imp__sub_8238CA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CA70"))) PPC_WEAK_FUNC(sub_8238CA70);
PPC_FUNC_IMPL(__imp__sub_8238CA70) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r3,-12052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8238CA94;
	sub_82397BA8(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r9,r31,r3
	ctx.r9.s64 = ctx.r3.s64 - r31.s64;
	// li r10,74
	ctx.r10.s64 = 74;
loc_8238CAA0:
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8238caa0
	if (!cr0.eq) goto loc_8238CAA0;
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

__attribute__((alias("__imp__sub_8238CAD4"))) PPC_WEAK_FUNC(sub_8238CAD4);
PPC_FUNC_IMPL(__imp__sub_8238CAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CAD8"))) PPC_WEAK_FUNC(sub_8238CAD8);
PPC_FUNC_IMPL(__imp__sub_8238CAD8) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82387b90
	ctx.lr = 0x8238CAFC;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238b6e8
	ctx.lr = 0x8238CB04;
	sub_8238B6E8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8238CB24"))) PPC_WEAK_FUNC(sub_8238CB24);
PPC_FUNC_IMPL(__imp__sub_8238CB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CB28"))) PPC_WEAK_FUNC(sub_8238CB28);
PPC_FUNC_IMPL(__imp__sub_8238CB28) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82387b90
	ctx.lr = 0x8238CB4C;
	sub_82387B90(ctx, base);
	// mulli r10,r30,8176
	ctx.r10.s64 = r30.s64 * 8176;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r3,r10
	r11.u64 = ctx.r3.u64 + ctx.r10.u64;
	// addi r11,r11,1360
	r11.s64 = r11.s64 + 1360;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_8238CB78"))) PPC_WEAK_FUNC(sub_8238CB78);
PPC_FUNC_IMPL(__imp__sub_8238CB78) {
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
	ctx.lr = 0x8238CB80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82387b90
	ctx.lr = 0x8238CB94;
	sub_82387B90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r30,8176
	r11.s64 = r30.s64 * 8176;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238ee58
	ctx.lr = 0x8238CBAC;
	sub_8238EE58(ctx, base);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,57424
	ctx.r8.u64 = ctx.r10.u64 | 57424;
	// stbx r9,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, ctx.r9.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238CBC4"))) PPC_WEAK_FUNC(sub_8238CBC4);
PPC_FUNC_IMPL(__imp__sub_8238CBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CBC8"))) PPC_WEAK_FUNC(sub_8238CBC8);
PPC_FUNC_IMPL(__imp__sub_8238CBC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8238CBD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82391b18
	ctx.lr = 0x8238CBE0;
	sub_82391B18(ctx, base);
	// addi r3,r31,596
	ctx.r3.s64 = r31.s64 + 596;
	// bl 0x82391b18
	ctx.lr = 0x8238CBE8;
	sub_82391B18(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,1260(r31)
	PPC_STORE_U32(r31.u32 + 1260, r11.u32);
	// bl 0x8238c120
	ctx.lr = 0x8238CBF8;
	sub_8238C120(ctx, base);
	// addi r29,r31,1360
	r29.s64 = r31.s64 + 1360;
	// li r30,29
	r30.s64 = 29;
loc_8238CC00:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f550
	ctx.lr = 0x8238CC08;
	sub_8238F550(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,8176
	r29.s64 = r29.s64 + 8176;
	// bge 0x8238cc00
	if (!cr0.lt) goto loc_8238CC00;
	// addis r29,r31,4
	r29.s64 = r31.s64 + 262144;
	// li r30,76
	r30.s64 = 76;
	// addi r29,r29,-15504
	r29.s64 = r29.s64 + -15504;
loc_8238CC20:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238ffc8
	ctx.lr = 0x8238CC28;
	sub_8238FFC8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,84
	r29.s64 = r29.s64 + 84;
	// bge 0x8238cc20
	if (!cr0.lt) goto loc_8238CC20;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addis r11,r31,4
	r11.s64 = r31.s64 + 262144;
	// li r10,29
	ctx.r10.s64 = 29;
	// addi r11,r11,-9036
	r11.s64 = r11.s64 + -9036;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8238CC48:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bge 0x8238cc48
	if (!cr0.lt) goto loc_8238CC48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238c9b0
	ctx.lr = 0x8238CC74;
	sub_8238C9B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238CC80"))) PPC_WEAK_FUNC(sub_8238CC80);
PPC_FUNC_IMPL(__imp__sub_8238CC80) {
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
	ctx.lr = 0x8238CC88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lwz r3,-12052(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12052);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8238ccf4
	if (!cr6.gt) goto loc_8238CCF4;
loc_8238CCB0:
	// extsh r30,r31
	r30.s64 = r31.s16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82397ba8
	ctx.lr = 0x8238CCBC;
	sub_82397BA8(ctx, base);
	// lbz r11,604(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 604);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238cce0
	if (cr6.eq) goto loc_8238CCE0;
	// lbz r11,605(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 605);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238ccdc
	if (cr6.eq) goto loc_8238CCDC;
	// mr r26,r30
	r26.u64 = r30.u64;
	// b 0x8238cce0
	goto loc_8238CCE0;
loc_8238CCDC:
	// mr r29,r30
	r29.u64 = r30.u64;
loc_8238CCE0:
	// lwz r3,-12052(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12052);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238ccb0
	if (cr6.lt) goto loc_8238CCB0;
loc_8238CCF4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82397ba8
	ctx.lr = 0x8238CCFC;
	sub_82397BA8(ctx, base);
	// addi r11,r27,4
	r11.s64 = r27.s64 + 4;
	// li r10,74
	ctx.r10.s64 = 74;
loc_8238CD04:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8238cd04
	if (!cr0.eq) goto loc_8238CD04;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-12052(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8238CD30;
	sub_82397BA8(ctx, base);
	// addi r11,r27,596
	r11.s64 = r27.s64 + 596;
	// li r10,74
	ctx.r10.s64 = 74;
loc_8238CD38:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8238cd38
	if (!cr0.eq) goto loc_8238CD38;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8238CD60"))) PPC_WEAK_FUNC(sub_8238CD60);
PPC_FUNC_IMPL(__imp__sub_8238CD60) {
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
	// bl 0x8238b4a0
	ctx.lr = 0x8238CD80;
	sub_8238B4A0(ctx, base);
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

__attribute__((alias("__imp__sub_8238CD9C"))) PPC_WEAK_FUNC(sub_8238CD9C);
PPC_FUNC_IMPL(__imp__sub_8238CD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CDA0"))) PPC_WEAK_FUNC(sub_8238CDA0);
PPC_FUNC_IMPL(__imp__sub_8238CDA0) {
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
	// bl 0x8238c4f8
	ctx.lr = 0x8238CDC0;
	sub_8238C4F8(ctx, base);
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

__attribute__((alias("__imp__sub_8238CDDC"))) PPC_WEAK_FUNC(sub_8238CDDC);
PPC_FUNC_IMPL(__imp__sub_8238CDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CDE0"))) PPC_WEAK_FUNC(sub_8238CDE0);
PPC_FUNC_IMPL(__imp__sub_8238CDE0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82387b90
	ctx.lr = 0x8238CE04;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238ab50
	ctx.lr = 0x8238CE0C;
	sub_8238AB50(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8238CE2C"))) PPC_WEAK_FUNC(sub_8238CE2C);
PPC_FUNC_IMPL(__imp__sub_8238CE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CE30"))) PPC_WEAK_FUNC(sub_8238CE30);
PPC_FUNC_IMPL(__imp__sub_8238CE30) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8238c9b0
	ctx.lr = 0x8238CE50;
	sub_8238C9B0(ctx, base);
	// clrlwi r30,r30,24
	r30.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8238ce74
	if (cr6.eq) goto loc_8238CE74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238c278
	ctx.lr = 0x8238CE64;
	sub_8238C278(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8238ce74
	if (cr6.eq) goto loc_8238CE74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238cc80
	ctx.lr = 0x8238CE74;
	sub_8238CC80(ctx, base);
loc_8238CE74:
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

__attribute__((alias("__imp__sub_8238CE8C"))) PPC_WEAK_FUNC(sub_8238CE8C);
PPC_FUNC_IMPL(__imp__sub_8238CE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CE90"))) PPC_WEAK_FUNC(sub_8238CE90);
PPC_FUNC_IMPL(__imp__sub_8238CE90) {
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
	// lis r11,-32199
	r11.s64 = -2110193664;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-12960
	ctx.r4.s64 = r11.s64 + -12960;
	// addi r3,r10,-6764
	ctx.r3.s64 = ctx.r10.s64 + -6764;
	// bl 0x82554798
	ctx.lr = 0x8238CEB0;
	sub_82554798(ctx, base);
	// lis r9,-32199
	ctx.r9.s64 = -2110193664;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-12896
	ctx.r4.s64 = ctx.r9.s64 + -12896;
	// addi r3,r8,-6796
	ctx.r3.s64 = ctx.r8.s64 + -6796;
	// bl 0x82554798
	ctx.lr = 0x8238CEC4;
	sub_82554798(ctx, base);
	// lis r7,-32199
	ctx.r7.s64 = -2110193664;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-13608
	ctx.r4.s64 = ctx.r7.s64 + -13608;
	// addi r3,r6,-6828
	ctx.r3.s64 = ctx.r6.s64 + -6828;
	// bl 0x82554798
	ctx.lr = 0x8238CED8;
	sub_82554798(ctx, base);
	// lis r5,-32199
	ctx.r5.s64 = -2110193664;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r4,r5,-15560
	ctx.r4.s64 = ctx.r5.s64 + -15560;
	// addi r3,r3,-6868
	ctx.r3.s64 = ctx.r3.s64 + -6868;
	// bl 0x82554798
	ctx.lr = 0x8238CEEC;
	sub_82554798(ctx, base);
	// lis r11,-32199
	r11.s64 = -2110193664;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-15504
	ctx.r4.s64 = r11.s64 + -15504;
	// addi r3,r10,-6912
	ctx.r3.s64 = ctx.r10.s64 + -6912;
	// bl 0x82554798
	ctx.lr = 0x8238CF00;
	sub_82554798(ctx, base);
	// lis r9,-32199
	ctx.r9.s64 = -2110193664;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-15448
	ctx.r4.s64 = ctx.r9.s64 + -15448;
	// addi r3,r8,-6956
	ctx.r3.s64 = ctx.r8.s64 + -6956;
	// bl 0x82554798
	ctx.lr = 0x8238CF14;
	sub_82554798(ctx, base);
	// lis r7,-32199
	ctx.r7.s64 = -2110193664;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-13528
	ctx.r4.s64 = ctx.r7.s64 + -13528;
	// addi r3,r6,-6988
	ctx.r3.s64 = ctx.r6.s64 + -6988;
	// bl 0x82554798
	ctx.lr = 0x8238CF28;
	sub_82554798(ctx, base);
	// lis r5,-32199
	ctx.r5.s64 = -2110193664;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r4,r5,-13448
	ctx.r4.s64 = ctx.r5.s64 + -13448;
	// addi r3,r3,-7020
	ctx.r3.s64 = ctx.r3.s64 + -7020;
	// bl 0x82554798
	ctx.lr = 0x8238CF3C;
	sub_82554798(ctx, base);
	// lis r11,-32199
	r11.s64 = -2110193664;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-13448
	ctx.r4.s64 = r11.s64 + -13448;
	// addi r3,r10,-7052
	ctx.r3.s64 = ctx.r10.s64 + -7052;
	// bl 0x82554798
	ctx.lr = 0x8238CF50;
	sub_82554798(ctx, base);
	// lis r9,-32199
	ctx.r9.s64 = -2110193664;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-15376
	ctx.r4.s64 = ctx.r9.s64 + -15376;
	// addi r3,r8,-7092
	ctx.r3.s64 = ctx.r8.s64 + -7092;
	// bl 0x82554798
	ctx.lr = 0x8238CF64;
	sub_82554798(ctx, base);
	// lis r7,-32199
	ctx.r7.s64 = -2110193664;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,-12832
	ctx.r4.s64 = ctx.r7.s64 + -12832;
	// addi r3,r6,-7124
	ctx.r3.s64 = ctx.r6.s64 + -7124;
	// bl 0x82554798
	ctx.lr = 0x8238CF78;
	sub_82554798(ctx, base);
	// lis r5,-32199
	ctx.r5.s64 = -2110193664;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r4,r5,-15320
	ctx.r4.s64 = ctx.r5.s64 + -15320;
	// addi r3,r3,-7148
	ctx.r3.s64 = ctx.r3.s64 + -7148;
	// bl 0x82554798
	ctx.lr = 0x8238CF8C;
	sub_82554798(ctx, base);
	// lis r11,-32199
	r11.s64 = -2110193664;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r11,-15264
	ctx.r4.s64 = r11.s64 + -15264;
	// addi r3,r10,-7180
	ctx.r3.s64 = ctx.r10.s64 + -7180;
	// bl 0x82554798
	ctx.lr = 0x8238CFA0;
	sub_82554798(ctx, base);
	// lis r9,-32199
	ctx.r9.s64 = -2110193664;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r4,r9,-15200
	ctx.r4.s64 = ctx.r9.s64 + -15200;
	// addi r3,r8,-7208
	ctx.r3.s64 = ctx.r8.s64 + -7208;
	// bl 0x82554798
	ctx.lr = 0x8238CFB4;
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

__attribute__((alias("__imp__sub_8238CFC4"))) PPC_WEAK_FUNC(sub_8238CFC4);
PPC_FUNC_IMPL(__imp__sub_8238CFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CFC8"))) PPC_WEAK_FUNC(sub_8238CFC8);
PPC_FUNC_IMPL(__imp__sub_8238CFC8) {
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
	// bl 0x8238cbc8
	ctx.lr = 0x8238CFE0;
	sub_8238CBC8(ctx, base);
	// lis r11,3
	r11.s64 = 196608;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,57424
	r11.u64 = r11.u64 | 57424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stbx r10,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, ctx.r10.u8);
	// bl 0x8238c9b0
	ctx.lr = 0x8238CFF8;
	sub_8238C9B0(ctx, base);
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

__attribute__((alias("__imp__sub_8238D010"))) PPC_WEAK_FUNC(sub_8238D010);
PPC_FUNC_IMPL(__imp__sub_8238D010) {
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
	// addi r9,r11,-6648
	ctx.r9.s64 = r11.s64 + -6648;
	// lbz r10,49(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 49);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238d054
	if (cr6.eq) goto loc_8238D054;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238d054
	if (cr6.eq) goto loc_8238D054;
	// bl 0x82130588
	ctx.lr = 0x8238D04C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_8238D054:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8238D05C;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_8238D070"))) PPC_WEAK_FUNC(sub_8238D070);
PPC_FUNC_IMPL(__imp__sub_8238D070) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_8238D088:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8238d088
	if (!cr6.eq) goto loc_8238D088;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// bl 0x823db670
	ctx.lr = 0x8238D0B0;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,43(r31)
	PPC_STORE_U8(r31.u32 + 43, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_8238D0CC"))) PPC_WEAK_FUNC(sub_8238D0CC);
PPC_FUNC_IMPL(__imp__sub_8238D0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D0D0"))) PPC_WEAK_FUNC(sub_8238D0D0);
PPC_FUNC_IMPL(__imp__sub_8238D0D0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D0D8"))) PPC_WEAK_FUNC(sub_8238D0D8);
PPC_FUNC_IMPL(__imp__sub_8238D0D8) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,4
	cr6.compare<uint32_t>(ctx.r5.u32, 4, xer);
	// bge cr6,0x8238d10c
	if (!cr6.lt) goto loc_8238D10C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6572
	ctx.r3.s64 = r11.s64 + -6572;
	// bl 0x82130000
	ctx.lr = 0x8238D104;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8238d180
	goto loc_8238D180;
loc_8238D10C:
	// lbz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 44);
	// addi r9,r5,-4
	ctx.r9.s64 = ctx.r5.s64 + -4;
	// addi r31,r3,44
	r31.s64 = ctx.r3.s64 + 44;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lbz r8,45(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 45);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,46(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 46);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,47(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 47);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r5,44(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r5,r9
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, xer);
	// ble cr6,0x8238d154
	if (!cr6.gt) goto loc_8238D154;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6572
	ctx.r3.s64 = r11.s64 + -6572;
	// bl 0x82130000
	ctx.lr = 0x8238D14C;
	sub_82130000(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x8238d180
	goto loc_8238D180;
loc_8238D154:
	// addi r30,r3,12
	r30.s64 = ctx.r3.s64 + 12;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8238D164;
	sub_823DA950(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r10,-6608
	ctx.r3.s64 = ctx.r10.s64 + -6608;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x8238D17C;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238D180:
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

__attribute__((alias("__imp__sub_8238D198"))) PPC_WEAK_FUNC(sub_8238D198);
PPC_FUNC_IMPL(__imp__sub_8238D198) {
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
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// bge cr6,0x8238d1d0
	if (!cr6.lt) goto loc_8238D1D0;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6572
	ctx.r3.s64 = r11.s64 + -6572;
	// bl 0x82130000
	ctx.lr = 0x8238D1BC;
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
loc_8238D1D0:
	// lbz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// addi r9,r5,-1
	ctx.r9.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// bge cr6,0x8238d204
	if (!cr6.lt) goto loc_8238D204;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6572
	ctx.r3.s64 = r11.s64 + -6572;
	// bl 0x82130000
	ctx.lr = 0x8238D1F0;
	sub_82130000(ctx, base);
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
loc_8238D204:
	// lbz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// addi r8,r11,8
	ctx.r8.s64 = r11.s64 + 8;
	// addi r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// stb r9,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r9.u8);
	// lbz r7,9(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// stb r7,2(r4)
	PPC_STORE_U8(ctx.r4.u32 + 2, ctx.r7.u8);
	// lbz r6,10(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// stb r6,3(r4)
	PPC_STORE_U8(ctx.r4.u32 + 3, ctx.r6.u8);
	// lbz r5,11(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// stb r5,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r5.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D240"))) PPC_WEAK_FUNC(sub_8238D240);
PPC_FUNC_IMPL(__imp__sub_8238D240) {
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
	ctx.lr = 0x8238D248;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r5,r30
	cr6.compare<uint32_t>(ctx.r5.u32, r30.u32, xer);
	// ble cr6,0x8238d28c
	if (!cr6.gt) goto loc_8238D28C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6572
	ctx.r3.s64 = r11.s64 + -6572;
	// bl 0x82130000
	ctx.lr = 0x8238D270;
	sub_82130000(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x823da950
	ctx.lr = 0x8238D280;
	sub_823DA950(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8238D28C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x823da950
	ctx.lr = 0x8238D298;
	sub_823DA950(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// addi r3,r11,-6524
	ctx.r3.s64 = r11.s64 + -6524;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x8238D2AC;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238D2B8"))) PPC_WEAK_FUNC(sub_8238D2B8);
PPC_FUNC_IMPL(__imp__sub_8238D2B8) {
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
	ctx.lr = 0x8238D2C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// bge cr6,0x8238d2f0
	if (!cr6.lt) goto loc_8238D2F0;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6272
	ctx.r3.s64 = r11.s64 + -6272;
	// bl 0x82130000
	ctx.lr = 0x8238D2E4;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8238D2F0:
	// addi r9,r5,-1
	ctx.r9.s64 = ctx.r5.s64 + -1;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bge cr6,0x8238d324
	if (!cr6.lt) goto loc_8238D324;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6272
	ctx.r3.s64 = r11.s64 + -6272;
	// bl 0x82130000
	ctx.lr = 0x8238D30C;
	sub_82130000(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8238D324:
	// lbz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// lwz r30,1(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1);
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// beq cr6,0x8238d34c
	if (cr6.eq) goto loc_8238D34C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// addi r3,r11,-6368
	ctx.r3.s64 = r11.s64 + -6368;
	// bl 0x82130000
	ctx.lr = 0x8238D348;
	sub_82130000(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
loc_8238D34C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x8238d36c
	if (cr6.eq) goto loc_8238D36C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// addi r3,r11,-6488
	ctx.r3.s64 = r11.s64 + -6488;
	// bl 0x82130000
	ctx.lr = 0x8238D368;
	sub_82130000(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
loc_8238D36C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// addi r9,r11,5
	ctx.r9.s64 = r11.s64 + 5;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238D38C"))) PPC_WEAK_FUNC(sub_8238D38C);
PPC_FUNC_IMPL(__imp__sub_8238D38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D390"))) PPC_WEAK_FUNC(sub_8238D390);
PPC_FUNC_IMPL(__imp__sub_8238D390) {
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
	ctx.lr = 0x8238D398;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r5,r30
	cr6.compare<uint32_t>(ctx.r5.u32, r30.u32, xer);
	// ble cr6,0x8238d3dc
	if (!cr6.gt) goto loc_8238D3DC;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-6272
	ctx.r3.s64 = r11.s64 + -6272;
	// bl 0x82130000
	ctx.lr = 0x8238D3C0;
	sub_82130000(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x823da950
	ctx.lr = 0x8238D3D0;
	sub_823DA950(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8238D3DC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x823da950
	ctx.lr = 0x8238D3E8;
	sub_823DA950(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238D3F4"))) PPC_WEAK_FUNC(sub_8238D3F4);
PPC_FUNC_IMPL(__imp__sub_8238D3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D3F8"))) PPC_WEAK_FUNC(sub_8238D3F8);
PPC_FUNC_IMPL(__imp__sub_8238D3F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,9
	ctx.r3.s64 = r11.s64 + 9;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D40C"))) PPC_WEAK_FUNC(sub_8238D40C);
PPC_FUNC_IMPL(__imp__sub_8238D40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D410"))) PPC_WEAK_FUNC(sub_8238D410);
PPC_FUNC_IMPL(__imp__sub_8238D410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-6648
	ctx.r9.s64 = ctx.r10.s64 + -6648;
	// stb r11,49(r3)
	PPC_STORE_U8(ctx.r3.u32 + 49, r11.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, r11.u8);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D43C"))) PPC_WEAK_FUNC(sub_8238D43C);
PPC_FUNC_IMPL(__imp__sub_8238D43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D440"))) PPC_WEAK_FUNC(sub_8238D440);
PPC_FUNC_IMPL(__imp__sub_8238D440) {
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
	// addi r9,r11,-6648
	ctx.r9.s64 = r11.s64 + -6648;
	// lbz r10,49(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 49);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238d48c
	if (cr6.eq) goto loc_8238D48C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238d48c
	if (cr6.eq) goto loc_8238D48C;
	// bl 0x82130588
	ctx.lr = 0x8238D484;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_8238D48C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8238D494;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238d4ac
	if (cr6.eq) goto loc_8238D4AC;
	// bl 0x82130588
	ctx.lr = 0x8238D4A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238D4AC:
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

__attribute__((alias("__imp__sub_8238D4C4"))) PPC_WEAK_FUNC(sub_8238D4C4);
PPC_FUNC_IMPL(__imp__sub_8238D4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D4C8"))) PPC_WEAK_FUNC(sub_8238D4C8);
PPC_FUNC_IMPL(__imp__sub_8238D4C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r11,0
	r11.s64 = 0;
	// rlwimi r10,r9,2,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 2) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D4EC"))) PPC_WEAK_FUNC(sub_8238D4EC);
PPC_FUNC_IMPL(__imp__sub_8238D4EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D4F0"))) PPC_WEAK_FUNC(sub_8238D4F0);
PPC_FUNC_IMPL(__imp__sub_8238D4F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,5
	ctx.r10.s64 = 5;
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwimi r9,r10,2,0,29
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 2) & 0xFFFFFFFC) | (ctx.r9.u64 & 0xFFFFFFFF00000003);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stb r9,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r9.u8);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D51C"))) PPC_WEAK_FUNC(sub_8238D51C);
PPC_FUNC_IMPL(__imp__sub_8238D51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D520"))) PPC_WEAK_FUNC(sub_8238D520);
PPC_FUNC_IMPL(__imp__sub_8238D520) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8238d544
	if (!cr6.eq) goto loc_8238D544;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8238d548
	if (cr6.eq) goto loc_8238D548;
loc_8238D544:
	// li r11,0
	r11.s64 = 0;
loc_8238D548:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D550"))) PPC_WEAK_FUNC(sub_8238D550);
PPC_FUNC_IMPL(__imp__sub_8238D550) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8238d580
	if (cr6.lt) goto loc_8238D580;
	// bne cr6,0x8238d574
	if (!cr6.eq) goto loc_8238D574;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8238d580
	if (cr6.lt) goto loc_8238D580;
loc_8238D574:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_8238D580:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D58C"))) PPC_WEAK_FUNC(sub_8238D58C);
PPC_FUNC_IMPL(__imp__sub_8238D58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D590"))) PPC_WEAK_FUNC(sub_8238D590);
PPC_FUNC_IMPL(__imp__sub_8238D590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8238d5cc
	if (cr6.lt) goto loc_8238D5CC;
	// beq cr6,0x8238d5bc
	if (cr6.eq) goto loc_8238D5BC;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// subfc r9,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r8,31
	ctx.r3.u64 = ctx.r8.u32 & 0x1;
	// blr 
	return;
loc_8238D5BC:
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// b 0x8238d5d8
	goto loc_8238D5D8;
loc_8238D5CC:
	// lfs f0,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
loc_8238D5D8:
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8238d5e4
	if (cr6.lt) goto loc_8238D5E4;
	// li r11,0
	r11.s64 = 0;
loc_8238D5E4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D5EC"))) PPC_WEAK_FUNC(sub_8238D5EC);
PPC_FUNC_IMPL(__imp__sub_8238D5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D5F0"))) PPC_WEAK_FUNC(sub_8238D5F0);
PPC_FUNC_IMPL(__imp__sub_8238D5F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lbz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rlwimi r10,r9,0,24,26
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// lbz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rlwimi r7,r6,0,27,29
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x1C) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFE3);
	// stb r7,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D620"))) PPC_WEAK_FUNC(sub_8238D620);
PPC_FUNC_IMPL(__imp__sub_8238D620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rlwinm r11,r9,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8238d650
	if (cr6.lt) goto loc_8238D650;
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lbz r11,8(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rlwimi r9,r11,0,27,29
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x1C) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFE3);
	// stb r9,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r9.u8);
	// blr 
	return;
loc_8238D650:
	// lfs f0,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lbz r11,8(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rlwimi r9,r11,0,27,29
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x1C) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFE3);
	// stb r9,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D670"))) PPC_WEAK_FUNC(sub_8238D670);
PPC_FUNC_IMPL(__imp__sub_8238D670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238d68c
	if (cr6.eq) goto loc_8238D68C;
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
loc_8238D68C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D69C"))) PPC_WEAK_FUNC(sub_8238D69C);
PPC_FUNC_IMPL(__imp__sub_8238D69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D6A0"))) PPC_WEAK_FUNC(sub_8238D6A0);
PPC_FUNC_IMPL(__imp__sub_8238D6A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,8
	cr6.compare<uint32_t>(ctx.r5.u32, 8, xer);
	// blt cr6,0x8238d6f0
	if (cr6.lt) goto loc_8238D6F0;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// stb r8,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r8.u8);
	// lbz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// stb r7,2(r4)
	PPC_STORE_U8(ctx.r4.u32 + 2, ctx.r7.u8);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// stb r6,3(r4)
	PPC_STORE_U8(ctx.r4.u32 + 3, ctx.r6.u8);
	// lbz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// stb r5,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r5.u8);
	// lbz r3,5(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// stb r3,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, ctx.r3.u8);
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// stb r10,6(r4)
	PPC_STORE_U8(ctx.r4.u32 + 6, ctx.r10.u8);
	// lbz r9,7(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// stb r9,7(r4)
	PPC_STORE_U8(ctx.r4.u32 + 7, ctx.r9.u8);
loc_8238D6F0:
	// lbz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// addi r10,r4,10
	ctx.r10.s64 = ctx.r4.s64 + 10;
	// addi r10,r4,12
	ctx.r10.s64 = ctx.r4.s64 + 12;
	// rlwinm r8,r9,1,26,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x38;
	// rlwinm r7,r9,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// li r3,16
	ctx.r3.s64 = 16;
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stb r6,8(r4)
	PPC_STORE_U8(ctx.r4.u32 + 8, ctx.r6.u8);
	// lbz r5,9(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// stb r5,9(r4)
	PPC_STORE_U8(ctx.r4.u32 + 9, ctx.r5.u8);
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// stb r10,10(r4)
	PPC_STORE_U8(ctx.r4.u32 + 10, ctx.r10.u8);
	// lbz r9,11(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// stb r9,11(r4)
	PPC_STORE_U8(ctx.r4.u32 + 11, ctx.r9.u8);
	// lbz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// stb r8,12(r4)
	PPC_STORE_U8(ctx.r4.u32 + 12, ctx.r8.u8);
	// lbz r7,13(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// stb r7,13(r4)
	PPC_STORE_U8(ctx.r4.u32 + 13, ctx.r7.u8);
	// lbz r6,14(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 14);
	// stb r6,14(r4)
	PPC_STORE_U8(ctx.r4.u32 + 14, ctx.r6.u8);
	// lbz r5,15(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 15);
	// stb r5,15(r4)
	PPC_STORE_U8(ctx.r4.u32 + 15, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D74C"))) PPC_WEAK_FUNC(sub_8238D74C);
PPC_FUNC_IMPL(__imp__sub_8238D74C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D750"))) PPC_WEAK_FUNC(sub_8238D750);
PPC_FUNC_IMPL(__imp__sub_8238D750) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,8
	cr6.compare<uint32_t>(ctx.r5.u32, 8, xer);
	// blt cr6,0x8238d7a0
	if (cr6.lt) goto loc_8238D7A0;
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r8,1(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,2(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,3(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lbz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r5,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r5.u8);
	// lbz r3,5(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// stb r3,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r3.u8);
	// lbz r10,6(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
	// lbz r9,7(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// stb r9,7(r11)
	PPC_STORE_U8(r11.u32 + 7, ctx.r9.u8);
loc_8238D7A0:
	// lbz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// addi r10,r11,10
	ctx.r10.s64 = r11.s64 + 10;
	// lbz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// li r3,16
	ctx.r3.s64 = 16;
	// rlwimi r8,r9,5,19,26
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x1FE0) | (ctx.r8.u64 & 0xFFFFFFFFFFFFE01F);
	// rlwimi r8,r9,31,27,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 31) & 0x1C) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFE3);
	// stb r8,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r8.u8);
	// lbz r6,9(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// stb r6,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r6.u8);
	// lbz r5,10(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r5,10(r11)
	PPC_STORE_U8(r11.u32 + 10, ctx.r5.u8);
	// lbz r10,11(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// stb r10,11(r11)
	PPC_STORE_U8(r11.u32 + 11, ctx.r10.u8);
	// lbz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// stb r9,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r9.u8);
	// lbz r8,13(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 13);
	// stb r8,13(r11)
	PPC_STORE_U8(r11.u32 + 13, ctx.r8.u8);
	// lbz r7,14(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// stb r7,14(r11)
	PPC_STORE_U8(r11.u32 + 14, ctx.r7.u8);
	// lbz r6,15(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 15);
	// stb r6,15(r11)
	PPC_STORE_U8(r11.u32 + 15, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D7FC"))) PPC_WEAK_FUNC(sub_8238D7FC);
PPC_FUNC_IMPL(__imp__sub_8238D7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D800"))) PPC_WEAK_FUNC(sub_8238D800);
PPC_FUNC_IMPL(__imp__sub_8238D800) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// rlwinm r10,r10,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// blt cr6,0x8238d82c
	if (cr6.lt) goto loc_8238D82C;
	// beq cr6,0x8238d824
	if (cr6.eq) goto loc_8238D824;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
loc_8238D824:
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x8238d83c
	goto loc_8238D83C;
loc_8238D82C:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
loc_8238D83C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D84C"))) PPC_WEAK_FUNC(sub_8238D84C);
PPC_FUNC_IMPL(__imp__sub_8238D84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D850"))) PPC_WEAK_FUNC(sub_8238D850);
PPC_FUNC_IMPL(__imp__sub_8238D850) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blt cr6,0x8238d8a8
	if (cr6.lt) goto loc_8238D8A8;
	// beq cr6,0x8238d88c
	if (cr6.eq) goto loc_8238D88C;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f0,f13
	f0.f64 = double(float(ctx.f13.f64));
	// b 0x8238d8ac
	goto loc_8238D8AC;
loc_8238D88C:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f0,f13
	f0.f64 = double(float(ctx.f13.f64));
	// b 0x8238d8ac
	goto loc_8238D8AC;
loc_8238D8A8:
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
loc_8238D8AC:
	// fcmpu cr6,f0,f1
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D8BC"))) PPC_WEAK_FUNC(sub_8238D8BC);
PPC_FUNC_IMPL(__imp__sub_8238D8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D8C0"))) PPC_WEAK_FUNC(sub_8238D8C0);
PPC_FUNC_IMPL(__imp__sub_8238D8C0) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r11,r9,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// blt cr6,0x8238d930
	if (cr6.lt) goto loc_8238D930;
	// beq cr6,0x8238d914
	if (cr6.eq) goto loc_8238D914;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8238d940
	if (!cr6.lt) goto loc_8238D940;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f0,f12
	f0.f64 = double(float(ctx.f12.f64));
	// b 0x8238d934
	goto loc_8238D934;
loc_8238D914:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f0,f12
	f0.f64 = double(float(ctx.f12.f64));
	// b 0x8238d934
	goto loc_8238D934;
loc_8238D930:
	// lfs f0,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
loc_8238D934:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8238d940
	if (!cr6.lt) goto loc_8238D940;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8238D940:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8223de50
	ctx.lr = 0x8238D954;
	sub_8223DE50(ctx, base);
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

__attribute__((alias("__imp__sub_8238D96C"))) PPC_WEAK_FUNC(sub_8238D96C);
PPC_FUNC_IMPL(__imp__sub_8238D96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D970"))) PPC_WEAK_FUNC(sub_8238D970);
PPC_FUNC_IMPL(__imp__sub_8238D970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// lbz r6,3(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// rlwinm r4,r9,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// extsb r11,r8
	r11.s64 = ctx.r8.s8;
	// or r10,r4,r7
	ctx.r10.u64 = ctx.r4.u64 | ctx.r7.u64;
	// extsb r9,r6
	ctx.r9.s64 = ctx.r6.s8;
	// rlwinm r8,r10,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238D9B4"))) PPC_WEAK_FUNC(sub_8238D9B4);
PPC_FUNC_IMPL(__imp__sub_8238D9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238D9B8"))) PPC_WEAK_FUNC(sub_8238D9B8);
PPC_FUNC_IMPL(__imp__sub_8238D9B8) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r9,-5904
	ctx.r5.s64 = ctx.r9.s64 + -5904;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// extsb r9,r6
	ctx.r9.s64 = ctx.r6.s8;
	// lbz r30,0(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r6,r30
	ctx.r6.s64 = r30.s8;
	// bl 0x82137a08
	ctx.lr = 0x8238DA0C;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_8238DA28"))) PPC_WEAK_FUNC(sub_8238DA28);
PPC_FUNC_IMPL(__imp__sub_8238DA28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r11,r9,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// extsb r9,r8
	ctx.r9.s64 = ctx.r8.s8;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// or r8,r11,r7
	ctx.r8.u64 = r11.u64 | ctx.r7.u64;
	// stfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// extsb r7,r4
	ctx.r7.s64 = ctx.r4.s8;
	// rlwinm r5,r8,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwimi r10,r6,2,27,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 2) & 0x1C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE3);
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// clrlwi r11,r10,27
	r11.u64 = ctx.r10.u32 & 0x1F;
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// or r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 | ctx.r7.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238DA80"))) PPC_WEAK_FUNC(sub_8238DA80);
PPC_FUNC_IMPL(__imp__sub_8238DA80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// lbz r11,2(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r31,8(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// rlwimi r10,r6,2,27,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 2) & 0x1C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE3);
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// clrlwi r6,r31,30
	ctx.r6.u64 = r31.u32 & 0x3;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r10,r6
	r11.u64 = ctx.r10.u64 | ctx.r6.u64;
	// or r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238DAE8"))) PPC_WEAK_FUNC(sub_8238DAE8);
PPC_FUNC_IMPL(__imp__sub_8238DAE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r10,64
	ctx.r10.s64 = 64;
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// lbz r11,2(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r31,8(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// rlwimi r10,r6,2,27,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 2) & 0x1C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE3);
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// clrlwi r6,r31,30
	ctx.r6.u64 = r31.u32 & 0x3;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r10,r6
	r11.u64 = ctx.r10.u64 | ctx.r6.u64;
	// or r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238DB50"))) PPC_WEAK_FUNC(sub_8238DB50);
PPC_FUNC_IMPL(__imp__sub_8238DB50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// lbz r7,2(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r11,r8,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// extsb r8,r7
	ctx.r8.s64 = ctx.r7.s8;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// or r7,r11,r6
	ctx.r7.u64 = r11.u64 | ctx.r6.u64;
	// stfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// extsb r6,r4
	ctx.r6.s64 = ctx.r4.s8;
	// rlwinm r4,r7,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwimi r9,r5,2,27,29
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 2) & 0x1C) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFE3);
	// or r11,r4,r8
	r11.u64 = ctx.r4.u64 | ctx.r8.u64;
	// clrlwi r10,r9,27
	ctx.r10.u64 = ctx.r9.u32 & 0x1F;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238DBAC"))) PPC_WEAK_FUNC(sub_8238DBAC);
PPC_FUNC_IMPL(__imp__sub_8238DBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238DBB0"))) PPC_WEAK_FUNC(sub_8238DBB0);
PPC_FUNC_IMPL(__imp__sub_8238DBB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// li r10,32
	ctx.r10.s64 = 32;
	// extsb r7,r11
	ctx.r7.s64 = r11.s8;
	// lbz r11,2(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// lbz r31,8(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// rlwimi r10,r5,2,27,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 2) & 0x1C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE3);
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// clrlwi r6,r31,30
	ctx.r6.u64 = r31.u32 & 0x3;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r10,r6
	r11.u64 = ctx.r10.u64 | ctx.r6.u64;
	// or r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238DC1C"))) PPC_WEAK_FUNC(sub_8238DC1C);
PPC_FUNC_IMPL(__imp__sub_8238DC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238DC20"))) PPC_WEAK_FUNC(sub_8238DC20);
PPC_FUNC_IMPL(__imp__sub_8238DC20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// li r10,64
	ctx.r10.s64 = 64;
	// extsb r7,r11
	ctx.r7.s64 = r11.s8;
	// lbz r11,2(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// lbz r4,3(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// rlwinm r7,r7,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// lbz r31,8(r3)
	r31.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// rlwimi r10,r5,2,27,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 2) & 0x1C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE3);
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// clrlwi r6,r31,30
	ctx.r6.u64 = r31.u32 & 0x3;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// extsb r4,r4
	ctx.r4.s64 = ctx.r4.s8;
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r10,r6
	r11.u64 = ctx.r10.u64 | ctx.r6.u64;
	// or r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238DC8C"))) PPC_WEAK_FUNC(sub_8238DC8C);
PPC_FUNC_IMPL(__imp__sub_8238DC8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238DC90"))) PPC_WEAK_FUNC(sub_8238DC90);
PPC_FUNC_IMPL(__imp__sub_8238DC90) {
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
	ctx.lr = 0x8238DC98;
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
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8238dd3c
	if (cr6.lt) goto loc_8238DD3C;
	// beq cr6,0x8238dd00
	if (cr6.eq) goto loc_8238DD00;
	// bl 0x8238d9b8
	ctx.lr = 0x8238DCC8;
	sub_8238D9B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,-5888
	ctx.r5.s64 = r11.s64 + -5888;
	// li r4,25
	ctx.r4.s64 = 25;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DCE0;
	sub_82137A08(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r10,-5892
	ctx.r5.s64 = ctx.r10.s64 + -5892;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DCF8;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8238DD00:
	// bl 0x8238d9b8
	ctx.lr = 0x8238DD04;
	sub_8238D9B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,-5888
	ctx.r5.s64 = r11.s64 + -5888;
	// li r4,25
	ctx.r4.s64 = 25;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DD1C;
	sub_82137A08(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r10,32684
	ctx.r5.s64 = ctx.r10.s64 + 32684;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DD34;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8238DD3C:
	// bl 0x8238d9b8
	ctx.lr = 0x8238DD40;
	sub_8238D9B8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,-5888
	ctx.r5.s64 = r11.s64 + -5888;
	// li r4,25
	ctx.r4.s64 = 25;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DD58;
	sub_82137A08(ctx, base);
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r5,r10,9792
	ctx.r5.s64 = ctx.r10.s64 + 9792;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DD78;
	sub_82137A08(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238DD80"))) PPC_WEAK_FUNC(sub_8238DD80);
PPC_FUNC_IMPL(__imp__sub_8238DD80) {
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
	ctx.lr = 0x8238DD88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,52(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r29,r3,52
	r29.s64 = ctx.r3.s64 + 52;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8238ddd8
	if (cr6.eq) goto loc_8238DDD8;
loc_8238DDA4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238DDBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8238dde4
	if (!cr6.eq) goto loc_8238DDE4;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8238dda4
	if (!cr6.eq) goto loc_8238DDA4;
loc_8238DDD8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8238DDE4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238DDF0"))) PPC_WEAK_FUNC(sub_8238DDF0);
PPC_FUNC_IMPL(__imp__sub_8238DDF0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8238DDF8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addic. r10,r26,-1
	xer.ca = r26.u32 > 0;
	ctx.r10.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// ble 0x8238de40
	if (!cr0.gt) goto loc_8238DE40;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,-5792
	ctx.r8.s64 = ctx.r9.s64 + -5792;
	// subf r8,r30,r8
	ctx.r8.s64 = ctx.r8.s64 - r30.s64;
loc_8238DE24:
	// lbzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238de40
	if (cr6.eq) goto loc_8238DE40;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x8238de24
	if (cr0.gt) goto loc_8238DE24;
loc_8238DE40:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r11,-6752(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6752);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238de68
	if (cr6.eq) goto loc_8238DE68;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
loc_8238DE68:
	// lbz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// lbz r7,1(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// extsb r6,r3
	ctx.r6.s64 = ctx.r3.s8;
	// addi r5,r10,-5904
	ctx.r5.s64 = ctx.r10.s64 + -5904;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsb r9,r11
	ctx.r9.s64 = r11.s8;
	// extsb r7,r7
	ctx.r7.s64 = ctx.r7.s8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82137a08
	ctx.lr = 0x8238DEA0;
	sub_82137A08(ctx, base);
	// extsb r11,r27
	r11.s64 = r27.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8238deb0
	if (cr6.eq) goto loc_8238DEB0;
	// stb r27,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, r27.u8);
loc_8238DEB0:
	// lbz r11,89(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,58
	cr6.compare<int32_t>(r11.s32, 58, xer);
	// bne cr6,0x8238ded4
	if (!cr6.eq) goto loc_8238DED4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d8c0
	ctx.lr = 0x8238DECC;
	sub_8238D8C0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238DED4:
	// cmpwi cr6,r11,37
	cr6.compare<int32_t>(r11.s32, 37, xer);
	// bne cr6,0x8238df40
	if (!cr6.eq) goto loc_8238DF40;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8238df04
	if (cr6.lt) goto loc_8238DF04;
	// beq cr6,0x8238defc
	if (cr6.eq) goto loc_8238DEFC;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8238df20
	if (!cr6.lt) goto loc_8238DF20;
loc_8238DEFC:
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// b 0x8238df14
	goto loc_8238DF14;
loc_8238DF04:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8238DF14:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge cr6,0x8238df20
	if (!cr6.lt) goto loc_8238DF20;
	// li r6,0
	ctx.r6.s64 = 0;
loc_8238DF20:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r11,-5800
	ctx.r5.s64 = r11.s64 + -5800;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238DF34;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238DF40:
	// cmpwi cr6,r11,109
	cr6.compare<int32_t>(r11.s32, 109, xer);
	// bne cr6,0x8238dfb0
	if (!cr6.eq) goto loc_8238DFB0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d850
	ctx.lr = 0x8238DF50;
	sub_8238D850(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8238df90
	if (cr6.eq) goto loc_8238DF90;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r5,r10,-5812
	ctx.r5.s64 = ctx.r10.s64 + -5812;
	// lfs f0,-5804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5804);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x8238DF84;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238DF90:
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r5,r11,-5820
	ctx.r5.s64 = r11.s64 + -5820;
	// bl 0x82137a08
	ctx.lr = 0x8238DFA4;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238DFB0:
	// cmpwi cr6,r11,107
	cr6.compare<int32_t>(r11.s32, 107, xer);
	// bne cr6,0x8238e020
	if (!cr6.eq) goto loc_8238E020;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d850
	ctx.lr = 0x8238DFC0;
	sub_8238D850(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8238dff4
	if (cr6.eq) goto loc_8238DFF4;
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r5,r11,-5828
	ctx.r5.s64 = r11.s64 + -5828;
	// bl 0x82137a08
	ctx.lr = 0x8238DFE8;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238DFF4:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r5,r10,-5840
	ctx.r5.s64 = ctx.r10.s64 + -5840;
	// lfs f0,-5832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5832);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x8238E014;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E020:
	// cmpwi cr6,r11,118
	cr6.compare<int32_t>(r11.s32, 118, xer);
	// bne cr6,0x8238e090
	if (!cr6.eq) goto loc_8238E090;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d850
	ctx.lr = 0x8238E030;
	sub_8238D850(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8238e064
	if (cr6.eq) goto loc_8238E064;
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r5,r11,-5848
	ctx.r5.s64 = r11.s64 + -5848;
	// bl 0x82137a08
	ctx.lr = 0x8238E058;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E064:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r5,r10,-5856
	ctx.r5.s64 = ctx.r10.s64 + -5856;
	// lfs f0,-5832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5832);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x8238E084;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E090:
	// cmpwi cr6,r11,115
	cr6.compare<int32_t>(r11.s32, 115, xer);
	// bne cr6,0x8238e0c8
	if (!cr6.eq) goto loc_8238E0C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d850
	ctx.lr = 0x8238E0A0;
	sub_8238D850(ctx, base);
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r11,-5864
	ctx.r5.s64 = r11.s64 + -5864;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x8238E0BC;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E0C8:
	// cmpwi cr6,r11,104
	cr6.compare<int32_t>(r11.s32, 104, xer);
	// bne cr6,0x8238e140
	if (!cr6.eq) goto loc_8238E140;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d850
	ctx.lr = 0x8238E0D8;
	sub_8238D850(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r9,-30584
	ctx.r9.s64 = -2004353024;
	// li r10,60
	ctx.r10.s64 = 60;
	// ori r7,r9,34953
	ctx.r7.u64 = ctx.r9.u64 | 34953;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lfs f0,-26872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26872);
	f0.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// addi r5,r8,-5872
	ctx.r5.s64 = ctx.r8.s64 + -5872;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r6,r11,r10
	ctx.r6.s32 = r11.s32 / ctx.r10.s32;
	// mulhw r10,r11,r7
	ctx.r10.s64 = (int64_t(r11.s32) * int64_t(ctx.r7.s32)) >> 32;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// srawi r11,r8,5
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	r11.s64 = ctx.r8.s32 >> 5;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mulli r11,r7,60
	r11.s64 = ctx.r7.s64 * 60;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
	// bl 0x82137a08
	ctx.lr = 0x8238E134;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E140:
	// cmpwi cr6,r11,36
	cr6.compare<int32_t>(r11.s32, 36, xer);
	// bne cr6,0x8238e178
	if (!cr6.eq) goto loc_8238E178;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d800
	ctx.lr = 0x8238E150;
	sub_8238D800(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82217b70
	ctx.lr = 0x8238E16C;
	sub_82217B70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E178:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8238e1e4
	if (cr6.lt) goto loc_8238E1E4;
	// beq cr6,0x8238e1b8
	if (cr6.eq) goto loc_8238E1B8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8238e214
	if (!cr6.lt) goto loc_8238E214;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238E1AC;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E1B8:
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x8238e214
	if (cr6.lt) goto loc_8238E214;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238E1D8;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8238E1E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8238e214
	if (cr6.lt) goto loc_8238E214;
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r11,-5880
	ctx.r5.s64 = r11.s64 + -5880;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8238E214;
	sub_82137A08(ctx, base);
loc_8238E214:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8238E220"))) PPC_WEAK_FUNC(sub_8238E220);
PPC_FUNC_IMPL(__imp__sub_8238E220) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8238e2bc
	if (!cr6.eq) goto loc_8238E2BC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x822cd5b0
	ctx.lr = 0x8238E258;
	sub_822CD5B0(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238e2b0
	if (cr6.eq) goto loc_8238E2B0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8238E26C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r6,r11,r9
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r6,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r6.u32);
	// lwz r5,4(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r5,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r5.u32);
	// lwz r4,8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r4,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r4.u32);
	// lwz r3,12(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// stw r3,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r3.u32);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8238e26c
	if (cr6.lt) goto loc_8238E26C;
loc_8238E2B0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8238E2B8;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8238E2BC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,4
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
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

__attribute__((alias("__imp__sub_8238E2EC"))) PPC_WEAK_FUNC(sub_8238E2EC);
PPC_FUNC_IMPL(__imp__sub_8238E2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238E2F0"))) PPC_WEAK_FUNC(sub_8238E2F0);
PPC_FUNC_IMPL(__imp__sub_8238E2F0) {
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
	// lis r11,4095
	r11.s64 = 268369920;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x8238e330
	if (!cr6.gt) goto loc_8238E330;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-15120
	ctx.r3.s64 = r11.s64 + -15120;
	// bl 0x823dd898
	ctx.lr = 0x8238E328;
	sub_823DD898(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823db0a0
	ctx.lr = 0x8238E330;
	sub_823DB0A0(ctx, base);
loc_8238E330:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8238e344
	if (cr6.eq) goto loc_8238E344;
	// rlwinm r3,r4,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x8238E340;
	sub_82130528(ctx, base);
	// b 0x8238e348
	goto loc_8238E348;
loc_8238E344:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8238E348:
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x8238e38c
	if (cr6.eq) goto loc_8238E38C;
	// subf r9,r31,r3
	ctx.r9.s64 = ctx.r3.s64 - r31.s64;
loc_8238E358:
	// add. r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8238e380
	if (cr0.eq) goto loc_8238E380;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r5,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
loc_8238E380:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8238e358
	if (!cr6.eq) goto loc_8238E358;
loc_8238E38C:
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

__attribute__((alias("__imp__sub_8238E3A4"))) PPC_WEAK_FUNC(sub_8238E3A4);
PPC_FUNC_IMPL(__imp__sub_8238E3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238E3A8"))) PPC_WEAK_FUNC(sub_8238E3A8);
PPC_FUNC_IMPL(__imp__sub_8238E3A8) {
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
	ctx.lr = 0x8238E3B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,52(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r30,r3,52
	r30.s64 = ctx.r3.s64 + 52;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8238e468
	if (cr6.eq) goto loc_8238E468;
loc_8238E3D4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238E3EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238e458
	if (cr6.eq) goto loc_8238E458;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82130528
	ctx.lr = 0x8238E400;
	sub_82130528(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8238E40C;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238dc90
	ctx.lr = 0x8238E420;
	sub_8238DC90(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238ddf0
	ctx.lr = 0x8238E434;
	sub_8238DDF0(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8238E440;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
	// bl 0x8262e420
	ctx.lr = 0x8238E454;
	sub_8262E420(ctx, base);
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
loc_8238E458:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8238e3d4
	if (!cr6.eq) goto loc_8238E3D4;
loc_8238E468:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8238E470"))) PPC_WEAK_FUNC(sub_8238E470);
PPC_FUNC_IMPL(__imp__sub_8238E470) {
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
	ctx.lr = 0x8238E478;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,52(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r30,r3,52
	r30.s64 = ctx.r3.s64 + 52;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8238e4f8
	if (cr6.eq) goto loc_8238E4F8;
loc_8238E498:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238E4B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238e4e8
	if (cr6.eq) goto loc_8238E4E8;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238e220
	ctx.lr = 0x8238E4C8;
	sub_8238E220(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
loc_8238E4E8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8238e498
	if (!cr6.eq) goto loc_8238E498;
loc_8238E4F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238E500"))) PPC_WEAK_FUNC(sub_8238E500);
PPC_FUNC_IMPL(__imp__sub_8238E500) {
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
	ctx.lr = 0x8238E508;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// srawi r8,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	// cmplw cr6,r8,r29
	cr6.compare<uint32_t>(ctx.r8.u32, r29.u32, xer);
	// bge cr6,0x8238e5b8
	if (!cr6.lt) goto loc_8238E5B8;
	// lis r11,4095
	r11.s64 = 268369920;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8238e54c
	if (!cr6.gt) goto loc_8238E54C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-5912
	ctx.r3.s64 = r11.s64 + -5912;
	// bl 0x82616560
	ctx.lr = 0x8238E54C;
	sub_82616560(ctx, base);
loc_8238E54C:
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// subf r11,r5,r6
	r11.s64 = ctx.r6.s64 - ctx.r5.s64;
	// srawi r27,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	r27.s64 = r11.s32 >> 4;
	// beq cr6,0x8238e58c
	if (cr6.eq) goto loc_8238E58C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238e2f0
	ctx.lr = 0x8238E570;
	sub_8238E2F0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238e59c
	if (cr6.eq) goto loc_8238E59C;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82130588
	ctx.lr = 0x8238E588;
	sub_82130588(ctx, base);
	// b 0x8238e59c
	goto loc_8238E59C;
loc_8238E58C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822cdc20
	ctx.lr = 0x8238E598;
	sub_822CDC20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8238E59C:
	// rlwinm r10,r27,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
loc_8238E5B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238E5C0"))) PPC_WEAK_FUNC(sub_8238E5C0);
PPC_FUNC_IMPL(__imp__sub_8238E5C0) {
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
	// bl 0x8238d410
	ctx.lr = 0x8238E5D8;
	sub_8238D410(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-5764
	ctx.r9.s64 = ctx.r10.s64 + -5764;
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r4,1000
	ctx.r4.s64 = 1000;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// bl 0x8238e500
	ctx.lr = 0x8238E600;
	sub_8238E500(ctx, base);
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

__attribute__((alias("__imp__sub_8238E618"))) PPC_WEAK_FUNC(sub_8238E618);
PPC_FUNC_IMPL(__imp__sub_8238E618) {
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
	// addi r10,r11,-5764
	ctx.r10.s64 = r11.s64 + -5764;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238e648
	if (cr6.eq) goto loc_8238E648;
	// bl 0x82130588
	ctx.lr = 0x8238E648;
	sub_82130588(ctx, base);
loc_8238E648:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d010
	ctx.lr = 0x8238E650;
	sub_8238D010(ctx, base);
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

__attribute__((alias("__imp__sub_8238E664"))) PPC_WEAK_FUNC(sub_8238E664);
PPC_FUNC_IMPL(__imp__sub_8238E664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238E668"))) PPC_WEAK_FUNC(sub_8238E668);
PPC_FUNC_IMPL(__imp__sub_8238E668) {
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
	// addi r10,r11,-5764
	ctx.r10.s64 = r11.s64 + -5764;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238e6a0
	if (cr6.eq) goto loc_8238E6A0;
	// bl 0x82130588
	ctx.lr = 0x8238E6A0;
	sub_82130588(ctx, base);
loc_8238E6A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238d010
	ctx.lr = 0x8238E6A8;
	sub_8238D010(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238e6c0
	if (cr6.eq) goto loc_8238E6C0;
	// bl 0x82130588
	ctx.lr = 0x8238E6BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238E6C0:
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

__attribute__((alias("__imp__sub_8238E6D8"))) PPC_WEAK_FUNC(sub_8238E6D8);
PPC_FUNC_IMPL(__imp__sub_8238E6D8) {
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
	ctx.lr = 0x8238E6E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-27920
	r29.s64 = r11.s64 + -27920;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238E6F8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238E704;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e73c
	if (cr6.eq) goto loc_8238E73C;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,28
	r11.s64 = r29.s64 + 28;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238e6f8
	if (cr6.lt) goto loc_8238E6F8;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-4160
	ctx.r3.s64 = r11.s64 + -4160;
	// bl 0x821bd618
	ctx.lr = 0x8238E730;
	sub_821BD618(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E73C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238E748"))) PPC_WEAK_FUNC(sub_8238E748);
PPC_FUNC_IMPL(__imp__sub_8238E748) {
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
	ctx.lr = 0x8238E750;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-27892
	r29.s64 = r11.s64 + -27892;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238E768:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238E774;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e79c
	if (cr6.eq) goto loc_8238E79C;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,56
	r11.s64 = r29.s64 + 56;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238e768
	if (cr6.lt) goto loc_8238E768;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E79C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238E7A8"))) PPC_WEAK_FUNC(sub_8238E7A8);
PPC_FUNC_IMPL(__imp__sub_8238E7A8) {
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
	ctx.lr = 0x8238E7B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-27836
	r29.s64 = r11.s64 + -27836;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238E7C8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238E7D4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e80c
	if (cr6.eq) goto loc_8238E80C;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,28
	r11.s64 = r29.s64 + 28;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238e7c8
	if (cr6.lt) goto loc_8238E7C8;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-4116
	ctx.r3.s64 = r11.s64 + -4116;
	// bl 0x82130000
	ctx.lr = 0x8238E800;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E80C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238E818"))) PPC_WEAK_FUNC(sub_8238E818);
PPC_FUNC_IMPL(__imp__sub_8238E818) {
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
	ctx.lr = 0x8238E820;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,-27200
	ctx.r4.s64 = r11.s64 + -27200;
	// bl 0x823db730
	ctx.lr = 0x8238E834;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e854
	if (cr6.eq) goto loc_8238E854;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-4028
	ctx.r4.s64 = r11.s64 + -4028;
	// bl 0x823db730
	ctx.lr = 0x8238E84C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8238e85c
	if (!cr6.eq) goto loc_8238E85C;
loc_8238E854:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r28,r11,-4224
	r28.s64 = r11.s64 + -4224;
loc_8238E85C:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,-28196
	r29.s64 = r11.s64 + -28196;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238E86C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238E878;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e8b0
	if (cr6.eq) goto loc_8238E8B0;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,28
	r11.s64 = r29.s64 + 28;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238e86c
	if (cr6.lt) goto loc_8238E86C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-4072
	ctx.r3.s64 = r11.s64 + -4072;
	// bl 0x821bd618
	ctx.lr = 0x8238E8A4;
	sub_821BD618(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E8B0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238E8BC"))) PPC_WEAK_FUNC(sub_8238E8BC);
PPC_FUNC_IMPL(__imp__sub_8238E8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238E8C0"))) PPC_WEAK_FUNC(sub_8238E8C0);
PPC_FUNC_IMPL(__imp__sub_8238E8C0) {
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
	ctx.lr = 0x8238E8C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8238e980
	if (cr6.eq) goto loc_8238E980;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r31,r11,-3860
	r31.s64 = r11.s64 + -3860;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db730
	ctx.lr = 0x8238E8EC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8238e900
	if (!cr6.eq) goto loc_8238E900;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E900:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823db730
	ctx.lr = 0x8238E90C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8238e920
	if (!cr6.eq) goto loc_8238E920;
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E920:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,-28140
	r29.s64 = r11.s64 + -28140;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238E930:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238E93C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e974
	if (cr6.eq) goto loc_8238E974;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,16
	r11.s64 = r29.s64 + 16;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238e930
	if (cr6.lt) goto loc_8238E930;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-3908
	ctx.r3.s64 = r11.s64 + -3908;
	// bl 0x82130000
	ctx.lr = 0x8238E968;
	sub_82130000(ctx, base);
	// li r3,-2
	ctx.r3.s64 = -2;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E974:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E980:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-4008
	ctx.r3.s64 = r11.s64 + -4008;
	// bl 0x82130000
	ctx.lr = 0x8238E98C;
	sub_82130000(ctx, base);
	// li r3,-2
	ctx.r3.s64 = -2;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238E998"))) PPC_WEAK_FUNC(sub_8238E998);
PPC_FUNC_IMPL(__imp__sub_8238E998) {
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
	ctx.lr = 0x8238E9A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-28116
	r29.s64 = r11.s64 + -28116;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238E9B8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238E9C4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238e9fc
	if (cr6.eq) goto loc_8238E9FC;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,20
	r11.s64 = r29.s64 + 20;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238e9b8
	if (cr6.lt) goto loc_8238E9B8;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-3840
	ctx.r3.s64 = r11.s64 + -3840;
	// bl 0x82130000
	ctx.lr = 0x8238E9F0;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238E9FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238EA08"))) PPC_WEAK_FUNC(sub_8238EA08);
PPC_FUNC_IMPL(__imp__sub_8238EA08) {
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
	ctx.lr = 0x8238EA10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-27672
	r29.s64 = r11.s64 + -27672;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8238EA28:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8238EA34;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238ea6c
	if (cr6.eq) goto loc_8238EA6C;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,152
	r11.s64 = r29.s64 + 152;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8238ea28
	if (cr6.lt) goto loc_8238EA28;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-3796
	ctx.r3.s64 = r11.s64 + -3796;
	// bl 0x82130000
	ctx.lr = 0x8238EA60;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238EA6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238EA78"))) PPC_WEAK_FUNC(sub_8238EA78);
PPC_FUNC_IMPL(__imp__sub_8238EA78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8238eaa8
	if (cr6.eq) goto loc_8238EAA8;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// beq cr6,0x8238ea9c
	if (cr6.eq) goto loc_8238EA9C;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28140
	ctx.r9.s64 = r11.s64 + -28140;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
loc_8238EA9C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-3756
	ctx.r3.s64 = r11.s64 + -3756;
	// blr 
	return;
loc_8238EAA8:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-3860
	ctx.r3.s64 = r11.s64 + -3860;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EAB4"))) PPC_WEAK_FUNC(sub_8238EAB4);
PPC_FUNC_IMPL(__imp__sub_8238EAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EAB8"))) PPC_WEAK_FUNC(sub_8238EAB8);
PPC_FUNC_IMPL(__imp__sub_8238EAB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8238eb18
	if (cr6.gt) goto loc_8238EB18;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-5412
	r12.s64 = r12.s64 + -5412;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8238EB18;
	case 1:
		goto loc_8238EB18;
	case 2:
		goto loc_8238EB18;
	case 3:
		goto loc_8238EB18;
	case 4:
		goto loc_8238EB18;
	case 5:
		goto loc_8238EB18;
	case 6:
		goto loc_8238EB18;
	case 7:
		goto loc_8238EB18;
	case 8:
		goto loc_8238EB10;
	case 9:
		goto loc_8238EB10;
	case 10:
		goto loc_8238EB18;
	case 11:
		goto loc_8238EB10;
	case 12:
		goto loc_8238EB18;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5360(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5360);
	// lwz r17,-5360(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5360);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
	// lwz r17,-5360(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5360);
	// lwz r17,-5352(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5352);
loc_8238EB10:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238EB18:
	// li r3,0
	ctx.r3.s64 = 0;
}

__attribute__((alias("__imp__sub_8238EB20"))) PPC_WEAK_FUNC(sub_8238EB20);
PPC_FUNC_IMPL(__imp__sub_8238EB20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8238eb88
	if (cr6.gt) goto loc_8238EB88;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-5308
	r12.s64 = r12.s64 + -5308;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8238EB78;
	case 1:
		goto loc_8238EB78;
	case 2:
		goto loc_8238EB78;
	case 3:
		goto loc_8238EB88;
	case 4:
		goto loc_8238EB78;
	case 5:
		goto loc_8238EB88;
	case 6:
		goto loc_8238EB88;
	case 7:
		goto loc_8238EB80;
	case 8:
		goto loc_8238EB80;
	case 9:
		goto loc_8238EB80;
	case 10:
		goto loc_8238EB80;
	case 11:
		goto loc_8238EB80;
	case 12:
		goto loc_8238EB80;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-5256(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5256);
	// lwz r17,-5256(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5256);
	// lwz r17,-5256(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5256);
	// lwz r17,-5240(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5240);
	// lwz r17,-5256(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5256);
	// lwz r17,-5240(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5240);
	// lwz r17,-5240(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5240);
	// lwz r17,-5248(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5248);
	// lwz r17,-5248(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5248);
	// lwz r17,-5248(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5248);
	// lwz r17,-5248(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5248);
	// lwz r17,-5248(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5248);
	// lwz r17,-5248(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5248);
loc_8238EB78:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8238EB80:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8238EB88:
	// li r3,0
	ctx.r3.s64 = 0;
}

__attribute__((alias("__imp__sub_8238EB90"))) PPC_WEAK_FUNC(sub_8238EB90);
PPC_FUNC_IMPL(__imp__sub_8238EB90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
	PPCRegister temp{};
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-5196
	r12.s64 = r12.s64 + -5196;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8238EBC4;
	case 1:
		goto loc_8238EBD0;
	case 2:
		goto loc_8238EBDC;
	case 3:
		goto loc_8238EBE8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-5180(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5180);
	// lwz r17,-5168(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5168);
	// lwz r17,-5156(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5156);
	// lwz r17,-5144(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -5144);
loc_8238EBC4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8238EBD0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f1,-31376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31376);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8238EBDC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,15004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15004);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8238EBE8:
	// lis r11,-32251
	r11.s64 = -2113601536;
}

__attribute__((alias("__imp__sub_8238EBF4"))) PPC_WEAK_FUNC(sub_8238EBF4);
PPC_FUNC_IMPL(__imp__sub_8238EBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EBF8"))) PPC_WEAK_FUNC(sub_8238EBF8);
PPC_FUNC_IMPL(__imp__sub_8238EBF8) {
	PPC_FUNC_PROLOGUE();
	// b 0x823895f8
	sub_823895F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238EBFC"))) PPC_WEAK_FUNC(sub_8238EBFC);
PPC_FUNC_IMPL(__imp__sub_8238EBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EC00"))) PPC_WEAK_FUNC(sub_8238EC00);
PPC_FUNC_IMPL(__imp__sub_8238EC00) {
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
	ctx.lr = 0x8238EC08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-12648
	r31.s64 = r11.s64 + -12648;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238ec58
	if (cr6.eq) goto loc_8238EC58;
	// li r29,0
	r29.s64 = 0;
loc_8238EC2C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x823db730
	ctx.lr = 0x8238EC3C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238ec74
	if (cr6.eq) goto loc_8238EC74;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8238ec2c
	if (cr6.lt) goto loc_8238EC2C;
loc_8238EC58:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-3732
	ctx.r3.s64 = r11.s64 + -3732;
	// bl 0x821bd618
	ctx.lr = 0x8238EC68;
	sub_821BD618(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8238EC74:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238EC90"))) PPC_WEAK_FUNC(sub_8238EC90);
PPC_FUNC_IMPL(__imp__sub_8238EC90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-3156
	ctx.r3.s64 = r11.s64 + -3156;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EC9C"))) PPC_WEAK_FUNC(sub_8238EC9C);
PPC_FUNC_IMPL(__imp__sub_8238EC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238ECA0"))) PPC_WEAK_FUNC(sub_8238ECA0);
PPC_FUNC_IMPL(__imp__sub_8238ECA0) {
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
	// addi r10,r11,-3164
	ctx.r10.s64 = r11.s64 + -3164;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8238ECCC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238ece4
	if (cr6.eq) goto loc_8238ECE4;
	// bl 0x82130588
	ctx.lr = 0x8238ECE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238ECE4:
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

__attribute__((alias("__imp__sub_8238ECFC"))) PPC_WEAK_FUNC(sub_8238ECFC);
PPC_FUNC_IMPL(__imp__sub_8238ECFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238ED00"))) PPC_WEAK_FUNC(sub_8238ED00);
PPC_FUNC_IMPL(__imp__sub_8238ED00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-3132
	ctx.r3.s64 = r11.s64 + -3132;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238ED0C"))) PPC_WEAK_FUNC(sub_8238ED0C);
PPC_FUNC_IMPL(__imp__sub_8238ED0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238ED10"))) PPC_WEAK_FUNC(sub_8238ED10);
PPC_FUNC_IMPL(__imp__sub_8238ED10) {
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-3140
	ctx.r10.s64 = r11.s64 + -3140;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8238ED40;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8238ED48;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238ed60
	if (cr6.eq) goto loc_8238ED60;
	// bl 0x82130588
	ctx.lr = 0x8238ED5C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238ED60:
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

__attribute__((alias("__imp__sub_8238ED78"))) PPC_WEAK_FUNC(sub_8238ED78);
PPC_FUNC_IMPL(__imp__sub_8238ED78) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,-3116
	ctx.r9.s64 = r11.s64 + -3116;
	// addi r8,r10,-3164
	ctx.r8.s64 = ctx.r10.s64 + -3164;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,8080
	ctx.r3.s64 = r31.s64 + 8080;
	// stw r8,8080(r31)
	PPC_STORE_U32(r31.u32 + 8080, ctx.r8.u32);
	// bl 0x821d2028
	ctx.lr = 0x8238EDB0;
	sub_821D2028(ctx, base);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x82392950
	ctx.lr = 0x8238EDB8;
	sub_82392950(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// addi r6,r7,-3140
	ctx.r6.s64 = ctx.r7.s64 + -3140;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x8238EDD0;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8238EDD8;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8238EDE0;
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

__attribute__((alias("__imp__sub_8238EDF8"))) PPC_WEAK_FUNC(sub_8238EDF8);
PPC_FUNC_IMPL(__imp__sub_8238EDF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-3108
	ctx.r3.s64 = r11.s64 + -3108;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EE04"))) PPC_WEAK_FUNC(sub_8238EE04);
PPC_FUNC_IMPL(__imp__sub_8238EE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EE08"))) PPC_WEAK_FUNC(sub_8238EE08);
PPC_FUNC_IMPL(__imp__sub_8238EE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r3,8109
	ctx.r10.s64 = ctx.r3.s64 + 8109;
	// addi r11,r11,-3100
	r11.s64 = r11.s64 + -3100;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8238EE1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8238ee1c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238EE1C;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,8141(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8141, r11.u8);
	// stw r11,8100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8100, r11.u32);
	// stw r11,8096(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8096, r11.u32);
	// stb r10,8108(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8108, ctx.r10.u8);
	// stw r10,8088(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8088, ctx.r10.u32);
	// stw r11,8104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8104, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EE54"))) PPC_WEAK_FUNC(sub_8238EE54);
PPC_FUNC_IMPL(__imp__sub_8238EE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EE58"))) PPC_WEAK_FUNC(sub_8238EE58);
PPC_FUNC_IMPL(__imp__sub_8238EE58) {
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
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x8238ef10
	if (cr6.eq) goto loc_8238EF10;
	// addi r3,r31,8109
	ctx.r3.s64 = r31.s64 + 8109;
	// addi r4,r30,8109
	ctx.r4.s64 = r30.s64 + 8109;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x823da950
	ctx.lr = 0x8238EE8C;
	sub_823DA950(ctx, base);
	// addi r3,r31,8141
	ctx.r3.s64 = r31.s64 + 8141;
	// addi r4,r30,8141
	ctx.r4.s64 = r30.s64 + 8141;
	// li r5,34
	ctx.r5.s64 = 34;
	// bl 0x823da950
	ctx.lr = 0x8238EE9C;
	sub_823DA950(ctx, base);
	// lis r11,15
	r11.s64 = 983040;
	// addi r4,r30,20
	ctx.r4.s64 = r30.s64 + 20;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r10,8092(r31)
	PPC_STORE_U32(r31.u32 + 8092, ctx.r10.u32);
	// bl 0x82397e88
	ctx.lr = 0x8238EEB4;
	sub_82397E88(ctx, base);
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x823934e8
	ctx.lr = 0x8238EEC0;
	sub_823934E8(ctx, base);
	// addi r4,r30,8080
	ctx.r4.s64 = r30.s64 + 8080;
	// addi r3,r31,8080
	ctx.r3.s64 = r31.s64 + 8080;
	// bl 0x82130000
	ctx.lr = 0x8238EECC;
	sub_82130000(ctx, base);
	// lwz r9,8096(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8096);
	// stw r9,8096(r31)
	PPC_STORE_U32(r31.u32 + 8096, ctx.r9.u32);
	// lwz r8,8100(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8100);
	// stw r8,8100(r31)
	PPC_STORE_U32(r31.u32 + 8100, ctx.r8.u32);
	// lbz r7,8108(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 8108);
	// extsb r11,r7
	r11.s64 = ctx.r7.s8;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// stb r7,8108(r31)
	PPC_STORE_U8(r31.u32 + 8108, ctx.r7.u8);
	// blt cr6,0x8238eef8
	if (cr6.lt) goto loc_8238EEF8;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// blt cr6,0x8238ef00
	if (cr6.lt) goto loc_8238EF00;
loc_8238EEF8:
	// li r11,-1
	r11.s64 = -1;
	// stb r11,8108(r31)
	PPC_STORE_U8(r31.u32 + 8108, r11.u8);
loc_8238EF00:
	// lwz r11,8088(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8088);
	// stw r11,8088(r31)
	PPC_STORE_U32(r31.u32 + 8088, r11.u32);
	// lwz r10,8104(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8104);
	// stw r10,8104(r31)
	PPC_STORE_U32(r31.u32 + 8104, ctx.r10.u32);
loc_8238EF10:
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

__attribute__((alias("__imp__sub_8238EF2C"))) PPC_WEAK_FUNC(sub_8238EF2C);
PPC_FUNC_IMPL(__imp__sub_8238EF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EF30"))) PPC_WEAK_FUNC(sub_8238EF30);
PPC_FUNC_IMPL(__imp__sub_8238EF30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8084(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8084);
	// lwz r10,2128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2128);
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// lwz r7,8092(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8092);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 | ctx.r4.u64;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r4,8092(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8092, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EF58"))) PPC_WEAK_FUNC(sub_8238EF58);
PPC_FUNC_IMPL(__imp__sub_8238EF58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// not r9,r4
	ctx.r9.u64 = ~ctx.r4.u64;
	// addi r11,r3,20
	r11.s64 = ctx.r3.s64 + 20;
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// addi r11,r3,8080
	r11.s64 = ctx.r3.s64 + 8080;
	// lwz r7,2128(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2128);
	// and r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 & ctx.r9.u64;
	// stw r6,2128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2128, ctx.r6.u32);
	// lwz r5,8084(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8084);
	// and r4,r9,r5
	ctx.r4.u64 = ctx.r9.u64 & ctx.r5.u64;
	// stw r4,8084(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8084, ctx.r4.u32);
	// lwz r11,8092(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8092);
	// and r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 & r11.u64;
	// stw r10,8092(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8092, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EF9C"))) PPC_WEAK_FUNC(sub_8238EF9C);
PPC_FUNC_IMPL(__imp__sub_8238EF9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EFA0"))) PPC_WEAK_FUNC(sub_8238EFA0);
PPC_FUNC_IMPL(__imp__sub_8238EFA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,2128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2128, r11.u32);
	// stw r11,8084(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8084, r11.u32);
	// stw r11,8092(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8092, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EFB8"))) PPC_WEAK_FUNC(sub_8238EFB8);
PPC_FUNC_IMPL(__imp__sub_8238EFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8084(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8084);
	// lwz r10,2128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2128);
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// lwz r7,8092(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8092);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r5,8092(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8092, ctx.r5.u32);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238EFE0"))) PPC_WEAK_FUNC(sub_8238EFE0);
PPC_FUNC_IMPL(__imp__sub_8238EFE0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8238ee58
	sub_8238EE58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238EFE4"))) PPC_WEAK_FUNC(sub_8238EFE4);
PPC_FUNC_IMPL(__imp__sub_8238EFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238EFE8"))) PPC_WEAK_FUNC(sub_8238EFE8);
PPC_FUNC_IMPL(__imp__sub_8238EFE8) {
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
	// addi r30,r31,8109
	r30.s64 = r31.s64 + 8109;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8239c698
	ctx.lr = 0x8238F00C;
	sub_8239C698(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8238f030
	if (!cr6.eq) goto loc_8238F030;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-3088
	ctx.r3.s64 = r11.s64 + -3088;
	// bl 0x82130000
	ctx.lr = 0x8238F024;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8238f058
	goto loc_8238F058;
loc_8238F030:
	// lbz r11,60(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x8238f054
	if (!cr6.eq) goto loc_8238F054;
	// lbz r11,59(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x8238f054
	if (!cr6.eq) goto loc_8238F054;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8238F054:
	// bl 0x8239c2c8
	ctx.lr = 0x8238F058;
	sub_8239C2C8(ctx, base);
loc_8238F058:
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

__attribute__((alias("__imp__sub_8238F070"))) PPC_WEAK_FUNC(sub_8238F070);
PPC_FUNC_IMPL(__imp__sub_8238F070) {
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
	// li r5,84
	ctx.r5.s64 = 84;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823da950
	ctx.lr = 0x8238F08C;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_8238F0A4"))) PPC_WEAK_FUNC(sub_8238F0A4);
PPC_FUNC_IMPL(__imp__sub_8238F0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238F0A8"))) PPC_WEAK_FUNC(sub_8238F0A8);
PPC_FUNC_IMPL(__imp__sub_8238F0A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82396f58
	sub_82396F58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238F0B0"))) PPC_WEAK_FUNC(sub_8238F0B0);
PPC_FUNC_IMPL(__imp__sub_8238F0B0) {
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
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,54
	cr6.compare<int32_t>(r30.s32, 54, xer);
	// blt cr6,0x8238f0dc
	if (cr6.lt) goto loc_8238F0DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8238f1d0
	goto loc_8238F1D0;
loc_8238F0DC:
	// li r5,216
	ctx.r5.s64 = 216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823d9890
	ctx.lr = 0x8238F0EC;
	sub_823D9890(ctx, base);
	// addi r10,r31,13
	ctx.r10.s64 = r31.s64 + 13;
	// addi r9,r31,14
	ctx.r9.s64 = r31.s64 + 14;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// addi r8,r31,15
	ctx.r8.s64 = r31.s64 + 15;
	// addi r7,r31,16
	ctx.r7.s64 = r31.s64 + 16;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// addi r6,r31,17
	ctx.r6.s64 = r31.s64 + 17;
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// addi r5,r31,18
	ctx.r5.s64 = r31.s64 + 18;
	// stw r7,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// addi r4,r31,19
	ctx.r4.s64 = r31.s64 + 19;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// stw r5,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r5.u32);
	// stw r4,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r4.u32);
	// addi r9,r31,21
	ctx.r9.s64 = r31.s64 + 21;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// addi r8,r31,22
	ctx.r8.s64 = r31.s64 + 22;
	// addi r7,r31,23
	ctx.r7.s64 = r31.s64 + 23;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// addi r5,r31,25
	ctx.r5.s64 = r31.s64 + 25;
	// addi r4,r31,26
	ctx.r4.s64 = r31.s64 + 26;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// addi r10,r31,27
	ctx.r10.s64 = r31.s64 + 27;
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// addi r9,r31,28
	ctx.r9.s64 = r31.s64 + 28;
	// stw r4,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r4.u32);
	// addi r8,r31,29
	ctx.r8.s64 = r31.s64 + 29;
	// stw r10,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r10.u32);
	// addi r7,r31,30
	ctx.r7.s64 = r31.s64 + 30;
	// stw r9,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r9.u32);
	// addi r6,r31,40
	ctx.r6.s64 = r31.s64 + 40;
	// stw r8,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r8.u32);
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r6,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r6.u32);
	// addi r5,r31,50
	ctx.r5.s64 = r31.s64 + 50;
	// addi r4,r31,52
	ctx.r4.s64 = r31.s64 + 52;
	// addi r10,r31,71
	ctx.r10.s64 = r31.s64 + 71;
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// addi r9,r31,73
	ctx.r9.s64 = r31.s64 + 73;
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// addi r8,r31,81
	ctx.r8.s64 = r31.s64 + 81;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// addi r7,r31,79
	ctx.r7.s64 = r31.s64 + 79;
	// stw r9,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r9.u32);
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// stw r8,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r8.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// lwzx r3,r3,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
loc_8238F1D0:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
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

__attribute__((alias("__imp__sub_8238F1E8"))) PPC_WEAK_FUNC(sub_8238F1E8);
PPC_FUNC_IMPL(__imp__sub_8238F1E8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8109
	ctx.r3.s64 = ctx.r3.s64 + 8109;
	// b 0x82396408
	sub_82396408(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238F1F0"))) PPC_WEAK_FUNC(sub_8238F1F0);
PPC_FUNC_IMPL(__imp__sub_8238F1F0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8238F1F8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,1
	r31.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r28,8109
	ctx.r3.s64 = r28.s64 + 8109;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
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
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
	// bl 0x821c9790
	ctx.lr = 0x8238F240;
	sub_821C9790(ctx, base);
	// bl 0x82396fb8
	ctx.lr = 0x8238F244;
	sub_82396FB8(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238f290
	if (cr6.eq) goto loc_8238F290;
	// bl 0x823964a8
	ctx.lr = 0x8238F254;
	sub_823964A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238f290
	if (cr6.eq) goto loc_8238F290;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r29.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r29.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r29.u32);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
loc_8238F290:
	// mr r30,r29
	r30.u64 = r29.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,2
	ctx.r10.s64 = 2;
loc_8238F29C:
	// lwz r8,-16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r9,-12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// lwz r5,-8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// bne 0x8238f29c
	if (!cr0.eq) goto loc_8238F29C;
	// addi r31,r28,20
	r31.s64 = r28.s64 + 20;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82398018
	ctx.lr = 0x8238F2F0;
	sub_82398018(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82398018
	ctx.lr = 0x8238F308;
	sub_82398018(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82398018
	ctx.lr = 0x8238F320;
	sub_82398018(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82398018
	ctx.lr = 0x8238F338;
	sub_82398018(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82398018
	ctx.lr = 0x8238F350;
	sub_82398018(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82398018
	ctx.lr = 0x8238F368;
	sub_82398018(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82398018
	ctx.lr = 0x8238F380;
	sub_82398018(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82398018
	ctx.lr = 0x8238F398;
	sub_82398018(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82398018
	ctx.lr = 0x8238F3B0;
	sub_82398018(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82398018
	ctx.lr = 0x8238F3C8;
	sub_82398018(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82398018
	ctx.lr = 0x8238F3E0;
	sub_82398018(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82398018
	ctx.lr = 0x8238F3F8;
	sub_82398018(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// stw r7,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r7.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,2
	ctx.r10.s64 = 2;
loc_8238F40C:
	// lwz r6,-12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r8,-16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// bne 0x8238f40c
	if (!cr0.eq) goto loc_8238F40C;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r31,87(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82397f08
	ctx.lr = 0x8238F498;
	sub_82397F08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8238F4A4"))) PPC_WEAK_FUNC(sub_8238F4A4);
PPC_FUNC_IMPL(__imp__sub_8238F4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238F4A8"))) PPC_WEAK_FUNC(sub_8238F4A8);
PPC_FUNC_IMPL(__imp__sub_8238F4A8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,13508
	ctx.r5.s64 = r11.s64 + 13508;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8109
	ctx.r6.s64 = r31.s64 + 8109;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824df200
	ctx.lr = 0x8238F4E4;
	sub_824DF200(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// sth r10,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r10.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-25364
	ctx.r5.s64 = ctx.r9.s64 + -25364;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8141
	ctx.r6.s64 = r31.s64 + 8141;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824df200
	ctx.lr = 0x8238F50C;
	sub_824DF200(ctx, base);
	// li r8,34
	ctx.r8.s64 = 34;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// sth r8,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r8.u16);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x82394388
	ctx.lr = 0x8238F520;
	sub_82394388(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,8080
	ctx.r3.s64 = r31.s64 + 8080;
	// bl 0x82130000
	ctx.lr = 0x8238F52C;
	sub_82130000(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82398390
	ctx.lr = 0x8238F538;
	sub_82398390(ctx, base);
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

__attribute__((alias("__imp__sub_8238F550"))) PPC_WEAK_FUNC(sub_8238F550);
PPC_FUNC_IMPL(__imp__sub_8238F550) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// addi r10,r11,-3116
	ctx.r10.s64 = r11.s64 + -3116;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82398118
	ctx.lr = 0x8238F578;
	sub_82398118(ctx, base);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x82395138
	ctx.lr = 0x8238F580;
	sub_82395138(ctx, base);
	// addi r3,r31,8080
	ctx.r3.s64 = r31.s64 + 8080;
	// bl 0x8239e308
	ctx.lr = 0x8238F588;
	sub_8239E308(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r10,r31,8109
	ctx.r10.s64 = r31.s64 + 8109;
	// addi r11,r9,-3100
	r11.s64 = ctx.r9.s64 + -3100;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8238F59C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8238f59c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238F59C;
	// lis r9,15
	ctx.r9.s64 = 983040;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// ori r8,r9,55315
	ctx.r8.u64 = ctx.r9.u64 | 55315;
	// stb r11,8141(r31)
	PPC_STORE_U8(r31.u32 + 8141, r11.u8);
	// stw r11,8100(r31)
	PPC_STORE_U32(r31.u32 + 8100, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8096(r31)
	PPC_STORE_U32(r31.u32 + 8096, r11.u32);
	// stb r10,8108(r31)
	PPC_STORE_U8(r31.u32 + 8108, ctx.r10.u8);
	// stw r10,8088(r31)
	PPC_STORE_U32(r31.u32 + 8088, ctx.r10.u32);
	// stw r11,8104(r31)
	PPC_STORE_U32(r31.u32 + 8104, r11.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stb r11,8175(r31)
	PPC_STORE_U8(r31.u32 + 8175, r11.u8);
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

__attribute__((alias("__imp__sub_8238F5F8"))) PPC_WEAK_FUNC(sub_8238F5F8);
PPC_FUNC_IMPL(__imp__sub_8238F5F8) {
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
	// bl 0x8238ed78
	ctx.lr = 0x8238F618;
	sub_8238ED78(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238f630
	if (cr6.eq) goto loc_8238F630;
	// bl 0x82130588
	ctx.lr = 0x8238F62C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238F630:
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

__attribute__((alias("__imp__sub_8238F648"))) PPC_WEAK_FUNC(sub_8238F648);
PPC_FUNC_IMPL(__imp__sub_8238F648) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// addi r10,r11,-3116
	ctx.r10.s64 = r11.s64 + -3116;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82398118
	ctx.lr = 0x8238F678;
	sub_82398118(ctx, base);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x82395138
	ctx.lr = 0x8238F680;
	sub_82395138(ctx, base);
	// addi r3,r31,8080
	ctx.r3.s64 = r31.s64 + 8080;
	// bl 0x8239e308
	ctx.lr = 0x8238F688;
	sub_8239E308(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238ee58
	ctx.lr = 0x8238F694;
	sub_8238EE58(ctx, base);
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

__attribute__((alias("__imp__sub_8238F6B0"))) PPC_WEAK_FUNC(sub_8238F6B0);
PPC_FUNC_IMPL(__imp__sub_8238F6B0) {
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
	// bl 0x8238efe8
	ctx.lr = 0x8238F6C0;
	sub_8238EFE8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f0,-2772(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2772);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8238f6e4
	if (!cr6.lt) goto loc_8238F6E4;
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
loc_8238F6E4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,28628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28628);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8238f708
	if (!cr6.lt) goto loc_8238F708;
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
loc_8238F708:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,-2776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2776);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8238f720
	if (cr6.lt) goto loc_8238F720;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8238F720:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238F730"))) PPC_WEAK_FUNC(sub_8238F730);
PPC_FUNC_IMPL(__imp__sub_8238F730) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r11,r31,30
	r11.s64 = r31.s64 + 30;
	// li r10,10
	ctx.r10.s64 = 10;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// stb r30,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r30.u8);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
	// stb r30,15(r31)
	PPC_STORE_U8(r31.u32 + 15, r30.u8);
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// stb r30,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r30.u8);
	// stb r30,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r30.u8);
	// stb r30,19(r31)
	PPC_STORE_U8(r31.u32 + 19, r30.u8);
	// stb r30,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r30.u8);
	// stb r30,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r30.u8);
	// stb r30,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r30.u8);
	// stb r30,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r30.u8);
	// stb r30,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r30.u8);
	// stb r30,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r30.u8);
	// stb r30,26(r31)
	PPC_STORE_U8(r31.u32 + 26, r30.u8);
	// stb r30,27(r31)
	PPC_STORE_U8(r31.u32 + 27, r30.u8);
	// stb r30,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r30.u8);
	// stb r30,29(r31)
	PPC_STORE_U8(r31.u32 + 29, r30.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8238F7A4:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8238f7a4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238F7A4;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8238F7C0:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8238f7c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238F7C0;
	// stb r30,50(r31)
	PPC_STORE_U8(r31.u32 + 50, r30.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,51(r31)
	PPC_STORE_U8(r31.u32 + 51, r30.u8);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x823d9890
	ctx.lr = 0x8238F7E4;
	sub_823D9890(ctx, base);
	// stb r30,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r30.u8);
	// stb r30,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r30.u8);
	// stb r30,79(r31)
	PPC_STORE_U8(r31.u32 + 79, r30.u8);
	// stb r30,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r30.u8);
	// addi r11,r31,73
	r11.s64 = r31.s64 + 73;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8238F804:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8238f804
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8238F804;
	// stb r30,81(r31)
	PPC_STORE_U8(r31.u32 + 81, r30.u8);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// sth r30,82(r31)
	PPC_STORE_U16(r31.u32 + 82, r30.u16);
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

__attribute__((alias("__imp__sub_8238F834"))) PPC_WEAK_FUNC(sub_8238F834);
PPC_FUNC_IMPL(__imp__sub_8238F834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238F838"))) PPC_WEAK_FUNC(sub_8238F838);
PPC_FUNC_IMPL(__imp__sub_8238F838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r24{};
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,52
	cr6.compare<uint32_t>(r11.u32, 52, xer);
	// bgt cr6,0x8238f960
	if (cr6.gt) goto loc_8238F960;
	// lis r12,-32199
	r12.s64 = -2110193664;
	// addi r12,r12,-1956
	r12.s64 = r12.s64 + -1956;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8238F930;
	case 1:
		goto loc_8238F930;
	case 2:
		goto loc_8238F930;
	case 3:
		goto loc_8238F930;
	case 4:
		goto loc_8238F930;
	case 5:
		goto loc_8238F930;
	case 6:
		goto loc_8238F940;
	case 7:
		goto loc_8238F948;
	case 8:
		goto loc_8238F950;
	case 9:
		goto loc_8238F938;
	case 10:
		goto loc_8238F930;
	case 11:
		goto loc_8238F930;
	case 12:
		goto loc_8238F930;
	case 13:
		goto loc_8238F930;
	case 14:
		goto loc_8238F960;
	case 15:
		goto loc_8238F930;
	case 16:
		goto loc_8238F930;
	case 17:
		goto loc_8238F930;
	case 18:
		goto loc_8238F930;
	case 19:
		goto loc_8238F960;
	case 20:
		goto loc_8238F930;
	case 21:
		goto loc_8238F960;
	case 22:
		goto loc_8238F960;
	case 23:
		goto loc_8238F960;
	case 24:
		goto loc_8238F960;
	case 25:
		goto loc_8238F960;
	case 26:
		goto loc_8238F960;
	case 27:
		goto loc_8238F960;
	case 28:
		goto loc_8238F960;
	case 29:
		goto loc_8238F930;
	case 30:
		goto loc_8238F960;
	case 31:
		goto loc_8238F960;
	case 32:
		goto loc_8238F960;
	case 33:
		goto loc_8238F960;
	case 34:
		goto loc_8238F958;
	case 35:
		goto loc_8238F960;
	case 36:
		goto loc_8238F960;
	case 37:
		goto loc_8238F960;
	case 38:
		goto loc_8238F960;
	case 39:
		goto loc_8238F960;
	case 40:
		goto loc_8238F960;
	case 41:
		goto loc_8238F960;
	case 42:
		goto loc_8238F930;
	case 43:
		goto loc_8238F930;
	case 44:
		goto loc_8238F930;
	case 45:
		goto loc_8238F930;
	case 46:
		goto loc_8238F960;
	case 47:
		goto loc_8238F960;
	case 48:
		goto loc_8238F960;
	case 49:
		goto loc_8238F960;
	case 50:
		goto loc_8238F960;
	case 51:
		goto loc_8238F938;
	case 52:
		goto loc_8238F930;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1728(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1728);
	// lwz r17,-1720(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1720);
	// lwz r17,-1712(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1712);
	// lwz r17,-1736(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1736);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1704(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1704);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1696(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1696);
	// lwz r17,-1736(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1736);
	// lwz r17,-1744(r24)
	r17.u64 = PPC_LOAD_U32(r24.u32 + -1744);
loc_8238F930:
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_8238F938:
	// li r3,80
	ctx.r3.s64 = 80;
	// blr 
	return;
loc_8238F940:
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
loc_8238F948:
	// li r3,150
	ctx.r3.s64 = 150;
	// blr 
	return;
loc_8238F950:
	// li r3,10
	ctx.r3.s64 = 10;
	// blr 
	return;
loc_8238F958:
	// li r3,45
	ctx.r3.s64 = 45;
	// blr 
	return;
loc_8238F960:
	// li r3,0
	ctx.r3.s64 = 0;
}

__attribute__((alias("__imp__sub_8238F968"))) PPC_WEAK_FUNC(sub_8238F968);
PPC_FUNC_IMPL(__imp__sub_8238F968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,34
	ctx.r4.s64 = 34;
	// addi r3,r3,8141
	ctx.r3.s64 = ctx.r3.s64 + 8141;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238F980"))) PPC_WEAK_FUNC(sub_8238F980);
PPC_FUNC_IMPL(__imp__sub_8238F980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r3,8109
	ctx.r3.s64 = ctx.r3.s64 + 8109;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238F998"))) PPC_WEAK_FUNC(sub_8238F998);
PPC_FUNC_IMPL(__imp__sub_8238F998) {
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
	// addi r3,r3,8109
	ctx.r3.s64 = ctx.r3.s64 + 8109;
	// bl 0x82396408
	ctx.lr = 0x8238F9AC;
	sub_82396408(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238F9CC"))) PPC_WEAK_FUNC(sub_8238F9CC);
PPC_FUNC_IMPL(__imp__sub_8238F9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238F9D0"))) PPC_WEAK_FUNC(sub_8238F9D0);
PPC_FUNC_IMPL(__imp__sub_8238F9D0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r31,r30,8109
	r31.s64 = r30.s64 + 8109;
	// addi r4,r11,-2716
	ctx.r4.s64 = r11.s64 + -2716;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d90b0
	ctx.lr = 0x8238F9FC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238fa1c
	if (cr6.eq) goto loc_8238FA1C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r5,r11,-2736
	ctx.r5.s64 = r11.s64 + -2736;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8238FA18;
	sub_82137A08(ctx, base);
	// b 0x8238fa5c
	goto loc_8238FA5C;
loc_8238FA1C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-2744
	ctx.r4.s64 = r11.s64 + -2744;
	// bl 0x823d90b0
	ctx.lr = 0x8238FA2C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x8238fa4c
	if (cr6.eq) goto loc_8238FA4C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r31,4
	ctx.r6.s64 = r31.s64 + 4;
	// addi r5,r11,-2756
	ctx.r5.s64 = r11.s64 + -2756;
	// b 0x8238fa58
	goto loc_8238FA58;
loc_8238FA4C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r6,r31,3
	ctx.r6.s64 = r31.s64 + 3;
	// addi r5,r11,-2768
	ctx.r5.s64 = r11.s64 + -2768;
loc_8238FA58:
	// bl 0x82137a08
	ctx.lr = 0x8238FA5C;
	sub_82137A08(ctx, base);
loc_8238FA5C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,-12040(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12040);
	// bl 0x82399b60
	ctx.lr = 0x8238FA70;
	sub_82399B60(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8238fa80
	if (!cr6.lt) goto loc_8238FA80;
	// li r31,0
	r31.s64 = 0;
loc_8238FA80:
	// clrlwi r4,r31,24
	ctx.r4.u64 = r31.u32 & 0xFF;
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// bl 0x82391e18
	ctx.lr = 0x8238FA8C;
	sub_82391E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_8238FAA8"))) PPC_WEAK_FUNC(sub_8238FAA8);
PPC_FUNC_IMPL(__imp__sub_8238FAA8) {
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
	ctx.lr = 0x8238FAB0;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-2696
	ctx.r4.s64 = ctx.r10.s64 + -2696;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8238FAD0;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r5,r9,-6232
	ctx.r5.s64 = ctx.r9.s64 + -6232;
	// addi r4,r8,-2712
	ctx.r4.s64 = ctx.r8.s64 + -2712;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8238FAF0;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8238fb10
	if (!cr6.eq) goto loc_8238FB10;
	// bl 0x821c9a90
	ctx.lr = 0x8238FB04;
	sub_821C9A90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d924c
	return;
loc_8238FB10:
	// bl 0x821c9a90
	ctx.lr = 0x8238FB14;
	sub_821C9A90(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-29924
	ctx.r9.s64 = r11.s64 + -29924;
	// stw r10,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r4,4416(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4416);
	// bl 0x821cf7b8
	ctx.lr = 0x8238FB3C;
	sub_821CF7B8(ctx, base);
loc_8238FB3C:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,80
	ctx.r5.s64 = 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821cffe8
	ctx.lr = 0x8238FB54;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8238fb3c
	if (cr6.eq) goto loc_8238FB3C;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8238fbbc
	if (cr6.eq) goto loc_8238FBBC;
	// addi r10,r30,8109
	ctx.r10.s64 = r30.s64 + 8109;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8238FB6C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8238fb90
	if (cr6.eq) goto loc_8238FB90;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8238fb6c
	if (cr6.eq) goto loc_8238FB6C;
loc_8238FB90:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8238fb3c
	if (!cr6.eq) goto loc_8238FB3C;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821d0490
	ctx.lr = 0x8238FBA4;
	sub_821D0490(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8238FBB0;
	sub_821BE610(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d924c
	return;
loc_8238FBBC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x8238FBC4;
	sub_821BE610(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8238FBD0"))) PPC_WEAK_FUNC(sub_8238FBD0);
PPC_FUNC_IMPL(__imp__sub_8238FBD0) {
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
	ctx.lr = 0x8238FBD8;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821bbea8
	ctx.lr = 0x8238FBF0;
	sub_821BBEA8(ctx, base);
	// li r3,5728
	ctx.r3.s64 = 5728;
	// bl 0x82130528
	ctx.lr = 0x8238FBF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238fc10
	if (cr6.eq) goto loc_8238FC10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824df990
	ctx.lr = 0x8238FC08;
	sub_824DF990(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8238fc14
	goto loc_8238FC14;
loc_8238FC10:
	// li r31,0
	r31.s64 = 0;
loc_8238FC14:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f4a8
	ctx.lr = 0x8238FC20;
	sub_8238F4A8(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x8238FC24;
	sub_821BBF00(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca8c8
	ctx.lr = 0x8238FC34;
	sub_821CA8C8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x8238FC48;
	sub_821CA540(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stb r10,5724(r31)
	PPC_STORE_U8(r31.u32 + 5724, ctx.r10.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0288
	ctx.lr = 0x8238FC60;
	sub_824E0288(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8238FC6C;
	sub_821C9A90(ctx, base);
	// lis r9,15
	ctx.r9.s64 = 983040;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r8,r9,65535
	ctx.r8.u64 = ctx.r9.u64 | 65535;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r8,8092(r30)
	PPC_STORE_U32(r30.u32 + 8092, ctx.r8.u32);
	// bl 0x821c9790
	ctx.lr = 0x8238FC84;
	sub_821C9790(ctx, base);
	// stw r3,8104(r30)
	PPC_STORE_U32(r30.u32 + 8104, ctx.r3.u32);
	// bl 0x821bbea8
	ctx.lr = 0x8238FC8C;
	sub_821BBEA8(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8238FCA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x821bbf00
	ctx.lr = 0x8238FCA8;
	sub_821BBF00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238FCB4"))) PPC_WEAK_FUNC(sub_8238FCB4);
PPC_FUNC_IMPL(__imp__sub_8238FCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238FCB8"))) PPC_WEAK_FUNC(sub_8238FCB8);
PPC_FUNC_IMPL(__imp__sub_8238FCB8) {
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
	// li r3,8176
	ctx.r3.s64 = 8176;
	// bl 0x82130528
	ctx.lr = 0x8238FCD8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238fcec
	if (cr6.eq) goto loc_8238FCEC;
	// bl 0x8238f550
	ctx.lr = 0x8238FCE4;
	sub_8238F550(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8238fcf0
	goto loc_8238FCF0;
loc_8238FCEC:
	// li r31,0
	r31.s64 = 0;
loc_8238FCF0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8238fd1c
	if (cr6.eq) goto loc_8238FD1C;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fd1c
	if (cr6.eq) goto loc_8238FD1C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r31,8109
	ctx.r3.s64 = r31.s64 + 8109;
	// bl 0x82137a08
	ctx.lr = 0x8238FD1C;
	sub_82137A08(ctx, base);
loc_8238FD1C:
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

__attribute__((alias("__imp__sub_8238FD38"))) PPC_WEAK_FUNC(sub_8238FD38);
PPC_FUNC_IMPL(__imp__sub_8238FD38) {
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
	ctx.lr = 0x8238FD40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,8109
	r28.s64 = r31.s64 + 8109;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,8100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8100);
	// lwz r29,8088(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8088);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r27,r9,1
	r27.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82396408
	ctx.lr = 0x8238FD6C;
	sub_82396408(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12120);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,12(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// bl 0x82396408
	ctx.lr = 0x8238FD84;
	sub_82396408(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8238fd90
	if (cr6.lt) goto loc_8238FD90;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8238FD90:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82398170
	ctx.lr = 0x8238FD9C;
	sub_82398170(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x823955c8
	ctx.lr = 0x8238FDB4;
	sub_823955C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,8080
	ctx.r3.s64 = r31.s64 + 8080;
	// bl 0x8239e318
	ctx.lr = 0x8238FDCC;
	sub_8239E318(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226b338
	ctx.lr = 0x8238FDE8;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,8092
	ctx.r4.s64 = r31.s64 + 8092;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82299788
	ctx.lr = 0x8238FE04;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,8096(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8096);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226b338
	ctx.lr = 0x8238FE20;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f70
	ctx.lr = 0x8238FE38;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82619080
	ctx.lr = 0x8238FE54;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fe80
	if (cr6.eq) goto loc_8238FE80;
	// li r5,34
	ctx.r5.s64 = 34;
	// addi r4,r31,8141
	ctx.r4.s64 = r31.s64 + 8141;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82619080
	ctx.lr = 0x8238FE70;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8238fe84
	if (!cr6.eq) goto loc_8238FE84;
loc_8238FE80:
	// li r11,0
	r11.s64 = 0;
loc_8238FE84:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238FE90"))) PPC_WEAK_FUNC(sub_8238FE90);
PPC_FUNC_IMPL(__imp__sub_8238FE90) {
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
	ctx.lr = 0x8238FE98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r31,r29,8109
	r31.s64 = r29.s64 + 8109;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8238FEB4;
	sub_82396408(ctx, base);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r26,r29,8141
	r26.s64 = r29.s64 + 8141;
	// lwz r25,48(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8238f6b0
	ctx.lr = 0x8238FED4;
	sub_8238F6B0(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r3,65
	ctx.r4.s64 = ctx.r3.s64 + 65;
	// addi r3,r10,-2680
	ctx.r3.s64 = ctx.r10.s64 + -2680;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// bl 0x82130000
	ctx.lr = 0x8238FEEC;
	sub_82130000(ctx, base);
	// lwz r9,8100(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8100);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8238ff04
	if (!cr6.eq) goto loc_8238FF04;
loc_8238FEF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8238FF04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8238FF0C;
	sub_82396408(ctx, base);
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823961a0
	ctx.lr = 0x8238FF20;
	sub_823961A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238fef8
	if (cr6.eq) goto loc_8238FEF8;
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// bne cr6,0x8238ff64
	if (!cr6.eq) goto loc_8238FF64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8238FF3C;
	sub_82396408(ctx, base);
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823964a8
	ctx.lr = 0x8238FF4C;
	sub_823964A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8238ffa4
	if (!cr6.eq) goto loc_8238FFA4;
loc_8238FF58:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8238FF64:
	// cmpwi cr6,r27,5
	cr6.compare<int32_t>(r27.s32, 5, xer);
	// bne cr6,0x8238ff9c
	if (!cr6.eq) goto loc_8238FF9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396408
	ctx.lr = 0x8238FF74;
	sub_82396408(ctx, base);
	// lwz r11,-12120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12120);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823964a8
	ctx.lr = 0x8238FF84;
	sub_823964A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238ffa4
	if (cr6.eq) goto loc_8238FFA4;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8238FF9C:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8238ff58
	if (cr6.lt) goto loc_8238FF58;
loc_8238FFA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f6b0
	ctx.lr = 0x8238FFAC;
	sub_8238F6B0(ctx, base);
	// subfic r11,r27,3
	xer.ca = r27.u32 <= 3;
	r11.s64 = 3 - r27.s64;
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8238FFC4"))) PPC_WEAK_FUNC(sub_8238FFC4);
PPC_FUNC_IMPL(__imp__sub_8238FFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238FFC8"))) PPC_WEAK_FUNC(sub_8238FFC8);
PPC_FUNC_IMPL(__imp__sub_8238FFC8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,-10208
	ctx.r9.s64 = r11.s64 + -10208;
	// addi r11,r31,30
	r11.s64 = r31.s64 + 30;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// stb r30,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r30.u8);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
	// stb r30,15(r31)
	PPC_STORE_U8(r31.u32 + 15, r30.u8);
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// stb r30,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r30.u8);
	// stb r30,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r30.u8);
	// stb r30,19(r31)
	PPC_STORE_U8(r31.u32 + 19, r30.u8);
	// stb r30,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r30.u8);
	// stb r30,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r30.u8);
	// stb r30,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r30.u8);
	// stb r30,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r30.u8);
	// stb r30,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r30.u8);
	// stb r30,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r30.u8);
	// stb r30,26(r31)
	PPC_STORE_U8(r31.u32 + 26, r30.u8);
	// stb r30,27(r31)
	PPC_STORE_U8(r31.u32 + 27, r30.u8);
	// stb r30,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r30.u8);
	// stb r30,29(r31)
	PPC_STORE_U8(r31.u32 + 29, r30.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82390050:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82390050
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82390050;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8239006C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8239006c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8239006C;
	// stb r30,50(r31)
	PPC_STORE_U8(r31.u32 + 50, r30.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,51(r31)
	PPC_STORE_U8(r31.u32 + 51, r30.u8);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x823d9890
	ctx.lr = 0x82390090;
	sub_823D9890(ctx, base);
	// stb r30,71(r31)
	PPC_STORE_U8(r31.u32 + 71, r30.u8);
	// stb r30,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r30.u8);
	// addi r11,r31,73
	r11.s64 = r31.s64 + 73;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823900A8:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x823900a8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823900A8;
	// stb r30,79(r31)
	PPC_STORE_U8(r31.u32 + 79, r30.u8);
	// stb r30,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r30.u8);
	// stb r30,81(r31)
	PPC_STORE_U8(r31.u32 + 81, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r30,82(r31)
	PPC_STORE_U16(r31.u32 + 82, r30.u16);
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

__attribute__((alias("__imp__sub_823900E0"))) PPC_WEAK_FUNC(sub_823900E0);
PPC_FUNC_IMPL(__imp__sub_823900E0) {
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
	ctx.lr = 0x823900E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8238f838
	ctx.lr = 0x823900FC;
	sub_8238F838(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x823901b4
	if (!cr6.gt) goto loc_823901B4;
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// bge cr6,0x823901b4
	if (!cr6.lt) goto loc_823901B4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f0b0
	ctx.lr = 0x82390114;
	sub_8238F0B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823901b4
	if (cr6.eq) goto loc_823901B4;
	// clrlwi r10,r31,29
	ctx.r10.u64 = r31.u32 & 0x7;
	// srawi r11,r31,3
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7) != 0);
	r11.s64 = r31.s32 >> 3;
	// li r9,1
	ctx.r9.s64 = 1;
	// slw r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// lbzx r7,r11,r3
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r3.u32);
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x823901b4
	if (!cr6.eq) goto loc_823901B4;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stbx r8,r11,r3
	PPC_STORE_U8(r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lhz r11,82(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 82);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,52684
	cr6.compare<uint32_t>(r11.u32, 52684, xer);
	// bne cr6,0x82390178
	if (!cr6.eq) goto loc_82390178;
	// lis r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r11,r11,52684
	r11.u64 = r11.u64 | 52684;
	// sth r11,82(r30)
	PPC_STORE_U16(r30.u32 + 82, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82390178:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x823901a0
	if (!cr6.lt) goto loc_823901A0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,82(r30)
	PPC_STORE_U16(r30.u32 + 82, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823901A0:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r11,82(r30)
	PPC_STORE_U16(r30.u32 + 82, r11.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823901B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823901C0"))) PPC_WEAK_FUNC(sub_823901C0);
PPC_FUNC_IMPL(__imp__sub_823901C0) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x8238f838
	ctx.lr = 0x823901DC;
	sub_8238F838(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x823901fc
	if (cr6.gt) goto loc_823901FC;
loc_823901E4:
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
loc_823901FC:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8238f0b0
	ctx.lr = 0x82390204;
	sub_8238F0B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823901e4
	if (cr6.eq) goto loc_823901E4;
	// srawi r11,r31,3
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7) != 0);
	r11.s64 = r31.s32 >> 3;
	// clrlwi r10,r31,29
	ctx.r10.u64 = r31.u32 & 0x7;
	// li r9,1
	ctx.r9.s64 = 1;
	// slw r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// lbzx r7,r11,r3
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r3.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
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

__attribute__((alias("__imp__sub_82390244"))) PPC_WEAK_FUNC(sub_82390244);
PPC_FUNC_IMPL(__imp__sub_82390244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82390248"))) PPC_WEAK_FUNC(sub_82390248);
PPC_FUNC_IMPL(__imp__sub_82390248) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82390250;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x821c9788
	ctx.lr = 0x82390278;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821ce460
	ctx.lr = 0x82390288;
	sub_821CE460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r30,8109
	ctx.r3.s64 = r30.s64 + 8109;
	// addi r11,r10,-3100
	r11.s64 = ctx.r10.s64 + -3100;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823902A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x823902a0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823902A0;
	// li r29,0
	r29.s64 = 0;
	// stb r29,8141(r30)
	PPC_STORE_U8(r30.u32 + 8141, r29.u8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r9,8108(r30)
	PPC_STORE_U8(r30.u32 + 8108, ctx.r9.u8);
	// stw r29,8104(r30)
	PPC_STORE_U32(r30.u32 + 8104, r29.u32);
	// lis r11,23772
	r11.s64 = 1557921792;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// ori r31,r11,64167
	r31.u64 = r11.u64 | 64167;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r6,r8,-12120
	ctx.r6.s64 = ctx.r8.s64 + -12120;
	// stw r29,8100(r30)
	PPC_STORE_U32(r30.u32 + 8100, r29.u32);
	// mulld r10,r10,r31
	ctx.r10.s64 = ctx.r10.s64 * r31.s64;
	// stw r29,8096(r30)
	PPC_STORE_U32(r30.u32 + 8096, r29.u32);
	// stw r9,8088(r30)
	PPC_STORE_U32(r30.u32 + 8088, ctx.r9.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lhz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// rldicl r6,r11,32,32
	ctx.r6.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// lwz r11,-12120(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12120);
	// addi r5,r4,9572
	ctx.r5.s64 = ctx.r4.s64 + 9572;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// divw r6,r7,r9
	ctx.r6.s32 = ctx.r7.s32 / ctx.r9.s32;
	// mullw r4,r6,r9
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// subf r8,r4,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// mulli r6,r8,104
	ctx.r6.s64 = ctx.r8.s64 * 104;
	// lwzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// li r4,32
	ctx.r4.s64 = 32;
	// andc r11,r9,r7
	r11.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// twllei r9,0
	// twlgei r11,-1
	// bl 0x82137a08
	ctx.lr = 0x82390344;
	sub_82137A08(ctx, base);
	// lis r11,12483
	r11.s64 = 818085888;
	// addi r28,r30,64
	r28.s64 = r30.s64 + 64;
	// ori r30,r11,3121
	r30.u64 = r11.u64 | 3121;
loc_82390350:
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mulld r10,r9,r31
	ctx.r10.s64 = ctx.r9.s64 * r31.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r7,r11,32,32
	ctx.r7.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// mulhw r5,r6,r30
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(r30.s32)) >> 32;
	// srawi r11,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	r11.s64 = ctx.r5.s32 >> 3;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mulli r10,r11,42
	ctx.r10.s64 = r11.s64 * 42;
	// subf r5,r10,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r10.s64;
	// bl 0x823924b0
	ctx.lr = 0x82390394;
	sub_823924B0(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// bne cr6,0x82390350
	if (!cr6.eq) goto loc_82390350;
	// lwz r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mulld r10,r7,r31
	ctx.r10.s64 = ctx.r7.s64 * r31.s64;
	// lfs f31,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f31.f64 = double(temp.f32);
	// add r11,r10,r8
	r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r10,r11,32,32
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r9,r6,r31
	ctx.r9.s64 = ctx.r6.s64 * r31.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rldicl r11,r10,32,32
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// mulld r9,r4,r31
	ctx.r9.s64 = ctx.r4.s64 * r31.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r5,r10,9
	ctx.r5.u64 = ctx.r10.u32 & 0x7FFFFF;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f5,f8,f31
	ctx.f5.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f5,116(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f4,f7,f31
	ctx.f4.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f4,120(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f3,f6,f31
	ctx.f3.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f3,112(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8261e2b8
	ctx.lr = 0x82390448;
	sub_8261E2B8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8261e440
	ctx.lr = 0x82390450;
	sub_8261E440(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f30,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// beq cr6,0x82390468
	if (cr6.eq) goto loc_82390468;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8261e4f8
	ctx.lr = 0x82390468;
	sub_8261E4F8(ctx, base);
loc_82390468:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82391ff8
	ctx.lr = 0x82390480;
	sub_82391FF8(ctx, base);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mulld r10,r9,r31
	ctx.r10.s64 = ctx.r9.s64 * r31.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r10,r11,32,32
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r9,r8,r31
	ctx.r9.s64 = ctx.r8.s64 * r31.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rldicl r11,r10,32,32
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// mulld r9,r6,r31
	ctx.r9.s64 = ctx.r6.s64 * r31.s64;
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// clrlwi r7,r10,9
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFF;
	// clrlwi r9,r11,9
	ctx.r9.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// rldicl r5,r11,32,32
	ctx.r5.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f4,f7,f31
	ctx.f4.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f4,120(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// fmuls f3,f6,f31
	ctx.f3.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f3,112(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f5,f8,f31
	ctx.f5.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f5,116(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8261e2b8
	ctx.lr = 0x82390518;
	sub_8261E2B8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8261e440
	ctx.lr = 0x82390520;
	sub_8261E440(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// beq cr6,0x82390530
	if (cr6.eq) goto loc_82390530;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8261e4f8
	ctx.lr = 0x82390530;
	sub_8261E4F8(ctx, base);
loc_82390530:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82391ff8
	ctx.lr = 0x82390548;
	sub_82391FF8(ctx, base);
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

__attribute__((alias("__imp__sub_82390558"))) PPC_WEAK_FUNC(sub_82390558);
PPC_FUNC_IMPL(__imp__sub_82390558) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8238faa8
	ctx.lr = 0x82390574;
	sub_8238FAA8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x82390584
	if (!cr6.lt) goto loc_82390584;
	// li r31,0
	r31.s64 = 0;
loc_82390584:
	// clrlwi r4,r31,24
	ctx.r4.u64 = r31.u32 & 0xFF;
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// bl 0x82391e00
	ctx.lr = 0x82390590;
	sub_82391E00(ctx, base);
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

__attribute__((alias("__imp__sub_823905AC"))) PPC_WEAK_FUNC(sub_823905AC);
PPC_FUNC_IMPL(__imp__sub_823905AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823905B0"))) PPC_WEAK_FUNC(sub_823905B0);
PPC_FUNC_IMPL(__imp__sub_823905B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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

__attribute__((alias("__imp__sub_823905D4"))) PPC_WEAK_FUNC(sub_823905D4);
PPC_FUNC_IMPL(__imp__sub_823905D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823905D8"))) PPC_WEAK_FUNC(sub_823905D8);
PPC_FUNC_IMPL(__imp__sub_823905D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8238ee58
	sub_8238EE58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823905E8"))) PPC_WEAK_FUNC(sub_823905E8);
PPC_FUNC_IMPL(__imp__sub_823905E8) {
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
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8239062c
	if (cr6.eq) goto loc_8239062C;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,8109
	r11.s64 = r11.s64 + 8109;
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
loc_8239062C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-2968
	ctx.r3.s64 = r11.s64 + -2968;
	// bl 0x82130000
	ctx.lr = 0x82390638;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,-2996
	ctx.r8.s64 = ctx.r9.s64 + -2996;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8239065C"))) PPC_WEAK_FUNC(sub_8239065C);
PPC_FUNC_IMPL(__imp__sub_8239065C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82390660"))) PPC_WEAK_FUNC(sub_82390660);
PPC_FUNC_IMPL(__imp__sub_82390660) {
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
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823906a4
	if (cr6.eq) goto loc_823906A4;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,8141
	r11.s64 = r11.s64 + 8141;
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
loc_823906A4:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-2872
	ctx.r3.s64 = r11.s64 + -2872;
	// bl 0x82130000
	ctx.lr = 0x823906B0;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,-2996
	ctx.r8.s64 = ctx.r9.s64 + -2996;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823906D4"))) PPC_WEAK_FUNC(sub_823906D4);
PPC_FUNC_IMPL(__imp__sub_823906D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823906D8"))) PPC_WEAK_FUNC(sub_823906D8);
PPC_FUNC_IMPL(__imp__sub_823906D8) {
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
	ctx.lr = 0x823906E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// bl 0x824e9038
	ctx.lr = 0x82390704;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82388628
	ctx.lr = 0x82390714;
	sub_82388628(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82390758
	if (cr6.lt) goto loc_82390758;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e9690
	ctx.lr = 0x82390730;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82390758
	if (cr6.eq) goto loc_82390758;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x8238fe90
	ctx.lr = 0x82390750;
	sub_8238FE90(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82390758:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82390764"))) PPC_WEAK_FUNC(sub_82390764);
PPC_FUNC_IMPL(__imp__sub_82390764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82390768"))) PPC_WEAK_FUNC(sub_82390768);
PPC_FUNC_IMPL(__imp__sub_82390768) {
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
	ctx.lr = 0x82390770;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-12040(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12040);
	// lbz r10,2116(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2116);
	// lhz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 44);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8239079c
	if (cr6.lt) goto loc_8239079C;
	// bl 0x8238f9d0
	ctx.lr = 0x82390798;
	sub_8238F9D0(ctx, base);
	// lwz r11,-12040(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12040);
loc_8239079C:
	// lbz r10,2118(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2118);
	// lhz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x823907d4
	if (cr6.lt) goto loc_823907D4;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823907cc
	if (cr6.eq) goto loc_823907CC;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x82391e00
	ctx.lr = 0x823907C4;
	sub_82391E00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823907CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82390558
	ctx.lr = 0x823907D4;
	sub_82390558(ctx, base);
loc_823907D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823907DC"))) PPC_WEAK_FUNC(sub_823907DC);
PPC_FUNC_IMPL(__imp__sub_823907DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

