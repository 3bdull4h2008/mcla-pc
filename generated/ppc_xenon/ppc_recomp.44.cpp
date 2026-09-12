#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822C7198"))) PPC_WEAK_FUNC(sub_822C7198);
PPC_FUNC_IMPL(__imp__sub_822C7198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822C71A0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x822c748c
	if (cr6.gt) goto loc_822C748C;
	// lis r12,-32212
	r12.s64 = -2111045632;
	// addi r12,r12,29144
	r12.s64 = r12.s64 + 29144;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822C71EC;
	case 1:
		goto loc_822C7338;
	case 2:
		goto loc_822C7370;
	case 3:
		goto loc_822C73E0;
	case 4:
		goto loc_822C7460;
	default:
		__builtin_unreachable();
	}
	// lwz r17,29164(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29164);
	// lwz r17,29496(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29496);
	// lwz r17,29552(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29552);
	// lwz r17,29664(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29664);
	// lwz r17,29792(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29792);
loc_822C71EC:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C71F8;
	sub_8268C9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x822c748c
	if (cr6.gt) goto loc_822C748C;
	// lis r12,-32212
	r12.s64 = -2111045632;
	// addi r12,r12,29216
	r12.s64 = r12.s64 + 29216;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822C723C;
	case 1:
		goto loc_822C72C8;
	case 2:
		goto loc_822C748C;
	case 3:
		goto loc_822C748C;
	case 4:
		goto loc_822C7274;
	case 5:
		goto loc_822C7274;
	case 6:
		goto loc_822C7300;
	default:
		__builtin_unreachable();
	}
	// lwz r17,29244(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29244);
	// lwz r17,29384(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29384);
	// lwz r17,29836(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29836);
	// lwz r17,29836(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29836);
	// lwz r17,29300(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29300);
	// lwz r17,29300(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29300);
	// lwz r17,29440(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 29440);
loc_822C723C:
	// lwz r30,4(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C724C;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x822C7264;
	sub_821FDE78(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C7274:
	// lwz r30,4(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C7284;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x822C729C;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x822C72B0;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C72C8:
	// lfs f31,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f31.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C72D8;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fde10
	ctx.lr = 0x822C72F0;
	sub_821FDE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C7300:
	// lbz r30,4(r3)
	r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C7310;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x822c7138
	ctx.lr = 0x822C7328;
	sub_822C7138(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C7338:
	// bl 0x823bbf80
	ctx.lr = 0x822C733C;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c748c
	if (cr6.eq) goto loc_822C748C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C7354;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C7370:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r30,r11,-18800
	r30.s64 = r11.s64 + -18800;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x822C7380;
	sub_821FA230(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c748c
	if (cr6.eq) goto loc_822C748C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x822C7390;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C73A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c748c
	if (cr6.eq) goto loc_822C748C;
	// bl 0x82256058
	ctx.lr = 0x822C73B0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c748c
	if (cr6.eq) goto loc_822C748C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C73C4;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C73E0:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822C73F0;
	sub_822A3998(ctx, base);
	// bl 0x822a7cc8
	ctx.lr = 0x822C73F4;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c748c
	if (cr6.eq) goto loc_822C748C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822C740C;
	sub_822A3998(ctx, base);
	// lbz r11,17(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c7428
	if (!cr6.eq) goto loc_822C7428;
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822c742c
	if (cr6.eq) goto loc_822C742C;
loc_822C7428:
	// li r11,1
	r11.s64 = 1;
loc_822C742C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c748c
	if (!cr6.eq) goto loc_822C748C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822C7444;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822C7460:
	// bl 0x823bbf80
	ctx.lr = 0x822C7464;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c748c
	if (cr6.eq) goto loc_822C748C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb498
	ctx.lr = 0x822C747C;
	sub_823BB498(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// addi r3,r11,10736
	ctx.r3.s64 = r11.s64 + 10736;
	// bl 0x82214168
	ctx.lr = 0x822C748C;
	sub_82214168(ctx, base);
loc_822C748C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C749C"))) PPC_WEAK_FUNC(sub_822C749C);
PPC_FUNC_IMPL(__imp__sub_822C749C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C74A0"))) PPC_WEAK_FUNC(sub_822C74A0);
PPC_FUNC_IMPL(__imp__sub_822C74A0) {
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
	// bl 0x822d2d00
	ctx.lr = 0x822C74B8;
	sub_822D2D00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-24528
	ctx.r9.s64 = ctx.r10.s64 + -24528;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
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

__attribute__((alias("__imp__sub_822C74F4"))) PPC_WEAK_FUNC(sub_822C74F4);
PPC_FUNC_IMPL(__imp__sub_822C74F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C74F8"))) PPC_WEAK_FUNC(sub_822C74F8);
PPC_FUNC_IMPL(__imp__sub_822C74F8) {
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
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8258b088
	ctx.lr = 0x822C7514;
	sub_8258B088(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c7524
	if (cr6.eq) goto loc_822C7524;
	// bl 0x82729d28
	ctx.lr = 0x822C7524;
	sub_82729D28(ctx, base);
loc_822C7524:
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

__attribute__((alias("__imp__sub_822C7538"))) PPC_WEAK_FUNC(sub_822C7538);
PPC_FUNC_IMPL(__imp__sub_822C7538) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-6420
	ctx.r10.s64 = r11.s64 + -6420;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// b 0x822d5a30
	sub_822D5A30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C7550"))) PPC_WEAK_FUNC(sub_822C7550);
PPC_FUNC_IMPL(__imp__sub_822C7550) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C7554"))) PPC_WEAK_FUNC(sub_822C7554);
PPC_FUNC_IMPL(__imp__sub_822C7554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7558"))) PPC_WEAK_FUNC(sub_822C7558);
PPC_FUNC_IMPL(__imp__sub_822C7558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-24480
	ctx.r3.s64 = r11.s64 + -24480;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C7564"))) PPC_WEAK_FUNC(sub_822C7564);
PPC_FUNC_IMPL(__imp__sub_822C7564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7568"))) PPC_WEAK_FUNC(sub_822C7568);
PPC_FUNC_IMPL(__imp__sub_822C7568) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,-27856(r11)
	PPC_STORE_U32(r11.u32 + -27856, ctx.r3.u32);
	// bl 0x822c4eb8
	ctx.lr = 0x822C7580;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c54d8
	ctx.lr = 0x822C7588;
	sub_822C54D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C7598"))) PPC_WEAK_FUNC(sub_822C7598);
PPC_FUNC_IMPL(__imp__sub_822C7598) {
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
	// bl 0x822c4eb8
	ctx.lr = 0x822C75AC;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822c4ed8
	ctx.lr = 0x822C75B8;
	sub_822C4ED8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4ec8
	ctx.lr = 0x822C75C4;
	sub_822C4EC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C75D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C75E0;
	sub_822C4F20(ctx, base);
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

__attribute__((alias("__imp__sub_822C75F4"))) PPC_WEAK_FUNC(sub_822C75F4);
PPC_FUNC_IMPL(__imp__sub_822C75F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C75F8"))) PPC_WEAK_FUNC(sub_822C75F8);
PPC_FUNC_IMPL(__imp__sub_822C75F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C7604"))) PPC_WEAK_FUNC(sub_822C7604);
PPC_FUNC_IMPL(__imp__sub_822C7604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7608"))) PPC_WEAK_FUNC(sub_822C7608);
PPC_FUNC_IMPL(__imp__sub_822C7608) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d6800
	sub_822D6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C760C"))) PPC_WEAK_FUNC(sub_822C760C);
PPC_FUNC_IMPL(__imp__sub_822C760C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7610"))) PPC_WEAK_FUNC(sub_822C7610);
PPC_FUNC_IMPL(__imp__sub_822C7610) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-24468
	ctx.r10.s64 = r11.s64 + -24468;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8272a8e0
	ctx.lr = 0x822C763C;
	sub_8272A8E0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c7654
	if (cr6.eq) goto loc_822C7654;
	// bl 0x82130588
	ctx.lr = 0x822C7650;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C7654:
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

__attribute__((alias("__imp__sub_822C766C"))) PPC_WEAK_FUNC(sub_822C766C);
PPC_FUNC_IMPL(__imp__sub_822C766C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7670"))) PPC_WEAK_FUNC(sub_822C7670);
PPC_FUNC_IMPL(__imp__sub_822C7670) {
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
	ctx.lr = 0x822C7678;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x822C769C;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822c76c8
	if (!cr6.eq) goto loc_822C76C8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r11,-24464
	ctx.r3.s64 = r11.s64 + -24464;
	// bl 0x82130000
	ctx.lr = 0x822C76BC;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
loc_822C76C8:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1ce8
	ctx.lr = 0x822C76D4;
	sub_821D1CE8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r28,528
	ctx.r3.s64 = r28.s64 + 528;
	// bl 0x8268a598
	ctx.lr = 0x822C76E0;
	sub_8268A598(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x822C76E8;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C76F4"))) PPC_WEAK_FUNC(sub_822C76F4);
PPC_FUNC_IMPL(__imp__sub_822C76F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C76F8"))) PPC_WEAK_FUNC(sub_822C76F8);
PPC_FUNC_IMPL(__imp__sub_822C76F8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-24528
	ctx.r10.s64 = r11.s64 + -24528;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822d2bb8
	ctx.lr = 0x822C7724;
	sub_822D2BB8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c773c
	if (cr6.eq) goto loc_822C773C;
	// bl 0x82130588
	ctx.lr = 0x822C7738;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C773C:
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

__attribute__((alias("__imp__sub_822C7754"))) PPC_WEAK_FUNC(sub_822C7754);
PPC_FUNC_IMPL(__imp__sub_822C7754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7758"))) PPC_WEAK_FUNC(sub_822C7758);
PPC_FUNC_IMPL(__imp__sub_822C7758) {
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
	ctx.lr = 0x822C7760;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82681630
	ctx.lr = 0x822C776C;
	sub_82681630(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c778c
	if (cr6.eq) goto loc_822C778C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C778C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C778C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r29,0
	r29.s64 = 0;
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c77d0
	if (cr6.eq) goto loc_822C77D0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-4964(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4964);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c77c4
	if (cr6.eq) goto loc_822C77C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C77C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C77C4:
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-4964(r30)
	PPC_STORE_U32(r30.u32 + -4964, r11.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
loc_822C77D0:
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// bl 0x822ecb30
	ctx.lr = 0x822C77D8;
	sub_822ECB30(ctx, base);
	// bl 0x8229d4b8
	ctx.lr = 0x822C77DC;
	sub_8229D4B8(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c77fc
	if (cr6.eq) goto loc_822C77FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C77FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C77FC:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// lwz r3,-17628(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17628);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c7814
	if (cr6.eq) goto loc_822C7814;
	// bl 0x82173840
	ctx.lr = 0x822C7814;
	sub_82173840(ctx, base);
loc_822C7814:
	// bl 0x826fbfb0
	ctx.lr = 0x822C7818;
	sub_826FBFB0(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-11832(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -11832);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c783c
	if (cr6.eq) goto loc_822C783C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C783C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C783C:
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-11832(r30)
	PPC_STORE_U32(r30.u32 + -11832, r11.u32);
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822c7860
	if (cr6.eq) goto loc_822C7860;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8226aee0
	ctx.lr = 0x822C7858;
	sub_8226AEE0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822C7860;
	sub_82130588(ctx, base);
loc_822C7860:
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C786C"))) PPC_WEAK_FUNC(sub_822C786C);
PPC_FUNC_IMPL(__imp__sub_822C786C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7870"))) PPC_WEAK_FUNC(sub_822C7870);
PPC_FUNC_IMPL(__imp__sub_822C7870) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lwz r11,76(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c78dc
	if (cr6.eq) goto loc_822C78DC;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x825883c0
	ctx.lr = 0x822C78A8;
	sub_825883C0(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C78C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82588428
	ctx.lr = 0x822C78CC;
	sub_82588428(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82476238
	ctx.lr = 0x822C78D8;
	sub_82476238(ctx, base);
	// b 0x822c7914
	goto loc_822C7914;
loc_822C78DC:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23636(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c78fc
	if (cr6.eq) goto loc_822C78FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C78FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C78FC:
	// bl 0x822e9b38
	ctx.lr = 0x822C7900;
	sub_822E9B38(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C7914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C7914:
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

__attribute__((alias("__imp__sub_822C792C"))) PPC_WEAK_FUNC(sub_822C792C);
PPC_FUNC_IMPL(__imp__sub_822C792C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7930"))) PPC_WEAK_FUNC(sub_822C7930);
PPC_FUNC_IMPL(__imp__sub_822C7930) {
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
	// li r3,612
	ctx.r3.s64 = 612;
	// bl 0x82130528
	ctx.lr = 0x822C7948;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c7980
	if (cr6.eq) goto loc_822C7980;
	// bl 0x8272b218
	ctx.lr = 0x822C7958;
	sub_8272B218(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-24468
	ctx.r9.s64 = r11.s64 + -24468;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-4964(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4964, r31.u32);
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
loc_822C7980:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-4964(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4964, r11.u32);
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

__attribute__((alias("__imp__sub_822C79A0"))) PPC_WEAK_FUNC(sub_822C79A0);
PPC_FUNC_IMPL(__imp__sub_822C79A0) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822C79A8;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x822C79B0;
	// stwu r1,-1312(r1)
	ea = -1312 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238ec00
	ctx.lr = 0x822C79C4;
	sub_8238EC00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d6058
	ctx.lr = 0x822C79CC;
	sub_822D6058(ctx, base);
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x822C79D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c79e4
	if (cr6.eq) goto loc_822C79E4;
	// bl 0x822da3d8
	ctx.lr = 0x822C79E0;
	sub_822DA3D8(ctx, base);
	// b 0x822c79e8
	goto loc_822C79E8;
loc_822C79E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C79E8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-11832
	r11.s64 = r11.s64 + -11832;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x822da210
	ctx.lr = 0x822C79F8;
	sub_822DA210(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826fc2f8
	ctx.lr = 0x822C7A00;
	sub_826FC2F8(ctx, base);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// lwz r11,-17628(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7a90
	if (cr6.eq) goto loc_822C7A90;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,28
	r27.s64 = 28;
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C7A34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,19612
	ctx.r4.s64 = ctx.r9.s64 + 19612;
	// bl 0x821ca540
	ctx.lr = 0x822C7A44;
	sub_821CA540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x822C7A50;
	sub_821CA540(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// addi r4,r8,-24304
	ctx.r4.s64 = ctx.r8.s64 + -24304;
	// bl 0x82177020
	ctx.lr = 0x822C7A64;
	sub_82177020(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822C7A6C;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822C7A74;
	sub_821C9A90(ctx, base);
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// bl 0x82173e20
	ctx.lr = 0x822C7A7C;
	sub_82173E20(ctx, base);
	// lwzx r3,r27,r28
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822C7A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C7A90:
	// lis r27,-32119
	r27.s64 = -2104950784;
	// lwz r11,-17604(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -17604);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7b0c
	if (cr6.eq) goto loc_822C7B0C;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,28
	r28.s64 = 28;
	// lwzx r3,r28,r29
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C7ABC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r9,-24320
	ctx.r5.s64 = ctx.r9.s64 + -24320;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82137a08
	ctx.lr = 0x822C7AD4;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca540
	ctx.lr = 0x822C7AE0;
	sub_821CA540(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r3,-17604(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17604);
	// addi r4,r8,-24332
	ctx.r4.s64 = ctx.r8.s64 + -24332;
	// bl 0x82689a48
	ctx.lr = 0x822C7AF0;
	sub_82689A48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822C7AF8;
	sub_821C9A90(ctx, base);
	// lwzx r3,r28,r29
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822C7B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C7B0C:
	// lis r27,-32119
	r27.s64 = -2104950784;
	// lwz r11,-17600(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -17600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7bbc
	if (cr6.eq) goto loc_822C7BBC;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c7bbc
	if (cr6.eq) goto loc_822C7BBC;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,28
	r28.s64 = 28;
	// lwzx r3,r28,r29
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C7B48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r9,-24348
	ctx.r5.s64 = ctx.r9.s64 + -24348;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82137a08
	ctx.lr = 0x822C7B60;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// bl 0x821ca540
	ctx.lr = 0x822C7B6C;
	sub_821CA540(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,-17600(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17600);
	// addi r5,r8,-24356
	ctx.r5.s64 = ctx.r8.s64 + -24356;
	// addi r4,r7,-24368
	ctx.r4.s64 = ctx.r7.s64 + -24368;
	// bl 0x822c7670
	ctx.lr = 0x822C7B84;
	sub_822C7670(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,-17600(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17600);
	// addi r5,r6,-24388
	ctx.r5.s64 = ctx.r6.s64 + -24388;
	// addi r4,r4,-24408
	ctx.r4.s64 = ctx.r4.s64 + -24408;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x82689d18
	ctx.lr = 0x822C7BA0;
	sub_82689D18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822C7BA8;
	sub_821C9A90(ctx, base);
	// lwzx r3,r28,r29
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C7BBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C7BBC:
	// li r3,204
	ctx.r3.s64 = 204;
	// bl 0x82130528
	ctx.lr = 0x822C7BC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c7bd4
	if (cr6.eq) goto loc_822C7BD4;
	// bl 0x82740fb8
	ctx.lr = 0x822C7BD0;
	sub_82740FB8(ctx, base);
	// b 0x822c7bd8
	goto loc_822C7BD8;
loc_822C7BD4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C7BD8:
	// stw r3,20(r26)
	PPC_STORE_U32(r26.u32 + 20, ctx.r3.u32);
	// bl 0x82587f10
	ctx.lr = 0x822C7BE0;
	sub_82587F10(ctx, base);
	// bl 0x822e9a98
	ctx.lr = 0x822C7BE4;
	sub_822E9A98(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r4,20(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r27,3528(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lwz r5,8(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// addi r6,r5,16
	ctx.r6.s64 = ctx.r5.s64 + 16;
	// bl 0x822d4c58
	ctx.lr = 0x822C7C04;
	sub_822D4C58(ctx, base);
	// lwz r7,8(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,8(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lvx128 v62,r6,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,8(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lfs f1,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f31.f64 = double(temp.f32);
	// lfs f30,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f30.f64 = double(temp.f32);
	// lfs f29,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f29.f64 = double(temp.f32);
	// lfs f28,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f28.f64 = double(temp.f32);
	// bl 0x822da7e8
	ctx.lr = 0x822C7C4C;
	sub_822DA7E8(ctx, base);
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x822C7C54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c7c64
	if (cr6.eq) goto loc_822C7C64;
	// bl 0x8226ae80
	ctx.lr = 0x822C7C60;
	sub_8226AE80(ctx, base);
	// b 0x822c7c68
	goto loc_822C7C68;
loc_822C7C64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C7C68:
	// stw r3,24(r26)
	PPC_STORE_U32(r26.u32 + 24, ctx.r3.u32);
	// stfs f29,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f28,92(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-3660(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3660);
	// bl 0x8226aa98
	ctx.lr = 0x822C7C98;
	sub_8226AA98(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x825f3d78
	ctx.lr = 0x822C7CA0;
	sub_825F3D78(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fmr f5,f28
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f28.f64;
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f6,31020(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31020);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f6
	ctx.f3.f64 = ctx.f6.f64;
	// bl 0x825f3de8
	ctx.lr = 0x822C7CC4;
	sub_825F3DE8(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,30436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 30436);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822C7CE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x822ed428
	ctx.lr = 0x822C7CE4;
	sub_822ED428(ctx, base);
	// bl 0x822ecd28
	ctx.lr = 0x822C7CE8;
	sub_822ECD28(ctx, base);
	// bl 0x822e9170
	ctx.lr = 0x822C7CEC;
	sub_822E9170(ctx, base);
	// lis r29,-32120
	r29.s64 = -2105016320;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-7436(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -7436);
	// bl 0x822f98d8
	ctx.lr = 0x822C7D00;
	sub_822F98D8(ctx, base);
	// bl 0x822c7930
	ctx.lr = 0x822C7D04;
	sub_822C7930(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r31,r11,-13560
	r31.s64 = r11.s64 + -13560;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// addi r28,r11,-27852
	r28.s64 = r11.s64 + -27852;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r11,-4964(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -4964);
	// stw r11,28(r26)
	PPC_STORE_U32(r26.u32 + 28, r11.u32);
	// lwz r11,19620(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 19620);
	// stw r11,32(r26)
	PPC_STORE_U32(r26.u32 + 32, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c7d70
	if (!cr6.eq) goto loc_822C7D70;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,28(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// bl 0x8272ca60
	ctx.lr = 0x822C7D48;
	sub_8272CA60(ctx, base);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r3,28(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7d68
	if (cr6.eq) goto loc_822C7D68;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,-27856(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// bl 0x8272ac30
	ctx.lr = 0x822C7D64;
	sub_8272AC30(ctx, base);
	// b 0x822c7d70
	goto loc_822C7D70;
loc_822C7D68:
	// lwz r4,-27856(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// bl 0x8272ce50
	ctx.lr = 0x822C7D70;
	sub_8272CE50(ctx, base);
loc_822C7D70:
	// lwz r3,-7436(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -7436);
	// bl 0x822f87e8
	ctx.lr = 0x822C7D78;
	sub_822F87E8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c7df0
	if (!cr6.eq) goto loc_822C7DF0;
loc_822C7D84:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c7d84
	if (cr6.eq) goto loc_822C7D84;
	// li r3,36
	ctx.r3.s64 = 36;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x82130528
	ctx.lr = 0x822C7DA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c7db0
	if (cr6.eq) goto loc_822C7DB0;
	// bl 0x82310200
	ctx.lr = 0x822C7DAC;
	sub_82310200(ctx, base);
	// b 0x822c7db4
	goto loc_822C7DB4;
loc_822C7DB0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C7DB4:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7dd4
	if (cr6.eq) goto loc_822C7DD4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r5,-27856(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// lwz r4,-7572(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x823107f0
	ctx.lr = 0x822C7DD0;
	sub_823107F0(ctx, base);
	// b 0x822c7ddc
	goto loc_822C7DDC;
loc_822C7DD4:
	// lwz r4,-27856(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// bl 0x82310988
	ctx.lr = 0x822C7DDC;
	sub_82310988(ctx, base);
loc_822C7DDC:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c7ddc
	if (cr6.eq) goto loc_822C7DDC;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_822C7DF0:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x822C7DF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c7e0c
	if (cr6.eq) goto loc_822C7E0C;
	// lwz r4,8(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// bl 0x82680240
	ctx.lr = 0x822C7E08;
	sub_82680240(ctx, base);
	// b 0x822c7e10
	goto loc_822C7E10;
loc_822C7E0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C7E10:
	// stw r3,36(r26)
	PPC_STORE_U32(r26.u32 + 36, ctx.r3.u32);
	// bl 0x82681cd8
	ctx.lr = 0x822C7E18;
	sub_82681CD8(ctx, base);
	// bl 0x822ed628
	ctx.lr = 0x822C7E1C;
	sub_822ED628(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-18004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// bl 0x82305230
	ctx.lr = 0x822C7E28;
	sub_82305230(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d2028
	ctx.lr = 0x822C7E30;
	sub_821D2028(ctx, base);
	// addi r1,r1,1312
	ctx.r1.s64 = ctx.r1.s64 + 1312;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x822C7E3C;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822C7E40"))) PPC_WEAK_FUNC(sub_822C7E40);
PPC_FUNC_IMPL(__imp__sub_822C7E40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r4,-27856(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// b 0x822c79a0
	sub_822C79A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C7E4C"))) PPC_WEAK_FUNC(sub_822C7E4C);
PPC_FUNC_IMPL(__imp__sub_822C7E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7E50"))) PPC_WEAK_FUNC(sub_822C7E50);
PPC_FUNC_IMPL(__imp__sub_822C7E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f8,f12,f12
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f1,f7
	ctx.f1.f64 = double(float(sqrt(ctx.f7.f64)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C7E78"))) PPC_WEAK_FUNC(sub_822C7E78);
PPC_FUNC_IMPL(__imp__sub_822C7E78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822C7E80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387b90
	ctx.lr = 0x822C7E90;
	sub_82387B90(ctx, base);
	// extsh r5,r30
	ctx.r5.s64 = r30.s16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x8238af98
	ctx.lr = 0x822C7EA0;
	sub_8238AF98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238b128
	ctx.lr = 0x822C7EAC;
	sub_8238B128(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C7EB4"))) PPC_WEAK_FUNC(sub_822C7EB4);
PPC_FUNC_IMPL(__imp__sub_822C7EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7EB8"))) PPC_WEAK_FUNC(sub_822C7EB8);
PPC_FUNC_IMPL(__imp__sub_822C7EB8) {
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
	ctx.lr = 0x822C7EC0;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x822c7efc
	if (!cr6.eq) goto loc_822C7EFC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822c7eec
	if (cr6.eq) goto loc_822C7EEC;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822c7ef0
	if (!cr6.eq) goto loc_822C7EF0;
loc_822C7EEC:
	// li r11,1
	r11.s64 = 1;
loc_822C7EF0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_822C7EFC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822c7fbc
	if (cr6.eq) goto loc_822C7FBC;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7fbc
	if (cr6.eq) goto loc_822C7FBC;
	// li r5,127
	ctx.r5.s64 = 127;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x822C7F20;
	sub_823DB670(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r5,127
	ctx.r5.s64 = 127;
	// stb r30,207(r1)
	PPC_STORE_U8(ctx.r1.u32 + 207, r30.u8);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x823db670
	ctx.lr = 0x822C7F38;
	sub_823DB670(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// stb r30,335(r1)
	PPC_STORE_U8(ctx.r1.u32 + 335, r30.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7f6c
	if (cr6.eq) goto loc_822C7F6C;
loc_822C7F4C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x822C7F58;
	sub_823DF058(ctx, base);
	// stb r3,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c7f4c
	if (!cr6.eq) goto loc_822C7F4C;
loc_822C7F6C:
	// lbz r11,208(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 208);
	// addi r31,r1,208
	r31.s64 = ctx.r1.s64 + 208;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7f9c
	if (cr6.eq) goto loc_822C7F9C;
loc_822C7F7C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x822C7F88;
	sub_823DF058(ctx, base);
	// stb r3,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c7f7c
	if (!cr6.eq) goto loc_822C7F7C;
loc_822C7F9C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d90b0
	ctx.lr = 0x822C7FA8;
	sub_823D90B0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_822C7FBC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C7FC8"))) PPC_WEAK_FUNC(sub_822C7FC8);
PPC_FUNC_IMPL(__imp__sub_822C7FC8) {
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
	// bl 0x82207d30
	ctx.lr = 0x822C7FE8;
	sub_82207D30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c7ffc
	if (cr6.eq) goto loc_822C7FFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822c803c
	goto loc_822C803C;
loc_822C7FFC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388598
	ctx.lr = 0x822C8004;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// slw r8,r9,r30
	ctx.r8.u64 = r30.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r30.u8 & 0x3F));
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xor r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// and r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 & ctx.r8.u64;
	// and r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
loc_822C803C:
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

__attribute__((alias("__imp__sub_822C8054"))) PPC_WEAK_FUNC(sub_822C8054);
PPC_FUNC_IMPL(__imp__sub_822C8054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8058"))) PPC_WEAK_FUNC(sub_822C8058);
PPC_FUNC_IMPL(__imp__sub_822C8058) {
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
	// bl 0x82207d30
	ctx.lr = 0x822C8070;
	sub_82207D30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c8098
	if (cr6.eq) goto loc_822C8098;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
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
loc_822C8098:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82388598
	ctx.lr = 0x822C80A0;
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
	// lfs f0,-28876(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28876);
	f0.f64 = double(temp.f32);
	// lbz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// lfs f12,1068(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 1068);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
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
	// blt cr6,0x822c80fc
	if (cr6.lt) goto loc_822C80FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822c8100
	if (!cr6.gt) goto loc_822C8100;
loc_822C80FC:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_822C8100:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
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

__attribute__((alias("__imp__sub_822C8118"))) PPC_WEAK_FUNC(sub_822C8118);
PPC_FUNC_IMPL(__imp__sub_822C8118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c81c8
	if (cr6.eq) goto loc_822C81C8;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-27760(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27760);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c8158
	if (!cr6.eq) goto loc_822C8158;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r11,-27760(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27760, r11.u32);
loc_822C8158:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r30,r8,-27824
	r30.s64 = ctx.r8.s64 + -27824;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r6,48
	ctx.r6.s64 = 48;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v60,v63,v61
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stvx128 v63,r30,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x822C81BC;
	sub_82202EC0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// b 0x822c81d0
	goto loc_822C81D0;
loc_822C81C8:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C81D0:
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822d5340
	ctx.lr = 0x822C81D8;
	sub_822D5340(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_822C81F0"))) PPC_WEAK_FUNC(sub_822C81F0);
PPC_FUNC_IMPL(__imp__sub_822C81F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c8290
	if (cr6.eq) goto loc_822C8290;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-27680(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27680);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c8230
	if (!cr6.eq) goto loc_822C8230;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r11,-27680(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27680, r11.u32);
loc_822C8230:
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vaddfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r30,r11,-27744
	r30.s64 = r11.s64 + -27744;
	// li r7,48
	ctx.r7.s64 = 48;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v63,r30,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x822C8284;
	sub_82202EC0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// b 0x822c8298
	goto loc_822C8298;
loc_822C8290:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C8298:
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822d5340
	ctx.lr = 0x822C82A0;
	sub_822D5340(ctx, base);
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

__attribute__((alias("__imp__sub_822C82B8"))) PPC_WEAK_FUNC(sub_822C82B8);
PPC_FUNC_IMPL(__imp__sub_822C82B8) {
	PPC_FUNC_PROLOGUE();
	// b 0x822c7598
	sub_822C7598(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82BC"))) PPC_WEAK_FUNC(sub_822C82BC);
PPC_FUNC_IMPL(__imp__sub_822C82BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82C0"))) PPC_WEAK_FUNC(sub_822C82C0);
PPC_FUNC_IMPL(__imp__sub_822C82C0) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d3a40
	sub_822D3A40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82C4"))) PPC_WEAK_FUNC(sub_822C82C4);
PPC_FUNC_IMPL(__imp__sub_822C82C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82C8"))) PPC_WEAK_FUNC(sub_822C82C8);
PPC_FUNC_IMPL(__imp__sub_822C82C8) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d67f0
	sub_822D67F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82CC"))) PPC_WEAK_FUNC(sub_822C82CC);
PPC_FUNC_IMPL(__imp__sub_822C82CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82D0"))) PPC_WEAK_FUNC(sub_822C82D0);
PPC_FUNC_IMPL(__imp__sub_822C82D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x822bfb38
	sub_822BFB38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82D4"))) PPC_WEAK_FUNC(sub_822C82D4);
PPC_FUNC_IMPL(__imp__sub_822C82D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82D8"))) PPC_WEAK_FUNC(sub_822C82D8);
PPC_FUNC_IMPL(__imp__sub_822C82D8) {
	PPC_FUNC_PROLOGUE();
	// b 0x822bfb90
	sub_822BFB90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82DC"))) PPC_WEAK_FUNC(sub_822C82DC);
PPC_FUNC_IMPL(__imp__sub_822C82DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82E0"))) PPC_WEAK_FUNC(sub_822C82E0);
PPC_FUNC_IMPL(__imp__sub_822C82E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x826a62d0
	sub_826A62D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82E4"))) PPC_WEAK_FUNC(sub_822C82E4);
PPC_FUNC_IMPL(__imp__sub_822C82E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82E8"))) PPC_WEAK_FUNC(sub_822C82E8);
PPC_FUNC_IMPL(__imp__sub_822C82E8) {
	PPC_FUNC_PROLOGUE();
	// b 0x826a6300
	sub_826A6300(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82EC"))) PPC_WEAK_FUNC(sub_822C82EC);
PPC_FUNC_IMPL(__imp__sub_822C82EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82F0"))) PPC_WEAK_FUNC(sub_822C82F0);
PPC_FUNC_IMPL(__imp__sub_822C82F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8269fcc8
	sub_8269FCC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82F4"))) PPC_WEAK_FUNC(sub_822C82F4);
PPC_FUNC_IMPL(__imp__sub_822C82F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C82F8"))) PPC_WEAK_FUNC(sub_822C82F8);
PPC_FUNC_IMPL(__imp__sub_822C82F8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8269fb18
	sub_8269FB18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C82FC"))) PPC_WEAK_FUNC(sub_822C82FC);
PPC_FUNC_IMPL(__imp__sub_822C82FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8300"))) PPC_WEAK_FUNC(sub_822C8300);
PPC_FUNC_IMPL(__imp__sub_822C8300) {
	PPC_FUNC_PROLOGUE();
	// b 0x826a6330
	sub_826A6330(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8304"))) PPC_WEAK_FUNC(sub_822C8304);
PPC_FUNC_IMPL(__imp__sub_822C8304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8308"))) PPC_WEAK_FUNC(sub_822C8308);
PPC_FUNC_IMPL(__imp__sub_822C8308) {
	PPC_FUNC_PROLOGUE();
	// b 0x8269f8c0
	sub_8269F8C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C830C"))) PPC_WEAK_FUNC(sub_822C830C);
PPC_FUNC_IMPL(__imp__sub_822C830C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8310"))) PPC_WEAK_FUNC(sub_822C8310);
PPC_FUNC_IMPL(__imp__sub_822C8310) {
	PPC_FUNC_PROLOGUE();
	// b 0x8269c240
	sub_8269C240(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8314"))) PPC_WEAK_FUNC(sub_822C8314);
PPC_FUNC_IMPL(__imp__sub_822C8314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8318"))) PPC_WEAK_FUNC(sub_822C8318);
PPC_FUNC_IMPL(__imp__sub_822C8318) {
	PPC_FUNC_PROLOGUE();
	// b 0x826ab510
	sub_826AB510(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C831C"))) PPC_WEAK_FUNC(sub_822C831C);
PPC_FUNC_IMPL(__imp__sub_822C831C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8320"))) PPC_WEAK_FUNC(sub_822C8320);
PPC_FUNC_IMPL(__imp__sub_822C8320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r11,r5,r6
	r11.s64 = ctx.r6.s64 - ctx.r5.s64;
	// ori r7,r9,64167
	ctx.r7.u64 = ctx.r9.u64 | 64167;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mulld r9,r8,r7
	ctx.r9.s64 = ctx.r8.s64 * ctx.r7.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// twllei r11,0
	// clrlwi r8,r10,1
	ctx.r8.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// twllei r6,0
	// divw r31,r8,r11
	r31.s32 = ctx.r8.s32 / r11.s32;
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r7,r31,r11
	ctx.r7.s64 = int64_t(r31.s32) * int64_t(r11.s32);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// subf r9,r5,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rldicl r8,r10,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// add r10,r9,r4
	ctx.r10.u64 = ctx.r9.u64 + ctx.r4.u64;
	// andc r7,r11,r7
	ctx.r7.u64 = r11.u64 & ~ctx.r7.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// twlgei r7,-1
	// rotlwi r11,r4,1
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// divw r3,r4,r6
	ctx.r3.s32 = ctx.r4.s32 / ctx.r6.s32;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// mullw r9,r3,r6
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// subf r11,r9,r4
	r11.s64 = ctx.r4.s64 - ctx.r9.s64;
	// andc r8,r6,r10
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r10.u64;
	// add r3,r11,r5
	ctx.r3.u64 = r11.u64 + ctx.r5.u64;
	// twlgei r8,-1
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C83AC"))) PPC_WEAK_FUNC(sub_822C83AC);
PPC_FUNC_IMPL(__imp__sub_822C83AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C83B0"))) PPC_WEAK_FUNC(sub_822C83B0);
PPC_FUNC_IMPL(__imp__sub_822C83B0) {
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
	// bl 0x82553a18
	ctx.lr = 0x822C83D0;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// bge cr6,0x822c83e4
	if (!cr6.lt) goto loc_822C83E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x822c843c
	goto loc_822C843C;
loc_822C83E4:
	// bl 0x8268d518
	ctx.lr = 0x822C83E8;
	sub_8268D518(ctx, base);
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r9,r10,64167
	ctx.r9.u64 = ctx.r10.u64 | 64167;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mulld r10,r7,r9
	ctx.r10.s64 = ctx.r7.s64 * ctx.r9.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// twllei r8,0
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// rldicl r5,r11,32,32
	ctx.r5.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r4,r6,r8
	ctx.r4.s32 = ctx.r6.s32 / ctx.r8.s32;
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// mullw r9,r4,r8
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// subf r11,r9,r6
	r11.s64 = ctx.r6.s64 - ctx.r9.s64;
	// andc r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// twlgei r4,-1
loc_822C843C:
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

__attribute__((alias("__imp__sub_822C8454"))) PPC_WEAK_FUNC(sub_822C8454);
PPC_FUNC_IMPL(__imp__sub_822C8454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8458"))) PPC_WEAK_FUNC(sub_822C8458);
PPC_FUNC_IMPL(__imp__sub_822C8458) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// bl 0x82553a18
	ctx.lr = 0x822C8478;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// bge cr6,0x822c848c
	if (!cr6.lt) goto loc_822C848C;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// b 0x822c84e0
	goto loc_822C84E0;
loc_822C848C:
	// bl 0x8268d518
	ctx.lr = 0x822C8490;
	sub_8268D518(ctx, base);
	// lis r11,23772
	r11.s64 = 1557921792;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f13,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f31.f64));
	// ori r8,r11,64167
	ctx.r8.u64 = r11.u64 | 64167;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mulld r10,r7,r8
	ctx.r10.s64 = ctx.r7.s64 * ctx.r8.s64;
	// lfs f0,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmadds f1,f9,f0,f31
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64 + f31.f64));
loc_822C84E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C84F8"))) PPC_WEAK_FUNC(sub_822C84F8);
PPC_FUNC_IMPL(__imp__sub_822C84F8) {
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
	ctx.lr = 0x822C8500;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82553a18
	ctx.lr = 0x822C8514;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x8268d518
	ctx.lr = 0x822C851C;
	sub_8268D518(ctx, base);
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r11,r31,r29
	r11.s64 = r29.s64 - r31.s64;
	// ori r9,r10,64167
	ctx.r9.u64 = ctx.r10.u64 | 64167;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulld r9,r7,r9
	ctx.r9.s64 = ctx.r7.s64 * ctx.r9.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// twllei r11,0
	// clrlwi r6,r10,1
	ctx.r6.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// twllei r8,0
	// divw r4,r6,r11
	ctx.r4.s32 = ctx.r6.s32 / r11.s32;
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// mullw r7,r4,r11
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(r11.s32);
	// subf r6,r7,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r7.s64;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// subf r9,r31,r6
	ctx.r9.s64 = ctx.r6.s64 - r31.s64;
	// rldicl r4,r10,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// add r10,r9,r30
	ctx.r10.u64 = ctx.r9.u64 + r30.u64;
	// andc r11,r11,r5
	r11.u64 = r11.u64 & ~ctx.r5.u64;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// twlgei r11,-1
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r9,r10,r8
	ctx.r9.s32 = ctx.r10.s32 / ctx.r8.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r9,r8
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// subf r11,r6,r10
	r11.s64 = ctx.r10.s64 - ctx.r6.s64;
	// andc r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// twlgei r5,-1
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C85A4"))) PPC_WEAK_FUNC(sub_822C85A4);
PPC_FUNC_IMPL(__imp__sub_822C85A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C85A8"))) PPC_WEAK_FUNC(sub_822C85A8);
PPC_FUNC_IMPL(__imp__sub_822C85A8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// bl 0x824804d0
	ctx.lr = 0x822C85D8;
	sub_824804D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c85fc
	if (cr6.eq) goto loc_822C85FC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a020
	ctx.lr = 0x822C85F0;
	sub_8247A020(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a838
	ctx.lr = 0x822C85F8;
	sub_8247A838(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C85FC:
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

__attribute__((alias("__imp__sub_822C8614"))) PPC_WEAK_FUNC(sub_822C8614);
PPC_FUNC_IMPL(__imp__sub_822C8614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8618"))) PPC_WEAK_FUNC(sub_822C8618);
PPC_FUNC_IMPL(__imp__sub_822C8618) {
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
	// bl 0x82553a18
	ctx.lr = 0x822C862C;
	sub_82553A18(ctx, base);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r31,r11,1
	r31.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// bl 0x8268d518
	ctx.lr = 0x822C8664;
	sub_8268D518(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ce210
	ctx.lr = 0x822C866C;
	sub_821CE210(ctx, base);
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

__attribute__((alias("__imp__sub_822C8680"))) PPC_WEAK_FUNC(sub_822C8680);
PPC_FUNC_IMPL(__imp__sub_822C8680) {
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
	// bl 0x82553a18
	ctx.lr = 0x822C869C;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x8268d518
	ctx.lr = 0x822C86A4;
	sub_8268D518(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ce210
	ctx.lr = 0x822C86AC;
	sub_821CE210(ctx, base);
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

__attribute__((alias("__imp__sub_822C86C0"))) PPC_WEAK_FUNC(sub_822C86C0);
PPC_FUNC_IMPL(__imp__sub_822C86C0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822c83b0
	ctx.lr = 0x822C86E4;
	sub_822C83B0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8700"))) PPC_WEAK_FUNC(sub_822C8700);
PPC_FUNC_IMPL(__imp__sub_822C8700) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822c8458
	ctx.lr = 0x822C8724;
	sub_822C8458(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C8740"))) PPC_WEAK_FUNC(sub_822C8740);
PPC_FUNC_IMPL(__imp__sub_822C8740) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x822c84f8
	ctx.lr = 0x822C8768;
	sub_822C84F8(ctx, base);
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

__attribute__((alias("__imp__sub_822C8784"))) PPC_WEAK_FUNC(sub_822C8784);
PPC_FUNC_IMPL(__imp__sub_822C8784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8788"))) PPC_WEAK_FUNC(sub_822C8788);
PPC_FUNC_IMPL(__imp__sub_822C8788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f30.f64 = double(temp.f32);
	// bl 0x82553a18
	ctx.lr = 0x822C87B4;
	sub_82553A18(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x8268d518
	ctx.lr = 0x822C87BC;
	sub_8268D518(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x821ce328
	ctx.lr = 0x822C87C8;
	sub_821CE328(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C87EC"))) PPC_WEAK_FUNC(sub_822C87EC);
PPC_FUNC_IMPL(__imp__sub_822C87EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C87F0"))) PPC_WEAK_FUNC(sub_822C87F0);
PPC_FUNC_IMPL(__imp__sub_822C87F0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x821bb3d8
	ctx.lr = 0x822C8824;
	sub_821BB3D8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,30288(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C884C"))) PPC_WEAK_FUNC(sub_822C884C);
PPC_FUNC_IMPL(__imp__sub_822C884C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8850"))) PPC_WEAK_FUNC(sub_822C8850);
PPC_FUNC_IMPL(__imp__sub_822C8850) {
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
	ctx.lr = 0x822C8858;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82387b90
	ctx.lr = 0x822C886C;
	sub_82387B90(ctx, base);
	// extsh r5,r30
	ctx.r5.s64 = r30.s16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x8238af98
	ctx.lr = 0x822C887C;
	sub_8238AF98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238b128
	ctx.lr = 0x822C8888;
	sub_8238B128(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C8890"))) PPC_WEAK_FUNC(sub_822C8890);
PPC_FUNC_IMPL(__imp__sub_822C8890) {
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
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82388580
	ctx.lr = 0x822C88B0;
	sub_82388580(ctx, base);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
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

__attribute__((alias("__imp__sub_822C88C8"))) PPC_WEAK_FUNC(sub_822C88C8);
PPC_FUNC_IMPL(__imp__sub_822C88C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82728100
	sub_82728100(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C88D4"))) PPC_WEAK_FUNC(sub_822C88D4);
PPC_FUNC_IMPL(__imp__sub_822C88D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C88D8"))) PPC_WEAK_FUNC(sub_822C88D8);
PPC_FUNC_IMPL(__imp__sub_822C88D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82728090
	sub_82728090(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C88E4"))) PPC_WEAK_FUNC(sub_822C88E4);
PPC_FUNC_IMPL(__imp__sub_822C88E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C88E8"))) PPC_WEAK_FUNC(sub_822C88E8);
PPC_FUNC_IMPL(__imp__sub_822C88E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x827280c8
	sub_827280C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C88F4"))) PPC_WEAK_FUNC(sub_822C88F4);
PPC_FUNC_IMPL(__imp__sub_822C88F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C88F8"))) PPC_WEAK_FUNC(sub_822C88F8);
PPC_FUNC_IMPL(__imp__sub_822C88F8) {
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
	// bl 0x82728178
	ctx.lr = 0x822C8910;
	sub_82728178(ctx, base);
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

__attribute__((alias("__imp__sub_822C8930"))) PPC_WEAK_FUNC(sub_822C8930);
PPC_FUNC_IMPL(__imp__sub_822C8930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822cad80
	sub_822CAD80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C893C"))) PPC_WEAK_FUNC(sub_822C893C);
PPC_FUNC_IMPL(__imp__sub_822C893C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8940"))) PPC_WEAK_FUNC(sub_822C8940);
PPC_FUNC_IMPL(__imp__sub_822C8940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,3656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3656);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,3656(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3656, temp.u32);
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8960"))) PPC_WEAK_FUNC(sub_822C8960);
PPC_FUNC_IMPL(__imp__sub_822C8960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,3528
	ctx.r9.s64 = r11.s64 + 3528;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,24(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 24, temp.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8984"))) PPC_WEAK_FUNC(sub_822C8984);
PPC_FUNC_IMPL(__imp__sub_822C8984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8988"))) PPC_WEAK_FUNC(sub_822C8988);
PPC_FUNC_IMPL(__imp__sub_822C8988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r10,3528
	ctx.r9.s64 = ctx.r10.s64 + 3528;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// stb r11,28(r9)
	PPC_STORE_U8(ctx.r9.u32 + 28, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C89B8"))) PPC_WEAK_FUNC(sub_822C89B8);
PPC_FUNC_IMPL(__imp__sub_822C89B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x822d67e0
	sub_822D67E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C89D4"))) PPC_WEAK_FUNC(sub_822C89D4);
PPC_FUNC_IMPL(__imp__sub_822C89D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C89D8"))) PPC_WEAK_FUNC(sub_822C89D8);
PPC_FUNC_IMPL(__imp__sub_822C89D8) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,3528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822d52a0
	ctx.lr = 0x822C8A00;
	sub_822D52A0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8A20"))) PPC_WEAK_FUNC(sub_822C8A20);
PPC_FUNC_IMPL(__imp__sub_822C8A20) {
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
	// bl 0x822bf228
	ctx.lr = 0x822C8A38;
	sub_822BF228(ctx, base);
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

__attribute__((alias("__imp__sub_822C8A58"))) PPC_WEAK_FUNC(sub_822C8A58);
PPC_FUNC_IMPL(__imp__sub_822C8A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x822bfb70
	sub_822BFB70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8A74"))) PPC_WEAK_FUNC(sub_822C8A74);
PPC_FUNC_IMPL(__imp__sub_822C8A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8A78"))) PPC_WEAK_FUNC(sub_822C8A78);
PPC_FUNC_IMPL(__imp__sub_822C8A78) {
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
	// bl 0x822bfb50
	ctx.lr = 0x822C8A90;
	sub_822BFB50(ctx, base);
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

__attribute__((alias("__imp__sub_822C8AB0"))) PPC_WEAK_FUNC(sub_822C8AB0);
PPC_FUNC_IMPL(__imp__sub_822C8AB0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822c7fc8
	ctx.lr = 0x822C8AD4;
	sub_822C7FC8(ctx, base);
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

__attribute__((alias("__imp__sub_822C8AF4"))) PPC_WEAK_FUNC(sub_822C8AF4);
PPC_FUNC_IMPL(__imp__sub_822C8AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8AF8"))) PPC_WEAK_FUNC(sub_822C8AF8);
PPC_FUNC_IMPL(__imp__sub_822C8AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r9,21384
	r11.s64 = ctx.r9.s64 + 21384;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r10,r6,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// slw r4,r8,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r5.u8 & 0x3F));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// xor r10,r11,r3
	ctx.r10.u64 = r11.u64 ^ ctx.r3.u64;
	// and r9,r4,r10
	ctx.r9.u64 = ctx.r4.u64 & ctx.r10.u64;
	// and r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 & ctx.r3.u64;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8B4C"))) PPC_WEAK_FUNC(sub_822C8B4C);
PPC_FUNC_IMPL(__imp__sub_822C8B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8B50"))) PPC_WEAK_FUNC(sub_822C8B50);
PPC_FUNC_IMPL(__imp__sub_822C8B50) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822c8058
	ctx.lr = 0x822C8B70;
	sub_822C8058(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C8B8C"))) PPC_WEAK_FUNC(sub_822C8B8C);
PPC_FUNC_IMPL(__imp__sub_822C8B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8B90"))) PPC_WEAK_FUNC(sub_822C8B90);
PPC_FUNC_IMPL(__imp__sub_822C8B90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// b 0x8269c298
	sub_8269C298(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8BB0"))) PPC_WEAK_FUNC(sub_822C8BB0);
PPC_FUNC_IMPL(__imp__sub_822C8BB0) {
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
	// bl 0x8269c3d8
	ctx.lr = 0x822C8BC8;
	sub_8269C3D8(ctx, base);
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

__attribute__((alias("__imp__sub_822C8BE8"))) PPC_WEAK_FUNC(sub_822C8BE8);
PPC_FUNC_IMPL(__imp__sub_822C8BE8) {
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
	// bl 0x82388050
	ctx.lr = 0x822C8C00;
	sub_82388050(ctx, base);
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

__attribute__((alias("__imp__sub_822C8C20"))) PPC_WEAK_FUNC(sub_822C8C20);
PPC_FUNC_IMPL(__imp__sub_822C8C20) {
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
	// bl 0x82387d28
	ctx.lr = 0x822C8C38;
	sub_82387D28(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8C54"))) PPC_WEAK_FUNC(sub_822C8C54);
PPC_FUNC_IMPL(__imp__sub_822C8C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8C58"))) PPC_WEAK_FUNC(sub_822C8C58);
PPC_FUNC_IMPL(__imp__sub_822C8C58) {
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
	// bl 0x82387d70
	ctx.lr = 0x822C8C70;
	sub_82387D70(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8C8C"))) PPC_WEAK_FUNC(sub_822C8C8C);
PPC_FUNC_IMPL(__imp__sub_822C8C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8C90"))) PPC_WEAK_FUNC(sub_822C8C90);
PPC_FUNC_IMPL(__imp__sub_822C8C90) {
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
	// bl 0x82387db8
	ctx.lr = 0x822C8CA8;
	sub_82387DB8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8CC4"))) PPC_WEAK_FUNC(sub_822C8CC4);
PPC_FUNC_IMPL(__imp__sub_822C8CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8CC8"))) PPC_WEAK_FUNC(sub_822C8CC8);
PPC_FUNC_IMPL(__imp__sub_822C8CC8) {
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
	// bl 0x82387dd0
	ctx.lr = 0x822C8CE0;
	sub_82387DD0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8CFC"))) PPC_WEAK_FUNC(sub_822C8CFC);
PPC_FUNC_IMPL(__imp__sub_822C8CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8D00"))) PPC_WEAK_FUNC(sub_822C8D00);
PPC_FUNC_IMPL(__imp__sub_822C8D00) {
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
	// bl 0x823885b8
	ctx.lr = 0x822C8D18;
	sub_823885B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8D34"))) PPC_WEAK_FUNC(sub_822C8D34);
PPC_FUNC_IMPL(__imp__sub_822C8D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8D38"))) PPC_WEAK_FUNC(sub_822C8D38);
PPC_FUNC_IMPL(__imp__sub_822C8D38) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x82387e80
	ctx.lr = 0x822C8D50;
	sub_82387E80(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C8D6C"))) PPC_WEAK_FUNC(sub_822C8D6C);
PPC_FUNC_IMPL(__imp__sub_822C8D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8D70"))) PPC_WEAK_FUNC(sub_822C8D70);
PPC_FUNC_IMPL(__imp__sub_822C8D70) {
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
	// bl 0x823885f0
	ctx.lr = 0x822C8D88;
	sub_823885F0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8DA4"))) PPC_WEAK_FUNC(sub_822C8DA4);
PPC_FUNC_IMPL(__imp__sub_822C8DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8DA8"))) PPC_WEAK_FUNC(sub_822C8DA8);
PPC_FUNC_IMPL(__imp__sub_822C8DA8) {
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
	// bl 0x82387ec0
	ctx.lr = 0x822C8DC0;
	sub_82387EC0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8DDC"))) PPC_WEAK_FUNC(sub_822C8DDC);
PPC_FUNC_IMPL(__imp__sub_822C8DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8DE0"))) PPC_WEAK_FUNC(sub_822C8DE0);
PPC_FUNC_IMPL(__imp__sub_822C8DE0) {
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
	// bl 0x82388070
	ctx.lr = 0x822C8DF8;
	sub_82388070(ctx, base);
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

__attribute__((alias("__imp__sub_822C8E18"))) PPC_WEAK_FUNC(sub_822C8E18);
PPC_FUNC_IMPL(__imp__sub_822C8E18) {
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
	// bl 0x823880a0
	ctx.lr = 0x822C8E30;
	sub_823880A0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8E50"))) PPC_WEAK_FUNC(sub_822C8E50);
PPC_FUNC_IMPL(__imp__sub_822C8E50) {
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
	// bl 0x82387e38
	ctx.lr = 0x822C8E68;
	sub_82387E38(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8E84"))) PPC_WEAK_FUNC(sub_822C8E84);
PPC_FUNC_IMPL(__imp__sub_822C8E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8E88"))) PPC_WEAK_FUNC(sub_822C8E88);
PPC_FUNC_IMPL(__imp__sub_822C8E88) {
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
	// bl 0x823880c0
	ctx.lr = 0x822C8EA0;
	sub_823880C0(ctx, base);
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

__attribute__((alias("__imp__sub_822C8EC0"))) PPC_WEAK_FUNC(sub_822C8EC0);
PPC_FUNC_IMPL(__imp__sub_822C8EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r11,8109
	ctx.r9.s64 = r11.s64 + 8109;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C8ED8"))) PPC_WEAK_FUNC(sub_822C8ED8);
PPC_FUNC_IMPL(__imp__sub_822C8ED8) {
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
	// bl 0x82727e38
	ctx.lr = 0x822C8EF8;
	sub_82727E38(ctx, base);
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

__attribute__((alias("__imp__sub_822C8F18"))) PPC_WEAK_FUNC(sub_822C8F18);
PPC_FUNC_IMPL(__imp__sub_822C8F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82728138
	sub_82728138(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8F28"))) PPC_WEAK_FUNC(sub_822C8F28);
PPC_FUNC_IMPL(__imp__sub_822C8F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x827281a0
	sub_827281A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C8F34"))) PPC_WEAK_FUNC(sub_822C8F34);
PPC_FUNC_IMPL(__imp__sub_822C8F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8F38"))) PPC_WEAK_FUNC(sub_822C8F38);
PPC_FUNC_IMPL(__imp__sub_822C8F38) {
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
	// bl 0x827281d8
	ctx.lr = 0x822C8F50;
	sub_827281D8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8F6C"))) PPC_WEAK_FUNC(sub_822C8F6C);
PPC_FUNC_IMPL(__imp__sub_822C8F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8F70"))) PPC_WEAK_FUNC(sub_822C8F70);
PPC_FUNC_IMPL(__imp__sub_822C8F70) {
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
	// bl 0x82728228
	ctx.lr = 0x822C8F90;
	sub_82728228(ctx, base);
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

__attribute__((alias("__imp__sub_822C8FAC"))) PPC_WEAK_FUNC(sub_822C8FAC);
PPC_FUNC_IMPL(__imp__sub_822C8FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8FB0"))) PPC_WEAK_FUNC(sub_822C8FB0);
PPC_FUNC_IMPL(__imp__sub_822C8FB0) {
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
	// bl 0x822c75f8
	ctx.lr = 0x822C8FC8;
	sub_822C75F8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C8FE4"))) PPC_WEAK_FUNC(sub_822C8FE4);
PPC_FUNC_IMPL(__imp__sub_822C8FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C8FE8"))) PPC_WEAK_FUNC(sub_822C8FE8);
PPC_FUNC_IMPL(__imp__sub_822C8FE8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82388c48
	ctx.lr = 0x822C900C;
	sub_82388C48(ctx, base);
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

__attribute__((alias("__imp__sub_822C9028"))) PPC_WEAK_FUNC(sub_822C9028);
PPC_FUNC_IMPL(__imp__sub_822C9028) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389de8
	ctx.lr = 0x822C9050;
	sub_82389DE8(ctx, base);
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

__attribute__((alias("__imp__sub_822C906C"))) PPC_WEAK_FUNC(sub_822C906C);
PPC_FUNC_IMPL(__imp__sub_822C906C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9070"))) PPC_WEAK_FUNC(sub_822C9070);
PPC_FUNC_IMPL(__imp__sub_822C9070) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82388c60
	ctx.lr = 0x822C9094;
	sub_82388C60(ctx, base);
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

__attribute__((alias("__imp__sub_822C90B0"))) PPC_WEAK_FUNC(sub_822C90B0);
PPC_FUNC_IMPL(__imp__sub_822C90B0) {
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
	// bl 0x825c1da0
	ctx.lr = 0x822C90D0;
	sub_825C1DA0(ctx, base);
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

__attribute__((alias("__imp__sub_822C90EC"))) PPC_WEAK_FUNC(sub_822C90EC);
PPC_FUNC_IMPL(__imp__sub_822C90EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C90F0"))) PPC_WEAK_FUNC(sub_822C90F0);
PPC_FUNC_IMPL(__imp__sub_822C90F0) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823889c0
	ctx.lr = 0x822C9110;
	sub_823889C0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C912C"))) PPC_WEAK_FUNC(sub_822C912C);
PPC_FUNC_IMPL(__imp__sub_822C912C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9130"))) PPC_WEAK_FUNC(sub_822C9130);
PPC_FUNC_IMPL(__imp__sub_822C9130) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823889c8
	ctx.lr = 0x822C9150;
	sub_823889C8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C916C"))) PPC_WEAK_FUNC(sub_822C916C);
PPC_FUNC_IMPL(__imp__sub_822C916C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9170"))) PPC_WEAK_FUNC(sub_822C9170);
PPC_FUNC_IMPL(__imp__sub_822C9170) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823889d0
	ctx.lr = 0x822C9194;
	sub_823889D0(ctx, base);
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

__attribute__((alias("__imp__sub_822C91B0"))) PPC_WEAK_FUNC(sub_822C91B0);
PPC_FUNC_IMPL(__imp__sub_822C91B0) {
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
	// bl 0x8263b728
	ctx.lr = 0x822C91D0;
	sub_8263B728(ctx, base);
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

__attribute__((alias("__imp__sub_822C91EC"))) PPC_WEAK_FUNC(sub_822C91EC);
PPC_FUNC_IMPL(__imp__sub_822C91EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C91F0"))) PPC_WEAK_FUNC(sub_822C91F0);
PPC_FUNC_IMPL(__imp__sub_822C91F0) {
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
	// bl 0x823889e0
	ctx.lr = 0x822C9210;
	sub_823889E0(ctx, base);
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

__attribute__((alias("__imp__sub_822C922C"))) PPC_WEAK_FUNC(sub_822C922C);
PPC_FUNC_IMPL(__imp__sub_822C922C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9230"))) PPC_WEAK_FUNC(sub_822C9230);
PPC_FUNC_IMPL(__imp__sub_822C9230) {
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
	// bl 0x82618670
	ctx.lr = 0x822C9250;
	sub_82618670(ctx, base);
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

__attribute__((alias("__imp__sub_822C926C"))) PPC_WEAK_FUNC(sub_822C926C);
PPC_FUNC_IMPL(__imp__sub_822C926C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9270"))) PPC_WEAK_FUNC(sub_822C9270);
PPC_FUNC_IMPL(__imp__sub_822C9270) {
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
	// bl 0x823eaef8
	ctx.lr = 0x822C9290;
	sub_823EAEF8(ctx, base);
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

__attribute__((alias("__imp__sub_822C92AC"))) PPC_WEAK_FUNC(sub_822C92AC);
PPC_FUNC_IMPL(__imp__sub_822C92AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C92B0"))) PPC_WEAK_FUNC(sub_822C92B0);
PPC_FUNC_IMPL(__imp__sub_822C92B0) {
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
	// bl 0x823889f0
	ctx.lr = 0x822C92D0;
	sub_823889F0(ctx, base);
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

__attribute__((alias("__imp__sub_822C92EC"))) PPC_WEAK_FUNC(sub_822C92EC);
PPC_FUNC_IMPL(__imp__sub_822C92EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C92F0"))) PPC_WEAK_FUNC(sub_822C92F0);
PPC_FUNC_IMPL(__imp__sub_822C92F0) {
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
	// bl 0x82656bf8
	ctx.lr = 0x822C9310;
	sub_82656BF8(ctx, base);
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

__attribute__((alias("__imp__sub_822C932C"))) PPC_WEAK_FUNC(sub_822C932C);
PPC_FUNC_IMPL(__imp__sub_822C932C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9330"))) PPC_WEAK_FUNC(sub_822C9330);
PPC_FUNC_IMPL(__imp__sub_822C9330) {
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
	// bl 0x82388a08
	ctx.lr = 0x822C9350;
	sub_82388A08(ctx, base);
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

__attribute__((alias("__imp__sub_822C936C"))) PPC_WEAK_FUNC(sub_822C936C);
PPC_FUNC_IMPL(__imp__sub_822C936C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9370"))) PPC_WEAK_FUNC(sub_822C9370);
PPC_FUNC_IMPL(__imp__sub_822C9370) {
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
	// bl 0x82388a10
	ctx.lr = 0x822C9390;
	sub_82388A10(ctx, base);
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

__attribute__((alias("__imp__sub_822C93AC"))) PPC_WEAK_FUNC(sub_822C93AC);
PPC_FUNC_IMPL(__imp__sub_822C93AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C93B0"))) PPC_WEAK_FUNC(sub_822C93B0);
PPC_FUNC_IMPL(__imp__sub_822C93B0) {
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
	// bl 0x82388a28
	ctx.lr = 0x822C93D0;
	sub_82388A28(ctx, base);
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

__attribute__((alias("__imp__sub_822C93F0"))) PPC_WEAK_FUNC(sub_822C93F0);
PPC_FUNC_IMPL(__imp__sub_822C93F0) {
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
	// bl 0x82388a40
	ctx.lr = 0x822C9410;
	sub_82388A40(ctx, base);
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

__attribute__((alias("__imp__sub_822C9430"))) PPC_WEAK_FUNC(sub_822C9430);
PPC_FUNC_IMPL(__imp__sub_822C9430) {
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
	// bl 0x82496208
	ctx.lr = 0x822C9448;
	sub_82496208(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C9464"))) PPC_WEAK_FUNC(sub_822C9464);
PPC_FUNC_IMPL(__imp__sub_822C9464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9468"))) PPC_WEAK_FUNC(sub_822C9468);
PPC_FUNC_IMPL(__imp__sub_822C9468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273fbf8
	sub_8273FBF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9474"))) PPC_WEAK_FUNC(sub_822C9474);
PPC_FUNC_IMPL(__imp__sub_822C9474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9478"))) PPC_WEAK_FUNC(sub_822C9478);
PPC_FUNC_IMPL(__imp__sub_822C9478) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x8273fbd8
	ctx.lr = 0x822C94A4;
	sub_8273FBD8(ctx, base);
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

__attribute__((alias("__imp__sub_822C94C0"))) PPC_WEAK_FUNC(sub_822C94C0);
PPC_FUNC_IMPL(__imp__sub_822C94C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273eff8
	sub_8273EFF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C94CC"))) PPC_WEAK_FUNC(sub_822C94CC);
PPC_FUNC_IMPL(__imp__sub_822C94CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C94D0"))) PPC_WEAK_FUNC(sub_822C94D0);
PPC_FUNC_IMPL(__imp__sub_822C94D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273fbe0
	sub_8273FBE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C94E0"))) PPC_WEAK_FUNC(sub_822C94E0);
PPC_FUNC_IMPL(__imp__sub_822C94E0) {
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
	// bl 0x8273eff0
	ctx.lr = 0x822C9500;
	sub_8273EFF0(ctx, base);
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

__attribute__((alias("__imp__sub_822C951C"))) PPC_WEAK_FUNC(sub_822C951C);
PPC_FUNC_IMPL(__imp__sub_822C951C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9520"))) PPC_WEAK_FUNC(sub_822C9520);
PPC_FUNC_IMPL(__imp__sub_822C9520) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8273fbe8
	ctx.lr = 0x822C954C;
	sub_8273FBE8(ctx, base);
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

__attribute__((alias("__imp__sub_822C9568"))) PPC_WEAK_FUNC(sub_822C9568);
PPC_FUNC_IMPL(__imp__sub_822C9568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273fbf0
	sub_8273FBF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C957C"))) PPC_WEAK_FUNC(sub_822C957C);
PPC_FUNC_IMPL(__imp__sub_822C957C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9580"))) PPC_WEAK_FUNC(sub_822C9580);
PPC_FUNC_IMPL(__imp__sub_822C9580) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8273ef48
	ctx.lr = 0x822C95A4;
	sub_8273EF48(ctx, base);
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

__attribute__((alias("__imp__sub_822C95C0"))) PPC_WEAK_FUNC(sub_822C95C0);
PPC_FUNC_IMPL(__imp__sub_822C95C0) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8273ef60
	ctx.lr = 0x822C95E4;
	sub_8273EF60(ctx, base);
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

__attribute__((alias("__imp__sub_822C9604"))) PPC_WEAK_FUNC(sub_822C9604);
PPC_FUNC_IMPL(__imp__sub_822C9604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9608"))) PPC_WEAK_FUNC(sub_822C9608);
PPC_FUNC_IMPL(__imp__sub_822C9608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// b 0x8273ef70
	sub_8273EF70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C962C"))) PPC_WEAK_FUNC(sub_822C962C);
PPC_FUNC_IMPL(__imp__sub_822C962C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9630"))) PPC_WEAK_FUNC(sub_822C9630);
PPC_FUNC_IMPL(__imp__sub_822C9630) {
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
	// bl 0x8273ef80
	ctx.lr = 0x822C9650;
	sub_8273EF80(ctx, base);
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

__attribute__((alias("__imp__sub_822C966C"))) PPC_WEAK_FUNC(sub_822C966C);
PPC_FUNC_IMPL(__imp__sub_822C966C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9670"))) PPC_WEAK_FUNC(sub_822C9670);
PPC_FUNC_IMPL(__imp__sub_822C9670) {
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
	// bl 0x824e6270
	ctx.lr = 0x822C9690;
	sub_824E6270(ctx, base);
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

__attribute__((alias("__imp__sub_822C96AC"))) PPC_WEAK_FUNC(sub_822C96AC);
PPC_FUNC_IMPL(__imp__sub_822C96AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C96B0"))) PPC_WEAK_FUNC(sub_822C96B0);
PPC_FUNC_IMPL(__imp__sub_822C96B0) {
	PPC_FUNC_PROLOGUE();
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
	// b 0x8247a8d0
	sub_8247A8D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C96C4"))) PPC_WEAK_FUNC(sub_822C96C4);
PPC_FUNC_IMPL(__imp__sub_822C96C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C96C8"))) PPC_WEAK_FUNC(sub_822C96C8);
PPC_FUNC_IMPL(__imp__sub_822C96C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stwx r5,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, ctx.r5.u32);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f11,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r8,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r8.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C9794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822C97B0"))) PPC_WEAK_FUNC(sub_822C97B0);
PPC_FUNC_IMPL(__imp__sub_822C97B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stwx r6,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lfs f1,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9828"))) PPC_WEAK_FUNC(sub_822C9828);
PPC_FUNC_IMPL(__imp__sub_822C9828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stwx r8,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r8.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// lwz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cntlzw r8,r5
	ctx.r8.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lfs f1,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C98B8"))) PPC_WEAK_FUNC(sub_822C98B8);
PPC_FUNC_IMPL(__imp__sub_822C98B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r3,r7
	ctx.r3.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r3,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r8,r5,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// xori r6,r8,1
	ctx.r6.u64 = ctx.r8.u64 ^ 1;
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9948"))) PPC_WEAK_FUNC(sub_822C9948);
PPC_FUNC_IMPL(__imp__sub_822C9948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stwx r3,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r3.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r6,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r6.u32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,2
	r11.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cntlzw r9,r6
	ctx.r9.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r10,r5
	ctx.r10.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r6,r5,24
	ctx.r6.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9A2C"))) PPC_WEAK_FUNC(sub_822C9A2C);
PPC_FUNC_IMPL(__imp__sub_822C9A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9A30"))) PPC_WEAK_FUNC(sub_822C9A30);
PPC_FUNC_IMPL(__imp__sub_822C9A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stwx r3,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r3.u32);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// addi r7,r11,4
	ctx.r7.s64 = r11.s64 + 4;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r6,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r6.u32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r10,2
	r11.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f10,8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r5,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f1,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f3,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// lfs f2,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9B0C"))) PPC_WEAK_FUNC(sub_822C9B0C);
PPC_FUNC_IMPL(__imp__sub_822C9B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9B10"))) PPC_WEAK_FUNC(sub_822C9B10);
PPC_FUNC_IMPL(__imp__sub_822C9B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r5,r11
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lwz r6,12(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822C9B88"))) PPC_WEAK_FUNC(sub_822C9B88);
PPC_FUNC_IMPL(__imp__sub_822C9B88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C9C04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C9C20"))) PPC_WEAK_FUNC(sub_822C9C20);
PPC_FUNC_IMPL(__imp__sub_822C9C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32212
	r11.s64 = -2111045632;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,32336
	ctx.r3.s64 = r11.s64 + 32336;
	// b 0x822c96c8
	sub_822C96C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9C30"))) PPC_WEAK_FUNC(sub_822C9C30);
PPC_FUNC_IMPL(__imp__sub_822C9C30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c9c74
	if (!cr6.eq) goto loc_822C9C74;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c9c5c
	if (cr6.eq) goto loc_822C9C5C;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822c9c60
	if (!cr6.eq) goto loc_822C9C60;
loc_822C9C5C:
	// li r11,1
	r11.s64 = 1;
loc_822C9C60:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822C9C74:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822c9c98
	if (cr6.eq) goto loc_822C9C98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822c9c74
	if (cr6.eq) goto loc_822C9C74;
loc_822C9C98:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C9CB0"))) PPC_WEAK_FUNC(sub_822C9CB0);
PPC_FUNC_IMPL(__imp__sub_822C9CB0) {
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
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822c9cfc
	if (!cr6.eq) goto loc_822C9CFC;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822c9cf0
	if (cr6.eq) goto loc_822C9CF0;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822c9cf4
	if (!cr6.eq) goto loc_822C9CF4;
loc_822C9CF0:
	// li r11,1
	r11.s64 = 1;
loc_822C9CF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x822c9d08
	goto loc_822C9D08;
loc_822C9CFC:
	// bl 0x823db730
	ctx.lr = 0x822C9D00;
	sub_823DB730(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_822C9D08:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_822C9D28"))) PPC_WEAK_FUNC(sub_822C9D28);
PPC_FUNC_IMPL(__imp__sub_822C9D28) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822c7eb8
	ctx.lr = 0x822C9D4C;
	sub_822C7EB8(ctx, base);
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

__attribute__((alias("__imp__sub_822C9D6C"))) PPC_WEAK_FUNC(sub_822C9D6C);
PPC_FUNC_IMPL(__imp__sub_822C9D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9D70"))) PPC_WEAK_FUNC(sub_822C9D70);
PPC_FUNC_IMPL(__imp__sub_822C9D70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_822C9D84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c9d84
	if (!cr6.eq) goto loc_822C9D84;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_822C9D98:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x822c9d98
	if (!cr6.eq) goto loc_822C9D98;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C9DB4"))) PPC_WEAK_FUNC(sub_822C9DB4);
PPC_FUNC_IMPL(__imp__sub_822C9DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9DB8"))) PPC_WEAK_FUNC(sub_822C9DB8);
PPC_FUNC_IMPL(__imp__sub_822C9DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-18344
	ctx.r3.s64 = r11.s64 + -18344;
	// b 0x822c97b0
	sub_822C97B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DC8"))) PPC_WEAK_FUNC(sub_822C9DC8);
PPC_FUNC_IMPL(__imp__sub_822C9DC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-18240
	ctx.r3.s64 = r11.s64 + -18240;
	// b 0x822c9828
	sub_822C9828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DD8"))) PPC_WEAK_FUNC(sub_822C9DD8);
PPC_FUNC_IMPL(__imp__sub_822C9DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822c7568
	sub_822C7568(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DE4"))) PPC_WEAK_FUNC(sub_822C9DE4);
PPC_FUNC_IMPL(__imp__sub_822C9DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9DE8"))) PPC_WEAK_FUNC(sub_822C9DE8);
PPC_FUNC_IMPL(__imp__sub_822C9DE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822d39d0
	sub_822D39D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9DF4"))) PPC_WEAK_FUNC(sub_822C9DF4);
PPC_FUNC_IMPL(__imp__sub_822C9DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9DF8"))) PPC_WEAK_FUNC(sub_822C9DF8);
PPC_FUNC_IMPL(__imp__sub_822C9DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-32488
	ctx.r3.s64 = r11.s64 + -32488;
	// b 0x822c98b8
	sub_822C98B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9E08"))) PPC_WEAK_FUNC(sub_822C9E08);
PPC_FUNC_IMPL(__imp__sub_822C9E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-32272
	ctx.r3.s64 = r11.s64 + -32272;
	// b 0x822c9948
	sub_822C9948(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9E18"))) PPC_WEAK_FUNC(sub_822C9E18);
PPC_FUNC_IMPL(__imp__sub_822C9E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32212
	r11.s64 = -2111045632;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-1112
	ctx.r3.s64 = r11.s64 + -1112;
	// b 0x822c9a30
	sub_822C9A30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9E28"))) PPC_WEAK_FUNC(sub_822C9E28);
PPC_FUNC_IMPL(__imp__sub_822C9E28) {
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
	// bl 0x8238ec00
	ctx.lr = 0x822C9E48;
	sub_8238EC00(ctx, base);
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

__attribute__((alias("__imp__sub_822C9E64"))) PPC_WEAK_FUNC(sub_822C9E64);
PPC_FUNC_IMPL(__imp__sub_822C9E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9E68"))) PPC_WEAK_FUNC(sub_822C9E68);
PPC_FUNC_IMPL(__imp__sub_822C9E68) {
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
	// bl 0x82396408
	ctx.lr = 0x822C9E88;
	sub_82396408(ctx, base);
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

__attribute__((alias("__imp__sub_822C9EA4"))) PPC_WEAK_FUNC(sub_822C9EA4);
PPC_FUNC_IMPL(__imp__sub_822C9EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9EA8"))) PPC_WEAK_FUNC(sub_822C9EA8);
PPC_FUNC_IMPL(__imp__sub_822C9EA8) {
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
	// bl 0x82397018
	ctx.lr = 0x822C9EC8;
	sub_82397018(ctx, base);
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

__attribute__((alias("__imp__sub_822C9EE4"))) PPC_WEAK_FUNC(sub_822C9EE4);
PPC_FUNC_IMPL(__imp__sub_822C9EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9EE8"))) PPC_WEAK_FUNC(sub_822C9EE8);
PPC_FUNC_IMPL(__imp__sub_822C9EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r7,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82388908
	sub_82388908(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9F54"))) PPC_WEAK_FUNC(sub_822C9F54);
PPC_FUNC_IMPL(__imp__sub_822C9F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C9F58"))) PPC_WEAK_FUNC(sub_822C9F58);
PPC_FUNC_IMPL(__imp__sub_822C9F58) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389800
	ctx.lr = 0x822C9F7C;
	sub_82389800(ctx, base);
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

__attribute__((alias("__imp__sub_822C9F98"))) PPC_WEAK_FUNC(sub_822C9F98);
PPC_FUNC_IMPL(__imp__sub_822C9F98) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389880
	ctx.lr = 0x822C9FBC;
	sub_82389880(ctx, base);
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

__attribute__((alias("__imp__sub_822C9FD8"))) PPC_WEAK_FUNC(sub_822C9FD8);
PPC_FUNC_IMPL(__imp__sub_822C9FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32199
	r11.s64 = -2110193664;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-29560
	ctx.r3.s64 = r11.s64 + -29560;
	// b 0x822c9b10
	sub_822C9B10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C9FE8"))) PPC_WEAK_FUNC(sub_822C9FE8);
PPC_FUNC_IMPL(__imp__sub_822C9FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r4,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r4.u32);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823889b0
	sub_823889B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CA04C"))) PPC_WEAK_FUNC(sub_822CA04C);
PPC_FUNC_IMPL(__imp__sub_822CA04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA050"))) PPC_WEAK_FUNC(sub_822CA050);
PPC_FUNC_IMPL(__imp__sub_822CA050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8273f218
	sub_8273F218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CA064"))) PPC_WEAK_FUNC(sub_822CA064);
PPC_FUNC_IMPL(__imp__sub_822CA064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA068"))) PPC_WEAK_FUNC(sub_822CA068);
PPC_FUNC_IMPL(__imp__sub_822CA068) {
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
	// bl 0x82387bc0
	ctx.lr = 0x822CA088;
	sub_82387BC0(ctx, base);
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

__attribute__((alias("__imp__sub_822CA0A4"))) PPC_WEAK_FUNC(sub_822CA0A4);
PPC_FUNC_IMPL(__imp__sub_822CA0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA0A8"))) PPC_WEAK_FUNC(sub_822CA0A8);
PPC_FUNC_IMPL(__imp__sub_822CA0A8) {
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
	// bl 0x82387c08
	ctx.lr = 0x822CA0C8;
	sub_82387C08(ctx, base);
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

__attribute__((alias("__imp__sub_822CA0E4"))) PPC_WEAK_FUNC(sub_822CA0E4);
PPC_FUNC_IMPL(__imp__sub_822CA0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA0E8"))) PPC_WEAK_FUNC(sub_822CA0E8);
PPC_FUNC_IMPL(__imp__sub_822CA0E8) {
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
	// bl 0x82387c50
	ctx.lr = 0x822CA108;
	sub_82387C50(ctx, base);
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

__attribute__((alias("__imp__sub_822CA124"))) PPC_WEAK_FUNC(sub_822CA124);
PPC_FUNC_IMPL(__imp__sub_822CA124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA128"))) PPC_WEAK_FUNC(sub_822CA128);
PPC_FUNC_IMPL(__imp__sub_822CA128) {
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
	// bl 0x82387c98
	ctx.lr = 0x822CA148;
	sub_82387C98(ctx, base);
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

__attribute__((alias("__imp__sub_822CA164"))) PPC_WEAK_FUNC(sub_822CA164);
PPC_FUNC_IMPL(__imp__sub_822CA164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA168"))) PPC_WEAK_FUNC(sub_822CA168);
PPC_FUNC_IMPL(__imp__sub_822CA168) {
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
	// bl 0x82387ce0
	ctx.lr = 0x822CA188;
	sub_82387CE0(ctx, base);
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

__attribute__((alias("__imp__sub_822CA1A4"))) PPC_WEAK_FUNC(sub_822CA1A4);
PPC_FUNC_IMPL(__imp__sub_822CA1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822CA1A8"))) PPC_WEAK_FUNC(sub_822CA1A8);
PPC_FUNC_IMPL(__imp__sub_822CA1A8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82387ef8
	ctx.lr = 0x822CA1CC;
	sub_82387EF8(ctx, base);
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

__attribute__((alias("__imp__sub_822CA1E8"))) PPC_WEAK_FUNC(sub_822CA1E8);
PPC_FUNC_IMPL(__imp__sub_822CA1E8) {
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
	// bl 0x82388090
	ctx.lr = 0x822CA208;
	sub_82388090(ctx, base);
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

__attribute__((alias("__imp__sub_822CA228"))) PPC_WEAK_FUNC(sub_822CA228);
PPC_FUNC_IMPL(__imp__sub_822CA228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32211
	r11.s64 = -2110980096;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-31320
	ctx.r3.s64 = r11.s64 + -31320;
	// b 0x822c9b88
	sub_822C9B88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822CA238"))) PPC_WEAK_FUNC(sub_822CA238);
PPC_FUNC_IMPL(__imp__sub_822CA238) {
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
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-31208
	ctx.r4.s64 = r11.s64 + -31208;
	// addi r3,r10,-20804
	ctx.r3.s64 = ctx.r10.s64 + -20804;
	// bl 0x82554798
	ctx.lr = 0x822CA258;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-31104
	ctx.r4.s64 = ctx.r9.s64 + -31104;
	// addi r3,r8,-20820
	ctx.r3.s64 = ctx.r8.s64 + -20820;
	// bl 0x82554798
	ctx.lr = 0x822CA26C;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-31040
	ctx.r4.s64 = ctx.r7.s64 + -31040;
	// addi r3,r6,-20836
	ctx.r3.s64 = ctx.r6.s64 + -20836;
	// bl 0x82554798
	ctx.lr = 0x822CA280;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30976
	ctx.r4.s64 = ctx.r5.s64 + -30976;
	// addi r3,r3,-20856
	ctx.r3.s64 = ctx.r3.s64 + -20856;
	// bl 0x82554798
	ctx.lr = 0x822CA294;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30912
	ctx.r4.s64 = r11.s64 + -30912;
	// addi r3,r10,-20884
	ctx.r3.s64 = ctx.r10.s64 + -20884;
	// bl 0x82554798
	ctx.lr = 0x822CA2A8;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30840
	ctx.r4.s64 = ctx.r9.s64 + -30840;
	// addi r3,r8,-20904
	ctx.r3.s64 = ctx.r8.s64 + -20904;
	// bl 0x82554798
	ctx.lr = 0x822CA2BC;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30736
	ctx.r4.s64 = ctx.r7.s64 + -30736;
	// addi r3,r6,-20928
	ctx.r3.s64 = ctx.r6.s64 + -20928;
	// bl 0x82554798
	ctx.lr = 0x822CA2D0;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25568
	ctx.r4.s64 = ctx.r5.s64 + -25568;
	// addi r3,r3,-20940
	ctx.r3.s64 = ctx.r3.s64 + -20940;
	// bl 0x82554798
	ctx.lr = 0x822CA2E4;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-25552
	ctx.r4.s64 = r11.s64 + -25552;
	// addi r3,r10,-20956
	ctx.r3.s64 = ctx.r10.s64 + -20956;
	// bl 0x82554798
	ctx.lr = 0x822CA2F8;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-25424
	ctx.r4.s64 = ctx.r9.s64 + -25424;
	// addi r3,r8,-20976
	ctx.r3.s64 = ctx.r8.s64 + -20976;
	// bl 0x82554798
	ctx.lr = 0x822CA30C;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-25304
	ctx.r4.s64 = ctx.r7.s64 + -25304;
	// addi r3,r6,-20996
	ctx.r3.s64 = ctx.r6.s64 + -20996;
	// bl 0x82554798
	ctx.lr = 0x822CA320;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25232
	ctx.r4.s64 = ctx.r5.s64 + -25232;
	// addi r3,r3,-21008
	ctx.r3.s64 = ctx.r3.s64 + -21008;
	// bl 0x82554798
	ctx.lr = 0x822CA334;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30640
	ctx.r4.s64 = r11.s64 + -30640;
	// addi r3,r10,-21032
	ctx.r3.s64 = ctx.r10.s64 + -21032;
	// bl 0x82554798
	ctx.lr = 0x822CA348;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30576
	ctx.r4.s64 = ctx.r9.s64 + -30576;
	// addi r3,r8,-21052
	ctx.r3.s64 = ctx.r8.s64 + -21052;
	// bl 0x82554798
	ctx.lr = 0x822CA35C;
	sub_82554798(ctx, base);
	// bl 0x8238ce90
	ctx.lr = 0x822CA360;
	sub_8238CE90(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28992
	ctx.r4.s64 = ctx.r7.s64 + -28992;
	// addi r3,r6,-21084
	ctx.r3.s64 = ctx.r6.s64 + -21084;
	// bl 0x82554798
	ctx.lr = 0x822CA374;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28968
	ctx.r4.s64 = ctx.r5.s64 + -28968;
	// addi r3,r3,-21100
	ctx.r3.s64 = ctx.r3.s64 + -21100;
	// bl 0x82554798
	ctx.lr = 0x822CA388;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28904
	ctx.r4.s64 = r11.s64 + -28904;
	// addi r3,r10,-21124
	ctx.r3.s64 = ctx.r10.s64 + -21124;
	// bl 0x82554798
	ctx.lr = 0x822CA39C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30520
	ctx.r4.s64 = ctx.r9.s64 + -30520;
	// addi r3,r8,-21140
	ctx.r3.s64 = ctx.r8.s64 + -21140;
	// bl 0x82554798
	ctx.lr = 0x822CA3B0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30504
	ctx.r4.s64 = ctx.r7.s64 + -30504;
	// addi r3,r6,-21160
	ctx.r3.s64 = ctx.r6.s64 + -21160;
	// bl 0x82554798
	ctx.lr = 0x822CA3C4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30488
	ctx.r4.s64 = ctx.r5.s64 + -30488;
	// addi r3,r3,-21188
	ctx.r3.s64 = ctx.r3.s64 + -21188;
	// bl 0x82554798
	ctx.lr = 0x822CA3D8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30472
	ctx.r4.s64 = r11.s64 + -30472;
	// addi r3,r10,-21204
	ctx.r3.s64 = ctx.r10.s64 + -21204;
	// bl 0x82554798
	ctx.lr = 0x822CA3EC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28888
	ctx.r4.s64 = ctx.r9.s64 + -28888;
	// addi r3,r8,-21216
	ctx.r3.s64 = ctx.r8.s64 + -21216;
	// bl 0x82554798
	ctx.lr = 0x822CA400;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28872
	ctx.r4.s64 = ctx.r7.s64 + -28872;
	// addi r3,r6,-21232
	ctx.r3.s64 = ctx.r6.s64 + -21232;
	// bl 0x82554798
	ctx.lr = 0x822CA414;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28816
	ctx.r4.s64 = ctx.r5.s64 + -28816;
	// addi r3,r3,-21252
	ctx.r3.s64 = ctx.r3.s64 + -21252;
	// bl 0x82554798
	ctx.lr = 0x822CA428;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-25160
	ctx.r4.s64 = r11.s64 + -25160;
	// addi r3,r10,-21276
	ctx.r3.s64 = ctx.r10.s64 + -21276;
	// bl 0x82554798
	ctx.lr = 0x822CA43C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30416
	ctx.r4.s64 = ctx.r9.s64 + -30416;
	// addi r3,r8,-21300
	ctx.r3.s64 = ctx.r8.s64 + -21300;
	// bl 0x82554798
	ctx.lr = 0x822CA450;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-25144
	ctx.r4.s64 = ctx.r7.s64 + -25144;
	// addi r3,r6,-21332
	ctx.r3.s64 = ctx.r6.s64 + -21332;
	// bl 0x82554798
	ctx.lr = 0x822CA464;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25128
	ctx.r4.s64 = ctx.r5.s64 + -25128;
	// addi r3,r3,-21352
	ctx.r3.s64 = ctx.r3.s64 + -21352;
	// bl 0x82554798
	ctx.lr = 0x822CA478;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32072
	ctx.r4.s64 = r11.s64 + -32072;
	// addi r3,r10,-21376
	ctx.r3.s64 = ctx.r10.s64 + -21376;
	// bl 0x82554798
	ctx.lr = 0x822CA48C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-25112
	ctx.r4.s64 = ctx.r9.s64 + -25112;
	// addi r3,r8,-21404
	ctx.r3.s64 = ctx.r8.s64 + -21404;
	// bl 0x82554798
	ctx.lr = 0x822CA4A0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-32064
	ctx.r4.s64 = ctx.r7.s64 + -32064;
	// addi r3,r6,-21436
	ctx.r3.s64 = ctx.r6.s64 + -21436;
	// bl 0x82554798
	ctx.lr = 0x822CA4B4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25096
	ctx.r4.s64 = ctx.r5.s64 + -25096;
	// addi r3,r3,-21464
	ctx.r3.s64 = ctx.r3.s64 + -21464;
	// bl 0x82554798
	ctx.lr = 0x822CA4C8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-25080
	ctx.r4.s64 = r11.s64 + -25080;
	// addi r3,r10,-21496
	ctx.r3.s64 = ctx.r10.s64 + -21496;
	// bl 0x82554798
	ctx.lr = 0x822CA4DC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30400
	ctx.r4.s64 = ctx.r9.s64 + -30400;
	// addi r3,r8,-21528
	ctx.r3.s64 = ctx.r8.s64 + -21528;
	// bl 0x82554798
	ctx.lr = 0x822CA4F0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30368
	ctx.r4.s64 = ctx.r7.s64 + -30368;
	// addi r3,r6,-21560
	ctx.r3.s64 = ctx.r6.s64 + -21560;
	// bl 0x82554798
	ctx.lr = 0x822CA504;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30328
	ctx.r4.s64 = ctx.r5.s64 + -30328;
	// addi r3,r3,-21584
	ctx.r3.s64 = ctx.r3.s64 + -21584;
	// bl 0x82554798
	ctx.lr = 0x822CA518;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30280
	ctx.r4.s64 = r11.s64 + -30280;
	// addi r3,r10,-21612
	ctx.r3.s64 = ctx.r10.s64 + -21612;
	// bl 0x82554798
	ctx.lr = 0x822CA52C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30248
	ctx.r4.s64 = ctx.r9.s64 + -30248;
	// addi r3,r8,-21632
	ctx.r3.s64 = ctx.r8.s64 + -21632;
	// bl 0x82554798
	ctx.lr = 0x822CA540;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-32056
	ctx.r4.s64 = ctx.r7.s64 + -32056;
	// addi r3,r6,-21652
	ctx.r3.s64 = ctx.r6.s64 + -21652;
	// bl 0x82554798
	ctx.lr = 0x822CA554;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25064
	ctx.r4.s64 = ctx.r5.s64 + -25064;
	// addi r3,r3,-21668
	ctx.r3.s64 = ctx.r3.s64 + -21668;
	// bl 0x82554798
	ctx.lr = 0x822CA568;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30176
	ctx.r4.s64 = r11.s64 + -30176;
	// addi r3,r10,-21684
	ctx.r3.s64 = ctx.r10.s64 + -21684;
	// bl 0x82554798
	ctx.lr = 0x822CA57C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-32048
	ctx.r4.s64 = ctx.r9.s64 + -32048;
	// addi r3,r8,-21704
	ctx.r3.s64 = ctx.r8.s64 + -21704;
	// bl 0x82554798
	ctx.lr = 0x822CA590;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30120
	ctx.r4.s64 = ctx.r7.s64 + -30120;
	// addi r3,r6,-21728
	ctx.r3.s64 = ctx.r6.s64 + -21728;
	// bl 0x82554798
	ctx.lr = 0x822CA5A4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30088
	ctx.r4.s64 = ctx.r5.s64 + -30088;
	// addi r3,r3,-21748
	ctx.r3.s64 = ctx.r3.s64 + -21748;
	// bl 0x82554798
	ctx.lr = 0x822CA5B8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32040
	ctx.r4.s64 = r11.s64 + -32040;
	// addi r3,r10,-21772
	ctx.r3.s64 = ctx.r10.s64 + -21772;
	// bl 0x82554798
	ctx.lr = 0x822CA5CC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30032
	ctx.r4.s64 = ctx.r9.s64 + -30032;
	// addi r3,r8,-21788
	ctx.r3.s64 = ctx.r8.s64 + -21788;
	// bl 0x82554798
	ctx.lr = 0x822CA5E0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29960
	ctx.r4.s64 = ctx.r7.s64 + -29960;
	// addi r3,r6,-21808
	ctx.r3.s64 = ctx.r6.s64 + -21808;
	// bl 0x82554798
	ctx.lr = 0x822CA5F4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29872
	ctx.r4.s64 = ctx.r5.s64 + -29872;
	// addi r3,r3,-21832
	ctx.r3.s64 = ctx.r3.s64 + -21832;
	// bl 0x82554798
	ctx.lr = 0x822CA608;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// addi r4,r11,-32032
	ctx.r4.s64 = r11.s64 + -32032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-21864
	ctx.r3.s64 = ctx.r10.s64 + -21864;
	// bl 0x82554798
	ctx.lr = 0x822CA61C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-32024
	ctx.r4.s64 = ctx.r9.s64 + -32024;
	// addi r3,r8,-21900
	ctx.r3.s64 = ctx.r8.s64 + -21900;
	// bl 0x82554798
	ctx.lr = 0x822CA630;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-32016
	ctx.r4.s64 = ctx.r7.s64 + -32016;
	// addi r3,r6,-21928
	ctx.r3.s64 = ctx.r6.s64 + -21928;
	// bl 0x82554798
	ctx.lr = 0x822CA644;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-32008
	ctx.r4.s64 = ctx.r5.s64 + -32008;
	// addi r3,r3,-21960
	ctx.r3.s64 = ctx.r3.s64 + -21960;
	// bl 0x82554798
	ctx.lr = 0x822CA658;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32000
	ctx.r4.s64 = r11.s64 + -32000;
	// addi r3,r10,-21992
	ctx.r3.s64 = ctx.r10.s64 + -21992;
	// bl 0x82554798
	ctx.lr = 0x822CA66C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-31992
	ctx.r4.s64 = ctx.r9.s64 + -31992;
	// addi r3,r8,-22024
	ctx.r3.s64 = ctx.r8.s64 + -22024;
	// bl 0x82554798
	ctx.lr = 0x822CA680;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-31984
	ctx.r4.s64 = ctx.r7.s64 + -31984;
	// addi r3,r6,-22064
	ctx.r3.s64 = ctx.r6.s64 + -22064;
	// bl 0x82554798
	ctx.lr = 0x822CA694;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29808
	ctx.r4.s64 = ctx.r5.s64 + -29808;
	// addi r3,r3,-22100
	ctx.r3.s64 = ctx.r3.s64 + -22100;
	// bl 0x82554798
	ctx.lr = 0x822CA6A8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29776
	ctx.r4.s64 = r11.s64 + -29776;
	// addi r3,r10,-22124
	ctx.r3.s64 = ctx.r10.s64 + -22124;
	// bl 0x82554798
	ctx.lr = 0x822CA6BC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-31976
	ctx.r4.s64 = ctx.r9.s64 + -31976;
	// addi r3,r8,-22140
	ctx.r3.s64 = ctx.r8.s64 + -22140;
	// bl 0x82554798
	ctx.lr = 0x822CA6D0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28752
	ctx.r4.s64 = ctx.r7.s64 + -28752;
	// addi r3,r6,-22156
	ctx.r3.s64 = ctx.r6.s64 + -22156;
	// bl 0x82554798
	ctx.lr = 0x822CA6E4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25048
	ctx.r4.s64 = ctx.r5.s64 + -25048;
	// addi r3,r3,-22168
	ctx.r3.s64 = ctx.r3.s64 + -22168;
	// bl 0x82554798
	ctx.lr = 0x822CA6F8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-24984
	ctx.r4.s64 = r11.s64 + -24984;
	// addi r3,r10,-22180
	ctx.r3.s64 = ctx.r10.s64 + -22180;
	// bl 0x82554798
	ctx.lr = 0x822CA70C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-24920
	ctx.r4.s64 = ctx.r9.s64 + -24920;
	// addi r3,r8,-22196
	ctx.r3.s64 = ctx.r8.s64 + -22196;
	// bl 0x82554798
	ctx.lr = 0x822CA720;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24856
	ctx.r4.s64 = ctx.r7.s64 + -24856;
	// addi r3,r6,-22236
	ctx.r3.s64 = ctx.r6.s64 + -22236;
	// bl 0x82554798
	ctx.lr = 0x822CA734;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24744
	ctx.r4.s64 = ctx.r5.s64 + -24744;
	// addi r3,r3,-22264
	ctx.r3.s64 = ctx.r3.s64 + -22264;
	// bl 0x82554798
	ctx.lr = 0x822CA748;
	sub_82554798(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r3,r11,-22300
	ctx.r3.s64 = r11.s64 + -22300;
	// addi r4,r10,-28696
	ctx.r4.s64 = ctx.r10.s64 + -28696;
	// bl 0x82554798
	ctx.lr = 0x822CA75C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28632
	ctx.r4.s64 = ctx.r9.s64 + -28632;
	// addi r3,r8,-22340
	ctx.r3.s64 = ctx.r8.s64 + -22340;
	// bl 0x82554798
	ctx.lr = 0x822CA770;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24680
	ctx.r4.s64 = ctx.r7.s64 + -24680;
	// addi r3,r6,-22376
	ctx.r3.s64 = ctx.r6.s64 + -22376;
	// bl 0x82554798
	ctx.lr = 0x822CA784;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28560
	ctx.r4.s64 = ctx.r5.s64 + -28560;
	// addi r3,r3,-22412
	ctx.r3.s64 = ctx.r3.s64 + -22412;
	// bl 0x82554798
	ctx.lr = 0x822CA798;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28496
	ctx.r4.s64 = r11.s64 + -28496;
	// addi r3,r10,-22448
	ctx.r3.s64 = ctx.r10.s64 + -22448;
	// bl 0x82554798
	ctx.lr = 0x822CA7AC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-24616
	ctx.r4.s64 = ctx.r9.s64 + -24616;
	// addi r3,r8,-22480
	ctx.r3.s64 = ctx.r8.s64 + -22480;
	// bl 0x82554798
	ctx.lr = 0x822CA7C0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24600
	ctx.r4.s64 = ctx.r7.s64 + -24600;
	// addi r3,r6,-22520
	ctx.r3.s64 = ctx.r6.s64 + -22520;
	// bl 0x82554798
	ctx.lr = 0x822CA7D4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28432
	ctx.r4.s64 = ctx.r5.s64 + -28432;
	// addi r3,r3,-22556
	ctx.r3.s64 = ctx.r3.s64 + -22556;
	// bl 0x82554798
	ctx.lr = 0x822CA7E8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28368
	ctx.r4.s64 = r11.s64 + -28368;
	// addi r3,r10,-22592
	ctx.r3.s64 = ctx.r10.s64 + -22592;
	// bl 0x82554798
	ctx.lr = 0x822CA7FC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28304
	ctx.r4.s64 = ctx.r9.s64 + -28304;
	// addi r3,r8,-22624
	ctx.r3.s64 = ctx.r8.s64 + -22624;
	// bl 0x82554798
	ctx.lr = 0x822CA810;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28240
	ctx.r4.s64 = ctx.r7.s64 + -28240;
	// addi r3,r6,-22656
	ctx.r3.s64 = ctx.r6.s64 + -22656;
	// bl 0x82554798
	ctx.lr = 0x822CA824;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-28176
	ctx.r4.s64 = ctx.r5.s64 + -28176;
	// addi r3,r3,-22692
	ctx.r3.s64 = ctx.r3.s64 + -22692;
	// bl 0x82554798
	ctx.lr = 0x822CA838;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28112
	ctx.r4.s64 = r11.s64 + -28112;
	// addi r3,r10,-22720
	ctx.r3.s64 = ctx.r10.s64 + -22720;
	// bl 0x82554798
	ctx.lr = 0x822CA84C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28048
	ctx.r4.s64 = ctx.r9.s64 + -28048;
	// addi r3,r8,-22752
	ctx.r3.s64 = ctx.r8.s64 + -22752;
	// bl 0x82554798
	ctx.lr = 0x822CA860;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27984
	ctx.r4.s64 = ctx.r7.s64 + -27984;
	// addi r3,r6,-22784
	ctx.r3.s64 = ctx.r6.s64 + -22784;
	// bl 0x82554798
	ctx.lr = 0x822CA874;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27920
	ctx.r4.s64 = ctx.r5.s64 + -27920;
	// addi r3,r3,-22816
	ctx.r3.s64 = ctx.r3.s64 + -22816;
	// bl 0x82554798
	ctx.lr = 0x822CA888;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27856
	ctx.r4.s64 = r11.s64 + -27856;
	// addi r3,r10,-22852
	ctx.r3.s64 = ctx.r10.s64 + -22852;
	// bl 0x82554798
	ctx.lr = 0x822CA89C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27792
	ctx.r4.s64 = ctx.r9.s64 + -27792;
	// addi r3,r8,-22884
	ctx.r3.s64 = ctx.r8.s64 + -22884;
	// bl 0x82554798
	ctx.lr = 0x822CA8B0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27728
	ctx.r4.s64 = ctx.r7.s64 + -27728;
	// addi r3,r6,-22920
	ctx.r3.s64 = ctx.r6.s64 + -22920;
	// bl 0x82554798
	ctx.lr = 0x822CA8C4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27664
	ctx.r4.s64 = ctx.r5.s64 + -27664;
	// addi r3,r3,-22952
	ctx.r3.s64 = ctx.r3.s64 + -22952;
	// bl 0x82554798
	ctx.lr = 0x822CA8D8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27600
	ctx.r4.s64 = r11.s64 + -27600;
	// addi r3,r10,-22972
	ctx.r3.s64 = ctx.r10.s64 + -22972;
	// bl 0x82554798
	ctx.lr = 0x822CA8EC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27544
	ctx.r4.s64 = ctx.r9.s64 + -27544;
	// addi r3,r8,-22992
	ctx.r3.s64 = ctx.r8.s64 + -22992;
	// bl 0x82554798
	ctx.lr = 0x822CA900;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27528
	ctx.r4.s64 = ctx.r7.s64 + -27528;
	// addi r3,r6,-23012
	ctx.r3.s64 = ctx.r6.s64 + -23012;
	// bl 0x82554798
	ctx.lr = 0x822CA914;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27456
	ctx.r4.s64 = ctx.r5.s64 + -27456;
	// addi r3,r3,-23032
	ctx.r3.s64 = ctx.r3.s64 + -23032;
	// bl 0x82554798
	ctx.lr = 0x822CA928;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27440
	ctx.r4.s64 = r11.s64 + -27440;
	// addi r3,r10,-23060
	ctx.r3.s64 = ctx.r10.s64 + -23060;
	// bl 0x82554798
	ctx.lr = 0x822CA93C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27424
	ctx.r4.s64 = ctx.r9.s64 + -27424;
	// addi r3,r8,-23092
	ctx.r3.s64 = ctx.r8.s64 + -23092;
	// bl 0x82554798
	ctx.lr = 0x822CA950;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27360
	ctx.r4.s64 = ctx.r7.s64 + -27360;
	// addi r3,r6,-23132
	ctx.r3.s64 = ctx.r6.s64 + -23132;
	// bl 0x82554798
	ctx.lr = 0x822CA964;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27288
	ctx.r4.s64 = ctx.r5.s64 + -27288;
	// addi r3,r3,-23164
	ctx.r3.s64 = ctx.r3.s64 + -23164;
	// bl 0x82554798
	ctx.lr = 0x822CA978;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27264
	ctx.r4.s64 = r11.s64 + -27264;
	// addi r3,r10,-23192
	ctx.r3.s64 = ctx.r10.s64 + -23192;
	// bl 0x82554798
	ctx.lr = 0x822CA98C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-27200
	ctx.r4.s64 = ctx.r9.s64 + -27200;
	// addi r3,r8,-23212
	ctx.r3.s64 = ctx.r8.s64 + -23212;
	// bl 0x82554798
	ctx.lr = 0x822CA9A0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-27128
	ctx.r4.s64 = ctx.r7.s64 + -27128;
	// addi r3,r6,-23232
	ctx.r3.s64 = ctx.r6.s64 + -23232;
	// bl 0x82554798
	ctx.lr = 0x822CA9B4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-27088
	ctx.r4.s64 = ctx.r5.s64 + -27088;
	// addi r3,r3,-23264
	ctx.r3.s64 = ctx.r3.s64 + -23264;
	// bl 0x82554798
	ctx.lr = 0x822CA9C8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-27024
	ctx.r4.s64 = r11.s64 + -27024;
	// addi r3,r10,-23288
	ctx.r3.s64 = ctx.r10.s64 + -23288;
	// bl 0x82554798
	ctx.lr = 0x822CA9DC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-24496
	ctx.r4.s64 = ctx.r9.s64 + -24496;
	// addi r3,r8,-23308
	ctx.r3.s64 = ctx.r8.s64 + -23308;
	// bl 0x82554798
	ctx.lr = 0x822CA9F0;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24472
	ctx.r4.s64 = ctx.r7.s64 + -24472;
	// addi r3,r6,-23328
	ctx.r3.s64 = ctx.r6.s64 + -23328;
	// bl 0x82554798
	ctx.lr = 0x822CAA04;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24408
	ctx.r4.s64 = ctx.r5.s64 + -24408;
	// addi r3,r3,-23348
	ctx.r3.s64 = ctx.r3.s64 + -23348;
	// bl 0x82554798
	ctx.lr = 0x822CAA18;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-24344
	ctx.r4.s64 = r11.s64 + -24344;
	// addi r3,r10,-23372
	ctx.r3.s64 = ctx.r10.s64 + -23372;
	// bl 0x82554798
	ctx.lr = 0x822CAA2C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29720
	ctx.r4.s64 = ctx.r9.s64 + -29720;
	// addi r3,r8,-23396
	ctx.r3.s64 = ctx.r8.s64 + -23396;
	// bl 0x82554798
	ctx.lr = 0x822CAA40;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24280
	ctx.r4.s64 = ctx.r7.s64 + -24280;
	// addi r3,r6,-23420
	ctx.r3.s64 = ctx.r6.s64 + -23420;
	// bl 0x82554798
	ctx.lr = 0x822CAA54;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24216
	ctx.r4.s64 = ctx.r5.s64 + -24216;
	// addi r3,r3,-23444
	ctx.r3.s64 = ctx.r3.s64 + -23444;
	// bl 0x82554798
	ctx.lr = 0x822CAA68;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29664
	ctx.r4.s64 = r11.s64 + -29664;
	// addi r3,r10,-23472
	ctx.r3.s64 = ctx.r10.s64 + -23472;
	// bl 0x82554798
	ctx.lr = 0x822CAA7C;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29608
	ctx.r4.s64 = ctx.r9.s64 + -29608;
	// addi r3,r8,-23496
	ctx.r3.s64 = ctx.r8.s64 + -23496;
	// bl 0x82554798
	ctx.lr = 0x822CAA90;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29552
	ctx.r4.s64 = ctx.r7.s64 + -29552;
	// addi r3,r6,-23520
	ctx.r3.s64 = ctx.r6.s64 + -23520;
	// bl 0x82554798
	ctx.lr = 0x822CAAA4;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-24152
	ctx.r4.s64 = ctx.r5.s64 + -24152;
	// addi r3,r3,-23548
	ctx.r3.s64 = ctx.r3.s64 + -23548;
	// bl 0x82554798
	ctx.lr = 0x822CAAB8;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29496
	ctx.r4.s64 = r11.s64 + -29496;
	// addi r3,r10,-23580
	ctx.r3.s64 = ctx.r10.s64 + -23580;
	// bl 0x82554798
	ctx.lr = 0x822CAACC;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29440
	ctx.r4.s64 = ctx.r9.s64 + -29440;
	// addi r3,r8,-23616
	ctx.r3.s64 = ctx.r8.s64 + -23616;
	// bl 0x82554798
	ctx.lr = 0x822CAAE0;
	sub_82554798(ctx, base);
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r5,30576
	ctx.r3.s64 = ctx.r5.s64 + 30576;
	// addi r7,r7,-23620
	ctx.r7.s64 = ctx.r7.s64 + -23620;
	// addi r6,r6,-23664
	ctx.r6.s64 = ctx.r6.s64 + -23664;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca2f8
	ctx.lr = 0x822CAB08;
	sub_821CA2F8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb488
	ctx.lr = 0x822CAB14;
	sub_821CB488(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822cab58
	if (cr6.eq) goto loc_822CAB58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822CAB30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// cmpldi cr6,r3,3184
	cr6.compare<uint64_t>(ctx.r3.u64, 3184, xer);
	// addi r3,r10,-23696
	ctx.r3.s64 = ctx.r10.s64 + -23696;
	// bne cr6,0x822cab4c
	if (!cr6.eq) goto loc_822CAB4C;
	// lis r11,-32211
	r11.s64 = -2110980096;
	// addi r4,r11,-29384
	ctx.r4.s64 = r11.s64 + -29384;
	// b 0x822cab68
	goto loc_822CAB68;
loc_822CAB4C:
	// lis r11,-32211
	r11.s64 = -2110980096;
	// addi r4,r11,-29328
	ctx.r4.s64 = r11.s64 + -29328;
	// b 0x822cab68
	goto loc_822CAB68;
loc_822CAB58:
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29328
	ctx.r4.s64 = r11.s64 + -29328;
	// addi r3,r10,-23696
	ctx.r3.s64 = ctx.r10.s64 + -23696;
loc_822CAB68:
	// bl 0x82554798
	ctx.lr = 0x822CAB6C;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29272
	ctx.r4.s64 = r11.s64 + -29272;
	// addi r3,r10,-23720
	ctx.r3.s64 = ctx.r10.s64 + -23720;
	// bl 0x82554798
	ctx.lr = 0x822CAB80;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29216
	ctx.r4.s64 = ctx.r9.s64 + -29216;
	// addi r3,r8,-23740
	ctx.r3.s64 = ctx.r8.s64 + -23740;
	// bl 0x82554798
	ctx.lr = 0x822CAB94;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24088
	ctx.r4.s64 = ctx.r7.s64 + -24088;
	// addi r3,r6,-23768
	ctx.r3.s64 = ctx.r6.s64 + -23768;
	// bl 0x82554798
	ctx.lr = 0x822CABA8;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29160
	ctx.r4.s64 = ctx.r5.s64 + -29160;
	// addi r3,r3,-23788
	ctx.r3.s64 = ctx.r3.s64 + -23788;
	// bl 0x82554798
	ctx.lr = 0x822CABBC;
	sub_82554798(ctx, base);
	// lis r11,-32211
	r11.s64 = -2110980096;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-29160
	ctx.r4.s64 = r11.s64 + -29160;
	// addi r3,r10,-23812
	ctx.r3.s64 = ctx.r10.s64 + -23812;
	// bl 0x82554798
	ctx.lr = 0x822CABD0;
	sub_82554798(ctx, base);
	// lis r9,-32211
	ctx.r9.s64 = -2110980096;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29104
	ctx.r4.s64 = ctx.r9.s64 + -29104;
	// addi r3,r8,-23840
	ctx.r3.s64 = ctx.r8.s64 + -23840;
	// bl 0x82554798
	ctx.lr = 0x822CABE4;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29048
	ctx.r4.s64 = ctx.r7.s64 + -29048;
	// addi r3,r6,-23864
	ctx.r3.s64 = ctx.r6.s64 + -23864;
	// bl 0x82554798
	ctx.lr = 0x822CABF8;
	sub_82554798(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// addi r3,r3,-23880
	ctx.r3.s64 = ctx.r3.s64 + -23880;
	// bl 0x82554798
	ctx.lr = 0x822CAC0C;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,-23896
	ctx.r3.s64 = ctx.r10.s64 + -23896;
	// bl 0x82554798
	ctx.lr = 0x822CAC20;
	sub_82554798(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,0
	ctx.r4.s64 = ctx.r9.s64 + 0;
	// addi r3,r8,-23908
	ctx.r3.s64 = ctx.r8.s64 + -23908;
	// bl 0x82554798
	ctx.lr = 0x822CAC34;
	sub_82554798(ctx, base);
	// lis r7,-32211
	ctx.r7.s64 = -2110980096;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-24024
	ctx.r4.s64 = ctx.r7.s64 + -24024;
	// addi r3,r6,-23940
	ctx.r3.s64 = ctx.r6.s64 + -23940;
	// bl 0x82554798
	ctx.lr = 0x822CAC48;
	sub_82554798(ctx, base);
	// lis r5,-32211
	ctx.r5.s64 = -2110980096;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-26960
	ctx.r4.s64 = ctx.r5.s64 + -26960;
	// addi r3,r3,-23972
	ctx.r3.s64 = ctx.r3.s64 + -23972;
	// bl 0x82554798
	ctx.lr = 0x822CAC5C;
	sub_82554798(ctx, base);
	// bl 0x822c7018
	ctx.lr = 0x822CAC60;
	sub_822C7018(ctx, base);
	// bl 0x82305468
	ctx.lr = 0x822CAC64;
	sub_82305468(ctx, base);
	// bl 0x821e7e08
	ctx.lr = 0x822CAC68;
	sub_821E7E08(ctx, base);
	// bl 0x8268bb28
	ctx.lr = 0x822CAC6C;
	sub_8268BB28(ctx, base);
	// bl 0x822a7b20
	ctx.lr = 0x822CAC70;
	sub_822A7B20(ctx, base);
	// bl 0x822a4500
	ctx.lr = 0x822CAC74;
	sub_822A4500(ctx, base);
	// bl 0x822b9d28
	ctx.lr = 0x822CAC78;
	sub_822B9D28(ctx, base);
	// bl 0x822b8f48
	ctx.lr = 0x822CAC7C;
	sub_822B8F48(ctx, base);
	// bl 0x82744130
	ctx.lr = 0x822CAC80;
	sub_82744130(ctx, base);
	// bl 0x822624e8
	ctx.lr = 0x822CAC84;
	sub_822624E8(ctx, base);
	// bl 0x827096c8
	ctx.lr = 0x822CAC88;
	sub_827096C8(ctx, base);
	// bl 0x82742b10
	ctx.lr = 0x822CAC8C;
	sub_82742B10(ctx, base);
	// bl 0x822b6578
	ctx.lr = 0x822CAC90;
	sub_822B6578(ctx, base);
	// bl 0x8239d8d0
	ctx.lr = 0x822CAC94;
	sub_8239D8D0(ctx, base);
	// bl 0x82721540
	ctx.lr = 0x822CAC98;
	sub_82721540(ctx, base);
	// bl 0x821fdac8
	ctx.lr = 0x822CAC9C;
	sub_821FDAC8(ctx, base);
	// bl 0x82628270
	ctx.lr = 0x822CACA0;
	sub_82628270(ctx, base);
	// bl 0x82238b68
	ctx.lr = 0x822CACA4;
	sub_82238B68(ctx, base);
	// bl 0x82234f28
	ctx.lr = 0x822CACA8;
	sub_82234F28(ctx, base);
	// bl 0x82721fd8
	ctx.lr = 0x822CACAC;
	sub_82721FD8(ctx, base);
	// bl 0x8223de38
	ctx.lr = 0x822CACB0;
	sub_8223DE38(ctx, base);
	// bl 0x82212750
	ctx.lr = 0x822CACB4;
	sub_82212750(ctx, base);
	// bl 0x82218b98
	ctx.lr = 0x822CACB8;
	sub_82218B98(ctx, base);
	// bl 0x8272cfe8
	ctx.lr = 0x822CACBC;
	sub_8272CFE8(ctx, base);
	// bl 0x82255cb0
	ctx.lr = 0x822CACC0;
	sub_82255CB0(ctx, base);
	// bl 0x82256e60
	ctx.lr = 0x822CACC4;
	sub_82256E60(ctx, base);
	// bl 0x822671c8
	ctx.lr = 0x822CACC8;
	sub_822671C8(ctx, base);
	// bl 0x82264418
	ctx.lr = 0x822CACCC;
	sub_82264418(ctx, base);
	// bl 0x82267be0
	ctx.lr = 0x822CACD0;
	sub_82267BE0(ctx, base);
	// bl 0x82264780
	ctx.lr = 0x822CACD4;
	sub_82264780(ctx, base);
	// bl 0x823c6ef8
	ctx.lr = 0x822CACD8;
	sub_823C6EF8(ctx, base);
	// bl 0x826c2160
	ctx.lr = 0x822CACDC;
	sub_826C2160(ctx, base);
	// bl 0x826bb680
	ctx.lr = 0x822CACE0;
	sub_826BB680(ctx, base);
	// bl 0x826b6278
	ctx.lr = 0x822CACE4;
	sub_826B6278(ctx, base);
	// bl 0x826b50d0
	ctx.lr = 0x822CACE8;
	sub_826B50D0(ctx, base);
	// bl 0x82293988
	ctx.lr = 0x822CACEC;
	sub_82293988(ctx, base);
	// bl 0x826d8cc0
	ctx.lr = 0x822CACF0;
	sub_826D8CC0(ctx, base);
	// bl 0x82692268
	ctx.lr = 0x822CACF4;
	sub_82692268(ctx, base);
	// bl 0x82684998
	ctx.lr = 0x822CACF8;
	sub_82684998(ctx, base);
	// bl 0x82687090
	ctx.lr = 0x822CACFC;
	sub_82687090(ctx, base);
	// bl 0x826869a8
	ctx.lr = 0x822CAD00;
	sub_826869A8(ctx, base);
	// bl 0x82685188
	ctx.lr = 0x822CAD04;
	sub_82685188(ctx, base);
	// bl 0x82680fd8
	ctx.lr = 0x822CAD08;
	sub_82680FD8(ctx, base);
	// bl 0x8239d638
	ctx.lr = 0x822CAD0C;
	sub_8239D638(ctx, base);
	// bl 0x82398f80
	ctx.lr = 0x822CAD10;
	sub_82398F80(ctx, base);
	// bl 0x8239cd98
	ctx.lr = 0x822CAD14;
	sub_8239CD98(ctx, base);
	// bl 0x82390c00
	ctx.lr = 0x822CAD18;
	sub_82390C00(ctx, base);
	// bl 0x82260938
	ctx.lr = 0x822CAD1C;
	sub_82260938(ctx, base);
	// bl 0x8225d1f0
	ctx.lr = 0x822CAD20;
	sub_8225D1F0(ctx, base);
	// bl 0x822ccc00
	ctx.lr = 0x822CAD24;
	sub_822CCC00(ctx, base);
	// bl 0x8273bb38
	ctx.lr = 0x822CAD28;
	sub_8273BB38(ctx, base);
	// bl 0x8273aed8
	ctx.lr = 0x822CAD2C;
	sub_8273AED8(ctx, base);
	// bl 0x82397838
	ctx.lr = 0x822CAD30;
	sub_82397838(ctx, base);
	// bl 0x82269520
	ctx.lr = 0x822CAD34;
	sub_82269520(ctx, base);
	// bl 0x82269538
	ctx.lr = 0x822CAD38;
	sub_82269538(ctx, base);
	// bl 0x822d1648
	ctx.lr = 0x822CAD3C;
	sub_822D1648(ctx, base);
	// bl 0x826c3b50
	ctx.lr = 0x822CAD40;
	sub_826C3B50(ctx, base);
	// bl 0x821f0c60
	ctx.lr = 0x822CAD44;
	sub_821F0C60(ctx, base);
	// bl 0x82633b50
	ctx.lr = 0x822CAD48;
	sub_82633B50(ctx, base);
	// bl 0x821f2a08
	ctx.lr = 0x822CAD4C;
	sub_821F2A08(ctx, base);
	// bl 0x822e9118
	ctx.lr = 0x822CAD50;
	sub_822E9118(ctx, base);
	// bl 0x82307c98
	ctx.lr = 0x822CAD54;
	sub_82307C98(ctx, base);
	// bl 0x82328fb8
	ctx.lr = 0x822CAD58;
	sub_82328FB8(ctx, base);
	// bl 0x822f3bc0
	ctx.lr = 0x822CAD5C;
	sub_822F3BC0(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

