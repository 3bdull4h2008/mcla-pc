#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_827A3050"))) PPC_WEAK_FUNC(sub_827A3050);
PPC_FUNC_IMPL(__imp__sub_827A3050) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827A3058;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d8
	ctx.lr = 0x827A3060;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lfs f29,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f29.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f30,f29
	f30.f64 = f29.f64;
	// fmr f28,f31
	f28.f64 = f31.f64;
	// lbz r9,256(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 256);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827a30dc
	if (cr6.eq) goto loc_827A30DC;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x826e5cb8
	ctx.lr = 0x827A30A4;
	sub_826E5CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r29,288
	ctx.r3.s64 = r29.s64 + 288;
	// bl 0x827a4ac8
	ctx.lr = 0x827A30B0;
	sub_827A4AC8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x827a30dc
	if (!cr6.gt) goto loc_827A30DC;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x826e5cb8
	ctx.lr = 0x827A30C0;
	sub_826E5CB8(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,288
	ctx.r3.s64 = r11.s64 + 288;
	// bl 0x827a4a90
	ctx.lr = 0x827A30D0;
	sub_827A4A90(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lfs f28,252(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 252);
	f28.f64 = double(temp.f32);
loc_827A30DC:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f31,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f31,8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// beq cr6,0x827a3118
	if (cr6.eq) goto loc_827A3118;
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f30,4(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f28,8(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// rlwimi r11,r10,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
loc_827A3118:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x827A3124;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A3128"))) PPC_WEAK_FUNC(sub_827A3128);
PPC_FUNC_IMPL(__imp__sub_827A3128) {
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
	// bl 0x823d91f0
	ctx.lr = 0x827A3130;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d0
	ctx.lr = 0x827A3138;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r30,0
	r30.s64 = 0;
	// lis r8,-32242
	ctx.r8.s64 = -2113011712;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f13,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stb r30,124(r1)
	PPC_STORE_U8(ctx.r1.u32 + 124, r30.u8);
	// lfs f12,14752(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14752);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,412(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 412);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f11,-20628(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20628);
	ctx.f11.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmuls f11,f12,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f10,3732(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f10.f64 = double(temp.f32);
	// addis r5,r8,6
	ctx.r5.s64 = ctx.r8.s64 + 393216;
	// lfs f29,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// addi r5,r5,16704
	ctx.r5.s64 = ctx.r5.s64 + 16704;
	// lfs f30,-31400(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31400);
	f30.f64 = double(temp.f32);
	// fsel f9,f11,f11,f31
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// fsel f8,f11,f11,f31
	ctx.f8.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// fmr f28,f30
	f28.f64 = f30.f64;
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f6,f7,f0,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f8.f64;
	// fmadds f5,f6,f10,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f10.f64 + f0.f64));
	// fmuls f4,f5,f13
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// stfs f4,120(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r11,448(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 448);
	// lfs f3,148(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,144(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 144);
	ctx.f2.f64 = double(temp.f32);
	// fadds f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 + ctx.f2.f64));
	// fmuls f0,f1,f29
	f0.f64 = double(float(ctx.f1.f64 * f29.f64));
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r10,496(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 496);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lwz r8,188(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lwz r7,192(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lfs f13,208(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f12,196(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r6,104(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// lfs f11,112(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x827a6448
	ctx.lr = 0x827A3258;
	sub_827A6448(ctx, base);
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a3274
	if (cr6.eq) goto loc_827A3274;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x827a3274
	if (!cr6.eq) goto loc_827A3274;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_827A3274:
	// mr r27,r30
	r27.u64 = r30.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a32fc
	if (cr6.eq) goto loc_827A32FC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A3294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r26,r3,48
	r26.s64 = ctx.r3.s64 + 48;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x826e5cb8
	ctx.lr = 0x827A32A0;
	sub_826E5CB8(ctx, base);
	// lfs f0,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f13,8(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f12,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f28,f3
	f28.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x827a32e4
	if (!cr6.eq) goto loc_827A32E4;
	// fmr f28,f30
	f28.f64 = f30.f64;
	// b 0x827a3300
	goto loc_827A3300;
loc_827A32E4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// beq cr6,0x827a3300
	if (cr6.eq) goto loc_827A3300;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// li r27,1
	r27.s64 = 1;
	// b 0x827a3300
	goto loc_827A3300;
loc_827A32FC:
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
loc_827A3300:
	// lbz r11,16(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// stfs f31,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// stfs f31,8(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 8, temp.u32);
	// fcmpu cr6,f28,f30
	cr6.compare(f28.f64, f30.f64);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stfs f31,12(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 12, temp.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// stb r10,16(r28)
	PPC_STORE_U8(r28.u32 + 16, ctx.r10.u8);
	// beq cr6,0x827a3444
	if (cr6.eq) goto loc_827A3444;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x826e95f0
	ctx.lr = 0x827A332C;
	sub_826E95F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A333C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// fmuls f27,f1,f29
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64 * f29.f64));
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A3354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// fmuls f29,f1,f29
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64 * f29.f64));
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A336C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f30,f9
	f30.f64 = double(float(sqrt(ctx.f9.f64)));
	// bl 0x826e95f0
	ctx.lr = 0x827A3394;
	sub_826E95F0(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827A33A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r3,32
	r29.s64 = ctx.r3.s64 + 32;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A33C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r3,32
	ctx.r7.s64 = ctx.r3.s64 + 32;
	// lfs f8,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f7,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f6,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lbz r6,6(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// lfs f5,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// cmplwi cr6,r6,2
	cr6.compare<uint32_t>(ctx.r6.u32, 2, xer);
	// fmuls f4,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// fmadds f26,f7,f5,f4
	f26.f64 = double(float(ctx.f7.f64 * ctx.f5.f64 + ctx.f4.f64));
	// bne cr6,0x827a33f8
	if (!cr6.eq) goto loc_827A33F8;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x826e9870
	ctx.lr = 0x827A33F8;
	sub_826E9870(ctx, base);
loc_827A33F8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3408
	if (!cr6.eq) goto loc_827A3408;
	// fmuls f30,f26,f30
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(f26.f64 * f30.f64));
loc_827A3408:
	// fadds f0,f29,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 + f27.f64));
	// lbz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// li r11,16256
	r11.s64 = 16256;
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// fsel f12,f30,f30,f31
	ctx.f12.f64 = f30.f64 >= 0.0 ? f30.f64 : f31.f64;
	// rlwimi r11,r27,6,25,25
	r11.u64 = (__builtin_rotateleft32(r27.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stfs f28,4(r28)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// stfs f12,8(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r28.u32 + 8, temp.u32);
	// or r8,r11,r9
	ctx.r8.u64 = r11.u64 | ctx.r9.u64;
	// stb r8,16(r28)
	PPC_STORE_U8(r28.u32 + 16, ctx.r8.u8);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f11,12(r28)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r28.u32 + 12, temp.u32);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r6,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r6.u32);
loc_827A3444:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba1c
	ctx.lr = 0x827A3450;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A3454"))) PPC_WEAK_FUNC(sub_827A3454);
PPC_FUNC_IMPL(__imp__sub_827A3454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A3458"))) PPC_WEAK_FUNC(sub_827A3458);
PPC_FUNC_IMPL(__imp__sub_827A3458) {
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
	ctx.lr = 0x827A3460;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827a3480
	if (!cr6.eq) goto loc_827A3480;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827A3480:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822452f8
	ctx.lr = 0x827A3488;
	sub_822452F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8273a178
	ctx.lr = 0x827A3494;
	sub_8273A178(ctx, base);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a34c0
	if (cr6.eq) goto loc_827A34C0;
	// bl 0x82739c00
	ctx.lr = 0x827A34B0;
	sub_82739C00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a34c0
	if (cr6.eq) goto loc_827A34C0;
	// li r28,1
	r28.s64 = 1;
loc_827A34C0:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a34e8
	if (cr6.eq) goto loc_827A34E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x8273a848
	ctx.lr = 0x827A34D8;
	sub_8273A848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// and r28,r9,r28
	r28.u64 = ctx.r9.u64 & r28.u64;
loc_827A34E8:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3560
	if (!cr6.eq) goto loc_827A3560;
	// lwz r30,16(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826e5cb8
	ctx.lr = 0x827A3500;
	sub_826E5CB8(ctx, base);
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f10,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f13,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f12,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmuls f6,f9,f9
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f5,f7,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f11
	cr6.compare(ctx.f5.f64, ctx.f11.f64);
	// bge cr6,0x827a3560
	if (!cr6.lt) goto loc_827A3560;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826e5cb8
	ctx.lr = 0x827A3538;
	sub_826E5CB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273e210
	ctx.lr = 0x827A3544;
	sub_8273E210(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x827a3560
	if (cr6.lt) goto loc_827A3560;
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
loc_827A3560:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A356C"))) PPC_WEAK_FUNC(sub_827A356C);
PPC_FUNC_IMPL(__imp__sub_827A356C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A3570"))) PPC_WEAK_FUNC(sub_827A3570);
PPC_FUNC_IMPL(__imp__sub_827A3570) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827A3578;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lfs f29,-31400(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f29.f64 = double(temp.f32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// beq cr6,0x827a3688
	if (cr6.eq) goto loc_827A3688;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x827a3458
	ctx.lr = 0x827A35C4;
	sub_827A3458(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a367c
	if (!cr6.eq) goto loc_827A367C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A35E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A35F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A360C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,48(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x827A3620;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x826e5cb8
	ctx.lr = 0x827A362C;
	sub_826E5CB8(ctx, base);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmadds f12,f0,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fsqrts f31,f12
	f31.f64 = double(float(sqrt(ctx.f12.f64)));
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x827a3664
	if (!cr6.lt) goto loc_827A3664;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x827a368c
	goto loc_827A368C;
loc_827A3664:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x827a368c
	if (cr6.eq) goto loc_827A368C;
	// li r27,1
	r27.s64 = 1;
	// stw r28,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r28.u32);
	// b 0x827a368c
	goto loc_827A368C;
loc_827A367C:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a368c
	if (cr6.eq) goto loc_827A368C;
loc_827A3688:
	// stw r26,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r26.u32);
loc_827A368C:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// stfs f30,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f30,4(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// stfs f30,12(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// stb r11,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r11.u8);
	// beq cr6,0x827a36f0
	if (cr6.eq) goto loc_827A36F0;
	// li r10,16256
	ctx.r10.s64 = 16256;
	// stfs f31,4(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// clrlwi r9,r11,26
	ctx.r9.u64 = r11.u32 & 0x3F;
	// rlwimi r10,r27,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(r27.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stb r8,16(r30)
	PPC_STORE_U8(r30.u32 + 16, ctx.r8.u8);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x826e95f0
	ctx.lr = 0x827A36D0;
	sub_826E95F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827A36E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,14884(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f0,12(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
loc_827A36F0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A3704"))) PPC_WEAK_FUNC(sub_827A3704);
PPC_FUNC_IMPL(__imp__sub_827A3704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A3708"))) PPC_WEAK_FUNC(sub_827A3708);
PPC_FUNC_IMPL(__imp__sub_827A3708) {
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
	ctx.lr = 0x827A3710;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lbz r11,16(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 16);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827a37a8
	if (!cr6.eq) goto loc_827A37A8;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r30,104
	ctx.r5.s64 = r30.s64 + 104;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x827a2b38
	ctx.lr = 0x827A3750;
	sub_827A2B38(ctx, base);
	// addi r5,r30,84
	ctx.r5.s64 = r30.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x827a3570
	ctx.lr = 0x827A376C;
	sub_827A3570(ctx, base);
	// addi r5,r30,64
	ctx.r5.s64 = r30.s64 + 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a3128
	ctx.lr = 0x827A377C;
	sub_827A3128(ctx, base);
	// addi r5,r30,124
	ctx.r5.s64 = r30.s64 + 124;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a3050
	ctx.lr = 0x827A378C;
	sub_827A3050(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827a59a0
	ctx.lr = 0x827A3798;
	sub_827A59A0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,152(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 152, temp.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,156(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 156, temp.u32);
loc_827A37A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827A37B4"))) PPC_WEAK_FUNC(sub_827A37B4);
PPC_FUNC_IMPL(__imp__sub_827A37B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A37B8"))) PPC_WEAK_FUNC(sub_827A37B8);
PPC_FUNC_IMPL(__imp__sub_827A37B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A37D4"))) PPC_WEAK_FUNC(sub_827A37D4);
PPC_FUNC_IMPL(__imp__sub_827A37D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A37D8"))) PPC_WEAK_FUNC(sub_827A37D8);
PPC_FUNC_IMPL(__imp__sub_827A37D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// b 0x82799138
	sub_82799138(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A37E4"))) PPC_WEAK_FUNC(sub_827A37E4);
PPC_FUNC_IMPL(__imp__sub_827A37E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A37E8"))) PPC_WEAK_FUNC(sub_827A37E8);
PPC_FUNC_IMPL(__imp__sub_827A37E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x827a3804
	if (cr6.gt) goto loc_827A3804;
	// li r11,0
	r11.s64 = 0;
loc_827A3804:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A380C"))) PPC_WEAK_FUNC(sub_827A380C);
PPC_FUNC_IMPL(__imp__sub_827A380C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A3810"))) PPC_WEAK_FUNC(sub_827A3810);
PPC_FUNC_IMPL(__imp__sub_827A3810) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827A3818;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lfs f0,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x827a3aa0
	if (cr6.gt) goto loc_827A3AA0;
	// lis r11,6
	r11.s64 = 393216;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r30,8(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// ori r9,r11,16977
	ctx.r9.u64 = r11.u64 | 16977;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827a3aa0
	if (!cr6.eq) goto loc_827A3AA0;
	// bl 0x82387a18
	ctx.lr = 0x827A385C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3aa0
	if (!cr6.eq) goto loc_827A3AA0;
	// lwz r31,8(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82794ee8
	ctx.lr = 0x827A3874;
	sub_82794EE8(ctx, base);
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x827a3aa0
	if (cr6.lt) goto loc_827A3AA0;
	// lwz r11,420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x827a3aa0
	if (cr6.eq) goto loc_827A3AA0;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a38a8
	if (cr6.eq) goto loc_827A38A8;
	// lwz r10,3604(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3604);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x827a3aa0
	if (!cr6.lt) goto loc_827A3AA0;
loc_827A38A8:
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3aa0
	if (!cr6.eq) goto loc_827A3AA0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r28,436(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// lwz r11,432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 432);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827a38d8
	if (cr6.eq) goto loc_827A38D8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a38d8
	if (cr6.eq) goto loc_827A38D8;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x827a3aa0
	if (!cr6.eq) goto loc_827A3AA0;
loc_827A38D8:
	// lwz r11,452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a3964
	if (cr6.eq) goto loc_827A3964;
	// lwz r31,192(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a3964
	if (cr6.eq) goto loc_827A3964;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822452f8
	ctx.lr = 0x827A38F8;
	sub_822452F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827a3964
	if (cr6.eq) goto loc_827A3964;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8273a178
	ctx.lr = 0x827A3908;
	sub_8273A178(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3964
	if (!cr6.eq) goto loc_827A3964;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A3928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,8(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// bl 0x826e5cb8
	ctx.lr = 0x827A3934;
	sub_826E5CB8(ctx, base);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f0,-11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11364);
	f0.f64 = double(temp.f32);
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f0
	cr6.compare(ctx.f7.f64, f0.f64);
	// blt cr6,0x827a3aa0
	if (cr6.lt) goto loc_827A3AA0;
loc_827A3964:
	// lfs f0,412(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x827a3978
	if (cr6.eq) goto loc_827A3978;
	// li r11,0
	r11.s64 = 0;
loc_827A3978:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a39cc
	if (cr6.eq) goto loc_827A39CC;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a39b4
	if (cr6.eq) goto loc_827A39B4;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a39b4
	if (cr6.eq) goto loc_827A39B4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lbz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 184);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a39cc
	if (cr6.eq) goto loc_827A39CC;
loc_827A39B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826e94e8
	ctx.lr = 0x827A39BC;
	sub_826E94E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a39d0
	if (cr6.eq) goto loc_827A39D0;
loc_827A39CC:
	// li r30,0
	r30.s64 = 0;
loc_827A39D0:
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A39E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A3A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827a3a14
	if (!cr6.eq) goto loc_827A3A14;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a3a38
	if (cr6.eq) goto loc_827A3A38;
loc_827A3A14:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a3a38
	if (cr6.eq) goto loc_827A3A38;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3a38
	if (!cr6.eq) goto loc_827A3A38;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x827a3a3c
	if (cr6.eq) goto loc_827A3A3C;
loc_827A3A38:
	// li r11,0
	r11.s64 = 0;
loc_827A3A3C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a3a90
	if (cr6.eq) goto loc_827A3A90;
	// lfs f0,12(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	f0.f64 = double(temp.f32);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lfs f13,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,0(r26)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// lfs f0,-20324(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20324);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x827a3aa0
	if (!cr6.gt) goto loc_827A3AA0;
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x827a3aa0
	if (!cr6.lt) goto loc_827A3AA0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stfs f31,4(r26)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r26.u32 + 4, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_827A3A90:
	// li r11,0
	r11.s64 = 0;
	// stfs f31,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r26.u32 + 4, temp.u32);
	// stfs f31,0(r26)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// stw r11,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r11.u32);
loc_827A3AA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A3AB0"))) PPC_WEAK_FUNC(sub_827A3AB0);
PPC_FUNC_IMPL(__imp__sub_827A3AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
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
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f12,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// lfs f13,-20320(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20320);
	ctx.f13.f64 = double(temp.f32);
	// stfs f11,4(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// ble cr6,0x827a3b18
	if (!cr6.gt) goto loc_827A3B18;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827a3dc8
	goto loc_827A3DC8;
loc_827A3B18:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x826e95f0
	ctx.lr = 0x827A3B20;
	sub_826E95F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A3B30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lfs f30,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f30.f64 = double(temp.f32);
	// fmuls f31,f1,f30
	f31.f64 = double(float(ctx.f1.f64 * f30.f64));
	// bl 0x826e95f0
	ctx.lr = 0x827A3B44;
	sub_826E95F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A3B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f30,f1,f30
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64 * f30.f64));
	// bl 0x826e6ec8
	ctx.lr = 0x827A3B60;
	sub_826E6EC8(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lbz r5,500(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 500);
	// rlwinm r4,r5,0,26,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827a3b9c
	if (cr6.eq) goto loc_827A3B9C;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a3b9c
	if (cr6.eq) goto loc_827A3B9C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827a3b9c
	if (cr6.eq) goto loc_827A3B9C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x827a3ba0
	goto loc_827A3BA0;
loc_827A3B9C:
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
loc_827A3BA0:
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r8,512
	ctx.r8.s64 = 512;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// ori r7,r10,16956
	ctx.r7.u64 = ctx.r10.u64 | 16956;
	// li r6,14366
	ctx.r6.s64 = 14366;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// lwzx r4,r9,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// lfs f0,-13148(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -13148);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x827a3cbc
	if (cr6.eq) goto loc_827A3CBC;
	// bl 0x826e5cb8
	ctx.lr = 0x827A3BE4;
	sub_826E5CB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v126,v63,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// bl 0x82794ee8
	ctx.lr = 0x827A3C08;
	sub_82794EE8(ctx, base);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lis r6,-32242
	ctx.r6.s64 = -2113011712;
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp128 v127,v62,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v127.f32)));
	// lfs f0,-21984(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21984);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x827A3C34;
	sub_82794EE8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvlx128 v61,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lfs f0,32680(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fmuls f31,f30,f0
	f31.f64 = double(float(f30.f64 * f0.f64));
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmaddfp128 v127,v59,v60,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)), simde_mm_load_ps(v127.f32)));
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v126,v58,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x827A3C7C;
	sub_82794EE8(ctx, base);
	// li r30,32
	r30.s64 = 32;
	// vor128 v57,v127,v127
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v56,r3,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp128 v57,v56,v126,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v57.f32)));
	// lvlx128 v55,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v126,v55,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x827A3CB0;
	sub_82794EE8(ctx, base);
	// lvx128 v54,r3,r30
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v127,v54,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v127.f32)));
	// b 0x827a3d94
	goto loc_827A3D94;
loc_827A3CBC:
	// bl 0x826e5cb8
	ctx.lr = 0x827A3CC0;
	sub_826E5CB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v53,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v126,v53,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// bl 0x82794ee8
	ctx.lr = 0x827A3CE4;
	sub_82794EE8(ctx, base);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lis r6,-32242
	ctx.r6.s64 = -2113011712;
	// lvx128 v52,r3,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp128 v127,v52,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v127.f32)));
	// lfs f0,-21988(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21988);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x827A3D10;
	sub_82794EE8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v49,r0,r3
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvlx128 v51,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lfs f0,32680(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fmuls f31,f30,f0
	f31.f64 = double(float(f30.f64 * f0.f64));
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmaddfp128 v127,v49,v50,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)), simde_mm_load_ps(v127.f32)));
	// lvlx128 v48,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v126,v48,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x827A3D58;
	sub_82794EE8(ctx, base);
	// li r30,32
	r30.s64 = 32;
	// vor128 v47,v127,v127
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v46,r3,r30
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmaddfp128 v47,v46,v126,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v47.f32)));
	// lvlx128 v45,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v126,v45,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// stvx128 v47,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x827A3D8C;
	sub_82794EE8(ctx, base);
	// lvx128 v44,r3,r30
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v127,v44,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(v127.f32)));
loc_827A3D94:
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827974f0
	ctx.lr = 0x827A3DA8;
	sub_827974F0(ctx, base);
	// lwz r5,192(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r11,r3,1
	r11.u64 = ctx.r3.u64 ^ 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
loc_827A3DC8:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_827A3DF8"))) PPC_WEAK_FUNC(sub_827A3DF8);
PPC_FUNC_IMPL(__imp__sub_827A3DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A3E08"))) PPC_WEAK_FUNC(sub_827A3E08);
PPC_FUNC_IMPL(__imp__sub_827A3E08) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827A3E10;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82387a18
	ctx.lr = 0x827A3E28;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a3e44
	if (cr6.eq) goto loc_827A3E44;
loc_827A3E34:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_827A3E44:
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a3e64
	if (cr6.eq) goto loc_827A3E64;
	// lwz r10,3604(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3604);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x827a3e34
	if (!cr6.lt) goto loc_827A3E34;
loc_827A3E64:
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a3e34
	if (!cr6.eq) goto loc_827A3E34;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82794ee8
	ctx.lr = 0x827A3E78;
	sub_82794EE8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x827a3e34
	if (cr6.lt) goto loc_827A3E34;
	// lfs f0,412(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x827a3ea0
	if (cr6.eq) goto loc_827A3EA0;
	// li r11,0
	r11.s64 = 0;
loc_827A3EA0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a3f6c
	if (cr6.eq) goto loc_827A3F6C;
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lfs f13,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f13,0(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// lfs f0,-20004(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20004);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x827a3ed4
	if (cr6.gt) goto loc_827A3ED4;
loc_827A3ED0:
	// li r8,0
	ctx.r8.s64 = 0;
loc_827A3ED4:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// addi r11,r11,384
	r11.s64 = r11.s64 + 384;
	// ori r7,r10,64167
	ctx.r7.u64 = ctx.r10.u64 | 64167;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r5,r7
	ctx.r9.s64 = ctx.r5.s64 * ctx.r7.s64;
	// lfs f13,3804(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3804);
	ctx.f13.f64 = double(temp.f32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r9,r10,9
	ctx.r9.u64 = ctx.r10.u32 & 0x7FFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x827a3e34
	if (cr6.gt) goto loc_827A3E34;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// addi r7,r10,2256
	ctx.r7.s64 = ctx.r10.s64 + 2256;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,288
	ctx.r4.s64 = r11.s64 + 288;
	// bl 0x827992d0
	ctx.lr = 0x827A3F50;
	sub_827992D0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a3f60
	if (cr6.eq) goto loc_827A3F60;
	// stfs f31,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
loc_827A3F60:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_827A3F6C:
	// stfs f31,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// b 0x827a3ed0
	goto loc_827A3ED0;
}

__attribute__((alias("__imp__sub_827A3F74"))) PPC_WEAK_FUNC(sub_827A3F74);
PPC_FUNC_IMPL(__imp__sub_827A3F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A3F78"))) PPC_WEAK_FUNC(sub_827A3F78);
PPC_FUNC_IMPL(__imp__sub_827A3F78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A3F9C"))) PPC_WEAK_FUNC(sub_827A3F9C);
PPC_FUNC_IMPL(__imp__sub_827A3F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A3FA0"))) PPC_WEAK_FUNC(sub_827A3FA0);
PPC_FUNC_IMPL(__imp__sub_827A3FA0) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827a402c
	if (cr6.eq) goto loc_827A402C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A3FD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// lis r8,-32242
	ctx.r8.s64 = -2113011712;
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f0,-19696(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -19696);
	f0.f64 = double(temp.f32);
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f0
	cr6.compare(ctx.f3.f64, f0.f64);
	// ble cr6,0x827a402c
	if (!cr6.gt) goto loc_827A402C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_827A402C:
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

__attribute__((alias("__imp__sub_827A4044"))) PPC_WEAK_FUNC(sub_827A4044);
PPC_FUNC_IMPL(__imp__sub_827A4044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4048"))) PPC_WEAK_FUNC(sub_827A4048);
PPC_FUNC_IMPL(__imp__sub_827A4048) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x827A4050;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// bl 0x82387a18
	ctx.lr = 0x827A4068;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4084
	if (cr6.eq) goto loc_827A4084;
loc_827A4074:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_827A4084:
	// lwz r31,8(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r11,420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x827a4074
	if (cr6.eq) goto loc_827A4074;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82794ee8
	ctx.lr = 0x827A409C;
	sub_82794EE8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x827a4074
	if (cr6.lt) goto loc_827A4074;
	// lwz r11,452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a413c
	if (cr6.eq) goto loc_827A413C;
	// lwz r31,192(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a413c
	if (cr6.eq) goto loc_827A413C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822452f8
	ctx.lr = 0x827A40D0;
	sub_822452F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827a413c
	if (cr6.eq) goto loc_827A413C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8273a178
	ctx.lr = 0x827A40E0;
	sub_8273A178(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a413c
	if (!cr6.eq) goto loc_827A413C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4100;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,8(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// bl 0x826e5cb8
	ctx.lr = 0x827A410C;
	sub_826E5CB8(ctx, base);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f0,-11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11364);
	f0.f64 = double(temp.f32);
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f0
	cr6.compare(ctx.f7.f64, f0.f64);
	// blt cr6,0x827a4074
	if (cr6.lt) goto loc_827A4074;
loc_827A413C:
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x827a4154
	if (cr6.eq) goto loc_827A4154;
	// li r11,0
	r11.s64 = 0;
loc_827A4154:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4174
	if (cr6.eq) goto loc_827A4174;
	// lfs f0,12(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,32(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,32(r23)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r23.u32 + 32, temp.u32);
	// b 0x827a4178
	goto loc_827A4178;
loc_827A4174:
	// stfs f31,32(r23)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r23.u32 + 32, temp.u32);
loc_827A4178:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// lfs f13,32(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-19700(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19700);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x827a4194
	if (cr6.gt) goto loc_827A4194;
	// li r10,0
	ctx.r10.s64 = 0;
loc_827A4194:
	// lbz r11,6(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 6);
	// clrlwi r27,r10,24
	r27.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// beq cr6,0x827a420c
	if (cr6.eq) goto loc_827A420C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a420c
	if (cr6.eq) goto loc_827A420C;
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// addi r11,r11,384
	r11.s64 = r11.s64 + 384;
	// ori r8,r10,64167
	ctx.r8.u64 = ctx.r10.u64 | 64167;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f0,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r6,r8
	ctx.r9.s64 = ctx.r6.s64 * ctx.r8.s64;
	// lfs f13,4400(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4400);
	ctx.f13.f64 = double(temp.f32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r3,r10,9
	ctx.r3.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x827a4074
	if (cr6.gt) goto loc_827A4074;
loc_827A420C:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// li r28,-1
	r28.s64 = -1;
	// addi r25,r11,-19692
	r25.s64 = r11.s64 + -19692;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r30,r25
	r30.u64 = r25.u64;
	// addi r29,r11,2256
	r29.s64 = r11.s64 + 2256;
loc_827A4224:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// addi r9,r11,288
	ctx.r9.s64 = r11.s64 + 288;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82799728
	ctx.lr = 0x827A4250;
	sub_82799728(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4270
	if (!cr6.eq) goto loc_827A4270;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r25,12
	r11.s64 = r25.s64 + 12;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827a4224
	if (cr6.lt) goto loc_827A4224;
loc_827A4270:
	// clrlwi r30,r31,24
	r30.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827a42b0
	if (cr6.eq) goto loc_827A42B0;
	// stw r24,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r24.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,16
	ctx.r8.s64 = 16;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r23,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x827a42b0
	if (cr6.eq) goto loc_827A42B0;
	// stfs f31,32(r23)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r23.u32 + 32, temp.u32);
loc_827A42B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827A42C0"))) PPC_WEAK_FUNC(sub_827A42C0);
PPC_FUNC_IMPL(__imp__sub_827A42C0) {
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
	ctx.lr = 0x827A42C8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a4408
	if (cr6.eq) goto loc_827A4408;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A42F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r3,48
	r29.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826e5cb8
	ctx.lr = 0x827A4300;
	sub_826E5CB8(ctx, base);
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f10,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lfs f11,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f6,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,412(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f0,f2
	f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// bne cr6,0x827a4388
	if (!cr6.eq) goto loc_827A4388;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A435C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f0,23364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 23364);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f8,f0
	cr6.compare(ctx.f8.f64, f0.f64);
	// b 0x827a4400
	goto loc_827A4400;
loc_827A4388:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f12,15004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15004);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x827a43e4
	if (cr6.lt) goto loc_827A43E4;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// fdivs f31,f0,f13
	f31.f64 = double(float(f0.f64 / ctx.f13.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a43f4
	if (cr6.eq) goto loc_827A43F4;
	// lwz r3,188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827a43f4
	if (cr6.eq) goto loc_827A43F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A43C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32242
	ctx.r9.s64 = -2113011712;
	// lfs f0,-19680(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x827a43f4
	if (!cr6.gt) goto loc_827A43F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,12428(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12428);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x827a4408
	if (!cr6.lt) goto loc_827A4408;
loc_827A43E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_827A43F4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,30712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
loc_827A4400:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// blt cr6,0x827a440c
	if (cr6.lt) goto loc_827A440C;
loc_827A4408:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827A440C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827A4418"))) PPC_WEAK_FUNC(sub_827A4418);
PPC_FUNC_IMPL(__imp__sub_827A4418) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827A4420;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x827A4428;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x827a4454
	if (!cr6.eq) goto loc_827A4454;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x827A4450;
	// b 0x823d9248
	return;
loc_827A4454:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f31,f2
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f2.f64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fmr f29,f30
	f29.f64 = f30.f64;
	// fcmpu cr6,f27,f30
	cr6.compare(f27.f64, f30.f64);
	// ble cr6,0x827a44fc
	if (!cr6.gt) goto loc_827A44FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f28,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f28.f64 = double(temp.f32);
loc_827A4478:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// bge cr6,0x827a44fc
	if (!cr6.lt) goto loc_827A44FC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A449C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A44C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// blt cr6,0x827a44f0
	if (cr6.lt) goto loc_827A44F0;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bne cr6,0x827a44ec
	if (!cr6.eq) goto loc_827A44EC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a44ec
	if (cr6.eq) goto loc_827A44EC;
	// mr r31,r29
	r31.u64 = r29.u64;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// fmr f29,f30
	f29.f64 = f30.f64;
	// b 0x827a44f0
	goto loc_827A44F0;
loc_827A44EC:
	// li r31,0
	r31.s64 = 0;
loc_827A44F0:
	// fsubs f27,f27,f28
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(f27.f64 - f28.f64));
	// fcmpu cr6,f27,f30
	cr6.compare(f27.f64, f30.f64);
	// bgt cr6,0x827a4478
	if (cr6.gt) goto loc_827A4478;
loc_827A44FC:
	// stfs f31,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x827A4510;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A4514"))) PPC_WEAK_FUNC(sub_827A4514);
PPC_FUNC_IMPL(__imp__sub_827A4514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4518"))) PPC_WEAK_FUNC(sub_827A4518);
PPC_FUNC_IMPL(__imp__sub_827A4518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A4524"))) PPC_WEAK_FUNC(sub_827A4524);
PPC_FUNC_IMPL(__imp__sub_827A4524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4528"))) PPC_WEAK_FUNC(sub_827A4528);
PPC_FUNC_IMPL(__imp__sub_827A4528) {
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
	ctx.lr = 0x827A4530;
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
	// lwz r30,128(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r27,92(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x827a455c
	if (!cr6.lt) goto loc_827A455C;
loc_827A4550:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827A455C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a4550
	if (cr6.eq) goto loc_827A4550;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82245340
	ctx.lr = 0x827A456C;
	sub_82245340(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827a4584
	if (cr6.eq) goto loc_827A4584;
	// bl 0x82244820
	ctx.lr = 0x827A4578;
	sub_82244820(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4550
	if (!cr6.eq) goto loc_827A4550;
loc_827A4584:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a50f0
	ctx.lr = 0x827A4594;
	sub_827A50F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4550
	if (!cr6.eq) goto loc_827A4550;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a50f0
	ctx.lr = 0x827A45B0;
	sub_827A50F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4550
	if (!cr6.eq) goto loc_827A4550;
	// addi r11,r27,-1
	r11.s64 = r27.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x827a45e8
	if (!cr6.lt) goto loc_827A45E8;
	// addi r5,r30,1
	ctx.r5.s64 = r30.s64 + 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a50f0
	ctx.lr = 0x827A45D8;
	sub_827A50F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a45ec
	if (!cr6.eq) goto loc_827A45EC;
loc_827A45E8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827A45EC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827A45F4"))) PPC_WEAK_FUNC(sub_827A45F4);
PPC_FUNC_IMPL(__imp__sub_827A45F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A45F8"))) PPC_WEAK_FUNC(sub_827A45F8);
PPC_FUNC_IMPL(__imp__sub_827A45F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827a465c
	if (cr6.eq) goto loc_827A465C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827a465c
	if (cr6.lt) goto loc_827A465C;
	// lwz r3,124(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// ble cr6,0x827a4640
	if (!cr6.gt) goto loc_827A4640;
loc_827A4634:
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827a4634
	if (cr0.gt) goto loc_827A4634;
loc_827A4640:
	// addi r7,r30,4
	ctx.r7.s64 = r30.s64 + 4;
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// bl 0x82242e90
	ctx.lr = 0x827A4650;
	sub_82242E90(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
loc_827A465C:
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

__attribute__((alias("__imp__sub_827A4674"))) PPC_WEAK_FUNC(sub_827A4674);
PPC_FUNC_IMPL(__imp__sub_827A4674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4678"))) PPC_WEAK_FUNC(sub_827A4678);
PPC_FUNC_IMPL(__imp__sub_827A4678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x827A4680;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r26,8(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A46CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A46E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// fnmsubs f31,f1,f0,f31
	f31.f64 = double(float(-(ctx.f1.f64 * f0.f64 - f31.f64)));
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x827a473c
	if (!cr6.gt) goto loc_827A473C;
	// stw r26,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r26.u32);
	// stw r31,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r31.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// fadds f31,f13,f30
	f31.f64 = double(float(ctx.f13.f64 + f30.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A4730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fdivs f12,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f31.f64 / ctx.f1.f64));
	// stfs f12,4(r25)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r25.u32 + 4, temp.u32);
	// b 0x827a4898
	goto loc_827A4898;
loc_827A473C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r22,0
	r22.s64 = 0;
	// addi r24,r11,2384
	r24.s64 = r11.s64 + 2384;
	// lfs f29,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
loc_827A4750:
	// lwz r11,92(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 92);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bge cr6,0x827a4898
	if (!cr6.lt) goto loc_827A4898;
	// lwz r28,124(r23)
	r28.u64 = PPC_LOAD_U32(r23.u32 + 124);
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x827a4778
	if (!cr6.gt) goto loc_827A4778;
loc_827A476C:
	// lwz r28,28(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827a476c
	if (cr0.gt) goto loc_827A476C;
loc_827A4778:
	// stfs f29,4(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r25.u32 + 4, temp.u32);
	// stw r31,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r31.u32);
	// stw r26,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r26.u32);
	// li r29,0
	r29.s64 = 0;
	// lwz r11,96(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827a4868
	if (!cr6.gt) goto loc_827A4868;
loc_827A4794:
	// addi r11,r29,8
	r11.s64 = r29.s64 + 8;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r27,r28
	r30.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x827a4858
	if (cr6.eq) goto loc_827A4858;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a47c4
	if (cr6.eq) goto loc_827A47C4;
	// add r11,r28,r29
	r11.u64 = r28.u64 + r29.u64;
	// lbz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 100);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a4858
	if (cr6.eq) goto loc_827A4858;
loc_827A47C4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A47D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A47F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v127,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827a4858
	if (cr6.eq) goto loc_827A4858;
	// lwzx r31,r27,r28
	r31.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4830;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x827a487c
	if (cr6.gt) goto loc_827A487C;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fadds f31,f1,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64 + f31.f64));
	// li r29,-1
	r29.s64 = -1;
loc_827A4858:
	// lwz r11,96(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x827a4794
	if (cr6.lt) goto loc_827A4794;
loc_827A4868:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpwi cr6,r22,3
	cr6.compare<int32_t>(r22.s32, 3, xer);
	// blt cr6,0x827a4750
	if (cr6.lt) goto loc_827A4750;
	// b 0x827a4898
	goto loc_827A4898;
loc_827A487C:
	// fsubs f31,f30,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f30.f64 - f31.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fdivs f0,f31,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 / ctx.f1.f64));
	// stfs f0,4(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 4, temp.u32);
	// stw r31,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r31.u32);
	// stw r26,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r26.u32);
loc_827A4898:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_827A48B4"))) PPC_WEAK_FUNC(sub_827A48B4);
PPC_FUNC_IMPL(__imp__sub_827A48B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A48B8"))) PPC_WEAK_FUNC(sub_827A48B8);
PPC_FUNC_IMPL(__imp__sub_827A48B8) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827A48C0;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,16(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827a4a7c
	if (!cr6.eq) goto loc_827A4A7C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r31,r11,288
	r31.s64 = r11.s64 + 288;
	// lwz r10,412(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a4a7c
	if (cr6.eq) goto loc_827A4A7C;
	// lwz r30,188(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,192(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// lfs f30,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	f30.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x827a4528
	ctx.lr = 0x827A4914;
	sub_827A4528(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4a7c
	if (cr6.eq) goto loc_827A4A7C;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lfs f1,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 412);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8279ea30
	ctx.lr = 0x827A492C;
	sub_8279EA30(ctx, base);
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lfs f1,412(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 412);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8279ea90
	ctx.lr = 0x827A493C;
	sub_8279EA90(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f30,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x827a4418
	ctx.lr = 0x827A49A0;
	sub_827A4418(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a4b10
	ctx.lr = 0x827A49B8;
	sub_827A4B10(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a45f8
	ctx.lr = 0x827A49D0;
	sub_827A45F8(ctx, base);
	// addi r6,r1,116
	ctx.r6.s64 = ctx.r1.s64 + 116;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a45f8
	ctx.lr = 0x827A49E4;
	sub_827A45F8(ctx, base);
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x827a49fc
	if (!cr6.eq) goto loc_827A49FC;
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4a7c
	if (cr6.eq) goto loc_827A4A7C;
loc_827A49FC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827a4a0c
	if (cr6.eq) goto loc_827A4A0C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82245bd0
	ctx.lr = 0x827A4A0C;
	sub_82245BD0(ctx, base);
loc_827A4A0C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a4a1c
	if (cr6.eq) goto loc_827A4A1C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82245bd0
	ctx.lr = 0x827A4A1C;
	sub_82245BD0(ctx, base);
loc_827A4A1C:
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x827a4a58
	if (!cr6.eq) goto loc_827A4A58;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4a7c
	if (cr6.eq) goto loc_827A4A7C;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a4678
	ctx.lr = 0x827A4A4C;
	sub_827A4678(ctx, base);
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x827a4a7c
	if (cr6.eq) goto loc_827A4A7C;
loc_827A4A58:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f2,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f2.f64 = double(temp.f32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// lfs f1,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// bl 0x827999e8
	ctx.lr = 0x827A4A7C;
	sub_827999E8(ctx, base);
loc_827A4A7C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A4A90"))) PPC_WEAK_FUNC(sub_827A4A90);
PPC_FUNC_IMPL(__imp__sub_827A4A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r11,32
	r11.s64 = 32;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-8(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f1,f10
	ctx.f1.f64 = double(float(sqrt(ctx.f10.f64)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A4AC8"))) PPC_WEAK_FUNC(sub_827A4AC8);
PPC_FUNC_IMPL(__imp__sub_827A4AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r11,32
	r11.s64 = 32;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lfs f0,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	f0.f64 = double(temp.f32);
	// lfs f13,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-12(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmadds f7,f13,f11,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f1,f12,f10,f7
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A4B08"))) PPC_WEAK_FUNC(sub_827A4B08);
PPC_FUNC_IMPL(__imp__sub_827A4B08) {
	PPC_FUNC_PROLOGUE();
	// b 0x8224fa68
	sub_8224FA68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A4B0C"))) PPC_WEAK_FUNC(sub_827A4B0C);
PPC_FUNC_IMPL(__imp__sub_827A4B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4B10"))) PPC_WEAK_FUNC(sub_827A4B10);
PPC_FUNC_IMPL(__imp__sub_827A4B10) {
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
	ctx.lr = 0x827A4B18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827a4c50
	if (cr6.eq) goto loc_827A4C50;
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4c50
	if (cr6.eq) goto loc_827A4C50;
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r26,92(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x827a4c14
	if (cr6.lt) goto loc_827A4C14;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8224f978
	ctx.lr = 0x827A4B60;
	sub_8224F978(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4b78
	if (cr6.eq) goto loc_827A4B78;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827A4B78:
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// bge cr6,0x827a4bb8
	if (!cr6.lt) goto loc_827A4BB8;
loc_827A4B88:
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
	// bl 0x8224f978
	ctx.lr = 0x827A4BA0;
	sub_8224F978(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4c08
	if (!cr6.eq) goto loc_827A4C08;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// blt cr6,0x827a4b88
	if (cr6.lt) goto loc_827A4B88;
loc_827A4BB8:
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827a4c50
	if (!cr6.gt) goto loc_827A4C50;
loc_827A4BC8:
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
	// bl 0x8224f978
	ctx.lr = 0x827A4BE0;
	sub_8224F978(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4c08
	if (!cr6.eq) goto loc_827A4C08;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827a4bc8
	if (cr6.lt) goto loc_827A4BC8;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827A4C08:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827A4C14:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x827a4c50
	if (!cr6.gt) goto loc_827A4C50;
loc_827A4C20:
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
	// bl 0x8224f978
	ctx.lr = 0x827A4C38;
	sub_8224F978(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4c08
	if (!cr6.eq) goto loc_827A4C08;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// blt cr6,0x827a4c20
	if (cr6.lt) goto loc_827A4C20;
loc_827A4C50:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A4C5C"))) PPC_WEAK_FUNC(sub_827A4C5C);
PPC_FUNC_IMPL(__imp__sub_827A4C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4C60"))) PPC_WEAK_FUNC(sub_827A4C60);
PPC_FUNC_IMPL(__imp__sub_827A4C60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,96(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827a4cb8
	if (!cr6.gt) goto loc_827A4CB8;
loc_827A4C74:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x827a4c9c
	if (cr6.eq) goto loc_827A4C9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x827a4c74
	if (cr6.lt) goto loc_827A4C74;
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_827A4C9C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827a4cb8
	if (cr6.lt) goto loc_827A4CB8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lbz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 100);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827a4cbc
	if (!cr6.eq) goto loc_827A4CBC;
loc_827A4CB8:
	// li r11,0
	r11.s64 = 0;
loc_827A4CBC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A4CC4"))) PPC_WEAK_FUNC(sub_827A4CC4);
PPC_FUNC_IMPL(__imp__sub_827A4CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A4CC8"))) PPC_WEAK_FUNC(sub_827A4CC8);
PPC_FUNC_IMPL(__imp__sub_827A4CC8) {
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
	// bl 0x8224f818
	ctx.lr = 0x827A4CE0;
	sub_8224F818(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827A4D00"))) PPC_WEAK_FUNC(sub_827A4D00);
PPC_FUNC_IMPL(__imp__sub_827A4D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x827A4D08;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-208
	r31.s64 = ctx.r1.s64 + -208;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x827a50c0
	if (cr6.lt) goto loc_827A50C0;
	// lwz r11,92(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x827a50c0
	if (!cr6.lt) goto loc_827A50C0;
	// lwz r25,124(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x827a4d50
	if (!cr6.gt) goto loc_827A4D50;
loc_827A4D44:
	// lwz r25,28(r25)
	r25.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827a4d44
	if (cr0.gt) goto loc_827A4D44;
loc_827A4D50:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// lwz r29,12(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4f44
	if (cr6.eq) goto loc_827A4F44;
	// lwz r26,96(r25)
	r26.u64 = PPC_LOAD_U32(r25.u32 + 96);
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x827A4D74;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r21,r11,2384
	r21.s64 = r11.s64 + 2384;
	// addi r24,r1,80
	r24.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x827a4e90
	if (!cr6.gt) goto loc_827A4E90;
	// mr r27,r24
	r27.u64 = r24.u64;
	// addi r30,r25,32
	r30.s64 = r25.s64 + 32;
	// addi r22,r25,100
	r22.s64 = r25.s64 + 100;
loc_827A4DA4:
	// lbzx r11,r22,r28
	r11.u64 = PPC_LOAD_U8(r22.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a4e14
	if (cr6.eq) goto loc_827A4E14;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4DC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A4DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v127,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827a4e14
	if (cr6.eq) goto loc_827A4E14;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
loc_827A4E14:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// blt cr6,0x827a4da4
	if (cr6.lt) goto loc_827A4DA4;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x827a4e90
	if (!cr6.gt) goto loc_827A4E90;
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lwz r8,384(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + 384);
	// addi r11,r23,384
	r11.s64 = r23.s64 + 384;
	// lwz r10,388(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 388);
	// ori r7,r9,64167
	ctx.r7.u64 = ctx.r9.u64 | 64167;
	// twllei r29,0
	// mulld r11,r8,r7
	r11.s64 = ctx.r8.s64 * ctx.r7.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,384(r23)
	PPC_STORE_U32(r23.u32 + 384, r11.u32);
	// divw r4,r6,r29
	ctx.r4.s32 = ctx.r6.s32 / r29.s32;
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// mullw r3,r4,r29
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r29.s32);
	// subf r9,r3,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r3.s64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rldicl r6,r11,32,32
	ctx.r6.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// andc r5,r29,r8
	ctx.r5.u64 = r29.u64 & ~ctx.r8.u64;
	// stw r6,388(r23)
	PPC_STORE_U32(r23.u32 + 388, ctx.r6.u32);
	// twlgei r5,-1
	// lwzx r3,r7,r24
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + r24.u32);
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9228
	return;
loc_827A4E90:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x827a50c0
	if (!cr6.gt) goto loc_827A50C0;
	// addi r29,r25,32
	r29.s64 = r25.s64 + 32;
	// addi r28,r25,100
	r28.s64 = r25.s64 + 100;
loc_827A4EA4:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a4f04
	if (!cr6.eq) goto loc_827A4F04;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4EC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A4EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v127,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v56,v58,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v55,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827a4f28
	if (!cr6.eq) goto loc_827A4F28;
loc_827A4F04:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// blt cr6,0x827a4ea4
	if (cr6.lt) goto loc_827A4EA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9228
	return;
loc_827A4F28:
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r25
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9228
	return;
loc_827A4F44:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224d270
	ctx.lr = 0x827A4F54;
	sub_8224D270(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r11,2384
	r28.s64 = r11.s64 + 2384;
	// ble cr6,0x827a504c
	if (!cr6.gt) goto loc_827A504C;
loc_827A4F6C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x827A4F78;
	sub_8224D6F8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A4F88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A4FA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v53,v127,v63
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v52,v54,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v51,v53,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32)));
	cr6.setFromMask(simde_mm_load_ps(v51.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827a5040
	if (cr6.eq) goto loc_827A5040;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x827A4FD4;
	sub_8224D6F8(ctx, base);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827a4ff4
	if (cr6.eq) goto loc_827A4FF4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,26,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827a4ff8
	if (!cr6.eq) goto loc_827A4FF8;
loc_827A4FF4:
	// li r11,0
	r11.s64 = 0;
loc_827A4FF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5040
	if (!cr6.eq) goto loc_827A5040;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x827A5010;
	sub_8224D6F8(ctx, base);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827a5030
	if (cr6.eq) goto loc_827A5030;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827a5034
	if (!cr6.eq) goto loc_827A5034;
loc_827A5030:
	// li r11,0
	r11.s64 = 0;
loc_827A5034:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a50d4
	if (cr6.eq) goto loc_827A50D4;
loc_827A5040:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x827a4f6c
	if (cr6.lt) goto loc_827A4F6C;
loc_827A504C:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x827a50c0
	if (!cr6.gt) goto loc_827A50C0;
loc_827A5058:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x827A5064;
	sub_8224D6F8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A5090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r3
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v49,v127,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v48,v50,v63
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v47,v49,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827a50d4
	if (!cr6.eq) goto loc_827A50D4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x827a5058
	if (cr6.lt) goto loc_827A5058;
loc_827A50C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9228
	return;
loc_827A50D4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x827A50E0;
	sub_8224D6F8(ctx, base);
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_827A50F0"))) PPC_WEAK_FUNC(sub_827A50F0);
PPC_FUNC_IMPL(__imp__sub_827A50F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// lwz r3,124(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827a510c
	if (!cr6.gt) goto loc_827A510C;
loc_827A5100:
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827a5100
	if (cr0.gt) goto loc_827A5100;
loc_827A510C:
	// b 0x827a4c60
	sub_827A4C60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A5110"))) PPC_WEAK_FUNC(sub_827A5110);
PPC_FUNC_IMPL(__imp__sub_827A5110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827A5118;
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
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5214
	if (cr6.eq) goto loc_827A5214;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827a5154
	if (!cr6.gt) goto loc_827A5154;
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x827a5158
	if (cr6.eq) goto loc_827A5158;
loc_827A5154:
	// li r11,0
	r11.s64 = 0;
loc_827A5158:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5214
	if (cr6.eq) goto loc_827A5214;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826e5cb8
	ctx.lr = 0x827A516C;
	sub_826E5CB8(ctx, base);
	// li r11,32
	r11.s64 = 32;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	f0.f64 = double(temp.f32);
	// lbz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// lfs f13,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rlwinm r7,r9,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// lfs f11,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f12,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f0,f8
	ctx.f7.f64 = double(float(f0.f64 * ctx.f8.f64));
	// fmadds f6,f13,f10,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f0,f11,f9,f6
	f0.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f6.f64));
	// beq cr6,0x827a51f8
	if (cr6.eq) goto loc_827A51F8;
	// lfs f13,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x827a51f8
	if (!cr6.eq) goto loc_827A51F8;
	// lfs f13,412(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// beq cr6,0x827a51e0
	if (cr6.eq) goto loc_827A51E0;
	// li r11,0
	r11.s64 = 0;
loc_827A51E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a51f8
	if (cr6.eq) goto loc_827A51F8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_827A51F8:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x827a5208
	if (cr6.lt) goto loc_827A5208;
	// li r11,0
	r11.s64 = 0;
loc_827A5208:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_827A5214:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827A5220"))) PPC_WEAK_FUNC(sub_827A5220);
PPC_FUNC_IMPL(__imp__sub_827A5220) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827A5228;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5258
	if (cr6.eq) goto loc_827A5258;
	// lwz r28,188(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827a526c
	if (!cr6.eq) goto loc_827A526C;
loc_827A5258:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_827A526C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f30,208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x827A5280;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827a52d4
	if (!cr6.eq) goto loc_827A52D4;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lwz r9,384(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// lwz r11,388(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 388);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// ori r7,r10,64167
	ctx.r7.u64 = ctx.r10.u64 | 64167;
	// mulld r10,r9,r7
	ctx.r10.s64 = ctx.r9.s64 * ctx.r7.s64;
	// lfs f0,14348(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r30,384
	ctx.r10.s64 = r30.s64 + 384;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,384(r30)
	PPC_STORE_U32(r30.u32 + 384, r11.u32);
	// rldicl r3,r11,32,32
	ctx.r3.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r3,388(r30)
	PPC_STORE_U32(r30.u32 + 388, ctx.r3.u32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f31,f11,f0
	f31.f64 = double(float(ctx.f11.f64 * f0.f64));
loc_827A52D4:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8224c408
	ctx.lr = 0x827A52DC;
	sub_8224C408(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r9,1
	ctx.r9.s64 = 1;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lwz r4,-10012(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// bl 0x826f2d98
	ctx.lr = 0x827A5300;
	sub_826F2D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8224f818
	ctx.lr = 0x827A530C;
	sub_8224F818(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r11,-18952
	r29.s64 = r11.s64 + -18952;
	// stw r29,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, r29.u32);
	// lwz r11,220(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5354
	if (!cr6.eq) goto loc_827A5354;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,-10012(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x826f2d98
	ctx.lr = 0x827A5344;
	sub_826F2D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8224f818
	ctx.lr = 0x827A5350;
	sub_8224F818(ctx, base);
	// stw r29,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, r29.u32);
loc_827A5354:
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827a5408
	if (cr6.eq) goto loc_827A5408;
	// lwz r11,220(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5488
	if (cr6.eq) goto loc_827A5488;
	// lwz r3,476(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 476);
	// bl 0x826edf18
	ctx.lr = 0x827A5380;
	sub_826EDF18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5408
	if (!cr6.eq) goto loc_827A5408;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lfs f2,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f2.f64 = double(temp.f32);
	// addis r4,r11,6
	ctx.r4.s64 = r11.s64 + 393216;
	// lfs f1,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// addi r9,r10,-19044
	ctx.r9.s64 = ctx.r10.s64 + -19044;
	// lwz r10,184(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// addi r4,r4,16704
	ctx.r4.s64 = ctx.r4.s64 + 16704;
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x8224c7b8
	ctx.lr = 0x827A53BC;
	sub_8224C7B8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8224fa68
	ctx.lr = 0x827A53C4;
	sub_8224FA68(ctx, base);
	// lwz r9,348(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827a53e4
	if (!cr6.eq) goto loc_827A53E4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_827A53E4:
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8224f818
	ctx.lr = 0x827A53F0;
	sub_8224F818(ctx, base);
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,8516
	ctx.r3.s64 = r11.s64 + 8516;
	// bl 0x826f00a0
	ctx.lr = 0x827A5404;
	sub_826F00A0(ctx, base);
	// stw r29,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r29.u32);
loc_827A5408:
	// lwz r11,220(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5488
	if (cr6.eq) goto loc_827A5488;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8224fa68
	ctx.lr = 0x827A541C;
	sub_8224FA68(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8224f818
	ctx.lr = 0x827A5428;
	sub_8224F818(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r31,r26,32
	r31.s64 = r26.s64 + 32;
	// stw r11,128(r27)
	PPC_STORE_U32(r27.u32 + 128, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,132(r27)
	PPC_STORE_U32(r27.u32 + 132, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82798d08
	ctx.lr = 0x827A5448;
	sub_82798D08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82798b98
	ctx.lr = 0x827A5458;
	sub_82798B98(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f31.f64 = double(temp.f32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82798698
	ctx.lr = 0x827A5488;
	sub_82798698(ctx, base);
loc_827A5488:
	// lwz r11,220(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A54A8"))) PPC_WEAK_FUNC(sub_827A54A8);
PPC_FUNC_IMPL(__imp__sub_827A54A8) {
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
	ctx.lr = 0x827A54B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x827a4b10
	ctx.lr = 0x827A54CC;
	sub_827A4B10(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x827a555c
	if (cr6.lt) goto loc_827A555C;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827a4d00
	ctx.lr = 0x827A54F0;
	sub_827A4D00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827a5588
	if (!cr6.eq) goto loc_827A5588;
	// addi r27,r28,1
	r27.s64 = r28.s64 + 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827a4d00
	ctx.lr = 0x827A5514;
	sub_827A4D00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827a5588
	if (!cr6.eq) goto loc_827A5588;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827a4d00
	ctx.lr = 0x827A5534;
	sub_827A4D00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827a5588
	if (!cr6.eq) goto loc_827A5588;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827a4d00
	ctx.lr = 0x827A5554;
	sub_827A4D00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827a5588
	if (!cr6.eq) goto loc_827A5588;
loc_827A555C:
	// lbz r11,84(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// ori r8,r9,224
	ctx.r8.u64 = ctx.r9.u64 | 224;
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// stb r8,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r8.u8);
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x8273bd80
	ctx.lr = 0x827A5588;
	sub_8273BD80(ctx, base);
loc_827A5588:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827A5590"))) PPC_WEAK_FUNC(sub_827A5590);
PPC_FUNC_IMPL(__imp__sub_827A5590) {
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
	ctx.lr = 0x827A5598;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r5,r30,240
	ctx.r5.s64 = r30.s64 + 240;
	// lbz r11,256(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 256);
	// lwz r29,28(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a55f4
	if (cr6.eq) goto loc_827A55F4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x827a5110
	ctx.lr = 0x827A55CC;
	sub_827A5110(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a55f4
	if (cr6.eq) goto loc_827A55F4;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a5220
	ctx.lr = 0x827A55E8;
	sub_827A5220(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r28,r10,27,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_827A55F4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5610
	if (cr6.eq) goto loc_827A5610;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// b 0x827a562c
	goto loc_827A562C;
loc_827A5610:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,188(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// bl 0x827a4b10
	ctx.lr = 0x827A5628;
	sub_827A4B10(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
loc_827A562C:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827a563c
	if (cr6.lt) goto loc_827A563C;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
loc_827A563C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827A5644"))) PPC_WEAK_FUNC(sub_827A5644);
PPC_FUNC_IMPL(__imp__sub_827A5644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A5648"))) PPC_WEAK_FUNC(sub_827A5648);
PPC_FUNC_IMPL(__imp__sub_827A5648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A5658"))) PPC_WEAK_FUNC(sub_827A5658);
PPC_FUNC_IMPL(__imp__sub_827A5658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827A5660;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addi r6,r10,-564
	ctx.r6.s64 = ctx.r10.s64 + -564;
	// addi r5,r9,-532
	ctx.r5.s64 = ctx.r9.s64 + -532;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x827A56A0;
	sub_823DEDD8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x827a598c
	if (cr6.eq) goto loc_827A598C;
	// lwz r28,16(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827a598c
	if (cr6.eq) goto loc_827A598C;
	// lwz r30,452(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 452);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827a598c
	if (cr6.eq) goto loc_827A598C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A56D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827a598c
	if (!cr6.eq) goto loc_827A598C;
	// lwz r30,432(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 432);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826e95f0
	ctx.lr = 0x827A56EC;
	sub_826E95F0(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x827a598c
	if (!cr6.eq) goto loc_827A598C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826e95f0
	ctx.lr = 0x827A5720;
	sub_826E95F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A5730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvx128 v63,r3,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vaddfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,14884(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827A5790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826e95f0
	ctx.lr = 0x827A57A8;
	sub_826E95F0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A57B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lvx128 v57,r3,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// vaddfp128 v56,v127,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v57.f32)));
	// addi r4,r7,2240
	ctx.r4.s64 = ctx.r7.s64 + 2240;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwz r7,4(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r9,-31648
	ctx.r6.s64 = ctx.r9.s64 + -31648;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// stfs f31,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v55,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v54,v55
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// addi r11,r5,-31664
	r11.s64 = ctx.r5.s64 + -31664;
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v54,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v63,v6
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v53,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A5850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826e95f0
	ctx.lr = 0x827A5868;
	sub_826E95F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A5878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// lvx128 v51,r3,r6
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stvx128 v51,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v50,r0,r4
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r11,452(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 452);
	// fmadds f8,f10,f12,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmadds f0,f13,f9,f8
	f0.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f8.f64));
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v48,v63,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmsum3fp128 v47,v63,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// stvx128 v48,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f13,f7,f0
	ctx.f13.f64 = double(float(ctx.f7.f64 - f0.f64));
	// stvx128 v47,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f0,f6,f0
	f0.f64 = double(float(ctx.f6.f64 - f0.f64));
	// beq cr6,0x827a5934
	if (cr6.eq) goto loc_827A5934;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5934
	if (cr6.eq) goto loc_827A5934;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827a5938
	if (cr6.eq) goto loc_827A5938;
loc_827A5934:
	// li r11,0
	r11.s64 = 0;
loc_827A5938:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5988
	if (cr6.eq) goto loc_827A5988;
	// lwz r11,452(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5970
	if (cr6.eq) goto loc_827A5970;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5970
	if (cr6.eq) goto loc_827A5970;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827a5974
	if (cr6.eq) goto loc_827A5974;
loc_827A5970:
	// li r11,0
	r11.s64 = 0;
loc_827A5974:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a598c
	if (cr6.eq) goto loc_827A598C;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x827a598c
	if (cr6.gt) goto loc_827A598C;
loc_827A5988:
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
loc_827A598C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827A59A0"))) PPC_WEAK_FUNC(sub_827A59A0);
PPC_FUNC_IMPL(__imp__sub_827A59A0) {
	PPC_FUNC_PROLOGUE();
	// b 0x827a5658
	sub_827A5658(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A59A4"))) PPC_WEAK_FUNC(sub_827A59A4);
PPC_FUNC_IMPL(__imp__sub_827A59A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A59A8"))) PPC_WEAK_FUNC(sub_827A59A8);
PPC_FUNC_IMPL(__imp__sub_827A59A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827A59B0;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A59F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f30,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f30.f64 = double(temp.f32);
	// fmuls f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 * f30.f64));
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * f30.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A5A24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r3,32
	ctx.r5.s64 = ctx.r3.s64 + 32;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vspltisw128 v58,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v127,r0,r30
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v57,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vmulfp128 v55,v59,v56
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v56.f32)));
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v127,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v54,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v53,v62,v63
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v52,v62,v63
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vsubfp128 v51,v61,v63
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A5AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vsubfp128 v49,v127,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v50.f32)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stvx128 v126,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r8,r11,2240
	ctx.r8.s64 = r11.s64 + 2240;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r10,r4,2528
	ctx.r10.s64 = ctx.r4.s64 + 2528;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,-31648
	ctx.r8.s64 = ctx.r3.s64 + -31648;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r9,-31664
	ctx.r4.s64 = ctx.r9.s64 + -31664;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v49,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v48,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v47,v48
	simde_mm_store_ps(v47.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v48.f32))));
	// vor128 v12,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v47,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v63,v6
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v46,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827A5BA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v44,v126,v45
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v45.f32)));
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A5BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f10,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// fmuls f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64));
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f11,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f10,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,-31400(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31400);
	f0.f64 = double(temp.f32);
	// lfs f13,-31068(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31068);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827A5C08:
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827a5c88
	if (!cr6.eq) goto loc_827A5C88;
	// lvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// vsubfp128 v42,v43,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_sub_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v42,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f6.f64));
	// fmadds f4,f8,f12,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f5.f64));
	// fmadds f3,f7,f11,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f4.f64));
	// fsubs f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsubs f1,f3,f13
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fsel f0,f2,f0,f3
	f0.f64 = ctx.f2.f64 >= 0.0 ? f0.f64 : ctx.f3.f64;
	// fsel f13,f1,f3,f13
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f3.f64 : ctx.f13.f64;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x827a5c5c
	if (!cr6.lt) goto loc_827A5C5C;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x827a5c74
	if (cr6.gt) goto loc_827A5C74;
loc_827A5C5C:
	// fabs f8,f0
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f9
	cr6.compare(ctx.f8.f64, ctx.f9.f64);
	// blt cr6,0x827a5c74
	if (cr6.lt) goto loc_827A5C74;
	// fabs f8,f13
	ctx.f8.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f9
	cr6.compare(ctx.f8.f64, ctx.f9.f64);
	// bge cr6,0x827a5c78
	if (!cr6.lt) goto loc_827A5C78;
loc_827A5C74:
	// li r11,1
	r11.s64 = 1;
loc_827A5C78:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x827a5c08
	if (cr6.lt) goto loc_827A5C08;
loc_827A5C88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A5CB4"))) PPC_WEAK_FUNC(sub_827A5CB4);
PPC_FUNC_IMPL(__imp__sub_827A5CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A5CB8"))) PPC_WEAK_FUNC(sub_827A5CB8);
PPC_FUNC_IMPL(__imp__sub_827A5CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x827A5CC0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// lwz r25,96(r28)
	r25.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x827a5e10
	if (cr6.eq) goto loc_827A5E10;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_827A5CFC:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// beq cr6,0x827a5e04
	if (cr6.eq) goto loc_827A5E04;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5D20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r8,r3,48
	ctx.r8.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A5D3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r3,48
	ctx.r6.s64 = ctx.r3.s64 + 48;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v127.f32)));
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827A5D64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bgt cr6,0x827a5e04
	if (cr6.gt) goto loc_827A5E04;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_827A5DA4:
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x827a5dd0
	if (!cr6.lt) goto loc_827A5DD0;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r7
	cr6.compare<uint32_t>(r30.u32, ctx.r7.u32, xer);
	// bne cr6,0x827a5dbc
	if (!cr6.eq) goto loc_827A5DBC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_827A5DBC:
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x827a5da4
	if (!cr6.eq) goto loc_827A5DA4;
loc_827A5DD0:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5e04
	if (cr6.eq) goto loc_827A5E04;
	// cmpw cr6,r8,r24
	cr6.compare<int32_t>(ctx.r8.s32, r24.s32, xer);
	// bge cr6,0x827a5e10
	if (!cr6.lt) goto loc_827A5E10;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r9,r26
	PPC_STORE_U32(ctx.r9.u32 + r26.u32, r28.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
loc_827A5E04:
	// lwz r25,4(r25)
	r25.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x827a5cfc
	if (!cr6.eq) goto loc_827A5CFC;
loc_827A5E10:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827A5E24"))) PPC_WEAK_FUNC(sub_827A5E24);
PPC_FUNC_IMPL(__imp__sub_827A5E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A5E28"))) PPC_WEAK_FUNC(sub_827A5E28);
PPC_FUNC_IMPL(__imp__sub_827A5E28) {
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
	ctx.lr = 0x827A5E30;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5E50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f0,7868(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7868);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bgt cr6,0x827a5f2c
	if (cr6.gt) goto loc_827A5F2C;
	// lbz r11,6(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bne cr6,0x827a5f3c
	if (!cr6.eq) goto loc_827A5F3C;
	// lwz r31,312(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 312);
loc_827A5E88:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a5f2c
	if (cr6.eq) goto loc_827A5F2C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A5EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r30,r3,32
	r30.s64 = ctx.r3.s64 + 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A5EBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r3,32
	ctx.r7.s64 = ctx.r3.s64 + 32;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r6,-32242
	ctx.r6.s64 = -2113011712;
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f10,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,-18452(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -18452);
	f0.f64 = double(temp.f32);
	// fmadds f9,f13,f10,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// blt cr6,0x827a60a8
	if (cr6.lt) goto loc_827A60A8;
	// lwz r3,640(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827a5f04
	if (cr6.eq) goto loc_827A5F04;
	// bl 0x82245990
	ctx.lr = 0x827A5EF8;
	sub_82245990(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a60a8
	if (!cr6.eq) goto loc_827A60A8;
loc_827A5F04:
	// lfs f0,872(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 872);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,876(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 876);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x827a5f1c
	if (cr6.gt) goto loc_827A5F1C;
	// li r11,0
	r11.s64 = 0;
loc_827A5F1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5f30
	if (!cr6.eq) goto loc_827A5F30;
loc_827A5F2C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827A5F30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_827A5F3C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5f4c
	if (!cr6.eq) goto loc_827A5F4C;
	// mr r31,r30
	r31.u64 = r30.u64;
	// b 0x827a5e88
	goto loc_827A5E88;
loc_827A5F4C:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x827a5f2c
	if (!cr6.eq) goto loc_827A5F2C;
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5f78
	if (cr6.eq) goto loc_827A5F78;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5fdc
	if (!cr6.eq) goto loc_827A5FDC;
loc_827A5F78:
	// lfs f0,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x827a5f8c
	if (cr6.eq) goto loc_827A5F8C;
	// li r11,0
	r11.s64 = 0;
loc_827A5F8C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5fac
	if (cr6.eq) goto loc_827A5FAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826e94e8
	ctx.lr = 0x827A5FA0;
	sub_826E94E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a60a8
	if (cr6.eq) goto loc_827A60A8;
loc_827A5FAC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-19948(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19948);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x827a5fdc
	if (!cr6.lt) goto loc_827A5FDC;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827a60a8
	if (!cr6.eq) goto loc_827A60A8;
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a60a8
	if (!cr6.eq) goto loc_827A60A8;
loc_827A5FDC:
	// lwz r11,452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6008
	if (cr6.eq) goto loc_827A6008;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6008
	if (cr6.eq) goto loc_827A6008;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x827a600c
	if (!cr6.eq) goto loc_827A600C;
loc_827A6008:
	// li r11,0
	r11.s64 = 0;
loc_827A600C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5f2c
	if (cr6.eq) goto loc_827A5F2C;
	// lfs f0,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x827a602c
	if (cr6.eq) goto loc_827A602C;
	// li r11,0
	r11.s64 = 0;
loc_827A602C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a5f2c
	if (cr6.eq) goto loc_827A5F2C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826e94e8
	ctx.lr = 0x827A6040;
	sub_826E94E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a5f2c
	if (!cr6.eq) goto loc_827A5F2C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r3,32
	r31.s64 = ctx.r3.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A6078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r3,32
	ctx.r7.s64 = ctx.r3.s64 + 32;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f9,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f12,f8,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bge cr6,0x827a5f2c
	if (!cr6.lt) goto loc_827A5F2C;
loc_827A60A8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827A60B8"))) PPC_WEAK_FUNC(sub_827A60B8);
PPC_FUNC_IMPL(__imp__sub_827A60B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x827A60C0;
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r22,316(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// lwz r21,308(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r19,r7
	r19.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r18,r11,2384
	r18.s64 = r11.s64 + 2384;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a619c
	if (cr6.eq) goto loc_827A619C;
	// li r29,0
	r29.s64 = 0;
loc_827A6110:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A612C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// lvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A6148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v127,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r4,r5,0,24,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x827a6188
	if (!cr6.eq) goto loc_827A6188;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a5cb8
	ctx.lr = 0x827A6188;
	sub_827A5CB8(ctx, base);
loc_827A6188:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x827a6110
	if (cr6.lt) goto loc_827A6110;
loc_827A619C:
	// lhz r11,4(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a61ec
	if (cr6.eq) goto loc_827A61EC;
	// li r31,0
	r31.s64 = 0;
loc_827A61B0:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplw cr6,r3,r27
	cr6.compare<uint32_t>(ctx.r3.u32, r27.u32, xer);
	// beq cr6,0x827a61d8
	if (cr6.eq) goto loc_827A61D8;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x827a5cb8
	ctx.lr = 0x827A61D8;
	sub_827A5CB8(ctx, base);
loc_827A61D8:
	// lhz r11,4(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x827a61b0
	if (cr6.lt) goto loc_827A61B0;
loc_827A61EC:
	// lhz r11,4(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6294
	if (cr6.eq) goto loc_827A6294;
	// li r30,0
	r30.s64 = 0;
loc_827A6200:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplw cr6,r31,r20
	cr6.compare<uint32_t>(r31.u32, r20.u32, xer);
	// beq cr6,0x827a6280
	if (cr6.eq) goto loc_827A6280;
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A6240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v127,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v56,v58,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v55,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827a6280
	if (!cr6.eq) goto loc_827A6280;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a5cb8
	ctx.lr = 0x827A6280;
	sub_827A5CB8(ctx, base);
loc_827A6280:
	// lhz r11,4(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x827a6200
	if (cr6.lt) goto loc_827A6200;
loc_827A6294:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_827A62A4"))) PPC_WEAK_FUNC(sub_827A62A4);
PPC_FUNC_IMPL(__imp__sub_827A62A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A62A8"))) PPC_WEAK_FUNC(sub_827A62A8);
PPC_FUNC_IMPL(__imp__sub_827A62A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x827A62B0;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
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
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827a6434
	if (cr6.eq) goto loc_827A6434;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r27,0
	r27.s64 = 0;
	// addi r21,r11,2384
	r21.s64 = r11.s64 + 2384;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a638c
	if (cr6.eq) goto loc_827A638C;
	// li r29,0
	r29.s64 = 0;
loc_827A6300:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r31,r11,r29
	r31.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A631C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// lvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A6338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v127,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r4,r5,0,24,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x827a6378
	if (!cr6.eq) goto loc_827A6378;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a5cb8
	ctx.lr = 0x827A6378;
	sub_827A5CB8(ctx, base);
loc_827A6378:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x827a6300
	if (cr6.lt) goto loc_827A6300;
loc_827A638C:
	// lhz r11,4(r20)
	r11.u64 = PPC_LOAD_U16(r20.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6434
	if (cr6.eq) goto loc_827A6434;
	// li r30,0
	r30.s64 = 0;
loc_827A63A0:
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x827a6420
	if (cr6.eq) goto loc_827A6420;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A63C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A63E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v127,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v56,v58,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v55,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827a6420
	if (!cr6.eq) goto loc_827A6420;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a5cb8
	ctx.lr = 0x827A6420;
	sub_827A5CB8(ctx, base);
loc_827A6420:
	// lhz r11,4(r20)
	r11.u64 = PPC_LOAD_U16(r20.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x827a63a0
	if (cr6.lt) goto loc_827A63A0;
loc_827A6434:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_827A6444"))) PPC_WEAK_FUNC(sub_827A6444);
PPC_FUNC_IMPL(__imp__sub_827A6444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A6448"))) PPC_WEAK_FUNC(sub_827A6448);
PPC_FUNC_IMPL(__imp__sub_827A6448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x827A6450;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823db9d0
	ctx.lr = 0x827A6458;
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-960(r1)
	ea = -960 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// lwz r11,4(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6558
	if (cr6.eq) goto loc_827A6558;
	// lwz r11,0(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6558
	if (cr6.eq) goto loc_827A6558;
	// lwz r3,4(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r31,r11,2384
	r31.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v62,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v60,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v60.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827a6558
	if (cr6.eq) goto loc_827A6558;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A64D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v59,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v57,v58,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v57.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827a6558
	if (cr6.eq) goto loc_827A6558;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2192
	ctx.r7.s64 = ctx.r9.s64 + 2192;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r3,2192(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r3,r6
	ctx.r10.s64 = ctx.r3.s64 * ctx.r6.s64;
	// lfs f0,14348(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lfs f13,-3072(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3072);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x827a6bf4
	if (cr6.gt) goto loc_827A6BF4;
loc_827A6558:
	// li r19,0
	r19.s64 = 0;
	// mr r30,r19
	r30.u64 = r19.u64;
	// stw r19,0(r18)
	PPC_STORE_U32(r18.u32 + 0, r19.u32);
	// stw r19,4(r18)
	PPC_STORE_U32(r18.u32 + 4, r19.u32);
	// lwz r11,12(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// beq cr6,0x827a659c
	if (cr6.eq) goto loc_827A659C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// mr r11,r19
	r11.u64 = r19.u64;
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
	// beq cr6,0x827a65a0
	if (cr6.eq) goto loc_827A65A0;
loc_827A659C:
	// li r11,1
	r11.s64 = 1;
loc_827A65A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6658
	if (cr6.eq) goto loc_827A6658;
	// lwz r3,4(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A65C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// addi r29,r1,192
	r29.s64 = ctx.r1.s64 + 192;
	// lwz r31,-3660(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3660);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226ad80
	ctx.lr = 0x827A65D8;
	sub_8226AD80(ctx, base);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8226a808
	ctx.lr = 0x827A65E8;
	sub_8226A808(ctx, base);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// li r7,9
	ctx.r7.s64 = 9;
loc_827A65F0:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6648
	if (cr6.eq) goto loc_827A6648;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_827A6608:
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// beq cr6,0x827a661c
	if (cr6.eq) goto loc_827A661C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827a663c
	if (!cr6.eq) goto loc_827A663C;
loc_827A661C:
	// lwz r10,4(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x827a663c
	if (cr6.eq) goto loc_827A663C;
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// bge cr6,0x827a663c
	if (!cr6.lt) goto loc_827A663C;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
loc_827A663C:
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a6608
	if (!cr6.eq) goto loc_827A6608;
loc_827A6648:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x827a65f0
	if (!cr0.eq) goto loc_827A65F0;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
loc_827A6658:
	// lwz r8,12(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827a6678
	if (cr6.eq) goto loc_827A6678;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827a667c
	if (cr6.eq) goto loc_827A667C;
loc_827A6678:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_827A667C:
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lwz r11,16(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a66a0
	if (cr6.eq) goto loc_827A66A0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827a66a4
	if (cr6.eq) goto loc_827A66A4;
loc_827A66A0:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_827A66A4:
	// lwz r10,20(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 20);
	// clrlwi r25,r11,24
	r25.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a66c8
	if (cr6.eq) goto loc_827A66C8;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r7,r11,0,19,20
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x827a66cc
	if (cr6.eq) goto loc_827A66CC;
loc_827A66C8:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_827A66CC:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// mr r29,r19
	r29.u64 = r19.u64;
	// mr r30,r19
	r30.u64 = r19.u64;
	// mr r26,r19
	r26.u64 = r19.u64;
	// mr r27,r19
	r27.u64 = r19.u64;
	// mr r31,r19
	r31.u64 = r19.u64;
	// mr r28,r19
	r28.u64 = r19.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a66f8
	if (cr6.eq) goto loc_827A66F8;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// b 0x827a6708
	goto loc_827A6708;
loc_827A66F8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6750
	if (cr6.eq) goto loc_827A6750;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
loc_827A6708:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A671C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lhz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// rotlwi r10,r3,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 3);
	// lwz r11,56(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// lhzx r9,r4,r7
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r7.u32);
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// rotlwi r10,r9,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
loc_827A6750:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a67a8
	if (cr6.eq) goto loc_827A67A8;
	// lwz r28,16(r20)
	r28.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lhz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// rotlwi r10,r3,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 3);
	// lwz r11,56(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// lhzx r9,r4,r7
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r7.u32);
	// add r26,r10,r11
	r26.u64 = ctx.r10.u64 + r11.u64;
	// rotlwi r10,r9,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
loc_827A67A8:
	// lwz r25,4(r20)
	r25.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827a67f0
	if (cr6.eq) goto loc_827A67F0;
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bne cr6,0x827a67f0
	if (!cr6.eq) goto loc_827A67F0;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r8,r1,496
	ctx.r8.s64 = ctx.r1.s64 + 496;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a60b8
	ctx.lr = 0x827A67EC;
	sub_827A60B8(ctx, base);
	// b 0x827a6838
	goto loc_827A6838;
loc_827A67F0:
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,496
	ctx.r6.s64 = ctx.r1.s64 + 496;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a62a8
	ctx.lr = 0x827A6814;
	sub_827A62A8(ctx, base);
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,496
	ctx.r6.s64 = ctx.r1.s64 + 496;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827a62a8
	ctx.lr = 0x827A6838;
	sub_827A62A8(ctx, base);
loc_827A6838:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r22,r19
	r22.u64 = r19.u64;
	// mr r23,r19
	r23.u64 = r19.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lfs f0,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f0.f64 = double(temp.f32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// fmr f27,f0
	f27.f64 = f0.f64;
	// fmr f28,f0
	f28.f64 = f0.f64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A6868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827a6bf4
	if (!cr6.gt) goto loc_827A6BF4;
	// mr r21,r11
	r21.u64 = r11.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r24,r1,240
	r24.s64 = ctx.r1.s64 + 240;
	// lfs f29,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f26,-26208(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26208);
	f26.f64 = double(temp.f32);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
loc_827A6894:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A68A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A68C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r3,48
	ctx.r6.s64 = ctx.r3.s64 + 48;
	// lwz r5,0(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v56,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v127.f32)));
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stvx128 v55,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827A68F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fnmadds f31,f12,f8,f7
	f31.f64 = double(float(-(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64)));
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x827a6be8
	if (cr6.lt) goto loc_827A6BE8;
	// mr r31,r19
	r31.u64 = r19.u64;
	// fcmpu cr6,f31,f27
	cr6.compare(f31.f64, f27.f64);
	// mr r26,r19
	r26.u64 = r19.u64;
	// bge cr6,0x827a6938
	if (!cr6.lt) goto loc_827A6938;
	// li r31,1
	r31.s64 = 1;
	// mr r22,r30
	r22.u64 = r30.u64;
loc_827A6938:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// bge cr6,0x827a6960
	if (!cr6.lt) goto loc_827A6960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// bl 0x827a5e28
	ctx.lr = 0x827A694C;
	sub_827A5E28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6960
	if (cr6.eq) goto loc_827A6960;
	// li r26,1
	r26.s64 = 1;
	// mr r23,r30
	r23.u64 = r30.u64;
loc_827A6960:
	// clrlwi r27,r31,24
	r27.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x827a6978
	if (!cr6.eq) goto loc_827A6978;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6be8
	if (cr6.eq) goto loc_827A6BE8;
loc_827A6978:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A698C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A69A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,6(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// mr r28,r19
	r28.u64 = r19.u64;
	// mr r29,r19
	r29.u64 = r19.u64;
	// cmplwi cr6,r7,2
	cr6.compare<uint32_t>(ctx.r7.u32, 2, xer);
	// bne cr6,0x827a6aa0
	if (!cr6.eq) goto loc_827A6AA0;
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a6aa0
	if (cr6.eq) goto loc_827A6AA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826e9870
	ctx.lr = 0x827A69C8;
	sub_826E9870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6aa0
	if (cr6.eq) goto loc_827A6AA0;
	// lwz r10,452(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a6aa0
	if (cr6.eq) goto loc_827A6AA0;
	// lwz r11,188(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6a04
	if (cr6.eq) goto loc_827A6A04;
	// lwz r9,12(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 12);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x827a6a9c
	if (cr6.eq) goto loc_827A6A9C;
	// lwz r9,16(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x827a6a9c
	if (cr6.eq) goto loc_827A6A9C;
loc_827A6A04:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a6aa0
	if (cr6.eq) goto loc_827A6AA0;
	// lwz r11,192(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6aa0
	if (cr6.eq) goto loc_827A6AA0;
	// lwz r10,16(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x827a6aa0
	if (!cr6.eq) goto loc_827A6AA0;
	// lfs f0,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x827a6a38
	if (cr6.eq) goto loc_827A6A38;
	// mr r11,r19
	r11.u64 = r19.u64;
loc_827A6A38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a6aa0
	if (!cr6.eq) goto loc_827A6AA0;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A6A74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f26
	cr6.compare(ctx.f7.f64, f26.f64);
	// bge cr6,0x827a6aa0
	if (!cr6.lt) goto loc_827A6AA0;
loc_827A6A9C:
	// li r29,1
	r29.s64 = 1;
loc_827A6AA0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a6bb8
	if (!cr6.eq) goto loc_827A6BB8;
	// lwz r31,12(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a6bb8
	if (cr6.eq) goto loc_827A6BB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r17,r1,104
	r17.s64 = ctx.r1.s64 + 104;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r16,r1,96
	r16.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6AD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// lwz r9,56(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A6AF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x827a6b18
	if (!cr6.gt) goto loc_827A6B18;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// blt cr6,0x827a6b94
	if (cr6.lt) goto loc_827A6B94;
loc_827A6B18:
	// lwz r31,16(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827a6b90
	if (cr6.eq) goto loc_827A6B90;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r17,r1,104
	r17.s64 = ctx.r1.s64 + 104;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r16,r1,96
	r16.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6B44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// lwz r9,56(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A6B64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// stvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x827a6b90
	if (!cr6.gt) goto loc_827A6B90;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x827a6b90
	if (!cr6.lt) goto loc_827A6B90;
	// lfs f13,32(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x827a6b94
	if (!cr6.lt) goto loc_827A6B94;
loc_827A6B90:
	// li r28,1
	r28.s64 = 1;
loc_827A6B94:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827a6bb8
	if (!cr6.eq) goto loc_827A6BB8;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x827a59a8
	ctx.lr = 0x827A6BB4;
	sub_827A59A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_827A6BB8:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x827a6be8
	if (cr6.eq) goto loc_827A6BE8;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x827a6bd4
	if (cr6.eq) goto loc_827A6BD4;
	// stw r22,0(r18)
	PPC_STORE_U32(r18.u32 + 0, r22.u32);
	// fmr f27,f31
	ctx.fpscr.disableFlushMode();
	f27.f64 = f31.f64;
loc_827A6BD4:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6be8
	if (cr6.eq) goto loc_827A6BE8;
	// stw r23,4(r18)
	PPC_STORE_U32(r18.u32 + 4, r23.u32);
	// fmr f28,f31
	ctx.fpscr.disableFlushMode();
	f28.f64 = f31.f64;
loc_827A6BE8:
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// bne 0x827a6894
	if (!cr0.eq) goto loc_827A6894;
loc_827A6BF4:
	// addi r1,r1,960
	ctx.r1.s64 = ctx.r1.s64 + 960;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823dba1c
	ctx.lr = 0x827A6C08;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_827A6C0C"))) PPC_WEAK_FUNC(sub_827A6C0C);
PPC_FUNC_IMPL(__imp__sub_827A6C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A6C10"))) PPC_WEAK_FUNC(sub_827A6C10);
PPC_FUNC_IMPL(__imp__sub_827A6C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-18444
	ctx.r8.s64 = ctx.r10.s64 + -18444;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A6C34"))) PPC_WEAK_FUNC(sub_827A6C34);
PPC_FUNC_IMPL(__imp__sub_827A6C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A6C38"))) PPC_WEAK_FUNC(sub_827A6C38);
PPC_FUNC_IMPL(__imp__sub_827A6C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r10,r11,-18444
	ctx.r10.s64 = r11.s64 + -18444;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A6C48"))) PPC_WEAK_FUNC(sub_827A6C48);
PPC_FUNC_IMPL(__imp__sub_827A6C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827A6C64"))) PPC_WEAK_FUNC(sub_827A6C64);
PPC_FUNC_IMPL(__imp__sub_827A6C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A6C68"))) PPC_WEAK_FUNC(sub_827A6C68);
PPC_FUNC_IMPL(__imp__sub_827A6C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827A6C78"))) PPC_WEAK_FUNC(sub_827A6C78);
PPC_FUNC_IMPL(__imp__sub_827A6C78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827A6C94"))) PPC_WEAK_FUNC(sub_827A6C94);
PPC_FUNC_IMPL(__imp__sub_827A6C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A6C98"))) PPC_WEAK_FUNC(sub_827A6C98);
PPC_FUNC_IMPL(__imp__sub_827A6C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827A6CB4"))) PPC_WEAK_FUNC(sub_827A6CB4);
PPC_FUNC_IMPL(__imp__sub_827A6CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A6CB8"))) PPC_WEAK_FUNC(sub_827A6CB8);
PPC_FUNC_IMPL(__imp__sub_827A6CB8) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x827a6cec
	if (!cr6.eq) goto loc_827A6CEC;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x827a6d40
	goto loc_827A6D40;
loc_827A6CEC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6D04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a6d38
	if (cr6.eq) goto loc_827A6D38;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6D28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827a6d3c
	if (!cr6.eq) goto loc_827A6D3C;
loc_827A6D38:
	// li r11,0
	r11.s64 = 0;
loc_827A6D3C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
loc_827A6D40:
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

__attribute__((alias("__imp__sub_827A6D58"))) PPC_WEAK_FUNC(sub_827A6D58);
PPC_FUNC_IMPL(__imp__sub_827A6D58) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6D84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a6db0
	if (cr6.eq) goto loc_827A6DB0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A6DAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827a6db8
	goto loc_827A6DB8;
loc_827A6DB0:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-6920
	ctx.r3.s64 = r11.s64 + -6920;
loc_827A6DB8:
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

__attribute__((alias("__imp__sub_827A6DD0"))) PPC_WEAK_FUNC(sub_827A6DD0);
PPC_FUNC_IMPL(__imp__sub_827A6DD0) {
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
	// lis r11,-32242
	r11.s64 = -2113011712;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-18444
	ctx.r9.s64 = r11.s64 + -18444;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x827a6e04
	if (cr6.eq) goto loc_827A6E04;
	// bl 0x82130588
	ctx.lr = 0x827A6E00;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827A6E04:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827A6E18"))) PPC_WEAK_FUNC(sub_827A6E18);
PPC_FUNC_IMPL(__imp__sub_827A6E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A6E68"))) PPC_WEAK_FUNC(sub_827A6E68);
PPC_FUNC_IMPL(__imp__sub_827A6E68) {
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
	ctx.lr = 0x827A6E70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6E8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a6ea4
	if (cr6.eq) goto loc_827A6EA4;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827A6EA4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r29,12(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a6d58
	ctx.lr = 0x827A6EB4;
	sub_827A6D58(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827a6d58
	ctx.lr = 0x827A6EC4;
	sub_827A6D58(ctx, base);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-18360
	ctx.r3.s64 = r11.s64 + -18360;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x821bd618
	ctx.lr = 0x827A6EE0;
	sub_821BD618(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A6EE8"))) PPC_WEAK_FUNC(sub_827A6EE8);
PPC_FUNC_IMPL(__imp__sub_827A6EE8) {
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
	ctx.lr = 0x827A6EF0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a6f3c
	if (cr6.eq) goto loc_827A6F3C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827A6F3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827A6F3C:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a6f7c
	if (cr6.eq) goto loc_827A6F7C;
	// li r30,0
	r30.s64 = 0;
loc_827A6F50:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A6F68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x827a6f50
	if (cr6.lt) goto loc_827A6F50;
loc_827A6F7C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A6F90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827A6F98"))) PPC_WEAK_FUNC(sub_827A6F98);
PPC_FUNC_IMPL(__imp__sub_827A6F98) {
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
	ctx.lr = 0x827A6FA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A6FC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827a7008
	if (cr6.eq) goto loc_827A7008;
	// li r29,0
	r29.s64 = 0;
loc_827A6FDC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A6FF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x827a6fdc
	if (cr6.lt) goto loc_827A6FDC;
loc_827A7008:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a704c
	if (cr6.eq) goto loc_827A704C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A7038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,52(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A704C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827A704C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A7054"))) PPC_WEAK_FUNC(sub_827A7054);
PPC_FUNC_IMPL(__imp__sub_827A7054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7058"))) PPC_WEAK_FUNC(sub_827A7058);
PPC_FUNC_IMPL(__imp__sub_827A7058) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827a712c
	if (cr6.eq) goto loc_827A712C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A7090;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A70A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827A70CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A70F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r3,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A7114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A712C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827A712C:
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

__attribute__((alias("__imp__sub_827A7144"))) PPC_WEAK_FUNC(sub_827A7144);
PPC_FUNC_IMPL(__imp__sub_827A7144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7148"))) PPC_WEAK_FUNC(sub_827A7148);
PPC_FUNC_IMPL(__imp__sub_827A7148) {
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
	ctx.lr = 0x827A7150;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A7170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a7218
	if (cr6.eq) goto loc_827A7218;
	// li r29,-1
	r29.s64 = -1;
loc_827A7180:
	// cmpwi cr6,r30,20
	cr6.compare<int32_t>(r30.s32, 20, xer);
	// bge cr6,0x827a7218
	if (!cr6.lt) goto loc_827A7218;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A719C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r8,r28,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,32(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A71C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// rotlwi r11,r5,0
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A71F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827A720C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827a7180
	if (!cr6.eq) goto loc_827A7180;
loc_827A7218:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A7220"))) PPC_WEAK_FUNC(sub_827A7220);
PPC_FUNC_IMPL(__imp__sub_827A7220) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-18276
	ctx.r9.s64 = ctx.r10.s64 + -18276;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A724C"))) PPC_WEAK_FUNC(sub_827A724C);
PPC_FUNC_IMPL(__imp__sub_827A724C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7250"))) PPC_WEAK_FUNC(sub_827A7250);
PPC_FUNC_IMPL(__imp__sub_827A7250) {
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
	ctx.lr = 0x827A7258;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a72b0
	if (cr6.eq) goto loc_827A72B0;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_827A7278:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827a729c
	if (cr6.eq) goto loc_827A729C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A729C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827A729C:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x827a7278
	if (cr6.lt) goto loc_827A7278;
loc_827A72B0:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x827A72B8;
	sub_82130588(ctx, base);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// sth r28,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r28.u16);
	// sth r28,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A72CC"))) PPC_WEAK_FUNC(sub_827A72CC);
PPC_FUNC_IMPL(__imp__sub_827A72CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A72D0"))) PPC_WEAK_FUNC(sub_827A72D0);
PPC_FUNC_IMPL(__imp__sub_827A72D0) {
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
	// lis r11,-32242
	r11.s64 = -2113011712;
	// addi r9,r11,-18276
	ctx.r9.s64 = r11.s64 + -18276;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a7300
	if (cr6.eq) goto loc_827A7300;
	// bl 0x827a7250
	ctx.lr = 0x827A7300;
	sub_827A7250(ctx, base);
loc_827A7300:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a7314
	if (cr6.eq) goto loc_827A7314;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x827A7314;
	sub_82130588(ctx, base);
loc_827A7314:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827A7328"))) PPC_WEAK_FUNC(sub_827A7328);
PPC_FUNC_IMPL(__imp__sub_827A7328) {
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
	ctx.lr = 0x827A7330;
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
	// bl 0x827a7250
	ctx.lr = 0x827A7344;
	sub_827A7250(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A7368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827a73b0
	if (cr6.eq) goto loc_827A73B0;
	// li r29,0
	r29.s64 = 0;
loc_827A737C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827A739C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x827a737c
	if (cr6.lt) goto loc_827A737C;
loc_827A73B0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827A73C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827A73D0"))) PPC_WEAK_FUNC(sub_827A73D0);
PPC_FUNC_IMPL(__imp__sub_827A73D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x827a7250
	sub_827A7250(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A73D4"))) PPC_WEAK_FUNC(sub_827A73D4);
PPC_FUNC_IMPL(__imp__sub_827A73D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A73D8"))) PPC_WEAK_FUNC(sub_827A73D8);
PPC_FUNC_IMPL(__imp__sub_827A73D8) {
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
	// lis r11,-32242
	r11.s64 = -2113011712;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-18276
	ctx.r9.s64 = r11.s64 + -18276;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a7410
	if (cr6.eq) goto loc_827A7410;
	// bl 0x827a7250
	ctx.lr = 0x827A7410;
	sub_827A7250(ctx, base);
loc_827A7410:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a7424
	if (cr6.eq) goto loc_827A7424;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x827A7424;
	sub_82130588(ctx, base);
loc_827A7424:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a743c
	if (cr6.eq) goto loc_827A743C;
	// bl 0x82130588
	ctx.lr = 0x827A7438;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827A743C:
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

__attribute__((alias("__imp__sub_827A7454"))) PPC_WEAK_FUNC(sub_827A7454);
PPC_FUNC_IMPL(__imp__sub_827A7454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7458"))) PPC_WEAK_FUNC(sub_827A7458);
PPC_FUNC_IMPL(__imp__sub_827A7458) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,10056(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 10056);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827A7468;
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r27,0
	r27.s64 = 0;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stw r27,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r27.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827a74d8
	if (!cr6.eq) goto loc_827A74D8;
loc_827A74AC:
	// bl 0x823e1000
	ctx.lr = 0x827A74B0;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x827A74D0;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x827a7650
	goto loc_827A7650;
loc_827A74D8:
	// cntlzw r11,r26
	r11.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827a74ac
	if (cr6.eq) goto loc_827A74AC;
	// addi r11,r31,84
	r11.s64 = r31.s64 + 84;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// addi r10,r31,192
	ctx.r10.s64 = r31.s64 + 192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x823e12d0
	ctx.lr = 0x827A7504;
	sub_823E12D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827a7608
	if (!cr0.eq) goto loc_827A7608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A751C;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x827a756c
	if (cr6.eq) goto loc_827A756C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A752C;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x827a756c
	if (cr6.eq) goto loc_827A756C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A753C;
	sub_823E3DE0(ctx, base);
	// srawi r10,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r28,r10,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// bl 0x823e3de0
	ctx.lr = 0x827A7554;
	sub_823E3DE0(ctx, base);
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r28,r9,-17448
	r28.s64 = ctx.r9.s64 + -17448;
	// b 0x827a7580
	goto loc_827A7580;
loc_827A756C:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r28,r10,-17448
	r28.s64 = ctx.r10.s64 + -17448;
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_827A7580:
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827a75dc
	if (!cr0.eq) goto loc_827A75DC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A7594;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x827a75d0
	if (cr6.eq) goto loc_827A75D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A75A4;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x827a75d0
	if (cr6.eq) goto loc_827A75D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A75B4;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x827A75C4;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
loc_827A75D0:
	// lbz r11,40(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 40);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x827a7608
	if (cr0.eq) goto loc_827A7608;
loc_827A75DC:
	// bl 0x823e1000
	ctx.lr = 0x827A75E0;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x827A7600;
	sub_823E02A8(ctx, base);
	// li r27,-1
	r27.s64 = -1;
	// stw r27,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r27.u32);
loc_827A7608:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x827a7640
	if (!cr6.eq) goto loc_827A7640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e13f8
	ctx.lr = 0x827A7618;
	sub_823E13F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,84(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e1668
	ctx.lr = 0x827A7630;
	sub_823E1668(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e14d0
	ctx.lr = 0x827A7640;
	sub_823E14D0(ctx, base);
loc_827A7640:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x827a7658
	ctx.lr = 0x827A764C;
	sub_827A7658(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_827A7650:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A7460"))) PPC_WEAK_FUNC(sub_827A7460);
PPC_FUNC_IMPL(__imp__sub_827A7460) {
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
	ctx.lr = 0x827A7468;
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r27,0
	r27.s64 = 0;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stw r27,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r27.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827a74d8
	if (!cr6.eq) goto loc_827A74D8;
loc_827A74AC:
	// bl 0x823e1000
	ctx.lr = 0x827A74B0;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x827A74D0;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x827a7650
	goto loc_827A7650;
loc_827A74D8:
	// cntlzw r11,r26
	r11.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827a74ac
	if (cr6.eq) goto loc_827A74AC;
	// addi r11,r31,84
	r11.s64 = r31.s64 + 84;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// addi r10,r31,192
	ctx.r10.s64 = r31.s64 + 192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x823e12d0
	ctx.lr = 0x827A7504;
	sub_823E12D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827a7608
	if (!cr0.eq) goto loc_827A7608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A751C;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x827a756c
	if (cr6.eq) goto loc_827A756C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A752C;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x827a756c
	if (cr6.eq) goto loc_827A756C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A753C;
	sub_823E3DE0(ctx, base);
	// srawi r10,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r28,r10,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// bl 0x823e3de0
	ctx.lr = 0x827A7554;
	sub_823E3DE0(ctx, base);
	// lwzx r11,r28,r29
	r11.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r28,r9,-17448
	r28.s64 = ctx.r9.s64 + -17448;
	// b 0x827a7580
	goto loc_827A7580;
loc_827A756C:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r28,r10,-17448
	r28.s64 = ctx.r10.s64 + -17448;
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_827A7580:
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x827a75dc
	if (!cr0.eq) goto loc_827A75DC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A7594;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x827a75d0
	if (cr6.eq) goto loc_827A75D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A75A4;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x827a75d0
	if (cr6.eq) goto loc_827A75D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x827A75B4;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x827A75C4;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
loc_827A75D0:
	// lbz r11,40(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 40);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x827a7608
	if (cr0.eq) goto loc_827A7608;
loc_827A75DC:
	// bl 0x823e1000
	ctx.lr = 0x827A75E0;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x827A7600;
	sub_823E02A8(ctx, base);
	// li r27,-1
	r27.s64 = -1;
	// stw r27,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r27.u32);
loc_827A7608:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x827a7640
	if (!cr6.eq) goto loc_827A7640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e13f8
	ctx.lr = 0x827A7618;
	sub_823E13F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,84(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e1668
	ctx.lr = 0x827A7630;
	sub_823E1668(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e14d0
	ctx.lr = 0x827A7640;
	sub_823E14D0(ctx, base);
loc_827A7640:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x827a7658
	ctx.lr = 0x827A764C;
	sub_827A7658(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_827A7650:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827A7658"))) PPC_WEAK_FUNC(sub_827A7658);
PPC_FUNC_IMPL(__imp__sub_827A7658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x823e1390
	ctx.lr = 0x827A7674;
	sub_823E1390(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// lwz r12,-16(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A7688"))) PPC_WEAK_FUNC(sub_827A7688);
PPC_FUNC_IMPL(__imp__sub_827A7688) {
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
	// bl 0x82131228
	ctx.lr = 0x827A7698;
	sub_82131228(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827A76B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32132
	ctx.r7.s64 = -2105802752;
	// addi r3,r7,-30976
	ctx.r3.s64 = ctx.r7.s64 + -30976;
	// bl 0x823d9a98
	ctx.lr = 0x827A76C0;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A76D0"))) PPC_WEAK_FUNC(sub_827A76D0);
PPC_FUNC_IMPL(__imp__sub_827A76D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4108
	ctx.r5.s64 = r11.s64 + 4108;
	// addi r3,r10,2492
	ctx.r3.s64 = ctx.r10.s64 + 2492;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A76EC"))) PPC_WEAK_FUNC(sub_827A76EC);
PPC_FUNC_IMPL(__imp__sub_827A76EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A76F0"))) PPC_WEAK_FUNC(sub_827A76F0);
PPC_FUNC_IMPL(__imp__sub_827A76F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4124
	ctx.r5.s64 = r11.s64 + 4124;
	// addi r3,r10,2592
	ctx.r3.s64 = ctx.r10.s64 + 2592;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A770C"))) PPC_WEAK_FUNC(sub_827A770C);
PPC_FUNC_IMPL(__imp__sub_827A770C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7710"))) PPC_WEAK_FUNC(sub_827A7710);
PPC_FUNC_IMPL(__imp__sub_827A7710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4144
	ctx.r5.s64 = r11.s64 + 4144;
	// addi r3,r10,2632
	ctx.r3.s64 = ctx.r10.s64 + 2632;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A772C"))) PPC_WEAK_FUNC(sub_827A772C);
PPC_FUNC_IMPL(__imp__sub_827A772C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7730"))) PPC_WEAK_FUNC(sub_827A7730);
PPC_FUNC_IMPL(__imp__sub_827A7730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4156
	ctx.r5.s64 = r11.s64 + 4156;
	// addi r3,r10,2652
	ctx.r3.s64 = ctx.r10.s64 + 2652;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A774C"))) PPC_WEAK_FUNC(sub_827A774C);
PPC_FUNC_IMPL(__imp__sub_827A774C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7750"))) PPC_WEAK_FUNC(sub_827A7750);
PPC_FUNC_IMPL(__imp__sub_827A7750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4164
	ctx.r5.s64 = r11.s64 + 4164;
	// addi r3,r10,2532
	ctx.r3.s64 = ctx.r10.s64 + 2532;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A776C"))) PPC_WEAK_FUNC(sub_827A776C);
PPC_FUNC_IMPL(__imp__sub_827A776C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7770"))) PPC_WEAK_FUNC(sub_827A7770);
PPC_FUNC_IMPL(__imp__sub_827A7770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4172
	ctx.r5.s64 = r11.s64 + 4172;
	// addi r3,r10,2784
	ctx.r3.s64 = ctx.r10.s64 + 2784;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A778C"))) PPC_WEAK_FUNC(sub_827A778C);
PPC_FUNC_IMPL(__imp__sub_827A778C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7790"))) PPC_WEAK_FUNC(sub_827A7790);
PPC_FUNC_IMPL(__imp__sub_827A7790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4188
	ctx.r5.s64 = r11.s64 + 4188;
	// addi r3,r10,2512
	ctx.r3.s64 = ctx.r10.s64 + 2512;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A77AC"))) PPC_WEAK_FUNC(sub_827A77AC);
PPC_FUNC_IMPL(__imp__sub_827A77AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A77B0"))) PPC_WEAK_FUNC(sub_827A77B0);
PPC_FUNC_IMPL(__imp__sub_827A77B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4196
	ctx.r5.s64 = r11.s64 + 4196;
	// addi r3,r10,2712
	ctx.r3.s64 = ctx.r10.s64 + 2712;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A77CC"))) PPC_WEAK_FUNC(sub_827A77CC);
PPC_FUNC_IMPL(__imp__sub_827A77CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A77D0"))) PPC_WEAK_FUNC(sub_827A77D0);
PPC_FUNC_IMPL(__imp__sub_827A77D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4204
	ctx.r5.s64 = r11.s64 + 4204;
	// addi r3,r10,2692
	ctx.r3.s64 = ctx.r10.s64 + 2692;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A77EC"))) PPC_WEAK_FUNC(sub_827A77EC);
PPC_FUNC_IMPL(__imp__sub_827A77EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A77F0"))) PPC_WEAK_FUNC(sub_827A77F0);
PPC_FUNC_IMPL(__imp__sub_827A77F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4216
	ctx.r5.s64 = r11.s64 + 4216;
	// addi r3,r10,2612
	ctx.r3.s64 = ctx.r10.s64 + 2612;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A780C"))) PPC_WEAK_FUNC(sub_827A780C);
PPC_FUNC_IMPL(__imp__sub_827A780C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7810"))) PPC_WEAK_FUNC(sub_827A7810);
PPC_FUNC_IMPL(__imp__sub_827A7810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4232
	ctx.r5.s64 = r11.s64 + 4232;
	// addi r3,r10,2672
	ctx.r3.s64 = ctx.r10.s64 + 2672;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A782C"))) PPC_WEAK_FUNC(sub_827A782C);
PPC_FUNC_IMPL(__imp__sub_827A782C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7830"))) PPC_WEAK_FUNC(sub_827A7830);
PPC_FUNC_IMPL(__imp__sub_827A7830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4248
	ctx.r5.s64 = r11.s64 + 4248;
	// addi r3,r10,2552
	ctx.r3.s64 = ctx.r10.s64 + 2552;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A784C"))) PPC_WEAK_FUNC(sub_827A784C);
PPC_FUNC_IMPL(__imp__sub_827A784C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7850"))) PPC_WEAK_FUNC(sub_827A7850);
PPC_FUNC_IMPL(__imp__sub_827A7850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4260
	ctx.r5.s64 = r11.s64 + 4260;
	// addi r3,r10,2764
	ctx.r3.s64 = ctx.r10.s64 + 2764;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A786C"))) PPC_WEAK_FUNC(sub_827A786C);
PPC_FUNC_IMPL(__imp__sub_827A786C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7870"))) PPC_WEAK_FUNC(sub_827A7870);
PPC_FUNC_IMPL(__imp__sub_827A7870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4276
	ctx.r5.s64 = r11.s64 + 4276;
	// addi r3,r10,2744
	ctx.r3.s64 = ctx.r10.s64 + 2744;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A788C"))) PPC_WEAK_FUNC(sub_827A788C);
PPC_FUNC_IMPL(__imp__sub_827A788C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7890"))) PPC_WEAK_FUNC(sub_827A7890);
PPC_FUNC_IMPL(__imp__sub_827A7890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4292
	ctx.r5.s64 = r11.s64 + 4292;
	// addi r3,r10,2804
	ctx.r3.s64 = ctx.r10.s64 + 2804;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A78AC"))) PPC_WEAK_FUNC(sub_827A78AC);
PPC_FUNC_IMPL(__imp__sub_827A78AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A78B0"))) PPC_WEAK_FUNC(sub_827A78B0);
PPC_FUNC_IMPL(__imp__sub_827A78B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,4304
	ctx.r5.s64 = r11.s64 + 4304;
	// addi r3,r10,2572
	ctx.r3.s64 = ctx.r10.s64 + 2572;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A78CC"))) PPC_WEAK_FUNC(sub_827A78CC);
PPC_FUNC_IMPL(__imp__sub_827A78CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A78D0"))) PPC_WEAK_FUNC(sub_827A78D0);
PPC_FUNC_IMPL(__imp__sub_827A78D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_827A78D0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a78d0
	if (cr6.eq) goto loc_827A78D0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// std r11,2736(r10)
	PPC_STORE_U64(ctx.r10.u32 + 2736, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A78EC"))) PPC_WEAK_FUNC(sub_827A78EC);
PPC_FUNC_IMPL(__imp__sub_827A78EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A78F0"))) PPC_WEAK_FUNC(sub_827A78F0);
PPC_FUNC_IMPL(__imp__sub_827A78F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,5584(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 5584);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f0,5672(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 5672, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A7910"))) PPC_WEAK_FUNC(sub_827A7910);
PPC_FUNC_IMPL(__imp__sub_827A7910) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82130000
	ctx.lr = 0x827A7928;
	sub_82130000(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30936
	ctx.r3.s64 = ctx.r10.s64 + -30936;
	// bl 0x823d9a98
	ctx.lr = 0x827A7934;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A7944"))) PPC_WEAK_FUNC(sub_827A7944);
PPC_FUNC_IMPL(__imp__sub_827A7944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7948"))) PPC_WEAK_FUNC(sub_827A7948);
PPC_FUNC_IMPL(__imp__sub_827A7948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,7448
	ctx.r5.s64 = r11.s64 + 7448;
	// addi r3,r10,5676
	ctx.r3.s64 = ctx.r10.s64 + 5676;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7964"))) PPC_WEAK_FUNC(sub_827A7964);
PPC_FUNC_IMPL(__imp__sub_827A7964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7968"))) PPC_WEAK_FUNC(sub_827A7968);
PPC_FUNC_IMPL(__imp__sub_827A7968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30920
	ctx.r3.s64 = r11.s64 + -30920;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7974"))) PPC_WEAK_FUNC(sub_827A7974);
PPC_FUNC_IMPL(__imp__sub_827A7974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7978"))) PPC_WEAK_FUNC(sub_827A7978);
PPC_FUNC_IMPL(__imp__sub_827A7978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,8364
	ctx.r5.s64 = r11.s64 + 8364;
	// addi r3,r10,5712
	ctx.r3.s64 = ctx.r10.s64 + 5712;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7994"))) PPC_WEAK_FUNC(sub_827A7994);
PPC_FUNC_IMPL(__imp__sub_827A7994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7998"))) PPC_WEAK_FUNC(sub_827A7998);
PPC_FUNC_IMPL(__imp__sub_827A7998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,8376
	ctx.r5.s64 = r11.s64 + 8376;
	// addi r3,r10,5732
	ctx.r3.s64 = ctx.r10.s64 + 5732;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A79B4"))) PPC_WEAK_FUNC(sub_827A79B4);
PPC_FUNC_IMPL(__imp__sub_827A79B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A79B8"))) PPC_WEAK_FUNC(sub_827A79B8);
PPC_FUNC_IMPL(__imp__sub_827A79B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,9940
	ctx.r5.s64 = r11.s64 + 9940;
	// addi r3,r10,5956
	ctx.r3.s64 = ctx.r10.s64 + 5956;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A79D4"))) PPC_WEAK_FUNC(sub_827A79D4);
PPC_FUNC_IMPL(__imp__sub_827A79D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A79D8"))) PPC_WEAK_FUNC(sub_827A79D8);
PPC_FUNC_IMPL(__imp__sub_827A79D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,9956
	ctx.r5.s64 = r11.s64 + 9956;
	// addi r3,r10,5860
	ctx.r3.s64 = ctx.r10.s64 + 5860;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A79F4"))) PPC_WEAK_FUNC(sub_827A79F4);
PPC_FUNC_IMPL(__imp__sub_827A79F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A79F8"))) PPC_WEAK_FUNC(sub_827A79F8);
PPC_FUNC_IMPL(__imp__sub_827A79F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30856
	ctx.r3.s64 = r11.s64 + -30856;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7A04"))) PPC_WEAK_FUNC(sub_827A7A04);
PPC_FUNC_IMPL(__imp__sub_827A7A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7A08"))) PPC_WEAK_FUNC(sub_827A7A08);
PPC_FUNC_IMPL(__imp__sub_827A7A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30872
	ctx.r3.s64 = r11.s64 + -30872;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7A14"))) PPC_WEAK_FUNC(sub_827A7A14);
PPC_FUNC_IMPL(__imp__sub_827A7A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7A18"))) PPC_WEAK_FUNC(sub_827A7A18);
PPC_FUNC_IMPL(__imp__sub_827A7A18) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5924
	ctx.r3.s64 = r11.s64 + 5924;
	// bl 0x821c8ed8
	ctx.lr = 0x827A7A30;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30904
	ctx.r3.s64 = ctx.r10.s64 + -30904;
	// bl 0x823d9a98
	ctx.lr = 0x827A7A3C;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A7A4C"))) PPC_WEAK_FUNC(sub_827A7A4C);
PPC_FUNC_IMPL(__imp__sub_827A7A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7A50"))) PPC_WEAK_FUNC(sub_827A7A50);
PPC_FUNC_IMPL(__imp__sub_827A7A50) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,5892
	ctx.r3.s64 = r11.s64 + 5892;
	// bl 0x821c8ed8
	ctx.lr = 0x827A7A68;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30888
	ctx.r3.s64 = ctx.r10.s64 + -30888;
	// bl 0x823d9a98
	ctx.lr = 0x827A7A74;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827A7A84"))) PPC_WEAK_FUNC(sub_827A7A84);
PPC_FUNC_IMPL(__imp__sub_827A7A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7A88"))) PPC_WEAK_FUNC(sub_827A7A88);
PPC_FUNC_IMPL(__imp__sub_827A7A88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,10448
	ctx.r5.s64 = r11.s64 + 10448;
	// addi r3,r10,6016
	ctx.r3.s64 = ctx.r10.s64 + 6016;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7AA4"))) PPC_WEAK_FUNC(sub_827A7AA4);
PPC_FUNC_IMPL(__imp__sub_827A7AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7AA8"))) PPC_WEAK_FUNC(sub_827A7AA8);
PPC_FUNC_IMPL(__imp__sub_827A7AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,10460
	ctx.r5.s64 = r11.s64 + 10460;
	// addi r3,r10,5996
	ctx.r3.s64 = ctx.r10.s64 + 5996;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7AC4"))) PPC_WEAK_FUNC(sub_827A7AC4);
PPC_FUNC_IMPL(__imp__sub_827A7AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7AC8"))) PPC_WEAK_FUNC(sub_827A7AC8);
PPC_FUNC_IMPL(__imp__sub_827A7AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30840
	ctx.r3.s64 = r11.s64 + -30840;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7AD4"))) PPC_WEAK_FUNC(sub_827A7AD4);
PPC_FUNC_IMPL(__imp__sub_827A7AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7AD8"))) PPC_WEAK_FUNC(sub_827A7AD8);
PPC_FUNC_IMPL(__imp__sub_827A7AD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30808
	ctx.r3.s64 = r11.s64 + -30808;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7AE4"))) PPC_WEAK_FUNC(sub_827A7AE4);
PPC_FUNC_IMPL(__imp__sub_827A7AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7AE8"))) PPC_WEAK_FUNC(sub_827A7AE8);
PPC_FUNC_IMPL(__imp__sub_827A7AE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,10792
	ctx.r5.s64 = r11.s64 + 10792;
	// addi r3,r10,6260
	ctx.r3.s64 = ctx.r10.s64 + 6260;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7B04"))) PPC_WEAK_FUNC(sub_827A7B04);
PPC_FUNC_IMPL(__imp__sub_827A7B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7B08"))) PPC_WEAK_FUNC(sub_827A7B08);
PPC_FUNC_IMPL(__imp__sub_827A7B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,11424
	ctx.r5.s64 = r11.s64 + 11424;
	// addi r3,r10,7456
	ctx.r3.s64 = ctx.r10.s64 + 7456;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7B24"))) PPC_WEAK_FUNC(sub_827A7B24);
PPC_FUNC_IMPL(__imp__sub_827A7B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7B28"))) PPC_WEAK_FUNC(sub_827A7B28);
PPC_FUNC_IMPL(__imp__sub_827A7B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30776
	ctx.r3.s64 = r11.s64 + -30776;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7B34"))) PPC_WEAK_FUNC(sub_827A7B34);
PPC_FUNC_IMPL(__imp__sub_827A7B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7B38"))) PPC_WEAK_FUNC(sub_827A7B38);
PPC_FUNC_IMPL(__imp__sub_827A7B38) {
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
	ctx.lr = 0x827A7B40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a0a0
	ctx.lr = 0x827A7B54;
	sub_8214A0A0(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x821433e8
	ctx.lr = 0x827A7B5C;
	sub_821433E8(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x8214cea0
	ctx.lr = 0x827A7B64;
	sub_8214CEA0(ctx, base);
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x8215fec8
	ctx.lr = 0x827A7B6C;
	sub_8215FEC8(ctx, base);
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// bl 0x8214dee8
	ctx.lr = 0x827A7B74;
	sub_8214DEE8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f12,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,14124
	ctx.r9.s64 = r11.s64 + 14124;
	// addi r8,r10,14164
	ctx.r8.s64 = ctx.r10.s64 + 14164;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r9,1260(r31)
	PPC_STORE_U32(r31.u32 + 1260, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, r11.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r10,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r29,848
	r29.s64 = 848;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,14188(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14188);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f12,14184(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14184);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stw r8,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, ctx.r8.u32);
	// li r28,832
	r28.s64 = 832;
	// stb r9,1308(r31)
	PPC_STORE_U8(r31.u32 + 1308, ctx.r9.u8);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,14100
	ctx.r7.s64 = ctx.r7.s64 + 14100;
	// addi r6,r6,14144
	ctx.r6.s64 = ctx.r6.s64 + 14144;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r5,14084
	ctx.r5.s64 = ctx.r5.s64 + 14084;
	// stvx128 v63,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,14064
	ctx.r4.s64 = ctx.r4.s64 + 14064;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,255
	r11.s64 = 255;
	// stfs f13,1248(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1248, temp.u32);
	// li r10,96
	ctx.r10.s64 = 96;
	// stfs f0,1252(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1252, temp.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stfs f12,1256(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1256, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r7,1268(r31)
	PPC_STORE_U32(r31.u32 + 1268, ctx.r7.u32);
	// stw r6,1272(r31)
	PPC_STORE_U32(r31.u32 + 1272, ctx.r6.u32);
	// stvx128 v63,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,1276(r31)
	PPC_STORE_U32(r31.u32 + 1276, ctx.r5.u32);
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// stw r4,1280(r31)
	PPC_STORE_U32(r31.u32 + 1280, ctx.r4.u32);
	// stw r11,1284(r31)
	PPC_STORE_U32(r31.u32 + 1284, r11.u32);
	// stw r10,1292(r31)
	PPC_STORE_U32(r31.u32 + 1292, ctx.r10.u32);
	// stw r9,1288(r31)
	PPC_STORE_U32(r31.u32 + 1288, ctx.r9.u32);
	// stw r8,1296(r31)
	PPC_STORE_U32(r31.u32 + 1296, ctx.r8.u32);
	// bl 0x8215f8d0
	ctx.lr = 0x827A7C68;
	sub_8215F8D0(ctx, base);
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r3,r9,-30760
	ctx.r3.s64 = ctx.r9.s64 + -30760;
	// bl 0x823d9a98
	ctx.lr = 0x827A7C74;
	sub_823D9A98(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827A7C7C"))) PPC_WEAK_FUNC(sub_827A7C7C);
PPC_FUNC_IMPL(__imp__sub_827A7C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7C80"))) PPC_WEAK_FUNC(sub_827A7C80);
PPC_FUNC_IMPL(__imp__sub_827A7C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14252
	ctx.r5.s64 = r11.s64 + 14252;
	// addi r3,r10,19816
	ctx.r3.s64 = ctx.r10.s64 + 19816;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7C9C"))) PPC_WEAK_FUNC(sub_827A7C9C);
PPC_FUNC_IMPL(__imp__sub_827A7C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7CA0"))) PPC_WEAK_FUNC(sub_827A7CA0);
PPC_FUNC_IMPL(__imp__sub_827A7CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14260
	ctx.r5.s64 = r11.s64 + 14260;
	// addi r3,r10,19796
	ctx.r3.s64 = ctx.r10.s64 + 19796;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7CBC"))) PPC_WEAK_FUNC(sub_827A7CBC);
PPC_FUNC_IMPL(__imp__sub_827A7CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7CC0"))) PPC_WEAK_FUNC(sub_827A7CC0);
PPC_FUNC_IMPL(__imp__sub_827A7CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14268
	ctx.r5.s64 = r11.s64 + 14268;
	// addi r3,r10,19836
	ctx.r3.s64 = ctx.r10.s64 + 19836;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7CDC"))) PPC_WEAK_FUNC(sub_827A7CDC);
PPC_FUNC_IMPL(__imp__sub_827A7CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7CE0"))) PPC_WEAK_FUNC(sub_827A7CE0);
PPC_FUNC_IMPL(__imp__sub_827A7CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14284
	ctx.r5.s64 = r11.s64 + 14284;
	// addi r3,r10,26592
	ctx.r3.s64 = ctx.r10.s64 + 26592;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7CFC"))) PPC_WEAK_FUNC(sub_827A7CFC);
PPC_FUNC_IMPL(__imp__sub_827A7CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7D00"))) PPC_WEAK_FUNC(sub_827A7D00);
PPC_FUNC_IMPL(__imp__sub_827A7D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,26624
	ctx.r3.s64 = r11.s64 + 26624;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821ce460
	sub_821CE460(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7D14"))) PPC_WEAK_FUNC(sub_827A7D14);
PPC_FUNC_IMPL(__imp__sub_827A7D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7D18"))) PPC_WEAK_FUNC(sub_827A7D18);
PPC_FUNC_IMPL(__imp__sub_827A7D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,17036
	ctx.r5.s64 = r11.s64 + 17036;
	// addi r3,r10,26664
	ctx.r3.s64 = ctx.r10.s64 + 26664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7D34"))) PPC_WEAK_FUNC(sub_827A7D34);
PPC_FUNC_IMPL(__imp__sub_827A7D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7D38"))) PPC_WEAK_FUNC(sub_827A7D38);
PPC_FUNC_IMPL(__imp__sub_827A7D38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,17860
	ctx.r5.s64 = r11.s64 + 17860;
	// addi r3,r10,26696
	ctx.r3.s64 = ctx.r10.s64 + 26696;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7D54"))) PPC_WEAK_FUNC(sub_827A7D54);
PPC_FUNC_IMPL(__imp__sub_827A7D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7D58"))) PPC_WEAK_FUNC(sub_827A7D58);
PPC_FUNC_IMPL(__imp__sub_827A7D58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,28736
	ctx.r5.s64 = r11.s64 + 28736;
	// addi r3,r10,27088
	ctx.r3.s64 = ctx.r10.s64 + 27088;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7D74"))) PPC_WEAK_FUNC(sub_827A7D74);
PPC_FUNC_IMPL(__imp__sub_827A7D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7D78"))) PPC_WEAK_FUNC(sub_827A7D78);
PPC_FUNC_IMPL(__imp__sub_827A7D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,28752
	ctx.r5.s64 = r11.s64 + 28752;
	// addi r3,r10,27108
	ctx.r3.s64 = ctx.r10.s64 + 27108;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7D94"))) PPC_WEAK_FUNC(sub_827A7D94);
PPC_FUNC_IMPL(__imp__sub_827A7D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7D98"))) PPC_WEAK_FUNC(sub_827A7D98);
PPC_FUNC_IMPL(__imp__sub_827A7D98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r4,r11,-32172
	ctx.r4.s64 = r11.s64 + -32172;
	// addi r3,r10,-31096
	ctx.r3.s64 = ctx.r10.s64 + -31096;
	// b 0x821ce1d0
	sub_821CE1D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7DAC"))) PPC_WEAK_FUNC(sub_827A7DAC);
PPC_FUNC_IMPL(__imp__sub_827A7DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7DB0"))) PPC_WEAK_FUNC(sub_827A7DB0);
PPC_FUNC_IMPL(__imp__sub_827A7DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-31060
	ctx.r5.s64 = r11.s64 + -31060;
	// addi r3,r10,-30920
	ctx.r3.s64 = ctx.r10.s64 + -30920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7DCC"))) PPC_WEAK_FUNC(sub_827A7DCC);
PPC_FUNC_IMPL(__imp__sub_827A7DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7DD0"))) PPC_WEAK_FUNC(sub_827A7DD0);
PPC_FUNC_IMPL(__imp__sub_827A7DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28840
	ctx.r5.s64 = r11.s64 + -28840;
	// addi r3,r10,-28248
	ctx.r3.s64 = ctx.r10.s64 + -28248;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7DEC"))) PPC_WEAK_FUNC(sub_827A7DEC);
PPC_FUNC_IMPL(__imp__sub_827A7DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7DF0"))) PPC_WEAK_FUNC(sub_827A7DF0);
PPC_FUNC_IMPL(__imp__sub_827A7DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28828
	ctx.r5.s64 = r11.s64 + -28828;
	// addi r3,r10,-28308
	ctx.r3.s64 = ctx.r10.s64 + -28308;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7E0C"))) PPC_WEAK_FUNC(sub_827A7E0C);
PPC_FUNC_IMPL(__imp__sub_827A7E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7E10"))) PPC_WEAK_FUNC(sub_827A7E10);
PPC_FUNC_IMPL(__imp__sub_827A7E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28816
	ctx.r5.s64 = r11.s64 + -28816;
	// addi r3,r10,-28388
	ctx.r3.s64 = ctx.r10.s64 + -28388;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7E2C"))) PPC_WEAK_FUNC(sub_827A7E2C);
PPC_FUNC_IMPL(__imp__sub_827A7E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7E30"))) PPC_WEAK_FUNC(sub_827A7E30);
PPC_FUNC_IMPL(__imp__sub_827A7E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28812
	ctx.r5.s64 = r11.s64 + -28812;
	// addi r3,r10,-28468
	ctx.r3.s64 = ctx.r10.s64 + -28468;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7E4C"))) PPC_WEAK_FUNC(sub_827A7E4C);
PPC_FUNC_IMPL(__imp__sub_827A7E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7E50"))) PPC_WEAK_FUNC(sub_827A7E50);
PPC_FUNC_IMPL(__imp__sub_827A7E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28800
	ctx.r5.s64 = r11.s64 + -28800;
	// addi r3,r10,-28348
	ctx.r3.s64 = ctx.r10.s64 + -28348;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7E6C"))) PPC_WEAK_FUNC(sub_827A7E6C);
PPC_FUNC_IMPL(__imp__sub_827A7E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7E70"))) PPC_WEAK_FUNC(sub_827A7E70);
PPC_FUNC_IMPL(__imp__sub_827A7E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28792
	ctx.r5.s64 = r11.s64 + -28792;
	// addi r3,r10,-28408
	ctx.r3.s64 = ctx.r10.s64 + -28408;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7E8C"))) PPC_WEAK_FUNC(sub_827A7E8C);
PPC_FUNC_IMPL(__imp__sub_827A7E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7E90"))) PPC_WEAK_FUNC(sub_827A7E90);
PPC_FUNC_IMPL(__imp__sub_827A7E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28784
	ctx.r5.s64 = r11.s64 + -28784;
	// addi r3,r10,-28368
	ctx.r3.s64 = ctx.r10.s64 + -28368;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7EAC"))) PPC_WEAK_FUNC(sub_827A7EAC);
PPC_FUNC_IMPL(__imp__sub_827A7EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7EB0"))) PPC_WEAK_FUNC(sub_827A7EB0);
PPC_FUNC_IMPL(__imp__sub_827A7EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28772
	ctx.r5.s64 = r11.s64 + -28772;
	// addi r3,r10,-28268
	ctx.r3.s64 = ctx.r10.s64 + -28268;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7ECC"))) PPC_WEAK_FUNC(sub_827A7ECC);
PPC_FUNC_IMPL(__imp__sub_827A7ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7ED0"))) PPC_WEAK_FUNC(sub_827A7ED0);
PPC_FUNC_IMPL(__imp__sub_827A7ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28760
	ctx.r5.s64 = r11.s64 + -28760;
	// addi r3,r10,-28448
	ctx.r3.s64 = ctx.r10.s64 + -28448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7EEC"))) PPC_WEAK_FUNC(sub_827A7EEC);
PPC_FUNC_IMPL(__imp__sub_827A7EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7EF0"))) PPC_WEAK_FUNC(sub_827A7EF0);
PPC_FUNC_IMPL(__imp__sub_827A7EF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28744
	ctx.r5.s64 = r11.s64 + -28744;
	// addi r3,r10,-28288
	ctx.r3.s64 = ctx.r10.s64 + -28288;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7F0C"))) PPC_WEAK_FUNC(sub_827A7F0C);
PPC_FUNC_IMPL(__imp__sub_827A7F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7F10"))) PPC_WEAK_FUNC(sub_827A7F10);
PPC_FUNC_IMPL(__imp__sub_827A7F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28728
	ctx.r5.s64 = r11.s64 + -28728;
	// addi r3,r10,-28328
	ctx.r3.s64 = ctx.r10.s64 + -28328;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7F2C"))) PPC_WEAK_FUNC(sub_827A7F2C);
PPC_FUNC_IMPL(__imp__sub_827A7F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7F30"))) PPC_WEAK_FUNC(sub_827A7F30);
PPC_FUNC_IMPL(__imp__sub_827A7F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28712
	ctx.r5.s64 = r11.s64 + -28712;
	// addi r3,r10,-28488
	ctx.r3.s64 = ctx.r10.s64 + -28488;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7F4C"))) PPC_WEAK_FUNC(sub_827A7F4C);
PPC_FUNC_IMPL(__imp__sub_827A7F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7F50"))) PPC_WEAK_FUNC(sub_827A7F50);
PPC_FUNC_IMPL(__imp__sub_827A7F50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28696
	ctx.r5.s64 = r11.s64 + -28696;
	// addi r3,r10,-28508
	ctx.r3.s64 = ctx.r10.s64 + -28508;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7F6C"))) PPC_WEAK_FUNC(sub_827A7F6C);
PPC_FUNC_IMPL(__imp__sub_827A7F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7F70"))) PPC_WEAK_FUNC(sub_827A7F70);
PPC_FUNC_IMPL(__imp__sub_827A7F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28684
	ctx.r5.s64 = r11.s64 + -28684;
	// addi r3,r10,-28528
	ctx.r3.s64 = ctx.r10.s64 + -28528;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7F8C"))) PPC_WEAK_FUNC(sub_827A7F8C);
PPC_FUNC_IMPL(__imp__sub_827A7F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7F90"))) PPC_WEAK_FUNC(sub_827A7F90);
PPC_FUNC_IMPL(__imp__sub_827A7F90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28672
	ctx.r5.s64 = r11.s64 + -28672;
	// addi r3,r10,-28428
	ctx.r3.s64 = ctx.r10.s64 + -28428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7FAC"))) PPC_WEAK_FUNC(sub_827A7FAC);
PPC_FUNC_IMPL(__imp__sub_827A7FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7FB0"))) PPC_WEAK_FUNC(sub_827A7FB0);
PPC_FUNC_IMPL(__imp__sub_827A7FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r5,r11,11728
	ctx.r5.s64 = r11.s64 + 11728;
	// addi r4,r10,-27692
	ctx.r4.s64 = ctx.r10.s64 + -27692;
	// addi r3,r9,-27208
	ctx.r3.s64 = ctx.r9.s64 + -27208;
	// li r6,5258
	ctx.r6.s64 = 5258;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7FD0"))) PPC_WEAK_FUNC(sub_827A7FD0);
PPC_FUNC_IMPL(__imp__sub_827A7FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27668
	ctx.r5.s64 = r11.s64 + -27668;
	// addi r3,r10,-27152
	ctx.r3.s64 = ctx.r10.s64 + -27152;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A7FEC"))) PPC_WEAK_FUNC(sub_827A7FEC);
PPC_FUNC_IMPL(__imp__sub_827A7FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A7FF0"))) PPC_WEAK_FUNC(sub_827A7FF0);
PPC_FUNC_IMPL(__imp__sub_827A7FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27664
	ctx.r5.s64 = r11.s64 + -27664;
	// addi r3,r10,-27172
	ctx.r3.s64 = ctx.r10.s64 + -27172;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A800C"))) PPC_WEAK_FUNC(sub_827A800C);
PPC_FUNC_IMPL(__imp__sub_827A800C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8010"))) PPC_WEAK_FUNC(sub_827A8010);
PPC_FUNC_IMPL(__imp__sub_827A8010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27648
	ctx.r5.s64 = r11.s64 + -27648;
	// addi r3,r10,-27316
	ctx.r3.s64 = ctx.r10.s64 + -27316;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A802C"))) PPC_WEAK_FUNC(sub_827A802C);
PPC_FUNC_IMPL(__imp__sub_827A802C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8030"))) PPC_WEAK_FUNC(sub_827A8030);
PPC_FUNC_IMPL(__imp__sub_827A8030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27644
	ctx.r5.s64 = r11.s64 + -27644;
	// addi r3,r10,-27576
	ctx.r3.s64 = ctx.r10.s64 + -27576;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A804C"))) PPC_WEAK_FUNC(sub_827A804C);
PPC_FUNC_IMPL(__imp__sub_827A804C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8050"))) PPC_WEAK_FUNC(sub_827A8050);
PPC_FUNC_IMPL(__imp__sub_827A8050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27628
	ctx.r5.s64 = r11.s64 + -27628;
	// addi r3,r10,-27376
	ctx.r3.s64 = ctx.r10.s64 + -27376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A806C"))) PPC_WEAK_FUNC(sub_827A806C);
PPC_FUNC_IMPL(__imp__sub_827A806C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8070"))) PPC_WEAK_FUNC(sub_827A8070);
PPC_FUNC_IMPL(__imp__sub_827A8070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27612
	ctx.r5.s64 = r11.s64 + -27612;
	// addi r3,r10,-27336
	ctx.r3.s64 = ctx.r10.s64 + -27336;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A808C"))) PPC_WEAK_FUNC(sub_827A808C);
PPC_FUNC_IMPL(__imp__sub_827A808C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8090"))) PPC_WEAK_FUNC(sub_827A8090);
PPC_FUNC_IMPL(__imp__sub_827A8090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27604
	ctx.r5.s64 = r11.s64 + -27604;
	// addi r3,r10,-27616
	ctx.r3.s64 = ctx.r10.s64 + -27616;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A80AC"))) PPC_WEAK_FUNC(sub_827A80AC);
PPC_FUNC_IMPL(__imp__sub_827A80AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A80B0"))) PPC_WEAK_FUNC(sub_827A80B0);
PPC_FUNC_IMPL(__imp__sub_827A80B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27592
	ctx.r5.s64 = r11.s64 + -27592;
	// addi r3,r10,-27456
	ctx.r3.s64 = ctx.r10.s64 + -27456;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A80CC"))) PPC_WEAK_FUNC(sub_827A80CC);
PPC_FUNC_IMPL(__imp__sub_827A80CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A80D0"))) PPC_WEAK_FUNC(sub_827A80D0);
PPC_FUNC_IMPL(__imp__sub_827A80D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27576
	ctx.r5.s64 = r11.s64 + -27576;
	// addi r3,r10,-27396
	ctx.r3.s64 = ctx.r10.s64 + -27396;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A80EC"))) PPC_WEAK_FUNC(sub_827A80EC);
PPC_FUNC_IMPL(__imp__sub_827A80EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A80F0"))) PPC_WEAK_FUNC(sub_827A80F0);
PPC_FUNC_IMPL(__imp__sub_827A80F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27560
	ctx.r5.s64 = r11.s64 + -27560;
	// addi r3,r10,-27436
	ctx.r3.s64 = ctx.r10.s64 + -27436;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A810C"))) PPC_WEAK_FUNC(sub_827A810C);
PPC_FUNC_IMPL(__imp__sub_827A810C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8110"))) PPC_WEAK_FUNC(sub_827A8110);
PPC_FUNC_IMPL(__imp__sub_827A8110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27548
	ctx.r5.s64 = r11.s64 + -27548;
	// addi r3,r10,-27192
	ctx.r3.s64 = ctx.r10.s64 + -27192;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A812C"))) PPC_WEAK_FUNC(sub_827A812C);
PPC_FUNC_IMPL(__imp__sub_827A812C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8130"))) PPC_WEAK_FUNC(sub_827A8130);
PPC_FUNC_IMPL(__imp__sub_827A8130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27544
	ctx.r5.s64 = r11.s64 + -27544;
	// addi r3,r10,-27596
	ctx.r3.s64 = ctx.r10.s64 + -27596;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A814C"))) PPC_WEAK_FUNC(sub_827A814C);
PPC_FUNC_IMPL(__imp__sub_827A814C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8150"))) PPC_WEAK_FUNC(sub_827A8150);
PPC_FUNC_IMPL(__imp__sub_827A8150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27536
	ctx.r5.s64 = r11.s64 + -27536;
	// addi r3,r10,-27416
	ctx.r3.s64 = ctx.r10.s64 + -27416;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827A816C"))) PPC_WEAK_FUNC(sub_827A816C);
PPC_FUNC_IMPL(__imp__sub_827A816C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827A8170"))) PPC_WEAK_FUNC(sub_827A8170);
PPC_FUNC_IMPL(__imp__sub_827A8170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27528
	ctx.r5.s64 = r11.s64 + -27528;
	// addi r3,r10,-27356
	ctx.r3.s64 = ctx.r10.s64 + -27356;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

