#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822E0F60"))) PPC_WEAK_FUNC(sub_822E0F60);
PPC_FUNC_IMPL(__imp__sub_822E0F60) {
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
	ctx.lr = 0x822E0F68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-11720
	r31.s64 = r11.s64 + -11720;
	// lwz r11,-11720(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11720);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e10a8
	if (!cr6.eq) goto loc_822E10A8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822E0F88;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e0f98
	if (cr6.eq) goto loc_822E0F98;
	// bl 0x821d5408
	ctx.lr = 0x822E0F94;
	sub_821D5408(ctx, base);
	// b 0x822e0f9c
	goto loc_822E0F9C;
loc_822E0F98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822E0F9C:
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// addi r4,r8,-9364
	ctx.r4.s64 = ctx.r8.s64 + -9364;
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r9,80
	ctx.r9.s64 = 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r7,5044
	ctx.r8.s64 = ctx.r7.s64 + 5044;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r7,r5,5068
	ctx.r7.s64 = ctx.r5.s64 + 5068;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r9,32
	ctx.r9.s64 = 32;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// addi r30,r10,5152
	r30.s64 = ctx.r10.s64 + 5152;
	// li r10,16
	ctx.r10.s64 = 16;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// addi r3,r5,5104
	ctx.r3.s64 = ctx.r5.s64 + 5104;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// addi r7,r4,5128
	ctx.r7.s64 = ctx.r4.s64 + 5128;
	// li r8,60
	ctx.r8.s64 = 60;
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r11,-11724(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -11724);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// bne cr6,0x822e1040
	if (!cr6.eq) goto loc_822E1040;
	// bl 0x822e0e38
	ctx.lr = 0x822E103C;
	sub_822E0E38(ctx, base);
	// lwz r11,-11724(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -11724);
loc_822E1040:
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x822E1054;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822E1064;
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
	ctx.lr = 0x822E1080;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,5188
	ctx.r4.s64 = ctx.r8.s64 + 5188;
	// bl 0x821d4b00
	ctx.lr = 0x822E1090;
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
	ctx.lr = 0x822E10A8;
	sub_821C0548(ctx, base);
loc_822E10A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E10B0"))) PPC_WEAK_FUNC(sub_822E10B0);
PPC_FUNC_IMPL(__imp__sub_822E10B0) {
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
	ctx.lr = 0x822E10B8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r11,-11712
	r29.s64 = r11.s64 + -11712;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r29
	r31.u64 = r29.u64;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
loc_822E10EC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82496790
	ctx.lr = 0x822E10FC;
	sub_82496790(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// addi r11,r29,160
	r11.s64 = r29.s64 + 160;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822e10ec
	if (cr6.lt) goto loc_822E10EC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r11,-11552
	r30.s64 = r11.s64 + -11552;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822E1118:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1120;
	sub_82496ED8(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// addi r11,r30,160
	r11.s64 = r30.s64 + 160;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822e1118
	if (cr6.lt) goto loc_822E1118;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_822E1134:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E113C;
	sub_82496ED8(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// addi r11,r29,160
	r11.s64 = r29.s64 + 160;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822e1134
	if (cr6.lt) goto loc_822E1134;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E1158"))) PPC_WEAK_FUNC(sub_822E1158);
PPC_FUNC_IMPL(__imp__sub_822E1158) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,5456
	ctx.r7.s64 = ctx.r9.s64 + 5456;
	// addi r10,r11,224
	ctx.r10.s64 = r11.s64 + 224;
	// lfs f12,5456(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 5456);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,224(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 224, temp.u32);
	// stfs f13,228(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 228, temp.u32);
	// stfs f0,232(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 232, temp.u32);
	// stfs f11,236(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 236, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E119C"))) PPC_WEAK_FUNC(sub_822E119C);
PPC_FUNC_IMPL(__imp__sub_822E119C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E11A0"))) PPC_WEAK_FUNC(sub_822E11A0);
PPC_FUNC_IMPL(__imp__sub_822E11A0) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822E11A8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822E11BC;
	sub_822F10D0(ctx, base);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// lbzx r30,r9,r10
	r30.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// lwz r31,22080(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 22080);
	// lwz r3,-17936(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17936);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// bne cr6,0x822e11e8
	if (!cr6.eq) goto loc_822E11E8;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_822E11E8:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r10,r8,6976
	ctx.r10.s64 = ctx.r8.s64 + 6976;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r6,r11,5456
	ctx.r6.s64 = r11.s64 + 5456;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfsx f13,r5,r10
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r11,-11712
	ctx.r4.s64 = r11.s64 + -11712;
	// lfs f11,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fdivs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 / ctx.f13.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// stfs f13,4(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f12,8(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// addi r10,r4,24
	ctx.r10.s64 = ctx.r4.s64 + 24;
	// addi r5,r11,6928
	ctx.r5.s64 = r11.s64 + 6928;
loc_822E1240:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e1250
	if (!cr6.eq) goto loc_822E1250;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E1250:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f11,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// ble cr6,0x822e1298
	if (!cr6.gt) goto loc_822E1298;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E127C:
	// lfs f9,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f9,f1
	cr6.compare(ctx.f9.f64, ctx.f1.f64);
	// bge cr6,0x822e134c
	if (!cr6.lt) goto loc_822E134C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e127c
	if (cr6.lt) goto loc_822E127C;
loc_822E1298:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_822E12AC:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// addi r29,r4,184
	r29.s64 = ctx.r4.s64 + 184;
	// lfs f9,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// fsubs f8,f1,f9
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f9.f64));
	// lfs f6,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f5,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f2.f64 = double(temp.f32);
	// lfs f9,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// lfs f31,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f31.f64 = double(temp.f32);
	// fmadds f7,f8,f7,f6
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f6,f5,f8,f4
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f8.f64 + ctx.f4.f64));
	// stfs f6,84(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f5,f3,f8,f2
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f8.f64 + ctx.f2.f64));
	// stfs f5,88(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f4,f9,f8,f31
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + f31.f64));
	// stfs f4,92(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f0,f3,f11,f0
	f0.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + f0.f64));
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f13,f2,f11,f13
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fmadds f12,f9,f11,f12
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f13,4(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f12,8(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// blt cr6,0x822e1240
	if (cr6.lt) goto loc_822E1240;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822E134C:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x822e12ac
	goto loc_822E12AC;
}

__attribute__((alias("__imp__sub_822E1364"))) PPC_WEAK_FUNC(sub_822E1364);
PPC_FUNC_IMPL(__imp__sub_822E1364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E1368"))) PPC_WEAK_FUNC(sub_822E1368);
PPC_FUNC_IMPL(__imp__sub_822E1368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r9,r11,5456
	ctx.r9.s64 = r11.s64 + 5456;
	// addi r8,r1,28
	ctx.r8.s64 = ctx.r1.s64 + 28;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v0,v13,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E139C"))) PPC_WEAK_FUNC(sub_822E139C);
PPC_FUNC_IMPL(__imp__sub_822E139C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E13A0"))) PPC_WEAK_FUNC(sub_822E13A0);
PPC_FUNC_IMPL(__imp__sub_822E13A0) {
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
	ctx.lr = 0x822E13A8;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r31,r11,-11712
	r31.s64 = r11.s64 + -11712;
	// addi r29,r10,6912
	r29.s64 = ctx.r10.s64 + 6912;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r29
	r30.u64 = r29.u64;
	// addi r27,r11,-9064
	r27.s64 = r11.s64 + -9064;
loc_822E13CC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x822E13DC;
	sub_823DC018(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E13F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E1400;
	sub_8261DDE8(ctx, base);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r8,r29,16
	ctx.r8.s64 = r29.s64 + 16;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r31.u32);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// blt cr6,0x822e13cc
	if (cr6.lt) goto loc_822E13CC;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822E1424"))) PPC_WEAK_FUNC(sub_822E1424);
PPC_FUNC_IMPL(__imp__sub_822E1424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E1428"))) PPC_WEAK_FUNC(sub_822E1428);
PPC_FUNC_IMPL(__imp__sub_822E1428) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822E1430;
	// lwz r4,0(r13)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,72
	r31.s64 = 72;
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e1454
	if (cr6.eq) goto loc_822E1454;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e1458
	goto loc_822E1458;
loc_822E1454:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E1458:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r10,6976
	ctx.r8.s64 = ctx.r10.s64 + 6976;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r6,r3,80
	ctx.r6.s64 = ctx.r3.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfsx f12,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r3,120
	ctx.r10.s64 = ctx.r3.s64 + 120;
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r11,6928
	ctx.r5.s64 = r11.s64 + 6928;
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// fdivs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
loc_822E149C:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e14b0
	if (cr6.eq) goto loc_822E14B0;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e14b4
	goto loc_822E14B4;
loc_822E14B0:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E14B4:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e14fc
	if (!cr6.gt) goto loc_822E14FC;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E14E0:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e14fc
	if (!cr6.lt) goto loc_822E14FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e14e0
	if (cr6.lt) goto loc_822E14E0;
loc_822E14FC:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f2,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// lfs f12,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f10,f11,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f10,-64(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f9,f8,f11,f7
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f9,-60(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f8,f6,f11,f5
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f8,-56(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f7,f4,f11,f3
	ctx.f7.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f7,-52(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f3,f5,f0,f2
	ctx.f3.f64 = double(float(ctx.f5.f64 * f0.f64 + ctx.f2.f64));
	// lfs f6,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,-44(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,-40(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -40);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f12,f4,f0,f12
	ctx.f12.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f11,f2,f0,f6
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64 + ctx.f6.f64));
	// stfs f3,0(r6)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f12,84(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f11,88(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blt cr6,0x822e149c
	if (cr6.lt) goto loc_822E149C;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E15B0"))) PPC_WEAK_FUNC(sub_822E15B0);
PPC_FUNC_IMPL(__imp__sub_822E15B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822E15B8;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822e06e0
	ctx.lr = 0x822E15CC;
	sub_822E06E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-9032
	ctx.r9.s64 = r11.s64 + -9032;
	// addi r31,r30,96
	r31.s64 = r30.s64 + 96;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// li r29,3
	r29.s64 = 3;
	// mr r28,r31
	r28.u64 = r31.u64;
	// lfs f31,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f31.f64 = double(temp.f32);
	// stfs f31,80(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 80, temp.u32);
	// stfs f31,84(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 84, temp.u32);
	// stfs f31,88(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 88, temp.u32);
loc_822E15F8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E1600;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e15f8
	if (!cr0.lt) goto loc_822E15F8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,4
	r29.s64 = 4;
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
loc_822E1618:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1620;
	sub_82496ED8(ctx, base);
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82496790
	ctx.lr = 0x822E1640;
	sub_82496790(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// bne 0x822e1618
	if (!cr0.eq) goto loc_822E1618;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E1660"))) PPC_WEAK_FUNC(sub_822E1660);
PPC_FUNC_IMPL(__imp__sub_822E1660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11716(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11716);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E166C"))) PPC_WEAK_FUNC(sub_822E166C);
PPC_FUNC_IMPL(__imp__sub_822E166C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E1670"))) PPC_WEAK_FUNC(sub_822E1670);
PPC_FUNC_IMPL(__imp__sub_822E1670) {
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
	ctx.lr = 0x822E1678;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,3
	r30.s64 = 3;
	// addi r31,r29,256
	r31.s64 = r29.s64 + 256;
loc_822E1688:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E1694;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e1688
	if (!cr0.lt) goto loc_822E1688;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-9408
	ctx.r9.s64 = r11.s64 + -9408;
	// addi r8,r10,-9420
	ctx.r8.s64 = ctx.r10.s64 + -9420;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// addi r11,r29,48
	r11.s64 = r29.s64 + 48;
	// stw r8,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r8.u32);
	// lhz r7,58(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 58);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e16cc
	if (cr6.eq) goto loc_822E16CC;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822E16CC;
	sub_82130588(ctx, base);
loc_822E16CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E16D4"))) PPC_WEAK_FUNC(sub_822E16D4);
PPC_FUNC_IMPL(__imp__sub_822E16D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E16D8"))) PPC_WEAK_FUNC(sub_822E16D8);
PPC_FUNC_IMPL(__imp__sub_822E16D8) {
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
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822E16EC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e1708
	if (cr6.eq) goto loc_822E1708;
	// bl 0x822e15b0
	ctx.lr = 0x822E16F8;
	sub_822E15B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E1708:
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

__attribute__((alias("__imp__sub_822E171C"))) PPC_WEAK_FUNC(sub_822E171C);
PPC_FUNC_IMPL(__imp__sub_822E171C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E1720"))) PPC_WEAK_FUNC(sub_822E1720);
PPC_FUNC_IMPL(__imp__sub_822E1720) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-11716
	r31.s64 = r11.s64 + -11716;
	// lwz r11,-11716(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11716);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e1870
	if (!cr6.eq) goto loc_822E1870;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822E1750;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e1764
	if (cr6.eq) goto loc_822E1764;
	// bl 0x821d5408
	ctx.lr = 0x822E1760;
	sub_821D5408(ctx, base);
	// b 0x822e1768
	goto loc_822E1768;
loc_822E1764:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822E1768:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12424
	ctx.r7.s64 = ctx.r10.s64 + -12424;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,5848
	ctx.r4.s64 = ctx.r8.s64 + 5848;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,5392
	ctx.r9.s64 = ctx.r3.s64 + 5392;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,96
	ctx.r10.s64 = 96;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e17e4
	if (!cr6.eq) goto loc_822E17E4;
	// bl 0x824970b0
	ctx.lr = 0x822E17E0;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E17E4:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r10,5348
	ctx.r9.s64 = ctx.r10.s64 + 5348;
	// lwz r4,-11720(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bne cr6,0x822e1808
	if (!cr6.eq) goto loc_822E1808;
	// bl 0x822e0f60
	ctx.lr = 0x822E1804;
	sub_822E0F60(ctx, base);
	// lwz r4,-11720(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -11720);
loc_822E1808:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x822E1814;
	sub_821D4458(ctx, base);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x822E182C;
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
	ctx.lr = 0x822E1848;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,5384
	ctx.r4.s64 = ctx.r8.s64 + 5384;
	// bl 0x821d4b00
	ctx.lr = 0x822E1858;
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
	ctx.lr = 0x822E1870;
	sub_821C0548(ctx, base);
loc_822E1870:
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

__attribute__((alias("__imp__sub_822E1888"))) PPC_WEAK_FUNC(sub_822E1888);
PPC_FUNC_IMPL(__imp__sub_822E1888) {
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
	// bl 0x822e1670
	ctx.lr = 0x822E18A8;
	sub_822E1670(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e18c0
	if (cr6.eq) goto loc_822E18C0;
	// bl 0x82130588
	ctx.lr = 0x822E18BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E18C0:
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

__attribute__((alias("__imp__sub_822E18D8"))) PPC_WEAK_FUNC(sub_822E18D8);
PPC_FUNC_IMPL(__imp__sub_822E18D8) {
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
	ctx.lr = 0x822E18E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r7,-10732
	r30.s64 = ctx.r7.s64 + -10732;
	// addi r29,r8,-9932
	r29.s64 = ctx.r8.s64 + -9932;
	// addi r28,r9,-10892
	r28.s64 = ctx.r9.s64 + -10892;
	// addi r27,r10,-10252
	r27.s64 = ctx.r10.s64 + -10252;
	// addi r26,r11,-11052
	r26.s64 = r11.s64 + -11052;
loc_822E1910:
	// add r3,r31,r26
	ctx.r3.u64 = r31.u64 + r26.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1918;
	sub_82496ED8(ctx, base);
	// add r3,r31,r27
	ctx.r3.u64 = r31.u64 + r27.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1920;
	sub_82496ED8(ctx, base);
	// add r3,r31,r28
	ctx.r3.u64 = r31.u64 + r28.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1928;
	sub_82496ED8(ctx, base);
	// add r3,r31,r29
	ctx.r3.u64 = r31.u64 + r29.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1930;
	sub_82496ED8(ctx, base);
	// add r3,r31,r30
	ctx.r3.u64 = r31.u64 + r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1938;
	sub_82496ED8(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// cmpwi cr6,r31,160
	cr6.compare<int32_t>(r31.s32, 160, xer);
	// blt cr6,0x822e1910
	if (cr6.lt) goto loc_822E1910;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r7,-10412
	r30.s64 = ctx.r7.s64 + -10412;
	// addi r29,r8,-11212
	r29.s64 = ctx.r8.s64 + -11212;
	// addi r28,r9,-10572
	r28.s64 = ctx.r9.s64 + -10572;
	// addi r27,r10,-11372
	r27.s64 = ctx.r10.s64 + -11372;
	// addi r26,r11,-10092
	r26.s64 = r11.s64 + -10092;
loc_822E1970:
	// add r3,r31,r26
	ctx.r3.u64 = r31.u64 + r26.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1978;
	sub_82496ED8(ctx, base);
	// add r3,r31,r27
	ctx.r3.u64 = r31.u64 + r27.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1980;
	sub_82496ED8(ctx, base);
	// add r3,r31,r28
	ctx.r3.u64 = r31.u64 + r28.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1988;
	sub_82496ED8(ctx, base);
	// add r3,r31,r29
	ctx.r3.u64 = r31.u64 + r29.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1990;
	sub_82496ED8(ctx, base);
	// add r3,r31,r30
	ctx.r3.u64 = r31.u64 + r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E1998;
	sub_82496ED8(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// cmpwi cr6,r31,160
	cr6.compare<int32_t>(r31.s32, 160, xer);
	// blt cr6,0x822e1970
	if (cr6.lt) goto loc_822E1970;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822E19AC"))) PPC_WEAK_FUNC(sub_822E19AC);
PPC_FUNC_IMPL(__imp__sub_822E19AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E19B0"))) PPC_WEAK_FUNC(sub_822E19B0);
PPC_FUNC_IMPL(__imp__sub_822E19B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e19f4
	if (cr6.eq) goto loc_822E19F4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54609
	ctx.r9.u64 = ctx.r10.u64 | 54609;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822e19f8
	if (!cr6.eq) goto loc_822E19F8;
loc_822E19F4:
	// li r11,0
	r11.s64 = 0;
loc_822E19F8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e1b40
	if (!cr6.eq) goto loc_822E1B40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e1a30
	if (cr6.eq) goto loc_822E1A30;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E1A24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822e1b40
	if (!cr6.eq) goto loc_822E1B40;
loc_822E1A30:
	// bl 0x82207e88
	ctx.lr = 0x822E1A34;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e1b40
	if (!cr6.eq) goto loc_822E1B40;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e1b40
	if (cr6.eq) goto loc_822E1B40;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f11,5736(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 5736);
	ctx.f11.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f0,5728(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 5728);
	f0.f64 = double(temp.f32);
	// li r4,400
	ctx.r4.s64 = 400;
	// lfs f13,5732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 5732);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lfs f12,-11376(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11376);
	ctx.f12.f64 = double(temp.f32);
	// li r8,14464
	ctx.r8.s64 = 14464;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r7,14480
	ctx.r7.s64 = 14480;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r31,-32256
	r31.s64 = -2113929216;
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r30,6000
	ctx.r4.s64 = r30.s64 + 6000;
	// lwz r11,-7572(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -7572);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,21664(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,368
	ctx.r3.s64 = 368;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// li r31,384
	r31.s64 = 384;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,6016
	ctx.r8.s64 = ctx.r4.s64 + 6016;
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lfs f10,14492(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14492);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f13,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + f0.f64));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f7,f0,f12
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f8,f0,f13
	ctx.f8.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fsubs f6,f0,f11
	ctx.f6.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fmadds f4,f7,f10,f12
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f12.f64));
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f5,f8,f10,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + ctx.f13.f64));
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f6,f10,f11
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v59,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v63,v62
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v58,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E1B40:
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

__attribute__((alias("__imp__sub_822E1B58"))) PPC_WEAK_FUNC(sub_822E1B58);
PPC_FUNC_IMPL(__imp__sub_822E1B58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// bl 0x823d91fc
	ctx.lr = 0x822E1B60;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822E1B7C;
	sub_822F10D0(ctx, base);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// lbzx r30,r9,r10
	r30.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// lwz r31,22080(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 22080);
	// lwz r3,-17936(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17936);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// bne cr6,0x822e1ba8
	if (!cr6.eq) goto loc_822E1BA8;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_822E1BA8:
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,6976
	ctx.r10.s64 = ctx.r9.s64 + 6976;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,6000
	ctx.r7.s64 = r11.s64 + 6000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfsx f8,r4,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-10092
	ctx.r5.s64 = r11.s64 + -10092;
	// lfs f9,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fmr f13,f9
	ctx.f13.f64 = ctx.f9.f64;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmr f12,f9
	ctx.f12.f64 = ctx.f9.f64;
	// fmr f11,f9
	ctx.f11.f64 = ctx.f9.f64;
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmr f10,f9
	ctx.f10.f64 = ctx.f9.f64;
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f11,8(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
	// stfs f10,12(r7)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// fdivs f8,f0,f8
	ctx.f8.f64 = double(float(f0.f64 / ctx.f8.f64));
	// addi r4,r11,6928
	ctx.r4.s64 = r11.s64 + 6928;
loc_822E1C0C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e1c1c
	if (!cr6.eq) goto loc_822E1C1C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E1C1C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r6
	ctx.r9.u64 = r11.u64 + ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f8
	f0.f64 = double(float(f0.f64 * ctx.f8.f64));
	// ble cr6,0x822e1c64
	if (!cr6.gt) goto loc_822E1C64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E1C48:
	// lfs f7,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fcmpu cr6,f7,f1
	cr6.compare(ctx.f7.f64, ctx.f1.f64);
	// bge cr6,0x822e1c64
	if (!cr6.lt) goto loc_822E1C64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e1c48
	if (cr6.lt) goto loc_822E1C48;
loc_822E1C64:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f7,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f1,f7
	ctx.f6.f64 = double(float(ctx.f1.f64 - ctx.f7.f64));
	// lfs f4,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f31,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f31.f64 = double(temp.f32);
	// lfs f30,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f30.f64 = double(temp.f32);
	// lfs f29,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f29.f64 = double(temp.f32);
	// fmadds f5,f5,f6,f4
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f6.f64 + ctx.f4.f64));
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f4,f3,f6,f2
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f6.f64 + ctx.f2.f64));
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f3,f7,f6,f31
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 + f31.f64));
	// stfs f3,104(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f2,f30,f6,f29
	ctx.f2.f64 = double(float(f30.f64 * ctx.f6.f64 + f29.f64));
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f13,f7,f0,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// lfs f5,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f12,f6,f0,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// lfs f4,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f11,f5,f0,f11
	ctx.f11.f64 = double(float(ctx.f5.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f10,f4,f0,f10
	ctx.f10.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f10.f64));
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f11,8(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfs f10,12(r7)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// blt cr6,0x822e1c0c
	if (cr6.lt) goto loc_822E1C0C;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// fmr f13,f9
	ctx.f13.f64 = ctx.f9.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// fmr f12,f9
	ctx.f12.f64 = ctx.f9.f64;
	// addi r7,r10,6016
	ctx.r7.s64 = ctx.r10.s64 + 6016;
	// fmr f11,f9
	ctx.f11.f64 = ctx.f9.f64;
	// addi r5,r11,-11372
	ctx.r5.s64 = r11.s64 + -11372;
	// fmr f10,f9
	ctx.f10.f64 = ctx.f9.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f11,8(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfs f10,12(r7)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
loc_822E1D50:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e1d60
	if (!cr6.eq) goto loc_822E1D60;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E1D60:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r6
	ctx.r9.u64 = r11.u64 + ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f8
	f0.f64 = double(float(f0.f64 * ctx.f8.f64));
	// ble cr6,0x822e1da8
	if (!cr6.gt) goto loc_822E1DA8;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E1D8C:
	// lfs f7,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fcmpu cr6,f7,f1
	cr6.compare(ctx.f7.f64, ctx.f1.f64);
	// bge cr6,0x822e1da8
	if (!cr6.lt) goto loc_822E1DA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e1d8c
	if (cr6.lt) goto loc_822E1D8C;
loc_822E1DA8:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f7,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f1,f7
	ctx.f6.f64 = double(float(ctx.f1.f64 - ctx.f7.f64));
	// lfs f4,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f31,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f31.f64 = double(temp.f32);
	// lfs f30,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f30.f64 = double(temp.f32);
	// lfs f29,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f29.f64 = double(temp.f32);
	// fmadds f5,f5,f6,f4
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f6.f64 + ctx.f4.f64));
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f4,f3,f6,f2
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f6.f64 + ctx.f2.f64));
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f3,f7,f6,f31
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 + f31.f64));
	// stfs f3,104(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f2,f30,f6,f29
	ctx.f2.f64 = double(float(f30.f64 * ctx.f6.f64 + f29.f64));
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f13,f0,f7,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f7.f64 + ctx.f13.f64));
	// lfs f5,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f12,f0,f6,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f6.f64 + ctx.f12.f64));
	// lfs f4,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f11,f0,f5,f11
	ctx.f11.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// fmadds f10,f0,f4,f10
	ctx.f10.f64 = double(float(f0.f64 * ctx.f4.f64 + ctx.f10.f64));
	// stfs f13,0(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f12,4(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f11,8(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfs f10,12(r7)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// blt cr6,0x822e1d50
	if (cr6.lt) goto loc_822E1D50;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-10572
	ctx.r5.s64 = r11.s64 + -10572;
	// stfs f0,5728(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 5728, temp.u32);
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
loc_822E1E78:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e1e88
	if (!cr6.eq) goto loc_822E1E88;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E1E88:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// ble cr6,0x822e1ed0
	if (!cr6.gt) goto loc_822E1ED0;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E1EB4:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e1ed0
	if (!cr6.lt) goto loc_822E1ED0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e1eb4
	if (cr6.lt) goto loc_822E1EB4;
loc_822E1ED0:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f11,f10,f7
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f7,f6,f11,f5
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f6,f4,f11,f3
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f5,f2,f11,f12
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f13,f4,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + f0.f64));
	// stfs f0,5728(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 5728, temp.u32);
	// blt cr6,0x822e1e78
	if (cr6.lt) goto loc_822E1E78;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
	// stfs f0,5732(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 5732, temp.u32);
loc_822E1F74:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e1f84
	if (!cr6.eq) goto loc_822E1F84;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E1F84:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// ble cr6,0x822e1fcc
	if (!cr6.gt) goto loc_822E1FCC;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E1FB0:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e1fcc
	if (!cr6.lt) goto loc_822E1FCC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e1fb0
	if (cr6.lt) goto loc_822E1FB0;
loc_822E1FCC:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f10,f11,f7
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f7,f6,f11,f5
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f6,f4,f11,f3
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f5,f2,f11,f12
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f13,f4,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + f0.f64));
	// stfs f0,5732(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 5732, temp.u32);
	// blt cr6,0x822e1f74
	if (cr6.lt) goto loc_822E1F74;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-11212
	ctx.r6.s64 = r11.s64 + -11212;
	// stfs f0,-11376(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -11376, temp.u32);
	// addi r10,r6,24
	ctx.r10.s64 = ctx.r6.s64 + 24;
loc_822E2078:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e2088
	if (!cr6.eq) goto loc_822E2088;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E2088:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// ble cr6,0x822e20d0
	if (!cr6.gt) goto loc_822E20D0;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E20B4:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e20d0
	if (!cr6.lt) goto loc_822E20D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e20b4
	if (cr6.lt) goto loc_822E20B4;
loc_822E20D0:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r6,184
	r29.s64 = ctx.r6.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f10,f11,f7
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f7,f6,f11,f5
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f6,f4,f11,f3
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f5,f2,f11,f12
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f13,f4,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + f0.f64));
	// stfs f0,-11376(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -11376, temp.u32);
	// blt cr6,0x822e2078
	if (cr6.lt) goto loc_822E2078;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// fmr f0,f9
	f0.f64 = ctx.f9.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-10412
	ctx.r6.s64 = r11.s64 + -10412;
	// stfs f0,5736(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 5736, temp.u32);
	// addi r10,r6,24
	ctx.r10.s64 = ctx.r6.s64 + 24;
loc_822E217C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e218c
	if (!cr6.eq) goto loc_822E218C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E218C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// ble cr6,0x822e21d4
	if (!cr6.gt) goto loc_822E21D4;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E21B8:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e21d4
	if (!cr6.lt) goto loc_822E21D4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e21b8
	if (cr6.lt) goto loc_822E21B8;
loc_822E21D4:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r6,184
	r29.s64 = ctx.r6.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f12,f10,f11,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f10,f7,f11,f6
	ctx.f10.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f6.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f9,f5,f11,f4
	ctx.f9.f64 = double(float(ctx.f5.f64 * ctx.f11.f64 + ctx.f4.f64));
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f7,f3,f11,f2
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f2.f64));
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f0,f13,f6,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + f0.f64));
	// stfs f0,5736(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 5736, temp.u32);
	// blt cr6,0x822e217c
	if (cr6.lt) goto loc_822E217C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-56(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E2278"))) PPC_WEAK_FUNC(sub_822E2278);
PPC_FUNC_IMPL(__imp__sub_822E2278) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// bl 0x823d91fc
	ctx.lr = 0x822E2280;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r9,r11,6000
	ctx.r9.s64 = r11.s64 + 6000;
	// addi r8,r1,-48
	ctx.r8.s64 = ctx.r1.s64 + -48;
	// addi r7,r1,-48
	ctx.r7.s64 = ctx.r1.s64 + -48;
	// addi r11,r1,-48
	r11.s64 = ctx.r1.s64 + -48;
	// lvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-48
	ctx.r10.s64 = ctx.r1.s64 + -48;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r4,r6,6016
	ctx.r4.s64 = ctx.r6.s64 + 6016;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r31,-32130
	r31.s64 = -2105671680;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r29,-32130
	r29.s64 = -2105671680;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,5728(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 5728);
	f0.f64 = double(temp.f32);
	// lfs f13,5732(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 5732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11376(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -11376);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,5736(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 5736);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-44(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,-40(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -40);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f4,f10,f1
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmuls f6,f7,f1
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f1.f64));
	// stfs f6,-44(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// fmuls f5,f8,f1
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f1.f64));
	// stfs f5,-48(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// fmuls f3,f9,f1
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// stfs f4,-40(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f3,-36(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r3,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v62
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,-36(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-44(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	ctx.f8.f64 = double(temp.f32);
	// lfs f2,-40(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -40);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f5,f2,f1
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f1.f64));
	// fmuls f7,f8,f1
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64));
	// stfs f7,-44(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// fmuls f6,f9,f1
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// stfs f6,-48(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// fmuls f4,f10,f1
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// stfs f5,-40(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// stfs f4,-36(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -36, temp.u32);
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,112(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fmadds f0,f2,f1,f0
	f0.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + f0.f64));
	// stfs f0,5728(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 5728, temp.u32);
	// lfs f0,116(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmadds f0,f10,f1,f13
	f0.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f13.f64));
	// stfs f0,5732(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 5732, temp.u32);
	// lfs f9,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fmadds f0,f8,f1,f12
	f0.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f0,-11376(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + -11376, temp.u32);
	// lfs f7,124(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f11.f64));
	// fmadds f0,f6,f1,f11
	f0.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f0,5736(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 5736, temp.u32);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E23A4"))) PPC_WEAK_FUNC(sub_822E23A4);
PPC_FUNC_IMPL(__imp__sub_822E23A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E23A8"))) PPC_WEAK_FUNC(sub_822E23A8);
PPC_FUNC_IMPL(__imp__sub_822E23A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x822E23B0;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r16,r11,6912
	r16.s64 = r11.s64 + 6912;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r16
	r30.u64 = r16.u64;
	// addi r26,r5,-10412
	r26.s64 = ctx.r5.s64 + -10412;
	// addi r25,r4,-11212
	r25.s64 = ctx.r4.s64 + -11212;
	// addi r24,r3,-10572
	r24.s64 = ctx.r3.s64 + -10572;
	// addi r23,r28,-11372
	r23.s64 = r28.s64 + -11372;
	// addi r22,r6,-10092
	r22.s64 = ctx.r6.s64 + -10092;
	// addi r21,r7,-8584
	r21.s64 = ctx.r7.s64 + -8584;
	// addi r20,r8,-8608
	r20.s64 = ctx.r8.s64 + -8608;
	// addi r19,r9,-8636
	r19.s64 = ctx.r9.s64 + -8636;
	// addi r18,r10,-8664
	r18.s64 = ctx.r10.s64 + -8664;
	// addi r17,r11,-8692
	r17.s64 = r11.s64 + -8692;
loc_822E2418:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x822E2428;
	sub_823DC018(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E2438;
	sub_823DC018(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E2448;
	sub_823DC018(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E2458;
	sub_823DC018(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E2468;
	sub_823DC018(ctx, base);
	// lwzx r11,r31,r22
	r11.u64 = PPC_LOAD_U32(r31.u32 + r22.u32);
	// add r28,r31,r22
	r28.u64 = r31.u64 + r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E2480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E2490;
	sub_8261DDE8(ctx, base);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r27,r31,r23
	r27.u64 = r31.u64 + r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r28,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r28.u32);
	// lwzx r8,r31,r23
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r23.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822E24B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E24C0;
	sub_8261DDE8(ctx, base);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r28,r31,r24
	r28.u64 = r31.u64 + r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r27.u32);
	// lwzx r5,r31,r24
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822E24E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E24F0;
	sub_8261DDE8(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r27,r31,r25
	r27.u64 = r31.u64 + r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// lwzx r10,r31,r25
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r25.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E2510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E2520;
	sub_8261DDE8(ctx, base);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r28,r31,r26
	r28.u64 = r31.u64 + r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// lwzx r7,r31,r26
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822E2540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E2550;
	sub_8261DDE8(ctx, base);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// addi r4,r16,16
	ctx.r4.s64 = r16.s64 + 16;
	// stw r28,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r28.u32);
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// blt cr6,0x822e2418
	if (cr6.lt) goto loc_822E2418;
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_822E2574"))) PPC_WEAK_FUNC(sub_822E2574);
PPC_FUNC_IMPL(__imp__sub_822E2574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E2578"))) PPC_WEAK_FUNC(sub_822E2578);
PPC_FUNC_IMPL(__imp__sub_822E2578) {
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
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822E2580;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// lwz r4,0(r13)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,72
	r31.s64 = 72;
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e25a8
	if (cr6.eq) goto loc_822E25A8;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e25ac
	goto loc_822E25AC;
loc_822E25A8:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E25AC:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r10,6976
	ctx.r8.s64 = ctx.r10.s64 + 6976;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r6,r3,80
	ctx.r6.s64 = ctx.r3.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f12,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfsx f13,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r3,152
	ctx.r10.s64 = ctx.r3.s64 + 152;
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r5,r11,6928
	ctx.r5.s64 = r11.s64 + 6928;
	// stfs f12,80(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,84(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f12,88(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f12,92(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
loc_822E25F4:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e2608
	if (cr6.eq) goto loc_822E2608;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e260c
	goto loc_822E260C;
loc_822E2608:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E260C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e2654
	if (!cr6.gt) goto loc_822E2654;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E2638:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e2654
	if (!cr6.lt) goto loc_822E2654;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e2638
	if (cr6.lt) goto loc_822E2638;
loc_822E2654:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f31,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	f31.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f11,f3,f0,f11
	ctx.f11.f64 = double(float(ctx.f3.f64 * f0.f64 + ctx.f11.f64));
	// lfs f10,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f2,f0,f31
	ctx.f9.f64 = double(float(ctx.f2.f64 * f0.f64 + f31.f64));
	// lfs f8,-68(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -68);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f10,f0,f5
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f5.f64));
	// fmadds f6,f8,f0,f4
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f4.f64));
	// stfs f11,0(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f9,84(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f7,88(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f6,92(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// blt cr6,0x822e25f4
	if (cr6.lt) goto loc_822E25F4;
	// stfs f12,96(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// addi r6,r3,96
	ctx.r6.s64 = ctx.r3.s64 + 96;
	// stfs f12,100(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stfs f12,104(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// addi r10,r3,312
	ctx.r10.s64 = ctx.r3.s64 + 312;
	// stfs f12,108(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
loc_822E2730:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e2744
	if (cr6.eq) goto loc_822E2744;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e2748
	goto loc_822E2748;
loc_822E2744:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E2748:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e2790
	if (!cr6.gt) goto loc_822E2790;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E2774:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e2790
	if (!cr6.lt) goto loc_822E2790;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e2774
	if (cr6.lt) goto loc_822E2774;
loc_822E2790:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f31,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	f31.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// lfs f5,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f4.f64 = double(temp.f32);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-60(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-56(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-64(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-52(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lfs f5,104(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,108(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f4.f64 = double(temp.f32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f11,f0,f3,f11
	ctx.f11.f64 = double(float(f0.f64 * ctx.f3.f64 + ctx.f11.f64));
	// lfs f10,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f0,f2,f31
	ctx.f9.f64 = double(float(f0.f64 * ctx.f2.f64 + f31.f64));
	// lfs f8,-68(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -68);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f0,f10,f5
	ctx.f7.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f5.f64));
	// fmadds f6,f0,f8,f4
	ctx.f6.f64 = double(float(f0.f64 * ctx.f8.f64 + ctx.f4.f64));
	// stfs f11,0(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f9,100(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f7,104(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f6,108(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// blt cr6,0x822e2730
	if (cr6.lt) goto loc_822E2730;
	// addi r10,r3,472
	ctx.r10.s64 = ctx.r3.s64 + 472;
	// stfs f12,112(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_822E2860:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e2874
	if (cr6.eq) goto loc_822E2874;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e2878
	goto loc_822E2878;
loc_822E2874:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E2878:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// add r8,r11,r6
	ctx.r8.u64 = r11.u64 + ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// lfsx f0,r8,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e28c0
	if (!cr6.gt) goto loc_822E28C0;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
loc_822E28A4:
	// lfs f11,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e28c0
	if (!cr6.lt) goto loc_822E28C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x822e28a4
	if (cr6.lt) goto loc_822E28A4;
loc_822E28C0:
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,112(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-60(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-64(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f0,f5,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfs f4,112(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// blt cr6,0x822e2860
	if (cr6.lt) goto loc_822E2860;
	// stfs f12,116(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
loc_822E2958:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e296c
	if (cr6.eq) goto loc_822E296C;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e2970
	goto loc_822E2970;
loc_822E296C:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E2970:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e29b8
	if (!cr6.gt) goto loc_822E29B8;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E299C:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e29b8
	if (!cr6.lt) goto loc_822E29B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e299c
	if (cr6.lt) goto loc_822E299C;
loc_822E29B8:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,116(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f10,f9,f8
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f0,f5,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfs f4,116(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// blt cr6,0x822e2958
	if (cr6.lt) goto loc_822E2958;
	// stfs f12,120(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r3,632
	ctx.r10.s64 = ctx.r3.s64 + 632;
loc_822E2A54:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e2a68
	if (cr6.eq) goto loc_822E2A68;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e2a6c
	goto loc_822E2A6C;
loc_822E2A68:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E2A6C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e2ab4
	if (!cr6.gt) goto loc_822E2AB4;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E2A98:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e2ab4
	if (!cr6.lt) goto loc_822E2AB4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e2a98
	if (cr6.lt) goto loc_822E2A98;
loc_822E2AB4:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f0,f5,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfs f4,120(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// blt cr6,0x822e2a54
	if (cr6.lt) goto loc_822E2A54;
	// stfs f12,124(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r3,792
	ctx.r10.s64 = ctx.r3.s64 + 792;
loc_822E2B50:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e2b64
	if (cr6.eq) goto loc_822E2B64;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e2b68
	goto loc_822E2B68;
loc_822E2B64:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E2B68:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e2bb0
	if (!cr6.gt) goto loc_822E2BB0;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E2B94:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e2bb0
	if (!cr6.lt) goto loc_822E2BB0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e2b94
	if (cr6.lt) goto loc_822E2B94;
loc_822E2BB0:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f2,124(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	ctx.f2.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f12,f10,f11,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f12,-64(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f10,f8,f11,f7
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f10,-60(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f9,f6,f11,f5
	ctx.f9.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f9,-56(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f8,f4,f11,f3
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f8,-52(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f0,f7,f2
	ctx.f6.f64 = double(float(f0.f64 * ctx.f7.f64 + ctx.f2.f64));
	// stfs f6,124(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// blt cr6,0x822e2b50
	if (cr6.lt) goto loc_822E2B50;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E2C48"))) PPC_WEAK_FUNC(sub_822E2C48);
PPC_FUNC_IMPL(__imp__sub_822E2C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x822E2C50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822e06e0
	ctx.lr = 0x822E2C5C;
	sub_822E06E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r11,-8556
	ctx.r3.s64 = r11.s64 + -8556;
	// lfs f12,-32032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32032);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	ctx.f11.f64 = double(temp.f32);
	// addi r29,r31,128
	r29.s64 = r31.s64 + 128;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stfs f13,92(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// li r30,3
	r30.s64 = 3;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lfs f13,32308(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,29500(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 29500);
	ctx.f9.f64 = double(temp.f32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f11,112(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,116(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f10,120(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f9,124(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
loc_822E2CD8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E2CE0;
	sub_82495CF0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,40
	r29.s64 = r29.s64 + 40;
	// bge 0x822e2cd8
	if (!cr0.lt) goto loc_822E2CD8;
	// addi r29,r31,288
	r29.s64 = r31.s64 + 288;
	// li r30,3
	r30.s64 = 3;
loc_822E2CF4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E2CFC;
	sub_82495CF0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,40
	r29.s64 = r29.s64 + 40;
	// bge 0x822e2cf4
	if (!cr0.lt) goto loc_822E2CF4;
	// addi r30,r31,448
	r30.s64 = r31.s64 + 448;
	// li r29,3
	r29.s64 = 3;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_822E2D14:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E2D1C;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e2d14
	if (!cr0.lt) goto loc_822E2D14;
	// addi r28,r31,608
	r28.s64 = r31.s64 + 608;
	// li r29,3
	r29.s64 = 3;
loc_822E2D30:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E2D38;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e2d30
	if (!cr0.lt) goto loc_822E2D30;
	// addi r28,r31,768
	r28.s64 = r31.s64 + 768;
	// li r29,3
	r29.s64 = 3;
loc_822E2D4C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E2D54;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e2d4c
	if (!cr0.lt) goto loc_822E2D4C;
	// li r29,4
	r29.s64 = 4;
loc_822E2D64:
	// addi r28,r30,-160
	r28.s64 = r30.s64 + -160;
	// addi r3,r28,-160
	ctx.r3.s64 = r28.s64 + -160;
	// bl 0x82496ed8
	ctx.lr = 0x822E2D70;
	sub_82496ED8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E2D78;
	sub_82496ED8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E2D80;
	sub_82496ED8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E2D88;
	sub_82496ED8(ctx, base);
	// addi r3,r30,160
	ctx.r3.s64 = r30.s64 + 160;
	// bl 0x82496ed8
	ctx.lr = 0x822E2D90;
	sub_82496ED8(ctx, base);
	// addi r3,r30,320
	ctx.r3.s64 = r30.s64 + 320;
	// bl 0x82496ed8
	ctx.lr = 0x822E2D98;
	sub_82496ED8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// bne 0x822e2d64
	if (!cr0.eq) goto loc_822E2D64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E2DB0"))) PPC_WEAK_FUNC(sub_822E2DB0);
PPC_FUNC_IMPL(__imp__sub_822E2DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11380(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11380);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E2DBC"))) PPC_WEAK_FUNC(sub_822E2DBC);
PPC_FUNC_IMPL(__imp__sub_822E2DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E2DC0"))) PPC_WEAK_FUNC(sub_822E2DC0);
PPC_FUNC_IMPL(__imp__sub_822E2DC0) {
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
	ctx.lr = 0x822E2DC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,3
	r30.s64 = 3;
	// addi r29,r28,160
	r29.s64 = r28.s64 + 160;
	// addi r31,r29,768
	r31.s64 = r29.s64 + 768;
loc_822E2DDC:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E2DE8;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e2ddc
	if (!cr0.lt) goto loc_822E2DDC;
	// addi r31,r29,608
	r31.s64 = r29.s64 + 608;
	// li r30,3
	r30.s64 = 3;
loc_822E2DF8:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E2E04;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e2df8
	if (!cr0.lt) goto loc_822E2DF8;
	// addi r31,r29,448
	r31.s64 = r29.s64 + 448;
	// li r30,3
	r30.s64 = 3;
loc_822E2E14:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E2E20;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e2e14
	if (!cr0.lt) goto loc_822E2E14;
	// addi r31,r29,288
	r31.s64 = r29.s64 + 288;
	// li r30,3
	r30.s64 = 3;
loc_822E2E30:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E2E3C;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e2e30
	if (!cr0.lt) goto loc_822E2E30;
	// addi r31,r29,128
	r31.s64 = r29.s64 + 128;
	// li r30,3
	r30.s64 = 3;
loc_822E2E4C:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E2E58;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e2e4c
	if (!cr0.lt) goto loc_822E2E4C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-9408
	ctx.r9.s64 = r11.s64 + -9408;
	// addi r8,r10,-9420
	ctx.r8.s64 = ctx.r10.s64 + -9420;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// addi r11,r28,48
	r11.s64 = r28.s64 + 48;
	// stw r8,48(r28)
	PPC_STORE_U32(r28.u32 + 48, ctx.r8.u32);
	// lhz r7,58(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 58);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e2e90
	if (cr6.eq) goto loc_822E2E90;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822E2E90;
	sub_82130588(ctx, base);
loc_822E2E90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E2E98"))) PPC_WEAK_FUNC(sub_822E2E98);
PPC_FUNC_IMPL(__imp__sub_822E2E98) {
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
	// li r3,928
	ctx.r3.s64 = 928;
	// bl 0x82130528
	ctx.lr = 0x822E2EAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e2ec8
	if (cr6.eq) goto loc_822E2EC8;
	// bl 0x822e2c48
	ctx.lr = 0x822E2EB8;
	sub_822E2C48(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E2EC8:
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

__attribute__((alias("__imp__sub_822E2EDC"))) PPC_WEAK_FUNC(sub_822E2EDC);
PPC_FUNC_IMPL(__imp__sub_822E2EDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E2EE0"))) PPC_WEAK_FUNC(sub_822E2EE0);
PPC_FUNC_IMPL(__imp__sub_822E2EE0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-11380
	r31.s64 = r11.s64 + -11380;
	// lwz r11,-11380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e30e0
	if (!cr6.eq) goto loc_822E30E0;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822E2F10;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e2f24
	if (cr6.eq) goto loc_822E2F24;
	// bl 0x821d5408
	ctx.lr = 0x822E2F20;
	sub_821D5408(ctx, base);
	// b 0x822e2f28
	goto loc_822E2F28;
loc_822E2F24:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822E2F28:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12444
	ctx.r7.s64 = ctx.r10.s64 + -12444;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,928
	ctx.r5.s64 = 928;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,11928
	ctx.r4.s64 = ctx.r8.s64 + 11928;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,5740
	ctx.r9.s64 = ctx.r3.s64 + 5740;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,128
	ctx.r10.s64 = 128;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e2fa4
	if (!cr6.eq) goto loc_822E2FA4;
	// bl 0x824970b0
	ctx.lr = 0x822E2FA0;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E2FA4:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,5524
	ctx.r8.s64 = ctx.r10.s64 + 5524;
	// addi r7,r9,5788
	ctx.r7.s64 = ctx.r9.s64 + 5788;
	// li r10,288
	ctx.r10.s64 = 288;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e2fd0
	if (!cr6.eq) goto loc_822E2FD0;
	// bl 0x824970b0
	ctx.lr = 0x822E2FCC;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E2FD0:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,5560
	ctx.r8.s64 = ctx.r10.s64 + 5560;
	// addi r7,r9,5836
	ctx.r7.s64 = ctx.r9.s64 + 5836;
	// li r10,448
	ctx.r10.s64 = 448;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e2ffc
	if (!cr6.eq) goto loc_822E2FFC;
	// bl 0x824970b0
	ctx.lr = 0x822E2FF8;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E2FFC:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,5596
	ctx.r8.s64 = ctx.r10.s64 + 5596;
	// addi r7,r9,5884
	ctx.r7.s64 = ctx.r9.s64 + 5884;
	// li r10,608
	ctx.r10.s64 = 608;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e3028
	if (!cr6.eq) goto loc_822E3028;
	// bl 0x824970b0
	ctx.lr = 0x822E3024;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E3028:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,5632
	ctx.r8.s64 = ctx.r10.s64 + 5632;
	// addi r7,r9,5932
	ctx.r7.s64 = ctx.r9.s64 + 5932;
	// li r10,768
	ctx.r10.s64 = 768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e3054
	if (!cr6.eq) goto loc_822E3054;
	// bl 0x824970b0
	ctx.lr = 0x822E3050;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E3054:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r10,5668
	ctx.r9.s64 = ctx.r10.s64 + 5668;
	// lwz r4,-11720(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bne cr6,0x822e3078
	if (!cr6.eq) goto loc_822E3078;
	// bl 0x822e0f60
	ctx.lr = 0x822E3074;
	sub_822E0F60(ctx, base);
	// lwz r4,-11720(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -11720);
loc_822E3078:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x822E3084;
	sub_821D4458(ctx, base);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x822E309C;
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
	ctx.lr = 0x822E30B8;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,5704
	ctx.r4.s64 = ctx.r8.s64 + 5704;
	// bl 0x821d4b00
	ctx.lr = 0x822E30C8;
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
	ctx.lr = 0x822E30E0;
	sub_821C0548(ctx, base);
loc_822E30E0:
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

__attribute__((alias("__imp__sub_822E30F8"))) PPC_WEAK_FUNC(sub_822E30F8);
PPC_FUNC_IMPL(__imp__sub_822E30F8) {
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
	// bl 0x822e2dc0
	ctx.lr = 0x822E3118;
	sub_822E2DC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e3130
	if (cr6.eq) goto loc_822E3130;
	// bl 0x82130588
	ctx.lr = 0x822E312C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E3130:
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

__attribute__((alias("__imp__sub_822E3148"))) PPC_WEAK_FUNC(sub_822E3148);
PPC_FUNC_IMPL(__imp__sub_822E3148) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltisw v13,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,6288
	ctx.r9.s64 = r11.s64 + 6288;
	// addi r8,r10,-9744
	ctx.r8.s64 = ctx.r10.s64 + -9744;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r3,r7,6540
	ctx.r3.s64 = ctx.r7.s64 + 6540;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lfs f0,6540(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6540);
	f0.f64 = double(temp.f32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// stfs f0,22272(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 22272, temp.u32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f9,7444(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// addi r7,r6,22272
	ctx.r7.s64 = ctx.r6.s64 + 22272;
	// lfs f12,-9756(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9756);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lfs f0,6284(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6284);
	f0.f64 = double(temp.f32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// lis r3,-32119
	ctx.r3.s64 = -2104950784;
	// stfs f13,4(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// addi r10,r5,22288
	ctx.r10.s64 = ctx.r5.s64 + 22288;
	// lfs f11,6276(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 6276);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,6280(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 6280);
	ctx.f10.f64 = double(temp.f32);
	// stfs f12,-17440(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + -17440, temp.u32);
	// stfs f11,22252(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 22252, temp.u32);
	// stfs f10,-17436(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + -17436, temp.u32);
	// stvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x822e31f8
	if (!cr6.lt) goto loc_822E31F8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f0,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// stfs f0,6284(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 6284, temp.u32);
	// stfs f0,22256(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 22256, temp.u32);
	// blr 
	return;
loc_822E31F8:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f0,22256(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 22256, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E3204"))) PPC_WEAK_FUNC(sub_822E3204);
PPC_FUNC_IMPL(__imp__sub_822E3204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E3208"))) PPC_WEAK_FUNC(sub_822E3208);
PPC_FUNC_IMPL(__imp__sub_822E3208) {
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
	ctx.lr = 0x822E3210;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r7,-8608
	r30.s64 = ctx.r7.s64 + -8608;
	// addi r29,r8,-9408
	r29.s64 = ctx.r8.s64 + -9408;
	// addi r28,r9,-9568
	r28.s64 = ctx.r9.s64 + -9568;
	// addi r27,r10,-9248
	r27.s64 = ctx.r10.s64 + -9248;
	// addi r26,r11,-8288
	r26.s64 = r11.s64 + -8288;
loc_822E3240:
	// add r3,r31,r26
	ctx.r3.u64 = r31.u64 + r26.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E3248;
	sub_82496ED8(ctx, base);
	// add r3,r31,r27
	ctx.r3.u64 = r31.u64 + r27.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E3250;
	sub_82496ED8(ctx, base);
	// add r3,r31,r28
	ctx.r3.u64 = r31.u64 + r28.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E3258;
	sub_82496ED8(ctx, base);
	// add r3,r31,r29
	ctx.r3.u64 = r31.u64 + r29.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E3260;
	sub_82496ED8(ctx, base);
	// add r3,r31,r30
	ctx.r3.u64 = r31.u64 + r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E3268;
	sub_82496ED8(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// cmpwi cr6,r31,160
	cr6.compare<int32_t>(r31.s32, 160, xer);
	// blt cr6,0x822e3240
	if (cr6.lt) goto loc_822E3240;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r7,-9728
	r30.s64 = ctx.r7.s64 + -9728;
	// addi r29,r8,-8928
	r29.s64 = ctx.r8.s64 + -8928;
	// addi r28,r9,-9088
	r28.s64 = ctx.r9.s64 + -9088;
	// addi r27,r10,-8448
	r27.s64 = ctx.r10.s64 + -8448;
	// addi r26,r11,-8768
	r26.s64 = r11.s64 + -8768;
loc_822E32A0:
	// add r3,r31,r26
	ctx.r3.u64 = r31.u64 + r26.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E32A8;
	sub_82496ED8(ctx, base);
	// add r3,r31,r27
	ctx.r3.u64 = r31.u64 + r27.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E32B0;
	sub_82496ED8(ctx, base);
	// add r3,r31,r28
	ctx.r3.u64 = r31.u64 + r28.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E32B8;
	sub_82496ED8(ctx, base);
	// add r3,r31,r29
	ctx.r3.u64 = r31.u64 + r29.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E32C0;
	sub_82496ED8(ctx, base);
	// add r3,r31,r30
	ctx.r3.u64 = r31.u64 + r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E32C8;
	sub_82496ED8(ctx, base);
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// cmpwi cr6,r31,160
	cr6.compare<int32_t>(r31.s32, 160, xer);
	// blt cr6,0x822e32a0
	if (cr6.lt) goto loc_822E32A0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822E32DC"))) PPC_WEAK_FUNC(sub_822E32DC);
PPC_FUNC_IMPL(__imp__sub_822E32DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E32E0"))) PPC_WEAK_FUNC(sub_822E32E0);
PPC_FUNC_IMPL(__imp__sub_822E32E0) {
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
	// bl 0x823d91fc
	ctx.lr = 0x822E32E8;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822E3300;
	sub_822F10D0(ctx, base);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// lbzx r30,r9,r10
	r30.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// lwz r31,22080(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 22080);
	// lwz r3,-17936(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17936);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// bne cr6,0x822e332c
	if (!cr6.eq) goto loc_822E332C;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_822E332C:
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,6976
	ctx.r10.s64 = ctx.r9.s64 + 6976;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,-9744
	ctx.r7.s64 = r11.s64 + -9744;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfsx f9,r4,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	ctx.f9.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-8768
	ctx.r5.s64 = r11.s64 + -8768;
	// lfs f10,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// lfs f11,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmr f13,f10
	ctx.f13.f64 = ctx.f10.f64;
	// fmr f12,f10
	ctx.f12.f64 = ctx.f10.f64;
	// stfs f0,0(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f13,4(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
	// stfs f12,8(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// fdivs f9,f11,f9
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f9.f64));
	// addi r4,r11,6928
	ctx.r4.s64 = r11.s64 + 6928;
loc_822E3388:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e3398
	if (!cr6.eq) goto loc_822E3398;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E3398:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r6
	ctx.r9.u64 = r11.u64 + ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f11,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// ble cr6,0x822e33e0
	if (!cr6.gt) goto loc_822E33E0;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E33C4:
	// lfs f8,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f8,f1
	cr6.compare(ctx.f8.f64, ctx.f1.f64);
	// bge cr6,0x822e33e0
	if (!cr6.lt) goto loc_822E33E0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e33c4
	if (cr6.lt) goto loc_822E33C4;
loc_822E33E0:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f8,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f1,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 - ctx.f8.f64));
	// lfs f5,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f6,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f8,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f31,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f31.f64 = double(temp.f32);
	// lfs f30,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f30.f64 = double(temp.f32);
	// fmadds f6,f6,f7,f5
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f7.f64 + ctx.f5.f64));
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f5,f4,f7,f3
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f7.f64 + ctx.f3.f64));
	// stfs f5,100(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f4,f2,f7,f8
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f7.f64 + ctx.f8.f64));
	// stfs f4,104(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f3,f31,f7,f30
	ctx.f3.f64 = double(float(f31.f64 * ctx.f7.f64 + f30.f64));
	// stfs f3,108(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f0,f2,f11,f0
	f0.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + f0.f64));
	// lfs f7,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f13,f8,f11,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fmadds f12,f7,f11,f12
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f0,0(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f13,4(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f12,8(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// blt cr6,0x822e3388
	if (cr6.lt) goto loc_822E3388;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// fmr f13,f10
	ctx.f13.f64 = ctx.f10.f64;
	// addi r6,r10,6540
	ctx.r6.s64 = ctx.r10.s64 + 6540;
	// addi r5,r11,-8448
	ctx.r5.s64 = r11.s64 + -8448;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f13,4(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
loc_822E34B0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e34c0
	if (!cr6.eq) goto loc_822E34C0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E34C0:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f12,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f9
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// ble cr6,0x822e3508
	if (!cr6.gt) goto loc_822E3508;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E34EC:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e3508
	if (!cr6.lt) goto loc_822E3508;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e34ec
	if (cr6.lt) goto loc_822E34EC;
loc_822E3508:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f1,f11
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f6,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f5,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// lfs f31,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f31.f64 = double(temp.f32);
	// fmadds f7,f8,f7,f6
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f6,f5,f8,f4
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f8.f64 + ctx.f4.f64));
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f5,f3,f8,f2
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f8.f64 + ctx.f2.f64));
	// stfs f5,104(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f4,f11,f8,f31
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 + f31.f64));
	// stfs f4,108(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f0,f12,f3,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f3.f64 + f0.f64));
	// fmadds f13,f12,f2,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f2.f64 + ctx.f13.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f13,4(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// blt cr6,0x822e34b0
	if (cr6.lt) goto loc_822E34B0;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-9088
	ctx.r6.s64 = r11.s64 + -9088;
	// stfs f0,-9756(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -9756, temp.u32);
	// addi r10,r6,24
	ctx.r10.s64 = ctx.r6.s64 + 24;
loc_822E35C0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e35d0
	if (!cr6.eq) goto loc_822E35D0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E35D0:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// ble cr6,0x822e3618
	if (!cr6.gt) goto loc_822E3618;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E35FC:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e3618
	if (!cr6.lt) goto loc_822E3618;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e35fc
	if (cr6.lt) goto loc_822E35FC;
loc_822E3618:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r6,184
	r29.s64 = ctx.r6.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f8,f11,f7
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f7,f6,f11,f5
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f6,f4,f11,f3
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f5,f2,f11,f12
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f13,f4,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + f0.f64));
	// stfs f0,-9756(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -9756, temp.u32);
	// blt cr6,0x822e35c0
	if (cr6.lt) goto loc_822E35C0;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-8928
	ctx.r6.s64 = r11.s64 + -8928;
	// stfs f0,6276(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 6276, temp.u32);
	// addi r10,r6,24
	ctx.r10.s64 = ctx.r6.s64 + 24;
loc_822E36C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e36d4
	if (!cr6.eq) goto loc_822E36D4;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E36D4:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// ble cr6,0x822e371c
	if (!cr6.gt) goto loc_822E371C;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E3700:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e371c
	if (!cr6.lt) goto loc_822E371C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e3700
	if (cr6.lt) goto loc_822E3700;
loc_822E371C:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r6,184
	r29.s64 = ctx.r6.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f8,f11,f7
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f7,f6,f11,f5
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f6,f4,f11,f3
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f5,f2,f11,f12
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f13,f4,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + f0.f64));
	// stfs f0,6276(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 6276, temp.u32);
	// blt cr6,0x822e36c4
	if (cr6.lt) goto loc_822E36C4;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-9728
	ctx.r5.s64 = r11.s64 + -9728;
	// stfs f0,6280(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6280, temp.u32);
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
loc_822E37C8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e37d8
	if (!cr6.eq) goto loc_822E37D8;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E37D8:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// ble cr6,0x822e3820
	if (!cr6.gt) goto loc_822E3820;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E3804:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e3820
	if (!cr6.lt) goto loc_822E3820;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e3804
	if (cr6.lt) goto loc_822E3804;
loc_822E3820:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f8,f11,f7
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f7,f6,f11,f5
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f6,f4,f11,f3
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f5,f2,f11,f12
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f0,f13,f4,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + f0.f64));
	// stfs f0,6280(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6280, temp.u32);
	// blt cr6,0x822e37c8
	if (cr6.lt) goto loc_822E37C8;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r5,24
	ctx.r10.s64 = ctx.r5.s64 + 24;
	// stfs f0,6284(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6284, temp.u32);
loc_822E38C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bne cr6,0x822e38d4
	if (!cr6.eq) goto loc_822E38D4;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822E38D4:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f13,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// ble cr6,0x822e391c
	if (!cr6.gt) goto loc_822E391C;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E3900:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e391c
	if (!cr6.lt) goto loc_822E391C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e3900
	if (cr6.lt) goto loc_822E3900;
loc_822E391C:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r5,184
	r29.s64 = ctx.r5.s64 + 184;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f12,f11,f10,f8
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f10,f7,f11,f6
	ctx.f10.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f6.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f8,f5,f11,f4
	ctx.f8.f64 = double(float(ctx.f5.f64 * ctx.f11.f64 + ctx.f4.f64));
	// stfs f8,104(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f7,f3,f11,f2
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f2.f64));
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f0,f13,f6,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + f0.f64));
	// stfs f0,6284(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6284, temp.u32);
	// blt cr6,0x822e38c4
	if (cr6.lt) goto loc_822E38C4;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E39BC"))) PPC_WEAK_FUNC(sub_822E39BC);
PPC_FUNC_IMPL(__imp__sub_822E39BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E39C0"))) PPC_WEAK_FUNC(sub_822E39C0);
PPC_FUNC_IMPL(__imp__sub_822E39C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r9,r11,-9744
	ctx.r9.s64 = r11.s64 + -9744;
	// addi r8,r1,28
	ctx.r8.s64 = ctx.r1.s64 + 28;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,6540
	ctx.r5.s64 = ctx.r7.s64 + 6540;
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lfs f0,6540(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6540);
	f0.f64 = double(temp.f32);
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f13,4(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9756(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -9756);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f11,6276(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 6276);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f10,6280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6280);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,6284(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 6284);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,100(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f3,f5,f1
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// fmuls f4,f6,f1
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// fadds f0,f3,f0
	f0.f64 = double(float(ctx.f3.f64 + f0.f64));
	// stfs f0,6540(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 6540, temp.u32);
	// fadds f13,f13,f4
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f4.f64));
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f2,104(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f0,f2,f12
	f0.f64 = double(float(ctx.f2.f64 - ctx.f12.f64));
	// fmadds f0,f0,f1,f12
	f0.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f0,-9756(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + -9756, temp.u32);
	// lfs f13,108(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fmadds f0,f12,f1,f11
	f0.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f0,6276(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 6276, temp.u32);
	// lfs f11,112(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmadds f0,f8,f1,f10
	f0.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f0,6280(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 6280, temp.u32);
	// lfs f7,116(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// fmadds f0,f6,f1,f9
	f0.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f9.f64));
	// stfs f0,6284(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6284, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E3A8C"))) PPC_WEAK_FUNC(sub_822E3A8C);
PPC_FUNC_IMPL(__imp__sub_822E3A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E3A90"))) PPC_WEAK_FUNC(sub_822E3A90);
PPC_FUNC_IMPL(__imp__sub_822E3A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x822E3A98;
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r16,r11,6912
	r16.s64 = r11.s64 + 6912;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r16
	r30.u64 = r16.u64;
	// addi r26,r5,-9728
	r26.s64 = ctx.r5.s64 + -9728;
	// addi r25,r4,-8928
	r25.s64 = ctx.r4.s64 + -8928;
	// addi r24,r3,-9088
	r24.s64 = ctx.r3.s64 + -9088;
	// addi r23,r28,-8448
	r23.s64 = r28.s64 + -8448;
	// addi r22,r6,-8768
	r22.s64 = ctx.r6.s64 + -8768;
	// addi r21,r7,-8104
	r21.s64 = ctx.r7.s64 + -8104;
	// addi r20,r8,-8124
	r20.s64 = ctx.r8.s64 + -8124;
	// addi r19,r9,-8152
	r19.s64 = ctx.r9.s64 + -8152;
	// addi r18,r10,-8164
	r18.s64 = ctx.r10.s64 + -8164;
	// addi r17,r11,-8184
	r17.s64 = r11.s64 + -8184;
loc_822E3B00:
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x822E3B10;
	sub_823DC018(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E3B20;
	sub_823DC018(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E3B30;
	sub_823DC018(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E3B40;
	sub_823DC018(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822E3B50;
	sub_823DC018(ctx, base);
	// lwzx r11,r31,r22
	r11.u64 = PPC_LOAD_U32(r31.u32 + r22.u32);
	// add r28,r31,r22
	r28.u64 = r31.u64 + r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E3B68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E3B78;
	sub_8261DDE8(ctx, base);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r27,r31,r23
	r27.u64 = r31.u64 + r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r28,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r28.u32);
	// lwzx r8,r31,r23
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r23.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822E3B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E3BA8;
	sub_8261DDE8(ctx, base);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r28,r31,r24
	r28.u64 = r31.u64 + r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r27.u32);
	// lwzx r5,r31,r24
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822E3BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E3BD8;
	sub_8261DDE8(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r27,r31,r25
	r27.u64 = r31.u64 + r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r28,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r28.u32);
	// lwzx r10,r31,r25
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r25.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E3BF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E3C08;
	sub_8261DDE8(ctx, base);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r28,r31,r26
	r28.u64 = r31.u64 + r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r27,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r27.u32);
	// lwzx r7,r31,r26
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822E3C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8261dde8
	ctx.lr = 0x822E3C38;
	sub_8261DDE8(ctx, base);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r31,r31,40
	r31.s64 = r31.s64 + 40;
	// addi r4,r16,16
	ctx.r4.s64 = r16.s64 + 16;
	// stw r28,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r28.u32);
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// blt cr6,0x822e3b00
	if (cr6.lt) goto loc_822E3B00;
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_822E3C5C"))) PPC_WEAK_FUNC(sub_822E3C5C);
PPC_FUNC_IMPL(__imp__sub_822E3C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E3C60"))) PPC_WEAK_FUNC(sub_822E3C60);
PPC_FUNC_IMPL(__imp__sub_822E3C60) {
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
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822E3C68;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// lwz r4,0(r13)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,72
	r31.s64 = 72;
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e3c90
	if (cr6.eq) goto loc_822E3C90;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e3c94
	goto loc_822E3C94;
loc_822E3C90:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E3C94:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r10,6976
	ctx.r8.s64 = ctx.r10.s64 + 6976;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r6,r3,80
	ctx.r6.s64 = ctx.r3.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f12,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfsx f13,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r3,144
	ctx.r10.s64 = ctx.r3.s64 + 144;
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r5,r11,6928
	ctx.r5.s64 = r11.s64 + 6928;
	// stfs f12,80(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,84(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f12,88(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
loc_822E3CD8:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e3cec
	if (cr6.eq) goto loc_822E3CEC;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e3cf0
	goto loc_822E3CF0;
loc_822E3CEC:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E3CF0:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e3d38
	if (!cr6.gt) goto loc_822E3D38;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E3D1C:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e3d38
	if (!cr6.lt) goto loc_822E3D38;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e3d1c
	if (cr6.lt) goto loc_822E3D1C;
loc_822E3D38:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f31,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	f31.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f2,f4,f0,f11
	ctx.f2.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f11.f64));
	// lfs f5,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f3,f0,f31
	ctx.f10.f64 = double(float(ctx.f3.f64 * f0.f64 + f31.f64));
	// fmadds f9,f11,f0,f5
	ctx.f9.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f5.f64));
	// stfs f2,0(r6)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f10,84(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f9,88(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blt cr6,0x822e3cd8
	if (cr6.lt) goto loc_822E3CD8;
	// stfs f12,96(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// addi r6,r3,96
	ctx.r6.s64 = ctx.r3.s64 + 96;
	// stfs f12,100(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r3,304
	ctx.r10.s64 = ctx.r3.s64 + 304;
loc_822E3DFC:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e3e10
	if (cr6.eq) goto loc_822E3E10;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e3e14
	goto loc_822E3E14;
loc_822E3E10:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E3E14:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r9,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e3e5c
	if (!cr6.gt) goto loc_822E3E5C;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E3E40:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e3e5c
	if (!cr6.lt) goto loc_822E3E5C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e3e40
	if (cr6.lt) goto loc_822E3E40;
loc_822E3E5C:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f31,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	f31.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f0,f5,f11
	ctx.f3.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// fmadds f2,f0,f4,f31
	ctx.f2.f64 = double(float(f0.f64 * ctx.f4.f64 + f31.f64));
	// stfs f3,0(r6)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f2,100(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// blt cr6,0x822e3dfc
	if (cr6.lt) goto loc_822E3DFC;
	// stfs f12,104(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r3,464
	ctx.r10.s64 = ctx.r3.s64 + 464;
loc_822E3F08:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e3f1c
	if (cr6.eq) goto loc_822E3F1C;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e3f20
	goto loc_822E3F20;
loc_822E3F1C:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E3F20:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e3f68
	if (!cr6.gt) goto loc_822E3F68;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E3F4C:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e3f68
	if (!cr6.lt) goto loc_822E3F68;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e3f4c
	if (cr6.lt) goto loc_822E3F4C;
loc_822E3F68:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,104(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f10,f9,f8
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f0,f5,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfs f4,104(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// blt cr6,0x822e3f08
	if (cr6.lt) goto loc_822E3F08;
	// stfs f12,108(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r10,r3,624
	ctx.r10.s64 = ctx.r3.s64 + 624;
loc_822E4004:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4018
	if (cr6.eq) goto loc_822E4018;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e401c
	goto loc_822E401C;
loc_822E4018:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E401C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e4064
	if (!cr6.gt) goto loc_822E4064;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E4048:
	// lfs f11,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e4064
	if (!cr6.lt) goto loc_822E4064;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e4048
	if (cr6.lt) goto loc_822E4048;
loc_822E4064:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,108(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f0,f5,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfs f4,108(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// blt cr6,0x822e4004
	if (cr6.lt) goto loc_822E4004;
	// addi r10,r3,784
	ctx.r10.s64 = ctx.r3.s64 + 784;
	// stfs f12,112(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_822E4104:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4118
	if (cr6.eq) goto loc_822E4118;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e411c
	goto loc_822E411C;
loc_822E4118:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E411C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// add r8,r11,r6
	ctx.r8.u64 = r11.u64 + ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// lfsx f0,r8,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e4164
	if (!cr6.gt) goto loc_822E4164;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
loc_822E4148:
	// lfs f11,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x822e4164
	if (!cr6.lt) goto loc_822E4164;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x822e4148
	if (cr6.lt) goto loc_822E4148;
loc_822E4164:
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r9,40
	ctx.r9.s64 = ctx.r9.s64 + 40;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,112(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f9,f10,f8
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,-64(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f8,f7,f10,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f7,f5,f10,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f7,-56(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f6,f3,f10,f2
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f2.f64));
	// stfs f6,-52(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f0,f5,f11
	ctx.f4.f64 = double(float(f0.f64 * ctx.f5.f64 + ctx.f11.f64));
	// stfs f4,112(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// blt cr6,0x822e4104
	if (cr6.lt) goto loc_822E4104;
	// stfs f12,116(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
loc_822E41FC:
	// lbzx r11,r31,r4
	r11.u64 = PPC_LOAD_U8(r31.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4210
	if (cr6.eq) goto loc_822E4210;
	// lwz r11,22080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// b 0x822e4214
	goto loc_822E4214;
loc_822E4210:
	// lwz r11,-17936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17936);
loc_822E4214:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// add r9,r11,r7
	ctx.r9.u64 = r11.u64 + ctx.r7.u64;
	// li r11,1
	r11.s64 = 1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// lfsx f0,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// ble cr6,0x822e425c
	if (!cr6.gt) goto loc_822E425C;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
loc_822E4240:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x822e425c
	if (!cr6.lt) goto loc_822E425C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e4240
	if (cr6.lt) goto loc_822E4240;
loc_822E425C:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f2,116(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f12,f10,f11,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f12,-64(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmadds f10,f8,f11,f7
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f10,-60(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmadds f9,f6,f11,f5
	ctx.f9.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f9,-56(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// fmadds f8,f4,f11,f3
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f8,-52(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f0,f7,f2
	ctx.f6.f64 = double(float(f0.f64 * ctx.f7.f64 + ctx.f2.f64));
	// stfs f6,116(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// blt cr6,0x822e41fc
	if (cr6.lt) goto loc_822E41FC;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E42F4"))) PPC_WEAK_FUNC(sub_822E42F4);
PPC_FUNC_IMPL(__imp__sub_822E42F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E42F8"))) PPC_WEAK_FUNC(sub_822E42F8);
PPC_FUNC_IMPL(__imp__sub_822E42F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x822E4300;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822e06e0
	ctx.lr = 0x822E430C;
	sub_822E06E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r5,r11,-8072
	ctx.r5.s64 = r11.s64 + -8072;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-8080(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8080);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r31,120
	r29.s64 = r31.s64 + 120;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// li r30,3
	r30.s64 = 3;
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lfs f12,-332(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -332);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-12736(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12736);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f12,108(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f11,112(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f10,116(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
loc_822E436C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E4374;
	sub_82495CF0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,40
	r29.s64 = r29.s64 + 40;
	// bge 0x822e436c
	if (!cr0.lt) goto loc_822E436C;
	// addi r30,r31,280
	r30.s64 = r31.s64 + 280;
	// li r29,3
	r29.s64 = 3;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_822E438C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E4394;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e438c
	if (!cr0.lt) goto loc_822E438C;
	// addi r28,r31,440
	r28.s64 = r31.s64 + 440;
	// li r29,3
	r29.s64 = 3;
loc_822E43A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E43B0;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e43a8
	if (!cr0.lt) goto loc_822E43A8;
	// addi r28,r31,600
	r28.s64 = r31.s64 + 600;
	// li r29,3
	r29.s64 = 3;
loc_822E43C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E43CC;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e43c4
	if (!cr0.lt) goto loc_822E43C4;
	// addi r28,r31,760
	r28.s64 = r31.s64 + 760;
	// li r29,3
	r29.s64 = 3;
loc_822E43E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822E43E8;
	sub_82495CF0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,40
	r28.s64 = r28.s64 + 40;
	// bge 0x822e43e0
	if (!cr0.lt) goto loc_822E43E0;
	// li r29,4
	r29.s64 = 4;
loc_822E43F8:
	// addi r3,r30,-160
	ctx.r3.s64 = r30.s64 + -160;
	// bl 0x82496ed8
	ctx.lr = 0x822E4400;
	sub_82496ED8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496ed8
	ctx.lr = 0x822E4408;
	sub_82496ED8(ctx, base);
	// addi r3,r30,160
	ctx.r3.s64 = r30.s64 + 160;
	// bl 0x82496ed8
	ctx.lr = 0x822E4410;
	sub_82496ED8(ctx, base);
	// addi r3,r30,320
	ctx.r3.s64 = r30.s64 + 320;
	// bl 0x82496ed8
	ctx.lr = 0x822E4418;
	sub_82496ED8(ctx, base);
	// addi r3,r30,480
	ctx.r3.s64 = r30.s64 + 480;
	// bl 0x82496ed8
	ctx.lr = 0x822E4420;
	sub_82496ED8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// bne 0x822e43f8
	if (!cr0.eq) goto loc_822E43F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E4438"))) PPC_WEAK_FUNC(sub_822E4438);
PPC_FUNC_IMPL(__imp__sub_822E4438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-9760(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9760);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E4444"))) PPC_WEAK_FUNC(sub_822E4444);
PPC_FUNC_IMPL(__imp__sub_822E4444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E4448"))) PPC_WEAK_FUNC(sub_822E4448);
PPC_FUNC_IMPL(__imp__sub_822E4448) {
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
	ctx.lr = 0x822E4450;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,3
	r30.s64 = 3;
	// addi r31,r29,920
	r31.s64 = r29.s64 + 920;
loc_822E4460:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E446C;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e4460
	if (!cr0.lt) goto loc_822E4460;
	// addi r31,r29,760
	r31.s64 = r29.s64 + 760;
	// li r30,3
	r30.s64 = 3;
loc_822E447C:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E4488;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e447c
	if (!cr0.lt) goto loc_822E447C;
	// addi r31,r29,600
	r31.s64 = r29.s64 + 600;
	// li r30,3
	r30.s64 = 3;
loc_822E4498:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E44A4;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e4498
	if (!cr0.lt) goto loc_822E4498;
	// addi r31,r29,440
	r31.s64 = r29.s64 + 440;
	// li r30,3
	r30.s64 = 3;
loc_822E44B4:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E44C0;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e44b4
	if (!cr0.lt) goto loc_822E44B4;
	// addi r31,r29,280
	r31.s64 = r29.s64 + 280;
	// li r30,3
	r30.s64 = 3;
loc_822E44D0:
	// addi r31,r31,-40
	r31.s64 = r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82495d58
	ctx.lr = 0x822E44DC;
	sub_82495D58(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822e44d0
	if (!cr0.lt) goto loc_822E44D0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-9408
	ctx.r9.s64 = r11.s64 + -9408;
	// addi r8,r10,-9420
	ctx.r8.s64 = ctx.r10.s64 + -9420;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// addi r11,r29,48
	r11.s64 = r29.s64 + 48;
	// stw r8,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r8.u32);
	// lhz r7,58(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 58);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e4514
	if (cr6.eq) goto loc_822E4514;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822E4514;
	sub_82130588(ctx, base);
loc_822E4514:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E451C"))) PPC_WEAK_FUNC(sub_822E451C);
PPC_FUNC_IMPL(__imp__sub_822E451C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E4520"))) PPC_WEAK_FUNC(sub_822E4520);
PPC_FUNC_IMPL(__imp__sub_822E4520) {
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
	// li r3,928
	ctx.r3.s64 = 928;
	// bl 0x82130528
	ctx.lr = 0x822E4534;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e4550
	if (cr6.eq) goto loc_822E4550;
	// bl 0x822e42f8
	ctx.lr = 0x822E4540;
	sub_822E42F8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E4550:
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

__attribute__((alias("__imp__sub_822E4564"))) PPC_WEAK_FUNC(sub_822E4564);
PPC_FUNC_IMPL(__imp__sub_822E4564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E4568"))) PPC_WEAK_FUNC(sub_822E4568);
PPC_FUNC_IMPL(__imp__sub_822E4568) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-9760
	r31.s64 = r11.s64 + -9760;
	// lwz r11,-9760(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9760);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4768
	if (!cr6.eq) goto loc_822E4768;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822E4598;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e45ac
	if (cr6.eq) goto loc_822E45AC;
	// bl 0x821d5408
	ctx.lr = 0x822E45A8;
	sub_821D5408(ctx, base);
	// b 0x822e45b0
	goto loc_822E45B0;
loc_822E45AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822E45B0:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12464
	ctx.r7.s64 = ctx.r10.s64 + -12464;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,928
	ctx.r5.s64 = 928;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,17696
	ctx.r4.s64 = ctx.r8.s64 + 17696;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,6292
	ctx.r9.s64 = ctx.r3.s64 + 6292;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,120
	ctx.r10.s64 = 120;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e462c
	if (!cr6.eq) goto loc_822E462C;
	// bl 0x824970b0
	ctx.lr = 0x822E4628;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E462C:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,6072
	ctx.r8.s64 = ctx.r10.s64 + 6072;
	// addi r7,r9,6340
	ctx.r7.s64 = ctx.r9.s64 + 6340;
	// li r10,280
	ctx.r10.s64 = 280;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e4658
	if (!cr6.eq) goto loc_822E4658;
	// bl 0x824970b0
	ctx.lr = 0x822E4654;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E4658:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,6108
	ctx.r8.s64 = ctx.r10.s64 + 6108;
	// addi r7,r9,6388
	ctx.r7.s64 = ctx.r9.s64 + 6388;
	// li r10,440
	ctx.r10.s64 = 440;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e4684
	if (!cr6.eq) goto loc_822E4684;
	// bl 0x824970b0
	ctx.lr = 0x822E4680;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E4684:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,6144
	ctx.r8.s64 = ctx.r10.s64 + 6144;
	// addi r7,r9,6436
	ctx.r7.s64 = ctx.r9.s64 + 6436;
	// li r10,600
	ctx.r10.s64 = 600;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e46b0
	if (!cr6.eq) goto loc_822E46B0;
	// bl 0x824970b0
	ctx.lr = 0x822E46AC;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E46B0:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r10,6180
	ctx.r8.s64 = ctx.r10.s64 + 6180;
	// addi r7,r9,6484
	ctx.r7.s64 = ctx.r9.s64 + 6484;
	// li r10,760
	ctx.r10.s64 = 760;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822e46dc
	if (!cr6.eq) goto loc_822E46DC;
	// bl 0x824970b0
	ctx.lr = 0x822E46D8;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20464);
loc_822E46DC:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r10,6216
	ctx.r9.s64 = ctx.r10.s64 + 6216;
	// lwz r4,-11720(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bne cr6,0x822e4700
	if (!cr6.eq) goto loc_822E4700;
	// bl 0x822e0f60
	ctx.lr = 0x822E46FC;
	sub_822E0F60(ctx, base);
	// lwz r4,-11720(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -11720);
loc_822E4700:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x822E470C;
	sub_821D4458(ctx, base);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x822E4724;
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
	ctx.lr = 0x822E4740;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,6252
	ctx.r4.s64 = ctx.r8.s64 + 6252;
	// bl 0x821d4b00
	ctx.lr = 0x822E4750;
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
	ctx.lr = 0x822E4768;
	sub_821C0548(ctx, base);
loc_822E4768:
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

__attribute__((alias("__imp__sub_822E4780"))) PPC_WEAK_FUNC(sub_822E4780);
PPC_FUNC_IMPL(__imp__sub_822E4780) {
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
	// bl 0x822e4448
	ctx.lr = 0x822E47A0;
	sub_822E4448(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e47b8
	if (cr6.eq) goto loc_822E47B8;
	// bl 0x82130588
	ctx.lr = 0x822E47B4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E47B8:
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

__attribute__((alias("__imp__sub_822E47D0"))) PPC_WEAK_FUNC(sub_822E47D0);
PPC_FUNC_IMPL(__imp__sub_822E47D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E47DC"))) PPC_WEAK_FUNC(sub_822E47DC);
PPC_FUNC_IMPL(__imp__sub_822E47DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E47E0"))) PPC_WEAK_FUNC(sub_822E47E0);
PPC_FUNC_IMPL(__imp__sub_822E47E0) {
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
	ctx.lr = 0x822E47E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,32
	ctx.r10.s64 = 32;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822E4804:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822e4804
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822E4804;
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,13
	ctx.r10.s64 = 13;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822E4820:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822e4820
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822E4820;
	// li r11,2
	r11.s64 = 2;
	// stw r11,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r11.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r10.u32);
	// li r28,1
	r28.s64 = 1;
	// stb r28,368(r31)
	PPC_STORE_U8(r31.u32 + 368, r28.u8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r30,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r30.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// stw r30,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r30.u32);
	// stw r30,444(r31)
	PPC_STORE_U32(r31.u32 + 444, r30.u32);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lfs f0,31016(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// stfs f0,440(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 440, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r4,r5,-8004
	ctx.r4.s64 = ctx.r5.s64 + -8004;
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,320(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 320, temp.u32);
	// stfs f13,324(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
	// stfs f0,328(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 328, temp.u32);
	// stfs f0,332(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 332, temp.u32);
	// stfs f0,336(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stfs f0,340(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// stfs f0,344(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stb r30,393(r31)
	PPC_STORE_U8(r31.u32 + 393, r30.u8);
	// stb r30,435(r31)
	PPC_STORE_U8(r31.u32 + 435, r30.u8);
	// stw r30,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r30.u32);
	// stw r30,412(r31)
	PPC_STORE_U32(r31.u32 + 412, r30.u32);
	// lwz r11,17012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17012);
	// stw r11,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r11.u32);
	// lwz r11,17016(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17016);
	// stw r11,420(r31)
	PPC_STORE_U32(r31.u32 + 420, r11.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e48e4
	if (cr6.eq) goto loc_822E48E4;
	// li r11,640
	r11.s64 = 640;
	// stw r8,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r8.u32);
	// li r7,480
	ctx.r7.s64 = 480;
	// stw r11,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r11.u32);
	// stw r7,420(r31)
	PPC_STORE_U32(r31.u32 + 420, ctx.r7.u32);
loc_822E48E4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r7,r11,-8044
	ctx.r7.s64 = r11.s64 + -8044;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e490c
	if (cr6.eq) goto loc_822E490C;
	// stw r8,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r8.u32);
	// li r11,960
	r11.s64 = 960;
	// li r8,720
	ctx.r8.s64 = 720;
	// stw r11,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r11.u32);
	// stw r8,420(r31)
	PPC_STORE_U32(r31.u32 + 420, ctx.r8.u32);
loc_822E490C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r8,r11,-7964
	ctx.r8.s64 = r11.s64 + -7964;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4994
	if (!cr6.eq) goto loc_822E4994;
	// lwz r10,17012(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17012);
	// lis r29,157
	r29.s64 = 10289152;
	// ori r29,r29,32768
	r29.u64 = r29.u64 | 32768;
	// cmpwi cr6,r10,720
	cr6.compare<int32_t>(ctx.r10.s32, 720, xer);
	// bgt cr6,0x822e4950
	if (cr6.gt) goto loc_822E4950;
	// lwz r11,17016(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17016);
	// cmpwi cr6,r11,576
	cr6.compare<int32_t>(r11.s32, 576, xer);
	// bgt cr6,0x822e4950
	if (cr6.gt) goto loc_822E4950;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// addis r10,r11,16
	ctx.r10.s64 = r11.s64 + 1048576;
	// addi r10,r10,11264
	ctx.r10.s64 = ctx.r10.s64 + 11264;
	// rlwinm r29,r10,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
loc_822E4950:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822E4958;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e498c
	if (cr6.eq) goto loc_822E498C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r11,-6864
	ctx.r4.s64 = r11.s64 + -6864;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4096
	ctx.r7.s64 = 4096;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821851c8
	ctx.lr = 0x822E4988;
	sub_821851C8(ctx, base);
	// b 0x822e4990
	goto loc_822E4990;
loc_822E498C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822E4990:
	// stw r3,436(r31)
	PPC_STORE_U32(r31.u32 + 436, ctx.r3.u32);
loc_822E4994:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r29,r11,-7924
	r29.s64 = r11.s64 + -7924;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e49b4
	if (cr6.eq) goto loc_822E49B4;
	// lis r11,15935
	r11.s64 = 1044316160;
	// ori r10,r11,35328
	ctx.r10.u64 = r11.u64 | 35328;
	// stw r10,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r10.u32);
loc_822E49B4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-8064
	ctx.r10.s64 = r11.s64 + -8064;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e49d8
	if (cr6.eq) goto loc_822E49D8;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// rlwinm r10,r11,0,27,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFE1F;
	// rlwinm r10,r10,0,19,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFF9FFF;
	// stw r10,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r10.u32);
loc_822E49D8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-8024
	ctx.r10.s64 = r11.s64 + -8024;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e49f8
	if (!cr6.eq) goto loc_822E49F8;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// rlwinm r10,r11,0,8,6
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFEFFFFFF;
	// stw r10,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r10.u32);
loc_822E49F8:
	// stb r30,370(r31)
	PPC_STORE_U8(r31.u32 + 370, r30.u8);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stb r30,369(r31)
	PPC_STORE_U8(r31.u32 + 369, r30.u8);
	// addi r10,r11,-8084
	ctx.r10.s64 = r11.s64 + -8084;
	// stw r30,400(r31)
	PPC_STORE_U32(r31.u32 + 400, r30.u32);
	// stw r30,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r30.u32);
	// stw r30,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r30.u32);
	// stw r30,404(r31)
	PPC_STORE_U32(r31.u32 + 404, r30.u32);
	// stb r28,371(r31)
	PPC_STORE_U8(r31.u32 + 371, r28.u8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4a3c
	if (!cr6.eq) goto loc_822E4A3C;
	// bl 0x82178880
	ctx.lr = 0x822E4A2C;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x822e4a40
	if (!cr6.eq) goto loc_822E4A40;
loc_822E4A3C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_822E4A40:
	// stb r30,434(r31)
	PPC_STORE_U8(r31.u32 + 434, r30.u8);
	// stw r30,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r30.u32);
	// stw r30,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r30.u32);
	// stb r30,432(r31)
	PPC_STORE_U8(r31.u32 + 432, r30.u8);
	// stb r30,433(r31)
	PPC_STORE_U8(r31.u32 + 433, r30.u8);
	// stb r30,375(r31)
	PPC_STORE_U8(r31.u32 + 375, r30.u8);
	// stb r11,373(r31)
	PPC_STORE_U8(r31.u32 + 373, r11.u8);
	// stb r28,374(r31)
	PPC_STORE_U8(r31.u32 + 374, r28.u8);
	// stb r30,372(r31)
	PPC_STORE_U8(r31.u32 + 372, r30.u8);
	// lbz r10,371(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 371);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r30,389(r31)
	PPC_STORE_U8(r31.u32 + 389, r30.u8);
	// stb r30,390(r31)
	PPC_STORE_U8(r31.u32 + 390, r30.u8);
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r28,388(r31)
	PPC_STORE_U8(r31.u32 + 388, r28.u8);
	// stb r7,376(r31)
	PPC_STORE_U8(r31.u32 + 376, ctx.r7.u8);
	// bne cr6,0x822e4a9c
	if (!cr6.eq) goto loc_822E4A9C;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// rlwinm r10,r11,0,22,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
	// stw r10,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r10.u32);
loc_822E4A9C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,452(r31)
	PPC_STORE_U32(r31.u32 + 452, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E4AAC"))) PPC_WEAK_FUNC(sub_822E4AAC);
PPC_FUNC_IMPL(__imp__sub_822E4AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E4AB0"))) PPC_WEAK_FUNC(sub_822E4AB0);
PPC_FUNC_IMPL(__imp__sub_822E4AB0) {
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
	ctx.lr = 0x822E4AB8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,464
	ctx.r3.s64 = 464;
	// bl 0x82130528
	ctx.lr = 0x822E4AC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e4ae0
	if (cr6.eq) goto loc_822E4AE0;
	// bl 0x822e47e0
	ctx.lr = 0x822E4AD0;
	sub_822E47E0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-8092
	r31.s64 = r11.s64 + -8092;
	// stw r3,-8092(r11)
	PPC_STORE_U32(r11.u32 + -8092, ctx.r3.u32);
	// b 0x822e4af0
	goto loc_822E4AF0;
loc_822E4AE0:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// addi r31,r10,-8092
	r31.s64 = ctx.r10.s64 + -8092;
	// stw r11,-8092(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8092, r11.u32);
loc_822E4AF0:
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x822E4AF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e4b0c
	if (cr6.eq) goto loc_822E4B0C;
	// bl 0x8217d5e8
	ctx.lr = 0x822E4B04;
	sub_8217D5E8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// b 0x822e4b10
	goto loc_822E4B10;
loc_822E4B0C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E4B10:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,992
	ctx.r3.s64 = 992;
	// stw r10,180(r11)
	PPC_STORE_U32(r11.u32 + 180, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x822E4B20;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e4b30
	if (cr6.eq) goto loc_822E4B30;
	// bl 0x8217d5e8
	ctx.lr = 0x822E4B2C;
	sub_8217D5E8(ctx, base);
	// b 0x822e4b34
	goto loc_822E4B34;
loc_822E4B30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822E4B34:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,184(r11)
	PPC_STORE_U32(r11.u32 + 184, ctx.r3.u32);
	// bl 0x82178880
	ctx.lr = 0x822E4B40;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4b78
	if (!cr6.eq) goto loc_822E4B78;
	// lwz r11,17012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17012);
	// cmpwi cr6,r11,720
	cr6.compare<int32_t>(r11.s32, 720, xer);
	// bgt cr6,0x822e4b78
	if (cr6.gt) goto loc_822E4B78;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
	// cmpwi cr6,r11,576
	cr6.compare<int32_t>(r11.s32, 576, xer);
	// bgt cr6,0x822e4b78
	if (cr6.gt) goto loc_822E4B78;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,384(r11)
	PPC_STORE_U32(r11.u32 + 384, ctx.r10.u32);
loc_822E4B78:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-7944
	ctx.r10.s64 = r11.s64 + -7944;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4ba0
	if (!cr6.eq) goto loc_822E4BA0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-7924
	ctx.r10.s64 = r11.s64 + -7924;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4bac
	if (cr6.eq) goto loc_822E4BAC;
loc_822E4BA0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,384(r11)
	PPC_STORE_U32(r11.u32 + 384, ctx.r10.u32);
loc_822E4BAC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// stw r9,352(r11)
	PPC_STORE_U32(r11.u32 + 352, ctx.r9.u32);
	// lwz r11,-25824(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -25824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4c10
	if (cr6.eq) goto loc_822E4C10;
	// bl 0x82178880
	ctx.lr = 0x822E4BD0;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4c00
	if (!cr6.eq) goto loc_822E4C00;
	// lwz r11,17012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17012);
	// cmpwi cr6,r11,720
	cr6.compare<int32_t>(r11.s32, 720, xer);
	// ble cr6,0x822e4c00
	if (!cr6.gt) goto loc_822E4C00;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lwz r11,-25824(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -25824);
	// stfs f0,36(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822E4C00:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r11,-25824(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -25824);
	// stfs f0,36(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
loc_822E4C10:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E4C18"))) PPC_WEAK_FUNC(sub_822E4C18);
PPC_FUNC_IMPL(__imp__sub_822E4C18) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82178880
	ctx.lr = 0x822E4C30;
	sub_82178880(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4c48
	if (cr6.eq) goto loc_822E4C48;
	// li r31,256
	r31.s64 = 256;
	// li r30,256
	r30.s64 = 256;
	// b 0x822e4c50
	goto loc_822E4C50;
loc_822E4C48:
	// li r31,128
	r31.s64 = 128;
	// li r30,128
	r30.s64 = 128;
loc_822E4C50:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x822E4C5C;
	sub_82180430(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,-25232(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r4,r7,-6844
	ctx.r4.s64 = ctx.r7.s64 + -6844;
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r11.u8);
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_822E4CC8"))) PPC_WEAK_FUNC(sub_822E4CC8);
PPC_FUNC_IMPL(__imp__sub_822E4CC8) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822E4CD0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82180430
	ctx.lr = 0x822E4CE4;
	sub_82180430(ctx, base);
	// lwz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// li r25,1
	r25.s64 = 1;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// stb r25,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r25.u8);
	// mr r11,r25
	r11.u64 = r25.u64;
	// stb r25,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, r25.u8);
	// li r10,5
	ctx.r10.s64 = 5;
	// stb r28,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r28.u8);
	// stb r25,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r25.u8);
	// li r3,28
	ctx.r3.s64 = 28;
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r28.u32);
	// stb r11,2488(r30)
	PPC_STORE_U8(r30.u32 + 2488, r11.u8);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x822E4D24;
	sub_82130528(ctx, base);
	// lis r27,-32125
	r27.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e4d64
	if (cr6.eq) goto loc_822E4D64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r11,2484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 2484);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r4,r9,-6732
	ctx.r4.s64 = ctx.r9.s64 + -6732;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4096
	ctx.r7.s64 = 4096;
	// li r6,3
	ctx.r6.s64 = 3;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821851c8
	ctx.lr = 0x822E4D5C;
	sub_821851C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x822e4d68
	goto loc_822E4D68;
loc_822E4D64:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_822E4D68:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r11,r28
	r11.u64 = r28.u64;
	// addi r9,r10,-8004
	ctx.r9.s64 = ctx.r10.s64 + -8004;
	// stb r11,2488(r30)
	PPC_STORE_U8(r30.u32 + 2488, r11.u8);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e4e0c
	if (cr6.eq) goto loc_822E4E0C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82183710
	ctx.lr = 0x822E4D94;
	sub_82183710(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r7,420(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// addi r30,r11,-25232
	r30.s64 = r11.s64 + -25232;
	// lwz r6,416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// addi r4,r10,-6760
	ctx.r4.s64 = ctx.r10.s64 + -6760;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,-24876(r26)
	PPC_STORE_U32(r26.u32 + -24876, r11.u32);
	// lwz r9,404(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// bl 0x82183710
	ctx.lr = 0x822E4DF4;
	sub_82183710(ctx, base);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// lwz r3,2484(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 2484);
	// bl 0x82183748
	ctx.lr = 0x822E4E00;
	sub_82183748(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r8,-6784
	ctx.r4.s64 = ctx.r8.s64 + -6784;
	// b 0x822e4ed0
	goto loc_822E4ED0;
loc_822E4E0C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// addi r10,r11,-8044
	ctx.r10.s64 = r11.s64 + -8044;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e4e50
	if (!cr6.eq) goto loc_822E4E50;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stb r28,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r28.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r11,-25232
	r30.s64 = r11.s64 + -25232;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4E48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// b 0x822e4ea4
	goto loc_822E4EA4;
loc_822E4E50:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82183710
	ctx.lr = 0x822E4E60;
	sub_82183710(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r7,420(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// addi r30,r11,-25232
	r30.s64 = r11.s64 + -25232;
	// lwz r6,416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// addi r4,r10,-6760
	ctx.r4.s64 = ctx.r10.s64 + -6760;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4E98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// stw r11,-24876(r26)
	PPC_STORE_U32(r26.u32 + -24876, r11.u32);
loc_822E4EA4:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// bl 0x82183710
	ctx.lr = 0x822E4EBC;
	sub_82183710(ctx, base);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// lwz r3,2484(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 2484);
	// bl 0x82183748
	ctx.lr = 0x822E4EC8;
	sub_82183748(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-6784
	ctx.r4.s64 = ctx.r10.s64 + -6784;
loc_822E4ED0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r6,416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r7,420(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4EF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r3,396(r31)
	PPC_STORE_U32(r31.u32 + 396, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,-24876(r26)
	PPC_STORE_U32(r26.u32 + -24876, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82183710
	ctx.lr = 0x822E4F14;
	sub_82183710(ctx, base);
	// lwz r11,2484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 2484);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x82183748
	ctx.lr = 0x822E4F24;
	sub_82183748(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r6,416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lwz r7,420(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r8,-6808
	ctx.r4.s64 = ctx.r8.s64 + -6808;
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4F54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,400(r31)
	PPC_STORE_U32(r31.u32 + 400, ctx.r3.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stb r28,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r28.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,-24876(r26)
	PPC_STORE_U32(r26.u32 + -24876, r11.u32);
	// li r11,2
	r11.s64 = 2;
	// stb r25,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r25.u8);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// stb r25,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r25.u8);
	// stb r28,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r28.u8);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// stb r25,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, r25.u8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E4F98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r4,r5,-6820
	ctx.r4.s64 = ctx.r5.s64 + -6820;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r7,17016(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17016);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r6,17012(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 17012);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E4FD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// stw r3,412(r31)
	PPC_STORE_U32(r31.u32 + 412, ctx.r3.u32);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e503c
	if (cr6.eq) goto loc_822E503C;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r5,176(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r6,-25360(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25360);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822E5004;
	sub_82189CE0(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r5,r8,-32224
	ctx.r5.s64 = ctx.r8.s64 + -32224;
	// addi r6,r11,448
	ctx.r6.s64 = r11.s64 + 448;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,1584(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 1584);
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E503C;
	sub_8218A6E0(ctx, base);
loc_822E503C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822E5044"))) PPC_WEAK_FUNC(sub_822E5044);
PPC_FUNC_IMPL(__imp__sub_822E5044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E5048"))) PPC_WEAK_FUNC(sub_822E5048);
PPC_FUNC_IMPL(__imp__sub_822E5048) {
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
	// lwz r3,436(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 436);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e50a0
	if (cr6.eq) goto loc_822E50A0;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// bl 0x82183710
	ctx.lr = 0x822E5070;
	sub_82183710(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,-24876(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24876);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// subf r4,r5,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r5.s64;
	// cmpw cr6,r4,r31
	cr6.compare<int32_t>(ctx.r4.s32, r31.s32, xer);
	// bge cr6,0x822e50a0
	if (!cr6.lt) goto loc_822E50A0;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-24876(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24876, r11.u32);
loc_822E50A0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822E50B4"))) PPC_WEAK_FUNC(sub_822E50B4);
PPC_FUNC_IMPL(__imp__sub_822E50B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E50B8"))) PPC_WEAK_FUNC(sub_822E50B8);
PPC_FUNC_IMPL(__imp__sub_822E50B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,436(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-24876(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24876, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E50D4"))) PPC_WEAK_FUNC(sub_822E50D4);
PPC_FUNC_IMPL(__imp__sub_822E50D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E50D8"))) PPC_WEAK_FUNC(sub_822E50D8);
PPC_FUNC_IMPL(__imp__sub_822E50D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,32
	ctx.r9.s64 = 32;
loc_822E50E4:
	// and r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 & ctx.r4.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822e50f4
	if (cr6.eq) goto loc_822E50F4;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
loc_822E50F4:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// bne 0x822e50e4
	if (!cr0.eq) goto loc_822E50E4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5108"))) PPC_WEAK_FUNC(sub_822E5108);
PPC_FUNC_IMPL(__imp__sub_822E5108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822E5114:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// bne cr6,0x822e5124
	if (!cr6.eq) goto loc_822E5124;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_822E5124:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822e5114
	if (!cr0.eq) goto loc_822E5114;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5134"))) PPC_WEAK_FUNC(sub_822E5134);
PPC_FUNC_IMPL(__imp__sub_822E5134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E5138"))) PPC_WEAK_FUNC(sub_822E5138);
PPC_FUNC_IMPL(__imp__sub_822E5138) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5148"))) PPC_WEAK_FUNC(sub_822E5148);
PPC_FUNC_IMPL(__imp__sub_822E5148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,128
	r11.s64 = ctx.r3.s64 + 128;
loc_822E5150:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x822e5170
	if (cr6.eq) goto loc_822E5170;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,13
	cr6.compare<int32_t>(ctx.r10.s32, 13, xer);
	// blt cr6,0x822e5150
	if (cr6.lt) goto loc_822E5150;
	// blr 
	return;
loc_822E5170:
	// addi r11,r10,32
	r11.s64 = ctx.r10.s64 + 32;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5184"))) PPC_WEAK_FUNC(sub_822E5184);
PPC_FUNC_IMPL(__imp__sub_822E5184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E5188"))) PPC_WEAK_FUNC(sub_822E5188);
PPC_FUNC_IMPL(__imp__sub_822E5188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r11,-17936(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17936);
	// addi r6,r11,3
	ctx.r6.s64 = r11.s64 + 3;
	// rlwinm r11,r6,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17936);
	// addi r5,r11,45
	ctx.r5.s64 = r11.s64 + 45;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// b 0x8217ce80
	sub_8217CE80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822E51DC"))) PPC_WEAK_FUNC(sub_822E51DC);
PPC_FUNC_IMPL(__imp__sub_822E51DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E51E0"))) PPC_WEAK_FUNC(sub_822E51E0);
PPC_FUNC_IMPL(__imp__sub_822E51E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,404(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E51E8"))) PPC_WEAK_FUNC(sub_822E51E8);
PPC_FUNC_IMPL(__imp__sub_822E51E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r3,-8110(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -8110);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E51F4"))) PPC_WEAK_FUNC(sub_822E51F4);
PPC_FUNC_IMPL(__imp__sub_822E51F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E51F8"))) PPC_WEAK_FUNC(sub_822E51F8);
PPC_FUNC_IMPL(__imp__sub_822E51F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,448(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	// or r10,r11,r5
	ctx.r10.u64 = r11.u64 | ctx.r5.u64;
	// bne cr6,0x822e5210
	if (!cr6.eq) goto loc_822E5210;
	// andc r10,r11,r5
	ctx.r10.u64 = r11.u64 & ~ctx.r5.u64;
loc_822E5210:
	// stw r10,448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 448, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5218"))) PPC_WEAK_FUNC(sub_822E5218);
PPC_FUNC_IMPL(__imp__sub_822E5218) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822E5220;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r28,-256
	r28.s64 = -16777216;
	// li r31,0
	r31.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// lwz r4,408(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822e5290
	if (cr6.eq) goto loc_822E5290;
	// lwz r11,364(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 364);
	// lis r10,10240
	ctx.r10.s64 = 671088640;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x822e5290
	if (cr6.eq) goto loc_822E5290;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r31,102(r1)
	PPC_STORE_U8(ctx.r1.u32 + 102, r31.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r29,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r29.u8);
	// stb r29,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r29.u8);
	// stb r31,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r31.u8);
	// stb r31,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r31.u8);
	// bl 0x82178f70
	ctx.lr = 0x822E5290;
	sub_82178F70(ctx, base);
loc_822E5290:
	// lwz r10,384(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r30,r11,-8110
	r30.s64 = r11.s64 + -8110;
	// ble cr6,0x822e52c4
	if (!cr6.gt) goto loc_822E52C4;
	// lbz r11,10(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e52c4
	if (!cr6.eq) goto loc_822E52C4;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e531c
	if (cr6.eq) goto loc_822E531C;
	// bl 0x8217b430
	ctx.lr = 0x822E52C0;
	sub_8217B430(ctx, base);
	// b 0x822e531c
	goto loc_822E531C;
loc_822E52C4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r28.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stb r29,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r11,-27692(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27692);
	// stb r31,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r31.u8);
	// neg r9,r11
	ctx.r9.s64 = -r11.s64;
	// stb r29,135(r1)
	PPC_STORE_U8(ctx.r1.u32 + 135, r29.u8);
	// stb r31,133(r1)
	PPC_STORE_U8(ctx.r1.u32 + 133, r31.u8);
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stb r31,134(r1)
	PPC_STORE_U8(ctx.r1.u32 + 134, r31.u8);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822E531C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E531C:
	// lbz r11,-2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -2);
	// stb r31,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r31.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e533c
	if (cr6.eq) goto loc_822E533C;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x8241e428
	ctx.lr = 0x822E533C;
	sub_8241E428(ctx, base);
loc_822E533C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-18004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// bl 0x82304df0
	ctx.lr = 0x822E534C;
	sub_82304DF0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E5358"))) PPC_WEAK_FUNC(sub_822E5358);
PPC_FUNC_IMPL(__imp__sub_822E5358) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x822E5360;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r27,380(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 380);
	// cmpwi cr6,r27,3
	cr6.compare<int32_t>(r27.s32, 3, xer);
	// beq cr6,0x822e5390
	if (cr6.eq) goto loc_822E5390;
	// lbz r11,393(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 393);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e5390
	if (!cr6.eq) goto loc_822E5390;
	// lbz r11,373(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 373);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5394
	if (cr6.eq) goto loc_822E5394;
loc_822E5390:
	// li r27,4
	r27.s64 = 4;
loc_822E5394:
	// lbz r11,375(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 375);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5598
	if (cr6.eq) goto loc_822E5598;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-25232(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E53BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-25232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -25232);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822E53DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// lis r4,-32124
	ctx.r4.s64 = -2105278464;
	// li r29,1
	r29.s64 = 1;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r31.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// lis r10,-256
	ctx.r10.s64 = -16777216;
	// lfs f0,7444(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stb r31,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, r31.u8);
	// stw r11,-27692(r4)
	PPC_STORE_U32(ctx.r4.u32 + -27692, r11.u32);
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r10,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r10.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r29,167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 167, r29.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r29,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r29.u8);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r31.u8);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stb r31,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8217a470
	ctx.lr = 0x822E543C;
	sub_8217A470(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x822E5448;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x822E5454;
	sub_8217F768(ctx, base);
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217fed0
	ctx.lr = 0x822E545C;
	sub_8217FED0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x822E546C;
	sub_8217F768(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217fed0
	ctx.lr = 0x822E5474;
	sub_8217FED0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x822E5484;
	sub_8217F768(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8217d9a0
	ctx.lr = 0x822E548C;
	sub_8217D9A0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e20
	ctx.lr = 0x822E5498;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e20
	ctx.lr = 0x822E54A4;
	sub_82189E20(ctx, base);
	// lwz r8,364(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 364);
	// lis r9,10240
	ctx.r9.s64 = 671088640;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x822e5538
	if (cr6.eq) goto loc_822E5538;
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r24,r1,128
	r24.s64 = ctx.r1.s64 + 128;
	// li r28,-1
	r28.s64 = -1;
	// lwz r27,-12280(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + -12280);
	// bl 0x821771e8
	ctx.lr = 0x822E54CC;
	sub_821771E8(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// bl 0x82177198
	ctx.lr = 0x822E54E4;
	sub_82177198(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lfs f9,7444(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmr f5,f9
	ctx.f5.f64 = ctx.f9.f64;
	// std r9,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r9.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lfs f7,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fmr f2,f7
	ctx.f2.f64 = ctx.f7.f64;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// frsp f3,f11
	ctx.f3.f64 = double(float(ctx.f11.f64));
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r24.u32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x823083f8
	ctx.lr = 0x822E5534;
	sub_823083F8(ctx, base);
	// b 0x822e5554
	goto loc_822E5554;
loc_822E5538:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f1,7444(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178370
	ctx.lr = 0x822E5554;
	sub_82178370(ctx, base);
loc_822E5554:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x822E555C;
	sub_8217D9A0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e20
	ctx.lr = 0x822E5568;
	sub_82189E20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e20
	ctx.lr = 0x822E5574;
	sub_82189E20(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x822E5580;
	sub_8217F768(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x822E558C;
	sub_8217F768(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_822E5598:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82178370
	ctx.lr = 0x822E55B8;
	sub_82178370(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822E55C4"))) PPC_WEAK_FUNC(sub_822E55C4);
PPC_FUNC_IMPL(__imp__sub_822E55C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E55C8"))) PPC_WEAK_FUNC(sub_822E55C8);
PPC_FUNC_IMPL(__imp__sub_822E55C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,408(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E55D0"))) PPC_WEAK_FUNC(sub_822E55D0);
PPC_FUNC_IMPL(__imp__sub_822E55D0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822E55D8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,4
	r11.s64 = 262144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x822e55f8
	if (!cr6.lt) goto loc_822E55F8;
	// li r11,0
	r11.s64 = 0;
loc_822E55F8:
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
	// li r24,15
	r24.s64 = 15;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// bne cr6,0x822e5618
	if (!cr6.eq) goto loc_822E5618;
	// li r25,0
	r25.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822e563c
	goto loc_822E563C;
loc_822E5618:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmpwi cr6,r28,8192
	cr6.compare<int32_t>(r28.s32, 8192, xer);
	// lwz r25,6616(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 6616);
	// beq cr6,0x822e5638
	if (cr6.eq) goto loc_822E5638;
	// cmpwi cr6,r28,16384
	cr6.compare<int32_t>(r28.s32, 16384, xer);
	// beq cr6,0x822e5638
	if (cr6.eq) goto loc_822E5638;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822e563c
	goto loc_822E563C;
loc_822E5638:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E563C:
	// rlwinm r9,r28,0,12,20
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFF800;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// rlwinm r9,r9,0,19,12
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFF81FFF;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cntlzw r6,r9
	ctx.r6.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r26,r11,6606
	r26.s64 = r11.s64 + 6606;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e5674
	if (cr6.eq) goto loc_822E5674;
	// lbz r11,-2(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + -2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e5684
	if (!cr6.eq) goto loc_822E5684;
loc_822E5674:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822e5688
	if (cr6.eq) goto loc_822E5688;
loc_822E5684:
	// li r11,1
	r11.s64 = 1;
loc_822E5688:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// beq cr6,0x822e56b0
	if (cr6.eq) goto loc_822E56B0;
	// cmpwi cr6,r28,4096
	cr6.compare<int32_t>(r28.s32, 4096, xer);
	// blt cr6,0x822e56a8
	if (cr6.lt) goto loc_822E56A8;
	// lis r11,1024
	r11.s64 = 67108864;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// ble cr6,0x822e56b0
	if (!cr6.gt) goto loc_822E56B0;
loc_822E56A8:
	// li r11,0
	r11.s64 = 0;
	// b 0x822e56b4
	goto loc_822E56B4;
loc_822E56B0:
	// li r11,1
	r11.s64 = 1;
loc_822E56B4:
	// rlwinm r10,r28,0,19,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x1FF0;
	// clrlwi r23,r11,24
	r23.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,23,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822e56f8
	if (cr6.eq) goto loc_822E56F8;
	// cmpwi cr6,r28,4096
	cr6.compare<int32_t>(r28.s32, 4096, xer);
	// beq cr6,0x822e56f8
	if (cr6.eq) goto loc_822E56F8;
	// cmpwi cr6,r28,8192
	cr6.compare<int32_t>(r28.s32, 8192, xer);
	// beq cr6,0x822e56f8
	if (cr6.eq) goto loc_822E56F8;
	// cmpwi cr6,r28,16384
	cr6.compare<int32_t>(r28.s32, 16384, xer);
	// beq cr6,0x822e56f8
	if (cr6.eq) goto loc_822E56F8;
	// rlwinm r11,r28,0,27,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e56f0
	if (cr6.eq) goto loc_822E56F0;
	// li r24,0
	r24.s64 = 0;
loc_822E56F0:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r25,6620(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 6620);
loc_822E56F8:
	// cmpwi cr6,r28,2048
	cr6.compare<int32_t>(r28.s32, 2048, xer);
	// bne cr6,0x822e5704
	if (!cr6.eq) goto loc_822E5704;
	// li r24,0
	r24.s64 = 0;
loc_822E5704:
	// rlwinm r10,r28,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x2000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822e5774
	if (!cr6.eq) goto loc_822E5774;
	// rlwinm r11,r28,0,17,17
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822e573c
	if (!cr6.eq) goto loc_822E573C;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5734
	if (cr6.eq) goto loc_822E5734;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822e5738
	if (cr6.eq) goto loc_822E5738;
loc_822E5734:
	// li r11,0
	r11.s64 = 0;
loc_822E5738:
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
loc_822E573C:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822e5774
	if (!cr6.eq) goto loc_822E5774;
	// rlwinm r11,r28,0,17,17
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822e5774
	if (!cr6.eq) goto loc_822E5774;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e5768
	if (cr6.eq) goto loc_822E5768;
	// lbz r11,-1(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + -1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822e576c
	if (!cr6.eq) goto loc_822E576C;
loc_822E5768:
	// li r11,0
	r11.s64 = 0;
loc_822E576C:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// b 0x822e5778
	goto loc_822E5778;
loc_822E5774:
	// li r29,0
	r29.s64 = 0;
loc_822E5778:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e5794
	if (!cr6.eq) goto loc_822E5794;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5798
	if (cr6.eq) goto loc_822E5798;
loc_822E5794:
	// li r31,1
	r31.s64 = 1;
loc_822E5798:
	// clrlwi r30,r7,24
	r30.u64 = ctx.r7.u32 & 0xFF;
	// li r3,8
	ctx.r3.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8217f768
	ctx.lr = 0x822E57A8;
	sub_8217F768(ctx, base);
	// subfic r11,r30,0
	xer.ca = r30.u32 <= 0;
	r11.s64 = 0 - r30.s64;
	// li r3,2
	ctx.r3.s64 = 2;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r10,0,30,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r4,r11,5
	ctx.r4.s64 = r11.s64 + 5;
	// bl 0x8217f768
	ctx.lr = 0x822E57C0;
	sub_8217F768(ctx, base);
	// clrlwi r4,r27,24
	ctx.r4.u64 = r27.u32 & 0xFF;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x822E57CC;
	sub_8217F768(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8217f768
	ctx.lr = 0x822E57D8;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217f768
	ctx.lr = 0x822E57E4;
	sub_8217F768(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x822E57F0;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x822E57FC;
	sub_8217F768(ctx, base);
	// clrlwi r4,r31,24
	ctx.r4.u64 = r31.u32 & 0xFF;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x822E5808;
	sub_8217F768(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x822E5814;
	sub_8217F768(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x822E5820;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217f768
	ctx.lr = 0x822E582C;
	sub_8217F768(ctx, base);
	// li r4,255
	ctx.r4.s64 = 255;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8217f768
	ctx.lr = 0x822E5838;
	sub_8217F768(ctx, base);
	// li r4,255
	ctx.r4.s64 = 255;
	// li r3,26
	ctx.r3.s64 = 26;
	// bl 0x8217f768
	ctx.lr = 0x822E5844;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x8217f768
	ctx.lr = 0x822E5850;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8217f768
	ctx.lr = 0x822E585C;
	sub_8217F768(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8217f768
	ctx.lr = 0x822E5868;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x8217f768
	ctx.lr = 0x822E5874;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x8217f768
	ctx.lr = 0x822E5880;
	sub_8217F768(ctx, base);
	// rlwinm r9,r28,0,23,27
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822e58b0
	if (cr6.eq) goto loc_822E58B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e20
	ctx.lr = 0x822E5898;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e20
	ctx.lr = 0x822E58A4;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82189e20
	ctx.lr = 0x822E58B0;
	sub_82189E20(ctx, base);
loc_822E58B0:
	// rlwinm r11,r28,0,2,4
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x38000000;
	// li r3,5
	ctx.r3.s64 = 5;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e58d8
	if (cr6.eq) goto loc_822E58D8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x822E58C8;
	sub_82189E20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e20
	ctx.lr = 0x822E58D4;
	sub_82189E20(ctx, base);
	// b 0x822e5954
	goto loc_822E5954;
loc_822E58D8:
	// rlwinm r11,r28,0,28,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xE;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e5900
	if (cr6.eq) goto loc_822E5900;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x822E58EC;
	sub_82189E20(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e20
	ctx.lr = 0x822E58F8;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x822e5958
	goto loc_822E5958;
loc_822E5900:
	// lbz r11,-15(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + -15);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,30
	r11.u64 = ctx.r9.u32 & 0x3;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x82189e20
	ctx.lr = 0x822E5918;
	sub_82189E20(ctx, base);
	// lbz r8,-15(r26)
	ctx.r8.u64 = PPC_LOAD_U8(r26.u32 + -15);
	// li r3,4
	ctx.r3.s64 = 4;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r6,30
	r11.u64 = ctx.r6.u32 & 0x3;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x82189e20
	ctx.lr = 0x822E5934;
	sub_82189E20(ctx, base);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lbz r4,-8099(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + -8099);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822e5954
	if (cr6.eq) goto loc_822E5954;
	// lbz r11,-15(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + -15);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e5958
	if (!cr6.eq) goto loc_822E5958;
loc_822E5954:
	// li r4,1
	ctx.r4.s64 = 1;
loc_822E5958:
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82189e20
	ctx.lr = 0x822E5960;
	sub_82189E20(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r3,14
	ctx.r3.s64 = 14;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e59a0
	if (cr6.eq) goto loc_822E59A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822E5978;
	sub_8217F768(ctx, base);
	// lbz r11,0(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5994
	if (cr6.eq) goto loc_822E5994;
	// lwz r11,384(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 384);
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bgt cr6,0x822e5998
	if (cr6.gt) goto loc_822E5998;
loc_822E5994:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822E5998:
	// li r3,15
	ctx.r3.s64 = 15;
	// b 0x822e59a4
	goto loc_822E59A4;
loc_822E59A0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822E59A4:
	// bl 0x8217f768
	ctx.lr = 0x822E59A8;
	sub_8217F768(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-18004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// bl 0x82304df0
	ctx.lr = 0x822E59B8;
	sub_82304DF0(ctx, base);
	// stb r29,391(r22)
	PPC_STORE_U8(r22.u32 + 391, r29.u8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822e59d4
	if (!cr6.eq) goto loc_822E59D4;
	// lis r11,1
	r11.s64 = 65536;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822e59d8
	if (!cr6.eq) goto loc_822E59D8;
loc_822E59D4:
	// li r11,1
	r11.s64 = 1;
loc_822E59D8:
	// stb r11,392(r22)
	PPC_STORE_U8(r22.u32 + 392, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822E59E4"))) PPC_WEAK_FUNC(sub_822E59E4);
PPC_FUNC_IMPL(__imp__sub_822E59E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E59E8"))) PPC_WEAK_FUNC(sub_822E59E8);
PPC_FUNC_IMPL(__imp__sub_822E59E8) {
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
	ctx.lr = 0x822E59F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x8217fed0
	ctx.lr = 0x822E5A04;
	sub_8217FED0(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r31,r11,-8128
	r31.s64 = r11.s64 + -8128;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x8217fed0
	ctx.lr = 0x822E5A24;
	sub_8217FED0(ctx, base);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lbz r7,392(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 392);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
	// bne cr6,0x822e5a64
	if (!cr6.eq) goto loc_822E5A64;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x8217f768
	ctx.lr = 0x822E5A4C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,15
	ctx.r3.s64 = 15;
	// bl 0x8217f768
	ctx.lr = 0x822E5A58;
	sub_8217F768(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217f6f0
	ctx.lr = 0x822E5A64;
	sub_8217F6F0(ctx, base);
loc_822E5A64:
	// lbz r11,368(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 368);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,369(r30)
	PPC_STORE_U8(r30.u32 + 369, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e5a8c
	if (!cr6.eq) goto loc_822E5A8C;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r4,10922
	ctx.r4.s64 = 715784192;
	// ori r4,r4,43690
	ctx.r4.u64 = ctx.r4.u64 | 43690;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x8241bd08
	ctx.lr = 0x822E5A8C;
	sub_8241BD08(ctx, base);
loc_822E5A8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822E5A94;
	sub_82190890(ctx, base);
	// lwz r11,360(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 360);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// rlwinm r10,r11,21,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e5ac8
	if (cr6.eq) goto loc_822E5AC8;
	// rlwinm r11,r29,0,20,20
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x800;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e5ac8
	if (cr6.eq) goto loc_822E5AC8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823112c0
	ctx.lr = 0x822E5AC8;
	sub_823112C0(ctx, base);
loc_822E5AC8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E5AD0"))) PPC_WEAK_FUNC(sub_822E5AD0);
PPC_FUNC_IMPL(__imp__sub_822E5AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// b 0x822f0f38
	sub_822F0F38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822E5ADC"))) PPC_WEAK_FUNC(sub_822E5ADC);
PPC_FUNC_IMPL(__imp__sub_822E5ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E5AE0"))) PPC_WEAK_FUNC(sub_822E5AE0);
PPC_FUNC_IMPL(__imp__sub_822E5AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,364(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	// or r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 | r11.u64;
	// stw r10,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5AF0"))) PPC_WEAK_FUNC(sub_822E5AF0);
PPC_FUNC_IMPL(__imp__sub_822E5AF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,364(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	// andc r10,r11,r4
	ctx.r10.u64 = r11.u64 & ~ctx.r4.u64;
	// stw r10,364(r3)
	PPC_STORE_U32(ctx.r3.u32 + 364, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5B00"))) PPC_WEAK_FUNC(sub_822E5B00);
PPC_FUNC_IMPL(__imp__sub_822E5B00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,424(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// or r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 | r11.u64;
	// stw r10,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5B10"))) PPC_WEAK_FUNC(sub_822E5B10);
PPC_FUNC_IMPL(__imp__sub_822E5B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,428(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// or r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 | r11.u64;
	// stw r10,428(r3)
	PPC_STORE_U32(ctx.r3.u32 + 428, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5B20"))) PPC_WEAK_FUNC(sub_822E5B20);
PPC_FUNC_IMPL(__imp__sub_822E5B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r4,433(r3)
	PPC_STORE_U8(ctx.r3.u32 + 433, ctx.r4.u8);
	// stb r11,432(r3)
	PPC_STORE_U8(ctx.r3.u32 + 432, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5B30"))) PPC_WEAK_FUNC(sub_822E5B30);
PPC_FUNC_IMPL(__imp__sub_822E5B30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,432(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 432);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5b58
	if (cr6.eq) goto loc_822E5B58;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822e5b58
	if (!cr6.eq) goto loc_822E5B58;
	// lbz r3,433(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 433);
	// blr 
	return;
loc_822E5B58:
	// lbz r3,373(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 373);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5B60"))) PPC_WEAK_FUNC(sub_822E5B60);
PPC_FUNC_IMPL(__imp__sub_822E5B60) {
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
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// lwz r10,364(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// lwz r9,424(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// andc r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 & ~r11.u64;
	// lbz r7,432(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 432);
	// stw r30,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r30.u32);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r30,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r30.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r6,364(r31)
	PPC_STORE_U32(r31.u32 + 364, ctx.r6.u32);
	// beq cr6,0x822e5bb4
	if (cr6.eq) goto loc_822E5BB4;
	// lbz r11,433(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 433);
	// stb r30,432(r31)
	PPC_STORE_U8(r31.u32 + 432, r30.u8);
	// stb r11,373(r31)
	PPC_STORE_U8(r31.u32 + 373, r11.u8);
loc_822E5BB4:
	// bl 0x82387a18
	ctx.lr = 0x822E5BB8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5bd8
	if (cr6.eq) goto loc_822E5BD8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lbz r10,756(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 756);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822e5bf0
	if (!cr6.eq) goto loc_822E5BF0;
loc_822E5BD8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-8892
	ctx.r10.s64 = r11.s64 + -8892;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// beq cr6,0x822e5bf4
	if (cr6.eq) goto loc_822E5BF4;
loc_822E5BF0:
	// li r11,1
	r11.s64 = 1;
loc_822E5BF4:
	// stb r11,435(r31)
	PPC_STORE_U8(r31.u32 + 435, r11.u8);
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

__attribute__((alias("__imp__sub_822E5C10"))) PPC_WEAK_FUNC(sub_822E5C10);
PPC_FUNC_IMPL(__imp__sub_822E5C10) {
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
	// bl 0x823bc630
	ctx.lr = 0x822E5C28;
	sub_823BC630(ctx, base);
	// lbz r11,388(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5c4c
	if (cr6.eq) goto loc_822E5C4C;
	// lbz r11,389(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 389);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5c4c
	if (cr6.eq) goto loc_822E5C4C;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5c5c
	if (cr6.eq) goto loc_822E5C5C;
loc_822E5C4C:
	// lbz r11,390(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 390);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822e5c60
	if (cr6.eq) goto loc_822E5C60;
loc_822E5C5C:
	// li r11,1
	r11.s64 = 1;
loc_822E5C60:
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

__attribute__((alias("__imp__sub_822E5C78"))) PPC_WEAK_FUNC(sub_822E5C78);
PPC_FUNC_IMPL(__imp__sub_822E5C78) {
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
	// lwz r30,396(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822e5ccc
	if (cr6.eq) goto loc_822E5CCC;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822E5CA4;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822e5ccc
	if (!cr6.eq) goto loc_822E5CCC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822e5ccc
	if (cr6.eq) goto loc_822E5CCC;
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
	ctx.lr = 0x822E5CCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E5CCC:
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e5ce8
	if (cr6.eq) goto loc_822E5CE8;
	// lwz r11,396(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 396);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x822e5ce8
	if (cr6.eq) goto loc_822E5CE8;
	// bl 0x82177a08
	ctx.lr = 0x822E5CE8;
	sub_82177A08(ctx, base);
loc_822E5CE8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r10,416(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x822e5d0c
	if (!cr6.lt) goto loc_822E5D0C;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e5d0c
	if (cr6.eq) goto loc_822E5D0C;
	// bl 0x82177a08
	ctx.lr = 0x822E5D0C;
	sub_82177A08(ctx, base);
loc_822E5D0C:
	// lwz r31,436(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 436);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e5d28
	if (cr6.eq) goto loc_822E5D28;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821852a8
	ctx.lr = 0x822E5D20;
	sub_821852A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822E5D28;
	sub_82130588(ctx, base);
loc_822E5D28:
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

__attribute__((alias("__imp__sub_822E5D40"))) PPC_WEAK_FUNC(sub_822E5D40);
PPC_FUNC_IMPL(__imp__sub_822E5D40) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x822e5d70
	if (cr6.eq) goto loc_822E5D70;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x822e5048
	ctx.lr = 0x822E5D70;
	sub_822E5048(ctx, base);
loc_822E5D70:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x822E5D7C;
	sub_82180430(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,1
	r11.s64 = 1;
	// lwz r7,420(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// li r8,18
	ctx.r8.s64 = 18;
	// lwz r6,416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r11.u8);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// addi r4,r4,-6704
	ctx.r4.s64 = ctx.r4.s64 + -6704;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822E5DD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,408(r31)
	PPC_STORE_U32(r31.u32 + 408, ctx.r3.u32);
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x822e5df8
	if (cr6.eq) goto loc_822E5DF8;
	// lwz r11,436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5df8
	if (cr6.eq) goto loc_822E5DF8;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-24876(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24876, r11.u32);
loc_822E5DF8:
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

__attribute__((alias("__imp__sub_822E5E10"))) PPC_WEAK_FUNC(sub_822E5E10);
PPC_FUNC_IMPL(__imp__sub_822E5E10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d8
	ctx.lr = 0x822E5E24;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f4
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f4.f64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// lfs f0,-15876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15876);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x822e5e54
	if (!cr6.lt) goto loc_822E5E54;
	// fneg f2,f31
	ctx.f2.u64 = f31.u64 ^ 0x8000000000000000;
	// b 0x822e5e94
	goto loc_822E5E94;
loc_822E5E54:
	// bl 0x82178848
	ctx.lr = 0x822E5E58;
	sub_82178848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e5e70
	if (cr6.eq) goto loc_822E5E70;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f12,-6164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6164);
	ctx.f12.f64 = double(temp.f32);
	// b 0x822e5e78
	goto loc_822E5E78;
loc_822E5E70:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f12,-6168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6168);
	ctx.f12.f64 = double(temp.f32);
loc_822E5E78:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f13,6876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6876);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,6872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 6872);
	f0.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f13,f31,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f31.f64 + f0.f64));
	// fmuls f2,f11,f12
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
loc_822E5E94:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// fmr f4,f28
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f28.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r10,r11,45
	ctx.r10.s64 = r11.s64 + 45;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// bl 0x8217d460
	ctx.lr = 0x822E5EB8;
	sub_8217D460(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba24
	ctx.lr = 0x822E5EC4;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E5ED4"))) PPC_WEAK_FUNC(sub_822E5ED4);
PPC_FUNC_IMPL(__imp__sub_822E5ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E5ED8"))) PPC_WEAK_FUNC(sub_822E5ED8);
PPC_FUNC_IMPL(__imp__sub_822E5ED8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822E5EE0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-18004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// bl 0x82304df0
	ctx.lr = 0x822E5EFC;
	sub_82304DF0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r8,384(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r30,r11,-8112
	r30.s64 = r11.s64 + -8112;
	// lwz r11,-27788(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27788);
	// lwz r28,404(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// addi r9,r11,99
	ctx.r9.s64 = r11.s64 + 99;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r7,r31
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// ble cr6,0x822e604c
	if (!cr6.gt) goto loc_822E604C;
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e604c
	if (!cr6.eq) goto loc_822E604C;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r7,352(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,102(r1)
	PPC_STORE_U8(ctx.r1.u32 + 102, r11.u8);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// stb r10,2(r30)
	PPC_STORE_U8(r30.u32 + 2, ctx.r10.u8);
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// lwz r9,-27692(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27692);
	// lfs f31,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stb r10,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, ctx.r10.u8);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stb r10,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// bne cr6,0x822e5f88
	if (!cr6.eq) goto loc_822E5F88;
	// li r6,4
	ctx.r6.s64 = 4;
loc_822E5F88:
	// lbz r10,393(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e5f98
	if (cr6.eq) goto loc_822E5F98;
	// li r6,4
	ctx.r6.s64 = 4;
loc_822E5F98:
	// lbz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 432);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e5fc0
	if (cr6.eq) goto loc_822E5FC0;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822e5fc0
	if (!cr6.eq) goto loc_822E5FC0;
	// lbz r10,433(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 433);
	// b 0x822e5fc4
	goto loc_822E5FC4;
loc_822E5FC0:
	// lbz r10,373(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 373);
loc_822E5FC4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e5fd4
	if (cr6.eq) goto loc_822E5FD4;
	// li r6,4
	ctx.r6.s64 = 4;
loc_822E5FD4:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e6008
	if (cr6.eq) goto loc_822E6008;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lbz r9,6588(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6588);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e6008
	if (cr6.eq) goto loc_822E6008;
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// blt cr6,0x822e6004
	if (cr6.lt) goto loc_822E6004;
	// lwz r10,416(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmpwi cr6,r10,640
	cr6.compare<int32_t>(ctx.r10.s32, 640, xer);
	// bgt cr6,0x822e6008
	if (cr6.gt) goto loc_822E6008;
loc_822E6004:
	// li r11,12
	r11.s64 = 12;
loc_822E6008:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217a470
	ctx.lr = 0x822E6020;
	sub_8217A470(ctx, base);
	// lbz r11,368(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 368);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e6088
	if (!cr6.eq) goto loc_822E6088;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178370
	ctx.lr = 0x822E6048;
	sub_82178370(ctx, base);
	// b 0x822e6088
	goto loc_822E6088;
loc_822E604C:
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,2(r30)
	PPC_STORE_U8(r30.u32 + 2, r11.u8);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,-25232(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25232);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822E6088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E6088:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,-4916(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4916);
	// stw r28,128(r11)
	PPC_STORE_U32(r11.u32 + 128, r28.u32);
	// lwz r11,-4916(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4916);
	// stw r29,132(r11)
	PPC_STORE_U32(r11.u32 + 132, r29.u32);
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e60b8
	if (cr6.eq) goto loc_822E60B8;
	// stw r28,112(r11)
	PPC_STORE_U32(r11.u32 + 112, r28.u32);
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// stw r29,116(r11)
	PPC_STORE_U32(r11.u32 + 116, r29.u32);
loc_822E60B8:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e60d4
	if (cr6.eq) goto loc_822E60D4;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x8241e428
	ctx.lr = 0x822E60D4;
	sub_8241E428(ctx, base);
loc_822E60D4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E60E0"))) PPC_WEAK_FUNC(sub_822E60E0);
PPC_FUNC_IMPL(__imp__sub_822E60E0) {
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
	ctx.lr = 0x822E60E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,6616(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 6616);
	// bl 0x8217f768
	ctx.lr = 0x822E6100;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822E610C;
	sub_8217F768(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x822E6118;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8217f768
	ctx.lr = 0x822E6124;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217f768
	ctx.lr = 0x822E6130;
	sub_8217F768(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x822E613C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x822E6148;
	sub_8217F768(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x822E6154;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x822E6160;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x822E616C;
	sub_8217F768(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// li r3,10
	ctx.r3.s64 = 10;
	// addi r8,r9,17328
	ctx.r8.s64 = ctx.r9.s64 + 17328;
	// lwz r4,6612(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6612);
	// stw r4,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r4.u32);
	// bl 0x8217f768
	ctx.lr = 0x822E6188;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x822E6194;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x8217f768
	ctx.lr = 0x822E61A0;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// bl 0x8217f768
	ctx.lr = 0x822E61AC;
	sub_8217F768(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r31,r11,6600
	r31.s64 = r11.s64 + 6600;
	// lbz r7,-9(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + -9);
	// subfic r6,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r5,30
	r11.u64 = ctx.r5.u32 & 0x3;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x82189e20
	ctx.lr = 0x822E61D0;
	sub_82189E20(ctx, base);
	// lbz r4,-9(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + -9);
	// li r3,4
	ctx.r3.s64 = 4;
	// subfic r11,r4,0
	xer.ca = ctx.r4.u32 <= 0;
	r11.s64 = 0 - ctx.r4.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r10,30
	r11.u64 = ctx.r10.u32 & 0x3;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x82189e20
	ctx.lr = 0x822E61EC;
	sub_82189E20(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r11,-8096
	r30.s64 = r11.s64 + -8096;
	// lbz r9,-3(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -3);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e6210
	if (cr6.eq) goto loc_822E6210;
	// lbz r11,-9(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -9);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e6214
	if (!cr6.eq) goto loc_822E6214;
loc_822E6210:
	// li r4,1
	ctx.r4.s64 = 1;
loc_822E6214:
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82189e20
	ctx.lr = 0x822E621C;
	sub_82189E20(ctx, base);
	// lbz r11,432(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 432);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6244
	if (cr6.eq) goto loc_822E6244;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822e6244
	if (!cr6.eq) goto loc_822E6244;
	// lbz r11,433(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 433);
	// b 0x822e6248
	goto loc_822E6248;
loc_822E6244:
	// lbz r11,373(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 373);
loc_822E6248:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r4,16
	ctx.r4.s64 = 16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e625c
	if (!cr6.eq) goto loc_822E625C;
	// lwz r4,-4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -4);
loc_822E625C:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82189e20
	ctx.lr = 0x822E6264;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e20
	ctx.lr = 0x822E6270;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82189e20
	ctx.lr = 0x822E627C;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82189e20
	ctx.lr = 0x822E6288;
	sub_82189E20(ctx, base);
	// li r3,7
	ctx.r3.s64 = 7;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82189ee0
	ctx.lr = 0x822E6294;
	sub_82189EE0(ctx, base);
	// li r30,0
	r30.s64 = 0;
loc_822E6298:
	// li r4,56
	ctx.r4.s64 = 56;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82177df0
	ctx.lr = 0x822E62A8;
	sub_82177DF0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x822e6298
	if (cr6.lt) goto loc_822E6298;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E62BC"))) PPC_WEAK_FUNC(sub_822E62BC);
PPC_FUNC_IMPL(__imp__sub_822E62BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E62C0"))) PPC_WEAK_FUNC(sub_822E62C0);
PPC_FUNC_IMPL(__imp__sub_822E62C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// addi r31,r11,-8128
	r31.s64 = r11.s64 + -8128;
	// lbz r4,-8128(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + -8128);
	// bl 0x8217f768
	ctx.lr = 0x822E62F0;
	sub_8217F768(ctx, base);
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,369(r30)
	PPC_STORE_U8(r30.u32 + 369, ctx.r10.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e6318
	if (cr6.eq) goto loc_822E6318;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,7444
	r11.s64 = r11.s64 + 7444;
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// b 0x822e633c
	goto loc_822E633C;
loc_822E6318:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,-27692(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27692);
	// lfs f1,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82179778
	ctx.lr = 0x822E632C;
	sub_82179778(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,7444
	r11.s64 = r11.s64 + 7444;
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fdivs f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 / ctx.f1.f64));
loc_822E633C:
	// bl 0x8217f6f0
	ctx.lr = 0x822E6340;
	sub_8217F6F0(ctx, base);
	// lbz r11,368(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 368);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e635c
	if (!cr6.eq) goto loc_822E635C;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x8241bd08
	ctx.lr = 0x822E635C;
	sub_8241BD08(ctx, base);
loc_822E635C:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x82190890
	ctx.lr = 0x822E6364;
	sub_82190890(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f0f38
	ctx.lr = 0x822E6374;
	sub_822F0F38(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_822E6390"))) PPC_WEAK_FUNC(sub_822E6390);
PPC_FUNC_IMPL(__imp__sub_822E6390) {
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
	ctx.lr = 0x822E6398;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// lwz r31,-8092(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lwz r30,184(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822e63c4
	if (cr6.eq) goto loc_822E63C4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217cb48
	ctx.lr = 0x822E63B8;
	sub_8217CB48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822E63C0;
	sub_82130588(ctx, base);
	// lwz r31,-8092(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -8092);
loc_822E63C4:
	// lwz r30,180(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822e63e4
	if (cr6.eq) goto loc_822E63E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217cb48
	ctx.lr = 0x822E63D8;
	sub_8217CB48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822E63E0;
	sub_82130588(ctx, base);
	// lwz r31,-8092(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -8092);
loc_822E63E4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e63fc
	if (cr6.eq) goto loc_822E63FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e5c78
	ctx.lr = 0x822E63F4;
	sub_822E5C78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822E63FC;
	sub_82130588(ctx, base);
loc_822E63FC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E6404"))) PPC_WEAK_FUNC(sub_822E6404);
PPC_FUNC_IMPL(__imp__sub_822E6404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6408"))) PPC_WEAK_FUNC(sub_822E6408);
PPC_FUNC_IMPL(__imp__sub_822E6408) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x822E6410;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r16,r11,-8111
	r16.s64 = r11.s64 + -8111;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r29,r10,6588
	r29.s64 = ctx.r10.s64 + 6588;
	// lwz r28,384(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 384);
	// lbz r11,2(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 2);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// lwz r3,21764(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 21764);
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stb r11,11(r16)
	PPC_STORE_U8(r16.u32 + 11, r11.u8);
	// bl 0x82612348
	ctx.lr = 0x822E6450;
	sub_82612348(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822f0f38
	ctx.lr = 0x822E6468;
	sub_822F0F38(ctx, base);
	// lbz r9,-1(r16)
	ctx.r9.u64 = PPC_LOAD_U8(r16.u32 + -1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e64a8
	if (cr6.eq) goto loc_822E64A8;
	// lbz r11,1(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e64a8
	if (cr6.eq) goto loc_822E64A8;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e64a8
	if (cr6.eq) goto loc_822E64A8;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x822e64a0
	if (cr6.lt) goto loc_822E64A0;
	// lwz r11,416(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 416);
	// cmpwi cr6,r11,640
	cr6.compare<int32_t>(r11.s32, 640, xer);
	// ble cr6,0x822e64a8
	if (!cr6.gt) goto loc_822E64A8;
loc_822E64A0:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x822e64ac
	goto loc_822E64AC;
loc_822E64A8:
	// li r4,2
	ctx.r4.s64 = 2;
loc_822E64AC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r11,r11,-28076
	r11.s64 = r11.s64 + -28076;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8241e428
	ctx.lr = 0x822E64C0;
	sub_8241E428(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r15,0
	r15.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x822e64fc
	if (!cr6.eq) goto loc_822E64FC;
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e64e8
	if (cr6.eq) goto loc_822E64E8;
	// stw r15,112(r11)
	PPC_STORE_U32(r11.u32 + 112, r15.u32);
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// stw r15,116(r11)
	PPC_STORE_U32(r11.u32 + 116, r15.u32);
loc_822E64E8:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-4916(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4916);
	// stw r15,128(r11)
	PPC_STORE_U32(r11.u32 + 128, r15.u32);
	// lwz r11,-4916(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4916);
	// stw r15,132(r11)
	PPC_STORE_U32(r11.u32 + 132, r15.u32);
loc_822E64FC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r9,r11,-7924
	ctx.r9.s64 = r11.s64 + -7924;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6524
	if (cr6.eq) goto loc_822E6524;
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6524
	if (cr6.eq) goto loc_822E6524;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,316(r11)
	PPC_STORE_U32(r11.u32 + 316, ctx.r10.u32);
loc_822E6524:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822e60e0
	ctx.lr = 0x822E652C;
	sub_822E60E0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lbz r9,-7904(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -7904);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lwz r8,416(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// lwz r7,420(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r4,r7
	ctx.r4.s64 = ctx.r7.s32;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// fdivs f4,f31,f7
	ctx.f4.f64 = double(float(f31.f64 / ctx.f7.f64));
	// stfs f4,120(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// stfs f6,116(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fdivs f5,f31,f8
	ctx.f5.f64 = double(float(f31.f64 / ctx.f8.f64));
	// stfs f5,124(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// beq cr6,0x822e65d0
	if (cr6.eq) goto loc_822E65D0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,5640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 5640);
	f0.f64 = double(temp.f32);
	// lfs f13,5636(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5636);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6684(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -6684);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-6688(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6688);
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
loc_822E65D0:
	// lwz r11,452(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 452);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822e65f0
	if (!cr6.eq) goto loc_822E65F0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-6696
	ctx.r3.s64 = r11.s64 + -6696;
	// bl 0x8218a4e8
	ctx.lr = 0x822E65EC;
	sub_8218A4E8(ctx, base);
	// stw r3,452(r27)
	PPC_STORE_U32(r27.u32 + 452, ctx.r3.u32);
loc_822E65F0:
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r3,452(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 452);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8218aef8
	ctx.lr = 0x822E6604;
	sub_8218AEF8(ctx, base);
	// lbz r10,371(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 371);
	// lwz r11,448(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 448);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e6620
	if (cr6.eq) goto loc_822E6620;
	// lbz r10,435(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 435);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e6624
	if (cr6.eq) goto loc_822E6624;
loc_822E6620:
	// rlwinm r11,r11,0,22,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
loc_822E6624:
	// lwz r17,364(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 364);
	// lis r14,10240
	r14.s64 = 671088640;
	// lwz r10,380(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 380);
	// and r21,r17,r11
	r21.u64 = r17.u64 & r11.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822e6648
	if (!cr6.eq) goto loc_822E6648;
	// lbz r11,373(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 373);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6654
	if (cr6.eq) goto loc_822E6654;
loc_822E6648:
	// cmpw cr6,r17,r14
	cr6.compare<int32_t>(r17.s32, r14.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822e6658
	if (!cr6.eq) goto loc_822E6658;
loc_822E6654:
	// mr r11,r15
	r11.u64 = r15.u64;
loc_822E6658:
	// lbz r10,434(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 434);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stb r9,375(r27)
	PPC_STORE_U8(r27.u32 + 375, ctx.r9.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822e66a0
	if (!cr6.eq) goto loc_822E66A0;
	// lbz r10,393(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 393);
	// lwz r9,-12288(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e6690
	if (cr6.eq) goto loc_822E6690;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x822e66a0
	if (!cr6.eq) goto loc_822E66A0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822e66a8
	if (!cr6.eq) goto loc_822E66A8;
loc_822E6690:
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822e66a8
	if (!cr6.eq) goto loc_822E66A8;
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// b 0x822e66a4
	goto loc_822E66A4;
loc_822E66A0:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822E66A4:
	// stw r10,-12288(r11)
	PPC_STORE_U32(r11.u32 + -12288, ctx.r10.u32);
loc_822E66A8:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r30,1
	r30.s64 = 1;
	// mr r24,r27
	r24.u64 = r27.u64;
	// lis r18,1
	r18.s64 = 65536;
	// lis r22,-32124
	r22.s64 = -2105278464;
	// lis r19,16384
	r19.s64 = 1073741824;
	// lis r26,-32131
	r26.s64 = -2105737216;
	// lis r25,-32120
	r25.s64 = -2105016320;
	// lis r20,-32130
	r20.s64 = -2105671680;
	// addi r23,r11,-31280
	r23.s64 = r11.s64 + -31280;
loc_822E66D0:
	// stw r30,356(r27)
	PPC_STORE_U32(r27.u32 + 356, r30.u32);
	// cmpw cr6,r17,r14
	cr6.compare<int32_t>(r17.s32, r14.s32, xer);
	// stw r21,360(r27)
	PPC_STORE_U32(r27.u32 + 360, r21.u32);
	// bne cr6,0x822e66f0
	if (!cr6.eq) goto loc_822E66F0;
	// rlwinm r11,r30,0,2,4
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x38000000;
	// rlwinm r11,r11,0,4,2
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// b 0x822e66f4
	goto loc_822E66F4;
loc_822E66F0:
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
loc_822E66F4:
	// beq cr6,0x822e6908
	if (cr6.eq) goto loc_822E6908;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6728
	if (cr6.eq) goto loc_822E6728;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x822e6728
	if (!cr6.gt) goto loc_822E6728;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// blt cr6,0x822e6720
	if (cr6.lt) goto loc_822E6720;
	// lwz r11,416(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 416);
	// cmpwi cr6,r11,640
	cr6.compare<int32_t>(r11.s32, 640, xer);
	// bgt cr6,0x822e6728
	if (cr6.gt) goto loc_822E6728;
loc_822E6720:
	// li r11,1
	r11.s64 = 1;
	// b 0x822e672c
	goto loc_822E672C;
loc_822E6728:
	// mr r11,r15
	r11.u64 = r15.u64;
loc_822E672C:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x822e67a4
	if (!cr6.gt) goto loc_822E67A4;
	// lbz r11,368(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 368);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6754
	if (cr6.eq) goto loc_822E6754;
	// cmpwi cr6,r30,2048
	cr6.compare<int32_t>(r30.s32, 2048, xer);
	// beq cr6,0x822e6768
	if (cr6.eq) goto loc_822E6768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e6770
	if (!cr6.eq) goto loc_822E6770;
loc_822E6754:
	// cmpw cr6,r30,r18
	cr6.compare<int32_t>(r30.s32, r18.s32, xer);
	// bne cr6,0x822e6770
	if (!cr6.eq) goto loc_822E6770;
	// rlwinm r11,r21,0,10,14
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 0) & 0x3E0000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e67d0
	if (cr6.eq) goto loc_822E67D0;
loc_822E6768:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822e5ed8
	ctx.lr = 0x822E6770;
	sub_822E5ED8(ctx, base);
loc_822E6770:
	// cmpwi cr6,r30,4096
	cr6.compare<int32_t>(r30.s32, 4096, xer);
	// bne cr6,0x822e67a4
	if (!cr6.eq) goto loc_822E67A4;
	// lbz r11,-1(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + -1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e67d0
	if (cr6.eq) goto loc_822E67D0;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e67d0
	if (cr6.eq) goto loc_822E67D0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8241c7c0
	ctx.lr = 0x822E67A0;
	sub_8241C7C0(ctx, base);
	// b 0x822e67d0
	goto loc_822E67D0;
loc_822E67A4:
	// cmpwi cr6,r30,8192
	cr6.compare<int32_t>(r30.s32, 8192, xer);
	// bne cr6,0x822e67d0
	if (!cr6.eq) goto loc_822E67D0;
	// lbz r11,-1(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + -1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e67d0
	if (cr6.eq) goto loc_822E67D0;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e67d0
	if (cr6.eq) goto loc_822E67D0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8241cb08
	ctx.lr = 0x822E67D0;
	sub_8241CB08(ctx, base);
loc_822E67D0:
	// rlwinm r11,r30,0,23,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822e67f4
	if (!cr6.eq) goto loc_822E67F4;
	// lwz r11,22080(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 22080);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r27
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// bl 0x8217c658
	ctx.lr = 0x822E67F4;
	sub_8217C658(ctx, base);
loc_822E67F4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822e55d0
	ctx.lr = 0x822E6800;
	sub_822E55D0(ctx, base);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6824
	if (cr6.eq) goto loc_822E6824;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E6824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E6824:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-7436(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -7436);
	// bl 0x822f7550
	ctx.lr = 0x822E6830;
	sub_822F7550(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-26876(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -26876);
	// stb r11,17292(r26)
	PPC_STORE_U8(r26.u32 + 17292, r11.u8);
	// bl 0x8217c088
	ctx.lr = 0x822E6844;
	sub_8217C088(ctx, base);
	// and r10,r30,r21
	ctx.r10.u64 = r30.u64 & r21.u64;
	// mr r11,r15
	r11.u64 = r15.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,17292(r26)
	PPC_STORE_U8(r26.u32 + 17292, r11.u8);
	// beq cr6,0x822e68d8
	if (cr6.eq) goto loc_822E68D8;
	// addi r29,r27,128
	r29.s64 = r27.s64 + 128;
	// li r28,13
	r28.s64 = 13;
loc_822E6860:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e68c4
	if (cr6.eq) goto loc_822E68C4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// and r10,r11,r30
	ctx.r10.u64 = r11.u64 & r30.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822e68c4
	if (cr6.eq) goto loc_822E68C4;
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
	ctx.lr = 0x822E6894;
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
	ctx.lr = 0x822E68AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822E68C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E68C4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822e6860
	if (!cr0.eq) goto loc_822E6860;
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,88(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_822E68D8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-7436(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -7436);
	// bl 0x822f7570
	ctx.lr = 0x822E68E4;
	sub_822F7570(ctx, base);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6908
	if (cr6.eq) goto loc_822E6908;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E6908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E6908:
	// rlwinm r30,r30,1,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r30,r19
	cr6.compare<int32_t>(r30.s32, r19.s32, xer);
	// bne cr6,0x822e66d0
	if (!cr6.eq) goto loc_822E66D0;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,21764(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 21764);
	// bl 0x82612348
	ctx.lr = 0x822E6928;
	sub_82612348(ctx, base);
	// lbz r11,1(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1);
	// stb r11,0(r16)
	PPC_STORE_U8(r16.u32 + 0, r11.u8);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_822E693C"))) PPC_WEAK_FUNC(sub_822E693C);
PPC_FUNC_IMPL(__imp__sub_822E693C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6940"))) PPC_WEAK_FUNC(sub_822E6940);
PPC_FUNC_IMPL(__imp__sub_822E6940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-6284
	ctx.r10.s64 = r11.s64 + -6284;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822E6950"))) PPC_WEAK_FUNC(sub_822E6950);
PPC_FUNC_IMPL(__imp__sub_822E6950) {
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
	// addi r10,r11,-6284
	ctx.r10.s64 = r11.s64 + -6284;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x822E697C;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e6994
	if (cr6.eq) goto loc_822E6994;
	// bl 0x82130588
	ctx.lr = 0x822E6990;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E6994:
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

__attribute__((alias("__imp__sub_822E69AC"))) PPC_WEAK_FUNC(sub_822E69AC);
PPC_FUNC_IMPL(__imp__sub_822E69AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E69B0"))) PPC_WEAK_FUNC(sub_822E69B0);
PPC_FUNC_IMPL(__imp__sub_822E69B0) {
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
	// lwz r31,8(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e69f8
	if (cr6.eq) goto loc_822E69F8;
loc_822E69D4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E69EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822e69d4
	if (!cr6.eq) goto loc_822E69D4;
loc_822E69F8:
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

__attribute__((alias("__imp__sub_822E6A10"))) PPC_WEAK_FUNC(sub_822E6A10);
PPC_FUNC_IMPL(__imp__sub_822E6A10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// bne cr6,0x822e6a2c
	if (!cr6.eq) goto loc_822E6A2C;
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_822E6A2C:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6a58
	if (cr6.eq) goto loc_822E6A58;
loc_822E6A38:
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e6a58
	if (cr6.eq) goto loc_822E6A58;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beq cr6,0x822e6a68
	if (cr6.eq) goto loc_822E6A68;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e6a38
	if (!cr6.eq) goto loc_822E6A38;
loc_822E6A58:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// addi r3,r11,-6264
	ctx.r3.s64 = r11.s64 + -6264;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822E6A68:
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r9,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E6A7C"))) PPC_WEAK_FUNC(sub_822E6A7C);
PPC_FUNC_IMPL(__imp__sub_822E6A7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6A80"))) PPC_WEAK_FUNC(sub_822E6A80);
PPC_FUNC_IMPL(__imp__sub_822E6A80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_822E6A8C:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_822E6A94:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822e6ab8
	if (cr6.eq) goto loc_822E6AB8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822e6a94
	if (cr6.eq) goto loc_822E6A94;
loc_822E6AB8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822e6a8c
	if (!cr6.eq) goto loc_822E6A8C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E6AD0"))) PPC_WEAK_FUNC(sub_822E6AD0);
PPC_FUNC_IMPL(__imp__sub_822E6AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// stw r3,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r3.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E6AE4"))) PPC_WEAK_FUNC(sub_822E6AE4);
PPC_FUNC_IMPL(__imp__sub_822E6AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6AE8"))) PPC_WEAK_FUNC(sub_822E6AE8);
PPC_FUNC_IMPL(__imp__sub_822E6AE8) {
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
	ctx.lr = 0x822E6AF0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e6b30
	if (cr6.eq) goto loc_822E6B30;
loc_822E6B08:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x822e6b24
	if (!cr6.eq) goto loc_822E6B24;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e6b24
	if (cr6.eq) goto loc_822E6B24;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822dad18
	ctx.lr = 0x822E6B24;
	sub_822DAD18(ctx, base);
loc_822E6B24:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822e6b08
	if (!cr6.eq) goto loc_822E6B08;
loc_822E6B30:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E6B38"))) PPC_WEAK_FUNC(sub_822E6B38);
PPC_FUNC_IMPL(__imp__sub_822E6B38) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-6284
	ctx.r10.s64 = r11.s64 + -6284;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822E6B60;
	sub_821B5A60(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822E6B80"))) PPC_WEAK_FUNC(sub_822E6B80);
PPC_FUNC_IMPL(__imp__sub_822E6B80) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-6284
	ctx.r10.s64 = r11.s64 + -6284;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822E6BA8;
	sub_821B5A60(ctx, base);
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

__attribute__((alias("__imp__sub_822E6BC0"))) PPC_WEAK_FUNC(sub_822E6BC0);
PPC_FUNC_IMPL(__imp__sub_822E6BC0) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-6204
	ctx.r10.s64 = r11.s64 + -6204;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822e6bf4
	if (cr6.eq) goto loc_822E6BF4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822e6a10
	ctx.lr = 0x822E6BF4;
	sub_822E6A10(ctx, base);
loc_822E6BF4:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822E6BFC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822E6C04;
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

__attribute__((alias("__imp__sub_822E6C18"))) PPC_WEAK_FUNC(sub_822E6C18);
PPC_FUNC_IMPL(__imp__sub_822E6C18) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821378b8
	ctx.lr = 0x822E6C34;
	sub_821378B8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822E6C4C"))) PPC_WEAK_FUNC(sub_822E6C4C);
PPC_FUNC_IMPL(__imp__sub_822E6C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6C50"))) PPC_WEAK_FUNC(sub_822E6C50);
PPC_FUNC_IMPL(__imp__sub_822E6C50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822e6c74
	if (cr6.eq) goto loc_822E6C74;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
loc_822E6C74:
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E6C7C"))) PPC_WEAK_FUNC(sub_822E6C7C);
PPC_FUNC_IMPL(__imp__sub_822E6C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6C80"))) PPC_WEAK_FUNC(sub_822E6C80);
PPC_FUNC_IMPL(__imp__sub_822E6C80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// bne cr6,0x822e6c98
	if (!cr6.eq) goto loc_822E6C98;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
loc_822E6C98:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e6ca4
	if (cr6.eq) goto loc_822E6CA4;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_822E6CA4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E6CB4"))) PPC_WEAK_FUNC(sub_822E6CB4);
PPC_FUNC_IMPL(__imp__sub_822E6CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6CB8"))) PPC_WEAK_FUNC(sub_822E6CB8);
PPC_FUNC_IMPL(__imp__sub_822E6CB8) {
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
	// lwz r31,20(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e6d00
	if (cr6.eq) goto loc_822E6D00;
loc_822E6CDC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E6CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822e6cdc
	if (!cr6.eq) goto loc_822E6CDC;
loc_822E6D00:
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

__attribute__((alias("__imp__sub_822E6D18"))) PPC_WEAK_FUNC(sub_822E6D18);
PPC_FUNC_IMPL(__imp__sub_822E6D18) {
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
	// addi r10,r11,-6204
	ctx.r10.s64 = r11.s64 + -6204;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822e6d54
	if (cr6.eq) goto loc_822E6D54;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822e6a10
	ctx.lr = 0x822E6D54;
	sub_822E6A10(ctx, base);
loc_822E6D54:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822E6D5C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822E6D64;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6d7c
	if (cr6.eq) goto loc_822E6D7C;
	// bl 0x82130588
	ctx.lr = 0x822E6D78;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E6D7C:
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

__attribute__((alias("__imp__sub_822E6D94"))) PPC_WEAK_FUNC(sub_822E6D94);
PPC_FUNC_IMPL(__imp__sub_822E6D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6D98"))) PPC_WEAK_FUNC(sub_822E6D98);
PPC_FUNC_IMPL(__imp__sub_822E6D98) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-6204
	ctx.r10.s64 = r11.s64 + -6204;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822E6DC0;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x822E6DC8;
	sub_821B5A60(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821b5a60
	ctx.lr = 0x822E6DD0;
	sub_821B5A60(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821b5a60
	ctx.lr = 0x822E6DD8;
	sub_821B5A60(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
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

__attribute__((alias("__imp__sub_822E6E0C"))) PPC_WEAK_FUNC(sub_822E6E0C);
PPC_FUNC_IMPL(__imp__sub_822E6E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6E10"))) PPC_WEAK_FUNC(sub_822E6E10);
PPC_FUNC_IMPL(__imp__sub_822E6E10) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-6204
	ctx.r10.s64 = r11.s64 + -6204;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822E6E38;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x822E6E40;
	sub_821B5A60(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821b5a60
	ctx.lr = 0x822E6E48;
	sub_821B5A60(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821b5a60
	ctx.lr = 0x822E6E50;
	sub_821B5A60(ctx, base);
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

__attribute__((alias("__imp__sub_822E6E68"))) PPC_WEAK_FUNC(sub_822E6E68);
PPC_FUNC_IMPL(__imp__sub_822E6E68) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-6188
	ctx.r10.s64 = r11.s64 + -6188;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822e6eb8
	if (cr6.eq) goto loc_822E6EB8;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x822e6eb8
	if (!cr0.eq) goto loc_822E6EB8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E6EB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E6EB8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822E6EC0;
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

__attribute__((alias("__imp__sub_822E6ED4"))) PPC_WEAK_FUNC(sub_822E6ED4);
PPC_FUNC_IMPL(__imp__sub_822E6ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E6ED8"))) PPC_WEAK_FUNC(sub_822E6ED8);
PPC_FUNC_IMPL(__imp__sub_822E6ED8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-6188
	ctx.r10.s64 = r11.s64 + -6188;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822e6f30
	if (cr6.eq) goto loc_822E6F30;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x822e6f30
	if (!cr0.eq) goto loc_822E6F30;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E6F30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E6F30:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822E6F38;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e6f50
	if (cr6.eq) goto loc_822E6F50;
	// bl 0x82130588
	ctx.lr = 0x822E6F4C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E6F50:
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

__attribute__((alias("__imp__sub_822E6F68"))) PPC_WEAK_FUNC(sub_822E6F68);
PPC_FUNC_IMPL(__imp__sub_822E6F68) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-6188
	ctx.r10.s64 = r11.s64 + -6188;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822E6F90;
	sub_821B5A60(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821b5a60
	ctx.lr = 0x822E6F98;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x822E6FA0;
	sub_821B5A60(ctx, base);
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
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822E6FC8"))) PPC_WEAK_FUNC(sub_822E6FC8);
PPC_FUNC_IMPL(__imp__sub_822E6FC8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-6188
	ctx.r10.s64 = r11.s64 + -6188;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822E6FF0;
	sub_821B5A60(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821b5a60
	ctx.lr = 0x822E6FF8;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x822E7000;
	sub_821B5A60(ctx, base);
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

__attribute__((alias("__imp__sub_822E7018"))) PPC_WEAK_FUNC(sub_822E7018);
PPC_FUNC_IMPL(__imp__sub_822E7018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-6172
	ctx.r10.s64 = r11.s64 + -6172;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822E7028"))) PPC_WEAK_FUNC(sub_822E7028);
PPC_FUNC_IMPL(__imp__sub_822E7028) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-6172
	ctx.r10.s64 = r11.s64 + -6172;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E7038"))) PPC_WEAK_FUNC(sub_822E7038);
PPC_FUNC_IMPL(__imp__sub_822E7038) {
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
	// addi r10,r11,-6172
	ctx.r10.s64 = r11.s64 + -6172;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x822E7064;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e707c
	if (cr6.eq) goto loc_822E707C;
	// bl 0x82130588
	ctx.lr = 0x822E7078;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E707C:
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

__attribute__((alias("__imp__sub_822E7094"))) PPC_WEAK_FUNC(sub_822E7094);
PPC_FUNC_IMPL(__imp__sub_822E7094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E7098"))) PPC_WEAK_FUNC(sub_822E7098);
PPC_FUNC_IMPL(__imp__sub_822E7098) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-5868
	ctx.r3.s64 = r11.s64 + -5868;
	// bl 0x82188248
	ctx.lr = 0x822E70B0;
	sub_82188248(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-5876
	ctx.r3.s64 = ctx.r10.s64 + -5876;
	// bl 0x82188248
	ctx.lr = 0x822E70BC;
	sub_82188248(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r9,-5888
	ctx.r3.s64 = ctx.r9.s64 + -5888;
	// bl 0x82188248
	ctx.lr = 0x822E70C8;
	sub_82188248(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E70D8"))) PPC_WEAK_FUNC(sub_822E70D8);
PPC_FUNC_IMPL(__imp__sub_822E70D8) {
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
	ctx.lr = 0x822E70E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-5868
	ctx.r3.s64 = r11.s64 + -5868;
	// bl 0x821881b8
	ctx.lr = 0x822E70F4;
	sub_821881B8(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-5876
	ctx.r3.s64 = ctx.r10.s64 + -5876;
	// bl 0x821881b8
	ctx.lr = 0x822E7104;
	sub_821881B8(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r9,-5888
	ctx.r3.s64 = ctx.r9.s64 + -5888;
	// bl 0x821881b8
	ctx.lr = 0x822E7114;
	sub_821881B8(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r30,r7,-5600
	r30.s64 = ctx.r7.s64 + -5600;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24728);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E7144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
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
	ctx.lr = 0x822E717C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-5612
	ctx.r4.s64 = ctx.r10.s64 + -5612;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E7194;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-5636
	ctx.r4.s64 = ctx.r8.s64 + -5636;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E71B0;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-5656
	ctx.r4.s64 = ctx.r4.s64 + -5656;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E71CC;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r3,-5672
	ctx.r4.s64 = ctx.r3.s64 + -5672;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E71E8;
	sub_8218A568(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-5688
	ctx.r4.s64 = ctx.r9.s64 + -5688;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E7204;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-5704
	ctx.r4.s64 = ctx.r8.s64 + -5704;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E7220;
	sub_8218A568(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-5720
	ctx.r4.s64 = ctx.r6.s64 + -5720;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E723C;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-5728
	ctx.r4.s64 = ctx.r10.s64 + -5728;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E7258;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-5736
	ctx.r4.s64 = ctx.r9.s64 + -5736;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E7274;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-5748
	ctx.r4.s64 = ctx.r6.s64 + -5748;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E7290;
	sub_8218A568(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r5,-5784
	ctx.r4.s64 = ctx.r5.s64 + -5784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x822E72AC;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x822E72B4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e72c4
	if (cr6.eq) goto loc_822E72C4;
	// bl 0x82611298
	ctx.lr = 0x822E72C0;
	sub_82611298(ctx, base);
	// b 0x822e72c8
	goto loc_822E72C8;
loc_822E72C4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822E72C8:
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r28,r11,-5792
	r28.s64 = r11.s64 + -5792;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E72F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822E72F8;
	sub_821C9A90(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-5828
	ctx.r4.s64 = ctx.r8.s64 + -5828;
	// bl 0x821ca540
	ctx.lr = 0x822E7308;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x822E7310;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e7320
	if (cr6.eq) goto loc_822E7320;
	// bl 0x82611298
	ctx.lr = 0x822E731C;
	sub_82611298(ctx, base);
	// b 0x822e7324
	goto loc_822E7324;
loc_822E7320:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822E7324:
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E7344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822E734C;
	sub_821C9A90(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-5860
	ctx.r4.s64 = ctx.r9.s64 + -5860;
	// bl 0x821ca540
	ctx.lr = 0x822E735C;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x822E7364;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e7374
	if (cr6.eq) goto loc_822E7374;
	// bl 0x82611298
	ctx.lr = 0x822E7370;
	sub_82611298(ctx, base);
	// b 0x822e7378
	goto loc_822E7378;
loc_822E7374:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822E7378:
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E7398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822E73A0;
	sub_821C9A90(ctx, base);
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// li r3,256
	ctx.r3.s64 = 256;
	// stw r29,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r29.u32);
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x822E73B8;
	sub_82130528(ctx, base);
	// li r30,32
	r30.s64 = 32;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822E73D0;
	sub_82130528(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822E73E4;
	sub_82130528(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// stw r29,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r29.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822E73F8;
	sub_82130528(ctx, base);
	// li r8,112
	ctx.r8.s64 = 112;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// stw r8,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r7,128(r31)
	PPC_STORE_U8(r31.u32 + 128, ctx.r7.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E7418"))) PPC_WEAK_FUNC(sub_822E7418);
PPC_FUNC_IMPL(__imp__sub_822E7418) {
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
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82130528
	ctx.lr = 0x822E742C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e7450
	if (cr6.eq) goto loc_822E7450;
	// bl 0x822e70d8
	ctx.lr = 0x822E7438;
	sub_822E70D8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,-7900(r11)
	PPC_STORE_U32(r11.u32 + -7900, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E7450:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7900(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7900, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E746C"))) PPC_WEAK_FUNC(sub_822E746C);
PPC_FUNC_IMPL(__imp__sub_822E746C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E7470"))) PPC_WEAK_FUNC(sub_822E7470);
PPC_FUNC_IMPL(__imp__sub_822E7470) {
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E74A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822e74d4
	if (!cr6.eq) goto loc_822E74D4;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822e7598
	if (!cr6.lt) goto loc_822E7598;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r8.u32);
	// b 0x822e7598
	goto loc_822E7598;
loc_822E74D4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E74E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x822e7554
	if (!cr6.eq) goto loc_822E7554;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e7528
	if (cr6.eq) goto loc_822E7528;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822e7598
	if (!cr6.lt) goto loc_822E7598;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r8.u32);
	// b 0x822e7598
	goto loc_822E7598;
loc_822E7528:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822e7598
	if (!cr6.lt) goto loc_822E7598;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r8.u32);
	// b 0x822e7598
	goto loc_822E7598;
loc_822E7554:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E7568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x822e7598
	if (!cr6.eq) goto loc_822E7598;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822e7598
	if (!cr6.lt) goto loc_822E7598;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
loc_822E7598:
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

__attribute__((alias("__imp__sub_822E75B0"))) PPC_WEAK_FUNC(sub_822E75B0);
PPC_FUNC_IMPL(__imp__sub_822E75B0) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r31,-7900(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -7900);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e75fc
	if (cr6.eq) goto loc_822E75FC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e75f4
	if (cr6.eq) goto loc_822E75F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E75F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E75F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822E75FC;
	sub_82130588(ctx, base);
loc_822E75FC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7900(r30)
	PPC_STORE_U32(r30.u32 + -7900, r11.u32);
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

__attribute__((alias("__imp__sub_822E761C"))) PPC_WEAK_FUNC(sub_822E761C);
PPC_FUNC_IMPL(__imp__sub_822E761C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E7620"))) PPC_WEAK_FUNC(sub_822E7620);
PPC_FUNC_IMPL(__imp__sub_822E7620) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91d0
	ctx.lr = 0x822E7628;
	// stfd f29,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f29.u64);
	// stfd f30,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,128(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e7f3c
	if (cr6.eq) goto loc_822E7F3C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x822E7650;
	sub_82187BE0(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e51e8
	ctx.lr = 0x822E765C;
	sub_822E51E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e76cc
	if (cr6.eq) goto loc_822E76CC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r24.u32);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// stw r24,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r24.u32);
	// li r11,1
	r11.s64 = 1;
	// stb r24,134(r1)
	PPC_STORE_U8(ctx.r1.u32 + 134, r24.u8);
	// ori r8,r9,65535
	ctx.r8.u64 = ctx.r9.u64 | 65535;
	// stb r24,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r24.u8);
	// stb r11,135(r1)
	PPC_STORE_U8(ctx.r1.u32 + 135, r11.u8);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r11,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r11.u8);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stb r24,133(r1)
	PPC_STORE_U8(ctx.r1.u32 + 133, r24.u8);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e51e0
	ctx.lr = 0x822E76B0;
	sub_822E51E0(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178f70
	ctx.lr = 0x822E76C4;
	sub_82178F70(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// b 0x822e76ec
	goto loc_822E76EC;
loc_822E76CC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E76E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_822E76EC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822E7700;
	sub_82189CE0(ctx, base);
	// li r11,20
	r11.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822E7710;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,20
	ctx.r3.s64 = 20;
	// std r10,532(r1)
	PPC_STORE_U64(ctx.r1.u32 + 532, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x822E7728;
	sub_8217F768(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// addi r26,r9,-31280
	r26.s64 = ctx.r9.s64 + -31280;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822E7740;
	sub_8217C088(ctx, base);
	// lwz r11,-26876(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// li r27,16
	r27.s64 = 16;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// addi r7,r1,480
	ctx.r7.s64 = ctx.r1.s64 + 480;
	// li r28,32
	r28.s64 = 32;
	// addi r6,r1,496
	ctx.r6.s64 = ctx.r1.s64 + 496;
	// addi r5,r1,512
	ctx.r5.s64 = ctx.r1.s64 + 512;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,48
	r29.s64 = 48;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cec00
	ctx.lr = 0x822E778C;
	sub_821CEC00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,9
	ctx.r9.s64 = 9;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r1,464
	ctx.r6.s64 = ctx.r1.s64 + 464;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E77B0;
	sub_8218A6E0(ctx, base);
	// li r4,27
	ctx.r4.s64 = 27;
	// li r3,27
	ctx.r3.s64 = 27;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822E77C0;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r11,96(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,27
	ctx.r3.s64 = 27;
	// std r11,540(r1)
	PPC_STORE_U64(ctx.r1.u32 + 540, r11.u64);
	// bl 0x8217f768
	ctx.lr = 0x822E77D8;
	sub_8217F768(ctx, base);
	// li r10,24
	ctx.r10.s64 = 24;
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822E77E8;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// ld r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,24
	ctx.r3.s64 = 24;
	// std r9,548(r1)
	PPC_STORE_U64(ctx.r1.u32 + 548, ctx.r9.u64);
	// bl 0x8217f768
	ctx.lr = 0x822E7800;
	sub_8217F768(ctx, base);
	// li r8,25
	ctx.r8.s64 = 25;
	// li r3,25
	ctx.r3.s64 = 25;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822E7810;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// ld r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r6,556(r1)
	PPC_STORE_U64(ctx.r1.u32 + 556, ctx.r6.u64);
	// li r3,25
	ctx.r3.s64 = 25;
	// stw r7,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r7.u32);
	// bl 0x8217f768
	ctx.lr = 0x822E7830;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217f768
	ctx.lr = 0x822E783C;
	sub_8217F768(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82190870
	ctx.lr = 0x822E7844;
	sub_82190870(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// li r3,48
	ctx.r3.s64 = 48;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r26,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lvx128 v61,r26,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r26,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r25,r24
	r25.u64 = r24.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x822e79a4
	if (!cr6.gt) goto loc_822E79A4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r26,r24
	r26.u64 = r24.u64;
	// lfs f31,-5572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5572);
	f31.f64 = double(temp.f32);
loc_822E789C:
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r30,r1,160
	r30.s64 = ctx.r1.s64 + 160;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r23,r1,176
	r23.s64 = ctx.r1.s64 + 176;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r22,r1,192
	r22.s64 = ctx.r1.s64 + 192;
	// addi r21,r1,144
	r21.s64 = ctx.r1.s64 + 144;
	// lwzx r11,r26,r10
	r11.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// addi r20,r1,160
	r20.s64 = ctx.r1.s64 + 160;
	// addi r19,r1,176
	r19.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r18,r1,80
	r18.s64 = ctx.r1.s64 + 80;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r29
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r26,r10
	r11.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// lfs f0,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// lvlx128 v58,r0,r18
	temp.u32 = r18.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// vmulfp128 v55,v62,v57
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32)));
	// vmulfp128 v54,v61,v57
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7940;
	sub_8218A6E0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f12,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f11,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f10,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822E7990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r25,r7
	cr6.compare<int32_t>(r25.s32, ctx.r7.s32, xer);
	// blt cr6,0x822e789c
	if (cr6.lt) goto loc_822E789C;
loc_822E79A4:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x82187be0
	ctx.lr = 0x822E79AC;
	sub_82187BE0(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r26,r24
	r26.u64 = r24.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822e7a80
	if (!cr6.gt) goto loc_822E7A80;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_822E79C0:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwzx r10,r30,r10
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// addi r25,r10,32
	r25.s64 = ctx.r10.s64 + 32;
	// bl 0x8218a6e0
	ctx.lr = 0x822E79F0;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7A14;
	sub_8218A6E0(ctx, base);
	// lwz r6,108(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwzx r10,r30,r6
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r6,r10,112
	ctx.r6.s64 = ctx.r10.s64 + 112;
	// bl 0x8218a6e0
	ctx.lr = 0x822E7A40;
	sub_8218A6E0(ctx, base);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r11,r30,r4
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r4.u32);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E7A6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e79c0
	if (cr6.lt) goto loc_822E79C0;
loc_822E7A80:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82187be0
	ctx.lr = 0x822E7A88;
	sub_82187BE0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r8,88(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r25,64
	r25.s64 = 64;
	// mr r26,r24
	r26.u64 = r24.u64;
	// lfs f29,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f29.f64 = double(temp.f32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lfs f30,-5576(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5576);
	f30.f64 = double(temp.f32);
	// lfs f31,-16776(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -16776);
	f31.f64 = double(temp.f32);
	// ble cr6,0x822e7cd4
	if (!cr6.gt) goto loc_822E7CD4;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_822E7AB8:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r23,r1,224
	r23.s64 = ctx.r1.s64 + 224;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r22,r1,240
	r22.s64 = ctx.r1.s64 + 240;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r21,r1,256
	r21.s64 = ctx.r1.s64 + 256;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwzx r20,r11,r30
	r20.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lvx128 v52,r20,r27
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lvx128 v51,r3,r28
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lvx128 v50,r3,r29
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lvx128 v49,r11,r25
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7B20;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7B44;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7B68;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7B8C;
	sub_8218A6E0(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwzx r10,r10,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// addi r6,r10,144
	ctx.r6.s64 = ctx.r10.s64 + 144;
	// bl 0x8218a6e0
	ctx.lr = 0x822E7BB8;
	sub_8218A6E0(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r10,r30
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwzx r7,r10,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f0,28(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * f31.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * f30.f64));
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// lvlx128 v48,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// addi r23,r1,80
	r23.s64 = ctx.r1.s64 + 80;
	// lwz r22,64(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r21,r1,96
	r21.s64 = ctx.r1.s64 + 96;
	// lvx128 v46,r11,r29
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// stvx128 v46,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r10,r30
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lfs f10,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// vmulfp128 v45,v63,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v47.f32)));
	// lfs f9,68(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f8,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fsubs f5,f10,f9
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f3,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmuls f1,f5,f5
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// lvlx128 v44,r0,r23
	temp.u32 = r23.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v43,v44,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// stvx128 v45,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// vmulfp128 v42,v62,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v43.f32)));
	// fmadds f0,f6,f6,f1
	ctx.fpscr.disableFlushModeUnconditional();
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f1.f64));
	// stvx128 v42,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f12,f2,f2,f0
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + f0.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// fmadds f10,f13,f29,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * f29.f64 + ctx.f11.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v41,r0,r21
	temp.u32 = r21.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v40,v41,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// vmulfp128 v39,v61,v40
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v40.f32)));
	// stvx128 v39,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E7CC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,88(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e7ab8
	if (cr6.lt) goto loc_822E7AB8;
loc_822E7CD4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x822E7CDC;
	sub_82187BE0(ctx, base);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x82187be0
	ctx.lr = 0x822E7CE4;
	sub_82187BE0(ctx, base);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// mr r26,r24
	r26.u64 = r24.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822e7f14
	if (!cr6.gt) goto loc_822E7F14;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_822E7CF8:
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// addi r23,r1,416
	r23.s64 = ctx.r1.s64 + 416;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r22,r1,432
	r22.s64 = ctx.r1.s64 + 432;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r21,r1,448
	r21.s64 = ctx.r1.s64 + 448;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwzx r20,r11,r30
	r20.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,400
	ctx.r6.s64 = ctx.r1.s64 + 400;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lvx128 v38,r20,r27
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lvx128 v37,r3,r28
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lvx128 v36,r3,r29
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lvx128 v35,r11,r25
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7D60;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7D84;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,432
	ctx.r6.s64 = ctx.r1.s64 + 432;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7DA8;
	sub_8218A6E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,448
	ctx.r6.s64 = ctx.r1.s64 + 448;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822E7DCC;
	sub_8218A6E0(ctx, base);
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwzx r10,r10,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// addi r6,r10,144
	ctx.r6.s64 = ctx.r10.s64 + 144;
	// bl 0x8218a6e0
	ctx.lr = 0x822E7DF8;
	sub_8218A6E0(ctx, base);
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r11,r10,r30
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwzx r7,r10,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f0,28(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * f31.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * f30.f64));
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lvlx128 v34,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// vspltw128 v33,v34,0
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// addi r23,r1,96
	r23.s64 = ctx.r1.s64 + 96;
	// lwz r22,64(r31)
	r22.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r21,r1,80
	r21.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r11,r29
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// vmulfp128 v32,v63,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v33.f32)));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lvlx128 v63,r0,r23
	temp.u32 = r23.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v63,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v62,v60
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// lwzx r11,r10,r30
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lfs f10,68(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// lfs f7,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f7.f64));
	// lfs f3,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f3,f1
	f0.f64 = double(float(ctx.f3.f64 - ctx.f1.f64));
	// stvx128 v32,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f2,f4,f4,f6
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f6.f64));
	// fmadds f12,f0,f0,f2
	ctx.f12.f64 = double(float(f0.f64 * f0.f64 + ctx.f2.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// fmadds f10,f13,f29,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * f29.f64 + ctx.f11.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v57,r0,r21
	temp.u32 = r21.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vmulfp128 v55,v61,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E7F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,112(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x822e7cf8
	if (cr6.lt) goto loc_822E7CF8;
loc_822E7F14:
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x822E7F1C;
	sub_82187BE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x822E7F24;
	sub_82190870(ctx, base);
	// stw r24,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r24.u32);
	// stw r24,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r24.u32);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// stw r24,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r24.u32);
	// stw r24,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r24.u32);
	// bl 0x82491668
	ctx.lr = 0x822E7F3C;
	sub_82491668(ctx, base);
loc_822E7F3C:
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// lfd f29,-144(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f30,-136(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_822E7F50"))) PPC_WEAK_FUNC(sub_822E7F50);
PPC_FUNC_IMPL(__imp__sub_822E7F50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r3,208
	r11.s64 = ctx.r3.s64 + 208;
	// addi r9,r10,-31280
	ctx.r9.s64 = ctx.r10.s64 + -31280;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,96
	ctx.r8.s64 = 96;
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r8,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r8.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,48
	ctx.r8.s64 = 48;
	// lvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,48
	ctx.r7.s64 = 48;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1
	ctx.r5.s64 = 1;
	// lvx128 v63,r9,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,304(r3)
	PPC_STORE_U32(ctx.r3.u32 + 304, ctx.r10.u32);
	// stb r5,3392(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3392, ctx.r5.u8);
	// lfs f0,3796(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stfs f0,124(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// stfs f0,128(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// stfs f0,132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// stfs f0,140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,144(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stfs f13,148(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// stfs f13,152(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// stfs f13,160(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stfs f13,164(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// stfs f13,168(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// lfs f13,14192(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,180(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// stfs f13,184(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 184, temp.u32);
	// lfs f13,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-5272(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5272);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,192(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f12,196(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f11,200(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stfs f0,272(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// stfs f0,276(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// stfs f0,280(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// stfs f0,288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// stfs f0,292(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// stfs f0,296(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E805C"))) PPC_WEAK_FUNC(sub_822E805C);
PPC_FUNC_IMPL(__imp__sub_822E805C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E8060"))) PPC_WEAK_FUNC(sub_822E8060);
PPC_FUNC_IMPL(__imp__sub_822E8060) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822E8068;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// bl 0x82180430
	ctx.lr = 0x822E8090;
	sub_82180430(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// lis r28,-32120
	r28.s64 = -2105016320;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r11,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r11.u8);
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-8092(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// bl 0x822e5048
	ctx.lr = 0x822E80C0;
	sub_822E5048(ctx, base);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// lwz r3,-8092(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x822E80CC;
	sub_822E50B8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E80D4"))) PPC_WEAK_FUNC(sub_822E80D4);
PPC_FUNC_IMPL(__imp__sub_822E80D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E80D8"))) PPC_WEAK_FUNC(sub_822E80D8);
PPC_FUNC_IMPL(__imp__sub_822E80D8) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r30,r10,-5076
	r30.s64 = ctx.r10.s64 + -5076;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822E811C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822E8150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,-6696
	ctx.r3.s64 = ctx.r10.s64 + -6696;
	// bl 0x8218a4e8
	ctx.lr = 0x822E8160;
	sub_8218A4E8(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-5612
	ctx.r4.s64 = ctx.r8.s64 + -5612;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E817C;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-5636
	ctx.r4.s64 = ctx.r6.s64 + -5636;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E8198;
	sub_8218A568(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-5096
	ctx.r4.s64 = ctx.r4.s64 + -5096;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E81B4;
	sub_8218A568(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-5108
	ctx.r4.s64 = ctx.r10.s64 + -5108;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E81D0;
	sub_8218A568(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-5128
	ctx.r4.s64 = ctx.r9.s64 + -5128;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E81EC;
	sub_8218A568(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-5140
	ctx.r4.s64 = ctx.r6.s64 + -5140;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E8208;
	sub_8218A568(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-5160
	ctx.r4.s64 = ctx.r4.s64 + -5160;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E8224;
	sub_8218A568(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// addi r4,r11,-5176
	ctx.r4.s64 = r11.s64 + -5176;
	// bl 0x8218a568
	ctx.lr = 0x822E8240;
	sub_8218A568(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-5188
	ctx.r4.s64 = ctx.r8.s64 + -5188;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E825C;
	sub_8218A568(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-10808
	ctx.r4.s64 = ctx.r7.s64 + -10808;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E8278;
	sub_8218A568(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-10820
	ctx.r4.s64 = r11.s64 + -10820;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E8294;
	sub_8218A568(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-10832
	ctx.r4.s64 = ctx.r10.s64 + -10832;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E82B0;
	sub_8218A568(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-10852
	ctx.r4.s64 = ctx.r7.s64 + -10852;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E82CC;
	sub_8218A568(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-10872
	ctx.r4.s64 = ctx.r6.s64 + -10872;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E82E8;
	sub_8218A568(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-5200
	ctx.r4.s64 = ctx.r10.s64 + -5200;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E8304;
	sub_8218A568(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-5216
	ctx.r4.s64 = ctx.r9.s64 + -5216;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822E8320;
	sub_8218B688(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-5224
	ctx.r4.s64 = ctx.r6.s64 + -5224;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822E833C;
	sub_8218B688(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-5240
	ctx.r4.s64 = ctx.r4.s64 + -5240;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822E8358;
	sub_8218B688(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-5268
	ctx.r4.s64 = ctx.r10.s64 + -5268;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822E8374;
	sub_8218B688(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822E8390"))) PPC_WEAK_FUNC(sub_822E8390);
PPC_FUNC_IMPL(__imp__sub_822E8390) {
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
	// li r3,3408
	ctx.r3.s64 = 3408;
	// bl 0x82130528
	ctx.lr = 0x822E83A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e83c8
	if (cr6.eq) goto loc_822E83C8;
	// bl 0x822e7f50
	ctx.lr = 0x822E83B0;
	sub_822E7F50(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,-7896(r11)
	PPC_STORE_U32(r11.u32 + -7896, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E83C8:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7896(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7896, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E83E4"))) PPC_WEAK_FUNC(sub_822E83E4);
PPC_FUNC_IMPL(__imp__sub_822E83E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E83E8"))) PPC_WEAK_FUNC(sub_822E83E8);
PPC_FUNC_IMPL(__imp__sub_822E83E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r9,r11,7
	ctx.r9.s64 = r11.s64 + 7;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v63,r8,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,516(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 516, temp.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lfs f13,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,512(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 512, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E8428"))) PPC_WEAK_FUNC(sub_822E8428);
PPC_FUNC_IMPL(__imp__sub_822E8428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r10,r11,9
	ctx.r10.s64 = r11.s64 + 9;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E8444"))) PPC_WEAK_FUNC(sub_822E8444);
PPC_FUNC_IMPL(__imp__sub_822E8444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E8448"))) PPC_WEAK_FUNC(sub_822E8448);
PPC_FUNC_IMPL(__imp__sub_822E8448) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x822E8450;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd534
	ctx.lr = 0x822E8458;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmpwi cr6,r11,24
	cr6.compare<int32_t>(r11.s32, 24, xer);
	// bge cr6,0x822e876c
	if (!cr6.lt) goto loc_822E876C;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r27,48
	r26.s64 = r27.s64 + 48;
	// addi r22,r11,2384
	r22.s64 = r11.s64 + 2384;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r25,r27,16
	r25.s64 = r27.s64 + 16;
	// addi r21,r11,2352
	r21.s64 = r11.s64 + 2352;
	// addi r24,r27,32
	r24.s64 = r27.s64 + 32;
	// lvx128 v60,r0,r26
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// vand128 v59,v60,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvx128 v58,r0,r25
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// lvx128 v62,r0,r21
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lvx128 v57,r0,r24
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v61,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v55,v58,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// vand128 v54,v57,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v53,v62,v59
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cec00
	ctx.lr = 0x822E84E8;
	sub_821CEC00(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lwz r11,-12348(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12348);
	// lwz r10,-12640(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12640);
	// lbz r5,76(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r4,r5,0,25,25
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822e8538
	if (cr6.eq) goto loc_822E8538;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e8530
	if (!cr6.eq) goto loc_822E8530;
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822e8538
	if (cr6.eq) goto loc_822E8538;
loc_822E8530:
	// li r11,1
	r11.s64 = 1;
	// b 0x822e853c
	goto loc_822E853C;
loc_822E8538:
	// li r11,0
	r11.s64 = 0;
loc_822E853C:
	// lbz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822e855c
	if (cr6.eq) goto loc_822E855C;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822e8560
	if (cr6.eq) goto loc_822E8560;
loc_822E855C:
	// li r11,0
	r11.s64 = 0;
loc_822E8560:
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e8598
	if (cr6.eq) goto loc_822E8598;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,16
	r28.s64 = 16;
	// lvx128 v60,r0,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,32
	r29.s64 = 32;
	// lvx128 v59,r0,r26
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,48
	r30.s64 = 48;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x822e8650
	goto loc_822E8650;
loc_822E8598:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e8630
	if (cr6.eq) goto loc_822E8630;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lbz r10,374(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 374);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e8630
	if (cr6.eq) goto loc_822E8630;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lvx128 v52,r0,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,8
	ctx.r10.s64 = 8;
	// lvx128 v51,r0,r26
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lvx128 v61,r0,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r0,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// li r30,48
	r30.s64 = 48;
	// lvlx128 v50,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r5,272
	ctx.r5.s64 = 272;
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lfs f0,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r28,16
	r28.s64 = 16;
	// lvlx128 v48,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmulfp128 v46,v52,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v49.f32)));
	// lwz r11,-26876(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -26876);
	// lvx128 v45,r31,r5
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,32
	r29.s64 = 32;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lvx128 v44,r11,r30
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v124,v44,v45
	simde_mm_store_ps(v124.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v45.f32)));
	// vmulfp128 v43,v46,v47
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	// vsubfp128 v59,v51,v43
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v43.f32)));
	// b 0x822e8654
	goto loc_822E8654;
loc_822E8630:
	// li r28,16
	r28.s64 = 16;
	// lvx128 v62,r0,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,32
	r29.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// lvx128 v61,r23,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r23,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r23,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E8650:
	// lvx128 v124,r11,r30
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E8654:
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvx128 v126,r11,r28
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// lvx128 v125,r11,r29
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// vand128 v42,v59,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v59,r0,r21
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r10
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lvx128 v35,r0,r9
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// vand128 v41,v62,v63
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// vand128 v40,v61,v63
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r11,r1,256
	r11.s64 = ctx.r1.s64 + 256;
	// vand128 v39,v60,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// vor128 v38,v59,v42
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v42.u8)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v34,r0,r8
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v41,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stvx128 v40,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v37,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215e000
	ctx.lr = 0x822E86EC;
	sub_8215E000(ctx, base);
	// lwz r8,304(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r8,7,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,320
	r11.s64 = r11.s64 + 320;
	// lvx128 v33,r0,r7
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v32,r0,r6
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// addi r3,r11,3
	ctx.r3.s64 = r11.s64 + 3;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r3,7,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stvx128 v33,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,304(r31)
	PPC_STORE_U32(r31.u32 + 304, ctx.r10.u32);
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd7cc
	ctx.lr = 0x822E8768;
	// b 0x823d922c
	return;
loc_822E876C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd7cc
	ctx.lr = 0x822E877C;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_822E8780"))) PPC_WEAK_FUNC(sub_822E8780);
PPC_FUNC_IMPL(__imp__sub_822E8780) {
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
	PPCRegister f0{};
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
	// bl 0x823d91d4
	ctx.lr = 0x822E8788;
	// stwu r1,-1824(r1)
	ea = -1824 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217c658
	ctx.lr = 0x822E87A0;
	sub_8217C658(ctx, base);
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r26,16
	r26.s64 = 16;
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// li r24,32
	r24.s64 = 32;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r25,48
	r25.s64 = 48;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822E87EC;
	sub_8217CE80(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// lwz r11,-12348(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12348);
	// lwz r10,-12640(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12640);
	// lbz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r3,r4,0,25,25
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e883c
	if (cr6.eq) goto loc_822E883C;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e8834
	if (!cr6.eq) goto loc_822E8834;
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822e883c
	if (cr6.eq) goto loc_822E883C;
loc_822E8834:
	// li r11,1
	r11.s64 = 1;
	// b 0x822e8840
	goto loc_822E8840;
loc_822E883C:
	// li r11,0
	r11.s64 = 0;
loc_822E8840:
	// lbz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e8860
	if (cr6.eq) goto loc_822E8860;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822e8864
	if (cr6.eq) goto loc_822E8864;
loc_822E8860:
	// li r11,0
	r11.s64 = 0;
loc_822E8864:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e8890
	if (!cr6.eq) goto loc_822E8890;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// li r11,0
	r11.s64 = 0;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822e8894
	if (!cr6.lt) goto loc_822E8894;
loc_822E8890:
	// li r11,1
	r11.s64 = 1;
loc_822E8894:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r20,-32120
	r20.s64 = -2105016320;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e8924
	if (!cr6.eq) goto loc_822E8924;
	// lwz r11,-8092(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + -8092);
	// lbz r11,374(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e8924
	if (cr6.eq) goto loc_822E8924;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r29,256
	ctx.r10.s64 = r29.s64 + 256;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r29,272
	ctx.r9.s64 = r29.s64 + 272;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// vsubfp128 v58,v63,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32)));
	// lfs f0,-29232(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r29,208
	r11.s64 = r29.s64 + 208;
	// lvlx128 v57,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vmulfp128 v55,v58,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v56.f32)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r4
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r3
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v50,v63,v51
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E8924:
	// clrlwi r19,r8,24
	r19.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x822e893c
	if (!cr6.eq) goto loc_822E893C;
	// addi r4,r29,208
	ctx.r4.s64 = r29.s64 + 208;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217ce80
	ctx.lr = 0x822E893C;
	sub_8217CE80(ctx, base);
loc_822E893C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r23,r11,-31280
	r23.s64 = r11.s64 + -31280;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8217c088
	ctx.lr = 0x822E8950;
	sub_8217C088(ctx, base);
	// lwz r11,304(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822e89d0
	if (!cr6.gt) goto loc_822E89D0;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r31,r1,208
	r31.s64 = ctx.r1.s64 + 208;
	// addi r28,r29,384
	r28.s64 = r29.s64 + 384;
	// li r21,-32
	r21.s64 = -32;
	// li r22,-16
	r22.s64 = -16;
loc_822E8974:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x822e8988
	if (!cr6.eq) goto loc_822E8988;
	// addi r4,r28,-64
	ctx.r4.s64 = r28.s64 + -64;
	// bl 0x8217ce80
	ctx.lr = 0x822E8984;
	sub_8217CE80(ctx, base);
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
loc_822E8988:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8217c088
	ctx.lr = 0x822E8990;
	sub_8217C088(ctx, base);
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// lwz r10,304(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r11,r3,512
	r11.s64 = ctx.r3.s64 + 512;
	// addi r28,r28,128
	r28.s64 = r28.s64 + 128;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r31,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r11,r26
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r31,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r11,r24
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r11,r25
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// blt cr6,0x822e8974
	if (cr6.lt) goto loc_822E8974;
loc_822E89D0:
	// lis r31,-32112
	r31.s64 = -2104492032;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r3,21664(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// bl 0x8260e5c8
	ctx.lr = 0x822E89E0;
	sub_8260E5C8(ctx, base);
	// lwz r3,-8092(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + -8092);
	// lwz r31,21664(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// bl 0x822e55c8
	ctx.lr = 0x822E89EC;
	sub_822E55C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8260e998
	ctx.lr = 0x822E89F8;
	sub_8260E998(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217ce80
	ctx.lr = 0x822E8A04;
	sub_8217CE80(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822E8A10;
	sub_8217C088(ctx, base);
	// lwz r10,-26876(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r11,r29,208
	r11.s64 = r29.s64 + 208;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v44,r10,r26
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r10,r24
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r10,r25
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v42,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,304(r29)
	PPC_STORE_U32(r29.u32 + 304, ctx.r8.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x822e8448
	ctx.lr = 0x822E8A6C;
	sub_822E8448(ctx, base);
	// addi r1,r1,1824
	ctx.r1.s64 = ctx.r1.s64 + 1824;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822E8A74"))) PPC_WEAK_FUNC(sub_822E8A74);
PPC_FUNC_IMPL(__imp__sub_822E8A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E8A78"))) PPC_WEAK_FUNC(sub_822E8A78);
PPC_FUNC_IMPL(__imp__sub_822E8A78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r9,-7884(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -7884);
	// lwz r10,-17936(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17936);
	// lfs f12,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// bne cr6,0x822e8aa8
	if (!cr6.eq) goto loc_822E8AA8;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// b 0x822e8aac
	goto loc_822E8AAC;
loc_822E8AA8:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822E8AAC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r11,6928
	r11.s64 = r11.s64 + 6928;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// stfsx f13,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
	// stfs f13,32(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// bne cr6,0x822e8ad0
	if (!cr6.eq) goto loc_822E8AD0;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// b 0x822e8ad4
	goto loc_822E8AD4;
loc_822E8AD0:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822E8AD4:
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// stfsx f13,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
	// stfs f13,36(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// bne cr6,0x822e8af0
	if (!cr6.eq) goto loc_822E8AF0;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// b 0x822e8af4
	goto loc_822E8AF4;
loc_822E8AF0:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822E8AF4:
	// addi r8,r11,8
	ctx.r8.s64 = r11.s64 + 8;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// stfsx f13,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
	// stfs f13,40(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// bne cr6,0x822e8b0c
	if (!cr6.eq) goto loc_822E8B0C;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_822E8B0C:
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// stfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// stfs f0,44(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E8B1C"))) PPC_WEAK_FUNC(sub_822E8B1C);
PPC_FUNC_IMPL(__imp__sub_822E8B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E8B20"))) PPC_WEAK_FUNC(sub_822E8B20);
PPC_FUNC_IMPL(__imp__sub_822E8B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r10,r11,6928
	ctx.r10.s64 = r11.s64 + 6928;
	// lfs f0,32(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f0,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f0,40(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f0,44(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E8B4C"))) PPC_WEAK_FUNC(sub_822E8B4C);
PPC_FUNC_IMPL(__imp__sub_822E8B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E8B50"))) PPC_WEAK_FUNC(sub_822E8B50);
PPC_FUNC_IMPL(__imp__sub_822E8B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r11,r9,6928
	r11.s64 = ctx.r9.s64 + 6928;
	// lwz r10,-17936(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17936);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// rlwinm r6,r10,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r11,12
	ctx.r5.s64 = r11.s64 + 12;
	// stfsx f0,r6,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, temp.u32);
	// stfs f0,32(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// lfs f0,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfsx f0,r6,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, temp.u32);
	// stfs f0,36(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// lfs f0,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfsx f0,r6,r7
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, temp.u32);
	// stfs f0,40(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// lfs f0,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfsx f0,r6,r5
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r5.u32, temp.u32);
	// stfs f0,44(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E8BA4"))) PPC_WEAK_FUNC(sub_822E8BA4);
PPC_FUNC_IMPL(__imp__sub_822E8BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E8BA8"))) PPC_WEAK_FUNC(sub_822E8BA8);
PPC_FUNC_IMPL(__imp__sub_822E8BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r17{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lbz r10,-6728(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6728);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e8bcc
	if (cr6.eq) goto loc_822E8BCC;
	// li r11,2
	r11.s64 = 2;
	// stw r11,-7884(r4)
	PPC_STORE_U32(ctx.r4.u32 + -7884, r11.u32);
loc_822E8BCC:
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r7,r11,-7878
	ctx.r7.s64 = r11.s64 + -7878;
	// addi r5,r10,29952
	ctx.r5.s64 = ctx.r10.s64 + 29952;
	// lwz r6,-8092(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8092);
	// lbz r8,-1(r7)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + -1);
	// lbz r3,393(r6)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r6.u32 + 393);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822e8c78
	if (!cr6.eq) goto loc_822E8C78;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e8c78
	if (!cr6.eq) goto loc_822E8C78;
	// lbz r11,0(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e8c78
	if (!cr6.eq) goto loc_822E8C78;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-7572
	ctx.r9.s64 = r11.s64 + -7572;
	// addi r10,r10,-7888
	ctx.r10.s64 = ctx.r10.s64 + -7888;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f12,6988(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 6988);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14496(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14496);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// ble cr6,0x822e8c5c
	if (!cr6.gt) goto loc_822E8C5C;
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f13,14496(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14496);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822e8c94
	if (!cr6.lt) goto loc_822E8C94;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x822e8c90
	goto loc_822E8C90;
loc_822E8C5C:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f13,14496(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14496);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822e8c94
	if (!cr6.gt) goto loc_822E8C94;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x822e8c90
	goto loc_822E8C90;
loc_822E8C78:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-7572
	ctx.r9.s64 = r11.s64 + -7572;
	// addi r10,r10,-7888
	ctx.r10.s64 = ctx.r10.s64 + -7888;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lfs f0,14496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14496);
	f0.f64 = double(temp.f32);
loc_822E8C90:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_822E8C94:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lfs f13,14500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14500);
	ctx.f13.f64 = double(temp.f32);
	// lbz r8,393(r6)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r6.u32 + 393);
	// stfs f0,14576(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 14576, temp.u32);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stb r10,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, ctx.r10.u8);
	// stb r8,-1(r7)
	PPC_STORE_U8(ctx.r7.u32 + -1, ctx.r8.u8);
	// stfs f13,14580(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 14580, temp.u32);
	// lbz r11,393(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 393);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e8ccc
	if (cr6.eq) goto loc_822E8CCC;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7884(r4)
	PPC_STORE_U32(ctx.r4.u32 + -7884, r11.u32);
	// b 0x822e8cd0
	goto loc_822E8CD0;
loc_822E8CCC:
	// lwz r11,-7884(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -7884);
loc_822E8CD0:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r9,6928
	ctx.r8.s64 = ctx.r9.s64 + 6928;
	// lbz r10,14545(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 14545);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e8fb4
	if (cr6.eq) goto loc_822E8FB4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r7,-12640(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lbz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e8d0c
	if (cr6.eq) goto loc_822E8D0C;
	// lbz r10,10(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822e8d10
	if (cr6.eq) goto loc_822E8D10;
loc_822E8D0C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E8D10:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f6,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lfs f4,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f4.f64 = double(temp.f32);
	// bne cr6,0x822e8e4c
	if (!cr6.eq) goto loc_822E8E4C;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lfs f0,-7892(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7892);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f6
	f0.f64 = double(float(f0.f64 - ctx.f6.f64));
	// stfs f0,-7892(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -7892, temp.u32);
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// bgt cr6,0x822e8e4c
	if (cr6.gt) goto loc_822E8E4C;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lbz r5,-7880(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + -7880);
	// lfs f0,-1540(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -1540);
	f0.f64 = double(temp.f32);
	// stfs f0,-7892(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -7892, temp.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822e8e4c
	if (cr6.eq) goto loc_822E8E4C;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// addi r3,r6,2192
	ctx.r3.s64 = ctx.r6.s64 + 2192;
	// ori r5,r5,64167
	ctx.r5.u64 = ctx.r5.u64 | 64167;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lwz r30,2192(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2192);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mulld r9,r30,r5
	ctx.r9.s64 = r30.s64 * ctx.r5.s64;
	// lfs f0,14348(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r5,r10,9
	ctx.r5.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f13,-32(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stw r9,2192(r6)
	PPC_STORE_U32(ctx.r6.u32 + 2192, ctx.r9.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bgt cr6,0x822e8e4c
	if (cr6.gt) goto loc_822E8E4C;
	// lis r12,-32209
	r12.s64 = -2110849024;
	// addi r12,r12,-29236
	r12.s64 = r12.s64 + -29236;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822E8DDC;
	case 1:
		goto loc_822E8DF4;
	case 2:
		goto loc_822E8E44;
	case 3:
		goto loc_822E8E24;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-29220(r14)
	r17.u64 = PPC_LOAD_U32(r14.u32 + -29220);
	// lwz r17,-29196(r14)
	r17.u64 = PPC_LOAD_U32(r14.u32 + -29196);
	// lwz r17,-29116(r14)
	r17.u64 = PPC_LOAD_U32(r14.u32 + -29116);
	// lwz r17,-29148(r14)
	r17.u64 = PPC_LOAD_U32(r14.u32 + -29148);
loc_822E8DDC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-3164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822e8e1c
	if (!cr6.lt) goto loc_822E8E1C;
	// li r11,0
	r11.s64 = 0;
	// b 0x822e8e48
	goto loc_822E8E48;
loc_822E8DF4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822e8e0c
	if (!cr6.lt) goto loc_822E8E0C;
	// li r11,0
	r11.s64 = 0;
	// b 0x822e8e48
	goto loc_822E8E48;
loc_822E8E0C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822e8e44
	if (!cr6.lt) goto loc_822E8E44;
loc_822E8E1C:
	// li r11,1
	r11.s64 = 1;
	// b 0x822e8e48
	goto loc_822E8E48;
loc_822E8E24:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,-4724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4724);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822e8e3c
	if (!cr6.lt) goto loc_822E8E3C;
	// li r11,1
	r11.s64 = 1;
	// b 0x822e8e48
	goto loc_822E8E48;
loc_822E8E3C:
	// li r11,2
	r11.s64 = 2;
	// b 0x822e8e48
	goto loc_822E8E48;
loc_822E8E44:
	// li r11,3
	r11.s64 = 3;
loc_822E8E48:
	// stw r11,-7884(r4)
	PPC_STORE_U32(ctx.r4.u32 + -7884, r11.u32);
loc_822E8E4C:
	// lbz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e8e68
	if (cr6.eq) goto loc_822E8E68;
	// lbz r10,10(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822e8e6c
	if (cr6.eq) goto loc_822E8E6C;
loc_822E8E68:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E8E6C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e8eb0
	if (cr6.eq) goto loc_822E8EB0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r10,-12348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r10,76(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 76);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822e8ea0
	if (!cr6.eq) goto loc_822E8EA0;
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822e8ea4
	if (cr6.eq) goto loc_822E8EA4;
loc_822E8EA0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E8EA4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e9028
	if (cr6.eq) goto loc_822E9028;
loc_822E8EB0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f5,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f5.f64 = double(temp.f32);
	// bne cr6,0x822e8ec8
	if (!cr6.eq) goto loc_822E8EC8;
	// fmr f12,f5
	ctx.f12.f64 = ctx.f5.f64;
	// b 0x822e8ecc
	goto loc_822E8ECC;
loc_822E8EC8:
	// fmr f12,f4
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f4.f64;
loc_822E8ECC:
	// lfs f0,32(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f9,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,-4728(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4728);
	ctx.f10.f64 = double(temp.f32);
	// fabs f11,f13
	ctx.f11.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f9
	cr6.compare(ctx.f11.f64, ctx.f9.f64);
	// bge cr6,0x822e8ef8
	if (!cr6.lt) goto loc_822E8EF8;
	// fmr f7,f12
	ctx.f7.f64 = ctx.f12.f64;
	// b 0x822e8f00
	goto loc_822E8F00;
loc_822E8EF8:
	// fmuls f13,f6,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmadds f7,f13,f10,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + f0.f64));
loc_822E8F00:
	// stfs f7,32(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 32, temp.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822e8f14
	if (!cr6.eq) goto loc_822E8F14;
	// fmr f12,f5
	ctx.f12.f64 = ctx.f5.f64;
	// b 0x822e8f18
	goto loc_822E8F18;
loc_822E8F14:
	// fmr f12,f4
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f4.f64;
loc_822E8F18:
	// lfs f0,36(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	f0.f64 = double(temp.f32);
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fabs f11,f13
	ctx.f11.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f9
	cr6.compare(ctx.f11.f64, ctx.f9.f64);
	// bge cr6,0x822e8f34
	if (!cr6.lt) goto loc_822E8F34;
	// fmr f8,f12
	ctx.f8.f64 = ctx.f12.f64;
	// b 0x822e8f3c
	goto loc_822E8F3C;
loc_822E8F34:
	// fmuls f13,f6,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmadds f8,f13,f10,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + f0.f64));
loc_822E8F3C:
	// stfs f8,36(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + 36, temp.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822e8f50
	if (!cr6.eq) goto loc_822E8F50;
	// fmr f12,f5
	ctx.f12.f64 = ctx.f5.f64;
	// b 0x822e8f54
	goto loc_822E8F54;
loc_822E8F50:
	// fmr f12,f4
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f4.f64;
loc_822E8F54:
	// lfs f0,40(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	f0.f64 = double(temp.f32);
	// fsubs f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fabs f11,f13
	ctx.f11.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f9
	cr6.compare(ctx.f11.f64, ctx.f9.f64);
	// bge cr6,0x822e8f70
	if (!cr6.lt) goto loc_822E8F70;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// b 0x822e8f78
	goto loc_822E8F78;
loc_822E8F70:
	// fmuls f13,f6,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmadds f11,f13,f10,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + f0.f64));
loc_822E8F78:
	// stfs f11,40(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 40, temp.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822e8f8c
	if (!cr6.eq) goto loc_822E8F8C;
	// fmr f0,f5
	f0.f64 = ctx.f5.f64;
	// b 0x822e8f90
	goto loc_822E8F90;
loc_822E8F8C:
	// fmr f0,f4
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f4.f64;
loc_822E8F90:
	// lfs f13,44(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fabs f5,f12
	ctx.f5.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f5,f9
	cr6.compare(ctx.f5.f64, ctx.f9.f64);
	// blt cr6,0x822e8fac
	if (cr6.lt) goto loc_822E8FAC;
	// fmuls f0,f6,f12
	f0.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// fmadds f0,f0,f10,f13
	f0.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f13.f64));
loc_822E8FAC:
	// stfs f0,44(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 44, temp.u32);
	// b 0x822e9038
	goto loc_822E9038;
loc_822E8FB4:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f12,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// bne cr6,0x822e8fd4
	if (!cr6.eq) goto loc_822E8FD4;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// b 0x822e8fd8
	goto loc_822E8FD8;
loc_822E8FD4:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822E8FD8:
	// fmr f7,f13
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = ctx.f13.f64;
	// stfs f7,32(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 32, temp.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822e8ff0
	if (!cr6.eq) goto loc_822E8FF0;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// b 0x822e8ff4
	goto loc_822E8FF4;
loc_822E8FF0:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822E8FF4:
	// fmr f8,f13
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = ctx.f13.f64;
	// stfs f8,36(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + 36, temp.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822e900c
	if (!cr6.eq) goto loc_822E900C;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// b 0x822e9010
	goto loc_822E9010;
loc_822E900C:
	// fmr f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = f0.f64;
loc_822E9010:
	// stfs f11,40(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 40, temp.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822e9020
	if (!cr6.eq) goto loc_822E9020;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_822E9020:
	// stfs f0,44(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 44, temp.u32);
	// b 0x822e9038
	goto loc_822E9038;
loc_822E9028:
	// lfs f0,44(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	f0.f64 = double(temp.f32);
	// lfs f11,40(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lfs f8,36(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,32(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
loc_822E9038:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// fadds f13,f8,f7
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f8.f64 + ctx.f7.f64));
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r7,r8,8
	ctx.r7.s64 = ctx.r8.s64 + 8;
	// addi r6,r9,6976
	ctx.r6.s64 = ctx.r9.s64 + 6976;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r5,r8,12
	ctx.r5.s64 = ctx.r8.s64 + 12;
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f12,f13,f11
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// stfsx f7,r4,r8
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r8.u32, temp.u32);
	// lfs f13,36(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f13,r4,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r10.u32, temp.u32);
	// lfs f13,40(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfsx f13,r4,r7
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r7.u32, temp.u32);
	// lfs f13,44(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,8(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// stfsx f0,r3,r6
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r6.u32, temp.u32);
	// stfsx f13,r4,r5
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, temp.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9098"))) PPC_WEAK_FUNC(sub_822E9098);
PPC_FUNC_IMPL(__imp__sub_822E9098) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stw r11,-7884(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7884, r11.u32);
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822e8a78
	sub_822E8A78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822E90C8"))) PPC_WEAK_FUNC(sub_822E90C8);
PPC_FUNC_IMPL(__imp__sub_822E90C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E90CC"))) PPC_WEAK_FUNC(sub_822E90CC);
PPC_FUNC_IMPL(__imp__sub_822E90CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E90D0"))) PPC_WEAK_FUNC(sub_822E90D0);
PPC_FUNC_IMPL(__imp__sub_822E90D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-7884(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7884);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E90E4"))) PPC_WEAK_FUNC(sub_822E90E4);
PPC_FUNC_IMPL(__imp__sub_822E90E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E90E8"))) PPC_WEAK_FUNC(sub_822E90E8);
PPC_FUNC_IMPL(__imp__sub_822E90E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r7,-7880(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + -7880);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,-7880(r10)
	PPC_STORE_U8(ctx.r10.u32 + -7880, ctx.r5.u8);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r7,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9114"))) PPC_WEAK_FUNC(sub_822E9114);
PPC_FUNC_IMPL(__imp__sub_822E9114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9118"))) PPC_WEAK_FUNC(sub_822E9118);
PPC_FUNC_IMPL(__imp__sub_822E9118) {
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
	// lis r11,-32209
	r11.s64 = -2110849024;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28520
	ctx.r4.s64 = r11.s64 + -28520;
	// addi r3,r10,-4656
	ctx.r3.s64 = ctx.r10.s64 + -4656;
	// bl 0x82554798
	ctx.lr = 0x822E9138;
	sub_82554798(ctx, base);
	// lis r9,-32209
	ctx.r9.s64 = -2110849024;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28464
	ctx.r4.s64 = ctx.r9.s64 + -28464;
	// addi r3,r8,-4684
	ctx.r3.s64 = ctx.r8.s64 + -4684;
	// bl 0x82554798
	ctx.lr = 0x822E914C;
	sub_82554798(ctx, base);
	// lis r7,-32209
	ctx.r7.s64 = -2110849024;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28440
	ctx.r4.s64 = ctx.r7.s64 + -28440;
	// addi r3,r6,-4720
	ctx.r3.s64 = ctx.r6.s64 + -4720;
	// bl 0x82554798
	ctx.lr = 0x822E9160;
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

__attribute__((alias("__imp__sub_822E9170"))) PPC_WEAK_FUNC(sub_822E9170);
PPC_FUNC_IMPL(__imp__sub_822E9170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,2304
	ctx.r5.s64 = r11.s64 + 2304;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822E9198;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r11,-4916(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -4916);
	// addi r4,r11,28
	ctx.r4.s64 = r11.s64 + 28;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stw r3,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r3.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r8,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// lwz r3,0(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r9,8(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r4,12(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r4,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r4.u32);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r3,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E920C"))) PPC_WEAK_FUNC(sub_822E920C);
PPC_FUNC_IMPL(__imp__sub_822E920C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9210"))) PPC_WEAK_FUNC(sub_822E9210);
PPC_FUNC_IMPL(__imp__sub_822E9210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-7856
	ctx.r8.s64 = r11.s64 + -7856;
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
loc_822E9220:
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9248
	if (cr6.eq) goto loc_822E9248;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e9248
	if (cr6.eq) goto loc_822E9248;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e9248
	if (!cr6.eq) goto loc_822E9248;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E9248:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9270
	if (cr6.eq) goto loc_822E9270;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e9270
	if (cr6.eq) goto loc_822E9270;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e9270
	if (!cr6.eq) goto loc_822E9270;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E9270:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9298
	if (cr6.eq) goto loc_822E9298;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e9298
	if (cr6.eq) goto loc_822E9298;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e9298
	if (!cr6.eq) goto loc_822E9298;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E9298:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e92c0
	if (cr6.eq) goto loc_822E92C0;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e92c0
	if (cr6.eq) goto loc_822E92C0;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e92c0
	if (!cr6.eq) goto loc_822E92C0;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E92C0:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r8,36
	r11.s64 = ctx.r8.s64 + 36;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x822e9220
	if (cr6.lt) goto loc_822E9220;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E92D4"))) PPC_WEAK_FUNC(sub_822E92D4);
PPC_FUNC_IMPL(__imp__sub_822E92D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E92D8"))) PPC_WEAK_FUNC(sub_822E92D8);
PPC_FUNC_IMPL(__imp__sub_822E92D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,-7856
	ctx.r10.s64 = r11.s64 + -7856;
	// lwz r11,-7856(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7856);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e92f4
	if (cr6.eq) goto loc_822E92F4;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E92F4:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9304
	if (cr6.eq) goto loc_822E9304;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9304:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9314
	if (cr6.eq) goto loc_822E9314;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9314:
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9324
	if (cr6.eq) goto loc_822E9324;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9324:
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9334
	if (cr6.eq) goto loc_822E9334;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9334:
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9344
	if (cr6.eq) goto loc_822E9344;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9344:
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9354
	if (cr6.eq) goto loc_822E9354;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9354:
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9368"))) PPC_WEAK_FUNC(sub_822E9368);
PPC_FUNC_IMPL(__imp__sub_822E9368) {
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
	// bl 0x822e92d8
	ctx.lr = 0x822E9378;
	sub_822E92D8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7820(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7820);
	// bl 0x82741860
	ctx.lr = 0x822E9384;
	sub_82741860(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9394"))) PPC_WEAK_FUNC(sub_822E9394);
PPC_FUNC_IMPL(__imp__sub_822E9394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9398"))) PPC_WEAK_FUNC(sub_822E9398);
PPC_FUNC_IMPL(__imp__sub_822E9398) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-7860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7860);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e94b4
	if (!cr6.eq) goto loc_822E94B4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-7816
	ctx.r10.s64 = r11.s64 + -7816;
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
	// beq cr6,0x822e93e8
	if (cr6.eq) goto loc_822E93E8;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4208
	ctx.r4.s64 = ctx.r10.s64 + -4208;
	// b 0x822e93f0
	goto loc_822E93F0;
loc_822E93E8:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4256
	ctx.r4.s64 = ctx.r10.s64 + -4256;
loc_822E93F0:
	// bl 0x821ca540
	ctx.lr = 0x822E93F4;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x822E93FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e940c
	if (cr6.eq) goto loc_822E940C;
	// bl 0x82611298
	ctx.lr = 0x822E9408;
	sub_82611298(ctx, base);
	// b 0x822e9410
	goto loc_822E9410;
loc_822E940C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822E9410:
	// stw r3,-7860(r31)
	PPC_STORE_U32(r31.u32 + -7860, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-5792
	ctx.r4.s64 = ctx.r10.s64 + -5792;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E9434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822E943C;
	sub_821C9A90(ctx, base);
	// lwz r11,-7860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7860);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r8,-4272
	ctx.r4.s64 = ctx.r8.s64 + -4272;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82192680
	ctx.lr = 0x822E9450;
	sub_82192680(ctx, base);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-4288
	ctx.r4.s64 = ctx.r7.s64 + -4288;
	// stw r3,-7864(r31)
	PPC_STORE_U32(r31.u32 + -7864, ctx.r3.u32);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E946C;
	sub_8218A568(ctx, base);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r3,-7876(r6)
	PPC_STORE_U32(ctx.r6.u32 + -7876, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,-7864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7864);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-4308
	ctx.r4.s64 = ctx.r4.s64 + -4308;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E948C;
	sub_8218A568(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stw r3,-7872(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7872, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r11,-7864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7864);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-4324
	ctx.r4.s64 = ctx.r9.s64 + -4324;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E94AC;
	sub_8218A568(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// stw r3,-7868(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7868, ctx.r3.u32);
loc_822E94B4:
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

__attribute__((alias("__imp__sub_822E94CC"))) PPC_WEAK_FUNC(sub_822E94CC);
PPC_FUNC_IMPL(__imp__sub_822E94CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E94D0"))) PPC_WEAK_FUNC(sub_822E94D0);
PPC_FUNC_IMPL(__imp__sub_822E94D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
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
	// bl 0x823d91fc
	ctx.lr = 0x822E94D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r29,r5,48
	r29.s64 = ctx.r5.s64 + 48;
	// li r8,48
	ctx.r8.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r5,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r5,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,64(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e9648
	if (cr6.eq) goto loc_822E9648;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e9648
	if (cr6.eq) goto loc_822E9648;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// beq cr6,0x822e958c
	if (cr6.eq) goto loc_822E958C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4096
	ctx.r4.s64 = ctx.r10.s64 + -4096;
	// bl 0x824804d0
	ctx.lr = 0x822E9558;
	sub_824804D0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-4100(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4100);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,-4104(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4108(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-30580(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30580);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// b 0x822e95c8
	goto loc_822E95C8;
loc_822E958C:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4120
	ctx.r4.s64 = ctx.r10.s64 + -4120;
	// bl 0x824804d0
	ctx.lr = 0x822E9598;
	sub_824804D0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,-4124(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4124);
	f0.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,-4128(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4132(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4132);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-4136(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4136);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-4140(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4140);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-4144(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4144);
	ctx.f8.f64 = double(temp.f32);
loc_822E95C8:
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r9,7040
	ctx.r5.s64 = ctx.r9.s64 + 7040;
	// lfs f11,12428(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12428);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r8,7056
	ctx.r4.s64 = ctx.r8.s64 + 7056;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stfs f10,7056(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + 7056, temp.u32);
	// stfs f0,7040(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 7040, temp.u32);
	// lfs f7,-4148(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4148);
	ctx.f7.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stfs f11,12(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// stfs f7,12(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f8,8(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// stfs f9,4(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f12,8(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// beq cr6,0x822e9648
	if (cr6.eq) goto loc_822E9648;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,272
	ctx.r10.s64 = 272;
	// li r9,416
	ctx.r9.s64 = 416;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r5,128(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// lvx128 v59,r5,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247a020
	ctx.lr = 0x822E9640;
	sub_8247A020(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a838
	ctx.lr = 0x822E9648;
	sub_8247A838(ctx, base);
loc_822E9648:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E9650"))) PPC_WEAK_FUNC(sub_822E9650);
PPC_FUNC_IMPL(__imp__sub_822E9650) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,88(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,7016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7016);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822e9750
	if (cr6.gt) goto loc_822E9750;
	// fdivs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,7056
	r11.s64 = r11.s64 + 7056;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f12,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fneg f9,f12
	ctx.f9.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fsel f8,f10,f10,f0
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsel f7,f10,f10,f0
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsubs f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f5,f6,f13,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f7.f64;
	// fmadds f1,f5,f9,f12
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f9.f64 + ctx.f12.f64));
	// beq cr6,0x822e9750
	if (cr6.eq) goto loc_822E9750;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822e9750
	if (cr6.eq) goto loc_822E9750;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e96ec
	if (cr6.eq) goto loc_822E96EC;
	// addi r10,r10,272
	ctx.r10.s64 = ctx.r10.s64 + 272;
	// b 0x822e96f4
	goto loc_822E96F4;
loc_822E96EC:
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_822E96F4:
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r8,48
	ctx.r8.s64 = 48;
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r9,7072
	ctx.r7.s64 = ctx.r9.s64 + 7072;
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stfs f12,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-7436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7436);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f79c0
	ctx.lr = 0x822E9750;
	sub_822F79C0(ctx, base);
loc_822E9750:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9760"))) PPC_WEAK_FUNC(sub_822E9760);
PPC_FUNC_IMPL(__imp__sub_822E9760) {
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
	// bl 0x823d91ec
	ctx.lr = 0x822E9768;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// addi r30,r11,-7856
	r30.s64 = r11.s64 + -7856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_822E979C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e97b4
	if (cr6.eq) goto loc_822E97B4;
	// lbz r10,92(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e97dc
	if (cr6.eq) goto loc_822E97DC;
loc_822E97B4:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r30,32
	ctx.r10.s64 = r30.s64 + 32;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822e979c
	if (cr6.lt) goto loc_822E979C;
loc_822E97C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822E97DC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-7820(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7820);
	// bl 0x827419e0
	ctx.lr = 0x822E97F0;
	sub_827419E0(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822e980c
	if (cr6.eq) goto loc_822E980C;
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e980c
	if (cr6.eq) goto loc_822E980C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x822e9810
	goto loc_822E9810;
loc_822E980C:
	// li r11,0
	r11.s64 = 0;
loc_822E9810:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// rlwinm r31,r28,2,0,29
	r31.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,-16385
	ctx.r7.s64 = -16385;
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r8,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r8.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r7,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r7.u32);
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwzx r8,r31,r30
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r11,48
	r11.s64 = 48;
	// stw r3,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r25,80(r7)
	PPC_STORE_U32(ctx.r7.u32 + 80, r25.u32);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stb r6,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, ctx.r6.u8);
	// lwzx r8,r31,r30
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stfs f0,88(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 88, temp.u32);
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r29,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r29,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r29,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r6,r31,r30
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stfs f31,76(r6)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 76, temp.u32);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stfs f30,72(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stw r27,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r27.u32);
	// lwzx r10,r31,r30
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lwz r3,96(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// bl 0x822e94d0
	ctx.lr = 0x822E98B8;
	sub_822E94D0(ctx, base);
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// bge cr6,0x822e97c8
	if (!cr6.lt) goto loc_822E97C8;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822E98D4"))) PPC_WEAK_FUNC(sub_822E98D4);
PPC_FUNC_IMPL(__imp__sub_822E98D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E98D8"))) PPC_WEAK_FUNC(sub_822E98D8);
PPC_FUNC_IMPL(__imp__sub_822E98D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e99d8
	if (cr6.eq) goto loc_822E99D8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f10,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmadds f8,f11,f0,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f8,88(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// fcmpu cr6,f8,f9
	cr6.compare(ctx.f8.f64, ctx.f9.f64);
	// ble cr6,0x822e993c
	if (!cr6.gt) goto loc_822E993C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E993C:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e99c0
	if (cr6.eq) goto loc_822E99C0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e99c0
	if (cr6.eq) goto loc_822E99C0;
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e99c0
	if (cr6.eq) goto loc_822E99C0;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lfs f0,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E99C0:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822e99d8
	if (cr6.eq) goto loc_822E99D8;
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// bl 0x822e9650
	ctx.lr = 0x822E99D8;
	sub_822E9650(ctx, base);
loc_822E99D8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E99E8"))) PPC_WEAK_FUNC(sub_822E99E8);
PPC_FUNC_IMPL(__imp__sub_822E99E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r31,32(r11)
	PPC_STORE_U32(r11.u32 + 32, r31.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822e9398
	ctx.lr = 0x822E9A0C;
	sub_822E9398(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// li r10,0
	ctx.r10.s64 = 0;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// stfs f13,84(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,12424(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12424);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12428(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822E9A98"))) PPC_WEAK_FUNC(sub_822E9A98);
PPC_FUNC_IMPL(__imp__sub_822E9A98) {
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
	ctx.lr = 0x822E9AA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r11,-7856
	r29.s64 = r11.s64 + -7856;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822E9AB4:
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x822E9ABC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e9ae4
	if (cr6.eq) goto loc_822E9AE4;
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x822E9AD0;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r28,92(r31)
	PPC_STORE_U8(r31.u32 + 92, r28.u8);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// b 0x822e9ae8
	goto loc_822E9AE8;
loc_822E9AE4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822E9AE8:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// bl 0x822e99e8
	ctx.lr = 0x822E9AF0;
	sub_822E99E8(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r29,32
	r11.s64 = r29.s64 + 32;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822e9ab4
	if (cr6.lt) goto loc_822E9AB4;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x822E9B08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9b18
	if (cr6.eq) goto loc_822E9B18;
	// bl 0x82741848
	ctx.lr = 0x822E9B14;
	sub_82741848(ctx, base);
	// b 0x822e9b1c
	goto loc_822E9B1C;
loc_822E9B18:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822E9B1C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r11,r11,-7820
	r11.s64 = r11.s64 + -7820;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x82741b18
	ctx.lr = 0x822E9B30;
	sub_82741B18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E9B38"))) PPC_WEAK_FUNC(sub_822E9B38);
PPC_FUNC_IMPL(__imp__sub_822E9B38) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7820(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7820);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9b60
	if (cr6.eq) goto loc_822E9B60;
	// bl 0x82741920
	ctx.lr = 0x822E9B60;
	sub_82741920(ctx, base);
loc_822E9B60:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r11,-7856
	r30.s64 = r11.s64 + -7856;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822E9B6C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9b88
	if (cr6.eq) goto loc_822E9B88;
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9b88
	if (cr6.eq) goto loc_822E9B88;
	// bl 0x822e98d8
	ctx.lr = 0x822E9B88;
	sub_822E98D8(ctx, base);
loc_822E9B88:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822e9b6c
	if (cr6.lt) goto loc_822E9B6C;
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

__attribute__((alias("__imp__sub_822E9BB0"))) PPC_WEAK_FUNC(sub_822E9BB0);
PPC_FUNC_IMPL(__imp__sub_822E9BB0) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7796(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9be4
	if (cr6.eq) goto loc_822E9BE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E9BE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E9BE4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7796(r31)
	PPC_STORE_U32(r31.u32 + -7796, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822E9C00"))) PPC_WEAK_FUNC(sub_822E9C00);
PPC_FUNC_IMPL(__imp__sub_822E9C00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
loc_822E9C08:
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e9c28
	if (cr6.eq) goto loc_822E9C28;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,28
	cr6.compare<int32_t>(r11.s32, 28, xer);
	// blt cr6,0x822e9c08
	if (cr6.lt) goto loc_822E9C08;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822E9C28:
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,20(r9)
	PPC_STORE_U8(ctx.r9.u32 + 20, ctx.r7.u8);
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9C44"))) PPC_WEAK_FUNC(sub_822E9C44);
PPC_FUNC_IMPL(__imp__sub_822E9C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9C48"))) PPC_WEAK_FUNC(sub_822E9C48);
PPC_FUNC_IMPL(__imp__sub_822E9C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_822E9C5C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822e9ca0
	if (cr6.eq) goto loc_822E9CA0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,28
	cr6.compare<int32_t>(ctx.r10.s32, 28, xer);
	// blt cr6,0x822e9c5c
	if (cr6.lt) goto loc_822E9C5C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r11,r3,164
	r11.s64 = ctx.r3.s64 + 164;
loc_822E9C80:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822e9cac
	if (cr6.eq) goto loc_822E9CAC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x822e9c80
	if (cr6.lt) goto loc_822E9C80;
	// blr 
	return;
loc_822E9CA0:
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stb r9,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r9.u8);
	// blr 
	return;
loc_822E9CAC:
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stb r9,160(r11)
	PPC_STORE_U8(r11.u32 + 160, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9CB8"))) PPC_WEAK_FUNC(sub_822E9CB8);
PPC_FUNC_IMPL(__imp__sub_822E9CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,160
	ctx.r10.s64 = ctx.r3.s64 + 160;
loc_822E9CC0:
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e9ce0
	if (cr6.eq) goto loc_822E9CE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x822e9cc0
	if (cr6.lt) goto loc_822E9CC0;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822E9CE0:
	// addi r10,r11,41
	ctx.r10.s64 = r11.s64 + 41;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,160(r9)
	PPC_STORE_U8(ctx.r9.u32 + 160, ctx.r7.u8);
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9CFC"))) PPC_WEAK_FUNC(sub_822E9CFC);
PPC_FUNC_IMPL(__imp__sub_822E9CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9D00"))) PPC_WEAK_FUNC(sub_822E9D00);
PPC_FUNC_IMPL(__imp__sub_822E9D00) {
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
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x82130588
	ctx.lr = 0x822E9D20;
	sub_82130588(ctx, base);
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x82130588
	ctx.lr = 0x822E9D28;
	sub_82130588(ctx, base);
	// addi r31,r31,128
	r31.s64 = r31.s64 + 128;
	// li r30,3
	r30.s64 = 3;
loc_822E9D30:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9d50
	if (cr6.eq) goto loc_822E9D50;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E9D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E9D50:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822e9d30
	if (!cr0.eq) goto loc_822E9D30;
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

__attribute__((alias("__imp__sub_822E9D74"))) PPC_WEAK_FUNC(sub_822E9D74);
PPC_FUNC_IMPL(__imp__sub_822E9D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9D78"))) PPC_WEAK_FUNC(sub_822E9D78);
PPC_FUNC_IMPL(__imp__sub_822E9D78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// stfs f1,52(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 52, temp.u32);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x822e9d94
	if (!cr6.eq) goto loc_822E9D94;
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
loc_822E9D94:
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,52
	ctx.r8.s64 = ctx.r1.s64 + 52;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,48
	ctx.r4.s64 = 48;
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkd3d128 v60,v62,4
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v60 = vTemp;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrlimi128 v63,v59,1,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 1));
	// li r8,255
	ctx.r8.s64 = 255;
	// vspltw128 v57,v60,3
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x0));
	// vmrghw128 v56,v62,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vor128 v54,v56,v56
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vmrghw128 v53,v57,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vrlimi128 v54,v56,3,2
	simde_mm_store_ps(v54.f32, simde_mm_blend_ps(simde_mm_load_ps(v54.f32), simde_mm_permute_ps(simde_mm_load_ps(v56.f32), 78), 3));
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v55,v52,1,0
	simde_mm_store_ps(v55.f32, simde_mm_blend_ps(simde_mm_load_ps(v55.f32), simde_mm_permute_ps(simde_mm_load_ps(v52.f32), 228), 1));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// vor128 v51,v53,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// stvx128 v54,r6,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// vrlimi128 v51,v53,3,2
	simde_mm_store_ps(v51.f32, simde_mm_blend_ps(simde_mm_load_ps(v51.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 78), 3));
	// stvx128 v51,r5,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,124(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// stwx r8,r4,r7
	PPC_STORE_U32(ctx.r4.u32 + ctx.r7.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9E30"))) PPC_WEAK_FUNC(sub_822E9E30);
PPC_FUNC_IMPL(__imp__sub_822E9E30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x822E9E38;
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
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r30,100(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// ble cr6,0x822e9e60
	if (!cr6.gt) goto loc_822E9E60;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_822E9E60:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2470
	ctx.lr = 0x822E9E6C;
	sub_821D2470(ctx, base);
	// lvlx128 v63,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r11,r30,6,0,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// li r8,32
	ctx.r8.s64 = 32;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// vrlimi128 v62,v63,1,1
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// li r9,255
	ctx.r9.s64 = 255;
	// stvx128 v62,r10,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// vrlimi128 v61,v63,1,1
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// stvx128 v61,r6,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stwx r9,r7,r5
	PPC_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.r9.u32);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x822e9ecc
	if (!cr6.gt) goto loc_822E9ECC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_822E9ECC:
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r8,r10
	r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v60,v63,1,1
	simde_mm_store_ps(v60.f32, simde_mm_blend_ps(simde_mm_load_ps(v60.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v59,v63,1,1
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,124(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stwx r9,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E9F10"))) PPC_WEAK_FUNC(sub_822E9F10);
PPC_FUNC_IMPL(__imp__sub_822E9F10) {
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
	PPCRegister f0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822E9F18;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfs f1,228(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x822e9f50
	if (cr6.lt) goto loc_822E9F50;
	// li r11,0
	r11.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_822E9F50:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,208
	ctx.r10.s64 = 208;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-7796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7796);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f3
	ctx.f13.f64 = double(float(f0.f64 * ctx.f3.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x821d2470
	ctx.lr = 0x822E9F80;
	sub_821D2470(ctx, base);
	// lvlx128 v62,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,120(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r6,r8,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// li r3,32
	ctx.r3.s64 = 32;
	// vrlimi128 v60,v61,1,1
	simde_mm_store_ps(v60.f32, simde_mm_blend_ps(simde_mm_load_ps(v60.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 147), 1));
	// addi r9,r1,228
	ctx.r9.s64 = ctx.r1.s64 + 228;
	// li r8,16
	ctx.r8.s64 = 16;
	// vupkd3d128 v58,v59,4
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// li r27,48
	r27.s64 = 48;
	// li r26,255
	r26.s64 = 255;
	// stvx128 v60,r6,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r7,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// vrlimi128 v57,v61,1,1
	simde_mm_store_ps(v57.f32, simde_mm_blend_ps(simde_mm_load_ps(v57.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 147), 1));
	// vspltw128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vspltw128 v54,v58,3
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x0));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stvx128 v57,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// vmrghw128 v53,v59,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r7,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// vmrghw128 v52,v54,v55
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vor128 v51,v53,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// vor128 v50,v52,v52
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vrlimi128 v51,v53,3,2
	simde_mm_store_ps(v51.f32, simde_mm_blend_ps(simde_mm_load_ps(v51.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 78), 3));
	// vrlimi128 v50,v52,3,2
	simde_mm_store_ps(v50.f32, simde_mm_blend_ps(simde_mm_load_ps(v50.f32), simde_mm_permute_ps(simde_mm_load_ps(v52.f32), 78), 3));
	// stvx128 v51,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stvx128 v50,r9,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,124(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r26,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r26.u32);
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// bl 0x822e9e30
	ctx.lr = 0x822EA078;
	sub_822E9E30(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822EA084"))) PPC_WEAK_FUNC(sub_822EA084);
PPC_FUNC_IMPL(__imp__sub_822EA084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA088"))) PPC_WEAK_FUNC(sub_822EA088);
PPC_FUNC_IMPL(__imp__sub_822EA088) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-3756
	ctx.r9.s64 = r11.s64 + -3756;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822EA0C0;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-7792(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7792, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822EA0D4;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822ea0ec
	if (cr6.eq) goto loc_822EA0EC;
	// bl 0x82130588
	ctx.lr = 0x822EA0E8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822EA0EC:
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

__attribute__((alias("__imp__sub_822EA104"))) PPC_WEAK_FUNC(sub_822EA104);
PPC_FUNC_IMPL(__imp__sub_822EA104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA108"))) PPC_WEAK_FUNC(sub_822EA108);
PPC_FUNC_IMPL(__imp__sub_822EA108) {
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
	// bl 0x822e6b38
	ctx.lr = 0x822EA120;
	sub_822E6B38(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-3756
	ctx.r9.s64 = r11.s64 + -3756;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822EA150;
	sub_822E5138(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r6,-3732
	ctx.r4.s64 = ctx.r6.s64 + -3732;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// lfs f0,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,252(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stfs f0,248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f0,244(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stfs f0,240(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// stfs f0,284(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stfs f0,276(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 276, temp.u32);
	// stfs f0,272(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 272, temp.u32);
	// stfs f0,316(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 316, temp.u32);
	// stfs f0,312(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 312, temp.u32);
	// stfs f0,308(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 304, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822EA1BC"))) PPC_WEAK_FUNC(sub_822EA1BC);
PPC_FUNC_IMPL(__imp__sub_822EA1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA1C0"))) PPC_WEAK_FUNC(sub_822EA1C0);
PPC_FUNC_IMPL(__imp__sub_822EA1C0) {
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
	PPCRegister f0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822EA1C8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r24,32
	r24.s64 = 32;
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r25,48
	r25.s64 = 48;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r5,80
	ctx.r5.s64 = 80;
	// lvlx128 v60,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r29,0
	r29.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// addi r28,r31,128
	r28.s64 = r31.s64 + 128;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// li r26,3
	r26.s64 = 3;
	// stw r4,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r4.u32);
	// stb r29,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r29.u8);
	// stvx128 v58,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r29,118(r31)
	PPC_STORE_U8(r31.u32 + 118, r29.u8);
	// stvx128 v57,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// lis r23,-32120
	r23.s64 = -2105016320;
	// stvx128 v59,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822EA268:
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r29
	r27.u64 = r29.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea298
	if (cr6.eq) goto loc_822EA298;
	// lbz r27,6(r30)
	r27.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822ea298
	if (!cr6.eq) goto loc_822EA298;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA298:
	// lwz r11,-7796(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -7796);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// bl 0x8244d150
	ctx.lr = 0x822EA2BC;
	sub_8244D150(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea2f0
	if (cr6.eq) goto loc_822EA2F0;
	// lbz r11,6(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ea2f0
	if (cr6.eq) goto loc_822EA2F0;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ea2f0
	if (!cr6.eq) goto loc_822EA2F0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA2F0:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x822ea268
	if (!cr0.eq) goto loc_822EA268;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// vupkd3d128 v55,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v55 = vTemp;
	// vspltw128 v62,v55,3
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x0));
	// ble cr6,0x822ea37c
	if (!cr6.gt) goto loc_822EA37C;
	// vmrghw128 v54,v63,v63
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// vmrghw128 v53,v62,v63
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// vmrghw128 v62,v53,v54
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
loc_822EA330:
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// stvx128 v63,r6,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r5,r11,r8
	ctx.r5.u64 = r11.u64 + ctx.r8.u64;
	// stvx128 v63,r5,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// stvx128 v62,r4,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stwx r29,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, r29.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x822ea330
	if (cr6.lt) goto loc_822EA330;
loc_822EA37C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822EA384"))) PPC_WEAK_FUNC(sub_822EA384);
PPC_FUNC_IMPL(__imp__sub_822EA384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA388"))) PPC_WEAK_FUNC(sub_822EA388);
PPC_FUNC_IMPL(__imp__sub_822EA388) {
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
	ctx.lr = 0x822EA390;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,32(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f31,20(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f31,24(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lwz r30,464(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 464);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea490
	if (cr6.eq) goto loc_822EA490;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82564e28
	ctx.lr = 0x822EA3D4;
	sub_82564E28(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822ea3e4
	if (!cr6.lt) goto loc_822EA3E4;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// b 0x822ea3f8
	goto loc_822EA3F8;
loc_822EA3E4:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f31,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	f31.f64 = double(temp.f32);
	// bl 0x82564e28
	ctx.lr = 0x822EA3F4;
	sub_82564E28(ctx, base);
	// fdivs f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 / f31.f64));
loc_822EA3F8:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r10,r11,-3776
	ctx.r10.s64 = r11.s64 + -3776;
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// blt cr6,0x822ea44c
	if (cr6.lt) goto loc_822EA44C;
	// lhz r11,46(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 46);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822ea430
	if (!cr6.eq) goto loc_822EA430;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x822ea43c
	goto loc_822EA43C;
loc_822EA430:
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
loc_822EA43C:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// stfs f10,32(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_822EA44C:
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfs f13,520(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 520);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822ea490
	if (cr6.lt) goto loc_822EA490;
	// lhz r11,44(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 44);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822ea474
	if (!cr6.eq) goto loc_822EA474;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x822ea480
	goto loc_822EA480;
loc_822EA474:
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822EA480:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f11,32(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_822EA490:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822EA4A0"))) PPC_WEAK_FUNC(sub_822EA4A0);
PPC_FUNC_IMPL(__imp__sub_822EA4A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822EA4A8;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x822EA4B0;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r11,r5,320
	r11.s64 = ctx.r5.s64 + 320;
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r28,48
	r28.s64 = 48;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltw128 v126,v63,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f0,-6176(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6176);
	f0.f64 = double(temp.f32);
	// lfs f12,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lvx128 v127,r11,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v0,r11,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f30,f12,f0
	f30.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f13,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// vmaddcfp128 v126,v127,v126,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v126.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stfs f30,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fdivs f28,f13,f12
	f28.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// bl 0x822ea388
	ctx.lr = 0x822EA52C;
	sub_822EA388(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f29,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lwz r26,144(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// beq cr6,0x822ea78c
	if (cr6.eq) goto loc_822EA78C;
	// lfs f3,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f3.f64 = double(temp.f32);
	// fcmpu cr6,f3,f29
	cr6.compare(ctx.f3.f64, f29.f64);
	// beq cr6,0x822ea78c
	if (cr6.eq) goto loc_822EA78C;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r27,1
	r27.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// beq cr6,0x822ea574
	if (cr6.eq) goto loc_822EA574;
	// lbz r11,116(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ea574
	if (!cr6.eq) goto loc_822EA574;
	// stb r27,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r27.u8);
	// stw r29,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r29.u32);
loc_822EA574:
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v126,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v62.f32)));
	// lfs f12,-3708(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3708);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f31,f9
	f31.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// blt cr6,0x822ea7a0
	if (cr6.lt) goto loc_822EA7A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vpermwi128 v61,v127,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// vpermwi128 v0,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fneg f0,f30
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vor128 v60,v126,v126
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v59,v126,v126
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// fdivs f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 / f31.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v54,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vmulfp128 v127,v63,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v53.f32)));
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v57,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v58,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vspltw128 v55,v57,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// vpermwi128 v52,v127,99
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vpermwi128 v13,v127,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// lbz r4,116(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// lfs f12,96(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// fmuls f30,f12,f28
	f30.f64 = double(float(ctx.f12.f64 * f28.f64));
	// vmulfp128 v12,v61,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp128 v60,v0,v55,v60
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v55.f32)), simde_mm_load_ps(v60.f32)));
	// vmaddfp128 v59,v0,v56,v59
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v56.f32)), simde_mm_load_ps(v59.f32)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822ea6f0
	if (cr6.eq) goto loc_822EA6F0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v127,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,64
	ctx.r8.s64 = r31.s64 + 64;
	// addi r9,r31,80
	ctx.r9.s64 = r31.s64 + 80;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lvlx128 v50,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vspltw128 v11,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmaddfp v10,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v9,v0,v11,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v10,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822ea698
	if (cr6.eq) goto loc_822EA698;
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
loc_822EA698:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822e9f10
	ctx.lr = 0x822EA6AC;
	sub_822E9F10(ctx, base);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stb r29,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r29.u8);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822e9f10
	ctx.lr = 0x822EA6D4;
	sub_822E9F10(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// stvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// b 0x822ea7a0
	goto loc_822EA7A0;
loc_822EA6F0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bgt cr6,0x822ea754
	if (cr6.gt) goto loc_822EA754;
	// lfs f0,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-3712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3712);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f8,f9,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// blt cr6,0x822ea754
	if (cr6.lt) goto loc_822EA754;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e9d78
	ctx.lr = 0x822EA750;
	sub_822E9D78(ctx, base);
	// b 0x822ea7a0
	goto loc_822EA7A0;
loc_822EA754:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f29.f64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e9f10
	ctx.lr = 0x822EA770;
	sub_822E9F10(ctx, base);
	// stvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r27,118(r31)
	PPC_STORE_U8(r31.u32 + 118, r27.u8);
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// b 0x822ea7a0
	goto loc_822EA7A0;
loc_822EA78C:
	// li r11,0
	r11.s64 = 0;
	// stfs f29,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
loc_822EA7A0:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x822EA7BC;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822EA7C0"))) PPC_WEAK_FUNC(sub_822EA7C0);
PPC_FUNC_IMPL(__imp__sub_822EA7C0) {
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
	ctx.lr = 0x822EA7C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32131
	r25.s64 = -2105737216;
	// lis r11,-21846
	r11.s64 = -1431699456;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r28,r11,43691
	r28.u64 = r11.u64 | 43691;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,11724(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 11724);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(r28.u32)) >> 32;
	// rlwinm r11,r8,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r7,r9
	r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r4,r31
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821b3478
	ctx.lr = 0x822EA810;
	sub_821B3478(ctx, base);
	// lwz r10,11724(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 11724);
	// lwz r6,104(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// li r26,0
	r26.s64 = 0;
	// mulhwu r7,r8,r28
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(r28.u32)) >> 32;
	// rlwinm r11,r7,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r24,8(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// slw r27,r3,r4
	r27.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r4.u8 & 0x3F));
	// ble cr6,0x822ea8a4
	if (!cr6.gt) goto loc_822EA8A4;
	// li r30,0
	r30.s64 = 0;
	// li r29,0
	r29.s64 = 0;
loc_822EA850:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & r27.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ea888
	if (cr6.eq) goto loc_822EA888;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r5,64
	ctx.r5.s64 = 64;
	// add r3,r29,r24
	ctx.r3.u64 = r29.u64 + r24.u64;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x822EA878;
	sub_8244D5C0(ctx, base);
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// andc r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ~r27.u64;
	// stwx r9,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r9.u32);
loc_822EA888:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,64
	r29.s64 = r29.s64 + 64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x822ea850
	if (cr6.lt) goto loc_822EA850;
	// lwz r10,11724(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 11724);
loc_822EA8A4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r6,108(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// li r3,4
	ctx.r3.s64 = 4;
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(r28.u32)) >> 32;
	// lwz r11,-7796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7796);
	// lwz r4,340(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// rlwinm r11,r8,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r7,r9
	r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r5,r11,32
	ctx.r5.s64 = r11.s64 + 32;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x821793e0
	ctx.lr = 0x822EA8E0;
	sub_821793E0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ea914
	if (cr6.eq) goto loc_822EA914;
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ea914
	if (cr6.eq) goto loc_822EA914;
	// lbz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822ea914
	if (!cr6.eq) goto loc_822EA914;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA914:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822EA91C"))) PPC_WEAK_FUNC(sub_822EA91C);
PPC_FUNC_IMPL(__imp__sub_822EA91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA920"))) PPC_WEAK_FUNC(sub_822EA920);
PPC_FUNC_IMPL(__imp__sub_822EA920) {
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
	ctx.lr = 0x822EA928;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r29,48
	r31.s64 = r29.s64 + 48;
	// addi r10,r11,-3732
	ctx.r10.s64 = r11.s64 + -3732;
	// li r28,28
	r28.s64 = 28;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_822EA944:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea960
	if (cr6.eq) goto loc_822EA960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e9d00
	ctx.lr = 0x822EA958;
	sub_822E9D00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822EA960;
	sub_82130588(ctx, base);
loc_822EA960:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822ea944
	if (!cr0.eq) goto loc_822EA944;
	// addi r31,r29,164
	r31.s64 = r29.s64 + 164;
	// li r28,4
	r28.s64 = 4;
loc_822EA974:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea990
	if (cr6.eq) goto loc_822EA990;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e9d00
	ctx.lr = 0x822EA988;
	sub_822E9D00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822EA990;
	sub_82130588(ctx, base);
loc_822EA990:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822ea974
	if (!cr0.eq) goto loc_822EA974;
	// lwz r3,180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// bl 0x82130588
	ctx.lr = 0x822EA9A4;
	sub_82130588(ctx, base);
	// lwz r31,184(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EA9B0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ea9d8
	if (!cr6.eq) goto loc_822EA9D8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ea9d8
	if (cr6.eq) goto loc_822EA9D8;
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
	ctx.lr = 0x822EA9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA9D8:
	// lwz r3,188(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ea9f8
	if (cr6.eq) goto loc_822EA9F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA9F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA9F8:
	// lwz r3,336(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 336);
	// bl 0x82130588
	ctx.lr = 0x822EAA00;
	sub_82130588(ctx, base);
	// lwz r3,340(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 340);
	// bl 0x821870b8
	ctx.lr = 0x822EAA08;
	sub_821870B8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-3756
	ctx.r9.s64 = r11.s64 + -3756;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822EAA24;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,-7792(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7792, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822EAA38;
	sub_822E6940(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EAA40"))) PPC_WEAK_FUNC(sub_822EAA40);
PPC_FUNC_IMPL(__imp__sub_822EAA40) {
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
	ctx.lr = 0x822EAA48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r9,1023
	ctx.r9.s64 = 67043328;
	// addi r8,r30,-1
	ctx.r8.s64 = r30.s64 + -1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r30,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// ori r6,r9,65535
	ctx.r6.u64 = ctx.r9.u64 | 65535;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// li r29,-1
	r29.s64 = -1;
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// cmplw cr6,r30,r6
	cr6.compare<uint32_t>(r30.u32, ctx.r6.u32, xer);
	// stw r7,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r7.u32);
	// rlwinm r3,r30,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// ble cr6,0x822eaaa4
	if (!cr6.gt) goto loc_822EAAA4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822EAAA4:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82130550
	ctx.lr = 0x822EAAAC;
	sub_82130550(ctx, base);
	// lis r11,16383
	r11.s64 = 1073676288;
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// ble cr6,0x822eaac8
	if (!cr6.gt) goto loc_822EAAC8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822EAAC8:
	// bl 0x82130528
	ctx.lr = 0x822EAACC;
	sub_82130528(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// addi r29,r31,128
	r29.s64 = r31.s64 + 128;
	// li r30,3
	r30.s64 = 3;
	// lwz r11,-7796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7796);
	// lwz r28,336(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 336);
loc_822EAAE4:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821b4838
	ctx.lr = 0x822EAAF8;
	sub_821B4838(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822eaae4
	if (!cr0.eq) goto loc_822EAAE4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ea1c0
	ctx.lr = 0x822EAB10;
	sub_822EA1C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EAB18"))) PPC_WEAK_FUNC(sub_822EAB18);
PPC_FUNC_IMPL(__imp__sub_822EAB18) {
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
	// bl 0x822ea920
	ctx.lr = 0x822EAB38;
	sub_822EA920(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eab50
	if (cr6.eq) goto loc_822EAB50;
	// bl 0x82130588
	ctx.lr = 0x822EAB4C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822EAB50:
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

__attribute__((alias("__imp__sub_822EAB68"))) PPC_WEAK_FUNC(sub_822EAB68);
PPC_FUNC_IMPL(__imp__sub_822EAB68) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822EAB70;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r3,32
	ctx.r3.s64 = 32;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822EAB8C;
	sub_82130528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// addi r29,r6,30576
	r29.s64 = ctx.r6.s64 + 30576;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f31,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f31.f64 = double(temp.f32);
	// addi r4,r5,-3680
	ctx.r4.s64 = ctx.r5.s64 + -3680;
	// stfs f31,12(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfs f31,16(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// lfs f13,-13148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lfs f12,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,24(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// stfs f12,28(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// bl 0x821ca540
	ctx.lr = 0x822EABFC;
	sub_821CA540(ctx, base);
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-3692
	ctx.r4.s64 = r11.s64 + -3692;
	// lwz r3,-25232(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822EAC20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822EAC2C;
	sub_821C9A90(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r29,r7,-3704
	r29.s64 = ctx.r7.s64 + -3704;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24728);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EAC58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
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
	ctx.lr = 0x822EAC8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-27772
	ctx.r4.s64 = ctx.r10.s64 + -27772;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822EACA4;
	sub_8218B688(ctx, base);
	// lwz r7,188(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-27840
	ctx.r4.s64 = ctx.r8.s64 + -27840;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EACC0;
	sub_8218A568(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// stfs f31,220(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// lfs f0,11360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822EACE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eacf4
	if (cr6.eq) goto loc_822EACF4;
	// bl 0x8218fe20
	ctx.lr = 0x822EACF0;
	sub_8218FE20(ctx, base);
	// b 0x822eacf8
	goto loc_822EACF8;
loc_822EACF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EACF8:
	// stw r3,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821902b0
	ctx.lr = 0x822EAD0C;
	sub_821902B0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x82190540
	ctx.lr = 0x822EAD1C;
	sub_82190540(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82190640
	ctx.lr = 0x822EAD30;
	sub_82190640(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187150
	ctx.lr = 0x822EAD48;
	sub_82187150(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r28,r31,48
	r28.s64 = r31.s64 + 48;
	// addi r27,r31,20
	r27.s64 = r31.s64 + 20;
loc_822EAD58:
	// stbx r30,r27,r29
	PPC_STORE_U8(r27.u32 + r29.u32, r30.u8);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x822EAD64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ead74
	if (cr6.eq) goto loc_822EAD74;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// b 0x822ead78
	goto loc_822EAD78;
loc_822EAD74:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EAD78:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822eaa40
	ctx.lr = 0x822EAD84;
	sub_822EAA40(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,28
	cr6.compare<int32_t>(r29.s32, 28, xer);
	// blt cr6,0x822ead58
	if (cr6.lt) goto loc_822EAD58;
	// addi r28,r31,164
	r28.s64 = r31.s64 + 164;
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
loc_822EADA0:
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x822EADA8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eadb8
	if (cr6.eq) goto loc_822EADB8;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// b 0x822eadbc
	goto loc_822EADBC;
loc_822EADB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EADBC:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// bl 0x822eaa40
	ctx.lr = 0x822EADC8;
	sub_822EAA40(ctx, base);
	// stbx r30,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, r30.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x822eada0
	if (cr6.lt) goto loc_822EADA0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822EADE8"))) PPC_WEAK_FUNC(sub_822EADE8);
PPC_FUNC_IMPL(__imp__sub_822EADE8) {
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
	// li r3,352
	ctx.r3.s64 = 352;
	// bl 0x82130528
	ctx.lr = 0x822EADFC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eae0c
	if (cr6.eq) goto loc_822EAE0C;
	// bl 0x822ea108
	ctx.lr = 0x822EAE08;
	sub_822EA108(ctx, base);
	// b 0x822eae10
	goto loc_822EAE10;
loc_822EAE0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822EAE10:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-7796
	r11.s64 = r11.s64 + -7796;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x822eab68
	ctx.lr = 0x822EAE20;
	sub_822EAB68(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EAE30"))) PPC_WEAK_FUNC(sub_822EAE30);
PPC_FUNC_IMPL(__imp__sub_822EAE30) {
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
	ctx.lr = 0x822EAE38;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,20
	r11.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822EAE50;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r9,100(r1)
	PPC_STORE_U64(ctx.r1.u32 + 100, ctx.r9.u64);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x8217f768
	ctx.lr = 0x822EAE70;
	sub_8217F768(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r4,r7,-31280
	ctx.r4.s64 = ctx.r7.s64 + -31280;
	// lwz r3,-26876(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822EAE84;
	sub_8217C088(ctx, base);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r6,184(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EAE9C;
	sub_82189CE0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187f40
	ctx.lr = 0x822EAEB0;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822eaf34
	if (cr6.eq) goto loc_822EAF34;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187b88
	ctx.lr = 0x822EAEC4;
	sub_82187B88(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
loc_822EAED0:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eaee4
	if (cr6.eq) goto loc_822EAEE4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822ea7c0
	ctx.lr = 0x822EAEE4;
	sub_822EA7C0(ctx, base);
loc_822EAEE4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,28
	cr6.compare<int32_t>(r30.s32, 28, xer);
	// blt cr6,0x822eaed0
	if (cr6.lt) goto loc_822EAED0;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,164
	r29.s64 = r31.s64 + 164;
	// addi r28,r31,160
	r28.s64 = r31.s64 + 160;
loc_822EAF00:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eaf14
	if (cr6.eq) goto loc_822EAF14;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822ea7c0
	ctx.lr = 0x822EAF14;
	sub_822EA7C0(ctx, base);
loc_822EAF14:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x822eaf00
	if (cr6.lt) goto loc_822EAF00;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187ba8
	ctx.lr = 0x822EAF2C;
	sub_82187BA8(ctx, base);
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187bd0
	ctx.lr = 0x822EAF34;
	sub_82187BD0(ctx, base);
loc_822EAF34:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x822EAF40;
	sub_8217F768(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x822EAF4C;
	sub_8217F768(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82491668
	ctx.lr = 0x822EAF54;
	sub_82491668(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EAF5C"))) PPC_WEAK_FUNC(sub_822EAF5C);
PPC_FUNC_IMPL(__imp__sub_822EAF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EAF60"))) PPC_WEAK_FUNC(sub_822EAF60);
PPC_FUNC_IMPL(__imp__sub_822EAF60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r8,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r8.u8);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f13,28(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EAFAC"))) PPC_WEAK_FUNC(sub_822EAFAC);
PPC_FUNC_IMPL(__imp__sub_822EAFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EAFB0"))) PPC_WEAK_FUNC(sub_822EAFB0);
PPC_FUNC_IMPL(__imp__sub_822EAFB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821ec060
	sub_821EC060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822EAFF8"))) PPC_WEAK_FUNC(sub_822EAFF8);
PPC_FUNC_IMPL(__imp__sub_822EAFF8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EAFFC"))) PPC_WEAK_FUNC(sub_822EAFFC);
PPC_FUNC_IMPL(__imp__sub_822EAFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB000"))) PPC_WEAK_FUNC(sub_822EB000);
PPC_FUNC_IMPL(__imp__sub_822EB000) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82144a20
	ctx.lr = 0x822EB028;
	sub_82144A20(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eb044
	if (cr6.eq) goto loc_822EB044;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,23
	cr6.compare<uint32_t>(r11.u32, 23, xer);
	// bne cr6,0x822eb044
	if (!cr6.eq) goto loc_822EB044;
	// stw r3,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r3.u32);
	// b 0x822eb05c
	goto loc_822EB05C;
loc_822EB044:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r10,-3328
	ctx.r3.s64 = ctx.r10.s64 + -3328;
	// bl 0x82130000
	ctx.lr = 0x822EB05C;
	sub_82130000(ctx, base);
loc_822EB05C:
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

__attribute__((alias("__imp__sub_822EB074"))) PPC_WEAK_FUNC(sub_822EB074);
PPC_FUNC_IMPL(__imp__sub_822EB074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB078"))) PPC_WEAK_FUNC(sub_822EB078);
PPC_FUNC_IMPL(__imp__sub_822EB078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822eb090
	if (!cr6.eq) goto loc_822EB090;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_822EB090:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lfs f0,7220(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7220);
	f0.f64 = double(temp.f32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f12,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// stfs f12,32(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// bgt cr6,0x822eb0d8
	if (cr6.gt) goto loc_822EB0D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_822EB0D8:
	// stfs f0,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821ec060
	sub_821EC060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822EB0F0"))) PPC_WEAK_FUNC(sub_822EB0F0);
PPC_FUNC_IMPL(__imp__sub_822EB0F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB0F4"))) PPC_WEAK_FUNC(sub_822EB0F4);
PPC_FUNC_IMPL(__imp__sub_822EB0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB0F8"))) PPC_WEAK_FUNC(sub_822EB0F8);
PPC_FUNC_IMPL(__imp__sub_822EB0F8) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822eb144
	if (!cr6.gt) goto loc_822EB144;
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822eb144
	if (!cr6.gt) goto loc_822EB144;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822eb144
	if (!cr6.eq) goto loc_822EB144;
	// bl 0x822eb078
	ctx.lr = 0x822EB144;
	sub_822EB078(ctx, base);
loc_822EB144:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822eb180
	if (cr6.lt) goto loc_822EB180;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x822eb174
	if (cr6.lt) goto loc_822EB174;
	// bne cr6,0x822eb17c
	if (!cr6.eq) goto loc_822EB17C;
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// li r11,2
	r11.s64 = 2;
	// b 0x822eb178
	goto loc_822EB178;
loc_822EB174:
	// li r11,3
	r11.s64 = 3;
loc_822EB178:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_822EB17C:
	// stfs f31,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_822EB180:
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

__attribute__((alias("__imp__sub_822EB198"))) PPC_WEAK_FUNC(sub_822EB198);
PPC_FUNC_IMPL(__imp__sub_822EB198) {
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
	// bl 0x824e0648
	ctx.lr = 0x822EB1B0;
	sub_824E0648(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-3252
	ctx.r6.s64 = ctx.r7.s64 + -3252;
	// lfs f13,-3212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3212);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3216(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3216);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-3220(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3220);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822EB204"))) PPC_WEAK_FUNC(sub_822EB204);
PPC_FUNC_IMPL(__imp__sub_822EB204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB208"))) PPC_WEAK_FUNC(sub_822EB208);
PPC_FUNC_IMPL(__imp__sub_822EB208) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-3208
	ctx.r3.s64 = r11.s64 + -3208;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB214"))) PPC_WEAK_FUNC(sub_822EB214);
PPC_FUNC_IMPL(__imp__sub_822EB214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB218"))) PPC_WEAK_FUNC(sub_822EB218);
PPC_FUNC_IMPL(__imp__sub_822EB218) {
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
	// addi r5,r11,-3124
	ctx.r5.s64 = r11.s64 + -3124;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EB254;
	sub_824DF200(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-3148
	ctx.r5.s64 = ctx.r10.s64 + -3148;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EB274;
	sub_824DF200(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3172
	ctx.r5.s64 = ctx.r9.s64 + -3172;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EB294;
	sub_824DF200(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-3196
	ctx.r5.s64 = ctx.r7.s64 + -3196;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822EB2B4;
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

__attribute__((alias("__imp__sub_822EB2CC"))) PPC_WEAK_FUNC(sub_822EB2CC);
PPC_FUNC_IMPL(__imp__sub_822EB2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB2D0"))) PPC_WEAK_FUNC(sub_822EB2D0);
PPC_FUNC_IMPL(__imp__sub_822EB2D0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822eb2f8
	if (cr6.eq) goto loc_822EB2F8;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822eb390
	if (!cr6.eq) goto loc_822EB390;
loc_822EB2F8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f0,f11,f0,f12
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822eb340
	if (cr6.lt) goto loc_822EB340;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822EB340:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x822eb378
	if (!cr6.gt) goto loc_822EB378;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822eb370
	if (!cr6.lt) goto loc_822EB370;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x822EB368;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// b 0x822eb37c
	goto loc_822EB37C;
loc_822EB370:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// b 0x822eb37c
	goto loc_822EB37C;
loc_822EB378:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_822EB37C:
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,20(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_822EB390:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822EB3A4"))) PPC_WEAK_FUNC(sub_822EB3A4);
PPC_FUNC_IMPL(__imp__sub_822EB3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB3A8"))) PPC_WEAK_FUNC(sub_822EB3A8);
PPC_FUNC_IMPL(__imp__sub_822EB3A8) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eb3ec
	if (cr6.eq) goto loc_822EB3EC;
	// bl 0x822eb2d0
	ctx.lr = 0x822EB3CC;
	sub_822EB2D0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// bl 0x822eb0f8
	ctx.lr = 0x822EB3EC;
	sub_822EB0F8(ctx, base);
loc_822EB3EC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822EB400"))) PPC_WEAK_FUNC(sub_822EB400);
PPC_FUNC_IMPL(__imp__sub_822EB400) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lfs f13,7220(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7220);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f13,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfs f1,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// bgt cr6,0x822eb458
	if (cr6.gt) goto loc_822EB458;
	// stfs f1,24(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// b 0x822eb45c
	goto loc_822EB45C;
loc_822EB458:
	// stfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_822EB45C:
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822eb490
	if (cr6.eq) goto loc_822EB490;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r5,r31,40
	ctx.r5.s64 = r31.s64 + 40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822eb490
	if (!cr6.eq) goto loc_822EB490;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// bl 0x821ee370
	ctx.lr = 0x822EB490;
	sub_821EE370(ctx, base);
loc_822EB490:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eb4c4
	if (cr6.eq) goto loc_822EB4C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822eb2d0
	ctx.lr = 0x822EB4A4;
	sub_822EB2D0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// bl 0x822eb0f8
	ctx.lr = 0x822EB4C4;
	sub_822EB0F8(ctx, base);
loc_822EB4C4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_822EB4D8"))) PPC_WEAK_FUNC(sub_822EB4D8);
PPC_FUNC_IMPL(__imp__sub_822EB4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x822EB4E0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r11,-2756
	ctx.r8.s64 = r11.s64 + -2756;
	// li r30,0
	r30.s64 = 0;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// lfs f0,-15956(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15956);
	f0.f64 = double(temp.f32);
	// stb r30,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r30.u8);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r11,r31,28
	r11.s64 = r31.s64 + 28;
	// stfs f31,24(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stb r30,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r30.u8);
	// stfs f31,36(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// addi r29,r6,-2772
	r29.s64 = ctx.r6.s64 + -2772;
	// stfs f31,44(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stb r30,52(r31)
	PPC_STORE_U8(r31.u32 + 52, r30.u8);
	// stfs f31,56(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stb r30,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r30.u8);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stfs f31,64(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lwz r3,-24728(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -24728);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EB57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
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
	ctx.lr = 0x822EB5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-27772
	ctx.r4.s64 = ctx.r10.s64 + -27772;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822EB5C8;
	sub_8218B688(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stfs f31,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stfs f31,92(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lfs f0,32688(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32688);
	f0.f64 = double(temp.f32);
	// lfs f13,-32032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,-2776(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -2776);
	f0.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stfs f13,88(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,-2780(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -2780);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f0,-2784(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -2784);
	f0.f64 = double(temp.f32);
	// lfs f13,-2788(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -2788);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// addi r4,r7,-2808
	ctx.r4.s64 = ctx.r7.s64 + -2808;
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lfs f0,-2792(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2792);
	f0.f64 = double(temp.f32);
	// lfs f13,-2796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -2796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f31,116(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f31,120(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// lfs f0,-2800(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -2800);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f31,132(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f31,136(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f13,140(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EB674;
	sub_8218A568(ctx, base);
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-2816
	ctx.r4.s64 = r11.s64 + -2816;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EB690;
	sub_8218A568(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822EB6B4"))) PPC_WEAK_FUNC(sub_822EB6B4);
PPC_FUNC_IMPL(__imp__sub_822EB6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB6B8"))) PPC_WEAK_FUNC(sub_822EB6B8);
PPC_FUNC_IMPL(__imp__sub_822EB6B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7788(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7788);
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

__attribute__((alias("__imp__sub_822EB6DC"))) PPC_WEAK_FUNC(sub_822EB6DC);
PPC_FUNC_IMPL(__imp__sub_822EB6DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB6E0"))) PPC_WEAK_FUNC(sub_822EB6E0);
PPC_FUNC_IMPL(__imp__sub_822EB6E0) {
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
	// addi r5,r11,-2704
	ctx.r5.s64 = r11.s64 + -2704;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822EB71C;
	sub_824DF200(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-2720
	ctx.r5.s64 = ctx.r10.s64 + -2720;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822EB73C;
	sub_824DF200(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-2736
	ctx.r5.s64 = ctx.r9.s64 + -2736;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822EB75C;
	sub_824DF200(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-2752
	ctx.r5.s64 = ctx.r7.s64 + -2752;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822EB77C;
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

__attribute__((alias("__imp__sub_822EB794"))) PPC_WEAK_FUNC(sub_822EB794);
PPC_FUNC_IMPL(__imp__sub_822EB794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB798"))) PPC_WEAK_FUNC(sub_822EB798);
PPC_FUNC_IMPL(__imp__sub_822EB798) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82375c98
	ctx.lr = 0x822EB7B4;
	sub_82375C98(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x82375c98
	ctx.lr = 0x822EB7BC;
	sub_82375C98(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82375c98
	ctx.lr = 0x822EB7C4;
	sub_82375C98(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822eb7f8
	if (cr6.gt) goto loc_822EB7F8;
	// lfs f11,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822eb7f0
	if (cr6.gt) goto loc_822EB7F0;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822eb900
	if (!cr6.gt) goto loc_822EB900;
loc_822EB7F0:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822eb82c
	if (!cr6.gt) goto loc_822EB82C;
loc_822EB7F8:
	// li r9,80
	ctx.r9.s64 = 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r11,96
	r11.s64 = 96;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	f0.f64 = double(temp.f32);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// b 0x822eb864
	goto loc_822EB864;
loc_822EB82C:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822eb86c
	if (!cr6.gt) goto loc_822EB86C;
	// li r11,128
	r11.s64 = 128;
	// li r9,112
	ctx.r9.s64 = 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	f0.f64 = double(temp.f32);
	// lfs f13,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
loc_822EB864:
	// stfs f10,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_822EB86C:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822EB890;
	sub_8218A6E0(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822EB8B4;
	sub_8218A6E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lis r11,257
	r11.s64 = 16842752;
	// ori r11,r11,257
	r11.u64 = r11.u64 | 257;
	// lfs f9,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// lfs f2,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// fmr f4,f9
	ctx.f4.f64 = ctx.f9.f64;
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// fmr f3,f9
	ctx.f3.f64 = ctx.f9.f64;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x82194b58
	ctx.lr = 0x822EB900;
	sub_82194B58(ctx, base);
loc_822EB900:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB914"))) PPC_WEAK_FUNC(sub_822EB914);
PPC_FUNC_IMPL(__imp__sub_822EB914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

